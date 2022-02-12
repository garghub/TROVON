int pkey_main(int argc, char **argv)
{
BIO *in = NULL, *out = NULL;
ENGINE *e = NULL;
EVP_PKEY *pkey = NULL;
const EVP_CIPHER *cipher = NULL;
char *infile = NULL, *outfile = NULL, *passin = NULL, *passout = NULL;
char *passinarg = NULL, *passoutarg = NULL, *prog;
OPTION_CHOICE o;
int informat = FORMAT_PEM, outformat = FORMAT_PEM;
int pubin = 0, pubout = 0, pubtext = 0, text = 0, noout = 0, ret = 1;
int private = 0, traditional = 0;
prog = opt_init(argc, argv, pkey_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(pkey_options);
ret = 0;
goto end;
case OPT_INFORM:
if (!opt_format(opt_arg(), OPT_FMT_ANY, &informat))
goto opthelp;
break;
case OPT_OUTFORM:
if (!opt_format(opt_arg(), OPT_FMT_PEMDER, &outformat))
goto opthelp;
break;
case OPT_PASSIN:
passinarg = opt_arg();
break;
case OPT_PASSOUT:
passoutarg = opt_arg();
break;
case OPT_ENGINE:
e = setup_engine(opt_arg(), 0);
break;
case OPT_IN:
infile = opt_arg();
break;
case OPT_OUT:
outfile = opt_arg();
break;
case OPT_PUBIN:
pubin = pubout = pubtext = 1;
break;
case OPT_PUBOUT:
pubout = 1;
break;
case OPT_TEXT_PUB:
pubtext = text = 1;
break;
case OPT_TEXT:
text = 1;
break;
case OPT_NOOUT:
noout = 1;
break;
case OPT_TRADITIONAL:
traditional = 1;
break;
case OPT_MD:
if (!opt_cipher(opt_unknown(), &cipher))
goto opthelp;
}
}
argc = opt_num_rest();
if (argc != 0)
goto opthelp;
private = !noout && !pubout ? 1 : 0;
if (text && !pubtext)
private = 1;
if (!app_passwd(passinarg, passoutarg, &passin, &passout)) {
BIO_printf(bio_err, "Error getting passwords\n");
goto end;
}
out = bio_open_owner(outfile, outformat, private);
if (out == NULL)
goto end;
if (pubin)
pkey = load_pubkey(infile, informat, 1, passin, e, "Public Key");
else
pkey = load_key(infile, informat, 1, passin, e, "key");
if (!pkey)
goto end;
if (!noout) {
if (outformat == FORMAT_PEM) {
if (pubout)
PEM_write_bio_PUBKEY(out, pkey);
else {
assert(private);
if (traditional)
PEM_write_bio_PrivateKey_traditional(out, pkey, cipher,
NULL, 0, NULL,
passout);
else
PEM_write_bio_PrivateKey(out, pkey, cipher,
NULL, 0, NULL, passout);
}
} else if (outformat == FORMAT_ASN1) {
if (pubout)
i2d_PUBKEY_bio(out, pkey);
else {
assert(private);
i2d_PrivateKey_bio(out, pkey);
}
} else {
BIO_printf(bio_err, "Bad format specified for key\n");
goto end;
}
}
if (text) {
if (pubtext)
EVP_PKEY_print_public(out, pkey, 0, NULL);
else {
assert(private);
EVP_PKEY_print_private(out, pkey, 0, NULL);
}
}
ret = 0;
end:
EVP_PKEY_free(pkey);
BIO_free_all(out);
BIO_free(in);
OPENSSL_free(passin);
OPENSSL_free(passout);
return ret;
}
