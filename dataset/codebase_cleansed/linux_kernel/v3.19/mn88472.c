static int mn88472_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *s)
{
s->min_delay_ms = 400;
return 0;
}
static int mn88472_set_frontend(struct dvb_frontend *fe)
{
struct i2c_client *client = fe->demodulator_priv;
struct mn88472_dev *dev = i2c_get_clientdata(client);
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret, i;
u32 if_frequency = 0;
u8 delivery_system_val, if_val[3], bw_val[7], bw_val2;
dev_dbg(&client->dev,
"delivery_system=%d modulation=%d frequency=%d symbol_rate=%d inversion=%d\n",
c->delivery_system, c->modulation,
c->frequency, c->symbol_rate, c->inversion);
if (!dev->warm) {
ret = -EAGAIN;
goto err;
}
switch (c->delivery_system) {
case SYS_DVBT:
delivery_system_val = 0x02;
break;
case SYS_DVBT2:
delivery_system_val = 0x03;
break;
case SYS_DVBC_ANNEX_A:
delivery_system_val = 0x04;
break;
default:
ret = -EINVAL;
goto err;
}
switch (c->delivery_system) {
case SYS_DVBT:
case SYS_DVBT2:
if (c->bandwidth_hz <= 6000000) {
memcpy(if_val, "\x2c\x94\xdb", 3);
memcpy(bw_val, "\xbf\x55\x55\x15\x6b\x15\x6b", 7);
bw_val2 = 0x02;
} else if (c->bandwidth_hz <= 7000000) {
memcpy(if_val, "\x39\x11\xbc", 3);
memcpy(bw_val, "\xa4\x00\x00\x0f\x2c\x0f\x2c", 7);
bw_val2 = 0x01;
} else if (c->bandwidth_hz <= 8000000) {
memcpy(if_val, "\x39\x11\xbc", 3);
memcpy(bw_val, "\x8f\x80\x00\x08\xee\x08\xee", 7);
bw_val2 = 0x00;
} else {
ret = -EINVAL;
goto err;
}
break;
case SYS_DVBC_ANNEX_A:
memcpy(if_val, "\x3f\x50\x2c", 3);
memcpy(bw_val, "\x8f\x80\x00\x08\xee\x08\xee", 7);
bw_val2 = 0x00;
break;
default:
ret = -EINVAL;
goto err;
}
if (fe->ops.tuner_ops.set_params) {
ret = fe->ops.tuner_ops.set_params(fe);
if (ret)
goto err;
}
if (fe->ops.tuner_ops.get_if_frequency) {
ret = fe->ops.tuner_ops.get_if_frequency(fe, &if_frequency);
if (ret)
goto err;
dev_dbg(&client->dev, "get_if_frequency=%d\n", if_frequency);
}
switch (if_frequency) {
case 3570000:
case 4570000:
case 5070000:
break;
default:
dev_err(&client->dev, "IF frequency %d not supported\n",
if_frequency);
ret = -EINVAL;
goto err;
}
ret = regmap_write(dev->regmap[2], 0xfb, 0x13);
ret = regmap_write(dev->regmap[2], 0xef, 0x13);
ret = regmap_write(dev->regmap[2], 0xf9, 0x13);
if (ret)
goto err;
ret = regmap_write(dev->regmap[2], 0x00, 0x66);
if (ret)
goto err;
ret = regmap_write(dev->regmap[2], 0x01, 0x00);
if (ret)
goto err;
ret = regmap_write(dev->regmap[2], 0x02, 0x01);
if (ret)
goto err;
ret = regmap_write(dev->regmap[2], 0x03, delivery_system_val);
if (ret)
goto err;
ret = regmap_write(dev->regmap[2], 0x04, bw_val2);
if (ret)
goto err;
for (i = 0; i < sizeof(if_val); i++) {
ret = regmap_write(dev->regmap[2], 0x10 + i, if_val[i]);
if (ret)
goto err;
}
for (i = 0; i < sizeof(bw_val); i++) {
ret = regmap_write(dev->regmap[2], 0x13 + i, bw_val[i]);
if (ret)
goto err;
}
switch (c->delivery_system) {
case SYS_DVBT:
ret = regmap_write(dev->regmap[0], 0x07, 0x26);
ret = regmap_write(dev->regmap[0], 0xb0, 0x0a);
ret = regmap_write(dev->regmap[0], 0xb4, 0x00);
ret = regmap_write(dev->regmap[0], 0xcd, 0x1f);
ret = regmap_write(dev->regmap[0], 0xd4, 0x0a);
ret = regmap_write(dev->regmap[0], 0xd6, 0x48);
ret = regmap_write(dev->regmap[0], 0x00, 0xba);
ret = regmap_write(dev->regmap[0], 0x01, 0x13);
if (ret)
goto err;
break;
case SYS_DVBT2:
ret = regmap_write(dev->regmap[2], 0x2b, 0x13);
ret = regmap_write(dev->regmap[2], 0x4f, 0x05);
ret = regmap_write(dev->regmap[1], 0xf6, 0x05);
ret = regmap_write(dev->regmap[0], 0xb0, 0x0a);
ret = regmap_write(dev->regmap[0], 0xb4, 0xf6);
ret = regmap_write(dev->regmap[0], 0xcd, 0x01);
ret = regmap_write(dev->regmap[0], 0xd4, 0x09);
ret = regmap_write(dev->regmap[0], 0xd6, 0x46);
ret = regmap_write(dev->regmap[2], 0x30, 0x80);
ret = regmap_write(dev->regmap[2], 0x32, 0x00);
if (ret)
goto err;
break;
case SYS_DVBC_ANNEX_A:
ret = regmap_write(dev->regmap[0], 0xb0, 0x0b);
ret = regmap_write(dev->regmap[0], 0xb4, 0x00);
ret = regmap_write(dev->regmap[0], 0xcd, 0x17);
ret = regmap_write(dev->regmap[0], 0xd4, 0x09);
ret = regmap_write(dev->regmap[0], 0xd6, 0x48);
ret = regmap_write(dev->regmap[1], 0x00, 0xb0);
if (ret)
goto err;
break;
default:
ret = -EINVAL;
goto err;
}
ret = regmap_write(dev->regmap[0], 0x46, 0x00);
ret = regmap_write(dev->regmap[0], 0xae, 0x00);
ret = regmap_write(dev->regmap[2], 0x08, 0x1d);
ret = regmap_write(dev->regmap[0], 0xd9, 0xe3);
ret = regmap_write(dev->regmap[2], 0xf8, 0x9f);
if (ret)
goto err;
dev->delivery_system = c->delivery_system;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int mn88472_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct i2c_client *client = fe->demodulator_priv;
struct mn88472_dev *dev = i2c_get_clientdata(client);
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret;
unsigned int utmp;
*status = 0;
if (!dev->warm) {
ret = -EAGAIN;
goto err;
}
switch (c->delivery_system) {
case SYS_DVBT:
case SYS_DVBT2:
utmp = 0x08;
break;
case SYS_DVBC_ANNEX_A:
ret = regmap_read(dev->regmap[1], 0x84, &utmp);
if (ret)
goto err;
break;
default:
ret = -EINVAL;
goto err;
}
if (utmp == 0x08)
*status = FE_HAS_SIGNAL | FE_HAS_CARRIER | FE_HAS_VITERBI |
FE_HAS_SYNC | FE_HAS_LOCK;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int mn88472_init(struct dvb_frontend *fe)
{
struct i2c_client *client = fe->demodulator_priv;
struct mn88472_dev *dev = i2c_get_clientdata(client);
int ret, len, remaining;
const struct firmware *fw = NULL;
u8 *fw_file = MN88472_FIRMWARE;
dev_dbg(&client->dev, "\n");
dev->warm = false;
ret = regmap_write(dev->regmap[2], 0x05, 0x00);
if (ret)
goto err;
ret = regmap_bulk_write(dev->regmap[2], 0x0b, "\x00\x00", 2);
if (ret)
goto err;
ret = request_firmware(&fw, fw_file, &client->dev);
if (ret) {
dev_err(&client->dev, "firmare file '%s' not found\n",
fw_file);
goto err;
}
dev_info(&client->dev, "downloading firmware from file '%s'\n",
fw_file);
ret = regmap_write(dev->regmap[0], 0xf5, 0x03);
if (ret)
goto err;
for (remaining = fw->size; remaining > 0;
remaining -= (dev->i2c_wr_max - 1)) {
len = remaining;
if (len > (dev->i2c_wr_max - 1))
len = (dev->i2c_wr_max - 1);
ret = regmap_bulk_write(dev->regmap[0], 0xf6,
&fw->data[fw->size - remaining], len);
if (ret) {
dev_err(&client->dev,
"firmware download failed=%d\n", ret);
goto err;
}
}
ret = regmap_write(dev->regmap[0], 0xf5, 0x00);
if (ret)
goto err;
release_firmware(fw);
fw = NULL;
dev->warm = true;
return 0;
err:
if (fw)
release_firmware(fw);
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int mn88472_sleep(struct dvb_frontend *fe)
{
struct i2c_client *client = fe->demodulator_priv;
struct mn88472_dev *dev = i2c_get_clientdata(client);
int ret;
dev_dbg(&client->dev, "\n");
ret = regmap_write(dev->regmap[2], 0x0b, 0x30);
if (ret)
goto err;
ret = regmap_write(dev->regmap[2], 0x05, 0x3e);
if (ret)
goto err;
dev->delivery_system = SYS_UNDEFINED;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int mn88472_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mn88472_config *config = client->dev.platform_data;
struct mn88472_dev *dev;
int ret;
unsigned int utmp;
static const struct regmap_config regmap_config = {
.reg_bits = 8,
.val_bits = 8,
};
dev_dbg(&client->dev, "\n");
if (config->fe == NULL) {
dev_err(&client->dev, "frontend pointer not defined\n");
ret = -EINVAL;
goto err;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
ret = -ENOMEM;
goto err;
}
dev->i2c_wr_max = config->i2c_wr_max;
dev->client[0] = client;
dev->regmap[0] = regmap_init_i2c(dev->client[0], &regmap_config);
if (IS_ERR(dev->regmap[0])) {
ret = PTR_ERR(dev->regmap[0]);
goto err_kfree;
}
ret = regmap_read(dev->regmap[0], 0x00, &utmp);
if (ret)
goto err_regmap_0_regmap_exit;
dev->client[1] = i2c_new_dummy(client->adapter, 0x1a);
if (dev->client[1] == NULL) {
ret = -ENODEV;
dev_err(&client->dev, "I2C registration failed\n");
if (ret)
goto err_regmap_0_regmap_exit;
}
dev->regmap[1] = regmap_init_i2c(dev->client[1], &regmap_config);
if (IS_ERR(dev->regmap[1])) {
ret = PTR_ERR(dev->regmap[1]);
goto err_client_1_i2c_unregister_device;
}
i2c_set_clientdata(dev->client[1], dev);
dev->client[2] = i2c_new_dummy(client->adapter, 0x1c);
if (dev->client[2] == NULL) {
ret = -ENODEV;
dev_err(&client->dev, "2nd I2C registration failed\n");
if (ret)
goto err_regmap_1_regmap_exit;
}
dev->regmap[2] = regmap_init_i2c(dev->client[2], &regmap_config);
if (IS_ERR(dev->regmap[2])) {
ret = PTR_ERR(dev->regmap[2]);
goto err_client_2_i2c_unregister_device;
}
i2c_set_clientdata(dev->client[2], dev);
memcpy(&dev->fe.ops, &mn88472_ops, sizeof(struct dvb_frontend_ops));
dev->fe.demodulator_priv = client;
*config->fe = &dev->fe;
i2c_set_clientdata(client, dev);
dev_info(&client->dev, "Panasonic MN88472 successfully attached\n");
return 0;
err_client_2_i2c_unregister_device:
i2c_unregister_device(dev->client[2]);
err_regmap_1_regmap_exit:
regmap_exit(dev->regmap[1]);
err_client_1_i2c_unregister_device:
i2c_unregister_device(dev->client[1]);
err_regmap_0_regmap_exit:
regmap_exit(dev->regmap[0]);
err_kfree:
kfree(dev);
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int mn88472_remove(struct i2c_client *client)
{
struct mn88472_dev *dev = i2c_get_clientdata(client);
dev_dbg(&client->dev, "\n");
regmap_exit(dev->regmap[2]);
i2c_unregister_device(dev->client[2]);
regmap_exit(dev->regmap[1]);
i2c_unregister_device(dev->client[1]);
regmap_exit(dev->regmap[0]);
kfree(dev);
return 0;
}
