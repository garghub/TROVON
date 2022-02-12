static void cpu_bringup(void)
{
int cpu;
cpu_init();
touch_softlockup_watchdog();
preempt_disable();
if (!xen_feature(XENFEAT_supervisor_mode_kernel)) {
xen_enable_sysenter();
xen_enable_syscall();
}
cpu = smp_processor_id();
smp_store_cpu_info(cpu);
cpu_data(cpu).x86_max_cores = 1;
set_cpu_sibling_map(cpu);
xen_setup_cpu_clockevents();
notify_cpu_starting(cpu);
set_cpu_online(cpu, true);
cpu_set_state_online(cpu);
local_irq_enable();
}
asmlinkage __visible void cpu_bringup_and_idle(void)
{
cpu_bringup();
cpu_startup_entry(CPUHP_AP_ONLINE_IDLE);
}
void xen_smp_intr_free_pv(unsigned int cpu)
{
if (per_cpu(xen_irq_work, cpu).irq >= 0) {
unbind_from_irqhandler(per_cpu(xen_irq_work, cpu).irq, NULL);
per_cpu(xen_irq_work, cpu).irq = -1;
kfree(per_cpu(xen_irq_work, cpu).name);
per_cpu(xen_irq_work, cpu).name = NULL;
}
if (per_cpu(xen_pmu_irq, cpu).irq >= 0) {
unbind_from_irqhandler(per_cpu(xen_pmu_irq, cpu).irq, NULL);
per_cpu(xen_pmu_irq, cpu).irq = -1;
kfree(per_cpu(xen_pmu_irq, cpu).name);
per_cpu(xen_pmu_irq, cpu).name = NULL;
}
}
int xen_smp_intr_init_pv(unsigned int cpu)
{
int rc;
char *callfunc_name, *pmu_name;
callfunc_name = kasprintf(GFP_KERNEL, "irqwork%d", cpu);
rc = bind_ipi_to_irqhandler(XEN_IRQ_WORK_VECTOR,
cpu,
xen_irq_work_interrupt,
IRQF_PERCPU|IRQF_NOBALANCING,
callfunc_name,
NULL);
if (rc < 0)
goto fail;
per_cpu(xen_irq_work, cpu).irq = rc;
per_cpu(xen_irq_work, cpu).name = callfunc_name;
if (is_xen_pmu(cpu)) {
pmu_name = kasprintf(GFP_KERNEL, "pmu%d", cpu);
rc = bind_virq_to_irqhandler(VIRQ_XENPMU, cpu,
xen_pmu_irq_handler,
IRQF_PERCPU|IRQF_NOBALANCING,
pmu_name, NULL);
if (rc < 0)
goto fail;
per_cpu(xen_pmu_irq, cpu).irq = rc;
per_cpu(xen_pmu_irq, cpu).name = pmu_name;
}
return 0;
fail:
xen_smp_intr_free_pv(cpu);
return rc;
}
static void __init xen_fill_possible_map(void)
{
int i, rc;
if (xen_initial_domain())
return;
for (i = 0; i < nr_cpu_ids; i++) {
rc = HYPERVISOR_vcpu_op(VCPUOP_is_up, i, NULL);
if (rc >= 0) {
num_processors++;
set_cpu_possible(i, true);
}
}
}
static void __init xen_filter_cpu_maps(void)
{
int i, rc;
unsigned int subtract = 0;
if (!xen_initial_domain())
return;
num_processors = 0;
disabled_cpus = 0;
for (i = 0; i < nr_cpu_ids; i++) {
rc = HYPERVISOR_vcpu_op(VCPUOP_is_up, i, NULL);
if (rc >= 0) {
num_processors++;
set_cpu_possible(i, true);
} else {
set_cpu_possible(i, false);
set_cpu_present(i, false);
subtract++;
}
}
#ifdef CONFIG_HOTPLUG_CPU
if (subtract)
nr_cpu_ids = nr_cpu_ids - subtract;
#endif
}
static void __init xen_pv_smp_prepare_boot_cpu(void)
{
BUG_ON(smp_processor_id() != 0);
native_smp_prepare_boot_cpu();
if (!xen_feature(XENFEAT_writable_page_tables))
make_lowmem_page_readwrite(xen_initial_gdt);
#ifdef CONFIG_X86_32
loadsegment(ds, __USER_DS);
loadsegment(es, __USER_DS);
#endif
xen_filter_cpu_maps();
xen_setup_vcpu_info_placement();
xen_init_spinlocks();
}
static void __init xen_pv_smp_prepare_cpus(unsigned int max_cpus)
{
unsigned cpu;
unsigned int i;
if (skip_ioapic_setup) {
char *m = (max_cpus == 0) ?
"The nosmp parameter is incompatible with Xen; " \
"use Xen dom0_max_vcpus=1 parameter" :
"The noapic parameter is incompatible with Xen";
xen_raw_printk(m);
panic(m);
}
xen_init_lock_cpu(0);
smp_store_boot_cpu_info();
cpu_data(0).x86_max_cores = 1;
for_each_possible_cpu(i) {
zalloc_cpumask_var(&per_cpu(cpu_sibling_map, i), GFP_KERNEL);
zalloc_cpumask_var(&per_cpu(cpu_core_map, i), GFP_KERNEL);
zalloc_cpumask_var(&per_cpu(cpu_llc_shared_map, i), GFP_KERNEL);
}
set_cpu_sibling_map(0);
xen_pmu_init(0);
if (xen_smp_intr_init(0) || xen_smp_intr_init_pv(0))
BUG();
if (!alloc_cpumask_var(&xen_cpu_initialized_map, GFP_KERNEL))
panic("could not allocate xen_cpu_initialized_map\n");
cpumask_copy(xen_cpu_initialized_map, cpumask_of(0));
while ((num_possible_cpus() > 1) && (num_possible_cpus() > max_cpus)) {
for (cpu = nr_cpu_ids - 1; !cpu_possible(cpu); cpu--)
continue;
set_cpu_possible(cpu, false);
}
for_each_possible_cpu(cpu)
set_cpu_present(cpu, true);
}
static int
cpu_initialize_context(unsigned int cpu, struct task_struct *idle)
{
struct vcpu_guest_context *ctxt;
struct desc_struct *gdt;
unsigned long gdt_mfn;
cpumask_set_cpu(cpu, cpu_callout_mask);
if (cpumask_test_and_set_cpu(cpu, xen_cpu_initialized_map))
return 0;
ctxt = kzalloc(sizeof(*ctxt), GFP_KERNEL);
if (ctxt == NULL)
return -ENOMEM;
gdt = get_cpu_gdt_rw(cpu);
#ifdef CONFIG_X86_32
ctxt->user_regs.fs = __KERNEL_PERCPU;
ctxt->user_regs.gs = __KERNEL_STACK_CANARY;
#endif
memset(&ctxt->fpu_ctxt, 0, sizeof(ctxt->fpu_ctxt));
ctxt->user_regs.eip = (unsigned long)cpu_bringup_and_idle;
ctxt->flags = VGCF_IN_KERNEL;
ctxt->user_regs.eflags = 0x1000;
ctxt->user_regs.ds = __USER_DS;
ctxt->user_regs.es = __USER_DS;
ctxt->user_regs.ss = __KERNEL_DS;
xen_copy_trap_info(ctxt->trap_ctxt);
ctxt->ldt_ents = 0;
BUG_ON((unsigned long)gdt & ~PAGE_MASK);
gdt_mfn = arbitrary_virt_to_mfn(gdt);
make_lowmem_page_readonly(gdt);
make_lowmem_page_readonly(mfn_to_virt(gdt_mfn));
ctxt->gdt_frames[0] = gdt_mfn;
ctxt->gdt_ents = GDT_ENTRIES;
ctxt->kernel_ss = __KERNEL_DS;
ctxt->kernel_sp = idle->thread.sp0;
#ifdef CONFIG_X86_32
ctxt->event_callback_cs = __KERNEL_CS;
ctxt->failsafe_callback_cs = __KERNEL_CS;
#else
ctxt->gs_base_kernel = per_cpu_offset(cpu);
#endif
ctxt->event_callback_eip =
(unsigned long)xen_hypervisor_callback;
ctxt->failsafe_callback_eip =
(unsigned long)xen_failsafe_callback;
ctxt->user_regs.cs = __KERNEL_CS;
per_cpu(xen_cr3, cpu) = __pa(swapper_pg_dir);
ctxt->user_regs.esp = idle->thread.sp0 - sizeof(struct pt_regs);
ctxt->ctrlreg[3] = xen_pfn_to_cr3(virt_to_gfn(swapper_pg_dir));
if (HYPERVISOR_vcpu_op(VCPUOP_initialise, xen_vcpu_nr(cpu), ctxt))
BUG();
kfree(ctxt);
return 0;
}
static int xen_pv_cpu_up(unsigned int cpu, struct task_struct *idle)
{
int rc;
common_cpu_up(cpu, idle);
xen_setup_runstate_info(cpu);
rc = cpu_check_up_prepare(cpu);
if (rc)
return rc;
per_cpu(xen_vcpu, cpu)->evtchn_upcall_mask = 1;
rc = cpu_initialize_context(cpu, idle);
if (rc)
return rc;
xen_pmu_init(cpu);
rc = HYPERVISOR_vcpu_op(VCPUOP_up, xen_vcpu_nr(cpu), NULL);
BUG_ON(rc);
while (cpu_report_state(cpu) != CPU_ONLINE)
HYPERVISOR_sched_op(SCHEDOP_yield, NULL);
return 0;
}
static void xen_pv_smp_cpus_done(unsigned int max_cpus)
{
}
static int xen_pv_cpu_disable(void)
{
unsigned int cpu = smp_processor_id();
if (cpu == 0)
return -EBUSY;
cpu_disable_common();
load_cr3(swapper_pg_dir);
return 0;
}
static void xen_pv_cpu_die(unsigned int cpu)
{
while (HYPERVISOR_vcpu_op(VCPUOP_is_up,
xen_vcpu_nr(cpu), NULL)) {
__set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(HZ/10);
}
if (common_cpu_die(cpu) == 0) {
xen_smp_intr_free(cpu);
xen_uninit_lock_cpu(cpu);
xen_teardown_timer(cpu);
xen_pmu_finish(cpu);
}
}
static void xen_pv_play_dead(void)
{
play_dead_common();
HYPERVISOR_vcpu_op(VCPUOP_down, xen_vcpu_nr(smp_processor_id()), NULL);
cpu_bringup();
tick_nohz_idle_enter();
cpu_startup_entry(CPUHP_AP_ONLINE_IDLE);
}
static int xen_pv_cpu_disable(void)
{
return -ENOSYS;
}
static void xen_pv_cpu_die(unsigned int cpu)
{
BUG();
}
static void xen_pv_play_dead(void)
{
BUG();
}
static void stop_self(void *v)
{
int cpu = smp_processor_id();
load_cr3(swapper_pg_dir);
set_cpu_online(cpu, false);
HYPERVISOR_vcpu_op(VCPUOP_down, xen_vcpu_nr(cpu), NULL);
BUG();
}
static void xen_pv_stop_other_cpus(int wait)
{
smp_call_function(stop_self, NULL, wait);
}
static irqreturn_t xen_irq_work_interrupt(int irq, void *dev_id)
{
irq_enter();
irq_work_run();
inc_irq_stat(apic_irq_work_irqs);
irq_exit();
return IRQ_HANDLED;
}
void __init xen_smp_init(void)
{
smp_ops = xen_smp_ops;
xen_fill_possible_map();
}
