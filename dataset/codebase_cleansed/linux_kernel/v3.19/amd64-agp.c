static void amd64_tlbflush(struct agp_memory *temp)
{
amd_flush_garts();
}
static int amd64_insert_memory(struct agp_memory *mem, off_t pg_start, int type)
{
int i, j, num_entries;
long long tmp;
int mask_type;
struct agp_bridge_data *bridge = mem->bridge;
u32 pte;
num_entries = agp_num_entries();
if (type != mem->type)
return -EINVAL;
mask_type = bridge->driver->agp_type_to_mask_type(bridge, type);
if (mask_type != 0)
return -EINVAL;
if (((unsigned long)pg_start + mem->page_count) > num_entries)
return -EINVAL;
j = pg_start;
while (j < (pg_start + mem->page_count)) {
if (!PGE_EMPTY(agp_bridge, readl(agp_bridge->gatt_table+j)))
return -EBUSY;
j++;
}
if (!mem->is_flushed) {
global_cache_flush();
mem->is_flushed = true;
}
for (i = 0, j = pg_start; i < mem->page_count; i++, j++) {
tmp = agp_bridge->driver->mask_memory(agp_bridge,
page_to_phys(mem->pages[i]),
mask_type);
BUG_ON(tmp & 0xffffff0000000ffcULL);
pte = (tmp & 0x000000ff00000000ULL) >> 28;
pte |=(tmp & 0x00000000fffff000ULL);
pte |= GPTE_VALID | GPTE_COHERENT;
writel(pte, agp_bridge->gatt_table+j);
readl(agp_bridge->gatt_table+j);
}
amd64_tlbflush(mem);
return 0;
}
static int amd64_fetch_size(void)
{
struct pci_dev *dev;
int i;
u32 temp;
struct aper_size_info_32 *values;
dev = node_to_amd_nb(0)->misc;
if (dev==NULL)
return 0;
pci_read_config_dword(dev, AMD64_GARTAPERTURECTL, &temp);
temp = (temp & 0xe);
values = A_SIZE_32(amd64_aperture_sizes);
for (i = 0; i < agp_bridge->driver->num_aperture_sizes; i++) {
if (temp == values[i].size_value) {
agp_bridge->previous_size =
agp_bridge->current_size = (void *) (values + i);
agp_bridge->aperture_size_idx = i;
return values[i].size;
}
}
return 0;
}
static u64 amd64_configure(struct pci_dev *hammer, u64 gatt_table)
{
u64 aperturebase;
u32 tmp;
u64 aper_base;
pci_read_config_dword(hammer, AMD64_GARTAPERTUREBASE, &tmp);
aperturebase = tmp << 25;
aper_base = (aperturebase & PCI_BASE_ADDRESS_MEM_MASK);
enable_gart_translation(hammer, gatt_table);
return aper_base;
}
static int amd_8151_configure(void)
{
unsigned long gatt_bus = virt_to_phys(agp_bridge->gatt_table_real);
int i;
if (!amd_nb_has_feature(AMD_NB_GART))
return 0;
for (i = 0; i < amd_nb_num(); i++) {
agp_bridge->gart_bus_addr =
amd64_configure(node_to_amd_nb(i)->misc, gatt_bus);
}
amd_flush_garts();
return 0;
}
static void amd64_cleanup(void)
{
u32 tmp;
int i;
if (!amd_nb_has_feature(AMD_NB_GART))
return;
for (i = 0; i < amd_nb_num(); i++) {
struct pci_dev *dev = node_to_amd_nb(i)->misc;
pci_read_config_dword(dev, AMD64_GARTAPERTURECTL, &tmp);
tmp &= ~GARTEN;
pci_write_config_dword(dev, AMD64_GARTAPERTURECTL, tmp);
}
}
static int agp_aperture_valid(u64 aper, u32 size)
{
if (!aperture_valid(aper, size, 32*1024*1024))
return 0;
if (!aperture_resource &&
!(aperture_resource = request_mem_region(aper, size, "aperture"))) {
printk(KERN_ERR PFX "Aperture conflicts with PCI mapping.\n");
return 0;
}
return 1;
}
static int fix_northbridge(struct pci_dev *nb, struct pci_dev *agp, u16 cap)
{
u64 aper, nb_aper;
int order = 0;
u32 nb_order, nb_base;
u16 apsize;
pci_read_config_dword(nb, AMD64_GARTAPERTURECTL, &nb_order);
nb_order = (nb_order >> 1) & 7;
pci_read_config_dword(nb, AMD64_GARTAPERTUREBASE, &nb_base);
nb_aper = nb_base << 25;
pci_read_config_word(agp, cap+0x14, &apsize);
if (apsize == 0xffff) {
if (agp_aperture_valid(nb_aper, (32*1024*1024)<<nb_order))
return 0;
return -1;
}
apsize &= 0xfff;
if (apsize & 0xff)
apsize |= 0xf00;
order = 7 - hweight16(apsize);
aper = pci_bus_address(agp, AGP_APERTURE_BAR);
if (order >=0 && aper + (32ULL<<(20 + order)) > 0x100000000ULL) {
dev_info(&agp->dev, "aperture size %u MB is not right, using settings from NB\n",
32 << order);
order = nb_order;
}
if (nb_order >= order) {
if (agp_aperture_valid(nb_aper, (32*1024*1024)<<nb_order))
return 0;
}
dev_info(&agp->dev, "aperture from AGP @ %Lx size %u MB\n",
aper, 32 << order);
if (order < 0 || !agp_aperture_valid(aper, (32*1024*1024)<<order))
return -1;
gart_set_size_and_enable(nb, order);
pci_write_config_dword(nb, AMD64_GARTAPERTUREBASE, aper >> 25);
return 0;
}
static int cache_nbs(struct pci_dev *pdev, u32 cap_ptr)
{
int i;
if (amd_cache_northbridges() < 0)
return -ENODEV;
if (!amd_nb_has_feature(AMD_NB_GART))
return -ENODEV;
i = 0;
for (i = 0; i < amd_nb_num(); i++) {
struct pci_dev *dev = node_to_amd_nb(i)->misc;
if (fix_northbridge(dev, pdev, cap_ptr) < 0) {
dev_err(&dev->dev, "no usable aperture found\n");
#ifdef __x86_64__
dev_err(&dev->dev, "consider rebooting with iommu=memaper=2 to get a good aperture\n");
#endif
return -1;
}
}
return 0;
}
static void amd8151_init(struct pci_dev *pdev, struct agp_bridge_data *bridge)
{
char *revstring;
switch (pdev->revision) {
case 0x01: revstring="A0"; break;
case 0x02: revstring="A1"; break;
case 0x11: revstring="B0"; break;
case 0x12: revstring="B1"; break;
case 0x13: revstring="B2"; break;
case 0x14: revstring="B3"; break;
default: revstring="??"; break;
}
dev_info(&pdev->dev, "AMD 8151 AGP Bridge rev %s\n", revstring);
if (pdev->revision < 0x13) {
dev_info(&pdev->dev, "correcting AGP revision (reports 3.5, is really 3.0)\n");
bridge->major_version = 3;
bridge->minor_version = 0;
}
}
static int uli_agp_init(struct pci_dev *pdev)
{
u32 httfea,baseaddr,enuscr;
struct pci_dev *dev1;
int i, ret;
unsigned size = amd64_fetch_size();
dev_info(&pdev->dev, "setting up ULi AGP\n");
dev1 = pci_get_slot (pdev->bus,PCI_DEVFN(0,0));
if (dev1 == NULL) {
dev_info(&pdev->dev, "can't find ULi secondary device\n");
return -ENODEV;
}
for (i = 0; i < ARRAY_SIZE(uli_sizes); i++)
if (uli_sizes[i].size == size)
break;
if (i == ARRAY_SIZE(uli_sizes)) {
dev_info(&pdev->dev, "no ULi size found for %d\n", size);
ret = -ENODEV;
goto put;
}
pci_read_config_dword (node_to_amd_nb(0)->misc, AMD64_GARTAPERTUREBASE,
&httfea);
if ((httfea & 0x7fff) >> (32 - 25)) {
ret = -ENODEV;
goto put;
}
httfea = (httfea& 0x7fff) << 25;
pci_read_config_dword(pdev, ULI_X86_64_BASE_ADDR, &baseaddr);
baseaddr&= ~PCI_BASE_ADDRESS_MEM_MASK;
baseaddr|= httfea;
pci_write_config_dword(pdev, ULI_X86_64_BASE_ADDR, baseaddr);
enuscr= httfea+ (size * 1024 * 1024) - 1;
pci_write_config_dword(dev1, ULI_X86_64_HTT_FEA_REG, httfea);
pci_write_config_dword(dev1, ULI_X86_64_ENU_SCR_REG, enuscr);
ret = 0;
put:
pci_dev_put(dev1);
return ret;
}
static int nforce3_agp_init(struct pci_dev *pdev)
{
u32 tmp, apbase, apbar, aplimit;
struct pci_dev *dev1;
int i, ret;
unsigned size = amd64_fetch_size();
dev_info(&pdev->dev, "setting up Nforce3 AGP\n");
dev1 = pci_get_slot(pdev->bus, PCI_DEVFN(11, 0));
if (dev1 == NULL) {
dev_info(&pdev->dev, "can't find Nforce3 secondary device\n");
return -ENODEV;
}
for (i = 0; i < ARRAY_SIZE(nforce3_sizes); i++)
if (nforce3_sizes[i].size == size)
break;
if (i == ARRAY_SIZE(nforce3_sizes)) {
dev_info(&pdev->dev, "no NForce3 size found for %d\n", size);
ret = -ENODEV;
goto put;
}
pci_read_config_dword(dev1, NVIDIA_X86_64_1_APSIZE, &tmp);
tmp &= ~(0xf);
tmp |= nforce3_sizes[i].size_value;
pci_write_config_dword(dev1, NVIDIA_X86_64_1_APSIZE, tmp);
pci_read_config_dword (node_to_amd_nb(0)->misc, AMD64_GARTAPERTUREBASE,
&apbase);
if ( (apbase & 0x7fff) >> (32 - 25) ) {
dev_info(&pdev->dev, "aperture base > 4G\n");
ret = -ENODEV;
goto put;
}
apbase = (apbase & 0x7fff) << 25;
pci_read_config_dword(pdev, NVIDIA_X86_64_0_APBASE, &apbar);
apbar &= ~PCI_BASE_ADDRESS_MEM_MASK;
apbar |= apbase;
pci_write_config_dword(pdev, NVIDIA_X86_64_0_APBASE, apbar);
aplimit = apbase + (size * 1024 * 1024) - 1;
pci_write_config_dword(dev1, NVIDIA_X86_64_1_APBASE1, apbase);
pci_write_config_dword(dev1, NVIDIA_X86_64_1_APLIMIT1, aplimit);
pci_write_config_dword(dev1, NVIDIA_X86_64_1_APBASE2, apbase);
pci_write_config_dword(dev1, NVIDIA_X86_64_1_APLIMIT2, aplimit);
ret = 0;
put:
pci_dev_put(dev1);
return ret;
}
static int agp_amd64_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct agp_bridge_data *bridge;
u8 cap_ptr;
int err;
if (agp_bridges_found)
return -ENODEV;
cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
if (!cap_ptr)
return -ENODEV;
bridge = agp_alloc_bridge();
if (!bridge)
return -ENOMEM;
if (pdev->vendor == PCI_VENDOR_ID_AMD &&
pdev->device == PCI_DEVICE_ID_AMD_8151_0) {
amd8151_init(pdev, bridge);
} else {
dev_info(&pdev->dev, "AGP bridge [%04x/%04x]\n",
pdev->vendor, pdev->device);
}
bridge->driver = &amd_8151_driver;
bridge->dev = pdev;
bridge->capndx = cap_ptr;
pci_read_config_dword(pdev, bridge->capndx+PCI_AGP_STATUS, &bridge->mode);
if (cache_nbs(pdev, cap_ptr) == -1) {
agp_put_bridge(bridge);
return -ENODEV;
}
if (pdev->vendor == PCI_VENDOR_ID_NVIDIA) {
int ret = nforce3_agp_init(pdev);
if (ret) {
agp_put_bridge(bridge);
return ret;
}
}
if (pdev->vendor == PCI_VENDOR_ID_AL) {
int ret = uli_agp_init(pdev);
if (ret) {
agp_put_bridge(bridge);
return ret;
}
}
pci_set_drvdata(pdev, bridge);
err = agp_add_bridge(bridge);
if (err < 0)
return err;
agp_bridges_found++;
return 0;
}
static void agp_amd64_remove(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge = pci_get_drvdata(pdev);
release_mem_region(virt_to_phys(bridge->gatt_table_real),
amd64_aperture_sizes[bridge->aperture_size_idx].size);
agp_remove_bridge(bridge);
agp_put_bridge(bridge);
agp_bridges_found--;
}
static int agp_amd64_suspend(struct pci_dev *pdev, pm_message_t state)
{
pci_save_state(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int agp_amd64_resume(struct pci_dev *pdev)
{
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
if (pdev->vendor == PCI_VENDOR_ID_NVIDIA)
nforce3_agp_init(pdev);
return amd_8151_configure();
}
int __init agp_amd64_init(void)
{
int err = 0;
if (agp_off)
return -EINVAL;
err = pci_register_driver(&agp_amd64_pci_driver);
if (err < 0)
return err;
if (agp_bridges_found == 0) {
if (!agp_try_unsupported && !agp_try_unsupported_boot) {
printk(KERN_INFO PFX "No supported AGP bridge found.\n");
#ifdef MODULE
printk(KERN_INFO PFX "You can try agp_try_unsupported=1\n");
#else
printk(KERN_INFO PFX "You can boot with agp=try_unsupported\n");
#endif
pci_unregister_driver(&agp_amd64_pci_driver);
return -ENODEV;
}
if (!pci_dev_present(amd_nb_misc_ids)) {
pci_unregister_driver(&agp_amd64_pci_driver);
return -ENODEV;
}
agp_amd64_pci_driver.id_table = agp_amd64_pci_promisc_table;
err = driver_attach(&agp_amd64_pci_driver.driver);
if (err == 0 && agp_bridges_found == 0) {
pci_unregister_driver(&agp_amd64_pci_driver);
err = -ENODEV;
}
}
return err;
}
static int __init agp_amd64_mod_init(void)
{
#ifndef MODULE
if (gart_iommu_aperture)
return agp_bridges_found ? 0 : -ENODEV;
#endif
return agp_amd64_init();
}
static void __exit agp_amd64_cleanup(void)
{
#ifndef MODULE
if (gart_iommu_aperture)
return;
#endif
if (aperture_resource)
release_resource(aperture_resource);
pci_unregister_driver(&agp_amd64_pci_driver);
}
