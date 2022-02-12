void OPENSSL_load_builtin_modules(void)
{
ASN1_add_oid_module();
ASN1_add_stable_module();
#ifndef OPENSSL_NO_ENGINE
ENGINE_add_conf_module();
#endif
EVP_add_alg_module();
}
