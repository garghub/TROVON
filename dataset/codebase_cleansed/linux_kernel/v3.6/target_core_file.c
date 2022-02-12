static int fd_attach_hba(struct se_hba *hba, u32 host_id)
{
struct fd_host *fd_host;
fd_host = kzalloc(sizeof(struct fd_host), GFP_KERNEL);
if (!fd_host) {
pr_err("Unable to allocate memory for struct fd_host\n");
return -ENOMEM;
}
fd_host->fd_host_id = host_id;
hba->hba_ptr = fd_host;
pr_debug("CORE_HBA[%d] - TCM FILEIO HBA Driver %s on Generic"
" Target Core Stack %s\n", hba->hba_id, FD_VERSION,
TARGET_CORE_MOD_VERSION);
pr_debug("CORE_HBA[%d] - Attached FILEIO HBA: %u to Generic"
" MaxSectors: %u\n",
hba->hba_id, fd_host->fd_host_id, FD_MAX_SECTORS);
return 0;
}
static void fd_detach_hba(struct se_hba *hba)
{
struct fd_host *fd_host = hba->hba_ptr;
pr_debug("CORE_HBA[%d] - Detached FILEIO HBA: %u from Generic"
" Target Core\n", hba->hba_id, fd_host->fd_host_id);
kfree(fd_host);
hba->hba_ptr = NULL;
}
static void *fd_allocate_virtdevice(struct se_hba *hba, const char *name)
{
struct fd_dev *fd_dev;
struct fd_host *fd_host = hba->hba_ptr;
fd_dev = kzalloc(sizeof(struct fd_dev), GFP_KERNEL);
if (!fd_dev) {
pr_err("Unable to allocate memory for struct fd_dev\n");
return NULL;
}
fd_dev->fd_host = fd_host;
pr_debug("FILEIO: Allocated fd_dev for %p\n", name);
return fd_dev;
}
static struct se_device *fd_create_virtdevice(
struct se_hba *hba,
struct se_subsystem_dev *se_dev,
void *p)
{
struct se_device *dev;
struct se_dev_limits dev_limits;
struct queue_limits *limits;
struct fd_dev *fd_dev = p;
struct fd_host *fd_host = hba->hba_ptr;
struct file *file;
struct inode *inode = NULL;
int dev_flags = 0, flags, ret = -EINVAL;
memset(&dev_limits, 0, sizeof(struct se_dev_limits));
flags = O_RDWR | O_CREAT | O_LARGEFILE | O_DSYNC;
file = filp_open(fd_dev->fd_dev_name, flags, 0600);
if (IS_ERR(file)) {
pr_err("filp_open(%s) failed\n", fd_dev->fd_dev_name);
ret = PTR_ERR(file);
goto fail;
}
fd_dev->fd_file = file;
inode = file->f_mapping->host;
if (S_ISBLK(inode->i_mode)) {
struct request_queue *q;
unsigned long long dev_size;
q = bdev_get_queue(inode->i_bdev);
limits = &dev_limits.limits;
limits->logical_block_size = bdev_logical_block_size(inode->i_bdev);
limits->max_hw_sectors = queue_max_hw_sectors(q);
limits->max_sectors = queue_max_sectors(q);
fd_dev->fd_block_size = bdev_logical_block_size(inode->i_bdev);
dev_size = (i_size_read(file->f_mapping->host) -
fd_dev->fd_block_size);
pr_debug("FILEIO: Using size: %llu bytes from struct"
" block_device blocks: %llu logical_block_size: %d\n",
dev_size, div_u64(dev_size, fd_dev->fd_block_size),
fd_dev->fd_block_size);
} else {
if (!(fd_dev->fbd_flags & FBDF_HAS_SIZE)) {
pr_err("FILEIO: Missing fd_dev_size="
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
se_dev, dev_flags, fd_dev,
&dev_limits, "FILEIO", FD_VERSION);
if (!dev)
goto fail;
fd_dev->fd_dev_id = fd_host->fd_host_dev_id_count++;
fd_dev->fd_queue_depth = dev->queue_depth;
pr_debug("CORE_FILE[%u] - Added TCM FILEIO Device ID: %u at %s,"
" %llu total bytes\n", fd_host->fd_host_id, fd_dev->fd_dev_id,
fd_dev->fd_dev_name, fd_dev->fd_dev_size);
return dev;
fail:
if (fd_dev->fd_file) {
filp_close(fd_dev->fd_file, NULL);
fd_dev->fd_file = NULL;
}
return ERR_PTR(ret);
}
static void fd_free_device(void *p)
{
struct fd_dev *fd_dev = p;
if (fd_dev->fd_file) {
filp_close(fd_dev->fd_file, NULL);
fd_dev->fd_file = NULL;
}
kfree(fd_dev);
}
static int fd_do_readv(struct se_cmd *cmd, struct scatterlist *sgl,
u32 sgl_nents)
{
struct se_device *se_dev = cmd->se_dev;
struct fd_dev *dev = se_dev->dev_ptr;
struct file *fd = dev->fd_file;
struct scatterlist *sg;
struct iovec *iov;
mm_segment_t old_fs;
loff_t pos = (cmd->t_task_lba *
se_dev->se_sub_dev->se_dev_attrib.block_size);
int ret = 0, i;
iov = kzalloc(sizeof(struct iovec) * sgl_nents, GFP_KERNEL);
if (!iov) {
pr_err("Unable to allocate fd_do_readv iov[]\n");
return -ENOMEM;
}
for_each_sg(sgl, sg, sgl_nents, i) {
iov[i].iov_len = sg->length;
iov[i].iov_base = sg_virt(sg);
}
old_fs = get_fs();
set_fs(get_ds());
ret = vfs_readv(fd, &iov[0], sgl_nents, &pos);
set_fs(old_fs);
kfree(iov);
if (S_ISBLK(fd->f_dentry->d_inode->i_mode)) {
if (ret < 0 || ret != cmd->data_length) {
pr_err("vfs_readv() returned %d,"
" expecting %d for S_ISBLK\n", ret,
(int)cmd->data_length);
return (ret < 0 ? ret : -EINVAL);
}
} else {
if (ret < 0) {
pr_err("vfs_readv() returned %d for non"
" S_ISBLK\n", ret);
return ret;
}
}
return 1;
}
static int fd_do_writev(struct se_cmd *cmd, struct scatterlist *sgl,
u32 sgl_nents)
{
struct se_device *se_dev = cmd->se_dev;
struct fd_dev *dev = se_dev->dev_ptr;
struct file *fd = dev->fd_file;
struct scatterlist *sg;
struct iovec *iov;
mm_segment_t old_fs;
loff_t pos = (cmd->t_task_lba *
se_dev->se_sub_dev->se_dev_attrib.block_size);
int ret, i = 0;
iov = kzalloc(sizeof(struct iovec) * sgl_nents, GFP_KERNEL);
if (!iov) {
pr_err("Unable to allocate fd_do_writev iov[]\n");
return -ENOMEM;
}
for_each_sg(sgl, sg, sgl_nents, i) {
iov[i].iov_len = sg->length;
iov[i].iov_base = sg_virt(sg);
}
old_fs = get_fs();
set_fs(get_ds());
ret = vfs_writev(fd, &iov[0], sgl_nents, &pos);
set_fs(old_fs);
kfree(iov);
if (ret < 0 || ret != cmd->data_length) {
pr_err("vfs_writev() returned %d\n", ret);
return (ret < 0 ? ret : -EINVAL);
}
return 1;
}
static int fd_execute_sync_cache(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct fd_dev *fd_dev = dev->dev_ptr;
int immed = (cmd->t_task_cdb[1] & 0x2);
loff_t start, end;
int ret;
if (immed)
target_complete_cmd(cmd, SAM_STAT_GOOD);
if (cmd->t_task_lba == 0 && cmd->data_length == 0) {
start = 0;
end = LLONG_MAX;
} else {
start = cmd->t_task_lba * dev->se_sub_dev->se_dev_attrib.block_size;
if (cmd->data_length)
end = start + cmd->data_length;
else
end = LLONG_MAX;
}
ret = vfs_fsync_range(fd_dev->fd_file, start, end, 1);
if (ret != 0)
pr_err("FILEIO: vfs_fsync_range() failed: %d\n", ret);
if (immed)
return 0;
if (ret) {
cmd->scsi_sense_reason = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
target_complete_cmd(cmd, SAM_STAT_CHECK_CONDITION);
} else {
target_complete_cmd(cmd, SAM_STAT_GOOD);
}
return 0;
}
static int fd_execute_rw(struct se_cmd *cmd)
{
struct scatterlist *sgl = cmd->t_data_sg;
u32 sgl_nents = cmd->t_data_nents;
enum dma_data_direction data_direction = cmd->data_direction;
struct se_device *dev = cmd->se_dev;
int ret = 0;
if (data_direction == DMA_FROM_DEVICE) {
ret = fd_do_readv(cmd, sgl, sgl_nents);
} else {
ret = fd_do_writev(cmd, sgl, sgl_nents);
if (ret > 0 &&
dev->se_sub_dev->se_dev_attrib.emulate_fua_write > 0 &&
(cmd->se_cmd_flags & SCF_FUA)) {
struct fd_dev *fd_dev = dev->dev_ptr;
loff_t start = cmd->t_task_lba *
dev->se_sub_dev->se_dev_attrib.block_size;
loff_t end = start + cmd->data_length;
vfs_fsync_range(fd_dev->fd_file, start, end, 1);
}
}
if (ret < 0) {
cmd->scsi_sense_reason = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
return ret;
}
if (ret)
target_complete_cmd(cmd, SAM_STAT_GOOD);
return 0;
}
static ssize_t fd_set_configfs_dev_params(
struct se_hba *hba,
struct se_subsystem_dev *se_dev,
const char *page, ssize_t count)
{
struct fd_dev *fd_dev = se_dev->se_dev_su_ptr;
char *orig, *ptr, *arg_p, *opts;
substring_t args[MAX_OPT_ARGS];
int ret = 0, token;
opts = kstrdup(page, GFP_KERNEL);
if (!opts)
return -ENOMEM;
orig = opts;
while ((ptr = strsep(&opts, ",\n")) != NULL) {
if (!*ptr)
continue;
token = match_token(ptr, tokens, args);
switch (token) {
case Opt_fd_dev_name:
if (match_strlcpy(fd_dev->fd_dev_name, &args[0],
FD_MAX_DEV_NAME) == 0) {
ret = -EINVAL;
break;
}
pr_debug("FILEIO: Referencing Path: %s\n",
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
pr_err("strict_strtoull() failed for"
" fd_dev_size=\n");
goto out;
}
pr_debug("FILEIO: Referencing Size: %llu"
" bytes\n", fd_dev->fd_dev_size);
fd_dev->fbd_flags |= FBDF_HAS_SIZE;
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
struct fd_dev *fd_dev = se_dev->se_dev_su_ptr;
if (!(fd_dev->fbd_flags & FBDF_HAS_PATH)) {
pr_err("Missing fd_dev_name=\n");
return -EINVAL;
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
bl += sprintf(b + bl, " File: %s Size: %llu Mode: O_DSYNC\n",
fd_dev->fd_dev_name, fd_dev->fd_dev_size);
return bl;
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
struct file *f = fd_dev->fd_file;
struct inode *i = f->f_mapping->host;
unsigned long long dev_size;
if (S_ISBLK(i->i_mode))
dev_size = (i_size_read(i) - fd_dev->fd_block_size);
else
dev_size = fd_dev->fd_dev_size;
return div_u64(dev_size, dev->se_sub_dev->se_dev_attrib.block_size);
}
static int fd_parse_cdb(struct se_cmd *cmd)
{
return sbc_parse_cdb(cmd, &fd_spc_ops);
}
static int __init fileio_module_init(void)
{
return transport_subsystem_register(&fileio_template);
}
static void fileio_module_exit(void)
{
transport_subsystem_release(&fileio_template);
}
