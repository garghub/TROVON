int __init bcm63xx_spi_register(void)
{
if (BCMCPU_IS_6328() || BCMCPU_IS_6345())
return -ENODEV;
spi_resources[0].start = bcm63xx_regset_address(RSET_SPI);
spi_resources[0].end = spi_resources[0].start;
spi_resources[1].start = bcm63xx_get_irq_number(IRQ_SPI);
if (BCMCPU_IS_6338() || BCMCPU_IS_6348()) {
bcm63xx_spi_device.name = "bcm6348-spi",
spi_resources[0].end += BCM_6348_RSET_SPI_SIZE - 1;
}
if (BCMCPU_IS_3368() || BCMCPU_IS_6358() || BCMCPU_IS_6362() ||
BCMCPU_IS_6368()) {
bcm63xx_spi_device.name = "bcm6358-spi",
spi_resources[0].end += BCM_6358_RSET_SPI_SIZE - 1;
}
return platform_device_register(&bcm63xx_spi_device);
}
