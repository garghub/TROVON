static int init(EVP_MD_CTX *ctx)
{
return WHIRLPOOL_Init(EVP_MD_CTX_md_data(ctx));
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return WHIRLPOOL_Update(EVP_MD_CTX_md_data(ctx), data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return WHIRLPOOL_Final(md, EVP_MD_CTX_md_data(ctx));
}
const EVP_MD *EVP_whirlpool(void)
{
return (&whirlpool_md);
}
