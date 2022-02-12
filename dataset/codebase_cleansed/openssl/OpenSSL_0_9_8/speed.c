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
static DES_cblock key ={0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0};
static DES_cblock key2={0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0,0x12};
static DES_cblock key3={0x56,0x78,0x9a,0xbc,0xde,0xf0,0x12,0x34};
DES_key_schedule sch,sch2,sch3;
double a,b,c,d,e;
#ifndef SIGALRM
long ca,cb,cc,cd,ce;
#endif
#ifndef TIMES
printf("To get the most accurate results, try to run this\n");
printf("program when this computer is idle.\n");
#endif
DES_set_key_unchecked(&key2,&sch2);
DES_set_key_unchecked(&key3,&sch3);
#ifndef SIGALRM
printf("First we calculate the approximate speed ...\n");
DES_set_key_unchecked(&key,&sch);
count=10;
do {
long i;
DES_LONG data[2];
count*=2;
Time_F(START);
for (i=count; i; i--)
DES_encrypt1(data,&sch,DES_ENCRYPT);
d=Time_F(STOP);
} while (d < 3.0);
ca=count;
cb=count*3;
cc=count*3*8/BUFSIZE+1;
cd=count*8/BUFSIZE+1;
ce=count/20+1;
printf("Doing set_key %ld times\n",ca);
#define COND(d) (count != (d))
#define COUNT(d) (d)
#else
#define COND(c) (run)
#define COUNT(d) (count)
signal(SIGALRM,sig_done);
printf("Doing set_key for 10 seconds\n");
alarm(10);
#endif
Time_F(START);
for (count=0,run=1; COND(ca); count++)
DES_set_key_unchecked(&key,&sch);
d=Time_F(STOP);
printf("%ld set_key's in %.2f seconds\n",count,d);
a=((double)COUNT(ca))/d;
#ifdef SIGALRM
printf("Doing DES_encrypt's for 10 seconds\n");
alarm(10);
#else
printf("Doing DES_encrypt %ld times\n",cb);
#endif
Time_F(START);
for (count=0,run=1; COND(cb); count++)
{
DES_LONG data[2];
DES_encrypt1(data,&sch,DES_ENCRYPT);
}
d=Time_F(STOP);
printf("%ld DES_encrypt's in %.2f second\n",count,d);
b=((double)COUNT(cb)*8)/d;
#ifdef SIGALRM
printf("Doing DES_cbc_encrypt on %ld byte blocks for 10 seconds\n",
BUFSIZE);
alarm(10);
#else
printf("Doing DES_cbc_encrypt %ld times on %ld byte blocks\n",cc,
BUFSIZE);
#endif
Time_F(START);
for (count=0,run=1; COND(cc); count++)
DES_ncbc_encrypt(buf,buf,BUFSIZE,&sch,
&key,DES_ENCRYPT);
d=Time_F(STOP);
printf("%ld DES_cbc_encrypt's of %ld byte blocks in %.2f second\n",
count,BUFSIZE,d);
c=((double)COUNT(cc)*BUFSIZE)/d;
#ifdef SIGALRM
printf("Doing DES_ede_cbc_encrypt on %ld byte blocks for 10 seconds\n",
BUFSIZE);
alarm(10);
#else
printf("Doing DES_ede_cbc_encrypt %ld times on %ld byte blocks\n",cd,
BUFSIZE);
#endif
Time_F(START);
for (count=0,run=1; COND(cd); count++)
DES_ede3_cbc_encrypt(buf,buf,BUFSIZE,
&sch,
&sch2,
&sch3,
&key,
DES_ENCRYPT);
d=Time_F(STOP);
printf("%ld DES_ede_cbc_encrypt's of %ld byte blocks in %.2f second\n",
count,BUFSIZE,d);
d=((double)COUNT(cd)*BUFSIZE)/d;
#ifdef SIGALRM
printf("Doing crypt for 10 seconds\n");
alarm(10);
#else
printf("Doing crypt %ld times\n",ce);
#endif
Time_F(START);
for (count=0,run=1; COND(ce); count++)
crypt("testing1","ef");
e=Time_F(STOP);
printf("%ld crypts in %.2f second\n",count,e);
e=((double)COUNT(ce))/e;
printf("set_key per sec = %12.2f (%9.3fuS)\n",a,1.0e6/a);
printf("DES raw ecb bytes per sec = %12.2f (%9.3fuS)\n",b,8.0e6/b);
printf("DES cbc bytes per sec = %12.2f (%9.3fuS)\n",c,8.0e6/c);
printf("DES ede cbc bytes per sec = %12.2f (%9.3fuS)\n",d,8.0e6/d);
printf("crypt per sec = %12.2f (%9.3fuS)\n",e,1.0e6/e);
exit(0);
#if defined(LINT) || defined(OPENSSL_SYS_MSDOS)
return(0);
#endif
}
