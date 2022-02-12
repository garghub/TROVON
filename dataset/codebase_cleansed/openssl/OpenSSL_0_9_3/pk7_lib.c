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
ret=p7->detached;
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
PKCS7_content_free(p7->d.sign->contents);
p7->d.sign->contents=p7_data;
break;
case NID_pkcs7_digest:
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
PKCS7_content_free(p7);
obj=OBJ_nid2obj(type);
switch (type)
{
case NID_pkcs7_signed:
p7->type=obj;
if ((p7->d.sign=PKCS7_SIGNED_new()) == NULL)
goto err;
ASN1_INTEGER_set(p7->d.sign->version,1);
break;
case NID_pkcs7_data:
p7->type=obj;
if ((p7->d.data=ASN1_OCTET_STRING_new()) == NULL)
goto err;
break;
case NID_pkcs7_signedAndEnveloped:
p7->type=obj;
if ((p7->d.signed_and_enveloped=PKCS7_SIGN_ENVELOPE_new())
== NULL) goto err;
ASN1_INTEGER_set(p7->d.signed_and_enveloped->version,1);
break;
case NID_pkcs7_enveloped:
p7->type=obj;
if ((p7->d.enveloped=PKCS7_ENVELOPE_new())
== NULL) goto err;
ASN1_INTEGER_set(p7->d.enveloped->version,0);
break;
case NID_pkcs7_digest:
case NID_pkcs7_encrypted:
default:
PKCS7err(PKCS7_F_PKCS7_SET_TYPE,PKCS7_R_UNSUPPORTED_CONTENT_TYPE);
goto err;
}
return(1);
err:
return(0);
}
int PKCS7_add_signer(PKCS7 *p7, PKCS7_SIGNER_INFO *psi)
{
int i,j,nid;
X509_ALGOR *alg;
STACK *signer_sk;
STACK *md_sk;
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
for (i=0; i<sk_num(md_sk); i++)
{
alg=(X509_ALGOR *)sk_value(md_sk,i);
if (OBJ_obj2nid(alg->algorithm) == nid)
{
j=1;
break;
}
}
if (!j)
{
alg=X509_ALGOR_new();
alg->algorithm=OBJ_nid2obj(nid);
sk_push(md_sk,(char *)alg);
}
sk_push(signer_sk,(char *)psi);
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
CRYPTO_add(&x509->references,1,CRYPTO_LOCK_X509);
sk_X509_push(*sk,x509);
return(1);
}
int PKCS7_add_crl(PKCS7 *p7, X509_CRL *crl)
{
int i;
STACK **sk;
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
*sk=sk_new_null();
CRYPTO_add(&crl->references,1,CRYPTO_LOCK_X509_CRL);
sk_push(*sk,(char *)crl);
return(1);
}
int PKCS7_SIGNER_INFO_set(PKCS7_SIGNER_INFO *p7i, X509 *x509, EVP_PKEY *pkey,
EVP_MD *dgst)
{
ASN1_INTEGER_set(p7i->version,1);
X509_NAME_set(&p7i->issuer_and_serial->issuer,
X509_get_issuer_name(x509));
ASN1_INTEGER_free(p7i->issuer_and_serial->serial);
p7i->issuer_and_serial->serial=
ASN1_INTEGER_dup(X509_get_serialNumber(x509));
CRYPTO_add(&pkey->references,1,CRYPTO_LOCK_EVP_PKEY);
p7i->pkey=pkey;
if (pkey->type == EVP_PKEY_DSA)
p7i->digest_alg->algorithm=OBJ_nid2obj(NID_sha1);
else
p7i->digest_alg->algorithm=OBJ_nid2obj(EVP_MD_type(dgst));
if (p7i->digest_alg->parameter != NULL)
ASN1_TYPE_free(p7i->digest_alg->parameter);
if ((p7i->digest_alg->parameter=ASN1_TYPE_new()) == NULL)
goto err;
p7i->digest_alg->parameter->type=V_ASN1_NULL;
p7i->digest_enc_alg->algorithm=OBJ_nid2obj(EVP_PKEY_type(pkey->type));
if (p7i->digest_enc_alg->parameter != NULL)
ASN1_TYPE_free(p7i->digest_enc_alg->parameter);
if ((p7i->digest_enc_alg->parameter=ASN1_TYPE_new()) == NULL)
goto err;
p7i->digest_enc_alg->parameter->type=V_ASN1_NULL;
return(1);
err:
return(0);
}
PKCS7_SIGNER_INFO *PKCS7_add_signature(PKCS7 *p7, X509 *x509, EVP_PKEY *pkey,
EVP_MD *dgst)
{
PKCS7_SIGNER_INFO *si;
if ((si=PKCS7_SIGNER_INFO_new()) == NULL) goto err;
if (!PKCS7_SIGNER_INFO_set(si,x509,pkey,dgst)) goto err;
if (!PKCS7_add_signer(p7,si)) goto err;
return(si);
err:
return(NULL);
}
STACK *PKCS7_get_signer_info(PKCS7 *p7)
{
if (PKCS7_type_is_signed(p7))
{
return(p7->d.sign->signer_info);
}
else if (PKCS7_type_is_signedAndEnveloped(p7))
{
return(p7->d.signed_and_enveloped->signer_info);
}
else
return(NULL);
}
PKCS7_RECIP_INFO *PKCS7_add_recipient(PKCS7 *p7, X509 *x509)
{
PKCS7_RECIP_INFO *ri;
if ((ri=PKCS7_RECIP_INFO_new()) == NULL) goto err;
if (!PKCS7_RECIP_INFO_set(ri,x509)) goto err;
if (!PKCS7_add_recipient_info(p7,ri)) goto err;
return(ri);
err:
return(NULL);
}
int PKCS7_add_recipient_info(PKCS7 *p7, PKCS7_RECIP_INFO *ri)
{
int i;
STACK *sk;
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
sk_push(sk,(char *)ri);
return(1);
}
int PKCS7_RECIP_INFO_set(PKCS7_RECIP_INFO *p7i, X509 *x509)
{
ASN1_INTEGER_set(p7i->version,0);
X509_NAME_set(&p7i->issuer_and_serial->issuer,
X509_get_issuer_name(x509));
ASN1_INTEGER_free(p7i->issuer_and_serial->serial);
p7i->issuer_and_serial->serial=
ASN1_INTEGER_dup(X509_get_serialNumber(x509));
X509_ALGOR_free(p7i->key_enc_algor);
p7i->key_enc_algor=(X509_ALGOR *)ASN1_dup(i2d_X509_ALGOR,
(char *(*)())d2i_X509_ALGOR,
(char *)x509->cert_info->key->algor);
CRYPTO_add(&x509->references,1,CRYPTO_LOCK_X509);
p7i->cert=x509;
return(1);
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
ec->cipher = cipher;
return 1;
}
