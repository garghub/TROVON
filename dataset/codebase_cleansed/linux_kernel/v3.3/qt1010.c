static int qt1010_readreg(struct qt1010_priv *priv, u8 reg, u8 *val)
{
struct i2c_msg msg[2] = {
{ .addr = priv->cfg->i2c_address,
.flags = 0, .buf = &reg, .len = 1 },
{ .addr = priv->cfg->i2c_address,
.flags = I2C_M_RD, .buf = val, .len = 1 },
};
if (i2c_transfer(priv->i2c, msg, 2) != 2) {
printk(KERN_WARNING "qt1010 I2C read failed\n");
return -EREMOTEIO;
}
return 0;
}
static int qt1010_writereg(struct qt1010_priv *priv, u8 reg, u8 val)
{
u8 buf[2] = { reg, val };
struct i2c_msg msg = { .addr = priv->cfg->i2c_address,
.flags = 0, .buf = buf, .len = 2 };
if (i2c_transfer(priv->i2c, &msg, 1) != 1) {
printk(KERN_WARNING "qt1010 I2C write failed\n");
return -EREMOTEIO;
}
return 0;
}
static void qt1010_dump_regs(struct qt1010_priv *priv)
{
u8 reg, val;
for (reg = 0; ; reg++) {
if (reg % 16 == 0) {
if (reg)
printk(KERN_CONT "\n");
printk(KERN_DEBUG "%02x:", reg);
}
if (qt1010_readreg(priv, reg, &val) == 0)
printk(KERN_CONT " %02x", val);
else
printk(KERN_CONT " --");
if (reg == 0x2f)
break;
}
printk(KERN_CONT "\n");
}
static int qt1010_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct qt1010_priv *priv;
int err;
u32 freq, div, mod1, mod2;
u8 i, tmpval, reg05;
qt1010_i2c_oper_t rd[48] = {
{ QT1010_WR, 0x01, 0x80 },
{ QT1010_WR, 0x02, 0x3f },
{ QT1010_WR, 0x05, 0xff },
{ QT1010_WR, 0x06, 0x44 },
{ QT1010_WR, 0x07, 0xff },
{ QT1010_WR, 0x08, 0x08 },
{ QT1010_WR, 0x09, 0xff },
{ QT1010_WR, 0x0a, 0xff },
{ QT1010_WR, 0x0b, 0xff },
{ QT1010_WR, 0x0c, 0xe1 },
{ QT1010_WR, 0x1a, 0xff },
{ QT1010_WR, 0x1b, 0x00 },
{ QT1010_WR, 0x1c, 0x89 },
{ QT1010_WR, 0x11, 0xff },
{ QT1010_WR, 0x12, 0xff },
{ QT1010_WR, 0x22, 0xff },
{ QT1010_WR, 0x1e, 0x00 },
{ QT1010_WR, 0x1e, 0xd0 },
{ QT1010_RD, 0x22, 0xff },
{ QT1010_WR, 0x1e, 0x00 },
{ QT1010_RD, 0x05, 0xff },
{ QT1010_RD, 0x22, 0xff },
{ QT1010_WR, 0x23, 0xd0 },
{ QT1010_WR, 0x1e, 0x00 },
{ QT1010_WR, 0x1e, 0xe0 },
{ QT1010_RD, 0x23, 0xff },
{ QT1010_RD, 0x23, 0xff },
{ QT1010_WR, 0x1e, 0x00 },
{ QT1010_WR, 0x24, 0xd0 },
{ QT1010_WR, 0x1e, 0x00 },
{ QT1010_WR, 0x1e, 0xf0 },
{ QT1010_RD, 0x24, 0xff },
{ QT1010_WR, 0x1e, 0x00 },
{ QT1010_WR, 0x14, 0x7f },
{ QT1010_WR, 0x15, 0x7f },
{ QT1010_WR, 0x05, 0xff },
{ QT1010_WR, 0x06, 0x00 },
{ QT1010_WR, 0x15, 0x1f },
{ QT1010_WR, 0x16, 0xff },
{ QT1010_WR, 0x18, 0xff },
{ QT1010_WR, 0x1f, 0xff },
{ QT1010_WR, 0x20, 0xff },
{ QT1010_WR, 0x21, 0x53 },
{ QT1010_WR, 0x25, 0xff },
{ QT1010_WR, 0x26, 0x15 },
{ QT1010_WR, 0x00, 0xff },
{ QT1010_WR, 0x02, 0x00 },
{ QT1010_WR, 0x01, 0x00 }
};
#define FREQ1 32000000
#define FREQ2 4000000
priv = fe->tuner_priv;
freq = c->frequency;
div = (freq + QT1010_OFFSET) / QT1010_STEP;
freq = (div * QT1010_STEP) - QT1010_OFFSET;
mod1 = (freq + QT1010_OFFSET) % FREQ1;
mod2 = (freq + QT1010_OFFSET) % FREQ2;
priv->frequency = freq;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (freq < 290000000) reg05 = 0x14;
else if (freq < 610000000) reg05 = 0x34;
else if (freq < 802000000) reg05 = 0x54;
else reg05 = 0x74;
rd[2].val = reg05;
rd[4].val = (freq + QT1010_OFFSET) / FREQ1;
if (mod1 < 8000000) rd[6].val = 0x1d;
else rd[6].val = 0x1c;
if (mod1 < 1*FREQ2) rd[7].val = 0x09;
else if (mod1 < 2*FREQ2) rd[7].val = 0x08;
else if (mod1 < 3*FREQ2) rd[7].val = 0x0f;
else if (mod1 < 4*FREQ2) rd[7].val = 0x0e;
else if (mod1 < 5*FREQ2) rd[7].val = 0x0d;
else if (mod1 < 6*FREQ2) rd[7].val = 0x0c;
else if (mod1 < 7*FREQ2) rd[7].val = 0x0b;
else rd[7].val = 0x0a;
if (mod2 < 2000000) rd[8].val = 0x45;
else rd[8].val = 0x44;
tmpval = 0x78;
rd[10].val = tmpval-((mod2/QT1010_STEP)*0x08);
rd[13].val = 0xfd;
rd[14].val = 0x91;
if (freq < 450000000) rd[15].val = 0xd0;
else if (freq < 482000000) rd[15].val = 0xd1;
else if (freq < 514000000) rd[15].val = 0xd4;
else if (freq < 546000000) rd[15].val = 0xd7;
else if (freq < 610000000) rd[15].val = 0xda;
else rd[15].val = 0xd0;
rd[35].val = (reg05 & 0xf0);
if (mod1 < 8000000) tmpval = 0x00;
else if (mod1 < 12000000) tmpval = 0x01;
else if (mod1 < 16000000) tmpval = 0x02;
else if (mod1 < 24000000) tmpval = 0x03;
else if (mod1 < 28000000) tmpval = 0x04;
else tmpval = 0x05;
rd[40].val = (priv->reg1f_init_val + 0x0e + tmpval);
if (mod1 < 8000000) tmpval = 0x00;
else if (mod1 < 12000000) tmpval = 0x01;
else if (mod1 < 20000000) tmpval = 0x02;
else if (mod1 < 24000000) tmpval = 0x03;
else if (mod1 < 28000000) tmpval = 0x04;
else tmpval = 0x05;
rd[41].val = (priv->reg20_init_val + 0x0d + tmpval);
rd[43].val = priv->reg25_init_val;
rd[45].val = 0x92;
dprintk("freq:%u 05:%02x 07:%02x 09:%02x 0a:%02x 0b:%02x " \
"1a:%02x 11:%02x 12:%02x 22:%02x 05:%02x 1f:%02x " \
"20:%02x 25:%02x 00:%02x", \
freq, rd[2].val, rd[4].val, rd[6].val, rd[7].val, rd[8].val, \
rd[10].val, rd[13].val, rd[14].val, rd[15].val, rd[35].val, \
rd[40].val, rd[41].val, rd[43].val, rd[45].val);
for (i = 0; i < ARRAY_SIZE(rd); i++) {
if (rd[i].oper == QT1010_WR) {
err = qt1010_writereg(priv, rd[i].reg, rd[i].val);
} else {
err = qt1010_readreg(priv, rd[i].reg, &tmpval);
}
if (err) return err;
}
if (debug)
qt1010_dump_regs(priv);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return 0;
}
static int qt1010_init_meas1(struct qt1010_priv *priv,
u8 oper, u8 reg, u8 reg_init_val, u8 *retval)
{
u8 i, val1, val2;
int err;
qt1010_i2c_oper_t i2c_data[] = {
{ QT1010_WR, reg, reg_init_val },
{ QT1010_WR, 0x1e, 0x00 },
{ QT1010_WR, 0x1e, oper },
{ QT1010_RD, reg, 0xff }
};
for (i = 0; i < ARRAY_SIZE(i2c_data); i++) {
if (i2c_data[i].oper == QT1010_WR) {
err = qt1010_writereg(priv, i2c_data[i].reg,
i2c_data[i].val);
} else {
err = qt1010_readreg(priv, i2c_data[i].reg, &val2);
}
if (err) return err;
}
do {
val1 = val2;
err = qt1010_readreg(priv, reg, &val2);
if (err) return err;
dprintk("compare reg:%02x %02x %02x", reg, val1, val2);
} while (val1 != val2);
*retval = val1;
return qt1010_writereg(priv, 0x1e, 0x00);
}
static u8 qt1010_init_meas2(struct qt1010_priv *priv,
u8 reg_init_val, u8 *retval)
{
u8 i, val;
int err;
qt1010_i2c_oper_t i2c_data[] = {
{ QT1010_WR, 0x07, reg_init_val },
{ QT1010_WR, 0x22, 0xd0 },
{ QT1010_WR, 0x1e, 0x00 },
{ QT1010_WR, 0x1e, 0xd0 },
{ QT1010_RD, 0x22, 0xff },
{ QT1010_WR, 0x1e, 0x00 },
{ QT1010_WR, 0x22, 0xff }
};
for (i = 0; i < ARRAY_SIZE(i2c_data); i++) {
if (i2c_data[i].oper == QT1010_WR) {
err = qt1010_writereg(priv, i2c_data[i].reg,
i2c_data[i].val);
} else {
err = qt1010_readreg(priv, i2c_data[i].reg, &val);
}
if (err) return err;
}
*retval = val;
return 0;
}
static int qt1010_init(struct dvb_frontend *fe)
{
struct qt1010_priv *priv = fe->tuner_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int err = 0;
u8 i, tmpval, *valptr = NULL;
qt1010_i2c_oper_t i2c_data[] = {
{ QT1010_WR, 0x01, 0x80 },
{ QT1010_WR, 0x0d, 0x84 },
{ QT1010_WR, 0x0e, 0xb7 },
{ QT1010_WR, 0x2a, 0x23 },
{ QT1010_WR, 0x2c, 0xdc },
{ QT1010_M1, 0x25, 0x40 },
{ QT1010_M1, 0x81, 0xff },
{ QT1010_WR, 0x2b, 0x70 },
{ QT1010_WR, 0x2a, 0x23 },
{ QT1010_M1, 0x26, 0x08 },
{ QT1010_M1, 0x82, 0xff },
{ QT1010_WR, 0x05, 0x14 },
{ QT1010_WR, 0x06, 0x44 },
{ QT1010_WR, 0x07, 0x28 },
{ QT1010_WR, 0x08, 0x0b },
{ QT1010_WR, 0x11, 0xfd },
{ QT1010_M1, 0x22, 0x0d },
{ QT1010_M1, 0xd0, 0xff },
{ QT1010_WR, 0x06, 0x40 },
{ QT1010_WR, 0x16, 0xf0 },
{ QT1010_WR, 0x02, 0x38 },
{ QT1010_WR, 0x03, 0x18 },
{ QT1010_WR, 0x20, 0xe0 },
{ QT1010_M1, 0x1f, 0x20 },
{ QT1010_M1, 0x84, 0xff },
{ QT1010_RD, 0x20, 0x20 },
{ QT1010_WR, 0x03, 0x19 },
{ QT1010_WR, 0x02, 0x3f },
{ QT1010_WR, 0x21, 0x53 },
{ QT1010_RD, 0x21, 0xff },
{ QT1010_WR, 0x11, 0xfd },
{ QT1010_WR, 0x05, 0x34 },
{ QT1010_WR, 0x06, 0x44 },
{ QT1010_WR, 0x08, 0x08 }
};
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
for (i = 0; i < ARRAY_SIZE(i2c_data); i++) {
switch (i2c_data[i].oper) {
case QT1010_WR:
err = qt1010_writereg(priv, i2c_data[i].reg,
i2c_data[i].val);
break;
case QT1010_RD:
if (i2c_data[i].val == 0x20)
valptr = &priv->reg20_init_val;
else
valptr = &tmpval;
err = qt1010_readreg(priv, i2c_data[i].reg, valptr);
break;
case QT1010_M1:
if (i2c_data[i].val == 0x25)
valptr = &priv->reg25_init_val;
else if (i2c_data[i].val == 0x1f)
valptr = &priv->reg1f_init_val;
else
valptr = &tmpval;
err = qt1010_init_meas1(priv, i2c_data[i+1].reg,
i2c_data[i].reg,
i2c_data[i].val, valptr);
i++;
break;
}
if (err) return err;
}
for (i = 0x31; i < 0x3a; i++)
if ((err = qt1010_init_meas2(priv, i, &tmpval)))
return err;
c->frequency = 545000000;
return qt1010_set_params(fe);
}
static int qt1010_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
static int qt1010_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct qt1010_priv *priv = fe->tuner_priv;
*frequency = priv->frequency;
return 0;
}
static int qt1010_get_if_frequency(struct dvb_frontend *fe, u32 *frequency)
{
*frequency = 36125000;
return 0;
}
struct dvb_frontend * qt1010_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c,
struct qt1010_config *cfg)
{
struct qt1010_priv *priv = NULL;
u8 id;
priv = kzalloc(sizeof(struct qt1010_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
priv->cfg = cfg;
priv->i2c = i2c;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (qt1010_readreg(priv, 0x29, &id) != 0 || (id != 0x39)) {
kfree(priv);
return NULL;
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
printk(KERN_INFO "Quantek QT1010 successfully identified.\n");
memcpy(&fe->ops.tuner_ops, &qt1010_tuner_ops,
sizeof(struct dvb_tuner_ops));
fe->tuner_priv = priv;
return fe;
}
