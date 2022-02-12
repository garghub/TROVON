static struct arm_smmu_domain *to_smmu_domain(struct iommu_domain *dom)
{
return container_of(dom, struct arm_smmu_domain, domain);
}
static void parse_driver_options(struct arm_smmu_device *smmu)
{
int i = 0;
do {
if (of_property_read_bool(smmu->dev->of_node,
arm_smmu_options[i].prop)) {
smmu->options |= arm_smmu_options[i].opt;
dev_notice(smmu->dev, "option %s\n",
arm_smmu_options[i].prop);
}
} while (arm_smmu_options[++i].opt);
}
static struct device_node *dev_get_dev_node(struct device *dev)
{
if (dev_is_pci(dev)) {
struct pci_bus *bus = to_pci_dev(dev)->bus;
while (!pci_is_root_bus(bus))
bus = bus->parent;
return of_node_get(bus->bridge->parent->of_node);
}
return of_node_get(dev->of_node);
}
static int __arm_smmu_get_pci_sid(struct pci_dev *pdev, u16 alias, void *data)
{
*((__be32 *)data) = cpu_to_be32(alias);
return 0;
}
static int __find_legacy_master_phandle(struct device *dev, void *data)
{
struct of_phandle_iterator *it = *(void **)data;
struct device_node *np = it->node;
int err;
of_for_each_phandle(it, err, dev->of_node, "mmu-masters",
"#stream-id-cells", 0)
if (it->node == np) {
*(void **)data = dev;
return 1;
}
it->node = np;
return err == -ENOENT ? 0 : err;
}
static int arm_smmu_register_legacy_master(struct device *dev,
struct arm_smmu_device **smmu)
{
struct device *smmu_dev;
struct device_node *np;
struct of_phandle_iterator it;
void *data = &it;
u32 *sids;
__be32 pci_sid;
int err;
np = dev_get_dev_node(dev);
if (!np || !of_find_property(np, "#stream-id-cells", NULL)) {
of_node_put(np);
return -ENODEV;
}
it.node = np;
err = driver_for_each_device(&arm_smmu_driver.driver, NULL, &data,
__find_legacy_master_phandle);
smmu_dev = data;
of_node_put(np);
if (err == 0)
return -ENODEV;
if (err < 0)
return err;
if (dev_is_pci(dev)) {
pci_for_each_dma_alias(to_pci_dev(dev), __arm_smmu_get_pci_sid,
&pci_sid);
it.cur = &pci_sid;
it.cur_count = 1;
}
err = iommu_fwspec_init(dev, &smmu_dev->of_node->fwnode,
&arm_smmu_ops);
if (err)
return err;
sids = kcalloc(it.cur_count, sizeof(*sids), GFP_KERNEL);
if (!sids)
return -ENOMEM;
*smmu = dev_get_drvdata(smmu_dev);
of_phandle_iterator_args(&it, sids, it.cur_count);
err = iommu_fwspec_add_ids(dev, sids, it.cur_count);
kfree(sids);
return err;
}
static int __arm_smmu_alloc_bitmap(unsigned long *map, int start, int end)
{
int idx;
do {
idx = find_next_zero_bit(map, end, start);
if (idx == end)
return -ENOSPC;
} while (test_and_set_bit(idx, map));
return idx;
}
static void __arm_smmu_free_bitmap(unsigned long *map, int idx)
{
clear_bit(idx, map);
}
static void __arm_smmu_tlb_sync(struct arm_smmu_device *smmu)
{
int count = 0;
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
writel_relaxed(0, gr0_base + ARM_SMMU_GR0_sTLBGSYNC);
while (readl_relaxed(gr0_base + ARM_SMMU_GR0_sTLBGSTATUS)
& sTLBGSTATUS_GSACTIVE) {
cpu_relax();
if (++count == TLB_LOOP_TIMEOUT) {
dev_err_ratelimited(smmu->dev,
"TLB sync timed out -- SMMU may be deadlocked\n");
return;
}
udelay(1);
}
}
static void arm_smmu_tlb_sync(void *cookie)
{
struct arm_smmu_domain *smmu_domain = cookie;
__arm_smmu_tlb_sync(smmu_domain->smmu);
}
static void arm_smmu_tlb_inv_context(void *cookie)
{
struct arm_smmu_domain *smmu_domain = cookie;
struct arm_smmu_cfg *cfg = &smmu_domain->cfg;
struct arm_smmu_device *smmu = smmu_domain->smmu;
bool stage1 = cfg->cbar != CBAR_TYPE_S2_TRANS;
void __iomem *base;
if (stage1) {
base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, cfg->cbndx);
writel_relaxed(ARM_SMMU_CB_ASID(smmu, cfg),
base + ARM_SMMU_CB_S1_TLBIASID);
} else {
base = ARM_SMMU_GR0(smmu);
writel_relaxed(ARM_SMMU_CB_VMID(smmu, cfg),
base + ARM_SMMU_GR0_TLBIVMID);
}
__arm_smmu_tlb_sync(smmu);
}
static void arm_smmu_tlb_inv_range_nosync(unsigned long iova, size_t size,
size_t granule, bool leaf, void *cookie)
{
struct arm_smmu_domain *smmu_domain = cookie;
struct arm_smmu_cfg *cfg = &smmu_domain->cfg;
struct arm_smmu_device *smmu = smmu_domain->smmu;
bool stage1 = cfg->cbar != CBAR_TYPE_S2_TRANS;
void __iomem *reg;
if (stage1) {
reg = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, cfg->cbndx);
reg += leaf ? ARM_SMMU_CB_S1_TLBIVAL : ARM_SMMU_CB_S1_TLBIVA;
if (cfg->fmt != ARM_SMMU_CTX_FMT_AARCH64) {
iova &= ~12UL;
iova |= ARM_SMMU_CB_ASID(smmu, cfg);
do {
writel_relaxed(iova, reg);
iova += granule;
} while (size -= granule);
} else {
iova >>= 12;
iova |= (u64)ARM_SMMU_CB_ASID(smmu, cfg) << 48;
do {
writeq_relaxed(iova, reg);
iova += granule >> 12;
} while (size -= granule);
}
} else if (smmu->version == ARM_SMMU_V2) {
reg = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, cfg->cbndx);
reg += leaf ? ARM_SMMU_CB_S2_TLBIIPAS2L :
ARM_SMMU_CB_S2_TLBIIPAS2;
iova >>= 12;
do {
smmu_write_atomic_lq(iova, reg);
iova += granule >> 12;
} while (size -= granule);
} else {
reg = ARM_SMMU_GR0(smmu) + ARM_SMMU_GR0_TLBIVMID;
writel_relaxed(ARM_SMMU_CB_VMID(smmu, cfg), reg);
}
}
static irqreturn_t arm_smmu_context_fault(int irq, void *dev)
{
u32 fsr, fsynr;
unsigned long iova;
struct iommu_domain *domain = dev;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct arm_smmu_cfg *cfg = &smmu_domain->cfg;
struct arm_smmu_device *smmu = smmu_domain->smmu;
void __iomem *cb_base;
cb_base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, cfg->cbndx);
fsr = readl_relaxed(cb_base + ARM_SMMU_CB_FSR);
if (!(fsr & FSR_FAULT))
return IRQ_NONE;
fsynr = readl_relaxed(cb_base + ARM_SMMU_CB_FSYNR0);
iova = readq_relaxed(cb_base + ARM_SMMU_CB_FAR);
dev_err_ratelimited(smmu->dev,
"Unhandled context fault: fsr=0x%x, iova=0x%08lx, fsynr=0x%x, cb=%d\n",
fsr, iova, fsynr, cfg->cbndx);
writel(fsr, cb_base + ARM_SMMU_CB_FSR);
return IRQ_HANDLED;
}
static irqreturn_t arm_smmu_global_fault(int irq, void *dev)
{
u32 gfsr, gfsynr0, gfsynr1, gfsynr2;
struct arm_smmu_device *smmu = dev;
void __iomem *gr0_base = ARM_SMMU_GR0_NS(smmu);
gfsr = readl_relaxed(gr0_base + ARM_SMMU_GR0_sGFSR);
gfsynr0 = readl_relaxed(gr0_base + ARM_SMMU_GR0_sGFSYNR0);
gfsynr1 = readl_relaxed(gr0_base + ARM_SMMU_GR0_sGFSYNR1);
gfsynr2 = readl_relaxed(gr0_base + ARM_SMMU_GR0_sGFSYNR2);
if (!gfsr)
return IRQ_NONE;
dev_err_ratelimited(smmu->dev,
"Unexpected global fault, this could be serious\n");
dev_err_ratelimited(smmu->dev,
"\tGFSR 0x%08x, GFSYNR0 0x%08x, GFSYNR1 0x%08x, GFSYNR2 0x%08x\n",
gfsr, gfsynr0, gfsynr1, gfsynr2);
writel(gfsr, gr0_base + ARM_SMMU_GR0_sGFSR);
return IRQ_HANDLED;
}
static void arm_smmu_init_context_bank(struct arm_smmu_domain *smmu_domain,
struct io_pgtable_cfg *pgtbl_cfg)
{
u32 reg, reg2;
u64 reg64;
bool stage1;
struct arm_smmu_cfg *cfg = &smmu_domain->cfg;
struct arm_smmu_device *smmu = smmu_domain->smmu;
void __iomem *cb_base, *gr1_base;
gr1_base = ARM_SMMU_GR1(smmu);
stage1 = cfg->cbar != CBAR_TYPE_S2_TRANS;
cb_base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, cfg->cbndx);
if (smmu->version > ARM_SMMU_V1) {
if (cfg->fmt == ARM_SMMU_CTX_FMT_AARCH64)
reg = CBA2R_RW64_64BIT;
else
reg = CBA2R_RW64_32BIT;
if (smmu->features & ARM_SMMU_FEAT_VMID16)
reg |= ARM_SMMU_CB_VMID(smmu, cfg) << CBA2R_VMID_SHIFT;
writel_relaxed(reg, gr1_base + ARM_SMMU_GR1_CBA2R(cfg->cbndx));
}
reg = cfg->cbar;
if (smmu->version < ARM_SMMU_V2)
reg |= cfg->irptndx << CBAR_IRPTNDX_SHIFT;
if (stage1) {
reg |= (CBAR_S1_BPSHCFG_NSH << CBAR_S1_BPSHCFG_SHIFT) |
(CBAR_S1_MEMATTR_WB << CBAR_S1_MEMATTR_SHIFT);
} else if (!(smmu->features & ARM_SMMU_FEAT_VMID16)) {
reg |= ARM_SMMU_CB_VMID(smmu, cfg) << CBAR_VMID_SHIFT;
}
writel_relaxed(reg, gr1_base + ARM_SMMU_GR1_CBAR(cfg->cbndx));
if (stage1) {
u16 asid = ARM_SMMU_CB_ASID(smmu, cfg);
if (cfg->fmt == ARM_SMMU_CTX_FMT_AARCH32_S) {
reg = pgtbl_cfg->arm_v7s_cfg.ttbr[0];
writel_relaxed(reg, cb_base + ARM_SMMU_CB_TTBR0);
reg = pgtbl_cfg->arm_v7s_cfg.ttbr[1];
writel_relaxed(reg, cb_base + ARM_SMMU_CB_TTBR1);
writel_relaxed(asid, cb_base + ARM_SMMU_CB_CONTEXTIDR);
} else {
reg64 = pgtbl_cfg->arm_lpae_s1_cfg.ttbr[0];
reg64 |= (u64)asid << TTBRn_ASID_SHIFT;
writeq_relaxed(reg64, cb_base + ARM_SMMU_CB_TTBR0);
reg64 = pgtbl_cfg->arm_lpae_s1_cfg.ttbr[1];
reg64 |= (u64)asid << TTBRn_ASID_SHIFT;
writeq_relaxed(reg64, cb_base + ARM_SMMU_CB_TTBR1);
}
} else {
reg64 = pgtbl_cfg->arm_lpae_s2_cfg.vttbr;
writeq_relaxed(reg64, cb_base + ARM_SMMU_CB_TTBR0);
}
if (stage1) {
if (cfg->fmt == ARM_SMMU_CTX_FMT_AARCH32_S) {
reg = pgtbl_cfg->arm_v7s_cfg.tcr;
reg2 = 0;
} else {
reg = pgtbl_cfg->arm_lpae_s1_cfg.tcr;
reg2 = pgtbl_cfg->arm_lpae_s1_cfg.tcr >> 32;
reg2 |= TTBCR2_SEP_UPSTREAM;
}
if (smmu->version > ARM_SMMU_V1)
writel_relaxed(reg2, cb_base + ARM_SMMU_CB_TTBCR2);
} else {
reg = pgtbl_cfg->arm_lpae_s2_cfg.vtcr;
}
writel_relaxed(reg, cb_base + ARM_SMMU_CB_TTBCR);
if (stage1) {
if (cfg->fmt == ARM_SMMU_CTX_FMT_AARCH32_S) {
reg = pgtbl_cfg->arm_v7s_cfg.prrr;
reg2 = pgtbl_cfg->arm_v7s_cfg.nmrr;
} else {
reg = pgtbl_cfg->arm_lpae_s1_cfg.mair[0];
reg2 = pgtbl_cfg->arm_lpae_s1_cfg.mair[1];
}
writel_relaxed(reg, cb_base + ARM_SMMU_CB_S1_MAIR0);
writel_relaxed(reg2, cb_base + ARM_SMMU_CB_S1_MAIR1);
}
reg = SCTLR_CFIE | SCTLR_CFRE | SCTLR_AFE | SCTLR_TRE | SCTLR_M;
if (stage1)
reg |= SCTLR_S1_ASIDPNE;
#ifdef __BIG_ENDIAN
reg |= SCTLR_E;
#endif
writel_relaxed(reg, cb_base + ARM_SMMU_CB_SCTLR);
}
static int arm_smmu_init_domain_context(struct iommu_domain *domain,
struct arm_smmu_device *smmu)
{
int irq, start, ret = 0;
unsigned long ias, oas;
struct io_pgtable_ops *pgtbl_ops;
struct io_pgtable_cfg pgtbl_cfg;
enum io_pgtable_fmt fmt;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct arm_smmu_cfg *cfg = &smmu_domain->cfg;
mutex_lock(&smmu_domain->init_mutex);
if (smmu_domain->smmu)
goto out_unlock;
if (!(smmu->features & ARM_SMMU_FEAT_TRANS_S1))
smmu_domain->stage = ARM_SMMU_DOMAIN_S2;
if (!(smmu->features & ARM_SMMU_FEAT_TRANS_S2))
smmu_domain->stage = ARM_SMMU_DOMAIN_S1;
if (smmu->features & ARM_SMMU_FEAT_FMT_AARCH32_L)
cfg->fmt = ARM_SMMU_CTX_FMT_AARCH32_L;
if (IS_ENABLED(CONFIG_IOMMU_IO_PGTABLE_ARMV7S) &&
!IS_ENABLED(CONFIG_64BIT) && !IS_ENABLED(CONFIG_ARM_LPAE) &&
(smmu->features & ARM_SMMU_FEAT_FMT_AARCH32_S) &&
(smmu_domain->stage == ARM_SMMU_DOMAIN_S1))
cfg->fmt = ARM_SMMU_CTX_FMT_AARCH32_S;
if ((IS_ENABLED(CONFIG_64BIT) || cfg->fmt == ARM_SMMU_CTX_FMT_NONE) &&
(smmu->features & (ARM_SMMU_FEAT_FMT_AARCH64_64K |
ARM_SMMU_FEAT_FMT_AARCH64_16K |
ARM_SMMU_FEAT_FMT_AARCH64_4K)))
cfg->fmt = ARM_SMMU_CTX_FMT_AARCH64;
if (cfg->fmt == ARM_SMMU_CTX_FMT_NONE) {
ret = -EINVAL;
goto out_unlock;
}
switch (smmu_domain->stage) {
case ARM_SMMU_DOMAIN_S1:
cfg->cbar = CBAR_TYPE_S1_TRANS_S2_BYPASS;
start = smmu->num_s2_context_banks;
ias = smmu->va_size;
oas = smmu->ipa_size;
if (cfg->fmt == ARM_SMMU_CTX_FMT_AARCH64) {
fmt = ARM_64_LPAE_S1;
} else if (cfg->fmt == ARM_SMMU_CTX_FMT_AARCH32_L) {
fmt = ARM_32_LPAE_S1;
ias = min(ias, 32UL);
oas = min(oas, 40UL);
} else {
fmt = ARM_V7S;
ias = min(ias, 32UL);
oas = min(oas, 32UL);
}
break;
case ARM_SMMU_DOMAIN_NESTED:
case ARM_SMMU_DOMAIN_S2:
cfg->cbar = CBAR_TYPE_S2_TRANS;
start = 0;
ias = smmu->ipa_size;
oas = smmu->pa_size;
if (cfg->fmt == ARM_SMMU_CTX_FMT_AARCH64) {
fmt = ARM_64_LPAE_S2;
} else {
fmt = ARM_32_LPAE_S2;
ias = min(ias, 40UL);
oas = min(oas, 40UL);
}
break;
default:
ret = -EINVAL;
goto out_unlock;
}
ret = __arm_smmu_alloc_bitmap(smmu->context_map, start,
smmu->num_context_banks);
if (ret < 0)
goto out_unlock;
cfg->cbndx = ret;
if (smmu->version < ARM_SMMU_V2) {
cfg->irptndx = atomic_inc_return(&smmu->irptndx);
cfg->irptndx %= smmu->num_context_irqs;
} else {
cfg->irptndx = cfg->cbndx;
}
pgtbl_cfg = (struct io_pgtable_cfg) {
.pgsize_bitmap = smmu->pgsize_bitmap,
.ias = ias,
.oas = oas,
.tlb = &arm_smmu_gather_ops,
.iommu_dev = smmu->dev,
};
smmu_domain->smmu = smmu;
pgtbl_ops = alloc_io_pgtable_ops(fmt, &pgtbl_cfg, smmu_domain);
if (!pgtbl_ops) {
ret = -ENOMEM;
goto out_clear_smmu;
}
domain->pgsize_bitmap = pgtbl_cfg.pgsize_bitmap;
domain->geometry.aperture_end = (1UL << ias) - 1;
domain->geometry.force_aperture = true;
arm_smmu_init_context_bank(smmu_domain, &pgtbl_cfg);
irq = smmu->irqs[smmu->num_global_irqs + cfg->irptndx];
ret = devm_request_irq(smmu->dev, irq, arm_smmu_context_fault,
IRQF_SHARED, "arm-smmu-context-fault", domain);
if (ret < 0) {
dev_err(smmu->dev, "failed to request context IRQ %d (%u)\n",
cfg->irptndx, irq);
cfg->irptndx = INVALID_IRPTNDX;
}
mutex_unlock(&smmu_domain->init_mutex);
smmu_domain->pgtbl_ops = pgtbl_ops;
return 0;
out_clear_smmu:
smmu_domain->smmu = NULL;
out_unlock:
mutex_unlock(&smmu_domain->init_mutex);
return ret;
}
static void arm_smmu_destroy_domain_context(struct iommu_domain *domain)
{
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct arm_smmu_device *smmu = smmu_domain->smmu;
struct arm_smmu_cfg *cfg = &smmu_domain->cfg;
void __iomem *cb_base;
int irq;
if (!smmu)
return;
cb_base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, cfg->cbndx);
writel_relaxed(0, cb_base + ARM_SMMU_CB_SCTLR);
if (cfg->irptndx != INVALID_IRPTNDX) {
irq = smmu->irqs[smmu->num_global_irqs + cfg->irptndx];
devm_free_irq(smmu->dev, irq, domain);
}
free_io_pgtable_ops(smmu_domain->pgtbl_ops);
__arm_smmu_free_bitmap(smmu->context_map, cfg->cbndx);
}
static struct iommu_domain *arm_smmu_domain_alloc(unsigned type)
{
struct arm_smmu_domain *smmu_domain;
if (type != IOMMU_DOMAIN_UNMANAGED && type != IOMMU_DOMAIN_DMA)
return NULL;
smmu_domain = kzalloc(sizeof(*smmu_domain), GFP_KERNEL);
if (!smmu_domain)
return NULL;
if (type == IOMMU_DOMAIN_DMA && (using_legacy_binding ||
iommu_get_dma_cookie(&smmu_domain->domain))) {
kfree(smmu_domain);
return NULL;
}
mutex_init(&smmu_domain->init_mutex);
spin_lock_init(&smmu_domain->pgtbl_lock);
return &smmu_domain->domain;
}
static void arm_smmu_domain_free(struct iommu_domain *domain)
{
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
iommu_put_dma_cookie(domain);
arm_smmu_destroy_domain_context(domain);
kfree(smmu_domain);
}
static void arm_smmu_write_smr(struct arm_smmu_device *smmu, int idx)
{
struct arm_smmu_smr *smr = smmu->smrs + idx;
u32 reg = smr->id << SMR_ID_SHIFT | smr->mask << SMR_MASK_SHIFT;
if (smr->valid)
reg |= SMR_VALID;
writel_relaxed(reg, ARM_SMMU_GR0(smmu) + ARM_SMMU_GR0_SMR(idx));
}
static void arm_smmu_write_s2cr(struct arm_smmu_device *smmu, int idx)
{
struct arm_smmu_s2cr *s2cr = smmu->s2crs + idx;
u32 reg = (s2cr->type & S2CR_TYPE_MASK) << S2CR_TYPE_SHIFT |
(s2cr->cbndx & S2CR_CBNDX_MASK) << S2CR_CBNDX_SHIFT |
(s2cr->privcfg & S2CR_PRIVCFG_MASK) << S2CR_PRIVCFG_SHIFT;
writel_relaxed(reg, ARM_SMMU_GR0(smmu) + ARM_SMMU_GR0_S2CR(idx));
}
static void arm_smmu_write_sme(struct arm_smmu_device *smmu, int idx)
{
arm_smmu_write_s2cr(smmu, idx);
if (smmu->smrs)
arm_smmu_write_smr(smmu, idx);
}
static int arm_smmu_find_sme(struct arm_smmu_device *smmu, u16 id, u16 mask)
{
struct arm_smmu_smr *smrs = smmu->smrs;
int i, free_idx = -ENOSPC;
if (!smrs)
return id;
for (i = 0; i < smmu->num_mapping_groups; ++i) {
if (!smrs[i].valid) {
if (free_idx < 0)
free_idx = i;
continue;
}
if ((mask & smrs[i].mask) == mask &&
!((id ^ smrs[i].id) & ~smrs[i].mask))
return i;
if (!((id ^ smrs[i].id) & ~(smrs[i].mask | mask)))
return -EINVAL;
}
return free_idx;
}
static bool arm_smmu_free_sme(struct arm_smmu_device *smmu, int idx)
{
if (--smmu->s2crs[idx].count)
return false;
smmu->s2crs[idx] = s2cr_init_val;
if (smmu->smrs)
smmu->smrs[idx].valid = false;
return true;
}
static int arm_smmu_master_alloc_smes(struct device *dev)
{
struct iommu_fwspec *fwspec = dev->iommu_fwspec;
struct arm_smmu_master_cfg *cfg = fwspec->iommu_priv;
struct arm_smmu_device *smmu = cfg->smmu;
struct arm_smmu_smr *smrs = smmu->smrs;
struct iommu_group *group;
int i, idx, ret;
mutex_lock(&smmu->stream_map_mutex);
for_each_cfg_sme(fwspec, i, idx) {
u16 sid = fwspec->ids[i];
u16 mask = fwspec->ids[i] >> SMR_MASK_SHIFT;
if (idx != INVALID_SMENDX) {
ret = -EEXIST;
goto out_err;
}
ret = arm_smmu_find_sme(smmu, sid, mask);
if (ret < 0)
goto out_err;
idx = ret;
if (smrs && smmu->s2crs[idx].count == 0) {
smrs[idx].id = sid;
smrs[idx].mask = mask;
smrs[idx].valid = true;
}
smmu->s2crs[idx].count++;
cfg->smendx[i] = (s16)idx;
}
group = iommu_group_get_for_dev(dev);
if (!group)
group = ERR_PTR(-ENOMEM);
if (IS_ERR(group)) {
ret = PTR_ERR(group);
goto out_err;
}
iommu_group_put(group);
for_each_cfg_sme(fwspec, i, idx) {
arm_smmu_write_sme(smmu, idx);
smmu->s2crs[idx].group = group;
}
mutex_unlock(&smmu->stream_map_mutex);
return 0;
out_err:
while (i--) {
arm_smmu_free_sme(smmu, cfg->smendx[i]);
cfg->smendx[i] = INVALID_SMENDX;
}
mutex_unlock(&smmu->stream_map_mutex);
return ret;
}
static void arm_smmu_master_free_smes(struct iommu_fwspec *fwspec)
{
struct arm_smmu_device *smmu = fwspec_smmu(fwspec);
struct arm_smmu_master_cfg *cfg = fwspec->iommu_priv;
int i, idx;
mutex_lock(&smmu->stream_map_mutex);
for_each_cfg_sme(fwspec, i, idx) {
if (arm_smmu_free_sme(smmu, idx))
arm_smmu_write_sme(smmu, idx);
cfg->smendx[i] = INVALID_SMENDX;
}
mutex_unlock(&smmu->stream_map_mutex);
}
static int arm_smmu_domain_add_master(struct arm_smmu_domain *smmu_domain,
struct iommu_fwspec *fwspec)
{
struct arm_smmu_device *smmu = smmu_domain->smmu;
struct arm_smmu_s2cr *s2cr = smmu->s2crs;
enum arm_smmu_s2cr_type type = S2CR_TYPE_TRANS;
u8 cbndx = smmu_domain->cfg.cbndx;
int i, idx;
for_each_cfg_sme(fwspec, i, idx) {
if (type == s2cr[idx].type && cbndx == s2cr[idx].cbndx)
continue;
s2cr[idx].type = type;
s2cr[idx].privcfg = S2CR_PRIVCFG_UNPRIV;
s2cr[idx].cbndx = cbndx;
arm_smmu_write_s2cr(smmu, idx);
}
return 0;
}
static int arm_smmu_attach_dev(struct iommu_domain *domain, struct device *dev)
{
int ret;
struct iommu_fwspec *fwspec = dev->iommu_fwspec;
struct arm_smmu_device *smmu;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
if (!fwspec || fwspec->ops != &arm_smmu_ops) {
dev_err(dev, "cannot attach to SMMU, is it on the same bus?\n");
return -ENXIO;
}
if (!fwspec->iommu_priv)
return -ENODEV;
smmu = fwspec_smmu(fwspec);
ret = arm_smmu_init_domain_context(domain, smmu);
if (ret < 0)
return ret;
if (smmu_domain->smmu != smmu) {
dev_err(dev,
"cannot attach to SMMU %s whilst already attached to domain on SMMU %s\n",
dev_name(smmu_domain->smmu->dev), dev_name(smmu->dev));
return -EINVAL;
}
return arm_smmu_domain_add_master(smmu_domain, fwspec);
}
static int arm_smmu_map(struct iommu_domain *domain, unsigned long iova,
phys_addr_t paddr, size_t size, int prot)
{
int ret;
unsigned long flags;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct io_pgtable_ops *ops= smmu_domain->pgtbl_ops;
if (!ops)
return -ENODEV;
spin_lock_irqsave(&smmu_domain->pgtbl_lock, flags);
ret = ops->map(ops, iova, paddr, size, prot);
spin_unlock_irqrestore(&smmu_domain->pgtbl_lock, flags);
return ret;
}
static size_t arm_smmu_unmap(struct iommu_domain *domain, unsigned long iova,
size_t size)
{
size_t ret;
unsigned long flags;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct io_pgtable_ops *ops= smmu_domain->pgtbl_ops;
if (!ops)
return 0;
spin_lock_irqsave(&smmu_domain->pgtbl_lock, flags);
ret = ops->unmap(ops, iova, size);
spin_unlock_irqrestore(&smmu_domain->pgtbl_lock, flags);
return ret;
}
static phys_addr_t arm_smmu_iova_to_phys_hard(struct iommu_domain *domain,
dma_addr_t iova)
{
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct arm_smmu_device *smmu = smmu_domain->smmu;
struct arm_smmu_cfg *cfg = &smmu_domain->cfg;
struct io_pgtable_ops *ops= smmu_domain->pgtbl_ops;
struct device *dev = smmu->dev;
void __iomem *cb_base;
u32 tmp;
u64 phys;
unsigned long va;
cb_base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, cfg->cbndx);
va = iova & ~0xfffUL;
if (smmu->version == ARM_SMMU_V2)
smmu_write_atomic_lq(va, cb_base + ARM_SMMU_CB_ATS1PR);
else
writel_relaxed(va, cb_base + ARM_SMMU_CB_ATS1PR);
if (readl_poll_timeout_atomic(cb_base + ARM_SMMU_CB_ATSR, tmp,
!(tmp & ATSR_ACTIVE), 5, 50)) {
dev_err(dev,
"iova to phys timed out on %pad. Falling back to software table walk.\n",
&iova);
return ops->iova_to_phys(ops, iova);
}
phys = readq_relaxed(cb_base + ARM_SMMU_CB_PAR);
if (phys & CB_PAR_F) {
dev_err(dev, "translation fault!\n");
dev_err(dev, "PAR = 0x%llx\n", phys);
return 0;
}
return (phys & GENMASK_ULL(39, 12)) | (iova & 0xfff);
}
static phys_addr_t arm_smmu_iova_to_phys(struct iommu_domain *domain,
dma_addr_t iova)
{
phys_addr_t ret;
unsigned long flags;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct io_pgtable_ops *ops= smmu_domain->pgtbl_ops;
if (!ops)
return 0;
spin_lock_irqsave(&smmu_domain->pgtbl_lock, flags);
if (smmu_domain->smmu->features & ARM_SMMU_FEAT_TRANS_OPS &&
smmu_domain->stage == ARM_SMMU_DOMAIN_S1) {
ret = arm_smmu_iova_to_phys_hard(domain, iova);
} else {
ret = ops->iova_to_phys(ops, iova);
}
spin_unlock_irqrestore(&smmu_domain->pgtbl_lock, flags);
return ret;
}
static bool arm_smmu_capable(enum iommu_cap cap)
{
switch (cap) {
case IOMMU_CAP_CACHE_COHERENCY:
return true;
case IOMMU_CAP_INTR_REMAP:
return true;
case IOMMU_CAP_NOEXEC:
return true;
default:
return false;
}
}
static int arm_smmu_match_node(struct device *dev, void *data)
{
return dev->of_node == data;
}
static struct arm_smmu_device *arm_smmu_get_by_node(struct device_node *np)
{
struct device *dev = driver_find_device(&arm_smmu_driver.driver, NULL,
np, arm_smmu_match_node);
put_device(dev);
return dev ? dev_get_drvdata(dev) : NULL;
}
static int arm_smmu_add_device(struct device *dev)
{
struct arm_smmu_device *smmu;
struct arm_smmu_master_cfg *cfg;
struct iommu_fwspec *fwspec = dev->iommu_fwspec;
int i, ret;
if (using_legacy_binding) {
ret = arm_smmu_register_legacy_master(dev, &smmu);
fwspec = dev->iommu_fwspec;
if (ret)
goto out_free;
} else if (fwspec && fwspec->ops == &arm_smmu_ops) {
smmu = arm_smmu_get_by_node(to_of_node(fwspec->iommu_fwnode));
} else {
return -ENODEV;
}
ret = -EINVAL;
for (i = 0; i < fwspec->num_ids; i++) {
u16 sid = fwspec->ids[i];
u16 mask = fwspec->ids[i] >> SMR_MASK_SHIFT;
if (sid & ~smmu->streamid_mask) {
dev_err(dev, "stream ID 0x%x out of range for SMMU (0x%x)\n",
sid, smmu->streamid_mask);
goto out_free;
}
if (mask & ~smmu->smr_mask_mask) {
dev_err(dev, "SMR mask 0x%x out of range for SMMU (0x%x)\n",
sid, smmu->smr_mask_mask);
goto out_free;
}
}
ret = -ENOMEM;
cfg = kzalloc(offsetof(struct arm_smmu_master_cfg, smendx[i]),
GFP_KERNEL);
if (!cfg)
goto out_free;
cfg->smmu = smmu;
fwspec->iommu_priv = cfg;
while (i--)
cfg->smendx[i] = INVALID_SMENDX;
ret = arm_smmu_master_alloc_smes(dev);
if (ret)
goto out_free;
return 0;
out_free:
if (fwspec)
kfree(fwspec->iommu_priv);
iommu_fwspec_free(dev);
return ret;
}
static void arm_smmu_remove_device(struct device *dev)
{
struct iommu_fwspec *fwspec = dev->iommu_fwspec;
if (!fwspec || fwspec->ops != &arm_smmu_ops)
return;
arm_smmu_master_free_smes(fwspec);
iommu_group_remove_device(dev);
kfree(fwspec->iommu_priv);
iommu_fwspec_free(dev);
}
static struct iommu_group *arm_smmu_device_group(struct device *dev)
{
struct iommu_fwspec *fwspec = dev->iommu_fwspec;
struct arm_smmu_device *smmu = fwspec_smmu(fwspec);
struct iommu_group *group = NULL;
int i, idx;
for_each_cfg_sme(fwspec, i, idx) {
if (group && smmu->s2crs[idx].group &&
group != smmu->s2crs[idx].group)
return ERR_PTR(-EINVAL);
group = smmu->s2crs[idx].group;
}
if (group)
return group;
if (dev_is_pci(dev))
group = pci_device_group(dev);
else
group = generic_device_group(dev);
return group;
}
static int arm_smmu_domain_get_attr(struct iommu_domain *domain,
enum iommu_attr attr, void *data)
{
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
switch (attr) {
case DOMAIN_ATTR_NESTING:
*(int *)data = (smmu_domain->stage == ARM_SMMU_DOMAIN_NESTED);
return 0;
default:
return -ENODEV;
}
}
static int arm_smmu_domain_set_attr(struct iommu_domain *domain,
enum iommu_attr attr, void *data)
{
int ret = 0;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
mutex_lock(&smmu_domain->init_mutex);
switch (attr) {
case DOMAIN_ATTR_NESTING:
if (smmu_domain->smmu) {
ret = -EPERM;
goto out_unlock;
}
if (*(int *)data)
smmu_domain->stage = ARM_SMMU_DOMAIN_NESTED;
else
smmu_domain->stage = ARM_SMMU_DOMAIN_S1;
break;
default:
ret = -ENODEV;
}
out_unlock:
mutex_unlock(&smmu_domain->init_mutex);
return ret;
}
static int arm_smmu_of_xlate(struct device *dev, struct of_phandle_args *args)
{
u32 fwid = 0;
if (args->args_count > 0)
fwid |= (u16)args->args[0];
if (args->args_count > 1)
fwid |= (u16)args->args[1] << SMR_MASK_SHIFT;
return iommu_fwspec_add_ids(dev, &fwid, 1);
}
static void arm_smmu_device_reset(struct arm_smmu_device *smmu)
{
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
void __iomem *cb_base;
int i;
u32 reg, major;
reg = readl_relaxed(ARM_SMMU_GR0_NS(smmu) + ARM_SMMU_GR0_sGFSR);
writel(reg, ARM_SMMU_GR0_NS(smmu) + ARM_SMMU_GR0_sGFSR);
for (i = 0; i < smmu->num_mapping_groups; ++i)
arm_smmu_write_sme(smmu, i);
reg = readl_relaxed(gr0_base + ARM_SMMU_GR0_ID7);
major = (reg >> ID7_MAJOR_SHIFT) & ID7_MAJOR_MASK;
if ((smmu->model == ARM_MMU500) && (major >= 2)) {
reg = readl_relaxed(gr0_base + ARM_SMMU_GR0_sACR);
reg &= ~ARM_MMU500_ACR_CACHE_LOCK;
writel_relaxed(reg, gr0_base + ARM_SMMU_GR0_sACR);
}
for (i = 0; i < smmu->num_context_banks; ++i) {
cb_base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, i);
writel_relaxed(0, cb_base + ARM_SMMU_CB_SCTLR);
writel_relaxed(FSR_FAULT, cb_base + ARM_SMMU_CB_FSR);
if (smmu->model == ARM_MMU500) {
reg = readl_relaxed(cb_base + ARM_SMMU_CB_ACTLR);
reg &= ~ARM_MMU500_ACTLR_CPRE;
writel_relaxed(reg, cb_base + ARM_SMMU_CB_ACTLR);
}
}
writel_relaxed(0, gr0_base + ARM_SMMU_GR0_TLBIALLH);
writel_relaxed(0, gr0_base + ARM_SMMU_GR0_TLBIALLNSNH);
reg = readl_relaxed(ARM_SMMU_GR0_NS(smmu) + ARM_SMMU_GR0_sCR0);
reg |= (sCR0_GFRE | sCR0_GFIE | sCR0_GCFGFRE | sCR0_GCFGFIE);
reg |= (sCR0_VMIDPNE | sCR0_PTM);
reg &= ~sCR0_CLIENTPD;
if (disable_bypass)
reg |= sCR0_USFCFG;
else
reg &= ~sCR0_USFCFG;
reg &= ~sCR0_FB;
reg &= ~(sCR0_BSU_MASK << sCR0_BSU_SHIFT);
if (smmu->features & ARM_SMMU_FEAT_VMID16)
reg |= sCR0_VMID16EN;
__arm_smmu_tlb_sync(smmu);
writel(reg, ARM_SMMU_GR0_NS(smmu) + ARM_SMMU_GR0_sCR0);
}
static int arm_smmu_id_size_to_bits(int size)
{
switch (size) {
case 0:
return 32;
case 1:
return 36;
case 2:
return 40;
case 3:
return 42;
case 4:
return 44;
case 5:
default:
return 48;
}
}
static int arm_smmu_device_cfg_probe(struct arm_smmu_device *smmu)
{
unsigned long size;
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
u32 id;
bool cttw_dt, cttw_reg;
int i;
dev_notice(smmu->dev, "probing hardware configuration...\n");
dev_notice(smmu->dev, "SMMUv%d with:\n",
smmu->version == ARM_SMMU_V2 ? 2 : 1);
id = readl_relaxed(gr0_base + ARM_SMMU_GR0_ID0);
if (force_stage == 1)
id &= ~(ID0_S2TS | ID0_NTS);
else if (force_stage == 2)
id &= ~(ID0_S1TS | ID0_NTS);
if (id & ID0_S1TS) {
smmu->features |= ARM_SMMU_FEAT_TRANS_S1;
dev_notice(smmu->dev, "\tstage 1 translation\n");
}
if (id & ID0_S2TS) {
smmu->features |= ARM_SMMU_FEAT_TRANS_S2;
dev_notice(smmu->dev, "\tstage 2 translation\n");
}
if (id & ID0_NTS) {
smmu->features |= ARM_SMMU_FEAT_TRANS_NESTED;
dev_notice(smmu->dev, "\tnested translation\n");
}
if (!(smmu->features &
(ARM_SMMU_FEAT_TRANS_S1 | ARM_SMMU_FEAT_TRANS_S2))) {
dev_err(smmu->dev, "\tno translation support!\n");
return -ENODEV;
}
if ((id & ID0_S1TS) &&
((smmu->version < ARM_SMMU_V2) || !(id & ID0_ATOSNS))) {
smmu->features |= ARM_SMMU_FEAT_TRANS_OPS;
dev_notice(smmu->dev, "\taddress translation ops\n");
}
cttw_dt = of_dma_is_coherent(smmu->dev->of_node);
cttw_reg = !!(id & ID0_CTTW);
if (cttw_dt)
smmu->features |= ARM_SMMU_FEAT_COHERENT_WALK;
if (cttw_dt || cttw_reg)
dev_notice(smmu->dev, "\t%scoherent table walk\n",
cttw_dt ? "" : "non-");
if (cttw_dt != cttw_reg)
dev_notice(smmu->dev,
"\t(IDR0.CTTW overridden by dma-coherent property)\n");
size = 1 << ((id >> ID0_NUMSIDB_SHIFT) & ID0_NUMSIDB_MASK);
smmu->streamid_mask = size - 1;
if (id & ID0_SMS) {
u32 smr;
smmu->features |= ARM_SMMU_FEAT_STREAM_MATCH;
size = (id >> ID0_NUMSMRG_SHIFT) & ID0_NUMSMRG_MASK;
if (size == 0) {
dev_err(smmu->dev,
"stream-matching supported, but no SMRs present!\n");
return -ENODEV;
}
smr = smmu->streamid_mask << SMR_ID_SHIFT;
writel_relaxed(smr, gr0_base + ARM_SMMU_GR0_SMR(0));
smr = readl_relaxed(gr0_base + ARM_SMMU_GR0_SMR(0));
smmu->streamid_mask = smr >> SMR_ID_SHIFT;
smr = smmu->streamid_mask << SMR_MASK_SHIFT;
writel_relaxed(smr, gr0_base + ARM_SMMU_GR0_SMR(0));
smr = readl_relaxed(gr0_base + ARM_SMMU_GR0_SMR(0));
smmu->smr_mask_mask = smr >> SMR_MASK_SHIFT;
smmu->smrs = devm_kcalloc(smmu->dev, size, sizeof(*smmu->smrs),
GFP_KERNEL);
if (!smmu->smrs)
return -ENOMEM;
dev_notice(smmu->dev,
"\tstream matching with %lu register groups, mask 0x%x",
size, smmu->smr_mask_mask);
}
smmu->s2crs = devm_kmalloc_array(smmu->dev, size, sizeof(*smmu->s2crs),
GFP_KERNEL);
if (!smmu->s2crs)
return -ENOMEM;
for (i = 0; i < size; i++)
smmu->s2crs[i] = s2cr_init_val;
smmu->num_mapping_groups = size;
mutex_init(&smmu->stream_map_mutex);
if (smmu->version < ARM_SMMU_V2 || !(id & ID0_PTFS_NO_AARCH32)) {
smmu->features |= ARM_SMMU_FEAT_FMT_AARCH32_L;
if (!(id & ID0_PTFS_NO_AARCH32S))
smmu->features |= ARM_SMMU_FEAT_FMT_AARCH32_S;
}
id = readl_relaxed(gr0_base + ARM_SMMU_GR0_ID1);
smmu->pgshift = (id & ID1_PAGESIZE) ? 16 : 12;
size = 1 << (((id >> ID1_NUMPAGENDXB_SHIFT) & ID1_NUMPAGENDXB_MASK) + 1);
size *= 2 << smmu->pgshift;
if (smmu->size != size)
dev_warn(smmu->dev,
"SMMU address space size (0x%lx) differs from mapped region size (0x%lx)!\n",
size, smmu->size);
smmu->num_s2_context_banks = (id >> ID1_NUMS2CB_SHIFT) & ID1_NUMS2CB_MASK;
smmu->num_context_banks = (id >> ID1_NUMCB_SHIFT) & ID1_NUMCB_MASK;
if (smmu->num_s2_context_banks > smmu->num_context_banks) {
dev_err(smmu->dev, "impossible number of S2 context banks!\n");
return -ENODEV;
}
dev_notice(smmu->dev, "\t%u context banks (%u stage-2 only)\n",
smmu->num_context_banks, smmu->num_s2_context_banks);
if (smmu->model == CAVIUM_SMMUV2) {
smmu->cavium_id_base =
atomic_add_return(smmu->num_context_banks,
&cavium_smmu_context_count);
smmu->cavium_id_base -= smmu->num_context_banks;
}
id = readl_relaxed(gr0_base + ARM_SMMU_GR0_ID2);
size = arm_smmu_id_size_to_bits((id >> ID2_IAS_SHIFT) & ID2_IAS_MASK);
smmu->ipa_size = size;
size = arm_smmu_id_size_to_bits((id >> ID2_OAS_SHIFT) & ID2_OAS_MASK);
smmu->pa_size = size;
if (id & ID2_VMID16)
smmu->features |= ARM_SMMU_FEAT_VMID16;
if (dma_set_mask_and_coherent(smmu->dev, DMA_BIT_MASK(size)))
dev_warn(smmu->dev,
"failed to set DMA mask for table walker\n");
if (smmu->version < ARM_SMMU_V2) {
smmu->va_size = smmu->ipa_size;
if (smmu->version == ARM_SMMU_V1_64K)
smmu->features |= ARM_SMMU_FEAT_FMT_AARCH64_64K;
} else {
size = (id >> ID2_UBS_SHIFT) & ID2_UBS_MASK;
smmu->va_size = arm_smmu_id_size_to_bits(size);
if (id & ID2_PTFS_4K)
smmu->features |= ARM_SMMU_FEAT_FMT_AARCH64_4K;
if (id & ID2_PTFS_16K)
smmu->features |= ARM_SMMU_FEAT_FMT_AARCH64_16K;
if (id & ID2_PTFS_64K)
smmu->features |= ARM_SMMU_FEAT_FMT_AARCH64_64K;
}
if (smmu->features & ARM_SMMU_FEAT_FMT_AARCH32_S)
smmu->pgsize_bitmap |= SZ_4K | SZ_64K | SZ_1M | SZ_16M;
if (smmu->features &
(ARM_SMMU_FEAT_FMT_AARCH32_L | ARM_SMMU_FEAT_FMT_AARCH64_4K))
smmu->pgsize_bitmap |= SZ_4K | SZ_2M | SZ_1G;
if (smmu->features & ARM_SMMU_FEAT_FMT_AARCH64_16K)
smmu->pgsize_bitmap |= SZ_16K | SZ_32M;
if (smmu->features & ARM_SMMU_FEAT_FMT_AARCH64_64K)
smmu->pgsize_bitmap |= SZ_64K | SZ_512M;
if (arm_smmu_ops.pgsize_bitmap == -1UL)
arm_smmu_ops.pgsize_bitmap = smmu->pgsize_bitmap;
else
arm_smmu_ops.pgsize_bitmap |= smmu->pgsize_bitmap;
dev_notice(smmu->dev, "\tSupported page sizes: 0x%08lx\n",
smmu->pgsize_bitmap);
if (smmu->features & ARM_SMMU_FEAT_TRANS_S1)
dev_notice(smmu->dev, "\tStage-1: %lu-bit VA -> %lu-bit IPA\n",
smmu->va_size, smmu->ipa_size);
if (smmu->features & ARM_SMMU_FEAT_TRANS_S2)
dev_notice(smmu->dev, "\tStage-2: %lu-bit IPA -> %lu-bit PA\n",
smmu->ipa_size, smmu->pa_size);
return 0;
}
static int arm_smmu_device_dt_probe(struct platform_device *pdev)
{
const struct arm_smmu_match_data *data;
struct resource *res;
struct arm_smmu_device *smmu;
struct device *dev = &pdev->dev;
int num_irqs, i, err;
bool legacy_binding;
legacy_binding = of_find_property(dev->of_node, "mmu-masters", NULL);
if (legacy_binding && !using_generic_binding) {
if (!using_legacy_binding)
pr_notice("deprecated \"mmu-masters\" DT property in use; DMA API support unavailable\n");
using_legacy_binding = true;
} else if (!legacy_binding && !using_legacy_binding) {
using_generic_binding = true;
} else {
dev_err(dev, "not probing due to mismatched DT properties\n");
return -ENODEV;
}
smmu = devm_kzalloc(dev, sizeof(*smmu), GFP_KERNEL);
if (!smmu) {
dev_err(dev, "failed to allocate arm_smmu_device\n");
return -ENOMEM;
}
smmu->dev = dev;
data = of_device_get_match_data(dev);
smmu->version = data->version;
smmu->model = data->model;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
smmu->base = devm_ioremap_resource(dev, res);
if (IS_ERR(smmu->base))
return PTR_ERR(smmu->base);
smmu->size = resource_size(res);
if (of_property_read_u32(dev->of_node, "#global-interrupts",
&smmu->num_global_irqs)) {
dev_err(dev, "missing #global-interrupts property\n");
return -ENODEV;
}
num_irqs = 0;
while ((res = platform_get_resource(pdev, IORESOURCE_IRQ, num_irqs))) {
num_irqs++;
if (num_irqs > smmu->num_global_irqs)
smmu->num_context_irqs++;
}
if (!smmu->num_context_irqs) {
dev_err(dev, "found %d interrupts but expected at least %d\n",
num_irqs, smmu->num_global_irqs + 1);
return -ENODEV;
}
smmu->irqs = devm_kzalloc(dev, sizeof(*smmu->irqs) * num_irqs,
GFP_KERNEL);
if (!smmu->irqs) {
dev_err(dev, "failed to allocate %d irqs\n", num_irqs);
return -ENOMEM;
}
for (i = 0; i < num_irqs; ++i) {
int irq = platform_get_irq(pdev, i);
if (irq < 0) {
dev_err(dev, "failed to get irq index %d\n", i);
return -ENODEV;
}
smmu->irqs[i] = irq;
}
err = arm_smmu_device_cfg_probe(smmu);
if (err)
return err;
parse_driver_options(smmu);
if (smmu->version == ARM_SMMU_V2 &&
smmu->num_context_banks != smmu->num_context_irqs) {
dev_err(dev,
"found only %d context interrupt(s) but %d required\n",
smmu->num_context_irqs, smmu->num_context_banks);
return -ENODEV;
}
for (i = 0; i < smmu->num_global_irqs; ++i) {
err = devm_request_irq(smmu->dev, smmu->irqs[i],
arm_smmu_global_fault,
IRQF_SHARED,
"arm-smmu global fault",
smmu);
if (err) {
dev_err(dev, "failed to request global IRQ %d (%u)\n",
i, smmu->irqs[i]);
return err;
}
}
of_iommu_set_ops(dev->of_node, &arm_smmu_ops);
platform_set_drvdata(pdev, smmu);
arm_smmu_device_reset(smmu);
if (!iommu_present(&platform_bus_type))
bus_set_iommu(&platform_bus_type, &arm_smmu_ops);
#ifdef CONFIG_ARM_AMBA
if (!iommu_present(&amba_bustype))
bus_set_iommu(&amba_bustype, &arm_smmu_ops);
#endif
#ifdef CONFIG_PCI
if (!iommu_present(&pci_bus_type)) {
pci_request_acs();
bus_set_iommu(&pci_bus_type, &arm_smmu_ops);
}
#endif
return 0;
}
static int arm_smmu_device_remove(struct platform_device *pdev)
{
struct arm_smmu_device *smmu = platform_get_drvdata(pdev);
if (!smmu)
return -ENODEV;
if (!bitmap_empty(smmu->context_map, ARM_SMMU_MAX_CBS))
dev_err(&pdev->dev, "removing device with active domains!\n");
writel(sCR0_CLIENTPD, ARM_SMMU_GR0_NS(smmu) + ARM_SMMU_GR0_sCR0);
return 0;
}
static int __init arm_smmu_init(void)
{
static bool registered;
int ret = 0;
if (!registered) {
ret = platform_driver_register(&arm_smmu_driver);
registered = !ret;
}
return ret;
}
static void __exit arm_smmu_exit(void)
{
return platform_driver_unregister(&arm_smmu_driver);
}
static int __init arm_smmu_of_init(struct device_node *np)
{
int ret = arm_smmu_init();
if (ret)
return ret;
if (!of_platform_device_create(np, NULL, platform_bus_type.dev_root))
return -ENODEV;
return 0;
}
