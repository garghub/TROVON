static int si2157_cmd_execute(struct si2157 *s, struct si2157_cmd *cmd)
{
int ret;
unsigned long timeout;
mutex_lock(&s->i2c_mutex);
if (cmd->wlen) {
ret = i2c_master_send(s->client, cmd->args, cmd->wlen);
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
ret = i2c_master_recv(s->client, cmd->args, cmd->rlen);
if (ret < 0) {
goto err_mutex_unlock;
} else if (ret != cmd->rlen) {
ret = -EREMOTEIO;
goto err_mutex_unlock;
}
if ((cmd->args[0] >> 7) & 0x01)
break;
}
dev_dbg(&s->client->dev, "cmd execution took %d ms\n",
jiffies_to_msecs(jiffies) -
(jiffies_to_msecs(timeout) - TIMEOUT));
if (!((cmd->args[0] >> 7) & 0x01)) {
ret = -ETIMEDOUT;
goto err_mutex_unlock;
}
}
ret = 0;
err_mutex_unlock:
mutex_unlock(&s->i2c_mutex);
if (ret)
goto err;
return 0;
err:
dev_dbg(&s->client->dev, "failed=%d\n", ret);
return ret;
}
static int si2157_init(struct dvb_frontend *fe)
{
struct si2157 *s = fe->tuner_priv;
int ret, len, remaining;
struct si2157_cmd cmd;
const struct firmware *fw = NULL;
u8 *fw_file;
unsigned int chip_id;
dev_dbg(&s->client->dev, "\n");
if (s->fw_loaded)
goto warm;
if (s->chiptype == SI2157_CHIPTYPE_SI2146) {
memcpy(cmd.args, "\xc0\x05\x01\x00\x00\x0b\x00\x00\x01", 9);
cmd.wlen = 9;
} else {
memcpy(cmd.args, "\xc0\x00\x0c\x00\x00\x01\x01\x01\x01\x01\x01\x02\x00\x00\x01", 15);
cmd.wlen = 15;
}
cmd.rlen = 1;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
memcpy(cmd.args, "\x02", 1);
cmd.wlen = 1;
cmd.rlen = 13;
ret = si2157_cmd_execute(s, &cmd);
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
fw_file = SI2158_A20_FIRMWARE;
break;
case SI2157_A30:
case SI2147_A30:
case SI2146_A10:
goto skip_fw_download;
default:
dev_err(&s->client->dev,
"unknown chip version Si21%d-%c%c%c\n",
cmd.args[2], cmd.args[1],
cmd.args[3], cmd.args[4]);
ret = -EINVAL;
goto err;
}
dev_info(&s->client->dev, "found a '%s' in cold state\n",
si2157_ops.info.name);
ret = request_firmware(&fw, fw_file, &s->client->dev);
if (ret) {
dev_err(&s->client->dev, "firmware file '%s' not found\n",
fw_file);
goto err;
}
if (fw->size % 17 != 0) {
dev_err(&s->client->dev, "firmware file '%s' is invalid\n",
fw_file);
ret = -EINVAL;
goto fw_release_exit;
}
dev_info(&s->client->dev, "downloading firmware from file '%s'\n",
fw_file);
for (remaining = fw->size; remaining > 0; remaining -= 17) {
len = fw->data[fw->size - remaining];
memcpy(cmd.args, &fw->data[(fw->size - remaining) + 1], len);
cmd.wlen = len;
cmd.rlen = 1;
ret = si2157_cmd_execute(s, &cmd);
if (ret) {
dev_err(&s->client->dev,
"firmware download failed=%d\n",
ret);
goto fw_release_exit;
}
}
release_firmware(fw);
fw = NULL;
skip_fw_download:
memcpy(cmd.args, "\x01\x01", 2);
cmd.wlen = 2;
cmd.rlen = 1;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
s->fw_loaded = true;
warm:
s->active = true;
return 0;
fw_release_exit:
release_firmware(fw);
err:
dev_dbg(&s->client->dev, "failed=%d\n", ret);
return ret;
}
static int si2157_sleep(struct dvb_frontend *fe)
{
struct si2157 *s = fe->tuner_priv;
int ret;
struct si2157_cmd cmd;
dev_dbg(&s->client->dev, "\n");
s->active = false;
memcpy(cmd.args, "\x16\x00", 2);
cmd.wlen = 2;
cmd.rlen = 1;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
return 0;
err:
dev_dbg(&s->client->dev, "failed=%d\n", ret);
return ret;
}
static int si2157_set_params(struct dvb_frontend *fe)
{
struct si2157 *s = fe->tuner_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret;
struct si2157_cmd cmd;
u8 bandwidth, delivery_system;
dev_dbg(&s->client->dev,
"delivery_system=%d frequency=%u bandwidth_hz=%u\n",
c->delivery_system, c->frequency,
c->bandwidth_hz);
if (!s->active) {
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
break;
case SYS_DVBC_ANNEX_B:
delivery_system = 0x10;
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
if (s->inversion)
cmd.args[5] = 0x01;
cmd.wlen = 6;
cmd.rlen = 4;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
if (s->chiptype == SI2157_CHIPTYPE_SI2146)
memcpy(cmd.args, "\x14\x00\x02\x07\x00\x01", 6);
else
memcpy(cmd.args, "\x14\x00\x02\x07\x01\x00", 6);
cmd.wlen = 6;
cmd.rlen = 4;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
memcpy(cmd.args, "\x41\x00\x00\x00\x00\x00\x00\x00", 8);
cmd.args[4] = (c->frequency >> 0) & 0xff;
cmd.args[5] = (c->frequency >> 8) & 0xff;
cmd.args[6] = (c->frequency >> 16) & 0xff;
cmd.args[7] = (c->frequency >> 24) & 0xff;
cmd.wlen = 8;
cmd.rlen = 1;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
return 0;
err:
dev_dbg(&s->client->dev, "failed=%d\n", ret);
return ret;
}
static int si2157_get_if_frequency(struct dvb_frontend *fe, u32 *frequency)
{
*frequency = 5000000;
return 0;
}
static int si2157_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct si2157_config *cfg = client->dev.platform_data;
struct dvb_frontend *fe = cfg->fe;
struct si2157 *s;
struct si2157_cmd cmd;
int ret;
s = kzalloc(sizeof(struct si2157), GFP_KERNEL);
if (!s) {
ret = -ENOMEM;
dev_err(&client->dev, "kzalloc() failed\n");
goto err;
}
s->client = client;
s->fe = cfg->fe;
s->inversion = cfg->inversion;
s->fw_loaded = false;
s->chiptype = (u8)id->driver_data;
mutex_init(&s->i2c_mutex);
cmd.wlen = 0;
cmd.rlen = 1;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
fe->tuner_priv = s;
memcpy(&fe->ops.tuner_ops, &si2157_ops,
sizeof(struct dvb_tuner_ops));
i2c_set_clientdata(client, s);
dev_info(&s->client->dev,
"Silicon Labs %s successfully attached\n",
s->chiptype == SI2157_CHIPTYPE_SI2146 ?
"Si2146" : "Si2147/2148/2157/2158");
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
kfree(s);
return ret;
}
static int si2157_remove(struct i2c_client *client)
{
struct si2157 *s = i2c_get_clientdata(client);
struct dvb_frontend *fe = s->fe;
dev_dbg(&client->dev, "\n");
memset(&fe->ops.tuner_ops, 0, sizeof(struct dvb_tuner_ops));
fe->tuner_priv = NULL;
kfree(s);
return 0;
}
