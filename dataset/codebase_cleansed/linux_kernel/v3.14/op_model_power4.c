static int power7_marked_instr_event(u64 mmcr1)
{
u64 psel, unit;
int pmc, cntr_marked_events = 0;
for (pmc = 0; pmc < 4; pmc++) {
psel = mmcr1 & (OPROFILE_PM_PMCSEL_MSK
<< (OPROFILE_MAX_PMC_NUM - pmc)
* OPROFILE_PMSEL_FIELD_WIDTH);
psel = (psel >> ((OPROFILE_MAX_PMC_NUM - pmc)
* OPROFILE_PMSEL_FIELD_WIDTH)) & ~1ULL;
unit = mmcr1 & (OPROFILE_PM_UNIT_MSK
<< (OPROFILE_PM_UNIT_SHIFT
- (pmc * OPROFILE_PMSEL_FIELD_WIDTH )));
unit = unit >> (OPROFILE_PM_UNIT_SHIFT
- (pmc * OPROFILE_PMSEL_FIELD_WIDTH));
switch (psel >> 4) {
case 2:
cntr_marked_events |= (pmc == 1 || pmc == 3) << pmc;
break;
case 3:
if (psel == 0x3c) {
cntr_marked_events |= (pmc == 0) << pmc;
break;
}
if (psel == 0x3e) {
cntr_marked_events |= (pmc != 1) << pmc;
break;
}
cntr_marked_events |= 1 << pmc;
break;
case 4:
case 5:
cntr_marked_events |= (unit == 0xd) << pmc;
break;
case 6:
if (psel == 0x64)
cntr_marked_events |= (pmc >= 2) << pmc;
break;
case 8:
cntr_marked_events |= (unit == 0xd) << pmc;
break;
}
}
return cntr_marked_events;
}
static int power4_reg_setup(struct op_counter_config *ctr,
struct op_system_config *sys,
int num_ctrs)
{
int i;
mmcr0_val = sys->mmcr0;
mmcr1_val = sys->mmcr1;
mmcra_val = sys->mmcra;
if (pvr_version_is(PVR_POWER7p))
cntr_marked_events = power7_marked_instr_event(mmcr1_val);
else
cntr_marked_events = 0;
for (i = 0; i < cur_cpu_spec->num_pmcs; ++i)
reset_value[i] = 0x80000000UL - ctr[i].count;
if (sys->enable_kernel)
mmcr0_val &= ~MMCR0_KERNEL_DISABLE;
else
mmcr0_val |= MMCR0_KERNEL_DISABLE;
if (sys->enable_user)
mmcr0_val &= ~MMCR0_PROBLEM_DISABLE;
else
mmcr0_val |= MMCR0_PROBLEM_DISABLE;
if (pvr_version_is(PVR_POWER4) || pvr_version_is(PVR_POWER4p) ||
pvr_version_is(PVR_970) || pvr_version_is(PVR_970FX) ||
pvr_version_is(PVR_970MP) || pvr_version_is(PVR_970GX) ||
pvr_version_is(PVR_POWER5) || pvr_version_is(PVR_POWER5p))
use_slot_nums = 1;
return 0;
}
static inline int mmcra_must_set_sample(void)
{
if (pvr_version_is(PVR_POWER4) || pvr_version_is(PVR_POWER4p) ||
pvr_version_is(PVR_970) || pvr_version_is(PVR_970FX) ||
pvr_version_is(PVR_970MP) || pvr_version_is(PVR_970GX))
return 1;
return 0;
}
static int power4_cpu_setup(struct op_counter_config *ctr)
{
unsigned int mmcr0 = mmcr0_val;
unsigned long mmcra = mmcra_val;
ppc_enable_pmcs();
mmcr0 |= MMCR0_FC;
mtspr(SPRN_MMCR0, mmcr0);
mmcr0 |= MMCR0_FCM1|MMCR0_PMXE|MMCR0_FCECE;
mmcr0 |= MMCR0_PMC1CE|MMCR0_PMCjCE;
mtspr(SPRN_MMCR0, mmcr0);
mtspr(SPRN_MMCR1, mmcr1_val);
if (mmcra_must_set_sample())
mmcra |= MMCRA_SAMPLE_ENABLE;
mtspr(SPRN_MMCRA, mmcra);
dbg("setup on cpu %d, mmcr0 %lx\n", smp_processor_id(),
mfspr(SPRN_MMCR0));
dbg("setup on cpu %d, mmcr1 %lx\n", smp_processor_id(),
mfspr(SPRN_MMCR1));
dbg("setup on cpu %d, mmcra %lx\n", smp_processor_id(),
mfspr(SPRN_MMCRA));
return 0;
}
static int power4_start(struct op_counter_config *ctr)
{
int i;
unsigned int mmcr0;
mtmsrd(mfmsr() | MSR_PMM);
for (i = 0; i < cur_cpu_spec->num_pmcs; ++i) {
if (ctr[i].enabled) {
classic_ctr_write(i, reset_value[i]);
} else {
classic_ctr_write(i, 0);
}
}
mmcr0 = mfspr(SPRN_MMCR0);
mmcr0 &= ~MMCR0_PMAO;
mmcr0 &= ~MMCR0_FC;
mtspr(SPRN_MMCR0, mmcr0);
oprofile_running = 1;
dbg("start on cpu %d, mmcr0 %x\n", smp_processor_id(), mmcr0);
return 0;
}
static void power4_stop(void)
{
unsigned int mmcr0;
mmcr0 = mfspr(SPRN_MMCR0);
mmcr0 |= MMCR0_FC;
mtspr(SPRN_MMCR0, mmcr0);
oprofile_running = 0;
dbg("stop on cpu %d, mmcr0 %x\n", smp_processor_id(), mmcr0);
mb();
}
static void __used hypervisor_bucket(void)
{
}
static void __used rtas_bucket(void)
{
}
static void __used kernel_unknown_bucket(void)
{
}
static unsigned long get_pc(struct pt_regs *regs)
{
unsigned long pc = mfspr(SPRN_SIAR);
unsigned long mmcra;
unsigned long slot;
if (!cur_cpu_spec->oprofile_mmcra_sihv)
return pc;
mmcra = mfspr(SPRN_MMCRA);
if (use_slot_nums && (mmcra & MMCRA_SAMPLE_ENABLE)) {
slot = ((mmcra & MMCRA_SLOT) >> MMCRA_SLOT_SHIFT);
if (slot > 1)
pc += 4 * (slot - 1);
}
if (firmware_has_feature(FW_FEATURE_LPAR) &&
(mmcra & cur_cpu_spec->oprofile_mmcra_sihv))
return *((unsigned long *)hypervisor_bucket);
if (mmcra & cur_cpu_spec->oprofile_mmcra_sipr)
return pc;
#ifdef CONFIG_PPC_RTAS
if (pc >= rtas.base && pc < (rtas.base + rtas.size))
return *((unsigned long *)rtas_bucket);
#endif
if (pc < 0x1000000UL)
return (unsigned long)__va(pc);
if (!is_kernel_addr(pc))
return *((unsigned long *)kernel_unknown_bucket);
return pc;
}
static int get_kernel(unsigned long pc, unsigned long mmcra)
{
int is_kernel;
if (!cur_cpu_spec->oprofile_mmcra_sihv) {
is_kernel = is_kernel_addr(pc);
} else {
is_kernel = ((mmcra & cur_cpu_spec->oprofile_mmcra_sipr) == 0);
}
return is_kernel;
}
static bool pmc_overflow(unsigned long val)
{
if ((int)val < 0)
return true;
if (pvr_version_is(PVR_POWER7) && ((0x80000000 - val) <= 256))
return true;
return false;
}
static void power4_handle_interrupt(struct pt_regs *regs,
struct op_counter_config *ctr)
{
unsigned long pc;
int is_kernel;
int val;
int i;
unsigned int mmcr0;
unsigned long mmcra;
bool siar_valid = false;
mmcra = mfspr(SPRN_MMCRA);
pc = get_pc(regs);
is_kernel = get_kernel(pc, mmcra);
mtmsrd(mfmsr() | MSR_PMM);
if ((mmcra & MMCRA_SIAR_VALID_MASK) == MMCRA_SIAR_VALID_MASK)
siar_valid = true;
for (i = 0; i < cur_cpu_spec->num_pmcs; ++i) {
val = classic_ctr_read(i);
if (pmc_overflow(val)) {
if (oprofile_running && ctr[i].enabled) {
if ((siar_valid &&
(cntr_marked_events & (1 << i)))
|| !(cntr_marked_events & (1 << i)))
oprofile_add_ext_sample(pc, regs, i,
is_kernel);
classic_ctr_write(i, reset_value[i]);
} else {
classic_ctr_write(i, 0);
}
}
}
mmcr0 = mfspr(SPRN_MMCR0);
mmcr0 |= MMCR0_PMXE;
mmcr0 &= ~MMCR0_PMAO;
mmcra &= ~cur_cpu_spec->oprofile_mmcra_clear;
mtspr(SPRN_MMCRA, mmcra);
mmcr0 &= ~MMCR0_FC;
mtspr(SPRN_MMCR0, mmcr0);
}
