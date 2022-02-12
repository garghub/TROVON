static int tlclk_open(struct inode *inode, struct file *filp)
{
int result;
mutex_lock(&tlclk_mutex);
if (test_and_set_bit(0, &useflags)) {
result = -EBUSY;
goto out;
}
inb(TLCLK_REG6);
result = request_irq(telclk_interrupt, &tlclk_interrupt,
IRQF_DISABLED, "telco_clock", tlclk_interrupt);
if (result == -EBUSY)
printk(KERN_ERR "tlclk: Interrupt can't be reserved.\n");
else
inb(TLCLK_REG6);
out:
mutex_unlock(&tlclk_mutex);
return result;
}
static int tlclk_release(struct inode *inode, struct file *filp)
{
free_irq(telclk_interrupt, tlclk_interrupt);
clear_bit(0, &useflags);
return 0;
}
static ssize_t tlclk_read(struct file *filp, char __user *buf, size_t count,
loff_t *f_pos)
{
if (count < sizeof(struct tlclk_alarms))
return -EIO;
if (mutex_lock_interruptible(&tlclk_mutex))
return -EINTR;
wait_event_interruptible(wq, got_event);
if (copy_to_user(buf, alarm_events, sizeof(struct tlclk_alarms))) {
mutex_unlock(&tlclk_mutex);
return -EFAULT;
}
memset(alarm_events, 0, sizeof(struct tlclk_alarms));
got_event = 0;
mutex_unlock(&tlclk_mutex);
return sizeof(struct tlclk_alarms);
}
static ssize_t show_current_ref(struct device *d,
struct device_attribute *attr, char *buf)
{
unsigned long ret_val;
unsigned long flags;
spin_lock_irqsave(&event_lock, flags);
ret_val = ((inb(TLCLK_REG1) & 0x08) >> 3);
spin_unlock_irqrestore(&event_lock, flags);
return sprintf(buf, "0x%lX\n", ret_val);
}
static ssize_t show_telclock_version(struct device *d,
struct device_attribute *attr, char *buf)
{
unsigned long ret_val;
unsigned long flags;
spin_lock_irqsave(&event_lock, flags);
ret_val = inb(TLCLK_REG5);
spin_unlock_irqrestore(&event_lock, flags);
return sprintf(buf, "0x%lX\n", ret_val);
}
static ssize_t show_alarms(struct device *d,
struct device_attribute *attr, char *buf)
{
unsigned long ret_val;
unsigned long flags;
spin_lock_irqsave(&event_lock, flags);
ret_val = (inb(TLCLK_REG2) & 0xf0);
spin_unlock_irqrestore(&event_lock, flags);
return sprintf(buf, "0x%lX\n", ret_val);
}
static ssize_t store_received_ref_clk3a(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned char val;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, ": tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG1, 0xef, val);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_received_ref_clk3b(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned char val;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, ": tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG1, 0xdf, val << 1);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_enable_clk3b_output(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned char val;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, ": tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG3, 0x7f, val << 7);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_enable_clk3a_output(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long flags;
unsigned long tmp;
unsigned char val;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG3, 0xbf, val << 6);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_enable_clkb1_output(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long flags;
unsigned long tmp;
unsigned char val;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG2, 0xf7, val << 3);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_enable_clka1_output(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long flags;
unsigned long tmp;
unsigned char val;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG2, 0xfb, val << 2);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_enable_clkb0_output(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long flags;
unsigned long tmp;
unsigned char val;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG2, 0xfd, val << 1);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_enable_clka0_output(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long flags;
unsigned long tmp;
unsigned char val;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG2, 0xfe, val);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_select_amcb2_transmit_clock(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long flags;
unsigned long tmp;
unsigned char val;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
if ((val == CLK_8kHz) || (val == CLK_16_384MHz)) {
SET_PORT_BITS(TLCLK_REG3, 0xc7, 0x28);
SET_PORT_BITS(TLCLK_REG1, 0xfb, ~val);
} else if (val >= CLK_8_592MHz) {
SET_PORT_BITS(TLCLK_REG3, 0xc7, 0x38);
switch (val) {
case CLK_8_592MHz:
SET_PORT_BITS(TLCLK_REG0, 0xfc, 2);
break;
case CLK_11_184MHz:
SET_PORT_BITS(TLCLK_REG0, 0xfc, 0);
break;
case CLK_34_368MHz:
SET_PORT_BITS(TLCLK_REG0, 0xfc, 3);
break;
case CLK_44_736MHz:
SET_PORT_BITS(TLCLK_REG0, 0xfc, 1);
break;
}
} else
SET_PORT_BITS(TLCLK_REG3, 0xc7, val << 3);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_select_amcb1_transmit_clock(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned char val;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
if ((val == CLK_8kHz) || (val == CLK_16_384MHz)) {
SET_PORT_BITS(TLCLK_REG3, 0xf8, 0x5);
SET_PORT_BITS(TLCLK_REG1, 0xfb, ~val);
} else if (val >= CLK_8_592MHz) {
SET_PORT_BITS(TLCLK_REG3, 0xf8, 0x7);
switch (val) {
case CLK_8_592MHz:
SET_PORT_BITS(TLCLK_REG0, 0xfc, 2);
break;
case CLK_11_184MHz:
SET_PORT_BITS(TLCLK_REG0, 0xfc, 0);
break;
case CLK_34_368MHz:
SET_PORT_BITS(TLCLK_REG0, 0xfc, 3);
break;
case CLK_44_736MHz:
SET_PORT_BITS(TLCLK_REG0, 0xfc, 1);
break;
}
} else
SET_PORT_BITS(TLCLK_REG3, 0xf8, val);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_select_redundant_clock(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned char val;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG1, 0xfe, val);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_select_ref_frequency(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned char val;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG1, 0xfd, val);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_filter_select(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned char val;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG0, 0xfb, val);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_hardware_switching_mode(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned char val;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG0, 0xbf, val);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_hardware_switching(struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned char val;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG0, 0x7f, val);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_refalign (struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG0, 0xf7, 0);
SET_PORT_BITS(TLCLK_REG0, 0xf7, 0x08);
SET_PORT_BITS(TLCLK_REG0, 0xf7, 0);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_mode_select (struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned char val;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG0, 0xcf, val);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static ssize_t store_reset (struct device *d,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long tmp;
unsigned char val;
unsigned long flags;
sscanf(buf, "%lX", &tmp);
dev_dbg(d, "tmp = 0x%lX\n", tmp);
val = (unsigned char)tmp;
spin_lock_irqsave(&event_lock, flags);
SET_PORT_BITS(TLCLK_REG4, 0xfd, val);
spin_unlock_irqrestore(&event_lock, flags);
return strnlen(buf, count);
}
static int __init tlclk_init(void)
{
int ret;
ret = register_chrdev(tlclk_major, "telco_clock", &tlclk_fops);
if (ret < 0) {
printk(KERN_ERR "tlclk: can't get major %d.\n", tlclk_major);
return ret;
}
tlclk_major = ret;
alarm_events = kzalloc( sizeof(struct tlclk_alarms), GFP_KERNEL);
if (!alarm_events) {
ret = -ENOMEM;
goto out1;
}
if (!request_region(TLCLK_BASE, 8, "telco_clock")) {
printk(KERN_ERR "tlclk: request_region 0x%X failed.\n",
TLCLK_BASE);
ret = -EBUSY;
goto out2;
}
telclk_interrupt = (inb(TLCLK_REG7) & 0x0f);
if (0x0F == telclk_interrupt ) {
printk(KERN_ERR "telclk_interrupt = 0x%x non-mcpbl0010 hw.\n",
telclk_interrupt);
ret = -ENXIO;
goto out3;
}
init_timer(&switchover_timer);
ret = misc_register(&tlclk_miscdev);
if (ret < 0) {
printk(KERN_ERR "tlclk: misc_register returns %d.\n", ret);
goto out3;
}
tlclk_device = platform_device_register_simple("telco_clock",
-1, NULL, 0);
if (IS_ERR(tlclk_device)) {
printk(KERN_ERR "tlclk: platform_device_register failed.\n");
ret = PTR_ERR(tlclk_device);
goto out4;
}
ret = sysfs_create_group(&tlclk_device->dev.kobj,
&tlclk_attribute_group);
if (ret) {
printk(KERN_ERR "tlclk: failed to create sysfs device attributes.\n");
goto out5;
}
return 0;
out5:
platform_device_unregister(tlclk_device);
out4:
misc_deregister(&tlclk_miscdev);
out3:
release_region(TLCLK_BASE, 8);
out2:
kfree(alarm_events);
out1:
unregister_chrdev(tlclk_major, "telco_clock");
return ret;
}
static void __exit tlclk_cleanup(void)
{
sysfs_remove_group(&tlclk_device->dev.kobj, &tlclk_attribute_group);
platform_device_unregister(tlclk_device);
misc_deregister(&tlclk_miscdev);
unregister_chrdev(tlclk_major, "telco_clock");
release_region(TLCLK_BASE, 8);
del_timer_sync(&switchover_timer);
kfree(alarm_events);
}
static void switchover_timeout(unsigned long data)
{
unsigned long flags = *(unsigned long *) data;
if ((flags & 1)) {
if ((inb(TLCLK_REG1) & 0x08) != (flags & 0x08))
alarm_events->switchover_primary++;
} else {
if ((inb(TLCLK_REG1) & 0x08) != (flags & 0x08))
alarm_events->switchover_secondary++;
}
del_timer(&switchover_timer);
got_event = 1;
wake_up(&wq);
}
static irqreturn_t tlclk_interrupt(int irq, void *dev_id)
{
unsigned long flags;
spin_lock_irqsave(&event_lock, flags);
int_events = inb(TLCLK_REG6);
if (int_events & PRI_LOS_01_MASK) {
if (inb(TLCLK_REG2) & SEC_LOST_MASK)
alarm_events->lost_clocks++;
else
alarm_events->lost_primary_clock++;
}
if (int_events & PRI_LOS_10_MASK) {
alarm_events->primary_clock_back++;
SET_PORT_BITS(TLCLK_REG1, 0xFE, 1);
}
if (int_events & SEC_LOS_01_MASK) {
if (inb(TLCLK_REG2) & PRI_LOST_MASK)
alarm_events->lost_clocks++;
else
alarm_events->lost_secondary_clock++;
}
if (int_events & SEC_LOS_10_MASK) {
alarm_events->secondary_clock_back++;
SET_PORT_BITS(TLCLK_REG1, 0xFE, 0);
}
if (int_events & HOLDOVER_10_MASK)
alarm_events->pll_end_holdover++;
if (int_events & UNLOCK_01_MASK)
alarm_events->pll_lost_sync++;
if (int_events & UNLOCK_10_MASK)
alarm_events->pll_sync++;
if (int_events & HOLDOVER_01_MASK) {
alarm_events->pll_holdover++;
switchover_timer.expires = jiffies + msecs_to_jiffies(10);
tlclk_timer_data = inb(TLCLK_REG1);
switchover_timer.data = (unsigned long) &tlclk_timer_data;
mod_timer(&switchover_timer, switchover_timer.expires);
} else {
got_event = 1;
wake_up(&wq);
}
spin_unlock_irqrestore(&event_lock, flags);
return IRQ_HANDLED;
}
