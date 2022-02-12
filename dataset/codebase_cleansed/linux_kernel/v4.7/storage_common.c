void fsg_lun_close(struct fsg_lun *curlun)
{
if (curlun->filp) {
LDBG(curlun, "close backing file\n");
fput(curlun->filp);
curlun->filp = NULL;
}
}
int fsg_lun_open(struct fsg_lun *curlun, const char *filename)
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
if (!(filp->f_mode & FMODE_CAN_READ)) {
LINFO(curlun, "file not readable: %s\n", filename);
goto out;
}
if (!(filp->f_mode & FMODE_CAN_WRITE))
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
int fsg_lun_fsync_sub(struct fsg_lun *curlun)
{
struct file *filp = curlun->filp;
if (curlun->ro || !filp)
return 0;
return vfs_fsync(filp, 1);
}
void store_cdrom_address(u8 *dest, int msf, u32 addr)
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
ssize_t fsg_show_ro(struct fsg_lun *curlun, char *buf)
{
return sprintf(buf, "%d\n", fsg_lun_is_open(curlun)
? curlun->ro
: curlun->initially_ro);
}
ssize_t fsg_show_nofua(struct fsg_lun *curlun, char *buf)
{
return sprintf(buf, "%u\n", curlun->nofua);
}
ssize_t fsg_show_file(struct fsg_lun *curlun, struct rw_semaphore *filesem,
char *buf)
{
char *p;
ssize_t rc;
down_read(filesem);
if (fsg_lun_is_open(curlun)) {
p = file_path(curlun->filp, buf, PAGE_SIZE - 1);
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
ssize_t fsg_show_cdrom(struct fsg_lun *curlun, char *buf)
{
return sprintf(buf, "%u\n", curlun->cdrom);
}
ssize_t fsg_show_removable(struct fsg_lun *curlun, char *buf)
{
return sprintf(buf, "%u\n", curlun->removable);
}
static ssize_t _fsg_store_ro(struct fsg_lun *curlun, bool ro)
{
if (fsg_lun_is_open(curlun)) {
LDBG(curlun, "read-only status change prevented\n");
return -EBUSY;
}
curlun->ro = ro;
curlun->initially_ro = ro;
LDBG(curlun, "read-only status set to %d\n", curlun->ro);
return 0;
}
ssize_t fsg_store_ro(struct fsg_lun *curlun, struct rw_semaphore *filesem,
const char *buf, size_t count)
{
ssize_t rc;
bool ro;
rc = strtobool(buf, &ro);
if (rc)
return rc;
down_read(filesem);
rc = _fsg_store_ro(curlun, ro);
if (!rc)
rc = count;
up_read(filesem);
return rc;
}
ssize_t fsg_store_nofua(struct fsg_lun *curlun, const char *buf, size_t count)
{
bool nofua;
int ret;
ret = strtobool(buf, &nofua);
if (ret)
return ret;
if (!nofua && curlun->nofua)
fsg_lun_fsync_sub(curlun);
curlun->nofua = nofua;
return count;
}
ssize_t fsg_store_file(struct fsg_lun *curlun, struct rw_semaphore *filesem,
const char *buf, size_t count)
{
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
ssize_t fsg_store_cdrom(struct fsg_lun *curlun, struct rw_semaphore *filesem,
const char *buf, size_t count)
{
bool cdrom;
int ret;
ret = strtobool(buf, &cdrom);
if (ret)
return ret;
down_read(filesem);
ret = cdrom ? _fsg_store_ro(curlun, true) : 0;
if (!ret) {
curlun->cdrom = cdrom;
ret = count;
}
up_read(filesem);
return ret;
}
ssize_t fsg_store_removable(struct fsg_lun *curlun, const char *buf,
size_t count)
{
bool removable;
int ret;
ret = strtobool(buf, &removable);
if (ret)
return ret;
curlun->removable = removable;
return count;
}
