void mmc_decode_cid(struct mmc_card *card)
{
u32 *resp = card->raw_cid;
card->cid.manfid = UNSTUFF_BITS(resp, 120, 8);
card->cid.oemid = UNSTUFF_BITS(resp, 104, 16);
card->cid.prod_name[0] = UNSTUFF_BITS(resp, 96, 8);
card->cid.prod_name[1] = UNSTUFF_BITS(resp, 88, 8);
card->cid.prod_name[2] = UNSTUFF_BITS(resp, 80, 8);
card->cid.prod_name[3] = UNSTUFF_BITS(resp, 72, 8);
card->cid.prod_name[4] = UNSTUFF_BITS(resp, 64, 8);
card->cid.hwrev = UNSTUFF_BITS(resp, 60, 4);
card->cid.fwrev = UNSTUFF_BITS(resp, 56, 4);
card->cid.serial = UNSTUFF_BITS(resp, 24, 32);
card->cid.year = UNSTUFF_BITS(resp, 12, 8);
card->cid.month = UNSTUFF_BITS(resp, 8, 4);
card->cid.year += 2000;
}
static int mmc_decode_csd(struct mmc_card *card)
{
struct mmc_csd *csd = &card->csd;
unsigned int e, m, csd_struct;
u32 *resp = card->raw_csd;
csd_struct = UNSTUFF_BITS(resp, 126, 2);
switch (csd_struct) {
case 0:
m = UNSTUFF_BITS(resp, 115, 4);
e = UNSTUFF_BITS(resp, 112, 3);
csd->tacc_ns = (tacc_exp[e] * tacc_mant[m] + 9) / 10;
csd->tacc_clks = UNSTUFF_BITS(resp, 104, 8) * 100;
m = UNSTUFF_BITS(resp, 99, 4);
e = UNSTUFF_BITS(resp, 96, 3);
csd->max_dtr = tran_exp[e] * tran_mant[m];
csd->cmdclass = UNSTUFF_BITS(resp, 84, 12);
e = UNSTUFF_BITS(resp, 47, 3);
m = UNSTUFF_BITS(resp, 62, 12);
csd->capacity = (1 + m) << (e + 2);
csd->read_blkbits = UNSTUFF_BITS(resp, 80, 4);
csd->read_partial = UNSTUFF_BITS(resp, 79, 1);
csd->write_misalign = UNSTUFF_BITS(resp, 78, 1);
csd->read_misalign = UNSTUFF_BITS(resp, 77, 1);
csd->dsr_imp = UNSTUFF_BITS(resp, 76, 1);
csd->r2w_factor = UNSTUFF_BITS(resp, 26, 3);
csd->write_blkbits = UNSTUFF_BITS(resp, 22, 4);
csd->write_partial = UNSTUFF_BITS(resp, 21, 1);
if (UNSTUFF_BITS(resp, 46, 1)) {
csd->erase_size = 1;
} else if (csd->write_blkbits >= 9) {
csd->erase_size = UNSTUFF_BITS(resp, 39, 7) + 1;
csd->erase_size <<= csd->write_blkbits - 9;
}
break;
case 1:
mmc_card_set_blockaddr(card);
csd->tacc_ns = 0;
csd->tacc_clks = 0;
m = UNSTUFF_BITS(resp, 99, 4);
e = UNSTUFF_BITS(resp, 96, 3);
csd->max_dtr = tran_exp[e] * tran_mant[m];
csd->cmdclass = UNSTUFF_BITS(resp, 84, 12);
csd->c_size = UNSTUFF_BITS(resp, 48, 22);
if (csd->c_size >= 0xFFFF)
mmc_card_set_ext_capacity(card);
m = UNSTUFF_BITS(resp, 48, 22);
csd->capacity = (1 + m) << 10;
csd->read_blkbits = 9;
csd->read_partial = 0;
csd->write_misalign = 0;
csd->read_misalign = 0;
csd->r2w_factor = 4;
csd->write_blkbits = 9;
csd->write_partial = 0;
csd->erase_size = 1;
break;
default:
pr_err("%s: unrecognised CSD structure version %d\n",
mmc_hostname(card->host), csd_struct);
return -EINVAL;
}
card->erase_size = csd->erase_size;
return 0;
}
static int mmc_decode_scr(struct mmc_card *card)
{
struct sd_scr *scr = &card->scr;
unsigned int scr_struct;
u32 resp[4];
resp[3] = card->raw_scr[1];
resp[2] = card->raw_scr[0];
scr_struct = UNSTUFF_BITS(resp, 60, 4);
if (scr_struct != 0) {
pr_err("%s: unrecognised SCR structure version %d\n",
mmc_hostname(card->host), scr_struct);
return -EINVAL;
}
scr->sda_vsn = UNSTUFF_BITS(resp, 56, 4);
scr->bus_widths = UNSTUFF_BITS(resp, 48, 4);
if (scr->sda_vsn == SCR_SPEC_VER_2)
scr->sda_spec3 = UNSTUFF_BITS(resp, 47, 1);
if (UNSTUFF_BITS(resp, 55, 1))
card->erased_byte = 0xFF;
else
card->erased_byte = 0x0;
if (scr->sda_spec3)
scr->cmds = UNSTUFF_BITS(resp, 32, 2);
return 0;
}
static int mmc_read_ssr(struct mmc_card *card)
{
unsigned int au, es, et, eo;
__be32 *raw_ssr;
int i;
if (!(card->csd.cmdclass & CCC_APP_SPEC)) {
pr_warn("%s: card lacks mandatory SD Status function\n",
mmc_hostname(card->host));
return 0;
}
raw_ssr = kmalloc(sizeof(card->raw_ssr), GFP_KERNEL);
if (!raw_ssr)
return -ENOMEM;
if (mmc_app_sd_status(card, raw_ssr)) {
pr_warn("%s: problem reading SD Status register\n",
mmc_hostname(card->host));
kfree(raw_ssr);
return 0;
}
for (i = 0; i < 16; i++)
card->raw_ssr[i] = be32_to_cpu(raw_ssr[i]);
kfree(raw_ssr);
au = UNSTUFF_BITS(card->raw_ssr, 428 - 384, 4);
if (au) {
if (au <= 9 || card->scr.sda_spec3) {
card->ssr.au = sd_au_size[au];
es = UNSTUFF_BITS(card->raw_ssr, 408 - 384, 16);
et = UNSTUFF_BITS(card->raw_ssr, 402 - 384, 6);
if (es && et) {
eo = UNSTUFF_BITS(card->raw_ssr, 400 - 384, 2);
card->ssr.erase_timeout = (et * 1000) / es;
card->ssr.erase_offset = eo * 1000;
}
} else {
pr_warn("%s: SD Status: Invalid Allocation Unit size\n",
mmc_hostname(card->host));
}
}
return 0;
}
static int mmc_read_switch(struct mmc_card *card)
{
int err;
u8 *status;
if (card->scr.sda_vsn < SCR_SPEC_VER_1)
return 0;
if (!(card->csd.cmdclass & CCC_SWITCH)) {
pr_warn("%s: card lacks mandatory switch function, performance might suffer\n",
mmc_hostname(card->host));
return 0;
}
err = -EIO;
status = kmalloc(64, GFP_KERNEL);
if (!status)
return -ENOMEM;
err = mmc_sd_switch(card, 0, 0, 0, status);
if (err) {
if (err != -EINVAL && err != -ENOSYS && err != -EFAULT)
goto out;
pr_warn("%s: problem reading Bus Speed modes\n",
mmc_hostname(card->host));
err = 0;
goto out;
}
if (status[13] & SD_MODE_HIGH_SPEED)
card->sw_caps.hs_max_dtr = HIGH_SPEED_MAX_DTR;
if (card->scr.sda_spec3) {
card->sw_caps.sd3_bus_mode = status[13];
card->sw_caps.sd3_drv_type = status[9];
card->sw_caps.sd3_curr_limit = status[7] | status[6] << 8;
}
out:
kfree(status);
return err;
}
int mmc_sd_switch_hs(struct mmc_card *card)
{
int err;
u8 *status;
if (card->scr.sda_vsn < SCR_SPEC_VER_1)
return 0;
if (!(card->csd.cmdclass & CCC_SWITCH))
return 0;
if (!(card->host->caps & MMC_CAP_SD_HIGHSPEED))
return 0;
if (card->sw_caps.hs_max_dtr == 0)
return 0;
status = kmalloc(64, GFP_KERNEL);
if (!status)
return -ENOMEM;
err = mmc_sd_switch(card, 1, 0, 1, status);
if (err)
goto out;
if ((status[16] & 0xF) != 1) {
pr_warn("%s: Problem switching card into high-speed mode!\n",
mmc_hostname(card->host));
err = 0;
} else {
err = 1;
}
out:
kfree(status);
return err;
}
static int sd_select_driver_type(struct mmc_card *card, u8 *status)
{
int card_drv_type, drive_strength, drv_type;
int err;
card->drive_strength = 0;
card_drv_type = card->sw_caps.sd3_drv_type | SD_DRIVER_TYPE_B;
drive_strength = mmc_select_drive_strength(card,
card->sw_caps.uhs_max_dtr,
card_drv_type, &drv_type);
if (drive_strength) {
err = mmc_sd_switch(card, 1, 2, drive_strength, status);
if (err)
return err;
if ((status[15] & 0xF) != drive_strength) {
pr_warn("%s: Problem setting drive strength!\n",
mmc_hostname(card->host));
return 0;
}
card->drive_strength = drive_strength;
}
if (drv_type)
mmc_set_driver_type(card->host, drv_type);
return 0;
}
static void sd_update_bus_speed_mode(struct mmc_card *card)
{
if (!mmc_host_uhs(card->host)) {
card->sd_bus_speed = 0;
return;
}
if ((card->host->caps & MMC_CAP_UHS_SDR104) &&
(card->sw_caps.sd3_bus_mode & SD_MODE_UHS_SDR104)) {
card->sd_bus_speed = UHS_SDR104_BUS_SPEED;
} else if ((card->host->caps & MMC_CAP_UHS_DDR50) &&
(card->sw_caps.sd3_bus_mode & SD_MODE_UHS_DDR50)) {
card->sd_bus_speed = UHS_DDR50_BUS_SPEED;
} else if ((card->host->caps & (MMC_CAP_UHS_SDR104 |
MMC_CAP_UHS_SDR50)) && (card->sw_caps.sd3_bus_mode &
SD_MODE_UHS_SDR50)) {
card->sd_bus_speed = UHS_SDR50_BUS_SPEED;
} else if ((card->host->caps & (MMC_CAP_UHS_SDR104 |
MMC_CAP_UHS_SDR50 | MMC_CAP_UHS_SDR25)) &&
(card->sw_caps.sd3_bus_mode & SD_MODE_UHS_SDR25)) {
card->sd_bus_speed = UHS_SDR25_BUS_SPEED;
} else if ((card->host->caps & (MMC_CAP_UHS_SDR104 |
MMC_CAP_UHS_SDR50 | MMC_CAP_UHS_SDR25 |
MMC_CAP_UHS_SDR12)) && (card->sw_caps.sd3_bus_mode &
SD_MODE_UHS_SDR12)) {
card->sd_bus_speed = UHS_SDR12_BUS_SPEED;
}
}
static int sd_set_bus_speed_mode(struct mmc_card *card, u8 *status)
{
int err;
unsigned int timing = 0;
switch (card->sd_bus_speed) {
case UHS_SDR104_BUS_SPEED:
timing = MMC_TIMING_UHS_SDR104;
card->sw_caps.uhs_max_dtr = UHS_SDR104_MAX_DTR;
break;
case UHS_DDR50_BUS_SPEED:
timing = MMC_TIMING_UHS_DDR50;
card->sw_caps.uhs_max_dtr = UHS_DDR50_MAX_DTR;
break;
case UHS_SDR50_BUS_SPEED:
timing = MMC_TIMING_UHS_SDR50;
card->sw_caps.uhs_max_dtr = UHS_SDR50_MAX_DTR;
break;
case UHS_SDR25_BUS_SPEED:
timing = MMC_TIMING_UHS_SDR25;
card->sw_caps.uhs_max_dtr = UHS_SDR25_MAX_DTR;
break;
case UHS_SDR12_BUS_SPEED:
timing = MMC_TIMING_UHS_SDR12;
card->sw_caps.uhs_max_dtr = UHS_SDR12_MAX_DTR;
break;
default:
return 0;
}
err = mmc_sd_switch(card, 1, 0, card->sd_bus_speed, status);
if (err)
return err;
if ((status[16] & 0xF) != card->sd_bus_speed)
pr_warn("%s: Problem setting bus speed mode!\n",
mmc_hostname(card->host));
else {
mmc_set_timing(card->host, timing);
mmc_set_clock(card->host, card->sw_caps.uhs_max_dtr);
}
return 0;
}
static u32 sd_get_host_max_current(struct mmc_host *host)
{
u32 voltage, max_current;
voltage = 1 << host->ios.vdd;
switch (voltage) {
case MMC_VDD_165_195:
max_current = host->max_current_180;
break;
case MMC_VDD_29_30:
case MMC_VDD_30_31:
max_current = host->max_current_300;
break;
case MMC_VDD_32_33:
case MMC_VDD_33_34:
max_current = host->max_current_330;
break;
default:
max_current = 0;
}
return max_current;
}
static int sd_set_current_limit(struct mmc_card *card, u8 *status)
{
int current_limit = SD_SET_CURRENT_NO_CHANGE;
int err;
u32 max_current;
if ((card->sd_bus_speed != UHS_SDR50_BUS_SPEED) &&
(card->sd_bus_speed != UHS_SDR104_BUS_SPEED) &&
(card->sd_bus_speed != UHS_DDR50_BUS_SPEED))
return 0;
max_current = sd_get_host_max_current(card->host);
if (max_current >= 800 &&
card->sw_caps.sd3_curr_limit & SD_MAX_CURRENT_800)
current_limit = SD_SET_CURRENT_LIMIT_800;
else if (max_current >= 600 &&
card->sw_caps.sd3_curr_limit & SD_MAX_CURRENT_600)
current_limit = SD_SET_CURRENT_LIMIT_600;
else if (max_current >= 400 &&
card->sw_caps.sd3_curr_limit & SD_MAX_CURRENT_400)
current_limit = SD_SET_CURRENT_LIMIT_400;
else if (max_current >= 200 &&
card->sw_caps.sd3_curr_limit & SD_MAX_CURRENT_200)
current_limit = SD_SET_CURRENT_LIMIT_200;
if (current_limit != SD_SET_CURRENT_NO_CHANGE) {
err = mmc_sd_switch(card, 1, 3, current_limit, status);
if (err)
return err;
if (((status[15] >> 4) & 0x0F) != current_limit)
pr_warn("%s: Problem setting current limit!\n",
mmc_hostname(card->host));
}
return 0;
}
static int mmc_sd_init_uhs_card(struct mmc_card *card)
{
int err;
u8 *status;
if (!card->scr.sda_spec3)
return 0;
if (!(card->csd.cmdclass & CCC_SWITCH))
return 0;
status = kmalloc(64, GFP_KERNEL);
if (!status)
return -ENOMEM;
if ((card->host->caps & MMC_CAP_4_BIT_DATA) &&
(card->scr.bus_widths & SD_SCR_BUS_WIDTH_4)) {
err = mmc_app_set_bus_width(card, MMC_BUS_WIDTH_4);
if (err)
goto out;
mmc_set_bus_width(card->host, MMC_BUS_WIDTH_4);
}
sd_update_bus_speed_mode(card);
err = sd_select_driver_type(card, status);
if (err)
goto out;
err = sd_set_current_limit(card, status);
if (err)
goto out;
err = sd_set_bus_speed_mode(card, status);
if (err)
goto out;
if (!mmc_host_is_spi(card->host) &&
(card->host->ios.timing == MMC_TIMING_UHS_SDR50 ||
card->host->ios.timing == MMC_TIMING_UHS_DDR50 ||
card->host->ios.timing == MMC_TIMING_UHS_SDR104)) {
err = mmc_execute_tuning(card);
if (err && card->host->ios.timing == MMC_TIMING_UHS_DDR50) {
pr_warn("%s: ddr50 tuning failed\n",
mmc_hostname(card->host));
err = 0;
}
}
out:
kfree(status);
return err;
}
static ssize_t mmc_dsr_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct mmc_card *card = mmc_dev_to_card(dev);
struct mmc_host *host = card->host;
if (card->csd.dsr_imp && host->dsr_req)
return sprintf(buf, "0x%x\n", host->dsr);
else
return sprintf(buf, "0x%x\n", 0x404);
}
int mmc_sd_get_cid(struct mmc_host *host, u32 ocr, u32 *cid, u32 *rocr)
{
int err;
u32 max_current;
int retries = 10;
u32 pocr = ocr;
try_again:
if (!retries) {
ocr &= ~SD_OCR_S18R;
pr_warn("%s: Skipping voltage switch\n", mmc_hostname(host));
}
mmc_go_idle(host);
err = mmc_send_if_cond(host, ocr);
if (!err)
ocr |= SD_OCR_CCS;
if (retries && mmc_host_uhs(host))
ocr |= SD_OCR_S18R;
max_current = sd_get_host_max_current(host);
if (max_current > 150)
ocr |= SD_OCR_XPC;
err = mmc_send_app_op_cond(host, ocr, rocr);
if (err)
return err;
if (!mmc_host_is_spi(host) && rocr &&
((*rocr & 0x41000000) == 0x41000000)) {
err = mmc_set_uhs_voltage(host, pocr);
if (err == -EAGAIN) {
retries--;
goto try_again;
} else if (err) {
retries = 0;
goto try_again;
}
}
err = mmc_send_cid(host, cid);
return err;
}
int mmc_sd_get_csd(struct mmc_host *host, struct mmc_card *card)
{
int err;
err = mmc_send_csd(card, card->raw_csd);
if (err)
return err;
err = mmc_decode_csd(card);
if (err)
return err;
return 0;
}
static int mmc_sd_get_ro(struct mmc_host *host)
{
int ro;
if (host->caps2 & MMC_CAP2_NO_WRITE_PROTECT)
return 0;
if (!host->ops->get_ro)
return -1;
ro = host->ops->get_ro(host);
return ro;
}
int mmc_sd_setup_card(struct mmc_host *host, struct mmc_card *card,
bool reinit)
{
int err;
if (!reinit) {
err = mmc_app_send_scr(card);
if (err)
return err;
err = mmc_decode_scr(card);
if (err)
return err;
err = mmc_read_ssr(card);
if (err)
return err;
mmc_init_erase(card);
err = mmc_read_switch(card);
if (err)
return err;
}
if (mmc_host_is_spi(host)) {
err = mmc_spi_set_crc(host, use_spi_crc);
if (err)
return err;
}
if (!reinit) {
int ro = mmc_sd_get_ro(host);
if (ro < 0) {
pr_warn("%s: host does not support reading read-only switch, assuming write-enable\n",
mmc_hostname(host));
} else if (ro > 0) {
mmc_card_set_readonly(card);
}
}
return 0;
}
unsigned mmc_sd_get_max_clock(struct mmc_card *card)
{
unsigned max_dtr = (unsigned int)-1;
if (mmc_card_hs(card)) {
if (max_dtr > card->sw_caps.hs_max_dtr)
max_dtr = card->sw_caps.hs_max_dtr;
} else if (max_dtr > card->csd.max_dtr) {
max_dtr = card->csd.max_dtr;
}
return max_dtr;
}
static int mmc_sd_init_card(struct mmc_host *host, u32 ocr,
struct mmc_card *oldcard)
{
struct mmc_card *card;
int err;
u32 cid[4];
u32 rocr = 0;
WARN_ON(!host->claimed);
err = mmc_sd_get_cid(host, ocr, cid, &rocr);
if (err)
return err;
if (oldcard) {
if (memcmp(cid, oldcard->raw_cid, sizeof(cid)) != 0)
return -ENOENT;
card = oldcard;
} else {
card = mmc_alloc_card(host, &sd_type);
if (IS_ERR(card))
return PTR_ERR(card);
card->ocr = ocr;
card->type = MMC_TYPE_SD;
memcpy(card->raw_cid, cid, sizeof(card->raw_cid));
}
if (host->ops->init_card)
host->ops->init_card(host, card);
if (!mmc_host_is_spi(host)) {
err = mmc_send_relative_addr(host, &card->rca);
if (err)
goto free_card;
}
if (!oldcard) {
err = mmc_sd_get_csd(host, card);
if (err)
goto free_card;
mmc_decode_cid(card);
}
if (card->csd.dsr_imp && host->dsr_req)
mmc_set_dsr(host);
if (!mmc_host_is_spi(host)) {
err = mmc_select_card(card);
if (err)
goto free_card;
}
err = mmc_sd_setup_card(host, card, oldcard != NULL);
if (err)
goto free_card;
if (rocr & SD_ROCR_S18A) {
err = mmc_sd_init_uhs_card(card);
if (err)
goto free_card;
} else {
err = mmc_sd_switch_hs(card);
if (err > 0)
mmc_set_timing(card->host, MMC_TIMING_SD_HS);
else if (err)
goto free_card;
mmc_set_clock(host, mmc_sd_get_max_clock(card));
if ((host->caps & MMC_CAP_4_BIT_DATA) &&
(card->scr.bus_widths & SD_SCR_BUS_WIDTH_4)) {
err = mmc_app_set_bus_width(card, MMC_BUS_WIDTH_4);
if (err)
goto free_card;
mmc_set_bus_width(host, MMC_BUS_WIDTH_4);
}
}
host->card = card;
return 0;
free_card:
if (!oldcard)
mmc_remove_card(card);
return err;
}
static void mmc_sd_remove(struct mmc_host *host)
{
mmc_remove_card(host->card);
host->card = NULL;
}
static int mmc_sd_alive(struct mmc_host *host)
{
return mmc_send_status(host->card, NULL);
}
static void mmc_sd_detect(struct mmc_host *host)
{
int err;
mmc_get_card(host->card);
err = _mmc_detect_card_removed(host);
mmc_put_card(host->card);
if (err) {
mmc_sd_remove(host);
mmc_claim_host(host);
mmc_detach_bus(host);
mmc_power_off(host);
mmc_release_host(host);
}
}
static int _mmc_sd_suspend(struct mmc_host *host)
{
int err = 0;
mmc_claim_host(host);
if (mmc_card_suspended(host->card))
goto out;
if (!mmc_host_is_spi(host))
err = mmc_deselect_cards(host);
if (!err) {
mmc_power_off(host);
mmc_card_set_suspended(host->card);
}
out:
mmc_release_host(host);
return err;
}
static int mmc_sd_suspend(struct mmc_host *host)
{
int err;
err = _mmc_sd_suspend(host);
if (!err) {
pm_runtime_disable(&host->card->dev);
pm_runtime_set_suspended(&host->card->dev);
}
return err;
}
static int _mmc_sd_resume(struct mmc_host *host)
{
int err = 0;
mmc_claim_host(host);
if (!mmc_card_suspended(host->card))
goto out;
mmc_power_up(host, host->card->ocr);
err = mmc_sd_init_card(host, host->card->ocr, host->card);
mmc_card_clr_suspended(host->card);
out:
mmc_release_host(host);
return err;
}
static int mmc_sd_resume(struct mmc_host *host)
{
pm_runtime_enable(&host->card->dev);
return 0;
}
static int mmc_sd_runtime_suspend(struct mmc_host *host)
{
int err;
if (!(host->caps & MMC_CAP_AGGRESSIVE_PM))
return 0;
err = _mmc_sd_suspend(host);
if (err)
pr_err("%s: error %d doing aggressive suspend\n",
mmc_hostname(host), err);
return err;
}
static int mmc_sd_runtime_resume(struct mmc_host *host)
{
int err;
err = _mmc_sd_resume(host);
if (err && err != -ENOMEDIUM)
pr_err("%s: error %d doing runtime resume\n",
mmc_hostname(host), err);
return 0;
}
static int mmc_sd_reset(struct mmc_host *host)
{
mmc_power_cycle(host, host->card->ocr);
return mmc_sd_init_card(host, host->card->ocr, host->card);
}
int mmc_attach_sd(struct mmc_host *host)
{
int err;
u32 ocr, rocr;
WARN_ON(!host->claimed);
err = mmc_send_app_op_cond(host, 0, &ocr);
if (err)
return err;
mmc_attach_bus(host, &mmc_sd_ops);
if (host->ocr_avail_sd)
host->ocr_avail = host->ocr_avail_sd;
if (mmc_host_is_spi(host)) {
mmc_go_idle(host);
err = mmc_spi_read_ocr(host, 0, &ocr);
if (err)
goto err;
}
rocr = mmc_select_voltage(host, ocr);
if (!rocr) {
err = -EINVAL;
goto err;
}
err = mmc_sd_init_card(host, rocr, NULL);
if (err)
goto err;
mmc_release_host(host);
err = mmc_add_card(host->card);
if (err)
goto remove_card;
mmc_claim_host(host);
return 0;
remove_card:
mmc_remove_card(host->card);
host->card = NULL;
mmc_claim_host(host);
err:
mmc_detach_bus(host);
pr_err("%s: error %d whilst initialising SD card\n",
mmc_hostname(host), err);
return err;
}
