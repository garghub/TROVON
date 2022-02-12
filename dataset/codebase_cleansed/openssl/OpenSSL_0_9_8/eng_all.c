void ENGINE_load_builtin_engines(void)
{
#if 0
ENGINE_load_openssl();
#endif
ENGINE_load_dynamic();
#ifndef OPENSSL_NO_STATIC_ENGINE
#ifndef OPENSSL_NO_HW
#ifndef OPENSSL_NO_HW_4758_CCA
ENGINE_load_4758cca();
#endif
#ifndef OPENSSL_NO_HW_AEP
ENGINE_load_aep();
#endif
#ifndef OPENSSL_NO_HW_ATALLA
ENGINE_load_atalla();
#endif
#ifndef OPENSSL_NO_HW_CSWIFT
ENGINE_load_cswift();
#endif
#ifndef OPENSSL_NO_HW_NCIPHER
ENGINE_load_chil();
#endif
#ifndef OPENSSL_NO_HW_NURON
ENGINE_load_nuron();
#endif
#ifndef OPENSSL_NO_HW_SUREWARE
ENGINE_load_sureware();
#endif
#ifndef OPENSSL_NO_HW_UBSEC
ENGINE_load_ubsec();
#endif
#ifndef OPENSSL_NO_HW_PADLOCK
ENGINE_load_padlock();
#endif
#endif
#if defined(__OpenBSD__) || defined(__FreeBSD__)
ENGINE_load_cryptodev();
#endif
#if !defined(OPENSSL_NO_GMP) && !defined(OPENSSL_NO_HW_GMP)
ENGINE_load_gmp();
#endif
#endif
}
void ENGINE_setup_bsd_cryptodev(void) {
static int bsd_cryptodev_default_loaded = 0;
if (!bsd_cryptodev_default_loaded) {
ENGINE_load_cryptodev();
ENGINE_register_all_complete();
}
bsd_cryptodev_default_loaded=1;
}
