static inline void setup_num_counters(void)
{
#ifdef CONFIG_SMP
if (smp_num_siblings == 2) {
num_counters = NUM_COUNTERS_HT2;
num_controls = NUM_CONTROLS_HT2;
}
#endif
}
static inline int addr_increment(void)
{
#ifdef CONFIG_SMP
return smp_num_siblings == 2 ? 2 : 1;
#else
return 1;
#endif
}
static unsigned int get_stagger(void)
{
#ifdef CONFIG_SMP
int cpu = smp_processor_id();
return cpu != cpumask_first(this_cpu_cpumask_var_ptr(cpu_sibling_map));
#endif
return 0;
}
static void p4_shutdown(struct op_msrs const * const msrs)
{
int i;
for (i = 0; i < num_counters; ++i) {
if (msrs->counters[i].addr)
release_perfctr_nmi(msrs->counters[i].addr);
}
for (i = num_counters; i < num_controls; ++i) {
if (msrs->controls[i].addr)
release_evntsel_nmi(msrs->controls[i].addr);
}
}
static int p4_fill_in_addresses(struct op_msrs * const msrs)
{
unsigned int i;
unsigned int addr, cccraddr, stag;
setup_num_counters();
stag = get_stagger();
for (i = 0; i < num_counters; ++i) {
addr = p4_counters[VIRT_CTR(stag, i)].counter_address;
cccraddr = p4_counters[VIRT_CTR(stag, i)].cccr_address;
if (reserve_perfctr_nmi(addr)) {
msrs->counters[i].addr = addr;
msrs->controls[i].addr = cccraddr;
}
}
for (addr = MSR_P4_BSU_ESCR0 + stag;
addr < MSR_P4_IQ_ESCR0; ++i, addr += addr_increment()) {
if (reserve_evntsel_nmi(addr))
msrs->controls[i].addr = addr;
}
if (boot_cpu_data.x86_model >= 0x3) {
for (addr = MSR_P4_BSU_ESCR0 + stag;
addr <= MSR_P4_BSU_ESCR1; ++i, addr += addr_increment()) {
if (reserve_evntsel_nmi(addr))
msrs->controls[i].addr = addr;
}
} else {
for (addr = MSR_P4_IQ_ESCR0 + stag;
addr <= MSR_P4_IQ_ESCR1; ++i, addr += addr_increment()) {
if (reserve_evntsel_nmi(addr))
msrs->controls[i].addr = addr;
}
}
for (addr = MSR_P4_RAT_ESCR0 + stag;
addr <= MSR_P4_SSU_ESCR0; ++i, addr += addr_increment()) {
if (reserve_evntsel_nmi(addr))
msrs->controls[i].addr = addr;
}
for (addr = MSR_P4_MS_ESCR0 + stag;
addr <= MSR_P4_TC_ESCR1; ++i, addr += addr_increment()) {
if (reserve_evntsel_nmi(addr))
msrs->controls[i].addr = addr;
}
for (addr = MSR_P4_IX_ESCR0 + stag;
addr <= MSR_P4_CRU_ESCR3; ++i, addr += addr_increment()) {
if (reserve_evntsel_nmi(addr))
msrs->controls[i].addr = addr;
}
if (num_counters == NUM_COUNTERS_NON_HT) {
if (reserve_evntsel_nmi(MSR_P4_CRU_ESCR5))
msrs->controls[i++].addr = MSR_P4_CRU_ESCR5;
if (reserve_evntsel_nmi(MSR_P4_CRU_ESCR4))
msrs->controls[i++].addr = MSR_P4_CRU_ESCR4;
} else if (stag == 0) {
if (reserve_evntsel_nmi(MSR_P4_CRU_ESCR4))
msrs->controls[i++].addr = MSR_P4_CRU_ESCR4;
} else {
if (reserve_evntsel_nmi(MSR_P4_CRU_ESCR5)) {
msrs->controls[i++].addr = MSR_P4_CRU_ESCR5;
msrs->controls[i++].addr = MSR_P4_CRU_ESCR5;
}
}
for (i = 0; i < num_counters; ++i) {
if (!counter_config[i].enabled)
continue;
if (msrs->controls[i].addr)
continue;
op_x86_warn_reserved(i);
p4_shutdown(msrs);
return -EBUSY;
}
return 0;
}
static void pmc_setup_one_p4_counter(unsigned int ctr)
{
int i;
int const maxbind = 2;
unsigned int cccr = 0;
unsigned int escr = 0;
unsigned int high = 0;
unsigned int counter_bit;
struct p4_event_binding *ev = NULL;
unsigned int stag;
stag = get_stagger();
counter_bit = 1 << VIRT_CTR(stag, ctr);
if (counter_config[ctr].event <= 0 || counter_config[ctr].event > NUM_EVENTS) {
printk(KERN_ERR
"oprofile: P4 event code 0x%lx out of range\n",
counter_config[ctr].event);
return;
}
ev = &(p4_events[counter_config[ctr].event - 1]);
for (i = 0; i < maxbind; i++) {
if (ev->bindings[i].virt_counter & counter_bit) {
rdmsr(ev->bindings[i].escr_address, escr, high);
ESCR_CLEAR(escr);
if (stag == 0) {
ESCR_SET_USR_0(escr, counter_config[ctr].user);
ESCR_SET_OS_0(escr, counter_config[ctr].kernel);
} else {
ESCR_SET_USR_1(escr, counter_config[ctr].user);
ESCR_SET_OS_1(escr, counter_config[ctr].kernel);
}
ESCR_SET_EVENT_SELECT(escr, ev->event_select);
ESCR_SET_EVENT_MASK(escr, counter_config[ctr].unit_mask);
wrmsr(ev->bindings[i].escr_address, escr, high);
rdmsr(p4_counters[VIRT_CTR(stag, ctr)].cccr_address,
cccr, high);
CCCR_CLEAR(cccr);
CCCR_SET_REQUIRED_BITS(cccr);
CCCR_SET_ESCR_SELECT(cccr, ev->escr_select);
if (stag == 0)
CCCR_SET_PMI_OVF_0(cccr);
else
CCCR_SET_PMI_OVF_1(cccr);
wrmsr(p4_counters[VIRT_CTR(stag, ctr)].cccr_address,
cccr, high);
return;
}
}
printk(KERN_ERR
"oprofile: P4 event code 0x%lx no binding, stag %d ctr %d\n",
counter_config[ctr].event, stag, ctr);
}
static void p4_setup_ctrs(struct op_x86_model_spec const *model,
struct op_msrs const * const msrs)
{
unsigned int i;
unsigned int low, high;
unsigned int stag;
stag = get_stagger();
rdmsr(MSR_IA32_MISC_ENABLE, low, high);
if (!MISC_PMC_ENABLED_P(low)) {
printk(KERN_ERR "oprofile: P4 PMC not available\n");
return;
}
for (i = 0; i < num_counters; i++) {
if (unlikely(!msrs->controls[i].addr))
continue;
rdmsr(p4_counters[VIRT_CTR(stag, i)].cccr_address, low, high);
CCCR_CLEAR(low);
CCCR_SET_REQUIRED_BITS(low);
wrmsr(p4_counters[VIRT_CTR(stag, i)].cccr_address, low, high);
}
for (i = num_counters; i < num_controls; i++) {
if (unlikely(!msrs->controls[i].addr))
continue;
wrmsr(msrs->controls[i].addr, 0, 0);
}
for (i = 0; i < num_counters; ++i) {
if (counter_config[i].enabled && msrs->controls[i].addr) {
reset_value[i] = counter_config[i].count;
pmc_setup_one_p4_counter(i);
wrmsrl(p4_counters[VIRT_CTR(stag, i)].counter_address,
-(u64)counter_config[i].count);
} else {
reset_value[i] = 0;
}
}
}
static int p4_check_ctrs(struct pt_regs * const regs,
struct op_msrs const * const msrs)
{
unsigned long ctr, low, high, stag, real;
int i;
stag = get_stagger();
for (i = 0; i < num_counters; ++i) {
if (!reset_value[i])
continue;
real = VIRT_CTR(stag, i);
rdmsr(p4_counters[real].cccr_address, low, high);
rdmsr(p4_counters[real].counter_address, ctr, high);
if (CCCR_OVF_P(low) || !(ctr & OP_CTR_OVERFLOW)) {
oprofile_add_sample(regs, i);
wrmsrl(p4_counters[real].counter_address,
-(u64)reset_value[i]);
CCCR_CLEAR_OVF(low);
wrmsr(p4_counters[real].cccr_address, low, high);
wrmsrl(p4_counters[real].counter_address,
-(u64)reset_value[i]);
}
}
apic_write(APIC_LVTPC, apic_read(APIC_LVTPC) & ~APIC_LVT_MASKED);
return 1;
}
static void p4_start(struct op_msrs const * const msrs)
{
unsigned int low, high, stag;
int i;
stag = get_stagger();
for (i = 0; i < num_counters; ++i) {
if (!reset_value[i])
continue;
rdmsr(p4_counters[VIRT_CTR(stag, i)].cccr_address, low, high);
CCCR_SET_ENABLE(low);
wrmsr(p4_counters[VIRT_CTR(stag, i)].cccr_address, low, high);
}
}
static void p4_stop(struct op_msrs const * const msrs)
{
unsigned int low, high, stag;
int i;
stag = get_stagger();
for (i = 0; i < num_counters; ++i) {
if (!reset_value[i])
continue;
rdmsr(p4_counters[VIRT_CTR(stag, i)].cccr_address, low, high);
CCCR_SET_DISABLE(low);
wrmsr(p4_counters[VIRT_CTR(stag, i)].cccr_address, low, high);
}
}
