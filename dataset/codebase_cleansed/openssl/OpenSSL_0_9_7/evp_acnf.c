void OPENSSL_add_all_algorithms_conf(void)
{
OPENSSL_add_all_algorithms_noconf();
OPENSSL_config(NULL);
}
