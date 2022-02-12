static int search_cmp_ftr_reg(const void *id, const void *regp)
{
return (int)(unsigned long)id - (int)((const struct __ftr_reg_entry *)regp)->sys_id;
}
static struct arm64_ftr_reg *get_arm64_ftr_reg(u32 sys_id)
{
const struct __ftr_reg_entry *ret;
ret = bsearch((const void *)(unsigned long)sys_id,
arm64_ftr_regs,
ARRAY_SIZE(arm64_ftr_regs),
sizeof(arm64_ftr_regs[0]),
search_cmp_ftr_reg);
if (ret)
return ret->reg;
return NULL;
}
static u64 arm64_ftr_set_value(const struct arm64_ftr_bits *ftrp, s64 reg,
s64 ftr_val)
{
u64 mask = arm64_ftr_mask(ftrp);
reg &= ~mask;
reg |= (ftr_val << ftrp->shift) & mask;
return reg;
}
static s64 arm64_ftr_safe_value(const struct arm64_ftr_bits *ftrp, s64 new,
s64 cur)
{
s64 ret = 0;
switch (ftrp->type) {
case FTR_EXACT:
ret = ftrp->safe_val;
break;
case FTR_LOWER_SAFE:
ret = new < cur ? new : cur;
break;
case FTR_HIGHER_SAFE:
ret = new > cur ? new : cur;
break;
default:
BUG();
}
return ret;
}
static void __init sort_ftr_regs(void)
{
int i;
for (i = 1; i < ARRAY_SIZE(arm64_ftr_regs); i++)
BUG_ON(arm64_ftr_regs[i].sys_id < arm64_ftr_regs[i - 1].sys_id);
}
static void __init init_cpu_ftr_reg(u32 sys_reg, u64 new)
{
u64 val = 0;
u64 strict_mask = ~0x0ULL;
const struct arm64_ftr_bits *ftrp;
struct arm64_ftr_reg *reg = get_arm64_ftr_reg(sys_reg);
BUG_ON(!reg);
for (ftrp = reg->ftr_bits; ftrp->width; ftrp++) {
s64 ftr_new = arm64_ftr_value(ftrp, new);
val = arm64_ftr_set_value(ftrp, val, ftr_new);
if (!ftrp->strict)
strict_mask &= ~arm64_ftr_mask(ftrp);
}
reg->sys_val = val;
reg->strict_mask = strict_mask;
}
void __init init_cpu_features(struct cpuinfo_arm64 *info)
{
sort_ftr_regs();
init_cpu_ftr_reg(SYS_CTR_EL0, info->reg_ctr);
init_cpu_ftr_reg(SYS_DCZID_EL0, info->reg_dczid);
init_cpu_ftr_reg(SYS_CNTFRQ_EL0, info->reg_cntfrq);
init_cpu_ftr_reg(SYS_ID_AA64DFR0_EL1, info->reg_id_aa64dfr0);
init_cpu_ftr_reg(SYS_ID_AA64DFR1_EL1, info->reg_id_aa64dfr1);
init_cpu_ftr_reg(SYS_ID_AA64ISAR0_EL1, info->reg_id_aa64isar0);
init_cpu_ftr_reg(SYS_ID_AA64ISAR1_EL1, info->reg_id_aa64isar1);
init_cpu_ftr_reg(SYS_ID_AA64MMFR0_EL1, info->reg_id_aa64mmfr0);
init_cpu_ftr_reg(SYS_ID_AA64MMFR1_EL1, info->reg_id_aa64mmfr1);
init_cpu_ftr_reg(SYS_ID_AA64MMFR2_EL1, info->reg_id_aa64mmfr2);
init_cpu_ftr_reg(SYS_ID_AA64PFR0_EL1, info->reg_id_aa64pfr0);
init_cpu_ftr_reg(SYS_ID_AA64PFR1_EL1, info->reg_id_aa64pfr1);
if (id_aa64pfr0_32bit_el0(info->reg_id_aa64pfr0)) {
init_cpu_ftr_reg(SYS_ID_DFR0_EL1, info->reg_id_dfr0);
init_cpu_ftr_reg(SYS_ID_ISAR0_EL1, info->reg_id_isar0);
init_cpu_ftr_reg(SYS_ID_ISAR1_EL1, info->reg_id_isar1);
init_cpu_ftr_reg(SYS_ID_ISAR2_EL1, info->reg_id_isar2);
init_cpu_ftr_reg(SYS_ID_ISAR3_EL1, info->reg_id_isar3);
init_cpu_ftr_reg(SYS_ID_ISAR4_EL1, info->reg_id_isar4);
init_cpu_ftr_reg(SYS_ID_ISAR5_EL1, info->reg_id_isar5);
init_cpu_ftr_reg(SYS_ID_MMFR0_EL1, info->reg_id_mmfr0);
init_cpu_ftr_reg(SYS_ID_MMFR1_EL1, info->reg_id_mmfr1);
init_cpu_ftr_reg(SYS_ID_MMFR2_EL1, info->reg_id_mmfr2);
init_cpu_ftr_reg(SYS_ID_MMFR3_EL1, info->reg_id_mmfr3);
init_cpu_ftr_reg(SYS_ID_PFR0_EL1, info->reg_id_pfr0);
init_cpu_ftr_reg(SYS_ID_PFR1_EL1, info->reg_id_pfr1);
init_cpu_ftr_reg(SYS_MVFR0_EL1, info->reg_mvfr0);
init_cpu_ftr_reg(SYS_MVFR1_EL1, info->reg_mvfr1);
init_cpu_ftr_reg(SYS_MVFR2_EL1, info->reg_mvfr2);
}
}
static void update_cpu_ftr_reg(struct arm64_ftr_reg *reg, u64 new)
{
const struct arm64_ftr_bits *ftrp;
for (ftrp = reg->ftr_bits; ftrp->width; ftrp++) {
s64 ftr_cur = arm64_ftr_value(ftrp, reg->sys_val);
s64 ftr_new = arm64_ftr_value(ftrp, new);
if (ftr_cur == ftr_new)
continue;
ftr_new = arm64_ftr_safe_value(ftrp, ftr_new, ftr_cur);
reg->sys_val = arm64_ftr_set_value(ftrp, reg->sys_val, ftr_new);
}
}
static int check_update_ftr_reg(u32 sys_id, int cpu, u64 val, u64 boot)
{
struct arm64_ftr_reg *regp = get_arm64_ftr_reg(sys_id);
BUG_ON(!regp);
update_cpu_ftr_reg(regp, val);
if ((boot & regp->strict_mask) == (val & regp->strict_mask))
return 0;
pr_warn("SANITY CHECK: Unexpected variation in %s. Boot CPU: %#016llx, CPU%d: %#016llx\n",
regp->name, boot, cpu, val);
return 1;
}
void update_cpu_features(int cpu,
struct cpuinfo_arm64 *info,
struct cpuinfo_arm64 *boot)
{
int taint = 0;
taint |= check_update_ftr_reg(SYS_CTR_EL0, cpu,
info->reg_ctr, boot->reg_ctr);
taint |= check_update_ftr_reg(SYS_DCZID_EL0, cpu,
info->reg_dczid, boot->reg_dczid);
taint |= check_update_ftr_reg(SYS_CNTFRQ_EL0, cpu,
info->reg_cntfrq, boot->reg_cntfrq);
taint |= check_update_ftr_reg(SYS_ID_AA64DFR0_EL1, cpu,
info->reg_id_aa64dfr0, boot->reg_id_aa64dfr0);
taint |= check_update_ftr_reg(SYS_ID_AA64DFR1_EL1, cpu,
info->reg_id_aa64dfr1, boot->reg_id_aa64dfr1);
taint |= check_update_ftr_reg(SYS_ID_AA64ISAR0_EL1, cpu,
info->reg_id_aa64isar0, boot->reg_id_aa64isar0);
taint |= check_update_ftr_reg(SYS_ID_AA64ISAR1_EL1, cpu,
info->reg_id_aa64isar1, boot->reg_id_aa64isar1);
taint |= check_update_ftr_reg(SYS_ID_AA64MMFR0_EL1, cpu,
info->reg_id_aa64mmfr0, boot->reg_id_aa64mmfr0);
taint |= check_update_ftr_reg(SYS_ID_AA64MMFR1_EL1, cpu,
info->reg_id_aa64mmfr1, boot->reg_id_aa64mmfr1);
taint |= check_update_ftr_reg(SYS_ID_AA64MMFR2_EL1, cpu,
info->reg_id_aa64mmfr2, boot->reg_id_aa64mmfr2);
taint |= check_update_ftr_reg(SYS_ID_AA64PFR0_EL1, cpu,
info->reg_id_aa64pfr0, boot->reg_id_aa64pfr0);
taint |= check_update_ftr_reg(SYS_ID_AA64PFR1_EL1, cpu,
info->reg_id_aa64pfr1, boot->reg_id_aa64pfr1);
if (id_aa64pfr0_32bit_el0(read_system_reg(SYS_ID_AA64PFR0_EL1)) &&
id_aa64pfr0_32bit_el0(info->reg_id_aa64pfr0)) {
taint |= check_update_ftr_reg(SYS_ID_DFR0_EL1, cpu,
info->reg_id_dfr0, boot->reg_id_dfr0);
taint |= check_update_ftr_reg(SYS_ID_ISAR0_EL1, cpu,
info->reg_id_isar0, boot->reg_id_isar0);
taint |= check_update_ftr_reg(SYS_ID_ISAR1_EL1, cpu,
info->reg_id_isar1, boot->reg_id_isar1);
taint |= check_update_ftr_reg(SYS_ID_ISAR2_EL1, cpu,
info->reg_id_isar2, boot->reg_id_isar2);
taint |= check_update_ftr_reg(SYS_ID_ISAR3_EL1, cpu,
info->reg_id_isar3, boot->reg_id_isar3);
taint |= check_update_ftr_reg(SYS_ID_ISAR4_EL1, cpu,
info->reg_id_isar4, boot->reg_id_isar4);
taint |= check_update_ftr_reg(SYS_ID_ISAR5_EL1, cpu,
info->reg_id_isar5, boot->reg_id_isar5);
taint |= check_update_ftr_reg(SYS_ID_MMFR0_EL1, cpu,
info->reg_id_mmfr0, boot->reg_id_mmfr0);
taint |= check_update_ftr_reg(SYS_ID_MMFR1_EL1, cpu,
info->reg_id_mmfr1, boot->reg_id_mmfr1);
taint |= check_update_ftr_reg(SYS_ID_MMFR2_EL1, cpu,
info->reg_id_mmfr2, boot->reg_id_mmfr2);
taint |= check_update_ftr_reg(SYS_ID_MMFR3_EL1, cpu,
info->reg_id_mmfr3, boot->reg_id_mmfr3);
taint |= check_update_ftr_reg(SYS_ID_PFR0_EL1, cpu,
info->reg_id_pfr0, boot->reg_id_pfr0);
taint |= check_update_ftr_reg(SYS_ID_PFR1_EL1, cpu,
info->reg_id_pfr1, boot->reg_id_pfr1);
taint |= check_update_ftr_reg(SYS_MVFR0_EL1, cpu,
info->reg_mvfr0, boot->reg_mvfr0);
taint |= check_update_ftr_reg(SYS_MVFR1_EL1, cpu,
info->reg_mvfr1, boot->reg_mvfr1);
taint |= check_update_ftr_reg(SYS_MVFR2_EL1, cpu,
info->reg_mvfr2, boot->reg_mvfr2);
}
WARN_TAINT_ONCE(taint, TAINT_CPU_OUT_OF_SPEC,
"Unsupported CPU feature variation.\n");
}
u64 read_system_reg(u32 id)
{
struct arm64_ftr_reg *regp = get_arm64_ftr_reg(id);
BUG_ON(!regp);
return regp->sys_val;
}
static u64 __raw_read_system_reg(u32 sys_id)
{
switch (sys_id) {
case SYS_ID_PFR0_EL1: return read_cpuid(ID_PFR0_EL1);
case SYS_ID_PFR1_EL1: return read_cpuid(ID_PFR1_EL1);
case SYS_ID_DFR0_EL1: return read_cpuid(ID_DFR0_EL1);
case SYS_ID_MMFR0_EL1: return read_cpuid(ID_MMFR0_EL1);
case SYS_ID_MMFR1_EL1: return read_cpuid(ID_MMFR1_EL1);
case SYS_ID_MMFR2_EL1: return read_cpuid(ID_MMFR2_EL1);
case SYS_ID_MMFR3_EL1: return read_cpuid(ID_MMFR3_EL1);
case SYS_ID_ISAR0_EL1: return read_cpuid(ID_ISAR0_EL1);
case SYS_ID_ISAR1_EL1: return read_cpuid(ID_ISAR1_EL1);
case SYS_ID_ISAR2_EL1: return read_cpuid(ID_ISAR2_EL1);
case SYS_ID_ISAR3_EL1: return read_cpuid(ID_ISAR3_EL1);
case SYS_ID_ISAR4_EL1: return read_cpuid(ID_ISAR4_EL1);
case SYS_ID_ISAR5_EL1: return read_cpuid(ID_ISAR4_EL1);
case SYS_MVFR0_EL1: return read_cpuid(MVFR0_EL1);
case SYS_MVFR1_EL1: return read_cpuid(MVFR1_EL1);
case SYS_MVFR2_EL1: return read_cpuid(MVFR2_EL1);
case SYS_ID_AA64PFR0_EL1: return read_cpuid(ID_AA64PFR0_EL1);
case SYS_ID_AA64PFR1_EL1: return read_cpuid(ID_AA64PFR0_EL1);
case SYS_ID_AA64DFR0_EL1: return read_cpuid(ID_AA64DFR0_EL1);
case SYS_ID_AA64DFR1_EL1: return read_cpuid(ID_AA64DFR0_EL1);
case SYS_ID_AA64MMFR0_EL1: return read_cpuid(ID_AA64MMFR0_EL1);
case SYS_ID_AA64MMFR1_EL1: return read_cpuid(ID_AA64MMFR1_EL1);
case SYS_ID_AA64MMFR2_EL1: return read_cpuid(ID_AA64MMFR2_EL1);
case SYS_ID_AA64ISAR0_EL1: return read_cpuid(ID_AA64ISAR0_EL1);
case SYS_ID_AA64ISAR1_EL1: return read_cpuid(ID_AA64ISAR1_EL1);
case SYS_CNTFRQ_EL0: return read_cpuid(CNTFRQ_EL0);
case SYS_CTR_EL0: return read_cpuid(CTR_EL0);
case SYS_DCZID_EL0: return read_cpuid(DCZID_EL0);
default:
BUG();
return 0;
}
}
static bool
feature_matches(u64 reg, const struct arm64_cpu_capabilities *entry)
{
int val = cpuid_feature_extract_field(reg, entry->field_pos, entry->sign);
return val >= entry->min_field_value;
}
static bool
has_cpuid_feature(const struct arm64_cpu_capabilities *entry, int scope)
{
u64 val;
WARN_ON(scope == SCOPE_LOCAL_CPU && preemptible());
if (scope == SCOPE_SYSTEM)
val = read_system_reg(entry->sys_reg);
else
val = __raw_read_system_reg(entry->sys_reg);
return feature_matches(val, entry);
}
static bool has_useable_gicv3_cpuif(const struct arm64_cpu_capabilities *entry, int scope)
{
bool has_sre;
if (!has_cpuid_feature(entry, scope))
return false;
has_sre = gic_enable_sre();
if (!has_sre)
pr_warn_once("%s present but disabled by higher exception level\n",
entry->desc);
return has_sre;
}
static bool has_no_hw_prefetch(const struct arm64_cpu_capabilities *entry, int __unused)
{
u32 midr = read_cpuid_id();
u32 rv_min, rv_max;
rv_min = 0;
rv_max = (1 << MIDR_VARIANT_SHIFT) | MIDR_REVISION_MASK;
return MIDR_IS_CPU_MODEL_RANGE(midr, MIDR_THUNDERX, rv_min, rv_max);
}
static bool runs_at_el2(const struct arm64_cpu_capabilities *entry, int __unused)
{
return is_kernel_in_hyp_mode();
}
static bool hyp_offset_low(const struct arm64_cpu_capabilities *entry,
int __unused)
{
phys_addr_t idmap_addr = virt_to_phys(__hyp_idmap_text_start);
return idmap_addr > GENMASK(VA_BITS - 2, 0) && !is_kernel_in_hyp_mode();
}
static void __init cap_set_elf_hwcap(const struct arm64_cpu_capabilities *cap)
{
switch (cap->hwcap_type) {
case CAP_HWCAP:
elf_hwcap |= cap->hwcap;
break;
#ifdef CONFIG_COMPAT
case CAP_COMPAT_HWCAP:
compat_elf_hwcap |= (u32)cap->hwcap;
break;
case CAP_COMPAT_HWCAP2:
compat_elf_hwcap2 |= (u32)cap->hwcap;
break;
#endif
default:
WARN_ON(1);
break;
}
}
static bool cpus_have_elf_hwcap(const struct arm64_cpu_capabilities *cap)
{
bool rc;
switch (cap->hwcap_type) {
case CAP_HWCAP:
rc = (elf_hwcap & cap->hwcap) != 0;
break;
#ifdef CONFIG_COMPAT
case CAP_COMPAT_HWCAP:
rc = (compat_elf_hwcap & (u32)cap->hwcap) != 0;
break;
case CAP_COMPAT_HWCAP2:
rc = (compat_elf_hwcap2 & (u32)cap->hwcap) != 0;
break;
#endif
default:
WARN_ON(1);
rc = false;
}
return rc;
}
static void __init setup_elf_hwcaps(const struct arm64_cpu_capabilities *hwcaps)
{
for (; hwcaps->matches; hwcaps++)
if (hwcaps->matches(hwcaps, hwcaps->def_scope))
cap_set_elf_hwcap(hwcaps);
}
void update_cpu_capabilities(const struct arm64_cpu_capabilities *caps,
const char *info)
{
for (; caps->matches; caps++) {
if (!caps->matches(caps, caps->def_scope))
continue;
if (!cpus_have_cap(caps->capability) && caps->desc)
pr_info("%s %s\n", info, caps->desc);
cpus_set_cap(caps->capability);
}
}
void __init enable_cpu_capabilities(const struct arm64_cpu_capabilities *caps)
{
for (; caps->matches; caps++)
if (caps->enable && cpus_have_cap(caps->capability))
stop_machine(caps->enable, NULL, cpu_online_mask);
}
static inline void set_sys_caps_initialised(void)
{
sys_caps_initialised = true;
}
static void check_early_cpu_features(void)
{
verify_cpu_run_el();
verify_cpu_asid_bits();
}
static void
verify_local_elf_hwcaps(const struct arm64_cpu_capabilities *caps)
{
for (; caps->matches; caps++)
if (cpus_have_elf_hwcap(caps) && !caps->matches(caps, SCOPE_LOCAL_CPU)) {
pr_crit("CPU%d: missing HWCAP: %s\n",
smp_processor_id(), caps->desc);
cpu_die_early();
}
}
static void
verify_local_cpu_features(const struct arm64_cpu_capabilities *caps)
{
for (; caps->matches; caps++) {
if (!cpus_have_cap(caps->capability))
continue;
if (!caps->matches(caps, SCOPE_LOCAL_CPU)) {
pr_crit("CPU%d: missing feature: %s\n",
smp_processor_id(), caps->desc);
cpu_die_early();
}
if (caps->enable)
caps->enable(NULL);
}
}
static void verify_local_cpu_capabilities(void)
{
verify_local_cpu_errata_workarounds();
verify_local_cpu_features(arm64_features);
verify_local_elf_hwcaps(arm64_elf_hwcaps);
if (system_supports_32bit_el0())
verify_local_elf_hwcaps(compat_elf_hwcaps);
}
void check_local_cpu_capabilities(void)
{
check_early_cpu_features();
if (!sys_caps_initialised)
update_cpu_errata_workarounds();
else
verify_local_cpu_capabilities();
}
static void __init setup_feature_capabilities(void)
{
update_cpu_capabilities(arm64_features, "detected feature:");
enable_cpu_capabilities(arm64_features);
}
bool this_cpu_has_cap(unsigned int cap)
{
const struct arm64_cpu_capabilities *caps;
if (WARN_ON(preemptible()))
return false;
for (caps = arm64_features; caps->desc; caps++)
if (caps->capability == cap && caps->matches)
return caps->matches(caps, SCOPE_LOCAL_CPU);
return false;
}
void __init setup_cpu_features(void)
{
u32 cwg;
int cls;
setup_feature_capabilities();
enable_errata_workarounds();
setup_elf_hwcaps(arm64_elf_hwcaps);
if (system_supports_32bit_el0())
setup_elf_hwcaps(compat_elf_hwcaps);
set_sys_caps_initialised();
cwg = cache_type_cwg();
cls = cache_line_size();
if (!cwg)
pr_warn("No Cache Writeback Granule information, assuming cache line size %d\n",
cls);
if (L1_CACHE_BYTES < cls)
pr_warn("L1_CACHE_BYTES smaller than the Cache Writeback Granule (%d < %d)\n",
L1_CACHE_BYTES, cls);
}
static bool __maybe_unused
cpufeature_pan_not_uao(const struct arm64_cpu_capabilities *entry, int __unused)
{
return (cpus_have_cap(ARM64_HAS_PAN) && !cpus_have_cap(ARM64_HAS_UAO));
}
