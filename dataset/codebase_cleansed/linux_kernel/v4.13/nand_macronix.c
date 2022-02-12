static int macronix_nand_init(struct nand_chip *chip)
{
if (nand_is_slc(chip))
chip->bbt_options |= NAND_BBT_SCAN2NDPAGE;
return 0;
}
