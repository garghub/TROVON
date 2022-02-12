static inline u32
xscale1pmu_read_pmnc(void)
{
u32 val;
asm volatile("mrc p14, 0, %0, c0, c0, 0" : "=r" (val));
return val;
}
static inline void
xscale1pmu_write_pmnc(u32 val)
{
val &= 0xffff77f;
asm volatile("mcr p14, 0, %0, c0, c0, 0" : : "r" (val));
}
static inline int
xscale1_pmnc_counter_has_overflowed(unsigned long pmnc,
enum xscale_counters counter)
{
int ret = 0;
switch (counter) {
case XSCALE_CYCLE_COUNTER:
ret = pmnc & XSCALE1_CCOUNT_OVERFLOW;
break;
case XSCALE_COUNTER0:
ret = pmnc & XSCALE1_COUNT0_OVERFLOW;
break;
case XSCALE_COUNTER1:
ret = pmnc & XSCALE1_COUNT1_OVERFLOW;
break;
default:
WARN_ONCE(1, "invalid counter number (%d)\n", counter);
}
return ret;
}
static irqreturn_t
xscale1pmu_handle_irq(int irq_num, void *dev)
{
unsigned long pmnc;
struct perf_sample_data data;
struct arm_pmu *cpu_pmu = (struct arm_pmu *)dev;
struct pmu_hw_events *cpuc = cpu_pmu->get_hw_events();
struct pt_regs *regs;
int idx;
pmnc = xscale1pmu_read_pmnc();
xscale1pmu_write_pmnc(pmnc & ~XSCALE_PMU_ENABLE);
if (!(pmnc & XSCALE1_OVERFLOWED_MASK))
return IRQ_NONE;
regs = get_irq_regs();
for (idx = 0; idx < cpu_pmu->num_events; ++idx) {
struct perf_event *event = cpuc->events[idx];
struct hw_perf_event *hwc;
if (!event)
continue;
if (!xscale1_pmnc_counter_has_overflowed(pmnc, idx))
continue;
hwc = &event->hw;
armpmu_event_update(event);
perf_sample_data_init(&data, 0, hwc->last_period);
if (!armpmu_event_set_period(event))
continue;
if (perf_event_overflow(event, &data, regs))
cpu_pmu->disable(event);
}
irq_work_run();
pmnc = xscale1pmu_read_pmnc() | XSCALE_PMU_ENABLE;
xscale1pmu_write_pmnc(pmnc);
return IRQ_HANDLED;
}
static void xscale1pmu_enable_event(struct perf_event *event)
{
unsigned long val, mask, evt, flags;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
int idx = hwc->idx;
switch (idx) {
case XSCALE_CYCLE_COUNTER:
mask = 0;
evt = XSCALE1_CCOUNT_INT_EN;
break;
case XSCALE_COUNTER0:
mask = XSCALE1_COUNT0_EVT_MASK;
evt = (hwc->config_base << XSCALE1_COUNT0_EVT_SHFT) |
XSCALE1_COUNT0_INT_EN;
break;
case XSCALE_COUNTER1:
mask = XSCALE1_COUNT1_EVT_MASK;
evt = (hwc->config_base << XSCALE1_COUNT1_EVT_SHFT) |
XSCALE1_COUNT1_INT_EN;
break;
default:
WARN_ONCE(1, "invalid counter number (%d)\n", idx);
return;
}
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = xscale1pmu_read_pmnc();
val &= ~mask;
val |= evt;
xscale1pmu_write_pmnc(val);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void xscale1pmu_disable_event(struct perf_event *event)
{
unsigned long val, mask, evt, flags;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
int idx = hwc->idx;
switch (idx) {
case XSCALE_CYCLE_COUNTER:
mask = XSCALE1_CCOUNT_INT_EN;
evt = 0;
break;
case XSCALE_COUNTER0:
mask = XSCALE1_COUNT0_INT_EN | XSCALE1_COUNT0_EVT_MASK;
evt = XSCALE_PERFCTR_UNUSED << XSCALE1_COUNT0_EVT_SHFT;
break;
case XSCALE_COUNTER1:
mask = XSCALE1_COUNT1_INT_EN | XSCALE1_COUNT1_EVT_MASK;
evt = XSCALE_PERFCTR_UNUSED << XSCALE1_COUNT1_EVT_SHFT;
break;
default:
WARN_ONCE(1, "invalid counter number (%d)\n", idx);
return;
}
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = xscale1pmu_read_pmnc();
val &= ~mask;
val |= evt;
xscale1pmu_write_pmnc(val);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static int
xscale1pmu_get_event_idx(struct pmu_hw_events *cpuc,
struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
if (XSCALE_PERFCTR_CCNT == hwc->config_base) {
if (test_and_set_bit(XSCALE_CYCLE_COUNTER, cpuc->used_mask))
return -EAGAIN;
return XSCALE_CYCLE_COUNTER;
} else {
if (!test_and_set_bit(XSCALE_COUNTER1, cpuc->used_mask))
return XSCALE_COUNTER1;
if (!test_and_set_bit(XSCALE_COUNTER0, cpuc->used_mask))
return XSCALE_COUNTER0;
return -EAGAIN;
}
}
static void xscale1pmu_start(struct arm_pmu *cpu_pmu)
{
unsigned long flags, val;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = xscale1pmu_read_pmnc();
val |= XSCALE_PMU_ENABLE;
xscale1pmu_write_pmnc(val);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void xscale1pmu_stop(struct arm_pmu *cpu_pmu)
{
unsigned long flags, val;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = xscale1pmu_read_pmnc();
val &= ~XSCALE_PMU_ENABLE;
xscale1pmu_write_pmnc(val);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static inline u32 xscale1pmu_read_counter(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
int counter = hwc->idx;
u32 val = 0;
switch (counter) {
case XSCALE_CYCLE_COUNTER:
asm volatile("mrc p14, 0, %0, c1, c0, 0" : "=r" (val));
break;
case XSCALE_COUNTER0:
asm volatile("mrc p14, 0, %0, c2, c0, 0" : "=r" (val));
break;
case XSCALE_COUNTER1:
asm volatile("mrc p14, 0, %0, c3, c0, 0" : "=r" (val));
break;
}
return val;
}
static inline void xscale1pmu_write_counter(struct perf_event *event, u32 val)
{
struct hw_perf_event *hwc = &event->hw;
int counter = hwc->idx;
switch (counter) {
case XSCALE_CYCLE_COUNTER:
asm volatile("mcr p14, 0, %0, c1, c0, 0" : : "r" (val));
break;
case XSCALE_COUNTER0:
asm volatile("mcr p14, 0, %0, c2, c0, 0" : : "r" (val));
break;
case XSCALE_COUNTER1:
asm volatile("mcr p14, 0, %0, c3, c0, 0" : : "r" (val));
break;
}
}
static int xscale_map_event(struct perf_event *event)
{
return armpmu_map_event(event, &xscale_perf_map,
&xscale_perf_cache_map, 0xFF);
}
static int xscale1pmu_init(struct arm_pmu *cpu_pmu)
{
cpu_pmu->name = "armv5_xscale1";
cpu_pmu->handle_irq = xscale1pmu_handle_irq;
cpu_pmu->enable = xscale1pmu_enable_event;
cpu_pmu->disable = xscale1pmu_disable_event;
cpu_pmu->read_counter = xscale1pmu_read_counter;
cpu_pmu->write_counter = xscale1pmu_write_counter;
cpu_pmu->get_event_idx = xscale1pmu_get_event_idx;
cpu_pmu->start = xscale1pmu_start;
cpu_pmu->stop = xscale1pmu_stop;
cpu_pmu->map_event = xscale_map_event;
cpu_pmu->num_events = 3;
cpu_pmu->max_period = (1LLU << 32) - 1;
return 0;
}
static inline u32
xscale2pmu_read_pmnc(void)
{
u32 val;
asm volatile("mrc p14, 0, %0, c0, c1, 0" : "=r" (val));
return val & 0xff000009;
}
static inline void
xscale2pmu_write_pmnc(u32 val)
{
val &= 0xf;
asm volatile("mcr p14, 0, %0, c0, c1, 0" : : "r" (val));
}
static inline u32
xscale2pmu_read_overflow_flags(void)
{
u32 val;
asm volatile("mrc p14, 0, %0, c5, c1, 0" : "=r" (val));
return val;
}
static inline void
xscale2pmu_write_overflow_flags(u32 val)
{
asm volatile("mcr p14, 0, %0, c5, c1, 0" : : "r" (val));
}
static inline u32
xscale2pmu_read_event_select(void)
{
u32 val;
asm volatile("mrc p14, 0, %0, c8, c1, 0" : "=r" (val));
return val;
}
static inline void
xscale2pmu_write_event_select(u32 val)
{
asm volatile("mcr p14, 0, %0, c8, c1, 0" : : "r"(val));
}
static inline u32
xscale2pmu_read_int_enable(void)
{
u32 val;
asm volatile("mrc p14, 0, %0, c4, c1, 0" : "=r" (val));
return val;
}
static void
xscale2pmu_write_int_enable(u32 val)
{
asm volatile("mcr p14, 0, %0, c4, c1, 0" : : "r" (val));
}
static inline int
xscale2_pmnc_counter_has_overflowed(unsigned long of_flags,
enum xscale_counters counter)
{
int ret = 0;
switch (counter) {
case XSCALE_CYCLE_COUNTER:
ret = of_flags & XSCALE2_CCOUNT_OVERFLOW;
break;
case XSCALE_COUNTER0:
ret = of_flags & XSCALE2_COUNT0_OVERFLOW;
break;
case XSCALE_COUNTER1:
ret = of_flags & XSCALE2_COUNT1_OVERFLOW;
break;
case XSCALE_COUNTER2:
ret = of_flags & XSCALE2_COUNT2_OVERFLOW;
break;
case XSCALE_COUNTER3:
ret = of_flags & XSCALE2_COUNT3_OVERFLOW;
break;
default:
WARN_ONCE(1, "invalid counter number (%d)\n", counter);
}
return ret;
}
static irqreturn_t
xscale2pmu_handle_irq(int irq_num, void *dev)
{
unsigned long pmnc, of_flags;
struct perf_sample_data data;
struct arm_pmu *cpu_pmu = (struct arm_pmu *)dev;
struct pmu_hw_events *cpuc = cpu_pmu->get_hw_events();
struct pt_regs *regs;
int idx;
pmnc = xscale2pmu_read_pmnc();
xscale2pmu_write_pmnc(pmnc & ~XSCALE_PMU_ENABLE);
of_flags = xscale2pmu_read_overflow_flags();
if (!(of_flags & XSCALE2_OVERFLOWED_MASK))
return IRQ_NONE;
xscale2pmu_write_overflow_flags(of_flags);
regs = get_irq_regs();
for (idx = 0; idx < cpu_pmu->num_events; ++idx) {
struct perf_event *event = cpuc->events[idx];
struct hw_perf_event *hwc;
if (!event)
continue;
if (!xscale2_pmnc_counter_has_overflowed(of_flags, idx))
continue;
hwc = &event->hw;
armpmu_event_update(event);
perf_sample_data_init(&data, 0, hwc->last_period);
if (!armpmu_event_set_period(event))
continue;
if (perf_event_overflow(event, &data, regs))
cpu_pmu->disable(event);
}
irq_work_run();
pmnc = xscale2pmu_read_pmnc() | XSCALE_PMU_ENABLE;
xscale2pmu_write_pmnc(pmnc);
return IRQ_HANDLED;
}
static void xscale2pmu_enable_event(struct perf_event *event)
{
unsigned long flags, ien, evtsel;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
int idx = hwc->idx;
ien = xscale2pmu_read_int_enable();
evtsel = xscale2pmu_read_event_select();
switch (idx) {
case XSCALE_CYCLE_COUNTER:
ien |= XSCALE2_CCOUNT_INT_EN;
break;
case XSCALE_COUNTER0:
ien |= XSCALE2_COUNT0_INT_EN;
evtsel &= ~XSCALE2_COUNT0_EVT_MASK;
evtsel |= hwc->config_base << XSCALE2_COUNT0_EVT_SHFT;
break;
case XSCALE_COUNTER1:
ien |= XSCALE2_COUNT1_INT_EN;
evtsel &= ~XSCALE2_COUNT1_EVT_MASK;
evtsel |= hwc->config_base << XSCALE2_COUNT1_EVT_SHFT;
break;
case XSCALE_COUNTER2:
ien |= XSCALE2_COUNT2_INT_EN;
evtsel &= ~XSCALE2_COUNT2_EVT_MASK;
evtsel |= hwc->config_base << XSCALE2_COUNT2_EVT_SHFT;
break;
case XSCALE_COUNTER3:
ien |= XSCALE2_COUNT3_INT_EN;
evtsel &= ~XSCALE2_COUNT3_EVT_MASK;
evtsel |= hwc->config_base << XSCALE2_COUNT3_EVT_SHFT;
break;
default:
WARN_ONCE(1, "invalid counter number (%d)\n", idx);
return;
}
raw_spin_lock_irqsave(&events->pmu_lock, flags);
xscale2pmu_write_event_select(evtsel);
xscale2pmu_write_int_enable(ien);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void xscale2pmu_disable_event(struct perf_event *event)
{
unsigned long flags, ien, evtsel, of_flags;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
int idx = hwc->idx;
ien = xscale2pmu_read_int_enable();
evtsel = xscale2pmu_read_event_select();
switch (idx) {
case XSCALE_CYCLE_COUNTER:
ien &= ~XSCALE2_CCOUNT_INT_EN;
of_flags = XSCALE2_CCOUNT_OVERFLOW;
break;
case XSCALE_COUNTER0:
ien &= ~XSCALE2_COUNT0_INT_EN;
evtsel &= ~XSCALE2_COUNT0_EVT_MASK;
evtsel |= XSCALE_PERFCTR_UNUSED << XSCALE2_COUNT0_EVT_SHFT;
of_flags = XSCALE2_COUNT0_OVERFLOW;
break;
case XSCALE_COUNTER1:
ien &= ~XSCALE2_COUNT1_INT_EN;
evtsel &= ~XSCALE2_COUNT1_EVT_MASK;
evtsel |= XSCALE_PERFCTR_UNUSED << XSCALE2_COUNT1_EVT_SHFT;
of_flags = XSCALE2_COUNT1_OVERFLOW;
break;
case XSCALE_COUNTER2:
ien &= ~XSCALE2_COUNT2_INT_EN;
evtsel &= ~XSCALE2_COUNT2_EVT_MASK;
evtsel |= XSCALE_PERFCTR_UNUSED << XSCALE2_COUNT2_EVT_SHFT;
of_flags = XSCALE2_COUNT2_OVERFLOW;
break;
case XSCALE_COUNTER3:
ien &= ~XSCALE2_COUNT3_INT_EN;
evtsel &= ~XSCALE2_COUNT3_EVT_MASK;
evtsel |= XSCALE_PERFCTR_UNUSED << XSCALE2_COUNT3_EVT_SHFT;
of_flags = XSCALE2_COUNT3_OVERFLOW;
break;
default:
WARN_ONCE(1, "invalid counter number (%d)\n", idx);
return;
}
raw_spin_lock_irqsave(&events->pmu_lock, flags);
xscale2pmu_write_event_select(evtsel);
xscale2pmu_write_int_enable(ien);
xscale2pmu_write_overflow_flags(of_flags);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static int
xscale2pmu_get_event_idx(struct pmu_hw_events *cpuc,
struct perf_event *event)
{
int idx = xscale1pmu_get_event_idx(cpuc, event);
if (idx >= 0)
goto out;
if (!test_and_set_bit(XSCALE_COUNTER3, cpuc->used_mask))
idx = XSCALE_COUNTER3;
else if (!test_and_set_bit(XSCALE_COUNTER2, cpuc->used_mask))
idx = XSCALE_COUNTER2;
out:
return idx;
}
static void xscale2pmu_start(struct arm_pmu *cpu_pmu)
{
unsigned long flags, val;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = xscale2pmu_read_pmnc() & ~XSCALE_PMU_CNT64;
val |= XSCALE_PMU_ENABLE;
xscale2pmu_write_pmnc(val);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void xscale2pmu_stop(struct arm_pmu *cpu_pmu)
{
unsigned long flags, val;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = xscale2pmu_read_pmnc();
val &= ~XSCALE_PMU_ENABLE;
xscale2pmu_write_pmnc(val);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static inline u32 xscale2pmu_read_counter(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
int counter = hwc->idx;
u32 val = 0;
switch (counter) {
case XSCALE_CYCLE_COUNTER:
asm volatile("mrc p14, 0, %0, c1, c1, 0" : "=r" (val));
break;
case XSCALE_COUNTER0:
asm volatile("mrc p14, 0, %0, c0, c2, 0" : "=r" (val));
break;
case XSCALE_COUNTER1:
asm volatile("mrc p14, 0, %0, c1, c2, 0" : "=r" (val));
break;
case XSCALE_COUNTER2:
asm volatile("mrc p14, 0, %0, c2, c2, 0" : "=r" (val));
break;
case XSCALE_COUNTER3:
asm volatile("mrc p14, 0, %0, c3, c2, 0" : "=r" (val));
break;
}
return val;
}
static inline void xscale2pmu_write_counter(struct perf_event *event, u32 val)
{
struct hw_perf_event *hwc = &event->hw;
int counter = hwc->idx;
switch (counter) {
case XSCALE_CYCLE_COUNTER:
asm volatile("mcr p14, 0, %0, c1, c1, 0" : : "r" (val));
break;
case XSCALE_COUNTER0:
asm volatile("mcr p14, 0, %0, c0, c2, 0" : : "r" (val));
break;
case XSCALE_COUNTER1:
asm volatile("mcr p14, 0, %0, c1, c2, 0" : : "r" (val));
break;
case XSCALE_COUNTER2:
asm volatile("mcr p14, 0, %0, c2, c2, 0" : : "r" (val));
break;
case XSCALE_COUNTER3:
asm volatile("mcr p14, 0, %0, c3, c2, 0" : : "r" (val));
break;
}
}
static int xscale2pmu_init(struct arm_pmu *cpu_pmu)
{
cpu_pmu->name = "armv5_xscale2";
cpu_pmu->handle_irq = xscale2pmu_handle_irq;
cpu_pmu->enable = xscale2pmu_enable_event;
cpu_pmu->disable = xscale2pmu_disable_event;
cpu_pmu->read_counter = xscale2pmu_read_counter;
cpu_pmu->write_counter = xscale2pmu_write_counter;
cpu_pmu->get_event_idx = xscale2pmu_get_event_idx;
cpu_pmu->start = xscale2pmu_start;
cpu_pmu->stop = xscale2pmu_stop;
cpu_pmu->map_event = xscale_map_event;
cpu_pmu->num_events = 5;
cpu_pmu->max_period = (1LLU << 32) - 1;
return 0;
}
static inline int xscale1pmu_init(struct arm_pmu *cpu_pmu)
{
return -ENODEV;
}
static inline int xscale2pmu_init(struct arm_pmu *cpu_pmu)
{
return -ENODEV;
}
