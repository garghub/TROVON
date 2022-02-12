static int pkey_ec_init(EVP_PKEY_CTX *ctx)
{
EC_PKEY_CTX *dctx;
dctx = OPENSSL_malloc(sizeof(EC_PKEY_CTX));
if (!dctx)
return 0;
dctx->gen_group = NULL;
dctx->md = NULL;
ctx->data = dctx;
return 1;
}
static int pkey_ec_copy(EVP_PKEY_CTX *dst, EVP_PKEY_CTX *src)
{
EC_PKEY_CTX *dctx, *sctx;
if (!pkey_ec_init(dst))
return 0;
sctx = src->data;
dctx = dst->data;
if (sctx->gen_group)
{
dctx->gen_group = EC_GROUP_dup(sctx->gen_group);
if (!dctx->gen_group)
return 0;
}
dctx->md = sctx->md;
return 1;
}
static void pkey_ec_cleanup(EVP_PKEY_CTX *ctx)
{
EC_PKEY_CTX *dctx = ctx->data;
if (dctx)
{
if (dctx->gen_group)
EC_GROUP_free(dctx->gen_group);
OPENSSL_free(dctx);
}
}
static int pkey_ec_sign(EVP_PKEY_CTX *ctx, unsigned char *sig, size_t *siglen,
const unsigned char *tbs, size_t tbslen)
{
int ret, type;
unsigned int sltmp;
EC_PKEY_CTX *dctx = ctx->data;
EC_KEY *ec = ctx->pkey->pkey.ec;
if (!sig)
{
*siglen = ECDSA_size(ec);
return 1;
}
else if(*siglen < (size_t)ECDSA_size(ec))
{
ECerr(EC_F_PKEY_EC_SIGN, EC_R_BUFFER_TOO_SMALL);
return 0;
}
if (dctx->md)
type = EVP_MD_type(dctx->md);
else
type = NID_sha1;
ret = ECDSA_sign(type, tbs, tbslen, sig, &sltmp, ec);
if (ret <= 0)
return ret;
*siglen = (size_t)sltmp;
return 1;
}
static int pkey_ec_verify(EVP_PKEY_CTX *ctx,
const unsigned char *sig, size_t siglen,
const unsigned char *tbs, size_t tbslen)
{
int ret, type;
EC_PKEY_CTX *dctx = ctx->data;
EC_KEY *ec = ctx->pkey->pkey.ec;
if (dctx->md)
type = EVP_MD_type(dctx->md);
else
type = NID_sha1;
ret = ECDSA_verify(type, tbs, tbslen, sig, siglen, ec);
return ret;
}
static int pkey_ec_derive(EVP_PKEY_CTX *ctx, unsigned char *key, size_t *keylen)
{
int ret;
size_t outlen;
const EC_POINT *pubkey = NULL;
if (!ctx->pkey || !ctx->peerkey)
{
ECerr(EC_F_PKEY_EC_DERIVE, EC_R_KEYS_NOT_SET);
return 0;
}
if (!key)
{
const EC_GROUP *group;
group = EC_KEY_get0_group(ctx->pkey->pkey.ec);
*keylen = (EC_GROUP_get_degree(group) + 7)/8;
return 1;
}
pubkey = EC_KEY_get0_public_key(ctx->peerkey->pkey.ec);
outlen = *keylen;
ret = ECDH_compute_key(key, outlen, pubkey, ctx->pkey->pkey.ec, 0);
if (ret < 0)
return ret;
*keylen = ret;
return 1;
}
static int pkey_ec_ctrl(EVP_PKEY_CTX *ctx, int type, int p1, void *p2)
{
EC_PKEY_CTX *dctx = ctx->data;
EC_GROUP *group;
switch (type)
{
case EVP_PKEY_CTRL_EC_PARAMGEN_CURVE_NID:
group = EC_GROUP_new_by_curve_name(p1);
if (group == NULL)
{
ECerr(EC_F_PKEY_EC_CTRL, EC_R_INVALID_CURVE);
return 0;
}
if (dctx->gen_group)
EC_GROUP_free(dctx->gen_group);
dctx->gen_group = group;
return 1;
case EVP_PKEY_CTRL_MD:
if (EVP_MD_type((const EVP_MD *)p2) != NID_sha1 &&
EVP_MD_type((const EVP_MD *)p2) != NID_sha224 &&
EVP_MD_type((const EVP_MD *)p2) != NID_sha256 &&
EVP_MD_type((const EVP_MD *)p2) != NID_sha384 &&
EVP_MD_type((const EVP_MD *)p2) != NID_sha512)
{
ECerr(EC_F_PKEY_EC_CTRL, EC_R_INVALID_DIGEST_TYPE);
return 0;
}
dctx->md = p2;
return 1;
case EVP_PKEY_CTRL_PEER_KEY:
case EVP_PKEY_CTRL_DIGESTINIT:
case EVP_PKEY_CTRL_PKCS7_SIGN:
case EVP_PKEY_CTRL_CMS_SIGN:
return 1;
default:
return -2;
}
}
static int pkey_ec_ctrl_str(EVP_PKEY_CTX *ctx,
const char *type, const char *value)
{
if (!strcmp(type, "ec_paramgen_curve"))
{
int nid;
nid = OBJ_sn2nid(value);
if (nid == NID_undef)
nid = OBJ_ln2nid(value);
if (nid == NID_undef)
{
ECerr(EC_F_PKEY_EC_CTRL_STR, EC_R_INVALID_CURVE);
return 0;
}
return EVP_PKEY_CTX_set_ec_paramgen_curve_nid(ctx, nid);
}
return -2;
}
static int pkey_ec_paramgen(EVP_PKEY_CTX *ctx, EVP_PKEY *pkey)
{
EC_KEY *ec = NULL;
EC_PKEY_CTX *dctx = ctx->data;
int ret = 0;
if (dctx->gen_group == NULL)
{
ECerr(EC_F_PKEY_EC_PARAMGEN, EC_R_NO_PARAMETERS_SET);
return 0;
}
ec = EC_KEY_new();
if (!ec)
return 0;
ret = EC_KEY_set_group(ec, dctx->gen_group);
if (ret)
EVP_PKEY_assign_EC_KEY(pkey, ec);
else
EC_KEY_free(ec);
return ret;
}
static int pkey_ec_keygen(EVP_PKEY_CTX *ctx, EVP_PKEY *pkey)
{
EC_KEY *ec = NULL;
if (ctx->pkey == NULL)
{
ECerr(EC_F_PKEY_EC_KEYGEN, EC_R_NO_PARAMETERS_SET);
return 0;
}
ec = EC_KEY_new();
if (!ec)
return 0;
EVP_PKEY_assign_EC_KEY(pkey, ec);
if (!EVP_PKEY_copy_parameters(pkey, ctx->pkey))
return 0;
return EC_KEY_generate_key(pkey->pkey.ec);
}
