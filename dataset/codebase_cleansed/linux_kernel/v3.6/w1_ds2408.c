static int _read_reg(struct w1_slave *sl, u8 address, unsigned char* buf)
{
u8 wrbuf[3];
dev_dbg(&sl->dev,
"Reading with slave: %p, reg addr: %0#4x, buff addr: %p",
sl, (unsigned int)address, buf);
if (!buf)
return -EINVAL;
mutex_lock(&sl->master->bus_mutex);
dev_dbg(&sl->dev, "mutex locked");
if (w1_reset_select_slave(sl)) {
mutex_unlock(&sl->master->bus_mutex);
return -EIO;
}
wrbuf[0] = W1_F29_FUNC_READ_PIO_REGS;
wrbuf[1] = address;
wrbuf[2] = 0;
w1_write_block(sl->master, wrbuf, 3);
*buf = w1_read_8(sl->master);
mutex_unlock(&sl->master->bus_mutex);
dev_dbg(&sl->dev, "mutex unlocked");
return 1;
}
static ssize_t w1_f29_read_state(
struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
dev_dbg(&kobj_to_w1_slave(kobj)->dev,
"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj), W1_F29_REG_LOGIG_STATE, buf);
}
static ssize_t w1_f29_read_output(
struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
dev_dbg(&kobj_to_w1_slave(kobj)->dev,
"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj),
W1_F29_REG_OUTPUT_LATCH_STATE, buf);
}
static ssize_t w1_f29_read_activity(
struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
dev_dbg(&kobj_to_w1_slave(kobj)->dev,
"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj),
W1_F29_REG_ACTIVITY_LATCH_STATE, buf);
}
static ssize_t w1_f29_read_cond_search_mask(
struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
dev_dbg(&kobj_to_w1_slave(kobj)->dev,
"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj),
W1_F29_REG_COND_SEARCH_SELECT_MASK, buf);
}
static ssize_t w1_f29_read_cond_search_polarity(
struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj),
W1_F29_REG_COND_SEARCH_POL_SELECT, buf);
}
static ssize_t w1_f29_read_status_control(
struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj),
W1_F29_REG_CONTROL_AND_STATUS, buf);
}
static ssize_t w1_f29_write_output(
struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
u8 w1_buf[3];
u8 readBack;
unsigned int retries = W1_F29_RETRIES;
if (count != 1 || off != 0)
return -EFAULT;
dev_dbg(&sl->dev, "locking mutex for write_output");
mutex_lock(&sl->master->bus_mutex);
dev_dbg(&sl->dev, "mutex locked");
if (w1_reset_select_slave(sl))
goto error;
while (retries--) {
w1_buf[0] = W1_F29_FUNC_CHANN_ACCESS_WRITE;
w1_buf[1] = *buf;
w1_buf[2] = ~(*buf);
w1_write_block(sl->master, w1_buf, 3);
readBack = w1_read_8(sl->master);
if (w1_reset_resume_command(sl->master))
goto error;
if (readBack != 0xAA) {
continue;
}
w1_buf[0] = W1_F29_FUNC_READ_PIO_REGS;
w1_buf[1] = W1_F29_REG_OUTPUT_LATCH_STATE;
w1_buf[2] = 0;
w1_write_block(sl->master, w1_buf, 3);
if (w1_read_8(sl->master) == *buf) {
mutex_unlock(&sl->master->bus_mutex);
dev_dbg(&sl->dev,
"mutex unlocked, retries:%d", retries);
return 1;
}
}
error:
mutex_unlock(&sl->master->bus_mutex);
dev_dbg(&sl->dev, "mutex unlocked in error, retries:%d", retries);
return -EIO;
}
static ssize_t w1_f29_write_activity(
struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
unsigned int retries = W1_F29_RETRIES;
if (count != 1 || off != 0)
return -EFAULT;
mutex_lock(&sl->master->bus_mutex);
if (w1_reset_select_slave(sl))
goto error;
while (retries--) {
w1_write_8(sl->master, W1_F29_FUNC_RESET_ACTIVITY_LATCHES);
if (w1_read_8(sl->master) == W1_F29_SUCCESS_CONFIRM_BYTE) {
mutex_unlock(&sl->master->bus_mutex);
return 1;
}
if (w1_reset_resume_command(sl->master))
goto error;
}
error:
mutex_unlock(&sl->master->bus_mutex);
return -EIO;
}
static ssize_t w1_f29_write_status_control(
struct file *filp,
struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf,
loff_t off,
size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
u8 w1_buf[4];
unsigned int retries = W1_F29_RETRIES;
if (count != 1 || off != 0)
return -EFAULT;
mutex_lock(&sl->master->bus_mutex);
if (w1_reset_select_slave(sl))
goto error;
while (retries--) {
w1_buf[0] = W1_F29_FUNC_WRITE_COND_SEARCH_REG;
w1_buf[1] = W1_F29_REG_CONTROL_AND_STATUS;
w1_buf[2] = 0;
w1_buf[3] = *buf;
w1_write_block(sl->master, w1_buf, 4);
if (w1_reset_resume_command(sl->master))
goto error;
w1_buf[0] = W1_F29_FUNC_READ_PIO_REGS;
w1_buf[1] = W1_F29_REG_CONTROL_AND_STATUS;
w1_buf[2] = 0;
w1_write_block(sl->master, w1_buf, 3);
if (w1_read_8(sl->master) == *buf) {
mutex_unlock(&sl->master->bus_mutex);
return 1;
}
}
error:
mutex_unlock(&sl->master->bus_mutex);
return -EIO;
}
static int w1_f29_add_slave(struct w1_slave *sl)
{
int err = 0;
int i;
for (i = 0; i < NB_SYSFS_BIN_FILES && !err; ++i)
err = sysfs_create_bin_file(
&sl->dev.kobj,
&(w1_f29_sysfs_bin_files[i]));
if (err)
while (--i >= 0)
sysfs_remove_bin_file(&sl->dev.kobj,
&(w1_f29_sysfs_bin_files[i]));
return err;
}
static void w1_f29_remove_slave(struct w1_slave *sl)
{
int i;
for (i = NB_SYSFS_BIN_FILES - 1; i >= 0; --i)
sysfs_remove_bin_file(&sl->dev.kobj,
&(w1_f29_sysfs_bin_files[i]));
}
static int __init w1_f29_init(void)
{
return w1_register_family(&w1_family_29);
}
static void __exit w1_f29_exit(void)
{
w1_unregister_family(&w1_family_29);
}
