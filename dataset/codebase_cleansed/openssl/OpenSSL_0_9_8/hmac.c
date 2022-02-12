void HMAC_Init_ex(HMAC_CTX *ctx, const void *key, int len,
const EVP_MD *md, ENGINE *impl)
{
int i,j,reset=0;
unsigned char pad[HMAC_MAX_MD_CBLOCK];
if (md != NULL)
{
reset=1;
ctx->md=md;
}
else
md=ctx->md;
if (key != NULL)
{
reset=1;
j=EVP_MD_block_size(md);
OPENSSL_assert(j <= (int)sizeof(ctx->key));
if (j < len)
{
EVP_DigestInit_ex(&ctx->md_ctx,md, impl);
EVP_DigestUpdate(&ctx->md_ctx,key,len);
EVP_DigestFinal_ex(&(ctx->md_ctx),ctx->key,
&ctx->key_length);
}
else
{
OPENSSL_assert(len>=0 && len<=(int)sizeof(ctx->key));
memcpy(ctx->key,key,len);
ctx->key_length=len;
}
if(ctx->key_length != HMAC_MAX_MD_CBLOCK)
memset(&ctx->key[ctx->key_length], 0,
HMAC_MAX_MD_CBLOCK - ctx->key_length);
}
if (reset)
{
for (i=0; i<HMAC_MAX_MD_CBLOCK; i++)
pad[i]=0x36^ctx->key[i];
EVP_DigestInit_ex(&ctx->i_ctx,md, impl);
EVP_DigestUpdate(&ctx->i_ctx,pad,EVP_MD_block_size(md));
for (i=0; i<HMAC_MAX_MD_CBLOCK; i++)
pad[i]=0x5c^ctx->key[i];
EVP_DigestInit_ex(&ctx->o_ctx,md, impl);
EVP_DigestUpdate(&ctx->o_ctx,pad,EVP_MD_block_size(md));
}
EVP_MD_CTX_copy_ex(&ctx->md_ctx,&ctx->i_ctx);
}
void HMAC_Init(HMAC_CTX *ctx, const void *key, int len,
const EVP_MD *md)
{
if(key && md)
HMAC_CTX_init(ctx);
HMAC_Init_ex(ctx,key,len,md, NULL);
}
void HMAC_Update(HMAC_CTX *ctx, const unsigned char *data, size_t len)
{
EVP_DigestUpdate(&ctx->md_ctx,data,len);
}
void HMAC_Final(HMAC_CTX *ctx, unsigned char *md, unsigned int *len)
{
int j;
unsigned int i;
unsigned char buf[EVP_MAX_MD_SIZE];
j=EVP_MD_block_size(ctx->md);
EVP_DigestFinal_ex(&ctx->md_ctx,buf,&i);
EVP_MD_CTX_copy_ex(&ctx->md_ctx,&ctx->o_ctx);
EVP_DigestUpdate(&ctx->md_ctx,buf,i);
EVP_DigestFinal_ex(&ctx->md_ctx,md,len);
}
void HMAC_CTX_init(HMAC_CTX *ctx)
{
EVP_MD_CTX_init(&ctx->i_ctx);
EVP_MD_CTX_init(&ctx->o_ctx);
EVP_MD_CTX_init(&ctx->md_ctx);
}
void HMAC_CTX_cleanup(HMAC_CTX *ctx)
{
EVP_MD_CTX_cleanup(&ctx->i_ctx);
EVP_MD_CTX_cleanup(&ctx->o_ctx);
EVP_MD_CTX_cleanup(&ctx->md_ctx);
memset(ctx,0,sizeof *ctx);
}
unsigned char *HMAC(const EVP_MD *evp_md, const void *key, int key_len,
const unsigned char *d, size_t n, unsigned char *md,
unsigned int *md_len)
{
HMAC_CTX c;
static unsigned char m[EVP_MAX_MD_SIZE];
if (md == NULL) md=m;
HMAC_CTX_init(&c);
HMAC_Init(&c,key,key_len,evp_md);
HMAC_Update(&c,d,n);
HMAC_Final(&c,md,md_len);
HMAC_CTX_cleanup(&c);
return(md);
}
