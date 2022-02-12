static int xen_pcpu_down(uint32_t cpu_id)
{
struct xen_platform_op op = {
.cmd = XENPF_cpu_offline,
.interface_version = XENPF_INTERFACE_VERSION,
.u.cpu_ol.cpuid = cpu_id,
};
return HYPERVISOR_dom0_op(&op);
}
static int xen_pcpu_up(uint32_t cpu_id)
{
struct xen_platform_op op = {
.cmd = XENPF_cpu_online,
.interface_version = XENPF_INTERFACE_VERSION,
.u.cpu_ol.cpuid = cpu_id,
};
return HYPERVISOR_dom0_op(&op);
}
static ssize_t show_online(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct pcpu *cpu = container_of(dev, struct pcpu, dev);
return sprintf(buf, "%u\n", !!(cpu->flags & XEN_PCPU_FLAGS_ONLINE));
}
static ssize_t __ref store_online(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct pcpu *pcpu = container_of(dev, struct pcpu, dev);
unsigned long long val;
ssize_t ret;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (kstrtoull(buf, 0, &val) < 0)
return -EINVAL;
switch (val) {
case 0:
ret = xen_pcpu_down(pcpu->cpu_id);
break;
case 1:
ret = xen_pcpu_up(pcpu->cpu_id);
break;
default:
ret = -EINVAL;
}
if (ret >= 0)
ret = count;
return ret;
}
static bool xen_pcpu_online(uint32_t flags)
{
return !!(flags & XEN_PCPU_FLAGS_ONLINE);
}
static void pcpu_online_status(struct xenpf_pcpuinfo *info,
struct pcpu *pcpu)
{
if (xen_pcpu_online(info->flags) &&
!xen_pcpu_online(pcpu->flags)) {
pcpu->flags |= XEN_PCPU_FLAGS_ONLINE;
kobject_uevent(&pcpu->dev.kobj, KOBJ_ONLINE);
} else if (!xen_pcpu_online(info->flags) &&
xen_pcpu_online(pcpu->flags)) {
pcpu->flags &= ~XEN_PCPU_FLAGS_ONLINE;
kobject_uevent(&pcpu->dev.kobj, KOBJ_OFFLINE);
}
}
static struct pcpu *get_pcpu(uint32_t cpu_id)
{
struct pcpu *pcpu;
list_for_each_entry(pcpu, &xen_pcpus, list) {
if (pcpu->cpu_id == cpu_id)
return pcpu;
}
return NULL;
}
static void pcpu_release(struct device *dev)
{
struct pcpu *pcpu = container_of(dev, struct pcpu, dev);
list_del(&pcpu->list);
kfree(pcpu);
}
static void unregister_and_remove_pcpu(struct pcpu *pcpu)
{
struct device *dev;
if (!pcpu)
return;
dev = &pcpu->dev;
if (dev->id)
device_remove_file(dev, &dev_attr_online);
device_unregister(dev);
}
static int register_pcpu(struct pcpu *pcpu)
{
struct device *dev;
int err = -EINVAL;
if (!pcpu)
return err;
dev = &pcpu->dev;
dev->bus = &xen_pcpu_subsys;
dev->id = pcpu->cpu_id;
dev->release = pcpu_release;
err = device_register(dev);
if (err) {
pcpu_release(dev);
return err;
}
if (dev->id) {
err = device_create_file(dev, &dev_attr_online);
if (err) {
device_unregister(dev);
return err;
}
}
return 0;
}
static struct pcpu *create_and_register_pcpu(struct xenpf_pcpuinfo *info)
{
struct pcpu *pcpu;
int err;
if (info->flags & XEN_PCPU_FLAGS_INVALID)
return ERR_PTR(-ENODEV);
pcpu = kzalloc(sizeof(struct pcpu), GFP_KERNEL);
if (!pcpu)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&pcpu->list);
pcpu->cpu_id = info->xen_cpuid;
pcpu->flags = info->flags;
list_add_tail(&pcpu->list, &xen_pcpus);
err = register_pcpu(pcpu);
if (err) {
pr_warning(XEN_PCPU "Failed to register pcpu%u\n",
info->xen_cpuid);
return ERR_PTR(-ENOENT);
}
return pcpu;
}
static int sync_pcpu(uint32_t cpu, uint32_t *max_cpu)
{
int ret;
struct pcpu *pcpu = NULL;
struct xenpf_pcpuinfo *info;
struct xen_platform_op op = {
.cmd = XENPF_get_cpuinfo,
.interface_version = XENPF_INTERFACE_VERSION,
.u.pcpu_info.xen_cpuid = cpu,
};
ret = HYPERVISOR_dom0_op(&op);
if (ret)
return ret;
info = &op.u.pcpu_info;
if (max_cpu)
*max_cpu = info->max_present;
pcpu = get_pcpu(cpu);
if (info->flags & XEN_PCPU_FLAGS_INVALID) {
unregister_and_remove_pcpu(pcpu);
return 0;
}
if (!pcpu) {
pcpu = create_and_register_pcpu(info);
if (IS_ERR_OR_NULL(pcpu))
return -ENODEV;
} else
pcpu_online_status(info, pcpu);
return 0;
}
static int xen_sync_pcpus(void)
{
uint32_t cpu = 0, max_cpu = 0;
int err = 0;
struct pcpu *pcpu, *tmp;
mutex_lock(&xen_pcpu_lock);
while (!err && (cpu <= max_cpu)) {
err = sync_pcpu(cpu, &max_cpu);
cpu++;
}
if (err)
list_for_each_entry_safe(pcpu, tmp, &xen_pcpus, list)
unregister_and_remove_pcpu(pcpu);
mutex_unlock(&xen_pcpu_lock);
return err;
}
static void xen_pcpu_work_fn(struct work_struct *work)
{
xen_sync_pcpus();
}
static irqreturn_t xen_pcpu_interrupt(int irq, void *dev_id)
{
schedule_work(&xen_pcpu_work);
return IRQ_HANDLED;
}
static int __init xen_pcpu_init(void)
{
int irq, ret;
if (!xen_initial_domain())
return -ENODEV;
irq = bind_virq_to_irqhandler(VIRQ_PCPU_STATE, 0,
xen_pcpu_interrupt, 0,
"xen-pcpu", NULL);
if (irq < 0) {
pr_warning(XEN_PCPU "Failed to bind pcpu virq\n");
return irq;
}
ret = subsys_system_register(&xen_pcpu_subsys, NULL);
if (ret) {
pr_warning(XEN_PCPU "Failed to register pcpu subsys\n");
goto err1;
}
ret = xen_sync_pcpus();
if (ret) {
pr_warning(XEN_PCPU "Failed to sync pcpu info\n");
goto err2;
}
return 0;
err2:
bus_unregister(&xen_pcpu_subsys);
err1:
unbind_from_irqhandler(irq, NULL);
return ret;
}
