int pkcs7_main(int argc, char **argv)
{
PKCS7 *p7 = NULL;
BIO *in = NULL, *out = NULL;
int informat = FORMAT_PEM, outformat = FORMAT_PEM;
char *infile = NULL, *outfile = NULL, *prog;
int i, print_certs = 0, text = 0, noout = 0, p7_print = 0, ret = 1;
OPTION_CHOICE o;
prog = opt_init(argc, argv, pkcs7_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(pkcs7_options);
ret = 0;
goto end;
case OPT_INFORM:
if (!opt_format(opt_arg(), OPT_FMT_PEMDER, &informat))
goto opthelp;
break;
case OPT_OUTFORM:
if (!opt_format(opt_arg(), OPT_FMT_PEMDER, &outformat))
goto opthelp;
break;
case OPT_IN:
infile = opt_arg();
break;
case OPT_OUT:
outfile = opt_arg();
break;
case OPT_NOOUT:
noout = 1;
break;
case OPT_TEXT:
text = 1;
break;
case OPT_PRINT:
p7_print = 1;
break;
case OPT_PRINT_CERTS:
print_certs = 1;
break;
case OPT_ENGINE:
(void)setup_engine(opt_arg(), 0);
break;
}
}
argc = opt_num_rest();
if (argc != 0)
goto opthelp;
in = bio_open_default(infile, 'r', informat);
if (in == NULL)
goto end;
if (informat == FORMAT_ASN1)
p7 = d2i_PKCS7_bio(in, NULL);
else
p7 = PEM_read_bio_PKCS7(in, NULL, NULL, NULL);
if (p7 == NULL) {
BIO_printf(bio_err, "unable to load PKCS7 object\n");
ERR_print_errors(bio_err);
goto end;
}
out = bio_open_default(outfile, 'w', outformat);
if (out == NULL)
goto end;
if (p7_print)
PKCS7_print_ctx(out, p7, 0, NULL);
if (print_certs) {
STACK_OF(X509) *certs = NULL;
STACK_OF(X509_CRL) *crls = NULL;
i = OBJ_obj2nid(p7->type);
switch (i) {
case NID_pkcs7_signed:
if (p7->d.sign != NULL) {
certs = p7->d.sign->cert;
crls = p7->d.sign->crl;
}
break;
case NID_pkcs7_signedAndEnveloped:
if (p7->d.signed_and_enveloped != NULL) {
certs = p7->d.signed_and_enveloped->cert;
crls = p7->d.signed_and_enveloped->crl;
}
break;
default:
break;
}
if (certs != NULL) {
X509 *x;
for (i = 0; i < sk_X509_num(certs); i++) {
x = sk_X509_value(certs, i);
if (text)
X509_print(out, x);
else
dump_cert_text(out, x);
if (!noout)
PEM_write_bio_X509(out, x);
BIO_puts(out, "\n");
}
}
if (crls != NULL) {
X509_CRL *crl;
for (i = 0; i < sk_X509_CRL_num(crls); i++) {
crl = sk_X509_CRL_value(crls, i);
X509_CRL_print(out, crl);
if (!noout)
PEM_write_bio_X509_CRL(out, crl);
BIO_puts(out, "\n");
}
}
ret = 0;
goto end;
}
if (!noout) {
if (outformat == FORMAT_ASN1)
i = i2d_PKCS7_bio(out, p7);
else
i = PEM_write_bio_PKCS7(out, p7);
if (!i) {
BIO_printf(bio_err, "unable to write pkcs7 object\n");
ERR_print_errors(bio_err);
goto end;
}
}
ret = 0;
end:
PKCS7_free(p7);
BIO_free(in);
BIO_free_all(out);
return (ret);
}
