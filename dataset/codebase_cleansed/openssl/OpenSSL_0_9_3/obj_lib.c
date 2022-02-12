ASN1_OBJECT *OBJ_dup(ASN1_OBJECT *o)
{
ASN1_OBJECT *r;
int i;
char *ln=NULL;
if (o == NULL) return(NULL);
if (!(o->flags & ASN1_OBJECT_FLAG_DYNAMIC))
return(o);
r=ASN1_OBJECT_new();
if (r == NULL)
{
OBJerr(OBJ_F_OBJ_DUP,ERR_R_ASN1_LIB);
return(NULL);
}
r->data=Malloc(o->length);
if (r->data == NULL)
goto err;
memcpy(r->data,o->data,o->length);
r->length=o->length;
r->nid=o->nid;
r->ln=r->sn=NULL;
if (o->ln != NULL)
{
i=strlen(o->ln)+1;
r->ln=ln=Malloc(i);
if (r->ln == NULL) goto err;
memcpy(ln,o->ln,i);
}
if (o->sn != NULL)
{
char *s;
i=strlen(o->sn)+1;
r->sn=s=Malloc(i);
if (r->sn == NULL) goto err;
memcpy(s,o->sn,i);
}
r->flags=o->flags|(ASN1_OBJECT_FLAG_DYNAMIC|
ASN1_OBJECT_FLAG_DYNAMIC_STRINGS|ASN1_OBJECT_FLAG_DYNAMIC_DATA);
return(r);
err:
OBJerr(OBJ_F_OBJ_DUP,ERR_R_MALLOC_FAILURE);
if (r != NULL)
{
if (ln != NULL) Free(ln);
if (r->data != NULL) Free(r->data);
Free(r);
}
return(NULL);
}
int OBJ_cmp(ASN1_OBJECT *a, ASN1_OBJECT *b)
{
int ret;
ret=(a->length-b->length);
if (ret) return(ret);
return(memcmp(a->data,b->data,a->length));
}
