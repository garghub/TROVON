static inline int status_reg(struct pi_adapter *pi)
{
return pi_read_regr(pi, 1, 6);
}
static inline int read_reg(struct pi_adapter *pi, int reg)
{
return pi_read_regr(pi, 0, reg);
}
static inline void write_reg(struct pi_adapter *pi, int reg, int val)
{
pi_write_regr(pi, 0, reg, val);
}
static inline u8 DRIVE(struct pt_unit *tape)
{
return 0xa0+0x10*tape->drive;
}
static int pt_wait(struct pt_unit *tape, int go, int stop, char *fun, char *msg)
{
int j, r, e, s, p;
struct pi_adapter *pi = tape->pi;
j = 0;
while ((((r = status_reg(pi)) & go) || (stop && (!(r & stop))))
&& (j++ < PT_SPIN))
udelay(PT_SPIN_DEL);
if ((r & (STAT_ERR & stop)) || (j > PT_SPIN)) {
s = read_reg(pi, 7);
e = read_reg(pi, 1);
p = read_reg(pi, 2);
if (j > PT_SPIN)
e |= 0x100;
if (fun)
printk("%s: %s %s: alt=0x%x stat=0x%x err=0x%x"
" loop=%d phase=%d\n",
tape->name, fun, msg, r, s, e, j, p);
return (e << 8) + s;
}
return 0;
}
static int pt_command(struct pt_unit *tape, char *cmd, int dlen, char *fun)
{
struct pi_adapter *pi = tape->pi;
pi_connect(pi);
write_reg(pi, 6, DRIVE(tape));
if (pt_wait(tape, STAT_BUSY | STAT_DRQ, 0, fun, "before command")) {
pi_disconnect(pi);
return -1;
}
write_reg(pi, 4, dlen % 256);
write_reg(pi, 5, dlen / 256);
write_reg(pi, 7, 0xa0);
if (pt_wait(tape, STAT_BUSY, STAT_DRQ, fun, "command DRQ")) {
pi_disconnect(pi);
return -1;
}
if (read_reg(pi, 2) != 1) {
printk("%s: %s: command phase error\n", tape->name, fun);
pi_disconnect(pi);
return -1;
}
pi_write_block(pi, cmd, 12);
return 0;
}
static int pt_completion(struct pt_unit *tape, char *buf, char *fun)
{
struct pi_adapter *pi = tape->pi;
int r, s, n, p;
r = pt_wait(tape, STAT_BUSY, STAT_DRQ | STAT_READY | STAT_ERR,
fun, "completion");
if (read_reg(pi, 7) & STAT_DRQ) {
n = (((read_reg(pi, 4) + 256 * read_reg(pi, 5)) +
3) & 0xfffc);
p = read_reg(pi, 2) & 3;
if (p == 0)
pi_write_block(pi, buf, n);
if (p == 2)
pi_read_block(pi, buf, n);
}
s = pt_wait(tape, STAT_BUSY, STAT_READY | STAT_ERR, fun, "data done");
pi_disconnect(pi);
return (r ? r : s);
}
static void pt_req_sense(struct pt_unit *tape, int quiet)
{
char rs_cmd[12] = { ATAPI_REQ_SENSE, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0 };
char buf[16];
int r;
r = pt_command(tape, rs_cmd, 16, "Request sense");
mdelay(1);
if (!r)
pt_completion(tape, buf, "Request sense");
tape->last_sense = -1;
if (!r) {
if (!quiet)
printk("%s: Sense key: %x, ASC: %x, ASQ: %x\n",
tape->name, buf[2] & 0xf, buf[12], buf[13]);
tape->last_sense = (buf[2] & 0xf) | ((buf[12] & 0xff) << 8)
| ((buf[13] & 0xff) << 16);
}
}
static int pt_atapi(struct pt_unit *tape, char *cmd, int dlen, char *buf, char *fun)
{
int r;
r = pt_command(tape, cmd, dlen, fun);
mdelay(1);
if (!r)
r = pt_completion(tape, buf, fun);
if (r)
pt_req_sense(tape, !fun);
return r;
}
static void pt_sleep(int cs)
{
schedule_timeout_interruptible(cs);
}
static int pt_poll_dsc(struct pt_unit *tape, int pause, int tmo, char *msg)
{
struct pi_adapter *pi = tape->pi;
int k, e, s;
k = 0;
e = 0;
s = 0;
while (k < tmo) {
pt_sleep(pause);
k++;
pi_connect(pi);
write_reg(pi, 6, DRIVE(tape));
s = read_reg(pi, 7);
e = read_reg(pi, 1);
pi_disconnect(pi);
if (s & (STAT_ERR | STAT_SEEK))
break;
}
if ((k >= tmo) || (s & STAT_ERR)) {
if (k >= tmo)
printk("%s: %s DSC timeout\n", tape->name, msg);
else
printk("%s: %s stat=0x%x err=0x%x\n", tape->name, msg, s,
e);
pt_req_sense(tape, 0);
return 0;
}
return 1;
}
static void pt_media_access_cmd(struct pt_unit *tape, int tmo, char *cmd, char *fun)
{
if (pt_command(tape, cmd, 0, fun)) {
pt_req_sense(tape, 0);
return;
}
pi_disconnect(tape->pi);
pt_poll_dsc(tape, HZ, tmo, fun);
}
static void pt_rewind(struct pt_unit *tape)
{
char rw_cmd[12] = { ATAPI_REWIND, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
pt_media_access_cmd(tape, PT_REWIND_TMO, rw_cmd, "rewind");
}
static void pt_write_fm(struct pt_unit *tape)
{
char wm_cmd[12] = { ATAPI_WFM, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 };
pt_media_access_cmd(tape, PT_TMO, wm_cmd, "write filemark");
}
static int pt_reset(struct pt_unit *tape)
{
struct pi_adapter *pi = tape->pi;
int i, k, flg;
int expect[5] = { 1, 1, 1, 0x14, 0xeb };
pi_connect(pi);
write_reg(pi, 6, DRIVE(tape));
write_reg(pi, 7, 8);
pt_sleep(20 * HZ / 1000);
k = 0;
while ((k++ < PT_RESET_TMO) && (status_reg(pi) & STAT_BUSY))
pt_sleep(HZ / 10);
flg = 1;
for (i = 0; i < 5; i++)
flg &= (read_reg(pi, i + 1) == expect[i]);
if (verbose) {
printk("%s: Reset (%d) signature = ", tape->name, k);
for (i = 0; i < 5; i++)
printk("%3x", read_reg(pi, i + 1));
if (!flg)
printk(" (incorrect)");
printk("\n");
}
pi_disconnect(pi);
return flg - 1;
}
static int pt_ready_wait(struct pt_unit *tape, int tmo)
{
char tr_cmd[12] = { ATAPI_TEST_READY, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int k, p;
k = 0;
while (k < tmo) {
tape->last_sense = 0;
pt_atapi(tape, tr_cmd, 0, NULL, DBMSG("test unit ready"));
p = tape->last_sense;
if (!p)
return 0;
if (!(((p & 0xffff) == 0x0402) || ((p & 0xff) == 6)))
return p;
k++;
pt_sleep(HZ);
}
return 0x000020;
}
static void xs(char *buf, char *targ, int offs, int len)
{
int j, k, l;
j = 0;
l = 0;
for (k = 0; k < len; k++)
if ((buf[k + offs] != 0x20) || (buf[k + offs] != l))
l = targ[j++] = buf[k + offs];
if (l == 0x20)
j--;
targ[j] = 0;
}
static int xn(char *buf, int offs, int size)
{
int v, k;
v = 0;
for (k = 0; k < size; k++)
v = v * 256 + (buf[k + offs] & 0xff);
return v;
}
static int pt_identify(struct pt_unit *tape)
{
int dt, s;
char *ms[2] = { "master", "slave" };
char mf[10], id[18];
char id_cmd[12] = { ATAPI_IDENTIFY, 0, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0 };
char ms_cmd[12] =
{ ATAPI_MODE_SENSE, 0, 0x2a, 0, 36, 0, 0, 0, 0, 0, 0, 0 };
char ls_cmd[12] =
{ ATAPI_LOG_SENSE, 0, 0x71, 0, 0, 0, 0, 0, 36, 0, 0, 0 };
char buf[36];
s = pt_atapi(tape, id_cmd, 36, buf, "identify");
if (s)
return -1;
dt = buf[0] & 0x1f;
if (dt != 1) {
if (verbose)
printk("%s: Drive %d, unsupported type %d\n",
tape->name, tape->drive, dt);
return -1;
}
xs(buf, mf, 8, 8);
xs(buf, id, 16, 16);
tape->flags = 0;
tape->capacity = 0;
tape->bs = 0;
if (!pt_ready_wait(tape, PT_READY_TMO))
tape->flags |= PT_MEDIA;
if (!pt_atapi(tape, ms_cmd, 36, buf, "mode sense")) {
if (!(buf[2] & 0x80))
tape->flags |= PT_WRITE_OK;
tape->bs = xn(buf, 10, 2);
}
if (!pt_atapi(tape, ls_cmd, 36, buf, "log sense"))
tape->capacity = xn(buf, 24, 4);
printk("%s: %s %s, %s", tape->name, mf, id, ms[tape->drive]);
if (!(tape->flags & PT_MEDIA))
printk(", no media\n");
else {
if (!(tape->flags & PT_WRITE_OK))
printk(", RO");
printk(", blocksize %d, %d MB\n", tape->bs, tape->capacity / 1024);
}
return 0;
}
static int pt_probe(struct pt_unit *tape)
{
if (tape->drive == -1) {
for (tape->drive = 0; tape->drive <= 1; tape->drive++)
if (!pt_reset(tape))
return pt_identify(tape);
} else {
if (!pt_reset(tape))
return pt_identify(tape);
}
return -1;
}
static int pt_detect(void)
{
struct pt_unit *tape;
int specified = 0, found = 0;
int unit;
printk("%s: %s version %s, major %d\n", name, name, PT_VERSION, major);
par_drv = pi_register_driver(name);
if (!par_drv) {
pr_err("failed to register %s driver\n", name);
return -1;
}
specified = 0;
for (unit = 0; unit < PT_UNITS; unit++) {
struct pt_unit *tape = &pt[unit];
tape->pi = &tape->pia;
atomic_set(&tape->available, 1);
tape->flags = 0;
tape->last_sense = 0;
tape->present = 0;
tape->bufptr = NULL;
tape->drive = DU[D_SLV];
snprintf(tape->name, PT_NAMELEN, "%s%d", name, unit);
if (!DU[D_PRT])
continue;
specified++;
if (pi_init(tape->pi, 0, DU[D_PRT], DU[D_MOD], DU[D_UNI],
DU[D_PRO], DU[D_DLY], pt_scratch, PI_PT,
verbose, tape->name)) {
if (!pt_probe(tape)) {
tape->present = 1;
found++;
} else
pi_release(tape->pi);
}
}
if (specified == 0) {
tape = pt;
if (pi_init(tape->pi, 1, -1, -1, -1, -1, -1, pt_scratch,
PI_PT, verbose, tape->name)) {
if (!pt_probe(tape)) {
tape->present = 1;
found++;
} else
pi_release(tape->pi);
}
}
if (found)
return 0;
pi_unregister_driver(par_drv);
printk("%s: No ATAPI tape drive detected\n", name);
return -1;
}
static int pt_open(struct inode *inode, struct file *file)
{
int unit = iminor(inode) & 0x7F;
struct pt_unit *tape = pt + unit;
int err;
mutex_lock(&pt_mutex);
if (unit >= PT_UNITS || (!tape->present)) {
mutex_unlock(&pt_mutex);
return -ENODEV;
}
err = -EBUSY;
if (!atomic_dec_and_test(&tape->available))
goto out;
pt_identify(tape);
err = -ENODEV;
if (!(tape->flags & PT_MEDIA))
goto out;
err = -EROFS;
if ((!(tape->flags & PT_WRITE_OK)) && (file->f_mode & FMODE_WRITE))
goto out;
if (!(iminor(inode) & 128))
tape->flags |= PT_REWIND;
err = -ENOMEM;
tape->bufptr = kmalloc(PT_BUFSIZE, GFP_KERNEL);
if (tape->bufptr == NULL) {
printk("%s: buffer allocation failed\n", tape->name);
goto out;
}
file->private_data = tape;
mutex_unlock(&pt_mutex);
return 0;
out:
atomic_inc(&tape->available);
mutex_unlock(&pt_mutex);
return err;
}
static long pt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct pt_unit *tape = file->private_data;
struct mtop __user *p = (void __user *)arg;
struct mtop mtop;
switch (cmd) {
case MTIOCTOP:
if (copy_from_user(&mtop, p, sizeof(struct mtop)))
return -EFAULT;
switch (mtop.mt_op) {
case MTREW:
mutex_lock(&pt_mutex);
pt_rewind(tape);
mutex_unlock(&pt_mutex);
return 0;
case MTWEOF:
mutex_lock(&pt_mutex);
pt_write_fm(tape);
mutex_unlock(&pt_mutex);
return 0;
default:
printk(KERN_DEBUG "%s: Unimplemented mt_op %d\n", tape->name,
mtop.mt_op);
return -EINVAL;
}
default:
return -ENOTTY;
}
}
static int
pt_release(struct inode *inode, struct file *file)
{
struct pt_unit *tape = file->private_data;
if (atomic_read(&tape->available) > 1)
return -EINVAL;
if (tape->flags & PT_WRITING)
pt_write_fm(tape);
if (tape->flags & PT_REWIND)
pt_rewind(tape);
kfree(tape->bufptr);
tape->bufptr = NULL;
atomic_inc(&tape->available);
return 0;
}
static ssize_t pt_read(struct file *filp, char __user *buf, size_t count, loff_t * ppos)
{
struct pt_unit *tape = filp->private_data;
struct pi_adapter *pi = tape->pi;
char rd_cmd[12] = { ATAPI_READ_6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int k, n, r, p, s, t, b;
if (!(tape->flags & (PT_READING | PT_WRITING))) {
tape->flags |= PT_READING;
if (pt_atapi(tape, rd_cmd, 0, NULL, "start read-ahead"))
return -EIO;
} else if (tape->flags & PT_WRITING)
return -EIO;
if (tape->flags & PT_EOF)
return 0;
t = 0;
while (count > 0) {
if (!pt_poll_dsc(tape, HZ / 100, PT_TMO, "read"))
return -EIO;
n = count;
if (n > 32768)
n = 32768;
b = (n - 1 + tape->bs) / tape->bs;
n = b * tape->bs;
rd_cmd[4] = b;
r = pt_command(tape, rd_cmd, n, "read");
mdelay(1);
if (r) {
pt_req_sense(tape, 0);
return -EIO;
}
while (1) {
r = pt_wait(tape, STAT_BUSY,
STAT_DRQ | STAT_ERR | STAT_READY,
DBMSG("read DRQ"), "");
if (r & STAT_SENSE) {
pi_disconnect(pi);
pt_req_sense(tape, 0);
return -EIO;
}
if (r)
tape->flags |= PT_EOF;
s = read_reg(pi, 7);
if (!(s & STAT_DRQ))
break;
n = (read_reg(pi, 4) + 256 * read_reg(pi, 5));
p = (read_reg(pi, 2) & 3);
if (p != 2) {
pi_disconnect(pi);
printk("%s: Phase error on read: %d\n", tape->name,
p);
return -EIO;
}
while (n > 0) {
k = n;
if (k > PT_BUFSIZE)
k = PT_BUFSIZE;
pi_read_block(pi, tape->bufptr, k);
n -= k;
b = k;
if (b > count)
b = count;
if (copy_to_user(buf + t, tape->bufptr, b)) {
pi_disconnect(pi);
return -EFAULT;
}
t += b;
count -= b;
}
}
pi_disconnect(pi);
if (tape->flags & PT_EOF)
break;
}
return t;
}
static ssize_t pt_write(struct file *filp, const char __user *buf, size_t count, loff_t * ppos)
{
struct pt_unit *tape = filp->private_data;
struct pi_adapter *pi = tape->pi;
char wr_cmd[12] = { ATAPI_WRITE_6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int k, n, r, p, s, t, b;
if (!(tape->flags & PT_WRITE_OK))
return -EROFS;
if (!(tape->flags & (PT_READING | PT_WRITING))) {
tape->flags |= PT_WRITING;
if (pt_atapi
(tape, wr_cmd, 0, NULL, "start buffer-available mode"))
return -EIO;
} else if (tape->flags & PT_READING)
return -EIO;
if (tape->flags & PT_EOF)
return -ENOSPC;
t = 0;
while (count > 0) {
if (!pt_poll_dsc(tape, HZ / 100, PT_TMO, "write"))
return -EIO;
n = count;
if (n > 32768)
n = 32768;
b = (n - 1 + tape->bs) / tape->bs;
n = b * tape->bs;
wr_cmd[4] = b;
r = pt_command(tape, wr_cmd, n, "write");
mdelay(1);
if (r) {
pt_req_sense(tape, 0);
return -EIO;
}
while (1) {
r = pt_wait(tape, STAT_BUSY,
STAT_DRQ | STAT_ERR | STAT_READY,
DBMSG("write DRQ"), NULL);
if (r & STAT_SENSE) {
pi_disconnect(pi);
pt_req_sense(tape, 0);
return -EIO;
}
if (r)
tape->flags |= PT_EOF;
s = read_reg(pi, 7);
if (!(s & STAT_DRQ))
break;
n = (read_reg(pi, 4) + 256 * read_reg(pi, 5));
p = (read_reg(pi, 2) & 3);
if (p != 0) {
pi_disconnect(pi);
printk("%s: Phase error on write: %d \n",
tape->name, p);
return -EIO;
}
while (n > 0) {
k = n;
if (k > PT_BUFSIZE)
k = PT_BUFSIZE;
b = k;
if (b > count)
b = count;
if (copy_from_user(tape->bufptr, buf + t, b)) {
pi_disconnect(pi);
return -EFAULT;
}
pi_write_block(pi, tape->bufptr, k);
t += b;
count -= b;
n -= k;
}
}
pi_disconnect(pi);
if (tape->flags & PT_EOF)
break;
}
return t;
}
static int __init pt_init(void)
{
int unit;
int err;
if (disable) {
err = -EINVAL;
goto out;
}
if (pt_detect()) {
err = -ENODEV;
goto out;
}
err = register_chrdev(major, name, &pt_fops);
if (err < 0) {
printk("pt_init: unable to get major number %d\n", major);
for (unit = 0; unit < PT_UNITS; unit++)
if (pt[unit].present)
pi_release(pt[unit].pi);
goto out;
}
major = err;
pt_class = class_create(THIS_MODULE, "pt");
if (IS_ERR(pt_class)) {
err = PTR_ERR(pt_class);
goto out_chrdev;
}
for (unit = 0; unit < PT_UNITS; unit++)
if (pt[unit].present) {
device_create(pt_class, NULL, MKDEV(major, unit), NULL,
"pt%d", unit);
device_create(pt_class, NULL, MKDEV(major, unit + 128),
NULL, "pt%dn", unit);
}
goto out;
out_chrdev:
unregister_chrdev(major, "pt");
out:
return err;
}
static void __exit pt_exit(void)
{
int unit;
for (unit = 0; unit < PT_UNITS; unit++)
if (pt[unit].present) {
device_destroy(pt_class, MKDEV(major, unit));
device_destroy(pt_class, MKDEV(major, unit + 128));
}
class_destroy(pt_class);
unregister_chrdev(major, name);
for (unit = 0; unit < PT_UNITS; unit++)
if (pt[unit].present)
pi_release(pt[unit].pi);
}
