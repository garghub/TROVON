int EVP_VerifyFinal(EVP_MD_CTX *ctx, unsigned char *sigbuf,
unsigned int siglen, EVP_PKEY *pkey)
{
unsigned char m[EVP_MAX_MD_SIZE];
unsigned int m_len;
int i,ok=0,v;
MS_STATIC EVP_MD_CTX tmp_ctx;
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
EVP_MD_CTX_init(&tmp_ctx);
EVP_MD_CTX_copy_ex(&tmp_ctx,ctx);
EVP_DigestFinal_ex(&tmp_ctx,&(m[0]),&m_len);
EVP_MD_CTX_cleanup(&tmp_ctx);
if (ctx->digest->verify == NULL)
{
EVPerr(EVP_F_EVP_VERIFYFINAL,EVP_R_NO_VERIFY_FUNCTION_CONFIGURED);
return(0);
}
return(ctx->digest->verify(ctx->digest->type,m,m_len,
sigbuf,siglen,pkey->pkey.ptr));
}
