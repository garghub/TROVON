static void mpc52xx_gpt_irq_unmask(struct irq_data *d)
{
struct mpc52xx_gpt_priv *gpt = irq_data_get_irq_chip_data(d);
unsigned long flags;
spin_lock_irqsave(&gpt->lock, flags);
setbits32(&gpt->regs->mode, MPC52xx_GPT_MODE_IRQ_EN);
spin_unlock_irqrestore(&gpt->lock, flags);
}
static void mpc52xx_gpt_irq_mask(struct irq_data *d)
{
struct mpc52xx_gpt_priv *gpt = irq_data_get_irq_chip_data(d);
unsigned long flags;
spin_lock_irqsave(&gpt->lock, flags);
clrbits32(&gpt->regs->mode, MPC52xx_GPT_MODE_IRQ_EN);
spin_unlock_irqrestore(&gpt->lock, flags);
}
static void mpc52xx_gpt_irq_ack(struct irq_data *d)
{
struct mpc52xx_gpt_priv *gpt = irq_data_get_irq_chip_data(d);
out_be32(&gpt->regs->status, MPC52xx_GPT_STATUS_IRQMASK);
}
static int mpc52xx_gpt_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
struct mpc52xx_gpt_priv *gpt = irq_data_get_irq_chip_data(d);
unsigned long flags;
u32 reg;
dev_dbg(gpt->dev, "%s: virq=%i type=%x\n", __func__, d->irq, flow_type);
spin_lock_irqsave(&gpt->lock, flags);
reg = in_be32(&gpt->regs->mode) & ~MPC52xx_GPT_MODE_ICT_MASK;
if (flow_type & IRQF_TRIGGER_RISING)
reg |= MPC52xx_GPT_MODE_ICT_RISING;
if (flow_type & IRQF_TRIGGER_FALLING)
reg |= MPC52xx_GPT_MODE_ICT_FALLING;
out_be32(&gpt->regs->mode, reg);
spin_unlock_irqrestore(&gpt->lock, flags);
return 0;
}
void mpc52xx_gpt_irq_cascade(unsigned int virq, struct irq_desc *desc)
{
struct mpc52xx_gpt_priv *gpt = irq_get_handler_data(virq);
int sub_virq;
u32 status;
status = in_be32(&gpt->regs->status) & MPC52xx_GPT_STATUS_IRQMASK;
if (status) {
sub_virq = irq_linear_revmap(gpt->irqhost, 0);
generic_handle_irq(sub_virq);
}
}
static int mpc52xx_gpt_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct mpc52xx_gpt_priv *gpt = h->host_data;
dev_dbg(gpt->dev, "%s: h=%p, virq=%i\n", __func__, h, virq);
irq_set_chip_data(virq, gpt);
irq_set_chip_and_handler(virq, &mpc52xx_gpt_irq_chip, handle_edge_irq);
return 0;
}
static int mpc52xx_gpt_irq_xlate(struct irq_domain *h, struct device_node *ct,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq,
unsigned int *out_flags)
{
struct mpc52xx_gpt_priv *gpt = h->host_data;
dev_dbg(gpt->dev, "%s: flags=%i\n", __func__, intspec[0]);
if ((intsize < 1) || (intspec[0] > 3)) {
dev_err(gpt->dev, "bad irq specifier in %s\n", ct->full_name);
return -EINVAL;
}
*out_hwirq = 0;
*out_flags = intspec[0];
return 0;
}
static void
mpc52xx_gpt_irq_setup(struct mpc52xx_gpt_priv *gpt, struct device_node *node)
{
int cascade_virq;
unsigned long flags;
u32 mode;
cascade_virq = irq_of_parse_and_map(node, 0);
if (!cascade_virq)
return;
gpt->irqhost = irq_domain_add_linear(node, 1, &mpc52xx_gpt_irq_ops, gpt);
if (!gpt->irqhost) {
dev_err(gpt->dev, "irq_domain_add_linear() failed\n");
return;
}
irq_set_handler_data(cascade_virq, gpt);
irq_set_chained_handler(cascade_virq, mpc52xx_gpt_irq_cascade);
spin_lock_irqsave(&gpt->lock, flags);
mode = in_be32(&gpt->regs->mode);
if ((mode & MPC52xx_GPT_MODE_MS_MASK) == 0)
out_be32(&gpt->regs->mode, mode | MPC52xx_GPT_MODE_MS_IC);
spin_unlock_irqrestore(&gpt->lock, flags);
dev_dbg(gpt->dev, "%s() complete. virq=%i\n", __func__, cascade_virq);
}
static inline struct mpc52xx_gpt_priv *gc_to_mpc52xx_gpt(struct gpio_chip *gc)
{
return container_of(gc, struct mpc52xx_gpt_priv, gc);
}
static int mpc52xx_gpt_gpio_get(struct gpio_chip *gc, unsigned int gpio)
{
struct mpc52xx_gpt_priv *gpt = gc_to_mpc52xx_gpt(gc);
return (in_be32(&gpt->regs->status) >> 8) & 1;
}
static void
mpc52xx_gpt_gpio_set(struct gpio_chip *gc, unsigned int gpio, int v)
{
struct mpc52xx_gpt_priv *gpt = gc_to_mpc52xx_gpt(gc);
unsigned long flags;
u32 r;
dev_dbg(gpt->dev, "%s: gpio:%d v:%d\n", __func__, gpio, v);
r = v ? MPC52xx_GPT_MODE_GPIO_OUT_HIGH : MPC52xx_GPT_MODE_GPIO_OUT_LOW;
spin_lock_irqsave(&gpt->lock, flags);
clrsetbits_be32(&gpt->regs->mode, MPC52xx_GPT_MODE_GPIO_MASK, r);
spin_unlock_irqrestore(&gpt->lock, flags);
}
static int mpc52xx_gpt_gpio_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
struct mpc52xx_gpt_priv *gpt = gc_to_mpc52xx_gpt(gc);
unsigned long flags;
dev_dbg(gpt->dev, "%s: gpio:%d\n", __func__, gpio);
spin_lock_irqsave(&gpt->lock, flags);
clrbits32(&gpt->regs->mode, MPC52xx_GPT_MODE_GPIO_MASK);
spin_unlock_irqrestore(&gpt->lock, flags);
return 0;
}
static int
mpc52xx_gpt_gpio_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
mpc52xx_gpt_gpio_set(gc, gpio, val);
return 0;
}
static void
mpc52xx_gpt_gpio_setup(struct mpc52xx_gpt_priv *gpt, struct device_node *node)
{
int rc;
if (!of_find_property(node, "gpio-controller", NULL))
return;
gpt->gc.label = kstrdup(node->full_name, GFP_KERNEL);
if (!gpt->gc.label) {
dev_err(gpt->dev, "out of memory\n");
return;
}
gpt->gc.ngpio = 1;
gpt->gc.direction_input = mpc52xx_gpt_gpio_dir_in;
gpt->gc.direction_output = mpc52xx_gpt_gpio_dir_out;
gpt->gc.get = mpc52xx_gpt_gpio_get;
gpt->gc.set = mpc52xx_gpt_gpio_set;
gpt->gc.base = -1;
gpt->gc.of_node = node;
clrsetbits_be32(&gpt->regs->mode, MPC52xx_GPT_MODE_MS_MASK,
MPC52xx_GPT_MODE_MS_GPIO);
rc = gpiochip_add(&gpt->gc);
if (rc)
dev_err(gpt->dev, "gpiochip_add() failed; rc=%i\n", rc);
dev_dbg(gpt->dev, "%s() complete.\n", __func__);
}
static void
mpc52xx_gpt_gpio_setup(struct mpc52xx_gpt_priv *p, struct device_node *np) { }
struct mpc52xx_gpt_priv *mpc52xx_gpt_from_irq(int irq)
{
struct mpc52xx_gpt_priv *gpt;
struct list_head *pos;
mutex_lock(&mpc52xx_gpt_list_mutex);
list_for_each(pos, &mpc52xx_gpt_list) {
gpt = container_of(pos, struct mpc52xx_gpt_priv, list);
if (gpt->irqhost && irq == irq_linear_revmap(gpt->irqhost, 0)) {
mutex_unlock(&mpc52xx_gpt_list_mutex);
return gpt;
}
}
mutex_unlock(&mpc52xx_gpt_list_mutex);
return NULL;
}
static int mpc52xx_gpt_do_start(struct mpc52xx_gpt_priv *gpt, u64 period,
int continuous, int as_wdt)
{
u32 clear, set;
u64 clocks;
u32 prescale;
unsigned long flags;
clear = MPC52xx_GPT_MODE_MS_MASK | MPC52xx_GPT_MODE_CONTINUOUS;
set = MPC52xx_GPT_MODE_MS_GPIO | MPC52xx_GPT_MODE_COUNTER_ENABLE;
if (as_wdt) {
clear |= MPC52xx_GPT_MODE_IRQ_EN;
set |= MPC52xx_GPT_MODE_WDT_EN;
} else if (continuous)
set |= MPC52xx_GPT_MODE_CONTINUOUS;
clocks = period * (u64)gpt->ipb_freq;
do_div(clocks, 1000000000);
if (clocks > 0xffffffff)
return -EINVAL;
prescale = (clocks >> 16) + 1;
do_div(clocks, prescale);
if (clocks > 0xffff) {
pr_err("calculation error; prescale:%x clocks:%llx\n",
prescale, clocks);
return -EINVAL;
}
spin_lock_irqsave(&gpt->lock, flags);
if (as_wdt)
gpt->wdt_mode |= MPC52xx_GPT_IS_WDT;
else if ((gpt->wdt_mode & MPC52xx_GPT_IS_WDT) != 0) {
spin_unlock_irqrestore(&gpt->lock, flags);
return -EBUSY;
}
out_be32(&gpt->regs->count, prescale << 16 | clocks);
clrsetbits_be32(&gpt->regs->mode, clear, set);
spin_unlock_irqrestore(&gpt->lock, flags);
return 0;
}
int mpc52xx_gpt_start_timer(struct mpc52xx_gpt_priv *gpt, u64 period,
int continuous)
{
return mpc52xx_gpt_do_start(gpt, period, continuous, 0);
}
int mpc52xx_gpt_stop_timer(struct mpc52xx_gpt_priv *gpt)
{
unsigned long flags;
spin_lock_irqsave(&gpt->lock, flags);
if ((gpt->wdt_mode & MPC52xx_GPT_IS_WDT) != 0) {
spin_unlock_irqrestore(&gpt->lock, flags);
return -EBUSY;
}
clrbits32(&gpt->regs->mode, MPC52xx_GPT_MODE_COUNTER_ENABLE);
spin_unlock_irqrestore(&gpt->lock, flags);
return 0;
}
u64 mpc52xx_gpt_timer_period(struct mpc52xx_gpt_priv *gpt)
{
u64 period;
u64 prescale;
unsigned long flags;
spin_lock_irqsave(&gpt->lock, flags);
period = in_be32(&gpt->regs->count);
spin_unlock_irqrestore(&gpt->lock, flags);
prescale = period >> 16;
period &= 0xffff;
if (prescale == 0)
prescale = 0x10000;
period = period * prescale * 1000000000ULL;
do_div(period, (u64)gpt->ipb_freq);
return period;
}
static inline void mpc52xx_gpt_wdt_ping(struct mpc52xx_gpt_priv *gpt_wdt)
{
unsigned long flags;
spin_lock_irqsave(&gpt_wdt->lock, flags);
out_8((u8 *) &gpt_wdt->regs->mode, MPC52xx_GPT_MODE_WDT_PING);
spin_unlock_irqrestore(&gpt_wdt->lock, flags);
}
static ssize_t mpc52xx_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
struct mpc52xx_gpt_priv *gpt_wdt = file->private_data;
mpc52xx_gpt_wdt_ping(gpt_wdt);
return 0;
}
static long mpc52xx_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct mpc52xx_gpt_priv *gpt_wdt = file->private_data;
int __user *data = (int __user *)arg;
int timeout;
u64 real_timeout;
int ret = 0;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user(data, &mpc5200_wdt_info,
sizeof(mpc5200_wdt_info));
if (ret)
ret = -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
ret = put_user(0, data);
break;
case WDIOC_KEEPALIVE:
mpc52xx_gpt_wdt_ping(gpt_wdt);
break;
case WDIOC_SETTIMEOUT:
ret = get_user(timeout, data);
if (ret)
break;
real_timeout = (u64) timeout * 1000000000ULL;
ret = mpc52xx_gpt_do_start(gpt_wdt, real_timeout, 0, 1);
if (ret)
break;
case WDIOC_GETTIMEOUT:
real_timeout =
mpc52xx_gpt_timer_period(gpt_wdt) + 500000000ULL;
do_div(real_timeout, 1000000000ULL);
timeout = (int) real_timeout;
ret = put_user(timeout, data);
break;
default:
ret = -ENOTTY;
}
return ret;
}
static int mpc52xx_wdt_open(struct inode *inode, struct file *file)
{
int ret;
if (!mpc52xx_gpt_wdt)
return -ENODEV;
if (test_and_set_bit(0, &wdt_is_active))
return -EBUSY;
ret = mpc52xx_gpt_do_start(mpc52xx_gpt_wdt, 30ULL * 1000000000ULL,
0, 1);
if (ret) {
clear_bit(0, &wdt_is_active);
return ret;
}
file->private_data = mpc52xx_gpt_wdt;
return nonseekable_open(inode, file);
}
static int mpc52xx_wdt_release(struct inode *inode, struct file *file)
{
#if !defined(CONFIG_WATCHDOG_NOWAYOUT)
struct mpc52xx_gpt_priv *gpt_wdt = file->private_data;
unsigned long flags;
spin_lock_irqsave(&gpt_wdt->lock, flags);
clrbits32(&gpt_wdt->regs->mode,
MPC52xx_GPT_MODE_COUNTER_ENABLE | MPC52xx_GPT_MODE_WDT_EN);
gpt_wdt->wdt_mode &= ~MPC52xx_GPT_IS_WDT;
spin_unlock_irqrestore(&gpt_wdt->lock, flags);
#endif
clear_bit(0, &wdt_is_active);
return 0;
}
static int __devinit mpc52xx_gpt_wdt_init(void)
{
int err;
err = misc_register(&mpc52xx_wdt_miscdev);
if (err)
pr_err("%s: cannot register watchdog device\n", WDT_IDENTITY);
else
pr_info("%s: watchdog device registered\n", WDT_IDENTITY);
return err;
}
static int mpc52xx_gpt_wdt_setup(struct mpc52xx_gpt_priv *gpt,
const u32 *period)
{
u64 real_timeout;
mpc52xx_gpt_wdt = gpt;
if (!period || *period == 0)
return 0;
real_timeout = (u64) *period * 1000000000ULL;
if (mpc52xx_gpt_do_start(gpt, real_timeout, 0, 1))
dev_warn(gpt->dev, "starting as wdt failed\n");
else
dev_info(gpt->dev, "watchdog set to %us timeout\n", *period);
return 0;
}
static int __devinit mpc52xx_gpt_wdt_init(void)
{
return 0;
}
static inline int mpc52xx_gpt_wdt_setup(struct mpc52xx_gpt_priv *gpt,
const u32 *period)
{
return 0;
}
static int __devinit mpc52xx_gpt_probe(struct platform_device *ofdev)
{
struct mpc52xx_gpt_priv *gpt;
gpt = kzalloc(sizeof *gpt, GFP_KERNEL);
if (!gpt)
return -ENOMEM;
spin_lock_init(&gpt->lock);
gpt->dev = &ofdev->dev;
gpt->ipb_freq = mpc5xxx_get_bus_frequency(ofdev->dev.of_node);
gpt->regs = of_iomap(ofdev->dev.of_node, 0);
if (!gpt->regs) {
kfree(gpt);
return -ENOMEM;
}
dev_set_drvdata(&ofdev->dev, gpt);
mpc52xx_gpt_gpio_setup(gpt, ofdev->dev.of_node);
mpc52xx_gpt_irq_setup(gpt, ofdev->dev.of_node);
mutex_lock(&mpc52xx_gpt_list_mutex);
list_add(&gpt->list, &mpc52xx_gpt_list);
mutex_unlock(&mpc52xx_gpt_list_mutex);
if (of_get_property(ofdev->dev.of_node, "fsl,has-wdt", NULL) ||
of_get_property(ofdev->dev.of_node, "has-wdt", NULL)) {
const u32 *on_boot_wdt;
gpt->wdt_mode = MPC52xx_GPT_CAN_WDT;
on_boot_wdt = of_get_property(ofdev->dev.of_node,
"fsl,wdt-on-boot", NULL);
if (on_boot_wdt) {
dev_info(gpt->dev, "used as watchdog\n");
gpt->wdt_mode |= MPC52xx_GPT_IS_WDT;
} else
dev_info(gpt->dev, "can function as watchdog\n");
mpc52xx_gpt_wdt_setup(gpt, on_boot_wdt);
}
return 0;
}
static int mpc52xx_gpt_remove(struct platform_device *ofdev)
{
return -EBUSY;
}
static int __init mpc52xx_gpt_init(void)
{
return platform_driver_register(&mpc52xx_gpt_driver);
}
