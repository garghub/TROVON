static double Time_F(int s)
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
return((ret < 1e-3)?1e-3:ret);
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
ret=((double)(tend.time-tstart.time))+((double)i)/1000.0;
return((ret < 0.001)?0.001:ret);
}
#endif
}
int main(int argc, char **argv)
{
BN_CTX *ctx;
BIGNUM a,b,c;
ctx=BN_CTX_new();
BN_init(&a);
BN_init(&b);
BN_init(&c);
do_mul(&a,&b,&c,ctx);
}
void do_mul(BIGNUM *r, BIGNUM *a, BIGNUM *b, BN_CTX *ctx)
{
int i,j,k;
double tm;
long num;
for (i=0; i<NUM_SIZES; i++)
{
num=BASENUM;
if (i) num/=(i*3);
BN_rand(a,sizes[i],1,0);
for (j=i; j<NUM_SIZES; j++)
{
BN_rand(b,sizes[j],1,0);
Time_F(START);
for (k=0; k<num; k++)
BN_mul(r,b,a,ctx);
tm=Time_F(STOP);
printf("mul %4d x %4d -> %8.3fms\n",sizes[i],sizes[j],tm*1000.0/num);
}
}
for (i=0; i<NUM_SIZES; i++)
{
num=BASENUM;
if (i) num/=(i*3);
BN_rand(a,sizes[i],1,0);
Time_F(START);
for (k=0; k<num; k++)
BN_sqr(r,a,ctx);
tm=Time_F(STOP);
printf("sqr %4d x %4d -> %8.3fms\n",sizes[i],sizes[i],tm*1000.0/num);
}
for (i=0; i<NUM_SIZES; i++)
{
num=BASENUM/10;
if (i) num/=(i*3);
BN_rand(a,sizes[i]-1,1,0);
for (j=i; j<NUM_SIZES; j++)
{
BN_rand(b,sizes[j],1,0);
Time_F(START);
for (k=0; k<100000; k++)
BN_div(r, NULL, b, a,ctx);
tm=Time_F(STOP);
printf("div %4d / %4d -> %8.3fms\n",sizes[j],sizes[i]-1,tm*1000.0/num);
}
}
}
