int X509_CERT_AUX_print(BIO *out, X509_CERT_AUX *aux, int indent)
{
char oidstr[80], first;
int i;
if(!aux) return 1;
if(aux->trust) {
first = 1;
BIO_printf(out, "%*sTrusted Uses:\n%*s",
indent, "", indent + 2, "");
for(i = 0; i < sk_ASN1_OBJECT_num(aux->trust); i++) {
if(!first) BIO_puts(out, ", ");
else first = 0;
OBJ_obj2txt(oidstr, 80,
sk_ASN1_OBJECT_value(aux->trust, i), 0);
BIO_puts(out, oidstr);
}
BIO_puts(out, "\n");
} else BIO_printf(out, "%*sNo Trusted Uses.\n", indent, "");
if(aux->reject) {
first = 1;
BIO_printf(out, "%*sRejected Uses:\n%*s",
indent, "", indent + 2, "");
for(i = 0; i < sk_ASN1_OBJECT_num(aux->reject); i++) {
if(!first) BIO_puts(out, ", ");
else first = 0;
OBJ_obj2txt(oidstr, 80,
sk_ASN1_OBJECT_value(aux->reject, i), 0);
BIO_puts(out, oidstr);
}
BIO_puts(out, "\n");
} else BIO_printf(out, "%*sNo Rejected Uses.\n", indent, "");
if(aux->alias) BIO_printf(out, "%*sAlias: %s\n", indent, "",
aux->alias->data);
return 1;
}
