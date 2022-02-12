void OPENSSL_load_builtin_modules(void)
{
ASN1_add_oid_module();
#ifndef OPENSSL_NO_ENGINE
ENGINE_add_conf_module();
#endif
}
