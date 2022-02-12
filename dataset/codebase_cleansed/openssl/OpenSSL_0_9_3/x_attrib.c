int i2d_X509_ATTRIBUTE(X509_ATTRIBUTE *a, unsigned char **pp)
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
if (a->set)
ret+=i2d_ASN1_SET_OF_ASN1_TYPE(a->value.set,p,i2d_ASN1_TYPE,
V_ASN1_SET,V_ASN1_UNIVERSAL,IS_SET);
else
ret+=i2d_ASN1_TYPE(a->value.single,p);
if (k++) return(r);
}
}
X509_ATTRIBUTE *d2i_X509_ATTRIBUTE(X509_ATTRIBUTE **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,X509_ATTRIBUTE *,X509_ATTRIBUTE_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->object,d2i_ASN1_OBJECT);
if ((c.slen != 0) &&
(M_ASN1_next == (V_ASN1_CONSTRUCTED|V_ASN1_UNIVERSAL|V_ASN1_SET)))
{
ret->set=1;
M_ASN1_D2I_get_set_type(ASN1_TYPE,ret->value.set,d2i_ASN1_TYPE,
ASN1_TYPE_free);
}
else
{
ret->set=0;
M_ASN1_D2I_get(ret->value.single,d2i_ASN1_TYPE);
}
M_ASN1_D2I_Finish(a,X509_ATTRIBUTE_free,ASN1_F_D2I_X509_ATTRIBUTE);
}
X509_ATTRIBUTE *X509_ATTRIBUTE_create(int nid, int atrtype, void *value)
{
X509_ATTRIBUTE *ret=NULL;
ASN1_TYPE *val=NULL;
if ((ret=X509_ATTRIBUTE_new()) == NULL)
return(NULL);
ret->object=OBJ_nid2obj(nid);
ret->set=1;
if ((ret->value.set=sk_ASN1_TYPE_new_null()) == NULL) goto err;
if ((val=ASN1_TYPE_new()) == NULL) goto err;
if (!sk_ASN1_TYPE_push(ret->value.set,val)) goto err;
ASN1_TYPE_set(val,atrtype,value);
return(ret);
err:
if (ret != NULL) X509_ATTRIBUTE_free(ret);
if (val != NULL) ASN1_TYPE_free(val);
return(NULL);
}
X509_ATTRIBUTE *X509_ATTRIBUTE_new(void)
{
X509_ATTRIBUTE *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_ATTRIBUTE);
ret->object=OBJ_nid2obj(NID_undef);
ret->set=0;
ret->value.ptr=NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_X509_ATTRIBUTE_NEW);
}
void X509_ATTRIBUTE_free(X509_ATTRIBUTE *a)
{
if (a == NULL) return;
ASN1_OBJECT_free(a->object);
if (a->set)
sk_ASN1_TYPE_pop_free(a->value.set,ASN1_TYPE_free);
else
ASN1_TYPE_free(a->value.single);
Free((char *)a);
}
