static int init(EVP_MD_CTX *ctx)
{
return RIPEMD160_Init(ctx->md_data);
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return RIPEMD160_Update(ctx->md_data, data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return RIPEMD160_Final(md, ctx->md_data);
}
const EVP_MD *EVP_ripemd160(void)
{
return (&ripemd160_md);
}
