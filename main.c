#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <regex.h>

enum DEVICE {
    BIT_READ = 1,
    BYTE_READ = 3,
    BIT_WRITE = 5,
    BYTE_WRITE = 6,
};

enum DEVICEOPERATIONS { SUCCESS = 10, FAIL, CONVERT_DEC_TO_HEX_SUCCESS, CONVERT_DEC_TO_HEX_FAIL, CONVERT_HEX_TO_DEC_SUCCESS, CONVERT_HEX_TO_DEC_FAIL };

struct device_ops{
    int address;
    int operation_num;
    char buffer[16];
    char value;
};

int getData(const char* fileName){
    FILE *fileDesc = fopen(fileName, "rb");
    if(fileDesc !=NULL){
        int val = fgetc(fileDesc);
        //printf("Character from file %d\n", val);
        fclose(fileDesc);
        return val;
    }
    return FAIL;

}

typedef struct device_ops devOps;

void bit_write(char buffer[], char value)
{

}
char* convertDecToHex(int buffer[]){
    size_t i;
    int buffer_size = sizeof buffer / sizeof(int);
    //массив для хексов
    char *hexNumber = (char*)malloc(buffer_size*4);

    for(i = 0; i < buffer_size; ++i){
        int decimal = buffer[i] % 16;
        if(decimal < 10){
            decimal +=48;
        }
        else{
            decimal+=55;
            buffer[i++]=decimal;

        }
    }
    return *hexNumber;
}

int convertHexToDec(char buffer[]){
    size_t i;
    size_t buffer_size = strlen(buffer)-1;

    for(i = 0; i < buffer_size; ++i){
        /*
        __asm__("xorl %eax,%eax\n\t"
                "xorl %ecx,%ecx\n\t"
                "  \n\t");
                */
    }
    return FAIL;
}

void prepPackData(const char pack)
{
    regex_t reg(pack);

}

void bit_read(){

}


void byte_write( char buffer[], char value){

}

void byte_read(){

}

void setDeviceAddress(devOps* DevOps, int address){
    DevOps->address = address;
}

void setOpsNum(devOps* DevOps, enum DEVICE dev){
    DevOps->operation_num = dev;
}

void setBuffer(devOps* DevOps, char value){
    memset(DevOps, value, sizeof(DevOps->buffer));
}

devOps* init(void){
    devOps *_device = NULL;
    _device = (devOps*)malloc(sizeof(devOps));
    if(_device != NULL)
    {
        setDeviceAddress(_device, 0);
        setOpsNum(_device, 0);
        setBuffer(_device, '0');
        return _device;
    }
    free(_device);
    return NULL;
}

int operation(enum DEVICE device, struct device_ops *devOps){
    switch(device)
    {
        case BIT_READ:
        bit_read();
        break;
        case BIT_WRITE:
        //bit_write();
        break;
        case BYTE_READ:
        bit_read();
        break;
        case BYTE_WRITE:
        //byte_write();
        break;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    devOps *devOps = NULL;
    devOps = init();
    if(devOps != NULL)
    {
        setDeviceAddress(devOps,1);
        setOpsNum(devOps, BIT_WRITE);

        int l = getData("message.text");
        printf("l val is %d\n", l);

        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
