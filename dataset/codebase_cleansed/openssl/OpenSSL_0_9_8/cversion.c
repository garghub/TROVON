const char *SSLeay_version(int t)
{
if (t == SSLEAY_VERSION)
return OPENSSL_VERSION_TEXT;
if (t == SSLEAY_BUILT_ON)
{
#ifdef DATE
static char buf[sizeof(DATE)+11];
BIO_snprintf(buf,sizeof buf,"built on: %s",DATE);
return(buf);
#else
return("built on: date not available");
#endif
}
if (t == SSLEAY_CFLAGS)
{
#ifdef CFLAGS
static char buf[sizeof(CFLAGS)+11];
BIO_snprintf(buf,sizeof buf,"compiler: %s",CFLAGS);
return(buf);
#else
return("compiler: information not available");
#endif
}
if (t == SSLEAY_PLATFORM)
{
#ifdef PLATFORM
static char buf[sizeof(PLATFORM)+11];
BIO_snprintf(buf,sizeof buf,"platform: %s", PLATFORM);
return(buf);
#else
return("platform: information not available");
#endif
}
if (t == SSLEAY_DIR)
{
#ifdef OPENSSLDIR
return "OPENSSLDIR: \"" OPENSSLDIR "\"";
#else
return "OPENSSLDIR: N/A";
#endif
}
return("not available");
}
unsigned long SSLeay(void)
{
return(SSLEAY_VERSION_NUMBER);
}
