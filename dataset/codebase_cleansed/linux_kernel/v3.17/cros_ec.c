int cros_ec_prepare_tx(struct cros_ec_device *ec_dev,
struct cros_ec_command *msg)
{
uint8_t *out;
int csum, i;
BUG_ON(msg->outsize > EC_PROTO2_MAX_PARAM_SIZE);
out = ec_dev->dout;
out[0] = EC_CMD_VERSION0 + msg->version;
out[1] = msg->command;
out[2] = msg->outsize;
csum = out[0] + out[1] + out[2];
for (i = 0; i < msg->outsize; i++)
csum += out[EC_MSG_TX_HEADER_BYTES + i] = msg->outdata[i];
out[EC_MSG_TX_HEADER_BYTES + msg->outsize] = (uint8_t)(csum & 0xff);
return EC_MSG_TX_PROTO_BYTES + msg->outsize;
}
int cros_ec_check_result(struct cros_ec_device *ec_dev,
struct cros_ec_command *msg)
{
switch (msg->result) {
case EC_RES_SUCCESS:
return 0;
case EC_RES_IN_PROGRESS:
dev_dbg(ec_dev->dev, "command 0x%02x in progress\n",
msg->command);
return -EAGAIN;
default:
dev_dbg(ec_dev->dev, "command 0x%02x returned %d\n",
msg->command, msg->result);
return 0;
}
}
int cros_ec_register(struct cros_ec_device *ec_dev)
{
struct device *dev = ec_dev->dev;
int err = 0;
if (ec_dev->din_size) {
ec_dev->din = devm_kzalloc(dev, ec_dev->din_size, GFP_KERNEL);
if (!ec_dev->din)
return -ENOMEM;
}
if (ec_dev->dout_size) {
ec_dev->dout = devm_kzalloc(dev, ec_dev->dout_size, GFP_KERNEL);
if (!ec_dev->dout)
return -ENOMEM;
}
err = mfd_add_devices(dev, 0, cros_devs,
ARRAY_SIZE(cros_devs),
NULL, ec_dev->irq, NULL);
if (err) {
dev_err(dev, "failed to add mfd devices\n");
return err;
}
dev_info(dev, "Chrome EC device registered\n");
return 0;
}
int cros_ec_remove(struct cros_ec_device *ec_dev)
{
mfd_remove_devices(ec_dev->dev);
return 0;
}
int cros_ec_suspend(struct cros_ec_device *ec_dev)
{
struct device *dev = ec_dev->dev;
if (device_may_wakeup(dev))
ec_dev->wake_enabled = !enable_irq_wake(ec_dev->irq);
disable_irq(ec_dev->irq);
ec_dev->was_wake_device = ec_dev->wake_enabled;
return 0;
}
int cros_ec_resume(struct cros_ec_device *ec_dev)
{
enable_irq(ec_dev->irq);
if (ec_dev->wake_enabled) {
disable_irq_wake(ec_dev->irq);
ec_dev->wake_enabled = 0;
}
return 0;
}
