static inline bool fsg_lun_is_open(struct fsg_lun *curlun)
{
return curlun->filp != NULL;
}
static inline struct fsg_lun *fsg_lun_from_dev(struct device *dev)
{
return container_of(dev, struct fsg_lun, dev);
}
static inline int fsg_num_buffers_validate(void)
{
if (fsg_num_buffers >= 2 && fsg_num_buffers <= 4)
return 0;
pr_err("fsg_num_buffers %u is out of range (%d to %d)\n",
fsg_num_buffers, 2 ,4);
return -EINVAL;
}
static inline u32 get_unaligned_be24(u8 *buf)
{
return 0xffffff & (u32) get_unaligned_be32(buf - 1);
}
static void fsg_lun_close(struct fsg_lun *curlun)
{
if (curlun->filp) {
LDBG(curlun, "close backing file\n");
fput(curlun->filp);
curlun->filp = NULL;
}
}
static int fsg_lun_open(struct fsg_lun *curlun, const char *filename)
{
int ro;
struct file *filp = NULL;
int rc = -EINVAL;
struct inode *inode = NULL;
loff_t size;
loff_t num_sectors;
loff_t min_sectors;
unsigned int blkbits;
unsigned int blksize;
ro = curlun->initially_ro;
if (!ro) {
filp = filp_open(filename, O_RDWR | O_LARGEFILE, 0);
if (PTR_ERR(filp) == -EROFS || PTR_ERR(filp) == -EACCES)
ro = 1;
}
if (ro)
filp = filp_open(filename, O_RDONLY | O_LARGEFILE, 0);
if (IS_ERR(filp)) {
LINFO(curlun, "unable to open backing file: %s\n", filename);
return PTR_ERR(filp);
}
if (!(filp->f_mode & FMODE_WRITE))
ro = 1;
inode = file_inode(filp);
if ((!S_ISREG(inode->i_mode) && !S_ISBLK(inode->i_mode))) {
LINFO(curlun, "invalid file type: %s\n", filename);
goto out;
}
if (!(filp->f_op->read || filp->f_op->aio_read)) {
LINFO(curlun, "file not readable: %s\n", filename);
goto out;
}
if (!(filp->f_op->write || filp->f_op->aio_write))
ro = 1;
size = i_size_read(inode->i_mapping->host);
if (size < 0) {
LINFO(curlun, "unable to find file size: %s\n", filename);
rc = (int) size;
goto out;
}
if (curlun->cdrom) {
blksize = 2048;
blkbits = 11;
} else if (inode->i_bdev) {
blksize = bdev_logical_block_size(inode->i_bdev);
blkbits = blksize_bits(blksize);
} else {
blksize = 512;
blkbits = 9;
}
num_sectors = size >> blkbits;
min_sectors = 1;
if (curlun->cdrom) {
min_sectors = 300;
if (num_sectors >= 256*60*75) {
num_sectors = 256*60*75 - 1;
LINFO(curlun, "file too big: %s\n", filename);
LINFO(curlun, "using only first %d blocks\n",
(int) num_sectors);
}
}
if (num_sectors < min_sectors) {
LINFO(curlun, "file too small: %s\n", filename);
rc = -ETOOSMALL;
goto out;
}
if (fsg_lun_is_open(curlun))
fsg_lun_close(curlun);
curlun->blksize = blksize;
curlun->blkbits = blkbits;
curlun->ro = ro;
curlun->filp = filp;
curlun->file_length = size;
curlun->num_sectors = num_sectors;
LDBG(curlun, "open backing file: %s\n", filename);
return 0;
out:
fput(filp);
return rc;
}
static int fsg_lun_fsync_sub(struct fsg_lun *curlun)
{
struct file *filp = curlun->filp;
if (curlun->ro || !filp)
return 0;
return vfs_fsync(filp, 1);
}
static void store_cdrom_address(u8 *dest, int msf, u32 addr)
{
if (msf) {
addr >>= 2;
addr += 2*75;
dest[3] = addr % 75;
addr /= 75;
dest[2] = addr % 60;
addr /= 60;
dest[1] = addr;
dest[0] = 0;
} else {
put_unaligned_be32(addr, dest);
}
}
static ssize_t fsg_show_ro(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fsg_lun *curlun = fsg_lun_from_dev(dev);
return sprintf(buf, "%d\n", fsg_lun_is_open(curlun)
? curlun->ro
: curlun->initially_ro);
}
static ssize_t fsg_show_nofua(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fsg_lun *curlun = fsg_lun_from_dev(dev);
return sprintf(buf, "%u\n", curlun->nofua);
}
static ssize_t fsg_show_file(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fsg_lun *curlun = fsg_lun_from_dev(dev);
struct rw_semaphore *filesem = dev_get_drvdata(dev);
char *p;
ssize_t rc;
down_read(filesem);
if (fsg_lun_is_open(curlun)) {
p = d_path(&curlun->filp->f_path, buf, PAGE_SIZE - 1);
if (IS_ERR(p))
rc = PTR_ERR(p);
else {
rc = strlen(p);
memmove(buf, p, rc);
buf[rc] = '\n';
buf[++rc] = 0;
}
} else {
*buf = 0;
rc = 0;
}
up_read(filesem);
return rc;
}
static ssize_t fsg_store_ro(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
ssize_t rc;
struct fsg_lun *curlun = fsg_lun_from_dev(dev);
struct rw_semaphore *filesem = dev_get_drvdata(dev);
unsigned ro;
rc = kstrtouint(buf, 2, &ro);
if (rc)
return rc;
down_read(filesem);
if (fsg_lun_is_open(curlun)) {
LDBG(curlun, "read-only status change prevented\n");
rc = -EBUSY;
} else {
curlun->ro = ro;
curlun->initially_ro = ro;
LDBG(curlun, "read-only status set to %d\n", curlun->ro);
rc = count;
}
up_read(filesem);
return rc;
}
static ssize_t fsg_store_nofua(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct fsg_lun *curlun = fsg_lun_from_dev(dev);
unsigned nofua;
int ret;
ret = kstrtouint(buf, 2, &nofua);
if (ret)
return ret;
if (!nofua && curlun->nofua)
fsg_lun_fsync_sub(curlun);
curlun->nofua = nofua;
return count;
}
static ssize_t fsg_store_file(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct fsg_lun *curlun = fsg_lun_from_dev(dev);
struct rw_semaphore *filesem = dev_get_drvdata(dev);
int rc = 0;
if (curlun->prevent_medium_removal && fsg_lun_is_open(curlun)) {
LDBG(curlun, "eject attempt prevented\n");
return -EBUSY;
}
if (count > 0 && buf[count-1] == '\n')
((char *) buf)[count-1] = 0;
down_write(filesem);
if (count > 0 && buf[0]) {
rc = fsg_lun_open(curlun, buf);
if (rc == 0)
curlun->unit_attention_data =
SS_NOT_READY_TO_READY_TRANSITION;
} else if (fsg_lun_is_open(curlun)) {
fsg_lun_close(curlun);
curlun->unit_attention_data = SS_MEDIUM_NOT_PRESENT;
}
up_write(filesem);
return (rc < 0 ? rc : count);
}
