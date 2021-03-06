bool psci_tos_resident_on(int cpu)
{
return cpu == resident_cpu;
}
static inline bool psci_has_ext_power_state(void)
{
return psci_cpu_suspend_feature &
PSCI_1_0_FEATURES_CPU_SUSPEND_PF_MASK;
}
bool psci_power_state_loses_context(u32 state)
{
const u32 mask = psci_has_ext_power_state() ?
PSCI_1_0_EXT_POWER_STATE_TYPE_MASK :
PSCI_0_2_POWER_STATE_TYPE_MASK;
return state & mask;
}
bool psci_power_state_is_valid(u32 state)
{
const u32 valid_mask = psci_has_ext_power_state() ?
PSCI_1_0_EXT_POWER_STATE_MASK :
PSCI_0_2_POWER_STATE_MASK;
return !(state & ~valid_mask);
}
static unsigned long __invoke_psci_fn_hvc(unsigned long function_id,
unsigned long arg0, unsigned long arg1,
unsigned long arg2)
{
struct arm_smccc_res res;
arm_smccc_hvc(function_id, arg0, arg1, arg2, 0, 0, 0, 0, &res);
return res.a0;
}
static unsigned long __invoke_psci_fn_smc(unsigned long function_id,
unsigned long arg0, unsigned long arg1,
unsigned long arg2)
{
struct arm_smccc_res res;
arm_smccc_smc(function_id, arg0, arg1, arg2, 0, 0, 0, 0, &res);
return res.a0;
}
static int psci_to_linux_errno(int errno)
{
switch (errno) {
case PSCI_RET_SUCCESS:
return 0;
case PSCI_RET_NOT_SUPPORTED:
return -EOPNOTSUPP;
case PSCI_RET_INVALID_PARAMS:
case PSCI_RET_INVALID_ADDRESS:
return -EINVAL;
case PSCI_RET_DENIED:
return -EPERM;
};
return -EINVAL;
}
static u32 psci_get_version(void)
{
return invoke_psci_fn(PSCI_0_2_FN_PSCI_VERSION, 0, 0, 0);
}
static int psci_cpu_suspend(u32 state, unsigned long entry_point)
{
int err;
u32 fn;
fn = psci_function_id[PSCI_FN_CPU_SUSPEND];
err = invoke_psci_fn(fn, state, entry_point, 0);
return psci_to_linux_errno(err);
}
static int psci_cpu_off(u32 state)
{
int err;
u32 fn;
fn = psci_function_id[PSCI_FN_CPU_OFF];
err = invoke_psci_fn(fn, state, 0, 0);
return psci_to_linux_errno(err);
}
static int psci_cpu_on(unsigned long cpuid, unsigned long entry_point)
{
int err;
u32 fn;
fn = psci_function_id[PSCI_FN_CPU_ON];
err = invoke_psci_fn(fn, cpuid, entry_point, 0);
return psci_to_linux_errno(err);
}
static int psci_migrate(unsigned long cpuid)
{
int err;
u32 fn;
fn = psci_function_id[PSCI_FN_MIGRATE];
err = invoke_psci_fn(fn, cpuid, 0, 0);
return psci_to_linux_errno(err);
}
static int psci_affinity_info(unsigned long target_affinity,
unsigned long lowest_affinity_level)
{
return invoke_psci_fn(PSCI_FN_NATIVE(0_2, AFFINITY_INFO),
target_affinity, lowest_affinity_level, 0);
}
static int psci_migrate_info_type(void)
{
return invoke_psci_fn(PSCI_0_2_FN_MIGRATE_INFO_TYPE, 0, 0, 0);
}
static unsigned long psci_migrate_info_up_cpu(void)
{
return invoke_psci_fn(PSCI_FN_NATIVE(0_2, MIGRATE_INFO_UP_CPU),
0, 0, 0);
}
static int get_set_conduit_method(struct device_node *np)
{
const char *method;
pr_info("probing for conduit method from DT.\n");
if (of_property_read_string(np, "method", &method)) {
pr_warn("missing \"method\" property\n");
return -ENXIO;
}
if (!strcmp("hvc", method)) {
invoke_psci_fn = __invoke_psci_fn_hvc;
} else if (!strcmp("smc", method)) {
invoke_psci_fn = __invoke_psci_fn_smc;
} else {
pr_warn("invalid \"method\" property: %s\n", method);
return -EINVAL;
}
return 0;
}
static void psci_sys_reset(enum reboot_mode reboot_mode, const char *cmd)
{
invoke_psci_fn(PSCI_0_2_FN_SYSTEM_RESET, 0, 0, 0);
}
static void psci_sys_poweroff(void)
{
invoke_psci_fn(PSCI_0_2_FN_SYSTEM_OFF, 0, 0, 0);
}
static int __init psci_features(u32 psci_func_id)
{
return invoke_psci_fn(PSCI_1_0_FN_PSCI_FEATURES,
psci_func_id, 0, 0);
}
static int psci_dt_cpu_init_idle(struct device_node *cpu_node, int cpu)
{
int i, ret, count = 0;
u32 *psci_states;
struct device_node *state_node;
if (!psci_ops.cpu_suspend)
return -EOPNOTSUPP;
while ((state_node = of_parse_phandle(cpu_node, "cpu-idle-states",
count))) {
count++;
of_node_put(state_node);
}
if (!count)
return -ENODEV;
psci_states = kcalloc(count, sizeof(*psci_states), GFP_KERNEL);
if (!psci_states)
return -ENOMEM;
for (i = 0; i < count; i++) {
u32 state;
state_node = of_parse_phandle(cpu_node, "cpu-idle-states", i);
ret = of_property_read_u32(state_node,
"arm,psci-suspend-param",
&state);
if (ret) {
pr_warn(" * %s missing arm,psci-suspend-param property\n",
state_node->full_name);
of_node_put(state_node);
goto free_mem;
}
of_node_put(state_node);
pr_debug("psci-power-state %#x index %d\n", state, i);
if (!psci_power_state_is_valid(state)) {
pr_warn("Invalid PSCI power state %#x\n", state);
ret = -EINVAL;
goto free_mem;
}
psci_states[i] = state;
}
per_cpu(psci_power_state, cpu) = psci_states;
return 0;
free_mem:
kfree(psci_states);
return ret;
}
int psci_cpu_init_idle(unsigned int cpu)
{
struct device_node *cpu_node;
int ret;
cpu_node = of_get_cpu_node(cpu, NULL);
if (!cpu_node)
return -ENODEV;
ret = psci_dt_cpu_init_idle(cpu_node, cpu);
of_node_put(cpu_node);
return ret;
}
static int psci_suspend_finisher(unsigned long index)
{
u32 *state = __this_cpu_read(psci_power_state);
return psci_ops.cpu_suspend(state[index - 1],
virt_to_phys(cpu_resume));
}
int psci_cpu_suspend_enter(unsigned long index)
{
int ret;
u32 *state = __this_cpu_read(psci_power_state);
if (WARN_ON_ONCE(!index))
return -EINVAL;
if (!psci_power_state_loses_context(state[index - 1]))
ret = psci_ops.cpu_suspend(state[index - 1], 0);
else
ret = cpu_suspend(index, psci_suspend_finisher);
return ret;
}
static int psci_system_suspend(unsigned long unused)
{
return invoke_psci_fn(PSCI_FN_NATIVE(1_0, SYSTEM_SUSPEND),
virt_to_phys(cpu_resume), 0, 0);
}
static int psci_system_suspend_enter(suspend_state_t state)
{
return cpu_suspend(0, psci_system_suspend);
}
static void __init psci_init_system_suspend(void)
{
int ret;
if (!IS_ENABLED(CONFIG_SUSPEND))
return;
ret = psci_features(PSCI_FN_NATIVE(1_0, SYSTEM_SUSPEND));
if (ret != PSCI_RET_NOT_SUPPORTED)
suspend_set_ops(&psci_suspend_ops);
}
static void __init psci_init_cpu_suspend(void)
{
int feature = psci_features(psci_function_id[PSCI_FN_CPU_SUSPEND]);
if (feature != PSCI_RET_NOT_SUPPORTED)
psci_cpu_suspend_feature = feature;
}
static void __init psci_init_migrate(void)
{
unsigned long cpuid;
int type, cpu = -1;
type = psci_ops.migrate_info_type();
if (type == PSCI_0_2_TOS_MP) {
pr_info("Trusted OS migration not required\n");
return;
}
if (type == PSCI_RET_NOT_SUPPORTED) {
pr_info("MIGRATE_INFO_TYPE not supported.\n");
return;
}
if (type != PSCI_0_2_TOS_UP_MIGRATE &&
type != PSCI_0_2_TOS_UP_NO_MIGRATE) {
pr_err("MIGRATE_INFO_TYPE returned unknown type (%d)\n", type);
return;
}
cpuid = psci_migrate_info_up_cpu();
if (cpuid & ~MPIDR_HWID_BITMASK) {
pr_warn("MIGRATE_INFO_UP_CPU reported invalid physical ID (0x%lx)\n",
cpuid);
return;
}
cpu = get_logical_index(cpuid);
resident_cpu = cpu >= 0 ? cpu : -1;
pr_info("Trusted OS resident on physical CPU 0x%lx\n", cpuid);
}
static void __init psci_0_2_set_functions(void)
{
pr_info("Using standard PSCI v0.2 function IDs\n");
psci_function_id[PSCI_FN_CPU_SUSPEND] =
PSCI_FN_NATIVE(0_2, CPU_SUSPEND);
psci_ops.cpu_suspend = psci_cpu_suspend;
psci_function_id[PSCI_FN_CPU_OFF] = PSCI_0_2_FN_CPU_OFF;
psci_ops.cpu_off = psci_cpu_off;
psci_function_id[PSCI_FN_CPU_ON] = PSCI_FN_NATIVE(0_2, CPU_ON);
psci_ops.cpu_on = psci_cpu_on;
psci_function_id[PSCI_FN_MIGRATE] = PSCI_FN_NATIVE(0_2, MIGRATE);
psci_ops.migrate = psci_migrate;
psci_ops.affinity_info = psci_affinity_info;
psci_ops.migrate_info_type = psci_migrate_info_type;
arm_pm_restart = psci_sys_reset;
pm_power_off = psci_sys_poweroff;
}
static int __init psci_probe(void)
{
u32 ver = psci_get_version();
pr_info("PSCIv%d.%d detected in firmware.\n",
PSCI_VERSION_MAJOR(ver),
PSCI_VERSION_MINOR(ver));
if (PSCI_VERSION_MAJOR(ver) == 0 && PSCI_VERSION_MINOR(ver) < 2) {
pr_err("Conflicting PSCI version detected.\n");
return -EINVAL;
}
psci_0_2_set_functions();
psci_init_migrate();
if (PSCI_VERSION_MAJOR(ver) >= 1) {
psci_init_cpu_suspend();
psci_init_system_suspend();
}
return 0;
}
static int __init psci_0_2_init(struct device_node *np)
{
int err;
err = get_set_conduit_method(np);
if (err)
goto out_put_node;
err = psci_probe();
out_put_node:
of_node_put(np);
return err;
}
static int __init psci_0_1_init(struct device_node *np)
{
u32 id;
int err;
err = get_set_conduit_method(np);
if (err)
goto out_put_node;
pr_info("Using PSCI v0.1 Function IDs from DT\n");
if (!of_property_read_u32(np, "cpu_suspend", &id)) {
psci_function_id[PSCI_FN_CPU_SUSPEND] = id;
psci_ops.cpu_suspend = psci_cpu_suspend;
}
if (!of_property_read_u32(np, "cpu_off", &id)) {
psci_function_id[PSCI_FN_CPU_OFF] = id;
psci_ops.cpu_off = psci_cpu_off;
}
if (!of_property_read_u32(np, "cpu_on", &id)) {
psci_function_id[PSCI_FN_CPU_ON] = id;
psci_ops.cpu_on = psci_cpu_on;
}
if (!of_property_read_u32(np, "migrate", &id)) {
psci_function_id[PSCI_FN_MIGRATE] = id;
psci_ops.migrate = psci_migrate;
}
out_put_node:
of_node_put(np);
return err;
}
int __init psci_dt_init(void)
{
struct device_node *np;
const struct of_device_id *matched_np;
psci_initcall_t init_fn;
np = of_find_matching_node_and_match(NULL, psci_of_match, &matched_np);
if (!np)
return -ENODEV;
init_fn = (psci_initcall_t)matched_np->data;
return init_fn(np);
}
int __init psci_acpi_init(void)
{
if (!acpi_psci_present()) {
pr_info("is not implemented in ACPI.\n");
return -EOPNOTSUPP;
}
pr_info("probing for conduit method from ACPI.\n");
if (acpi_psci_use_hvc())
invoke_psci_fn = __invoke_psci_fn_hvc;
else
invoke_psci_fn = __invoke_psci_fn_smc;
return psci_probe();
}
