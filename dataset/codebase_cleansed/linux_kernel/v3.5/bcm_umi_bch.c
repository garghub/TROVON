static int bcm_umi_bch_read_page_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, uint8_t * buf,
int oob_required, int page)
{
int sectorIdx = 0;
int eccsize = chip->ecc.size;
int eccsteps = chip->ecc.steps;
uint8_t *datap = buf;
uint8_t eccCalc[NAND_ECC_NUM_BYTES];
int sectorOobSize = mtd->oobsize / eccsteps;
int stat;
unsigned int max_bitflips = 0;
for (sectorIdx = 0; sectorIdx < eccsteps;
sectorIdx++, datap += eccsize) {
if (sectorIdx > 0) {
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, sectorIdx * eccsize,
-1);
}
nand_bcm_umi_bch_enable_read_hwecc();
bcm_umi_nand_read_buf(mtd, datap, eccsize);
nand_bcm_umi_bch_pause_read_ecc_calc();
chip->cmdfunc(mtd, NAND_CMD_RNDOUT,
mtd->writesize + sectorIdx * sectorOobSize, -1);
nand_bcm_umi_bch_read_oobEcc(mtd->writesize, eccCalc,
NAND_ECC_NUM_BYTES,
chip->oob_poi +
sectorIdx * sectorOobSize);
stat =
nand_bcm_umi_bch_correct_page(datap, eccCalc,
NAND_ECC_NUM_BYTES);
if (stat < 0) {
#if defined(NAND_BCM_UMI_DEBUG)
printk(KERN_WARNING "%s uncorr_err sectorIdx=%d\n",
__func__, sectorIdx);
printk(KERN_WARNING
"%s data %02x %02x %02x %02x "
"%02x %02x %02x %02x\n",
__func__, datap[0], datap[1], datap[2], datap[3],
datap[4], datap[5], datap[6], datap[7]);
printk(KERN_WARNING
"%s ecc %02x %02x %02x %02x "
"%02x %02x %02x %02x %02x %02x "
"%02x %02x %02x\n",
__func__, eccCalc[0], eccCalc[1], eccCalc[2],
eccCalc[3], eccCalc[4], eccCalc[5], eccCalc[6],
eccCalc[7], eccCalc[8], eccCalc[9], eccCalc[10],
eccCalc[11], eccCalc[12]);
BUG();
#endif
mtd->ecc_stats.failed++;
} else {
#if defined(NAND_BCM_UMI_DEBUG)
if (stat > 0) {
printk(KERN_INFO
"%s %d correctable_errors detected\n",
__func__, stat);
}
#endif
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
}
return max_bitflips;
}
static void bcm_umi_bch_write_page_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, const uint8_t *buf, int oob_required)
{
int sectorIdx = 0;
int eccsize = chip->ecc.size;
int eccsteps = chip->ecc.steps;
const uint8_t *datap = buf;
uint8_t *oobp = chip->oob_poi;
int sectorOobSize = mtd->oobsize / eccsteps;
for (sectorIdx = 0; sectorIdx < eccsteps;
sectorIdx++, datap += eccsize, oobp += sectorOobSize) {
nand_bcm_umi_bch_enable_write_hwecc();
bcm_umi_nand_write_buf(mtd, datap, eccsize);
nand_bcm_umi_bch_write_oobEcc(mtd->writesize, oobp,
NAND_ECC_NUM_BYTES);
}
bcm_umi_nand_write_buf(mtd, chip->oob_poi, mtd->oobsize);
}
