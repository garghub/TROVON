static int pseries_rng_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
u64 buffer[PLPAR_HCALL_BUFSIZE];
int rc;
rc = plpar_hcall(H_RANDOM, (unsigned long *)buffer);
if (rc != H_SUCCESS) {
pr_err_ratelimited("H_RANDOM call failed %d\n", rc);
return -EIO;
}
memcpy(data, buffer, 8);
return 8;
}
static unsigned long pseries_rng_get_desired_dma(struct vio_dev *vdev)
{
return 0;
}
static int pseries_rng_probe(struct vio_dev *dev,
const struct vio_device_id *id)
{
return hwrng_register(&pseries_rng);
}
static int pseries_rng_remove(struct vio_dev *dev)
{
hwrng_unregister(&pseries_rng);
return 0;
}
static int __init rng_init(void)
{
pr_info("Registering IBM pSeries RNG driver\n");
return vio_register_driver(&pseries_rng_driver);
}
static void __exit rng_exit(void)
{
vio_unregister_driver(&pseries_rng_driver);
}
