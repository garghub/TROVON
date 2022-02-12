static int hts221_i2c_read(struct device *dev, u8 addr, int len, u8 *data)
{
struct i2c_msg msg[2];
struct i2c_client *client = to_i2c_client(dev);
if (len > 1)
addr |= I2C_AUTO_INCREMENT;
msg[0].addr = client->addr;
msg[0].flags = client->flags;
msg[0].len = 1;
msg[0].buf = &addr;
msg[1].addr = client->addr;
msg[1].flags = client->flags | I2C_M_RD;
msg[1].len = len;
msg[1].buf = data;
return i2c_transfer(client->adapter, msg, 2);
}
static int hts221_i2c_write(struct device *dev, u8 addr, int len, u8 *data)
{
u8 send[len + 1];
struct i2c_msg msg;
struct i2c_client *client = to_i2c_client(dev);
if (len > 1)
addr |= I2C_AUTO_INCREMENT;
send[0] = addr;
memcpy(&send[1], data, len * sizeof(u8));
msg.addr = client->addr;
msg.flags = client->flags;
msg.len = len + 1;
msg.buf = send;
return i2c_transfer(client->adapter, &msg, 1);
}
static int hts221_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct hts221_hw *hw;
struct iio_dev *iio_dev;
iio_dev = devm_iio_device_alloc(&client->dev, sizeof(*hw));
if (!iio_dev)
return -ENOMEM;
i2c_set_clientdata(client, iio_dev);
hw = iio_priv(iio_dev);
hw->name = client->name;
hw->dev = &client->dev;
hw->irq = client->irq;
hw->tf = &hts221_transfer_fn;
return hts221_probe(iio_dev);
}
