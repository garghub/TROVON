static int mcp3021_read16(struct i2c_client *client)
{
struct mcp3021_data *data = i2c_get_clientdata(client);
int ret;
u16 reg;
__be16 buf;
ret = i2c_master_recv(client, (char *)&buf, 2);
if (ret < 0)
return ret;
if (ret != 2)
return -EIO;
reg = be16_to_cpu(buf);
reg = (reg >> data->sar_shift) & data->sar_mask;
return reg;
}
static inline u16 volts_from_reg(struct mcp3021_data *data, u16 val)
{
return DIV_ROUND_CLOSEST(data->vdd * val, 1 << data->output_res);
}
static ssize_t in0_input_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct mcp3021_data *data = i2c_get_clientdata(client);
int reg, in_input;
reg = mcp3021_read16(client);
if (reg < 0)
return reg;
in_input = volts_from_reg(data, reg);
return sprintf(buf, "%d\n", in_input);
}
static int mcp3021_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int err;
struct mcp3021_data *data = NULL;
struct device_node *np = client->dev.of_node;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
data = devm_kzalloc(&client->dev, sizeof(struct mcp3021_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
if (np) {
if (!of_property_read_u32(np, "reference-voltage-microvolt",
&data->vdd))
data->vdd /= 1000;
else
data->vdd = MCP3021_VDD_REF_DEFAULT;
} else {
u32 *pdata = dev_get_platdata(&client->dev);
if (pdata)
data->vdd = *pdata;
else
data->vdd = MCP3021_VDD_REF_DEFAULT;
}
switch (id->driver_data) {
case mcp3021:
data->sar_shift = MCP3021_SAR_SHIFT;
data->sar_mask = MCP3021_SAR_MASK;
data->output_res = MCP3021_OUTPUT_RES;
break;
case mcp3221:
data->sar_shift = MCP3221_SAR_SHIFT;
data->sar_mask = MCP3221_SAR_MASK;
data->output_res = MCP3221_OUTPUT_RES;
break;
}
if (data->vdd > MCP3021_VDD_REF_MAX || data->vdd < MCP3021_VDD_REF_MIN)
return -EINVAL;
err = sysfs_create_file(&client->dev.kobj, &dev_attr_in0_input.attr);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_file(&client->dev.kobj, &dev_attr_in0_input.attr);
return err;
}
static int mcp3021_remove(struct i2c_client *client)
{
struct mcp3021_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_file(&client->dev.kobj, &dev_attr_in0_input.attr);
return 0;
}
