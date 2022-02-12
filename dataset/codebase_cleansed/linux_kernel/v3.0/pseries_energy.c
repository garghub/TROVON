static int check_for_h_best_energy(void)
{
struct device_node *rtas = NULL;
const char *hypertas, *s;
int length;
int rc = 0;
rtas = of_find_node_by_path("/rtas");
if (!rtas)
return 0;
hypertas = of_get_property(rtas, "ibm,hypertas-functions", &length);
if (!hypertas) {
of_node_put(rtas);
return 0;
}
for (s = hypertas; s < hypertas + length; s += strlen(s) + 1) {
if (!strncmp("hcall-best-energy-1", s, 19)) {
rc = 1;
break;
}
}
of_node_put(rtas);
return rc;
}
static u32 cpu_to_drc_index(int cpu)
{
struct device_node *dn = NULL;
const int *indexes;
int i;
int rc = 1;
u32 ret = 0;
dn = of_find_node_by_path("/cpus");
if (dn == NULL)
goto err;
indexes = of_get_property(dn, "ibm,drc-indexes", NULL);
if (indexes == NULL)
goto err_of_node_put;
i = cpu_core_index_of_thread(cpu);
WARN_ON(i > indexes[0]);
ret = indexes[i + 1];
rc = 0;
err_of_node_put:
of_node_put(dn);
err:
if (rc)
printk(KERN_WARNING "cpu_to_drc_index(%d) failed", cpu);
return ret;
}
static int drc_index_to_cpu(u32 drc_index)
{
struct device_node *dn = NULL;
const int *indexes;
int i, cpu = 0;
int rc = 1;
dn = of_find_node_by_path("/cpus");
if (dn == NULL)
goto err;
indexes = of_get_property(dn, "ibm,drc-indexes", NULL);
if (indexes == NULL)
goto err_of_node_put;
for (i = 0; i < indexes[0]; i++) {
if (indexes[i + 1] == drc_index)
break;
}
cpu = cpu_first_thread_of_core(i);
rc = 0;
err_of_node_put:
of_node_put(dn);
err:
if (rc)
printk(KERN_WARNING "drc_index_to_cpu(%d) failed", drc_index);
return cpu;
}
static ssize_t get_best_energy_list(char *page, int activate)
{
int rc, cnt, i, cpu;
unsigned long retbuf[PLPAR_HCALL9_BUFSIZE];
unsigned long flags = 0;
u32 *buf_page;
char *s = page;
buf_page = (u32 *) get_zeroed_page(GFP_KERNEL);
if (!buf_page)
return -ENOMEM;
flags = FLAGS_MODE1;
if (activate)
flags |= FLAGS_ACTIVATE;
rc = plpar_hcall9(H_BEST_ENERGY, retbuf, flags, 0, __pa(buf_page),
0, 0, 0, 0, 0, 0);
if (rc != H_SUCCESS) {
free_page((unsigned long) buf_page);
return -EINVAL;
}
cnt = retbuf[0];
for (i = 0; i < cnt; i++) {
cpu = drc_index_to_cpu(buf_page[2*i+1]);
if ((cpu_online(cpu) && !activate) ||
(!cpu_online(cpu) && activate))
s += sprintf(s, "%d,", cpu);
}
if (s > page) {
s--;
s += sprintf(s, "\n");
}
free_page((unsigned long) buf_page);
return s-page;
}
static ssize_t get_best_energy_data(struct sys_device *dev,
char *page, int activate)
{
int rc;
unsigned long retbuf[PLPAR_HCALL9_BUFSIZE];
unsigned long flags = 0;
flags = FLAGS_MODE2;
if (activate)
flags |= FLAGS_ACTIVATE;
rc = plpar_hcall9(H_BEST_ENERGY, retbuf, flags,
cpu_to_drc_index(dev->id),
0, 0, 0, 0, 0, 0, 0);
if (rc != H_SUCCESS)
return -EINVAL;
return sprintf(page, "%lu\n", retbuf[1] >> 32);
}
static ssize_t cpu_activate_hint_list_show(struct sysdev_class *class,
struct sysdev_class_attribute *attr, char *page)
{
return get_best_energy_list(page, 1);
}
static ssize_t cpu_deactivate_hint_list_show(struct sysdev_class *class,
struct sysdev_class_attribute *attr, char *page)
{
return get_best_energy_list(page, 0);
}
static ssize_t percpu_activate_hint_show(struct sys_device *dev,
struct sysdev_attribute *attr, char *page)
{
return get_best_energy_data(dev, page, 1);
}
static ssize_t percpu_deactivate_hint_show(struct sys_device *dev,
struct sysdev_attribute *attr, char *page)
{
return get_best_energy_data(dev, page, 0);
}
static int __init pseries_energy_init(void)
{
int cpu, err;
struct sys_device *cpu_sys_dev;
if (!check_for_h_best_energy()) {
printk(KERN_INFO "Hypercall H_BEST_ENERGY not supported\n");
return 0;
}
err = sysfs_create_file(&cpu_sysdev_class.kset.kobj,
&attr_cpu_activate_hint_list.attr);
if (!err)
err = sysfs_create_file(&cpu_sysdev_class.kset.kobj,
&attr_cpu_deactivate_hint_list.attr);
if (err)
return err;
for_each_possible_cpu(cpu) {
cpu_sys_dev = get_cpu_sysdev(cpu);
err = sysfs_create_file(&cpu_sys_dev->kobj,
&attr_percpu_activate_hint.attr);
if (err)
break;
err = sysfs_create_file(&cpu_sys_dev->kobj,
&attr_percpu_deactivate_hint.attr);
if (err)
break;
}
if (err)
return err;
sysfs_entries = 1;
return 0;
}
static void __exit pseries_energy_cleanup(void)
{
int cpu;
struct sys_device *cpu_sys_dev;
if (!sysfs_entries)
return;
sysfs_remove_file(&cpu_sysdev_class.kset.kobj,
&attr_cpu_activate_hint_list.attr);
sysfs_remove_file(&cpu_sysdev_class.kset.kobj,
&attr_cpu_deactivate_hint_list.attr);
for_each_possible_cpu(cpu) {
cpu_sys_dev = get_cpu_sysdev(cpu);
sysfs_remove_file(&cpu_sys_dev->kobj,
&attr_percpu_activate_hint.attr);
sysfs_remove_file(&cpu_sys_dev->kobj,
&attr_percpu_deactivate_hint.attr);
}
}
