void OPENSSL_config(const char *config_name)
{
if (openssl_configured)
return;
OPENSSL_load_builtin_modules();
#ifndef OPENSSL_NO_ENGINE
ENGINE_load_builtin_engines();
#endif
ERR_clear_error();
if (CONF_modules_load_file(NULL, NULL,
CONF_MFLAGS_IGNORE_MISSING_FILE) <= 0)
{
BIO *bio_err;
ERR_load_crypto_strings();
if ((bio_err=BIO_new_fp(stderr, BIO_NOCLOSE)) != NULL)
{
BIO_printf(bio_err,"Auto configuration failed\n");
ERR_print_errors(bio_err);
BIO_free(bio_err);
}
exit(1);
}
return;
}
void OPENSSL_no_config()
{
openssl_configured = 1;
}
