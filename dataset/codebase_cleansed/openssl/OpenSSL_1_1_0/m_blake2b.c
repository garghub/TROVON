static int init(EVP_MD_CTX *ctx)
{
return BLAKE2b_Init(EVP_MD_CTX_md_data(ctx));
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return BLAKE2b_Update(EVP_MD_CTX_md_data(ctx), data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return BLAKE2b_Final(md, EVP_MD_CTX_md_data(ctx));
}
const EVP_MD *EVP_blake2b512(void)
{
return (&blake2b_md);
}
