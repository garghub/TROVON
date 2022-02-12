int ipath_diag_add(struct ipath_devdata *dd)
{
char name[16];
int ret = 0;
if (atomic_inc_return(&diagpkt_count) == 1) {
ret = ipath_cdev_init(IPATH_DIAGPKT_MINOR,
"ipath_diagpkt", &diagpkt_file_ops,
&diagpkt_cdev, &diagpkt_dev);
if (ret) {
ipath_dev_err(dd, "Couldn't create ipath_diagpkt "
"device: %d", ret);
goto done;
}
}
snprintf(name, sizeof(name), "ipath_diag%d", dd->ipath_unit);
ret = ipath_cdev_init(IPATH_DIAG_MINOR_BASE + dd->ipath_unit, name,
&diag_file_ops, &dd->diag_cdev,
&dd->diag_dev);
if (ret)
ipath_dev_err(dd, "Couldn't create %s device: %d",
name, ret);
done:
return ret;
}
void ipath_diag_remove(struct ipath_devdata *dd)
{
if (atomic_dec_and_test(&diagpkt_count))
ipath_cdev_cleanup(&diagpkt_cdev, &diagpkt_dev);
ipath_cdev_cleanup(&dd->diag_cdev, &dd->diag_dev);
}
static int ipath_read_umem64(struct ipath_devdata *dd, void __user *uaddr,
const void __iomem *caddr, size_t count)
{
const u64 __iomem *reg_addr = caddr;
const u64 __iomem *reg_end = reg_addr + (count / sizeof(u64));
int ret;
if (reg_addr < dd->ipath_kregbase || reg_end > dd->ipath_kregend) {
ret = -EINVAL;
goto bail;
}
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
static int ipath_write_umem64(struct ipath_devdata *dd, void __iomem *caddr,
const void __user *uaddr, size_t count)
{
u64 __iomem *reg_addr = caddr;
const u64 __iomem *reg_end = reg_addr + (count / sizeof(u64));
int ret;
if (reg_addr < dd->ipath_kregbase || reg_end > dd->ipath_kregend) {
ret = -EINVAL;
goto bail;
}
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
static int ipath_read_umem32(struct ipath_devdata *dd, void __user *uaddr,
const void __iomem *caddr, size_t count)
{
const u32 __iomem *reg_addr = caddr;
const u32 __iomem *reg_end = reg_addr + (count / sizeof(u32));
int ret;
if (reg_addr < (u32 __iomem *) dd->ipath_kregbase ||
reg_end > (u32 __iomem *) dd->ipath_kregend) {
ret = -EINVAL;
goto bail;
}
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
static int ipath_write_umem32(struct ipath_devdata *dd, void __iomem *caddr,
const void __user *uaddr, size_t count)
{
u32 __iomem *reg_addr = caddr;
const u32 __iomem *reg_end = reg_addr + (count / sizeof(u32));
int ret;
if (reg_addr < (u32 __iomem *) dd->ipath_kregbase ||
reg_end > (u32 __iomem *) dd->ipath_kregend) {
ret = -EINVAL;
goto bail;
}
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
static int ipath_diag_open(struct inode *in, struct file *fp)
{
int unit = iminor(in) - IPATH_DIAG_MINOR_BASE;
struct ipath_devdata *dd;
int ret;
mutex_lock(&ipath_mutex);
if (ipath_diag_inuse) {
ret = -EBUSY;
goto bail;
}
dd = ipath_lookup(unit);
if (dd == NULL || !(dd->ipath_flags & IPATH_PRESENT) ||
!dd->ipath_kregbase) {
ret = -ENODEV;
goto bail;
}
fp->private_data = dd;
ipath_diag_inuse = -2;
diag_set_link = 0;
ret = 0;
ipath_expose_reset(&dd->pcidev->dev);
bail:
mutex_unlock(&ipath_mutex);
return ret;
}
static ssize_t ipath_diagpkt_write(struct file *fp,
const char __user *data,
size_t count, loff_t *off)
{
u32 __iomem *piobuf;
u32 plen, pbufn, maxlen_reserve;
struct ipath_diag_pkt odp;
struct ipath_diag_xpkt dp;
u32 *tmpbuf = NULL;
struct ipath_devdata *dd;
ssize_t ret = 0;
u64 val;
u32 l_state, lt_state;
if (count == sizeof(dp)) {
if (copy_from_user(&dp, data, sizeof(dp))) {
ret = -EFAULT;
goto bail;
}
} else if (count == sizeof(odp)) {
if (copy_from_user(&odp, data, sizeof(odp))) {
ret = -EFAULT;
goto bail;
}
} else {
ret = -EINVAL;
goto bail;
}
if (dp.len & 3) {
ret = -EINVAL;
goto bail;
}
plen = dp.len >> 2;
dd = ipath_lookup(dp.unit);
if (!dd || !(dd->ipath_flags & IPATH_PRESENT) ||
!dd->ipath_kregbase) {
ipath_cdbg(VERBOSE, "illegal unit %u for diag data send\n",
dp.unit);
ret = -ENODEV;
goto bail;
}
if (ipath_diag_inuse && !diag_set_link &&
!(dd->ipath_flags & IPATH_LINKACTIVE)) {
diag_set_link = 1;
ipath_cdbg(VERBOSE, "Trying to set to set link active for "
"diag pkt\n");
ipath_set_linkstate(dd, IPATH_IB_LINKARM);
ipath_set_linkstate(dd, IPATH_IB_LINKACTIVE);
}
if (!(dd->ipath_flags & IPATH_INITTED)) {
ipath_cdbg(VERBOSE, "unit %u not usable\n", dd->ipath_unit);
ret = -ENODEV;
goto bail;
}
val = ipath_ib_state(dd, dd->ipath_lastibcstat);
lt_state = ipath_ib_linktrstate(dd, dd->ipath_lastibcstat);
l_state = ipath_ib_linkstate(dd, dd->ipath_lastibcstat);
if (!dp.pbc_wd && (lt_state != INFINIPATH_IBCS_LT_STATE_LINKUP ||
(val != dd->ib_init && val != dd->ib_arm &&
val != dd->ib_active))) {
ipath_cdbg(VERBOSE, "unit %u not ready (state %llx)\n",
dd->ipath_unit, (unsigned long long) val);
ret = -EINVAL;
goto bail;
}
maxlen_reserve = 2 * sizeof(u32);
if (dp.len > dd->ipath_ibmaxlen - maxlen_reserve) {
ipath_dbg("Pkt len 0x%x > ibmaxlen %x\n",
dp.len, dd->ipath_ibmaxlen);
ret = -EINVAL;
goto bail;
}
plen = sizeof(u32) + dp.len;
tmpbuf = vmalloc(plen);
if (!tmpbuf) {
dev_info(&dd->pcidev->dev, "Unable to allocate tmp buffer, "
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
piobuf = ipath_getpiobuf(dd, plen, &pbufn);
if (!piobuf) {
ipath_cdbg(VERBOSE, "No PIO buffers avail unit for %u\n",
dd->ipath_unit);
ret = -EBUSY;
goto bail;
}
ipath_disarm_piobufs(dd, pbufn, 1);
if (ipath_debug & __IPATH_PKTDBG)
ipath_cdbg(VERBOSE, "unit %u 0x%x+1w pio%d\n",
dd->ipath_unit, plen - 1, pbufn);
if (dp.pbc_wd == 0)
dp.pbc_wd = plen;
writeq(dp.pbc_wd, piobuf);
if (dd->ipath_flags & IPATH_PIO_FLUSH_WC) {
ipath_flush_wc();
__iowrite32_copy(piobuf + 2, tmpbuf, plen - 1);
ipath_flush_wc();
__raw_writel(tmpbuf[plen - 1], piobuf + plen + 1);
} else
__iowrite32_copy(piobuf + 2, tmpbuf, plen);
ipath_flush_wc();
ret = sizeof(dp);
bail:
vfree(tmpbuf);
return ret;
}
static int ipath_diag_release(struct inode *in, struct file *fp)
{
mutex_lock(&ipath_mutex);
ipath_diag_inuse = 0;
fp->private_data = NULL;
mutex_unlock(&ipath_mutex);
return 0;
}
static ssize_t ipath_diag_read(struct file *fp, char __user *data,
size_t count, loff_t *off)
{
struct ipath_devdata *dd = fp->private_data;
void __iomem *kreg_base;
ssize_t ret;
kreg_base = dd->ipath_kregbase;
if (count == 0)
ret = 0;
else if ((count % 4) || (*off % 4))
ret = -EINVAL;
else if (ipath_diag_inuse < 1 && (*off || count != 8))
ret = -EINVAL;
else if ((count % 8) || (*off % 8))
ret = ipath_read_umem32(dd, data, kreg_base + *off, count);
else
ret = ipath_read_umem64(dd, data, kreg_base + *off, count);
if (ret >= 0) {
*off += count;
ret = count;
if (ipath_diag_inuse == -2)
ipath_diag_inuse++;
}
return ret;
}
static ssize_t ipath_diag_write(struct file *fp, const char __user *data,
size_t count, loff_t *off)
{
struct ipath_devdata *dd = fp->private_data;
void __iomem *kreg_base;
ssize_t ret;
kreg_base = dd->ipath_kregbase;
if (count == 0)
ret = 0;
else if ((count % 4) || (*off % 4))
ret = -EINVAL;
else if ((ipath_diag_inuse == -1 && (*off || count != 8)) ||
ipath_diag_inuse == -2)
ret = -EINVAL;
else if ((count % 8) || (*off % 8))
ret = ipath_write_umem32(dd, kreg_base + *off, data, count);
else
ret = ipath_write_umem64(dd, kreg_base + *off, data, count);
if (ret >= 0) {
*off += count;
ret = count;
if (ipath_diag_inuse == -1)
ipath_diag_inuse = 1;
}
return ret;
}
