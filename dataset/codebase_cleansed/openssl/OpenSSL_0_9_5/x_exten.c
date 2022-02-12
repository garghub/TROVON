int i2d_X509_EXTENSION(X509_EXTENSION *a, unsigned char **pp)
{
int k=0;
int r=0,ret=0;
unsigned char **p=NULL;
if (a == NULL) return(0);
p=NULL;
for (;;)
{
if (k)
{
r=ASN1_object_size(1,ret,V_ASN1_SEQUENCE);
if (pp == NULL) return(r);
p=pp;
ASN1_put_object(p,1,ret,V_ASN1_SEQUENCE,
V_ASN1_UNIVERSAL);
}
ret+=i2d_ASN1_OBJECT(a->object,p);
if ((a->critical) || a->netscape_hack)
ret+=i2d_ASN1_BOOLEAN(a->critical,p);
ret+=i2d_ASN1_OCTET_STRING(a->value,p);
if (k++) return(r);
}
}
X509_EXTENSION *d2i_X509_EXTENSION(X509_EXTENSION **a, unsigned char **pp,
long length)
{
int i;
M_ASN1_D2I_vars(a,X509_EXTENSION *,X509_EXTENSION_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->object,d2i_ASN1_OBJECT);
ret->netscape_hack=0;
if ((c.slen != 0) &&
(M_ASN1_next == (V_ASN1_UNIVERSAL|V_ASN1_BOOLEAN)))
{
c.q=c.p;
if (d2i_ASN1_BOOLEAN(&i,&c.p,c.slen) < 0) goto err;
ret->critical=i;
c.slen-=(c.p-c.q);
if (ret->critical == 0) ret->netscape_hack=1;
}
M_ASN1_D2I_get(ret->value,d2i_ASN1_OCTET_STRING);
M_ASN1_D2I_Finish(a,X509_EXTENSION_free,ASN1_F_D2I_X509_EXTENSION);
}
X509_EXTENSION *X509_EXTENSION_new(void)
{
X509_EXTENSION *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_EXTENSION);
ret->object=OBJ_nid2obj(NID_undef);
M_ASN1_New(ret->value,M_ASN1_OCTET_STRING_new);
ret->critical=0;
ret->netscape_hack=0;
return(ret);
M_ASN1_New_Error(ASN1_F_X509_EXTENSION_NEW);
}
void X509_EXTENSION_free(X509_EXTENSION *a)
{
if (a == NULL) return;
ASN1_OBJECT_free(a->object);
M_ASN1_OCTET_STRING_free(a->value);
Free(a);
}
