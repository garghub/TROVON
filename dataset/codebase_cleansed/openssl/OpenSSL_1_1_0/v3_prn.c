int X509V3_EXT_print(BIO *out, X509_EXTENSION *ext, unsigned long flag,
int indent)
{
void *ext_str = NULL;
char *value = NULL;
ASN1_OCTET_STRING *extoct;
const unsigned char *p;
int extlen;
const X509V3_EXT_METHOD *method;
STACK_OF(CONF_VALUE) *nval = NULL;
int ok = 1;
extoct = X509_EXTENSION_get_data(ext);
p = ASN1_STRING_get0_data(extoct);
extlen = ASN1_STRING_length(extoct);
if ((method = X509V3_EXT_get(ext)) == NULL)
return unknown_ext_print(out, p, extlen, flag, indent, 0);
if (method->it)
ext_str = ASN1_item_d2i(NULL, &p, extlen, ASN1_ITEM_ptr(method->it));
else
ext_str = method->d2i(NULL, &p, extlen);
if (!ext_str)
return unknown_ext_print(out, p, extlen, flag, indent, 1);
if (method->i2s) {
if ((value = method->i2s(method, ext_str)) == NULL) {
ok = 0;
goto err;
}
#ifndef CHARSET_EBCDIC
BIO_printf(out, "%*s%s", indent, "", value);
#else
{
int len;
char *tmp;
len = strlen(value) + 1;
tmp = OPENSSL_malloc(len);
if (tmp != NULL) {
ascii2ebcdic(tmp, value, len);
BIO_printf(out, "%*s%s", indent, "", tmp);
OPENSSL_free(tmp);
}
}
#endif
} else if (method->i2v) {
if ((nval = method->i2v(method, ext_str, NULL)) == NULL) {
ok = 0;
goto err;
}
X509V3_EXT_val_prn(out, nval, indent,
method->ext_flags & X509V3_EXT_MULTILINE);
} else if (method->i2r) {
if (!method->i2r(method, ext_str, out, indent))
ok = 0;
} else
ok = 0;
err:
sk_CONF_VALUE_pop_free(nval, X509V3_conf_free);
OPENSSL_free(value);
if (method->it)
ASN1_item_free(ext_str, ASN1_ITEM_ptr(method->it));
else
method->ext_free(ext_str);
return ok;
}
static int unknown_ext_print(BIO *out, const unsigned char *ext, int extlen,
unsigned long flag, int indent, int supported)
{
switch (flag & X509V3_EXT_UNKNOWN_MASK) {
case X509V3_EXT_DEFAULT:
return 0;
case X509V3_EXT_ERROR_UNKNOWN:
if (supported)
BIO_printf(out, "%*s<Parse Error>", indent, "");
else
BIO_printf(out, "%*s<Not Supported>", indent, "");
return 1;
case X509V3_EXT_PARSE_UNKNOWN:
return ASN1_parse_dump(out, ext, extlen, indent, -1);
case X509V3_EXT_DUMP_UNKNOWN:
return BIO_dump_indent(out, (const char *)ext, extlen, indent);
default:
return 1;
}
}
int X509V3_EXT_print_fp(FILE *fp, X509_EXTENSION *ext, int flag, int indent)
{
BIO *bio_tmp;
int ret;
if ((bio_tmp = BIO_new_fp(fp, BIO_NOCLOSE)) == NULL)
return 0;
ret = X509V3_EXT_print(bio_tmp, ext, flag, indent);
BIO_free(bio_tmp);
return ret;
}
