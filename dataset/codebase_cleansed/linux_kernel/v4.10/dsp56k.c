static int dsp56k_reset(void)
{
u_char status;
sound_ym.rd_data_reg_sel = 14;
status = sound_ym.rd_data_reg_sel & 0xef;
sound_ym.wd_data = status;
sound_ym.wd_data = status | 0x10;
udelay(10);
sound_ym.rd_data_reg_sel = 14;
sound_ym.wd_data = sound_ym.rd_data_reg_sel & 0xef;
return 0;
}
static int dsp56k_upload(u_char __user *bin, int len)
{
struct platform_device *pdev;
const struct firmware *fw;
const char fw_name[] = "dsp56k/bootstrap.bin";
int err;
int i;
dsp56k_reset();
pdev = platform_device_register_simple("dsp56k", 0, NULL, 0);
if (IS_ERR(pdev)) {
printk(KERN_ERR "Failed to register device for \"%s\"\n",
fw_name);
return -EINVAL;
}
err = request_firmware(&fw, fw_name, &pdev->dev);
platform_device_unregister(pdev);
if (err) {
printk(KERN_ERR "Failed to load image \"%s\" err %d\n",
fw_name, err);
return err;
}
if (fw->size % 3) {
printk(KERN_ERR "Bogus length %d in image \"%s\"\n",
fw->size, fw_name);
release_firmware(fw);
return -EINVAL;
}
for (i = 0; i < fw->size; i = i + 3) {
dsp56k_host_interface.data.b[1] = fw->data[i];
dsp56k_host_interface.data.b[2] = fw->data[i + 1];
dsp56k_host_interface.data.b[3] = fw->data[i + 2];
}
release_firmware(fw);
for (; i < 512; i++) {
dsp56k_host_interface.data.b[1] = 0;
dsp56k_host_interface.data.b[2] = 0;
dsp56k_host_interface.data.b[3] = 0;
}
for (i = 0; i < len; i++) {
tx_wait(10);
get_user(dsp56k_host_interface.data.b[1], bin++);
get_user(dsp56k_host_interface.data.b[2], bin++);
get_user(dsp56k_host_interface.data.b[3], bin++);
}
tx_wait(10);
dsp56k_host_interface.data.l = 3;
return 0;
}
static ssize_t dsp56k_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
struct inode *inode = file_inode(file);
int dev = iminor(inode) & 0x0f;
switch(dev)
{
case DSP56K_DEV_56001:
{
long n;
if (!count) return 0;
n = 0;
switch (dsp56k.rx_wsize) {
case 1:
{
handshake(count, dsp56k.maxio, dsp56k.timeout, DSP56K_RECEIVE,
put_user(dsp56k_host_interface.data.b[3], buf+n++));
return n;
}
case 2:
{
short __user *data;
count /= 2;
data = (short __user *) buf;
handshake(count, dsp56k.maxio, dsp56k.timeout, DSP56K_RECEIVE,
put_user(dsp56k_host_interface.data.w[1], data+n++));
return 2*n;
}
case 3:
{
count /= 3;
handshake(count, dsp56k.maxio, dsp56k.timeout, DSP56K_RECEIVE,
put_user(dsp56k_host_interface.data.b[1], buf+n++);
put_user(dsp56k_host_interface.data.b[2], buf+n++);
put_user(dsp56k_host_interface.data.b[3], buf+n++));
return 3*n;
}
case 4:
{
long __user *data;
count /= 4;
data = (long __user *) buf;
handshake(count, dsp56k.maxio, dsp56k.timeout, DSP56K_RECEIVE,
put_user(dsp56k_host_interface.data.l, data+n++));
return 4*n;
}
}
return -EFAULT;
}
default:
printk(KERN_ERR "DSP56k driver: Unknown minor device: %d\n", dev);
return -ENXIO;
}
}
static ssize_t dsp56k_write(struct file *file, const char __user *buf, size_t count,
loff_t *ppos)
{
struct inode *inode = file_inode(file);
int dev = iminor(inode) & 0x0f;
switch(dev)
{
case DSP56K_DEV_56001:
{
long n;
if (!count) return 0;
n = 0;
switch (dsp56k.tx_wsize) {
case 1:
{
handshake(count, dsp56k.maxio, dsp56k.timeout, DSP56K_TRANSMIT,
get_user(dsp56k_host_interface.data.b[3], buf+n++));
return n;
}
case 2:
{
const short __user *data;
count /= 2;
data = (const short __user *)buf;
handshake(count, dsp56k.maxio, dsp56k.timeout, DSP56K_TRANSMIT,
get_user(dsp56k_host_interface.data.w[1], data+n++));
return 2*n;
}
case 3:
{
count /= 3;
handshake(count, dsp56k.maxio, dsp56k.timeout, DSP56K_TRANSMIT,
get_user(dsp56k_host_interface.data.b[1], buf+n++);
get_user(dsp56k_host_interface.data.b[2], buf+n++);
get_user(dsp56k_host_interface.data.b[3], buf+n++));
return 3*n;
}
case 4:
{
const long __user *data;
count /= 4;
data = (const long __user *)buf;
handshake(count, dsp56k.maxio, dsp56k.timeout, DSP56K_TRANSMIT,
get_user(dsp56k_host_interface.data.l, data+n++));
return 4*n;
}
}
return -EFAULT;
}
default:
printk(KERN_ERR "DSP56k driver: Unknown minor device: %d\n", dev);
return -ENXIO;
}
}
static long dsp56k_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int dev = iminor(file_inode(file)) & 0x0f;
void __user *argp = (void __user *)arg;
switch(dev)
{
case DSP56K_DEV_56001:
switch(cmd) {
case DSP56K_UPLOAD:
{
char __user *bin;
int r, len;
struct dsp56k_upload __user *binary = argp;
if(get_user(len, &binary->len) < 0)
return -EFAULT;
if(get_user(bin, &binary->bin) < 0)
return -EFAULT;
if (len <= 0) {
return -EINVAL;
}
if (len > DSP56K_MAX_BINARY_LENGTH) {
return -EINVAL;
}
mutex_lock(&dsp56k_mutex);
r = dsp56k_upload(bin, len);
mutex_unlock(&dsp56k_mutex);
if (r < 0) {
return r;
}
break;
}
case DSP56K_SET_TX_WSIZE:
if (arg > 4 || arg < 1)
return -EINVAL;
mutex_lock(&dsp56k_mutex);
dsp56k.tx_wsize = (int) arg;
mutex_unlock(&dsp56k_mutex);
break;
case DSP56K_SET_RX_WSIZE:
if (arg > 4 || arg < 1)
return -EINVAL;
mutex_lock(&dsp56k_mutex);
dsp56k.rx_wsize = (int) arg;
mutex_unlock(&dsp56k_mutex);
break;
case DSP56K_HOST_FLAGS:
{
int dir, out, status;
struct dsp56k_host_flags __user *hf = argp;
if(get_user(dir, &hf->dir) < 0)
return -EFAULT;
if(get_user(out, &hf->out) < 0)
return -EFAULT;
mutex_lock(&dsp56k_mutex);
if ((dir & 0x1) && (out & 0x1))
dsp56k_host_interface.icr |= DSP56K_ICR_HF0;
else if (dir & 0x1)
dsp56k_host_interface.icr &= ~DSP56K_ICR_HF0;
if ((dir & 0x2) && (out & 0x2))
dsp56k_host_interface.icr |= DSP56K_ICR_HF1;
else if (dir & 0x2)
dsp56k_host_interface.icr &= ~DSP56K_ICR_HF1;
status = 0;
if (dsp56k_host_interface.icr & DSP56K_ICR_HF0) status |= 0x1;
if (dsp56k_host_interface.icr & DSP56K_ICR_HF1) status |= 0x2;
if (dsp56k_host_interface.isr & DSP56K_ISR_HF2) status |= 0x4;
if (dsp56k_host_interface.isr & DSP56K_ISR_HF3) status |= 0x8;
mutex_unlock(&dsp56k_mutex);
return put_user(status, &hf->status);
}
case DSP56K_HOST_CMD:
if (arg > 31)
return -EINVAL;
mutex_lock(&dsp56k_mutex);
dsp56k_host_interface.cvr = (u_char)((arg & DSP56K_CVR_HV_MASK) |
DSP56K_CVR_HC);
mutex_unlock(&dsp56k_mutex);
break;
default:
return -EINVAL;
}
return 0;
default:
printk(KERN_ERR "DSP56k driver: Unknown minor device: %d\n", dev);
return -ENXIO;
}
}
static int dsp56k_open(struct inode *inode, struct file *file)
{
int dev = iminor(inode) & 0x0f;
int ret = 0;
mutex_lock(&dsp56k_mutex);
switch(dev)
{
case DSP56K_DEV_56001:
if (test_and_set_bit(0, &dsp56k.in_use)) {
ret = -EBUSY;
goto out;
}
dsp56k.timeout = TIMEOUT;
dsp56k.maxio = MAXIO;
dsp56k.rx_wsize = dsp56k.tx_wsize = 4;
DSP56K_TX_INT_OFF;
DSP56K_RX_INT_OFF;
dsp56k_host_interface.icr &= ~DSP56K_ICR_HF0;
dsp56k_host_interface.icr &= ~DSP56K_ICR_HF1;
break;
default:
ret = -ENODEV;
}
out:
mutex_unlock(&dsp56k_mutex);
return ret;
}
static int dsp56k_release(struct inode *inode, struct file *file)
{
int dev = iminor(inode) & 0x0f;
switch(dev)
{
case DSP56K_DEV_56001:
clear_bit(0, &dsp56k.in_use);
break;
default:
printk(KERN_ERR "DSP56k driver: Unknown minor device: %d\n", dev);
return -ENXIO;
}
return 0;
}
static int __init dsp56k_init_driver(void)
{
int err = 0;
if(!MACH_IS_ATARI || !ATARIHW_PRESENT(DSP56K)) {
printk("DSP56k driver: Hardware not present\n");
return -ENODEV;
}
if(register_chrdev(DSP56K_MAJOR, "dsp56k", &dsp56k_fops)) {
printk("DSP56k driver: Unable to register driver\n");
return -ENODEV;
}
dsp56k_class = class_create(THIS_MODULE, "dsp56k");
if (IS_ERR(dsp56k_class)) {
err = PTR_ERR(dsp56k_class);
goto out_chrdev;
}
device_create(dsp56k_class, NULL, MKDEV(DSP56K_MAJOR, 0), NULL,
"dsp56k");
printk(banner);
goto out;
out_chrdev:
unregister_chrdev(DSP56K_MAJOR, "dsp56k");
out:
return err;
}
static void __exit dsp56k_cleanup_driver(void)
{
device_destroy(dsp56k_class, MKDEV(DSP56K_MAJOR, 0));
class_destroy(dsp56k_class);
unregister_chrdev(DSP56K_MAJOR, "dsp56k");
}
