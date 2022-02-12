void cleanup_tc(struct tc *tc)
{
}
static ssize_t store_kill(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
struct vpe *vpe = get_vpe(aprp_cpu_index());
struct vpe_notifications *notifier;
list_for_each_entry(notifier, &vpe->notify, list)
notifier->stop(aprp_cpu_index());
release_progmem(vpe->load_addr);
vpe->state = VPE_STATE_UNUSED;
return len;
}
static ssize_t ntcs_show(struct device *cd, struct device_attribute *attr,
char *buf)
{
struct vpe *vpe = get_vpe(aprp_cpu_index());
return sprintf(buf, "%d\n", vpe->ntcs);
}
static ssize_t ntcs_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
struct vpe *vpe = get_vpe(aprp_cpu_index());
unsigned long new;
int ret;
ret = kstrtoul(buf, 0, &new);
if (ret < 0)
return ret;
if (new != 1)
return -EINVAL;
vpe->ntcs = new;
return len;
}
static void vpe_device_release(struct device *cd)
{
kfree(cd);
}
int __init vpe_module_init(void)
{
struct vpe *v = NULL;
struct tc *t;
int err;
if (!cpu_has_mipsmt) {
pr_warn("VPE loader: not a MIPS MT capable processor\n");
return -ENODEV;
}
if (num_possible_cpus() - aprp_cpu_index() < 1) {
pr_warn("No VPEs reserved for AP/SP, not initialize VPE loader\n"
"Pass maxcpus=<n> argument as kernel argument\n");
return -ENODEV;
}
major = register_chrdev(0, VPE_MODULE_NAME, &vpe_fops);
if (major < 0) {
pr_warn("VPE loader: unable to register character device\n");
return major;
}
err = class_register(&vpe_class);
if (err) {
pr_err("vpe_class registration failed\n");
goto out_chrdev;
}
device_initialize(&vpe_device);
vpe_device.class = &vpe_class,
vpe_device.parent = NULL,
dev_set_name(&vpe_device, "vpe_sp");
vpe_device.devt = MKDEV(major, VPE_MODULE_MINOR);
err = device_add(&vpe_device);
if (err) {
pr_err("Adding vpe_device failed\n");
goto out_class;
}
t = alloc_tc(aprp_cpu_index());
if (!t) {
pr_warn("VPE: unable to allocate TC\n");
err = -ENOMEM;
goto out_dev;
}
v = alloc_vpe(aprp_cpu_index());
if (v == NULL) {
pr_warn("VPE: unable to allocate VPE\n");
kfree(t);
err = -ENOMEM;
goto out_dev;
}
v->ntcs = 1;
list_add(&t->tc, &v->tc);
t->pvpe = v;
return 0;
out_dev:
device_del(&vpe_device);
out_class:
class_unregister(&vpe_class);
out_chrdev:
unregister_chrdev(major, VPE_MODULE_NAME);
return err;
}
void __exit vpe_module_exit(void)
{
struct vpe *v, *n;
device_del(&vpe_device);
class_unregister(&vpe_class);
unregister_chrdev(major, VPE_MODULE_NAME);
list_for_each_entry_safe(v, n, &vpecontrol.vpe_list, list)
if (v->state != VPE_STATE_UNUSED)
release_vpe(v);
}
