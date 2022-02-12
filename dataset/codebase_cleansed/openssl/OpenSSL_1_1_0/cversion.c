unsigned long OpenSSL_version_num(void)
{
return OPENSSL_VERSION_NUMBER;
}
const char *OpenSSL_version(int t)
{
if (t == OPENSSL_VERSION)
return OPENSSL_VERSION_TEXT;
if (t == OPENSSL_BUILT_ON) {
#ifdef DATE
# ifdef OPENSSL_USE_BUILD_DATE
return (DATE);
# else
return ("built on: reproducible build, date unspecified");
# endif
#else
return ("built on: date not available");
#endif
}
if (t == OPENSSL_CFLAGS) {
#ifdef CFLAGS
return (CFLAGS);
#else
return ("compiler: information not available");
#endif
}
if (t == OPENSSL_PLATFORM) {
#ifdef PLATFORM
return (PLATFORM);
#else
return ("platform: information not available");
#endif
}
if (t == OPENSSL_DIR) {
#ifdef OPENSSLDIR
return "OPENSSLDIR: \"" OPENSSLDIR "\"";
#else
return "OPENSSLDIR: N/A";
#endif
}
if (t == OPENSSL_ENGINES_DIR) {
#ifdef ENGINESDIR
return "ENGINESDIR: \"" ENGINESDIR "\"";
#else
return "ENGINESDIR: N/A";
#endif
}
return ("not available");
}
