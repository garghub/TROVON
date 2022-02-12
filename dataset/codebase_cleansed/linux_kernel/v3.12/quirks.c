static void quirk_mmio_always_on(struct pci_dev *dev)
{
dev->mmio_always_on = 1;
}
static void quirk_mellanox_tavor(struct pci_dev *dev)
{
dev->broken_parity_status = 1;
}
static void quirk_passive_release(struct pci_dev *dev)
{
struct pci_dev *d = NULL;
unsigned char dlc;
while ((d = pci_get_device(PCI_VENDOR_ID_INTEL, PCI_DEVICE_ID_INTEL_82371SB_0, d))) {
pci_read_config_byte(d, 0x82, &dlc);
if (!(dlc & 1<<1)) {
dev_info(&d->dev, "PIIX3: Enabling Passive Release\n");
dlc |= 1<<1;
pci_write_config_byte(d, 0x82, dlc);
}
}
}
static void quirk_isa_dma_hangs(struct pci_dev *dev)
{
if (!isa_dma_bridge_buggy) {
isa_dma_bridge_buggy=1;
dev_info(&dev->dev, "Activating ISA DMA hang workarounds\n");
}
}
static void quirk_tigerpoint_bm_sts(struct pci_dev *dev)
{
u32 pmbase;
u16 pm1a;
pci_read_config_dword(dev, 0x40, &pmbase);
pmbase = pmbase & 0xff80;
pm1a = inw(pmbase);
if (pm1a & 0x10) {
dev_info(&dev->dev, FW_BUG "TigerPoint LPC.BM_STS cleared\n");
outw(0x10, pmbase);
}
}
static void quirk_nopcipci(struct pci_dev *dev)
{
if ((pci_pci_problems & PCIPCI_FAIL)==0) {
dev_info(&dev->dev, "Disabling direct PCI/PCI transfers\n");
pci_pci_problems |= PCIPCI_FAIL;
}
}
static void quirk_nopciamd(struct pci_dev *dev)
{
u8 rev;
pci_read_config_byte(dev, 0x08, &rev);
if (rev == 0x13) {
dev_info(&dev->dev, "Chipset erratum: Disabling direct PCI/AGP transfers\n");
pci_pci_problems |= PCIAGP_FAIL;
}
}
static void quirk_triton(struct pci_dev *dev)
{
if ((pci_pci_problems&PCIPCI_TRITON)==0) {
dev_info(&dev->dev, "Limiting direct PCI/PCI transfers\n");
pci_pci_problems |= PCIPCI_TRITON;
}
}
static void quirk_vialatency(struct pci_dev *dev)
{
struct pci_dev *p;
u8 busarb;
p = pci_get_device(PCI_VENDOR_ID_VIA, PCI_DEVICE_ID_VIA_82C686, NULL);
if (p!=NULL) {
if (p->revision < 0x40 || p->revision > 0x42)
goto exit;
} else {
p = pci_get_device(PCI_VENDOR_ID_VIA, PCI_DEVICE_ID_VIA_8231, NULL);
if (p==NULL)
goto exit;
if (p->revision < 0x10 || p->revision > 0x12)
goto exit;
}
pci_read_config_byte(dev, 0x76, &busarb);
busarb &= ~(1<<5);
busarb |= (1<<4);
pci_write_config_byte(dev, 0x76, busarb);
dev_info(&dev->dev, "Applying VIA southbridge workaround\n");
exit:
pci_dev_put(p);
}
static void quirk_viaetbf(struct pci_dev *dev)
{
if ((pci_pci_problems&PCIPCI_VIAETBF)==0) {
dev_info(&dev->dev, "Limiting direct PCI/PCI transfers\n");
pci_pci_problems |= PCIPCI_VIAETBF;
}
}
static void quirk_vsfx(struct pci_dev *dev)
{
if ((pci_pci_problems&PCIPCI_VSFX)==0) {
dev_info(&dev->dev, "Limiting direct PCI/PCI transfers\n");
pci_pci_problems |= PCIPCI_VSFX;
}
}
static void quirk_alimagik(struct pci_dev *dev)
{
if ((pci_pci_problems&PCIPCI_ALIMAGIK)==0) {
dev_info(&dev->dev, "Limiting direct PCI/PCI transfers\n");
pci_pci_problems |= PCIPCI_ALIMAGIK|PCIPCI_TRITON;
}
}
static void quirk_natoma(struct pci_dev *dev)
{
if ((pci_pci_problems&PCIPCI_NATOMA)==0) {
dev_info(&dev->dev, "Limiting direct PCI/PCI transfers\n");
pci_pci_problems |= PCIPCI_NATOMA;
}
}
static void quirk_citrine(struct pci_dev *dev)
{
dev->cfg_size = 0xA0;
}
static void quirk_s3_64M(struct pci_dev *dev)
{
struct resource *r = &dev->resource[0];
if ((r->start & 0x3ffffff) || r->end != r->start + 0x3ffffff) {
r->start = 0;
r->end = 0x3ffffff;
}
}
static void quirk_cs5536_vsa(struct pci_dev *dev)
{
if (pci_resource_len(dev, 0) != 8) {
struct resource *res = &dev->resource[0];
res->end = res->start + 8 - 1;
dev_info(&dev->dev, "CS5536 ISA bridge bug detected "
"(incorrect header); workaround applied.\n");
}
}
static void quirk_io_region(struct pci_dev *dev, int port,
unsigned size, int nr, const char *name)
{
u16 region;
struct pci_bus_region bus_region;
struct resource *res = dev->resource + nr;
pci_read_config_word(dev, port, &region);
region &= ~(size - 1);
if (!region)
return;
res->name = pci_name(dev);
res->flags = IORESOURCE_IO;
bus_region.start = region;
bus_region.end = region + size - 1;
pcibios_bus_to_resource(dev, res, &bus_region);
if (!pci_claim_resource(dev, nr))
dev_info(&dev->dev, "quirk: %pR claimed by %s\n", res, name);
}
static void quirk_ati_exploding_mce(struct pci_dev *dev)
{
dev_info(&dev->dev, "ATI Northbridge, reserving I/O ports 0x3b0 to 0x3bb\n");
request_region(0x3b0, 0x0C, "RadeonIGP");
request_region(0x3d3, 0x01, "RadeonIGP");
}
static void quirk_ali7101_acpi(struct pci_dev *dev)
{
quirk_io_region(dev, 0xE0, 64, PCI_BRIDGE_RESOURCES, "ali7101 ACPI");
quirk_io_region(dev, 0xE2, 32, PCI_BRIDGE_RESOURCES+1, "ali7101 SMB");
}
static void piix4_io_quirk(struct pci_dev *dev, const char *name, unsigned int port, unsigned int enable)
{
u32 devres;
u32 mask, size, base;
pci_read_config_dword(dev, port, &devres);
if ((devres & enable) != enable)
return;
mask = (devres >> 16) & 15;
base = devres & 0xffff;
size = 16;
for (;;) {
unsigned bit = size >> 1;
if ((bit & mask) == bit)
break;
size = bit;
}
base &= -size;
dev_info(&dev->dev, "%s PIO at %04x-%04x\n", name, base, base + size - 1);
}
static void piix4_mem_quirk(struct pci_dev *dev, const char *name, unsigned int port, unsigned int enable)
{
u32 devres;
u32 mask, size, base;
pci_read_config_dword(dev, port, &devres);
if ((devres & enable) != enable)
return;
base = devres & 0xffff0000;
mask = (devres & 0x3f) << 16;
size = 128 << 16;
for (;;) {
unsigned bit = size >> 1;
if ((bit & mask) == bit)
break;
size = bit;
}
base &= -size;
dev_info(&dev->dev, "%s MMIO at %04x-%04x\n", name, base, base + size - 1);
}
static void quirk_piix4_acpi(struct pci_dev *dev)
{
u32 res_a;
quirk_io_region(dev, 0x40, 64, PCI_BRIDGE_RESOURCES, "PIIX4 ACPI");
quirk_io_region(dev, 0x90, 16, PCI_BRIDGE_RESOURCES+1, "PIIX4 SMB");
pci_read_config_dword(dev, 0x5c, &res_a);
piix4_io_quirk(dev, "PIIX4 devres B", 0x60, 3 << 21);
piix4_io_quirk(dev, "PIIX4 devres C", 0x64, 3 << 21);
if (res_a & (1 << 29)) {
piix4_io_quirk(dev, "PIIX4 devres E", 0x68, 1 << 20);
piix4_mem_quirk(dev, "PIIX4 devres F", 0x6c, 1 << 7);
}
if (res_a & (1 << 30)) {
piix4_io_quirk(dev, "PIIX4 devres G", 0x70, 1 << 20);
piix4_mem_quirk(dev, "PIIX4 devres H", 0x74, 1 << 7);
}
piix4_io_quirk(dev, "PIIX4 devres I", 0x78, 1 << 20);
piix4_io_quirk(dev, "PIIX4 devres J", 0x7c, 1 << 20);
}
static void quirk_ich4_lpc_acpi(struct pci_dev *dev)
{
u8 enable;
pci_read_config_byte(dev, ICH_ACPI_CNTL, &enable);
if (enable & ICH4_ACPI_EN)
quirk_io_region(dev, ICH_PMBASE, 128, PCI_BRIDGE_RESOURCES,
"ICH4 ACPI/GPIO/TCO");
pci_read_config_byte(dev, ICH4_GPIO_CNTL, &enable);
if (enable & ICH4_GPIO_EN)
quirk_io_region(dev, ICH4_GPIOBASE, 64, PCI_BRIDGE_RESOURCES+1,
"ICH4 GPIO");
}
static void ich6_lpc_acpi_gpio(struct pci_dev *dev)
{
u8 enable;
pci_read_config_byte(dev, ICH_ACPI_CNTL, &enable);
if (enable & ICH6_ACPI_EN)
quirk_io_region(dev, ICH_PMBASE, 128, PCI_BRIDGE_RESOURCES,
"ICH6 ACPI/GPIO/TCO");
pci_read_config_byte(dev, ICH6_GPIO_CNTL, &enable);
if (enable & ICH6_GPIO_EN)
quirk_io_region(dev, ICH6_GPIOBASE, 64, PCI_BRIDGE_RESOURCES+1,
"ICH6 GPIO");
}
static void ich6_lpc_generic_decode(struct pci_dev *dev, unsigned reg, const char *name, int dynsize)
{
u32 val;
u32 size, base;
pci_read_config_dword(dev, reg, &val);
if (!(val & 1))
return;
base = val & 0xfffc;
if (dynsize) {
size = 16;
} else {
size = 128;
}
base &= ~(size-1);
dev_info(&dev->dev, "%s PIO at %04x-%04x\n", name, base, base+size-1);
}
static void quirk_ich6_lpc(struct pci_dev *dev)
{
ich6_lpc_acpi_gpio(dev);
ich6_lpc_generic_decode(dev, 0x84, "LPC Generic IO decode 1", 0);
ich6_lpc_generic_decode(dev, 0x88, "LPC Generic IO decode 2", 1);
}
static void ich7_lpc_generic_decode(struct pci_dev *dev, unsigned reg, const char *name)
{
u32 val;
u32 mask, base;
pci_read_config_dword(dev, reg, &val);
if (!(val & 1))
return;
base = val & 0xfffc;
mask = (val >> 16) & 0xfc;
mask |= 3;
dev_info(&dev->dev, "%s PIO at %04x (mask %04x)\n", name, base, mask);
}
static void quirk_ich7_lpc(struct pci_dev *dev)
{
ich6_lpc_acpi_gpio(dev);
ich7_lpc_generic_decode(dev, 0x84, "ICH7 LPC Generic IO decode 1");
ich7_lpc_generic_decode(dev, 0x88, "ICH7 LPC Generic IO decode 2");
ich7_lpc_generic_decode(dev, 0x8c, "ICH7 LPC Generic IO decode 3");
ich7_lpc_generic_decode(dev, 0x90, "ICH7 LPC Generic IO decode 4");
}
static void quirk_vt82c586_acpi(struct pci_dev *dev)
{
if (dev->revision & 0x10)
quirk_io_region(dev, 0x48, 256, PCI_BRIDGE_RESOURCES,
"vt82c586 ACPI");
}
static void quirk_vt82c686_acpi(struct pci_dev *dev)
{
quirk_vt82c586_acpi(dev);
quirk_io_region(dev, 0x70, 128, PCI_BRIDGE_RESOURCES+1,
"vt82c686 HW-mon");
quirk_io_region(dev, 0x90, 16, PCI_BRIDGE_RESOURCES+2, "vt82c686 SMB");
}
static void quirk_vt8235_acpi(struct pci_dev *dev)
{
quirk_io_region(dev, 0x88, 128, PCI_BRIDGE_RESOURCES, "vt8235 PM");
quirk_io_region(dev, 0xd0, 16, PCI_BRIDGE_RESOURCES+1, "vt8235 SMB");
}
static void quirk_xio2000a(struct pci_dev *dev)
{
struct pci_dev *pdev;
u16 command;
dev_warn(&dev->dev, "TI XIO2000a quirk detected; "
"secondary bus fast back-to-back transfers disabled\n");
list_for_each_entry(pdev, &dev->subordinate->devices, bus_list) {
pci_read_config_word(pdev, PCI_COMMAND, &command);
if (command & PCI_COMMAND_FAST_BACK)
pci_write_config_word(pdev, PCI_COMMAND, command & ~PCI_COMMAND_FAST_BACK);
}
}
static void quirk_via_ioapic(struct pci_dev *dev)
{
u8 tmp;
if (nr_ioapics < 1)
tmp = 0;
else
tmp = 0x1f;
dev_info(&dev->dev, "%sbling VIA external APIC routing\n",
tmp == 0 ? "Disa" : "Ena");
pci_write_config_byte (dev, 0x58, tmp);
}
static void quirk_via_vt8237_bypass_apic_deassert(struct pci_dev *dev)
{
u8 misc_control2;
#define BYPASS_APIC_DEASSERT 8
pci_read_config_byte(dev, 0x5B, &misc_control2);
if (!(misc_control2 & BYPASS_APIC_DEASSERT)) {
dev_info(&dev->dev, "Bypassing VIA 8237 APIC De-Assert Message\n");
pci_write_config_byte(dev, 0x5B, misc_control2|BYPASS_APIC_DEASSERT);
}
}
static void quirk_amd_ioapic(struct pci_dev *dev)
{
if (dev->revision >= 0x02) {
dev_warn(&dev->dev, "I/O APIC: AMD Erratum #22 may be present. In the event of instability try\n");
dev_warn(&dev->dev, " : booting with the \"noapic\" option\n");
}
}
static void quirk_ioapic_rmw(struct pci_dev *dev)
{
if (dev->devfn == 0 && dev->bus->number == 0)
sis_apic_bug = 1;
}
static void quirk_amd_8131_mmrbc(struct pci_dev *dev)
{
if (dev->subordinate && dev->revision <= 0x12) {
dev_info(&dev->dev, "AMD8131 rev %x detected; "
"disabling PCI-X MMRBC\n", dev->revision);
dev->subordinate->bus_flags |= PCI_BUS_FLAGS_NO_MMRBC;
}
}
static void quirk_via_acpi(struct pci_dev *d)
{
u8 irq;
pci_read_config_byte(d, 0x42, &irq);
irq &= 0xf;
if (irq && (irq != 2))
d->irq = irq;
}
static void quirk_via_bridge(struct pci_dev *dev)
{
switch (dev->device) {
case PCI_DEVICE_ID_VIA_82C686:
via_vlink_dev_lo = PCI_SLOT(dev->devfn);
via_vlink_dev_hi = PCI_SLOT(dev->devfn);
break;
case PCI_DEVICE_ID_VIA_8237:
case PCI_DEVICE_ID_VIA_8237A:
via_vlink_dev_lo = 15;
break;
case PCI_DEVICE_ID_VIA_8235:
via_vlink_dev_lo = 16;
break;
case PCI_DEVICE_ID_VIA_8231:
case PCI_DEVICE_ID_VIA_8233_0:
case PCI_DEVICE_ID_VIA_8233A:
case PCI_DEVICE_ID_VIA_8233C_0:
via_vlink_dev_lo = 17;
break;
}
}
static void quirk_via_vlink(struct pci_dev *dev)
{
u8 irq, new_irq;
if (via_vlink_dev_lo == -1)
return;
new_irq = dev->irq;
if (!new_irq || new_irq > 15)
return;
if (dev->bus->number != 0 || PCI_SLOT(dev->devfn) > via_vlink_dev_hi ||
PCI_SLOT(dev->devfn) < via_vlink_dev_lo)
return;
pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &irq);
if (new_irq != irq) {
dev_info(&dev->dev, "VIA VLink IRQ fixup, from %d to %d\n",
irq, new_irq);
udelay(15);
pci_write_config_byte(dev, PCI_INTERRUPT_LINE, new_irq);
}
}
static void quirk_vt82c598_id(struct pci_dev *dev)
{
pci_write_config_byte(dev, 0xfc, 0);
pci_read_config_word(dev, PCI_DEVICE_ID, &dev->device);
}
static void quirk_cardbus_legacy(struct pci_dev *dev)
{
pci_write_config_dword(dev, PCI_CB_LEGACY_MODE_BASE, 0);
}
static void quirk_amd_ordering(struct pci_dev *dev)
{
u32 pcic;
pci_read_config_dword(dev, 0x4C, &pcic);
if ((pcic&6)!=6) {
pcic |= 6;
dev_warn(&dev->dev, "BIOS failed to enable PCI standards compliance; fixing this error\n");
pci_write_config_dword(dev, 0x4C, pcic);
pci_read_config_dword(dev, 0x84, &pcic);
pcic |= (1<<23);
pci_write_config_dword(dev, 0x84, pcic);
}
}
static void quirk_dunord(struct pci_dev *dev)
{
struct resource *r = &dev->resource [1];
r->start = 0;
r->end = 0xffffff;
}
static void quirk_transparent_bridge(struct pci_dev *dev)
{
dev->transparent = 1;
}
static void quirk_mediagx_master(struct pci_dev *dev)
{
u8 reg;
pci_read_config_byte(dev, 0x41, &reg);
if (reg & 2) {
reg &= ~2;
dev_info(&dev->dev, "Fixup for MediaGX/Geode Slave Disconnect Boundary (0x41=0x%02x)\n", reg);
pci_write_config_byte(dev, 0x41, reg);
}
}
static void quirk_disable_pxb(struct pci_dev *pdev)
{
u16 config;
if (pdev->revision != 0x04)
return;
pci_read_config_word(pdev, 0x40, &config);
if (config & (1<<6)) {
config &= ~(1<<6);
pci_write_config_word(pdev, 0x40, config);
dev_info(&pdev->dev, "C0 revision 450NX. Disabling PCI restreaming\n");
}
}
static void quirk_amd_ide_mode(struct pci_dev *pdev)
{
u8 tmp;
pci_read_config_byte(pdev, PCI_CLASS_DEVICE, &tmp);
if (tmp == 0x01) {
pci_read_config_byte(pdev, 0x40, &tmp);
pci_write_config_byte(pdev, 0x40, tmp|1);
pci_write_config_byte(pdev, 0x9, 1);
pci_write_config_byte(pdev, 0xa, 6);
pci_write_config_byte(pdev, 0x40, tmp);
pdev->class = PCI_CLASS_STORAGE_SATA_AHCI;
dev_info(&pdev->dev, "set SATA to AHCI mode\n");
}
}
static void quirk_svwks_csb5ide(struct pci_dev *pdev)
{
u8 prog;
pci_read_config_byte(pdev, PCI_CLASS_PROG, &prog);
if (prog & 5) {
prog &= ~5;
pdev->class &= ~5;
pci_write_config_byte(pdev, PCI_CLASS_PROG, prog);
}
}
static void quirk_ide_samemode(struct pci_dev *pdev)
{
u8 prog;
pci_read_config_byte(pdev, PCI_CLASS_PROG, &prog);
if (((prog & 1) && !(prog & 4)) || ((prog & 4) && !(prog & 1))) {
dev_info(&pdev->dev, "IDE mode mismatch; forcing legacy mode\n");
prog &= ~5;
pdev->class &= ~5;
pci_write_config_byte(pdev, PCI_CLASS_PROG, prog);
}
}
static void quirk_no_ata_d3(struct pci_dev *pdev)
{
pdev->dev_flags |= PCI_DEV_FLAGS_NO_D3;
}
static void quirk_eisa_bridge(struct pci_dev *dev)
{
dev->class = PCI_CLASS_BRIDGE_EISA << 8;
}
static void asus_hides_smbus_hostbridge(struct pci_dev *dev)
{
if (unlikely(dev->subsystem_vendor == PCI_VENDOR_ID_ASUSTEK)) {
if (dev->device == PCI_DEVICE_ID_INTEL_82845_HB)
switch(dev->subsystem_device) {
case 0x8025:
case 0x8070:
case 0x8088:
case 0x1626:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_82845G_HB)
switch(dev->subsystem_device) {
case 0x80b1:
case 0x80b2:
case 0x8093:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_82850_HB)
switch(dev->subsystem_device) {
case 0x8030:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_7205_0)
switch (dev->subsystem_device) {
case 0x8070:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_E7501_MCH)
switch (dev->subsystem_device) {
case 0x80c9:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_82855GM_HB)
switch (dev->subsystem_device) {
case 0x1751:
case 0x1821:
case 0x1897:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_82855PM_HB)
switch (dev->subsystem_device) {
case 0x184b:
case 0x186a:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_82865_HB)
switch (dev->subsystem_device) {
case 0x80f2:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_82915GM_HB)
switch (dev->subsystem_device) {
case 0x1882:
case 0x1977:
asus_hides_smbus = 1;
}
} else if (unlikely(dev->subsystem_vendor == PCI_VENDOR_ID_HP)) {
if (dev->device == PCI_DEVICE_ID_INTEL_82855PM_HB)
switch(dev->subsystem_device) {
case 0x088C:
case 0x0890:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_82865_HB)
switch (dev->subsystem_device) {
case 0x12bc:
case 0x12bd:
case 0x006a:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_82875_HB)
switch (dev->subsystem_device) {
case 0x12bf:
asus_hides_smbus = 1;
}
} else if (unlikely(dev->subsystem_vendor == PCI_VENDOR_ID_SAMSUNG)) {
if (dev->device == PCI_DEVICE_ID_INTEL_82855PM_HB)
switch(dev->subsystem_device) {
case 0xC00C:
asus_hides_smbus = 1;
}
} else if (unlikely(dev->subsystem_vendor == PCI_VENDOR_ID_COMPAQ)) {
if (dev->device == PCI_DEVICE_ID_INTEL_82855PM_HB)
switch(dev->subsystem_device) {
case 0x0058:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_82810_IG3)
switch(dev->subsystem_device) {
case 0xB16C:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_82801DB_2)
switch(dev->subsystem_device) {
case 0x00b8:
case 0x00b9:
case 0x00ba:
asus_hides_smbus = 1;
}
else if (dev->device == PCI_DEVICE_ID_INTEL_82815_CGC)
switch (dev->subsystem_device) {
case 0x001A:
asus_hides_smbus = 1;
}
}
}
static void asus_hides_smbus_lpc(struct pci_dev *dev)
{
u16 val;
if (likely(!asus_hides_smbus))
return;
pci_read_config_word(dev, 0xF2, &val);
if (val & 0x8) {
pci_write_config_word(dev, 0xF2, val & (~0x8));
pci_read_config_word(dev, 0xF2, &val);
if (val & 0x8)
dev_info(&dev->dev, "i801 SMBus device continues to play 'hide and seek'! 0x%x\n", val);
else
dev_info(&dev->dev, "Enabled i801 SMBus device\n");
}
}
static void asus_hides_smbus_lpc_ich6_suspend(struct pci_dev *dev)
{
u32 rcba;
if (likely(!asus_hides_smbus))
return;
WARN_ON(asus_rcba_base);
pci_read_config_dword(dev, 0xF0, &rcba);
asus_rcba_base = ioremap_nocache(rcba & 0xFFFFC000, 0x4000);
if (asus_rcba_base == NULL)
return;
}
static void asus_hides_smbus_lpc_ich6_resume_early(struct pci_dev *dev)
{
u32 val;
if (likely(!asus_hides_smbus || !asus_rcba_base))
return;
val = readl(asus_rcba_base + 0x3418);
writel(val & 0xFFFFFFF7, asus_rcba_base + 0x3418);
}
static void asus_hides_smbus_lpc_ich6_resume(struct pci_dev *dev)
{
if (likely(!asus_hides_smbus || !asus_rcba_base))
return;
iounmap(asus_rcba_base);
asus_rcba_base = NULL;
dev_info(&dev->dev, "Enabled ICH6/i801 SMBus device\n");
}
static void asus_hides_smbus_lpc_ich6(struct pci_dev *dev)
{
asus_hides_smbus_lpc_ich6_suspend(dev);
asus_hides_smbus_lpc_ich6_resume_early(dev);
asus_hides_smbus_lpc_ich6_resume(dev);
}
static void quirk_sis_96x_smbus(struct pci_dev *dev)
{
u8 val = 0;
pci_read_config_byte(dev, 0x77, &val);
if (val & 0x10) {
dev_info(&dev->dev, "Enabling SiS 96x SMBus\n");
pci_write_config_byte(dev, 0x77, val & ~0x10);
}
}
static void quirk_sis_503(struct pci_dev *dev)
{
u8 reg;
u16 devid;
pci_read_config_byte(dev, SIS_DETECT_REGISTER, &reg);
pci_write_config_byte(dev, SIS_DETECT_REGISTER, reg | (1 << 6));
pci_read_config_word(dev, PCI_DEVICE_ID, &devid);
if (((devid & 0xfff0) != 0x0960) && (devid != 0x0018)) {
pci_write_config_byte(dev, SIS_DETECT_REGISTER, reg);
return;
}
dev->device = devid;
quirk_sis_96x_smbus(dev);
}
static void asus_hides_ac97_lpc(struct pci_dev *dev)
{
u8 val;
int asus_hides_ac97 = 0;
if (likely(dev->subsystem_vendor == PCI_VENDOR_ID_ASUSTEK)) {
if (dev->device == PCI_DEVICE_ID_VIA_8237)
asus_hides_ac97 = 1;
}
if (!asus_hides_ac97)
return;
pci_read_config_byte(dev, 0x50, &val);
if (val & 0xc0) {
pci_write_config_byte(dev, 0x50, val & (~0xc0));
pci_read_config_byte(dev, 0x50, &val);
if (val & 0xc0)
dev_info(&dev->dev, "Onboard AC97/MC97 devices continue to play 'hide and seek'! 0x%x\n", val);
else
dev_info(&dev->dev, "Enabled onboard AC97/MC97 devices\n");
}
}
static void quirk_jmicron_ata(struct pci_dev *pdev)
{
u32 conf1, conf5, class;
u8 hdr;
if (PCI_FUNC(pdev->devfn))
return;
pci_read_config_dword(pdev, 0x40, &conf1);
pci_read_config_dword(pdev, 0x80, &conf5);
conf1 &= ~0x00CFF302;
conf5 &= ~(1 << 24);
switch (pdev->device) {
case PCI_DEVICE_ID_JMICRON_JMB360:
case PCI_DEVICE_ID_JMICRON_JMB362:
case PCI_DEVICE_ID_JMICRON_JMB364:
conf1 |= 0x0002A100;
break;
case PCI_DEVICE_ID_JMICRON_JMB365:
case PCI_DEVICE_ID_JMICRON_JMB366:
conf5 |= (1 << 24);
case PCI_DEVICE_ID_JMICRON_JMB361:
case PCI_DEVICE_ID_JMICRON_JMB363:
case PCI_DEVICE_ID_JMICRON_JMB369:
conf1 |= 0x00C2A1B3;
break;
case PCI_DEVICE_ID_JMICRON_JMB368:
conf1 |= 0x00C00000;
break;
}
pci_write_config_dword(pdev, 0x40, conf1);
pci_write_config_dword(pdev, 0x80, conf5);
pci_read_config_byte(pdev, PCI_HEADER_TYPE, &hdr);
pdev->hdr_type = hdr & 0x7f;
pdev->multifunction = !!(hdr & 0x80);
pci_read_config_dword(pdev, PCI_CLASS_REVISION, &class);
pdev->class = class >> 8;
}
static void quirk_alder_ioapic(struct pci_dev *pdev)
{
int i;
if ((pdev->class >> 8) != 0xff00)
return;
if (pci_resource_start(pdev, 0) && pci_resource_len(pdev, 0))
insert_resource(&iomem_resource, &pdev->resource[0]);
for (i=1; i < 6; i++) {
memset(&pdev->resource[i], 0, sizeof(pdev->resource[i]));
}
}
static void quirk_pcie_mch(struct pci_dev *pdev)
{
pci_msi_off(pdev);
pdev->no_msi = 1;
}
static void quirk_pcie_pxh(struct pci_dev *dev)
{
pci_msi_off(dev);
dev->no_msi = 1;
dev_warn(&dev->dev, "PXH quirk detected; SHPC device MSI disabled\n");
}
static void quirk_intel_pcie_pm(struct pci_dev * dev)
{
pci_pm_d3_delay = 120;
dev->no_d1d2 = 1;
}
static void quirk_reroute_to_boot_interrupts_intel(struct pci_dev *dev)
{
if (noioapicquirk || noioapicreroute)
return;
dev->irq_reroute_variant = INTEL_IRQ_REROUTE_VARIANT;
dev_info(&dev->dev, "rerouting interrupts for [%04x:%04x]\n",
dev->vendor, dev->device);
}
static void quirk_disable_intel_boot_interrupt(struct pci_dev *dev)
{
u16 pci_config_word;
if (noioapicquirk)
return;
pci_read_config_word(dev, INTEL_6300_IOAPIC_ABAR, &pci_config_word);
pci_config_word |= INTEL_6300_DISABLE_BOOT_IRQ;
pci_write_config_word(dev, INTEL_6300_IOAPIC_ABAR, pci_config_word);
dev_info(&dev->dev, "disabled boot interrupts on device [%04x:%04x]\n",
dev->vendor, dev->device);
}
static void quirk_disable_broadcom_boot_interrupt(struct pci_dev *dev)
{
u32 pci_config_dword;
u8 irq;
if (noioapicquirk)
return;
pci_read_config_dword(dev, BC_HT1000_FEATURE_REG, &pci_config_dword);
pci_write_config_dword(dev, BC_HT1000_FEATURE_REG, pci_config_dword |
BC_HT1000_PIC_REGS_ENABLE);
for (irq = 0x10; irq < 0x10 + 32; irq++) {
outb(irq, BC_HT1000_MAP_IDX);
outb(0x00, BC_HT1000_MAP_DATA);
}
pci_write_config_dword(dev, BC_HT1000_FEATURE_REG, pci_config_dword);
dev_info(&dev->dev, "disabled boot interrupts on device [%04x:%04x]\n",
dev->vendor, dev->device);
}
static void quirk_disable_amd_813x_boot_interrupt(struct pci_dev *dev)
{
u32 pci_config_dword;
if (noioapicquirk)
return;
if ((dev->revision == AMD_813X_REV_B1) ||
(dev->revision == AMD_813X_REV_B2))
return;
pci_read_config_dword(dev, AMD_813X_MISC, &pci_config_dword);
pci_config_dword &= ~AMD_813X_NOIOAMODE;
pci_write_config_dword(dev, AMD_813X_MISC, pci_config_dword);
dev_info(&dev->dev, "disabled boot interrupts on device [%04x:%04x]\n",
dev->vendor, dev->device);
}
static void quirk_disable_amd_8111_boot_interrupt(struct pci_dev *dev)
{
u16 pci_config_word;
if (noioapicquirk)
return;
pci_read_config_word(dev, AMD_8111_PCI_IRQ_ROUTING, &pci_config_word);
if (!pci_config_word) {
dev_info(&dev->dev, "boot interrupts on device [%04x:%04x] "
"already disabled\n", dev->vendor, dev->device);
return;
}
pci_write_config_word(dev, AMD_8111_PCI_IRQ_ROUTING, 0);
dev_info(&dev->dev, "disabled boot interrupts on device [%04x:%04x]\n",
dev->vendor, dev->device);
}
static void quirk_tc86c001_ide(struct pci_dev *dev)
{
struct resource *r = &dev->resource[0];
if (r->start & 0x8) {
r->start = 0;
r->end = 0xf;
}
}
static void quirk_plx_pci9050(struct pci_dev *dev)
{
unsigned int bar;
if (dev->revision >= 2)
return;
for (bar = 0; bar <= 1; bar++)
if (pci_resource_len(dev, bar) == 0x80 &&
(pci_resource_start(dev, bar) & 0x80)) {
struct resource *r = &dev->resource[bar];
dev_info(&dev->dev,
"Re-allocating PLX PCI 9050 BAR %u to length 256 to avoid bit 7 bug\n",
bar);
r->start = 0;
r->end = 0xff;
}
}
static void quirk_netmos(struct pci_dev *dev)
{
unsigned int num_parallel = (dev->subsystem_device & 0xf0) >> 4;
unsigned int num_serial = dev->subsystem_device & 0xf;
switch (dev->device) {
case PCI_DEVICE_ID_NETMOS_9835:
if (dev->subsystem_vendor == PCI_VENDOR_ID_IBM &&
dev->subsystem_device == 0x0299)
return;
case PCI_DEVICE_ID_NETMOS_9735:
case PCI_DEVICE_ID_NETMOS_9745:
case PCI_DEVICE_ID_NETMOS_9845:
case PCI_DEVICE_ID_NETMOS_9855:
if (num_parallel) {
dev_info(&dev->dev, "Netmos %04x (%u parallel, "
"%u serial); changing class SERIAL to OTHER "
"(use parport_serial)\n",
dev->device, num_parallel, num_serial);
dev->class = (PCI_CLASS_COMMUNICATION_OTHER << 8) |
(dev->class & 0xff);
}
}
}
static void quirk_e100_interrupt(struct pci_dev *dev)
{
u16 command, pmcsr;
u8 __iomem *csr;
u8 cmd_hi;
switch (dev->device) {
case 0x1029:
case 0x1030 ... 0x1034:
case 0x1038 ... 0x103E:
case 0x1050 ... 0x1057:
case 0x1059:
case 0x1064 ... 0x106B:
case 0x1091 ... 0x1095:
case 0x1209:
case 0x1229:
case 0x2449:
case 0x2459:
case 0x245D:
case 0x27DC:
break;
default:
return;
}
pci_read_config_word(dev, PCI_COMMAND, &command);
if (!(command & PCI_COMMAND_MEMORY) || !pci_resource_start(dev, 0))
return;
if (dev->pm_cap) {
pci_read_config_word(dev, dev->pm_cap + PCI_PM_CTRL, &pmcsr);
if ((pmcsr & PCI_PM_CTRL_STATE_MASK) != PCI_D0)
return;
}
csr = ioremap(pci_resource_start(dev, 0), 8);
if (!csr) {
dev_warn(&dev->dev, "Can't map e100 registers\n");
return;
}
cmd_hi = readb(csr + 3);
if (cmd_hi == 0) {
dev_warn(&dev->dev, "Firmware left e100 interrupts enabled; "
"disabling\n");
writeb(1, csr + 3);
}
iounmap(csr);
}
static void quirk_disable_aspm_l0s(struct pci_dev *dev)
{
dev_info(&dev->dev, "Disabling L0s\n");
pci_disable_link_state(dev, PCIE_LINK_STATE_L0S);
}
static void fixup_rev1_53c810(struct pci_dev *dev)
{
if (dev->class == PCI_CLASS_NOT_DEFINED) {
dev_info(&dev->dev, "NCR 53c810 rev 1 detected; setting PCI class\n");
dev->class = PCI_CLASS_STORAGE_SCSI;
}
}
static void quirk_p64h2_1k_io(struct pci_dev *dev)
{
u16 en1k;
pci_read_config_word(dev, 0x40, &en1k);
if (en1k & 0x200) {
dev_info(&dev->dev, "Enable I/O Space to 1KB granularity\n");
dev->io_window_1k = 1;
}
}
static void quirk_nvidia_ck804_pcie_aer_ext_cap(struct pci_dev *dev)
{
uint8_t b;
if (pci_read_config_byte(dev, 0xf41, &b) == 0) {
if (!(b & 0x20)) {
pci_write_config_byte(dev, 0xf41, b | 0x20);
dev_info(&dev->dev,
"Linking AER extended capability\n");
}
}
}
static void quirk_via_cx700_pci_parking_caching(struct pci_dev *dev)
{
struct pci_dev *p = pci_get_device(PCI_VENDOR_ID_VIA,
PCI_DEVICE_ID_VIA_8235_USB_2, NULL);
uint8_t b;
p = pci_get_device(PCI_VENDOR_ID_VIA, PCI_DEVICE_ID_VIA_8235_USB_2, p);
if (!p)
return;
pci_dev_put(p);
if (pci_read_config_byte(dev, 0x76, &b) == 0) {
if (b & 0x40) {
pci_write_config_byte(dev, 0x76, b ^ 0x40);
dev_info(&dev->dev,
"Disabling VIA CX700 PCI parking\n");
}
}
if (pci_read_config_byte(dev, 0x72, &b) == 0) {
if (b != 0) {
pci_write_config_byte(dev, 0x72, 0x0);
pci_write_config_byte(dev, 0x75, 0x1);
pci_write_config_byte(dev, 0x77, 0x0);
dev_info(&dev->dev,
"Disabling VIA CX700 PCI caching\n");
}
}
}
static void quirk_brcm_570x_limit_vpd(struct pci_dev *dev)
{
if ((dev->device == PCI_DEVICE_ID_NX2_5706) ||
(dev->device == PCI_DEVICE_ID_NX2_5706S) ||
(dev->device == PCI_DEVICE_ID_NX2_5708) ||
(dev->device == PCI_DEVICE_ID_NX2_5708S) ||
((dev->device == PCI_DEVICE_ID_NX2_5709) &&
(dev->revision & 0xf0) == 0x0)) {
if (dev->vpd)
dev->vpd->len = 0x80;
}
}
static void quirk_brcm_5719_limit_mrrs(struct pci_dev *dev)
{
u32 rev;
pci_read_config_dword(dev, 0xf4, &rev);
if (rev == 0x05719000) {
int readrq = pcie_get_readrq(dev);
if (readrq > 2048)
pcie_set_readrq(dev, 2048);
}
}
static void quirk_unhide_mch_dev6(struct pci_dev *dev)
{
u8 reg;
if (pci_read_config_byte(dev, 0xF4, &reg) == 0 && !(reg & 0x02)) {
dev_info(&dev->dev, "Enabling MCH 'Overflow' Device\n");
pci_write_config_byte(dev, 0xF4, reg | 0x02);
}
}
static void quirk_tile_plx_gen1(struct pci_dev *dev)
{
if (tile_plx_gen1) {
pci_write_config_dword(dev, 0x98, 0x1);
mdelay(50);
}
}
static void quirk_disable_all_msi(struct pci_dev *dev)
{
pci_no_msi();
dev_warn(&dev->dev, "MSI quirk detected; MSI disabled\n");
}
static void quirk_disable_msi(struct pci_dev *dev)
{
if (dev->subordinate) {
dev_warn(&dev->dev, "MSI quirk detected; "
"subordinate MSI disabled\n");
dev->subordinate->bus_flags |= PCI_BUS_FLAGS_NO_MSI;
}
}
static void quirk_amd_780_apc_msi(struct pci_dev *host_bridge)
{
struct pci_dev *apc_bridge;
apc_bridge = pci_get_slot(host_bridge->bus, PCI_DEVFN(1, 0));
if (apc_bridge) {
if (apc_bridge->device == 0x9602)
quirk_disable_msi(apc_bridge);
pci_dev_put(apc_bridge);
}
}
static int msi_ht_cap_enabled(struct pci_dev *dev)
{
int pos, ttl = 48;
pos = pci_find_ht_capability(dev, HT_CAPTYPE_MSI_MAPPING);
while (pos && ttl--) {
u8 flags;
if (pci_read_config_byte(dev, pos + HT_MSI_FLAGS,
&flags) == 0)
{
dev_info(&dev->dev, "Found %s HT MSI Mapping\n",
flags & HT_MSI_FLAGS_ENABLE ?
"enabled" : "disabled");
return (flags & HT_MSI_FLAGS_ENABLE) != 0;
}
pos = pci_find_next_ht_capability(dev, pos,
HT_CAPTYPE_MSI_MAPPING);
}
return 0;
}
static void quirk_msi_ht_cap(struct pci_dev *dev)
{
if (dev->subordinate && !msi_ht_cap_enabled(dev)) {
dev_warn(&dev->dev, "MSI quirk detected; "
"subordinate MSI disabled\n");
dev->subordinate->bus_flags |= PCI_BUS_FLAGS_NO_MSI;
}
}
static void quirk_nvidia_ck804_msi_ht_cap(struct pci_dev *dev)
{
struct pci_dev *pdev;
if (!dev->subordinate)
return;
pdev = pci_get_slot(dev->bus, 0);
if (!pdev)
return;
if (!msi_ht_cap_enabled(dev) && !msi_ht_cap_enabled(pdev)) {
dev_warn(&dev->dev, "MSI quirk detected; "
"subordinate MSI disabled\n");
dev->subordinate->bus_flags |= PCI_BUS_FLAGS_NO_MSI;
}
pci_dev_put(pdev);
}
static void ht_enable_msi_mapping(struct pci_dev *dev)
{
int pos, ttl = 48;
pos = pci_find_ht_capability(dev, HT_CAPTYPE_MSI_MAPPING);
while (pos && ttl--) {
u8 flags;
if (pci_read_config_byte(dev, pos + HT_MSI_FLAGS,
&flags) == 0) {
dev_info(&dev->dev, "Enabling HT MSI Mapping\n");
pci_write_config_byte(dev, pos + HT_MSI_FLAGS,
flags | HT_MSI_FLAGS_ENABLE);
}
pos = pci_find_next_ht_capability(dev, pos,
HT_CAPTYPE_MSI_MAPPING);
}
}
static void nvenet_msi_disable(struct pci_dev *dev)
{
const char *board_name = dmi_get_system_info(DMI_BOARD_NAME);
if (board_name &&
(strstr(board_name, "P5N32-SLI PREMIUM") ||
strstr(board_name, "P5N32-E SLI"))) {
dev_info(&dev->dev,
"Disabling msi for MCP55 NIC on P5N32-SLI\n");
dev->no_msi = 1;
}
}
static void nvbridge_check_legacy_irq_routing(struct pci_dev *dev)
{
u32 cfg;
if (!pci_find_capability(dev, PCI_CAP_ID_HT))
return;
pci_read_config_dword(dev, 0x74, &cfg);
if (cfg & ((1 << 2) | (1 << 15))) {
printk(KERN_INFO "Rewriting irq routing register on MCP55\n");
cfg &= ~((1 << 2) | (1 << 15));
pci_write_config_dword(dev, 0x74, cfg);
}
}
static int ht_check_msi_mapping(struct pci_dev *dev)
{
int pos, ttl = 48;
int found = 0;
pos = pci_find_ht_capability(dev, HT_CAPTYPE_MSI_MAPPING);
while (pos && ttl--) {
u8 flags;
if (found < 1)
found = 1;
if (pci_read_config_byte(dev, pos + HT_MSI_FLAGS,
&flags) == 0) {
if (flags & HT_MSI_FLAGS_ENABLE) {
if (found < 2) {
found = 2;
break;
}
}
}
pos = pci_find_next_ht_capability(dev, pos,
HT_CAPTYPE_MSI_MAPPING);
}
return found;
}
static int host_bridge_with_leaf(struct pci_dev *host_bridge)
{
struct pci_dev *dev;
int pos;
int i, dev_no;
int found = 0;
dev_no = host_bridge->devfn >> 3;
for (i = dev_no + 1; i < 0x20; i++) {
dev = pci_get_slot(host_bridge->bus, PCI_DEVFN(i, 0));
if (!dev)
continue;
pos = pci_find_ht_capability(dev, HT_CAPTYPE_SLAVE);
if (pos != 0) {
pci_dev_put(dev);
break;
}
if (ht_check_msi_mapping(dev)) {
found = 1;
pci_dev_put(dev);
break;
}
pci_dev_put(dev);
}
return found;
}
static int is_end_of_ht_chain(struct pci_dev *dev)
{
int pos, ctrl_off;
int end = 0;
u16 flags, ctrl;
pos = pci_find_ht_capability(dev, HT_CAPTYPE_SLAVE);
if (!pos)
goto out;
pci_read_config_word(dev, pos + PCI_CAP_FLAGS, &flags);
ctrl_off = ((flags >> 10) & 1) ?
PCI_HT_CAP_SLAVE_CTRL0 : PCI_HT_CAP_SLAVE_CTRL1;
pci_read_config_word(dev, pos + ctrl_off, &ctrl);
if (ctrl & (1 << 6))
end = 1;
out:
return end;
}
static void nv_ht_enable_msi_mapping(struct pci_dev *dev)
{
struct pci_dev *host_bridge;
int pos;
int i, dev_no;
int found = 0;
dev_no = dev->devfn >> 3;
for (i = dev_no; i >= 0; i--) {
host_bridge = pci_get_slot(dev->bus, PCI_DEVFN(i, 0));
if (!host_bridge)
continue;
pos = pci_find_ht_capability(host_bridge, HT_CAPTYPE_SLAVE);
if (pos != 0) {
found = 1;
break;
}
pci_dev_put(host_bridge);
}
if (!found)
return;
if (host_bridge == dev && is_end_of_ht_chain(host_bridge) &&
host_bridge_with_leaf(host_bridge))
goto out;
if (msi_ht_cap_enabled(host_bridge))
goto out;
ht_enable_msi_mapping(dev);
out:
pci_dev_put(host_bridge);
}
static void ht_disable_msi_mapping(struct pci_dev *dev)
{
int pos, ttl = 48;
pos = pci_find_ht_capability(dev, HT_CAPTYPE_MSI_MAPPING);
while (pos && ttl--) {
u8 flags;
if (pci_read_config_byte(dev, pos + HT_MSI_FLAGS,
&flags) == 0) {
dev_info(&dev->dev, "Disabling HT MSI Mapping\n");
pci_write_config_byte(dev, pos + HT_MSI_FLAGS,
flags & ~HT_MSI_FLAGS_ENABLE);
}
pos = pci_find_next_ht_capability(dev, pos,
HT_CAPTYPE_MSI_MAPPING);
}
}
static void __nv_msi_ht_cap_quirk(struct pci_dev *dev, int all)
{
struct pci_dev *host_bridge;
int pos;
int found;
if (!pci_msi_enabled())
return;
found = ht_check_msi_mapping(dev);
if (found == 0)
return;
host_bridge = pci_get_bus_and_slot(0, PCI_DEVFN(0, 0));
if (host_bridge == NULL) {
dev_warn(&dev->dev,
"nv_msi_ht_cap_quirk didn't locate host bridge\n");
return;
}
pos = pci_find_ht_capability(host_bridge, HT_CAPTYPE_SLAVE);
if (pos != 0) {
if (found == 1) {
if (all)
ht_enable_msi_mapping(dev);
else
nv_ht_enable_msi_mapping(dev);
}
goto out;
}
if (found == 1)
goto out;
ht_disable_msi_mapping(dev);
out:
pci_dev_put(host_bridge);
}
static void nv_msi_ht_cap_quirk_all(struct pci_dev *dev)
{
return __nv_msi_ht_cap_quirk(dev, 1);
}
static void nv_msi_ht_cap_quirk_leaf(struct pci_dev *dev)
{
return __nv_msi_ht_cap_quirk(dev, 0);
}
static void quirk_msi_intx_disable_bug(struct pci_dev *dev)
{
dev->dev_flags |= PCI_DEV_FLAGS_MSI_INTX_DISABLE_BUG;
}
static void quirk_msi_intx_disable_ati_bug(struct pci_dev *dev)
{
struct pci_dev *p;
p = pci_get_device(PCI_VENDOR_ID_ATI, PCI_DEVICE_ID_ATI_SBX00_SMBUS,
NULL);
if (!p)
return;
if ((p->revision < 0x3B) && (p->revision >= 0x30))
dev->dev_flags |= PCI_DEV_FLAGS_MSI_INTX_DISABLE_BUG;
pci_dev_put(p);
}
static void quirk_msi_intx_disable_qca_bug(struct pci_dev *dev)
{
if (dev->revision < 0x18) {
dev_info(&dev->dev, "set MSI_INTX_DISABLE_BUG flag\n");
dev->dev_flags |= PCI_DEV_FLAGS_MSI_INTX_DISABLE_BUG;
}
}
static void quirk_hotplug_bridge(struct pci_dev *dev)
{
dev->is_hotplug_bridge = 1;
}
static void ricoh_mmc_fixup_rl5c476(struct pci_dev *dev)
{
u8 write_enable;
u8 write_target;
u8 disable;
if (PCI_FUNC(dev->devfn))
return;
pci_read_config_byte(dev, 0xB7, &disable);
if (disable & 0x02)
return;
pci_read_config_byte(dev, 0x8E, &write_enable);
pci_write_config_byte(dev, 0x8E, 0xAA);
pci_read_config_byte(dev, 0x8D, &write_target);
pci_write_config_byte(dev, 0x8D, 0xB7);
pci_write_config_byte(dev, 0xB7, disable | 0x02);
pci_write_config_byte(dev, 0x8E, write_enable);
pci_write_config_byte(dev, 0x8D, write_target);
dev_notice(&dev->dev, "proprietary Ricoh MMC controller disabled (via cardbus function)\n");
dev_notice(&dev->dev, "MMC cards are now supported by standard SDHCI controller\n");
}
static void ricoh_mmc_fixup_r5c832(struct pci_dev *dev)
{
u8 write_enable;
u8 disable;
if (PCI_FUNC(dev->devfn))
return;
if (dev->device == PCI_DEVICE_ID_RICOH_R5CE822 ||
dev->device == PCI_DEVICE_ID_RICOH_R5CE823) {
pci_write_config_byte(dev, 0xf9, 0xfc);
pci_write_config_byte(dev, 0x150, 0x10);
pci_write_config_byte(dev, 0xf9, 0x00);
pci_write_config_byte(dev, 0xfc, 0x01);
pci_write_config_byte(dev, 0xe1, 0x32);
pci_write_config_byte(dev, 0xfc, 0x00);
dev_notice(&dev->dev, "MMC controller base frequency changed to 50Mhz.\n");
}
pci_read_config_byte(dev, 0xCB, &disable);
if (disable & 0x02)
return;
pci_read_config_byte(dev, 0xCA, &write_enable);
pci_write_config_byte(dev, 0xCA, 0x57);
pci_write_config_byte(dev, 0xCB, disable | 0x02);
pci_write_config_byte(dev, 0xCA, write_enable);
dev_notice(&dev->dev, "proprietary Ricoh MMC controller disabled (via firewire function)\n");
dev_notice(&dev->dev, "MMC cards are now supported by standard SDHCI controller\n");
}
static void vtd_mask_spec_errors(struct pci_dev *dev)
{
u32 word;
pci_read_config_dword(dev, VTUNCERRMSK_REG, &word);
pci_write_config_dword(dev, VTUNCERRMSK_REG, word | VTD_MSK_SPEC_ERRORS);
}
static void fixup_ti816x_class(struct pci_dev *dev)
{
dev_info(&dev->dev, "Setting PCI class for 816x PCIe device\n");
dev->class = PCI_CLASS_MULTIMEDIA_VIDEO;
}
static void fixup_mpss_256(struct pci_dev *dev)
{
dev->pcie_mpss = 1;
}
static void quirk_intel_mc_errata(struct pci_dev *dev)
{
int err;
u16 rcc;
if (pcie_bus_config == PCIE_BUS_TUNE_OFF)
return;
err = pci_read_config_word(dev, 0x48, &rcc);
if (err) {
dev_err(&dev->dev, "Error attempting to read the read "
"completion coalescing register.\n");
return;
}
if (!(rcc & (1 << 10)))
return;
rcc &= ~(1 << 10);
err = pci_write_config_word(dev, 0x48, rcc);
if (err) {
dev_err(&dev->dev, "Error attempting to write the read "
"completion coalescing register.\n");
return;
}
pr_info_once("Read completion coalescing disabled due to hardware "
"errata relating to 256B MPS.\n");
}
static void quirk_intel_ntb(struct pci_dev *dev)
{
int rc;
u8 val;
rc = pci_read_config_byte(dev, 0x00D0, &val);
if (rc)
return;
dev->resource[2].end = dev->resource[2].start + ((u64) 1 << val) - 1;
rc = pci_read_config_byte(dev, 0x00D1, &val);
if (rc)
return;
dev->resource[4].end = dev->resource[4].start + ((u64) 1 << val) - 1;
}
static ktime_t fixup_debug_start(struct pci_dev *dev,
void (*fn)(struct pci_dev *dev))
{
ktime_t calltime = ktime_set(0, 0);
dev_dbg(&dev->dev, "calling %pF\n", fn);
if (initcall_debug) {
pr_debug("calling %pF @ %i for %s\n",
fn, task_pid_nr(current), dev_name(&dev->dev));
calltime = ktime_get();
}
return calltime;
}
static void fixup_debug_report(struct pci_dev *dev, ktime_t calltime,
void (*fn)(struct pci_dev *dev))
{
ktime_t delta, rettime;
unsigned long long duration;
if (initcall_debug) {
rettime = ktime_get();
delta = ktime_sub(rettime, calltime);
duration = (unsigned long long) ktime_to_ns(delta) >> 10;
pr_debug("pci fixup %pF returned after %lld usecs for %s\n",
fn, duration, dev_name(&dev->dev));
}
}
static void disable_igfx_irq(struct pci_dev *dev)
{
void __iomem *regs = pci_iomap(dev, 0, 0);
if (regs == NULL) {
dev_warn(&dev->dev, "igfx quirk: Can't iomap PCI device\n");
return;
}
if (readl(regs + I915_DEIER_REG) != 0) {
dev_warn(&dev->dev, "BIOS left Intel GPU interrupts enabled; "
"disabling\n");
writel(0, regs + I915_DEIER_REG);
}
pci_iounmap(dev, regs);
}
static void quirk_broken_intx_masking(struct pci_dev *dev)
{
dev->broken_intx_masking = 1;
}
static void pci_do_fixups(struct pci_dev *dev, struct pci_fixup *f,
struct pci_fixup *end)
{
ktime_t calltime;
for (; f < end; f++)
if ((f->class == (u32) (dev->class >> f->class_shift) ||
f->class == (u32) PCI_ANY_ID) &&
(f->vendor == dev->vendor ||
f->vendor == (u16) PCI_ANY_ID) &&
(f->device == dev->device ||
f->device == (u16) PCI_ANY_ID)) {
calltime = fixup_debug_start(dev, f->hook);
f->hook(dev);
fixup_debug_report(dev, calltime, f->hook);
}
}
void pci_fixup_device(enum pci_fixup_pass pass, struct pci_dev *dev)
{
struct pci_fixup *start, *end;
switch(pass) {
case pci_fixup_early:
start = __start_pci_fixups_early;
end = __end_pci_fixups_early;
break;
case pci_fixup_header:
start = __start_pci_fixups_header;
end = __end_pci_fixups_header;
break;
case pci_fixup_final:
if (!pci_apply_fixup_final_quirks)
return;
start = __start_pci_fixups_final;
end = __end_pci_fixups_final;
break;
case pci_fixup_enable:
start = __start_pci_fixups_enable;
end = __end_pci_fixups_enable;
break;
case pci_fixup_resume:
start = __start_pci_fixups_resume;
end = __end_pci_fixups_resume;
break;
case pci_fixup_resume_early:
start = __start_pci_fixups_resume_early;
end = __end_pci_fixups_resume_early;
break;
case pci_fixup_suspend:
start = __start_pci_fixups_suspend;
end = __end_pci_fixups_suspend;
break;
default:
return;
}
pci_do_fixups(dev, start, end);
}
static int __init pci_apply_final_quirks(void)
{
struct pci_dev *dev = NULL;
u8 cls = 0;
u8 tmp;
if (pci_cache_line_size)
printk(KERN_DEBUG "PCI: CLS %u bytes\n",
pci_cache_line_size << 2);
pci_apply_fixup_final_quirks = true;
for_each_pci_dev(dev) {
pci_fixup_device(pci_fixup_final, dev);
if (!pci_cache_line_size) {
pci_read_config_byte(dev, PCI_CACHE_LINE_SIZE, &tmp);
if (!cls)
cls = tmp;
if (!tmp || cls == tmp)
continue;
printk(KERN_DEBUG "PCI: CLS mismatch (%u != %u), "
"using %u bytes\n", cls << 2, tmp << 2,
pci_dfl_cache_line_size << 2);
pci_cache_line_size = pci_dfl_cache_line_size;
}
}
if (!pci_cache_line_size) {
printk(KERN_DEBUG "PCI: CLS %u bytes, default %u\n",
cls << 2, pci_dfl_cache_line_size << 2);
pci_cache_line_size = cls ? cls : pci_dfl_cache_line_size;
}
return 0;
}
static int reset_intel_generic_dev(struct pci_dev *dev, int probe)
{
int pos;
if (dev->class == PCI_CLASS_SERIAL_USB) {
pos = pci_find_capability(dev, PCI_CAP_ID_VNDR);
if (!pos)
return -ENOTTY;
if (probe)
return 0;
pci_write_config_byte(dev, pos + 0x4, 1);
msleep(100);
return 0;
} else {
return -ENOTTY;
}
}
static int reset_intel_82599_sfp_virtfn(struct pci_dev *dev, int probe)
{
if (probe)
return 0;
if (!pci_wait_for_pending_transaction(dev))
dev_err(&dev->dev, "transaction is not cleared; proceeding with reset anyway\n");
pcie_capability_set_word(dev, PCI_EXP_DEVCTL, PCI_EXP_DEVCTL_BCR_FLR);
msleep(100);
return 0;
}
static int reset_ivb_igd(struct pci_dev *dev, int probe)
{
void __iomem *mmio_base;
unsigned long timeout;
u32 val;
if (probe)
return 0;
mmio_base = pci_iomap(dev, 0, 0);
if (!mmio_base)
return -ENOMEM;
iowrite32(0x00000002, mmio_base + MSG_CTL);
iowrite32(0x00000005, mmio_base + SOUTH_CHICKEN2);
val = ioread32(mmio_base + PCH_PP_CONTROL) & 0xfffffffe;
iowrite32(val, mmio_base + PCH_PP_CONTROL);
timeout = jiffies + msecs_to_jiffies(IGD_OPERATION_TIMEOUT);
do {
val = ioread32(mmio_base + PCH_PP_STATUS);
if ((val & 0xb0000000) == 0)
goto reset_complete;
msleep(10);
} while (time_before(jiffies, timeout));
dev_warn(&dev->dev, "timeout during reset\n");
reset_complete:
iowrite32(0x00000002, mmio_base + NSDE_PWR_STATE);
pci_iounmap(dev, mmio_base);
return 0;
}
static int reset_chelsio_generic_dev(struct pci_dev *dev, int probe)
{
u16 old_command;
u16 msix_flags;
if ((dev->device & 0xf000) != 0x4000)
return -ENOTTY;
if (probe)
return 0;
pci_read_config_word(dev, PCI_COMMAND, &old_command);
pci_write_config_word(dev, PCI_COMMAND,
old_command | PCI_COMMAND_MASTER);
pci_save_state(dev);
pci_read_config_word(dev, dev->msix_cap+PCI_MSIX_FLAGS, &msix_flags);
if ((msix_flags & PCI_MSIX_FLAGS_ENABLE) == 0)
pci_write_config_word(dev, dev->msix_cap+PCI_MSIX_FLAGS,
msix_flags |
PCI_MSIX_FLAGS_ENABLE |
PCI_MSIX_FLAGS_MASKALL);
if (!pci_wait_for_pending_transaction(dev))
dev_err(&dev->dev, "transaction is not cleared; proceeding with reset anyway\n");
pcie_capability_set_word(dev, PCI_EXP_DEVCTL, PCI_EXP_DEVCTL_BCR_FLR);
msleep(100);
pci_restore_state(dev);
pci_write_config_word(dev, PCI_COMMAND, old_command);
return 0;
}
int pci_dev_specific_reset(struct pci_dev *dev, int probe)
{
const struct pci_dev_reset_methods *i;
for (i = pci_dev_reset_methods; i->reset; i++) {
if ((i->vendor == dev->vendor ||
i->vendor == (u16)PCI_ANY_ID) &&
(i->device == dev->device ||
i->device == (u16)PCI_ANY_ID))
return i->reset(dev, probe);
}
return -ENOTTY;
}
static struct pci_dev *pci_func_0_dma_source(struct pci_dev *dev)
{
if (!PCI_FUNC(dev->devfn))
return pci_dev_get(dev);
return pci_get_slot(dev->bus, PCI_DEVFN(PCI_SLOT(dev->devfn), 0));
}
struct pci_dev *pci_get_dma_source(struct pci_dev *dev)
{
const struct pci_dev_dma_source *i;
for (i = pci_dev_dma_source; i->dma_source; i++) {
if ((i->vendor == dev->vendor ||
i->vendor == (u16)PCI_ANY_ID) &&
(i->device == dev->device ||
i->device == (u16)PCI_ANY_ID))
return i->dma_source(dev);
}
return pci_dev_get(dev);
}
static int pci_quirk_amd_sb_acs(struct pci_dev *dev, u16 acs_flags)
{
#ifdef CONFIG_ACPI
struct acpi_table_header *header = NULL;
acpi_status status;
if (!dev->multifunction || !pci_is_root_bus(dev->bus))
return -ENODEV;
status = acpi_get_table("IVRS", 0, &header);
if (ACPI_FAILURE(status))
return -ENODEV;
acs_flags &= (PCI_ACS_RR | PCI_ACS_CR | PCI_ACS_EC | PCI_ACS_DT);
return acs_flags & ~(PCI_ACS_RR | PCI_ACS_CR) ? 0 : 1;
#else
return -ENODEV;
#endif
}
int pci_dev_specific_acs_enabled(struct pci_dev *dev, u16 acs_flags)
{
const struct pci_dev_acs_enabled *i;
int ret;
for (i = pci_dev_acs_enabled; i->acs_enabled; i++) {
if ((i->vendor == dev->vendor ||
i->vendor == (u16)PCI_ANY_ID) &&
(i->device == dev->device ||
i->device == (u16)PCI_ANY_ID)) {
ret = i->acs_enabled(dev, acs_flags);
if (ret >= 0)
return ret;
}
}
return -ENOTTY;
}
