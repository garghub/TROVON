static void ctr_set_enable(u64 *state, int ctr_set)
{
*state |= cpumf_state_ctl[ctr_set] << CPUMF_LCCTL_ENABLE_SHIFT;
}
static void ctr_set_disable(u64 *state, int ctr_set)
{
*state &= ~(cpumf_state_ctl[ctr_set] << CPUMF_LCCTL_ENABLE_SHIFT);
}
static void ctr_set_start(u64 *state, int ctr_set)
{
*state |= cpumf_state_ctl[ctr_set] << CPUMF_LCCTL_ACTCTL_SHIFT;
}
static void ctr_set_stop(u64 *state, int ctr_set)
{
*state &= ~(cpumf_state_ctl[ctr_set] << CPUMF_LCCTL_ACTCTL_SHIFT);
}
static int get_counter_set(u64 event)
{
int set = -1;
if (event < 32)
set = CPUMF_CTR_SET_BASIC;
else if (event < 64)
set = CPUMF_CTR_SET_USER;
else if (event < 128)
set = CPUMF_CTR_SET_CRYPTO;
else if (event < 256)
set = CPUMF_CTR_SET_EXT;
return set;
}
static int validate_event(const struct hw_perf_event *hwc)
{
switch (hwc->config_base) {
case CPUMF_CTR_SET_BASIC:
case CPUMF_CTR_SET_USER:
case CPUMF_CTR_SET_CRYPTO:
case CPUMF_CTR_SET_EXT:
if ((hwc->config >= 6 && hwc->config <= 31) ||
(hwc->config >= 38 && hwc->config <= 63) ||
(hwc->config >= 80 && hwc->config <= 127))
return -EOPNOTSUPP;
break;
default:
return -EINVAL;
}
return 0;
}
static int validate_ctr_version(const struct hw_perf_event *hwc)
{
struct cpu_hw_events *cpuhw;
int err = 0;
cpuhw = &get_cpu_var(cpu_hw_events);
switch (hwc->config_base) {
case CPUMF_CTR_SET_BASIC:
case CPUMF_CTR_SET_USER:
if (cpuhw->info.cfvn < 1)
err = -EOPNOTSUPP;
break;
case CPUMF_CTR_SET_CRYPTO:
case CPUMF_CTR_SET_EXT:
if (cpuhw->info.csvn < 1)
err = -EOPNOTSUPP;
if ((cpuhw->info.csvn == 1 && hwc->config > 159) ||
(cpuhw->info.csvn == 2 && hwc->config > 175) ||
(cpuhw->info.csvn > 2 && hwc->config > 255))
err = -EOPNOTSUPP;
break;
}
put_cpu_var(cpu_hw_events);
return err;
}
static int validate_ctr_auth(const struct hw_perf_event *hwc)
{
struct cpu_hw_events *cpuhw;
u64 ctrs_state;
int err = 0;
cpuhw = &get_cpu_var(cpu_hw_events);
ctrs_state = cpumf_state_ctl[hwc->config_base];
if (!(ctrs_state & cpuhw->info.auth_ctl))
err = -ENOENT;
put_cpu_var(cpu_hw_events);
return err;
}
static void cpumf_pmu_enable(struct pmu *pmu)
{
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
int err;
if (cpuhw->flags & PMU_F_ENABLED)
return;
err = lcctl(cpuhw->state);
if (err) {
pr_err("Enabling the performance measuring unit "
"failed with rc=%x\n", err);
return;
}
cpuhw->flags |= PMU_F_ENABLED;
}
static void cpumf_pmu_disable(struct pmu *pmu)
{
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
int err;
u64 inactive;
if (!(cpuhw->flags & PMU_F_ENABLED))
return;
inactive = cpuhw->state & ~((1 << CPUMF_LCCTL_ENABLE_SHIFT) - 1);
err = lcctl(inactive);
if (err) {
pr_err("Disabling the performance measuring unit "
"failed with rc=%x\n", err);
return;
}
cpuhw->flags &= ~PMU_F_ENABLED;
}
static void cpumf_measurement_alert(struct ext_code ext_code,
unsigned int alert, unsigned long unused)
{
struct cpu_hw_events *cpuhw;
if (!(alert & CPU_MF_INT_CF_MASK))
return;
inc_irq_stat(IRQEXT_CMC);
cpuhw = this_cpu_ptr(&cpu_hw_events);
if (!(cpuhw->flags & PMU_F_RESERVED))
return;
if (alert & CPU_MF_INT_CF_CACA)
qctri(&cpuhw->info);
if (alert & CPU_MF_INT_CF_LCDA)
pr_err("CPU[%i] Counter data was lost\n", smp_processor_id());
}
static void setup_pmc_cpu(void *flags)
{
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
switch (*((int *) flags)) {
case PMC_INIT:
memset(&cpuhw->info, 0, sizeof(cpuhw->info));
qctri(&cpuhw->info);
cpuhw->flags |= PMU_F_RESERVED;
break;
case PMC_RELEASE:
cpuhw->flags &= ~PMU_F_RESERVED;
break;
}
lcctl(0);
}
static int reserve_pmc_hardware(void)
{
int flags = PMC_INIT;
on_each_cpu(setup_pmc_cpu, &flags, 1);
irq_subclass_register(IRQ_SUBCLASS_MEASUREMENT_ALERT);
return 0;
}
static void release_pmc_hardware(void)
{
int flags = PMC_RELEASE;
on_each_cpu(setup_pmc_cpu, &flags, 1);
irq_subclass_unregister(IRQ_SUBCLASS_MEASUREMENT_ALERT);
}
static void hw_perf_event_destroy(struct perf_event *event)
{
if (!atomic_add_unless(&num_events, -1, 1)) {
mutex_lock(&pmc_reserve_mutex);
if (atomic_dec_return(&num_events) == 0)
release_pmc_hardware();
mutex_unlock(&pmc_reserve_mutex);
}
}
static int __hw_perf_event_init(struct perf_event *event)
{
struct perf_event_attr *attr = &event->attr;
struct hw_perf_event *hwc = &event->hw;
int err;
u64 ev;
switch (attr->type) {
case PERF_TYPE_RAW:
if (attr->exclude_kernel || attr->exclude_user ||
attr->exclude_hv)
return -EOPNOTSUPP;
ev = attr->config;
break;
case PERF_TYPE_HARDWARE:
ev = attr->config;
if (!attr->exclude_user && attr->exclude_kernel) {
if (ev >= ARRAY_SIZE(cpumf_generic_events_user))
return -EOPNOTSUPP;
ev = cpumf_generic_events_user[ev];
} else if (!attr->exclude_kernel && attr->exclude_user) {
return -EOPNOTSUPP;
} else {
if (ev >= ARRAY_SIZE(cpumf_generic_events_basic))
return -EOPNOTSUPP;
ev = cpumf_generic_events_basic[ev];
}
break;
default:
return -ENOENT;
}
if (ev == -1)
return -ENOENT;
if (ev >= PERF_CPUM_CF_MAX_CTR)
return -EINVAL;
hwc->config = ev;
hwc->config_base = get_counter_set(ev);
err = validate_event(hwc);
if (err)
return err;
if (!atomic_inc_not_zero(&num_events)) {
mutex_lock(&pmc_reserve_mutex);
if (atomic_read(&num_events) == 0 && reserve_pmc_hardware())
err = -EBUSY;
else
atomic_inc(&num_events);
mutex_unlock(&pmc_reserve_mutex);
}
event->destroy = hw_perf_event_destroy;
err = validate_ctr_auth(hwc);
if (!err)
err = validate_ctr_version(hwc);
return err;
}
static int cpumf_pmu_event_init(struct perf_event *event)
{
int err;
switch (event->attr.type) {
case PERF_TYPE_HARDWARE:
case PERF_TYPE_HW_CACHE:
case PERF_TYPE_RAW:
err = __hw_perf_event_init(event);
break;
default:
return -ENOENT;
}
if (unlikely(err) && event->destroy)
event->destroy(event);
return err;
}
static int hw_perf_event_reset(struct perf_event *event)
{
u64 prev, new;
int err;
do {
prev = local64_read(&event->hw.prev_count);
err = ecctr(event->hw.config, &new);
if (err) {
if (err != 3)
break;
new = 0;
}
} while (local64_cmpxchg(&event->hw.prev_count, prev, new) != prev);
return err;
}
static int hw_perf_event_update(struct perf_event *event)
{
u64 prev, new, delta;
int err;
do {
prev = local64_read(&event->hw.prev_count);
err = ecctr(event->hw.config, &new);
if (err)
goto out;
} while (local64_cmpxchg(&event->hw.prev_count, prev, new) != prev);
delta = (prev <= new) ? new - prev
: (-1ULL - prev) + new + 1;
local64_add(delta, &event->count);
out:
return err;
}
static void cpumf_pmu_read(struct perf_event *event)
{
if (event->hw.state & PERF_HES_STOPPED)
return;
hw_perf_event_update(event);
}
static void cpumf_pmu_start(struct perf_event *event, int flags)
{
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
struct hw_perf_event *hwc = &event->hw;
if (WARN_ON_ONCE(!(hwc->state & PERF_HES_STOPPED)))
return;
if (WARN_ON_ONCE(hwc->config == -1))
return;
if (flags & PERF_EF_RELOAD)
WARN_ON_ONCE(!(hwc->state & PERF_HES_UPTODATE));
hwc->state = 0;
ctr_set_enable(&cpuhw->state, hwc->config_base);
ctr_set_start(&cpuhw->state, hwc->config_base);
hw_perf_event_reset(event);
atomic_inc(&cpuhw->ctr_set[hwc->config_base]);
}
static void cpumf_pmu_stop(struct perf_event *event, int flags)
{
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
struct hw_perf_event *hwc = &event->hw;
if (!(hwc->state & PERF_HES_STOPPED)) {
if (!atomic_dec_return(&cpuhw->ctr_set[hwc->config_base]))
ctr_set_stop(&cpuhw->state, hwc->config_base);
event->hw.state |= PERF_HES_STOPPED;
}
if ((flags & PERF_EF_UPDATE) && !(hwc->state & PERF_HES_UPTODATE)) {
hw_perf_event_update(event);
event->hw.state |= PERF_HES_UPTODATE;
}
}
static int cpumf_pmu_add(struct perf_event *event, int flags)
{
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
if (!(cpuhw->txn_flags & PERF_PMU_TXN_ADD))
if (validate_ctr_auth(&event->hw))
return -ENOENT;
ctr_set_enable(&cpuhw->state, event->hw.config_base);
event->hw.state = PERF_HES_UPTODATE | PERF_HES_STOPPED;
if (flags & PERF_EF_START)
cpumf_pmu_start(event, PERF_EF_RELOAD);
perf_event_update_userpage(event);
return 0;
}
static void cpumf_pmu_del(struct perf_event *event, int flags)
{
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
cpumf_pmu_stop(event, PERF_EF_UPDATE);
if (!atomic_read(&cpuhw->ctr_set[event->hw.config_base]))
ctr_set_disable(&cpuhw->state, event->hw.config_base);
perf_event_update_userpage(event);
}
static void cpumf_pmu_start_txn(struct pmu *pmu, unsigned int txn_flags)
{
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
WARN_ON_ONCE(cpuhw->txn_flags);
cpuhw->txn_flags = txn_flags;
if (txn_flags & ~PERF_PMU_TXN_ADD)
return;
perf_pmu_disable(pmu);
cpuhw->tx_state = cpuhw->state;
}
static void cpumf_pmu_cancel_txn(struct pmu *pmu)
{
unsigned int txn_flags;
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
WARN_ON_ONCE(!cpuhw->txn_flags);
txn_flags = cpuhw->txn_flags;
cpuhw->txn_flags = 0;
if (txn_flags & ~PERF_PMU_TXN_ADD)
return;
WARN_ON(cpuhw->tx_state != cpuhw->state);
perf_pmu_enable(pmu);
}
static int cpumf_pmu_commit_txn(struct pmu *pmu)
{
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
u64 state;
WARN_ON_ONCE(!cpuhw->txn_flags);
if (cpuhw->txn_flags & ~PERF_PMU_TXN_ADD) {
cpuhw->txn_flags = 0;
return 0;
}
state = cpuhw->state & ~((1 << CPUMF_LCCTL_ENABLE_SHIFT) - 1);
state >>= CPUMF_LCCTL_ENABLE_SHIFT;
if ((state & cpuhw->info.auth_ctl) != state)
return -ENOENT;
cpuhw->txn_flags = 0;
perf_pmu_enable(pmu);
return 0;
}
static int cpumf_pmf_setup(unsigned int cpu, int flags)
{
local_irq_disable();
setup_pmc_cpu(&flags);
local_irq_enable();
return 0;
}
static int s390_pmu_online_cpu(unsigned int cpu)
{
return cpumf_pmf_setup(cpu, PMC_INIT);
}
static int s390_pmu_offline_cpu(unsigned int cpu)
{
return cpumf_pmf_setup(cpu, PMC_RELEASE);
}
static int __init cpumf_pmu_init(void)
{
int rc;
if (!cpum_cf_avail())
return -ENODEV;
ctl_clear_bit(0, 48);
rc = register_external_irq(EXT_IRQ_MEASURE_ALERT,
cpumf_measurement_alert);
if (rc) {
pr_err("Registering for CPU-measurement alerts "
"failed with rc=%i\n", rc);
return rc;
}
cpumf_pmu.attr_groups = cpumf_cf_event_group();
rc = perf_pmu_register(&cpumf_pmu, "cpum_cf", PERF_TYPE_RAW);
if (rc) {
pr_err("Registering the cpum_cf PMU failed with rc=%i\n", rc);
unregister_external_irq(EXT_IRQ_MEASURE_ALERT,
cpumf_measurement_alert);
return rc;
}
return cpuhp_setup_state(CPUHP_AP_PERF_S390_CF_ONLINE,
"perf/s390/cf:online",
s390_pmu_online_cpu, s390_pmu_offline_cpu);
}
