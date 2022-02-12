static void samsung_nand_decode_id(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
if (chip->id.len == 6 && !nand_is_slc(chip) &&
chip->id.data[5] != 0x00) {
u8 extid = chip->id.data[3];
mtd->writesize = 2048 << (extid & 0x03);
extid >>= 2;
switch (((extid >> 2) & 0x4) | (extid & 0x3)) {
case 1:
mtd->oobsize = 128;
break;
case 2:
mtd->oobsize = 218;
break;
case 3:
mtd->oobsize = 400;
break;
case 4:
mtd->oobsize = 436;
break;
case 5:
mtd->oobsize = 512;
break;
case 6:
mtd->oobsize = 640;
break;
default:
WARN(1, "Invalid OOB size value");
break;
}
extid >>= 2;
mtd->erasesize = (128 * 1024) <<
(((extid >> 1) & 0x04) | (extid & 0x03));
extid = (chip->id.data[4] >> 4) & 0x07;
if (extid < 5) {
chip->ecc_step_ds = 512;
chip->ecc_strength_ds = 1 << extid;
} else {
chip->ecc_step_ds = 1024;
switch (extid) {
case 5:
chip->ecc_strength_ds = 24;
break;
case 6:
chip->ecc_strength_ds = 40;
break;
case 7:
chip->ecc_strength_ds = 60;
break;
default:
WARN(1, "Could not decode ECC info");
chip->ecc_step_ds = 0;
}
}
} else {
nand_decode_ext_id(chip);
}
}
static int samsung_nand_init(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
if (mtd->writesize > 512)
chip->options |= NAND_SAMSUNG_LP_OPTIONS;
if (!nand_is_slc(chip))
chip->bbt_options |= NAND_BBT_SCANLASTPAGE;
else
chip->bbt_options |= NAND_BBT_SCAN2NDPAGE;
return 0;
}
