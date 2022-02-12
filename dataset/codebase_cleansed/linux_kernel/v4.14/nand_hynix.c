static bool hynix_nand_has_valid_jedecid(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
u8 jedecid[6] = { };
int i = 0;
chip->cmdfunc(mtd, NAND_CMD_READID, 0x40, -1);
for (i = 0; i < 5; i++)
jedecid[i] = chip->read_byte(mtd);
return !strcmp("JEDEC", jedecid);
}
static int hynix_nand_setup_read_retry(struct mtd_info *mtd, int retry_mode)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct hynix_nand *hynix = nand_get_manufacturer_data(chip);
const u8 *values;
int status;
int i;
values = hynix->read_retry->values +
(retry_mode * hynix->read_retry->nregs);
chip->cmdfunc(mtd, NAND_HYNIX_CMD_SET_PARAMS, -1, -1);
for (i = 0; i < hynix->read_retry->nregs; i++) {
int column = hynix->read_retry->regs[i];
column |= column << 8;
chip->cmdfunc(mtd, NAND_CMD_NONE, column, -1);
chip->write_byte(mtd, values[i]);
}
chip->cmdfunc(mtd, NAND_HYNIX_CMD_APPLY_PARAMS, -1, -1);
status = chip->waitfunc(mtd, chip);
if (status & NAND_STATUS_FAIL)
return -EIO;
return 0;
}
static int hynix_get_majority(const u8 *in, int repeat, u8 *out)
{
int i, j, half = repeat / 2;
for (i = 0; i < half; i++) {
int cnt = 0;
u8 val = in[i];
for (j = i + 1; j < repeat; j++) {
if (in[j] == val)
cnt++;
}
if (cnt > half) {
*out = val;
return 0;
}
}
return -EIO;
}
static int hynix_read_rr_otp(struct nand_chip *chip,
const struct hynix_read_retry_otp *info,
void *buf)
{
struct mtd_info *mtd = nand_to_mtd(chip);
int i;
chip->cmdfunc(mtd, NAND_CMD_RESET, -1, -1);
chip->cmdfunc(mtd, NAND_HYNIX_CMD_SET_PARAMS, -1, -1);
for (i = 0; i < info->nregs; i++) {
int column = info->regs[i];
column |= column << 8;
chip->cmdfunc(mtd, NAND_CMD_NONE, column, -1);
chip->write_byte(mtd, info->values[i]);
}
chip->cmdfunc(mtd, NAND_HYNIX_CMD_APPLY_PARAMS, -1, -1);
chip->cmdfunc(mtd, 0x17, -1, -1);
chip->cmdfunc(mtd, 0x04, -1, -1);
chip->cmdfunc(mtd, 0x19, -1, -1);
chip->cmdfunc(mtd, NAND_CMD_READ0, 0x0, info->page);
chip->read_buf(mtd, buf, info->size);
chip->cmdfunc(mtd, NAND_CMD_RESET, -1, -1);
chip->cmdfunc(mtd, NAND_HYNIX_CMD_SET_PARAMS, 0x38, -1);
chip->write_byte(mtd, 0x0);
chip->cmdfunc(mtd, NAND_HYNIX_CMD_APPLY_PARAMS, -1, -1);
chip->cmdfunc(mtd, NAND_CMD_READ0, 0x0, -1);
return 0;
}
static int hynix_mlc_1xnm_rr_value(const u8 *buf, int nmodes, int nregs,
int mode, int reg, bool inv, u8 *val)
{
u8 tmp[NAND_HYNIX_1XNM_RR_REPEAT];
int val_offs = (mode * nregs) + reg;
int set_size = nmodes * nregs;
int i, ret;
for (i = 0; i < NAND_HYNIX_1XNM_RR_REPEAT; i++) {
int set_offs = NAND_HYNIX_1XNM_RR_SET_OFFS(i, set_size, inv);
tmp[i] = buf[val_offs + set_offs];
}
ret = hynix_get_majority(tmp, NAND_HYNIX_1XNM_RR_REPEAT, val);
if (ret)
return ret;
if (inv)
*val = ~*val;
return 0;
}
static int hynix_mlc_1xnm_rr_init(struct nand_chip *chip,
const struct hynix_read_retry_otp *info)
{
struct hynix_nand *hynix = nand_get_manufacturer_data(chip);
struct hynix_read_retry *rr = NULL;
int ret, i, j;
u8 nregs, nmodes;
u8 *buf;
buf = kmalloc(info->size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hynix_read_rr_otp(chip, info, buf);
if (ret)
goto out;
ret = hynix_get_majority(buf, NAND_HYNIX_1XNM_RR_REPEAT,
&nmodes);
if (ret)
goto out;
ret = hynix_get_majority(buf + NAND_HYNIX_1XNM_RR_REPEAT,
NAND_HYNIX_1XNM_RR_REPEAT,
&nregs);
if (ret)
goto out;
rr = kzalloc(sizeof(*rr) + (nregs * nmodes), GFP_KERNEL);
if (!rr) {
ret = -ENOMEM;
goto out;
}
for (i = 0; i < nmodes; i++) {
for (j = 0; j < nregs; j++) {
u8 *val = rr->values + (i * nregs);
ret = hynix_mlc_1xnm_rr_value(buf, nmodes, nregs, i, j,
false, val);
if (!ret)
continue;
ret = hynix_mlc_1xnm_rr_value(buf, nmodes, nregs, i, j,
true, val);
if (ret)
goto out;
}
}
rr->nregs = nregs;
rr->regs = hynix_1xnm_mlc_read_retry_regs;
hynix->read_retry = rr;
chip->setup_read_retry = hynix_nand_setup_read_retry;
chip->read_retries = nmodes;
out:
kfree(buf);
if (ret)
kfree(rr);
return ret;
}
static int hynix_nand_rr_init(struct nand_chip *chip)
{
int i, ret = 0;
bool valid_jedecid;
valid_jedecid = hynix_nand_has_valid_jedecid(chip);
if (valid_jedecid) {
u8 nand_tech = chip->id.data[5] >> 4;
if (nand_tech == 4) {
for (i = 0; i < ARRAY_SIZE(hynix_mlc_1xnm_rr_otps);
i++) {
ret = hynix_mlc_1xnm_rr_init(chip,
hynix_mlc_1xnm_rr_otps);
if (!ret)
break;
}
}
}
if (ret)
pr_warn("failed to initialize read-retry infrastructure");
return 0;
}
static void hynix_nand_extract_oobsize(struct nand_chip *chip,
bool valid_jedecid)
{
struct mtd_info *mtd = nand_to_mtd(chip);
u8 oobsize;
oobsize = ((chip->id.data[3] >> 2) & 0x3) |
((chip->id.data[3] >> 4) & 0x4);
if (valid_jedecid) {
switch (oobsize) {
case 0:
mtd->oobsize = 2048;
break;
case 1:
mtd->oobsize = 1664;
break;
case 2:
mtd->oobsize = 1024;
break;
case 3:
mtd->oobsize = 640;
break;
default:
WARN(1, "Invalid OOB size");
break;
}
} else {
switch (oobsize) {
case 0:
mtd->oobsize = 128;
break;
case 1:
mtd->oobsize = 224;
break;
case 2:
mtd->oobsize = 448;
break;
case 3:
mtd->oobsize = 64;
break;
case 4:
mtd->oobsize = 32;
break;
case 5:
mtd->oobsize = 16;
break;
case 6:
mtd->oobsize = 640;
break;
default:
WARN(1, "Invalid OOB size");
break;
}
}
}
static void hynix_nand_extract_ecc_requirements(struct nand_chip *chip,
bool valid_jedecid)
{
u8 ecc_level = (chip->id.data[4] >> 4) & 0x7;
if (valid_jedecid) {
chip->ecc_step_ds = 1024;
switch (ecc_level) {
case 0:
chip->ecc_step_ds = 0;
chip->ecc_strength_ds = 0;
break;
case 1:
chip->ecc_strength_ds = 4;
break;
case 2:
chip->ecc_strength_ds = 24;
break;
case 3:
chip->ecc_strength_ds = 32;
break;
case 4:
chip->ecc_strength_ds = 40;
break;
case 5:
chip->ecc_strength_ds = 50;
break;
case 6:
chip->ecc_strength_ds = 60;
break;
default:
WARN(1, "Invalid ECC requirements");
}
} else {
u8 nand_tech = chip->id.data[5] & 0x7;
if (nand_tech < 3) {
if (ecc_level < 5) {
chip->ecc_step_ds = 512;
chip->ecc_strength_ds = 1 << ecc_level;
} else if (ecc_level < 7) {
if (ecc_level == 5)
chip->ecc_step_ds = 2048;
else
chip->ecc_step_ds = 1024;
chip->ecc_strength_ds = 24;
} else {
WARN(1, "Invalid ECC requirements");
}
} else {
if (!ecc_level) {
chip->ecc_step_ds = 0;
chip->ecc_strength_ds = 0;
} else if (ecc_level < 5) {
chip->ecc_step_ds = 512;
chip->ecc_strength_ds = 1 << (ecc_level - 1);
} else {
chip->ecc_step_ds = 1024;
chip->ecc_strength_ds = 24 +
(8 * (ecc_level - 5));
}
}
}
}
static void hynix_nand_extract_scrambling_requirements(struct nand_chip *chip,
bool valid_jedecid)
{
u8 nand_tech;
if (chip->bits_per_cell > 2)
chip->options |= NAND_NEED_SCRAMBLING;
if (valid_jedecid) {
nand_tech = chip->id.data[5] >> 4;
if (nand_tech > 0)
chip->options |= NAND_NEED_SCRAMBLING;
} else {
nand_tech = chip->id.data[5] & 0x7;
if (nand_tech > 2)
chip->options |= NAND_NEED_SCRAMBLING;
}
}
static void hynix_nand_decode_id(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
bool valid_jedecid;
u8 tmp;
if (chip->id.len < 6 || nand_is_slc(chip)) {
nand_decode_ext_id(chip);
return;
}
mtd->writesize = 2048 << (chip->id.data[3] & 0x03);
tmp = (chip->id.data[3] >> 4) & 0x3;
if (chip->id.data[3] & 0x80)
mtd->erasesize = SZ_1M << tmp;
else if (tmp == 3)
mtd->erasesize = SZ_512K + SZ_256K;
else
mtd->erasesize = SZ_128K << tmp;
valid_jedecid = hynix_nand_has_valid_jedecid(chip);
hynix_nand_extract_oobsize(chip, valid_jedecid);
hynix_nand_extract_ecc_requirements(chip, valid_jedecid);
hynix_nand_extract_scrambling_requirements(chip, valid_jedecid);
}
static void hynix_nand_cleanup(struct nand_chip *chip)
{
struct hynix_nand *hynix = nand_get_manufacturer_data(chip);
if (!hynix)
return;
kfree(hynix->read_retry);
kfree(hynix);
nand_set_manufacturer_data(chip, NULL);
}
static int hynix_nand_init(struct nand_chip *chip)
{
struct hynix_nand *hynix;
int ret;
if (!nand_is_slc(chip))
chip->bbt_options |= NAND_BBT_SCANLASTPAGE;
else
chip->bbt_options |= NAND_BBT_SCAN2NDPAGE;
hynix = kzalloc(sizeof(*hynix), GFP_KERNEL);
if (!hynix)
return -ENOMEM;
nand_set_manufacturer_data(chip, hynix);
ret = hynix_nand_rr_init(chip);
if (ret)
hynix_nand_cleanup(chip);
return ret;
}
