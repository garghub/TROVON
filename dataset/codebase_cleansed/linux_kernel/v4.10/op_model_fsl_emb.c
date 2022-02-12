static inline u32 get_pmlca(int ctr)
{
u32 pmlca;
switch (ctr) {
case 0:
pmlca = mfpmr(PMRN_PMLCA0);
break;
case 1:
pmlca = mfpmr(PMRN_PMLCA1);
break;
case 2:
pmlca = mfpmr(PMRN_PMLCA2);
break;
case 3:
pmlca = mfpmr(PMRN_PMLCA3);
break;
case 4:
pmlca = mfpmr(PMRN_PMLCA4);
break;
case 5:
pmlca = mfpmr(PMRN_PMLCA5);
break;
default:
panic("Bad ctr number\n");
}
return pmlca;
}
static inline void set_pmlca(int ctr, u32 pmlca)
{
switch (ctr) {
case 0:
mtpmr(PMRN_PMLCA0, pmlca);
break;
case 1:
mtpmr(PMRN_PMLCA1, pmlca);
break;
case 2:
mtpmr(PMRN_PMLCA2, pmlca);
break;
case 3:
mtpmr(PMRN_PMLCA3, pmlca);
break;
case 4:
mtpmr(PMRN_PMLCA4, pmlca);
break;
case 5:
mtpmr(PMRN_PMLCA5, pmlca);
break;
default:
panic("Bad ctr number\n");
}
}
static inline unsigned int ctr_read(unsigned int i)
{
switch(i) {
case 0:
return mfpmr(PMRN_PMC0);
case 1:
return mfpmr(PMRN_PMC1);
case 2:
return mfpmr(PMRN_PMC2);
case 3:
return mfpmr(PMRN_PMC3);
case 4:
return mfpmr(PMRN_PMC4);
case 5:
return mfpmr(PMRN_PMC5);
default:
return 0;
}
}
static inline void ctr_write(unsigned int i, unsigned int val)
{
switch(i) {
case 0:
mtpmr(PMRN_PMC0, val);
break;
case 1:
mtpmr(PMRN_PMC1, val);
break;
case 2:
mtpmr(PMRN_PMC2, val);
break;
case 3:
mtpmr(PMRN_PMC3, val);
break;
case 4:
mtpmr(PMRN_PMC4, val);
break;
case 5:
mtpmr(PMRN_PMC5, val);
break;
default:
break;
}
}
static void init_pmc_stop(int ctr)
{
u32 pmlca = (PMLCA_FC | PMLCA_FCS | PMLCA_FCU |
PMLCA_FCM1 | PMLCA_FCM0);
u32 pmlcb = 0;
switch (ctr) {
case 0:
mtpmr(PMRN_PMLCA0, pmlca);
mtpmr(PMRN_PMLCB0, pmlcb);
break;
case 1:
mtpmr(PMRN_PMLCA1, pmlca);
mtpmr(PMRN_PMLCB1, pmlcb);
break;
case 2:
mtpmr(PMRN_PMLCA2, pmlca);
mtpmr(PMRN_PMLCB2, pmlcb);
break;
case 3:
mtpmr(PMRN_PMLCA3, pmlca);
mtpmr(PMRN_PMLCB3, pmlcb);
break;
case 4:
mtpmr(PMRN_PMLCA4, pmlca);
mtpmr(PMRN_PMLCB4, pmlcb);
break;
case 5:
mtpmr(PMRN_PMLCA5, pmlca);
mtpmr(PMRN_PMLCB5, pmlcb);
break;
default:
panic("Bad ctr number!\n");
}
}
static void set_pmc_event(int ctr, int event)
{
u32 pmlca;
pmlca = get_pmlca(ctr);
pmlca = (pmlca & ~PMLCA_EVENT_MASK) |
((event << PMLCA_EVENT_SHIFT) &
PMLCA_EVENT_MASK);
set_pmlca(ctr, pmlca);
}
static void set_pmc_user_kernel(int ctr, int user, int kernel)
{
u32 pmlca;
pmlca = get_pmlca(ctr);
if(user)
pmlca &= ~PMLCA_FCU;
else
pmlca |= PMLCA_FCU;
if(kernel)
pmlca &= ~PMLCA_FCS;
else
pmlca |= PMLCA_FCS;
set_pmlca(ctr, pmlca);
}
static void set_pmc_marked(int ctr, int mark0, int mark1)
{
u32 pmlca = get_pmlca(ctr);
if(mark0)
pmlca &= ~PMLCA_FCM0;
else
pmlca |= PMLCA_FCM0;
if(mark1)
pmlca &= ~PMLCA_FCM1;
else
pmlca |= PMLCA_FCM1;
set_pmlca(ctr, pmlca);
}
static void pmc_start_ctr(int ctr, int enable)
{
u32 pmlca = get_pmlca(ctr);
pmlca &= ~PMLCA_FC;
if (enable)
pmlca |= PMLCA_CE;
else
pmlca &= ~PMLCA_CE;
set_pmlca(ctr, pmlca);
}
static void pmc_start_ctrs(int enable)
{
u32 pmgc0 = mfpmr(PMRN_PMGC0);
pmgc0 &= ~PMGC0_FAC;
pmgc0 |= PMGC0_FCECE;
if (enable)
pmgc0 |= PMGC0_PMIE;
else
pmgc0 &= ~PMGC0_PMIE;
mtpmr(PMRN_PMGC0, pmgc0);
}
static void pmc_stop_ctrs(void)
{
u32 pmgc0 = mfpmr(PMRN_PMGC0);
pmgc0 |= PMGC0_FAC;
pmgc0 &= ~(PMGC0_PMIE | PMGC0_FCECE);
mtpmr(PMRN_PMGC0, pmgc0);
}
static int fsl_emb_cpu_setup(struct op_counter_config *ctr)
{
int i;
pmc_stop_ctrs();
for (i = 0;i < num_counters;i++) {
init_pmc_stop(i);
set_pmc_event(i, ctr[i].event);
set_pmc_user_kernel(i, ctr[i].user, ctr[i].kernel);
}
return 0;
}
static int fsl_emb_reg_setup(struct op_counter_config *ctr,
struct op_system_config *sys,
int num_ctrs)
{
int i;
num_counters = num_ctrs;
for (i = 0; i < num_counters; ++i)
reset_value[i] = 0x80000000UL - ctr[i].count;
return 0;
}
static int fsl_emb_start(struct op_counter_config *ctr)
{
int i;
mtmsr(mfmsr() | MSR_PMM);
for (i = 0; i < num_counters; ++i) {
if (ctr[i].enabled) {
ctr_write(i, reset_value[i]);
set_pmc_marked(i, 1, 0);
pmc_start_ctr(i, 1);
} else {
ctr_write(i, 0);
pmc_start_ctr(i, 0);
}
}
pmc_start_ctrs(1);
oprofile_running = 1;
pr_debug("start on cpu %d, pmgc0 %x\n", smp_processor_id(),
mfpmr(PMRN_PMGC0));
return 0;
}
static void fsl_emb_stop(void)
{
pmc_stop_ctrs();
oprofile_running = 0;
pr_debug("stop on cpu %d, pmgc0 %x\n", smp_processor_id(),
mfpmr(PMRN_PMGC0));
mb();
}
static void fsl_emb_handle_interrupt(struct pt_regs *regs,
struct op_counter_config *ctr)
{
unsigned long pc;
int is_kernel;
int val;
int i;
pc = regs->nip;
is_kernel = is_kernel_addr(pc);
for (i = 0; i < num_counters; ++i) {
val = ctr_read(i);
if (val < 0) {
if (oprofile_running && ctr[i].enabled) {
oprofile_add_ext_sample(pc, regs, i, is_kernel);
ctr_write(i, reset_value[i]);
} else {
ctr_write(i, 0);
}
}
}
mtmsr(mfmsr() | MSR_PMM);
pmc_start_ctrs(1);
}
