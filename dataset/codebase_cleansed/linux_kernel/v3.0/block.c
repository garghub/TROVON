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
static int mmc_blk_release(struct gendisk *disk, fmode_t mode)
{
struct mmc_blk_data *md = disk->private_data;
mutex_lock(&block_mutex);
mmc_blk_put(md);
mutex_unlock(&block_mutex);
return 0;
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
static int mmc_blk_ioctl_cmd(struct block_device *bdev,
struct mmc_ioc_cmd __user *ic_ptr)
{
struct mmc_blk_ioc_data *idata;
struct mmc_blk_data *md;
struct mmc_card *card;
struct mmc_command cmd = {0};
struct mmc_data data = {0};
struct mmc_request mrq = {0};
struct scatterlist sg;
int err;
if ((!capable(CAP_SYS_RAWIO)) || (bdev != bdev->bd_contains))
return -EPERM;
idata = mmc_blk_ioctl_copy_from_user(ic_ptr);
if (IS_ERR(idata))
return PTR_ERR(idata);
cmd.opcode = idata->ic.opcode;
cmd.arg = idata->ic.arg;
cmd.flags = idata->ic.flags;
data.sg = &sg;
data.sg_len = 1;
data.blksz = idata->ic.blksz;
data.blocks = idata->ic.blocks;
sg_init_one(data.sg, idata->buf, idata->buf_bytes);
if (idata->ic.write_flag)
data.flags = MMC_DATA_WRITE;
else
data.flags = MMC_DATA_READ;
mrq.cmd = &cmd;
mrq.data = &data;
md = mmc_blk_get(bdev->bd_disk);
if (!md) {
err = -EINVAL;
goto cmd_done;
}
card = md->queue.card;
if (IS_ERR(card)) {
err = PTR_ERR(card);
goto cmd_done;
}
mmc_claim_host(card->host);
if (idata->ic.is_acmd) {
err = mmc_app_cmd(card->host, card);
if (err)
goto cmd_rel_host;
}
mmc_set_data_timeout(&data, card);
if (idata->ic.data_timeout_ns)
data.timeout_ns = idata->ic.data_timeout_ns;
if ((cmd.flags & MMC_RSP_R1B) == MMC_RSP_R1B) {
data.timeout_ns = idata->ic.cmd_timeout_ms * 1000000;
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
cmd_rel_host:
mmc_release_host(card->host);
cmd_done:
mmc_blk_put(md);
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
card->ext_csd.part_config &= ~EXT_CSD_PART_CONFIG_ACC_MASK;
card->ext_csd.part_config |= md->part_type;
ret = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
EXT_CSD_PART_CONFIG, card->ext_csd.part_config,
card->ext_csd.part_time);
if (ret)
return ret;
}
main_md->part_curr = md->part_type;
return 0;
}
static u32 mmc_sd_num_wr_blocks(struct mmc_card *card)
{
int err;
u32 result;
__be32 *blocks;
struct mmc_request mrq = {0};
struct mmc_command cmd = {0};
struct mmc_data data = {0};
unsigned int timeout_us;
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
data.timeout_ns = card->csd.tacc_ns * 100;
data.timeout_clks = card->csd.tacc_clks * 100;
timeout_us = data.timeout_ns / 1000;
timeout_us += data.timeout_clks * 1000 /
(card->host->ios.clock / 1000);
if (timeout_us > 100000) {
data.timeout_ns = 100000000;
data.timeout_clks = 0;
}
data.blksz = 4;
data.blocks = 1;
data.flags = MMC_DATA_READ;
data.sg = &sg;
data.sg_len = 1;
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
static u32 get_card_status(struct mmc_card *card, struct request *req)
{
struct mmc_command cmd = {0};
int err;
cmd.opcode = MMC_SEND_STATUS;
if (!mmc_host_is_spi(card->host))
cmd.arg = card->rca << 16;
cmd.flags = MMC_RSP_SPI_R2 | MMC_RSP_R1 | MMC_CMD_AC;
err = mmc_wait_for_cmd(card->host, &cmd, 0);
if (err)
printk(KERN_ERR "%s: error %d sending status command",
req->rq_disk->disk_name, err);
return cmd.resp[0];
}
static int mmc_blk_issue_discard_rq(struct mmc_queue *mq, struct request *req)
{
struct mmc_blk_data *md = mq->data;
struct mmc_card *card = md->queue.card;
unsigned int from, nr, arg;
int err = 0;
if (!mmc_can_erase(card)) {
err = -EOPNOTSUPP;
goto out;
}
from = blk_rq_pos(req);
nr = blk_rq_sectors(req);
if (mmc_can_trim(card))
arg = MMC_TRIM_ARG;
else
arg = MMC_ERASE_ARG;
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
spin_lock_irq(&md->lock);
__blk_end_request(req, err, blk_rq_bytes(req));
spin_unlock_irq(&md->lock);
return err ? 0 : 1;
}
static int mmc_blk_issue_secdiscard_rq(struct mmc_queue *mq,
struct request *req)
{
struct mmc_blk_data *md = mq->data;
struct mmc_card *card = md->queue.card;
unsigned int from, nr, arg;
int err = 0;
if (!mmc_can_secure_erase_trim(card)) {
err = -EOPNOTSUPP;
goto out;
}
from = blk_rq_pos(req);
nr = blk_rq_sectors(req);
if (mmc_can_trim(card) && !mmc_erase_group_aligned(card, from, nr))
arg = MMC_SECURE_TRIM1_ARG;
else
arg = MMC_SECURE_ERASE_ARG;
if (card->quirks & MMC_QUIRK_INAND_CMD38) {
err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
INAND_CMD38_ARG_EXT_CSD,
arg == MMC_SECURE_TRIM1_ARG ?
INAND_CMD38_ARG_SECTRIM1 :
INAND_CMD38_ARG_SECERASE,
0);
if (err)
goto out;
}
err = mmc_erase(card, from, nr, arg);
if (!err && arg == MMC_SECURE_TRIM1_ARG) {
if (card->quirks & MMC_QUIRK_INAND_CMD38) {
err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
INAND_CMD38_ARG_EXT_CSD,
INAND_CMD38_ARG_SECTRIM2,
0);
if (err)
goto out;
}
err = mmc_erase(card, from, nr, MMC_SECURE_TRIM2_ARG);
}
out:
spin_lock_irq(&md->lock);
__blk_end_request(req, err, blk_rq_bytes(req));
spin_unlock_irq(&md->lock);
return err ? 0 : 1;
}
static int mmc_blk_issue_flush(struct mmc_queue *mq, struct request *req)
{
struct mmc_blk_data *md = mq->data;
spin_lock_irq(&md->lock);
__blk_end_request_all(req, 0);
spin_unlock_irq(&md->lock);
return 1;
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
static int mmc_blk_issue_rw_rq(struct mmc_queue *mq, struct request *req)
{
struct mmc_blk_data *md = mq->data;
struct mmc_card *card = md->queue.card;
struct mmc_blk_request brq;
int ret = 1, disable_multi = 0;
bool do_rel_wr = ((req->cmd_flags & REQ_FUA) ||
(req->cmd_flags & REQ_META)) &&
(rq_data_dir(req) == WRITE) &&
(md->flags & MMC_BLK_REL_WR);
do {
struct mmc_command cmd = {0};
u32 readcmd, writecmd, status = 0;
memset(&brq, 0, sizeof(struct mmc_blk_request));
brq.mrq.cmd = &brq.cmd;
brq.mrq.data = &brq.data;
brq.cmd.arg = blk_rq_pos(req);
if (!mmc_card_blockaddr(card))
brq.cmd.arg <<= 9;
brq.cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_ADTC;
brq.data.blksz = 512;
brq.stop.opcode = MMC_STOP_TRANSMISSION;
brq.stop.arg = 0;
brq.stop.flags = MMC_RSP_SPI_R1B | MMC_RSP_R1B | MMC_CMD_AC;
brq.data.blocks = blk_rq_sectors(req);
if (brq.data.blocks > card->host->max_blk_count)
brq.data.blocks = card->host->max_blk_count;
if (disable_multi && brq.data.blocks > 1)
brq.data.blocks = 1;
if (brq.data.blocks > 1 || do_rel_wr) {
if (!mmc_host_is_spi(card->host) ||
rq_data_dir(req) == READ)
brq.mrq.stop = &brq.stop;
readcmd = MMC_READ_MULTIPLE_BLOCK;
writecmd = MMC_WRITE_MULTIPLE_BLOCK;
} else {
brq.mrq.stop = NULL;
readcmd = MMC_READ_SINGLE_BLOCK;
writecmd = MMC_WRITE_BLOCK;
}
if (rq_data_dir(req) == READ) {
brq.cmd.opcode = readcmd;
brq.data.flags |= MMC_DATA_READ;
} else {
brq.cmd.opcode = writecmd;
brq.data.flags |= MMC_DATA_WRITE;
}
if (do_rel_wr)
mmc_apply_rel_rw(&brq, card, req);
if ((md->flags & MMC_BLK_CMD23) &&
mmc_op_multi(brq.cmd.opcode) &&
(do_rel_wr || !(card->quirks & MMC_QUIRK_BLK_NO_CMD23))) {
brq.sbc.opcode = MMC_SET_BLOCK_COUNT;
brq.sbc.arg = brq.data.blocks |
(do_rel_wr ? (1 << 31) : 0);
brq.sbc.flags = MMC_RSP_R1 | MMC_CMD_AC;
brq.mrq.sbc = &brq.sbc;
}
mmc_set_data_timeout(&brq.data, card);
brq.data.sg = mq->sg;
brq.data.sg_len = mmc_queue_map_sg(mq);
if (brq.data.blocks != blk_rq_sectors(req)) {
int i, data_size = brq.data.blocks << 9;
struct scatterlist *sg;
for_each_sg(brq.data.sg, sg, brq.data.sg_len, i) {
data_size -= sg->length;
if (data_size <= 0) {
sg->length += data_size;
i++;
break;
}
}
brq.data.sg_len = i;
}
mmc_queue_bounce_pre(mq);
mmc_wait_for_req(card->host, &brq.mrq);
mmc_queue_bounce_post(mq);
if (brq.sbc.error || brq.cmd.error ||
brq.data.error || brq.stop.error) {
if (brq.data.blocks > 1 && rq_data_dir(req) == READ) {
printk(KERN_WARNING "%s: retrying using single "
"block read\n", req->rq_disk->disk_name);
disable_multi = 1;
continue;
}
status = get_card_status(card, req);
}
if (brq.sbc.error) {
printk(KERN_ERR "%s: error %d sending SET_BLOCK_COUNT "
"command, response %#x, card status %#x\n",
req->rq_disk->disk_name, brq.sbc.error,
brq.sbc.resp[0], status);
}
if (brq.cmd.error) {
printk(KERN_ERR "%s: error %d sending read/write "
"command, response %#x, card status %#x\n",
req->rq_disk->disk_name, brq.cmd.error,
brq.cmd.resp[0], status);
}
if (brq.data.error) {
if (brq.data.error == -ETIMEDOUT && brq.mrq.stop)
status = brq.mrq.stop->resp[0];
printk(KERN_ERR "%s: error %d transferring data,"
" sector %u, nr %u, card status %#x\n",
req->rq_disk->disk_name, brq.data.error,
(unsigned)blk_rq_pos(req),
(unsigned)blk_rq_sectors(req), status);
}
if (brq.stop.error) {
printk(KERN_ERR "%s: error %d sending stop command, "
"response %#x, card status %#x\n",
req->rq_disk->disk_name, brq.stop.error,
brq.stop.resp[0], status);
}
if (!mmc_host_is_spi(card->host) && rq_data_dir(req) != READ) {
do {
int err;
cmd.opcode = MMC_SEND_STATUS;
cmd.arg = card->rca << 16;
cmd.flags = MMC_RSP_R1 | MMC_CMD_AC;
err = mmc_wait_for_cmd(card->host, &cmd, 5);
if (err) {
printk(KERN_ERR "%s: error %d requesting status\n",
req->rq_disk->disk_name, err);
goto cmd_err;
}
} while (!(cmd.resp[0] & R1_READY_FOR_DATA) ||
(R1_CURRENT_STATE(cmd.resp[0]) == 7));
#if 0
if (cmd.resp[0] & ~0x00000900)
printk(KERN_ERR "%s: status = %08x\n",
req->rq_disk->disk_name, cmd.resp[0]);
if (mmc_decode_status(cmd.resp))
goto cmd_err;
#endif
}
if (brq.cmd.error || brq.stop.error || brq.data.error) {
if (rq_data_dir(req) == READ) {
spin_lock_irq(&md->lock);
ret = __blk_end_request(req, -EIO, brq.data.blksz);
spin_unlock_irq(&md->lock);
continue;
}
goto cmd_err;
}
spin_lock_irq(&md->lock);
ret = __blk_end_request(req, 0, brq.data.bytes_xfered);
spin_unlock_irq(&md->lock);
} while (ret);
return 1;
cmd_err:
if (mmc_card_sd(card)) {
u32 blocks;
blocks = mmc_sd_num_wr_blocks(card);
if (blocks != (u32)-1) {
spin_lock_irq(&md->lock);
ret = __blk_end_request(req, 0, blocks << 9);
spin_unlock_irq(&md->lock);
}
} else {
spin_lock_irq(&md->lock);
ret = __blk_end_request(req, 0, brq.data.bytes_xfered);
spin_unlock_irq(&md->lock);
}
spin_lock_irq(&md->lock);
while (ret)
ret = __blk_end_request(req, -EIO, blk_rq_cur_bytes(req));
spin_unlock_irq(&md->lock);
return 0;
}
static int mmc_blk_issue_rq(struct mmc_queue *mq, struct request *req)
{
int ret;
struct mmc_blk_data *md = mq->data;
struct mmc_card *card = md->queue.card;
mmc_claim_host(card->host);
ret = mmc_blk_part_switch(card, md);
if (ret) {
ret = 0;
goto out;
}
if (req->cmd_flags & REQ_DISCARD) {
if (req->cmd_flags & REQ_SECURE)
ret = mmc_blk_issue_secdiscard_rq(mq, req);
else
ret = mmc_blk_issue_discard_rq(mq, req);
} else if (req->cmd_flags & REQ_FLUSH) {
ret = mmc_blk_issue_flush(mq, req);
} else {
ret = mmc_blk_issue_rw_rq(mq, req);
}
out:
mmc_release_host(card->host);
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
const char *subname)
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
}
else
md->name_idx = ((struct mmc_blk_data *)
dev_to_disk(parent)->private_data)->name_idx;
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
snprintf(md->disk->disk_name, sizeof(md->disk->disk_name),
"mmcblk%d%s", md->name_idx, subname ? subname : "");
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
md = mmc_blk_alloc_req(card, &card->dev, size, false, NULL);
return md;
}
static int mmc_blk_alloc_part(struct mmc_card *card,
struct mmc_blk_data *md,
unsigned int part_type,
sector_t size,
bool default_ro,
const char *subname)
{
char cap_str[10];
struct mmc_blk_data *part_md;
part_md = mmc_blk_alloc_req(card, disk_to_dev(md->disk), size, default_ro,
subname);
if (IS_ERR(part_md))
return PTR_ERR(part_md);
part_md->part_type = part_type;
list_add(&part_md->part, &md->part);
string_get_size((u64)get_capacity(part_md->disk) << 9, STRING_UNITS_2,
cap_str, sizeof(cap_str));
printk(KERN_INFO "%s: %s %s partition %u %s\n",
part_md->disk->disk_name, mmc_card_id(card),
mmc_card_name(card), part_md->part_type, cap_str);
return 0;
}
static int mmc_blk_alloc_parts(struct mmc_card *card, struct mmc_blk_data *md)
{
int ret = 0;
if (!mmc_card_mmc(card))
return 0;
if (card->ext_csd.boot_size) {
ret = mmc_blk_alloc_part(card, md, EXT_CSD_PART_CONFIG_ACC_BOOT0,
card->ext_csd.boot_size >> 9,
true,
"boot0");
if (ret)
return ret;
ret = mmc_blk_alloc_part(card, md, EXT_CSD_PART_CONFIG_ACC_BOOT1,
card->ext_csd.boot_size >> 9,
true,
"boot1");
if (ret)
return ret;
}
return ret;
}
static int
mmc_blk_set_blksize(struct mmc_blk_data *md, struct mmc_card *card)
{
int err;
mmc_claim_host(card->host);
err = mmc_set_blocklen(card, 512);
mmc_release_host(card->host);
if (err) {
printk(KERN_ERR "%s: unable to set block size to 512: %d\n",
md->disk->disk_name, err);
return -EINVAL;
}
return 0;
}
static void mmc_blk_remove_req(struct mmc_blk_data *md)
{
if (md) {
if (md->disk->flags & GENHD_FL_UP) {
device_remove_file(disk_to_dev(md->disk), &md->force_ro);
del_gendisk(md->disk);
}
mmc_cleanup_queue(&md->queue);
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
add_disk(md->disk);
md->force_ro.show = force_ro_show;
md->force_ro.store = force_ro_store;
sysfs_attr_init(&md->force_ro.attr);
md->force_ro.attr.name = "force_ro";
md->force_ro.attr.mode = S_IRUGO | S_IWUSR;
ret = device_create_file(disk_to_dev(md->disk), &md->force_ro);
if (ret)
del_gendisk(md->disk);
return ret;
}
static int mmc_blk_probe(struct mmc_card *card)
{
struct mmc_blk_data *md, *part_md;
int err;
char cap_str[10];
if (!(card->csd.cmdclass & CCC_BLOCK_READ))
return -ENODEV;
md = mmc_blk_alloc(card);
if (IS_ERR(md))
return PTR_ERR(md);
err = mmc_blk_set_blksize(md, card);
if (err)
goto out;
string_get_size((u64)get_capacity(md->disk) << 9, STRING_UNITS_2,
cap_str, sizeof(cap_str));
printk(KERN_INFO "%s: %s %s %s %s\n",
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
return 0;
out:
mmc_blk_remove_parts(card, md);
mmc_blk_remove_req(md);
return err;
}
static void mmc_blk_remove(struct mmc_card *card)
{
struct mmc_blk_data *md = mmc_get_drvdata(card);
mmc_blk_remove_parts(card, md);
mmc_claim_host(card->host);
mmc_blk_part_switch(card, md);
mmc_release_host(card->host);
mmc_blk_remove_req(md);
mmc_set_drvdata(card, NULL);
}
static int mmc_blk_suspend(struct mmc_card *card, pm_message_t state)
{
struct mmc_blk_data *part_md;
struct mmc_blk_data *md = mmc_get_drvdata(card);
if (md) {
mmc_queue_suspend(&md->queue);
list_for_each_entry(part_md, &md->part, part) {
mmc_queue_suspend(&part_md->queue);
}
}
return 0;
}
static int mmc_blk_resume(struct mmc_card *card)
{
struct mmc_blk_data *part_md;
struct mmc_blk_data *md = mmc_get_drvdata(card);
if (md) {
mmc_blk_set_blksize(md, card);
md->part_curr = md->part_type;
mmc_queue_resume(&md->queue);
list_for_each_entry(part_md, &md->part, part) {
mmc_queue_resume(&part_md->queue);
}
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
