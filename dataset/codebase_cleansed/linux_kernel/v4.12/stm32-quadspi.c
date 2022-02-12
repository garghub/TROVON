static int stm32_qspi_wait_cmd(struct stm32_qspi *qspi)
{
u32 cr;
int err = 0;
if (readl_relaxed(qspi->io_base + QUADSPI_SR) & SR_TCF)
return 0;
reinit_completion(&qspi->cmd_completion);
cr = readl_relaxed(qspi->io_base + QUADSPI_CR);
writel_relaxed(cr | CR_TCIE, qspi->io_base + QUADSPI_CR);
if (!wait_for_completion_interruptible_timeout(&qspi->cmd_completion,
msecs_to_jiffies(1000)))
err = -ETIMEDOUT;
writel_relaxed(cr, qspi->io_base + QUADSPI_CR);
return err;
}
static int stm32_qspi_wait_nobusy(struct stm32_qspi *qspi)
{
u32 sr;
return readl_relaxed_poll_timeout(qspi->io_base + QUADSPI_SR, sr,
!(sr & SR_BUSY), 10,
STM32_QSPI_BUSY_TIMEOUT_US);
}
static void stm32_qspi_set_framemode(struct spi_nor *nor,
struct stm32_qspi_cmd *cmd, bool read)
{
u32 dmode = CCR_DMODE_1;
cmd->framemode = CCR_IMODE_1;
if (read) {
switch (nor->flash_read) {
case SPI_NOR_NORMAL:
case SPI_NOR_FAST:
dmode = CCR_DMODE_1;
break;
case SPI_NOR_DUAL:
dmode = CCR_DMODE_2;
break;
case SPI_NOR_QUAD:
dmode = CCR_DMODE_4;
break;
}
}
cmd->framemode |= cmd->tx_data ? dmode : 0;
cmd->framemode |= cmd->addr_width ? CCR_ADMODE_1 : 0;
}
static void stm32_qspi_read_fifo(u8 *val, void __iomem *addr)
{
*val = readb_relaxed(addr);
}
static void stm32_qspi_write_fifo(u8 *val, void __iomem *addr)
{
writeb_relaxed(*val, addr);
}
static int stm32_qspi_tx_poll(struct stm32_qspi *qspi,
const struct stm32_qspi_cmd *cmd)
{
void (*tx_fifo)(u8 *, void __iomem *);
u32 len = cmd->len, sr;
u8 *buf = cmd->buf;
int ret;
if (cmd->qspimode == CCR_FMODE_INDW)
tx_fifo = stm32_qspi_write_fifo;
else
tx_fifo = stm32_qspi_read_fifo;
while (len--) {
ret = readl_relaxed_poll_timeout(qspi->io_base + QUADSPI_SR,
sr, (sr & SR_FTF), 10,
STM32_QSPI_FIFO_TIMEOUT_US);
if (ret) {
dev_err(qspi->dev, "fifo timeout (stat:%#x)\n", sr);
break;
}
tx_fifo(buf++, qspi->io_base + QUADSPI_DR);
}
return ret;
}
static int stm32_qspi_tx_mm(struct stm32_qspi *qspi,
const struct stm32_qspi_cmd *cmd)
{
memcpy_fromio(cmd->buf, qspi->mm_base + cmd->addr, cmd->len);
return 0;
}
static int stm32_qspi_tx(struct stm32_qspi *qspi,
const struct stm32_qspi_cmd *cmd)
{
if (!cmd->tx_data)
return 0;
if (cmd->qspimode == CCR_FMODE_MM)
return stm32_qspi_tx_mm(qspi, cmd);
return stm32_qspi_tx_poll(qspi, cmd);
}
static int stm32_qspi_send(struct stm32_qspi_flash *flash,
const struct stm32_qspi_cmd *cmd)
{
struct stm32_qspi *qspi = flash->qspi;
u32 ccr, dcr, cr;
int err;
err = stm32_qspi_wait_nobusy(qspi);
if (err)
goto abort;
dcr = readl_relaxed(qspi->io_base + QUADSPI_DCR) & ~DCR_FSIZE_MASK;
dcr |= DCR_FSIZE(flash->fsize);
writel_relaxed(dcr, qspi->io_base + QUADSPI_DCR);
cr = readl_relaxed(qspi->io_base + QUADSPI_CR);
cr &= ~CR_PRESC_MASK & ~CR_FSEL;
cr |= CR_PRESC(flash->presc);
cr |= flash->cs ? CR_FSEL : 0;
writel_relaxed(cr, qspi->io_base + QUADSPI_CR);
if (cmd->tx_data)
writel_relaxed(cmd->len - 1, qspi->io_base + QUADSPI_DLR);
ccr = cmd->framemode | cmd->qspimode;
if (cmd->dummy)
ccr |= CCR_DCYC(cmd->dummy);
if (cmd->addr_width)
ccr |= CCR_ADSIZE(cmd->addr_width - 1);
ccr |= CCR_INST(cmd->opcode);
writel_relaxed(ccr, qspi->io_base + QUADSPI_CCR);
if (cmd->addr_width && cmd->qspimode != CCR_FMODE_MM)
writel_relaxed(cmd->addr, qspi->io_base + QUADSPI_AR);
err = stm32_qspi_tx(qspi, cmd);
if (err)
goto abort;
if (cmd->qspimode != CCR_FMODE_MM) {
err = stm32_qspi_wait_cmd(qspi);
if (err)
goto abort;
writel_relaxed(FCR_CTCF, qspi->io_base + QUADSPI_FCR);
}
return err;
abort:
cr = readl_relaxed(qspi->io_base + QUADSPI_CR) | CR_ABORT;
writel_relaxed(cr, qspi->io_base + QUADSPI_CR);
dev_err(qspi->dev, "%s abort err:%d\n", __func__, err);
return err;
}
static int stm32_qspi_read_reg(struct spi_nor *nor,
u8 opcode, u8 *buf, int len)
{
struct stm32_qspi_flash *flash = nor->priv;
struct device *dev = flash->qspi->dev;
struct stm32_qspi_cmd cmd;
dev_dbg(dev, "read_reg: cmd:%#.2x buf:%p len:%#x\n", opcode, buf, len);
memset(&cmd, 0, sizeof(cmd));
cmd.opcode = opcode;
cmd.tx_data = true;
cmd.len = len;
cmd.buf = buf;
cmd.qspimode = CCR_FMODE_INDR;
stm32_qspi_set_framemode(nor, &cmd, false);
return stm32_qspi_send(flash, &cmd);
}
static int stm32_qspi_write_reg(struct spi_nor *nor, u8 opcode,
u8 *buf, int len)
{
struct stm32_qspi_flash *flash = nor->priv;
struct device *dev = flash->qspi->dev;
struct stm32_qspi_cmd cmd;
dev_dbg(dev, "write_reg: cmd:%#.2x buf:%p len:%#x\n", opcode, buf, len);
memset(&cmd, 0, sizeof(cmd));
cmd.opcode = opcode;
cmd.tx_data = !!(buf && len > 0);
cmd.len = len;
cmd.buf = buf;
cmd.qspimode = CCR_FMODE_INDW;
stm32_qspi_set_framemode(nor, &cmd, false);
return stm32_qspi_send(flash, &cmd);
}
static ssize_t stm32_qspi_read(struct spi_nor *nor, loff_t from, size_t len,
u_char *buf)
{
struct stm32_qspi_flash *flash = nor->priv;
struct stm32_qspi *qspi = flash->qspi;
struct stm32_qspi_cmd cmd;
int err;
dev_dbg(qspi->dev, "read(%#.2x): buf:%p from:%#.8x len:%#x\n",
nor->read_opcode, buf, (u32)from, len);
memset(&cmd, 0, sizeof(cmd));
cmd.opcode = nor->read_opcode;
cmd.addr_width = nor->addr_width;
cmd.addr = (u32)from;
cmd.tx_data = true;
cmd.dummy = nor->read_dummy;
cmd.len = len;
cmd.buf = buf;
cmd.qspimode = flash->read_mode;
stm32_qspi_set_framemode(nor, &cmd, true);
err = stm32_qspi_send(flash, &cmd);
return err ? err : len;
}
static ssize_t stm32_qspi_write(struct spi_nor *nor, loff_t to, size_t len,
const u_char *buf)
{
struct stm32_qspi_flash *flash = nor->priv;
struct device *dev = flash->qspi->dev;
struct stm32_qspi_cmd cmd;
int err;
dev_dbg(dev, "write(%#.2x): buf:%p to:%#.8x len:%#x\n",
nor->program_opcode, buf, (u32)to, len);
memset(&cmd, 0, sizeof(cmd));
cmd.opcode = nor->program_opcode;
cmd.addr_width = nor->addr_width;
cmd.addr = (u32)to;
cmd.tx_data = true;
cmd.len = len;
cmd.buf = (void *)buf;
cmd.qspimode = CCR_FMODE_INDW;
stm32_qspi_set_framemode(nor, &cmd, false);
err = stm32_qspi_send(flash, &cmd);
return err ? err : len;
}
static int stm32_qspi_erase(struct spi_nor *nor, loff_t offs)
{
struct stm32_qspi_flash *flash = nor->priv;
struct device *dev = flash->qspi->dev;
struct stm32_qspi_cmd cmd;
dev_dbg(dev, "erase(%#.2x):offs:%#x\n", nor->erase_opcode, (u32)offs);
memset(&cmd, 0, sizeof(cmd));
cmd.opcode = nor->erase_opcode;
cmd.addr_width = nor->addr_width;
cmd.addr = (u32)offs;
cmd.qspimode = CCR_FMODE_INDW;
stm32_qspi_set_framemode(nor, &cmd, false);
return stm32_qspi_send(flash, &cmd);
}
static irqreturn_t stm32_qspi_irq(int irq, void *dev_id)
{
struct stm32_qspi *qspi = (struct stm32_qspi *)dev_id;
u32 cr, sr, fcr = 0;
cr = readl_relaxed(qspi->io_base + QUADSPI_CR);
sr = readl_relaxed(qspi->io_base + QUADSPI_SR);
if ((cr & CR_TCIE) && (sr & SR_TCF)) {
fcr |= FCR_CTCF;
complete(&qspi->cmd_completion);
} else {
dev_info_ratelimited(qspi->dev, "spurious interrupt\n");
}
writel_relaxed(fcr, qspi->io_base + QUADSPI_FCR);
return IRQ_HANDLED;
}
static int stm32_qspi_prep(struct spi_nor *nor, enum spi_nor_ops ops)
{
struct stm32_qspi_flash *flash = nor->priv;
struct stm32_qspi *qspi = flash->qspi;
mutex_lock(&qspi->lock);
return 0;
}
static void stm32_qspi_unprep(struct spi_nor *nor, enum spi_nor_ops ops)
{
struct stm32_qspi_flash *flash = nor->priv;
struct stm32_qspi *qspi = flash->qspi;
mutex_unlock(&qspi->lock);
}
static int stm32_qspi_flash_setup(struct stm32_qspi *qspi,
struct device_node *np)
{
u32 width, flash_read, presc, cs_num, max_rate = 0;
struct stm32_qspi_flash *flash;
struct mtd_info *mtd;
int ret;
of_property_read_u32(np, "reg", &cs_num);
if (cs_num >= STM32_MAX_NORCHIP)
return -EINVAL;
of_property_read_u32(np, "spi-max-frequency", &max_rate);
if (!max_rate)
return -EINVAL;
presc = DIV_ROUND_UP(qspi->clk_rate, max_rate) - 1;
if (of_property_read_u32(np, "spi-rx-bus-width", &width))
width = 1;
if (width == 4)
flash_read = SPI_NOR_QUAD;
else if (width == 2)
flash_read = SPI_NOR_DUAL;
else if (width == 1)
flash_read = SPI_NOR_NORMAL;
else
return -EINVAL;
flash = &qspi->flash[cs_num];
flash->qspi = qspi;
flash->cs = cs_num;
flash->presc = presc;
flash->nor.dev = qspi->dev;
spi_nor_set_flash_node(&flash->nor, np);
flash->nor.priv = flash;
mtd = &flash->nor.mtd;
flash->nor.read = stm32_qspi_read;
flash->nor.write = stm32_qspi_write;
flash->nor.erase = stm32_qspi_erase;
flash->nor.read_reg = stm32_qspi_read_reg;
flash->nor.write_reg = stm32_qspi_write_reg;
flash->nor.prepare = stm32_qspi_prep;
flash->nor.unprepare = stm32_qspi_unprep;
writel_relaxed(LPTR_DFT_TIMEOUT, qspi->io_base + QUADSPI_LPTR);
writel_relaxed(CR_PRESC(presc) | CR_FTHRES(3) | CR_TCEN | CR_SSHIFT
| CR_EN, qspi->io_base + QUADSPI_CR);
flash->fsize = FSIZE_VAL(SZ_1K);
ret = spi_nor_scan(&flash->nor, NULL, flash_read);
if (ret) {
dev_err(qspi->dev, "device scan failed\n");
return ret;
}
flash->fsize = FSIZE_VAL(mtd->size);
flash->read_mode = CCR_FMODE_MM;
if (mtd->size > qspi->mm_size)
flash->read_mode = CCR_FMODE_INDR;
writel_relaxed(DCR_CSHT(1), qspi->io_base + QUADSPI_DCR);
ret = mtd_device_register(mtd, NULL, 0);
if (ret) {
dev_err(qspi->dev, "mtd device parse failed\n");
return ret;
}
flash->registered = true;
dev_dbg(qspi->dev, "read mm:%s cs:%d bus:%d\n",
flash->read_mode == CCR_FMODE_MM ? "yes" : "no", cs_num, width);
return 0;
}
static void stm32_qspi_mtd_free(struct stm32_qspi *qspi)
{
int i;
for (i = 0; i < STM32_MAX_NORCHIP; i++)
if (qspi->flash[i].registered)
mtd_device_unregister(&qspi->flash[i].nor.mtd);
}
static int stm32_qspi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *flash_np;
struct reset_control *rstc;
struct stm32_qspi *qspi;
struct resource *res;
int ret, irq;
qspi = devm_kzalloc(dev, sizeof(*qspi), GFP_KERNEL);
if (!qspi)
return -ENOMEM;
qspi->nor_num = of_get_child_count(dev->of_node);
if (!qspi->nor_num || qspi->nor_num > STM32_MAX_NORCHIP)
return -ENODEV;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "qspi");
qspi->io_base = devm_ioremap_resource(dev, res);
if (IS_ERR(qspi->io_base))
return PTR_ERR(qspi->io_base);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "qspi_mm");
qspi->mm_base = devm_ioremap_resource(dev, res);
if (IS_ERR(qspi->mm_base))
return PTR_ERR(qspi->mm_base);
qspi->mm_size = resource_size(res);
irq = platform_get_irq(pdev, 0);
ret = devm_request_irq(dev, irq, stm32_qspi_irq, 0,
dev_name(dev), qspi);
if (ret) {
dev_err(dev, "failed to request irq\n");
return ret;
}
init_completion(&qspi->cmd_completion);
qspi->clk = devm_clk_get(dev, NULL);
if (IS_ERR(qspi->clk))
return PTR_ERR(qspi->clk);
qspi->clk_rate = clk_get_rate(qspi->clk);
if (!qspi->clk_rate)
return -EINVAL;
ret = clk_prepare_enable(qspi->clk);
if (ret) {
dev_err(dev, "can not enable the clock\n");
return ret;
}
rstc = devm_reset_control_get(dev, NULL);
if (!IS_ERR(rstc)) {
reset_control_assert(rstc);
udelay(2);
reset_control_deassert(rstc);
}
qspi->dev = dev;
platform_set_drvdata(pdev, qspi);
mutex_init(&qspi->lock);
for_each_available_child_of_node(dev->of_node, flash_np) {
ret = stm32_qspi_flash_setup(qspi, flash_np);
if (ret) {
dev_err(dev, "unable to setup flash chip\n");
goto err_flash;
}
}
return 0;
err_flash:
mutex_destroy(&qspi->lock);
stm32_qspi_mtd_free(qspi);
clk_disable_unprepare(qspi->clk);
return ret;
}
static int stm32_qspi_remove(struct platform_device *pdev)
{
struct stm32_qspi *qspi = platform_get_drvdata(pdev);
writel_relaxed(0, qspi->io_base + QUADSPI_CR);
stm32_qspi_mtd_free(qspi);
mutex_destroy(&qspi->lock);
clk_disable_unprepare(qspi->clk);
return 0;
}
