static int __init favr32_flash_init(void)
{
int ret;
smc_set_timing(&flash_config, &flash_timing);
ret = smc_set_configuration(0, &flash_config);
if (ret < 0) {
printk(KERN_ERR "Favr-32: failed to set NOR flash timing\n");
return ret;
}
platform_device_register(&flash_device);
return 0;
}
