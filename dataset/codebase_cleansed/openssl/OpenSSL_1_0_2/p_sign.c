void EVP_SignInit(EVP_MD_CTX *ctx, EVP_MD *type)
{
EVP_DigestInit_ex(ctx, type);
}
void EVP_SignUpdate(EVP_MD_CTX *ctx, unsigned char *data, unsigned int count)
{
EVP_DigestUpdate(ctx, data, count);
}
int EVP_SignFinal(EVP_MD_CTX *ctx, unsigned char *sigret,
unsigned int *siglen, EVP_PKEY *pkey)
{
unsigned char m[EVP_MAX_MD_SIZE];
unsigned int m_len;
int i = 0, ok = 0, v;
EVP_MD_CTX tmp_ctx;
EVP_PKEY_CTX *pkctx = NULL;
*siglen = 0;
EVP_MD_CTX_init(&tmp_ctx);
if (!EVP_MD_CTX_copy_ex(&tmp_ctx, ctx))
goto err;
if (!EVP_DigestFinal_ex(&tmp_ctx, &(m[0]), &m_len))
goto err;
EVP_MD_CTX_cleanup(&tmp_ctx);
if (ctx->digest->flags & EVP_MD_FLAG_PKEY_METHOD_SIGNATURE) {
size_t sltmp = (size_t)EVP_PKEY_size(pkey);
i = 0;
pkctx = EVP_PKEY_CTX_new(pkey, NULL);
if (!pkctx)
goto err;
if (EVP_PKEY_sign_init(pkctx) <= 0)
goto err;
if (EVP_PKEY_CTX_set_signature_md(pkctx, ctx->digest) <= 0)
goto err;
if (EVP_PKEY_sign(pkctx, sigret, &sltmp, m, m_len) <= 0)
goto err;
*siglen = sltmp;
i = 1;
err:
EVP_PKEY_CTX_free(pkctx);
return i;
}
for (i = 0; i < 4; i++) {
v = ctx->digest->required_pkey_type[i];
if (v == 0)
break;
if (pkey->type == v) {
ok = 1;
break;
}
}
if (!ok) {
EVPerr(EVP_F_EVP_SIGNFINAL, EVP_R_WRONG_PUBLIC_KEY_TYPE);
return (0);
}
if (ctx->digest->sign == NULL) {
EVPerr(EVP_F_EVP_SIGNFINAL, EVP_R_NO_SIGN_FUNCTION_CONFIGURED);
return (0);
}
return (ctx->digest->sign(ctx->digest->type, m, m_len, sigret, siglen,
pkey->pkey.ptr));
}
