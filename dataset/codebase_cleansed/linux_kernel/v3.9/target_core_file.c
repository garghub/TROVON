static inline struct fd_dev *FD_DEV(struct se_device *dev)
{
return container_of(dev, struct fd_dev, dev);
}
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
static struct se_device *fd_alloc_device(struct se_hba *hba, const char *name)
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
return &fd_dev->dev;
}
static int fd_configure_device(struct se_device *dev)
{
struct fd_dev *fd_dev = FD_DEV(dev);
struct fd_host *fd_host = dev->se_hba->hba_ptr;
struct file *file;
struct inode *inode = NULL;
int flags, ret = -EINVAL;
if (!(fd_dev->fbd_flags & FBDF_HAS_PATH)) {
pr_err("Missing fd_dev_name=\n");
return -EINVAL;
}
flags = O_RDWR | O_CREAT | O_LARGEFILE | O_DSYNC;
if (fd_dev->fbd_flags & FDBD_HAS_BUFFERED_IO_WCE) {
pr_debug("FILEIO: Disabling O_DSYNC, using buffered FILEIO\n");
flags &= ~O_DSYNC;
}
file = filp_open(fd_dev->fd_dev_name, flags, 0600);
if (IS_ERR(file)) {
pr_err("filp_open(%s) failed\n", fd_dev->fd_dev_name);
ret = PTR_ERR(file);
goto fail;
}
fd_dev->fd_file = file;
inode = file->f_mapping->host;
if (S_ISBLK(inode->i_mode)) {
struct request_queue *q = bdev_get_queue(inode->i_bdev);
unsigned long long dev_size;
dev->dev_attrib.hw_block_size =
bdev_logical_block_size(inode->i_bdev);
dev->dev_attrib.hw_max_sectors = queue_max_hw_sectors(q);
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
dev->dev_attrib.hw_block_size = FD_BLOCKSIZE;
dev->dev_attrib.hw_max_sectors = FD_MAX_SECTORS;
}
fd_dev->fd_block_size = dev->dev_attrib.hw_block_size;
dev->dev_attrib.hw_queue_depth = FD_MAX_DEVICE_QUEUE_DEPTH;
if (fd_dev->fbd_flags & FDBD_HAS_BUFFERED_IO_WCE) {
pr_debug("FILEIO: Forcing setting of emulate_write_cache=1"
" with FDBD_HAS_BUFFERED_IO_WCE\n");
dev->dev_attrib.emulate_write_cache = 1;
}
fd_dev->fd_dev_id = fd_host->fd_host_dev_id_count++;
fd_dev->fd_queue_depth = dev->queue_depth;
dev->dev_attrib.max_write_same_len = 0x1000;
pr_debug("CORE_FILE[%u] - Added TCM FILEIO Device ID: %u at %s,"
" %llu total bytes\n", fd_host->fd_host_id, fd_dev->fd_dev_id,
fd_dev->fd_dev_name, fd_dev->fd_dev_size);
return 0;
fail:
if (fd_dev->fd_file) {
filp_close(fd_dev->fd_file, NULL);
fd_dev->fd_file = NULL;
}
return ret;
}
static void fd_free_device(struct se_device *dev)
{
struct fd_dev *fd_dev = FD_DEV(dev);
if (fd_dev->fd_file) {
filp_close(fd_dev->fd_file, NULL);
fd_dev->fd_file = NULL;
}
kfree(fd_dev);
}
static int fd_do_rw(struct se_cmd *cmd, struct scatterlist *sgl,
u32 sgl_nents, int is_write)
{
struct se_device *se_dev = cmd->se_dev;
struct fd_dev *dev = FD_DEV(se_dev);
struct file *fd = dev->fd_file;
struct scatterlist *sg;
struct iovec *iov;
mm_segment_t old_fs;
loff_t pos = (cmd->t_task_lba * se_dev->dev_attrib.block_size);
int ret = 0, i;
iov = kzalloc(sizeof(struct iovec) * sgl_nents, GFP_KERNEL);
if (!iov) {
pr_err("Unable to allocate fd_do_readv iov[]\n");
return -ENOMEM;
}
for_each_sg(sgl, sg, sgl_nents, i) {
iov[i].iov_len = sg->length;
iov[i].iov_base = kmap(sg_page(sg)) + sg->offset;
}
old_fs = get_fs();
set_fs(get_ds());
if (is_write)
ret = vfs_writev(fd, &iov[0], sgl_nents, &pos);
else
ret = vfs_readv(fd, &iov[0], sgl_nents, &pos);
set_fs(old_fs);
for_each_sg(sgl, sg, sgl_nents, i)
kunmap(sg_page(sg));
kfree(iov);
if (is_write) {
if (ret < 0 || ret != cmd->data_length) {
pr_err("%s() write returned %d\n", __func__, ret);
return (ret < 0 ? ret : -EINVAL);
}
} else {
if (S_ISBLK(file_inode(fd)->i_mode)) {
if (ret < 0 || ret != cmd->data_length) {
pr_err("%s() returned %d, expecting %u for "
"S_ISBLK\n", __func__, ret,
cmd->data_length);
return (ret < 0 ? ret : -EINVAL);
}
} else {
if (ret < 0) {
pr_err("%s() returned %d for non S_ISBLK\n",
__func__, ret);
return ret;
}
}
}
return 1;
}
static sense_reason_t
fd_execute_sync_cache(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct fd_dev *fd_dev = FD_DEV(dev);
int immed = (cmd->t_task_cdb[1] & 0x2);
loff_t start, end;
int ret;
if (immed)
target_complete_cmd(cmd, SAM_STAT_GOOD);
if (cmd->t_task_lba == 0 && cmd->data_length == 0) {
start = 0;
end = LLONG_MAX;
} else {
start = cmd->t_task_lba * dev->dev_attrib.block_size;
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
if (ret)
target_complete_cmd(cmd, SAM_STAT_CHECK_CONDITION);
else
target_complete_cmd(cmd, SAM_STAT_GOOD);
return 0;
}
static unsigned char *
fd_setup_write_same_buf(struct se_cmd *cmd, struct scatterlist *sg,
unsigned int len)
{
struct se_device *se_dev = cmd->se_dev;
unsigned int block_size = se_dev->dev_attrib.block_size;
unsigned int i = 0, end;
unsigned char *buf, *p, *kmap_buf;
buf = kzalloc(min_t(unsigned int, len, PAGE_SIZE), GFP_KERNEL);
if (!buf) {
pr_err("Unable to allocate fd_execute_write_same buf\n");
return NULL;
}
kmap_buf = kmap(sg_page(sg)) + sg->offset;
if (!kmap_buf) {
pr_err("kmap() failed in fd_setup_write_same\n");
kfree(buf);
return NULL;
}
p = buf;
end = min_t(unsigned int, len, PAGE_SIZE);
while (i < end) {
memcpy(p, kmap_buf, block_size);
i += block_size;
p += block_size;
}
kunmap(sg_page(sg));
return buf;
}
static sense_reason_t
fd_execute_write_same(struct se_cmd *cmd)
{
struct se_device *se_dev = cmd->se_dev;
struct fd_dev *fd_dev = FD_DEV(se_dev);
struct file *f = fd_dev->fd_file;
struct scatterlist *sg;
struct iovec *iov;
mm_segment_t old_fs;
sector_t nolb = sbc_get_write_same_sectors(cmd);
loff_t pos = cmd->t_task_lba * se_dev->dev_attrib.block_size;
unsigned int len, len_tmp, iov_num;
int i, rc;
unsigned char *buf;
if (!nolb) {
target_complete_cmd(cmd, SAM_STAT_GOOD);
return 0;
}
sg = &cmd->t_data_sg[0];
if (cmd->t_data_nents > 1 ||
sg->length != cmd->se_dev->dev_attrib.block_size) {
pr_err("WRITE_SAME: Illegal SGL t_data_nents: %u length: %u"
" block_size: %u\n", cmd->t_data_nents, sg->length,
cmd->se_dev->dev_attrib.block_size);
return TCM_INVALID_CDB_FIELD;
}
len = len_tmp = nolb * se_dev->dev_attrib.block_size;
iov_num = DIV_ROUND_UP(len, PAGE_SIZE);
buf = fd_setup_write_same_buf(cmd, sg, len);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
iov = vzalloc(sizeof(struct iovec) * iov_num);
if (!iov) {
pr_err("Unable to allocate fd_execute_write_same iovecs\n");
kfree(buf);
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
for (i = 0; i < iov_num; i++) {
iov[i].iov_base = buf;
iov[i].iov_len = min_t(unsigned int, len_tmp, PAGE_SIZE);
len_tmp -= iov[i].iov_len;
}
old_fs = get_fs();
set_fs(get_ds());
rc = vfs_writev(f, &iov[0], iov_num, &pos);
set_fs(old_fs);
vfree(iov);
kfree(buf);
if (rc < 0 || rc != len) {
pr_err("vfs_writev() returned %d for write same\n", rc);
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
target_complete_cmd(cmd, SAM_STAT_GOOD);
return 0;
}
static sense_reason_t
fd_execute_rw(struct se_cmd *cmd)
{
struct scatterlist *sgl = cmd->t_data_sg;
u32 sgl_nents = cmd->t_data_nents;
enum dma_data_direction data_direction = cmd->data_direction;
struct se_device *dev = cmd->se_dev;
int ret = 0;
if (data_direction == DMA_FROM_DEVICE) {
ret = fd_do_rw(cmd, sgl, sgl_nents, 0);
} else {
ret = fd_do_rw(cmd, sgl, sgl_nents, 1);
if (ret > 0 &&
dev->dev_attrib.emulate_fua_write > 0 &&
(cmd->se_cmd_flags & SCF_FUA)) {
struct fd_dev *fd_dev = FD_DEV(dev);
loff_t start = cmd->t_task_lba *
dev->dev_attrib.block_size;
loff_t end = start + cmd->data_length;
vfs_fsync_range(fd_dev->fd_file, start, end, 1);
}
}
if (ret < 0)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
if (ret)
target_complete_cmd(cmd, SAM_STAT_GOOD);
return 0;
}
static ssize_t fd_set_configfs_dev_params(struct se_device *dev,
const char *page, ssize_t count)
{
struct fd_dev *fd_dev = FD_DEV(dev);
char *orig, *ptr, *arg_p, *opts;
substring_t args[MAX_OPT_ARGS];
int ret = 0, arg, token;
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
case Opt_fd_buffered_io:
match_int(args, &arg);
if (arg != 1) {
pr_err("bogus fd_buffered_io=%d value\n", arg);
ret = -EINVAL;
goto out;
}
pr_debug("FILEIO: Using buffered I/O"
" operations for struct fd_dev\n");
fd_dev->fbd_flags |= FDBD_HAS_BUFFERED_IO_WCE;
break;
default:
break;
}
}
out:
kfree(orig);
return (!ret) ? count : ret;
}
static ssize_t fd_show_configfs_dev_params(struct se_device *dev, char *b)
{
struct fd_dev *fd_dev = FD_DEV(dev);
ssize_t bl = 0;
bl = sprintf(b + bl, "TCM FILEIO ID: %u", fd_dev->fd_dev_id);
bl += sprintf(b + bl, " File: %s Size: %llu Mode: %s\n",
fd_dev->fd_dev_name, fd_dev->fd_dev_size,
(fd_dev->fbd_flags & FDBD_HAS_BUFFERED_IO_WCE) ?
"Buffered-WCE" : "O_DSYNC");
return bl;
}
static sector_t fd_get_blocks(struct se_device *dev)
{
struct fd_dev *fd_dev = FD_DEV(dev);
struct file *f = fd_dev->fd_file;
struct inode *i = f->f_mapping->host;
unsigned long long dev_size;
if (S_ISBLK(i->i_mode))
dev_size = (i_size_read(i) - fd_dev->fd_block_size);
else
dev_size = fd_dev->fd_dev_size;
return div_u64(dev_size, dev->dev_attrib.block_size);
}
static sense_reason_t
fd_parse_cdb(struct se_cmd *cmd)
{
return sbc_parse_cdb(cmd, &fd_sbc_ops);
}
static int __init fileio_module_init(void)
{
return transport_subsystem_register(&fileio_template);
}
static void __exit fileio_module_exit(void)
{
transport_subsystem_release(&fileio_template);
}
