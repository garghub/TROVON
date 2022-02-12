static int krng_get_random(struct crypto_rng *tfm, u8 *rdata, unsigned int dlen)
{
get_random_bytes(rdata, dlen);
return 0;
}
static int krng_reset(struct crypto_rng *tfm, u8 *seed, unsigned int slen)
{
return 0;
}
static int __init krng_mod_init(void)
{
return crypto_register_alg(&krng_alg);
}
static void __exit krng_mod_fini(void)
{
crypto_unregister_alg(&krng_alg);
return;
}
