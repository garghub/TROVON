static scom_map_t get_scom(int cpu, struct device_node *np, int *first_thread)
{
scom_map_t scom = per_cpu(scom_ptrs, cpu);
int tcpu;
if (scom_map_ok(scom)) {
*first_thread = 0;
return scom;
}
*first_thread = 1;
scom = scom_map_device(np, 0);
for (tcpu = cpu_first_thread_sibling(cpu);
tcpu <= cpu_last_thread_sibling(cpu); tcpu++)
per_cpu(scom_ptrs, tcpu) = scom;
if (cpu_first_thread_sibling(cpu) == 0)
*first_thread = 0;
return scom;
}
static int a2_scom_ram(scom_map_t scom, int thread, u32 insn, int extmask)
{
u64 cmd, mask, val;
int n = 0;
cmd = ((u64)insn << 32) | (((u64)extmask & 0xf) << 28)
| ((u64)thread << 17) | SCOM_RAMC_ENABLE | SCOM_RAMC_EXECUTE;
mask = SCOM_RAMC_DONE | SCOM_RAMC_INTERRUPT | SCOM_RAMC_ERROR;
scom_write(scom, SCOM_RAMIC, cmd);
for (;;) {
if (scom_read(scom, SCOM_RAMC, &val) != 0) {
pr_err("SCOM error on instruction 0x%08x, thread %d\n",
insn, thread);
return -1;
}
if (val & mask)
break;
pr_devel("Waiting on RAMC = 0x%llx\n", val);
if (++n == 3) {
pr_err("RAMC timeout on instruction 0x%08x, thread %d\n",
insn, thread);
return -1;
}
}
if (val & SCOM_RAMC_INTERRUPT) {
pr_err("RAMC interrupt on instruction 0x%08x, thread %d\n",
insn, thread);
return -SCOM_RAMC_INTERRUPT;
}
if (val & SCOM_RAMC_ERROR) {
pr_err("RAMC error on instruction 0x%08x, thread %d\n",
insn, thread);
return -SCOM_RAMC_ERROR;
}
return 0;
}
static int a2_scom_getgpr(scom_map_t scom, int thread, int gpr, int alt,
u64 *out_gpr)
{
int rc;
u32 insn = 0x7c000378 | (gpr << 21) | (gpr << 16) | (gpr << 11);
rc = a2_scom_ram(scom, thread, insn, alt ? 0xf : 0x0);
if (rc)
return rc;
return scom_read(scom, SCOM_RAMD, out_gpr);
}
static int a2_scom_getspr(scom_map_t scom, int thread, int spr, u64 *out_spr)
{
int rc, sprhi, sprlo;
u32 insn;
sprhi = spr >> 5;
sprlo = spr & 0x1f;
insn = 0x7c2002a6 | (sprlo << 16) | (sprhi << 11);
if (spr == 0x0ff0)
insn = 0x7c2000a6;
rc = a2_scom_ram(scom, thread, insn, 0xf);
if (rc)
return rc;
return a2_scom_getgpr(scom, thread, 1, 1, out_spr);
}
static int a2_scom_setgpr(scom_map_t scom, int thread, int gpr,
int alt, u64 val)
{
u32 lis = 0x3c000000 | (gpr << 21);
u32 li = 0x38000000 | (gpr << 21);
u32 oris = 0x64000000 | (gpr << 21) | (gpr << 16);
u32 ori = 0x60000000 | (gpr << 21) | (gpr << 16);
u32 rldicr32 = 0x780007c6 | (gpr << 21) | (gpr << 16);
u32 highest = val >> 48;
u32 higher = (val >> 32) & 0xffff;
u32 high = (val >> 16) & 0xffff;
u32 low = val & 0xffff;
int lext = alt ? 0x8 : 0x0;
int oext = alt ? 0xf : 0x0;
int rc = 0;
if (highest)
rc |= a2_scom_ram(scom, thread, lis | highest, lext);
if (higher) {
if (highest)
rc |= a2_scom_ram(scom, thread, oris | higher, oext);
else
rc |= a2_scom_ram(scom, thread, li | higher, lext);
}
if (highest || higher)
rc |= a2_scom_ram(scom, thread, rldicr32, oext);
if (high) {
if (highest || higher)
rc |= a2_scom_ram(scom, thread, oris | high, oext);
else
rc |= a2_scom_ram(scom, thread, lis | high, lext);
}
if (highest || higher || high)
rc |= a2_scom_ram(scom, thread, ori | low, oext);
else
rc |= a2_scom_ram(scom, thread, li | low, lext);
return rc;
}
static int a2_scom_setspr(scom_map_t scom, int thread, int spr, u64 val)
{
int sprhi = spr >> 5;
int sprlo = spr & 0x1f;
u32 insn = 0x7c2003a6 | (sprlo << 16) | (sprhi << 11);
if (spr == 0x0ff0)
insn = 0x7c200124;
if (a2_scom_setgpr(scom, thread, 1, 1, val))
return -1;
return a2_scom_ram(scom, thread, insn, 0xf);
}
static int a2_scom_initial_tlb(scom_map_t scom, int thread)
{
extern u32 a2_tlbinit_code_start[], a2_tlbinit_code_end[];
extern u32 a2_tlbinit_after_iprot_flush[];
extern u32 a2_tlbinit_after_linear_map[];
u32 assoc, entries, i;
u64 epn, tlbcfg;
u32 *p;
int rc;
rc = a2_scom_getspr(scom, thread, SPRN_TLB0CFG, &tlbcfg);
if (rc)
goto scom_fail;
entries = tlbcfg & TLBnCFG_N_ENTRY;
assoc = (tlbcfg & TLBnCFG_ASSOC) >> 24;
epn = 0;
a2_scom_setspr(scom, thread, SPRN_MMUCR2, 0x000a7531);
a2_scom_setspr(scom, thread, SPRN_MMUCR3, 0x0000000f);
a2_scom_setspr(scom, thread, SPRN_MAS1, MAS1_TSIZE(BOOK3E_PAGESZ_1GB));
a2_scom_setspr(scom, thread, SPRN_MAS2, epn);
for (i = 0; i < entries; i++) {
a2_scom_setspr(scom, thread, SPRN_MAS0, MAS0_ESEL(i % assoc));
rc = a2_scom_ram(scom, thread, 0x7c0007a4, 0);
if (rc)
goto scom_fail;
if((i + 1) % assoc == 0) {
epn += (1 << 30);
a2_scom_setspr(scom, thread, SPRN_MAS2, epn);
}
}
rc = a2_scom_setgpr(scom, thread, 3, 0, MAS0_TLBSEL(0));
if (rc)
goto scom_fail;
for (p = a2_tlbinit_code_start; p < a2_tlbinit_after_linear_map; p++) {
rc = a2_scom_ram(scom, thread, *p, 0);
if (rc)
goto scom_fail;
}
for (p = a2_tlbinit_after_iprot_flush; p < a2_tlbinit_code_end; p++) {
rc = a2_scom_ram(scom, thread, *p, 0);
if (rc)
goto scom_fail;
}
scom_fail:
if (rc)
pr_err("Setting up initial TLB failed, err %d\n", rc);
if (rc == -SCOM_RAMC_INTERRUPT) {
int rc[10];
u64 iar, srr0, srr1, esr, mas0, mas1, mas2, mas7_3, mas8, ccr2;
rc[0] = a2_scom_getspr(scom, thread, SPRN_IAR, &iar);
rc[1] = a2_scom_getspr(scom, thread, SPRN_SRR0, &srr0);
rc[2] = a2_scom_getspr(scom, thread, SPRN_SRR1, &srr1);
rc[3] = a2_scom_getspr(scom, thread, SPRN_ESR, &esr);
rc[4] = a2_scom_getspr(scom, thread, SPRN_MAS0, &mas0);
rc[5] = a2_scom_getspr(scom, thread, SPRN_MAS1, &mas1);
rc[6] = a2_scom_getspr(scom, thread, SPRN_MAS2, &mas2);
rc[7] = a2_scom_getspr(scom, thread, SPRN_MAS7_MAS3, &mas7_3);
rc[8] = a2_scom_getspr(scom, thread, SPRN_MAS8, &mas8);
rc[9] = a2_scom_getspr(scom, thread, SPRN_A2_CCR2, &ccr2);
pr_err(" -> retreived IAR =0x%llx (err %d)\n", iar, rc[0]);
pr_err(" retreived SRR0=0x%llx (err %d)\n", srr0, rc[1]);
pr_err(" retreived SRR1=0x%llx (err %d)\n", srr1, rc[2]);
pr_err(" retreived ESR =0x%llx (err %d)\n", esr, rc[3]);
pr_err(" retreived MAS0=0x%llx (err %d)\n", mas0, rc[4]);
pr_err(" retreived MAS1=0x%llx (err %d)\n", mas1, rc[5]);
pr_err(" retreived MAS2=0x%llx (err %d)\n", mas2, rc[6]);
pr_err(" retreived MS73=0x%llx (err %d)\n", mas7_3, rc[7]);
pr_err(" retreived MAS8=0x%llx (err %d)\n", mas8, rc[8]);
pr_err(" retreived CCR2=0x%llx (err %d)\n", ccr2, rc[9]);
}
return rc;
}
int a2_scom_startup_cpu(unsigned int lcpu, int thr_idx, struct device_node *np)
{
u64 init_iar, init_msr, init_ccr2;
unsigned long start_here;
int rc, core_setup;
scom_map_t scom;
u64 pccr0;
scom = get_scom(lcpu, np, &core_setup);
if (!scom) {
printk(KERN_ERR "Couldn't map SCOM for CPU%d\n", lcpu);
return -1;
}
pr_devel("Bringing up CPU%d using SCOM...\n", lcpu);
if (scom_read(scom, SCOM_PCCR0, &pccr0) != 0) {
printk(KERN_ERR "XSCOM failure readng PCCR0 on CPU%d\n", lcpu);
return -1;
}
scom_write(scom, SCOM_PCCR0, pccr0 | SCOM_PCCR0_ENABLE_DEBUG |
SCOM_PCCR0_ENABLE_RAM);
if (core_setup)
scom_write(scom, SCOM_THRCTL_OR,
SCOM_THRCTL_T0_STOP |
SCOM_THRCTL_T1_STOP |
SCOM_THRCTL_T2_STOP |
SCOM_THRCTL_T3_STOP |
SCOM_THRCTL_ASYNC_DIS);
else
scom_write(scom, SCOM_THRCTL_OR, SCOM_THRCTL_T0_STOP >> thr_idx);
scom_write(scom, SCOM_RAMC, ((u64)thr_idx << 17) |
SCOM_RAMC_FLUSH | SCOM_RAMC_ENABLE);
a2_scom_getspr(scom, thr_idx, SPRN_IAR, &init_iar);
a2_scom_getspr(scom, thr_idx, 0x0ff0, &init_msr);
a2_scom_getspr(scom, thr_idx, SPRN_A2_CCR2, &init_ccr2);
rc = a2_scom_setspr(scom, thr_idx, 0x0ff0, MSR_CM);
if (rc) {
pr_err("Failed to set MSR ! err %d\n", rc);
return rc;
}
a2_scom_ram(scom, thr_idx, 0x7c0004ac, 0);
a2_scom_ram(scom, thr_idx, 0x4c00012c, 0);
if (core_setup) {
pr_devel("CPU%d is first thread in core, initializing TLB...\n",
lcpu);
rc = a2_scom_initial_tlb(scom, thr_idx);
if (rc)
goto fail;
}
start_here = *(unsigned long *)(core_setup ? generic_secondary_smp_init
: generic_secondary_thread_init);
pr_devel("CPU%d entry point at 0x%lx...\n", lcpu, start_here);
rc |= a2_scom_setspr(scom, thr_idx, SPRN_IAR, start_here);
rc |= a2_scom_setgpr(scom, thr_idx, 3, 0,
get_hard_smp_processor_id(lcpu));
rc |= a2_scom_setgpr(scom, thr_idx, 4, 0, 1);
rc |= a2_scom_setspr(scom, thr_idx, SPRN_TENS, 0x1 << thr_idx);
scom_write(scom, SCOM_RAMC, 0);
scom_write(scom, SCOM_THRCTL_AND, ~(SCOM_THRCTL_T0_STOP >> thr_idx));
scom_write(scom, SCOM_PCCR0, pccr0);
fail:
pr_devel(" SCOM initialization %s\n", rc ? "failed" : "succeeded");
if (rc) {
pr_err("Old IAR=0x%08llx MSR=0x%08llx CCR2=0x%08llx\n",
init_iar, init_msr, init_ccr2);
}
return rc;
}
