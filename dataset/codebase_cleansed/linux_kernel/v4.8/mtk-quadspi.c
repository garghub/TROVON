static void mt8173_nor_set_read_mode(struct mt8173_nor *mt8173_nor)
{
struct spi_nor *nor = &mt8173_nor->nor;
switch (nor->flash_read) {
case SPI_NOR_FAST:
writeb(nor->read_opcode, mt8173_nor->base +
MTK_NOR_PRGDATA3_REG);
writeb(MTK_NOR_FAST_READ, mt8173_nor->base +
MTK_NOR_CFG1_REG);
break;
case SPI_NOR_DUAL:
writeb(nor->read_opcode, mt8173_nor->base +
MTK_NOR_PRGDATA3_REG);
writeb(MTK_NOR_DUAL_READ_EN, mt8173_nor->base +
MTK_NOR_DUAL_REG);
break;
case SPI_NOR_QUAD:
writeb(nor->read_opcode, mt8173_nor->base +
MTK_NOR_PRGDATA4_REG);
writeb(MTK_NOR_QUAD_READ_EN, mt8173_nor->base +
MTK_NOR_DUAL_REG);
break;
default:
writeb(MTK_NOR_DUAL_DISABLE, mt8173_nor->base +
MTK_NOR_DUAL_REG);
break;
}
}
static int mt8173_nor_execute_cmd(struct mt8173_nor *mt8173_nor, u8 cmdval)
{
int reg;
u8 val = cmdval & 0x1f;
writeb(cmdval, mt8173_nor->base + MTK_NOR_CMD_REG);
return readl_poll_timeout(mt8173_nor->base + MTK_NOR_CMD_REG, reg,
!(reg & val), 100, 10000);
}
static int mt8173_nor_do_tx_rx(struct mt8173_nor *mt8173_nor, u8 op,
u8 *tx, int txlen, u8 *rx, int rxlen)
{
int len = 1 + txlen + rxlen;
int i, ret, idx;
if (len > MTK_NOR_MAX_SHIFT)
return -EINVAL;
writeb(len * 8, mt8173_nor->base + MTK_NOR_CNT_REG);
idx = MTK_NOR_MAX_RX_TX_SHIFT - 1;
writeb(op, mt8173_nor->base + MTK_NOR_PRG_REG(idx));
idx--;
for (i = 0; i < txlen; i++, idx--)
writeb(tx[i], mt8173_nor->base + MTK_NOR_PRG_REG(idx));
while (idx >= 0) {
writeb(0, mt8173_nor->base + MTK_NOR_PRG_REG(idx));
idx--;
}
ret = mt8173_nor_execute_cmd(mt8173_nor, MTK_NOR_PRG_CMD);
if (ret)
return ret;
idx = rxlen - 1;
for (i = 0; i < rxlen; i++, idx--)
rx[i] = readb(mt8173_nor->base + MTK_NOR_SHREG(idx));
return 0;
}
static int mt8173_nor_wr_sr(struct mt8173_nor *mt8173_nor, u8 sr)
{
writeb(sr, mt8173_nor->base + MTK_NOR_PRGDATA5_REG);
writeb(8, mt8173_nor->base + MTK_NOR_CNT_REG);
return mt8173_nor_execute_cmd(mt8173_nor, MTK_NOR_WRSR_CMD);
}
static int mt8173_nor_write_buffer_enable(struct mt8173_nor *mt8173_nor)
{
u8 reg;
writel(MTK_NOR_WR_BUF_ENABLE, mt8173_nor->base + MTK_NOR_CFG2_REG);
return readb_poll_timeout(mt8173_nor->base + MTK_NOR_CFG2_REG, reg,
0x01 == (reg & 0x01), 100, 10000);
}
static int mt8173_nor_write_buffer_disable(struct mt8173_nor *mt8173_nor)
{
u8 reg;
writel(MTK_NOR_WR_BUF_DISABLE, mt8173_nor->base + MTK_NOR_CFG2_REG);
return readb_poll_timeout(mt8173_nor->base + MTK_NOR_CFG2_REG, reg,
MTK_NOR_WR_BUF_DISABLE == (reg & 0x1), 100,
10000);
}
static void mt8173_nor_set_addr(struct mt8173_nor *mt8173_nor, u32 addr)
{
int i;
for (i = 0; i < 3; i++) {
writeb(addr & 0xff, mt8173_nor->base + MTK_NOR_RADR0_REG + i * 4);
addr >>= 8;
}
writeb(addr & 0xff, mt8173_nor->base + MTK_NOR_RADR3_REG);
}
static ssize_t mt8173_nor_read(struct spi_nor *nor, loff_t from, size_t length,
u_char *buffer)
{
int i, ret;
int addr = (int)from;
u8 *buf = (u8 *)buffer;
struct mt8173_nor *mt8173_nor = nor->priv;
mt8173_nor_set_read_mode(mt8173_nor);
mt8173_nor_set_addr(mt8173_nor, addr);
for (i = 0; i < length; i++) {
ret = mt8173_nor_execute_cmd(mt8173_nor, MTK_NOR_PIO_READ_CMD);
if (ret < 0)
return ret;
buf[i] = readb(mt8173_nor->base + MTK_NOR_RDATA_REG);
}
return length;
}
static int mt8173_nor_write_single_byte(struct mt8173_nor *mt8173_nor,
int addr, int length, u8 *data)
{
int i, ret;
mt8173_nor_set_addr(mt8173_nor, addr);
for (i = 0; i < length; i++) {
writeb(*data++, mt8173_nor->base + MTK_NOR_WDATA_REG);
ret = mt8173_nor_execute_cmd(mt8173_nor, MTK_NOR_PIO_WR_CMD);
if (ret < 0)
return ret;
}
return 0;
}
static int mt8173_nor_write_buffer(struct mt8173_nor *mt8173_nor, int addr,
const u8 *buf)
{
int i, bufidx, data;
mt8173_nor_set_addr(mt8173_nor, addr);
bufidx = 0;
for (i = 0; i < SFLASH_WRBUF_SIZE; i += 4) {
data = buf[bufidx + 3]<<24 | buf[bufidx + 2]<<16 |
buf[bufidx + 1]<<8 | buf[bufidx];
bufidx += 4;
writel(data, mt8173_nor->base + MTK_NOR_PP_DATA_REG);
}
return mt8173_nor_execute_cmd(mt8173_nor, MTK_NOR_WR_CMD);
}
static ssize_t mt8173_nor_write(struct spi_nor *nor, loff_t to, size_t len,
const u_char *buf)
{
int ret;
struct mt8173_nor *mt8173_nor = nor->priv;
size_t i;
ret = mt8173_nor_write_buffer_enable(mt8173_nor);
if (ret < 0) {
dev_warn(mt8173_nor->dev, "write buffer enable failed!\n");
return ret;
}
for (i = 0; i + SFLASH_WRBUF_SIZE <= len; i += SFLASH_WRBUF_SIZE) {
ret = mt8173_nor_write_buffer(mt8173_nor, to, buf);
if (ret < 0) {
dev_err(mt8173_nor->dev, "write buffer failed!\n");
return ret;
}
to += SFLASH_WRBUF_SIZE;
buf += SFLASH_WRBUF_SIZE;
}
ret = mt8173_nor_write_buffer_disable(mt8173_nor);
if (ret < 0) {
dev_warn(mt8173_nor->dev, "write buffer disable failed!\n");
return ret;
}
if (i < len) {
ret = mt8173_nor_write_single_byte(mt8173_nor, to,
(int)(len - i), (u8 *)buf);
if (ret < 0) {
dev_err(mt8173_nor->dev, "write single byte failed!\n");
return ret;
}
}
return len;
}
static int mt8173_nor_read_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
int ret;
struct mt8173_nor *mt8173_nor = nor->priv;
switch (opcode) {
case SPINOR_OP_RDSR:
ret = mt8173_nor_execute_cmd(mt8173_nor, MTK_NOR_RDSR_CMD);
if (ret < 0)
return ret;
if (len == 1)
*buf = readb(mt8173_nor->base + MTK_NOR_RDSR_REG);
else
dev_err(mt8173_nor->dev, "len should be 1 for read status!\n");
break;
default:
ret = mt8173_nor_do_tx_rx(mt8173_nor, opcode, NULL, 0, buf, len);
break;
}
return ret;
}
static int mt8173_nor_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf,
int len)
{
int ret;
struct mt8173_nor *mt8173_nor = nor->priv;
switch (opcode) {
case SPINOR_OP_WRSR:
ret = mt8173_nor_wr_sr(mt8173_nor, *buf);
break;
default:
ret = mt8173_nor_do_tx_rx(mt8173_nor, opcode, buf, len, NULL, 0);
if (ret)
dev_warn(mt8173_nor->dev, "write reg failure!\n");
break;
}
return ret;
}
static int mtk_nor_init(struct mt8173_nor *mt8173_nor,
struct device_node *flash_node)
{
int ret;
struct spi_nor *nor;
writel(MTK_NOR_ENABLE_SF_CMD, mt8173_nor->base + MTK_NOR_WRPROT_REG);
nor = &mt8173_nor->nor;
nor->dev = mt8173_nor->dev;
nor->priv = mt8173_nor;
spi_nor_set_flash_node(nor, flash_node);
nor->read = mt8173_nor_read;
nor->read_reg = mt8173_nor_read_reg;
nor->write = mt8173_nor_write;
nor->write_reg = mt8173_nor_write_reg;
nor->mtd.name = "mtk_nor";
ret = spi_nor_scan(nor, NULL, SPI_NOR_DUAL);
if (ret)
return ret;
return mtd_device_register(&nor->mtd, NULL, 0);
}
static int mtk_nor_drv_probe(struct platform_device *pdev)
{
struct device_node *flash_np;
struct resource *res;
int ret;
struct mt8173_nor *mt8173_nor;
if (!pdev->dev.of_node) {
dev_err(&pdev->dev, "No DT found\n");
return -EINVAL;
}
mt8173_nor = devm_kzalloc(&pdev->dev, sizeof(*mt8173_nor), GFP_KERNEL);
if (!mt8173_nor)
return -ENOMEM;
platform_set_drvdata(pdev, mt8173_nor);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mt8173_nor->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mt8173_nor->base))
return PTR_ERR(mt8173_nor->base);
mt8173_nor->spi_clk = devm_clk_get(&pdev->dev, "spi");
if (IS_ERR(mt8173_nor->spi_clk))
return PTR_ERR(mt8173_nor->spi_clk);
mt8173_nor->nor_clk = devm_clk_get(&pdev->dev, "sf");
if (IS_ERR(mt8173_nor->nor_clk))
return PTR_ERR(mt8173_nor->nor_clk);
mt8173_nor->dev = &pdev->dev;
ret = clk_prepare_enable(mt8173_nor->spi_clk);
if (ret)
return ret;
ret = clk_prepare_enable(mt8173_nor->nor_clk);
if (ret) {
clk_disable_unprepare(mt8173_nor->spi_clk);
return ret;
}
flash_np = of_get_next_available_child(pdev->dev.of_node, NULL);
if (!flash_np) {
dev_err(&pdev->dev, "no SPI flash device to configure\n");
ret = -ENODEV;
goto nor_free;
}
ret = mtk_nor_init(mt8173_nor, flash_np);
nor_free:
if (ret) {
clk_disable_unprepare(mt8173_nor->spi_clk);
clk_disable_unprepare(mt8173_nor->nor_clk);
}
return ret;
}
static int mtk_nor_drv_remove(struct platform_device *pdev)
{
struct mt8173_nor *mt8173_nor = platform_get_drvdata(pdev);
clk_disable_unprepare(mt8173_nor->spi_clk);
clk_disable_unprepare(mt8173_nor->nor_clk);
return 0;
}
