static int nxp_spifi_wait_for_cmd(struct nxp_spifi *spifi)
{
u8 stat;
int ret;
ret = readb_poll_timeout(spifi->io_base + SPIFI_STAT, stat,
!(stat & SPIFI_STAT_CMD), 10, 30);
if (ret)
dev_warn(spifi->dev, "command timed out\n");
return ret;
}
static int nxp_spifi_reset(struct nxp_spifi *spifi)
{
u8 stat;
int ret;
writel(SPIFI_STAT_RESET, spifi->io_base + SPIFI_STAT);
ret = readb_poll_timeout(spifi->io_base + SPIFI_STAT, stat,
!(stat & SPIFI_STAT_RESET), 10, 30);
if (ret)
dev_warn(spifi->dev, "state reset timed out\n");
return ret;
}
static int nxp_spifi_set_memory_mode_off(struct nxp_spifi *spifi)
{
int ret;
if (!spifi->memory_mode)
return 0;
ret = nxp_spifi_reset(spifi);
if (ret)
dev_err(spifi->dev, "unable to enter command mode\n");
else
spifi->memory_mode = false;
return ret;
}
static int nxp_spifi_set_memory_mode_on(struct nxp_spifi *spifi)
{
u8 stat;
int ret;
if (spifi->memory_mode)
return 0;
writel(spifi->mcmd, spifi->io_base + SPIFI_MCMD);
ret = readb_poll_timeout(spifi->io_base + SPIFI_STAT, stat,
stat & SPIFI_STAT_MCINIT, 10, 30);
if (ret)
dev_err(spifi->dev, "unable to enter memory mode\n");
else
spifi->memory_mode = true;
return ret;
}
static int nxp_spifi_read_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
struct nxp_spifi *spifi = nor->priv;
u32 cmd;
int ret;
ret = nxp_spifi_set_memory_mode_off(spifi);
if (ret)
return ret;
cmd = SPIFI_CMD_DATALEN(len) |
SPIFI_CMD_OPCODE(opcode) |
SPIFI_CMD_FIELDFORM_ALL_SERIAL |
SPIFI_CMD_FRAMEFORM_OPCODE_ONLY;
writel(cmd, spifi->io_base + SPIFI_CMD);
while (len--)
*buf++ = readb(spifi->io_base + SPIFI_DATA);
return nxp_spifi_wait_for_cmd(spifi);
}
static int nxp_spifi_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
struct nxp_spifi *spifi = nor->priv;
u32 cmd;
int ret;
ret = nxp_spifi_set_memory_mode_off(spifi);
if (ret)
return ret;
cmd = SPIFI_CMD_DOUT |
SPIFI_CMD_DATALEN(len) |
SPIFI_CMD_OPCODE(opcode) |
SPIFI_CMD_FIELDFORM_ALL_SERIAL |
SPIFI_CMD_FRAMEFORM_OPCODE_ONLY;
writel(cmd, spifi->io_base + SPIFI_CMD);
while (len--)
writeb(*buf++, spifi->io_base + SPIFI_DATA);
return nxp_spifi_wait_for_cmd(spifi);
}
static int nxp_spifi_read(struct spi_nor *nor, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
struct nxp_spifi *spifi = nor->priv;
int ret;
ret = nxp_spifi_set_memory_mode_on(spifi);
if (ret)
return ret;
memcpy_fromio(buf, spifi->flash_base + from, len);
*retlen += len;
return 0;
}
static void nxp_spifi_write(struct spi_nor *nor, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct nxp_spifi *spifi = nor->priv;
u32 cmd;
int ret;
ret = nxp_spifi_set_memory_mode_off(spifi);
if (ret)
return;
writel(to, spifi->io_base + SPIFI_ADDR);
*retlen += len;
cmd = SPIFI_CMD_DOUT |
SPIFI_CMD_DATALEN(len) |
SPIFI_CMD_FIELDFORM_ALL_SERIAL |
SPIFI_CMD_OPCODE(nor->program_opcode) |
SPIFI_CMD_FRAMEFORM(spifi->nor.addr_width + 1);
writel(cmd, spifi->io_base + SPIFI_CMD);
while (len--)
writeb(*buf++, spifi->io_base + SPIFI_DATA);
nxp_spifi_wait_for_cmd(spifi);
}
static int nxp_spifi_erase(struct spi_nor *nor, loff_t offs)
{
struct nxp_spifi *spifi = nor->priv;
u32 cmd;
int ret;
ret = nxp_spifi_set_memory_mode_off(spifi);
if (ret)
return ret;
writel(offs, spifi->io_base + SPIFI_ADDR);
cmd = SPIFI_CMD_FIELDFORM_ALL_SERIAL |
SPIFI_CMD_OPCODE(nor->erase_opcode) |
SPIFI_CMD_FRAMEFORM(spifi->nor.addr_width + 1);
writel(cmd, spifi->io_base + SPIFI_CMD);
return nxp_spifi_wait_for_cmd(spifi);
}
static int nxp_spifi_setup_memory_cmd(struct nxp_spifi *spifi)
{
switch (spifi->nor.flash_read) {
case SPI_NOR_NORMAL:
case SPI_NOR_FAST:
spifi->mcmd = SPIFI_CMD_FIELDFORM_ALL_SERIAL;
break;
case SPI_NOR_DUAL:
case SPI_NOR_QUAD:
spifi->mcmd = SPIFI_CMD_FIELDFORM_QUAD_DUAL_DATA;
break;
default:
dev_err(spifi->dev, "unsupported SPI read mode\n");
return -EINVAL;
}
if (spifi->nor.addr_width < 1 || spifi->nor.addr_width > 4)
return -EINVAL;
spifi->mcmd |= SPIFI_CMD_OPCODE(spifi->nor.read_opcode) |
SPIFI_CMD_INTLEN(spifi->nor.read_dummy / 8) |
SPIFI_CMD_FRAMEFORM(spifi->nor.addr_width + 1);
return 0;
}
static void nxp_spifi_dummy_id_read(struct spi_nor *nor)
{
u8 id[SPI_NOR_MAX_ID_LEN];
nor->read_reg(nor, SPINOR_OP_RDID, id, SPI_NOR_MAX_ID_LEN);
}
static int nxp_spifi_setup_flash(struct nxp_spifi *spifi,
struct device_node *np)
{
enum read_mode flash_read;
u32 ctrl, property;
u16 mode = 0;
int ret;
if (!of_property_read_u32(np, "spi-rx-bus-width", &property)) {
switch (property) {
case 1:
break;
case 2:
mode |= SPI_RX_DUAL;
break;
case 4:
mode |= SPI_RX_QUAD;
break;
default:
dev_err(spifi->dev, "unsupported rx-bus-width\n");
return -EINVAL;
}
}
if (of_find_property(np, "spi-cpha", NULL))
mode |= SPI_CPHA;
if (of_find_property(np, "spi-cpol", NULL))
mode |= SPI_CPOL;
ctrl = SPIFI_CTRL_TIMEOUT(1000) |
SPIFI_CTRL_CSHIGH(15) |
SPIFI_CTRL_FBCLK;
if (mode & SPI_RX_DUAL) {
ctrl |= SPIFI_CTRL_DUAL;
flash_read = SPI_NOR_DUAL;
} else if (mode & SPI_RX_QUAD) {
ctrl &= ~SPIFI_CTRL_DUAL;
flash_read = SPI_NOR_QUAD;
} else {
ctrl |= SPIFI_CTRL_DUAL;
flash_read = SPI_NOR_NORMAL;
}
switch (mode & (SPI_CPHA | SPI_CPOL)) {
case SPI_MODE_0:
ctrl &= ~SPIFI_CTRL_MODE3;
break;
case SPI_MODE_3:
ctrl |= SPIFI_CTRL_MODE3;
break;
default:
dev_err(spifi->dev, "only mode 0 and 3 supported\n");
return -EINVAL;
}
writel(ctrl, spifi->io_base + SPIFI_CTRL);
spifi->nor.dev = spifi->dev;
spi_nor_set_flash_node(&spifi->nor, np);
spifi->nor.priv = spifi;
spifi->nor.read = nxp_spifi_read;
spifi->nor.write = nxp_spifi_write;
spifi->nor.erase = nxp_spifi_erase;
spifi->nor.read_reg = nxp_spifi_read_reg;
spifi->nor.write_reg = nxp_spifi_write_reg;
nxp_spifi_dummy_id_read(&spifi->nor);
ret = spi_nor_scan(&spifi->nor, NULL, flash_read);
if (ret) {
dev_err(spifi->dev, "device scan failed\n");
return ret;
}
ret = nxp_spifi_setup_memory_cmd(spifi);
if (ret) {
dev_err(spifi->dev, "memory command setup failed\n");
return ret;
}
ret = mtd_device_register(&spifi->nor.mtd, NULL, 0);
if (ret) {
dev_err(spifi->dev, "mtd device parse failed\n");
return ret;
}
return 0;
}
static int nxp_spifi_probe(struct platform_device *pdev)
{
struct device_node *flash_np;
struct nxp_spifi *spifi;
struct resource *res;
int ret;
spifi = devm_kzalloc(&pdev->dev, sizeof(*spifi), GFP_KERNEL);
if (!spifi)
return -ENOMEM;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "spifi");
spifi->io_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(spifi->io_base))
return PTR_ERR(spifi->io_base);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "flash");
spifi->flash_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(spifi->flash_base))
return PTR_ERR(spifi->flash_base);
spifi->clk_spifi = devm_clk_get(&pdev->dev, "spifi");
if (IS_ERR(spifi->clk_spifi)) {
dev_err(&pdev->dev, "spifi clock not found\n");
return PTR_ERR(spifi->clk_spifi);
}
spifi->clk_reg = devm_clk_get(&pdev->dev, "reg");
if (IS_ERR(spifi->clk_reg)) {
dev_err(&pdev->dev, "reg clock not found\n");
return PTR_ERR(spifi->clk_reg);
}
ret = clk_prepare_enable(spifi->clk_reg);
if (ret) {
dev_err(&pdev->dev, "unable to enable reg clock\n");
return ret;
}
ret = clk_prepare_enable(spifi->clk_spifi);
if (ret) {
dev_err(&pdev->dev, "unable to enable spifi clock\n");
goto dis_clk_reg;
}
spifi->dev = &pdev->dev;
platform_set_drvdata(pdev, spifi);
nxp_spifi_reset(spifi);
writel(0, spifi->io_base + SPIFI_IDATA);
writel(0, spifi->io_base + SPIFI_MCMD);
nxp_spifi_reset(spifi);
flash_np = of_get_next_available_child(pdev->dev.of_node, NULL);
if (!flash_np) {
dev_err(&pdev->dev, "no SPI flash device to configure\n");
ret = -ENODEV;
goto dis_clks;
}
ret = nxp_spifi_setup_flash(spifi, flash_np);
if (ret) {
dev_err(&pdev->dev, "unable to setup flash chip\n");
goto dis_clks;
}
return 0;
dis_clks:
clk_disable_unprepare(spifi->clk_spifi);
dis_clk_reg:
clk_disable_unprepare(spifi->clk_reg);
return ret;
}
static int nxp_spifi_remove(struct platform_device *pdev)
{
struct nxp_spifi *spifi = platform_get_drvdata(pdev);
mtd_device_unregister(&spifi->nor.mtd);
clk_disable_unprepare(spifi->clk_spifi);
clk_disable_unprepare(spifi->clk_reg);
return 0;
}
