static int pca9541_reg_write(struct i2c_client *client, u8 command, u8 val)
{
struct i2c_adapter *adap = client->adapter;
int ret;
if (adap->algo->master_xfer) {
struct i2c_msg msg;
char buf[2];
msg.addr = client->addr;
msg.flags = 0;
msg.len = 2;
buf[0] = command;
buf[1] = val;
msg.buf = buf;
ret = __i2c_transfer(adap, &msg, 1);
} else {
union i2c_smbus_data data;
data.byte = val;
ret = adap->algo->smbus_xfer(adap, client->addr,
client->flags,
I2C_SMBUS_WRITE,
command,
I2C_SMBUS_BYTE_DATA, &data);
}
return ret;
}
static int pca9541_reg_read(struct i2c_client *client, u8 command)
{
struct i2c_adapter *adap = client->adapter;
int ret;
u8 val;
if (adap->algo->master_xfer) {
struct i2c_msg msg[2] = {
{
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = &command
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = 1,
.buf = &val
}
};
ret = __i2c_transfer(adap, msg, 2);
if (ret == 2)
ret = val;
else if (ret >= 0)
ret = -EIO;
} else {
union i2c_smbus_data data;
ret = adap->algo->smbus_xfer(adap, client->addr,
client->flags,
I2C_SMBUS_READ,
command,
I2C_SMBUS_BYTE_DATA, &data);
if (!ret)
ret = data.byte;
}
return ret;
}
static void pca9541_release_bus(struct i2c_client *client)
{
int reg;
reg = pca9541_reg_read(client, PCA9541_CONTROL);
if (reg >= 0 && !busoff(reg) && mybus(reg))
pca9541_reg_write(client, PCA9541_CONTROL,
(reg & PCA9541_CTL_NBUSON) >> 1);
}
static int pca9541_arbitrate(struct i2c_client *client)
{
struct pca9541 *data = i2c_get_clientdata(client);
int reg;
reg = pca9541_reg_read(client, PCA9541_CONTROL);
if (reg < 0)
return reg;
if (busoff(reg)) {
int istat;
istat = pca9541_reg_read(client, PCA9541_ISTAT);
if (!(istat & PCA9541_ISTAT_NMYTEST)
|| time_is_before_eq_jiffies(data->arb_timeout)) {
pca9541_reg_write(client,
PCA9541_CONTROL,
pca9541_control[reg & 0x0f]
| PCA9541_CTL_NTESTON);
data->select_timeout = SELECT_DELAY_SHORT;
} else {
data->select_timeout = SELECT_DELAY_LONG * 2;
}
} else if (mybus(reg)) {
if (reg & (PCA9541_CTL_NTESTON | PCA9541_CTL_BUSINIT))
pca9541_reg_write(client,
PCA9541_CONTROL,
reg & ~(PCA9541_CTL_NTESTON
| PCA9541_CTL_BUSINIT));
return 1;
} else {
data->select_timeout = SELECT_DELAY_LONG;
if (time_is_before_eq_jiffies(data->arb_timeout)) {
pca9541_reg_write(client,
PCA9541_CONTROL,
pca9541_control[reg & 0x0f]
| PCA9541_CTL_BUSINIT
| PCA9541_CTL_NTESTON);
} else {
if (!(reg & PCA9541_CTL_NTESTON))
pca9541_reg_write(client,
PCA9541_CONTROL,
reg | PCA9541_CTL_NTESTON);
}
}
return 0;
}
static int pca9541_select_chan(struct i2c_adapter *adap, void *client, u32 chan)
{
struct pca9541 *data = i2c_get_clientdata(client);
int ret;
unsigned long timeout = jiffies + ARB2_TIMEOUT;
data->arb_timeout = jiffies + ARB_TIMEOUT;
do {
ret = pca9541_arbitrate(client);
if (ret)
return ret < 0 ? ret : 0;
if (data->select_timeout == SELECT_DELAY_SHORT)
udelay(data->select_timeout);
else
msleep(data->select_timeout / 1000);
} while (time_is_after_eq_jiffies(timeout));
return -ETIMEDOUT;
}
static int pca9541_release_chan(struct i2c_adapter *adap,
void *client, u32 chan)
{
pca9541_release_bus(client);
return 0;
}
static int pca9541_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adap = client->adapter;
struct pca954x_platform_data *pdata = dev_get_platdata(&client->dev);
struct pca9541 *data;
int force;
int ret = -ENODEV;
if (!i2c_check_functionality(adap, I2C_FUNC_SMBUS_BYTE_DATA))
goto err;
data = kzalloc(sizeof(struct pca9541), GFP_KERNEL);
if (!data) {
ret = -ENOMEM;
goto err;
}
i2c_set_clientdata(client, data);
i2c_lock_adapter(adap);
pca9541_release_bus(client);
i2c_unlock_adapter(adap);
force = 0;
if (pdata)
force = pdata->modes[0].adap_id;
data->mux_adap = i2c_add_mux_adapter(adap, &client->dev, client,
force, 0, 0,
pca9541_select_chan,
pca9541_release_chan);
if (data->mux_adap == NULL) {
dev_err(&client->dev, "failed to register master selector\n");
goto exit_free;
}
dev_info(&client->dev, "registered master selector for I2C %s\n",
client->name);
return 0;
exit_free:
kfree(data);
err:
return ret;
}
static int pca9541_remove(struct i2c_client *client)
{
struct pca9541 *data = i2c_get_clientdata(client);
i2c_del_mux_adapter(data->mux_adap);
kfree(data);
return 0;
}
