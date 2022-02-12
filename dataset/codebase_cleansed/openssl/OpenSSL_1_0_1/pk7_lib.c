long PKCS7_ctrl(PKCS7 *p7, int cmd, long larg, char *parg)
{
int nid;
long ret;
nid=OBJ_obj2nid(p7->type);
switch (cmd)
{
case PKCS7_OP_SET_DETACHED_SIGNATURE:
if (nid == NID_pkcs7_signed)
{
ret=p7->detached=(int)larg;
if (ret && PKCS7_type_is_data(p7->d.sign->contents))
{
ASN1_OCTET_STRING *os;
os=p7->d.sign->contents->d.data;
ASN1_OCTET_STRING_free(os);
p7->d.sign->contents->d.data = NULL;
}
}
else
{
PKCS7err(PKCS7_F_PKCS7_CTRL,PKCS7_R_OPERATION_NOT_SUPPORTED_ON_THIS_TYPE);
ret=0;
}
break;
case PKCS7_OP_GET_DETACHED_SIGNATURE:
if (nid == NID_pkcs7_signed)
{
if(!p7->d.sign || !p7->d.sign->contents->d.ptr)
ret = 1;
else ret = 0;
p7->detached = ret;
}
else
{
PKCS7err(PKCS7_F_PKCS7_CTRL,PKCS7_R_OPERATION_NOT_SUPPORTED_ON_THIS_TYPE);
ret=0;
}
break;
default:
PKCS7err(PKCS7_F_PKCS7_CTRL,PKCS7_R_UNKNOWN_OPERATION);
ret=0;
}
return(ret);
}
int PKCS7_content_new(PKCS7 *p7, int type)
{
PKCS7 *ret=NULL;
if ((ret=PKCS7_new()) == NULL) goto err;
if (!PKCS7_set_type(ret,type)) goto err;
if (!PKCS7_set_content(p7,ret)) goto err;
return(1);
err:
if (ret != NULL) PKCS7_free(ret);
return(0);
}
int PKCS7_set_content(PKCS7 *p7, PKCS7 *p7_data)
{
int i;
i=OBJ_obj2nid(p7->type);
switch (i)
{
case NID_pkcs7_signed:
if (p7->d.sign->contents != NULL)
PKCS7_free(p7->d.sign->contents);
p7->d.sign->contents=p7_data;
break;
case NID_pkcs7_digest:
if (p7->d.digest->contents != NULL)
PKCS7_free(p7->d.digest->contents);
p7->d.digest->contents=p7_data;
break;
case NID_pkcs7_data:
case NID_pkcs7_enveloped:
case NID_pkcs7_signedAndEnveloped:
case NID_pkcs7_encrypted:
default:
PKCS7err(PKCS7_F_PKCS7_SET_CONTENT,PKCS7_R_UNSUPPORTED_CONTENT_TYPE);
goto err;
}
return(1);
err:
return(0);
}
int PKCS7_set_type(PKCS7 *p7, int type)
{
ASN1_OBJECT *obj;
obj=OBJ_nid2obj(type);
switch (type)
{
case NID_pkcs7_signed:
p7->type=obj;
if ((p7->d.sign=PKCS7_SIGNED_new()) == NULL)
goto err;
if (!ASN1_INTEGER_set(p7->d.sign->version,1))
{
PKCS7_SIGNED_free(p7->d.sign);
p7->d.sign=NULL;
goto err;
}
break;
case NID_pkcs7_data:
p7->type=obj;
if ((p7->d.data=M_ASN1_OCTET_STRING_new()) == NULL)
goto err;
break;
case NID_pkcs7_signedAndEnveloped:
p7->type=obj;
if ((p7->d.signed_and_enveloped=PKCS7_SIGN_ENVELOPE_new())
== NULL) goto err;
ASN1_INTEGER_set(p7->d.signed_and_enveloped->version,1);
if (!ASN1_INTEGER_set(p7->d.signed_and_enveloped->version,1))
goto err;
p7->d.signed_and_enveloped->enc_data->content_type
= OBJ_nid2obj(NID_pkcs7_data);
break;
case NID_pkcs7_enveloped:
p7->type=obj;
if ((p7->d.enveloped=PKCS7_ENVELOPE_new())
== NULL) goto err;
if (!ASN1_INTEGER_set(p7->d.enveloped->version,0))
goto err;
p7->d.enveloped->enc_data->content_type
= OBJ_nid2obj(NID_pkcs7_data);
break;
case NID_pkcs7_encrypted:
p7->type=obj;
if ((p7->d.encrypted=PKCS7_ENCRYPT_new())
== NULL) goto err;
if (!ASN1_INTEGER_set(p7->d.encrypted->version,0))
goto err;
p7->d.encrypted->enc_data->content_type
= OBJ_nid2obj(NID_pkcs7_data);
break;
case NID_pkcs7_digest:
p7->type=obj;
if ((p7->d.digest=PKCS7_DIGEST_new())
== NULL) goto err;
if (!ASN1_INTEGER_set(p7->d.digest->version,0))
goto err;
break;
default:
PKCS7err(PKCS7_F_PKCS7_SET_TYPE,PKCS7_R_UNSUPPORTED_CONTENT_TYPE);
goto err;
}
return(1);
err:
return(0);
}
int PKCS7_set0_type_other(PKCS7 *p7, int type, ASN1_TYPE *other)
{
p7->type = OBJ_nid2obj(type);
p7->d.other = other;
return 1;
}
int PKCS7_add_signer(PKCS7 *p7, PKCS7_SIGNER_INFO *psi)
{
int i,j,nid;
X509_ALGOR *alg;
STACK_OF(PKCS7_SIGNER_INFO) *signer_sk;
STACK_OF(X509_ALGOR) *md_sk;
i=OBJ_obj2nid(p7->type);
switch (i)
{
case NID_pkcs7_signed:
signer_sk= p7->d.sign->signer_info;
md_sk= p7->d.sign->md_algs;
break;
case NID_pkcs7_signedAndEnveloped:
signer_sk= p7->d.signed_and_enveloped->signer_info;
md_sk= p7->d.signed_and_enveloped->md_algs;
break;
default:
PKCS7err(PKCS7_F_PKCS7_ADD_SIGNER,PKCS7_R_WRONG_CONTENT_TYPE);
return(0);
}
nid=OBJ_obj2nid(psi->digest_alg->algorithm);
j=0;
for (i=0; i<sk_X509_ALGOR_num(md_sk); i++)
{
alg=sk_X509_ALGOR_value(md_sk,i);
if (OBJ_obj2nid(alg->algorithm) == nid)
{
j=1;
break;
}
}
if (!j)
{
if(!(alg=X509_ALGOR_new())
|| !(alg->parameter = ASN1_TYPE_new()))
{
X509_ALGOR_free(alg);
PKCS7err(PKCS7_F_PKCS7_ADD_SIGNER,ERR_R_MALLOC_FAILURE);
return(0);
}
alg->algorithm=OBJ_nid2obj(nid);
alg->parameter->type = V_ASN1_NULL;
if (!sk_X509_ALGOR_push(md_sk,alg))
{
X509_ALGOR_free(alg);
return 0;
}
}
if (!sk_PKCS7_SIGNER_INFO_push(signer_sk,psi))
return 0;
return(1);
}
int PKCS7_add_certificate(PKCS7 *p7, X509 *x509)
{
int i;
STACK_OF(X509) **sk;
i=OBJ_obj2nid(p7->type);
switch (i)
{
case NID_pkcs7_signed:
sk= &(p7->d.sign->cert);
break;
case NID_pkcs7_signedAndEnveloped:
sk= &(p7->d.signed_and_enveloped->cert);
break;
default:
PKCS7err(PKCS7_F_PKCS7_ADD_CERTIFICATE,PKCS7_R_WRONG_CONTENT_TYPE);
return(0);
}
if (*sk == NULL)
*sk=sk_X509_new_null();
if (*sk == NULL)
{
PKCS7err(PKCS7_F_PKCS7_ADD_CERTIFICATE, ERR_R_MALLOC_FAILURE);
return 0;
}
CRYPTO_add(&x509->references,1,CRYPTO_LOCK_X509);
if (!sk_X509_push(*sk,x509))
{
X509_free(x509);
return 0;
}
return(1);
}
int PKCS7_add_crl(PKCS7 *p7, X509_CRL *crl)
{
int i;
STACK_OF(X509_CRL) **sk;
i=OBJ_obj2nid(p7->type);
switch (i)
{
case NID_pkcs7_signed:
sk= &(p7->d.sign->crl);
break;
case NID_pkcs7_signedAndEnveloped:
sk= &(p7->d.signed_and_enveloped->crl);
break;
default:
PKCS7err(PKCS7_F_PKCS7_ADD_CRL,PKCS7_R_WRONG_CONTENT_TYPE);
return(0);
}
if (*sk == NULL)
*sk=sk_X509_CRL_new_null();
if (*sk == NULL)
{
PKCS7err(PKCS7_F_PKCS7_ADD_CRL,ERR_R_MALLOC_FAILURE);
return 0;
}
CRYPTO_add(&crl->references,1,CRYPTO_LOCK_X509_CRL);
if (!sk_X509_CRL_push(*sk,crl))
{
X509_CRL_free(crl);
return 0;
}
return(1);
}
int PKCS7_SIGNER_INFO_set(PKCS7_SIGNER_INFO *p7i, X509 *x509, EVP_PKEY *pkey,
const EVP_MD *dgst)
{
int ret;
if (!ASN1_INTEGER_set(p7i->version,1))
goto err;
if (!X509_NAME_set(&p7i->issuer_and_serial->issuer,
X509_get_issuer_name(x509)))
goto err;
M_ASN1_INTEGER_free(p7i->issuer_and_serial->serial);
if (!(p7i->issuer_and_serial->serial=
M_ASN1_INTEGER_dup(X509_get_serialNumber(x509))))
goto err;
CRYPTO_add(&pkey->references,1,CRYPTO_LOCK_EVP_PKEY);
p7i->pkey=pkey;
X509_ALGOR_set0(p7i->digest_alg, OBJ_nid2obj(EVP_MD_type(dgst)),
V_ASN1_NULL, NULL);
if (pkey->ameth && pkey->ameth->pkey_ctrl)
{
ret = pkey->ameth->pkey_ctrl(pkey, ASN1_PKEY_CTRL_PKCS7_SIGN,
0, p7i);
if (ret > 0)
return 1;
if (ret != -2)
{
PKCS7err(PKCS7_F_PKCS7_SIGNER_INFO_SET,
PKCS7_R_SIGNING_CTRL_FAILURE);
return 0;
}
}
PKCS7err(PKCS7_F_PKCS7_SIGNER_INFO_SET,
PKCS7_R_SIGNING_NOT_SUPPORTED_FOR_THIS_KEY_TYPE);
err:
return 0;
}
PKCS7_SIGNER_INFO *PKCS7_add_signature(PKCS7 *p7, X509 *x509, EVP_PKEY *pkey,
const EVP_MD *dgst)
{
PKCS7_SIGNER_INFO *si = NULL;
if (dgst == NULL)
{
int def_nid;
if (EVP_PKEY_get_default_digest_nid(pkey, &def_nid) <= 0)
goto err;
dgst = EVP_get_digestbynid(def_nid);
if (dgst == NULL)
{
PKCS7err(PKCS7_F_PKCS7_ADD_SIGNATURE,
PKCS7_R_NO_DEFAULT_DIGEST);
goto err;
}
}
if ((si=PKCS7_SIGNER_INFO_new()) == NULL) goto err;
if (!PKCS7_SIGNER_INFO_set(si,x509,pkey,dgst)) goto err;
if (!PKCS7_add_signer(p7,si)) goto err;
return(si);
err:
if (si)
PKCS7_SIGNER_INFO_free(si);
return(NULL);
}
int PKCS7_set_digest(PKCS7 *p7, const EVP_MD *md)
{
if (PKCS7_type_is_digest(p7))
{
if(!(p7->d.digest->md->parameter = ASN1_TYPE_new()))
{
PKCS7err(PKCS7_F_PKCS7_SET_DIGEST,ERR_R_MALLOC_FAILURE);
return 0;
}
p7->d.digest->md->parameter->type = V_ASN1_NULL;
p7->d.digest->md->algorithm = OBJ_nid2obj(EVP_MD_nid(md));
return 1;
}
PKCS7err(PKCS7_F_PKCS7_SET_DIGEST,PKCS7_R_WRONG_CONTENT_TYPE);
return 1;
}
void PKCS7_RECIP_INFO_get0_alg(PKCS7_RECIP_INFO *ri, X509_ALGOR **penc)
{
if (penc)
*penc = ri->key_enc_algor;
}
PKCS7_RECIP_INFO *PKCS7_add_recipient(PKCS7 *p7, X509 *x509)
{
PKCS7_RECIP_INFO *ri;
if ((ri=PKCS7_RECIP_INFO_new()) == NULL) goto err;
if (!PKCS7_RECIP_INFO_set(ri,x509)) goto err;
if (!PKCS7_add_recipient_info(p7,ri)) goto err;
return ri;
err:
if (ri)
PKCS7_RECIP_INFO_free(ri);
return NULL;
}
int PKCS7_add_recipient_info(PKCS7 *p7, PKCS7_RECIP_INFO *ri)
{
int i;
STACK_OF(PKCS7_RECIP_INFO) *sk;
i=OBJ_obj2nid(p7->type);
switch (i)
{
case NID_pkcs7_signedAndEnveloped:
sk= p7->d.signed_and_enveloped->recipientinfo;
break;
case NID_pkcs7_enveloped:
sk= p7->d.enveloped->recipientinfo;
break;
default:
PKCS7err(PKCS7_F_PKCS7_ADD_RECIPIENT_INFO,PKCS7_R_WRONG_CONTENT_TYPE);
return(0);
}
if (!sk_PKCS7_RECIP_INFO_push(sk,ri))
return 0;
return(1);
}
int PKCS7_RECIP_INFO_set(PKCS7_RECIP_INFO *p7i, X509 *x509)
{
int ret;
EVP_PKEY *pkey = NULL;
if (!ASN1_INTEGER_set(p7i->version,0))
return 0;
if (!X509_NAME_set(&p7i->issuer_and_serial->issuer,
X509_get_issuer_name(x509)))
return 0;
M_ASN1_INTEGER_free(p7i->issuer_and_serial->serial);
if (!(p7i->issuer_and_serial->serial=
M_ASN1_INTEGER_dup(X509_get_serialNumber(x509))))
return 0;
pkey = X509_get_pubkey(x509);
if (!pkey || !pkey->ameth || !pkey->ameth->pkey_ctrl)
{
PKCS7err(PKCS7_F_PKCS7_RECIP_INFO_SET,
PKCS7_R_ENCRYPTION_NOT_SUPPORTED_FOR_THIS_KEY_TYPE);
goto err;
}
ret = pkey->ameth->pkey_ctrl(pkey, ASN1_PKEY_CTRL_PKCS7_ENCRYPT,
0, p7i);
if (ret == -2)
{
PKCS7err(PKCS7_F_PKCS7_RECIP_INFO_SET,
PKCS7_R_ENCRYPTION_NOT_SUPPORTED_FOR_THIS_KEY_TYPE);
goto err;
}
if (ret <= 0)
{
PKCS7err(PKCS7_F_PKCS7_RECIP_INFO_SET,
PKCS7_R_ENCRYPTION_CTRL_FAILURE);
goto err;
}
EVP_PKEY_free(pkey);
CRYPTO_add(&x509->references,1,CRYPTO_LOCK_X509);
p7i->cert=x509;
return 1;
err:
if (pkey)
EVP_PKEY_free(pkey);
return 0;
}
X509 *PKCS7_cert_from_signer_info(PKCS7 *p7, PKCS7_SIGNER_INFO *si)
{
if (PKCS7_type_is_signed(p7))
return(X509_find_by_issuer_and_serial(p7->d.sign->cert,
si->issuer_and_serial->issuer,
si->issuer_and_serial->serial));
else
return(NULL);
}
int PKCS7_set_cipher(PKCS7 *p7, const EVP_CIPHER *cipher)
{
int i;
PKCS7_ENC_CONTENT *ec;
i=OBJ_obj2nid(p7->type);
switch (i)
{
case NID_pkcs7_signedAndEnveloped:
ec=p7->d.signed_and_enveloped->enc_data;
break;
case NID_pkcs7_enveloped:
ec=p7->d.enveloped->enc_data;
break;
default:
PKCS7err(PKCS7_F_PKCS7_SET_CIPHER,PKCS7_R_WRONG_CONTENT_TYPE);
return(0);
}
i = EVP_CIPHER_type(cipher);
if(i == NID_undef) {
PKCS7err(PKCS7_F_PKCS7_SET_CIPHER,PKCS7_R_CIPHER_HAS_NO_OBJECT_IDENTIFIER);
return(0);
}
ec->cipher = cipher;
return 1;
}
int PKCS7_stream(unsigned char ***boundary, PKCS7 *p7)
{
ASN1_OCTET_STRING *os = NULL;
switch (OBJ_obj2nid(p7->type))
{
case NID_pkcs7_data:
os = p7->d.data;
break;
case NID_pkcs7_signedAndEnveloped:
os = p7->d.signed_and_enveloped->enc_data->enc_data;
if (os == NULL)
{
os=M_ASN1_OCTET_STRING_new();
p7->d.signed_and_enveloped->enc_data->enc_data=os;
}
break;
case NID_pkcs7_enveloped:
os = p7->d.enveloped->enc_data->enc_data;
if (os == NULL)
{
os=M_ASN1_OCTET_STRING_new();
p7->d.enveloped->enc_data->enc_data=os;
}
break;
case NID_pkcs7_signed:
os=p7->d.sign->contents->d.data;
break;
default:
os = NULL;
break;
}
if (os == NULL)
return 0;
os->flags |= ASN1_STRING_FLAG_NDEF;
*boundary = &os->data;
return 1;
}
