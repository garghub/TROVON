int X509V3_EXT_print(BIO *out, X509_EXTENSION *ext, int flag, int indent)
{
char *ext_str = NULL, *value = NULL;
unsigned char *p;
X509V3_EXT_METHOD *method;
STACK_OF(CONF_VALUE) *nval = NULL;
int ok = 1;
if(!(method = X509V3_EXT_get(ext))) return 0;
p = ext->value->data;
if(!(ext_str = method->d2i(NULL, &p, ext->value->length))) return 0;
if(method->i2s) {
if(!(value = method->i2s(method, ext_str))) {
ok = 0;
goto err;
}
BIO_printf(out, "%*s%s", indent, "", value);
} else if(method->i2v) {
if(!(nval = method->i2v(method, ext_str, NULL))) {
ok = 0;
goto err;
}
X509V3_EXT_val_prn(out, nval, indent,
method->ext_flags & X509V3_EXT_MULTILINE);
} else if(method->i2r) {
if(!method->i2r(method, ext_str, out, indent)) ok = 0;
} else ok = 0;
err:
sk_CONF_VALUE_pop_free(nval, X509V3_conf_free);
if(value) Free(value);
method->ext_free(ext_str);
return ok;
}
int X509V3_EXT_print_fp(FILE *fp, X509_EXTENSION *ext, int flag, int indent)
{
BIO *bio_tmp;
int ret;
if(!(bio_tmp = BIO_new_fp(fp, BIO_NOCLOSE))) return 0;
ret = X509V3_EXT_print(bio_tmp, ext, flag, indent);
BIO_free(bio_tmp);
return ret;
}
