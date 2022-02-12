int FIPS_mode(void)
{
#ifdef OPENSSL_FIPS
return FIPS_module_mode();
#else
return 0;
#endif
}
int FIPS_mode_set(int r)
{
#ifdef OPENSSL_FIPS
return FIPS_module_mode_set(r);
#else
if (r == 0)
return 1;
CRYPTOerr(CRYPTO_F_FIPS_MODE_SET, CRYPTO_R_FIPS_MODE_NOT_SUPPORTED);
return 0;
#endif
}
