static int arcxcnn_update_field(struct arcxcnn *lp, u8 reg, u8 mask, u8 data)
{
int ret;
u8 tmp;
ret = i2c_smbus_read_byte_data(lp->client, reg);
if (ret < 0) {
dev_err(lp->dev, "failed to read 0x%.2x\n", reg);
return ret;
}
tmp = (u8)ret;
tmp &= ~mask;
tmp |= data & mask;
return i2c_smbus_write_byte_data(lp->client, reg, tmp);
}
static int arcxcnn_set_brightness(struct arcxcnn *lp, u32 brightness)
{
int ret;
u8 val;
val = (brightness & 0xF) << ARCXCNN_WLED_ISET_LSB_SHIFT;
ret = i2c_smbus_write_byte_data(lp->client,
ARCXCNN_WLED_ISET_LSB, val);
if (ret < 0)
return ret;
val = (brightness >> 4);
return i2c_smbus_write_byte_data(lp->client,
ARCXCNN_WLED_ISET_MSB, val);
}
static int arcxcnn_bl_update_status(struct backlight_device *bl)
{
struct arcxcnn *lp = bl_get_data(bl);
u32 brightness = bl->props.brightness;
int ret;
if (bl->props.state & (BL_CORE_SUSPENDED | BL_CORE_FBBLANK))
brightness = 0;
ret = arcxcnn_set_brightness(lp, brightness);
if (ret)
return ret;
return arcxcnn_update_field(lp, ARCXCNN_CMD, ARCXCNN_CMD_STDBY,
(bl->props.power == 0) ? 0 : ARCXCNN_CMD_STDBY);
}
static int arcxcnn_backlight_register(struct arcxcnn *lp)
{
struct backlight_properties *props;
const char *name = lp->pdata->name ? : "arctic_bl";
props = devm_kzalloc(lp->dev, sizeof(*props), GFP_KERNEL);
if (!props)
return -ENOMEM;
props->type = BACKLIGHT_PLATFORM;
props->max_brightness = MAX_BRIGHTNESS;
if (lp->pdata->initial_brightness > props->max_brightness)
lp->pdata->initial_brightness = props->max_brightness;
props->brightness = lp->pdata->initial_brightness;
lp->bl = devm_backlight_device_register(lp->dev, name, lp->dev, lp,
&arcxcnn_bl_ops, props);
return PTR_ERR_OR_ZERO(lp->bl);
}
static void arcxcnn_parse_dt(struct arcxcnn *lp)
{
struct device *dev = lp->dev;
struct device_node *node = dev->of_node;
u32 prog_val, num_entry, entry, sources[ARCXCNN_LEDEN_BITS];
int ret;
if (!node)
return;
ret = of_property_read_string(node, "label", &lp->pdata->name);
if (ret < 0)
lp->pdata->name = NULL;
ret = of_property_read_u32(node, "default-brightness", &prog_val);
if (ret == 0)
lp->pdata->initial_brightness = prog_val;
ret = of_property_read_u32(node, "arc,led-config-0", &prog_val);
if (ret == 0)
lp->pdata->led_config_0 = (u8)prog_val;
ret = of_property_read_u32(node, "arc,led-config-1", &prog_val);
if (ret == 0)
lp->pdata->led_config_1 = (u8)prog_val;
ret = of_property_read_u32(node, "arc,dim-freq", &prog_val);
if (ret == 0)
lp->pdata->dim_freq = (u8)prog_val;
ret = of_property_read_u32(node, "arc,comp-config", &prog_val);
if (ret == 0)
lp->pdata->comp_config = (u8)prog_val;
ret = of_property_read_u32(node, "arc,filter-config", &prog_val);
if (ret == 0)
lp->pdata->filter_config = (u8)prog_val;
ret = of_property_read_u32(node, "arc,trim-config", &prog_val);
if (ret == 0)
lp->pdata->trim_config = (u8)prog_val;
ret = of_property_count_u32_elems(node, "led-sources");
if (ret < 0) {
lp->pdata->leden = ARCXCNN_LEDEN_MASK;
} else {
num_entry = ret;
if (num_entry > ARCXCNN_LEDEN_BITS)
num_entry = ARCXCNN_LEDEN_BITS;
ret = of_property_read_u32_array(node, "led-sources", sources,
num_entry);
if (ret < 0) {
dev_err(dev, "led-sources node is invalid.\n");
return;
}
lp->pdata->leden = 0;
for (entry = 0; entry < num_entry; entry++) {
u8 onbit = 1 << sources[entry];
lp->pdata->leden |= onbit;
}
}
}
static int arcxcnn_probe(struct i2c_client *cl, const struct i2c_device_id *id)
{
struct arcxcnn *lp;
int ret;
if (!i2c_check_functionality(cl->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
lp = devm_kzalloc(&cl->dev, sizeof(*lp), GFP_KERNEL);
if (!lp)
return -ENOMEM;
lp->client = cl;
lp->dev = &cl->dev;
lp->pdata = dev_get_platdata(&cl->dev);
ret = i2c_smbus_write_byte_data(lp->client,
ARCXCNN_CMD, ARCXCNN_CMD_RESET);
if (ret)
goto probe_err;
if (!lp->pdata) {
lp->pdata = devm_kzalloc(lp->dev,
sizeof(*lp->pdata), GFP_KERNEL);
if (!lp->pdata)
return -ENOMEM;
lp->pdata->name = NULL;
lp->pdata->initial_brightness = INIT_BRIGHT;
lp->pdata->leden = ARCXCNN_LEDEN_MASK;
lp->pdata->led_config_0 = i2c_smbus_read_byte_data(
lp->client, ARCXCNN_FADECTRL);
lp->pdata->led_config_1 = i2c_smbus_read_byte_data(
lp->client, ARCXCNN_ILED_CONFIG);
lp->pdata->led_config_1 |= ARCXCNN_ILED_DIM_INT;
lp->pdata->dim_freq = i2c_smbus_read_byte_data(
lp->client, ARCXCNN_DIMFREQ);
lp->pdata->comp_config = i2c_smbus_read_byte_data(
lp->client, ARCXCNN_COMP_CONFIG);
lp->pdata->filter_config = i2c_smbus_read_byte_data(
lp->client, ARCXCNN_FILT_CONFIG);
lp->pdata->trim_config = i2c_smbus_read_byte_data(
lp->client, ARCXCNN_IMAXTUNE);
if (IS_ENABLED(CONFIG_OF))
arcxcnn_parse_dt(lp);
}
i2c_set_clientdata(cl, lp);
if (lp->pdata->initial_brightness > MAX_BRIGHTNESS)
lp->pdata->initial_brightness = MAX_BRIGHTNESS;
ret = arcxcnn_set_brightness(lp, lp->pdata->initial_brightness);
if (ret)
goto probe_err;
ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_FADECTRL,
lp->pdata->led_config_0);
if (ret)
goto probe_err;
ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_ILED_CONFIG,
lp->pdata->led_config_1);
if (ret)
goto probe_err;
ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_DIMFREQ,
lp->pdata->dim_freq);
if (ret)
goto probe_err;
ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_COMP_CONFIG,
lp->pdata->comp_config);
if (ret)
goto probe_err;
ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_FILT_CONFIG,
lp->pdata->filter_config);
if (ret)
goto probe_err;
ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_IMAXTUNE,
lp->pdata->trim_config);
if (ret)
goto probe_err;
arcxcnn_update_field(lp, ARCXCNN_LEDEN,
ARCXCNN_LEDEN_MASK, lp->pdata->leden);
ret = arcxcnn_backlight_register(lp);
if (ret)
goto probe_register_err;
backlight_update_status(lp->bl);
return 0;
probe_register_err:
dev_err(lp->dev,
"failed to register backlight.\n");
probe_err:
dev_err(lp->dev,
"failure ret: %d\n", ret);
return ret;
}
static int arcxcnn_remove(struct i2c_client *cl)
{
struct arcxcnn *lp = i2c_get_clientdata(cl);
i2c_smbus_write_byte_data(lp->client,
ARCXCNN_LEDEN, 0x00);
i2c_smbus_write_byte_data(lp->client,
ARCXCNN_CMD, ARCXCNN_CMD_RESET);
lp->bl->props.brightness = 0;
backlight_update_status(lp->bl);
return 0;
}
