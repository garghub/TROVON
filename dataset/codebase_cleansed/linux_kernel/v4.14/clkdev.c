static struct clk *__of_clk_get(struct device_node *np, int index,
const char *dev_id, const char *con_id)
{
struct of_phandle_args clkspec;
struct clk *clk;
int rc;
if (index < 0)
return ERR_PTR(-EINVAL);
rc = of_parse_phandle_with_args(np, "clocks", "#clock-cells", index,
&clkspec);
if (rc)
return ERR_PTR(rc);
clk = __of_clk_get_from_provider(&clkspec, dev_id, con_id);
of_node_put(clkspec.np);
return clk;
}
struct clk *of_clk_get(struct device_node *np, int index)
{
return __of_clk_get(np, index, np->full_name, NULL);
}
static struct clk *__of_clk_get_by_name(struct device_node *np,
const char *dev_id,
const char *name)
{
struct clk *clk = ERR_PTR(-ENOENT);
while (np) {
int index = 0;
if (name)
index = of_property_match_string(np, "clock-names", name);
clk = __of_clk_get(np, index, dev_id, name);
if (!IS_ERR(clk)) {
break;
} else if (name && index >= 0) {
if (PTR_ERR(clk) != -EPROBE_DEFER)
pr_err("ERROR: could not get clock %pOF:%s(%i)\n",
np, name ? name : "", index);
return clk;
}
np = np->parent;
if (np && !of_get_property(np, "clock-ranges", NULL))
break;
}
return clk;
}
struct clk *of_clk_get_by_name(struct device_node *np, const char *name)
{
if (!np)
return ERR_PTR(-ENOENT);
return __of_clk_get_by_name(np, np->full_name, name);
}
static struct clk *__of_clk_get_by_name(struct device_node *np,
const char *dev_id,
const char *name)
{
return ERR_PTR(-ENOENT);
}
static struct clk_lookup *clk_find(const char *dev_id, const char *con_id)
{
struct clk_lookup *p, *cl = NULL;
int match, best_found = 0, best_possible = 0;
if (dev_id)
best_possible += 2;
if (con_id)
best_possible += 1;
list_for_each_entry(p, &clocks, node) {
match = 0;
if (p->dev_id) {
if (!dev_id || strcmp(p->dev_id, dev_id))
continue;
match += 2;
}
if (p->con_id) {
if (!con_id || strcmp(p->con_id, con_id))
continue;
match += 1;
}
if (match > best_found) {
cl = p;
if (match != best_possible)
best_found = match;
else
break;
}
}
return cl;
}
struct clk *clk_get_sys(const char *dev_id, const char *con_id)
{
struct clk_lookup *cl;
struct clk *clk = NULL;
mutex_lock(&clocks_mutex);
cl = clk_find(dev_id, con_id);
if (!cl)
goto out;
clk = __clk_create_clk(cl->clk_hw, dev_id, con_id);
if (IS_ERR(clk))
goto out;
if (!__clk_get(clk)) {
__clk_free_clk(clk);
cl = NULL;
goto out;
}
out:
mutex_unlock(&clocks_mutex);
return cl ? clk : ERR_PTR(-ENOENT);
}
struct clk *clk_get(struct device *dev, const char *con_id)
{
const char *dev_id = dev ? dev_name(dev) : NULL;
struct clk *clk;
if (dev) {
clk = __of_clk_get_by_name(dev->of_node, dev_id, con_id);
if (!IS_ERR(clk) || PTR_ERR(clk) == -EPROBE_DEFER)
return clk;
}
return clk_get_sys(dev_id, con_id);
}
void clk_put(struct clk *clk)
{
__clk_put(clk);
}
static void __clkdev_add(struct clk_lookup *cl)
{
mutex_lock(&clocks_mutex);
list_add_tail(&cl->node, &clocks);
mutex_unlock(&clocks_mutex);
}
void clkdev_add(struct clk_lookup *cl)
{
if (!cl->clk_hw)
cl->clk_hw = __clk_get_hw(cl->clk);
__clkdev_add(cl);
}
void clkdev_add_table(struct clk_lookup *cl, size_t num)
{
mutex_lock(&clocks_mutex);
while (num--) {
cl->clk_hw = __clk_get_hw(cl->clk);
list_add_tail(&cl->node, &clocks);
cl++;
}
mutex_unlock(&clocks_mutex);
}
static struct clk_lookup * __ref
vclkdev_alloc(struct clk_hw *hw, const char *con_id, const char *dev_fmt,
va_list ap)
{
struct clk_lookup_alloc *cla;
cla = __clkdev_alloc(sizeof(*cla));
if (!cla)
return NULL;
cla->cl.clk_hw = hw;
if (con_id) {
strlcpy(cla->con_id, con_id, sizeof(cla->con_id));
cla->cl.con_id = cla->con_id;
}
if (dev_fmt) {
vscnprintf(cla->dev_id, sizeof(cla->dev_id), dev_fmt, ap);
cla->cl.dev_id = cla->dev_id;
}
return &cla->cl;
}
static struct clk_lookup *
vclkdev_create(struct clk_hw *hw, const char *con_id, const char *dev_fmt,
va_list ap)
{
struct clk_lookup *cl;
cl = vclkdev_alloc(hw, con_id, dev_fmt, ap);
if (cl)
__clkdev_add(cl);
return cl;
}
struct clk_lookup * __ref
clkdev_alloc(struct clk *clk, const char *con_id, const char *dev_fmt, ...)
{
struct clk_lookup *cl;
va_list ap;
va_start(ap, dev_fmt);
cl = vclkdev_alloc(__clk_get_hw(clk), con_id, dev_fmt, ap);
va_end(ap);
return cl;
}
struct clk_lookup *
clkdev_hw_alloc(struct clk_hw *hw, const char *con_id, const char *dev_fmt, ...)
{
struct clk_lookup *cl;
va_list ap;
va_start(ap, dev_fmt);
cl = vclkdev_alloc(hw, con_id, dev_fmt, ap);
va_end(ap);
return cl;
}
struct clk_lookup *clkdev_create(struct clk *clk, const char *con_id,
const char *dev_fmt, ...)
{
struct clk_lookup *cl;
va_list ap;
va_start(ap, dev_fmt);
cl = vclkdev_create(__clk_get_hw(clk), con_id, dev_fmt, ap);
va_end(ap);
return cl;
}
struct clk_lookup *clkdev_hw_create(struct clk_hw *hw, const char *con_id,
const char *dev_fmt, ...)
{
struct clk_lookup *cl;
va_list ap;
va_start(ap, dev_fmt);
cl = vclkdev_create(hw, con_id, dev_fmt, ap);
va_end(ap);
return cl;
}
int clk_add_alias(const char *alias, const char *alias_dev_name,
const char *con_id, struct device *dev)
{
struct clk *r = clk_get(dev, con_id);
struct clk_lookup *l;
if (IS_ERR(r))
return PTR_ERR(r);
l = clkdev_create(r, alias, alias_dev_name ? "%s" : NULL,
alias_dev_name);
clk_put(r);
return l ? 0 : -ENODEV;
}
void clkdev_drop(struct clk_lookup *cl)
{
mutex_lock(&clocks_mutex);
list_del(&cl->node);
mutex_unlock(&clocks_mutex);
kfree(cl);
}
static struct clk_lookup *__clk_register_clkdev(struct clk_hw *hw,
const char *con_id,
const char *dev_id, ...)
{
struct clk_lookup *cl;
va_list ap;
va_start(ap, dev_id);
cl = vclkdev_create(hw, con_id, dev_id, ap);
va_end(ap);
return cl;
}
int clk_register_clkdev(struct clk *clk, const char *con_id,
const char *dev_id)
{
struct clk_lookup *cl;
if (IS_ERR(clk))
return PTR_ERR(clk);
if (dev_id)
cl = __clk_register_clkdev(__clk_get_hw(clk), con_id, "%s",
dev_id);
else
cl = __clk_register_clkdev(__clk_get_hw(clk), con_id, NULL);
return cl ? 0 : -ENOMEM;
}
int clk_hw_register_clkdev(struct clk_hw *hw, const char *con_id,
const char *dev_id)
{
struct clk_lookup *cl;
if (IS_ERR(hw))
return PTR_ERR(hw);
if (dev_id)
cl = __clk_register_clkdev(hw, con_id, "%s", dev_id);
else
cl = __clk_register_clkdev(hw, con_id, NULL);
return cl ? 0 : -ENOMEM;
}
