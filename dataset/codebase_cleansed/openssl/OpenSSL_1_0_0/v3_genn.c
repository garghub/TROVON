int GENERAL_NAME_cmp(GENERAL_NAME *a, GENERAL_NAME *b)
{
int result = -1;
if (!a || !b || a->type != b->type) return -1;
switch(a->type)
{
case GEN_X400:
case GEN_EDIPARTY:
result = ASN1_TYPE_cmp(a->d.other, b->d.other);
break;
case GEN_OTHERNAME:
result = OTHERNAME_cmp(a->d.otherName, b->d.otherName);
break;
case GEN_EMAIL:
case GEN_DNS:
case GEN_URI:
result = ASN1_STRING_cmp(a->d.ia5, b->d.ia5);
break;
case GEN_DIRNAME:
result = X509_NAME_cmp(a->d.dirn, b->d.dirn);
break;
case GEN_IPADD:
result = ASN1_OCTET_STRING_cmp(a->d.ip, b->d.ip);
break;
case GEN_RID:
result = OBJ_cmp(a->d.rid, b->d.rid);
break;
}
return result;
}
int OTHERNAME_cmp(OTHERNAME *a, OTHERNAME *b)
{
int result = -1;
if (!a || !b) return -1;
if ((result = OBJ_cmp(a->type_id, b->type_id)) != 0)
return result;
result = ASN1_TYPE_cmp(a->value, b->value);
return result;
}
void GENERAL_NAME_set0_value(GENERAL_NAME *a, int type, void *value)
{
switch(type)
{
case GEN_X400:
case GEN_EDIPARTY:
a->d.other = value;
break;
case GEN_OTHERNAME:
a->d.otherName = value;
break;
case GEN_EMAIL:
case GEN_DNS:
case GEN_URI:
a->d.ia5 = value;
break;
case GEN_DIRNAME:
a->d.dirn = value;
break;
case GEN_IPADD:
a->d.ip = value;
break;
case GEN_RID:
a->d.rid = value;
break;
}
a->type = type;
}
void *GENERAL_NAME_get0_value(GENERAL_NAME *a, int *ptype)
{
if (ptype)
*ptype = a->type;
switch(a->type)
{
case GEN_X400:
case GEN_EDIPARTY:
return a->d.other;
case GEN_OTHERNAME:
return a->d.otherName;
case GEN_EMAIL:
case GEN_DNS:
case GEN_URI:
return a->d.ia5;
case GEN_DIRNAME:
return a->d.dirn;
case GEN_IPADD:
return a->d.ip;
case GEN_RID:
return a->d.rid;
default:
return NULL;
}
}
int GENERAL_NAME_set0_othername(GENERAL_NAME *gen,
ASN1_OBJECT *oid, ASN1_TYPE *value)
{
OTHERNAME *oth;
oth = OTHERNAME_new();
if (!oth)
return 0;
oth->type_id = oid;
oth->value = value;
GENERAL_NAME_set0_value(gen, GEN_OTHERNAME, oth);
return 1;
}
int GENERAL_NAME_get0_otherName(GENERAL_NAME *gen,
ASN1_OBJECT **poid, ASN1_TYPE **pvalue)
{
if (gen->type != GEN_OTHERNAME)
return 0;
if (poid)
*poid = gen->d.otherName->type_id;
if (pvalue)
*pvalue = gen->d.otherName->value;
return 1;
}
