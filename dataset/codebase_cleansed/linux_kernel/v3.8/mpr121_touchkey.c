static irqreturn_t mpr_touchkey_interrupt(int irq, void *dev_id)
{
struct mpr121_touchkey *mpr121 = dev_id;
struct i2c_client *client = mpr121->client;
struct input_dev *input = mpr121->input_dev;
unsigned int key_num, key_val, pressed;
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
key_num = ffs(reg ^ mpr121->statusbits) - 1;
pressed = reg & (1 << key_num);
mpr121->statusbits = reg;
key_val = mpr121->keycodes[key_num];
input_event(input, EV_MSC, MSC_SCAN, key_num);
input_report_key(input, key_val, pressed);
input_sync(input);
dev_dbg(&client->dev, "key %d %d %s\n", key_num, key_val,
pressed ? "pressed" : "released");
out:
return IRQ_HANDLED;
}
static int mpr121_phys_init(const struct mpr121_platform_data *pdata,
struct mpr121_touchkey *mpr121,
struct i2c_client *client)
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
vdd = pdata->vdd_uv / 1000;
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
const struct mpr121_platform_data *pdata = client->dev.platform_data;
struct mpr121_touchkey *mpr121;
struct input_dev *input_dev;
int error;
int i;
if (!pdata) {
dev_err(&client->dev, "no platform data defined\n");
return -EINVAL;
}
if (!pdata->keymap || !pdata->keymap_size) {
dev_err(&client->dev, "missing keymap data\n");
return -EINVAL;
}
if (pdata->keymap_size > MPR121_MAX_KEY_COUNT) {
dev_err(&client->dev, "too many keys defined\n");
return -EINVAL;
}
if (!client->irq) {
dev_err(&client->dev, "irq number should not be zero\n");
return -EINVAL;
}
mpr121 = kzalloc(sizeof(struct mpr121_touchkey), GFP_KERNEL);
input_dev = input_allocate_device();
if (!mpr121 || !input_dev) {
dev_err(&client->dev, "Failed to allocate memory\n");
error = -ENOMEM;
goto err_free_mem;
}
mpr121->client = client;
mpr121->input_dev = input_dev;
mpr121->keycount = pdata->keymap_size;
input_dev->name = "Freescale MPR121 Touchkey";
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = &client->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
input_dev->keycode = mpr121->keycodes;
input_dev->keycodesize = sizeof(mpr121->keycodes[0]);
input_dev->keycodemax = mpr121->keycount;
for (i = 0; i < pdata->keymap_size; i++) {
input_set_capability(input_dev, EV_KEY, pdata->keymap[i]);
mpr121->keycodes[i] = pdata->keymap[i];
}
error = mpr121_phys_init(pdata, mpr121, client);
if (error) {
dev_err(&client->dev, "Failed to init register\n");
goto err_free_mem;
}
error = request_threaded_irq(client->irq, NULL,
mpr_touchkey_interrupt,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
client->dev.driver->name, mpr121);
if (error) {
dev_err(&client->dev, "Failed to register interrupt\n");
goto err_free_mem;
}
error = input_register_device(input_dev);
if (error)
goto err_free_irq;
i2c_set_clientdata(client, mpr121);
device_init_wakeup(&client->dev, pdata->wakeup);
return 0;
err_free_irq:
free_irq(client->irq, mpr121);
err_free_mem:
input_free_device(input_dev);
kfree(mpr121);
return error;
}
static int mpr_touchkey_remove(struct i2c_client *client)
{
struct mpr121_touchkey *mpr121 = i2c_get_clientdata(client);
free_irq(client->irq, mpr121);
input_unregister_device(mpr121->input_dev);
kfree(mpr121);
return 0;
}
static int mpr_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
if (device_may_wakeup(&client->dev))
enable_irq_wake(client->irq);
i2c_smbus_write_byte_data(client, ELECTRODE_CONF_ADDR, 0x00);
return 0;
}
static int mpr_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct mpr121_touchkey *mpr121 = i2c_get_clientdata(client);
if (device_may_wakeup(&client->dev))
disable_irq_wake(client->irq);
i2c_smbus_write_byte_data(client, ELECTRODE_CONF_ADDR,
mpr121->keycount);
return 0;
}
