int vpe_run(struct vpe *v)
{
unsigned long flags, val, dmt_flag;
struct vpe_notifications *notifier;
unsigned int vpeflags;
struct tc *t;
local_irq_save(flags);
val = read_c0_vpeconf0();
if (!(val & VPECONF0_MVP)) {
pr_warn("VPE loader: only Master VPE's are able to config MT\n");
local_irq_restore(flags);
return -1;
}
dmt_flag = dmt();
vpeflags = dvpe();
if (list_empty(&v->tc)) {
evpe(vpeflags);
emt(dmt_flag);
local_irq_restore(flags);
pr_warn("VPE loader: No TC's associated with VPE %d\n",
v->minor);
return -ENOEXEC;
}
t = list_first_entry(&v->tc, struct tc, tc);
set_c0_mvpcontrol(MVPCONTROL_VPC);
settc(t->index);
if ((read_tc_c0_tcstatus() & TCSTATUS_A) ||
!(read_tc_c0_tchalt() & TCHALT_H)) {
evpe(vpeflags);
emt(dmt_flag);
local_irq_restore(flags);
pr_warn("VPE loader: TC %d is already active!\n",
t->index);
return -ENOEXEC;
}
write_tc_c0_tcrestart((unsigned long)v->__start);
write_tc_c0_tccontext((unsigned long)0);
val = read_tc_c0_tcstatus();
val = (val & ~(TCSTATUS_DA | TCSTATUS_IXMT)) | TCSTATUS_A;
write_tc_c0_tcstatus(val);
write_tc_c0_tchalt(read_tc_c0_tchalt() & ~TCHALT_H);
mttgpr(6, v->ntcs);
mttgpr(7, physical_memsize);
write_tc_c0_tcbind((read_tc_c0_tcbind() & ~TCBIND_CURVPE) | 1);
write_vpe_c0_vpeconf0(read_vpe_c0_vpeconf0() & ~(VPECONF0_VPA));
back_to_back_c0_hazard();
write_vpe_c0_vpeconf0((read_vpe_c0_vpeconf0() & ~(VPECONF0_XTC))
| (t->index << VPECONF0_XTC_SHIFT));
back_to_back_c0_hazard();
write_vpe_c0_vpeconf0(read_vpe_c0_vpeconf0() | VPECONF0_VPA);
write_vpe_c0_status(0);
write_vpe_c0_cause(0);
clear_c0_mvpcontrol(MVPCONTROL_VPC);
#ifdef CONFIG_SMP
evpe(vpeflags);
#else
evpe(EVPE_ENABLE);
#endif
emt(dmt_flag);
local_irq_restore(flags);
list_for_each_entry(notifier, &v->notify, list)
notifier->start(VPE_MODULE_MINOR);
return 0;
}
void cleanup_tc(struct tc *tc)
{
unsigned long flags;
unsigned int mtflags, vpflags;
int tmp;
local_irq_save(flags);
mtflags = dmt();
vpflags = dvpe();
set_c0_mvpcontrol(MVPCONTROL_VPC);
settc(tc->index);
tmp = read_tc_c0_tcstatus();
tmp &= ~(TCSTATUS_A | TCSTATUS_DA);
tmp |= TCSTATUS_IXMT;
write_tc_c0_tcstatus(tmp);
write_tc_c0_tchalt(TCHALT_H);
mips_ihb();
clear_c0_mvpcontrol(MVPCONTROL_VPC);
evpe(vpflags);
emt(mtflags);
local_irq_restore(flags);
}
void *vpe_alloc(void)
{
int i;
struct vpe *v;
for (i = 1; i < MAX_VPES; i++) {
v = get_vpe(i);
if (v != NULL) {
v->state = VPE_STATE_INUSE;
return v;
}
}
return NULL;
}
int vpe_start(void *vpe, unsigned long start)
{
struct vpe *v = vpe;
v->__start = start;
return vpe_run(v);
}
int vpe_stop(void *vpe)
{
struct vpe *v = vpe;
struct tc *t;
unsigned int evpe_flags;
evpe_flags = dvpe();
t = list_entry(v->tc.next, struct tc, tc);
if (t != NULL) {
settc(t->index);
write_vpe_c0_vpeconf0(read_vpe_c0_vpeconf0() & ~VPECONF0_VPA);
}
evpe(evpe_flags);
return 0;
}
int vpe_free(void *vpe)
{
struct vpe *v = vpe;
struct tc *t;
unsigned int evpe_flags;
t = list_entry(v->tc.next, struct tc, tc);
if (t == NULL)
return -ENOEXEC;
evpe_flags = dvpe();
set_c0_mvpcontrol(MVPCONTROL_VPC);
settc(t->index);
write_vpe_c0_vpeconf0(read_vpe_c0_vpeconf0() & ~VPECONF0_VPA);
write_tc_c0_tchalt(TCHALT_H);
mips_ihb();
write_tc_c0_tcstatus(read_tc_c0_tcstatus() & ~TCSTATUS_A);
v->state = VPE_STATE_UNUSED;
clear_c0_mvpcontrol(MVPCONTROL_VPC);
evpe(evpe_flags);
return 0;
}
static ssize_t store_kill(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
struct vpe *vpe = get_vpe(aprp_cpu_index());
struct vpe_notifications *notifier;
list_for_each_entry(notifier, &vpe->notify, list)
notifier->stop(aprp_cpu_index());
release_progmem(vpe->load_addr);
cleanup_tc(get_tc(aprp_cpu_index()));
vpe_stop(vpe);
vpe_free(vpe);
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
if (new == 0 || new > (hw_tcs - aprp_cpu_index()))
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
unsigned int mtflags, vpflags;
unsigned long flags, val;
struct vpe *v = NULL;
struct tc *t;
int tc, err;
if (!cpu_has_mipsmt) {
pr_warn("VPE loader: not a MIPS MT capable processor\n");
return -ENODEV;
}
if (vpelimit == 0) {
pr_warn("No VPEs reserved for AP/SP, not initialize VPE loader\n"
"Pass maxvpes=<n> argument as kernel argument\n");
return -ENODEV;
}
if (aprp_cpu_index() == 0) {
pr_warn("No TCs reserved for AP/SP, not initialize VPE loader\n"
"Pass maxtcs=<n> argument as kernel argument\n");
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
dev_set_name(&vpe_device, "vpe1");
vpe_device.devt = MKDEV(major, VPE_MODULE_MINOR);
err = device_add(&vpe_device);
if (err) {
pr_err("Adding vpe_device failed\n");
goto out_class;
}
local_irq_save(flags);
mtflags = dmt();
vpflags = dvpe();
set_c0_mvpcontrol(MVPCONTROL_VPC);
val = read_c0_mvpconf0();
hw_tcs = (val & MVPCONF0_PTC) + 1;
hw_vpes = ((val & MVPCONF0_PVPE) >> MVPCONF0_PVPE_SHIFT) + 1;
for (tc = aprp_cpu_index(); tc < hw_tcs; tc++) {
clear_c0_mvpcontrol(MVPCONTROL_VPC);
evpe(vpflags);
emt(mtflags);
local_irq_restore(flags);
t = alloc_tc(tc);
if (!t) {
err = -ENOMEM;
goto out_dev;
}
local_irq_save(flags);
mtflags = dmt();
vpflags = dvpe();
set_c0_mvpcontrol(MVPCONTROL_VPC);
if (tc < hw_tcs) {
settc(tc);
v = alloc_vpe(tc);
if (v == NULL) {
pr_warn("VPE: unable to allocate VPE\n");
goto out_reenable;
}
v->ntcs = hw_tcs - aprp_cpu_index();
list_add(&t->tc, &v->tc);
if (tc >= aprp_cpu_index()) {
unsigned long tmp = read_vpe_c0_vpeconf0();
tmp &= ~VPECONF0_VPA;
tmp |= VPECONF0_MVP;
write_vpe_c0_vpeconf0(tmp);
}
write_vpe_c0_vpecontrol(read_vpe_c0_vpecontrol() &
~VPECONTROL_TE);
if (tc >= vpelimit) {
write_vpe_c0_config(read_c0_config());
}
}
t->pvpe = v;
if (tc >= aprp_cpu_index()) {
unsigned long tmp;
settc(tc);
tmp = read_tc_c0_tcbind();
if (tmp & TCBIND_CURVPE) {
write_tc_c0_tcbind(tmp & ~TCBIND_CURVPE);
t->pvpe = get_vpe(0);
}
write_tc_c0_tchalt(TCHALT_H);
mips_ihb();
tmp = read_tc_c0_tcstatus();
tmp &= ~(TCSTATUS_A | TCSTATUS_DA);
tmp |= TCSTATUS_IXMT;
write_tc_c0_tcstatus(tmp);
}
}
out_reenable:
clear_c0_mvpcontrol(MVPCONTROL_VPC);
evpe(vpflags);
emt(mtflags);
local_irq_restore(flags);
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
list_for_each_entry_safe(v, n, &vpecontrol.vpe_list, list) {
if (v->state != VPE_STATE_UNUSED)
release_vpe(v);
}
}
