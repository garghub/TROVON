static const struct cpu_operations * __init cpu_get_ops(const char *name)
{
const struct cpu_operations **ops;
ops = acpi_disabled ? dt_supported_cpu_ops : acpi_supported_cpu_ops;
while (*ops) {
if (!strcmp(name, (*ops)->name))
return *ops;
ops++;
}
return NULL;
}
static const char *__init cpu_read_enable_method(int cpu)
{
const char *enable_method;
if (acpi_disabled) {
struct device_node *dn = of_get_cpu_node(cpu, NULL);
if (!dn) {
if (!cpu)
pr_err("Failed to find device node for boot cpu\n");
return NULL;
}
enable_method = of_get_property(dn, "enable-method", NULL);
if (!enable_method) {
if (cpu != 0)
pr_err("%s: missing enable-method property\n",
dn->full_name);
}
} else {
enable_method = acpi_get_enable_method(cpu);
if (!enable_method) {
if (cpu != 0)
pr_err("Unsupported ACPI enable-method\n");
}
}
return enable_method;
}
int __init cpu_read_ops(int cpu)
{
const char *enable_method = cpu_read_enable_method(cpu);
if (!enable_method)
return -ENODEV;
cpu_ops[cpu] = cpu_get_ops(enable_method);
if (!cpu_ops[cpu]) {
pr_warn("Unsupported enable-method: %s\n", enable_method);
return -EOPNOTSUPP;
}
return 0;
}
