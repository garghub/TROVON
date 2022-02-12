int dhparam_main(int argc, char **argv)
{
BIO *in = NULL, *out = NULL;
DH *dh = NULL;
char *infile = NULL, *outfile = NULL, *prog, *inrand = NULL;
#ifndef OPENSSL_NO_DSA
int dsaparam = 0;
#endif
int i, text = 0, C = 0, ret = 1, num = 0, g = 0;
int informat = FORMAT_PEM, outformat = FORMAT_PEM, check = 0, noout = 0;
OPTION_CHOICE o;
prog = opt_init(argc, argv, dhparam_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(dhparam_options);
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
case OPT_ENGINE:
(void)setup_engine(opt_arg(), 0);
break;
case OPT_CHECK:
check = 1;
break;
case OPT_TEXT:
text = 1;
break;
case OPT_DSAPARAM:
#ifndef OPENSSL_NO_DSA
dsaparam = 1;
#endif
break;
case OPT_C:
C = 1;
break;
case OPT_2:
g = 2;
break;
case OPT_5:
g = 5;
break;
case OPT_NOOUT:
noout = 1;
break;
case OPT_RAND:
inrand = opt_arg();
break;
}
}
argc = opt_num_rest();
argv = opt_rest();
if (argv[0] && (!opt_int(argv[0], &num) || num <= 0))
goto end;
if (g && !num)
num = DEFBITS;
# ifndef OPENSSL_NO_DSA
if (dsaparam && g) {
BIO_printf(bio_err,
"generator may not be chosen for DSA parameters\n");
goto end;
}
# endif
if (num && !g)
g = 2;
if (num) {
BN_GENCB *cb;
cb = BN_GENCB_new();
if (cb == NULL) {
ERR_print_errors(bio_err);
goto end;
}
BN_GENCB_set(cb, dh_cb, bio_err);
if (!app_RAND_load_file(NULL, 1) && inrand == NULL) {
BIO_printf(bio_err,
"warning, not much extra random data, consider using the -rand option\n");
}
if (inrand != NULL)
BIO_printf(bio_err, "%ld semi-random bytes loaded\n",
app_RAND_load_files(inrand));
# ifndef OPENSSL_NO_DSA
if (dsaparam) {
DSA *dsa = DSA_new();
BIO_printf(bio_err,
"Generating DSA parameters, %d bit long prime\n", num);
if (dsa == NULL
|| !DSA_generate_parameters_ex(dsa, num, NULL, 0, NULL, NULL,
cb)) {
DSA_free(dsa);
BN_GENCB_free(cb);
ERR_print_errors(bio_err);
goto end;
}
dh = DSA_dup_DH(dsa);
DSA_free(dsa);
if (dh == NULL) {
BN_GENCB_free(cb);
ERR_print_errors(bio_err);
goto end;
}
} else
# endif
{
dh = DH_new();
BIO_printf(bio_err,
"Generating DH parameters, %d bit long safe prime, generator %d\n",
num, g);
BIO_printf(bio_err, "This is going to take a long time\n");
if (dh == NULL || !DH_generate_parameters_ex(dh, num, g, cb)) {
BN_GENCB_free(cb);
ERR_print_errors(bio_err);
goto end;
}
}
BN_GENCB_free(cb);
app_RAND_write_file(NULL);
} else {
in = bio_open_default(infile, 'r', informat);
if (in == NULL)
goto end;
# ifndef OPENSSL_NO_DSA
if (dsaparam) {
DSA *dsa;
if (informat == FORMAT_ASN1)
dsa = d2i_DSAparams_bio(in, NULL);
else
dsa = PEM_read_bio_DSAparams(in, NULL, NULL, NULL);
if (dsa == NULL) {
BIO_printf(bio_err, "unable to load DSA parameters\n");
ERR_print_errors(bio_err);
goto end;
}
dh = DSA_dup_DH(dsa);
DSA_free(dsa);
if (dh == NULL) {
ERR_print_errors(bio_err);
goto end;
}
} else
# endif
{
if (informat == FORMAT_ASN1)
dh = d2i_DHparams_bio(in, NULL);
else
dh = PEM_read_bio_DHparams(in, NULL, NULL, NULL);
if (dh == NULL) {
BIO_printf(bio_err, "unable to load DH parameters\n");
ERR_print_errors(bio_err);
goto end;
}
}
}
out = bio_open_default(outfile, 'w', outformat);
if (out == NULL)
goto end;
if (text) {
DHparams_print(out, dh);
}
if (check) {
if (!DH_check(dh, &i)) {
ERR_print_errors(bio_err);
goto end;
}
if (i & DH_CHECK_P_NOT_PRIME)
BIO_printf(bio_err, "WARNING: p value is not prime\n");
if (i & DH_CHECK_P_NOT_SAFE_PRIME)
BIO_printf(bio_err, "WARNING: p value is not a safe prime\n");
if (i & DH_CHECK_Q_NOT_PRIME)
BIO_printf(bio_err, "WARNING: q value is not a prime\n");
if (i & DH_CHECK_INVALID_Q_VALUE)
BIO_printf(bio_err, "WARNING: q value is invalid\n");
if (i & DH_CHECK_INVALID_J_VALUE)
BIO_printf(bio_err, "WARNING: j value is invalid\n");
if (i & DH_UNABLE_TO_CHECK_GENERATOR)
BIO_printf(bio_err,
"WARNING: unable to check the generator value\n");
if (i & DH_NOT_SUITABLE_GENERATOR)
BIO_printf(bio_err, "WARNING: the g value is not a generator\n");
if (i == 0)
BIO_printf(bio_err, "DH parameters appear to be ok.\n");
if (num != 0 && i != 0) {
BIO_printf(bio_err, "ERROR: Invalid parameters generated\n");
goto end;
}
}
if (C) {
unsigned char *data;
int len, bits;
const BIGNUM *pbn, *gbn;
len = DH_size(dh);
bits = DH_bits(dh);
DH_get0_pqg(dh, &pbn, NULL, &gbn);
data = app_malloc(len, "print a BN");
BIO_printf(out, "#ifndef HEADER_DH_H\n"
"# include <openssl/dh.h>\n"
"#endif\n"
"\n");
BIO_printf(out, "DH *get_dh%d()\n{\n", bits);
print_bignum_var(out, pbn, "dhp", bits, data);
print_bignum_var(out, gbn, "dhg", bits, data);
BIO_printf(out, " DH *dh = DH_new();\n"
" BIGNUM *dhp_bn, *dhg_bn;\n"
"\n"
" if (dh == NULL)\n"
" return NULL;\n");
BIO_printf(out, " dhp_bn = BN_bin2bn(dhp_%d, sizeof (dhp_%d), NULL);\n",
bits, bits);
BIO_printf(out, " dhg_bn = BN_bin2bn(dhg_%d, sizeof (dhg_%d), NULL);\n",
bits, bits);
BIO_printf(out, " if (dhp_bn == NULL || dhg_bn == NULL\n"
" || !DH_set0_pqg(dh, dhp_bn, NULL, dhg_bn)) {\n"
" DH_free(dh);\n"
" BN_free(dhp_bn);\n"
" BN_free(dhg_bn);\n"
" return NULL;\n"
" }\n");
if (DH_get_length(dh) > 0)
BIO_printf(out,
" if (!DH_set_length(dh, %ld)) {\n"
" DH_free(dh);\n"
" }\n", DH_get_length(dh));
BIO_printf(out, " return dh;\n}\n");
OPENSSL_free(data);
}
if (!noout) {
const BIGNUM *q;
DH_get0_pqg(dh, NULL, &q, NULL);
if (outformat == FORMAT_ASN1)
i = i2d_DHparams_bio(out, dh);
else if (q != NULL)
i = PEM_write_bio_DHxparams(out, dh);
else
i = PEM_write_bio_DHparams(out, dh);
if (!i) {
BIO_printf(bio_err, "unable to write DH parameters\n");
ERR_print_errors(bio_err);
goto end;
}
}
ret = 0;
end:
BIO_free(in);
BIO_free_all(out);
DH_free(dh);
return (ret);
}
static int dh_cb(int p, int n, BN_GENCB *cb)
{
char c = '*';
if (p == 0)
c = '.';
if (p == 1)
c = '+';
if (p == 2)
c = '*';
if (p == 3)
c = '\n';
BIO_write(BN_GENCB_get_arg(cb), &c, 1);
(void)BIO_flush(BN_GENCB_get_arg(cb));
return 1;
}
