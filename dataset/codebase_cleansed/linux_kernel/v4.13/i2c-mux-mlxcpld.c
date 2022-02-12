static int mlxcpld_mux_reg_write(struct i2c_adapter *adap,
struct i2c_client *client, u8 val)
{
struct mlxcpld_mux_plat_data *pdata = dev_get_platdata(&client->dev);
int ret = -ENODEV;
if (adap->algo->master_xfer) {
struct i2c_msg msg;
u8 msgbuf[] = {pdata->sel_reg_addr, val};
msg.addr = client->addr;
msg.flags = 0;
msg.len = 2;
msg.buf = msgbuf;
ret = __i2c_transfer(adap, &msg, 1);
if (ret >= 0 && ret != 1)
ret = -EREMOTEIO;
} else if (adap->algo->smbus_xfer) {
union i2c_smbus_data data;
data.byte = val;
ret = adap->algo->smbus_xfer(adap, client->addr,
client->flags, I2C_SMBUS_WRITE,
pdata->sel_reg_addr,
I2C_SMBUS_BYTE_DATA, &data);
}
return ret;
}
static int mlxcpld_mux_select_chan(struct i2c_mux_core *muxc, u32 chan)
{
struct mlxcpld_mux *data = i2c_mux_priv(muxc);
struct i2c_client *client = data->client;
u8 regval = chan + 1;
int err = 0;
if (data->last_chan != regval) {
err = mlxcpld_mux_reg_write(muxc->parent, client, regval);
data->last_chan = err < 0 ? 0 : regval;
}
return err;
}
static int mlxcpld_mux_deselect(struct i2c_mux_core *muxc, u32 chan)
{
struct mlxcpld_mux *data = i2c_mux_priv(muxc);
struct i2c_client *client = data->client;
data->last_chan = 0;
return mlxcpld_mux_reg_write(muxc->parent, client, data->last_chan);
}
static int mlxcpld_mux_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adap = to_i2c_adapter(client->dev.parent);
struct mlxcpld_mux_plat_data *pdata = dev_get_platdata(&client->dev);
struct i2c_mux_core *muxc;
int num, force;
struct mlxcpld_mux *data;
int err;
if (!pdata)
return -EINVAL;
if (!i2c_check_functionality(adap, I2C_FUNC_SMBUS_WRITE_BYTE_DATA))
return -ENODEV;
muxc = i2c_mux_alloc(adap, &client->dev, CPLD_MUX_MAX_NCHANS,
sizeof(*data), 0, mlxcpld_mux_select_chan,
mlxcpld_mux_deselect);
if (!muxc)
return -ENOMEM;
data = i2c_mux_priv(muxc);
i2c_set_clientdata(client, muxc);
data->client = client;
data->last_chan = 0;
for (num = 0; num < CPLD_MUX_MAX_NCHANS; num++) {
if (num >= pdata->num_adaps)
break;
force = pdata->adap_ids[num];
err = i2c_mux_add_adapter(muxc, force, num, 0);
if (err)
goto virt_reg_failed;
}
return 0;
virt_reg_failed:
i2c_mux_del_adapters(muxc);
return err;
}
static int mlxcpld_mux_remove(struct i2c_client *client)
{
struct i2c_mux_core *muxc = i2c_get_clientdata(client);
i2c_mux_del_adapters(muxc);
return 0;
}
