int RSA_sign(int type, const unsigned char *m, unsigned int m_len,
unsigned char *sigret, unsigned int *siglen, RSA *rsa)
{
X509_SIG sig;
ASN1_TYPE parameter;
int i,j,ret=1;
unsigned char *p, *tmps = NULL;
const unsigned char *s = NULL;
X509_ALGOR algor;
ASN1_OCTET_STRING digest;
if((rsa->flags & RSA_FLAG_SIGN_VER) && rsa->meth->rsa_sign)
{
return rsa->meth->rsa_sign(type, m, m_len,
sigret, siglen, rsa);
}
if(type == NID_md5_sha1) {
if(m_len != SSL_SIG_LENGTH) {
RSAerr(RSA_F_RSA_SIGN,RSA_R_INVALID_MESSAGE_LENGTH);
return(0);
}
i = SSL_SIG_LENGTH;
s = m;
} else {
sig.algor= &algor;
sig.algor->algorithm=OBJ_nid2obj(type);
if (sig.algor->algorithm == NULL)
{
RSAerr(RSA_F_RSA_SIGN,RSA_R_UNKNOWN_ALGORITHM_TYPE);
return(0);
}
if (sig.algor->algorithm->length == 0)
{
RSAerr(RSA_F_RSA_SIGN,RSA_R_THE_ASN1_OBJECT_IDENTIFIER_IS_NOT_KNOWN_FOR_THIS_MD);
return(0);
}
parameter.type=V_ASN1_NULL;
parameter.value.ptr=NULL;
sig.algor->parameter= &parameter;
sig.digest= &digest;
sig.digest->data=(unsigned char *)m;
sig.digest->length=m_len;
i=i2d_X509_SIG(&sig,NULL);
}
j=RSA_size(rsa);
if (i > (j-RSA_PKCS1_PADDING_SIZE))
{
RSAerr(RSA_F_RSA_SIGN,RSA_R_DIGEST_TOO_BIG_FOR_RSA_KEY);
return(0);
}
if(type != NID_md5_sha1) {
tmps=(unsigned char *)OPENSSL_malloc((unsigned int)j+1);
if (tmps == NULL)
{
RSAerr(RSA_F_RSA_SIGN,ERR_R_MALLOC_FAILURE);
return(0);
}
p=tmps;
i2d_X509_SIG(&sig,&p);
s=tmps;
}
i=RSA_private_encrypt(i,s,sigret,rsa,RSA_PKCS1_PADDING);
if (i <= 0)
ret=0;
else
*siglen=i;
if(type != NID_md5_sha1) {
OPENSSL_cleanse(tmps,(unsigned int)j+1);
OPENSSL_free(tmps);
}
return(ret);
}
int RSA_verify(int dtype, const unsigned char *m, unsigned int m_len,
unsigned char *sigbuf, unsigned int siglen, RSA *rsa)
{
int i,ret=0,sigtype;
unsigned char *s;
X509_SIG *sig=NULL;
if (siglen != (unsigned int)RSA_size(rsa))
{
RSAerr(RSA_F_RSA_VERIFY,RSA_R_WRONG_SIGNATURE_LENGTH);
return(0);
}
if((rsa->flags & RSA_FLAG_SIGN_VER) && rsa->meth->rsa_verify)
{
return rsa->meth->rsa_verify(dtype, m, m_len,
sigbuf, siglen, rsa);
}
s=(unsigned char *)OPENSSL_malloc((unsigned int)siglen);
if (s == NULL)
{
RSAerr(RSA_F_RSA_VERIFY,ERR_R_MALLOC_FAILURE);
goto err;
}
if((dtype == NID_md5_sha1) && (m_len != SSL_SIG_LENGTH) ) {
RSAerr(RSA_F_RSA_VERIFY,RSA_R_INVALID_MESSAGE_LENGTH);
goto err;
}
i=RSA_public_decrypt((int)siglen,sigbuf,s,rsa,RSA_PKCS1_PADDING);
if (i <= 0) goto err;
if(dtype == NID_md5_sha1) {
if((i != SSL_SIG_LENGTH) || memcmp(s, m, SSL_SIG_LENGTH))
RSAerr(RSA_F_RSA_VERIFY,RSA_R_BAD_SIGNATURE);
else ret = 1;
} else {
const unsigned char *p=s;
sig=d2i_X509_SIG(NULL,&p,(long)i);
if (sig == NULL) goto err;
sigtype=OBJ_obj2nid(sig->algor->algorithm);
#ifdef RSA_DEBUG
fprintf(stderr,"in(%s) expect(%s)\n",OBJ_nid2ln(sigtype),
OBJ_nid2ln(dtype));
#endif
if (sigtype != dtype)
{
if (((dtype == NID_md5) &&
(sigtype == NID_md5WithRSAEncryption)) ||
((dtype == NID_md2) &&
(sigtype == NID_md2WithRSAEncryption)))
{
#if !defined(OPENSSL_NO_STDIO) && !defined(OPENSSL_SYS_WIN16)
fprintf(stderr,"signature has problems, re-make with post SSLeay045\n");
#endif
}
else
{
RSAerr(RSA_F_RSA_VERIFY,
RSA_R_ALGORITHM_MISMATCH);
goto err;
}
}
if ( ((unsigned int)sig->digest->length != m_len) ||
(memcmp(m,sig->digest->data,m_len) != 0))
{
RSAerr(RSA_F_RSA_VERIFY,RSA_R_BAD_SIGNATURE);
}
else
ret=1;
}
err:
if (sig != NULL) X509_SIG_free(sig);
if (s != NULL)
{
OPENSSL_cleanse(s,(unsigned int)siglen);
OPENSSL_free(s);
}
return(ret);
}
