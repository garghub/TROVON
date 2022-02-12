static inline int dca2_tag_map_valid(u8 *tag_map)
{
return ((tag_map[0] == DCA2_TAG_MAP_BYTE0) &&
(tag_map[1] == DCA2_TAG_MAP_BYTE1) &&
(tag_map[2] == DCA2_TAG_MAP_BYTE2) &&
(tag_map[3] == DCA2_TAG_MAP_BYTE3) &&
(tag_map[4] == DCA2_TAG_MAP_BYTE4));
}
static inline u16 dcaid_from_pcidev(struct pci_dev *pci)
{
return (pci->bus->number << 8) | pci->devfn;
}
static int dca_enabled_in_bios(struct pci_dev *pdev)
{
unsigned long cpuid_level_9;
int res;
cpuid_level_9 = cpuid_eax(9);
res = test_bit(0, &cpuid_level_9);
if (!res)
dev_dbg(&pdev->dev, "DCA is disabled in BIOS\n");
return res;
}
int system_has_dca_enabled(struct pci_dev *pdev)
{
if (boot_cpu_has(X86_FEATURE_DCA))
return dca_enabled_in_bios(pdev);
dev_dbg(&pdev->dev, "boot cpu doesn't have X86_FEATURE_DCA\n");
return 0;
}
static int ioat_dca_dev_managed(struct dca_provider *dca,
struct device *dev)
{
struct ioat_dca_priv *ioatdca = dca_priv(dca);
struct pci_dev *pdev;
int i;
pdev = to_pci_dev(dev);
for (i = 0; i < ioatdca->max_requesters; i++) {
if (ioatdca->req_slots[i].pdev == pdev)
return 1;
}
return 0;
}
static int ioat_dca_add_requester(struct dca_provider *dca, struct device *dev)
{
struct ioat_dca_priv *ioatdca = dca_priv(dca);
struct pci_dev *pdev;
int i;
u16 id;
u16 global_req_table;
if (!dev_is_pci(dev))
return -ENODEV;
pdev = to_pci_dev(dev);
id = dcaid_from_pcidev(pdev);
if (ioatdca->requester_count == ioatdca->max_requesters)
return -ENODEV;
for (i = 0; i < ioatdca->max_requesters; i++) {
if (ioatdca->req_slots[i].pdev == NULL) {
ioatdca->requester_count++;
ioatdca->req_slots[i].pdev = pdev;
ioatdca->req_slots[i].rid = id;
global_req_table =
readw(ioatdca->dca_base + IOAT3_DCA_GREQID_OFFSET);
writel(id | IOAT_DCA_GREQID_VALID,
ioatdca->iobase + global_req_table + (i * 4));
return i;
}
}
return -EFAULT;
}
static int ioat_dca_remove_requester(struct dca_provider *dca,
struct device *dev)
{
struct ioat_dca_priv *ioatdca = dca_priv(dca);
struct pci_dev *pdev;
int i;
u16 global_req_table;
if (!dev_is_pci(dev))
return -ENODEV;
pdev = to_pci_dev(dev);
for (i = 0; i < ioatdca->max_requesters; i++) {
if (ioatdca->req_slots[i].pdev == pdev) {
global_req_table =
readw(ioatdca->dca_base + IOAT3_DCA_GREQID_OFFSET);
writel(0, ioatdca->iobase + global_req_table + (i * 4));
ioatdca->req_slots[i].pdev = NULL;
ioatdca->req_slots[i].rid = 0;
ioatdca->requester_count--;
return i;
}
}
return -ENODEV;
}
static u8 ioat_dca_get_tag(struct dca_provider *dca,
struct device *dev,
int cpu)
{
u8 tag;
struct ioat_dca_priv *ioatdca = dca_priv(dca);
int i, apic_id, bit, value;
u8 entry;
tag = 0;
apic_id = cpu_physical_id(cpu);
for (i = 0; i < IOAT_TAG_MAP_LEN; i++) {
entry = ioatdca->tag_map[i];
if (entry & DCA3_TAG_MAP_BIT_TO_SEL) {
bit = entry &
~(DCA3_TAG_MAP_BIT_TO_SEL | DCA3_TAG_MAP_BIT_TO_INV);
value = (apic_id & (1 << bit)) ? 1 : 0;
} else if (entry & DCA3_TAG_MAP_BIT_TO_INV) {
bit = entry & ~DCA3_TAG_MAP_BIT_TO_INV;
value = (apic_id & (1 << bit)) ? 0 : 1;
} else {
value = (entry & DCA3_TAG_MAP_LITERAL_VAL) ? 1 : 0;
}
tag |= (value << i);
}
return tag;
}
static int ioat_dca_count_dca_slots(void *iobase, u16 dca_offset)
{
int slots = 0;
u32 req;
u16 global_req_table;
global_req_table = readw(iobase + dca_offset + IOAT3_DCA_GREQID_OFFSET);
if (global_req_table == 0)
return 0;
do {
req = readl(iobase + global_req_table + (slots * sizeof(u32)));
slots++;
} while ((req & IOAT_DCA_GREQID_LASTID) == 0);
return slots;
}
static inline int dca3_tag_map_invalid(u8 *tag_map)
{
return ((tag_map[0] == DCA_TAG_MAP_VALID) &&
(tag_map[1] == DCA_TAG_MAP_VALID) &&
(tag_map[2] == DCA_TAG_MAP_VALID) &&
(tag_map[3] == DCA_TAG_MAP_VALID) &&
(tag_map[4] == DCA_TAG_MAP_VALID));
}
struct dca_provider *ioat_dca_init(struct pci_dev *pdev, void __iomem *iobase)
{
struct dca_provider *dca;
struct ioat_dca_priv *ioatdca;
int slots;
int i;
int err;
u16 dca_offset;
u16 csi_fsb_control;
u16 pcie_control;
u8 bit;
union {
u64 full;
struct {
u32 low;
u32 high;
};
} tag_map;
if (!system_has_dca_enabled(pdev))
return NULL;
dca_offset = readw(iobase + IOAT_DCAOFFSET_OFFSET);
if (dca_offset == 0)
return NULL;
slots = ioat_dca_count_dca_slots(iobase, dca_offset);
if (slots == 0)
return NULL;
dca = alloc_dca_provider(&ioat_dca_ops,
sizeof(*ioatdca)
+ (sizeof(struct ioat_dca_slot) * slots));
if (!dca)
return NULL;
ioatdca = dca_priv(dca);
ioatdca->iobase = iobase;
ioatdca->dca_base = iobase + dca_offset;
ioatdca->max_requesters = slots;
csi_fsb_control = readw(ioatdca->dca_base + IOAT3_CSI_CONTROL_OFFSET);
if ((csi_fsb_control & IOAT3_CSI_CONTROL_PREFETCH) == 0) {
csi_fsb_control |= IOAT3_CSI_CONTROL_PREFETCH;
writew(csi_fsb_control,
ioatdca->dca_base + IOAT3_CSI_CONTROL_OFFSET);
}
pcie_control = readw(ioatdca->dca_base + IOAT3_PCI_CONTROL_OFFSET);
if ((pcie_control & IOAT3_PCI_CONTROL_MEMWR) == 0) {
pcie_control |= IOAT3_PCI_CONTROL_MEMWR;
writew(pcie_control,
ioatdca->dca_base + IOAT3_PCI_CONTROL_OFFSET);
}
tag_map.low =
readl(ioatdca->dca_base + IOAT3_APICID_TAG_MAP_OFFSET_LOW);
tag_map.high =
readl(ioatdca->dca_base + IOAT3_APICID_TAG_MAP_OFFSET_HIGH);
for (i = 0; i < 8; i++) {
bit = tag_map.full >> (8 * i);
ioatdca->tag_map[i] = bit & DCA_TAG_MAP_MASK;
}
if (dca3_tag_map_invalid(ioatdca->tag_map)) {
add_taint(TAINT_FIRMWARE_WORKAROUND, LOCKDEP_STILL_OK);
pr_warn_once("%s %s: APICID_TAG_MAP set incorrectly by BIOS, disabling DCA\n",
dev_driver_string(&pdev->dev),
dev_name(&pdev->dev));
free_dca_provider(dca);
return NULL;
}
err = register_dca_provider(dca, &pdev->dev);
if (err) {
free_dca_provider(dca);
return NULL;
}
return dca;
}
