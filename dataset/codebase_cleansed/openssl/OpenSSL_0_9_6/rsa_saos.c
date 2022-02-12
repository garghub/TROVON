int RSA_sign_ASN1_OCTET_STRING(int type, unsigned char *m, unsigned int m_len,
unsigned char *sigret, unsigned int *siglen, RSA *rsa)
{
ASN1_OCTET_STRING sig;
int i,j,ret=1;
unsigned char *p,*s;
sig.type=V_ASN1_OCTET_STRING;
sig.length=m_len;
sig.data=m;
i=i2d_ASN1_OCTET_STRING(&sig,NULL);
j=RSA_size(rsa);
if ((i-RSA_PKCS1_PADDING) > j)
{
RSAerr(RSA_F_RSA_SIGN_ASN1_OCTET_STRING,RSA_R_DIGEST_TOO_BIG_FOR_RSA_KEY);
return(0);
}
s=(unsigned char *)OPENSSL_malloc((unsigned int)j+1);
if (s == NULL)
{
RSAerr(RSA_F_RSA_SIGN_ASN1_OCTET_STRING,ERR_R_MALLOC_FAILURE);
return(0);
}
p=s;
i2d_ASN1_OCTET_STRING(&sig,&p);
i=RSA_private_encrypt(i,s,sigret,rsa,RSA_PKCS1_PADDING);
if (i <= 0)
ret=0;
else
*siglen=i;
memset(s,0,(unsigned int)j+1);
OPENSSL_free(s);
return(ret);
}
int RSA_verify_ASN1_OCTET_STRING(int dtype, unsigned char *m,
unsigned int m_len, unsigned char *sigbuf, unsigned int siglen,
RSA *rsa)
{
int i,ret=0;
unsigned char *p,*s;
ASN1_OCTET_STRING *sig=NULL;
if (siglen != (unsigned int)RSA_size(rsa))
{
RSAerr(RSA_F_RSA_VERIFY_ASN1_OCTET_STRING,RSA_R_WRONG_SIGNATURE_LENGTH);
return(0);
}
s=(unsigned char *)OPENSSL_malloc((unsigned int)siglen);
if (s == NULL)
{
RSAerr(RSA_F_RSA_VERIFY_ASN1_OCTET_STRING,ERR_R_MALLOC_FAILURE);
goto err;
}
i=RSA_public_decrypt((int)siglen,sigbuf,s,rsa,RSA_PKCS1_PADDING);
if (i <= 0) goto err;
p=s;
sig=d2i_ASN1_OCTET_STRING(NULL,&p,(long)i);
if (sig == NULL) goto err;
if ( ((unsigned int)sig->length != m_len) ||
(memcmp(m,sig->data,m_len) != 0))
{
RSAerr(RSA_F_RSA_VERIFY_ASN1_OCTET_STRING,RSA_R_BAD_SIGNATURE);
}
else
ret=1;
err:
if (sig != NULL) M_ASN1_OCTET_STRING_free(sig);
memset(s,0,(unsigned int)siglen);
OPENSSL_free(s);
return(ret);
}
