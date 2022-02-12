int X509_keyid_set1(X509 *x, unsigned char *id, int len)
{
X509_CERT_AUX *aux;
if (!id)
{
if (!x || !x->aux || !x->aux->keyid)
return 1;
ASN1_OCTET_STRING_free(x->aux->keyid);
x->aux->keyid = NULL;
return 1;
}
if(!(aux = aux_get(x))) return 0;
if(!aux->keyid && !(aux->keyid = ASN1_OCTET_STRING_new())) return 0;
return ASN1_STRING_set(aux->keyid, id, len);
}
unsigned char *X509_alias_get0(X509 *x, int *len)
{
if(!x->aux || !x->aux->alias) return NULL;
if(len) *len = x->aux->alias->length;
return x->aux->alias->data;
}
unsigned char *X509_keyid_get0(X509 *x, int *len)
{
if(!x->aux || !x->aux->keyid) return NULL;
if(len) *len = x->aux->keyid->length;
return x->aux->keyid->data;
}
int X509_add1_trust_object(X509 *x, ASN1_OBJECT *obj)
{
X509_CERT_AUX *aux;
ASN1_OBJECT *objtmp;
if(!(objtmp = OBJ_dup(obj))) return 0;
if(!(aux = aux_get(x))) return 0;
if(!aux->trust
&& !(aux->trust = sk_ASN1_OBJECT_new_null())) return 0;
return sk_ASN1_OBJECT_push(aux->trust, objtmp);
}
int X509_add1_reject_object(X509 *x, ASN1_OBJECT *obj)
{
X509_CERT_AUX *aux;
ASN1_OBJECT *objtmp;
if(!(objtmp = OBJ_dup(obj))) return 0;
if(!(aux = aux_get(x))) return 0;
if(!aux->reject
&& !(aux->reject = sk_ASN1_OBJECT_new_null())) return 0;
return sk_ASN1_OBJECT_push(aux->reject, objtmp);
}
void X509_trust_clear(X509 *x)
{
if(x->aux && x->aux->trust) {
sk_ASN1_OBJECT_pop_free(x->aux->trust, ASN1_OBJECT_free);
x->aux->trust = NULL;
}
}
void X509_reject_clear(X509 *x)
{
if(x->aux && x->aux->reject) {
sk_ASN1_OBJECT_pop_free(x->aux->reject, ASN1_OBJECT_free);
x->aux->reject = NULL;
}
}
