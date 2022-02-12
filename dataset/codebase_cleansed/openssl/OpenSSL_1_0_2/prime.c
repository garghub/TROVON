int MAIN(int argc, char **argv)
{
int hex = 0;
int checks = 20;
int generate = 0;
int bits = 0;
int safe = 0;
BIGNUM *bn = NULL;
BIO *bio_out;
apps_startup();
if (bio_err == NULL)
if ((bio_err = BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err, stderr, BIO_NOCLOSE | BIO_FP_TEXT);
--argc;
++argv;
while (argc >= 1 && **argv == '-') {
if (!strcmp(*argv, "-hex"))
hex = 1;
else if (!strcmp(*argv, "-generate"))
generate = 1;
else if (!strcmp(*argv, "-bits"))
if (--argc < 1)
goto bad;
else
bits = atoi(*++argv);
else if (!strcmp(*argv, "-safe"))
safe = 1;
else if (!strcmp(*argv, "-checks"))
if (--argc < 1)
goto bad;
else
checks = atoi(*++argv);
else {
BIO_printf(bio_err, "Unknown option '%s'\n", *argv);
goto bad;
}
--argc;
++argv;
}
if (argv[0] == NULL && !generate) {
BIO_printf(bio_err, "No prime specified\n");
goto bad;
}
if ((bio_out = BIO_new(BIO_s_file())) != NULL) {
BIO_set_fp(bio_out, stdout, BIO_NOCLOSE);
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
bio_out = BIO_push(tmpbio, bio_out);
}
#endif
}
if (generate) {
char *s;
if (!bits) {
BIO_printf(bio_err, "Specifiy the number of bits.\n");
return 1;
}
bn = BN_new();
BN_generate_prime_ex(bn, bits, safe, NULL, NULL, NULL);
s = hex ? BN_bn2hex(bn) : BN_bn2dec(bn);
BIO_printf(bio_out, "%s\n", s);
OPENSSL_free(s);
} else {
if (hex)
BN_hex2bn(&bn, argv[0]);
else
BN_dec2bn(&bn, argv[0]);
BN_print(bio_out, bn);
BIO_printf(bio_out, " is %sprime\n",
BN_is_prime_ex(bn, checks, NULL, NULL) ? "" : "not ");
}
BN_free(bn);
BIO_free_all(bio_out);
return 0;
bad:
BIO_printf(bio_err, "options are\n");
BIO_printf(bio_err, "%-14s hex\n", "-hex");
BIO_printf(bio_err, "%-14s number of checks\n", "-checks <n>");
return 1;
}
