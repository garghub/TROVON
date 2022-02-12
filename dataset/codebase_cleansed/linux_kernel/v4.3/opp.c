static struct device_list_opp *_find_list_dev(const struct device *dev,
struct device_opp *dev_opp)
{
struct device_list_opp *list_dev;
list_for_each_entry(list_dev, &dev_opp->dev_list, node)
if (list_dev->dev == dev)
return list_dev;
return NULL;
}
static struct device_opp *_managed_opp(const struct device_node *np)
{
struct device_opp *dev_opp;
list_for_each_entry_rcu(dev_opp, &dev_opp_list, node) {
if (dev_opp->np == np) {
return dev_opp->shared_opp ? dev_opp : NULL;
}
}
return NULL;
}
static struct device_opp *_find_device_opp(struct device *dev)
{
struct device_opp *dev_opp;
if (IS_ERR_OR_NULL(dev)) {
pr_err("%s: Invalid parameters\n", __func__);
return ERR_PTR(-EINVAL);
}
list_for_each_entry_rcu(dev_opp, &dev_opp_list, node)
if (_find_list_dev(dev, dev_opp))
return dev_opp;
return ERR_PTR(-ENODEV);
}
unsigned long dev_pm_opp_get_voltage(struct dev_pm_opp *opp)
{
struct dev_pm_opp *tmp_opp;
unsigned long v = 0;
opp_rcu_lockdep_assert();
tmp_opp = rcu_dereference(opp);
if (IS_ERR_OR_NULL(tmp_opp) || !tmp_opp->available)
pr_err("%s: Invalid parameters\n", __func__);
else
v = tmp_opp->u_volt;
return v;
}
unsigned long dev_pm_opp_get_freq(struct dev_pm_opp *opp)
{
struct dev_pm_opp *tmp_opp;
unsigned long f = 0;
opp_rcu_lockdep_assert();
tmp_opp = rcu_dereference(opp);
if (IS_ERR_OR_NULL(tmp_opp) || !tmp_opp->available)
pr_err("%s: Invalid parameters\n", __func__);
else
f = tmp_opp->rate;
return f;
}
bool dev_pm_opp_is_turbo(struct dev_pm_opp *opp)
{
struct dev_pm_opp *tmp_opp;
opp_rcu_lockdep_assert();
tmp_opp = rcu_dereference(opp);
if (IS_ERR_OR_NULL(tmp_opp) || !tmp_opp->available) {
pr_err("%s: Invalid parameters\n", __func__);
return false;
}
return tmp_opp->turbo;
}
unsigned long dev_pm_opp_get_max_clock_latency(struct device *dev)
{
struct device_opp *dev_opp;
unsigned long clock_latency_ns;
rcu_read_lock();
dev_opp = _find_device_opp(dev);
if (IS_ERR(dev_opp))
clock_latency_ns = 0;
else
clock_latency_ns = dev_opp->clock_latency_ns_max;
rcu_read_unlock();
return clock_latency_ns;
}
struct dev_pm_opp *dev_pm_opp_get_suspend_opp(struct device *dev)
{
struct device_opp *dev_opp;
opp_rcu_lockdep_assert();
dev_opp = _find_device_opp(dev);
if (IS_ERR(dev_opp) || !dev_opp->suspend_opp ||
!dev_opp->suspend_opp->available)
return NULL;
return dev_opp->suspend_opp;
}
int dev_pm_opp_get_opp_count(struct device *dev)
{
struct device_opp *dev_opp;
struct dev_pm_opp *temp_opp;
int count = 0;
rcu_read_lock();
dev_opp = _find_device_opp(dev);
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
dev_opp = _find_device_opp(dev);
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
dev_opp = _find_device_opp(dev);
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
dev_opp = _find_device_opp(dev);
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
static void _kfree_list_dev_rcu(struct rcu_head *head)
{
struct device_list_opp *list_dev;
list_dev = container_of(head, struct device_list_opp, rcu_head);
kfree_rcu(list_dev, rcu_head);
}
static void _remove_list_dev(struct device_list_opp *list_dev,
struct device_opp *dev_opp)
{
list_del(&list_dev->node);
call_srcu(&dev_opp->srcu_head.srcu, &list_dev->rcu_head,
_kfree_list_dev_rcu);
}
static struct device_list_opp *_add_list_dev(const struct device *dev,
struct device_opp *dev_opp)
{
struct device_list_opp *list_dev;
list_dev = kzalloc(sizeof(*list_dev), GFP_KERNEL);
if (!list_dev)
return NULL;
list_dev->dev = dev;
list_add_rcu(&list_dev->node, &dev_opp->dev_list);
return list_dev;
}
static struct device_opp *_add_device_opp(struct device *dev)
{
struct device_opp *dev_opp;
struct device_list_opp *list_dev;
dev_opp = _find_device_opp(dev);
if (!IS_ERR(dev_opp))
return dev_opp;
dev_opp = kzalloc(sizeof(*dev_opp), GFP_KERNEL);
if (!dev_opp)
return NULL;
INIT_LIST_HEAD(&dev_opp->dev_list);
list_dev = _add_list_dev(dev, dev_opp);
if (!list_dev) {
kfree(dev_opp);
return NULL;
}
srcu_init_notifier_head(&dev_opp->srcu_head);
INIT_LIST_HEAD(&dev_opp->opp_list);
list_add_rcu(&dev_opp->node, &dev_opp_list);
return dev_opp;
}
static void _kfree_device_rcu(struct rcu_head *head)
{
struct device_opp *device_opp = container_of(head, struct device_opp, rcu_head);
kfree_rcu(device_opp, rcu_head);
}
static void _remove_device_opp(struct device_opp *dev_opp)
{
struct device_list_opp *list_dev;
if (!list_empty(&dev_opp->opp_list))
return;
list_dev = list_first_entry(&dev_opp->dev_list, struct device_list_opp,
node);
_remove_list_dev(list_dev, dev_opp);
WARN_ON(!list_empty(&dev_opp->dev_list));
list_del_rcu(&dev_opp->node);
call_srcu(&dev_opp->srcu_head.srcu, &dev_opp->rcu_head,
_kfree_device_rcu);
}
static void _kfree_opp_rcu(struct rcu_head *head)
{
struct dev_pm_opp *opp = container_of(head, struct dev_pm_opp, rcu_head);
kfree_rcu(opp, rcu_head);
}
static void _opp_remove(struct device_opp *dev_opp,
struct dev_pm_opp *opp, bool notify)
{
if (notify)
srcu_notifier_call_chain(&dev_opp->srcu_head, OPP_EVENT_REMOVE, opp);
list_del_rcu(&opp->node);
call_srcu(&dev_opp->srcu_head.srcu, &opp->rcu_head, _kfree_opp_rcu);
_remove_device_opp(dev_opp);
}
void dev_pm_opp_remove(struct device *dev, unsigned long freq)
{
struct dev_pm_opp *opp;
struct device_opp *dev_opp;
bool found = false;
mutex_lock(&dev_opp_list_lock);
dev_opp = _find_device_opp(dev);
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
_opp_remove(dev_opp, opp, true);
unlock:
mutex_unlock(&dev_opp_list_lock);
}
static struct dev_pm_opp *_allocate_opp(struct device *dev,
struct device_opp **dev_opp)
{
struct dev_pm_opp *opp;
opp = kzalloc(sizeof(*opp), GFP_KERNEL);
if (!opp)
return NULL;
INIT_LIST_HEAD(&opp->node);
*dev_opp = _add_device_opp(dev);
if (!*dev_opp) {
kfree(opp);
return NULL;
}
return opp;
}
static int _opp_add(struct device *dev, struct dev_pm_opp *new_opp,
struct device_opp *dev_opp)
{
struct dev_pm_opp *opp;
struct list_head *head = &dev_opp->opp_list;
list_for_each_entry_rcu(opp, &dev_opp->opp_list, node) {
if (new_opp->rate > opp->rate) {
head = &opp->node;
continue;
}
if (new_opp->rate < opp->rate)
break;
dev_warn(dev, "%s: duplicate OPPs detected. Existing: freq: %lu, volt: %lu, enabled: %d. New: freq: %lu, volt: %lu, enabled: %d\n",
__func__, opp->rate, opp->u_volt, opp->available,
new_opp->rate, new_opp->u_volt, new_opp->available);
return opp->available && new_opp->u_volt == opp->u_volt ?
0 : -EEXIST;
}
new_opp->dev_opp = dev_opp;
list_add_rcu(&new_opp->node, head);
return 0;
}
static int _opp_add_dynamic(struct device *dev, unsigned long freq,
long u_volt, bool dynamic)
{
struct device_opp *dev_opp;
struct dev_pm_opp *new_opp;
int ret;
mutex_lock(&dev_opp_list_lock);
new_opp = _allocate_opp(dev, &dev_opp);
if (!new_opp) {
ret = -ENOMEM;
goto unlock;
}
new_opp->rate = freq;
new_opp->u_volt = u_volt;
new_opp->available = true;
new_opp->dynamic = dynamic;
ret = _opp_add(dev, new_opp, dev_opp);
if (ret)
goto free_opp;
mutex_unlock(&dev_opp_list_lock);
srcu_notifier_call_chain(&dev_opp->srcu_head, OPP_EVENT_ADD, new_opp);
return 0;
free_opp:
_opp_remove(dev_opp, new_opp, false);
unlock:
mutex_unlock(&dev_opp_list_lock);
return ret;
}
static int opp_get_microvolt(struct dev_pm_opp *opp, struct device *dev)
{
u32 microvolt[3] = {0};
int count, ret;
if (!of_find_property(opp->np, "opp-microvolt", NULL))
return 0;
count = of_property_count_u32_elems(opp->np, "opp-microvolt");
if (count < 0) {
dev_err(dev, "%s: Invalid opp-microvolt property (%d)\n",
__func__, count);
return count;
}
if (count != 1 && count != 3) {
dev_err(dev, "%s: Invalid number of elements in opp-microvolt property (%d)\n",
__func__, count);
return -EINVAL;
}
ret = of_property_read_u32_array(opp->np, "opp-microvolt", microvolt,
count);
if (ret) {
dev_err(dev, "%s: error parsing opp-microvolt: %d\n", __func__,
ret);
return -EINVAL;
}
opp->u_volt = microvolt[0];
opp->u_volt_min = microvolt[1];
opp->u_volt_max = microvolt[2];
return 0;
}
static int _opp_add_static_v2(struct device *dev, struct device_node *np)
{
struct device_opp *dev_opp;
struct dev_pm_opp *new_opp;
u64 rate;
u32 val;
int ret;
mutex_lock(&dev_opp_list_lock);
new_opp = _allocate_opp(dev, &dev_opp);
if (!new_opp) {
ret = -ENOMEM;
goto unlock;
}
ret = of_property_read_u64(np, "opp-hz", &rate);
if (ret < 0) {
dev_err(dev, "%s: opp-hz not found\n", __func__);
goto free_opp;
}
new_opp->rate = (unsigned long)rate;
new_opp->turbo = of_property_read_bool(np, "turbo-mode");
new_opp->np = np;
new_opp->dynamic = false;
new_opp->available = true;
if (!of_property_read_u32(np, "clock-latency-ns", &val))
new_opp->clock_latency_ns = val;
ret = opp_get_microvolt(new_opp, dev);
if (ret)
goto free_opp;
if (!of_property_read_u32(new_opp->np, "opp-microamp", &val))
new_opp->u_amp = val;
ret = _opp_add(dev, new_opp, dev_opp);
if (ret)
goto free_opp;
if (of_property_read_bool(np, "opp-suspend")) {
if (dev_opp->suspend_opp)
dev_warn(dev, "%s: Multiple suspend OPPs found (%lu %lu)\n",
__func__, dev_opp->suspend_opp->rate,
new_opp->rate);
else
dev_opp->suspend_opp = new_opp;
}
if (new_opp->clock_latency_ns > dev_opp->clock_latency_ns_max)
dev_opp->clock_latency_ns_max = new_opp->clock_latency_ns;
mutex_unlock(&dev_opp_list_lock);
pr_debug("%s: turbo:%d rate:%lu uv:%lu uvmin:%lu uvmax:%lu latency:%lu\n",
__func__, new_opp->turbo, new_opp->rate, new_opp->u_volt,
new_opp->u_volt_min, new_opp->u_volt_max,
new_opp->clock_latency_ns);
srcu_notifier_call_chain(&dev_opp->srcu_head, OPP_EVENT_ADD, new_opp);
return 0;
free_opp:
_opp_remove(dev_opp, new_opp, false);
unlock:
mutex_unlock(&dev_opp_list_lock);
return ret;
}
int dev_pm_opp_add(struct device *dev, unsigned long freq, unsigned long u_volt)
{
return _opp_add_dynamic(dev, freq, u_volt, true);
}
static int _opp_set_availability(struct device *dev, unsigned long freq,
bool availability_req)
{
struct device_opp *dev_opp;
struct dev_pm_opp *new_opp, *tmp_opp, *opp = ERR_PTR(-ENODEV);
int r = 0;
new_opp = kmalloc(sizeof(*new_opp), GFP_KERNEL);
if (!new_opp)
return -ENOMEM;
mutex_lock(&dev_opp_list_lock);
dev_opp = _find_device_opp(dev);
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
call_srcu(&dev_opp->srcu_head.srcu, &opp->rcu_head, _kfree_opp_rcu);
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
return _opp_set_availability(dev, freq, true);
}
int dev_pm_opp_disable(struct device *dev, unsigned long freq)
{
return _opp_set_availability(dev, freq, false);
}
struct srcu_notifier_head *dev_pm_opp_get_notifier(struct device *dev)
{
struct device_opp *dev_opp = _find_device_opp(dev);
if (IS_ERR(dev_opp))
return ERR_CAST(dev_opp);
return &dev_opp->srcu_head;
}
void of_free_opp_table(struct device *dev)
{
struct device_opp *dev_opp;
struct dev_pm_opp *opp, *tmp;
mutex_lock(&dev_opp_list_lock);
dev_opp = _find_device_opp(dev);
if (IS_ERR(dev_opp)) {
int error = PTR_ERR(dev_opp);
if (error != -ENODEV)
WARN(1, "%s: dev_opp: %d\n",
IS_ERR_OR_NULL(dev) ?
"Invalid device" : dev_name(dev),
error);
goto unlock;
}
if (list_is_singular(&dev_opp->dev_list)) {
list_for_each_entry_safe(opp, tmp, &dev_opp->opp_list, node) {
if (!opp->dynamic)
_opp_remove(dev_opp, opp, true);
}
} else {
_remove_list_dev(_find_list_dev(dev, dev_opp), dev_opp);
}
unlock:
mutex_unlock(&dev_opp_list_lock);
}
void of_cpumask_free_opp_table(cpumask_var_t cpumask)
{
struct device *cpu_dev;
int cpu;
WARN_ON(cpumask_empty(cpumask));
for_each_cpu(cpu, cpumask) {
cpu_dev = get_cpu_device(cpu);
if (!cpu_dev) {
pr_err("%s: failed to get cpu%d device\n", __func__,
cpu);
continue;
}
of_free_opp_table(cpu_dev);
}
}
static struct device_node *
_of_get_opp_desc_node_from_prop(struct device *dev, const struct property *prop)
{
struct device_node *opp_np;
opp_np = of_find_node_by_phandle(be32_to_cpup(prop->value));
if (!opp_np) {
dev_err(dev, "%s: Prop: %s contains invalid opp desc phandle\n",
__func__, prop->name);
return ERR_PTR(-EINVAL);
}
return opp_np;
}
static struct device_node *_of_get_opp_desc_node(struct device *dev)
{
const struct property *prop;
prop = of_find_property(dev->of_node, "operating-points-v2", NULL);
if (!prop)
return ERR_PTR(-ENODEV);
if (!prop->value)
return ERR_PTR(-ENODATA);
if (prop->length != sizeof(__be32)) {
dev_err(dev, "%s: Invalid opp desc phandle\n", __func__);
return ERR_PTR(-EINVAL);
}
return _of_get_opp_desc_node_from_prop(dev, prop);
}
static int _of_init_opp_table_v2(struct device *dev,
const struct property *prop)
{
struct device_node *opp_np, *np;
struct device_opp *dev_opp;
int ret = 0, count = 0;
if (!prop->value)
return -ENODATA;
opp_np = _of_get_opp_desc_node_from_prop(dev, prop);
if (IS_ERR(opp_np))
return PTR_ERR(opp_np);
dev_opp = _managed_opp(opp_np);
if (dev_opp) {
if (!_add_list_dev(dev, dev_opp))
ret = -ENOMEM;
goto put_opp_np;
}
for_each_available_child_of_node(opp_np, np) {
count++;
ret = _opp_add_static_v2(dev, np);
if (ret) {
dev_err(dev, "%s: Failed to add OPP, %d\n", __func__,
ret);
goto free_table;
}
}
if (WARN_ON(!count)) {
ret = -ENOENT;
goto put_opp_np;
}
dev_opp = _find_device_opp(dev);
if (WARN_ON(IS_ERR(dev_opp))) {
ret = PTR_ERR(dev_opp);
goto free_table;
}
dev_opp->np = opp_np;
dev_opp->shared_opp = of_property_read_bool(opp_np, "opp-shared");
of_node_put(opp_np);
return 0;
free_table:
of_free_opp_table(dev);
put_opp_np:
of_node_put(opp_np);
return ret;
}
static int _of_init_opp_table_v1(struct device *dev)
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
if (_opp_add_dynamic(dev, freq, volt, false))
dev_warn(dev, "%s: Failed to add OPP %ld\n",
__func__, freq);
nr -= 2;
}
return 0;
}
int of_init_opp_table(struct device *dev)
{
const struct property *prop;
prop = of_find_property(dev->of_node, "operating-points-v2", NULL);
if (!prop) {
return _of_init_opp_table_v1(dev);
}
return _of_init_opp_table_v2(dev, prop);
}
int of_cpumask_init_opp_table(cpumask_var_t cpumask)
{
struct device *cpu_dev;
int cpu, ret = 0;
WARN_ON(cpumask_empty(cpumask));
for_each_cpu(cpu, cpumask) {
cpu_dev = get_cpu_device(cpu);
if (!cpu_dev) {
pr_err("%s: failed to get cpu%d device\n", __func__,
cpu);
continue;
}
ret = of_init_opp_table(cpu_dev);
if (ret) {
pr_err("%s: couldn't find opp table for cpu:%d, %d\n",
__func__, cpu, ret);
of_cpumask_free_opp_table(cpumask);
break;
}
}
return ret;
}
int set_cpus_sharing_opps(struct device *cpu_dev, cpumask_var_t cpumask)
{
struct device_list_opp *list_dev;
struct device_opp *dev_opp;
struct device *dev;
int cpu, ret = 0;
rcu_read_lock();
dev_opp = _find_device_opp(cpu_dev);
if (IS_ERR(dev_opp)) {
ret = -EINVAL;
goto out_rcu_read_unlock;
}
for_each_cpu(cpu, cpumask) {
if (cpu == cpu_dev->id)
continue;
dev = get_cpu_device(cpu);
if (!dev) {
dev_err(cpu_dev, "%s: failed to get cpu%d device\n",
__func__, cpu);
continue;
}
list_dev = _add_list_dev(dev, dev_opp);
if (!list_dev) {
dev_err(dev, "%s: failed to add list-dev for cpu%d device\n",
__func__, cpu);
continue;
}
}
out_rcu_read_unlock:
rcu_read_unlock();
return 0;
}
int of_get_cpus_sharing_opps(struct device *cpu_dev, cpumask_var_t cpumask)
{
struct device_node *np, *tmp_np;
struct device *tcpu_dev;
int cpu, ret = 0;
np = _of_get_opp_desc_node(cpu_dev);
if (IS_ERR(np)) {
dev_dbg(cpu_dev, "%s: Couldn't find opp node: %ld\n", __func__,
PTR_ERR(np));
return -ENOENT;
}
if (!of_property_read_bool(np, "opp-shared"))
goto put_cpu_node;
for_each_possible_cpu(cpu) {
if (cpu == cpu_dev->id)
continue;
tcpu_dev = get_cpu_device(cpu);
if (!tcpu_dev) {
dev_err(cpu_dev, "%s: failed to get cpu%d device\n",
__func__, cpu);
ret = -ENODEV;
goto put_cpu_node;
}
tmp_np = _of_get_opp_desc_node(tcpu_dev);
if (IS_ERR(tmp_np)) {
dev_err(tcpu_dev, "%s: Couldn't find opp node: %ld\n",
__func__, PTR_ERR(tmp_np));
ret = PTR_ERR(tmp_np);
goto put_cpu_node;
}
if (np == tmp_np)
cpumask_set_cpu(cpu, cpumask);
of_node_put(tmp_np);
}
put_cpu_node:
of_node_put(np);
return ret;
}
