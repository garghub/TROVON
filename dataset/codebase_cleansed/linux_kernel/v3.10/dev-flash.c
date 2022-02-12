static int __init bcm63xx_detect_flash_type(void)
{
u32 val;
switch (bcm63xx_get_cpu_id()) {
case BCM6328_CPU_ID:
val = bcm_misc_readl(MISC_STRAPBUS_6328_REG);
if (val & STRAPBUS_6328_BOOT_SEL_SERIAL)
return BCM63XX_FLASH_TYPE_SERIAL;
else
return BCM63XX_FLASH_TYPE_NAND;
case BCM6338_CPU_ID:
case BCM6345_CPU_ID:
case BCM6348_CPU_ID:
return BCM63XX_FLASH_TYPE_PARALLEL;
case BCM6358_CPU_ID:
val = bcm_gpio_readl(GPIO_STRAPBUS_REG);
if (val & STRAPBUS_6358_BOOT_SEL_PARALLEL)
return BCM63XX_FLASH_TYPE_PARALLEL;
else
return BCM63XX_FLASH_TYPE_SERIAL;
case BCM6362_CPU_ID:
val = bcm_misc_readl(MISC_STRAPBUS_6362_REG);
if (val & STRAPBUS_6362_BOOT_SEL_SERIAL)
return BCM63XX_FLASH_TYPE_SERIAL;
else
return BCM63XX_FLASH_TYPE_NAND;
case BCM6368_CPU_ID:
val = bcm_gpio_readl(GPIO_STRAPBUS_REG);
switch (val & STRAPBUS_6368_BOOT_SEL_MASK) {
case STRAPBUS_6368_BOOT_SEL_NAND:
return BCM63XX_FLASH_TYPE_NAND;
case STRAPBUS_6368_BOOT_SEL_SERIAL:
return BCM63XX_FLASH_TYPE_SERIAL;
case STRAPBUS_6368_BOOT_SEL_PARALLEL:
return BCM63XX_FLASH_TYPE_PARALLEL;
}
default:
return -EINVAL;
}
}
int __init bcm63xx_flash_register(void)
{
int flash_type;
u32 val;
flash_type = bcm63xx_detect_flash_type();
switch (flash_type) {
case BCM63XX_FLASH_TYPE_PARALLEL:
val = bcm_mpi_readl(MPI_CSBASE_REG(0));
val &= MPI_CSBASE_BASE_MASK;
mtd_resources[0].start = val;
mtd_resources[0].end = 0x1FFFFFFF;
return platform_device_register(&mtd_dev);
case BCM63XX_FLASH_TYPE_SERIAL:
pr_warn("unsupported serial flash detected\n");
return -ENODEV;
case BCM63XX_FLASH_TYPE_NAND:
pr_warn("unsupported NAND flash detected\n");
return -ENODEV;
default:
pr_err("flash detection failed for BCM%x: %d\n",
bcm63xx_get_cpu_id(), flash_type);
return -ENODEV;
}
}
