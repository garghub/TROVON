ASN1_OBJECT *OBJ_dup(const ASN1_OBJECT *o)
{
ASN1_OBJECT *r;
if (o == NULL)
return NULL;
if (!(o->flags & ASN1_OBJECT_FLAG_DYNAMIC))
return ((ASN1_OBJECT *)o);
r = ASN1_OBJECT_new();
if (r == NULL) {
OBJerr(OBJ_F_OBJ_DUP, ERR_R_ASN1_LIB);
return (NULL);
}
r->flags = o->flags | (ASN1_OBJECT_FLAG_DYNAMIC |
ASN1_OBJECT_FLAG_DYNAMIC_STRINGS |
ASN1_OBJECT_FLAG_DYNAMIC_DATA);
if (o->length > 0 && (r->data = OPENSSL_memdup(o->data, o->length)) == NULL)
goto err;
r->length = o->length;
r->nid = o->nid;
if (o->ln != NULL && (r->ln = OPENSSL_strdup(o->ln)) == NULL)
goto err;
if (o->sn != NULL && (r->sn = OPENSSL_strdup(o->sn)) == NULL)
goto err;
return r;
err:
ASN1_OBJECT_free(r);
OBJerr(OBJ_F_OBJ_DUP, ERR_R_MALLOC_FAILURE);
return NULL;
}
int OBJ_cmp(const ASN1_OBJECT *a, const ASN1_OBJECT *b)
{
int ret;
ret = (a->length - b->length);
if (ret)
return (ret);
return (memcmp(a->data, b->data, a->length));
}
