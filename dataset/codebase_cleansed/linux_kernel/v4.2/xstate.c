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
if (!(xfeatures & XSTATE_FP)) {
fx->cwd = 0x37f;
fx->swd = 0;
fx->twd = 0;
fx->fop = 0;
fx->rip = 0;
fx->rdp = 0;
memset(&fx->st_space[0], 0, 128);
}
if (!(xfeatures & XSTATE_SSE))
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
static void __init setup_xstate_features(void)
{
u32 eax, ebx, ecx, edx, leaf;
xfeatures_nr = fls64(xfeatures_mask);
for (leaf = 2; leaf < xfeatures_nr; leaf++) {
cpuid_count(XSTATE_CPUID, leaf, &eax, &ebx, &ecx, &edx);
xstate_offsets[leaf] = ebx;
xstate_sizes[leaf] = eax;
printk(KERN_INFO "x86/fpu: xstate_offset[%d]: %04x, xstate_sizes[%d]: %04x\n", leaf, ebx, leaf, eax);
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
print_xstate_feature(XSTATE_FP);
print_xstate_feature(XSTATE_SSE);
print_xstate_feature(XSTATE_YMM);
print_xstate_feature(XSTATE_BNDREGS);
print_xstate_feature(XSTATE_BNDCSR);
print_xstate_feature(XSTATE_OPMASK);
print_xstate_feature(XSTATE_ZMM_Hi256);
print_xstate_feature(XSTATE_Hi16_ZMM);
}
static void __init setup_xstate_comp(void)
{
unsigned int xstate_comp_sizes[sizeof(xfeatures_mask)*8];
int i;
xstate_comp_offsets[0] = 0;
xstate_comp_offsets[1] = offsetof(struct fxregs_state, xmm_space);
if (!cpu_has_xsaves) {
for (i = 2; i < xfeatures_nr; i++) {
if (test_bit(i, (unsigned long *)&xfeatures_mask)) {
xstate_comp_offsets[i] = xstate_offsets[i];
xstate_comp_sizes[i] = xstate_sizes[i];
}
}
return;
}
xstate_comp_offsets[2] = FXSAVE_SIZE + XSAVE_HDR_SIZE;
for (i = 2; i < xfeatures_nr; i++) {
if (test_bit(i, (unsigned long *)&xfeatures_mask))
xstate_comp_sizes[i] = xstate_sizes[i];
else
xstate_comp_sizes[i] = 0;
if (i > 2)
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
static void __init init_xstate_size(void)
{
unsigned int eax, ebx, ecx, edx;
int i;
if (!cpu_has_xsaves) {
cpuid_count(XSTATE_CPUID, 0, &eax, &ebx, &ecx, &edx);
xstate_size = ebx;
return;
}
xstate_size = FXSAVE_SIZE + XSAVE_HDR_SIZE;
for (i = 2; i < 64; i++) {
if (test_bit(i, (unsigned long *)&xfeatures_mask)) {
cpuid_count(XSTATE_CPUID, i, &eax, &ebx, &ecx, &edx);
xstate_size += eax;
}
}
}
void __init fpu__init_system_xstate(void)
{
unsigned int eax, ebx, ecx, edx;
static int on_boot_cpu = 1;
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
if ((xfeatures_mask & XSTATE_FPSSE) != XSTATE_FPSSE) {
pr_err("x86/fpu: FP/SSE not present amongst the CPU's xstate features: 0x%llx.\n", xfeatures_mask);
BUG();
}
xfeatures_mask = xfeatures_mask & XCNTXT_MASK;
fpu__init_cpu_xstate();
init_xstate_size();
update_regset_xstate_info(xstate_size, xfeatures_mask);
fpu__init_prepare_fx_sw_frame();
setup_init_fpu_buf();
setup_xstate_comp();
pr_info("x86/fpu: Enabled xstate features 0x%llx, context size is 0x%x bytes, using '%s' format.\n",
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
xsave = &current->thread.fpu.state.xsave;
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
