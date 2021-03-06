static int iblock_attach_hba(struct se_hba *hba, u32 host_id)
{
struct iblock_hba *ib_host;
ib_host = kzalloc(sizeof(struct iblock_hba), GFP_KERNEL);
if (!ib_host) {
pr_err("Unable to allocate memory for"
" struct iblock_hba\n");
return -ENOMEM;
}
ib_host->iblock_host_id = host_id;
hba->hba_ptr = ib_host;
pr_debug("CORE_HBA[%d] - TCM iBlock HBA Driver %s on"
" Generic Target Core Stack %s\n", hba->hba_id,
IBLOCK_VERSION, TARGET_CORE_MOD_VERSION);
pr_debug("CORE_HBA[%d] - Attached iBlock HBA: %u to Generic\n",
hba->hba_id, ib_host->iblock_host_id);
return 0;
}
static void iblock_detach_hba(struct se_hba *hba)
{
struct iblock_hba *ib_host = hba->hba_ptr;
pr_debug("CORE_HBA[%d] - Detached iBlock HBA: %u from Generic"
" Target Core\n", hba->hba_id, ib_host->iblock_host_id);
kfree(ib_host);
hba->hba_ptr = NULL;
}
static void *iblock_allocate_virtdevice(struct se_hba *hba, const char *name)
{
struct iblock_dev *ib_dev = NULL;
struct iblock_hba *ib_host = hba->hba_ptr;
ib_dev = kzalloc(sizeof(struct iblock_dev), GFP_KERNEL);
if (!ib_dev) {
pr_err("Unable to allocate struct iblock_dev\n");
return NULL;
}
ib_dev->ibd_host = ib_host;
pr_debug( "IBLOCK: Allocated ib_dev for %s\n", name);
return ib_dev;
}
static struct se_device *iblock_create_virtdevice(
struct se_hba *hba,
struct se_subsystem_dev *se_dev,
void *p)
{
struct iblock_dev *ib_dev = p;
struct se_device *dev;
struct se_dev_limits dev_limits;
struct block_device *bd = NULL;
struct request_queue *q;
struct queue_limits *limits;
u32 dev_flags = 0;
int ret = -EINVAL;
if (!ib_dev) {
pr_err("Unable to locate struct iblock_dev parameter\n");
return ERR_PTR(ret);
}
memset(&dev_limits, 0, sizeof(struct se_dev_limits));
ib_dev->ibd_bio_set = bioset_create(32, 64);
if (!ib_dev->ibd_bio_set) {
pr_err("IBLOCK: Unable to create bioset()\n");
return ERR_PTR(-ENOMEM);
}
pr_debug("IBLOCK: Created bio_set()\n");
pr_debug( "IBLOCK: Claiming struct block_device: %s\n",
ib_dev->ibd_udev_path);
bd = blkdev_get_by_path(ib_dev->ibd_udev_path,
FMODE_WRITE|FMODE_READ|FMODE_EXCL, ib_dev);
if (IS_ERR(bd)) {
ret = PTR_ERR(bd);
goto failed;
}
q = bdev_get_queue(bd);
limits = &dev_limits.limits;
limits->logical_block_size = bdev_logical_block_size(bd);
limits->max_hw_sectors = queue_max_hw_sectors(q);
limits->max_sectors = queue_max_sectors(q);
dev_limits.hw_queue_depth = q->nr_requests;
dev_limits.queue_depth = q->nr_requests;
ib_dev->ibd_bd = bd;
dev = transport_add_device_to_core_hba(hba,
&iblock_template, se_dev, dev_flags, ib_dev,
&dev_limits, "IBLOCK", IBLOCK_VERSION);
if (!dev)
goto failed;
if (blk_queue_discard(q)) {
dev->se_sub_dev->se_dev_attrib.max_unmap_lba_count =
q->limits.max_discard_sectors;
dev->se_sub_dev->se_dev_attrib.max_unmap_block_desc_count = 1;
dev->se_sub_dev->se_dev_attrib.unmap_granularity =
q->limits.discard_granularity;
dev->se_sub_dev->se_dev_attrib.unmap_granularity_alignment =
q->limits.discard_alignment;
pr_debug("IBLOCK: BLOCK Discard support available,"
" disabled by default\n");
}
if (blk_queue_nonrot(q))
dev->se_sub_dev->se_dev_attrib.is_nonrot = 1;
return dev;
failed:
if (ib_dev->ibd_bio_set) {
bioset_free(ib_dev->ibd_bio_set);
ib_dev->ibd_bio_set = NULL;
}
ib_dev->ibd_bd = NULL;
return ERR_PTR(ret);
}
static void iblock_free_device(void *p)
{
struct iblock_dev *ib_dev = p;
if (ib_dev->ibd_bd != NULL)
blkdev_put(ib_dev->ibd_bd, FMODE_WRITE|FMODE_READ|FMODE_EXCL);
if (ib_dev->ibd_bio_set != NULL)
bioset_free(ib_dev->ibd_bio_set);
kfree(ib_dev);
}
static inline struct iblock_req *IBLOCK_REQ(struct se_task *task)
{
return container_of(task, struct iblock_req, ib_task);
}
static struct se_task *
iblock_alloc_task(unsigned char *cdb)
{
struct iblock_req *ib_req;
ib_req = kzalloc(sizeof(struct iblock_req), GFP_KERNEL);
if (!ib_req) {
pr_err("Unable to allocate memory for struct iblock_req\n");
return NULL;
}
atomic_set(&ib_req->ib_bio_cnt, 0);
return &ib_req->ib_task;
}
static unsigned long long iblock_emulate_read_cap_with_block_size(
struct se_device *dev,
struct block_device *bd,
struct request_queue *q)
{
unsigned long long blocks_long = (div_u64(i_size_read(bd->bd_inode),
bdev_logical_block_size(bd)) - 1);
u32 block_size = bdev_logical_block_size(bd);
if (block_size == dev->se_sub_dev->se_dev_attrib.block_size)
return blocks_long;
switch (block_size) {
case 4096:
switch (dev->se_sub_dev->se_dev_attrib.block_size) {
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
switch (dev->se_sub_dev->se_dev_attrib.block_size) {
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
switch (dev->se_sub_dev->se_dev_attrib.block_size) {
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
switch (dev->se_sub_dev->se_dev_attrib.block_size) {
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
static void iblock_emulate_sync_cache(struct se_task *task)
{
struct se_cmd *cmd = task->task_se_cmd;
struct iblock_dev *ib_dev = cmd->se_dev->dev_ptr;
int immed = (cmd->t_task_cdb[1] & 0x2);
sector_t error_sector;
int ret;
if (immed)
transport_complete_sync_cache(cmd, 1);
ret = blkdev_issue_flush(ib_dev->ibd_bd, GFP_KERNEL, &error_sector);
if (ret != 0) {
pr_err("IBLOCK: block_issue_flush() failed: %d "
" error_sector: %llu\n", ret,
(unsigned long long)error_sector);
}
if (!immed)
transport_complete_sync_cache(cmd, ret == 0);
}
static int iblock_emulated_write_cache(struct se_device *dev)
{
return 1;
}
static int iblock_emulated_dpo(struct se_device *dev)
{
return 0;
}
static int iblock_emulated_fua_write(struct se_device *dev)
{
return 1;
}
static int iblock_emulated_fua_read(struct se_device *dev)
{
return 0;
}
static int iblock_do_task(struct se_task *task)
{
struct se_device *dev = task->task_se_cmd->se_dev;
struct iblock_req *req = IBLOCK_REQ(task);
struct bio *bio = req->ib_bio, *nbio = NULL;
struct blk_plug plug;
int rw;
if (task->task_data_direction == DMA_TO_DEVICE) {
if (dev->se_sub_dev->se_dev_attrib.emulate_write_cache == 0 ||
(dev->se_sub_dev->se_dev_attrib.emulate_fua_write > 0 &&
task->task_se_cmd->t_tasks_fua))
rw = WRITE_FUA;
else
rw = WRITE;
} else {
rw = READ;
}
blk_start_plug(&plug);
while (bio) {
nbio = bio->bi_next;
bio->bi_next = NULL;
pr_debug("Calling submit_bio() task: %p bio: %p"
" bio->bi_sector: %llu\n", task, bio,
(unsigned long long)bio->bi_sector);
submit_bio(rw, bio);
bio = nbio;
}
blk_finish_plug(&plug);
return PYX_TRANSPORT_SENT_TO_TRANSPORT;
}
static int iblock_do_discard(struct se_device *dev, sector_t lba, u32 range)
{
struct iblock_dev *ibd = dev->dev_ptr;
struct block_device *bd = ibd->ibd_bd;
int barrier = 0;
return blkdev_issue_discard(bd, lba, range, GFP_KERNEL, barrier);
}
static void iblock_free_task(struct se_task *task)
{
struct iblock_req *req = IBLOCK_REQ(task);
struct bio *bio, *hbio = req->ib_bio;
while (hbio != NULL) {
bio = hbio;
hbio = hbio->bi_next;
bio->bi_next = NULL;
bio_put(bio);
}
kfree(req);
}
static ssize_t iblock_set_configfs_dev_params(struct se_hba *hba,
struct se_subsystem_dev *se_dev,
const char *page, ssize_t count)
{
struct iblock_dev *ib_dev = se_dev->se_dev_su_ptr;
char *orig, *ptr, *arg_p, *opts;
substring_t args[MAX_OPT_ARGS];
int ret = 0, token;
opts = kstrdup(page, GFP_KERNEL);
if (!opts)
return -ENOMEM;
orig = opts;
while ((ptr = strsep(&opts, ",")) != NULL) {
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
arg_p = match_strdup(&args[0]);
if (!arg_p) {
ret = -ENOMEM;
break;
}
snprintf(ib_dev->ibd_udev_path, SE_UDEV_PATH_LEN,
"%s", arg_p);
kfree(arg_p);
pr_debug("IBLOCK: Referencing UDEV path: %s\n",
ib_dev->ibd_udev_path);
ib_dev->ibd_flags |= IBDF_HAS_UDEV_PATH;
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
static ssize_t iblock_check_configfs_dev_params(
struct se_hba *hba,
struct se_subsystem_dev *se_dev)
{
struct iblock_dev *ibd = se_dev->se_dev_su_ptr;
if (!(ibd->ibd_flags & IBDF_HAS_UDEV_PATH)) {
pr_err("Missing udev_path= parameters for IBLOCK\n");
return -EINVAL;
}
return 0;
}
static ssize_t iblock_show_configfs_dev_params(
struct se_hba *hba,
struct se_subsystem_dev *se_dev,
char *b)
{
struct iblock_dev *ibd = se_dev->se_dev_su_ptr;
struct block_device *bd = ibd->ibd_bd;
char buf[BDEVNAME_SIZE];
ssize_t bl = 0;
if (bd)
bl += sprintf(b + bl, "iBlock device: %s",
bdevname(bd, buf));
if (ibd->ibd_flags & IBDF_HAS_UDEV_PATH) {
bl += sprintf(b + bl, " UDEV PATH: %s\n",
ibd->ibd_udev_path);
} else
bl += sprintf(b + bl, "\n");
bl += sprintf(b + bl, " ");
if (bd) {
bl += sprintf(b + bl, "Major: %d Minor: %d %s\n",
MAJOR(bd->bd_dev), MINOR(bd->bd_dev), (!bd->bd_contains) ?
"" : (bd->bd_holder == (struct iblock_dev *)ibd) ?
"CLAIMED: IBLOCK" : "CLAIMED: OS");
} else {
bl += sprintf(b + bl, "Major: 0 Minor: 0\n");
}
return bl;
}
static void iblock_bio_destructor(struct bio *bio)
{
struct se_task *task = bio->bi_private;
struct iblock_dev *ib_dev = task->se_dev->dev_ptr;
bio_free(bio, ib_dev->ibd_bio_set);
}
static struct bio *iblock_get_bio(
struct se_task *task,
struct iblock_req *ib_req,
struct iblock_dev *ib_dev,
int *ret,
sector_t lba,
u32 sg_num)
{
struct bio *bio;
bio = bio_alloc_bioset(GFP_NOIO, sg_num, ib_dev->ibd_bio_set);
if (!bio) {
pr_err("Unable to allocate memory for bio\n");
*ret = PYX_TRANSPORT_OUT_OF_MEMORY_RESOURCES;
return NULL;
}
pr_debug("Allocated bio: %p task_sg_nents: %u using ibd_bio_set:"
" %p\n", bio, task->task_sg_nents, ib_dev->ibd_bio_set);
pr_debug("Allocated bio: %p task_size: %u\n", bio, task->task_size);
bio->bi_bdev = ib_dev->ibd_bd;
bio->bi_private = task;
bio->bi_destructor = iblock_bio_destructor;
bio->bi_end_io = &iblock_bio_done;
bio->bi_sector = lba;
atomic_inc(&ib_req->ib_bio_cnt);
pr_debug("Set bio->bi_sector: %llu\n", (unsigned long long)bio->bi_sector);
pr_debug("Set ib_req->ib_bio_cnt: %d\n",
atomic_read(&ib_req->ib_bio_cnt));
return bio;
}
static int iblock_map_data_SG(struct se_task *task)
{
struct se_cmd *cmd = task->task_se_cmd;
struct se_device *dev = cmd->se_dev;
struct iblock_dev *ib_dev = task->se_dev->dev_ptr;
struct iblock_req *ib_req = IBLOCK_REQ(task);
struct bio *bio = NULL, *hbio = NULL, *tbio = NULL;
struct scatterlist *sg;
int ret = 0;
u32 i, sg_num = task->task_sg_nents;
sector_t block_lba;
if (dev->se_sub_dev->se_dev_attrib.block_size == 4096)
block_lba = (task->task_lba << 3);
else if (dev->se_sub_dev->se_dev_attrib.block_size == 2048)
block_lba = (task->task_lba << 2);
else if (dev->se_sub_dev->se_dev_attrib.block_size == 1024)
block_lba = (task->task_lba << 1);
else if (dev->se_sub_dev->se_dev_attrib.block_size == 512)
block_lba = task->task_lba;
else {
pr_err("Unsupported SCSI -> BLOCK LBA conversion:"
" %u\n", dev->se_sub_dev->se_dev_attrib.block_size);
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
bio = iblock_get_bio(task, ib_req, ib_dev, &ret, block_lba, sg_num);
if (!bio)
return ret;
ib_req->ib_bio = bio;
hbio = tbio = bio;
for_each_sg(task->task_sg, sg, task->task_sg_nents, i) {
pr_debug("task: %p bio: %p Calling bio_add_page(): page:"
" %p len: %u offset: %u\n", task, bio, sg_page(sg),
sg->length, sg->offset);
again:
ret = bio_add_page(bio, sg_page(sg), sg->length, sg->offset);
if (ret != sg->length) {
pr_debug("*** Set bio->bi_sector: %llu\n",
(unsigned long long)bio->bi_sector);
pr_debug("** task->task_size: %u\n",
task->task_size);
pr_debug("*** bio->bi_max_vecs: %u\n",
bio->bi_max_vecs);
pr_debug("*** bio->bi_vcnt: %u\n",
bio->bi_vcnt);
bio = iblock_get_bio(task, ib_req, ib_dev, &ret,
block_lba, sg_num);
if (!bio)
goto fail;
tbio = tbio->bi_next = bio;
pr_debug("-----------------> Added +1 bio: %p to"
" list, Going to again\n", bio);
goto again;
}
block_lba += sg->length >> IBLOCK_LBA_SHIFT;
sg_num--;
pr_debug("task: %p bio-add_page() passed!, decremented"
" sg_num to %u\n", task, sg_num);
pr_debug("task: %p bio_add_page() passed!, increased lba"
" to %llu\n", task, (unsigned long long)block_lba);
pr_debug("task: %p bio_add_page() passed!, bio->bi_vcnt:"
" %u\n", task, bio->bi_vcnt);
}
return 0;
fail:
while (hbio) {
bio = hbio;
hbio = hbio->bi_next;
bio->bi_next = NULL;
bio_put(bio);
}
return ret;
}
static unsigned char *iblock_get_cdb(struct se_task *task)
{
return IBLOCK_REQ(task)->ib_scsi_cdb;
}
static u32 iblock_get_device_rev(struct se_device *dev)
{
return SCSI_SPC_2;
}
static u32 iblock_get_device_type(struct se_device *dev)
{
return TYPE_DISK;
}
static sector_t iblock_get_blocks(struct se_device *dev)
{
struct iblock_dev *ibd = dev->dev_ptr;
struct block_device *bd = ibd->ibd_bd;
struct request_queue *q = bdev_get_queue(bd);
return iblock_emulate_read_cap_with_block_size(dev, bd, q);
}
static void iblock_bio_done(struct bio *bio, int err)
{
struct se_task *task = bio->bi_private;
struct iblock_req *ibr = IBLOCK_REQ(task);
if (!test_bit(BIO_UPTODATE, &bio->bi_flags) && !err)
err = -EIO;
if (err != 0) {
pr_err("test_bit(BIO_UPTODATE) failed for bio: %p,"
" err: %d\n", bio, err);
atomic_inc(&ibr->ib_bio_err_cnt);
smp_mb__after_atomic_inc();
bio_put(bio);
if (!atomic_dec_and_test(&ibr->ib_bio_cnt))
return;
ibr->ib_bio = NULL;
transport_complete_task(task, 0);
return;
}
pr_debug("done[%p] bio: %p task_lba: %llu bio_lba: %llu err=%d\n",
task, bio, task->task_lba, (unsigned long long)bio->bi_sector, err);
bio_put(bio);
if (!atomic_dec_and_test(&ibr->ib_bio_cnt))
return;
ibr->ib_bio = NULL;
transport_complete_task(task, (!atomic_read(&ibr->ib_bio_err_cnt)));
}
static int __init iblock_module_init(void)
{
return transport_subsystem_register(&iblock_template);
}
static void iblock_module_exit(void)
{
transport_subsystem_release(&iblock_template);
}
