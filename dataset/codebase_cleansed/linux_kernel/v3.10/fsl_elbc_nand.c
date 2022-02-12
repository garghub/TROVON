static void set_addr(struct mtd_info *mtd, int column, int page_addr, int oob)
{
struct nand_chip *chip = mtd->priv;
struct fsl_elbc_mtd *priv = chip->priv;
struct fsl_lbc_ctrl *ctrl = priv->ctrl;
struct fsl_lbc_regs __iomem *lbc = ctrl->regs;
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl = ctrl->nand;
int buf_num;
elbc_fcm_ctrl->page = page_addr;
if (priv->page_size) {
out_be32(&lbc->fbar, page_addr >> 6);
out_be32(&lbc->fpar,
((page_addr << FPAR_LP_PI_SHIFT) & FPAR_LP_PI) |
(oob ? FPAR_LP_MS : 0) | column);
buf_num = (page_addr & 1) << 2;
} else {
out_be32(&lbc->fbar, page_addr >> 5);
out_be32(&lbc->fpar,
((page_addr << FPAR_SP_PI_SHIFT) & FPAR_SP_PI) |
(oob ? FPAR_SP_MS : 0) | column);
buf_num = page_addr & 7;
}
elbc_fcm_ctrl->addr = priv->vbase + buf_num * 1024;
elbc_fcm_ctrl->index = column;
if (oob)
elbc_fcm_ctrl->index += priv->page_size ? 2048 : 512;
dev_vdbg(priv->dev, "set_addr: bank=%d, "
"elbc_fcm_ctrl->addr=0x%p (0x%p), "
"index %x, pes %d ps %d\n",
buf_num, elbc_fcm_ctrl->addr, priv->vbase,
elbc_fcm_ctrl->index,
chip->phys_erase_shift, chip->page_shift);
}
static int fsl_elbc_run_command(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct fsl_elbc_mtd *priv = chip->priv;
struct fsl_lbc_ctrl *ctrl = priv->ctrl;
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl = ctrl->nand;
struct fsl_lbc_regs __iomem *lbc = ctrl->regs;
out_be32(&lbc->fmr, priv->fmr | 3);
if (elbc_fcm_ctrl->use_mdr)
out_be32(&lbc->mdr, elbc_fcm_ctrl->mdr);
dev_vdbg(priv->dev,
"fsl_elbc_run_command: fmr=%08x fir=%08x fcr=%08x\n",
in_be32(&lbc->fmr), in_be32(&lbc->fir), in_be32(&lbc->fcr));
dev_vdbg(priv->dev,
"fsl_elbc_run_command: fbar=%08x fpar=%08x "
"fbcr=%08x bank=%d\n",
in_be32(&lbc->fbar), in_be32(&lbc->fpar),
in_be32(&lbc->fbcr), priv->bank);
ctrl->irq_status = 0;
out_be32(&lbc->lsor, priv->bank);
wait_event_timeout(ctrl->irq_wait, ctrl->irq_status,
FCM_TIMEOUT_MSECS * HZ/1000);
elbc_fcm_ctrl->status = ctrl->irq_status;
if (elbc_fcm_ctrl->use_mdr)
elbc_fcm_ctrl->mdr = in_be32(&lbc->mdr);
elbc_fcm_ctrl->use_mdr = 0;
if (elbc_fcm_ctrl->status != LTESR_CC) {
dev_info(priv->dev,
"command failed: fir %x fcr %x status %x mdr %x\n",
in_be32(&lbc->fir), in_be32(&lbc->fcr),
elbc_fcm_ctrl->status, elbc_fcm_ctrl->mdr);
return -EIO;
}
if (chip->ecc.mode != NAND_ECC_HW)
return 0;
elbc_fcm_ctrl->max_bitflips = 0;
if (elbc_fcm_ctrl->read_bytes == mtd->writesize + mtd->oobsize) {
uint32_t lteccr = in_be32(&lbc->lteccr);
if (lteccr & 0x000F000F)
out_be32(&lbc->lteccr, 0x000F000F);
if (lteccr & 0x000F0000) {
mtd->ecc_stats.corrected++;
elbc_fcm_ctrl->max_bitflips = 1;
}
}
return 0;
}
static void fsl_elbc_do_read(struct nand_chip *chip, int oob)
{
struct fsl_elbc_mtd *priv = chip->priv;
struct fsl_lbc_ctrl *ctrl = priv->ctrl;
struct fsl_lbc_regs __iomem *lbc = ctrl->regs;
if (priv->page_size) {
out_be32(&lbc->fir,
(FIR_OP_CM0 << FIR_OP0_SHIFT) |
(FIR_OP_CA << FIR_OP1_SHIFT) |
(FIR_OP_PA << FIR_OP2_SHIFT) |
(FIR_OP_CM1 << FIR_OP3_SHIFT) |
(FIR_OP_RBW << FIR_OP4_SHIFT));
out_be32(&lbc->fcr, (NAND_CMD_READ0 << FCR_CMD0_SHIFT) |
(NAND_CMD_READSTART << FCR_CMD1_SHIFT));
} else {
out_be32(&lbc->fir,
(FIR_OP_CM0 << FIR_OP0_SHIFT) |
(FIR_OP_CA << FIR_OP1_SHIFT) |
(FIR_OP_PA << FIR_OP2_SHIFT) |
(FIR_OP_RBW << FIR_OP3_SHIFT));
if (oob)
out_be32(&lbc->fcr, NAND_CMD_READOOB << FCR_CMD0_SHIFT);
else
out_be32(&lbc->fcr, NAND_CMD_READ0 << FCR_CMD0_SHIFT);
}
}
static void fsl_elbc_cmdfunc(struct mtd_info *mtd, unsigned int command,
int column, int page_addr)
{
struct nand_chip *chip = mtd->priv;
struct fsl_elbc_mtd *priv = chip->priv;
struct fsl_lbc_ctrl *ctrl = priv->ctrl;
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl = ctrl->nand;
struct fsl_lbc_regs __iomem *lbc = ctrl->regs;
elbc_fcm_ctrl->use_mdr = 0;
elbc_fcm_ctrl->read_bytes = 0;
if (command != NAND_CMD_PAGEPROG)
elbc_fcm_ctrl->index = 0;
switch (command) {
case NAND_CMD_READ1:
column += 256;
case NAND_CMD_READ0:
dev_dbg(priv->dev,
"fsl_elbc_cmdfunc: NAND_CMD_READ0, page_addr:"
" 0x%x, column: 0x%x.\n", page_addr, column);
out_be32(&lbc->fbcr, 0);
set_addr(mtd, 0, page_addr, 0);
elbc_fcm_ctrl->read_bytes = mtd->writesize + mtd->oobsize;
elbc_fcm_ctrl->index += column;
fsl_elbc_do_read(chip, 0);
fsl_elbc_run_command(mtd);
return;
case NAND_CMD_READOOB:
dev_vdbg(priv->dev,
"fsl_elbc_cmdfunc: NAND_CMD_READOOB, page_addr:"
" 0x%x, column: 0x%x.\n", page_addr, column);
out_be32(&lbc->fbcr, mtd->oobsize - column);
set_addr(mtd, column, page_addr, 1);
elbc_fcm_ctrl->read_bytes = mtd->writesize + mtd->oobsize;
fsl_elbc_do_read(chip, 1);
fsl_elbc_run_command(mtd);
return;
case NAND_CMD_READID:
case NAND_CMD_PARAM:
dev_vdbg(priv->dev, "fsl_elbc_cmdfunc: NAND_CMD %x\n", command);
out_be32(&lbc->fir, (FIR_OP_CM0 << FIR_OP0_SHIFT) |
(FIR_OP_UA << FIR_OP1_SHIFT) |
(FIR_OP_RBW << FIR_OP2_SHIFT));
out_be32(&lbc->fcr, command << FCR_CMD0_SHIFT);
out_be32(&lbc->fbcr, 256);
elbc_fcm_ctrl->read_bytes = 256;
elbc_fcm_ctrl->use_mdr = 1;
elbc_fcm_ctrl->mdr = column;
set_addr(mtd, 0, 0, 0);
fsl_elbc_run_command(mtd);
return;
case NAND_CMD_ERASE1:
dev_vdbg(priv->dev,
"fsl_elbc_cmdfunc: NAND_CMD_ERASE1, "
"page_addr: 0x%x.\n", page_addr);
set_addr(mtd, 0, page_addr, 0);
return;
case NAND_CMD_ERASE2:
dev_vdbg(priv->dev, "fsl_elbc_cmdfunc: NAND_CMD_ERASE2.\n");
out_be32(&lbc->fir,
(FIR_OP_CM0 << FIR_OP0_SHIFT) |
(FIR_OP_PA << FIR_OP1_SHIFT) |
(FIR_OP_CM2 << FIR_OP2_SHIFT) |
(FIR_OP_CW1 << FIR_OP3_SHIFT) |
(FIR_OP_RS << FIR_OP4_SHIFT));
out_be32(&lbc->fcr,
(NAND_CMD_ERASE1 << FCR_CMD0_SHIFT) |
(NAND_CMD_STATUS << FCR_CMD1_SHIFT) |
(NAND_CMD_ERASE2 << FCR_CMD2_SHIFT));
out_be32(&lbc->fbcr, 0);
elbc_fcm_ctrl->read_bytes = 0;
elbc_fcm_ctrl->use_mdr = 1;
fsl_elbc_run_command(mtd);
return;
case NAND_CMD_SEQIN: {
__be32 fcr;
dev_vdbg(priv->dev,
"fsl_elbc_cmdfunc: NAND_CMD_SEQIN/PAGE_PROG, "
"page_addr: 0x%x, column: 0x%x.\n",
page_addr, column);
elbc_fcm_ctrl->column = column;
elbc_fcm_ctrl->use_mdr = 1;
if (column >= mtd->writesize) {
column -= mtd->writesize;
elbc_fcm_ctrl->oob = 1;
} else {
WARN_ON(column != 0);
elbc_fcm_ctrl->oob = 0;
}
fcr = (NAND_CMD_STATUS << FCR_CMD1_SHIFT) |
(NAND_CMD_SEQIN << FCR_CMD2_SHIFT) |
(NAND_CMD_PAGEPROG << FCR_CMD3_SHIFT);
if (priv->page_size) {
out_be32(&lbc->fir,
(FIR_OP_CM2 << FIR_OP0_SHIFT) |
(FIR_OP_CA << FIR_OP1_SHIFT) |
(FIR_OP_PA << FIR_OP2_SHIFT) |
(FIR_OP_WB << FIR_OP3_SHIFT) |
(FIR_OP_CM3 << FIR_OP4_SHIFT) |
(FIR_OP_CW1 << FIR_OP5_SHIFT) |
(FIR_OP_RS << FIR_OP6_SHIFT));
} else {
out_be32(&lbc->fir,
(FIR_OP_CM0 << FIR_OP0_SHIFT) |
(FIR_OP_CM2 << FIR_OP1_SHIFT) |
(FIR_OP_CA << FIR_OP2_SHIFT) |
(FIR_OP_PA << FIR_OP3_SHIFT) |
(FIR_OP_WB << FIR_OP4_SHIFT) |
(FIR_OP_CM3 << FIR_OP5_SHIFT) |
(FIR_OP_CW1 << FIR_OP6_SHIFT) |
(FIR_OP_RS << FIR_OP7_SHIFT));
if (elbc_fcm_ctrl->oob)
fcr |= NAND_CMD_READOOB << FCR_CMD0_SHIFT;
else
fcr |= NAND_CMD_READ0 << FCR_CMD0_SHIFT;
}
out_be32(&lbc->fcr, fcr);
set_addr(mtd, column, page_addr, elbc_fcm_ctrl->oob);
return;
}
case NAND_CMD_PAGEPROG: {
dev_vdbg(priv->dev,
"fsl_elbc_cmdfunc: NAND_CMD_PAGEPROG "
"writing %d bytes.\n", elbc_fcm_ctrl->index);
if (elbc_fcm_ctrl->oob || elbc_fcm_ctrl->column != 0 ||
elbc_fcm_ctrl->index != mtd->writesize + mtd->oobsize)
out_be32(&lbc->fbcr,
elbc_fcm_ctrl->index - elbc_fcm_ctrl->column);
else
out_be32(&lbc->fbcr, 0);
fsl_elbc_run_command(mtd);
return;
}
case NAND_CMD_STATUS:
out_be32(&lbc->fir,
(FIR_OP_CM0 << FIR_OP0_SHIFT) |
(FIR_OP_RBW << FIR_OP1_SHIFT));
out_be32(&lbc->fcr, NAND_CMD_STATUS << FCR_CMD0_SHIFT);
out_be32(&lbc->fbcr, 1);
set_addr(mtd, 0, 0, 0);
elbc_fcm_ctrl->read_bytes = 1;
fsl_elbc_run_command(mtd);
setbits8(elbc_fcm_ctrl->addr, NAND_STATUS_WP);
return;
case NAND_CMD_RESET:
dev_dbg(priv->dev, "fsl_elbc_cmdfunc: NAND_CMD_RESET.\n");
out_be32(&lbc->fir, FIR_OP_CM0 << FIR_OP0_SHIFT);
out_be32(&lbc->fcr, NAND_CMD_RESET << FCR_CMD0_SHIFT);
fsl_elbc_run_command(mtd);
return;
default:
dev_err(priv->dev,
"fsl_elbc_cmdfunc: error, unsupported command 0x%x.\n",
command);
}
}
static void fsl_elbc_select_chip(struct mtd_info *mtd, int chip)
{
}
static void fsl_elbc_write_buf(struct mtd_info *mtd, const u8 *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct fsl_elbc_mtd *priv = chip->priv;
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl = priv->ctrl->nand;
unsigned int bufsize = mtd->writesize + mtd->oobsize;
if (len <= 0) {
dev_err(priv->dev, "write_buf of %d bytes", len);
elbc_fcm_ctrl->status = 0;
return;
}
if ((unsigned int)len > bufsize - elbc_fcm_ctrl->index) {
dev_err(priv->dev,
"write_buf beyond end of buffer "
"(%d requested, %u available)\n",
len, bufsize - elbc_fcm_ctrl->index);
len = bufsize - elbc_fcm_ctrl->index;
}
memcpy_toio(&elbc_fcm_ctrl->addr[elbc_fcm_ctrl->index], buf, len);
in_8(&elbc_fcm_ctrl->addr[elbc_fcm_ctrl->index] + len - 1);
elbc_fcm_ctrl->index += len;
}
static u8 fsl_elbc_read_byte(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct fsl_elbc_mtd *priv = chip->priv;
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl = priv->ctrl->nand;
if (elbc_fcm_ctrl->index < elbc_fcm_ctrl->read_bytes)
return in_8(&elbc_fcm_ctrl->addr[elbc_fcm_ctrl->index++]);
dev_err(priv->dev, "read_byte beyond end of buffer\n");
return ERR_BYTE;
}
static void fsl_elbc_read_buf(struct mtd_info *mtd, u8 *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct fsl_elbc_mtd *priv = chip->priv;
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl = priv->ctrl->nand;
int avail;
if (len < 0)
return;
avail = min((unsigned int)len,
elbc_fcm_ctrl->read_bytes - elbc_fcm_ctrl->index);
memcpy_fromio(buf, &elbc_fcm_ctrl->addr[elbc_fcm_ctrl->index], avail);
elbc_fcm_ctrl->index += avail;
if (len > avail)
dev_err(priv->dev,
"read_buf beyond end of buffer "
"(%d requested, %d available)\n",
len, avail);
}
static int fsl_elbc_wait(struct mtd_info *mtd, struct nand_chip *chip)
{
struct fsl_elbc_mtd *priv = chip->priv;
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl = priv->ctrl->nand;
if (elbc_fcm_ctrl->status != LTESR_CC)
return NAND_STATUS_FAIL;
return (elbc_fcm_ctrl->mdr & 0xff) | NAND_STATUS_WP;
}
static int fsl_elbc_chip_init_tail(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct fsl_elbc_mtd *priv = chip->priv;
struct fsl_lbc_ctrl *ctrl = priv->ctrl;
struct fsl_lbc_regs __iomem *lbc = ctrl->regs;
unsigned int al;
al = 0;
if (chip->pagemask & 0xffff0000)
al++;
if (chip->pagemask & 0xff000000)
al++;
priv->fmr |= al << FMR_AL_SHIFT;
dev_dbg(priv->dev, "fsl_elbc_init: nand->numchips = %d\n",
chip->numchips);
dev_dbg(priv->dev, "fsl_elbc_init: nand->chipsize = %lld\n",
chip->chipsize);
dev_dbg(priv->dev, "fsl_elbc_init: nand->pagemask = %8x\n",
chip->pagemask);
dev_dbg(priv->dev, "fsl_elbc_init: nand->chip_delay = %d\n",
chip->chip_delay);
dev_dbg(priv->dev, "fsl_elbc_init: nand->badblockpos = %d\n",
chip->badblockpos);
dev_dbg(priv->dev, "fsl_elbc_init: nand->chip_shift = %d\n",
chip->chip_shift);
dev_dbg(priv->dev, "fsl_elbc_init: nand->page_shift = %d\n",
chip->page_shift);
dev_dbg(priv->dev, "fsl_elbc_init: nand->phys_erase_shift = %d\n",
chip->phys_erase_shift);
dev_dbg(priv->dev, "fsl_elbc_init: nand->ecclayout = %p\n",
chip->ecclayout);
dev_dbg(priv->dev, "fsl_elbc_init: nand->ecc.mode = %d\n",
chip->ecc.mode);
dev_dbg(priv->dev, "fsl_elbc_init: nand->ecc.steps = %d\n",
chip->ecc.steps);
dev_dbg(priv->dev, "fsl_elbc_init: nand->ecc.bytes = %d\n",
chip->ecc.bytes);
dev_dbg(priv->dev, "fsl_elbc_init: nand->ecc.total = %d\n",
chip->ecc.total);
dev_dbg(priv->dev, "fsl_elbc_init: nand->ecc.layout = %p\n",
chip->ecc.layout);
dev_dbg(priv->dev, "fsl_elbc_init: mtd->flags = %08x\n", mtd->flags);
dev_dbg(priv->dev, "fsl_elbc_init: mtd->size = %lld\n", mtd->size);
dev_dbg(priv->dev, "fsl_elbc_init: mtd->erasesize = %d\n",
mtd->erasesize);
dev_dbg(priv->dev, "fsl_elbc_init: mtd->writesize = %d\n",
mtd->writesize);
dev_dbg(priv->dev, "fsl_elbc_init: mtd->oobsize = %d\n",
mtd->oobsize);
if (mtd->writesize == 512) {
priv->page_size = 0;
clrbits32(&lbc->bank[priv->bank].or, OR_FCM_PGS);
} else if (mtd->writesize == 2048) {
priv->page_size = 1;
setbits32(&lbc->bank[priv->bank].or, OR_FCM_PGS);
if ((in_be32(&lbc->bank[priv->bank].br) & BR_DECC) ==
BR_DECC_CHK_GEN) {
chip->ecc.size = 512;
chip->ecc.layout = (priv->fmr & FMR_ECCM) ?
&fsl_elbc_oob_lp_eccm1 :
&fsl_elbc_oob_lp_eccm0;
}
} else {
dev_err(priv->dev,
"fsl_elbc_init: page size %d is not supported\n",
mtd->writesize);
return -1;
}
return 0;
}
static int fsl_elbc_read_page(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
struct fsl_elbc_mtd *priv = chip->priv;
struct fsl_lbc_ctrl *ctrl = priv->ctrl;
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl = ctrl->nand;
fsl_elbc_read_buf(mtd, buf, mtd->writesize);
if (oob_required)
fsl_elbc_read_buf(mtd, chip->oob_poi, mtd->oobsize);
if (fsl_elbc_wait(mtd, chip) & NAND_STATUS_FAIL)
mtd->ecc_stats.failed++;
return elbc_fcm_ctrl->max_bitflips;
}
static int fsl_elbc_write_page(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required)
{
fsl_elbc_write_buf(mtd, buf, mtd->writesize);
fsl_elbc_write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int fsl_elbc_chip_init(struct fsl_elbc_mtd *priv)
{
struct fsl_lbc_ctrl *ctrl = priv->ctrl;
struct fsl_lbc_regs __iomem *lbc = ctrl->regs;
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl = ctrl->nand;
struct nand_chip *chip = &priv->chip;
dev_dbg(priv->dev, "eLBC Set Information for bank %d\n", priv->bank);
priv->mtd.priv = chip;
priv->mtd.owner = THIS_MODULE;
priv->fmr = 15 << FMR_CWTO_SHIFT;
if (in_be32(&lbc->bank[priv->bank].or) & OR_FCM_PGS)
priv->fmr |= FMR_ECCM;
chip->read_byte = fsl_elbc_read_byte;
chip->write_buf = fsl_elbc_write_buf;
chip->read_buf = fsl_elbc_read_buf;
chip->select_chip = fsl_elbc_select_chip;
chip->cmdfunc = fsl_elbc_cmdfunc;
chip->waitfunc = fsl_elbc_wait;
chip->bbt_td = &bbt_main_descr;
chip->bbt_md = &bbt_mirror_descr;
chip->bbt_options = NAND_BBT_USE_FLASH;
chip->controller = &elbc_fcm_ctrl->controller;
chip->priv = priv;
chip->ecc.read_page = fsl_elbc_read_page;
chip->ecc.write_page = fsl_elbc_write_page;
if ((in_be32(&lbc->bank[priv->bank].br) & BR_DECC) ==
BR_DECC_CHK_GEN) {
chip->ecc.mode = NAND_ECC_HW;
chip->ecc.layout = (priv->fmr & FMR_ECCM) ?
&fsl_elbc_oob_sp_eccm1 : &fsl_elbc_oob_sp_eccm0;
chip->ecc.size = 512;
chip->ecc.bytes = 3;
chip->ecc.strength = 1;
} else {
chip->ecc.mode = NAND_ECC_SOFT;
}
return 0;
}
static int fsl_elbc_chip_remove(struct fsl_elbc_mtd *priv)
{
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl = priv->ctrl->nand;
nand_release(&priv->mtd);
kfree(priv->mtd.name);
if (priv->vbase)
iounmap(priv->vbase);
elbc_fcm_ctrl->chips[priv->bank] = NULL;
kfree(priv);
return 0;
}
static int fsl_elbc_nand_probe(struct platform_device *pdev)
{
struct fsl_lbc_regs __iomem *lbc;
struct fsl_elbc_mtd *priv;
struct resource res;
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl;
static const char *part_probe_types[]
= { "cmdlinepart", "RedBoot", "ofpart", NULL };
int ret;
int bank;
struct device *dev;
struct device_node *node = pdev->dev.of_node;
struct mtd_part_parser_data ppdata;
ppdata.of_node = pdev->dev.of_node;
if (!fsl_lbc_ctrl_dev || !fsl_lbc_ctrl_dev->regs)
return -ENODEV;
lbc = fsl_lbc_ctrl_dev->regs;
dev = fsl_lbc_ctrl_dev->dev;
ret = of_address_to_resource(node, 0, &res);
if (ret) {
dev_err(dev, "failed to get resource\n");
return ret;
}
for (bank = 0; bank < MAX_BANKS; bank++)
if ((in_be32(&lbc->bank[bank].br) & BR_V) &&
(in_be32(&lbc->bank[bank].br) & BR_MSEL) == BR_MS_FCM &&
(in_be32(&lbc->bank[bank].br) &
in_be32(&lbc->bank[bank].or) & BR_BA)
== fsl_lbc_addr(res.start))
break;
if (bank >= MAX_BANKS) {
dev_err(dev, "address did not match any chip selects\n");
return -ENODEV;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
mutex_lock(&fsl_elbc_nand_mutex);
if (!fsl_lbc_ctrl_dev->nand) {
elbc_fcm_ctrl = kzalloc(sizeof(*elbc_fcm_ctrl), GFP_KERNEL);
if (!elbc_fcm_ctrl) {
dev_err(dev, "failed to allocate memory\n");
mutex_unlock(&fsl_elbc_nand_mutex);
ret = -ENOMEM;
goto err;
}
elbc_fcm_ctrl->counter++;
spin_lock_init(&elbc_fcm_ctrl->controller.lock);
init_waitqueue_head(&elbc_fcm_ctrl->controller.wq);
fsl_lbc_ctrl_dev->nand = elbc_fcm_ctrl;
} else {
elbc_fcm_ctrl = fsl_lbc_ctrl_dev->nand;
}
mutex_unlock(&fsl_elbc_nand_mutex);
elbc_fcm_ctrl->chips[bank] = priv;
priv->bank = bank;
priv->ctrl = fsl_lbc_ctrl_dev;
priv->dev = &pdev->dev;
dev_set_drvdata(priv->dev, priv);
priv->vbase = ioremap(res.start, resource_size(&res));
if (!priv->vbase) {
dev_err(dev, "failed to map chip region\n");
ret = -ENOMEM;
goto err;
}
priv->mtd.name = kasprintf(GFP_KERNEL, "%x.flash", (unsigned)res.start);
if (!priv->mtd.name) {
ret = -ENOMEM;
goto err;
}
ret = fsl_elbc_chip_init(priv);
if (ret)
goto err;
ret = nand_scan_ident(&priv->mtd, 1, NULL);
if (ret)
goto err;
ret = fsl_elbc_chip_init_tail(&priv->mtd);
if (ret)
goto err;
ret = nand_scan_tail(&priv->mtd);
if (ret)
goto err;
mtd_device_parse_register(&priv->mtd, part_probe_types, &ppdata,
NULL, 0);
printk(KERN_INFO "eLBC NAND device at 0x%llx, bank %d\n",
(unsigned long long)res.start, priv->bank);
return 0;
err:
fsl_elbc_chip_remove(priv);
return ret;
}
static int fsl_elbc_nand_remove(struct platform_device *pdev)
{
struct fsl_elbc_fcm_ctrl *elbc_fcm_ctrl = fsl_lbc_ctrl_dev->nand;
struct fsl_elbc_mtd *priv = dev_get_drvdata(&pdev->dev);
fsl_elbc_chip_remove(priv);
mutex_lock(&fsl_elbc_nand_mutex);
elbc_fcm_ctrl->counter--;
if (!elbc_fcm_ctrl->counter) {
fsl_lbc_ctrl_dev->nand = NULL;
kfree(elbc_fcm_ctrl);
}
mutex_unlock(&fsl_elbc_nand_mutex);
return 0;
}
