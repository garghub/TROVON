static void __init *spidev_platform_data(void *info)
{
struct spi_board_info *spi_info = info;
spi_info->mode = SPI_MODE_0;
spi_info->controller_data = &spidev_spi_chip;
return NULL;
}
