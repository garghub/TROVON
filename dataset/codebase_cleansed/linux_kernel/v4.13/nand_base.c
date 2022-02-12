static int nand_ooblayout_ecc_sp(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &chip->ecc;
if (section > 1)
return -ERANGE;
if (!section) {
oobregion->offset = 0;
if (mtd->oobsize == 16)
oobregion->length = 4;
else
oobregion->length = 3;
} else {
if (mtd->oobsize == 8)
return -ERANGE;
oobregion->offset = 6;
oobregion->length = ecc->total - 4;
}
return 0;
}
static int nand_ooblayout_free_sp(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
if (section > 1)
return -ERANGE;
if (mtd->oobsize == 16) {
if (section)
return -ERANGE;
oobregion->length = 8;
oobregion->offset = 8;
} else {
oobregion->length = 2;
if (!section)
oobregion->offset = 3;
else
oobregion->offset = 6;
}
return 0;
}
static int nand_ooblayout_ecc_lp(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &chip->ecc;
if (section)
return -ERANGE;
oobregion->length = ecc->total;
oobregion->offset = mtd->oobsize - oobregion->length;
return 0;
}
static int nand_ooblayout_free_lp(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &chip->ecc;
if (section)
return -ERANGE;
oobregion->length = mtd->oobsize - ecc->total - 2;
oobregion->offset = 2;
return 0;
}
static int nand_ooblayout_ecc_lp_hamming(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &chip->ecc;
if (section)
return -ERANGE;
switch (mtd->oobsize) {
case 64:
oobregion->offset = 40;
break;
case 128:
oobregion->offset = 80;
break;
default:
return -EINVAL;
}
oobregion->length = ecc->total;
if (oobregion->offset + oobregion->length > mtd->oobsize)
return -ERANGE;
return 0;
}
static int nand_ooblayout_free_lp_hamming(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &chip->ecc;
int ecc_offset = 0;
if (section < 0 || section > 1)
return -ERANGE;
switch (mtd->oobsize) {
case 64:
ecc_offset = 40;
break;
case 128:
ecc_offset = 80;
break;
default:
return -EINVAL;
}
if (section == 0) {
oobregion->offset = 2;
oobregion->length = ecc_offset - 2;
} else {
oobregion->offset = ecc_offset + ecc->total;
oobregion->length = mtd->oobsize - oobregion->offset;
}
return 0;
}
static int check_offs_len(struct mtd_info *mtd,
loff_t ofs, uint64_t len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
int ret = 0;
if (ofs & ((1ULL << chip->phys_erase_shift) - 1)) {
pr_debug("%s: unaligned address\n", __func__);
ret = -EINVAL;
}
if (len & ((1ULL << chip->phys_erase_shift) - 1)) {
pr_debug("%s: length not block aligned\n", __func__);
ret = -EINVAL;
}
return ret;
}
static void nand_release_device(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
spin_lock(&chip->controller->lock);
chip->controller->active = NULL;
chip->state = FL_READY;
wake_up(&chip->controller->wq);
spin_unlock(&chip->controller->lock);
}
static uint8_t nand_read_byte(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
return readb(chip->IO_ADDR_R);
}
static uint8_t nand_read_byte16(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
return (uint8_t) cpu_to_le16(readw(chip->IO_ADDR_R));
}
static u16 nand_read_word(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
return readw(chip->IO_ADDR_R);
}
static void nand_select_chip(struct mtd_info *mtd, int chipnr)
{
struct nand_chip *chip = mtd_to_nand(mtd);
switch (chipnr) {
case -1:
chip->cmd_ctrl(mtd, NAND_CMD_NONE, 0 | NAND_CTRL_CHANGE);
break;
case 0:
break;
default:
BUG();
}
}
static void nand_write_byte(struct mtd_info *mtd, uint8_t byte)
{
struct nand_chip *chip = mtd_to_nand(mtd);
chip->write_buf(mtd, &byte, 1);
}
static void nand_write_byte16(struct mtd_info *mtd, uint8_t byte)
{
struct nand_chip *chip = mtd_to_nand(mtd);
uint16_t word = byte;
chip->write_buf(mtd, (uint8_t *)&word, 2);
}
static void nand_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
iowrite8_rep(chip->IO_ADDR_W, buf, len);
}
static void nand_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
ioread8_rep(chip->IO_ADDR_R, buf, len);
}
static void nand_write_buf16(struct mtd_info *mtd, const uint8_t *buf, int len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
u16 *p = (u16 *) buf;
iowrite16_rep(chip->IO_ADDR_W, p, len >> 1);
}
static void nand_read_buf16(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
u16 *p = (u16 *) buf;
ioread16_rep(chip->IO_ADDR_R, p, len >> 1);
}
static int nand_block_bad(struct mtd_info *mtd, loff_t ofs)
{
int page, page_end, res;
struct nand_chip *chip = mtd_to_nand(mtd);
u8 bad;
if (chip->bbt_options & NAND_BBT_SCANLASTPAGE)
ofs += mtd->erasesize - mtd->writesize;
page = (int)(ofs >> chip->page_shift) & chip->pagemask;
page_end = page + (chip->bbt_options & NAND_BBT_SCAN2NDPAGE ? 2 : 1);
for (; page < page_end; page++) {
res = chip->ecc.read_oob(mtd, chip, page);
if (res)
return res;
bad = chip->oob_poi[chip->badblockpos];
if (likely(chip->badblockbits == 8))
res = bad != 0xFF;
else
res = hweight8(bad) < chip->badblockbits;
if (res)
return res;
}
return 0;
}
static int nand_default_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct mtd_oob_ops ops;
uint8_t buf[2] = { 0, 0 };
int ret = 0, res, i = 0;
memset(&ops, 0, sizeof(ops));
ops.oobbuf = buf;
ops.ooboffs = chip->badblockpos;
if (chip->options & NAND_BUSWIDTH_16) {
ops.ooboffs &= ~0x01;
ops.len = ops.ooblen = 2;
} else {
ops.len = ops.ooblen = 1;
}
ops.mode = MTD_OPS_PLACE_OOB;
if (chip->bbt_options & NAND_BBT_SCANLASTPAGE)
ofs += mtd->erasesize - mtd->writesize;
do {
res = nand_do_write_oob(mtd, ofs, &ops);
if (!ret)
ret = res;
i++;
ofs += mtd->writesize;
} while ((chip->bbt_options & NAND_BBT_SCAN2NDPAGE) && i < 2);
return ret;
}
static int nand_block_markbad_lowlevel(struct mtd_info *mtd, loff_t ofs)
{
struct nand_chip *chip = mtd_to_nand(mtd);
int res, ret = 0;
if (!(chip->bbt_options & NAND_BBT_NO_OOB_BBM)) {
struct erase_info einfo;
memset(&einfo, 0, sizeof(einfo));
einfo.mtd = mtd;
einfo.addr = ofs;
einfo.len = 1ULL << chip->phys_erase_shift;
nand_erase_nand(mtd, &einfo, 0);
nand_get_device(mtd, FL_WRITING);
ret = chip->block_markbad(mtd, ofs);
nand_release_device(mtd);
}
if (chip->bbt) {
res = nand_markbad_bbt(mtd, ofs);
if (!ret)
ret = res;
}
if (!ret)
mtd->ecc_stats.badblocks++;
return ret;
}
static int nand_check_wp(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (chip->options & NAND_BROKEN_XD)
return 0;
chip->cmdfunc(mtd, NAND_CMD_STATUS, -1, -1);
return (chip->read_byte(mtd) & NAND_STATUS_WP) ? 0 : 1;
}
static int nand_block_isreserved(struct mtd_info *mtd, loff_t ofs)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (!chip->bbt)
return 0;
return nand_isreserved_bbt(mtd, ofs);
}
static int nand_block_checkbad(struct mtd_info *mtd, loff_t ofs, int allowbbt)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (!chip->bbt)
return chip->block_bad(mtd, ofs);
return nand_isbad_bbt(mtd, ofs, allowbbt);
}
static void panic_nand_wait_ready(struct mtd_info *mtd, unsigned long timeo)
{
struct nand_chip *chip = mtd_to_nand(mtd);
int i;
for (i = 0; i < timeo; i++) {
if (chip->dev_ready(mtd))
break;
touch_softlockup_watchdog();
mdelay(1);
}
}
void nand_wait_ready(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
unsigned long timeo = 400;
if (in_interrupt() || oops_in_progress)
return panic_nand_wait_ready(mtd, timeo);
timeo = jiffies + msecs_to_jiffies(timeo);
do {
if (chip->dev_ready(mtd))
return;
cond_resched();
} while (time_before(jiffies, timeo));
if (!chip->dev_ready(mtd))
pr_warn_ratelimited("timeout while waiting for chip to become ready\n");
}
static void nand_wait_status_ready(struct mtd_info *mtd, unsigned long timeo)
{
register struct nand_chip *chip = mtd_to_nand(mtd);
timeo = jiffies + msecs_to_jiffies(timeo);
do {
if ((chip->read_byte(mtd) & NAND_STATUS_READY))
break;
touch_softlockup_watchdog();
} while (time_before(jiffies, timeo));
}
static void nand_command(struct mtd_info *mtd, unsigned int command,
int column, int page_addr)
{
register struct nand_chip *chip = mtd_to_nand(mtd);
int ctrl = NAND_CTRL_CLE | NAND_CTRL_CHANGE;
if (command == NAND_CMD_SEQIN) {
int readcmd;
if (column >= mtd->writesize) {
column -= mtd->writesize;
readcmd = NAND_CMD_READOOB;
} else if (column < 256) {
readcmd = NAND_CMD_READ0;
} else {
column -= 256;
readcmd = NAND_CMD_READ1;
}
chip->cmd_ctrl(mtd, readcmd, ctrl);
ctrl &= ~NAND_CTRL_CHANGE;
}
chip->cmd_ctrl(mtd, command, ctrl);
ctrl = NAND_CTRL_ALE | NAND_CTRL_CHANGE;
if (column != -1) {
if (chip->options & NAND_BUSWIDTH_16 &&
!nand_opcode_8bits(command))
column >>= 1;
chip->cmd_ctrl(mtd, column, ctrl);
ctrl &= ~NAND_CTRL_CHANGE;
}
if (page_addr != -1) {
chip->cmd_ctrl(mtd, page_addr, ctrl);
ctrl &= ~NAND_CTRL_CHANGE;
chip->cmd_ctrl(mtd, page_addr >> 8, ctrl);
if (chip->chipsize > (32 << 20))
chip->cmd_ctrl(mtd, page_addr >> 16, ctrl);
}
chip->cmd_ctrl(mtd, NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);
switch (command) {
case NAND_CMD_PAGEPROG:
case NAND_CMD_ERASE1:
case NAND_CMD_ERASE2:
case NAND_CMD_SEQIN:
case NAND_CMD_STATUS:
case NAND_CMD_READID:
case NAND_CMD_SET_FEATURES:
return;
case NAND_CMD_RESET:
if (chip->dev_ready)
break;
udelay(chip->chip_delay);
chip->cmd_ctrl(mtd, NAND_CMD_STATUS,
NAND_CTRL_CLE | NAND_CTRL_CHANGE);
chip->cmd_ctrl(mtd,
NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);
nand_wait_status_ready(mtd, 250);
return;
case NAND_CMD_READ0:
if (column == -1 && page_addr == -1)
return;
default:
if (!chip->dev_ready) {
udelay(chip->chip_delay);
return;
}
}
ndelay(100);
nand_wait_ready(mtd);
}
static void nand_ccs_delay(struct nand_chip *chip)
{
if (!(chip->options & NAND_WAIT_TCCS))
return;
if (chip->data_interface && chip->data_interface->timings.sdr.tCCS_min)
ndelay(chip->data_interface->timings.sdr.tCCS_min / 1000);
else
ndelay(500);
}
static void nand_command_lp(struct mtd_info *mtd, unsigned int command,
int column, int page_addr)
{
register struct nand_chip *chip = mtd_to_nand(mtd);
if (command == NAND_CMD_READOOB) {
column += mtd->writesize;
command = NAND_CMD_READ0;
}
chip->cmd_ctrl(mtd, command, NAND_NCE | NAND_CLE | NAND_CTRL_CHANGE);
if (column != -1 || page_addr != -1) {
int ctrl = NAND_CTRL_CHANGE | NAND_NCE | NAND_ALE;
if (column != -1) {
if (chip->options & NAND_BUSWIDTH_16 &&
!nand_opcode_8bits(command))
column >>= 1;
chip->cmd_ctrl(mtd, column, ctrl);
ctrl &= ~NAND_CTRL_CHANGE;
if (!nand_opcode_8bits(command))
chip->cmd_ctrl(mtd, column >> 8, ctrl);
}
if (page_addr != -1) {
chip->cmd_ctrl(mtd, page_addr, ctrl);
chip->cmd_ctrl(mtd, page_addr >> 8,
NAND_NCE | NAND_ALE);
if (chip->chipsize > (128 << 20))
chip->cmd_ctrl(mtd, page_addr >> 16,
NAND_NCE | NAND_ALE);
}
}
chip->cmd_ctrl(mtd, NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);
switch (command) {
case NAND_CMD_CACHEDPROG:
case NAND_CMD_PAGEPROG:
case NAND_CMD_ERASE1:
case NAND_CMD_ERASE2:
case NAND_CMD_SEQIN:
case NAND_CMD_STATUS:
case NAND_CMD_READID:
case NAND_CMD_SET_FEATURES:
return;
case NAND_CMD_RNDIN:
nand_ccs_delay(chip);
return;
case NAND_CMD_RESET:
if (chip->dev_ready)
break;
udelay(chip->chip_delay);
chip->cmd_ctrl(mtd, NAND_CMD_STATUS,
NAND_NCE | NAND_CLE | NAND_CTRL_CHANGE);
chip->cmd_ctrl(mtd, NAND_CMD_NONE,
NAND_NCE | NAND_CTRL_CHANGE);
nand_wait_status_ready(mtd, 250);
return;
case NAND_CMD_RNDOUT:
chip->cmd_ctrl(mtd, NAND_CMD_RNDOUTSTART,
NAND_NCE | NAND_CLE | NAND_CTRL_CHANGE);
chip->cmd_ctrl(mtd, NAND_CMD_NONE,
NAND_NCE | NAND_CTRL_CHANGE);
nand_ccs_delay(chip);
return;
case NAND_CMD_READ0:
if (column == -1 && page_addr == -1)
return;
chip->cmd_ctrl(mtd, NAND_CMD_READSTART,
NAND_NCE | NAND_CLE | NAND_CTRL_CHANGE);
chip->cmd_ctrl(mtd, NAND_CMD_NONE,
NAND_NCE | NAND_CTRL_CHANGE);
default:
if (!chip->dev_ready) {
udelay(chip->chip_delay);
return;
}
}
ndelay(100);
nand_wait_ready(mtd);
}
static void panic_nand_get_device(struct nand_chip *chip,
struct mtd_info *mtd, int new_state)
{
chip->controller->active = chip;
chip->state = new_state;
}
static int
nand_get_device(struct mtd_info *mtd, int new_state)
{
struct nand_chip *chip = mtd_to_nand(mtd);
spinlock_t *lock = &chip->controller->lock;
wait_queue_head_t *wq = &chip->controller->wq;
DECLARE_WAITQUEUE(wait, current);
retry:
spin_lock(lock);
if (!chip->controller->active)
chip->controller->active = chip;
if (chip->controller->active == chip && chip->state == FL_READY) {
chip->state = new_state;
spin_unlock(lock);
return 0;
}
if (new_state == FL_PM_SUSPENDED) {
if (chip->controller->active->state == FL_PM_SUSPENDED) {
chip->state = FL_PM_SUSPENDED;
spin_unlock(lock);
return 0;
}
}
set_current_state(TASK_UNINTERRUPTIBLE);
add_wait_queue(wq, &wait);
spin_unlock(lock);
schedule();
remove_wait_queue(wq, &wait);
goto retry;
}
static void panic_nand_wait(struct mtd_info *mtd, struct nand_chip *chip,
unsigned long timeo)
{
int i;
for (i = 0; i < timeo; i++) {
if (chip->dev_ready) {
if (chip->dev_ready(mtd))
break;
} else {
if (chip->read_byte(mtd) & NAND_STATUS_READY)
break;
}
mdelay(1);
}
}
static int nand_wait(struct mtd_info *mtd, struct nand_chip *chip)
{
int status;
unsigned long timeo = 400;
ndelay(100);
chip->cmdfunc(mtd, NAND_CMD_STATUS, -1, -1);
if (in_interrupt() || oops_in_progress)
panic_nand_wait(mtd, chip, timeo);
else {
timeo = jiffies + msecs_to_jiffies(timeo);
do {
if (chip->dev_ready) {
if (chip->dev_ready(mtd))
break;
} else {
if (chip->read_byte(mtd) & NAND_STATUS_READY)
break;
}
cond_resched();
} while (time_before(jiffies, timeo));
}
status = (int)chip->read_byte(mtd);
WARN_ON(!(status & NAND_STATUS_READY));
return status;
}
static int nand_reset_data_interface(struct nand_chip *chip, int chipnr)
{
struct mtd_info *mtd = nand_to_mtd(chip);
const struct nand_data_interface *conf;
int ret;
if (!chip->setup_data_interface)
return 0;
conf = nand_get_default_data_interface();
ret = chip->setup_data_interface(mtd, chipnr, conf);
if (ret)
pr_err("Failed to configure data interface to SDR timing mode 0\n");
return ret;
}
static int nand_setup_data_interface(struct nand_chip *chip, int chipnr)
{
struct mtd_info *mtd = nand_to_mtd(chip);
int ret;
if (!chip->setup_data_interface || !chip->data_interface)
return 0;
if (chip->onfi_version &&
(le16_to_cpu(chip->onfi_params.opt_cmd) &
ONFI_OPT_CMD_SET_GET_FEATURES)) {
u8 tmode_param[ONFI_SUBFEATURE_PARAM_LEN] = {
chip->onfi_timing_mode_default,
};
ret = chip->onfi_set_features(mtd, chip,
ONFI_FEATURE_ADDR_TIMING_MODE,
tmode_param);
if (ret)
goto err;
}
ret = chip->setup_data_interface(mtd, chipnr, chip->data_interface);
err:
return ret;
}
static int nand_init_data_interface(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
int modes, mode, ret;
if (!chip->setup_data_interface)
return 0;
modes = onfi_get_async_timing_mode(chip);
if (modes == ONFI_TIMING_MODE_UNKNOWN) {
if (!chip->onfi_timing_mode_default)
return 0;
modes = GENMASK(chip->onfi_timing_mode_default, 0);
}
chip->data_interface = kzalloc(sizeof(*chip->data_interface),
GFP_KERNEL);
if (!chip->data_interface)
return -ENOMEM;
for (mode = fls(modes) - 1; mode >= 0; mode--) {
ret = onfi_init_data_interface(chip, chip->data_interface,
NAND_SDR_IFACE, mode);
if (ret)
continue;
ret = chip->setup_data_interface(mtd,
NAND_DATA_IFACE_CHECK_ONLY,
chip->data_interface);
if (!ret) {
chip->onfi_timing_mode_default = mode;
break;
}
}
return 0;
}
static void nand_release_data_interface(struct nand_chip *chip)
{
kfree(chip->data_interface);
}
int nand_reset(struct nand_chip *chip, int chipnr)
{
struct mtd_info *mtd = nand_to_mtd(chip);
int ret;
ret = nand_reset_data_interface(chip, chipnr);
if (ret)
return ret;
chip->select_chip(mtd, chipnr);
chip->cmdfunc(mtd, NAND_CMD_RESET, -1, -1);
chip->select_chip(mtd, -1);
chip->select_chip(mtd, chipnr);
ret = nand_setup_data_interface(chip, chipnr);
chip->select_chip(mtd, -1);
if (ret)
return ret;
return 0;
}
static int __nand_unlock(struct mtd_info *mtd, loff_t ofs,
uint64_t len, int invert)
{
int ret = 0;
int status, page;
struct nand_chip *chip = mtd_to_nand(mtd);
page = ofs >> chip->page_shift;
chip->cmdfunc(mtd, NAND_CMD_UNLOCK1, -1, page & chip->pagemask);
page = (ofs + len) >> chip->page_shift;
chip->cmdfunc(mtd, NAND_CMD_UNLOCK2, -1,
(page | invert) & chip->pagemask);
status = chip->waitfunc(mtd, chip);
if (status & NAND_STATUS_FAIL) {
pr_debug("%s: error status = 0x%08x\n",
__func__, status);
ret = -EIO;
}
return ret;
}
int nand_unlock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
int ret = 0;
int chipnr;
struct nand_chip *chip = mtd_to_nand(mtd);
pr_debug("%s: start = 0x%012llx, len = %llu\n",
__func__, (unsigned long long)ofs, len);
if (check_offs_len(mtd, ofs, len))
return -EINVAL;
if (ofs + len == mtd->size)
len -= mtd->erasesize;
nand_get_device(mtd, FL_UNLOCKING);
chipnr = ofs >> chip->chip_shift;
nand_reset(chip, chipnr);
chip->select_chip(mtd, chipnr);
if (nand_check_wp(mtd)) {
pr_debug("%s: device is write protected!\n",
__func__);
ret = -EIO;
goto out;
}
ret = __nand_unlock(mtd, ofs, len, 0);
out:
chip->select_chip(mtd, -1);
nand_release_device(mtd);
return ret;
}
int nand_lock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
int ret = 0;
int chipnr, status, page;
struct nand_chip *chip = mtd_to_nand(mtd);
pr_debug("%s: start = 0x%012llx, len = %llu\n",
__func__, (unsigned long long)ofs, len);
if (check_offs_len(mtd, ofs, len))
return -EINVAL;
nand_get_device(mtd, FL_LOCKING);
chipnr = ofs >> chip->chip_shift;
nand_reset(chip, chipnr);
chip->select_chip(mtd, chipnr);
if (nand_check_wp(mtd)) {
pr_debug("%s: device is write protected!\n",
__func__);
status = MTD_ERASE_FAILED;
ret = -EIO;
goto out;
}
page = ofs >> chip->page_shift;
chip->cmdfunc(mtd, NAND_CMD_LOCK, -1, page & chip->pagemask);
status = chip->waitfunc(mtd, chip);
if (status & NAND_STATUS_FAIL) {
pr_debug("%s: error status = 0x%08x\n",
__func__, status);
ret = -EIO;
goto out;
}
ret = __nand_unlock(mtd, ofs, len, 0x1);
out:
chip->select_chip(mtd, -1);
nand_release_device(mtd);
return ret;
}
static int nand_check_erased_buf(void *buf, int len, int bitflips_threshold)
{
const unsigned char *bitmap = buf;
int bitflips = 0;
int weight;
for (; len && ((uintptr_t)bitmap) % sizeof(long);
len--, bitmap++) {
weight = hweight8(*bitmap);
bitflips += BITS_PER_BYTE - weight;
if (unlikely(bitflips > bitflips_threshold))
return -EBADMSG;
}
for (; len >= sizeof(long);
len -= sizeof(long), bitmap += sizeof(long)) {
unsigned long d = *((unsigned long *)bitmap);
if (d == ~0UL)
continue;
weight = hweight_long(d);
bitflips += BITS_PER_LONG - weight;
if (unlikely(bitflips > bitflips_threshold))
return -EBADMSG;
}
for (; len > 0; len--, bitmap++) {
weight = hweight8(*bitmap);
bitflips += BITS_PER_BYTE - weight;
if (unlikely(bitflips > bitflips_threshold))
return -EBADMSG;
}
return bitflips;
}
int nand_check_erased_ecc_chunk(void *data, int datalen,
void *ecc, int ecclen,
void *extraoob, int extraooblen,
int bitflips_threshold)
{
int data_bitflips = 0, ecc_bitflips = 0, extraoob_bitflips = 0;
data_bitflips = nand_check_erased_buf(data, datalen,
bitflips_threshold);
if (data_bitflips < 0)
return data_bitflips;
bitflips_threshold -= data_bitflips;
ecc_bitflips = nand_check_erased_buf(ecc, ecclen, bitflips_threshold);
if (ecc_bitflips < 0)
return ecc_bitflips;
bitflips_threshold -= ecc_bitflips;
extraoob_bitflips = nand_check_erased_buf(extraoob, extraooblen,
bitflips_threshold);
if (extraoob_bitflips < 0)
return extraoob_bitflips;
if (data_bitflips)
memset(data, 0xff, datalen);
if (ecc_bitflips)
memset(ecc, 0xff, ecclen);
if (extraoob_bitflips)
memset(extraoob, 0xff, extraooblen);
return data_bitflips + ecc_bitflips + extraoob_bitflips;
}
int nand_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
chip->read_buf(mtd, buf, mtd->writesize);
if (oob_required)
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int nand_read_page_raw_syndrome(struct mtd_info *mtd,
struct nand_chip *chip, uint8_t *buf,
int oob_required, int page)
{
int eccsize = chip->ecc.size;
int eccbytes = chip->ecc.bytes;
uint8_t *oob = chip->oob_poi;
int steps, size;
for (steps = chip->ecc.steps; steps > 0; steps--) {
chip->read_buf(mtd, buf, eccsize);
buf += eccsize;
if (chip->ecc.prepad) {
chip->read_buf(mtd, oob, chip->ecc.prepad);
oob += chip->ecc.prepad;
}
chip->read_buf(mtd, oob, eccbytes);
oob += eccbytes;
if (chip->ecc.postpad) {
chip->read_buf(mtd, oob, chip->ecc.postpad);
oob += chip->ecc.postpad;
}
}
size = mtd->oobsize - (oob - chip->oob_poi);
if (size)
chip->read_buf(mtd, oob, size);
return 0;
}
static int nand_read_page_swecc(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
int i, eccsize = chip->ecc.size, ret;
int eccbytes = chip->ecc.bytes;
int eccsteps = chip->ecc.steps;
uint8_t *p = buf;
uint8_t *ecc_calc = chip->buffers->ecccalc;
uint8_t *ecc_code = chip->buffers->ecccode;
unsigned int max_bitflips = 0;
chip->ecc.read_page_raw(mtd, chip, buf, 1, page);
for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize)
chip->ecc.calculate(mtd, p, &ecc_calc[i]);
ret = mtd_ooblayout_get_eccbytes(mtd, ecc_code, chip->oob_poi, 0,
chip->ecc.total);
if (ret)
return ret;
eccsteps = chip->ecc.steps;
p = buf;
for (i = 0 ; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
int stat;
stat = chip->ecc.correct(mtd, p, &ecc_code[i], &ecc_calc[i]);
if (stat < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
}
return max_bitflips;
}
static int nand_read_subpage(struct mtd_info *mtd, struct nand_chip *chip,
uint32_t data_offs, uint32_t readlen, uint8_t *bufpoi,
int page)
{
int start_step, end_step, num_steps, ret;
uint8_t *p;
int data_col_addr, i, gaps = 0;
int datafrag_len, eccfrag_len, aligned_len, aligned_pos;
int busw = (chip->options & NAND_BUSWIDTH_16) ? 2 : 1;
int index, section = 0;
unsigned int max_bitflips = 0;
struct mtd_oob_region oobregion = { };
start_step = data_offs / chip->ecc.size;
end_step = (data_offs + readlen - 1) / chip->ecc.size;
num_steps = end_step - start_step + 1;
index = start_step * chip->ecc.bytes;
datafrag_len = num_steps * chip->ecc.size;
eccfrag_len = num_steps * chip->ecc.bytes;
data_col_addr = start_step * chip->ecc.size;
if (data_col_addr != 0)
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, data_col_addr, -1);
p = bufpoi + data_col_addr;
chip->read_buf(mtd, p, datafrag_len);
for (i = 0; i < eccfrag_len ; i += chip->ecc.bytes, p += chip->ecc.size)
chip->ecc.calculate(mtd, p, &chip->buffers->ecccalc[i]);
ret = mtd_ooblayout_find_eccregion(mtd, index, &section, &oobregion);
if (ret)
return ret;
if (oobregion.length < eccfrag_len)
gaps = 1;
if (gaps) {
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, mtd->writesize, -1);
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
} else {
aligned_pos = oobregion.offset & ~(busw - 1);
aligned_len = eccfrag_len;
if (oobregion.offset & (busw - 1))
aligned_len++;
if ((oobregion.offset + (num_steps * chip->ecc.bytes)) &
(busw - 1))
aligned_len++;
chip->cmdfunc(mtd, NAND_CMD_RNDOUT,
mtd->writesize + aligned_pos, -1);
chip->read_buf(mtd, &chip->oob_poi[aligned_pos], aligned_len);
}
ret = mtd_ooblayout_get_eccbytes(mtd, chip->buffers->ecccode,
chip->oob_poi, index, eccfrag_len);
if (ret)
return ret;
p = bufpoi + data_col_addr;
for (i = 0; i < eccfrag_len ; i += chip->ecc.bytes, p += chip->ecc.size) {
int stat;
stat = chip->ecc.correct(mtd, p,
&chip->buffers->ecccode[i], &chip->buffers->ecccalc[i]);
if (stat == -EBADMSG &&
(chip->ecc.options & NAND_ECC_GENERIC_ERASED_CHECK)) {
stat = nand_check_erased_ecc_chunk(p, chip->ecc.size,
&chip->buffers->ecccode[i],
chip->ecc.bytes,
NULL, 0,
chip->ecc.strength);
}
if (stat < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
}
return max_bitflips;
}
static int nand_read_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
int i, eccsize = chip->ecc.size, ret;
int eccbytes = chip->ecc.bytes;
int eccsteps = chip->ecc.steps;
uint8_t *p = buf;
uint8_t *ecc_calc = chip->buffers->ecccalc;
uint8_t *ecc_code = chip->buffers->ecccode;
unsigned int max_bitflips = 0;
for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
chip->ecc.hwctl(mtd, NAND_ECC_READ);
chip->read_buf(mtd, p, eccsize);
chip->ecc.calculate(mtd, p, &ecc_calc[i]);
}
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
ret = mtd_ooblayout_get_eccbytes(mtd, ecc_code, chip->oob_poi, 0,
chip->ecc.total);
if (ret)
return ret;
eccsteps = chip->ecc.steps;
p = buf;
for (i = 0 ; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
int stat;
stat = chip->ecc.correct(mtd, p, &ecc_code[i], &ecc_calc[i]);
if (stat == -EBADMSG &&
(chip->ecc.options & NAND_ECC_GENERIC_ERASED_CHECK)) {
stat = nand_check_erased_ecc_chunk(p, eccsize,
&ecc_code[i], eccbytes,
NULL, 0,
chip->ecc.strength);
}
if (stat < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
}
return max_bitflips;
}
static int nand_read_page_hwecc_oob_first(struct mtd_info *mtd,
struct nand_chip *chip, uint8_t *buf, int oob_required, int page)
{
int i, eccsize = chip->ecc.size, ret;
int eccbytes = chip->ecc.bytes;
int eccsteps = chip->ecc.steps;
uint8_t *p = buf;
uint8_t *ecc_code = chip->buffers->ecccode;
uint8_t *ecc_calc = chip->buffers->ecccalc;
unsigned int max_bitflips = 0;
chip->cmdfunc(mtd, NAND_CMD_READOOB, 0, page);
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
chip->cmdfunc(mtd, NAND_CMD_READ0, 0, page);
ret = mtd_ooblayout_get_eccbytes(mtd, ecc_code, chip->oob_poi, 0,
chip->ecc.total);
if (ret)
return ret;
for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
int stat;
chip->ecc.hwctl(mtd, NAND_ECC_READ);
chip->read_buf(mtd, p, eccsize);
chip->ecc.calculate(mtd, p, &ecc_calc[i]);
stat = chip->ecc.correct(mtd, p, &ecc_code[i], NULL);
if (stat == -EBADMSG &&
(chip->ecc.options & NAND_ECC_GENERIC_ERASED_CHECK)) {
stat = nand_check_erased_ecc_chunk(p, eccsize,
&ecc_code[i], eccbytes,
NULL, 0,
chip->ecc.strength);
}
if (stat < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
}
return max_bitflips;
}
static int nand_read_page_syndrome(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
int i, eccsize = chip->ecc.size;
int eccbytes = chip->ecc.bytes;
int eccsteps = chip->ecc.steps;
int eccpadbytes = eccbytes + chip->ecc.prepad + chip->ecc.postpad;
uint8_t *p = buf;
uint8_t *oob = chip->oob_poi;
unsigned int max_bitflips = 0;
for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
int stat;
chip->ecc.hwctl(mtd, NAND_ECC_READ);
chip->read_buf(mtd, p, eccsize);
if (chip->ecc.prepad) {
chip->read_buf(mtd, oob, chip->ecc.prepad);
oob += chip->ecc.prepad;
}
chip->ecc.hwctl(mtd, NAND_ECC_READSYN);
chip->read_buf(mtd, oob, eccbytes);
stat = chip->ecc.correct(mtd, p, oob, NULL);
oob += eccbytes;
if (chip->ecc.postpad) {
chip->read_buf(mtd, oob, chip->ecc.postpad);
oob += chip->ecc.postpad;
}
if (stat == -EBADMSG &&
(chip->ecc.options & NAND_ECC_GENERIC_ERASED_CHECK)) {
stat = nand_check_erased_ecc_chunk(p, chip->ecc.size,
oob - eccpadbytes,
eccpadbytes,
NULL, 0,
chip->ecc.strength);
}
if (stat < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
}
i = mtd->oobsize - (oob - chip->oob_poi);
if (i)
chip->read_buf(mtd, oob, i);
return max_bitflips;
}
static uint8_t *nand_transfer_oob(struct mtd_info *mtd, uint8_t *oob,
struct mtd_oob_ops *ops, size_t len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
int ret;
switch (ops->mode) {
case MTD_OPS_PLACE_OOB:
case MTD_OPS_RAW:
memcpy(oob, chip->oob_poi + ops->ooboffs, len);
return oob + len;
case MTD_OPS_AUTO_OOB:
ret = mtd_ooblayout_get_databytes(mtd, oob, chip->oob_poi,
ops->ooboffs, len);
BUG_ON(ret);
return oob + len;
default:
BUG();
}
return NULL;
}
static int nand_setup_read_retry(struct mtd_info *mtd, int retry_mode)
{
struct nand_chip *chip = mtd_to_nand(mtd);
pr_debug("setting READ RETRY mode %d\n", retry_mode);
if (retry_mode >= chip->read_retries)
return -EINVAL;
if (!chip->setup_read_retry)
return -EOPNOTSUPP;
return chip->setup_read_retry(mtd, retry_mode);
}
static int nand_do_read_ops(struct mtd_info *mtd, loff_t from,
struct mtd_oob_ops *ops)
{
int chipnr, page, realpage, col, bytes, aligned, oob_required;
struct nand_chip *chip = mtd_to_nand(mtd);
int ret = 0;
uint32_t readlen = ops->len;
uint32_t oobreadlen = ops->ooblen;
uint32_t max_oobsize = mtd_oobavail(mtd, ops);
uint8_t *bufpoi, *oob, *buf;
int use_bufpoi;
unsigned int max_bitflips = 0;
int retry_mode = 0;
bool ecc_fail = false;
chipnr = (int)(from >> chip->chip_shift);
chip->select_chip(mtd, chipnr);
realpage = (int)(from >> chip->page_shift);
page = realpage & chip->pagemask;
col = (int)(from & (mtd->writesize - 1));
buf = ops->datbuf;
oob = ops->oobbuf;
oob_required = oob ? 1 : 0;
while (1) {
unsigned int ecc_failures = mtd->ecc_stats.failed;
bytes = min(mtd->writesize - col, readlen);
aligned = (bytes == mtd->writesize);
if (!aligned)
use_bufpoi = 1;
else if (chip->options & NAND_USE_BOUNCE_BUFFER)
use_bufpoi = !virt_addr_valid(buf) ||
!IS_ALIGNED((unsigned long)buf,
chip->buf_align);
else
use_bufpoi = 0;
if (realpage != chip->pagebuf || oob) {
bufpoi = use_bufpoi ? chip->buffers->databuf : buf;
if (use_bufpoi && aligned)
pr_debug("%s: using read bounce buffer for buf@%p\n",
__func__, buf);
read_retry:
if (nand_standard_page_accessors(&chip->ecc))
chip->cmdfunc(mtd, NAND_CMD_READ0, 0x00, page);
if (unlikely(ops->mode == MTD_OPS_RAW))
ret = chip->ecc.read_page_raw(mtd, chip, bufpoi,
oob_required,
page);
else if (!aligned && NAND_HAS_SUBPAGE_READ(chip) &&
!oob)
ret = chip->ecc.read_subpage(mtd, chip,
col, bytes, bufpoi,
page);
else
ret = chip->ecc.read_page(mtd, chip, bufpoi,
oob_required, page);
if (ret < 0) {
if (use_bufpoi)
chip->pagebuf = -1;
break;
}
if (use_bufpoi) {
if (!NAND_HAS_SUBPAGE_READ(chip) && !oob &&
!(mtd->ecc_stats.failed - ecc_failures) &&
(ops->mode != MTD_OPS_RAW)) {
chip->pagebuf = realpage;
chip->pagebuf_bitflips = ret;
} else {
chip->pagebuf = -1;
}
memcpy(buf, chip->buffers->databuf + col, bytes);
}
if (unlikely(oob)) {
int toread = min(oobreadlen, max_oobsize);
if (toread) {
oob = nand_transfer_oob(mtd,
oob, ops, toread);
oobreadlen -= toread;
}
}
if (chip->options & NAND_NEED_READRDY) {
if (!chip->dev_ready)
udelay(chip->chip_delay);
else
nand_wait_ready(mtd);
}
if (mtd->ecc_stats.failed - ecc_failures) {
if (retry_mode + 1 < chip->read_retries) {
retry_mode++;
ret = nand_setup_read_retry(mtd,
retry_mode);
if (ret < 0)
break;
mtd->ecc_stats.failed = ecc_failures;
goto read_retry;
} else {
ecc_fail = true;
}
}
buf += bytes;
max_bitflips = max_t(unsigned int, max_bitflips, ret);
} else {
memcpy(buf, chip->buffers->databuf + col, bytes);
buf += bytes;
max_bitflips = max_t(unsigned int, max_bitflips,
chip->pagebuf_bitflips);
}
readlen -= bytes;
if (retry_mode) {
ret = nand_setup_read_retry(mtd, 0);
if (ret < 0)
break;
retry_mode = 0;
}
if (!readlen)
break;
col = 0;
realpage++;
page = realpage & chip->pagemask;
if (!page) {
chipnr++;
chip->select_chip(mtd, -1);
chip->select_chip(mtd, chipnr);
}
}
chip->select_chip(mtd, -1);
ops->retlen = ops->len - (size_t) readlen;
if (oob)
ops->oobretlen = ops->ooblen - oobreadlen;
if (ret < 0)
return ret;
if (ecc_fail)
return -EBADMSG;
return max_bitflips;
}
static int nand_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, uint8_t *buf)
{
struct mtd_oob_ops ops;
int ret;
nand_get_device(mtd, FL_READING);
memset(&ops, 0, sizeof(ops));
ops.len = len;
ops.datbuf = buf;
ops.mode = MTD_OPS_PLACE_OOB;
ret = nand_do_read_ops(mtd, from, &ops);
*retlen = ops.retlen;
nand_release_device(mtd);
return ret;
}
int nand_read_oob_std(struct mtd_info *mtd, struct nand_chip *chip, int page)
{
chip->cmdfunc(mtd, NAND_CMD_READOOB, 0, page);
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
int nand_read_oob_syndrome(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
int length = mtd->oobsize;
int chunk = chip->ecc.bytes + chip->ecc.prepad + chip->ecc.postpad;
int eccsize = chip->ecc.size;
uint8_t *bufpoi = chip->oob_poi;
int i, toread, sndrnd = 0, pos;
chip->cmdfunc(mtd, NAND_CMD_READ0, chip->ecc.size, page);
for (i = 0; i < chip->ecc.steps; i++) {
if (sndrnd) {
pos = eccsize + i * (eccsize + chunk);
if (mtd->writesize > 512)
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, pos, -1);
else
chip->cmdfunc(mtd, NAND_CMD_READ0, pos, page);
} else
sndrnd = 1;
toread = min_t(int, length, chunk);
chip->read_buf(mtd, bufpoi, toread);
bufpoi += toread;
length -= toread;
}
if (length > 0)
chip->read_buf(mtd, bufpoi, length);
return 0;
}
int nand_write_oob_std(struct mtd_info *mtd, struct nand_chip *chip, int page)
{
int status = 0;
const uint8_t *buf = chip->oob_poi;
int length = mtd->oobsize;
chip->cmdfunc(mtd, NAND_CMD_SEQIN, mtd->writesize, page);
chip->write_buf(mtd, buf, length);
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
status = chip->waitfunc(mtd, chip);
return status & NAND_STATUS_FAIL ? -EIO : 0;
}
int nand_write_oob_syndrome(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
int chunk = chip->ecc.bytes + chip->ecc.prepad + chip->ecc.postpad;
int eccsize = chip->ecc.size, length = mtd->oobsize;
int i, len, pos, status = 0, sndcmd = 0, steps = chip->ecc.steps;
const uint8_t *bufpoi = chip->oob_poi;
if (!chip->ecc.prepad && !chip->ecc.postpad) {
pos = steps * (eccsize + chunk);
steps = 0;
} else
pos = eccsize;
chip->cmdfunc(mtd, NAND_CMD_SEQIN, pos, page);
for (i = 0; i < steps; i++) {
if (sndcmd) {
if (mtd->writesize <= 512) {
uint32_t fill = 0xFFFFFFFF;
len = eccsize;
while (len > 0) {
int num = min_t(int, len, 4);
chip->write_buf(mtd, (uint8_t *)&fill,
num);
len -= num;
}
} else {
pos = eccsize + i * (eccsize + chunk);
chip->cmdfunc(mtd, NAND_CMD_RNDIN, pos, -1);
}
} else
sndcmd = 1;
len = min_t(int, length, chunk);
chip->write_buf(mtd, bufpoi, len);
bufpoi += len;
length -= len;
}
if (length > 0)
chip->write_buf(mtd, bufpoi, length);
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
status = chip->waitfunc(mtd, chip);
return status & NAND_STATUS_FAIL ? -EIO : 0;
}
static int nand_do_read_oob(struct mtd_info *mtd, loff_t from,
struct mtd_oob_ops *ops)
{
int page, realpage, chipnr;
struct nand_chip *chip = mtd_to_nand(mtd);
struct mtd_ecc_stats stats;
int readlen = ops->ooblen;
int len;
uint8_t *buf = ops->oobbuf;
int ret = 0;
pr_debug("%s: from = 0x%08Lx, len = %i\n",
__func__, (unsigned long long)from, readlen);
stats = mtd->ecc_stats;
len = mtd_oobavail(mtd, ops);
if (unlikely(ops->ooboffs >= len)) {
pr_debug("%s: attempt to start read outside oob\n",
__func__);
return -EINVAL;
}
if (unlikely(from >= mtd->size ||
ops->ooboffs + readlen > ((mtd->size >> chip->page_shift) -
(from >> chip->page_shift)) * len)) {
pr_debug("%s: attempt to read beyond end of device\n",
__func__);
return -EINVAL;
}
chipnr = (int)(from >> chip->chip_shift);
chip->select_chip(mtd, chipnr);
realpage = (int)(from >> chip->page_shift);
page = realpage & chip->pagemask;
while (1) {
if (ops->mode == MTD_OPS_RAW)
ret = chip->ecc.read_oob_raw(mtd, chip, page);
else
ret = chip->ecc.read_oob(mtd, chip, page);
if (ret < 0)
break;
len = min(len, readlen);
buf = nand_transfer_oob(mtd, buf, ops, len);
if (chip->options & NAND_NEED_READRDY) {
if (!chip->dev_ready)
udelay(chip->chip_delay);
else
nand_wait_ready(mtd);
}
readlen -= len;
if (!readlen)
break;
realpage++;
page = realpage & chip->pagemask;
if (!page) {
chipnr++;
chip->select_chip(mtd, -1);
chip->select_chip(mtd, chipnr);
}
}
chip->select_chip(mtd, -1);
ops->oobretlen = ops->ooblen - readlen;
if (ret < 0)
return ret;
if (mtd->ecc_stats.failed - stats.failed)
return -EBADMSG;
return mtd->ecc_stats.corrected - stats.corrected ? -EUCLEAN : 0;
}
static int nand_read_oob(struct mtd_info *mtd, loff_t from,
struct mtd_oob_ops *ops)
{
int ret;
ops->retlen = 0;
if (ops->datbuf && (from + ops->len) > mtd->size) {
pr_debug("%s: attempt to read beyond end of device\n",
__func__);
return -EINVAL;
}
if (ops->mode != MTD_OPS_PLACE_OOB &&
ops->mode != MTD_OPS_AUTO_OOB &&
ops->mode != MTD_OPS_RAW)
return -ENOTSUPP;
nand_get_device(mtd, FL_READING);
if (!ops->datbuf)
ret = nand_do_read_oob(mtd, from, ops);
else
ret = nand_do_read_ops(mtd, from, ops);
nand_release_device(mtd);
return ret;
}
int nand_write_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required, int page)
{
chip->write_buf(mtd, buf, mtd->writesize);
if (oob_required)
chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int nand_write_page_raw_syndrome(struct mtd_info *mtd,
struct nand_chip *chip,
const uint8_t *buf, int oob_required,
int page)
{
int eccsize = chip->ecc.size;
int eccbytes = chip->ecc.bytes;
uint8_t *oob = chip->oob_poi;
int steps, size;
for (steps = chip->ecc.steps; steps > 0; steps--) {
chip->write_buf(mtd, buf, eccsize);
buf += eccsize;
if (chip->ecc.prepad) {
chip->write_buf(mtd, oob, chip->ecc.prepad);
oob += chip->ecc.prepad;
}
chip->write_buf(mtd, oob, eccbytes);
oob += eccbytes;
if (chip->ecc.postpad) {
chip->write_buf(mtd, oob, chip->ecc.postpad);
oob += chip->ecc.postpad;
}
}
size = mtd->oobsize - (oob - chip->oob_poi);
if (size)
chip->write_buf(mtd, oob, size);
return 0;
}
static int nand_write_page_swecc(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required,
int page)
{
int i, eccsize = chip->ecc.size, ret;
int eccbytes = chip->ecc.bytes;
int eccsteps = chip->ecc.steps;
uint8_t *ecc_calc = chip->buffers->ecccalc;
const uint8_t *p = buf;
for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize)
chip->ecc.calculate(mtd, p, &ecc_calc[i]);
ret = mtd_ooblayout_set_eccbytes(mtd, ecc_calc, chip->oob_poi, 0,
chip->ecc.total);
if (ret)
return ret;
return chip->ecc.write_page_raw(mtd, chip, buf, 1, page);
}
static int nand_write_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required,
int page)
{
int i, eccsize = chip->ecc.size, ret;
int eccbytes = chip->ecc.bytes;
int eccsteps = chip->ecc.steps;
uint8_t *ecc_calc = chip->buffers->ecccalc;
const uint8_t *p = buf;
for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
chip->ecc.hwctl(mtd, NAND_ECC_WRITE);
chip->write_buf(mtd, p, eccsize);
chip->ecc.calculate(mtd, p, &ecc_calc[i]);
}
ret = mtd_ooblayout_set_eccbytes(mtd, ecc_calc, chip->oob_poi, 0,
chip->ecc.total);
if (ret)
return ret;
chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int nand_write_subpage_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, uint32_t offset,
uint32_t data_len, const uint8_t *buf,
int oob_required, int page)
{
uint8_t *oob_buf = chip->oob_poi;
uint8_t *ecc_calc = chip->buffers->ecccalc;
int ecc_size = chip->ecc.size;
int ecc_bytes = chip->ecc.bytes;
int ecc_steps = chip->ecc.steps;
uint32_t start_step = offset / ecc_size;
uint32_t end_step = (offset + data_len - 1) / ecc_size;
int oob_bytes = mtd->oobsize / ecc_steps;
int step, ret;
for (step = 0; step < ecc_steps; step++) {
chip->ecc.hwctl(mtd, NAND_ECC_WRITE);
chip->write_buf(mtd, buf, ecc_size);
if ((step < start_step) || (step > end_step))
memset(ecc_calc, 0xff, ecc_bytes);
else
chip->ecc.calculate(mtd, buf, ecc_calc);
if (!oob_required || (step < start_step) || (step > end_step))
memset(oob_buf, 0xff, oob_bytes);
buf += ecc_size;
ecc_calc += ecc_bytes;
oob_buf += oob_bytes;
}
ecc_calc = chip->buffers->ecccalc;
ret = mtd_ooblayout_set_eccbytes(mtd, ecc_calc, chip->oob_poi, 0,
chip->ecc.total);
if (ret)
return ret;
chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int nand_write_page_syndrome(struct mtd_info *mtd,
struct nand_chip *chip,
const uint8_t *buf, int oob_required,
int page)
{
int i, eccsize = chip->ecc.size;
int eccbytes = chip->ecc.bytes;
int eccsteps = chip->ecc.steps;
const uint8_t *p = buf;
uint8_t *oob = chip->oob_poi;
for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
chip->ecc.hwctl(mtd, NAND_ECC_WRITE);
chip->write_buf(mtd, p, eccsize);
if (chip->ecc.prepad) {
chip->write_buf(mtd, oob, chip->ecc.prepad);
oob += chip->ecc.prepad;
}
chip->ecc.calculate(mtd, p, oob);
chip->write_buf(mtd, oob, eccbytes);
oob += eccbytes;
if (chip->ecc.postpad) {
chip->write_buf(mtd, oob, chip->ecc.postpad);
oob += chip->ecc.postpad;
}
}
i = mtd->oobsize - (oob - chip->oob_poi);
if (i)
chip->write_buf(mtd, oob, i);
return 0;
}
static int nand_write_page(struct mtd_info *mtd, struct nand_chip *chip,
uint32_t offset, int data_len, const uint8_t *buf,
int oob_required, int page, int raw)
{
int status, subpage;
if (!(chip->options & NAND_NO_SUBPAGE_WRITE) &&
chip->ecc.write_subpage)
subpage = offset || (data_len < mtd->writesize);
else
subpage = 0;
if (nand_standard_page_accessors(&chip->ecc))
chip->cmdfunc(mtd, NAND_CMD_SEQIN, 0x00, page);
if (unlikely(raw))
status = chip->ecc.write_page_raw(mtd, chip, buf,
oob_required, page);
else if (subpage)
status = chip->ecc.write_subpage(mtd, chip, offset, data_len,
buf, oob_required, page);
else
status = chip->ecc.write_page(mtd, chip, buf, oob_required,
page);
if (status < 0)
return status;
if (nand_standard_page_accessors(&chip->ecc)) {
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
status = chip->waitfunc(mtd, chip);
if (status & NAND_STATUS_FAIL)
return -EIO;
}
return 0;
}
static uint8_t *nand_fill_oob(struct mtd_info *mtd, uint8_t *oob, size_t len,
struct mtd_oob_ops *ops)
{
struct nand_chip *chip = mtd_to_nand(mtd);
int ret;
memset(chip->oob_poi, 0xff, mtd->oobsize);
switch (ops->mode) {
case MTD_OPS_PLACE_OOB:
case MTD_OPS_RAW:
memcpy(chip->oob_poi + ops->ooboffs, oob, len);
return oob + len;
case MTD_OPS_AUTO_OOB:
ret = mtd_ooblayout_set_databytes(mtd, oob, chip->oob_poi,
ops->ooboffs, len);
BUG_ON(ret);
return oob + len;
default:
BUG();
}
return NULL;
}
static int nand_do_write_ops(struct mtd_info *mtd, loff_t to,
struct mtd_oob_ops *ops)
{
int chipnr, realpage, page, blockmask, column;
struct nand_chip *chip = mtd_to_nand(mtd);
uint32_t writelen = ops->len;
uint32_t oobwritelen = ops->ooblen;
uint32_t oobmaxlen = mtd_oobavail(mtd, ops);
uint8_t *oob = ops->oobbuf;
uint8_t *buf = ops->datbuf;
int ret;
int oob_required = oob ? 1 : 0;
ops->retlen = 0;
if (!writelen)
return 0;
if (NOTALIGNED(to) || NOTALIGNED(ops->len)) {
pr_notice("%s: attempt to write non page aligned data\n",
__func__);
return -EINVAL;
}
column = to & (mtd->writesize - 1);
chipnr = (int)(to >> chip->chip_shift);
chip->select_chip(mtd, chipnr);
if (nand_check_wp(mtd)) {
ret = -EIO;
goto err_out;
}
realpage = (int)(to >> chip->page_shift);
page = realpage & chip->pagemask;
blockmask = (1 << (chip->phys_erase_shift - chip->page_shift)) - 1;
if (to <= ((loff_t)chip->pagebuf << chip->page_shift) &&
((loff_t)chip->pagebuf << chip->page_shift) < (to + ops->len))
chip->pagebuf = -1;
if (oob && ops->ooboffs && (ops->ooboffs + ops->ooblen > oobmaxlen)) {
ret = -EINVAL;
goto err_out;
}
while (1) {
int bytes = mtd->writesize;
uint8_t *wbuf = buf;
int use_bufpoi;
int part_pagewr = (column || writelen < mtd->writesize);
if (part_pagewr)
use_bufpoi = 1;
else if (chip->options & NAND_USE_BOUNCE_BUFFER)
use_bufpoi = !virt_addr_valid(buf) ||
!IS_ALIGNED((unsigned long)buf,
chip->buf_align);
else
use_bufpoi = 0;
if (use_bufpoi) {
pr_debug("%s: using write bounce buffer for buf@%p\n",
__func__, buf);
if (part_pagewr)
bytes = min_t(int, bytes - column, writelen);
chip->pagebuf = -1;
memset(chip->buffers->databuf, 0xff, mtd->writesize);
memcpy(&chip->buffers->databuf[column], buf, bytes);
wbuf = chip->buffers->databuf;
}
if (unlikely(oob)) {
size_t len = min(oobwritelen, oobmaxlen);
oob = nand_fill_oob(mtd, oob, len, ops);
oobwritelen -= len;
} else {
memset(chip->oob_poi, 0xff, mtd->oobsize);
}
ret = nand_write_page(mtd, chip, column, bytes, wbuf,
oob_required, page,
(ops->mode == MTD_OPS_RAW));
if (ret)
break;
writelen -= bytes;
if (!writelen)
break;
column = 0;
buf += bytes;
realpage++;
page = realpage & chip->pagemask;
if (!page) {
chipnr++;
chip->select_chip(mtd, -1);
chip->select_chip(mtd, chipnr);
}
}
ops->retlen = ops->len - writelen;
if (unlikely(oob))
ops->oobretlen = ops->ooblen;
err_out:
chip->select_chip(mtd, -1);
return ret;
}
static int panic_nand_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const uint8_t *buf)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct mtd_oob_ops ops;
int ret;
panic_nand_wait(mtd, chip, 400);
panic_nand_get_device(chip, mtd, FL_WRITING);
memset(&ops, 0, sizeof(ops));
ops.len = len;
ops.datbuf = (uint8_t *)buf;
ops.mode = MTD_OPS_PLACE_OOB;
ret = nand_do_write_ops(mtd, to, &ops);
*retlen = ops.retlen;
return ret;
}
static int nand_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const uint8_t *buf)
{
struct mtd_oob_ops ops;
int ret;
nand_get_device(mtd, FL_WRITING);
memset(&ops, 0, sizeof(ops));
ops.len = len;
ops.datbuf = (uint8_t *)buf;
ops.mode = MTD_OPS_PLACE_OOB;
ret = nand_do_write_ops(mtd, to, &ops);
*retlen = ops.retlen;
nand_release_device(mtd);
return ret;
}
static int nand_do_write_oob(struct mtd_info *mtd, loff_t to,
struct mtd_oob_ops *ops)
{
int chipnr, page, status, len;
struct nand_chip *chip = mtd_to_nand(mtd);
pr_debug("%s: to = 0x%08x, len = %i\n",
__func__, (unsigned int)to, (int)ops->ooblen);
len = mtd_oobavail(mtd, ops);
if ((ops->ooboffs + ops->ooblen) > len) {
pr_debug("%s: attempt to write past end of page\n",
__func__);
return -EINVAL;
}
if (unlikely(ops->ooboffs >= len)) {
pr_debug("%s: attempt to start write outside oob\n",
__func__);
return -EINVAL;
}
if (unlikely(to >= mtd->size ||
ops->ooboffs + ops->ooblen >
((mtd->size >> chip->page_shift) -
(to >> chip->page_shift)) * len)) {
pr_debug("%s: attempt to write beyond end of device\n",
__func__);
return -EINVAL;
}
chipnr = (int)(to >> chip->chip_shift);
nand_reset(chip, chipnr);
chip->select_chip(mtd, chipnr);
page = (int)(to >> chip->page_shift);
if (nand_check_wp(mtd)) {
chip->select_chip(mtd, -1);
return -EROFS;
}
if (page == chip->pagebuf)
chip->pagebuf = -1;
nand_fill_oob(mtd, ops->oobbuf, ops->ooblen, ops);
if (ops->mode == MTD_OPS_RAW)
status = chip->ecc.write_oob_raw(mtd, chip, page & chip->pagemask);
else
status = chip->ecc.write_oob(mtd, chip, page & chip->pagemask);
chip->select_chip(mtd, -1);
if (status)
return status;
ops->oobretlen = ops->ooblen;
return 0;
}
static int nand_write_oob(struct mtd_info *mtd, loff_t to,
struct mtd_oob_ops *ops)
{
int ret = -ENOTSUPP;
ops->retlen = 0;
if (ops->datbuf && (to + ops->len) > mtd->size) {
pr_debug("%s: attempt to write beyond end of device\n",
__func__);
return -EINVAL;
}
nand_get_device(mtd, FL_WRITING);
switch (ops->mode) {
case MTD_OPS_PLACE_OOB:
case MTD_OPS_AUTO_OOB:
case MTD_OPS_RAW:
break;
default:
goto out;
}
if (!ops->datbuf)
ret = nand_do_write_oob(mtd, to, ops);
else
ret = nand_do_write_ops(mtd, to, ops);
out:
nand_release_device(mtd);
return ret;
}
static int single_erase(struct mtd_info *mtd, int page)
{
struct nand_chip *chip = mtd_to_nand(mtd);
chip->cmdfunc(mtd, NAND_CMD_ERASE1, -1, page);
chip->cmdfunc(mtd, NAND_CMD_ERASE2, -1, -1);
return chip->waitfunc(mtd, chip);
}
static int nand_erase(struct mtd_info *mtd, struct erase_info *instr)
{
return nand_erase_nand(mtd, instr, 0);
}
int nand_erase_nand(struct mtd_info *mtd, struct erase_info *instr,
int allowbbt)
{
int page, status, pages_per_block, ret, chipnr;
struct nand_chip *chip = mtd_to_nand(mtd);
loff_t len;
pr_debug("%s: start = 0x%012llx, len = %llu\n",
__func__, (unsigned long long)instr->addr,
(unsigned long long)instr->len);
if (check_offs_len(mtd, instr->addr, instr->len))
return -EINVAL;
nand_get_device(mtd, FL_ERASING);
page = (int)(instr->addr >> chip->page_shift);
chipnr = (int)(instr->addr >> chip->chip_shift);
pages_per_block = 1 << (chip->phys_erase_shift - chip->page_shift);
chip->select_chip(mtd, chipnr);
if (nand_check_wp(mtd)) {
pr_debug("%s: device is write protected!\n",
__func__);
instr->state = MTD_ERASE_FAILED;
goto erase_exit;
}
len = instr->len;
instr->state = MTD_ERASING;
while (len) {
if (nand_block_checkbad(mtd, ((loff_t) page) <<
chip->page_shift, allowbbt)) {
pr_warn("%s: attempt to erase a bad block at page 0x%08x\n",
__func__, page);
instr->state = MTD_ERASE_FAILED;
goto erase_exit;
}
if (page <= chip->pagebuf && chip->pagebuf <
(page + pages_per_block))
chip->pagebuf = -1;
status = chip->erase(mtd, page & chip->pagemask);
if (status & NAND_STATUS_FAIL) {
pr_debug("%s: failed erase, page 0x%08x\n",
__func__, page);
instr->state = MTD_ERASE_FAILED;
instr->fail_addr =
((loff_t)page << chip->page_shift);
goto erase_exit;
}
len -= (1ULL << chip->phys_erase_shift);
page += pages_per_block;
if (len && !(page & chip->pagemask)) {
chipnr++;
chip->select_chip(mtd, -1);
chip->select_chip(mtd, chipnr);
}
}
instr->state = MTD_ERASE_DONE;
erase_exit:
ret = instr->state == MTD_ERASE_DONE ? 0 : -EIO;
chip->select_chip(mtd, -1);
nand_release_device(mtd);
if (!ret)
mtd_erase_callback(instr);
return ret;
}
static void nand_sync(struct mtd_info *mtd)
{
pr_debug("%s: called\n", __func__);
nand_get_device(mtd, FL_SYNCING);
nand_release_device(mtd);
}
static int nand_block_isbad(struct mtd_info *mtd, loff_t offs)
{
struct nand_chip *chip = mtd_to_nand(mtd);
int chipnr = (int)(offs >> chip->chip_shift);
int ret;
nand_get_device(mtd, FL_READING);
chip->select_chip(mtd, chipnr);
ret = nand_block_checkbad(mtd, offs, 0);
chip->select_chip(mtd, -1);
nand_release_device(mtd);
return ret;
}
static int nand_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
int ret;
ret = nand_block_isbad(mtd, ofs);
if (ret) {
if (ret > 0)
return 0;
return ret;
}
return nand_block_markbad_lowlevel(mtd, ofs);
}
static int nand_max_bad_blocks(struct mtd_info *mtd, loff_t ofs, size_t len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
u32 part_start_block;
u32 part_end_block;
u32 part_start_die;
u32 part_end_die;
if (!chip->max_bb_per_die || !chip->blocks_per_die)
return -ENOTSUPP;
part_start_block = mtd_div_by_eb(ofs, mtd);
part_end_block = mtd_div_by_eb(len, mtd) + part_start_block - 1;
part_start_die = part_start_block / chip->blocks_per_die;
part_end_die = part_end_block / chip->blocks_per_die;
return chip->max_bb_per_die * (part_end_die - part_start_die + 1);
}
static int nand_onfi_set_features(struct mtd_info *mtd, struct nand_chip *chip,
int addr, uint8_t *subfeature_param)
{
int status;
int i;
if (!chip->onfi_version ||
!(le16_to_cpu(chip->onfi_params.opt_cmd)
& ONFI_OPT_CMD_SET_GET_FEATURES))
return -EINVAL;
chip->cmdfunc(mtd, NAND_CMD_SET_FEATURES, addr, -1);
for (i = 0; i < ONFI_SUBFEATURE_PARAM_LEN; ++i)
chip->write_byte(mtd, subfeature_param[i]);
status = chip->waitfunc(mtd, chip);
if (status & NAND_STATUS_FAIL)
return -EIO;
return 0;
}
static int nand_onfi_get_features(struct mtd_info *mtd, struct nand_chip *chip,
int addr, uint8_t *subfeature_param)
{
int i;
if (!chip->onfi_version ||
!(le16_to_cpu(chip->onfi_params.opt_cmd)
& ONFI_OPT_CMD_SET_GET_FEATURES))
return -EINVAL;
chip->cmdfunc(mtd, NAND_CMD_GET_FEATURES, addr, -1);
for (i = 0; i < ONFI_SUBFEATURE_PARAM_LEN; ++i)
*subfeature_param++ = chip->read_byte(mtd);
return 0;
}
int nand_onfi_get_set_features_notsupp(struct mtd_info *mtd,
struct nand_chip *chip, int addr,
u8 *subfeature_param)
{
return -ENOTSUPP;
}
static int nand_suspend(struct mtd_info *mtd)
{
return nand_get_device(mtd, FL_PM_SUSPENDED);
}
static void nand_resume(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (chip->state == FL_PM_SUSPENDED)
nand_release_device(mtd);
else
pr_err("%s called for a chip which is not in suspended state\n",
__func__);
}
static void nand_shutdown(struct mtd_info *mtd)
{
nand_get_device(mtd, FL_PM_SUSPENDED);
}
static void nand_set_defaults(struct nand_chip *chip)
{
unsigned int busw = chip->options & NAND_BUSWIDTH_16;
if (!chip->chip_delay)
chip->chip_delay = 20;
if (chip->cmdfunc == NULL)
chip->cmdfunc = nand_command;
if (chip->waitfunc == NULL)
chip->waitfunc = nand_wait;
if (!chip->select_chip)
chip->select_chip = nand_select_chip;
if (!chip->onfi_set_features)
chip->onfi_set_features = nand_onfi_set_features;
if (!chip->onfi_get_features)
chip->onfi_get_features = nand_onfi_get_features;
if (!chip->read_byte || chip->read_byte == nand_read_byte)
chip->read_byte = busw ? nand_read_byte16 : nand_read_byte;
if (!chip->read_word)
chip->read_word = nand_read_word;
if (!chip->block_bad)
chip->block_bad = nand_block_bad;
if (!chip->block_markbad)
chip->block_markbad = nand_default_block_markbad;
if (!chip->write_buf || chip->write_buf == nand_write_buf)
chip->write_buf = busw ? nand_write_buf16 : nand_write_buf;
if (!chip->write_byte || chip->write_byte == nand_write_byte)
chip->write_byte = busw ? nand_write_byte16 : nand_write_byte;
if (!chip->read_buf || chip->read_buf == nand_read_buf)
chip->read_buf = busw ? nand_read_buf16 : nand_read_buf;
if (!chip->scan_bbt)
chip->scan_bbt = nand_default_bbt;
if (!chip->controller) {
chip->controller = &chip->hwcontrol;
nand_hw_control_init(chip->controller);
}
if (!chip->buf_align)
chip->buf_align = 1;
}
static void sanitize_string(uint8_t *s, size_t len)
{
ssize_t i;
s[len - 1] = 0;
for (i = 0; i < len - 1; i++) {
if (s[i] < ' ' || s[i] > 127)
s[i] = '?';
}
strim(s);
}
static u16 onfi_crc16(u16 crc, u8 const *p, size_t len)
{
int i;
while (len--) {
crc ^= *p++ << 8;
for (i = 0; i < 8; i++)
crc = (crc << 1) ^ ((crc & 0x8000) ? 0x8005 : 0);
}
return crc;
}
static int nand_flash_detect_ext_param_page(struct nand_chip *chip,
struct nand_onfi_params *p)
{
struct mtd_info *mtd = nand_to_mtd(chip);
struct onfi_ext_param_page *ep;
struct onfi_ext_section *s;
struct onfi_ext_ecc_info *ecc;
uint8_t *cursor;
int ret = -EINVAL;
int len;
int i;
len = le16_to_cpu(p->ext_param_page_length) * 16;
ep = kmalloc(len, GFP_KERNEL);
if (!ep)
return -ENOMEM;
chip->cmdfunc(mtd, NAND_CMD_PARAM, 0, -1);
chip->cmdfunc(mtd, NAND_CMD_RNDOUT,
sizeof(*p) * p->num_of_param_pages , -1);
chip->read_buf(mtd, (uint8_t *)ep, len);
if ((onfi_crc16(ONFI_CRC_BASE, ((uint8_t *)ep) + 2, len - 2)
!= le16_to_cpu(ep->crc))) {
pr_debug("fail in the CRC.\n");
goto ext_out;
}
if (strncmp(ep->sig, "EPPS", 4)) {
pr_debug("The signature is invalid.\n");
goto ext_out;
}
cursor = (uint8_t *)(ep + 1);
for (i = 0; i < ONFI_EXT_SECTION_MAX; i++) {
s = ep->sections + i;
if (s->type == ONFI_SECTION_TYPE_2)
break;
cursor += s->length * 16;
}
if (i == ONFI_EXT_SECTION_MAX) {
pr_debug("We can not find the ECC section.\n");
goto ext_out;
}
ecc = (struct onfi_ext_ecc_info *)cursor;
if (!ecc->codeword_size) {
pr_debug("Invalid codeword size\n");
goto ext_out;
}
chip->ecc_strength_ds = ecc->ecc_bits;
chip->ecc_step_ds = 1 << ecc->codeword_size;
ret = 0;
ext_out:
kfree(ep);
return ret;
}
static int nand_flash_detect_onfi(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
struct nand_onfi_params *p = &chip->onfi_params;
int i, j;
int val;
chip->cmdfunc(mtd, NAND_CMD_READID, 0x20, -1);
if (chip->read_byte(mtd) != 'O' || chip->read_byte(mtd) != 'N' ||
chip->read_byte(mtd) != 'F' || chip->read_byte(mtd) != 'I')
return 0;
chip->cmdfunc(mtd, NAND_CMD_PARAM, 0, -1);
for (i = 0; i < 3; i++) {
for (j = 0; j < sizeof(*p); j++)
((uint8_t *)p)[j] = chip->read_byte(mtd);
if (onfi_crc16(ONFI_CRC_BASE, (uint8_t *)p, 254) ==
le16_to_cpu(p->crc)) {
break;
}
}
if (i == 3) {
pr_err("Could not find valid ONFI parameter page; aborting\n");
return 0;
}
val = le16_to_cpu(p->revision);
if (val & (1 << 5))
chip->onfi_version = 23;
else if (val & (1 << 4))
chip->onfi_version = 22;
else if (val & (1 << 3))
chip->onfi_version = 21;
else if (val & (1 << 2))
chip->onfi_version = 20;
else if (val & (1 << 1))
chip->onfi_version = 10;
if (!chip->onfi_version) {
pr_info("unsupported ONFI version: %d\n", val);
return 0;
}
sanitize_string(p->manufacturer, sizeof(p->manufacturer));
sanitize_string(p->model, sizeof(p->model));
if (!mtd->name)
mtd->name = p->model;
mtd->writesize = le32_to_cpu(p->byte_per_page);
mtd->erasesize = 1 << (fls(le32_to_cpu(p->pages_per_block)) - 1);
mtd->erasesize *= mtd->writesize;
mtd->oobsize = le16_to_cpu(p->spare_bytes_per_page);
chip->chipsize = 1 << (fls(le32_to_cpu(p->blocks_per_lun)) - 1);
chip->chipsize *= (uint64_t)mtd->erasesize * p->lun_count;
chip->bits_per_cell = p->bits_per_cell;
chip->max_bb_per_die = le16_to_cpu(p->bb_per_lun);
chip->blocks_per_die = le32_to_cpu(p->blocks_per_lun);
if (onfi_feature(chip) & ONFI_FEATURE_16_BIT_BUS)
chip->options |= NAND_BUSWIDTH_16;
if (p->ecc_bits != 0xff) {
chip->ecc_strength_ds = p->ecc_bits;
chip->ecc_step_ds = 512;
} else if (chip->onfi_version >= 21 &&
(onfi_feature(chip) & ONFI_FEATURE_EXT_PARAM_PAGE)) {
if (mtd->writesize > 512 && chip->cmdfunc == nand_command)
chip->cmdfunc = nand_command_lp;
if (nand_flash_detect_ext_param_page(chip, p))
pr_warn("Failed to detect ONFI extended param page\n");
} else {
pr_warn("Could not retrieve ONFI ECC requirements\n");
}
return 1;
}
static int nand_flash_detect_jedec(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
struct nand_jedec_params *p = &chip->jedec_params;
struct jedec_ecc_info *ecc;
int val;
int i, j;
chip->cmdfunc(mtd, NAND_CMD_READID, 0x40, -1);
if (chip->read_byte(mtd) != 'J' || chip->read_byte(mtd) != 'E' ||
chip->read_byte(mtd) != 'D' || chip->read_byte(mtd) != 'E' ||
chip->read_byte(mtd) != 'C')
return 0;
chip->cmdfunc(mtd, NAND_CMD_PARAM, 0x40, -1);
for (i = 0; i < 3; i++) {
for (j = 0; j < sizeof(*p); j++)
((uint8_t *)p)[j] = chip->read_byte(mtd);
if (onfi_crc16(ONFI_CRC_BASE, (uint8_t *)p, 510) ==
le16_to_cpu(p->crc))
break;
}
if (i == 3) {
pr_err("Could not find valid JEDEC parameter page; aborting\n");
return 0;
}
val = le16_to_cpu(p->revision);
if (val & (1 << 2))
chip->jedec_version = 10;
else if (val & (1 << 1))
chip->jedec_version = 1;
if (!chip->jedec_version) {
pr_info("unsupported JEDEC version: %d\n", val);
return 0;
}
sanitize_string(p->manufacturer, sizeof(p->manufacturer));
sanitize_string(p->model, sizeof(p->model));
if (!mtd->name)
mtd->name = p->model;
mtd->writesize = le32_to_cpu(p->byte_per_page);
mtd->erasesize = 1 << (fls(le32_to_cpu(p->pages_per_block)) - 1);
mtd->erasesize *= mtd->writesize;
mtd->oobsize = le16_to_cpu(p->spare_bytes_per_page);
chip->chipsize = 1 << (fls(le32_to_cpu(p->blocks_per_lun)) - 1);
chip->chipsize *= (uint64_t)mtd->erasesize * p->lun_count;
chip->bits_per_cell = p->bits_per_cell;
if (jedec_feature(chip) & JEDEC_FEATURE_16_BIT_BUS)
chip->options |= NAND_BUSWIDTH_16;
ecc = &p->ecc_info[0];
if (ecc->codeword_size >= 9) {
chip->ecc_strength_ds = ecc->ecc_bits;
chip->ecc_step_ds = 1 << ecc->codeword_size;
} else {
pr_warn("Invalid codeword size\n");
}
return 1;
}
static int nand_id_has_period(u8 *id_data, int arrlen, int period)
{
int i, j;
for (i = 0; i < period; i++)
for (j = i + period; j < arrlen; j += period)
if (id_data[i] != id_data[j])
return 0;
return 1;
}
static int nand_id_len(u8 *id_data, int arrlen)
{
int last_nonzero, period;
for (last_nonzero = arrlen - 1; last_nonzero >= 0; last_nonzero--)
if (id_data[last_nonzero])
break;
if (last_nonzero < 0)
return 0;
for (period = 1; period < arrlen; period++)
if (nand_id_has_period(id_data, arrlen, period))
break;
if (period < arrlen)
return period;
if (last_nonzero < arrlen - 1)
return last_nonzero + 1;
return arrlen;
}
static int nand_get_bits_per_cell(u8 cellinfo)
{
int bits;
bits = cellinfo & NAND_CI_CELLTYPE_MSK;
bits >>= NAND_CI_CELLTYPE_SHIFT;
return bits + 1;
}
void nand_decode_ext_id(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
int extid;
u8 *id_data = chip->id.data;
chip->bits_per_cell = nand_get_bits_per_cell(id_data[2]);
extid = id_data[3];
mtd->writesize = 1024 << (extid & 0x03);
extid >>= 2;
mtd->oobsize = (8 << (extid & 0x01)) * (mtd->writesize >> 9);
extid >>= 2;
mtd->erasesize = (64 * 1024) << (extid & 0x03);
extid >>= 2;
if (extid & 0x1)
chip->options |= NAND_BUSWIDTH_16;
}
static void nand_decode_id(struct nand_chip *chip, struct nand_flash_dev *type)
{
struct mtd_info *mtd = nand_to_mtd(chip);
mtd->erasesize = type->erasesize;
mtd->writesize = type->pagesize;
mtd->oobsize = mtd->writesize / 32;
chip->bits_per_cell = 1;
}
static void nand_decode_bbm_options(struct nand_chip *chip)
{
struct mtd_info *mtd = nand_to_mtd(chip);
if (mtd->writesize > 512 || (chip->options & NAND_BUSWIDTH_16))
chip->badblockpos = NAND_LARGE_BADBLOCK_POS;
else
chip->badblockpos = NAND_SMALL_BADBLOCK_POS;
}
static inline bool is_full_id_nand(struct nand_flash_dev *type)
{
return type->id_len;
}
static bool find_full_id_nand(struct nand_chip *chip,
struct nand_flash_dev *type)
{
struct mtd_info *mtd = nand_to_mtd(chip);
u8 *id_data = chip->id.data;
if (!strncmp(type->id, id_data, type->id_len)) {
mtd->writesize = type->pagesize;
mtd->erasesize = type->erasesize;
mtd->oobsize = type->oobsize;
chip->bits_per_cell = nand_get_bits_per_cell(id_data[2]);
chip->chipsize = (uint64_t)type->chipsize << 20;
chip->options |= type->options;
chip->ecc_strength_ds = NAND_ECC_STRENGTH(type);
chip->ecc_step_ds = NAND_ECC_STEP(type);
chip->onfi_timing_mode_default =
type->onfi_timing_mode_default;
if (!mtd->name)
mtd->name = type->name;
return true;
}
return false;
}
static void nand_manufacturer_detect(struct nand_chip *chip)
{
if (chip->manufacturer.desc && chip->manufacturer.desc->ops &&
chip->manufacturer.desc->ops->detect)
chip->manufacturer.desc->ops->detect(chip);
else
nand_decode_ext_id(chip);
}
static int nand_manufacturer_init(struct nand_chip *chip)
{
if (!chip->manufacturer.desc || !chip->manufacturer.desc->ops ||
!chip->manufacturer.desc->ops->init)
return 0;
return chip->manufacturer.desc->ops->init(chip);
}
static void nand_manufacturer_cleanup(struct nand_chip *chip)
{
if (chip->manufacturer.desc && chip->manufacturer.desc->ops &&
chip->manufacturer.desc->ops->cleanup)
chip->manufacturer.desc->ops->cleanup(chip);
}
static int nand_detect(struct nand_chip *chip, struct nand_flash_dev *type)
{
const struct nand_manufacturer *manufacturer;
struct mtd_info *mtd = nand_to_mtd(chip);
int busw;
int i, ret;
u8 *id_data = chip->id.data;
u8 maf_id, dev_id;
nand_reset(chip, 0);
chip->select_chip(mtd, 0);
chip->cmdfunc(mtd, NAND_CMD_READID, 0x00, -1);
maf_id = chip->read_byte(mtd);
dev_id = chip->read_byte(mtd);
chip->cmdfunc(mtd, NAND_CMD_READID, 0x00, -1);
for (i = 0; i < 8; i++)
id_data[i] = chip->read_byte(mtd);
if (id_data[0] != maf_id || id_data[1] != dev_id) {
pr_info("second ID read did not match %02x,%02x against %02x,%02x\n",
maf_id, dev_id, id_data[0], id_data[1]);
return -ENODEV;
}
chip->id.len = nand_id_len(id_data, 8);
manufacturer = nand_get_manufacturer(maf_id);
chip->manufacturer.desc = manufacturer;
if (!type)
type = nand_flash_ids;
busw = chip->options & NAND_BUSWIDTH_16;
chip->options &= ~NAND_BUSWIDTH_16;
for (; type->name != NULL; type++) {
if (is_full_id_nand(type)) {
if (find_full_id_nand(chip, type))
goto ident_done;
} else if (dev_id == type->dev_id) {
break;
}
}
chip->onfi_version = 0;
if (!type->name || !type->pagesize) {
if (nand_flash_detect_onfi(chip))
goto ident_done;
if (nand_flash_detect_jedec(chip))
goto ident_done;
}
if (!type->name)
return -ENODEV;
if (!mtd->name)
mtd->name = type->name;
chip->chipsize = (uint64_t)type->chipsize << 20;
if (!type->pagesize)
nand_manufacturer_detect(chip);
else
nand_decode_id(chip, type);
chip->options |= type->options;
ident_done:
if (chip->options & NAND_BUSWIDTH_AUTO) {
WARN_ON(busw & NAND_BUSWIDTH_16);
nand_set_defaults(chip);
} else if (busw != (chip->options & NAND_BUSWIDTH_16)) {
pr_info("device found, Manufacturer ID: 0x%02x, Chip ID: 0x%02x\n",
maf_id, dev_id);
pr_info("%s %s\n", nand_manufacturer_name(manufacturer),
mtd->name);
pr_warn("bus width %d instead of %d bits\n", busw ? 16 : 8,
(chip->options & NAND_BUSWIDTH_16) ? 16 : 8);
return -EINVAL;
}
nand_decode_bbm_options(chip);
chip->page_shift = ffs(mtd->writesize) - 1;
chip->pagemask = (chip->chipsize >> chip->page_shift) - 1;
chip->bbt_erase_shift = chip->phys_erase_shift =
ffs(mtd->erasesize) - 1;
if (chip->chipsize & 0xffffffff)
chip->chip_shift = ffs((unsigned)chip->chipsize) - 1;
else {
chip->chip_shift = ffs((unsigned)(chip->chipsize >> 32));
chip->chip_shift += 32 - 1;
}
chip->badblockbits = 8;
chip->erase = single_erase;
if (mtd->writesize > 512 && chip->cmdfunc == nand_command)
chip->cmdfunc = nand_command_lp;
ret = nand_manufacturer_init(chip);
if (ret)
return ret;
pr_info("device found, Manufacturer ID: 0x%02x, Chip ID: 0x%02x\n",
maf_id, dev_id);
if (chip->onfi_version)
pr_info("%s %s\n", nand_manufacturer_name(manufacturer),
chip->onfi_params.model);
else if (chip->jedec_version)
pr_info("%s %s\n", nand_manufacturer_name(manufacturer),
chip->jedec_params.model);
else
pr_info("%s %s\n", nand_manufacturer_name(manufacturer),
type->name);
pr_info("%d MiB, %s, erase size: %d KiB, page size: %d, OOB size: %d\n",
(int)(chip->chipsize >> 20), nand_is_slc(chip) ? "SLC" : "MLC",
mtd->erasesize >> 10, mtd->writesize, mtd->oobsize);
return 0;
}
static int of_get_nand_ecc_mode(struct device_node *np)
{
const char *pm;
int err, i;
err = of_property_read_string(np, "nand-ecc-mode", &pm);
if (err < 0)
return err;
for (i = 0; i < ARRAY_SIZE(nand_ecc_modes); i++)
if (!strcasecmp(pm, nand_ecc_modes[i]))
return i;
if (!strcasecmp(pm, "soft_bch"))
return NAND_ECC_SOFT;
return -ENODEV;
}
static int of_get_nand_ecc_algo(struct device_node *np)
{
const char *pm;
int err, i;
err = of_property_read_string(np, "nand-ecc-algo", &pm);
if (!err) {
for (i = NAND_ECC_HAMMING; i < ARRAY_SIZE(nand_ecc_algos); i++)
if (!strcasecmp(pm, nand_ecc_algos[i]))
return i;
return -ENODEV;
}
err = of_property_read_string(np, "nand-ecc-mode", &pm);
if (err < 0)
return err;
if (!strcasecmp(pm, "soft"))
return NAND_ECC_HAMMING;
else if (!strcasecmp(pm, "soft_bch"))
return NAND_ECC_BCH;
return -ENODEV;
}
static int of_get_nand_ecc_step_size(struct device_node *np)
{
int ret;
u32 val;
ret = of_property_read_u32(np, "nand-ecc-step-size", &val);
return ret ? ret : val;
}
static int of_get_nand_ecc_strength(struct device_node *np)
{
int ret;
u32 val;
ret = of_property_read_u32(np, "nand-ecc-strength", &val);
return ret ? ret : val;
}
static int of_get_nand_bus_width(struct device_node *np)
{
u32 val;
if (of_property_read_u32(np, "nand-bus-width", &val))
return 8;
switch (val) {
case 8:
case 16:
return val;
default:
return -EIO;
}
}
static bool of_get_nand_on_flash_bbt(struct device_node *np)
{
return of_property_read_bool(np, "nand-on-flash-bbt");
}
static int nand_dt_init(struct nand_chip *chip)
{
struct device_node *dn = nand_get_flash_node(chip);
int ecc_mode, ecc_algo, ecc_strength, ecc_step;
if (!dn)
return 0;
if (of_get_nand_bus_width(dn) == 16)
chip->options |= NAND_BUSWIDTH_16;
if (of_get_nand_on_flash_bbt(dn))
chip->bbt_options |= NAND_BBT_USE_FLASH;
ecc_mode = of_get_nand_ecc_mode(dn);
ecc_algo = of_get_nand_ecc_algo(dn);
ecc_strength = of_get_nand_ecc_strength(dn);
ecc_step = of_get_nand_ecc_step_size(dn);
if (ecc_mode >= 0)
chip->ecc.mode = ecc_mode;
if (ecc_algo >= 0)
chip->ecc.algo = ecc_algo;
if (ecc_strength >= 0)
chip->ecc.strength = ecc_strength;
if (ecc_step > 0)
chip->ecc.size = ecc_step;
if (of_property_read_bool(dn, "nand-ecc-maximize"))
chip->ecc.options |= NAND_ECC_MAXIMIZE;
return 0;
}
int nand_scan_ident(struct mtd_info *mtd, int maxchips,
struct nand_flash_dev *table)
{
int i, nand_maf_id, nand_dev_id;
struct nand_chip *chip = mtd_to_nand(mtd);
int ret;
ret = nand_dt_init(chip);
if (ret)
return ret;
if (!mtd->name && mtd->dev.parent)
mtd->name = dev_name(mtd->dev.parent);
if ((!chip->cmdfunc || !chip->select_chip) && !chip->cmd_ctrl) {
pr_err("chip.cmd_ctrl() callback is not provided");
return -EINVAL;
}
nand_set_defaults(chip);
ret = nand_detect(chip, table);
if (ret) {
if (!(chip->options & NAND_SCAN_SILENT_NODEV))
pr_warn("No NAND device found\n");
chip->select_chip(mtd, -1);
return ret;
}
ret = nand_init_data_interface(chip);
if (ret)
goto err_nand_init;
ret = nand_setup_data_interface(chip, 0);
if (ret)
goto err_nand_init;
nand_maf_id = chip->id.data[0];
nand_dev_id = chip->id.data[1];
chip->select_chip(mtd, -1);
for (i = 1; i < maxchips; i++) {
nand_reset(chip, i);
chip->select_chip(mtd, i);
chip->cmdfunc(mtd, NAND_CMD_READID, 0x00, -1);
if (nand_maf_id != chip->read_byte(mtd) ||
nand_dev_id != chip->read_byte(mtd)) {
chip->select_chip(mtd, -1);
break;
}
chip->select_chip(mtd, -1);
}
if (i > 1)
pr_info("%d chips detected\n", i);
chip->numchips = i;
mtd->size = i * chip->chipsize;
return 0;
err_nand_init:
nand_manufacturer_cleanup(chip);
return ret;
}
static int nand_set_ecc_soft_ops(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &chip->ecc;
if (WARN_ON(ecc->mode != NAND_ECC_SOFT))
return -EINVAL;
switch (ecc->algo) {
case NAND_ECC_HAMMING:
ecc->calculate = nand_calculate_ecc;
ecc->correct = nand_correct_data;
ecc->read_page = nand_read_page_swecc;
ecc->read_subpage = nand_read_subpage;
ecc->write_page = nand_write_page_swecc;
ecc->read_page_raw = nand_read_page_raw;
ecc->write_page_raw = nand_write_page_raw;
ecc->read_oob = nand_read_oob_std;
ecc->write_oob = nand_write_oob_std;
if (!ecc->size)
ecc->size = 256;
ecc->bytes = 3;
ecc->strength = 1;
return 0;
case NAND_ECC_BCH:
if (!mtd_nand_has_bch()) {
WARN(1, "CONFIG_MTD_NAND_ECC_BCH not enabled\n");
return -EINVAL;
}
ecc->calculate = nand_bch_calculate_ecc;
ecc->correct = nand_bch_correct_data;
ecc->read_page = nand_read_page_swecc;
ecc->read_subpage = nand_read_subpage;
ecc->write_page = nand_write_page_swecc;
ecc->read_page_raw = nand_read_page_raw;
ecc->write_page_raw = nand_write_page_raw;
ecc->read_oob = nand_read_oob_std;
ecc->write_oob = nand_write_oob_std;
if (!ecc->size && (mtd->oobsize >= 64)) {
ecc->size = 512;
ecc->strength = 4;
}
if (!mtd->ooblayout) {
if (mtd->oobsize < 64) {
WARN(1, "OOB layout is required when using software BCH on small pages\n");
return -EINVAL;
}
mtd_set_ooblayout(mtd, &nand_ooblayout_lp_ops);
}
if (mtd->ooblayout == &nand_ooblayout_lp_ops &&
ecc->options & NAND_ECC_MAXIMIZE) {
int steps, bytes;
ecc->size = 1024;
steps = mtd->writesize / ecc->size;
bytes = (mtd->oobsize - 2) / steps;
ecc->strength = bytes * 8 / fls(8 * ecc->size);
}
ecc->bytes = 0;
ecc->priv = nand_bch_init(mtd);
if (!ecc->priv) {
WARN(1, "BCH ECC initialization failed!\n");
return -EINVAL;
}
return 0;
default:
WARN(1, "Unsupported ECC algorithm!\n");
return -EINVAL;
}
}
int nand_check_ecc_caps(struct nand_chip *chip,
const struct nand_ecc_caps *caps, int oobavail)
{
struct mtd_info *mtd = nand_to_mtd(chip);
const struct nand_ecc_step_info *stepinfo;
int preset_step = chip->ecc.size;
int preset_strength = chip->ecc.strength;
int nsteps, ecc_bytes;
int i, j;
if (WARN_ON(oobavail < 0))
return -EINVAL;
if (!preset_step || !preset_strength)
return -ENODATA;
nsteps = mtd->writesize / preset_step;
for (i = 0; i < caps->nstepinfos; i++) {
stepinfo = &caps->stepinfos[i];
if (stepinfo->stepsize != preset_step)
continue;
for (j = 0; j < stepinfo->nstrengths; j++) {
if (stepinfo->strengths[j] != preset_strength)
continue;
ecc_bytes = caps->calc_ecc_bytes(preset_step,
preset_strength);
if (WARN_ON_ONCE(ecc_bytes < 0))
return ecc_bytes;
if (ecc_bytes * nsteps > oobavail) {
pr_err("ECC (step, strength) = (%d, %d) does not fit in OOB",
preset_step, preset_strength);
return -ENOSPC;
}
chip->ecc.bytes = ecc_bytes;
return 0;
}
}
pr_err("ECC (step, strength) = (%d, %d) not supported on this controller",
preset_step, preset_strength);
return -ENOTSUPP;
}
int nand_match_ecc_req(struct nand_chip *chip,
const struct nand_ecc_caps *caps, int oobavail)
{
struct mtd_info *mtd = nand_to_mtd(chip);
const struct nand_ecc_step_info *stepinfo;
int req_step = chip->ecc_step_ds;
int req_strength = chip->ecc_strength_ds;
int req_corr, step_size, strength, nsteps, ecc_bytes, ecc_bytes_total;
int best_step, best_strength, best_ecc_bytes;
int best_ecc_bytes_total = INT_MAX;
int i, j;
if (WARN_ON(oobavail < 0))
return -EINVAL;
if (!req_step || !req_strength)
return -ENOTSUPP;
req_corr = mtd->writesize / req_step * req_strength;
for (i = 0; i < caps->nstepinfos; i++) {
stepinfo = &caps->stepinfos[i];
step_size = stepinfo->stepsize;
for (j = 0; j < stepinfo->nstrengths; j++) {
strength = stepinfo->strengths[j];
if (step_size < req_step && strength < req_strength)
continue;
if (mtd->writesize % step_size)
continue;
nsteps = mtd->writesize / step_size;
ecc_bytes = caps->calc_ecc_bytes(step_size, strength);
if (WARN_ON_ONCE(ecc_bytes < 0))
continue;
ecc_bytes_total = ecc_bytes * nsteps;
if (ecc_bytes_total > oobavail ||
strength * nsteps < req_corr)
continue;
if (ecc_bytes_total < best_ecc_bytes_total) {
best_ecc_bytes_total = ecc_bytes_total;
best_step = step_size;
best_strength = strength;
best_ecc_bytes = ecc_bytes;
}
}
}
if (best_ecc_bytes_total == INT_MAX)
return -ENOTSUPP;
chip->ecc.size = best_step;
chip->ecc.strength = best_strength;
chip->ecc.bytes = best_ecc_bytes;
return 0;
}
int nand_maximize_ecc(struct nand_chip *chip,
const struct nand_ecc_caps *caps, int oobavail)
{
struct mtd_info *mtd = nand_to_mtd(chip);
const struct nand_ecc_step_info *stepinfo;
int step_size, strength, nsteps, ecc_bytes, corr;
int best_corr = 0;
int best_step = 0;
int best_strength, best_ecc_bytes;
int i, j;
if (WARN_ON(oobavail < 0))
return -EINVAL;
for (i = 0; i < caps->nstepinfos; i++) {
stepinfo = &caps->stepinfos[i];
step_size = stepinfo->stepsize;
if (chip->ecc.size && step_size != chip->ecc.size)
continue;
for (j = 0; j < stepinfo->nstrengths; j++) {
strength = stepinfo->strengths[j];
if (mtd->writesize % step_size)
continue;
nsteps = mtd->writesize / step_size;
ecc_bytes = caps->calc_ecc_bytes(step_size, strength);
if (WARN_ON_ONCE(ecc_bytes < 0))
continue;
if (ecc_bytes * nsteps > oobavail)
continue;
corr = strength * nsteps;
if (corr > best_corr ||
(corr == best_corr && step_size > best_step)) {
best_corr = corr;
best_step = step_size;
best_strength = strength;
best_ecc_bytes = ecc_bytes;
}
}
}
if (!best_corr)
return -ENOTSUPP;
chip->ecc.size = best_step;
chip->ecc.strength = best_strength;
chip->ecc.bytes = best_ecc_bytes;
return 0;
}
static bool nand_ecc_strength_good(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &chip->ecc;
int corr, ds_corr;
if (ecc->size == 0 || chip->ecc_step_ds == 0)
return true;
corr = (mtd->writesize * ecc->strength) / ecc->size;
ds_corr = (mtd->writesize * chip->ecc_strength_ds) / chip->ecc_step_ds;
return corr >= ds_corr && ecc->strength >= chip->ecc_strength_ds;
}
static bool invalid_ecc_page_accessors(struct nand_chip *chip)
{
struct nand_ecc_ctrl *ecc = &chip->ecc;
if (nand_standard_page_accessors(ecc))
return false;
return (!ecc->read_page || !ecc->write_page ||
!ecc->read_page_raw || !ecc->write_page_raw ||
(NAND_HAS_SUBPAGE_READ(chip) && !ecc->read_subpage) ||
(NAND_HAS_SUBPAGE_WRITE(chip) && !ecc->write_subpage &&
ecc->hwctl && ecc->calculate));
}
int nand_scan_tail(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &chip->ecc;
struct nand_buffers *nbuf = NULL;
int ret;
if (WARN_ON((chip->bbt_options & NAND_BBT_NO_OOB_BBM) &&
!(chip->bbt_options & NAND_BBT_USE_FLASH))) {
ret = -EINVAL;
goto err_ident;
}
if (invalid_ecc_page_accessors(chip)) {
pr_err("Invalid ECC page accessors setup\n");
ret = -EINVAL;
goto err_ident;
}
if (!(chip->options & NAND_OWN_BUFFERS)) {
nbuf = kzalloc(sizeof(*nbuf), GFP_KERNEL);
if (!nbuf) {
ret = -ENOMEM;
goto err_ident;
}
nbuf->ecccalc = kmalloc(mtd->oobsize, GFP_KERNEL);
if (!nbuf->ecccalc) {
ret = -ENOMEM;
goto err_free;
}
nbuf->ecccode = kmalloc(mtd->oobsize, GFP_KERNEL);
if (!nbuf->ecccode) {
ret = -ENOMEM;
goto err_free;
}
nbuf->databuf = kmalloc(mtd->writesize + mtd->oobsize,
GFP_KERNEL);
if (!nbuf->databuf) {
ret = -ENOMEM;
goto err_free;
}
chip->buffers = nbuf;
} else {
if (!chip->buffers) {
ret = -ENOMEM;
goto err_ident;
}
}
chip->oob_poi = chip->buffers->databuf + mtd->writesize;
if (!mtd->ooblayout &&
!(ecc->mode == NAND_ECC_SOFT && ecc->algo == NAND_ECC_BCH)) {
switch (mtd->oobsize) {
case 8:
case 16:
mtd_set_ooblayout(mtd, &nand_ooblayout_sp_ops);
break;
case 64:
case 128:
mtd_set_ooblayout(mtd, &nand_ooblayout_lp_hamming_ops);
break;
default:
WARN(1, "No oob scheme defined for oobsize %d\n",
mtd->oobsize);
ret = -EINVAL;
goto err_free;
}
}
switch (ecc->mode) {
case NAND_ECC_HW_OOB_FIRST:
if (!ecc->calculate || !ecc->correct || !ecc->hwctl) {
WARN(1, "No ECC functions supplied; hardware ECC not possible\n");
ret = -EINVAL;
goto err_free;
}
if (!ecc->read_page)
ecc->read_page = nand_read_page_hwecc_oob_first;
case NAND_ECC_HW:
if (!ecc->read_page)
ecc->read_page = nand_read_page_hwecc;
if (!ecc->write_page)
ecc->write_page = nand_write_page_hwecc;
if (!ecc->read_page_raw)
ecc->read_page_raw = nand_read_page_raw;
if (!ecc->write_page_raw)
ecc->write_page_raw = nand_write_page_raw;
if (!ecc->read_oob)
ecc->read_oob = nand_read_oob_std;
if (!ecc->write_oob)
ecc->write_oob = nand_write_oob_std;
if (!ecc->read_subpage)
ecc->read_subpage = nand_read_subpage;
if (!ecc->write_subpage && ecc->hwctl && ecc->calculate)
ecc->write_subpage = nand_write_subpage_hwecc;
case NAND_ECC_HW_SYNDROME:
if ((!ecc->calculate || !ecc->correct || !ecc->hwctl) &&
(!ecc->read_page ||
ecc->read_page == nand_read_page_hwecc ||
!ecc->write_page ||
ecc->write_page == nand_write_page_hwecc)) {
WARN(1, "No ECC functions supplied; hardware ECC not possible\n");
ret = -EINVAL;
goto err_free;
}
if (!ecc->read_page)
ecc->read_page = nand_read_page_syndrome;
if (!ecc->write_page)
ecc->write_page = nand_write_page_syndrome;
if (!ecc->read_page_raw)
ecc->read_page_raw = nand_read_page_raw_syndrome;
if (!ecc->write_page_raw)
ecc->write_page_raw = nand_write_page_raw_syndrome;
if (!ecc->read_oob)
ecc->read_oob = nand_read_oob_syndrome;
if (!ecc->write_oob)
ecc->write_oob = nand_write_oob_syndrome;
if (mtd->writesize >= ecc->size) {
if (!ecc->strength) {
WARN(1, "Driver must set ecc.strength when using hardware ECC\n");
ret = -EINVAL;
goto err_free;
}
break;
}
pr_warn("%d byte HW ECC not possible on %d byte page size, fallback to SW ECC\n",
ecc->size, mtd->writesize);
ecc->mode = NAND_ECC_SOFT;
ecc->algo = NAND_ECC_HAMMING;
case NAND_ECC_SOFT:
ret = nand_set_ecc_soft_ops(mtd);
if (ret) {
ret = -EINVAL;
goto err_free;
}
break;
case NAND_ECC_ON_DIE:
if (!ecc->read_page || !ecc->write_page) {
WARN(1, "No ECC functions supplied; on-die ECC not possible\n");
ret = -EINVAL;
goto err_free;
}
if (!ecc->read_oob)
ecc->read_oob = nand_read_oob_std;
if (!ecc->write_oob)
ecc->write_oob = nand_write_oob_std;
break;
case NAND_ECC_NONE:
pr_warn("NAND_ECC_NONE selected by board driver. This is not recommended!\n");
ecc->read_page = nand_read_page_raw;
ecc->write_page = nand_write_page_raw;
ecc->read_oob = nand_read_oob_std;
ecc->read_page_raw = nand_read_page_raw;
ecc->write_page_raw = nand_write_page_raw;
ecc->write_oob = nand_write_oob_std;
ecc->size = mtd->writesize;
ecc->bytes = 0;
ecc->strength = 0;
break;
default:
WARN(1, "Invalid NAND_ECC_MODE %d\n", ecc->mode);
ret = -EINVAL;
goto err_free;
}
if (!ecc->read_oob_raw)
ecc->read_oob_raw = ecc->read_oob;
if (!ecc->write_oob_raw)
ecc->write_oob_raw = ecc->write_oob;
mtd->ecc_strength = ecc->strength;
mtd->ecc_step_size = ecc->size;
ecc->steps = mtd->writesize / ecc->size;
if (ecc->steps * ecc->size != mtd->writesize) {
WARN(1, "Invalid ECC parameters\n");
ret = -EINVAL;
goto err_free;
}
ecc->total = ecc->steps * ecc->bytes;
if (ecc->total > mtd->oobsize) {
WARN(1, "Total number of ECC bytes exceeded oobsize\n");
ret = -EINVAL;
goto err_free;
}
ret = mtd_ooblayout_count_freebytes(mtd);
if (ret < 0)
ret = 0;
mtd->oobavail = ret;
if (!nand_ecc_strength_good(mtd))
pr_warn("WARNING: %s: the ECC used on your system is too weak compared to the one required by the NAND chip\n",
mtd->name);
if (!(chip->options & NAND_NO_SUBPAGE_WRITE) && nand_is_slc(chip)) {
switch (ecc->steps) {
case 2:
mtd->subpage_sft = 1;
break;
case 4:
case 8:
case 16:
mtd->subpage_sft = 2;
break;
}
}
chip->subpagesize = mtd->writesize >> mtd->subpage_sft;
chip->state = FL_READY;
chip->pagebuf = -1;
switch (ecc->mode) {
case NAND_ECC_SOFT:
if (chip->page_shift > 9)
chip->options |= NAND_SUBPAGE_READ;
break;
default:
break;
}
mtd->type = nand_is_slc(chip) ? MTD_NANDFLASH : MTD_MLCNANDFLASH;
mtd->flags = (chip->options & NAND_ROM) ? MTD_CAP_ROM :
MTD_CAP_NANDFLASH;
mtd->_erase = nand_erase;
mtd->_point = NULL;
mtd->_unpoint = NULL;
mtd->_read = nand_read;
mtd->_write = nand_write;
mtd->_panic_write = panic_nand_write;
mtd->_read_oob = nand_read_oob;
mtd->_write_oob = nand_write_oob;
mtd->_sync = nand_sync;
mtd->_lock = NULL;
mtd->_unlock = NULL;
mtd->_suspend = nand_suspend;
mtd->_resume = nand_resume;
mtd->_reboot = nand_shutdown;
mtd->_block_isreserved = nand_block_isreserved;
mtd->_block_isbad = nand_block_isbad;
mtd->_block_markbad = nand_block_markbad;
mtd->_max_bad_blocks = nand_max_bad_blocks;
mtd->writebufsize = mtd->writesize;
if (!mtd->bitflip_threshold)
mtd->bitflip_threshold = DIV_ROUND_UP(mtd->ecc_strength * 3, 4);
if (chip->options & NAND_SKIP_BBTSCAN)
return 0;
ret = chip->scan_bbt(mtd);
if (ret)
goto err_free;
return 0;
err_free:
if (nbuf) {
kfree(nbuf->databuf);
kfree(nbuf->ecccode);
kfree(nbuf->ecccalc);
kfree(nbuf);
}
err_ident:
nand_manufacturer_cleanup(chip);
return ret;
}
int nand_scan(struct mtd_info *mtd, int maxchips)
{
int ret;
ret = nand_scan_ident(mtd, maxchips, NULL);
if (!ret)
ret = nand_scan_tail(mtd);
return ret;
}
void nand_cleanup(struct nand_chip *chip)
{
if (chip->ecc.mode == NAND_ECC_SOFT &&
chip->ecc.algo == NAND_ECC_BCH)
nand_bch_free((struct nand_bch_control *)chip->ecc.priv);
nand_release_data_interface(chip);
kfree(chip->bbt);
if (!(chip->options & NAND_OWN_BUFFERS) && chip->buffers) {
kfree(chip->buffers->databuf);
kfree(chip->buffers->ecccode);
kfree(chip->buffers->ecccalc);
kfree(chip->buffers);
}
if (chip->badblock_pattern && chip->badblock_pattern->options
& NAND_BBT_DYNAMICSTRUCT)
kfree(chip->badblock_pattern);
nand_manufacturer_cleanup(chip);
}
void nand_release(struct mtd_info *mtd)
{
mtd_device_unregister(mtd);
nand_cleanup(mtd_to_nand(mtd));
}
