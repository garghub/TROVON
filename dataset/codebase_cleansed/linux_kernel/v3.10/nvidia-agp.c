static int nvidia_fetch_size(void)
{
int i;
u8 size_value;
struct aper_size_info_8 *values;
pci_read_config_byte(agp_bridge->dev, NVIDIA_0_APSIZE, &size_value);
size_value &= 0x0f;
values = A_SIZE_8(agp_bridge->driver->aperture_sizes);
for (i = 0; i < agp_bridge->driver->num_aperture_sizes; i++) {
if (size_value == values[i].size_value) {
agp_bridge->previous_size =
agp_bridge->current_size = (void *) (values + i);
agp_bridge->aperture_size_idx = i;
return values[i].size;
}
}
return 0;
}
static int nvidia_init_iorr(u32 base, u32 size)
{
u32 base_hi, base_lo;
u32 mask_hi, mask_lo;
u32 sys_hi, sys_lo;
u32 iorr_addr, free_iorr_addr;
free_iorr_addr = AMD_K7_NUM_IORR;
for (iorr_addr = 0; iorr_addr < AMD_K7_NUM_IORR; iorr_addr++) {
rdmsr(IORR_BASE0 + 2 * iorr_addr, base_lo, base_hi);
rdmsr(IORR_MASK0 + 2 * iorr_addr, mask_lo, mask_hi);
if ((base_lo & 0xfffff000) == (base & 0xfffff000))
break;
if ((mask_lo & 0x00000800) == 0)
free_iorr_addr = iorr_addr;
}
if (iorr_addr >= AMD_K7_NUM_IORR) {
iorr_addr = free_iorr_addr;
if (iorr_addr >= AMD_K7_NUM_IORR)
return -EINVAL;
}
base_hi = 0x0;
base_lo = (base & ~0xfff) | 0x18;
mask_hi = 0xf;
mask_lo = ((~(size - 1)) & 0xfffff000) | 0x800;
wrmsr(IORR_BASE0 + 2 * iorr_addr, base_lo, base_hi);
wrmsr(IORR_MASK0 + 2 * iorr_addr, mask_lo, mask_hi);
rdmsr(SYSCFG, sys_lo, sys_hi);
sys_lo |= 0x00100000;
wrmsr(SYSCFG, sys_lo, sys_hi);
return 0;
}
static int nvidia_configure(void)
{
int i, rc, num_dirs;
u32 apbase, aplimit;
struct aper_size_info_8 *current_size;
u32 temp;
current_size = A_SIZE_8(agp_bridge->current_size);
pci_write_config_byte(agp_bridge->dev, NVIDIA_0_APSIZE,
current_size->size_value);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &apbase);
apbase &= PCI_BASE_ADDRESS_MEM_MASK;
agp_bridge->gart_bus_addr = apbase;
aplimit = apbase + (current_size->size * 1024 * 1024) - 1;
pci_write_config_dword(nvidia_private.dev_2, NVIDIA_2_APBASE, apbase);
pci_write_config_dword(nvidia_private.dev_2, NVIDIA_2_APLIMIT, aplimit);
pci_write_config_dword(nvidia_private.dev_3, NVIDIA_3_APBASE, apbase);
pci_write_config_dword(nvidia_private.dev_3, NVIDIA_3_APLIMIT, aplimit);
if (0 != (rc = nvidia_init_iorr(apbase, current_size->size * 1024 * 1024)))
return rc;
num_dirs = current_size->size / 64;
nvidia_private.num_active_entries = current_size->num_entries;
nvidia_private.pg_offset = 0;
if (num_dirs == 0) {
num_dirs = 1;
nvidia_private.num_active_entries /= (64 / current_size->size);
nvidia_private.pg_offset = (apbase & (64 * 1024 * 1024 - 1) &
~(current_size->size * 1024 * 1024 - 1)) / PAGE_SIZE;
}
for (i = 0; i < 8; i++) {
pci_write_config_dword(nvidia_private.dev_2, NVIDIA_2_ATTBASE(i),
(agp_bridge->gatt_bus_addr + (i % num_dirs) * 64 * 1024) | 1);
}
pci_read_config_dword(nvidia_private.dev_2, NVIDIA_2_GARTCTRL, &temp);
pci_write_config_dword(nvidia_private.dev_2, NVIDIA_2_GARTCTRL, temp | 0x11);
pci_read_config_dword(agp_bridge->dev, NVIDIA_0_APSIZE, &temp);
pci_write_config_dword(agp_bridge->dev, NVIDIA_0_APSIZE, temp | 0x100);
nvidia_private.aperture =
(volatile u32 __iomem *) ioremap(apbase, 33 * PAGE_SIZE);
if (!nvidia_private.aperture)
return -ENOMEM;
return 0;
}
static void nvidia_cleanup(void)
{
struct aper_size_info_8 *previous_size;
u32 temp;
pci_read_config_dword(agp_bridge->dev, NVIDIA_0_APSIZE, &temp);
pci_write_config_dword(agp_bridge->dev, NVIDIA_0_APSIZE, temp & ~(0x100));
pci_read_config_dword(nvidia_private.dev_2, NVIDIA_2_GARTCTRL, &temp);
pci_write_config_dword(nvidia_private.dev_2, NVIDIA_2_GARTCTRL, temp & ~(0x11));
iounmap((void __iomem *) nvidia_private.aperture);
previous_size = A_SIZE_8(agp_bridge->previous_size);
pci_write_config_byte(agp_bridge->dev, NVIDIA_0_APSIZE,
previous_size->size_value);
nvidia_init_iorr(agp_bridge->gart_bus_addr,
previous_size->size * 1024 * 1024);
}
static int nvidia_insert_memory(struct agp_memory *mem, off_t pg_start, int type)
{
int i, j;
int mask_type;
mask_type = agp_generic_type_to_mask_type(mem->bridge, type);
if (mask_type != 0 || type != mem->type)
return -EINVAL;
if (mem->page_count == 0)
return 0;
if ((pg_start + mem->page_count) >
(nvidia_private.num_active_entries - agp_memory_reserved/PAGE_SIZE))
return -EINVAL;
for (j = pg_start; j < (pg_start + mem->page_count); j++) {
if (!PGE_EMPTY(agp_bridge, readl(agp_bridge->gatt_table+nvidia_private.pg_offset+j)))
return -EBUSY;
}
if (!mem->is_flushed) {
global_cache_flush();
mem->is_flushed = true;
}
for (i = 0, j = pg_start; i < mem->page_count; i++, j++) {
writel(agp_bridge->driver->mask_memory(agp_bridge,
page_to_phys(mem->pages[i]), mask_type),
agp_bridge->gatt_table+nvidia_private.pg_offset+j);
}
readl(agp_bridge->gatt_table+nvidia_private.pg_offset+j - 1);
agp_bridge->driver->tlb_flush(mem);
return 0;
}
static int nvidia_remove_memory(struct agp_memory *mem, off_t pg_start, int type)
{
int i;
int mask_type;
mask_type = agp_generic_type_to_mask_type(mem->bridge, type);
if (mask_type != 0 || type != mem->type)
return -EINVAL;
if (mem->page_count == 0)
return 0;
for (i = pg_start; i < (mem->page_count + pg_start); i++)
writel(agp_bridge->scratch_page, agp_bridge->gatt_table+nvidia_private.pg_offset+i);
agp_bridge->driver->tlb_flush(mem);
return 0;
}
static void nvidia_tlbflush(struct agp_memory *mem)
{
unsigned long end;
u32 wbc_reg, temp;
int i;
if (nvidia_private.wbc_mask) {
pci_read_config_dword(nvidia_private.dev_1, NVIDIA_1_WBC, &wbc_reg);
wbc_reg |= nvidia_private.wbc_mask;
pci_write_config_dword(nvidia_private.dev_1, NVIDIA_1_WBC, wbc_reg);
end = jiffies + 3*HZ;
do {
pci_read_config_dword(nvidia_private.dev_1,
NVIDIA_1_WBC, &wbc_reg);
if (time_before_eq(end, jiffies)) {
printk(KERN_ERR PFX
"TLB flush took more than 3 seconds.\n");
}
} while (wbc_reg & nvidia_private.wbc_mask);
}
for (i = 0; i < 32 + 1; i++)
temp = readl(nvidia_private.aperture+(i * PAGE_SIZE / sizeof(u32)));
for (i = 0; i < 32 + 1; i++)
temp = readl(nvidia_private.aperture+(i * PAGE_SIZE / sizeof(u32)));
}
static int agp_nvidia_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct agp_bridge_data *bridge;
u8 cap_ptr;
nvidia_private.dev_1 =
pci_get_bus_and_slot((unsigned int)pdev->bus->number, PCI_DEVFN(0, 1));
nvidia_private.dev_2 =
pci_get_bus_and_slot((unsigned int)pdev->bus->number, PCI_DEVFN(0, 2));
nvidia_private.dev_3 =
pci_get_bus_and_slot((unsigned int)pdev->bus->number, PCI_DEVFN(30, 0));
if (!nvidia_private.dev_1 || !nvidia_private.dev_2 || !nvidia_private.dev_3) {
printk(KERN_INFO PFX "Detected an NVIDIA nForce/nForce2 "
"chipset, but could not find the secondary devices.\n");
return -ENODEV;
}
cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
if (!cap_ptr)
return -ENODEV;
switch (pdev->device) {
case PCI_DEVICE_ID_NVIDIA_NFORCE:
printk(KERN_INFO PFX "Detected NVIDIA nForce chipset\n");
nvidia_private.wbc_mask = 0x00010000;
break;
case PCI_DEVICE_ID_NVIDIA_NFORCE2:
printk(KERN_INFO PFX "Detected NVIDIA nForce2 chipset\n");
nvidia_private.wbc_mask = 0x80000000;
break;
default:
printk(KERN_ERR PFX "Unsupported NVIDIA chipset (device id: %04x)\n",
pdev->device);
return -ENODEV;
}
bridge = agp_alloc_bridge();
if (!bridge)
return -ENOMEM;
bridge->driver = &nvidia_driver;
bridge->dev_private_data = &nvidia_private,
bridge->dev = pdev;
bridge->capndx = cap_ptr;
pci_read_config_dword(pdev,
bridge->capndx+PCI_AGP_STATUS,
&bridge->mode);
pci_set_drvdata(pdev, bridge);
return agp_add_bridge(bridge);
}
static void agp_nvidia_remove(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge = pci_get_drvdata(pdev);
agp_remove_bridge(bridge);
agp_put_bridge(bridge);
}
static int agp_nvidia_suspend(struct pci_dev *pdev, pm_message_t state)
{
pci_save_state (pdev);
pci_set_power_state (pdev, 3);
return 0;
}
static int agp_nvidia_resume(struct pci_dev *pdev)
{
pci_set_power_state (pdev, 0);
pci_restore_state(pdev);
nvidia_configure();
return 0;
}
static int __init agp_nvidia_init(void)
{
if (agp_off)
return -EINVAL;
return pci_register_driver(&agp_nvidia_pci_driver);
}
static void __exit agp_nvidia_cleanup(void)
{
pci_unregister_driver(&agp_nvidia_pci_driver);
pci_dev_put(nvidia_private.dev_1);
pci_dev_put(nvidia_private.dev_2);
pci_dev_put(nvidia_private.dev_3);
}
