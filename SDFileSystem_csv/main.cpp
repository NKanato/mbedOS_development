/*ジャイロセンサの値を読み込んで、値をcsv形式でSDカードに保存する*/

#include "mbed.h"
#include "SDFileSystem.h"
#include "BlockDevice.h"
#include "MPU6050.h"

//Create an SDFileSystem object
SDFileSystem sd(D11, D12, D13, D10, "sd");
RawSerial pc(USBTX,USBRX);
MPU6050 mpu6050;
Timer timer;

int main()
{
    //Mount the filesystem
    char c;
    int i;
    int16_t axis_ac[3];
    int time = 0;

    BlockDevice *bd = BlockDevice::get_default_instance();
    mpu6050.resetMPU6050();
    mpu6050.SetUp_MPU6050();
    sd.mount(bd);
    FILE *fp;
    timer.start();
    fp = fopen("/sd/csvtest.csv", "w");
    pc.printf("Start\n\r");


    while(time <= 10){
        mpu6050.readGyroData(&axis_ac[0]);
        pc.printf("\nWriting to SD card...");

        time = timer.read();
        if (fp != NULL) {
            fprintf(fp, "%d,%d,%d,%d\n",time,axis_ac[0],axis_ac[1],axis_ac[2]);
            pc.printf("X=%d  Y=%d  Z=%d\n\r",axis_ac[0],axis_ac[1],axis_ac[2]);
        } else {
            printf("failed!\n");
            break;
        }
    }
    pc.printf("finished\n\r");
    fclose(fp);
    pc.printf("file closed\n\r");
    //Unmount the filesystem
    sd.unmount();
}