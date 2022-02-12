static inline void mmc_blk_clear_packed(struct mmc_queue_req *mqrq)
{
struct mmc_packed *packed = mqrq->packed;
BUG_ON(!packed);
mqrq->cmd_type = MMC_PACKED_NONE;
packed->nr_entries = MMC_PACKED_NR_ZERO;
packed->idx_failure = MMC_PACKED_NR_IDX;
packed->retries = 0;
packed->blocks = 0;
}
static struct mmc_blk_data *mmc_blk_get(struct gendisk *disk)
{
struct mmc_blk_data *md;
mutex_lock(&open_lock);
md = disk->private_data;
if (md && md->usage == 0)
md = NULL;
if (md)
md->usage++;
mutex_unlock(&open_lock);
return md;
}
static inline int mmc_get_devidx(struct gendisk *disk)
{
int devmaj = MAJOR(disk_devt(disk));
int devidx = MINOR(disk_devt(disk)) / perdev_minors;
if (!devmaj)
devidx = disk->first_minor / perdev_minors;
return devidx;
}
static void mmc_blk_put(struct mmc_blk_data *md)
{
mutex_lock(&open_lock);
md->usage--;
if (md->usage == 0) {
int devidx = mmc_get_devidx(md->disk);
blk_cleanup_queue(md->queue.queue);
__clear_bit(devidx, dev_use);
put_disk(md->disk);
kfree(md);
}
mutex_unlock(&open_lock);
}
static ssize_t power_ro_lock_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
struct mmc_blk_data *md = mmc_blk_get(dev_to_disk(dev));
struct mmc_card *card = md->queue.card;
int locked = 0;
if (card->ext_csd.boot_ro_lock & EXT_CSD_BOOT_WP_B_PERM_WP_EN)
locked = 2;
else if (card->ext_csd.boot_ro_lock & EXT_CSD_BOOT_WP_B_PWR_WP_EN)
locked = 1;
ret = snprintf(buf, PAGE_SIZE, "%d\n", locked);
return ret;
}
static ssize_t power_ro_lock_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int ret;
struct mmc_blk_data *md, *part_md;
struct mmc_card *card;
unsigned long set;
if (kstrtoul(buf, 0, &set))
return -EINVAL;
if (set != 1)
return count;
md = mmc_blk_get(dev_to_disk(dev));
card = md->queue.card;
mmc_get_card(card);
ret = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL, EXT_CSD_BOOT_WP,
card->ext_csd.boot_ro_lock |
EXT_CSD_BOOT_WP_B_PWR_WP_EN,
card->ext_csd.part_time);
if (ret)
pr_err("%s: Locking boot partition ro until next power on failed: %d\n", md->disk->disk_name, ret);
else
card->ext_csd.boot_ro_lock |= EXT_CSD_BOOT_WP_B_PWR_WP_EN;
mmc_put_card(card);
if (!ret) {
pr_info("%s: Locking boot partition ro until next power on\n",
md->disk->disk_name);
set_disk_ro(md->disk, 1);
list_for_each_entry(part_md, &md->part, part)
if (part_md->area_type == MMC_BLK_DATA_AREA_BOOT) {
pr_info("%s: Locking boot partition ro until next power on\n", part_md->disk->disk_name);
set_disk_ro(part_md->disk, 1);
}
}
mmc_blk_put(md);
return count;
}
static ssize_t force_ro_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
int ret;
struct mmc_blk_data *md = mmc_blk_get(dev_to_disk(dev));
ret = snprintf(buf, PAGE_SIZE, "%d",
get_disk_ro(dev_to_disk(dev)) ^
md->read_only);
mmc_blk_put(md);
return ret;
}
static ssize_t force_ro_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
char *end;
struct mmc_blk_data *md = mmc_blk_get(dev_to_disk(dev));
unsigned long set = simple_strtoul(buf, &end, 0);
if (end == buf) {
ret = -EINVAL;
goto out;
}
set_disk_ro(dev_to_disk(dev), set || md->read_only);
ret = count;
out:
mmc_blk_put(md);
return ret;
}
static int mmc_blk_open(struct block_device *bdev, fmode_t mode)
{
struct mmc_blk_data *md = mmc_blk_get(bdev->bd_disk);
int ret = -ENXIO;
mutex_lock(&block_mutex);
if (md) {
if (md->usage == 2)
check_disk_change(bdev);
ret = 0;
if ((mode & FMODE_WRITE) && md->read_only) {
mmc_blk_put(md);
ret = -EROFS;
}
}
mutex_unlock(&block_mutex);
return ret;
}
static void mmc_blk_release(struct gendisk *disk, fmode_t mode)
{
struct mmc_blk_data *md = disk->private_data;
mutex_lock(&block_mutex);
mmc_blk_put(md);
mutex_unlock(&block_mutex);
}
static int
mmc_blk_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
geo->cylinders = get_capacity(bdev->bd_disk) / (4 * 16);
geo->heads = 4;
geo->sectors = 16;
return 0;
}
static struct mmc_blk_ioc_data *mmc_blk_ioctl_copy_from_user(
struct mmc_ioc_cmd __user *user)
{
struct mmc_blk_ioc_data *idata;
int err;
idata = kzalloc(sizeof(*idata), GFP_KERNEL);
if (!idata) {
err = -ENOMEM;
goto out;
}
if (copy_from_user(&idata->ic, user, sizeof(idata->ic))) {
err = -EFAULT;
goto idata_err;
}
idata->buf_bytes = (u64) idata->ic.blksz * idata->ic.blocks;
if (idata->buf_bytes > MMC_IOC_MAX_BYTES) {
err = -EOVERFLOW;
goto idata_err;
}
if (!idata->buf_bytes)
return idata;
idata->buf = kzalloc(idata->buf_bytes, GFP_KERNEL);
if (!idata->buf) {
err = -ENOMEM;
goto idata_err;
}
if (copy_from_user(idata->buf, (void __user *)(unsigned long)
idata->ic.data_ptr, idata->buf_bytes)) {
err = -EFAULT;
goto copy_err;
}
return idata;
copy_err:
kfree(idata->buf);
idata_err:
kfree(idata);
out:
return ERR_PTR(err);
}
static int ioctl_rpmb_card_status_poll(struct mmc_card *card, u32 *status,
u32 retries_max)
{
int err;
u32 retry_count = 0;
if (!status || !retries_max)
return -EINVAL;
do {
err = get_card_status(card, status, 5);
if (err)
break;
if (!R1_STATUS(*status) &&
(R1_CURRENT_STATE(*status) != R1_STATE_PRG))
break;
usleep_range(1000, 5000);
} while (++retry_count < retries_max);
if (retry_count == retries_max)
err = -EPERM;
return err;
}
static int ioctl_do_sanitize(struct mmc_card *card)
{
int err;
if (!(mmc_can_sanitize(card) &&
(card->host->caps2 & MMC_CAP2_SANITIZE))) {
pr_warn("%s: %s - SANITIZE is not supported\n",
mmc_hostname(card->host), __func__);
err = -EOPNOTSUPP;
goto out;
}
pr_debug("%s: %s - SANITIZE IN PROGRESS...\n",
mmc_hostname(card->host), __func__);
err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
EXT_CSD_SANITIZE_START, 1,
MMC_SANITIZE_REQ_TIMEOUT);
if (err)
pr_err("%s: %s - EXT_CSD_SANITIZE_START failed. err=%d\n",
mmc_hostname(card->host), __func__, err);
pr_debug("%s: %s - SANITIZE COMPLETED\n", mmc_hostname(card->host),
__func__);
out:
return err;
}
static int mmc_blk_ioctl_cmd(struct block_device *bdev,
struct mmc_ioc_cmd __user *ic_ptr)
{
struct mmc_blk_ioc_data *idata;
struct mmc_blk_data *md;
struct mmc_card *card;
struct mmc_command cmd = {0};
struct mmc_data data = {0};
struct mmc_request mrq = {NULL};
struct scatterlist sg;
int err;
int is_rpmb = false;
u32 status = 0;
if ((!capable(CAP_SYS_RAWIO)) || (bdev != bdev->bd_contains))
return -EPERM;
idata = mmc_blk_ioctl_copy_from_user(ic_ptr);
if (IS_ERR(idata))
return PTR_ERR(idata);
md = mmc_blk_get(bdev->bd_disk);
if (!md) {
err = -EINVAL;
goto cmd_err;
}
if (md->area_type & MMC_BLK_DATA_AREA_RPMB)
is_rpmb = true;
card = md->queue.card;
if (IS_ERR(card)) {
err = PTR_ERR(card);
goto cmd_done;
}
cmd.opcode = idata->ic.opcode;
cmd.arg = idata->ic.arg;
cmd.flags = idata->ic.flags;
if (idata->buf_bytes) {
data.sg = &sg;
data.sg_len = 1;
data.blksz = idata->ic.blksz;
data.blocks = idata->ic.blocks;
sg_init_one(data.sg, idata->buf, idata->buf_bytes);
if (idata->ic.write_flag)
data.flags = MMC_DATA_WRITE;
else
data.flags = MMC_DATA_READ;
mmc_set_data_timeout(&data, card);
if (idata->ic.data_timeout_ns)
data.timeout_ns = idata->ic.data_timeout_ns;
if ((cmd.flags & MMC_RSP_R1B) == MMC_RSP_R1B) {
data.timeout_ns = idata->ic.cmd_timeout_ms * 1000000;
}
mrq.data = &data;
}
mrq.cmd = &cmd;
mmc_get_card(card);
err = mmc_blk_part_switch(card, md);
if (err)
goto cmd_rel_host;
if (idata->ic.is_acmd) {
err = mmc_app_cmd(card->host, card);
if (err)
goto cmd_rel_host;
}
if (is_rpmb) {
err = mmc_set_blockcount(card, data.blocks,
idata->ic.write_flag & (1 << 31));
if (err)
goto cmd_rel_host;
}
if ((MMC_EXTRACT_INDEX_FROM_ARG(cmd.arg) == EXT_CSD_SANITIZE_START) &&
(cmd.opcode == MMC_SWITCH)) {
err = ioctl_do_sanitize(card);
if (err)
pr_err("%s: ioctl_do_sanitize() failed. err = %d",
__func__, err);
goto cmd_rel_host;
}
mmc_wait_for_req(card->host, &mrq);
if (cmd.error) {
dev_err(mmc_dev(card->host), "%s: cmd error %d\n",
__func__, cmd.error);
err = cmd.error;
goto cmd_rel_host;
}
if (data.error) {
dev_err(mmc_dev(card->host), "%s: data error %d\n",
__func__, data.error);
err = data.error;
goto cmd_rel_host;
}
if (idata->ic.postsleep_min_us)
usleep_range(idata->ic.postsleep_min_us, idata->ic.postsleep_max_us);
if (copy_to_user(&(ic_ptr->response), cmd.resp, sizeof(cmd.resp))) {
err = -EFAULT;
goto cmd_rel_host;
}
if (!idata->ic.write_flag) {
if (copy_to_user((void __user *)(unsigned long) idata->ic.data_ptr,
idata->buf, idata->buf_bytes)) {
err = -EFAULT;
goto cmd_rel_host;
}
}
if (is_rpmb) {
err = ioctl_rpmb_card_status_poll(card, &status, 5);
if (err)
dev_err(mmc_dev(card->host),
"%s: Card Status=0x%08X, error %d\n",
__func__, status, err);
}
cmd_rel_host:
mmc_put_card(card);
cmd_done:
mmc_blk_put(md);
cmd_err:
kfree(idata->buf);
kfree(idata);
return err;
}
static int mmc_blk_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
int ret = -EINVAL;
if (cmd == MMC_IOC_CMD)
ret = mmc_blk_ioctl_cmd(bdev, (struct mmc_ioc_cmd __user *)arg);
return ret;
}
static int mmc_blk_compat_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
return mmc_blk_ioctl(bdev, mode, cmd, (unsigned long) compat_ptr(arg));
}
static inline int mmc_blk_part_switch(struct mmc_card *card,
struct mmc_blk_data *md)
{
int ret;
struct mmc_blk_data *main_md = mmc_get_drvdata(card);
if (main_md->part_curr == md->part_type)
return 0;
if (mmc_card_mmc(card)) {
u8 part_config = card->ext_csd.part_config;
part_config &= ~EXT_CSD_PART_CONFIG_ACC_MASK;
part_config |= md->part_type;
ret = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
EXT_CSD_PART_CONFIG, part_config,
card->ext_csd.part_time);
if (ret)
return ret;
card->ext_csd.part_config = part_config;
}
main_md->part_curr = md->part_type;
return 0;
}
static u32 mmc_sd_num_wr_blocks(struct mmc_card *card)
{
int err;
u32 result;
__be32 *blocks;
struct mmc_request mrq = {NULL};
struct mmc_command cmd = {0};
struct mmc_data data = {0};
struct scatterlist sg;
cmd.opcode = MMC_APP_CMD;
cmd.arg = card->rca << 16;
cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_AC;
err = mmc_wait_for_cmd(card->host, &cmd, 0);
if (err)
return (u32)-1;
if (!mmc_host_is_spi(card->host) && !(cmd.resp[0] & R1_APP_CMD))
return (u32)-1;
memset(&cmd, 0, sizeof(struct mmc_command));
cmd.opcode = SD_APP_SEND_NUM_WR_BLKS;
cmd.arg = 0;
cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_ADTC;
data.blksz = 4;
data.blocks = 1;
data.flags = MMC_DATA_READ;
data.sg = &sg;
data.sg_len = 1;
mmc_set_data_timeout(&data, card);
mrq.cmd = &cmd;
mrq.data = &data;
blocks = kmalloc(4, GFP_KERNEL);
if (!blocks)
return (u32)-1;
sg_init_one(&sg, blocks, 4);
mmc_wait_for_req(card->host, &mrq);
result = ntohl(*blocks);
kfree(blocks);
if (cmd.error || data.error)
result = (u32)-1;
return result;
}
static int send_stop(struct mmc_card *card, u32 *status)
{
struct mmc_command cmd = {0};
int err;
cmd.opcode = MMC_STOP_TRANSMISSION;
cmd.flags = MMC_RSP_SPI_R1B | MMC_RSP_R1B | MMC_CMD_AC;
err = mmc_wait_for_cmd(card->host, &cmd, 5);
if (err == 0)
*status = cmd.resp[0];
return err;
}
static int get_card_status(struct mmc_card *card, u32 *status, int retries)
{
struct mmc_command cmd = {0};
int err;
cmd.opcode = MMC_SEND_STATUS;
if (!mmc_host_is_spi(card->host))
cmd.arg = card->rca << 16;
cmd.flags = MMC_RSP_SPI_R2 | MMC_RSP_R1 | MMC_CMD_AC;
err = mmc_wait_for_cmd(card->host, &cmd, retries);
if (err == 0)
*status = cmd.resp[0];
return err;
}
static int mmc_blk_cmd_error(struct request *req, const char *name, int error,
bool status_valid, u32 status)
{
switch (error) {
case -EILSEQ:
pr_err("%s: %s sending %s command, card status %#x\n",
req->rq_disk->disk_name, "response CRC error",
name, status);
return ERR_RETRY;
case -ETIMEDOUT:
pr_err("%s: %s sending %s command, card status %#x\n",
req->rq_disk->disk_name, "timed out", name, status);
if (!status_valid)
return ERR_RETRY;
if (status & (R1_COM_CRC_ERROR | R1_ILLEGAL_COMMAND))
return ERR_RETRY;
return ERR_ABORT;
default:
pr_err("%s: unknown error %d sending read/write command, card status %#x\n",
req->rq_disk->disk_name, error, status);
return ERR_ABORT;
}
}
static int mmc_blk_cmd_recovery(struct mmc_card *card, struct request *req,
struct mmc_blk_request *brq, int *ecc_err, int *gen_err)
{
bool prev_cmd_status_valid = true;
u32 status, stop_status = 0;
int err, retry;
if (mmc_card_removed(card))
return ERR_NOMEDIUM;
for (retry = 2; retry >= 0; retry--) {
err = get_card_status(card, &status, 0);
if (!err)
break;
prev_cmd_status_valid = false;
pr_err("%s: error %d sending status command, %sing\n",
req->rq_disk->disk_name, err, retry ? "retry" : "abort");
}
if (err) {
if (mmc_detect_card_removed(card->host))
return ERR_NOMEDIUM;
return ERR_ABORT;
}
if ((status & R1_CARD_ECC_FAILED) ||
(brq->stop.resp[0] & R1_CARD_ECC_FAILED) ||
(brq->cmd.resp[0] & R1_CARD_ECC_FAILED))
*ecc_err = 1;
if (!mmc_host_is_spi(card->host) && rq_data_dir(req) != READ)
if ((status & R1_ERROR) ||
(brq->stop.resp[0] & R1_ERROR)) {
pr_err("%s: %s: general error sending stop or status command, stop cmd response %#x, card status %#x\n",
req->rq_disk->disk_name, __func__,
brq->stop.resp[0], status);
*gen_err = 1;
}
if (R1_CURRENT_STATE(status) == R1_STATE_DATA ||
R1_CURRENT_STATE(status) == R1_STATE_RCV) {
err = send_stop(card, &stop_status);
if (err)
pr_err("%s: error %d sending stop command\n",
req->rq_disk->disk_name, err);
if (err)
return ERR_ABORT;
if (stop_status & R1_CARD_ECC_FAILED)
*ecc_err = 1;
if (!mmc_host_is_spi(card->host) && rq_data_dir(req) != READ)
if (stop_status & R1_ERROR) {
pr_err("%s: %s: general error sending stop command, stop cmd response %#x\n",
req->rq_disk->disk_name, __func__,
stop_status);
*gen_err = 1;
}
}
if (brq->sbc.error)
return mmc_blk_cmd_error(req, "SET_BLOCK_COUNT", brq->sbc.error,
prev_cmd_status_valid, status);
if (brq->cmd.error)
return mmc_blk_cmd_error(req, "r/w cmd", brq->cmd.error,
prev_cmd_status_valid, status);
if (!brq->stop.error)
return ERR_CONTINUE;
pr_err("%s: error %d sending stop command, original cmd response %#x, card status %#x\n",
req->rq_disk->disk_name, brq->stop.error,
brq->cmd.resp[0], status);
if (stop_status) {
brq->stop.resp[0] = stop_status;
brq->stop.error = 0;
}
return ERR_CONTINUE;
}
static int mmc_blk_reset(struct mmc_blk_data *md, struct mmc_host *host,
int type)
{
int err;
if (md->reset_done & type)
return -EEXIST;
md->reset_done |= type;
err = mmc_hw_reset(host);
if (err != -EOPNOTSUPP) {
struct mmc_blk_data *main_md = mmc_get_drvdata(host->card);
int part_err;
main_md->part_curr = main_md->part_type;
part_err = mmc_blk_part_switch(host->card, md);
if (part_err) {
return -ENODEV;
}
}
return err;
}
static inline void mmc_blk_reset_success(struct mmc_blk_data *md, int type)
{
md->reset_done &= ~type;
}
static int mmc_blk_issue_discard_rq(struct mmc_queue *mq, struct request *req)
{
struct mmc_blk_data *md = mq->data;
struct mmc_card *card = md->queue.card;
unsigned int from, nr, arg;
int err = 0, type = MMC_BLK_DISCARD;
if (!mmc_can_erase(card)) {
err = -EOPNOTSUPP;
goto out;
}
from = blk_rq_pos(req);
nr = blk_rq_sectors(req);
if (mmc_can_discard(card))
arg = MMC_DISCARD_ARG;
else if (mmc_can_trim(card))
arg = MMC_TRIM_ARG;
else
arg = MMC_ERASE_ARG;
retry:
if (card->quirks & MMC_QUIRK_INAND_CMD38) {
err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
INAND_CMD38_ARG_EXT_CSD,
arg == MMC_TRIM_ARG ?
INAND_CMD38_ARG_TRIM :
INAND_CMD38_ARG_ERASE,
0);
if (err)
goto out;
}
err = mmc_erase(card, from, nr, arg);
out:
if (err == -EIO && !mmc_blk_reset(md, card->host, type))
goto retry;
if (!err)
mmc_blk_reset_success(md, type);
blk_end_request(req, err, blk_rq_bytes(req));
return err ? 0 : 1;
}
static int mmc_blk_issue_secdiscard_rq(struct mmc_queue *mq,
struct request *req)
{
struct mmc_blk_data *md = mq->data;
struct mmc_card *card = md->queue.card;
unsigned int from, nr, arg;
int err = 0, type = MMC_BLK_SECDISCARD;
if (!(mmc_can_secure_erase_trim(card))) {
err = -EOPNOTSUPP;
goto out;
}
from = blk_rq_pos(req);
nr = blk_rq_sectors(req);
if (mmc_can_trim(card) && !mmc_erase_group_aligned(card, from, nr))
arg = MMC_SECURE_TRIM1_ARG;
else
arg = MMC_SECURE_ERASE_ARG;
retry:
if (card->quirks & MMC_QUIRK_INAND_CMD38) {
err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
INAND_CMD38_ARG_EXT_CSD,
arg == MMC_SECURE_TRIM1_ARG ?
INAND_CMD38_ARG_SECTRIM1 :
INAND_CMD38_ARG_SECERASE,
0);
if (err)
goto out_retry;
}
err = mmc_erase(card, from, nr, arg);
if (err == -EIO)
goto out_retry;
if (err)
goto out;
if (arg == MMC_SECURE_TRIM1_ARG) {
if (card->quirks & MMC_QUIRK_INAND_CMD38) {
err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
INAND_CMD38_ARG_EXT_CSD,
INAND_CMD38_ARG_SECTRIM2,
0);
if (err)
goto out_retry;
}
err = mmc_erase(card, from, nr, MMC_SECURE_TRIM2_ARG);
if (err == -EIO)
goto out_retry;
if (err)
goto out;
}
out_retry:
if (err && !mmc_blk_reset(md, card->host, type))
goto retry;
if (!err)
mmc_blk_reset_success(md, type);
out:
blk_end_request(req, err, blk_rq_bytes(req));
return err ? 0 : 1;
}
static int mmc_blk_issue_flush(struct mmc_queue *mq, struct request *req)
{
struct mmc_blk_data *md = mq->data;
struct mmc_card *card = md->queue.card;
int ret = 0;
ret = mmc_flush_cache(card);
if (ret)
ret = -EIO;
blk_end_request_all(req, ret);
return ret ? 0 : 1;
}
static inline void mmc_apply_rel_rw(struct mmc_blk_request *brq,
struct mmc_card *card,
struct request *req)
{
if (!(card->ext_csd.rel_param & EXT_CSD_WR_REL_PARAM_EN)) {
if (!IS_ALIGNED(brq->cmd.arg, card->ext_csd.rel_sectors))
brq->data.blocks = 1;
if (brq->data.blocks > card->ext_csd.rel_sectors)
brq->data.blocks = card->ext_csd.rel_sectors;
else if (brq->data.blocks < card->ext_csd.rel_sectors)
brq->data.blocks = 1;
}
}
static int mmc_blk_err_check(struct mmc_card *card,
struct mmc_async_req *areq)
{
struct mmc_queue_req *mq_mrq = container_of(areq, struct mmc_queue_req,
mmc_active);
struct mmc_blk_request *brq = &mq_mrq->brq;
struct request *req = mq_mrq->req;
int ecc_err = 0, gen_err = 0;
if (brq->sbc.error || brq->cmd.error || brq->stop.error ||
brq->data.error) {
switch (mmc_blk_cmd_recovery(card, req, brq, &ecc_err, &gen_err)) {
case ERR_RETRY:
return MMC_BLK_RETRY;
case ERR_ABORT:
return MMC_BLK_ABORT;
case ERR_NOMEDIUM:
return MMC_BLK_NOMEDIUM;
case ERR_CONTINUE:
break;
}
}
if (brq->cmd.resp[0] & CMD_ERRORS) {
pr_err("%s: r/w command failed, status = %#x\n",
req->rq_disk->disk_name, brq->cmd.resp[0]);
return MMC_BLK_ABORT;
}
if (!mmc_host_is_spi(card->host) && rq_data_dir(req) != READ) {
u32 status;
unsigned long timeout;
if (brq->stop.resp[0] & R1_ERROR) {
pr_err("%s: %s: general error sending stop command, stop cmd response %#x\n",
req->rq_disk->disk_name, __func__,
brq->stop.resp[0]);
gen_err = 1;
}
timeout = jiffies + msecs_to_jiffies(MMC_BLK_TIMEOUT_MS);
do {
int err = get_card_status(card, &status, 5);
if (err) {
pr_err("%s: error %d requesting status\n",
req->rq_disk->disk_name, err);
return MMC_BLK_CMD_ERR;
}
if (status & R1_ERROR) {
pr_err("%s: %s: general error sending status command, card status %#x\n",
req->rq_disk->disk_name, __func__,
status);
gen_err = 1;
}
if (time_after(jiffies, timeout)) {
pr_err("%s: Card stuck in programming state!"\
" %s %s\n", mmc_hostname(card->host),
req->rq_disk->disk_name, __func__);
return MMC_BLK_CMD_ERR;
}
} while (!(status & R1_READY_FOR_DATA) ||
(R1_CURRENT_STATE(status) == R1_STATE_PRG));
}
if (gen_err) {
pr_warn("%s: retrying write for general error\n",
req->rq_disk->disk_name);
return MMC_BLK_RETRY;
}
if (brq->data.error) {
pr_err("%s: error %d transferring data, sector %u, nr %u, cmd response %#x, card status %#x\n",
req->rq_disk->disk_name, brq->data.error,
(unsigned)blk_rq_pos(req),
(unsigned)blk_rq_sectors(req),
brq->cmd.resp[0], brq->stop.resp[0]);
if (rq_data_dir(req) == READ) {
if (ecc_err)
return MMC_BLK_ECC_ERR;
return MMC_BLK_DATA_ERR;
} else {
return MMC_BLK_CMD_ERR;
}
}
if (!brq->data.bytes_xfered)
return MMC_BLK_RETRY;
if (mmc_packed_cmd(mq_mrq->cmd_type)) {
if (unlikely(brq->data.blocks << 9 != brq->data.bytes_xfered))
return MMC_BLK_PARTIAL;
else
return MMC_BLK_SUCCESS;
}
if (blk_rq_bytes(req) != brq->data.bytes_xfered)
return MMC_BLK_PARTIAL;
return MMC_BLK_SUCCESS;
}
static int mmc_blk_packed_err_check(struct mmc_card *card,
struct mmc_async_req *areq)
{
struct mmc_queue_req *mq_rq = container_of(areq, struct mmc_queue_req,
mmc_active);
struct request *req = mq_rq->req;
struct mmc_packed *packed = mq_rq->packed;
int err, check, status;
u8 *ext_csd;
BUG_ON(!packed);
packed->retries--;
check = mmc_blk_err_check(card, areq);
err = get_card_status(card, &status, 0);
if (err) {
pr_err("%s: error %d sending status command\n",
req->rq_disk->disk_name, err);
return MMC_BLK_ABORT;
}
if (status & R1_EXCEPTION_EVENT) {
ext_csd = kzalloc(512, GFP_KERNEL);
if (!ext_csd) {
pr_err("%s: unable to allocate buffer for ext_csd\n",
req->rq_disk->disk_name);
return -ENOMEM;
}
err = mmc_send_ext_csd(card, ext_csd);
if (err) {
pr_err("%s: error %d sending ext_csd\n",
req->rq_disk->disk_name, err);
check = MMC_BLK_ABORT;
goto free;
}
if ((ext_csd[EXT_CSD_EXP_EVENTS_STATUS] &
EXT_CSD_PACKED_FAILURE) &&
(ext_csd[EXT_CSD_PACKED_CMD_STATUS] &
EXT_CSD_PACKED_GENERIC_ERROR)) {
if (ext_csd[EXT_CSD_PACKED_CMD_STATUS] &
EXT_CSD_PACKED_INDEXED_ERROR) {
packed->idx_failure =
ext_csd[EXT_CSD_PACKED_FAILURE_INDEX] - 1;
check = MMC_BLK_PARTIAL;
}
pr_err("%s: packed cmd failed, nr %u, sectors %u, "
"failure index: %d\n",
req->rq_disk->disk_name, packed->nr_entries,
packed->blocks, packed->idx_failure);
}
free:
kfree(ext_csd);
}
return check;
}
static void mmc_blk_rw_rq_prep(struct mmc_queue_req *mqrq,
struct mmc_card *card,
int disable_multi,
struct mmc_queue *mq)
{
u32 readcmd, writecmd;
struct mmc_blk_request *brq = &mqrq->brq;
struct request *req = mqrq->req;
struct mmc_blk_data *md = mq->data;
bool do_data_tag;
bool do_rel_wr = ((req->cmd_flags & REQ_FUA) ||
(req->cmd_flags & REQ_META)) &&
(rq_data_dir(req) == WRITE) &&
(md->flags & MMC_BLK_REL_WR);
memset(brq, 0, sizeof(struct mmc_blk_request));
brq->mrq.cmd = &brq->cmd;
brq->mrq.data = &brq->data;
brq->cmd.arg = blk_rq_pos(req);
if (!mmc_card_blockaddr(card))
brq->cmd.arg <<= 9;
brq->cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_ADTC;
brq->data.blksz = 512;
brq->stop.opcode = MMC_STOP_TRANSMISSION;
brq->stop.arg = 0;
brq->stop.flags = MMC_RSP_SPI_R1B | MMC_RSP_R1B | MMC_CMD_AC;
brq->data.blocks = blk_rq_sectors(req);
if (brq->data.blocks > card->host->max_blk_count)
brq->data.blocks = card->host->max_blk_count;
if (brq->data.blocks > 1) {
if (disable_multi)
brq->data.blocks = 1;
if (card->host->caps2 & MMC_CAP2_NO_MULTI_READ &&
rq_data_dir(req) == READ)
brq->data.blocks = 1;
}
if (brq->data.blocks > 1 || do_rel_wr) {
if (!mmc_host_is_spi(card->host) ||
rq_data_dir(req) == READ)
brq->mrq.stop = &brq->stop;
readcmd = MMC_READ_MULTIPLE_BLOCK;
writecmd = MMC_WRITE_MULTIPLE_BLOCK;
} else {
brq->mrq.stop = NULL;
readcmd = MMC_READ_SINGLE_BLOCK;
writecmd = MMC_WRITE_BLOCK;
}
if (rq_data_dir(req) == READ) {
brq->cmd.opcode = readcmd;
brq->data.flags |= MMC_DATA_READ;
} else {
brq->cmd.opcode = writecmd;
brq->data.flags |= MMC_DATA_WRITE;
}
if (do_rel_wr)
mmc_apply_rel_rw(brq, card, req);
do_data_tag = (card->ext_csd.data_tag_unit_size) &&
(req->cmd_flags & REQ_META) &&
(rq_data_dir(req) == WRITE) &&
((brq->data.blocks * brq->data.blksz) >=
card->ext_csd.data_tag_unit_size);
if ((md->flags & MMC_BLK_CMD23) && mmc_op_multi(brq->cmd.opcode) &&
(do_rel_wr || !(card->quirks & MMC_QUIRK_BLK_NO_CMD23) ||
do_data_tag)) {
brq->sbc.opcode = MMC_SET_BLOCK_COUNT;
brq->sbc.arg = brq->data.blocks |
(do_rel_wr ? (1 << 31) : 0) |
(do_data_tag ? (1 << 29) : 0);
brq->sbc.flags = MMC_RSP_R1 | MMC_CMD_AC;
brq->mrq.sbc = &brq->sbc;
}
mmc_set_data_timeout(&brq->data, card);
brq->data.sg = mqrq->sg;
brq->data.sg_len = mmc_queue_map_sg(mq, mqrq);
if (brq->data.blocks != blk_rq_sectors(req)) {
int i, data_size = brq->data.blocks << 9;
struct scatterlist *sg;
for_each_sg(brq->data.sg, sg, brq->data.sg_len, i) {
data_size -= sg->length;
if (data_size <= 0) {
sg->length += data_size;
i++;
break;
}
}
brq->data.sg_len = i;
}
mqrq->mmc_active.mrq = &brq->mrq;
mqrq->mmc_active.err_check = mmc_blk_err_check;
mmc_queue_bounce_pre(mqrq);
}
static inline u8 mmc_calc_packed_hdr_segs(struct request_queue *q,
struct mmc_card *card)
{
unsigned int hdr_sz = mmc_large_sector(card) ? 4096 : 512;
unsigned int max_seg_sz = queue_max_segment_size(q);
unsigned int len, nr_segs = 0;
do {
len = min(hdr_sz, max_seg_sz);
hdr_sz -= len;
nr_segs++;
} while (hdr_sz);
return nr_segs;
}
static u8 mmc_blk_prep_packed_list(struct mmc_queue *mq, struct request *req)
{
struct request_queue *q = mq->queue;
struct mmc_card *card = mq->card;
struct request *cur = req, *next = NULL;
struct mmc_blk_data *md = mq->data;
struct mmc_queue_req *mqrq = mq->mqrq_cur;
bool en_rel_wr = card->ext_csd.rel_param & EXT_CSD_WR_REL_PARAM_EN;
unsigned int req_sectors = 0, phys_segments = 0;
unsigned int max_blk_count, max_phys_segs;
bool put_back = true;
u8 max_packed_rw = 0;
u8 reqs = 0;
if (!(md->flags & MMC_BLK_PACKED_CMD))
goto no_packed;
if ((rq_data_dir(cur) == WRITE) &&
mmc_host_packed_wr(card->host))
max_packed_rw = card->ext_csd.max_packed_writes;
if (max_packed_rw == 0)
goto no_packed;
if (mmc_req_rel_wr(cur) &&
(md->flags & MMC_BLK_REL_WR) && !en_rel_wr)
goto no_packed;
if (mmc_large_sector(card) &&
!IS_ALIGNED(blk_rq_sectors(cur), 8))
goto no_packed;
mmc_blk_clear_packed(mqrq);
max_blk_count = min(card->host->max_blk_count,
card->host->max_req_size >> 9);
if (unlikely(max_blk_count > 0xffff))
max_blk_count = 0xffff;
max_phys_segs = queue_max_segments(q);
req_sectors += blk_rq_sectors(cur);
phys_segments += cur->nr_phys_segments;
if (rq_data_dir(cur) == WRITE) {
req_sectors += mmc_large_sector(card) ? 8 : 1;
phys_segments += mmc_calc_packed_hdr_segs(q, card);
}
do {
if (reqs >= max_packed_rw - 1) {
put_back = false;
break;
}
spin_lock_irq(q->queue_lock);
next = blk_fetch_request(q);
spin_unlock_irq(q->queue_lock);
if (!next) {
put_back = false;
break;
}
if (mmc_large_sector(card) &&
!IS_ALIGNED(blk_rq_sectors(next), 8))
break;
if (next->cmd_flags & REQ_DISCARD ||
next->cmd_flags & REQ_FLUSH)
break;
if (rq_data_dir(cur) != rq_data_dir(next))
break;
if (mmc_req_rel_wr(next) &&
(md->flags & MMC_BLK_REL_WR) && !en_rel_wr)
break;
req_sectors += blk_rq_sectors(next);
if (req_sectors > max_blk_count)
break;
phys_segments += next->nr_phys_segments;
if (phys_segments > max_phys_segs)
break;
list_add_tail(&next->queuelist, &mqrq->packed->list);
cur = next;
reqs++;
} while (1);
if (put_back) {
spin_lock_irq(q->queue_lock);
blk_requeue_request(q, next);
spin_unlock_irq(q->queue_lock);
}
if (reqs > 0) {
list_add(&req->queuelist, &mqrq->packed->list);
mqrq->packed->nr_entries = ++reqs;
mqrq->packed->retries = reqs;
return reqs;
}
no_packed:
mqrq->cmd_type = MMC_PACKED_NONE;
return 0;
}
static void mmc_blk_packed_hdr_wrq_prep(struct mmc_queue_req *mqrq,
struct mmc_card *card,
struct mmc_queue *mq)
{
struct mmc_blk_request *brq = &mqrq->brq;
struct request *req = mqrq->req;
struct request *prq;
struct mmc_blk_data *md = mq->data;
struct mmc_packed *packed = mqrq->packed;
bool do_rel_wr, do_data_tag;
u32 *packed_cmd_hdr;
u8 hdr_blocks;
u8 i = 1;
BUG_ON(!packed);
mqrq->cmd_type = MMC_PACKED_WRITE;
packed->blocks = 0;
packed->idx_failure = MMC_PACKED_NR_IDX;
packed_cmd_hdr = packed->cmd_hdr;
memset(packed_cmd_hdr, 0, sizeof(packed->cmd_hdr));
packed_cmd_hdr[0] = (packed->nr_entries << 16) |
(PACKED_CMD_WR << 8) | PACKED_CMD_VER;
hdr_blocks = mmc_large_sector(card) ? 8 : 1;
list_for_each_entry(prq, &packed->list, queuelist) {
do_rel_wr = mmc_req_rel_wr(prq) && (md->flags & MMC_BLK_REL_WR);
do_data_tag = (card->ext_csd.data_tag_unit_size) &&
(prq->cmd_flags & REQ_META) &&
(rq_data_dir(prq) == WRITE) &&
((brq->data.blocks * brq->data.blksz) >=
card->ext_csd.data_tag_unit_size);
packed_cmd_hdr[(i * 2)] =
(do_rel_wr ? MMC_CMD23_ARG_REL_WR : 0) |
(do_data_tag ? MMC_CMD23_ARG_TAG_REQ : 0) |
blk_rq_sectors(prq);
packed_cmd_hdr[((i * 2)) + 1] =
mmc_card_blockaddr(card) ?
blk_rq_pos(prq) : blk_rq_pos(prq) << 9;
packed->blocks += blk_rq_sectors(prq);
i++;
}
memset(brq, 0, sizeof(struct mmc_blk_request));
brq->mrq.cmd = &brq->cmd;
brq->mrq.data = &brq->data;
brq->mrq.sbc = &brq->sbc;
brq->mrq.stop = &brq->stop;
brq->sbc.opcode = MMC_SET_BLOCK_COUNT;
brq->sbc.arg = MMC_CMD23_ARG_PACKED | (packed->blocks + hdr_blocks);
brq->sbc.flags = MMC_RSP_R1 | MMC_CMD_AC;
brq->cmd.opcode = MMC_WRITE_MULTIPLE_BLOCK;
brq->cmd.arg = blk_rq_pos(req);
if (!mmc_card_blockaddr(card))
brq->cmd.arg <<= 9;
brq->cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_ADTC;
brq->data.blksz = 512;
brq->data.blocks = packed->blocks + hdr_blocks;
brq->data.flags |= MMC_DATA_WRITE;
brq->stop.opcode = MMC_STOP_TRANSMISSION;
brq->stop.arg = 0;
brq->stop.flags = MMC_RSP_SPI_R1B | MMC_RSP_R1B | MMC_CMD_AC;
mmc_set_data_timeout(&brq->data, card);
brq->data.sg = mqrq->sg;
brq->data.sg_len = mmc_queue_map_sg(mq, mqrq);
mqrq->mmc_active.mrq = &brq->mrq;
mqrq->mmc_active.err_check = mmc_blk_packed_err_check;
mmc_queue_bounce_pre(mqrq);
}
static int mmc_blk_cmd_err(struct mmc_blk_data *md, struct mmc_card *card,
struct mmc_blk_request *brq, struct request *req,
int ret)
{
struct mmc_queue_req *mq_rq;
mq_rq = container_of(brq, struct mmc_queue_req, brq);
if (mmc_card_sd(card)) {
u32 blocks;
blocks = mmc_sd_num_wr_blocks(card);
if (blocks != (u32)-1) {
ret = blk_end_request(req, 0, blocks << 9);
}
} else {
if (!mmc_packed_cmd(mq_rq->cmd_type))
ret = blk_end_request(req, 0, brq->data.bytes_xfered);
}
return ret;
}
static int mmc_blk_end_packed_req(struct mmc_queue_req *mq_rq)
{
struct request *prq;
struct mmc_packed *packed = mq_rq->packed;
int idx = packed->idx_failure, i = 0;
int ret = 0;
BUG_ON(!packed);
while (!list_empty(&packed->list)) {
prq = list_entry_rq(packed->list.next);
if (idx == i) {
packed->nr_entries -= idx;
mq_rq->req = prq;
ret = 1;
if (packed->nr_entries == MMC_PACKED_NR_SINGLE) {
list_del_init(&prq->queuelist);
mmc_blk_clear_packed(mq_rq);
}
return ret;
}
list_del_init(&prq->queuelist);
blk_end_request(prq, 0, blk_rq_bytes(prq));
i++;
}
mmc_blk_clear_packed(mq_rq);
return ret;
}
static void mmc_blk_abort_packed_req(struct mmc_queue_req *mq_rq)
{
struct request *prq;
struct mmc_packed *packed = mq_rq->packed;
BUG_ON(!packed);
while (!list_empty(&packed->list)) {
prq = list_entry_rq(packed->list.next);
list_del_init(&prq->queuelist);
blk_end_request(prq, -EIO, blk_rq_bytes(prq));
}
mmc_blk_clear_packed(mq_rq);
}
static void mmc_blk_revert_packed_req(struct mmc_queue *mq,
struct mmc_queue_req *mq_rq)
{
struct request *prq;
struct request_queue *q = mq->queue;
struct mmc_packed *packed = mq_rq->packed;
BUG_ON(!packed);
while (!list_empty(&packed->list)) {
prq = list_entry_rq(packed->list.prev);
if (prq->queuelist.prev != &packed->list) {
list_del_init(&prq->queuelist);
spin_lock_irq(q->queue_lock);
blk_requeue_request(mq->queue, prq);
spin_unlock_irq(q->queue_lock);
} else {
list_del_init(&prq->queuelist);
}
}
mmc_blk_clear_packed(mq_rq);
}
static int mmc_blk_issue_rw_rq(struct mmc_queue *mq, struct request *rqc)
{
struct mmc_blk_data *md = mq->data;
struct mmc_card *card = md->queue.card;
struct mmc_blk_request *brq = &mq->mqrq_cur->brq;
int ret = 1, disable_multi = 0, retry = 0, type;
enum mmc_blk_status status;
struct mmc_queue_req *mq_rq;
struct request *req = rqc;
struct mmc_async_req *areq;
const u8 packed_nr = 2;
u8 reqs = 0;
if (!rqc && !mq->mqrq_prev->req)
return 0;
if (rqc)
reqs = mmc_blk_prep_packed_list(mq, rqc);
do {
if (rqc) {
if ((brq->data.blocks & 0x07) &&
(card->ext_csd.data_sector_size == 4096)) {
pr_err("%s: Transfer size is not 4KB sector size aligned\n",
req->rq_disk->disk_name);
mq_rq = mq->mqrq_cur;
goto cmd_abort;
}
if (reqs >= packed_nr)
mmc_blk_packed_hdr_wrq_prep(mq->mqrq_cur,
card, mq);
else
mmc_blk_rw_rq_prep(mq->mqrq_cur, card, 0, mq);
areq = &mq->mqrq_cur->mmc_active;
} else
areq = NULL;
areq = mmc_start_req(card->host, areq, (int *) &status);
if (!areq) {
if (status == MMC_BLK_NEW_REQUEST)
mq->flags |= MMC_QUEUE_NEW_REQUEST;
return 0;
}
mq_rq = container_of(areq, struct mmc_queue_req, mmc_active);
brq = &mq_rq->brq;
req = mq_rq->req;
type = rq_data_dir(req) == READ ? MMC_BLK_READ : MMC_BLK_WRITE;
mmc_queue_bounce_post(mq_rq);
switch (status) {
case MMC_BLK_SUCCESS:
case MMC_BLK_PARTIAL:
mmc_blk_reset_success(md, type);
if (mmc_packed_cmd(mq_rq->cmd_type)) {
ret = mmc_blk_end_packed_req(mq_rq);
break;
} else {
ret = blk_end_request(req, 0,
brq->data.bytes_xfered);
}
if (status == MMC_BLK_SUCCESS && ret) {
pr_err("%s BUG rq_tot %d d_xfer %d\n",
__func__, blk_rq_bytes(req),
brq->data.bytes_xfered);
rqc = NULL;
goto cmd_abort;
}
break;
case MMC_BLK_CMD_ERR:
ret = mmc_blk_cmd_err(md, card, brq, req, ret);
if (!mmc_blk_reset(md, card->host, type))
break;
goto cmd_abort;
case MMC_BLK_RETRY:
if (retry++ < 5)
break;
case MMC_BLK_ABORT:
if (!mmc_blk_reset(md, card->host, type))
break;
goto cmd_abort;
case MMC_BLK_DATA_ERR: {
int err;
err = mmc_blk_reset(md, card->host, type);
if (!err)
break;
if (err == -ENODEV ||
mmc_packed_cmd(mq_rq->cmd_type))
goto cmd_abort;
}
case MMC_BLK_ECC_ERR:
if (brq->data.blocks > 1) {
pr_warning("%s: retrying using single block read\n",
req->rq_disk->disk_name);
disable_multi = 1;
break;
}
ret = blk_end_request(req, -EIO,
brq->data.blksz);
if (!ret)
goto start_new_req;
break;
case MMC_BLK_NOMEDIUM:
goto cmd_abort;
default:
pr_err("%s: Unhandled return value (%d)",
req->rq_disk->disk_name, status);
goto cmd_abort;
}
if (ret) {
if (mmc_packed_cmd(mq_rq->cmd_type)) {
if (!mq_rq->packed->retries)
goto cmd_abort;
mmc_blk_packed_hdr_wrq_prep(mq_rq, card, mq);
mmc_start_req(card->host,
&mq_rq->mmc_active, NULL);
} else {
mmc_blk_rw_rq_prep(mq_rq, card,
disable_multi, mq);
mmc_start_req(card->host,
&mq_rq->mmc_active, NULL);
}
}
} while (ret);
return 1;
cmd_abort:
if (mmc_packed_cmd(mq_rq->cmd_type)) {
mmc_blk_abort_packed_req(mq_rq);
} else {
if (mmc_card_removed(card))
req->cmd_flags |= REQ_QUIET;
while (ret)
ret = blk_end_request(req, -EIO,
blk_rq_cur_bytes(req));
}
start_new_req:
if (rqc) {
if (mmc_card_removed(card)) {
rqc->cmd_flags |= REQ_QUIET;
blk_end_request_all(rqc, -EIO);
} else {
if (mmc_packed_cmd(mq->mqrq_cur->cmd_type))
mmc_blk_revert_packed_req(mq, mq->mqrq_cur);
mmc_blk_rw_rq_prep(mq->mqrq_cur, card, 0, mq);
mmc_start_req(card->host,
&mq->mqrq_cur->mmc_active, NULL);
}
}
return 0;
}
static int mmc_blk_issue_rq(struct mmc_queue *mq, struct request *req)
{
int ret;
struct mmc_blk_data *md = mq->data;
struct mmc_card *card = md->queue.card;
struct mmc_host *host = card->host;
unsigned long flags;
if (req && !mq->mqrq_prev->req)
mmc_get_card(card);
ret = mmc_blk_part_switch(card, md);
if (ret) {
if (req) {
blk_end_request_all(req, -EIO);
}
ret = 0;
goto out;
}
mq->flags &= ~MMC_QUEUE_NEW_REQUEST;
if (req && req->cmd_flags & REQ_DISCARD) {
if (card->host->areq)
mmc_blk_issue_rw_rq(mq, NULL);
if (req->cmd_flags & REQ_SECURE &&
!(card->quirks & MMC_QUIRK_SEC_ERASE_TRIM_BROKEN))
ret = mmc_blk_issue_secdiscard_rq(mq, req);
else
ret = mmc_blk_issue_discard_rq(mq, req);
} else if (req && req->cmd_flags & REQ_FLUSH) {
if (card->host->areq)
mmc_blk_issue_rw_rq(mq, NULL);
ret = mmc_blk_issue_flush(mq, req);
} else {
if (!req && host->areq) {
spin_lock_irqsave(&host->context_info.lock, flags);
host->context_info.is_waiting_last_req = true;
spin_unlock_irqrestore(&host->context_info.lock, flags);
}
ret = mmc_blk_issue_rw_rq(mq, req);
}
out:
if ((!req && !(mq->flags & MMC_QUEUE_NEW_REQUEST)) ||
(req && (req->cmd_flags & MMC_REQ_SPECIAL_MASK)))
mmc_put_card(card);
return ret;
}
static inline int mmc_blk_readonly(struct mmc_card *card)
{
return mmc_card_readonly(card) ||
!(card->csd.cmdclass & CCC_BLOCK_WRITE);
}
static struct mmc_blk_data *mmc_blk_alloc_req(struct mmc_card *card,
struct device *parent,
sector_t size,
bool default_ro,
const char *subname,
int area_type)
{
struct mmc_blk_data *md;
int devidx, ret;
devidx = find_first_zero_bit(dev_use, max_devices);
if (devidx >= max_devices)
return ERR_PTR(-ENOSPC);
__set_bit(devidx, dev_use);
md = kzalloc(sizeof(struct mmc_blk_data), GFP_KERNEL);
if (!md) {
ret = -ENOMEM;
goto out;
}
if (!subname) {
md->name_idx = find_first_zero_bit(name_use, max_devices);
__set_bit(md->name_idx, name_use);
} else
md->name_idx = ((struct mmc_blk_data *)
dev_to_disk(parent)->private_data)->name_idx;
md->area_type = area_type;
md->read_only = mmc_blk_readonly(card);
md->disk = alloc_disk(perdev_minors);
if (md->disk == NULL) {
ret = -ENOMEM;
goto err_kfree;
}
spin_lock_init(&md->lock);
INIT_LIST_HEAD(&md->part);
md->usage = 1;
ret = mmc_init_queue(&md->queue, card, &md->lock, subname);
if (ret)
goto err_putdisk;
md->queue.issue_fn = mmc_blk_issue_rq;
md->queue.data = md;
md->disk->major = MMC_BLOCK_MAJOR;
md->disk->first_minor = devidx * perdev_minors;
md->disk->fops = &mmc_bdops;
md->disk->private_data = md;
md->disk->queue = md->queue.queue;
md->disk->driverfs_dev = parent;
set_disk_ro(md->disk, md->read_only || default_ro);
if (area_type & MMC_BLK_DATA_AREA_RPMB)
md->disk->flags |= GENHD_FL_NO_PART_SCAN;
snprintf(md->disk->disk_name, sizeof(md->disk->disk_name),
"mmcblk%d%s", md->name_idx, subname ? subname : "");
if (mmc_card_mmc(card))
blk_queue_logical_block_size(md->queue.queue,
card->ext_csd.data_sector_size);
else
blk_queue_logical_block_size(md->queue.queue, 512);
set_capacity(md->disk, size);
if (mmc_host_cmd23(card->host)) {
if (mmc_card_mmc(card) ||
(mmc_card_sd(card) &&
card->scr.cmds & SD_SCR_CMD23_SUPPORT))
md->flags |= MMC_BLK_CMD23;
}
if (mmc_card_mmc(card) &&
md->flags & MMC_BLK_CMD23 &&
((card->ext_csd.rel_param & EXT_CSD_WR_REL_PARAM_EN) ||
card->ext_csd.rel_sectors)) {
md->flags |= MMC_BLK_REL_WR;
blk_queue_flush(md->queue.queue, REQ_FLUSH | REQ_FUA);
}
if (mmc_card_mmc(card) &&
(area_type == MMC_BLK_DATA_AREA_MAIN) &&
(md->flags & MMC_BLK_CMD23) &&
card->ext_csd.packed_event_en) {
if (!mmc_packed_init(&md->queue, card))
md->flags |= MMC_BLK_PACKED_CMD;
}
return md;
err_putdisk:
put_disk(md->disk);
err_kfree:
kfree(md);
out:
return ERR_PTR(ret);
}
static struct mmc_blk_data *mmc_blk_alloc(struct mmc_card *card)
{
sector_t size;
struct mmc_blk_data *md;
if (!mmc_card_sd(card) && mmc_card_blockaddr(card)) {
size = card->ext_csd.sectors;
} else {
size = card->csd.capacity << (card->csd.read_blkbits - 9);
}
md = mmc_blk_alloc_req(card, &card->dev, size, false, NULL,
MMC_BLK_DATA_AREA_MAIN);
return md;
}
static int mmc_blk_alloc_part(struct mmc_card *card,
struct mmc_blk_data *md,
unsigned int part_type,
sector_t size,
bool default_ro,
const char *subname,
int area_type)
{
char cap_str[10];
struct mmc_blk_data *part_md;
part_md = mmc_blk_alloc_req(card, disk_to_dev(md->disk), size, default_ro,
subname, area_type);
if (IS_ERR(part_md))
return PTR_ERR(part_md);
part_md->part_type = part_type;
list_add(&part_md->part, &md->part);
string_get_size((u64)get_capacity(part_md->disk) << 9, STRING_UNITS_2,
cap_str, sizeof(cap_str));
pr_info("%s: %s %s partition %u %s\n",
part_md->disk->disk_name, mmc_card_id(card),
mmc_card_name(card), part_md->part_type, cap_str);
return 0;
}
static int mmc_blk_alloc_parts(struct mmc_card *card, struct mmc_blk_data *md)
{
int idx, ret = 0;
if (!mmc_card_mmc(card))
return 0;
for (idx = 0; idx < card->nr_parts; idx++) {
if (card->part[idx].size) {
ret = mmc_blk_alloc_part(card, md,
card->part[idx].part_cfg,
card->part[idx].size >> 9,
card->part[idx].force_ro,
card->part[idx].name,
card->part[idx].area_type);
if (ret)
return ret;
}
}
return ret;
}
static void mmc_blk_remove_req(struct mmc_blk_data *md)
{
struct mmc_card *card;
if (md) {
card = md->queue.card;
mmc_cleanup_queue(&md->queue);
if (md->flags & MMC_BLK_PACKED_CMD)
mmc_packed_clean(&md->queue);
if (md->disk->flags & GENHD_FL_UP) {
device_remove_file(disk_to_dev(md->disk), &md->force_ro);
if ((md->area_type & MMC_BLK_DATA_AREA_BOOT) &&
card->ext_csd.boot_ro_lockable)
device_remove_file(disk_to_dev(md->disk),
&md->power_ro_lock);
del_gendisk(md->disk);
}
mmc_blk_put(md);
}
}
static void mmc_blk_remove_parts(struct mmc_card *card,
struct mmc_blk_data *md)
{
struct list_head *pos, *q;
struct mmc_blk_data *part_md;
__clear_bit(md->name_idx, name_use);
list_for_each_safe(pos, q, &md->part) {
part_md = list_entry(pos, struct mmc_blk_data, part);
list_del(pos);
mmc_blk_remove_req(part_md);
}
}
static int mmc_add_disk(struct mmc_blk_data *md)
{
int ret;
struct mmc_card *card = md->queue.card;
add_disk(md->disk);
md->force_ro.show = force_ro_show;
md->force_ro.store = force_ro_store;
sysfs_attr_init(&md->force_ro.attr);
md->force_ro.attr.name = "force_ro";
md->force_ro.attr.mode = S_IRUGO | S_IWUSR;
ret = device_create_file(disk_to_dev(md->disk), &md->force_ro);
if (ret)
goto force_ro_fail;
if ((md->area_type & MMC_BLK_DATA_AREA_BOOT) &&
card->ext_csd.boot_ro_lockable) {
umode_t mode;
if (card->ext_csd.boot_ro_lock & EXT_CSD_BOOT_WP_B_PWR_WP_DIS)
mode = S_IRUGO;
else
mode = S_IRUGO | S_IWUSR;
md->power_ro_lock.show = power_ro_lock_show;
md->power_ro_lock.store = power_ro_lock_store;
sysfs_attr_init(&md->power_ro_lock.attr);
md->power_ro_lock.attr.mode = mode;
md->power_ro_lock.attr.name =
"ro_lock_until_next_power_on";
ret = device_create_file(disk_to_dev(md->disk),
&md->power_ro_lock);
if (ret)
goto power_ro_lock_fail;
}
return ret;
power_ro_lock_fail:
device_remove_file(disk_to_dev(md->disk), &md->force_ro);
force_ro_fail:
del_gendisk(md->disk);
return ret;
}
static int mmc_blk_probe(struct mmc_card *card)
{
struct mmc_blk_data *md, *part_md;
char cap_str[10];
if (!(card->csd.cmdclass & CCC_BLOCK_READ))
return -ENODEV;
md = mmc_blk_alloc(card);
if (IS_ERR(md))
return PTR_ERR(md);
string_get_size((u64)get_capacity(md->disk) << 9, STRING_UNITS_2,
cap_str, sizeof(cap_str));
pr_info("%s: %s %s %s %s\n",
md->disk->disk_name, mmc_card_id(card), mmc_card_name(card),
cap_str, md->read_only ? "(ro)" : "");
if (mmc_blk_alloc_parts(card, md))
goto out;
mmc_set_drvdata(card, md);
mmc_fixup_device(card, blk_fixups);
if (mmc_add_disk(md))
goto out;
list_for_each_entry(part_md, &md->part, part) {
if (mmc_add_disk(part_md))
goto out;
}
pm_runtime_set_autosuspend_delay(&card->dev, 3000);
pm_runtime_use_autosuspend(&card->dev);
if (card->type != MMC_TYPE_SD_COMBO) {
pm_runtime_set_active(&card->dev);
pm_runtime_enable(&card->dev);
}
return 0;
out:
mmc_blk_remove_parts(card, md);
mmc_blk_remove_req(md);
return 0;
}
static void mmc_blk_remove(struct mmc_card *card)
{
struct mmc_blk_data *md = mmc_get_drvdata(card);
mmc_blk_remove_parts(card, md);
pm_runtime_get_sync(&card->dev);
mmc_claim_host(card->host);
mmc_blk_part_switch(card, md);
mmc_release_host(card->host);
if (card->type != MMC_TYPE_SD_COMBO)
pm_runtime_disable(&card->dev);
pm_runtime_put_noidle(&card->dev);
mmc_blk_remove_req(md);
mmc_set_drvdata(card, NULL);
}
static int _mmc_blk_suspend(struct mmc_card *card)
{
struct mmc_blk_data *part_md;
struct mmc_blk_data *md = mmc_get_drvdata(card);
if (md) {
pm_runtime_get_sync(&card->dev);
mmc_queue_suspend(&md->queue);
list_for_each_entry(part_md, &md->part, part) {
mmc_queue_suspend(&part_md->queue);
}
}
return 0;
}
static void mmc_blk_shutdown(struct mmc_card *card)
{
_mmc_blk_suspend(card);
}
static int mmc_blk_suspend(struct mmc_card *card)
{
return _mmc_blk_suspend(card);
}
static int mmc_blk_resume(struct mmc_card *card)
{
struct mmc_blk_data *part_md;
struct mmc_blk_data *md = mmc_get_drvdata(card);
if (md) {
md->part_curr = md->part_type;
mmc_queue_resume(&md->queue);
list_for_each_entry(part_md, &md->part, part) {
mmc_queue_resume(&part_md->queue);
}
pm_runtime_put(&card->dev);
}
return 0;
}
static int __init mmc_blk_init(void)
{
int res;
if (perdev_minors != CONFIG_MMC_BLOCK_MINORS)
pr_info("mmcblk: using %d minors per device\n", perdev_minors);
max_devices = 256 / perdev_minors;
res = register_blkdev(MMC_BLOCK_MAJOR, "mmc");
if (res)
goto out;
res = mmc_register_driver(&mmc_driver);
if (res)
goto out2;
return 0;
out2:
unregister_blkdev(MMC_BLOCK_MAJOR, "mmc");
out:
return res;
}
static void __exit mmc_blk_exit(void)
{
mmc_unregister_driver(&mmc_driver);
unregister_blkdev(MMC_BLOCK_MAJOR, "mmc");
}
