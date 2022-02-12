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
struct pca954x_platform_data *pdata = client->dev.platform_data;
int num, force;
struct pca954x *data;
int ret = -ENODEV;
if (!i2c_check_functionality(adap, I2C_FUNC_SMBUS_BYTE))
goto err;
data = kzalloc(sizeof(struct pca954x), GFP_KERNEL);
if (!data) {
ret = -ENOMEM;
goto err;
}
i2c_set_clientdata(client, data);
if (i2c_smbus_write_byte(client, 0) < 0) {
dev_warn(&client->dev, "probe failed\n");
goto exit_free;
}
data->type = id->driver_data;
data->last_chan = 0;
for (num = 0; num < chips[data->type].nchans; num++) {
force = 0;
if (pdata) {
if (num < pdata->num_modes)
force = pdata->modes[num].adap_id;
else
break;
}
data->virt_adaps[num] =
i2c_add_mux_adapter(adap, client,
force, num, pca954x_select_chan,
(pdata && pdata->modes[num].deselect_on_exit)
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
exit_free:
kfree(data);
err:
return ret;
}
static int pca954x_remove(struct i2c_client *client)
{
struct pca954x *data = i2c_get_clientdata(client);
const struct chip_desc *chip = &chips[data->type];
int i, err;
for (i = 0; i < chip->nchans; ++i)
if (data->virt_adaps[i]) {
err = i2c_del_mux_adapter(data->virt_adaps[i]);
if (err)
return err;
data->virt_adaps[i] = NULL;
}
kfree(data);
return 0;
}
static int __init pca954x_init(void)
{
return i2c_add_driver(&pca954x_driver);
}
static void __exit pca954x_exit(void)
{
i2c_del_driver(&pca954x_driver);
}
