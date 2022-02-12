static gpa_t kvm_trap_emul_gva_to_gpa_cb(gva_t gva)
{
gpa_t gpa;
gva_t kseg = KSEGX(gva);
gva_t gkseg = KVM_GUEST_KSEGX(gva);
if ((kseg == CKSEG0) || (kseg == CKSEG1))
gpa = CPHYSADDR(gva);
else if (gkseg == KVM_GUEST_KSEG0)
gpa = KVM_GUEST_CPHYSADDR(gva);
else {
kvm_err("%s: cannot find GPA for GVA: %#lx\n", __func__, gva);
kvm_mips_dump_host_tlbs();
gpa = KVM_INVALID_ADDR;
}
kvm_debug("%s: gva %#lx, gpa: %#llx\n", __func__, gva, gpa);
return gpa;
}
static int kvm_trap_emul_no_handler(struct kvm_vcpu *vcpu)
{
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
u32 exccode = (cause & CAUSEF_EXCCODE) >> CAUSEB_EXCCODE;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
u32 inst = 0;
if (cause & CAUSEF_BD)
opc += 1;
kvm_get_badinstr(opc, vcpu, &inst);
kvm_err("Exception Code: %d not handled @ PC: %p, inst: 0x%08x BadVaddr: %#lx Status: %#x\n",
exccode, opc, inst, badvaddr,
kvm_read_c0_guest_status(vcpu->arch.cop0));
kvm_arch_vcpu_dump_regs(vcpu);
vcpu->run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return RESUME_HOST;
}
static int kvm_trap_emul_handle_cop_unusable(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
if (((cause & CAUSEF_CE) >> CAUSEB_CE) == 1) {
if (!kvm_mips_guest_has_fpu(&vcpu->arch) ||
(kvm_read_c0_guest_status(cop0) & ST0_CU1) == 0) {
er = kvm_mips_emulate_fpu_exc(cause, opc, run, vcpu);
} else {
kvm_own_fpu(vcpu);
er = EMULATE_DONE;
}
} else {
er = kvm_mips_emulate_inst(cause, opc, run, vcpu);
}
switch (er) {
case EMULATE_DONE:
ret = RESUME_GUEST;
break;
case EMULATE_FAIL:
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
break;
case EMULATE_WAIT:
run->exit_reason = KVM_EXIT_INTR;
ret = RESUME_HOST;
break;
case EMULATE_HYPERCALL:
ret = kvm_mips_handle_hypcall(vcpu);
break;
default:
BUG();
}
return ret;
}
static int kvm_mips_bad_load(u32 cause, u32 *opc, struct kvm_run *run,
struct kvm_vcpu *vcpu)
{
enum emulation_result er;
union mips_instruction inst;
int err;
if (kvm_is_ifetch_fault(&vcpu->arch)) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return RESUME_HOST;
}
if (cause & CAUSEF_BD)
opc += 1;
err = kvm_get_badinstr(opc, vcpu, &inst.word);
if (err) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return RESUME_HOST;
}
er = kvm_mips_emulate_load(inst, cause, run, vcpu);
if (er == EMULATE_FAIL) {
kvm_err("Emulate load from MMIO space failed\n");
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
} else {
run->exit_reason = KVM_EXIT_MMIO;
}
return RESUME_HOST;
}
static int kvm_mips_bad_store(u32 cause, u32 *opc, struct kvm_run *run,
struct kvm_vcpu *vcpu)
{
enum emulation_result er;
union mips_instruction inst;
int err;
if (cause & CAUSEF_BD)
opc += 1;
err = kvm_get_badinstr(opc, vcpu, &inst.word);
if (err) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return RESUME_HOST;
}
er = kvm_mips_emulate_store(inst, cause, run, vcpu);
if (er == EMULATE_FAIL) {
kvm_err("Emulate store to MMIO space failed\n");
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
} else {
run->exit_reason = KVM_EXIT_MMIO;
}
return RESUME_HOST;
}
static int kvm_mips_bad_access(u32 cause, u32 *opc, struct kvm_run *run,
struct kvm_vcpu *vcpu, bool store)
{
if (store)
return kvm_mips_bad_store(cause, opc, run, vcpu);
else
return kvm_mips_bad_load(cause, opc, run, vcpu);
}
static int kvm_trap_emul_handle_tlb_mod(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
u32 cause = vcpu->arch.host_cp0_cause;
struct kvm_mips_tlb *tlb;
unsigned long entryhi;
int index;
if (KVM_GUEST_KSEGX(badvaddr) < KVM_GUEST_KSEG0
|| KVM_GUEST_KSEGX(badvaddr) == KVM_GUEST_KSEG23) {
entryhi = (badvaddr & VPN2_MASK) |
(kvm_read_c0_guest_entryhi(cop0) & KVM_ENTRYHI_ASID);
index = kvm_mips_guest_tlb_lookup(vcpu, entryhi);
if (unlikely(index < 0)) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return RESUME_HOST;
}
tlb = vcpu->arch.guest_tlb + index;
if (unlikely(!TLB_IS_VALID(*tlb, badvaddr))) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return RESUME_HOST;
}
if (!TLB_IS_DIRTY(*tlb, badvaddr)) {
kvm_mips_emulate_tlbmod(cause, opc, run, vcpu);
return RESUME_GUEST;
}
if (kvm_mips_handle_mapped_seg_tlb_fault(vcpu, tlb, badvaddr,
true))
return kvm_mips_bad_store(cause, opc, run, vcpu);
return RESUME_GUEST;
} else if (KVM_GUEST_KSEGX(badvaddr) == KVM_GUEST_KSEG0) {
if (kvm_mips_handle_kseg0_tlb_fault(badvaddr, vcpu, true) < 0)
return kvm_mips_bad_store(cause, opc, run, vcpu);
return RESUME_GUEST;
} else {
return kvm_mips_bad_store(cause, opc, run, vcpu);
}
}
static int kvm_trap_emul_handle_tlb_miss(struct kvm_vcpu *vcpu, bool store)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
if (((badvaddr & PAGE_MASK) == KVM_GUEST_COMMPAGE_ADDR)
&& KVM_GUEST_KERNEL_MODE(vcpu)) {
if (kvm_mips_handle_commpage_tlb_fault(badvaddr, vcpu) < 0) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
} else if (KVM_GUEST_KSEGX(badvaddr) < KVM_GUEST_KSEG0
|| KVM_GUEST_KSEGX(badvaddr) == KVM_GUEST_KSEG23) {
kvm_debug("USER ADDR TLB %s fault: cause %#x, PC: %p, BadVaddr: %#lx\n",
store ? "ST" : "LD", cause, opc, badvaddr);
er = kvm_mips_handle_tlbmiss(cause, opc, run, vcpu, store);
if (er == EMULATE_DONE)
ret = RESUME_GUEST;
else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
} else if (KVM_GUEST_KSEGX(badvaddr) == KVM_GUEST_KSEG0) {
if (kvm_mips_handle_kseg0_tlb_fault(badvaddr, vcpu, store) < 0)
ret = kvm_mips_bad_access(cause, opc, run, vcpu, store);
} else if (KVM_GUEST_KERNEL_MODE(vcpu)
&& (KSEGX(badvaddr) == CKSEG0 || KSEGX(badvaddr) == CKSEG1)) {
ret = kvm_mips_bad_access(cause, opc, run, vcpu, store);
} else {
kvm_err("Illegal TLB %s fault address , cause %#x, PC: %p, BadVaddr: %#lx\n",
store ? "ST" : "LD", cause, opc, badvaddr);
kvm_mips_dump_host_tlbs();
kvm_arch_vcpu_dump_regs(vcpu);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_tlb_st_miss(struct kvm_vcpu *vcpu)
{
return kvm_trap_emul_handle_tlb_miss(vcpu, true);
}
static int kvm_trap_emul_handle_tlb_ld_miss(struct kvm_vcpu *vcpu)
{
return kvm_trap_emul_handle_tlb_miss(vcpu, false);
}
static int kvm_trap_emul_handle_addr_err_st(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
u32 cause = vcpu->arch.host_cp0_cause;
int ret = RESUME_GUEST;
if (KVM_GUEST_KERNEL_MODE(vcpu)
&& (KSEGX(badvaddr) == CKSEG0 || KSEGX(badvaddr) == CKSEG1)) {
ret = kvm_mips_bad_store(cause, opc, run, vcpu);
} else {
kvm_err("Address Error (STORE): cause %#x, PC: %p, BadVaddr: %#lx\n",
cause, opc, badvaddr);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_addr_err_ld(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
u32 cause = vcpu->arch.host_cp0_cause;
int ret = RESUME_GUEST;
if (KSEGX(badvaddr) == CKSEG0 || KSEGX(badvaddr) == CKSEG1) {
ret = kvm_mips_bad_load(cause, opc, run, vcpu);
} else {
kvm_err("Address Error (LOAD): cause %#x, PC: %p, BadVaddr: %#lx\n",
cause, opc, badvaddr);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_syscall(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_emulate_syscall(cause, opc, run, vcpu);
if (er == EMULATE_DONE)
ret = RESUME_GUEST;
else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_res_inst(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_handle_ri(cause, opc, run, vcpu);
if (er == EMULATE_DONE)
ret = RESUME_GUEST;
else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_break(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_emulate_bp_exc(cause, opc, run, vcpu);
if (er == EMULATE_DONE)
ret = RESUME_GUEST;
else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_trap(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *)vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_emulate_trap_exc(cause, opc, run, vcpu);
if (er == EMULATE_DONE) {
ret = RESUME_GUEST;
} else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_msa_fpe(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *)vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_emulate_msafpe_exc(cause, opc, run, vcpu);
if (er == EMULATE_DONE) {
ret = RESUME_GUEST;
} else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_fpe(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *)vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_emulate_fpe_exc(cause, opc, run, vcpu);
if (er == EMULATE_DONE) {
ret = RESUME_GUEST;
} else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_msa_disabled(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
if (!kvm_mips_guest_has_msa(&vcpu->arch) ||
(kvm_read_c0_guest_status(cop0) & (ST0_CU1 | ST0_FR)) == ST0_CU1) {
er = kvm_mips_emulate_ri_exc(cause, opc, run, vcpu);
} else if (!(kvm_read_c0_guest_config5(cop0) & MIPS_CONF5_MSAEN)) {
er = kvm_mips_emulate_msadis_exc(cause, opc, run, vcpu);
} else {
kvm_own_msa(vcpu);
er = EMULATE_DONE;
}
switch (er) {
case EMULATE_DONE:
ret = RESUME_GUEST;
break;
case EMULATE_FAIL:
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
break;
default:
BUG();
}
return ret;
}
static int kvm_trap_emul_hardware_enable(void)
{
return 0;
}
static void kvm_trap_emul_hardware_disable(void)
{
}
static int kvm_trap_emul_check_extension(struct kvm *kvm, long ext)
{
int r;
switch (ext) {
case KVM_CAP_MIPS_TE:
r = 1;
break;
default:
r = 0;
break;
}
return r;
}
static int kvm_trap_emul_vcpu_init(struct kvm_vcpu *vcpu)
{
struct mm_struct *kern_mm = &vcpu->arch.guest_kernel_mm;
struct mm_struct *user_mm = &vcpu->arch.guest_user_mm;
kern_mm->pgd = pgd_alloc(kern_mm);
if (!kern_mm->pgd)
return -ENOMEM;
user_mm->pgd = pgd_alloc(user_mm);
if (!user_mm->pgd) {
pgd_free(kern_mm, kern_mm->pgd);
return -ENOMEM;
}
return 0;
}
static void kvm_mips_emul_free_gva_pt(pgd_t *pgd)
{
const unsigned long end = 0x80000000;
unsigned long pgd_va, pud_va, pmd_va;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
int i, j, k;
for (i = 0; i < USER_PTRS_PER_PGD; i++) {
if (pgd_none(pgd[i]))
continue;
pgd_va = (unsigned long)i << PGDIR_SHIFT;
if (pgd_va >= end)
break;
pud = pud_offset(pgd + i, 0);
for (j = 0; j < PTRS_PER_PUD; j++) {
if (pud_none(pud[j]))
continue;
pud_va = pgd_va | ((unsigned long)j << PUD_SHIFT);
if (pud_va >= end)
break;
pmd = pmd_offset(pud + j, 0);
for (k = 0; k < PTRS_PER_PMD; k++) {
if (pmd_none(pmd[k]))
continue;
pmd_va = pud_va | (k << PMD_SHIFT);
if (pmd_va >= end)
break;
pte = pte_offset(pmd + k, 0);
pte_free_kernel(NULL, pte);
}
pmd_free(NULL, pmd);
}
pud_free(NULL, pud);
}
pgd_free(NULL, pgd);
}
static void kvm_trap_emul_vcpu_uninit(struct kvm_vcpu *vcpu)
{
kvm_mips_emul_free_gva_pt(vcpu->arch.guest_kernel_mm.pgd);
kvm_mips_emul_free_gva_pt(vcpu->arch.guest_user_mm.pgd);
}
static int kvm_trap_emul_vcpu_setup(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
u32 config, config1;
int vcpu_id = vcpu->vcpu_id;
kvm_mips_init_count(vcpu, 100*1000*1000);
#ifndef CONFIG_CPU_MIPSR6
kvm_write_c0_guest_prid(cop0, 0x00019300);
#else
kvm_write_c0_guest_prid(cop0, 0x00010000);
#endif
config = read_c0_config() & MIPS_CONF_AR;
config |= MIPS_CONF_M | CONF_CM_CACHABLE_NONCOHERENT | MIPS_CONF_MT_TLB;
#ifdef CONFIG_CPU_BIG_ENDIAN
config |= CONF_BE;
#endif
if (cpu_has_vtag_icache)
config |= MIPS_CONF_VI;
kvm_write_c0_guest_config(cop0, config);
config1 = (read_c0_config1() & ~0x7f);
if (cpu_dcache_line_size()) {
config1 &= ~MIPS_CONF1_DL;
config1 |= ((ilog2(cpu_dcache_line_size()) - 1) <<
MIPS_CONF1_DL_SHF) & MIPS_CONF1_DL;
}
config1 &= ~(0x3f << 25);
config1 |= ((KVM_MIPS_GUEST_TLB_SIZE - 1) << 25);
config1 &= ~(MIPS_CONF1_C2 | MIPS_CONF1_MD | MIPS_CONF1_PC |
MIPS_CONF1_WR | MIPS_CONF1_CA);
kvm_write_c0_guest_config1(cop0, config1);
kvm_write_c0_guest_config2(cop0, MIPS_CONF_M);
kvm_write_c0_guest_config3(cop0, MIPS_CONF_M | MIPS_CONF3_ULRI);
kvm_write_c0_guest_config4(cop0, MIPS_CONF_M);
kvm_write_c0_guest_config5(cop0, 0);
kvm_write_c0_guest_config7(cop0, (MIPS_CONF7_WII) | (1 << 10));
kvm_write_c0_guest_status(cop0, ST0_BEV | ST0_ERL);
kvm_write_c0_guest_intctl(cop0, 0xFC000000);
kvm_write_c0_guest_ebase(cop0, KVM_GUEST_KSEG0 |
(vcpu_id & MIPS_EBASE_CPUNUM));
vcpu->arch.pc = KVM_GUEST_CKSEG1ADDR(0x1fc00000);
return 0;
}
static void kvm_trap_emul_flush_shadow_all(struct kvm *kvm)
{
kvm_flush_remote_tlbs(kvm);
}
static void kvm_trap_emul_flush_shadow_memslot(struct kvm *kvm,
const struct kvm_memory_slot *slot)
{
kvm_trap_emul_flush_shadow_all(kvm);
}
static unsigned long kvm_trap_emul_num_regs(struct kvm_vcpu *vcpu)
{
return ARRAY_SIZE(kvm_trap_emul_get_one_regs);
}
static int kvm_trap_emul_copy_reg_indices(struct kvm_vcpu *vcpu,
u64 __user *indices)
{
if (copy_to_user(indices, kvm_trap_emul_get_one_regs,
sizeof(kvm_trap_emul_get_one_regs)))
return -EFAULT;
indices += ARRAY_SIZE(kvm_trap_emul_get_one_regs);
return 0;
}
static int kvm_trap_emul_get_one_reg(struct kvm_vcpu *vcpu,
const struct kvm_one_reg *reg,
s64 *v)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
switch (reg->id) {
case KVM_REG_MIPS_CP0_INDEX:
*v = (long)kvm_read_c0_guest_index(cop0);
break;
case KVM_REG_MIPS_CP0_ENTRYLO0:
*v = kvm_read_c0_guest_entrylo0(cop0);
break;
case KVM_REG_MIPS_CP0_ENTRYLO1:
*v = kvm_read_c0_guest_entrylo1(cop0);
break;
case KVM_REG_MIPS_CP0_CONTEXT:
*v = (long)kvm_read_c0_guest_context(cop0);
break;
case KVM_REG_MIPS_CP0_USERLOCAL:
*v = (long)kvm_read_c0_guest_userlocal(cop0);
break;
case KVM_REG_MIPS_CP0_PAGEMASK:
*v = (long)kvm_read_c0_guest_pagemask(cop0);
break;
case KVM_REG_MIPS_CP0_WIRED:
*v = (long)kvm_read_c0_guest_wired(cop0);
break;
case KVM_REG_MIPS_CP0_HWRENA:
*v = (long)kvm_read_c0_guest_hwrena(cop0);
break;
case KVM_REG_MIPS_CP0_BADVADDR:
*v = (long)kvm_read_c0_guest_badvaddr(cop0);
break;
case KVM_REG_MIPS_CP0_ENTRYHI:
*v = (long)kvm_read_c0_guest_entryhi(cop0);
break;
case KVM_REG_MIPS_CP0_COMPARE:
*v = (long)kvm_read_c0_guest_compare(cop0);
break;
case KVM_REG_MIPS_CP0_STATUS:
*v = (long)kvm_read_c0_guest_status(cop0);
break;
case KVM_REG_MIPS_CP0_INTCTL:
*v = (long)kvm_read_c0_guest_intctl(cop0);
break;
case KVM_REG_MIPS_CP0_CAUSE:
*v = (long)kvm_read_c0_guest_cause(cop0);
break;
case KVM_REG_MIPS_CP0_EPC:
*v = (long)kvm_read_c0_guest_epc(cop0);
break;
case KVM_REG_MIPS_CP0_PRID:
*v = (long)kvm_read_c0_guest_prid(cop0);
break;
case KVM_REG_MIPS_CP0_EBASE:
*v = (long)kvm_read_c0_guest_ebase(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG:
*v = (long)kvm_read_c0_guest_config(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG1:
*v = (long)kvm_read_c0_guest_config1(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG2:
*v = (long)kvm_read_c0_guest_config2(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG3:
*v = (long)kvm_read_c0_guest_config3(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG4:
*v = (long)kvm_read_c0_guest_config4(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG5:
*v = (long)kvm_read_c0_guest_config5(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG7:
*v = (long)kvm_read_c0_guest_config7(cop0);
break;
case KVM_REG_MIPS_CP0_COUNT:
*v = kvm_mips_read_count(vcpu);
break;
case KVM_REG_MIPS_COUNT_CTL:
*v = vcpu->arch.count_ctl;
break;
case KVM_REG_MIPS_COUNT_RESUME:
*v = ktime_to_ns(vcpu->arch.count_resume);
break;
case KVM_REG_MIPS_COUNT_HZ:
*v = vcpu->arch.count_hz;
break;
case KVM_REG_MIPS_CP0_ERROREPC:
*v = (long)kvm_read_c0_guest_errorepc(cop0);
break;
case KVM_REG_MIPS_CP0_KSCRATCH1:
*v = (long)kvm_read_c0_guest_kscratch1(cop0);
break;
case KVM_REG_MIPS_CP0_KSCRATCH2:
*v = (long)kvm_read_c0_guest_kscratch2(cop0);
break;
case KVM_REG_MIPS_CP0_KSCRATCH3:
*v = (long)kvm_read_c0_guest_kscratch3(cop0);
break;
case KVM_REG_MIPS_CP0_KSCRATCH4:
*v = (long)kvm_read_c0_guest_kscratch4(cop0);
break;
case KVM_REG_MIPS_CP0_KSCRATCH5:
*v = (long)kvm_read_c0_guest_kscratch5(cop0);
break;
case KVM_REG_MIPS_CP0_KSCRATCH6:
*v = (long)kvm_read_c0_guest_kscratch6(cop0);
break;
default:
return -EINVAL;
}
return 0;
}
static int kvm_trap_emul_set_one_reg(struct kvm_vcpu *vcpu,
const struct kvm_one_reg *reg,
s64 v)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
int ret = 0;
unsigned int cur, change;
switch (reg->id) {
case KVM_REG_MIPS_CP0_INDEX:
kvm_write_c0_guest_index(cop0, v);
break;
case KVM_REG_MIPS_CP0_ENTRYLO0:
kvm_write_c0_guest_entrylo0(cop0, v);
break;
case KVM_REG_MIPS_CP0_ENTRYLO1:
kvm_write_c0_guest_entrylo1(cop0, v);
break;
case KVM_REG_MIPS_CP0_CONTEXT:
kvm_write_c0_guest_context(cop0, v);
break;
case KVM_REG_MIPS_CP0_USERLOCAL:
kvm_write_c0_guest_userlocal(cop0, v);
break;
case KVM_REG_MIPS_CP0_PAGEMASK:
kvm_write_c0_guest_pagemask(cop0, v);
break;
case KVM_REG_MIPS_CP0_WIRED:
kvm_write_c0_guest_wired(cop0, v);
break;
case KVM_REG_MIPS_CP0_HWRENA:
kvm_write_c0_guest_hwrena(cop0, v);
break;
case KVM_REG_MIPS_CP0_BADVADDR:
kvm_write_c0_guest_badvaddr(cop0, v);
break;
case KVM_REG_MIPS_CP0_ENTRYHI:
kvm_write_c0_guest_entryhi(cop0, v);
break;
case KVM_REG_MIPS_CP0_STATUS:
kvm_write_c0_guest_status(cop0, v);
break;
case KVM_REG_MIPS_CP0_INTCTL:
break;
case KVM_REG_MIPS_CP0_EPC:
kvm_write_c0_guest_epc(cop0, v);
break;
case KVM_REG_MIPS_CP0_PRID:
kvm_write_c0_guest_prid(cop0, v);
break;
case KVM_REG_MIPS_CP0_EBASE:
kvm_change_c0_guest_ebase(cop0, 0x1ffff000 | MIPS_EBASE_CPUNUM,
v);
break;
case KVM_REG_MIPS_CP0_COUNT:
kvm_mips_write_count(vcpu, v);
break;
case KVM_REG_MIPS_CP0_COMPARE:
kvm_mips_write_compare(vcpu, v, false);
break;
case KVM_REG_MIPS_CP0_CAUSE:
if ((kvm_read_c0_guest_cause(cop0) ^ v) & CAUSEF_DC) {
if (v & CAUSEF_DC) {
kvm_mips_count_disable_cause(vcpu);
kvm_change_c0_guest_cause(cop0, (u32)~CAUSEF_DC,
v);
} else {
kvm_change_c0_guest_cause(cop0, (u32)~CAUSEF_DC,
v);
kvm_mips_count_enable_cause(vcpu);
}
} else {
kvm_write_c0_guest_cause(cop0, v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG:
break;
case KVM_REG_MIPS_CP0_CONFIG1:
cur = kvm_read_c0_guest_config1(cop0);
change = (cur ^ v) & kvm_mips_config1_wrmask(vcpu);
if (change) {
v = cur ^ change;
kvm_write_c0_guest_config1(cop0, v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG2:
break;
case KVM_REG_MIPS_CP0_CONFIG3:
cur = kvm_read_c0_guest_config3(cop0);
change = (cur ^ v) & kvm_mips_config3_wrmask(vcpu);
if (change) {
v = cur ^ change;
kvm_write_c0_guest_config3(cop0, v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG4:
cur = kvm_read_c0_guest_config4(cop0);
change = (cur ^ v) & kvm_mips_config4_wrmask(vcpu);
if (change) {
v = cur ^ change;
kvm_write_c0_guest_config4(cop0, v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG5:
cur = kvm_read_c0_guest_config5(cop0);
change = (cur ^ v) & kvm_mips_config5_wrmask(vcpu);
if (change) {
v = cur ^ change;
kvm_write_c0_guest_config5(cop0, v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG7:
break;
case KVM_REG_MIPS_COUNT_CTL:
ret = kvm_mips_set_count_ctl(vcpu, v);
break;
case KVM_REG_MIPS_COUNT_RESUME:
ret = kvm_mips_set_count_resume(vcpu, v);
break;
case KVM_REG_MIPS_COUNT_HZ:
ret = kvm_mips_set_count_hz(vcpu, v);
break;
case KVM_REG_MIPS_CP0_ERROREPC:
kvm_write_c0_guest_errorepc(cop0, v);
break;
case KVM_REG_MIPS_CP0_KSCRATCH1:
kvm_write_c0_guest_kscratch1(cop0, v);
break;
case KVM_REG_MIPS_CP0_KSCRATCH2:
kvm_write_c0_guest_kscratch2(cop0, v);
break;
case KVM_REG_MIPS_CP0_KSCRATCH3:
kvm_write_c0_guest_kscratch3(cop0, v);
break;
case KVM_REG_MIPS_CP0_KSCRATCH4:
kvm_write_c0_guest_kscratch4(cop0, v);
break;
case KVM_REG_MIPS_CP0_KSCRATCH5:
kvm_write_c0_guest_kscratch5(cop0, v);
break;
case KVM_REG_MIPS_CP0_KSCRATCH6:
kvm_write_c0_guest_kscratch6(cop0, v);
break;
default:
return -EINVAL;
}
return ret;
}
static int kvm_trap_emul_vcpu_load(struct kvm_vcpu *vcpu, int cpu)
{
struct mm_struct *kern_mm = &vcpu->arch.guest_kernel_mm;
struct mm_struct *user_mm = &vcpu->arch.guest_user_mm;
struct mm_struct *mm;
if (current->flags & PF_VCPU) {
mm = KVM_GUEST_KERNEL_MODE(vcpu) ? kern_mm : user_mm;
if ((cpu_context(cpu, mm) ^ asid_cache(cpu)) &
asid_version_mask(cpu))
get_new_mmu_context(mm, cpu);
write_c0_entryhi(cpu_asid(cpu, mm));
TLBMISS_HANDLER_SETUP_PGD(mm->pgd);
kvm_mips_suspend_mm(cpu);
ehb();
}
return 0;
}
static int kvm_trap_emul_vcpu_put(struct kvm_vcpu *vcpu, int cpu)
{
kvm_lose_fpu(vcpu);
if (current->flags & PF_VCPU) {
if (((cpu_context(cpu, current->mm) ^ asid_cache(cpu)) &
asid_version_mask(cpu)))
get_new_mmu_context(current->mm, cpu);
write_c0_entryhi(cpu_asid(cpu, current->mm));
TLBMISS_HANDLER_SETUP_PGD(current->mm->pgd);
kvm_mips_resume_mm(cpu);
ehb();
}
return 0;
}
static void kvm_trap_emul_check_requests(struct kvm_vcpu *vcpu, int cpu,
bool reload_asid)
{
struct mm_struct *kern_mm = &vcpu->arch.guest_kernel_mm;
struct mm_struct *user_mm = &vcpu->arch.guest_user_mm;
struct mm_struct *mm;
int i;
if (likely(!kvm_request_pending(vcpu)))
return;
if (kvm_check_request(KVM_REQ_TLB_FLUSH, vcpu)) {
kvm_mips_flush_gva_pt(kern_mm->pgd, KMF_GPA | KMF_KERN);
kvm_mips_flush_gva_pt(user_mm->pgd, KMF_GPA | KMF_USER);
for_each_possible_cpu(i) {
cpu_context(i, kern_mm) = 0;
cpu_context(i, user_mm) = 0;
}
if (reload_asid) {
mm = KVM_GUEST_KERNEL_MODE(vcpu) ? kern_mm : user_mm;
get_new_mmu_context(mm, cpu);
htw_stop();
write_c0_entryhi(cpu_asid(cpu, mm));
TLBMISS_HANDLER_SETUP_PGD(mm->pgd);
htw_start();
}
}
}
void kvm_trap_emul_gva_lockless_begin(struct kvm_vcpu *vcpu)
{
WARN_ON_ONCE(irqs_disabled());
local_irq_disable();
smp_store_mb(vcpu->mode, READING_SHADOW_PAGE_TABLES);
kvm_trap_emul_check_requests(vcpu, smp_processor_id(), true);
}
void kvm_trap_emul_gva_lockless_end(struct kvm_vcpu *vcpu)
{
smp_store_release(&vcpu->mode, OUTSIDE_GUEST_MODE);
local_irq_enable();
}
static void kvm_trap_emul_vcpu_reenter(struct kvm_run *run,
struct kvm_vcpu *vcpu)
{
struct mm_struct *kern_mm = &vcpu->arch.guest_kernel_mm;
struct mm_struct *user_mm = &vcpu->arch.guest_user_mm;
struct mm_struct *mm;
struct mips_coproc *cop0 = vcpu->arch.cop0;
int i, cpu = smp_processor_id();
unsigned int gasid;
kvm_trap_emul_check_requests(vcpu, cpu, false);
if (KVM_GUEST_KERNEL_MODE(vcpu)) {
mm = kern_mm;
} else {
mm = user_mm;
gasid = kvm_read_c0_guest_entryhi(cop0) & KVM_ENTRYHI_ASID;
if (gasid != vcpu->arch.last_user_gasid) {
kvm_mips_flush_gva_pt(user_mm->pgd, KMF_USER);
for_each_possible_cpu(i)
cpu_context(i, user_mm) = 0;
vcpu->arch.last_user_gasid = gasid;
}
}
if ((cpu_context(cpu, mm) ^ asid_cache(cpu)) &
asid_version_mask(cpu))
get_new_mmu_context(mm, cpu);
}
static int kvm_trap_emul_vcpu_run(struct kvm_run *run, struct kvm_vcpu *vcpu)
{
int cpu = smp_processor_id();
int r;
kvm_mips_deliver_interrupts(vcpu,
kvm_read_c0_guest_cause(vcpu->arch.cop0));
kvm_trap_emul_vcpu_reenter(run, vcpu);
pagefault_disable();
htw_stop();
kvm_mips_suspend_mm(cpu);
r = vcpu->arch.vcpu_run(run, vcpu);
cpu = smp_processor_id();
if (((cpu_context(cpu, current->mm) ^ asid_cache(cpu)) &
asid_version_mask(cpu)))
get_new_mmu_context(current->mm, cpu);
write_c0_entryhi(cpu_asid(cpu, current->mm));
TLBMISS_HANDLER_SETUP_PGD(current->mm->pgd);
kvm_mips_resume_mm(cpu);
htw_start();
pagefault_enable();
return r;
}
int kvm_mips_emulation_init(struct kvm_mips_callbacks **install_callbacks)
{
*install_callbacks = &kvm_trap_emul_callbacks;
return 0;
}
