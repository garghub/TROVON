static int oob_sm_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
if (section > 1)
return -ERANGE;
oobregion->length = 3;
oobregion->offset = ((section + 1) * 8) - 3;
return 0;
}
static int oob_sm_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
switch (section) {
case 0:
oobregion->offset = 0;
oobregion->length = 4;
break;
case 1:
oobregion->offset = 6;
oobregion->length = 2;
break;
case 2:
oobregion->offset = 11;
oobregion->length = 2;
break;
default:
return -ERANGE;
}
return 0;
}
static int oob_sm_small_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
if (section)
return -ERANGE;
oobregion->length = 3;
oobregion->offset = 0;
return 0;
}
static int oob_sm_small_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
switch (section) {
case 0:
oobregion->offset = 3;
oobregion->length = 2;
break;
case 1:
oobregion->offset = 6;
oobregion->length = 2;
break;
default:
return -ERANGE;
}
return 0;
}
static int sm_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
struct mtd_oob_ops ops;
struct sm_oob oob;
int ret;
memset(&oob, -1, SM_OOB_SIZE);
oob.block_status = 0x0F;
ops.mode = MTD_OPS_PLACE_OOB;
ops.ooboffs = 0;
ops.ooblen = mtd->oobsize;
ops.oobbuf = (void *)&oob;
ops.datbuf = NULL;
ret = mtd_write_oob(mtd, ofs, &ops);
if (ret < 0 || ops.oobretlen != SM_OOB_SIZE) {
printk(KERN_NOTICE
"sm_common: can't mark sector at %i as bad\n",
(int)ofs);
return -EIO;
}
return 0;
}
int sm_register_device(struct mtd_info *mtd, int smartmedia)
{
struct nand_chip *chip = mtd_to_nand(mtd);
int ret;
chip->options |= NAND_SKIP_BBTSCAN;
ret = nand_scan_ident(mtd, 1, smartmedia ?
nand_smartmedia_flash_ids : nand_xd_flash_ids);
if (ret)
return ret;
chip->badblockpos = 0x05;
chip->badblockbits = 7;
chip->block_markbad = sm_block_markbad;
if (mtd->writesize == SM_SECTOR_SIZE)
mtd_set_ooblayout(mtd, &oob_sm_ops);
else if (mtd->writesize == SM_SMALL_PAGE)
mtd_set_ooblayout(mtd, &oob_sm_small_ops);
else
return -ENODEV;
ret = nand_scan_tail(mtd);
if (ret)
return ret;
return mtd_device_register(mtd, NULL, 0);
}
