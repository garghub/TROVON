static int m25p80_read_reg(struct spi_nor *nor, u8 code, u8 *val, int len)
{
struct m25p *flash = nor->priv;
struct spi_device *spi = flash->spi;
int ret;
ret = spi_write_then_read(spi, &code, 1, val, len);
if (ret < 0)
dev_err(&spi->dev, "error %d reading %x\n", ret, code);
return ret;
}
static void m25p_addr2cmd(struct spi_nor *nor, unsigned int addr, u8 *cmd)
{
cmd[1] = addr >> (nor->addr_width * 8 - 8);
cmd[2] = addr >> (nor->addr_width * 8 - 16);
cmd[3] = addr >> (nor->addr_width * 8 - 24);
cmd[4] = addr >> (nor->addr_width * 8 - 32);
}
static int m25p_cmdsz(struct spi_nor *nor)
{
return 1 + nor->addr_width;
}
static int m25p80_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
struct m25p *flash = nor->priv;
struct spi_device *spi = flash->spi;
flash->command[0] = opcode;
if (buf)
memcpy(&flash->command[1], buf, len);
return spi_write(spi, flash->command, len + 1);
}
static ssize_t m25p80_write(struct spi_nor *nor, loff_t to, size_t len,
const u_char *buf)
{
struct m25p *flash = nor->priv;
struct spi_device *spi = flash->spi;
unsigned int inst_nbits, addr_nbits, data_nbits, data_idx;
struct spi_transfer t[3] = {};
struct spi_message m;
int cmd_sz = m25p_cmdsz(nor);
ssize_t ret;
inst_nbits = spi_nor_get_protocol_inst_nbits(nor->write_proto);
addr_nbits = spi_nor_get_protocol_addr_nbits(nor->write_proto);
data_nbits = spi_nor_get_protocol_data_nbits(nor->write_proto);
spi_message_init(&m);
if (nor->program_opcode == SPINOR_OP_AAI_WP && nor->sst_write_second)
cmd_sz = 1;
flash->command[0] = nor->program_opcode;
m25p_addr2cmd(nor, to, flash->command);
t[0].tx_buf = flash->command;
t[0].tx_nbits = inst_nbits;
t[0].len = cmd_sz;
spi_message_add_tail(&t[0], &m);
data_idx = 1;
if (addr_nbits != inst_nbits) {
t[0].len = 1;
t[1].tx_buf = &flash->command[1];
t[1].tx_nbits = addr_nbits;
t[1].len = cmd_sz - 1;
spi_message_add_tail(&t[1], &m);
data_idx = 2;
}
t[data_idx].tx_buf = buf;
t[data_idx].tx_nbits = data_nbits;
t[data_idx].len = len;
spi_message_add_tail(&t[data_idx], &m);
ret = spi_sync(spi, &m);
if (ret)
return ret;
ret = m.actual_length - cmd_sz;
if (ret < 0)
return -EIO;
return ret;
}
static ssize_t m25p80_read(struct spi_nor *nor, loff_t from, size_t len,
u_char *buf)
{
struct m25p *flash = nor->priv;
struct spi_device *spi = flash->spi;
unsigned int inst_nbits, addr_nbits, data_nbits, data_idx;
struct spi_transfer t[3];
struct spi_message m;
unsigned int dummy = nor->read_dummy;
ssize_t ret;
int cmd_sz;
inst_nbits = spi_nor_get_protocol_inst_nbits(nor->read_proto);
addr_nbits = spi_nor_get_protocol_addr_nbits(nor->read_proto);
data_nbits = spi_nor_get_protocol_data_nbits(nor->read_proto);
dummy = (dummy * addr_nbits) / 8;
if (spi_flash_read_supported(spi)) {
struct spi_flash_read_message msg;
memset(&msg, 0, sizeof(msg));
msg.buf = buf;
msg.from = from;
msg.len = len;
msg.read_opcode = nor->read_opcode;
msg.addr_width = nor->addr_width;
msg.dummy_bytes = dummy;
msg.opcode_nbits = inst_nbits;
msg.addr_nbits = addr_nbits;
msg.data_nbits = data_nbits;
ret = spi_flash_read(spi, &msg);
if (ret < 0)
return ret;
return msg.retlen;
}
spi_message_init(&m);
memset(t, 0, (sizeof t));
flash->command[0] = nor->read_opcode;
m25p_addr2cmd(nor, from, flash->command);
t[0].tx_buf = flash->command;
t[0].tx_nbits = inst_nbits;
t[0].len = m25p_cmdsz(nor) + dummy;
spi_message_add_tail(&t[0], &m);
cmd_sz = t[0].len;
memset(flash->command + cmd_sz - dummy, 0xff, dummy);
data_idx = 1;
if (addr_nbits != inst_nbits) {
t[0].len = 1;
t[1].tx_buf = &flash->command[1];
t[1].tx_nbits = addr_nbits;
t[1].len = cmd_sz - 1;
spi_message_add_tail(&t[1], &m);
data_idx = 2;
}
t[data_idx].rx_buf = buf;
t[data_idx].rx_nbits = data_nbits;
t[data_idx].len = min3(len, spi_max_transfer_size(spi),
spi_max_message_size(spi) - cmd_sz);
spi_message_add_tail(&t[data_idx], &m);
ret = spi_sync(spi, &m);
if (ret)
return ret;
ret = m.actual_length - cmd_sz;
if (ret < 0)
return -EIO;
return ret;
}
static int m25p_probe(struct spi_device *spi)
{
struct flash_platform_data *data;
struct m25p *flash;
struct spi_nor *nor;
struct spi_nor_hwcaps hwcaps = {
.mask = SNOR_HWCAPS_READ |
SNOR_HWCAPS_READ_FAST |
SNOR_HWCAPS_PP,
};
char *flash_name;
int ret;
data = dev_get_platdata(&spi->dev);
flash = devm_kzalloc(&spi->dev, sizeof(*flash), GFP_KERNEL);
if (!flash)
return -ENOMEM;
nor = &flash->spi_nor;
nor->read = m25p80_read;
nor->write = m25p80_write;
nor->write_reg = m25p80_write_reg;
nor->read_reg = m25p80_read_reg;
nor->dev = &spi->dev;
spi_nor_set_flash_node(nor, spi->dev.of_node);
nor->priv = flash;
spi_set_drvdata(spi, flash);
flash->spi = spi;
if (spi->mode & SPI_RX_QUAD) {
hwcaps.mask |= SNOR_HWCAPS_READ_1_1_4;
if (spi->mode & SPI_TX_QUAD)
hwcaps.mask |= (SNOR_HWCAPS_READ_1_4_4 |
SNOR_HWCAPS_PP_1_1_4 |
SNOR_HWCAPS_PP_1_4_4);
} else if (spi->mode & SPI_RX_DUAL) {
hwcaps.mask |= SNOR_HWCAPS_READ_1_1_2;
if (spi->mode & SPI_TX_DUAL)
hwcaps.mask |= SNOR_HWCAPS_READ_1_2_2;
}
if (data && data->name)
nor->mtd.name = data->name;
if (data && data->type)
flash_name = data->type;
else if (!strcmp(spi->modalias, "spi-nor"))
flash_name = NULL;
else
flash_name = spi->modalias;
ret = spi_nor_scan(nor, flash_name, &hwcaps);
if (ret)
return ret;
return mtd_device_register(&nor->mtd, data ? data->parts : NULL,
data ? data->nr_parts : 0);
}
static int m25p_remove(struct spi_device *spi)
{
struct m25p *flash = spi_get_drvdata(spi);
return mtd_device_unregister(&flash->spi_nor.mtd);
}
