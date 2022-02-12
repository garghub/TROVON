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
static __always_inline void timer_set_mode(const int access, int mode,
struct clock_event_device *clk)
{
unsigned long ctrl;
switch (mode) {
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
ctrl = arch_timer_reg_read(access, ARCH_TIMER_REG_CTRL, clk);
ctrl &= ~ARCH_TIMER_CTRL_ENABLE;
arch_timer_reg_write(access, ARCH_TIMER_REG_CTRL, ctrl, clk);
break;
default:
break;
}
}
static void arch_timer_set_mode_virt(enum clock_event_mode mode,
struct clock_event_device *clk)
{
timer_set_mode(ARCH_TIMER_VIRT_ACCESS, mode, clk);
}
static void arch_timer_set_mode_phys(enum clock_event_mode mode,
struct clock_event_device *clk)
{
timer_set_mode(ARCH_TIMER_PHYS_ACCESS, mode, clk);
}
static void arch_timer_set_mode_virt_mem(enum clock_event_mode mode,
struct clock_event_device *clk)
{
timer_set_mode(ARCH_TIMER_MEM_VIRT_ACCESS, mode, clk);
}
static void arch_timer_set_mode_phys_mem(enum clock_event_mode mode,
struct clock_event_device *clk)
{
timer_set_mode(ARCH_TIMER_MEM_PHYS_ACCESS, mode, clk);
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
set_next_event(ARCH_TIMER_VIRT_ACCESS, evt, clk);
return 0;
}
static int arch_timer_set_next_event_phys(unsigned long evt,
struct clock_event_device *clk)
{
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
if (type == ARCH_CP15_TIMER) {
if (arch_timer_c3stop)
clk->features |= CLOCK_EVT_FEAT_C3STOP;
clk->name = "arch_sys_timer";
clk->rating = 450;
clk->cpumask = cpumask_of(smp_processor_id());
if (arch_timer_use_virtual) {
clk->irq = arch_timer_ppi[VIRT_PPI];
clk->set_mode = arch_timer_set_mode_virt;
clk->set_next_event = arch_timer_set_next_event_virt;
} else {
clk->irq = arch_timer_ppi[PHYS_SECURE_PPI];
clk->set_mode = arch_timer_set_mode_phys;
clk->set_next_event = arch_timer_set_next_event_phys;
}
} else {
clk->features |= CLOCK_EVT_FEAT_DYNIRQ;
clk->name = "arch_mem_timer";
clk->rating = 400;
clk->cpumask = cpu_all_mask;
if (arch_timer_mem_use_virtual) {
clk->set_mode = arch_timer_set_mode_virt_mem;
clk->set_next_event =
arch_timer_set_next_event_virt_mem;
} else {
clk->set_mode = arch_timer_set_mode_phys_mem;
clk->set_next_event =
arch_timer_set_next_event_phys_mem;
}
}
clk->set_mode(CLOCK_EVT_MODE_SHUTDOWN, clk);
clockevents_config_and_register(clk, arch_timer_rate, 0xf, 0x7fffffff);
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
static int arch_timer_setup(struct clock_event_device *clk)
{
__arch_timer_setup(ARCH_CP15_TIMER, clk);
if (arch_timer_use_virtual)
enable_percpu_irq(arch_timer_ppi[VIRT_PPI], 0);
else {
enable_percpu_irq(arch_timer_ppi[PHYS_SECURE_PPI], 0);
if (arch_timer_ppi[PHYS_NONSECURE_PPI])
enable_percpu_irq(arch_timer_ppi[PHYS_NONSECURE_PPI], 0);
}
arch_counter_set_user_access();
if (IS_ENABLED(CONFIG_ARM_ARCH_TIMER_EVTSTREAM))
arch_timer_configure_evtstream();
return 0;
}
static void
arch_timer_detect_rate(void __iomem *cntbase, struct device_node *np)
{
if (arch_timer_rate)
return;
if (of_property_read_u32(np, "clock-frequency", &arch_timer_rate)) {
if (cntbase)
arch_timer_rate = readl_relaxed(cntbase + CNTFRQ);
else
arch_timer_rate = arch_timer_get_cntfrq();
}
if (arch_timer_rate == 0)
pr_warn("Architected timer frequency not available\n");
}
static void arch_timer_banner(unsigned type)
{
pr_info("Architected %s%s%s timer(s) running at %lu.%02luMHz (%s%s%s).\n",
type & ARCH_CP15_TIMER ? "cp15" : "",
type == (ARCH_CP15_TIMER | ARCH_MEM_TIMER) ? " and " : "",
type & ARCH_MEM_TIMER ? "mmio" : "",
(unsigned long)arch_timer_rate / 1000000,
(unsigned long)(arch_timer_rate / 10000) % 100,
type & ARCH_CP15_TIMER ?
arch_timer_use_virtual ? "virt" : "phys" :
"",
type == (ARCH_CP15_TIMER | ARCH_MEM_TIMER) ? "/" : "",
type & ARCH_MEM_TIMER ?
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
static cycle_t arch_counter_read(struct clocksource *cs)
{
return arch_timer_read_counter();
}
static cycle_t arch_counter_read_cc(const struct cyclecounter *cc)
{
return arch_timer_read_counter();
}
struct timecounter *arch_timer_get_timecounter(void)
{
return &timecounter;
}
static void __init arch_counter_register(unsigned type)
{
u64 start_count;
if (type & ARCH_CP15_TIMER)
arch_timer_read_counter = arch_counter_get_cntvct;
else
arch_timer_read_counter = arch_counter_get_cntvct_mem;
start_count = arch_timer_read_counter();
clocksource_register_hz(&clocksource_counter, arch_timer_rate);
cyclecounter.mult = clocksource_counter.mult;
cyclecounter.shift = clocksource_counter.shift;
timecounter_init(&timecounter, &cyclecounter, start_count);
sched_clock_register(arch_timer_read_counter, 56, arch_timer_rate);
}
static void arch_timer_stop(struct clock_event_device *clk)
{
pr_debug("arch_timer_teardown disable IRQ%d cpu #%d\n",
clk->irq, smp_processor_id());
if (arch_timer_use_virtual)
disable_percpu_irq(arch_timer_ppi[VIRT_PPI]);
else {
disable_percpu_irq(arch_timer_ppi[PHYS_SECURE_PPI]);
if (arch_timer_ppi[PHYS_NONSECURE_PPI])
disable_percpu_irq(arch_timer_ppi[PHYS_NONSECURE_PPI]);
}
clk->set_mode(CLOCK_EVT_MODE_UNUSED, clk);
}
static int arch_timer_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_STARTING:
arch_timer_setup(this_cpu_ptr(arch_timer_evt));
break;
case CPU_DYING:
arch_timer_stop(this_cpu_ptr(arch_timer_evt));
break;
}
return NOTIFY_OK;
}
static int arch_timer_cpu_pm_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
if (action == CPU_PM_ENTER)
saved_cntkctl = arch_timer_get_cntkctl();
else if (action == CPU_PM_ENTER_FAILED || action == CPU_PM_EXIT)
arch_timer_set_cntkctl(saved_cntkctl);
return NOTIFY_OK;
}
static int __init arch_timer_cpu_pm_init(void)
{
return cpu_pm_register_notifier(&arch_timer_cpu_pm_notifier);
}
static int __init arch_timer_cpu_pm_init(void)
{
return 0;
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
if (arch_timer_use_virtual) {
ppi = arch_timer_ppi[VIRT_PPI];
err = request_percpu_irq(ppi, arch_timer_handler_virt,
"arch_timer", arch_timer_evt);
} else {
ppi = arch_timer_ppi[PHYS_SECURE_PPI];
err = request_percpu_irq(ppi, arch_timer_handler_phys,
"arch_timer", arch_timer_evt);
if (!err && arch_timer_ppi[PHYS_NONSECURE_PPI]) {
ppi = arch_timer_ppi[PHYS_NONSECURE_PPI];
err = request_percpu_irq(ppi, arch_timer_handler_phys,
"arch_timer", arch_timer_evt);
if (err)
free_percpu_irq(arch_timer_ppi[PHYS_SECURE_PPI],
arch_timer_evt);
}
}
if (err) {
pr_err("arch_timer: can't register interrupt %d (%d)\n",
ppi, err);
goto out_free;
}
err = register_cpu_notifier(&arch_timer_cpu_nb);
if (err)
goto out_free_irq;
err = arch_timer_cpu_pm_init();
if (err)
goto out_unreg_notify;
arch_timer_setup(this_cpu_ptr(arch_timer_evt));
return 0;
out_unreg_notify:
unregister_cpu_notifier(&arch_timer_cpu_nb);
out_free_irq:
if (arch_timer_use_virtual)
free_percpu_irq(arch_timer_ppi[VIRT_PPI], arch_timer_evt);
else {
free_percpu_irq(arch_timer_ppi[PHYS_SECURE_PPI],
arch_timer_evt);
if (arch_timer_ppi[PHYS_NONSECURE_PPI])
free_percpu_irq(arch_timer_ppi[PHYS_NONSECURE_PPI],
arch_timer_evt);
}
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
__arch_timer_setup(ARCH_MEM_TIMER, &t->evt);
if (arch_timer_mem_use_virtual)
func = arch_timer_handler_virt_mem;
else
func = arch_timer_handler_phys_mem;
ret = request_irq(irq, func, IRQF_TIMER, "arch_mem_timer", &t->evt);
if (ret) {
pr_err("arch_timer: Failed to request mem timer irq\n");
kfree(t);
}
return ret;
}
static void __init arch_timer_common_init(void)
{
unsigned mask = ARCH_CP15_TIMER | ARCH_MEM_TIMER;
if ((arch_timers_present & mask) != mask) {
if (of_find_matching_node(NULL, arch_timer_mem_of_match) &&
!(arch_timers_present & ARCH_MEM_TIMER))
return;
if (of_find_matching_node(NULL, arch_timer_of_match) &&
!(arch_timers_present & ARCH_CP15_TIMER))
return;
}
arch_timer_banner(arch_timers_present);
arch_counter_register(arch_timers_present);
arch_timer_arch_init();
}
static void __init arch_timer_init(struct device_node *np)
{
int i;
if (arch_timers_present & ARCH_CP15_TIMER) {
pr_warn("arch_timer: multiple nodes in dt, skipping\n");
return;
}
arch_timers_present |= ARCH_CP15_TIMER;
for (i = PHYS_SECURE_PPI; i < MAX_TIMER_PPI; i++)
arch_timer_ppi[i] = irq_of_parse_and_map(np, i);
arch_timer_detect_rate(NULL, np);
if (is_hyp_mode_available() || !arch_timer_ppi[VIRT_PPI]) {
arch_timer_use_virtual = false;
if (!arch_timer_ppi[PHYS_SECURE_PPI] ||
!arch_timer_ppi[PHYS_NONSECURE_PPI]) {
pr_warn("arch_timer: No interrupt available, giving up\n");
return;
}
}
arch_timer_c3stop = !of_property_read_bool(np, "always-on");
arch_timer_register();
arch_timer_common_init();
}
static void __init arch_timer_mem_init(struct device_node *np)
{
struct device_node *frame, *best_frame = NULL;
void __iomem *cntctlbase, *base;
unsigned int irq;
u32 cnttidr;
arch_timers_present |= ARCH_MEM_TIMER;
cntctlbase = of_iomap(np, 0);
if (!cntctlbase) {
pr_err("arch_timer: Can't find CNTCTLBase\n");
return;
}
cnttidr = readl_relaxed(cntctlbase + CNTTIDR);
iounmap(cntctlbase);
for_each_available_child_of_node(np, frame) {
int n;
if (of_property_read_u32(frame, "frame-number", &n)) {
pr_err("arch_timer: Missing frame-number\n");
of_node_put(best_frame);
of_node_put(frame);
return;
}
if (cnttidr & CNTTIDR_VIRT(n)) {
of_node_put(best_frame);
best_frame = frame;
arch_timer_mem_use_virtual = true;
break;
}
of_node_put(best_frame);
best_frame = of_node_get(frame);
}
base = arch_counter_base = of_iomap(best_frame, 0);
if (!base) {
pr_err("arch_timer: Can't map frame's registers\n");
of_node_put(best_frame);
return;
}
if (arch_timer_mem_use_virtual)
irq = irq_of_parse_and_map(best_frame, 1);
else
irq = irq_of_parse_and_map(best_frame, 0);
of_node_put(best_frame);
if (!irq) {
pr_err("arch_timer: Frame missing %s irq",
arch_timer_mem_use_virtual ? "virt" : "phys");
return;
}
arch_timer_detect_rate(base, np);
arch_timer_mem_register(base, irq);
arch_timer_common_init();
}
