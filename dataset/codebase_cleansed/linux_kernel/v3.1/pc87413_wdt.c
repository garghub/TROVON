static inline void pc87413_select_wdt_out(void)
{
unsigned int cr_data = 0;
outb_p(SIOCFG2, WDT_INDEX_IO_PORT);
cr_data = inb(WDT_DATA_IO_PORT);
cr_data |= 0x80;
outb_p(SIOCFG2, WDT_INDEX_IO_PORT);
outb_p(cr_data, WDT_DATA_IO_PORT);
#ifdef DEBUG
printk(KERN_INFO DPFX
"Select multiple pin,pin55,as WDT output: Bit7 to 1: %d\n",
cr_data);
#endif
}
static inline void pc87413_enable_swc(void)
{
unsigned int cr_data = 0;
outb_p(0x07, WDT_INDEX_IO_PORT);
outb_p(SWC_LDN, WDT_DATA_IO_PORT);
outb_p(0x30, WDT_INDEX_IO_PORT);
cr_data = inb(WDT_DATA_IO_PORT);
cr_data |= 0x01;
outb_p(0x30, WDT_INDEX_IO_PORT);
outb_p(cr_data, WDT_DATA_IO_PORT);
#ifdef DEBUG
printk(KERN_INFO DPFX "pc87413 - Enable SWC functions\n");
#endif
}
static void pc87413_get_swc_base_addr(void)
{
unsigned char addr_l, addr_h = 0;
outb_p(0x60, WDT_INDEX_IO_PORT);
addr_h = inb(WDT_DATA_IO_PORT);
outb_p(0x61, WDT_INDEX_IO_PORT);
addr_l = inb(WDT_DATA_IO_PORT);
swc_base_addr = (addr_h << 8) + addr_l;
#ifdef DEBUG
printk(KERN_INFO DPFX
"Read SWC I/O Base Address: low %d, high %d, res %d\n",
addr_l, addr_h, swc_base_addr);
#endif
}
static inline void pc87413_swc_bank3(void)
{
outb_p(inb(swc_base_addr + 0x0f) | 0x03, swc_base_addr + 0x0f);
#ifdef DEBUG
printk(KERN_INFO DPFX "Select Bank3 of SWC\n");
#endif
}
static inline void pc87413_programm_wdto(char pc87413_time)
{
outb_p(pc87413_time, swc_base_addr + WDTO);
#ifdef DEBUG
printk(KERN_INFO DPFX "Set WDTO to %d minutes\n", pc87413_time);
#endif
}
static inline void pc87413_enable_wden(void)
{
outb_p(inb(swc_base_addr + WDCTL) | 0x01, swc_base_addr + WDCTL);
#ifdef DEBUG
printk(KERN_INFO DPFX "Enable WDEN\n");
#endif
}
static inline void pc87413_enable_sw_wd_tren(void)
{
outb_p(inb(swc_base_addr + WDCFG) | 0x80, swc_base_addr + WDCFG);
#ifdef DEBUG
printk(KERN_INFO DPFX "Enable SW_WD_TREN\n");
#endif
}
static inline void pc87413_disable_sw_wd_tren(void)
{
outb_p(inb(swc_base_addr + WDCFG) & 0x7f, swc_base_addr + WDCFG);
#ifdef DEBUG
printk(KERN_INFO DPFX "pc87413 - Disable SW_WD_TREN\n");
#endif
}
static inline void pc87413_enable_sw_wd_trg(void)
{
outb_p(inb(swc_base_addr + WDCTL) | 0x80, swc_base_addr + WDCTL);
#ifdef DEBUG
printk(KERN_INFO DPFX "pc87413 - Enable SW_WD_TRG\n");
#endif
}
static inline void pc87413_disable_sw_wd_trg(void)
{
outb_p(inb(swc_base_addr + WDCTL) & 0x7f, swc_base_addr + WDCTL);
#ifdef DEBUG
printk(KERN_INFO DPFX "Disable SW_WD_TRG\n");
#endif
}
static void pc87413_enable(void)
{
spin_lock(&io_lock);
pc87413_swc_bank3();
pc87413_programm_wdto(timeout);
pc87413_enable_wden();
pc87413_enable_sw_wd_tren();
pc87413_enable_sw_wd_trg();
spin_unlock(&io_lock);
}
static void pc87413_disable(void)
{
spin_lock(&io_lock);
pc87413_swc_bank3();
pc87413_disable_sw_wd_tren();
pc87413_disable_sw_wd_trg();
pc87413_programm_wdto(0);
spin_unlock(&io_lock);
}
static void pc87413_refresh(void)
{
spin_lock(&io_lock);
pc87413_swc_bank3();
pc87413_disable_sw_wd_tren();
pc87413_disable_sw_wd_trg();
pc87413_programm_wdto(timeout);
pc87413_enable_wden();
pc87413_enable_sw_wd_tren();
pc87413_enable_sw_wd_trg();
spin_unlock(&io_lock);
}
static int pc87413_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &timer_enabled))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
pc87413_refresh();
printk(KERN_INFO MODNAME
"Watchdog enabled. Timeout set to %d minute(s).\n", timeout);
return nonseekable_open(inode, file);
}
static int pc87413_release(struct inode *inode, struct file *file)
{
if (expect_close == 42) {
pc87413_disable();
printk(KERN_INFO MODNAME
"Watchdog disabled, sleeping again...\n");
} else {
printk(KERN_CRIT MODNAME
"Unexpected close, not stopping watchdog!\n");
pc87413_refresh();
}
clear_bit(0, &timer_enabled);
expect_close = 0;
return 0;
}
static int pc87413_status(void)
{
return 0;
}
static ssize_t pc87413_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
expect_close = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
}
pc87413_refresh();
}
return len;
}
static long pc87413_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int new_timeout;
union {
struct watchdog_info __user *ident;
int __user *i;
} uarg;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING |
WDIOF_SETTIMEOUT |
WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = "PC87413(HF/F) watchdog",
};
uarg.i = (int __user *)arg;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(uarg.ident, &ident,
sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
return put_user(pc87413_status(), uarg.i);
case WDIOC_GETBOOTSTATUS:
return put_user(0, uarg.i);
case WDIOC_SETOPTIONS:
{
int options, retval = -EINVAL;
if (get_user(options, uarg.i))
return -EFAULT;
if (options & WDIOS_DISABLECARD) {
pc87413_disable();
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
pc87413_enable();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
pc87413_refresh();
#ifdef DEBUG
printk(KERN_INFO DPFX "keepalive\n");
#endif
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_timeout, uarg.i))
return -EFAULT;
new_timeout /= 60;
if (new_timeout < 0 || new_timeout > MAX_TIMEOUT)
return -EINVAL;
timeout = new_timeout;
pc87413_refresh();
case WDIOC_GETTIMEOUT:
new_timeout = timeout * 60;
return put_user(new_timeout, uarg.i);
default:
return -ENOTTY;
}
}
static int pc87413_notify_sys(struct notifier_block *this,
unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
pc87413_disable();
return NOTIFY_DONE;
}
static int __init pc87413_init(void)
{
int ret;
printk(KERN_INFO PFX "Version " VERSION " at io 0x%X\n",
WDT_INDEX_IO_PORT);
if (!request_muxed_region(io, 2, MODNAME))
return -EBUSY;
ret = register_reboot_notifier(&pc87413_notifier);
if (ret != 0) {
printk(KERN_ERR PFX
"cannot register reboot notifier (err=%d)\n", ret);
}
ret = misc_register(&pc87413_miscdev);
if (ret != 0) {
printk(KERN_ERR PFX
"cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
goto reboot_unreg;
}
printk(KERN_INFO PFX "initialized. timeout=%d min \n", timeout);
pc87413_select_wdt_out();
pc87413_enable_swc();
pc87413_get_swc_base_addr();
if (!request_region(swc_base_addr, 0x20, MODNAME)) {
printk(KERN_ERR PFX
"cannot request SWC region at 0x%x\n", swc_base_addr);
ret = -EBUSY;
goto misc_unreg;
}
pc87413_enable();
release_region(io, 2);
return 0;
misc_unreg:
misc_deregister(&pc87413_miscdev);
reboot_unreg:
unregister_reboot_notifier(&pc87413_notifier);
release_region(io, 2);
return ret;
}
static void __exit pc87413_exit(void)
{
if (!nowayout) {
pc87413_disable();
printk(KERN_INFO MODNAME "Watchdog disabled.\n");
}
misc_deregister(&pc87413_miscdev);
unregister_reboot_notifier(&pc87413_notifier);
release_region(swc_base_addr, 0x20);
printk(KERN_INFO MODNAME " watchdog component driver removed.\n");
}
