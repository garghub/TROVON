static int init(EVP_MD_CTX *ctx)
{
return SHA1_Init(ctx->md_data);
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return SHA1_Update(ctx->md_data, data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return SHA1_Final(md, ctx->md_data);
}
const EVP_MD *EVP_sha1(void)
{
return (&sha1_md);
}
static int init224(EVP_MD_CTX *ctx)
{
return SHA224_Init(ctx->md_data);
}
static int init256(EVP_MD_CTX *ctx)
{
return SHA256_Init(ctx->md_data);
}
static int update256(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return SHA256_Update(ctx->md_data, data, count);
}
static int final256(EVP_MD_CTX *ctx, unsigned char *md)
{
return SHA256_Final(md, ctx->md_data);
}
const EVP_MD *EVP_sha224(void)
{
return (&sha224_md);
}
const EVP_MD *EVP_sha256(void)
{
return (&sha256_md);
}
static int init384(EVP_MD_CTX *ctx)
{
return SHA384_Init(ctx->md_data);
}
static int init512(EVP_MD_CTX *ctx)
{
return SHA512_Init(ctx->md_data);
}
static int update512(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return SHA512_Update(ctx->md_data, data, count);
}
static int final512(EVP_MD_CTX *ctx, unsigned char *md)
{
return SHA512_Final(md, ctx->md_data);
}
const EVP_MD *EVP_sha384(void)
{
return (&sha384_md);
}
const EVP_MD *EVP_sha512(void)
{
return (&sha512_md);
}
