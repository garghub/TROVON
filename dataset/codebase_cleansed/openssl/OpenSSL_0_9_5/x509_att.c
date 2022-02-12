int X509_ATTRIBUTE_set1_data(X509_ATTRIBUTE *attr, int attrtype, void *data, int len)
{
ASN1_TYPE *ttmp;
ASN1_STRING *stmp;
int atype;
if (!attr) return 0;
if(attrtype & MBSTRING_FLAG) {
stmp = ASN1_STRING_set_by_NID(NULL, data, len, attrtype,
OBJ_obj2nid(attr->object));
if(!stmp) {
X509err(X509_F_X509_ATTRIBUTE_SET1_DATA, ERR_R_ASN1_LIB);
return 0;
}
atype = stmp->type;
} else {
if(!(stmp = ASN1_STRING_type_new(attrtype))) goto err;
if(!ASN1_STRING_set(stmp, data, len)) goto err;
atype = attrtype;
}
if(!(attr->value.set = sk_ASN1_TYPE_new_null())) goto err;
if(!(ttmp = ASN1_TYPE_new())) goto err;
if(!sk_ASN1_TYPE_push(attr->value.set, ttmp)) goto err;
attr->set = 1;
ASN1_TYPE_set(ttmp, atype, stmp);
return 1;
err:
X509err(X509_F_X509_ATTRIBUTE_SET1_DATA, ERR_R_MALLOC_FAILURE);
return 0;
}
int X509_ATTRIBUTE_count(X509_ATTRIBUTE *attr)
{
if(attr->set) return sk_ASN1_TYPE_num(attr->value.set);
if(attr->value.single) return 1;
return 0;
}
ASN1_OBJECT *X509_ATTRIBUTE_get0_object(X509_ATTRIBUTE *attr)
{
if (attr == NULL) return(NULL);
return(attr->object);
}
void *X509_ATTRIBUTE_get0_data(X509_ATTRIBUTE *attr, int idx,
int atrtype, void *data)
{
ASN1_TYPE *ttmp;
ttmp = X509_ATTRIBUTE_get0_type(attr, idx);
if(!ttmp) return NULL;
if(atrtype != ASN1_TYPE_get(ttmp)){
X509err(X509_F_X509_ATTRIBUTE_GET0_DATA, X509_R_WRONG_TYPE);
return NULL;
}
return ttmp->value.ptr;
}
ASN1_TYPE *X509_ATTRIBUTE_get0_type(X509_ATTRIBUTE *attr, int idx)
{
if (attr == NULL) return(NULL);
if(idx >= X509_ATTRIBUTE_count(attr)) return NULL;
if(attr->set) return sk_ASN1_TYPE_value(attr->value.set, idx);
else return attr->value.single;
}
