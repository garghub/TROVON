static int i2c_mux_reg_set(const struct regmux *mux, unsigned int chan_id)
{
if (!mux->data.reg)
return -EINVAL;
switch (mux->data.reg_size) {
case 4:
if (mux->data.little_endian)
iowrite32(chan_id, mux->data.reg);
else
iowrite32be(chan_id, mux->data.reg);
if (!mux->data.write_only)
ioread32(mux->data.reg);
break;
case 2:
if (mux->data.little_endian)
iowrite16(chan_id, mux->data.reg);
else
iowrite16be(chan_id, mux->data.reg);
if (!mux->data.write_only)
ioread16(mux->data.reg);
break;
case 1:
iowrite8(chan_id, mux->data.reg);
if (!mux->data.write_only)
ioread8(mux->data.reg);
break;
}
return 0;
}
static int i2c_mux_reg_select(struct i2c_mux_core *muxc, u32 chan)
{
struct regmux *mux = i2c_mux_priv(muxc);
return i2c_mux_reg_set(mux, chan);
}
static int i2c_mux_reg_deselect(struct i2c_mux_core *muxc, u32 chan)
{
struct regmux *mux = i2c_mux_priv(muxc);
if (mux->data.idle_in_use)
return i2c_mux_reg_set(mux, mux->data.idle);
return 0;
}
static int i2c_mux_reg_probe_dt(struct regmux *mux,
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *adapter_np, *child;
struct i2c_adapter *adapter;
struct resource res;
unsigned *values;
int i = 0;
if (!np)
return -ENODEV;
adapter_np = of_parse_phandle(np, "i2c-parent", 0);
if (!adapter_np) {
dev_err(&pdev->dev, "Cannot parse i2c-parent\n");
return -ENODEV;
}
adapter = of_find_i2c_adapter_by_node(adapter_np);
of_node_put(adapter_np);
if (!adapter)
return -EPROBE_DEFER;
mux->data.parent = i2c_adapter_id(adapter);
put_device(&adapter->dev);
mux->data.n_values = of_get_child_count(np);
if (of_find_property(np, "little-endian", NULL)) {
mux->data.little_endian = true;
} else if (of_find_property(np, "big-endian", NULL)) {
mux->data.little_endian = false;
} else {
#if defined(__BYTE_ORDER) ? __BYTE_ORDER == __LITTLE_ENDIAN : \
defined(__LITTLE_ENDIAN)
mux->data.little_endian = true;
#elif defined(__BYTE_ORDER) ? __BYTE_ORDER == __BIG_ENDIAN : \
defined(__BIG_ENDIAN)
mux->data.little_endian = false;
#else
#error Endianness not defined?
#endif
}
if (of_find_property(np, "write-only", NULL))
mux->data.write_only = true;
else
mux->data.write_only = false;
values = devm_kzalloc(&pdev->dev,
sizeof(*mux->data.values) * mux->data.n_values,
GFP_KERNEL);
if (!values) {
dev_err(&pdev->dev, "Cannot allocate values array");
return -ENOMEM;
}
for_each_child_of_node(np, child) {
of_property_read_u32(child, "reg", values + i);
i++;
}
mux->data.values = values;
if (!of_property_read_u32(np, "idle-state", &mux->data.idle))
mux->data.idle_in_use = true;
if (of_address_to_resource(np, 0, &res) == 0) {
mux->data.reg_size = resource_size(&res);
mux->data.reg = devm_ioremap_resource(&pdev->dev, &res);
if (IS_ERR(mux->data.reg))
return PTR_ERR(mux->data.reg);
}
return 0;
}
static int i2c_mux_reg_probe_dt(struct regmux *mux,
struct platform_device *pdev)
{
return 0;
}
static int i2c_mux_reg_probe(struct platform_device *pdev)
{
struct i2c_mux_core *muxc;
struct regmux *mux;
struct i2c_adapter *parent;
struct resource *res;
unsigned int class;
int i, ret, nr;
mux = devm_kzalloc(&pdev->dev, sizeof(*mux), GFP_KERNEL);
if (!mux)
return -ENOMEM;
if (dev_get_platdata(&pdev->dev)) {
memcpy(&mux->data, dev_get_platdata(&pdev->dev),
sizeof(mux->data));
} else {
ret = i2c_mux_reg_probe_dt(mux, pdev);
if (ret < 0) {
dev_err(&pdev->dev, "Error parsing device tree");
return ret;
}
}
parent = i2c_get_adapter(mux->data.parent);
if (!parent)
return -EPROBE_DEFER;
if (!mux->data.reg) {
dev_info(&pdev->dev,
"Register not set, using platform resource\n");
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mux->data.reg_size = resource_size(res);
mux->data.reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mux->data.reg)) {
ret = PTR_ERR(mux->data.reg);
goto err_put_parent;
}
}
if (mux->data.reg_size != 4 && mux->data.reg_size != 2 &&
mux->data.reg_size != 1) {
dev_err(&pdev->dev, "Invalid register size\n");
ret = -EINVAL;
goto err_put_parent;
}
muxc = i2c_mux_alloc(parent, &pdev->dev, mux->data.n_values, 0, 0,
i2c_mux_reg_select, NULL);
if (!muxc) {
ret = -ENOMEM;
goto err_put_parent;
}
muxc->priv = mux;
platform_set_drvdata(pdev, muxc);
if (mux->data.idle_in_use)
muxc->deselect = i2c_mux_reg_deselect;
for (i = 0; i < mux->data.n_values; i++) {
nr = mux->data.base_nr ? (mux->data.base_nr + i) : 0;
class = mux->data.classes ? mux->data.classes[i] : 0;
ret = i2c_mux_add_adapter(muxc, nr, mux->data.values[i], class);
if (ret)
goto err_del_mux_adapters;
}
dev_dbg(&pdev->dev, "%d port mux on %s adapter\n",
mux->data.n_values, muxc->parent->name);
return 0;
err_del_mux_adapters:
i2c_mux_del_adapters(muxc);
err_put_parent:
i2c_put_adapter(parent);
return ret;
}
static int i2c_mux_reg_remove(struct platform_device *pdev)
{
struct i2c_mux_core *muxc = platform_get_drvdata(pdev);
i2c_mux_del_adapters(muxc);
i2c_put_adapter(muxc->parent);
return 0;
}
