static int init(EVP_MD_CTX *ctx)
{
return MD4_Init(EVP_MD_CTX_md_data(ctx));
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return MD4_Update(EVP_MD_CTX_md_data(ctx), data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return MD4_Final(md, EVP_MD_CTX_md_data(ctx));
}
const EVP_MD *EVP_md4(void)
{
return (&md4_md);
}
