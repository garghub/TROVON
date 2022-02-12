int kvm_mips_entry_setup(void)
{
unsigned int kscratch_mask = cpu_data[0].kscratch_mask & 0xfc;
if (kscratch_mask) {
scratch_vcpu[0] = 31;
scratch_vcpu[1] = ffs(kscratch_mask) - 1;
kscratch_mask &= ~BIT(scratch_vcpu[1]);
}
if (kscratch_mask) {
scratch_tmp[0] = 31;
scratch_tmp[1] = ffs(kscratch_mask) - 1;
kscratch_mask &= ~BIT(scratch_tmp[1]);
}
return 0;
}
static void kvm_mips_build_save_scratch(u32 **p, unsigned int tmp,
unsigned int frame)
{
UASM_i_MFC0(p, tmp, scratch_vcpu[0], scratch_vcpu[1]);
UASM_i_SW(p, tmp, offsetof(struct pt_regs, cp0_epc), frame);
if (scratch_tmp[0] == 31) {
UASM_i_MFC0(p, tmp, scratch_tmp[0], scratch_tmp[1]);
UASM_i_SW(p, tmp, offsetof(struct pt_regs, cp0_cause), frame);
}
}
static void kvm_mips_build_restore_scratch(u32 **p, unsigned int tmp,
unsigned int frame)
{
UASM_i_LW(p, tmp, offsetof(struct pt_regs, cp0_epc), frame);
UASM_i_MTC0(p, tmp, scratch_vcpu[0], scratch_vcpu[1]);
if (scratch_tmp[0] == 31) {
UASM_i_LW(p, tmp, offsetof(struct pt_regs, cp0_cause), frame);
UASM_i_MTC0(p, tmp, scratch_tmp[0], scratch_tmp[1]);
}
}
static inline void build_set_exc_base(u32 **p, unsigned int reg)
{
if (cpu_has_ebase_wg) {
uasm_i_ori(p, reg, reg, MIPS_EBASE_WG);
UASM_i_MTC0(p, reg, C0_EBASE);
} else {
uasm_i_mtc0(p, reg, C0_EBASE);
}
}
void *kvm_mips_build_vcpu_run(void *addr)
{
u32 *p = addr;
unsigned int i;
UASM_i_ADDIU(&p, K1, SP, -(int)sizeof(struct pt_regs));
for (i = 16; i < 32; ++i) {
if (i == 24)
i = 28;
UASM_i_SW(&p, i, offsetof(struct pt_regs, regs[i]), K1);
}
uasm_i_mfc0(&p, V0, C0_STATUS);
UASM_i_SW(&p, V0, offsetof(struct pt_regs, cp0_status), K1);
kvm_mips_build_save_scratch(&p, V1, K1);
UASM_i_MTC0(&p, A1, scratch_vcpu[0], scratch_vcpu[1]);
UASM_i_ADDIU(&p, K1, A1, offsetof(struct kvm_vcpu, arch));
UASM_i_SW(&p, SP, offsetof(struct kvm_vcpu_arch, host_stack), K1);
UASM_i_SW(&p, GP, offsetof(struct kvm_vcpu_arch, host_gp), K1);
UASM_i_LA(&p, K0, ST0_EXL | KSU_USER | ST0_BEV | ST0_KX_IF_64);
uasm_i_mtc0(&p, K0, C0_STATUS);
uasm_i_ehb(&p);
UASM_i_LW(&p, K0, offsetof(struct kvm_vcpu_arch, guest_ebase), K1);
build_set_exc_base(&p, K0);
uasm_i_addiu(&p, K0, ZERO, ST0_EXL | KSU_USER | ST0_IE | ST0_KX_IF_64);
uasm_i_andi(&p, V0, V0, ST0_IM);
uasm_i_or(&p, K0, K0, V0);
uasm_i_mtc0(&p, K0, C0_STATUS);
uasm_i_ehb(&p);
p = kvm_mips_build_enter_guest(p);
return p;
}
static void *kvm_mips_build_enter_guest(void *addr)
{
u32 *p = addr;
unsigned int i;
struct uasm_label labels[2];
struct uasm_reloc relocs[2];
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
UASM_i_LW(&p, T0, offsetof(struct kvm_vcpu_arch, pc), K1);
UASM_i_MTC0(&p, T0, C0_EPC);
UASM_i_LW(&p, T0, offsetof(struct kvm_vcpu_arch, cop0), K1);
UASM_i_LW(&p, T0, offsetof(struct mips_coproc, reg[MIPS_CP0_STATUS][0]),
T0);
uasm_i_andi(&p, T0, T0, KSU_USER | ST0_ERL | ST0_EXL);
uasm_i_xori(&p, T0, T0, KSU_USER);
uasm_il_bnez(&p, &r, T0, label_kernel_asid);
UASM_i_ADDIU(&p, T1, K1,
offsetof(struct kvm_vcpu_arch, guest_kernel_asid));
UASM_i_ADDIU(&p, T1, K1,
offsetof(struct kvm_vcpu_arch, guest_user_asid));
uasm_l_kernel_asid(&l, p);
uasm_i_lw(&p, T2, offsetof(struct thread_info, cpu), GP);
uasm_i_sll(&p, T2, T2, 2);
UASM_i_ADDU(&p, T3, T1, T2);
uasm_i_lw(&p, K0, 0, T3);
#ifdef CONFIG_MIPS_ASID_BITS_VARIABLE
uasm_i_addiu(&p, T3, ZERO, sizeof(struct cpuinfo_mips)/4);
uasm_i_mul(&p, T2, T2, T3);
UASM_i_LA_mostly(&p, AT, (long)&cpu_data[0].asid_mask);
UASM_i_ADDU(&p, AT, AT, T2);
UASM_i_LW(&p, T2, uasm_rel_lo((long)&cpu_data[0].asid_mask), AT);
uasm_i_and(&p, K0, K0, T2);
#else
uasm_i_andi(&p, K0, K0, MIPS_ENTRYHI_ASID);
#endif
uasm_i_mtc0(&p, K0, C0_ENTRYHI);
uasm_i_ehb(&p);
uasm_i_mtc0(&p, ZERO, C0_HWRENA);
for (i = 1; i < 32; ++i) {
if (i == K0 || i == K1)
continue;
UASM_i_LW(&p, i, offsetof(struct kvm_vcpu_arch, gprs[i]), K1);
}
#ifndef CONFIG_CPU_MIPSR6
UASM_i_LW(&p, K0, offsetof(struct kvm_vcpu_arch, hi), K1);
uasm_i_mthi(&p, K0);
UASM_i_LW(&p, K0, offsetof(struct kvm_vcpu_arch, lo), K1);
uasm_i_mtlo(&p, K0);
#endif
UASM_i_LW(&p, K0, offsetof(struct kvm_vcpu_arch, gprs[K0]), K1);
UASM_i_LW(&p, K1, offsetof(struct kvm_vcpu_arch, gprs[K1]), K1);
uasm_i_eret(&p);
uasm_resolve_relocs(relocs, labels);
return p;
}
void *kvm_mips_build_exception(void *addr, void *handler)
{
u32 *p = addr;
struct uasm_label labels[2];
struct uasm_reloc relocs[2];
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
UASM_i_MTC0(&p, K1, scratch_tmp[0], scratch_tmp[1]);
UASM_i_MFC0(&p, K1, scratch_vcpu[0], scratch_vcpu[1]);
UASM_i_ADDIU(&p, K1, K1, offsetof(struct kvm_vcpu, arch));
UASM_i_SW(&p, K0, offsetof(struct kvm_vcpu_arch, gprs[K0]), K1);
uasm_il_b(&p, &r, label_exit_common);
uasm_i_nop(&p);
uasm_l_exit_common(&l, handler);
uasm_resolve_relocs(relocs, labels);
return p;
}
void *kvm_mips_build_exit(void *addr)
{
u32 *p = addr;
unsigned int i;
struct uasm_label labels[3];
struct uasm_reloc relocs[3];
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
for (i = 0; i < 32; ++i) {
if (i == K0 || i == K1)
continue;
UASM_i_SW(&p, i, offsetof(struct kvm_vcpu_arch, gprs[i]), K1);
}
#ifndef CONFIG_CPU_MIPSR6
uasm_i_mfhi(&p, T0);
UASM_i_SW(&p, T0, offsetof(struct kvm_vcpu_arch, hi), K1);
uasm_i_mflo(&p, T0);
UASM_i_SW(&p, T0, offsetof(struct kvm_vcpu_arch, lo), K1);
#endif
uasm_i_ehb(&p);
UASM_i_MFC0(&p, T0, scratch_tmp[0], scratch_tmp[1]);
UASM_i_SW(&p, T0, offsetof(struct kvm_vcpu_arch, gprs[K1]), K1);
UASM_i_MFC0(&p, A1, scratch_vcpu[0], scratch_vcpu[1]);
uasm_i_move(&p, S1, A1);
UASM_i_LW(&p, A0, offsetof(struct kvm_vcpu, run), A1);
uasm_i_move(&p, S0, A0);
UASM_i_MFC0(&p, K0, C0_EPC);
UASM_i_SW(&p, K0, offsetof(struct kvm_vcpu_arch, pc), K1);
UASM_i_MFC0(&p, K0, C0_BADVADDR);
UASM_i_SW(&p, K0, offsetof(struct kvm_vcpu_arch, host_cp0_badvaddr),
K1);
uasm_i_mfc0(&p, K0, C0_CAUSE);
uasm_i_sw(&p, K0, offsetof(struct kvm_vcpu_arch, host_cp0_cause), K1);
uasm_i_mfc0(&p, V0, C0_STATUS);
uasm_i_lui(&p, AT, ST0_BEV >> 16);
uasm_i_or(&p, K0, V0, AT);
uasm_i_mtc0(&p, K0, C0_STATUS);
uasm_i_ehb(&p);
UASM_i_LA_mostly(&p, K0, (long)&ebase);
UASM_i_LW(&p, K0, uasm_rel_lo((long)&ebase), K0);
build_set_exc_base(&p, K0);
if (raw_cpu_has_fpu) {
uasm_i_lui(&p, AT, ST0_CU1 >> 16);
uasm_i_and(&p, V1, V0, AT);
uasm_il_beqz(&p, &r, V1, label_fpu_1);
uasm_i_nop(&p);
uasm_i_cfc1(&p, T0, 31);
uasm_i_sw(&p, T0, offsetof(struct kvm_vcpu_arch, fpu.fcr31),
K1);
uasm_i_ctc1(&p, ZERO, 31);
uasm_l_fpu_1(&l, p);
}
if (cpu_has_msa) {
uasm_i_mfc0(&p, T0, C0_CONFIG5);
uasm_i_ext(&p, T0, T0, 27, 1);
uasm_il_beqz(&p, &r, T0, label_msa_1);
uasm_i_nop(&p);
uasm_i_cfcmsa(&p, T0, MSA_CSR);
uasm_i_sw(&p, T0, offsetof(struct kvm_vcpu_arch, fpu.msacsr),
K1);
uasm_i_ctcmsa(&p, MSA_CSR, ZERO);
uasm_l_msa_1(&l, p);
}
uasm_i_addiu(&p, AT, ZERO, ~(ST0_EXL | KSU_USER | ST0_IE));
uasm_i_and(&p, V0, V0, AT);
uasm_i_lui(&p, AT, ST0_CU0 >> 16);
uasm_i_or(&p, V0, V0, AT);
uasm_i_mtc0(&p, V0, C0_STATUS);
uasm_i_ehb(&p);
UASM_i_LW(&p, GP, offsetof(struct kvm_vcpu_arch, host_gp), K1);
UASM_i_LW(&p, SP, offsetof(struct kvm_vcpu_arch, host_stack), K1);
UASM_i_ADDIU(&p, SP, SP, -(int)sizeof(struct pt_regs));
kvm_mips_build_restore_scratch(&p, K0, SP);
UASM_i_LA_mostly(&p, K0, (long)&hwrena);
uasm_i_lw(&p, K0, uasm_rel_lo((long)&hwrena), K0);
uasm_i_mtc0(&p, K0, C0_HWRENA);
UASM_i_LA(&p, T9, (unsigned long)kvm_mips_handle_exit);
uasm_i_jalr(&p, RA, T9);
UASM_i_ADDIU(&p, SP, SP, -CALLFRAME_SIZ);
uasm_resolve_relocs(relocs, labels);
p = kvm_mips_build_ret_from_exit(p);
return p;
}
static void *kvm_mips_build_ret_from_exit(void *addr)
{
u32 *p = addr;
struct uasm_label labels[2];
struct uasm_reloc relocs[2];
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
uasm_i_di(&p, ZERO);
uasm_i_ehb(&p);
uasm_i_move(&p, K1, S1);
UASM_i_ADDIU(&p, K1, K1, offsetof(struct kvm_vcpu, arch));
uasm_i_andi(&p, T0, V0, RESUME_HOST);
uasm_il_bnez(&p, &r, T0, label_return_to_host);
uasm_i_nop(&p);
p = kvm_mips_build_ret_to_guest(p);
uasm_l_return_to_host(&l, p);
p = kvm_mips_build_ret_to_host(p);
uasm_resolve_relocs(relocs, labels);
return p;
}
static void *kvm_mips_build_ret_to_guest(void *addr)
{
u32 *p = addr;
UASM_i_MTC0(&p, S1, scratch_vcpu[0], scratch_vcpu[1]);
UASM_i_LW(&p, T0, offsetof(struct kvm_vcpu_arch, guest_ebase), K1);
uasm_i_mfc0(&p, V1, C0_STATUS);
uasm_i_lui(&p, AT, ST0_BEV >> 16);
uasm_i_or(&p, K0, V1, AT);
uasm_i_mtc0(&p, K0, C0_STATUS);
uasm_i_ehb(&p);
build_set_exc_base(&p, T0);
uasm_i_ori(&p, V1, V1, ST0_EXL | KSU_USER | ST0_IE);
UASM_i_LA(&p, AT, ~(ST0_CU0 | ST0_MX));
uasm_i_and(&p, V1, V1, AT);
uasm_i_mtc0(&p, V1, C0_STATUS);
uasm_i_ehb(&p);
p = kvm_mips_build_enter_guest(p);
return p;
}
static void *kvm_mips_build_ret_to_host(void *addr)
{
u32 *p = addr;
unsigned int i;
UASM_i_LW(&p, K1, offsetof(struct kvm_vcpu_arch, host_stack), K1);
UASM_i_ADDIU(&p, K1, K1, -(int)sizeof(struct pt_regs));
uasm_i_sra(&p, K0, V0, 2);
uasm_i_move(&p, V0, K0);
for (i = 16; i < 31; ++i) {
if (i == 24)
i = 28;
UASM_i_LW(&p, i, offsetof(struct pt_regs, regs[i]), K1);
}
UASM_i_LA_mostly(&p, K0, (long)&hwrena);
uasm_i_lw(&p, K0, uasm_rel_lo((long)&hwrena), K0);
uasm_i_mtc0(&p, K0, C0_HWRENA);
UASM_i_LW(&p, RA, offsetof(struct pt_regs, regs[RA]), K1);
uasm_i_jr(&p, RA);
uasm_i_nop(&p);
return p;
}
