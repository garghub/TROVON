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
static ssize_t state_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf, loff_t off,
size_t count)
{
dev_dbg(&kobj_to_w1_slave(kobj)->dev,
"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj), W1_F29_REG_LOGIG_STATE, buf);
}
static ssize_t output_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
dev_dbg(&kobj_to_w1_slave(kobj)->dev,
"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj),
W1_F29_REG_OUTPUT_LATCH_STATE, buf);
}
static ssize_t activity_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
dev_dbg(&kobj_to_w1_slave(kobj)->dev,
"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj),
W1_F29_REG_ACTIVITY_LATCH_STATE, buf);
}
static ssize_t cond_search_mask_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
dev_dbg(&kobj_to_w1_slave(kobj)->dev,
"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj),
W1_F29_REG_COND_SEARCH_SELECT_MASK, buf);
}
static ssize_t cond_search_polarity_read(struct file *filp,
struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj),
W1_F29_REG_COND_SEARCH_POL_SELECT, buf);
}
static ssize_t status_control_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
if (count != 1 || off != 0)
return -EFAULT;
return _read_reg(kobj_to_w1_slave(kobj),
W1_F29_REG_CONTROL_AND_STATUS, buf);
}
static ssize_t output_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
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
if (readBack != W1_F29_SUCCESS_CONFIRM_BYTE) {
if (w1_reset_resume_command(sl->master))
goto error;
continue;
}
#ifdef CONFIG_W1_SLAVE_DS2408_READBACK
if (w1_reset_resume_command(sl->master))
goto error;
w1_buf[0] = W1_F29_FUNC_READ_PIO_REGS;
w1_buf[1] = W1_F29_REG_OUTPUT_LATCH_STATE;
w1_buf[2] = 0;
w1_write_block(sl->master, w1_buf, 3);
if (w1_read_8(sl->master) == *buf)
#endif
{
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
static ssize_t activity_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
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
static ssize_t status_control_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
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
static int w1_f29_disable_test_mode(struct w1_slave *sl)
{
int res;
u8 magic[10] = {0x96, };
u64 rn = le64_to_cpu(*((u64*)&sl->reg_num));
memcpy(&magic[1], &rn, 8);
magic[9] = 0x3C;
mutex_lock(&sl->master->bus_mutex);
res = w1_reset_bus(sl->master);
if (res)
goto out;
w1_write_block(sl->master, magic, ARRAY_SIZE(magic));
res = w1_reset_bus(sl->master);
out:
mutex_unlock(&sl->master->bus_mutex);
return res;
}
static int __init w1_f29_init(void)
{
return w1_register_family(&w1_family_29);
}
static void __exit w1_f29_exit(void)
{
w1_unregister_family(&w1_family_29);
}
