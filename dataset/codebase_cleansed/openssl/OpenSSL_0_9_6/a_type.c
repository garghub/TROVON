int i2d_ASN1_TYPE(ASN1_TYPE *a, unsigned char **pp)
{
int r=0;
if (a == NULL) return(0);
switch (a->type)
{
case V_ASN1_NULL:
if (pp != NULL)
ASN1_put_object(pp,0,0,V_ASN1_NULL,V_ASN1_UNIVERSAL);
r=2;
break;
case V_ASN1_INTEGER:
case V_ASN1_NEG_INTEGER:
r=i2d_ASN1_INTEGER(a->value.integer,pp);
break;
case V_ASN1_ENUMERATED:
case V_ASN1_NEG_ENUMERATED:
r=i2d_ASN1_ENUMERATED(a->value.enumerated,pp);
break;
case V_ASN1_BIT_STRING:
r=i2d_ASN1_BIT_STRING(a->value.bit_string,pp);
break;
case V_ASN1_OCTET_STRING:
r=i2d_ASN1_OCTET_STRING(a->value.octet_string,pp);
break;
case V_ASN1_OBJECT:
r=i2d_ASN1_OBJECT(a->value.object,pp);
break;
case V_ASN1_PRINTABLESTRING:
r=M_i2d_ASN1_PRINTABLESTRING(a->value.printablestring,pp);
break;
case V_ASN1_T61STRING:
r=M_i2d_ASN1_T61STRING(a->value.t61string,pp);
break;
case V_ASN1_IA5STRING:
r=M_i2d_ASN1_IA5STRING(a->value.ia5string,pp);
break;
case V_ASN1_GENERALSTRING:
r=M_i2d_ASN1_GENERALSTRING(a->value.generalstring,pp);
break;
case V_ASN1_UNIVERSALSTRING:
r=M_i2d_ASN1_UNIVERSALSTRING(a->value.universalstring,pp);
break;
case V_ASN1_UTF8STRING:
r=M_i2d_ASN1_UTF8STRING(a->value.utf8string,pp);
break;
case V_ASN1_VISIBLESTRING:
r=M_i2d_ASN1_VISIBLESTRING(a->value.visiblestring,pp);
break;
case V_ASN1_BMPSTRING:
r=M_i2d_ASN1_BMPSTRING(a->value.bmpstring,pp);
break;
case V_ASN1_UTCTIME:
r=i2d_ASN1_UTCTIME(a->value.utctime,pp);
break;
case V_ASN1_GENERALIZEDTIME:
r=i2d_ASN1_GENERALIZEDTIME(a->value.generalizedtime,pp);
break;
case V_ASN1_SET:
case V_ASN1_SEQUENCE:
case V_ASN1_OTHER:
default:
if (a->value.set == NULL)
r=0;
else
{
r=a->value.set->length;
if (pp != NULL)
{
memcpy(*pp,a->value.set->data,r);
*pp+=r;
}
}
break;
}
return(r);
}
ASN1_TYPE *d2i_ASN1_TYPE(ASN1_TYPE **a, unsigned char **pp, long length)
{
ASN1_TYPE *ret=NULL;
unsigned char *q,*p,*max;
int inf,tag,xclass;
long len;
if ((a == NULL) || ((*a) == NULL))
{
if ((ret=ASN1_TYPE_new()) == NULL) goto err;
}
else
ret=(*a);
p= *pp;
q=p;
max=(p+length);
inf=ASN1_get_object(&q,&len,&tag,&xclass,length);
if (inf & 0x80) goto err;
if(xclass != V_ASN1_UNIVERSAL) tag = V_ASN1_OTHER;
ASN1_TYPE_component_free(ret);
switch (tag)
{
case V_ASN1_NULL:
p=q;
ret->value.ptr=NULL;
break;
case V_ASN1_INTEGER:
if ((ret->value.integer=
d2i_ASN1_INTEGER(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_ENUMERATED:
if ((ret->value.enumerated=
d2i_ASN1_ENUMERATED(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_BIT_STRING:
if ((ret->value.bit_string=
d2i_ASN1_BIT_STRING(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_OCTET_STRING:
if ((ret->value.octet_string=
d2i_ASN1_OCTET_STRING(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_VISIBLESTRING:
if ((ret->value.visiblestring=
d2i_ASN1_VISIBLESTRING(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_UTF8STRING:
if ((ret->value.utf8string=
d2i_ASN1_UTF8STRING(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_OBJECT:
if ((ret->value.object=
d2i_ASN1_OBJECT(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_PRINTABLESTRING:
if ((ret->value.printablestring=
d2i_ASN1_PRINTABLESTRING(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_T61STRING:
if ((ret->value.t61string=
M_d2i_ASN1_T61STRING(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_IA5STRING:
if ((ret->value.ia5string=
M_d2i_ASN1_IA5STRING(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_GENERALSTRING:
if ((ret->value.generalstring=
M_d2i_ASN1_GENERALSTRING(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_UNIVERSALSTRING:
if ((ret->value.universalstring=
M_d2i_ASN1_UNIVERSALSTRING(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_BMPSTRING:
if ((ret->value.bmpstring=
M_d2i_ASN1_BMPSTRING(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_UTCTIME:
if ((ret->value.utctime=
d2i_ASN1_UTCTIME(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_GENERALIZEDTIME:
if ((ret->value.generalizedtime=
d2i_ASN1_GENERALIZEDTIME(NULL,&p,max-p)) == NULL)
goto err;
break;
case V_ASN1_SET:
case V_ASN1_SEQUENCE:
case V_ASN1_OTHER:
default:
if ((ret->value.set=ASN1_STRING_new()) == NULL) goto err;
ret->value.set->type=tag;
len+=(q-p);
if (!ASN1_STRING_set(ret->value.set,p,(int)len)) goto err;
p+=len;
break;
}
ret->type=tag;
if (a != NULL) (*a)=ret;
*pp=p;
return(ret);
err:
if ((ret != NULL) && ((a == NULL) || (*a != ret))) ASN1_TYPE_free(ret);
return(NULL);
}
ASN1_TYPE *ASN1_TYPE_new(void)
{
ASN1_TYPE *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,ASN1_TYPE);
ret->type= -1;
ret->value.ptr=NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_ASN1_TYPE_NEW);
}
void ASN1_TYPE_free(ASN1_TYPE *a)
{
if (a == NULL) return;
ASN1_TYPE_component_free(a);
OPENSSL_free(a);
}
int ASN1_TYPE_get(ASN1_TYPE *a)
{
if (a->value.ptr != NULL)
return(a->type);
else
return(0);
}
void ASN1_TYPE_set(ASN1_TYPE *a, int type, void *value)
{
if (a->value.ptr != NULL)
ASN1_TYPE_component_free(a);
a->type=type;
a->value.ptr=value;
}
static void ASN1_TYPE_component_free(ASN1_TYPE *a)
{
if (a == NULL) return;
if (a->value.ptr != NULL)
{
switch (a->type)
{
case V_ASN1_OBJECT:
ASN1_OBJECT_free(a->value.object);
break;
case V_ASN1_NULL:
break;
case V_ASN1_INTEGER:
case V_ASN1_NEG_INTEGER:
case V_ASN1_ENUMERATED:
case V_ASN1_NEG_ENUMERATED:
case V_ASN1_BIT_STRING:
case V_ASN1_OCTET_STRING:
case V_ASN1_SEQUENCE:
case V_ASN1_SET:
case V_ASN1_NUMERICSTRING:
case V_ASN1_PRINTABLESTRING:
case V_ASN1_T61STRING:
case V_ASN1_VIDEOTEXSTRING:
case V_ASN1_IA5STRING:
case V_ASN1_UTCTIME:
case V_ASN1_GENERALIZEDTIME:
case V_ASN1_GRAPHICSTRING:
case V_ASN1_VISIBLESTRING:
case V_ASN1_GENERALSTRING:
case V_ASN1_UNIVERSALSTRING:
case V_ASN1_BMPSTRING:
case V_ASN1_UTF8STRING:
case V_ASN1_OTHER:
default:
ASN1_STRING_free((ASN1_STRING *)a->value.ptr);
break;
}
a->type=0;
a->value.ptr=NULL;
}
}
