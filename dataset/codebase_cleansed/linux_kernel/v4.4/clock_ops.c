static inline void __pm_clk_enable(struct device *dev, struct pm_clock_entry *ce)
{
int ret;
if (ce->status < PCE_STATUS_ERROR) {
ret = clk_enable(ce->clk);
if (!ret)
ce->status = PCE_STATUS_ENABLED;
else
dev_err(dev, "%s: failed to enable clk %p, error %d\n",
__func__, ce->clk, ret);
}
}
static void pm_clk_acquire(struct device *dev, struct pm_clock_entry *ce)
{
if (!ce->clk)
ce->clk = clk_get(dev, ce->con_id);
if (IS_ERR(ce->clk)) {
ce->status = PCE_STATUS_ERROR;
} else {
clk_prepare(ce->clk);
ce->status = PCE_STATUS_ACQUIRED;
dev_dbg(dev, "Clock %pC con_id %s managed by runtime PM.\n",
ce->clk, ce->con_id);
}
}
static int __pm_clk_add(struct device *dev, const char *con_id,
struct clk *clk)
{
struct pm_subsys_data *psd = dev_to_psd(dev);
struct pm_clock_entry *ce;
if (!psd)
return -EINVAL;
ce = kzalloc(sizeof(*ce), GFP_KERNEL);
if (!ce)
return -ENOMEM;
if (con_id) {
ce->con_id = kstrdup(con_id, GFP_KERNEL);
if (!ce->con_id) {
dev_err(dev,
"Not enough memory for clock connection ID.\n");
kfree(ce);
return -ENOMEM;
}
} else {
if (IS_ERR(clk)) {
kfree(ce);
return -ENOENT;
}
ce->clk = clk;
}
pm_clk_acquire(dev, ce);
spin_lock_irq(&psd->lock);
list_add_tail(&ce->node, &psd->clock_list);
spin_unlock_irq(&psd->lock);
return 0;
}
int pm_clk_add(struct device *dev, const char *con_id)
{
return __pm_clk_add(dev, con_id, NULL);
}
int pm_clk_add_clk(struct device *dev, struct clk *clk)
{
return __pm_clk_add(dev, NULL, clk);
}
static void __pm_clk_remove(struct pm_clock_entry *ce)
{
if (!ce)
return;
if (ce->status < PCE_STATUS_ERROR) {
if (ce->status == PCE_STATUS_ENABLED)
clk_disable(ce->clk);
if (ce->status >= PCE_STATUS_ACQUIRED) {
clk_unprepare(ce->clk);
clk_put(ce->clk);
}
}
kfree(ce->con_id);
kfree(ce);
}
void pm_clk_remove(struct device *dev, const char *con_id)
{
struct pm_subsys_data *psd = dev_to_psd(dev);
struct pm_clock_entry *ce;
if (!psd)
return;
spin_lock_irq(&psd->lock);
list_for_each_entry(ce, &psd->clock_list, node) {
if (!con_id && !ce->con_id)
goto remove;
else if (!con_id || !ce->con_id)
continue;
else if (!strcmp(con_id, ce->con_id))
goto remove;
}
spin_unlock_irq(&psd->lock);
return;
remove:
list_del(&ce->node);
spin_unlock_irq(&psd->lock);
__pm_clk_remove(ce);
}
void pm_clk_init(struct device *dev)
{
struct pm_subsys_data *psd = dev_to_psd(dev);
if (psd)
INIT_LIST_HEAD(&psd->clock_list);
}
int pm_clk_create(struct device *dev)
{
return dev_pm_get_subsys_data(dev);
}
void pm_clk_destroy(struct device *dev)
{
struct pm_subsys_data *psd = dev_to_psd(dev);
struct pm_clock_entry *ce, *c;
struct list_head list;
if (!psd)
return;
INIT_LIST_HEAD(&list);
spin_lock_irq(&psd->lock);
list_for_each_entry_safe_reverse(ce, c, &psd->clock_list, node)
list_move(&ce->node, &list);
spin_unlock_irq(&psd->lock);
dev_pm_put_subsys_data(dev);
list_for_each_entry_safe_reverse(ce, c, &list, node) {
list_del(&ce->node);
__pm_clk_remove(ce);
}
}
int pm_clk_suspend(struct device *dev)
{
struct pm_subsys_data *psd = dev_to_psd(dev);
struct pm_clock_entry *ce;
unsigned long flags;
dev_dbg(dev, "%s()\n", __func__);
if (!psd)
return 0;
spin_lock_irqsave(&psd->lock, flags);
list_for_each_entry_reverse(ce, &psd->clock_list, node) {
if (ce->status < PCE_STATUS_ERROR) {
if (ce->status == PCE_STATUS_ENABLED)
clk_disable(ce->clk);
ce->status = PCE_STATUS_ACQUIRED;
}
}
spin_unlock_irqrestore(&psd->lock, flags);
return 0;
}
int pm_clk_resume(struct device *dev)
{
struct pm_subsys_data *psd = dev_to_psd(dev);
struct pm_clock_entry *ce;
unsigned long flags;
dev_dbg(dev, "%s()\n", __func__);
if (!psd)
return 0;
spin_lock_irqsave(&psd->lock, flags);
list_for_each_entry(ce, &psd->clock_list, node)
__pm_clk_enable(dev, ce);
spin_unlock_irqrestore(&psd->lock, flags);
return 0;
}
static int pm_clk_notify(struct notifier_block *nb,
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
if (dev->pm_domain)
break;
error = pm_clk_create(dev);
if (error)
break;
dev->pm_domain = clknb->pm_domain;
if (clknb->con_ids[0]) {
for (con_id = clknb->con_ids; *con_id; con_id++)
pm_clk_add(dev, *con_id);
} else {
pm_clk_add(dev, NULL);
}
break;
case BUS_NOTIFY_DEL_DEVICE:
if (dev->pm_domain != clknb->pm_domain)
break;
dev->pm_domain = NULL;
pm_clk_destroy(dev);
break;
}
return 0;
}
int pm_clk_runtime_suspend(struct device *dev)
{
int ret;
dev_dbg(dev, "%s\n", __func__);
ret = pm_generic_runtime_suspend(dev);
if (ret) {
dev_err(dev, "failed to suspend device\n");
return ret;
}
ret = pm_clk_suspend(dev);
if (ret) {
dev_err(dev, "failed to suspend clock\n");
pm_generic_runtime_resume(dev);
return ret;
}
return 0;
}
int pm_clk_runtime_resume(struct device *dev)
{
int ret;
dev_dbg(dev, "%s\n", __func__);
ret = pm_clk_resume(dev);
if (ret) {
dev_err(dev, "failed to resume clock\n");
return ret;
}
return pm_generic_runtime_resume(dev);
}
static void enable_clock(struct device *dev, const char *con_id)
{
struct clk *clk;
clk = clk_get(dev, con_id);
if (!IS_ERR(clk)) {
clk_prepare_enable(clk);
clk_put(clk);
dev_info(dev, "Runtime PM disabled, clock forced on.\n");
}
}
static void disable_clock(struct device *dev, const char *con_id)
{
struct clk *clk;
clk = clk_get(dev, con_id);
if (!IS_ERR(clk)) {
clk_disable_unprepare(clk);
clk_put(clk);
dev_info(dev, "Runtime PM disabled, clock forced off.\n");
}
}
static int pm_clk_notify(struct notifier_block *nb,
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
void pm_clk_add_notifier(struct bus_type *bus,
struct pm_clk_notifier_block *clknb)
{
if (!bus || !clknb)
return;
clknb->nb.notifier_call = pm_clk_notify;
bus_register_notifier(bus, &clknb->nb);
}
