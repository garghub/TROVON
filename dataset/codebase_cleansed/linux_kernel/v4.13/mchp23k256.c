static void mchp23k256_addr2cmd(struct mchp23k256_flash *flash,
unsigned int addr, u8 *cmd)
{
int i;
for (i = flash->caps->addr_width; i > 0; i--, addr >>= 8)
cmd[i] = addr;
}
static int mchp23k256_cmdsz(struct mchp23k256_flash *flash)
{
return 1 + flash->caps->addr_width;
}
static int mchp23k256_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const unsigned char *buf)
{
struct mchp23k256_flash *flash = to_mchp23k256_flash(mtd);
struct spi_transfer transfer[2] = {};
struct spi_message message;
unsigned char command[MAX_CMD_SIZE];
spi_message_init(&message);
command[0] = MCHP23K256_CMD_WRITE;
mchp23k256_addr2cmd(flash, to, command);
transfer[0].tx_buf = command;
transfer[0].len = mchp23k256_cmdsz(flash);
spi_message_add_tail(&transfer[0], &message);
transfer[1].tx_buf = buf;
transfer[1].len = len;
spi_message_add_tail(&transfer[1], &message);
mutex_lock(&flash->lock);
spi_sync(flash->spi, &message);
if (retlen && message.actual_length > sizeof(command))
*retlen += message.actual_length - sizeof(command);
mutex_unlock(&flash->lock);
return 0;
}
static int mchp23k256_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, unsigned char *buf)
{
struct mchp23k256_flash *flash = to_mchp23k256_flash(mtd);
struct spi_transfer transfer[2] = {};
struct spi_message message;
unsigned char command[MAX_CMD_SIZE];
spi_message_init(&message);
memset(&transfer, 0, sizeof(transfer));
command[0] = MCHP23K256_CMD_READ;
mchp23k256_addr2cmd(flash, from, command);
transfer[0].tx_buf = command;
transfer[0].len = mchp23k256_cmdsz(flash);
spi_message_add_tail(&transfer[0], &message);
transfer[1].rx_buf = buf;
transfer[1].len = len;
spi_message_add_tail(&transfer[1], &message);
mutex_lock(&flash->lock);
spi_sync(flash->spi, &message);
if (retlen && message.actual_length > sizeof(command))
*retlen += message.actual_length - sizeof(command);
mutex_unlock(&flash->lock);
return 0;
}
static int mchp23k256_set_mode(struct spi_device *spi)
{
struct spi_transfer transfer = {};
struct spi_message message;
unsigned char command[2];
spi_message_init(&message);
command[0] = MCHP23K256_CMD_WRITE_STATUS;
command[1] = MCHP23K256_MODE_SEQ;
transfer.tx_buf = command;
transfer.len = sizeof(command);
spi_message_add_tail(&transfer, &message);
return spi_sync(spi, &message);
}
static int mchp23k256_probe(struct spi_device *spi)
{
struct mchp23k256_flash *flash;
struct flash_platform_data *data;
int err;
flash = devm_kzalloc(&spi->dev, sizeof(*flash), GFP_KERNEL);
if (!flash)
return -ENOMEM;
flash->spi = spi;
mutex_init(&flash->lock);
spi_set_drvdata(spi, flash);
err = mchp23k256_set_mode(spi);
if (err)
return err;
data = dev_get_platdata(&spi->dev);
flash->caps = of_device_get_match_data(&spi->dev);
if (!flash->caps)
flash->caps = &mchp23k256_caps;
mtd_set_of_node(&flash->mtd, spi->dev.of_node);
flash->mtd.dev.parent = &spi->dev;
flash->mtd.type = MTD_RAM;
flash->mtd.flags = MTD_CAP_RAM;
flash->mtd.writesize = 1;
flash->mtd.size = flash->caps->size;
flash->mtd._read = mchp23k256_read;
flash->mtd._write = mchp23k256_write;
err = mtd_device_register(&flash->mtd, data ? data->parts : NULL,
data ? data->nr_parts : 0);
if (err)
return err;
return 0;
}
static int mchp23k256_remove(struct spi_device *spi)
{
struct mchp23k256_flash *flash = spi_get_drvdata(spi);
return mtd_device_unregister(&flash->mtd);
}
