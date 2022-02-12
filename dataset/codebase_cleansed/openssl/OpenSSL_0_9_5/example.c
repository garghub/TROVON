int add_signed_time(PKCS7_SIGNER_INFO *si)
{
ASN1_UTCTIME *sign_time;
sign_time=X509_gmtime_adj(NULL,0);
PKCS7_add_signed_attribute(si,NID_pkcs9_signingTime,
V_ASN1_UTCTIME,(char *)sign_time);
return(1);
}
ASN1_UTCTIME *get_signed_time(PKCS7_SIGNER_INFO *si)
{
ASN1_TYPE *so;
so=PKCS7_get_signed_attribute(si,NID_pkcs9_signingTime);
if (so->type == V_ASN1_UTCTIME)
return so->value.utctime;
return NULL;
}
void add_signed_string(PKCS7_SIGNER_INFO *si, char *str)
{
ASN1_OCTET_STRING *os;
if (signed_string_nid == -1)
signed_string_nid=
OBJ_create("1.2.3.4.5","OID_example","Our example OID");
os=ASN1_OCTET_STRING_new();
ASN1_OCTET_STRING_set(os,(unsigned char*)str,strlen(str));
PKCS7_add_signed_attribute(si,signed_string_nid,
V_ASN1_OCTET_STRING,(char *)os);
}
int get_signed_string(PKCS7_SIGNER_INFO *si, char *buf, int len)
{
ASN1_TYPE *so;
ASN1_OCTET_STRING *os;
int i;
if (signed_string_nid == -1)
signed_string_nid=
OBJ_create("1.2.3.4.5","OID_example","Our example OID");
so=PKCS7_get_signed_attribute(si,signed_string_nid);
if (so != NULL)
{
if (so->type == V_ASN1_OCTET_STRING)
{
os=so->value.octet_string;
i=os->length;
if ((i+1) > len)
i=len-1;
memcpy(buf,os->data,i);
return(i);
}
}
return(0);
}
int add_signed_seq2string(PKCS7_SIGNER_INFO *si, char *str1, char *str2)
{
unsigned char *p;
ASN1_OCTET_STRING *os1,*os2;
ASN1_STRING *seq;
unsigned char *data;
int i,total;
if (signed_seq2string_nid == -1)
signed_seq2string_nid=
OBJ_create("1.9.9999","OID_example","Our example OID");
os1=ASN1_OCTET_STRING_new();
os2=ASN1_OCTET_STRING_new();
ASN1_OCTET_STRING_set(os1,(unsigned char*)str1,strlen(str1));
ASN1_OCTET_STRING_set(os2,(unsigned char*)str1,strlen(str1));
i =i2d_ASN1_OCTET_STRING(os1,NULL);
i+=i2d_ASN1_OCTET_STRING(os2,NULL);
total=ASN1_object_size(1,i,V_ASN1_SEQUENCE);
data=malloc(total);
p=data;
ASN1_put_object(&p,1,i,V_ASN1_SEQUENCE,V_ASN1_UNIVERSAL);
i2d_ASN1_OCTET_STRING(os1,&p);
i2d_ASN1_OCTET_STRING(os2,&p);
seq=ASN1_STRING_new();
ASN1_STRING_set(seq,data,total);
free(data);
ASN1_OCTET_STRING_free(os1);
ASN1_OCTET_STRING_free(os2);
PKCS7_add_signed_attribute(si,signed_seq2string_nid,
V_ASN1_SEQUENCE,(char *)seq);
return(1);
}
int get_signed_seq2string(PKCS7_SIGNER_INFO *si, char **str1, char **str2)
{
ASN1_TYPE *so;
if (signed_seq2string_nid == -1)
signed_seq2string_nid=
OBJ_create("1.9.9999","OID_example","Our example OID");
so=PKCS7_get_signed_attribute(si,signed_seq2string_nid);
if (so && (so->type == V_ASN1_SEQUENCE))
{
ASN1_CTX c;
ASN1_STRING *s;
long length;
ASN1_OCTET_STRING *os1,*os2;
s=so->value.sequence;
c.p=ASN1_STRING_data(s);
c.max=c.p+ASN1_STRING_length(s);
if (!asn1_GetSequence(&c,&length)) goto err;
c.q=c.p;
if ((os1=d2i_ASN1_OCTET_STRING(NULL,&c.p,c.slen)) == NULL)
goto err;
c.slen-=(c.p-c.q);
c.q=c.p;
if ((os2=d2i_ASN1_OCTET_STRING(NULL,&c.p,c.slen)) == NULL)
goto err;
c.slen-=(c.p-c.q);
if (!asn1_Finish(&c)) goto err;
*str1=malloc(os1->length+1);
*str2=malloc(os2->length+1);
memcpy(*str1,os1->data,os1->length);
memcpy(*str2,os2->data,os2->length);
(*str1)[os1->length]='\0';
(*str2)[os2->length]='\0';
ASN1_OCTET_STRING_free(os1);
ASN1_OCTET_STRING_free(os2);
return(1);
}
err:
return(0);
}
X509_ATTRIBUTE *create_time(void)
{
ASN1_UTCTIME *sign_time;
X509_ATTRIBUTE *ret;
sign_time=X509_gmtime_adj(NULL,0);
ret=X509_ATTRIBUTE_create(NID_pkcs9_signingTime,
V_ASN1_UTCTIME,(char *)sign_time);
return(ret);
}
X509_ATTRIBUTE *create_string(char *str)
{
ASN1_OCTET_STRING *os;
X509_ATTRIBUTE *ret;
if (signed_string_nid == -1)
signed_string_nid=
OBJ_create("1.2.3.4.5","OID_example","Our example OID");
os=ASN1_OCTET_STRING_new();
ASN1_OCTET_STRING_set(os,(unsigned char*)str,strlen(str));
ret=X509_ATTRIBUTE_create(signed_string_nid,
V_ASN1_OCTET_STRING,(char *)os);
return(ret);
}
X509_ATTRIBUTE *add_seq2string(PKCS7_SIGNER_INFO *si, char *str1, char *str2)
{
unsigned char *p;
ASN1_OCTET_STRING *os1,*os2;
ASN1_STRING *seq;
X509_ATTRIBUTE *ret;
unsigned char *data;
int i,total;
if (signed_seq2string_nid == -1)
signed_seq2string_nid=
OBJ_create("1.9.9999","OID_example","Our example OID");
os1=ASN1_OCTET_STRING_new();
os2=ASN1_OCTET_STRING_new();
ASN1_OCTET_STRING_set(os1,(unsigned char*)str1,strlen(str1));
ASN1_OCTET_STRING_set(os2,(unsigned char*)str1,strlen(str1));
i =i2d_ASN1_OCTET_STRING(os1,NULL);
i+=i2d_ASN1_OCTET_STRING(os2,NULL);
total=ASN1_object_size(1,i,V_ASN1_SEQUENCE);
data=malloc(total);
p=data;
ASN1_put_object(&p,1,i,V_ASN1_SEQUENCE,V_ASN1_UNIVERSAL);
i2d_ASN1_OCTET_STRING(os1,&p);
i2d_ASN1_OCTET_STRING(os2,&p);
seq=ASN1_STRING_new();
ASN1_STRING_set(seq,data,total);
free(data);
ASN1_OCTET_STRING_free(os1);
ASN1_OCTET_STRING_free(os2);
ret=X509_ATTRIBUTE_create(signed_seq2string_nid,
V_ASN1_SEQUENCE,(char *)seq);
return(ret);
}
