static void ppro_shutdown(struct op_msrs const * const msrs)
{
int i;
for (i = 0; i < num_counters; ++i) {
if (!msrs->counters[i].addr)
continue;
release_perfctr_nmi(MSR_P6_PERFCTR0 + i);
release_evntsel_nmi(MSR_P6_EVNTSEL0 + i);
}
}
static int ppro_fill_in_addresses(struct op_msrs * const msrs)
{
int i;
for (i = 0; i < num_counters; i++) {
if (!reserve_perfctr_nmi(MSR_P6_PERFCTR0 + i))
goto fail;
if (!reserve_evntsel_nmi(MSR_P6_EVNTSEL0 + i)) {
release_perfctr_nmi(MSR_P6_PERFCTR0 + i);
goto fail;
}
msrs->counters[i].addr = MSR_P6_PERFCTR0 + i;
msrs->controls[i].addr = MSR_P6_EVNTSEL0 + i;
continue;
fail:
if (!counter_config[i].enabled)
continue;
op_x86_warn_reserved(i);
ppro_shutdown(msrs);
return -EBUSY;
}
return 0;
}
static void ppro_setup_ctrs(struct op_x86_model_spec const *model,
struct op_msrs const * const msrs)
{
u64 val;
int i;
if (cpu_has_arch_perfmon) {
union cpuid10_eax eax;
eax.full = cpuid_eax(0xa);
if (!(eax.split.version_id == 0 &&
__this_cpu_read(cpu_info.x86) == 6 &&
__this_cpu_read(cpu_info.x86_model) == 15)) {
if (counter_width < eax.split.bit_width)
counter_width = eax.split.bit_width;
}
}
for (i = 0; i < num_counters; ++i) {
if (!msrs->controls[i].addr)
continue;
rdmsrl(msrs->controls[i].addr, val);
if (val & ARCH_PERFMON_EVENTSEL_ENABLE)
op_x86_warn_in_use(i);
val &= model->reserved;
wrmsrl(msrs->controls[i].addr, val);
wrmsrl(msrs->counters[i].addr, -1LL);
}
for (i = 0; i < num_counters; ++i) {
if (counter_config[i].enabled && msrs->counters[i].addr) {
reset_value[i] = counter_config[i].count;
wrmsrl(msrs->counters[i].addr, -reset_value[i]);
rdmsrl(msrs->controls[i].addr, val);
val &= model->reserved;
val |= op_x86_get_ctrl(model, &counter_config[i]);
wrmsrl(msrs->controls[i].addr, val);
} else {
reset_value[i] = 0;
}
}
}
static int ppro_check_ctrs(struct pt_regs * const regs,
struct op_msrs const * const msrs)
{
u64 val;
int i;
for (i = 0; i < num_counters; ++i) {
if (!reset_value[i])
continue;
rdmsrl(msrs->counters[i].addr, val);
if (val & (1ULL << (counter_width - 1)))
continue;
oprofile_add_sample(regs, i);
wrmsrl(msrs->counters[i].addr, -reset_value[i]);
}
apic_write(APIC_LVTPC, apic_read(APIC_LVTPC) & ~APIC_LVT_MASKED);
return 1;
}
static void ppro_start(struct op_msrs const * const msrs)
{
u64 val;
int i;
for (i = 0; i < num_counters; ++i) {
if (reset_value[i]) {
rdmsrl(msrs->controls[i].addr, val);
val |= ARCH_PERFMON_EVENTSEL_ENABLE;
wrmsrl(msrs->controls[i].addr, val);
}
}
}
static void ppro_stop(struct op_msrs const * const msrs)
{
u64 val;
int i;
for (i = 0; i < num_counters; ++i) {
if (!reset_value[i])
continue;
rdmsrl(msrs->controls[i].addr, val);
val &= ~ARCH_PERFMON_EVENTSEL_ENABLE;
wrmsrl(msrs->controls[i].addr, val);
}
}
static void arch_perfmon_setup_counters(void)
{
union cpuid10_eax eax;
eax.full = cpuid_eax(0xa);
if (eax.split.version_id == 0 && __this_cpu_read(cpu_info.x86) == 6 &&
__this_cpu_read(cpu_info.x86_model) == 15) {
eax.split.version_id = 2;
eax.split.num_counters = 2;
eax.split.bit_width = 40;
}
num_counters = min((int)eax.split.num_counters, OP_MAX_COUNTER);
op_arch_perfmon_spec.num_counters = num_counters;
op_arch_perfmon_spec.num_controls = num_counters;
}
static int arch_perfmon_init(struct oprofile_operations *ignore)
{
arch_perfmon_setup_counters();
return 0;
}
