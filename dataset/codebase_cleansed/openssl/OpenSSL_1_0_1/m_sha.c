static int init(EVP_MD_CTX *ctx)
{ return SHA_Init(ctx->md_data); }
static int update(EVP_MD_CTX *ctx,const void *data,size_t count)
{ return SHA_Update(ctx->md_data,data,count); }
static int final(EVP_MD_CTX *ctx,unsigned char *md)
{ return SHA_Final(md,ctx->md_data); }
const EVP_MD *EVP_sha(void)
{
return(&sha_md);
}
