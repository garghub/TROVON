int EVP_VerifyFinal(EVP_MD_CTX *ctx, const unsigned char *sigbuf,
unsigned int siglen, EVP_PKEY *pkey)
{
unsigned char m[EVP_MAX_MD_SIZE];
unsigned int m_len;
int i=-1,ok=0,v;
EVP_MD_CTX tmp_ctx;
EVP_PKEY_CTX *pkctx = NULL;
EVP_MD_CTX_init(&tmp_ctx);
if (!EVP_MD_CTX_copy_ex(&tmp_ctx,ctx))
goto err;
if (!EVP_DigestFinal_ex(&tmp_ctx,&(m[0]),&m_len))
goto err;
EVP_MD_CTX_cleanup(&tmp_ctx);
if (ctx->digest->flags & EVP_MD_FLAG_PKEY_METHOD_SIGNATURE)
{
i = -1;
pkctx = EVP_PKEY_CTX_new(pkey, NULL);
if (!pkctx)
goto err;
if (EVP_PKEY_verify_init(pkctx) <= 0)
goto err;
if (EVP_PKEY_CTX_set_signature_md(pkctx, ctx->digest) <= 0)
goto err;
i = EVP_PKEY_verify(pkctx, sigbuf, siglen, m, m_len);
err:
EVP_PKEY_CTX_free(pkctx);
return i;
}
for (i=0; i<4; i++)
{
v=ctx->digest->required_pkey_type[i];
if (v == 0) break;
if (pkey->type == v)
{
ok=1;
break;
}
}
if (!ok)
{
EVPerr(EVP_F_EVP_VERIFYFINAL,EVP_R_WRONG_PUBLIC_KEY_TYPE);
return(-1);
}
if (ctx->digest->verify == NULL)
{
EVPerr(EVP_F_EVP_VERIFYFINAL,EVP_R_NO_VERIFY_FUNCTION_CONFIGURED);
return(0);
}
return(ctx->digest->verify(ctx->digest->type,m,m_len,
sigbuf,siglen,pkey->pkey.ptr));
}
