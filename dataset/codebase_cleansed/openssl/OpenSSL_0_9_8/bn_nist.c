const BIGNUM *BN_get0_nist_prime_192(void)
{
static BIGNUM const_nist_192 = { (BN_ULONG *)_nist_p_192,
BN_NIST_192_TOP, BN_NIST_192_TOP, 0, BN_FLG_STATIC_DATA };
return &const_nist_192;
}
const BIGNUM *BN_get0_nist_prime_224(void)
{
static BIGNUM const_nist_224 = { (BN_ULONG *)_nist_p_224,
BN_NIST_224_TOP, BN_NIST_224_TOP, 0, BN_FLG_STATIC_DATA };
return &const_nist_224;
}
const BIGNUM *BN_get0_nist_prime_256(void)
{
static BIGNUM const_nist_256 = { (BN_ULONG *)_nist_p_256,
BN_NIST_256_TOP, BN_NIST_256_TOP, 0, BN_FLG_STATIC_DATA };
return &const_nist_256;
}
const BIGNUM *BN_get0_nist_prime_384(void)
{
static BIGNUM const_nist_384 = { (BN_ULONG *)_nist_p_384,
BN_NIST_384_TOP, BN_NIST_384_TOP, 0, BN_FLG_STATIC_DATA };
return &const_nist_384;
}
const BIGNUM *BN_get0_nist_prime_521(void)
{
static BIGNUM const_nist_521 = { (BN_ULONG *)_nist_p_521,
BN_NIST_521_TOP, BN_NIST_521_TOP, 0, BN_FLG_STATIC_DATA };
return &const_nist_521;
}
static void nist_cp_bn_0(BN_ULONG *buf, BN_ULONG *a, int top, int max)
{
int i;
BN_ULONG *_tmp1 = (buf), *_tmp2 = (a);
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
BN_ULONG carry = 0;
register BN_ULONG *r_d, *a_d = a->d;
BN_ULONG t_d[BN_NIST_192_TOP],
buf[BN_NIST_192_TOP];
i = BN_ucmp(field, a);
if (i == 0)
{
BN_zero(r);
return 1;
}
else if (i > 0)
return (r == a) ? 1 : (BN_copy(r ,a) != NULL);
if (top == BN_NIST_192_TOP)
return BN_usub(r, a, field);
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
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma message save
# pragma message disable BADSUBSCRIPT
#endif
nist_set_192(t_d, buf, 0, 3, 3);
if (bn_add_words(r_d, r_d, t_d, BN_NIST_192_TOP))
++carry;
nist_set_192(t_d, buf, 4, 4, 0);
if (bn_add_words(r_d, r_d, t_d, BN_NIST_192_TOP))
++carry;
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma message restore
#endif
nist_set_192(t_d, buf, 5, 5, 5)
if (bn_add_words(r_d, r_d, t_d, BN_NIST_192_TOP))
++carry;
while (carry)
{
if (bn_sub_words(r_d, r_d, _nist_p_192, BN_NIST_192_TOP))
--carry;
}
r->top = BN_NIST_192_TOP;
bn_correct_top(r);
if (BN_ucmp(r, field) >= 0)
{
bn_sub_words(r_d, r_d, _nist_p_192, BN_NIST_192_TOP);
bn_correct_top(r);
}
bn_check_top(r);
return 1;
}
int BN_nist_mod_224(BIGNUM *r, const BIGNUM *a, const BIGNUM *field,
BN_CTX *ctx)
{
#if BN_BITS2 != 64
int top = a->top, i;
int carry = 0;
BN_ULONG *r_d, *a_d = a->d;
BN_ULONG t_d[BN_NIST_224_TOP],
buf[BN_NIST_224_TOP];
i = BN_ucmp(field, a);
if (i == 0)
{
BN_zero(r);
return 1;
}
else if (i > 0)
return (r == a)? 1 : (BN_copy(r ,a) != NULL);
if (top == BN_NIST_224_TOP)
return BN_usub(r, a, field);
if (r != a)
{
if (!bn_wexpand(r, BN_NIST_224_TOP))
return 0;
r_d = r->d;
nist_cp_bn(r_d, a_d, BN_NIST_224_TOP);
}
else
r_d = a_d;
nist_cp_bn_0(buf, a_d + BN_NIST_224_TOP, top - BN_NIST_224_TOP, BN_NIST_224_TOP);
nist_set_224(t_d, buf, 10, 9, 8, 7, 0, 0, 0);
if (bn_add_words(r_d, r_d, t_d, BN_NIST_224_TOP))
++carry;
nist_set_224(t_d, buf, 0, 13, 12, 11, 0, 0, 0);
if (bn_add_words(r_d, r_d, t_d, BN_NIST_224_TOP))
++carry;
nist_set_224(t_d, buf, 13, 12, 11, 10, 9, 8, 7);
if (bn_sub_words(r_d, r_d, t_d, BN_NIST_224_TOP))
--carry;
nist_set_224(t_d, buf, 0, 0, 0, 0, 13, 12, 11);
if (bn_sub_words(r_d, r_d, t_d, BN_NIST_224_TOP))
--carry;
if (carry > 0)
while (carry)
{
if (bn_sub_words(r_d,r_d,_nist_p_224,BN_NIST_224_TOP))
--carry;
}
else if (carry < 0)
while (carry)
{
if (bn_add_words(r_d,r_d,_nist_p_224,BN_NIST_224_TOP))
++carry;
}
r->top = BN_NIST_224_TOP;
bn_correct_top(r);
if (BN_ucmp(r, field) >= 0)
{
bn_sub_words(r_d, r_d, _nist_p_224, BN_NIST_224_TOP);
bn_correct_top(r);
}
bn_check_top(r);
return 1;
#else
return 0;
#endif
}
static void _init_256_data(void)
{
int i;
BN_ULONG *tmp1 = _256_data;
const BN_ULONG *tmp2 = tmp1;
memcpy(tmp1, _nist_p_256, BN_NIST_256_TOP * sizeof(BN_ULONG));
tmp1 += BN_NIST_256_TOP;
for (i=0; i<5; i++)
{
bn_add_words(tmp1, _nist_p_256, tmp2, BN_NIST_256_TOP);
tmp2 = tmp1;
tmp1 += BN_NIST_256_TOP;
}
_is_set_256_data = 1;
}
int BN_nist_mod_256(BIGNUM *r, const BIGNUM *a, const BIGNUM *field,
BN_CTX *ctx)
{
#if BN_BITS2 != 64
int i, top = a->top;
int carry = 0;
register BN_ULONG *a_d = a->d, *r_d;
BN_ULONG t_d[BN_NIST_256_TOP],
t_d2[BN_NIST_256_TOP],
buf[BN_NIST_256_TOP];
if (!_is_set_256_data)
{
CRYPTO_w_lock(CRYPTO_LOCK_BN);
if (!_is_set_256_data)
_init_256_data();
CRYPTO_w_unlock(CRYPTO_LOCK_BN);
}
i = BN_ucmp(field, a);
if (i == 0)
{
BN_zero(r);
return 1;
}
else if (i > 0)
return (r == a)? 1 : (BN_copy(r ,a) != NULL);
if (top == BN_NIST_256_TOP)
return BN_usub(r, a, field);
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
nist_set_256(t_d2,buf, 0, 15, 14, 13, 12, 0, 0, 0);
if (bn_add_words(t_d, t_d, t_d2, BN_NIST_256_TOP))
carry = 2;
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
if (c)
++carry;
}
if (bn_add_words(r_d, r_d, t_d, BN_NIST_256_TOP))
++carry;
nist_set_256(t_d, buf, 15, 14, 0, 0, 0, 10, 9, 8);
if (bn_add_words(r_d, r_d, t_d, BN_NIST_256_TOP))
++carry;
nist_set_256(t_d, buf, 8, 13, 15, 14, 13, 11, 10, 9);
if (bn_add_words(r_d, r_d, t_d, BN_NIST_256_TOP))
++carry;
nist_set_256(t_d, buf, 10, 8, 0, 0, 0, 13, 12, 11);
if (bn_sub_words(r_d, r_d, t_d, BN_NIST_256_TOP))
--carry;
nist_set_256(t_d, buf, 11, 9, 0, 0, 15, 14, 13, 12);
if (bn_sub_words(r_d, r_d, t_d, BN_NIST_256_TOP))
--carry;
nist_set_256(t_d, buf, 12, 0, 10, 9, 8, 15, 14, 13);
if (bn_sub_words(r_d, r_d, t_d, BN_NIST_256_TOP))
--carry;
nist_set_256(t_d, buf, 13, 0, 11, 10, 9, 0, 15, 14);
if (bn_sub_words(r_d, r_d, t_d, BN_NIST_256_TOP))
--carry;
if (carry)
{
if (carry > 0)
bn_sub_words(r_d, r_d, _256_data + BN_NIST_256_TOP *
--carry, BN_NIST_256_TOP);
else
{
carry = -carry;
bn_add_words(r_d, r_d, _256_data + BN_NIST_256_TOP *
--carry, BN_NIST_256_TOP);
}
}
r->top = BN_NIST_256_TOP;
bn_correct_top(r);
if (BN_ucmp(r, field) >= 0)
{
bn_sub_words(r_d, r_d, _nist_p_256, BN_NIST_256_TOP);
bn_correct_top(r);
}
bn_check_top(r);
return 1;
#else
return 0;
#endif
}
static void _init_384_data(void)
{
int i;
BN_ULONG *tmp1 = _384_data;
const BN_ULONG *tmp2 = tmp1;
memcpy(tmp1, _nist_p_384, BN_NIST_384_TOP * sizeof(BN_ULONG));
tmp1 += BN_NIST_384_TOP;
for (i=0; i<7; i++)
{
bn_add_words(tmp1, _nist_p_384, tmp2, BN_NIST_384_TOP);
tmp2 = tmp1;
tmp1 += BN_NIST_384_TOP;
}
_is_set_384_data = 1;
}
int BN_nist_mod_384(BIGNUM *r, const BIGNUM *a, const BIGNUM *field,
BN_CTX *ctx)
{
#if BN_BITS2 != 64
int i, top = a->top;
int carry = 0;
register BN_ULONG *r_d, *a_d = a->d;
BN_ULONG t_d[BN_NIST_384_TOP],
buf[BN_NIST_384_TOP];
if (!_is_set_384_data)
{
CRYPTO_w_lock(CRYPTO_LOCK_BN);
if (!_is_set_384_data)
_init_384_data();
CRYPTO_w_unlock(CRYPTO_LOCK_BN);
}
i = BN_ucmp(field, a);
if (i == 0)
{
BN_zero(r);
return 1;
}
else if (i > 0)
return (r == a)? 1 : (BN_copy(r ,a) != NULL);
if (top == BN_NIST_384_TOP)
return BN_usub(r, a, field);
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
for (i = BN_NIST_256_TOP; i != 0; --i)
{
t= *ap;
*(ap++)=((t<<1)|c)&BN_MASK2;
c=(t & BN_TBIT)?1:0;
}
}
if (bn_add_words(r_d+(128/BN_BITS2), r_d+(128/BN_BITS2),
t_d, BN_NIST_256_TOP))
++carry;
if (bn_add_words(r_d, r_d, buf, BN_NIST_384_TOP))
++carry;
nist_set_384(t_d,buf,20,19,18,17,16,15,14,13,12,23,22,21);
if (bn_add_words(r_d, r_d, t_d, BN_NIST_384_TOP))
++carry;
nist_set_384(t_d,buf,19,18,17,16,15,14,13,12,20,0,23,0);
if (bn_add_words(r_d, r_d, t_d, BN_NIST_384_TOP))
++carry;
nist_set_256(t_d, buf, 0, 0, 0, 0, 23-4, 22-4, 21-4, 20-4);
if (bn_add_words(r_d+(128/BN_BITS2), r_d+(128/BN_BITS2),
t_d, BN_NIST_256_TOP))
++carry;
nist_set_384(t_d,buf,0,0,0,0,0,0,23,22,21,0,0,20);
if (bn_add_words(r_d, r_d, t_d, BN_NIST_384_TOP))
++carry;
nist_set_384(t_d,buf,22,21,20,19,18,17,16,15,14,13,12,23);
if (bn_sub_words(r_d, r_d, t_d, BN_NIST_384_TOP))
--carry;
nist_set_384(t_d,buf,0,0,0,0,0,0,0,23,22,21,20,0);
if (bn_sub_words(r_d, r_d, t_d, BN_NIST_384_TOP))
--carry;
nist_set_384(t_d,buf,0,0,0,0,0,0,0,23,23,0,0,0);
if (bn_sub_words(r_d, r_d, t_d, BN_NIST_384_TOP))
--carry;
if (carry)
{
if (carry > 0)
bn_sub_words(r_d, r_d, _384_data + BN_NIST_384_TOP *
--carry, BN_NIST_384_TOP);
else
{
carry = -carry;
bn_add_words(r_d, r_d, _384_data + BN_NIST_384_TOP *
--carry, BN_NIST_384_TOP);
}
}
r->top = BN_NIST_384_TOP;
bn_correct_top(r);
if (BN_ucmp(r, field) >= 0)
{
bn_sub_words(r_d, r_d, _nist_p_384, BN_NIST_384_TOP);
bn_correct_top(r);
}
bn_check_top(r);
return 1;
#else
return 0;
#endif
}
int BN_nist_mod_521(BIGNUM *r, const BIGNUM *a, const BIGNUM *field,
BN_CTX *ctx)
{
#if BN_BITS2 == 64
#define BN_NIST_521_TOP_MASK (BN_ULONG)0x1FF
#elif BN_BITS2 == 32
#define BN_NIST_521_TOP_MASK (BN_ULONG)0x1FF
#elif BN_BITS2 == 16
#define BN_NIST_521_TOP_MASK (BN_ULONG)0x1FF
#elif BN_BITS2 == 8
#define BN_NIST_521_TOP_MASK (BN_ULONG)0x1
#endif
int top, ret = 0;
BN_ULONG *r_d;
BIGNUM *tmp;
top = a->top;
if (top < BN_NIST_521_TOP || ( top == BN_NIST_521_TOP &&
(!(a->d[BN_NIST_521_TOP-1] & ~(BN_NIST_521_TOP_MASK)))))
return (r == a)? 1 : (BN_copy(r ,a) != NULL);
BN_CTX_start(ctx);
tmp = BN_CTX_get(ctx);
if (!tmp)
goto err;
if (!bn_wexpand(tmp, BN_NIST_521_TOP))
goto err;
nist_cp_bn(tmp->d, a->d, BN_NIST_521_TOP);
tmp->top = BN_NIST_521_TOP;
tmp->d[BN_NIST_521_TOP-1] &= BN_NIST_521_TOP_MASK;
bn_correct_top(tmp);
if (!BN_rshift(r, a, 521))
goto err;
if (!BN_uadd(r, tmp, r))
goto err;
top = r->top;
r_d = r->d;
if (top == BN_NIST_521_TOP &&
(r_d[BN_NIST_521_TOP-1] & ~(BN_NIST_521_TOP_MASK)))
{
BN_NIST_ADD_ONE(r_d)
r_d[BN_NIST_521_TOP-1] &= BN_NIST_521_TOP_MASK;
}
bn_correct_top(r);
ret = 1;
err:
BN_CTX_end(ctx);
bn_check_top(r);
return ret;
}
