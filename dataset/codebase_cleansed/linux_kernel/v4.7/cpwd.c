static void cpwd_writew(u16 val, void __iomem *addr)
{
writew(cpu_to_le16(val), addr);
}
static u16 cpwd_readw(void __iomem *addr)
{
u16 val = readw(addr);
return le16_to_cpu(val);
}
static void cpwd_writeb(u8 val, void __iomem *addr)
{
writeb(val, addr);
}
static u8 cpwd_readb(void __iomem *addr)
{
return readb(addr);
}
static void cpwd_toggleintr(struct cpwd *p, int index, int enable)
{
unsigned char curregs = cpwd_readb(p->regs + PLD_IMASK);
unsigned char setregs =
(index == -1) ?
(WD0_INTR_MASK | WD1_INTR_MASK | WD2_INTR_MASK) :
(p->devs[index].intr_mask);
if (enable == WD_INTR_ON)
curregs &= ~setregs;
else
curregs |= setregs;
cpwd_writeb(curregs, p->regs + PLD_IMASK);
}
static void cpwd_resetbrokentimer(struct cpwd *p, int index)
{
cpwd_toggleintr(p, index, WD_INTR_ON);
cpwd_writew(WD_BLIMIT, p->devs[index].regs + WD_LIMIT);
}
static void cpwd_brokentimer(unsigned long data)
{
struct cpwd *p = (struct cpwd *) data;
int id, tripped = 0;
if (timer_pending(&cpwd_timer))
del_timer(&cpwd_timer);
for (id = 0; id < WD_NUMDEVS; id++) {
if (p->devs[id].runstatus & WD_STAT_BSTOP) {
++tripped;
cpwd_resetbrokentimer(p, id);
}
}
if (tripped) {
cpwd_timer.expires = WD_BTIMEOUT;
add_timer(&cpwd_timer);
}
}
static void cpwd_pingtimer(struct cpwd *p, int index)
{
if (cpwd_readb(p->devs[index].regs + WD_STATUS) & WD_S_RUNNING)
cpwd_readw(p->devs[index].regs + WD_DCNTR);
}
static void cpwd_stoptimer(struct cpwd *p, int index)
{
if (cpwd_readb(p->devs[index].regs + WD_STATUS) & WD_S_RUNNING) {
cpwd_toggleintr(p, index, WD_INTR_OFF);
if (p->broken) {
p->devs[index].runstatus |= WD_STAT_BSTOP;
cpwd_brokentimer((unsigned long) p);
}
}
}
static void cpwd_starttimer(struct cpwd *p, int index)
{
if (p->broken)
p->devs[index].runstatus &= ~WD_STAT_BSTOP;
p->devs[index].runstatus &= ~WD_STAT_SVCD;
cpwd_writew(p->devs[index].timeout, p->devs[index].regs + WD_LIMIT);
cpwd_toggleintr(p, index, WD_INTR_ON);
}
static int cpwd_getstatus(struct cpwd *p, int index)
{
unsigned char stat = cpwd_readb(p->devs[index].regs + WD_STATUS);
unsigned char intr = cpwd_readb(p->devs[index].regs + PLD_IMASK);
unsigned char ret = WD_STOPPED;
if (!stat)
return ret;
else if (WD_S_EXPIRED & stat) {
ret = WD_EXPIRED;
} else if (WD_S_RUNNING & stat) {
if (intr & p->devs[index].intr_mask) {
ret = WD_FREERUN;
} else {
if (p->broken &&
(p->devs[index].runstatus & WD_STAT_BSTOP)) {
if (p->devs[index].runstatus & WD_STAT_SVCD) {
ret = WD_EXPIRED;
} else {
ret = WD_FREERUN;
}
} else {
ret = WD_RUNNING;
}
}
}
if (p->devs[index].runstatus & WD_STAT_SVCD)
ret |= WD_SERVICED;
return ret;
}
static irqreturn_t cpwd_interrupt(int irq, void *dev_id)
{
struct cpwd *p = dev_id;
spin_lock_irq(&p->lock);
cpwd_stoptimer(p, WD0_ID);
p->devs[WD0_ID].runstatus |= WD_STAT_SVCD;
spin_unlock_irq(&p->lock);
return IRQ_HANDLED;
}
static int cpwd_open(struct inode *inode, struct file *f)
{
struct cpwd *p = cpwd_device;
mutex_lock(&cpwd_mutex);
switch (iminor(inode)) {
case WD0_MINOR:
case WD1_MINOR:
case WD2_MINOR:
break;
default:
mutex_unlock(&cpwd_mutex);
return -ENODEV;
}
if (!p->initialized) {
if (request_irq(p->irq, &cpwd_interrupt,
IRQF_SHARED, DRIVER_NAME, p)) {
pr_err("Cannot register IRQ %d\n", p->irq);
mutex_unlock(&cpwd_mutex);
return -EBUSY;
}
p->initialized = true;
}
mutex_unlock(&cpwd_mutex);
return nonseekable_open(inode, f);
}
static int cpwd_release(struct inode *inode, struct file *file)
{
return 0;
}
static long cpwd_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
static const struct watchdog_info info = {
.options = WDIOF_SETTIMEOUT,
.firmware_version = 1,
.identity = DRIVER_NAME,
};
void __user *argp = (void __user *)arg;
struct inode *inode = file_inode(file);
int index = iminor(inode) - WD0_MINOR;
struct cpwd *p = cpwd_device;
int setopt = 0;
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &info, sizeof(struct watchdog_info)))
return -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
if (put_user(0, (int __user *)argp))
return -EFAULT;
break;
case WDIOC_KEEPALIVE:
cpwd_pingtimer(p, index);
break;
case WDIOC_SETOPTIONS:
if (copy_from_user(&setopt, argp, sizeof(unsigned int)))
return -EFAULT;
if (setopt & WDIOS_DISABLECARD) {
if (p->enabled)
return -EINVAL;
cpwd_stoptimer(p, index);
} else if (setopt & WDIOS_ENABLECARD) {
cpwd_starttimer(p, index);
} else {
return -EINVAL;
}
break;
case WIOCGSTAT:
setopt = cpwd_getstatus(p, index);
if (copy_to_user(argp, &setopt, sizeof(unsigned int)))
return -EFAULT;
break;
case WIOCSTART:
cpwd_starttimer(p, index);
break;
case WIOCSTOP:
if (p->enabled)
return -EINVAL;
cpwd_stoptimer(p, index);
break;
default:
return -EINVAL;
}
return 0;
}
static long cpwd_compat_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int rval = -ENOIOCTLCMD;
switch (cmd) {
case WIOCSTART:
case WIOCSTOP:
case WIOCGSTAT:
mutex_lock(&cpwd_mutex);
rval = cpwd_ioctl(file, cmd, arg);
mutex_unlock(&cpwd_mutex);
break;
default:
break;
}
return rval;
}
static ssize_t cpwd_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct inode *inode = file_inode(file);
struct cpwd *p = cpwd_device;
int index = iminor(inode);
if (count) {
cpwd_pingtimer(p, index);
return 1;
}
return 0;
}
static ssize_t cpwd_read(struct file *file, char __user *buffer,
size_t count, loff_t *ppos)
{
return -EINVAL;
}
static int cpwd_probe(struct platform_device *op)
{
struct device_node *options;
const char *str_prop;
const void *prop_val;
int i, err = -EINVAL;
struct cpwd *p;
if (cpwd_device)
return -EINVAL;
p = kzalloc(sizeof(*p), GFP_KERNEL);
err = -ENOMEM;
if (!p) {
pr_err("Unable to allocate struct cpwd\n");
goto out;
}
p->irq = op->archdata.irqs[0];
spin_lock_init(&p->lock);
p->regs = of_ioremap(&op->resource[0], 0,
4 * WD_TIMER_REGSZ, DRIVER_NAME);
if (!p->regs) {
pr_err("Unable to map registers\n");
goto out_free;
}
options = of_find_node_by_path("/options");
err = -ENODEV;
if (!options) {
pr_err("Unable to find /options node\n");
goto out_iounmap;
}
prop_val = of_get_property(options, "watchdog-enable?", NULL);
p->enabled = (prop_val ? true : false);
prop_val = of_get_property(options, "watchdog-reboot?", NULL);
p->reboot = (prop_val ? true : false);
str_prop = of_get_property(options, "watchdog-timeout", NULL);
if (str_prop)
p->timeout = simple_strtoul(str_prop, NULL, 10);
str_prop = of_get_property(op->dev.of_node, "model", NULL);
p->broken = (str_prop && !strcmp(str_prop, WD_BADMODEL));
if (!p->enabled)
cpwd_toggleintr(p, -1, WD_INTR_OFF);
for (i = 0; i < WD_NUMDEVS; i++) {
static const char *cpwd_names[] = { "RIC", "XIR", "POR" };
static int *parms[] = { &wd0_timeout,
&wd1_timeout,
&wd2_timeout };
struct miscdevice *mp = &p->devs[i].misc;
mp->minor = WD0_MINOR + i;
mp->name = cpwd_names[i];
mp->fops = &cpwd_fops;
p->devs[i].regs = p->regs + (i * WD_TIMER_REGSZ);
p->devs[i].intr_mask = (WD0_INTR_MASK << i);
p->devs[i].runstatus &= ~WD_STAT_BSTOP;
p->devs[i].runstatus |= WD_STAT_INIT;
p->devs[i].timeout = p->timeout;
if (*parms[i])
p->devs[i].timeout = *parms[i];
err = misc_register(&p->devs[i].misc);
if (err) {
pr_err("Could not register misc device for dev %d\n",
i);
goto out_unregister;
}
}
if (p->broken) {
setup_timer(&cpwd_timer, cpwd_brokentimer, (unsigned long)p);
cpwd_timer.expires = WD_BTIMEOUT;
pr_info("PLD defect workaround enabled for model %s\n",
WD_BADMODEL);
}
platform_set_drvdata(op, p);
cpwd_device = p;
err = 0;
out:
return err;
out_unregister:
for (i--; i >= 0; i--)
misc_deregister(&p->devs[i].misc);
out_iounmap:
of_iounmap(&op->resource[0], p->regs, 4 * WD_TIMER_REGSZ);
out_free:
kfree(p);
goto out;
}
static int cpwd_remove(struct platform_device *op)
{
struct cpwd *p = platform_get_drvdata(op);
int i;
for (i = 0; i < WD_NUMDEVS; i++) {
misc_deregister(&p->devs[i].misc);
if (!p->enabled) {
cpwd_stoptimer(p, i);
if (p->devs[i].runstatus & WD_STAT_BSTOP)
cpwd_resetbrokentimer(p, i);
}
}
if (p->broken)
del_timer_sync(&cpwd_timer);
if (p->initialized)
free_irq(p->irq, p);
of_iounmap(&op->resource[0], p->regs, 4 * WD_TIMER_REGSZ);
kfree(p);
cpwd_device = NULL;
return 0;
}
