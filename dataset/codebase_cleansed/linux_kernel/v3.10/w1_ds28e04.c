static inline size_t w1_f1C_fix_count(loff_t off, size_t count, size_t size)
{
if (off > size)
return 0;
if ((off + count) > size)
return size - off;
return count;
}
static int w1_f1C_refresh_block(struct w1_slave *sl, struct w1_f1C_data *data,
int block)
{
u8 wrbuf[3];
int off = block * W1_PAGE_SIZE;
if (data->validcrc & (1 << block))
return 0;
if (w1_reset_select_slave(sl)) {
data->validcrc = 0;
return -EIO;
}
wrbuf[0] = W1_F1C_READ_EEPROM;
wrbuf[1] = off & 0xff;
wrbuf[2] = off >> 8;
w1_write_block(sl->master, wrbuf, 3);
w1_read_block(sl->master, &data->memory[off], W1_PAGE_SIZE);
if (crc16(CRC16_INIT, &data->memory[off], W1_PAGE_SIZE) == CRC16_VALID)
data->validcrc |= (1 << block);
return 0;
}
static int w1_f1C_read(struct w1_slave *sl, int addr, int len, char *data)
{
u8 wrbuf[3];
if (w1_reset_select_slave(sl))
return -EIO;
wrbuf[0] = W1_F1C_READ_EEPROM;
wrbuf[1] = addr & 0xff;
wrbuf[2] = addr >> 8;
w1_write_block(sl->master, wrbuf, sizeof(wrbuf));
return w1_read_block(sl->master, data, len);
}
static ssize_t w1_f1C_read_bin(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
struct w1_f1C_data *data = sl->family_data;
int i, min_page, max_page;
count = w1_f1C_fix_count(off, count, W1_EEPROM_SIZE);
if (count == 0)
return 0;
mutex_lock(&sl->master->mutex);
if (w1_enable_crccheck) {
min_page = (off >> W1_PAGE_BITS);
max_page = (off + count - 1) >> W1_PAGE_BITS;
for (i = min_page; i <= max_page; i++) {
if (w1_f1C_refresh_block(sl, data, i)) {
count = -EIO;
goto out_up;
}
}
memcpy(buf, &data->memory[off], count);
} else {
count = w1_f1C_read(sl, off, count, buf);
}
out_up:
mutex_unlock(&sl->master->mutex);
return count;
}
static int w1_f1C_write(struct w1_slave *sl, int addr, int len, const u8 *data)
{
u8 wrbuf[4];
u8 rdbuf[W1_PAGE_SIZE + 3];
u8 es = (addr + len - 1) & 0x1f;
unsigned int tm = 10;
int i;
struct w1_f1C_data *f1C = sl->family_data;
if (w1_reset_select_slave(sl))
return -1;
wrbuf[0] = W1_F1C_WRITE_SCRATCH;
wrbuf[1] = addr & 0xff;
wrbuf[2] = addr >> 8;
w1_write_block(sl->master, wrbuf, 3);
w1_write_block(sl->master, data, len);
if (w1_reset_select_slave(sl))
return -1;
w1_write_8(sl->master, W1_F1C_READ_SCRATCH);
w1_read_block(sl->master, rdbuf, len + 3);
if ((rdbuf[0] != wrbuf[1]) || (rdbuf[1] != wrbuf[2]) ||
(rdbuf[2] != es) || (memcmp(data, &rdbuf[3], len) != 0))
return -1;
if (w1_reset_select_slave(sl))
return -1;
wrbuf[0] = W1_F1C_COPY_SCRATCH;
wrbuf[3] = es;
for (i = 0; i < sizeof(wrbuf); ++i) {
if (w1_strong_pullup && i == sizeof(wrbuf)-1)
w1_next_pullup(sl->master, tm);
w1_write_8(sl->master, wrbuf[i]);
}
if (!w1_strong_pullup)
msleep(tm);
if (w1_enable_crccheck) {
f1C->validcrc &= ~(1 << (addr >> W1_PAGE_BITS));
}
w1_reset_bus(sl->master);
return 0;
}
static ssize_t w1_f1C_write_bin(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int addr, len, idx;
count = w1_f1C_fix_count(off, count, W1_EEPROM_SIZE);
if (count == 0)
return 0;
if (w1_enable_crccheck) {
if ((off & W1_PAGE_MASK) || (count & W1_PAGE_MASK)) {
dev_err(&sl->dev, "invalid offset/count off=%d cnt=%zd\n",
(int)off, count);
return -EINVAL;
}
for (idx = 0; idx < count; idx += W1_PAGE_SIZE) {
if (crc16(CRC16_INIT, &buf[idx], W1_PAGE_SIZE)
!= CRC16_VALID) {
dev_err(&sl->dev, "bad CRC at offset %d\n",
(int)off);
return -EINVAL;
}
}
}
mutex_lock(&sl->master->mutex);
idx = 0;
while (idx < count) {
addr = off + idx;
len = W1_PAGE_SIZE - (addr & W1_PAGE_MASK);
if (len > (count - idx))
len = count - idx;
if (w1_f1C_write(sl, addr, len, &buf[idx]) < 0) {
count = -EIO;
goto out_up;
}
idx += len;
}
out_up:
mutex_unlock(&sl->master->mutex);
return count;
}
static ssize_t w1_f1C_read_pio(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int ret;
if (off != 0 || count != 1 || buf == NULL)
return -EINVAL;
mutex_lock(&sl->master->mutex);
ret = w1_f1C_read(sl, W1_1C_REG_LOGIC_STATE, count, buf);
mutex_unlock(&sl->master->mutex);
return ret;
}
static ssize_t w1_f1C_write_pio(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
u8 wrbuf[3];
u8 ack;
if (off != 0 || count != 1 || buf == NULL)
return -EINVAL;
mutex_lock(&sl->master->mutex);
if (w1_reset_select_slave(sl)) {
mutex_unlock(&sl->master->mutex);
return -1;
}
*buf = *buf | 0xFC;
wrbuf[0] = W1_F1C_ACCESS_WRITE;
wrbuf[1] = *buf;
wrbuf[2] = ~(*buf);
w1_write_block(sl->master, wrbuf, 3);
w1_read_block(sl->master, &ack, sizeof(ack));
mutex_unlock(&sl->master->mutex);
if (ack != 0xAA)
return -EIO;
return count;
}
static ssize_t w1_f1C_show_crccheck(struct device *dev,
struct device_attribute *attr, char *buf)
{
if (put_user(w1_enable_crccheck + 0x30, buf))
return -EFAULT;
return sizeof(w1_enable_crccheck);
}
static ssize_t w1_f1C_store_crccheck(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
char val;
if (count != 1 || !buf)
return -EINVAL;
if (get_user(val, buf))
return -EFAULT;
val = val - 0x30;
if (val != 0 && val != 1)
return -EINVAL;
w1_enable_crccheck = val;
return sizeof(w1_enable_crccheck);
}
static int w1_f1C_add_slave(struct w1_slave *sl)
{
int err = 0;
int i;
struct w1_f1C_data *data = NULL;
if (w1_enable_crccheck) {
data = kzalloc(sizeof(struct w1_f1C_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
sl->family_data = data;
}
for (i = 0; i < NB_SYSFS_BIN_FILES && !err; ++i)
err = sysfs_create_bin_file(
&sl->dev.kobj, &(w1_f1C_bin_attr[i]));
if (!err) {
err = device_create_file(&sl->dev, &dev_attr_crccheck);
}
if (err) {
for (i = 0; i < NB_SYSFS_BIN_FILES; ++i)
sysfs_remove_bin_file(
&sl->dev.kobj, &(w1_f1C_bin_attr[i]));
kfree(data);
}
return err;
}
static void w1_f1C_remove_slave(struct w1_slave *sl)
{
int i;
kfree(sl->family_data);
sl->family_data = NULL;
device_remove_file(&sl->dev, &dev_attr_crccheck);
for (i = 0; i < NB_SYSFS_BIN_FILES; ++i)
sysfs_remove_bin_file(&sl->dev.kobj, &(w1_f1C_bin_attr[i]));
}
static int __init w1_f1C_init(void)
{
return w1_register_family(&w1_family_1C);
}
static void __exit w1_f1C_fini(void)
{
w1_unregister_family(&w1_family_1C);
}
