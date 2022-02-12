static int ec_i2c_count_message(const struct i2c_msg i2c_msgs[], int num)
{
int i;
int size;
size = sizeof(struct ec_params_i2c_passthru);
size += num * sizeof(struct ec_params_i2c_passthru_msg);
for (i = 0; i < num; i++)
if (!(i2c_msgs[i].flags & I2C_M_RD))
size += i2c_msgs[i].len;
return size;
}
static int ec_i2c_construct_message(u8 *buf, const struct i2c_msg i2c_msgs[],
int num, u16 bus_num)
{
struct ec_params_i2c_passthru *params;
u8 *out_data;
int i;
out_data = buf + sizeof(struct ec_params_i2c_passthru) +
num * sizeof(struct ec_params_i2c_passthru_msg);
params = (struct ec_params_i2c_passthru *)buf;
params->port = bus_num;
params->num_msgs = num;
for (i = 0; i < num; i++) {
const struct i2c_msg *i2c_msg = &i2c_msgs[i];
struct ec_params_i2c_passthru_msg *msg = &params->msg[i];
msg->len = i2c_msg->len;
msg->addr_flags = i2c_msg->addr;
if (i2c_msg->flags & I2C_M_TEN)
return -EINVAL;
if (i2c_msg->flags & I2C_M_RD) {
msg->addr_flags |= EC_I2C_FLAG_READ;
} else {
memcpy(out_data, i2c_msg->buf, msg->len);
out_data += msg->len;
}
}
return 0;
}
static int ec_i2c_count_response(struct i2c_msg i2c_msgs[], int num)
{
int size;
int i;
size = sizeof(struct ec_response_i2c_passthru);
for (i = 0; i < num; i++)
if (i2c_msgs[i].flags & I2C_M_RD)
size += i2c_msgs[i].len;
return size;
}
static int ec_i2c_parse_response(const u8 *buf, struct i2c_msg i2c_msgs[],
int *num)
{
const struct ec_response_i2c_passthru *resp;
const u8 *in_data;
int i;
in_data = buf + sizeof(struct ec_response_i2c_passthru);
resp = (const struct ec_response_i2c_passthru *)buf;
if (resp->i2c_status & EC_I2C_STATUS_TIMEOUT)
return -ETIMEDOUT;
else if (resp->i2c_status & EC_I2C_STATUS_ERROR)
return -EREMOTEIO;
if (resp->num_msgs > *num)
return -EPROTO;
*num = resp->num_msgs;
for (i = 0; i < *num; i++) {
struct i2c_msg *i2c_msg = &i2c_msgs[i];
if (i2c_msgs[i].flags & I2C_M_RD) {
memcpy(i2c_msg->buf, in_data, i2c_msg->len);
in_data += i2c_msg->len;
}
}
return 0;
}
static int ec_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg i2c_msgs[],
int num)
{
struct ec_i2c_device *bus = adap->algo_data;
struct device *dev = bus->dev;
const u16 bus_num = bus->remote_bus;
int request_len;
int response_len;
int result;
struct cros_ec_command msg = { };
request_len = ec_i2c_count_message(i2c_msgs, num);
if (request_len < 0) {
dev_warn(dev, "Error constructing message %d\n", request_len);
return request_len;
}
response_len = ec_i2c_count_response(i2c_msgs, num);
if (response_len < 0) {
dev_warn(dev, "Error preparing response %d\n", response_len);
return response_len;
}
result = ec_i2c_construct_message(msg.outdata, i2c_msgs, num, bus_num);
if (result)
return result;
msg.version = 0;
msg.command = EC_CMD_I2C_PASSTHRU;
msg.outsize = request_len;
msg.insize = response_len;
result = cros_ec_cmd_xfer(bus->ec, &msg);
if (result < 0)
return result;
result = ec_i2c_parse_response(msg.indata, i2c_msgs, &num);
if (result < 0)
return result;
return num;
}
static u32 ec_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int ec_i2c_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct cros_ec_device *ec = dev_get_drvdata(pdev->dev.parent);
struct device *dev = &pdev->dev;
struct ec_i2c_device *bus = NULL;
u32 remote_bus;
int err;
if (!ec->cmd_xfer) {
dev_err(dev, "Missing sendrecv\n");
return -EINVAL;
}
bus = devm_kzalloc(dev, sizeof(*bus), GFP_KERNEL);
if (bus == NULL)
return -ENOMEM;
err = of_property_read_u32(np, "google,remote-bus", &remote_bus);
if (err) {
dev_err(dev, "Couldn't read remote-bus property\n");
return err;
}
bus->remote_bus = remote_bus;
bus->ec = ec;
bus->dev = dev;
bus->adap.owner = THIS_MODULE;
strlcpy(bus->adap.name, "cros-ec-i2c-tunnel", sizeof(bus->adap.name));
bus->adap.algo = &ec_i2c_algorithm;
bus->adap.algo_data = bus;
bus->adap.dev.parent = &pdev->dev;
bus->adap.dev.of_node = np;
bus->adap.retries = I2C_MAX_RETRIES;
err = i2c_add_adapter(&bus->adap);
if (err) {
dev_err(dev, "cannot register i2c adapter\n");
return err;
}
platform_set_drvdata(pdev, bus);
return err;
}
static int ec_i2c_remove(struct platform_device *dev)
{
struct ec_i2c_device *bus = platform_get_drvdata(dev);
i2c_del_adapter(&bus->adap);
return 0;
}
