static void __asr_toggle(void)
{
unsigned char reg;
reg = inb(asr_read_addr);
outb(reg & ~asr_toggle_mask, asr_write_addr);
reg = inb(asr_read_addr);
outb(reg | asr_toggle_mask, asr_write_addr);
reg = inb(asr_read_addr);
outb(reg & ~asr_toggle_mask, asr_write_addr);
reg = inb(asr_read_addr);
}
static void asr_toggle(void)
{
spin_lock(&asr_lock);
__asr_toggle();
spin_unlock(&asr_lock);
}
static void asr_enable(void)
{
unsigned char reg;
spin_lock(&asr_lock);
if (asr_type == ASMTYPE_TOPAZ) {
reg = inb(asr_read_addr);
outb(reg & ~(TOPAZ_ASR_TOGGLE | TOPAZ_ASR_DISABLE),
asr_read_addr);
} else {
__asr_toggle();
reg = inb(asr_read_addr);
outb(reg & ~asr_disable_mask, asr_write_addr);
}
reg = inb(asr_read_addr);
spin_unlock(&asr_lock);
}
static void asr_disable(void)
{
unsigned char reg;
spin_lock(&asr_lock);
reg = inb(asr_read_addr);
if (asr_type == ASMTYPE_TOPAZ)
outb(reg | TOPAZ_ASR_TOGGLE | TOPAZ_ASR_DISABLE,
asr_read_addr);
else {
outb(reg | asr_toggle_mask, asr_write_addr);
reg = inb(asr_read_addr);
outb(reg | asr_disable_mask, asr_write_addr);
}
reg = inb(asr_read_addr);
spin_unlock(&asr_lock);
}
static int __init asr_get_base_address(void)
{
unsigned char low, high;
const char *type = "";
asr_length = 1;
switch (asr_type) {
case ASMTYPE_TOPAZ:
outb(0x07, 0x2e);
outb(0x07, 0x2f);
outb(0x60, 0x2e);
high = inb(0x2f);
outb(0x61, 0x2e);
low = inb(0x2f);
asr_base = (high << 16) | low;
asr_read_addr = asr_write_addr =
asr_base + TOPAZ_ASR_REG_OFFSET;
asr_length = 5;
break;
case ASMTYPE_JASPER:
type = "Jaspers ";
#if 0
u32 r;
pdev = pci_get_bus_and_slot(0, DEVFN(0x1f, 0));
if (pdev == NULL)
return -ENODEV;
pci_read_config_dword(pdev, 0x58, &r);
asr_base = r & 0xFFFE;
pci_dev_put(pdev);
#else
outl(0x8000f858, 0xcf8);
asr_base = inl(0xcfc) & 0xfffe;
#endif
asr_read_addr = asr_write_addr =
asr_base + JASPER_ASR_REG_OFFSET;
asr_toggle_mask = JASPER_ASR_TOGGLE_MASK;
asr_disable_mask = JASPER_ASR_DISABLE_MASK;
asr_length = JASPER_ASR_REG_OFFSET + 1;
break;
case ASMTYPE_PEARL:
type = "Pearls ";
asr_base = PEARL_BASE;
asr_read_addr = PEARL_READ;
asr_write_addr = PEARL_WRITE;
asr_toggle_mask = PEARL_ASR_TOGGLE_MASK;
asr_disable_mask = PEARL_ASR_DISABLE_MASK;
asr_length = 4;
break;
case ASMTYPE_JUNIPER:
type = "Junipers ";
asr_base = JUNIPER_BASE_ADDRESS;
asr_read_addr = asr_write_addr = asr_base;
asr_toggle_mask = JUNIPER_ASR_TOGGLE_MASK;
asr_disable_mask = JUNIPER_ASR_DISABLE_MASK;
break;
case ASMTYPE_SPRUCE:
type = "Spruce's ";
asr_base = SPRUCE_BASE_ADDRESS;
asr_read_addr = asr_write_addr = asr_base;
asr_toggle_mask = SPRUCE_ASR_TOGGLE_MASK;
asr_disable_mask = SPRUCE_ASR_DISABLE_MASK;
break;
}
if (!request_region(asr_base, asr_length, "ibmasr")) {
printk(KERN_ERR PFX "address %#x already in use\n",
asr_base);
return -EBUSY;
}
printk(KERN_INFO PFX "found %sASR @ addr %#x\n", type, asr_base);
return 0;
}
static ssize_t asr_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
if (!nowayout) {
size_t i;
asr_expect_close = 0;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
if (c == 'V')
asr_expect_close = 42;
}
}
asr_toggle();
}
return count;
}
static long asr_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING |
WDIOF_MAGICCLOSE,
.identity = "IBM ASR",
};
void __user *argp = (void __user *)arg;
int __user *p = argp;
int heartbeat;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
{
int new_options, retval = -EINVAL;
if (get_user(new_options, p))
return -EFAULT;
if (new_options & WDIOS_DISABLECARD) {
asr_disable();
retval = 0;
}
if (new_options & WDIOS_ENABLECARD) {
asr_enable();
asr_toggle();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
asr_toggle();
return 0;
case WDIOC_GETTIMEOUT:
heartbeat = 256;
return put_user(heartbeat, p);
default:
return -ENOTTY;
}
}
static int asr_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &asr_is_open))
return -EBUSY;
asr_toggle();
asr_enable();
return nonseekable_open(inode, file);
}
static int asr_release(struct inode *inode, struct file *file)
{
if (asr_expect_close == 42)
asr_disable();
else {
printk(KERN_CRIT PFX
"unexpected close, not stopping watchdog!\n");
asr_toggle();
}
clear_bit(0, &asr_is_open);
asr_expect_close = 0;
return 0;
}
static int __init ibmasr_init(void)
{
struct ibmasr_id *id;
int rc;
for (id = ibmasr_id_table; id->desc; id++) {
if (dmi_find_device(DMI_DEV_TYPE_OTHER, id->desc, NULL)) {
asr_type = id->type;
break;
}
}
if (!asr_type)
return -ENODEV;
rc = asr_get_base_address();
if (rc)
return rc;
rc = misc_register(&asr_miscdev);
if (rc < 0) {
release_region(asr_base, asr_length);
printk(KERN_ERR PFX "failed to register misc device\n");
return rc;
}
return 0;
}
static void __exit ibmasr_exit(void)
{
if (!nowayout)
asr_disable();
misc_deregister(&asr_miscdev);
release_region(asr_base, asr_length);
}
