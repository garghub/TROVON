static struct pci_dev *get_pci_dev(struct device_node *dn)
{
return PCI_DN(dn)->pcidev;
}
struct pci_dev *pnv_pci_get_gpu_dev(struct pci_dev *npdev)
{
struct device_node *dn;
struct pci_dev *gpdev;
if (WARN_ON(!npdev))
return NULL;
if (WARN_ON(!npdev->dev.of_node))
return NULL;
dn = of_parse_phandle(npdev->dev.of_node, "ibm,gpu", 0);
if (!dn)
return NULL;
gpdev = get_pci_dev(dn);
of_node_put(dn);
return gpdev;
}
struct pci_dev *pnv_pci_get_npu_dev(struct pci_dev *gpdev, int index)
{
struct device_node *dn;
struct pci_dev *npdev;
if (WARN_ON(!gpdev))
return NULL;
if (!gpdev->dev.of_node)
return NULL;
dn = of_parse_phandle(gpdev->dev.of_node, "ibm,npu", index);
if (!dn)
return NULL;
npdev = get_pci_dev(dn);
of_node_put(dn);
return npdev;
}
static void *dma_npu_alloc(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flag,
unsigned long attrs)
{
NPU_DMA_OP_UNSUPPORTED();
return NULL;
}
static void dma_npu_free(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle,
unsigned long attrs)
{
NPU_DMA_OP_UNSUPPORTED();
}
static dma_addr_t dma_npu_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction direction,
unsigned long attrs)
{
NPU_DMA_OP_UNSUPPORTED();
return 0;
}
static int dma_npu_map_sg(struct device *dev, struct scatterlist *sglist,
int nelems, enum dma_data_direction direction,
unsigned long attrs)
{
NPU_DMA_OP_UNSUPPORTED();
return 0;
}
static int dma_npu_dma_supported(struct device *dev, u64 mask)
{
NPU_DMA_OP_UNSUPPORTED();
return 0;
}
static u64 dma_npu_get_required_mask(struct device *dev)
{
NPU_DMA_OP_UNSUPPORTED();
return 0;
}
static struct pnv_ioda_pe *get_gpu_pci_dev_and_pe(struct pnv_ioda_pe *npe,
struct pci_dev **gpdev)
{
struct pnv_phb *phb;
struct pci_controller *hose;
struct pci_dev *pdev;
struct pnv_ioda_pe *pe;
struct pci_dn *pdn;
pdev = pnv_pci_get_gpu_dev(npe->pdev);
if (!pdev)
return NULL;
pdn = pci_get_pdn(pdev);
if (WARN_ON(!pdn || pdn->pe_number == IODA_INVALID_PE))
return NULL;
hose = pci_bus_to_host(pdev->bus);
phb = hose->private_data;
pe = &phb->ioda.pe_array[pdn->pe_number];
if (gpdev)
*gpdev = pdev;
return pe;
}
long pnv_npu_set_window(struct pnv_ioda_pe *npe, int num,
struct iommu_table *tbl)
{
struct pnv_phb *phb = npe->phb;
int64_t rc;
const unsigned long size = tbl->it_indirect_levels ?
tbl->it_level_size : tbl->it_size;
const __u64 start_addr = tbl->it_offset << tbl->it_page_shift;
const __u64 win_size = tbl->it_size << tbl->it_page_shift;
pe_info(npe, "Setting up window %llx..%llx pg=%lx\n",
start_addr, start_addr + win_size - 1,
IOMMU_PAGE_SIZE(tbl));
rc = opal_pci_map_pe_dma_window(phb->opal_id,
npe->pe_number,
npe->pe_number,
tbl->it_indirect_levels + 1,
__pa(tbl->it_base),
size << 3,
IOMMU_PAGE_SIZE(tbl));
if (rc) {
pe_err(npe, "Failed to configure TCE table, err %lld\n", rc);
return rc;
}
pnv_pci_ioda2_tce_invalidate_entire(phb, false);
pnv_pci_link_table_and_group(phb->hose->node, num,
tbl, &npe->table_group);
return 0;
}
long pnv_npu_unset_window(struct pnv_ioda_pe *npe, int num)
{
struct pnv_phb *phb = npe->phb;
int64_t rc;
pe_info(npe, "Removing DMA window\n");
rc = opal_pci_map_pe_dma_window(phb->opal_id, npe->pe_number,
npe->pe_number,
0, 0,
0, 0);
if (rc) {
pe_err(npe, "Unmapping failed, ret = %lld\n", rc);
return rc;
}
pnv_pci_ioda2_tce_invalidate_entire(phb, false);
pnv_pci_unlink_table_and_group(npe->table_group.tables[num],
&npe->table_group);
return 0;
}
static void pnv_npu_dma_set_32(struct pnv_ioda_pe *npe)
{
struct pci_dev *gpdev;
struct pnv_ioda_pe *gpe;
int64_t rc;
if (!npe->pdev || !(npe->flags & PNV_IODA_PE_DEV))
return;
gpe = get_gpu_pci_dev_and_pe(npe, &gpdev);
if (!gpe)
return;
rc = pnv_npu_set_window(npe, 0, gpe->table_group.tables[0]);
set_dma_ops(&npe->pdev->dev, &dma_npu_ops);
}
static int pnv_npu_dma_set_bypass(struct pnv_ioda_pe *npe)
{
struct pnv_phb *phb = npe->phb;
int64_t rc = 0;
phys_addr_t top = memblock_end_of_DRAM();
if (phb->type != PNV_PHB_NPU || !npe->pdev)
return -EINVAL;
rc = pnv_npu_unset_window(npe, 0);
if (rc != OPAL_SUCCESS)
return rc;
top = roundup_pow_of_two(top);
dev_info(&npe->pdev->dev, "Enabling bypass for PE %x\n",
npe->pe_number);
rc = opal_pci_map_pe_dma_window_real(phb->opal_id,
npe->pe_number, npe->pe_number,
0 , top);
if (rc == OPAL_SUCCESS)
pnv_pci_ioda2_tce_invalidate_entire(phb, false);
return rc;
}
void pnv_npu_try_dma_set_bypass(struct pci_dev *gpdev, bool bypass)
{
int i;
struct pnv_phb *phb;
struct pci_dn *pdn;
struct pnv_ioda_pe *npe;
struct pci_dev *npdev;
for (i = 0; ; ++i) {
npdev = pnv_pci_get_npu_dev(gpdev, i);
if (!npdev)
break;
pdn = pci_get_pdn(npdev);
if (WARN_ON(!pdn || pdn->pe_number == IODA_INVALID_PE))
return;
phb = pci_bus_to_host(npdev->bus)->private_data;
npe = &phb->ioda.pe_array[pdn->pe_number];
if (bypass) {
dev_info(&npdev->dev,
"Using 64-bit DMA iommu bypass\n");
pnv_npu_dma_set_bypass(npe);
} else {
dev_info(&npdev->dev, "Using 32-bit DMA via iommu\n");
pnv_npu_dma_set_32(npe);
}
}
}
void pnv_npu_take_ownership(struct pnv_ioda_pe *npe)
{
struct pnv_phb *phb = npe->phb;
int64_t rc;
if (npe->table_group.tables[0]) {
pnv_npu_unset_window(npe, 0);
return;
}
rc = opal_pci_map_pe_dma_window_real(phb->opal_id,
npe->pe_number, npe->pe_number,
0 , 0);
if (rc) {
pe_err(npe, "Failed to disable bypass, err %lld\n", rc);
return;
}
pnv_pci_ioda2_tce_invalidate_entire(npe->phb, false);
}
struct pnv_ioda_pe *pnv_pci_npu_setup_iommu(struct pnv_ioda_pe *npe)
{
struct pnv_phb *phb = npe->phb;
struct pci_bus *pbus = phb->hose->bus;
struct pci_dev *npdev, *gpdev = NULL, *gptmp;
struct pnv_ioda_pe *gpe = get_gpu_pci_dev_and_pe(npe, &gpdev);
if (!gpe || !gpdev)
return NULL;
list_for_each_entry(npdev, &pbus->devices, bus_list) {
gptmp = pnv_pci_get_gpu_dev(npdev);
if (gptmp != gpdev)
continue;
pe_info(gpe, "Attached NPU %s\n", dev_name(&npdev->dev));
iommu_group_add_device(gpe->table_group.group, &npdev->dev);
}
return gpe;
}
static int get_mmio_atsd_reg(struct npu *npu)
{
int i;
for (i = 0; i < npu->mmio_atsd_count; i++) {
if (!test_and_set_bit(i, &npu->mmio_atsd_usage))
return i;
}
return -ENOSPC;
}
static void put_mmio_atsd_reg(struct npu *npu, int reg)
{
clear_bit(reg, &npu->mmio_atsd_usage);
}
static int mmio_launch_invalidate(struct npu *npu, unsigned long launch,
unsigned long va)
{
int mmio_atsd_reg;
do {
mmio_atsd_reg = get_mmio_atsd_reg(npu);
cpu_relax();
} while (mmio_atsd_reg < 0);
__raw_writeq(cpu_to_be64(va),
npu->mmio_atsd_regs[mmio_atsd_reg] + XTS_ATSD_AVA);
eieio();
__raw_writeq(cpu_to_be64(launch), npu->mmio_atsd_regs[mmio_atsd_reg]);
return mmio_atsd_reg;
}
static int mmio_invalidate_pid(struct npu *npu, unsigned long pid, bool flush)
{
unsigned long launch;
launch = PPC_BIT(12);
launch |= PPC_BIT(13);
launch |= (u64) mmu_get_ap(mmu_virtual_psize) << PPC_BITLSHIFT(17);
launch |= pid << PPC_BITLSHIFT(38);
launch |= !flush << PPC_BITLSHIFT(39);
return mmio_launch_invalidate(npu, launch, 0);
}
static int mmio_invalidate_va(struct npu *npu, unsigned long va,
unsigned long pid, bool flush)
{
unsigned long launch;
launch = 0;
launch |= PPC_BIT(13);
launch |= (u64) mmu_get_ap(mmu_virtual_psize) << PPC_BITLSHIFT(17);
launch |= pid << PPC_BITLSHIFT(38);
launch |= !flush << PPC_BITLSHIFT(39);
return mmio_launch_invalidate(npu, launch, va);
}
static void mmio_invalidate_wait(
struct mmio_atsd_reg mmio_atsd_reg[NV_MAX_NPUS], bool flush)
{
struct npu *npu;
int i, reg;
for (i = 0; i <= max_npu2_index; i++) {
if (mmio_atsd_reg[i].reg < 0)
continue;
npu = mmio_atsd_reg[i].npu;
reg = mmio_atsd_reg[i].reg;
while (__raw_readq(npu->mmio_atsd_regs[reg] + XTS_ATSD_STAT))
cpu_relax();
put_mmio_atsd_reg(npu, reg);
if (flush)
mmio_invalidate_pid(npu, 0, true);
}
}
static void mmio_invalidate(struct npu_context *npu_context, int va,
unsigned long address, bool flush)
{
int i, j;
struct npu *npu;
struct pnv_phb *nphb;
struct pci_dev *npdev;
struct mmio_atsd_reg mmio_atsd_reg[NV_MAX_NPUS];
unsigned long pid = npu_context->mm->context.id;
for (i = 0; i <= max_npu2_index; i++) {
mmio_atsd_reg[i].reg = -1;
for (j = 0; j < NV_MAX_LINKS; j++) {
npdev = npu_context->npdev[i][j];
if (!npdev)
continue;
nphb = pci_bus_to_host(npdev->bus)->private_data;
npu = &nphb->npu;
mmio_atsd_reg[i].npu = npu;
if (va)
mmio_atsd_reg[i].reg =
mmio_invalidate_va(npu, address, pid,
flush);
else
mmio_atsd_reg[i].reg =
mmio_invalidate_pid(npu, pid, flush);
break;
}
}
flush_tlb_mm(npu_context->mm);
mmio_invalidate_wait(mmio_atsd_reg, flush);
if (flush)
mmio_invalidate_wait(mmio_atsd_reg, false);
}
static void pnv_npu2_mn_release(struct mmu_notifier *mn,
struct mm_struct *mm)
{
struct npu_context *npu_context = mn_to_npu_context(mn);
if (npu_context->release_cb)
npu_context->release_cb(npu_context, npu_context->priv);
mmio_invalidate(npu_context, 0, 0, true);
}
static void pnv_npu2_mn_change_pte(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long address,
pte_t pte)
{
struct npu_context *npu_context = mn_to_npu_context(mn);
mmio_invalidate(npu_context, 1, address, true);
}
static void pnv_npu2_mn_invalidate_page(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long address)
{
struct npu_context *npu_context = mn_to_npu_context(mn);
mmio_invalidate(npu_context, 1, address, true);
}
static void pnv_npu2_mn_invalidate_range(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start, unsigned long end)
{
struct npu_context *npu_context = mn_to_npu_context(mn);
unsigned long address;
for (address = start; address < end; address += PAGE_SIZE)
mmio_invalidate(npu_context, 1, address, false);
mmio_invalidate(npu_context, 1, address, true);
}
static void pnv_npu2_release_context(struct kref *kref)
{
struct npu_context *npu_context =
container_of(kref, struct npu_context, kref);
npu_context->mm->context.npu_context = NULL;
mmu_notifier_unregister(&npu_context->mn,
npu_context->mm);
kfree(npu_context);
}
void pnv_npu2_destroy_context(struct npu_context *npu_context,
struct pci_dev *gpdev)
{
struct pnv_phb *nphb;
struct npu *npu;
struct pci_dev *npdev = pnv_pci_get_npu_dev(gpdev, 0);
struct device_node *nvlink_dn;
u32 nvlink_index;
if (WARN_ON(!npdev))
return;
if (!firmware_has_feature(FW_FEATURE_OPAL))
return;
nphb = pci_bus_to_host(npdev->bus)->private_data;
npu = &nphb->npu;
nvlink_dn = of_parse_phandle(npdev->dev.of_node, "ibm,nvlink", 0);
if (WARN_ON(of_property_read_u32(nvlink_dn, "ibm,npu-link-index",
&nvlink_index)))
return;
npu_context->npdev[npu->index][nvlink_index] = NULL;
opal_npu_destroy_context(nphb->opal_id, npu_context->mm->context.id,
PCI_DEVID(gpdev->bus->number, gpdev->devfn));
kref_put(&npu_context->kref, pnv_npu2_release_context);
}
int pnv_npu2_handle_fault(struct npu_context *context, uintptr_t *ea,
unsigned long *flags, unsigned long *status, int count)
{
u64 rc = 0, result = 0;
int i, is_write;
struct page *page[1];
struct mm_struct *mm = context->mm;
if (!firmware_has_feature(FW_FEATURE_OPAL))
return -ENODEV;
WARN_ON(!rwsem_is_locked(&mm->mmap_sem));
for (i = 0; i < count; i++) {
is_write = flags[i] & NPU2_WRITE;
rc = get_user_pages_remote(NULL, mm, ea[i], 1,
is_write ? FOLL_WRITE : 0,
page, NULL, NULL);
if (rc != 1) {
status[i] = rc;
result = -EFAULT;
continue;
}
status[i] = 0;
put_page(page[0]);
}
return result;
}
int pnv_npu2_init(struct pnv_phb *phb)
{
unsigned int i;
u64 mmio_atsd;
struct device_node *dn;
struct pci_dev *gpdev;
static int npu_index;
uint64_t rc = 0;
for_each_child_of_node(phb->hose->dn, dn) {
gpdev = pnv_pci_get_gpu_dev(get_pci_dev(dn));
if (gpdev) {
rc = opal_npu_map_lpar(phb->opal_id,
PCI_DEVID(gpdev->bus->number, gpdev->devfn),
0, 0);
if (rc)
dev_err(&gpdev->dev,
"Error %lld mapping device to LPAR\n",
rc);
}
}
for (i = 0; !of_property_read_u64_index(phb->hose->dn, "ibm,mmio-atsd",
i, &mmio_atsd); i++)
phb->npu.mmio_atsd_regs[i] = ioremap(mmio_atsd, 32);
pr_info("NPU%lld: Found %d MMIO ATSD registers", phb->opal_id, i);
phb->npu.mmio_atsd_count = i;
phb->npu.mmio_atsd_usage = 0;
npu_index++;
if (WARN_ON(npu_index >= NV_MAX_NPUS))
return -ENOSPC;
max_npu2_index = npu_index;
phb->npu.index = npu_index;
return 0;
}
