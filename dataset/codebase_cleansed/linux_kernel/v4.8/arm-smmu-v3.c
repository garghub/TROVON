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
static bool queue_full(struct arm_smmu_queue *q)
{
return Q_IDX(q, q->prod) == Q_IDX(q, q->cons) &&
Q_WRP(q, q->prod) != Q_WRP(q, q->cons);
}
static bool queue_empty(struct arm_smmu_queue *q)
{
return Q_IDX(q, q->prod) == Q_IDX(q, q->cons) &&
Q_WRP(q, q->prod) == Q_WRP(q, q->cons);
}
static void queue_sync_cons(struct arm_smmu_queue *q)
{
q->cons = readl_relaxed(q->cons_reg);
}
static void queue_inc_cons(struct arm_smmu_queue *q)
{
u32 cons = (Q_WRP(q, q->cons) | Q_IDX(q, q->cons)) + 1;
q->cons = Q_OVF(q, q->cons) | Q_WRP(q, cons) | Q_IDX(q, cons);
writel(q->cons, q->cons_reg);
}
static int queue_sync_prod(struct arm_smmu_queue *q)
{
int ret = 0;
u32 prod = readl_relaxed(q->prod_reg);
if (Q_OVF(q, prod) != Q_OVF(q, q->prod))
ret = -EOVERFLOW;
q->prod = prod;
return ret;
}
static void queue_inc_prod(struct arm_smmu_queue *q)
{
u32 prod = (Q_WRP(q, q->prod) | Q_IDX(q, q->prod)) + 1;
q->prod = Q_OVF(q, q->prod) | Q_WRP(q, prod) | Q_IDX(q, prod);
writel(q->prod, q->prod_reg);
}
static bool __queue_cons_before(struct arm_smmu_queue *q, u32 until)
{
if (Q_WRP(q, q->cons) == Q_WRP(q, until))
return Q_IDX(q, q->cons) < Q_IDX(q, until);
return Q_IDX(q, q->cons) >= Q_IDX(q, until);
}
static int queue_poll_cons(struct arm_smmu_queue *q, u32 until, bool wfe)
{
ktime_t timeout = ktime_add_us(ktime_get(), ARM_SMMU_POLL_TIMEOUT_US);
while (queue_sync_cons(q), __queue_cons_before(q, until)) {
if (ktime_compare(ktime_get(), timeout) > 0)
return -ETIMEDOUT;
if (wfe) {
wfe();
} else {
cpu_relax();
udelay(1);
}
}
return 0;
}
static void queue_write(__le64 *dst, u64 *src, size_t n_dwords)
{
int i;
for (i = 0; i < n_dwords; ++i)
*dst++ = cpu_to_le64(*src++);
}
static int queue_insert_raw(struct arm_smmu_queue *q, u64 *ent)
{
if (queue_full(q))
return -ENOSPC;
queue_write(Q_ENT(q, q->prod), ent, q->ent_dwords);
queue_inc_prod(q);
return 0;
}
static void queue_read(__le64 *dst, u64 *src, size_t n_dwords)
{
int i;
for (i = 0; i < n_dwords; ++i)
*dst++ = le64_to_cpu(*src++);
}
static int queue_remove_raw(struct arm_smmu_queue *q, u64 *ent)
{
if (queue_empty(q))
return -EAGAIN;
queue_read(ent, Q_ENT(q, q->cons), q->ent_dwords);
queue_inc_cons(q);
return 0;
}
static int arm_smmu_cmdq_build_cmd(u64 *cmd, struct arm_smmu_cmdq_ent *ent)
{
memset(cmd, 0, CMDQ_ENT_DWORDS << 3);
cmd[0] |= (ent->opcode & CMDQ_0_OP_MASK) << CMDQ_0_OP_SHIFT;
switch (ent->opcode) {
case CMDQ_OP_TLBI_EL2_ALL:
case CMDQ_OP_TLBI_NSNH_ALL:
break;
case CMDQ_OP_PREFETCH_CFG:
cmd[0] |= (u64)ent->prefetch.sid << CMDQ_PREFETCH_0_SID_SHIFT;
cmd[1] |= ent->prefetch.size << CMDQ_PREFETCH_1_SIZE_SHIFT;
cmd[1] |= ent->prefetch.addr & CMDQ_PREFETCH_1_ADDR_MASK;
break;
case CMDQ_OP_CFGI_STE:
cmd[0] |= (u64)ent->cfgi.sid << CMDQ_CFGI_0_SID_SHIFT;
cmd[1] |= ent->cfgi.leaf ? CMDQ_CFGI_1_LEAF : 0;
break;
case CMDQ_OP_CFGI_ALL:
cmd[1] |= CMDQ_CFGI_1_RANGE_MASK << CMDQ_CFGI_1_RANGE_SHIFT;
break;
case CMDQ_OP_TLBI_NH_VA:
cmd[0] |= (u64)ent->tlbi.asid << CMDQ_TLBI_0_ASID_SHIFT;
cmd[1] |= ent->tlbi.leaf ? CMDQ_TLBI_1_LEAF : 0;
cmd[1] |= ent->tlbi.addr & CMDQ_TLBI_1_VA_MASK;
break;
case CMDQ_OP_TLBI_S2_IPA:
cmd[0] |= (u64)ent->tlbi.vmid << CMDQ_TLBI_0_VMID_SHIFT;
cmd[1] |= ent->tlbi.leaf ? CMDQ_TLBI_1_LEAF : 0;
cmd[1] |= ent->tlbi.addr & CMDQ_TLBI_1_IPA_MASK;
break;
case CMDQ_OP_TLBI_NH_ASID:
cmd[0] |= (u64)ent->tlbi.asid << CMDQ_TLBI_0_ASID_SHIFT;
case CMDQ_OP_TLBI_S12_VMALL:
cmd[0] |= (u64)ent->tlbi.vmid << CMDQ_TLBI_0_VMID_SHIFT;
break;
case CMDQ_OP_PRI_RESP:
cmd[0] |= ent->substream_valid ? CMDQ_0_SSV : 0;
cmd[0] |= ent->pri.ssid << CMDQ_PRI_0_SSID_SHIFT;
cmd[0] |= (u64)ent->pri.sid << CMDQ_PRI_0_SID_SHIFT;
cmd[1] |= ent->pri.grpid << CMDQ_PRI_1_GRPID_SHIFT;
switch (ent->pri.resp) {
case PRI_RESP_DENY:
cmd[1] |= CMDQ_PRI_1_RESP_DENY;
break;
case PRI_RESP_FAIL:
cmd[1] |= CMDQ_PRI_1_RESP_FAIL;
break;
case PRI_RESP_SUCC:
cmd[1] |= CMDQ_PRI_1_RESP_SUCC;
break;
default:
return -EINVAL;
}
break;
case CMDQ_OP_CMD_SYNC:
cmd[0] |= CMDQ_SYNC_0_CS_SEV;
break;
default:
return -ENOENT;
}
return 0;
}
static void arm_smmu_cmdq_skip_err(struct arm_smmu_device *smmu)
{
static const char *cerror_str[] = {
[CMDQ_ERR_CERROR_NONE_IDX] = "No error",
[CMDQ_ERR_CERROR_ILL_IDX] = "Illegal command",
[CMDQ_ERR_CERROR_ABT_IDX] = "Abort on command fetch",
};
int i;
u64 cmd[CMDQ_ENT_DWORDS];
struct arm_smmu_queue *q = &smmu->cmdq.q;
u32 cons = readl_relaxed(q->cons_reg);
u32 idx = cons >> CMDQ_ERR_SHIFT & CMDQ_ERR_MASK;
struct arm_smmu_cmdq_ent cmd_sync = {
.opcode = CMDQ_OP_CMD_SYNC,
};
dev_err(smmu->dev, "CMDQ error (cons 0x%08x): %s\n", cons,
idx < ARRAY_SIZE(cerror_str) ? cerror_str[idx] : "Unknown");
switch (idx) {
case CMDQ_ERR_CERROR_ABT_IDX:
dev_err(smmu->dev, "retrying command fetch\n");
case CMDQ_ERR_CERROR_NONE_IDX:
return;
case CMDQ_ERR_CERROR_ILL_IDX:
default:
break;
}
queue_read(cmd, Q_ENT(q, cons), q->ent_dwords);
dev_err(smmu->dev, "skipping command in error state:\n");
for (i = 0; i < ARRAY_SIZE(cmd); ++i)
dev_err(smmu->dev, "\t0x%016llx\n", (unsigned long long)cmd[i]);
if (arm_smmu_cmdq_build_cmd(cmd, &cmd_sync)) {
dev_err(smmu->dev, "failed to convert to CMD_SYNC\n");
return;
}
queue_write(Q_ENT(q, cons), cmd, q->ent_dwords);
}
static void arm_smmu_cmdq_issue_cmd(struct arm_smmu_device *smmu,
struct arm_smmu_cmdq_ent *ent)
{
u32 until;
u64 cmd[CMDQ_ENT_DWORDS];
bool wfe = !!(smmu->features & ARM_SMMU_FEAT_SEV);
struct arm_smmu_queue *q = &smmu->cmdq.q;
if (arm_smmu_cmdq_build_cmd(cmd, ent)) {
dev_warn(smmu->dev, "ignoring unknown CMDQ opcode 0x%x\n",
ent->opcode);
return;
}
spin_lock(&smmu->cmdq.lock);
while (until = q->prod + 1, queue_insert_raw(q, cmd) == -ENOSPC) {
if (queue_poll_cons(q, until, wfe))
dev_err_ratelimited(smmu->dev, "CMDQ timeout\n");
}
if (ent->opcode == CMDQ_OP_CMD_SYNC && queue_poll_cons(q, until, wfe))
dev_err_ratelimited(smmu->dev, "CMD_SYNC timeout\n");
spin_unlock(&smmu->cmdq.lock);
}
static u64 arm_smmu_cpu_tcr_to_cd(u64 tcr)
{
u64 val = 0;
val |= ARM_SMMU_TCR2CD(tcr, T0SZ);
val |= ARM_SMMU_TCR2CD(tcr, TG0);
val |= ARM_SMMU_TCR2CD(tcr, IRGN0);
val |= ARM_SMMU_TCR2CD(tcr, ORGN0);
val |= ARM_SMMU_TCR2CD(tcr, SH0);
val |= ARM_SMMU_TCR2CD(tcr, EPD0);
val |= ARM_SMMU_TCR2CD(tcr, EPD1);
val |= ARM_SMMU_TCR2CD(tcr, IPS);
val |= ARM_SMMU_TCR2CD(tcr, TBI0);
return val;
}
static void arm_smmu_write_ctx_desc(struct arm_smmu_device *smmu,
struct arm_smmu_s1_cfg *cfg)
{
u64 val;
val = arm_smmu_cpu_tcr_to_cd(cfg->cd.tcr) |
#ifdef __BIG_ENDIAN
CTXDESC_CD_0_ENDI |
#endif
CTXDESC_CD_0_R | CTXDESC_CD_0_A | CTXDESC_CD_0_ASET_PRIVATE |
CTXDESC_CD_0_AA64 | (u64)cfg->cd.asid << CTXDESC_CD_0_ASID_SHIFT |
CTXDESC_CD_0_V;
cfg->cdptr[0] = cpu_to_le64(val);
val = cfg->cd.ttbr & CTXDESC_CD_1_TTB0_MASK << CTXDESC_CD_1_TTB0_SHIFT;
cfg->cdptr[1] = cpu_to_le64(val);
cfg->cdptr[3] = cpu_to_le64(cfg->cd.mair << CTXDESC_CD_3_MAIR_SHIFT);
}
static void
arm_smmu_write_strtab_l1_desc(__le64 *dst, struct arm_smmu_strtab_l1_desc *desc)
{
u64 val = 0;
val |= (desc->span & STRTAB_L1_DESC_SPAN_MASK)
<< STRTAB_L1_DESC_SPAN_SHIFT;
val |= desc->l2ptr_dma &
STRTAB_L1_DESC_L2PTR_MASK << STRTAB_L1_DESC_L2PTR_SHIFT;
*dst = cpu_to_le64(val);
}
static void arm_smmu_sync_ste_for_sid(struct arm_smmu_device *smmu, u32 sid)
{
struct arm_smmu_cmdq_ent cmd = {
.opcode = CMDQ_OP_CFGI_STE,
.cfgi = {
.sid = sid,
.leaf = true,
},
};
arm_smmu_cmdq_issue_cmd(smmu, &cmd);
cmd.opcode = CMDQ_OP_CMD_SYNC;
arm_smmu_cmdq_issue_cmd(smmu, &cmd);
}
static void arm_smmu_write_strtab_ent(struct arm_smmu_device *smmu, u32 sid,
__le64 *dst, struct arm_smmu_strtab_ent *ste)
{
u64 val = le64_to_cpu(dst[0]);
bool ste_live = false;
struct arm_smmu_cmdq_ent prefetch_cmd = {
.opcode = CMDQ_OP_PREFETCH_CFG,
.prefetch = {
.sid = sid,
},
};
if (val & STRTAB_STE_0_V) {
u64 cfg;
cfg = val & STRTAB_STE_0_CFG_MASK << STRTAB_STE_0_CFG_SHIFT;
switch (cfg) {
case STRTAB_STE_0_CFG_BYPASS:
break;
case STRTAB_STE_0_CFG_S1_TRANS:
case STRTAB_STE_0_CFG_S2_TRANS:
ste_live = true;
break;
case STRTAB_STE_0_CFG_ABORT:
if (disable_bypass)
break;
default:
BUG();
}
}
val &= ~(STRTAB_STE_0_CFG_MASK << STRTAB_STE_0_CFG_SHIFT);
if (ste->valid)
val |= STRTAB_STE_0_V;
else
val &= ~STRTAB_STE_0_V;
if (ste->bypass) {
val |= disable_bypass ? STRTAB_STE_0_CFG_ABORT
: STRTAB_STE_0_CFG_BYPASS;
dst[0] = cpu_to_le64(val);
dst[1] = cpu_to_le64(STRTAB_STE_1_SHCFG_INCOMING
<< STRTAB_STE_1_SHCFG_SHIFT);
dst[2] = 0;
if (ste_live)
arm_smmu_sync_ste_for_sid(smmu, sid);
return;
}
if (ste->s1_cfg) {
BUG_ON(ste_live);
dst[1] = cpu_to_le64(
STRTAB_STE_1_S1C_CACHE_WBRA
<< STRTAB_STE_1_S1CIR_SHIFT |
STRTAB_STE_1_S1C_CACHE_WBRA
<< STRTAB_STE_1_S1COR_SHIFT |
STRTAB_STE_1_S1C_SH_ISH << STRTAB_STE_1_S1CSH_SHIFT |
#ifdef CONFIG_PCI_ATS
STRTAB_STE_1_EATS_TRANS << STRTAB_STE_1_EATS_SHIFT |
#endif
STRTAB_STE_1_STRW_NSEL1 << STRTAB_STE_1_STRW_SHIFT);
if (smmu->features & ARM_SMMU_FEAT_STALLS)
dst[1] |= cpu_to_le64(STRTAB_STE_1_S1STALLD);
val |= (ste->s1_cfg->cdptr_dma & STRTAB_STE_0_S1CTXPTR_MASK
<< STRTAB_STE_0_S1CTXPTR_SHIFT) |
STRTAB_STE_0_CFG_S1_TRANS;
}
if (ste->s2_cfg) {
BUG_ON(ste_live);
dst[2] = cpu_to_le64(
ste->s2_cfg->vmid << STRTAB_STE_2_S2VMID_SHIFT |
(ste->s2_cfg->vtcr & STRTAB_STE_2_VTCR_MASK)
<< STRTAB_STE_2_VTCR_SHIFT |
#ifdef __BIG_ENDIAN
STRTAB_STE_2_S2ENDI |
#endif
STRTAB_STE_2_S2PTW | STRTAB_STE_2_S2AA64 |
STRTAB_STE_2_S2R);
dst[3] = cpu_to_le64(ste->s2_cfg->vttbr &
STRTAB_STE_3_S2TTB_MASK << STRTAB_STE_3_S2TTB_SHIFT);
val |= STRTAB_STE_0_CFG_S2_TRANS;
}
arm_smmu_sync_ste_for_sid(smmu, sid);
dst[0] = cpu_to_le64(val);
arm_smmu_sync_ste_for_sid(smmu, sid);
if (!(smmu->options & ARM_SMMU_OPT_SKIP_PREFETCH))
arm_smmu_cmdq_issue_cmd(smmu, &prefetch_cmd);
}
static void arm_smmu_init_bypass_stes(u64 *strtab, unsigned int nent)
{
unsigned int i;
struct arm_smmu_strtab_ent ste = {
.valid = true,
.bypass = true,
};
for (i = 0; i < nent; ++i) {
arm_smmu_write_strtab_ent(NULL, -1, strtab, &ste);
strtab += STRTAB_STE_DWORDS;
}
}
static int arm_smmu_init_l2_strtab(struct arm_smmu_device *smmu, u32 sid)
{
size_t size;
void *strtab;
struct arm_smmu_strtab_cfg *cfg = &smmu->strtab_cfg;
struct arm_smmu_strtab_l1_desc *desc = &cfg->l1_desc[sid >> STRTAB_SPLIT];
if (desc->l2ptr)
return 0;
size = 1 << (STRTAB_SPLIT + ilog2(STRTAB_STE_DWORDS) + 3);
strtab = &cfg->strtab[(sid >> STRTAB_SPLIT) * STRTAB_L1_DESC_DWORDS];
desc->span = STRTAB_SPLIT + 1;
desc->l2ptr = dmam_alloc_coherent(smmu->dev, size, &desc->l2ptr_dma,
GFP_KERNEL | __GFP_ZERO);
if (!desc->l2ptr) {
dev_err(smmu->dev,
"failed to allocate l2 stream table for SID %u\n",
sid);
return -ENOMEM;
}
arm_smmu_init_bypass_stes(desc->l2ptr, 1 << STRTAB_SPLIT);
arm_smmu_write_strtab_l1_desc(strtab, desc);
return 0;
}
static irqreturn_t arm_smmu_evtq_thread(int irq, void *dev)
{
int i;
struct arm_smmu_device *smmu = dev;
struct arm_smmu_queue *q = &smmu->evtq.q;
u64 evt[EVTQ_ENT_DWORDS];
while (!queue_remove_raw(q, evt)) {
u8 id = evt[0] >> EVTQ_0_ID_SHIFT & EVTQ_0_ID_MASK;
dev_info(smmu->dev, "event 0x%02x received:\n", id);
for (i = 0; i < ARRAY_SIZE(evt); ++i)
dev_info(smmu->dev, "\t0x%016llx\n",
(unsigned long long)evt[i]);
}
q->cons = Q_OVF(q, q->prod) | Q_WRP(q, q->cons) | Q_IDX(q, q->cons);
return IRQ_HANDLED;
}
static irqreturn_t arm_smmu_evtq_handler(int irq, void *dev)
{
irqreturn_t ret = IRQ_WAKE_THREAD;
struct arm_smmu_device *smmu = dev;
struct arm_smmu_queue *q = &smmu->evtq.q;
if (queue_sync_prod(q) == -EOVERFLOW)
dev_err(smmu->dev, "EVTQ overflow detected -- events lost\n");
else if (queue_empty(q))
ret = IRQ_NONE;
return ret;
}
static irqreturn_t arm_smmu_priq_thread(int irq, void *dev)
{
struct arm_smmu_device *smmu = dev;
struct arm_smmu_queue *q = &smmu->priq.q;
u64 evt[PRIQ_ENT_DWORDS];
while (!queue_remove_raw(q, evt)) {
u32 sid, ssid;
u16 grpid;
bool ssv, last;
sid = evt[0] >> PRIQ_0_SID_SHIFT & PRIQ_0_SID_MASK;
ssv = evt[0] & PRIQ_0_SSID_V;
ssid = ssv ? evt[0] >> PRIQ_0_SSID_SHIFT & PRIQ_0_SSID_MASK : 0;
last = evt[0] & PRIQ_0_PRG_LAST;
grpid = evt[1] >> PRIQ_1_PRG_IDX_SHIFT & PRIQ_1_PRG_IDX_MASK;
dev_info(smmu->dev, "unexpected PRI request received:\n");
dev_info(smmu->dev,
"\tsid 0x%08x.0x%05x: [%u%s] %sprivileged %s%s%s access at iova 0x%016llx\n",
sid, ssid, grpid, last ? "L" : "",
evt[0] & PRIQ_0_PERM_PRIV ? "" : "un",
evt[0] & PRIQ_0_PERM_READ ? "R" : "",
evt[0] & PRIQ_0_PERM_WRITE ? "W" : "",
evt[0] & PRIQ_0_PERM_EXEC ? "X" : "",
evt[1] & PRIQ_1_ADDR_MASK << PRIQ_1_ADDR_SHIFT);
if (last) {
struct arm_smmu_cmdq_ent cmd = {
.opcode = CMDQ_OP_PRI_RESP,
.substream_valid = ssv,
.pri = {
.sid = sid,
.ssid = ssid,
.grpid = grpid,
.resp = PRI_RESP_DENY,
},
};
arm_smmu_cmdq_issue_cmd(smmu, &cmd);
}
}
q->cons = Q_OVF(q, q->prod) | Q_WRP(q, q->cons) | Q_IDX(q, q->cons);
return IRQ_HANDLED;
}
static irqreturn_t arm_smmu_priq_handler(int irq, void *dev)
{
irqreturn_t ret = IRQ_WAKE_THREAD;
struct arm_smmu_device *smmu = dev;
struct arm_smmu_queue *q = &smmu->priq.q;
if (queue_sync_prod(q) == -EOVERFLOW)
dev_err(smmu->dev, "PRIQ overflow detected -- requests lost\n");
else if (queue_empty(q))
ret = IRQ_NONE;
return ret;
}
static irqreturn_t arm_smmu_cmdq_sync_handler(int irq, void *dev)
{
return IRQ_HANDLED;
}
static irqreturn_t arm_smmu_gerror_handler(int irq, void *dev)
{
u32 gerror, gerrorn, active;
struct arm_smmu_device *smmu = dev;
gerror = readl_relaxed(smmu->base + ARM_SMMU_GERROR);
gerrorn = readl_relaxed(smmu->base + ARM_SMMU_GERRORN);
active = gerror ^ gerrorn;
if (!(active & GERROR_ERR_MASK))
return IRQ_NONE;
dev_warn(smmu->dev,
"unexpected global error reported (0x%08x), this could be serious\n",
active);
if (active & GERROR_SFM_ERR) {
dev_err(smmu->dev, "device has entered Service Failure Mode!\n");
arm_smmu_device_disable(smmu);
}
if (active & GERROR_MSI_GERROR_ABT_ERR)
dev_warn(smmu->dev, "GERROR MSI write aborted\n");
if (active & GERROR_MSI_PRIQ_ABT_ERR) {
dev_warn(smmu->dev, "PRIQ MSI write aborted\n");
arm_smmu_priq_handler(irq, smmu->dev);
}
if (active & GERROR_MSI_EVTQ_ABT_ERR) {
dev_warn(smmu->dev, "EVTQ MSI write aborted\n");
arm_smmu_evtq_handler(irq, smmu->dev);
}
if (active & GERROR_MSI_CMDQ_ABT_ERR) {
dev_warn(smmu->dev, "CMDQ MSI write aborted\n");
arm_smmu_cmdq_sync_handler(irq, smmu->dev);
}
if (active & GERROR_PRIQ_ABT_ERR)
dev_err(smmu->dev, "PRIQ write aborted -- events may have been lost\n");
if (active & GERROR_EVTQ_ABT_ERR)
dev_err(smmu->dev, "EVTQ write aborted -- events may have been lost\n");
if (active & GERROR_CMDQ_ERR)
arm_smmu_cmdq_skip_err(smmu);
writel(gerror, smmu->base + ARM_SMMU_GERRORN);
return IRQ_HANDLED;
}
static void __arm_smmu_tlb_sync(struct arm_smmu_device *smmu)
{
struct arm_smmu_cmdq_ent cmd;
cmd.opcode = CMDQ_OP_CMD_SYNC;
arm_smmu_cmdq_issue_cmd(smmu, &cmd);
}
static void arm_smmu_tlb_sync(void *cookie)
{
struct arm_smmu_domain *smmu_domain = cookie;
__arm_smmu_tlb_sync(smmu_domain->smmu);
}
static void arm_smmu_tlb_inv_context(void *cookie)
{
struct arm_smmu_domain *smmu_domain = cookie;
struct arm_smmu_device *smmu = smmu_domain->smmu;
struct arm_smmu_cmdq_ent cmd;
if (smmu_domain->stage == ARM_SMMU_DOMAIN_S1) {
cmd.opcode = CMDQ_OP_TLBI_NH_ASID;
cmd.tlbi.asid = smmu_domain->s1_cfg.cd.asid;
cmd.tlbi.vmid = 0;
} else {
cmd.opcode = CMDQ_OP_TLBI_S12_VMALL;
cmd.tlbi.vmid = smmu_domain->s2_cfg.vmid;
}
arm_smmu_cmdq_issue_cmd(smmu, &cmd);
__arm_smmu_tlb_sync(smmu);
}
static void arm_smmu_tlb_inv_range_nosync(unsigned long iova, size_t size,
size_t granule, bool leaf, void *cookie)
{
struct arm_smmu_domain *smmu_domain = cookie;
struct arm_smmu_device *smmu = smmu_domain->smmu;
struct arm_smmu_cmdq_ent cmd = {
.tlbi = {
.leaf = leaf,
.addr = iova,
},
};
if (smmu_domain->stage == ARM_SMMU_DOMAIN_S1) {
cmd.opcode = CMDQ_OP_TLBI_NH_VA;
cmd.tlbi.asid = smmu_domain->s1_cfg.cd.asid;
} else {
cmd.opcode = CMDQ_OP_TLBI_S2_IPA;
cmd.tlbi.vmid = smmu_domain->s2_cfg.vmid;
}
do {
arm_smmu_cmdq_issue_cmd(smmu, &cmd);
cmd.tlbi.addr += granule;
} while (size -= granule);
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
static struct iommu_domain *arm_smmu_domain_alloc(unsigned type)
{
struct arm_smmu_domain *smmu_domain;
if (type != IOMMU_DOMAIN_UNMANAGED && type != IOMMU_DOMAIN_DMA)
return NULL;
smmu_domain = kzalloc(sizeof(*smmu_domain), GFP_KERNEL);
if (!smmu_domain)
return NULL;
if (type == IOMMU_DOMAIN_DMA &&
iommu_get_dma_cookie(&smmu_domain->domain)) {
kfree(smmu_domain);
return NULL;
}
mutex_init(&smmu_domain->init_mutex);
spin_lock_init(&smmu_domain->pgtbl_lock);
return &smmu_domain->domain;
}
static int arm_smmu_bitmap_alloc(unsigned long *map, int span)
{
int idx, size = 1 << span;
do {
idx = find_first_zero_bit(map, size);
if (idx == size)
return -ENOSPC;
} while (test_and_set_bit(idx, map));
return idx;
}
static void arm_smmu_bitmap_free(unsigned long *map, int idx)
{
clear_bit(idx, map);
}
static void arm_smmu_domain_free(struct iommu_domain *domain)
{
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct arm_smmu_device *smmu = smmu_domain->smmu;
iommu_put_dma_cookie(domain);
free_io_pgtable_ops(smmu_domain->pgtbl_ops);
if (smmu_domain->stage == ARM_SMMU_DOMAIN_S1) {
struct arm_smmu_s1_cfg *cfg = &smmu_domain->s1_cfg;
if (cfg->cdptr) {
dmam_free_coherent(smmu_domain->smmu->dev,
CTXDESC_CD_DWORDS << 3,
cfg->cdptr,
cfg->cdptr_dma);
arm_smmu_bitmap_free(smmu->asid_map, cfg->cd.asid);
}
} else {
struct arm_smmu_s2_cfg *cfg = &smmu_domain->s2_cfg;
if (cfg->vmid)
arm_smmu_bitmap_free(smmu->vmid_map, cfg->vmid);
}
kfree(smmu_domain);
}
static int arm_smmu_domain_finalise_s1(struct arm_smmu_domain *smmu_domain,
struct io_pgtable_cfg *pgtbl_cfg)
{
int ret;
int asid;
struct arm_smmu_device *smmu = smmu_domain->smmu;
struct arm_smmu_s1_cfg *cfg = &smmu_domain->s1_cfg;
asid = arm_smmu_bitmap_alloc(smmu->asid_map, smmu->asid_bits);
if (asid < 0)
return asid;
cfg->cdptr = dmam_alloc_coherent(smmu->dev, CTXDESC_CD_DWORDS << 3,
&cfg->cdptr_dma,
GFP_KERNEL | __GFP_ZERO);
if (!cfg->cdptr) {
dev_warn(smmu->dev, "failed to allocate context descriptor\n");
ret = -ENOMEM;
goto out_free_asid;
}
cfg->cd.asid = (u16)asid;
cfg->cd.ttbr = pgtbl_cfg->arm_lpae_s1_cfg.ttbr[0];
cfg->cd.tcr = pgtbl_cfg->arm_lpae_s1_cfg.tcr;
cfg->cd.mair = pgtbl_cfg->arm_lpae_s1_cfg.mair[0];
return 0;
out_free_asid:
arm_smmu_bitmap_free(smmu->asid_map, asid);
return ret;
}
static int arm_smmu_domain_finalise_s2(struct arm_smmu_domain *smmu_domain,
struct io_pgtable_cfg *pgtbl_cfg)
{
int vmid;
struct arm_smmu_device *smmu = smmu_domain->smmu;
struct arm_smmu_s2_cfg *cfg = &smmu_domain->s2_cfg;
vmid = arm_smmu_bitmap_alloc(smmu->vmid_map, smmu->vmid_bits);
if (vmid < 0)
return vmid;
cfg->vmid = (u16)vmid;
cfg->vttbr = pgtbl_cfg->arm_lpae_s2_cfg.vttbr;
cfg->vtcr = pgtbl_cfg->arm_lpae_s2_cfg.vtcr;
return 0;
}
static int arm_smmu_domain_finalise(struct iommu_domain *domain)
{
int ret;
unsigned long ias, oas;
enum io_pgtable_fmt fmt;
struct io_pgtable_cfg pgtbl_cfg;
struct io_pgtable_ops *pgtbl_ops;
int (*finalise_stage_fn)(struct arm_smmu_domain *,
struct io_pgtable_cfg *);
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct arm_smmu_device *smmu = smmu_domain->smmu;
if (!(smmu->features & ARM_SMMU_FEAT_TRANS_S1))
smmu_domain->stage = ARM_SMMU_DOMAIN_S2;
if (!(smmu->features & ARM_SMMU_FEAT_TRANS_S2))
smmu_domain->stage = ARM_SMMU_DOMAIN_S1;
switch (smmu_domain->stage) {
case ARM_SMMU_DOMAIN_S1:
ias = VA_BITS;
oas = smmu->ias;
fmt = ARM_64_LPAE_S1;
finalise_stage_fn = arm_smmu_domain_finalise_s1;
break;
case ARM_SMMU_DOMAIN_NESTED:
case ARM_SMMU_DOMAIN_S2:
ias = smmu->ias;
oas = smmu->oas;
fmt = ARM_64_LPAE_S2;
finalise_stage_fn = arm_smmu_domain_finalise_s2;
break;
default:
return -EINVAL;
}
pgtbl_cfg = (struct io_pgtable_cfg) {
.pgsize_bitmap = smmu->pgsize_bitmap,
.ias = ias,
.oas = oas,
.tlb = &arm_smmu_gather_ops,
.iommu_dev = smmu->dev,
};
pgtbl_ops = alloc_io_pgtable_ops(fmt, &pgtbl_cfg, smmu_domain);
if (!pgtbl_ops)
return -ENOMEM;
domain->pgsize_bitmap = pgtbl_cfg.pgsize_bitmap;
smmu_domain->pgtbl_ops = pgtbl_ops;
ret = finalise_stage_fn(smmu_domain, &pgtbl_cfg);
if (ret < 0)
free_io_pgtable_ops(pgtbl_ops);
return ret;
}
static struct arm_smmu_group *arm_smmu_group_get(struct device *dev)
{
struct iommu_group *group;
struct arm_smmu_group *smmu_group;
group = iommu_group_get(dev);
if (!group)
return NULL;
smmu_group = iommu_group_get_iommudata(group);
iommu_group_put(group);
return smmu_group;
}
static __le64 *arm_smmu_get_step_for_sid(struct arm_smmu_device *smmu, u32 sid)
{
__le64 *step;
struct arm_smmu_strtab_cfg *cfg = &smmu->strtab_cfg;
if (smmu->features & ARM_SMMU_FEAT_2_LVL_STRTAB) {
struct arm_smmu_strtab_l1_desc *l1_desc;
int idx;
idx = (sid >> STRTAB_SPLIT) * STRTAB_L1_DESC_DWORDS;
l1_desc = &cfg->l1_desc[idx];
idx = (sid & ((1 << STRTAB_SPLIT) - 1)) * STRTAB_STE_DWORDS;
step = &l1_desc->l2ptr[idx];
} else {
step = &cfg->strtab[sid * STRTAB_STE_DWORDS];
}
return step;
}
static int arm_smmu_install_ste_for_group(struct arm_smmu_group *smmu_group)
{
int i;
struct arm_smmu_domain *smmu_domain = smmu_group->domain;
struct arm_smmu_strtab_ent *ste = &smmu_group->ste;
struct arm_smmu_device *smmu = smmu_group->smmu;
if (smmu_domain->stage == ARM_SMMU_DOMAIN_S1) {
ste->s1_cfg = &smmu_domain->s1_cfg;
ste->s2_cfg = NULL;
arm_smmu_write_ctx_desc(smmu, ste->s1_cfg);
} else {
ste->s1_cfg = NULL;
ste->s2_cfg = &smmu_domain->s2_cfg;
}
for (i = 0; i < smmu_group->num_sids; ++i) {
u32 sid = smmu_group->sids[i];
__le64 *step = arm_smmu_get_step_for_sid(smmu, sid);
arm_smmu_write_strtab_ent(smmu, sid, step, ste);
}
return 0;
}
static void arm_smmu_detach_dev(struct device *dev)
{
struct arm_smmu_group *smmu_group = arm_smmu_group_get(dev);
smmu_group->ste.bypass = true;
if (arm_smmu_install_ste_for_group(smmu_group) < 0)
dev_warn(dev, "failed to install bypass STE\n");
smmu_group->domain = NULL;
}
static int arm_smmu_attach_dev(struct iommu_domain *domain, struct device *dev)
{
int ret = 0;
struct arm_smmu_device *smmu;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct arm_smmu_group *smmu_group = arm_smmu_group_get(dev);
if (!smmu_group)
return -ENOENT;
if (smmu_group->domain && smmu_group->domain != smmu_domain)
arm_smmu_detach_dev(dev);
smmu = smmu_group->smmu;
mutex_lock(&smmu_domain->init_mutex);
if (!smmu_domain->smmu) {
smmu_domain->smmu = smmu;
ret = arm_smmu_domain_finalise(domain);
if (ret) {
smmu_domain->smmu = NULL;
goto out_unlock;
}
} else if (smmu_domain->smmu != smmu) {
dev_err(dev,
"cannot attach to SMMU %s (upstream of %s)\n",
dev_name(smmu_domain->smmu->dev),
dev_name(smmu->dev));
ret = -ENXIO;
goto out_unlock;
}
if (smmu_group->domain)
goto out_unlock;
smmu_group->domain = smmu_domain;
smmu_group->ste.bypass = domain->type == IOMMU_DOMAIN_DMA;
ret = arm_smmu_install_ste_for_group(smmu_group);
if (ret < 0)
smmu_group->domain = NULL;
out_unlock:
mutex_unlock(&smmu_domain->init_mutex);
return ret;
}
static int arm_smmu_map(struct iommu_domain *domain, unsigned long iova,
phys_addr_t paddr, size_t size, int prot)
{
int ret;
unsigned long flags;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct io_pgtable_ops *ops = smmu_domain->pgtbl_ops;
if (!ops)
return -ENODEV;
spin_lock_irqsave(&smmu_domain->pgtbl_lock, flags);
ret = ops->map(ops, iova, paddr, size, prot);
spin_unlock_irqrestore(&smmu_domain->pgtbl_lock, flags);
return ret;
}
static size_t
arm_smmu_unmap(struct iommu_domain *domain, unsigned long iova, size_t size)
{
size_t ret;
unsigned long flags;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct io_pgtable_ops *ops = smmu_domain->pgtbl_ops;
if (!ops)
return 0;
spin_lock_irqsave(&smmu_domain->pgtbl_lock, flags);
ret = ops->unmap(ops, iova, size);
spin_unlock_irqrestore(&smmu_domain->pgtbl_lock, flags);
return ret;
}
static phys_addr_t
arm_smmu_iova_to_phys(struct iommu_domain *domain, dma_addr_t iova)
{
phys_addr_t ret;
unsigned long flags;
struct arm_smmu_domain *smmu_domain = to_smmu_domain(domain);
struct io_pgtable_ops *ops = smmu_domain->pgtbl_ops;
if (!ops)
return 0;
spin_lock_irqsave(&smmu_domain->pgtbl_lock, flags);
ret = ops->iova_to_phys(ops, iova);
spin_unlock_irqrestore(&smmu_domain->pgtbl_lock, flags);
return ret;
}
static int __arm_smmu_get_pci_sid(struct pci_dev *pdev, u16 alias, void *sidp)
{
*(u32 *)sidp = alias;
return 0;
}
static void __arm_smmu_release_pci_iommudata(void *data)
{
kfree(data);
}
static struct arm_smmu_device *arm_smmu_get_for_pci_dev(struct pci_dev *pdev)
{
struct device_node *of_node;
struct platform_device *smmu_pdev;
struct arm_smmu_device *smmu = NULL;
struct pci_bus *bus = pdev->bus;
while (!pci_is_root_bus(bus))
bus = bus->parent;
of_node = of_parse_phandle(bus->bridge->parent->of_node, "iommus", 0);
if (!of_node)
return NULL;
smmu_pdev = of_find_device_by_node(of_node);
if (smmu_pdev)
smmu = platform_get_drvdata(smmu_pdev);
of_node_put(of_node);
return smmu;
}
static bool arm_smmu_sid_in_range(struct arm_smmu_device *smmu, u32 sid)
{
unsigned long limit = smmu->strtab_cfg.num_l1_ents;
if (smmu->features & ARM_SMMU_FEAT_2_LVL_STRTAB)
limit *= 1UL << STRTAB_SPLIT;
return sid < limit;
}
static int arm_smmu_add_device(struct device *dev)
{
int i, ret;
u32 sid, *sids;
struct pci_dev *pdev;
struct iommu_group *group;
struct arm_smmu_group *smmu_group;
struct arm_smmu_device *smmu;
if (!dev_is_pci(dev))
return -ENODEV;
pdev = to_pci_dev(dev);
group = iommu_group_get_for_dev(dev);
if (IS_ERR(group))
return PTR_ERR(group);
smmu_group = iommu_group_get_iommudata(group);
if (!smmu_group) {
smmu = arm_smmu_get_for_pci_dev(pdev);
if (!smmu) {
ret = -ENOENT;
goto out_remove_dev;
}
smmu_group = kzalloc(sizeof(*smmu_group), GFP_KERNEL);
if (!smmu_group) {
ret = -ENOMEM;
goto out_remove_dev;
}
smmu_group->ste.valid = true;
smmu_group->smmu = smmu;
iommu_group_set_iommudata(group, smmu_group,
__arm_smmu_release_pci_iommudata);
} else {
smmu = smmu_group->smmu;
}
pci_for_each_dma_alias(pdev, __arm_smmu_get_pci_sid, &sid);
for (i = 0; i < smmu_group->num_sids; ++i) {
if (smmu_group->sids[i] == sid)
goto out_put_group;
}
if (!arm_smmu_sid_in_range(smmu, sid)) {
ret = -ERANGE;
goto out_remove_dev;
}
if (smmu->features & ARM_SMMU_FEAT_2_LVL_STRTAB) {
ret = arm_smmu_init_l2_strtab(smmu, sid);
if (ret)
goto out_remove_dev;
}
smmu_group->num_sids++;
sids = krealloc(smmu_group->sids, smmu_group->num_sids * sizeof(*sids),
GFP_KERNEL);
if (!sids) {
smmu_group->num_sids--;
ret = -ENOMEM;
goto out_remove_dev;
}
sids[smmu_group->num_sids - 1] = sid;
smmu_group->sids = sids;
out_put_group:
iommu_group_put(group);
return 0;
out_remove_dev:
iommu_group_remove_device(dev);
iommu_group_put(group);
return ret;
}
static void arm_smmu_remove_device(struct device *dev)
{
iommu_group_remove_device(dev);
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
static int arm_smmu_init_one_queue(struct arm_smmu_device *smmu,
struct arm_smmu_queue *q,
unsigned long prod_off,
unsigned long cons_off,
size_t dwords)
{
size_t qsz = ((1 << q->max_n_shift) * dwords) << 3;
q->base = dmam_alloc_coherent(smmu->dev, qsz, &q->base_dma, GFP_KERNEL);
if (!q->base) {
dev_err(smmu->dev, "failed to allocate queue (0x%zx bytes)\n",
qsz);
return -ENOMEM;
}
q->prod_reg = smmu->base + prod_off;
q->cons_reg = smmu->base + cons_off;
q->ent_dwords = dwords;
q->q_base = Q_BASE_RWA;
q->q_base |= q->base_dma & Q_BASE_ADDR_MASK << Q_BASE_ADDR_SHIFT;
q->q_base |= (q->max_n_shift & Q_BASE_LOG2SIZE_MASK)
<< Q_BASE_LOG2SIZE_SHIFT;
q->prod = q->cons = 0;
return 0;
}
static int arm_smmu_init_queues(struct arm_smmu_device *smmu)
{
int ret;
spin_lock_init(&smmu->cmdq.lock);
ret = arm_smmu_init_one_queue(smmu, &smmu->cmdq.q, ARM_SMMU_CMDQ_PROD,
ARM_SMMU_CMDQ_CONS, CMDQ_ENT_DWORDS);
if (ret)
return ret;
ret = arm_smmu_init_one_queue(smmu, &smmu->evtq.q, ARM_SMMU_EVTQ_PROD,
ARM_SMMU_EVTQ_CONS, EVTQ_ENT_DWORDS);
if (ret)
return ret;
if (!(smmu->features & ARM_SMMU_FEAT_PRI))
return 0;
return arm_smmu_init_one_queue(smmu, &smmu->priq.q, ARM_SMMU_PRIQ_PROD,
ARM_SMMU_PRIQ_CONS, PRIQ_ENT_DWORDS);
}
static int arm_smmu_init_l1_strtab(struct arm_smmu_device *smmu)
{
unsigned int i;
struct arm_smmu_strtab_cfg *cfg = &smmu->strtab_cfg;
size_t size = sizeof(*cfg->l1_desc) * cfg->num_l1_ents;
void *strtab = smmu->strtab_cfg.strtab;
cfg->l1_desc = devm_kzalloc(smmu->dev, size, GFP_KERNEL);
if (!cfg->l1_desc) {
dev_err(smmu->dev, "failed to allocate l1 stream table desc\n");
return -ENOMEM;
}
for (i = 0; i < cfg->num_l1_ents; ++i) {
arm_smmu_write_strtab_l1_desc(strtab, &cfg->l1_desc[i]);
strtab += STRTAB_L1_DESC_DWORDS << 3;
}
return 0;
}
static int arm_smmu_init_strtab_2lvl(struct arm_smmu_device *smmu)
{
void *strtab;
u64 reg;
u32 size, l1size;
struct arm_smmu_strtab_cfg *cfg = &smmu->strtab_cfg;
if (smmu->sid_bits < STRTAB_SPLIT) {
size = 0;
} else {
size = STRTAB_L1_SZ_SHIFT - (ilog2(STRTAB_L1_DESC_DWORDS) + 3);
size = min(size, smmu->sid_bits - STRTAB_SPLIT);
}
cfg->num_l1_ents = 1 << size;
size += STRTAB_SPLIT;
if (size < smmu->sid_bits)
dev_warn(smmu->dev,
"2-level strtab only covers %u/%u bits of SID\n",
size, smmu->sid_bits);
l1size = cfg->num_l1_ents * (STRTAB_L1_DESC_DWORDS << 3);
strtab = dmam_alloc_coherent(smmu->dev, l1size, &cfg->strtab_dma,
GFP_KERNEL | __GFP_ZERO);
if (!strtab) {
dev_err(smmu->dev,
"failed to allocate l1 stream table (%u bytes)\n",
size);
return -ENOMEM;
}
cfg->strtab = strtab;
reg = STRTAB_BASE_CFG_FMT_2LVL;
reg |= (size & STRTAB_BASE_CFG_LOG2SIZE_MASK)
<< STRTAB_BASE_CFG_LOG2SIZE_SHIFT;
reg |= (STRTAB_SPLIT & STRTAB_BASE_CFG_SPLIT_MASK)
<< STRTAB_BASE_CFG_SPLIT_SHIFT;
cfg->strtab_base_cfg = reg;
return arm_smmu_init_l1_strtab(smmu);
}
static int arm_smmu_init_strtab_linear(struct arm_smmu_device *smmu)
{
void *strtab;
u64 reg;
u32 size;
struct arm_smmu_strtab_cfg *cfg = &smmu->strtab_cfg;
size = (1 << smmu->sid_bits) * (STRTAB_STE_DWORDS << 3);
strtab = dmam_alloc_coherent(smmu->dev, size, &cfg->strtab_dma,
GFP_KERNEL | __GFP_ZERO);
if (!strtab) {
dev_err(smmu->dev,
"failed to allocate linear stream table (%u bytes)\n",
size);
return -ENOMEM;
}
cfg->strtab = strtab;
cfg->num_l1_ents = 1 << smmu->sid_bits;
reg = STRTAB_BASE_CFG_FMT_LINEAR;
reg |= (smmu->sid_bits & STRTAB_BASE_CFG_LOG2SIZE_MASK)
<< STRTAB_BASE_CFG_LOG2SIZE_SHIFT;
cfg->strtab_base_cfg = reg;
arm_smmu_init_bypass_stes(strtab, cfg->num_l1_ents);
return 0;
}
static int arm_smmu_init_strtab(struct arm_smmu_device *smmu)
{
u64 reg;
int ret;
if (smmu->features & ARM_SMMU_FEAT_2_LVL_STRTAB)
ret = arm_smmu_init_strtab_2lvl(smmu);
else
ret = arm_smmu_init_strtab_linear(smmu);
if (ret)
return ret;
reg = smmu->strtab_cfg.strtab_dma &
STRTAB_BASE_ADDR_MASK << STRTAB_BASE_ADDR_SHIFT;
reg |= STRTAB_BASE_RA;
smmu->strtab_cfg.strtab_base = reg;
set_bit(0, smmu->vmid_map);
return 0;
}
static int arm_smmu_init_structures(struct arm_smmu_device *smmu)
{
int ret;
ret = arm_smmu_init_queues(smmu);
if (ret)
return ret;
return arm_smmu_init_strtab(smmu);
}
static int arm_smmu_write_reg_sync(struct arm_smmu_device *smmu, u32 val,
unsigned int reg_off, unsigned int ack_off)
{
u32 reg;
writel_relaxed(val, smmu->base + reg_off);
return readl_relaxed_poll_timeout(smmu->base + ack_off, reg, reg == val,
1, ARM_SMMU_POLL_TIMEOUT_US);
}
static void arm_smmu_free_msis(void *data)
{
struct device *dev = data;
platform_msi_domain_free_irqs(dev);
}
static void arm_smmu_write_msi_msg(struct msi_desc *desc, struct msi_msg *msg)
{
phys_addr_t doorbell;
struct device *dev = msi_desc_to_dev(desc);
struct arm_smmu_device *smmu = dev_get_drvdata(dev);
phys_addr_t *cfg = arm_smmu_msi_cfg[desc->platform.msi_index];
doorbell = (((u64)msg->address_hi) << 32) | msg->address_lo;
doorbell &= MSI_CFG0_ADDR_MASK << MSI_CFG0_ADDR_SHIFT;
writeq_relaxed(doorbell, smmu->base + cfg[0]);
writel_relaxed(msg->data, smmu->base + cfg[1]);
writel_relaxed(MSI_CFG2_MEMATTR_DEVICE_nGnRE, smmu->base + cfg[2]);
}
static void arm_smmu_setup_msis(struct arm_smmu_device *smmu)
{
struct msi_desc *desc;
int ret, nvec = ARM_SMMU_MAX_MSIS;
struct device *dev = smmu->dev;
writeq_relaxed(0, smmu->base + ARM_SMMU_GERROR_IRQ_CFG0);
writeq_relaxed(0, smmu->base + ARM_SMMU_EVTQ_IRQ_CFG0);
if (smmu->features & ARM_SMMU_FEAT_PRI)
writeq_relaxed(0, smmu->base + ARM_SMMU_PRIQ_IRQ_CFG0);
else
nvec--;
if (!(smmu->features & ARM_SMMU_FEAT_MSI))
return;
ret = platform_msi_domain_alloc_irqs(dev, nvec, arm_smmu_write_msi_msg);
if (ret) {
dev_warn(dev, "failed to allocate MSIs\n");
return;
}
for_each_msi_entry(desc, dev) {
switch (desc->platform.msi_index) {
case EVTQ_MSI_INDEX:
smmu->evtq.q.irq = desc->irq;
break;
case GERROR_MSI_INDEX:
smmu->gerr_irq = desc->irq;
break;
case PRIQ_MSI_INDEX:
smmu->priq.q.irq = desc->irq;
break;
default:
continue;
}
}
devm_add_action(dev, arm_smmu_free_msis, dev);
}
static int arm_smmu_setup_irqs(struct arm_smmu_device *smmu)
{
int ret, irq;
u32 irqen_flags = IRQ_CTRL_EVTQ_IRQEN | IRQ_CTRL_GERROR_IRQEN;
ret = arm_smmu_write_reg_sync(smmu, 0, ARM_SMMU_IRQ_CTRL,
ARM_SMMU_IRQ_CTRLACK);
if (ret) {
dev_err(smmu->dev, "failed to disable irqs\n");
return ret;
}
arm_smmu_setup_msis(smmu);
irq = smmu->evtq.q.irq;
if (irq) {
ret = devm_request_threaded_irq(smmu->dev, irq,
arm_smmu_evtq_handler,
arm_smmu_evtq_thread,
0, "arm-smmu-v3-evtq", smmu);
if (ret < 0)
dev_warn(smmu->dev, "failed to enable evtq irq\n");
}
irq = smmu->cmdq.q.irq;
if (irq) {
ret = devm_request_irq(smmu->dev, irq,
arm_smmu_cmdq_sync_handler, 0,
"arm-smmu-v3-cmdq-sync", smmu);
if (ret < 0)
dev_warn(smmu->dev, "failed to enable cmdq-sync irq\n");
}
irq = smmu->gerr_irq;
if (irq) {
ret = devm_request_irq(smmu->dev, irq, arm_smmu_gerror_handler,
0, "arm-smmu-v3-gerror", smmu);
if (ret < 0)
dev_warn(smmu->dev, "failed to enable gerror irq\n");
}
if (smmu->features & ARM_SMMU_FEAT_PRI) {
irq = smmu->priq.q.irq;
if (irq) {
ret = devm_request_threaded_irq(smmu->dev, irq,
arm_smmu_priq_handler,
arm_smmu_priq_thread,
0, "arm-smmu-v3-priq",
smmu);
if (ret < 0)
dev_warn(smmu->dev,
"failed to enable priq irq\n");
else
irqen_flags |= IRQ_CTRL_PRIQ_IRQEN;
}
}
ret = arm_smmu_write_reg_sync(smmu, irqen_flags,
ARM_SMMU_IRQ_CTRL, ARM_SMMU_IRQ_CTRLACK);
if (ret)
dev_warn(smmu->dev, "failed to enable irqs\n");
return 0;
}
static int arm_smmu_device_disable(struct arm_smmu_device *smmu)
{
int ret;
ret = arm_smmu_write_reg_sync(smmu, 0, ARM_SMMU_CR0, ARM_SMMU_CR0ACK);
if (ret)
dev_err(smmu->dev, "failed to clear cr0\n");
return ret;
}
static int arm_smmu_device_reset(struct arm_smmu_device *smmu)
{
int ret;
u32 reg, enables;
struct arm_smmu_cmdq_ent cmd;
reg = readl_relaxed(smmu->base + ARM_SMMU_CR0);
if (reg & CR0_SMMUEN)
dev_warn(smmu->dev, "SMMU currently enabled! Resetting...\n");
ret = arm_smmu_device_disable(smmu);
if (ret)
return ret;
reg = (CR1_SH_ISH << CR1_TABLE_SH_SHIFT) |
(CR1_CACHE_WB << CR1_TABLE_OC_SHIFT) |
(CR1_CACHE_WB << CR1_TABLE_IC_SHIFT) |
(CR1_SH_ISH << CR1_QUEUE_SH_SHIFT) |
(CR1_CACHE_WB << CR1_QUEUE_OC_SHIFT) |
(CR1_CACHE_WB << CR1_QUEUE_IC_SHIFT);
writel_relaxed(reg, smmu->base + ARM_SMMU_CR1);
reg = CR2_PTM | CR2_RECINVSID | CR2_E2H;
writel_relaxed(reg, smmu->base + ARM_SMMU_CR2);
writeq_relaxed(smmu->strtab_cfg.strtab_base,
smmu->base + ARM_SMMU_STRTAB_BASE);
writel_relaxed(smmu->strtab_cfg.strtab_base_cfg,
smmu->base + ARM_SMMU_STRTAB_BASE_CFG);
writeq_relaxed(smmu->cmdq.q.q_base, smmu->base + ARM_SMMU_CMDQ_BASE);
writel_relaxed(smmu->cmdq.q.prod, smmu->base + ARM_SMMU_CMDQ_PROD);
writel_relaxed(smmu->cmdq.q.cons, smmu->base + ARM_SMMU_CMDQ_CONS);
enables = CR0_CMDQEN;
ret = arm_smmu_write_reg_sync(smmu, enables, ARM_SMMU_CR0,
ARM_SMMU_CR0ACK);
if (ret) {
dev_err(smmu->dev, "failed to enable command queue\n");
return ret;
}
cmd.opcode = CMDQ_OP_CFGI_ALL;
arm_smmu_cmdq_issue_cmd(smmu, &cmd);
cmd.opcode = CMDQ_OP_CMD_SYNC;
arm_smmu_cmdq_issue_cmd(smmu, &cmd);
if (smmu->features & ARM_SMMU_FEAT_HYP) {
cmd.opcode = CMDQ_OP_TLBI_EL2_ALL;
arm_smmu_cmdq_issue_cmd(smmu, &cmd);
}
cmd.opcode = CMDQ_OP_TLBI_NSNH_ALL;
arm_smmu_cmdq_issue_cmd(smmu, &cmd);
cmd.opcode = CMDQ_OP_CMD_SYNC;
arm_smmu_cmdq_issue_cmd(smmu, &cmd);
writeq_relaxed(smmu->evtq.q.q_base, smmu->base + ARM_SMMU_EVTQ_BASE);
writel_relaxed(smmu->evtq.q.prod, smmu->base + ARM_SMMU_EVTQ_PROD);
writel_relaxed(smmu->evtq.q.cons, smmu->base + ARM_SMMU_EVTQ_CONS);
enables |= CR0_EVTQEN;
ret = arm_smmu_write_reg_sync(smmu, enables, ARM_SMMU_CR0,
ARM_SMMU_CR0ACK);
if (ret) {
dev_err(smmu->dev, "failed to enable event queue\n");
return ret;
}
if (smmu->features & ARM_SMMU_FEAT_PRI) {
writeq_relaxed(smmu->priq.q.q_base,
smmu->base + ARM_SMMU_PRIQ_BASE);
writel_relaxed(smmu->priq.q.prod,
smmu->base + ARM_SMMU_PRIQ_PROD);
writel_relaxed(smmu->priq.q.cons,
smmu->base + ARM_SMMU_PRIQ_CONS);
enables |= CR0_PRIQEN;
ret = arm_smmu_write_reg_sync(smmu, enables, ARM_SMMU_CR0,
ARM_SMMU_CR0ACK);
if (ret) {
dev_err(smmu->dev, "failed to enable PRI queue\n");
return ret;
}
}
ret = arm_smmu_setup_irqs(smmu);
if (ret) {
dev_err(smmu->dev, "failed to setup irqs\n");
return ret;
}
enables |= CR0_SMMUEN;
ret = arm_smmu_write_reg_sync(smmu, enables, ARM_SMMU_CR0,
ARM_SMMU_CR0ACK);
if (ret) {
dev_err(smmu->dev, "failed to enable SMMU interface\n");
return ret;
}
return 0;
}
static int arm_smmu_device_probe(struct arm_smmu_device *smmu)
{
u32 reg;
bool coherent;
reg = readl_relaxed(smmu->base + ARM_SMMU_IDR0);
if ((reg & IDR0_ST_LVL_MASK << IDR0_ST_LVL_SHIFT) == IDR0_ST_LVL_2LVL)
smmu->features |= ARM_SMMU_FEAT_2_LVL_STRTAB;
if (reg & IDR0_CD2L)
smmu->features |= ARM_SMMU_FEAT_2_LVL_CDTAB;
switch (reg & IDR0_TTENDIAN_MASK << IDR0_TTENDIAN_SHIFT) {
case IDR0_TTENDIAN_MIXED:
smmu->features |= ARM_SMMU_FEAT_TT_LE | ARM_SMMU_FEAT_TT_BE;
break;
#ifdef __BIG_ENDIAN
case IDR0_TTENDIAN_BE:
smmu->features |= ARM_SMMU_FEAT_TT_BE;
break;
#else
case IDR0_TTENDIAN_LE:
smmu->features |= ARM_SMMU_FEAT_TT_LE;
break;
#endif
default:
dev_err(smmu->dev, "unknown/unsupported TT endianness!\n");
return -ENXIO;
}
if (IS_ENABLED(CONFIG_PCI_PRI) && reg & IDR0_PRI)
smmu->features |= ARM_SMMU_FEAT_PRI;
if (IS_ENABLED(CONFIG_PCI_ATS) && reg & IDR0_ATS)
smmu->features |= ARM_SMMU_FEAT_ATS;
if (reg & IDR0_SEV)
smmu->features |= ARM_SMMU_FEAT_SEV;
if (reg & IDR0_MSI)
smmu->features |= ARM_SMMU_FEAT_MSI;
if (reg & IDR0_HYP)
smmu->features |= ARM_SMMU_FEAT_HYP;
coherent = of_dma_is_coherent(smmu->dev->of_node);
if (coherent)
smmu->features |= ARM_SMMU_FEAT_COHERENCY;
if (!!(reg & IDR0_COHACC) != coherent)
dev_warn(smmu->dev, "IDR0.COHACC overridden by dma-coherent property (%s)\n",
coherent ? "true" : "false");
switch (reg & IDR0_STALL_MODEL_MASK << IDR0_STALL_MODEL_SHIFT) {
case IDR0_STALL_MODEL_STALL:
case IDR0_STALL_MODEL_FORCE:
smmu->features |= ARM_SMMU_FEAT_STALLS;
}
if (reg & IDR0_S1P)
smmu->features |= ARM_SMMU_FEAT_TRANS_S1;
if (reg & IDR0_S2P)
smmu->features |= ARM_SMMU_FEAT_TRANS_S2;
if (!(reg & (IDR0_S1P | IDR0_S2P))) {
dev_err(smmu->dev, "no translation support!\n");
return -ENXIO;
}
switch (reg & IDR0_TTF_MASK << IDR0_TTF_SHIFT) {
case IDR0_TTF_AARCH32_64:
smmu->ias = 40;
case IDR0_TTF_AARCH64:
break;
default:
dev_err(smmu->dev, "AArch64 table format not supported!\n");
return -ENXIO;
}
smmu->asid_bits = reg & IDR0_ASID16 ? 16 : 8;
smmu->vmid_bits = reg & IDR0_VMID16 ? 16 : 8;
reg = readl_relaxed(smmu->base + ARM_SMMU_IDR1);
if (reg & (IDR1_TABLES_PRESET | IDR1_QUEUES_PRESET | IDR1_REL)) {
dev_err(smmu->dev, "embedded implementation not supported\n");
return -ENXIO;
}
smmu->cmdq.q.max_n_shift = min((u32)CMDQ_MAX_SZ_SHIFT,
reg >> IDR1_CMDQ_SHIFT & IDR1_CMDQ_MASK);
if (!smmu->cmdq.q.max_n_shift) {
dev_err(smmu->dev, "unit-length command queue not supported\n");
return -ENXIO;
}
smmu->evtq.q.max_n_shift = min((u32)EVTQ_MAX_SZ_SHIFT,
reg >> IDR1_EVTQ_SHIFT & IDR1_EVTQ_MASK);
smmu->priq.q.max_n_shift = min((u32)PRIQ_MAX_SZ_SHIFT,
reg >> IDR1_PRIQ_SHIFT & IDR1_PRIQ_MASK);
smmu->ssid_bits = reg >> IDR1_SSID_SHIFT & IDR1_SSID_MASK;
smmu->sid_bits = reg >> IDR1_SID_SHIFT & IDR1_SID_MASK;
reg = readl_relaxed(smmu->base + ARM_SMMU_IDR5);
smmu->evtq.max_stalls = reg >> IDR5_STALL_MAX_SHIFT
& IDR5_STALL_MAX_MASK;
if (reg & IDR5_GRAN64K)
smmu->pgsize_bitmap |= SZ_64K | SZ_512M;
if (reg & IDR5_GRAN16K)
smmu->pgsize_bitmap |= SZ_16K | SZ_32M;
if (reg & IDR5_GRAN4K)
smmu->pgsize_bitmap |= SZ_4K | SZ_2M | SZ_1G;
if (arm_smmu_ops.pgsize_bitmap == -1UL)
arm_smmu_ops.pgsize_bitmap = smmu->pgsize_bitmap;
else
arm_smmu_ops.pgsize_bitmap |= smmu->pgsize_bitmap;
switch (reg & IDR5_OAS_MASK << IDR5_OAS_SHIFT) {
case IDR5_OAS_32_BIT:
smmu->oas = 32;
break;
case IDR5_OAS_36_BIT:
smmu->oas = 36;
break;
case IDR5_OAS_40_BIT:
smmu->oas = 40;
break;
case IDR5_OAS_42_BIT:
smmu->oas = 42;
break;
case IDR5_OAS_44_BIT:
smmu->oas = 44;
break;
default:
dev_info(smmu->dev,
"unknown output address size. Truncating to 48-bit\n");
case IDR5_OAS_48_BIT:
smmu->oas = 48;
}
if (dma_set_mask_and_coherent(smmu->dev, DMA_BIT_MASK(smmu->oas)))
dev_warn(smmu->dev,
"failed to set DMA mask for table walker\n");
smmu->ias = max(smmu->ias, smmu->oas);
dev_info(smmu->dev, "ias %lu-bit, oas %lu-bit (features 0x%08x)\n",
smmu->ias, smmu->oas, smmu->features);
return 0;
}
static int arm_smmu_device_dt_probe(struct platform_device *pdev)
{
int irq, ret;
struct resource *res;
struct arm_smmu_device *smmu;
struct device *dev = &pdev->dev;
smmu = devm_kzalloc(dev, sizeof(*smmu), GFP_KERNEL);
if (!smmu) {
dev_err(dev, "failed to allocate arm_smmu_device\n");
return -ENOMEM;
}
smmu->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (resource_size(res) + 1 < SZ_128K) {
dev_err(dev, "MMIO region too small (%pr)\n", res);
return -EINVAL;
}
smmu->base = devm_ioremap_resource(dev, res);
if (IS_ERR(smmu->base))
return PTR_ERR(smmu->base);
irq = platform_get_irq_byname(pdev, "eventq");
if (irq > 0)
smmu->evtq.q.irq = irq;
irq = platform_get_irq_byname(pdev, "priq");
if (irq > 0)
smmu->priq.q.irq = irq;
irq = platform_get_irq_byname(pdev, "cmdq-sync");
if (irq > 0)
smmu->cmdq.q.irq = irq;
irq = platform_get_irq_byname(pdev, "gerror");
if (irq > 0)
smmu->gerr_irq = irq;
parse_driver_options(smmu);
ret = arm_smmu_device_probe(smmu);
if (ret)
return ret;
ret = arm_smmu_init_structures(smmu);
if (ret)
return ret;
platform_set_drvdata(pdev, smmu);
return arm_smmu_device_reset(smmu);
}
static int arm_smmu_device_remove(struct platform_device *pdev)
{
struct arm_smmu_device *smmu = platform_get_drvdata(pdev);
arm_smmu_device_disable(smmu);
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
pci_request_acs();
return bus_set_iommu(&pci_bus_type, &arm_smmu_ops);
}
static void __exit arm_smmu_exit(void)
{
return platform_driver_unregister(&arm_smmu_driver);
}
