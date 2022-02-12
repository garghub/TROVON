void ENGINE_load_rsax (void)
{
#ifdef COMPILE_RSAX
ENGINE *toadd = ENGINE_rsax();
if(!toadd) return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
#endif
}
static int bind_helper(ENGINE *e)
{
#ifndef OPENSSL_NO_RSA
const RSA_METHOD *meth1;
#endif
if(!ENGINE_set_id(e, engine_e_rsax_id) ||
!ENGINE_set_name(e, engine_e_rsax_name) ||
#ifndef OPENSSL_NO_RSA
!ENGINE_set_RSA(e, &e_rsax_rsa) ||
#endif
!ENGINE_set_destroy_function(e, e_rsax_destroy) ||
!ENGINE_set_init_function(e, e_rsax_init) ||
!ENGINE_set_finish_function(e, e_rsax_finish) ||
!ENGINE_set_ctrl_function(e, e_rsax_ctrl) ||
!ENGINE_set_cmd_defns(e, e_rsax_cmd_defns))
return 0;
#ifndef OPENSSL_NO_RSA
meth1 = RSA_PKCS1_SSLeay();
e_rsax_rsa.rsa_pub_enc = meth1->rsa_pub_enc;
e_rsax_rsa.rsa_pub_dec = meth1->rsa_pub_dec;
e_rsax_rsa.rsa_priv_enc = meth1->rsa_priv_enc;
e_rsax_rsa.rsa_priv_dec = meth1->rsa_priv_dec;
e_rsax_rsa.bn_mod_exp = meth1->bn_mod_exp;
#endif
return 1;
}
static ENGINE *ENGINE_rsax(void)
{
ENGINE *ret = ENGINE_new();
if(!ret)
return NULL;
if(!bind_helper(ret))
{
ENGINE_free(ret);
return NULL;
}
return ret;
}
static int e_rsax_destroy(ENGINE *e)
{
return 1;
}
static int e_rsax_init(ENGINE *e)
{
#ifndef OPENSSL_NO_RSA
if (rsax_ex_data_idx == -1)
rsax_ex_data_idx = RSA_get_ex_new_index(0,
NULL,
NULL, NULL, NULL);
#endif
if (rsax_ex_data_idx == -1)
return 0;
return 1;
}
static int e_rsax_finish(ENGINE *e)
{
return 1;
}
static int e_rsax_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f)(void))
{
int to_return = 1;
switch(cmd)
{
default:
to_return = 0;
break;
}
return to_return;
}
static E_RSAX_MOD_CTX *e_rsax_get_ctx(RSA *rsa, int idx, BIGNUM* m)
{
E_RSAX_MOD_CTX *hptr;
if (idx < 0 || idx > 2)
return NULL;
hptr = RSA_get_ex_data(rsa, rsax_ex_data_idx);
if (!hptr) {
hptr = OPENSSL_malloc(3*sizeof(E_RSAX_MOD_CTX));
if (!hptr) return NULL;
hptr[2].type = hptr[1].type= hptr[0].type = 0;
RSA_set_ex_data(rsa, rsax_ex_data_idx, hptr);
}
if (hptr[idx].type == (UINT64)BN_num_bits(m))
return hptr+idx;
if (BN_num_bits(m) == 512) {
UINT64 _m[8];
bn_extract_to_array_512(m, 8, _m);
memset( &hptr[idx].ctx.b512, 0, sizeof(struct mod_ctx_512));
mod_exp_pre_compute_data_512(_m, &hptr[idx].ctx.b512);
}
hptr[idx].type = BN_num_bits(m);
return hptr+idx;
}
static int e_rsax_rsa_finish(RSA *rsa)
{
E_RSAX_MOD_CTX *hptr = RSA_get_ex_data(rsa, rsax_ex_data_idx);
if(hptr)
{
OPENSSL_free(hptr);
RSA_set_ex_data(rsa, rsax_ex_data_idx, NULL);
}
if (rsa->_method_mod_n)
BN_MONT_CTX_free(rsa->_method_mod_n);
if (rsa->_method_mod_p)
BN_MONT_CTX_free(rsa->_method_mod_p);
if (rsa->_method_mod_q)
BN_MONT_CTX_free(rsa->_method_mod_q);
return 1;
}
static int e_rsax_bn_mod_exp(BIGNUM *r, const BIGNUM *g, const BIGNUM *e,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont, E_RSAX_MOD_CTX* rsax_mod_ctx )
{
if (rsax_mod_ctx && BN_get_flags(e, BN_FLG_CONSTTIME) != 0) {
if (BN_num_bits(m) == 512) {
UINT64 _r[8];
UINT64 _g[8];
UINT64 _e[8];
bn_extract_to_array_512(g, 8, _g);
bn_extract_to_array_512(e, 8, _e);
mod_exp_512(_r, _g, _e, &rsax_mod_ctx->ctx.b512);
interleaved_array_to_bn_512(r, _r);
return 1;
}
}
return BN_mod_exp_mont(r, g, e, m, ctx, in_mont);
}
static int bn_extract_to_array_512(const BIGNUM* b, unsigned int n, UINT64 *array)
{
int i;
UINT64 tmp;
unsigned char bn_buff[64];
memset(bn_buff, 0, 64);
if (BN_num_bytes(b) > 64) {
printf ("Can't support this byte size\n");
return 0; }
if (BN_num_bytes(b)!=0) {
if (!BN_bn2bin(b, bn_buff+(64-BN_num_bytes(b)))) {
printf ("Error's in bn2bin\n");
return 0; } }
while (n-- > 0) {
array[n] = 0;
for (i=7; i>=0; i--) {
tmp = bn_buff[63-(n*8+i)];
array[n] |= tmp << (8*i); } }
return 1;
}
static int interleaved_array_to_bn_512(BIGNUM* b, UINT64 *array)
{
unsigned char tmp[64];
int n=8;
int i;
while (n-- > 0) {
for (i = 7; i>=0; i--) {
tmp[63-(n*8+i)] = (unsigned char)(array[n]>>(8*i)); } }
BN_bin2bn(tmp, 64, b);
return 0;
}
static int mod_exp_pre_compute_data_512(UINT64 *m, struct mod_ctx_512 *data)
{
BIGNUM two_768, two_640, two_128, two_512, tmp, _m, tmp2;
BN_CTX* ctx;
UINT64 _t[8];
int i, j, ret = 0;
BN_init(&_m);
interleaved_array_to_bn_512(&_m, m);
memset(_t, 0, 64);
BN_init(&two_768);
BN_init(&two_640);
BN_init(&two_128);
BN_init(&two_512);
BN_init(&tmp);
BN_init(&tmp2);
if ((ctx=BN_CTX_new()) == NULL) { goto err; }
BN_CTX_start(ctx);
BN_lshift(&two_768, BN_value_one(), 768);
BN_lshift(&two_640, BN_value_one(), 640);
BN_lshift(&two_128, BN_value_one(), 128);
BN_lshift(&two_512, BN_value_one(), 512);
if (0 == (m[7] & 0x8000000000000000)) {
exit(1);
}
if (0 == (m[0] & 0x1)) {
exit(1);
}
BN_mod(&tmp, &two_768, &_m, ctx);
if (!bn_extract_to_array_512(&tmp, 8, &data->m1[0])) {
goto err; }
BN_mod(&tmp, &two_640, &_m, ctx);
if (!bn_extract_to_array_512(&tmp, 8, &data->m2[0])) {
goto err;
}
BN_mod_inverse(&tmp, &_m, &two_128, ctx);
if (!BN_is_zero(&tmp)) { BN_sub(&tmp, &two_128, &tmp); }
if (!bn_extract_to_array_512(&tmp, 2, &data->k1[0])) {
goto err; }
for (i=0; i<8; i++) {
BN_zero(&tmp);
if (i & 1) { BN_add(&tmp, &two_512, &tmp); }
if (i & 2) { BN_add(&tmp, &two_512, &tmp); }
if (i & 4) { BN_add(&tmp, &two_640, &tmp); }
BN_nnmod(&tmp2, &tmp, &_m, ctx);
if (!bn_extract_to_array_512(&tmp2, 8, _t)) {
goto err; }
for (j=0; j<8; j++) data->t[j][i] = _t[j]; }
for (i=0; i<8; i++) {
data->m[i] = m[i]; }
ret = 1;
err:
if (ctx != NULL) {
BN_CTX_end(ctx); BN_CTX_free(ctx); }
BN_free(&two_768);
BN_free(&two_640);
BN_free(&two_128);
BN_free(&two_512);
BN_free(&tmp);
BN_free(&tmp2);
BN_free(&_m);
return ret;
}
static int e_rsax_rsa_mod_exp(BIGNUM *r0, const BIGNUM *I, RSA *rsa, BN_CTX *ctx)
{
BIGNUM *r1,*m1,*vrfy;
BIGNUM local_dmp1,local_dmq1,local_c,local_r1;
BIGNUM *dmp1,*dmq1,*c,*pr1;
int ret=0;
BN_CTX_start(ctx);
r1 = BN_CTX_get(ctx);
m1 = BN_CTX_get(ctx);
vrfy = BN_CTX_get(ctx);
{
BIGNUM local_p, local_q;
BIGNUM *p = NULL, *q = NULL;
int error = 0;
if (!(rsa->flags & RSA_FLAG_NO_CONSTTIME))
{
BN_init(&local_p);
p = &local_p;
BN_with_flags(p, rsa->p, BN_FLG_CONSTTIME);
BN_init(&local_q);
q = &local_q;
BN_with_flags(q, rsa->q, BN_FLG_CONSTTIME);
}
else
{
p = rsa->p;
q = rsa->q;
}
if (rsa->flags & RSA_FLAG_CACHE_PRIVATE)
{
if (!BN_MONT_CTX_set_locked(&rsa->_method_mod_p, CRYPTO_LOCK_RSA, p, ctx))
error = 1;
if (!BN_MONT_CTX_set_locked(&rsa->_method_mod_q, CRYPTO_LOCK_RSA, q, ctx))
error = 1;
}
if (!(rsa->flags & RSA_FLAG_NO_CONSTTIME))
{
BN_free(&local_p);
BN_free(&local_q);
}
if ( error )
goto err;
}
if (rsa->flags & RSA_FLAG_CACHE_PUBLIC)
if (!BN_MONT_CTX_set_locked(&rsa->_method_mod_n, CRYPTO_LOCK_RSA, rsa->n, ctx))
goto err;
if (!(rsa->flags & RSA_FLAG_NO_CONSTTIME))
{
c = &local_c;
BN_with_flags(c, I, BN_FLG_CONSTTIME);
if (!BN_mod(r1,c,rsa->q,ctx)) goto err;
}
else
{
if (!BN_mod(r1,I,rsa->q,ctx)) goto err;
}
if (!(rsa->flags & RSA_FLAG_NO_CONSTTIME))
{
dmq1 = &local_dmq1;
BN_with_flags(dmq1, rsa->dmq1, BN_FLG_CONSTTIME);
}
else
dmq1 = rsa->dmq1;
if (!e_rsax_bn_mod_exp(m1,r1,dmq1,rsa->q,ctx,
rsa->_method_mod_q, e_rsax_get_ctx(rsa, 0, rsa->q) )) goto err;
if (!(rsa->flags & RSA_FLAG_NO_CONSTTIME))
{
c = &local_c;
BN_with_flags(c, I, BN_FLG_CONSTTIME);
if (!BN_mod(r1,c,rsa->p,ctx)) goto err;
}
else
{
if (!BN_mod(r1,I,rsa->p,ctx)) goto err;
}
if (!(rsa->flags & RSA_FLAG_NO_CONSTTIME))
{
dmp1 = &local_dmp1;
BN_with_flags(dmp1, rsa->dmp1, BN_FLG_CONSTTIME);
}
else
dmp1 = rsa->dmp1;
if (!e_rsax_bn_mod_exp(r0,r1,dmp1,rsa->p,ctx,
rsa->_method_mod_p, e_rsax_get_ctx(rsa, 1, rsa->p) )) goto err;
if (!BN_sub(r0,r0,m1)) goto err;
if (BN_is_negative(r0))
if (!BN_add(r0,r0,rsa->p)) goto err;
if (!BN_mul(r1,r0,rsa->iqmp,ctx)) goto err;
if (!(rsa->flags & RSA_FLAG_NO_CONSTTIME))
{
pr1 = &local_r1;
BN_with_flags(pr1, r1, BN_FLG_CONSTTIME);
}
else
pr1 = r1;
if (!BN_mod(r0,pr1,rsa->p,ctx)) goto err;
if (BN_is_negative(r0))
if (!BN_add(r0,r0,rsa->p)) goto err;
if (!BN_mul(r1,r0,rsa->q,ctx)) goto err;
if (!BN_add(r0,r1,m1)) goto err;
if (rsa->e && rsa->n)
{
if (!e_rsax_bn_mod_exp(vrfy,r0,rsa->e,rsa->n,ctx,rsa->_method_mod_n, e_rsax_get_ctx(rsa, 2, rsa->n) ))
goto err;
if (!BN_sub(vrfy, vrfy, I)) goto err;
if (!BN_mod(vrfy, vrfy, rsa->n, ctx)) goto err;
if (BN_is_negative(vrfy))
if (!BN_add(vrfy, vrfy, rsa->n)) goto err;
if (!BN_is_zero(vrfy))
{
BIGNUM local_d;
BIGNUM *d = NULL;
if (!(rsa->flags & RSA_FLAG_NO_CONSTTIME))
{
d = &local_d;
BN_with_flags(d, rsa->d, BN_FLG_CONSTTIME);
}
else
d = rsa->d;
if (!e_rsax_bn_mod_exp(r0,I,d,rsa->n,ctx,
rsa->_method_mod_n, e_rsax_get_ctx(rsa, 2, rsa->n) )) goto err;
}
}
ret=1;
err:
BN_CTX_end(ctx);
return ret;
}
