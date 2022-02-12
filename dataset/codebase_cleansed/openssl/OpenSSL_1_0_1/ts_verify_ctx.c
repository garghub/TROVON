TS_VERIFY_CTX *TS_VERIFY_CTX_new(void)
{
TS_VERIFY_CTX *ctx =
(TS_VERIFY_CTX *) OPENSSL_malloc(sizeof(TS_VERIFY_CTX));
if (ctx)
memset(ctx, 0, sizeof(TS_VERIFY_CTX));
else
TSerr(TS_F_TS_VERIFY_CTX_NEW, ERR_R_MALLOC_FAILURE);
return ctx;
}
void TS_VERIFY_CTX_init(TS_VERIFY_CTX *ctx)
{
OPENSSL_assert(ctx != NULL);
memset(ctx, 0, sizeof(TS_VERIFY_CTX));
}
void TS_VERIFY_CTX_free(TS_VERIFY_CTX *ctx)
{
if (!ctx) return;
TS_VERIFY_CTX_cleanup(ctx);
OPENSSL_free(ctx);
}
void TS_VERIFY_CTX_cleanup(TS_VERIFY_CTX *ctx)
{
if (!ctx) return;
X509_STORE_free(ctx->store);
sk_X509_pop_free(ctx->certs, X509_free);
ASN1_OBJECT_free(ctx->policy);
X509_ALGOR_free(ctx->md_alg);
OPENSSL_free(ctx->imprint);
BIO_free_all(ctx->data);
ASN1_INTEGER_free(ctx->nonce);
GENERAL_NAME_free(ctx->tsa_name);
TS_VERIFY_CTX_init(ctx);
}
TS_VERIFY_CTX *TS_REQ_to_TS_VERIFY_CTX(TS_REQ *req, TS_VERIFY_CTX *ctx)
{
TS_VERIFY_CTX *ret = ctx;
ASN1_OBJECT *policy;
TS_MSG_IMPRINT *imprint;
X509_ALGOR *md_alg;
ASN1_OCTET_STRING *msg;
const ASN1_INTEGER *nonce;
OPENSSL_assert(req != NULL);
if (ret)
TS_VERIFY_CTX_cleanup(ret);
else
if (!(ret = TS_VERIFY_CTX_new())) return NULL;
ret->flags = TS_VFY_ALL_IMPRINT & ~(TS_VFY_TSA_NAME | TS_VFY_SIGNATURE);
if ((policy = TS_REQ_get_policy_id(req)) != NULL)
{
if (!(ret->policy = OBJ_dup(policy))) goto err;
}
else
ret->flags &= ~TS_VFY_POLICY;
imprint = TS_REQ_get_msg_imprint(req);
md_alg = TS_MSG_IMPRINT_get_algo(imprint);
if (!(ret->md_alg = X509_ALGOR_dup(md_alg))) goto err;
msg = TS_MSG_IMPRINT_get_msg(imprint);
ret->imprint_len = ASN1_STRING_length(msg);
if (!(ret->imprint = OPENSSL_malloc(ret->imprint_len))) goto err;
memcpy(ret->imprint, ASN1_STRING_data(msg), ret->imprint_len);
if ((nonce = TS_REQ_get_nonce(req)) != NULL)
{
if (!(ret->nonce = ASN1_INTEGER_dup(nonce))) goto err;
}
else
ret->flags &= ~TS_VFY_NONCE;
return ret;
err:
if (ctx)
TS_VERIFY_CTX_cleanup(ctx);
else
TS_VERIFY_CTX_free(ret);
return NULL;
}
