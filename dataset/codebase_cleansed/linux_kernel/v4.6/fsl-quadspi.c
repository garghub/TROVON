static inline int needs_swap_endian(struct fsl_qspi *q)
{
return q->devtype_data->driver_data & QUADSPI_QUIRK_SWAP_ENDIAN;
}
static inline int needs_4x_clock(struct fsl_qspi *q)
{
return q->devtype_data->driver_data & QUADSPI_QUIRK_4X_INT_CLK;
}
static inline int needs_fill_txfifo(struct fsl_qspi *q)
{
return q->devtype_data->driver_data & QUADSPI_QUIRK_TKT253890;
}
static inline int needs_wakeup_wait_mode(struct fsl_qspi *q)
{
return q->devtype_data->driver_data & QUADSPI_QUIRK_TKT245618;
}
static void qspi_writel(struct fsl_qspi *q, u32 val, void __iomem *addr)
{
if (q->big_endian)
iowrite32be(val, addr);
else
iowrite32(val, addr);
}
static u32 qspi_readl(struct fsl_qspi *q, void __iomem *addr)
{
if (q->big_endian)
return ioread32be(addr);
else
return ioread32(addr);
}
static inline u32 fsl_qspi_endian_xchg(struct fsl_qspi *q, u32 a)
{
return needs_swap_endian(q) ? __swab32(a) : a;
}
static inline void fsl_qspi_unlock_lut(struct fsl_qspi *q)
{
qspi_writel(q, QUADSPI_LUTKEY_VALUE, q->iobase + QUADSPI_LUTKEY);
qspi_writel(q, QUADSPI_LCKER_UNLOCK, q->iobase + QUADSPI_LCKCR);
}
static inline void fsl_qspi_lock_lut(struct fsl_qspi *q)
{
qspi_writel(q, QUADSPI_LUTKEY_VALUE, q->iobase + QUADSPI_LUTKEY);
qspi_writel(q, QUADSPI_LCKER_LOCK, q->iobase + QUADSPI_LCKCR);
}
static irqreturn_t fsl_qspi_irq_handler(int irq, void *dev_id)
{
struct fsl_qspi *q = dev_id;
u32 reg;
reg = qspi_readl(q, q->iobase + QUADSPI_FR);
qspi_writel(q, reg, q->iobase + QUADSPI_FR);
if (reg & QUADSPI_FR_TFF_MASK)
complete(&q->c);
dev_dbg(q->dev, "QUADSPI_FR : 0x%.8x:0x%.8x\n", q->chip_base_addr, reg);
return IRQ_HANDLED;
}
static void fsl_qspi_init_lut(struct fsl_qspi *q)
{
void __iomem *base = q->iobase;
int rxfifo = q->devtype_data->rxfifo;
u32 lut_base;
u8 cmd, addrlen, dummy;
int i;
fsl_qspi_unlock_lut(q);
for (i = 0; i < QUADSPI_LUT_NUM; i++)
qspi_writel(q, 0, base + QUADSPI_LUT_BASE + i * 4);
lut_base = SEQID_QUAD_READ * 4;
if (q->nor_size <= SZ_16M) {
cmd = SPINOR_OP_READ_1_1_4;
addrlen = ADDR24BIT;
dummy = 8;
} else {
cmd = SPINOR_OP_READ_1_1_4;
addrlen = ADDR32BIT;
dummy = 8;
}
qspi_writel(q, LUT0(CMD, PAD1, cmd) | LUT1(ADDR, PAD1, addrlen),
base + QUADSPI_LUT(lut_base));
qspi_writel(q, LUT0(DUMMY, PAD1, dummy) | LUT1(FSL_READ, PAD4, rxfifo),
base + QUADSPI_LUT(lut_base + 1));
lut_base = SEQID_WREN * 4;
qspi_writel(q, LUT0(CMD, PAD1, SPINOR_OP_WREN),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_PP * 4;
if (q->nor_size <= SZ_16M) {
cmd = SPINOR_OP_PP;
addrlen = ADDR24BIT;
} else {
cmd = SPINOR_OP_PP;
addrlen = ADDR32BIT;
}
qspi_writel(q, LUT0(CMD, PAD1, cmd) | LUT1(ADDR, PAD1, addrlen),
base + QUADSPI_LUT(lut_base));
qspi_writel(q, LUT0(FSL_WRITE, PAD1, 0),
base + QUADSPI_LUT(lut_base + 1));
lut_base = SEQID_RDSR * 4;
qspi_writel(q, LUT0(CMD, PAD1, SPINOR_OP_RDSR) |
LUT1(FSL_READ, PAD1, 0x1),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_SE * 4;
cmd = q->nor[0].erase_opcode;
addrlen = q->nor_size <= SZ_16M ? ADDR24BIT : ADDR32BIT;
qspi_writel(q, LUT0(CMD, PAD1, cmd) | LUT1(ADDR, PAD1, addrlen),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_CHIP_ERASE * 4;
qspi_writel(q, LUT0(CMD, PAD1, SPINOR_OP_CHIP_ERASE),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_RDID * 4;
qspi_writel(q, LUT0(CMD, PAD1, SPINOR_OP_RDID) |
LUT1(FSL_READ, PAD1, 0x8),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_WRSR * 4;
qspi_writel(q, LUT0(CMD, PAD1, SPINOR_OP_WRSR) |
LUT1(FSL_WRITE, PAD1, 0x2),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_RDCR * 4;
qspi_writel(q, LUT0(CMD, PAD1, SPINOR_OP_RDCR) |
LUT1(FSL_READ, PAD1, 0x1),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_WRDI * 4;
qspi_writel(q, LUT0(CMD, PAD1, SPINOR_OP_WRDI),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_EN4B * 4;
qspi_writel(q, LUT0(CMD, PAD1, SPINOR_OP_EN4B),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_BRWR * 4;
qspi_writel(q, LUT0(CMD, PAD1, SPINOR_OP_BRWR),
base + QUADSPI_LUT(lut_base));
fsl_qspi_lock_lut(q);
}
static int fsl_qspi_get_seqid(struct fsl_qspi *q, u8 cmd)
{
switch (cmd) {
case SPINOR_OP_READ_1_1_4:
return SEQID_QUAD_READ;
case SPINOR_OP_WREN:
return SEQID_WREN;
case SPINOR_OP_WRDI:
return SEQID_WRDI;
case SPINOR_OP_RDSR:
return SEQID_RDSR;
case SPINOR_OP_SE:
return SEQID_SE;
case SPINOR_OP_CHIP_ERASE:
return SEQID_CHIP_ERASE;
case SPINOR_OP_PP:
return SEQID_PP;
case SPINOR_OP_RDID:
return SEQID_RDID;
case SPINOR_OP_WRSR:
return SEQID_WRSR;
case SPINOR_OP_RDCR:
return SEQID_RDCR;
case SPINOR_OP_EN4B:
return SEQID_EN4B;
case SPINOR_OP_BRWR:
return SEQID_BRWR;
default:
if (cmd == q->nor[0].erase_opcode)
return SEQID_SE;
dev_err(q->dev, "Unsupported cmd 0x%.2x\n", cmd);
break;
}
return -EINVAL;
}
static int
fsl_qspi_runcmd(struct fsl_qspi *q, u8 cmd, unsigned int addr, int len)
{
void __iomem *base = q->iobase;
int seqid;
u32 reg, reg2;
int err;
init_completion(&q->c);
dev_dbg(q->dev, "to 0x%.8x:0x%.8x, len:%d, cmd:%.2x\n",
q->chip_base_addr, addr, len, cmd);
reg = qspi_readl(q, base + QUADSPI_MCR);
qspi_writel(q, q->memmap_phy + q->chip_base_addr + addr,
base + QUADSPI_SFAR);
qspi_writel(q, QUADSPI_RBCT_WMRK_MASK | QUADSPI_RBCT_RXBRD_USEIPS,
base + QUADSPI_RBCT);
qspi_writel(q, reg | QUADSPI_MCR_CLR_RXF_MASK, base + QUADSPI_MCR);
do {
reg2 = qspi_readl(q, base + QUADSPI_SR);
if (reg2 & (QUADSPI_SR_IP_ACC_MASK | QUADSPI_SR_AHB_ACC_MASK)) {
udelay(1);
dev_dbg(q->dev, "The controller is busy, 0x%x\n", reg2);
continue;
}
break;
} while (1);
seqid = fsl_qspi_get_seqid(q, cmd);
qspi_writel(q, (seqid << QUADSPI_IPCR_SEQID_SHIFT) | len,
base + QUADSPI_IPCR);
if (!wait_for_completion_timeout(&q->c, msecs_to_jiffies(1000))) {
dev_err(q->dev,
"cmd 0x%.2x timeout, addr@%.8x, FR:0x%.8x, SR:0x%.8x\n",
cmd, addr, qspi_readl(q, base + QUADSPI_FR),
qspi_readl(q, base + QUADSPI_SR));
err = -ETIMEDOUT;
} else {
err = 0;
}
qspi_writel(q, reg, base + QUADSPI_MCR);
return err;
}
static void fsl_qspi_read_data(struct fsl_qspi *q, int len, u8 *rxbuf)
{
u32 tmp;
int i = 0;
while (len > 0) {
tmp = qspi_readl(q, q->iobase + QUADSPI_RBDR + i * 4);
tmp = fsl_qspi_endian_xchg(q, tmp);
dev_dbg(q->dev, "chip addr:0x%.8x, rcv:0x%.8x\n",
q->chip_base_addr, tmp);
if (len >= 4) {
*((u32 *)rxbuf) = tmp;
rxbuf += 4;
} else {
memcpy(rxbuf, &tmp, len);
break;
}
len -= 4;
i++;
}
}
static inline void fsl_qspi_invalid(struct fsl_qspi *q)
{
u32 reg;
reg = qspi_readl(q, q->iobase + QUADSPI_MCR);
reg |= QUADSPI_MCR_SWRSTHD_MASK | QUADSPI_MCR_SWRSTSD_MASK;
qspi_writel(q, reg, q->iobase + QUADSPI_MCR);
udelay(1);
reg &= ~(QUADSPI_MCR_SWRSTHD_MASK | QUADSPI_MCR_SWRSTSD_MASK);
qspi_writel(q, reg, q->iobase + QUADSPI_MCR);
}
static int fsl_qspi_nor_write(struct fsl_qspi *q, struct spi_nor *nor,
u8 opcode, unsigned int to, u32 *txbuf,
unsigned count, size_t *retlen)
{
int ret, i, j;
u32 tmp;
dev_dbg(q->dev, "to 0x%.8x:0x%.8x, len : %d\n",
q->chip_base_addr, to, count);
tmp = qspi_readl(q, q->iobase + QUADSPI_MCR);
qspi_writel(q, tmp | QUADSPI_MCR_CLR_TXF_MASK, q->iobase + QUADSPI_MCR);
for (j = 0, i = ((count + 3) / 4); j < i; j++) {
tmp = fsl_qspi_endian_xchg(q, *txbuf);
qspi_writel(q, tmp, q->iobase + QUADSPI_TBDR);
txbuf++;
}
if (needs_fill_txfifo(q))
for (; i < 4; i++)
qspi_writel(q, tmp, q->iobase + QUADSPI_TBDR);
ret = fsl_qspi_runcmd(q, opcode, to, count);
if (ret == 0 && retlen)
*retlen += count;
return ret;
}
static void fsl_qspi_set_map_addr(struct fsl_qspi *q)
{
int nor_size = q->nor_size;
void __iomem *base = q->iobase;
qspi_writel(q, nor_size + q->memmap_phy, base + QUADSPI_SFA1AD);
qspi_writel(q, nor_size * 2 + q->memmap_phy, base + QUADSPI_SFA2AD);
qspi_writel(q, nor_size * 3 + q->memmap_phy, base + QUADSPI_SFB1AD);
qspi_writel(q, nor_size * 4 + q->memmap_phy, base + QUADSPI_SFB2AD);
}
static void fsl_qspi_init_abh_read(struct fsl_qspi *q)
{
void __iomem *base = q->iobase;
int seqid;
qspi_writel(q, QUADSPI_BUFXCR_INVALID_MSTRID, base + QUADSPI_BUF0CR);
qspi_writel(q, QUADSPI_BUFXCR_INVALID_MSTRID, base + QUADSPI_BUF1CR);
qspi_writel(q, QUADSPI_BUFXCR_INVALID_MSTRID, base + QUADSPI_BUF2CR);
qspi_writel(q, QUADSPI_BUF3CR_ALLMST_MASK |
((q->devtype_data->ahb_buf_size / 8)
<< QUADSPI_BUF3CR_ADATSZ_SHIFT),
base + QUADSPI_BUF3CR);
qspi_writel(q, 0, base + QUADSPI_BUF0IND);
qspi_writel(q, 0, base + QUADSPI_BUF1IND);
qspi_writel(q, 0, base + QUADSPI_BUF2IND);
seqid = fsl_qspi_get_seqid(q, q->nor[0].read_opcode);
qspi_writel(q, seqid << QUADSPI_BFGENCR_SEQID_SHIFT,
q->iobase + QUADSPI_BFGENCR);
}
static int fsl_qspi_clk_prep_enable(struct fsl_qspi *q)
{
int ret;
ret = clk_prepare_enable(q->clk_en);
if (ret)
return ret;
ret = clk_prepare_enable(q->clk);
if (ret) {
clk_disable_unprepare(q->clk_en);
return ret;
}
if (needs_wakeup_wait_mode(q))
pm_qos_add_request(&q->pm_qos_req, PM_QOS_CPU_DMA_LATENCY, 0);
return 0;
}
static void fsl_qspi_clk_disable_unprep(struct fsl_qspi *q)
{
if (needs_wakeup_wait_mode(q))
pm_qos_remove_request(&q->pm_qos_req);
clk_disable_unprepare(q->clk);
clk_disable_unprepare(q->clk_en);
}
static int fsl_qspi_nor_setup(struct fsl_qspi *q)
{
void __iomem *base = q->iobase;
u32 reg;
int ret;
fsl_qspi_clk_disable_unprep(q);
ret = clk_set_rate(q->clk, 66000000);
if (ret)
return ret;
ret = fsl_qspi_clk_prep_enable(q);
if (ret)
return ret;
qspi_writel(q, QUADSPI_MCR_SWRSTSD_MASK | QUADSPI_MCR_SWRSTHD_MASK,
base + QUADSPI_MCR);
udelay(1);
fsl_qspi_init_lut(q);
qspi_writel(q, QUADSPI_MCR_MDIS_MASK | QUADSPI_MCR_RESERVED_MASK,
base + QUADSPI_MCR);
reg = qspi_readl(q, base + QUADSPI_SMPR);
qspi_writel(q, reg & ~(QUADSPI_SMPR_FSDLY_MASK
| QUADSPI_SMPR_FSPHS_MASK
| QUADSPI_SMPR_HSENA_MASK
| QUADSPI_SMPR_DDRSMP_MASK), base + QUADSPI_SMPR);
qspi_writel(q, QUADSPI_MCR_RESERVED_MASK | QUADSPI_MCR_END_CFG_MASK,
base + QUADSPI_MCR);
qspi_writel(q, 0xffffffff, q->iobase + QUADSPI_FR);
qspi_writel(q, QUADSPI_RSER_TFIE, q->iobase + QUADSPI_RSER);
return 0;
}
static int fsl_qspi_nor_setup_last(struct fsl_qspi *q)
{
unsigned long rate = q->clk_rate;
int ret;
if (needs_4x_clock(q))
rate *= 4;
fsl_qspi_clk_disable_unprep(q);
ret = clk_set_rate(q->clk, rate);
if (ret)
return ret;
ret = fsl_qspi_clk_prep_enable(q);
if (ret)
return ret;
fsl_qspi_init_lut(q);
fsl_qspi_init_abh_read(q);
return 0;
}
static void fsl_qspi_set_base_addr(struct fsl_qspi *q, struct spi_nor *nor)
{
q->chip_base_addr = q->nor_size * (nor - q->nor);
}
static int fsl_qspi_read_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
int ret;
struct fsl_qspi *q = nor->priv;
ret = fsl_qspi_runcmd(q, opcode, 0, len);
if (ret)
return ret;
fsl_qspi_read_data(q, len, buf);
return 0;
}
static int fsl_qspi_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
struct fsl_qspi *q = nor->priv;
int ret;
if (!buf) {
ret = fsl_qspi_runcmd(q, opcode, 0, 1);
if (ret)
return ret;
if (opcode == SPINOR_OP_CHIP_ERASE)
fsl_qspi_invalid(q);
} else if (len > 0) {
ret = fsl_qspi_nor_write(q, nor, opcode, 0,
(u32 *)buf, len, NULL);
} else {
dev_err(q->dev, "invalid cmd %d\n", opcode);
ret = -EINVAL;
}
return ret;
}
static void fsl_qspi_write(struct spi_nor *nor, loff_t to,
size_t len, size_t *retlen, const u_char *buf)
{
struct fsl_qspi *q = nor->priv;
fsl_qspi_nor_write(q, nor, nor->program_opcode, to,
(u32 *)buf, len, retlen);
fsl_qspi_invalid(q);
}
static int fsl_qspi_read(struct spi_nor *nor, loff_t from,
size_t len, size_t *retlen, u_char *buf)
{
struct fsl_qspi *q = nor->priv;
u8 cmd = nor->read_opcode;
if (!q->ahb_addr) {
q->memmap_offs = q->chip_base_addr + from;
q->memmap_len = len > QUADSPI_MIN_IOMAP ? len : QUADSPI_MIN_IOMAP;
q->ahb_addr = ioremap_nocache(
q->memmap_phy + q->memmap_offs,
q->memmap_len);
if (!q->ahb_addr) {
dev_err(q->dev, "ioremap failed\n");
return -ENOMEM;
}
} else if (q->chip_base_addr + from < q->memmap_offs
|| q->chip_base_addr + from + len >
q->memmap_offs + q->memmap_len) {
iounmap(q->ahb_addr);
q->memmap_offs = q->chip_base_addr + from;
q->memmap_len = len > QUADSPI_MIN_IOMAP ? len : QUADSPI_MIN_IOMAP;
q->ahb_addr = ioremap_nocache(
q->memmap_phy + q->memmap_offs,
q->memmap_len);
if (!q->ahb_addr) {
dev_err(q->dev, "ioremap failed\n");
return -ENOMEM;
}
}
dev_dbg(q->dev, "cmd [%x],read from %p, len:%zd\n",
cmd, q->ahb_addr + q->chip_base_addr + from - q->memmap_offs,
len);
memcpy(buf, q->ahb_addr + q->chip_base_addr + from - q->memmap_offs,
len);
*retlen += len;
return 0;
}
static int fsl_qspi_erase(struct spi_nor *nor, loff_t offs)
{
struct fsl_qspi *q = nor->priv;
int ret;
dev_dbg(nor->dev, "%dKiB at 0x%08x:0x%08x\n",
nor->mtd.erasesize / 1024, q->chip_base_addr, (u32)offs);
ret = fsl_qspi_runcmd(q, nor->erase_opcode, offs, 0);
if (ret)
return ret;
fsl_qspi_invalid(q);
return 0;
}
static int fsl_qspi_prep(struct spi_nor *nor, enum spi_nor_ops ops)
{
struct fsl_qspi *q = nor->priv;
int ret;
mutex_lock(&q->lock);
ret = fsl_qspi_clk_prep_enable(q);
if (ret)
goto err_mutex;
fsl_qspi_set_base_addr(q, nor);
return 0;
err_mutex:
mutex_unlock(&q->lock);
return ret;
}
static void fsl_qspi_unprep(struct spi_nor *nor, enum spi_nor_ops ops)
{
struct fsl_qspi *q = nor->priv;
fsl_qspi_clk_disable_unprep(q);
mutex_unlock(&q->lock);
}
static int fsl_qspi_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct fsl_qspi *q;
struct resource *res;
struct spi_nor *nor;
struct mtd_info *mtd;
int ret, i = 0;
q = devm_kzalloc(dev, sizeof(*q), GFP_KERNEL);
if (!q)
return -ENOMEM;
q->nor_num = of_get_child_count(dev->of_node);
if (!q->nor_num || q->nor_num > FSL_QSPI_MAX_CHIP)
return -ENODEV;
q->dev = dev;
q->devtype_data = of_device_get_match_data(dev);
if (!q->devtype_data)
return -ENODEV;
platform_set_drvdata(pdev, q);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "QuadSPI");
q->iobase = devm_ioremap_resource(dev, res);
if (IS_ERR(q->iobase))
return PTR_ERR(q->iobase);
q->big_endian = of_property_read_bool(np, "big-endian");
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"QuadSPI-memory");
if (!devm_request_mem_region(dev, res->start, resource_size(res),
res->name)) {
dev_err(dev, "can't request region for resource %pR\n", res);
return -EBUSY;
}
q->memmap_phy = res->start;
q->clk_en = devm_clk_get(dev, "qspi_en");
if (IS_ERR(q->clk_en))
return PTR_ERR(q->clk_en);
q->clk = devm_clk_get(dev, "qspi");
if (IS_ERR(q->clk))
return PTR_ERR(q->clk);
ret = fsl_qspi_clk_prep_enable(q);
if (ret) {
dev_err(dev, "can not enable the clock\n");
goto clk_failed;
}
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(dev, "failed to get the irq: %d\n", ret);
goto irq_failed;
}
ret = devm_request_irq(dev, ret,
fsl_qspi_irq_handler, 0, pdev->name, q);
if (ret) {
dev_err(dev, "failed to request irq: %d\n", ret);
goto irq_failed;
}
ret = fsl_qspi_nor_setup(q);
if (ret)
goto irq_failed;
if (of_get_property(np, "fsl,qspi-has-second-chip", NULL))
q->has_second_chip = true;
mutex_init(&q->lock);
for_each_available_child_of_node(dev->of_node, np) {
if (!q->has_second_chip)
i *= 2;
nor = &q->nor[i];
mtd = &nor->mtd;
nor->dev = dev;
spi_nor_set_flash_node(nor, np);
nor->priv = q;
nor->read_reg = fsl_qspi_read_reg;
nor->write_reg = fsl_qspi_write_reg;
nor->read = fsl_qspi_read;
nor->write = fsl_qspi_write;
nor->erase = fsl_qspi_erase;
nor->prepare = fsl_qspi_prep;
nor->unprepare = fsl_qspi_unprep;
ret = of_property_read_u32(np, "spi-max-frequency",
&q->clk_rate);
if (ret < 0)
goto mutex_failed;
fsl_qspi_set_base_addr(q, nor);
ret = spi_nor_scan(nor, NULL, SPI_NOR_QUAD);
if (ret)
goto mutex_failed;
ret = mtd_device_register(mtd, NULL, 0);
if (ret)
goto mutex_failed;
if (q->nor_size == 0) {
q->nor_size = mtd->size;
fsl_qspi_set_map_addr(q);
}
if (nor->page_size > q->devtype_data->txfifo)
nor->page_size = q->devtype_data->txfifo;
i++;
}
ret = fsl_qspi_nor_setup_last(q);
if (ret)
goto last_init_failed;
fsl_qspi_clk_disable_unprep(q);
return 0;
last_init_failed:
for (i = 0; i < q->nor_num; i++) {
if (!q->has_second_chip)
i *= 2;
mtd_device_unregister(&q->nor[i].mtd);
}
mutex_failed:
mutex_destroy(&q->lock);
irq_failed:
fsl_qspi_clk_disable_unprep(q);
clk_failed:
dev_err(dev, "Freescale QuadSPI probe failed\n");
return ret;
}
static int fsl_qspi_remove(struct platform_device *pdev)
{
struct fsl_qspi *q = platform_get_drvdata(pdev);
int i;
for (i = 0; i < q->nor_num; i++) {
if (!q->has_second_chip)
i *= 2;
mtd_device_unregister(&q->nor[i].mtd);
}
qspi_writel(q, QUADSPI_MCR_MDIS_MASK, q->iobase + QUADSPI_MCR);
qspi_writel(q, 0x0, q->iobase + QUADSPI_RSER);
mutex_destroy(&q->lock);
if (q->ahb_addr)
iounmap(q->ahb_addr);
return 0;
}
static int fsl_qspi_suspend(struct platform_device *pdev, pm_message_t state)
{
return 0;
}
static int fsl_qspi_resume(struct platform_device *pdev)
{
int ret;
struct fsl_qspi *q = platform_get_drvdata(pdev);
ret = fsl_qspi_clk_prep_enable(q);
if (ret)
return ret;
fsl_qspi_nor_setup(q);
fsl_qspi_set_map_addr(q);
fsl_qspi_nor_setup_last(q);
fsl_qspi_clk_disable_unprep(q);
return 0;
}
