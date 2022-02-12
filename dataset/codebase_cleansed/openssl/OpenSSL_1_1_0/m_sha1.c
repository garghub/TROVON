static int init(EVP_MD_CTX *ctx)
{
return SHA1_Init(EVP_MD_CTX_md_data(ctx));
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return SHA1_Update(EVP_MD_CTX_md_data(ctx), data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return SHA1_Final(md, EVP_MD_CTX_md_data(ctx));
}
static int ctrl(EVP_MD_CTX *ctx, int cmd, int mslen, void *ms)
{
unsigned char padtmp[40];
unsigned char sha1tmp[SHA_DIGEST_LENGTH];
SHA_CTX *sha1 = EVP_MD_CTX_md_data(ctx);
if (cmd != EVP_CTRL_SSL3_MASTER_SECRET)
return 0;
if (mslen != 48)
return 0;
if (SHA1_Update(sha1, ms, mslen) <= 0)
return 0;
memset(padtmp, 0x36, sizeof(padtmp));
if (!SHA1_Update(sha1, padtmp, sizeof(padtmp)))
return 0;
if (!SHA1_Final(sha1tmp, sha1))
return 0;
if (!SHA1_Init(sha1))
return 0;
if (SHA1_Update(sha1, ms, mslen) <= 0)
return 0;
memset(padtmp, 0x5c, sizeof(padtmp));
if (!SHA1_Update(sha1, padtmp, sizeof(padtmp)))
return 0;
if (!SHA1_Update(sha1, sha1tmp, sizeof(sha1tmp)))
return 0;
OPENSSL_cleanse(sha1tmp, sizeof(sha1tmp));
return 1;
}
const EVP_MD *EVP_sha1(void)
{
return (&sha1_md);
}
static int init224(EVP_MD_CTX *ctx)
{
return SHA224_Init(EVP_MD_CTX_md_data(ctx));
}
static int init256(EVP_MD_CTX *ctx)
{
return SHA256_Init(EVP_MD_CTX_md_data(ctx));
}
static int update256(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return SHA256_Update(EVP_MD_CTX_md_data(ctx), data, count);
}
static int final256(EVP_MD_CTX *ctx, unsigned char *md)
{
return SHA256_Final(md, EVP_MD_CTX_md_data(ctx));
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
return SHA384_Init(EVP_MD_CTX_md_data(ctx));
}
static int init512(EVP_MD_CTX *ctx)
{
return SHA512_Init(EVP_MD_CTX_md_data(ctx));
}
static int update512(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return SHA512_Update(EVP_MD_CTX_md_data(ctx), data, count);
}
static int final512(EVP_MD_CTX *ctx, unsigned char *md)
{
return SHA512_Final(md, EVP_MD_CTX_md_data(ctx));
}
const EVP_MD *EVP_sha384(void)
{
return (&sha384_md);
}
const EVP_MD *EVP_sha512(void)
{
return (&sha512_md);
}
