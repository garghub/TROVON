static void print_notice(BIO *out, USERNOTICE *notice, int indent)
{
int i;
if(notice->noticeref) {
NOTICEREF *ref;
ref = notice->noticeref;
BIO_printf(out, "%*sOrganization: %s\n", indent, "",
ref->organization->data);
BIO_printf(out, "%*sNumber%s: ", indent, "",
sk_ASN1_INTEGER_num(ref->noticenos) > 1 ? "s" : "");
for(i = 0; i < sk_ASN1_INTEGER_num(ref->noticenos); i++) {
ASN1_INTEGER *num;
char *tmp;
num = sk_ASN1_INTEGER_value(ref->noticenos, i);
if(i) BIO_puts(out, ", ");
tmp = i2s_ASN1_INTEGER(NULL, num);
BIO_puts(out, tmp);
OPENSSL_free(tmp);
}
BIO_puts(out, "\n");
}
if(notice->exptext)
BIO_printf(out, "%*sExplicit Text: %s\n", indent, "",
notice->exptext->data);
}
