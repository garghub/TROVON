void HMAC_Init(HMAC_CTX *ctx, const void *key, int len,
const EVP_MD *md)
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
if (j < len)
{
EVP_DigestInit(&ctx->md_ctx,md);
EVP_DigestUpdate(&ctx->md_ctx,key,len);
EVP_DigestFinal(&(ctx->md_ctx),ctx->key,
&ctx->key_length);
}
else
{
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
EVP_DigestInit(&ctx->i_ctx,md);
EVP_DigestUpdate(&ctx->i_ctx,pad,EVP_MD_block_size(md));
for (i=0; i<HMAC_MAX_MD_CBLOCK; i++)
pad[i]=0x5c^ctx->key[i];
EVP_DigestInit(&ctx->o_ctx,md);
EVP_DigestUpdate(&ctx->o_ctx,pad,EVP_MD_block_size(md));
}
memcpy(&ctx->md_ctx,&ctx->i_ctx,sizeof(ctx->i_ctx));
}
void HMAC_Update(HMAC_CTX *ctx, const unsigned char *data, int len)
{
EVP_DigestUpdate(&(ctx->md_ctx),data,len);
}
void HMAC_Final(HMAC_CTX *ctx, unsigned char *md, unsigned int *len)
{
int j;
unsigned int i;
unsigned char buf[EVP_MAX_MD_SIZE];
j=EVP_MD_block_size(ctx->md);
EVP_DigestFinal(&(ctx->md_ctx),buf,&i);
memcpy(&(ctx->md_ctx),&(ctx->o_ctx),sizeof(ctx->o_ctx));
EVP_DigestUpdate(&(ctx->md_ctx),buf,i);
EVP_DigestFinal(&(ctx->md_ctx),md,len);
}
void HMAC_cleanup(HMAC_CTX *ctx)
{
memset(ctx,0,sizeof(HMAC_CTX));
}
unsigned char *HMAC(const EVP_MD *evp_md, const void *key, int key_len,
const unsigned char *d, int n, unsigned char *md,
unsigned int *md_len)
{
HMAC_CTX c;
static unsigned char m[EVP_MAX_MD_SIZE];
if (md == NULL) md=m;
HMAC_Init(&c,key,key_len,evp_md);
HMAC_Update(&c,d,n);
HMAC_Final(&c,md,md_len);
HMAC_cleanup(&c);
return(md);
}
