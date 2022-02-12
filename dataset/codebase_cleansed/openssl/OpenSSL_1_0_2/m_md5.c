static int init(EVP_MD_CTX *ctx)
{
return MD5_Init(ctx->md_data);
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return MD5_Update(ctx->md_data, data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return MD5_Final(md, ctx->md_data);
}
const EVP_MD *EVP_md5(void)
{
return (&md5_md);
}
