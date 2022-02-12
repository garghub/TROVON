int DSA_generate_parameters_ex(DSA *ret, int bits,
const unsigned char *seed_in, int seed_len,
int *counter_ret, unsigned long *h_ret,
BN_GENCB *cb)
{
# ifdef OPENSSL_FIPS
if (FIPS_mode() && !(ret->meth->flags & DSA_FLAG_FIPS_METHOD)
&& !(ret->flags & DSA_FLAG_NON_FIPS_ALLOW)) {
DSAerr(DSA_F_DSA_GENERATE_PARAMETERS_EX, DSA_R_NON_FIPS_DSA_METHOD);
return 0;
}
# endif
if (ret->meth->dsa_paramgen)
return ret->meth->dsa_paramgen(ret, bits, seed_in, seed_len,
counter_ret, h_ret, cb);
# ifdef OPENSSL_FIPS
else if (FIPS_mode()) {
return FIPS_dsa_generate_parameters_ex(ret, bits,
seed_in, seed_len,
counter_ret, h_ret, cb);
}
# endif
else {
const EVP_MD *evpmd;
size_t qbits = bits >= 2048 ? 256 : 160;
if (bits >= 2048) {
qbits = 256;
evpmd = EVP_sha256();
} else {
qbits = 160;
evpmd = EVP_sha1();
}
return dsa_builtin_paramgen(ret, bits, qbits, evpmd,
seed_in, seed_len, NULL, counter_ret,
h_ret, cb);
}
}
int dsa_builtin_paramgen(DSA *ret, size_t bits, size_t qbits,
const EVP_MD *evpmd, const unsigned char *seed_in,
size_t seed_len, unsigned char *seed_out,
int *counter_ret, unsigned long *h_ret, BN_GENCB *cb)
{
int ok = 0;
unsigned char seed[SHA256_DIGEST_LENGTH];
unsigned char md[SHA256_DIGEST_LENGTH];
unsigned char buf[SHA256_DIGEST_LENGTH], buf2[SHA256_DIGEST_LENGTH];
BIGNUM *r0, *W, *X, *c, *test;
BIGNUM *g = NULL, *q = NULL, *p = NULL;
BN_MONT_CTX *mont = NULL;
int i, k, n = 0, m = 0, qsize = qbits >> 3;
int counter = 0;
int r = 0;
BN_CTX *ctx = NULL;
unsigned int h = 2;
if (qsize != SHA_DIGEST_LENGTH && qsize != SHA224_DIGEST_LENGTH &&
qsize != SHA256_DIGEST_LENGTH)
return 0;
if (evpmd == NULL)
evpmd = EVP_sha1();
if (bits < 512)
bits = 512;
bits = (bits + 63) / 64 * 64;
if (seed_len && (seed_len < (size_t)qsize))
seed_in = NULL;
if (seed_len > (size_t)qsize)
seed_len = qsize;
if (seed_in != NULL)
memcpy(seed, seed_in, seed_len);
if ((ctx = BN_CTX_new()) == NULL)
goto err;
if ((mont = BN_MONT_CTX_new()) == NULL)
goto err;
BN_CTX_start(ctx);
r0 = BN_CTX_get(ctx);
g = BN_CTX_get(ctx);
W = BN_CTX_get(ctx);
q = BN_CTX_get(ctx);
X = BN_CTX_get(ctx);
c = BN_CTX_get(ctx);
p = BN_CTX_get(ctx);
test = BN_CTX_get(ctx);
if (!BN_lshift(test, BN_value_one(), bits - 1))
goto err;
for (;;) {
for (;;) {
int seed_is_random;
if (!BN_GENCB_call(cb, 0, m++))
goto err;
if (!seed_len) {
RAND_pseudo_bytes(seed, qsize);
seed_is_random = 1;
} else {
seed_is_random = 0;
seed_len = 0;
}
memcpy(buf, seed, qsize);
memcpy(buf2, seed, qsize);
for (i = qsize - 1; i >= 0; i--) {
buf[i]++;
if (buf[i] != 0)
break;
}
if (!EVP_Digest(seed, qsize, md, NULL, evpmd, NULL))
goto err;
if (!EVP_Digest(buf, qsize, buf2, NULL, evpmd, NULL))
goto err;
for (i = 0; i < qsize; i++)
md[i] ^= buf2[i];
md[0] |= 0x80;
md[qsize - 1] |= 0x01;
if (!BN_bin2bn(md, qsize, q))
goto err;
r = BN_is_prime_fasttest_ex(q, DSS_prime_checks, ctx,
seed_is_random, cb);
if (r > 0)
break;
if (r != 0)
goto err;
}
if (!BN_GENCB_call(cb, 2, 0))
goto err;
if (!BN_GENCB_call(cb, 3, 0))
goto err;
counter = 0;
n = (bits - 1) / 160;
for (;;) {
if ((counter != 0) && !BN_GENCB_call(cb, 0, counter))
goto err;
BN_zero(W);
for (k = 0; k <= n; k++) {
for (i = qsize - 1; i >= 0; i--) {
buf[i]++;
if (buf[i] != 0)
break;
}
if (!EVP_Digest(buf, qsize, md, NULL, evpmd, NULL))
goto err;
if (!BN_bin2bn(md, qsize, r0))
goto err;
if (!BN_lshift(r0, r0, (qsize << 3) * k))
goto err;
if (!BN_add(W, W, r0))
goto err;
}
if (!BN_mask_bits(W, bits - 1))
goto err;
if (!BN_copy(X, W))
goto err;
if (!BN_add(X, X, test))
goto err;
if (!BN_lshift1(r0, q))
goto err;
if (!BN_mod(c, X, r0, ctx))
goto err;
if (!BN_sub(r0, c, BN_value_one()))
goto err;
if (!BN_sub(p, X, r0))
goto err;
if (BN_cmp(p, test) >= 0) {
r = BN_is_prime_fasttest_ex(p, DSS_prime_checks, ctx, 1, cb);
if (r > 0)
goto end;
if (r != 0)
goto err;
}
counter++;
if (counter >= 4096)
break;
}
}
end:
if (!BN_GENCB_call(cb, 2, 1))
goto err;
if (!BN_sub(test, p, BN_value_one()))
goto err;
if (!BN_div(r0, NULL, test, q, ctx))
goto err;
if (!BN_set_word(test, h))
goto err;
if (!BN_MONT_CTX_set(mont, p, ctx))
goto err;
for (;;) {
if (!BN_mod_exp_mont(g, test, r0, p, ctx, mont))
goto err;
if (!BN_is_one(g))
break;
if (!BN_add(test, test, BN_value_one()))
goto err;
h++;
}
if (!BN_GENCB_call(cb, 3, 1))
goto err;
ok = 1;
err:
if (ok) {
if (ret->p)
BN_free(ret->p);
if (ret->q)
BN_free(ret->q);
if (ret->g)
BN_free(ret->g);
ret->p = BN_dup(p);
ret->q = BN_dup(q);
ret->g = BN_dup(g);
if (ret->p == NULL || ret->q == NULL || ret->g == NULL) {
ok = 0;
goto err;
}
if (counter_ret != NULL)
*counter_ret = counter;
if (h_ret != NULL)
*h_ret = h;
if (seed_out)
memcpy(seed_out, seed, qsize);
}
if (ctx) {
BN_CTX_end(ctx);
BN_CTX_free(ctx);
}
if (mont != NULL)
BN_MONT_CTX_free(mont);
return ok;
}
int dsa_builtin_paramgen2(DSA *ret, size_t L, size_t N,
const EVP_MD *evpmd, const unsigned char *seed_in,
size_t seed_len, int idx, unsigned char *seed_out,
int *counter_ret, unsigned long *h_ret,
BN_GENCB *cb)
{
int ok = -1;
unsigned char *seed = NULL, *seed_tmp = NULL;
unsigned char md[EVP_MAX_MD_SIZE];
int mdsize;
BIGNUM *r0, *W, *X, *c, *test;
BIGNUM *g = NULL, *q = NULL, *p = NULL;
BN_MONT_CTX *mont = NULL;
int i, k, n = 0, m = 0, qsize = N >> 3;
int counter = 0;
int r = 0;
BN_CTX *ctx = NULL;
EVP_MD_CTX mctx;
unsigned int h = 2;
# ifdef OPENSSL_FIPS
if (FIPS_mode())
return fips_dsa_builtin_paramgen2(ret, L, N, evpmd,
seed_in, seed_len, idx,
seed_out, counter_ret, h_ret, cb);
# endif
EVP_MD_CTX_init(&mctx);
if (evpmd == NULL) {
if (N == 160)
evpmd = EVP_sha1();
else if (N == 224)
evpmd = EVP_sha224();
else
evpmd = EVP_sha256();
}
mdsize = EVP_MD_size(evpmd);
if (!ret->p || !ret->q || idx >= 0) {
if (seed_len == 0)
seed_len = mdsize;
seed = OPENSSL_malloc(seed_len);
if (seed_out)
seed_tmp = seed_out;
else
seed_tmp = OPENSSL_malloc(seed_len);
if (!seed || !seed_tmp)
goto err;
if (seed_in)
memcpy(seed, seed_in, seed_len);
}
if ((ctx = BN_CTX_new()) == NULL)
goto err;
if ((mont = BN_MONT_CTX_new()) == NULL)
goto err;
BN_CTX_start(ctx);
r0 = BN_CTX_get(ctx);
g = BN_CTX_get(ctx);
W = BN_CTX_get(ctx);
X = BN_CTX_get(ctx);
c = BN_CTX_get(ctx);
test = BN_CTX_get(ctx);
if (ret->p && ret->q) {
p = ret->p;
q = ret->q;
if (idx >= 0)
memcpy(seed_tmp, seed, seed_len);
goto g_only;
} else {
p = BN_CTX_get(ctx);
q = BN_CTX_get(ctx);
}
if (!BN_lshift(test, BN_value_one(), L - 1))
goto err;
for (;;) {
for (;;) {
unsigned char *pmd;
if (!BN_GENCB_call(cb, 0, m++))
goto err;
if (!seed_in) {
if (RAND_pseudo_bytes(seed, seed_len) < 0)
goto err;
}
if (!EVP_Digest(seed, seed_len, md, NULL, evpmd, NULL))
goto err;
if (mdsize > qsize)
pmd = md + mdsize - qsize;
else
pmd = md;
if (mdsize < qsize)
memset(md + mdsize, 0, qsize - mdsize);
pmd[0] |= 0x80;
pmd[qsize - 1] |= 0x01;
if (!BN_bin2bn(pmd, qsize, q))
goto err;
r = BN_is_prime_fasttest_ex(q, DSS_prime_checks, ctx,
seed_in ? 1 : 0, cb);
if (r > 0)
break;
if (r != 0)
goto err;
if (seed_in) {
ok = 0;
DSAerr(DSA_F_DSA_BUILTIN_PARAMGEN2, DSA_R_Q_NOT_PRIME);
goto err;
}
}
if (seed_out)
memcpy(seed_out, seed, seed_len);
if (!BN_GENCB_call(cb, 2, 0))
goto err;
if (!BN_GENCB_call(cb, 3, 0))
goto err;
counter = 0;
n = (L - 1) / (mdsize << 3);
for (;;) {
if ((counter != 0) && !BN_GENCB_call(cb, 0, counter))
goto err;
BN_zero(W);
for (k = 0; k <= n; k++) {
for (i = seed_len - 1; i >= 0; i--) {
seed[i]++;
if (seed[i] != 0)
break;
}
if (!EVP_Digest(seed, seed_len, md, NULL, evpmd, NULL))
goto err;
if (!BN_bin2bn(md, mdsize, r0))
goto err;
if (!BN_lshift(r0, r0, (mdsize << 3) * k))
goto err;
if (!BN_add(W, W, r0))
goto err;
}
if (!BN_mask_bits(W, L - 1))
goto err;
if (!BN_copy(X, W))
goto err;
if (!BN_add(X, X, test))
goto err;
if (!BN_lshift1(r0, q))
goto err;
if (!BN_mod(c, X, r0, ctx))
goto err;
if (!BN_sub(r0, c, BN_value_one()))
goto err;
if (!BN_sub(p, X, r0))
goto err;
if (BN_cmp(p, test) >= 0) {
r = BN_is_prime_fasttest_ex(p, DSS_prime_checks, ctx, 1, cb);
if (r > 0)
goto end;
if (r != 0)
goto err;
}
counter++;
if (counter >= (int)(4 * L))
break;
}
if (seed_in) {
ok = 0;
DSAerr(DSA_F_DSA_BUILTIN_PARAMGEN2, DSA_R_INVALID_PARAMETERS);
goto err;
}
}
end:
if (!BN_GENCB_call(cb, 2, 1))
goto err;
g_only:
if (!BN_sub(test, p, BN_value_one()))
goto err;
if (!BN_div(r0, NULL, test, q, ctx))
goto err;
if (idx < 0) {
if (!BN_set_word(test, h))
goto err;
} else
h = 1;
if (!BN_MONT_CTX_set(mont, p, ctx))
goto err;
for (;;) {
static const unsigned char ggen[4] = { 0x67, 0x67, 0x65, 0x6e };
if (idx >= 0) {
md[0] = idx & 0xff;
md[1] = (h >> 8) & 0xff;
md[2] = h & 0xff;
if (!EVP_DigestInit_ex(&mctx, evpmd, NULL))
goto err;
if (!EVP_DigestUpdate(&mctx, seed_tmp, seed_len))
goto err;
if (!EVP_DigestUpdate(&mctx, ggen, sizeof(ggen)))
goto err;
if (!EVP_DigestUpdate(&mctx, md, 3))
goto err;
if (!EVP_DigestFinal_ex(&mctx, md, NULL))
goto err;
if (!BN_bin2bn(md, mdsize, test))
goto err;
}
if (!BN_mod_exp_mont(g, test, r0, p, ctx, mont))
goto err;
if (!BN_is_one(g))
break;
if (idx < 0 && !BN_add(test, test, BN_value_one()))
goto err;
h++;
if (idx >= 0 && h > 0xffff)
goto err;
}
if (!BN_GENCB_call(cb, 3, 1))
goto err;
ok = 1;
err:
if (ok == 1) {
if (p != ret->p) {
if (ret->p)
BN_free(ret->p);
ret->p = BN_dup(p);
}
if (q != ret->q) {
if (ret->q)
BN_free(ret->q);
ret->q = BN_dup(q);
}
if (ret->g)
BN_free(ret->g);
ret->g = BN_dup(g);
if (ret->p == NULL || ret->q == NULL || ret->g == NULL) {
ok = -1;
goto err;
}
if (counter_ret != NULL)
*counter_ret = counter;
if (h_ret != NULL)
*h_ret = h;
}
if (seed)
OPENSSL_free(seed);
if (seed_out != seed_tmp)
OPENSSL_free(seed_tmp);
if (ctx) {
BN_CTX_end(ctx);
BN_CTX_free(ctx);
}
if (mont != NULL)
BN_MONT_CTX_free(mont);
EVP_MD_CTX_cleanup(&mctx);
return ok;
}
int dsa_paramgen_check_g(DSA *dsa)
{
BN_CTX *ctx;
BIGNUM *tmp;
BN_MONT_CTX *mont = NULL;
int rv = -1;
ctx = BN_CTX_new();
if (!ctx)
return -1;
BN_CTX_start(ctx);
if (BN_cmp(dsa->g, BN_value_one()) <= 0)
return 0;
if (BN_cmp(dsa->g, dsa->p) >= 0)
return 0;
tmp = BN_CTX_get(ctx);
if (!tmp)
goto err;
if ((mont = BN_MONT_CTX_new()) == NULL)
goto err;
if (!BN_MONT_CTX_set(mont, dsa->p, ctx))
goto err;
if (!BN_mod_exp_mont(tmp, dsa->g, dsa->q, dsa->p, ctx, mont))
goto err;
if (!BN_cmp(tmp, BN_value_one()))
rv = 1;
else
rv = 0;
err:
BN_CTX_end(ctx);
if (mont)
BN_MONT_CTX_free(mont);
BN_CTX_free(ctx);
return rv;
}
