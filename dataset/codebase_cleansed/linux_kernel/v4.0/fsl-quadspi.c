static inline int is_vybrid_qspi(struct fsl_qspi *q)
{
return q->devtype_data->devtype == FSL_QUADSPI_VYBRID;
}
static inline int is_imx6sx_qspi(struct fsl_qspi *q)
{
return q->devtype_data->devtype == FSL_QUADSPI_IMX6SX;
}
static inline u32 fsl_qspi_endian_xchg(struct fsl_qspi *q, u32 a)
{
return is_vybrid_qspi(q) ? __swab32(a) : a;
}
static inline void fsl_qspi_unlock_lut(struct fsl_qspi *q)
{
writel(QUADSPI_LUTKEY_VALUE, q->iobase + QUADSPI_LUTKEY);
writel(QUADSPI_LCKER_UNLOCK, q->iobase + QUADSPI_LCKCR);
}
static inline void fsl_qspi_lock_lut(struct fsl_qspi *q)
{
writel(QUADSPI_LUTKEY_VALUE, q->iobase + QUADSPI_LUTKEY);
writel(QUADSPI_LCKER_LOCK, q->iobase + QUADSPI_LCKCR);
}
static irqreturn_t fsl_qspi_irq_handler(int irq, void *dev_id)
{
struct fsl_qspi *q = dev_id;
u32 reg;
reg = readl(q->iobase + QUADSPI_FR);
writel(reg, q->iobase + QUADSPI_FR);
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
writel(0, base + QUADSPI_LUT_BASE + i * 4);
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
writel(LUT0(CMD, PAD1, cmd) | LUT1(ADDR, PAD1, addrlen),
base + QUADSPI_LUT(lut_base));
writel(LUT0(DUMMY, PAD1, dummy) | LUT1(READ, PAD4, rxfifo),
base + QUADSPI_LUT(lut_base + 1));
lut_base = SEQID_WREN * 4;
writel(LUT0(CMD, PAD1, SPINOR_OP_WREN), base + QUADSPI_LUT(lut_base));
lut_base = SEQID_PP * 4;
if (q->nor_size <= SZ_16M) {
cmd = SPINOR_OP_PP;
addrlen = ADDR24BIT;
} else {
cmd = SPINOR_OP_PP;
addrlen = ADDR32BIT;
}
writel(LUT0(CMD, PAD1, cmd) | LUT1(ADDR, PAD1, addrlen),
base + QUADSPI_LUT(lut_base));
writel(LUT0(WRITE, PAD1, 0), base + QUADSPI_LUT(lut_base + 1));
lut_base = SEQID_RDSR * 4;
writel(LUT0(CMD, PAD1, SPINOR_OP_RDSR) | LUT1(READ, PAD1, 0x1),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_SE * 4;
if (q->nor_size <= SZ_16M) {
cmd = SPINOR_OP_SE;
addrlen = ADDR24BIT;
} else {
cmd = SPINOR_OP_SE;
addrlen = ADDR32BIT;
}
writel(LUT0(CMD, PAD1, cmd) | LUT1(ADDR, PAD1, addrlen),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_CHIP_ERASE * 4;
writel(LUT0(CMD, PAD1, SPINOR_OP_CHIP_ERASE),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_RDID * 4;
writel(LUT0(CMD, PAD1, SPINOR_OP_RDID) | LUT1(READ, PAD1, 0x8),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_WRSR * 4;
writel(LUT0(CMD, PAD1, SPINOR_OP_WRSR) | LUT1(WRITE, PAD1, 0x2),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_RDCR * 4;
writel(LUT0(CMD, PAD1, SPINOR_OP_RDCR) | LUT1(READ, PAD1, 0x1),
base + QUADSPI_LUT(lut_base));
lut_base = SEQID_WRDI * 4;
writel(LUT0(CMD, PAD1, SPINOR_OP_WRDI), base + QUADSPI_LUT(lut_base));
lut_base = SEQID_EN4B * 4;
writel(LUT0(CMD, PAD1, SPINOR_OP_EN4B), base + QUADSPI_LUT(lut_base));
lut_base = SEQID_BRWR * 4;
writel(LUT0(CMD, PAD1, SPINOR_OP_BRWR), base + QUADSPI_LUT(lut_base));
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
reg = readl(base + QUADSPI_MCR);
writel(q->memmap_phy + q->chip_base_addr + addr, base + QUADSPI_SFAR);
writel(QUADSPI_RBCT_WMRK_MASK | QUADSPI_RBCT_RXBRD_USEIPS,
base + QUADSPI_RBCT);
writel(reg | QUADSPI_MCR_CLR_RXF_MASK, base + QUADSPI_MCR);
do {
reg2 = readl(base + QUADSPI_SR);
if (reg2 & (QUADSPI_SR_IP_ACC_MASK | QUADSPI_SR_AHB_ACC_MASK)) {
udelay(1);
dev_dbg(q->dev, "The controller is busy, 0x%x\n", reg2);
continue;
}
break;
} while (1);
seqid = fsl_qspi_get_seqid(q, cmd);
writel((seqid << QUADSPI_IPCR_SEQID_SHIFT) | len, base + QUADSPI_IPCR);
err = wait_for_completion_timeout(&q->c, msecs_to_jiffies(1000));
if (!err) {
dev_err(q->dev,
"cmd 0x%.2x timeout, addr@%.8x, FR:0x%.8x, SR:0x%.8x\n",
cmd, addr, readl(base + QUADSPI_FR),
readl(base + QUADSPI_SR));
err = -ETIMEDOUT;
} else {
err = 0;
}
writel(reg, base + QUADSPI_MCR);
return err;
}
static void fsl_qspi_read_data(struct fsl_qspi *q, int len, u8 *rxbuf)
{
u32 tmp;
int i = 0;
while (len > 0) {
tmp = readl(q->iobase + QUADSPI_RBDR + i * 4);
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
reg = readl(q->iobase + QUADSPI_MCR);
reg |= QUADSPI_MCR_SWRSTHD_MASK | QUADSPI_MCR_SWRSTSD_MASK;
writel(reg, q->iobase + QUADSPI_MCR);
udelay(1);
reg &= ~(QUADSPI_MCR_SWRSTHD_MASK | QUADSPI_MCR_SWRSTSD_MASK);
writel(reg, q->iobase + QUADSPI_MCR);
}
static int fsl_qspi_nor_write(struct fsl_qspi *q, struct spi_nor *nor,
u8 opcode, unsigned int to, u32 *txbuf,
unsigned count, size_t *retlen)
{
int ret, i, j;
u32 tmp;
dev_dbg(q->dev, "to 0x%.8x:0x%.8x, len : %d\n",
q->chip_base_addr, to, count);
tmp = readl(q->iobase + QUADSPI_MCR);
writel(tmp | QUADSPI_MCR_CLR_RXF_MASK, q->iobase + QUADSPI_MCR);
for (j = 0, i = ((count + 3) / 4); j < i; j++) {
tmp = fsl_qspi_endian_xchg(q, *txbuf);
writel(tmp, q->iobase + QUADSPI_TBDR);
txbuf++;
}
ret = fsl_qspi_runcmd(q, opcode, to, count);
if (ret == 0 && retlen)
*retlen += count;
return ret;
}
static void fsl_qspi_set_map_addr(struct fsl_qspi *q)
{
int nor_size = q->nor_size;
void __iomem *base = q->iobase;
writel(nor_size + q->memmap_phy, base + QUADSPI_SFA1AD);
writel(nor_size * 2 + q->memmap_phy, base + QUADSPI_SFA2AD);
writel(nor_size * 3 + q->memmap_phy, base + QUADSPI_SFB1AD);
writel(nor_size * 4 + q->memmap_phy, base + QUADSPI_SFB2AD);
}
static void fsl_qspi_init_abh_read(struct fsl_qspi *q)
{
void __iomem *base = q->iobase;
int seqid;
writel(QUADSPI_BUFXCR_INVALID_MSTRID, base + QUADSPI_BUF0CR);
writel(QUADSPI_BUFXCR_INVALID_MSTRID, base + QUADSPI_BUF1CR);
writel(QUADSPI_BUFXCR_INVALID_MSTRID, base + QUADSPI_BUF2CR);
writel(QUADSPI_BUF3CR_ALLMST_MASK | ((q->devtype_data->ahb_buf_size / 8)
<< QUADSPI_BUF3CR_ADATSZ_SHIFT), base + QUADSPI_BUF3CR);
writel(0, base + QUADSPI_BUF0IND);
writel(0, base + QUADSPI_BUF1IND);
writel(0, base + QUADSPI_BUF2IND);
seqid = fsl_qspi_get_seqid(q, q->nor[0].read_opcode);
writel(seqid << QUADSPI_BFGENCR_SEQID_SHIFT,
q->iobase + QUADSPI_BFGENCR);
}
static int fsl_qspi_nor_setup(struct fsl_qspi *q)
{
void __iomem *base = q->iobase;
u32 reg;
int ret;
ret = clk_set_rate(q->clk, 66000000);
if (ret)
return ret;
fsl_qspi_init_lut(q);
writel(QUADSPI_MCR_MDIS_MASK | QUADSPI_MCR_RESERVED_MASK,
base + QUADSPI_MCR);
reg = readl(base + QUADSPI_SMPR);
writel(reg & ~(QUADSPI_SMPR_FSDLY_MASK
| QUADSPI_SMPR_FSPHS_MASK
| QUADSPI_SMPR_HSENA_MASK
| QUADSPI_SMPR_DDRSMP_MASK), base + QUADSPI_SMPR);
writel(QUADSPI_MCR_RESERVED_MASK | QUADSPI_MCR_END_CFG_MASK,
base + QUADSPI_MCR);
writel(QUADSPI_RSER_TFIE, q->iobase + QUADSPI_RSER);
return 0;
}
static int fsl_qspi_nor_setup_last(struct fsl_qspi *q)
{
unsigned long rate = q->clk_rate;
int ret;
if (is_imx6sx_qspi(q))
rate *= 4;
ret = clk_set_rate(q->clk, rate);
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
static int fsl_qspi_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len,
int write_enable)
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
dev_dbg(q->dev, "cmd [%x],read from (0x%p, 0x%.8x, 0x%.8x),len:%d\n",
cmd, q->ahb_base, q->chip_base_addr, (unsigned int)from, len);
memcpy(buf, q->ahb_base + q->chip_base_addr + from, len);
*retlen += len;
return 0;
}
static int fsl_qspi_erase(struct spi_nor *nor, loff_t offs)
{
struct fsl_qspi *q = nor->priv;
int ret;
dev_dbg(nor->dev, "%dKiB at 0x%08x:0x%08x\n",
nor->mtd->erasesize / 1024, q->chip_base_addr, (u32)offs);
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
ret = clk_enable(q->clk_en);
if (ret)
return ret;
ret = clk_enable(q->clk);
if (ret) {
clk_disable(q->clk_en);
return ret;
}
fsl_qspi_set_base_addr(q, nor);
return 0;
}
static void fsl_qspi_unprep(struct spi_nor *nor, enum spi_nor_ops ops)
{
struct fsl_qspi *q = nor->priv;
clk_disable(q->clk);
clk_disable(q->clk_en);
}
static int fsl_qspi_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mtd_part_parser_data ppdata;
struct device *dev = &pdev->dev;
struct fsl_qspi *q;
struct resource *res;
struct spi_nor *nor;
struct mtd_info *mtd;
int ret, i = 0;
const struct of_device_id *of_id =
of_match_device(fsl_qspi_dt_ids, &pdev->dev);
q = devm_kzalloc(dev, sizeof(*q), GFP_KERNEL);
if (!q)
return -ENOMEM;
q->nor_num = of_get_child_count(dev->of_node);
if (!q->nor_num || q->nor_num > FSL_QSPI_MAX_CHIP)
return -ENODEV;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "QuadSPI");
q->iobase = devm_ioremap_resource(dev, res);
if (IS_ERR(q->iobase))
return PTR_ERR(q->iobase);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"QuadSPI-memory");
q->ahb_base = devm_ioremap_resource(dev, res);
if (IS_ERR(q->ahb_base))
return PTR_ERR(q->ahb_base);
q->memmap_phy = res->start;
q->clk_en = devm_clk_get(dev, "qspi_en");
if (IS_ERR(q->clk_en))
return PTR_ERR(q->clk_en);
q->clk = devm_clk_get(dev, "qspi");
if (IS_ERR(q->clk))
return PTR_ERR(q->clk);
ret = clk_prepare_enable(q->clk_en);
if (ret) {
dev_err(dev, "can not enable the qspi_en clock\n");
return ret;
}
ret = clk_prepare_enable(q->clk);
if (ret) {
dev_err(dev, "can not enable the qspi clock\n");
goto clk_failed;
}
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(dev, "failed to get the irq\n");
goto irq_failed;
}
ret = devm_request_irq(dev, ret,
fsl_qspi_irq_handler, 0, pdev->name, q);
if (ret) {
dev_err(dev, "failed to request irq.\n");
goto irq_failed;
}
q->dev = dev;
q->devtype_data = (struct fsl_qspi_devtype_data *)of_id->data;
platform_set_drvdata(pdev, q);
ret = fsl_qspi_nor_setup(q);
if (ret)
goto irq_failed;
if (of_get_property(np, "fsl,qspi-has-second-chip", NULL))
q->has_second_chip = true;
for_each_available_child_of_node(dev->of_node, np) {
char modalias[40];
if (!q->has_second_chip)
i *= 2;
nor = &q->nor[i];
mtd = &q->mtd[i];
nor->mtd = mtd;
nor->dev = dev;
nor->priv = q;
mtd->priv = nor;
nor->read_reg = fsl_qspi_read_reg;
nor->write_reg = fsl_qspi_write_reg;
nor->read = fsl_qspi_read;
nor->write = fsl_qspi_write;
nor->erase = fsl_qspi_erase;
nor->prepare = fsl_qspi_prep;
nor->unprepare = fsl_qspi_unprep;
ret = of_modalias_node(np, modalias, sizeof(modalias));
if (ret < 0)
goto irq_failed;
ret = of_property_read_u32(np, "spi-max-frequency",
&q->clk_rate);
if (ret < 0)
goto irq_failed;
fsl_qspi_set_base_addr(q, nor);
ret = spi_nor_scan(nor, modalias, SPI_NOR_QUAD);
if (ret)
goto irq_failed;
ppdata.of_node = np;
ret = mtd_device_parse_register(mtd, NULL, &ppdata, NULL, 0);
if (ret)
goto irq_failed;
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
clk_disable(q->clk);
clk_disable(q->clk_en);
return 0;
last_init_failed:
for (i = 0; i < q->nor_num; i++) {
if (!q->has_second_chip)
i *= 2;
mtd_device_unregister(&q->mtd[i]);
}
irq_failed:
clk_disable_unprepare(q->clk);
clk_failed:
clk_disable_unprepare(q->clk_en);
return ret;
}
static int fsl_qspi_remove(struct platform_device *pdev)
{
struct fsl_qspi *q = platform_get_drvdata(pdev);
int i;
for (i = 0; i < q->nor_num; i++) {
if (!q->has_second_chip)
i *= 2;
mtd_device_unregister(&q->mtd[i]);
}
writel(QUADSPI_MCR_MDIS_MASK, q->iobase + QUADSPI_MCR);
writel(0x0, q->iobase + QUADSPI_RSER);
clk_unprepare(q->clk);
clk_unprepare(q->clk_en);
return 0;
}
static int fsl_qspi_suspend(struct platform_device *pdev, pm_message_t state)
{
return 0;
}
static int fsl_qspi_resume(struct platform_device *pdev)
{
struct fsl_qspi *q = platform_get_drvdata(pdev);
fsl_qspi_nor_setup(q);
fsl_qspi_set_map_addr(q);
fsl_qspi_nor_setup_last(q);
return 0;
}
