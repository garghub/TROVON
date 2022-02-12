static inline size_t w1_f2d_fix_count(loff_t off, size_t count, size_t size)
{
if (off > size)
return 0;
if ((off + count) > size)
return size - off;
return count;
}
static int w1_f2d_readblock(struct w1_slave *sl, int off, int count, char *buf)
{
u8 wrbuf[3];
u8 cmp[W1_F2D_READ_MAXLEN];
int tries = W1_F2D_READ_RETRIES;
do {
wrbuf[0] = W1_F2D_READ_EEPROM;
wrbuf[1] = off & 0xff;
wrbuf[2] = off >> 8;
if (w1_reset_select_slave(sl))
return -1;
w1_write_block(sl->master, wrbuf, 3);
w1_read_block(sl->master, buf, count);
if (w1_reset_select_slave(sl))
return -1;
w1_write_block(sl->master, wrbuf, 3);
w1_read_block(sl->master, cmp, count);
if (!memcmp(cmp, buf, count))
return 0;
} while (--tries);
dev_err(&sl->dev, "proof reading failed %d times\n",
W1_F2D_READ_RETRIES);
return -1;
}
static ssize_t eeprom_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int todo = count;
count = w1_f2d_fix_count(off, count, W1_F2D_EEPROM_SIZE);
if (count == 0)
return 0;
mutex_lock(&sl->master->bus_mutex);
while (todo > 0) {
int block_read;
if (todo >= W1_F2D_READ_MAXLEN)
block_read = W1_F2D_READ_MAXLEN;
else
block_read = todo;
if (w1_f2d_readblock(sl, off, block_read, buf) < 0)
count = -EIO;
todo -= W1_F2D_READ_MAXLEN;
buf += W1_F2D_READ_MAXLEN;
off += W1_F2D_READ_MAXLEN;
}
mutex_unlock(&sl->master->bus_mutex);
return count;
}
static int w1_f2d_write(struct w1_slave *sl, int addr, int len, const u8 *data)
{
int tries = W1_F2D_READ_RETRIES;
u8 wrbuf[4];
u8 rdbuf[W1_F2D_SCRATCH_SIZE + 3];
u8 es = (addr + len - 1) % W1_F2D_SCRATCH_SIZE;
retry:
if (w1_reset_select_slave(sl))
return -1;
wrbuf[0] = W1_F2D_WRITE_SCRATCH;
wrbuf[1] = addr & 0xff;
wrbuf[2] = addr >> 8;
w1_write_block(sl->master, wrbuf, 3);
w1_write_block(sl->master, data, len);
if (w1_reset_select_slave(sl))
return -1;
w1_write_8(sl->master, W1_F2D_READ_SCRATCH);
w1_read_block(sl->master, rdbuf, len + 3);
if ((rdbuf[0] != wrbuf[1]) || (rdbuf[1] != wrbuf[2]) ||
(rdbuf[2] != es) || (memcmp(data, &rdbuf[3], len) != 0)) {
if (--tries)
goto retry;
dev_err(&sl->dev,
"could not write to eeprom, scratchpad compare failed %d times\n",
W1_F2D_READ_RETRIES);
return -1;
}
if (w1_reset_select_slave(sl))
return -1;
wrbuf[0] = W1_F2D_COPY_SCRATCH;
wrbuf[3] = es;
w1_write_block(sl->master, wrbuf, 4);
msleep(W1_F2D_TPROG_MS);
w1_reset_bus(sl->master);
return 0;
}
static ssize_t eeprom_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int addr, len;
int copy;
count = w1_f2d_fix_count(off, count, W1_F2D_EEPROM_SIZE);
if (count == 0)
return 0;
mutex_lock(&sl->master->bus_mutex);
addr = off;
len = count;
while (len > 0) {
if (len < W1_F2D_SCRATCH_SIZE || addr & W1_F2D_SCRATCH_MASK) {
char tmp[W1_F2D_SCRATCH_SIZE];
if (w1_f2d_readblock(sl, addr & ~W1_F2D_SCRATCH_MASK,
W1_F2D_SCRATCH_SIZE, tmp)) {
count = -EIO;
goto out_up;
}
copy = W1_F2D_SCRATCH_SIZE -
(addr & W1_F2D_SCRATCH_MASK);
if (copy > len)
copy = len;
memcpy(&tmp[addr & W1_F2D_SCRATCH_MASK], buf, copy);
if (w1_f2d_write(sl, addr & ~W1_F2D_SCRATCH_MASK,
W1_F2D_SCRATCH_SIZE, tmp) < 0) {
count = -EIO;
goto out_up;
}
} else {
copy = W1_F2D_SCRATCH_SIZE;
if (w1_f2d_write(sl, addr, copy, buf) < 0) {
count = -EIO;
goto out_up;
}
}
buf += copy;
addr += copy;
len -= copy;
}
out_up:
mutex_unlock(&sl->master->bus_mutex);
return count;
}
static int __init w1_f2d_init(void)
{
return w1_register_family(&w1_family_2d);
}
static void __exit w1_f2d_fini(void)
{
w1_unregister_family(&w1_family_2d);
}
