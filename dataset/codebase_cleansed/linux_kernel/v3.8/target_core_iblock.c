static inline struct iblock_dev *IBLOCK_DEV(struct se_device *dev)
{
return container_of(dev, struct iblock_dev, dev);
}
static int iblock_attach_hba(struct se_hba *hba, u32 host_id)
{
pr_debug("CORE_HBA[%d] - TCM iBlock HBA Driver %s on"
" Generic Target Core Stack %s\n", hba->hba_id,
IBLOCK_VERSION, TARGET_CORE_MOD_VERSION);
return 0;
}
static void iblock_detach_hba(struct se_hba *hba)
{
}
static struct se_device *iblock_alloc_device(struct se_hba *hba, const char *name)
{
struct iblock_dev *ib_dev = NULL;
ib_dev = kzalloc(sizeof(struct iblock_dev), GFP_KERNEL);
if (!ib_dev) {
pr_err("Unable to allocate struct iblock_dev\n");
return NULL;
}
pr_debug( "IBLOCK: Allocated ib_dev for %s\n", name);
return &ib_dev->dev;
}
static int iblock_configure_device(struct se_device *dev)
{
struct iblock_dev *ib_dev = IBLOCK_DEV(dev);
struct request_queue *q;
struct block_device *bd = NULL;
fmode_t mode;
int ret = -ENOMEM;
if (!(ib_dev->ibd_flags & IBDF_HAS_UDEV_PATH)) {
pr_err("Missing udev_path= parameters for IBLOCK\n");
return -EINVAL;
}
ib_dev->ibd_bio_set = bioset_create(IBLOCK_BIO_POOL_SIZE, 0);
if (!ib_dev->ibd_bio_set) {
pr_err("IBLOCK: Unable to create bioset\n");
goto out;
}
pr_debug( "IBLOCK: Claiming struct block_device: %s\n",
ib_dev->ibd_udev_path);
mode = FMODE_READ|FMODE_EXCL;
if (!ib_dev->ibd_readonly)
mode |= FMODE_WRITE;
bd = blkdev_get_by_path(ib_dev->ibd_udev_path, mode, ib_dev);
if (IS_ERR(bd)) {
ret = PTR_ERR(bd);
goto out_free_bioset;
}
ib_dev->ibd_bd = bd;
q = bdev_get_queue(bd);
dev->dev_attrib.hw_block_size = bdev_logical_block_size(bd);
dev->dev_attrib.hw_max_sectors = UINT_MAX;
dev->dev_attrib.hw_queue_depth = q->nr_requests;
if (blk_queue_discard(q)) {
dev->dev_attrib.max_unmap_lba_count =
q->limits.max_discard_sectors;
dev->dev_attrib.max_unmap_block_desc_count = 1;
dev->dev_attrib.unmap_granularity =
q->limits.discard_granularity >> 9;
dev->dev_attrib.unmap_granularity_alignment =
q->limits.discard_alignment;
pr_debug("IBLOCK: BLOCK Discard support available,"
" disabled by default\n");
}
dev->dev_attrib.max_write_same_len = 0xFFFF;
if (blk_queue_nonrot(q))
dev->dev_attrib.is_nonrot = 1;
return 0;
out_free_bioset:
bioset_free(ib_dev->ibd_bio_set);
ib_dev->ibd_bio_set = NULL;
out:
return ret;
}
static void iblock_free_device(struct se_device *dev)
{
struct iblock_dev *ib_dev = IBLOCK_DEV(dev);
if (ib_dev->ibd_bd != NULL)
blkdev_put(ib_dev->ibd_bd, FMODE_WRITE|FMODE_READ|FMODE_EXCL);
if (ib_dev->ibd_bio_set != NULL)
bioset_free(ib_dev->ibd_bio_set);
kfree(ib_dev);
}
static unsigned long long iblock_emulate_read_cap_with_block_size(
struct se_device *dev,
struct block_device *bd,
struct request_queue *q)
{
unsigned long long blocks_long = (div_u64(i_size_read(bd->bd_inode),
bdev_logical_block_size(bd)) - 1);
u32 block_size = bdev_logical_block_size(bd);
if (block_size == dev->dev_attrib.block_size)
return blocks_long;
switch (block_size) {
case 4096:
switch (dev->dev_attrib.block_size) {
case 2048:
blocks_long <<= 1;
break;
case 1024:
blocks_long <<= 2;
break;
case 512:
blocks_long <<= 3;
default:
break;
}
break;
case 2048:
switch (dev->dev_attrib.block_size) {
case 4096:
blocks_long >>= 1;
break;
case 1024:
blocks_long <<= 1;
break;
case 512:
blocks_long <<= 2;
break;
default:
break;
}
break;
case 1024:
switch (dev->dev_attrib.block_size) {
case 4096:
blocks_long >>= 2;
break;
case 2048:
blocks_long >>= 1;
break;
case 512:
blocks_long <<= 1;
break;
default:
break;
}
break;
case 512:
switch (dev->dev_attrib.block_size) {
case 4096:
blocks_long >>= 3;
break;
case 2048:
blocks_long >>= 2;
break;
case 1024:
blocks_long >>= 1;
break;
default:
break;
}
break;
default:
break;
}
return blocks_long;
}
static void iblock_complete_cmd(struct se_cmd *cmd)
{
struct iblock_req *ibr = cmd->priv;
u8 status;
if (!atomic_dec_and_test(&ibr->pending))
return;
if (atomic_read(&ibr->ib_bio_err_cnt))
status = SAM_STAT_CHECK_CONDITION;
else
status = SAM_STAT_GOOD;
target_complete_cmd(cmd, status);
kfree(ibr);
}
static void iblock_bio_done(struct bio *bio, int err)
{
struct se_cmd *cmd = bio->bi_private;
struct iblock_req *ibr = cmd->priv;
if (!test_bit(BIO_UPTODATE, &bio->bi_flags) && !err)
err = -EIO;
if (err != 0) {
pr_err("test_bit(BIO_UPTODATE) failed for bio: %p,"
" err: %d\n", bio, err);
atomic_inc(&ibr->ib_bio_err_cnt);
smp_mb__after_atomic_inc();
}
bio_put(bio);
iblock_complete_cmd(cmd);
}
static struct bio *
iblock_get_bio(struct se_cmd *cmd, sector_t lba, u32 sg_num)
{
struct iblock_dev *ib_dev = IBLOCK_DEV(cmd->se_dev);
struct bio *bio;
if (sg_num > BIO_MAX_PAGES)
sg_num = BIO_MAX_PAGES;
bio = bio_alloc_bioset(GFP_NOIO, sg_num, ib_dev->ibd_bio_set);
if (!bio) {
pr_err("Unable to allocate memory for bio\n");
return NULL;
}
bio->bi_bdev = ib_dev->ibd_bd;
bio->bi_private = cmd;
bio->bi_end_io = &iblock_bio_done;
bio->bi_sector = lba;
return bio;
}
static void iblock_submit_bios(struct bio_list *list, int rw)
{
struct blk_plug plug;
struct bio *bio;
blk_start_plug(&plug);
while ((bio = bio_list_pop(list)))
submit_bio(rw, bio);
blk_finish_plug(&plug);
}
static void iblock_end_io_flush(struct bio *bio, int err)
{
struct se_cmd *cmd = bio->bi_private;
if (err)
pr_err("IBLOCK: cache flush failed: %d\n", err);
if (cmd) {
if (err)
target_complete_cmd(cmd, SAM_STAT_CHECK_CONDITION);
else
target_complete_cmd(cmd, SAM_STAT_GOOD);
}
bio_put(bio);
}
static sense_reason_t
iblock_execute_sync_cache(struct se_cmd *cmd)
{
struct iblock_dev *ib_dev = IBLOCK_DEV(cmd->se_dev);
int immed = (cmd->t_task_cdb[1] & 0x2);
struct bio *bio;
if (immed)
target_complete_cmd(cmd, SAM_STAT_GOOD);
bio = bio_alloc(GFP_KERNEL, 0);
bio->bi_end_io = iblock_end_io_flush;
bio->bi_bdev = ib_dev->ibd_bd;
if (!immed)
bio->bi_private = cmd;
submit_bio(WRITE_FLUSH, bio);
return 0;
}
static sense_reason_t
iblock_execute_unmap(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct iblock_dev *ib_dev = IBLOCK_DEV(dev);
unsigned char *buf, *ptr = NULL;
sector_t lba;
int size;
u32 range;
sense_reason_t ret = 0;
int dl, bd_dl, err;
if (cmd->data_length < 8) {
pr_warn("UNMAP parameter list length %u too small\n",
cmd->data_length);
return TCM_INVALID_PARAMETER_LIST;
}
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
dl = get_unaligned_be16(&buf[0]);
bd_dl = get_unaligned_be16(&buf[2]);
size = cmd->data_length - 8;
if (bd_dl > size)
pr_warn("UNMAP parameter list length %u too small, ignoring bd_dl %u\n",
cmd->data_length, bd_dl);
else
size = bd_dl;
if (size / 16 > dev->dev_attrib.max_unmap_block_desc_count) {
ret = TCM_INVALID_PARAMETER_LIST;
goto err;
}
ptr = &buf[8];
pr_debug("UNMAP: Sub: %s Using dl: %u bd_dl: %u size: %u"
" ptr: %p\n", dev->transport->name, dl, bd_dl, size, ptr);
while (size >= 16) {
lba = get_unaligned_be64(&ptr[0]);
range = get_unaligned_be32(&ptr[8]);
pr_debug("UNMAP: Using lba: %llu and range: %u\n",
(unsigned long long)lba, range);
if (range > dev->dev_attrib.max_unmap_lba_count) {
ret = TCM_INVALID_PARAMETER_LIST;
goto err;
}
if (lba + range > dev->transport->get_blocks(dev) + 1) {
ret = TCM_ADDRESS_OUT_OF_RANGE;
goto err;
}
err = blkdev_issue_discard(ib_dev->ibd_bd, lba, range,
GFP_KERNEL, 0);
if (err < 0) {
pr_err("blkdev_issue_discard() failed: %d\n",
err);
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto err;
}
ptr += 16;
size -= 16;
}
err:
transport_kunmap_data_sg(cmd);
if (!ret)
target_complete_cmd(cmd, GOOD);
return ret;
}
static sense_reason_t
iblock_execute_write_same_unmap(struct se_cmd *cmd)
{
struct iblock_dev *ib_dev = IBLOCK_DEV(cmd->se_dev);
int rc;
rc = blkdev_issue_discard(ib_dev->ibd_bd, cmd->t_task_lba,
spc_get_write_same_sectors(cmd), GFP_KERNEL, 0);
if (rc < 0) {
pr_warn("blkdev_issue_discard() failed: %d\n", rc);
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
target_complete_cmd(cmd, GOOD);
return 0;
}
static sense_reason_t
iblock_execute_write_same(struct se_cmd *cmd)
{
struct iblock_req *ibr;
struct scatterlist *sg;
struct bio *bio;
struct bio_list list;
sector_t block_lba = cmd->t_task_lba;
sector_t sectors = spc_get_write_same_sectors(cmd);
sg = &cmd->t_data_sg[0];
if (cmd->t_data_nents > 1 ||
sg->length != cmd->se_dev->dev_attrib.block_size) {
pr_err("WRITE_SAME: Illegal SGL t_data_nents: %u length: %u"
" block_size: %u\n", cmd->t_data_nents, sg->length,
cmd->se_dev->dev_attrib.block_size);
return TCM_INVALID_CDB_FIELD;
}
ibr = kzalloc(sizeof(struct iblock_req), GFP_KERNEL);
if (!ibr)
goto fail;
cmd->priv = ibr;
bio = iblock_get_bio(cmd, block_lba, 1);
if (!bio)
goto fail_free_ibr;
bio_list_init(&list);
bio_list_add(&list, bio);
atomic_set(&ibr->pending, 1);
while (sectors) {
while (bio_add_page(bio, sg_page(sg), sg->length, sg->offset)
!= sg->length) {
bio = iblock_get_bio(cmd, block_lba, 1);
if (!bio)
goto fail_put_bios;
atomic_inc(&ibr->pending);
bio_list_add(&list, bio);
}
block_lba += sg->length >> IBLOCK_LBA_SHIFT;
sectors -= 1;
}
iblock_submit_bios(&list, WRITE);
return 0;
fail_put_bios:
while ((bio = bio_list_pop(&list)))
bio_put(bio);
fail_free_ibr:
kfree(ibr);
fail:
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
static ssize_t iblock_set_configfs_dev_params(struct se_device *dev,
const char *page, ssize_t count)
{
struct iblock_dev *ib_dev = IBLOCK_DEV(dev);
char *orig, *ptr, *arg_p, *opts;
substring_t args[MAX_OPT_ARGS];
int ret = 0, token;
unsigned long tmp_readonly;
opts = kstrdup(page, GFP_KERNEL);
if (!opts)
return -ENOMEM;
orig = opts;
while ((ptr = strsep(&opts, ",\n")) != NULL) {
if (!*ptr)
continue;
token = match_token(ptr, tokens, args);
switch (token) {
case Opt_udev_path:
if (ib_dev->ibd_bd) {
pr_err("Unable to set udev_path= while"
" ib_dev->ibd_bd exists\n");
ret = -EEXIST;
goto out;
}
if (match_strlcpy(ib_dev->ibd_udev_path, &args[0],
SE_UDEV_PATH_LEN) == 0) {
ret = -EINVAL;
break;
}
pr_debug("IBLOCK: Referencing UDEV path: %s\n",
ib_dev->ibd_udev_path);
ib_dev->ibd_flags |= IBDF_HAS_UDEV_PATH;
break;
case Opt_readonly:
arg_p = match_strdup(&args[0]);
if (!arg_p) {
ret = -ENOMEM;
break;
}
ret = strict_strtoul(arg_p, 0, &tmp_readonly);
kfree(arg_p);
if (ret < 0) {
pr_err("strict_strtoul() failed for"
" readonly=\n");
goto out;
}
ib_dev->ibd_readonly = tmp_readonly;
pr_debug("IBLOCK: readonly: %d\n", ib_dev->ibd_readonly);
break;
case Opt_force:
break;
default:
break;
}
}
out:
kfree(orig);
return (!ret) ? count : ret;
}
static ssize_t iblock_show_configfs_dev_params(struct se_device *dev, char *b)
{
struct iblock_dev *ib_dev = IBLOCK_DEV(dev);
struct block_device *bd = ib_dev->ibd_bd;
char buf[BDEVNAME_SIZE];
ssize_t bl = 0;
if (bd)
bl += sprintf(b + bl, "iBlock device: %s",
bdevname(bd, buf));
if (ib_dev->ibd_flags & IBDF_HAS_UDEV_PATH)
bl += sprintf(b + bl, " UDEV PATH: %s",
ib_dev->ibd_udev_path);
bl += sprintf(b + bl, " readonly: %d\n", ib_dev->ibd_readonly);
bl += sprintf(b + bl, " ");
if (bd) {
bl += sprintf(b + bl, "Major: %d Minor: %d %s\n",
MAJOR(bd->bd_dev), MINOR(bd->bd_dev), (!bd->bd_contains) ?
"" : (bd->bd_holder == ib_dev) ?
"CLAIMED: IBLOCK" : "CLAIMED: OS");
} else {
bl += sprintf(b + bl, "Major: 0 Minor: 0\n");
}
return bl;
}
static sense_reason_t
iblock_execute_rw(struct se_cmd *cmd)
{
struct scatterlist *sgl = cmd->t_data_sg;
u32 sgl_nents = cmd->t_data_nents;
enum dma_data_direction data_direction = cmd->data_direction;
struct se_device *dev = cmd->se_dev;
struct iblock_req *ibr;
struct bio *bio;
struct bio_list list;
struct scatterlist *sg;
u32 sg_num = sgl_nents;
sector_t block_lba;
unsigned bio_cnt;
int rw;
int i;
if (data_direction == DMA_TO_DEVICE) {
if (dev->dev_attrib.emulate_write_cache == 0 ||
(dev->dev_attrib.emulate_fua_write > 0 &&
(cmd->se_cmd_flags & SCF_FUA)))
rw = WRITE_FUA;
else
rw = WRITE;
} else {
rw = READ;
}
if (dev->dev_attrib.block_size == 4096)
block_lba = (cmd->t_task_lba << 3);
else if (dev->dev_attrib.block_size == 2048)
block_lba = (cmd->t_task_lba << 2);
else if (dev->dev_attrib.block_size == 1024)
block_lba = (cmd->t_task_lba << 1);
else if (dev->dev_attrib.block_size == 512)
block_lba = cmd->t_task_lba;
else {
pr_err("Unsupported SCSI -> BLOCK LBA conversion:"
" %u\n", dev->dev_attrib.block_size);
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
ibr = kzalloc(sizeof(struct iblock_req), GFP_KERNEL);
if (!ibr)
goto fail;
cmd->priv = ibr;
if (!sgl_nents) {
atomic_set(&ibr->pending, 1);
iblock_complete_cmd(cmd);
return 0;
}
bio = iblock_get_bio(cmd, block_lba, sgl_nents);
if (!bio)
goto fail_free_ibr;
bio_list_init(&list);
bio_list_add(&list, bio);
atomic_set(&ibr->pending, 2);
bio_cnt = 1;
for_each_sg(sgl, sg, sgl_nents, i) {
while (bio_add_page(bio, sg_page(sg), sg->length, sg->offset)
!= sg->length) {
if (bio_cnt >= IBLOCK_MAX_BIO_PER_TASK) {
iblock_submit_bios(&list, rw);
bio_cnt = 0;
}
bio = iblock_get_bio(cmd, block_lba, sg_num);
if (!bio)
goto fail_put_bios;
atomic_inc(&ibr->pending);
bio_list_add(&list, bio);
bio_cnt++;
}
block_lba += sg->length >> IBLOCK_LBA_SHIFT;
sg_num--;
}
iblock_submit_bios(&list, rw);
iblock_complete_cmd(cmd);
return 0;
fail_put_bios:
while ((bio = bio_list_pop(&list)))
bio_put(bio);
fail_free_ibr:
kfree(ibr);
fail:
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
static sector_t iblock_get_blocks(struct se_device *dev)
{
struct iblock_dev *ib_dev = IBLOCK_DEV(dev);
struct block_device *bd = ib_dev->ibd_bd;
struct request_queue *q = bdev_get_queue(bd);
return iblock_emulate_read_cap_with_block_size(dev, bd, q);
}
static sense_reason_t
iblock_parse_cdb(struct se_cmd *cmd)
{
return sbc_parse_cdb(cmd, &iblock_sbc_ops);
}
static int __init iblock_module_init(void)
{
return transport_subsystem_register(&iblock_template);
}
static void iblock_module_exit(void)
{
transport_subsystem_release(&iblock_template);
}
