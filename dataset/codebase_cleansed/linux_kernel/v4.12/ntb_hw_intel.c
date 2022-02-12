static inline u64 _ioread64(void __iomem *mmio)
{
u64 low, high;
low = ioread32(mmio);
high = ioread32(mmio + sizeof(u32));
return low | (high << 32);
}
static inline void _iowrite64(u64 val, void __iomem *mmio)
{
iowrite32(val, mmio);
iowrite32(val >> 32, mmio + sizeof(u32));
}
static inline int pdev_is_atom(struct pci_dev *pdev)
{
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_NTB_B2B_BWD:
return 1;
}
return 0;
}
static inline int pdev_is_xeon(struct pci_dev *pdev)
{
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_NTB_SS_JSF:
case PCI_DEVICE_ID_INTEL_NTB_SS_SNB:
case PCI_DEVICE_ID_INTEL_NTB_SS_IVT:
case PCI_DEVICE_ID_INTEL_NTB_SS_HSX:
case PCI_DEVICE_ID_INTEL_NTB_SS_BDX:
case PCI_DEVICE_ID_INTEL_NTB_PS_JSF:
case PCI_DEVICE_ID_INTEL_NTB_PS_SNB:
case PCI_DEVICE_ID_INTEL_NTB_PS_IVT:
case PCI_DEVICE_ID_INTEL_NTB_PS_HSX:
case PCI_DEVICE_ID_INTEL_NTB_PS_BDX:
case PCI_DEVICE_ID_INTEL_NTB_B2B_JSF:
case PCI_DEVICE_ID_INTEL_NTB_B2B_SNB:
case PCI_DEVICE_ID_INTEL_NTB_B2B_IVT:
case PCI_DEVICE_ID_INTEL_NTB_B2B_HSX:
case PCI_DEVICE_ID_INTEL_NTB_B2B_BDX:
return 1;
}
return 0;
}
static inline int pdev_is_skx_xeon(struct pci_dev *pdev)
{
if (pdev->device == PCI_DEVICE_ID_INTEL_NTB_B2B_SKX)
return 1;
return 0;
}
static inline void ndev_reset_unsafe_flags(struct intel_ntb_dev *ndev)
{
ndev->unsafe_flags = 0;
ndev->unsafe_flags_ignore = 0;
if (ndev->hwerr_flags & NTB_HWERR_SDOORBELL_LOCKUP)
if (!ntb_topo_is_b2b(ndev->ntb.topo))
ndev->unsafe_flags |= NTB_UNSAFE_DB;
if (ndev->hwerr_flags & NTB_HWERR_SB01BASE_LOCKUP) {
ndev->unsafe_flags |= NTB_UNSAFE_DB;
ndev->unsafe_flags |= NTB_UNSAFE_SPAD;
}
}
static inline int ndev_is_unsafe(struct intel_ntb_dev *ndev,
unsigned long flag)
{
return !!(flag & ndev->unsafe_flags & ~ndev->unsafe_flags_ignore);
}
static inline int ndev_ignore_unsafe(struct intel_ntb_dev *ndev,
unsigned long flag)
{
flag &= ndev->unsafe_flags;
ndev->unsafe_flags_ignore |= flag;
return !!flag;
}
static int ndev_mw_to_bar(struct intel_ntb_dev *ndev, int idx)
{
if (idx < 0 || idx >= ndev->mw_count)
return -EINVAL;
return ndev->reg->mw_bar[idx];
}
static inline int ndev_db_addr(struct intel_ntb_dev *ndev,
phys_addr_t *db_addr, resource_size_t *db_size,
phys_addr_t reg_addr, unsigned long reg)
{
if (ndev_is_unsafe(ndev, NTB_UNSAFE_DB))
pr_warn_once("%s: NTB unsafe doorbell access", __func__);
if (db_addr) {
*db_addr = reg_addr + reg;
dev_dbg(ndev_dev(ndev), "Peer db addr %llx\n", *db_addr);
}
if (db_size) {
*db_size = ndev->reg->db_size;
dev_dbg(ndev_dev(ndev), "Peer db size %llx\n", *db_size);
}
return 0;
}
static inline u64 ndev_db_read(struct intel_ntb_dev *ndev,
void __iomem *mmio)
{
if (ndev_is_unsafe(ndev, NTB_UNSAFE_DB))
pr_warn_once("%s: NTB unsafe doorbell access", __func__);
return ndev->reg->db_ioread(mmio);
}
static inline int ndev_db_write(struct intel_ntb_dev *ndev, u64 db_bits,
void __iomem *mmio)
{
if (ndev_is_unsafe(ndev, NTB_UNSAFE_DB))
pr_warn_once("%s: NTB unsafe doorbell access", __func__);
if (db_bits & ~ndev->db_valid_mask)
return -EINVAL;
ndev->reg->db_iowrite(db_bits, mmio);
return 0;
}
static inline int ndev_db_set_mask(struct intel_ntb_dev *ndev, u64 db_bits,
void __iomem *mmio)
{
unsigned long irqflags;
if (ndev_is_unsafe(ndev, NTB_UNSAFE_DB))
pr_warn_once("%s: NTB unsafe doorbell access", __func__);
if (db_bits & ~ndev->db_valid_mask)
return -EINVAL;
spin_lock_irqsave(&ndev->db_mask_lock, irqflags);
{
ndev->db_mask |= db_bits;
ndev->reg->db_iowrite(ndev->db_mask, mmio);
}
spin_unlock_irqrestore(&ndev->db_mask_lock, irqflags);
return 0;
}
static inline int ndev_db_clear_mask(struct intel_ntb_dev *ndev, u64 db_bits,
void __iomem *mmio)
{
unsigned long irqflags;
if (ndev_is_unsafe(ndev, NTB_UNSAFE_DB))
pr_warn_once("%s: NTB unsafe doorbell access", __func__);
if (db_bits & ~ndev->db_valid_mask)
return -EINVAL;
spin_lock_irqsave(&ndev->db_mask_lock, irqflags);
{
ndev->db_mask &= ~db_bits;
ndev->reg->db_iowrite(ndev->db_mask, mmio);
}
spin_unlock_irqrestore(&ndev->db_mask_lock, irqflags);
return 0;
}
static inline int ndev_vec_mask(struct intel_ntb_dev *ndev, int db_vector)
{
u64 shift, mask;
shift = ndev->db_vec_shift;
mask = BIT_ULL(shift) - 1;
return mask << (shift * db_vector);
}
static inline int ndev_spad_addr(struct intel_ntb_dev *ndev, int idx,
phys_addr_t *spad_addr, phys_addr_t reg_addr,
unsigned long reg)
{
if (ndev_is_unsafe(ndev, NTB_UNSAFE_SPAD))
pr_warn_once("%s: NTB unsafe scratchpad access", __func__);
if (idx < 0 || idx >= ndev->spad_count)
return -EINVAL;
if (spad_addr) {
*spad_addr = reg_addr + reg + (idx << 2);
dev_dbg(ndev_dev(ndev), "Peer spad addr %llx\n", *spad_addr);
}
return 0;
}
static inline u32 ndev_spad_read(struct intel_ntb_dev *ndev, int idx,
void __iomem *mmio)
{
if (ndev_is_unsafe(ndev, NTB_UNSAFE_SPAD))
pr_warn_once("%s: NTB unsafe scratchpad access", __func__);
if (idx < 0 || idx >= ndev->spad_count)
return 0;
return ioread32(mmio + (idx << 2));
}
static inline int ndev_spad_write(struct intel_ntb_dev *ndev, int idx, u32 val,
void __iomem *mmio)
{
if (ndev_is_unsafe(ndev, NTB_UNSAFE_SPAD))
pr_warn_once("%s: NTB unsafe scratchpad access", __func__);
if (idx < 0 || idx >= ndev->spad_count)
return -EINVAL;
iowrite32(val, mmio + (idx << 2));
return 0;
}
static irqreturn_t ndev_interrupt(struct intel_ntb_dev *ndev, int vec)
{
u64 vec_mask;
vec_mask = ndev_vec_mask(ndev, vec);
if ((ndev->hwerr_flags & NTB_HWERR_MSIX_VECTOR32_BAD) && (vec == 31))
vec_mask |= ndev->db_link_mask;
dev_dbg(ndev_dev(ndev), "vec %d vec_mask %llx\n", vec, vec_mask);
ndev->last_ts = jiffies;
if (vec_mask & ndev->db_link_mask) {
if (ndev->reg->poll_link(ndev))
ntb_link_event(&ndev->ntb);
}
if (vec_mask & ndev->db_valid_mask)
ntb_db_event(&ndev->ntb, vec);
return IRQ_HANDLED;
}
static irqreturn_t ndev_vec_isr(int irq, void *dev)
{
struct intel_ntb_vec *nvec = dev;
dev_dbg(ndev_dev(nvec->ndev), "irq: %d nvec->num: %d\n",
irq, nvec->num);
return ndev_interrupt(nvec->ndev, nvec->num);
}
static irqreturn_t ndev_irq_isr(int irq, void *dev)
{
struct intel_ntb_dev *ndev = dev;
return ndev_interrupt(ndev, irq - ndev_pdev(ndev)->irq);
}
static int ndev_init_isr(struct intel_ntb_dev *ndev,
int msix_min, int msix_max,
int msix_shift, int total_shift)
{
struct pci_dev *pdev;
int rc, i, msix_count, node;
pdev = ndev_pdev(ndev);
node = dev_to_node(&pdev->dev);
ndev->db_mask = ndev->db_valid_mask;
ndev->reg->db_iowrite(ndev->db_mask,
ndev->self_mmio +
ndev->self_reg->db_mask);
ndev->vec = kzalloc_node(msix_max * sizeof(*ndev->vec),
GFP_KERNEL, node);
if (!ndev->vec)
goto err_msix_vec_alloc;
ndev->msix = kzalloc_node(msix_max * sizeof(*ndev->msix),
GFP_KERNEL, node);
if (!ndev->msix)
goto err_msix_alloc;
for (i = 0; i < msix_max; ++i)
ndev->msix[i].entry = i;
msix_count = pci_enable_msix_range(pdev, ndev->msix,
msix_min, msix_max);
if (msix_count < 0)
goto err_msix_enable;
for (i = 0; i < msix_count; ++i) {
ndev->vec[i].ndev = ndev;
ndev->vec[i].num = i;
rc = request_irq(ndev->msix[i].vector, ndev_vec_isr, 0,
"ndev_vec_isr", &ndev->vec[i]);
if (rc)
goto err_msix_request;
}
dev_dbg(ndev_dev(ndev), "Using %d msix interrupts\n", msix_count);
ndev->db_vec_count = msix_count;
ndev->db_vec_shift = msix_shift;
return 0;
err_msix_request:
while (i-- > 0)
free_irq(ndev->msix[i].vector, &ndev->vec[i]);
pci_disable_msix(pdev);
err_msix_enable:
kfree(ndev->msix);
err_msix_alloc:
kfree(ndev->vec);
err_msix_vec_alloc:
ndev->msix = NULL;
ndev->vec = NULL;
rc = pci_enable_msi(pdev);
if (rc)
goto err_msi_enable;
rc = request_irq(pdev->irq, ndev_irq_isr, 0,
"ndev_irq_isr", ndev);
if (rc)
goto err_msi_request;
dev_dbg(ndev_dev(ndev), "Using msi interrupts\n");
ndev->db_vec_count = 1;
ndev->db_vec_shift = total_shift;
return 0;
err_msi_request:
pci_disable_msi(pdev);
err_msi_enable:
pci_intx(pdev, 1);
rc = request_irq(pdev->irq, ndev_irq_isr, IRQF_SHARED,
"ndev_irq_isr", ndev);
if (rc)
goto err_intx_request;
dev_dbg(ndev_dev(ndev), "Using intx interrupts\n");
ndev->db_vec_count = 1;
ndev->db_vec_shift = total_shift;
return 0;
err_intx_request:
return rc;
}
static void ndev_deinit_isr(struct intel_ntb_dev *ndev)
{
struct pci_dev *pdev;
int i;
pdev = ndev_pdev(ndev);
ndev->db_mask = ndev->db_valid_mask;
ndev->reg->db_iowrite(ndev->db_mask,
ndev->self_mmio +
ndev->self_reg->db_mask);
if (ndev->msix) {
i = ndev->db_vec_count;
while (i--)
free_irq(ndev->msix[i].vector, &ndev->vec[i]);
pci_disable_msix(pdev);
kfree(ndev->msix);
kfree(ndev->vec);
} else {
free_irq(pdev->irq, ndev);
if (pci_dev_msi_enabled(pdev))
pci_disable_msi(pdev);
}
}
static ssize_t ndev_ntb3_debugfs_read(struct file *filp, char __user *ubuf,
size_t count, loff_t *offp)
{
struct intel_ntb_dev *ndev;
void __iomem *mmio;
char *buf;
size_t buf_size;
ssize_t ret, off;
union { u64 v64; u32 v32; u16 v16; } u;
ndev = filp->private_data;
mmio = ndev->self_mmio;
buf_size = min(count, 0x800ul);
buf = kmalloc(buf_size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
off = 0;
off += scnprintf(buf + off, buf_size - off,
"NTB Device Information:\n");
off += scnprintf(buf + off, buf_size - off,
"Connection Topology -\t%s\n",
ntb_topo_string(ndev->ntb.topo));
off += scnprintf(buf + off, buf_size - off,
"NTB CTL -\t\t%#06x\n", ndev->ntb_ctl);
off += scnprintf(buf + off, buf_size - off,
"LNK STA -\t\t%#06x\n", ndev->lnk_sta);
if (!ndev->reg->link_is_up(ndev))
off += scnprintf(buf + off, buf_size - off,
"Link Status -\t\tDown\n");
else {
off += scnprintf(buf + off, buf_size - off,
"Link Status -\t\tUp\n");
off += scnprintf(buf + off, buf_size - off,
"Link Speed -\t\tPCI-E Gen %u\n",
NTB_LNK_STA_SPEED(ndev->lnk_sta));
off += scnprintf(buf + off, buf_size - off,
"Link Width -\t\tx%u\n",
NTB_LNK_STA_WIDTH(ndev->lnk_sta));
}
off += scnprintf(buf + off, buf_size - off,
"Memory Window Count -\t%u\n", ndev->mw_count);
off += scnprintf(buf + off, buf_size - off,
"Scratchpad Count -\t%u\n", ndev->spad_count);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Count -\t%u\n", ndev->db_count);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Vector Count -\t%u\n", ndev->db_vec_count);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Vector Shift -\t%u\n", ndev->db_vec_shift);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Valid Mask -\t%#llx\n", ndev->db_valid_mask);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Link Mask -\t%#llx\n", ndev->db_link_mask);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Mask Cached -\t%#llx\n", ndev->db_mask);
u.v64 = ndev_db_read(ndev, mmio + ndev->self_reg->db_mask);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Mask -\t\t%#llx\n", u.v64);
u.v64 = ndev_db_read(ndev, mmio + ndev->self_reg->db_bell);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Bell -\t\t%#llx\n", u.v64);
off += scnprintf(buf + off, buf_size - off,
"\nNTB Incoming XLAT:\n");
u.v64 = ioread64(mmio + SKX_IMBAR1XBASE_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"IMBAR1XBASE -\t\t%#018llx\n", u.v64);
u.v64 = ioread64(mmio + SKX_IMBAR2XBASE_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"IMBAR2XBASE -\t\t%#018llx\n", u.v64);
u.v64 = ioread64(mmio + SKX_IMBAR1XLMT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"IMBAR1XLMT -\t\t\t%#018llx\n", u.v64);
u.v64 = ioread64(mmio + SKX_IMBAR2XLMT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"IMBAR2XLMT -\t\t\t%#018llx\n", u.v64);
if (ntb_topo_is_b2b(ndev->ntb.topo)) {
off += scnprintf(buf + off, buf_size - off,
"\nNTB Outgoing B2B XLAT:\n");
u.v64 = ioread64(mmio + SKX_EMBAR1XBASE_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"EMBAR1XBASE -\t\t%#018llx\n", u.v64);
u.v64 = ioread64(mmio + SKX_EMBAR2XBASE_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"EMBAR2XBASE -\t\t%#018llx\n", u.v64);
u.v64 = ioread64(mmio + SKX_EMBAR1XLMT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"EMBAR1XLMT -\t\t%#018llx\n", u.v64);
u.v64 = ioread64(mmio + SKX_EMBAR2XLMT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"EMBAR2XLMT -\t\t%#018llx\n", u.v64);
off += scnprintf(buf + off, buf_size - off,
"\nNTB Secondary BAR:\n");
u.v64 = ioread64(mmio + SKX_EMBAR0_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"EMBAR0 -\t\t%#018llx\n", u.v64);
u.v64 = ioread64(mmio + SKX_EMBAR1_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"EMBAR1 -\t\t%#018llx\n", u.v64);
u.v64 = ioread64(mmio + SKX_EMBAR2_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"EMBAR2 -\t\t%#018llx\n", u.v64);
}
off += scnprintf(buf + off, buf_size - off,
"\nNTB Statistics:\n");
u.v16 = ioread16(mmio + SKX_USMEMMISS_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"Upstream Memory Miss -\t%u\n", u.v16);
off += scnprintf(buf + off, buf_size - off,
"\nNTB Hardware Errors:\n");
if (!pci_read_config_word(ndev->ntb.pdev,
SKX_DEVSTS_OFFSET, &u.v16))
off += scnprintf(buf + off, buf_size - off,
"DEVSTS -\t\t%#06x\n", u.v16);
if (!pci_read_config_word(ndev->ntb.pdev,
SKX_LINK_STATUS_OFFSET, &u.v16))
off += scnprintf(buf + off, buf_size - off,
"LNKSTS -\t\t%#06x\n", u.v16);
if (!pci_read_config_dword(ndev->ntb.pdev,
SKX_UNCERRSTS_OFFSET, &u.v32))
off += scnprintf(buf + off, buf_size - off,
"UNCERRSTS -\t\t%#06x\n", u.v32);
if (!pci_read_config_dword(ndev->ntb.pdev,
SKX_CORERRSTS_OFFSET, &u.v32))
off += scnprintf(buf + off, buf_size - off,
"CORERRSTS -\t\t%#06x\n", u.v32);
ret = simple_read_from_buffer(ubuf, count, offp, buf, off);
kfree(buf);
return ret;
}
static ssize_t ndev_ntb_debugfs_read(struct file *filp, char __user *ubuf,
size_t count, loff_t *offp)
{
struct intel_ntb_dev *ndev;
struct pci_dev *pdev;
void __iomem *mmio;
char *buf;
size_t buf_size;
ssize_t ret, off;
union { u64 v64; u32 v32; u16 v16; u8 v8; } u;
ndev = filp->private_data;
pdev = ndev_pdev(ndev);
mmio = ndev->self_mmio;
buf_size = min(count, 0x800ul);
buf = kmalloc(buf_size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
off = 0;
off += scnprintf(buf + off, buf_size - off,
"NTB Device Information:\n");
off += scnprintf(buf + off, buf_size - off,
"Connection Topology -\t%s\n",
ntb_topo_string(ndev->ntb.topo));
if (ndev->b2b_idx != UINT_MAX) {
off += scnprintf(buf + off, buf_size - off,
"B2B MW Idx -\t\t%u\n", ndev->b2b_idx);
off += scnprintf(buf + off, buf_size - off,
"B2B Offset -\t\t%#lx\n", ndev->b2b_off);
}
off += scnprintf(buf + off, buf_size - off,
"BAR4 Split -\t\t%s\n",
ndev->bar4_split ? "yes" : "no");
off += scnprintf(buf + off, buf_size - off,
"NTB CTL -\t\t%#06x\n", ndev->ntb_ctl);
off += scnprintf(buf + off, buf_size - off,
"LNK STA -\t\t%#06x\n", ndev->lnk_sta);
if (!ndev->reg->link_is_up(ndev)) {
off += scnprintf(buf + off, buf_size - off,
"Link Status -\t\tDown\n");
} else {
off += scnprintf(buf + off, buf_size - off,
"Link Status -\t\tUp\n");
off += scnprintf(buf + off, buf_size - off,
"Link Speed -\t\tPCI-E Gen %u\n",
NTB_LNK_STA_SPEED(ndev->lnk_sta));
off += scnprintf(buf + off, buf_size - off,
"Link Width -\t\tx%u\n",
NTB_LNK_STA_WIDTH(ndev->lnk_sta));
}
off += scnprintf(buf + off, buf_size - off,
"Memory Window Count -\t%u\n", ndev->mw_count);
off += scnprintf(buf + off, buf_size - off,
"Scratchpad Count -\t%u\n", ndev->spad_count);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Count -\t%u\n", ndev->db_count);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Vector Count -\t%u\n", ndev->db_vec_count);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Vector Shift -\t%u\n", ndev->db_vec_shift);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Valid Mask -\t%#llx\n", ndev->db_valid_mask);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Link Mask -\t%#llx\n", ndev->db_link_mask);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Mask Cached -\t%#llx\n", ndev->db_mask);
u.v64 = ndev_db_read(ndev, mmio + ndev->self_reg->db_mask);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Mask -\t\t%#llx\n", u.v64);
u.v64 = ndev_db_read(ndev, mmio + ndev->self_reg->db_bell);
off += scnprintf(buf + off, buf_size - off,
"Doorbell Bell -\t\t%#llx\n", u.v64);
off += scnprintf(buf + off, buf_size - off,
"\nNTB Window Size:\n");
pci_read_config_byte(pdev, XEON_PBAR23SZ_OFFSET, &u.v8);
off += scnprintf(buf + off, buf_size - off,
"PBAR23SZ %hhu\n", u.v8);
if (!ndev->bar4_split) {
pci_read_config_byte(pdev, XEON_PBAR45SZ_OFFSET, &u.v8);
off += scnprintf(buf + off, buf_size - off,
"PBAR45SZ %hhu\n", u.v8);
} else {
pci_read_config_byte(pdev, XEON_PBAR4SZ_OFFSET, &u.v8);
off += scnprintf(buf + off, buf_size - off,
"PBAR4SZ %hhu\n", u.v8);
pci_read_config_byte(pdev, XEON_PBAR5SZ_OFFSET, &u.v8);
off += scnprintf(buf + off, buf_size - off,
"PBAR5SZ %hhu\n", u.v8);
}
pci_read_config_byte(pdev, XEON_SBAR23SZ_OFFSET, &u.v8);
off += scnprintf(buf + off, buf_size - off,
"SBAR23SZ %hhu\n", u.v8);
if (!ndev->bar4_split) {
pci_read_config_byte(pdev, XEON_SBAR45SZ_OFFSET, &u.v8);
off += scnprintf(buf + off, buf_size - off,
"SBAR45SZ %hhu\n", u.v8);
} else {
pci_read_config_byte(pdev, XEON_SBAR4SZ_OFFSET, &u.v8);
off += scnprintf(buf + off, buf_size - off,
"SBAR4SZ %hhu\n", u.v8);
pci_read_config_byte(pdev, XEON_SBAR5SZ_OFFSET, &u.v8);
off += scnprintf(buf + off, buf_size - off,
"SBAR5SZ %hhu\n", u.v8);
}
off += scnprintf(buf + off, buf_size - off,
"\nNTB Incoming XLAT:\n");
u.v64 = ioread64(mmio + bar2_off(ndev->xlat_reg->bar2_xlat, 2));
off += scnprintf(buf + off, buf_size - off,
"XLAT23 -\t\t%#018llx\n", u.v64);
if (ndev->bar4_split) {
u.v32 = ioread32(mmio + bar2_off(ndev->xlat_reg->bar2_xlat, 4));
off += scnprintf(buf + off, buf_size - off,
"XLAT4 -\t\t\t%#06x\n", u.v32);
u.v32 = ioread32(mmio + bar2_off(ndev->xlat_reg->bar2_xlat, 5));
off += scnprintf(buf + off, buf_size - off,
"XLAT5 -\t\t\t%#06x\n", u.v32);
} else {
u.v64 = ioread64(mmio + bar2_off(ndev->xlat_reg->bar2_xlat, 4));
off += scnprintf(buf + off, buf_size - off,
"XLAT45 -\t\t%#018llx\n", u.v64);
}
u.v64 = ioread64(mmio + bar2_off(ndev->xlat_reg->bar2_limit, 2));
off += scnprintf(buf + off, buf_size - off,
"LMT23 -\t\t\t%#018llx\n", u.v64);
if (ndev->bar4_split) {
u.v32 = ioread32(mmio + bar2_off(ndev->xlat_reg->bar2_limit, 4));
off += scnprintf(buf + off, buf_size - off,
"LMT4 -\t\t\t%#06x\n", u.v32);
u.v32 = ioread32(mmio + bar2_off(ndev->xlat_reg->bar2_limit, 5));
off += scnprintf(buf + off, buf_size - off,
"LMT5 -\t\t\t%#06x\n", u.v32);
} else {
u.v64 = ioread64(mmio + bar2_off(ndev->xlat_reg->bar2_limit, 4));
off += scnprintf(buf + off, buf_size - off,
"LMT45 -\t\t\t%#018llx\n", u.v64);
}
if (pdev_is_xeon(pdev)) {
if (ntb_topo_is_b2b(ndev->ntb.topo)) {
off += scnprintf(buf + off, buf_size - off,
"\nNTB Outgoing B2B XLAT:\n");
u.v64 = ioread64(mmio + XEON_PBAR23XLAT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"B2B XLAT23 -\t\t%#018llx\n", u.v64);
if (ndev->bar4_split) {
u.v32 = ioread32(mmio + XEON_PBAR4XLAT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"B2B XLAT4 -\t\t%#06x\n",
u.v32);
u.v32 = ioread32(mmio + XEON_PBAR5XLAT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"B2B XLAT5 -\t\t%#06x\n",
u.v32);
} else {
u.v64 = ioread64(mmio + XEON_PBAR45XLAT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"B2B XLAT45 -\t\t%#018llx\n",
u.v64);
}
u.v64 = ioread64(mmio + XEON_PBAR23LMT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"B2B LMT23 -\t\t%#018llx\n", u.v64);
if (ndev->bar4_split) {
u.v32 = ioread32(mmio + XEON_PBAR4LMT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"B2B LMT4 -\t\t%#06x\n",
u.v32);
u.v32 = ioread32(mmio + XEON_PBAR5LMT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"B2B LMT5 -\t\t%#06x\n",
u.v32);
} else {
u.v64 = ioread64(mmio + XEON_PBAR45LMT_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"B2B LMT45 -\t\t%#018llx\n",
u.v64);
}
off += scnprintf(buf + off, buf_size - off,
"\nNTB Secondary BAR:\n");
u.v64 = ioread64(mmio + XEON_SBAR0BASE_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"SBAR01 -\t\t%#018llx\n", u.v64);
u.v64 = ioread64(mmio + XEON_SBAR23BASE_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"SBAR23 -\t\t%#018llx\n", u.v64);
if (ndev->bar4_split) {
u.v32 = ioread32(mmio + XEON_SBAR4BASE_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"SBAR4 -\t\t\t%#06x\n", u.v32);
u.v32 = ioread32(mmio + XEON_SBAR5BASE_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"SBAR5 -\t\t\t%#06x\n", u.v32);
} else {
u.v64 = ioread64(mmio + XEON_SBAR45BASE_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"SBAR45 -\t\t%#018llx\n",
u.v64);
}
}
off += scnprintf(buf + off, buf_size - off,
"\nXEON NTB Statistics:\n");
u.v16 = ioread16(mmio + XEON_USMEMMISS_OFFSET);
off += scnprintf(buf + off, buf_size - off,
"Upstream Memory Miss -\t%u\n", u.v16);
off += scnprintf(buf + off, buf_size - off,
"\nXEON NTB Hardware Errors:\n");
if (!pci_read_config_word(pdev,
XEON_DEVSTS_OFFSET, &u.v16))
off += scnprintf(buf + off, buf_size - off,
"DEVSTS -\t\t%#06x\n", u.v16);
if (!pci_read_config_word(pdev,
XEON_LINK_STATUS_OFFSET, &u.v16))
off += scnprintf(buf + off, buf_size - off,
"LNKSTS -\t\t%#06x\n", u.v16);
if (!pci_read_config_dword(pdev,
XEON_UNCERRSTS_OFFSET, &u.v32))
off += scnprintf(buf + off, buf_size - off,
"UNCERRSTS -\t\t%#06x\n", u.v32);
if (!pci_read_config_dword(pdev,
XEON_CORERRSTS_OFFSET, &u.v32))
off += scnprintf(buf + off, buf_size - off,
"CORERRSTS -\t\t%#06x\n", u.v32);
}
ret = simple_read_from_buffer(ubuf, count, offp, buf, off);
kfree(buf);
return ret;
}
static ssize_t ndev_debugfs_read(struct file *filp, char __user *ubuf,
size_t count, loff_t *offp)
{
struct intel_ntb_dev *ndev = filp->private_data;
if (pdev_is_xeon(ndev->ntb.pdev) ||
pdev_is_atom(ndev->ntb.pdev))
return ndev_ntb_debugfs_read(filp, ubuf, count, offp);
else if (pdev_is_skx_xeon(ndev->ntb.pdev))
return ndev_ntb3_debugfs_read(filp, ubuf, count, offp);
return -ENXIO;
}
static void ndev_init_debugfs(struct intel_ntb_dev *ndev)
{
if (!debugfs_dir) {
ndev->debugfs_dir = NULL;
ndev->debugfs_info = NULL;
} else {
ndev->debugfs_dir =
debugfs_create_dir(ndev_name(ndev), debugfs_dir);
if (!ndev->debugfs_dir)
ndev->debugfs_info = NULL;
else
ndev->debugfs_info =
debugfs_create_file("info", S_IRUSR,
ndev->debugfs_dir, ndev,
&intel_ntb_debugfs_info);
}
}
static void ndev_deinit_debugfs(struct intel_ntb_dev *ndev)
{
debugfs_remove_recursive(ndev->debugfs_dir);
}
static int intel_ntb_mw_count(struct ntb_dev *ntb)
{
return ntb_ndev(ntb)->mw_count;
}
static int intel_ntb_mw_get_range(struct ntb_dev *ntb, int idx,
phys_addr_t *base,
resource_size_t *size,
resource_size_t *align,
resource_size_t *align_size)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
int bar;
if (idx >= ndev->b2b_idx && !ndev->b2b_off)
idx += 1;
bar = ndev_mw_to_bar(ndev, idx);
if (bar < 0)
return bar;
if (base)
*base = pci_resource_start(ndev->ntb.pdev, bar) +
(idx == ndev->b2b_idx ? ndev->b2b_off : 0);
if (size)
*size = pci_resource_len(ndev->ntb.pdev, bar) -
(idx == ndev->b2b_idx ? ndev->b2b_off : 0);
if (align)
*align = pci_resource_len(ndev->ntb.pdev, bar);
if (align_size)
*align_size = 1;
return 0;
}
static int intel_ntb_mw_set_trans(struct ntb_dev *ntb, int idx,
dma_addr_t addr, resource_size_t size)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
unsigned long base_reg, xlat_reg, limit_reg;
resource_size_t bar_size, mw_size;
void __iomem *mmio;
u64 base, limit, reg_val;
int bar;
if (idx >= ndev->b2b_idx && !ndev->b2b_off)
idx += 1;
bar = ndev_mw_to_bar(ndev, idx);
if (bar < 0)
return bar;
bar_size = pci_resource_len(ndev->ntb.pdev, bar);
if (idx == ndev->b2b_idx)
mw_size = bar_size - ndev->b2b_off;
else
mw_size = bar_size;
if (addr & (bar_size - 1))
return -EINVAL;
if (size > mw_size)
return -EINVAL;
mmio = ndev->self_mmio;
base_reg = bar0_off(ndev->xlat_reg->bar0_base, bar);
xlat_reg = bar2_off(ndev->xlat_reg->bar2_xlat, bar);
limit_reg = bar2_off(ndev->xlat_reg->bar2_limit, bar);
if (bar < 4 || !ndev->bar4_split) {
base = ioread64(mmio + base_reg) & NTB_BAR_MASK_64;
if (limit_reg && size != mw_size)
limit = base + size;
else
limit = 0;
iowrite64(addr, mmio + xlat_reg);
reg_val = ioread64(mmio + xlat_reg);
if (reg_val != addr) {
iowrite64(0, mmio + xlat_reg);
return -EIO;
}
iowrite64(limit, mmio + limit_reg);
reg_val = ioread64(mmio + limit_reg);
if (reg_val != limit) {
iowrite64(base, mmio + limit_reg);
iowrite64(0, mmio + xlat_reg);
return -EIO;
}
} else {
if (addr & (~0ull << 32))
return -EINVAL;
if ((addr + size) & (~0ull << 32))
return -EINVAL;
base = ioread32(mmio + base_reg) & NTB_BAR_MASK_32;
if (limit_reg && size != mw_size)
limit = base + size;
else
limit = 0;
iowrite32(addr, mmio + xlat_reg);
reg_val = ioread32(mmio + xlat_reg);
if (reg_val != addr) {
iowrite32(0, mmio + xlat_reg);
return -EIO;
}
iowrite32(limit, mmio + limit_reg);
reg_val = ioread32(mmio + limit_reg);
if (reg_val != limit) {
iowrite32(base, mmio + limit_reg);
iowrite32(0, mmio + xlat_reg);
return -EIO;
}
}
return 0;
}
static int intel_ntb_link_is_up(struct ntb_dev *ntb,
enum ntb_speed *speed,
enum ntb_width *width)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
if (ndev->reg->link_is_up(ndev)) {
if (speed)
*speed = NTB_LNK_STA_SPEED(ndev->lnk_sta);
if (width)
*width = NTB_LNK_STA_WIDTH(ndev->lnk_sta);
return 1;
} else {
if (speed)
*speed = NTB_SPEED_NONE;
if (width)
*width = NTB_WIDTH_NONE;
return 0;
}
}
static int intel_ntb_link_enable(struct ntb_dev *ntb,
enum ntb_speed max_speed,
enum ntb_width max_width)
{
struct intel_ntb_dev *ndev;
u32 ntb_ctl;
ndev = container_of(ntb, struct intel_ntb_dev, ntb);
if (ndev->ntb.topo == NTB_TOPO_SEC)
return -EINVAL;
dev_dbg(ndev_dev(ndev),
"Enabling link with max_speed %d max_width %d\n",
max_speed, max_width);
if (max_speed != NTB_SPEED_AUTO)
dev_dbg(ndev_dev(ndev), "ignoring max_speed %d\n", max_speed);
if (max_width != NTB_WIDTH_AUTO)
dev_dbg(ndev_dev(ndev), "ignoring max_width %d\n", max_width);
ntb_ctl = ioread32(ndev->self_mmio + ndev->reg->ntb_ctl);
ntb_ctl &= ~(NTB_CTL_DISABLE | NTB_CTL_CFG_LOCK);
ntb_ctl |= NTB_CTL_P2S_BAR2_SNOOP | NTB_CTL_S2P_BAR2_SNOOP;
ntb_ctl |= NTB_CTL_P2S_BAR4_SNOOP | NTB_CTL_S2P_BAR4_SNOOP;
if (ndev->bar4_split)
ntb_ctl |= NTB_CTL_P2S_BAR5_SNOOP | NTB_CTL_S2P_BAR5_SNOOP;
iowrite32(ntb_ctl, ndev->self_mmio + ndev->reg->ntb_ctl);
return 0;
}
static int intel_ntb_link_disable(struct ntb_dev *ntb)
{
struct intel_ntb_dev *ndev;
u32 ntb_cntl;
ndev = container_of(ntb, struct intel_ntb_dev, ntb);
if (ndev->ntb.topo == NTB_TOPO_SEC)
return -EINVAL;
dev_dbg(ndev_dev(ndev), "Disabling link\n");
ntb_cntl = ioread32(ndev->self_mmio + ndev->reg->ntb_ctl);
ntb_cntl &= ~(NTB_CTL_P2S_BAR2_SNOOP | NTB_CTL_S2P_BAR2_SNOOP);
ntb_cntl &= ~(NTB_CTL_P2S_BAR4_SNOOP | NTB_CTL_S2P_BAR4_SNOOP);
if (ndev->bar4_split)
ntb_cntl &= ~(NTB_CTL_P2S_BAR5_SNOOP | NTB_CTL_S2P_BAR5_SNOOP);
ntb_cntl |= NTB_CTL_DISABLE | NTB_CTL_CFG_LOCK;
iowrite32(ntb_cntl, ndev->self_mmio + ndev->reg->ntb_ctl);
return 0;
}
static int intel_ntb_db_is_unsafe(struct ntb_dev *ntb)
{
return ndev_ignore_unsafe(ntb_ndev(ntb), NTB_UNSAFE_DB);
}
static u64 intel_ntb_db_valid_mask(struct ntb_dev *ntb)
{
return ntb_ndev(ntb)->db_valid_mask;
}
static int intel_ntb_db_vector_count(struct ntb_dev *ntb)
{
struct intel_ntb_dev *ndev;
ndev = container_of(ntb, struct intel_ntb_dev, ntb);
return ndev->db_vec_count;
}
static u64 intel_ntb_db_vector_mask(struct ntb_dev *ntb, int db_vector)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
if (db_vector < 0 || db_vector > ndev->db_vec_count)
return 0;
return ndev->db_valid_mask & ndev_vec_mask(ndev, db_vector);
}
static u64 intel_ntb_db_read(struct ntb_dev *ntb)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_db_read(ndev,
ndev->self_mmio +
ndev->self_reg->db_bell);
}
static int intel_ntb_db_clear(struct ntb_dev *ntb, u64 db_bits)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_db_write(ndev, db_bits,
ndev->self_mmio +
ndev->self_reg->db_bell);
}
static int intel_ntb_db_set_mask(struct ntb_dev *ntb, u64 db_bits)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_db_set_mask(ndev, db_bits,
ndev->self_mmio +
ndev->self_reg->db_mask);
}
static int intel_ntb_db_clear_mask(struct ntb_dev *ntb, u64 db_bits)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_db_clear_mask(ndev, db_bits,
ndev->self_mmio +
ndev->self_reg->db_mask);
}
static int intel_ntb_peer_db_addr(struct ntb_dev *ntb,
phys_addr_t *db_addr,
resource_size_t *db_size)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_db_addr(ndev, db_addr, db_size, ndev->peer_addr,
ndev->peer_reg->db_bell);
}
static int intel_ntb_peer_db_set(struct ntb_dev *ntb, u64 db_bits)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_db_write(ndev, db_bits,
ndev->peer_mmio +
ndev->peer_reg->db_bell);
}
static int intel_ntb_spad_is_unsafe(struct ntb_dev *ntb)
{
return ndev_ignore_unsafe(ntb_ndev(ntb), NTB_UNSAFE_SPAD);
}
static int intel_ntb_spad_count(struct ntb_dev *ntb)
{
struct intel_ntb_dev *ndev;
ndev = container_of(ntb, struct intel_ntb_dev, ntb);
return ndev->spad_count;
}
static u32 intel_ntb_spad_read(struct ntb_dev *ntb, int idx)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_spad_read(ndev, idx,
ndev->self_mmio +
ndev->self_reg->spad);
}
static int intel_ntb_spad_write(struct ntb_dev *ntb,
int idx, u32 val)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_spad_write(ndev, idx, val,
ndev->self_mmio +
ndev->self_reg->spad);
}
static int intel_ntb_peer_spad_addr(struct ntb_dev *ntb, int idx,
phys_addr_t *spad_addr)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_spad_addr(ndev, idx, spad_addr, ndev->peer_addr,
ndev->peer_reg->spad);
}
static u32 intel_ntb_peer_spad_read(struct ntb_dev *ntb, int idx)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_spad_read(ndev, idx,
ndev->peer_mmio +
ndev->peer_reg->spad);
}
static int intel_ntb_peer_spad_write(struct ntb_dev *ntb,
int idx, u32 val)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_spad_write(ndev, idx, val,
ndev->peer_mmio +
ndev->peer_reg->spad);
}
static u64 atom_db_ioread(void __iomem *mmio)
{
return ioread64(mmio);
}
static void atom_db_iowrite(u64 bits, void __iomem *mmio)
{
iowrite64(bits, mmio);
}
static int atom_poll_link(struct intel_ntb_dev *ndev)
{
u32 ntb_ctl;
ntb_ctl = ioread32(ndev->self_mmio + ATOM_NTBCNTL_OFFSET);
if (ntb_ctl == ndev->ntb_ctl)
return 0;
ndev->ntb_ctl = ntb_ctl;
ndev->lnk_sta = ioread32(ndev->self_mmio + ATOM_LINK_STATUS_OFFSET);
return 1;
}
static int atom_link_is_up(struct intel_ntb_dev *ndev)
{
return ATOM_NTB_CTL_ACTIVE(ndev->ntb_ctl);
}
static int atom_link_is_err(struct intel_ntb_dev *ndev)
{
if (ioread32(ndev->self_mmio + ATOM_LTSSMSTATEJMP_OFFSET)
& ATOM_LTSSMSTATEJMP_FORCEDETECT)
return 1;
if (ioread32(ndev->self_mmio + ATOM_IBSTERRRCRVSTS0_OFFSET)
& ATOM_IBIST_ERR_OFLOW)
return 1;
return 0;
}
static inline enum ntb_topo atom_ppd_topo(struct intel_ntb_dev *ndev, u32 ppd)
{
switch (ppd & ATOM_PPD_TOPO_MASK) {
case ATOM_PPD_TOPO_B2B_USD:
dev_dbg(ndev_dev(ndev), "PPD %d B2B USD\n", ppd);
return NTB_TOPO_B2B_USD;
case ATOM_PPD_TOPO_B2B_DSD:
dev_dbg(ndev_dev(ndev), "PPD %d B2B DSD\n", ppd);
return NTB_TOPO_B2B_DSD;
case ATOM_PPD_TOPO_PRI_USD:
case ATOM_PPD_TOPO_PRI_DSD:
case ATOM_PPD_TOPO_SEC_USD:
case ATOM_PPD_TOPO_SEC_DSD:
dev_dbg(ndev_dev(ndev), "PPD %d non B2B disabled\n", ppd);
return NTB_TOPO_NONE;
}
dev_dbg(ndev_dev(ndev), "PPD %d invalid\n", ppd);
return NTB_TOPO_NONE;
}
static void atom_link_hb(struct work_struct *work)
{
struct intel_ntb_dev *ndev = hb_ndev(work);
unsigned long poll_ts;
void __iomem *mmio;
u32 status32;
poll_ts = ndev->last_ts + ATOM_LINK_HB_TIMEOUT;
if (time_after(poll_ts, jiffies) && atom_link_is_up(ndev)) {
schedule_delayed_work(&ndev->hb_timer, poll_ts - jiffies);
return;
}
if (atom_poll_link(ndev))
ntb_link_event(&ndev->ntb);
if (atom_link_is_up(ndev) || !atom_link_is_err(ndev)) {
schedule_delayed_work(&ndev->hb_timer, ATOM_LINK_HB_TIMEOUT);
return;
}
mmio = ndev->self_mmio;
iowrite8(0xe0, mmio + ATOM_MODPHY_PCSREG6);
iowrite8(0x40, mmio + ATOM_MODPHY_PCSREG4);
iowrite8(0x60, mmio + ATOM_MODPHY_PCSREG4);
iowrite8(0x60, mmio + ATOM_MODPHY_PCSREG6);
msleep(100);
status32 = ioread32(mmio + ATOM_ERRCORSTS_OFFSET);
dev_dbg(ndev_dev(ndev), "ERRCORSTS = %x\n", status32);
status32 &= PCI_ERR_COR_REP_ROLL;
iowrite32(status32, mmio + ATOM_ERRCORSTS_OFFSET);
status32 = ioread32(mmio + ATOM_LTSSMERRSTS0_OFFSET);
dev_dbg(ndev_dev(ndev), "LTSSMERRSTS0 = %x\n", status32);
status32 |= ATOM_LTSSMERRSTS0_UNEXPECTEDEI;
iowrite32(status32, mmio + ATOM_LTSSMERRSTS0_OFFSET);
status32 = ioread32(mmio + ATOM_DESKEWSTS_OFFSET);
dev_dbg(ndev_dev(ndev), "DESKEWSTS = %x\n", status32);
status32 |= ATOM_DESKEWSTS_DBERR;
iowrite32(status32, mmio + ATOM_DESKEWSTS_OFFSET);
status32 = ioread32(mmio + ATOM_IBSTERRRCRVSTS0_OFFSET);
dev_dbg(ndev_dev(ndev), "IBSTERRRCRVSTS0 = %x\n", status32);
status32 &= ATOM_IBIST_ERR_OFLOW;
iowrite32(status32, mmio + ATOM_IBSTERRRCRVSTS0_OFFSET);
status32 = ioread32(mmio + ATOM_LTSSMSTATEJMP_OFFSET);
dev_dbg(ndev_dev(ndev), "LTSSMSTATEJMP = %x\n", status32);
status32 &= ~ATOM_LTSSMSTATEJMP_FORCEDETECT;
iowrite32(status32, mmio + ATOM_LTSSMSTATEJMP_OFFSET);
schedule_delayed_work(&ndev->hb_timer, ATOM_LINK_RECOVERY_TIME
+ prandom_u32() % ATOM_LINK_RECOVERY_TIME);
}
static int atom_init_isr(struct intel_ntb_dev *ndev)
{
int rc;
rc = ndev_init_isr(ndev, 1, ATOM_DB_MSIX_VECTOR_COUNT,
ATOM_DB_MSIX_VECTOR_SHIFT, ATOM_DB_TOTAL_SHIFT);
if (rc)
return rc;
ndev->last_ts = jiffies;
INIT_DELAYED_WORK(&ndev->hb_timer, atom_link_hb);
schedule_delayed_work(&ndev->hb_timer, ATOM_LINK_HB_TIMEOUT);
return 0;
}
static void atom_deinit_isr(struct intel_ntb_dev *ndev)
{
cancel_delayed_work_sync(&ndev->hb_timer);
ndev_deinit_isr(ndev);
}
static int atom_init_ntb(struct intel_ntb_dev *ndev)
{
ndev->mw_count = ATOM_MW_COUNT;
ndev->spad_count = ATOM_SPAD_COUNT;
ndev->db_count = ATOM_DB_COUNT;
switch (ndev->ntb.topo) {
case NTB_TOPO_B2B_USD:
case NTB_TOPO_B2B_DSD:
ndev->self_reg = &atom_pri_reg;
ndev->peer_reg = &atom_b2b_reg;
ndev->xlat_reg = &atom_sec_xlat;
iowrite16(PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER,
ndev->self_mmio + ATOM_SPCICMD_OFFSET);
break;
default:
return -EINVAL;
}
ndev->db_valid_mask = BIT_ULL(ndev->db_count) - 1;
return 0;
}
static int atom_init_dev(struct intel_ntb_dev *ndev)
{
u32 ppd;
int rc;
rc = pci_read_config_dword(ndev->ntb.pdev, ATOM_PPD_OFFSET, &ppd);
if (rc)
return -EIO;
ndev->ntb.topo = atom_ppd_topo(ndev, ppd);
if (ndev->ntb.topo == NTB_TOPO_NONE)
return -EINVAL;
rc = atom_init_ntb(ndev);
if (rc)
return rc;
rc = atom_init_isr(ndev);
if (rc)
return rc;
if (ndev->ntb.topo != NTB_TOPO_SEC) {
rc = pci_write_config_dword(ndev->ntb.pdev, ATOM_PPD_OFFSET,
ppd | ATOM_PPD_INIT_LINK);
if (rc)
return rc;
}
return 0;
}
static void atom_deinit_dev(struct intel_ntb_dev *ndev)
{
atom_deinit_isr(ndev);
}
static int skx_poll_link(struct intel_ntb_dev *ndev)
{
u16 reg_val;
int rc;
ndev->reg->db_iowrite(ndev->db_link_mask,
ndev->self_mmio +
ndev->self_reg->db_clear);
rc = pci_read_config_word(ndev->ntb.pdev,
SKX_LINK_STATUS_OFFSET, &reg_val);
if (rc)
return 0;
if (reg_val == ndev->lnk_sta)
return 0;
ndev->lnk_sta = reg_val;
return 1;
}
static u64 skx_db_ioread(void __iomem *mmio)
{
return ioread64(mmio);
}
static void skx_db_iowrite(u64 bits, void __iomem *mmio)
{
iowrite64(bits, mmio);
}
static int skx_init_isr(struct intel_ntb_dev *ndev)
{
int i;
for (i = 0; i < SKX_DB_MSIX_VECTOR_COUNT; i++)
iowrite8(i, ndev->self_mmio + SKX_INTVEC_OFFSET + i);
if (ndev->hwerr_flags & NTB_HWERR_MSIX_VECTOR32_BAD) {
iowrite8(SKX_DB_MSIX_VECTOR_COUNT - 2,
ndev->self_mmio + SKX_INTVEC_OFFSET +
(SKX_DB_MSIX_VECTOR_COUNT - 1));
}
return ndev_init_isr(ndev, SKX_DB_MSIX_VECTOR_COUNT,
SKX_DB_MSIX_VECTOR_COUNT,
SKX_DB_MSIX_VECTOR_SHIFT,
SKX_DB_TOTAL_SHIFT);
}
static int skx_setup_b2b_mw(struct intel_ntb_dev *ndev,
const struct intel_b2b_addr *addr,
const struct intel_b2b_addr *peer_addr)
{
struct pci_dev *pdev;
void __iomem *mmio;
resource_size_t bar_size;
phys_addr_t bar_addr;
int b2b_bar;
u8 bar_sz;
pdev = ndev_pdev(ndev);
mmio = ndev->self_mmio;
if (ndev->b2b_idx == UINT_MAX) {
dev_dbg(ndev_dev(ndev), "not using b2b mw\n");
b2b_bar = 0;
ndev->b2b_off = 0;
} else {
b2b_bar = ndev_mw_to_bar(ndev, ndev->b2b_idx);
if (b2b_bar < 0)
return -EIO;
dev_dbg(ndev_dev(ndev), "using b2b mw bar %d\n", b2b_bar);
bar_size = pci_resource_len(ndev->ntb.pdev, b2b_bar);
dev_dbg(ndev_dev(ndev), "b2b bar size %#llx\n", bar_size);
if (b2b_mw_share && ((bar_size >> 1) >= XEON_B2B_MIN_SIZE)) {
dev_dbg(ndev_dev(ndev),
"b2b using first half of bar\n");
ndev->b2b_off = bar_size >> 1;
} else if (bar_size >= XEON_B2B_MIN_SIZE) {
dev_dbg(ndev_dev(ndev),
"b2b using whole bar\n");
ndev->b2b_off = 0;
--ndev->mw_count;
} else {
dev_dbg(ndev_dev(ndev),
"b2b bar size is too small\n");
return -EIO;
}
}
pci_read_config_byte(pdev, SKX_IMBAR1SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "IMBAR1SZ %#x\n", bar_sz);
if (b2b_bar == 1) {
if (ndev->b2b_off)
bar_sz -= 1;
else
bar_sz = 0;
}
pci_write_config_byte(pdev, SKX_EMBAR1SZ_OFFSET, bar_sz);
pci_read_config_byte(pdev, SKX_EMBAR1SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "EMBAR1SZ %#x\n", bar_sz);
pci_read_config_byte(pdev, SKX_IMBAR2SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "IMBAR2SZ %#x\n", bar_sz);
if (b2b_bar == 2) {
if (ndev->b2b_off)
bar_sz -= 1;
else
bar_sz = 0;
}
pci_write_config_byte(pdev, SKX_EMBAR2SZ_OFFSET, bar_sz);
pci_read_config_byte(pdev, SKX_EMBAR2SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "EMBAR2SZ %#x\n", bar_sz);
if (b2b_bar == 0)
bar_addr = addr->bar0_addr;
else if (b2b_bar == 1)
bar_addr = addr->bar2_addr64;
else if (b2b_bar == 2)
bar_addr = addr->bar4_addr64;
else
return -EIO;
bar_addr = addr->bar2_addr64 + (b2b_bar == 1 ? ndev->b2b_off : 0);
iowrite64(bar_addr, mmio + SKX_IMBAR1XLMT_OFFSET);
bar_addr = ioread64(mmio + SKX_IMBAR1XLMT_OFFSET);
dev_dbg(ndev_dev(ndev), "IMBAR1XLMT %#018llx\n", bar_addr);
bar_addr = addr->bar4_addr64 + (b2b_bar == 2 ? ndev->b2b_off : 0);
iowrite64(bar_addr, mmio + SKX_IMBAR2XLMT_OFFSET);
bar_addr = ioread64(mmio + SKX_IMBAR2XLMT_OFFSET);
dev_dbg(ndev_dev(ndev), "IMBAR2XLMT %#018llx\n", bar_addr);
iowrite64(0, mmio + SKX_IMBAR1XBASE_OFFSET);
iowrite64(0, mmio + SKX_IMBAR2XBASE_OFFSET);
ndev->peer_mmio = ndev->self_mmio;
return 0;
}
static int skx_init_ntb(struct intel_ntb_dev *ndev)
{
int rc;
ndev->mw_count = XEON_MW_COUNT;
ndev->spad_count = SKX_SPAD_COUNT;
ndev->db_count = SKX_DB_COUNT;
ndev->db_link_mask = SKX_DB_LINK_BIT;
if (ndev->hwerr_flags & NTB_HWERR_MSIX_VECTOR32_BAD)
ndev->db_link_mask |= BIT_ULL(31);
switch (ndev->ntb.topo) {
case NTB_TOPO_B2B_USD:
case NTB_TOPO_B2B_DSD:
ndev->self_reg = &skx_pri_reg;
ndev->peer_reg = &skx_b2b_reg;
ndev->xlat_reg = &skx_sec_xlat;
if (ndev->ntb.topo == NTB_TOPO_B2B_USD) {
rc = skx_setup_b2b_mw(ndev,
&xeon_b2b_dsd_addr,
&xeon_b2b_usd_addr);
} else {
rc = skx_setup_b2b_mw(ndev,
&xeon_b2b_usd_addr,
&xeon_b2b_dsd_addr);
}
if (rc)
return rc;
iowrite16(PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER,
ndev->self_mmio + SKX_SPCICMD_OFFSET);
break;
default:
return -EINVAL;
}
ndev->db_valid_mask = BIT_ULL(ndev->db_count) - 1;
ndev->reg->db_iowrite(ndev->db_valid_mask,
ndev->self_mmio +
ndev->self_reg->db_mask);
return 0;
}
static int skx_init_dev(struct intel_ntb_dev *ndev)
{
struct pci_dev *pdev;
u8 ppd;
int rc;
pdev = ndev_pdev(ndev);
ndev->reg = &skx_reg;
rc = pci_read_config_byte(pdev, XEON_PPD_OFFSET, &ppd);
if (rc)
return -EIO;
ndev->ntb.topo = xeon_ppd_topo(ndev, ppd);
dev_dbg(ndev_dev(ndev), "ppd %#x topo %s\n", ppd,
ntb_topo_string(ndev->ntb.topo));
if (ndev->ntb.topo == NTB_TOPO_NONE)
return -EINVAL;
if (pdev_is_skx_xeon(pdev))
ndev->hwerr_flags |= NTB_HWERR_MSIX_VECTOR32_BAD;
rc = skx_init_ntb(ndev);
if (rc)
return rc;
return skx_init_isr(ndev);
}
static int intel_ntb3_link_enable(struct ntb_dev *ntb,
enum ntb_speed max_speed,
enum ntb_width max_width)
{
struct intel_ntb_dev *ndev;
u32 ntb_ctl;
ndev = container_of(ntb, struct intel_ntb_dev, ntb);
dev_dbg(ndev_dev(ndev),
"Enabling link with max_speed %d max_width %d\n",
max_speed, max_width);
if (max_speed != NTB_SPEED_AUTO)
dev_dbg(ndev_dev(ndev), "ignoring max_speed %d\n", max_speed);
if (max_width != NTB_WIDTH_AUTO)
dev_dbg(ndev_dev(ndev), "ignoring max_width %d\n", max_width);
ntb_ctl = ioread32(ndev->self_mmio + ndev->reg->ntb_ctl);
ntb_ctl &= ~(NTB_CTL_DISABLE | NTB_CTL_CFG_LOCK);
ntb_ctl |= NTB_CTL_P2S_BAR2_SNOOP | NTB_CTL_S2P_BAR2_SNOOP;
ntb_ctl |= NTB_CTL_P2S_BAR4_SNOOP | NTB_CTL_S2P_BAR4_SNOOP;
iowrite32(ntb_ctl, ndev->self_mmio + ndev->reg->ntb_ctl);
return 0;
}
static int intel_ntb3_mw_set_trans(struct ntb_dev *ntb, int idx,
dma_addr_t addr, resource_size_t size)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
unsigned long xlat_reg, limit_reg;
resource_size_t bar_size, mw_size;
void __iomem *mmio;
u64 base, limit, reg_val;
int bar;
if (idx >= ndev->b2b_idx && !ndev->b2b_off)
idx += 1;
bar = ndev_mw_to_bar(ndev, idx);
if (bar < 0)
return bar;
bar_size = pci_resource_len(ndev->ntb.pdev, bar);
if (idx == ndev->b2b_idx)
mw_size = bar_size - ndev->b2b_off;
else
mw_size = bar_size;
if (addr & (bar_size - 1))
return -EINVAL;
if (size > mw_size)
return -EINVAL;
mmio = ndev->self_mmio;
xlat_reg = ndev->xlat_reg->bar2_xlat + (idx * 0x10);
limit_reg = ndev->xlat_reg->bar2_limit + (idx * 0x10);
base = pci_resource_start(ndev->ntb.pdev, bar);
if (limit_reg && size != mw_size)
limit = base + size;
else
limit = base + mw_size;
iowrite64(addr, mmio + xlat_reg);
reg_val = ioread64(mmio + xlat_reg);
if (reg_val != addr) {
iowrite64(0, mmio + xlat_reg);
return -EIO;
}
dev_dbg(ndev_dev(ndev), "BAR %d IMBARXBASE: %#Lx\n", bar, reg_val);
iowrite64(limit, mmio + limit_reg);
reg_val = ioread64(mmio + limit_reg);
if (reg_val != limit) {
iowrite64(base, mmio + limit_reg);
iowrite64(0, mmio + xlat_reg);
return -EIO;
}
dev_dbg(ndev_dev(ndev), "BAR %d IMBARXLMT: %#Lx\n", bar, reg_val);
limit_reg = ndev->xlat_reg->bar2_limit + (idx * 0x10) + 0x4000;
base = ioread64(mmio + SKX_EMBAR1_OFFSET + (8 * idx));
base &= ~0xf;
if (limit_reg && size != mw_size)
limit = base + size;
else
limit = base + mw_size;
iowrite64(limit, mmio + limit_reg);
reg_val = ioread64(mmio + limit_reg);
if (reg_val != limit) {
iowrite64(base, mmio + limit_reg);
iowrite64(0, mmio + xlat_reg);
return -EIO;
}
dev_dbg(ndev_dev(ndev), "BAR %d EMBARXLMT: %#Lx\n", bar, reg_val);
return 0;
}
static int intel_ntb3_peer_db_set(struct ntb_dev *ntb, u64 db_bits)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
int bit;
if (db_bits & ~ndev->db_valid_mask)
return -EINVAL;
while (db_bits) {
bit = __ffs(db_bits);
iowrite32(1, ndev->peer_mmio +
ndev->peer_reg->db_bell + (bit * 4));
db_bits &= db_bits - 1;
}
return 0;
}
static u64 intel_ntb3_db_read(struct ntb_dev *ntb)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_db_read(ndev,
ndev->self_mmio +
ndev->self_reg->db_clear);
}
static int intel_ntb3_db_clear(struct ntb_dev *ntb, u64 db_bits)
{
struct intel_ntb_dev *ndev = ntb_ndev(ntb);
return ndev_db_write(ndev, db_bits,
ndev->self_mmio +
ndev->self_reg->db_clear);
}
static u64 xeon_db_ioread(void __iomem *mmio)
{
return (u64)ioread16(mmio);
}
static void xeon_db_iowrite(u64 bits, void __iomem *mmio)
{
iowrite16((u16)bits, mmio);
}
static int xeon_poll_link(struct intel_ntb_dev *ndev)
{
u16 reg_val;
int rc;
ndev->reg->db_iowrite(ndev->db_link_mask,
ndev->self_mmio +
ndev->self_reg->db_bell);
rc = pci_read_config_word(ndev->ntb.pdev,
XEON_LINK_STATUS_OFFSET, &reg_val);
if (rc)
return 0;
if (reg_val == ndev->lnk_sta)
return 0;
ndev->lnk_sta = reg_val;
return 1;
}
static int xeon_link_is_up(struct intel_ntb_dev *ndev)
{
if (ndev->ntb.topo == NTB_TOPO_SEC)
return 1;
return NTB_LNK_STA_ACTIVE(ndev->lnk_sta);
}
static inline enum ntb_topo xeon_ppd_topo(struct intel_ntb_dev *ndev, u8 ppd)
{
switch (ppd & XEON_PPD_TOPO_MASK) {
case XEON_PPD_TOPO_B2B_USD:
return NTB_TOPO_B2B_USD;
case XEON_PPD_TOPO_B2B_DSD:
return NTB_TOPO_B2B_DSD;
case XEON_PPD_TOPO_PRI_USD:
case XEON_PPD_TOPO_PRI_DSD:
return NTB_TOPO_PRI;
case XEON_PPD_TOPO_SEC_USD:
case XEON_PPD_TOPO_SEC_DSD:
return NTB_TOPO_SEC;
}
return NTB_TOPO_NONE;
}
static inline int xeon_ppd_bar4_split(struct intel_ntb_dev *ndev, u8 ppd)
{
if (ppd & XEON_PPD_SPLIT_BAR_MASK) {
dev_dbg(ndev_dev(ndev), "PPD %d split bar\n", ppd);
return 1;
}
return 0;
}
static int xeon_init_isr(struct intel_ntb_dev *ndev)
{
return ndev_init_isr(ndev, XEON_DB_MSIX_VECTOR_COUNT,
XEON_DB_MSIX_VECTOR_COUNT,
XEON_DB_MSIX_VECTOR_SHIFT,
XEON_DB_TOTAL_SHIFT);
}
static void xeon_deinit_isr(struct intel_ntb_dev *ndev)
{
ndev_deinit_isr(ndev);
}
static int xeon_setup_b2b_mw(struct intel_ntb_dev *ndev,
const struct intel_b2b_addr *addr,
const struct intel_b2b_addr *peer_addr)
{
struct pci_dev *pdev;
void __iomem *mmio;
resource_size_t bar_size;
phys_addr_t bar_addr;
int b2b_bar;
u8 bar_sz;
pdev = ndev_pdev(ndev);
mmio = ndev->self_mmio;
if (ndev->b2b_idx == UINT_MAX) {
dev_dbg(ndev_dev(ndev), "not using b2b mw\n");
b2b_bar = 0;
ndev->b2b_off = 0;
} else {
b2b_bar = ndev_mw_to_bar(ndev, ndev->b2b_idx);
if (b2b_bar < 0)
return -EIO;
dev_dbg(ndev_dev(ndev), "using b2b mw bar %d\n", b2b_bar);
bar_size = pci_resource_len(ndev->ntb.pdev, b2b_bar);
dev_dbg(ndev_dev(ndev), "b2b bar size %#llx\n", bar_size);
if (b2b_mw_share && XEON_B2B_MIN_SIZE <= bar_size >> 1) {
dev_dbg(ndev_dev(ndev),
"b2b using first half of bar\n");
ndev->b2b_off = bar_size >> 1;
} else if (XEON_B2B_MIN_SIZE <= bar_size) {
dev_dbg(ndev_dev(ndev),
"b2b using whole bar\n");
ndev->b2b_off = 0;
--ndev->mw_count;
} else {
dev_dbg(ndev_dev(ndev),
"b2b bar size is too small\n");
return -EIO;
}
}
pci_read_config_byte(pdev, XEON_PBAR23SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "PBAR23SZ %#x\n", bar_sz);
if (b2b_bar == 2) {
if (ndev->b2b_off)
bar_sz -= 1;
else
bar_sz = 0;
}
pci_write_config_byte(pdev, XEON_SBAR23SZ_OFFSET, bar_sz);
pci_read_config_byte(pdev, XEON_SBAR23SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "SBAR23SZ %#x\n", bar_sz);
if (!ndev->bar4_split) {
pci_read_config_byte(pdev, XEON_PBAR45SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "PBAR45SZ %#x\n", bar_sz);
if (b2b_bar == 4) {
if (ndev->b2b_off)
bar_sz -= 1;
else
bar_sz = 0;
}
pci_write_config_byte(pdev, XEON_SBAR45SZ_OFFSET, bar_sz);
pci_read_config_byte(pdev, XEON_SBAR45SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "SBAR45SZ %#x\n", bar_sz);
} else {
pci_read_config_byte(pdev, XEON_PBAR4SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "PBAR4SZ %#x\n", bar_sz);
if (b2b_bar == 4) {
if (ndev->b2b_off)
bar_sz -= 1;
else
bar_sz = 0;
}
pci_write_config_byte(pdev, XEON_SBAR4SZ_OFFSET, bar_sz);
pci_read_config_byte(pdev, XEON_SBAR4SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "SBAR4SZ %#x\n", bar_sz);
pci_read_config_byte(pdev, XEON_PBAR5SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "PBAR5SZ %#x\n", bar_sz);
if (b2b_bar == 5) {
if (ndev->b2b_off)
bar_sz -= 1;
else
bar_sz = 0;
}
pci_write_config_byte(pdev, XEON_SBAR5SZ_OFFSET, bar_sz);
pci_read_config_byte(pdev, XEON_SBAR5SZ_OFFSET, &bar_sz);
dev_dbg(ndev_dev(ndev), "SBAR5SZ %#x\n", bar_sz);
}
if (b2b_bar == 0)
bar_addr = addr->bar0_addr;
else if (b2b_bar == 2)
bar_addr = addr->bar2_addr64;
else if (b2b_bar == 4 && !ndev->bar4_split)
bar_addr = addr->bar4_addr64;
else if (b2b_bar == 4)
bar_addr = addr->bar4_addr32;
else if (b2b_bar == 5)
bar_addr = addr->bar5_addr32;
else
return -EIO;
dev_dbg(ndev_dev(ndev), "SBAR01 %#018llx\n", bar_addr);
iowrite64(bar_addr, mmio + XEON_SBAR0BASE_OFFSET);
bar_addr = addr->bar2_addr64 + (b2b_bar == 2 ? ndev->b2b_off : 0);
iowrite64(bar_addr, mmio + XEON_SBAR23BASE_OFFSET);
bar_addr = ioread64(mmio + XEON_SBAR23BASE_OFFSET);
dev_dbg(ndev_dev(ndev), "SBAR23 %#018llx\n", bar_addr);
if (!ndev->bar4_split) {
bar_addr = addr->bar4_addr64 +
(b2b_bar == 4 ? ndev->b2b_off : 0);
iowrite64(bar_addr, mmio + XEON_SBAR45BASE_OFFSET);
bar_addr = ioread64(mmio + XEON_SBAR45BASE_OFFSET);
dev_dbg(ndev_dev(ndev), "SBAR45 %#018llx\n", bar_addr);
} else {
bar_addr = addr->bar4_addr32 +
(b2b_bar == 4 ? ndev->b2b_off : 0);
iowrite32(bar_addr, mmio + XEON_SBAR4BASE_OFFSET);
bar_addr = ioread32(mmio + XEON_SBAR4BASE_OFFSET);
dev_dbg(ndev_dev(ndev), "SBAR4 %#010llx\n", bar_addr);
bar_addr = addr->bar5_addr32 +
(b2b_bar == 5 ? ndev->b2b_off : 0);
iowrite32(bar_addr, mmio + XEON_SBAR5BASE_OFFSET);
bar_addr = ioread32(mmio + XEON_SBAR5BASE_OFFSET);
dev_dbg(ndev_dev(ndev), "SBAR5 %#010llx\n", bar_addr);
}
bar_addr = addr->bar2_addr64 + (b2b_bar == 2 ? ndev->b2b_off : 0);
iowrite64(bar_addr, mmio + XEON_SBAR23LMT_OFFSET);
bar_addr = ioread64(mmio + XEON_SBAR23LMT_OFFSET);
dev_dbg(ndev_dev(ndev), "SBAR23LMT %#018llx\n", bar_addr);
if (!ndev->bar4_split) {
bar_addr = addr->bar4_addr64 +
(b2b_bar == 4 ? ndev->b2b_off : 0);
iowrite64(bar_addr, mmio + XEON_SBAR45LMT_OFFSET);
bar_addr = ioread64(mmio + XEON_SBAR45LMT_OFFSET);
dev_dbg(ndev_dev(ndev), "SBAR45LMT %#018llx\n", bar_addr);
} else {
bar_addr = addr->bar4_addr32 +
(b2b_bar == 4 ? ndev->b2b_off : 0);
iowrite32(bar_addr, mmio + XEON_SBAR4LMT_OFFSET);
bar_addr = ioread32(mmio + XEON_SBAR4LMT_OFFSET);
dev_dbg(ndev_dev(ndev), "SBAR4LMT %#010llx\n", bar_addr);
bar_addr = addr->bar5_addr32 +
(b2b_bar == 5 ? ndev->b2b_off : 0);
iowrite32(bar_addr, mmio + XEON_SBAR5LMT_OFFSET);
bar_addr = ioread32(mmio + XEON_SBAR5LMT_OFFSET);
dev_dbg(ndev_dev(ndev), "SBAR5LMT %#05llx\n", bar_addr);
}
iowrite64(0, mmio + XEON_SBAR23XLAT_OFFSET);
if (!ndev->bar4_split) {
iowrite64(0, mmio + XEON_SBAR45XLAT_OFFSET);
} else {
iowrite32(0, mmio + XEON_SBAR4XLAT_OFFSET);
iowrite32(0, mmio + XEON_SBAR5XLAT_OFFSET);
}
iowrite64(0, mmio + XEON_PBAR23LMT_OFFSET);
if (!ndev->bar4_split) {
iowrite64(0, mmio + XEON_PBAR45LMT_OFFSET);
} else {
iowrite32(0, mmio + XEON_PBAR4LMT_OFFSET);
iowrite32(0, mmio + XEON_PBAR5LMT_OFFSET);
}
bar_addr = peer_addr->bar2_addr64;
iowrite64(bar_addr, mmio + XEON_PBAR23XLAT_OFFSET);
bar_addr = ioread64(mmio + XEON_PBAR23XLAT_OFFSET);
dev_dbg(ndev_dev(ndev), "PBAR23XLAT %#018llx\n", bar_addr);
if (!ndev->bar4_split) {
bar_addr = peer_addr->bar4_addr64;
iowrite64(bar_addr, mmio + XEON_PBAR45XLAT_OFFSET);
bar_addr = ioread64(mmio + XEON_PBAR45XLAT_OFFSET);
dev_dbg(ndev_dev(ndev), "PBAR45XLAT %#018llx\n", bar_addr);
} else {
bar_addr = peer_addr->bar4_addr32;
iowrite32(bar_addr, mmio + XEON_PBAR4XLAT_OFFSET);
bar_addr = ioread32(mmio + XEON_PBAR4XLAT_OFFSET);
dev_dbg(ndev_dev(ndev), "PBAR4XLAT %#010llx\n", bar_addr);
bar_addr = peer_addr->bar5_addr32;
iowrite32(bar_addr, mmio + XEON_PBAR5XLAT_OFFSET);
bar_addr = ioread32(mmio + XEON_PBAR5XLAT_OFFSET);
dev_dbg(ndev_dev(ndev), "PBAR5XLAT %#010llx\n", bar_addr);
}
if (b2b_bar == 0)
bar_addr = peer_addr->bar0_addr;
else if (b2b_bar == 2)
bar_addr = peer_addr->bar2_addr64;
else if (b2b_bar == 4 && !ndev->bar4_split)
bar_addr = peer_addr->bar4_addr64;
else if (b2b_bar == 4)
bar_addr = peer_addr->bar4_addr32;
else if (b2b_bar == 5)
bar_addr = peer_addr->bar5_addr32;
else
return -EIO;
dev_dbg(ndev_dev(ndev), "B2BXLAT %#018llx\n", bar_addr);
iowrite32(bar_addr, mmio + XEON_B2B_XLAT_OFFSETL);
iowrite32(bar_addr >> 32, mmio + XEON_B2B_XLAT_OFFSETU);
if (b2b_bar) {
ndev->peer_mmio = pci_iomap(pdev, b2b_bar,
XEON_B2B_MIN_SIZE);
if (!ndev->peer_mmio)
return -EIO;
ndev->peer_addr = pci_resource_start(pdev, b2b_bar);
}
return 0;
}
static int xeon_init_ntb(struct intel_ntb_dev *ndev)
{
int rc;
u32 ntb_ctl;
if (ndev->bar4_split)
ndev->mw_count = HSX_SPLIT_BAR_MW_COUNT;
else
ndev->mw_count = XEON_MW_COUNT;
ndev->spad_count = XEON_SPAD_COUNT;
ndev->db_count = XEON_DB_COUNT;
ndev->db_link_mask = XEON_DB_LINK_BIT;
switch (ndev->ntb.topo) {
case NTB_TOPO_PRI:
if (ndev->hwerr_flags & NTB_HWERR_SDOORBELL_LOCKUP) {
dev_err(ndev_dev(ndev), "NTB Primary config disabled\n");
return -EINVAL;
}
ntb_ctl = ioread32(ndev->self_mmio + ndev->reg->ntb_ctl);
ntb_ctl &= ~NTB_CTL_DISABLE;
iowrite32(ntb_ctl, ndev->self_mmio + ndev->reg->ntb_ctl);
ndev->spad_count >>= 1;
ndev->self_reg = &xeon_pri_reg;
ndev->peer_reg = &xeon_sec_reg;
ndev->xlat_reg = &xeon_sec_xlat;
break;
case NTB_TOPO_SEC:
if (ndev->hwerr_flags & NTB_HWERR_SDOORBELL_LOCKUP) {
dev_err(ndev_dev(ndev), "NTB Secondary config disabled\n");
return -EINVAL;
}
ndev->spad_count >>= 1;
ndev->self_reg = &xeon_sec_reg;
ndev->peer_reg = &xeon_pri_reg;
ndev->xlat_reg = &xeon_pri_xlat;
break;
case NTB_TOPO_B2B_USD:
case NTB_TOPO_B2B_DSD:
ndev->self_reg = &xeon_pri_reg;
ndev->peer_reg = &xeon_b2b_reg;
ndev->xlat_reg = &xeon_sec_xlat;
if (ndev->hwerr_flags & NTB_HWERR_SDOORBELL_LOCKUP) {
ndev->peer_reg = &xeon_pri_reg;
if (b2b_mw_idx < 0)
ndev->b2b_idx = b2b_mw_idx + ndev->mw_count;
else
ndev->b2b_idx = b2b_mw_idx;
if (ndev->b2b_idx >= ndev->mw_count) {
dev_dbg(ndev_dev(ndev),
"b2b_mw_idx %d invalid for mw_count %u\n",
b2b_mw_idx, ndev->mw_count);
return -EINVAL;
}
dev_dbg(ndev_dev(ndev),
"setting up b2b mw idx %d means %d\n",
b2b_mw_idx, ndev->b2b_idx);
} else if (ndev->hwerr_flags & NTB_HWERR_B2BDOORBELL_BIT14) {
dev_warn(ndev_dev(ndev), "Reduce doorbell count by 1\n");
ndev->db_count -= 1;
}
if (ndev->ntb.topo == NTB_TOPO_B2B_USD) {
rc = xeon_setup_b2b_mw(ndev,
&xeon_b2b_dsd_addr,
&xeon_b2b_usd_addr);
} else {
rc = xeon_setup_b2b_mw(ndev,
&xeon_b2b_usd_addr,
&xeon_b2b_dsd_addr);
}
if (rc)
return rc;
iowrite16(PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER,
ndev->self_mmio + XEON_SPCICMD_OFFSET);
break;
default:
return -EINVAL;
}
ndev->db_valid_mask = BIT_ULL(ndev->db_count) - 1;
ndev->reg->db_iowrite(ndev->db_valid_mask,
ndev->self_mmio +
ndev->self_reg->db_mask);
return 0;
}
static int xeon_init_dev(struct intel_ntb_dev *ndev)
{
struct pci_dev *pdev;
u8 ppd;
int rc, mem;
pdev = ndev_pdev(ndev);
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_NTB_SS_JSF:
case PCI_DEVICE_ID_INTEL_NTB_PS_JSF:
case PCI_DEVICE_ID_INTEL_NTB_B2B_JSF:
case PCI_DEVICE_ID_INTEL_NTB_SS_SNB:
case PCI_DEVICE_ID_INTEL_NTB_PS_SNB:
case PCI_DEVICE_ID_INTEL_NTB_B2B_SNB:
case PCI_DEVICE_ID_INTEL_NTB_SS_IVT:
case PCI_DEVICE_ID_INTEL_NTB_PS_IVT:
case PCI_DEVICE_ID_INTEL_NTB_B2B_IVT:
case PCI_DEVICE_ID_INTEL_NTB_SS_HSX:
case PCI_DEVICE_ID_INTEL_NTB_PS_HSX:
case PCI_DEVICE_ID_INTEL_NTB_B2B_HSX:
case PCI_DEVICE_ID_INTEL_NTB_SS_BDX:
case PCI_DEVICE_ID_INTEL_NTB_PS_BDX:
case PCI_DEVICE_ID_INTEL_NTB_B2B_BDX:
ndev->hwerr_flags |= NTB_HWERR_SDOORBELL_LOCKUP;
break;
}
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_NTB_SS_IVT:
case PCI_DEVICE_ID_INTEL_NTB_PS_IVT:
case PCI_DEVICE_ID_INTEL_NTB_B2B_IVT:
case PCI_DEVICE_ID_INTEL_NTB_SS_HSX:
case PCI_DEVICE_ID_INTEL_NTB_PS_HSX:
case PCI_DEVICE_ID_INTEL_NTB_B2B_HSX:
case PCI_DEVICE_ID_INTEL_NTB_SS_BDX:
case PCI_DEVICE_ID_INTEL_NTB_PS_BDX:
case PCI_DEVICE_ID_INTEL_NTB_B2B_BDX:
ndev->hwerr_flags |= NTB_HWERR_SB01BASE_LOCKUP;
break;
}
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_NTB_SS_JSF:
case PCI_DEVICE_ID_INTEL_NTB_PS_JSF:
case PCI_DEVICE_ID_INTEL_NTB_B2B_JSF:
case PCI_DEVICE_ID_INTEL_NTB_SS_SNB:
case PCI_DEVICE_ID_INTEL_NTB_PS_SNB:
case PCI_DEVICE_ID_INTEL_NTB_B2B_SNB:
case PCI_DEVICE_ID_INTEL_NTB_SS_IVT:
case PCI_DEVICE_ID_INTEL_NTB_PS_IVT:
case PCI_DEVICE_ID_INTEL_NTB_B2B_IVT:
case PCI_DEVICE_ID_INTEL_NTB_SS_HSX:
case PCI_DEVICE_ID_INTEL_NTB_PS_HSX:
case PCI_DEVICE_ID_INTEL_NTB_B2B_HSX:
case PCI_DEVICE_ID_INTEL_NTB_SS_BDX:
case PCI_DEVICE_ID_INTEL_NTB_PS_BDX:
case PCI_DEVICE_ID_INTEL_NTB_B2B_BDX:
ndev->hwerr_flags |= NTB_HWERR_B2BDOORBELL_BIT14;
break;
}
ndev->reg = &xeon_reg;
rc = pci_read_config_byte(pdev, XEON_PPD_OFFSET, &ppd);
if (rc)
return -EIO;
ndev->ntb.topo = xeon_ppd_topo(ndev, ppd);
dev_dbg(ndev_dev(ndev), "ppd %#x topo %s\n", ppd,
ntb_topo_string(ndev->ntb.topo));
if (ndev->ntb.topo == NTB_TOPO_NONE)
return -EINVAL;
if (ndev->ntb.topo != NTB_TOPO_SEC) {
ndev->bar4_split = xeon_ppd_bar4_split(ndev, ppd);
dev_dbg(ndev_dev(ndev), "ppd %#x bar4_split %d\n",
ppd, ndev->bar4_split);
} else {
mem = pci_select_bars(pdev, IORESOURCE_MEM);
ndev->bar4_split = hweight32(mem) ==
HSX_SPLIT_BAR_MW_COUNT + 1;
dev_dbg(ndev_dev(ndev), "mem %#x bar4_split %d\n",
mem, ndev->bar4_split);
}
rc = xeon_init_ntb(ndev);
if (rc)
return rc;
return xeon_init_isr(ndev);
}
static void xeon_deinit_dev(struct intel_ntb_dev *ndev)
{
xeon_deinit_isr(ndev);
}
static int intel_ntb_init_pci(struct intel_ntb_dev *ndev, struct pci_dev *pdev)
{
int rc;
pci_set_drvdata(pdev, ndev);
rc = pci_enable_device(pdev);
if (rc)
goto err_pci_enable;
rc = pci_request_regions(pdev, NTB_NAME);
if (rc)
goto err_pci_regions;
pci_set_master(pdev);
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
if (rc) {
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc)
goto err_dma_mask;
dev_warn(ndev_dev(ndev), "Cannot DMA highmem\n");
}
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (rc) {
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc)
goto err_dma_mask;
dev_warn(ndev_dev(ndev), "Cannot DMA consistent highmem\n");
}
ndev->self_mmio = pci_iomap(pdev, 0, 0);
if (!ndev->self_mmio) {
rc = -EIO;
goto err_mmio;
}
ndev->peer_mmio = ndev->self_mmio;
ndev->peer_addr = pci_resource_start(pdev, 0);
return 0;
err_mmio:
err_dma_mask:
pci_clear_master(pdev);
pci_release_regions(pdev);
err_pci_regions:
pci_disable_device(pdev);
err_pci_enable:
pci_set_drvdata(pdev, NULL);
return rc;
}
static void intel_ntb_deinit_pci(struct intel_ntb_dev *ndev)
{
struct pci_dev *pdev = ndev_pdev(ndev);
if (ndev->peer_mmio && ndev->peer_mmio != ndev->self_mmio)
pci_iounmap(pdev, ndev->peer_mmio);
pci_iounmap(pdev, ndev->self_mmio);
pci_clear_master(pdev);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static inline void ndev_init_struct(struct intel_ntb_dev *ndev,
struct pci_dev *pdev)
{
ndev->ntb.pdev = pdev;
ndev->ntb.topo = NTB_TOPO_NONE;
ndev->ntb.ops = &intel_ntb_ops;
ndev->b2b_off = 0;
ndev->b2b_idx = UINT_MAX;
ndev->bar4_split = 0;
ndev->mw_count = 0;
ndev->spad_count = 0;
ndev->db_count = 0;
ndev->db_vec_count = 0;
ndev->db_vec_shift = 0;
ndev->ntb_ctl = 0;
ndev->lnk_sta = 0;
ndev->db_valid_mask = 0;
ndev->db_link_mask = 0;
ndev->db_mask = 0;
spin_lock_init(&ndev->db_mask_lock);
}
static int intel_ntb_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct intel_ntb_dev *ndev;
int rc, node;
node = dev_to_node(&pdev->dev);
if (pdev_is_atom(pdev)) {
ndev = kzalloc_node(sizeof(*ndev), GFP_KERNEL, node);
if (!ndev) {
rc = -ENOMEM;
goto err_ndev;
}
ndev_init_struct(ndev, pdev);
rc = intel_ntb_init_pci(ndev, pdev);
if (rc)
goto err_init_pci;
rc = atom_init_dev(ndev);
if (rc)
goto err_init_dev;
} else if (pdev_is_xeon(pdev)) {
ndev = kzalloc_node(sizeof(*ndev), GFP_KERNEL, node);
if (!ndev) {
rc = -ENOMEM;
goto err_ndev;
}
ndev_init_struct(ndev, pdev);
rc = intel_ntb_init_pci(ndev, pdev);
if (rc)
goto err_init_pci;
rc = xeon_init_dev(ndev);
if (rc)
goto err_init_dev;
} else if (pdev_is_skx_xeon(pdev)) {
ndev = kzalloc_node(sizeof(*ndev), GFP_KERNEL, node);
if (!ndev) {
rc = -ENOMEM;
goto err_ndev;
}
ndev_init_struct(ndev, pdev);
ndev->ntb.ops = &intel_ntb3_ops;
rc = intel_ntb_init_pci(ndev, pdev);
if (rc)
goto err_init_pci;
rc = skx_init_dev(ndev);
if (rc)
goto err_init_dev;
} else {
rc = -EINVAL;
goto err_ndev;
}
ndev_reset_unsafe_flags(ndev);
ndev->reg->poll_link(ndev);
ndev_init_debugfs(ndev);
rc = ntb_register_device(&ndev->ntb);
if (rc)
goto err_register;
dev_info(&pdev->dev, "NTB device registered.\n");
return 0;
err_register:
ndev_deinit_debugfs(ndev);
if (pdev_is_atom(pdev))
atom_deinit_dev(ndev);
else if (pdev_is_xeon(pdev) || pdev_is_skx_xeon(pdev))
xeon_deinit_dev(ndev);
err_init_dev:
intel_ntb_deinit_pci(ndev);
err_init_pci:
kfree(ndev);
err_ndev:
return rc;
}
static void intel_ntb_pci_remove(struct pci_dev *pdev)
{
struct intel_ntb_dev *ndev = pci_get_drvdata(pdev);
ntb_unregister_device(&ndev->ntb);
ndev_deinit_debugfs(ndev);
if (pdev_is_atom(pdev))
atom_deinit_dev(ndev);
else if (pdev_is_xeon(pdev) || pdev_is_skx_xeon(pdev))
xeon_deinit_dev(ndev);
intel_ntb_deinit_pci(ndev);
kfree(ndev);
}
static int __init intel_ntb_pci_driver_init(void)
{
pr_info("%s %s\n", NTB_DESC, NTB_VER);
if (debugfs_initialized())
debugfs_dir = debugfs_create_dir(KBUILD_MODNAME, NULL);
return pci_register_driver(&intel_ntb_pci_driver);
}
static void __exit intel_ntb_pci_driver_exit(void)
{
pci_unregister_driver(&intel_ntb_pci_driver);
debugfs_remove_recursive(debugfs_dir);
}
