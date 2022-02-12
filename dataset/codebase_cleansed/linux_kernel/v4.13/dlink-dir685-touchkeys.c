static irqreturn_t dir685_tk_irq_thread(int irq, void *data)
{
struct dir685_touchkeys *tk = data;
const int num_bits = min_t(int, ARRAY_SIZE(tk->codes), 16);
unsigned long changed;
u8 buf[6];
unsigned long key;
int i;
int err;
memset(buf, 0, sizeof(buf));
err = i2c_master_recv(tk->client, buf, sizeof(buf));
if (err != sizeof(buf)) {
dev_err(tk->dev, "short read %d\n", err);
return IRQ_HANDLED;
}
dev_dbg(tk->dev, "IN: %*ph\n", (int)sizeof(buf), buf);
key = be16_to_cpup((__be16 *) &buf[4]);
changed = tk->cur_key ^ key;
for_each_set_bit(i, &changed, num_bits) {
dev_dbg(tk->dev, "key %d is %s\n", i,
test_bit(i, &key) ? "down" : "up");
input_report_key(tk->input, tk->codes[i], test_bit(i, &key));
}
tk->cur_key = key;
input_sync(tk->input);
return IRQ_HANDLED;
}
static int dir685_tk_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct dir685_touchkeys *tk;
struct device *dev = &client->dev;
u8 bl_data[] = { 0xa7, 0x40 };
int err;
int i;
tk = devm_kzalloc(&client->dev, sizeof(*tk), GFP_KERNEL);
if (!tk)
return -ENOMEM;
tk->input = devm_input_allocate_device(dev);
if (!tk->input)
return -ENOMEM;
tk->client = client;
tk->dev = dev;
tk->input->keycodesize = sizeof(u16);
tk->input->keycodemax = ARRAY_SIZE(tk->codes);
tk->input->keycode = tk->codes;
tk->codes[0] = KEY_UP;
tk->codes[1] = KEY_DOWN;
tk->codes[2] = KEY_LEFT;
tk->codes[3] = KEY_RIGHT;
tk->codes[4] = KEY_ENTER;
tk->codes[5] = KEY_WPS_BUTTON;
tk->codes[6] = KEY_RESERVED;
__set_bit(EV_KEY, tk->input->evbit);
for (i = 0; i < ARRAY_SIZE(tk->codes); i++)
__set_bit(tk->codes[i], tk->input->keybit);
__clear_bit(KEY_RESERVED, tk->input->keybit);
tk->input->name = "D-Link DIR-685 touchkeys";
tk->input->id.bustype = BUS_I2C;
err = input_register_device(tk->input);
if (err)
return err;
err = i2c_master_send(client, bl_data, sizeof(bl_data));
if (err != sizeof(bl_data))
dev_warn(tk->dev, "error setting brightness level\n");
if (!client->irq) {
dev_err(dev, "no IRQ on the I2C device\n");
return -ENODEV;
}
err = devm_request_threaded_irq(dev, client->irq,
NULL, dir685_tk_irq_thread,
IRQF_ONESHOT,
"dir685-tk", tk);
if (err) {
dev_err(dev, "can't request IRQ\n");
return err;
}
return 0;
}
