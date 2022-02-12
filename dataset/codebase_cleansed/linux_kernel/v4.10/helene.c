static void helene_i2c_debug(struct helene_priv *priv,
u8 reg, u8 write, const u8 *data, u32 len)
{
dev_dbg(&priv->i2c->dev, "helene: I2C %s reg 0x%02x size %d\n",
(write == 0 ? "read" : "write"), reg, len);
print_hex_dump_bytes("helene: I2C data: ",
DUMP_PREFIX_OFFSET, data, len);
}
static int helene_write_regs(struct helene_priv *priv,
u8 reg, const u8 *data, u32 len)
{
int ret;
u8 buf[MAX_WRITE_REGSIZE + 1];
struct i2c_msg msg[1] = {
{
.addr = priv->i2c_address,
.flags = 0,
.len = len + 1,
.buf = buf,
}
};
if (len + 1 > sizeof(buf)) {
dev_warn(&priv->i2c->dev,
"wr reg=%04x: len=%d vs %Zu is too big!\n",
reg, len + 1, sizeof(buf));
return -E2BIG;
}
helene_i2c_debug(priv, reg, 1, data, len);
buf[0] = reg;
memcpy(&buf[1], data, len);
ret = i2c_transfer(priv->i2c, msg, 1);
if (ret >= 0 && ret != 1)
ret = -EREMOTEIO;
if (ret < 0) {
dev_warn(&priv->i2c->dev,
"%s: i2c wr failed=%d reg=%02x len=%d\n",
KBUILD_MODNAME, ret, reg, len);
return ret;
}
return 0;
}
static int helene_write_reg(struct helene_priv *priv, u8 reg, u8 val)
{
return helene_write_regs(priv, reg, &val, 1);
}
static int helene_read_regs(struct helene_priv *priv,
u8 reg, u8 *val, u32 len)
{
int ret;
struct i2c_msg msg[2] = {
{
.addr = priv->i2c_address,
.flags = 0,
.len = 1,
.buf = &reg,
}, {
.addr = priv->i2c_address,
.flags = I2C_M_RD,
.len = len,
.buf = val,
}
};
ret = i2c_transfer(priv->i2c, &msg[0], 1);
if (ret >= 0 && ret != 1)
ret = -EREMOTEIO;
if (ret < 0) {
dev_warn(&priv->i2c->dev,
"%s: I2C rw failed=%d addr=%02x reg=%02x\n",
KBUILD_MODNAME, ret, priv->i2c_address, reg);
return ret;
}
ret = i2c_transfer(priv->i2c, &msg[1], 1);
if (ret >= 0 && ret != 1)
ret = -EREMOTEIO;
if (ret < 0) {
dev_warn(&priv->i2c->dev,
"%s: i2c rd failed=%d addr=%02x reg=%02x\n",
KBUILD_MODNAME, ret, priv->i2c_address, reg);
return ret;
}
helene_i2c_debug(priv, reg, 0, val, len);
return 0;
}
static int helene_read_reg(struct helene_priv *priv, u8 reg, u8 *val)
{
return helene_read_regs(priv, reg, val, 1);
}
static int helene_set_reg_bits(struct helene_priv *priv,
u8 reg, u8 data, u8 mask)
{
int res;
u8 rdata;
if (mask != 0xff) {
res = helene_read_reg(priv, reg, &rdata);
if (res != 0)
return res;
data = ((data & mask) | (rdata & (mask ^ 0xFF)));
}
return helene_write_reg(priv, reg, data);
}
static int helene_enter_power_save(struct helene_priv *priv)
{
dev_dbg(&priv->i2c->dev, "%s()\n", __func__);
if (priv->state == STATE_SLEEP)
return 0;
helene_write_reg(priv, 0x88, 0x0);
helene_write_reg(priv, 0x87, 0xC0);
priv->state = STATE_SLEEP;
return 0;
}
static int helene_leave_power_save(struct helene_priv *priv)
{
dev_dbg(&priv->i2c->dev, "%s()\n", __func__);
if (priv->state == STATE_ACTIVE)
return 0;
helene_write_reg(priv, 0x87, 0xC4);
helene_write_reg(priv, 0x88, 0x40);
priv->state = STATE_ACTIVE;
return 0;
}
static int helene_init(struct dvb_frontend *fe)
{
struct helene_priv *priv = fe->tuner_priv;
dev_dbg(&priv->i2c->dev, "%s()\n", __func__);
return helene_leave_power_save(priv);
}
static void helene_release(struct dvb_frontend *fe)
{
struct helene_priv *priv = fe->tuner_priv;
dev_dbg(&priv->i2c->dev, "%s()\n", __func__);
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
}
static int helene_sleep(struct dvb_frontend *fe)
{
struct helene_priv *priv = fe->tuner_priv;
dev_dbg(&priv->i2c->dev, "%s()\n", __func__);
helene_enter_power_save(priv);
return 0;
}
static enum helene_tv_system_t helene_get_tv_system(struct dvb_frontend *fe)
{
enum helene_tv_system_t system = SONY_HELENE_TV_SYSTEM_UNKNOWN;
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct helene_priv *priv = fe->tuner_priv;
if (p->delivery_system == SYS_DVBT) {
if (p->bandwidth_hz <= 5000000)
system = SONY_HELENE_DTV_DVBT_5;
else if (p->bandwidth_hz <= 6000000)
system = SONY_HELENE_DTV_DVBT_6;
else if (p->bandwidth_hz <= 7000000)
system = SONY_HELENE_DTV_DVBT_7;
else if (p->bandwidth_hz <= 8000000)
system = SONY_HELENE_DTV_DVBT_8;
else {
system = SONY_HELENE_DTV_DVBT_8;
p->bandwidth_hz = 8000000;
}
} else if (p->delivery_system == SYS_DVBT2) {
if (p->bandwidth_hz <= 5000000)
system = SONY_HELENE_DTV_DVBT2_5;
else if (p->bandwidth_hz <= 6000000)
system = SONY_HELENE_DTV_DVBT2_6;
else if (p->bandwidth_hz <= 7000000)
system = SONY_HELENE_DTV_DVBT2_7;
else if (p->bandwidth_hz <= 8000000)
system = SONY_HELENE_DTV_DVBT2_8;
else {
system = SONY_HELENE_DTV_DVBT2_8;
p->bandwidth_hz = 8000000;
}
} else if (p->delivery_system == SYS_DVBS) {
system = SONY_HELENE_STV_DVBS;
} else if (p->delivery_system == SYS_DVBS2) {
system = SONY_HELENE_STV_DVBS2;
} else if (p->delivery_system == SYS_ISDBS) {
system = SONY_HELENE_STV_ISDBS;
} else if (p->delivery_system == SYS_ISDBT) {
if (p->bandwidth_hz <= 6000000)
system = SONY_HELENE_DTV_ISDBT_6;
else if (p->bandwidth_hz <= 7000000)
system = SONY_HELENE_DTV_ISDBT_7;
else if (p->bandwidth_hz <= 8000000)
system = SONY_HELENE_DTV_ISDBT_8;
else {
system = SONY_HELENE_DTV_ISDBT_8;
p->bandwidth_hz = 8000000;
}
} else if (p->delivery_system == SYS_DVBC_ANNEX_A) {
if (p->bandwidth_hz <= 6000000)
system = SONY_HELENE_DTV_DVBC_6;
else if (p->bandwidth_hz <= 8000000)
system = SONY_HELENE_DTV_DVBC_8;
}
dev_dbg(&priv->i2c->dev,
"%s(): HELENE DTV system %d (delsys %d, bandwidth %d)\n",
__func__, (int)system, p->delivery_system,
p->bandwidth_hz);
return system;
}
static int helene_set_params_s(struct dvb_frontend *fe)
{
u8 data[MAX_WRITE_REGSIZE];
u32 frequency;
enum helene_tv_system_t tv_system;
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct helene_priv *priv = fe->tuner_priv;
int frequencykHz = p->frequency;
uint32_t frequency4kHz = 0;
u32 symbol_rate = p->symbol_rate/1000;
dev_dbg(&priv->i2c->dev, "%s(): tune frequency %dkHz sr=%uKsps\n",
__func__, frequencykHz, symbol_rate);
tv_system = helene_get_tv_system(fe);
if (tv_system == SONY_HELENE_TV_SYSTEM_UNKNOWN) {
dev_err(&priv->i2c->dev, "%s(): unknown DTV system\n",
__func__);
return -EINVAL;
}
if (priv->set_tuner)
priv->set_tuner(priv->set_tuner_data, 0);
frequency = roundup(p->frequency / 1000, 1);
helene_write_reg(priv, 0x15, 0x02);
helene_write_reg(priv, 0x43, 0x06);
data[0] = 0x00;
data[1] = 0x00;
helene_write_regs(priv, 0x6A, data, 2);
helene_write_reg(priv, 0x75, 0x99);
helene_write_reg(priv, 0x9D, 0x00);
helene_write_reg(priv, 0x61, 0x07);
helene_write_reg(priv, 0x01, 0x01);
data[0] = 0xC4;
data[1] = 0x40;
switch (priv->xtal) {
case SONY_HELENE_XTAL_16000:
data[2] = 0x02;
break;
case SONY_HELENE_XTAL_20500:
data[2] = 0x02;
break;
case SONY_HELENE_XTAL_24000:
data[2] = 0x03;
break;
case SONY_HELENE_XTAL_41000:
data[2] = 0x05;
break;
default:
dev_err(&priv->i2c->dev, "%s(): unknown xtal %d\n",
__func__, priv->xtal);
return -EINVAL;
}
data[3] = 0x80;
if (priv->xtal == SONY_HELENE_XTAL_20500)
data[4] = 0x58;
else
data[4] = 0x70;
data[5] = 0x1E;
data[6] = 0x02;
data[7] = 0x24;
data[8] = 0x0F;
data[8] |= 0xE0;
data[9] = 0x02;
data[10] = 0x1E;
switch (tv_system) {
case SONY_HELENE_STV_ISDBS:
data[11] = 0x22;
break;
case SONY_HELENE_STV_DVBS:
if (symbol_rate <= 4000)
data[11] = 0x05;
else if (symbol_rate <= 10000)
data[11] = (uint8_t)((symbol_rate * 47
+ (40000-1)) / 40000);
else
data[11] = (uint8_t)((symbol_rate * 27
+ (40000-1)) / 40000 + 5);
if (data[11] > 36)
data[11] = 36;
break;
case SONY_HELENE_STV_DVBS2:
if (symbol_rate <= 4000)
data[11] = 0x05;
else if (symbol_rate <= 10000)
data[11] = (uint8_t)((symbol_rate * 11
+ (10000-1)) / 10000);
else
data[11] = (uint8_t)((symbol_rate * 3
+ (5000-1)) / 5000 + 5);
if (data[11] > 36)
data[11] = 36;
break;
default:
dev_err(&priv->i2c->dev, "%s(): unknown standard %d\n",
__func__, tv_system);
return -EINVAL;
}
frequency4kHz = (frequencykHz + 2) / 4;
data[12] = (uint8_t)(frequency4kHz & 0xFF);
data[13] = (uint8_t)((frequency4kHz >> 8) & 0xFF);
data[14] = (uint8_t)((frequency4kHz >> 16) & 0x0F);
data[15] = 0xFF;
data[16] = 0x00;
data[17] = 0x01;
helene_write_regs(priv, 0x04, data, 18);
dev_dbg(&priv->i2c->dev, "%s(): tune done\n",
__func__);
priv->frequency = frequency;
return 0;
}
static int helene_set_params(struct dvb_frontend *fe)
{
u8 data[MAX_WRITE_REGSIZE];
u32 frequency;
enum helene_tv_system_t tv_system;
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct helene_priv *priv = fe->tuner_priv;
int frequencykHz = p->frequency / 1000;
dev_dbg(&priv->i2c->dev, "%s(): tune frequency %dkHz\n",
__func__, frequencykHz);
tv_system = helene_get_tv_system(fe);
if (tv_system == SONY_HELENE_TV_SYSTEM_UNKNOWN) {
dev_dbg(&priv->i2c->dev, "%s(): unknown DTV system\n",
__func__);
return -EINVAL;
}
if (priv->set_tuner)
priv->set_tuner(priv->set_tuner_data, 1);
frequency = roundup(p->frequency / 1000, 25);
helene_write_reg(priv, 0x01, 0x00);
helene_write_reg(priv, 0x74, 0x02);
if (priv->state == STATE_SLEEP)
helene_leave_power_save(priv);
if ((tv_system == SONY_HELENE_DTV_DVBC_6) ||
(tv_system == SONY_HELENE_DTV_DVBC_8)) {
data[0] = 0x16;
data[1] = 0x26;
} else {
data[0] = 0x10;
data[1] = 0x20;
}
helene_write_regs(priv, 0x91, data, 2);
if (TERR_INTERNAL_LOOPFILTER_AVAILABLE(tv_system))
data[0] = 0x90;
else
data[0] = 0x00;
data[1] = (uint8_t)(terr_params[tv_system].IS_LOWERLOCAL & 0x01);
helene_write_regs(priv, 0x9C, data, 2);
data[0] = 0xEE;
data[1] = 0x02;
data[2] = 0x1E;
data[3] = 0x67;
if ((tv_system == SONY_HELENE_DTV_DVBC_6) ||
(tv_system == SONY_HELENE_DTV_DVBC_8))
data[4] = 0x18;
else
data[4] = 0x03;
if (TERR_INTERNAL_LOOPFILTER_AVAILABLE(tv_system)) {
data[5] = 0x38;
data[6] = 0x1E;
data[7] = 0x02;
data[8] = 0x24;
} else if ((tv_system == SONY_HELENE_DTV_DVBC_6) ||
(tv_system == SONY_HELENE_DTV_DVBC_8)) {
data[5] = 0x1C;
data[6] = 0x78;
data[7] = 0x08;
data[8] = 0x1C;
} else {
data[5] = 0xB4;
data[6] = 0x78;
data[7] = 0x08;
data[8] = 0x30;
}
helene_write_regs(priv, 0x5E, data, 9);
helene_set_reg_bits(priv, 0x67, 0x0, 0x02);
data[0] = 0x00;
if (terr_params[tv_system].RF_GAIN == HELENE_AUTO)
data[1] = 0x80;
else
data[1] = (uint8_t)((terr_params[tv_system].RF_GAIN
<< 4) & 0x70);
data[1] |= (uint8_t)(terr_params[tv_system].IF_BPF_GC & 0x0F);
data[2] = 0x00;
if (frequencykHz <= 172000) {
data[3] = (uint8_t)(terr_params[tv_system].RFOVLD_DET_LV1_VL
& 0x0F);
data[4] = (uint8_t)(terr_params[tv_system].IFOVLD_DET_LV_VL
& 0x07);
} else if (frequencykHz <= 464000) {
data[3] = (uint8_t)(terr_params[tv_system].RFOVLD_DET_LV1_VH
& 0x0F);
data[4] = (uint8_t)(terr_params[tv_system].IFOVLD_DET_LV_VH
& 0x07);
} else {
data[3] = (uint8_t)(terr_params[tv_system].RFOVLD_DET_LV1_U
& 0x0F);
data[4] = (uint8_t)(terr_params[tv_system].IFOVLD_DET_LV_U
& 0x07);
}
data[4] |= 0x20;
data[5] = (uint8_t)((terr_params[tv_system].IF_BPF_F0 << 4) & 0x30);
data[5] |= (uint8_t)(terr_params[tv_system].BW & 0x03);
data[6] = (uint8_t)(terr_params[tv_system].FIF_OFFSET & 0x1F);
data[7] = (uint8_t)(terr_params[tv_system].BW_OFFSET & 0x1F);
data[8] = (uint8_t)(frequencykHz & 0xFF);
data[9] = (uint8_t)((frequencykHz >> 8) & 0xFF);
data[10] = (uint8_t)((frequencykHz >> 16)
& 0x0F);
data[11] = 0xFF;
data[12] = 0x01;
if ((tv_system == SONY_HELENE_DTV_DVBC_6) ||
(tv_system == SONY_HELENE_DTV_DVBC_8)) {
data[13] = 0xD9;
data[14] = 0x0F;
data[15] = 0x24;
data[16] = 0x87;
} else {
data[13] = 0x99;
data[14] = 0x00;
data[15] = 0x24;
data[16] = 0x87;
}
helene_write_regs(priv, 0x68, data, 17);
dev_dbg(&priv->i2c->dev, "%s(): tune done\n",
__func__);
priv->frequency = frequency;
return 0;
}
static int helene_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct helene_priv *priv = fe->tuner_priv;
*frequency = priv->frequency * 1000;
return 0;
}
static int helene_x_pon(struct helene_priv *priv)
{
u8 dataT[] = { 0x06, 0x00, 0x02, 0x00 };
u8 dataS[] = { 0x05, 0x06 };
u8 cdata[] = {0x7A, 0x01};
u8 data[20];
u8 rdata[2];
helene_write_reg(priv, 0x01, 0x00);
helene_write_reg(priv, 0x67, dataT[3]);
helene_write_reg(priv, 0x43, dataS[1]);
helene_write_regs(priv, 0x5E, dataT, 3);
helene_write_reg(priv, 0x0C, dataS[0]);
helene_write_regs(priv, 0x99, cdata, sizeof(cdata));
data[0] = 0x18;
data[1] = (uint8_t)(0x80 | (0x04 & 0x1F));
data[2] = (uint8_t)(0x80 | (0x26 & 0x7F));
data[3] = 0x80;
data[4] = 0x00;
data[5] = 0x00;
data[6] = 0xC4;
data[7] = 0x40;
data[8] = 0x10;
data[9] = 0x00;
data[10] = 0x45;
data[11] = 0x75;
data[12] = 0x07;
data[13] = 0x1C;
data[14] = 0x3F;
data[15] = 0x02;
data[16] = 0x10;
data[17] = 0x20;
data[18] = 0x0A;
data[19] = 0x00;
helene_write_regs(priv, 0x81, data, sizeof(data));
helene_write_reg(priv, 0x9B, 0x00);
msleep(20);
helene_read_regs(priv, 0x1A, rdata, sizeof(rdata));
if (rdata[0] != 0x00) {
dev_err(&priv->i2c->dev,
"HELENE tuner CPU error 0x%x\n", rdata[0]);
return -EIO;
}
cdata[0] = 0x90;
cdata[1] = 0x06;
helene_write_regs(priv, 0x17, cdata, sizeof(cdata));
msleep(20);
helene_read_reg(priv, 0x19, data);
helene_write_reg(priv, 0x95, (uint8_t)((data[0] >> 4) & 0x0F));
helene_write_reg(priv, 0x74, 0x02);
helene_write_reg(priv, 0x88, 0x00);
helene_write_reg(priv, 0x87, 0xC0);
helene_write_reg(priv, 0x80, 0x01);
cdata[0] = 0x07;
cdata[1] = 0x00;
helene_write_regs(priv, 0x41, cdata, sizeof(cdata));
dev_info(&priv->i2c->dev,
"HELENE tuner x_pon done\n");
return 0;
}
struct dvb_frontend *helene_attach_s(struct dvb_frontend *fe,
const struct helene_config *config,
struct i2c_adapter *i2c)
{
struct helene_priv *priv = NULL;
priv = kzalloc(sizeof(struct helene_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
priv->i2c_address = (config->i2c_address >> 1);
priv->i2c = i2c;
priv->set_tuner_data = config->set_tuner_priv;
priv->set_tuner = config->set_tuner_callback;
priv->xtal = config->xtal;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (helene_x_pon(priv) != 0) {
kfree(priv);
return NULL;
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
memcpy(&fe->ops.tuner_ops, &helene_tuner_ops_s,
sizeof(struct dvb_tuner_ops));
fe->tuner_priv = priv;
dev_info(&priv->i2c->dev,
"Sony HELENE Sat attached on addr=%x at I2C adapter %p\n",
priv->i2c_address, priv->i2c);
return fe;
}
struct dvb_frontend *helene_attach(struct dvb_frontend *fe,
const struct helene_config *config,
struct i2c_adapter *i2c)
{
struct helene_priv *priv = NULL;
priv = kzalloc(sizeof(struct helene_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
priv->i2c_address = (config->i2c_address >> 1);
priv->i2c = i2c;
priv->set_tuner_data = config->set_tuner_priv;
priv->set_tuner = config->set_tuner_callback;
priv->xtal = config->xtal;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (helene_x_pon(priv) != 0) {
kfree(priv);
return NULL;
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
memcpy(&fe->ops.tuner_ops, &helene_tuner_ops,
sizeof(struct dvb_tuner_ops));
fe->tuner_priv = priv;
dev_info(&priv->i2c->dev,
"Sony HELENE Ter attached on addr=%x at I2C adapter %p\n",
priv->i2c_address, priv->i2c);
return fe;
}
