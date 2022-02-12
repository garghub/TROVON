static int st_lsm6dsx_i2c_read(struct device *dev, u8 addr, int len, u8 *data)
{
struct i2c_client *client = to_i2c_client(dev);
struct i2c_msg msg[2];
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
static int st_lsm6dsx_i2c_write(struct device *dev, u8 addr, int len, u8 *data)
{
struct i2c_client *client = to_i2c_client(dev);
struct i2c_msg msg;
u8 send[len + 1];
send[0] = addr;
memcpy(&send[1], data, len * sizeof(u8));
msg.addr = client->addr;
msg.flags = client->flags;
msg.len = len + 1;
msg.buf = send;
return i2c_transfer(client->adapter, &msg, 1);
}
static int st_lsm6dsx_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return st_lsm6dsx_probe(&client->dev, client->irq,
(int)id->driver_data,
&st_lsm6dsx_transfer_fn);
}
