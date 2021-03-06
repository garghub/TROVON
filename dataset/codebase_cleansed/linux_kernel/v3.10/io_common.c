static dma_addr_t
sn_default_pci_map(struct pci_dev *pdev, unsigned long paddr, size_t size, int type)
{
return 0;
}
static void
sn_default_pci_unmap(struct pci_dev *pdev, dma_addr_t addr, int direction)
{
return;
}
static void *
sn_default_pci_bus_fixup(struct pcibus_bussoft *soft, struct pci_controller *controller)
{
return NULL;
}
static inline u64
sal_get_device_dmaflush_list(u64 nasid, u64 widget_num, u64 device_num,
u64 address)
{
struct ia64_sal_retval ret_stuff;
ret_stuff.status = 0;
ret_stuff.v0 = 0;
SAL_CALL_NOLOCK(ret_stuff,
(u64) SN_SAL_IOIF_GET_DEVICE_DMAFLUSH_LIST,
(u64) nasid, (u64) widget_num,
(u64) device_num, (u64) address, 0, 0, 0);
return ret_stuff.status;
}
inline struct pcidev_info *
sn_pcidev_info_get(struct pci_dev *dev)
{
struct pcidev_info *pcidev;
list_for_each_entry(pcidev,
&(SN_PLATFORM_DATA(dev)->pcidev_info), pdi_list) {
if (pcidev->pdi_linux_pcidev == dev)
return pcidev;
}
return NULL;
}
static s64 sn_device_fixup_war(u64 nasid, u64 widget, int device,
struct sn_flush_device_common *common)
{
struct sn_flush_device_war *war_list;
struct sn_flush_device_war *dev_entry;
struct ia64_sal_retval isrv = {0,0,0,0};
printk_once(KERN_WARNING
"PROM version < 4.50 -- implementing old PROM flush WAR\n");
war_list = kzalloc(DEV_PER_WIDGET * sizeof(*war_list), GFP_KERNEL);
BUG_ON(!war_list);
SAL_CALL_NOLOCK(isrv, SN_SAL_IOIF_GET_WIDGET_DMAFLUSH_LIST,
nasid, widget, __pa(war_list), 0, 0, 0 ,0);
if (isrv.status)
panic("sn_device_fixup_war failed: %s\n",
ia64_sal_strerror(isrv.status));
dev_entry = war_list + device;
memcpy(common,dev_entry, sizeof(*common));
kfree(war_list);
return isrv.status;
}
void __init
sn_common_hubdev_init(struct hubdev_info *hubdev)
{
struct sn_flush_device_kernel *sn_flush_device_kernel;
struct sn_flush_device_kernel *dev_entry;
s64 status;
int widget, device, size;
if (hubdev->hdi_nasid & 1)
ice_error_init(hubdev);
else
hub_error_init(hubdev);
for (widget = 0; widget <= HUB_WIDGET_ID_MAX; widget++)
hubdev->hdi_xwidget_info[widget].xwi_hubinfo = hubdev;
if (!hubdev->hdi_flush_nasid_list.widget_p)
return;
size = (HUB_WIDGET_ID_MAX + 1) *
sizeof(struct sn_flush_device_kernel *);
hubdev->hdi_flush_nasid_list.widget_p =
kzalloc(size, GFP_KERNEL);
BUG_ON(!hubdev->hdi_flush_nasid_list.widget_p);
for (widget = 0; widget <= HUB_WIDGET_ID_MAX; widget++) {
size = DEV_PER_WIDGET *
sizeof(struct sn_flush_device_kernel);
sn_flush_device_kernel = kzalloc(size, GFP_KERNEL);
BUG_ON(!sn_flush_device_kernel);
dev_entry = sn_flush_device_kernel;
for (device = 0; device < DEV_PER_WIDGET;
device++, dev_entry++) {
size = sizeof(struct sn_flush_device_common);
dev_entry->common = kzalloc(size, GFP_KERNEL);
BUG_ON(!dev_entry->common);
if (sn_prom_feature_available(PRF_DEVICE_FLUSH_LIST))
status = sal_get_device_dmaflush_list(
hubdev->hdi_nasid, widget, device,
(u64)(dev_entry->common));
else
status = sn_device_fixup_war(hubdev->hdi_nasid,
widget, device,
dev_entry->common);
if (status != SALRET_OK)
panic("SAL call failed: %s\n",
ia64_sal_strerror(status));
spin_lock_init(&dev_entry->sfdl_flush_lock);
}
if (sn_flush_device_kernel)
hubdev->hdi_flush_nasid_list.widget_p[widget] =
sn_flush_device_kernel;
}
}
void sn_pci_unfixup_slot(struct pci_dev *dev)
{
struct pci_dev *host_pci_dev = SN_PCIDEV_INFO(dev)->host_pci_dev;
sn_irq_unfixup(dev);
pci_dev_put(host_pci_dev);
pci_dev_put(dev);
}
void sn_pci_fixup_slot(struct pci_dev *dev, struct pcidev_info *pcidev_info,
struct sn_irq_info *sn_irq_info)
{
int segment = pci_domain_nr(dev->bus);
struct pcibus_bussoft *bs;
struct pci_dev *host_pci_dev;
unsigned int bus_no, devfn;
pci_dev_get(dev);
list_add_tail(&pcidev_info->pdi_list,
&(SN_PLATFORM_DATA(dev->bus)->pcidev_info));
bus_no = (pcidev_info->pdi_slot_host_handle >> 32) & 0xff;
devfn = pcidev_info->pdi_slot_host_handle & 0xffffffff;
host_pci_dev = pci_get_domain_bus_and_slot(segment, bus_no, devfn);
pcidev_info->host_pci_dev = host_pci_dev;
pcidev_info->pdi_linux_pcidev = dev;
pcidev_info->pdi_host_pcidev_info = SN_PCIDEV_INFO(host_pci_dev);
bs = SN_PCIBUS_BUSSOFT(dev->bus);
pcidev_info->pdi_pcibus_info = bs;
if (bs && bs->bs_asic_type < PCIIO_ASIC_MAX_TYPES) {
SN_PCIDEV_BUSPROVIDER(dev) = sn_pci_provider[bs->bs_asic_type];
} else {
SN_PCIDEV_BUSPROVIDER(dev) = &sn_pci_default_provider;
}
if (bs && sn_irq_info->irq_irq) {
pcidev_info->pdi_sn_irq_info = sn_irq_info;
dev->irq = pcidev_info->pdi_sn_irq_info->irq_irq;
sn_irq_fixup(dev, sn_irq_info);
} else {
pcidev_info->pdi_sn_irq_info = NULL;
kfree(sn_irq_info);
}
}
void
sn_common_bus_fixup(struct pci_bus *bus,
struct pcibus_bussoft *prom_bussoft_ptr)
{
int cnode;
struct pci_controller *controller;
struct hubdev_info *hubdev_info;
int nasid;
void *provider_soft;
struct sn_pcibus_provider *provider;
struct sn_platform_data *sn_platform_data;
controller = PCI_CONTROLLER(bus);
if (prom_bussoft_ptr->bs_asic_type >= PCIIO_ASIC_MAX_TYPES) {
printk(KERN_WARNING "sn_common_bus_fixup: Unsupported asic type, %d",
prom_bussoft_ptr->bs_asic_type);
return;
}
if (prom_bussoft_ptr->bs_asic_type == PCIIO_ASIC_TYPE_PPB)
return;
provider = sn_pci_provider[prom_bussoft_ptr->bs_asic_type];
if (provider == NULL)
panic("sn_common_bus_fixup: No provider registered for this asic type, %d",
prom_bussoft_ptr->bs_asic_type);
if (provider->bus_fixup)
provider_soft = (*provider->bus_fixup) (prom_bussoft_ptr,
controller);
else
provider_soft = NULL;
controller->platform_data = kzalloc(sizeof(struct sn_platform_data),
GFP_KERNEL);
BUG_ON(controller->platform_data == NULL);
sn_platform_data =
(struct sn_platform_data *) controller->platform_data;
sn_platform_data->provider_soft = provider_soft;
INIT_LIST_HEAD(&((struct sn_platform_data *)
controller->platform_data)->pcidev_info);
nasid = NASID_GET(SN_PCIBUS_BUSSOFT(bus)->bs_base);
cnode = nasid_to_cnodeid(nasid);
hubdev_info = (struct hubdev_info *)(NODEPDA(cnode)->pdinfo);
SN_PCIBUS_BUSSOFT(bus)->bs_xwidget_info =
&(hubdev_info->hdi_xwidget_info[SN_PCIBUS_BUSSOFT(bus)->bs_xid]);
if (controller->node >= num_online_nodes()) {
struct pcibus_bussoft *b = SN_PCIBUS_BUSSOFT(bus);
printk(KERN_WARNING "Device ASIC=%u XID=%u PBUSNUM=%u "
"L_IO=%llx L_MEM=%llx BASE=%llx\n",
b->bs_asic_type, b->bs_xid, b->bs_persist_busnum,
b->bs_legacy_io, b->bs_legacy_mem, b->bs_base);
printk(KERN_WARNING "on node %d but only %d nodes online."
"Association set to undetermined.\n",
controller->node, num_online_nodes());
controller->node = -1;
}
}
void sn_bus_store_sysdata(struct pci_dev *dev)
{
struct sysdata_el *element;
element = kzalloc(sizeof(struct sysdata_el), GFP_KERNEL);
if (!element) {
dev_dbg(&dev->dev, "%s: out of memory!\n", __func__);
return;
}
element->sysdata = SN_PCIDEV_INFO(dev);
list_add(&element->entry, &sn_sysdata_list);
}
void sn_bus_free_sysdata(void)
{
struct sysdata_el *element;
struct list_head *list, *safe;
list_for_each_safe(list, safe, &sn_sysdata_list) {
element = list_entry(list, struct sysdata_el, entry);
list_del(&element->entry);
list_del(&(((struct pcidev_info *)
(element->sysdata))->pdi_list));
kfree(element->sysdata);
kfree(element);
}
return;
}
void __init hubdev_init_node(nodepda_t * npda, cnodeid_t node)
{
struct hubdev_info *hubdev_info;
int size;
pg_data_t *pg;
size = sizeof(struct hubdev_info);
if (node >= num_online_nodes())
pg = NODE_DATA(0);
else
pg = NODE_DATA(node);
hubdev_info = (struct hubdev_info *)alloc_bootmem_node(pg, size);
npda->pdinfo = (void *)hubdev_info;
}
geoid_t
cnodeid_get_geoid(cnodeid_t cnode)
{
struct hubdev_info *hubdev;
hubdev = (struct hubdev_info *)(NODEPDA(cnode)->pdinfo);
return hubdev->hdi_geoid;
}
void sn_generate_path(struct pci_bus *pci_bus, char *address)
{
nasid_t nasid;
cnodeid_t cnode;
geoid_t geoid;
moduleid_t moduleid;
u16 bricktype;
nasid = NASID_GET(SN_PCIBUS_BUSSOFT(pci_bus)->bs_base);
cnode = nasid_to_cnodeid(nasid);
geoid = cnodeid_get_geoid(cnode);
moduleid = geo_module(geoid);
sprintf(address, "module_%c%c%c%c%.2d",
'0'+RACK_GET_CLASS(MODULE_GET_RACK(moduleid)),
'0'+RACK_GET_GROUP(MODULE_GET_RACK(moduleid)),
'0'+RACK_GET_NUM(MODULE_GET_RACK(moduleid)),
MODULE_GET_BTCHAR(moduleid), MODULE_GET_BPOS(moduleid));
bricktype = MODULE_GET_BTYPE(moduleid);
if ((bricktype == L1_BRICKTYPE_191010) ||
(bricktype == L1_BRICKTYPE_1932))
sprintf(address + strlen(address), "^%d",
geo_slot(geoid));
}
void sn_pci_fixup_bus(struct pci_bus *bus)
{
if (SN_ACPI_BASE_SUPPORT())
sn_acpi_bus_fixup(bus);
else
sn_bus_fixup(bus);
}
static int __init
sn_io_early_init(void)
{
int i;
if (!ia64_platform_is("sn2") || IS_RUNNING_ON_FAKE_PROM())
return 0;
{
struct acpi_table_header *header = NULL;
acpi_get_table(ACPI_SIG_DSDT, 1, &header);
BUG_ON(header == NULL);
sn_acpi_rev = header->oem_revision;
}
for (i = 0; i < PCIIO_ASIC_MAX_TYPES; i++)
sn_pci_provider[i] = &sn_pci_default_provider;
pcibr_init_provider();
tioca_init_provider();
tioce_init_provider();
ia64_max_iommu_merge_mask = ~PAGE_MASK;
sn_irq_lh_init();
INIT_LIST_HEAD(&sn_sysdata_list);
sn_init_cpei_timer();
#ifdef CONFIG_PROC_FS
register_sn_procfs();
#endif
{
struct acpi_table_header *header;
(void)acpi_get_table(ACPI_SIG_DSDT, 1, &header);
printk(KERN_INFO "ACPI DSDT OEM Rev 0x%x\n",
header->oem_revision);
}
if (SN_ACPI_BASE_SUPPORT())
sn_io_acpi_init();
else
sn_io_init();
return 0;
}
int __init
sn_io_late_init(void)
{
struct pci_bus *bus;
struct pcibus_bussoft *bussoft;
cnodeid_t cnode;
nasid_t nasid;
cnodeid_t near_cnode;
if (!ia64_platform_is("sn2") || IS_RUNNING_ON_FAKE_PROM())
return 0;
bus = NULL;
while ((bus = pci_find_next_bus(bus)) != NULL) {
bussoft = SN_PCIBUS_BUSSOFT(bus);
nasid = NASID_GET(bussoft->bs_base);
cnode = nasid_to_cnodeid(nasid);
if ((bussoft->bs_asic_type == PCIIO_ASIC_TYPE_TIOCP) ||
(bussoft->bs_asic_type == PCIIO_ASIC_TYPE_TIOCE) ||
(bussoft->bs_asic_type == PCIIO_ASIC_TYPE_PIC)) {
int e = sn_hwperf_get_nearest_node(cnode, NULL,
&near_cnode);
if (e < 0) {
near_cnode = (cnodeid_t)-1;
printk(KERN_WARNING "sn_io_late_init: failed "
"to find near node with CPUs for "
"node %d, err=%d\n", cnode, e);
}
PCI_CONTROLLER(bus)->node = near_cnode;
}
}
sn_ioif_inited = 1;
return 0;
}
