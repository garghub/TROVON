static int hdcs_reg_write_seq(struct sd *sd, u8 reg, u8 *vals, u8 len)
{
u8 regs[I2C_MAX_BYTES * 2];
int i;
if (unlikely((len <= 0) || (len >= I2C_MAX_BYTES) ||
(reg + len > 0xff)))
return -EINVAL;
for (i = 0; i < len; i++) {
regs[2 * i] = reg;
regs[2 * i + 1] = vals[i];
reg += 2;
}
return stv06xx_write_sensor_bytes(sd, regs, len);
}
static int hdcs_set_state(struct sd *sd, enum hdcs_power_state state)
{
struct hdcs *hdcs = sd->sensor_priv;
u8 val;
int ret;
if (hdcs->state == state)
return 0;
if (hdcs->state != HDCS_STATE_IDLE) {
ret = stv06xx_write_sensor(sd, HDCS_REG_CONTROL(sd), 0);
if (ret)
return ret;
}
hdcs->state = HDCS_STATE_IDLE;
if (state == HDCS_STATE_IDLE)
return 0;
switch (state) {
case HDCS_STATE_SLEEP:
val = HDCS_SLEEP_MODE;
break;
case HDCS_STATE_RUN:
val = HDCS_RUN_ENABLE;
break;
default:
return -EINVAL;
}
ret = stv06xx_write_sensor(sd, HDCS_REG_CONTROL(sd), val);
if (!ret)
hdcs->state = state;
return ret;
}
static int hdcs_reset(struct sd *sd)
{
struct hdcs *hdcs = sd->sensor_priv;
int err;
err = stv06xx_write_sensor(sd, HDCS_REG_CONTROL(sd), 1);
if (err < 0)
return err;
err = stv06xx_write_sensor(sd, HDCS_REG_CONTROL(sd), 0);
if (err < 0)
hdcs->state = HDCS_STATE_IDLE;
return err;
}
static int hdcs_get_exposure(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
struct hdcs *hdcs = sd->sensor_priv;
*val = hdcs->exp_cache;
return 0;
}
static int hdcs_set_exposure(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
struct hdcs *hdcs = sd->sensor_priv;
int rowexp, srowexp;
int max_srowexp;
int ct;
int cp;
int rp;
int mnct;
int cycles, err;
u8 exp[14];
val &= 0xff;
hdcs->exp_cache = val;
cycles = val * HDCS_CLK_FREQ_MHZ * 257;
ct = hdcs->exp.cto + hdcs->psmp + (HDCS_ADC_START_SIG_DUR + 2);
cp = hdcs->exp.cto + (hdcs->w * ct / 2);
rp = hdcs->exp.rs + cp;
rowexp = cycles / rp;
cycles -= rowexp * rp;
if (IS_1020(sd)) {
srowexp = hdcs->w - (cycles + hdcs->exp.er + 13) / ct;
mnct = (hdcs->exp.er + 12 + ct - 1) / ct;
max_srowexp = hdcs->w - mnct;
} else {
srowexp = cp - hdcs->exp.er - 6 - cycles;
mnct = (hdcs->exp.er + 5 + ct - 1) / ct;
max_srowexp = cp - mnct * ct - 1;
}
if (srowexp < 0)
srowexp = 0;
else if (srowexp > max_srowexp)
srowexp = max_srowexp;
if (IS_1020(sd)) {
exp[0] = HDCS20_CONTROL;
exp[1] = 0x00;
exp[2] = HDCS_ROWEXPL;
exp[3] = rowexp & 0xff;
exp[4] = HDCS_ROWEXPH;
exp[5] = rowexp >> 8;
exp[6] = HDCS20_SROWEXP;
exp[7] = (srowexp >> 2) & 0xff;
exp[8] = HDCS20_ERROR;
exp[9] = 0x10;
exp[10] = HDCS20_CONTROL;
exp[11] = 0x04;
err = stv06xx_write_sensor_bytes(sd, exp, 6);
} else {
exp[0] = HDCS00_CONTROL;
exp[1] = 0x00;
exp[2] = HDCS_ROWEXPL;
exp[3] = rowexp & 0xff;
exp[4] = HDCS_ROWEXPH;
exp[5] = rowexp >> 8;
exp[6] = HDCS00_SROWEXPL;
exp[7] = srowexp & 0xff;
exp[8] = HDCS00_SROWEXPH;
exp[9] = srowexp >> 8;
exp[10] = HDCS_STATUS;
exp[11] = 0x10;
exp[12] = HDCS00_CONTROL;
exp[13] = 0x04;
err = stv06xx_write_sensor_bytes(sd, exp, 7);
if (err < 0)
return err;
}
PDEBUG(D_V4L2, "Writing exposure %d, rowexp %d, srowexp %d",
val, rowexp, srowexp);
return err;
}
static int hdcs_set_gains(struct sd *sd, u8 g)
{
struct hdcs *hdcs = sd->sensor_priv;
int err;
u8 gains[4];
hdcs->gain_cache = g;
if (g > 127)
g = 0x80 | (g / 2);
gains[0] = g;
gains[1] = g;
gains[2] = g;
gains[3] = g;
err = hdcs_reg_write_seq(sd, HDCS_ERECPGA, gains, 4);
return err;
}
static int hdcs_get_gain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
struct hdcs *hdcs = sd->sensor_priv;
*val = hdcs->gain_cache;
return 0;
}
static int hdcs_set_gain(struct gspca_dev *gspca_dev, __s32 val)
{
PDEBUG(D_V4L2, "Writing gain %d", val);
return hdcs_set_gains((struct sd *) gspca_dev,
val & 0xff);
}
static int hdcs_set_size(struct sd *sd,
unsigned int width, unsigned int height)
{
struct hdcs *hdcs = sd->sensor_priv;
u8 win[4];
unsigned int x, y;
int err;
width = (width + 3) & ~0x3;
height = (height + 3) & ~0x3;
if (width > hdcs->array.width)
width = hdcs->array.width;
if (IS_1020(sd)) {
if (height + 2 * hdcs->array.border + HDCS_1020_BOTTOM_Y_SKIP
> hdcs->array.height)
height = hdcs->array.height - 2 * hdcs->array.border -
HDCS_1020_BOTTOM_Y_SKIP;
y = (hdcs->array.height - HDCS_1020_BOTTOM_Y_SKIP - height) / 2
+ hdcs->array.top;
} else {
if (height > hdcs->array.height)
height = hdcs->array.height;
y = hdcs->array.top + (hdcs->array.height - height) / 2;
}
x = hdcs->array.left + (hdcs->array.width - width) / 2;
win[0] = y / 4;
win[1] = x / 4;
win[2] = (y + height) / 4 - 1;
win[3] = (x + width) / 4 - 1;
err = hdcs_reg_write_seq(sd, HDCS_FWROW, win, 4);
if (err < 0)
return err;
hdcs->w = width;
hdcs->h = height;
return err;
}
static int hdcs_probe_1x00(struct sd *sd)
{
struct hdcs *hdcs;
u16 sensor;
int ret;
ret = stv06xx_read_sensor(sd, HDCS_IDENT, &sensor);
if (ret < 0 || sensor != 0x08)
return -ENODEV;
pr_info("HDCS-1000/1100 sensor detected\n");
sd->gspca_dev.cam.cam_mode = hdcs1x00_mode;
sd->gspca_dev.cam.nmodes = ARRAY_SIZE(hdcs1x00_mode);
sd->desc.ctrls = hdcs1x00_ctrl;
sd->desc.nctrls = ARRAY_SIZE(hdcs1x00_ctrl);
hdcs = kmalloc(sizeof(struct hdcs), GFP_KERNEL);
if (!hdcs)
return -ENOMEM;
hdcs->array.left = 8;
hdcs->array.top = 8;
hdcs->array.width = HDCS_1X00_DEF_WIDTH;
hdcs->array.height = HDCS_1X00_DEF_HEIGHT;
hdcs->array.border = 4;
hdcs->exp.cto = 4;
hdcs->exp.cpo = 2;
hdcs->exp.rs = 186;
hdcs->exp.er = 100;
hdcs->psmp = (sd->bridge == BRIDGE_STV602) ? 20 : 5;
sd->sensor_priv = hdcs;
return 0;
}
static int hdcs_probe_1020(struct sd *sd)
{
struct hdcs *hdcs;
u16 sensor;
int ret;
ret = stv06xx_read_sensor(sd, HDCS_IDENT, &sensor);
if (ret < 0 || sensor != 0x10)
return -ENODEV;
pr_info("HDCS-1020 sensor detected\n");
sd->gspca_dev.cam.cam_mode = hdcs1020_mode;
sd->gspca_dev.cam.nmodes = ARRAY_SIZE(hdcs1020_mode);
sd->desc.ctrls = hdcs1020_ctrl;
sd->desc.nctrls = ARRAY_SIZE(hdcs1020_ctrl);
hdcs = kmalloc(sizeof(struct hdcs), GFP_KERNEL);
if (!hdcs)
return -ENOMEM;
hdcs->array.left = 24;
hdcs->array.top = 4;
hdcs->array.width = HDCS_1020_DEF_WIDTH;
hdcs->array.height = 304;
hdcs->array.border = 4;
hdcs->psmp = 6;
hdcs->exp.cto = 3;
hdcs->exp.cpo = 3;
hdcs->exp.rs = 155;
hdcs->exp.er = 96;
sd->sensor_priv = hdcs;
return 0;
}
static int hdcs_start(struct sd *sd)
{
PDEBUG(D_STREAM, "Starting stream");
return hdcs_set_state(sd, HDCS_STATE_RUN);
}
static int hdcs_stop(struct sd *sd)
{
PDEBUG(D_STREAM, "Halting stream");
return hdcs_set_state(sd, HDCS_STATE_SLEEP);
}
static void hdcs_disconnect(struct sd *sd)
{
PDEBUG(D_PROBE, "Disconnecting the sensor");
kfree(sd->sensor_priv);
}
static int hdcs_init(struct sd *sd)
{
struct hdcs *hdcs = sd->sensor_priv;
int i, err = 0;
if (sd->bridge == BRIDGE_STV602)
stv06xx_write_bridge(sd, STV_STV0600_EMULATION, 1);
for (i = 0; i < ARRAY_SIZE(stv_bridge_init) && !err; i++) {
err = stv06xx_write_bridge(sd, stv_bridge_init[i][0],
stv_bridge_init[i][1]);
}
if (err < 0)
return err;
hdcs_reset(sd);
for (i = 0; i < ARRAY_SIZE(stv_sensor_init) && !err; i++) {
err = stv06xx_write_sensor(sd, stv_sensor_init[i][0],
stv_sensor_init[i][1]);
}
if (err < 0)
return err;
err = stv06xx_write_sensor(sd, HDCS_REG_CONFIG(sd), BIT(3));
if (err < 0)
return err;
if (IS_1020(sd))
err = stv06xx_write_sensor(sd, HDCS_TCTRL,
(HDCS_ADC_START_SIG_DUR << 6) | hdcs->psmp);
else
err = stv06xx_write_sensor(sd, HDCS_TCTRL,
(HDCS_ADC_START_SIG_DUR << 5) | hdcs->psmp);
if (err < 0)
return err;
err = hdcs_set_gains(sd, HDCS_DEFAULT_GAIN);
if (err < 0)
return err;
err = hdcs_set_size(sd, hdcs->array.width, hdcs->array.height);
if (err < 0)
return err;
err = hdcs_set_exposure(&sd->gspca_dev, HDCS_DEFAULT_EXPOSURE);
return err;
}
static int hdcs_dump(struct sd *sd)
{
u16 reg, val;
pr_info("Dumping sensor registers:\n");
for (reg = HDCS_IDENT; reg <= HDCS_ROWEXPH; reg++) {
stv06xx_read_sensor(sd, reg, &val);
pr_info("reg 0x%02x = 0x%02x\n", reg, val);
}
return 0;
}
