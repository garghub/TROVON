static struct pm_runtime_clk_data *__to_prd(struct device *dev)
{
return dev ? dev->power.subsys_data : NULL;
}
int pm_runtime_clk_add(struct device *dev, const char *con_id)
{
struct pm_runtime_clk_data *prd = __to_prd(dev);
struct pm_clock_entry *ce;
if (!prd)
return -EINVAL;
ce = kzalloc(sizeof(*ce), GFP_KERNEL);
if (!ce) {
dev_err(dev, "Not enough memory for clock entry.\n");
return -ENOMEM;
}
if (con_id) {
ce->con_id = kstrdup(con_id, GFP_KERNEL);
if (!ce->con_id) {
dev_err(dev,
"Not enough memory for clock connection ID.\n");
kfree(ce);
return -ENOMEM;
}
}
mutex_lock(&prd->lock);
list_add_tail(&ce->node, &prd->clock_list);
mutex_unlock(&prd->lock);
return 0;
}
static void __pm_runtime_clk_remove(struct pm_clock_entry *ce)
{
if (!ce)
return;
list_del(&ce->node);
if (ce->status < PCE_STATUS_ERROR) {
if (ce->status == PCE_STATUS_ENABLED)
clk_disable(ce->clk);
if (ce->status >= PCE_STATUS_ACQUIRED)
clk_put(ce->clk);
}
if (ce->con_id)
kfree(ce->con_id);
kfree(ce);
}
void pm_runtime_clk_remove(struct device *dev, const char *con_id)
{
struct pm_runtime_clk_data *prd = __to_prd(dev);
struct pm_clock_entry *ce;
if (!prd)
return;
mutex_lock(&prd->lock);
list_for_each_entry(ce, &prd->clock_list, node) {
if (!con_id && !ce->con_id) {
__pm_runtime_clk_remove(ce);
break;
} else if (!con_id || !ce->con_id) {
continue;
} else if (!strcmp(con_id, ce->con_id)) {
__pm_runtime_clk_remove(ce);
break;
}
}
mutex_unlock(&prd->lock);
}
int pm_runtime_clk_init(struct device *dev)
{
struct pm_runtime_clk_data *prd;
prd = kzalloc(sizeof(*prd), GFP_KERNEL);
if (!prd) {
dev_err(dev, "Not enough memory fo runtime PM data.\n");
return -ENOMEM;
}
INIT_LIST_HEAD(&prd->clock_list);
mutex_init(&prd->lock);
dev->power.subsys_data = prd;
return 0;
}
void pm_runtime_clk_destroy(struct device *dev)
{
struct pm_runtime_clk_data *prd = __to_prd(dev);
struct pm_clock_entry *ce, *c;
if (!prd)
return;
dev->power.subsys_data = NULL;
mutex_lock(&prd->lock);
list_for_each_entry_safe_reverse(ce, c, &prd->clock_list, node)
__pm_runtime_clk_remove(ce);
mutex_unlock(&prd->lock);
kfree(prd);
}
static void pm_runtime_clk_acquire(struct device *dev,
struct pm_clock_entry *ce)
{
ce->clk = clk_get(dev, ce->con_id);
if (IS_ERR(ce->clk)) {
ce->status = PCE_STATUS_ERROR;
} else {
ce->status = PCE_STATUS_ACQUIRED;
dev_dbg(dev, "Clock %s managed by runtime PM.\n", ce->con_id);
}
}
int pm_runtime_clk_suspend(struct device *dev)
{
struct pm_runtime_clk_data *prd = __to_prd(dev);
struct pm_clock_entry *ce;
dev_dbg(dev, "%s()\n", __func__);
if (!prd)
return 0;
mutex_lock(&prd->lock);
list_for_each_entry_reverse(ce, &prd->clock_list, node) {
if (ce->status == PCE_STATUS_NONE)
pm_runtime_clk_acquire(dev, ce);
if (ce->status < PCE_STATUS_ERROR) {
clk_disable(ce->clk);
ce->status = PCE_STATUS_ACQUIRED;
}
}
mutex_unlock(&prd->lock);
return 0;
}
int pm_runtime_clk_resume(struct device *dev)
{
struct pm_runtime_clk_data *prd = __to_prd(dev);
struct pm_clock_entry *ce;
dev_dbg(dev, "%s()\n", __func__);
if (!prd)
return 0;
mutex_lock(&prd->lock);
list_for_each_entry(ce, &prd->clock_list, node) {
if (ce->status == PCE_STATUS_NONE)
pm_runtime_clk_acquire(dev, ce);
if (ce->status < PCE_STATUS_ERROR) {
clk_enable(ce->clk);
ce->status = PCE_STATUS_ENABLED;
}
}
mutex_unlock(&prd->lock);
return 0;
}
static int pm_runtime_clk_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct pm_clk_notifier_block *clknb;
struct device *dev = data;
char **con_id;
int error;
dev_dbg(dev, "%s() %ld\n", __func__, action);
clknb = container_of(nb, struct pm_clk_notifier_block, nb);
switch (action) {
case BUS_NOTIFY_ADD_DEVICE:
if (dev->pwr_domain)
break;
error = pm_runtime_clk_init(dev);
if (error)
break;
dev->pwr_domain = clknb->pwr_domain;
if (clknb->con_ids[0]) {
for (con_id = clknb->con_ids; *con_id; con_id++)
pm_runtime_clk_add(dev, *con_id);
} else {
pm_runtime_clk_add(dev, NULL);
}
break;
case BUS_NOTIFY_DEL_DEVICE:
if (dev->pwr_domain != clknb->pwr_domain)
break;
dev->pwr_domain = NULL;
pm_runtime_clk_destroy(dev);
break;
}
return 0;
}
static void enable_clock(struct device *dev, const char *con_id)
{
struct clk *clk;
clk = clk_get(dev, con_id);
if (!IS_ERR(clk)) {
clk_enable(clk);
clk_put(clk);
dev_info(dev, "Runtime PM disabled, clock forced on.\n");
}
}
static void disable_clock(struct device *dev, const char *con_id)
{
struct clk *clk;
clk = clk_get(dev, con_id);
if (!IS_ERR(clk)) {
clk_disable(clk);
clk_put(clk);
dev_info(dev, "Runtime PM disabled, clock forced off.\n");
}
}
static int pm_runtime_clk_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct pm_clk_notifier_block *clknb;
struct device *dev = data;
char **con_id;
dev_dbg(dev, "%s() %ld\n", __func__, action);
clknb = container_of(nb, struct pm_clk_notifier_block, nb);
switch (action) {
case BUS_NOTIFY_BIND_DRIVER:
if (clknb->con_ids[0]) {
for (con_id = clknb->con_ids; *con_id; con_id++)
enable_clock(dev, *con_id);
} else {
enable_clock(dev, NULL);
}
break;
case BUS_NOTIFY_UNBOUND_DRIVER:
if (clknb->con_ids[0]) {
for (con_id = clknb->con_ids; *con_id; con_id++)
disable_clock(dev, *con_id);
} else {
disable_clock(dev, NULL);
}
break;
}
return 0;
}
void pm_runtime_clk_add_notifier(struct bus_type *bus,
struct pm_clk_notifier_block *clknb)
{
if (!bus || !clknb)
return;
clknb->nb.notifier_call = pm_runtime_clk_notify;
bus_register_notifier(bus, &clknb->nb);
}
