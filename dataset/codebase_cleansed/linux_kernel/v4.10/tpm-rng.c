static int tpm_rng_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
return tpm_get_random(TPM_ANY_NUM, data, max);
}
static int __init rng_init(void)
{
return hwrng_register(&tpm_rng);
}
static void __exit rng_exit(void)
{
hwrng_unregister(&tpm_rng);
}
