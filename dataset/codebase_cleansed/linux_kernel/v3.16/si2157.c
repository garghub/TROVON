static int si2157_cmd_execute(struct si2157 *s, struct si2157_cmd *cmd)
{
int ret;
u8 buf[1];
unsigned long timeout;
mutex_lock(&s->i2c_mutex);
if (cmd->len) {
ret = i2c_master_send(s->client, cmd->args, cmd->len);
if (ret < 0) {
goto err_mutex_unlock;
} else if (ret != cmd->len) {
ret = -EREMOTEIO;
goto err_mutex_unlock;
}
}
#define TIMEOUT 80
timeout = jiffies + msecs_to_jiffies(TIMEOUT);
while (!time_after(jiffies, timeout)) {
ret = i2c_master_recv(s->client, buf, 1);
if (ret < 0) {
goto err_mutex_unlock;
} else if (ret != 1) {
ret = -EREMOTEIO;
goto err_mutex_unlock;
}
if ((buf[0] >> 7) & 0x01)
break;
}
dev_dbg(&s->client->dev, "%s: cmd execution took %d ms\n", __func__,
jiffies_to_msecs(jiffies) -
(jiffies_to_msecs(timeout) - TIMEOUT));
if (!((buf[0] >> 7) & 0x01)) {
ret = -ETIMEDOUT;
goto err_mutex_unlock;
} else {
ret = 0;
}
err_mutex_unlock:
mutex_unlock(&s->i2c_mutex);
if (ret)
goto err;
return 0;
err:
dev_dbg(&s->client->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int si2157_init(struct dvb_frontend *fe)
{
struct si2157 *s = fe->tuner_priv;
dev_dbg(&s->client->dev, "%s:\n", __func__);
s->active = true;
return 0;
}
static int si2157_sleep(struct dvb_frontend *fe)
{
struct si2157 *s = fe->tuner_priv;
dev_dbg(&s->client->dev, "%s:\n", __func__);
s->active = false;
return 0;
}
static int si2157_set_params(struct dvb_frontend *fe)
{
struct si2157 *s = fe->tuner_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret;
struct si2157_cmd cmd;
dev_dbg(&s->client->dev,
"%s: delivery_system=%d frequency=%u bandwidth_hz=%u\n",
__func__, c->delivery_system, c->frequency,
c->bandwidth_hz);
if (!s->active) {
ret = -EAGAIN;
goto err;
}
cmd.args[0] = 0xc0;
cmd.args[1] = 0x00;
cmd.args[2] = 0x0c;
cmd.args[3] = 0x00;
cmd.args[4] = 0x00;
cmd.args[5] = 0x01;
cmd.args[6] = 0x01;
cmd.args[7] = 0x01;
cmd.args[8] = 0x01;
cmd.args[9] = 0x01;
cmd.args[10] = 0x01;
cmd.args[11] = 0x02;
cmd.args[12] = 0x00;
cmd.args[13] = 0x00;
cmd.args[14] = 0x01;
cmd.len = 15;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
cmd.args[0] = 0x02;
cmd.len = 1;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
cmd.args[0] = 0x01;
cmd.args[1] = 0x01;
cmd.len = 2;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
cmd.args[0] = 0x41;
cmd.args[1] = 0x00;
cmd.args[2] = 0x00;
cmd.args[3] = 0x00;
cmd.args[4] = (c->frequency >> 0) & 0xff;
cmd.args[5] = (c->frequency >> 8) & 0xff;
cmd.args[6] = (c->frequency >> 16) & 0xff;
cmd.args[7] = (c->frequency >> 24) & 0xff;
cmd.len = 8;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
return 0;
err:
dev_dbg(&s->client->dev, "%s: failed=%d\n", __func__, ret);
return ret;
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
dev_err(&client->dev, "%s: kzalloc() failed\n", KBUILD_MODNAME);
goto err;
}
s->client = client;
s->fe = cfg->fe;
mutex_init(&s->i2c_mutex);
cmd.len = 0;
ret = si2157_cmd_execute(s, &cmd);
if (ret)
goto err;
fe->tuner_priv = s;
memcpy(&fe->ops.tuner_ops, &si2157_tuner_ops,
sizeof(struct dvb_tuner_ops));
i2c_set_clientdata(client, s);
dev_info(&s->client->dev,
"%s: Silicon Labs Si2157 successfully attached\n",
KBUILD_MODNAME);
return 0;
err:
dev_dbg(&client->dev, "%s: failed=%d\n", __func__, ret);
kfree(s);
return ret;
}
static int si2157_remove(struct i2c_client *client)
{
struct si2157 *s = i2c_get_clientdata(client);
struct dvb_frontend *fe = s->fe;
dev_dbg(&client->dev, "%s:\n", __func__);
memset(&fe->ops.tuner_ops, 0, sizeof(struct dvb_tuner_ops));
fe->tuner_priv = NULL;
kfree(s);
return 0;
}
