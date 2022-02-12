static void ssl_library_stop(void)
{
if (stopped)
return;
stopped = 1;
if (ssl_base_inited) {
#ifndef OPENSSL_NO_COMP
# ifdef OPENSSL_INIT_DEBUG
fprintf(stderr, "OPENSSL_INIT: ssl_library_stop: "
"ssl_comp_free_compression_methods_int()\n");
# endif
ssl_comp_free_compression_methods_int();
#endif
}
if (ssl_strings_inited) {
#ifdef OPENSSL_INIT_DEBUG
fprintf(stderr, "OPENSSL_INIT: ssl_library_stop: "
"err_free_strings_int()\n");
#endif
err_free_strings_int();
}
}
int OPENSSL_init_ssl(uint64_t opts, const OPENSSL_INIT_SETTINGS * settings)
{
static int stoperrset = 0;
if (stopped) {
if (!stoperrset) {
stoperrset = 1;
SSLerr(SSL_F_OPENSSL_INIT_SSL, ERR_R_INIT_FAIL);
}
return 0;
}
if (!OPENSSL_init_crypto(opts | OPENSSL_INIT_ADD_ALL_CIPHERS
| OPENSSL_INIT_ADD_ALL_DIGESTS, settings))
return 0;
if (!RUN_ONCE(&ssl_base, ossl_init_ssl_base))
return 0;
if ((opts & OPENSSL_INIT_NO_LOAD_SSL_STRINGS)
&& !RUN_ONCE(&ssl_strings, ossl_init_no_load_ssl_strings))
return 0;
if ((opts & OPENSSL_INIT_LOAD_SSL_STRINGS)
&& !RUN_ONCE(&ssl_strings, ossl_init_load_ssl_strings))
return 0;
return 1;
}
