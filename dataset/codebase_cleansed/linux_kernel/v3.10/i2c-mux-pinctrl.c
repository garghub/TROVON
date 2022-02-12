static int i2c_mux_pinctrl_select(struct i2c_adapter *adap, void *data,
u32 chan)
{
struct i2c_mux_pinctrl *mux = data;
return pinctrl_select_state(mux->pinctrl, mux->states[chan]);
}
static int i2c_mux_pinctrl_deselect(struct i2c_adapter *adap, void *data,
u32 chan)
{
struct i2c_mux_pinctrl *mux = data;
return pinctrl_select_state(mux->pinctrl, mux->state_idle);
}
static int i2c_mux_pinctrl_parse_dt(struct i2c_mux_pinctrl *mux,
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
int num_names, i, ret;
struct device_node *adapter_np;
struct i2c_adapter *adapter;
if (!np)
return 0;
mux->pdata = devm_kzalloc(&pdev->dev, sizeof(*mux->pdata), GFP_KERNEL);
if (!mux->pdata) {
dev_err(mux->dev,
"Cannot allocate i2c_mux_pinctrl_platform_data\n");
return -ENOMEM;
}
num_names = of_property_count_strings(np, "pinctrl-names");
if (num_names < 0) {
dev_err(mux->dev, "Cannot parse pinctrl-names: %d\n",
num_names);
return num_names;
}
mux->pdata->pinctrl_states = devm_kzalloc(&pdev->dev,
sizeof(*mux->pdata->pinctrl_states) * num_names,
GFP_KERNEL);
if (!mux->pdata->pinctrl_states) {
dev_err(mux->dev, "Cannot allocate pinctrl_states\n");
return -ENOMEM;
}
for (i = 0; i < num_names; i++) {
ret = of_property_read_string_index(np, "pinctrl-names", i,
&mux->pdata->pinctrl_states[mux->pdata->bus_count]);
if (ret < 0) {
dev_err(mux->dev, "Cannot parse pinctrl-names: %d\n",
ret);
return ret;
}
if (!strcmp(mux->pdata->pinctrl_states[mux->pdata->bus_count],
"idle")) {
if (i != num_names - 1) {
dev_err(mux->dev, "idle state must be last\n");
return -EINVAL;
}
mux->pdata->pinctrl_state_idle = "idle";
} else {
mux->pdata->bus_count++;
}
}
adapter_np = of_parse_phandle(np, "i2c-parent", 0);
if (!adapter_np) {
dev_err(mux->dev, "Cannot parse i2c-parent\n");
return -ENODEV;
}
adapter = of_find_i2c_adapter_by_node(adapter_np);
if (!adapter) {
dev_err(mux->dev, "Cannot find parent bus\n");
return -ENODEV;
}
mux->pdata->parent_bus_num = i2c_adapter_id(adapter);
put_device(&adapter->dev);
return 0;
}
static inline int i2c_mux_pinctrl_parse_dt(struct i2c_mux_pinctrl *mux,
struct platform_device *pdev)
{
return 0;
}
static int i2c_mux_pinctrl_probe(struct platform_device *pdev)
{
struct i2c_mux_pinctrl *mux;
int (*deselect)(struct i2c_adapter *, void *, u32);
int i, ret;
mux = devm_kzalloc(&pdev->dev, sizeof(*mux), GFP_KERNEL);
if (!mux) {
dev_err(&pdev->dev, "Cannot allocate i2c_mux_pinctrl\n");
ret = -ENOMEM;
goto err;
}
platform_set_drvdata(pdev, mux);
mux->dev = &pdev->dev;
mux->pdata = pdev->dev.platform_data;
if (!mux->pdata) {
ret = i2c_mux_pinctrl_parse_dt(mux, pdev);
if (ret < 0)
goto err;
}
if (!mux->pdata) {
dev_err(&pdev->dev, "Missing platform data\n");
ret = -ENODEV;
goto err;
}
mux->states = devm_kzalloc(&pdev->dev,
sizeof(*mux->states) * mux->pdata->bus_count,
GFP_KERNEL);
if (!mux->states) {
dev_err(&pdev->dev, "Cannot allocate states\n");
ret = -ENOMEM;
goto err;
}
mux->busses = devm_kzalloc(&pdev->dev,
sizeof(*mux->busses) * mux->pdata->bus_count,
GFP_KERNEL);
if (!mux->busses) {
dev_err(&pdev->dev, "Cannot allocate busses\n");
ret = -ENOMEM;
goto err;
}
mux->pinctrl = devm_pinctrl_get(&pdev->dev);
if (IS_ERR(mux->pinctrl)) {
ret = PTR_ERR(mux->pinctrl);
dev_err(&pdev->dev, "Cannot get pinctrl: %d\n", ret);
goto err;
}
for (i = 0; i < mux->pdata->bus_count; i++) {
mux->states[i] = pinctrl_lookup_state(mux->pinctrl,
mux->pdata->pinctrl_states[i]);
if (IS_ERR(mux->states[i])) {
ret = PTR_ERR(mux->states[i]);
dev_err(&pdev->dev,
"Cannot look up pinctrl state %s: %d\n",
mux->pdata->pinctrl_states[i], ret);
goto err;
}
}
if (mux->pdata->pinctrl_state_idle) {
mux->state_idle = pinctrl_lookup_state(mux->pinctrl,
mux->pdata->pinctrl_state_idle);
if (IS_ERR(mux->state_idle)) {
ret = PTR_ERR(mux->state_idle);
dev_err(&pdev->dev,
"Cannot look up pinctrl state %s: %d\n",
mux->pdata->pinctrl_state_idle, ret);
goto err;
}
deselect = i2c_mux_pinctrl_deselect;
} else {
deselect = NULL;
}
mux->parent = i2c_get_adapter(mux->pdata->parent_bus_num);
if (!mux->parent) {
dev_err(&pdev->dev, "Parent adapter (%d) not found\n",
mux->pdata->parent_bus_num);
ret = -ENODEV;
goto err;
}
for (i = 0; i < mux->pdata->bus_count; i++) {
u32 bus = mux->pdata->base_bus_num ?
(mux->pdata->base_bus_num + i) : 0;
mux->busses[i] = i2c_add_mux_adapter(mux->parent, &pdev->dev,
mux, bus, i, 0,
i2c_mux_pinctrl_select,
deselect);
if (!mux->busses[i]) {
ret = -ENODEV;
dev_err(&pdev->dev, "Failed to add adapter %d\n", i);
goto err_del_adapter;
}
}
return 0;
err_del_adapter:
for (; i > 0; i--)
i2c_del_mux_adapter(mux->busses[i - 1]);
i2c_put_adapter(mux->parent);
err:
return ret;
}
static int i2c_mux_pinctrl_remove(struct platform_device *pdev)
{
struct i2c_mux_pinctrl *mux = platform_get_drvdata(pdev);
int i;
for (i = 0; i < mux->pdata->bus_count; i++)
i2c_del_mux_adapter(mux->busses[i]);
i2c_put_adapter(mux->parent);
return 0;
}
