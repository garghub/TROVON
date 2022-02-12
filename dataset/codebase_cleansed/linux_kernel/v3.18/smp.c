static inline int __pcpu_sigp_relax(u16 addr, u8 order, unsigned long parm,
u32 *status)
{
int cc;
while (1) {
cc = __pcpu_sigp(addr, order, parm, NULL);
if (cc != SIGP_CC_BUSY)
return cc;
cpu_relax();
}
}
static int pcpu_sigp_retry(struct pcpu *pcpu, u8 order, u32 parm)
{
int cc, retry;
for (retry = 0; ; retry++) {
cc = __pcpu_sigp(pcpu->address, order, parm, NULL);
if (cc != SIGP_CC_BUSY)
break;
if (retry >= 3)
udelay(10);
}
return cc;
}
static inline int pcpu_stopped(struct pcpu *pcpu)
{
u32 uninitialized_var(status);
if (__pcpu_sigp(pcpu->address, SIGP_SENSE,
0, &status) != SIGP_CC_STATUS_STORED)
return 0;
return !!(status & (SIGP_STATUS_CHECK_STOP|SIGP_STATUS_STOPPED));
}
static inline int pcpu_running(struct pcpu *pcpu)
{
if (__pcpu_sigp(pcpu->address, SIGP_SENSE_RUNNING,
0, NULL) != SIGP_CC_STATUS_STORED)
return 1;
return 0;
}
static struct pcpu *pcpu_find_address(const struct cpumask *mask, int address)
{
int cpu;
for_each_cpu(cpu, mask)
if (pcpu_devices[cpu].address == address)
return pcpu_devices + cpu;
return NULL;
}
static void pcpu_ec_call(struct pcpu *pcpu, int ec_bit)
{
int order;
if (test_and_set_bit(ec_bit, &pcpu->ec_mask))
return;
order = pcpu_running(pcpu) ? SIGP_EXTERNAL_CALL : SIGP_EMERGENCY_SIGNAL;
pcpu_sigp_retry(pcpu, order, 0);
}
static int pcpu_alloc_lowcore(struct pcpu *pcpu, int cpu)
{
struct _lowcore *lc;
if (pcpu != &pcpu_devices[0]) {
pcpu->lowcore = (struct _lowcore *)
__get_free_pages(GFP_KERNEL | GFP_DMA, LC_ORDER);
pcpu->async_stack = __get_free_pages(GFP_KERNEL, ASYNC_ORDER);
pcpu->panic_stack = __get_free_page(GFP_KERNEL);
if (!pcpu->lowcore || !pcpu->panic_stack || !pcpu->async_stack)
goto out;
}
lc = pcpu->lowcore;
memcpy(lc, &S390_lowcore, 512);
memset((char *) lc + 512, 0, sizeof(*lc) - 512);
lc->async_stack = pcpu->async_stack + ASYNC_SIZE
- STACK_FRAME_OVERHEAD - sizeof(struct pt_regs);
lc->panic_stack = pcpu->panic_stack + PAGE_SIZE
- STACK_FRAME_OVERHEAD - sizeof(struct pt_regs);
lc->cpu_nr = cpu;
lc->spinlock_lockval = arch_spin_lockval(cpu);
#ifndef CONFIG_64BIT
if (MACHINE_HAS_IEEE) {
lc->extended_save_area_addr = get_zeroed_page(GFP_KERNEL);
if (!lc->extended_save_area_addr)
goto out;
}
#else
if (MACHINE_HAS_VX)
lc->vector_save_area_addr =
(unsigned long) &lc->vector_save_area;
if (vdso_alloc_per_cpu(lc))
goto out;
#endif
lowcore_ptr[cpu] = lc;
pcpu_sigp_retry(pcpu, SIGP_SET_PREFIX, (u32)(unsigned long) lc);
return 0;
out:
if (pcpu != &pcpu_devices[0]) {
free_page(pcpu->panic_stack);
free_pages(pcpu->async_stack, ASYNC_ORDER);
free_pages((unsigned long) pcpu->lowcore, LC_ORDER);
}
return -ENOMEM;
}
static void pcpu_free_lowcore(struct pcpu *pcpu)
{
pcpu_sigp_retry(pcpu, SIGP_SET_PREFIX, 0);
lowcore_ptr[pcpu - pcpu_devices] = NULL;
#ifndef CONFIG_64BIT
if (MACHINE_HAS_IEEE) {
struct _lowcore *lc = pcpu->lowcore;
free_page((unsigned long) lc->extended_save_area_addr);
lc->extended_save_area_addr = 0;
}
#else
vdso_free_per_cpu(pcpu->lowcore);
#endif
if (pcpu != &pcpu_devices[0]) {
free_page(pcpu->panic_stack);
free_pages(pcpu->async_stack, ASYNC_ORDER);
free_pages((unsigned long) pcpu->lowcore, LC_ORDER);
}
}
static void pcpu_prepare_secondary(struct pcpu *pcpu, int cpu)
{
struct _lowcore *lc = pcpu->lowcore;
if (MACHINE_HAS_TLB_LC)
cpumask_set_cpu(cpu, &init_mm.context.cpu_attach_mask);
cpumask_set_cpu(cpu, mm_cpumask(&init_mm));
atomic_inc(&init_mm.context.attach_count);
lc->cpu_nr = cpu;
lc->spinlock_lockval = arch_spin_lockval(cpu);
lc->percpu_offset = __per_cpu_offset[cpu];
lc->kernel_asce = S390_lowcore.kernel_asce;
lc->machine_flags = S390_lowcore.machine_flags;
lc->ftrace_func = S390_lowcore.ftrace_func;
lc->user_timer = lc->system_timer = lc->steal_timer = 0;
__ctl_store(lc->cregs_save_area, 0, 15);
save_access_regs((unsigned int *) lc->access_regs_save_area);
memcpy(lc->stfle_fac_list, S390_lowcore.stfle_fac_list,
MAX_FACILITY_BIT/8);
}
static void pcpu_attach_task(struct pcpu *pcpu, struct task_struct *tsk)
{
struct _lowcore *lc = pcpu->lowcore;
struct thread_info *ti = task_thread_info(tsk);
lc->kernel_stack = (unsigned long) task_stack_page(tsk)
+ THREAD_SIZE - STACK_FRAME_OVERHEAD - sizeof(struct pt_regs);
lc->thread_info = (unsigned long) task_thread_info(tsk);
lc->current_task = (unsigned long) tsk;
lc->user_timer = ti->user_timer;
lc->system_timer = ti->system_timer;
lc->steal_timer = 0;
}
static void pcpu_start_fn(struct pcpu *pcpu, void (*func)(void *), void *data)
{
struct _lowcore *lc = pcpu->lowcore;
lc->restart_stack = lc->kernel_stack;
lc->restart_fn = (unsigned long) func;
lc->restart_data = (unsigned long) data;
lc->restart_source = -1UL;
pcpu_sigp_retry(pcpu, SIGP_RESTART, 0);
}
static void pcpu_delegate(struct pcpu *pcpu, void (*func)(void *),
void *data, unsigned long stack)
{
struct _lowcore *lc = lowcore_ptr[pcpu - pcpu_devices];
unsigned long source_cpu = stap();
__load_psw_mask(PSW_KERNEL_BITS);
if (pcpu->address == source_cpu)
func(data);
pcpu_sigp_retry(pcpu, SIGP_STOP, 0);
mem_assign_absolute(lc->restart_stack, stack);
mem_assign_absolute(lc->restart_fn, (unsigned long) func);
mem_assign_absolute(lc->restart_data, (unsigned long) data);
mem_assign_absolute(lc->restart_source, source_cpu);
asm volatile(
"0: sigp 0,%0,%2 # sigp restart to target cpu\n"
" brc 2,0b # busy, try again\n"
"1: sigp 0,%1,%3 # sigp stop to current cpu\n"
" brc 2,1b # busy, try again\n"
: : "d" (pcpu->address), "d" (source_cpu),
"K" (SIGP_RESTART), "K" (SIGP_STOP)
: "0", "1", "cc");
for (;;) ;
}
void smp_call_online_cpu(void (*func)(void *), void *data)
{
struct pcpu *pcpu;
pcpu = pcpu_find_address(cpu_online_mask, stap());
if (!pcpu)
pcpu = pcpu_devices + cpumask_first(cpu_online_mask);
pcpu_delegate(pcpu, func, data, (unsigned long) restart_stack);
}
void smp_call_ipl_cpu(void (*func)(void *), void *data)
{
pcpu_delegate(&pcpu_devices[0], func, data,
pcpu_devices->panic_stack + PAGE_SIZE);
}
int smp_find_processor_id(u16 address)
{
int cpu;
for_each_present_cpu(cpu)
if (pcpu_devices[cpu].address == address)
return cpu;
return -1;
}
int smp_vcpu_scheduled(int cpu)
{
return pcpu_running(pcpu_devices + cpu);
}
void smp_yield_cpu(int cpu)
{
if (MACHINE_HAS_DIAG9C)
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
else if (MACHINE_HAS_DIAG44)
asm volatile("diag 0,0,0x44");
}
static void smp_emergency_stop(cpumask_t *cpumask)
{
u64 end;
int cpu;
end = get_tod_clock() + (1000000UL << 12);
for_each_cpu(cpu, cpumask) {
struct pcpu *pcpu = pcpu_devices + cpu;
set_bit(ec_stop_cpu, &pcpu->ec_mask);
while (__pcpu_sigp(pcpu->address, SIGP_EMERGENCY_SIGNAL,
0, NULL) == SIGP_CC_BUSY &&
get_tod_clock() < end)
cpu_relax();
}
while (get_tod_clock() < end) {
for_each_cpu(cpu, cpumask)
if (pcpu_stopped(pcpu_devices + cpu))
cpumask_clear_cpu(cpu, cpumask);
if (cpumask_empty(cpumask))
break;
cpu_relax();
}
}
void smp_send_stop(void)
{
cpumask_t cpumask;
int cpu;
__load_psw_mask(PSW_KERNEL_BITS | PSW_MASK_DAT);
trace_hardirqs_off();
debug_set_critical();
cpumask_copy(&cpumask, cpu_online_mask);
cpumask_clear_cpu(smp_processor_id(), &cpumask);
if (oops_in_progress)
smp_emergency_stop(&cpumask);
for_each_cpu(cpu, &cpumask) {
struct pcpu *pcpu = pcpu_devices + cpu;
pcpu_sigp_retry(pcpu, SIGP_STOP, 0);
while (!pcpu_stopped(pcpu))
cpu_relax();
}
}
static void smp_handle_ext_call(void)
{
unsigned long bits;
bits = xchg(&pcpu_devices[smp_processor_id()].ec_mask, 0);
if (test_bit(ec_stop_cpu, &bits))
smp_stop_cpu();
if (test_bit(ec_schedule, &bits))
scheduler_ipi();
if (test_bit(ec_call_function_single, &bits))
generic_smp_call_function_single_interrupt();
}
static void do_ext_call_interrupt(struct ext_code ext_code,
unsigned int param32, unsigned long param64)
{
inc_irq_stat(ext_code.code == 0x1202 ? IRQEXT_EXC : IRQEXT_EMS);
smp_handle_ext_call();
}
void arch_send_call_function_ipi_mask(const struct cpumask *mask)
{
int cpu;
for_each_cpu(cpu, mask)
pcpu_ec_call(pcpu_devices + cpu, ec_call_function_single);
}
void arch_send_call_function_single_ipi(int cpu)
{
pcpu_ec_call(pcpu_devices + cpu, ec_call_function_single);
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
pcpu_ec_call(pcpu_devices + cpu, ec_schedule);
}
static void smp_ctl_bit_callback(void *info)
{
struct ec_creg_mask_parms *pp = info;
unsigned long cregs[16];
__ctl_store(cregs, 0, 15);
cregs[pp->cr] = (cregs[pp->cr] & pp->andval) | pp->orval;
__ctl_load(cregs, 0, 15);
}
void smp_ctl_set_bit(int cr, int bit)
{
struct ec_creg_mask_parms parms = { 1UL << bit, -1UL, cr };
on_each_cpu(smp_ctl_bit_callback, &parms, 1);
}
void smp_ctl_clear_bit(int cr, int bit)
{
struct ec_creg_mask_parms parms = { 0, ~(1UL << bit), cr };
on_each_cpu(smp_ctl_bit_callback, &parms, 1);
}
static void __init smp_get_save_area(int cpu, u16 address)
{
void *lc = pcpu_devices[0].lowcore;
struct save_area_ext *sa_ext;
unsigned long vx_sa;
if (is_kdump_kernel())
return;
if (!OLDMEM_BASE && (address == boot_cpu_address ||
ipl_info.type != IPL_TYPE_FCP_DUMP))
return;
sa_ext = dump_save_area_create(cpu);
if (!sa_ext)
panic("could not allocate memory for save area\n");
if (address == boot_cpu_address) {
copy_oldmem_page(1, (void *) &sa_ext->sa, sizeof(sa_ext->sa),
SAVE_AREA_BASE - PAGE_SIZE, 0);
if (MACHINE_HAS_VX)
save_vx_regs_safe(sa_ext->vx_regs);
return;
}
__pcpu_sigp_relax(address, SIGP_STOP_AND_STORE_STATUS, 0, NULL);
memcpy_real(&sa_ext->sa, lc + SAVE_AREA_BASE, sizeof(sa_ext->sa));
if (!MACHINE_HAS_VX)
return;
vx_sa = __get_free_page(GFP_KERNEL);
if (!vx_sa)
panic("could not allocate memory for VX save area\n");
__pcpu_sigp_relax(address, SIGP_STORE_ADDITIONAL_STATUS, vx_sa, NULL);
memcpy(sa_ext->vx_regs, (void *) vx_sa, sizeof(sa_ext->vx_regs));
free_page(vx_sa);
}
int smp_store_status(int cpu)
{
unsigned long vx_sa;
struct pcpu *pcpu;
pcpu = pcpu_devices + cpu;
if (__pcpu_sigp_relax(pcpu->address, SIGP_STOP_AND_STORE_STATUS,
0, NULL) != SIGP_CC_ORDER_CODE_ACCEPTED)
return -EIO;
if (!MACHINE_HAS_VX)
return 0;
vx_sa = __pa(pcpu->lowcore->vector_save_area_addr);
__pcpu_sigp_relax(pcpu->address, SIGP_STORE_ADDITIONAL_STATUS,
vx_sa, NULL);
return 0;
}
static inline void smp_get_save_area(int cpu, u16 address) { }
void smp_cpu_set_polarization(int cpu, int val)
{
pcpu_devices[cpu].polarization = val;
}
int smp_cpu_get_polarization(int cpu)
{
return pcpu_devices[cpu].polarization;
}
static struct sclp_cpu_info *smp_get_cpu_info(void)
{
static int use_sigp_detection;
struct sclp_cpu_info *info;
int address;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (info && (use_sigp_detection || sclp_get_cpu_info(info))) {
use_sigp_detection = 1;
for (address = 0; address <= MAX_CPU_ADDRESS; address++) {
if (__pcpu_sigp_relax(address, SIGP_SENSE, 0, NULL) ==
SIGP_CC_NOT_OPERATIONAL)
continue;
info->cpu[info->configured].address = address;
info->configured++;
}
info->combined = info->configured;
}
return info;
}
static int __smp_rescan_cpus(struct sclp_cpu_info *info, int sysfs_add)
{
struct pcpu *pcpu;
cpumask_t avail;
int cpu, nr, i;
nr = 0;
cpumask_xor(&avail, cpu_possible_mask, cpu_present_mask);
cpu = cpumask_first(&avail);
for (i = 0; (i < info->combined) && (cpu < nr_cpu_ids); i++) {
if (info->has_cpu_type && info->cpu[i].type != boot_cpu_type)
continue;
if (pcpu_find_address(cpu_present_mask, info->cpu[i].address))
continue;
pcpu = pcpu_devices + cpu;
pcpu->address = info->cpu[i].address;
pcpu->state = (i >= info->configured) ?
CPU_STATE_STANDBY : CPU_STATE_CONFIGURED;
smp_cpu_set_polarization(cpu, POLARIZATION_UNKNOWN);
set_cpu_present(cpu, true);
if (sysfs_add && smp_add_present_cpu(cpu) != 0)
set_cpu_present(cpu, false);
else
nr++;
cpu = cpumask_next(cpu, &avail);
}
return nr;
}
static void __init smp_detect_cpus(void)
{
unsigned int cpu, c_cpus, s_cpus;
struct sclp_cpu_info *info;
info = smp_get_cpu_info();
if (!info)
panic("smp_detect_cpus failed to allocate memory\n");
if (info->has_cpu_type) {
for (cpu = 0; cpu < info->combined; cpu++) {
if (info->cpu[cpu].address != boot_cpu_address)
continue;
boot_cpu_type = info->cpu[cpu].type;
break;
}
}
c_cpus = s_cpus = 0;
for (cpu = 0; cpu < info->combined; cpu++) {
if (info->has_cpu_type && info->cpu[cpu].type != boot_cpu_type)
continue;
if (cpu < info->configured) {
smp_get_save_area(c_cpus, info->cpu[cpu].address);
c_cpus++;
} else
s_cpus++;
}
pr_info("%d configured CPUs, %d standby CPUs\n", c_cpus, s_cpus);
get_online_cpus();
__smp_rescan_cpus(info, 0);
put_online_cpus();
kfree(info);
}
static void smp_start_secondary(void *cpuvoid)
{
S390_lowcore.last_update_clock = get_tod_clock();
S390_lowcore.restart_stack = (unsigned long) restart_stack;
S390_lowcore.restart_fn = (unsigned long) do_restart;
S390_lowcore.restart_data = 0;
S390_lowcore.restart_source = -1UL;
restore_access_regs(S390_lowcore.access_regs_save_area);
__ctl_load(S390_lowcore.cregs_save_area, 0, 15);
__load_psw_mask(PSW_KERNEL_BITS | PSW_MASK_DAT);
cpu_init();
preempt_disable();
init_cpu_timer();
vtime_init();
pfault_init();
notify_cpu_starting(smp_processor_id());
set_cpu_online(smp_processor_id(), true);
inc_irq_stat(CPU_RST);
local_irq_enable();
cpu_startup_entry(CPUHP_ONLINE);
}
int __cpu_up(unsigned int cpu, struct task_struct *tidle)
{
struct pcpu *pcpu;
int rc;
pcpu = pcpu_devices + cpu;
if (pcpu->state != CPU_STATE_CONFIGURED)
return -EIO;
if (pcpu_sigp_retry(pcpu, SIGP_INITIAL_CPU_RESET, 0) !=
SIGP_CC_ORDER_CODE_ACCEPTED)
return -EIO;
rc = pcpu_alloc_lowcore(pcpu, cpu);
if (rc)
return rc;
pcpu_prepare_secondary(pcpu, cpu);
pcpu_attach_task(pcpu, tidle);
pcpu_start_fn(pcpu, smp_start_secondary, NULL);
while (!cpu_online(cpu))
cpu_relax();
return 0;
}
static int __init _setup_possible_cpus(char *s)
{
get_option(&s, &setup_possible_cpus);
return 0;
}
int __cpu_disable(void)
{
unsigned long cregs[16];
smp_handle_ext_call();
set_cpu_online(smp_processor_id(), false);
pfault_fini();
__ctl_store(cregs, 0, 15);
cregs[0] &= ~0x0000ee70UL;
cregs[6] &= ~0xff000000UL;
cregs[14] &= ~0x1f000000UL;
__ctl_load(cregs, 0, 15);
clear_cpu_flag(CIF_NOHZ_DELAY);
return 0;
}
void __cpu_die(unsigned int cpu)
{
struct pcpu *pcpu;
pcpu = pcpu_devices + cpu;
while (!pcpu_stopped(pcpu))
cpu_relax();
pcpu_free_lowcore(pcpu);
atomic_dec(&init_mm.context.attach_count);
cpumask_clear_cpu(cpu, mm_cpumask(&init_mm));
if (MACHINE_HAS_TLB_LC)
cpumask_clear_cpu(cpu, &init_mm.context.cpu_attach_mask);
}
void __noreturn cpu_die(void)
{
idle_task_exit();
pcpu_sigp_retry(pcpu_devices + smp_processor_id(), SIGP_STOP, 0);
for (;;) ;
}
void __init smp_fill_possible_mask(void)
{
unsigned int possible, sclp, cpu;
sclp = sclp_get_max_cpu() ?: nr_cpu_ids;
possible = setup_possible_cpus ?: nr_cpu_ids;
possible = min(possible, sclp);
for (cpu = 0; cpu < possible && cpu < nr_cpu_ids; cpu++)
set_cpu_possible(cpu, true);
}
void __init smp_prepare_cpus(unsigned int max_cpus)
{
if (register_external_irq(EXT_IRQ_EMERGENCY_SIG, do_ext_call_interrupt))
panic("Couldn't request external interrupt 0x1201");
if (register_external_irq(EXT_IRQ_EXTERNAL_CALL, do_ext_call_interrupt))
panic("Couldn't request external interrupt 0x1202");
smp_detect_cpus();
}
void __init smp_prepare_boot_cpu(void)
{
struct pcpu *pcpu = pcpu_devices;
boot_cpu_address = stap();
pcpu->state = CPU_STATE_CONFIGURED;
pcpu->address = boot_cpu_address;
pcpu->lowcore = (struct _lowcore *)(unsigned long) store_prefix();
pcpu->async_stack = S390_lowcore.async_stack - ASYNC_SIZE
+ STACK_FRAME_OVERHEAD + sizeof(struct pt_regs);
pcpu->panic_stack = S390_lowcore.panic_stack - PAGE_SIZE
+ STACK_FRAME_OVERHEAD + sizeof(struct pt_regs);
S390_lowcore.percpu_offset = __per_cpu_offset[0];
smp_cpu_set_polarization(0, POLARIZATION_UNKNOWN);
set_cpu_present(0, true);
set_cpu_online(0, true);
}
void __init smp_cpus_done(unsigned int max_cpus)
{
}
void __init smp_setup_processor_id(void)
{
S390_lowcore.cpu_nr = 0;
S390_lowcore.spinlock_lockval = arch_spin_lockval(0);
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
count = sprintf(buf, "%d\n", pcpu_devices[dev->id].state);
mutex_unlock(&smp_cpu_state_mutex);
return count;
}
static ssize_t cpu_configure_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct pcpu *pcpu;
int cpu, val, rc;
char delim;
if (sscanf(buf, "%d %c", &val, &delim) != 1)
return -EINVAL;
if (val != 0 && val != 1)
return -EINVAL;
get_online_cpus();
mutex_lock(&smp_cpu_state_mutex);
rc = -EBUSY;
cpu = dev->id;
if (cpu_online(cpu) || cpu == 0)
goto out;
pcpu = pcpu_devices + cpu;
rc = 0;
switch (val) {
case 0:
if (pcpu->state != CPU_STATE_CONFIGURED)
break;
rc = sclp_cpu_deconfigure(pcpu->address);
if (rc)
break;
pcpu->state = CPU_STATE_STANDBY;
smp_cpu_set_polarization(cpu, POLARIZATION_UNKNOWN);
topology_expect_change();
break;
case 1:
if (pcpu->state != CPU_STATE_STANDBY)
break;
rc = sclp_cpu_configure(pcpu->address);
if (rc)
break;
pcpu->state = CPU_STATE_CONFIGURED;
smp_cpu_set_polarization(cpu, POLARIZATION_UNKNOWN);
topology_expect_change();
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
return sprintf(buf, "%d\n", pcpu_devices[dev->id].address);
}
static int smp_cpu_notify(struct notifier_block *self, unsigned long action,
void *hcpu)
{
unsigned int cpu = (unsigned int)(long)hcpu;
struct cpu *c = pcpu_devices[cpu].cpu;
struct device *s = &c->dev;
int err = 0;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_ONLINE:
err = sysfs_create_group(&s->kobj, &cpu_online_attr_group);
break;
case CPU_DEAD:
sysfs_remove_group(&s->kobj, &cpu_online_attr_group);
break;
}
return notifier_from_errno(err);
}
static int smp_add_present_cpu(int cpu)
{
struct device *s;
struct cpu *c;
int rc;
c = kzalloc(sizeof(*c), GFP_KERNEL);
if (!c)
return -ENOMEM;
pcpu_devices[cpu].cpu = c;
s = &c->dev;
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
struct sclp_cpu_info *info;
int nr;
info = smp_get_cpu_info();
if (!info)
return -ENOMEM;
get_online_cpus();
mutex_lock(&smp_cpu_state_mutex);
nr = __smp_rescan_cpus(info, 1);
mutex_unlock(&smp_cpu_state_mutex);
put_online_cpus();
kfree(info);
if (nr)
topology_schedule_update();
return 0;
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
int cpu, rc = 0;
#ifdef CONFIG_HOTPLUG_CPU
rc = device_create_file(cpu_subsys.dev_root, &dev_attr_rescan);
if (rc)
return rc;
#endif
cpu_notifier_register_begin();
for_each_present_cpu(cpu) {
rc = smp_add_present_cpu(cpu);
if (rc)
goto out;
}
__hotcpu_notifier(smp_cpu_notify, 0);
out:
cpu_notifier_register_done();
return rc;
}
