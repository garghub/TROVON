void EVP_DigestInit(EVP_MD_CTX *ctx, const EVP_MD *type)
{
ctx->digest=type;
type->init(&(ctx->md));
}
void EVP_DigestUpdate(EVP_MD_CTX *ctx, const unsigned char *data,
unsigned int count)
{
ctx->digest->update(&(ctx->md.base[0]),data,(unsigned long)count);
}
void EVP_DigestFinal(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *size)
{
ctx->digest->final(md,&(ctx->md.base[0]));
if (size != NULL)
*size=ctx->digest->md_size;
memset(&(ctx->md),0,sizeof(ctx->md));
}
int EVP_MD_CTX_copy(EVP_MD_CTX *out, EVP_MD_CTX *in)
{
if ((in == NULL) || (in->digest == NULL)) {
EVPerr(EVP_F_EVP_MD_CTX_COPY,EVP_R_INPUT_NOT_INITIALIZED);
return 0;
}
memcpy((char *)out,(char *)in,in->digest->ctx_size);
return 1;
}
