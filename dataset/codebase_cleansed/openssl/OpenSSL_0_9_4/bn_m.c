int BN_m(BIGNUM *r, BIGNUM *a, BIGNUM *b)
{
BIGNUM *sk;
int i,n;
n=(BN_num_bits_word(a->top|b->top)-limit_bits);
n*=2;
sk=(BIGNUM *)malloc(sizeof(BIGNUM)*n);
for (i=0; i<n; i++)
BN_init(&(sk[i]));
return(BN_mm(r,a,b,&(sk[0])));
}
int BN_mm(BIGNUM *m, BIGNUM *A, BIGNUM *B, BIGNUM *sk)
{
int i,num,anum,bnum;
int an,bn;
BIGNUM ah,al,bh,bl;
an=A->top;
bn=B->top;
if ((an <= limit_num) || (bn <= limit_num))
{
return(BN_mul(m,A,B));
}
anum=(an>bn)?an:bn;
num=(anum)/2;
bnum=num*BN_BITS2;
BN_init(&ahal);
BN_init(&blbh);
BN_init(&ah);
BN_init(&al);
BN_init(&bh);
BN_init(&bl);
al.top=num;
al.d=A->d;
ah.top=A->top-num;
ah.d= &(A->d[num]);
bl.top=num;
bl.d=B->d;
bh.top=B->top-num;
bh.d= &(B->d[num]);
BN_sub(&ahal,&ah,&al);
BN_sub(&blbh,&bl,&bh);
BN_mm(m,&ahal,&blbh,&(sk[2]));
BN_mm(&ahal,&al,&bl,&(sk[2]));
BN_mm(&blbh,&ah,&bh,&(sk[2]));
BN_add(m,m,&ahal);
BN_add(m,m,&blbh);
BN_lshift(m,m,bnum);
BN_add(m,m,&ahal);
BN_lshift(&blbh,&blbh,bnum*2);
BN_add(m,m,&blbh);
m->neg=A->neg^B->neg;
return(1);
}
