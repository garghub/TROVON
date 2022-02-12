static int si2157_cmd_execute(struct i2c_client *client, struct si2157_cmd *cmd)
{
struct si2157_dev *dev = i2c_get_clientdata(client);
int ret;
unsigned long timeout;
mutex_lock(&dev->i2c_mutex);
if (cmd->wlen) {
ret = i2c_master_send(client, cmd->args, cmd->wlen);
if (ret < 0) {
goto err_mutex_unlock;
} else if (ret != cmd->wlen) {
ret = -EREMOTEIO;
goto err_mutex_unlock;
}
}
if (cmd->rlen) {
#define TIMEOUT 80
timeout = jiffies + msecs_to_jiffies(TIMEOUT);
while (!time_after(jiffies, timeout)) {
ret = i2c_master_recv(client, cmd->args, cmd->rlen);
if (ret < 0) {
goto err_mutex_unlock;
} else if (ret != cmd->rlen) {
ret = -EREMOTEIO;
goto err_mutex_unlock;
}
if ((cmd->args[0] >> 7) & 0x01)
break;
}
dev_dbg(&client->dev, "cmd execution took %d ms\n",
jiffies_to_msecs(jiffies) -
(jiffies_to_msecs(timeout) - TIMEOUT));
if (!((cmd->args[0] >> 7) & 0x01)) {
ret = -ETIMEDOUT;
goto err_mutex_unlock;
}
}
mutex_unlock(&dev->i2c_mutex);
return 0;
err_mutex_unlock:
mutex_unlock(&dev->i2c_mutex);
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int si2157_init(struct dvb_frontend *fe)
{
struct i2c_client *client = fe->tuner_priv;
struct si2157_dev *dev = i2c_get_clientdata(client);
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret, len, remaining;
struct si2157_cmd cmd;
const struct firmware *fw;
const char *fw_name;
unsigned int chip_id;
dev_dbg(&client->dev, "\n");
if (dev->fw_loaded)
goto warm;
if (dev->chiptype == SI2157_CHIPTYPE_SI2146) {
memcpy(cmd.args, "\xc0\x05\x01\x00\x00\x0b\x00\x00\x01", 9);
cmd.wlen = 9;
} else {
memcpy(cmd.args, "\xc0\x00\x0c\x00\x00\x01\x01\x01\x01\x01\x01\x02\x00\x00\x01", 15);
cmd.wlen = 15;
}
cmd.rlen = 1;
ret = si2157_cmd_execute(client, &cmd);
if (ret)
goto err;
memcpy(cmd.args, "\x02", 1);
cmd.wlen = 1;
cmd.rlen = 13;
ret = si2157_cmd_execute(client, &cmd);
if (ret)
goto err;
chip_id = cmd.args[1] << 24 | cmd.args[2] << 16 | cmd.args[3] << 8 |
cmd.args[4] << 0;
#define SI2158_A20 ('A' << 24 | 58 << 16 | '2' << 8 | '0' << 0)
#define SI2148_A20 ('A' << 24 | 48 << 16 | '2' << 8 | '0' << 0)
#define SI2157_A30 ('A' << 24 | 57 << 16 | '3' << 8 | '0' << 0)
#define SI2147_A30 ('A' << 24 | 47 << 16 | '3' << 8 | '0' << 0)
#define SI2146_A10 ('A' << 24 | 46 << 16 | '1' << 8 | '0' << 0)
switch (chip_id) {
case SI2158_A20:
case SI2148_A20:
fw_name = SI2158_A20_FIRMWARE;
break;
case SI2157_A30:
case SI2147_A30:
case SI2146_A10:
fw_name = NULL;
break;
default:
dev_err(&client->dev, "unknown chip version Si21%d-%c%c%c\n",
cmd.args[2], cmd.args[1],
cmd.args[3], cmd.args[4]);
ret = -EINVAL;
goto err;
}
dev_info(&client->dev, "found a 'Silicon Labs Si21%d-%c%c%c'\n",
cmd.args[2], cmd.args[1], cmd.args[3], cmd.args[4]);
if (fw_name == NULL)
goto skip_fw_download;
ret = request_firmware(&fw, fw_name, &client->dev);
if (ret) {
dev_err(&client->dev, "firmware file '%s' not found\n",
fw_name);
goto err;
}
if (fw->size % 17 != 0) {
dev_err(&client->dev, "firmware file '%s' is invalid\n",
fw_name);
ret = -EINVAL;
goto err_release_firmware;
}
dev_info(&client->dev, "downloading firmware from file '%s'\n",
fw_name);
for (remaining = fw->size; remaining > 0; remaining -= 17) {
len = fw->data[fw->size - remaining];
if (len > SI2157_ARGLEN) {
dev_err(&client->dev, "Bad firmware length\n");
ret = -EINVAL;
goto err_release_firmware;
}
memcpy(cmd.args, &fw->data[(fw->size - remaining) + 1], len);
cmd.wlen = len;
cmd.rlen = 1;
ret = si2157_cmd_execute(client, &cmd);
if (ret) {
dev_err(&client->dev, "firmware download failed %d\n",
ret);
goto err_release_firmware;
}
}
release_firmware(fw);
skip_fw_download:
memcpy(cmd.args, "\x01\x01", 2);
cmd.wlen = 2;
cmd.rlen = 1;
ret = si2157_cmd_execute(client, &cmd);
if (ret)
goto err;
memcpy(cmd.args, "\x11", 1);
cmd.wlen = 1;
cmd.rlen = 10;
ret = si2157_cmd_execute(client, &cmd);
if (ret)
goto err;
dev_info(&client->dev, "firmware version: %c.%c.%d\n",
cmd.args[6], cmd.args[7], cmd.args[8]);
dev->fw_loaded = true;
warm:
c->strength.len = 1;
c->strength.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
schedule_delayed_work(&dev->stat_work, msecs_to_jiffies(1000));
dev->active = true;
return 0;
err_release_firmware:
release_firmware(fw);
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int si2157_sleep(struct dvb_frontend *fe)
{
struct i2c_client *client = fe->tuner_priv;
struct si2157_dev *dev = i2c_get_clientdata(client);
int ret;
struct si2157_cmd cmd;
dev_dbg(&client->dev, "\n");
dev->active = false;
cancel_delayed_work_sync(&dev->stat_work);
memcpy(cmd.args, "\x16\x00", 2);
cmd.wlen = 2;
cmd.rlen = 1;
ret = si2157_cmd_execute(client, &cmd);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int si2157_set_params(struct dvb_frontend *fe)
{
struct i2c_client *client = fe->tuner_priv;
struct si2157_dev *dev = i2c_get_clientdata(client);
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret;
struct si2157_cmd cmd;
u8 bandwidth, delivery_system;
u32 if_frequency = 5000000;
dev_dbg(&client->dev,
"delivery_system=%d frequency=%u bandwidth_hz=%u\n",
c->delivery_system, c->frequency, c->bandwidth_hz);
if (!dev->active) {
ret = -EAGAIN;
goto err;
}
if (c->bandwidth_hz <= 6000000)
bandwidth = 0x06;
else if (c->bandwidth_hz <= 7000000)
bandwidth = 0x07;
else if (c->bandwidth_hz <= 8000000)
bandwidth = 0x08;
else
bandwidth = 0x0f;
switch (c->delivery_system) {
case SYS_ATSC:
delivery_system = 0x00;
if_frequency = 3250000;
break;
case SYS_DVBC_ANNEX_B:
delivery_system = 0x10;
if_frequency = 4000000;
break;
case SYS_DVBT:
case SYS_DVBT2:
delivery_system = 0x20;
break;
case SYS_DVBC_ANNEX_A:
delivery_system = 0x30;
break;
default:
ret = -EINVAL;
goto err;
}
memcpy(cmd.args, "\x14\x00\x03\x07\x00\x00", 6);
cmd.args[4] = delivery_system | bandwidth;
if (dev->inversion)
cmd.args[5] = 0x01;
cmd.wlen = 6;
cmd.rlen = 4;
ret = si2157_cmd_execute(client, &cmd);
if (ret)
goto err;
if (dev->chiptype == SI2157_CHIPTYPE_SI2146)
memcpy(cmd.args, "\x14\x00\x02\x07\x00\x01", 6);
else
memcpy(cmd.args, "\x14\x00\x02\x07\x00\x00", 6);
cmd.args[4] = dev->if_port;
cmd.wlen = 6;
cmd.rlen = 4;
ret = si2157_cmd_execute(client, &cmd);
if (ret)
goto err;
if (if_frequency != dev->if_frequency) {
memcpy(cmd.args, "\x14\x00\x06\x07", 4);
cmd.args[4] = (if_frequency / 1000) & 0xff;
cmd.args[5] = ((if_frequency / 1000) >> 8) & 0xff;
cmd.wlen = 6;
cmd.rlen = 4;
ret = si2157_cmd_execute(client, &cmd);
if (ret)
goto err;
dev->if_frequency = if_frequency;
}
memcpy(cmd.args, "\x41\x00\x00\x00\x00\x00\x00\x00", 8);
cmd.args[4] = (c->frequency >> 0) & 0xff;
cmd.args[5] = (c->frequency >> 8) & 0xff;
cmd.args[6] = (c->frequency >> 16) & 0xff;
cmd.args[7] = (c->frequency >> 24) & 0xff;
cmd.wlen = 8;
cmd.rlen = 1;
ret = si2157_cmd_execute(client, &cmd);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int si2157_get_if_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct i2c_client *client = fe->tuner_priv;
struct si2157_dev *dev = i2c_get_clientdata(client);
*frequency = dev->if_frequency;
return 0;
}
static void si2157_stat_work(struct work_struct *work)
{
struct si2157_dev *dev = container_of(work, struct si2157_dev, stat_work.work);
struct dvb_frontend *fe = dev->fe;
struct i2c_client *client = fe->tuner_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct si2157_cmd cmd;
int ret;
dev_dbg(&client->dev, "\n");
memcpy(cmd.args, "\x42\x00", 2);
cmd.wlen = 2;
cmd.rlen = 12;
ret = si2157_cmd_execute(client, &cmd);
if (ret)
goto err;
c->strength.stat[0].scale = FE_SCALE_DECIBEL;
c->strength.stat[0].svalue = (s8) cmd.args[3] * 1000;
schedule_delayed_work(&dev->stat_work, msecs_to_jiffies(2000));
return;
err:
c->strength.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
dev_dbg(&client->dev, "failed=%d\n", ret);
}
static int si2157_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct si2157_config *cfg = client->dev.platform_data;
struct dvb_frontend *fe = cfg->fe;
struct si2157_dev *dev;
struct si2157_cmd cmd;
int ret;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
ret = -ENOMEM;
dev_err(&client->dev, "kzalloc() failed\n");
goto err;
}
i2c_set_clientdata(client, dev);
dev->fe = cfg->fe;
dev->inversion = cfg->inversion;
dev->if_port = cfg->if_port;
dev->fw_loaded = false;
dev->chiptype = (u8)id->driver_data;
dev->if_frequency = 5000000;
mutex_init(&dev->i2c_mutex);
INIT_DELAYED_WORK(&dev->stat_work, si2157_stat_work);
cmd.wlen = 0;
cmd.rlen = 1;
ret = si2157_cmd_execute(client, &cmd);
if (ret)
goto err_kfree;
memcpy(&fe->ops.tuner_ops, &si2157_ops, sizeof(struct dvb_tuner_ops));
fe->tuner_priv = client;
dev_info(&client->dev, "Silicon Labs %s successfully attached\n",
dev->chiptype == SI2157_CHIPTYPE_SI2146 ?
"Si2146" : "Si2147/2148/2157/2158");
return 0;
err_kfree:
kfree(dev);
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int si2157_remove(struct i2c_client *client)
{
struct si2157_dev *dev = i2c_get_clientdata(client);
struct dvb_frontend *fe = dev->fe;
dev_dbg(&client->dev, "\n");
memset(&fe->ops.tuner_ops, 0, sizeof(struct dvb_tuner_ops));
fe->tuner_priv = NULL;
kfree(dev);
return 0;
}
