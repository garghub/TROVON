static u64 read_hpet(struct clocksource *cs)
{
return (u64)read_counter((void __iomem *)hpet_mctr);
}
static inline unsigned long long readq(void __iomem *addr)
{
return readl(addr) | (((unsigned long long)readl(addr + 4)) << 32LL);
}
static inline void writeq(unsigned long long v, void __iomem *addr)
{
writel(v & 0xffffffff, addr);
writel(v >> 32, addr + 4);
}
static irqreturn_t hpet_interrupt(int irq, void *data)
{
struct hpet_dev *devp;
unsigned long isr;
devp = data;
isr = 1 << (devp - devp->hd_hpets->hp_dev);
if ((devp->hd_flags & HPET_SHARED_IRQ) &&
!(isr & readl(&devp->hd_hpet->hpet_isr)))
return IRQ_NONE;
spin_lock(&hpet_lock);
devp->hd_irqdata++;
if ((devp->hd_flags & (HPET_IE | HPET_PERIODIC)) == HPET_IE) {
unsigned long m, t, mc, base, k;
struct hpet __iomem *hpet = devp->hd_hpet;
struct hpets *hpetp = devp->hd_hpets;
t = devp->hd_ireqfreq;
m = read_counter(&devp->hd_timer->hpet_compare);
mc = read_counter(&hpet->hpet_mc);
base = mc % t;
k = (mc - base + hpetp->hp_delta) / t;
write_counter(t * (k + 1) + base,
&devp->hd_timer->hpet_compare);
}
if (devp->hd_flags & HPET_SHARED_IRQ)
writel(isr, &devp->hd_hpet->hpet_isr);
spin_unlock(&hpet_lock);
wake_up_interruptible(&devp->hd_waitqueue);
kill_fasync(&devp->hd_async_queue, SIGIO, POLL_IN);
return IRQ_HANDLED;
}
static void hpet_timer_set_irq(struct hpet_dev *devp)
{
unsigned long v;
int irq, gsi;
struct hpet_timer __iomem *timer;
spin_lock_irq(&hpet_lock);
if (devp->hd_hdwirq) {
spin_unlock_irq(&hpet_lock);
return;
}
timer = devp->hd_timer;
v = readl(&timer->hpet_config);
if (!(v & Tn_INT_TYPE_CNF_MASK)) {
v |= Tn_INT_TYPE_CNF_MASK;
writel(v, &timer->hpet_config);
}
spin_unlock_irq(&hpet_lock);
v = (readq(&timer->hpet_config) & Tn_INT_ROUTE_CAP_MASK) >>
Tn_INT_ROUTE_CAP_SHIFT;
if (acpi_irq_model == ACPI_IRQ_MODEL_PIC)
v &= ~0xf3df;
else
v &= ~0xffff;
for_each_set_bit(irq, &v, HPET_MAX_IRQ) {
if (irq >= nr_irqs) {
irq = HPET_MAX_IRQ;
break;
}
gsi = acpi_register_gsi(NULL, irq, ACPI_LEVEL_SENSITIVE,
ACPI_ACTIVE_LOW);
if (gsi > 0)
break;
}
if (irq < HPET_MAX_IRQ) {
spin_lock_irq(&hpet_lock);
v = readl(&timer->hpet_config);
v |= irq << Tn_INT_ROUTE_CNF_SHIFT;
writel(v, &timer->hpet_config);
devp->hd_hdwirq = gsi;
spin_unlock_irq(&hpet_lock);
}
return;
}
static int hpet_open(struct inode *inode, struct file *file)
{
struct hpet_dev *devp;
struct hpets *hpetp;
int i;
if (file->f_mode & FMODE_WRITE)
return -EINVAL;
mutex_lock(&hpet_mutex);
spin_lock_irq(&hpet_lock);
for (devp = NULL, hpetp = hpets; hpetp && !devp; hpetp = hpetp->hp_next)
for (i = 0; i < hpetp->hp_ntimer; i++)
if (hpetp->hp_dev[i].hd_flags & HPET_OPEN)
continue;
else {
devp = &hpetp->hp_dev[i];
break;
}
if (!devp) {
spin_unlock_irq(&hpet_lock);
mutex_unlock(&hpet_mutex);
return -EBUSY;
}
file->private_data = devp;
devp->hd_irqdata = 0;
devp->hd_flags |= HPET_OPEN;
spin_unlock_irq(&hpet_lock);
mutex_unlock(&hpet_mutex);
hpet_timer_set_irq(devp);
return 0;
}
static ssize_t
hpet_read(struct file *file, char __user *buf, size_t count, loff_t * ppos)
{
DECLARE_WAITQUEUE(wait, current);
unsigned long data;
ssize_t retval;
struct hpet_dev *devp;
devp = file->private_data;
if (!devp->hd_ireqfreq)
return -EIO;
if (count < sizeof(unsigned long))
return -EINVAL;
add_wait_queue(&devp->hd_waitqueue, &wait);
for ( ; ; ) {
set_current_state(TASK_INTERRUPTIBLE);
spin_lock_irq(&hpet_lock);
data = devp->hd_irqdata;
devp->hd_irqdata = 0;
spin_unlock_irq(&hpet_lock);
if (data)
break;
else if (file->f_flags & O_NONBLOCK) {
retval = -EAGAIN;
goto out;
} else if (signal_pending(current)) {
retval = -ERESTARTSYS;
goto out;
}
schedule();
}
retval = put_user(data, (unsigned long __user *)buf);
if (!retval)
retval = sizeof(unsigned long);
out:
__set_current_state(TASK_RUNNING);
remove_wait_queue(&devp->hd_waitqueue, &wait);
return retval;
}
static unsigned int hpet_poll(struct file *file, poll_table * wait)
{
unsigned long v;
struct hpet_dev *devp;
devp = file->private_data;
if (!devp->hd_ireqfreq)
return 0;
poll_wait(file, &devp->hd_waitqueue, wait);
spin_lock_irq(&hpet_lock);
v = devp->hd_irqdata;
spin_unlock_irq(&hpet_lock);
if (v != 0)
return POLLIN | POLLRDNORM;
return 0;
}
static __init int hpet_mmap_enable(char *str)
{
get_option(&str, &hpet_mmap_enabled);
pr_info("HPET mmap %s\n", hpet_mmap_enabled ? "enabled" : "disabled");
return 1;
}
static int hpet_mmap(struct file *file, struct vm_area_struct *vma)
{
struct hpet_dev *devp;
unsigned long addr;
if (!hpet_mmap_enabled)
return -EACCES;
devp = file->private_data;
addr = devp->hd_hpets->hp_hpet_phys;
if (addr & (PAGE_SIZE - 1))
return -ENOSYS;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
return vm_iomap_memory(vma, addr, PAGE_SIZE);
}
static int hpet_mmap(struct file *file, struct vm_area_struct *vma)
{
return -ENOSYS;
}
static int hpet_fasync(int fd, struct file *file, int on)
{
struct hpet_dev *devp;
devp = file->private_data;
if (fasync_helper(fd, file, on, &devp->hd_async_queue) >= 0)
return 0;
else
return -EIO;
}
static int hpet_release(struct inode *inode, struct file *file)
{
struct hpet_dev *devp;
struct hpet_timer __iomem *timer;
int irq = 0;
devp = file->private_data;
timer = devp->hd_timer;
spin_lock_irq(&hpet_lock);
writeq((readq(&timer->hpet_config) & ~Tn_INT_ENB_CNF_MASK),
&timer->hpet_config);
irq = devp->hd_irq;
devp->hd_irq = 0;
devp->hd_ireqfreq = 0;
if (devp->hd_flags & HPET_PERIODIC
&& readq(&timer->hpet_config) & Tn_TYPE_CNF_MASK) {
unsigned long v;
v = readq(&timer->hpet_config);
v ^= Tn_TYPE_CNF_MASK;
writeq(v, &timer->hpet_config);
}
devp->hd_flags &= ~(HPET_OPEN | HPET_IE | HPET_PERIODIC);
spin_unlock_irq(&hpet_lock);
if (irq)
free_irq(irq, devp);
file->private_data = NULL;
return 0;
}
static int hpet_ioctl_ieon(struct hpet_dev *devp)
{
struct hpet_timer __iomem *timer;
struct hpet __iomem *hpet;
struct hpets *hpetp;
int irq;
unsigned long g, v, t, m;
unsigned long flags, isr;
timer = devp->hd_timer;
hpet = devp->hd_hpet;
hpetp = devp->hd_hpets;
if (!devp->hd_ireqfreq)
return -EIO;
spin_lock_irq(&hpet_lock);
if (devp->hd_flags & HPET_IE) {
spin_unlock_irq(&hpet_lock);
return -EBUSY;
}
devp->hd_flags |= HPET_IE;
if (readl(&timer->hpet_config) & Tn_INT_TYPE_CNF_MASK)
devp->hd_flags |= HPET_SHARED_IRQ;
spin_unlock_irq(&hpet_lock);
irq = devp->hd_hdwirq;
if (irq) {
unsigned long irq_flags;
if (devp->hd_flags & HPET_SHARED_IRQ) {
writel(readl(&timer->hpet_config) & ~Tn_TYPE_CNF_MASK,
&timer->hpet_config);
write_counter(read_counter(&hpet->hpet_mc),
&timer->hpet_compare);
isr = 1 << (devp - devp->hd_hpets->hp_dev);
writel(isr, &hpet->hpet_isr);
}
sprintf(devp->hd_name, "hpet%d", (int)(devp - hpetp->hp_dev));
irq_flags = devp->hd_flags & HPET_SHARED_IRQ ? IRQF_SHARED : 0;
if (request_irq(irq, hpet_interrupt, irq_flags,
devp->hd_name, (void *)devp)) {
printk(KERN_ERR "hpet: IRQ %d is not free\n", irq);
irq = 0;
}
}
if (irq == 0) {
spin_lock_irq(&hpet_lock);
devp->hd_flags ^= HPET_IE;
spin_unlock_irq(&hpet_lock);
return -EIO;
}
devp->hd_irq = irq;
t = devp->hd_ireqfreq;
v = readq(&timer->hpet_config);
g = v | Tn_32MODE_CNF_MASK | Tn_INT_ENB_CNF_MASK;
if (devp->hd_flags & HPET_PERIODIC) {
g |= Tn_TYPE_CNF_MASK;
v |= Tn_TYPE_CNF_MASK | Tn_VAL_SET_CNF_MASK;
writeq(v, &timer->hpet_config);
local_irq_save(flags);
m = read_counter(&hpet->hpet_mc);
write_counter(t + m + hpetp->hp_delta, &timer->hpet_compare);
write_counter(t, &timer->hpet_compare);
} else {
local_irq_save(flags);
m = read_counter(&hpet->hpet_mc);
write_counter(t + m + hpetp->hp_delta, &timer->hpet_compare);
}
if (devp->hd_flags & HPET_SHARED_IRQ) {
isr = 1 << (devp - devp->hd_hpets->hp_dev);
writel(isr, &hpet->hpet_isr);
}
writeq(g, &timer->hpet_config);
local_irq_restore(flags);
return 0;
}
static inline unsigned long hpet_time_div(struct hpets *hpets,
unsigned long dis)
{
unsigned long long m;
m = hpets->hp_tick_freq + (dis >> 1);
do_div(m, dis);
return (unsigned long)m;
}
static int
hpet_ioctl_common(struct hpet_dev *devp, unsigned int cmd, unsigned long arg,
struct hpet_info *info)
{
struct hpet_timer __iomem *timer;
struct hpet __iomem *hpet;
struct hpets *hpetp;
int err;
unsigned long v;
switch (cmd) {
case HPET_IE_OFF:
case HPET_INFO:
case HPET_EPI:
case HPET_DPI:
case HPET_IRQFREQ:
timer = devp->hd_timer;
hpet = devp->hd_hpet;
hpetp = devp->hd_hpets;
break;
case HPET_IE_ON:
return hpet_ioctl_ieon(devp);
default:
return -EINVAL;
}
err = 0;
switch (cmd) {
case HPET_IE_OFF:
if ((devp->hd_flags & HPET_IE) == 0)
break;
v = readq(&timer->hpet_config);
v &= ~Tn_INT_ENB_CNF_MASK;
writeq(v, &timer->hpet_config);
if (devp->hd_irq) {
free_irq(devp->hd_irq, devp);
devp->hd_irq = 0;
}
devp->hd_flags ^= HPET_IE;
break;
case HPET_INFO:
{
memset(info, 0, sizeof(*info));
if (devp->hd_ireqfreq)
info->hi_ireqfreq =
hpet_time_div(hpetp, devp->hd_ireqfreq);
info->hi_flags =
readq(&timer->hpet_config) & Tn_PER_INT_CAP_MASK;
info->hi_hpet = hpetp->hp_which;
info->hi_timer = devp - hpetp->hp_dev;
break;
}
case HPET_EPI:
v = readq(&timer->hpet_config);
if ((v & Tn_PER_INT_CAP_MASK) == 0) {
err = -ENXIO;
break;
}
devp->hd_flags |= HPET_PERIODIC;
break;
case HPET_DPI:
v = readq(&timer->hpet_config);
if ((v & Tn_PER_INT_CAP_MASK) == 0) {
err = -ENXIO;
break;
}
if (devp->hd_flags & HPET_PERIODIC &&
readq(&timer->hpet_config) & Tn_TYPE_CNF_MASK) {
v = readq(&timer->hpet_config);
v ^= Tn_TYPE_CNF_MASK;
writeq(v, &timer->hpet_config);
}
devp->hd_flags &= ~HPET_PERIODIC;
break;
case HPET_IRQFREQ:
if ((arg > hpet_max_freq) &&
!capable(CAP_SYS_RESOURCE)) {
err = -EACCES;
break;
}
if (!arg) {
err = -EINVAL;
break;
}
devp->hd_ireqfreq = hpet_time_div(hpetp, arg);
}
return err;
}
static long
hpet_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct hpet_info info;
int err;
mutex_lock(&hpet_mutex);
err = hpet_ioctl_common(file->private_data, cmd, arg, &info);
mutex_unlock(&hpet_mutex);
if ((cmd == HPET_INFO) && !err &&
(copy_to_user((void __user *)arg, &info, sizeof(info))))
err = -EFAULT;
return err;
}
static long
hpet_compat_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct hpet_info info;
int err;
mutex_lock(&hpet_mutex);
err = hpet_ioctl_common(file->private_data, cmd, arg, &info);
mutex_unlock(&hpet_mutex);
if ((cmd == HPET_INFO) && !err) {
struct compat_hpet_info __user *u = compat_ptr(arg);
if (put_user(info.hi_ireqfreq, &u->hi_ireqfreq) ||
put_user(info.hi_flags, &u->hi_flags) ||
put_user(info.hi_hpet, &u->hi_hpet) ||
put_user(info.hi_timer, &u->hi_timer))
err = -EFAULT;
}
return err;
}
static int hpet_is_known(struct hpet_data *hdp)
{
struct hpets *hpetp;
for (hpetp = hpets; hpetp; hpetp = hpetp->hp_next)
if (hpetp->hp_hpet_phys == hdp->hd_phys_address)
return 1;
return 0;
}
static unsigned long __hpet_calibrate(struct hpets *hpetp)
{
struct hpet_timer __iomem *timer = NULL;
unsigned long t, m, count, i, flags, start;
struct hpet_dev *devp;
int j;
struct hpet __iomem *hpet;
for (j = 0, devp = hpetp->hp_dev; j < hpetp->hp_ntimer; j++, devp++)
if ((devp->hd_flags & HPET_OPEN) == 0) {
timer = devp->hd_timer;
break;
}
if (!timer)
return 0;
hpet = hpetp->hp_hpet;
t = read_counter(&timer->hpet_compare);
i = 0;
count = hpet_time_div(hpetp, TICK_CALIBRATE);
local_irq_save(flags);
start = read_counter(&hpet->hpet_mc);
do {
m = read_counter(&hpet->hpet_mc);
write_counter(t + m + hpetp->hp_delta, &timer->hpet_compare);
} while (i++, (m - start) < count);
local_irq_restore(flags);
return (m - start) / i;
}
static unsigned long hpet_calibrate(struct hpets *hpetp)
{
unsigned long ret = ~0UL;
unsigned long tmp;
for ( ; ; ) {
tmp = __hpet_calibrate(hpetp);
if (ret <= tmp)
break;
ret = tmp;
}
return ret;
}
int hpet_alloc(struct hpet_data *hdp)
{
u64 cap, mcfg;
struct hpet_dev *devp;
u32 i, ntimer;
struct hpets *hpetp;
size_t siz;
struct hpet __iomem *hpet;
static struct hpets *last;
unsigned long period;
unsigned long long temp;
u32 remainder;
if (hpet_is_known(hdp)) {
printk(KERN_DEBUG "%s: duplicate HPET ignored\n",
__func__);
return 0;
}
siz = sizeof(struct hpets) + ((hdp->hd_nirqs - 1) *
sizeof(struct hpet_dev));
hpetp = kzalloc(siz, GFP_KERNEL);
if (!hpetp)
return -ENOMEM;
hpetp->hp_which = hpet_nhpet++;
hpetp->hp_hpet = hdp->hd_address;
hpetp->hp_hpet_phys = hdp->hd_phys_address;
hpetp->hp_ntimer = hdp->hd_nirqs;
for (i = 0; i < hdp->hd_nirqs; i++)
hpetp->hp_dev[i].hd_hdwirq = hdp->hd_irq[i];
hpet = hpetp->hp_hpet;
cap = readq(&hpet->hpet_cap);
ntimer = ((cap & HPET_NUM_TIM_CAP_MASK) >> HPET_NUM_TIM_CAP_SHIFT) + 1;
if (hpetp->hp_ntimer != ntimer) {
printk(KERN_WARNING "hpet: number irqs doesn't agree"
" with number of timers\n");
kfree(hpetp);
return -ENODEV;
}
if (last)
last->hp_next = hpetp;
else
hpets = hpetp;
last = hpetp;
period = (cap & HPET_COUNTER_CLK_PERIOD_MASK) >>
HPET_COUNTER_CLK_PERIOD_SHIFT;
temp = 1000000000000000uLL;
temp += period >> 1;
do_div(temp, period);
hpetp->hp_tick_freq = temp;
printk(KERN_INFO "hpet%d: at MMIO 0x%lx, IRQ%s",
hpetp->hp_which, hdp->hd_phys_address,
hpetp->hp_ntimer > 1 ? "s" : "");
for (i = 0; i < hpetp->hp_ntimer; i++)
printk(KERN_CONT "%s %d", i > 0 ? "," : "", hdp->hd_irq[i]);
printk(KERN_CONT "\n");
temp = hpetp->hp_tick_freq;
remainder = do_div(temp, 1000000);
printk(KERN_INFO
"hpet%u: %u comparators, %d-bit %u.%06u MHz counter\n",
hpetp->hp_which, hpetp->hp_ntimer,
cap & HPET_COUNTER_SIZE_MASK ? 64 : 32,
(unsigned) temp, remainder);
mcfg = readq(&hpet->hpet_config);
if ((mcfg & HPET_ENABLE_CNF_MASK) == 0) {
write_counter(0L, &hpet->hpet_mc);
mcfg |= HPET_ENABLE_CNF_MASK;
writeq(mcfg, &hpet->hpet_config);
}
for (i = 0, devp = hpetp->hp_dev; i < hpetp->hp_ntimer; i++, devp++) {
struct hpet_timer __iomem *timer;
timer = &hpet->hpet_timers[devp - hpetp->hp_dev];
devp->hd_hpets = hpetp;
devp->hd_hpet = hpet;
devp->hd_timer = timer;
if (hdp->hd_state & (1 << i)) {
devp->hd_flags = HPET_OPEN;
continue;
}
init_waitqueue_head(&devp->hd_waitqueue);
}
hpetp->hp_delta = hpet_calibrate(hpetp);
#ifdef CONFIG_IA64
if (!hpet_clocksource) {
hpet_mctr = (void __iomem *)&hpetp->hp_hpet->hpet_mc;
clocksource_hpet.archdata.fsys_mmio = hpet_mctr;
clocksource_register_hz(&clocksource_hpet, hpetp->hp_tick_freq);
hpetp->hp_clocksource = &clocksource_hpet;
hpet_clocksource = &clocksource_hpet;
}
#endif
return 0;
}
static acpi_status hpet_resources(struct acpi_resource *res, void *data)
{
struct hpet_data *hdp;
acpi_status status;
struct acpi_resource_address64 addr;
hdp = data;
status = acpi_resource_to_address64(res, &addr);
if (ACPI_SUCCESS(status)) {
hdp->hd_phys_address = addr.address.minimum;
hdp->hd_address = ioremap(addr.address.minimum, addr.address.address_length);
if (hpet_is_known(hdp)) {
iounmap(hdp->hd_address);
return AE_ALREADY_EXISTS;
}
} else if (res->type == ACPI_RESOURCE_TYPE_FIXED_MEMORY32) {
struct acpi_resource_fixed_memory32 *fixmem32;
fixmem32 = &res->data.fixed_memory32;
hdp->hd_phys_address = fixmem32->address;
hdp->hd_address = ioremap(fixmem32->address,
HPET_RANGE_SIZE);
if (hpet_is_known(hdp)) {
iounmap(hdp->hd_address);
return AE_ALREADY_EXISTS;
}
} else if (res->type == ACPI_RESOURCE_TYPE_EXTENDED_IRQ) {
struct acpi_resource_extended_irq *irqp;
int i, irq;
irqp = &res->data.extended_irq;
for (i = 0; i < irqp->interrupt_count; i++) {
if (hdp->hd_nirqs >= HPET_MAX_TIMERS)
break;
irq = acpi_register_gsi(NULL, irqp->interrupts[i],
irqp->triggering, irqp->polarity);
if (irq < 0)
return AE_ERROR;
hdp->hd_irq[hdp->hd_nirqs] = irq;
hdp->hd_nirqs++;
}
}
return AE_OK;
}
static int hpet_acpi_add(struct acpi_device *device)
{
acpi_status result;
struct hpet_data data;
memset(&data, 0, sizeof(data));
result =
acpi_walk_resources(device->handle, METHOD_NAME__CRS,
hpet_resources, &data);
if (ACPI_FAILURE(result))
return -ENODEV;
if (!data.hd_address || !data.hd_nirqs) {
if (data.hd_address)
iounmap(data.hd_address);
printk("%s: no address or irqs in _CRS\n", __func__);
return -ENODEV;
}
return hpet_alloc(&data);
}
static int __init hpet_init(void)
{
int result;
result = misc_register(&hpet_misc);
if (result < 0)
return -ENODEV;
sysctl_header = register_sysctl_table(dev_root);
result = acpi_bus_register_driver(&hpet_acpi_driver);
if (result < 0) {
if (sysctl_header)
unregister_sysctl_table(sysctl_header);
misc_deregister(&hpet_misc);
return result;
}
return 0;
}
