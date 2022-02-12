static int pkey_hmac_init(EVP_PKEY_CTX *ctx)
{
HMAC_PKEY_CTX *hctx;
hctx = OPENSSL_malloc(sizeof(HMAC_PKEY_CTX));
if (!hctx)
return 0;
hctx->md = NULL;
hctx->ktmp.data = NULL;
hctx->ktmp.length = 0;
hctx->ktmp.flags = 0;
hctx->ktmp.type = V_ASN1_OCTET_STRING;
HMAC_CTX_init(&hctx->ctx);
ctx->data = hctx;
ctx->keygen_info_count = 0;
return 1;
}
static int pkey_hmac_copy(EVP_PKEY_CTX *dst, EVP_PKEY_CTX *src)
{
HMAC_PKEY_CTX *sctx, *dctx;
if (!pkey_hmac_init(dst))
return 0;
sctx = src->data;
dctx = dst->data;
dctx->md = sctx->md;
HMAC_CTX_init(&dctx->ctx);
HMAC_CTX_copy(&dctx->ctx, &sctx->ctx);
if (sctx->ktmp.data)
{
if (!ASN1_OCTET_STRING_set(&dctx->ktmp,
sctx->ktmp.data, sctx->ktmp.length))
return 0;
}
return 1;
}
static void pkey_hmac_cleanup(EVP_PKEY_CTX *ctx)
{
HMAC_PKEY_CTX *hctx = ctx->data;
HMAC_CTX_cleanup(&hctx->ctx);
if (hctx->ktmp.data)
{
if (hctx->ktmp.length)
OPENSSL_cleanse(hctx->ktmp.data, hctx->ktmp.length);
OPENSSL_free(hctx->ktmp.data);
hctx->ktmp.data = NULL;
}
OPENSSL_free(hctx);
}
static int pkey_hmac_keygen(EVP_PKEY_CTX *ctx, EVP_PKEY *pkey)
{
ASN1_OCTET_STRING *hkey = NULL;
HMAC_PKEY_CTX *hctx = ctx->data;
if (!hctx->ktmp.data)
return 0;
hkey = ASN1_OCTET_STRING_dup(&hctx->ktmp);
if (!hkey)
return 0;
EVP_PKEY_assign(pkey, EVP_PKEY_HMAC, hkey);
return 1;
}
static int int_update(EVP_MD_CTX *ctx,const void *data,size_t count)
{
HMAC_PKEY_CTX *hctx = ctx->pctx->data;
HMAC_Update(&hctx->ctx, data, count);
return 1;
}
static int hmac_signctx_init(EVP_PKEY_CTX *ctx, EVP_MD_CTX *mctx)
{
EVP_MD_CTX_set_flags(mctx, EVP_MD_CTX_FLAG_NO_INIT);
mctx->update = int_update;
return 1;
}
static int hmac_signctx(EVP_PKEY_CTX *ctx, unsigned char *sig, size_t *siglen,
EVP_MD_CTX *mctx)
{
unsigned int hlen;
HMAC_PKEY_CTX *hctx = ctx->data;
int l = EVP_MD_CTX_size(mctx);
if (l < 0)
return 0;
*siglen = l;
if (!sig)
return 1;
HMAC_Final(&hctx->ctx, sig, &hlen);
*siglen = (size_t)hlen;
return 1;
}
static int pkey_hmac_ctrl(EVP_PKEY_CTX *ctx, int type, int p1, void *p2)
{
HMAC_PKEY_CTX *hctx = ctx->data;
ASN1_OCTET_STRING *key;
switch (type)
{
case EVP_PKEY_CTRL_SET_MAC_KEY:
if ((!p2 && p1 > 0) || (p1 < -1))
return 0;
if (!ASN1_OCTET_STRING_set(&hctx->ktmp, p2, p1))
return 0;
break;
case EVP_PKEY_CTRL_MD:
hctx->md = p2;
break;
case EVP_PKEY_CTRL_DIGESTINIT:
key = (ASN1_OCTET_STRING *)ctx->pkey->pkey.ptr;
HMAC_Init_ex(&hctx->ctx, key->data, key->length, hctx->md,
ctx->engine);
break;
default:
return -2;
}
return 1;
}
static int pkey_hmac_ctrl_str(EVP_PKEY_CTX *ctx,
const char *type, const char *value)
{
if (!value)
{
return 0;
}
if (!strcmp(type, "key"))
{
void *p = (void *)value;
return pkey_hmac_ctrl(ctx, EVP_PKEY_CTRL_SET_MAC_KEY,
-1, p);
}
if (!strcmp(type, "hexkey"))
{
unsigned char *key;
int r;
long keylen;
key = string_to_hex(value, &keylen);
if (!key)
return 0;
r = pkey_hmac_ctrl(ctx, EVP_PKEY_CTRL_SET_MAC_KEY, keylen, key);
OPENSSL_free(key);
return r;
}
return -2;
}
