static inline size_t w1_f23_fix_count(loff_t off, size_t count, size_t size)
{
if (off > size)
return 0;
if ((off + count) > size)
return (size - off);
return count;
}
static int w1_f23_refresh_block(struct w1_slave *sl, struct w1_f23_data *data,
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
wrbuf[0] = W1_F23_READ_EEPROM;
wrbuf[1] = off & 0xff;
wrbuf[2] = off >> 8;
w1_write_block(sl->master, wrbuf, 3);
w1_read_block(sl->master, &data->memory[off], W1_PAGE_SIZE);
if (crc16(CRC16_INIT, &data->memory[off], W1_PAGE_SIZE) == CRC16_VALID)
data->validcrc |= (1 << block);
return 0;
}
static ssize_t w1_f23_read_bin(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
#ifdef CONFIG_W1_SLAVE_DS2433_CRC
struct w1_f23_data *data = sl->family_data;
int i, min_page, max_page;
#else
u8 wrbuf[3];
#endif
if ((count = w1_f23_fix_count(off, count, W1_EEPROM_SIZE)) == 0)
return 0;
mutex_lock(&sl->master->bus_mutex);
#ifdef CONFIG_W1_SLAVE_DS2433_CRC
min_page = (off >> W1_PAGE_BITS);
max_page = (off + count - 1) >> W1_PAGE_BITS;
for (i = min_page; i <= max_page; i++) {
if (w1_f23_refresh_block(sl, data, i)) {
count = -EIO;
goto out_up;
}
}
memcpy(buf, &data->memory[off], count);
#else
if (w1_reset_select_slave(sl)) {
count = -EIO;
goto out_up;
}
wrbuf[0] = W1_F23_READ_EEPROM;
wrbuf[1] = off & 0xff;
wrbuf[2] = off >> 8;
w1_write_block(sl->master, wrbuf, 3);
w1_read_block(sl->master, buf, count);
#endif
out_up:
mutex_unlock(&sl->master->bus_mutex);
return count;
}
static int w1_f23_write(struct w1_slave *sl, int addr, int len, const u8 *data)
{
#ifdef CONFIG_W1_SLAVE_DS2433_CRC
struct w1_f23_data *f23 = sl->family_data;
#endif
u8 wrbuf[4];
u8 rdbuf[W1_PAGE_SIZE + 3];
u8 es = (addr + len - 1) & 0x1f;
if (w1_reset_select_slave(sl))
return -1;
wrbuf[0] = W1_F23_WRITE_SCRATCH;
wrbuf[1] = addr & 0xff;
wrbuf[2] = addr >> 8;
w1_write_block(sl->master, wrbuf, 3);
w1_write_block(sl->master, data, len);
if (w1_reset_select_slave(sl))
return -1;
w1_write_8(sl->master, W1_F23_READ_SCRATCH);
w1_read_block(sl->master, rdbuf, len + 3);
if ((rdbuf[0] != wrbuf[1]) || (rdbuf[1] != wrbuf[2]) ||
(rdbuf[2] != es) || (memcmp(data, &rdbuf[3], len) != 0))
return -1;
if (w1_reset_select_slave(sl))
return -1;
wrbuf[0] = W1_F23_COPY_SCRATCH;
wrbuf[3] = es;
w1_write_block(sl->master, wrbuf, 4);
msleep(5);
w1_reset_bus(sl->master);
#ifdef CONFIG_W1_SLAVE_DS2433_CRC
f23->validcrc &= ~(1 << (addr >> W1_PAGE_BITS));
#endif
return 0;
}
static ssize_t w1_f23_write_bin(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int addr, len, idx;
if ((count = w1_f23_fix_count(off, count, W1_EEPROM_SIZE)) == 0)
return 0;
#ifdef CONFIG_W1_SLAVE_DS2433_CRC
if ((off & W1_PAGE_MASK) || (count & W1_PAGE_MASK)) {
dev_err(&sl->dev, "invalid offset/count off=%d cnt=%zd\n",
(int)off, count);
return -EINVAL;
}
for (idx = 0; idx < count; idx += W1_PAGE_SIZE) {
if (crc16(CRC16_INIT, &buf[idx], W1_PAGE_SIZE) != CRC16_VALID) {
dev_err(&sl->dev, "bad CRC at offset %d\n", (int)off);
return -EINVAL;
}
}
#endif
mutex_lock(&sl->master->bus_mutex);
idx = 0;
while (idx < count) {
addr = off + idx;
len = W1_PAGE_SIZE - (addr & W1_PAGE_MASK);
if (len > (count - idx))
len = count - idx;
if (w1_f23_write(sl, addr, len, &buf[idx]) < 0) {
count = -EIO;
goto out_up;
}
idx += len;
}
out_up:
mutex_unlock(&sl->master->bus_mutex);
return count;
}
static int w1_f23_add_slave(struct w1_slave *sl)
{
int err;
#ifdef CONFIG_W1_SLAVE_DS2433_CRC
struct w1_f23_data *data;
data = kzalloc(sizeof(struct w1_f23_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
sl->family_data = data;
#endif
err = sysfs_create_bin_file(&sl->dev.kobj, &w1_f23_bin_attr);
#ifdef CONFIG_W1_SLAVE_DS2433_CRC
if (err)
kfree(data);
#endif
return err;
}
static void w1_f23_remove_slave(struct w1_slave *sl)
{
#ifdef CONFIG_W1_SLAVE_DS2433_CRC
kfree(sl->family_data);
sl->family_data = NULL;
#endif
sysfs_remove_bin_file(&sl->dev.kobj, &w1_f23_bin_attr);
}
static int __init w1_f23_init(void)
{
return w1_register_family(&w1_family_23);
}
static void __exit w1_f23_fini(void)
{
w1_unregister_family(&w1_family_23);
}
