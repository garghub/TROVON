void __init ath79_register_spi(struct ath79_spi_platform_data *pdata,
struct spi_board_info const *info,
unsigned n)
{
spi_register_board_info(info, n);
ath79_spi_device.dev.platform_data = pdata;
platform_device_register(&ath79_spi_device);
}
