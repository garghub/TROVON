void OPENSSL_init(void)
{
static int done = 0;
if (done)
return;
done = 1;
#ifdef OPENSSL_FIPS
FIPS_set_locking_callbacks(CRYPTO_lock, CRYPTO_add_lock);
FIPS_set_error_callbacks(ERR_put_error, ERR_add_error_vdata);
FIPS_set_malloc_callbacks(CRYPTO_malloc, CRYPTO_free);
RAND_init_fips();
#endif
#if 0
fprintf(stderr, "Called OPENSSL_init\n");
#endif
}
