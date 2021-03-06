static int fd_attach_hba(struct se_hba *hba, u32 host_id)
{
struct fd_host *fd_host;
fd_host = kzalloc(sizeof(struct fd_host), GFP_KERNEL);
if (!(fd_host)) {
printk(KERN_ERR "Unable to allocate memory for struct fd_host\n");
return -1;
}
fd_host->fd_host_id = host_id;
atomic_set(&hba->left_queue_depth, FD_HBA_QUEUE_DEPTH);
atomic_set(&hba->max_queue_depth, FD_HBA_QUEUE_DEPTH);
hba->hba_ptr = (void *) fd_host;
printk(KERN_INFO "CORE_HBA[%d] - TCM FILEIO HBA Driver %s on Generic"
" Target Core Stack %s\n", hba->hba_id, FD_VERSION,
TARGET_CORE_MOD_VERSION);
printk(KERN_INFO "CORE_HBA[%d] - Attached FILEIO HBA: %u to Generic"
" Target Core with TCQ Depth: %d MaxSectors: %u\n",
hba->hba_id, fd_host->fd_host_id,
atomic_read(&hba->max_queue_depth), FD_MAX_SECTORS);
return 0;
}
static void fd_detach_hba(struct se_hba *hba)
{
struct fd_host *fd_host = hba->hba_ptr;
printk(KERN_INFO "CORE_HBA[%d] - Detached FILEIO HBA: %u from Generic"
" Target Core\n", hba->hba_id, fd_host->fd_host_id);
kfree(fd_host);
hba->hba_ptr = NULL;
}
static void *fd_allocate_virtdevice(struct se_hba *hba, const char *name)
{
struct fd_dev *fd_dev;
struct fd_host *fd_host = (struct fd_host *) hba->hba_ptr;
fd_dev = kzalloc(sizeof(struct fd_dev), GFP_KERNEL);
if (!(fd_dev)) {
printk(KERN_ERR "Unable to allocate memory for struct fd_dev\n");
return NULL;
}
fd_dev->fd_host = fd_host;
printk(KERN_INFO "FILEIO: Allocated fd_dev for %p\n", name);
return fd_dev;
}
static struct se_device *fd_create_virtdevice(
struct se_hba *hba,
struct se_subsystem_dev *se_dev,
void *p)
{
char *dev_p = NULL;
struct se_device *dev;
struct se_dev_limits dev_limits;
struct queue_limits *limits;
struct fd_dev *fd_dev = (struct fd_dev *) p;
struct fd_host *fd_host = (struct fd_host *) hba->hba_ptr;
mm_segment_t old_fs;
struct file *file;
struct inode *inode = NULL;
int dev_flags = 0, flags, ret = -EINVAL;
memset(&dev_limits, 0, sizeof(struct se_dev_limits));
old_fs = get_fs();
set_fs(get_ds());
dev_p = getname(fd_dev->fd_dev_name);
set_fs(old_fs);
if (IS_ERR(dev_p)) {
printk(KERN_ERR "getname(%s) failed: %lu\n",
fd_dev->fd_dev_name, IS_ERR(dev_p));
ret = PTR_ERR(dev_p);
goto fail;
}
#if 0
if (di->no_create_file)
flags = O_RDWR | O_LARGEFILE;
else
flags = O_RDWR | O_CREAT | O_LARGEFILE;
#else
flags = O_RDWR | O_CREAT | O_LARGEFILE;
#endif
if (!(fd_dev->fbd_flags & FDBD_USE_BUFFERED_IO))
flags |= O_SYNC;
file = filp_open(dev_p, flags, 0600);
if (IS_ERR(file)) {
printk(KERN_ERR "filp_open(%s) failed\n", dev_p);
ret = PTR_ERR(file);
goto fail;
}
if (!file || !file->f_dentry) {
printk(KERN_ERR "filp_open(%s) failed\n", dev_p);
goto fail;
}
fd_dev->fd_file = file;
inode = file->f_mapping->host;
if (S_ISBLK(inode->i_mode)) {
struct request_queue *q;
q = bdev_get_queue(inode->i_bdev);
limits = &dev_limits.limits;
limits->logical_block_size = bdev_logical_block_size(inode->i_bdev);
limits->max_hw_sectors = queue_max_hw_sectors(q);
limits->max_sectors = queue_max_sectors(q);
fd_dev->fd_block_size = bdev_logical_block_size(inode->i_bdev);
fd_dev->fd_dev_size = (i_size_read(file->f_mapping->host) -
fd_dev->fd_block_size);
printk(KERN_INFO "FILEIO: Using size: %llu bytes from struct"
" block_device blocks: %llu logical_block_size: %d\n",
fd_dev->fd_dev_size,
div_u64(fd_dev->fd_dev_size, fd_dev->fd_block_size),
fd_dev->fd_block_size);
} else {
if (!(fd_dev->fbd_flags & FBDF_HAS_SIZE)) {
printk(KERN_ERR "FILEIO: Missing fd_dev_size="
" parameter, and no backing struct"
" block_device\n");
goto fail;
}
limits = &dev_limits.limits;
limits->logical_block_size = FD_BLOCKSIZE;
limits->max_hw_sectors = FD_MAX_SECTORS;
limits->max_sectors = FD_MAX_SECTORS;
fd_dev->fd_block_size = FD_BLOCKSIZE;
}
dev_limits.hw_queue_depth = FD_MAX_DEVICE_QUEUE_DEPTH;
dev_limits.queue_depth = FD_DEVICE_QUEUE_DEPTH;
dev = transport_add_device_to_core_hba(hba, &fileio_template,
se_dev, dev_flags, (void *)fd_dev,
&dev_limits, "FILEIO", FD_VERSION);
if (!(dev))
goto fail;
fd_dev->fd_dev_id = fd_host->fd_host_dev_id_count++;
fd_dev->fd_queue_depth = dev->queue_depth;
printk(KERN_INFO "CORE_FILE[%u] - Added TCM FILEIO Device ID: %u at %s,"
" %llu total bytes\n", fd_host->fd_host_id, fd_dev->fd_dev_id,
fd_dev->fd_dev_name, fd_dev->fd_dev_size);
putname(dev_p);
return dev;
fail:
if (fd_dev->fd_file) {
filp_close(fd_dev->fd_file, NULL);
fd_dev->fd_file = NULL;
}
putname(dev_p);
return ERR_PTR(ret);
}
static void fd_free_device(void *p)
{
struct fd_dev *fd_dev = (struct fd_dev *) p;
if (fd_dev->fd_file) {
filp_close(fd_dev->fd_file, NULL);
fd_dev->fd_file = NULL;
}
kfree(fd_dev);
}
static inline struct fd_request *FILE_REQ(struct se_task *task)
{
return container_of(task, struct fd_request, fd_task);
}
static struct se_task *
fd_alloc_task(struct se_cmd *cmd)
{
struct fd_request *fd_req;
fd_req = kzalloc(sizeof(struct fd_request), GFP_KERNEL);
if (!(fd_req)) {
printk(KERN_ERR "Unable to allocate struct fd_request\n");
return NULL;
}
fd_req->fd_dev = SE_DEV(cmd)->dev_ptr;
return &fd_req->fd_task;
}
static int fd_do_readv(struct se_task *task)
{
struct fd_request *req = FILE_REQ(task);
struct file *fd = req->fd_dev->fd_file;
struct scatterlist *sg = task->task_sg;
struct iovec *iov;
mm_segment_t old_fs;
loff_t pos = (task->task_lba * DEV_ATTRIB(task->se_dev)->block_size);
int ret = 0, i;
iov = kzalloc(sizeof(struct iovec) * task->task_sg_num, GFP_KERNEL);
if (!(iov)) {
printk(KERN_ERR "Unable to allocate fd_do_readv iov[]\n");
return -1;
}
for (i = 0; i < task->task_sg_num; i++) {
iov[i].iov_len = sg[i].length;
iov[i].iov_base = sg_virt(&sg[i]);
}
old_fs = get_fs();
set_fs(get_ds());
ret = vfs_readv(fd, &iov[0], task->task_sg_num, &pos);
set_fs(old_fs);
kfree(iov);
if (S_ISBLK(fd->f_dentry->d_inode->i_mode)) {
if (ret < 0 || ret != task->task_size) {
printk(KERN_ERR "vfs_readv() returned %d,"
" expecting %d for S_ISBLK\n", ret,
(int)task->task_size);
return -1;
}
} else {
if (ret < 0) {
printk(KERN_ERR "vfs_readv() returned %d for non"
" S_ISBLK\n", ret);
return -1;
}
}
return 1;
}
static int fd_do_writev(struct se_task *task)
{
struct fd_request *req = FILE_REQ(task);
struct file *fd = req->fd_dev->fd_file;
struct scatterlist *sg = task->task_sg;
struct iovec *iov;
mm_segment_t old_fs;
loff_t pos = (task->task_lba * DEV_ATTRIB(task->se_dev)->block_size);
int ret, i = 0;
iov = kzalloc(sizeof(struct iovec) * task->task_sg_num, GFP_KERNEL);
if (!(iov)) {
printk(KERN_ERR "Unable to allocate fd_do_writev iov[]\n");
return -1;
}
for (i = 0; i < task->task_sg_num; i++) {
iov[i].iov_len = sg[i].length;
iov[i].iov_base = sg_virt(&sg[i]);
}
old_fs = get_fs();
set_fs(get_ds());
ret = vfs_writev(fd, &iov[0], task->task_sg_num, &pos);
set_fs(old_fs);
kfree(iov);
if (ret < 0 || ret != task->task_size) {
printk(KERN_ERR "vfs_writev() returned %d\n", ret);
return -1;
}
return 1;
}
static void fd_emulate_sync_cache(struct se_task *task)
{
struct se_cmd *cmd = TASK_CMD(task);
struct se_device *dev = cmd->se_dev;
struct fd_dev *fd_dev = dev->dev_ptr;
int immed = (cmd->t_task->t_task_cdb[1] & 0x2);
loff_t start, end;
int ret;
if (immed)
transport_complete_sync_cache(cmd, 1);
if (cmd->t_task->t_task_lba == 0 && cmd->data_length == 0) {
start = 0;
end = LLONG_MAX;
} else {
start = cmd->t_task->t_task_lba * DEV_ATTRIB(dev)->block_size;
if (cmd->data_length)
end = start + cmd->data_length;
else
end = LLONG_MAX;
}
ret = vfs_fsync_range(fd_dev->fd_file, start, end, 1);
if (ret != 0)
printk(KERN_ERR "FILEIO: vfs_fsync_range() failed: %d\n", ret);
if (!immed)
transport_complete_sync_cache(cmd, ret == 0);
}
static int fd_emulated_write_cache(struct se_device *dev)
{
return 1;
}
static int fd_emulated_dpo(struct se_device *dev)
{
return 0;
}
static int fd_emulated_fua_write(struct se_device *dev)
{
return 1;
}
static int fd_emulated_fua_read(struct se_device *dev)
{
return 0;
}
static void fd_emulate_write_fua(struct se_cmd *cmd, struct se_task *task)
{
struct se_device *dev = cmd->se_dev;
struct fd_dev *fd_dev = dev->dev_ptr;
loff_t start = task->task_lba * DEV_ATTRIB(dev)->block_size;
loff_t end = start + task->task_size;
int ret;
DEBUG_FD_CACHE("FILEIO: FUA WRITE LBA: %llu, bytes: %u\n",
task->task_lba, task->task_size);
ret = vfs_fsync_range(fd_dev->fd_file, start, end, 1);
if (ret != 0)
printk(KERN_ERR "FILEIO: vfs_fsync_range() failed: %d\n", ret);
}
static int fd_do_task(struct se_task *task)
{
struct se_cmd *cmd = task->task_se_cmd;
struct se_device *dev = cmd->se_dev;
int ret = 0;
if (task->task_data_direction == DMA_FROM_DEVICE) {
ret = fd_do_readv(task);
} else {
ret = fd_do_writev(task);
if (ret > 0 &&
DEV_ATTRIB(dev)->emulate_write_cache > 0 &&
DEV_ATTRIB(dev)->emulate_fua_write > 0 &&
T_TASK(cmd)->t_tasks_fua) {
fd_emulate_write_fua(cmd, task);
}
}
if (ret < 0)
return ret;
if (ret) {
task->task_scsi_status = GOOD;
transport_complete_task(task, 1);
}
return PYX_TRANSPORT_SENT_TO_TRANSPORT;
}
static void fd_free_task(struct se_task *task)
{
struct fd_request *req = FILE_REQ(task);
kfree(req);
}
static ssize_t fd_set_configfs_dev_params(
struct se_hba *hba,
struct se_subsystem_dev *se_dev,
const char *page, ssize_t count)
{
struct fd_dev *fd_dev = se_dev->se_dev_su_ptr;
char *orig, *ptr, *arg_p, *opts;
substring_t args[MAX_OPT_ARGS];
int ret = 0, arg, token;
opts = kstrdup(page, GFP_KERNEL);
if (!opts)
return -ENOMEM;
orig = opts;
while ((ptr = strsep(&opts, ",")) != NULL) {
if (!*ptr)
continue;
token = match_token(ptr, tokens, args);
switch (token) {
case Opt_fd_dev_name:
arg_p = match_strdup(&args[0]);
if (!arg_p) {
ret = -ENOMEM;
break;
}
snprintf(fd_dev->fd_dev_name, FD_MAX_DEV_NAME,
"%s", arg_p);
kfree(arg_p);
printk(KERN_INFO "FILEIO: Referencing Path: %s\n",
fd_dev->fd_dev_name);
fd_dev->fbd_flags |= FBDF_HAS_PATH;
break;
case Opt_fd_dev_size:
arg_p = match_strdup(&args[0]);
if (!arg_p) {
ret = -ENOMEM;
break;
}
ret = strict_strtoull(arg_p, 0, &fd_dev->fd_dev_size);
kfree(arg_p);
if (ret < 0) {
printk(KERN_ERR "strict_strtoull() failed for"
" fd_dev_size=\n");
goto out;
}
printk(KERN_INFO "FILEIO: Referencing Size: %llu"
" bytes\n", fd_dev->fd_dev_size);
fd_dev->fbd_flags |= FBDF_HAS_SIZE;
break;
case Opt_fd_buffered_io:
match_int(args, &arg);
if (arg != 1) {
printk(KERN_ERR "bogus fd_buffered_io=%d value\n", arg);
ret = -EINVAL;
goto out;
}
printk(KERN_INFO "FILEIO: Using buffered I/O"
" operations for struct fd_dev\n");
fd_dev->fbd_flags |= FDBD_USE_BUFFERED_IO;
break;
default:
break;
}
}
out:
kfree(orig);
return (!ret) ? count : ret;
}
static ssize_t fd_check_configfs_dev_params(struct se_hba *hba, struct se_subsystem_dev *se_dev)
{
struct fd_dev *fd_dev = (struct fd_dev *) se_dev->se_dev_su_ptr;
if (!(fd_dev->fbd_flags & FBDF_HAS_PATH)) {
printk(KERN_ERR "Missing fd_dev_name=\n");
return -1;
}
return 0;
}
static ssize_t fd_show_configfs_dev_params(
struct se_hba *hba,
struct se_subsystem_dev *se_dev,
char *b)
{
struct fd_dev *fd_dev = se_dev->se_dev_su_ptr;
ssize_t bl = 0;
bl = sprintf(b + bl, "TCM FILEIO ID: %u", fd_dev->fd_dev_id);
bl += sprintf(b + bl, " File: %s Size: %llu Mode: %s\n",
fd_dev->fd_dev_name, fd_dev->fd_dev_size,
(fd_dev->fbd_flags & FDBD_USE_BUFFERED_IO) ?
"Buffered" : "Synchronous");
return bl;
}
static unsigned char *fd_get_cdb(struct se_task *task)
{
struct fd_request *req = FILE_REQ(task);
return req->fd_scsi_cdb;
}
static u32 fd_get_device_rev(struct se_device *dev)
{
return SCSI_SPC_2;
}
static u32 fd_get_device_type(struct se_device *dev)
{
return TYPE_DISK;
}
static sector_t fd_get_blocks(struct se_device *dev)
{
struct fd_dev *fd_dev = dev->dev_ptr;
unsigned long long blocks_long = div_u64(fd_dev->fd_dev_size,
DEV_ATTRIB(dev)->block_size);
return blocks_long;
}
static int __init fileio_module_init(void)
{
return transport_subsystem_register(&fileio_template);
}
static void fileio_module_exit(void)
{
transport_subsystem_release(&fileio_template);
}
