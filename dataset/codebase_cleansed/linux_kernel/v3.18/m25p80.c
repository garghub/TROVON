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
static int m25p80_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len,
int wr_en)
{
struct m25p *flash = nor->priv;
struct spi_device *spi = flash->spi;
flash->command[0] = opcode;
if (buf)
memcpy(&flash->command[1], buf, len);
return spi_write(spi, flash->command, len + 1);
}
static void m25p80_write(struct spi_nor *nor, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct m25p *flash = nor->priv;
struct spi_device *spi = flash->spi;
struct spi_transfer t[2] = {};
struct spi_message m;
int cmd_sz = m25p_cmdsz(nor);
spi_message_init(&m);
if (nor->program_opcode == SPINOR_OP_AAI_WP && nor->sst_write_second)
cmd_sz = 1;
flash->command[0] = nor->program_opcode;
m25p_addr2cmd(nor, to, flash->command);
t[0].tx_buf = flash->command;
t[0].len = cmd_sz;
spi_message_add_tail(&t[0], &m);
t[1].tx_buf = buf;
t[1].len = len;
spi_message_add_tail(&t[1], &m);
spi_sync(spi, &m);
*retlen += m.actual_length - cmd_sz;
}
static inline unsigned int m25p80_rx_nbits(struct spi_nor *nor)
{
switch (nor->flash_read) {
case SPI_NOR_DUAL:
return 2;
case SPI_NOR_QUAD:
return 4;
default:
return 0;
}
}
static int m25p80_read(struct spi_nor *nor, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
struct m25p *flash = nor->priv;
struct spi_device *spi = flash->spi;
struct spi_transfer t[2];
struct spi_message m;
int dummy = nor->read_dummy;
int ret;
ret = nor->wait_till_ready(nor);
if (ret)
return ret;
spi_message_init(&m);
memset(t, 0, (sizeof t));
flash->command[0] = nor->read_opcode;
m25p_addr2cmd(nor, from, flash->command);
t[0].tx_buf = flash->command;
t[0].len = m25p_cmdsz(nor) + dummy;
spi_message_add_tail(&t[0], &m);
t[1].rx_buf = buf;
t[1].rx_nbits = m25p80_rx_nbits(nor);
t[1].len = len;
spi_message_add_tail(&t[1], &m);
spi_sync(spi, &m);
*retlen = m.actual_length - m25p_cmdsz(nor) - dummy;
return 0;
}
static int m25p80_erase(struct spi_nor *nor, loff_t offset)
{
struct m25p *flash = nor->priv;
int ret;
dev_dbg(nor->dev, "%dKiB at 0x%08x\n",
flash->mtd.erasesize / 1024, (u32)offset);
ret = nor->wait_till_ready(nor);
if (ret)
return ret;
ret = nor->write_reg(nor, SPINOR_OP_WREN, NULL, 0, 0);
if (ret)
return ret;
flash->command[0] = nor->erase_opcode;
m25p_addr2cmd(nor, offset, flash->command);
spi_write(flash->spi, flash->command, m25p_cmdsz(nor));
return 0;
}
static int m25p_probe(struct spi_device *spi)
{
struct mtd_part_parser_data ppdata;
struct flash_platform_data *data;
struct m25p *flash;
struct spi_nor *nor;
enum read_mode mode = SPI_NOR_NORMAL;
char *flash_name = NULL;
int ret;
data = dev_get_platdata(&spi->dev);
flash = devm_kzalloc(&spi->dev, sizeof(*flash), GFP_KERNEL);
if (!flash)
return -ENOMEM;
nor = &flash->spi_nor;
nor->read = m25p80_read;
nor->write = m25p80_write;
nor->erase = m25p80_erase;
nor->write_reg = m25p80_write_reg;
nor->read_reg = m25p80_read_reg;
nor->dev = &spi->dev;
nor->mtd = &flash->mtd;
nor->priv = flash;
spi_set_drvdata(spi, flash);
flash->mtd.priv = nor;
flash->spi = spi;
if (spi->mode & SPI_RX_QUAD)
mode = SPI_NOR_QUAD;
else if (spi->mode & SPI_RX_DUAL)
mode = SPI_NOR_DUAL;
if (data && data->name)
flash->mtd.name = data->name;
if (data && data->type)
flash_name = data->type;
else
flash_name = spi->modalias;
ret = spi_nor_scan(nor, flash_name, mode);
if (ret)
return ret;
ppdata.of_node = spi->dev.of_node;
return mtd_device_parse_register(&flash->mtd, NULL, &ppdata,
data ? data->parts : NULL,
data ? data->nr_parts : 0);
}
static int m25p_remove(struct spi_device *spi)
{
struct m25p *flash = spi_get_drvdata(spi);
return mtd_device_unregister(&flash->mtd);
}
