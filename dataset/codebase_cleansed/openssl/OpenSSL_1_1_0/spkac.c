int spkac_main(int argc, char **argv)
{
BIO *out = NULL;
CONF *conf = NULL;
ENGINE *e = NULL;
EVP_PKEY *pkey = NULL;
NETSCAPE_SPKI *spki = NULL;
char *challenge = NULL, *keyfile = NULL;
char *infile = NULL, *outfile = NULL, *passinarg = NULL, *passin = NULL;
char *spkstr = NULL, *prog;
const char *spkac = "SPKAC", *spksect = "default";
int i, ret = 1, verify = 0, noout = 0, pubkey = 0;
OPTION_CHOICE o;
prog = opt_init(argc, argv, spkac_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(spkac_options);
ret = 0;
goto end;
case OPT_IN:
infile = opt_arg();
break;
case OPT_OUT:
outfile = opt_arg();
break;
case OPT_NOOUT:
noout = 1;
break;
case OPT_PUBKEY:
pubkey = 1;
break;
case OPT_VERIFY:
verify = 1;
break;
case OPT_PASSIN:
passinarg = opt_arg();
break;
case OPT_KEY:
keyfile = opt_arg();
break;
case OPT_CHALLENGE:
challenge = opt_arg();
break;
case OPT_SPKAC:
spkac = opt_arg();
break;
case OPT_SPKSECT:
spksect = opt_arg();
break;
case OPT_ENGINE:
e = setup_engine(opt_arg(), 0);
break;
}
}
argc = opt_num_rest();
if (argc != 0)
goto opthelp;
if (!app_passwd(passinarg, NULL, &passin, NULL)) {
BIO_printf(bio_err, "Error getting password\n");
goto end;
}
if (keyfile) {
pkey = load_key(strcmp(keyfile, "-") ? keyfile : NULL,
FORMAT_PEM, 1, passin, e, "private key");
if (!pkey) {
goto end;
}
spki = NETSCAPE_SPKI_new();
if (challenge)
ASN1_STRING_set(spki->spkac->challenge,
challenge, (int)strlen(challenge));
NETSCAPE_SPKI_set_pubkey(spki, pkey);
NETSCAPE_SPKI_sign(spki, pkey, EVP_md5());
spkstr = NETSCAPE_SPKI_b64_encode(spki);
out = bio_open_default(outfile, 'w', FORMAT_TEXT);
if (out == NULL) {
OPENSSL_free(spkstr);
goto end;
}
BIO_printf(out, "SPKAC=%s\n", spkstr);
OPENSSL_free(spkstr);
ret = 0;
goto end;
}
if ((conf = app_load_config(infile)) == NULL)
goto end;
spkstr = NCONF_get_string(conf, spksect, spkac);
if (spkstr == NULL) {
BIO_printf(bio_err, "Can't find SPKAC called \"%s\"\n", spkac);
ERR_print_errors(bio_err);
goto end;
}
spki = NETSCAPE_SPKI_b64_decode(spkstr, -1);
if (!spki) {
BIO_printf(bio_err, "Error loading SPKAC\n");
ERR_print_errors(bio_err);
goto end;
}
out = bio_open_default(outfile, 'w', FORMAT_TEXT);
if (out == NULL)
goto end;
if (!noout)
NETSCAPE_SPKI_print(out, spki);
pkey = NETSCAPE_SPKI_get_pubkey(spki);
if (verify) {
i = NETSCAPE_SPKI_verify(spki, pkey);
if (i > 0)
BIO_printf(bio_err, "Signature OK\n");
else {
BIO_printf(bio_err, "Signature Failure\n");
ERR_print_errors(bio_err);
goto end;
}
}
if (pubkey)
PEM_write_bio_PUBKEY(out, pkey);
ret = 0;
end:
NCONF_free(conf);
NETSCAPE_SPKI_free(spki);
BIO_free_all(out);
EVP_PKEY_free(pkey);
OPENSSL_free(passin);
return (ret);
}
