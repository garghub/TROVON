static int raw_cpu_stopped(int cpu)
{
u32 status;
switch (raw_sigp_ps(&status, 0, cpu, sigp_sense)) {
case sigp_status_stored:
if (status & 0x50)
return 1;
break;
default:
break;
}
return 0;
}
static inline int cpu_stopped(int cpu)
{
return raw_cpu_stopped(cpu_logical_map(cpu));
}
void smp_restart_with_online_cpu(void)
{
int cpu;
for_each_online_cpu(cpu) {
if (stap() == __cpu_logical_map[cpu]) {
__load_psw_mask(psw_kernel_bits | PSW_MASK_DAT);
return;
}
}
while (sigp(cpu, sigp_restart) == sigp_busy)
cpu_relax();
while (raw_sigp(stap(), sigp_stop) == sigp_busy)
cpu_relax();
for (;;);
}
void smp_switch_to_ipl_cpu(void (*func)(void *), void *data)
{
struct _lowcore *lc, *current_lc;
struct stack_frame *sf;
struct pt_regs *regs;
unsigned long sp;
if (smp_processor_id() == 0)
func(data);
__load_psw_mask(PSW_DEFAULT_KEY | PSW_MASK_BASE |
PSW_MASK_EA | PSW_MASK_BA);
__ctl_clear_bit(0, 28);
current_lc = lowcore_ptr[smp_processor_id()];
lc = lowcore_ptr[0];
if (!lc)
lc = current_lc;
lc->restart_psw.mask =
PSW_DEFAULT_KEY | PSW_MASK_BASE | PSW_MASK_EA | PSW_MASK_BA;
lc->restart_psw.addr = PSW_ADDR_AMODE | (unsigned long) smp_restart_cpu;
if (!cpu_online(0))
smp_switch_to_cpu(func, data, 0, stap(), __cpu_logical_map[0]);
while (sigp(0, sigp_stop_and_store_status) == sigp_busy)
cpu_relax();
sp = lc->panic_stack;
sp -= sizeof(struct pt_regs);
regs = (struct pt_regs *) sp;
memcpy(&regs->gprs, &current_lc->gpregs_save_area, sizeof(regs->gprs));
regs->psw = current_lc->psw_save_area;
sp -= STACK_FRAME_OVERHEAD;
sf = (struct stack_frame *) sp;
sf->back_chain = 0;
smp_switch_to_cpu(func, data, sp, stap(), __cpu_logical_map[0]);
}
static void smp_stop_cpu(void)
{
while (sigp(smp_processor_id(), sigp_stop) == sigp_busy)
cpu_relax();
}
void smp_send_stop(void)
{
cpumask_t cpumask;
int cpu;
u64 end;
__load_psw_mask(psw_kernel_bits | PSW_MASK_DAT);
trace_hardirqs_off();
cpumask_copy(&cpumask, cpu_online_mask);
cpumask_clear_cpu(smp_processor_id(), &cpumask);
if (oops_in_progress) {
end = get_clock() + (1000000UL << 12);
for_each_cpu(cpu, &cpumask) {
set_bit(ec_stop_cpu, (unsigned long *)
&lowcore_ptr[cpu]->ext_call_fast);
while (sigp(cpu, sigp_emergency_signal) == sigp_busy &&
get_clock() < end)
cpu_relax();
}
while (get_clock() < end) {
for_each_cpu(cpu, &cpumask)
if (cpu_stopped(cpu))
cpumask_clear_cpu(cpu, &cpumask);
if (cpumask_empty(&cpumask))
break;
cpu_relax();
}
}
for_each_cpu(cpu, &cpumask) {
while (sigp(cpu, sigp_stop) == sigp_busy)
cpu_relax();
while (!cpu_stopped(cpu))
cpu_relax();
}
}
static void do_ext_call_interrupt(unsigned int ext_int_code,
unsigned int param32, unsigned long param64)
{
unsigned long bits;
if ((ext_int_code & 0xffff) == 0x1202)
kstat_cpu(smp_processor_id()).irqs[EXTINT_EXC]++;
else
kstat_cpu(smp_processor_id()).irqs[EXTINT_EMS]++;
bits = xchg(&S390_lowcore.ext_call_fast, 0);
if (test_bit(ec_stop_cpu, &bits))
smp_stop_cpu();
if (test_bit(ec_schedule, &bits))
scheduler_ipi();
if (test_bit(ec_call_function, &bits))
generic_smp_call_function_interrupt();
if (test_bit(ec_call_function_single, &bits))
generic_smp_call_function_single_interrupt();
}
static void smp_ext_bitcall(int cpu, int sig)
{
int order;
set_bit(sig, (unsigned long *) &lowcore_ptr[cpu]->ext_call_fast);
while (1) {
order = smp_vcpu_scheduled(cpu) ?
sigp_external_call : sigp_emergency_signal;
if (sigp(cpu, order) != sigp_busy)
break;
udelay(10);
}
}
void arch_send_call_function_ipi_mask(const struct cpumask *mask)
{
int cpu;
for_each_cpu(cpu, mask)
smp_ext_bitcall(cpu, ec_call_function);
}
void arch_send_call_function_single_ipi(int cpu)
{
smp_ext_bitcall(cpu, ec_call_function_single);
}
static void smp_ptlb_callback(void *info)
{
__tlb_flush_local();
}
void smp_ptlb_all(void)
{
on_each_cpu(smp_ptlb_callback, NULL, 1);
}
void smp_send_reschedule(int cpu)
{
smp_ext_bitcall(cpu, ec_schedule);
}
static void smp_ctl_bit_callback(void *info)
{
struct ec_creg_mask_parms *pp = info;
unsigned long cregs[16];
int i;
__ctl_store(cregs, 0, 15);
for (i = 0; i <= 15; i++)
cregs[i] = (cregs[i] & pp->andvals[i]) | pp->orvals[i];
__ctl_load(cregs, 0, 15);
}
void smp_ctl_set_bit(int cr, int bit)
{
struct ec_creg_mask_parms parms;
memset(&parms.orvals, 0, sizeof(parms.orvals));
memset(&parms.andvals, 0xff, sizeof(parms.andvals));
parms.orvals[cr] = 1UL << bit;
on_each_cpu(smp_ctl_bit_callback, &parms, 1);
}
void smp_ctl_clear_bit(int cr, int bit)
{
struct ec_creg_mask_parms parms;
memset(&parms.orvals, 0, sizeof(parms.orvals));
memset(&parms.andvals, 0xff, sizeof(parms.andvals));
parms.andvals[cr] = ~(1UL << bit);
on_each_cpu(smp_ctl_bit_callback, &parms, 1);
}
static void __init smp_get_save_area(unsigned int cpu, unsigned int phy_cpu)
{
if (ipl_info.type != IPL_TYPE_FCP_DUMP && !OLDMEM_BASE)
return;
if (is_kdump_kernel())
return;
if (cpu >= NR_CPUS) {
pr_warning("CPU %i exceeds the maximum %i and is excluded from "
"the dump\n", cpu, NR_CPUS - 1);
return;
}
zfcpdump_save_areas[cpu] = kmalloc(sizeof(struct save_area), GFP_KERNEL);
while (raw_sigp(phy_cpu, sigp_stop_and_store_status) == sigp_busy)
cpu_relax();
memcpy_real(zfcpdump_save_areas[cpu],
(void *)(unsigned long) store_prefix() + SAVE_AREA_BASE,
sizeof(struct save_area));
}
static inline void smp_get_save_area(unsigned int cpu, unsigned int phy_cpu) { }
static int cpu_known(int cpu_id)
{
int cpu;
for_each_present_cpu(cpu) {
if (__cpu_logical_map[cpu] == cpu_id)
return 1;
}
return 0;
}
static int smp_rescan_cpus_sigp(cpumask_t avail)
{
int cpu_id, logical_cpu;
logical_cpu = cpumask_first(&avail);
if (logical_cpu >= nr_cpu_ids)
return 0;
for (cpu_id = 0; cpu_id <= MAX_CPU_ADDRESS; cpu_id++) {
if (cpu_known(cpu_id))
continue;
__cpu_logical_map[logical_cpu] = cpu_id;
cpu_set_polarization(logical_cpu, POLARIZATION_UNKNOWN);
if (!cpu_stopped(logical_cpu))
continue;
set_cpu_present(logical_cpu, true);
smp_cpu_state[logical_cpu] = CPU_STATE_CONFIGURED;
logical_cpu = cpumask_next(logical_cpu, &avail);
if (logical_cpu >= nr_cpu_ids)
break;
}
return 0;
}
static int smp_rescan_cpus_sclp(cpumask_t avail)
{
struct sclp_cpu_info *info;
int cpu_id, logical_cpu, cpu;
int rc;
logical_cpu = cpumask_first(&avail);
if (logical_cpu >= nr_cpu_ids)
return 0;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
rc = sclp_get_cpu_info(info);
if (rc)
goto out;
for (cpu = 0; cpu < info->combined; cpu++) {
if (info->has_cpu_type && info->cpu[cpu].type != smp_cpu_type)
continue;
cpu_id = info->cpu[cpu].address;
if (cpu_known(cpu_id))
continue;
__cpu_logical_map[logical_cpu] = cpu_id;
cpu_set_polarization(logical_cpu, POLARIZATION_UNKNOWN);
set_cpu_present(logical_cpu, true);
if (cpu >= info->configured)
smp_cpu_state[logical_cpu] = CPU_STATE_STANDBY;
else
smp_cpu_state[logical_cpu] = CPU_STATE_CONFIGURED;
logical_cpu = cpumask_next(logical_cpu, &avail);
if (logical_cpu >= nr_cpu_ids)
break;
}
out:
kfree(info);
return rc;
}
static int __smp_rescan_cpus(void)
{
cpumask_t avail;
cpumask_xor(&avail, cpu_possible_mask, cpu_present_mask);
if (smp_use_sigp_detection)
return smp_rescan_cpus_sigp(avail);
else
return smp_rescan_cpus_sclp(avail);
}
static void __init smp_detect_cpus(void)
{
unsigned int cpu, c_cpus, s_cpus;
struct sclp_cpu_info *info;
u16 boot_cpu_addr, cpu_addr;
c_cpus = 1;
s_cpus = 0;
boot_cpu_addr = __cpu_logical_map[0];
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info)
panic("smp_detect_cpus failed to allocate memory\n");
#ifdef CONFIG_CRASH_DUMP
if (OLDMEM_BASE && !is_kdump_kernel()) {
struct save_area *save_area;
save_area = kmalloc(sizeof(*save_area), GFP_KERNEL);
if (!save_area)
panic("could not allocate memory for save area\n");
copy_oldmem_page(1, (void *) save_area, sizeof(*save_area),
0x200, 0);
zfcpdump_save_areas[0] = save_area;
}
#endif
if (sclp_get_cpu_info(info)) {
smp_use_sigp_detection = 1;
for (cpu = 0; cpu <= MAX_CPU_ADDRESS; cpu++) {
if (cpu == boot_cpu_addr)
continue;
if (!raw_cpu_stopped(cpu))
continue;
smp_get_save_area(c_cpus, cpu);
c_cpus++;
}
goto out;
}
if (info->has_cpu_type) {
for (cpu = 0; cpu < info->combined; cpu++) {
if (info->cpu[cpu].address == boot_cpu_addr) {
smp_cpu_type = info->cpu[cpu].type;
break;
}
}
}
for (cpu = 0; cpu < info->combined; cpu++) {
if (info->has_cpu_type && info->cpu[cpu].type != smp_cpu_type)
continue;
cpu_addr = info->cpu[cpu].address;
if (cpu_addr == boot_cpu_addr)
continue;
if (!raw_cpu_stopped(cpu_addr)) {
s_cpus++;
continue;
}
smp_get_save_area(c_cpus, cpu_addr);
c_cpus++;
}
out:
kfree(info);
pr_info("%d configured CPUs, %d standby CPUs\n", c_cpus, s_cpus);
get_online_cpus();
__smp_rescan_cpus();
put_online_cpus();
}
int __cpuinit start_secondary(void *cpuvoid)
{
cpu_init();
preempt_disable();
init_cpu_timer();
init_cpu_vtimer();
pfault_init();
notify_cpu_starting(smp_processor_id());
ipi_call_lock();
set_cpu_online(smp_processor_id(), true);
ipi_call_unlock();
__ctl_clear_bit(0, 28);
S390_lowcore.restart_psw.mask =
PSW_DEFAULT_KEY | PSW_MASK_BASE | PSW_MASK_EA | PSW_MASK_BA;
S390_lowcore.restart_psw.addr =
PSW_ADDR_AMODE | (unsigned long) psw_restart_int_handler;
__ctl_set_bit(0, 28);
while (!cpumask_test_cpu(smp_processor_id(), cpu_active_mask))
cpu_relax();
local_irq_enable();
cpu_idle();
return 0;
}
static void __cpuinit smp_fork_idle(struct work_struct *work)
{
struct create_idle *c_idle;
c_idle = container_of(work, struct create_idle, work);
c_idle->idle = fork_idle(c_idle->cpu);
complete(&c_idle->done);
}
static int __cpuinit smp_alloc_lowcore(int cpu)
{
unsigned long async_stack, panic_stack;
struct _lowcore *lowcore;
lowcore = (void *) __get_free_pages(GFP_KERNEL | GFP_DMA, LC_ORDER);
if (!lowcore)
return -ENOMEM;
async_stack = __get_free_pages(GFP_KERNEL, ASYNC_ORDER);
panic_stack = __get_free_page(GFP_KERNEL);
if (!panic_stack || !async_stack)
goto out;
memcpy(lowcore, &S390_lowcore, 512);
memset((char *)lowcore + 512, 0, sizeof(*lowcore) - 512);
lowcore->async_stack = async_stack + ASYNC_SIZE;
lowcore->panic_stack = panic_stack + PAGE_SIZE;
lowcore->restart_psw.mask =
PSW_DEFAULT_KEY | PSW_MASK_BASE | PSW_MASK_EA | PSW_MASK_BA;
lowcore->restart_psw.addr =
PSW_ADDR_AMODE | (unsigned long) restart_int_handler;
if (user_mode != HOME_SPACE_MODE)
lowcore->restart_psw.mask |= PSW_ASC_HOME;
#ifndef CONFIG_64BIT
if (MACHINE_HAS_IEEE) {
unsigned long save_area;
save_area = get_zeroed_page(GFP_KERNEL);
if (!save_area)
goto out;
lowcore->extended_save_area_addr = (u32) save_area;
}
#else
if (vdso_alloc_per_cpu(cpu, lowcore))
goto out;
#endif
lowcore_ptr[cpu] = lowcore;
return 0;
out:
free_page(panic_stack);
free_pages(async_stack, ASYNC_ORDER);
free_pages((unsigned long) lowcore, LC_ORDER);
return -ENOMEM;
}
static void smp_free_lowcore(int cpu)
{
struct _lowcore *lowcore;
lowcore = lowcore_ptr[cpu];
#ifndef CONFIG_64BIT
if (MACHINE_HAS_IEEE)
free_page((unsigned long) lowcore->extended_save_area_addr);
#else
vdso_free_per_cpu(cpu, lowcore);
#endif
free_page(lowcore->panic_stack - PAGE_SIZE);
free_pages(lowcore->async_stack - ASYNC_SIZE, ASYNC_ORDER);
free_pages((unsigned long) lowcore, LC_ORDER);
lowcore_ptr[cpu] = NULL;
}
int __cpuinit __cpu_up(unsigned int cpu)
{
struct _lowcore *cpu_lowcore;
struct create_idle c_idle;
struct task_struct *idle;
struct stack_frame *sf;
u32 lowcore;
int ccode;
if (smp_cpu_state[cpu] != CPU_STATE_CONFIGURED)
return -EIO;
idle = current_set[cpu];
if (!idle) {
c_idle.done = COMPLETION_INITIALIZER_ONSTACK(c_idle.done);
INIT_WORK_ONSTACK(&c_idle.work, smp_fork_idle);
c_idle.cpu = cpu;
schedule_work(&c_idle.work);
wait_for_completion(&c_idle.done);
if (IS_ERR(c_idle.idle))
return PTR_ERR(c_idle.idle);
idle = c_idle.idle;
current_set[cpu] = c_idle.idle;
}
init_idle(idle, cpu);
if (smp_alloc_lowcore(cpu))
return -ENOMEM;
do {
ccode = sigp(cpu, sigp_initial_cpu_reset);
if (ccode == sigp_busy)
udelay(10);
if (ccode == sigp_not_operational)
goto err_out;
} while (ccode == sigp_busy);
lowcore = (u32)(unsigned long)lowcore_ptr[cpu];
while (sigp_p(lowcore, cpu, sigp_set_prefix) == sigp_busy)
udelay(10);
cpu_lowcore = lowcore_ptr[cpu];
cpu_lowcore->kernel_stack = (unsigned long)
task_stack_page(idle) + THREAD_SIZE;
cpu_lowcore->thread_info = (unsigned long) task_thread_info(idle);
sf = (struct stack_frame *) (cpu_lowcore->kernel_stack
- sizeof(struct pt_regs)
- sizeof(struct stack_frame));
memset(sf, 0, sizeof(struct stack_frame));
sf->gprs[9] = (unsigned long) sf;
cpu_lowcore->gpregs_save_area[15] = (unsigned long) sf;
__ctl_store(cpu_lowcore->cregs_save_area, 0, 15);
atomic_inc(&init_mm.context.attach_count);
asm volatile(
" stam 0,15,0(%0)"
: : "a" (&cpu_lowcore->access_regs_save_area) : "memory");
cpu_lowcore->percpu_offset = __per_cpu_offset[cpu];
cpu_lowcore->current_task = (unsigned long) idle;
cpu_lowcore->cpu_nr = cpu;
cpu_lowcore->kernel_asce = S390_lowcore.kernel_asce;
cpu_lowcore->machine_flags = S390_lowcore.machine_flags;
cpu_lowcore->ftrace_func = S390_lowcore.ftrace_func;
memcpy(cpu_lowcore->stfle_fac_list, S390_lowcore.stfle_fac_list,
MAX_FACILITY_BIT/8);
eieio();
while (sigp(cpu, sigp_restart) == sigp_busy)
udelay(10);
while (!cpu_online(cpu))
cpu_relax();
return 0;
err_out:
smp_free_lowcore(cpu);
return -EIO;
}
static int __init setup_possible_cpus(char *s)
{
int pcpus, cpu;
pcpus = simple_strtoul(s, NULL, 0);
init_cpu_possible(cpumask_of(0));
for (cpu = 1; cpu < pcpus && cpu < nr_cpu_ids; cpu++)
set_cpu_possible(cpu, true);
return 0;
}
int __cpu_disable(void)
{
struct ec_creg_mask_parms cr_parms;
int cpu = smp_processor_id();
set_cpu_online(cpu, false);
pfault_fini();
memset(&cr_parms.orvals, 0, sizeof(cr_parms.orvals));
memset(&cr_parms.andvals, 0xff, sizeof(cr_parms.andvals));
cr_parms.orvals[0] = 0;
cr_parms.andvals[0] = ~(1 << 15 | 1 << 14 | 1 << 13 | 1 << 11 |
1 << 10 | 1 << 9 | 1 << 6 | 1 << 5 |
1 << 4);
cr_parms.orvals[6] = 0;
cr_parms.andvals[6] = ~(1 << 31 | 1 << 30 | 1 << 29 | 1 << 28 |
1 << 27 | 1 << 26 | 1 << 25 | 1 << 24);
cr_parms.orvals[14] = 0;
cr_parms.andvals[14] = ~(1 << 28 | 1 << 27 | 1 << 26 |
1 << 25 | 1 << 24);
smp_ctl_bit_callback(&cr_parms);
return 0;
}
void __cpu_die(unsigned int cpu)
{
while (!cpu_stopped(cpu))
cpu_relax();
while (sigp_p(0, cpu, sigp_set_prefix) == sigp_busy)
udelay(10);
smp_free_lowcore(cpu);
atomic_dec(&init_mm.context.attach_count);
}
void __noreturn cpu_die(void)
{
idle_task_exit();
while (sigp(smp_processor_id(), sigp_stop) == sigp_busy)
cpu_relax();
for (;;);
}
void __init smp_prepare_cpus(unsigned int max_cpus)
{
#ifndef CONFIG_64BIT
unsigned long save_area = 0;
#endif
unsigned long async_stack, panic_stack;
struct _lowcore *lowcore;
smp_detect_cpus();
if (register_external_interrupt(0x1201, do_ext_call_interrupt) != 0)
panic("Couldn't request external interrupt 0x1201");
if (register_external_interrupt(0x1202, do_ext_call_interrupt) != 0)
panic("Couldn't request external interrupt 0x1202");
lowcore = (void *) __get_free_pages(GFP_KERNEL | GFP_DMA, LC_ORDER);
panic_stack = __get_free_page(GFP_KERNEL);
async_stack = __get_free_pages(GFP_KERNEL, ASYNC_ORDER);
BUG_ON(!lowcore || !panic_stack || !async_stack);
#ifndef CONFIG_64BIT
if (MACHINE_HAS_IEEE)
save_area = get_zeroed_page(GFP_KERNEL);
#endif
local_irq_disable();
local_mcck_disable();
lowcore_ptr[smp_processor_id()] = lowcore;
*lowcore = S390_lowcore;
lowcore->panic_stack = panic_stack + PAGE_SIZE;
lowcore->async_stack = async_stack + ASYNC_SIZE;
#ifndef CONFIG_64BIT
if (MACHINE_HAS_IEEE)
lowcore->extended_save_area_addr = (u32) save_area;
#endif
set_prefix((u32)(unsigned long) lowcore);
local_mcck_enable();
local_irq_enable();
#ifdef CONFIG_64BIT
if (vdso_alloc_per_cpu(smp_processor_id(), &S390_lowcore))
BUG();
#endif
}
void __init smp_prepare_boot_cpu(void)
{
BUG_ON(smp_processor_id() != 0);
current_thread_info()->cpu = 0;
set_cpu_present(0, true);
set_cpu_online(0, true);
S390_lowcore.percpu_offset = __per_cpu_offset[0];
current_set[0] = current;
smp_cpu_state[0] = CPU_STATE_CONFIGURED;
cpu_set_polarization(0, POLARIZATION_UNKNOWN);
}
void __init smp_cpus_done(unsigned int max_cpus)
{
}
void __init smp_setup_processor_id(void)
{
S390_lowcore.cpu_nr = 0;
__cpu_logical_map[0] = stap();
}
int setup_profiling_timer(unsigned int multiplier)
{
return 0;
}
static ssize_t cpu_configure_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
ssize_t count;
mutex_lock(&smp_cpu_state_mutex);
count = sprintf(buf, "%d\n", smp_cpu_state[dev->id]);
mutex_unlock(&smp_cpu_state_mutex);
return count;
}
static ssize_t cpu_configure_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int cpu = dev->id;
int val, rc;
char delim;
if (sscanf(buf, "%d %c", &val, &delim) != 1)
return -EINVAL;
if (val != 0 && val != 1)
return -EINVAL;
get_online_cpus();
mutex_lock(&smp_cpu_state_mutex);
rc = -EBUSY;
if (cpu_online(cpu) || cpu == 0)
goto out;
rc = 0;
switch (val) {
case 0:
if (smp_cpu_state[cpu] == CPU_STATE_CONFIGURED) {
rc = sclp_cpu_deconfigure(__cpu_logical_map[cpu]);
if (!rc) {
smp_cpu_state[cpu] = CPU_STATE_STANDBY;
cpu_set_polarization(cpu, POLARIZATION_UNKNOWN);
topology_expect_change();
}
}
break;
case 1:
if (smp_cpu_state[cpu] == CPU_STATE_STANDBY) {
rc = sclp_cpu_configure(__cpu_logical_map[cpu]);
if (!rc) {
smp_cpu_state[cpu] = CPU_STATE_CONFIGURED;
cpu_set_polarization(cpu, POLARIZATION_UNKNOWN);
topology_expect_change();
}
}
break;
default:
break;
}
out:
mutex_unlock(&smp_cpu_state_mutex);
put_online_cpus();
return rc ? rc : count;
}
static ssize_t show_cpu_address(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", __cpu_logical_map[dev->id]);
}
static ssize_t show_capability(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned int capability;
int rc;
rc = get_cpu_capability(&capability);
if (rc)
return rc;
return sprintf(buf, "%u\n", capability);
}
static ssize_t show_idle_count(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct s390_idle_data *idle;
unsigned long long idle_count;
unsigned int sequence;
idle = &per_cpu(s390_idle, dev->id);
repeat:
sequence = idle->sequence;
smp_rmb();
if (sequence & 1)
goto repeat;
idle_count = idle->idle_count;
if (idle->idle_enter)
idle_count++;
smp_rmb();
if (idle->sequence != sequence)
goto repeat;
return sprintf(buf, "%llu\n", idle_count);
}
static ssize_t show_idle_time(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct s390_idle_data *idle;
unsigned long long now, idle_time, idle_enter;
unsigned int sequence;
idle = &per_cpu(s390_idle, dev->id);
now = get_clock();
repeat:
sequence = idle->sequence;
smp_rmb();
if (sequence & 1)
goto repeat;
idle_time = idle->idle_time;
idle_enter = idle->idle_enter;
if (idle_enter != 0ULL && idle_enter < now)
idle_time += now - idle_enter;
smp_rmb();
if (idle->sequence != sequence)
goto repeat;
return sprintf(buf, "%llu\n", idle_time >> 12);
}
static int __cpuinit smp_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned int)(long)hcpu;
struct cpu *c = &per_cpu(cpu_devices, cpu);
struct device *s = &c->dev;
struct s390_idle_data *idle;
int err = 0;
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
idle = &per_cpu(s390_idle, cpu);
memset(idle, 0, sizeof(struct s390_idle_data));
err = sysfs_create_group(&s->kobj, &cpu_online_attr_group);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
sysfs_remove_group(&s->kobj, &cpu_online_attr_group);
break;
}
return notifier_from_errno(err);
}
static int __devinit smp_add_present_cpu(int cpu)
{
struct cpu *c = &per_cpu(cpu_devices, cpu);
struct device *s = &c->dev;
int rc;
c->hotpluggable = 1;
rc = register_cpu(c, cpu);
if (rc)
goto out;
rc = sysfs_create_group(&s->kobj, &cpu_common_attr_group);
if (rc)
goto out_cpu;
if (cpu_online(cpu)) {
rc = sysfs_create_group(&s->kobj, &cpu_online_attr_group);
if (rc)
goto out_online;
}
rc = topology_cpu_init(c);
if (rc)
goto out_topology;
return 0;
out_topology:
if (cpu_online(cpu))
sysfs_remove_group(&s->kobj, &cpu_online_attr_group);
out_online:
sysfs_remove_group(&s->kobj, &cpu_common_attr_group);
out_cpu:
#ifdef CONFIG_HOTPLUG_CPU
unregister_cpu(c);
#endif
out:
return rc;
}
int __ref smp_rescan_cpus(void)
{
cpumask_t newcpus;
int cpu;
int rc;
get_online_cpus();
mutex_lock(&smp_cpu_state_mutex);
cpumask_copy(&newcpus, cpu_present_mask);
rc = __smp_rescan_cpus();
if (rc)
goto out;
cpumask_andnot(&newcpus, cpu_present_mask, &newcpus);
for_each_cpu(cpu, &newcpus) {
rc = smp_add_present_cpu(cpu);
if (rc)
set_cpu_present(cpu, false);
}
rc = 0;
out:
mutex_unlock(&smp_cpu_state_mutex);
put_online_cpus();
if (!cpumask_empty(&newcpus))
topology_schedule_update();
return rc;
}
static ssize_t __ref rescan_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
int rc;
rc = smp_rescan_cpus();
return rc ? rc : count;
}
static int __init s390_smp_init(void)
{
int cpu, rc;
register_cpu_notifier(&smp_cpu_nb);
#ifdef CONFIG_HOTPLUG_CPU
rc = device_create_file(cpu_subsys.dev_root, &dev_attr_rescan);
if (rc)
return rc;
#endif
for_each_present_cpu(cpu) {
rc = smp_add_present_cpu(cpu);
if (rc)
return rc;
}
return 0;
}
