static int __init xpa_disable(char *s)
{
mips_xpa_disabled = 1;
return 1;
}
static inline int r45k_bvahwbug(void)
{
return 0;
}
static inline int r4k_250MHZhwbug(void)
{
return 0;
}
static inline int __maybe_unused bcm1250_m3_war(void)
{
return BCM1250_M3_WAR;
}
static inline int __maybe_unused r10000_llsc_war(void)
{
return R10000_LLSC_WAR;
}
static int use_bbit_insns(void)
{
switch (current_cpu_type()) {
case CPU_CAVIUM_OCTEON:
case CPU_CAVIUM_OCTEON_PLUS:
case CPU_CAVIUM_OCTEON2:
case CPU_CAVIUM_OCTEON3:
return 1;
default:
return 0;
}
}
static int use_lwx_insns(void)
{
switch (current_cpu_type()) {
case CPU_CAVIUM_OCTEON2:
case CPU_CAVIUM_OCTEON3:
return 1;
default:
return 0;
}
}
static bool scratchpad_available(void)
{
return true;
}
static int scratchpad_offset(int i)
{
i += 1;
return CONFIG_CAVIUM_OCTEON_CVMSEG_SIZE * 128 - (8 * i) - 32768;
}
static bool scratchpad_available(void)
{
return false;
}
static int scratchpad_offset(int i)
{
BUG();
return 0;
}
static int m4kc_tlbp_war(void)
{
return (current_cpu_data.processor_id & 0xffff00) ==
(PRID_COMP_MIPS | PRID_IMP_4KC);
}
static void uasm_bgezl_hazard(u32 **p, struct uasm_reloc **r, int instance)
{
switch (instance) {
case 0 ... 7:
uasm_il_bgezl(p, r, 0, label_tlbw_hazard_0 + instance);
return;
default:
BUG();
}
}
static void uasm_bgezl_label(struct uasm_label **l, u32 **p, int instance)
{
switch (instance) {
case 0 ... 7:
uasm_build_label(l, *p, label_tlbw_hazard_0 + instance);
break;
default:
BUG();
}
}
static void output_pgtable_bits_defines(void)
{
#define pr_define(fmt, ...) \
pr_debug("#define " fmt, ##__VA_ARGS__)
pr_debug("#include <asm/asm.h>\n");
pr_debug("#include <asm/regdef.h>\n");
pr_debug("\n");
pr_define("_PAGE_PRESENT_SHIFT %d\n", _PAGE_PRESENT_SHIFT);
pr_define("_PAGE_NO_READ_SHIFT %d\n", _PAGE_NO_READ_SHIFT);
pr_define("_PAGE_WRITE_SHIFT %d\n", _PAGE_WRITE_SHIFT);
pr_define("_PAGE_ACCESSED_SHIFT %d\n", _PAGE_ACCESSED_SHIFT);
pr_define("_PAGE_MODIFIED_SHIFT %d\n", _PAGE_MODIFIED_SHIFT);
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
pr_define("_PAGE_HUGE_SHIFT %d\n", _PAGE_HUGE_SHIFT);
#endif
#ifdef _PAGE_NO_EXEC_SHIFT
if (cpu_has_rixi)
pr_define("_PAGE_NO_EXEC_SHIFT %d\n", _PAGE_NO_EXEC_SHIFT);
#endif
pr_define("_PAGE_GLOBAL_SHIFT %d\n", _PAGE_GLOBAL_SHIFT);
pr_define("_PAGE_VALID_SHIFT %d\n", _PAGE_VALID_SHIFT);
pr_define("_PAGE_DIRTY_SHIFT %d\n", _PAGE_DIRTY_SHIFT);
pr_define("_PFN_SHIFT %d\n", _PFN_SHIFT);
pr_debug("\n");
}
static inline void dump_handler(const char *symbol, const u32 *handler, int count)
{
int i;
pr_debug("LEAF(%s)\n", symbol);
pr_debug("\t.set push\n");
pr_debug("\t.set noreorder\n");
for (i = 0; i < count; i++)
pr_debug("\t.word\t0x%08x\t\t# %p\n", handler[i], &handler[i]);
pr_debug("\t.set\tpop\n");
pr_debug("\tEND(%s)\n", symbol);
}
static inline int __maybe_unused c0_kscratch(void)
{
switch (current_cpu_type()) {
case CPU_XLP:
case CPU_XLR:
return 22;
default:
return 31;
}
}
static int allocate_kscratch(void)
{
int r;
unsigned int a = cpu_data[0].kscratch_mask & ~kscratch_used_mask;
r = ffs(a);
if (r == 0)
return -1;
r--;
kscratch_used_mask |= (1 << r);
return r;
}
static struct work_registers build_get_work_registers(u32 **p)
{
struct work_registers r;
if (scratch_reg >= 0) {
UASM_i_MTC0(p, 1, c0_kscratch(), scratch_reg);
r.r1 = K0;
r.r2 = K1;
r.r3 = 1;
return r;
}
if (num_possible_cpus() > 1) {
UASM_i_CPUID_MFC0(p, K0, SMP_CPUID_REG);
UASM_i_SRL_SAFE(p, K0, K0, SMP_CPUID_REGSHIFT);
UASM_i_SLL(p, K0, K0, ilog2(sizeof(struct tlb_reg_save)));
UASM_i_LA(p, K1, (long)&handler_reg_save);
UASM_i_ADDU(p, K0, K0, K1);
} else {
UASM_i_LA(p, K0, (long)&handler_reg_save);
}
UASM_i_SW(p, 1, offsetof(struct tlb_reg_save, a), K0);
UASM_i_SW(p, 2, offsetof(struct tlb_reg_save, b), K0);
r.r1 = K1;
r.r2 = 1;
r.r3 = 2;
return r;
}
static void build_restore_work_registers(u32 **p)
{
if (scratch_reg >= 0) {
UASM_i_MFC0(p, 1, c0_kscratch(), scratch_reg);
return;
}
UASM_i_LW(p, 1, offsetof(struct tlb_reg_save, a), K0);
UASM_i_LW(p, 2, offsetof(struct tlb_reg_save, b), K0);
}
static void build_r3000_tlb_refill_handler(void)
{
long pgdc = (long)pgd_current;
u32 *p;
memset(tlb_handler, 0, sizeof(tlb_handler));
p = tlb_handler;
uasm_i_mfc0(&p, K0, C0_BADVADDR);
uasm_i_lui(&p, K1, uasm_rel_hi(pgdc));
uasm_i_lw(&p, K1, uasm_rel_lo(pgdc), K1);
uasm_i_srl(&p, K0, K0, 22);
uasm_i_sll(&p, K0, K0, 2);
uasm_i_addu(&p, K1, K1, K0);
uasm_i_mfc0(&p, K0, C0_CONTEXT);
uasm_i_lw(&p, K1, 0, K1);
uasm_i_andi(&p, K0, K0, 0xffc);
uasm_i_addu(&p, K1, K1, K0);
uasm_i_lw(&p, K0, 0, K1);
uasm_i_nop(&p);
uasm_i_mtc0(&p, K0, C0_ENTRYLO0);
uasm_i_mfc0(&p, K1, C0_EPC);
uasm_i_tlbwr(&p);
uasm_i_jr(&p, K1);
uasm_i_rfe(&p);
if (p > tlb_handler + 32)
panic("TLB refill handler space exceeded");
pr_debug("Wrote TLB refill handler (%u instructions).\n",
(unsigned int)(p - tlb_handler));
memcpy((void *)ebase, tlb_handler, 0x80);
local_flush_icache_range(ebase, ebase + 0x80);
dump_handler("r3000_tlb_refill", (u32 *)ebase, 32);
}
static void __maybe_unused build_tlb_probe_entry(u32 **p)
{
switch (current_cpu_type()) {
case CPU_R4600:
case CPU_R4700:
case CPU_R5000:
case CPU_NEVADA:
uasm_i_nop(p);
uasm_i_tlbp(p);
break;
default:
uasm_i_tlbp(p);
break;
}
}
void build_tlb_write_entry(u32 **p, struct uasm_label **l,
struct uasm_reloc **r,
enum tlb_write_entry wmode)
{
void(*tlbw)(u32 **) = NULL;
switch (wmode) {
case tlb_random: tlbw = uasm_i_tlbwr; break;
case tlb_indexed: tlbw = uasm_i_tlbwi; break;
}
if (cpu_has_mips_r2_r6) {
if (cpu_has_mips_r2_exec_hazard)
uasm_i_ehb(p);
tlbw(p);
return;
}
switch (current_cpu_type()) {
case CPU_R4000PC:
case CPU_R4000SC:
case CPU_R4000MC:
case CPU_R4400PC:
case CPU_R4400SC:
case CPU_R4400MC:
uasm_bgezl_hazard(p, r, hazard_instance);
tlbw(p);
uasm_bgezl_label(l, p, hazard_instance);
hazard_instance++;
uasm_i_nop(p);
break;
case CPU_R4600:
case CPU_R4700:
uasm_i_nop(p);
tlbw(p);
uasm_i_nop(p);
break;
case CPU_R5000:
case CPU_NEVADA:
uasm_i_nop(p);
uasm_i_nop(p);
tlbw(p);
break;
case CPU_R4300:
case CPU_5KC:
case CPU_TX49XX:
case CPU_PR4450:
case CPU_XLR:
uasm_i_nop(p);
tlbw(p);
break;
case CPU_R10000:
case CPU_R12000:
case CPU_R14000:
case CPU_R16000:
case CPU_4KC:
case CPU_4KEC:
case CPU_M14KC:
case CPU_M14KEC:
case CPU_SB1:
case CPU_SB1A:
case CPU_4KSC:
case CPU_20KC:
case CPU_25KF:
case CPU_BMIPS32:
case CPU_BMIPS3300:
case CPU_BMIPS4350:
case CPU_BMIPS4380:
case CPU_BMIPS5000:
case CPU_LOONGSON2:
case CPU_LOONGSON3:
case CPU_R5500:
if (m4kc_tlbp_war())
uasm_i_nop(p);
case CPU_ALCHEMY:
tlbw(p);
break;
case CPU_RM7000:
uasm_i_nop(p);
uasm_i_nop(p);
uasm_i_nop(p);
uasm_i_nop(p);
tlbw(p);
break;
case CPU_VR4111:
case CPU_VR4121:
case CPU_VR4122:
case CPU_VR4181:
case CPU_VR4181A:
uasm_i_nop(p);
uasm_i_nop(p);
tlbw(p);
uasm_i_nop(p);
uasm_i_nop(p);
break;
case CPU_VR4131:
case CPU_VR4133:
case CPU_R5432:
uasm_i_nop(p);
uasm_i_nop(p);
tlbw(p);
break;
case CPU_JZRISC:
tlbw(p);
uasm_i_nop(p);
break;
default:
panic("No TLB refill handler yet (CPU type: %d)",
current_cpu_type());
break;
}
}
static __maybe_unused void build_convert_pte_to_entrylo(u32 **p,
unsigned int reg)
{
if (_PAGE_GLOBAL_SHIFT == 0) {
return;
}
if (cpu_has_rixi && _PAGE_NO_EXEC) {
if (fill_includes_sw_bits) {
UASM_i_ROTR(p, reg, reg, ilog2(_PAGE_GLOBAL));
} else {
UASM_i_SRL(p, reg, reg, ilog2(_PAGE_NO_EXEC));
UASM_i_ROTR(p, reg, reg,
ilog2(_PAGE_GLOBAL) - ilog2(_PAGE_NO_EXEC));
}
} else {
#ifdef CONFIG_PHYS_ADDR_T_64BIT
uasm_i_dsrl_safe(p, reg, reg, ilog2(_PAGE_GLOBAL));
#else
UASM_i_SRL(p, reg, reg, ilog2(_PAGE_GLOBAL));
#endif
}
}
static void build_restore_pagemask(u32 **p, struct uasm_reloc **r,
unsigned int tmp, enum label_id lid,
int restore_scratch)
{
if (restore_scratch) {
if (PM_DEFAULT_MASK >> 16) {
uasm_i_lui(p, tmp, PM_DEFAULT_MASK >> 16);
uasm_i_ori(p, tmp, tmp, PM_DEFAULT_MASK & 0xffff);
uasm_i_mtc0(p, tmp, C0_PAGEMASK);
uasm_il_b(p, r, lid);
} else if (PM_DEFAULT_MASK) {
uasm_i_ori(p, tmp, 0, PM_DEFAULT_MASK);
uasm_i_mtc0(p, tmp, C0_PAGEMASK);
uasm_il_b(p, r, lid);
} else {
uasm_i_mtc0(p, 0, C0_PAGEMASK);
uasm_il_b(p, r, lid);
}
if (scratch_reg >= 0)
UASM_i_MFC0(p, 1, c0_kscratch(), scratch_reg);
else
UASM_i_LW(p, 1, scratchpad_offset(0), 0);
} else {
if (PM_DEFAULT_MASK >> 16) {
uasm_i_lui(p, tmp, PM_DEFAULT_MASK >> 16);
uasm_i_ori(p, tmp, tmp, PM_DEFAULT_MASK & 0xffff);
uasm_il_b(p, r, lid);
uasm_i_mtc0(p, tmp, C0_PAGEMASK);
} else if (PM_DEFAULT_MASK) {
uasm_i_ori(p, tmp, 0, PM_DEFAULT_MASK);
uasm_il_b(p, r, lid);
uasm_i_mtc0(p, tmp, C0_PAGEMASK);
} else {
uasm_il_b(p, r, lid);
uasm_i_mtc0(p, 0, C0_PAGEMASK);
}
}
}
static void build_huge_tlb_write_entry(u32 **p, struct uasm_label **l,
struct uasm_reloc **r,
unsigned int tmp,
enum tlb_write_entry wmode,
int restore_scratch)
{
uasm_i_lui(p, tmp, PM_HUGE_MASK >> 16);
uasm_i_ori(p, tmp, tmp, PM_HUGE_MASK & 0xffff);
uasm_i_mtc0(p, tmp, C0_PAGEMASK);
build_tlb_write_entry(p, l, r, wmode);
build_restore_pagemask(p, r, tmp, label_leave, restore_scratch);
}
static void
build_is_huge_pte(u32 **p, struct uasm_reloc **r, unsigned int tmp,
unsigned int pmd, int lid)
{
UASM_i_LW(p, tmp, 0, pmd);
if (use_bbit_insns()) {
uasm_il_bbit1(p, r, tmp, ilog2(_PAGE_HUGE), lid);
} else {
uasm_i_andi(p, tmp, tmp, _PAGE_HUGE);
uasm_il_bnez(p, r, tmp, lid);
}
}
static void build_huge_update_entries(u32 **p, unsigned int pte,
unsigned int tmp)
{
int small_sequence;
small_sequence = (HPAGE_SIZE >> 7) < 0x10000;
if (!small_sequence)
uasm_i_lui(p, tmp, HPAGE_SIZE >> (7 + 16));
build_convert_pte_to_entrylo(p, pte);
UASM_i_MTC0(p, pte, C0_ENTRYLO0);
if (small_sequence)
UASM_i_ADDIU(p, pte, pte, HPAGE_SIZE >> 7);
else
UASM_i_ADDU(p, pte, pte, tmp);
UASM_i_MTC0(p, pte, C0_ENTRYLO1);
}
static void build_huge_handler_tail(u32 **p, struct uasm_reloc **r,
struct uasm_label **l,
unsigned int pte,
unsigned int ptr,
unsigned int flush)
{
#ifdef CONFIG_SMP
UASM_i_SC(p, pte, 0, ptr);
uasm_il_beqz(p, r, pte, label_tlb_huge_update);
UASM_i_LW(p, pte, 0, ptr);
#else
UASM_i_SW(p, pte, 0, ptr);
#endif
if (cpu_has_ftlb && flush) {
BUG_ON(!cpu_has_tlbinv);
UASM_i_MFC0(p, ptr, C0_ENTRYHI);
uasm_i_ori(p, ptr, ptr, MIPS_ENTRYHI_EHINV);
UASM_i_MTC0(p, ptr, C0_ENTRYHI);
build_tlb_write_entry(p, l, r, tlb_indexed);
uasm_i_xori(p, ptr, ptr, MIPS_ENTRYHI_EHINV);
UASM_i_MTC0(p, ptr, C0_ENTRYHI);
build_huge_update_entries(p, pte, ptr);
build_huge_tlb_write_entry(p, l, r, pte, tlb_random, 0);
return;
}
build_huge_update_entries(p, pte, ptr);
build_huge_tlb_write_entry(p, l, r, pte, tlb_indexed, 0);
}
void build_get_pmde64(u32 **p, struct uasm_label **l, struct uasm_reloc **r,
unsigned int tmp, unsigned int ptr)
{
#ifndef CONFIG_MIPS_PGD_C0_CONTEXT
long pgdc = (long)pgd_current;
#endif
uasm_i_dmfc0(p, tmp, C0_BADVADDR);
if (check_for_high_segbits) {
uasm_i_dsrl_safe(p, ptr, tmp, PGDIR_SHIFT + PGD_ORDER + PAGE_SHIFT - 3);
uasm_il_bnez(p, r, ptr, label_vmalloc);
} else {
uasm_il_bltz(p, r, tmp, label_vmalloc);
}
if (pgd_reg != -1) {
if (cpu_has_ldpte)
UASM_i_MFC0(p, ptr, C0_PWBASE);
else
UASM_i_MFC0(p, ptr, c0_kscratch(), pgd_reg);
} else {
#if defined(CONFIG_MIPS_PGD_C0_CONTEXT)
UASM_i_MFC0(p, ptr, C0_CONTEXT);
uasm_i_dins(p, ptr, 0, 0, 23);
uasm_i_ori(p, ptr, ptr, 0x540);
uasm_i_drotr(p, ptr, ptr, 11);
#elif defined(CONFIG_SMP)
UASM_i_CPUID_MFC0(p, ptr, SMP_CPUID_REG);
uasm_i_dsrl_safe(p, ptr, ptr, SMP_CPUID_PTRSHIFT);
UASM_i_LA_mostly(p, tmp, pgdc);
uasm_i_daddu(p, ptr, ptr, tmp);
uasm_i_dmfc0(p, tmp, C0_BADVADDR);
uasm_i_ld(p, ptr, uasm_rel_lo(pgdc), ptr);
#else
UASM_i_LA_mostly(p, ptr, pgdc);
uasm_i_ld(p, ptr, uasm_rel_lo(pgdc), ptr);
#endif
}
uasm_l_vmalloc_done(l, *p);
uasm_i_dsrl_safe(p, tmp, tmp, PGDIR_SHIFT - 3);
uasm_i_andi(p, tmp, tmp, (PTRS_PER_PGD - 1)<<3);
uasm_i_daddu(p, ptr, ptr, tmp);
#ifndef __PAGETABLE_PUD_FOLDED
uasm_i_dmfc0(p, tmp, C0_BADVADDR);
uasm_i_ld(p, ptr, 0, ptr);
uasm_i_dsrl_safe(p, tmp, tmp, PUD_SHIFT - 3);
uasm_i_andi(p, tmp, tmp, (PTRS_PER_PUD - 1) << 3);
uasm_i_daddu(p, ptr, ptr, tmp);
#endif
#ifndef __PAGETABLE_PMD_FOLDED
uasm_i_dmfc0(p, tmp, C0_BADVADDR);
uasm_i_ld(p, ptr, 0, ptr);
uasm_i_dsrl_safe(p, tmp, tmp, PMD_SHIFT-3);
uasm_i_andi(p, tmp, tmp, (PTRS_PER_PMD - 1)<<3);
uasm_i_daddu(p, ptr, ptr, tmp);
#endif
}
static void
build_get_pgd_vmalloc64(u32 **p, struct uasm_label **l, struct uasm_reloc **r,
unsigned int bvaddr, unsigned int ptr,
enum vmalloc64_mode mode)
{
long swpd = (long)swapper_pg_dir;
int single_insn_swpd;
int did_vmalloc_branch = 0;
single_insn_swpd = uasm_in_compat_space_p(swpd) && !uasm_rel_lo(swpd);
uasm_l_vmalloc(l, *p);
if (mode != not_refill && check_for_high_segbits) {
if (single_insn_swpd) {
uasm_il_bltz(p, r, bvaddr, label_vmalloc_done);
uasm_i_lui(p, ptr, uasm_rel_hi(swpd));
did_vmalloc_branch = 1;
} else {
uasm_il_bgez(p, r, bvaddr, label_large_segbits_fault);
}
}
if (!did_vmalloc_branch) {
if (single_insn_swpd) {
uasm_il_b(p, r, label_vmalloc_done);
uasm_i_lui(p, ptr, uasm_rel_hi(swpd));
} else {
UASM_i_LA_mostly(p, ptr, swpd);
uasm_il_b(p, r, label_vmalloc_done);
if (uasm_in_compat_space_p(swpd))
uasm_i_addiu(p, ptr, ptr, uasm_rel_lo(swpd));
else
uasm_i_daddiu(p, ptr, ptr, uasm_rel_lo(swpd));
}
}
if (mode != not_refill && check_for_high_segbits) {
uasm_l_large_segbits_fault(l, *p);
UASM_i_LA(p, ptr, (unsigned long)tlb_do_page_fault_0);
uasm_i_jr(p, ptr);
if (mode == refill_scratch) {
if (scratch_reg >= 0)
UASM_i_MFC0(p, 1, c0_kscratch(), scratch_reg);
else
UASM_i_LW(p, 1, scratchpad_offset(0), 0);
} else {
uasm_i_nop(p);
}
}
}
void build_get_pgde32(u32 **p, unsigned int tmp, unsigned int ptr)
{
if (pgd_reg != -1) {
uasm_i_mfc0(p, ptr, c0_kscratch(), pgd_reg);
uasm_i_mfc0(p, tmp, C0_BADVADDR);
} else {
long pgdc = (long)pgd_current;
#ifdef CONFIG_SMP
uasm_i_mfc0(p, ptr, SMP_CPUID_REG);
UASM_i_LA_mostly(p, tmp, pgdc);
uasm_i_srl(p, ptr, ptr, SMP_CPUID_PTRSHIFT);
uasm_i_addu(p, ptr, tmp, ptr);
#else
UASM_i_LA_mostly(p, ptr, pgdc);
#endif
uasm_i_mfc0(p, tmp, C0_BADVADDR);
uasm_i_lw(p, ptr, uasm_rel_lo(pgdc), ptr);
}
uasm_i_srl(p, tmp, tmp, PGDIR_SHIFT);
uasm_i_sll(p, tmp, tmp, PGD_T_LOG2);
uasm_i_addu(p, ptr, ptr, tmp);
}
static void build_adjust_context(u32 **p, unsigned int ctx)
{
unsigned int shift = 4 - (PTE_T_LOG2 + 1) + PAGE_SHIFT - 12;
unsigned int mask = (PTRS_PER_PTE / 2 - 1) << (PTE_T_LOG2 + 1);
switch (current_cpu_type()) {
case CPU_VR41XX:
case CPU_VR4111:
case CPU_VR4121:
case CPU_VR4122:
case CPU_VR4131:
case CPU_VR4181:
case CPU_VR4181A:
case CPU_VR4133:
shift += 2;
break;
default:
break;
}
if (shift)
UASM_i_SRL(p, ctx, ctx, shift);
uasm_i_andi(p, ctx, ctx, mask);
}
void build_get_ptep(u32 **p, unsigned int tmp, unsigned int ptr)
{
switch (current_cpu_type()) {
case CPU_NEVADA:
UASM_i_LW(p, ptr, 0, ptr);
GET_CONTEXT(p, tmp);
break;
default:
GET_CONTEXT(p, tmp);
UASM_i_LW(p, ptr, 0, ptr);
break;
}
build_adjust_context(p, tmp);
UASM_i_ADDU(p, ptr, ptr, tmp);
}
void build_update_entries(u32 **p, unsigned int tmp, unsigned int ptep)
{
int pte_off_even = 0;
int pte_off_odd = sizeof(pte_t);
#if defined(CONFIG_CPU_MIPS32) && defined(CONFIG_PHYS_ADDR_T_64BIT)
pte_off_even += offsetof(pte_t, pte_high);
pte_off_odd += offsetof(pte_t, pte_high);
#endif
if (IS_ENABLED(CONFIG_XPA)) {
uasm_i_lw(p, tmp, pte_off_even, ptep);
UASM_i_ROTR(p, tmp, tmp, ilog2(_PAGE_GLOBAL));
UASM_i_MTC0(p, tmp, C0_ENTRYLO0);
if (cpu_has_xpa && !mips_xpa_disabled) {
uasm_i_lw(p, tmp, 0, ptep);
uasm_i_ext(p, tmp, tmp, 0, 24);
uasm_i_mthc0(p, tmp, C0_ENTRYLO0);
}
uasm_i_lw(p, tmp, pte_off_odd, ptep);
UASM_i_ROTR(p, tmp, tmp, ilog2(_PAGE_GLOBAL));
UASM_i_MTC0(p, tmp, C0_ENTRYLO1);
if (cpu_has_xpa && !mips_xpa_disabled) {
uasm_i_lw(p, tmp, sizeof(pte_t), ptep);
uasm_i_ext(p, tmp, tmp, 0, 24);
uasm_i_mthc0(p, tmp, C0_ENTRYLO1);
}
return;
}
UASM_i_LW(p, tmp, pte_off_even, ptep);
UASM_i_LW(p, ptep, pte_off_odd, ptep);
if (r45k_bvahwbug())
build_tlb_probe_entry(p);
build_convert_pte_to_entrylo(p, tmp);
if (r4k_250MHZhwbug())
UASM_i_MTC0(p, 0, C0_ENTRYLO0);
UASM_i_MTC0(p, tmp, C0_ENTRYLO0);
build_convert_pte_to_entrylo(p, ptep);
if (r45k_bvahwbug())
uasm_i_mfc0(p, tmp, C0_INDEX);
if (r4k_250MHZhwbug())
UASM_i_MTC0(p, 0, C0_ENTRYLO1);
UASM_i_MTC0(p, ptep, C0_ENTRYLO1);
}
static struct mips_huge_tlb_info
build_fast_tlb_refill_handler (u32 **p, struct uasm_label **l,
struct uasm_reloc **r, unsigned int tmp,
unsigned int ptr, int c0_scratch_reg)
{
struct mips_huge_tlb_info rv;
unsigned int even, odd;
int vmalloc_branch_delay_filled = 0;
const int scratch = 1;
rv.huge_pte = scratch;
rv.restore_scratch = 0;
rv.need_reload_pte = false;
if (check_for_high_segbits) {
UASM_i_MFC0(p, tmp, C0_BADVADDR);
if (pgd_reg != -1)
UASM_i_MFC0(p, ptr, c0_kscratch(), pgd_reg);
else
UASM_i_MFC0(p, ptr, C0_CONTEXT);
if (c0_scratch_reg >= 0)
UASM_i_MTC0(p, scratch, c0_kscratch(), c0_scratch_reg);
else
UASM_i_SW(p, scratch, scratchpad_offset(0), 0);
uasm_i_dsrl_safe(p, scratch, tmp,
PGDIR_SHIFT + PGD_ORDER + PAGE_SHIFT - 3);
uasm_il_bnez(p, r, scratch, label_vmalloc);
if (pgd_reg == -1) {
vmalloc_branch_delay_filled = 1;
uasm_i_dins(p, ptr, 0, 0, 23);
}
} else {
if (pgd_reg != -1)
UASM_i_MFC0(p, ptr, c0_kscratch(), pgd_reg);
else
UASM_i_MFC0(p, ptr, C0_CONTEXT);
UASM_i_MFC0(p, tmp, C0_BADVADDR);
if (c0_scratch_reg >= 0)
UASM_i_MTC0(p, scratch, c0_kscratch(), c0_scratch_reg);
else
UASM_i_SW(p, scratch, scratchpad_offset(0), 0);
if (pgd_reg == -1)
uasm_i_dins(p, ptr, 0, 0, 23);
uasm_il_bltz(p, r, tmp, label_vmalloc);
}
if (pgd_reg == -1) {
vmalloc_branch_delay_filled = 1;
uasm_i_ori(p, ptr, ptr, 0x540);
uasm_i_drotr(p, ptr, ptr, 11);
}
#ifdef __PAGETABLE_PMD_FOLDED
#define LOC_PTEP scratch
#else
#define LOC_PTEP ptr
#endif
if (!vmalloc_branch_delay_filled)
uasm_i_dsrl_safe(p, scratch, tmp, PGDIR_SHIFT - 3);
uasm_l_vmalloc_done(l, *p);
if (vmalloc_branch_delay_filled)
uasm_i_dsrl_safe(p, scratch, tmp, PGDIR_SHIFT - 3);
#ifdef __PAGETABLE_PMD_FOLDED
GET_CONTEXT(p, tmp);
#endif
uasm_i_andi(p, scratch, scratch, (PTRS_PER_PGD - 1) << 3);
if (use_lwx_insns()) {
UASM_i_LWX(p, LOC_PTEP, scratch, ptr);
} else {
uasm_i_daddu(p, ptr, ptr, scratch);
uasm_i_ld(p, LOC_PTEP, 0, ptr);
}
#ifndef __PAGETABLE_PUD_FOLDED
uasm_i_dsrl_safe(p, scratch, tmp, PUD_SHIFT - 3);
uasm_i_andi(p, scratch, scratch, (PTRS_PER_PUD - 1) << 3);
if (use_lwx_insns()) {
UASM_i_LWX(p, ptr, scratch, ptr);
} else {
uasm_i_daddu(p, ptr, ptr, scratch);
UASM_i_LW(p, ptr, 0, ptr);
}
#endif
#ifndef __PAGETABLE_PMD_FOLDED
uasm_i_dsrl_safe(p, scratch, tmp, PMD_SHIFT - 3);
uasm_i_andi(p, scratch, scratch, (PTRS_PER_PMD - 1) << 3);
GET_CONTEXT(p, tmp);
if (use_lwx_insns()) {
UASM_i_LWX(p, scratch, scratch, ptr);
} else {
uasm_i_daddu(p, ptr, ptr, scratch);
UASM_i_LW(p, scratch, 0, ptr);
}
#endif
build_adjust_context(p, tmp);
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
uasm_il_bbit1(p, r, scratch, ilog2(_PAGE_HUGE), label_tlb_huge_update);
if (use_lwx_insns())
uasm_i_nop(p);
#endif
if (use_lwx_insns()) {
even = ptr;
odd = tmp;
UASM_i_LWX(p, even, scratch, tmp);
UASM_i_ADDIU(p, tmp, tmp, sizeof(pte_t));
UASM_i_LWX(p, odd, scratch, tmp);
} else {
UASM_i_ADDU(p, ptr, scratch, tmp);
even = tmp;
odd = ptr;
UASM_i_LW(p, even, 0, ptr);
UASM_i_LW(p, odd, sizeof(pte_t), ptr);
}
if (cpu_has_rixi) {
uasm_i_drotr(p, even, even, ilog2(_PAGE_GLOBAL));
UASM_i_MTC0(p, even, C0_ENTRYLO0);
uasm_i_drotr(p, odd, odd, ilog2(_PAGE_GLOBAL));
} else {
uasm_i_dsrl_safe(p, even, even, ilog2(_PAGE_GLOBAL));
UASM_i_MTC0(p, even, C0_ENTRYLO0);
uasm_i_dsrl_safe(p, odd, odd, ilog2(_PAGE_GLOBAL));
}
UASM_i_MTC0(p, odd, C0_ENTRYLO1);
if (c0_scratch_reg >= 0) {
UASM_i_MFC0(p, scratch, c0_kscratch(), c0_scratch_reg);
build_tlb_write_entry(p, l, r, tlb_random);
uasm_l_leave(l, *p);
rv.restore_scratch = 1;
} else if (PAGE_SHIFT == 14 || PAGE_SHIFT == 13) {
build_tlb_write_entry(p, l, r, tlb_random);
uasm_l_leave(l, *p);
UASM_i_LW(p, scratch, scratchpad_offset(0), 0);
} else {
UASM_i_LW(p, scratch, scratchpad_offset(0), 0);
build_tlb_write_entry(p, l, r, tlb_random);
uasm_l_leave(l, *p);
rv.restore_scratch = 1;
}
uasm_i_eret(p);
return rv;
}
static void build_r4000_tlb_refill_handler(void)
{
u32 *p = tlb_handler;
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
u32 *f;
unsigned int final_len;
struct mips_huge_tlb_info htlb_info __maybe_unused;
enum vmalloc64_mode vmalloc_mode __maybe_unused;
memset(tlb_handler, 0, sizeof(tlb_handler));
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
memset(final_handler, 0, sizeof(final_handler));
if (IS_ENABLED(CONFIG_64BIT) && (scratch_reg >= 0 || scratchpad_available()) && use_bbit_insns()) {
htlb_info = build_fast_tlb_refill_handler(&p, &l, &r, K0, K1,
scratch_reg);
vmalloc_mode = refill_scratch;
} else {
htlb_info.huge_pte = K0;
htlb_info.restore_scratch = 0;
htlb_info.need_reload_pte = true;
vmalloc_mode = refill_noscratch;
if (bcm1250_m3_war()) {
unsigned int segbits = 44;
uasm_i_dmfc0(&p, K0, C0_BADVADDR);
uasm_i_dmfc0(&p, K1, C0_ENTRYHI);
uasm_i_xor(&p, K0, K0, K1);
uasm_i_dsrl_safe(&p, K1, K0, 62);
uasm_i_dsrl_safe(&p, K0, K0, 12 + 1);
uasm_i_dsll_safe(&p, K0, K0, 64 + 12 + 1 - segbits);
uasm_i_or(&p, K0, K0, K1);
uasm_il_bnez(&p, &r, K0, label_leave);
}
#ifdef CONFIG_64BIT
build_get_pmde64(&p, &l, &r, K0, K1);
#else
build_get_pgde32(&p, K0, K1);
#endif
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
build_is_huge_pte(&p, &r, K0, K1, label_tlb_huge_update);
#endif
build_get_ptep(&p, K0, K1);
build_update_entries(&p, K0, K1);
build_tlb_write_entry(&p, &l, &r, tlb_random);
uasm_l_leave(&l, p);
uasm_i_eret(&p);
}
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
uasm_l_tlb_huge_update(&l, p);
if (htlb_info.need_reload_pte)
UASM_i_LW(&p, htlb_info.huge_pte, 0, K1);
build_huge_update_entries(&p, htlb_info.huge_pte, K1);
build_huge_tlb_write_entry(&p, &l, &r, K0, tlb_random,
htlb_info.restore_scratch);
#endif
#ifdef CONFIG_64BIT
build_get_pgd_vmalloc64(&p, &l, &r, K0, K1, vmalloc_mode);
#endif
switch (boot_cpu_type()) {
default:
if (sizeof(long) == 4) {
case CPU_LOONGSON2:
if ((p - tlb_handler) > 64)
panic("TLB refill handler space exceeded");
f = final_handler;
uasm_copy_handler(relocs, labels, tlb_handler, p, f);
final_len = p - tlb_handler;
break;
} else {
if (((p - tlb_handler) > (MIPS64_REFILL_INSNS * 2) - 1)
|| (((p - tlb_handler) > (MIPS64_REFILL_INSNS * 2) - 3)
&& uasm_insn_has_bdelay(relocs,
tlb_handler + MIPS64_REFILL_INSNS - 3)))
panic("TLB refill handler space exceeded");
f = final_handler + MIPS64_REFILL_INSNS;
if ((p - tlb_handler) <= MIPS64_REFILL_INSNS) {
uasm_copy_handler(relocs, labels, tlb_handler, p, f);
final_len = p - tlb_handler;
} else {
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
const enum label_id ls = label_tlb_huge_update;
#else
const enum label_id ls = label_vmalloc;
#endif
u32 *split;
int ov = 0;
int i;
for (i = 0; i < ARRAY_SIZE(labels) && labels[i].lab != ls; i++)
;
BUG_ON(i == ARRAY_SIZE(labels));
split = labels[i].addr;
if (split > tlb_handler + MIPS64_REFILL_INSNS ||
split < p - MIPS64_REFILL_INSNS)
ov = 1;
if (ov) {
split = tlb_handler + MIPS64_REFILL_INSNS - 2;
if (uasm_insn_has_bdelay(relocs, split - 1))
split--;
}
uasm_copy_handler(relocs, labels, tlb_handler, split, f);
f += split - tlb_handler;
if (ov) {
uasm_l_split(&l, final_handler);
uasm_il_b(&f, &r, label_split);
if (uasm_insn_has_bdelay(relocs, split))
uasm_i_nop(&f);
else {
uasm_copy_handler(relocs, labels,
split, split + 1, f);
uasm_move_labels(labels, f, f + 1, -1);
f++;
split++;
}
}
uasm_copy_handler(relocs, labels, split, p, final_handler);
final_len = (f - (final_handler + MIPS64_REFILL_INSNS)) +
(p - split);
}
}
break;
}
uasm_resolve_relocs(relocs, labels);
pr_debug("Wrote TLB refill handler (%u instructions).\n",
final_len);
memcpy((void *)ebase, final_handler, 0x100);
local_flush_icache_range(ebase, ebase + 0x100);
dump_handler("r4000_tlb_refill", (u32 *)ebase, 64);
}
static void setup_pw(void)
{
unsigned long pgd_i, pgd_w;
#ifndef __PAGETABLE_PMD_FOLDED
unsigned long pmd_i, pmd_w;
#endif
unsigned long pt_i, pt_w;
unsigned long pte_i, pte_w;
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
unsigned long psn;
psn = ilog2(_PAGE_HUGE);
#endif
pgd_i = PGDIR_SHIFT;
#ifndef __PAGETABLE_PMD_FOLDED
pgd_w = PGDIR_SHIFT - PMD_SHIFT + PGD_ORDER;
pmd_i = PMD_SHIFT;
pmd_w = PMD_SHIFT - PAGE_SHIFT;
#else
pgd_w = PGDIR_SHIFT - PAGE_SHIFT + PGD_ORDER;
#endif
pt_i = PAGE_SHIFT;
pt_w = PAGE_SHIFT - 3;
pte_i = ilog2(_PAGE_GLOBAL);
pte_w = 0;
#ifndef __PAGETABLE_PMD_FOLDED
write_c0_pwfield(pgd_i << 24 | pmd_i << 12 | pt_i << 6 | pte_i);
write_c0_pwsize(1 << 30 | pgd_w << 24 | pmd_w << 12 | pt_w << 6 | pte_w);
#else
write_c0_pwfield(pgd_i << 24 | pt_i << 6 | pte_i);
write_c0_pwsize(1 << 30 | pgd_w << 24 | pt_w << 6 | pte_w);
#endif
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
write_c0_pwctl(1 << 6 | psn);
#endif
write_c0_kpgd(swapper_pg_dir);
kscratch_used_mask |= (1 << 7);
}
static void build_loongson3_tlb_refill_handler(void)
{
u32 *p = tlb_handler;
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
memset(tlb_handler, 0, sizeof(tlb_handler));
if (check_for_high_segbits) {
uasm_i_dmfc0(&p, K0, C0_BADVADDR);
uasm_i_dsrl_safe(&p, K1, K0, PGDIR_SHIFT + PGD_ORDER + PAGE_SHIFT - 3);
uasm_il_beqz(&p, &r, K1, label_vmalloc);
uasm_i_nop(&p);
uasm_il_bgez(&p, &r, K0, label_large_segbits_fault);
uasm_i_nop(&p);
uasm_l_vmalloc(&l, p);
}
uasm_i_dmfc0(&p, K1, C0_PGD);
uasm_i_lddir(&p, K0, K1, 3);
#ifndef __PAGETABLE_PMD_FOLDED
uasm_i_lddir(&p, K1, K0, 1);
#endif
uasm_i_ldpte(&p, K1, 0);
uasm_i_ldpte(&p, K1, 1);
uasm_i_tlbwr(&p);
if (PM_DEFAULT_MASK >> 16) {
uasm_i_lui(&p, K0, PM_DEFAULT_MASK >> 16);
uasm_i_ori(&p, K0, K0, PM_DEFAULT_MASK & 0xffff);
uasm_i_mtc0(&p, K0, C0_PAGEMASK);
} else if (PM_DEFAULT_MASK) {
uasm_i_ori(&p, K0, 0, PM_DEFAULT_MASK);
uasm_i_mtc0(&p, K0, C0_PAGEMASK);
} else {
uasm_i_mtc0(&p, 0, C0_PAGEMASK);
}
uasm_i_eret(&p);
if (check_for_high_segbits) {
uasm_l_large_segbits_fault(&l, p);
UASM_i_LA(&p, K1, (unsigned long)tlb_do_page_fault_0);
uasm_i_jr(&p, K1);
uasm_i_nop(&p);
}
uasm_resolve_relocs(relocs, labels);
memcpy((void *)(ebase + 0x80), tlb_handler, 0x80);
local_flush_icache_range(ebase + 0x80, ebase + 0x100);
dump_handler("loongson3_tlb_refill", (u32 *)(ebase + 0x80), 32);
}
static void build_setup_pgd(void)
{
const int a0 = 4;
const int __maybe_unused a1 = 5;
const int __maybe_unused a2 = 6;
u32 *p = tlbmiss_handler_setup_pgd_start;
const int tlbmiss_handler_setup_pgd_size =
tlbmiss_handler_setup_pgd_end - tlbmiss_handler_setup_pgd_start;
#ifndef CONFIG_MIPS_PGD_C0_CONTEXT
long pgdc = (long)pgd_current;
#endif
memset(tlbmiss_handler_setup_pgd, 0, tlbmiss_handler_setup_pgd_size *
sizeof(tlbmiss_handler_setup_pgd[0]));
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
pgd_reg = allocate_kscratch();
#ifdef CONFIG_MIPS_PGD_C0_CONTEXT
if (pgd_reg == -1) {
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
UASM_i_SRA(&p, a1, a0, 29);
UASM_i_ADDIU(&p, a1, a1, 4);
uasm_il_bnez(&p, &r, a1, label_tlbl_goaround1);
uasm_i_nop(&p);
uasm_i_dinsm(&p, a0, 0, 29, 64 - 29);
uasm_l_tlbl_goaround1(&l, p);
UASM_i_SLL(&p, a0, a0, 11);
uasm_i_jr(&p, 31);
UASM_i_MTC0(&p, a0, C0_CONTEXT);
} else {
uasm_i_jr(&p, 31);
if (cpu_has_ldpte)
UASM_i_MTC0(&p, a0, C0_PWBASE);
else
UASM_i_MTC0(&p, a0, c0_kscratch(), pgd_reg);
}
#else
#ifdef CONFIG_SMP
UASM_i_CPUID_MFC0(&p, a1, SMP_CPUID_REG);
UASM_i_SRL_SAFE(&p, a1, a1, SMP_CPUID_PTRSHIFT);
UASM_i_LA_mostly(&p, a2, pgdc);
UASM_i_ADDU(&p, a2, a2, a1);
UASM_i_SW(&p, a0, uasm_rel_lo(pgdc), a2);
#else
UASM_i_LA_mostly(&p, a2, pgdc);
UASM_i_SW(&p, a0, uasm_rel_lo(pgdc), a2);
#endif
uasm_i_jr(&p, 31);
if (pgd_reg != -1)
UASM_i_MTC0(&p, a0, c0_kscratch(), pgd_reg);
else
uasm_i_nop(&p);
#endif
if (p >= tlbmiss_handler_setup_pgd_end)
panic("tlbmiss_handler_setup_pgd space exceeded");
uasm_resolve_relocs(relocs, labels);
pr_debug("Wrote tlbmiss_handler_setup_pgd (%u instructions).\n",
(unsigned int)(p - tlbmiss_handler_setup_pgd));
dump_handler("tlbmiss_handler", tlbmiss_handler_setup_pgd,
tlbmiss_handler_setup_pgd_size);
}
static void
iPTE_LW(u32 **p, unsigned int pte, unsigned int ptr)
{
#ifdef CONFIG_SMP
# ifdef CONFIG_PHYS_ADDR_T_64BIT
if (cpu_has_64bits)
uasm_i_lld(p, pte, 0, ptr);
else
# endif
UASM_i_LL(p, pte, 0, ptr);
#else
# ifdef CONFIG_PHYS_ADDR_T_64BIT
if (cpu_has_64bits)
uasm_i_ld(p, pte, 0, ptr);
else
# endif
UASM_i_LW(p, pte, 0, ptr);
#endif
}
static void
iPTE_SW(u32 **p, struct uasm_reloc **r, unsigned int pte, unsigned int ptr,
unsigned int mode, unsigned int scratch)
{
unsigned int hwmode = mode & (_PAGE_VALID | _PAGE_DIRTY);
unsigned int swmode = mode & ~hwmode;
if (IS_ENABLED(CONFIG_XPA) && !cpu_has_64bits) {
uasm_i_lui(p, scratch, swmode >> 16);
uasm_i_or(p, pte, pte, scratch);
BUG_ON(swmode & 0xffff);
} else {
uasm_i_ori(p, pte, pte, mode);
}
#ifdef CONFIG_SMP
# ifdef CONFIG_PHYS_ADDR_T_64BIT
if (cpu_has_64bits)
uasm_i_scd(p, pte, 0, ptr);
else
# endif
UASM_i_SC(p, pte, 0, ptr);
if (r10000_llsc_war())
uasm_il_beqzl(p, r, pte, label_smp_pgtable_change);
else
uasm_il_beqz(p, r, pte, label_smp_pgtable_change);
# ifdef CONFIG_PHYS_ADDR_T_64BIT
if (!cpu_has_64bits) {
uasm_i_ll(p, pte, sizeof(pte_t) / 2, ptr);
uasm_i_ori(p, pte, pte, hwmode);
BUG_ON(hwmode & ~0xffff);
uasm_i_sc(p, pte, sizeof(pte_t) / 2, ptr);
uasm_il_beqz(p, r, pte, label_smp_pgtable_change);
uasm_i_lw(p, pte, 0, ptr);
} else
uasm_i_nop(p);
# else
uasm_i_nop(p);
# endif
#else
# ifdef CONFIG_PHYS_ADDR_T_64BIT
if (cpu_has_64bits)
uasm_i_sd(p, pte, 0, ptr);
else
# endif
UASM_i_SW(p, pte, 0, ptr);
# ifdef CONFIG_PHYS_ADDR_T_64BIT
if (!cpu_has_64bits) {
uasm_i_lw(p, pte, sizeof(pte_t) / 2, ptr);
uasm_i_ori(p, pte, pte, hwmode);
BUG_ON(hwmode & ~0xffff);
uasm_i_sw(p, pte, sizeof(pte_t) / 2, ptr);
uasm_i_lw(p, pte, 0, ptr);
}
# endif
#endif
}
static void
build_pte_present(u32 **p, struct uasm_reloc **r,
int pte, int ptr, int scratch, enum label_id lid)
{
int t = scratch >= 0 ? scratch : pte;
int cur = pte;
if (cpu_has_rixi) {
if (use_bbit_insns()) {
uasm_il_bbit0(p, r, pte, ilog2(_PAGE_PRESENT), lid);
uasm_i_nop(p);
} else {
if (_PAGE_PRESENT_SHIFT) {
uasm_i_srl(p, t, cur, _PAGE_PRESENT_SHIFT);
cur = t;
}
uasm_i_andi(p, t, cur, 1);
uasm_il_beqz(p, r, t, lid);
if (pte == t)
iPTE_LW(p, pte, ptr);
}
} else {
if (_PAGE_PRESENT_SHIFT) {
uasm_i_srl(p, t, cur, _PAGE_PRESENT_SHIFT);
cur = t;
}
uasm_i_andi(p, t, cur,
(_PAGE_PRESENT | _PAGE_NO_READ) >> _PAGE_PRESENT_SHIFT);
uasm_i_xori(p, t, t, _PAGE_PRESENT >> _PAGE_PRESENT_SHIFT);
uasm_il_bnez(p, r, t, lid);
if (pte == t)
iPTE_LW(p, pte, ptr);
}
}
static void
build_make_valid(u32 **p, struct uasm_reloc **r, unsigned int pte,
unsigned int ptr, unsigned int scratch)
{
unsigned int mode = _PAGE_VALID | _PAGE_ACCESSED;
iPTE_SW(p, r, pte, ptr, mode, scratch);
}
static void
build_pte_writable(u32 **p, struct uasm_reloc **r,
unsigned int pte, unsigned int ptr, int scratch,
enum label_id lid)
{
int t = scratch >= 0 ? scratch : pte;
int cur = pte;
if (_PAGE_PRESENT_SHIFT) {
uasm_i_srl(p, t, cur, _PAGE_PRESENT_SHIFT);
cur = t;
}
uasm_i_andi(p, t, cur,
(_PAGE_PRESENT | _PAGE_WRITE) >> _PAGE_PRESENT_SHIFT);
uasm_i_xori(p, t, t,
(_PAGE_PRESENT | _PAGE_WRITE) >> _PAGE_PRESENT_SHIFT);
uasm_il_bnez(p, r, t, lid);
if (pte == t)
iPTE_LW(p, pte, ptr);
else
uasm_i_nop(p);
}
static void
build_make_write(u32 **p, struct uasm_reloc **r, unsigned int pte,
unsigned int ptr, unsigned int scratch)
{
unsigned int mode = (_PAGE_ACCESSED | _PAGE_MODIFIED | _PAGE_VALID
| _PAGE_DIRTY);
iPTE_SW(p, r, pte, ptr, mode, scratch);
}
static void
build_pte_modifiable(u32 **p, struct uasm_reloc **r,
unsigned int pte, unsigned int ptr, int scratch,
enum label_id lid)
{
if (use_bbit_insns()) {
uasm_il_bbit0(p, r, pte, ilog2(_PAGE_WRITE), lid);
uasm_i_nop(p);
} else {
int t = scratch >= 0 ? scratch : pte;
uasm_i_srl(p, t, pte, _PAGE_WRITE_SHIFT);
uasm_i_andi(p, t, t, 1);
uasm_il_beqz(p, r, t, lid);
if (pte == t)
iPTE_LW(p, pte, ptr);
}
}
static void
build_r3000_pte_reload_tlbwi(u32 **p, unsigned int pte, unsigned int tmp)
{
uasm_i_mtc0(p, pte, C0_ENTRYLO0);
uasm_i_mfc0(p, tmp, C0_EPC);
uasm_i_tlbwi(p);
uasm_i_jr(p, tmp);
uasm_i_rfe(p);
}
static void
build_r3000_tlb_reload_write(u32 **p, struct uasm_label **l,
struct uasm_reloc **r, unsigned int pte,
unsigned int tmp)
{
uasm_i_mfc0(p, tmp, C0_INDEX);
uasm_i_mtc0(p, pte, C0_ENTRYLO0);
uasm_il_bltz(p, r, tmp, label_r3000_write_probe_fail);
uasm_i_mfc0(p, tmp, C0_EPC);
uasm_i_tlbwi(p);
uasm_i_jr(p, tmp);
uasm_i_rfe(p);
uasm_l_r3000_write_probe_fail(l, *p);
uasm_i_tlbwr(p);
uasm_i_jr(p, tmp);
uasm_i_rfe(p);
}
static void
build_r3000_tlbchange_handler_head(u32 **p, unsigned int pte,
unsigned int ptr)
{
long pgdc = (long)pgd_current;
uasm_i_mfc0(p, pte, C0_BADVADDR);
uasm_i_lui(p, ptr, uasm_rel_hi(pgdc));
uasm_i_lw(p, ptr, uasm_rel_lo(pgdc), ptr);
uasm_i_srl(p, pte, pte, 22);
uasm_i_sll(p, pte, pte, 2);
uasm_i_addu(p, ptr, ptr, pte);
uasm_i_mfc0(p, pte, C0_CONTEXT);
uasm_i_lw(p, ptr, 0, ptr);
uasm_i_andi(p, pte, pte, 0xffc);
uasm_i_addu(p, ptr, ptr, pte);
uasm_i_lw(p, pte, 0, ptr);
uasm_i_tlbp(p);
}
static void build_r3000_tlb_load_handler(void)
{
u32 *p = handle_tlbl;
const int handle_tlbl_size = handle_tlbl_end - handle_tlbl;
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
memset(handle_tlbl, 0, handle_tlbl_size * sizeof(handle_tlbl[0]));
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
build_r3000_tlbchange_handler_head(&p, K0, K1);
build_pte_present(&p, &r, K0, K1, -1, label_nopage_tlbl);
uasm_i_nop(&p);
build_make_valid(&p, &r, K0, K1, -1);
build_r3000_tlb_reload_write(&p, &l, &r, K0, K1);
uasm_l_nopage_tlbl(&l, p);
uasm_i_j(&p, (unsigned long)tlb_do_page_fault_0 & 0x0fffffff);
uasm_i_nop(&p);
if (p >= handle_tlbl_end)
panic("TLB load handler fastpath space exceeded");
uasm_resolve_relocs(relocs, labels);
pr_debug("Wrote TLB load handler fastpath (%u instructions).\n",
(unsigned int)(p - handle_tlbl));
dump_handler("r3000_tlb_load", handle_tlbl, handle_tlbl_size);
}
static void build_r3000_tlb_store_handler(void)
{
u32 *p = handle_tlbs;
const int handle_tlbs_size = handle_tlbs_end - handle_tlbs;
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
memset(handle_tlbs, 0, handle_tlbs_size * sizeof(handle_tlbs[0]));
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
build_r3000_tlbchange_handler_head(&p, K0, K1);
build_pte_writable(&p, &r, K0, K1, -1, label_nopage_tlbs);
uasm_i_nop(&p);
build_make_write(&p, &r, K0, K1, -1);
build_r3000_tlb_reload_write(&p, &l, &r, K0, K1);
uasm_l_nopage_tlbs(&l, p);
uasm_i_j(&p, (unsigned long)tlb_do_page_fault_1 & 0x0fffffff);
uasm_i_nop(&p);
if (p >= handle_tlbs_end)
panic("TLB store handler fastpath space exceeded");
uasm_resolve_relocs(relocs, labels);
pr_debug("Wrote TLB store handler fastpath (%u instructions).\n",
(unsigned int)(p - handle_tlbs));
dump_handler("r3000_tlb_store", handle_tlbs, handle_tlbs_size);
}
static void build_r3000_tlb_modify_handler(void)
{
u32 *p = handle_tlbm;
const int handle_tlbm_size = handle_tlbm_end - handle_tlbm;
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
memset(handle_tlbm, 0, handle_tlbm_size * sizeof(handle_tlbm[0]));
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
build_r3000_tlbchange_handler_head(&p, K0, K1);
build_pte_modifiable(&p, &r, K0, K1, -1, label_nopage_tlbm);
uasm_i_nop(&p);
build_make_write(&p, &r, K0, K1, -1);
build_r3000_pte_reload_tlbwi(&p, K0, K1);
uasm_l_nopage_tlbm(&l, p);
uasm_i_j(&p, (unsigned long)tlb_do_page_fault_1 & 0x0fffffff);
uasm_i_nop(&p);
if (p >= handle_tlbm_end)
panic("TLB modify handler fastpath space exceeded");
uasm_resolve_relocs(relocs, labels);
pr_debug("Wrote TLB modify handler fastpath (%u instructions).\n",
(unsigned int)(p - handle_tlbm));
dump_handler("r3000_tlb_modify", handle_tlbm, handle_tlbm_size);
}
static struct work_registers
build_r4000_tlbchange_handler_head(u32 **p, struct uasm_label **l,
struct uasm_reloc **r)
{
struct work_registers wr = build_get_work_registers(p);
#ifdef CONFIG_64BIT
build_get_pmde64(p, l, r, wr.r1, wr.r2);
#else
build_get_pgde32(p, wr.r1, wr.r2);
#endif
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
build_is_huge_pte(p, r, wr.r1, wr.r2, label_tlb_huge_update);
#endif
UASM_i_MFC0(p, wr.r1, C0_BADVADDR);
UASM_i_LW(p, wr.r2, 0, wr.r2);
UASM_i_SRL(p, wr.r1, wr.r1, PAGE_SHIFT + PTE_ORDER - PTE_T_LOG2);
uasm_i_andi(p, wr.r1, wr.r1, (PTRS_PER_PTE - 1) << PTE_T_LOG2);
UASM_i_ADDU(p, wr.r2, wr.r2, wr.r1);
#ifdef CONFIG_SMP
uasm_l_smp_pgtable_change(l, *p);
#endif
iPTE_LW(p, wr.r1, wr.r2);
if (!m4kc_tlbp_war()) {
build_tlb_probe_entry(p);
if (cpu_has_htw) {
uasm_i_ehb(p);
uasm_i_mfc0(p, wr.r3, C0_INDEX);
uasm_il_bltz(p, r, wr.r3, label_leave);
uasm_i_nop(p);
}
}
return wr;
}
static void
build_r4000_tlbchange_handler_tail(u32 **p, struct uasm_label **l,
struct uasm_reloc **r, unsigned int tmp,
unsigned int ptr)
{
uasm_i_ori(p, ptr, ptr, sizeof(pte_t));
uasm_i_xori(p, ptr, ptr, sizeof(pte_t));
build_update_entries(p, tmp, ptr);
build_tlb_write_entry(p, l, r, tlb_indexed);
uasm_l_leave(l, *p);
build_restore_work_registers(p);
uasm_i_eret(p);
#ifdef CONFIG_64BIT
build_get_pgd_vmalloc64(p, l, r, tmp, ptr, not_refill);
#endif
}
static void build_r4000_tlb_load_handler(void)
{
u32 *p = (u32 *)msk_isa16_mode((ulong)handle_tlbl);
const int handle_tlbl_size = handle_tlbl_end - handle_tlbl;
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
struct work_registers wr;
memset(handle_tlbl, 0, handle_tlbl_size * sizeof(handle_tlbl[0]));
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
if (bcm1250_m3_war()) {
unsigned int segbits = 44;
uasm_i_dmfc0(&p, K0, C0_BADVADDR);
uasm_i_dmfc0(&p, K1, C0_ENTRYHI);
uasm_i_xor(&p, K0, K0, K1);
uasm_i_dsrl_safe(&p, K1, K0, 62);
uasm_i_dsrl_safe(&p, K0, K0, 12 + 1);
uasm_i_dsll_safe(&p, K0, K0, 64 + 12 + 1 - segbits);
uasm_i_or(&p, K0, K0, K1);
uasm_il_bnez(&p, &r, K0, label_leave);
}
wr = build_r4000_tlbchange_handler_head(&p, &l, &r);
build_pte_present(&p, &r, wr.r1, wr.r2, wr.r3, label_nopage_tlbl);
if (m4kc_tlbp_war())
build_tlb_probe_entry(&p);
if (cpu_has_rixi && !cpu_has_rixiex) {
if (use_bbit_insns()) {
uasm_il_bbit0(&p, &r, wr.r1, ilog2(_PAGE_VALID),
label_tlbl_goaround1);
} else {
uasm_i_andi(&p, wr.r3, wr.r1, _PAGE_VALID);
uasm_il_beqz(&p, &r, wr.r3, label_tlbl_goaround1);
}
uasm_i_nop(&p);
uasm_i_tlbr(&p);
switch (current_cpu_type()) {
default:
if (cpu_has_mips_r2_exec_hazard) {
uasm_i_ehb(&p);
case CPU_CAVIUM_OCTEON:
case CPU_CAVIUM_OCTEON_PLUS:
case CPU_CAVIUM_OCTEON2:
break;
}
}
if (use_bbit_insns()) {
uasm_i_bbit0(&p, wr.r2, ilog2(sizeof(pte_t)), 8);
} else {
uasm_i_andi(&p, wr.r3, wr.r2, sizeof(pte_t));
uasm_i_beqz(&p, wr.r3, 8);
}
UASM_i_MFC0(&p, wr.r3, C0_ENTRYLO0);
UASM_i_MFC0(&p, wr.r3, C0_ENTRYLO1);
if (use_bbit_insns()) {
uasm_il_bbit1(&p, &r, wr.r3, 1, label_nopage_tlbl);
uasm_i_nop(&p);
uasm_l_tlbl_goaround1(&l, p);
} else {
uasm_i_andi(&p, wr.r3, wr.r3, 2);
uasm_il_bnez(&p, &r, wr.r3, label_nopage_tlbl);
uasm_i_nop(&p);
}
uasm_l_tlbl_goaround1(&l, p);
}
build_make_valid(&p, &r, wr.r1, wr.r2, wr.r3);
build_r4000_tlbchange_handler_tail(&p, &l, &r, wr.r1, wr.r2);
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
uasm_l_tlb_huge_update(&l, p);
iPTE_LW(&p, wr.r1, wr.r2);
build_pte_present(&p, &r, wr.r1, wr.r2, wr.r3, label_nopage_tlbl);
build_tlb_probe_entry(&p);
if (cpu_has_rixi && !cpu_has_rixiex) {
if (use_bbit_insns()) {
uasm_il_bbit0(&p, &r, wr.r1, ilog2(_PAGE_VALID),
label_tlbl_goaround2);
} else {
uasm_i_andi(&p, wr.r3, wr.r1, _PAGE_VALID);
uasm_il_beqz(&p, &r, wr.r3, label_tlbl_goaround2);
}
uasm_i_nop(&p);
uasm_i_tlbr(&p);
switch (current_cpu_type()) {
default:
if (cpu_has_mips_r2_exec_hazard) {
uasm_i_ehb(&p);
case CPU_CAVIUM_OCTEON:
case CPU_CAVIUM_OCTEON_PLUS:
case CPU_CAVIUM_OCTEON2:
break;
}
}
if (use_bbit_insns()) {
uasm_i_bbit0(&p, wr.r2, ilog2(sizeof(pte_t)), 8);
} else {
uasm_i_andi(&p, wr.r3, wr.r2, sizeof(pte_t));
uasm_i_beqz(&p, wr.r3, 8);
}
UASM_i_MFC0(&p, wr.r3, C0_ENTRYLO0);
UASM_i_MFC0(&p, wr.r3, C0_ENTRYLO1);
if (use_bbit_insns()) {
uasm_il_bbit0(&p, &r, wr.r3, 1, label_tlbl_goaround2);
} else {
uasm_i_andi(&p, wr.r3, wr.r3, 2);
uasm_il_beqz(&p, &r, wr.r3, label_tlbl_goaround2);
}
if (PM_DEFAULT_MASK == 0)
uasm_i_nop(&p);
build_restore_pagemask(&p, &r, wr.r3, label_nopage_tlbl, 0);
uasm_l_tlbl_goaround2(&l, p);
}
uasm_i_ori(&p, wr.r1, wr.r1, (_PAGE_ACCESSED | _PAGE_VALID));
build_huge_handler_tail(&p, &r, &l, wr.r1, wr.r2, 1);
#endif
uasm_l_nopage_tlbl(&l, p);
build_restore_work_registers(&p);
#ifdef CONFIG_CPU_MICROMIPS
if ((unsigned long)tlb_do_page_fault_0 & 1) {
uasm_i_lui(&p, K0, uasm_rel_hi((long)tlb_do_page_fault_0));
uasm_i_addiu(&p, K0, K0, uasm_rel_lo((long)tlb_do_page_fault_0));
uasm_i_jr(&p, K0);
} else
#endif
uasm_i_j(&p, (unsigned long)tlb_do_page_fault_0 & 0x0fffffff);
uasm_i_nop(&p);
if (p >= handle_tlbl_end)
panic("TLB load handler fastpath space exceeded");
uasm_resolve_relocs(relocs, labels);
pr_debug("Wrote TLB load handler fastpath (%u instructions).\n",
(unsigned int)(p - handle_tlbl));
dump_handler("r4000_tlb_load", handle_tlbl, handle_tlbl_size);
}
static void build_r4000_tlb_store_handler(void)
{
u32 *p = (u32 *)msk_isa16_mode((ulong)handle_tlbs);
const int handle_tlbs_size = handle_tlbs_end - handle_tlbs;
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
struct work_registers wr;
memset(handle_tlbs, 0, handle_tlbs_size * sizeof(handle_tlbs[0]));
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
wr = build_r4000_tlbchange_handler_head(&p, &l, &r);
build_pte_writable(&p, &r, wr.r1, wr.r2, wr.r3, label_nopage_tlbs);
if (m4kc_tlbp_war())
build_tlb_probe_entry(&p);
build_make_write(&p, &r, wr.r1, wr.r2, wr.r3);
build_r4000_tlbchange_handler_tail(&p, &l, &r, wr.r1, wr.r2);
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
uasm_l_tlb_huge_update(&l, p);
iPTE_LW(&p, wr.r1, wr.r2);
build_pte_writable(&p, &r, wr.r1, wr.r2, wr.r3, label_nopage_tlbs);
build_tlb_probe_entry(&p);
uasm_i_ori(&p, wr.r1, wr.r1,
_PAGE_ACCESSED | _PAGE_MODIFIED | _PAGE_VALID | _PAGE_DIRTY);
build_huge_handler_tail(&p, &r, &l, wr.r1, wr.r2, 1);
#endif
uasm_l_nopage_tlbs(&l, p);
build_restore_work_registers(&p);
#ifdef CONFIG_CPU_MICROMIPS
if ((unsigned long)tlb_do_page_fault_1 & 1) {
uasm_i_lui(&p, K0, uasm_rel_hi((long)tlb_do_page_fault_1));
uasm_i_addiu(&p, K0, K0, uasm_rel_lo((long)tlb_do_page_fault_1));
uasm_i_jr(&p, K0);
} else
#endif
uasm_i_j(&p, (unsigned long)tlb_do_page_fault_1 & 0x0fffffff);
uasm_i_nop(&p);
if (p >= handle_tlbs_end)
panic("TLB store handler fastpath space exceeded");
uasm_resolve_relocs(relocs, labels);
pr_debug("Wrote TLB store handler fastpath (%u instructions).\n",
(unsigned int)(p - handle_tlbs));
dump_handler("r4000_tlb_store", handle_tlbs, handle_tlbs_size);
}
static void build_r4000_tlb_modify_handler(void)
{
u32 *p = (u32 *)msk_isa16_mode((ulong)handle_tlbm);
const int handle_tlbm_size = handle_tlbm_end - handle_tlbm;
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
struct work_registers wr;
memset(handle_tlbm, 0, handle_tlbm_size * sizeof(handle_tlbm[0]));
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
wr = build_r4000_tlbchange_handler_head(&p, &l, &r);
build_pte_modifiable(&p, &r, wr.r1, wr.r2, wr.r3, label_nopage_tlbm);
if (m4kc_tlbp_war())
build_tlb_probe_entry(&p);
build_make_write(&p, &r, wr.r1, wr.r2, wr.r3);
build_r4000_tlbchange_handler_tail(&p, &l, &r, wr.r1, wr.r2);
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
uasm_l_tlb_huge_update(&l, p);
iPTE_LW(&p, wr.r1, wr.r2);
build_pte_modifiable(&p, &r, wr.r1, wr.r2, wr.r3, label_nopage_tlbm);
build_tlb_probe_entry(&p);
uasm_i_ori(&p, wr.r1, wr.r1,
_PAGE_ACCESSED | _PAGE_MODIFIED | _PAGE_VALID | _PAGE_DIRTY);
build_huge_handler_tail(&p, &r, &l, wr.r1, wr.r2, 0);
#endif
uasm_l_nopage_tlbm(&l, p);
build_restore_work_registers(&p);
#ifdef CONFIG_CPU_MICROMIPS
if ((unsigned long)tlb_do_page_fault_1 & 1) {
uasm_i_lui(&p, K0, uasm_rel_hi((long)tlb_do_page_fault_1));
uasm_i_addiu(&p, K0, K0, uasm_rel_lo((long)tlb_do_page_fault_1));
uasm_i_jr(&p, K0);
} else
#endif
uasm_i_j(&p, (unsigned long)tlb_do_page_fault_1 & 0x0fffffff);
uasm_i_nop(&p);
if (p >= handle_tlbm_end)
panic("TLB modify handler fastpath space exceeded");
uasm_resolve_relocs(relocs, labels);
pr_debug("Wrote TLB modify handler fastpath (%u instructions).\n",
(unsigned int)(p - handle_tlbm));
dump_handler("r4000_tlb_modify", handle_tlbm, handle_tlbm_size);
}
static void flush_tlb_handlers(void)
{
local_flush_icache_range((unsigned long)handle_tlbl,
(unsigned long)handle_tlbl_end);
local_flush_icache_range((unsigned long)handle_tlbs,
(unsigned long)handle_tlbs_end);
local_flush_icache_range((unsigned long)handle_tlbm,
(unsigned long)handle_tlbm_end);
local_flush_icache_range((unsigned long)tlbmiss_handler_setup_pgd,
(unsigned long)tlbmiss_handler_setup_pgd_end);
}
static void print_htw_config(void)
{
unsigned long config;
unsigned int pwctl;
const int field = 2 * sizeof(unsigned long);
config = read_c0_pwfield();
pr_debug("PWField (0x%0*lx): GDI: 0x%02lx UDI: 0x%02lx MDI: 0x%02lx PTI: 0x%02lx PTEI: 0x%02lx\n",
field, config,
(config & MIPS_PWFIELD_GDI_MASK) >> MIPS_PWFIELD_GDI_SHIFT,
(config & MIPS_PWFIELD_UDI_MASK) >> MIPS_PWFIELD_UDI_SHIFT,
(config & MIPS_PWFIELD_MDI_MASK) >> MIPS_PWFIELD_MDI_SHIFT,
(config & MIPS_PWFIELD_PTI_MASK) >> MIPS_PWFIELD_PTI_SHIFT,
(config & MIPS_PWFIELD_PTEI_MASK) >> MIPS_PWFIELD_PTEI_SHIFT);
config = read_c0_pwsize();
pr_debug("PWSize (0x%0*lx): PS: 0x%lx GDW: 0x%02lx UDW: 0x%02lx MDW: 0x%02lx PTW: 0x%02lx PTEW: 0x%02lx\n",
field, config,
(config & MIPS_PWSIZE_PS_MASK) >> MIPS_PWSIZE_PS_SHIFT,
(config & MIPS_PWSIZE_GDW_MASK) >> MIPS_PWSIZE_GDW_SHIFT,
(config & MIPS_PWSIZE_UDW_MASK) >> MIPS_PWSIZE_UDW_SHIFT,
(config & MIPS_PWSIZE_MDW_MASK) >> MIPS_PWSIZE_MDW_SHIFT,
(config & MIPS_PWSIZE_PTW_MASK) >> MIPS_PWSIZE_PTW_SHIFT,
(config & MIPS_PWSIZE_PTEW_MASK) >> MIPS_PWSIZE_PTEW_SHIFT);
pwctl = read_c0_pwctl();
pr_debug("PWCtl (0x%x): PWEn: 0x%x XK: 0x%x XS: 0x%x XU: 0x%x DPH: 0x%x HugePg: 0x%x Psn: 0x%x\n",
pwctl,
(pwctl & MIPS_PWCTL_PWEN_MASK) >> MIPS_PWCTL_PWEN_SHIFT,
(pwctl & MIPS_PWCTL_XK_MASK) >> MIPS_PWCTL_XK_SHIFT,
(pwctl & MIPS_PWCTL_XS_MASK) >> MIPS_PWCTL_XS_SHIFT,
(pwctl & MIPS_PWCTL_XU_MASK) >> MIPS_PWCTL_XU_SHIFT,
(pwctl & MIPS_PWCTL_DPH_MASK) >> MIPS_PWCTL_DPH_SHIFT,
(pwctl & MIPS_PWCTL_HUGEPG_MASK) >> MIPS_PWCTL_HUGEPG_SHIFT,
(pwctl & MIPS_PWCTL_PSN_MASK) >> MIPS_PWCTL_PSN_SHIFT);
}
static void config_htw_params(void)
{
unsigned long pwfield, pwsize, ptei;
unsigned int config;
pwfield = read_c0_pwfield();
pwfield &= ~MIPS_PWFIELD_GDI_MASK;
pwfield |= PGDIR_SHIFT << MIPS_PWFIELD_GDI_SHIFT;
pwfield &= ~MIPS_PWFIELD_PTI_MASK;
pwfield |= PAGE_SHIFT << MIPS_PWFIELD_PTI_SHIFT;
if (CONFIG_PGTABLE_LEVELS >= 3) {
pwfield &= ~MIPS_PWFIELD_MDI_MASK;
pwfield |= PMD_SHIFT << MIPS_PWFIELD_MDI_SHIFT;
}
ptei = _PAGE_GLOBAL_SHIFT << MIPS_PWFIELD_PTEI_SHIFT;
pwfield |= ptei;
write_c0_pwfield(pwfield);
back_to_back_c0_hazard();
pwfield = read_c0_pwfield();
if (((pwfield & MIPS_PWFIELD_PTEI_MASK) << MIPS_PWFIELD_PTEI_SHIFT)
!= ptei) {
pr_warn("Unsupported PTEI field value: 0x%lx. HTW will not be enabled",
ptei);
current_cpu_data.options &= ~MIPS_CPU_HTW;
return;
}
pwsize = ilog2(PTRS_PER_PGD) << MIPS_PWSIZE_GDW_SHIFT;
pwsize |= ilog2(PTRS_PER_PTE) << MIPS_PWSIZE_PTW_SHIFT;
if (CONFIG_PGTABLE_LEVELS >= 3)
pwsize |= ilog2(PTRS_PER_PMD) << MIPS_PWSIZE_MDW_SHIFT;
if (IS_ENABLED(CONFIG_64BIT))
pwsize |= MIPS_PWSIZE_PS_MASK;
pwsize |= ((PTE_T_LOG2 - PGD_T_LOG2) << MIPS_PWSIZE_PTEW_SHIFT)
& MIPS_PWSIZE_PTEW_MASK;
write_c0_pwsize(pwsize);
back_to_back_c0_hazard();
config = 1 << MIPS_PWCTL_PWEN_SHIFT;
if (IS_ENABLED(CONFIG_64BIT))
config |= MIPS_PWCTL_XU_MASK;
write_c0_pwctl(config);
pr_info("Hardware Page Table Walker enabled\n");
print_htw_config();
}
static void config_xpa_params(void)
{
#ifdef CONFIG_XPA
unsigned int pagegrain;
if (mips_xpa_disabled) {
pr_info("Extended Physical Addressing (XPA) disabled\n");
return;
}
pagegrain = read_c0_pagegrain();
write_c0_pagegrain(pagegrain | PG_ELPA);
back_to_back_c0_hazard();
pagegrain = read_c0_pagegrain();
if (pagegrain & PG_ELPA)
pr_info("Extended Physical Addressing (XPA) enabled\n");
else
panic("Extended Physical Addressing (XPA) disabled");
#endif
}
static void check_pabits(void)
{
unsigned long entry;
unsigned pabits, fillbits;
if (!cpu_has_rixi || !_PAGE_NO_EXEC) {
return;
}
write_c0_entrylo0(~0ul);
back_to_back_c0_hazard();
entry = read_c0_entrylo0();
entry &= ~((1 << MIPS_ENTRYLO_PFN_SHIFT) - 1);
entry &= ~(MIPS_ENTRYLO_RI | MIPS_ENTRYLO_XI);
pabits = fls_long(entry) + 6;
fillbits = max_t(int, (int)BITS_PER_LONG - pabits, 0);
fillbits -= min_t(unsigned, fillbits, 2);
if (fillbits >= ilog2(_PAGE_NO_EXEC))
fill_includes_sw_bits = true;
pr_debug("Entry* registers contain %u fill bits\n", fillbits);
}
void build_tlb_refill_handler(void)
{
static int run_once = 0;
if (IS_ENABLED(CONFIG_XPA) && !cpu_has_rixi)
panic("Kernels supporting XPA currently require CPUs with RIXI");
output_pgtable_bits_defines();
check_pabits();
#ifdef CONFIG_64BIT
check_for_high_segbits = current_cpu_data.vmbits > (PGDIR_SHIFT + PGD_ORDER + PAGE_SHIFT - 3);
#endif
switch (current_cpu_type()) {
case CPU_R2000:
case CPU_R3000:
case CPU_R3000A:
case CPU_R3081E:
case CPU_TX3912:
case CPU_TX3922:
case CPU_TX3927:
#ifndef CONFIG_MIPS_PGD_C0_CONTEXT
if (cpu_has_local_ebase)
build_r3000_tlb_refill_handler();
if (!run_once) {
if (!cpu_has_local_ebase)
build_r3000_tlb_refill_handler();
build_setup_pgd();
build_r3000_tlb_load_handler();
build_r3000_tlb_store_handler();
build_r3000_tlb_modify_handler();
flush_tlb_handlers();
run_once++;
}
#else
panic("No R3000 TLB refill handler");
#endif
break;
case CPU_R6000:
case CPU_R6000A:
panic("No R6000 TLB refill handler yet");
break;
case CPU_R8000:
panic("No R8000 TLB refill handler yet");
break;
default:
if (cpu_has_ldpte)
setup_pw();
if (!run_once) {
scratch_reg = allocate_kscratch();
build_setup_pgd();
build_r4000_tlb_load_handler();
build_r4000_tlb_store_handler();
build_r4000_tlb_modify_handler();
if (cpu_has_ldpte)
build_loongson3_tlb_refill_handler();
else if (!cpu_has_local_ebase)
build_r4000_tlb_refill_handler();
flush_tlb_handlers();
run_once++;
}
if (cpu_has_local_ebase)
build_r4000_tlb_refill_handler();
if (cpu_has_xpa)
config_xpa_params();
if (cpu_has_htw)
config_htw_params();
}
}
