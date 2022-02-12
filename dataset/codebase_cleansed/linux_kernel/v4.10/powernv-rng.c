static int powernv_rng_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
unsigned long *buf;
int i, len;
len = max / sizeof(unsigned long);
buf = (unsigned long *)data;
for (i = 0; i < len; i++)
powernv_get_random_long(buf++);
return len * sizeof(unsigned long);
}
static int powernv_rng_remove(struct platform_device *pdev)
{
hwrng_unregister(&powernv_hwrng);
return 0;
}
static int powernv_rng_probe(struct platform_device *pdev)
{
int rc;
rc = hwrng_register(&powernv_hwrng);
if (rc) {
if (rc == -EEXIST)
rc = -ENODEV;
return rc;
}
pr_info("Registered powernv hwrng.\n");
return 0;
}
