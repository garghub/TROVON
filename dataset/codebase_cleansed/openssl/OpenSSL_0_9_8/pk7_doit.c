static int PKCS7_type_is_other(PKCS7* p7)
{
int isOther=1;
int nid=OBJ_obj2nid(p7->type);
switch( nid )
{
case NID_pkcs7_data:
case NID_pkcs7_signed:
case NID_pkcs7_enveloped:
case NID_pkcs7_signedAndEnveloped:
case NID_pkcs7_digest:
case NID_pkcs7_encrypted:
isOther=0;
break;
default:
isOther=1;
}
return isOther;
}
static ASN1_OCTET_STRING *PKCS7_get_octet_string(PKCS7 *p7)
{
if ( PKCS7_type_is_data(p7))
return p7->d.data;
if ( PKCS7_type_is_other(p7) && p7->d.other
&& (p7->d.other->type == V_ASN1_OCTET_STRING))
return p7->d.other->value.octet_string;
return NULL;
}
static int PKCS7_bio_add_digest(BIO **pbio, X509_ALGOR *alg)
{
BIO *btmp;
const EVP_MD *md;
if ((btmp=BIO_new(BIO_f_md())) == NULL)
{
PKCS7err(PKCS7_F_PKCS7_BIO_ADD_DIGEST,ERR_R_BIO_LIB);
goto err;
}
md=EVP_get_digestbyobj(alg->algorithm);
if (md == NULL)
{
PKCS7err(PKCS7_F_PKCS7_BIO_ADD_DIGEST,PKCS7_R_UNKNOWN_DIGEST_TYPE);
goto err;
}
BIO_set_md(btmp,md);
if (*pbio == NULL)
*pbio=btmp;
else if (!BIO_push(*pbio,btmp))
{
PKCS7err(PKCS7_F_PKCS7_BIO_ADD_DIGEST,ERR_R_BIO_LIB);
goto err;
}
btmp=NULL;
return 1;
err:
if (btmp)
BIO_free(btmp);
return 0;
}
BIO *PKCS7_dataInit(PKCS7 *p7, BIO *bio)
{
int i;
BIO *out=NULL,*btmp=NULL;
X509_ALGOR *xa = NULL;
const EVP_CIPHER *evp_cipher=NULL;
STACK_OF(X509_ALGOR) *md_sk=NULL;
STACK_OF(PKCS7_RECIP_INFO) *rsk=NULL;
X509_ALGOR *xalg=NULL;
PKCS7_RECIP_INFO *ri=NULL;
EVP_PKEY *pkey;
ASN1_OCTET_STRING *os=NULL;
i=OBJ_obj2nid(p7->type);
p7->state=PKCS7_S_HEADER;
switch (i)
{
case NID_pkcs7_signed:
md_sk=p7->d.sign->md_algs;
os = PKCS7_get_octet_string(p7->d.sign->contents);
break;
case NID_pkcs7_signedAndEnveloped:
rsk=p7->d.signed_and_enveloped->recipientinfo;
md_sk=p7->d.signed_and_enveloped->md_algs;
xalg=p7->d.signed_and_enveloped->enc_data->algorithm;
evp_cipher=p7->d.signed_and_enveloped->enc_data->cipher;
if (evp_cipher == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATAINIT,
PKCS7_R_CIPHER_NOT_INITIALIZED);
goto err;
}
break;
case NID_pkcs7_enveloped:
rsk=p7->d.enveloped->recipientinfo;
xalg=p7->d.enveloped->enc_data->algorithm;
evp_cipher=p7->d.enveloped->enc_data->cipher;
if (evp_cipher == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATAINIT,
PKCS7_R_CIPHER_NOT_INITIALIZED);
goto err;
}
break;
case NID_pkcs7_digest:
xa = p7->d.digest->md;
os = PKCS7_get_octet_string(p7->d.digest->contents);
break;
default:
PKCS7err(PKCS7_F_PKCS7_DATAINIT,PKCS7_R_UNSUPPORTED_CONTENT_TYPE);
goto err;
}
for (i=0; i<sk_X509_ALGOR_num(md_sk); i++)
if (!PKCS7_bio_add_digest(&out, sk_X509_ALGOR_value(md_sk, i)))
goto err;
if (xa && !PKCS7_bio_add_digest(&out, xa))
goto err;
if (evp_cipher != NULL)
{
unsigned char key[EVP_MAX_KEY_LENGTH];
unsigned char iv[EVP_MAX_IV_LENGTH];
int keylen,ivlen;
int jj,max;
unsigned char *tmp;
EVP_CIPHER_CTX *ctx;
if ((btmp=BIO_new(BIO_f_cipher())) == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATAINIT,ERR_R_BIO_LIB);
goto err;
}
BIO_get_cipher_ctx(btmp, &ctx);
keylen=EVP_CIPHER_key_length(evp_cipher);
ivlen=EVP_CIPHER_iv_length(evp_cipher);
xalg->algorithm = OBJ_nid2obj(EVP_CIPHER_type(evp_cipher));
if (ivlen > 0) RAND_pseudo_bytes(iv,ivlen);
if (EVP_CipherInit_ex(ctx, evp_cipher, NULL, NULL, NULL, 1)<=0)
goto err;
if (EVP_CIPHER_CTX_rand_key(ctx, key) <= 0)
goto err;
if (EVP_CipherInit_ex(ctx, NULL, NULL, key, iv, 1) <= 0)
goto err;
if (ivlen > 0) {
if (xalg->parameter == NULL)
xalg->parameter=ASN1_TYPE_new();
if(EVP_CIPHER_param_to_asn1(ctx, xalg->parameter) < 0)
goto err;
}
max=0;
for (i=0; i<sk_PKCS7_RECIP_INFO_num(rsk); i++)
{
ri=sk_PKCS7_RECIP_INFO_value(rsk,i);
if (ri->cert == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATAINIT,PKCS7_R_MISSING_CERIPEND_INFO);
goto err;
}
pkey=X509_get_pubkey(ri->cert);
jj=EVP_PKEY_size(pkey);
EVP_PKEY_free(pkey);
if (max < jj) max=jj;
}
if ((tmp=(unsigned char *)OPENSSL_malloc(max)) == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATAINIT,ERR_R_MALLOC_FAILURE);
goto err;
}
for (i=0; i<sk_PKCS7_RECIP_INFO_num(rsk); i++)
{
ri=sk_PKCS7_RECIP_INFO_value(rsk,i);
pkey=X509_get_pubkey(ri->cert);
jj=EVP_PKEY_encrypt(tmp,key,keylen,pkey);
EVP_PKEY_free(pkey);
if (jj <= 0)
{
PKCS7err(PKCS7_F_PKCS7_DATAINIT,ERR_R_EVP_LIB);
OPENSSL_free(tmp);
goto err;
}
if (!M_ASN1_OCTET_STRING_set(ri->enc_key,tmp,jj))
{
PKCS7err(PKCS7_F_PKCS7_DATAINIT,
ERR_R_MALLOC_FAILURE);
OPENSSL_free(tmp);
goto err;
}
}
OPENSSL_free(tmp);
OPENSSL_cleanse(key, keylen);
if (out == NULL)
out=btmp;
else
BIO_push(out,btmp);
btmp=NULL;
}
if (bio == NULL)
{
if (PKCS7_is_detached(p7))
bio=BIO_new(BIO_s_null());
else if (os && os->length > 0)
bio = BIO_new_mem_buf(os->data, os->length);
if(bio == NULL)
{
bio=BIO_new(BIO_s_mem());
BIO_set_mem_eof_return(bio,0);
}
}
BIO_push(out,bio);
bio=NULL;
if (0)
{
err:
if (out != NULL)
BIO_free_all(out);
if (btmp != NULL)
BIO_free_all(btmp);
out=NULL;
}
return(out);
}
BIO *PKCS7_dataDecode(PKCS7 *p7, EVP_PKEY *pkey, BIO *in_bio, X509 *pcert)
{
int i,j;
BIO *out=NULL,*btmp=NULL,*etmp=NULL,*bio=NULL;
unsigned char *tmp=NULL;
X509_ALGOR *xa;
ASN1_OCTET_STRING *data_body=NULL;
const EVP_MD *evp_md;
const EVP_CIPHER *evp_cipher=NULL;
EVP_CIPHER_CTX *evp_ctx=NULL;
X509_ALGOR *enc_alg=NULL;
STACK_OF(X509_ALGOR) *md_sk=NULL;
STACK_OF(PKCS7_RECIP_INFO) *rsk=NULL;
X509_ALGOR *xalg=NULL;
PKCS7_RECIP_INFO *ri=NULL;
i=OBJ_obj2nid(p7->type);
p7->state=PKCS7_S_HEADER;
switch (i)
{
case NID_pkcs7_signed:
data_body=PKCS7_get_octet_string(p7->d.sign->contents);
md_sk=p7->d.sign->md_algs;
break;
case NID_pkcs7_signedAndEnveloped:
rsk=p7->d.signed_and_enveloped->recipientinfo;
md_sk=p7->d.signed_and_enveloped->md_algs;
data_body=p7->d.signed_and_enveloped->enc_data->enc_data;
enc_alg=p7->d.signed_and_enveloped->enc_data->algorithm;
evp_cipher=EVP_get_cipherbyobj(enc_alg->algorithm);
if (evp_cipher == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATADECODE,PKCS7_R_UNSUPPORTED_CIPHER_TYPE);
goto err;
}
xalg=p7->d.signed_and_enveloped->enc_data->algorithm;
break;
case NID_pkcs7_enveloped:
rsk=p7->d.enveloped->recipientinfo;
enc_alg=p7->d.enveloped->enc_data->algorithm;
data_body=p7->d.enveloped->enc_data->enc_data;
evp_cipher=EVP_get_cipherbyobj(enc_alg->algorithm);
if (evp_cipher == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATADECODE,PKCS7_R_UNSUPPORTED_CIPHER_TYPE);
goto err;
}
xalg=p7->d.enveloped->enc_data->algorithm;
break;
default:
PKCS7err(PKCS7_F_PKCS7_DATADECODE,PKCS7_R_UNSUPPORTED_CONTENT_TYPE);
goto err;
}
if (md_sk != NULL)
{
for (i=0; i<sk_X509_ALGOR_num(md_sk); i++)
{
xa=sk_X509_ALGOR_value(md_sk,i);
if ((btmp=BIO_new(BIO_f_md())) == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATADECODE,ERR_R_BIO_LIB);
goto err;
}
j=OBJ_obj2nid(xa->algorithm);
evp_md=EVP_get_digestbynid(j);
if (evp_md == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATADECODE,PKCS7_R_UNKNOWN_DIGEST_TYPE);
goto err;
}
BIO_set_md(btmp,evp_md);
if (out == NULL)
out=btmp;
else
BIO_push(out,btmp);
btmp=NULL;
}
}
if (evp_cipher != NULL)
{
#if 0
unsigned char key[EVP_MAX_KEY_LENGTH];
unsigned char iv[EVP_MAX_IV_LENGTH];
unsigned char *p;
int keylen,ivlen;
int max;
X509_OBJECT ret;
#endif
int jj;
if ((etmp=BIO_new(BIO_f_cipher())) == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATADECODE,ERR_R_BIO_LIB);
goto err;
}
for (i=0; i<sk_PKCS7_RECIP_INFO_num(rsk); i++) {
ri=sk_PKCS7_RECIP_INFO_value(rsk,i);
if(!X509_NAME_cmp(ri->issuer_and_serial->issuer,
pcert->cert_info->issuer) &&
!M_ASN1_INTEGER_cmp(pcert->cert_info->serialNumber,
ri->issuer_and_serial->serial)) break;
ri=NULL;
}
if (ri == NULL) {
PKCS7err(PKCS7_F_PKCS7_DATADECODE,
PKCS7_R_NO_RECIPIENT_MATCHES_CERTIFICATE);
goto err;
}
jj=EVP_PKEY_size(pkey);
tmp=(unsigned char *)OPENSSL_malloc(jj+10);
if (tmp == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATADECODE,ERR_R_MALLOC_FAILURE);
goto err;
}
jj=EVP_PKEY_decrypt(tmp, M_ASN1_STRING_data(ri->enc_key),
M_ASN1_STRING_length(ri->enc_key), pkey);
if (jj <= 0)
{
PKCS7err(PKCS7_F_PKCS7_DATADECODE,ERR_R_EVP_LIB);
goto err;
}
evp_ctx=NULL;
BIO_get_cipher_ctx(etmp,&evp_ctx);
if (EVP_CipherInit_ex(evp_ctx,evp_cipher,NULL,NULL,NULL,0) <= 0)
goto err;
if (EVP_CIPHER_asn1_to_param(evp_ctx,enc_alg->parameter) < 0)
goto err;
if (jj != EVP_CIPHER_CTX_key_length(evp_ctx)) {
if(!EVP_CIPHER_CTX_set_key_length(evp_ctx, jj))
{
PKCS7err(PKCS7_F_PKCS7_DATADECODE,
PKCS7_R_DECRYPTED_KEY_IS_WRONG_LENGTH);
goto err;
}
}
if (EVP_CipherInit_ex(evp_ctx,NULL,NULL,tmp,NULL,0) <= 0)
goto err;
OPENSSL_cleanse(tmp,jj);
if (out == NULL)
out=etmp;
else
BIO_push(out,etmp);
etmp=NULL;
}
#if 1
if (PKCS7_is_detached(p7) || (in_bio != NULL))
{
bio=in_bio;
}
else
{
#if 0
bio=BIO_new(BIO_s_mem());
BIO_set_mem_eof_return(bio,0);
if (data_body->length > 0)
BIO_write(bio,(char *)data_body->data,data_body->length);
#else
if (data_body->length > 0)
bio = BIO_new_mem_buf(data_body->data,data_body->length);
else {
bio=BIO_new(BIO_s_mem());
BIO_set_mem_eof_return(bio,0);
}
#endif
}
BIO_push(out,bio);
bio=NULL;
#endif
if (0)
{
err:
if (out != NULL) BIO_free_all(out);
if (btmp != NULL) BIO_free_all(btmp);
if (etmp != NULL) BIO_free_all(etmp);
if (bio != NULL) BIO_free_all(bio);
out=NULL;
}
if (tmp != NULL)
OPENSSL_free(tmp);
return(out);
}
static BIO *PKCS7_find_digest(EVP_MD_CTX **pmd, BIO *bio, int nid)
{
for (;;)
{
bio=BIO_find_type(bio,BIO_TYPE_MD);
if (bio == NULL)
{
PKCS7err(PKCS7_F_PKCS7_FIND_DIGEST,PKCS7_R_UNABLE_TO_FIND_MESSAGE_DIGEST);
return NULL;
}
BIO_get_md_ctx(bio,pmd);
if (*pmd == NULL)
{
PKCS7err(PKCS7_F_PKCS7_FIND_DIGEST,ERR_R_INTERNAL_ERROR);
return NULL;
}
if (EVP_MD_CTX_type(*pmd) == nid)
return bio;
bio=BIO_next(bio);
}
return NULL;
}
int PKCS7_dataFinal(PKCS7 *p7, BIO *bio)
{
int ret=0;
int i,j;
BIO *btmp;
BUF_MEM *buf_mem=NULL;
BUF_MEM *buf=NULL;
PKCS7_SIGNER_INFO *si;
EVP_MD_CTX *mdc,ctx_tmp;
STACK_OF(X509_ATTRIBUTE) *sk;
STACK_OF(PKCS7_SIGNER_INFO) *si_sk=NULL;
ASN1_OCTET_STRING *os=NULL;
EVP_MD_CTX_init(&ctx_tmp);
i=OBJ_obj2nid(p7->type);
p7->state=PKCS7_S_HEADER;
switch (i)
{
case NID_pkcs7_signedAndEnveloped:
si_sk=p7->d.signed_and_enveloped->signer_info;
if (!(os=M_ASN1_OCTET_STRING_new()))
{
PKCS7err(PKCS7_F_PKCS7_DATAFINAL,ERR_R_MALLOC_FAILURE);
goto err;
}
p7->d.signed_and_enveloped->enc_data->enc_data=os;
break;
case NID_pkcs7_enveloped:
if (!(os=M_ASN1_OCTET_STRING_new()))
{
PKCS7err(PKCS7_F_PKCS7_DATAFINAL,ERR_R_MALLOC_FAILURE);
goto err;
}
p7->d.enveloped->enc_data->enc_data=os;
break;
case NID_pkcs7_signed:
si_sk=p7->d.sign->signer_info;
os=PKCS7_get_octet_string(p7->d.sign->contents);
if(PKCS7_type_is_data(p7->d.sign->contents) && p7->detached) {
M_ASN1_OCTET_STRING_free(os);
p7->d.sign->contents->d.data = NULL;
}
break;
case NID_pkcs7_digest:
os=PKCS7_get_octet_string(p7->d.digest->contents);
if(PKCS7_type_is_data(p7->d.digest->contents) && p7->detached)
{
M_ASN1_OCTET_STRING_free(os);
p7->d.digest->contents->d.data = NULL;
}
break;
}
if (si_sk != NULL)
{
if ((buf=BUF_MEM_new()) == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATAFINAL,ERR_R_BIO_LIB);
goto err;
}
for (i=0; i<sk_PKCS7_SIGNER_INFO_num(si_sk); i++)
{
si=sk_PKCS7_SIGNER_INFO_value(si_sk,i);
if (si->pkey == NULL) continue;
j=OBJ_obj2nid(si->digest_alg->algorithm);
btmp=bio;
btmp = PKCS7_find_digest(&mdc, btmp, j);
if (btmp == NULL)
goto err;
EVP_MD_CTX_copy_ex(&ctx_tmp,mdc);
if (!BUF_MEM_grow_clean(buf,EVP_PKEY_size(si->pkey)))
{
PKCS7err(PKCS7_F_PKCS7_DATAFINAL,ERR_R_BIO_LIB);
goto err;
}
sk=si->auth_attr;
if ((sk != NULL) && (sk_X509_ATTRIBUTE_num(sk) != 0))
{
unsigned char md_data[EVP_MAX_MD_SIZE], *abuf=NULL;
unsigned int md_len, alen;
ASN1_OCTET_STRING *digest;
ASN1_UTCTIME *sign_time;
const EVP_MD *md_tmp;
if (!PKCS7_get_signed_attribute(si,
NID_pkcs9_signingTime))
{
if (!(sign_time=X509_gmtime_adj(NULL,0)))
{
PKCS7err(PKCS7_F_PKCS7_DATAFINAL,
ERR_R_MALLOC_FAILURE);
goto err;
}
PKCS7_add_signed_attribute(si,
NID_pkcs9_signingTime,
V_ASN1_UTCTIME,sign_time);
}
md_tmp=EVP_MD_CTX_md(&ctx_tmp);
EVP_DigestFinal_ex(&ctx_tmp,md_data,&md_len);
if (!(digest=M_ASN1_OCTET_STRING_new()))
{
PKCS7err(PKCS7_F_PKCS7_DATAFINAL,
ERR_R_MALLOC_FAILURE);
goto err;
}
if (!M_ASN1_OCTET_STRING_set(digest,md_data,
md_len))
{
PKCS7err(PKCS7_F_PKCS7_DATAFINAL,
ERR_R_MALLOC_FAILURE);
goto err;
}
PKCS7_add_signed_attribute(si,
NID_pkcs9_messageDigest,
V_ASN1_OCTET_STRING,digest);
EVP_SignInit_ex(&ctx_tmp,md_tmp,NULL);
alen = ASN1_item_i2d((ASN1_VALUE *)sk,&abuf,
ASN1_ITEM_rptr(PKCS7_ATTR_SIGN));
if(!abuf) goto err;
EVP_SignUpdate(&ctx_tmp,abuf,alen);
OPENSSL_free(abuf);
}
#ifndef OPENSSL_NO_DSA
if (si->pkey->type == EVP_PKEY_DSA)
ctx_tmp.digest=EVP_dss1();
#endif
#ifndef OPENSSL_NO_ECDSA
if (si->pkey->type == EVP_PKEY_EC)
ctx_tmp.digest=EVP_ecdsa();
#endif
if (!EVP_SignFinal(&ctx_tmp,(unsigned char *)buf->data,
(unsigned int *)&buf->length,si->pkey))
{
PKCS7err(PKCS7_F_PKCS7_DATAFINAL,ERR_R_EVP_LIB);
goto err;
}
if (!ASN1_STRING_set(si->enc_digest,
(unsigned char *)buf->data,buf->length))
{
PKCS7err(PKCS7_F_PKCS7_DATAFINAL,ERR_R_ASN1_LIB);
goto err;
}
}
}
else if (i == NID_pkcs7_digest)
{
unsigned char md_data[EVP_MAX_MD_SIZE];
unsigned int md_len;
if (!PKCS7_find_digest(&mdc, bio,
OBJ_obj2nid(p7->d.digest->md->algorithm)))
goto err;
EVP_DigestFinal_ex(mdc,md_data,&md_len);
M_ASN1_OCTET_STRING_set(p7->d.digest->digest, md_data, md_len);
}
if (!PKCS7_is_detached(p7))
{
btmp=BIO_find_type(bio,BIO_TYPE_MEM);
if (btmp == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATAFINAL,PKCS7_R_UNABLE_TO_FIND_MEM_BIO);
goto err;
}
BIO_get_mem_ptr(btmp,&buf_mem);
BIO_set_flags(btmp, BIO_FLAGS_MEM_RDONLY);
BIO_set_mem_eof_return(btmp, 0);
os->data = (unsigned char *)buf_mem->data;
os->length = buf_mem->length;
#if 0
M_ASN1_OCTET_STRING_set(os,
(unsigned char *)buf_mem->data,buf_mem->length);
#endif
}
ret=1;
err:
EVP_MD_CTX_cleanup(&ctx_tmp);
if (buf != NULL) BUF_MEM_free(buf);
return(ret);
}
int PKCS7_dataVerify(X509_STORE *cert_store, X509_STORE_CTX *ctx, BIO *bio,
PKCS7 *p7, PKCS7_SIGNER_INFO *si)
{
PKCS7_ISSUER_AND_SERIAL *ias;
int ret=0,i;
STACK_OF(X509) *cert;
X509 *x509;
if (PKCS7_type_is_signed(p7))
{
cert=p7->d.sign->cert;
}
else if (PKCS7_type_is_signedAndEnveloped(p7))
{
cert=p7->d.signed_and_enveloped->cert;
}
else
{
PKCS7err(PKCS7_F_PKCS7_DATAVERIFY,PKCS7_R_WRONG_PKCS7_TYPE);
goto err;
}
ias=si->issuer_and_serial;
x509=X509_find_by_issuer_and_serial(cert,ias->issuer,ias->serial);
if (x509 == NULL)
{
PKCS7err(PKCS7_F_PKCS7_DATAVERIFY,PKCS7_R_UNABLE_TO_FIND_CERTIFICATE);
goto err;
}
if(!X509_STORE_CTX_init(ctx,cert_store,x509,cert))
{
PKCS7err(PKCS7_F_PKCS7_DATAVERIFY,ERR_R_X509_LIB);
goto err;
}
X509_STORE_CTX_set_purpose(ctx, X509_PURPOSE_SMIME_SIGN);
i=X509_verify_cert(ctx);
if (i <= 0)
{
PKCS7err(PKCS7_F_PKCS7_DATAVERIFY,ERR_R_X509_LIB);
X509_STORE_CTX_cleanup(ctx);
goto err;
}
X509_STORE_CTX_cleanup(ctx);
return PKCS7_signatureVerify(bio, p7, si, x509);
err:
return ret;
}
int PKCS7_signatureVerify(BIO *bio, PKCS7 *p7, PKCS7_SIGNER_INFO *si,
X509 *x509)
{
ASN1_OCTET_STRING *os;
EVP_MD_CTX mdc_tmp,*mdc;
int ret=0,i;
int md_type;
STACK_OF(X509_ATTRIBUTE) *sk;
BIO *btmp;
EVP_PKEY *pkey;
EVP_MD_CTX_init(&mdc_tmp);
if (!PKCS7_type_is_signed(p7) &&
!PKCS7_type_is_signedAndEnveloped(p7)) {
PKCS7err(PKCS7_F_PKCS7_SIGNATUREVERIFY,
PKCS7_R_WRONG_PKCS7_TYPE);
goto err;
}
md_type=OBJ_obj2nid(si->digest_alg->algorithm);
btmp=bio;
for (;;)
{
if ((btmp == NULL) ||
((btmp=BIO_find_type(btmp,BIO_TYPE_MD)) == NULL))
{
PKCS7err(PKCS7_F_PKCS7_SIGNATUREVERIFY,
PKCS7_R_UNABLE_TO_FIND_MESSAGE_DIGEST);
goto err;
}
BIO_get_md_ctx(btmp,&mdc);
if (mdc == NULL)
{
PKCS7err(PKCS7_F_PKCS7_SIGNATUREVERIFY,
ERR_R_INTERNAL_ERROR);
goto err;
}
if (EVP_MD_CTX_type(mdc) == md_type)
break;
if (EVP_MD_pkey_type(EVP_MD_CTX_md(mdc)) == md_type)
break;
btmp=BIO_next(btmp);
}
EVP_MD_CTX_copy_ex(&mdc_tmp,mdc);
sk=si->auth_attr;
if ((sk != NULL) && (sk_X509_ATTRIBUTE_num(sk) != 0))
{
unsigned char md_dat[EVP_MAX_MD_SIZE], *abuf = NULL;
unsigned int md_len, alen;
ASN1_OCTET_STRING *message_digest;
EVP_DigestFinal_ex(&mdc_tmp,md_dat,&md_len);
message_digest=PKCS7_digest_from_attributes(sk);
if (!message_digest)
{
PKCS7err(PKCS7_F_PKCS7_SIGNATUREVERIFY,
PKCS7_R_UNABLE_TO_FIND_MESSAGE_DIGEST);
goto err;
}
if ((message_digest->length != (int)md_len) ||
(memcmp(message_digest->data,md_dat,md_len)))
{
#if 0
{
int ii;
for (ii=0; ii<message_digest->length; ii++)
printf("%02X",message_digest->data[ii]); printf(" sent\n");
for (ii=0; ii<md_len; ii++) printf("%02X",md_dat[ii]); printf(" calc\n");
}
#endif
PKCS7err(PKCS7_F_PKCS7_SIGNATUREVERIFY,
PKCS7_R_DIGEST_FAILURE);
ret= -1;
goto err;
}
EVP_VerifyInit_ex(&mdc_tmp,EVP_get_digestbynid(md_type), NULL);
alen = ASN1_item_i2d((ASN1_VALUE *)sk, &abuf,
ASN1_ITEM_rptr(PKCS7_ATTR_VERIFY));
EVP_VerifyUpdate(&mdc_tmp, abuf, alen);
OPENSSL_free(abuf);
}
os=si->enc_digest;
pkey = X509_get_pubkey(x509);
if (!pkey)
{
ret = -1;
goto err;
}
#ifndef OPENSSL_NO_DSA
if(pkey->type == EVP_PKEY_DSA) mdc_tmp.digest=EVP_dss1();
#endif
#ifndef OPENSSL_NO_ECDSA
if (pkey->type == EVP_PKEY_EC) mdc_tmp.digest=EVP_ecdsa();
#endif
i=EVP_VerifyFinal(&mdc_tmp,os->data,os->length, pkey);
EVP_PKEY_free(pkey);
if (i <= 0)
{
PKCS7err(PKCS7_F_PKCS7_SIGNATUREVERIFY,
PKCS7_R_SIGNATURE_FAILURE);
ret= -1;
goto err;
}
else
ret=1;
err:
EVP_MD_CTX_cleanup(&mdc_tmp);
return(ret);
}
PKCS7_ISSUER_AND_SERIAL *PKCS7_get_issuer_and_serial(PKCS7 *p7, int idx)
{
STACK_OF(PKCS7_RECIP_INFO) *rsk;
PKCS7_RECIP_INFO *ri;
int i;
i=OBJ_obj2nid(p7->type);
if (i != NID_pkcs7_signedAndEnveloped) return(NULL);
rsk=p7->d.signed_and_enveloped->recipientinfo;
ri=sk_PKCS7_RECIP_INFO_value(rsk,0);
if (sk_PKCS7_RECIP_INFO_num(rsk) <= idx) return(NULL);
ri=sk_PKCS7_RECIP_INFO_value(rsk,idx);
return(ri->issuer_and_serial);
}
ASN1_TYPE *PKCS7_get_signed_attribute(PKCS7_SIGNER_INFO *si, int nid)
{
return(get_attribute(si->auth_attr,nid));
}
ASN1_TYPE *PKCS7_get_attribute(PKCS7_SIGNER_INFO *si, int nid)
{
return(get_attribute(si->unauth_attr,nid));
}
int PKCS7_add_signed_attribute(PKCS7_SIGNER_INFO *p7si, int nid, int atrtype,
void *value)
{
return(add_attribute(&(p7si->auth_attr),nid,atrtype,value));
}
int PKCS7_add_attribute(PKCS7_SIGNER_INFO *p7si, int nid, int atrtype,
void *value)
{
return(add_attribute(&(p7si->unauth_attr),nid,atrtype,value));
}
