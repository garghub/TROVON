static irqreturn_t bq27xxx_battery_irq_handler_thread(int irq, void *data)
{
struct bq27xxx_device_info *di = data;
bq27xxx_battery_update(di);
return IRQ_HANDLED;
}
static int bq27xxx_battery_i2c_read(struct bq27xxx_device_info *di, u8 reg,
bool single)
{
struct i2c_client *client = to_i2c_client(di->dev);
struct i2c_msg msg[2];
u8 data[2];
int ret;
if (!client->adapter)
return -ENODEV;
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].buf = &reg;
msg[0].len = sizeof(reg);
msg[1].addr = client->addr;
msg[1].flags = I2C_M_RD;
msg[1].buf = data;
if (single)
msg[1].len = 1;
else
msg[1].len = 2;
ret = i2c_transfer(client->adapter, msg, ARRAY_SIZE(msg));
if (ret < 0)
return ret;
if (!single)
ret = get_unaligned_le16(data);
else
ret = data[0];
return ret;
}
static int bq27xxx_battery_i2c_write(struct bq27xxx_device_info *di, u8 reg,
int value, bool single)
{
struct i2c_client *client = to_i2c_client(di->dev);
struct i2c_msg msg;
u8 data[4];
int ret;
if (!client->adapter)
return -ENODEV;
data[0] = reg;
if (single) {
data[1] = (u8) value;
msg.len = 2;
} else {
put_unaligned_le16(value, &data[1]);
msg.len = 3;
}
msg.buf = data;
msg.addr = client->addr;
msg.flags = 0;
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret < 0)
return ret;
if (ret != 1)
return -EINVAL;
return 0;
}
static int bq27xxx_battery_i2c_bulk_read(struct bq27xxx_device_info *di, u8 reg,
u8 *data, int len)
{
struct i2c_client *client = to_i2c_client(di->dev);
int ret;
if (!client->adapter)
return -ENODEV;
ret = i2c_smbus_read_i2c_block_data(client, reg, len, data);
if (ret < 0)
return ret;
if (ret != len)
return -EINVAL;
return 0;
}
static int bq27xxx_battery_i2c_bulk_write(struct bq27xxx_device_info *di,
u8 reg, u8 *data, int len)
{
struct i2c_client *client = to_i2c_client(di->dev);
struct i2c_msg msg;
u8 buf[33];
int ret;
if (!client->adapter)
return -ENODEV;
buf[0] = reg;
memcpy(&buf[1], data, len);
msg.buf = buf;
msg.addr = client->addr;
msg.flags = 0;
msg.len = len + 1;
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret < 0)
return ret;
if (ret != 1)
return -EINVAL;
return 0;
}
static int bq27xxx_battery_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bq27xxx_device_info *di;
int ret;
char *name;
int num;
mutex_lock(&battery_mutex);
num = idr_alloc(&battery_id, client, 0, 0, GFP_KERNEL);
mutex_unlock(&battery_mutex);
if (num < 0)
return num;
name = devm_kasprintf(&client->dev, GFP_KERNEL, "%s-%d", id->name, num);
if (!name)
goto err_mem;
di = devm_kzalloc(&client->dev, sizeof(*di), GFP_KERNEL);
if (!di)
goto err_mem;
di->id = num;
di->dev = &client->dev;
di->chip = id->driver_data;
di->name = name;
di->bus.read = bq27xxx_battery_i2c_read;
di->bus.write = bq27xxx_battery_i2c_write;
di->bus.read_bulk = bq27xxx_battery_i2c_bulk_read;
di->bus.write_bulk = bq27xxx_battery_i2c_bulk_write;
ret = bq27xxx_battery_setup(di);
if (ret)
goto err_failed;
schedule_delayed_work(&di->work, 60 * HZ);
i2c_set_clientdata(client, di);
if (client->irq) {
ret = devm_request_threaded_irq(&client->dev, client->irq,
NULL, bq27xxx_battery_irq_handler_thread,
IRQF_ONESHOT,
di->name, di);
if (ret) {
dev_err(&client->dev,
"Unable to register IRQ %d error %d\n",
client->irq, ret);
return ret;
}
}
return 0;
err_mem:
ret = -ENOMEM;
err_failed:
mutex_lock(&battery_mutex);
idr_remove(&battery_id, num);
mutex_unlock(&battery_mutex);
return ret;
}
static int bq27xxx_battery_i2c_remove(struct i2c_client *client)
{
struct bq27xxx_device_info *di = i2c_get_clientdata(client);
bq27xxx_battery_teardown(di);
mutex_lock(&battery_mutex);
idr_remove(&battery_id, di->id);
mutex_unlock(&battery_mutex);
return 0;
}
