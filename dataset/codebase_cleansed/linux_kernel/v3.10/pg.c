static void pg_init_units(void)
{
int unit;
pg_drive_count = 0;
for (unit = 0; unit < PG_UNITS; unit++) {
int *parm = *drives[unit];
struct pg *dev = &devices[unit];
dev->pi = &dev->pia;
clear_bit(0, &dev->access);
dev->busy = 0;
dev->present = 0;
dev->bufptr = NULL;
dev->drive = parm[D_SLV];
snprintf(dev->name, PG_NAMELEN, "%s%c", name, 'a'+unit);
if (parm[D_PRT])
pg_drive_count++;
}
}
static inline int status_reg(struct pg *dev)
{
return pi_read_regr(dev->pi, 1, 6);
}
static inline int read_reg(struct pg *dev, int reg)
{
return pi_read_regr(dev->pi, 0, reg);
}
static inline void write_reg(struct pg *dev, int reg, int val)
{
pi_write_regr(dev->pi, 0, reg, val);
}
static inline u8 DRIVE(struct pg *dev)
{
return 0xa0+0x10*dev->drive;
}
static void pg_sleep(int cs)
{
schedule_timeout_interruptible(cs);
}
static int pg_wait(struct pg *dev, int go, int stop, unsigned long tmo, char *msg)
{
int j, r, e, s, p, to;
dev->status = 0;
j = 0;
while ((((r = status_reg(dev)) & go) || (stop && (!(r & stop))))
&& time_before(jiffies, tmo)) {
if (j++ < PG_SPIN)
udelay(PG_SPIN_DEL);
else
pg_sleep(1);
}
to = time_after_eq(jiffies, tmo);
if ((r & (STAT_ERR & stop)) || to) {
s = read_reg(dev, 7);
e = read_reg(dev, 1);
p = read_reg(dev, 2);
if (verbose > 1)
printk("%s: %s: stat=0x%x err=0x%x phase=%d%s\n",
dev->name, msg, s, e, p, to ? " timeout" : "");
if (to)
e |= 0x100;
dev->status = (e >> 4) & 0xff;
return -1;
}
return 0;
}
static int pg_command(struct pg *dev, char *cmd, int dlen, unsigned long tmo)
{
int k;
pi_connect(dev->pi);
write_reg(dev, 6, DRIVE(dev));
if (pg_wait(dev, STAT_BUSY | STAT_DRQ, 0, tmo, "before command"))
goto fail;
write_reg(dev, 4, dlen % 256);
write_reg(dev, 5, dlen / 256);
write_reg(dev, 7, 0xa0);
if (pg_wait(dev, STAT_BUSY, STAT_DRQ, tmo, "command DRQ"))
goto fail;
if (read_reg(dev, 2) != 1) {
printk("%s: command phase error\n", dev->name);
goto fail;
}
pi_write_block(dev->pi, cmd, 12);
if (verbose > 1) {
printk("%s: Command sent, dlen=%d packet= ", dev->name, dlen);
for (k = 0; k < 12; k++)
printk("%02x ", cmd[k] & 0xff);
printk("\n");
}
return 0;
fail:
pi_disconnect(dev->pi);
return -1;
}
static int pg_completion(struct pg *dev, char *buf, unsigned long tmo)
{
int r, d, n, p;
r = pg_wait(dev, STAT_BUSY, STAT_DRQ | STAT_READY | STAT_ERR,
tmo, "completion");
dev->dlen = 0;
while (read_reg(dev, 7) & STAT_DRQ) {
d = (read_reg(dev, 4) + 256 * read_reg(dev, 5));
n = ((d + 3) & 0xfffc);
p = read_reg(dev, 2) & 3;
if (p == 0)
pi_write_block(dev->pi, buf, n);
if (p == 2)
pi_read_block(dev->pi, buf, n);
if (verbose > 1)
printk("%s: %s %d bytes\n", dev->name,
p ? "Read" : "Write", n);
dev->dlen += (1 - p) * d;
buf += d;
r = pg_wait(dev, STAT_BUSY, STAT_DRQ | STAT_READY | STAT_ERR,
tmo, "completion");
}
pi_disconnect(dev->pi);
return r;
}
static int pg_reset(struct pg *dev)
{
int i, k, err;
int expect[5] = { 1, 1, 1, 0x14, 0xeb };
int got[5];
pi_connect(dev->pi);
write_reg(dev, 6, DRIVE(dev));
write_reg(dev, 7, 8);
pg_sleep(20 * HZ / 1000);
k = 0;
while ((k++ < PG_RESET_TMO) && (status_reg(dev) & STAT_BUSY))
pg_sleep(1);
for (i = 0; i < 5; i++)
got[i] = read_reg(dev, i + 1);
err = memcmp(expect, got, sizeof(got)) ? -1 : 0;
if (verbose) {
printk("%s: Reset (%d) signature = ", dev->name, k);
for (i = 0; i < 5; i++)
printk("%3x", got[i]);
if (err)
printk(" (incorrect)");
printk("\n");
}
pi_disconnect(dev->pi);
return err;
}
static void xs(char *buf, char *targ, int len)
{
char l = '\0';
int k;
for (k = 0; k < len; k++) {
char c = *buf++;
if (c != ' ' && c != l)
l = *targ++ = c;
}
if (l == ' ')
targ--;
*targ = '\0';
}
static int pg_identify(struct pg *dev, int log)
{
int s;
char *ms[2] = { "master", "slave" };
char mf[10], id[18];
char id_cmd[12] = { ATAPI_IDENTIFY, 0, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0 };
char buf[36];
s = pg_command(dev, id_cmd, 36, jiffies + PG_TMO);
if (s)
return -1;
s = pg_completion(dev, buf, jiffies + PG_TMO);
if (s)
return -1;
if (log) {
xs(buf + 8, mf, 8);
xs(buf + 16, id, 16);
printk("%s: %s %s, %s\n", dev->name, mf, id, ms[dev->drive]);
}
return 0;
}
static int pg_probe(struct pg *dev)
{
if (dev->drive == -1) {
for (dev->drive = 0; dev->drive <= 1; dev->drive++)
if (!pg_reset(dev))
return pg_identify(dev, 1);
} else {
if (!pg_reset(dev))
return pg_identify(dev, 1);
}
return -1;
}
static int pg_detect(void)
{
struct pg *dev = &devices[0];
int k, unit;
printk("%s: %s version %s, major %d\n", name, name, PG_VERSION, major);
k = 0;
if (pg_drive_count == 0) {
if (pi_init(dev->pi, 1, -1, -1, -1, -1, -1, pg_scratch,
PI_PG, verbose, dev->name)) {
if (!pg_probe(dev)) {
dev->present = 1;
k++;
} else
pi_release(dev->pi);
}
} else
for (unit = 0; unit < PG_UNITS; unit++, dev++) {
int *parm = *drives[unit];
if (!parm[D_PRT])
continue;
if (pi_init(dev->pi, 0, parm[D_PRT], parm[D_MOD],
parm[D_UNI], parm[D_PRO], parm[D_DLY],
pg_scratch, PI_PG, verbose, dev->name)) {
if (!pg_probe(dev)) {
dev->present = 1;
k++;
} else
pi_release(dev->pi);
}
}
if (k)
return 0;
printk("%s: No ATAPI device detected\n", name);
return -1;
}
static int pg_open(struct inode *inode, struct file *file)
{
int unit = iminor(inode) & 0x7f;
struct pg *dev = &devices[unit];
int ret = 0;
mutex_lock(&pg_mutex);
if ((unit >= PG_UNITS) || (!dev->present)) {
ret = -ENODEV;
goto out;
}
if (test_and_set_bit(0, &dev->access)) {
ret = -EBUSY;
goto out;
}
if (dev->busy) {
pg_reset(dev);
dev->busy = 0;
}
pg_identify(dev, (verbose > 1));
dev->bufptr = kmalloc(PG_MAX_DATA, GFP_KERNEL);
if (dev->bufptr == NULL) {
clear_bit(0, &dev->access);
printk("%s: buffer allocation failed\n", dev->name);
ret = -ENOMEM;
goto out;
}
file->private_data = dev;
out:
mutex_unlock(&pg_mutex);
return ret;
}
static int pg_release(struct inode *inode, struct file *file)
{
struct pg *dev = file->private_data;
kfree(dev->bufptr);
dev->bufptr = NULL;
clear_bit(0, &dev->access);
return 0;
}
static ssize_t pg_write(struct file *filp, const char __user *buf, size_t count, loff_t *ppos)
{
struct pg *dev = filp->private_data;
struct pg_write_hdr hdr;
int hs = sizeof (hdr);
if (dev->busy)
return -EBUSY;
if (count < hs)
return -EINVAL;
if (copy_from_user(&hdr, buf, hs))
return -EFAULT;
if (hdr.magic != PG_MAGIC)
return -EINVAL;
if (hdr.dlen > PG_MAX_DATA)
return -EINVAL;
if ((count - hs) > PG_MAX_DATA)
return -EINVAL;
if (hdr.func == PG_RESET) {
if (count != hs)
return -EINVAL;
if (pg_reset(dev))
return -EIO;
return count;
}
if (hdr.func != PG_COMMAND)
return -EINVAL;
dev->start = jiffies;
dev->timeout = hdr.timeout * HZ + HZ / 2 + jiffies;
if (pg_command(dev, hdr.packet, hdr.dlen, jiffies + PG_TMO)) {
if (dev->status & 0x10)
return -ETIME;
return -EIO;
}
dev->busy = 1;
if (copy_from_user(dev->bufptr, buf + hs, count - hs))
return -EFAULT;
return count;
}
static ssize_t pg_read(struct file *filp, char __user *buf, size_t count, loff_t *ppos)
{
struct pg *dev = filp->private_data;
struct pg_read_hdr hdr;
int hs = sizeof (hdr);
int copy;
if (!dev->busy)
return -EINVAL;
if (count < hs)
return -EINVAL;
dev->busy = 0;
if (pg_completion(dev, dev->bufptr, dev->timeout))
if (dev->status & 0x10)
return -ETIME;
memset(&hdr, 0, sizeof(hdr));
hdr.magic = PG_MAGIC;
hdr.dlen = dev->dlen;
copy = 0;
if (hdr.dlen < 0) {
hdr.dlen = -1 * hdr.dlen;
copy = hdr.dlen;
if (copy > (count - hs))
copy = count - hs;
}
hdr.duration = (jiffies - dev->start + HZ / 2) / HZ;
hdr.scsi = dev->status & 0x0f;
if (copy_to_user(buf, &hdr, hs))
return -EFAULT;
if (copy > 0)
if (copy_to_user(buf + hs, dev->bufptr, copy))
return -EFAULT;
return copy + hs;
}
static int __init pg_init(void)
{
int unit;
int err;
if (disable){
err = -EINVAL;
goto out;
}
pg_init_units();
if (pg_detect()) {
err = -ENODEV;
goto out;
}
err = register_chrdev(major, name, &pg_fops);
if (err < 0) {
printk("pg_init: unable to get major number %d\n", major);
for (unit = 0; unit < PG_UNITS; unit++) {
struct pg *dev = &devices[unit];
if (dev->present)
pi_release(dev->pi);
}
goto out;
}
major = err;
pg_class = class_create(THIS_MODULE, "pg");
if (IS_ERR(pg_class)) {
err = PTR_ERR(pg_class);
goto out_chrdev;
}
for (unit = 0; unit < PG_UNITS; unit++) {
struct pg *dev = &devices[unit];
if (dev->present)
device_create(pg_class, NULL, MKDEV(major, unit), NULL,
"pg%u", unit);
}
err = 0;
goto out;
out_chrdev:
unregister_chrdev(major, "pg");
out:
return err;
}
static void __exit pg_exit(void)
{
int unit;
for (unit = 0; unit < PG_UNITS; unit++) {
struct pg *dev = &devices[unit];
if (dev->present)
device_destroy(pg_class, MKDEV(major, unit));
}
class_destroy(pg_class);
unregister_chrdev(major, name);
for (unit = 0; unit < PG_UNITS; unit++) {
struct pg *dev = &devices[unit];
if (dev->present)
pi_release(dev->pi);
}
}
