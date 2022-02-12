static int atmel_read(struct atmel_captouch_device *capdev,
u8 reg, u8 *data, size_t len)
{
struct i2c_client *client = capdev->client;
struct device *dev = &client->dev;
struct i2c_msg msg[2];
int err;
if (len > sizeof(capdev->xfer_buf) - 2)
return -EINVAL;
capdev->xfer_buf[0] = reg;
capdev->xfer_buf[1] = len;
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].buf = capdev->xfer_buf;
msg[0].len = 2;
msg[1].addr = client->addr;
msg[1].flags = I2C_M_RD;
msg[1].buf = capdev->xfer_buf;
msg[1].len = len + 2;
err = i2c_transfer(client->adapter, msg, ARRAY_SIZE(msg));
if (err != ARRAY_SIZE(msg))
return err < 0 ? err : -EIO;
if (capdev->xfer_buf[0] != reg) {
dev_err(dev,
"I2C read error: register address does not match (%#02x vs %02x)\n",
capdev->xfer_buf[0], reg);
return -ECOMM;
}
memcpy(data, &capdev->xfer_buf[2], len);
return 0;
}
static irqreturn_t atmel_captouch_isr(int irq, void *data)
{
struct atmel_captouch_device *capdev = data;
struct device *dev = &capdev->client->dev;
int error;
int i;
u8 new_btn;
u8 changed_btn;
error = atmel_read(capdev, REG_KEY_STATE, &new_btn, 1);
if (error) {
dev_err(dev, "failed to read button state: %d\n", error);
goto out;
}
dev_dbg(dev, "%s: button state %#02x\n", __func__, new_btn);
changed_btn = new_btn ^ capdev->prev_btn;
capdev->prev_btn = new_btn;
for (i = 0; i < capdev->num_btn; i++) {
if (changed_btn & BIT(i))
input_report_key(capdev->input,
capdev->keycodes[i],
new_btn & BIT(i));
}
input_sync(capdev->input);
out:
return IRQ_HANDLED;
}
static int atmel_captouch_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct atmel_captouch_device *capdev;
struct device *dev = &client->dev;
struct device_node *node;
int i;
int err;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK)) {
dev_err(dev, "needed i2c functionality is not supported\n");
return -EINVAL;
}
capdev = devm_kzalloc(dev, sizeof(*capdev), GFP_KERNEL);
if (!capdev)
return -ENOMEM;
capdev->client = client;
err = atmel_read(capdev, REG_KEY_STATE,
&capdev->prev_btn, sizeof(capdev->prev_btn));
if (err) {
dev_err(dev, "failed to read initial button state: %d\n", err);
return err;
}
capdev->input = devm_input_allocate_device(dev);
if (!capdev->input) {
dev_err(dev, "failed to allocate input device\n");
return -ENOMEM;
}
capdev->input->id.bustype = BUS_I2C;
capdev->input->id.product = 0x880A;
capdev->input->id.version = 0;
capdev->input->name = "ATMegaXX Capacitive Button Controller";
__set_bit(EV_KEY, capdev->input->evbit);
node = dev->of_node;
if (!node) {
dev_err(dev, "failed to find matching node in device tree\n");
return -EINVAL;
}
if (of_property_read_bool(node, "autorepeat"))
__set_bit(EV_REP, capdev->input->evbit);
capdev->num_btn = of_property_count_u32_elems(node, "linux,keymap");
if (capdev->num_btn > MAX_NUM_OF_BUTTONS)
capdev->num_btn = MAX_NUM_OF_BUTTONS;
err = of_property_read_u32_array(node, "linux,keycodes",
capdev->keycodes,
capdev->num_btn);
if (err) {
dev_err(dev,
"failed to read linux,keycode property: %d\n", err);
return err;
}
for (i = 0; i < capdev->num_btn; i++)
__set_bit(capdev->keycodes[i], capdev->input->keybit);
capdev->input->keycode = capdev->keycodes;
capdev->input->keycodesize = sizeof(capdev->keycodes[0]);
capdev->input->keycodemax = capdev->num_btn;
err = input_register_device(capdev->input);
if (err)
return err;
err = devm_request_threaded_irq(dev, client->irq,
NULL, atmel_captouch_isr,
IRQF_ONESHOT,
"atmel_captouch", capdev);
if (err) {
dev_err(dev, "failed to request irq %d: %d\n",
client->irq, err);
return err;
}
return 0;
}
