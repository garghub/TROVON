static struct qib_diag_client *get_client(struct qib_devdata *dd)
{
struct qib_diag_client *dc;
dc = client_pool;
if (dc)
client_pool = dc->next;
else
dc = kmalloc(sizeof *dc, GFP_KERNEL);
if (dc) {
dc->next = NULL;
dc->dd = dd;
dc->pid = current->pid;
dc->state = OPENED;
}
return dc;
}
static void return_client(struct qib_diag_client *dc)
{
struct qib_devdata *dd = dc->dd;
struct qib_diag_client *tdc, *rdc;
rdc = NULL;
if (dc == dd->diag_client) {
dd->diag_client = dc->next;
rdc = dc;
} else {
tdc = dc->dd->diag_client;
while (tdc) {
if (dc == tdc->next) {
tdc->next = dc->next;
rdc = dc;
break;
}
tdc = tdc->next;
}
}
if (rdc) {
rdc->state = UNUSED;
rdc->dd = NULL;
rdc->pid = 0;
rdc->next = client_pool;
client_pool = rdc;
}
}
int qib_diag_add(struct qib_devdata *dd)
{
char name[16];
int ret = 0;
if (atomic_inc_return(&diagpkt_count) == 1) {
ret = qib_cdev_init(QIB_DIAGPKT_MINOR, "ipath_diagpkt",
&diagpkt_file_ops, &diagpkt_cdev,
&diagpkt_device);
if (ret)
goto done;
}
snprintf(name, sizeof(name), "ipath_diag%d", dd->unit);
ret = qib_cdev_init(QIB_DIAG_MINOR_BASE + dd->unit, name,
&diag_file_ops, &dd->diag_cdev,
&dd->diag_device);
done:
return ret;
}
void qib_diag_remove(struct qib_devdata *dd)
{
struct qib_diag_client *dc;
if (atomic_dec_and_test(&diagpkt_count))
qib_cdev_cleanup(&diagpkt_cdev, &diagpkt_device);
qib_cdev_cleanup(&dd->diag_cdev, &dd->diag_device);
while (dd->diag_client)
return_client(dd->diag_client);
while (client_pool) {
dc = client_pool;
client_pool = dc->next;
kfree(dc);
}
qib_unregister_observers(dd);
}
static u32 __iomem *qib_remap_ioaddr32(struct qib_devdata *dd, u32 offset,
u32 *cntp)
{
u32 kreglen;
u32 snd_bottom, snd_lim = 0;
u32 __iomem *krb32 = (u32 __iomem *)dd->kregbase;
u32 __iomem *map = NULL;
u32 cnt = 0;
u32 tot4k, offs4k;
kreglen = (dd->kregend - dd->kregbase) * sizeof(u64);
if (offset < kreglen) {
map = krb32 + (offset / sizeof(u32));
cnt = kreglen - offset;
goto mapped;
}
if (dd->userbase) {
u32 ulim = (dd->cfgctxts * dd->ureg_align) + dd->uregbase;
if (!dd->piovl15base)
snd_lim = dd->uregbase;
krb32 = (u32 __iomem *)dd->userbase;
if (offset >= dd->uregbase && offset < ulim) {
map = krb32 + (offset - dd->uregbase) / sizeof(u32);
cnt = ulim - offset;
goto mapped;
}
}
snd_bottom = dd->pio2k_bufbase;
if (snd_lim == 0) {
u32 tot2k = dd->piobcnt2k * ALIGN(dd->piosize2k, dd->palign);
snd_lim = snd_bottom + tot2k;
}
tot4k = dd->piobcnt4k * dd->align4k;
offs4k = dd->piobufbase >> 32;
if (dd->piobcnt4k) {
if (snd_bottom > offs4k)
snd_bottom = offs4k;
else {
if (!dd->userbase || dd->piovl15base)
snd_lim = offs4k + tot4k;
}
}
if (offset >= snd_bottom && offset < snd_lim) {
offset -= snd_bottom;
map = (u32 __iomem *)dd->piobase + (offset / sizeof(u32));
cnt = snd_lim - offset;
}
if (!map && offs4k && dd->piovl15base) {
snd_lim = offs4k + tot4k + 2 * dd->align4k;
if (offset >= (offs4k + tot4k) && offset < snd_lim) {
map = (u32 __iomem *)dd->piovl15base +
((offset - (offs4k + tot4k)) / sizeof(u32));
cnt = snd_lim - offset;
}
}
mapped:
if (cntp)
*cntp = cnt;
return map;
}
static int qib_read_umem64(struct qib_devdata *dd, void __user *uaddr,
u32 regoffs, size_t count)
{
const u64 __iomem *reg_addr;
const u64 __iomem *reg_end;
u32 limit;
int ret;
reg_addr = (const u64 __iomem *)qib_remap_ioaddr32(dd, regoffs, &limit);
if (reg_addr == NULL || limit == 0 || !(dd->flags & QIB_PRESENT)) {
ret = -EINVAL;
goto bail;
}
if (count >= limit)
count = limit;
reg_end = reg_addr + (count / sizeof(u64));
while (reg_addr < reg_end) {
u64 data = readq(reg_addr);
if (copy_to_user(uaddr, &data, sizeof(u64))) {
ret = -EFAULT;
goto bail;
}
reg_addr++;
uaddr += sizeof(u64);
}
ret = 0;
bail:
return ret;
}
static int qib_write_umem64(struct qib_devdata *dd, u32 regoffs,
const void __user *uaddr, size_t count)
{
u64 __iomem *reg_addr;
const u64 __iomem *reg_end;
u32 limit;
int ret;
reg_addr = (u64 __iomem *)qib_remap_ioaddr32(dd, regoffs, &limit);
if (reg_addr == NULL || limit == 0 || !(dd->flags & QIB_PRESENT)) {
ret = -EINVAL;
goto bail;
}
if (count >= limit)
count = limit;
reg_end = reg_addr + (count / sizeof(u64));
while (reg_addr < reg_end) {
u64 data;
if (copy_from_user(&data, uaddr, sizeof(data))) {
ret = -EFAULT;
goto bail;
}
writeq(data, reg_addr);
reg_addr++;
uaddr += sizeof(u64);
}
ret = 0;
bail:
return ret;
}
static int qib_read_umem32(struct qib_devdata *dd, void __user *uaddr,
u32 regoffs, size_t count)
{
const u32 __iomem *reg_addr;
const u32 __iomem *reg_end;
u32 limit;
int ret;
reg_addr = qib_remap_ioaddr32(dd, regoffs, &limit);
if (reg_addr == NULL || limit == 0 || !(dd->flags & QIB_PRESENT)) {
ret = -EINVAL;
goto bail;
}
if (count >= limit)
count = limit;
reg_end = reg_addr + (count / sizeof(u32));
while (reg_addr < reg_end) {
u32 data = readl(reg_addr);
if (copy_to_user(uaddr, &data, sizeof(data))) {
ret = -EFAULT;
goto bail;
}
reg_addr++;
uaddr += sizeof(u32);
}
ret = 0;
bail:
return ret;
}
static int qib_write_umem32(struct qib_devdata *dd, u32 regoffs,
const void __user *uaddr, size_t count)
{
u32 __iomem *reg_addr;
const u32 __iomem *reg_end;
u32 limit;
int ret;
reg_addr = qib_remap_ioaddr32(dd, regoffs, &limit);
if (reg_addr == NULL || limit == 0 || !(dd->flags & QIB_PRESENT)) {
ret = -EINVAL;
goto bail;
}
if (count >= limit)
count = limit;
reg_end = reg_addr + (count / sizeof(u32));
while (reg_addr < reg_end) {
u32 data;
if (copy_from_user(&data, uaddr, sizeof(data))) {
ret = -EFAULT;
goto bail;
}
writel(data, reg_addr);
reg_addr++;
uaddr += sizeof(u32);
}
ret = 0;
bail:
return ret;
}
static int qib_diag_open(struct inode *in, struct file *fp)
{
int unit = iminor(in) - QIB_DIAG_MINOR_BASE;
struct qib_devdata *dd;
struct qib_diag_client *dc;
int ret;
mutex_lock(&qib_mutex);
dd = qib_lookup(unit);
if (dd == NULL || !(dd->flags & QIB_PRESENT) ||
!dd->kregbase) {
ret = -ENODEV;
goto bail;
}
dc = get_client(dd);
if (!dc) {
ret = -ENOMEM;
goto bail;
}
dc->next = dd->diag_client;
dd->diag_client = dc;
fp->private_data = dc;
ret = 0;
bail:
mutex_unlock(&qib_mutex);
return ret;
}
static ssize_t qib_diagpkt_write(struct file *fp,
const char __user *data,
size_t count, loff_t *off)
{
u32 __iomem *piobuf;
u32 plen, clen, pbufn;
struct qib_diag_xpkt dp;
u32 *tmpbuf = NULL;
struct qib_devdata *dd;
struct qib_pportdata *ppd;
ssize_t ret = 0;
if (count != sizeof(dp)) {
ret = -EINVAL;
goto bail;
}
if (copy_from_user(&dp, data, sizeof(dp))) {
ret = -EFAULT;
goto bail;
}
dd = qib_lookup(dp.unit);
if (!dd || !(dd->flags & QIB_PRESENT) || !dd->kregbase) {
ret = -ENODEV;
goto bail;
}
if (!(dd->flags & QIB_INITTED)) {
ret = -ENODEV;
goto bail;
}
if (dp.version != _DIAG_XPKT_VERS) {
qib_dev_err(dd, "Invalid version %u for diagpkt_write\n",
dp.version);
ret = -EINVAL;
goto bail;
}
if (dp.len & 3) {
ret = -EINVAL;
goto bail;
}
if (!dp.port || dp.port > dd->num_pports) {
ret = -EINVAL;
goto bail;
}
ppd = &dd->pport[dp.port - 1];
plen = sizeof(u32) + dp.len;
clen = dp.len >> 2;
if ((plen + 4) > ppd->ibmaxlen) {
ret = -EINVAL;
goto bail;
}
tmpbuf = vmalloc(plen);
if (!tmpbuf) {
qib_devinfo(dd->pcidev, "Unable to allocate tmp buffer, "
"failing\n");
ret = -ENOMEM;
goto bail;
}
if (copy_from_user(tmpbuf,
(const void __user *) (unsigned long) dp.data,
dp.len)) {
ret = -EFAULT;
goto bail;
}
plen >>= 2;
if (dp.pbc_wd == 0)
dp.pbc_wd = plen;
piobuf = dd->f_getsendbuf(ppd, dp.pbc_wd, &pbufn);
if (!piobuf) {
ret = -EBUSY;
goto bail;
}
dd->f_sendctrl(dd->pport, QIB_SENDCTRL_DISARM_BUF(pbufn));
dd->f_txchk_change(dd, pbufn, 1, TXCHK_CHG_TYPE_DIS1, NULL);
writeq(dp.pbc_wd, piobuf);
if (dd->flags & QIB_PIO_FLUSH_WC) {
qib_flush_wc();
qib_pio_copy(piobuf + 2, tmpbuf, clen - 1);
qib_flush_wc();
__raw_writel(tmpbuf[clen - 1], piobuf + clen + 1);
} else
qib_pio_copy(piobuf + 2, tmpbuf, clen);
if (dd->flags & QIB_USE_SPCL_TRIG) {
u32 spcl_off = (pbufn >= dd->piobcnt2k) ? 2047 : 1023;
qib_flush_wc();
__raw_writel(0xaebecede, piobuf + spcl_off);
}
qib_flush_wc();
qib_sendbuf_done(dd, pbufn);
dd->f_txchk_change(dd, pbufn, 1, TXCHK_CHG_TYPE_ENAB1, NULL);
ret = sizeof(dp);
bail:
vfree(tmpbuf);
return ret;
}
static int qib_diag_release(struct inode *in, struct file *fp)
{
mutex_lock(&qib_mutex);
return_client(fp->private_data);
fp->private_data = NULL;
mutex_unlock(&qib_mutex);
return 0;
}
int qib_register_observer(struct qib_devdata *dd,
const struct diag_observer *op)
{
struct diag_observer_list_elt *olp;
int ret = -EINVAL;
if (!dd || !op)
goto bail;
ret = -ENOMEM;
olp = vmalloc(sizeof *olp);
if (!olp) {
printk(KERN_ERR QIB_DRV_NAME ": vmalloc for observer failed\n");
goto bail;
}
if (olp) {
unsigned long flags;
spin_lock_irqsave(&dd->qib_diag_trans_lock, flags);
olp->op = op;
olp->next = dd->diag_observer_list;
dd->diag_observer_list = olp;
spin_unlock_irqrestore(&dd->qib_diag_trans_lock, flags);
ret = 0;
}
bail:
return ret;
}
static void qib_unregister_observers(struct qib_devdata *dd)
{
struct diag_observer_list_elt *olp;
unsigned long flags;
spin_lock_irqsave(&dd->qib_diag_trans_lock, flags);
olp = dd->diag_observer_list;
while (olp) {
dd->diag_observer_list = olp->next;
spin_unlock_irqrestore(&dd->qib_diag_trans_lock, flags);
vfree(olp);
spin_lock_irqsave(&dd->qib_diag_trans_lock, flags);
olp = dd->diag_observer_list;
}
spin_unlock_irqrestore(&dd->qib_diag_trans_lock, flags);
}
static const struct diag_observer *diag_get_observer(struct qib_devdata *dd,
u32 addr)
{
struct diag_observer_list_elt *olp;
const struct diag_observer *op = NULL;
olp = dd->diag_observer_list;
while (olp) {
op = olp->op;
if (addr >= op->bottom && addr <= op->top)
break;
olp = olp->next;
}
if (!olp)
op = NULL;
return op;
}
static ssize_t qib_diag_read(struct file *fp, char __user *data,
size_t count, loff_t *off)
{
struct qib_diag_client *dc = fp->private_data;
struct qib_devdata *dd = dc->dd;
void __iomem *kreg_base;
ssize_t ret;
if (dc->pid != current->pid) {
ret = -EPERM;
goto bail;
}
kreg_base = dd->kregbase;
if (count == 0)
ret = 0;
else if ((count % 4) || (*off % 4))
ret = -EINVAL;
else if (dc->state < READY && (*off || count != 8))
ret = -EINVAL;
else {
unsigned long flags;
u64 data64 = 0;
int use_32;
const struct diag_observer *op;
use_32 = (count % 8) || (*off % 8);
ret = -1;
spin_lock_irqsave(&dd->qib_diag_trans_lock, flags);
op = diag_get_observer(dd, *off);
if (op) {
u32 offset = *off;
ret = op->hook(dd, op, offset, &data64, 0, use_32);
}
spin_unlock_irqrestore(&dd->qib_diag_trans_lock, flags);
if (!op) {
if (use_32)
ret = qib_read_umem32(dd, data, (u32) *off,
count);
else
ret = qib_read_umem64(dd, data, (u32) *off,
count);
} else if (ret == count) {
ret = copy_to_user(data, &data64, use_32 ?
sizeof(u32) : sizeof(u64));
if (ret)
ret = -EFAULT;
}
}
if (ret >= 0) {
*off += count;
ret = count;
if (dc->state == OPENED)
dc->state = INIT;
}
bail:
return ret;
}
static ssize_t qib_diag_write(struct file *fp, const char __user *data,
size_t count, loff_t *off)
{
struct qib_diag_client *dc = fp->private_data;
struct qib_devdata *dd = dc->dd;
void __iomem *kreg_base;
ssize_t ret;
if (dc->pid != current->pid) {
ret = -EPERM;
goto bail;
}
kreg_base = dd->kregbase;
if (count == 0)
ret = 0;
else if ((count % 4) || (*off % 4))
ret = -EINVAL;
else if (dc->state < READY &&
((*off || count != 8) || dc->state != INIT))
ret = -EINVAL;
else {
unsigned long flags;
const struct diag_observer *op = NULL;
int use_32 = (count % 8) || (*off % 8);
if (count == 4 || count == 8) {
u64 data64;
u32 offset = *off;
ret = copy_from_user(&data64, data, count);
if (ret) {
ret = -EFAULT;
goto bail;
}
spin_lock_irqsave(&dd->qib_diag_trans_lock, flags);
op = diag_get_observer(dd, *off);
if (op)
ret = op->hook(dd, op, offset, &data64, ~0Ull,
use_32);
spin_unlock_irqrestore(&dd->qib_diag_trans_lock, flags);
}
if (!op) {
if (use_32)
ret = qib_write_umem32(dd, (u32) *off, data,
count);
else
ret = qib_write_umem64(dd, (u32) *off, data,
count);
}
}
if (ret >= 0) {
*off += count;
ret = count;
if (dc->state == INIT)
dc->state = READY;
}
bail:
return ret;
}
