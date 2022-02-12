static int init(EVP_MD_CTX *ctx)
{ return MDC2_Init(ctx->md_data); }
static int update(EVP_MD_CTX *ctx,const void *data,unsigned long count)
{ return MDC2_Update(ctx->md_data,data,count); }
static int final(EVP_MD_CTX *ctx,unsigned char *md)
{ return MDC2_Final(md,ctx->md_data); }
const EVP_MD *EVP_mdc2(void)
{
return(&mdc2_md);
}
