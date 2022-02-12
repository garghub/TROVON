char *PEM_ASN1_read_bio(char *(*d2i)(), const char *name, BIO *bp, char **x,
pem_password_cb *cb, void *u)
{
unsigned char *p=NULL,*data=NULL;
long len;
char *ret=NULL;
if (!PEM_bytes_read_bio(&data, &len, NULL, name, bp, cb, u))
return NULL;
p = data;
ret=d2i(x,&p,len);
if (ret == NULL)
PEMerr(PEM_F_PEM_ASN1_READ_BIO,ERR_R_ASN1_LIB);
OPENSSL_free(data);
return(ret);
}
