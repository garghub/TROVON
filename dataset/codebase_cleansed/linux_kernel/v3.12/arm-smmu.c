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
static int insert_smmu_master(struct arm_smmu_device *smmu,
struct arm_smmu_master *master)
{
struct rb_node **new, *parent;
new = &smmu->masters.rb_node;
parent = NULL;
while (*new) {
struct arm_smmu_master *this;
this = container_of(*new, struct arm_smmu_master, node);
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
master->num_streamids = masterspec->args_count;
for (i = 0; i < master->num_streamids; ++i)
master->streamids[i] = masterspec->args[i];
return insert_smmu_master(smmu, master);
}
static struct arm_smmu_device *find_parent_smmu(struct arm_smmu_device *smmu)
{
struct arm_smmu_device *parent;
if (!smmu->parent_of_node)
return NULL;
spin_lock(&arm_smmu_devices_lock);
list_for_each_entry(parent, &arm_smmu_devices, list)
if (parent->dev->of_node == smmu->parent_of_node)
goto out_unlock;
parent = NULL;
dev_warn(smmu->dev,
"Failed to find SMMU parent despite parent in DT\n");
out_unlock:
spin_unlock(&arm_smmu_devices_lock);
return parent;
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
static void arm_smmu_tlb_sync(struct arm_smmu_device *smmu)
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
static void arm_smmu_tlb_inv_context(struct arm_smmu_cfg *cfg)
{
struct arm_smmu_device *smmu = cfg->smmu;
void __iomem *base = ARM_SMMU_GR0(smmu);
bool stage1 = cfg->cbar != CBAR_TYPE_S2_TRANS;
if (stage1) {
base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, cfg->cbndx);
writel_relaxed(ARM_SMMU_CB_ASID(cfg),
base + ARM_SMMU_CB_S1_TLBIASID);
} else {
base = ARM_SMMU_GR0(smmu);
writel_relaxed(ARM_SMMU_CB_VMID(cfg),
base + ARM_SMMU_GR0_TLBIVMID);
}
arm_smmu_tlb_sync(smmu);
}
static irqreturn_t arm_smmu_context_fault(int irq, void *dev)
{
int flags, ret;
u32 fsr, far, fsynr, resume;
unsigned long iova;
struct iommu_domain *domain = dev;
struct arm_smmu_domain *smmu_domain = domain->priv;
struct arm_smmu_cfg *root_cfg = &smmu_domain->root_cfg;
struct arm_smmu_device *smmu = root_cfg->smmu;
void __iomem *cb_base;
cb_base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, root_cfg->cbndx);
fsr = readl_relaxed(cb_base + ARM_SMMU_CB_FSR);
if (!(fsr & FSR_FAULT))
return IRQ_NONE;
if (fsr & FSR_IGN)
dev_err_ratelimited(smmu->dev,
"Unexpected context fault (fsr 0x%u)\n",
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
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
gfsr = readl_relaxed(gr0_base + ARM_SMMU_GR0_sGFSR);
if (!gfsr)
return IRQ_NONE;
gfsynr0 = readl_relaxed(gr0_base + ARM_SMMU_GR0_sGFSYNR0);
gfsynr1 = readl_relaxed(gr0_base + ARM_SMMU_GR0_sGFSYNR1);
gfsynr2 = readl_relaxed(gr0_base + ARM_SMMU_GR0_sGFSYNR2);
dev_err_ratelimited(smmu->dev,
"Unexpected global fault, this could be serious\n");
dev_err_ratelimited(smmu->dev,
"\tGFSR 0x%08x, GFSYNR0 0x%08x, GFSYNR1 0x%08x, GFSYNR2 0x%08x\n",
gfsr, gfsynr0, gfsynr1, gfsynr2);
writel(gfsr, gr0_base + ARM_SMMU_GR0_sGFSR);
return IRQ_HANDLED;
}
static void arm_smmu_init_context_bank(struct arm_smmu_domain *smmu_domain)
{
u32 reg;
bool stage1;
struct arm_smmu_cfg *root_cfg = &smmu_domain->root_cfg;
struct arm_smmu_device *smmu = root_cfg->smmu;
void __iomem *cb_base, *gr0_base, *gr1_base;
gr0_base = ARM_SMMU_GR0(smmu);
gr1_base = ARM_SMMU_GR1(smmu);
stage1 = root_cfg->cbar != CBAR_TYPE_S2_TRANS;
cb_base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, root_cfg->cbndx);
reg = root_cfg->cbar;
if (smmu->version == 1)
reg |= root_cfg->irptndx << CBAR_IRPTNDX_SHIFT;
if (stage1)
reg |= (CBAR_S1_MEMATTR_WB << CBAR_S1_MEMATTR_SHIFT);
else
reg |= ARM_SMMU_CB_VMID(root_cfg) << CBAR_VMID_SHIFT;
writel_relaxed(reg, gr1_base + ARM_SMMU_GR1_CBAR(root_cfg->cbndx));
if (smmu->version > 1) {
#ifdef CONFIG_64BIT
reg = CBA2R_RW64_64BIT;
#else
reg = CBA2R_RW64_32BIT;
#endif
writel_relaxed(reg,
gr1_base + ARM_SMMU_GR1_CBA2R(root_cfg->cbndx));
switch (smmu->input_size) {
case 32:
reg = (TTBCR2_ADDR_32 << TTBCR2_SEP_SHIFT);
break;
case 36:
reg = (TTBCR2_ADDR_36 << TTBCR2_SEP_SHIFT);
break;
case 39:
reg = (TTBCR2_ADDR_40 << TTBCR2_SEP_SHIFT);
break;
case 42:
reg = (TTBCR2_ADDR_42 << TTBCR2_SEP_SHIFT);
break;
case 44:
reg = (TTBCR2_ADDR_44 << TTBCR2_SEP_SHIFT);
break;
case 48:
reg = (TTBCR2_ADDR_48 << TTBCR2_SEP_SHIFT);
break;
}
switch (smmu->s1_output_size) {
case 32:
reg |= (TTBCR2_ADDR_32 << TTBCR2_PASIZE_SHIFT);
break;
case 36:
reg |= (TTBCR2_ADDR_36 << TTBCR2_PASIZE_SHIFT);
break;
case 39:
reg |= (TTBCR2_ADDR_40 << TTBCR2_PASIZE_SHIFT);
break;
case 42:
reg |= (TTBCR2_ADDR_42 << TTBCR2_PASIZE_SHIFT);
break;
case 44:
reg |= (TTBCR2_ADDR_44 << TTBCR2_PASIZE_SHIFT);
break;
case 48:
reg |= (TTBCR2_ADDR_48 << TTBCR2_PASIZE_SHIFT);
break;
}
if (stage1)
writel_relaxed(reg, cb_base + ARM_SMMU_CB_TTBCR2);
}
reg = __pa(root_cfg->pgd);
writel_relaxed(reg, cb_base + ARM_SMMU_CB_TTBR0_LO);
reg = (phys_addr_t)__pa(root_cfg->pgd) >> 32;
if (stage1)
reg |= ARM_SMMU_CB_ASID(root_cfg) << TTBRn_HI_ASID_SHIFT;
writel_relaxed(reg, cb_base + ARM_SMMU_CB_TTBR0_HI);
if (smmu->version > 1) {
if (PAGE_SIZE == SZ_4K)
reg = TTBCR_TG0_4K;
else
reg = TTBCR_TG0_64K;
if (!stage1) {
switch (smmu->s2_output_size) {
case 32:
reg |= (TTBCR2_ADDR_32 << TTBCR_PASIZE_SHIFT);
break;
case 36:
reg |= (TTBCR2_ADDR_36 << TTBCR_PASIZE_SHIFT);
break;
case 40:
reg |= (TTBCR2_ADDR_40 << TTBCR_PASIZE_SHIFT);
break;
case 42:
reg |= (TTBCR2_ADDR_42 << TTBCR_PASIZE_SHIFT);
break;
case 44:
reg |= (TTBCR2_ADDR_44 << TTBCR_PASIZE_SHIFT);
break;
case 48:
reg |= (TTBCR2_ADDR_48 << TTBCR_PASIZE_SHIFT);
break;
}
} else {
reg |= (64 - smmu->s1_output_size) << TTBCR_T0SZ_SHIFT;
}
} else {
reg = 0;
}
reg |= TTBCR_EAE |
(TTBCR_SH_IS << TTBCR_SH0_SHIFT) |
(TTBCR_RGN_WBWA << TTBCR_ORGN0_SHIFT) |
(TTBCR_RGN_WBWA << TTBCR_IRGN0_SHIFT) |
(TTBCR_SL0_LVL_1 << TTBCR_SL0_SHIFT);
writel_relaxed(reg, cb_base + ARM_SMMU_CB_TTBCR);
if (stage1) {
reg = (MAIR_ATTR_NC << MAIR_ATTR_SHIFT(MAIR_ATTR_IDX_NC)) |
(MAIR_ATTR_WBRWA << MAIR_ATTR_SHIFT(MAIR_ATTR_IDX_CACHE)) |
(MAIR_ATTR_DEVICE << MAIR_ATTR_SHIFT(MAIR_ATTR_IDX_DEV));
writel_relaxed(reg, cb_base + ARM_SMMU_CB_S1_MAIR0);
}
reg = SCTLR_CFCFG | SCTLR_CFIE | SCTLR_CFRE | SCTLR_M | SCTLR_EAE_SBOP;
if (stage1)
reg |= SCTLR_S1_ASIDPNE;
#ifdef __BIG_ENDIAN
reg |= SCTLR_E;
#endif
writel(reg, cb_base + ARM_SMMU_CB_SCTLR);
}
static int arm_smmu_init_domain_context(struct iommu_domain *domain,
struct device *dev)
{
int irq, ret, start;
struct arm_smmu_domain *smmu_domain = domain->priv;
struct arm_smmu_cfg *root_cfg = &smmu_domain->root_cfg;
struct arm_smmu_device *smmu, *parent;
parent = dev->archdata.iommu;
smmu_domain->output_mask = -1;
do {
smmu = parent;
smmu_domain->output_mask &= (1ULL << smmu->s2_output_size) - 1;
} while ((parent = find_parent_smmu(smmu)));
if (!find_smmu_master(smmu, dev->of_node)) {
dev_err(dev, "unable to find root SMMU for device\n");
return -ENODEV;
}
if (smmu->features & ARM_SMMU_FEAT_TRANS_NESTED) {
root_cfg->cbar = CBAR_TYPE_S1_TRANS_S2_BYPASS;
start = smmu->num_s2_context_banks;
} else if (smmu->features & ARM_SMMU_FEAT_TRANS_S2) {
root_cfg->cbar = CBAR_TYPE_S2_TRANS;
start = 0;
} else {
root_cfg->cbar = CBAR_TYPE_S1_TRANS_S2_BYPASS;
start = smmu->num_s2_context_banks;
}
ret = __arm_smmu_alloc_bitmap(smmu->context_map, start,
smmu->num_context_banks);
if (IS_ERR_VALUE(ret))
return ret;
root_cfg->cbndx = ret;
if (smmu->version == 1) {
root_cfg->irptndx = atomic_inc_return(&smmu->irptndx);
root_cfg->irptndx %= smmu->num_context_irqs;
} else {
root_cfg->irptndx = root_cfg->cbndx;
}
irq = smmu->irqs[smmu->num_global_irqs + root_cfg->irptndx];
ret = request_irq(irq, arm_smmu_context_fault, IRQF_SHARED,
"arm-smmu-context-fault", domain);
if (IS_ERR_VALUE(ret)) {
dev_err(smmu->dev, "failed to request context IRQ %d (%u)\n",
root_cfg->irptndx, irq);
root_cfg->irptndx = INVALID_IRPTNDX;
goto out_free_context;
}
root_cfg->smmu = smmu;
arm_smmu_init_context_bank(smmu_domain);
return ret;
out_free_context:
__arm_smmu_free_bitmap(smmu->context_map, root_cfg->cbndx);
return ret;
}
static void arm_smmu_destroy_domain_context(struct iommu_domain *domain)
{
struct arm_smmu_domain *smmu_domain = domain->priv;
struct arm_smmu_cfg *root_cfg = &smmu_domain->root_cfg;
struct arm_smmu_device *smmu = root_cfg->smmu;
void __iomem *cb_base;
int irq;
if (!smmu)
return;
cb_base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB(smmu, root_cfg->cbndx);
writel_relaxed(0, cb_base + ARM_SMMU_CB_SCTLR);
arm_smmu_tlb_inv_context(root_cfg);
if (root_cfg->irptndx != INVALID_IRPTNDX) {
irq = smmu->irqs[smmu->num_global_irqs + root_cfg->irptndx];
free_irq(irq, domain);
}
__arm_smmu_free_bitmap(smmu->context_map, root_cfg->cbndx);
}
static int arm_smmu_domain_init(struct iommu_domain *domain)
{
struct arm_smmu_domain *smmu_domain;
pgd_t *pgd;
smmu_domain = kzalloc(sizeof(*smmu_domain), GFP_KERNEL);
if (!smmu_domain)
return -ENOMEM;
pgd = kzalloc(PTRS_PER_PGD * sizeof(pgd_t), GFP_KERNEL);
if (!pgd)
goto out_free_domain;
smmu_domain->root_cfg.pgd = pgd;
spin_lock_init(&smmu_domain->lock);
domain->priv = smmu_domain;
return 0;
out_free_domain:
kfree(smmu_domain);
return -ENOMEM;
}
static void arm_smmu_free_ptes(pmd_t *pmd)
{
pgtable_t table = pmd_pgtable(*pmd);
pgtable_page_dtor(table);
__free_page(table);
}
static void arm_smmu_free_pmds(pud_t *pud)
{
int i;
pmd_t *pmd, *pmd_base = pmd_offset(pud, 0);
pmd = pmd_base;
for (i = 0; i < PTRS_PER_PMD; ++i) {
if (pmd_none(*pmd))
continue;
arm_smmu_free_ptes(pmd);
pmd++;
}
pmd_free(NULL, pmd_base);
}
static void arm_smmu_free_puds(pgd_t *pgd)
{
int i;
pud_t *pud, *pud_base = pud_offset(pgd, 0);
pud = pud_base;
for (i = 0; i < PTRS_PER_PUD; ++i) {
if (pud_none(*pud))
continue;
arm_smmu_free_pmds(pud);
pud++;
}
pud_free(NULL, pud_base);
}
static void arm_smmu_free_pgtables(struct arm_smmu_domain *smmu_domain)
{
int i;
struct arm_smmu_cfg *root_cfg = &smmu_domain->root_cfg;
pgd_t *pgd, *pgd_base = root_cfg->pgd;
pgd = pgd_base;
for (i = 0; i < PTRS_PER_PGD; ++i) {
if (pgd_none(*pgd))
continue;
arm_smmu_free_puds(pgd);
pgd++;
}
kfree(pgd_base);
}
static void arm_smmu_domain_destroy(struct iommu_domain *domain)
{
struct arm_smmu_domain *smmu_domain = domain->priv;
arm_smmu_destroy_domain_context(domain);
arm_smmu_free_pgtables(smmu_domain);
kfree(smmu_domain);
}
static int arm_smmu_master_configure_smrs(struct arm_smmu_device *smmu,
struct arm_smmu_master *master)
{
int i;
struct arm_smmu_smr *smrs;
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
if (!(smmu->features & ARM_SMMU_FEAT_STREAM_MATCH))
return 0;
if (master->smrs)
return -EEXIST;
smrs = kmalloc(sizeof(*smrs) * master->num_streamids, GFP_KERNEL);
if (!smrs) {
dev_err(smmu->dev, "failed to allocate %d SMRs for master %s\n",
master->num_streamids, master->of_node->name);
return -ENOMEM;
}
for (i = 0; i < master->num_streamids; ++i) {
int idx = __arm_smmu_alloc_bitmap(smmu->smr_map, 0,
smmu->num_mapping_groups);
if (IS_ERR_VALUE(idx)) {
dev_err(smmu->dev, "failed to allocate free SMR\n");
goto err_free_smrs;
}
smrs[i] = (struct arm_smmu_smr) {
.idx = idx,
.mask = 0,
.id = master->streamids[i],
};
}
for (i = 0; i < master->num_streamids; ++i) {
u32 reg = SMR_VALID | smrs[i].id << SMR_ID_SHIFT |
smrs[i].mask << SMR_MASK_SHIFT;
writel_relaxed(reg, gr0_base + ARM_SMMU_GR0_SMR(smrs[i].idx));
}
master->smrs = smrs;
return 0;
err_free_smrs:
while (--i >= 0)
__arm_smmu_free_bitmap(smmu->smr_map, smrs[i].idx);
kfree(smrs);
return -ENOSPC;
}
static void arm_smmu_master_free_smrs(struct arm_smmu_device *smmu,
struct arm_smmu_master *master)
{
int i;
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
struct arm_smmu_smr *smrs = master->smrs;
for (i = 0; i < master->num_streamids; ++i) {
u8 idx = smrs[i].idx;
writel_relaxed(~SMR_VALID, gr0_base + ARM_SMMU_GR0_SMR(idx));
__arm_smmu_free_bitmap(smmu->smr_map, idx);
}
master->smrs = NULL;
kfree(smrs);
}
static void arm_smmu_bypass_stream_mapping(struct arm_smmu_device *smmu,
struct arm_smmu_master *master)
{
int i;
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
for (i = 0; i < master->num_streamids; ++i) {
u16 sid = master->streamids[i];
writel_relaxed(S2CR_TYPE_BYPASS,
gr0_base + ARM_SMMU_GR0_S2CR(sid));
}
}
static int arm_smmu_domain_add_master(struct arm_smmu_domain *smmu_domain,
struct arm_smmu_master *master)
{
int i, ret;
struct arm_smmu_device *parent, *smmu = smmu_domain->root_cfg.smmu;
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
ret = arm_smmu_master_configure_smrs(smmu, master);
if (ret)
return ret;
smmu = smmu_domain->leaf_smmu;
while ((parent = find_parent_smmu(smmu))) {
if (smmu->features & ARM_SMMU_FEAT_STREAM_MATCH)
continue;
arm_smmu_bypass_stream_mapping(smmu, master);
smmu = parent;
}
for (i = 0; i < master->num_streamids; ++i) {
u32 idx, s2cr;
idx = master->smrs ? master->smrs[i].idx : master->streamids[i];
s2cr = (S2CR_TYPE_TRANS << S2CR_TYPE_SHIFT) |
(smmu_domain->root_cfg.cbndx << S2CR_CBNDX_SHIFT);
writel_relaxed(s2cr, gr0_base + ARM_SMMU_GR0_S2CR(idx));
}
return 0;
}
static void arm_smmu_domain_remove_master(struct arm_smmu_domain *smmu_domain,
struct arm_smmu_master *master)
{
struct arm_smmu_device *smmu = smmu_domain->root_cfg.smmu;
arm_smmu_bypass_stream_mapping(smmu, master);
arm_smmu_master_free_smrs(smmu, master);
}
static int arm_smmu_attach_dev(struct iommu_domain *domain, struct device *dev)
{
int ret = -EINVAL;
struct arm_smmu_domain *smmu_domain = domain->priv;
struct arm_smmu_device *device_smmu = dev->archdata.iommu;
struct arm_smmu_master *master;
if (!device_smmu) {
dev_err(dev, "cannot attach to SMMU, is it on the same bus?\n");
return -ENXIO;
}
spin_lock(&smmu_domain->lock);
if (!smmu_domain->leaf_smmu) {
ret = arm_smmu_init_domain_context(domain, dev);
if (IS_ERR_VALUE(ret))
goto err_unlock;
smmu_domain->leaf_smmu = device_smmu;
} else if (smmu_domain->leaf_smmu != device_smmu) {
dev_err(dev,
"cannot attach to SMMU %s whilst already attached to domain on SMMU %s\n",
dev_name(smmu_domain->leaf_smmu->dev),
dev_name(device_smmu->dev));
goto err_unlock;
}
spin_unlock(&smmu_domain->lock);
master = find_smmu_master(smmu_domain->leaf_smmu, dev->of_node);
if (!master)
return -ENODEV;
return arm_smmu_domain_add_master(smmu_domain, master);
err_unlock:
spin_unlock(&smmu_domain->lock);
return ret;
}
static void arm_smmu_detach_dev(struct iommu_domain *domain, struct device *dev)
{
struct arm_smmu_domain *smmu_domain = domain->priv;
struct arm_smmu_master *master;
master = find_smmu_master(smmu_domain->leaf_smmu, dev->of_node);
if (master)
arm_smmu_domain_remove_master(smmu_domain, master);
}
static void arm_smmu_flush_pgtable(struct arm_smmu_device *smmu, void *addr,
size_t size)
{
unsigned long offset = (unsigned long)addr & ~PAGE_MASK;
if (!(smmu->features & ARM_SMMU_FEAT_COHERENT_WALK))
dma_map_page(smmu->dev, virt_to_page(addr), offset, size,
DMA_TO_DEVICE);
}
static bool arm_smmu_pte_is_contiguous_range(unsigned long addr,
unsigned long end)
{
return !(addr & ~ARM_SMMU_PTE_CONT_MASK) &&
(addr + ARM_SMMU_PTE_CONT_SIZE <= end);
}
static int arm_smmu_alloc_init_pte(struct arm_smmu_device *smmu, pmd_t *pmd,
unsigned long addr, unsigned long end,
unsigned long pfn, int flags, int stage)
{
pte_t *pte, *start;
pteval_t pteval = ARM_SMMU_PTE_PAGE | ARM_SMMU_PTE_AF;
if (pmd_none(*pmd)) {
pgtable_t table = alloc_page(PGALLOC_GFP);
if (!table)
return -ENOMEM;
arm_smmu_flush_pgtable(smmu, page_address(table),
ARM_SMMU_PTE_HWTABLE_SIZE);
pgtable_page_ctor(table);
pmd_populate(NULL, pmd, table);
arm_smmu_flush_pgtable(smmu, pmd, sizeof(*pmd));
}
if (stage == 1) {
pteval |= ARM_SMMU_PTE_AP_UNPRIV | ARM_SMMU_PTE_nG;
if (!(flags & IOMMU_WRITE) && (flags & IOMMU_READ))
pteval |= ARM_SMMU_PTE_AP_RDONLY;
if (flags & IOMMU_CACHE)
pteval |= (MAIR_ATTR_IDX_CACHE <<
ARM_SMMU_PTE_ATTRINDX_SHIFT);
} else {
pteval |= ARM_SMMU_PTE_HAP_FAULT;
if (flags & IOMMU_READ)
pteval |= ARM_SMMU_PTE_HAP_READ;
if (flags & IOMMU_WRITE)
pteval |= ARM_SMMU_PTE_HAP_WRITE;
if (flags & IOMMU_CACHE)
pteval |= ARM_SMMU_PTE_MEMATTR_OIWB;
else
pteval |= ARM_SMMU_PTE_MEMATTR_NC;
}
if (!(flags & (IOMMU_READ | IOMMU_WRITE)))
pteval &= ~ARM_SMMU_PTE_PAGE;
pteval |= ARM_SMMU_PTE_SH_IS;
start = pmd_page_vaddr(*pmd) + pte_index(addr);
pte = start;
do {
int i = 1;
pteval &= ~ARM_SMMU_PTE_CONT;
if (arm_smmu_pte_is_contiguous_range(addr, end)) {
i = ARM_SMMU_PTE_CONT_ENTRIES;
pteval |= ARM_SMMU_PTE_CONT;
} else if (pte_val(*pte) &
(ARM_SMMU_PTE_CONT | ARM_SMMU_PTE_PAGE)) {
int j;
pte_t *cont_start;
unsigned long idx = pte_index(addr);
idx &= ~(ARM_SMMU_PTE_CONT_ENTRIES - 1);
cont_start = pmd_page_vaddr(*pmd) + idx;
for (j = 0; j < ARM_SMMU_PTE_CONT_ENTRIES; ++j)
pte_val(*(cont_start + j)) &= ~ARM_SMMU_PTE_CONT;
arm_smmu_flush_pgtable(smmu, cont_start,
sizeof(*pte) *
ARM_SMMU_PTE_CONT_ENTRIES);
}
do {
*pte = pfn_pte(pfn, __pgprot(pteval));
} while (pte++, pfn++, addr += PAGE_SIZE, --i);
} while (addr != end);
arm_smmu_flush_pgtable(smmu, start, sizeof(*pte) * (pte - start));
return 0;
}
static int arm_smmu_alloc_init_pmd(struct arm_smmu_device *smmu, pud_t *pud,
unsigned long addr, unsigned long end,
phys_addr_t phys, int flags, int stage)
{
int ret;
pmd_t *pmd;
unsigned long next, pfn = __phys_to_pfn(phys);
#ifndef __PAGETABLE_PMD_FOLDED
if (pud_none(*pud)) {
pmd = pmd_alloc_one(NULL, addr);
if (!pmd)
return -ENOMEM;
} else
#endif
pmd = pmd_offset(pud, addr);
do {
next = pmd_addr_end(addr, end);
ret = arm_smmu_alloc_init_pte(smmu, pmd, addr, end, pfn,
flags, stage);
pud_populate(NULL, pud, pmd);
arm_smmu_flush_pgtable(smmu, pud, sizeof(*pud));
phys += next - addr;
} while (pmd++, addr = next, addr < end);
return ret;
}
static int arm_smmu_alloc_init_pud(struct arm_smmu_device *smmu, pgd_t *pgd,
unsigned long addr, unsigned long end,
phys_addr_t phys, int flags, int stage)
{
int ret = 0;
pud_t *pud;
unsigned long next;
#ifndef __PAGETABLE_PUD_FOLDED
if (pgd_none(*pgd)) {
pud = pud_alloc_one(NULL, addr);
if (!pud)
return -ENOMEM;
} else
#endif
pud = pud_offset(pgd, addr);
do {
next = pud_addr_end(addr, end);
ret = arm_smmu_alloc_init_pmd(smmu, pud, addr, next, phys,
flags, stage);
pgd_populate(NULL, pud, pgd);
arm_smmu_flush_pgtable(smmu, pgd, sizeof(*pgd));
phys += next - addr;
} while (pud++, addr = next, addr < end);
return ret;
}
static int arm_smmu_handle_mapping(struct arm_smmu_domain *smmu_domain,
unsigned long iova, phys_addr_t paddr,
size_t size, int flags)
{
int ret, stage;
unsigned long end;
phys_addr_t input_mask, output_mask;
struct arm_smmu_cfg *root_cfg = &smmu_domain->root_cfg;
pgd_t *pgd = root_cfg->pgd;
struct arm_smmu_device *smmu = root_cfg->smmu;
if (root_cfg->cbar == CBAR_TYPE_S2_TRANS) {
stage = 2;
output_mask = (1ULL << smmu->s2_output_size) - 1;
} else {
stage = 1;
output_mask = (1ULL << smmu->s1_output_size) - 1;
}
if (!pgd)
return -EINVAL;
if (size & ~PAGE_MASK)
return -EINVAL;
input_mask = (1ULL << smmu->input_size) - 1;
if ((phys_addr_t)iova & ~input_mask)
return -ERANGE;
if (paddr & ~output_mask)
return -ERANGE;
spin_lock(&smmu_domain->lock);
pgd += pgd_index(iova);
end = iova + size;
do {
unsigned long next = pgd_addr_end(iova, end);
ret = arm_smmu_alloc_init_pud(smmu, pgd, iova, next, paddr,
flags, stage);
if (ret)
goto out_unlock;
paddr += next - iova;
iova = next;
} while (pgd++, iova != end);
out_unlock:
spin_unlock(&smmu_domain->lock);
if (smmu->features & ARM_SMMU_FEAT_COHERENT_WALK)
dsb();
return ret;
}
static int arm_smmu_map(struct iommu_domain *domain, unsigned long iova,
phys_addr_t paddr, size_t size, int flags)
{
struct arm_smmu_domain *smmu_domain = domain->priv;
struct arm_smmu_device *smmu = smmu_domain->leaf_smmu;
if (!smmu_domain || !smmu)
return -ENODEV;
if ((phys_addr_t)iova & ~smmu_domain->output_mask)
return -ERANGE;
return arm_smmu_handle_mapping(smmu_domain, iova, paddr, size, flags);
}
static size_t arm_smmu_unmap(struct iommu_domain *domain, unsigned long iova,
size_t size)
{
int ret;
struct arm_smmu_domain *smmu_domain = domain->priv;
ret = arm_smmu_handle_mapping(smmu_domain, iova, 0, size, 0);
arm_smmu_tlb_inv_context(&smmu_domain->root_cfg);
return ret ? ret : size;
}
static phys_addr_t arm_smmu_iova_to_phys(struct iommu_domain *domain,
dma_addr_t iova)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
struct arm_smmu_domain *smmu_domain = domain->priv;
struct arm_smmu_cfg *root_cfg = &smmu_domain->root_cfg;
struct arm_smmu_device *smmu = root_cfg->smmu;
spin_lock(&smmu_domain->lock);
pgd = root_cfg->pgd;
if (!pgd)
goto err_unlock;
pgd += pgd_index(iova);
if (pgd_none_or_clear_bad(pgd))
goto err_unlock;
pud = pud_offset(pgd, iova);
if (pud_none_or_clear_bad(pud))
goto err_unlock;
pmd = pmd_offset(pud, iova);
if (pmd_none_or_clear_bad(pmd))
goto err_unlock;
pte = pmd_page_vaddr(*pmd) + pte_index(iova);
if (pte_none(pte))
goto err_unlock;
spin_unlock(&smmu_domain->lock);
return __pfn_to_phys(pte_pfn(*pte)) | (iova & ~PAGE_MASK);
err_unlock:
spin_unlock(&smmu_domain->lock);
dev_warn(smmu->dev,
"invalid (corrupt?) page tables detected for iova 0x%llx\n",
(unsigned long long)iova);
return -EINVAL;
}
static int arm_smmu_domain_has_cap(struct iommu_domain *domain,
unsigned long cap)
{
unsigned long caps = 0;
struct arm_smmu_domain *smmu_domain = domain->priv;
if (smmu_domain->root_cfg.smmu->features & ARM_SMMU_FEAT_COHERENT_WALK)
caps |= IOMMU_CAP_CACHE_COHERENCY;
return !!(cap & caps);
}
static int arm_smmu_add_device(struct device *dev)
{
struct arm_smmu_device *child, *parent, *smmu;
struct arm_smmu_master *master = NULL;
spin_lock(&arm_smmu_devices_lock);
list_for_each_entry(parent, &arm_smmu_devices, list) {
smmu = parent;
list_for_each_entry(child, &arm_smmu_devices, list) {
if (child->parent_of_node == parent->dev->of_node) {
master = find_smmu_master(child, dev->of_node);
if (master) {
smmu = NULL;
break;
}
}
}
if (!smmu) {
master = NULL;
continue;
}
master = find_smmu_master(smmu, dev->of_node);
if (master)
break;
}
spin_unlock(&arm_smmu_devices_lock);
if (!master)
return -ENODEV;
dev->archdata.iommu = smmu;
return 0;
}
static void arm_smmu_remove_device(struct device *dev)
{
dev->archdata.iommu = NULL;
}
static void arm_smmu_device_reset(struct arm_smmu_device *smmu)
{
void __iomem *gr0_base = ARM_SMMU_GR0(smmu);
void __iomem *sctlr_base = ARM_SMMU_CB_BASE(smmu) + ARM_SMMU_CB_SCTLR;
int i = 0;
u32 scr0 = readl_relaxed(gr0_base + ARM_SMMU_GR0_sCR0);
for (i = 0; i < smmu->num_mapping_groups; ++i) {
writel_relaxed(~SMR_VALID, gr0_base + ARM_SMMU_GR0_SMR(i));
writel_relaxed(S2CR_TYPE_BYPASS, gr0_base + ARM_SMMU_GR0_S2CR(i));
}
for (i = 0; i < smmu->num_context_banks; ++i)
writel_relaxed(0, sctlr_base + ARM_SMMU_CB(smmu, i));
writel_relaxed(0, gr0_base + ARM_SMMU_GR0_STLBIALL);
writel_relaxed(0, gr0_base + ARM_SMMU_GR0_TLBIALLH);
writel_relaxed(0, gr0_base + ARM_SMMU_GR0_TLBIALLNSNH);
scr0 |= (sCR0_GFRE | sCR0_GFIE | sCR0_GCFGFRE | sCR0_GCFGFIE);
scr0 |= (sCR0_VMIDPNE | sCR0_PTM);
scr0 &= ~(sCR0_CLIENTPD | sCR0_USFCFG);
scr0 &= ~sCR0_FB;
scr0 &= ~(sCR0_BSU_MASK << sCR0_BSU_SHIFT);
arm_smmu_tlb_sync(smmu);
writel(scr0, gr0_base + ARM_SMMU_GR0_sCR0);
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
dev_notice(smmu->dev, "probing hardware configuration...\n");
id = readl_relaxed(gr0_base + ARM_SMMU_GR0_PIDR2);
smmu->version = ((id >> PIDR2_ARCH_SHIFT) & PIDR2_ARCH_MASK) + 1;
dev_notice(smmu->dev, "SMMUv%d with:\n", smmu->version);
id = readl_relaxed(gr0_base + ARM_SMMU_GR0_ID0);
#ifndef CONFIG_64BIT
if (((id >> ID0_PTFS_SHIFT) & ID0_PTFS_MASK) == ID0_PTFS_V8_ONLY) {
dev_err(smmu->dev, "\tno v7 descriptor support!\n");
return -ENODEV;
}
#endif
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
(ARM_SMMU_FEAT_TRANS_S1 | ARM_SMMU_FEAT_TRANS_S2 |
ARM_SMMU_FEAT_TRANS_NESTED))) {
dev_err(smmu->dev, "\tno translation support!\n");
return -ENODEV;
}
if (id & ID0_CTTW) {
smmu->features |= ARM_SMMU_FEAT_COHERENT_WALK;
dev_notice(smmu->dev, "\tcoherent table walk\n");
}
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
}
id = readl_relaxed(gr0_base + ARM_SMMU_GR0_ID1);
smmu->pagesize = (id & ID1_PAGESIZE) ? SZ_64K : SZ_4K;
size = 1 << (((id >> ID1_NUMPAGENDXB_SHIFT) & ID1_NUMPAGENDXB_MASK) + 1);
size *= (smmu->pagesize << 1);
if (smmu->size < size)
dev_warn(smmu->dev,
"device is 0x%lx bytes but only mapped 0x%lx!\n",
size, smmu->size);
smmu->num_s2_context_banks = (id >> ID1_NUMS2CB_SHIFT) &
ID1_NUMS2CB_MASK;
smmu->num_context_banks = (id >> ID1_NUMCB_SHIFT) & ID1_NUMCB_MASK;
if (smmu->num_s2_context_banks > smmu->num_context_banks) {
dev_err(smmu->dev, "impossible number of S2 context banks!\n");
return -ENODEV;
}
dev_notice(smmu->dev, "\t%u context banks (%u stage-2 only)\n",
smmu->num_context_banks, smmu->num_s2_context_banks);
id = readl_relaxed(gr0_base + ARM_SMMU_GR0_ID2);
size = arm_smmu_id_size_to_bits((id >> ID2_IAS_SHIFT) & ID2_IAS_MASK);
#ifdef CONFIG_64BIT
smmu->s1_output_size = min(39UL, size);
#else
smmu->s1_output_size = min(32UL, size);
#endif
size = arm_smmu_id_size_to_bits((id >> ID2_OAS_SHIFT) & ID2_OAS_MASK);
smmu->s2_output_size = min((unsigned long)PHYS_MASK_SHIFT, size);
if (smmu->version == 1) {
smmu->input_size = 32;
} else {
#ifdef CONFIG_64BIT
size = (id >> ID2_UBS_SHIFT) & ID2_UBS_MASK;
size = min(39, arm_smmu_id_size_to_bits(size));
#else
size = 32;
#endif
smmu->input_size = size;
if ((PAGE_SIZE == SZ_4K && !(id & ID2_PTFS_4K)) ||
(PAGE_SIZE == SZ_64K && !(id & ID2_PTFS_64K)) ||
(PAGE_SIZE != SZ_4K && PAGE_SIZE != SZ_64K)) {
dev_err(smmu->dev, "CPU page size 0x%lx unsupported\n",
PAGE_SIZE);
return -ENODEV;
}
}
dev_notice(smmu->dev,
"\t%lu-bit VA, %lu-bit IPA, %lu-bit PA\n",
smmu->input_size, smmu->s1_output_size, smmu->s2_output_size);
return 0;
}
static int arm_smmu_device_dt_probe(struct platform_device *pdev)
{
struct resource *res;
struct arm_smmu_device *smmu;
struct device_node *dev_node;
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
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "missing base address/size\n");
return -ENODEV;
}
smmu->size = resource_size(res);
smmu->base = devm_request_and_ioremap(dev, res);
if (!smmu->base)
return -EADDRNOTAVAIL;
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
if (num_irqs < smmu->num_global_irqs) {
dev_warn(dev, "found %d interrupts but expected at least %d\n",
num_irqs, smmu->num_global_irqs);
smmu->num_global_irqs = num_irqs;
}
smmu->num_context_irqs = num_irqs - smmu->num_global_irqs;
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
if ((dev_node = of_parse_phandle(dev->of_node, "smmu-parent", 0)))
smmu->parent_of_node = dev_node;
err = arm_smmu_device_cfg_probe(smmu);
if (err)
goto out_put_parent;
if (smmu->version > 1 &&
smmu->num_context_banks != smmu->num_context_irqs) {
dev_err(dev,
"found only %d context interrupt(s) but %d required\n",
smmu->num_context_irqs, smmu->num_context_banks);
goto out_put_parent;
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
out_put_parent:
if (smmu->parent_of_node)
of_node_put(smmu->parent_of_node);
out_put_masters:
for (node = rb_first(&smmu->masters); node; node = rb_next(node)) {
struct arm_smmu_master *master;
master = container_of(node, struct arm_smmu_master, node);
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
if (smmu->parent_of_node)
of_node_put(smmu->parent_of_node);
for (node = rb_first(&smmu->masters); node; node = rb_next(node)) {
struct arm_smmu_master *master;
master = container_of(node, struct arm_smmu_master, node);
of_node_put(master->of_node);
}
if (!bitmap_empty(smmu->context_map, ARM_SMMU_MAX_CBS))
dev_err(dev, "removing device with active domains!\n");
for (i = 0; i < smmu->num_global_irqs; ++i)
free_irq(smmu->irqs[i], smmu);
writel(sCR0_CLIENTPD, ARM_SMMU_GR0(smmu) + ARM_SMMU_GR0_sCR0);
return 0;
}
static int __init arm_smmu_init(void)
{
int ret;
ret = platform_driver_register(&arm_smmu_driver);
if (ret)
return ret;
if (!iommu_present(&platform_bus_type))
bus_set_iommu(&platform_bus_type, &arm_smmu_ops);
if (!iommu_present(&amba_bustype))
bus_set_iommu(&amba_bustype, &arm_smmu_ops);
return 0;
}
static void __exit arm_smmu_exit(void)
{
return platform_driver_unregister(&arm_smmu_driver);
}
