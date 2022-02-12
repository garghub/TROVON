static int init(EVP_MD_CTX *ctx)
{
return RIPEMD160_Init(EVP_MD_CTX_md_data(ctx));
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return RIPEMD160_Update(EVP_MD_CTX_md_data(ctx), data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return RIPEMD160_Final(md, EVP_MD_CTX_md_data(ctx));
}
const EVP_MD *EVP_ripemd160(void)
{
return (&ripemd160_md);
}
