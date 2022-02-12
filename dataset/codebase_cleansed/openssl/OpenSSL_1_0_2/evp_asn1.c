int ASN1_TYPE_set_octetstring(ASN1_TYPE *a, unsigned char *data, int len)
{
ASN1_STRING *os;
if ((os = M_ASN1_OCTET_STRING_new()) == NULL)
return (0);
if (!M_ASN1_OCTET_STRING_set(os, data, len)) {
M_ASN1_OCTET_STRING_free(os);
return 0;
}
ASN1_TYPE_set(a, V_ASN1_OCTET_STRING, os);
return (1);
}
int ASN1_TYPE_get_octetstring(ASN1_TYPE *a, unsigned char *data, int max_len)
{
int ret, num;
unsigned char *p;
if ((a->type != V_ASN1_OCTET_STRING) || (a->value.octet_string == NULL)) {
ASN1err(ASN1_F_ASN1_TYPE_GET_OCTETSTRING, ASN1_R_DATA_IS_WRONG);
return (-1);
}
p = M_ASN1_STRING_data(a->value.octet_string);
ret = M_ASN1_STRING_length(a->value.octet_string);
if (ret < max_len)
num = ret;
else
num = max_len;
memcpy(data, p, num);
return (ret);
}
int ASN1_TYPE_set_int_octetstring(ASN1_TYPE *a, long num, unsigned char *data,
int len)
{
int n, size;
ASN1_OCTET_STRING os, *osp;
ASN1_INTEGER in;
unsigned char *p;
unsigned char buf[32];
in.data = buf;
in.length = 32;
os.data = data;
os.type = V_ASN1_OCTET_STRING;
os.length = len;
ASN1_INTEGER_set(&in, num);
n = i2d_ASN1_INTEGER(&in, NULL);
n += M_i2d_ASN1_OCTET_STRING(&os, NULL);
size = ASN1_object_size(1, n, V_ASN1_SEQUENCE);
if ((osp = ASN1_STRING_new()) == NULL)
return (0);
if (!ASN1_STRING_set(osp, NULL, size)) {
ASN1_STRING_free(osp);
return (0);
}
M_ASN1_STRING_length_set(osp, size);
p = M_ASN1_STRING_data(osp);
ASN1_put_object(&p, 1, n, V_ASN1_SEQUENCE, V_ASN1_UNIVERSAL);
i2d_ASN1_INTEGER(&in, &p);
M_i2d_ASN1_OCTET_STRING(&os, &p);
ASN1_TYPE_set(a, V_ASN1_SEQUENCE, osp);
return (1);
}
int ASN1_TYPE_get_int_octetstring(ASN1_TYPE *a, long *num,
unsigned char *data, int max_len)
{
int ret = -1, n;
ASN1_INTEGER *ai = NULL;
ASN1_OCTET_STRING *os = NULL;
const unsigned char *p;
long length;
ASN1_const_CTX c;
if ((a->type != V_ASN1_SEQUENCE) || (a->value.sequence == NULL)) {
goto err;
}
p = M_ASN1_STRING_data(a->value.sequence);
length = M_ASN1_STRING_length(a->value.sequence);
c.pp = &p;
c.p = p;
c.max = p + length;
c.error = ASN1_R_DATA_IS_WRONG;
M_ASN1_D2I_start_sequence();
c.q = c.p;
if ((ai = d2i_ASN1_INTEGER(NULL, &c.p, c.slen)) == NULL)
goto err;
c.slen -= (c.p - c.q);
c.q = c.p;
if ((os = d2i_ASN1_OCTET_STRING(NULL, &c.p, c.slen)) == NULL)
goto err;
c.slen -= (c.p - c.q);
if (!M_ASN1_D2I_end_sequence())
goto err;
if (num != NULL)
*num = ASN1_INTEGER_get(ai);
ret = M_ASN1_STRING_length(os);
if (max_len > ret)
n = ret;
else
n = max_len;
if (data != NULL)
memcpy(data, M_ASN1_STRING_data(os), n);
if (0) {
err:
ASN1err(ASN1_F_ASN1_TYPE_GET_INT_OCTETSTRING, ASN1_R_DATA_IS_WRONG);
}
if (os != NULL)
M_ASN1_OCTET_STRING_free(os);
if (ai != NULL)
M_ASN1_INTEGER_free(ai);
return (ret);
}
