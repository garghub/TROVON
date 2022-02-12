int X509_issuer_and_serial_cmp(const X509 *a, const X509 *b)
{
int i;
X509_CINF *ai,*bi;
ai=a->cert_info;
bi=b->cert_info;
i=M_ASN1_INTEGER_cmp(ai->serialNumber,bi->serialNumber);
if (i) return(i);
return(X509_NAME_cmp(ai->issuer,bi->issuer));
}
unsigned long X509_issuer_and_serial_hash(X509 *a)
{
unsigned long ret=0;
EVP_MD_CTX ctx;
unsigned char md[16];
char *f;
EVP_MD_CTX_init(&ctx);
f=X509_NAME_oneline(a->cert_info->issuer,NULL,0);
ret=strlen(f);
EVP_DigestInit_ex(&ctx, EVP_md5(), NULL);
EVP_DigestUpdate(&ctx,(unsigned char *)f,ret);
OPENSSL_free(f);
EVP_DigestUpdate(&ctx,(unsigned char *)a->cert_info->serialNumber->data,
(unsigned long)a->cert_info->serialNumber->length);
EVP_DigestFinal_ex(&ctx,&(md[0]),NULL);
ret=( ((unsigned long)md[0] )|((unsigned long)md[1]<<8L)|
((unsigned long)md[2]<<16L)|((unsigned long)md[3]<<24L)
)&0xffffffffL;
EVP_MD_CTX_cleanup(&ctx);
return(ret);
}
int X509_issuer_name_cmp(const X509 *a, const X509 *b)
{
return(X509_NAME_cmp(a->cert_info->issuer,b->cert_info->issuer));
}
int X509_subject_name_cmp(const X509 *a, const X509 *b)
{
return(X509_NAME_cmp(a->cert_info->subject,b->cert_info->subject));
}
int X509_CRL_cmp(const X509_CRL *a, const X509_CRL *b)
{
return(X509_NAME_cmp(a->crl->issuer,b->crl->issuer));
}
int X509_CRL_match(const X509_CRL *a, const X509_CRL *b)
{
return memcmp(a->sha1_hash, b->sha1_hash, 20);
}
X509_NAME *X509_get_issuer_name(X509 *a)
{
return(a->cert_info->issuer);
}
unsigned long X509_issuer_name_hash(X509 *x)
{
return(X509_NAME_hash(x->cert_info->issuer));
}
unsigned long X509_issuer_name_hash_old(X509 *x)
{
return(X509_NAME_hash_old(x->cert_info->issuer));
}
X509_NAME *X509_get_subject_name(X509 *a)
{
return(a->cert_info->subject);
}
ASN1_INTEGER *X509_get_serialNumber(X509 *a)
{
return(a->cert_info->serialNumber);
}
unsigned long X509_subject_name_hash(X509 *x)
{
return(X509_NAME_hash(x->cert_info->subject));
}
unsigned long X509_subject_name_hash_old(X509 *x)
{
return(X509_NAME_hash_old(x->cert_info->subject));
}
int X509_cmp(const X509 *a, const X509 *b)
{
X509_check_purpose((X509 *)a, -1, 0);
X509_check_purpose((X509 *)b, -1, 0);
return memcmp(a->sha1_hash, b->sha1_hash, SHA_DIGEST_LENGTH);
}
int X509_NAME_cmp(const X509_NAME *a, const X509_NAME *b)
{
int ret;
if (!a->canon_enc || a->modified)
{
ret = i2d_X509_NAME((X509_NAME *)a, NULL);
if (ret < 0)
return -2;
}
if (!b->canon_enc || b->modified)
{
ret = i2d_X509_NAME((X509_NAME *)b, NULL);
if (ret < 0)
return -2;
}
ret = a->canon_enclen - b->canon_enclen;
if (ret)
return ret;
return memcmp(a->canon_enc, b->canon_enc, a->canon_enclen);
}
unsigned long X509_NAME_hash(X509_NAME *x)
{
unsigned long ret=0;
unsigned char md[SHA_DIGEST_LENGTH];
i2d_X509_NAME(x,NULL);
EVP_Digest(x->canon_enc, x->canon_enclen, md, NULL, EVP_sha1(), NULL);
ret=( ((unsigned long)md[0] )|((unsigned long)md[1]<<8L)|
((unsigned long)md[2]<<16L)|((unsigned long)md[3]<<24L)
)&0xffffffffL;
return(ret);
}
unsigned long X509_NAME_hash_old(X509_NAME *x)
{
unsigned long ret=0;
unsigned char md[16];
i2d_X509_NAME(x,NULL);
EVP_Digest(x->bytes->data, x->bytes->length, md, NULL, EVP_md5(), NULL);
ret=( ((unsigned long)md[0] )|((unsigned long)md[1]<<8L)|
((unsigned long)md[2]<<16L)|((unsigned long)md[3]<<24L)
)&0xffffffffL;
return(ret);
}
EVP_PKEY *X509_get_pubkey(X509 *x)
{
if ((x == NULL) || (x->cert_info == NULL))
return(NULL);
return(X509_PUBKEY_get(x->cert_info->key));
}
ASN1_BIT_STRING *X509_get0_pubkey_bitstr(const X509 *x)
{
if(!x) return NULL;
return x->cert_info->key->public_key;
}
int X509_check_private_key(X509 *x, EVP_PKEY *k)
{
EVP_PKEY *xk;
int ret;
xk=X509_get_pubkey(x);
if (xk)
ret = EVP_PKEY_cmp(xk, k);
else
ret = -2;
switch (ret)
{
case 1:
break;
case 0:
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_KEY_VALUES_MISMATCH);
break;
case -1:
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_KEY_TYPE_MISMATCH);
break;
case -2:
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_UNKNOWN_KEY_TYPE);
}
if (xk)
EVP_PKEY_free(xk);
if (ret > 0)
return 1;
return 0;
}
