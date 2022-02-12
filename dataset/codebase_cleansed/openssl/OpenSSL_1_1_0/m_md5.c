static int init(EVP_MD_CTX *ctx)
{
return MD5_Init(EVP_MD_CTX_md_data(ctx));
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return MD5_Update(EVP_MD_CTX_md_data(ctx), data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return MD5_Final(md, EVP_MD_CTX_md_data(ctx));
}
const EVP_MD *EVP_md5(void)
{
return (&md5_md);
}
