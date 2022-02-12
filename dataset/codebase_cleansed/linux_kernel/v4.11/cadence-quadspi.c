static int cqspi_wait_for_bit(void __iomem *reg, const u32 mask, bool clear)
{
unsigned long end = jiffies + msecs_to_jiffies(CQSPI_TIMEOUT_MS);
u32 val;
while (1) {
val = readl(reg);
if (clear)
val = ~val;
val &= mask;
if (val == mask)
return 0;
if (time_after(jiffies, end))
return -ETIMEDOUT;
}
}
static bool cqspi_is_idle(struct cqspi_st *cqspi)
{
u32 reg = readl(cqspi->iobase + CQSPI_REG_CONFIG);
return reg & (1 << CQSPI_REG_CONFIG_IDLE_LSB);
}
static u32 cqspi_get_rd_sram_level(struct cqspi_st *cqspi)
{
u32 reg = readl(cqspi->iobase + CQSPI_REG_SDRAMLEVEL);
reg >>= CQSPI_REG_SDRAMLEVEL_RD_LSB;
return reg & CQSPI_REG_SDRAMLEVEL_RD_MASK;
}
static irqreturn_t cqspi_irq_handler(int this_irq, void *dev)
{
struct cqspi_st *cqspi = dev;
unsigned int irq_status;
irq_status = readl(cqspi->iobase + CQSPI_REG_IRQSTATUS);
writel(irq_status, cqspi->iobase + CQSPI_REG_IRQSTATUS);
irq_status &= CQSPI_IRQ_MASK_RD | CQSPI_IRQ_MASK_WR;
if (irq_status)
complete(&cqspi->transfer_complete);
return IRQ_HANDLED;
}
static unsigned int cqspi_calc_rdreg(struct spi_nor *nor, const u8 opcode)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
u32 rdreg = 0;
rdreg |= f_pdata->inst_width << CQSPI_REG_RD_INSTR_TYPE_INSTR_LSB;
rdreg |= f_pdata->addr_width << CQSPI_REG_RD_INSTR_TYPE_ADDR_LSB;
rdreg |= f_pdata->data_width << CQSPI_REG_RD_INSTR_TYPE_DATA_LSB;
return rdreg;
}
static int cqspi_wait_idle(struct cqspi_st *cqspi)
{
const unsigned int poll_idle_retry = 3;
unsigned int count = 0;
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(CQSPI_TIMEOUT_MS);
while (1) {
if (cqspi_is_idle(cqspi))
count++;
else
count = 0;
if (count >= poll_idle_retry)
return 0;
if (time_after(jiffies, timeout)) {
dev_err(&cqspi->pdev->dev,
"QSPI is still busy after %dms timeout.\n",
CQSPI_TIMEOUT_MS);
return -ETIMEDOUT;
}
cpu_relax();
}
}
static int cqspi_exec_flash_cmd(struct cqspi_st *cqspi, unsigned int reg)
{
void __iomem *reg_base = cqspi->iobase;
int ret;
writel(reg, reg_base + CQSPI_REG_CMDCTRL);
reg |= CQSPI_REG_CMDCTRL_EXECUTE_MASK;
writel(reg, reg_base + CQSPI_REG_CMDCTRL);
ret = cqspi_wait_for_bit(reg_base + CQSPI_REG_CMDCTRL,
CQSPI_REG_CMDCTRL_INPROGRESS_MASK, 1);
if (ret) {
dev_err(&cqspi->pdev->dev,
"Flash command execution timed out.\n");
return ret;
}
return cqspi_wait_idle(cqspi);
}
static int cqspi_command_read(struct spi_nor *nor,
const u8 *txbuf, const unsigned n_tx,
u8 *rxbuf, const unsigned n_rx)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
void __iomem *reg_base = cqspi->iobase;
unsigned int rdreg;
unsigned int reg;
unsigned int read_len;
int status;
if (!n_rx || n_rx > CQSPI_STIG_DATA_LEN_MAX || !rxbuf) {
dev_err(nor->dev, "Invalid input argument, len %d rxbuf 0x%p\n",
n_rx, rxbuf);
return -EINVAL;
}
reg = txbuf[0] << CQSPI_REG_CMDCTRL_OPCODE_LSB;
rdreg = cqspi_calc_rdreg(nor, txbuf[0]);
writel(rdreg, reg_base + CQSPI_REG_RD_INSTR);
reg |= (0x1 << CQSPI_REG_CMDCTRL_RD_EN_LSB);
reg |= (((n_rx - 1) & CQSPI_REG_CMDCTRL_RD_BYTES_MASK)
<< CQSPI_REG_CMDCTRL_RD_BYTES_LSB);
status = cqspi_exec_flash_cmd(cqspi, reg);
if (status)
return status;
reg = readl(reg_base + CQSPI_REG_CMDREADDATALOWER);
read_len = (n_rx > 4) ? 4 : n_rx;
memcpy(rxbuf, &reg, read_len);
rxbuf += read_len;
if (n_rx > 4) {
reg = readl(reg_base + CQSPI_REG_CMDREADDATAUPPER);
read_len = n_rx - read_len;
memcpy(rxbuf, &reg, read_len);
}
return 0;
}
static int cqspi_command_write(struct spi_nor *nor, const u8 opcode,
const u8 *txbuf, const unsigned n_tx)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
void __iomem *reg_base = cqspi->iobase;
unsigned int reg;
unsigned int data;
int ret;
if (n_tx > 4 || (n_tx && !txbuf)) {
dev_err(nor->dev,
"Invalid input argument, cmdlen %d txbuf 0x%p\n",
n_tx, txbuf);
return -EINVAL;
}
reg = opcode << CQSPI_REG_CMDCTRL_OPCODE_LSB;
if (n_tx) {
reg |= (0x1 << CQSPI_REG_CMDCTRL_WR_EN_LSB);
reg |= ((n_tx - 1) & CQSPI_REG_CMDCTRL_WR_BYTES_MASK)
<< CQSPI_REG_CMDCTRL_WR_BYTES_LSB;
data = 0;
memcpy(&data, txbuf, n_tx);
writel(data, reg_base + CQSPI_REG_CMDWRITEDATALOWER);
}
ret = cqspi_exec_flash_cmd(cqspi, reg);
return ret;
}
static int cqspi_command_write_addr(struct spi_nor *nor,
const u8 opcode, const unsigned int addr)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
void __iomem *reg_base = cqspi->iobase;
unsigned int reg;
reg = opcode << CQSPI_REG_CMDCTRL_OPCODE_LSB;
reg |= (0x1 << CQSPI_REG_CMDCTRL_ADDR_EN_LSB);
reg |= ((nor->addr_width - 1) & CQSPI_REG_CMDCTRL_ADD_BYTES_MASK)
<< CQSPI_REG_CMDCTRL_ADD_BYTES_LSB;
writel(addr, reg_base + CQSPI_REG_CMDADDRESS);
return cqspi_exec_flash_cmd(cqspi, reg);
}
static int cqspi_indirect_read_setup(struct spi_nor *nor,
const unsigned int from_addr)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
void __iomem *reg_base = cqspi->iobase;
unsigned int dummy_clk = 0;
unsigned int reg;
writel(from_addr, reg_base + CQSPI_REG_INDIRECTRDSTARTADDR);
reg = nor->read_opcode << CQSPI_REG_RD_INSTR_OPCODE_LSB;
reg |= cqspi_calc_rdreg(nor, nor->read_opcode);
dummy_clk = nor->read_dummy;
if (dummy_clk > CQSPI_DUMMY_CLKS_MAX)
dummy_clk = CQSPI_DUMMY_CLKS_MAX;
if (dummy_clk / 8) {
reg |= (1 << CQSPI_REG_RD_INSTR_MODE_EN_LSB);
writel(0xFF, reg_base + CQSPI_REG_MODE_BIT);
if (f_pdata->inst_width != CQSPI_INST_TYPE_QUAD)
dummy_clk -= 8;
if (dummy_clk)
reg |= (dummy_clk & CQSPI_REG_RD_INSTR_DUMMY_MASK)
<< CQSPI_REG_RD_INSTR_DUMMY_LSB;
}
writel(reg, reg_base + CQSPI_REG_RD_INSTR);
reg = readl(reg_base + CQSPI_REG_SIZE);
reg &= ~CQSPI_REG_SIZE_ADDRESS_MASK;
reg |= (nor->addr_width - 1);
writel(reg, reg_base + CQSPI_REG_SIZE);
return 0;
}
static int cqspi_indirect_read_execute(struct spi_nor *nor,
u8 *rxbuf, const unsigned n_rx)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
void __iomem *reg_base = cqspi->iobase;
void __iomem *ahb_base = cqspi->ahb_base;
unsigned int remaining = n_rx;
unsigned int bytes_to_read = 0;
int ret = 0;
writel(remaining, reg_base + CQSPI_REG_INDIRECTRDBYTES);
writel(CQSPI_IRQ_STATUS_MASK, reg_base + CQSPI_REG_IRQSTATUS);
writel(CQSPI_IRQ_MASK_RD, reg_base + CQSPI_REG_IRQMASK);
reinit_completion(&cqspi->transfer_complete);
writel(CQSPI_REG_INDIRECTRD_START_MASK,
reg_base + CQSPI_REG_INDIRECTRD);
while (remaining > 0) {
ret = wait_for_completion_timeout(&cqspi->transfer_complete,
msecs_to_jiffies
(CQSPI_READ_TIMEOUT_MS));
bytes_to_read = cqspi_get_rd_sram_level(cqspi);
if (!ret && bytes_to_read == 0) {
dev_err(nor->dev, "Indirect read timeout, no bytes\n");
ret = -ETIMEDOUT;
goto failrd;
}
while (bytes_to_read != 0) {
bytes_to_read *= cqspi->fifo_width;
bytes_to_read = bytes_to_read > remaining ?
remaining : bytes_to_read;
ioread32_rep(ahb_base, rxbuf,
DIV_ROUND_UP(bytes_to_read, 4));
rxbuf += bytes_to_read;
remaining -= bytes_to_read;
bytes_to_read = cqspi_get_rd_sram_level(cqspi);
}
if (remaining > 0)
reinit_completion(&cqspi->transfer_complete);
}
ret = cqspi_wait_for_bit(reg_base + CQSPI_REG_INDIRECTRD,
CQSPI_REG_INDIRECTRD_DONE_MASK, 0);
if (ret) {
dev_err(nor->dev,
"Indirect read completion error (%i)\n", ret);
goto failrd;
}
writel(0, reg_base + CQSPI_REG_IRQMASK);
writel(CQSPI_REG_INDIRECTRD_DONE_MASK, reg_base + CQSPI_REG_INDIRECTRD);
return 0;
failrd:
writel(0, reg_base + CQSPI_REG_IRQMASK);
writel(CQSPI_REG_INDIRECTWR_CANCEL_MASK,
reg_base + CQSPI_REG_INDIRECTRD);
return ret;
}
static int cqspi_indirect_write_setup(struct spi_nor *nor,
const unsigned int to_addr)
{
unsigned int reg;
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
void __iomem *reg_base = cqspi->iobase;
reg = nor->program_opcode << CQSPI_REG_WR_INSTR_OPCODE_LSB;
writel(reg, reg_base + CQSPI_REG_WR_INSTR);
reg = cqspi_calc_rdreg(nor, nor->program_opcode);
writel(reg, reg_base + CQSPI_REG_RD_INSTR);
writel(to_addr, reg_base + CQSPI_REG_INDIRECTWRSTARTADDR);
reg = readl(reg_base + CQSPI_REG_SIZE);
reg &= ~CQSPI_REG_SIZE_ADDRESS_MASK;
reg |= (nor->addr_width - 1);
writel(reg, reg_base + CQSPI_REG_SIZE);
return 0;
}
static int cqspi_indirect_write_execute(struct spi_nor *nor,
const u8 *txbuf, const unsigned n_tx)
{
const unsigned int page_size = nor->page_size;
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
void __iomem *reg_base = cqspi->iobase;
unsigned int remaining = n_tx;
unsigned int write_bytes;
int ret;
writel(remaining, reg_base + CQSPI_REG_INDIRECTWRBYTES);
writel(CQSPI_IRQ_STATUS_MASK, reg_base + CQSPI_REG_IRQSTATUS);
writel(CQSPI_IRQ_MASK_WR, reg_base + CQSPI_REG_IRQMASK);
reinit_completion(&cqspi->transfer_complete);
writel(CQSPI_REG_INDIRECTWR_START_MASK,
reg_base + CQSPI_REG_INDIRECTWR);
while (remaining > 0) {
write_bytes = remaining > page_size ? page_size : remaining;
iowrite32_rep(cqspi->ahb_base, txbuf,
DIV_ROUND_UP(write_bytes, 4));
ret = wait_for_completion_timeout(&cqspi->transfer_complete,
msecs_to_jiffies
(CQSPI_TIMEOUT_MS));
if (!ret) {
dev_err(nor->dev, "Indirect write timeout\n");
ret = -ETIMEDOUT;
goto failwr;
}
txbuf += write_bytes;
remaining -= write_bytes;
if (remaining > 0)
reinit_completion(&cqspi->transfer_complete);
}
ret = cqspi_wait_for_bit(reg_base + CQSPI_REG_INDIRECTWR,
CQSPI_REG_INDIRECTWR_DONE_MASK, 0);
if (ret) {
dev_err(nor->dev,
"Indirect write completion error (%i)\n", ret);
goto failwr;
}
writel(0, reg_base + CQSPI_REG_IRQMASK);
writel(CQSPI_REG_INDIRECTWR_DONE_MASK, reg_base + CQSPI_REG_INDIRECTWR);
cqspi_wait_idle(cqspi);
return 0;
failwr:
writel(0, reg_base + CQSPI_REG_IRQMASK);
writel(CQSPI_REG_INDIRECTWR_CANCEL_MASK,
reg_base + CQSPI_REG_INDIRECTWR);
return ret;
}
static void cqspi_chipselect(struct spi_nor *nor)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
void __iomem *reg_base = cqspi->iobase;
unsigned int chip_select = f_pdata->cs;
unsigned int reg;
reg = readl(reg_base + CQSPI_REG_CONFIG);
if (cqspi->is_decoded_cs) {
reg |= CQSPI_REG_CONFIG_DECODE_MASK;
} else {
reg &= ~CQSPI_REG_CONFIG_DECODE_MASK;
chip_select = 0xF & ~(1 << chip_select);
}
reg &= ~(CQSPI_REG_CONFIG_CHIPSELECT_MASK
<< CQSPI_REG_CONFIG_CHIPSELECT_LSB);
reg |= (chip_select & CQSPI_REG_CONFIG_CHIPSELECT_MASK)
<< CQSPI_REG_CONFIG_CHIPSELECT_LSB;
writel(reg, reg_base + CQSPI_REG_CONFIG);
}
static void cqspi_configure_cs_and_sizes(struct spi_nor *nor)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
void __iomem *iobase = cqspi->iobase;
unsigned int reg;
reg = readl(iobase + CQSPI_REG_SIZE);
reg &= ~(CQSPI_REG_SIZE_PAGE_MASK << CQSPI_REG_SIZE_PAGE_LSB);
reg &= ~(CQSPI_REG_SIZE_BLOCK_MASK << CQSPI_REG_SIZE_BLOCK_LSB);
reg &= ~CQSPI_REG_SIZE_ADDRESS_MASK;
reg |= (nor->page_size << CQSPI_REG_SIZE_PAGE_LSB);
reg |= (ilog2(nor->mtd.erasesize) << CQSPI_REG_SIZE_BLOCK_LSB);
reg |= (nor->addr_width - 1);
writel(reg, iobase + CQSPI_REG_SIZE);
cqspi_chipselect(nor);
cqspi->current_page_size = nor->page_size;
cqspi->current_erase_size = nor->mtd.erasesize;
cqspi->current_addr_width = nor->addr_width;
}
static unsigned int calculate_ticks_for_ns(const unsigned int ref_clk_hz,
const unsigned int ns_val)
{
unsigned int ticks;
ticks = ref_clk_hz / 1000;
ticks = DIV_ROUND_UP(ticks * ns_val, 1000000);
return ticks;
}
static void cqspi_delay(struct spi_nor *nor)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
void __iomem *iobase = cqspi->iobase;
const unsigned int ref_clk_hz = cqspi->master_ref_clk_hz;
unsigned int tshsl, tchsh, tslch, tsd2d;
unsigned int reg;
unsigned int tsclk;
tsclk = DIV_ROUND_UP(ref_clk_hz, cqspi->sclk);
tshsl = calculate_ticks_for_ns(ref_clk_hz, f_pdata->tshsl_ns);
if (tshsl < tsclk)
tshsl = tsclk;
tchsh = calculate_ticks_for_ns(ref_clk_hz, f_pdata->tchsh_ns);
tslch = calculate_ticks_for_ns(ref_clk_hz, f_pdata->tslch_ns);
tsd2d = calculate_ticks_for_ns(ref_clk_hz, f_pdata->tsd2d_ns);
reg = (tshsl & CQSPI_REG_DELAY_TSHSL_MASK)
<< CQSPI_REG_DELAY_TSHSL_LSB;
reg |= (tchsh & CQSPI_REG_DELAY_TCHSH_MASK)
<< CQSPI_REG_DELAY_TCHSH_LSB;
reg |= (tslch & CQSPI_REG_DELAY_TSLCH_MASK)
<< CQSPI_REG_DELAY_TSLCH_LSB;
reg |= (tsd2d & CQSPI_REG_DELAY_TSD2D_MASK)
<< CQSPI_REG_DELAY_TSD2D_LSB;
writel(reg, iobase + CQSPI_REG_DELAY);
}
static void cqspi_config_baudrate_div(struct cqspi_st *cqspi)
{
const unsigned int ref_clk_hz = cqspi->master_ref_clk_hz;
void __iomem *reg_base = cqspi->iobase;
u32 reg, div;
div = DIV_ROUND_UP(ref_clk_hz, 2 * cqspi->sclk) - 1;
reg = readl(reg_base + CQSPI_REG_CONFIG);
reg &= ~(CQSPI_REG_CONFIG_BAUD_MASK << CQSPI_REG_CONFIG_BAUD_LSB);
reg |= (div & CQSPI_REG_CONFIG_BAUD_MASK) << CQSPI_REG_CONFIG_BAUD_LSB;
writel(reg, reg_base + CQSPI_REG_CONFIG);
}
static void cqspi_readdata_capture(struct cqspi_st *cqspi,
const unsigned int bypass,
const unsigned int delay)
{
void __iomem *reg_base = cqspi->iobase;
unsigned int reg;
reg = readl(reg_base + CQSPI_REG_READCAPTURE);
if (bypass)
reg |= (1 << CQSPI_REG_READCAPTURE_BYPASS_LSB);
else
reg &= ~(1 << CQSPI_REG_READCAPTURE_BYPASS_LSB);
reg &= ~(CQSPI_REG_READCAPTURE_DELAY_MASK
<< CQSPI_REG_READCAPTURE_DELAY_LSB);
reg |= (delay & CQSPI_REG_READCAPTURE_DELAY_MASK)
<< CQSPI_REG_READCAPTURE_DELAY_LSB;
writel(reg, reg_base + CQSPI_REG_READCAPTURE);
}
static void cqspi_controller_enable(struct cqspi_st *cqspi, bool enable)
{
void __iomem *reg_base = cqspi->iobase;
unsigned int reg;
reg = readl(reg_base + CQSPI_REG_CONFIG);
if (enable)
reg |= CQSPI_REG_CONFIG_ENABLE_MASK;
else
reg &= ~CQSPI_REG_CONFIG_ENABLE_MASK;
writel(reg, reg_base + CQSPI_REG_CONFIG);
}
static void cqspi_configure(struct spi_nor *nor)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
const unsigned int sclk = f_pdata->clk_rate;
int switch_cs = (cqspi->current_cs != f_pdata->cs);
int switch_ck = (cqspi->sclk != sclk);
if ((cqspi->current_page_size != nor->page_size) ||
(cqspi->current_erase_size != nor->mtd.erasesize) ||
(cqspi->current_addr_width != nor->addr_width))
switch_cs = 1;
if (switch_cs || switch_ck)
cqspi_controller_enable(cqspi, 0);
if (switch_cs) {
cqspi->current_cs = f_pdata->cs;
cqspi_configure_cs_and_sizes(nor);
}
if (switch_ck) {
cqspi->sclk = sclk;
cqspi_config_baudrate_div(cqspi);
cqspi_delay(nor);
cqspi_readdata_capture(cqspi, 1, f_pdata->read_delay);
}
if (switch_cs || switch_ck)
cqspi_controller_enable(cqspi, 1);
}
static int cqspi_set_protocol(struct spi_nor *nor, const int read)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
f_pdata->inst_width = CQSPI_INST_TYPE_SINGLE;
f_pdata->addr_width = CQSPI_INST_TYPE_SINGLE;
f_pdata->data_width = CQSPI_INST_TYPE_SINGLE;
if (read) {
switch (nor->flash_read) {
case SPI_NOR_NORMAL:
case SPI_NOR_FAST:
f_pdata->data_width = CQSPI_INST_TYPE_SINGLE;
break;
case SPI_NOR_DUAL:
f_pdata->data_width = CQSPI_INST_TYPE_DUAL;
break;
case SPI_NOR_QUAD:
f_pdata->data_width = CQSPI_INST_TYPE_QUAD;
break;
default:
return -EINVAL;
}
}
cqspi_configure(nor);
return 0;
}
static ssize_t cqspi_write(struct spi_nor *nor, loff_t to,
size_t len, const u_char *buf)
{
int ret;
ret = cqspi_set_protocol(nor, 0);
if (ret)
return ret;
ret = cqspi_indirect_write_setup(nor, to);
if (ret)
return ret;
ret = cqspi_indirect_write_execute(nor, buf, len);
if (ret)
return ret;
return len;
}
static ssize_t cqspi_read(struct spi_nor *nor, loff_t from,
size_t len, u_char *buf)
{
int ret;
ret = cqspi_set_protocol(nor, 1);
if (ret)
return ret;
ret = cqspi_indirect_read_setup(nor, from);
if (ret)
return ret;
ret = cqspi_indirect_read_execute(nor, buf, len);
if (ret)
return ret;
return len;
}
static int cqspi_erase(struct spi_nor *nor, loff_t offs)
{
int ret;
ret = cqspi_set_protocol(nor, 0);
if (ret)
return ret;
ret = nor->write_reg(nor, SPINOR_OP_WREN, NULL, 0);
if (ret)
return ret;
ret = cqspi_command_write_addr(nor, nor->erase_opcode, offs);
if (ret)
return ret;
return 0;
}
static int cqspi_prep(struct spi_nor *nor, enum spi_nor_ops ops)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
mutex_lock(&cqspi->bus_mutex);
return 0;
}
static void cqspi_unprep(struct spi_nor *nor, enum spi_nor_ops ops)
{
struct cqspi_flash_pdata *f_pdata = nor->priv;
struct cqspi_st *cqspi = f_pdata->cqspi;
mutex_unlock(&cqspi->bus_mutex);
}
static int cqspi_read_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
int ret;
ret = cqspi_set_protocol(nor, 0);
if (!ret)
ret = cqspi_command_read(nor, &opcode, 1, buf, len);
return ret;
}
static int cqspi_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
int ret;
ret = cqspi_set_protocol(nor, 0);
if (!ret)
ret = cqspi_command_write(nor, opcode, buf, len);
return ret;
}
static int cqspi_of_get_flash_pdata(struct platform_device *pdev,
struct cqspi_flash_pdata *f_pdata,
struct device_node *np)
{
if (of_property_read_u32(np, "cdns,read-delay", &f_pdata->read_delay)) {
dev_err(&pdev->dev, "couldn't determine read-delay\n");
return -ENXIO;
}
if (of_property_read_u32(np, "cdns,tshsl-ns", &f_pdata->tshsl_ns)) {
dev_err(&pdev->dev, "couldn't determine tshsl-ns\n");
return -ENXIO;
}
if (of_property_read_u32(np, "cdns,tsd2d-ns", &f_pdata->tsd2d_ns)) {
dev_err(&pdev->dev, "couldn't determine tsd2d-ns\n");
return -ENXIO;
}
if (of_property_read_u32(np, "cdns,tchsh-ns", &f_pdata->tchsh_ns)) {
dev_err(&pdev->dev, "couldn't determine tchsh-ns\n");
return -ENXIO;
}
if (of_property_read_u32(np, "cdns,tslch-ns", &f_pdata->tslch_ns)) {
dev_err(&pdev->dev, "couldn't determine tslch-ns\n");
return -ENXIO;
}
if (of_property_read_u32(np, "spi-max-frequency", &f_pdata->clk_rate)) {
dev_err(&pdev->dev, "couldn't determine spi-max-frequency\n");
return -ENXIO;
}
return 0;
}
static int cqspi_of_get_pdata(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct cqspi_st *cqspi = platform_get_drvdata(pdev);
cqspi->is_decoded_cs = of_property_read_bool(np, "cdns,is-decoded-cs");
if (of_property_read_u32(np, "cdns,fifo-depth", &cqspi->fifo_depth)) {
dev_err(&pdev->dev, "couldn't determine fifo-depth\n");
return -ENXIO;
}
if (of_property_read_u32(np, "cdns,fifo-width", &cqspi->fifo_width)) {
dev_err(&pdev->dev, "couldn't determine fifo-width\n");
return -ENXIO;
}
if (of_property_read_u32(np, "cdns,trigger-address",
&cqspi->trigger_address)) {
dev_err(&pdev->dev, "couldn't determine trigger-address\n");
return -ENXIO;
}
return 0;
}
static void cqspi_controller_init(struct cqspi_st *cqspi)
{
cqspi_controller_enable(cqspi, 0);
writel(0, cqspi->iobase + CQSPI_REG_REMAP);
writel(0, cqspi->iobase + CQSPI_REG_IRQMASK);
writel(cqspi->fifo_depth / 2, cqspi->iobase + CQSPI_REG_SRAMPARTITION);
writel(cqspi->trigger_address,
cqspi->iobase + CQSPI_REG_INDIRECTTRIGGER);
writel(cqspi->fifo_depth * cqspi->fifo_width / 2,
cqspi->iobase + CQSPI_REG_INDIRECTRDWATERMARK);
writel(cqspi->fifo_depth * cqspi->fifo_width / 8,
cqspi->iobase + CQSPI_REG_INDIRECTWRWATERMARK);
cqspi_controller_enable(cqspi, 1);
}
static int cqspi_setup_flash(struct cqspi_st *cqspi, struct device_node *np)
{
struct platform_device *pdev = cqspi->pdev;
struct device *dev = &pdev->dev;
struct cqspi_flash_pdata *f_pdata;
struct spi_nor *nor;
struct mtd_info *mtd;
unsigned int cs;
int i, ret;
for_each_available_child_of_node(dev->of_node, np) {
ret = of_property_read_u32(np, "reg", &cs);
if (ret) {
dev_err(dev, "Couldn't determine chip select.\n");
goto err;
}
if (cs >= CQSPI_MAX_CHIPSELECT) {
ret = -EINVAL;
dev_err(dev, "Chip select %d out of range.\n", cs);
goto err;
}
f_pdata = &cqspi->f_pdata[cs];
f_pdata->cqspi = cqspi;
f_pdata->cs = cs;
ret = cqspi_of_get_flash_pdata(pdev, f_pdata, np);
if (ret)
goto err;
nor = &f_pdata->nor;
mtd = &nor->mtd;
mtd->priv = nor;
nor->dev = dev;
spi_nor_set_flash_node(nor, np);
nor->priv = f_pdata;
nor->read_reg = cqspi_read_reg;
nor->write_reg = cqspi_write_reg;
nor->read = cqspi_read;
nor->write = cqspi_write;
nor->erase = cqspi_erase;
nor->prepare = cqspi_prep;
nor->unprepare = cqspi_unprep;
mtd->name = devm_kasprintf(dev, GFP_KERNEL, "%s.%d",
dev_name(dev), cs);
if (!mtd->name) {
ret = -ENOMEM;
goto err;
}
ret = spi_nor_scan(nor, NULL, SPI_NOR_QUAD);
if (ret)
goto err;
ret = mtd_device_register(mtd, NULL, 0);
if (ret)
goto err;
f_pdata->registered = true;
}
return 0;
err:
for (i = 0; i < CQSPI_MAX_CHIPSELECT; i++)
if (cqspi->f_pdata[i].registered)
mtd_device_unregister(&cqspi->f_pdata[i].nor.mtd);
return ret;
}
static int cqspi_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct cqspi_st *cqspi;
struct resource *res;
struct resource *res_ahb;
int ret;
int irq;
cqspi = devm_kzalloc(dev, sizeof(*cqspi), GFP_KERNEL);
if (!cqspi)
return -ENOMEM;
mutex_init(&cqspi->bus_mutex);
cqspi->pdev = pdev;
platform_set_drvdata(pdev, cqspi);
ret = cqspi_of_get_pdata(pdev);
if (ret) {
dev_err(dev, "Cannot get mandatory OF data.\n");
return -ENODEV;
}
cqspi->clk = devm_clk_get(dev, NULL);
if (IS_ERR(cqspi->clk)) {
dev_err(dev, "Cannot claim QSPI clock.\n");
return PTR_ERR(cqspi->clk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
cqspi->iobase = devm_ioremap_resource(dev, res);
if (IS_ERR(cqspi->iobase)) {
dev_err(dev, "Cannot remap controller address.\n");
return PTR_ERR(cqspi->iobase);
}
res_ahb = platform_get_resource(pdev, IORESOURCE_MEM, 1);
cqspi->ahb_base = devm_ioremap_resource(dev, res_ahb);
if (IS_ERR(cqspi->ahb_base)) {
dev_err(dev, "Cannot remap AHB address.\n");
return PTR_ERR(cqspi->ahb_base);
}
init_completion(&cqspi->transfer_complete);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "Cannot obtain IRQ.\n");
return -ENXIO;
}
ret = clk_prepare_enable(cqspi->clk);
if (ret) {
dev_err(dev, "Cannot enable QSPI clock.\n");
return ret;
}
cqspi->master_ref_clk_hz = clk_get_rate(cqspi->clk);
ret = devm_request_irq(dev, irq, cqspi_irq_handler, 0,
pdev->name, cqspi);
if (ret) {
dev_err(dev, "Cannot request IRQ.\n");
goto probe_irq_failed;
}
cqspi_wait_idle(cqspi);
cqspi_controller_init(cqspi);
cqspi->current_cs = -1;
cqspi->sclk = 0;
ret = cqspi_setup_flash(cqspi, np);
if (ret) {
dev_err(dev, "Cadence QSPI NOR probe failed %d\n", ret);
goto probe_setup_failed;
}
return ret;
probe_irq_failed:
cqspi_controller_enable(cqspi, 0);
probe_setup_failed:
clk_disable_unprepare(cqspi->clk);
return ret;
}
static int cqspi_remove(struct platform_device *pdev)
{
struct cqspi_st *cqspi = platform_get_drvdata(pdev);
int i;
for (i = 0; i < CQSPI_MAX_CHIPSELECT; i++)
if (cqspi->f_pdata[i].registered)
mtd_device_unregister(&cqspi->f_pdata[i].nor.mtd);
cqspi_controller_enable(cqspi, 0);
clk_disable_unprepare(cqspi->clk);
return 0;
}
static int cqspi_suspend(struct device *dev)
{
struct cqspi_st *cqspi = dev_get_drvdata(dev);
cqspi_controller_enable(cqspi, 0);
return 0;
}
static int cqspi_resume(struct device *dev)
{
struct cqspi_st *cqspi = dev_get_drvdata(dev);
cqspi_controller_enable(cqspi, 1);
return 0;
}
