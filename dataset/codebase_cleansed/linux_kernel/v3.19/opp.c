static struct device_opp *find_device_opp(struct device *dev)
{
struct device_opp *tmp_dev_opp, *dev_opp = ERR_PTR(-ENODEV);
if (unlikely(IS_ERR_OR_NULL(dev))) {
pr_err("%s: Invalid parameters\n", __func__);
return ERR_PTR(-EINVAL);
}
list_for_each_entry_rcu(tmp_dev_opp, &dev_opp_list, node) {
if (tmp_dev_opp->dev == dev) {
dev_opp = tmp_dev_opp;
break;
}
}
return dev_opp;
}
unsigned long dev_pm_opp_get_voltage(struct dev_pm_opp *opp)
{
struct dev_pm_opp *tmp_opp;
unsigned long v = 0;
tmp_opp = rcu_dereference(opp);
if (unlikely(IS_ERR_OR_NULL(tmp_opp)) || !tmp_opp->available)
pr_err("%s: Invalid parameters\n", __func__);
else
v = tmp_opp->u_volt;
return v;
}
unsigned long dev_pm_opp_get_freq(struct dev_pm_opp *opp)
{
struct dev_pm_opp *tmp_opp;
unsigned long f = 0;
tmp_opp = rcu_dereference(opp);
if (unlikely(IS_ERR_OR_NULL(tmp_opp)) || !tmp_opp->available)
pr_err("%s: Invalid parameters\n", __func__);
else
f = tmp_opp->rate;
return f;
}
int dev_pm_opp_get_opp_count(struct device *dev)
{
struct device_opp *dev_opp;
struct dev_pm_opp *temp_opp;
int count = 0;
rcu_read_lock();
dev_opp = find_device_opp(dev);
if (IS_ERR(dev_opp)) {
count = PTR_ERR(dev_opp);
dev_err(dev, "%s: device OPP not found (%d)\n",
__func__, count);
goto out_unlock;
}
list_for_each_entry_rcu(temp_opp, &dev_opp->opp_list, node) {
if (temp_opp->available)
count++;
}
out_unlock:
rcu_read_unlock();
return count;
}
struct dev_pm_opp *dev_pm_opp_find_freq_exact(struct device *dev,
unsigned long freq,
bool available)
{
struct device_opp *dev_opp;
struct dev_pm_opp *temp_opp, *opp = ERR_PTR(-ERANGE);
opp_rcu_lockdep_assert();
dev_opp = find_device_opp(dev);
if (IS_ERR(dev_opp)) {
int r = PTR_ERR(dev_opp);
dev_err(dev, "%s: device OPP not found (%d)\n", __func__, r);
return ERR_PTR(r);
}
list_for_each_entry_rcu(temp_opp, &dev_opp->opp_list, node) {
if (temp_opp->available == available &&
temp_opp->rate == freq) {
opp = temp_opp;
break;
}
}
return opp;
}
struct dev_pm_opp *dev_pm_opp_find_freq_ceil(struct device *dev,
unsigned long *freq)
{
struct device_opp *dev_opp;
struct dev_pm_opp *temp_opp, *opp = ERR_PTR(-ERANGE);
opp_rcu_lockdep_assert();
if (!dev || !freq) {
dev_err(dev, "%s: Invalid argument freq=%p\n", __func__, freq);
return ERR_PTR(-EINVAL);
}
dev_opp = find_device_opp(dev);
if (IS_ERR(dev_opp))
return ERR_CAST(dev_opp);
list_for_each_entry_rcu(temp_opp, &dev_opp->opp_list, node) {
if (temp_opp->available && temp_opp->rate >= *freq) {
opp = temp_opp;
*freq = opp->rate;
break;
}
}
return opp;
}
struct dev_pm_opp *dev_pm_opp_find_freq_floor(struct device *dev,
unsigned long *freq)
{
struct device_opp *dev_opp;
struct dev_pm_opp *temp_opp, *opp = ERR_PTR(-ERANGE);
opp_rcu_lockdep_assert();
if (!dev || !freq) {
dev_err(dev, "%s: Invalid argument freq=%p\n", __func__, freq);
return ERR_PTR(-EINVAL);
}
dev_opp = find_device_opp(dev);
if (IS_ERR(dev_opp))
return ERR_CAST(dev_opp);
list_for_each_entry_rcu(temp_opp, &dev_opp->opp_list, node) {
if (temp_opp->available) {
if (temp_opp->rate > *freq)
break;
else
opp = temp_opp;
}
}
if (!IS_ERR(opp))
*freq = opp->rate;
return opp;
}
static struct device_opp *add_device_opp(struct device *dev)
{
struct device_opp *dev_opp;
dev_opp = kzalloc(sizeof(*dev_opp), GFP_KERNEL);
if (!dev_opp)
return NULL;
dev_opp->dev = dev;
srcu_init_notifier_head(&dev_opp->srcu_head);
INIT_LIST_HEAD(&dev_opp->opp_list);
list_add_rcu(&dev_opp->node, &dev_opp_list);
return dev_opp;
}
static int dev_pm_opp_add_dynamic(struct device *dev, unsigned long freq,
unsigned long u_volt, bool dynamic)
{
struct device_opp *dev_opp = NULL;
struct dev_pm_opp *opp, *new_opp;
struct list_head *head;
int ret;
new_opp = kzalloc(sizeof(*new_opp), GFP_KERNEL);
if (!new_opp) {
dev_warn(dev, "%s: Unable to create new OPP node\n", __func__);
return -ENOMEM;
}
mutex_lock(&dev_opp_list_lock);
new_opp->rate = freq;
new_opp->u_volt = u_volt;
new_opp->available = true;
new_opp->dynamic = dynamic;
dev_opp = find_device_opp(dev);
if (IS_ERR(dev_opp)) {
dev_opp = add_device_opp(dev);
if (!dev_opp) {
ret = -ENOMEM;
goto free_opp;
}
head = &dev_opp->opp_list;
goto list_add;
}
head = &dev_opp->opp_list;
list_for_each_entry_rcu(opp, &dev_opp->opp_list, node) {
if (new_opp->rate <= opp->rate)
break;
else
head = &opp->node;
}
if (new_opp->rate == opp->rate) {
ret = opp->available && new_opp->u_volt == opp->u_volt ?
0 : -EEXIST;
dev_warn(dev, "%s: duplicate OPPs detected. Existing: freq: %lu, volt: %lu, enabled: %d. New: freq: %lu, volt: %lu, enabled: %d\n",
__func__, opp->rate, opp->u_volt, opp->available,
new_opp->rate, new_opp->u_volt, new_opp->available);
goto free_opp;
}
list_add:
new_opp->dev_opp = dev_opp;
list_add_rcu(&new_opp->node, head);
mutex_unlock(&dev_opp_list_lock);
srcu_notifier_call_chain(&dev_opp->srcu_head, OPP_EVENT_ADD, new_opp);
return 0;
free_opp:
mutex_unlock(&dev_opp_list_lock);
kfree(new_opp);
return ret;
}
int dev_pm_opp_add(struct device *dev, unsigned long freq, unsigned long u_volt)
{
return dev_pm_opp_add_dynamic(dev, freq, u_volt, true);
}
static void kfree_opp_rcu(struct rcu_head *head)
{
struct dev_pm_opp *opp = container_of(head, struct dev_pm_opp, rcu_head);
kfree_rcu(opp, rcu_head);
}
static void kfree_device_rcu(struct rcu_head *head)
{
struct device_opp *device_opp = container_of(head, struct device_opp, rcu_head);
kfree_rcu(device_opp, rcu_head);
}
static void __dev_pm_opp_remove(struct device_opp *dev_opp,
struct dev_pm_opp *opp)
{
srcu_notifier_call_chain(&dev_opp->srcu_head, OPP_EVENT_REMOVE, opp);
list_del_rcu(&opp->node);
call_srcu(&dev_opp->srcu_head.srcu, &opp->rcu_head, kfree_opp_rcu);
if (list_empty(&dev_opp->opp_list)) {
list_del_rcu(&dev_opp->node);
call_srcu(&dev_opp->srcu_head.srcu, &dev_opp->rcu_head,
kfree_device_rcu);
}
}
void dev_pm_opp_remove(struct device *dev, unsigned long freq)
{
struct dev_pm_opp *opp;
struct device_opp *dev_opp;
bool found = false;
mutex_lock(&dev_opp_list_lock);
dev_opp = find_device_opp(dev);
if (IS_ERR(dev_opp))
goto unlock;
list_for_each_entry(opp, &dev_opp->opp_list, node) {
if (opp->rate == freq) {
found = true;
break;
}
}
if (!found) {
dev_warn(dev, "%s: Couldn't find OPP with freq: %lu\n",
__func__, freq);
goto unlock;
}
__dev_pm_opp_remove(dev_opp, opp);
unlock:
mutex_unlock(&dev_opp_list_lock);
}
static int opp_set_availability(struct device *dev, unsigned long freq,
bool availability_req)
{
struct device_opp *dev_opp;
struct dev_pm_opp *new_opp, *tmp_opp, *opp = ERR_PTR(-ENODEV);
int r = 0;
new_opp = kmalloc(sizeof(*new_opp), GFP_KERNEL);
if (!new_opp) {
dev_warn(dev, "%s: Unable to create OPP\n", __func__);
return -ENOMEM;
}
mutex_lock(&dev_opp_list_lock);
dev_opp = find_device_opp(dev);
if (IS_ERR(dev_opp)) {
r = PTR_ERR(dev_opp);
dev_warn(dev, "%s: Device OPP not found (%d)\n", __func__, r);
goto unlock;
}
list_for_each_entry(tmp_opp, &dev_opp->opp_list, node) {
if (tmp_opp->rate == freq) {
opp = tmp_opp;
break;
}
}
if (IS_ERR(opp)) {
r = PTR_ERR(opp);
goto unlock;
}
if (opp->available == availability_req)
goto unlock;
*new_opp = *opp;
new_opp->available = availability_req;
list_replace_rcu(&opp->node, &new_opp->node);
mutex_unlock(&dev_opp_list_lock);
call_srcu(&dev_opp->srcu_head.srcu, &opp->rcu_head, kfree_opp_rcu);
if (availability_req)
srcu_notifier_call_chain(&dev_opp->srcu_head, OPP_EVENT_ENABLE,
new_opp);
else
srcu_notifier_call_chain(&dev_opp->srcu_head, OPP_EVENT_DISABLE,
new_opp);
return 0;
unlock:
mutex_unlock(&dev_opp_list_lock);
kfree(new_opp);
return r;
}
int dev_pm_opp_enable(struct device *dev, unsigned long freq)
{
return opp_set_availability(dev, freq, true);
}
int dev_pm_opp_disable(struct device *dev, unsigned long freq)
{
return opp_set_availability(dev, freq, false);
}
struct srcu_notifier_head *dev_pm_opp_get_notifier(struct device *dev)
{
struct device_opp *dev_opp = find_device_opp(dev);
if (IS_ERR(dev_opp))
return ERR_CAST(dev_opp);
return &dev_opp->srcu_head;
}
int of_init_opp_table(struct device *dev)
{
const struct property *prop;
const __be32 *val;
int nr;
prop = of_find_property(dev->of_node, "operating-points", NULL);
if (!prop)
return -ENODEV;
if (!prop->value)
return -ENODATA;
nr = prop->length / sizeof(u32);
if (nr % 2) {
dev_err(dev, "%s: Invalid OPP list\n", __func__);
return -EINVAL;
}
val = prop->value;
while (nr) {
unsigned long freq = be32_to_cpup(val++) * 1000;
unsigned long volt = be32_to_cpup(val++);
if (dev_pm_opp_add_dynamic(dev, freq, volt, false))
dev_warn(dev, "%s: Failed to add OPP %ld\n",
__func__, freq);
nr -= 2;
}
return 0;
}
void of_free_opp_table(struct device *dev)
{
struct device_opp *dev_opp;
struct dev_pm_opp *opp, *tmp;
dev_opp = find_device_opp(dev);
if (IS_ERR(dev_opp)) {
int error = PTR_ERR(dev_opp);
if (error != -ENODEV)
WARN(1, "%s: dev_opp: %d\n",
IS_ERR_OR_NULL(dev) ?
"Invalid device" : dev_name(dev),
error);
return;
}
mutex_lock(&dev_opp_list_lock);
list_for_each_entry_safe(opp, tmp, &dev_opp->opp_list, node) {
if (!opp->dynamic)
__dev_pm_opp_remove(dev_opp, opp);
}
mutex_unlock(&dev_opp_list_lock);
}
