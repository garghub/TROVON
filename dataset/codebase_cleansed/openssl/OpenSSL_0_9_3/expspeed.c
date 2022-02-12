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
BIGNUM *a,*b,*c,*r;
ctx=BN_CTX_new();
a=BN_new();
b=BN_new();
c=BN_new();
r=BN_new();
do_mul_exp(r,a,b,c,ctx);
}
void do_mul_exp(BIGNUM *r, BIGNUM *a, BIGNUM *b, BIGNUM *c, BN_CTX *ctx)
{
int i,k;
double tm;
long num;
BN_MONT_CTX m;
memset(&m,0,sizeof(m));
num=BASENUM;
for (i=0; i<NUM_SIZES; i++)
{
BN_rand(a,sizes[i],1,0);
BN_rand(b,sizes[i],1,0);
BN_rand(c,sizes[i],1,1);
BN_mod(a,a,c,ctx);
BN_mod(b,b,c,ctx);
BN_MONT_CTX_set(&m,c,ctx);
Time_F(START);
for (k=0; k<num; k++)
BN_mod_exp_mont(r,a,b,c,ctx,&m);
tm=Time_F(STOP);
printf("mul %4d ^ %4d %% %d -> %8.3fms %5.1f\n",sizes[i],sizes[i],sizes[i],tm*1000.0/num,tm*mul_c[i]/num);
num/=7;
if (num <= 0) num=1;
}
}
