static int init(EVP_MD_CTX *ctx)
{
struct md5_sha1_ctx *mctx = EVP_MD_CTX_md_data(ctx);
if (!MD5_Init(&mctx->md5))
return 0;
return SHA1_Init(&mctx->sha1);
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
struct md5_sha1_ctx *mctx = EVP_MD_CTX_md_data(ctx);
if (!MD5_Update(&mctx->md5, data, count))
return 0;
return SHA1_Update(&mctx->sha1, data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
struct md5_sha1_ctx *mctx = EVP_MD_CTX_md_data(ctx);
if (!MD5_Final(md, &mctx->md5))
return 0;
return SHA1_Final(md + MD5_DIGEST_LENGTH, &mctx->sha1);
}
static int ctrl(EVP_MD_CTX *ctx, int cmd, int mslen, void *ms)
{
unsigned char padtmp[48];
unsigned char md5tmp[MD5_DIGEST_LENGTH];
unsigned char sha1tmp[SHA_DIGEST_LENGTH];
struct md5_sha1_ctx *mctx = EVP_MD_CTX_md_data(ctx);
if (cmd != EVP_CTRL_SSL3_MASTER_SECRET)
return 0;
if (mslen != 48)
return 0;
if (update(ctx, ms, mslen) <= 0)
return 0;
memset(padtmp, 0x36, sizeof(padtmp));
if (!MD5_Update(&mctx->md5, padtmp, sizeof(padtmp)))
return 0;
if (!MD5_Final(md5tmp, &mctx->md5))
return 0;
if (!SHA1_Update(&mctx->sha1, padtmp, 40))
return 0;
if (!SHA1_Final(sha1tmp, &mctx->sha1))
return 0;
if (!init(ctx))
return 0;
if (update(ctx, ms, mslen) <= 0)
return 0;
memset(padtmp, 0x5c, sizeof(padtmp));
if (!MD5_Update(&mctx->md5, padtmp, sizeof(padtmp)))
return 0;
if (!MD5_Update(&mctx->md5, md5tmp, sizeof(md5tmp)))
return 0;
if (!SHA1_Update(&mctx->sha1, padtmp, 40))
return 0;
if (!SHA1_Update(&mctx->sha1, sha1tmp, sizeof(sha1tmp)))
return 0;
OPENSSL_cleanse(md5tmp, sizeof(md5tmp));
OPENSSL_cleanse(sha1tmp, sizeof(sha1tmp));
return 1;
}
const EVP_MD *EVP_md5_sha1(void)
{
return &md5_sha1_md;
}
