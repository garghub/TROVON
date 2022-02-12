int BN_mod_mul_montgomery(BIGNUM *r, BIGNUM *a, BIGNUM *b, BN_MONT_CTX *mont,
BN_CTX *ctx)
{
BIGNUM *tmp,*tmp2;
tmp= &(ctx->bn[ctx->tos]);
tmp2= &(ctx->bn[ctx->tos]);
ctx->tos+=2;
bn_check_top(tmp);
bn_check_top(tmp2);
if (a == b)
{
#if 0
bn_wexpand(tmp,a->top*2);
bn_wexpand(tmp2,a->top*4);
bn_sqr_recursive(tmp->d,a->d,a->top,tmp2->d);
tmp->top=a->top*2;
if (tmp->d[tmp->top-1] == 0)
tmp->top--;
#else
if (!BN_sqr(tmp,a,ctx)) goto err;
#endif
}
else
{
if (!BN_mul(tmp,a,b,ctx)) goto err;
}
if (!BN_from_montgomery(r,tmp,mont,ctx)) goto err;
ctx->tos-=2;
return(1);
err:
return(0);
}
int BN_from_montgomery(BIGNUM *ret, BIGNUM *a, BN_MONT_CTX *mont,
BN_CTX *ctx)
{
#ifdef BN_RECURSION_MONT
if (mont->use_word)
#endif
{
BIGNUM *n,*r;
BN_ULONG *ap,*np,*rp,n0,v,*nrp;
int al,nl,max,i,x,ri;
int retn=0;
r= &(ctx->bn[ctx->tos]);
if (!BN_copy(r,a)) goto err1;
n= &(mont->N);
ap=a->d;
al=ri=mont->ri/BN_BITS2;
nl=n->top;
if ((al == 0) || (nl == 0)) { r->top=0; return(1); }
max=(nl+al+1);
if (bn_wexpand(r,max) == NULL) goto err1;
if (bn_wexpand(ret,max) == NULL) goto err1;
r->neg=a->neg^n->neg;
np=n->d;
rp=r->d;
nrp= &(r->d[nl]);
#if 1
for (i=r->top; i<max; i++)
r->d[i]=0;
#else
memset(&(r->d[r->top]),0,(max-r->top)*sizeof(BN_ULONG));
#endif
r->top=max;
n0=mont->n0;
#ifdef BN_COUNT
printf("word BN_from_montgomery %d * %d\n",nl,nl);
#endif
for (i=0; i<nl; i++)
{
v=bn_mul_add_words(rp,np,nl,(rp[0]*n0)&BN_MASK2);
nrp++;
rp++;
if (((nrp[-1]+=v)&BN_MASK2) >= v)
continue;
else
{
if (((++nrp[0])&BN_MASK2) != 0) continue;
if (((++nrp[1])&BN_MASK2) != 0) continue;
for (x=2; (((++nrp[x])&BN_MASK2) == 0); x++) ;
}
}
bn_fix_top(r);
#if 0
BN_rshift(ret,r,mont->ri);
#else
x=ri;
rp=ret->d;
ap= &(r->d[x]);
if (r->top < x)
al=0;
else
al=r->top-x;
ret->top=al;
al-=4;
for (i=0; i<al; i+=4)
{
BN_ULONG t1,t2,t3,t4;
t1=ap[i+0];
t2=ap[i+1];
t3=ap[i+2];
t4=ap[i+3];
rp[i+0]=t1;
rp[i+1]=t2;
rp[i+2]=t3;
rp[i+3]=t4;
}
al+=4;
for (; i<al; i++)
rp[i]=ap[i];
#endif
if (BN_ucmp(ret, &(mont->N)) >= 0)
{
BN_usub(ret,ret,&(mont->N));
}
retn=1;
err1:
return(retn);
}
#ifdef BN_RECURSION_MONT
else
{
BIGNUM *t1,*t2,*t3;
int j,i;
#ifdef BN_COUNT
printf("number BN_from_montgomery\n");
#endif
t1= &(ctx->bn[ctx->tos]);
t2= &(ctx->bn[ctx->tos+1]);
t3= &(ctx->bn[ctx->tos+2]);
i=mont->Ni.top;
bn_wexpand(ret,i);
bn_wexpand(t1,i*4);
bn_wexpand(t2,i*2);
bn_mul_low_recursive(t2->d,a->d,mont->Ni.d,i,t1->d);
BN_zero(t3);
BN_set_bit(t3,mont->N.top*BN_BITS2);
bn_sub_words(t3->d,t3->d,a->d,i);
bn_mul_high(ret->d,t2->d,mont->N.d,t3->d,i,t1->d);
if (a->top > i)
{
j=(int)(bn_add_words(ret->d,ret->d,&(a->d[i]),i));
if (j)
bn_sub_words(ret->d,ret->d,mont->N.d,i);
}
ret->top=i;
bn_fix_top(ret);
if (a->d[0])
BN_add_word(ret,1);
else
{
for (i=1; i<mont->N.top-1; i++)
{
if (a->d[i])
{
BN_add_word(ret,1);
break;
}
}
}
if (BN_ucmp(ret,&(mont->N)) >= 0)
BN_usub(ret,ret,&(mont->N));
return(1);
}
#endif
}
BN_MONT_CTX *BN_MONT_CTX_new(void)
{
BN_MONT_CTX *ret;
if ((ret=(BN_MONT_CTX *)Malloc(sizeof(BN_MONT_CTX))) == NULL)
return(NULL);
BN_MONT_CTX_init(ret);
ret->flags=BN_FLG_MALLOCED;
return(ret);
}
void BN_MONT_CTX_init(BN_MONT_CTX *ctx)
{
ctx->use_word=0;
ctx->ri=0;
BN_init(&(ctx->RR));
BN_init(&(ctx->N));
BN_init(&(ctx->Ni));
ctx->flags=0;
}
void BN_MONT_CTX_free(BN_MONT_CTX *mont)
{
if(mont == NULL)
return;
BN_free(&(mont->RR));
BN_free(&(mont->N));
BN_free(&(mont->Ni));
if (mont->flags & BN_FLG_MALLOCED)
Free(mont);
}
int BN_MONT_CTX_set(BN_MONT_CTX *mont, BIGNUM *mod, BN_CTX *ctx)
{
BIGNUM Ri,*R;
BN_init(&Ri);
R= &(mont->RR);
BN_copy(&(mont->N),mod);
#ifdef BN_RECURSION_MONT
if (mont->N.top < BN_MONT_CTX_SET_SIZE_WORD)
#endif
{
BIGNUM tmod;
BN_ULONG buf[2];
mont->use_word=1;
mont->ri=(BN_num_bits(mod)+(BN_BITS2-1))/BN_BITS2*BN_BITS2;
BN_zero(R);
BN_set_bit(R,BN_BITS2);
buf[0]=mod->d[0];
buf[1]=0;
tmod.d=buf;
tmod.top=1;
tmod.max=mod->max;
tmod.neg=mod->neg;
if ((BN_mod_inverse(&Ri,R,&tmod,ctx)) == NULL)
goto err;
BN_lshift(&Ri,&Ri,BN_BITS2);
if (!BN_is_zero(&Ri))
{
#if 1
BN_sub_word(&Ri,1);
#else
BN_usub(&Ri,&Ri,BN_value_one());
#endif
}
else
{
BN_set_word(&Ri,BN_MASK2);
}
BN_div(&Ri,NULL,&Ri,&tmod,ctx);
mont->n0=Ri.d[0];
BN_free(&Ri);
}
#ifdef BN_RECURSION_MONT
else
{
mont->use_word=0;
mont->ri=(BN_num_bits(mod)+(BN_BITS2-1))/BN_BITS2*BN_BITS2;
#if 1
BN_zero(R);
BN_set_bit(R,mont->ri);
#else
BN_lshift(R,BN_value_one(),mont->ri);
#endif
if ((BN_mod_inverse(&Ri,R,mod,ctx)) == NULL)
goto err;
BN_lshift(&Ri,&Ri,mont->ri);
#if 1
BN_sub_word(&Ri,1);
#else
BN_usub(&Ri,&Ri,BN_value_one());
#endif
BN_div(&(mont->Ni),NULL,&Ri,mod,ctx);
BN_free(&Ri);
}
#endif
#if 1
BN_zero(&(mont->RR));
BN_set_bit(&(mont->RR),mont->ri*2);
#else
BN_lshift(mont->RR,BN_value_one(),mont->ri*2);
#endif
BN_mod(&(mont->RR),&(mont->RR),&(mont->N),ctx);
return(1);
err:
return(0);
}
BN_MONT_CTX *BN_MONT_CTX_copy(BN_MONT_CTX *to, BN_MONT_CTX *from)
{
if (to == from) return(to);
BN_copy(&(to->RR),&(from->RR));
BN_copy(&(to->N),&(from->N));
BN_copy(&(to->Ni),&(from->Ni));
to->use_word=from->use_word;
to->ri=from->ri;
to->n0=from->n0;
return(to);
}
