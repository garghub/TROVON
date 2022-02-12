static int init(EVP_MD_CTX *ctx)
{
return 1;
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return 1;
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return 1;
}
const EVP_MD *EVP_md_null(void)
{
return (&null_md);
}
