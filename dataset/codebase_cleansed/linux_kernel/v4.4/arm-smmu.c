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
return bus->bridge->parent->of_node;
}
return dev->of_node;
}
static struct arm_smmu_master *find_smmu_master(struct arm_smmu_device *smmu,
struct device_node *dev_node)
{
struct rb_node *node = smmu->masters.rb_node;
while (node) {
struct arm_smmu_master *master;
master = container_of(node, struct arm_smmu_master, node);
if (dev_node < master->of_node)
node = node->rb_left;
else if (dev_node > master->of_node)
node = node->rb_right;
else
return master;
}
return NULL;
}
static struct arm_smmu_master_cfg *
find_smmu_master_cfg(struct device *dev)
{
struct arm_smmu_master_cfg *cfg = NULL;
struct iommu_group *group = iommu_group_get(dev);
if (group) {
cfg = iommu_group_get_iommudata(group);
iommu_group_put(group);
}
return cfg;
}
static int insert_smmu_master(struct arm_smmu_device *smmu,
struct arm_smmu_master *master)
{
struct rb_node **new, *parent;
new = &smmu->masters.rb_node;
parent = NULL;
while (*new) {
struct arm_smmu_master *this
= container_of(*new, struct arm_smmu_master, node);
parent = *new;
if (master->of_node < this->of_node)
new = &((*new)->rb_left);
else if (master->of_node > this->of_node)
new = &((*new)->rb_right);
else
return -EEXIST;
}
rb_link_node(&master->node, parent, new);
rb_insert_color(&master->node, &smmu->masters);
return 0;
}
static int register_smmu_master(struct arm_smmu_device *smmu,
struct device *dev,
struct of_phandle_args *masterspec)
{
int i;
struct arm_smmu_master *master;
master = find_smmu_master(smmu, masterspec->np);
if (master) {
dev_err(dev,
"rejecting multiple registrations for master device %s\n",
masterspec->np->name);
return -EBUSY;
}
if (masterspec->args_count > MAX_MASTER_STREAMIDS) {
dev_err(dev,
"reached maximum number (%d) of stream IDs for master device %s\n",
MAX_MASTER_STREAMIDS, masterspec->np->name);
return -ENOSPC;
}
master = devm_kzalloc(dev, sizeof(*master), GFP_KERNEL);
if (!master)
return -ENOMEM;
master->of_node = masterspec->np;
master->cfg.num_streamids = masterspec->args_count;
for (i = 0; i < master->cfg.num_streamids; ++i) {
u16 streamid = masterspec->args[i];
if (!(smmu->features & ARM_SMMU_FEAT_STREAM_MATCH) &&
(streamid >= smmu->num_mapping_groups)) {
dev_err(dev,
"stream ID for master device %s greater than maximum allowed (%d)\n",
masterspec->np->name, smmu->num_mapping_groups);
return -ERANGE;
}
master->cfg.streamids[i] = streamid;
}
return insert_smmu_master(smmu, master);
}
static struct arm_smmu_device *find_smmu_for_device(struct device *dev)
{
struct arm_smmu_device *smmu;
struct arm_smmu_master *master = NULL;
struct device_node *dev_node = dev_get_dev_node(dev);
spin_lock(&arm_smmu_devices_lock);
list_for_each_entry(smmu, &arm_smmu_devices, list) {
master = find_smmu_master(smmu, dev_node);
if (master)
break;
}
spin_unlock(&arm_smmu_devices_lock);
return master ? smmu : NULL;
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
writel_relaxed(ARM_SMMU_CB_ASID(cfg),
base + ARM_SMMU_CB_S1_TLBIASID);
} else {
base = ARM_SMMU_GR0(smmu);
writel_relaxed(ARM_SMMU_CB_VMID(cfg),
base + ARM_SMMU_GR0_TLBIVMID);
}
__arm_smmu_tlb_sync(smmu);
}
static void arm_smmu_tlb_inv_range_nosync(unsigned long iova, size_t size,
bool leaf, void *cookie)
{
struct arm_smmu_domain *smmu_domain = cookie;
struct arm_smmu_cfg *cfg = &smmu_domain->cfg;
struct arm_smmu_device *smmu = smmu_domain->smmu;
bool stage1 = cfg->cbar != CBAR_TYPE_S2_TRANS;
void __iomem *reg;
if (stage1) {
reg = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, cfg->cbndx);
reg += leaf ? ARM_SMMU_CB_S1_TLBIVAL : ARM_SMMU_CB_S1_TLBIVA;
if (!IS_ENABLED(CONFIG_64BIT) || smmu->version == ARM_SMMU_V1) {
iova &= ~12UL;
iova |= ARM_SMMU_CB_ASID(cfg);
writel_relaxed(iova, reg);
#ifdef CONFIG_64BIT
} else {
iova >>= 12;
iova |= (u64)ARM_SMMU_CB_ASID(cfg) << 48;
writeq_relaxed(iova, reg);
#endif
}
#ifdef CONFIG_64BIT
} else if (smmu->version == ARM_SMMU_V2) {
reg = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, cfg->cbndx);
reg += leaf ? ARM_SMMU_CB_S2_TLBIIPAS2L :
ARM_SMMU_CB_S2_TLBIIPAS2;
writeq_relaxed(iova >> 12, reg);
#endif
} else {
reg = ARM_SMMU_GR0(smmu) + ARM_SMMU_GR0_TLBIVMID;
writel_relaxed(ARM_SMMU_CB_VMID(cfg), reg);
}
}
static irqreturn_t arm_smmu_context_fault(int irq, void *dev)
{
int flags, ret;
u32 fsr, far, fsynr, resume;
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
if (fsr & FSR_IGN)
dev_err_ratelimited(smmu->dev,
"Unexpected context fault (fsr 0x%x)\n",
fsr);
fsynr = readl_relaxed(cb_base + ARM_SMMU_CB_FSYNR0);
flags = fsynr & FSYNR0_WNR ? IOMMU_FAULT_WRITE : IOMMU_FAULT_READ;
far = readl_relaxed(cb_base + ARM_SMMU_CB_FAR_LO);
iova = far;
#ifdef CONFIG_64BIT
far = readl_relaxed(cb_base + ARM_SMMU_CB_FAR_HI);
iova |= ((unsigned long)far << 32);
#endif
if (!report_iommu_fault(domain, smmu->dev, iova, flags)) {
ret = IRQ_HANDLED;
resume = RESUME_RETRY;
} else {
dev_err_ratelimited(smmu->dev,
"Unhandled context fault: iova=0x%08lx, fsynr=0x%x, cb=%d\n",
iova, fsynr, cfg->cbndx);
ret = IRQ_NONE;
resume = RESUME_TERMINATE;
}
writel(fsr, cb_base + ARM_SMMU_CB_FSR);
if (fsr & FSR_SS)
writel_relaxed(resume, cb_base + ARM_SMMU_CB_RESUME);
return ret;
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
u32 reg;
u64 reg64;
bool stage1;
struct arm_smmu_cfg *cfg = &smmu_domain->cfg;
struct arm_smmu_device *smmu = smmu_domain->smmu;
void __iomem *cb_base, *gr1_base;
gr1_base = ARM_SMMU_GR1(smmu);
stage1 = cfg->cbar != CBAR_TYPE_S2_TRANS;
cb_base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, cfg->cbndx);
if (smmu->version > ARM_SMMU_V1) {
#ifdef CONFIG_64BIT
reg = CBA2R_RW64_64BIT;
#else
reg = CBA2R_RW64_32BIT;
#endif
writel_relaxed(reg, gr1_base + ARM_SMMU_GR1_CBA2R(cfg->cbndx));
}
reg = cfg->cbar;
if (smmu->version == ARM_SMMU_V1)
reg |= cfg->irptndx << CBAR_IRPTNDX_SHIFT;
if (stage1) {
reg |= (CBAR_S1_BPSHCFG_NSH << CBAR_S1_BPSHCFG_SHIFT) |
(CBAR_S1_MEMATTR_WB << CBAR_S1_MEMATTR_SHIFT);
} else {
reg |= ARM_SMMU_CB_VMID(cfg) << CBAR_VMID_SHIFT;
}
writel_relaxed(reg, gr1_base + ARM_SMMU_GR1_CBAR(cfg->cbndx));
if (stage1) {
reg64 = pgtbl_cfg->arm_lpae_s1_cfg.ttbr[0];
reg64 |= ((u64)ARM_SMMU_CB_ASID(cfg)) << TTBRn_ASID_SHIFT;
smmu_writeq(reg64, cb_base + ARM_SMMU_CB_TTBR0);
reg64 = pgtbl_cfg->arm_lpae_s1_cfg.ttbr[1];
reg64 |= ((u64)ARM_SMMU_CB_ASID(cfg)) << TTBRn_ASID_SHIFT;
smmu_writeq(reg64, cb_base + ARM_SMMU_CB_TTBR1);
} else {
reg64 = pgtbl_cfg->arm_lpae_s2_cfg.vttbr;
smmu_writeq(reg64, cb_base + ARM_SMMU_CB_TTBR0);
}
if (stage1) {
reg = pgtbl_cfg->arm_lpae_s1_cfg.tcr;
writel_relaxed(reg, cb_base + ARM_SMMU_CB_TTBCR);
if (smmu->version > ARM_SMMU_V1) {
reg = pgtbl_cfg->arm_lpae_s1_cfg.tcr >> 32;
reg |= TTBCR2_SEP_UPSTREAM;
writel_relaxed(reg, cb_base + ARM_SMMU_CB_TTBCR2);
}
} else {
reg = pgtbl_cfg->arm_lpae_s2_cfg.vtcr;
writel_relaxed(reg, cb_base + ARM_SMMU_CB_TTBCR);
}
if (stage1) {
reg = pgtbl_cfg->arm_lpae_s1_cfg.mair[0];
writel_relaxed(reg, cb_base + ARM_SMMU_CB_S1_MAIR0);
reg = pgtbl_cfg->arm_lpae_s1_cfg.mair[1];
writel_relaxed(reg, cb_base + ARM_SMMU_CB_S1_MAIR1);
}
reg = SCTLR_CFCFG | SCTLR_CFIE | SCTLR_CFRE | SCTLR_M | SCTLR_EAE_SBOP;
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
switch (smmu_domain->stage) {
case ARM_SMMU_DOMAIN_S1:
cfg->cbar = CBAR_TYPE_S1_TRANS_S2_BYPASS;
start = smmu->num_s2_context_banks;
ias = smmu->va_size;
oas = smmu->ipa_size;
if (IS_ENABLED(CONFIG_64BIT))
fmt = ARM_64_LPAE_S1;
else
fmt = ARM_32_LPAE_S1;
break;
case ARM_SMMU_DOMAIN_NESTED:
case ARM_SMMU_DOMAIN_S2:
cfg->cbar = CBAR_TYPE_S2_TRANS;
start = 0;
ias = smmu->ipa_size;
oas = smmu->pa_size;
if (IS_ENABLED(CONFIG_64BIT))
fmt = ARM_64_LPAE_S2;
else
fmt = ARM_32_LPAE_S2;
break;
default:
ret = -EINVAL;
goto out_unlock;
}
ret = __arm_smmu_alloc_bitmap(smmu->context_map, start,
smmu->num_context_banks);
if (IS_ERR_VALUE(ret))
goto out_unlock;
cfg->cbndx = ret;
if (smmu->version == ARM_SMMU_V1) {
cfg->irptndx = atomic_inc_return(&smmu->irptndx);
cfg->irptndx %= smmu->num_context_irqs;
} else {
cfg->irptndx = cfg->cbndx;
}
pgtbl_cfg = (struct io_pgtable_cfg) {
.pgsize_bitmap = arm_smmu_ops.pgsize_bitmap,
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
arm_smmu_ops.pgsize_bitmap = pgtbl_cfg.pgsize_bitmap;
arm_smmu_init_context_bank(smmu_domain, &pgtbl_cfg);
irq = smmu->irqs[smmu->num_global_irqs + cfg->irptndx];
ret = request_irq(irq, arm_smmu_context_fault, IRQF_SHARED,
"arm-smmu-context-fault", domain);
if (IS_ERR_VALUE(ret)) {
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
free_irq(irq, domain);
}
if (smmu_domain->pgtbl_ops)
free_io_pgtable_ops(smmu_domain->pgtbl_ops);
__arm_smmu_free_bitmap(smmu->context_map, cfg->cbndx);
}
static struct iommu_domain *arm_smmu_domain_alloc(unsigned type)
{
struct arm_smmu_domain *smmu_domain;
if (type != IOMMU_DOMAIN_UNMANAGED)
return NULL;
smmu_domain = kzalloc(sizeof(*smmu_domain), GFP_KERNEL);
if (!smmu_domain)
return NULL;
mutex_init(&smmu_domain->init_mutex);
spin_lock_init(&smmu_domain->pgtbl_lock);
return &smmu_domain->domain;
}
static void arm_smmu_domain_free(struct iommu_domain *domain)
{
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
arm_smmu_destroy_domain_context(domain);
kfree(smmu_domain);
}
static int arm_smmu_master_configure_smrs(struct arm_smmu_device *smmu,
struct arm_smmu_master_cfg *cfg)
{
int i;
struct arm_smmu_smr *smrs;
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
if (!(smmu->features & ARM_SMMU_FEAT_STREAM_MATCH))
return 0;
if (cfg->smrs)
return -EEXIST;
smrs = kmalloc_array(cfg->num_streamids, sizeof(*smrs), GFP_KERNEL);
if (!smrs) {
dev_err(smmu->dev, "failed to allocate %d SMRs\n",
cfg->num_streamids);
return -ENOMEM;
}
for (i = 0; i < cfg->num_streamids; ++i) {
int idx = __arm_smmu_alloc_bitmap(smmu->smr_map, 0,
smmu->num_mapping_groups);
if (IS_ERR_VALUE(idx)) {
dev_err(smmu->dev, "failed to allocate free SMR\n");
goto err_free_smrs;
}
smrs[i] = (struct arm_smmu_smr) {
.idx = idx,
.mask = 0,
.id = cfg->streamids[i],
};
}
for (i = 0; i < cfg->num_streamids; ++i) {
u32 reg = SMR_VALID | smrs[i].id << SMR_ID_SHIFT |
smrs[i].mask << SMR_MASK_SHIFT;
writel_relaxed(reg, gr0_base + ARM_SMMU_GR0_SMR(smrs[i].idx));
}
cfg->smrs = smrs;
return 0;
err_free_smrs:
while (--i >= 0)
__arm_smmu_free_bitmap(smmu->smr_map, smrs[i].idx);
kfree(smrs);
return -ENOSPC;
}
static void arm_smmu_master_free_smrs(struct arm_smmu_device *smmu,
struct arm_smmu_master_cfg *cfg)
{
int i;
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
struct arm_smmu_smr *smrs = cfg->smrs;
if (!smrs)
return;
for (i = 0; i < cfg->num_streamids; ++i) {
u8 idx = smrs[i].idx;
writel_relaxed(~SMR_VALID, gr0_base + ARM_SMMU_GR0_SMR(idx));
__arm_smmu_free_bitmap(smmu->smr_map, idx);
}
cfg->smrs = NULL;
kfree(smrs);
}
static int arm_smmu_domain_add_master(struct arm_smmu_domain *smmu_domain,
struct arm_smmu_master_cfg *cfg)
{
int i, ret;
struct arm_smmu_device *smmu = smmu_domain->smmu;
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
ret = arm_smmu_master_configure_smrs(smmu, cfg);
if (ret)
return ret == -EEXIST ? 0 : ret;
for (i = 0; i < cfg->num_streamids; ++i) {
u32 idx, s2cr;
idx = cfg->smrs ? cfg->smrs[i].idx : cfg->streamids[i];
s2cr = S2CR_TYPE_TRANS |
(smmu_domain->cfg.cbndx << S2CR_CBNDX_SHIFT);
writel_relaxed(s2cr, gr0_base + ARM_SMMU_GR0_S2CR(idx));
}
return 0;
}
static void arm_smmu_domain_remove_master(struct arm_smmu_domain *smmu_domain,
struct arm_smmu_master_cfg *cfg)
{
int i;
struct arm_smmu_device *smmu = smmu_domain->smmu;
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
if ((smmu->features & ARM_SMMU_FEAT_STREAM_MATCH) && !cfg->smrs)
return;
for (i = 0; i < cfg->num_streamids; ++i) {
u32 idx = cfg->smrs ? cfg->smrs[i].idx : cfg->streamids[i];
writel_relaxed(S2CR_TYPE_BYPASS,
gr0_base + ARM_SMMU_GR0_S2CR(idx));
}
arm_smmu_master_free_smrs(smmu, cfg);
}
static int arm_smmu_attach_dev(struct iommu_domain *domain, struct device *dev)
{
int ret;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct arm_smmu_device *smmu;
struct arm_smmu_master_cfg *cfg;
smmu = find_smmu_for_device(dev);
if (!smmu) {
dev_err(dev, "cannot attach to SMMU, is it on the same bus?\n");
return -ENXIO;
}
if (dev->archdata.iommu) {
dev_err(dev, "already attached to IOMMU domain\n");
return -EEXIST;
}
ret = arm_smmu_init_domain_context(domain, smmu);
if (IS_ERR_VALUE(ret))
return ret;
if (smmu_domain->smmu != smmu) {
dev_err(dev,
"cannot attach to SMMU %s whilst already attached to domain on SMMU %s\n",
dev_name(smmu_domain->smmu->dev), dev_name(smmu->dev));
return -EINVAL;
}
cfg = find_smmu_master_cfg(dev);
if (!cfg)
return -ENODEV;
ret = arm_smmu_domain_add_master(smmu_domain, cfg);
if (!ret)
dev->archdata.iommu = domain;
return ret;
}
static void arm_smmu_detach_dev(struct iommu_domain *domain, struct device *dev)
{
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct arm_smmu_master_cfg *cfg;
cfg = find_smmu_master_cfg(dev);
if (!cfg)
return;
dev->archdata.iommu = NULL;
arm_smmu_domain_remove_master(smmu_domain, cfg);
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
smmu_writeq(va, cb_base + ARM_SMMU_CB_ATS1PR);
else
writel_relaxed(va, cb_base + ARM_SMMU_CB_ATS1PR);
if (readl_poll_timeout_atomic(cb_base + ARM_SMMU_CB_ATSR, tmp,
!(tmp & ATSR_ACTIVE), 5, 50)) {
dev_err(dev,
"iova to phys timed out on %pad. Falling back to software table walk.\n",
&iova);
return ops->iova_to_phys(ops, iova);
}
phys = readl_relaxed(cb_base + ARM_SMMU_CB_PAR_LO);
phys |= ((u64)readl_relaxed(cb_base + ARM_SMMU_CB_PAR_HI)) << 32;
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
static int __arm_smmu_get_pci_sid(struct pci_dev *pdev, u16 alias, void *data)
{
*((u16 *)data) = alias;
return 0;
}
static void __arm_smmu_release_pci_iommudata(void *data)
{
kfree(data);
}
static int arm_smmu_init_pci_device(struct pci_dev *pdev,
struct iommu_group *group)
{
struct arm_smmu_master_cfg *cfg;
u16 sid;
int i;
cfg = iommu_group_get_iommudata(group);
if (!cfg) {
cfg = kzalloc(sizeof(*cfg), GFP_KERNEL);
if (!cfg)
return -ENOMEM;
iommu_group_set_iommudata(group, cfg,
__arm_smmu_release_pci_iommudata);
}
if (cfg->num_streamids >= MAX_MASTER_STREAMIDS)
return -ENOSPC;
pci_for_each_dma_alias(pdev, __arm_smmu_get_pci_sid, &sid);
for (i = 0; i < cfg->num_streamids; ++i)
if (cfg->streamids[i] == sid)
break;
if (i == cfg->num_streamids)
cfg->streamids[cfg->num_streamids++] = sid;
return 0;
}
static int arm_smmu_init_platform_device(struct device *dev,
struct iommu_group *group)
{
struct arm_smmu_device *smmu = find_smmu_for_device(dev);
struct arm_smmu_master *master;
if (!smmu)
return -ENODEV;
master = find_smmu_master(smmu, dev->of_node);
if (!master)
return -ENODEV;
iommu_group_set_iommudata(group, &master->cfg, NULL);
return 0;
}
static int arm_smmu_add_device(struct device *dev)
{
struct iommu_group *group;
group = iommu_group_get_for_dev(dev);
if (IS_ERR(group))
return PTR_ERR(group);
return 0;
}
static void arm_smmu_remove_device(struct device *dev)
{
iommu_group_remove_device(dev);
}
static struct iommu_group *arm_smmu_device_group(struct device *dev)
{
struct iommu_group *group;
int ret;
if (dev_is_pci(dev))
group = pci_device_group(dev);
else
group = generic_device_group(dev);
if (IS_ERR(group))
return group;
if (dev_is_pci(dev))
ret = arm_smmu_init_pci_device(to_pci_dev(dev), group);
else
ret = arm_smmu_init_platform_device(dev, group);
if (ret) {
iommu_group_put(group);
group = ERR_PTR(ret);
}
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
static void arm_smmu_device_reset(struct arm_smmu_device *smmu)
{
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
void __iomem *cb_base;
int i = 0;
u32 reg;
reg = readl_relaxed(ARM_SMMU_GR0_NS(smmu) + ARM_SMMU_GR0_sGFSR);
writel(reg, ARM_SMMU_GR0_NS(smmu) + ARM_SMMU_GR0_sGFSR);
for (i = 0; i < smmu->num_mapping_groups; ++i) {
writel_relaxed(0, gr0_base + ARM_SMMU_GR0_SMR(i));
writel_relaxed(S2CR_TYPE_BYPASS,
gr0_base + ARM_SMMU_GR0_S2CR(i));
}
for (i = 0; i < smmu->num_context_banks; ++i) {
cb_base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, i);
writel_relaxed(0, cb_base + ARM_SMMU_CB_SCTLR);
writel_relaxed(FSR_FAULT, cb_base + ARM_SMMU_CB_FSR);
}
writel_relaxed(0, gr0_base + ARM_SMMU_GR0_TLBIALLH);
writel_relaxed(0, gr0_base + ARM_SMMU_GR0_TLBIALLNSNH);
reg = readl_relaxed(ARM_SMMU_GR0_NS(smmu) + ARM_SMMU_GR0_sCR0);
reg |= (sCR0_GFRE | sCR0_GFIE | sCR0_GCFGFRE | sCR0_GCFGFIE);
reg |= (sCR0_VMIDPNE | sCR0_PTM);
reg &= ~(sCR0_CLIENTPD | sCR0_USFCFG);
reg &= ~sCR0_FB;
reg &= ~(sCR0_BSU_MASK << sCR0_BSU_SHIFT);
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
dev_notice(smmu->dev, "probing hardware configuration...\n");
dev_notice(smmu->dev, "SMMUv%d with:\n", smmu->version);
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
if ((id & ID0_S1TS) && ((smmu->version == 1) || !(id & ID0_ATOSNS))) {
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
if (id & ID0_SMS) {
u32 smr, sid, mask;
smmu->features |= ARM_SMMU_FEAT_STREAM_MATCH;
smmu->num_mapping_groups = (id >> ID0_NUMSMRG_SHIFT) &
ID0_NUMSMRG_MASK;
if (smmu->num_mapping_groups == 0) {
dev_err(smmu->dev,
"stream-matching supported, but no SMRs present!\n");
return -ENODEV;
}
smr = SMR_MASK_MASK << SMR_MASK_SHIFT;
smr |= (SMR_ID_MASK << SMR_ID_SHIFT);
writel_relaxed(smr, gr0_base + ARM_SMMU_GR0_SMR(0));
smr = readl_relaxed(gr0_base + ARM_SMMU_GR0_SMR(0));
mask = (smr >> SMR_MASK_SHIFT) & SMR_MASK_MASK;
sid = (smr >> SMR_ID_SHIFT) & SMR_ID_MASK;
if ((mask & sid) != sid) {
dev_err(smmu->dev,
"SMR mask bits (0x%x) insufficient for ID field (0x%x)\n",
mask, sid);
return -ENODEV;
}
dev_notice(smmu->dev,
"\tstream matching with %u register groups, mask 0x%x",
smmu->num_mapping_groups, mask);
} else {
smmu->num_mapping_groups = (id >> ID0_NUMSIDB_SHIFT) &
ID0_NUMSIDB_MASK;
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
id = readl_relaxed(gr0_base + ARM_SMMU_GR0_ID2);
size = arm_smmu_id_size_to_bits((id >> ID2_IAS_SHIFT) & ID2_IAS_MASK);
smmu->ipa_size = size;
size = arm_smmu_id_size_to_bits((id >> ID2_OAS_SHIFT) & ID2_OAS_MASK);
smmu->pa_size = size;
if (dma_set_mask_and_coherent(smmu->dev, DMA_BIT_MASK(size)))
dev_warn(smmu->dev,
"failed to set DMA mask for table walker\n");
if (smmu->version == ARM_SMMU_V1) {
smmu->va_size = smmu->ipa_size;
size = SZ_4K | SZ_2M | SZ_1G;
} else {
size = (id >> ID2_UBS_SHIFT) & ID2_UBS_MASK;
smmu->va_size = arm_smmu_id_size_to_bits(size);
#ifndef CONFIG_64BIT
smmu->va_size = min(32UL, smmu->va_size);
#endif
size = 0;
if (id & ID2_PTFS_4K)
size |= SZ_4K | SZ_2M | SZ_1G;
if (id & ID2_PTFS_16K)
size |= SZ_16K | SZ_32M;
if (id & ID2_PTFS_64K)
size |= SZ_64K | SZ_512M;
}
arm_smmu_ops.pgsize_bitmap &= size;
dev_notice(smmu->dev, "\tSupported page sizes: 0x%08lx\n", size);
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
const struct of_device_id *of_id;
struct resource *res;
struct arm_smmu_device *smmu;
struct device *dev = &pdev->dev;
struct rb_node *node;
struct of_phandle_args masterspec;
int num_irqs, i, err;
smmu = devm_kzalloc(dev, sizeof(*smmu), GFP_KERNEL);
if (!smmu) {
dev_err(dev, "failed to allocate arm_smmu_device\n");
return -ENOMEM;
}
smmu->dev = dev;
of_id = of_match_node(arm_smmu_of_match, dev->of_node);
smmu->version = (enum arm_smmu_arch_version)of_id->data;
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
i = 0;
smmu->masters = RB_ROOT;
while (!of_parse_phandle_with_args(dev->of_node, "mmu-masters",
"#stream-id-cells", i,
&masterspec)) {
err = register_smmu_master(smmu, dev, &masterspec);
if (err) {
dev_err(dev, "failed to add master %s\n",
masterspec.np->name);
goto out_put_masters;
}
i++;
}
dev_notice(dev, "registered %d master devices\n", i);
parse_driver_options(smmu);
if (smmu->version > ARM_SMMU_V1 &&
smmu->num_context_banks != smmu->num_context_irqs) {
dev_err(dev,
"found only %d context interrupt(s) but %d required\n",
smmu->num_context_irqs, smmu->num_context_banks);
err = -ENODEV;
goto out_put_masters;
}
for (i = 0; i < smmu->num_global_irqs; ++i) {
err = request_irq(smmu->irqs[i],
arm_smmu_global_fault,
IRQF_SHARED,
"arm-smmu global fault",
smmu);
if (err) {
dev_err(dev, "failed to request global IRQ %d (%u)\n",
i, smmu->irqs[i]);
goto out_free_irqs;
}
}
INIT_LIST_HEAD(&smmu->list);
spin_lock(&arm_smmu_devices_lock);
list_add(&smmu->list, &arm_smmu_devices);
spin_unlock(&arm_smmu_devices_lock);
arm_smmu_device_reset(smmu);
return 0;
out_free_irqs:
while (i--)
free_irq(smmu->irqs[i], smmu);
out_put_masters:
for (node = rb_first(&smmu->masters); node; node = rb_next(node)) {
struct arm_smmu_master *master
= container_of(node, struct arm_smmu_master, node);
of_node_put(master->of_node);
}
return err;
}
static int arm_smmu_device_remove(struct platform_device *pdev)
{
int i;
struct device *dev = &pdev->dev;
struct arm_smmu_device *curr, *smmu = NULL;
struct rb_node *node;
spin_lock(&arm_smmu_devices_lock);
list_for_each_entry(curr, &arm_smmu_devices, list) {
if (curr->dev == dev) {
smmu = curr;
list_del(&smmu->list);
break;
}
}
spin_unlock(&arm_smmu_devices_lock);
if (!smmu)
return -ENODEV;
for (node = rb_first(&smmu->masters); node; node = rb_next(node)) {
struct arm_smmu_master *master
= container_of(node, struct arm_smmu_master, node);
of_node_put(master->of_node);
}
if (!bitmap_empty(smmu->context_map, ARM_SMMU_MAX_CBS))
dev_err(dev, "removing device with active domains!\n");
for (i = 0; i < smmu->num_global_irqs; ++i)
free_irq(smmu->irqs[i], smmu);
writel(sCR0_CLIENTPD, ARM_SMMU_GR0_NS(smmu) + ARM_SMMU_GR0_sCR0);
return 0;
}
static int __init arm_smmu_init(void)
{
struct device_node *np;
int ret;
np = of_find_matching_node(NULL, arm_smmu_of_match);
if (!np)
return 0;
of_node_put(np);
ret = platform_driver_register(&arm_smmu_driver);
if (ret)
return ret;
if (!iommu_present(&platform_bus_type))
bus_set_iommu(&platform_bus_type, &arm_smmu_ops);
#ifdef CONFIG_ARM_AMBA
if (!iommu_present(&amba_bustype))
bus_set_iommu(&amba_bustype, &arm_smmu_ops);
#endif
#ifdef CONFIG_PCI
if (!iommu_present(&pci_bus_type))
bus_set_iommu(&pci_bus_type, &arm_smmu_ops);
#endif
return 0;
}
static void __exit arm_smmu_exit(void)
{
return platform_driver_unregister(&arm_smmu_driver);
}
