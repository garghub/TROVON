static void devm_clk_release(struct device *dev, void *res)
{
clk_put(*(struct clk **)res);
}
struct clk *devm_clk_get(struct device *dev, const char *id)
{
struct clk **ptr, *clk;
ptr = devres_alloc(devm_clk_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
clk = clk_get(dev, id);
if (!IS_ERR(clk)) {
*ptr = clk;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return clk;
}
static void devm_clk_bulk_release(struct device *dev, void *res)
{
struct clk_bulk_devres *devres = res;
clk_bulk_put(devres->num_clks, devres->clks);
}
int __must_check devm_clk_bulk_get(struct device *dev, int num_clks,
struct clk_bulk_data *clks)
{
struct clk_bulk_devres *devres;
int ret;
devres = devres_alloc(devm_clk_bulk_release,
sizeof(*devres), GFP_KERNEL);
if (!devres)
return -ENOMEM;
ret = clk_bulk_get(dev, num_clks, clks);
if (!ret) {
devres->clks = clks;
devres->num_clks = num_clks;
devres_add(dev, devres);
} else {
devres_free(devres);
}
return ret;
}
static int devm_clk_match(struct device *dev, void *res, void *data)
{
struct clk **c = res;
if (!c || !*c) {
WARN_ON(!c || !*c);
return 0;
}
return *c == data;
}
void devm_clk_put(struct device *dev, struct clk *clk)
{
int ret;
ret = devres_release(dev, devm_clk_release, devm_clk_match, clk);
WARN_ON(ret);
}
struct clk *devm_get_clk_from_child(struct device *dev,
struct device_node *np, const char *con_id)
{
struct clk **ptr, *clk;
ptr = devres_alloc(devm_clk_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
clk = of_clk_get_by_name(np, con_id);
if (!IS_ERR(clk)) {
*ptr = clk;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return clk;
}
