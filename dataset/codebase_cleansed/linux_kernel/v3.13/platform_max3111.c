static void __init *max3111_platform_data(void *info)
{
struct spi_board_info *spi_info = info;
int intr = get_gpio_by_name("max3111_int");
spi_info->mode = SPI_MODE_0;
if (intr == -1)
return NULL;
spi_info->irq = intr + INTEL_MID_IRQ_OFFSET;
return NULL;
}
