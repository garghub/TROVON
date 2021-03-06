static X509_CERT_AUX *aux_get(X509 *x)
{
if (x == NULL)
return NULL;
if (x->aux == NULL && (x->aux = X509_CERT_AUX_new()) == NULL)
return NULL;
return x->aux;
}
int X509_alias_set1(X509 *x, const unsigned char *name, int len)
{
X509_CERT_AUX *aux;
if (!name) {
if (!x || !x->aux || !x->aux->alias)
return 1;
ASN1_UTF8STRING_free(x->aux->alias);
x->aux->alias = NULL;
return 1;
}
if ((aux = aux_get(x)) == NULL)
return 0;
if (aux->alias == NULL && (aux->alias = ASN1_UTF8STRING_new()) == NULL)
return 0;
return ASN1_STRING_set(aux->alias, name, len);
}
int X509_keyid_set1(X509 *x, const unsigned char *id, int len)
{
X509_CERT_AUX *aux;
if (!id) {
if (!x || !x->aux || !x->aux->keyid)
return 1;
ASN1_OCTET_STRING_free(x->aux->keyid);
x->aux->keyid = NULL;
return 1;
}
if ((aux = aux_get(x)) == NULL)
return 0;
if (aux->keyid == NULL
&& (aux->keyid = ASN1_OCTET_STRING_new()) == NULL)
return 0;
return ASN1_STRING_set(aux->keyid, id, len);
}
unsigned char *X509_alias_get0(X509 *x, int *len)
{
if (!x->aux || !x->aux->alias)
return NULL;
if (len)
*len = x->aux->alias->length;
return x->aux->alias->data;
}
unsigned char *X509_keyid_get0(X509 *x, int *len)
{
if (!x->aux || !x->aux->keyid)
return NULL;
if (len)
*len = x->aux->keyid->length;
return x->aux->keyid->data;
}
int X509_add1_trust_object(X509 *x, const ASN1_OBJECT *obj)
{
X509_CERT_AUX *aux;
ASN1_OBJECT *objtmp = NULL;
if (obj) {
objtmp = OBJ_dup(obj);
if (!objtmp)
return 0;
}
if ((aux = aux_get(x)) == NULL)
goto err;
if (aux->trust == NULL
&& (aux->trust = sk_ASN1_OBJECT_new_null()) == NULL)
goto err;
if (!objtmp || sk_ASN1_OBJECT_push(aux->trust, objtmp))
return 1;
err:
ASN1_OBJECT_free(objtmp);
return 0;
}
int X509_add1_reject_object(X509 *x, const ASN1_OBJECT *obj)
{
X509_CERT_AUX *aux;
ASN1_OBJECT *objtmp;
if ((objtmp = OBJ_dup(obj)) == NULL)
return 0;
if ((aux = aux_get(x)) == NULL)
goto err;
if (aux->reject == NULL
&& (aux->reject = sk_ASN1_OBJECT_new_null()) == NULL)
goto err;
return sk_ASN1_OBJECT_push(aux->reject, objtmp);
err:
ASN1_OBJECT_free(objtmp);
return 0;
}
void X509_trust_clear(X509 *x)
{
if (x->aux) {
sk_ASN1_OBJECT_pop_free(x->aux->trust, ASN1_OBJECT_free);
x->aux->trust = NULL;
}
}
void X509_reject_clear(X509 *x)
{
if (x->aux) {
sk_ASN1_OBJECT_pop_free(x->aux->reject, ASN1_OBJECT_free);
x->aux->reject = NULL;
}
}
