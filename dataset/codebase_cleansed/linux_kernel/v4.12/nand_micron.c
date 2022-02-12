static int micron_nand_setup_read_retry(struct mtd_info *mtd, int retry_mode)
{
struct nand_chip *chip = mtd_to_nand(mtd);
u8 feature[ONFI_SUBFEATURE_PARAM_LEN] = {retry_mode};
return chip->onfi_set_features(mtd, chip, ONFI_FEATURE_ADDR_READ_RETRY,
feature);
}
static int micron_nand_onfi_init(struct nand_chip *chip)
{
struct nand_onfi_params *p = &chip->onfi_params;
struct nand_onfi_vendor_micron *micron = (void *)p->vendor;
if (!chip->onfi_version)
return 0;
if (le16_to_cpu(p->vendor_revision) < 1)
return 0;
chip->read_retries = micron->read_retry_options;
chip->setup_read_retry = micron_nand_setup_read_retry;
return 0;
}
static int micron_nand_init(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
int ret;
ret = micron_nand_onfi_init(chip);
if (ret)
return ret;
if (mtd->writesize == 2048)
chip->bbt_options |= NAND_BBT_SCAN2NDPAGE;
return 0;
}
