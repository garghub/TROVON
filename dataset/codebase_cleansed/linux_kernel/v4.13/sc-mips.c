static void mips_sc_wback_inv(unsigned long addr, unsigned long size)
{
blast_scache_range(addr, addr + size);
}
static void mips_sc_inv(unsigned long addr, unsigned long size)
{
unsigned long lsize = cpu_scache_line_size();
unsigned long almask = ~(lsize - 1);
cache_op(Hit_Writeback_Inv_SD, addr & almask);
cache_op(Hit_Writeback_Inv_SD, (addr + size - 1) & almask);
blast_inv_scache_range(addr, addr + size);
}
static void mips_sc_enable(void)
{
}
static void mips_sc_disable(void)
{
}
static void mips_sc_prefetch_enable(void)
{
unsigned long pftctl;
if (mips_cm_revision() < CM_REV_CM2_5)
return;
pftctl = read_gcr_l2_pft_control();
if (pftctl & CM_GCR_L2_PFT_CONTROL_NPFT_MSK) {
pftctl &= ~CM_GCR_L2_PFT_CONTROL_PAGEMASK_MSK;
pftctl |= PAGE_MASK & CM_GCR_L2_PFT_CONTROL_PAGEMASK_MSK;
pftctl |= CM_GCR_L2_PFT_CONTROL_PFTEN_MSK;
write_gcr_l2_pft_control(pftctl);
pftctl = read_gcr_l2_pft_control_b();
pftctl |= CM_GCR_L2_PFT_CONTROL_B_PORTID_MSK;
pftctl |= CM_GCR_L2_PFT_CONTROL_B_CEN_MSK;
write_gcr_l2_pft_control_b(pftctl);
}
}
static void mips_sc_prefetch_disable(void)
{
unsigned long pftctl;
if (mips_cm_revision() < CM_REV_CM2_5)
return;
pftctl = read_gcr_l2_pft_control();
pftctl &= ~CM_GCR_L2_PFT_CONTROL_PFTEN_MSK;
write_gcr_l2_pft_control(pftctl);
pftctl = read_gcr_l2_pft_control_b();
pftctl &= ~CM_GCR_L2_PFT_CONTROL_B_PORTID_MSK;
pftctl &= ~CM_GCR_L2_PFT_CONTROL_B_CEN_MSK;
write_gcr_l2_pft_control_b(pftctl);
}
static bool mips_sc_prefetch_is_enabled(void)
{
unsigned long pftctl;
if (mips_cm_revision() < CM_REV_CM2_5)
return false;
pftctl = read_gcr_l2_pft_control();
if (!(pftctl & CM_GCR_L2_PFT_CONTROL_NPFT_MSK))
return false;
return !!(pftctl & CM_GCR_L2_PFT_CONTROL_PFTEN_MSK);
}
static inline int mips_sc_is_activated(struct cpuinfo_mips *c)
{
unsigned int config2 = read_c0_config2();
unsigned int tmp;
switch (current_cpu_type()) {
case CPU_34K:
case CPU_74K:
case CPU_1004K:
case CPU_1074K:
case CPU_INTERAPTIV:
case CPU_PROAPTIV:
case CPU_P5600:
case CPU_BMIPS5000:
case CPU_QEMU_GENERIC:
case CPU_P6600:
if (config2 & (1 << 12))
return 0;
}
tmp = (config2 >> 4) & 0x0f;
if (0 < tmp && tmp <= 7)
c->scache.linesz = 2 << tmp;
else
return 0;
return 1;
}
static int __init mips_sc_probe_cm3(void)
{
struct cpuinfo_mips *c = &current_cpu_data;
unsigned long cfg = read_gcr_l2_config();
unsigned long sets, line_sz, assoc;
if (cfg & CM_GCR_L2_CONFIG_BYPASS_MSK)
return 0;
sets = cfg & CM_GCR_L2_CONFIG_SET_SIZE_MSK;
sets >>= CM_GCR_L2_CONFIG_SET_SIZE_SHF;
if (sets)
c->scache.sets = 64 << sets;
line_sz = cfg & CM_GCR_L2_CONFIG_LINE_SIZE_MSK;
line_sz >>= CM_GCR_L2_CONFIG_LINE_SIZE_SHF;
if (line_sz)
c->scache.linesz = 2 << line_sz;
assoc = cfg & CM_GCR_L2_CONFIG_ASSOC_MSK;
assoc >>= CM_GCR_L2_CONFIG_ASSOC_SHF;
c->scache.ways = assoc + 1;
c->scache.waysize = c->scache.sets * c->scache.linesz;
c->scache.waybit = __ffs(c->scache.waysize);
if (c->scache.linesz) {
c->scache.flags &= ~MIPS_CACHE_NOT_PRESENT;
c->options |= MIPS_CPU_INCLUSIVE_CACHES;
return 1;
}
return 0;
}
static inline int __init mips_sc_probe(void)
{
struct cpuinfo_mips *c = &current_cpu_data;
unsigned int config1, config2;
unsigned int tmp;
c->scache.flags |= MIPS_CACHE_NOT_PRESENT;
if (mips_cm_revision() >= CM_REV_CM3)
return mips_sc_probe_cm3();
if (!(c->isa_level & (MIPS_CPU_ISA_M32R1 | MIPS_CPU_ISA_M32R2 |
MIPS_CPU_ISA_M32R6 | MIPS_CPU_ISA_M64R1 |
MIPS_CPU_ISA_M64R2 | MIPS_CPU_ISA_M64R6)))
return 0;
config1 = read_c0_config1();
if (!(config1 & MIPS_CONF_M))
return 0;
config2 = read_c0_config2();
if (!mips_sc_is_activated(c))
return 0;
tmp = (config2 >> 8) & 0x0f;
if (tmp <= 7)
c->scache.sets = 64 << tmp;
else
return 0;
tmp = (config2 >> 0) & 0x0f;
if (tmp <= 7)
c->scache.ways = tmp + 1;
else
return 0;
c->scache.waysize = c->scache.sets * c->scache.linesz;
c->scache.waybit = __ffs(c->scache.waysize);
c->scache.flags &= ~MIPS_CACHE_NOT_PRESENT;
return 1;
}
int mips_sc_init(void)
{
int found = mips_sc_probe();
if (found) {
mips_sc_enable();
mips_sc_prefetch_enable();
bcops = &mips_sc_ops;
}
return found;
}
