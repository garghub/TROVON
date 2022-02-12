void ENGINE_load_builtin_engines(void)
{
OPENSSL_cpuid_setup();
OPENSSL_init_crypto(OPENSSL_INIT_ENGINE_ALL_BUILTIN, NULL);
}
void ENGINE_setup_bsd_cryptodev(void)
{
static int bsd_cryptodev_default_loaded = 0;
if (!bsd_cryptodev_default_loaded) {
OPENSSL_init_crypto(OPENSSL_INIT_ENGINE_CRYPTODEV, NULL);
ENGINE_register_all_complete();
}
bsd_cryptodev_default_loaded = 1;
}
