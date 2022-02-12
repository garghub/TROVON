static int init(EVP_MD_CTX *ctx)
{
return MD4_Init(ctx->md_data);
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return MD4_Update(ctx->md_data, data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return MD4_Final(md, ctx->md_data);
}
const EVP_MD *EVP_md4(void)
{
return (&md4_md);
}
