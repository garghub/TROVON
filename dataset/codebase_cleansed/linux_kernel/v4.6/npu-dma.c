static struct pci_dev *get_pci_dev(struct device_node *dn)
{
return PCI_DN(dn)->pcidev;
}
struct pci_dev *pnv_pci_get_gpu_dev(struct pci_dev *npdev)
{
struct device_node *dn;
struct pci_dev *gpdev;
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
dn = of_parse_phandle(gpdev->dev.of_node, "ibm,npu", index);
if (!dn)
return NULL;
npdev = get_pci_dev(dn);
of_node_put(dn);
return npdev;
}
static void *dma_npu_alloc(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flag,
struct dma_attrs *attrs)
{
NPU_DMA_OP_UNSUPPORTED();
return NULL;
}
static void dma_npu_free(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle,
struct dma_attrs *attrs)
{
NPU_DMA_OP_UNSUPPORTED();
}
static dma_addr_t dma_npu_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction direction,
struct dma_attrs *attrs)
{
NPU_DMA_OP_UNSUPPORTED();
return 0;
}
static int dma_npu_map_sg(struct device *dev, struct scatterlist *sglist,
int nelems, enum dma_data_direction direction,
struct dma_attrs *attrs)
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
if (npe->flags & PNV_IODA_PE_PEER) {
pe = npe->peers[0];
pdev = pe->pdev;
} else {
pdev = pnv_pci_get_gpu_dev(npe->pdev);
if (!pdev)
return NULL;
pdn = pci_get_pdn(pdev);
if (WARN_ON(!pdn || pdn->pe_number == IODA_INVALID_PE))
return NULL;
hose = pci_bus_to_host(pdev->bus);
phb = hose->private_data;
pe = &phb->ioda.pe_array[pdn->pe_number];
}
if (gpdev)
*gpdev = pdev;
return pe;
}
void pnv_npu_tce_invalidate_entire(struct pnv_ioda_pe *npe)
{
struct pnv_phb *phb = npe->phb;
if (WARN_ON(phb->type != PNV_PHB_NPU ||
!phb->ioda.tce_inval_reg ||
!(npe->flags & PNV_IODA_PE_DEV)))
return;
mb();
__raw_writeq(cpu_to_be64(TCE_KILL_INVAL_ALL),
phb->ioda.tce_inval_reg);
}
void pnv_npu_tce_invalidate(struct pnv_ioda_pe *npe,
struct iommu_table *tbl,
unsigned long index,
unsigned long npages,
bool rm)
{
struct pnv_phb *phb = npe->phb;
unsigned long val = TCE_KILL_INVAL_ALL;
if (WARN_ON(phb->type != PNV_PHB_NPU ||
!phb->ioda.tce_inval_reg ||
!(npe->flags & PNV_IODA_PE_DEV)))
return;
mb();
if (rm)
__raw_rm_writeq(cpu_to_be64(val),
(__be64 __iomem *) phb->ioda.tce_inval_reg_phys);
else
__raw_writeq(cpu_to_be64(val),
phb->ioda.tce_inval_reg);
}
void pnv_npu_init_dma_pe(struct pnv_ioda_pe *npe)
{
struct pnv_ioda_pe *gpe;
struct pci_dev *gpdev;
int i, avail = -1;
if (!npe->pdev || !(npe->flags & PNV_IODA_PE_DEV))
return;
gpe = get_gpu_pci_dev_and_pe(npe, &gpdev);
if (!gpe)
return;
for (i = 0; i < PNV_IODA_MAX_PEER_PES; i++) {
if (gpe->peers[i] == npe)
return;
if (!gpe->peers[i])
avail = i;
}
if (WARN_ON(avail < 0))
return;
gpe->peers[avail] = npe;
gpe->flags |= PNV_IODA_PE_PEER;
npe->peers[0] = gpe;
npe->flags |= PNV_IODA_PE_PEER;
}
static void pnv_npu_disable_bypass(struct pnv_ioda_pe *npe)
{
struct pnv_phb *phb = npe->phb;
struct pci_dev *gpdev;
struct pnv_ioda_pe *gpe;
void *addr;
unsigned int size;
int64_t rc;
if (!npe->pdev || !(npe->flags & PNV_IODA_PE_DEV))
return;
gpe = get_gpu_pci_dev_and_pe(npe, &gpdev);
if (!gpe)
return;
addr = (void *)gpe->table_group.tables[0]->it_base;
size = gpe->table_group.tables[0]->it_size << 3;
rc = opal_pci_map_pe_dma_window(phb->opal_id, npe->pe_number,
npe->pe_number, 1, __pa(addr),
size, 0x1000);
if (rc != OPAL_SUCCESS)
pr_warn("%s: Error %lld setting DMA window on PHB#%d-PE#%d\n",
__func__, rc, phb->hose->global_number, npe->pe_number);
set_dma_ops(&npe->pdev->dev, &dma_npu_ops);
}
int pnv_npu_dma_set_bypass(struct pnv_ioda_pe *npe, bool enable)
{
struct pnv_phb *phb = npe->phb;
int64_t rc = 0;
if (phb->type != PNV_PHB_NPU || !npe->pdev)
return -EINVAL;
if (enable) {
phys_addr_t top = memblock_end_of_DRAM();
npe->tce_bypass_base = 0;
top = roundup_pow_of_two(top);
dev_info(&npe->pdev->dev, "Enabling bypass for PE %d\n",
npe->pe_number);
rc = opal_pci_map_pe_dma_window_real(phb->opal_id,
npe->pe_number, npe->pe_number,
npe->tce_bypass_base, top);
} else {
pnv_npu_disable_bypass(npe);
}
return rc;
}
int pnv_npu_dma_set_mask(struct pci_dev *npdev, u64 dma_mask)
{
struct pci_controller *hose = pci_bus_to_host(npdev->bus);
struct pnv_phb *phb = hose->private_data;
struct pci_dn *pdn = pci_get_pdn(npdev);
struct pnv_ioda_pe *npe, *gpe;
struct pci_dev *gpdev;
uint64_t top;
bool bypass = false;
if (WARN_ON(!pdn || pdn->pe_number == IODA_INVALID_PE))
return -ENXIO;
npe = &phb->ioda.pe_array[pdn->pe_number];
gpe = get_gpu_pci_dev_and_pe(npe, &gpdev);
if (!gpe)
return -ENODEV;
if (gpe->tce_bypass_enabled) {
top = gpe->tce_bypass_base + memblock_end_of_DRAM() - 1;
bypass = (dma_mask >= top);
}
if (bypass)
dev_info(&npdev->dev, "Using 64-bit DMA iommu bypass\n");
else
dev_info(&npdev->dev, "Using 32-bit DMA via iommu\n");
pnv_npu_dma_set_bypass(npe, bypass);
*npdev->dev.dma_mask = dma_mask;
return 0;
}
