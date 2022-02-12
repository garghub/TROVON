static void usb251xb_reset(struct usb251xb *hub, int state)
{
if (!gpio_is_valid(hub->gpio_reset))
return;
gpio_set_value_cansleep(hub->gpio_reset, state);
if (state)
usleep_range(500, 750);
else
usleep_range(1, 10);
}
static int usb251xb_connect(struct usb251xb *hub)
{
struct device *dev = hub->dev;
int err, i;
char i2c_wb[USB251XB_I2C_REG_SZ];
memset(i2c_wb, 0, USB251XB_I2C_REG_SZ);
if (hub->skip_config) {
dev_info(dev, "Skip hub configuration, only attach.\n");
i2c_wb[0] = 0x01;
i2c_wb[1] = USB251XB_STATUS_COMMAND_ATTACH;
usb251xb_reset(hub, 1);
err = i2c_smbus_write_i2c_block_data(hub->i2c,
USB251XB_ADDR_STATUS_COMMAND, 2, i2c_wb);
if (err) {
dev_err(dev, "attaching hub failed: %d\n", err);
return err;
}
return 0;
}
i2c_wb[USB251XB_ADDR_VENDOR_ID_MSB] = (hub->vendor_id >> 8) & 0xFF;
i2c_wb[USB251XB_ADDR_VENDOR_ID_LSB] = hub->vendor_id & 0xFF;
i2c_wb[USB251XB_ADDR_PRODUCT_ID_MSB] = (hub->product_id >> 8) & 0xFF;
i2c_wb[USB251XB_ADDR_PRODUCT_ID_LSB] = hub->product_id & 0xFF;
i2c_wb[USB251XB_ADDR_DEVICE_ID_MSB] = (hub->device_id >> 8) & 0xFF;
i2c_wb[USB251XB_ADDR_DEVICE_ID_LSB] = hub->device_id & 0xFF;
i2c_wb[USB251XB_ADDR_CONFIG_DATA_1] = hub->conf_data1;
i2c_wb[USB251XB_ADDR_CONFIG_DATA_2] = hub->conf_data2;
i2c_wb[USB251XB_ADDR_CONFIG_DATA_3] = hub->conf_data3;
i2c_wb[USB251XB_ADDR_NON_REMOVABLE_DEVICES] = hub->non_rem_dev;
i2c_wb[USB251XB_ADDR_PORT_DISABLE_SELF] = hub->port_disable_sp;
i2c_wb[USB251XB_ADDR_PORT_DISABLE_BUS] = hub->port_disable_bp;
i2c_wb[USB251XB_ADDR_MAX_POWER_SELF] = hub->max_power_sp;
i2c_wb[USB251XB_ADDR_MAX_POWER_BUS] = hub->max_power_bp;
i2c_wb[USB251XB_ADDR_MAX_CURRENT_SELF] = hub->max_current_sp;
i2c_wb[USB251XB_ADDR_MAX_CURRENT_BUS] = hub->max_current_bp;
i2c_wb[USB251XB_ADDR_POWER_ON_TIME] = hub->power_on_time;
i2c_wb[USB251XB_ADDR_LANGUAGE_ID_HIGH] = (hub->lang_id >> 8) & 0xFF;
i2c_wb[USB251XB_ADDR_LANGUAGE_ID_LOW] = hub->lang_id & 0xFF;
i2c_wb[USB251XB_ADDR_MANUFACTURER_STRING_LEN] = hub->manufacturer_len;
i2c_wb[USB251XB_ADDR_PRODUCT_STRING_LEN] = hub->product_len;
i2c_wb[USB251XB_ADDR_SERIAL_STRING_LEN] = hub->serial_len;
memcpy(&i2c_wb[USB251XB_ADDR_MANUFACTURER_STRING], hub->manufacturer,
USB251XB_STRING_BUFSIZE);
memcpy(&i2c_wb[USB251XB_ADDR_SERIAL_STRING], hub->serial,
USB251XB_STRING_BUFSIZE);
memcpy(&i2c_wb[USB251XB_ADDR_PRODUCT_STRING], hub->product,
USB251XB_STRING_BUFSIZE);
i2c_wb[USB251XB_ADDR_BATTERY_CHARGING_ENABLE] = hub->bat_charge_en;
i2c_wb[USB251XB_ADDR_BOOST_UP] = hub->boost_up;
i2c_wb[USB251XB_ADDR_BOOST_X] = hub->boost_x;
i2c_wb[USB251XB_ADDR_PORT_SWAP] = hub->port_swap;
i2c_wb[USB251XB_ADDR_PORT_MAP_12] = hub->port_map12;
i2c_wb[USB251XB_ADDR_PORT_MAP_34] = hub->port_map34;
i2c_wb[USB251XB_ADDR_STATUS_COMMAND] = USB251XB_STATUS_COMMAND_ATTACH;
usb251xb_reset(hub, 1);
for (i = 0; i < (USB251XB_I2C_REG_SZ / USB251XB_I2C_WRITE_SZ); i++) {
int offset = i * USB251XB_I2C_WRITE_SZ;
char wbuf[USB251XB_I2C_WRITE_SZ + 1];
wbuf[0] = USB251XB_I2C_WRITE_SZ;
memcpy(&wbuf[1], &i2c_wb[offset], USB251XB_I2C_WRITE_SZ);
dev_dbg(dev, "writing %d byte block %d to 0x%02X\n",
USB251XB_I2C_WRITE_SZ, i, offset);
err = i2c_smbus_write_i2c_block_data(hub->i2c, offset,
USB251XB_I2C_WRITE_SZ + 1,
wbuf);
if (err)
goto out_err;
}
dev_info(dev, "Hub configuration was successful.\n");
return 0;
out_err:
dev_err(dev, "configuring block %d failed: %d\n", i, err);
return err;
}
static int usb251xb_get_ofdata(struct usb251xb *hub,
struct usb251xb_data *data)
{
struct device *dev = hub->dev;
struct device_node *np = dev->of_node;
int len, err, i;
u32 *property_u32 = NULL;
const u32 *cproperty_u32;
const char *cproperty_char;
char str[USB251XB_STRING_BUFSIZE / 2];
if (!np) {
dev_err(dev, "failed to get ofdata\n");
return -ENODEV;
}
if (of_get_property(np, "skip-config", NULL))
hub->skip_config = 1;
else
hub->skip_config = 0;
hub->gpio_reset = of_get_named_gpio(np, "reset-gpios", 0);
if (hub->gpio_reset == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (gpio_is_valid(hub->gpio_reset)) {
err = devm_gpio_request_one(dev, hub->gpio_reset,
GPIOF_OUT_INIT_LOW,
"usb251xb reset");
if (err) {
dev_err(dev,
"unable to request GPIO %d as reset pin (%d)\n",
hub->gpio_reset, err);
return err;
}
}
if (of_property_read_u16_array(np, "vendor-id", &hub->vendor_id, 1))
hub->vendor_id = USB251XB_DEF_VENDOR_ID;
if (of_property_read_u16_array(np, "product-id",
&hub->product_id, 1))
hub->product_id = data->product_id;
if (of_property_read_u16_array(np, "device-id", &hub->device_id, 1))
hub->device_id = USB251XB_DEF_DEVICE_ID;
hub->conf_data1 = USB251XB_DEF_CONFIG_DATA_1;
if (of_get_property(np, "self-powered", NULL)) {
hub->conf_data1 |= BIT(7);
hub->conf_data1 &= ~BIT(2);
if (of_get_property(np, "ganged-sensing", NULL))
hub->conf_data1 &= ~BIT(1);
else if (of_get_property(np, "individual-sensing", NULL))
hub->conf_data1 |= BIT(1);
} else if (of_get_property(np, "bus-powered", NULL)) {
hub->conf_data1 &= ~BIT(7);
hub->conf_data1 |= BIT(2);
}
if (of_get_property(np, "disable-hi-speed", NULL))
hub->conf_data1 |= BIT(5);
if (of_get_property(np, "multi-tt", NULL))
hub->conf_data1 |= BIT(4);
else if (of_get_property(np, "single-tt", NULL))
hub->conf_data1 &= ~BIT(4);
if (of_get_property(np, "disable-eop", NULL))
hub->conf_data1 |= BIT(3);
if (of_get_property(np, "individual-port-switching", NULL))
hub->conf_data1 |= BIT(0);
else if (of_get_property(np, "ganged-port-switching", NULL))
hub->conf_data1 &= ~BIT(0);
hub->conf_data2 = USB251XB_DEF_CONFIG_DATA_2;
if (of_get_property(np, "dynamic-power-switching", NULL))
hub->conf_data2 |= BIT(7);
if (!of_property_read_u32(np, "oc-delay-us", property_u32)) {
if (*property_u32 == 100) {
hub->conf_data2 &= ~BIT(5);
hub->conf_data2 &= ~BIT(4);
} else if (*property_u32 == 4000) {
hub->conf_data2 &= ~BIT(5);
hub->conf_data2 |= BIT(4);
} else if (*property_u32 == 16000) {
hub->conf_data2 |= BIT(5);
hub->conf_data2 |= BIT(4);
} else {
hub->conf_data2 |= BIT(5);
hub->conf_data2 &= ~BIT(4);
}
}
if (of_get_property(np, "compound-device", NULL))
hub->conf_data2 |= BIT(3);
hub->conf_data3 = USB251XB_DEF_CONFIG_DATA_3;
if (of_get_property(np, "port-mapping-mode", NULL))
hub->conf_data3 |= BIT(3);
if (of_get_property(np, "string-support", NULL))
hub->conf_data3 |= BIT(0);
hub->non_rem_dev = USB251XB_DEF_NON_REMOVABLE_DEVICES;
cproperty_u32 = of_get_property(np, "non-removable-ports", &len);
if (cproperty_u32 && (len / sizeof(u32)) > 0) {
for (i = 0; i < len / sizeof(u32); i++) {
u32 port = be32_to_cpu(cproperty_u32[i]);
if ((port >= 1) && (port <= 4))
hub->non_rem_dev |= BIT(port);
}
}
hub->port_disable_sp = USB251XB_DEF_PORT_DISABLE_SELF;
cproperty_u32 = of_get_property(np, "sp-disabled-ports", &len);
if (cproperty_u32 && (len / sizeof(u32)) > 0) {
for (i = 0; i < len / sizeof(u32); i++) {
u32 port = be32_to_cpu(cproperty_u32[i]);
if ((port >= 1) && (port <= 4))
hub->port_disable_sp |= BIT(port);
}
}
hub->port_disable_bp = USB251XB_DEF_PORT_DISABLE_BUS;
cproperty_u32 = of_get_property(np, "bp-disabled-ports", &len);
if (cproperty_u32 && (len / sizeof(u32)) > 0) {
for (i = 0; i < len / sizeof(u32); i++) {
u32 port = be32_to_cpu(cproperty_u32[i]);
if ((port >= 1) && (port <= 4))
hub->port_disable_bp |= BIT(port);
}
}
hub->power_on_time = USB251XB_DEF_POWER_ON_TIME;
if (!of_property_read_u32(np, "power-on-time-ms", property_u32))
hub->power_on_time = min_t(u8, *property_u32 / 2, 255);
if (of_property_read_u16_array(np, "language-id", &hub->lang_id, 1))
hub->lang_id = USB251XB_DEF_LANGUAGE_ID;
cproperty_char = of_get_property(np, "manufacturer", NULL);
strlcpy(str, cproperty_char ? : USB251XB_DEF_MANUFACTURER_STRING,
sizeof(str));
hub->manufacturer_len = strlen(str) & 0xFF;
memset(hub->manufacturer, 0, USB251XB_STRING_BUFSIZE);
len = min_t(size_t, USB251XB_STRING_BUFSIZE / 2, strlen(str));
len = utf8s_to_utf16s(str, len, UTF16_LITTLE_ENDIAN,
(wchar_t *)hub->manufacturer,
USB251XB_STRING_BUFSIZE);
cproperty_char = of_get_property(np, "product", NULL);
strlcpy(str, cproperty_char ? : data->product_str, sizeof(str));
hub->product_len = strlen(str) & 0xFF;
memset(hub->product, 0, USB251XB_STRING_BUFSIZE);
len = min_t(size_t, USB251XB_STRING_BUFSIZE / 2, strlen(str));
len = utf8s_to_utf16s(str, len, UTF16_LITTLE_ENDIAN,
(wchar_t *)hub->product,
USB251XB_STRING_BUFSIZE);
cproperty_char = of_get_property(np, "serial", NULL);
strlcpy(str, cproperty_char ? : USB251XB_DEF_SERIAL_STRING,
sizeof(str));
hub->serial_len = strlen(str) & 0xFF;
memset(hub->serial, 0, USB251XB_STRING_BUFSIZE);
len = min_t(size_t, USB251XB_STRING_BUFSIZE / 2, strlen(str));
len = utf8s_to_utf16s(str, len, UTF16_LITTLE_ENDIAN,
(wchar_t *)hub->serial,
USB251XB_STRING_BUFSIZE);
hub->max_power_sp = USB251XB_DEF_MAX_POWER_SELF;
hub->max_power_bp = USB251XB_DEF_MAX_POWER_BUS;
hub->max_current_sp = USB251XB_DEF_MAX_CURRENT_SELF;
hub->max_current_bp = USB251XB_DEF_MAX_CURRENT_BUS;
hub->bat_charge_en = USB251XB_DEF_BATTERY_CHARGING_ENABLE;
hub->boost_up = USB251XB_DEF_BOOST_UP;
hub->boost_x = USB251XB_DEF_BOOST_X;
hub->port_swap = USB251XB_DEF_PORT_SWAP;
hub->port_map12 = USB251XB_DEF_PORT_MAP_12;
hub->port_map34 = USB251XB_DEF_PORT_MAP_34;
return 0;
}
static int usb251xb_get_ofdata(struct usb251xb *hub,
struct usb251xb_data *data)
{
return 0;
}
static int usb251xb_probe(struct usb251xb *hub)
{
struct device *dev = hub->dev;
struct device_node *np = dev->of_node;
const struct of_device_id *of_id = of_match_device(usb251xb_of_match,
dev);
int err;
if (np) {
err = usb251xb_get_ofdata(hub,
(struct usb251xb_data *)of_id->data);
if (err) {
dev_err(dev, "failed to get ofdata: %d\n", err);
return err;
}
}
err = usb251xb_connect(hub);
if (err) {
dev_err(dev, "Failed to connect hub (%d)\n", err);
return err;
}
dev_info(dev, "Hub probed successfully\n");
return 0;
}
static int usb251xb_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct usb251xb *hub;
hub = devm_kzalloc(&i2c->dev, sizeof(struct usb251xb), GFP_KERNEL);
if (!hub)
return -ENOMEM;
i2c_set_clientdata(i2c, hub);
hub->dev = &i2c->dev;
hub->i2c = i2c;
return usb251xb_probe(hub);
}
