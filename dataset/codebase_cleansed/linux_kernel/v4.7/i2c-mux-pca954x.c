static int pca954x_reg_write(struct i2c_adapter *adap,
struct i2c_client *client, u8 val)
{
int ret = -ENODEV;
if (adap->algo->master_xfer) {
struct i2c_msg msg;
char buf[1];
msg.addr = client->addr;
msg.flags = 0;
msg.len = 1;
buf[0] = val;
msg.buf = buf;
ret = __i2c_transfer(adap, &msg, 1);
} else {
union i2c_smbus_data data;
ret = adap->algo->smbus_xfer(adap, client->addr,
client->flags,
I2C_SMBUS_WRITE,
val, I2C_SMBUS_BYTE, &data);
}
return ret;
}
static int pca954x_select_chan(struct i2c_mux_core *muxc, u32 chan)
{
struct pca954x *data = i2c_mux_priv(muxc);
struct i2c_client *client = data->client;
const struct chip_desc *chip = &chips[data->type];
u8 regval;
int ret = 0;
if (chip->muxtype == pca954x_ismux)
regval = chan | chip->enable;
else
regval = 1 << chan;
if (data->last_chan != regval) {
ret = pca954x_reg_write(muxc->parent, client, regval);
data->last_chan = regval;
}
return ret;
}
static int pca954x_deselect_mux(struct i2c_mux_core *muxc, u32 chan)
{
struct pca954x *data = i2c_mux_priv(muxc);
struct i2c_client *client = data->client;
if (!(data->deselect & (1 << chan)))
return 0;
data->last_chan = 0;
return pca954x_reg_write(muxc->parent, client, data->last_chan);
}
static int pca954x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adap = to_i2c_adapter(client->dev.parent);
struct pca954x_platform_data *pdata = dev_get_platdata(&client->dev);
struct device_node *of_node = client->dev.of_node;
bool idle_disconnect_dt;
struct gpio_desc *gpio;
int num, force, class;
struct i2c_mux_core *muxc;
struct pca954x *data;
int ret;
if (!i2c_check_functionality(adap, I2C_FUNC_SMBUS_BYTE))
return -ENODEV;
muxc = i2c_mux_alloc(adap, &client->dev,
PCA954X_MAX_NCHANS, sizeof(*data), 0,
pca954x_select_chan, pca954x_deselect_mux);
if (!muxc)
return -ENOMEM;
data = i2c_mux_priv(muxc);
i2c_set_clientdata(client, muxc);
data->client = client;
gpio = devm_gpiod_get_optional(&client->dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(gpio))
return PTR_ERR(gpio);
if (i2c_smbus_write_byte(client, 0) < 0) {
dev_warn(&client->dev, "probe failed\n");
return -ENODEV;
}
data->type = id->driver_data;
data->last_chan = 0;
idle_disconnect_dt = of_node &&
of_property_read_bool(of_node, "i2c-mux-idle-disconnect");
for (num = 0; num < chips[data->type].nchans; num++) {
bool idle_disconnect_pd = false;
force = 0;
class = 0;
if (pdata) {
if (num < pdata->num_modes) {
force = pdata->modes[num].adap_id;
class = pdata->modes[num].class;
} else
break;
idle_disconnect_pd = pdata->modes[num].deselect_on_exit;
data->deselect |= (idle_disconnect_pd
|| idle_disconnect_dt) << num;
}
ret = i2c_mux_add_adapter(muxc, force, num, class);
if (ret) {
dev_err(&client->dev,
"failed to register multiplexed adapter"
" %d as bus %d\n", num, force);
goto virt_reg_failed;
}
}
dev_info(&client->dev,
"registered %d multiplexed busses for I2C %s %s\n",
num, chips[data->type].muxtype == pca954x_ismux
? "mux" : "switch", client->name);
return 0;
virt_reg_failed:
i2c_mux_del_adapters(muxc);
return ret;
}
static int pca954x_remove(struct i2c_client *client)
{
struct i2c_mux_core *muxc = i2c_get_clientdata(client);
i2c_mux_del_adapters(muxc);
return 0;
}
static int pca954x_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct i2c_mux_core *muxc = i2c_get_clientdata(client);
struct pca954x *data = i2c_mux_priv(muxc);
data->last_chan = 0;
return i2c_smbus_write_byte(client, 0);
}
