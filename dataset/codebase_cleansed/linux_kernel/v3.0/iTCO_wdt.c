static inline unsigned int seconds_to_ticks(int seconds)
{
return (seconds * 10) / 6;
}
static void iTCO_wdt_set_NO_REBOOT_bit(void)
{
u32 val32;
if (iTCO_wdt_private.iTCO_version == 2) {
val32 = readl(iTCO_wdt_private.gcs);
val32 |= 0x00000020;
writel(val32, iTCO_wdt_private.gcs);
} else if (iTCO_wdt_private.iTCO_version == 1) {
pci_read_config_dword(iTCO_wdt_private.pdev, 0xd4, &val32);
val32 |= 0x00000002;
pci_write_config_dword(iTCO_wdt_private.pdev, 0xd4, val32);
}
}
static int iTCO_wdt_unset_NO_REBOOT_bit(void)
{
int ret = 0;
u32 val32;
if (iTCO_wdt_private.iTCO_version == 2) {
val32 = readl(iTCO_wdt_private.gcs);
val32 &= 0xffffffdf;
writel(val32, iTCO_wdt_private.gcs);
val32 = readl(iTCO_wdt_private.gcs);
if (val32 & 0x00000020)
ret = -EIO;
} else if (iTCO_wdt_private.iTCO_version == 1) {
pci_read_config_dword(iTCO_wdt_private.pdev, 0xd4, &val32);
val32 &= 0xfffffffd;
pci_write_config_dword(iTCO_wdt_private.pdev, 0xd4, val32);
pci_read_config_dword(iTCO_wdt_private.pdev, 0xd4, &val32);
if (val32 & 0x00000002)
ret = -EIO;
}
return ret;
}
static int iTCO_wdt_start(void)
{
unsigned int val;
spin_lock(&iTCO_wdt_private.io_lock);
iTCO_vendor_pre_start(iTCO_wdt_private.ACPIBASE, heartbeat);
if (iTCO_wdt_unset_NO_REBOOT_bit()) {
spin_unlock(&iTCO_wdt_private.io_lock);
printk(KERN_ERR PFX "failed to reset NO_REBOOT flag, "
"reboot disabled by hardware/BIOS\n");
return -EIO;
}
if (iTCO_wdt_private.iTCO_version == 2)
outw(0x01, TCO_RLD);
else if (iTCO_wdt_private.iTCO_version == 1)
outb(0x01, TCO_RLD);
val = inw(TCO1_CNT);
val &= 0xf7ff;
outw(val, TCO1_CNT);
val = inw(TCO1_CNT);
spin_unlock(&iTCO_wdt_private.io_lock);
if (val & 0x0800)
return -1;
return 0;
}
static int iTCO_wdt_stop(void)
{
unsigned int val;
spin_lock(&iTCO_wdt_private.io_lock);
iTCO_vendor_pre_stop(iTCO_wdt_private.ACPIBASE);
val = inw(TCO1_CNT);
val |= 0x0800;
outw(val, TCO1_CNT);
val = inw(TCO1_CNT);
iTCO_wdt_set_NO_REBOOT_bit();
spin_unlock(&iTCO_wdt_private.io_lock);
if ((val & 0x0800) == 0)
return -1;
return 0;
}
static int iTCO_wdt_keepalive(void)
{
spin_lock(&iTCO_wdt_private.io_lock);
iTCO_vendor_pre_keepalive(iTCO_wdt_private.ACPIBASE, heartbeat);
if (iTCO_wdt_private.iTCO_version == 2)
outw(0x01, TCO_RLD);
else if (iTCO_wdt_private.iTCO_version == 1) {
outw(0x0008, TCO1_STS);
outb(0x01, TCO_RLD);
}
spin_unlock(&iTCO_wdt_private.io_lock);
return 0;
}
static int iTCO_wdt_set_heartbeat(int t)
{
unsigned int val16;
unsigned char val8;
unsigned int tmrval;
tmrval = seconds_to_ticks(t);
if (iTCO_wdt_private.iTCO_version == 1)
tmrval /= 2;
if (tmrval < 0x04)
return -EINVAL;
if (((iTCO_wdt_private.iTCO_version == 2) && (tmrval > 0x3ff)) ||
((iTCO_wdt_private.iTCO_version == 1) && (tmrval > 0x03f)))
return -EINVAL;
iTCO_vendor_pre_set_heartbeat(tmrval);
if (iTCO_wdt_private.iTCO_version == 2) {
spin_lock(&iTCO_wdt_private.io_lock);
val16 = inw(TCOv2_TMR);
val16 &= 0xfc00;
val16 |= tmrval;
outw(val16, TCOv2_TMR);
val16 = inw(TCOv2_TMR);
spin_unlock(&iTCO_wdt_private.io_lock);
if ((val16 & 0x3ff) != tmrval)
return -EINVAL;
} else if (iTCO_wdt_private.iTCO_version == 1) {
spin_lock(&iTCO_wdt_private.io_lock);
val8 = inb(TCOv1_TMR);
val8 &= 0xc0;
val8 |= (tmrval & 0xff);
outb(val8, TCOv1_TMR);
val8 = inb(TCOv1_TMR);
spin_unlock(&iTCO_wdt_private.io_lock);
if ((val8 & 0x3f) != tmrval)
return -EINVAL;
}
heartbeat = t;
return 0;
}
static int iTCO_wdt_get_timeleft(int *time_left)
{
unsigned int val16;
unsigned char val8;
if (iTCO_wdt_private.iTCO_version == 2) {
spin_lock(&iTCO_wdt_private.io_lock);
val16 = inw(TCO_RLD);
val16 &= 0x3ff;
spin_unlock(&iTCO_wdt_private.io_lock);
*time_left = (val16 * 6) / 10;
} else if (iTCO_wdt_private.iTCO_version == 1) {
spin_lock(&iTCO_wdt_private.io_lock);
val8 = inb(TCO_RLD);
val8 &= 0x3f;
if (!(inw(TCO1_STS) & 0x0008))
val8 += (inb(TCOv1_TMR) & 0x3f);
spin_unlock(&iTCO_wdt_private.io_lock);
*time_left = (val8 * 6) / 10;
} else
return -EINVAL;
return 0;
}
static int iTCO_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &is_active))
return -EBUSY;
iTCO_wdt_start();
return nonseekable_open(inode, file);
}
static int iTCO_wdt_release(struct inode *inode, struct file *file)
{
if (expect_release == 42) {
iTCO_wdt_stop();
} else {
printk(KERN_CRIT PFX
"Unexpected close, not stopping watchdog!\n");
iTCO_wdt_keepalive();
}
clear_bit(0, &is_active);
expect_release = 0;
return 0;
}
static ssize_t iTCO_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
expect_release = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
expect_release = 42;
}
}
iTCO_wdt_keepalive();
}
return len;
}
static long iTCO_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int new_options, retval = -EINVAL;
int new_heartbeat;
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.options = WDIOF_SETTIMEOUT |
WDIOF_KEEPALIVEPING |
WDIOF_MAGICCLOSE,
.firmware_version = 0,
.identity = DRV_NAME,
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
{
if (get_user(new_options, p))
return -EFAULT;
if (new_options & WDIOS_DISABLECARD) {
iTCO_wdt_stop();
retval = 0;
}
if (new_options & WDIOS_ENABLECARD) {
iTCO_wdt_keepalive();
iTCO_wdt_start();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
iTCO_wdt_keepalive();
return 0;
case WDIOC_SETTIMEOUT:
{
if (get_user(new_heartbeat, p))
return -EFAULT;
if (iTCO_wdt_set_heartbeat(new_heartbeat))
return -EINVAL;
iTCO_wdt_keepalive();
}
case WDIOC_GETTIMEOUT:
return put_user(heartbeat, p);
case WDIOC_GETTIMELEFT:
{
int time_left;
if (iTCO_wdt_get_timeleft(&time_left))
return -EINVAL;
return put_user(time_left, p);
}
default:
return -ENOTTY;
}
}
static int __devinit iTCO_wdt_init(struct pci_dev *pdev,
const struct pci_device_id *ent, struct platform_device *dev)
{
int ret;
u32 base_address;
unsigned long RCBA;
unsigned long val32;
pci_read_config_dword(pdev, 0x40, &base_address);
base_address &= 0x0000ff80;
if (base_address == 0x00000000) {
printk(KERN_ERR PFX "failed to get TCOBASE address, "
"device disabled by hardware/BIOS\n");
return -ENODEV;
}
iTCO_wdt_private.iTCO_version =
iTCO_chipset_info[ent->driver_data].iTCO_version;
iTCO_wdt_private.ACPIBASE = base_address;
iTCO_wdt_private.pdev = pdev;
if (iTCO_wdt_private.iTCO_version == 2) {
pci_read_config_dword(pdev, 0xf0, &base_address);
if ((base_address & 1) == 0) {
printk(KERN_ERR PFX "RCBA is disabled by hardware"
"/BIOS, device disabled\n");
ret = -ENODEV;
goto out;
}
RCBA = base_address & 0xffffc000;
iTCO_wdt_private.gcs = ioremap((RCBA + 0x3410), 4);
}
if (iTCO_wdt_unset_NO_REBOOT_bit() && iTCO_vendor_check_noreboot_on()) {
printk(KERN_INFO PFX "unable to reset NO_REBOOT flag, "
"device disabled by hardware/BIOS\n");
ret = -ENODEV;
goto out_unmap;
}
iTCO_wdt_set_NO_REBOOT_bit();
if (!request_region(SMI_EN, 4, "iTCO_wdt")) {
printk(KERN_ERR PFX
"I/O address 0x%04lx already in use, "
"device disabled\n", SMI_EN);
ret = -EIO;
goto out_unmap;
}
val32 = inl(SMI_EN);
val32 &= 0xffffdfff;
outl(val32, SMI_EN);
if (!request_region(TCOBASE, 0x20, "iTCO_wdt")) {
printk(KERN_ERR PFX "I/O address 0x%04lx already in use "
"device disabled\n", TCOBASE);
ret = -EIO;
goto unreg_smi_en;
}
printk(KERN_INFO PFX
"Found a %s TCO device (Version=%d, TCOBASE=0x%04lx)\n",
iTCO_chipset_info[ent->driver_data].name,
iTCO_chipset_info[ent->driver_data].iTCO_version,
TCOBASE);
outw(0x0008, TCO1_STS);
outw(0x0002, TCO2_STS);
outw(0x0004, TCO2_STS);
iTCO_wdt_stop();
if (iTCO_wdt_set_heartbeat(heartbeat)) {
iTCO_wdt_set_heartbeat(WATCHDOG_HEARTBEAT);
printk(KERN_INFO PFX
"timeout value out of range, using %d\n", heartbeat);
}
ret = misc_register(&iTCO_wdt_miscdev);
if (ret != 0) {
printk(KERN_ERR PFX
"cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
goto unreg_region;
}
printk(KERN_INFO PFX "initialized. heartbeat=%d sec (nowayout=%d)\n",
heartbeat, nowayout);
return 0;
unreg_region:
release_region(TCOBASE, 0x20);
unreg_smi_en:
release_region(SMI_EN, 4);
out_unmap:
if (iTCO_wdt_private.iTCO_version == 2)
iounmap(iTCO_wdt_private.gcs);
out:
iTCO_wdt_private.ACPIBASE = 0;
return ret;
}
static void __devexit iTCO_wdt_cleanup(void)
{
if (!nowayout)
iTCO_wdt_stop();
misc_deregister(&iTCO_wdt_miscdev);
release_region(TCOBASE, 0x20);
release_region(SMI_EN, 4);
if (iTCO_wdt_private.iTCO_version == 2)
iounmap(iTCO_wdt_private.gcs);
pci_dev_put(iTCO_wdt_private.pdev);
iTCO_wdt_private.ACPIBASE = 0;
}
static int __devinit iTCO_wdt_probe(struct platform_device *dev)
{
int ret = -ENODEV;
int found = 0;
struct pci_dev *pdev = NULL;
const struct pci_device_id *ent;
spin_lock_init(&iTCO_wdt_private.io_lock);
for_each_pci_dev(pdev) {
ent = pci_match_id(iTCO_wdt_pci_tbl, pdev);
if (ent) {
found++;
ret = iTCO_wdt_init(pdev, ent, dev);
if (!ret)
break;
}
}
if (!found)
printk(KERN_INFO PFX "No device detected.\n");
return ret;
}
static int __devexit iTCO_wdt_remove(struct platform_device *dev)
{
if (iTCO_wdt_private.ACPIBASE)
iTCO_wdt_cleanup();
return 0;
}
static void iTCO_wdt_shutdown(struct platform_device *dev)
{
iTCO_wdt_stop();
}
static int __init iTCO_wdt_init_module(void)
{
int err;
printk(KERN_INFO PFX "Intel TCO WatchDog Timer Driver v%s\n",
DRV_VERSION);
err = platform_driver_register(&iTCO_wdt_driver);
if (err)
return err;
iTCO_wdt_platform_device = platform_device_register_simple(DRV_NAME,
-1, NULL, 0);
if (IS_ERR(iTCO_wdt_platform_device)) {
err = PTR_ERR(iTCO_wdt_platform_device);
goto unreg_platform_driver;
}
return 0;
unreg_platform_driver:
platform_driver_unregister(&iTCO_wdt_driver);
return err;
}
static void __exit iTCO_wdt_cleanup_module(void)
{
platform_device_unregister(iTCO_wdt_platform_device);
platform_driver_unregister(&iTCO_wdt_driver);
printk(KERN_INFO PFX "Watchdog Module Unloaded.\n");
}
