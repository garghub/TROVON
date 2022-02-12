static inline u32 qspi_readl(struct atmel_qspi *aq, u32 reg)
{
return readl_relaxed(aq->regs + reg);
}
static inline void qspi_writel(struct atmel_qspi *aq, u32 reg, u32 value)
{
writel_relaxed(value, aq->regs + reg);
}
static int atmel_qspi_run_transfer(struct atmel_qspi *aq,
const struct atmel_qspi_command *cmd)
{
void __iomem *ahb_mem;
ahb_mem = aq->mem;
if (cmd->enable.bits.address)
ahb_mem += cmd->address;
if (cmd->tx_buf)
_memcpy_toio(ahb_mem, cmd->tx_buf, cmd->buf_len);
else
_memcpy_fromio(cmd->rx_buf, ahb_mem, cmd->buf_len);
return 0;
}
static void atmel_qspi_debug_command(struct atmel_qspi *aq,
const struct atmel_qspi_command *cmd,
u32 ifr)
{
u8 cmd_buf[SPI_NOR_MAX_CMD_SIZE];
size_t len = 0;
int i;
if (cmd->enable.bits.instruction)
cmd_buf[len++] = cmd->instruction;
for (i = cmd->enable.bits.address-1; i >= 0; --i)
cmd_buf[len++] = (cmd->address >> (i << 3)) & 0xff;
if (cmd->enable.bits.mode)
cmd_buf[len++] = cmd->mode;
if (cmd->enable.bits.dummy) {
int num = cmd->num_dummy_cycles;
switch (ifr & QSPI_IFR_WIDTH_MASK) {
case QSPI_IFR_WIDTH_SINGLE_BIT_SPI:
case QSPI_IFR_WIDTH_DUAL_OUTPUT:
case QSPI_IFR_WIDTH_QUAD_OUTPUT:
num >>= 3;
break;
case QSPI_IFR_WIDTH_DUAL_IO:
case QSPI_IFR_WIDTH_DUAL_CMD:
num >>= 2;
break;
case QSPI_IFR_WIDTH_QUAD_IO:
case QSPI_IFR_WIDTH_QUAD_CMD:
num >>= 1;
break;
default:
return;
}
for (i = 0; i < num; ++i)
cmd_buf[len++] = 0;
}
print_hex_dump(KERN_DEBUG, "qspi cmd: ", DUMP_PREFIX_NONE,
32, 1, cmd_buf, len, false);
#ifdef VERBOSE_DEBUG
if (cmd->enable.bits.data && cmd->tx_buf)
print_hex_dump(KERN_DEBUG, "qspi tx : ", DUMP_PREFIX_NONE,
32, 1, cmd->tx_buf, cmd->buf_len, false);
#endif
}
static int atmel_qspi_run_command(struct atmel_qspi *aq,
const struct atmel_qspi_command *cmd,
u32 ifr_tfrtyp, u32 ifr_width)
{
u32 iar, icr, ifr, sr;
int err = 0;
iar = 0;
icr = 0;
ifr = ifr_tfrtyp | ifr_width;
if (cmd->enable.bits.instruction) {
icr |= QSPI_ICR_INST(cmd->instruction);
ifr |= QSPI_IFR_INSTEN;
}
switch (cmd->enable.bits.address) {
case 4:
ifr |= QSPI_IFR_ADDRL;
case 3:
iar = (cmd->enable.bits.data) ? 0 : cmd->address;
ifr |= QSPI_IFR_ADDREN;
break;
case 0:
break;
default:
return -EINVAL;
}
if (cmd->enable.bits.mode && cmd->num_mode_cycles) {
u32 mode_cycle_bits, mode_bits;
icr |= QSPI_ICR_OPT(cmd->mode);
ifr |= QSPI_IFR_OPTEN;
switch (ifr & QSPI_IFR_WIDTH_MASK) {
case QSPI_IFR_WIDTH_SINGLE_BIT_SPI:
case QSPI_IFR_WIDTH_DUAL_OUTPUT:
case QSPI_IFR_WIDTH_QUAD_OUTPUT:
mode_cycle_bits = 1;
break;
case QSPI_IFR_WIDTH_DUAL_IO:
case QSPI_IFR_WIDTH_DUAL_CMD:
mode_cycle_bits = 2;
break;
case QSPI_IFR_WIDTH_QUAD_IO:
case QSPI_IFR_WIDTH_QUAD_CMD:
mode_cycle_bits = 4;
break;
default:
return -EINVAL;
}
mode_bits = cmd->num_mode_cycles * mode_cycle_bits;
switch (mode_bits) {
case 1:
ifr |= QSPI_IFR_OPTL_1BIT;
break;
case 2:
ifr |= QSPI_IFR_OPTL_2BIT;
break;
case 4:
ifr |= QSPI_IFR_OPTL_4BIT;
break;
case 8:
ifr |= QSPI_IFR_OPTL_8BIT;
break;
default:
return -EINVAL;
}
}
if (cmd->enable.bits.dummy)
ifr |= QSPI_IFR_NBDUM(cmd->num_dummy_cycles);
if (cmd->enable.bits.data) {
ifr |= QSPI_IFR_DATAEN;
if (!cmd->tx_buf && !cmd->rx_buf)
ifr |= QSPI_IFR_CRM;
}
(void)qspi_readl(aq, QSPI_SR);
atmel_qspi_debug_command(aq, cmd, ifr);
qspi_writel(aq, QSPI_IAR, iar);
qspi_writel(aq, QSPI_ICR, icr);
qspi_writel(aq, QSPI_IFR, ifr);
if (!cmd->enable.bits.data)
goto no_data;
(void)qspi_readl(aq, QSPI_IFR);
if (!cmd->tx_buf && !cmd->rx_buf)
return 0;
err = atmel_qspi_run_transfer(aq, cmd);
qspi_writel(aq, QSPI_CR, QSPI_CR_LASTXFER);
if (err)
return err;
#if defined(DEBUG) && defined(VERBOSE_DEBUG)
if (cmd->rx_buf)
print_hex_dump(KERN_DEBUG, "qspi rx : ", DUMP_PREFIX_NONE,
32, 1, cmd->rx_buf, cmd->buf_len, false);
#endif
no_data:
sr = qspi_readl(aq, QSPI_SR);
if ((sr & QSPI_SR_CMD_COMPLETED) == QSPI_SR_CMD_COMPLETED)
return err;
reinit_completion(&aq->cmd_completion);
aq->pending = sr & QSPI_SR_CMD_COMPLETED;
qspi_writel(aq, QSPI_IER, QSPI_SR_CMD_COMPLETED);
if (!wait_for_completion_timeout(&aq->cmd_completion,
msecs_to_jiffies(1000)))
err = -ETIMEDOUT;
qspi_writel(aq, QSPI_IDR, QSPI_SR_CMD_COMPLETED);
return err;
}
static int atmel_qspi_read_reg(struct spi_nor *nor, u8 opcode,
u8 *buf, int len)
{
struct atmel_qspi *aq = nor->priv;
struct atmel_qspi_command cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.enable.bits.instruction = 1;
cmd.enable.bits.data = 1;
cmd.instruction = opcode;
cmd.rx_buf = buf;
cmd.buf_len = len;
return atmel_qspi_run_command(aq, &cmd, QSPI_IFR_TFRTYP_TRSFR_READ,
QSPI_IFR_WIDTH_SINGLE_BIT_SPI);
}
static int atmel_qspi_write_reg(struct spi_nor *nor, u8 opcode,
u8 *buf, int len)
{
struct atmel_qspi *aq = nor->priv;
struct atmel_qspi_command cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.enable.bits.instruction = 1;
cmd.enable.bits.data = (buf != NULL && len > 0);
cmd.instruction = opcode;
cmd.tx_buf = buf;
cmd.buf_len = len;
return atmel_qspi_run_command(aq, &cmd, QSPI_IFR_TFRTYP_TRSFR_WRITE,
QSPI_IFR_WIDTH_SINGLE_BIT_SPI);
}
static ssize_t atmel_qspi_write(struct spi_nor *nor, loff_t to, size_t len,
const u_char *write_buf)
{
struct atmel_qspi *aq = nor->priv;
struct atmel_qspi_command cmd;
ssize_t ret;
memset(&cmd, 0, sizeof(cmd));
cmd.enable.bits.instruction = 1;
cmd.enable.bits.address = nor->addr_width;
cmd.enable.bits.data = 1;
cmd.instruction = nor->program_opcode;
cmd.address = (u32)to;
cmd.tx_buf = write_buf;
cmd.buf_len = len;
ret = atmel_qspi_run_command(aq, &cmd, QSPI_IFR_TFRTYP_TRSFR_WRITE_MEM,
QSPI_IFR_WIDTH_SINGLE_BIT_SPI);
return (ret < 0) ? ret : len;
}
static int atmel_qspi_erase(struct spi_nor *nor, loff_t offs)
{
struct atmel_qspi *aq = nor->priv;
struct atmel_qspi_command cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.enable.bits.instruction = 1;
cmd.enable.bits.address = nor->addr_width;
cmd.instruction = nor->erase_opcode;
cmd.address = (u32)offs;
return atmel_qspi_run_command(aq, &cmd, QSPI_IFR_TFRTYP_TRSFR_WRITE,
QSPI_IFR_WIDTH_SINGLE_BIT_SPI);
}
static ssize_t atmel_qspi_read(struct spi_nor *nor, loff_t from, size_t len,
u_char *read_buf)
{
struct atmel_qspi *aq = nor->priv;
struct atmel_qspi_command cmd;
u8 num_mode_cycles, num_dummy_cycles;
u32 ifr_width;
ssize_t ret;
switch (nor->flash_read) {
case SPI_NOR_NORMAL:
case SPI_NOR_FAST:
ifr_width = QSPI_IFR_WIDTH_SINGLE_BIT_SPI;
break;
case SPI_NOR_DUAL:
ifr_width = QSPI_IFR_WIDTH_DUAL_OUTPUT;
break;
case SPI_NOR_QUAD:
ifr_width = QSPI_IFR_WIDTH_QUAD_OUTPUT;
break;
default:
return -EINVAL;
}
if (nor->read_dummy >= 2) {
num_mode_cycles = 2;
num_dummy_cycles = nor->read_dummy - 2;
} else {
num_mode_cycles = nor->read_dummy;
num_dummy_cycles = 0;
}
memset(&cmd, 0, sizeof(cmd));
cmd.enable.bits.instruction = 1;
cmd.enable.bits.address = nor->addr_width;
cmd.enable.bits.mode = (num_mode_cycles > 0);
cmd.enable.bits.dummy = (num_dummy_cycles > 0);
cmd.enable.bits.data = 1;
cmd.instruction = nor->read_opcode;
cmd.address = (u32)from;
cmd.mode = 0xff;
cmd.num_mode_cycles = num_mode_cycles;
cmd.num_dummy_cycles = num_dummy_cycles;
cmd.rx_buf = read_buf;
cmd.buf_len = len;
ret = atmel_qspi_run_command(aq, &cmd, QSPI_IFR_TFRTYP_TRSFR_READ_MEM,
ifr_width);
return (ret < 0) ? ret : len;
}
static int atmel_qspi_init(struct atmel_qspi *aq)
{
unsigned long src_rate;
u32 mr, scr, scbr;
qspi_writel(aq, QSPI_CR, QSPI_CR_SWRST);
mr = QSPI_MR_NBBITS(8) | QSPI_MR_SSM;
qspi_writel(aq, QSPI_MR, mr);
src_rate = clk_get_rate(aq->clk);
if (!src_rate)
return -EINVAL;
scbr = DIV_ROUND_UP(src_rate, aq->clk_rate);
if (scbr > 0)
scbr--;
scr = QSPI_SCR_SCBR(scbr);
qspi_writel(aq, QSPI_SCR, scr);
qspi_writel(aq, QSPI_CR, QSPI_CR_QSPIEN);
return 0;
}
static irqreturn_t atmel_qspi_interrupt(int irq, void *dev_id)
{
struct atmel_qspi *aq = (struct atmel_qspi *)dev_id;
u32 status, mask, pending;
status = qspi_readl(aq, QSPI_SR);
mask = qspi_readl(aq, QSPI_IMR);
pending = status & mask;
if (!pending)
return IRQ_NONE;
aq->pending |= pending;
if ((aq->pending & QSPI_SR_CMD_COMPLETED) == QSPI_SR_CMD_COMPLETED)
complete(&aq->cmd_completion);
return IRQ_HANDLED;
}
static int atmel_qspi_probe(struct platform_device *pdev)
{
struct device_node *child, *np = pdev->dev.of_node;
struct atmel_qspi *aq;
struct resource *res;
struct spi_nor *nor;
struct mtd_info *mtd;
int irq, err = 0;
if (of_get_child_count(np) != 1)
return -ENODEV;
child = of_get_next_child(np, NULL);
aq = devm_kzalloc(&pdev->dev, sizeof(*aq), GFP_KERNEL);
if (!aq) {
err = -ENOMEM;
goto exit;
}
platform_set_drvdata(pdev, aq);
init_completion(&aq->cmd_completion);
aq->pdev = pdev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "qspi_base");
aq->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(aq->regs)) {
dev_err(&pdev->dev, "missing registers\n");
err = PTR_ERR(aq->regs);
goto exit;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "qspi_mmap");
aq->mem = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(aq->mem)) {
dev_err(&pdev->dev, "missing AHB memory\n");
err = PTR_ERR(aq->mem);
goto exit;
}
aq->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(aq->clk)) {
dev_err(&pdev->dev, "missing peripheral clock\n");
err = PTR_ERR(aq->clk);
goto exit;
}
err = clk_prepare_enable(aq->clk);
if (err) {
dev_err(&pdev->dev, "failed to enable the peripheral clock\n");
goto exit;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "missing IRQ\n");
err = irq;
goto disable_clk;
}
err = devm_request_irq(&pdev->dev, irq, atmel_qspi_interrupt,
0, dev_name(&pdev->dev), aq);
if (err)
goto disable_clk;
nor = &aq->nor;
mtd = &nor->mtd;
nor->dev = &pdev->dev;
spi_nor_set_flash_node(nor, child);
nor->priv = aq;
mtd->priv = nor;
nor->read_reg = atmel_qspi_read_reg;
nor->write_reg = atmel_qspi_write_reg;
nor->read = atmel_qspi_read;
nor->write = atmel_qspi_write;
nor->erase = atmel_qspi_erase;
err = of_property_read_u32(child, "spi-max-frequency", &aq->clk_rate);
if (err < 0)
goto disable_clk;
err = atmel_qspi_init(aq);
if (err)
goto disable_clk;
err = spi_nor_scan(nor, NULL, SPI_NOR_QUAD);
if (err)
goto disable_clk;
err = mtd_device_register(mtd, NULL, 0);
if (err)
goto disable_clk;
of_node_put(child);
return 0;
disable_clk:
clk_disable_unprepare(aq->clk);
exit:
of_node_put(child);
return err;
}
static int atmel_qspi_remove(struct platform_device *pdev)
{
struct atmel_qspi *aq = platform_get_drvdata(pdev);
mtd_device_unregister(&aq->nor.mtd);
qspi_writel(aq, QSPI_CR, QSPI_CR_QSPIDIS);
clk_disable_unprepare(aq->clk);
return 0;
}
