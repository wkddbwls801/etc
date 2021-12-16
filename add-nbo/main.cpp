#include <stdint.h> //for uint32_t
#include <stdio.h> // for printf
uint32_t write_32bit(uint32_t n)
{
    uint32_t n1 = (n & 0xFF000000) >> 24;
    uint32_t n2 = (n & 0x00FF0000) >> 8;
    uint32_t n3 = (n & 0x0000FF00) << 8;
    uint32_t n4 = (n & 0x000000FF) << 24;

    return n1|n2|n3|n4;
}

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;

    uint32_t result1;
    uint32_t result2;
    uint32_t sum;

    fp1=fopen(argv[1], "rb");
    fp2=fopen(argv[2], "rb");

    fread(&result1, sizeof(uint32_t), 1, fp1);
    fread(&result2, sizeof(uint32_t), 1, fp2);


    result1 = write_32bit(result1);
    result2 = write_32bit(result2);

    sum=result1+result2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", result1, result1, result2, result2, sum, sum);

    fclose(fp2);
    fclose(fp1);
    return 0;
}
