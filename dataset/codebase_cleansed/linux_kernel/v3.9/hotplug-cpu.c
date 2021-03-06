static int __init setup_cede_offline(char *str)
{
if (!strcmp(str, "off"))
cede_offline_enabled = 0;
else if (!strcmp(str, "on"))
cede_offline_enabled = 1;
else
return 0;
return 1;
}
enum cpu_state_vals get_cpu_current_state(int cpu)
{
return per_cpu(current_state, cpu);
}
void set_cpu_current_state(int cpu, enum cpu_state_vals state)
{
per_cpu(current_state, cpu) = state;
}
enum cpu_state_vals get_preferred_offline_state(int cpu)
{
return per_cpu(preferred_offline_state, cpu);
}
void set_preferred_offline_state(int cpu, enum cpu_state_vals state)
{
per_cpu(preferred_offline_state, cpu) = state;
}
void set_default_offline_state(int cpu)
{
per_cpu(preferred_offline_state, cpu) = default_offline_state;
}
static void rtas_stop_self(void)
{
struct rtas_args *args = &rtas_stop_self_args;
local_irq_disable();
BUG_ON(args->token == RTAS_UNKNOWN_SERVICE);
printk("cpu %u (hwid %u) Ready to die...\n",
smp_processor_id(), hard_smp_processor_id());
enter_rtas(__pa(args));
panic("Alas, I survived.\n");
}
static void pseries_mach_cpu_die(void)
{
unsigned int cpu = smp_processor_id();
unsigned int hwcpu = hard_smp_processor_id();
u8 cede_latency_hint = 0;
local_irq_disable();
idle_task_exit();
xics_teardown_cpu();
if (get_preferred_offline_state(cpu) == CPU_STATE_INACTIVE) {
set_cpu_current_state(cpu, CPU_STATE_INACTIVE);
if (ppc_md.suspend_disable_cpu)
ppc_md.suspend_disable_cpu();
cede_latency_hint = 2;
get_lppaca()->idle = 1;
if (!get_lppaca()->shared_proc)
get_lppaca()->donate_dedicated_cpu = 1;
while (get_preferred_offline_state(cpu) == CPU_STATE_INACTIVE) {
while (!prep_irq_for_idle()) {
local_irq_enable();
local_irq_disable();
}
extended_cede_processor(cede_latency_hint);
}
local_irq_disable();
if (!get_lppaca()->shared_proc)
get_lppaca()->donate_dedicated_cpu = 0;
get_lppaca()->idle = 0;
if (get_preferred_offline_state(cpu) == CPU_STATE_ONLINE) {
unregister_slb_shadow(hwcpu);
hard_irq_disable();
start_secondary_resume();
}
}
WARN_ON(get_preferred_offline_state(cpu) != CPU_STATE_OFFLINE);
set_cpu_current_state(cpu, CPU_STATE_OFFLINE);
unregister_slb_shadow(hwcpu);
rtas_stop_self();
BUG();
for(;;);
}
static int pseries_cpu_disable(void)
{
int cpu = smp_processor_id();
set_cpu_online(cpu, false);
vdso_data->processorCount--;
if (cpu == boot_cpuid)
boot_cpuid = cpumask_any(cpu_online_mask);
xics_migrate_irqs_away();
return 0;
}
static void pseries_cpu_die(unsigned int cpu)
{
int tries;
int cpu_status = 1;
unsigned int pcpu = get_hard_smp_processor_id(cpu);
if (get_preferred_offline_state(cpu) == CPU_STATE_INACTIVE) {
cpu_status = 1;
for (tries = 0; tries < 5000; tries++) {
if (get_cpu_current_state(cpu) == CPU_STATE_INACTIVE) {
cpu_status = 0;
break;
}
msleep(1);
}
} else if (get_preferred_offline_state(cpu) == CPU_STATE_OFFLINE) {
for (tries = 0; tries < 25; tries++) {
cpu_status = smp_query_cpu_stopped(pcpu);
if (cpu_status == QCSS_STOPPED ||
cpu_status == QCSS_HARDWARE_ERROR)
break;
cpu_relax();
}
}
if (cpu_status != 0) {
printk("Querying DEAD? cpu %i (%i) shows %i\n",
cpu, pcpu, cpu_status);
}
paca[cpu].cpu_start = 0;
}
static int pseries_add_processor(struct device_node *np)
{
unsigned int cpu;
cpumask_var_t candidate_mask, tmp;
int err = -ENOSPC, len, nthreads, i;
const u32 *intserv;
intserv = of_get_property(np, "ibm,ppc-interrupt-server#s", &len);
if (!intserv)
return 0;
zalloc_cpumask_var(&candidate_mask, GFP_KERNEL);
zalloc_cpumask_var(&tmp, GFP_KERNEL);
nthreads = len / sizeof(u32);
for (i = 0; i < nthreads; i++)
cpumask_set_cpu(i, tmp);
cpu_maps_update_begin();
BUG_ON(!cpumask_subset(cpu_present_mask, cpu_possible_mask));
cpumask_xor(candidate_mask, cpu_possible_mask, cpu_present_mask);
if (cpumask_empty(candidate_mask)) {
printk(KERN_ERR "Cannot add cpu %s; this system configuration"
" supports %d logical cpus.\n", np->full_name,
cpumask_weight(cpu_possible_mask));
goto out_unlock;
}
while (!cpumask_empty(tmp))
if (cpumask_subset(tmp, candidate_mask))
break;
else
cpumask_shift_left(tmp, tmp, nthreads);
if (cpumask_empty(tmp)) {
printk(KERN_ERR "Unable to find space in cpu_present_mask for"
" processor %s with %d thread(s)\n", np->name,
nthreads);
goto out_unlock;
}
for_each_cpu(cpu, tmp) {
BUG_ON(cpu_present(cpu));
set_cpu_present(cpu, true);
set_hard_smp_processor_id(cpu, *intserv++);
}
err = 0;
out_unlock:
cpu_maps_update_done();
free_cpumask_var(candidate_mask);
free_cpumask_var(tmp);
return err;
}
static void pseries_remove_processor(struct device_node *np)
{
unsigned int cpu;
int len, nthreads, i;
const u32 *intserv;
intserv = of_get_property(np, "ibm,ppc-interrupt-server#s", &len);
if (!intserv)
return;
nthreads = len / sizeof(u32);
cpu_maps_update_begin();
for (i = 0; i < nthreads; i++) {
for_each_present_cpu(cpu) {
if (get_hard_smp_processor_id(cpu) != intserv[i])
continue;
BUG_ON(cpu_online(cpu));
set_cpu_present(cpu, false);
set_hard_smp_processor_id(cpu, -1);
break;
}
if (cpu >= nr_cpu_ids)
printk(KERN_WARNING "Could not find cpu to remove "
"with physical id 0x%x\n", intserv[i]);
}
cpu_maps_update_done();
}
static int pseries_smp_notifier(struct notifier_block *nb,
unsigned long action, void *node)
{
int err = 0;
switch (action) {
case OF_RECONFIG_ATTACH_NODE:
err = pseries_add_processor(node);
break;
case OF_RECONFIG_DETACH_NODE:
pseries_remove_processor(node);
break;
}
return notifier_from_errno(err);
}
static int parse_cede_parameters(void)
{
memset(cede_parameters, 0, CEDE_LATENCY_PARAM_MAX_LENGTH);
return rtas_call(rtas_token("ibm,get-system-parameter"), 3, 1,
NULL,
CEDE_LATENCY_TOKEN,
__pa(cede_parameters),
CEDE_LATENCY_PARAM_MAX_LENGTH);
}
static int __init pseries_cpu_hotplug_init(void)
{
struct device_node *np;
const char *typep;
int cpu;
int qcss_tok;
for_each_node_by_name(np, "interrupt-controller") {
typep = of_get_property(np, "compatible", NULL);
if (strstr(typep, "open-pic")) {
of_node_put(np);
printk(KERN_INFO "CPU Hotplug not supported on "
"systems using MPIC\n");
return 0;
}
}
rtas_stop_self_args.token = rtas_token("stop-self");
qcss_tok = rtas_token("query-cpu-stopped-state");
if (rtas_stop_self_args.token == RTAS_UNKNOWN_SERVICE ||
qcss_tok == RTAS_UNKNOWN_SERVICE) {
printk(KERN_INFO "CPU Hotplug not supported by firmware "
"- disabling.\n");
return 0;
}
ppc_md.cpu_die = pseries_mach_cpu_die;
smp_ops->cpu_disable = pseries_cpu_disable;
smp_ops->cpu_die = pseries_cpu_die;
if (firmware_has_feature(FW_FEATURE_LPAR)) {
of_reconfig_notifier_register(&pseries_smp_nb);
cpu_maps_update_begin();
if (cede_offline_enabled && parse_cede_parameters() == 0) {
default_offline_state = CPU_STATE_INACTIVE;
for_each_online_cpu(cpu)
set_default_offline_state(cpu);
}
cpu_maps_update_done();
}
return 0;
}
