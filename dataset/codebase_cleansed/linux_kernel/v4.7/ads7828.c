static inline u8 ads7828_cmd_byte(u8 cmd, int ch)
{
return cmd | (((ch >> 1) | (ch & 0x01) << 2) << 4);
}
static ssize_t ads7828_show_in(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ads7828_data *data = dev_get_drvdata(dev);
u8 cmd = ads7828_cmd_byte(data->cmd_byte, attr->index);
unsigned int regval;
int err;
err = regmap_read(data->regmap, cmd, &regval);
if (err < 0)
return err;
return sprintf(buf, "%d\n",
DIV_ROUND_CLOSEST(regval * data->lsb_resol, 1000));
}
static int ads7828_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct ads7828_platform_data *pdata = dev_get_platdata(dev);
struct ads7828_data *data;
struct device *hwmon_dev;
unsigned int vref_mv = ADS7828_INT_VREF_MV;
bool diff_input = false;
bool ext_vref = false;
unsigned int regval;
data = devm_kzalloc(dev, sizeof(struct ads7828_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
if (pdata) {
diff_input = pdata->diff_input;
ext_vref = pdata->ext_vref;
if (ext_vref && pdata->vref_mv)
vref_mv = pdata->vref_mv;
}
vref_mv = clamp_val(vref_mv, ADS7828_EXT_VREF_MV_MIN,
ADS7828_EXT_VREF_MV_MAX);
if (id->driver_data == ads7828) {
data->lsb_resol = DIV_ROUND_CLOSEST(vref_mv * 1000, 4096);
data->regmap = devm_regmap_init_i2c(client,
&ads2828_regmap_config);
} else {
data->lsb_resol = DIV_ROUND_CLOSEST(vref_mv * 1000, 256);
data->regmap = devm_regmap_init_i2c(client,
&ads2830_regmap_config);
}
if (IS_ERR(data->regmap))
return PTR_ERR(data->regmap);
data->cmd_byte = ext_vref ? ADS7828_CMD_PD1 : ADS7828_CMD_PD3;
if (!diff_input)
data->cmd_byte |= ADS7828_CMD_SD_SE;
if (!ext_vref)
regmap_read(data->regmap, data->cmd_byte, &regval);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data,
ads7828_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
