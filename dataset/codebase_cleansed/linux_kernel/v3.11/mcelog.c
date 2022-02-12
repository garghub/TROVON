static int xen_mce_chrdev_open(struct inode *inode, struct file *file)
{
spin_lock(&xen_mce_chrdev_state_lock);
if (xen_mce_chrdev_open_exclu ||
(xen_mce_chrdev_open_count && (file->f_flags & O_EXCL))) {
spin_unlock(&xen_mce_chrdev_state_lock);
return -EBUSY;
}
if (file->f_flags & O_EXCL)
xen_mce_chrdev_open_exclu = 1;
xen_mce_chrdev_open_count++;
spin_unlock(&xen_mce_chrdev_state_lock);
return nonseekable_open(inode, file);
}
static int xen_mce_chrdev_release(struct inode *inode, struct file *file)
{
spin_lock(&xen_mce_chrdev_state_lock);
xen_mce_chrdev_open_count--;
xen_mce_chrdev_open_exclu = 0;
spin_unlock(&xen_mce_chrdev_state_lock);
return 0;
}
static ssize_t xen_mce_chrdev_read(struct file *filp, char __user *ubuf,
size_t usize, loff_t *off)
{
char __user *buf = ubuf;
unsigned num;
int i, err;
mutex_lock(&mcelog_lock);
num = xen_mcelog.next;
err = -EINVAL;
if (*off != 0 || usize < XEN_MCE_LOG_LEN*sizeof(struct xen_mce))
goto out;
err = 0;
for (i = 0; i < num; i++) {
struct xen_mce *m = &xen_mcelog.entry[i];
err |= copy_to_user(buf, m, sizeof(*m));
buf += sizeof(*m);
}
memset(xen_mcelog.entry, 0, num * sizeof(struct xen_mce));
xen_mcelog.next = 0;
if (err)
err = -EFAULT;
out:
mutex_unlock(&mcelog_lock);
return err ? err : buf - ubuf;
}
static unsigned int xen_mce_chrdev_poll(struct file *file, poll_table *wait)
{
poll_wait(file, &xen_mce_chrdev_wait, wait);
if (xen_mcelog.next)
return POLLIN | POLLRDNORM;
return 0;
}
static long xen_mce_chrdev_ioctl(struct file *f, unsigned int cmd,
unsigned long arg)
{
int __user *p = (int __user *)arg;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
switch (cmd) {
case MCE_GET_RECORD_LEN:
return put_user(sizeof(struct xen_mce), p);
case MCE_GET_LOG_LEN:
return put_user(XEN_MCE_LOG_LEN, p);
case MCE_GETCLEAR_FLAGS: {
unsigned flags;
do {
flags = xen_mcelog.flags;
} while (cmpxchg(&xen_mcelog.flags, flags, 0) != flags);
return put_user(flags, p);
}
default:
return -ENOTTY;
}
}
static void xen_mce_log(struct xen_mce *mce)
{
unsigned entry;
entry = xen_mcelog.next;
if (entry >= XEN_MCE_LOG_LEN) {
set_bit(XEN_MCE_OVERFLOW,
(unsigned long *)&xen_mcelog.flags);
return;
}
memcpy(xen_mcelog.entry + entry, mce, sizeof(struct xen_mce));
xen_mcelog.next++;
}
static int convert_log(struct mc_info *mi)
{
struct mcinfo_common *mic;
struct mcinfo_global *mc_global;
struct mcinfo_bank *mc_bank;
struct xen_mce m;
uint32_t i;
mic = NULL;
x86_mcinfo_lookup(&mic, mi, MC_TYPE_GLOBAL);
if (unlikely(!mic)) {
pr_warn("Failed to find global error info\n");
return -ENODEV;
}
memset(&m, 0, sizeof(struct xen_mce));
mc_global = (struct mcinfo_global *)mic;
m.mcgstatus = mc_global->mc_gstatus;
m.apicid = mc_global->mc_apicid;
for (i = 0; i < ncpus; i++)
if (g_physinfo[i].mc_apicid == m.apicid)
break;
if (unlikely(i == ncpus)) {
pr_warn("Failed to match cpu with apicid %d\n", m.apicid);
return -ENODEV;
}
m.socketid = g_physinfo[i].mc_chipid;
m.cpu = m.extcpu = g_physinfo[i].mc_cpunr;
m.cpuvendor = (__u8)g_physinfo[i].mc_vendor;
m.mcgcap = g_physinfo[i].mc_msrvalues[__MC_MSR_MCGCAP].value;
mic = NULL;
x86_mcinfo_lookup(&mic, mi, MC_TYPE_BANK);
if (unlikely(!mic)) {
pr_warn("Fail to find bank error info\n");
return -ENODEV;
}
do {
if ((!mic) || (mic->size == 0) ||
(mic->type != MC_TYPE_GLOBAL &&
mic->type != MC_TYPE_BANK &&
mic->type != MC_TYPE_EXTENDED &&
mic->type != MC_TYPE_RECOVERY))
break;
if (mic->type == MC_TYPE_BANK) {
mc_bank = (struct mcinfo_bank *)mic;
m.misc = mc_bank->mc_misc;
m.status = mc_bank->mc_status;
m.addr = mc_bank->mc_addr;
m.tsc = mc_bank->mc_tsc;
m.bank = mc_bank->mc_bank;
m.finished = 1;
xen_mce_log(&m);
}
mic = x86_mcinfo_next(mic);
} while (1);
return 0;
}
static int mc_queue_handle(uint32_t flags)
{
struct xen_mc mc_op;
int ret = 0;
mc_op.cmd = XEN_MC_fetch;
mc_op.interface_version = XEN_MCA_INTERFACE_VERSION;
set_xen_guest_handle(mc_op.u.mc_fetch.data, &g_mi);
do {
mc_op.u.mc_fetch.flags = flags;
ret = HYPERVISOR_mca(&mc_op);
if (ret) {
pr_err("Failed to fetch %surgent error log\n",
flags == XEN_MC_URGENT ? "" : "non");
break;
}
if (mc_op.u.mc_fetch.flags & XEN_MC_NODATA ||
mc_op.u.mc_fetch.flags & XEN_MC_FETCHFAILED)
break;
else {
ret = convert_log(&g_mi);
if (ret)
pr_warn("Failed to convert this error log, continue acking it anyway\n");
mc_op.u.mc_fetch.flags = flags | XEN_MC_ACK;
ret = HYPERVISOR_mca(&mc_op);
if (ret) {
pr_err("Failed to ack previous error log\n");
break;
}
}
} while (1);
return ret;
}
static void xen_mce_work_fn(struct work_struct *work)
{
int err;
mutex_lock(&mcelog_lock);
err = mc_queue_handle(XEN_MC_URGENT);
if (err)
pr_err("Failed to handle urgent mc_info queue, continue handling nonurgent mc_info queue anyway\n");
err = mc_queue_handle(XEN_MC_NONURGENT);
if (err)
pr_err("Failed to handle nonurgent mc_info queue\n");
wake_up_interruptible(&xen_mce_chrdev_wait);
mutex_unlock(&mcelog_lock);
}
static irqreturn_t xen_mce_interrupt(int irq, void *dev_id)
{
schedule_work(&xen_mce_work);
return IRQ_HANDLED;
}
static int bind_virq_for_mce(void)
{
int ret;
struct xen_mc mc_op;
memset(&mc_op, 0, sizeof(struct xen_mc));
mc_op.cmd = XEN_MC_physcpuinfo;
mc_op.interface_version = XEN_MCA_INTERFACE_VERSION;
set_xen_guest_handle(mc_op.u.mc_physcpuinfo.info, g_physinfo);
ret = HYPERVISOR_mca(&mc_op);
if (ret) {
pr_err("Failed to get CPU numbers\n");
return ret;
}
ncpus = mc_op.u.mc_physcpuinfo.ncpus;
g_physinfo = kcalloc(ncpus, sizeof(struct mcinfo_logical_cpu),
GFP_KERNEL);
if (!g_physinfo)
return -ENOMEM;
set_xen_guest_handle(mc_op.u.mc_physcpuinfo.info, g_physinfo);
ret = HYPERVISOR_mca(&mc_op);
if (ret) {
pr_err("Failed to get CPU info\n");
kfree(g_physinfo);
return ret;
}
ret = bind_virq_to_irqhandler(VIRQ_MCA, 0,
xen_mce_interrupt, 0, "mce", NULL);
if (ret < 0) {
pr_err("Failed to bind virq\n");
kfree(g_physinfo);
return ret;
}
return 0;
}
static int __init xen_late_init_mcelog(void)
{
if (xen_initial_domain()) {
if (misc_register(&xen_mce_chrdev_device))
return -ENODEV;
return bind_virq_for_mce();
}
return -ENODEV;
}
