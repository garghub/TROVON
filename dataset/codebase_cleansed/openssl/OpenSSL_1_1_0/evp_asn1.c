int ASN1_TYPE_set_octetstring(ASN1_TYPE *a, unsigned char *data, int len)
{
ASN1_STRING *os;
if ((os = ASN1_OCTET_STRING_new()) == NULL)
return (0);
if (!ASN1_OCTET_STRING_set(os, data, len)) {
ASN1_OCTET_STRING_free(os);
return 0;
}
ASN1_TYPE_set(a, V_ASN1_OCTET_STRING, os);
return (1);
}
int ASN1_TYPE_get_octetstring(const ASN1_TYPE *a, unsigned char *data, int max_len)
{
int ret, num;
const unsigned char *p;
if ((a->type != V_ASN1_OCTET_STRING) || (a->value.octet_string == NULL)) {
ASN1err(ASN1_F_ASN1_TYPE_GET_OCTETSTRING, ASN1_R_DATA_IS_WRONG);
return (-1);
}
p = ASN1_STRING_get0_data(a->value.octet_string);
ret = ASN1_STRING_length(a->value.octet_string);
if (ret < max_len)
num = ret;
else
num = max_len;
memcpy(data, p, num);
return (ret);
}
