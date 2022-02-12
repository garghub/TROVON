static void cs5530a_warm_reset(struct pci_dev *dev)
{
pci_write_config_byte(dev, 0x44, 0x1);
udelay(50);
return;
}
static void cs5536_warm_reset(struct pci_dev *dev)
{
wrmsrl(MSR_DIVIL_SOFT_RESET, 1ULL);
udelay(50);
}
static void rdc321x_reset(struct pci_dev *dev)
{
unsigned i;
outl(0x80003840, 0xCF8);
i = inl(0xCFC);
i |= 0x1600;
outl(i, 0xCFC);
outb(1, 0x92);
}
static void ce4100_reset(struct pci_dev *dev)
{
int i;
for (i = 0; i < 10; i++) {
outb(0x2, 0xcf9);
udelay(50);
}
}
void mach_reboot_fixups(void)
{
const struct device_fixup *cur;
struct pci_dev *dev;
int i;
if (in_interrupt())
return;
for (i=0; i < ARRAY_SIZE(fixups_table); i++) {
cur = &(fixups_table[i]);
dev = pci_get_device(cur->vendor, cur->device, NULL);
if (!dev)
continue;
cur->reboot_fixup(dev);
pci_dev_put(dev);
}
}
