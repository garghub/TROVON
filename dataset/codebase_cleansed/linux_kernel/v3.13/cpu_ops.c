static const struct cpu_operations * __init cpu_get_ops(const char *name)
{
const struct cpu_operations **ops = supported_cpu_ops;
while (*ops) {
if (!strcmp(name, (*ops)->name))
return *ops;
ops++;
}
return NULL;
}
int __init cpu_read_ops(struct device_node *dn, int cpu)
{
const char *enable_method = of_get_property(dn, "enable-method", NULL);
if (!enable_method) {
if (cpu != 0)
pr_err("%s: missing enable-method property\n",
dn->full_name);
return -ENOENT;
}
cpu_ops[cpu] = cpu_get_ops(enable_method);
if (!cpu_ops[cpu]) {
pr_warn("%s: unsupported enable-method property: %s\n",
dn->full_name, enable_method);
return -EOPNOTSUPP;
}
return 0;
}
void __init cpu_read_bootcpu_ops(void)
{
struct device_node *dn = of_get_cpu_node(0, NULL);
if (!dn) {
pr_err("Failed to find device node for boot cpu\n");
return;
}
cpu_read_ops(dn, 0);
}
