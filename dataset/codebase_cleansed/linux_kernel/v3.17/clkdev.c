struct clk *of_clk_get_by_clkspec(struct of_phandle_args *clkspec)
{
struct clk *clk;
if (!clkspec)
return ERR_PTR(-EINVAL);
of_clk_lock();
clk = __of_clk_get_from_provider(clkspec);
if (!IS_ERR(clk) && !__clk_get(clk))
clk = ERR_PTR(-ENOENT);
of_clk_unlock();
return clk;
}
struct clk *of_clk_get(struct device_node *np, int index)
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
clk = of_clk_get_by_clkspec(&clkspec);
of_node_put(clkspec.np);
return clk;
}
struct clk *of_clk_get_by_name(struct device_node *np, const char *name)
{
struct clk *clk = ERR_PTR(-ENOENT);
while (np) {
int index = 0;
if (name)
index = of_property_match_string(np, "clock-names", name);
clk = of_clk_get(np, index);
if (!IS_ERR(clk))
break;
else if (name && index >= 0) {
if (PTR_ERR(clk) != -EPROBE_DEFER)
pr_err("ERROR: could not get clock %s:%s(%i)\n",
np->full_name, name ? name : "", index);
return clk;
}
np = np->parent;
if (np && !of_get_property(np, "clock-ranges", NULL))
break;
}
return clk;
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
mutex_lock(&clocks_mutex);
cl = clk_find(dev_id, con_id);
if (cl && !__clk_get(cl->clk))
cl = NULL;
mutex_unlock(&clocks_mutex);
return cl ? cl->clk : ERR_PTR(-ENOENT);
}
struct clk *clk_get(struct device *dev, const char *con_id)
{
const char *dev_id = dev ? dev_name(dev) : NULL;
struct clk *clk;
if (dev) {
clk = of_clk_get_by_name(dev->of_node, con_id);
if (!IS_ERR(clk))
return clk;
if (PTR_ERR(clk) == -EPROBE_DEFER)
return clk;
}
return clk_get_sys(dev_id, con_id);
}
void clk_put(struct clk *clk)
{
__clk_put(clk);
}
void clkdev_add(struct clk_lookup *cl)
{
mutex_lock(&clocks_mutex);
list_add_tail(&cl->node, &clocks);
mutex_unlock(&clocks_mutex);
}
void __init clkdev_add_table(struct clk_lookup *cl, size_t num)
{
mutex_lock(&clocks_mutex);
while (num--) {
list_add_tail(&cl->node, &clocks);
cl++;
}
mutex_unlock(&clocks_mutex);
}
static struct clk_lookup * __init_refok
vclkdev_alloc(struct clk *clk, const char *con_id, const char *dev_fmt,
va_list ap)
{
struct clk_lookup_alloc *cla;
cla = __clkdev_alloc(sizeof(*cla));
if (!cla)
return NULL;
cla->cl.clk = clk;
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
struct clk_lookup * __init_refok
clkdev_alloc(struct clk *clk, const char *con_id, const char *dev_fmt, ...)
{
struct clk_lookup *cl;
va_list ap;
va_start(ap, dev_fmt);
cl = vclkdev_alloc(clk, con_id, dev_fmt, ap);
va_end(ap);
return cl;
}
int clk_add_alias(const char *alias, const char *alias_dev_name, char *id,
struct device *dev)
{
struct clk *r = clk_get(dev, id);
struct clk_lookup *l;
if (IS_ERR(r))
return PTR_ERR(r);
l = clkdev_alloc(r, alias, alias_dev_name);
clk_put(r);
if (!l)
return -ENODEV;
clkdev_add(l);
return 0;
}
void clkdev_drop(struct clk_lookup *cl)
{
mutex_lock(&clocks_mutex);
list_del(&cl->node);
mutex_unlock(&clocks_mutex);
kfree(cl);
}
int clk_register_clkdev(struct clk *clk, const char *con_id,
const char *dev_fmt, ...)
{
struct clk_lookup *cl;
va_list ap;
if (IS_ERR(clk))
return PTR_ERR(clk);
va_start(ap, dev_fmt);
cl = vclkdev_alloc(clk, con_id, dev_fmt, ap);
va_end(ap);
if (!cl)
return -ENOMEM;
clkdev_add(cl);
return 0;
}
int clk_register_clkdevs(struct clk *clk, struct clk_lookup *cl, size_t num)
{
unsigned i;
if (IS_ERR(clk))
return PTR_ERR(clk);
for (i = 0; i < num; i++, cl++) {
cl->clk = clk;
clkdev_add(cl);
}
return 0;
}
