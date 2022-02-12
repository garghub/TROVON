static int init(EVP_MD_CTX *ctx)
{
return MDC2_Init(EVP_MD_CTX_md_data(ctx));
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return MDC2_Update(EVP_MD_CTX_md_data(ctx), data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return MDC2_Final(md, EVP_MD_CTX_md_data(ctx));
}
const EVP_MD *EVP_mdc2(void)
{
return (&mdc2_md);
}
