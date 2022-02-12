int ASN1_digest(int (*i2d)(), const EVP_MD *type, char *data,
unsigned char *md, unsigned int *len)
{
EVP_MD_CTX ctx;
int i;
unsigned char *str,*p;
i=i2d(data,NULL);
if ((str=(unsigned char *)Malloc(i)) == NULL) return(0);
p=str;
i2d(data,&p);
EVP_DigestInit(&ctx,type);
EVP_DigestUpdate(&ctx,str,i);
EVP_DigestFinal(&ctx,md,len);
Free(str);
return(1);
}
