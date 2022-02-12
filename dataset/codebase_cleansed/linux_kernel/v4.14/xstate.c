void fpu__xstate_clear_all_cpu_caps(void)
{
setup_clear_cpu_cap(X86_FEATURE_XSAVE);
setup_clear_cpu_cap(X86_FEATURE_XSAVEOPT);
setup_clear_cpu_cap(X86_FEATURE_XSAVEC);
setup_clear_cpu_cap(X86_FEATURE_XSAVES);
setup_clear_cpu_cap(X86_FEATURE_AVX);
setup_clear_cpu_cap(X86_FEATURE_AVX2);
setup_clear_cpu_cap(X86_FEATURE_AVX512F);
setup_clear_cpu_cap(X86_FEATURE_AVX512IFMA);
setup_clear_cpu_cap(X86_FEATURE_AVX512PF);
setup_clear_cpu_cap(X86_FEATURE_AVX512ER);
setup_clear_cpu_cap(X86_FEATURE_AVX512CD);
setup_clear_cpu_cap(X86_FEATURE_AVX512DQ);
setup_clear_cpu_cap(X86_FEATURE_AVX512BW);
setup_clear_cpu_cap(X86_FEATURE_AVX512VL);
setup_clear_cpu_cap(X86_FEATURE_MPX);
setup_clear_cpu_cap(X86_FEATURE_XGETBV1);
setup_clear_cpu_cap(X86_FEATURE_AVX512VBMI);
setup_clear_cpu_cap(X86_FEATURE_PKU);
setup_clear_cpu_cap(X86_FEATURE_AVX512_4VNNIW);
setup_clear_cpu_cap(X86_FEATURE_AVX512_4FMAPS);
setup_clear_cpu_cap(X86_FEATURE_AVX512_VPOPCNTDQ);
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
static int xfeature_is_supervisor(int xfeature_nr)
{
u32 eax, ebx, ecx, edx;
cpuid_count(XSTATE_CPUID, xfeature_nr, &eax, &ebx, &ecx, &edx);
return !!(ecx & 1);
}
static int xfeature_is_user(int xfeature_nr)
{
return !xfeature_is_supervisor(xfeature_nr);
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
int offset = xstate_comp_offsets[feature_bit];
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
if (!boot_cpu_has(X86_FEATURE_XSAVE) || !xfeatures_mask)
return;
WARN_ONCE((xfeatures_mask & XFEATURE_MASK_SUPERVISOR),
"x86/fpu: XSAVES supervisor states are not yet implemented.\n");
xfeatures_mask &= ~XFEATURE_MASK_SUPERVISOR;
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
xstate_offsets[0] = 0;
xstate_sizes[0] = offsetof(struct fxregs_state, xmm_space);
xstate_offsets[1] = xstate_sizes[0];
xstate_sizes[1] = FIELD_SIZEOF(struct fxregs_state, xmm_space);
for (i = FIRST_EXTENDED_XFEATURE; i < XFEATURE_MAX; i++) {
if (!xfeature_enabled(i))
continue;
cpuid_count(XSTATE_CPUID, i, &eax, &ebx, &ecx, &edx);
if (xfeature_is_user(i))
xstate_offsets[i] = ebx;
xstate_sizes[i] = eax;
WARN_ONCE(last_good_offset > xstate_offsets[i],
"x86/fpu: misordered xstate at %d\n", last_good_offset);
last_good_offset = xstate_offsets[i];
}
}
static void __init print_xstate_feature(u64 xstate_mask)
{
const char *feature_name;
if (cpu_has_xfeatures(xstate_mask, &feature_name))
pr_info("x86/fpu: Supporting XSAVE feature 0x%03Lx: '%s'\n", xstate_mask, feature_name);
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
print_xstate_feature(XFEATURE_MASK_PKRU);
}
static int xfeature_is_aligned(int xfeature_nr)
{
u32 eax, ebx, ecx, edx;
CHECK_XFEATURE(xfeature_nr);
cpuid_count(XSTATE_CPUID, xfeature_nr, &eax, &ebx, &ecx, &edx);
return !!(ecx & 2);
}
static void __init setup_xstate_comp(void)
{
unsigned int xstate_comp_sizes[sizeof(xfeatures_mask)*8];
int i;
xstate_comp_offsets[0] = 0;
xstate_comp_offsets[1] = offsetof(struct fxregs_state, xmm_space);
if (!boot_cpu_has(X86_FEATURE_XSAVES)) {
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
if (i > FIRST_EXTENDED_XFEATURE) {
xstate_comp_offsets[i] = xstate_comp_offsets[i-1]
+ xstate_comp_sizes[i-1];
if (xfeature_is_aligned(i))
xstate_comp_offsets[i] =
ALIGN(xstate_comp_offsets[i], 64);
}
}
}
static void __init print_xstate_offset_size(void)
{
int i;
for (i = FIRST_EXTENDED_XFEATURE; i < XFEATURE_MAX; i++) {
if (!xfeature_enabled(i))
continue;
pr_info("x86/fpu: xstate_offset[%d]: %4d, xstate_sizes[%d]: %4d\n",
i, xstate_comp_offsets[i], i, xstate_sizes[i]);
}
}
static void __init setup_init_fpu_buf(void)
{
static int on_boot_cpu __initdata = 1;
WARN_ON_FPU(!on_boot_cpu);
on_boot_cpu = 0;
if (!boot_cpu_has(X86_FEATURE_XSAVE))
return;
setup_xstate_features();
print_xstate_features();
if (boot_cpu_has(X86_FEATURE_XSAVES))
init_fpstate.xsave.header.xcomp_bv = (u64)1 << 63 | xfeatures_mask;
copy_kernel_to_xregs_booting(&init_fpstate.xsave);
copy_xregs_to_kernel_booting(&init_fpstate.xsave);
}
static int xfeature_uncompacted_offset(int xfeature_nr)
{
u32 eax, ebx, ecx, edx;
if (XFEATURE_MASK_SUPERVISOR & (1 << xfeature_nr)) {
WARN_ONCE(1, "No fixed offset for xstate %d\n", xfeature_nr);
return -1;
}
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
int using_compacted_format(void)
{
return boot_cpu_has(X86_FEATURE_XSAVES);
}
int validate_xstate_header(const struct xstate_header *hdr)
{
if (hdr->xfeatures & (~xfeatures_mask | XFEATURE_MASK_SUPERVISOR))
return -EINVAL;
if (hdr->xcomp_bv)
return -EINVAL;
BUILD_BUG_ON(sizeof(hdr->reserved) != 48);
if (memchr_inv(hdr->reserved, 0, sizeof(hdr->reserved)))
return -EINVAL;
return 0;
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
XCHECK_SZ(sz, nr, XFEATURE_PKRU, struct pkru_state);
if ((nr < XFEATURE_YMM) ||
(nr >= XFEATURE_MAX) ||
(nr == XFEATURE_PT_UNIMPLEMENTED_SO_FAR)) {
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
XSTATE_WARN_ON(paranoid_xstate_size != fpu_kernel_xstate_size);
}
static unsigned int __init get_xsaves_size(void)
{
unsigned int eax, ebx, ecx, edx;
cpuid_count(XSTATE_CPUID, 1, &eax, &ebx, &ecx, &edx);
return ebx;
}
static unsigned int __init get_xsave_size(void)
{
unsigned int eax, ebx, ecx, edx;
cpuid_count(XSTATE_CPUID, 0, &eax, &ebx, &ecx, &edx);
return ebx;
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
unsigned int possible_xstate_size;
unsigned int xsave_size;
xsave_size = get_xsave_size();
if (boot_cpu_has(X86_FEATURE_XSAVES))
possible_xstate_size = get_xsaves_size();
else
possible_xstate_size = xsave_size;
if (!is_supported_xstate_size(possible_xstate_size))
return -EINVAL;
fpu_kernel_xstate_size = possible_xstate_size;
do_extra_xstate_size_checks();
fpu_user_xstate_size = xsave_size;
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
static int on_boot_cpu __initdata = 1;
int err;
WARN_ON_FPU(!on_boot_cpu);
on_boot_cpu = 0;
if (!boot_cpu_has(X86_FEATURE_FPU)) {
pr_info("x86/fpu: No FPU detected\n");
return;
}
if (!boot_cpu_has(X86_FEATURE_XSAVE)) {
pr_info("x86/fpu: x87 FPU will use %s\n",
boot_cpu_has(X86_FEATURE_FXSR) ? "FXSAVE" : "FSAVE");
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
goto out_disable;
}
xfeatures_mask &= fpu__get_supported_xfeatures_mask();
fpu__init_cpu_xstate();
err = init_xstate_size();
if (err)
goto out_disable;
update_regset_xstate_info(fpu_user_xstate_size, xfeatures_mask & ~XFEATURE_MASK_SUPERVISOR);
fpu__init_prepare_fx_sw_frame();
setup_init_fpu_buf();
setup_xstate_comp();
print_xstate_offset_size();
pr_info("x86/fpu: Enabled xstate features 0x%llx, context size is %d bytes, using '%s' format.\n",
xfeatures_mask,
fpu_kernel_xstate_size,
boot_cpu_has(X86_FEATURE_XSAVES) ? "compacted" : "standard");
return;
out_disable:
fpu__init_disable_system_xstate();
}
void fpu__resume_cpu(void)
{
if (boot_cpu_has(X86_FEATURE_XSAVE))
xsetbv(XCR_XFEATURE_ENABLED_MASK, xfeatures_mask);
}
void *__raw_xsave_addr(struct xregs_state *xsave, int xstate_feature_mask)
{
int feature_nr = fls64(xstate_feature_mask) - 1;
if (!xfeature_enabled(feature_nr)) {
WARN_ON_FPU(1);
return NULL;
}
return (void *)xsave + xstate_comp_offsets[feature_nr];
}
void *get_xsave_addr(struct xregs_state *xsave, int xstate_feature)
{
if (!boot_cpu_has(X86_FEATURE_XSAVE))
return NULL;
WARN_ONCE(!(xfeatures_mask & xstate_feature),
"get of unsupported state");
if (!(xsave->header.xfeatures & xstate_feature))
return NULL;
return __raw_xsave_addr(xsave, xstate_feature);
}
const void *get_xsave_field_ptr(int xsave_state)
{
struct fpu *fpu = &current->thread.fpu;
if (!fpu->initialized)
return NULL;
fpu__save(fpu);
return get_xsave_addr(&fpu->state.xsave, xsave_state);
}
int arch_set_user_pkey_access(struct task_struct *tsk, int pkey,
unsigned long init_val)
{
u32 old_pkru;
int pkey_shift = (pkey * PKRU_BITS_PER_PKEY);
u32 new_pkru_bits = 0;
if (!boot_cpu_has(X86_FEATURE_OSPKE))
return -EINVAL;
if (init_val & PKEY_DISABLE_ACCESS)
new_pkru_bits |= PKRU_AD_BIT;
if (init_val & PKEY_DISABLE_WRITE)
new_pkru_bits |= PKRU_WD_BIT;
new_pkru_bits <<= pkey_shift;
old_pkru = read_pkru();
old_pkru &= ~((PKRU_AD_BIT|PKRU_WD_BIT) << pkey_shift);
write_pkru(old_pkru | new_pkru_bits);
return 0;
}
static inline bool xfeatures_mxcsr_quirk(u64 xfeatures)
{
if (!(xfeatures & (XFEATURE_MASK_SSE|XFEATURE_MASK_YMM)))
return false;
if (xfeatures & XFEATURE_MASK_FP)
return false;
return true;
}
static inline void
__copy_xstate_to_kernel(void *kbuf, const void *data,
unsigned int offset, unsigned int size, unsigned int size_total)
{
if (offset < size_total) {
unsigned int copy = min(size, size_total - offset);
memcpy(kbuf + offset, data, copy);
}
}
int copy_xstate_to_kernel(void *kbuf, struct xregs_state *xsave, unsigned int offset_start, unsigned int size_total)
{
unsigned int offset, size;
struct xstate_header header;
int i;
if (unlikely(offset_start != 0))
return -EFAULT;
memset(&header, 0, sizeof(header));
header.xfeatures = xsave->header.xfeatures;
header.xfeatures &= ~XFEATURE_MASK_SUPERVISOR;
offset = offsetof(struct xregs_state, header);
size = sizeof(header);
__copy_xstate_to_kernel(kbuf, &header, offset, size, size_total);
for (i = 0; i < XFEATURE_MAX; i++) {
if ((header.xfeatures >> i) & 1) {
void *src = __raw_xsave_addr(xsave, 1 << i);
offset = xstate_offsets[i];
size = xstate_sizes[i];
if (offset + size > size_total)
break;
__copy_xstate_to_kernel(kbuf, src, offset, size, size_total);
}
}
if (xfeatures_mxcsr_quirk(header.xfeatures)) {
offset = offsetof(struct fxregs_state, mxcsr);
size = MXCSR_AND_FLAGS_SIZE;
__copy_xstate_to_kernel(kbuf, &xsave->i387.mxcsr, offset, size, size_total);
}
offset = offsetof(struct fxregs_state, sw_reserved);
size = sizeof(xstate_fx_sw_bytes);
__copy_xstate_to_kernel(kbuf, xstate_fx_sw_bytes, offset, size, size_total);
return 0;
}
static inline int
__copy_xstate_to_user(void __user *ubuf, const void *data, unsigned int offset, unsigned int size, unsigned int size_total)
{
if (!size)
return 0;
if (offset < size_total) {
unsigned int copy = min(size, size_total - offset);
if (__copy_to_user(ubuf + offset, data, copy))
return -EFAULT;
}
return 0;
}
int copy_xstate_to_user(void __user *ubuf, struct xregs_state *xsave, unsigned int offset_start, unsigned int size_total)
{
unsigned int offset, size;
int ret, i;
struct xstate_header header;
if (unlikely(offset_start != 0))
return -EFAULT;
memset(&header, 0, sizeof(header));
header.xfeatures = xsave->header.xfeatures;
header.xfeatures &= ~XFEATURE_MASK_SUPERVISOR;
offset = offsetof(struct xregs_state, header);
size = sizeof(header);
ret = __copy_xstate_to_user(ubuf, &header, offset, size, size_total);
if (ret)
return ret;
for (i = 0; i < XFEATURE_MAX; i++) {
if ((header.xfeatures >> i) & 1) {
void *src = __raw_xsave_addr(xsave, 1 << i);
offset = xstate_offsets[i];
size = xstate_sizes[i];
if (offset + size > size_total)
break;
ret = __copy_xstate_to_user(ubuf, src, offset, size, size_total);
if (ret)
return ret;
}
}
if (xfeatures_mxcsr_quirk(header.xfeatures)) {
offset = offsetof(struct fxregs_state, mxcsr);
size = MXCSR_AND_FLAGS_SIZE;
__copy_xstate_to_user(ubuf, &xsave->i387.mxcsr, offset, size, size_total);
}
offset = offsetof(struct fxregs_state, sw_reserved);
size = sizeof(xstate_fx_sw_bytes);
ret = __copy_xstate_to_user(ubuf, xstate_fx_sw_bytes, offset, size, size_total);
if (ret)
return ret;
return 0;
}
int copy_kernel_to_xstate(struct xregs_state *xsave, const void *kbuf)
{
unsigned int offset, size;
int i;
struct xstate_header hdr;
offset = offsetof(struct xregs_state, header);
size = sizeof(hdr);
memcpy(&hdr, kbuf + offset, size);
if (validate_xstate_header(&hdr))
return -EINVAL;
for (i = 0; i < XFEATURE_MAX; i++) {
u64 mask = ((u64)1 << i);
if (hdr.xfeatures & mask) {
void *dst = __raw_xsave_addr(xsave, 1 << i);
offset = xstate_offsets[i];
size = xstate_sizes[i];
memcpy(dst, kbuf + offset, size);
}
}
if (xfeatures_mxcsr_quirk(hdr.xfeatures)) {
offset = offsetof(struct fxregs_state, mxcsr);
size = MXCSR_AND_FLAGS_SIZE;
memcpy(&xsave->i387.mxcsr, kbuf + offset, size);
}
xsave->header.xfeatures &= XFEATURE_MASK_SUPERVISOR;
xsave->header.xfeatures |= hdr.xfeatures;
return 0;
}
int copy_user_to_xstate(struct xregs_state *xsave, const void __user *ubuf)
{
unsigned int offset, size;
int i;
struct xstate_header hdr;
offset = offsetof(struct xregs_state, header);
size = sizeof(hdr);
if (__copy_from_user(&hdr, ubuf + offset, size))
return -EFAULT;
if (validate_xstate_header(&hdr))
return -EINVAL;
for (i = 0; i < XFEATURE_MAX; i++) {
u64 mask = ((u64)1 << i);
if (hdr.xfeatures & mask) {
void *dst = __raw_xsave_addr(xsave, 1 << i);
offset = xstate_offsets[i];
size = xstate_sizes[i];
if (__copy_from_user(dst, ubuf + offset, size))
return -EFAULT;
}
}
if (xfeatures_mxcsr_quirk(hdr.xfeatures)) {
offset = offsetof(struct fxregs_state, mxcsr);
size = MXCSR_AND_FLAGS_SIZE;
if (__copy_from_user(&xsave->i387.mxcsr, ubuf + offset, size))
return -EFAULT;
}
xsave->header.xfeatures &= XFEATURE_MASK_SUPERVISOR;
xsave->header.xfeatures |= hdr.xfeatures;
return 0;
}
