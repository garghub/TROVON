static void appldata_timer_function(unsigned long data)
{
if (atomic_dec_and_test(&appldata_expire_count)) {
atomic_set(&appldata_expire_count, num_online_cpus());
queue_work(appldata_wq, (struct work_struct *) data);
}
}
static void appldata_work_fn(struct work_struct *work)
{
struct list_head *lh;
struct appldata_ops *ops;
get_online_cpus();
mutex_lock(&appldata_ops_mutex);
list_for_each(lh, &appldata_ops_list) {
ops = list_entry(lh, struct appldata_ops, list);
if (ops->active == 1) {
ops->callback(ops->data);
}
}
mutex_unlock(&appldata_ops_mutex);
put_online_cpus();
}
int appldata_diag(char record_nr, u16 function, unsigned long buffer,
u16 length, char *mod_lvl)
{
struct appldata_product_id id = {
.prod_nr = {0xD3, 0xC9, 0xD5, 0xE4,
0xE7, 0xD2, 0xD9},
.prod_fn = 0xD5D3,
.version_nr = 0xF2F6,
.release_nr = 0xF0F1,
};
id.record_nr = record_nr;
id.mod_lvl = (mod_lvl[0]) << 8 | mod_lvl[1];
return appldata_asm(&id, function, (void *) buffer, length);
}
static void __appldata_mod_vtimer_wrap(void *p) {
struct {
struct vtimer_list *timer;
u64 expires;
} *args = p;
mod_virt_timer_periodic(args->timer, args->expires);
}
static void
__appldata_vtimer_setup(int cmd)
{
u64 per_cpu_interval;
int i;
switch (cmd) {
case APPLDATA_ADD_TIMER:
if (appldata_timer_active)
break;
per_cpu_interval = (u64) (appldata_interval*1000 /
num_online_cpus()) * TOD_MICRO;
for_each_online_cpu(i) {
per_cpu(appldata_timer, i).expires = per_cpu_interval;
smp_call_function_single(i, add_virt_timer_periodic,
&per_cpu(appldata_timer, i),
1);
}
appldata_timer_active = 1;
break;
case APPLDATA_DEL_TIMER:
for_each_online_cpu(i)
del_virt_timer(&per_cpu(appldata_timer, i));
if (!appldata_timer_active)
break;
appldata_timer_active = 0;
atomic_set(&appldata_expire_count, num_online_cpus());
break;
case APPLDATA_MOD_TIMER:
per_cpu_interval = (u64) (appldata_interval*1000 /
num_online_cpus()) * TOD_MICRO;
if (!appldata_timer_active)
break;
for_each_online_cpu(i) {
struct {
struct vtimer_list *timer;
u64 expires;
} args;
args.timer = &per_cpu(appldata_timer, i);
args.expires = per_cpu_interval;
smp_call_function_single(i, __appldata_mod_vtimer_wrap,
&args, 1);
}
}
}
static int
appldata_timer_handler(ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int len;
char buf[2];
if (!*lenp || *ppos) {
*lenp = 0;
return 0;
}
if (!write) {
len = sprintf(buf, appldata_timer_active ? "1\n" : "0\n");
if (len > *lenp)
len = *lenp;
if (copy_to_user(buffer, buf, len))
return -EFAULT;
goto out;
}
len = *lenp;
if (copy_from_user(buf, buffer, len > sizeof(buf) ? sizeof(buf) : len))
return -EFAULT;
get_online_cpus();
spin_lock(&appldata_timer_lock);
if (buf[0] == '1')
__appldata_vtimer_setup(APPLDATA_ADD_TIMER);
else if (buf[0] == '0')
__appldata_vtimer_setup(APPLDATA_DEL_TIMER);
spin_unlock(&appldata_timer_lock);
put_online_cpus();
out:
*lenp = len;
*ppos += len;
return 0;
}
static int
appldata_interval_handler(ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int len, interval;
char buf[16];
if (!*lenp || *ppos) {
*lenp = 0;
return 0;
}
if (!write) {
len = sprintf(buf, "%i\n", appldata_interval);
if (len > *lenp)
len = *lenp;
if (copy_to_user(buffer, buf, len))
return -EFAULT;
goto out;
}
len = *lenp;
if (copy_from_user(buf, buffer, len > sizeof(buf) ? sizeof(buf) : len)) {
return -EFAULT;
}
interval = 0;
sscanf(buf, "%i", &interval);
if (interval <= 0)
return -EINVAL;
get_online_cpus();
spin_lock(&appldata_timer_lock);
appldata_interval = interval;
__appldata_vtimer_setup(APPLDATA_MOD_TIMER);
spin_unlock(&appldata_timer_lock);
put_online_cpus();
out:
*lenp = len;
*ppos += len;
return 0;
}
static int
appldata_generic_handler(ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct appldata_ops *ops = NULL, *tmp_ops;
int rc, len, found;
char buf[2];
struct list_head *lh;
found = 0;
mutex_lock(&appldata_ops_mutex);
list_for_each(lh, &appldata_ops_list) {
tmp_ops = list_entry(lh, struct appldata_ops, list);
if (&tmp_ops->ctl_table[2] == ctl) {
found = 1;
}
}
if (!found) {
mutex_unlock(&appldata_ops_mutex);
return -ENODEV;
}
ops = ctl->data;
if (!try_module_get(ops->owner)) {
mutex_unlock(&appldata_ops_mutex);
return -ENODEV;
}
mutex_unlock(&appldata_ops_mutex);
if (!*lenp || *ppos) {
*lenp = 0;
module_put(ops->owner);
return 0;
}
if (!write) {
len = sprintf(buf, ops->active ? "1\n" : "0\n");
if (len > *lenp)
len = *lenp;
if (copy_to_user(buffer, buf, len)) {
module_put(ops->owner);
return -EFAULT;
}
goto out;
}
len = *lenp;
if (copy_from_user(buf, buffer,
len > sizeof(buf) ? sizeof(buf) : len)) {
module_put(ops->owner);
return -EFAULT;
}
mutex_lock(&appldata_ops_mutex);
if ((buf[0] == '1') && (ops->active == 0)) {
if (!try_module_get(ops->owner)) {
mutex_unlock(&appldata_ops_mutex);
module_put(ops->owner);
return -ENODEV;
}
ops->callback(ops->data);
rc = appldata_diag(ops->record_nr,
APPLDATA_START_INTERVAL_REC,
(unsigned long) ops->data, ops->size,
ops->mod_lvl);
if (rc != 0) {
pr_err("Starting the data collection for %s "
"failed with rc=%d\n", ops->name, rc);
module_put(ops->owner);
} else
ops->active = 1;
} else if ((buf[0] == '0') && (ops->active == 1)) {
ops->active = 0;
rc = appldata_diag(ops->record_nr, APPLDATA_STOP_REC,
(unsigned long) ops->data, ops->size,
ops->mod_lvl);
if (rc != 0)
pr_err("Stopping the data collection for %s "
"failed with rc=%d\n", ops->name, rc);
module_put(ops->owner);
}
mutex_unlock(&appldata_ops_mutex);
out:
*lenp = len;
*ppos += len;
module_put(ops->owner);
return 0;
}
int appldata_register_ops(struct appldata_ops *ops)
{
if (ops->size > APPLDATA_MAX_REC_SIZE)
return -EINVAL;
ops->ctl_table = kzalloc(4 * sizeof(struct ctl_table), GFP_KERNEL);
if (!ops->ctl_table)
return -ENOMEM;
mutex_lock(&appldata_ops_mutex);
list_add(&ops->list, &appldata_ops_list);
mutex_unlock(&appldata_ops_mutex);
ops->ctl_table[0].procname = appldata_proc_name;
ops->ctl_table[0].maxlen = 0;
ops->ctl_table[0].mode = S_IRUGO | S_IXUGO;
ops->ctl_table[0].child = &ops->ctl_table[2];
ops->ctl_table[2].procname = ops->name;
ops->ctl_table[2].mode = S_IRUGO | S_IWUSR;
ops->ctl_table[2].proc_handler = appldata_generic_handler;
ops->ctl_table[2].data = ops;
ops->sysctl_header = register_sysctl_table(ops->ctl_table);
if (!ops->sysctl_header)
goto out;
return 0;
out:
mutex_lock(&appldata_ops_mutex);
list_del(&ops->list);
mutex_unlock(&appldata_ops_mutex);
kfree(ops->ctl_table);
return -ENOMEM;
}
void appldata_unregister_ops(struct appldata_ops *ops)
{
mutex_lock(&appldata_ops_mutex);
list_del(&ops->list);
mutex_unlock(&appldata_ops_mutex);
unregister_sysctl_table(ops->sysctl_header);
kfree(ops->ctl_table);
}
static int appldata_freeze(struct device *dev)
{
struct appldata_ops *ops;
int rc;
struct list_head *lh;
get_online_cpus();
spin_lock(&appldata_timer_lock);
if (appldata_timer_active) {
__appldata_vtimer_setup(APPLDATA_DEL_TIMER);
appldata_timer_suspended = 1;
}
spin_unlock(&appldata_timer_lock);
put_online_cpus();
mutex_lock(&appldata_ops_mutex);
list_for_each(lh, &appldata_ops_list) {
ops = list_entry(lh, struct appldata_ops, list);
if (ops->active == 1) {
rc = appldata_diag(ops->record_nr, APPLDATA_STOP_REC,
(unsigned long) ops->data, ops->size,
ops->mod_lvl);
if (rc != 0)
pr_err("Stopping the data collection for %s "
"failed with rc=%d\n", ops->name, rc);
}
}
mutex_unlock(&appldata_ops_mutex);
return 0;
}
static int appldata_restore(struct device *dev)
{
struct appldata_ops *ops;
int rc;
struct list_head *lh;
get_online_cpus();
spin_lock(&appldata_timer_lock);
if (appldata_timer_suspended) {
__appldata_vtimer_setup(APPLDATA_ADD_TIMER);
appldata_timer_suspended = 0;
}
spin_unlock(&appldata_timer_lock);
put_online_cpus();
mutex_lock(&appldata_ops_mutex);
list_for_each(lh, &appldata_ops_list) {
ops = list_entry(lh, struct appldata_ops, list);
if (ops->active == 1) {
ops->callback(ops->data);
rc = appldata_diag(ops->record_nr,
APPLDATA_START_INTERVAL_REC,
(unsigned long) ops->data, ops->size,
ops->mod_lvl);
if (rc != 0) {
pr_err("Starting the data collection for %s "
"failed with rc=%d\n", ops->name, rc);
}
}
}
mutex_unlock(&appldata_ops_mutex);
return 0;
}
static int appldata_thaw(struct device *dev)
{
return appldata_restore(dev);
}
static void __cpuinit appldata_online_cpu(int cpu)
{
init_virt_timer(&per_cpu(appldata_timer, cpu));
per_cpu(appldata_timer, cpu).function = appldata_timer_function;
per_cpu(appldata_timer, cpu).data = (unsigned long)
&appldata_work;
atomic_inc(&appldata_expire_count);
spin_lock(&appldata_timer_lock);
__appldata_vtimer_setup(APPLDATA_MOD_TIMER);
spin_unlock(&appldata_timer_lock);
}
static void __cpuinit appldata_offline_cpu(int cpu)
{
del_virt_timer(&per_cpu(appldata_timer, cpu));
if (atomic_dec_and_test(&appldata_expire_count)) {
atomic_set(&appldata_expire_count, num_online_cpus());
queue_work(appldata_wq, &appldata_work);
}
spin_lock(&appldata_timer_lock);
__appldata_vtimer_setup(APPLDATA_MOD_TIMER);
spin_unlock(&appldata_timer_lock);
}
static int __cpuinit appldata_cpu_notify(struct notifier_block *self,
unsigned long action,
void *hcpu)
{
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
appldata_online_cpu((long) hcpu);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
appldata_offline_cpu((long) hcpu);
break;
default:
break;
}
return NOTIFY_OK;
}
static int __init appldata_init(void)
{
int i, rc;
rc = platform_driver_register(&appldata_pdrv);
if (rc)
return rc;
appldata_pdev = platform_device_register_simple("appldata", -1, NULL,
0);
if (IS_ERR(appldata_pdev)) {
rc = PTR_ERR(appldata_pdev);
goto out_driver;
}
appldata_wq = create_singlethread_workqueue("appldata");
if (!appldata_wq) {
rc = -ENOMEM;
goto out_device;
}
get_online_cpus();
for_each_online_cpu(i)
appldata_online_cpu(i);
put_online_cpus();
register_hotcpu_notifier(&appldata_nb);
appldata_sysctl_header = register_sysctl_table(appldata_dir_table);
return 0;
out_device:
platform_device_unregister(appldata_pdev);
out_driver:
platform_driver_unregister(&appldata_pdrv);
return rc;
}
