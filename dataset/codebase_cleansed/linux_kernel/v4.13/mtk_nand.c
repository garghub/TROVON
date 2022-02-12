static inline struct mtk_nfc_nand_chip *to_mtk_nand(struct nand_chip *nand)
{
return container_of(nand, struct mtk_nfc_nand_chip, nand);
}
static inline u8 *data_ptr(struct nand_chip *chip, const u8 *p, int i)
{
return (u8 *)p + i * chip->ecc.size;
}
static inline u8 *oob_ptr(struct nand_chip *chip, int i)
{
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
u8 *poi;
if (i < mtk_nand->bad_mark.sec)
poi = chip->oob_poi + (i + 1) * mtk_nand->fdm.reg_size;
else if (i == mtk_nand->bad_mark.sec)
poi = chip->oob_poi;
else
poi = chip->oob_poi + i * mtk_nand->fdm.reg_size;
return poi;
}
static inline int mtk_data_len(struct nand_chip *chip)
{
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
return chip->ecc.size + mtk_nand->spare_per_sector;
}
static inline u8 *mtk_data_ptr(struct nand_chip *chip, int i)
{
struct mtk_nfc *nfc = nand_get_controller_data(chip);
return nfc->buffer + i * mtk_data_len(chip);
}
static inline u8 *mtk_oob_ptr(struct nand_chip *chip, int i)
{
struct mtk_nfc *nfc = nand_get_controller_data(chip);
return nfc->buffer + i * mtk_data_len(chip) + chip->ecc.size;
}
static inline void nfi_writel(struct mtk_nfc *nfc, u32 val, u32 reg)
{
writel(val, nfc->regs + reg);
}
static inline void nfi_writew(struct mtk_nfc *nfc, u16 val, u32 reg)
{
writew(val, nfc->regs + reg);
}
static inline void nfi_writeb(struct mtk_nfc *nfc, u8 val, u32 reg)
{
writeb(val, nfc->regs + reg);
}
static inline u32 nfi_readl(struct mtk_nfc *nfc, u32 reg)
{
return readl_relaxed(nfc->regs + reg);
}
static inline u16 nfi_readw(struct mtk_nfc *nfc, u32 reg)
{
return readw_relaxed(nfc->regs + reg);
}
static inline u8 nfi_readb(struct mtk_nfc *nfc, u32 reg)
{
return readb_relaxed(nfc->regs + reg);
}
static void mtk_nfc_hw_reset(struct mtk_nfc *nfc)
{
struct device *dev = nfc->dev;
u32 val;
int ret;
nfi_writel(nfc, CON_FIFO_FLUSH | CON_NFI_RST, NFI_CON);
ret = readl_poll_timeout(nfc->regs + NFI_MASTER_STA, val,
!(val & MASTER_STA_MASK), 50,
MTK_RESET_TIMEOUT);
if (ret)
dev_warn(dev, "master active in reset [0x%x] = 0x%x\n",
NFI_MASTER_STA, val);
nfi_writel(nfc, CON_FIFO_FLUSH | CON_NFI_RST, NFI_CON);
nfi_writew(nfc, STAR_DE, NFI_STRDATA);
}
static int mtk_nfc_send_command(struct mtk_nfc *nfc, u8 command)
{
struct device *dev = nfc->dev;
u32 val;
int ret;
nfi_writel(nfc, command, NFI_CMD);
ret = readl_poll_timeout_atomic(nfc->regs + NFI_STA, val,
!(val & STA_CMD), 10, MTK_TIMEOUT);
if (ret) {
dev_warn(dev, "nfi core timed out entering command mode\n");
return -EIO;
}
return 0;
}
static int mtk_nfc_send_address(struct mtk_nfc *nfc, int addr)
{
struct device *dev = nfc->dev;
u32 val;
int ret;
nfi_writel(nfc, addr, NFI_COLADDR);
nfi_writel(nfc, 0, NFI_ROWADDR);
nfi_writew(nfc, 1, NFI_ADDRNOB);
ret = readl_poll_timeout_atomic(nfc->regs + NFI_STA, val,
!(val & STA_ADDR), 10, MTK_TIMEOUT);
if (ret) {
dev_warn(dev, "nfi core timed out entering address mode\n");
return -EIO;
}
return 0;
}
static int mtk_nfc_hw_runtime_config(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
struct mtk_nfc *nfc = nand_get_controller_data(chip);
u32 fmt, spare, i;
if (!mtd->writesize)
return 0;
spare = mtk_nand->spare_per_sector;
switch (mtd->writesize) {
case 512:
fmt = PAGEFMT_512_2K | PAGEFMT_SEC_SEL_512;
break;
case KB(2):
if (chip->ecc.size == 512)
fmt = PAGEFMT_2K_4K | PAGEFMT_SEC_SEL_512;
else
fmt = PAGEFMT_512_2K;
break;
case KB(4):
if (chip->ecc.size == 512)
fmt = PAGEFMT_4K_8K | PAGEFMT_SEC_SEL_512;
else
fmt = PAGEFMT_2K_4K;
break;
case KB(8):
if (chip->ecc.size == 512)
fmt = PAGEFMT_8K_16K | PAGEFMT_SEC_SEL_512;
else
fmt = PAGEFMT_4K_8K;
break;
case KB(16):
fmt = PAGEFMT_8K_16K;
break;
default:
dev_err(nfc->dev, "invalid page len: %d\n", mtd->writesize);
return -EINVAL;
}
if (chip->ecc.size == 1024)
spare >>= 1;
for (i = 0; i < nfc->caps->num_spare_size; i++) {
if (nfc->caps->spare_size[i] == spare)
break;
}
if (i == nfc->caps->num_spare_size) {
dev_err(nfc->dev, "invalid spare size %d\n", spare);
return -EINVAL;
}
fmt |= i << nfc->caps->pageformat_spare_shift;
fmt |= mtk_nand->fdm.reg_size << PAGEFMT_FDM_SHIFT;
fmt |= mtk_nand->fdm.ecc_size << PAGEFMT_FDM_ECC_SHIFT;
nfi_writel(nfc, fmt, NFI_PAGEFMT);
nfc->ecc_cfg.strength = chip->ecc.strength;
nfc->ecc_cfg.len = chip->ecc.size + mtk_nand->fdm.ecc_size;
return 0;
}
static void mtk_nfc_select_chip(struct mtd_info *mtd, int chip)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct mtk_nfc *nfc = nand_get_controller_data(nand);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(nand);
if (chip < 0)
return;
mtk_nfc_hw_runtime_config(mtd);
nfi_writel(nfc, mtk_nand->sels[chip], NFI_CSEL);
}
static int mtk_nfc_dev_ready(struct mtd_info *mtd)
{
struct mtk_nfc *nfc = nand_get_controller_data(mtd_to_nand(mtd));
if (nfi_readl(nfc, NFI_STA) & STA_BUSY)
return 0;
return 1;
}
static void mtk_nfc_cmd_ctrl(struct mtd_info *mtd, int dat, unsigned int ctrl)
{
struct mtk_nfc *nfc = nand_get_controller_data(mtd_to_nand(mtd));
if (ctrl & NAND_ALE) {
mtk_nfc_send_address(nfc, dat);
} else if (ctrl & NAND_CLE) {
mtk_nfc_hw_reset(nfc);
nfi_writew(nfc, CNFG_OP_CUST, NFI_CNFG);
mtk_nfc_send_command(nfc, dat);
}
}
static inline void mtk_nfc_wait_ioready(struct mtk_nfc *nfc)
{
int rc;
u8 val;
rc = readb_poll_timeout_atomic(nfc->regs + NFI_PIO_DIRDY, val,
val & PIO_DI_RDY, 10, MTK_TIMEOUT);
if (rc < 0)
dev_err(nfc->dev, "data not ready\n");
}
static inline u8 mtk_nfc_read_byte(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct mtk_nfc *nfc = nand_get_controller_data(chip);
u32 reg;
reg = nfi_readl(nfc, NFI_STA) & NFI_FSM_MASK;
if (reg != NFI_FSM_CUSTDATA) {
reg = nfi_readw(nfc, NFI_CNFG);
reg |= CNFG_BYTE_RW | CNFG_READ_EN;
nfi_writew(nfc, reg, NFI_CNFG);
reg = (MTK_MAX_SECTOR << CON_SEC_SHIFT) | CON_BRD;
nfi_writel(nfc, reg, NFI_CON);
nfi_writew(nfc, STAR_EN, NFI_STRDATA);
}
mtk_nfc_wait_ioready(nfc);
return nfi_readb(nfc, NFI_DATAR);
}
static void mtk_nfc_read_buf(struct mtd_info *mtd, u8 *buf, int len)
{
int i;
for (i = 0; i < len; i++)
buf[i] = mtk_nfc_read_byte(mtd);
}
static void mtk_nfc_write_byte(struct mtd_info *mtd, u8 byte)
{
struct mtk_nfc *nfc = nand_get_controller_data(mtd_to_nand(mtd));
u32 reg;
reg = nfi_readl(nfc, NFI_STA) & NFI_FSM_MASK;
if (reg != NFI_FSM_CUSTDATA) {
reg = nfi_readw(nfc, NFI_CNFG) | CNFG_BYTE_RW;
nfi_writew(nfc, reg, NFI_CNFG);
reg = MTK_MAX_SECTOR << CON_SEC_SHIFT | CON_BWR;
nfi_writel(nfc, reg, NFI_CON);
nfi_writew(nfc, STAR_EN, NFI_STRDATA);
}
mtk_nfc_wait_ioready(nfc);
nfi_writeb(nfc, byte, NFI_DATAW);
}
static void mtk_nfc_write_buf(struct mtd_info *mtd, const u8 *buf, int len)
{
int i;
for (i = 0; i < len; i++)
mtk_nfc_write_byte(mtd, buf[i]);
}
static int mtk_nfc_setup_data_interface(struct mtd_info *mtd, int csline,
const struct nand_data_interface *conf)
{
struct mtk_nfc *nfc = nand_get_controller_data(mtd_to_nand(mtd));
const struct nand_sdr_timings *timings;
u32 rate, tpoecs, tprecs, tc2r, tw2r, twh, twst, trlt;
timings = nand_get_sdr_timings(conf);
if (IS_ERR(timings))
return -ENOTSUPP;
if (csline == NAND_DATA_IFACE_CHECK_ONLY)
return 0;
rate = clk_get_rate(nfc->clk.nfi_clk);
rate /= nfc->caps->nfi_clk_div;
rate /= 1000;
tpoecs = max(timings->tALH_min, timings->tCLH_min) / 1000;
tpoecs = DIV_ROUND_UP(tpoecs * rate, 1000000);
tpoecs &= 0xf;
tprecs = max(timings->tCLS_min, timings->tALS_min) / 1000;
tprecs = DIV_ROUND_UP(tprecs * rate, 1000000);
tprecs &= 0x3f;
tc2r = 0;
tw2r = timings->tWHR_min / 1000;
tw2r = DIV_ROUND_UP(tw2r * rate, 1000000);
tw2r = DIV_ROUND_UP(tw2r - 1, 2);
tw2r &= 0xf;
twh = max(timings->tREH_min, timings->tWH_min) / 1000;
twh = DIV_ROUND_UP(twh * rate, 1000000) - 1;
twh &= 0xf;
twst = timings->tWP_min / 1000;
twst = DIV_ROUND_UP(twst * rate, 1000000) - 1;
twst &= 0xf;
trlt = max(timings->tREA_max, timings->tRP_min) / 1000;
trlt = DIV_ROUND_UP(trlt * rate, 1000000) - 1;
trlt &= 0xf;
trlt = ACCTIMING(tpoecs, tprecs, tc2r, tw2r, twh, twst, trlt);
nfi_writel(nfc, trlt, NFI_ACCCON);
return 0;
}
static int mtk_nfc_sector_encode(struct nand_chip *chip, u8 *data)
{
struct mtk_nfc *nfc = nand_get_controller_data(chip);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
int size = chip->ecc.size + mtk_nand->fdm.reg_size;
nfc->ecc_cfg.mode = ECC_DMA_MODE;
nfc->ecc_cfg.op = ECC_ENCODE;
return mtk_ecc_encode(nfc->ecc, &nfc->ecc_cfg, data, size);
}
static void mtk_nfc_no_bad_mark_swap(struct mtd_info *a, u8 *b, int c)
{
}
static void mtk_nfc_bad_mark_swap(struct mtd_info *mtd, u8 *buf, int raw)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct mtk_nfc_nand_chip *nand = to_mtk_nand(chip);
u32 bad_pos = nand->bad_mark.pos;
if (raw)
bad_pos += nand->bad_mark.sec * mtk_data_len(chip);
else
bad_pos += nand->bad_mark.sec * chip->ecc.size;
swap(chip->oob_poi[0], buf[bad_pos]);
}
static int mtk_nfc_format_subpage(struct mtd_info *mtd, u32 offset,
u32 len, const u8 *buf)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
struct mtk_nfc *nfc = nand_get_controller_data(chip);
struct mtk_nfc_fdm *fdm = &mtk_nand->fdm;
u32 start, end;
int i, ret;
start = offset / chip->ecc.size;
end = DIV_ROUND_UP(offset + len, chip->ecc.size);
memset(nfc->buffer, 0xff, mtd->writesize + mtd->oobsize);
for (i = 0; i < chip->ecc.steps; i++) {
memcpy(mtk_data_ptr(chip, i), data_ptr(chip, buf, i),
chip->ecc.size);
if (start > i || i >= end)
continue;
if (i == mtk_nand->bad_mark.sec)
mtk_nand->bad_mark.bm_swap(mtd, nfc->buffer, 1);
memcpy(mtk_oob_ptr(chip, i), oob_ptr(chip, i), fdm->reg_size);
ret = mtk_nfc_sector_encode(chip, mtk_data_ptr(chip, i));
if (ret < 0)
return ret;
}
return 0;
}
static void mtk_nfc_format_page(struct mtd_info *mtd, const u8 *buf)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
struct mtk_nfc *nfc = nand_get_controller_data(chip);
struct mtk_nfc_fdm *fdm = &mtk_nand->fdm;
u32 i;
memset(nfc->buffer, 0xff, mtd->writesize + mtd->oobsize);
for (i = 0; i < chip->ecc.steps; i++) {
if (buf)
memcpy(mtk_data_ptr(chip, i), data_ptr(chip, buf, i),
chip->ecc.size);
if (i == mtk_nand->bad_mark.sec)
mtk_nand->bad_mark.bm_swap(mtd, nfc->buffer, 1);
memcpy(mtk_oob_ptr(chip, i), oob_ptr(chip, i), fdm->reg_size);
}
}
static inline void mtk_nfc_read_fdm(struct nand_chip *chip, u32 start,
u32 sectors)
{
struct mtk_nfc *nfc = nand_get_controller_data(chip);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
struct mtk_nfc_fdm *fdm = &mtk_nand->fdm;
u32 vall, valm;
u8 *oobptr;
int i, j;
for (i = 0; i < sectors; i++) {
oobptr = oob_ptr(chip, start + i);
vall = nfi_readl(nfc, NFI_FDML(i));
valm = nfi_readl(nfc, NFI_FDMM(i));
for (j = 0; j < fdm->reg_size; j++)
oobptr[j] = (j >= 4 ? valm : vall) >> ((j % 4) * 8);
}
}
static inline void mtk_nfc_write_fdm(struct nand_chip *chip)
{
struct mtk_nfc *nfc = nand_get_controller_data(chip);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
struct mtk_nfc_fdm *fdm = &mtk_nand->fdm;
u32 vall, valm;
u8 *oobptr;
int i, j;
for (i = 0; i < chip->ecc.steps; i++) {
oobptr = oob_ptr(chip, i);
vall = 0;
valm = 0;
for (j = 0; j < 8; j++) {
if (j < 4)
vall |= (j < fdm->reg_size ? oobptr[j] : 0xff)
<< (j * 8);
else
valm |= (j < fdm->reg_size ? oobptr[j] : 0xff)
<< ((j - 4) * 8);
}
nfi_writel(nfc, vall, NFI_FDML(i));
nfi_writel(nfc, valm, NFI_FDMM(i));
}
}
static int mtk_nfc_do_write_page(struct mtd_info *mtd, struct nand_chip *chip,
const u8 *buf, int page, int len)
{
struct mtk_nfc *nfc = nand_get_controller_data(chip);
struct device *dev = nfc->dev;
dma_addr_t addr;
u32 reg;
int ret;
addr = dma_map_single(dev, (void *)buf, len, DMA_TO_DEVICE);
ret = dma_mapping_error(nfc->dev, addr);
if (ret) {
dev_err(nfc->dev, "dma mapping error\n");
return -EINVAL;
}
reg = nfi_readw(nfc, NFI_CNFG) | CNFG_AHB | CNFG_DMA_BURST_EN;
nfi_writew(nfc, reg, NFI_CNFG);
nfi_writel(nfc, chip->ecc.steps << CON_SEC_SHIFT, NFI_CON);
nfi_writel(nfc, lower_32_bits(addr), NFI_STRADDR);
nfi_writew(nfc, INTR_AHB_DONE_EN, NFI_INTR_EN);
init_completion(&nfc->done);
reg = nfi_readl(nfc, NFI_CON) | CON_BWR;
nfi_writel(nfc, reg, NFI_CON);
nfi_writew(nfc, STAR_EN, NFI_STRDATA);
ret = wait_for_completion_timeout(&nfc->done, msecs_to_jiffies(500));
if (!ret) {
dev_err(dev, "program ahb done timeout\n");
nfi_writew(nfc, 0, NFI_INTR_EN);
ret = -ETIMEDOUT;
goto timeout;
}
ret = readl_poll_timeout_atomic(nfc->regs + NFI_ADDRCNTR, reg,
ADDRCNTR_SEC(reg) >= chip->ecc.steps,
10, MTK_TIMEOUT);
if (ret)
dev_err(dev, "hwecc write timeout\n");
timeout:
dma_unmap_single(nfc->dev, addr, len, DMA_TO_DEVICE);
nfi_writel(nfc, 0, NFI_CON);
return ret;
}
static int mtk_nfc_write_page(struct mtd_info *mtd, struct nand_chip *chip,
const u8 *buf, int page, int raw)
{
struct mtk_nfc *nfc = nand_get_controller_data(chip);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
size_t len;
const u8 *bufpoi;
u32 reg;
int ret;
if (!raw) {
reg = nfi_readw(nfc, NFI_CNFG) | CNFG_AUTO_FMT_EN;
nfi_writew(nfc, reg | CNFG_HW_ECC_EN, NFI_CNFG);
nfc->ecc_cfg.op = ECC_ENCODE;
nfc->ecc_cfg.mode = ECC_NFI_MODE;
ret = mtk_ecc_enable(nfc->ecc, &nfc->ecc_cfg);
if (ret) {
reg = nfi_readw(nfc, NFI_CNFG);
reg &= ~(CNFG_AUTO_FMT_EN | CNFG_HW_ECC_EN);
nfi_writew(nfc, reg, NFI_CNFG);
return ret;
}
memcpy(nfc->buffer, buf, mtd->writesize);
mtk_nand->bad_mark.bm_swap(mtd, nfc->buffer, raw);
bufpoi = nfc->buffer;
mtk_nfc_write_fdm(chip);
} else {
bufpoi = buf;
}
len = mtd->writesize + (raw ? mtd->oobsize : 0);
ret = mtk_nfc_do_write_page(mtd, chip, bufpoi, page, len);
if (!raw)
mtk_ecc_disable(nfc->ecc);
return ret;
}
static int mtk_nfc_write_page_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, const u8 *buf,
int oob_on, int page)
{
return mtk_nfc_write_page(mtd, chip, buf, page, 0);
}
static int mtk_nfc_write_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
const u8 *buf, int oob_on, int pg)
{
struct mtk_nfc *nfc = nand_get_controller_data(chip);
mtk_nfc_format_page(mtd, buf);
return mtk_nfc_write_page(mtd, chip, nfc->buffer, pg, 1);
}
static int mtk_nfc_write_subpage_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, u32 offset,
u32 data_len, const u8 *buf,
int oob_on, int page)
{
struct mtk_nfc *nfc = nand_get_controller_data(chip);
int ret;
ret = mtk_nfc_format_subpage(mtd, offset, data_len, buf);
if (ret < 0)
return ret;
return mtk_nfc_write_page(mtd, chip, nfc->buffer, page, 1);
}
static int mtk_nfc_write_oob_std(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
int ret;
chip->cmdfunc(mtd, NAND_CMD_SEQIN, 0x00, page);
ret = mtk_nfc_write_page_raw(mtd, chip, NULL, 1, page);
if (ret < 0)
return -EIO;
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
ret = chip->waitfunc(mtd, chip);
return ret & NAND_STATUS_FAIL ? -EIO : 0;
}
static int mtk_nfc_update_ecc_stats(struct mtd_info *mtd, u8 *buf, u32 sectors)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct mtk_nfc *nfc = nand_get_controller_data(chip);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
struct mtk_ecc_stats stats;
int rc, i;
rc = nfi_readl(nfc, NFI_STA) & STA_EMP_PAGE;
if (rc) {
memset(buf, 0xff, sectors * chip->ecc.size);
for (i = 0; i < sectors; i++)
memset(oob_ptr(chip, i), 0xff, mtk_nand->fdm.reg_size);
return 0;
}
mtk_ecc_get_stats(nfc->ecc, &stats, sectors);
mtd->ecc_stats.corrected += stats.corrected;
mtd->ecc_stats.failed += stats.failed;
return stats.bitflips;
}
static int mtk_nfc_read_subpage(struct mtd_info *mtd, struct nand_chip *chip,
u32 data_offs, u32 readlen,
u8 *bufpoi, int page, int raw)
{
struct mtk_nfc *nfc = nand_get_controller_data(chip);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
u32 spare = mtk_nand->spare_per_sector;
u32 column, sectors, start, end, reg;
dma_addr_t addr;
int bitflips;
size_t len;
u8 *buf;
int rc;
start = data_offs / chip->ecc.size;
end = DIV_ROUND_UP(data_offs + readlen, chip->ecc.size);
sectors = end - start;
column = start * (chip->ecc.size + spare);
len = sectors * chip->ecc.size + (raw ? sectors * spare : 0);
buf = bufpoi + start * chip->ecc.size;
if (column != 0)
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, column, -1);
addr = dma_map_single(nfc->dev, buf, len, DMA_FROM_DEVICE);
rc = dma_mapping_error(nfc->dev, addr);
if (rc) {
dev_err(nfc->dev, "dma mapping error\n");
return -EINVAL;
}
reg = nfi_readw(nfc, NFI_CNFG);
reg |= CNFG_READ_EN | CNFG_DMA_BURST_EN | CNFG_AHB;
if (!raw) {
reg |= CNFG_AUTO_FMT_EN | CNFG_HW_ECC_EN;
nfi_writew(nfc, reg, NFI_CNFG);
nfc->ecc_cfg.mode = ECC_NFI_MODE;
nfc->ecc_cfg.sectors = sectors;
nfc->ecc_cfg.op = ECC_DECODE;
rc = mtk_ecc_enable(nfc->ecc, &nfc->ecc_cfg);
if (rc) {
dev_err(nfc->dev, "ecc enable\n");
reg &= ~(CNFG_DMA_BURST_EN | CNFG_AHB | CNFG_READ_EN |
CNFG_AUTO_FMT_EN | CNFG_HW_ECC_EN);
nfi_writew(nfc, reg, NFI_CNFG);
dma_unmap_single(nfc->dev, addr, len, DMA_FROM_DEVICE);
return rc;
}
} else {
nfi_writew(nfc, reg, NFI_CNFG);
}
nfi_writel(nfc, sectors << CON_SEC_SHIFT, NFI_CON);
nfi_writew(nfc, INTR_AHB_DONE_EN, NFI_INTR_EN);
nfi_writel(nfc, lower_32_bits(addr), NFI_STRADDR);
init_completion(&nfc->done);
reg = nfi_readl(nfc, NFI_CON) | CON_BRD;
nfi_writel(nfc, reg, NFI_CON);
nfi_writew(nfc, STAR_EN, NFI_STRDATA);
rc = wait_for_completion_timeout(&nfc->done, msecs_to_jiffies(500));
if (!rc)
dev_warn(nfc->dev, "read ahb/dma done timeout\n");
rc = readl_poll_timeout_atomic(nfc->regs + NFI_BYTELEN, reg,
ADDRCNTR_SEC(reg) >= sectors, 10,
MTK_TIMEOUT);
if (rc < 0) {
dev_err(nfc->dev, "subpage done timeout\n");
bitflips = -EIO;
} else {
bitflips = 0;
if (!raw) {
rc = mtk_ecc_wait_done(nfc->ecc, ECC_DECODE);
bitflips = rc < 0 ? -ETIMEDOUT :
mtk_nfc_update_ecc_stats(mtd, buf, sectors);
mtk_nfc_read_fdm(chip, start, sectors);
}
}
dma_unmap_single(nfc->dev, addr, len, DMA_FROM_DEVICE);
if (raw)
goto done;
mtk_ecc_disable(nfc->ecc);
if (clamp(mtk_nand->bad_mark.sec, start, end) == mtk_nand->bad_mark.sec)
mtk_nand->bad_mark.bm_swap(mtd, bufpoi, raw);
done:
nfi_writel(nfc, 0, NFI_CON);
return bitflips;
}
static int mtk_nfc_read_subpage_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, u32 off,
u32 len, u8 *p, int pg)
{
return mtk_nfc_read_subpage(mtd, chip, off, len, p, pg, 0);
}
static int mtk_nfc_read_page_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, u8 *p,
int oob_on, int pg)
{
return mtk_nfc_read_subpage(mtd, chip, 0, mtd->writesize, p, pg, 0);
}
static int mtk_nfc_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
u8 *buf, int oob_on, int page)
{
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
struct mtk_nfc *nfc = nand_get_controller_data(chip);
struct mtk_nfc_fdm *fdm = &mtk_nand->fdm;
int i, ret;
memset(nfc->buffer, 0xff, mtd->writesize + mtd->oobsize);
ret = mtk_nfc_read_subpage(mtd, chip, 0, mtd->writesize, nfc->buffer,
page, 1);
if (ret < 0)
return ret;
for (i = 0; i < chip->ecc.steps; i++) {
memcpy(oob_ptr(chip, i), mtk_oob_ptr(chip, i), fdm->reg_size);
if (i == mtk_nand->bad_mark.sec)
mtk_nand->bad_mark.bm_swap(mtd, nfc->buffer, 1);
if (buf)
memcpy(data_ptr(chip, buf, i), mtk_data_ptr(chip, i),
chip->ecc.size);
}
return ret;
}
static int mtk_nfc_read_oob_std(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
chip->cmdfunc(mtd, NAND_CMD_READ0, 0, page);
return mtk_nfc_read_page_raw(mtd, chip, NULL, 1, page);
}
static inline void mtk_nfc_hw_init(struct mtk_nfc *nfc)
{
nfi_writew(nfc, 0xf1, NFI_CNRNB);
nfi_writel(nfc, PAGEFMT_8K_16K, NFI_PAGEFMT);
mtk_nfc_hw_reset(nfc);
nfi_readl(nfc, NFI_INTR_STA);
nfi_writel(nfc, 0, NFI_INTR_EN);
}
static irqreturn_t mtk_nfc_irq(int irq, void *id)
{
struct mtk_nfc *nfc = id;
u16 sta, ien;
sta = nfi_readw(nfc, NFI_INTR_STA);
ien = nfi_readw(nfc, NFI_INTR_EN);
if (!(sta & ien))
return IRQ_NONE;
nfi_writew(nfc, ~sta & ien, NFI_INTR_EN);
complete(&nfc->done);
return IRQ_HANDLED;
}
static int mtk_nfc_enable_clk(struct device *dev, struct mtk_nfc_clk *clk)
{
int ret;
ret = clk_prepare_enable(clk->nfi_clk);
if (ret) {
dev_err(dev, "failed to enable nfi clk\n");
return ret;
}
ret = clk_prepare_enable(clk->pad_clk);
if (ret) {
dev_err(dev, "failed to enable pad clk\n");
clk_disable_unprepare(clk->nfi_clk);
return ret;
}
return 0;
}
static void mtk_nfc_disable_clk(struct mtk_nfc_clk *clk)
{
clk_disable_unprepare(clk->nfi_clk);
clk_disable_unprepare(clk->pad_clk);
}
static int mtk_nfc_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oob_region)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
struct mtk_nfc_fdm *fdm = &mtk_nand->fdm;
u32 eccsteps;
eccsteps = mtd->writesize / chip->ecc.size;
if (section >= eccsteps)
return -ERANGE;
oob_region->length = fdm->reg_size - fdm->ecc_size;
oob_region->offset = section * fdm->reg_size + fdm->ecc_size;
return 0;
}
static int mtk_nfc_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oob_region)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct mtk_nfc_nand_chip *mtk_nand = to_mtk_nand(chip);
u32 eccsteps;
if (section)
return -ERANGE;
eccsteps = mtd->writesize / chip->ecc.size;
oob_region->offset = mtk_nand->fdm.reg_size * eccsteps;
oob_region->length = mtd->oobsize - oob_region->offset;
return 0;
}
static void mtk_nfc_set_fdm(struct mtk_nfc_fdm *fdm, struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct mtk_nfc_nand_chip *chip = to_mtk_nand(nand);
u32 ecc_bytes;
ecc_bytes = DIV_ROUND_UP(nand->ecc.strength * ECC_PARITY_BITS, 8);
fdm->reg_size = chip->spare_per_sector - ecc_bytes;
if (fdm->reg_size > NFI_FDM_MAX_SIZE)
fdm->reg_size = NFI_FDM_MAX_SIZE;
fdm->ecc_size = 1;
}
static void mtk_nfc_set_bad_mark_ctl(struct mtk_nfc_bad_mark_ctl *bm_ctl,
struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
if (mtd->writesize == 512) {
bm_ctl->bm_swap = mtk_nfc_no_bad_mark_swap;
} else {
bm_ctl->bm_swap = mtk_nfc_bad_mark_swap;
bm_ctl->sec = mtd->writesize / mtk_data_len(nand);
bm_ctl->pos = mtd->writesize % mtk_data_len(nand);
}
}
static int mtk_nfc_set_spare_per_sector(u32 *sps, struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct mtk_nfc *nfc = nand_get_controller_data(nand);
const u8 *spare = nfc->caps->spare_size;
u32 eccsteps, i, closest_spare = 0;
eccsteps = mtd->writesize / nand->ecc.size;
*sps = mtd->oobsize / eccsteps;
if (nand->ecc.size == 1024)
*sps >>= 1;
if (*sps < MTK_NFC_MIN_SPARE)
return -EINVAL;
for (i = 0; i < nfc->caps->num_spare_size; i++) {
if (*sps >= spare[i] && spare[i] >= spare[closest_spare]) {
closest_spare = i;
if (*sps == spare[i])
break;
}
}
*sps = spare[closest_spare];
if (nand->ecc.size == 1024)
*sps <<= 1;
return 0;
}
static int mtk_nfc_ecc_init(struct device *dev, struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct mtk_nfc *nfc = nand_get_controller_data(nand);
u32 spare;
int free, ret;
if (nand->ecc.mode != NAND_ECC_HW) {
dev_err(dev, "ecc.mode not supported\n");
return -EINVAL;
}
if (!nand->ecc.size || !nand->ecc.strength) {
nand->ecc.strength = nand->ecc_strength_ds;
nand->ecc.size = nand->ecc_step_ds;
if (nand->ecc.size < 1024) {
if (mtd->writesize > 512) {
nand->ecc.size = 1024;
nand->ecc.strength <<= 1;
} else {
nand->ecc.size = 512;
}
} else {
nand->ecc.size = 1024;
}
ret = mtk_nfc_set_spare_per_sector(&spare, mtd);
if (ret)
return ret;
free = ((nand->ecc.strength * ECC_PARITY_BITS) + 7) >> 3;
free = spare - free;
if (free > NFI_FDM_MAX_SIZE) {
spare -= NFI_FDM_MAX_SIZE;
nand->ecc.strength = (spare << 3) / ECC_PARITY_BITS;
} else if (free < 0) {
spare -= NFI_FDM_MIN_SIZE;
nand->ecc.strength = (spare << 3) / ECC_PARITY_BITS;
}
}
mtk_ecc_adjust_strength(nfc->ecc, &nand->ecc.strength);
dev_info(dev, "eccsize %d eccstrength %d\n",
nand->ecc.size, nand->ecc.strength);
return 0;
}
static int mtk_nfc_nand_chip_init(struct device *dev, struct mtk_nfc *nfc,
struct device_node *np)
{
struct mtk_nfc_nand_chip *chip;
struct nand_chip *nand;
struct mtd_info *mtd;
int nsels, len;
u32 tmp;
int ret;
int i;
if (!of_get_property(np, "reg", &nsels))
return -ENODEV;
nsels /= sizeof(u32);
if (!nsels || nsels > MTK_NAND_MAX_NSELS) {
dev_err(dev, "invalid reg property size %d\n", nsels);
return -EINVAL;
}
chip = devm_kzalloc(dev, sizeof(*chip) + nsels * sizeof(u8),
GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->nsels = nsels;
for (i = 0; i < nsels; i++) {
ret = of_property_read_u32_index(np, "reg", i, &tmp);
if (ret) {
dev_err(dev, "reg property failure : %d\n", ret);
return ret;
}
chip->sels[i] = tmp;
}
nand = &chip->nand;
nand->controller = &nfc->controller;
nand_set_flash_node(nand, np);
nand_set_controller_data(nand, nfc);
nand->options |= NAND_USE_BOUNCE_BUFFER | NAND_SUBPAGE_READ;
nand->dev_ready = mtk_nfc_dev_ready;
nand->select_chip = mtk_nfc_select_chip;
nand->write_byte = mtk_nfc_write_byte;
nand->write_buf = mtk_nfc_write_buf;
nand->read_byte = mtk_nfc_read_byte;
nand->read_buf = mtk_nfc_read_buf;
nand->cmd_ctrl = mtk_nfc_cmd_ctrl;
nand->setup_data_interface = mtk_nfc_setup_data_interface;
nand->ecc.mode = NAND_ECC_HW;
nand->ecc.write_subpage = mtk_nfc_write_subpage_hwecc;
nand->ecc.write_page_raw = mtk_nfc_write_page_raw;
nand->ecc.write_page = mtk_nfc_write_page_hwecc;
nand->ecc.write_oob_raw = mtk_nfc_write_oob_std;
nand->ecc.write_oob = mtk_nfc_write_oob_std;
nand->ecc.read_subpage = mtk_nfc_read_subpage_hwecc;
nand->ecc.read_page_raw = mtk_nfc_read_page_raw;
nand->ecc.read_page = mtk_nfc_read_page_hwecc;
nand->ecc.read_oob_raw = mtk_nfc_read_oob_std;
nand->ecc.read_oob = mtk_nfc_read_oob_std;
mtd = nand_to_mtd(nand);
mtd->owner = THIS_MODULE;
mtd->dev.parent = dev;
mtd->name = MTK_NAME;
mtd_set_ooblayout(mtd, &mtk_nfc_ooblayout_ops);
mtk_nfc_hw_init(nfc);
ret = nand_scan_ident(mtd, nsels, NULL);
if (ret)
return ret;
if (nand->bbt_options & NAND_BBT_USE_FLASH)
nand->bbt_options |= NAND_BBT_NO_OOB;
ret = mtk_nfc_ecc_init(dev, mtd);
if (ret)
return -EINVAL;
if (nand->options & NAND_BUSWIDTH_16) {
dev_err(dev, "16bits buswidth not supported");
return -EINVAL;
}
ret = mtk_nfc_set_spare_per_sector(&chip->spare_per_sector, mtd);
if (ret)
return ret;
mtk_nfc_set_fdm(&chip->fdm, mtd);
mtk_nfc_set_bad_mark_ctl(&chip->bad_mark, mtd);
len = mtd->writesize + mtd->oobsize;
nfc->buffer = devm_kzalloc(dev, len, GFP_KERNEL);
if (!nfc->buffer)
return -ENOMEM;
ret = nand_scan_tail(mtd);
if (ret)
return ret;
ret = mtd_device_parse_register(mtd, NULL, NULL, NULL, 0);
if (ret) {
dev_err(dev, "mtd parse partition error\n");
nand_release(mtd);
return ret;
}
list_add_tail(&chip->node, &nfc->chips);
return 0;
}
static int mtk_nfc_nand_chips_init(struct device *dev, struct mtk_nfc *nfc)
{
struct device_node *np = dev->of_node;
struct device_node *nand_np;
int ret;
for_each_child_of_node(np, nand_np) {
ret = mtk_nfc_nand_chip_init(dev, nfc, nand_np);
if (ret) {
of_node_put(nand_np);
return ret;
}
}
return 0;
}
static int mtk_nfc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct mtk_nfc *nfc;
struct resource *res;
const struct of_device_id *of_nfc_id = NULL;
int ret, irq;
nfc = devm_kzalloc(dev, sizeof(*nfc), GFP_KERNEL);
if (!nfc)
return -ENOMEM;
spin_lock_init(&nfc->controller.lock);
init_waitqueue_head(&nfc->controller.wq);
INIT_LIST_HEAD(&nfc->chips);
nfc->ecc = of_mtk_ecc_get(np);
if (IS_ERR(nfc->ecc))
return PTR_ERR(nfc->ecc);
else if (!nfc->ecc)
return -ENODEV;
nfc->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
nfc->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(nfc->regs)) {
ret = PTR_ERR(nfc->regs);
goto release_ecc;
}
nfc->clk.nfi_clk = devm_clk_get(dev, "nfi_clk");
if (IS_ERR(nfc->clk.nfi_clk)) {
dev_err(dev, "no clk\n");
ret = PTR_ERR(nfc->clk.nfi_clk);
goto release_ecc;
}
nfc->clk.pad_clk = devm_clk_get(dev, "pad_clk");
if (IS_ERR(nfc->clk.pad_clk)) {
dev_err(dev, "no pad clk\n");
ret = PTR_ERR(nfc->clk.pad_clk);
goto release_ecc;
}
ret = mtk_nfc_enable_clk(dev, &nfc->clk);
if (ret)
goto release_ecc;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "no nfi irq resource\n");
ret = -EINVAL;
goto clk_disable;
}
ret = devm_request_irq(dev, irq, mtk_nfc_irq, 0x0, "mtk-nand", nfc);
if (ret) {
dev_err(dev, "failed to request nfi irq\n");
goto clk_disable;
}
ret = dma_set_mask(dev, DMA_BIT_MASK(32));
if (ret) {
dev_err(dev, "failed to set dma mask\n");
goto clk_disable;
}
of_nfc_id = of_match_device(mtk_nfc_id_table, &pdev->dev);
if (!of_nfc_id) {
ret = -ENODEV;
goto clk_disable;
}
nfc->caps = of_nfc_id->data;
platform_set_drvdata(pdev, nfc);
ret = mtk_nfc_nand_chips_init(dev, nfc);
if (ret) {
dev_err(dev, "failed to init nand chips\n");
goto clk_disable;
}
return 0;
clk_disable:
mtk_nfc_disable_clk(&nfc->clk);
release_ecc:
mtk_ecc_release(nfc->ecc);
return ret;
}
static int mtk_nfc_remove(struct platform_device *pdev)
{
struct mtk_nfc *nfc = platform_get_drvdata(pdev);
struct mtk_nfc_nand_chip *chip;
while (!list_empty(&nfc->chips)) {
chip = list_first_entry(&nfc->chips, struct mtk_nfc_nand_chip,
node);
nand_release(nand_to_mtd(&chip->nand));
list_del(&chip->node);
}
mtk_ecc_release(nfc->ecc);
mtk_nfc_disable_clk(&nfc->clk);
return 0;
}
static int mtk_nfc_suspend(struct device *dev)
{
struct mtk_nfc *nfc = dev_get_drvdata(dev);
mtk_nfc_disable_clk(&nfc->clk);
return 0;
}
static int mtk_nfc_resume(struct device *dev)
{
struct mtk_nfc *nfc = dev_get_drvdata(dev);
struct mtk_nfc_nand_chip *chip;
struct nand_chip *nand;
struct mtd_info *mtd;
int ret;
u32 i;
udelay(200);
ret = mtk_nfc_enable_clk(dev, &nfc->clk);
if (ret)
return ret;
list_for_each_entry(chip, &nfc->chips, node) {
nand = &chip->nand;
mtd = nand_to_mtd(nand);
for (i = 0; i < chip->nsels; i++) {
nand->select_chip(mtd, i);
nand->cmdfunc(mtd, NAND_CMD_RESET, -1, -1);
}
}
return 0;
}
