static inline size_t w1_f0d_fix_count(loff_t off, size_t count, size_t size)
{
if (off > size)
return 0;
if ((off + count) > size)
return size - off;
return count;
}
static int w1_f0d_readblock(struct w1_slave *sl, int off, int count, char *buf)
{
u8 wrbuf[3];
u8 cmp[W1_F0D_READ_MAXLEN];
int tries = W1_F0D_READ_RETRIES;
do {
wrbuf[0] = W1_F0D_READ_EEPROM;
wrbuf[1] = off & 0x7f;
wrbuf[2] = 0;
if (w1_reset_select_slave(sl))
return -1;
w1_write_block(sl->master, wrbuf, sizeof(wrbuf));
w1_read_block(sl->master, buf, count);
if (w1_reset_select_slave(sl))
return -1;
w1_write_block(sl->master, wrbuf, sizeof(wrbuf));
w1_read_block(sl->master, cmp, count);
if (!memcmp(cmp, buf, count))
return 0;
} while (--tries);
dev_err(&sl->dev, "proof reading failed %d times\n",
W1_F0D_READ_RETRIES);
return -1;
}
static ssize_t w1_f0d_read_bin(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int todo = count;
count = w1_f0d_fix_count(off, count, W1_F0D_EEPROM_SIZE);
if (count == 0)
return 0;
mutex_lock(&sl->master->mutex);
while (todo > 0) {
int block_read;
if (todo >= W1_F0D_READ_MAXLEN)
block_read = W1_F0D_READ_MAXLEN;
else
block_read = todo;
if (w1_f0d_readblock(sl, off, block_read, buf) < 0) {
count = -EIO;
break;
}
todo -= W1_F0D_READ_MAXLEN;
buf += W1_F0D_READ_MAXLEN;
off += W1_F0D_READ_MAXLEN;
}
mutex_unlock(&sl->master->mutex);
return count;
}
static int w1_f0d_write(struct w1_slave *sl, int addr, int len, const u8 *data)
{
int tries = W1_F0D_READ_RETRIES;
u8 wrbuf[3];
u8 rdbuf[W1_F0D_SCRATCH_SIZE];
u8 cs;
if ((addr & 1) || (len != 2)) {
dev_err(&sl->dev, "%s: bad addr/len - addr=%#x len=%d\n",
__func__, addr, len);
return -1;
}
retry:
if (w1_reset_select_slave(sl))
return -1;
wrbuf[0] = W1_F0D_WRITE_EEPROM;
wrbuf[1] = addr & 0xff;
wrbuf[2] = 0xff;
w1_write_block(sl->master, wrbuf, sizeof(wrbuf));
w1_write_block(sl->master, data, len);
w1_read_block(sl->master, rdbuf, sizeof(rdbuf));
if ((rdbuf[0] != data[0]) || (rdbuf[1] != data[1])) {
if (--tries)
goto retry;
dev_err(&sl->dev,
"could not write to eeprom, scratchpad compare failed %d times\n",
W1_F0D_READ_RETRIES);
pr_info("%s: rdbuf = %#x %#x data = %#x %#x\n",
__func__, rdbuf[0], rdbuf[1], data[0], data[1]);
return -1;
}
w1_write_8(sl->master, W1_F0D_RELEASE);
msleep(W1_F0D_TPROG_MS);
cs = w1_read_8(sl->master);
if (cs != W1_F0D_CS_OK) {
dev_err(&sl->dev, "save to eeprom failed = CS=%#x\n", cs);
return -1;
}
return 0;
}
static ssize_t w1_f0d_write_bin(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int addr, len;
int copy;
count = w1_f0d_fix_count(off, count, W1_F0D_EEPROM_SIZE);
if (count == 0)
return 0;
mutex_lock(&sl->master->mutex);
addr = off;
len = count;
while (len > 0) {
if (len < W1_F0D_SCRATCH_SIZE || addr & W1_F0D_SCRATCH_MASK) {
char tmp[W1_F0D_SCRATCH_SIZE];
if (w1_f0d_readblock(sl, addr & ~W1_F0D_SCRATCH_MASK,
W1_F0D_SCRATCH_SIZE, tmp)) {
count = -EIO;
goto out_up;
}
copy = W1_F0D_SCRATCH_SIZE -
(addr & W1_F0D_SCRATCH_MASK);
if (copy > len)
copy = len;
memcpy(&tmp[addr & W1_F0D_SCRATCH_MASK], buf, copy);
if (w1_f0d_write(sl, addr & ~W1_F0D_SCRATCH_MASK,
W1_F0D_SCRATCH_SIZE, tmp) < 0) {
count = -EIO;
goto out_up;
}
} else {
copy = W1_F0D_SCRATCH_SIZE;
if (w1_f0d_write(sl, addr, copy, buf) < 0) {
count = -EIO;
goto out_up;
}
}
buf += copy;
addr += copy;
len -= copy;
}
out_up:
mutex_unlock(&sl->master->mutex);
return count;
}
static int w1_f0d_add_slave(struct w1_slave *sl)
{
return sysfs_create_bin_file(&sl->dev.kobj, &w1_f0d_bin_attr);
}
static void w1_f0d_remove_slave(struct w1_slave *sl)
{
sysfs_remove_bin_file(&sl->dev.kobj, &w1_f0d_bin_attr);
}
static int __init w1_f0d_init(void)
{
pr_info("%s()\n", __func__);
return w1_register_family(&w1_family_2d);
}
static void __exit w1_f0d_fini(void)
{
pr_info("%s()\n", __func__);
w1_unregister_family(&w1_family_2d);
}
