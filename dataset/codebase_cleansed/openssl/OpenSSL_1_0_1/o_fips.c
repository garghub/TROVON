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
OPENSSL_init();
#ifdef OPENSSL_FIPS
#ifndef FIPS_AUTH_USER_PASS
#define FIPS_AUTH_USER_PASS "Default FIPS Crypto User Password"
#endif
if (!FIPS_module_mode_set(r, FIPS_AUTH_USER_PASS))
return 0;
if (r)
RAND_set_rand_method(FIPS_rand_get_method());
else
RAND_set_rand_method(NULL);
return 1;
#else
if (r == 0)
return 1;
CRYPTOerr(CRYPTO_F_FIPS_MODE_SET, CRYPTO_R_FIPS_MODE_NOT_SUPPORTED);
return 0;
#endif
}
