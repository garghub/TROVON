const char *SSLeay_version(int t)
{
if (t == SSLEAY_VERSION)
return OPENSSL_VERSION_TEXT;
if (t == SSLEAY_BUILT_ON) {
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
if (t == SSLEAY_CFLAGS) {
#ifdef CFLAGS
return (CFLAGS);
#else
return ("compiler: information not available");
#endif
}
if (t == SSLEAY_PLATFORM) {
#ifdef PLATFORM
return (PLATFORM);
#else
return ("platform: information not available");
#endif
}
if (t == SSLEAY_DIR) {
#ifdef OPENSSLDIR
return "OPENSSLDIR: \"" OPENSSLDIR "\"";
#else
return "OPENSSLDIR: N/A";
#endif
}
return ("not available");
}
unsigned long SSLeay(void)
{
return (SSLEAY_VERSION_NUMBER);
}
