EVP_CIPHER *EVP_rc2_cbc(void)
{
return(&r2_cbc_cipher);
}
EVP_CIPHER *EVP_rc2_64_cbc(void)
{
return(&r2_64_cbc_cipher);
}
EVP_CIPHER *EVP_rc2_40_cbc(void)
{
return(&r2_40_cbc_cipher);
}
static void rc2_cbc_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (key != NULL)
RC2_set_key(&(ctx->c.rc2_ks),EVP_CIPHER_CTX_key_length(ctx),
key,EVP_CIPHER_CTX_key_length(ctx)*8);
}
static void rc2_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
RC2_cbc_encrypt(
in,out,(long)inl,
&(ctx->c.rc2_ks),&(ctx->iv[0]),
ctx->encrypt);
}
static int rc2_meth_to_magic(const EVP_CIPHER *e)
{
int i;
i=EVP_CIPHER_key_length(e);
if (i == 16) return(RC2_128_MAGIC);
else if (i == 8) return(RC2_64_MAGIC);
else if (i == 5) return(RC2_40_MAGIC);
else return(0);
}
static EVP_CIPHER *rc2_magic_to_meth(int i)
{
if (i == RC2_128_MAGIC) return(EVP_rc2_cbc());
else if (i == RC2_64_MAGIC) return(EVP_rc2_64_cbc());
else if (i == RC2_40_MAGIC) return(EVP_rc2_40_cbc());
else
{
EVPerr(EVP_F_RC2_MAGIC_TO_METH,EVP_R_UNSUPPORTED_KEY_SIZE);
return(NULL);
}
}
static int rc2_get_asn1_type_and_iv(EVP_CIPHER_CTX *c, ASN1_TYPE *type)
{
long num=0;
int i=0,l;
EVP_CIPHER *e;
if (type != NULL)
{
l=EVP_CIPHER_CTX_iv_length(c);
i=ASN1_TYPE_get_int_octetstring(type,&num,c->oiv,l);
if (i != l)
return(-1);
else if (i > 0)
memcpy(c->iv,c->oiv,l);
e=rc2_magic_to_meth((int)num);
if (e == NULL)
return(-1);
if (e != EVP_CIPHER_CTX_cipher(c))
{
EVP_CIPHER_CTX_cipher(c)=e;
rc2_cbc_init_key(c,NULL,NULL,1);
}
}
return(i);
}
static int rc2_set_asn1_type_and_iv(EVP_CIPHER_CTX *c, ASN1_TYPE *type)
{
long num;
int i=0,j;
if (type != NULL)
{
num=rc2_meth_to_magic(EVP_CIPHER_CTX_cipher(c));
j=EVP_CIPHER_CTX_iv_length(c);
i=ASN1_TYPE_set_int_octetstring(type,num,c->oiv,j);
}
return(i);
}
