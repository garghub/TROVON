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
static int micron_nand_on_die_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
if (section >= 4)
return -ERANGE;
oobregion->offset = (section * 16) + 8;
oobregion->length = 8;
return 0;
}
static int micron_nand_on_die_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
if (section >= 4)
return -ERANGE;
oobregion->offset = (section * 16) + 2;
oobregion->length = 6;
return 0;
}
static int micron_nand_on_die_ecc_setup(struct nand_chip *chip, bool enable)
{
u8 feature[ONFI_SUBFEATURE_PARAM_LEN] = { 0, };
if (enable)
feature[0] |= ONFI_FEATURE_ON_DIE_ECC_EN;
return chip->onfi_set_features(nand_to_mtd(chip), chip,
ONFI_FEATURE_ON_DIE_ECC, feature);
}
static int
micron_nand_read_page_on_die_ecc(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required,
int page)
{
int status;
int max_bitflips = 0;
micron_nand_on_die_ecc_setup(chip, true);
chip->cmdfunc(mtd, NAND_CMD_READ0, 0x00, page);
chip->cmdfunc(mtd, NAND_CMD_STATUS, -1, -1);
status = chip->read_byte(mtd);
if (status & NAND_STATUS_FAIL)
mtd->ecc_stats.failed++;
else if (status & NAND_STATUS_WRITE_RECOMMENDED)
max_bitflips = chip->ecc.strength;
chip->cmdfunc(mtd, NAND_CMD_READ0, -1, -1);
nand_read_page_raw(mtd, chip, buf, oob_required, page);
micron_nand_on_die_ecc_setup(chip, false);
return max_bitflips;
}
static int
micron_nand_write_page_on_die_ecc(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required,
int page)
{
int status;
micron_nand_on_die_ecc_setup(chip, true);
chip->cmdfunc(mtd, NAND_CMD_SEQIN, 0x00, page);
nand_write_page_raw(mtd, chip, buf, oob_required, page);
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
status = chip->waitfunc(mtd, chip);
micron_nand_on_die_ecc_setup(chip, false);
return status & NAND_STATUS_FAIL ? -EIO : 0;
}
static int
micron_nand_read_page_raw_on_die_ecc(struct mtd_info *mtd,
struct nand_chip *chip,
uint8_t *buf, int oob_required,
int page)
{
chip->cmdfunc(mtd, NAND_CMD_READ0, 0x00, page);
nand_read_page_raw(mtd, chip, buf, oob_required, page);
return 0;
}
static int
micron_nand_write_page_raw_on_die_ecc(struct mtd_info *mtd,
struct nand_chip *chip,
const uint8_t *buf, int oob_required,
int page)
{
int status;
chip->cmdfunc(mtd, NAND_CMD_SEQIN, 0x00, page);
nand_write_page_raw(mtd, chip, buf, oob_required, page);
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
status = chip->waitfunc(mtd, chip);
return status & NAND_STATUS_FAIL ? -EIO : 0;
}
static int micron_supports_on_die_ecc(struct nand_chip *chip)
{
u8 feature[ONFI_SUBFEATURE_PARAM_LEN] = { 0, };
int ret;
if (chip->onfi_version == 0)
return MICRON_ON_DIE_UNSUPPORTED;
if (chip->bits_per_cell != 1)
return MICRON_ON_DIE_UNSUPPORTED;
ret = micron_nand_on_die_ecc_setup(chip, true);
if (ret)
return MICRON_ON_DIE_UNSUPPORTED;
chip->onfi_get_features(nand_to_mtd(chip), chip,
ONFI_FEATURE_ON_DIE_ECC, feature);
if ((feature[0] & ONFI_FEATURE_ON_DIE_ECC_EN) == 0)
return MICRON_ON_DIE_UNSUPPORTED;
ret = micron_nand_on_die_ecc_setup(chip, false);
if (ret)
return MICRON_ON_DIE_UNSUPPORTED;
chip->onfi_get_features(nand_to_mtd(chip), chip,
ONFI_FEATURE_ON_DIE_ECC, feature);
if (feature[0] & ONFI_FEATURE_ON_DIE_ECC_EN)
return MICRON_ON_DIE_MANDATORY;
if (chip->onfi_params.ecc_bits != 4)
return MICRON_ON_DIE_UNSUPPORTED;
return MICRON_ON_DIE_SUPPORTED;
}
static int micron_nand_init(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
int ondie;
int ret;
ret = micron_nand_onfi_init(chip);
if (ret)
return ret;
if (mtd->writesize == 2048)
chip->bbt_options |= NAND_BBT_SCAN2NDPAGE;
ondie = micron_supports_on_die_ecc(chip);
if (ondie == MICRON_ON_DIE_MANDATORY) {
pr_err("On-die ECC forcefully enabled, not supported\n");
return -EINVAL;
}
if (chip->ecc.mode == NAND_ECC_ON_DIE) {
if (ondie == MICRON_ON_DIE_UNSUPPORTED) {
pr_err("On-die ECC selected but not supported\n");
return -EINVAL;
}
chip->ecc.options = NAND_ECC_CUSTOM_PAGE_ACCESS;
chip->ecc.bytes = 8;
chip->ecc.size = 512;
chip->ecc.strength = 4;
chip->ecc.algo = NAND_ECC_BCH;
chip->ecc.read_page = micron_nand_read_page_on_die_ecc;
chip->ecc.write_page = micron_nand_write_page_on_die_ecc;
chip->ecc.read_page_raw =
micron_nand_read_page_raw_on_die_ecc;
chip->ecc.write_page_raw =
micron_nand_write_page_raw_on_die_ecc;
mtd_set_ooblayout(mtd, &micron_nand_on_die_ooblayout_ops);
}
return 0;
}
