static void toshiba_nand_decode_id(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
nand_decode_ext_id(chip);
if (chip->id.len >= 6 && nand_is_slc(chip) &&
(chip->id.data[5] & 0x7) == 0x6 &&
!(chip->id.data[4] & 0x80) )
mtd->oobsize = 32 * mtd->writesize >> 9;
}
static int toshiba_nand_init(struct nand_chip *chip)
{
if (nand_is_slc(chip))
chip->bbt_options |= NAND_BBT_SCAN2NDPAGE;
return 0;
}
