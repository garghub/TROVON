DSO_METHOD *DSO_METHOD_openssl(void)
{
#ifdef DEF_DSO_METHOD
return(DEF_DSO_METHOD());
#elif defined(DSO_DLFCN)
return(DSO_METHOD_dlfcn());
#elif defined(DSO_DL)
return(DSO_METHOD_dl());
#elif defined(DSO_WIN32)
return(DSO_METHOD_win32());
#elif defined(DSO_VMS)
return(DSO_METHOD_vms());
#elif defined(DSO_BEOS)
return(DSO_METHOD_beos());
#else
return(DSO_METHOD_null());
#endif
}
