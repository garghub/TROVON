static int pkey_dh_init(EVP_PKEY_CTX *ctx)
{
DH_PKEY_CTX *dctx;
dctx = OPENSSL_malloc(sizeof(DH_PKEY_CTX));
if (!dctx)
return 0;
dctx->prime_len = 1024;
dctx->generator = 2;
dctx->use_dsa = 0;
ctx->data = dctx;
ctx->keygen_info = dctx->gentmp;
ctx->keygen_info_count = 2;
return 1;
}
static int pkey_dh_copy(EVP_PKEY_CTX *dst, EVP_PKEY_CTX *src)
{
DH_PKEY_CTX *dctx, *sctx;
if (!pkey_dh_init(dst))
return 0;
sctx = src->data;
dctx = dst->data;
dctx->prime_len = sctx->prime_len;
dctx->generator = sctx->generator;
dctx->use_dsa = sctx->use_dsa;
return 1;
}
static void pkey_dh_cleanup(EVP_PKEY_CTX *ctx)
{
DH_PKEY_CTX *dctx = ctx->data;
if (dctx)
OPENSSL_free(dctx);
}
static int pkey_dh_ctrl(EVP_PKEY_CTX *ctx, int type, int p1, void *p2)
{
DH_PKEY_CTX *dctx = ctx->data;
switch (type)
{
case EVP_PKEY_CTRL_DH_PARAMGEN_PRIME_LEN:
if (p1 < 256)
return -2;
dctx->prime_len = p1;
return 1;
case EVP_PKEY_CTRL_DH_PARAMGEN_GENERATOR:
dctx->generator = p1;
return 1;
case EVP_PKEY_CTRL_PEER_KEY:
return 1;
default:
return -2;
}
}
static int pkey_dh_ctrl_str(EVP_PKEY_CTX *ctx,
const char *type, const char *value)
{
if (!strcmp(type, "dh_paramgen_prime_len"))
{
int len;
len = atoi(value);
return EVP_PKEY_CTX_set_dh_paramgen_prime_len(ctx, len);
}
if (!strcmp(type, "dh_paramgen_generator"))
{
int len;
len = atoi(value);
return EVP_PKEY_CTX_set_dh_paramgen_generator(ctx, len);
}
return -2;
}
static int pkey_dh_paramgen(EVP_PKEY_CTX *ctx, EVP_PKEY *pkey)
{
DH *dh = NULL;
DH_PKEY_CTX *dctx = ctx->data;
BN_GENCB *pcb, cb;
int ret;
if (ctx->pkey_gencb)
{
pcb = &cb;
evp_pkey_set_cb_translate(pcb, ctx);
}
else
pcb = NULL;
dh = DH_new();
if (!dh)
return 0;
ret = DH_generate_parameters_ex(dh,
dctx->prime_len, dctx->generator, pcb);
if (ret)
EVP_PKEY_assign_DH(pkey, dh);
else
DH_free(dh);
return ret;
}
static int pkey_dh_keygen(EVP_PKEY_CTX *ctx, EVP_PKEY *pkey)
{
DH *dh = NULL;
if (ctx->pkey == NULL)
{
DHerr(DH_F_PKEY_DH_KEYGEN, DH_R_NO_PARAMETERS_SET);
return 0;
}
dh = DH_new();
if (!dh)
return 0;
EVP_PKEY_assign_DH(pkey, dh);
if (!EVP_PKEY_copy_parameters(pkey, ctx->pkey))
return 0;
return DH_generate_key(pkey->pkey.dh);
}
static int pkey_dh_derive(EVP_PKEY_CTX *ctx, unsigned char *key, size_t *keylen)
{
int ret;
if (!ctx->pkey || !ctx->peerkey)
{
DHerr(DH_F_PKEY_DH_DERIVE, DH_R_KEYS_NOT_SET);
return 0;
}
ret = DH_compute_key(key, ctx->peerkey->pkey.dh->pub_key,
ctx->pkey->pkey.dh);
if (ret < 0)
return ret;
*keylen = ret;
return 1;
}
