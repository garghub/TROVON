static void pmc_start_ctrs(void)
{
u32 mmcr0 = mfspr(SPRN_MMCR0);
mmcr0 &= ~(MMCR0_FC | MMCR0_FCM0);
mmcr0 |= (MMCR0_FCECE | MMCR0_PMC1CE | MMCR0_PMCnCE | MMCR0_PMXE);
mtspr(SPRN_MMCR0, mmcr0);
}
static void pmc_stop_ctrs(void)
{
u32 mmcr0 = mfspr(SPRN_MMCR0);
mmcr0 |= MMCR0_FC;
mmcr0 &= ~(MMCR0_FCECE | MMCR0_PMC1CE | MMCR0_PMCnCE | MMCR0_PMXE);
mtspr(SPRN_MMCR0, mmcr0);
}
static int fsl7450_cpu_setup(struct op_counter_config *ctr)
{
pmc_stop_ctrs();
mtspr(SPRN_MMCR0, mmcr0_val);
mtspr(SPRN_MMCR1, mmcr1_val);
if (num_pmcs > 4)
mtspr(SPRN_MMCR2, mmcr2_val);
return 0;
}
static int fsl7450_reg_setup(struct op_counter_config *ctr,
struct op_system_config *sys,
int num_ctrs)
{
int i;
num_pmcs = num_ctrs;
for (i = 0; i < num_ctrs; ++i)
reset_value[i] = 0x80000000UL - ctr[i].count;
mmcr0_val = MMCR0_INIT | mmcr0_event1(ctr[0].event)
| mmcr0_event2(ctr[1].event);
if (sys->enable_kernel)
mmcr0_val &= ~(MMCR0_FCS);
if (sys->enable_user)
mmcr0_val &= ~(MMCR0_FCP);
mmcr1_val = mmcr1_event3(ctr[2].event)
| mmcr1_event4(ctr[3].event);
if (num_ctrs > 4)
mmcr1_val |= mmcr1_event5(ctr[4].event)
| mmcr1_event6(ctr[5].event);
mmcr2_val = 0;
return 0;
}
static int fsl7450_start(struct op_counter_config *ctr)
{
int i;
mtmsr(mfmsr() | MSR_PMM);
for (i = 0; i < num_pmcs; ++i) {
if (ctr[i].enabled)
classic_ctr_write(i, reset_value[i]);
else
classic_ctr_write(i, 0);
}
pmc_start_ctrs();
oprofile_running = 1;
return 0;
}
static void fsl7450_stop(void)
{
pmc_stop_ctrs();
oprofile_running = 0;
mb();
}
static void fsl7450_handle_interrupt(struct pt_regs *regs,
struct op_counter_config *ctr)
{
unsigned long pc;
int is_kernel;
int val;
int i;
mtmsr(mfmsr() | MSR_PMM);
pc = mfspr(SPRN_SIAR);
is_kernel = is_kernel_addr(pc);
for (i = 0; i < num_pmcs; ++i) {
val = classic_ctr_read(i);
if (val < 0) {
if (oprofile_running && ctr[i].enabled) {
oprofile_add_ext_sample(pc, regs, i, is_kernel);
classic_ctr_write(i, reset_value[i]);
} else {
classic_ctr_write(i, 0);
}
}
}
pmc_start_ctrs();
}
