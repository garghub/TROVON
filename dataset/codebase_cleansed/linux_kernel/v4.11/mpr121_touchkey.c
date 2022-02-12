static void mpr121_vdd_supply_disable(void *data)
{
struct regulator *vdd_supply = data;
regulator_disable(vdd_supply);
}
static struct regulator *mpr121_vdd_supply_init(struct device *dev)
{
struct regulator *vdd_supply;
int err;
vdd_supply = devm_regulator_get(dev, "vdd");
if (IS_ERR(vdd_supply)) {
dev_err(dev, "failed to get vdd regulator: %ld\n",
PTR_ERR(vdd_supply));
return vdd_supply;
}
err = regulator_enable(vdd_supply);
if (err) {
dev_err(dev, "failed to enable vdd regulator: %d\n", err);
return ERR_PTR(err);
}
err = devm_add_action(dev, mpr121_vdd_supply_disable, vdd_supply);
if (err) {
regulator_disable(vdd_supply);
dev_err(dev, "failed to add disable regulator action: %d\n",
err);
return ERR_PTR(err);
}
return vdd_supply;
}
static irqreturn_t mpr_touchkey_interrupt(int irq, void *dev_id)
{
struct mpr121_touchkey *mpr121 = dev_id;
struct i2c_client *client = mpr121->client;
struct input_dev *input = mpr121->input_dev;
unsigned long bit_changed;
unsigned int key_num;
int reg;
reg = i2c_smbus_read_byte_data(client, ELE_TOUCH_STATUS_1_ADDR);
if (reg < 0) {
dev_err(&client->dev, "i2c read error [%d]\n", reg);
goto out;
}
reg <<= 8;
reg |= i2c_smbus_read_byte_data(client, ELE_TOUCH_STATUS_0_ADDR);
if (reg < 0) {
dev_err(&client->dev, "i2c read error [%d]\n", reg);
goto out;
}
reg &= TOUCH_STATUS_MASK;
bit_changed = reg ^ mpr121->statusbits;
mpr121->statusbits = reg;
for_each_set_bit(key_num, &bit_changed, mpr121->keycount) {
unsigned int key_val, pressed;
pressed = reg & BIT(key_num);
key_val = mpr121->keycodes[key_num];
input_event(input, EV_MSC, MSC_SCAN, key_num);
input_report_key(input, key_val, pressed);
dev_dbg(&client->dev, "key %d %d %s\n", key_num, key_val,
pressed ? "pressed" : "released");
}
input_sync(input);
out:
return IRQ_HANDLED;
}
static int mpr121_phys_init(struct mpr121_touchkey *mpr121,
struct i2c_client *client, int vdd_uv)
{
const struct mpr121_init_register *reg;
unsigned char usl, lsl, tl, eleconf;
int i, t, vdd, ret;
for (i = 0; i <= MPR121_MAX_KEY_COUNT; i++) {
t = ELE0_TOUCH_THRESHOLD_ADDR + (i * 2);
ret = i2c_smbus_write_byte_data(client, t, TOUCH_THRESHOLD);
if (ret < 0)
goto err_i2c_write;
ret = i2c_smbus_write_byte_data(client, t + 1,
RELEASE_THRESHOLD);
if (ret < 0)
goto err_i2c_write;
}
for (i = 0; i < ARRAY_SIZE(init_reg_table); i++) {
reg = &init_reg_table[i];
ret = i2c_smbus_write_byte_data(client, reg->addr, reg->val);
if (ret < 0)
goto err_i2c_write;
}
vdd = vdd_uv / 1000;
usl = ((vdd - 700) * 256) / vdd;
lsl = (usl * 65) / 100;
tl = (usl * 90) / 100;
ret = i2c_smbus_write_byte_data(client, AUTO_CONFIG_USL_ADDR, usl);
ret |= i2c_smbus_write_byte_data(client, AUTO_CONFIG_LSL_ADDR, lsl);
ret |= i2c_smbus_write_byte_data(client, AUTO_CONFIG_TL_ADDR, tl);
eleconf = mpr121->keycount | ELECTRODE_CONF_QUICK_CHARGE;
ret |= i2c_smbus_write_byte_data(client, ELECTRODE_CONF_ADDR,
eleconf);
if (ret != 0)
goto err_i2c_write;
dev_dbg(&client->dev, "set up with %x keys.\n", mpr121->keycount);
return 0;
err_i2c_write:
dev_err(&client->dev, "i2c write error: %d\n", ret);
return ret;
}
static int mpr_touchkey_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct regulator *vdd_supply;
int vdd_uv;
struct mpr121_touchkey *mpr121;
struct input_dev *input_dev;
int error;
int i;
if (!client->irq) {
dev_err(dev, "irq number should not be zero\n");
return -EINVAL;
}
vdd_supply = mpr121_vdd_supply_init(dev);
if (IS_ERR(vdd_supply))
return PTR_ERR(vdd_supply);
vdd_uv = regulator_get_voltage(vdd_supply);
mpr121 = devm_kzalloc(dev, sizeof(*mpr121), GFP_KERNEL);
if (!mpr121)
return -ENOMEM;
input_dev = devm_input_allocate_device(dev);
if (!input_dev)
return -ENOMEM;
mpr121->client = client;
mpr121->input_dev = input_dev;
mpr121->keycount = device_property_read_u32_array(dev, "linux,keycodes",
NULL, 0);
if (mpr121->keycount > MPR121_MAX_KEY_COUNT) {
dev_err(dev, "too many keys defined (%d)\n", mpr121->keycount);
return -EINVAL;
}
error = device_property_read_u32_array(dev, "linux,keycodes",
mpr121->keycodes,
mpr121->keycount);
if (error) {
dev_err(dev,
"failed to read linux,keycode property: %d\n", error);
return error;
}
input_dev->name = "Freescale MPR121 Touchkey";
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = dev;
if (device_property_read_bool(dev, "autorepeat"))
__set_bit(EV_REP, input_dev->evbit);
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
input_dev->keycode = mpr121->keycodes;
input_dev->keycodesize = sizeof(mpr121->keycodes[0]);
input_dev->keycodemax = mpr121->keycount;
for (i = 0; i < mpr121->keycount; i++)
input_set_capability(input_dev, EV_KEY, mpr121->keycodes[i]);
error = mpr121_phys_init(mpr121, client, vdd_uv);
if (error) {
dev_err(dev, "Failed to init register\n");
return error;
}
error = devm_request_threaded_irq(dev, client->irq, NULL,
mpr_touchkey_interrupt,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
dev->driver->name, mpr121);
if (error) {
dev_err(dev, "Failed to register interrupt\n");
return error;
}
error = input_register_device(input_dev);
if (error)
return error;
i2c_set_clientdata(client, mpr121);
device_init_wakeup(dev,
device_property_read_bool(dev, "wakeup-source"));
return 0;
}
static int __maybe_unused mpr_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
if (device_may_wakeup(&client->dev))
enable_irq_wake(client->irq);
i2c_smbus_write_byte_data(client, ELECTRODE_CONF_ADDR, 0x00);
return 0;
}
static int __maybe_unused mpr_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct mpr121_touchkey *mpr121 = i2c_get_clientdata(client);
if (device_may_wakeup(&client->dev))
disable_irq_wake(client->irq);
i2c_smbus_write_byte_data(client, ELECTRODE_CONF_ADDR,
mpr121->keycount);
return 0;
}
