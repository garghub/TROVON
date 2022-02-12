int ASN1_digest(int (*i2d)(), const EVP_MD *type, char *data,
unsigned char *md, unsigned int *len)
{
int i;
unsigned char *str,*p;
i=i2d(data,NULL);
if ((str=(unsigned char *)OPENSSL_malloc(i)) == NULL) return(0);
p=str;
i2d(data,&p);
EVP_Digest(str, i, md, len, type, NULL);
OPENSSL_free(str);
return(1);
}
int ASN1_item_digest(const ASN1_ITEM *it, const EVP_MD *type, void *asn,
unsigned char *md, unsigned int *len)
{
int i;
unsigned char *str = NULL;
i=ASN1_item_i2d(asn,&str, it);
if (!str) return(0);
EVP_Digest(str, i, md, len, type, NULL);
OPENSSL_free(str);
return(1);
}
