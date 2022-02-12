int ASN1_TYPE_get(ASN1_TYPE *a)
{
if ((a->value.ptr != NULL) || (a->type == V_ASN1_NULL))
return(a->type);
else
return(0);
}
void ASN1_TYPE_set(ASN1_TYPE *a, int type, void *value)
{
if (a->value.ptr != NULL)
ASN1_primitive_free((ASN1_VALUE **)&a, NULL);
a->type=type;
a->value.ptr=value;
}
