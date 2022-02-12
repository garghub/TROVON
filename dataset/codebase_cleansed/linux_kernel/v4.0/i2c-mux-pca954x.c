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
ret = adap->algo->master_xfer(adap, &msg, 1);
} else {
union i2c_smbus_data data;
ret = adap->algo->smbus_xfer(adap, client->addr,
client->flags,
I2C_SMBUS_WRITE,
val, I2C_SMBUS_BYTE, &data);
}
return ret;
}
static int pca954x_select_chan(struct i2c_adapter *adap,
void *client, u32 chan)
{
struct pca954x *data = i2c_get_clientdata(client);
const struct chip_desc *chip = &chips[data->type];
u8 regval;
int ret = 0;
if (chip->muxtype == pca954x_ismux)
regval = chan | chip->enable;
else
regval = 1 << chan;
if (data->last_chan != regval) {
ret = pca954x_reg_write(adap, client, regval);
data->last_chan = regval;
}
return ret;
}
static int pca954x_deselect_mux(struct i2c_adapter *adap,
void *client, u32 chan)
{
struct pca954x *data = i2c_get_clientdata(client);
data->last_chan = 0;
return pca954x_reg_write(adap, client, data->last_chan);
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
struct pca954x *data;
int ret;
if (!i2c_check_functionality(adap, I2C_FUNC_SMBUS_BYTE))
return -ENODEV;
data = devm_kzalloc(&client->dev, sizeof(struct pca954x), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
gpio = devm_gpiod_get(&client->dev, "reset");
if (!IS_ERR(gpio))
gpiod_direction_output(gpio, 0);
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
}
data->virt_adaps[num] =
i2c_add_mux_adapter(adap, &client->dev, client,
force, num, class, pca954x_select_chan,
(idle_disconnect_pd || idle_disconnect_dt)
? pca954x_deselect_mux : NULL);
if (data->virt_adaps[num] == NULL) {
ret = -ENODEV;
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
for (num--; num >= 0; num--)
i2c_del_mux_adapter(data->virt_adaps[num]);
return ret;
}
static int pca954x_remove(struct i2c_client *client)
{
struct pca954x *data = i2c_get_clientdata(client);
const struct chip_desc *chip = &chips[data->type];
int i;
for (i = 0; i < chip->nchans; ++i)
if (data->virt_adaps[i]) {
i2c_del_mux_adapter(data->virt_adaps[i]);
data->virt_adaps[i] = NULL;
}
return 0;
}
static int pca954x_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct pca954x *data = i2c_get_clientdata(client);
data->last_chan = 0;
return i2c_smbus_write_byte(client, 0);
}
