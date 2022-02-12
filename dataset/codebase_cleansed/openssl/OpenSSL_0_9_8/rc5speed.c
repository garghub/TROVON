SIGRETTYPE sig_done(int sig)
{
signal(SIGALRM,sig_done);
run=0;
#ifdef LINT
sig=sig;
#endif
}
double Time_F(int s)
{
double ret;
#ifdef TIMES
static struct tms tstart,tend;
if (s == START)
{
times(&tstart);
return(0);
}
else
{
times(&tend);
ret=((double)(tend.tms_utime-tstart.tms_utime))/HZ;
return((ret == 0.0)?1e-6:ret);
}
#else
static struct timeb tstart,tend;
long i;
if (s == START)
{
ftime(&tstart);
return(0);
}
else
{
ftime(&tend);
i=(long)tend.millitm-(long)tstart.millitm;
ret=((double)(tend.time-tstart.time))+((double)i)/1e3;
return((ret == 0.0)?1e-6:ret);
}
#endif
}
int main(int argc, char **argv)
{
long count;
static unsigned char buf[BUFSIZE];
static unsigned char key[] ={
0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0,
0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10,
};
RC5_32_KEY sch;
double a,b,c,d;
#ifndef SIGALRM
long ca,cb,cc;
#endif
#ifndef TIMES
printf("To get the most accurate results, try to run this\n");
printf("program when this computer is idle.\n");
#endif
#ifndef SIGALRM
printf("First we calculate the approximate speed ...\n");
RC5_32_set_key(&sch,16,key,12);
count=10;
do {
long i;
unsigned long data[2];
count*=2;
Time_F(START);
for (i=count; i; i--)
RC5_32_encrypt(data,&sch);
d=Time_F(STOP);
} while (d < 3.0);
ca=count/512;
cb=count;
cc=count*8/BUFSIZE+1;
printf("Doing RC5_32_set_key %ld times\n",ca);
#define COND(d) (count != (d))
#define COUNT(d) (d)
#else
#define COND(c) (run)
#define COUNT(d) (count)
signal(SIGALRM,sig_done);
printf("Doing RC5_32_set_key for 10 seconds\n");
alarm(10);
#endif
Time_F(START);
for (count=0,run=1; COND(ca); count+=4)
{
RC5_32_set_key(&sch,16,key,12);
RC5_32_set_key(&sch,16,key,12);
RC5_32_set_key(&sch,16,key,12);
RC5_32_set_key(&sch,16,key,12);
}
d=Time_F(STOP);
printf("%ld RC5_32_set_key's in %.2f seconds\n",count,d);
a=((double)COUNT(ca))/d;
#ifdef SIGALRM
printf("Doing RC5_32_encrypt's for 10 seconds\n");
alarm(10);
#else
printf("Doing RC5_32_encrypt %ld times\n",cb);
#endif
Time_F(START);
for (count=0,run=1; COND(cb); count+=4)
{
unsigned long data[2];
RC5_32_encrypt(data,&sch);
RC5_32_encrypt(data,&sch);
RC5_32_encrypt(data,&sch);
RC5_32_encrypt(data,&sch);
}
d=Time_F(STOP);
printf("%ld RC5_32_encrypt's in %.2f second\n",count,d);
b=((double)COUNT(cb)*8)/d;
#ifdef SIGALRM
printf("Doing RC5_32_cbc_encrypt on %ld byte blocks for 10 seconds\n",
BUFSIZE);
alarm(10);
#else
printf("Doing RC5_32_cbc_encrypt %ld times on %ld byte blocks\n",cc,
BUFSIZE);
#endif
Time_F(START);
for (count=0,run=1; COND(cc); count++)
RC5_32_cbc_encrypt(buf,buf,BUFSIZE,&sch,
&(key[0]),RC5_ENCRYPT);
d=Time_F(STOP);
printf("%ld RC5_32_cbc_encrypt's of %ld byte blocks in %.2f second\n",
count,BUFSIZE,d);
c=((double)COUNT(cc)*BUFSIZE)/d;
printf("RC5_32/12/16 set_key per sec = %12.2f (%9.3fuS)\n",a,1.0e6/a);
printf("RC5_32/12/16 raw ecb bytes per sec = %12.2f (%9.3fuS)\n",b,8.0e6/b);
printf("RC5_32/12/16 cbc bytes per sec = %12.2f (%9.3fuS)\n",c,8.0e6/c);
exit(0);
#if defined(LINT) || defined(OPENSSL_SYS_MSDOS)
return(0);
#endif
}
