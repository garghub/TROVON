static void bn_GF2m_mul_1x1(BN_ULONG *r1, BN_ULONG *r0, const BN_ULONG a, const BN_ULONG b)
{
register BN_ULONG h, l, s;
BN_ULONG tab[8], top2b = a >> 30;
register BN_ULONG a1, a2, a4;
a1 = a & (0x3FFFFFFF); a2 = a1 << 1; a4 = a2 << 1;
tab[0] = 0; tab[1] = a1; tab[2] = a2; tab[3] = a1^a2;
tab[4] = a4; tab[5] = a1^a4; tab[6] = a2^a4; tab[7] = a1^a2^a4;
s = tab[b & 0x7]; l = s;
s = tab[b >> 3 & 0x7]; l ^= s << 3; h = s >> 29;
s = tab[b >> 6 & 0x7]; l ^= s << 6; h ^= s >> 26;
s = tab[b >> 9 & 0x7]; l ^= s << 9; h ^= s >> 23;
s = tab[b >> 12 & 0x7]; l ^= s << 12; h ^= s >> 20;
s = tab[b >> 15 & 0x7]; l ^= s << 15; h ^= s >> 17;
s = tab[b >> 18 & 0x7]; l ^= s << 18; h ^= s >> 14;
s = tab[b >> 21 & 0x7]; l ^= s << 21; h ^= s >> 11;
s = tab[b >> 24 & 0x7]; l ^= s << 24; h ^= s >> 8;
s = tab[b >> 27 & 0x7]; l ^= s << 27; h ^= s >> 5;
s = tab[b >> 30 ]; l ^= s << 30; h ^= s >> 2;
if (top2b & 01) { l ^= b << 30; h ^= b >> 2; }
if (top2b & 02) { l ^= b << 31; h ^= b >> 1; }
*r1 = h; *r0 = l;
}
static void bn_GF2m_mul_1x1(BN_ULONG *r1, BN_ULONG *r0, const BN_ULONG a, const BN_ULONG b)
{
register BN_ULONG h, l, s;
BN_ULONG tab[16], top3b = a >> 61;
register BN_ULONG a1, a2, a4, a8;
a1 = a & (0x1FFFFFFFFFFFFFFFULL); a2 = a1 << 1; a4 = a2 << 1; a8 = a4 << 1;
tab[ 0] = 0; tab[ 1] = a1; tab[ 2] = a2; tab[ 3] = a1^a2;
tab[ 4] = a4; tab[ 5] = a1^a4; tab[ 6] = a2^a4; tab[ 7] = a1^a2^a4;
tab[ 8] = a8; tab[ 9] = a1^a8; tab[10] = a2^a8; tab[11] = a1^a2^a8;
tab[12] = a4^a8; tab[13] = a1^a4^a8; tab[14] = a2^a4^a8; tab[15] = a1^a2^a4^a8;
s = tab[b & 0xF]; l = s;
s = tab[b >> 4 & 0xF]; l ^= s << 4; h = s >> 60;
s = tab[b >> 8 & 0xF]; l ^= s << 8; h ^= s >> 56;
s = tab[b >> 12 & 0xF]; l ^= s << 12; h ^= s >> 52;
s = tab[b >> 16 & 0xF]; l ^= s << 16; h ^= s >> 48;
s = tab[b >> 20 & 0xF]; l ^= s << 20; h ^= s >> 44;
s = tab[b >> 24 & 0xF]; l ^= s << 24; h ^= s >> 40;
s = tab[b >> 28 & 0xF]; l ^= s << 28; h ^= s >> 36;
s = tab[b >> 32 & 0xF]; l ^= s << 32; h ^= s >> 32;
s = tab[b >> 36 & 0xF]; l ^= s << 36; h ^= s >> 28;
s = tab[b >> 40 & 0xF]; l ^= s << 40; h ^= s >> 24;
s = tab[b >> 44 & 0xF]; l ^= s << 44; h ^= s >> 20;
s = tab[b >> 48 & 0xF]; l ^= s << 48; h ^= s >> 16;
s = tab[b >> 52 & 0xF]; l ^= s << 52; h ^= s >> 12;
s = tab[b >> 56 & 0xF]; l ^= s << 56; h ^= s >> 8;
s = tab[b >> 60 ]; l ^= s << 60; h ^= s >> 4;
if (top3b & 01) { l ^= b << 61; h ^= b >> 3; }
if (top3b & 02) { l ^= b << 62; h ^= b >> 2; }
if (top3b & 04) { l ^= b << 63; h ^= b >> 1; }
*r1 = h; *r0 = l;
}
static void bn_GF2m_mul_2x2(BN_ULONG *r, const BN_ULONG a1, const BN_ULONG a0, const BN_ULONG b1, const BN_ULONG b0)
{
BN_ULONG m1, m0;
bn_GF2m_mul_1x1(r+3, r+2, a1, b1);
bn_GF2m_mul_1x1(r+1, r, a0, b0);
bn_GF2m_mul_1x1(&m1, &m0, a0 ^ a1, b0 ^ b1);
r[2] ^= m1 ^ r[1] ^ r[3];
r[1] = r[3] ^ r[2] ^ r[0] ^ m1 ^ m0;
}
int BN_GF2m_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b)
{
int i;
const BIGNUM *at, *bt;
bn_check_top(a);
bn_check_top(b);
if (a->top < b->top) { at = b; bt = a; }
else { at = a; bt = b; }
if(bn_wexpand(r, at->top) == NULL)
return 0;
for (i = 0; i < bt->top; i++)
{
r->d[i] = at->d[i] ^ bt->d[i];
}
for (; i < at->top; i++)
{
r->d[i] = at->d[i];
}
r->top = at->top;
bn_correct_top(r);
return 1;
}
int BN_GF2m_mod_arr(BIGNUM *r, const BIGNUM *a, const int p[])
{
int j, k;
int n, dN, d0, d1;
BN_ULONG zz, *z;
bn_check_top(a);
if (!p[0])
{
BN_zero(r);
return 1;
}
if (a != r)
{
if (!bn_wexpand(r, a->top)) return 0;
for (j = 0; j < a->top; j++)
{
r->d[j] = a->d[j];
}
r->top = a->top;
}
z = r->d;
dN = p[0] / BN_BITS2;
for (j = r->top - 1; j > dN;)
{
zz = z[j];
if (z[j] == 0) { j--; continue; }
z[j] = 0;
for (k = 1; p[k] != 0; k++)
{
n = p[0] - p[k];
d0 = n % BN_BITS2; d1 = BN_BITS2 - d0;
n /= BN_BITS2;
z[j-n] ^= (zz>>d0);
if (d0) z[j-n-1] ^= (zz<<d1);
}
n = dN;
d0 = p[0] % BN_BITS2;
d1 = BN_BITS2 - d0;
z[j-n] ^= (zz >> d0);
if (d0) z[j-n-1] ^= (zz << d1);
}
while (j == dN)
{
d0 = p[0] % BN_BITS2;
zz = z[dN] >> d0;
if (zz == 0) break;
d1 = BN_BITS2 - d0;
if (d0)
z[dN] = (z[dN] << d1) >> d1;
else
z[dN] = 0;
z[0] ^= zz;
for (k = 1; p[k] != 0; k++)
{
BN_ULONG tmp_ulong;
n = p[k] / BN_BITS2;
d0 = p[k] % BN_BITS2;
d1 = BN_BITS2 - d0;
z[n] ^= (zz << d0);
tmp_ulong = zz >> d1;
if (d0 && tmp_ulong)
z[n+1] ^= tmp_ulong;
}
}
bn_correct_top(r);
return 1;
}
int BN_GF2m_mod(BIGNUM *r, const BIGNUM *a, const BIGNUM *p)
{
int ret = 0;
int arr[6];
bn_check_top(a);
bn_check_top(p);
ret = BN_GF2m_poly2arr(p, arr, sizeof(arr)/sizeof(arr[0]));
if (!ret || ret > (int)(sizeof(arr)/sizeof(arr[0])))
{
BNerr(BN_F_BN_GF2M_MOD,BN_R_INVALID_LENGTH);
return 0;
}
ret = BN_GF2m_mod_arr(r, a, arr);
bn_check_top(r);
return ret;
}
int BN_GF2m_mod_mul_arr(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const int p[], BN_CTX *ctx)
{
int zlen, i, j, k, ret = 0;
BIGNUM *s;
BN_ULONG x1, x0, y1, y0, zz[4];
bn_check_top(a);
bn_check_top(b);
if (a == b)
{
return BN_GF2m_mod_sqr_arr(r, a, p, ctx);
}
BN_CTX_start(ctx);
if ((s = BN_CTX_get(ctx)) == NULL) goto err;
zlen = a->top + b->top + 4;
if (!bn_wexpand(s, zlen)) goto err;
s->top = zlen;
for (i = 0; i < zlen; i++) s->d[i] = 0;
for (j = 0; j < b->top; j += 2)
{
y0 = b->d[j];
y1 = ((j+1) == b->top) ? 0 : b->d[j+1];
for (i = 0; i < a->top; i += 2)
{
x0 = a->d[i];
x1 = ((i+1) == a->top) ? 0 : a->d[i+1];
bn_GF2m_mul_2x2(zz, x1, x0, y1, y0);
for (k = 0; k < 4; k++) s->d[i+j+k] ^= zz[k];
}
}
bn_correct_top(s);
if (BN_GF2m_mod_arr(r, s, p))
ret = 1;
bn_check_top(r);
err:
BN_CTX_end(ctx);
return ret;
}
int BN_GF2m_mod_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *p, BN_CTX *ctx)
{
int ret = 0;
const int max = BN_num_bits(p) + 1;
int *arr=NULL;
bn_check_top(a);
bn_check_top(b);
bn_check_top(p);
if ((arr = (int *)OPENSSL_malloc(sizeof(int) * max)) == NULL) goto err;
ret = BN_GF2m_poly2arr(p, arr, max);
if (!ret || ret > max)
{
BNerr(BN_F_BN_GF2M_MOD_MUL,BN_R_INVALID_LENGTH);
goto err;
}
ret = BN_GF2m_mod_mul_arr(r, a, b, arr, ctx);
bn_check_top(r);
err:
if (arr) OPENSSL_free(arr);
return ret;
}
int BN_GF2m_mod_sqr_arr(BIGNUM *r, const BIGNUM *a, const int p[], BN_CTX *ctx)
{
int i, ret = 0;
BIGNUM *s;
bn_check_top(a);
BN_CTX_start(ctx);
if ((s = BN_CTX_get(ctx)) == NULL) return 0;
if (!bn_wexpand(s, 2 * a->top)) goto err;
for (i = a->top - 1; i >= 0; i--)
{
s->d[2*i+1] = SQR1(a->d[i]);
s->d[2*i ] = SQR0(a->d[i]);
}
s->top = 2 * a->top;
bn_correct_top(s);
if (!BN_GF2m_mod_arr(r, s, p)) goto err;
bn_check_top(r);
ret = 1;
err:
BN_CTX_end(ctx);
return ret;
}
int BN_GF2m_mod_sqr(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx)
{
int ret = 0;
const int max = BN_num_bits(p) + 1;
int *arr=NULL;
bn_check_top(a);
bn_check_top(p);
if ((arr = (int *)OPENSSL_malloc(sizeof(int) * max)) == NULL) goto err;
ret = BN_GF2m_poly2arr(p, arr, max);
if (!ret || ret > max)
{
BNerr(BN_F_BN_GF2M_MOD_SQR,BN_R_INVALID_LENGTH);
goto err;
}
ret = BN_GF2m_mod_sqr_arr(r, a, arr, ctx);
bn_check_top(r);
err:
if (arr) OPENSSL_free(arr);
return ret;
}
int BN_GF2m_mod_inv(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx)
{
BIGNUM *b, *c = NULL, *u = NULL, *v = NULL, *tmp;
int ret = 0;
bn_check_top(a);
bn_check_top(p);
BN_CTX_start(ctx);
if ((b = BN_CTX_get(ctx))==NULL) goto err;
if ((c = BN_CTX_get(ctx))==NULL) goto err;
if ((u = BN_CTX_get(ctx))==NULL) goto err;
if ((v = BN_CTX_get(ctx))==NULL) goto err;
if (!BN_GF2m_mod(u, a, p)) goto err;
if (BN_is_zero(u)) goto err;
if (!BN_copy(v, p)) goto err;
#if 0
if (!BN_one(b)) goto err;
while (1)
{
while (!BN_is_odd(u))
{
if (BN_is_zero(u)) goto err;
if (!BN_rshift1(u, u)) goto err;
if (BN_is_odd(b))
{
if (!BN_GF2m_add(b, b, p)) goto err;
}
if (!BN_rshift1(b, b)) goto err;
}
if (BN_abs_is_word(u, 1)) break;
if (BN_num_bits(u) < BN_num_bits(v))
{
tmp = u; u = v; v = tmp;
tmp = b; b = c; c = tmp;
}
if (!BN_GF2m_add(u, u, v)) goto err;
if (!BN_GF2m_add(b, b, c)) goto err;
}
#else
{
int i, ubits = BN_num_bits(u),
vbits = BN_num_bits(v),
top = p->top;
BN_ULONG *udp,*bdp,*vdp,*cdp;
bn_wexpand(u,top); udp = u->d;
for (i=u->top;i<top;i++) udp[i] = 0;
u->top = top;
bn_wexpand(b,top); bdp = b->d;
bdp[0] = 1;
for (i=1;i<top;i++) bdp[i] = 0;
b->top = top;
bn_wexpand(c,top); cdp = c->d;
for (i=0;i<top;i++) cdp[i] = 0;
c->top = top;
vdp = v->d;
while (1)
{
while (ubits && !(udp[0]&1))
{
BN_ULONG u0,u1,b0,b1,mask;
u0 = udp[0];
b0 = bdp[0];
mask = (BN_ULONG)0-(b0&1);
b0 ^= p->d[0]&mask;
for (i=0;i<top-1;i++)
{
u1 = udp[i+1];
udp[i] = ((u0>>1)|(u1<<(BN_BITS2-1)))&BN_MASK2;
u0 = u1;
b1 = bdp[i+1]^(p->d[i+1]&mask);
bdp[i] = ((b0>>1)|(b1<<(BN_BITS2-1)))&BN_MASK2;
b0 = b1;
}
udp[i] = u0>>1;
bdp[i] = b0>>1;
ubits--;
}
if (ubits<=BN_BITS2 && udp[0]==1) break;
if (ubits<vbits)
{
i = ubits; ubits = vbits; vbits = i;
tmp = u; u = v; v = tmp;
tmp = b; b = c; c = tmp;
udp = vdp; vdp = v->d;
bdp = cdp; cdp = c->d;
}
for(i=0;i<top;i++)
{
udp[i] ^= vdp[i];
bdp[i] ^= cdp[i];
}
if (ubits==vbits)
{
bn_correct_top(u);
ubits = BN_num_bits(u);
}
}
bn_correct_top(b);
}
#endif
if (!BN_copy(r, b)) goto err;
bn_check_top(r);
ret = 1;
err:
#ifdef BN_DEBUG
bn_correct_top(c);
bn_correct_top(u);
bn_correct_top(v);
#endif
BN_CTX_end(ctx);
return ret;
}
int BN_GF2m_mod_inv_arr(BIGNUM *r, const BIGNUM *xx, const int p[], BN_CTX *ctx)
{
BIGNUM *field;
int ret = 0;
bn_check_top(xx);
BN_CTX_start(ctx);
if ((field = BN_CTX_get(ctx)) == NULL) goto err;
if (!BN_GF2m_arr2poly(p, field)) goto err;
ret = BN_GF2m_mod_inv(r, xx, field, ctx);
bn_check_top(r);
err:
BN_CTX_end(ctx);
return ret;
}
int BN_GF2m_mod_div(BIGNUM *r, const BIGNUM *y, const BIGNUM *x, const BIGNUM *p, BN_CTX *ctx)
{
BIGNUM *xinv = NULL;
int ret = 0;
bn_check_top(y);
bn_check_top(x);
bn_check_top(p);
BN_CTX_start(ctx);
xinv = BN_CTX_get(ctx);
if (xinv == NULL) goto err;
if (!BN_GF2m_mod_inv(xinv, x, p, ctx)) goto err;
if (!BN_GF2m_mod_mul(r, y, xinv, p, ctx)) goto err;
bn_check_top(r);
ret = 1;
err:
BN_CTX_end(ctx);
return ret;
}
int BN_GF2m_mod_div(BIGNUM *r, const BIGNUM *y, const BIGNUM *x, const BIGNUM *p, BN_CTX *ctx)
{
BIGNUM *a, *b, *u, *v;
int ret = 0;
bn_check_top(y);
bn_check_top(x);
bn_check_top(p);
BN_CTX_start(ctx);
a = BN_CTX_get(ctx);
b = BN_CTX_get(ctx);
u = BN_CTX_get(ctx);
v = BN_CTX_get(ctx);
if (v == NULL) goto err;
if (!BN_GF2m_mod(u, y, p)) goto err;
if (!BN_GF2m_mod(a, x, p)) goto err;
if (!BN_copy(b, p)) goto err;
while (!BN_is_odd(a))
{
if (!BN_rshift1(a, a)) goto err;
if (BN_is_odd(u)) if (!BN_GF2m_add(u, u, p)) goto err;
if (!BN_rshift1(u, u)) goto err;
}
do
{
if (BN_GF2m_cmp(b, a) > 0)
{
if (!BN_GF2m_add(b, b, a)) goto err;
if (!BN_GF2m_add(v, v, u)) goto err;
do
{
if (!BN_rshift1(b, b)) goto err;
if (BN_is_odd(v)) if (!BN_GF2m_add(v, v, p)) goto err;
if (!BN_rshift1(v, v)) goto err;
} while (!BN_is_odd(b));
}
else if (BN_abs_is_word(a, 1))
break;
else
{
if (!BN_GF2m_add(a, a, b)) goto err;
if (!BN_GF2m_add(u, u, v)) goto err;
do
{
if (!BN_rshift1(a, a)) goto err;
if (BN_is_odd(u)) if (!BN_GF2m_add(u, u, p)) goto err;
if (!BN_rshift1(u, u)) goto err;
} while (!BN_is_odd(a));
}
} while (1);
if (!BN_copy(r, u)) goto err;
bn_check_top(r);
ret = 1;
err:
BN_CTX_end(ctx);
return ret;
}
int BN_GF2m_mod_div_arr(BIGNUM *r, const BIGNUM *yy, const BIGNUM *xx, const int p[], BN_CTX *ctx)
{
BIGNUM *field;
int ret = 0;
bn_check_top(yy);
bn_check_top(xx);
BN_CTX_start(ctx);
if ((field = BN_CTX_get(ctx)) == NULL) goto err;
if (!BN_GF2m_arr2poly(p, field)) goto err;
ret = BN_GF2m_mod_div(r, yy, xx, field, ctx);
bn_check_top(r);
err:
BN_CTX_end(ctx);
return ret;
}
int BN_GF2m_mod_exp_arr(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const int p[], BN_CTX *ctx)
{
int ret = 0, i, n;
BIGNUM *u;
bn_check_top(a);
bn_check_top(b);
if (BN_is_zero(b))
return(BN_one(r));
if (BN_abs_is_word(b, 1))
return (BN_copy(r, a) != NULL);
BN_CTX_start(ctx);
if ((u = BN_CTX_get(ctx)) == NULL) goto err;
if (!BN_GF2m_mod_arr(u, a, p)) goto err;
n = BN_num_bits(b) - 1;
for (i = n - 1; i >= 0; i--)
{
if (!BN_GF2m_mod_sqr_arr(u, u, p, ctx)) goto err;
if (BN_is_bit_set(b, i))
{
if (!BN_GF2m_mod_mul_arr(u, u, a, p, ctx)) goto err;
}
}
if (!BN_copy(r, u)) goto err;
bn_check_top(r);
ret = 1;
err:
BN_CTX_end(ctx);
return ret;
}
int BN_GF2m_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *p, BN_CTX *ctx)
{
int ret = 0;
const int max = BN_num_bits(p) + 1;
int *arr=NULL;
bn_check_top(a);
bn_check_top(b);
bn_check_top(p);
if ((arr = (int *)OPENSSL_malloc(sizeof(int) * max)) == NULL) goto err;
ret = BN_GF2m_poly2arr(p, arr, max);
if (!ret || ret > max)
{
BNerr(BN_F_BN_GF2M_MOD_EXP,BN_R_INVALID_LENGTH);
goto err;
}
ret = BN_GF2m_mod_exp_arr(r, a, b, arr, ctx);
bn_check_top(r);
err:
if (arr) OPENSSL_free(arr);
return ret;
}
int BN_GF2m_mod_sqrt_arr(BIGNUM *r, const BIGNUM *a, const int p[], BN_CTX *ctx)
{
int ret = 0;
BIGNUM *u;
bn_check_top(a);
if (!p[0])
{
BN_zero(r);
return 1;
}
BN_CTX_start(ctx);
if ((u = BN_CTX_get(ctx)) == NULL) goto err;
if (!BN_set_bit(u, p[0] - 1)) goto err;
ret = BN_GF2m_mod_exp_arr(r, a, u, p, ctx);
bn_check_top(r);
err:
BN_CTX_end(ctx);
return ret;
}
int BN_GF2m_mod_sqrt(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx)
{
int ret = 0;
const int max = BN_num_bits(p) + 1;
int *arr=NULL;
bn_check_top(a);
bn_check_top(p);
if ((arr = (int *)OPENSSL_malloc(sizeof(int) * max)) == NULL) goto err;
ret = BN_GF2m_poly2arr(p, arr, max);
if (!ret || ret > max)
{
BNerr(BN_F_BN_GF2M_MOD_SQRT,BN_R_INVALID_LENGTH);
goto err;
}
ret = BN_GF2m_mod_sqrt_arr(r, a, arr, ctx);
bn_check_top(r);
err:
if (arr) OPENSSL_free(arr);
return ret;
}
int BN_GF2m_mod_solve_quad_arr(BIGNUM *r, const BIGNUM *a_, const int p[], BN_CTX *ctx)
{
int ret = 0, count = 0, j;
BIGNUM *a, *z, *rho, *w, *w2, *tmp;
bn_check_top(a_);
if (!p[0])
{
BN_zero(r);
return 1;
}
BN_CTX_start(ctx);
a = BN_CTX_get(ctx);
z = BN_CTX_get(ctx);
w = BN_CTX_get(ctx);
if (w == NULL) goto err;
if (!BN_GF2m_mod_arr(a, a_, p)) goto err;
if (BN_is_zero(a))
{
BN_zero(r);
ret = 1;
goto err;
}
if (p[0] & 0x1)
{
if (!BN_copy(z, a)) goto err;
for (j = 1; j <= (p[0] - 1) / 2; j++)
{
if (!BN_GF2m_mod_sqr_arr(z, z, p, ctx)) goto err;
if (!BN_GF2m_mod_sqr_arr(z, z, p, ctx)) goto err;
if (!BN_GF2m_add(z, z, a)) goto err;
}
}
else
{
rho = BN_CTX_get(ctx);
w2 = BN_CTX_get(ctx);
tmp = BN_CTX_get(ctx);
if (tmp == NULL) goto err;
do
{
if (!BN_rand(rho, p[0], 0, 0)) goto err;
if (!BN_GF2m_mod_arr(rho, rho, p)) goto err;
BN_zero(z);
if (!BN_copy(w, rho)) goto err;
for (j = 1; j <= p[0] - 1; j++)
{
if (!BN_GF2m_mod_sqr_arr(z, z, p, ctx)) goto err;
if (!BN_GF2m_mod_sqr_arr(w2, w, p, ctx)) goto err;
if (!BN_GF2m_mod_mul_arr(tmp, w2, a, p, ctx)) goto err;
if (!BN_GF2m_add(z, z, tmp)) goto err;
if (!BN_GF2m_add(w, w2, rho)) goto err;
}
count++;
} while (BN_is_zero(w) && (count < MAX_ITERATIONS));
if (BN_is_zero(w))
{
BNerr(BN_F_BN_GF2M_MOD_SOLVE_QUAD_ARR,BN_R_TOO_MANY_ITERATIONS);
goto err;
}
}
if (!BN_GF2m_mod_sqr_arr(w, z, p, ctx)) goto err;
if (!BN_GF2m_add(w, z, w)) goto err;
if (BN_GF2m_cmp(w, a))
{
BNerr(BN_F_BN_GF2M_MOD_SOLVE_QUAD_ARR, BN_R_NO_SOLUTION);
goto err;
}
if (!BN_copy(r, z)) goto err;
bn_check_top(r);
ret = 1;
err:
BN_CTX_end(ctx);
return ret;
}
int BN_GF2m_mod_solve_quad(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx)
{
int ret = 0;
const int max = BN_num_bits(p) + 1;
int *arr=NULL;
bn_check_top(a);
bn_check_top(p);
if ((arr = (int *)OPENSSL_malloc(sizeof(int) *
max)) == NULL) goto err;
ret = BN_GF2m_poly2arr(p, arr, max);
if (!ret || ret > max)
{
BNerr(BN_F_BN_GF2M_MOD_SOLVE_QUAD,BN_R_INVALID_LENGTH);
goto err;
}
ret = BN_GF2m_mod_solve_quad_arr(r, a, arr, ctx);
bn_check_top(r);
err:
if (arr) OPENSSL_free(arr);
return ret;
}
int BN_GF2m_poly2arr(const BIGNUM *a, int p[], int max)
{
int i, j, k = 0;
BN_ULONG mask;
if (BN_is_zero(a))
return 0;
for (i = a->top - 1; i >= 0; i--)
{
if (!a->d[i])
continue;
mask = BN_TBIT;
for (j = BN_BITS2 - 1; j >= 0; j--)
{
if (a->d[i] & mask)
{
if (k < max) p[k] = BN_BITS2 * i + j;
k++;
}
mask >>= 1;
}
}
if (k < max) {
p[k] = -1;
k++;
}
return k;
}
int BN_GF2m_arr2poly(const int p[], BIGNUM *a)
{
int i;
bn_check_top(a);
BN_zero(a);
for (i = 0; p[i] != -1; i++)
{
if (BN_set_bit(a, p[i]) == 0)
return 0;
}
bn_check_top(a);
return 1;
}
