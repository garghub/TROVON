static void amd_nand_decode_id(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
nand_decode_ext_id(chip);
if (chip->id.data[4] != 0x00 && chip->id.data[5] == 0x00 &&
chip->id.data[6] == 0x00 && chip->id.data[7] == 0x00 &&
mtd->writesize == 512) {
mtd->erasesize = 128 * 1024;
mtd->erasesize <<= ((chip->id.data[3] & 0x03) << 1);
}
}
static int amd_nand_init(struct nand_chip *chip)
{
if (nand_is_slc(chip))
chip->bbt_options |= NAND_BBT_SCAN2NDPAGE;
return 0;
}
