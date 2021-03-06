int
tapechar_setup_device(struct tape_device * device)
{
char device_name[20];
sprintf(device_name, "ntibm%i", device->first_minor / 2);
device->nt = register_tape_dev(
&device->cdev->dev,
MKDEV(tapechar_major, device->first_minor),
&tape_fops,
device_name,
"non-rewinding"
);
device_name[0] = 'r';
device->rt = register_tape_dev(
&device->cdev->dev,
MKDEV(tapechar_major, device->first_minor + 1),
&tape_fops,
device_name,
"rewinding"
);
return 0;
}
void
tapechar_cleanup_device(struct tape_device *device)
{
unregister_tape_dev(&device->cdev->dev, device->rt);
device->rt = NULL;
unregister_tape_dev(&device->cdev->dev, device->nt);
device->nt = NULL;
}
static int
tapechar_check_idalbuffer(struct tape_device *device, size_t block_size)
{
struct idal_buffer *new;
if (device->char_data.idal_buf != NULL &&
device->char_data.idal_buf->size == block_size)
return 0;
if (block_size > MAX_BLOCKSIZE) {
DBF_EVENT(3, "Invalid blocksize (%zd > %d)\n",
block_size, MAX_BLOCKSIZE);
return -EINVAL;
}
new = idal_buffer_alloc(block_size, 0);
if (IS_ERR(new))
return -ENOMEM;
if (device->char_data.idal_buf != NULL)
idal_buffer_free(device->char_data.idal_buf);
device->char_data.idal_buf = new;
return 0;
}
static ssize_t
tapechar_read(struct file *filp, char __user *data, size_t count, loff_t *ppos)
{
struct tape_device *device;
struct tape_request *request;
size_t block_size;
int rc;
DBF_EVENT(6, "TCHAR:read\n");
device = (struct tape_device *) filp->private_data;
if(device->required_tapemarks) {
return tape_std_terminate_write(device);
}
if (device->char_data.block_size != 0) {
if (count < device->char_data.block_size) {
DBF_EVENT(3, "TCHAR:read smaller than block "
"size was requested\n");
return -EINVAL;
}
block_size = device->char_data.block_size;
} else {
block_size = count;
}
rc = tapechar_check_idalbuffer(device, block_size);
if (rc)
return rc;
DBF_EVENT(6, "TCHAR:nbytes: %lx\n", block_size);
request = device->discipline->read_block(device, block_size);
if (IS_ERR(request))
return PTR_ERR(request);
rc = tape_do_io(device, request);
if (rc == 0) {
rc = block_size - request->rescnt;
DBF_EVENT(6, "TCHAR:rbytes: %x\n", rc);
if (idal_buffer_to_user(device->char_data.idal_buf,
data, rc) != 0)
rc = -EFAULT;
}
tape_free_request(request);
return rc;
}
static ssize_t
tapechar_write(struct file *filp, const char __user *data, size_t count, loff_t *ppos)
{
struct tape_device *device;
struct tape_request *request;
size_t block_size;
size_t written;
int nblocks;
int i, rc;
DBF_EVENT(6, "TCHAR:write\n");
device = (struct tape_device *) filp->private_data;
if (device->char_data.block_size != 0) {
if (count < device->char_data.block_size) {
DBF_EVENT(3, "TCHAR:write smaller than block "
"size was requested\n");
return -EINVAL;
}
block_size = device->char_data.block_size;
nblocks = count / block_size;
} else {
block_size = count;
nblocks = 1;
}
rc = tapechar_check_idalbuffer(device, block_size);
if (rc)
return rc;
DBF_EVENT(6,"TCHAR:nbytes: %lx\n", block_size);
DBF_EVENT(6, "TCHAR:nblocks: %x\n", nblocks);
request = device->discipline->write_block(device, block_size);
if (IS_ERR(request))
return PTR_ERR(request);
rc = 0;
written = 0;
for (i = 0; i < nblocks; i++) {
if (idal_buffer_from_user(device->char_data.idal_buf,
data, block_size)) {
rc = -EFAULT;
break;
}
rc = tape_do_io(device, request);
if (rc)
break;
DBF_EVENT(6, "TCHAR:wbytes: %lx\n",
block_size - request->rescnt);
written += block_size - request->rescnt;
if (request->rescnt != 0)
break;
data += block_size;
}
tape_free_request(request);
if (rc == -ENOSPC) {
if (device->discipline->process_eov)
device->discipline->process_eov(device);
if (written > 0)
rc = 0;
}
if (!rc)
device->required_tapemarks = 2;
return rc ? rc : written;
}
static int
tapechar_open (struct inode *inode, struct file *filp)
{
struct tape_device *device;
int minor, rc;
DBF_EVENT(6, "TCHAR:open: %i:%i\n",
imajor(file_inode(filp)),
iminor(file_inode(filp)));
if (imajor(file_inode(filp)) != tapechar_major)
return -ENODEV;
minor = iminor(file_inode(filp));
device = tape_find_device(minor / TAPE_MINORS_PER_DEV);
if (IS_ERR(device)) {
DBF_EVENT(3, "TCHAR:open: tape_find_device() failed\n");
return PTR_ERR(device);
}
rc = tape_open(device);
if (rc == 0) {
filp->private_data = device;
nonseekable_open(inode, filp);
} else
tape_put_device(device);
return rc;
}
static int
tapechar_release(struct inode *inode, struct file *filp)
{
struct tape_device *device;
DBF_EVENT(6, "TCHAR:release: %x\n", iminor(inode));
device = (struct tape_device *) filp->private_data;
if ((iminor(inode) & 1) != 0) {
if (device->required_tapemarks)
tape_std_terminate_write(device);
tape_mtop(device, MTREW, 1);
} else {
if (device->required_tapemarks > 1) {
if (tape_mtop(device, MTWEOF, 1) == 0)
device->required_tapemarks--;
}
}
if (device->char_data.idal_buf != NULL) {
idal_buffer_free(device->char_data.idal_buf);
device->char_data.idal_buf = NULL;
}
tape_release(device);
filp->private_data = NULL;
tape_put_device(device);
return 0;
}
static int
__tapechar_ioctl(struct tape_device *device,
unsigned int no, unsigned long data)
{
int rc;
if (no == MTIOCTOP) {
struct mtop op;
if (copy_from_user(&op, (char __user *) data, sizeof(op)) != 0)
return -EFAULT;
if (op.mt_count < 0)
return -EINVAL;
switch (op.mt_op) {
case MTFSF:
case MTBSF:
case MTFSR:
case MTBSR:
case MTREW:
case MTOFFL:
case MTEOM:
case MTRETEN:
case MTBSFM:
case MTFSFM:
case MTSEEK:
if (device->required_tapemarks)
tape_std_terminate_write(device);
default:
;
}
rc = tape_mtop(device, op.mt_op, op.mt_count);
if (op.mt_op == MTWEOF && rc == 0) {
if (op.mt_count > device->required_tapemarks)
device->required_tapemarks = 0;
else
device->required_tapemarks -= op.mt_count;
}
return rc;
}
if (no == MTIOCPOS) {
struct mtpos pos;
rc = tape_mtop(device, MTTELL, 1);
if (rc < 0)
return rc;
pos.mt_blkno = rc;
if (copy_to_user((char __user *) data, &pos, sizeof(pos)) != 0)
return -EFAULT;
return 0;
}
if (no == MTIOCGET) {
struct mtget get;
memset(&get, 0, sizeof(get));
get.mt_type = MT_ISUNKNOWN;
get.mt_resid = 0 ;
get.mt_dsreg =
((device->char_data.block_size << MT_ST_BLKSIZE_SHIFT)
& MT_ST_BLKSIZE_MASK);
get.mt_gstat = 0;
get.mt_erreg = 0;
get.mt_fileno = 0;
get.mt_gstat = device->tape_generic_status;
if (device->medium_state == MS_LOADED) {
rc = tape_mtop(device, MTTELL, 1);
if (rc < 0)
return rc;
if (rc == 0)
get.mt_gstat |= GMT_BOT(~0);
get.mt_blkno = rc;
}
if (copy_to_user((char __user *) data, &get, sizeof(get)) != 0)
return -EFAULT;
return 0;
}
if (device->discipline->ioctl_fn == NULL)
return -EINVAL;
return device->discipline->ioctl_fn(device, no, data);
}
static long
tapechar_ioctl(struct file *filp, unsigned int no, unsigned long data)
{
struct tape_device *device;
long rc;
DBF_EVENT(6, "TCHAR:ioct\n");
device = (struct tape_device *) filp->private_data;
mutex_lock(&device->mutex);
rc = __tapechar_ioctl(device, no, data);
mutex_unlock(&device->mutex);
return rc;
}
static long
tapechar_compat_ioctl(struct file *filp, unsigned int no, unsigned long data)
{
struct tape_device *device = filp->private_data;
int rval = -ENOIOCTLCMD;
unsigned long argp;
argp = (unsigned long) compat_ptr(data);
if (device->discipline->ioctl_fn) {
mutex_lock(&device->mutex);
rval = device->discipline->ioctl_fn(device, no, argp);
mutex_unlock(&device->mutex);
if (rval == -EINVAL)
rval = -ENOIOCTLCMD;
}
return rval;
}
int
tapechar_init (void)
{
dev_t dev;
if (alloc_chrdev_region(&dev, 0, 256, "tape") != 0)
return -1;
tapechar_major = MAJOR(dev);
return 0;
}
void
tapechar_exit(void)
{
unregister_chrdev_region(MKDEV(tapechar_major, 0), 256);
}
