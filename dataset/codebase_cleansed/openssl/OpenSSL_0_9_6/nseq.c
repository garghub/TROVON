int MAIN(int argc, char **argv)
{
char **args, *infile = NULL, *outfile = NULL;
BIO *in = NULL, *out = NULL;
int toseq = 0;
X509 *x509 = NULL;
NETSCAPE_CERT_SEQUENCE *seq = NULL;
int i, ret = 1;
int badarg = 0;
if (bio_err == NULL) bio_err = BIO_new_fp (stderr, BIO_NOCLOSE);
ERR_load_crypto_strings();
args = argv + 1;
while (!badarg && *args && *args[0] == '-') {
if (!strcmp (*args, "-toseq")) toseq = 1;
else if (!strcmp (*args, "-in")) {
if (args[1]) {
args++;
infile = *args;
} else badarg = 1;
} else if (!strcmp (*args, "-out")) {
if (args[1]) {
args++;
outfile = *args;
} else badarg = 1;
} else badarg = 1;
args++;
}
if (badarg) {
BIO_printf (bio_err, "Netscape certificate sequence utility\n");
BIO_printf (bio_err, "Usage nseq [options]\n");
BIO_printf (bio_err, "where options are\n");
BIO_printf (bio_err, "-in file input file\n");
BIO_printf (bio_err, "-out file output file\n");
BIO_printf (bio_err, "-toseq output NS Sequence file\n");
EXIT(1);
}
if (infile) {
if (!(in = BIO_new_file (infile, "r"))) {
BIO_printf (bio_err,
"Can't open input file %s\n", infile);
goto end;
}
} else in = BIO_new_fp(stdin, BIO_NOCLOSE);
if (outfile) {
if (!(out = BIO_new_file (outfile, "w"))) {
BIO_printf (bio_err,
"Can't open output file %s\n", outfile);
goto end;
}
} else {
out = BIO_new_fp(stdout, BIO_NOCLOSE);
#ifdef VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
}
if (toseq) {
seq = NETSCAPE_CERT_SEQUENCE_new();
seq->certs = sk_X509_new_null();
while((x509 = PEM_read_bio_X509(in, NULL, NULL, NULL)))
sk_X509_push(seq->certs,x509);
if(!sk_X509_num(seq->certs))
{
BIO_printf (bio_err, "Error reading certs file %s\n", infile);
ERR_print_errors(bio_err);
goto end;
}
PEM_write_bio_NETSCAPE_CERT_SEQUENCE(out, seq);
ret = 0;
goto end;
}
if (!(seq = PEM_read_bio_NETSCAPE_CERT_SEQUENCE(in, NULL, NULL, NULL))) {
BIO_printf (bio_err, "Error reading sequence file %s\n", infile);
ERR_print_errors(bio_err);
goto end;
}
for(i = 0; i < sk_X509_num(seq->certs); i++) {
x509 = sk_X509_value(seq->certs, i);
dump_cert_text(out, x509);
PEM_write_bio_X509(out, x509);
}
ret = 0;
end:
BIO_free(in);
BIO_free_all(out);
NETSCAPE_CERT_SEQUENCE_free(seq);
EXIT(ret);
}
