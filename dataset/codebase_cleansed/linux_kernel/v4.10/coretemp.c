static ssize_t show_label(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct platform_data *pdata = dev_get_drvdata(dev);
struct temp_data *tdata = pdata->core_data[attr->index];
if (tdata->is_pkg_data)
return sprintf(buf, "Package id %u\n", pdata->pkg_id);
return sprintf(buf, "Core %u\n", tdata->cpu_core_id);
}
static ssize_t show_crit_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
u32 eax, edx;
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct platform_data *pdata = dev_get_drvdata(dev);
struct temp_data *tdata = pdata->core_data[attr->index];
mutex_lock(&tdata->update_lock);
rdmsr_on_cpu(tdata->cpu, tdata->status_reg, &eax, &edx);
mutex_unlock(&tdata->update_lock);
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
tdata->temp = tdata->tjmax - ((eax >> 16) & 0x7f) * 1000;
tdata->valid = 1;
tdata->last_updated = jiffies;
}
mutex_unlock(&tdata->update_lock);
return sprintf(buf, "%d\n", tdata->temp);
}
static int adjust_tjmax(struct cpuinfo_x86 *c, u32 id, struct device *dev)
{
int tjmax = 100000;
int tjmax_ee = 85000;
int usemsr_ee = 1;
int err;
u32 eax, edx;
int i;
struct pci_dev *host_bridge = pci_get_bus_and_slot(0, PCI_DEVFN(0, 0));
if (host_bridge && host_bridge->vendor == PCI_VENDOR_ID_INTEL) {
for (i = 0; i < ARRAY_SIZE(tjmax_pci_table); i++) {
if (host_bridge->device == tjmax_pci_table[i].device)
return tjmax_pci_table[i].tjmax;
}
}
for (i = 0; i < ARRAY_SIZE(tjmax_table); i++) {
if (strstr(c->x86_model_id, tjmax_table[i].id))
return tjmax_table[i].tjmax;
}
for (i = 0; i < ARRAY_SIZE(tjmax_model_table); i++) {
const struct tjmax_model *tm = &tjmax_model_table[i];
if (c->x86_model == tm->model &&
(tm->mask == ANY || c->x86_mask == tm->mask))
return tm->tjmax;
}
if (c->x86_model == 0xf && c->x86_mask < 4)
usemsr_ee = 0;
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
static bool cpu_has_tjmax(struct cpuinfo_x86 *c)
{
u8 model = c->x86_model;
return model > 0xe &&
model != 0x1c &&
model != 0x26 &&
model != 0x27 &&
model != 0x35 &&
model != 0x36;
}
static int get_tjmax(struct cpuinfo_x86 *c, u32 id, struct device *dev)
{
int err;
u32 eax, edx;
u32 val;
err = rdmsr_safe_on_cpu(id, MSR_IA32_TEMPERATURE_TARGET, &eax, &edx);
if (err) {
if (cpu_has_tjmax(c))
dev_warn(dev, "Unable to read TjMax from CPU %u\n", id);
} else {
val = (eax >> 16) & 0xff;
if (val) {
dev_dbg(dev, "TjMax is %d degrees C\n", val);
return val * 1000;
}
}
if (force_tjmax) {
dev_notice(dev, "TjMax forced to %d degrees C by user\n",
force_tjmax);
return force_tjmax * 1000;
}
return adjust_tjmax(c, id, dev);
}
static int create_core_attrs(struct temp_data *tdata, struct device *dev,
int attr_no)
{
int i;
static ssize_t (*const rd_ptr[TOTAL_ATTRS]) (struct device *dev,
struct device_attribute *devattr, char *buf) = {
show_label, show_crit_alarm, show_temp, show_tjmax,
show_ttarget };
static const char *const suffixes[TOTAL_ATTRS] = {
"label", "crit_alarm", "input", "crit", "max"
};
for (i = 0; i < tdata->attr_size; i++) {
snprintf(tdata->attr_name[i], CORETEMP_NAME_LENGTH,
"temp%d_%s", attr_no, suffixes[i]);
sysfs_attr_init(&tdata->sd_attrs[i].dev_attr.attr);
tdata->sd_attrs[i].dev_attr.attr.name = tdata->attr_name[i];
tdata->sd_attrs[i].dev_attr.attr.mode = S_IRUGO;
tdata->sd_attrs[i].dev_attr.show = rd_ptr[i];
tdata->sd_attrs[i].index = attr_no;
tdata->attrs[i] = &tdata->sd_attrs[i].dev_attr.attr;
}
tdata->attr_group.attrs = tdata->attrs;
return sysfs_create_group(&dev->kobj, &tdata->attr_group);
}
static int chk_ucode_version(unsigned int cpu)
{
struct cpuinfo_x86 *c = &cpu_data(cpu);
if (c->x86_model == 0xe && c->x86_mask < 0xc && c->microcode < 0x39) {
pr_err("Errata AE18 not fixed, update BIOS or microcode of the CPU!\n");
return -ENODEV;
}
return 0;
}
static struct platform_device *coretemp_get_pdev(unsigned int cpu)
{
int pkgid = topology_logical_package_id(cpu);
if (pkgid >= 0 && pkgid < max_packages)
return pkg_devices[pkgid];
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
tdata->attr_size = MAX_CORE_ATTRS;
mutex_init(&tdata->update_lock);
return tdata;
}
static int create_core_data(struct platform_device *pdev, unsigned int cpu,
int pkg_flag)
{
struct temp_data *tdata;
struct platform_data *pdata = platform_get_drvdata(pdev);
struct cpuinfo_x86 *c = &cpu_data(cpu);
u32 eax, edx;
int err, attr_no;
attr_no = pkg_flag ? PKG_SYSFS_ATTR_NO : TO_ATTR_NO(cpu);
if (attr_no > MAX_CORE_DATA - 1)
return -ERANGE;
tdata = init_temp_data(cpu, pkg_flag);
if (!tdata)
return -ENOMEM;
err = rdmsr_safe_on_cpu(cpu, tdata->status_reg, &eax, &edx);
if (err)
goto exit_free;
tdata->tjmax = get_tjmax(c, cpu, &pdev->dev);
if (c->x86_model > 0xe && c->x86_model != 0x1c) {
err = rdmsr_safe_on_cpu(cpu, MSR_IA32_TEMPERATURE_TARGET,
&eax, &edx);
if (!err) {
tdata->ttarget
= tdata->tjmax - ((eax >> 8) & 0xff) * 1000;
tdata->attr_size++;
}
}
pdata->core_data[attr_no] = tdata;
err = create_core_attrs(tdata, pdata->hwmon_dev, attr_no);
if (err)
goto exit_free;
return 0;
exit_free:
pdata->core_data[attr_no] = NULL;
kfree(tdata);
return err;
}
static void
coretemp_add_core(struct platform_device *pdev, unsigned int cpu, int pkg_flag)
{
if (create_core_data(pdev, cpu, pkg_flag))
dev_err(&pdev->dev, "Adding Core %u failed\n", cpu);
}
static void coretemp_remove_core(struct platform_data *pdata, int indx)
{
struct temp_data *tdata = pdata->core_data[indx];
sysfs_remove_group(&pdata->hwmon_dev->kobj, &tdata->attr_group);
kfree(pdata->core_data[indx]);
pdata->core_data[indx] = NULL;
}
static int coretemp_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct platform_data *pdata;
pdata = devm_kzalloc(dev, sizeof(struct platform_data), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
pdata->pkg_id = pdev->id;
platform_set_drvdata(pdev, pdata);
pdata->hwmon_dev = devm_hwmon_device_register_with_groups(dev, DRVNAME,
pdata, NULL);
return PTR_ERR_OR_ZERO(pdata->hwmon_dev);
}
static int coretemp_remove(struct platform_device *pdev)
{
struct platform_data *pdata = platform_get_drvdata(pdev);
int i;
for (i = MAX_CORE_DATA - 1; i >= 0; --i)
if (pdata->core_data[i])
coretemp_remove_core(pdata, i);
return 0;
}
static struct platform_device *coretemp_device_add(unsigned int cpu)
{
int err, pkgid = topology_logical_package_id(cpu);
struct platform_device *pdev;
if (pkgid < 0)
return ERR_PTR(-ENOMEM);
pdev = platform_device_alloc(DRVNAME, pkgid);
if (!pdev)
return ERR_PTR(-ENOMEM);
err = platform_device_add(pdev);
if (err) {
platform_device_put(pdev);
return ERR_PTR(err);
}
pkg_devices[pkgid] = pdev;
return pdev;
}
static int coretemp_cpu_online(unsigned int cpu)
{
struct platform_device *pdev = coretemp_get_pdev(cpu);
struct cpuinfo_x86 *c = &cpu_data(cpu);
struct platform_data *pdata;
if (!cpu_has(c, X86_FEATURE_DTHERM))
return -ENODEV;
if (!pdev) {
if (chk_ucode_version(cpu))
return -EINVAL;
pdev = coretemp_device_add(cpu);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
if (cpu_has(c, X86_FEATURE_PTS))
coretemp_add_core(pdev, cpu, 1);
}
pdata = platform_get_drvdata(pdev);
if (!cpumask_intersects(&pdata->cpumask, topology_sibling_cpumask(cpu)))
coretemp_add_core(pdev, cpu, 0);
cpumask_set_cpu(cpu, &pdata->cpumask);
return 0;
}
static int coretemp_cpu_offline(unsigned int cpu)
{
struct platform_device *pdev = coretemp_get_pdev(cpu);
struct platform_data *pd;
struct temp_data *tdata;
int indx, target;
if (!pdev)
return 0;
indx = TO_ATTR_NO(cpu);
if (indx > MAX_CORE_DATA - 1)
return 0;
pd = platform_get_drvdata(pdev);
tdata = pd->core_data[indx];
cpumask_clear_cpu(cpu, &pd->cpumask);
target = cpumask_any_and(&pd->cpumask, topology_sibling_cpumask(cpu));
if (target >= nr_cpu_ids) {
coretemp_remove_core(pd, indx);
} else if (tdata && tdata->cpu == cpu) {
mutex_lock(&tdata->update_lock);
tdata->cpu = target;
mutex_unlock(&tdata->update_lock);
}
if (cpumask_empty(&pd->cpumask)) {
pkg_devices[topology_logical_package_id(cpu)] = NULL;
platform_device_unregister(pdev);
return 0;
}
tdata = pd->core_data[PKG_SYSFS_ATTR_NO];
if (tdata && tdata->cpu == cpu) {
target = cpumask_first(&pd->cpumask);
mutex_lock(&tdata->update_lock);
tdata->cpu = target;
mutex_unlock(&tdata->update_lock);
}
return 0;
}
static int __init coretemp_init(void)
{
int err;
if (!x86_match_cpu(coretemp_ids))
return -ENODEV;
max_packages = topology_max_packages();
pkg_devices = kzalloc(max_packages * sizeof(struct platform_device *),
GFP_KERNEL);
if (!pkg_devices)
return -ENOMEM;
err = platform_driver_register(&coretemp_driver);
if (err)
return err;
err = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "hwmon/coretemp:online",
coretemp_cpu_online, coretemp_cpu_offline);
if (err < 0)
goto outdrv;
coretemp_hp_online = err;
return 0;
outdrv:
platform_driver_unregister(&coretemp_driver);
kfree(pkg_devices);
return err;
}
static void __exit coretemp_exit(void)
{
cpuhp_remove_state(coretemp_hp_online);
platform_driver_unregister(&coretemp_driver);
kfree(pkg_devices);
}
