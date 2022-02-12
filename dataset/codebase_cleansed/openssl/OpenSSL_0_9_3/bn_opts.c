int main(int argc, char **argv)
{
PARMS p;
BN_MONT_CTX *mont;
int size=0,num;
char *name;
int type=P_EXP;
mont=BN_MONT_CTX_new();
p.mont=NULL;
p.ctx=BN_CTX_new();
BN_init(&p.r);
BN_init(&p.a);
BN_init(&p.b);
BN_init(&p.c);
BN_init(&p.low);
p.w=0;
for (;;)
{
if (argc > 1)
{
if (argv[1][0] == '-')
{
switch(argv[1][1])
{
case 'e': type=P_EXP; break;
case 'm': type=P_MUL; break;
case 's': type=P_SQR; break;
case 'l': type=P_MULL; break;
case 'h': type=P_MULH; break;
case 'r': type=P_MRED; break;
default:
fprintf(stderr,"options: -[emslhr]\n");
exit(1);
}
}
else
{
size=atoi(argv[1]);
}
argc--;
argv++;
}
else
break;
}
if (size == 0)
size=DEFAULT_SIZE;
printf("bit size:%5d\n",size);
BN_rand(&p.a,size,1,0);
BN_rand(&p.b,size,1,0);
BN_rand(&p.c,size,1,1);
BN_mod(&p.a,&p.a,&p.c,p.ctx);
BN_mod(&p.b,&p.b,&p.c,p.ctx);
p.w=(p.a.top+1)/2;
BN_mul(&p.low,&p.a,&p.b,p.ctx);
p.low.top=p.a.top;
switch(type)
{
case P_EXP:
p.name="r=a^b%c";
p.func=do_mul_exp;
p.mont=mont;
break;
case P_MUL:
p.name="r=a*b";
p.func=do_mul;
break;
case P_SQR:
p.name="r=a*a";
p.func=do_sqr;
break;
case P_MULL:
p.name="r=low(a*b)";
p.func=do_mul_low;
break;
case P_MULH:
p.name="r=high(a*b)";
p.func=do_mul_high;
break;
case P_MRED:
p.name="r=montgomery_reduction(a)";
p.func=do_from_montgomery;
p.mont=mont;
break;
default:
fprintf(stderr,"options: -[emslhr]\n");
exit(1);
}
num=time_it(DEFAULT_TIME,&p);
do_it(num,&p);
}
void do_it(int num, PARMS *p)
{
char *start,*end;
int i,j,number;
double d;
start=ms_time_new();
end=ms_time_new();
number=BN_num_bits_word((BN_ULONG)BN_num_bits(&(p->c)))-
BN_num_bits_word(BN_BITS2)+2;
for (i=number-1; i >=0; i--)
{
if (i == 1) continue;
BN_set_params(i,i,i,1);
if (p->mont != NULL)
BN_MONT_CTX_set(p->mont,&(p->c),p->ctx);
printf("Timing %5d (%2d bit) %2d %2d %2d %2d :",
(1<<i)*BN_BITS2,i,
BN_get_params(0),
BN_get_params(1),
BN_get_params(2),
BN_get_params(3));
fflush(stdout);
ms_time_get(start);
p->func(num,p);
ms_time_get(end);
d=ms_time_diff(start,end);
printf("%6.6f sec, or %d in %.4f seconds\n",
(double)d/num,num,d);
}
}
int time_it(int sec, PARMS *p)
{
char *start,*end;
int i,j;
double d;
if (p->mont != NULL)
BN_MONT_CTX_set(p->mont,&(p->c),p->ctx);
start=ms_time_new();
end=ms_time_new();
i=1;
for (;;)
{
if (verbose)
printf("timing %s for %d interations\n",p->name,i);
ms_time_get(start);
p->func(i,p);
ms_time_get(end);
d=ms_time_diff(start,end);
if (d < 0.01) i*=100;
else if (d < 0.1 ) i*=10;
else if (d > (double)sec) break;
else
{
i=(int)(1.0*i*sec/d);
break;
}
}
if (verbose)
printf("using %d interations\n",i);
return(i);
}
void do_mul_exp(int num, PARMS *p)
{
int i;
for (i=0; i<num; i++)
BN_mod_exp_mont(&(p->r),&(p->a),&(p->b),&(p->c),
p->ctx,p->mont);
}
void do_mul(int num, PARMS *p)
{
int i;
for (i=0; i<num; i++)
BN_mul(&(p->r),&(p->a),&(p->b),p->ctx);
}
void do_sqr(int num, PARMS *p)
{
int i;
for (i=0; i<num; i++)
BN_sqr(&(p->r),&(p->a),p->ctx);
}
void do_mul_low(int num, PARMS *p)
{
int i;
for (i=0; i<num; i++)
BN_mul_low(&(p->r),&(p->a),&(p->b),p->w,p->ctx);
}
void do_mul_high(int num, PARMS *p)
{
int i;
for (i=0; i<num; i++)
BN_mul_low(&(p->r),&(p->a),&(p->b),&(p->low),p->w,p->ctx);
}
void do_from_montgomery(int num, PARMS *p)
{
int i;
for (i=0; i<num; i++)
BN_from_montgomery(&(p->r),&(p->a),p->mont,p->ctx);
}
