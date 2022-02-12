int gendsa_main(int argc, char **argv)
{
BIO *out = NULL, *in = NULL;
DSA *dsa = NULL;
const EVP_CIPHER *enc = NULL;
char *inrand = NULL, *dsaparams = NULL;
char *outfile = NULL, *passoutarg = NULL, *passout = NULL, *prog;
OPTION_CHOICE o;
int ret = 1, private = 0;
const BIGNUM *p = NULL;
prog = opt_init(argc, argv, gendsa_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
ret = 0;
opt_help(gendsa_options);
goto end;
case OPT_OUT:
outfile = opt_arg();
break;
case OPT_PASSOUT:
passoutarg = opt_arg();
break;
case OPT_ENGINE:
(void)setup_engine(opt_arg(), 0);
break;
case OPT_RAND:
inrand = opt_arg();
break;
case OPT_CIPHER:
if (!opt_cipher(opt_unknown(), &enc))
goto end;
break;
}
}
argc = opt_num_rest();
argv = opt_rest();
private = 1;
if (argc != 1)
goto opthelp;
dsaparams = *argv;
if (!app_passwd(NULL, passoutarg, NULL, &passout)) {
BIO_printf(bio_err, "Error getting password\n");
goto end;
}
in = bio_open_default(dsaparams, 'r', FORMAT_PEM);
if (in == NULL)
goto end2;
if ((dsa = PEM_read_bio_DSAparams(in, NULL, NULL, NULL)) == NULL) {
BIO_printf(bio_err, "unable to load DSA parameter file\n");
goto end;
}
BIO_free(in);
in = NULL;
out = bio_open_owner(outfile, FORMAT_PEM, private);
if (out == NULL)
goto end2;
if (!app_RAND_load_file(NULL, 1) && inrand == NULL) {
BIO_printf(bio_err,
"warning, not much extra random data, consider using the -rand option\n");
}
if (inrand != NULL)
BIO_printf(bio_err, "%ld semi-random bytes loaded\n",
app_RAND_load_files(inrand));
DSA_get0_pqg(dsa, &p, NULL, NULL);
BIO_printf(bio_err, "Generating DSA key, %d bits\n", BN_num_bits(p));
if (!DSA_generate_key(dsa))
goto end;
app_RAND_write_file(NULL);
assert(private);
if (!PEM_write_bio_DSAPrivateKey(out, dsa, enc, NULL, 0, NULL, passout))
goto end;
ret = 0;
end:
if (ret != 0)
ERR_print_errors(bio_err);
end2:
BIO_free(in);
BIO_free_all(out);
DSA_free(dsa);
OPENSSL_free(passout);
return (ret);
}
