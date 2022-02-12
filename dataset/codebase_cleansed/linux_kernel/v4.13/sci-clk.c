static int sci_clk_prepare(struct clk_hw *hw)
{
struct sci_clk *clk = to_sci_clk(hw);
bool enable_ssc = clk->flags & SCI_CLK_SSC_ENABLE;
bool allow_freq_change = clk->flags & SCI_CLK_ALLOW_FREQ_CHANGE;
bool input_termination = clk->flags & SCI_CLK_INPUT_TERMINATION;
return clk->provider->ops->get_clock(clk->provider->sci, clk->dev_id,
clk->clk_id, enable_ssc,
allow_freq_change,
input_termination);
}
static void sci_clk_unprepare(struct clk_hw *hw)
{
struct sci_clk *clk = to_sci_clk(hw);
int ret;
ret = clk->provider->ops->put_clock(clk->provider->sci, clk->dev_id,
clk->clk_id);
if (ret)
dev_err(clk->provider->dev,
"unprepare failed for dev=%d, clk=%d, ret=%d\n",
clk->dev_id, clk->clk_id, ret);
}
static int sci_clk_is_prepared(struct clk_hw *hw)
{
struct sci_clk *clk = to_sci_clk(hw);
bool req_state, current_state;
int ret;
ret = clk->provider->ops->is_on(clk->provider->sci, clk->dev_id,
clk->clk_id, &req_state,
&current_state);
if (ret) {
dev_err(clk->provider->dev,
"is_prepared failed for dev=%d, clk=%d, ret=%d\n",
clk->dev_id, clk->clk_id, ret);
return 0;
}
return req_state;
}
static unsigned long sci_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct sci_clk *clk = to_sci_clk(hw);
u64 freq;
int ret;
ret = clk->provider->ops->get_freq(clk->provider->sci, clk->dev_id,
clk->clk_id, &freq);
if (ret) {
dev_err(clk->provider->dev,
"recalc-rate failed for dev=%d, clk=%d, ret=%d\n",
clk->dev_id, clk->clk_id, ret);
return 0;
}
return freq;
}
static int sci_clk_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct sci_clk *clk = to_sci_clk(hw);
int ret;
u64 new_rate;
ret = clk->provider->ops->get_best_match_freq(clk->provider->sci,
clk->dev_id,
clk->clk_id,
req->min_rate,
req->rate,
req->max_rate,
&new_rate);
if (ret) {
dev_err(clk->provider->dev,
"determine-rate failed for dev=%d, clk=%d, ret=%d\n",
clk->dev_id, clk->clk_id, ret);
return ret;
}
req->rate = new_rate;
return 0;
}
static int sci_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct sci_clk *clk = to_sci_clk(hw);
return clk->provider->ops->set_freq(clk->provider->sci, clk->dev_id,
clk->clk_id, rate, rate, rate);
}
static u8 sci_clk_get_parent(struct clk_hw *hw)
{
struct sci_clk *clk = to_sci_clk(hw);
u8 parent_id;
int ret;
ret = clk->provider->ops->get_parent(clk->provider->sci, clk->dev_id,
clk->clk_id, &parent_id);
if (ret) {
dev_err(clk->provider->dev,
"get-parent failed for dev=%d, clk=%d, ret=%d\n",
clk->dev_id, clk->clk_id, ret);
return 0;
}
return parent_id - clk->clk_id - 1;
}
static int sci_clk_set_parent(struct clk_hw *hw, u8 index)
{
struct sci_clk *clk = to_sci_clk(hw);
return clk->provider->ops->set_parent(clk->provider->sci, clk->dev_id,
clk->clk_id,
index + 1 + clk->clk_id);
}
static struct clk_hw *_sci_clk_build(struct sci_clk_provider *provider,
u16 dev_id, u8 clk_id)
{
struct clk_init_data init = { NULL };
struct sci_clk *sci_clk = NULL;
char *name = NULL;
char **parent_names = NULL;
int i;
int ret;
sci_clk = devm_kzalloc(provider->dev, sizeof(*sci_clk), GFP_KERNEL);
if (!sci_clk)
return ERR_PTR(-ENOMEM);
sci_clk->dev_id = dev_id;
sci_clk->clk_id = clk_id;
sci_clk->provider = provider;
ret = provider->ops->get_num_parents(provider->sci, dev_id,
clk_id,
&init.num_parents);
if (ret)
goto err;
name = kasprintf(GFP_KERNEL, "%s:%d:%d", dev_name(provider->dev),
sci_clk->dev_id, sci_clk->clk_id);
init.name = name;
if (init.num_parents < 2)
init.num_parents = 0;
if (init.num_parents) {
parent_names = kcalloc(init.num_parents, sizeof(char *),
GFP_KERNEL);
if (!parent_names) {
ret = -ENOMEM;
goto err;
}
for (i = 0; i < init.num_parents; i++) {
char *parent_name;
parent_name = kasprintf(GFP_KERNEL, "%s:%d:%d",
dev_name(provider->dev),
sci_clk->dev_id,
sci_clk->clk_id + 1 + i);
if (!parent_name) {
ret = -ENOMEM;
goto err;
}
parent_names[i] = parent_name;
}
init.parent_names = (void *)parent_names;
}
init.ops = &sci_clk_ops;
sci_clk->hw.init = &init;
ret = devm_clk_hw_register(provider->dev, &sci_clk->hw);
if (ret)
dev_err(provider->dev, "failed clk register with %d\n", ret);
err:
if (parent_names) {
for (i = 0; i < init.num_parents; i++)
kfree(parent_names[i]);
kfree(parent_names);
}
kfree(name);
if (ret)
return ERR_PTR(ret);
return &sci_clk->hw;
}
static int _cmp_sci_clk(const void *a, const void *b)
{
const struct sci_clk *ca = a;
const struct sci_clk *cb = *(struct sci_clk **)b;
if (ca->dev_id == cb->dev_id && ca->clk_id == cb->clk_id)
return 0;
if (ca->dev_id > cb->dev_id ||
(ca->dev_id == cb->dev_id && ca->clk_id > cb->clk_id))
return 1;
return -1;
}
static struct clk_hw *sci_clk_get(struct of_phandle_args *clkspec, void *data)
{
struct sci_clk_provider *provider = data;
struct sci_clk **clk;
struct sci_clk key;
if (clkspec->args_count != 2)
return ERR_PTR(-EINVAL);
key.dev_id = clkspec->args[0];
key.clk_id = clkspec->args[1];
clk = bsearch(&key, provider->clocks, provider->num_clocks,
sizeof(clk), _cmp_sci_clk);
if (!clk)
return ERR_PTR(-ENODEV);
return &(*clk)->hw;
}
static int ti_sci_init_clocks(struct sci_clk_provider *p)
{
const struct sci_clk_data *data = p->clk_data;
struct clk_hw *hw;
int i;
int num_clks = 0;
while (data->num_clks) {
num_clks += data->num_clks;
data++;
}
p->num_clocks = num_clks;
p->clocks = devm_kcalloc(p->dev, num_clks, sizeof(struct sci_clk),
GFP_KERNEL);
if (!p->clocks)
return -ENOMEM;
num_clks = 0;
data = p->clk_data;
while (data->num_clks) {
for (i = 0; i < data->num_clks; i++) {
hw = _sci_clk_build(p, data->dev, i);
if (!IS_ERR(hw)) {
p->clocks[num_clks++] = hw;
continue;
}
if (PTR_ERR(hw) == -ENODEV)
continue;
return PTR_ERR(hw);
}
data++;
}
return 0;
}
static int ti_sci_clk_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct sci_clk_provider *provider;
const struct ti_sci_handle *handle;
const struct sci_clk_data *data;
int ret;
data = of_device_get_match_data(dev);
if (!data)
return -EINVAL;
handle = devm_ti_sci_get_handle(dev);
if (IS_ERR(handle))
return PTR_ERR(handle);
provider = devm_kzalloc(dev, sizeof(*provider), GFP_KERNEL);
if (!provider)
return -ENOMEM;
provider->clk_data = data;
provider->sci = handle;
provider->ops = &handle->ops.clk_ops;
provider->dev = dev;
ret = ti_sci_init_clocks(provider);
if (ret) {
pr_err("ti-sci-init-clocks failed.\n");
return ret;
}
return of_clk_add_hw_provider(np, sci_clk_get, provider);
}
static int ti_sci_clk_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
return 0;
}
