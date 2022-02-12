ASN1_STRING *d2i_ASN1_type_bytes(ASN1_STRING **a, const unsigned char **pp,
long length, int type)
{
ASN1_STRING *ret = NULL;
const unsigned char *p;
unsigned char *s;
long len;
int inf, tag, xclass;
int i = 0;
p = *pp;
inf = ASN1_get_object(&p, &len, &tag, &xclass, length);
if (inf & 0x80)
goto err;
if (tag >= 32) {
i = ASN1_R_TAG_VALUE_TOO_HIGH;
goto err;
}
if (!(ASN1_tag2bit(tag) & type)) {
i = ASN1_R_WRONG_TYPE;
goto err;
}
if (tag == V_ASN1_BIT_STRING)
return (d2i_ASN1_BIT_STRING(a, pp, length));
if ((a == NULL) || ((*a) == NULL)) {
if ((ret = ASN1_STRING_new()) == NULL)
return (NULL);
} else
ret = (*a);
if (len != 0) {
s = (unsigned char *)OPENSSL_malloc((int)len + 1);
if (s == NULL) {
i = ERR_R_MALLOC_FAILURE;
goto err;
}
memcpy(s, p, (int)len);
s[len] = '\0';
p += len;
} else
s = NULL;
if (ret->data != NULL)
OPENSSL_free(ret->data);
ret->length = (int)len;
ret->data = s;
ret->type = tag;
if (a != NULL)
(*a) = ret;
*pp = p;
return (ret);
err:
ASN1err(ASN1_F_D2I_ASN1_TYPE_BYTES, i);
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
ASN1_STRING_free(ret);
return (NULL);
}
int i2d_ASN1_bytes(ASN1_STRING *a, unsigned char **pp, int tag, int xclass)
{
int ret, r, constructed;
unsigned char *p;
if (a == NULL)
return (0);
if (tag == V_ASN1_BIT_STRING)
return (i2d_ASN1_BIT_STRING(a, pp));
ret = a->length;
r = ASN1_object_size(0, ret, tag);
if (pp == NULL)
return (r);
p = *pp;
if ((tag == V_ASN1_SEQUENCE) || (tag == V_ASN1_SET))
constructed = 1;
else
constructed = 0;
ASN1_put_object(&p, constructed, ret, tag, xclass);
memcpy(p, a->data, a->length);
p += a->length;
*pp = p;
return (r);
}
ASN1_STRING *d2i_ASN1_bytes(ASN1_STRING **a, const unsigned char **pp,
long length, int Ptag, int Pclass)
{
ASN1_STRING *ret = NULL;
const unsigned char *p;
unsigned char *s;
long len;
int inf, tag, xclass;
int i = 0;
if ((a == NULL) || ((*a) == NULL)) {
if ((ret = ASN1_STRING_new()) == NULL)
return (NULL);
} else
ret = (*a);
p = *pp;
inf = ASN1_get_object(&p, &len, &tag, &xclass, length);
if (inf & 0x80) {
i = ASN1_R_BAD_OBJECT_HEADER;
goto err;
}
if (tag != Ptag) {
i = ASN1_R_WRONG_TAG;
goto err;
}
if (inf & V_ASN1_CONSTRUCTED) {
ASN1_const_CTX c;
c.pp = pp;
c.p = p;
c.inf = inf;
c.slen = len;
c.tag = Ptag;
c.xclass = Pclass;
c.max = (length == 0) ? 0 : (p + length);
if (!asn1_collate_primitive(ret, &c))
goto err;
else {
p = c.p;
}
} else {
if (len != 0) {
if ((ret->length < len) || (ret->data == NULL)) {
if (ret->data != NULL)
OPENSSL_free(ret->data);
s = (unsigned char *)OPENSSL_malloc((int)len + 1);
if (s == NULL) {
i = ERR_R_MALLOC_FAILURE;
goto err;
}
} else
s = ret->data;
memcpy(s, p, (int)len);
s[len] = '\0';
p += len;
} else {
s = NULL;
if (ret->data != NULL)
OPENSSL_free(ret->data);
}
ret->length = (int)len;
ret->data = s;
ret->type = Ptag;
}
if (a != NULL)
(*a) = ret;
*pp = p;
return (ret);
err:
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
ASN1_STRING_free(ret);
ASN1err(ASN1_F_D2I_ASN1_BYTES, i);
return (NULL);
}
static int asn1_collate_primitive(ASN1_STRING *a, ASN1_const_CTX *c)
{
ASN1_STRING *os = NULL;
BUF_MEM b;
int num;
b.length = 0;
b.max = 0;
b.data = NULL;
if (a == NULL) {
c->error = ERR_R_PASSED_NULL_PARAMETER;
goto err;
}
num = 0;
for (;;) {
if (c->inf & 1) {
c->eos = ASN1_const_check_infinite_end(&c->p,
(long)(c->max - c->p));
if (c->eos)
break;
} else {
if (c->slen <= 0)
break;
}
c->q = c->p;
if (d2i_ASN1_bytes(&os, &c->p, c->max - c->p, c->tag, c->xclass)
== NULL) {
c->error = ERR_R_ASN1_LIB;
goto err;
}
if (!BUF_MEM_grow_clean(&b, num + os->length)) {
c->error = ERR_R_BUF_LIB;
goto err;
}
memcpy(&(b.data[num]), os->data, os->length);
if (!(c->inf & 1))
c->slen -= (c->p - c->q);
num += os->length;
}
if (!asn1_const_Finish(c))
goto err;
a->length = num;
if (a->data != NULL)
OPENSSL_free(a->data);
a->data = (unsigned char *)b.data;
if (os != NULL)
ASN1_STRING_free(os);
return (1);
err:
ASN1err(ASN1_F_ASN1_COLLATE_PRIMITIVE, c->error);
if (os != NULL)
ASN1_STRING_free(os);
if (b.data != NULL)
OPENSSL_free(b.data);
return (0);
}
