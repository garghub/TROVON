int errstr_main(int argc, char **argv)
{
OPTION_CHOICE o;
char buf[256], *prog;
int ret = 1;
unsigned long l;
prog = opt_init(argc, argv, errstr_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(errstr_options);
ret = 0;
goto end;
}
}
ret = 0;
for (argv = opt_rest(); *argv; argv++) {
if (sscanf(*argv, "%lx", &l) == 0)
ret++;
else {
OPENSSL_init_ssl(OPENSSL_INIT_LOAD_SSL_STRINGS
| OPENSSL_INIT_LOAD_CRYPTO_STRINGS, NULL);
ERR_error_string_n(l, buf, sizeof buf);
BIO_printf(bio_out, "%s\n", buf);
}
}
end:
return (ret);
}
