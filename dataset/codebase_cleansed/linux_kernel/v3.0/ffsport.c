int GLOB_Calc_Used_Bits(u32 n)
{
int tot_bits = 0;
if (n >= 1 << 16) {
n >>= 16;
tot_bits += 16;
}
if (n >= 1 << 8) {
n >>= 8;
tot_bits += 8;
}
if (n >= 1 << 4) {
n >>= 4;
tot_bits += 4;
}
if (n >= 1 << 2) {
n >>= 2;
tot_bits += 2;
}
if (n >= 1 << 1)
tot_bits += 1;
return ((n == 0) ? (0) : tot_bits);
}
u64 GLOB_u64_Div(u64 addr, u32 divisor)
{
return (u64)(addr >> GLOB_Calc_Used_Bits(divisor));
}
u64 GLOB_u64_Remainder(u64 addr, u32 divisor_type)
{
u64 result = 0;
if (divisor_type == 1) {
result = (addr >> DeviceInfo.nBitsInPageDataSize);
result = result * DeviceInfo.wPageDataSize;
} else if (divisor_type == 2) {
result = (addr >> DeviceInfo.nBitsInBlockDataSize);
result = result * DeviceInfo.wBlockDataSize;
}
result = addr - result;
return result;
}
static int force_flush_cache(void)
{
nand_dbg_print(NAND_DBG_DEBUG, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (ERR == GLOB_FTL_Flush_Cache()) {
printk(KERN_ERR "Fail to Flush FTL Cache!\n");
return -EFAULT;
}
#if CMD_DMA
if (glob_ftl_execute_cmds())
return -EIO;
else
return 0;
#endif
return 0;
}
static int ioctl_read_page_data(unsigned long arg)
{
u8 *buf;
struct ioctl_rw_page_info info;
int result = PASS;
if (copy_from_user(&info, (void __user *)arg, sizeof(info)))
return -EFAULT;
buf = kmalloc(IdentifyDeviceData.PageDataSize, GFP_ATOMIC);
if (!buf) {
printk(KERN_ERR "ioctl_read_page_data: "
"failed to allocate memory\n");
return -ENOMEM;
}
mutex_lock(&spectra_lock);
result = GLOB_FTL_Page_Read(buf,
(u64)info.page * IdentifyDeviceData.PageDataSize);
mutex_unlock(&spectra_lock);
if (copy_to_user((void __user *)info.data, buf,
IdentifyDeviceData.PageDataSize)) {
printk(KERN_ERR "ioctl_read_page_data: "
"failed to copy user data\n");
kfree(buf);
return -EFAULT;
}
kfree(buf);
return result;
}
static int ioctl_write_page_data(unsigned long arg)
{
u8 *buf;
struct ioctl_rw_page_info info;
int result = PASS;
if (copy_from_user(&info, (void __user *)arg, sizeof(info)))
return -EFAULT;
buf = kmalloc(IdentifyDeviceData.PageDataSize, GFP_ATOMIC);
if (!buf) {
printk(KERN_ERR "ioctl_write_page_data: "
"failed to allocate memory\n");
return -ENOMEM;
}
if (copy_from_user(buf, (void __user *)info.data,
IdentifyDeviceData.PageDataSize)) {
printk(KERN_ERR "ioctl_write_page_data: "
"failed to copy user data\n");
kfree(buf);
return -EFAULT;
}
mutex_lock(&spectra_lock);
result = GLOB_FTL_Page_Write(buf,
(u64)info.page * IdentifyDeviceData.PageDataSize);
mutex_unlock(&spectra_lock);
kfree(buf);
return result;
}
static int get_res_blk_num_bad_blk(void)
{
return IdentifyDeviceData.wDataBlockNum / 10;
}
static int get_res_blk_num_os(void)
{
u32 res_blks, blk_size;
blk_size = IdentifyDeviceData.PageDataSize *
IdentifyDeviceData.PagesPerBlock;
res_blks = (reserved_mb * 1024 * 1024) / blk_size;
if ((res_blks < 1) || (res_blks >= IdentifyDeviceData.wDataBlockNum))
res_blks = 1;
return res_blks;
}
static int do_transfer(struct spectra_nand_dev *tr, struct request *req)
{
u64 start_addr, addr;
u32 logical_start_sect, hd_start_sect;
u32 nsect, hd_sects;
u32 rsect, tsect = 0;
char *buf;
u32 ratio = IdentifyDeviceData.PageDataSize >> 9;
start_addr = (u64)(blk_rq_pos(req)) << 9;
start_addr += IdentifyDeviceData.PageDataSize *
IdentifyDeviceData.PagesPerBlock *
res_blks_os;
if (req->cmd_type & REQ_FLUSH) {
if (force_flush_cache())
return -EIO;
else
return 0;
}
if (req->cmd_type != REQ_TYPE_FS)
return -EIO;
if (blk_rq_pos(req) + blk_rq_cur_sectors(req) > get_capacity(tr->gd)) {
printk(KERN_ERR "Spectra error: request over the NAND "
"capacity!sector %d, current_nr_sectors %d, "
"while capacity is %d\n",
(int)blk_rq_pos(req),
blk_rq_cur_sectors(req),
(int)get_capacity(tr->gd));
return -EIO;
}
logical_start_sect = start_addr >> 9;
hd_start_sect = logical_start_sect / ratio;
rsect = logical_start_sect - hd_start_sect * ratio;
addr = (u64)hd_start_sect * ratio * 512;
buf = req->buffer;
nsect = blk_rq_cur_sectors(req);
if (rsect)
tsect = (ratio - rsect) < nsect ? (ratio - rsect) : nsect;
switch (rq_data_dir(req)) {
case READ:
if (rsect) {
if (GLOB_FTL_Page_Read(tr->tmp_buf, addr)) {
printk(KERN_ERR "Error in %s, Line %d\n",
__FILE__, __LINE__);
return -EIO;
}
memcpy(buf, tr->tmp_buf + (rsect << 9), tsect << 9);
addr += IdentifyDeviceData.PageDataSize;
buf += tsect << 9;
nsect -= tsect;
}
for (hd_sects = nsect / ratio; hd_sects > 0; hd_sects--) {
if (GLOB_FTL_Page_Read(buf, addr)) {
printk(KERN_ERR "Error in %s, Line %d\n",
__FILE__, __LINE__);
return -EIO;
}
addr += IdentifyDeviceData.PageDataSize;
buf += IdentifyDeviceData.PageDataSize;
}
if (nsect % ratio) {
if (GLOB_FTL_Page_Read(tr->tmp_buf, addr)) {
printk(KERN_ERR "Error in %s, Line %d\n",
__FILE__, __LINE__);
return -EIO;
}
memcpy(buf, tr->tmp_buf, (nsect % ratio) << 9);
}
#if CMD_DMA
if (glob_ftl_execute_cmds())
return -EIO;
else
return 0;
#endif
return 0;
case WRITE:
if (rsect) {
if (GLOB_FTL_Page_Read(tr->tmp_buf, addr)) {
printk(KERN_ERR "Error in %s, Line %d\n",
__FILE__, __LINE__);
return -EIO;
}
memcpy(tr->tmp_buf + (rsect << 9), buf, tsect << 9);
if (GLOB_FTL_Page_Write(tr->tmp_buf, addr)) {
printk(KERN_ERR "Error in %s, Line %d\n",
__FILE__, __LINE__);
return -EIO;
}
addr += IdentifyDeviceData.PageDataSize;
buf += tsect << 9;
nsect -= tsect;
}
for (hd_sects = nsect / ratio; hd_sects > 0; hd_sects--) {
if (GLOB_FTL_Page_Write(buf, addr)) {
printk(KERN_ERR "Error in %s, Line %d\n",
__FILE__, __LINE__);
return -EIO;
}
addr += IdentifyDeviceData.PageDataSize;
buf += IdentifyDeviceData.PageDataSize;
}
if (nsect % ratio) {
if (GLOB_FTL_Page_Read(tr->tmp_buf, addr)) {
printk(KERN_ERR "Error in %s, Line %d\n",
__FILE__, __LINE__);
return -EIO;
}
memcpy(tr->tmp_buf, buf, (nsect % ratio) << 9);
if (GLOB_FTL_Page_Write(tr->tmp_buf, addr)) {
printk(KERN_ERR "Error in %s, Line %d\n",
__FILE__, __LINE__);
return -EIO;
}
}
#if CMD_DMA
if (glob_ftl_execute_cmds())
return -EIO;
else
return 0;
#endif
return 0;
default:
printk(KERN_NOTICE "Unknown request %u\n", rq_data_dir(req));
return -EIO;
}
}
static int spectra_trans_thread(void *arg)
{
struct spectra_nand_dev *tr = arg;
struct request_queue *rq = tr->queue;
struct request *req = NULL;
current->flags |= PF_MEMALLOC;
spin_lock_irq(rq->queue_lock);
while (!kthread_should_stop()) {
int res;
if (!req) {
req = blk_fetch_request(rq);
if (!req) {
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_irq(rq->queue_lock);
schedule();
spin_lock_irq(rq->queue_lock);
continue;
}
}
spin_unlock_irq(rq->queue_lock);
mutex_lock(&spectra_lock);
res = do_transfer(tr, req);
mutex_unlock(&spectra_lock);
spin_lock_irq(rq->queue_lock);
if (!__blk_end_request_cur(req, res))
req = NULL;
}
if (req)
__blk_end_request_all(req, -EIO);
spin_unlock_irq(rq->queue_lock);
return 0;
}
static void GLOB_SBD_request(struct request_queue *rq)
{
struct spectra_nand_dev *pdev = rq->queuedata;
wake_up_process(pdev->thread);
}
static int GLOB_SBD_open(struct block_device *bdev, fmode_t mode)
{
nand_dbg_print(NAND_DBG_WARN, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
return 0;
}
static int GLOB_SBD_release(struct gendisk *disk, fmode_t mode)
{
int ret;
nand_dbg_print(NAND_DBG_WARN, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
mutex_lock(&spectra_lock);
ret = force_flush_cache();
mutex_unlock(&spectra_lock);
return 0;
}
static int GLOB_SBD_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
geo->heads = 4;
geo->sectors = 16;
geo->cylinders = get_capacity(bdev->bd_disk) / (4 * 16);
nand_dbg_print(NAND_DBG_DEBUG,
"heads: %d, sectors: %d, cylinders: %d\n",
geo->heads, geo->sectors, geo->cylinders);
return 0;
}
int GLOB_SBD_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
int ret;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
switch (cmd) {
case GLOB_SBD_IOCTL_GC:
nand_dbg_print(NAND_DBG_DEBUG,
"Spectra IOCTL: Garbage Collection "
"being performed\n");
if (PASS != GLOB_FTL_Garbage_Collection())
return -EFAULT;
return 0;
case GLOB_SBD_IOCTL_WL:
nand_dbg_print(NAND_DBG_DEBUG,
"Spectra IOCTL: Static Wear Leveling "
"being performed\n");
if (PASS != GLOB_FTL_Wear_Leveling())
return -EFAULT;
return 0;
case GLOB_SBD_IOCTL_FORMAT:
nand_dbg_print(NAND_DBG_DEBUG, "Spectra IOCTL: Flash format "
"being performed\n");
if (PASS != GLOB_FTL_Flash_Format())
return -EFAULT;
return 0;
case GLOB_SBD_IOCTL_FLUSH_CACHE:
nand_dbg_print(NAND_DBG_DEBUG, "Spectra IOCTL: Cache flush "
"being performed\n");
mutex_lock(&spectra_lock);
ret = force_flush_cache();
mutex_unlock(&spectra_lock);
return ret;
case GLOB_SBD_IOCTL_COPY_BLK_TABLE:
nand_dbg_print(NAND_DBG_DEBUG, "Spectra IOCTL: "
"Copy block table\n");
if (copy_to_user((void __user *)arg,
get_blk_table_start_addr(),
get_blk_table_len()))
return -EFAULT;
return 0;
case GLOB_SBD_IOCTL_COPY_WEAR_LEVELING_TABLE:
nand_dbg_print(NAND_DBG_DEBUG, "Spectra IOCTL: "
"Copy wear leveling table\n");
if (copy_to_user((void __user *)arg,
get_wear_leveling_table_start_addr(),
get_wear_leveling_table_len()))
return -EFAULT;
return 0;
case GLOB_SBD_IOCTL_GET_NAND_INFO:
nand_dbg_print(NAND_DBG_DEBUG, "Spectra IOCTL: "
"Get NAND info\n");
if (copy_to_user((void __user *)arg, &IdentifyDeviceData,
sizeof(IdentifyDeviceData)))
return -EFAULT;
return 0;
case GLOB_SBD_IOCTL_WRITE_DATA:
nand_dbg_print(NAND_DBG_DEBUG, "Spectra IOCTL: "
"Write one page data\n");
return ioctl_write_page_data(arg);
case GLOB_SBD_IOCTL_READ_DATA:
nand_dbg_print(NAND_DBG_DEBUG, "Spectra IOCTL: "
"Read one page data\n");
return ioctl_read_page_data(arg);
}
return -ENOTTY;
}
int GLOB_SBD_unlocked_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
int ret;
mutex_lock(&ffsport_mutex);
ret = GLOB_SBD_ioctl(bdev, mode, cmd, arg);
mutex_unlock(&ffsport_mutex);
return ret;
}
static int SBD_setup_device(struct spectra_nand_dev *dev, int which)
{
int res_blks;
u32 sects;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
memset(dev, 0, sizeof(struct spectra_nand_dev));
nand_dbg_print(NAND_DBG_WARN, "Reserved %d blocks "
"for OS image, %d blocks for bad block replacement.\n",
get_res_blk_num_os(),
get_res_blk_num_bad_blk());
res_blks = get_res_blk_num_bad_blk() + get_res_blk_num_os();
dev->size = (u64)IdentifyDeviceData.PageDataSize *
IdentifyDeviceData.PagesPerBlock *
(IdentifyDeviceData.wDataBlockNum - res_blks);
res_blks_os = get_res_blk_num_os();
spin_lock_init(&dev->qlock);
dev->tmp_buf = kmalloc(IdentifyDeviceData.PageDataSize, GFP_ATOMIC);
if (!dev->tmp_buf) {
printk(KERN_ERR "Failed to kmalloc memory in %s Line %d, exit.\n",
__FILE__, __LINE__);
goto out_vfree;
}
dev->queue = blk_init_queue(GLOB_SBD_request, &dev->qlock);
if (dev->queue == NULL) {
printk(KERN_ERR
"Spectra: Request queue could not be initialized."
" Aborting\n ");
goto out_vfree;
}
dev->queue->queuedata = dev;
blk_queue_logical_block_size(dev->queue, 512);
blk_queue_flush(dev->queue, REQ_FLUSH);
dev->thread = kthread_run(spectra_trans_thread, dev, "nand_thd");
if (IS_ERR(dev->thread)) {
blk_cleanup_queue(dev->queue);
unregister_blkdev(GLOB_SBD_majornum, GLOB_SBD_NAME);
return PTR_ERR(dev->thread);
}
dev->gd = alloc_disk(PARTITIONS);
if (!dev->gd) {
printk(KERN_ERR
"Spectra: Could not allocate disk. Aborting \n ");
goto out_vfree;
}
dev->gd->major = GLOB_SBD_majornum;
dev->gd->first_minor = which * PARTITIONS;
dev->gd->fops = &GLOB_SBD_ops;
dev->gd->queue = dev->queue;
dev->gd->private_data = dev;
snprintf(dev->gd->disk_name, 32, "%s%c", GLOB_SBD_NAME, which + 'a');
sects = dev->size >> 9;
nand_dbg_print(NAND_DBG_WARN, "Capacity sects: %d\n", sects);
set_capacity(dev->gd, sects);
add_disk(dev->gd);
return 0;
out_vfree:
return -ENOMEM;
}
static void register_spectra_ftl_async(void *unused, async_cookie_t cookie)
{
int i;
if (PASS != GLOB_FTL_IdentifyDevice(&IdentifyDeviceData)) {
printk(KERN_ERR "Spectra: Unable to Read Flash Device. "
"Aborting\n");
return;
} else {
nand_dbg_print(NAND_DBG_WARN, "In GLOB_SBD_init: "
"Num blocks=%d, pagesperblock=%d, "
"pagedatasize=%d, ECCBytesPerSector=%d\n",
(int)IdentifyDeviceData.NumBlocks,
(int)IdentifyDeviceData.PagesPerBlock,
(int)IdentifyDeviceData.PageDataSize,
(int)IdentifyDeviceData.wECCBytesPerSector);
}
printk(KERN_ALERT "Spectra: searching block table, please wait ...\n");
if (GLOB_FTL_Init() != PASS) {
printk(KERN_ERR "Spectra: Unable to Initialize FTL Layer. "
"Aborting\n");
goto out_ftl_flash_register;
}
printk(KERN_ALERT "Spectra: block table has been found.\n");
GLOB_SBD_majornum = register_blkdev(0, GLOB_SBD_NAME);
if (GLOB_SBD_majornum <= 0) {
printk(KERN_ERR "Unable to get the major %d for Spectra",
GLOB_SBD_majornum);
goto out_ftl_flash_register;
}
for (i = 0; i < NUM_DEVICES; i++)
if (SBD_setup_device(&nand_device[i], i) == -ENOMEM)
goto out_blk_register;
nand_dbg_print(NAND_DBG_DEBUG,
"Spectra: module loaded with major number %d\n",
GLOB_SBD_majornum);
return;
out_blk_register:
unregister_blkdev(GLOB_SBD_majornum, GLOB_SBD_NAME);
out_ftl_flash_register:
GLOB_FTL_Cache_Release();
printk(KERN_ERR "Spectra: Module load failed.\n");
}
int register_spectra_ftl()
{
async_schedule(register_spectra_ftl_async, NULL);
return 0;
}
static int GLOB_SBD_init(void)
{
printk(KERN_ALERT "Spectra: %s\n", GLOB_version);
mutex_init(&spectra_lock);
if (PASS != GLOB_FTL_Flash_Init()) {
printk(KERN_ERR "Spectra: Unable to Initialize Flash Device. "
"Aborting\n");
return -ENODEV;
}
return 0;
}
static void __exit GLOB_SBD_exit(void)
{
int i;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
for (i = 0; i < NUM_DEVICES; i++) {
struct spectra_nand_dev *dev = &nand_device[i];
if (dev->gd) {
del_gendisk(dev->gd);
put_disk(dev->gd);
}
if (dev->queue)
blk_cleanup_queue(dev->queue);
kfree(dev->tmp_buf);
}
unregister_blkdev(GLOB_SBD_majornum, GLOB_SBD_NAME);
mutex_lock(&spectra_lock);
force_flush_cache();
mutex_unlock(&spectra_lock);
GLOB_FTL_Cache_Release();
GLOB_FTL_Flash_Release();
nand_dbg_print(NAND_DBG_DEBUG,
"Spectra FTL module (major number %d) unloaded.\n",
GLOB_SBD_majornum);
}
