static int __devinit cru_detect(unsigned long map_entry,
unsigned long map_offset)
{
void *bios32_map;
unsigned long *bios32_entrypoint;
unsigned long cru_physical_address;
unsigned long cru_length;
unsigned long physical_bios_base = 0;
unsigned long physical_bios_offset = 0;
int retval = -ENODEV;
bios32_map = ioremap(map_entry, (2 * PAGE_SIZE));
if (bios32_map == NULL)
return -ENODEV;
bios32_entrypoint = bios32_map + map_offset;
cmn_regs.u1.reax = CRU_BIOS_SIGNATURE_VALUE;
asminline_call(&cmn_regs, bios32_entrypoint);
if (cmn_regs.u1.ral != 0) {
printk(KERN_WARNING
"hpwdt: Call succeeded but with an error: 0x%x\n",
cmn_regs.u1.ral);
} else {
physical_bios_base = cmn_regs.u2.rebx;
physical_bios_offset = cmn_regs.u4.redx;
cru_length = cmn_regs.u3.recx;
cru_physical_address =
physical_bios_base + physical_bios_offset;
if ((physical_bios_base + physical_bios_offset)) {
cru_rom_addr =
ioremap(cru_physical_address, cru_length);
if (cru_rom_addr)
retval = 0;
}
printk(KERN_DEBUG "hpwdt: CRU Base Address: 0x%lx\n",
physical_bios_base);
printk(KERN_DEBUG "hpwdt: CRU Offset Address: 0x%lx\n",
physical_bios_offset);
printk(KERN_DEBUG "hpwdt: CRU Length: 0x%lx\n",
cru_length);
printk(KERN_DEBUG "hpwdt: CRU Mapped Address: %p\n",
&cru_rom_addr);
}
iounmap(bios32_map);
return retval;
}
static int __devinit bios_checksum(const char __iomem *ptr, int len)
{
char sum = 0;
int i;
for (i = 0; i < len; i++)
sum += ptr[i];
return ((sum == 0) && (len > 0));
}
static int __devinit bios32_present(const char __iomem *p)
{
struct bios32_service_dir *bios_32_ptr;
int length;
unsigned long map_entry, map_offset;
bios_32_ptr = (struct bios32_service_dir *) p;
if (bios_32_ptr->signature == PCI_BIOS32_SD_VALUE) {
length = bios_32_ptr->length * PCI_BIOS32_PARAGRAPH_LEN;
if (bios_checksum(p, length)) {
map_entry = bios_32_ptr->entry_point & ~(PAGE_SIZE - 1);
map_offset = bios_32_ptr->entry_point - map_entry;
return cru_detect(map_entry, map_offset);
}
}
return -ENODEV;
}
static int __devinit detect_cru_service(void)
{
char __iomem *p, *q;
int rc = -1;
p = ioremap(PCI_ROM_BASE1, ROM_SIZE);
if (p == NULL)
return -ENOMEM;
for (q = p; q < p + ROM_SIZE; q += 16) {
rc = bios32_present(q);
if (!rc)
break;
}
iounmap(p);
return rc;
}
static void __devinit dmi_find_cru(const struct dmi_header *dm, void *dummy)
{
struct smbios_cru64_info *smbios_cru64_ptr;
unsigned long cru_physical_address;
if (dm->type == SMBIOS_CRU64_INFORMATION) {
smbios_cru64_ptr = (struct smbios_cru64_info *) dm;
if (smbios_cru64_ptr->signature == CRU_BIOS_SIGNATURE_VALUE) {
cru_physical_address =
smbios_cru64_ptr->physical_address +
smbios_cru64_ptr->double_offset;
cru_rom_addr = ioremap(cru_physical_address,
smbios_cru64_ptr->double_length);
set_memory_x((unsigned long)cru_rom_addr & PAGE_MASK,
smbios_cru64_ptr->double_length >> PAGE_SHIFT);
}
}
}
static int __devinit detect_cru_service(void)
{
cru_rom_addr = NULL;
dmi_walk(dmi_find_cru, NULL);
return ((cru_rom_addr != NULL) ? 0 : -ENODEV);
}
static void hpwdt_start(void)
{
reload = SECS_TO_TICKS(soft_margin);
iowrite16(reload, hpwdt_timer_reg);
iowrite16(0x85, hpwdt_timer_con);
}
static void hpwdt_stop(void)
{
unsigned long data;
data = ioread16(hpwdt_timer_con);
data &= 0xFE;
iowrite16(data, hpwdt_timer_con);
}
static void hpwdt_ping(void)
{
iowrite16(reload, hpwdt_timer_reg);
}
static int hpwdt_change_timer(int new_margin)
{
if (new_margin < 1 || new_margin > HPWDT_MAX_TIMER) {
printk(KERN_WARNING
"hpwdt: New value passed in is invalid: %d seconds.\n",
new_margin);
return -EINVAL;
}
soft_margin = new_margin;
printk(KERN_DEBUG
"hpwdt: New timer passed in is %d seconds.\n",
new_margin);
reload = SECS_TO_TICKS(soft_margin);
return 0;
}
static int hpwdt_time_left(void)
{
return TICKS_TO_SECS(ioread16(hpwdt_timer_reg));
}
static int hpwdt_pretimeout(struct notifier_block *nb, unsigned long ulReason,
void *data)
{
unsigned long rom_pl;
static int die_nmi_called;
if (ulReason != DIE_NMIUNKNOWN)
goto out;
if (!hpwdt_nmi_decoding)
goto out;
spin_lock_irqsave(&rom_lock, rom_pl);
if (!die_nmi_called)
asminline_call(&cmn_regs, cru_rom_addr);
die_nmi_called = 1;
spin_unlock_irqrestore(&rom_lock, rom_pl);
if (cmn_regs.u1.ral == 0) {
printk(KERN_WARNING "hpwdt: An NMI occurred, "
"but unable to determine source.\n");
} else {
if (allow_kdump)
hpwdt_stop();
panic("An NMI occurred, please see the Integrated "
"Management Log for details.\n");
}
out:
return NOTIFY_OK;
}
static int hpwdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &hpwdt_is_open))
return -EBUSY;
hpwdt_start();
hpwdt_ping();
return nonseekable_open(inode, file);
}
static int hpwdt_release(struct inode *inode, struct file *file)
{
if (expect_release == 42) {
hpwdt_stop();
} else {
printk(KERN_CRIT
"hpwdt: Unexpected close, not stopping watchdog!\n");
hpwdt_ping();
}
expect_release = 0;
clear_bit(0, &hpwdt_is_open);
return 0;
}
static ssize_t hpwdt_write(struct file *file, const char __user *data,
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
hpwdt_ping();
}
return len;
}
static long hpwdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int new_margin;
int ret = -ENOTTY;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = 0;
if (copy_to_user(argp, &ident, sizeof(ident)))
ret = -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
ret = put_user(0, p);
break;
case WDIOC_KEEPALIVE:
hpwdt_ping();
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(new_margin, p);
if (ret)
break;
ret = hpwdt_change_timer(new_margin);
if (ret)
break;
hpwdt_ping();
case WDIOC_GETTIMEOUT:
ret = put_user(soft_margin, p);
break;
case WDIOC_GETTIMELEFT:
ret = put_user(hpwdt_time_left(), p);
break;
}
return ret;
}
static void __devinit hpwdt_check_nmi_decoding(struct pci_dev *dev)
{
hpwdt_nmi_decoding = 1;
}
static void __devinit hpwdt_check_nmi_decoding(struct pci_dev *dev)
{
dev_warn(&dev->dev, "NMI decoding is disabled. "
"Your kernel does not support a NMI Watchdog.\n");
}
static int __devinit hpwdt_init_nmi_decoding(struct pci_dev *dev)
{
int retval;
retval = detect_cru_service();
if (retval < 0) {
dev_warn(&dev->dev,
"Unable to detect the %d Bit CRU Service.\n",
HPWDT_ARCH);
return retval;
}
cmn_regs.u1.rah = 0x0D;
cmn_regs.u1.ral = 0x02;
if (priority)
die_notifier.priority = 0x7FFFFFFF;
retval = register_die_notifier(&die_notifier);
if (retval != 0) {
dev_warn(&dev->dev,
"Unable to register a die notifier (err=%d).\n",
retval);
if (cru_rom_addr)
iounmap(cru_rom_addr);
}
dev_info(&dev->dev,
"HP Watchdog Timer Driver: NMI decoding initialized"
", allow kernel dump: %s (default = 0/OFF)"
", priority: %s (default = 0/LAST).\n",
(allow_kdump == 0) ? "OFF" : "ON",
(priority == 0) ? "LAST" : "FIRST");
return 0;
}
static void hpwdt_exit_nmi_decoding(void)
{
unregister_die_notifier(&die_notifier);
if (cru_rom_addr)
iounmap(cru_rom_addr);
}
static void __devinit hpwdt_check_nmi_decoding(struct pci_dev *dev)
{
}
static int __devinit hpwdt_init_nmi_decoding(struct pci_dev *dev)
{
return 0;
}
static void hpwdt_exit_nmi_decoding(void)
{
}
static int __devinit hpwdt_init_one(struct pci_dev *dev,
const struct pci_device_id *ent)
{
int retval;
hpwdt_check_nmi_decoding(dev);
if (dev->subsystem_vendor != PCI_VENDOR_ID_HP) {
dev_warn(&dev->dev,
"This server does not have an iLO2+ ASIC.\n");
return -ENODEV;
}
if (pci_enable_device(dev)) {
dev_warn(&dev->dev,
"Not possible to enable PCI Device: 0x%x:0x%x.\n",
ent->vendor, ent->device);
return -ENODEV;
}
pci_mem_addr = pci_iomap(dev, 1, 0x80);
if (!pci_mem_addr) {
dev_warn(&dev->dev,
"Unable to detect the iLO2+ server memory.\n");
retval = -ENOMEM;
goto error_pci_iomap;
}
hpwdt_timer_reg = pci_mem_addr + 0x70;
hpwdt_timer_con = pci_mem_addr + 0x72;
if (hpwdt_change_timer(soft_margin))
hpwdt_change_timer(DEFAULT_MARGIN);
retval = hpwdt_init_nmi_decoding(dev);
if (retval != 0)
goto error_init_nmi_decoding;
retval = misc_register(&hpwdt_miscdev);
if (retval < 0) {
dev_warn(&dev->dev,
"Unable to register miscdev on minor=%d (err=%d).\n",
WATCHDOG_MINOR, retval);
goto error_misc_register;
}
dev_info(&dev->dev, "HP Watchdog Timer Driver: %s"
", timer margin: %d seconds (nowayout=%d).\n",
HPWDT_VERSION, soft_margin, nowayout);
return 0;
error_misc_register:
hpwdt_exit_nmi_decoding();
error_init_nmi_decoding:
pci_iounmap(dev, pci_mem_addr);
error_pci_iomap:
pci_disable_device(dev);
return retval;
}
static void __devexit hpwdt_exit(struct pci_dev *dev)
{
if (!nowayout)
hpwdt_stop();
misc_deregister(&hpwdt_miscdev);
hpwdt_exit_nmi_decoding();
pci_iounmap(dev, pci_mem_addr);
pci_disable_device(dev);
}
static void __exit hpwdt_cleanup(void)
{
pci_unregister_driver(&hpwdt_driver);
}
static int __init hpwdt_init(void)
{
return pci_register_driver(&hpwdt_driver);
}
