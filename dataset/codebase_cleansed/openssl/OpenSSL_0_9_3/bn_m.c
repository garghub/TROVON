BIGNUM *BN_POOL_push(BN_POOL *bp)
{
BIGNUM *ret;
if (bp->used >= bp->tos)
{
ret=BN_new();
sk_push(bp->sk,(char *)ret);
bp->tos++;
bp->used++;
}
else
{
ret=(BIGNUM *)sk_value(bp->sk,bp->used);
bp->used++;
}
return(ret);
}
void BN_POOL_pop(BN_POOL *bp, int num)
{
bp->used-=num;
}
int BN_m(BIGNUM *r, BIGNUM *a, BIGNUM *b)
{
static BN_POOL bp;
static init=1;
if (init)
{
bp.used=0;
bp.tos=0;
bp.sk=sk_new_null();
init=0;
}
return(BN_mm(r,a,b,&bp));
}
int BN_mm(BIGNUM *m, BIGNUM *A, BIGNUM *B, BN_POOL *bp)
{
int i,num;
int an,bn;
BIGNUM *a,*b,*c,*d,*ac,*bd;
an=A->top;
bn=B->top;
if ((an <= limit) || (bn <= limit))
{
return(BN_mul(m,A,B));
}
a=BN_POOL_push(bp);
b=BN_POOL_push(bp);
c=BN_POOL_push(bp);
d=BN_POOL_push(bp);
ac=BN_POOL_push(bp);
bd=BN_POOL_push(bp);
num=(an <= bn)?an:bn;
num=1<<(BN_num_bits_word(num-1)-1);
num*=BN_BITS2;
BN_copy(a,A);
BN_mask_bits(a,num);
BN_rshift(b,A,num);
BN_copy(c,B);
BN_mask_bits(c,num);
BN_rshift(d,B,num);
BN_sub(ac ,b,a);
BN_sub(bd,c,d);
BN_mm(m,ac,bd,bp);
BN_mm(ac,a,c,bp);
BN_mm(bd,b,d,bp);
BN_add(m,m,ac);
BN_add(m,m,bd);
BN_lshift(m,m,num);
BN_lshift(bd,bd,num*2);
BN_add(m,m,ac);
BN_add(m,m,bd);
BN_POOL_pop(bp,6);
return(1);
}
