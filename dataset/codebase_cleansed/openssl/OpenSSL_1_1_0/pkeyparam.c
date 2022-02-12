int pkeyparam_main(int argc, char **argv)
{
BIO *in = NULL, *out = NULL;
EVP_PKEY *pkey = NULL;
int text = 0, noout = 0, ret = 1;
OPTION_CHOICE o;
char *infile = NULL, *outfile = NULL, *prog;
prog = opt_init(argc, argv, pkeyparam_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(pkeyparam_options);
ret = 0;
goto end;
case OPT_IN:
infile = opt_arg();
break;
case OPT_OUT:
outfile = opt_arg();
break;
case OPT_ENGINE:
(void)setup_engine(opt_arg(), 0);
break;
case OPT_TEXT:
text = 1;
break;
case OPT_NOOUT:
noout = 1;
break;
}
}
argc = opt_num_rest();
if (argc != 0)
goto opthelp;
in = bio_open_default(infile, 'r', FORMAT_PEM);
if (in == NULL)
goto end;
out = bio_open_default(outfile, 'w', FORMAT_PEM);
if (out == NULL)
goto end;
pkey = PEM_read_bio_Parameters(in, NULL);
if (!pkey) {
BIO_printf(bio_err, "Error reading parameters\n");
ERR_print_errors(bio_err);
goto end;
}
if (!noout)
PEM_write_bio_Parameters(out, pkey);
if (text)
EVP_PKEY_print_params(out, pkey, 0, NULL);
ret = 0;
end:
EVP_PKEY_free(pkey);
BIO_free_all(out);
BIO_free(in);
return ret;
}
