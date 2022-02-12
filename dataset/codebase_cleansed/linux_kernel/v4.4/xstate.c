void fpu__xstate_clear_all_cpu_caps(void)
{
setup_clear_cpu_cap(X86_FEATURE_XSAVE);
setup_clear_cpu_cap(X86_FEATURE_XSAVEOPT);
setup_clear_cpu_cap(X86_FEATURE_XSAVEC);
setup_clear_cpu_cap(X86_FEATURE_XSAVES);
setup_clear_cpu_cap(X86_FEATURE_AVX);
setup_clear_cpu_cap(X86_FEATURE_AVX2);
setup_clear_cpu_cap(X86_FEATURE_AVX512F);
setup_clear_cpu_cap(X86_FEATURE_AVX512PF);
setup_clear_cpu_cap(X86_FEATURE_AVX512ER);
setup_clear_cpu_cap(X86_FEATURE_AVX512CD);
setup_clear_cpu_cap(X86_FEATURE_MPX);
}
int cpu_has_xfeatures(u64 xfeatures_needed, const char **feature_name)
{
u64 xfeatures_missing = xfeatures_needed & ~xfeatures_mask;
if (unlikely(feature_name)) {
long xfeature_idx, max_idx;
u64 xfeatures_print;
if (xfeatures_missing)
xfeatures_print = xfeatures_missing;
else
xfeatures_print = xfeatures_needed;
xfeature_idx = fls64(xfeatures_print)-1;
max_idx = ARRAY_SIZE(xfeature_names)-1;
xfeature_idx = min(xfeature_idx, max_idx);
*feature_name = xfeature_names[xfeature_idx];
}
if (xfeatures_missing)
return 0;
return 1;
}
void fpstate_sanitize_xstate(struct fpu *fpu)
{
struct fxregs_state *fx = &fpu->state.fxsave;
int feature_bit;
u64 xfeatures;
if (!use_xsaveopt())
return;
xfeatures = fpu->state.xsave.header.xfeatures;
if ((xfeatures & xfeatures_mask) == xfeatures_mask)
return;
if (!(xfeatures & XFEATURE_MASK_FP)) {
fx->cwd = 0x37f;
fx->swd = 0;
fx->twd = 0;
fx->fop = 0;
fx->rip = 0;
fx->rdp = 0;
memset(&fx->st_space[0], 0, 128);
}
if (!(xfeatures & XFEATURE_MASK_SSE))
memset(&fx->xmm_space[0], 0, 256);
feature_bit = 0x2;
xfeatures = (xfeatures_mask & ~xfeatures) >> 2;
while (xfeatures) {
if (xfeatures & 0x1) {
int offset = xstate_offsets[feature_bit];
int size = xstate_sizes[feature_bit];
memcpy((void *)fx + offset,
(void *)&init_fpstate.xsave + offset,
size);
}
xfeatures >>= 1;
feature_bit++;
}
}
void fpu__init_cpu_xstate(void)
{
if (!cpu_has_xsave || !xfeatures_mask)
return;
cr4_set_bits(X86_CR4_OSXSAVE);
xsetbv(XCR_XFEATURE_ENABLED_MASK, xfeatures_mask);
}
static int xfeature_enabled(enum xfeature xfeature)
{
return !!(xfeatures_mask & (1UL << xfeature));
}
static void __init setup_xstate_features(void)
{
u32 eax, ebx, ecx, edx, i;
unsigned int last_good_offset = offsetof(struct xregs_state,
extended_state_area);
for (i = FIRST_EXTENDED_XFEATURE; i < XFEATURE_MAX; i++) {
if (!xfeature_enabled(i))
continue;
cpuid_count(XSTATE_CPUID, i, &eax, &ebx, &ecx, &edx);
xstate_offsets[i] = ebx;
xstate_sizes[i] = eax;
WARN_ONCE(last_good_offset > xstate_offsets[i],
"x86/fpu: misordered xstate at %d\n", last_good_offset);
last_good_offset = xstate_offsets[i];
printk(KERN_INFO "x86/fpu: xstate_offset[%d]: %4d, xstate_sizes[%d]: %4d\n", i, ebx, i, eax);
}
}
static void __init print_xstate_feature(u64 xstate_mask)
{
const char *feature_name;
if (cpu_has_xfeatures(xstate_mask, &feature_name))
pr_info("x86/fpu: Supporting XSAVE feature 0x%02Lx: '%s'\n", xstate_mask, feature_name);
}
static void __init print_xstate_features(void)
{
print_xstate_feature(XFEATURE_MASK_FP);
print_xstate_feature(XFEATURE_MASK_SSE);
print_xstate_feature(XFEATURE_MASK_YMM);
print_xstate_feature(XFEATURE_MASK_BNDREGS);
print_xstate_feature(XFEATURE_MASK_BNDCSR);
print_xstate_feature(XFEATURE_MASK_OPMASK);
print_xstate_feature(XFEATURE_MASK_ZMM_Hi256);
print_xstate_feature(XFEATURE_MASK_Hi16_ZMM);
}
static void __init setup_xstate_comp(void)
{
unsigned int xstate_comp_sizes[sizeof(xfeatures_mask)*8];
int i;
xstate_comp_offsets[0] = 0;
xstate_comp_offsets[1] = offsetof(struct fxregs_state, xmm_space);
if (!cpu_has_xsaves) {
for (i = FIRST_EXTENDED_XFEATURE; i < XFEATURE_MAX; i++) {
if (xfeature_enabled(i)) {
xstate_comp_offsets[i] = xstate_offsets[i];
xstate_comp_sizes[i] = xstate_sizes[i];
}
}
return;
}
xstate_comp_offsets[FIRST_EXTENDED_XFEATURE] =
FXSAVE_SIZE + XSAVE_HDR_SIZE;
for (i = FIRST_EXTENDED_XFEATURE; i < XFEATURE_MAX; i++) {
if (xfeature_enabled(i))
xstate_comp_sizes[i] = xstate_sizes[i];
else
xstate_comp_sizes[i] = 0;
if (i > FIRST_EXTENDED_XFEATURE)
xstate_comp_offsets[i] = xstate_comp_offsets[i-1]
+ xstate_comp_sizes[i-1];
}
}
static void __init setup_init_fpu_buf(void)
{
static int on_boot_cpu = 1;
WARN_ON_FPU(!on_boot_cpu);
on_boot_cpu = 0;
if (!cpu_has_xsave)
return;
setup_xstate_features();
print_xstate_features();
if (cpu_has_xsaves) {
init_fpstate.xsave.header.xcomp_bv = (u64)1 << 63 | xfeatures_mask;
init_fpstate.xsave.header.xfeatures = xfeatures_mask;
}
copy_kernel_to_xregs_booting(&init_fpstate.xsave);
copy_xregs_to_kernel_booting(&init_fpstate.xsave);
}
static int xfeature_is_supervisor(int xfeature_nr)
{
return 0;
}
static int xfeature_is_aligned(int xfeature_nr)
{
u32 eax, ebx, ecx, edx;
CHECK_XFEATURE(xfeature_nr);
cpuid_count(XSTATE_CPUID, xfeature_nr, &eax, &ebx, &ecx, &edx);
return !!(ecx & 2);
}
static int xfeature_uncompacted_offset(int xfeature_nr)
{
u32 eax, ebx, ecx, edx;
CHECK_XFEATURE(xfeature_nr);
cpuid_count(XSTATE_CPUID, xfeature_nr, &eax, &ebx, &ecx, &edx);
return ebx;
}
static int xfeature_size(int xfeature_nr)
{
u32 eax, ebx, ecx, edx;
CHECK_XFEATURE(xfeature_nr);
cpuid_count(XSTATE_CPUID, xfeature_nr, &eax, &ebx, &ecx, &edx);
return eax;
}
static int using_compacted_format(void)
{
return cpu_has_xsaves;
}
static void __xstate_dump_leaves(void)
{
int i;
u32 eax, ebx, ecx, edx;
static int should_dump = 1;
if (!should_dump)
return;
should_dump = 0;
for (i = 0; i < XFEATURE_MAX + 10; i++) {
cpuid_count(XSTATE_CPUID, i, &eax, &ebx, &ecx, &edx);
pr_warn("CPUID[%02x, %02x]: eax=%08x ebx=%08x ecx=%08x edx=%08x\n",
XSTATE_CPUID, i, eax, ebx, ecx, edx);
}
}
static void check_xstate_against_struct(int nr)
{
int sz = xfeature_size(nr);
XCHECK_SZ(sz, nr, XFEATURE_YMM, struct ymmh_struct);
XCHECK_SZ(sz, nr, XFEATURE_BNDREGS, struct mpx_bndreg_state);
XCHECK_SZ(sz, nr, XFEATURE_BNDCSR, struct mpx_bndcsr_state);
XCHECK_SZ(sz, nr, XFEATURE_OPMASK, struct avx_512_opmask_state);
XCHECK_SZ(sz, nr, XFEATURE_ZMM_Hi256, struct avx_512_zmm_uppers_state);
XCHECK_SZ(sz, nr, XFEATURE_Hi16_ZMM, struct avx_512_hi16_state);
if ((nr < XFEATURE_YMM) ||
(nr >= XFEATURE_MAX)) {
WARN_ONCE(1, "no structure for xstate: %d\n", nr);
XSTATE_WARN_ON(1);
}
}
static void do_extra_xstate_size_checks(void)
{
int paranoid_xstate_size = FXSAVE_SIZE + XSAVE_HDR_SIZE;
int i;
for (i = FIRST_EXTENDED_XFEATURE; i < XFEATURE_MAX; i++) {
if (!xfeature_enabled(i))
continue;
check_xstate_against_struct(i);
if (!using_compacted_format())
XSTATE_WARN_ON(xfeature_is_supervisor(i));
if (xfeature_is_aligned(i))
paranoid_xstate_size = ALIGN(paranoid_xstate_size, 64);
if (!using_compacted_format())
paranoid_xstate_size = xfeature_uncompacted_offset(i);
paranoid_xstate_size += xfeature_size(i);
}
XSTATE_WARN_ON(paranoid_xstate_size != xstate_size);
}
static unsigned int __init calculate_xstate_size(void)
{
unsigned int eax, ebx, ecx, edx;
unsigned int calculated_xstate_size;
if (!cpu_has_xsaves) {
cpuid_count(XSTATE_CPUID, 0, &eax, &ebx, &ecx, &edx);
calculated_xstate_size = ebx;
} else {
cpuid_count(XSTATE_CPUID, 1, &eax, &ebx, &ecx, &edx);
calculated_xstate_size = ebx;
}
return calculated_xstate_size;
}
static bool is_supported_xstate_size(unsigned int test_xstate_size)
{
if (test_xstate_size <= sizeof(union fpregs_state))
return true;
pr_warn("x86/fpu: xstate buffer too small (%zu < %d), disabling xsave\n",
sizeof(union fpregs_state), test_xstate_size);
return false;
}
static int init_xstate_size(void)
{
unsigned int possible_xstate_size = calculate_xstate_size();
if (!is_supported_xstate_size(possible_xstate_size))
return -EINVAL;
xstate_size = possible_xstate_size;
do_extra_xstate_size_checks();
return 0;
}
static void fpu__init_disable_system_xstate(void)
{
xfeatures_mask = 0;
cr4_clear_bits(X86_CR4_OSXSAVE);
fpu__xstate_clear_all_cpu_caps();
}
void __init fpu__init_system_xstate(void)
{
unsigned int eax, ebx, ecx, edx;
static int on_boot_cpu = 1;
int err;
WARN_ON_FPU(!on_boot_cpu);
on_boot_cpu = 0;
if (!cpu_has_xsave) {
pr_info("x86/fpu: Legacy x87 FPU detected.\n");
return;
}
if (boot_cpu_data.cpuid_level < XSTATE_CPUID) {
WARN_ON_FPU(1);
return;
}
cpuid_count(XSTATE_CPUID, 0, &eax, &ebx, &ecx, &edx);
xfeatures_mask = eax + ((u64)edx << 32);
if ((xfeatures_mask & XFEATURE_MASK_FPSSE) != XFEATURE_MASK_FPSSE) {
pr_err("x86/fpu: FP/SSE not present amongst the CPU's xstate features: 0x%llx.\n", xfeatures_mask);
BUG();
}
xfeatures_mask = xfeatures_mask & XCNTXT_MASK;
fpu__init_cpu_xstate();
err = init_xstate_size();
if (err) {
fpu__init_disable_system_xstate();
return;
}
update_regset_xstate_info(xstate_size, xfeatures_mask);
fpu__init_prepare_fx_sw_frame();
setup_init_fpu_buf();
setup_xstate_comp();
pr_info("x86/fpu: Enabled xstate features 0x%llx, context size is %d bytes, using '%s' format.\n",
xfeatures_mask,
xstate_size,
cpu_has_xsaves ? "compacted" : "standard");
}
void fpu__resume_cpu(void)
{
if (cpu_has_xsave)
xsetbv(XCR_XFEATURE_ENABLED_MASK, xfeatures_mask);
}
void *get_xsave_addr(struct xregs_state *xsave, int xstate_feature)
{
int feature_nr = fls64(xstate_feature) - 1;
if (!boot_cpu_has(X86_FEATURE_XSAVE))
return NULL;
WARN_ONCE(!(xfeatures_mask & xstate_feature),
"get of unsupported state");
if (!(xsave->header.xfeatures & xstate_feature))
return NULL;
return (void *)xsave + xstate_comp_offsets[feature_nr];
}
const void *get_xsave_field_ptr(int xsave_state)
{
struct fpu *fpu = &current->thread.fpu;
if (!fpu->fpstate_active)
return NULL;
fpu__save(fpu);
return get_xsave_addr(&fpu->state.xsave, xsave_state);
}
