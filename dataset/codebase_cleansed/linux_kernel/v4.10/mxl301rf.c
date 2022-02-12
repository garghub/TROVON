static struct mxl301rf_state *cfg_to_state(struct mxl301rf_config *c)
{
return container_of(c, struct mxl301rf_state, cfg);
}
static int raw_write(struct mxl301rf_state *state, const u8 *buf, int len)
{
int ret;
ret = i2c_master_send(state->i2c, buf, len);
if (ret >= 0 && ret < len)
ret = -EIO;
return (ret == len) ? 0 : ret;
}
static int reg_write(struct mxl301rf_state *state, u8 reg, u8 val)
{
u8 buf[2] = { reg, val };
return raw_write(state, buf, 2);
}
static int reg_read(struct mxl301rf_state *state, u8 reg, u8 *val)
{
u8 wbuf[2] = { 0xfb, reg };
int ret;
ret = raw_write(state, wbuf, sizeof(wbuf));
if (ret == 0)
ret = i2c_master_recv(state->i2c, val, 1);
if (ret >= 0 && ret < 1)
ret = -EIO;
return (ret == 1) ? 0 : ret;
}
static int mxl301rf_get_rf_strength(struct dvb_frontend *fe, u16 *out)
{
struct mxl301rf_state *state;
int ret;
u8 rf_in1, rf_in2, rf_off1, rf_off2;
u16 rf_in, rf_off;
s64 level;
struct dtv_fe_stats *rssi;
rssi = &fe->dtv_property_cache.strength;
rssi->len = 1;
rssi->stat[0].scale = FE_SCALE_NOT_AVAILABLE;
*out = 0;
state = fe->tuner_priv;
ret = reg_write(state, 0x14, 0x01);
if (ret < 0)
return ret;
usleep_range(1000, 2000);
ret = reg_read(state, 0x18, &rf_in1);
if (ret == 0)
ret = reg_read(state, 0x19, &rf_in2);
if (ret == 0)
ret = reg_read(state, 0xd6, &rf_off1);
if (ret == 0)
ret = reg_read(state, 0xd7, &rf_off2);
if (ret != 0)
return ret;
rf_in = (rf_in2 & 0x07) << 8 | rf_in1;
rf_off = (rf_off2 & 0x0f) << 5 | (rf_off1 >> 3);
level = rf_in - rf_off - (113 << 3);
level = level * 1000 / 8;
rssi->stat[0].svalue = level;
rssi->stat[0].scale = FE_SCALE_DECIBEL;
*out = (rf_in - rf_off + (1 << 9) - 1) * 100 / ((5 << 9) - 2);
return 0;
}
static int mxl301rf_set_params(struct dvb_frontend *fe)
{
struct reg_val tune0[] = {
{ 0x13, 0x00 },
{ 0x3b, 0xc0 },
{ 0x3b, 0x80 },
{ 0x10, 0x95 },
{ 0x1a, 0x05 },
{ 0x61, 0x00 },
{ 0x62, 0xa0 }
};
struct reg_val tune1[] = {
{ 0x11, 0x40 },
{ 0x12, 0x0e },
{ 0x13, 0x01 }
};
struct mxl301rf_state *state;
u32 freq;
u16 f;
u32 tmp, div;
int i, ret;
state = fe->tuner_priv;
freq = fe->dtv_property_cache.frequency;
for (i = 0; i < ARRAY_SIZE(shf_tab); i++) {
if (freq >= (shf_tab[i].freq - shf_tab[i].ofst_th) * 1000 &&
freq <= (shf_tab[i].freq + shf_tab[i].ofst_th) * 1000) {
tune0[5].val = shf_tab[i].shf_val;
tune0[6].val = 0xa0 | shf_tab[i].shf_dir;
break;
}
}
ret = raw_write(state, (u8 *) tune0, sizeof(tune0));
if (ret < 0)
goto failed;
usleep_range(3000, 4000);
f = freq / 1000000;
tmp = freq % 1000000;
div = 1000000;
for (i = 0; i < 6; i++) {
f <<= 1;
div >>= 1;
if (tmp > div) {
tmp -= div;
f |= 1;
}
}
if (tmp > 7812)
f++;
tune1[0].val = f & 0xff;
tune1[1].val = f >> 8;
ret = raw_write(state, (u8 *) tune1, sizeof(tune1));
if (ret < 0)
goto failed;
msleep(31);
ret = reg_write(state, 0x1a, 0x0d);
if (ret < 0)
goto failed;
ret = raw_write(state, (u8 *) set_idac, sizeof(set_idac));
if (ret < 0)
goto failed;
return 0;
failed:
dev_warn(&state->i2c->dev, "(%s) failed. [adap%d-fe%d]\n",
__func__, fe->dvb->num, fe->id);
return ret;
}
static int mxl301rf_sleep(struct dvb_frontend *fe)
{
struct mxl301rf_state *state;
int ret;
state = fe->tuner_priv;
ret = raw_write(state, (u8 *)standby_data, sizeof(standby_data));
if (ret < 0)
dev_warn(&state->i2c->dev, "(%s) failed. [adap%d-fe%d]\n",
__func__, fe->dvb->num, fe->id);
return ret;
}
static int mxl301rf_init(struct dvb_frontend *fe)
{
struct mxl301rf_state *state;
int ret;
state = fe->tuner_priv;
ret = reg_write(state, 0x01, 0x01);
if (ret < 0) {
dev_warn(&state->i2c->dev, "(%s) failed. [adap%d-fe%d]\n",
__func__, fe->dvb->num, fe->id);
return ret;
}
return 0;
}
static int mxl301rf_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mxl301rf_state *state;
struct mxl301rf_config *cfg;
struct dvb_frontend *fe;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return -ENOMEM;
state->i2c = client;
cfg = client->dev.platform_data;
memcpy(&state->cfg, cfg, sizeof(state->cfg));
fe = cfg->fe;
fe->tuner_priv = state;
memcpy(&fe->ops.tuner_ops, &mxl301rf_ops, sizeof(mxl301rf_ops));
i2c_set_clientdata(client, &state->cfg);
dev_info(&client->dev, "MaxLinear MxL301RF attached.\n");
return 0;
}
static int mxl301rf_remove(struct i2c_client *client)
{
struct mxl301rf_state *state;
state = cfg_to_state(i2c_get_clientdata(client));
state->cfg.fe->tuner_priv = NULL;
kfree(state);
return 0;
}
