static int cpu_has_cpufreq(unsigned int cpu)
{
struct cpufreq_policy policy;
if (!acpi_thermal_cpufreq_is_init || cpufreq_get_policy(&policy, cpu))
return 0;
return 1;
}
static int acpi_thermal_cpufreq_notifier(struct notifier_block *nb,
unsigned long event, void *data)
{
struct cpufreq_policy *policy = data;
unsigned long max_freq = 0;
if (event != CPUFREQ_ADJUST)
goto out;
max_freq = (
policy->cpuinfo.max_freq *
(100 - per_cpu(cpufreq_thermal_reduction_pctg, policy->cpu) * 20)
) / 100;
cpufreq_verify_within_limits(policy, 0, max_freq);
out:
return 0;
}
static int cpufreq_get_max_state(unsigned int cpu)
{
if (!cpu_has_cpufreq(cpu))
return 0;
return CPUFREQ_THERMAL_MAX_STEP;
}
static int cpufreq_get_cur_state(unsigned int cpu)
{
if (!cpu_has_cpufreq(cpu))
return 0;
return per_cpu(cpufreq_thermal_reduction_pctg, cpu);
}
static int cpufreq_set_cur_state(unsigned int cpu, int state)
{
if (!cpu_has_cpufreq(cpu))
return 0;
per_cpu(cpufreq_thermal_reduction_pctg, cpu) = state;
cpufreq_update_policy(cpu);
return 0;
}
void acpi_thermal_cpufreq_init(void)
{
int i;
for (i = 0; i < nr_cpu_ids; i++)
if (cpu_present(i))
per_cpu(cpufreq_thermal_reduction_pctg, i) = 0;
i = cpufreq_register_notifier(&acpi_thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
if (!i)
acpi_thermal_cpufreq_is_init = 1;
}
void acpi_thermal_cpufreq_exit(void)
{
if (acpi_thermal_cpufreq_is_init)
cpufreq_unregister_notifier
(&acpi_thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
acpi_thermal_cpufreq_is_init = 0;
}
static int cpufreq_get_max_state(unsigned int cpu)
{
return 0;
}
static int cpufreq_get_cur_state(unsigned int cpu)
{
return 0;
}
static int cpufreq_set_cur_state(unsigned int cpu, int state)
{
return 0;
}
int acpi_processor_get_limit_info(struct acpi_processor *pr)
{
if (!pr)
return -EINVAL;
if (pr->flags.throttling)
pr->flags.limit = 1;
return 0;
}
static int acpi_processor_max_state(struct acpi_processor *pr)
{
int max_state = 0;
max_state += cpufreq_get_max_state(pr->id);
if (pr->flags.throttling)
max_state += (pr->throttling.state_count -1);
return max_state;
}
static int
processor_get_max_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct acpi_device *device = cdev->devdata;
struct acpi_processor *pr = acpi_driver_data(device);
if (!device || !pr)
return -EINVAL;
*state = acpi_processor_max_state(pr);
return 0;
}
static int
processor_get_cur_state(struct thermal_cooling_device *cdev,
unsigned long *cur_state)
{
struct acpi_device *device = cdev->devdata;
struct acpi_processor *pr = acpi_driver_data(device);
if (!device || !pr)
return -EINVAL;
*cur_state = cpufreq_get_cur_state(pr->id);
if (pr->flags.throttling)
*cur_state += pr->throttling.state;
return 0;
}
static int
processor_set_cur_state(struct thermal_cooling_device *cdev,
unsigned long state)
{
struct acpi_device *device = cdev->devdata;
struct acpi_processor *pr = acpi_driver_data(device);
int result = 0;
int max_pstate;
if (!device || !pr)
return -EINVAL;
max_pstate = cpufreq_get_max_state(pr->id);
if (state > acpi_processor_max_state(pr))
return -EINVAL;
if (state <= max_pstate) {
if (pr->flags.throttling && pr->throttling.state)
result = acpi_processor_set_throttling(pr, 0, false);
cpufreq_set_cur_state(pr->id, state);
} else {
cpufreq_set_cur_state(pr->id, max_pstate);
result = acpi_processor_set_throttling(pr,
state - max_pstate, false);
}
return result;
}
