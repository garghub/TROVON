int __init spi_eeprom_register(int busid, int chipid, int size)
{
struct spi_board_info info = {
.modalias = "at25",
.max_speed_hz = 1500000,
.bus_num = busid,
.chip_select = chipid,
};
struct spi_eeprom *eeprom;
eeprom = kzalloc(sizeof(*eeprom), GFP_KERNEL);
if (!eeprom)
return -ENOMEM;
strcpy(eeprom->name, "at250x0");
eeprom->byte_len = size;
eeprom->page_size = AT250X0_PAGE_SIZE;
eeprom->flags = EE_ADDR1;
info.platform_data = eeprom;
return spi_register_board_info(&info, 1);
}
static int __init early_seeprom_probe(struct spi_device *spi)
{
int stat = 0;
u8 cmd[2];
int len = read_param->len;
char *buf = read_param->buf;
int address = read_param->address;
dev_info(&spi->dev, "spiclk %u KHz.\n",
(spi->max_speed_hz + 500) / 1000);
if (read_param->busid != spi->master->bus_num ||
read_param->chipid != spi->chip_select)
return -ENODEV;
while (len > 0) {
int c = len < AT250X0_PAGE_SIZE ? len : AT250X0_PAGE_SIZE;
cmd[0] = 0x03;
cmd[1] = address;
stat = spi_write_then_read(spi, cmd, sizeof(cmd), buf, c);
buf += c;
len -= c;
address += c;
}
return stat;
}
int __init spi_eeprom_read(int busid, int chipid, int address,
unsigned char *buf, int len)
{
int ret;
struct read_param param = {
.busid = busid,
.chipid = chipid,
.address = address,
.buf = buf,
.len = len
};
read_param = &param;
ret = spi_register_driver(&early_seeprom_driver);
if (!ret)
spi_unregister_driver(&early_seeprom_driver);
return ret;
}
