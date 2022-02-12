static void cpufeatures_flush_tlb(void)
{
switch (PVR_VER(mfspr(SPRN_PVR))) {
case PVR_POWER8:
case PVR_POWER8E:
case PVR_POWER8NVL:
__flush_tlb_power8(TLB_INVAL_SCOPE_GLOBAL);
break;
case PVR_POWER9:
__flush_tlb_power9(TLB_INVAL_SCOPE_GLOBAL);
break;
default:
pr_err("unknown CPU version for boot TLB flush\n");
break;
}
}
static void __restore_cpu_cpufeatures(void)
{
mtspr(SPRN_LPCR, system_registers.lpcr | mfspr(SPRN_LPCR));
if (hv_mode) {
mtspr(SPRN_LPID, 0);
mtspr(SPRN_HFSCR, system_registers.hfscr);
}
mtspr(SPRN_FSCR, system_registers.fscr);
if (init_pmu_registers)
init_pmu_registers();
cpufeatures_flush_tlb();
}
static void __init cpufeatures_setup_cpu(void)
{
set_cur_cpu_spec(&base_cpu_spec);
cur_cpu_spec->pvr_mask = -1;
cur_cpu_spec->pvr_value = mfspr(SPRN_PVR);
hv_mode = !!(mfmsr() & MSR_HV);
if (hv_mode) {
cur_cpu_spec->cpu_features |= CPU_FTR_HVMODE;
mtspr(SPRN_HFSCR, 0);
}
mtspr(SPRN_FSCR, 0);
}
static int __init feat_try_enable_unknown(struct dt_cpu_feature *f)
{
if (f->hv_support == HV_SUPPORT_NONE) {
} else if (f->hv_support & HV_SUPPORT_HFSCR) {
u64 hfscr = mfspr(SPRN_HFSCR);
hfscr |= 1UL << f->hfscr_bit_nr;
mtspr(SPRN_HFSCR, hfscr);
} else {
return 0;
}
if (f->os_support == OS_SUPPORT_NONE) {
} else if (f->os_support & OS_SUPPORT_FSCR) {
u64 fscr = mfspr(SPRN_FSCR);
fscr |= 1UL << f->fscr_bit_nr;
mtspr(SPRN_FSCR, fscr);
} else {
return 0;
}
if ((f->usable_privilege & USABLE_PR) && (f->hwcap_bit_nr != -1)) {
uint32_t word = f->hwcap_bit_nr / 32;
uint32_t bit = f->hwcap_bit_nr % 32;
if (word == 0)
cur_cpu_spec->cpu_user_features |= 1U << bit;
else if (word == 1)
cur_cpu_spec->cpu_user_features2 |= 1U << bit;
else
pr_err("%s could not advertise to user (no hwcap bits)\n", f->name);
}
return 1;
}
static int __init feat_enable(struct dt_cpu_feature *f)
{
if (f->hv_support != HV_SUPPORT_NONE) {
if (f->hfscr_bit_nr != -1) {
u64 hfscr = mfspr(SPRN_HFSCR);
hfscr |= 1UL << f->hfscr_bit_nr;
mtspr(SPRN_HFSCR, hfscr);
}
}
if (f->os_support != OS_SUPPORT_NONE) {
if (f->fscr_bit_nr != -1) {
u64 fscr = mfspr(SPRN_FSCR);
fscr |= 1UL << f->fscr_bit_nr;
mtspr(SPRN_FSCR, fscr);
}
}
if ((f->usable_privilege & USABLE_PR) && (f->hwcap_bit_nr != -1)) {
uint32_t word = f->hwcap_bit_nr / 32;
uint32_t bit = f->hwcap_bit_nr % 32;
if (word == 0)
cur_cpu_spec->cpu_user_features |= 1U << bit;
else if (word == 1)
cur_cpu_spec->cpu_user_features2 |= 1U << bit;
else
pr_err("CPU feature: %s could not advertise to user (no hwcap bits)\n", f->name);
}
return 1;
}
static int __init feat_disable(struct dt_cpu_feature *f)
{
return 0;
}
static int __init feat_enable_hv(struct dt_cpu_feature *f)
{
u64 lpcr;
if (!hv_mode) {
pr_err("CPU feature hypervisor present in device tree but HV mode not enabled in the CPU. Ignoring.\n");
return 0;
}
mtspr(SPRN_LPID, 0);
lpcr = mfspr(SPRN_LPCR);
lpcr &= ~LPCR_LPES0;
mtspr(SPRN_LPCR, lpcr);
cur_cpu_spec->cpu_features |= CPU_FTR_HVMODE;
return 1;
}
static int __init feat_enable_le(struct dt_cpu_feature *f)
{
cur_cpu_spec->cpu_user_features |= PPC_FEATURE_TRUE_LE;
return 1;
}
static int __init feat_enable_smt(struct dt_cpu_feature *f)
{
cur_cpu_spec->cpu_features |= CPU_FTR_SMT;
cur_cpu_spec->cpu_user_features |= PPC_FEATURE_SMT;
return 1;
}
static int __init feat_enable_idle_nap(struct dt_cpu_feature *f)
{
u64 lpcr;
lpcr = mfspr(SPRN_LPCR);
lpcr |= LPCR_PECE0;
lpcr |= LPCR_PECE1;
lpcr |= LPCR_PECE2;
mtspr(SPRN_LPCR, lpcr);
return 1;
}
static int __init feat_enable_align_dsisr(struct dt_cpu_feature *f)
{
cur_cpu_spec->cpu_features &= ~CPU_FTR_NODSISRALIGN;
return 1;
}
static int __init feat_enable_idle_stop(struct dt_cpu_feature *f)
{
u64 lpcr;
lpcr = mfspr(SPRN_LPCR);
lpcr |= LPCR_PECE0;
lpcr |= LPCR_PECE1;
lpcr |= LPCR_PECE2;
mtspr(SPRN_LPCR, lpcr);
return 1;
}
static int __init feat_enable_mmu_hash(struct dt_cpu_feature *f)
{
u64 lpcr;
lpcr = mfspr(SPRN_LPCR);
lpcr &= ~LPCR_ISL;
lpcr |= LPCR_VPM0;
lpcr &= ~LPCR_VPM1;
lpcr |= 0x10UL << LPCR_VRMASD_SH;
mtspr(SPRN_LPCR, lpcr);
cur_cpu_spec->mmu_features |= MMU_FTRS_HASH_BASE;
cur_cpu_spec->cpu_user_features |= PPC_FEATURE_HAS_MMU;
return 1;
}
static int __init feat_enable_mmu_hash_v3(struct dt_cpu_feature *f)
{
u64 lpcr;
lpcr = mfspr(SPRN_LPCR);
lpcr &= ~LPCR_ISL;
mtspr(SPRN_LPCR, lpcr);
cur_cpu_spec->mmu_features |= MMU_FTRS_HASH_BASE;
cur_cpu_spec->cpu_user_features |= PPC_FEATURE_HAS_MMU;
return 1;
}
static int __init feat_enable_mmu_radix(struct dt_cpu_feature *f)
{
#ifdef CONFIG_PPC_RADIX_MMU
cur_cpu_spec->mmu_features |= MMU_FTR_TYPE_RADIX;
cur_cpu_spec->mmu_features |= MMU_FTRS_HASH_BASE;
cur_cpu_spec->cpu_user_features |= PPC_FEATURE_HAS_MMU;
return 1;
#endif
return 0;
}
static int __init feat_enable_dscr(struct dt_cpu_feature *f)
{
u64 lpcr;
feat_enable(f);
lpcr = mfspr(SPRN_LPCR);
lpcr &= ~LPCR_DPFD;
lpcr |= (4UL << LPCR_DPFD_SH);
mtspr(SPRN_LPCR, lpcr);
return 1;
}
static void hfscr_pmu_enable(void)
{
u64 hfscr = mfspr(SPRN_HFSCR);
hfscr |= PPC_BIT(60);
mtspr(SPRN_HFSCR, hfscr);
}
static void init_pmu_power8(void)
{
if (hv_mode) {
mtspr(SPRN_MMCRC, 0);
mtspr(SPRN_MMCRH, 0);
}
mtspr(SPRN_MMCRA, 0);
mtspr(SPRN_MMCR0, 0);
mtspr(SPRN_MMCR1, 0);
mtspr(SPRN_MMCR2, 0);
mtspr(SPRN_MMCRS, 0);
}
static int __init feat_enable_mce_power8(struct dt_cpu_feature *f)
{
cur_cpu_spec->platform = "power8";
cur_cpu_spec->flush_tlb = __flush_tlb_power8;
cur_cpu_spec->machine_check_early = __machine_check_early_realmode_p8;
return 1;
}
static int __init feat_enable_pmu_power8(struct dt_cpu_feature *f)
{
hfscr_pmu_enable();
init_pmu_power8();
init_pmu_registers = init_pmu_power8;
cur_cpu_spec->cpu_features |= CPU_FTR_MMCRA;
cur_cpu_spec->cpu_user_features |= PPC_FEATURE_PSERIES_PERFMON_COMPAT;
if (pvr_version_is(PVR_POWER8E))
cur_cpu_spec->cpu_features |= CPU_FTR_PMAO_BUG;
cur_cpu_spec->num_pmcs = 6;
cur_cpu_spec->pmc_type = PPC_PMC_IBM;
cur_cpu_spec->oprofile_cpu_type = "ppc64/power8";
return 1;
}
static void init_pmu_power9(void)
{
if (hv_mode)
mtspr(SPRN_MMCRC, 0);
mtspr(SPRN_MMCRA, 0);
mtspr(SPRN_MMCR0, 0);
mtspr(SPRN_MMCR1, 0);
mtspr(SPRN_MMCR2, 0);
}
static int __init feat_enable_mce_power9(struct dt_cpu_feature *f)
{
cur_cpu_spec->platform = "power9";
cur_cpu_spec->flush_tlb = __flush_tlb_power9;
cur_cpu_spec->machine_check_early = __machine_check_early_realmode_p9;
return 1;
}
static int __init feat_enable_pmu_power9(struct dt_cpu_feature *f)
{
hfscr_pmu_enable();
init_pmu_power9();
init_pmu_registers = init_pmu_power9;
cur_cpu_spec->cpu_features |= CPU_FTR_MMCRA;
cur_cpu_spec->cpu_user_features |= PPC_FEATURE_PSERIES_PERFMON_COMPAT;
cur_cpu_spec->num_pmcs = 6;
cur_cpu_spec->pmc_type = PPC_PMC_IBM;
cur_cpu_spec->oprofile_cpu_type = "ppc64/power9";
return 1;
}
static int __init feat_enable_tm(struct dt_cpu_feature *f)
{
#ifdef CONFIG_PPC_TRANSACTIONAL_MEM
feat_enable(f);
cur_cpu_spec->cpu_user_features2 |= PPC_FEATURE2_HTM_NOSC;
return 1;
#endif
return 0;
}
static int __init feat_enable_fp(struct dt_cpu_feature *f)
{
feat_enable(f);
cur_cpu_spec->cpu_features &= ~CPU_FTR_FPU_UNAVAILABLE;
return 1;
}
static int __init feat_enable_vector(struct dt_cpu_feature *f)
{
#ifdef CONFIG_ALTIVEC
feat_enable(f);
cur_cpu_spec->cpu_features |= CPU_FTR_ALTIVEC;
cur_cpu_spec->cpu_features |= CPU_FTR_VMX_COPY;
cur_cpu_spec->cpu_user_features |= PPC_FEATURE_HAS_ALTIVEC;
return 1;
#endif
return 0;
}
static int __init feat_enable_vsx(struct dt_cpu_feature *f)
{
#ifdef CONFIG_VSX
feat_enable(f);
cur_cpu_spec->cpu_features |= CPU_FTR_VSX;
cur_cpu_spec->cpu_user_features |= PPC_FEATURE_HAS_VSX;
return 1;
#endif
return 0;
}
static int __init feat_enable_purr(struct dt_cpu_feature *f)
{
cur_cpu_spec->cpu_features |= CPU_FTR_PURR | CPU_FTR_SPURR;
return 1;
}
static int __init feat_enable_ebb(struct dt_cpu_feature *f)
{
f->hwcap_bit_nr = -1;
feat_enable(f);
return 1;
}
static int __init feat_enable_dbell(struct dt_cpu_feature *f)
{
u64 lpcr;
feat_enable(f);
cur_cpu_spec->cpu_features |= CPU_FTR_DBELL;
lpcr = mfspr(SPRN_LPCR);
lpcr |= LPCR_PECEDH;
mtspr(SPRN_LPCR, lpcr);
return 1;
}
static int __init feat_enable_hvi(struct dt_cpu_feature *f)
{
u64 lpcr;
lpcr = mfspr(SPRN_LPCR);
lpcr |= LPCR_HVICE;
lpcr |= LPCR_HEIC;
lpcr |= LPCR_PECE_HVEE;
mtspr(SPRN_LPCR, lpcr);
return 1;
}
static int __init feat_enable_large_ci(struct dt_cpu_feature *f)
{
cur_cpu_spec->mmu_features |= MMU_FTR_CI_LARGE_PAGE;
return 1;
}
static int __init dt_cpu_ftrs_parse(char *str)
{
if (!str)
return 0;
if (!strcmp(str, "off"))
using_dt_cpu_ftrs = false;
else if (!strcmp(str, "known"))
enable_unknown = false;
else
return 1;
return 0;
}
static void __init cpufeatures_setup_start(u32 isa)
{
pr_info("setup for ISA %d\n", isa);
if (isa >= 3000) {
cur_cpu_spec->cpu_features |= CPU_FTR_ARCH_300;
cur_cpu_spec->cpu_user_features2 |= PPC_FEATURE2_ARCH_3_00;
}
}
static bool __init cpufeatures_process_feature(struct dt_cpu_feature *f)
{
const struct dt_cpu_feature_match *m;
bool known = false;
int i;
for (i = 0; i < ARRAY_SIZE(dt_cpu_feature_match_table); i++) {
m = &dt_cpu_feature_match_table[i];
if (!strcmp(f->name, m->name)) {
known = true;
if (m->enable(f))
break;
pr_info("not enabling: %s (disabled or unsupported by kernel)\n",
f->name);
return false;
}
}
if (!known && enable_unknown) {
if (!feat_try_enable_unknown(f)) {
pr_info("not enabling: %s (unknown and unsupported by kernel)\n",
f->name);
return false;
}
}
if (m->cpu_ftr_bit_mask)
cur_cpu_spec->cpu_features |= m->cpu_ftr_bit_mask;
if (known)
pr_debug("enabling: %s\n", f->name);
else
pr_debug("enabling: %s (unknown)\n", f->name);
return true;
}
static __init void cpufeatures_cpu_quirks(void)
{
int version = mfspr(SPRN_PVR);
if ((version & 0xffffff00) == 0x004e0100)
cur_cpu_spec->cpu_features |= CPU_FTR_POWER9_DD1;
}
static void __init cpufeatures_setup_finished(void)
{
cpufeatures_cpu_quirks();
if (hv_mode && !(cur_cpu_spec->cpu_features & CPU_FTR_HVMODE)) {
pr_err("hypervisor not present in device tree but HV mode is enabled in the CPU. Enabling.\n");
cur_cpu_spec->cpu_features |= CPU_FTR_HVMODE;
}
system_registers.lpcr = mfspr(SPRN_LPCR);
system_registers.hfscr = mfspr(SPRN_HFSCR);
system_registers.fscr = mfspr(SPRN_FSCR);
cpufeatures_flush_tlb();
pr_info("final cpu/mmu features = 0x%016lx 0x%08x\n",
cur_cpu_spec->cpu_features, cur_cpu_spec->mmu_features);
}
static int __init disabled_on_cmdline(void)
{
unsigned long root, chosen;
const char *p;
root = of_get_flat_dt_root();
chosen = of_get_flat_dt_subnode_by_name(root, "chosen");
if (chosen == -FDT_ERR_NOTFOUND)
return false;
p = of_get_flat_dt_prop(chosen, "bootargs", NULL);
if (!p)
return false;
if (strstr(p, "dt_cpu_ftrs=off"))
return true;
return false;
}
static int __init fdt_find_cpu_features(unsigned long node, const char *uname,
int depth, void *data)
{
if (of_flat_dt_is_compatible(node, "ibm,powerpc-cpu-features")
&& of_get_flat_dt_prop(node, "isa", NULL))
return 1;
return 0;
}
bool __init dt_cpu_ftrs_in_use(void)
{
return using_dt_cpu_ftrs;
}
bool __init dt_cpu_ftrs_init(void *fdt)
{
using_dt_cpu_ftrs = false;
if (!early_init_dt_verify(fdt))
return false;
if (!of_scan_flat_dt(fdt_find_cpu_features, NULL))
return false;
if (disabled_on_cmdline())
return false;
cpufeatures_setup_cpu();
using_dt_cpu_ftrs = true;
return true;
}
static int __init process_cpufeatures_node(unsigned long node,
const char *uname, int i)
{
const __be32 *prop;
struct dt_cpu_feature *f;
int len;
f = &dt_cpu_features[i];
memset(f, 0, sizeof(struct dt_cpu_feature));
f->node = node;
f->name = uname;
prop = of_get_flat_dt_prop(node, "isa", &len);
if (!prop) {
pr_warn("%s: missing isa property\n", uname);
return 0;
}
f->isa = be32_to_cpup(prop);
prop = of_get_flat_dt_prop(node, "usable-privilege", &len);
if (!prop) {
pr_warn("%s: missing usable-privilege property", uname);
return 0;
}
f->usable_privilege = be32_to_cpup(prop);
prop = of_get_flat_dt_prop(node, "hv-support", &len);
if (prop)
f->hv_support = be32_to_cpup(prop);
else
f->hv_support = HV_SUPPORT_NONE;
prop = of_get_flat_dt_prop(node, "os-support", &len);
if (prop)
f->os_support = be32_to_cpup(prop);
else
f->os_support = OS_SUPPORT_NONE;
prop = of_get_flat_dt_prop(node, "hfscr-bit-nr", &len);
if (prop)
f->hfscr_bit_nr = be32_to_cpup(prop);
else
f->hfscr_bit_nr = -1;
prop = of_get_flat_dt_prop(node, "fscr-bit-nr", &len);
if (prop)
f->fscr_bit_nr = be32_to_cpup(prop);
else
f->fscr_bit_nr = -1;
prop = of_get_flat_dt_prop(node, "hwcap-bit-nr", &len);
if (prop)
f->hwcap_bit_nr = be32_to_cpup(prop);
else
f->hwcap_bit_nr = -1;
if (f->usable_privilege & USABLE_HV) {
if (!(mfmsr() & MSR_HV)) {
pr_warn("%s: HV feature passed to guest\n", uname);
return 0;
}
if (f->hv_support == HV_SUPPORT_NONE && f->hfscr_bit_nr != -1) {
pr_warn("%s: unwanted hfscr_bit_nr\n", uname);
return 0;
}
if (f->hv_support == HV_SUPPORT_HFSCR) {
if (f->hfscr_bit_nr == -1) {
pr_warn("%s: missing hfscr_bit_nr\n", uname);
return 0;
}
}
} else {
if (f->hv_support != HV_SUPPORT_NONE || f->hfscr_bit_nr != -1) {
pr_warn("%s: unwanted hv_support/hfscr_bit_nr\n", uname);
return 0;
}
}
if (f->usable_privilege & USABLE_OS) {
if (f->os_support == OS_SUPPORT_NONE && f->fscr_bit_nr != -1) {
pr_warn("%s: unwanted fscr_bit_nr\n", uname);
return 0;
}
if (f->os_support == OS_SUPPORT_FSCR) {
if (f->fscr_bit_nr == -1) {
pr_warn("%s: missing fscr_bit_nr\n", uname);
return 0;
}
}
} else {
if (f->os_support != OS_SUPPORT_NONE || f->fscr_bit_nr != -1) {
pr_warn("%s: unwanted os_support/fscr_bit_nr\n", uname);
return 0;
}
}
if (!(f->usable_privilege & USABLE_PR)) {
if (f->hwcap_bit_nr != -1) {
pr_warn("%s: unwanted hwcap_bit_nr\n", uname);
return 0;
}
}
if (!of_get_flat_dt_prop(node, "dependencies", &len)) {
if (cpufeatures_process_feature(f))
f->enabled = 1;
else
f->disabled = 1;
}
return 0;
}
static void __init cpufeatures_deps_enable(struct dt_cpu_feature *f)
{
const __be32 *prop;
int len;
int nr_deps;
int i;
if (f->enabled || f->disabled)
return;
prop = of_get_flat_dt_prop(f->node, "dependencies", &len);
if (!prop) {
pr_warn("%s: missing dependencies property", f->name);
return;
}
nr_deps = len / sizeof(int);
for (i = 0; i < nr_deps; i++) {
unsigned long phandle = be32_to_cpu(prop[i]);
int j;
for (j = 0; j < nr_dt_cpu_features; j++) {
struct dt_cpu_feature *d = &dt_cpu_features[j];
if (of_get_flat_dt_phandle(d->node) == phandle) {
cpufeatures_deps_enable(d);
if (d->disabled) {
f->disabled = 1;
return;
}
}
}
}
if (cpufeatures_process_feature(f))
f->enabled = 1;
else
f->disabled = 1;
}
static int __init scan_cpufeatures_subnodes(unsigned long node,
const char *uname,
void *data)
{
int *count = data;
process_cpufeatures_node(node, uname, *count);
(*count)++;
return 0;
}
static int __init count_cpufeatures_subnodes(unsigned long node,
const char *uname,
void *data)
{
int *count = data;
(*count)++;
return 0;
}
static int __init dt_cpu_ftrs_scan_callback(unsigned long node, const char
*uname, int depth, void *data)
{
const __be32 *prop;
int count, i;
u32 isa;
if (!of_flat_dt_is_compatible(node, "ibm,powerpc-cpu-features"))
return 0;
prop = of_get_flat_dt_prop(node, "isa", NULL);
if (!prop)
return 0;
isa = be32_to_cpup(prop);
of_scan_flat_dt_subnodes(node, count_cpufeatures_subnodes,
&nr_dt_cpu_features);
dt_cpu_features = __va(
memblock_alloc(sizeof(struct dt_cpu_feature)*
nr_dt_cpu_features, PAGE_SIZE));
cpufeatures_setup_start(isa);
count = 0;
of_scan_flat_dt_subnodes(node, scan_cpufeatures_subnodes, &count);
for (i = 0; i < nr_dt_cpu_features; i++) {
struct dt_cpu_feature *f = &dt_cpu_features[i];
cpufeatures_deps_enable(f);
}
prop = of_get_flat_dt_prop(node, "display-name", NULL);
if (prop && strlen((char *)prop) != 0) {
strlcpy(dt_cpu_name, (char *)prop, sizeof(dt_cpu_name));
cur_cpu_spec->cpu_name = dt_cpu_name;
}
cpufeatures_setup_finished();
memblock_free(__pa(dt_cpu_features),
sizeof(struct dt_cpu_feature)*nr_dt_cpu_features);
return 0;
}
void __init dt_cpu_ftrs_scan(void)
{
if (!using_dt_cpu_ftrs)
return;
of_scan_flat_dt(dt_cpu_ftrs_scan_callback, NULL);
}
