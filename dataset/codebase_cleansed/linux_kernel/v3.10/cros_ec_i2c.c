static inline struct cros_ec_device *to_ec_dev(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
return i2c_get_clientdata(client);
}
static int cros_ec_command_xfer(struct cros_ec_device *ec_dev,
struct cros_ec_msg *msg)
{
struct i2c_client *client = ec_dev->priv;
int ret = -ENOMEM;
int i;
int packet_len;
u8 *out_buf = NULL;
u8 *in_buf = NULL;
u8 sum;
struct i2c_msg i2c_msg[2];
i2c_msg[0].addr = client->addr;
i2c_msg[0].flags = 0;
i2c_msg[1].addr = client->addr;
i2c_msg[1].flags = I2C_M_RD;
packet_len = msg->in_len + 3;
in_buf = kzalloc(packet_len, GFP_KERNEL);
if (!in_buf)
goto done;
i2c_msg[1].len = packet_len;
i2c_msg[1].buf = (char *)in_buf;
packet_len = msg->out_len + 4;
out_buf = kzalloc(packet_len, GFP_KERNEL);
if (!out_buf)
goto done;
i2c_msg[0].len = packet_len;
i2c_msg[0].buf = (char *)out_buf;
out_buf[0] = EC_CMD_VERSION0 + msg->version;
out_buf[1] = msg->cmd;
out_buf[2] = msg->out_len;
sum = out_buf[0] + out_buf[1] + out_buf[2];
for (i = 0; i < msg->out_len; i++) {
out_buf[3 + i] = msg->out_buf[i];
sum += out_buf[3 + i];
}
out_buf[3 + msg->out_len] = sum;
ret = i2c_transfer(client->adapter, i2c_msg, 2);
if (ret < 0) {
dev_err(ec_dev->dev, "i2c transfer failed: %d\n", ret);
goto done;
} else if (ret != 2) {
dev_err(ec_dev->dev, "failed to get response: %d\n", ret);
ret = -EIO;
goto done;
}
if (i2c_msg[1].buf[0]) {
dev_warn(ec_dev->dev, "command 0x%02x returned an error %d\n",
msg->cmd, i2c_msg[1].buf[0]);
ret = -EINVAL;
goto done;
}
sum = in_buf[0] + in_buf[1];
for (i = 0; i < msg->in_len; i++) {
msg->in_buf[i] = in_buf[2 + i];
sum += in_buf[2 + i];
}
dev_dbg(ec_dev->dev, "packet: %*ph, sum = %02x\n",
i2c_msg[1].len, in_buf, sum);
if (sum != in_buf[2 + msg->in_len]) {
dev_err(ec_dev->dev, "bad packet checksum\n");
ret = -EBADMSG;
goto done;
}
ret = 0;
done:
kfree(in_buf);
kfree(out_buf);
return ret;
}
static int cros_ec_probe_i2c(struct i2c_client *client,
const struct i2c_device_id *dev_id)
{
struct device *dev = &client->dev;
struct cros_ec_device *ec_dev = NULL;
int err;
ec_dev = devm_kzalloc(dev, sizeof(*ec_dev), GFP_KERNEL);
if (!ec_dev)
return -ENOMEM;
i2c_set_clientdata(client, ec_dev);
ec_dev->name = "I2C";
ec_dev->dev = dev;
ec_dev->priv = client;
ec_dev->irq = client->irq;
ec_dev->command_xfer = cros_ec_command_xfer;
ec_dev->ec_name = client->name;
ec_dev->phys_name = client->adapter->name;
ec_dev->parent = &client->dev;
err = cros_ec_register(ec_dev);
if (err) {
dev_err(dev, "cannot register EC\n");
return err;
}
return 0;
}
static int cros_ec_remove_i2c(struct i2c_client *client)
{
struct cros_ec_device *ec_dev = i2c_get_clientdata(client);
cros_ec_remove(ec_dev);
return 0;
}
static int cros_ec_i2c_suspend(struct device *dev)
{
struct cros_ec_device *ec_dev = to_ec_dev(dev);
return cros_ec_suspend(ec_dev);
}
static int cros_ec_i2c_resume(struct device *dev)
{
struct cros_ec_device *ec_dev = to_ec_dev(dev);
return cros_ec_resume(ec_dev);
}
