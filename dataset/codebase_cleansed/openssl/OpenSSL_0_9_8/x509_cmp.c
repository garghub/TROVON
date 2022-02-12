int X509_issuer_and_serial_cmp(const X509 *a, const X509 *b)
{
int i;
X509_CINF *ai,*bi;
ai=a->cert_info;
bi=b->cert_info;
i=M_ASN1_INTEGER_cmp(ai->serialNumber,bi->serialNumber);
if (i) return(i);
return(X509_NAME_cmp(ai->issuer,bi->issuer));
}
unsigned long X509_issuer_and_serial_hash(X509 *a)
{
unsigned long ret=0;
EVP_MD_CTX ctx;
unsigned char md[16];
char *f;
EVP_MD_CTX_init(&ctx);
f=X509_NAME_oneline(a->cert_info->issuer,NULL,0);
ret=strlen(f);
EVP_DigestInit_ex(&ctx, EVP_md5(), NULL);
EVP_DigestUpdate(&ctx,(unsigned char *)f,ret);
OPENSSL_free(f);
EVP_DigestUpdate(&ctx,(unsigned char *)a->cert_info->serialNumber->data,
(unsigned long)a->cert_info->serialNumber->length);
EVP_DigestFinal_ex(&ctx,&(md[0]),NULL);
ret=( ((unsigned long)md[0] )|((unsigned long)md[1]<<8L)|
((unsigned long)md[2]<<16L)|((unsigned long)md[3]<<24L)
)&0xffffffffL;
EVP_MD_CTX_cleanup(&ctx);
return(ret);
}
int X509_issuer_name_cmp(const X509 *a, const X509 *b)
{
return(X509_NAME_cmp(a->cert_info->issuer,b->cert_info->issuer));
}
int X509_subject_name_cmp(const X509 *a, const X509 *b)
{
return(X509_NAME_cmp(a->cert_info->subject,b->cert_info->subject));
}
int X509_CRL_cmp(const X509_CRL *a, const X509_CRL *b)
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
int X509_cmp(const X509 *a, const X509 *b)
{
X509_check_purpose((X509 *)a, -1, 0);
X509_check_purpose((X509 *)b, -1, 0);
return memcmp(a->sha1_hash, b->sha1_hash, SHA_DIGEST_LENGTH);
}
static int nocase_cmp(const ASN1_STRING *a, const ASN1_STRING *b)
{
int i;
if (a->length != b->length)
return (a->length - b->length);
for (i=0; i<a->length; i++)
{
int ca, cb;
ca = tolower(a->data[i]);
cb = tolower(b->data[i]);
if (ca != cb)
return(ca-cb);
}
return 0;
}
static int nocase_spacenorm_cmp(const ASN1_STRING *a, const ASN1_STRING *b)
{
unsigned char *pa = NULL, *pb = NULL;
int la, lb;
la = a->length;
lb = b->length;
pa = a->data;
pb = b->data;
while (la > 0 && isspace(*pa))
{
la--;
pa++;
}
while (lb > 0 && isspace(*pb))
{
lb--;
pb++;
}
while (la > 0 && isspace(pa[la-1]))
la--;
while (lb > 0 && isspace(pb[lb-1]))
lb--;
while (la > 0 && lb > 0)
{
int ca, cb;
ca = tolower(*pa);
cb = tolower(*pb);
if (ca != cb)
return (ca - cb);
pa++; pb++;
la--; lb--;
if (la <= 0 || lb <= 0)
break;
if (isspace(*pa) && isspace(*pb))
{
while (la > 0 && isspace(*pa))
{
la--;
pa++;
}
while (lb > 0 && isspace(*pb))
{
lb--;
pb++;
}
}
}
if (la > 0 || lb > 0)
return la - lb;
return 0;
}
static int asn1_string_memcmp(ASN1_STRING *a, ASN1_STRING *b)
{
int j;
j = a->length - b->length;
if (j)
return j;
return memcmp(a->data, b->data, a->length);
}
int X509_NAME_cmp(const X509_NAME *a, const X509_NAME *b)
{
int i,j;
X509_NAME_ENTRY *na,*nb;
unsigned long nabit, nbbit;
j = sk_X509_NAME_ENTRY_num(a->entries)
- sk_X509_NAME_ENTRY_num(b->entries);
if (j)
return j;
for (i=sk_X509_NAME_ENTRY_num(a->entries)-1; i>=0; i--)
{
na=sk_X509_NAME_ENTRY_value(a->entries,i);
nb=sk_X509_NAME_ENTRY_value(b->entries,i);
j=na->value->type-nb->value->type;
if (j)
{
nabit = ASN1_tag2bit(na->value->type);
nbbit = ASN1_tag2bit(nb->value->type);
if (!(nabit & STR_TYPE_CMP) ||
!(nbbit & STR_TYPE_CMP))
return j;
j = asn1_string_memcmp(na->value, nb->value);
}
else if (na->value->type == V_ASN1_PRINTABLESTRING)
j=nocase_spacenorm_cmp(na->value, nb->value);
else if (na->value->type == V_ASN1_IA5STRING
&& OBJ_obj2nid(na->object) == NID_pkcs9_emailAddress)
j=nocase_cmp(na->value, nb->value);
else
j = asn1_string_memcmp(na->value, nb->value);
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
i2d_X509_NAME(x,NULL);
EVP_Digest(x->bytes->data, x->bytes->length, md, NULL, EVP_md5(), NULL);
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
ASN1_BIT_STRING *X509_get0_pubkey_bitstr(const X509 *x)
{
if(!x) return NULL;
return x->cert_info->key->public_key;
}
int X509_check_private_key(X509 *x, EVP_PKEY *k)
{
EVP_PKEY *xk=NULL;
int ok=0;
xk=X509_get_pubkey(x);
switch (EVP_PKEY_cmp(xk, k))
{
case 1:
ok=1;
break;
case 0:
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_KEY_VALUES_MISMATCH);
break;
case -1:
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_KEY_TYPE_MISMATCH);
break;
case -2:
#ifndef OPENSSL_NO_EC
if (k->type == EVP_PKEY_EC)
{
X509err(X509_F_X509_CHECK_PRIVATE_KEY, ERR_R_EC_LIB);
break;
}
#endif
#ifndef OPENSSL_NO_DH
if (k->type == EVP_PKEY_DH)
{
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_CANT_CHECK_DH_KEY);
break;
}
#endif
X509err(X509_F_X509_CHECK_PRIVATE_KEY,X509_R_UNKNOWN_KEY_TYPE);
}
EVP_PKEY_free(xk);
return(ok);
}
