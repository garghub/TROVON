void OPENSSL_config(const char *appname)
{
OPENSSL_INIT_SETTINGS settings;
memset(&settings, 0, sizeof(settings));
if (appname != NULL)
settings.appname = strdup(appname);
OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CONFIG, &settings);
}
void openssl_config_int(const char *appname)
{
if (openssl_configured)
return;
OPENSSL_load_builtin_modules();
#ifndef OPENSSL_NO_ENGINE
ENGINE_load_builtin_engines();
#endif
ERR_clear_error();
#ifndef OPENSSL_SYS_UEFI
CONF_modules_load_file(NULL, appname,
CONF_MFLAGS_DEFAULT_SECTION |
CONF_MFLAGS_IGNORE_MISSING_FILE);
#endif
openssl_configured = 1;
}
void openssl_no_config_int(void)
{
openssl_configured = 1;
}
