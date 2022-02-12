static void set_addr(struct mtd_info *mtd, int column, int page_addr, int oob)
{
struct nand_chip *chip = mtd->priv;
struct fsl_ifc_mtd *priv = chip->priv;
struct fsl_ifc_ctrl *ctrl = priv->ctrl;
struct fsl_ifc_regs __iomem *ifc = ctrl->regs;
int buf_num;
ifc_nand_ctrl->page = page_addr;
iowrite32be(page_addr, &ifc->ifc_nand.row0);
iowrite32be((oob ? IFC_NAND_COL_MS : 0) | column, &ifc->ifc_nand.col0);
buf_num = page_addr & priv->bufnum_mask;
ifc_nand_ctrl->addr = priv->vbase + buf_num * (mtd->writesize * 2);
ifc_nand_ctrl->index = column;
if (oob)
ifc_nand_ctrl->index += mtd->writesize;
}
static int is_blank(struct mtd_info *mtd, unsigned int bufnum)
{
struct nand_chip *chip = mtd->priv;
struct fsl_ifc_mtd *priv = chip->priv;
u8 __iomem *addr = priv->vbase + bufnum * (mtd->writesize * 2);
u32 __iomem *mainarea = (u32 __iomem *)addr;
u8 __iomem *oob = addr + mtd->writesize;
int i;
for (i = 0; i < mtd->writesize / 4; i++) {
if (__raw_readl(&mainarea[i]) != 0xffffffff)
return 0;
}
for (i = 0; i < chip->ecc.layout->eccbytes; i++) {
int pos = chip->ecc.layout->eccpos[i];
if (__raw_readb(&oob[pos]) != 0xff)
return 0;
}
return 1;
}
static int check_read_ecc(struct mtd_info *mtd, struct fsl_ifc_ctrl *ctrl,
u32 *eccstat, unsigned int bufnum)
{
u32 reg = eccstat[bufnum / 4];
int errors;
errors = (reg >> ((3 - bufnum % 4) * 8)) & 15;
return errors;
}
static void fsl_ifc_run_command(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct fsl_ifc_mtd *priv = chip->priv;
struct fsl_ifc_ctrl *ctrl = priv->ctrl;
struct fsl_ifc_nand_ctrl *nctrl = ifc_nand_ctrl;
struct fsl_ifc_regs __iomem *ifc = ctrl->regs;
u32 eccstat[4];
int i;
iowrite32be(priv->bank << IFC_NAND_CSEL_SHIFT,
&ifc->ifc_nand.nand_csel);
dev_vdbg(priv->dev,
"%s: fir0=%08x fcr0=%08x\n",
__func__,
ioread32be(&ifc->ifc_nand.nand_fir0),
ioread32be(&ifc->ifc_nand.nand_fcr0));
ctrl->nand_stat = 0;
iowrite32be(IFC_NAND_SEQ_STRT_FIR_STRT, &ifc->ifc_nand.nandseq_strt);
wait_event_timeout(ctrl->nand_wait, ctrl->nand_stat,
IFC_TIMEOUT_MSECS * HZ/1000);
if (!ctrl->nand_stat)
dev_err(priv->dev, "Controller is not responding\n");
if (ctrl->nand_stat & IFC_NAND_EVTER_STAT_FTOER)
dev_err(priv->dev, "NAND Flash Timeout Error\n");
if (ctrl->nand_stat & IFC_NAND_EVTER_STAT_WPER)
dev_err(priv->dev, "NAND Flash Write Protect Error\n");
nctrl->max_bitflips = 0;
if (nctrl->eccread) {
int errors;
int bufnum = nctrl->page & priv->bufnum_mask;
int sector = bufnum * chip->ecc.steps;
int sector_end = sector + chip->ecc.steps - 1;
for (i = sector / 4; i <= sector_end / 4; i++)
eccstat[i] = ioread32be(&ifc->ifc_nand.nand_eccstat[i]);
for (i = sector; i <= sector_end; i++) {
errors = check_read_ecc(mtd, ctrl, eccstat, i);
if (errors == 15) {
if (!is_blank(mtd, bufnum))
ctrl->nand_stat |=
IFC_NAND_EVTER_STAT_ECCER;
break;
}
mtd->ecc_stats.corrected += errors;
nctrl->max_bitflips = max_t(unsigned int,
nctrl->max_bitflips,
errors);
}
nctrl->eccread = 0;
}
}
static void fsl_ifc_do_read(struct nand_chip *chip,
int oob,
struct mtd_info *mtd)
{
struct fsl_ifc_mtd *priv = chip->priv;
struct fsl_ifc_ctrl *ctrl = priv->ctrl;
struct fsl_ifc_regs __iomem *ifc = ctrl->regs;
if (mtd->writesize > 512) {
iowrite32be((IFC_FIR_OP_CW0 << IFC_NAND_FIR0_OP0_SHIFT) |
(IFC_FIR_OP_CA0 << IFC_NAND_FIR0_OP1_SHIFT) |
(IFC_FIR_OP_RA0 << IFC_NAND_FIR0_OP2_SHIFT) |
(IFC_FIR_OP_CMD1 << IFC_NAND_FIR0_OP3_SHIFT) |
(IFC_FIR_OP_RBCD << IFC_NAND_FIR0_OP4_SHIFT),
&ifc->ifc_nand.nand_fir0);
iowrite32be(0x0, &ifc->ifc_nand.nand_fir1);
iowrite32be((NAND_CMD_READ0 << IFC_NAND_FCR0_CMD0_SHIFT) |
(NAND_CMD_READSTART << IFC_NAND_FCR0_CMD1_SHIFT),
&ifc->ifc_nand.nand_fcr0);
} else {
iowrite32be((IFC_FIR_OP_CW0 << IFC_NAND_FIR0_OP0_SHIFT) |
(IFC_FIR_OP_CA0 << IFC_NAND_FIR0_OP1_SHIFT) |
(IFC_FIR_OP_RA0 << IFC_NAND_FIR0_OP2_SHIFT) |
(IFC_FIR_OP_RBCD << IFC_NAND_FIR0_OP3_SHIFT),
&ifc->ifc_nand.nand_fir0);
iowrite32be(0x0, &ifc->ifc_nand.nand_fir1);
if (oob)
iowrite32be(NAND_CMD_READOOB <<
IFC_NAND_FCR0_CMD0_SHIFT,
&ifc->ifc_nand.nand_fcr0);
else
iowrite32be(NAND_CMD_READ0 <<
IFC_NAND_FCR0_CMD0_SHIFT,
&ifc->ifc_nand.nand_fcr0);
}
}
static void fsl_ifc_cmdfunc(struct mtd_info *mtd, unsigned int command,
int column, int page_addr) {
struct nand_chip *chip = mtd->priv;
struct fsl_ifc_mtd *priv = chip->priv;
struct fsl_ifc_ctrl *ctrl = priv->ctrl;
struct fsl_ifc_regs __iomem *ifc = ctrl->regs;
ifc_nand_ctrl->read_bytes = 0;
if (command != NAND_CMD_PAGEPROG)
ifc_nand_ctrl->index = 0;
switch (command) {
case NAND_CMD_READ0:
iowrite32be(0, &ifc->ifc_nand.nand_fbcr);
set_addr(mtd, 0, page_addr, 0);
ifc_nand_ctrl->read_bytes = mtd->writesize + mtd->oobsize;
ifc_nand_ctrl->index += column;
if (chip->ecc.mode == NAND_ECC_HW)
ifc_nand_ctrl->eccread = 1;
fsl_ifc_do_read(chip, 0, mtd);
fsl_ifc_run_command(mtd);
return;
case NAND_CMD_READOOB:
iowrite32be(mtd->oobsize - column, &ifc->ifc_nand.nand_fbcr);
set_addr(mtd, column, page_addr, 1);
ifc_nand_ctrl->read_bytes = mtd->writesize + mtd->oobsize;
fsl_ifc_do_read(chip, 1, mtd);
fsl_ifc_run_command(mtd);
return;
case NAND_CMD_READID:
case NAND_CMD_PARAM: {
int timing = IFC_FIR_OP_RB;
if (command == NAND_CMD_PARAM)
timing = IFC_FIR_OP_RBCD;
iowrite32be((IFC_FIR_OP_CW0 << IFC_NAND_FIR0_OP0_SHIFT) |
(IFC_FIR_OP_UA << IFC_NAND_FIR0_OP1_SHIFT) |
(timing << IFC_NAND_FIR0_OP2_SHIFT),
&ifc->ifc_nand.nand_fir0);
iowrite32be(command << IFC_NAND_FCR0_CMD0_SHIFT,
&ifc->ifc_nand.nand_fcr0);
iowrite32be(column, &ifc->ifc_nand.row3);
iowrite32be(256, &ifc->ifc_nand.nand_fbcr);
ifc_nand_ctrl->read_bytes = 256;
set_addr(mtd, 0, 0, 0);
fsl_ifc_run_command(mtd);
return;
}
case NAND_CMD_ERASE1:
set_addr(mtd, 0, page_addr, 0);
return;
case NAND_CMD_ERASE2:
iowrite32be((IFC_FIR_OP_CW0 << IFC_NAND_FIR0_OP0_SHIFT) |
(IFC_FIR_OP_RA0 << IFC_NAND_FIR0_OP1_SHIFT) |
(IFC_FIR_OP_CMD1 << IFC_NAND_FIR0_OP2_SHIFT),
&ifc->ifc_nand.nand_fir0);
iowrite32be((NAND_CMD_ERASE1 << IFC_NAND_FCR0_CMD0_SHIFT) |
(NAND_CMD_ERASE2 << IFC_NAND_FCR0_CMD1_SHIFT),
&ifc->ifc_nand.nand_fcr0);
iowrite32be(0, &ifc->ifc_nand.nand_fbcr);
ifc_nand_ctrl->read_bytes = 0;
fsl_ifc_run_command(mtd);
return;
case NAND_CMD_SEQIN: {
u32 nand_fcr0;
ifc_nand_ctrl->column = column;
ifc_nand_ctrl->oob = 0;
if (mtd->writesize > 512) {
nand_fcr0 =
(NAND_CMD_SEQIN << IFC_NAND_FCR0_CMD0_SHIFT) |
(NAND_CMD_PAGEPROG << IFC_NAND_FCR0_CMD1_SHIFT);
iowrite32be(
(IFC_FIR_OP_CW0 << IFC_NAND_FIR0_OP0_SHIFT) |
(IFC_FIR_OP_CA0 << IFC_NAND_FIR0_OP1_SHIFT) |
(IFC_FIR_OP_RA0 << IFC_NAND_FIR0_OP2_SHIFT) |
(IFC_FIR_OP_WBCD << IFC_NAND_FIR0_OP3_SHIFT) |
(IFC_FIR_OP_CW1 << IFC_NAND_FIR0_OP4_SHIFT),
&ifc->ifc_nand.nand_fir0);
} else {
nand_fcr0 = ((NAND_CMD_PAGEPROG <<
IFC_NAND_FCR0_CMD1_SHIFT) |
(NAND_CMD_SEQIN <<
IFC_NAND_FCR0_CMD2_SHIFT));
iowrite32be(
(IFC_FIR_OP_CW0 << IFC_NAND_FIR0_OP0_SHIFT) |
(IFC_FIR_OP_CMD2 << IFC_NAND_FIR0_OP1_SHIFT) |
(IFC_FIR_OP_CA0 << IFC_NAND_FIR0_OP2_SHIFT) |
(IFC_FIR_OP_RA0 << IFC_NAND_FIR0_OP3_SHIFT) |
(IFC_FIR_OP_WBCD << IFC_NAND_FIR0_OP4_SHIFT),
&ifc->ifc_nand.nand_fir0);
iowrite32be(IFC_FIR_OP_CW1 << IFC_NAND_FIR1_OP5_SHIFT,
&ifc->ifc_nand.nand_fir1);
if (column >= mtd->writesize)
nand_fcr0 |=
NAND_CMD_READOOB << IFC_NAND_FCR0_CMD0_SHIFT;
else
nand_fcr0 |=
NAND_CMD_READ0 << IFC_NAND_FCR0_CMD0_SHIFT;
}
if (column >= mtd->writesize) {
column -= mtd->writesize;
ifc_nand_ctrl->oob = 1;
}
iowrite32be(nand_fcr0, &ifc->ifc_nand.nand_fcr0);
set_addr(mtd, column, page_addr, ifc_nand_ctrl->oob);
return;
}
case NAND_CMD_PAGEPROG: {
if (ifc_nand_ctrl->oob) {
iowrite32be(ifc_nand_ctrl->index -
ifc_nand_ctrl->column,
&ifc->ifc_nand.nand_fbcr);
} else {
iowrite32be(0, &ifc->ifc_nand.nand_fbcr);
}
fsl_ifc_run_command(mtd);
return;
}
case NAND_CMD_STATUS:
iowrite32be((IFC_FIR_OP_CW0 << IFC_NAND_FIR0_OP0_SHIFT) |
(IFC_FIR_OP_RB << IFC_NAND_FIR0_OP1_SHIFT),
&ifc->ifc_nand.nand_fir0);
iowrite32be(NAND_CMD_STATUS << IFC_NAND_FCR0_CMD0_SHIFT,
&ifc->ifc_nand.nand_fcr0);
iowrite32be(1, &ifc->ifc_nand.nand_fbcr);
set_addr(mtd, 0, 0, 0);
ifc_nand_ctrl->read_bytes = 1;
fsl_ifc_run_command(mtd);
setbits8(ifc_nand_ctrl->addr, NAND_STATUS_WP);
return;
case NAND_CMD_RESET:
iowrite32be(IFC_FIR_OP_CW0 << IFC_NAND_FIR0_OP0_SHIFT,
&ifc->ifc_nand.nand_fir0);
iowrite32be(NAND_CMD_RESET << IFC_NAND_FCR0_CMD0_SHIFT,
&ifc->ifc_nand.nand_fcr0);
fsl_ifc_run_command(mtd);
return;
default:
dev_err(priv->dev, "%s: error, unsupported command 0x%x.\n",
__func__, command);
}
}
static void fsl_ifc_select_chip(struct mtd_info *mtd, int chip)
{
}
static void fsl_ifc_write_buf(struct mtd_info *mtd, const u8 *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct fsl_ifc_mtd *priv = chip->priv;
unsigned int bufsize = mtd->writesize + mtd->oobsize;
if (len <= 0) {
dev_err(priv->dev, "%s: len %d bytes", __func__, len);
return;
}
if ((unsigned int)len > bufsize - ifc_nand_ctrl->index) {
dev_err(priv->dev,
"%s: beyond end of buffer (%d requested, %u available)\n",
__func__, len, bufsize - ifc_nand_ctrl->index);
len = bufsize - ifc_nand_ctrl->index;
}
memcpy_toio(&ifc_nand_ctrl->addr[ifc_nand_ctrl->index], buf, len);
ifc_nand_ctrl->index += len;
}
static uint8_t fsl_ifc_read_byte(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct fsl_ifc_mtd *priv = chip->priv;
if (ifc_nand_ctrl->index < ifc_nand_ctrl->read_bytes)
return in_8(&ifc_nand_ctrl->addr[ifc_nand_ctrl->index++]);
dev_err(priv->dev, "%s: beyond end of buffer\n", __func__);
return ERR_BYTE;
}
static uint8_t fsl_ifc_read_byte16(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct fsl_ifc_mtd *priv = chip->priv;
uint16_t data;
if (ifc_nand_ctrl->index < ifc_nand_ctrl->read_bytes) {
data = in_be16((uint16_t __iomem *)&ifc_nand_ctrl->
addr[ifc_nand_ctrl->index]);
ifc_nand_ctrl->index += 2;
return (uint8_t) data;
}
dev_err(priv->dev, "%s: beyond end of buffer\n", __func__);
return ERR_BYTE;
}
static void fsl_ifc_read_buf(struct mtd_info *mtd, u8 *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct fsl_ifc_mtd *priv = chip->priv;
int avail;
if (len < 0) {
dev_err(priv->dev, "%s: len %d bytes", __func__, len);
return;
}
avail = min((unsigned int)len,
ifc_nand_ctrl->read_bytes - ifc_nand_ctrl->index);
memcpy_fromio(buf, &ifc_nand_ctrl->addr[ifc_nand_ctrl->index], avail);
ifc_nand_ctrl->index += avail;
if (len > avail)
dev_err(priv->dev,
"%s: beyond end of buffer (%d requested, %d available)\n",
__func__, len, avail);
}
static int fsl_ifc_wait(struct mtd_info *mtd, struct nand_chip *chip)
{
struct fsl_ifc_mtd *priv = chip->priv;
struct fsl_ifc_ctrl *ctrl = priv->ctrl;
struct fsl_ifc_regs __iomem *ifc = ctrl->regs;
u32 nand_fsr;
iowrite32be((IFC_FIR_OP_CW0 << IFC_NAND_FIR0_OP0_SHIFT) |
(IFC_FIR_OP_RDSTAT << IFC_NAND_FIR0_OP1_SHIFT),
&ifc->ifc_nand.nand_fir0);
iowrite32be(NAND_CMD_STATUS << IFC_NAND_FCR0_CMD0_SHIFT,
&ifc->ifc_nand.nand_fcr0);
iowrite32be(1, &ifc->ifc_nand.nand_fbcr);
set_addr(mtd, 0, 0, 0);
ifc_nand_ctrl->read_bytes = 1;
fsl_ifc_run_command(mtd);
nand_fsr = ioread32be(&ifc->ifc_nand.nand_fsr);
return nand_fsr | NAND_STATUS_WP;
}
static int fsl_ifc_read_page(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
struct fsl_ifc_mtd *priv = chip->priv;
struct fsl_ifc_ctrl *ctrl = priv->ctrl;
struct fsl_ifc_nand_ctrl *nctrl = ifc_nand_ctrl;
fsl_ifc_read_buf(mtd, buf, mtd->writesize);
if (oob_required)
fsl_ifc_read_buf(mtd, chip->oob_poi, mtd->oobsize);
if (ctrl->nand_stat & IFC_NAND_EVTER_STAT_ECCER)
dev_err(priv->dev, "NAND Flash ECC Uncorrectable Error\n");
if (ctrl->nand_stat != IFC_NAND_EVTER_STAT_OPC)
mtd->ecc_stats.failed++;
return nctrl->max_bitflips;
}
static int fsl_ifc_write_page(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required)
{
fsl_ifc_write_buf(mtd, buf, mtd->writesize);
fsl_ifc_write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int fsl_ifc_chip_init_tail(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct fsl_ifc_mtd *priv = chip->priv;
dev_dbg(priv->dev, "%s: nand->numchips = %d\n", __func__,
chip->numchips);
dev_dbg(priv->dev, "%s: nand->chipsize = %lld\n", __func__,
chip->chipsize);
dev_dbg(priv->dev, "%s: nand->pagemask = %8x\n", __func__,
chip->pagemask);
dev_dbg(priv->dev, "%s: nand->chip_delay = %d\n", __func__,
chip->chip_delay);
dev_dbg(priv->dev, "%s: nand->badblockpos = %d\n", __func__,
chip->badblockpos);
dev_dbg(priv->dev, "%s: nand->chip_shift = %d\n", __func__,
chip->chip_shift);
dev_dbg(priv->dev, "%s: nand->page_shift = %d\n", __func__,
chip->page_shift);
dev_dbg(priv->dev, "%s: nand->phys_erase_shift = %d\n", __func__,
chip->phys_erase_shift);
dev_dbg(priv->dev, "%s: nand->ecclayout = %p\n", __func__,
chip->ecclayout);
dev_dbg(priv->dev, "%s: nand->ecc.mode = %d\n", __func__,
chip->ecc.mode);
dev_dbg(priv->dev, "%s: nand->ecc.steps = %d\n", __func__,
chip->ecc.steps);
dev_dbg(priv->dev, "%s: nand->ecc.bytes = %d\n", __func__,
chip->ecc.bytes);
dev_dbg(priv->dev, "%s: nand->ecc.total = %d\n", __func__,
chip->ecc.total);
dev_dbg(priv->dev, "%s: nand->ecc.layout = %p\n", __func__,
chip->ecc.layout);
dev_dbg(priv->dev, "%s: mtd->flags = %08x\n", __func__, mtd->flags);
dev_dbg(priv->dev, "%s: mtd->size = %lld\n", __func__, mtd->size);
dev_dbg(priv->dev, "%s: mtd->erasesize = %d\n", __func__,
mtd->erasesize);
dev_dbg(priv->dev, "%s: mtd->writesize = %d\n", __func__,
mtd->writesize);
dev_dbg(priv->dev, "%s: mtd->oobsize = %d\n", __func__,
mtd->oobsize);
return 0;
}
static void fsl_ifc_sram_init(struct fsl_ifc_mtd *priv)
{
struct fsl_ifc_ctrl *ctrl = priv->ctrl;
struct fsl_ifc_regs __iomem *ifc = ctrl->regs;
uint32_t csor = 0, csor_8k = 0, csor_ext = 0;
uint32_t cs = priv->bank;
csor = ioread32be(&ifc->csor_cs[cs].csor);
csor_ext = ioread32be(&ifc->csor_cs[cs].csor_ext);
csor_8k = (csor & ~(CSOR_NAND_PGS_MASK)) | 0x0018C000;
iowrite32be(csor_8k, &ifc->csor_cs[cs].csor);
iowrite32be(0x0000400, &ifc->csor_cs[cs].csor_ext);
iowrite32be((IFC_FIR_OP_CW0 << IFC_NAND_FIR0_OP0_SHIFT) |
(IFC_FIR_OP_UA << IFC_NAND_FIR0_OP1_SHIFT) |
(IFC_FIR_OP_RB << IFC_NAND_FIR0_OP2_SHIFT),
&ifc->ifc_nand.nand_fir0);
iowrite32be(NAND_CMD_READID << IFC_NAND_FCR0_CMD0_SHIFT,
&ifc->ifc_nand.nand_fcr0);
iowrite32be(0x0, &ifc->ifc_nand.row3);
iowrite32be(0x0, &ifc->ifc_nand.nand_fbcr);
iowrite32be(0x0, &ifc->ifc_nand.row0);
iowrite32be(0x0, &ifc->ifc_nand.col0);
iowrite32be(cs << IFC_NAND_CSEL_SHIFT, &ifc->ifc_nand.nand_csel);
iowrite32be(IFC_NAND_SEQ_STRT_FIR_STRT, &ifc->ifc_nand.nandseq_strt);
wait_event_timeout(ctrl->nand_wait, ctrl->nand_stat,
IFC_TIMEOUT_MSECS * HZ/1000);
if (ctrl->nand_stat != IFC_NAND_EVTER_STAT_OPC)
printk(KERN_ERR "fsl-ifc: Failed to Initialise SRAM\n");
iowrite32be(csor, &ifc->csor_cs[cs].csor);
iowrite32be(csor_ext, &ifc->csor_cs[cs].csor_ext);
}
static int fsl_ifc_chip_init(struct fsl_ifc_mtd *priv)
{
struct fsl_ifc_ctrl *ctrl = priv->ctrl;
struct fsl_ifc_regs __iomem *ifc = ctrl->regs;
struct nand_chip *chip = &priv->chip;
struct nand_ecclayout *layout;
u32 csor, ver;
priv->mtd.priv = chip;
priv->mtd.owner = THIS_MODULE;
if ((ioread32be(&ifc->cspr_cs[priv->bank].cspr)) & CSPR_PORT_SIZE_16)
chip->read_byte = fsl_ifc_read_byte16;
else
chip->read_byte = fsl_ifc_read_byte;
chip->write_buf = fsl_ifc_write_buf;
chip->read_buf = fsl_ifc_read_buf;
chip->select_chip = fsl_ifc_select_chip;
chip->cmdfunc = fsl_ifc_cmdfunc;
chip->waitfunc = fsl_ifc_wait;
chip->bbt_td = &bbt_main_descr;
chip->bbt_md = &bbt_mirror_descr;
iowrite32be(0x0, &ifc->ifc_nand.ncfgr);
chip->bbt_options = NAND_BBT_USE_FLASH;
if (ioread32be(&ifc->cspr_cs[priv->bank].cspr) & CSPR_PORT_SIZE_16) {
chip->read_byte = fsl_ifc_read_byte16;
chip->options |= NAND_BUSWIDTH_16;
} else {
chip->read_byte = fsl_ifc_read_byte;
}
chip->controller = &ifc_nand_ctrl->controller;
chip->priv = priv;
chip->ecc.read_page = fsl_ifc_read_page;
chip->ecc.write_page = fsl_ifc_write_page;
csor = ioread32be(&ifc->csor_cs[priv->bank].csor);
chip->ecc.size = 512;
chip->ecc.bytes = 8;
chip->ecc.strength = 4;
switch (csor & CSOR_NAND_PGS_MASK) {
case CSOR_NAND_PGS_512:
if (chip->options & NAND_BUSWIDTH_16) {
layout = &oob_512_16bit_ecc4;
} else {
layout = &oob_512_8bit_ecc4;
bbt_main_descr.offs = 0;
bbt_mirror_descr.offs = 0;
}
priv->bufnum_mask = 15;
break;
case CSOR_NAND_PGS_2K:
layout = &oob_2048_ecc4;
priv->bufnum_mask = 3;
break;
case CSOR_NAND_PGS_4K:
if ((csor & CSOR_NAND_ECC_MODE_MASK) ==
CSOR_NAND_ECC_MODE_4) {
layout = &oob_4096_ecc4;
} else {
layout = &oob_4096_ecc8;
chip->ecc.bytes = 16;
}
priv->bufnum_mask = 1;
break;
default:
dev_err(priv->dev, "bad csor %#x: bad page size\n", csor);
return -ENODEV;
}
if (csor & CSOR_NAND_ECC_DEC_EN) {
chip->ecc.mode = NAND_ECC_HW;
chip->ecc.layout = layout;
} else {
chip->ecc.mode = NAND_ECC_SOFT;
}
ver = ioread32be(&ifc->ifc_rev);
if (ver == FSL_IFC_V1_1_0)
fsl_ifc_sram_init(priv);
return 0;
}
static int fsl_ifc_chip_remove(struct fsl_ifc_mtd *priv)
{
nand_release(&priv->mtd);
kfree(priv->mtd.name);
if (priv->vbase)
iounmap(priv->vbase);
ifc_nand_ctrl->chips[priv->bank] = NULL;
dev_set_drvdata(priv->dev, NULL);
kfree(priv);
return 0;
}
static int match_bank(struct fsl_ifc_regs __iomem *ifc, int bank,
phys_addr_t addr)
{
u32 cspr = ioread32be(&ifc->cspr_cs[bank].cspr);
if (!(cspr & CSPR_V))
return 0;
if ((cspr & CSPR_MSEL) != CSPR_MSEL_NAND)
return 0;
return (cspr & CSPR_BA) == convert_ifc_address(addr);
}
static int fsl_ifc_nand_probe(struct platform_device *dev)
{
struct fsl_ifc_regs __iomem *ifc;
struct fsl_ifc_mtd *priv;
struct resource res;
static const char *part_probe_types[]
= { "cmdlinepart", "RedBoot", "ofpart", NULL };
int ret;
int bank;
struct device_node *node = dev->dev.of_node;
struct mtd_part_parser_data ppdata;
ppdata.of_node = dev->dev.of_node;
if (!fsl_ifc_ctrl_dev || !fsl_ifc_ctrl_dev->regs)
return -ENODEV;
ifc = fsl_ifc_ctrl_dev->regs;
ret = of_address_to_resource(node, 0, &res);
if (ret) {
dev_err(&dev->dev, "%s: failed to get resource\n", __func__);
return ret;
}
for (bank = 0; bank < FSL_IFC_BANK_COUNT; bank++) {
if (match_bank(ifc, bank, res.start))
break;
}
if (bank >= FSL_IFC_BANK_COUNT) {
dev_err(&dev->dev, "%s: address did not match any chip selects\n",
__func__);
return -ENODEV;
}
priv = devm_kzalloc(&dev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
mutex_lock(&fsl_ifc_nand_mutex);
if (!fsl_ifc_ctrl_dev->nand) {
ifc_nand_ctrl = kzalloc(sizeof(*ifc_nand_ctrl), GFP_KERNEL);
if (!ifc_nand_ctrl) {
dev_err(&dev->dev, "failed to allocate memory\n");
mutex_unlock(&fsl_ifc_nand_mutex);
return -ENOMEM;
}
ifc_nand_ctrl->read_bytes = 0;
ifc_nand_ctrl->index = 0;
ifc_nand_ctrl->addr = NULL;
fsl_ifc_ctrl_dev->nand = ifc_nand_ctrl;
spin_lock_init(&ifc_nand_ctrl->controller.lock);
init_waitqueue_head(&ifc_nand_ctrl->controller.wq);
} else {
ifc_nand_ctrl = fsl_ifc_ctrl_dev->nand;
}
mutex_unlock(&fsl_ifc_nand_mutex);
ifc_nand_ctrl->chips[bank] = priv;
priv->bank = bank;
priv->ctrl = fsl_ifc_ctrl_dev;
priv->dev = &dev->dev;
priv->vbase = ioremap(res.start, resource_size(&res));
if (!priv->vbase) {
dev_err(priv->dev, "%s: failed to map chip region\n", __func__);
ret = -ENOMEM;
goto err;
}
dev_set_drvdata(priv->dev, priv);
iowrite32be(IFC_NAND_EVTER_EN_OPC_EN |
IFC_NAND_EVTER_EN_FTOER_EN |
IFC_NAND_EVTER_EN_WPER_EN,
&ifc->ifc_nand.nand_evter_en);
iowrite32be(IFC_NAND_EVTER_INTR_OPCIR_EN |
IFC_NAND_EVTER_INTR_FTOERIR_EN |
IFC_NAND_EVTER_INTR_WPERIR_EN,
&ifc->ifc_nand.nand_evter_intr_en);
priv->mtd.name = kasprintf(GFP_KERNEL, "%x.flash", (unsigned)res.start);
if (!priv->mtd.name) {
ret = -ENOMEM;
goto err;
}
ret = fsl_ifc_chip_init(priv);
if (ret)
goto err;
ret = nand_scan_ident(&priv->mtd, 1, NULL);
if (ret)
goto err;
ret = fsl_ifc_chip_init_tail(&priv->mtd);
if (ret)
goto err;
ret = nand_scan_tail(&priv->mtd);
if (ret)
goto err;
mtd_device_parse_register(&priv->mtd, part_probe_types, &ppdata,
NULL, 0);
dev_info(priv->dev, "IFC NAND device at 0x%llx, bank %d\n",
(unsigned long long)res.start, priv->bank);
return 0;
err:
fsl_ifc_chip_remove(priv);
return ret;
}
static int fsl_ifc_nand_remove(struct platform_device *dev)
{
struct fsl_ifc_mtd *priv = dev_get_drvdata(&dev->dev);
fsl_ifc_chip_remove(priv);
mutex_lock(&fsl_ifc_nand_mutex);
ifc_nand_ctrl->counter--;
if (!ifc_nand_ctrl->counter) {
fsl_ifc_ctrl_dev->nand = NULL;
kfree(ifc_nand_ctrl);
}
mutex_unlock(&fsl_ifc_nand_mutex);
return 0;
}
static int __init fsl_ifc_nand_init(void)
{
int ret;
ret = platform_driver_register(&fsl_ifc_nand_driver);
if (ret)
printk(KERN_ERR "fsl-ifc: Failed to register platform"
"driver\n");
return ret;
}
static void __exit fsl_ifc_nand_exit(void)
{
platform_driver_unregister(&fsl_ifc_nand_driver);
}
