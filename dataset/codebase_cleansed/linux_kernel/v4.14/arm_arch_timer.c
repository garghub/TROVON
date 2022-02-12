static int __init early_evtstrm_cfg(char *buf)
{
return strtobool(buf, &evtstrm_enable);
}
static __always_inline
void arch_timer_reg_write(int access, enum arch_timer_reg reg, u32 val,
struct clock_event_device *clk)
{
if (access == ARCH_TIMER_MEM_PHYS_ACCESS) {
struct arch_timer *timer = to_arch_timer(clk);
switch (reg) {
case ARCH_TIMER_REG_CTRL:
writel_relaxed(val, timer->base + CNTP_CTL);
break;
case ARCH_TIMER_REG_TVAL:
writel_relaxed(val, timer->base + CNTP_TVAL);
break;
}
} else if (access == ARCH_TIMER_MEM_VIRT_ACCESS) {
struct arch_timer *timer = to_arch_timer(clk);
switch (reg) {
case ARCH_TIMER_REG_CTRL:
writel_relaxed(val, timer->base + CNTV_CTL);
break;
case ARCH_TIMER_REG_TVAL:
writel_relaxed(val, timer->base + CNTV_TVAL);
break;
}
} else {
arch_timer_reg_write_cp15(access, reg, val);
}
}
static __always_inline
u32 arch_timer_reg_read(int access, enum arch_timer_reg reg,
struct clock_event_device *clk)
{
u32 val;
if (access == ARCH_TIMER_MEM_PHYS_ACCESS) {
struct arch_timer *timer = to_arch_timer(clk);
switch (reg) {
case ARCH_TIMER_REG_CTRL:
val = readl_relaxed(timer->base + CNTP_CTL);
break;
case ARCH_TIMER_REG_TVAL:
val = readl_relaxed(timer->base + CNTP_TVAL);
break;
}
} else if (access == ARCH_TIMER_MEM_VIRT_ACCESS) {
struct arch_timer *timer = to_arch_timer(clk);
switch (reg) {
case ARCH_TIMER_REG_CTRL:
val = readl_relaxed(timer->base + CNTV_CTL);
break;
case ARCH_TIMER_REG_TVAL:
val = readl_relaxed(timer->base + CNTV_TVAL);
break;
}
} else {
val = arch_timer_reg_read_cp15(access, reg);
}
return val;
}
static u64 arch_counter_read(struct clocksource *cs)
{
return arch_timer_read_counter();
}
static u64 arch_counter_read_cc(const struct cyclecounter *cc)
{
return arch_timer_read_counter();
}
static u32 notrace fsl_a008585_read_cntp_tval_el0(void)
{
return __fsl_a008585_read_reg(cntp_tval_el0);
}
static u32 notrace fsl_a008585_read_cntv_tval_el0(void)
{
return __fsl_a008585_read_reg(cntv_tval_el0);
}
static u64 notrace fsl_a008585_read_cntvct_el0(void)
{
return __fsl_a008585_read_reg(cntvct_el0);
}
static u32 notrace hisi_161010101_read_cntp_tval_el0(void)
{
return __hisi_161010101_read_reg(cntp_tval_el0);
}
static u32 notrace hisi_161010101_read_cntv_tval_el0(void)
{
return __hisi_161010101_read_reg(cntv_tval_el0);
}
static u64 notrace hisi_161010101_read_cntvct_el0(void)
{
return __hisi_161010101_read_reg(cntvct_el0);
}
static u64 notrace arm64_858921_read_cntvct_el0(void)
{
u64 old, new;
old = read_sysreg(cntvct_el0);
new = read_sysreg(cntvct_el0);
return (((old ^ new) >> 32) & 1) ? old : new;
}
static void erratum_set_next_event_tval_generic(const int access, unsigned long evt,
struct clock_event_device *clk)
{
unsigned long ctrl;
u64 cval = evt + arch_counter_get_cntvct();
ctrl = arch_timer_reg_read(access, ARCH_TIMER_REG_CTRL, clk);
ctrl |= ARCH_TIMER_CTRL_ENABLE;
ctrl &= ~ARCH_TIMER_CTRL_IT_MASK;
if (access == ARCH_TIMER_PHYS_ACCESS)
write_sysreg(cval, cntp_cval_el0);
else
write_sysreg(cval, cntv_cval_el0);
arch_timer_reg_write(access, ARCH_TIMER_REG_CTRL, ctrl, clk);
}
static __maybe_unused int erratum_set_next_event_tval_virt(unsigned long evt,
struct clock_event_device *clk)
{
erratum_set_next_event_tval_generic(ARCH_TIMER_VIRT_ACCESS, evt, clk);
return 0;
}
static __maybe_unused int erratum_set_next_event_tval_phys(unsigned long evt,
struct clock_event_device *clk)
{
erratum_set_next_event_tval_generic(ARCH_TIMER_PHYS_ACCESS, evt, clk);
return 0;
}
static
bool arch_timer_check_dt_erratum(const struct arch_timer_erratum_workaround *wa,
const void *arg)
{
const struct device_node *np = arg;
return of_property_read_bool(np, wa->id);
}
static
bool arch_timer_check_local_cap_erratum(const struct arch_timer_erratum_workaround *wa,
const void *arg)
{
return this_cpu_has_cap((uintptr_t)wa->id);
}
static
bool arch_timer_check_acpi_oem_erratum(const struct arch_timer_erratum_workaround *wa,
const void *arg)
{
static const struct ate_acpi_oem_info empty_oem_info = {};
const struct ate_acpi_oem_info *info = wa->id;
const struct acpi_table_header *table = arg;
while (memcmp(info, &empty_oem_info, sizeof(*info))) {
if (!memcmp(info->oem_id, table->oem_id, ACPI_OEM_ID_SIZE) &&
!memcmp(info->oem_table_id, table->oem_table_id, ACPI_OEM_TABLE_ID_SIZE) &&
info->oem_revision == table->oem_revision)
return true;
info++;
}
return false;
}
static const struct arch_timer_erratum_workaround *
arch_timer_iterate_errata(enum arch_timer_erratum_match_type type,
ate_match_fn_t match_fn,
void *arg)
{
int i;
for (i = 0; i < ARRAY_SIZE(ool_workarounds); i++) {
if (ool_workarounds[i].match_type != type)
continue;
if (match_fn(&ool_workarounds[i], arg))
return &ool_workarounds[i];
}
return NULL;
}
static
void arch_timer_enable_workaround(const struct arch_timer_erratum_workaround *wa,
bool local)
{
int i;
if (local) {
__this_cpu_write(timer_unstable_counter_workaround, wa);
} else {
for_each_possible_cpu(i)
per_cpu(timer_unstable_counter_workaround, i) = wa;
}
static_branch_enable_cpuslocked(&arch_timer_read_ool_enabled);
if (wa->read_cntvct_el0) {
clocksource_counter.archdata.vdso_direct = false;
vdso_default = false;
}
}
static void arch_timer_check_ool_workaround(enum arch_timer_erratum_match_type type,
void *arg)
{
const struct arch_timer_erratum_workaround *wa;
ate_match_fn_t match_fn = NULL;
bool local = false;
switch (type) {
case ate_match_dt:
match_fn = arch_timer_check_dt_erratum;
break;
case ate_match_local_cap_id:
match_fn = arch_timer_check_local_cap_erratum;
local = true;
break;
case ate_match_acpi_oem_info:
match_fn = arch_timer_check_acpi_oem_erratum;
break;
default:
WARN_ON(1);
return;
}
wa = arch_timer_iterate_errata(type, match_fn, arg);
if (!wa)
return;
if (needs_unstable_timer_counter_workaround()) {
const struct arch_timer_erratum_workaround *__wa;
__wa = __this_cpu_read(timer_unstable_counter_workaround);
if (__wa && wa != __wa)
pr_warn("Can't enable workaround for %s (clashes with %s\n)",
wa->desc, __wa->desc);
if (__wa)
return;
}
arch_timer_enable_workaround(wa, local);
pr_info("Enabling %s workaround for %s\n",
local ? "local" : "global", wa->desc);
}
static bool arch_timer_this_cpu_has_cntvct_wa(void)
{
const struct arch_timer_erratum_workaround *wa;
wa = __this_cpu_read(timer_unstable_counter_workaround);
return wa && wa->read_cntvct_el0;
}
static __always_inline irqreturn_t timer_handler(const int access,
struct clock_event_device *evt)
{
unsigned long ctrl;
ctrl = arch_timer_reg_read(access, ARCH_TIMER_REG_CTRL, evt);
if (ctrl & ARCH_TIMER_CTRL_IT_STAT) {
ctrl |= ARCH_TIMER_CTRL_IT_MASK;
arch_timer_reg_write(access, ARCH_TIMER_REG_CTRL, ctrl, evt);
evt->event_handler(evt);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static irqreturn_t arch_timer_handler_virt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
return timer_handler(ARCH_TIMER_VIRT_ACCESS, evt);
}
static irqreturn_t arch_timer_handler_phys(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
return timer_handler(ARCH_TIMER_PHYS_ACCESS, evt);
}
static irqreturn_t arch_timer_handler_phys_mem(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
return timer_handler(ARCH_TIMER_MEM_PHYS_ACCESS, evt);
}
static irqreturn_t arch_timer_handler_virt_mem(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
return timer_handler(ARCH_TIMER_MEM_VIRT_ACCESS, evt);
}
static __always_inline int timer_shutdown(const int access,
struct clock_event_device *clk)
{
unsigned long ctrl;
ctrl = arch_timer_reg_read(access, ARCH_TIMER_REG_CTRL, clk);
ctrl &= ~ARCH_TIMER_CTRL_ENABLE;
arch_timer_reg_write(access, ARCH_TIMER_REG_CTRL, ctrl, clk);
return 0;
}
static int arch_timer_shutdown_virt(struct clock_event_device *clk)
{
return timer_shutdown(ARCH_TIMER_VIRT_ACCESS, clk);
}
static int arch_timer_shutdown_phys(struct clock_event_device *clk)
{
return timer_shutdown(ARCH_TIMER_PHYS_ACCESS, clk);
}
static int arch_timer_shutdown_virt_mem(struct clock_event_device *clk)
{
return timer_shutdown(ARCH_TIMER_MEM_VIRT_ACCESS, clk);
}
static int arch_timer_shutdown_phys_mem(struct clock_event_device *clk)
{
return timer_shutdown(ARCH_TIMER_MEM_PHYS_ACCESS, clk);
}
static __always_inline void set_next_event(const int access, unsigned long evt,
struct clock_event_device *clk)
{
unsigned long ctrl;
ctrl = arch_timer_reg_read(access, ARCH_TIMER_REG_CTRL, clk);
ctrl |= ARCH_TIMER_CTRL_ENABLE;
ctrl &= ~ARCH_TIMER_CTRL_IT_MASK;
arch_timer_reg_write(access, ARCH_TIMER_REG_TVAL, evt, clk);
arch_timer_reg_write(access, ARCH_TIMER_REG_CTRL, ctrl, clk);
}
static int arch_timer_set_next_event_virt(unsigned long evt,
struct clock_event_device *clk)
{
int ret;
if (erratum_handler(set_next_event_virt, ret, evt, clk))
return ret;
set_next_event(ARCH_TIMER_VIRT_ACCESS, evt, clk);
return 0;
}
static int arch_timer_set_next_event_phys(unsigned long evt,
struct clock_event_device *clk)
{
int ret;
if (erratum_handler(set_next_event_phys, ret, evt, clk))
return ret;
set_next_event(ARCH_TIMER_PHYS_ACCESS, evt, clk);
return 0;
}
static int arch_timer_set_next_event_virt_mem(unsigned long evt,
struct clock_event_device *clk)
{
set_next_event(ARCH_TIMER_MEM_VIRT_ACCESS, evt, clk);
return 0;
}
static int arch_timer_set_next_event_phys_mem(unsigned long evt,
struct clock_event_device *clk)
{
set_next_event(ARCH_TIMER_MEM_PHYS_ACCESS, evt, clk);
return 0;
}
static void __arch_timer_setup(unsigned type,
struct clock_event_device *clk)
{
clk->features = CLOCK_EVT_FEAT_ONESHOT;
if (type == ARCH_TIMER_TYPE_CP15) {
if (arch_timer_c3stop)
clk->features |= CLOCK_EVT_FEAT_C3STOP;
clk->name = "arch_sys_timer";
clk->rating = 450;
clk->cpumask = cpumask_of(smp_processor_id());
clk->irq = arch_timer_ppi[arch_timer_uses_ppi];
switch (arch_timer_uses_ppi) {
case ARCH_TIMER_VIRT_PPI:
clk->set_state_shutdown = arch_timer_shutdown_virt;
clk->set_state_oneshot_stopped = arch_timer_shutdown_virt;
clk->set_next_event = arch_timer_set_next_event_virt;
break;
case ARCH_TIMER_PHYS_SECURE_PPI:
case ARCH_TIMER_PHYS_NONSECURE_PPI:
case ARCH_TIMER_HYP_PPI:
clk->set_state_shutdown = arch_timer_shutdown_phys;
clk->set_state_oneshot_stopped = arch_timer_shutdown_phys;
clk->set_next_event = arch_timer_set_next_event_phys;
break;
default:
BUG();
}
arch_timer_check_ool_workaround(ate_match_local_cap_id, NULL);
} else {
clk->features |= CLOCK_EVT_FEAT_DYNIRQ;
clk->name = "arch_mem_timer";
clk->rating = 400;
clk->cpumask = cpu_all_mask;
if (arch_timer_mem_use_virtual) {
clk->set_state_shutdown = arch_timer_shutdown_virt_mem;
clk->set_state_oneshot_stopped = arch_timer_shutdown_virt_mem;
clk->set_next_event =
arch_timer_set_next_event_virt_mem;
} else {
clk->set_state_shutdown = arch_timer_shutdown_phys_mem;
clk->set_state_oneshot_stopped = arch_timer_shutdown_phys_mem;
clk->set_next_event =
arch_timer_set_next_event_phys_mem;
}
}
clk->set_state_shutdown(clk);
clockevents_config_and_register(clk, arch_timer_rate, 0xf, 0x7fffffff);
}
static void arch_timer_evtstrm_enable(int divider)
{
u32 cntkctl = arch_timer_get_cntkctl();
cntkctl &= ~ARCH_TIMER_EVT_TRIGGER_MASK;
cntkctl |= (divider << ARCH_TIMER_EVT_TRIGGER_SHIFT)
| ARCH_TIMER_VIRT_EVT_EN;
arch_timer_set_cntkctl(cntkctl);
elf_hwcap |= HWCAP_EVTSTRM;
#ifdef CONFIG_COMPAT
compat_elf_hwcap |= COMPAT_HWCAP_EVTSTRM;
#endif
}
static void arch_timer_configure_evtstream(void)
{
int evt_stream_div, pos;
evt_stream_div = arch_timer_rate / ARCH_TIMER_EVT_STREAM_FREQ;
pos = fls(evt_stream_div);
if (pos > 1 && !(evt_stream_div & (1 << (pos - 2))))
pos--;
arch_timer_evtstrm_enable(min(pos, 15));
}
static void arch_counter_set_user_access(void)
{
u32 cntkctl = arch_timer_get_cntkctl();
cntkctl &= ~(ARCH_TIMER_USR_PT_ACCESS_EN
| ARCH_TIMER_USR_VT_ACCESS_EN
| ARCH_TIMER_USR_VCT_ACCESS_EN
| ARCH_TIMER_VIRT_EVT_EN
| ARCH_TIMER_USR_PCT_ACCESS_EN);
if (arch_timer_this_cpu_has_cntvct_wa())
pr_info("CPU%d: Trapping CNTVCT access\n", smp_processor_id());
else
cntkctl |= ARCH_TIMER_USR_VCT_ACCESS_EN;
arch_timer_set_cntkctl(cntkctl);
}
static bool arch_timer_has_nonsecure_ppi(void)
{
return (arch_timer_uses_ppi == ARCH_TIMER_PHYS_SECURE_PPI &&
arch_timer_ppi[ARCH_TIMER_PHYS_NONSECURE_PPI]);
}
static u32 check_ppi_trigger(int irq)
{
u32 flags = irq_get_trigger_type(irq);
if (flags != IRQF_TRIGGER_HIGH && flags != IRQF_TRIGGER_LOW) {
pr_warn("WARNING: Invalid trigger for IRQ%d, assuming level low\n", irq);
pr_warn("WARNING: Please fix your firmware\n");
flags = IRQF_TRIGGER_LOW;
}
return flags;
}
static int arch_timer_starting_cpu(unsigned int cpu)
{
struct clock_event_device *clk = this_cpu_ptr(arch_timer_evt);
u32 flags;
__arch_timer_setup(ARCH_TIMER_TYPE_CP15, clk);
flags = check_ppi_trigger(arch_timer_ppi[arch_timer_uses_ppi]);
enable_percpu_irq(arch_timer_ppi[arch_timer_uses_ppi], flags);
if (arch_timer_has_nonsecure_ppi()) {
flags = check_ppi_trigger(arch_timer_ppi[ARCH_TIMER_PHYS_NONSECURE_PPI]);
enable_percpu_irq(arch_timer_ppi[ARCH_TIMER_PHYS_NONSECURE_PPI],
flags);
}
arch_counter_set_user_access();
if (evtstrm_enable)
arch_timer_configure_evtstream();
return 0;
}
static void arch_timer_of_configure_rate(u32 rate, struct device_node *np)
{
if (arch_timer_rate)
return;
if (of_property_read_u32(np, "clock-frequency", &arch_timer_rate))
arch_timer_rate = rate;
if (arch_timer_rate == 0)
pr_warn("frequency not available\n");
}
static void arch_timer_banner(unsigned type)
{
pr_info("%s%s%s timer(s) running at %lu.%02luMHz (%s%s%s).\n",
type & ARCH_TIMER_TYPE_CP15 ? "cp15" : "",
type == (ARCH_TIMER_TYPE_CP15 | ARCH_TIMER_TYPE_MEM) ?
" and " : "",
type & ARCH_TIMER_TYPE_MEM ? "mmio" : "",
(unsigned long)arch_timer_rate / 1000000,
(unsigned long)(arch_timer_rate / 10000) % 100,
type & ARCH_TIMER_TYPE_CP15 ?
(arch_timer_uses_ppi == ARCH_TIMER_VIRT_PPI) ? "virt" : "phys" :
"",
type == (ARCH_TIMER_TYPE_CP15 | ARCH_TIMER_TYPE_MEM) ? "/" : "",
type & ARCH_TIMER_TYPE_MEM ?
arch_timer_mem_use_virtual ? "virt" : "phys" :
"");
}
u32 arch_timer_get_rate(void)
{
return arch_timer_rate;
}
static u64 arch_counter_get_cntvct_mem(void)
{
u32 vct_lo, vct_hi, tmp_hi;
do {
vct_hi = readl_relaxed(arch_counter_base + CNTVCT_HI);
vct_lo = readl_relaxed(arch_counter_base + CNTVCT_LO);
tmp_hi = readl_relaxed(arch_counter_base + CNTVCT_HI);
} while (vct_hi != tmp_hi);
return ((u64) vct_hi << 32) | vct_lo;
}
struct arch_timer_kvm_info *arch_timer_get_kvm_info(void)
{
return &arch_timer_kvm_info;
}
static void __init arch_counter_register(unsigned type)
{
u64 start_count;
if (type & ARCH_TIMER_TYPE_CP15) {
if (IS_ENABLED(CONFIG_ARM64) ||
arch_timer_uses_ppi == ARCH_TIMER_VIRT_PPI)
arch_timer_read_counter = arch_counter_get_cntvct;
else
arch_timer_read_counter = arch_counter_get_cntpct;
clocksource_counter.archdata.vdso_direct = vdso_default;
} else {
arch_timer_read_counter = arch_counter_get_cntvct_mem;
}
if (!arch_counter_suspend_stop)
clocksource_counter.flags |= CLOCK_SOURCE_SUSPEND_NONSTOP;
start_count = arch_timer_read_counter();
clocksource_register_hz(&clocksource_counter, arch_timer_rate);
cyclecounter.mult = clocksource_counter.mult;
cyclecounter.shift = clocksource_counter.shift;
timecounter_init(&arch_timer_kvm_info.timecounter,
&cyclecounter, start_count);
sched_clock_register(arch_timer_read_counter, 56, arch_timer_rate);
}
static void arch_timer_stop(struct clock_event_device *clk)
{
pr_debug("disable IRQ%d cpu #%d\n", clk->irq, smp_processor_id());
disable_percpu_irq(arch_timer_ppi[arch_timer_uses_ppi]);
if (arch_timer_has_nonsecure_ppi())
disable_percpu_irq(arch_timer_ppi[ARCH_TIMER_PHYS_NONSECURE_PPI]);
clk->set_state_shutdown(clk);
}
static int arch_timer_dying_cpu(unsigned int cpu)
{
struct clock_event_device *clk = this_cpu_ptr(arch_timer_evt);
arch_timer_stop(clk);
return 0;
}
static int arch_timer_cpu_pm_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
if (action == CPU_PM_ENTER)
__this_cpu_write(saved_cntkctl, arch_timer_get_cntkctl());
else if (action == CPU_PM_ENTER_FAILED || action == CPU_PM_EXIT)
arch_timer_set_cntkctl(__this_cpu_read(saved_cntkctl));
return NOTIFY_OK;
}
static int __init arch_timer_cpu_pm_init(void)
{
return cpu_pm_register_notifier(&arch_timer_cpu_pm_notifier);
}
static void __init arch_timer_cpu_pm_deinit(void)
{
WARN_ON(cpu_pm_unregister_notifier(&arch_timer_cpu_pm_notifier));
}
static int __init arch_timer_cpu_pm_init(void)
{
return 0;
}
static void __init arch_timer_cpu_pm_deinit(void)
{
}
static int __init arch_timer_register(void)
{
int err;
int ppi;
arch_timer_evt = alloc_percpu(struct clock_event_device);
if (!arch_timer_evt) {
err = -ENOMEM;
goto out;
}
ppi = arch_timer_ppi[arch_timer_uses_ppi];
switch (arch_timer_uses_ppi) {
case ARCH_TIMER_VIRT_PPI:
err = request_percpu_irq(ppi, arch_timer_handler_virt,
"arch_timer", arch_timer_evt);
break;
case ARCH_TIMER_PHYS_SECURE_PPI:
case ARCH_TIMER_PHYS_NONSECURE_PPI:
err = request_percpu_irq(ppi, arch_timer_handler_phys,
"arch_timer", arch_timer_evt);
if (!err && arch_timer_has_nonsecure_ppi()) {
ppi = arch_timer_ppi[ARCH_TIMER_PHYS_NONSECURE_PPI];
err = request_percpu_irq(ppi, arch_timer_handler_phys,
"arch_timer", arch_timer_evt);
if (err)
free_percpu_irq(arch_timer_ppi[ARCH_TIMER_PHYS_SECURE_PPI],
arch_timer_evt);
}
break;
case ARCH_TIMER_HYP_PPI:
err = request_percpu_irq(ppi, arch_timer_handler_phys,
"arch_timer", arch_timer_evt);
break;
default:
BUG();
}
if (err) {
pr_err("can't register interrupt %d (%d)\n", ppi, err);
goto out_free;
}
err = arch_timer_cpu_pm_init();
if (err)
goto out_unreg_notify;
err = cpuhp_setup_state(CPUHP_AP_ARM_ARCH_TIMER_STARTING,
"clockevents/arm/arch_timer:starting",
arch_timer_starting_cpu, arch_timer_dying_cpu);
if (err)
goto out_unreg_cpupm;
return 0;
out_unreg_cpupm:
arch_timer_cpu_pm_deinit();
out_unreg_notify:
free_percpu_irq(arch_timer_ppi[arch_timer_uses_ppi], arch_timer_evt);
if (arch_timer_has_nonsecure_ppi())
free_percpu_irq(arch_timer_ppi[ARCH_TIMER_PHYS_NONSECURE_PPI],
arch_timer_evt);
out_free:
free_percpu(arch_timer_evt);
out:
return err;
}
static int __init arch_timer_mem_register(void __iomem *base, unsigned int irq)
{
int ret;
irq_handler_t func;
struct arch_timer *t;
t = kzalloc(sizeof(*t), GFP_KERNEL);
if (!t)
return -ENOMEM;
t->base = base;
t->evt.irq = irq;
__arch_timer_setup(ARCH_TIMER_TYPE_MEM, &t->evt);
if (arch_timer_mem_use_virtual)
func = arch_timer_handler_virt_mem;
else
func = arch_timer_handler_phys_mem;
ret = request_irq(irq, func, IRQF_TIMER, "arch_mem_timer", &t->evt);
if (ret) {
pr_err("Failed to request mem timer irq\n");
kfree(t);
}
return ret;
}
static bool __init arch_timer_needs_of_probing(void)
{
struct device_node *dn;
bool needs_probing = false;
unsigned int mask = ARCH_TIMER_TYPE_CP15 | ARCH_TIMER_TYPE_MEM;
if ((arch_timers_present & mask) == mask)
return false;
if (arch_timers_present & ARCH_TIMER_TYPE_CP15)
dn = of_find_matching_node(NULL, arch_timer_mem_of_match);
else
dn = of_find_matching_node(NULL, arch_timer_of_match);
if (dn && of_device_is_available(dn))
needs_probing = true;
of_node_put(dn);
return needs_probing;
}
static int __init arch_timer_common_init(void)
{
arch_timer_banner(arch_timers_present);
arch_counter_register(arch_timers_present);
return arch_timer_arch_init();
}
static enum arch_timer_ppi_nr __init arch_timer_select_ppi(void)
{
if (is_kernel_in_hyp_mode())
return ARCH_TIMER_HYP_PPI;
if (!is_hyp_mode_available() && arch_timer_ppi[ARCH_TIMER_VIRT_PPI])
return ARCH_TIMER_VIRT_PPI;
if (IS_ENABLED(CONFIG_ARM64))
return ARCH_TIMER_PHYS_NONSECURE_PPI;
return ARCH_TIMER_PHYS_SECURE_PPI;
}
static int __init arch_timer_of_init(struct device_node *np)
{
int i, ret;
u32 rate;
if (arch_timers_present & ARCH_TIMER_TYPE_CP15) {
pr_warn("multiple nodes in dt, skipping\n");
return 0;
}
arch_timers_present |= ARCH_TIMER_TYPE_CP15;
for (i = ARCH_TIMER_PHYS_SECURE_PPI; i < ARCH_TIMER_MAX_TIMER_PPI; i++)
arch_timer_ppi[i] = irq_of_parse_and_map(np, i);
arch_timer_kvm_info.virtual_irq = arch_timer_ppi[ARCH_TIMER_VIRT_PPI];
rate = arch_timer_get_cntfrq();
arch_timer_of_configure_rate(rate, np);
arch_timer_c3stop = !of_property_read_bool(np, "always-on");
arch_timer_check_ool_workaround(ate_match_dt, np);
if (IS_ENABLED(CONFIG_ARM) &&
of_property_read_bool(np, "arm,cpu-registers-not-fw-configured"))
arch_timer_uses_ppi = ARCH_TIMER_PHYS_SECURE_PPI;
else
arch_timer_uses_ppi = arch_timer_select_ppi();
if (!arch_timer_ppi[arch_timer_uses_ppi]) {
pr_err("No interrupt available, giving up\n");
return -EINVAL;
}
arch_counter_suspend_stop = of_property_read_bool(np,
"arm,no-tick-in-suspend");
ret = arch_timer_register();
if (ret)
return ret;
if (arch_timer_needs_of_probing())
return 0;
return arch_timer_common_init();
}
static u32 __init
arch_timer_mem_frame_get_cntfrq(struct arch_timer_mem_frame *frame)
{
void __iomem *base;
u32 rate;
base = ioremap(frame->cntbase, frame->size);
if (!base) {
pr_err("Unable to map frame @ %pa\n", &frame->cntbase);
return 0;
}
rate = readl_relaxed(base + CNTFRQ);
iounmap(base);
return rate;
}
static struct arch_timer_mem_frame * __init
arch_timer_mem_find_best_frame(struct arch_timer_mem *timer_mem)
{
struct arch_timer_mem_frame *frame, *best_frame = NULL;
void __iomem *cntctlbase;
u32 cnttidr;
int i;
cntctlbase = ioremap(timer_mem->cntctlbase, timer_mem->size);
if (!cntctlbase) {
pr_err("Can't map CNTCTLBase @ %pa\n",
&timer_mem->cntctlbase);
return NULL;
}
cnttidr = readl_relaxed(cntctlbase + CNTTIDR);
for (i = 0; i < ARCH_TIMER_MEM_MAX_FRAMES; i++) {
u32 cntacr = CNTACR_RFRQ | CNTACR_RWPT | CNTACR_RPCT |
CNTACR_RWVT | CNTACR_RVOFF | CNTACR_RVCT;
frame = &timer_mem->frame[i];
if (!frame->valid)
continue;
writel_relaxed(cntacr, cntctlbase + CNTACR(i));
cntacr = readl_relaxed(cntctlbase + CNTACR(i));
if ((cnttidr & CNTTIDR_VIRT(i)) &&
!(~cntacr & (CNTACR_RWVT | CNTACR_RVCT))) {
best_frame = frame;
arch_timer_mem_use_virtual = true;
break;
}
if (~cntacr & (CNTACR_RWPT | CNTACR_RPCT))
continue;
best_frame = frame;
}
iounmap(cntctlbase);
if (!best_frame)
pr_err("Unable to find a suitable frame in timer @ %pa\n",
&timer_mem->cntctlbase);
return best_frame;
}
static int __init
arch_timer_mem_frame_register(struct arch_timer_mem_frame *frame)
{
void __iomem *base;
int ret, irq = 0;
if (arch_timer_mem_use_virtual)
irq = frame->virt_irq;
else
irq = frame->phys_irq;
if (!irq) {
pr_err("Frame missing %s irq.\n",
arch_timer_mem_use_virtual ? "virt" : "phys");
return -EINVAL;
}
if (!request_mem_region(frame->cntbase, frame->size,
"arch_mem_timer"))
return -EBUSY;
base = ioremap(frame->cntbase, frame->size);
if (!base) {
pr_err("Can't map frame's registers\n");
return -ENXIO;
}
ret = arch_timer_mem_register(base, irq);
if (ret) {
iounmap(base);
return ret;
}
arch_counter_base = base;
arch_timers_present |= ARCH_TIMER_TYPE_MEM;
return 0;
}
static int __init arch_timer_mem_of_init(struct device_node *np)
{
struct arch_timer_mem *timer_mem;
struct arch_timer_mem_frame *frame;
struct device_node *frame_node;
struct resource res;
int ret = -EINVAL;
u32 rate;
timer_mem = kzalloc(sizeof(*timer_mem), GFP_KERNEL);
if (!timer_mem)
return -ENOMEM;
if (of_address_to_resource(np, 0, &res))
goto out;
timer_mem->cntctlbase = res.start;
timer_mem->size = resource_size(&res);
for_each_available_child_of_node(np, frame_node) {
u32 n;
struct arch_timer_mem_frame *frame;
if (of_property_read_u32(frame_node, "frame-number", &n)) {
pr_err(FW_BUG "Missing frame-number.\n");
of_node_put(frame_node);
goto out;
}
if (n >= ARCH_TIMER_MEM_MAX_FRAMES) {
pr_err(FW_BUG "Wrong frame-number, only 0-%u are permitted.\n",
ARCH_TIMER_MEM_MAX_FRAMES - 1);
of_node_put(frame_node);
goto out;
}
frame = &timer_mem->frame[n];
if (frame->valid) {
pr_err(FW_BUG "Duplicated frame-number.\n");
of_node_put(frame_node);
goto out;
}
if (of_address_to_resource(frame_node, 0, &res)) {
of_node_put(frame_node);
goto out;
}
frame->cntbase = res.start;
frame->size = resource_size(&res);
frame->virt_irq = irq_of_parse_and_map(frame_node,
ARCH_TIMER_VIRT_SPI);
frame->phys_irq = irq_of_parse_and_map(frame_node,
ARCH_TIMER_PHYS_SPI);
frame->valid = true;
}
frame = arch_timer_mem_find_best_frame(timer_mem);
if (!frame) {
ret = -EINVAL;
goto out;
}
rate = arch_timer_mem_frame_get_cntfrq(frame);
arch_timer_of_configure_rate(rate, np);
ret = arch_timer_mem_frame_register(frame);
if (!ret && !arch_timer_needs_of_probing())
ret = arch_timer_common_init();
out:
kfree(timer_mem);
return ret;
}
static int __init
arch_timer_mem_verify_cntfrq(struct arch_timer_mem *timer_mem)
{
struct arch_timer_mem_frame *frame;
u32 rate;
int i;
for (i = 0; i < ARCH_TIMER_MEM_MAX_FRAMES; i++) {
frame = &timer_mem->frame[i];
if (!frame->valid)
continue;
rate = arch_timer_mem_frame_get_cntfrq(frame);
if (rate == arch_timer_rate)
continue;
pr_err(FW_BUG "CNTFRQ mismatch: frame @ %pa: (0x%08lx), CPU: (0x%08lx)\n",
&frame->cntbase,
(unsigned long)rate, (unsigned long)arch_timer_rate);
return -EINVAL;
}
return 0;
}
static int __init arch_timer_mem_acpi_init(int platform_timer_count)
{
struct arch_timer_mem *timers, *timer;
struct arch_timer_mem_frame *frame;
int timer_count, i, ret = 0;
timers = kcalloc(platform_timer_count, sizeof(*timers),
GFP_KERNEL);
if (!timers)
return -ENOMEM;
ret = acpi_arch_timer_mem_init(timers, &timer_count);
if (ret || !timer_count)
goto out;
for (i = 0; i < timer_count; i++) {
ret = arch_timer_mem_verify_cntfrq(&timers[i]);
if (ret) {
pr_err("Disabling MMIO timers due to CNTFRQ mismatch\n");
goto out;
}
}
for (i = 0; i < timer_count; i++) {
timer = &timers[i];
frame = arch_timer_mem_find_best_frame(timer);
if (frame)
break;
}
if (frame)
ret = arch_timer_mem_frame_register(frame);
out:
kfree(timers);
return ret;
}
static int __init arch_timer_acpi_init(struct acpi_table_header *table)
{
int ret, platform_timer_count;
if (arch_timers_present & ARCH_TIMER_TYPE_CP15) {
pr_warn("already initialized, skipping\n");
return -EINVAL;
}
arch_timers_present |= ARCH_TIMER_TYPE_CP15;
ret = acpi_gtdt_init(table, &platform_timer_count);
if (ret) {
pr_err("Failed to init GTDT table.\n");
return ret;
}
arch_timer_ppi[ARCH_TIMER_PHYS_NONSECURE_PPI] =
acpi_gtdt_map_ppi(ARCH_TIMER_PHYS_NONSECURE_PPI);
arch_timer_ppi[ARCH_TIMER_VIRT_PPI] =
acpi_gtdt_map_ppi(ARCH_TIMER_VIRT_PPI);
arch_timer_ppi[ARCH_TIMER_HYP_PPI] =
acpi_gtdt_map_ppi(ARCH_TIMER_HYP_PPI);
arch_timer_kvm_info.virtual_irq = arch_timer_ppi[ARCH_TIMER_VIRT_PPI];
arch_timer_rate = arch_timer_get_cntfrq();
if (!arch_timer_rate) {
pr_err(FW_BUG "frequency not available.\n");
return -EINVAL;
}
arch_timer_uses_ppi = arch_timer_select_ppi();
if (!arch_timer_ppi[arch_timer_uses_ppi]) {
pr_err("No interrupt available, giving up\n");
return -EINVAL;
}
arch_timer_c3stop = acpi_gtdt_c3stop(arch_timer_uses_ppi);
arch_timer_check_ool_workaround(ate_match_acpi_oem_info, table);
ret = arch_timer_register();
if (ret)
return ret;
if (platform_timer_count &&
arch_timer_mem_acpi_init(platform_timer_count))
pr_err("Failed to initialize memory-mapped timer.\n");
return arch_timer_common_init();
}
