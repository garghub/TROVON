int __init bcm63xx_hsspi_register(void)
{
if (!BCMCPU_IS_6328() && !BCMCPU_IS_6362())
return -ENODEV;
spi_resources[0].start = bcm63xx_regset_address(RSET_HSSPI);
spi_resources[0].end = spi_resources[0].start;
spi_resources[0].end += RSET_HSSPI_SIZE - 1;
spi_resources[1].start = bcm63xx_get_irq_number(IRQ_HSSPI);
return platform_device_register(&bcm63xx_hsspi_device);
}
