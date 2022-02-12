const struct gost_cipher_info *get_encryption_params(ASN1_OBJECT *obj)
{
int nid;
struct gost_cipher_info *param;
if (!obj)
{
const char * params = get_gost_engine_param(GOST_PARAM_CRYPT_PARAMS);
if (!params || !strlen(params))
return &gost_cipher_list[1];
nid = OBJ_txt2nid(params);
if (nid == NID_undef)
{
GOSTerr(GOST_F_GET_ENCRYPTION_PARAMS,
GOST_R_INVALID_CIPHER_PARAM_OID);
return NULL;
}
}
else
{
nid= OBJ_obj2nid(obj);
}
for (param=gost_cipher_list;param->sblock!=NULL && param->nid!=nid;
param++);
if (!param->sblock)
{
GOSTerr(GOST_F_GET_ENCRYPTION_PARAMS,GOST_R_INVALID_CIPHER_PARAMS);
return NULL;
}
return param;
}
static int gost_cipher_set_param(struct ossl_gost_cipher_ctx *c,int nid)
{
const struct gost_cipher_info *param;
param=get_encryption_params((nid==NID_undef?NULL:OBJ_nid2obj(nid)));
if (!param) return 0;
c->paramNID = param->nid;
c->key_meshing=param->key_meshing;
c->count=0;
gost_init(&(c->cctx), param->sblock);
return 1;
}
static int gost_cipher_init_param(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc, int paramNID,int mode)
{
struct ossl_gost_cipher_ctx *c=ctx->cipher_data;
if (ctx->app_data == NULL)
{
if (!gost_cipher_set_param(c,paramNID)) return 0;
ctx->app_data = ctx->cipher_data;
}
if (key) gost_key(&(c->cctx),key);
if(iv) memcpy(ctx->oiv, iv, EVP_CIPHER_CTX_iv_length(ctx));
memcpy(ctx->iv, ctx->oiv, EVP_CIPHER_CTX_iv_length(ctx));
return 1;
}
static int gost_cipher_init_cpa(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
struct ossl_gost_cipher_ctx *c=ctx->cipher_data;
gost_init(&(c->cctx),&Gost28147_CryptoProParamSetA);
c->key_meshing=1;
c->count=0;
if(key) gost_key(&(c->cctx),key);
if(iv) memcpy(ctx->oiv, iv, EVP_CIPHER_CTX_iv_length(ctx));
memcpy(ctx->iv, ctx->oiv, EVP_CIPHER_CTX_iv_length(ctx));
return 1;
}
int gost_cipher_init(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
return gost_cipher_init_param(ctx,key,iv,enc,NID_undef,EVP_CIPH_CFB_MODE);
}
static void gost_crypt_mesh (void *ctx,unsigned char *iv,unsigned char *buf)
{
struct ossl_gost_cipher_ctx *c = ctx;
if (c->count&&c->key_meshing && c->count%1024==0)
{
cryptopro_key_meshing(&(c->cctx),iv);
}
gostcrypt(&(c->cctx),iv,buf);
c->count+=8;
}
static void gost_cnt_next (void *ctx, unsigned char *iv, unsigned char *buf)
{
struct ossl_gost_cipher_ctx *c = ctx;
word32 g,go;
unsigned char buf1[8];
if (c->count && c->key_meshing && c->count %1024 ==0)
{
cryptopro_key_meshing(&(c->cctx),iv);
}
if (c->count==0)
{
gostcrypt(&(c->cctx),iv,buf1);
}
else
{
memcpy(buf1,iv,8);
}
g = buf1[0]|(buf1[1]<<8)|(buf1[2]<<16)|(buf1[3]<<24);
g += 0x01010101;
buf1[0]=(unsigned char)(g&0xff);
buf1[1]=(unsigned char)((g>>8)&0xff);
buf1[2]=(unsigned char)((g>>16)&0xff);
buf1[3]=(unsigned char)((g>>24)&0xff);
g = buf1[4]|(buf1[5]<<8)|(buf1[6]<<16)|(buf1[7]<<24);
go = g;
g += 0x01010104;
if (go > g)
g++;
buf1[4]=(unsigned char)(g&0xff);
buf1[5]=(unsigned char)((g>>8)&0xff);
buf1[6]=(unsigned char)((g>>16)&0xff);
buf1[7]=(unsigned char)((g>>24)&0xff);
memcpy(iv,buf1,8);
gostcrypt(&(c->cctx),buf1,buf);
c->count +=8;
}
int gost_cipher_do_cfb(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
const unsigned char *in_ptr=in;
unsigned char *out_ptr=out;
size_t i=0;
size_t j=0;
if (ctx->num)
{
for (j=ctx->num,i=0;j<8 && i<inl;j++,i++,in_ptr++,out_ptr++)
{
if (!ctx->encrypt) ctx->buf[j+8]=*in_ptr;
*out_ptr=ctx->buf[j]^(*in_ptr);
if (ctx->encrypt) ctx->buf[j+8]=*out_ptr;
}
if (j==8)
{
memcpy(ctx->iv,ctx->buf+8,8);
ctx->num=0;
}
else
{
ctx->num=j;
return 1;
}
}
for (;i+8<inl;i+=8,in_ptr+=8,out_ptr+=8)
{
gost_crypt_mesh(ctx->cipher_data,ctx->iv,ctx->buf);
if (!ctx->encrypt) memcpy(ctx->iv,in_ptr,8);
for (j=0;j<8;j++)
{
out_ptr[j]=ctx->buf[j]^in_ptr[j];
}
if (ctx->encrypt) memcpy(ctx->iv,out_ptr,8);
}
if (i<inl)
{
gost_crypt_mesh(ctx->cipher_data,ctx->iv,ctx->buf);
if (!ctx->encrypt) memcpy(ctx->buf+8,in_ptr,inl-i);
for (j=0;i<inl;j++,i++)
{
out_ptr[j]=ctx->buf[j]^in_ptr[j];
}
ctx->num = j;
if (ctx->encrypt) memcpy(ctx->buf+8,out_ptr,j);
}
else
{
ctx->num = 0;
}
return 1;
}
static int gost_cipher_do_cnt(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
const unsigned char *in_ptr=in;
unsigned char *out_ptr=out;
size_t i=0;
size_t j;
if (ctx->num)
{
for (j=ctx->num,i=0;j<8 && i<inl;j++,i++,in_ptr++,out_ptr++)
{
*out_ptr=ctx->buf[j]^(*in_ptr);
}
if (j==8)
{
ctx->num=0;
}
else
{
ctx->num=j;
return 1;
}
}
for (;i+8<inl;i+=8,in_ptr+=8,out_ptr+=8)
{
gost_cnt_next(ctx->cipher_data,ctx->iv,ctx->buf);
for (j=0;j<8;j++)
{
out_ptr[j]=ctx->buf[j]^in_ptr[j];
}
}
if (i<inl)
{
gost_cnt_next(ctx->cipher_data,ctx->iv,ctx->buf);
for (j=0;i<inl;j++,i++)
{
out_ptr[j]=ctx->buf[j]^in_ptr[j];
}
ctx->num = j;
}
else
{
ctx->num = 0;
}
return 1;
}
int gost_cipher_cleanup(EVP_CIPHER_CTX *ctx)
{
gost_destroy(&((struct ossl_gost_cipher_ctx *)ctx->cipher_data)->cctx);
ctx->app_data = NULL;
return 1;
}
int gost_cipher_ctl(EVP_CIPHER_CTX *ctx,int type,int arg,void *ptr)
{
switch (type)
{
case EVP_CTRL_RAND_KEY:
{
if (RAND_bytes((unsigned char *)ptr,ctx->key_len)<=0)
{
GOSTerr(GOST_F_GOST_CIPHER_CTL,GOST_R_RANDOM_GENERATOR_ERROR);
return -1;
}
break;
}
case EVP_CTRL_PBE_PRF_NID:
if (ptr) {
*((int *)ptr)= NID_id_HMACGostR3411_94;
return 1;
} else {
return 0;
}
default:
GOSTerr(GOST_F_GOST_CIPHER_CTL,GOST_R_UNSUPPORTED_CIPHER_CTL_COMMAND);
return -1;
}
return 1;
}
int gost89_set_asn1_parameters(EVP_CIPHER_CTX *ctx,ASN1_TYPE *params)
{
int len=0;
unsigned char *buf=NULL;
unsigned char *p=NULL;
struct ossl_gost_cipher_ctx *c = ctx->cipher_data;
GOST_CIPHER_PARAMS *gcp = GOST_CIPHER_PARAMS_new();
ASN1_OCTET_STRING *os = NULL;
if (!gcp)
{
GOSTerr(GOST_F_GOST89_SET_ASN1_PARAMETERS, GOST_R_NO_MEMORY);
return 0;
}
if (!ASN1_OCTET_STRING_set(gcp->iv, ctx->iv, ctx->cipher->iv_len))
{
GOST_CIPHER_PARAMS_free(gcp);
GOSTerr(GOST_F_GOST89_SET_ASN1_PARAMETERS, GOST_R_NO_MEMORY);
return 0;
}
ASN1_OBJECT_free(gcp->enc_param_set);
gcp->enc_param_set = OBJ_nid2obj(c->paramNID);
len = i2d_GOST_CIPHER_PARAMS(gcp, NULL);
p = buf = (unsigned char*)OPENSSL_malloc(len);
if (!buf)
{
GOST_CIPHER_PARAMS_free(gcp);
GOSTerr(GOST_F_GOST89_SET_ASN1_PARAMETERS, GOST_R_NO_MEMORY);
return 0;
}
i2d_GOST_CIPHER_PARAMS(gcp, &p);
GOST_CIPHER_PARAMS_free(gcp);
os = ASN1_OCTET_STRING_new();
if(!os || !ASN1_OCTET_STRING_set(os, buf, len))
{
OPENSSL_free(buf);
GOSTerr(GOST_F_GOST89_SET_ASN1_PARAMETERS, GOST_R_NO_MEMORY);
return 0;
}
OPENSSL_free(buf);
ASN1_TYPE_set(params, V_ASN1_SEQUENCE, os);
return 1;
}
int gost89_get_asn1_parameters(EVP_CIPHER_CTX *ctx,ASN1_TYPE *params)
{
int ret = -1;
int len;
GOST_CIPHER_PARAMS *gcp = NULL;
unsigned char *p;
struct ossl_gost_cipher_ctx *c=ctx->cipher_data;
if (ASN1_TYPE_get(params) != V_ASN1_SEQUENCE)
{
return ret;
}
p = params->value.sequence->data;
gcp = d2i_GOST_CIPHER_PARAMS(NULL, (const unsigned char **)&p,
params->value.sequence->length);
len = gcp->iv->length;
if (len != ctx->cipher->iv_len)
{
GOST_CIPHER_PARAMS_free(gcp);
GOSTerr(GOST_F_GOST89_GET_ASN1_PARAMETERS,
GOST_R_INVALID_IV_LENGTH);
return -1;
}
if (!gost_cipher_set_param(c,OBJ_obj2nid(gcp->enc_param_set)))
{
GOST_CIPHER_PARAMS_free(gcp);
return -1;
}
memcpy(ctx->oiv, gcp->iv->data, len);
GOST_CIPHER_PARAMS_free(gcp);
return 1;
}
int gost_imit_init_cpa(EVP_MD_CTX *ctx)
{
struct ossl_gost_imit_ctx *c = ctx->md_data;
memset(c->buffer,0,sizeof(c->buffer));
memset(c->partial_block,0,sizeof(c->partial_block));
c->count = 0;
c->bytes_left=0;
c->key_meshing=1;
gost_init(&(c->cctx),&Gost28147_CryptoProParamSetA);
return 1;
}
static void mac_block_mesh(struct ossl_gost_imit_ctx *c,const unsigned char *data)
{
unsigned char buffer[8];
if (c->key_meshing&& c->count && c->count %1024 ==0)
{
cryptopro_key_meshing(&(c->cctx),buffer);
}
mac_block(&(c->cctx),c->buffer,data);
c->count +=8;
}
int gost_imit_update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
struct ossl_gost_imit_ctx *c = ctx->md_data;
const unsigned char *p = data;
size_t bytes = count,i;
if (!(c->key_set)) {
GOSTerr(GOST_F_GOST_IMIT_UPDATE, GOST_R_MAC_KEY_NOT_SET);
return 0;
}
if (c->bytes_left)
{
for (i=c->bytes_left;i<8&&bytes>0;bytes--,i++,p++)
{
c->partial_block[i]=*p;
}
if (i==8)
{
mac_block_mesh(c,c->partial_block);
}
else
{
c->bytes_left = i;
return 1;
}
}
while (bytes>8)
{
mac_block_mesh(c,p);
p+=8;
bytes-=8;
}
if (bytes>0)
{
memcpy(c->partial_block,p,bytes);
}
c->bytes_left=bytes;
return 1;
}
int gost_imit_final(EVP_MD_CTX *ctx,unsigned char *md)
{
struct ossl_gost_imit_ctx *c = ctx->md_data;
if (!c->key_set) {
GOSTerr(GOST_F_GOST_IMIT_FINAL, GOST_R_MAC_KEY_NOT_SET);
return 0;
}
if (c->bytes_left)
{
int i;
for (i=c->bytes_left;i<8;i++)
{
c->partial_block[i]=0;
}
mac_block_mesh(c,c->partial_block);
}
get_mac(c->buffer,32,md);
return 1;
}
int gost_imit_ctrl(EVP_MD_CTX *ctx,int type, int arg, void *ptr)
{
switch (type)
{
case EVP_MD_CTRL_KEY_LEN:
*((unsigned int*)(ptr)) = 32;
return 1;
case EVP_MD_CTRL_SET_KEY:
{
if (arg!=32) {
GOSTerr(GOST_F_GOST_IMIT_CTRL, GOST_R_INVALID_MAC_KEY_LENGTH);
return 0;
}
gost_key(&(((struct ossl_gost_imit_ctx*)(ctx->md_data))->cctx),ptr) ;
((struct ossl_gost_imit_ctx*)(ctx->md_data))->key_set = 1;
return 1;
}
default:
return 0;
}
}
int gost_imit_copy(EVP_MD_CTX *to,const EVP_MD_CTX *from)
{
memcpy(to->md_data,from->md_data,sizeof(struct ossl_gost_imit_ctx));
return 1;
}
int gost_imit_cleanup(EVP_MD_CTX *ctx)
{
memset(ctx->md_data,0,sizeof(struct ossl_gost_imit_ctx));
return 1;
}
