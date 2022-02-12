int __init bcm63xx_rng_register(void)
{
if (!BCMCPU_IS_6368())
return -ENODEV;
rng_resources[0].start = bcm63xx_regset_address(RSET_RNG);
rng_resources[0].end = rng_resources[0].start;
rng_resources[0].end += RSET_RNG_SIZE - 1;
return platform_device_register(&bcm63xx_rng_device);
}
