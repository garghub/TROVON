static int pseries_rng_data_read(struct hwrng *rng, u32 *data)
{
if (plpar_hcall(H_RANDOM, (unsigned long *)data) != H_SUCCESS) {
printk(KERN_ERR "pseries rng hcall error\n");
return 0;
}
return 8;
}
static unsigned long pseries_rng_get_desired_dma(struct vio_dev *vdev)
{
return 0;
}
static int __init pseries_rng_probe(struct vio_dev *dev,
const struct vio_device_id *id)
{
return hwrng_register(&pseries_rng);
}
static int __exit pseries_rng_remove(struct vio_dev *dev)
{
hwrng_unregister(&pseries_rng);
return 0;
}
static int __init rng_init(void)
{
printk(KERN_INFO "Registering IBM pSeries RNG driver\n");
return vio_register_driver(&pseries_rng_driver);
}
static void __exit rng_exit(void)
{
vio_unregister_driver(&pseries_rng_driver);
}
