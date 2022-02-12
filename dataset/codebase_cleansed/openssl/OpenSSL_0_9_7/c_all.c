void OPENSSL_add_all_algorithms_noconf(void)
{
OpenSSL_add_all_ciphers();
OpenSSL_add_all_digests();
#ifdef __OpenBSD__
ENGINE_setup_openbsd();
#endif
}
