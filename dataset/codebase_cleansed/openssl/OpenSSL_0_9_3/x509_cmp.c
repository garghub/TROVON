int X509_issuer_and_serial_cmp(X509 *a, X509 *b)
{
int i;
X509_CINF *ai,*bi;
ai=a->cert_info;
bi=b->cert_info;
i=ASN1_INTEGER_cmp(ai->serialNumber,bi->serialNumber);
if (i) return(i);
return(X509_NAME_cmp(ai->issuer,bi->issuer));
}
unsigned long X509_issuer_and_serial_hash(X509 *a)
{
unsigned long ret=0;
MD5_CTX ctx;
unsigned char md[16];
char str[256];
X509_NAME_oneline(a->cert_info->issuer,str,256);
ret=strlen(str);
MD5_Init(&ctx);
MD5_Update(&ctx,(unsigned char *)str,ret);
MD5_Update(&ctx,(unsigned char *)a->cert_info->serialNumber->data,
(unsigned long)a->cert_info->serialNumber->length);
MD5_Final(&(md[0]),&ctx);
ret=( ((unsigned long)md[0] )|((unsigned long)md[1]<<8L)|
((unsigned long)md[2]<<16L)|((unsigned long)md[3]<<24L)
)&0xffffffffL;
return(ret);
}
int X509_issuer_name_cmp(X509 *a, X509 *b)
{
return(X509_NAME_cmp(a->cert_info->issuer,b->cert_info->issuer));
}
int X509_subject_name_cmp(X509 *a, X509 *b)
{
return(X509_NAME_cmp(a->cert_info->subject,b->cert_info->subject));
}
int X509_CRL_cmp(X509_CRL *a, X509_CRL *b)
{
return(X509_NAME_cmp(a->crl->issuer,b->crl->issuer));
}
X509_NAME *X509_get_issuer_name(X509 *a)
{
return(a->cert_info->issuer);
}
unsigned long X509_issuer_name_hash(X509 *x)
{
return(X509_NAME_hash(x->cert_info->issuer));
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
int X509_NAME_cmp(X509_NAME *a, X509_NAME *b)
{
int i,j;
X509_NAME_ENTRY *na,*nb;
if (sk_X509_NAME_ENTRY_num(a->entries)
!= sk_X509_NAME_ENTRY_num(b->entries))
return sk_X509_NAME_ENTRY_num(a->entries)
-sk_X509_NAME_ENTRY_num(b->entries);
for (i=sk_X509_NAME_ENTRY_num(a->entries)-1; i>=0; i--)
{
na=sk_X509_NAME_ENTRY_value(a->entries,i);
nb=sk_X509_NAME_ENTRY_value(b->entries,i);
j=na->value->length-nb->value->length;
if (j) return(j);
j=memcmp(na->value->data,nb->value->data,
na->value->length);
if (j) return(j);
j=na->set-nb->set;
if (j) return(j);
}
for (i=sk_X509_NAME_ENTRY_num(a->entries)-1; i>=0; i--)
{
na=sk_X509_NAME_ENTRY_value(a->entries,i);
nb=sk_X509_NAME_ENTRY_value(b->entries,i);
j=OBJ_cmp(na->object,nb->object);
if (j) return(j);
}
return(0);
}
unsigned long X509_NAME_hash(X509_NAME *x)
{
unsigned long ret=0;
unsigned char md[16];
unsigned char str[256],*p,*pp;
int i;
i=i2d_X509_NAME(x,NULL);
if (i > sizeof(str))
p=Malloc(i);
else
p=str;
pp=p;
i2d_X509_NAME(x,&pp);
MD5((unsigned char *)p,i,&(md[0]));
if (p != str) Free(p);
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
int X509_check_private_key(X509 *x, EVP_PKEY *k)
{
EVP_PKEY *xk=NULL;
int ok=0;
xk=X509_get_pubkey(x);
if (xk->type != k->type)
{
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_KEY_TYPE_MISMATCH);
goto err;
}
switch (k->type)
{
#ifndef NO_RSA
case EVP_PKEY_RSA:
if (BN_cmp(xk->pkey.rsa->n,k->pkey.rsa->n) != 0
|| BN_cmp(xk->pkey.rsa->e,k->pkey.rsa->e) != 0)
{
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_KEY_VALUES_MISMATCH);
goto err;
}
break;
#endif
#ifndef NO_DSA
case EVP_PKEY_DSA:
if (BN_cmp(xk->pkey.dsa->pub_key,k->pkey.dsa->pub_key) != 0)
{
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_KEY_VALUES_MISMATCH);
goto err;
}
break;
#endif
#ifndef NO_DH
case EVP_PKEY_DH:
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_CANT_CHECK_DH_KEY);
goto err;
#endif
default:
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_UNKNOWN_KEY_TYPE);
goto err;
}
ok=1;
err:
EVP_PKEY_free(xk);
return(ok);
}
