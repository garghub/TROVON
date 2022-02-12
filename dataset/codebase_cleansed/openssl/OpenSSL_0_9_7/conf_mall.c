void OPENSSL_load_builtin_modules(void)
{
ASN1_add_oid_module();
ENGINE_add_conf_module();
}
