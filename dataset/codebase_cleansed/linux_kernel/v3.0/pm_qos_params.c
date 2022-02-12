static inline int pm_qos_get_value(struct pm_qos_object *o)
{
if (plist_head_empty(&o->requests))
return o->default_value;
switch (o->type) {
case PM_QOS_MIN:
return plist_first(&o->requests)->prio;
case PM_QOS_MAX:
return plist_last(&o->requests)->prio;
default:
BUG();
}
}
static inline s32 pm_qos_read_value(struct pm_qos_object *o)
{
return o->target_value;
}
static inline void pm_qos_set_value(struct pm_qos_object *o, s32 value)
{
o->target_value = value;
}
static void update_target(struct pm_qos_object *o, struct plist_node *node,
int del, int value)
{
unsigned long flags;
int prev_value, curr_value;
spin_lock_irqsave(&pm_qos_lock, flags);
prev_value = pm_qos_get_value(o);
if (value != PM_QOS_DEFAULT_VALUE) {
plist_del(node, &o->requests);
plist_node_init(node, value);
plist_add(node, &o->requests);
} else if (del) {
plist_del(node, &o->requests);
} else {
plist_add(node, &o->requests);
}
curr_value = pm_qos_get_value(o);
pm_qos_set_value(o, curr_value);
spin_unlock_irqrestore(&pm_qos_lock, flags);
if (prev_value != curr_value)
blocking_notifier_call_chain(o->notifiers,
(unsigned long)curr_value,
NULL);
}
static int register_pm_qos_misc(struct pm_qos_object *qos)
{
qos->pm_qos_power_miscdev.minor = MISC_DYNAMIC_MINOR;
qos->pm_qos_power_miscdev.name = qos->name;
qos->pm_qos_power_miscdev.fops = &pm_qos_power_fops;
return misc_register(&qos->pm_qos_power_miscdev);
}
static int find_pm_qos_object_by_minor(int minor)
{
int pm_qos_class;
for (pm_qos_class = 0;
pm_qos_class < PM_QOS_NUM_CLASSES; pm_qos_class++) {
if (minor ==
pm_qos_array[pm_qos_class]->pm_qos_power_miscdev.minor)
return pm_qos_class;
}
return -1;
}
int pm_qos_request(int pm_qos_class)
{
return pm_qos_read_value(pm_qos_array[pm_qos_class]);
}
int pm_qos_request_active(struct pm_qos_request_list *req)
{
return req->pm_qos_class != 0;
}
void pm_qos_add_request(struct pm_qos_request_list *dep,
int pm_qos_class, s32 value)
{
struct pm_qos_object *o = pm_qos_array[pm_qos_class];
int new_value;
if (pm_qos_request_active(dep)) {
WARN(1, KERN_ERR "pm_qos_add_request() called for already added request\n");
return;
}
if (value == PM_QOS_DEFAULT_VALUE)
new_value = o->default_value;
else
new_value = value;
plist_node_init(&dep->list, new_value);
dep->pm_qos_class = pm_qos_class;
update_target(o, &dep->list, 0, PM_QOS_DEFAULT_VALUE);
}
void pm_qos_update_request(struct pm_qos_request_list *pm_qos_req,
s32 new_value)
{
s32 temp;
struct pm_qos_object *o;
if (!pm_qos_req)
return;
if (!pm_qos_request_active(pm_qos_req)) {
WARN(1, KERN_ERR "pm_qos_update_request() called for unknown object\n");
return;
}
o = pm_qos_array[pm_qos_req->pm_qos_class];
if (new_value == PM_QOS_DEFAULT_VALUE)
temp = o->default_value;
else
temp = new_value;
if (temp != pm_qos_req->list.prio)
update_target(o, &pm_qos_req->list, 0, temp);
}
void pm_qos_remove_request(struct pm_qos_request_list *pm_qos_req)
{
struct pm_qos_object *o;
if (pm_qos_req == NULL)
return;
if (!pm_qos_request_active(pm_qos_req)) {
WARN(1, KERN_ERR "pm_qos_remove_request() called for unknown object\n");
return;
}
o = pm_qos_array[pm_qos_req->pm_qos_class];
update_target(o, &pm_qos_req->list, 1, PM_QOS_DEFAULT_VALUE);
memset(pm_qos_req, 0, sizeof(*pm_qos_req));
}
int pm_qos_add_notifier(int pm_qos_class, struct notifier_block *notifier)
{
int retval;
retval = blocking_notifier_chain_register(
pm_qos_array[pm_qos_class]->notifiers, notifier);
return retval;
}
int pm_qos_remove_notifier(int pm_qos_class, struct notifier_block *notifier)
{
int retval;
retval = blocking_notifier_chain_unregister(
pm_qos_array[pm_qos_class]->notifiers, notifier);
return retval;
}
static int pm_qos_power_open(struct inode *inode, struct file *filp)
{
long pm_qos_class;
pm_qos_class = find_pm_qos_object_by_minor(iminor(inode));
if (pm_qos_class >= 0) {
struct pm_qos_request_list *req = kzalloc(sizeof(*req), GFP_KERNEL);
if (!req)
return -ENOMEM;
pm_qos_add_request(req, pm_qos_class, PM_QOS_DEFAULT_VALUE);
filp->private_data = req;
if (filp->private_data)
return 0;
}
return -EPERM;
}
static int pm_qos_power_release(struct inode *inode, struct file *filp)
{
struct pm_qos_request_list *req;
req = filp->private_data;
pm_qos_remove_request(req);
kfree(req);
return 0;
}
static ssize_t pm_qos_power_read(struct file *filp, char __user *buf,
size_t count, loff_t *f_pos)
{
s32 value;
unsigned long flags;
struct pm_qos_object *o;
struct pm_qos_request_list *pm_qos_req = filp->private_data;
if (!pm_qos_req)
return -EINVAL;
if (!pm_qos_request_active(pm_qos_req))
return -EINVAL;
o = pm_qos_array[pm_qos_req->pm_qos_class];
spin_lock_irqsave(&pm_qos_lock, flags);
value = pm_qos_get_value(o);
spin_unlock_irqrestore(&pm_qos_lock, flags);
return simple_read_from_buffer(buf, count, f_pos, &value, sizeof(s32));
}
static ssize_t pm_qos_power_write(struct file *filp, const char __user *buf,
size_t count, loff_t *f_pos)
{
s32 value;
struct pm_qos_request_list *pm_qos_req;
if (count == sizeof(s32)) {
if (copy_from_user(&value, buf, sizeof(s32)))
return -EFAULT;
} else if (count <= 11) {
char ascii_value[11];
unsigned long int ulval;
int ret;
if (copy_from_user(ascii_value, buf, count))
return -EFAULT;
if (count > 10) {
if (ascii_value[10] == '\n')
ascii_value[10] = '\0';
else
return -EINVAL;
} else {
ascii_value[count] = '\0';
}
ret = strict_strtoul(ascii_value, 16, &ulval);
if (ret) {
pr_debug("%s, 0x%lx, 0x%x\n", ascii_value, ulval, ret);
return -EINVAL;
}
value = (s32)lower_32_bits(ulval);
} else {
return -EINVAL;
}
pm_qos_req = filp->private_data;
pm_qos_update_request(pm_qos_req, value);
return count;
}
static int __init pm_qos_power_init(void)
{
int ret = 0;
ret = register_pm_qos_misc(&cpu_dma_pm_qos);
if (ret < 0) {
printk(KERN_ERR "pm_qos_param: cpu_dma_latency setup failed\n");
return ret;
}
ret = register_pm_qos_misc(&network_lat_pm_qos);
if (ret < 0) {
printk(KERN_ERR "pm_qos_param: network_latency setup failed\n");
return ret;
}
ret = register_pm_qos_misc(&network_throughput_pm_qos);
if (ret < 0)
printk(KERN_ERR
"pm_qos_param: network_throughput setup failed\n");
return ret;
}
