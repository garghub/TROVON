static int
rtas_ibm_cbe_perftools(int subfunc, int passthru,
void *address, unsigned long length)
{
u64 paddr = __pa(address);
return rtas_call(pm_rtas_token, 5, 1, NULL, subfunc,
passthru, paddr >> 32, paddr & 0xffffffff, length);
}
static void pm_rtas_reset_signals(u32 node)
{
int ret;
struct pm_signal pm_signal_local;
pm_signal_local.cpu = node;
pm_signal_local.signal_group = 21;
pm_signal_local.bus_word = 1;
pm_signal_local.sub_unit = 0;
pm_signal_local.bit = 0;
ret = rtas_ibm_cbe_perftools(SUBFUNC_RESET, PASSTHRU_DISABLE,
&pm_signal_local,
sizeof(struct pm_signal));
if (unlikely(ret))
printk(KERN_WARNING "%s: rtas returned: %d\n",
__func__, ret);
}
static int pm_rtas_activate_signals(u32 node, u32 count)
{
int ret;
int i, j;
struct pm_signal pm_signal_local[NR_PHYS_CTRS];
i = 0;
for (j = 0; j < count; j++) {
if (pm_signal[j].signal_group != PPU_CYCLES_GRP_NUM) {
pm_signal_local[i].cpu = node;
pm_signal_local[i].signal_group
= pm_signal[j].signal_group;
pm_signal_local[i].bus_word = pm_signal[j].bus_word;
pm_signal_local[i].sub_unit = pm_signal[j].sub_unit;
pm_signal_local[i].bit = pm_signal[j].bit;
i++;
}
}
if (i != 0) {
ret = rtas_ibm_cbe_perftools(SUBFUNC_ACTIVATE, PASSTHRU_ENABLE,
pm_signal_local,
i * sizeof(struct pm_signal));
if (unlikely(ret)) {
printk(KERN_WARNING "%s: rtas returned: %d\n",
__func__, ret);
return -EIO;
}
}
return 0;
}
static void set_pm_event(u32 ctr, int event, u32 unit_mask)
{
struct pm_signal *p;
u32 signal_bit;
u32 bus_word, bus_type, count_cycles, polarity, input_control;
int j, i;
if (event == PPU_CYCLES_EVENT_NUM) {
pm_regs.pm07_cntrl[ctr] = CBE_COUNT_ALL_CYCLES;
p = &(pm_signal[ctr]);
p->signal_group = PPU_CYCLES_GRP_NUM;
p->bus_word = 1;
p->sub_unit = 0;
p->bit = 0;
goto out;
} else {
pm_regs.pm07_cntrl[ctr] = 0;
}
bus_word = GET_BUS_WORD(unit_mask);
bus_type = GET_BUS_TYPE(unit_mask);
count_cycles = GET_COUNT_CYCLES(unit_mask);
polarity = GET_POLARITY(unit_mask);
input_control = GET_INPUT_CONTROL(unit_mask);
signal_bit = (event % 100);
p = &(pm_signal[ctr]);
p->signal_group = event / 100;
p->bus_word = bus_word;
p->sub_unit = GET_SUB_UNIT(unit_mask);
pm_regs.pm07_cntrl[ctr] = 0;
pm_regs.pm07_cntrl[ctr] |= PM07_CTR_COUNT_CYCLES(count_cycles);
pm_regs.pm07_cntrl[ctr] |= PM07_CTR_POLARITY(polarity);
pm_regs.pm07_cntrl[ctr] |= PM07_CTR_INPUT_CONTROL(input_control);
if (input_control == 0) {
if (signal_bit > 31) {
signal_bit -= 32;
if (bus_word == 0x3)
bus_word = 0x2;
else if (bus_word == 0xc)
bus_word = 0x8;
}
if ((bus_type == 0) && p->signal_group >= 60)
bus_type = 2;
if ((bus_type == 1) && p->signal_group >= 50)
bus_type = 0;
pm_regs.pm07_cntrl[ctr] |= PM07_CTR_INPUT_MUX(signal_bit);
} else {
pm_regs.pm07_cntrl[ctr] = 0;
p->bit = signal_bit;
}
for (i = 0; i < NUM_DEBUG_BUS_WORDS; i++) {
if (bus_word & (1 << i)) {
pm_regs.debug_bus_control |=
(bus_type << (30 - (2 * i)));
for (j = 0; j < NUM_INPUT_BUS_WORDS; j++) {
if (input_bus[j] == 0xff) {
input_bus[j] = i;
pm_regs.group_control |=
(i << (30 - (2 * j)));
break;
}
}
}
}
out:
;
}
static void write_pm_cntrl(int cpu)
{
u32 val = 0;
if (pm_regs.pm_cntrl.enable == 1)
val |= CBE_PM_ENABLE_PERF_MON;
if (pm_regs.pm_cntrl.stop_at_max == 1)
val |= CBE_PM_STOP_AT_MAX;
if (pm_regs.pm_cntrl.trace_mode != 0)
val |= CBE_PM_TRACE_MODE_SET(pm_regs.pm_cntrl.trace_mode);
if (pm_regs.pm_cntrl.trace_buf_ovflw == 1)
val |= CBE_PM_TRACE_BUF_OVFLW(pm_regs.pm_cntrl.trace_buf_ovflw);
if (pm_regs.pm_cntrl.freeze == 1)
val |= CBE_PM_FREEZE_ALL_CTRS;
val |= CBE_PM_SPU_ADDR_TRACE_SET(pm_regs.pm_cntrl.spu_addr_trace);
val |= CBE_PM_COUNT_MODE_SET(pm_regs.pm_cntrl.count_mode);
cbe_write_pm(cpu, pm_control, val);
}
static inline void
set_count_mode(u32 kernel, u32 user)
{
if (kernel) {
if (user)
pm_regs.pm_cntrl.count_mode = CBE_COUNT_ALL_MODES;
else
pm_regs.pm_cntrl.count_mode =
CBE_COUNT_SUPERVISOR_MODE;
} else {
if (user)
pm_regs.pm_cntrl.count_mode = CBE_COUNT_PROBLEM_MODE;
else
pm_regs.pm_cntrl.count_mode =
CBE_COUNT_HYPERVISOR_MODE;
}
}
static inline void enable_ctr(u32 cpu, u32 ctr, u32 *pm07_cntrl)
{
pm07_cntrl[ctr] |= CBE_PM_CTR_ENABLE;
cbe_write_pm07_control(cpu, ctr, pm07_cntrl[ctr]);
}
static void cell_virtual_cntr(unsigned long data)
{
int i, prev_hdw_thread, next_hdw_thread;
u32 cpu;
unsigned long flags;
spin_lock_irqsave(&cntr_lock, flags);
prev_hdw_thread = hdw_thread;
hdw_thread = 1 ^ hdw_thread;
next_hdw_thread = hdw_thread;
pm_regs.group_control = 0;
pm_regs.debug_bus_control = 0;
for (i = 0; i < NUM_INPUT_BUS_WORDS; i++)
input_bus[i] = 0xff;
for (i = 0; i < num_counters; i++)
set_pm_event(i,
pmc_cntrl[next_hdw_thread][i].evnts,
pmc_cntrl[next_hdw_thread][i].masks);
for_each_online_cpu(cpu) {
if (cbe_get_hw_thread_id(cpu))
continue;
cbe_disable_pm(cpu);
cbe_disable_pm_interrupts(cpu);
for (i = 0; i < num_counters; i++) {
per_cpu(pmc_values, cpu + prev_hdw_thread)[i]
= cbe_read_ctr(cpu, i);
if (per_cpu(pmc_values, cpu + next_hdw_thread)[i]
== 0xFFFFFFFF)
cbe_write_ctr(cpu, i, 0xFFFFFFF0);
else
cbe_write_ctr(cpu, i,
per_cpu(pmc_values,
cpu +
next_hdw_thread)[i]);
}
for (i = 0; i < num_counters; i++) {
if (pmc_cntrl[next_hdw_thread][i].enabled) {
enable_ctr(cpu, i,
pm_regs.pm07_cntrl);
} else {
cbe_write_pm07_control(cpu, i, 0);
}
}
cbe_enable_pm_interrupts(cpu, next_hdw_thread,
virt_cntr_inter_mask);
cbe_enable_pm(cpu);
}
spin_unlock_irqrestore(&cntr_lock, flags);
mod_timer(&timer_virt_cntr, jiffies + HZ / 10);
}
static void start_virt_cntrs(void)
{
init_timer(&timer_virt_cntr);
timer_virt_cntr.function = cell_virtual_cntr;
timer_virt_cntr.data = 0UL;
timer_virt_cntr.expires = jiffies + HZ / 10;
add_timer(&timer_virt_cntr);
}
static int cell_reg_setup_spu_cycles(struct op_counter_config *ctr,
struct op_system_config *sys, int num_ctrs)
{
spu_cycle_reset = ctr[0].count;
spu_rtas_token = rtas_token("ibm,cbe-spu-perftools");
if (unlikely(spu_rtas_token == RTAS_UNKNOWN_SERVICE)) {
printk(KERN_ERR
"%s: rtas token ibm,cbe-spu-perftools unknown\n",
__func__);
return -EIO;
}
return 0;
}
static void spu_evnt_swap(unsigned long data)
{
int node;
int cur_phys_spu, nxt_phys_spu, cur_spu_evnt_phys_spu_indx;
unsigned long flags;
int cpu;
int ret;
u32 interrupt_mask;
interrupt_mask = CBE_PM_CTR_OVERFLOW_INTR(0);
hdw_thread = 0;
spin_lock_irqsave(&cntr_lock, flags);
cur_spu_evnt_phys_spu_indx = spu_evnt_phys_spu_indx;
if (++(spu_evnt_phys_spu_indx) == NUM_SPUS_PER_NODE)
spu_evnt_phys_spu_indx = 0;
pm_signal[0].sub_unit = spu_evnt_phys_spu_indx;
pm_signal[1].sub_unit = spu_evnt_phys_spu_indx;
pm_signal[2].sub_unit = spu_evnt_phys_spu_indx;
for_each_online_cpu(cpu) {
if (cbe_get_hw_thread_id(cpu))
continue;
node = cbe_cpu_to_node(cpu);
cur_phys_spu = (node * NUM_SPUS_PER_NODE)
+ cur_spu_evnt_phys_spu_indx;
nxt_phys_spu = (node * NUM_SPUS_PER_NODE)
+ spu_evnt_phys_spu_indx;
cbe_disable_pm(cpu);
cbe_disable_pm_interrupts(cpu);
spu_pm_cnt[cur_phys_spu]
= cbe_read_ctr(cpu, 0);
if (spu_pm_cnt[nxt_phys_spu] >= 0xFFFFFFFF)
cbe_write_ctr(cpu, 0, 0xFFFFFFF0);
else
cbe_write_ctr(cpu, 0, spu_pm_cnt[nxt_phys_spu]);
pm_rtas_reset_signals(cbe_cpu_to_node(cpu));
ret = pm_rtas_activate_signals(cbe_cpu_to_node(cpu), 3);
if (ret)
printk(KERN_ERR "%s: pm_rtas_activate_signals failed, "
"SPU event swap\n", __func__);
cbe_write_pm(cpu, trace_address, 0);
enable_ctr(cpu, 0, pm_regs.pm07_cntrl);
cbe_enable_pm_interrupts(cpu, hdw_thread,
interrupt_mask);
cbe_enable_pm(cpu);
}
spin_unlock_irqrestore(&cntr_lock, flags);
mod_timer(&timer_spu_event_swap, jiffies + HZ / 25);
}
static void start_spu_event_swap(void)
{
init_timer(&timer_spu_event_swap);
timer_spu_event_swap.function = spu_evnt_swap;
timer_spu_event_swap.data = 0UL;
timer_spu_event_swap.expires = jiffies + HZ / 25;
add_timer(&timer_spu_event_swap);
}
static int cell_reg_setup_spu_events(struct op_counter_config *ctr,
struct op_system_config *sys, int num_ctrs)
{
int i;
spu_evnt_phys_spu_indx = 0;
pm_rtas_token = rtas_token("ibm,cbe-perftools");
if (unlikely(pm_rtas_token == RTAS_UNKNOWN_SERVICE)) {
printk(KERN_ERR
"%s: rtas token ibm,cbe-perftools unknown\n",
__func__);
return -EIO;
}
pm_regs.pm_cntrl.trace_buf_ovflw = 1;
pm_regs.pm_cntrl.trace_mode = 2;
pm_regs.pm_cntrl.spu_addr_trace = 0x1;
pm_signal[1].signal_group = SPU_PROFILE_EVENT_ADDR / 100;
pm_signal[1].bus_word = GET_BUS_WORD(SPU_PROFILE_EVENT_ADDR_MASK_A);
pm_signal[1].bit = SPU_PROFILE_EVENT_ADDR % 100;
pm_signal[1].sub_unit = spu_evnt_phys_spu_indx;
pm_signal[2].signal_group = SPU_PROFILE_EVENT_ADDR / 100;
pm_signal[2].bus_word = GET_BUS_WORD(SPU_PROFILE_EVENT_ADDR_MASK_B);
pm_signal[2].bit = SPU_PROFILE_EVENT_ADDR % 100;
pm_signal[2].sub_unit = spu_evnt_phys_spu_indx;
num_counters = 1;
set_pm_event(0, ctr[0].event, ctr[0].unit_mask);
reset_value[0] = 0xFFFFFFFF - ctr[0].count;
ctr_enabled |= 1;
for (i=0; i < MAX_NUMNODES * NUM_SPUS_PER_NODE; i++)
spu_pm_cnt[i] = reset_value[0];
return 0;
}
static int cell_reg_setup_ppu(struct op_counter_config *ctr,
struct op_system_config *sys, int num_ctrs)
{
int i, j, cpu;
num_counters = num_ctrs;
if (unlikely(num_ctrs > NR_PHYS_CTRS)) {
printk(KERN_ERR
"%s: Oprofile, number of specified events " \
"exceeds number of physical counters\n",
__func__);
return -EIO;
}
set_count_mode(sys->enable_kernel, sys->enable_user);
for (i = 0; i < num_ctrs; ++i) {
pmc_cntrl[0][i].evnts = ctr[i].event;
pmc_cntrl[0][i].masks = ctr[i].unit_mask;
pmc_cntrl[0][i].enabled = ctr[i].enabled;
pmc_cntrl[0][i].vcntr = i;
for_each_possible_cpu(j)
per_cpu(pmc_values, j)[i] = 0;
}
for (i = 0; i < num_ctrs; ++i) {
if ((ctr[i].event >= 2100) && (ctr[i].event <= 2111))
pmc_cntrl[1][i].evnts = ctr[i].event + 19;
else if (ctr[i].event == 2203)
pmc_cntrl[1][i].evnts = ctr[i].event;
else if ((ctr[i].event >= 2200) && (ctr[i].event <= 2215))
pmc_cntrl[1][i].evnts = ctr[i].event + 16;
else
pmc_cntrl[1][i].evnts = ctr[i].event;
pmc_cntrl[1][i].masks = ctr[i].unit_mask;
pmc_cntrl[1][i].enabled = ctr[i].enabled;
pmc_cntrl[1][i].vcntr = i;
}
for (i = 0; i < NUM_INPUT_BUS_WORDS; i++)
input_bus[i] = 0xff;
for (i = 0; i < num_counters; ++i) {
if (pmc_cntrl[0][i].enabled) {
reset_value[i] = 0xFFFFFFFF - ctr[i].count;
set_pm_event(i,
pmc_cntrl[0][i].evnts,
pmc_cntrl[0][i].masks);
ctr_enabled |= (1 << i);
}
}
for_each_online_cpu(cpu)
for (i = 0; i < num_counters; ++i) {
per_cpu(pmc_values, cpu)[i] = reset_value[i];
}
return 0;
}
static int cell_reg_setup(struct op_counter_config *ctr,
struct op_system_config *sys, int num_ctrs)
{
int ret=0;
spu_cycle_reset = 0;
pm_regs.group_control = 0;
pm_regs.debug_bus_control = 0;
pm_regs.pm_cntrl.stop_at_max = 1;
pm_regs.pm_cntrl.trace_mode = 0;
pm_regs.pm_cntrl.freeze = 1;
pm_regs.pm_cntrl.trace_buf_ovflw = 0;
pm_regs.pm_cntrl.spu_addr_trace = 0;
pm_rtas_token = rtas_token("ibm,cbe-perftools");
if (unlikely(pm_rtas_token == RTAS_UNKNOWN_SERVICE)) {
printk(KERN_ERR
"%s: rtas token ibm,cbe-perftools unknown\n",
__func__);
return -EIO;
}
if (ctr[0].event == SPU_CYCLES_EVENT_NUM) {
profiling_mode = SPU_PROFILING_CYCLES;
ret = cell_reg_setup_spu_cycles(ctr, sys, num_ctrs);
} else if ((ctr[0].event >= SPU_EVENT_NUM_START) &&
(ctr[0].event <= SPU_EVENT_NUM_STOP)) {
profiling_mode = SPU_PROFILING_EVENTS;
spu_cycle_reset = ctr[0].count;
cell_reg_setup_spu_events(ctr, sys, num_ctrs);
} else {
profiling_mode = PPU_PROFILING;
ret = cell_reg_setup_ppu(ctr, sys, num_ctrs);
}
return ret;
}
static int cell_cpu_setup(struct op_counter_config *cntr)
{
u32 cpu = smp_processor_id();
u32 num_enabled = 0;
int i;
int ret;
if (profiling_mode == SPU_PROFILING_CYCLES)
return 0;
if (cbe_get_hw_thread_id(cpu))
return 0;
cbe_disable_pm(cpu);
cbe_disable_pm_interrupts(cpu);
cbe_write_pm(cpu, pm_start_stop, 0);
cbe_write_pm(cpu, group_control, pm_regs.group_control);
cbe_write_pm(cpu, debug_bus_control, pm_regs.debug_bus_control);
write_pm_cntrl(cpu);
for (i = 0; i < num_counters; ++i) {
if (ctr_enabled & (1 << i)) {
pm_signal[num_enabled].cpu = cbe_cpu_to_node(cpu);
num_enabled++;
}
}
if (profiling_mode == SPU_PROFILING_EVENTS) {
ret = pm_rtas_activate_signals(cbe_cpu_to_node(cpu),
num_enabled+2);
cbe_write_pm(cpu, pm_interval, NUM_INTERVAL_CYC);
return ret;
} else
return pm_rtas_activate_signals(cbe_cpu_to_node(cpu),
num_enabled);
}
static int calculate_lfsr(int n)
{
int index;
if ((n >> 16) == 0)
index = 0;
else if (((n - V2_16) >> 19) == 0)
index = ((n - V2_16) >> 12) + 1;
else if (((n - V2_16 - V2_19) >> 22) == 0)
index = ((n - V2_16 - V2_19) >> 15 ) + 1 + 128;
else if (((n - V2_16 - V2_19 - V2_22) >> 24) == 0)
index = ((n - V2_16 - V2_19 - V2_22) >> 18 ) + 1 + 256;
else
index = ENTRIES-1;
if ((index >= ENTRIES) || (index < 0))
index = ENTRIES-1;
return initial_lfsr[index];
}
static int pm_rtas_activate_spu_profiling(u32 node)
{
int ret, i;
struct pm_signal pm_signal_local[NUM_SPUS_PER_NODE];
for (i = 0; i < ARRAY_SIZE(pm_signal_local); i++) {
pm_signal_local[i].cpu = node;
pm_signal_local[i].signal_group = 41;
pm_signal_local[i].bus_word = 1 << i / 2;
pm_signal_local[i].sub_unit = i;
pm_signal_local[i].bit = 63;
}
ret = rtas_ibm_cbe_perftools(SUBFUNC_ACTIVATE,
PASSTHRU_ENABLE, pm_signal_local,
(ARRAY_SIZE(pm_signal_local)
* sizeof(struct pm_signal)));
if (unlikely(ret)) {
printk(KERN_WARNING "%s: rtas returned: %d\n",
__func__, ret);
return -EIO;
}
return 0;
}
static int
oprof_cpufreq_notify(struct notifier_block *nb, unsigned long val, void *data)
{
int ret = 0;
struct cpufreq_freqs *frq = data;
if ((val == CPUFREQ_PRECHANGE && frq->old < frq->new) ||
(val == CPUFREQ_POSTCHANGE && frq->old > frq->new) ||
(val == CPUFREQ_RESUMECHANGE || val == CPUFREQ_SUSPENDCHANGE))
set_spu_profiling_frequency(frq->new, spu_cycle_reset);
return ret;
}
static void cell_global_stop_spu_cycles(void)
{
int subfunc, rtn_value;
unsigned int lfsr_value;
int cpu;
oprofile_running = 0;
smp_wmb();
#ifdef CONFIG_CPU_FREQ
cpufreq_unregister_notifier(&cpu_freq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
#endif
for_each_online_cpu(cpu) {
if (cbe_get_hw_thread_id(cpu))
continue;
subfunc = 3;
lfsr_value = 0x8f100000;
rtn_value = rtas_call(spu_rtas_token, 3, 1, NULL,
subfunc, cbe_cpu_to_node(cpu),
lfsr_value);
if (unlikely(rtn_value != 0)) {
printk(KERN_ERR
"%s: rtas call ibm,cbe-spu-perftools " \
"failed, return = %d\n",
__func__, rtn_value);
}
pm_rtas_reset_signals(cbe_cpu_to_node(cpu));
}
stop_spu_profiling_cycles();
}
static void cell_global_stop_spu_events(void)
{
int cpu;
oprofile_running = 0;
stop_spu_profiling_events();
smp_wmb();
for_each_online_cpu(cpu) {
if (cbe_get_hw_thread_id(cpu))
continue;
cbe_sync_irq(cbe_cpu_to_node(cpu));
cbe_disable_pm(cpu);
cbe_write_pm07_control(cpu, 0, 0);
pm_rtas_reset_signals(cbe_cpu_to_node(cpu));
cbe_disable_pm_interrupts(cpu);
}
del_timer_sync(&timer_spu_event_swap);
}
static void cell_global_stop_ppu(void)
{
int cpu;
del_timer_sync(&timer_virt_cntr);
oprofile_running = 0;
smp_wmb();
for_each_online_cpu(cpu) {
if (cbe_get_hw_thread_id(cpu))
continue;
cbe_sync_irq(cbe_cpu_to_node(cpu));
cbe_disable_pm(cpu);
pm_rtas_reset_signals(cbe_cpu_to_node(cpu));
cbe_disable_pm_interrupts(cpu);
}
}
static void cell_global_stop(void)
{
if (profiling_mode == PPU_PROFILING)
cell_global_stop_ppu();
else if (profiling_mode == SPU_PROFILING_EVENTS)
cell_global_stop_spu_events();
else
cell_global_stop_spu_cycles();
}
static int cell_global_start_spu_cycles(struct op_counter_config *ctr)
{
int subfunc;
unsigned int lfsr_value;
int cpu;
int ret;
int rtas_error;
unsigned int cpu_khzfreq = 0;
#ifdef CONFIG_CPU_FREQ
ret = cpufreq_register_notifier(&cpu_freq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
if (ret < 0)
printk(KERN_ERR "CPU freq change registration failed: %d\n",
ret);
else
cpu_khzfreq = cpufreq_quick_get(smp_processor_id());
#endif
set_spu_profiling_frequency(cpu_khzfreq, spu_cycle_reset);
for_each_online_cpu(cpu) {
if (cbe_get_hw_thread_id(cpu))
continue;
cbe_write_pm(cpu, pm_control, 0);
if (spu_cycle_reset > MAX_SPU_COUNT)
lfsr_value = calculate_lfsr(MAX_SPU_COUNT-1);
else
lfsr_value = calculate_lfsr(spu_cycle_reset);
if (lfsr_value == 0)
lfsr_value = calculate_lfsr(1);
lfsr_value = lfsr_value << 8;
ret = pm_rtas_activate_spu_profiling(cbe_cpu_to_node(cpu));
if (unlikely(ret)) {
rtas_error = ret;
goto out;
}
subfunc = 2;
ret = rtas_call(spu_rtas_token, 3, 1, NULL, subfunc,
cbe_cpu_to_node(cpu), lfsr_value);
if (unlikely(ret != 0)) {
printk(KERN_ERR
"%s: rtas call ibm,cbe-spu-perftools failed, " \
"return = %d\n", __func__, ret);
rtas_error = -EIO;
goto out;
}
}
rtas_error = start_spu_profiling_cycles(spu_cycle_reset);
if (rtas_error)
goto out_stop;
oprofile_running = 1;
return 0;
out_stop:
cell_global_stop_spu_cycles();
out:
return rtas_error;
}
static int cell_global_start_spu_events(struct op_counter_config *ctr)
{
int cpu;
u32 interrupt_mask = 0;
int rtn = 0;
hdw_thread = 0;
for_each_online_cpu(cpu) {
if (cbe_get_hw_thread_id(cpu))
continue;
if (ctr_enabled & 1) {
cbe_write_ctr(cpu, 0, reset_value[0]);
enable_ctr(cpu, 0, pm_regs.pm07_cntrl);
interrupt_mask |=
CBE_PM_CTR_OVERFLOW_INTR(0);
} else {
cbe_write_pm07_control(cpu, 0, 0);
}
cbe_get_and_clear_pm_interrupts(cpu);
cbe_enable_pm_interrupts(cpu, hdw_thread, interrupt_mask);
cbe_enable_pm(cpu);
cbe_write_pm(cpu, trace_address, 0);
}
start_spu_event_swap();
start_spu_profiling_events();
oprofile_running = 1;
smp_wmb();
return rtn;
}
static int cell_global_start_ppu(struct op_counter_config *ctr)
{
u32 cpu, i;
u32 interrupt_mask = 0;
for_each_online_cpu(cpu) {
if (cbe_get_hw_thread_id(cpu))
continue;
interrupt_mask = 0;
for (i = 0; i < num_counters; ++i) {
if (ctr_enabled & (1 << i)) {
cbe_write_ctr(cpu, i, reset_value[i]);
enable_ctr(cpu, i, pm_regs.pm07_cntrl);
interrupt_mask |= CBE_PM_CTR_OVERFLOW_INTR(i);
} else {
cbe_write_pm07_control(cpu, i, 0);
}
}
cbe_get_and_clear_pm_interrupts(cpu);
cbe_enable_pm_interrupts(cpu, hdw_thread, interrupt_mask);
cbe_enable_pm(cpu);
}
virt_cntr_inter_mask = interrupt_mask;
oprofile_running = 1;
smp_wmb();
start_virt_cntrs();
return 0;
}
static int cell_global_start(struct op_counter_config *ctr)
{
if (profiling_mode == SPU_PROFILING_CYCLES)
return cell_global_start_spu_cycles(ctr);
else if (profiling_mode == SPU_PROFILING_EVENTS)
return cell_global_start_spu_events(ctr);
else
return cell_global_start_ppu(ctr);
}
static void cell_handle_interrupt_spu(struct pt_regs *regs,
struct op_counter_config *ctr)
{
u32 cpu, cpu_tmp;
u64 trace_entry;
u32 interrupt_mask;
u64 trace_buffer[2];
u64 last_trace_buffer;
u32 sample;
u32 trace_addr;
unsigned long sample_array_lock_flags;
int spu_num;
unsigned long flags;
cpu = smp_processor_id();
spin_lock_irqsave(&cntr_lock, flags);
cpu_tmp = cpu;
cbe_disable_pm(cpu);
interrupt_mask = cbe_get_and_clear_pm_interrupts(cpu);
sample = 0xABCDEF;
trace_entry = 0xfedcba;
last_trace_buffer = 0xdeadbeaf;
if ((oprofile_running == 1) && (interrupt_mask != 0)) {
cbe_write_pm(cpu, pm_interval, 0);
if ((interrupt_mask & CBE_PM_CTR_OVERFLOW_INTR(0))
&& ctr[0].enabled)
cbe_write_ctr(cpu, 0, reset_value[0]);
trace_addr = cbe_read_pm(cpu, trace_address);
while (!(trace_addr & CBE_PM_TRACE_BUF_EMPTY)) {
cbe_read_trace_buffer(cpu, trace_buffer);
trace_addr = cbe_read_pm(cpu, trace_address);
}
trace_entry = trace_buffer[0]
& 0x00000000FFFF0000;
sample = trace_entry >> 14;
last_trace_buffer = trace_buffer[0];
spu_num = spu_evnt_phys_spu_indx
+ (cbe_cpu_to_node(cpu) * NUM_SPUS_PER_NODE);
spin_lock_irqsave(&oprof_spu_smpl_arry_lck,
sample_array_lock_flags);
spu_sync_buffer(spu_num, &sample, 1);
spin_unlock_irqrestore(&oprof_spu_smpl_arry_lck,
sample_array_lock_flags);
smp_wmb();
cbe_write_pm(cpu, pm_interval, NUM_INTERVAL_CYC);
cbe_enable_pm_interrupts(cpu, hdw_thread,
virt_cntr_inter_mask);
cbe_write_pm(cpu, trace_address, 0);
cbe_write_pm(cpu, pm_interval, NUM_INTERVAL_CYC);
write_pm_cntrl(cpu);
cbe_enable_pm(cpu);
}
spin_unlock_irqrestore(&cntr_lock, flags);
}
static void cell_handle_interrupt_ppu(struct pt_regs *regs,
struct op_counter_config *ctr)
{
u32 cpu;
u64 pc;
int is_kernel;
unsigned long flags = 0;
u32 interrupt_mask;
int i;
cpu = smp_processor_id();
spin_lock_irqsave(&cntr_lock, flags);
cbe_disable_pm(cpu);
interrupt_mask = cbe_get_and_clear_pm_interrupts(cpu);
if ((oprofile_running == 1) && (interrupt_mask != 0)) {
pc = regs->nip;
is_kernel = is_kernel_addr(pc);
for (i = 0; i < num_counters; ++i) {
if ((interrupt_mask & CBE_PM_CTR_OVERFLOW_INTR(i))
&& ctr[i].enabled) {
oprofile_add_ext_sample(pc, regs, i, is_kernel);
cbe_write_ctr(cpu, i, reset_value[i]);
}
}
cbe_enable_pm_interrupts(cpu, hdw_thread,
virt_cntr_inter_mask);
cbe_enable_pm(cpu);
}
spin_unlock_irqrestore(&cntr_lock, flags);
}
static void cell_handle_interrupt(struct pt_regs *regs,
struct op_counter_config *ctr)
{
if (profiling_mode == PPU_PROFILING)
cell_handle_interrupt_ppu(regs, ctr);
else
cell_handle_interrupt_spu(regs, ctr);
}
static int cell_sync_start(void)
{
if ((profiling_mode == SPU_PROFILING_CYCLES) ||
(profiling_mode == SPU_PROFILING_EVENTS))
return spu_sync_start();
else
return DO_GENERIC_SYNC;
}
static int cell_sync_stop(void)
{
if ((profiling_mode == SPU_PROFILING_CYCLES) ||
(profiling_mode == SPU_PROFILING_EVENTS))
return spu_sync_stop();
else
return 1;
}
