const BIGNUM *BN_get0_nist_prime_192(void)
{
return &_bignum_nist_p_192;
}
const BIGNUM *BN_get0_nist_prime_224(void)
{
return &_bignum_nist_p_224;
}
const BIGNUM *BN_get0_nist_prime_256(void)
{
return &_bignum_nist_p_256;
}
const BIGNUM *BN_get0_nist_prime_384(void)
{
return &_bignum_nist_p_384;
}
const BIGNUM *BN_get0_nist_prime_521(void)
{
return &_bignum_nist_p_521;
}
static void nist_cp_bn_0(BN_ULONG *buf, BN_ULONG *a, int top, int max)
{
int i;
BN_ULONG *_tmp1 = (buf), *_tmp2 = (a);
#ifdef BN_DEBUG
OPENSSL_assert(top <= max);
#endif
for (i = (top); i != 0; i--)
*_tmp1++ = *_tmp2++;
for (i = (max) - (top); i != 0; i--)
*_tmp1++ = (BN_ULONG) 0;
}
static void nist_cp_bn(BN_ULONG *buf, BN_ULONG *a, int top)
{
int i;
BN_ULONG *_tmp1 = (buf), *_tmp2 = (a);
for (i = (top); i != 0; i--)
*_tmp1++ = *_tmp2++;
}
int BN_nist_mod_192(BIGNUM *r, const BIGNUM *a, const BIGNUM *field,
BN_CTX *ctx)
{
int top = a->top, i;
int carry;
register BN_ULONG *r_d, *a_d = a->d;
BN_ULONG t_d[BN_NIST_192_TOP],
buf[BN_NIST_192_TOP],
c_d[BN_NIST_192_TOP],
*res;
size_t mask;
static const BIGNUM _bignum_nist_p_192_sqr = {
(BN_ULONG *)_nist_p_192_sqr,
sizeof(_nist_p_192_sqr)/sizeof(_nist_p_192_sqr[0]),
sizeof(_nist_p_192_sqr)/sizeof(_nist_p_192_sqr[0]),
0,BN_FLG_STATIC_DATA };
field = &_bignum_nist_p_192;
if (BN_is_negative(a) || BN_ucmp(a,&_bignum_nist_p_192_sqr)>=0)
return BN_nnmod(r, a, field, ctx);
i = BN_ucmp(field, a);
if (i == 0)
{
BN_zero(r);
return 1;
}
else if (i > 0)
return (r == a) ? 1 : (BN_copy(r ,a) != NULL);
if (r != a)
{
if (!bn_wexpand(r, BN_NIST_192_TOP))
return 0;
r_d = r->d;
nist_cp_bn(r_d, a_d, BN_NIST_192_TOP);
}
else
r_d = a_d;
nist_cp_bn_0(buf, a_d + BN_NIST_192_TOP, top - BN_NIST_192_TOP, BN_NIST_192_TOP);
nist_set_192(t_d, buf, 0, 3, 3);
carry = (int)bn_add_words(r_d, r_d, t_d, BN_NIST_192_TOP);
nist_set_192(t_d, buf, 4, 4, 0);
carry += (int)bn_add_words(r_d, r_d, t_d, BN_NIST_192_TOP);
nist_set_192(t_d, buf, 5, 5, 5)
carry += (int)bn_add_words(r_d, r_d, t_d, BN_NIST_192_TOP);
if (carry > 0)
carry = (int)bn_sub_words(r_d,r_d,_nist_p_192[carry-1],BN_NIST_192_TOP);
else
carry = 1;
mask = 0-(size_t)bn_sub_words(c_d,r_d,_nist_p_192[0],BN_NIST_192_TOP);
mask &= 0-(size_t)carry;
res = (BN_ULONG *)(((size_t)c_d&~mask) | ((size_t)r_d&mask));
nist_cp_bn(r_d, res, BN_NIST_192_TOP);
r->top = BN_NIST_192_TOP;
bn_correct_top(r);
return 1;
}
int BN_nist_mod_224(BIGNUM *r, const BIGNUM *a, const BIGNUM *field,
BN_CTX *ctx)
{
int top = a->top, i;
int carry;
BN_ULONG *r_d, *a_d = a->d;
BN_ULONG t_d[BN_NIST_224_TOP],
buf[BN_NIST_224_TOP],
c_d[BN_NIST_224_TOP],
*res;
size_t mask;
union { bn_addsub_f f; size_t p; } u;
static const BIGNUM _bignum_nist_p_224_sqr = {
(BN_ULONG *)_nist_p_224_sqr,
sizeof(_nist_p_224_sqr)/sizeof(_nist_p_224_sqr[0]),
sizeof(_nist_p_224_sqr)/sizeof(_nist_p_224_sqr[0]),
0,BN_FLG_STATIC_DATA };
field = &_bignum_nist_p_224;
if (BN_is_negative(a) || BN_ucmp(a,&_bignum_nist_p_224_sqr)>=0)
return BN_nnmod(r, a, field, ctx);
i = BN_ucmp(field, a);
if (i == 0)
{
BN_zero(r);
return 1;
}
else if (i > 0)
return (r == a)? 1 : (BN_copy(r ,a) != NULL);
if (r != a)
{
if (!bn_wexpand(r, BN_NIST_224_TOP))
return 0;
r_d = r->d;
nist_cp_bn(r_d, a_d, BN_NIST_224_TOP);
}
else
r_d = a_d;
#if BN_BITS2==64
nist_cp_bn_0(t_d, a_d + (BN_NIST_224_TOP-1), top - (BN_NIST_224_TOP-1), BN_NIST_224_TOP);
nist_set_224(buf, t_d, 14, 13, 12, 11, 10, 9, 8);
r_d[BN_NIST_224_TOP-1] &= BN_MASK2l;
#else
nist_cp_bn_0(buf, a_d + BN_NIST_224_TOP, top - BN_NIST_224_TOP, BN_NIST_224_TOP);
#endif
nist_set_224(t_d, buf, 10, 9, 8, 7, 0, 0, 0);
carry = (int)bn_add_words(r_d, r_d, t_d, BN_NIST_224_TOP);
nist_set_224(t_d, buf, 0, 13, 12, 11, 0, 0, 0);
carry += (int)bn_add_words(r_d, r_d, t_d, BN_NIST_224_TOP);
nist_set_224(t_d, buf, 13, 12, 11, 10, 9, 8, 7);
carry -= (int)bn_sub_words(r_d, r_d, t_d, BN_NIST_224_TOP);
nist_set_224(t_d, buf, 0, 0, 0, 0, 13, 12, 11);
carry -= (int)bn_sub_words(r_d, r_d, t_d, BN_NIST_224_TOP);
#if BN_BITS2==64
carry = (int)(r_d[BN_NIST_224_TOP-1]>>32);
#endif
u.f = bn_sub_words;
if (carry > 0)
{
carry = (int)bn_sub_words(r_d,r_d,_nist_p_224[carry-1],BN_NIST_224_TOP);
#if BN_BITS2==64
carry=(int)(~(r_d[BN_NIST_224_TOP-1]>>32))&1;
#endif
}
else if (carry < 0)
{
carry = (int)bn_add_words(r_d,r_d,_nist_p_224[-carry-1],BN_NIST_224_TOP);
mask = 0-(size_t)carry;
u.p = ((size_t)bn_sub_words&mask) | ((size_t)bn_add_words&~mask);
}
else
carry = 1;
mask = 0-(size_t)(*u.f)(c_d,r_d,_nist_p_224[0],BN_NIST_224_TOP);
mask &= 0-(size_t)carry;
res = (BN_ULONG *)(((size_t)c_d&~mask) | ((size_t)r_d&mask));
nist_cp_bn(r_d, res, BN_NIST_224_TOP);
r->top = BN_NIST_224_TOP;
bn_correct_top(r);
return 1;
}
int BN_nist_mod_256(BIGNUM *r, const BIGNUM *a, const BIGNUM *field,
BN_CTX *ctx)
{
int i, top = a->top;
int carry = 0;
register BN_ULONG *a_d = a->d, *r_d;
BN_ULONG t_d[BN_NIST_256_TOP],
buf[BN_NIST_256_TOP],
c_d[BN_NIST_256_TOP],
*res;
size_t mask;
union { bn_addsub_f f; size_t p; } u;
static const BIGNUM _bignum_nist_p_256_sqr = {
(BN_ULONG *)_nist_p_256_sqr,
sizeof(_nist_p_256_sqr)/sizeof(_nist_p_256_sqr[0]),
sizeof(_nist_p_256_sqr)/sizeof(_nist_p_256_sqr[0]),
0,BN_FLG_STATIC_DATA };
field = &_bignum_nist_p_256;
if (BN_is_negative(a) || BN_ucmp(a,&_bignum_nist_p_256_sqr)>=0)
return BN_nnmod(r, a, field, ctx);
i = BN_ucmp(field, a);
if (i == 0)
{
BN_zero(r);
return 1;
}
else if (i > 0)
return (r == a)? 1 : (BN_copy(r ,a) != NULL);
if (r != a)
{
if (!bn_wexpand(r, BN_NIST_256_TOP))
return 0;
r_d = r->d;
nist_cp_bn(r_d, a_d, BN_NIST_256_TOP);
}
else
r_d = a_d;
nist_cp_bn_0(buf, a_d + BN_NIST_256_TOP, top - BN_NIST_256_TOP, BN_NIST_256_TOP);
nist_set_256(t_d, buf, 15, 14, 13, 12, 11, 0, 0, 0);
nist_set_256(c_d, buf, 0, 15, 14, 13, 12, 0, 0, 0);
carry = (int)bn_add_words(t_d, t_d, c_d, BN_NIST_256_TOP);
{
register BN_ULONG *ap,t,c;
ap = t_d;
c=0;
for (i = BN_NIST_256_TOP; i != 0; --i)
{
t= *ap;
*(ap++)=((t<<1)|c)&BN_MASK2;
c=(t & BN_TBIT)?1:0;
}
carry <<= 1;
carry |= c;
}
carry += (int)bn_add_words(r_d, r_d, t_d, BN_NIST_256_TOP);
nist_set_256(t_d, buf, 15, 14, 0, 0, 0, 10, 9, 8);
carry += (int)bn_add_words(r_d, r_d, t_d, BN_NIST_256_TOP);
nist_set_256(t_d, buf, 8, 13, 15, 14, 13, 11, 10, 9);
carry += (int)bn_add_words(r_d, r_d, t_d, BN_NIST_256_TOP);
nist_set_256(t_d, buf, 10, 8, 0, 0, 0, 13, 12, 11);
carry -= (int)bn_sub_words(r_d, r_d, t_d, BN_NIST_256_TOP);
nist_set_256(t_d, buf, 11, 9, 0, 0, 15, 14, 13, 12);
carry -= (int)bn_sub_words(r_d, r_d, t_d, BN_NIST_256_TOP);
nist_set_256(t_d, buf, 12, 0, 10, 9, 8, 15, 14, 13);
carry -= (int)bn_sub_words(r_d, r_d, t_d, BN_NIST_256_TOP);
nist_set_256(t_d, buf, 13, 0, 11, 10, 9, 0, 15, 14);
carry -= (int)bn_sub_words(r_d, r_d, t_d, BN_NIST_256_TOP);
u.f = bn_sub_words;
if (carry > 0)
carry = (int)bn_sub_words(r_d,r_d,_nist_p_256[carry-1],BN_NIST_256_TOP);
else if (carry < 0)
{
carry = (int)bn_add_words(r_d,r_d,_nist_p_256[-carry-1],BN_NIST_256_TOP);
mask = 0-(size_t)carry;
u.p = ((size_t)bn_sub_words&mask) | ((size_t)bn_add_words&~mask);
}
else
carry = 1;
mask = 0-(size_t)(*u.f)(c_d,r_d,_nist_p_256[0],BN_NIST_256_TOP);
mask &= 0-(size_t)carry;
res = (BN_ULONG *)(((size_t)c_d&~mask) | ((size_t)r_d&mask));
nist_cp_bn(r_d, res, BN_NIST_256_TOP);
r->top = BN_NIST_256_TOP;
bn_correct_top(r);
return 1;
}
int BN_nist_mod_384(BIGNUM *r, const BIGNUM *a, const BIGNUM *field,
BN_CTX *ctx)
{
int i, top = a->top;
int carry = 0;
register BN_ULONG *r_d, *a_d = a->d;
BN_ULONG t_d[BN_NIST_384_TOP],
buf[BN_NIST_384_TOP],
c_d[BN_NIST_384_TOP],
*res;
size_t mask;
union { bn_addsub_f f; size_t p; } u;
static const BIGNUM _bignum_nist_p_384_sqr = {
(BN_ULONG *)_nist_p_384_sqr,
sizeof(_nist_p_384_sqr)/sizeof(_nist_p_384_sqr[0]),
sizeof(_nist_p_384_sqr)/sizeof(_nist_p_384_sqr[0]),
0,BN_FLG_STATIC_DATA };
field = &_bignum_nist_p_384;
if (BN_is_negative(a) || BN_ucmp(a,&_bignum_nist_p_384_sqr)>=0)
return BN_nnmod(r, a, field, ctx);
i = BN_ucmp(field, a);
if (i == 0)
{
BN_zero(r);
return 1;
}
else if (i > 0)
return (r == a)? 1 : (BN_copy(r ,a) != NULL);
if (r != a)
{
if (!bn_wexpand(r, BN_NIST_384_TOP))
return 0;
r_d = r->d;
nist_cp_bn(r_d, a_d, BN_NIST_384_TOP);
}
else
r_d = a_d;
nist_cp_bn_0(buf, a_d + BN_NIST_384_TOP, top - BN_NIST_384_TOP, BN_NIST_384_TOP);
nist_set_256(t_d, buf, 0, 0, 0, 0, 0, 23-4, 22-4, 21-4);
{
register BN_ULONG *ap,t,c;
ap = t_d;
c=0;
for (i = 3; i != 0; --i)
{
t= *ap;
*(ap++)=((t<<1)|c)&BN_MASK2;
c=(t & BN_TBIT)?1:0;
}
*ap=c;
}
carry = (int)bn_add_words(r_d+(128/BN_BITS2), r_d+(128/BN_BITS2),
t_d, BN_NIST_256_TOP);
carry += (int)bn_add_words(r_d, r_d, buf, BN_NIST_384_TOP);
nist_set_384(t_d,buf,20,19,18,17,16,15,14,13,12,23,22,21);
carry += (int)bn_add_words(r_d, r_d, t_d, BN_NIST_384_TOP);
nist_set_384(t_d,buf,19,18,17,16,15,14,13,12,20,0,23,0);
carry += (int)bn_add_words(r_d, r_d, t_d, BN_NIST_384_TOP);
nist_set_384(t_d, buf,0,0,0,0,23,22,21,20,0,0,0,0);
carry += (int)bn_add_words(r_d, r_d, t_d, BN_NIST_384_TOP);
nist_set_384(t_d,buf,0,0,0,0,0,0,23,22,21,0,0,20);
carry += (int)bn_add_words(r_d, r_d, t_d, BN_NIST_384_TOP);
nist_set_384(t_d,buf,22,21,20,19,18,17,16,15,14,13,12,23);
carry -= (int)bn_sub_words(r_d, r_d, t_d, BN_NIST_384_TOP);
nist_set_384(t_d,buf,0,0,0,0,0,0,0,23,22,21,20,0);
carry -= (int)bn_sub_words(r_d, r_d, t_d, BN_NIST_384_TOP);
nist_set_384(t_d,buf,0,0,0,0,0,0,0,23,23,0,0,0);
carry -= (int)bn_sub_words(r_d, r_d, t_d, BN_NIST_384_TOP);
u.f = bn_sub_words;
if (carry > 0)
carry = (int)bn_sub_words(r_d,r_d,_nist_p_384[carry-1],BN_NIST_384_TOP);
else if (carry < 0)
{
carry = (int)bn_add_words(r_d,r_d,_nist_p_384[-carry-1],BN_NIST_384_TOP);
mask = 0-(size_t)carry;
u.p = ((size_t)bn_sub_words&mask) | ((size_t)bn_add_words&~mask);
}
else
carry = 1;
mask = 0-(size_t)(*u.f)(c_d,r_d,_nist_p_384[0],BN_NIST_384_TOP);
mask &= 0-(size_t)carry;
res = (BN_ULONG *)(((size_t)c_d&~mask) | ((size_t)r_d&mask));
nist_cp_bn(r_d, res, BN_NIST_384_TOP);
r->top = BN_NIST_384_TOP;
bn_correct_top(r);
return 1;
}
int BN_nist_mod_521(BIGNUM *r, const BIGNUM *a, const BIGNUM *field,
BN_CTX *ctx)
{
int top = a->top, i;
BN_ULONG *r_d, *a_d = a->d,
t_d[BN_NIST_521_TOP],
val,tmp,*res;
size_t mask;
static const BIGNUM _bignum_nist_p_521_sqr = {
(BN_ULONG *)_nist_p_521_sqr,
sizeof(_nist_p_521_sqr)/sizeof(_nist_p_521_sqr[0]),
sizeof(_nist_p_521_sqr)/sizeof(_nist_p_521_sqr[0]),
0,BN_FLG_STATIC_DATA };
field = &_bignum_nist_p_521;
if (BN_is_negative(a) || BN_ucmp(a,&_bignum_nist_p_521_sqr)>=0)
return BN_nnmod(r, a, field, ctx);
i = BN_ucmp(field, a);
if (i == 0)
{
BN_zero(r);
return 1;
}
else if (i > 0)
return (r == a)? 1 : (BN_copy(r ,a) != NULL);
if (r != a)
{
if (!bn_wexpand(r,BN_NIST_521_TOP))
return 0;
r_d = r->d;
nist_cp_bn(r_d,a_d, BN_NIST_521_TOP);
}
else
r_d = a_d;
nist_cp_bn_0(t_d,a_d + (BN_NIST_521_TOP-1), top - (BN_NIST_521_TOP-1),BN_NIST_521_TOP);
for (val=t_d[0],i=0; i<BN_NIST_521_TOP-1; i++)
{
tmp = val>>BN_NIST_521_RSHIFT;
val = t_d[i+1];
t_d[i] = (tmp | val<<BN_NIST_521_LSHIFT) & BN_MASK2;
}
t_d[i] = val>>BN_NIST_521_RSHIFT;
r_d[i] &= BN_NIST_521_TOP_MASK;
bn_add_words(r_d,r_d,t_d,BN_NIST_521_TOP);
mask = 0-(size_t)bn_sub_words(t_d,r_d,_nist_p_521,BN_NIST_521_TOP);
res = (BN_ULONG *)(((size_t)t_d&~mask) | ((size_t)r_d&mask));
nist_cp_bn(r_d,res,BN_NIST_521_TOP);
r->top = BN_NIST_521_TOP;
bn_correct_top(r);
return 1;
}
