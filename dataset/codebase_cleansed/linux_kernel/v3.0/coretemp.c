static ssize_t show_name(struct device *dev,
struct device_attribute *devattr, char *buf)
{
return sprintf(buf, "%s\n", DRVNAME);
}
static ssize_t show_label(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct platform_data *pdata = dev_get_drvdata(dev);
struct temp_data *tdata = pdata->core_data[attr->index];
if (tdata->is_pkg_data)
return sprintf(buf, "Physical id %u\n", pdata->phys_proc_id);
return sprintf(buf, "Core %u\n", tdata->cpu_core_id);
}
static ssize_t show_crit_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
u32 eax, edx;
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct platform_data *pdata = dev_get_drvdata(dev);
struct temp_data *tdata = pdata->core_data[attr->index];
rdmsr_on_cpu(tdata->cpu, tdata->status_reg, &eax, &edx);
return sprintf(buf, "%d\n", (eax >> 5) & 1);
}
static ssize_t show_tjmax(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct platform_data *pdata = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", pdata->core_data[attr->index]->tjmax);
}
static ssize_t show_ttarget(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct platform_data *pdata = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", pdata->core_data[attr->index]->ttarget);
}
static ssize_t show_temp(struct device *dev,
struct device_attribute *devattr, char *buf)
{
u32 eax, edx;
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct platform_data *pdata = dev_get_drvdata(dev);
struct temp_data *tdata = pdata->core_data[attr->index];
mutex_lock(&tdata->update_lock);
if (!tdata->valid || time_after(jiffies, tdata->last_updated + HZ)) {
rdmsr_on_cpu(tdata->cpu, tdata->status_reg, &eax, &edx);
tdata->valid = 0;
if (eax & 0x80000000) {
tdata->temp = tdata->tjmax -
((eax >> 16) & 0x7f) * 1000;
tdata->valid = 1;
}
tdata->last_updated = jiffies;
}
mutex_unlock(&tdata->update_lock);
return tdata->valid ? sprintf(buf, "%d\n", tdata->temp) : -EAGAIN;
}
static int adjust_tjmax(struct cpuinfo_x86 *c, u32 id, struct device *dev)
{
int tjmax = 100000;
int tjmax_ee = 85000;
int usemsr_ee = 1;
int err;
u32 eax, edx;
struct pci_dev *host_bridge;
if (c->x86_model == 0xf && c->x86_mask < 4)
usemsr_ee = 0;
if (c->x86_model == 0x1c) {
usemsr_ee = 0;
host_bridge = pci_get_bus_and_slot(0, PCI_DEVFN(0, 0));
if (host_bridge && host_bridge->vendor == PCI_VENDOR_ID_INTEL
&& (host_bridge->device == 0xa000
|| host_bridge->device == 0xa010))
tjmax = 100000;
else
tjmax = 90000;
pci_dev_put(host_bridge);
}
if (c->x86_model > 0xe && usemsr_ee) {
u8 platform_id;
err = rdmsr_safe_on_cpu(id, 0x17, &eax, &edx);
if (err) {
dev_warn(dev,
"Unable to access MSR 0x17, assuming desktop"
" CPU\n");
usemsr_ee = 0;
} else if (c->x86_model < 0x17 && !(eax & 0x10000000)) {
usemsr_ee = 0;
} else {
platform_id = (edx >> 18) & 0x7;
if (c->x86_model == 0x17 &&
(platform_id == 5 || platform_id == 7)) {
tjmax_ee = 90000;
tjmax = 105000;
}
}
}
if (usemsr_ee) {
err = rdmsr_safe_on_cpu(id, 0xee, &eax, &edx);
if (err) {
dev_warn(dev,
"Unable to access MSR 0xEE, for Tjmax, left"
" at default\n");
} else if (eax & 0x40000000) {
tjmax = tjmax_ee;
}
} else if (tjmax == 100000) {
dev_warn(dev, "Using relative temperature scale!\n");
}
return tjmax;
}
static int get_tjmax(struct cpuinfo_x86 *c, u32 id, struct device *dev)
{
int err;
u32 eax, edx;
u32 val;
err = rdmsr_safe_on_cpu(id, MSR_IA32_TEMPERATURE_TARGET, &eax, &edx);
if (err) {
dev_warn(dev, "Unable to read TjMax from CPU.\n");
} else {
val = (eax >> 16) & 0xff;
if (val) {
dev_info(dev, "TjMax is %d C.\n", val);
return val * 1000;
}
}
return adjust_tjmax(c, id, dev);
}
static void __devinit get_ucode_rev_on_cpu(void *edx)
{
u32 eax;
wrmsr(MSR_IA32_UCODE_REV, 0, 0);
sync_core();
rdmsr(MSR_IA32_UCODE_REV, eax, *(u32 *)edx);
}
static int get_pkg_tjmax(unsigned int cpu, struct device *dev)
{
int err;
u32 eax, edx, val;
err = rdmsr_safe_on_cpu(cpu, MSR_IA32_TEMPERATURE_TARGET, &eax, &edx);
if (!err) {
val = (eax >> 16) & 0xff;
if (val)
return val * 1000;
}
dev_warn(dev, "Unable to read Pkg-TjMax from CPU:%u\n", cpu);
return 100000;
}
static int create_name_attr(struct platform_data *pdata, struct device *dev)
{
sysfs_attr_init(&pdata->name_attr.attr);
pdata->name_attr.attr.name = "name";
pdata->name_attr.attr.mode = S_IRUGO;
pdata->name_attr.show = show_name;
return device_create_file(dev, &pdata->name_attr);
}
static int create_core_attrs(struct temp_data *tdata, struct device *dev,
int attr_no)
{
int err, i;
static ssize_t (*rd_ptr[MAX_ATTRS]) (struct device *dev,
struct device_attribute *devattr, char *buf) = {
show_label, show_crit_alarm, show_ttarget,
show_temp, show_tjmax }
void update_ttarget(__u8 cpu_model, struct temp_data *tdata,
struct device *dev)
{
int err;
u32 eax, edx;
tdata->ttarget = tdata->tjmax - 20000;
if (cpu_model > 0xe && cpu_model != 0x1c) {
err = rdmsr_safe_on_cpu(tdata->cpu,
MSR_IA32_TEMPERATURE_TARGET, &eax, &edx);
if (err) {
dev_warn(dev,
"Unable to read IA32_TEMPERATURE_TARGET MSR\n");
} else {
tdata->ttarget = tdata->tjmax -
((eax >> 8) & 0xff) * 1000;
}
}
}
static int __devinit chk_ucode_version(struct platform_device *pdev)
{
struct cpuinfo_x86 *c = &cpu_data(pdev->id);
int err;
u32 edx;
if (c->x86_model == 0xe && c->x86_mask < 0xc) {
err = smp_call_function_single(pdev->id, get_ucode_rev_on_cpu,
&edx, 1);
if (err) {
dev_err(&pdev->dev,
"Cannot determine microcode revision of "
"CPU#%u (%d)!\n", pdev->id, err);
return -ENODEV;
} else if (edx < 0x39) {
dev_err(&pdev->dev,
"Errata AE18 not fixed, update BIOS or "
"microcode of the CPU!\n");
return -ENODEV;
}
}
return 0;
}
static struct platform_device *coretemp_get_pdev(unsigned int cpu)
{
u16 phys_proc_id = TO_PHYS_ID(cpu);
struct pdev_entry *p;
mutex_lock(&pdev_list_mutex);
list_for_each_entry(p, &pdev_list, list)
if (p->phys_proc_id == phys_proc_id) {
mutex_unlock(&pdev_list_mutex);
return p->pdev;
}
mutex_unlock(&pdev_list_mutex);
return NULL;
}
static struct temp_data *init_temp_data(unsigned int cpu, int pkg_flag)
{
struct temp_data *tdata;
tdata = kzalloc(sizeof(struct temp_data), GFP_KERNEL);
if (!tdata)
return NULL;
tdata->status_reg = pkg_flag ? MSR_IA32_PACKAGE_THERM_STATUS :
MSR_IA32_THERM_STATUS;
tdata->is_pkg_data = pkg_flag;
tdata->cpu = cpu;
tdata->cpu_core_id = TO_CORE_ID(cpu);
mutex_init(&tdata->update_lock);
return tdata;
}
static int create_core_data(struct platform_data *pdata,
struct platform_device *pdev,
unsigned int cpu, int pkg_flag)
{
struct temp_data *tdata;
struct cpuinfo_x86 *c = &cpu_data(cpu);
u32 eax, edx;
int err, attr_no;
attr_no = pkg_flag ? 1 : TO_ATTR_NO(cpu);
if (attr_no > MAX_CORE_DATA - 1)
return -ERANGE;
if (pdata->core_data[attr_no] != NULL)
return 0;
tdata = init_temp_data(cpu, pkg_flag);
if (!tdata)
return -ENOMEM;
err = rdmsr_safe_on_cpu(cpu, tdata->status_reg, &eax, &edx);
if (err)
goto exit_free;
if (pkg_flag)
tdata->tjmax = get_pkg_tjmax(pdev->id, &pdev->dev);
else
tdata->tjmax = get_tjmax(c, cpu, &pdev->dev);
update_ttarget(c->x86_model, tdata, &pdev->dev);
pdata->core_data[attr_no] = tdata;
err = create_core_attrs(tdata, &pdev->dev, attr_no);
if (err)
goto exit_free;
return 0;
exit_free:
kfree(tdata);
return err;
}
static void coretemp_add_core(unsigned int cpu, int pkg_flag)
{
struct platform_data *pdata;
struct platform_device *pdev = coretemp_get_pdev(cpu);
int err;
if (!pdev)
return;
pdata = platform_get_drvdata(pdev);
err = create_core_data(pdata, pdev, cpu, pkg_flag);
if (err)
dev_err(&pdev->dev, "Adding Core %u failed\n", cpu);
}
static void coretemp_remove_core(struct platform_data *pdata,
struct device *dev, int indx)
{
int i;
struct temp_data *tdata = pdata->core_data[indx];
for (i = 0; i < MAX_ATTRS; i++)
device_remove_file(dev, &tdata->sd_attrs[i].dev_attr);
kfree(pdata->core_data[indx]);
pdata->core_data[indx] = NULL;
}
static int __devinit coretemp_probe(struct platform_device *pdev)
{
struct platform_data *pdata;
int err;
err = chk_ucode_version(pdev);
if (err)
return err;
pdata = kzalloc(sizeof(struct platform_data), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
err = create_name_attr(pdata, &pdev->dev);
if (err)
goto exit_free;
pdata->phys_proc_id = TO_PHYS_ID(pdev->id);
platform_set_drvdata(pdev, pdata);
pdata->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(pdata->hwmon_dev)) {
err = PTR_ERR(pdata->hwmon_dev);
dev_err(&pdev->dev, "Class registration failed (%d)\n", err);
goto exit_name;
}
return 0;
exit_name:
device_remove_file(&pdev->dev, &pdata->name_attr);
platform_set_drvdata(pdev, NULL);
exit_free:
kfree(pdata);
return err;
}
static int __devexit coretemp_remove(struct platform_device *pdev)
{
struct platform_data *pdata = platform_get_drvdata(pdev);
int i;
for (i = MAX_CORE_DATA - 1; i >= 0; --i)
if (pdata->core_data[i])
coretemp_remove_core(pdata, &pdev->dev, i);
device_remove_file(&pdev->dev, &pdata->name_attr);
hwmon_device_unregister(pdata->hwmon_dev);
platform_set_drvdata(pdev, NULL);
kfree(pdata);
return 0;
}
static int __cpuinit coretemp_device_add(unsigned int cpu)
{
int err;
struct platform_device *pdev;
struct pdev_entry *pdev_entry;
mutex_lock(&pdev_list_mutex);
pdev = platform_device_alloc(DRVNAME, cpu);
if (!pdev) {
err = -ENOMEM;
pr_err("Device allocation failed\n");
goto exit;
}
pdev_entry = kzalloc(sizeof(struct pdev_entry), GFP_KERNEL);
if (!pdev_entry) {
err = -ENOMEM;
goto exit_device_put;
}
err = platform_device_add(pdev);
if (err) {
pr_err("Device addition failed (%d)\n", err);
goto exit_device_free;
}
pdev_entry->pdev = pdev;
pdev_entry->phys_proc_id = TO_PHYS_ID(cpu);
list_add_tail(&pdev_entry->list, &pdev_list);
mutex_unlock(&pdev_list_mutex);
return 0;
exit_device_free:
kfree(pdev_entry);
exit_device_put:
platform_device_put(pdev);
exit:
mutex_unlock(&pdev_list_mutex);
return err;
}
static void coretemp_device_remove(unsigned int cpu)
{
struct pdev_entry *p, *n;
u16 phys_proc_id = TO_PHYS_ID(cpu);
mutex_lock(&pdev_list_mutex);
list_for_each_entry_safe(p, n, &pdev_list, list) {
if (p->phys_proc_id != phys_proc_id)
continue;
platform_device_unregister(p->pdev);
list_del(&p->list);
kfree(p);
}
mutex_unlock(&pdev_list_mutex);
}
static bool is_any_core_online(struct platform_data *pdata)
{
int i;
for (i = MAX_CORE_DATA - 1; i >= 0; --i) {
if (pdata->core_data[i] &&
!pdata->core_data[i]->is_pkg_data) {
return true;
}
}
return false;
}
static void __cpuinit get_core_online(unsigned int cpu)
{
struct cpuinfo_x86 *c = &cpu_data(cpu);
struct platform_device *pdev = coretemp_get_pdev(cpu);
int err;
if (!cpu_has(c, X86_FEATURE_DTS))
return;
if (!pdev) {
err = coretemp_device_add(cpu);
if (err)
return;
if (cpu_has(c, X86_FEATURE_PTS))
coretemp_add_core(cpu, 1);
}
coretemp_add_core(cpu, 0);
}
static void __cpuinit put_core_offline(unsigned int cpu)
{
int i, indx;
struct platform_data *pdata;
struct platform_device *pdev = coretemp_get_pdev(cpu);
if (!pdev)
return;
pdata = platform_get_drvdata(pdev);
indx = TO_ATTR_NO(cpu);
if (pdata->core_data[indx] && pdata->core_data[indx]->cpu == cpu)
coretemp_remove_core(pdata, &pdev->dev, indx);
for_each_sibling(i, cpu) {
if (i != cpu) {
get_core_online(i);
break;
}
}
if (!is_any_core_online(pdata))
coretemp_device_remove(cpu);
}
static int __cpuinit coretemp_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long) hcpu;
switch (action) {
case CPU_ONLINE:
case CPU_DOWN_FAILED:
get_core_online(cpu);
break;
case CPU_DOWN_PREPARE:
put_core_offline(cpu);
break;
}
return NOTIFY_OK;
}
static int __init coretemp_init(void)
{
int i, err = -ENODEV;
if (cpu_data(0).x86_vendor != X86_VENDOR_INTEL)
goto exit;
err = platform_driver_register(&coretemp_driver);
if (err)
goto exit;
for_each_online_cpu(i)
get_core_online(i);
#ifndef CONFIG_HOTPLUG_CPU
if (list_empty(&pdev_list)) {
err = -ENODEV;
goto exit_driver_unreg;
}
#endif
register_hotcpu_notifier(&coretemp_cpu_notifier);
return 0;
#ifndef CONFIG_HOTPLUG_CPU
exit_driver_unreg:
platform_driver_unregister(&coretemp_driver);
#endif
exit:
return err;
}
static void __exit coretemp_exit(void)
{
struct pdev_entry *p, *n;
unregister_hotcpu_notifier(&coretemp_cpu_notifier);
mutex_lock(&pdev_list_mutex);
list_for_each_entry_safe(p, n, &pdev_list, list) {
platform_device_unregister(p->pdev);
list_del(&p->list);
kfree(p);
}
mutex_unlock(&pdev_list_mutex);
platform_driver_unregister(&coretemp_driver);
}
