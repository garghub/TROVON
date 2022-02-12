int BN_mul_high(BIGNUM *r, BIGNUM *a, BIGNUM *b, BIGNUM *low, int words)
{
int w2,borrow=0,full=0;
BIGNUM t1,t2,t3,h,ah,al,bh,bl,m,s0,s1;
BN_ULONG ul1,ul2;
BN_mul(r,a,b);
BN_rshift(r,r,words*BN_BITS2);
return(1);
w2=(words+1)/2;
#ifdef BN_MUL_HIGH_DEBUG
fprintf(stdout,"words=%d w2=%d\n",words,w2);
#endif
debug_BN_print(stdout,a," a\n");
debug_BN_print(stdout,b," b\n");
debug_BN_print(stdout,low," low\n");
BN_init(&al); BN_init(&ah);
BN_init(&bl); BN_init(&bh);
BN_init(&t1); BN_init(&t2); BN_init(&t3);
BN_init(&s0); BN_init(&s1);
BN_init(&h); BN_init(&m);
bn_set_low (&al,a,w2);
bn_set_high(&ah,a,w2);
bn_set_low (&bl,b,w2);
bn_set_high(&bh,b,w2);
bn_set_low(&s0,low,w2);
bn_set_high(&s1,low,w2);
debug_BN_print(stdout,&al," al\n");
debug_BN_print(stdout,&ah," ah\n");
debug_BN_print(stdout,&bl," bl\n");
debug_BN_print(stdout,&bh," bh\n");
debug_BN_print(stdout,&s0," s0\n");
debug_BN_print(stdout,&s1," s1\n");
BN_sub(&t1,&al,&ah);
BN_sub(&t2,&bh,&bl);
BN_mul(&m,&t1,&t2);
BN_mul(&h,&ah,&bh);
BN_add(&m,&m,&h);
BN_add(&t2,&m,&s0);
debug_BN_print(stdout,&t2," middle value\n");
if (w2 < t2.top) t2.top=w2;
#if 0
bn_set_low(&t3,&t2,w2);
#endif
debug_BN_print(stdout,&t2," low middle value\n");
BN_sub(&t1,&s1,&t2);
if (t1.neg)
{
debug_BN_print(stdout,&t1," before\n");
BN_zero(&t2);
BN_set_bit(&t2,w2*BN_BITS2);
BN_add(&t1,&t2,&t1);
debug_BN_print(stdout,&t1," after\n");
borrow=1;
}
BN_lshift(&t1,&t1,w2*BN_BITS2);
BN_add(&t1,&t1,&s0);
if (w2*2 < t1.top) t1.top=w2*2;
#if 0
BN_add(&m,&m,&t1);
debug_BN_print(stdout,&t1," s10\n");
debug_BN_print(stdout,&m," s21\n");
debug_BN_print(stdout,&h," s32\n");
BN_lshift(&m,&m,w2*BN_BITS2);
BN_lshift(&h,&h,w2*2*BN_BITS2);
BN_add(r,&m,&t1);
BN_add(r,r,&h);
BN_rshift(r,r,w2*2*BN_BITS2);
#else
BN_add(&m,&m,&t1);
bn_set_high(&t3,&t1,w2);
BN_add(&m,&m,&t3);
bn_set_high(&t3,&m,w2);
BN_add(r,&h,&t3);
#endif
#ifdef BN_MUL_HIGH_DEBUG
printf("carry=%d\n",borrow);
#endif
debug_BN_print(stdout,r," ret\n");
BN_free(&t1); BN_free(&t2);
BN_free(&m); BN_free(&h);
return(1);
}
