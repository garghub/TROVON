static ssize_t w1_f3a_read_state(
struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
dev_dbg(&sl->dev,
"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
if (off != 0)
return 0;
if (!buf)
return -EINVAL;
mutex_lock(&sl->master->bus_mutex);
dev_dbg(&sl->dev, "mutex locked");
if (w1_reset_select_slave(sl)) {
mutex_unlock(&sl->master->bus_mutex);
return -EIO;
}
w1_write_8(sl->master, W1_F3A_FUNC_PIO_ACCESS_READ);
*buf = w1_read_8(sl->master);
mutex_unlock(&sl->master->bus_mutex);
dev_dbg(&sl->dev, "mutex unlocked");
if ((*buf & 0x0F) != ((~*buf >> 4) & 0x0F))
return -EIO;
else
return 1;
}
static ssize_t w1_f3a_write_output(
struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
u8 w1_buf[3];
unsigned int retries = W1_F3A_RETRIES;
if (count != 1 || off != 0)
return -EFAULT;
dev_dbg(&sl->dev, "locking mutex for write_output");
mutex_lock(&sl->master->bus_mutex);
dev_dbg(&sl->dev, "mutex locked");
if (w1_reset_select_slave(sl))
goto error;
*buf = *buf | 0xFC;
while (retries--) {
w1_buf[0] = W1_F3A_FUNC_PIO_ACCESS_WRITE;
w1_buf[1] = *buf;
w1_buf[2] = ~(*buf);
w1_write_block(sl->master, w1_buf, 3);
if (w1_read_8(sl->master) == W1_F3A_SUCCESS_CONFIRM_BYTE) {
mutex_unlock(&sl->master->bus_mutex);
dev_dbg(&sl->dev, "mutex unlocked, retries:%d", retries);
return 1;
}
if (w1_reset_resume_command(sl->master))
goto error;
}
error:
mutex_unlock(&sl->master->bus_mutex);
dev_dbg(&sl->dev, "mutex unlocked in error, retries:%d", retries);
return -EIO;
}
static int w1_f3a_add_slave(struct w1_slave *sl)
{
int err = 0;
int i;
for (i = 0; i < NB_SYSFS_BIN_FILES && !err; ++i)
err = sysfs_create_bin_file(
&sl->dev.kobj,
&(w1_f3a_sysfs_bin_files[i]));
if (err)
while (--i >= 0)
sysfs_remove_bin_file(&sl->dev.kobj,
&(w1_f3a_sysfs_bin_files[i]));
return err;
}
static void w1_f3a_remove_slave(struct w1_slave *sl)
{
int i;
for (i = NB_SYSFS_BIN_FILES - 1; i >= 0; --i)
sysfs_remove_bin_file(&sl->dev.kobj,
&(w1_f3a_sysfs_bin_files[i]));
}
static int __init w1_f3a_init(void)
{
return w1_register_family(&w1_family_3a);
}
static void __exit w1_f3a_exit(void)
{
w1_unregister_family(&w1_family_3a);
}
