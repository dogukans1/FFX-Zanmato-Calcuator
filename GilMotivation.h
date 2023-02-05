int gilMotivation(int a)
{
    if (999999999 <= a) //not that it'd matter as a bigger value than 999999999 (more than game allows) would still result a return value of 112, but still...
    {
        a = 999999999;
    }
    if (a >= 1 && a <= 3)
    {
        return 0;
    }
    else if (a >= 4 && a <= 7)
    {
        return 4;
    }
    else if (a >= 8 && a <= 15)
    {
        return 8;
    }
    else if (a >= 16 && a <= 31)
    {
        return 12;
    }
    else if (a >= 32 && a <= 63)
    {
        return 16;
    }
    else if (a >= 64 && a <= 127)
    {
        return 20;
    }
    else if (a >= 128 && a <= 255)
    {
        return 24;
    }
    else if (a >= 256 && a <= 511)
    {
        return 28;
    }
    else if (a >= 512 && a <= 1023)
    {
        return 32;
    }
    else if (a >= 1024 && a <= 2047)
    {
        return 36;
    }
    else if (a >= 2048 && a <= 4095)
    {
        return 40;
    }
    else if (a >= 4096 && a <= 8191)
    {
        return 44;
    }
    else if (a >= 8192 && a <= 16383)
    {
        return 48;
    }
    else if (a >= 16384 && a <= 32767)
    {
        return 52;
    }
    else if (a >= 32768 && a <= 65535)
    {
        return 56;
    }
    else if (a >= 65536 && a <= 131071)
    {
        return 60;
    }
    else if (a >= 131072 && a <= 262143)
    {
        return 64;
    }
    else if (a >= 262144 && a <= 524287)
    {
        return 68;
    }
    else if (a >= 524288 && a <= 1048575)
    {
        return 72;
    }
    else if (a >= 1048576 && a <= 2097151)
    {
        return 76;
    }
    else if (a >= 2097152 && a <= 4194303)
    {
        return 80;
    }
    else if (a >= 4194304 && a <= 8388607)
    {
        return 84;
    }
    else if (a >= 8388608 && a <= 16777215)
    {
        return 88;
    }
    else if (a >= 16777216 && a <= 33554431)
    {
        return 92;
    }
    else if (a >= 33554432 && a <= 67108863)
    {
        return 96;
    }
    else if (a >= 67108864 && a <= 134217727)
    {
        return 100;
    }
    else if (a >= 134217728 && a <= 268435455)
    {
        return 104;
    }
    else if (a >= 268435456 && a <= 536870911)
    {
        return 108;
    }
    else  //end of the payment calcuation, courtesy of ChatGPT (I could write it by hand but it would change little, it it makes you happier I had to fix the formatting of text)
    {
        return 112;
    }
}