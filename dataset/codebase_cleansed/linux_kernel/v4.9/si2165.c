static int si2165_write(struct si2165_state *state, const u16 reg,
const u8 *src, const int count)
{
int ret;
if (debug & DEBUG_I2C_WRITE)
deb_i2c_write("reg: 0x%04x, data: %*ph\n", reg, count, src);
ret = regmap_bulk_write(state->regmap, reg, src, count);
if (ret)
dev_err(&state->client->dev, "%s: ret == %d\n", __func__, ret);
return ret;
}
static int si2165_read(struct si2165_state *state,
const u16 reg, u8 *val, const int count)
{
int ret = regmap_bulk_read(state->regmap, reg, val, count);
if (ret) {
dev_err(&state->client->dev, "%s: error (addr %02x reg %04x error (ret == %i)\n",
__func__, state->config.i2c_addr, reg, ret);
return ret;
}
if (debug & DEBUG_I2C_READ)
deb_i2c_read("reg: 0x%04x, data: %*ph\n", reg, count, val);
return 0;
}
static int si2165_readreg8(struct si2165_state *state,
const u16 reg, u8 *val)
{
unsigned int val_tmp;
int ret = regmap_read(state->regmap, reg, &val_tmp);
*val = (u8)val_tmp;
deb_readreg("R(0x%04x)=0x%02x\n", reg, *val);
return ret;
}
static int si2165_readreg16(struct si2165_state *state,
const u16 reg, u16 *val)
{
u8 buf[2];
int ret = si2165_read(state, reg, buf, 2);
*val = buf[0] | buf[1] << 8;
deb_readreg("R(0x%04x)=0x%04x\n", reg, *val);
return ret;
}
static int si2165_writereg8(struct si2165_state *state, const u16 reg, u8 val)
{
return regmap_write(state->regmap, reg, val);
}
static int si2165_writereg16(struct si2165_state *state, const u16 reg, u16 val)
{
u8 buf[2] = { val & 0xff, (val >> 8) & 0xff };
return si2165_write(state, reg, buf, 2);
}
static int si2165_writereg24(struct si2165_state *state, const u16 reg, u32 val)
{
u8 buf[3] = { val & 0xff, (val >> 8) & 0xff, (val >> 16) & 0xff };
return si2165_write(state, reg, buf, 3);
}
static int si2165_writereg32(struct si2165_state *state, const u16 reg, u32 val)
{
u8 buf[4] = {
val & 0xff,
(val >> 8) & 0xff,
(val >> 16) & 0xff,
(val >> 24) & 0xff
};
return si2165_write(state, reg, buf, 4);
}
static int si2165_writereg_mask8(struct si2165_state *state, const u16 reg,
u8 val, u8 mask)
{
if (mask != 0xff) {
u8 tmp;
int ret = si2165_readreg8(state, reg, &tmp);
if (ret < 0)
return ret;
val &= mask;
tmp &= ~mask;
val |= tmp;
}
return si2165_writereg8(state, reg, val);
}
static int si2165_write_reg_list(struct si2165_state *state,
const struct si2165_reg_value_pair *regs,
int count)
{
int i;
int ret;
for (i = 0; i < count; i++) {
ret = si2165_writereg8(state, regs[i].reg, regs[i].val);
if (ret < 0)
return ret;
}
return 0;
}
static int si2165_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *s)
{
s->min_delay_ms = 1000;
return 0;
}
static int si2165_init_pll(struct si2165_state *state)
{
u32 ref_freq_Hz = state->config.ref_freq_Hz;
u8 divr = 1;
u8 divp = 1;
u8 divn = 56;
u8 divm = 8;
u8 divl = 12;
u8 buf[4];
switch (ref_freq_Hz) {
case 16000000u:
divn = 56;
break;
case 24000000u:
divr = 2;
divp = 4;
divn = 19;
break;
default:
if (ref_freq_Hz > 16000000u)
divr = 2;
if (1624000000u * divr > ref_freq_Hz * 2u * 63u)
divp = 4;
divn = 1624000000u * divr / (ref_freq_Hz * 2u * divp);
break;
}
state->fvco_hz = ref_freq_Hz / divr
* 2u * divn * divp;
state->adc_clk = state->fvco_hz / (divm * 4u);
state->sys_clk = state->fvco_hz / (divl * 2u);
buf[0] = divl;
buf[1] = divm;
buf[2] = (divn & 0x3f) | ((divp == 1) ? 0x40 : 0x00) | 0x80;
buf[3] = divr;
return si2165_write(state, 0x00a0, buf, 4);
}
static int si2165_adjust_pll_divl(struct si2165_state *state, u8 divl)
{
state->sys_clk = state->fvco_hz / (divl * 2u);
return si2165_writereg8(state, 0x00a0, divl);
}
static u32 si2165_get_fe_clk(struct si2165_state *state)
{
return state->adc_clk;
}
static int si2165_wait_init_done(struct si2165_state *state)
{
int ret = -EINVAL;
u8 val = 0;
int i;
for (i = 0; i < 3; ++i) {
si2165_readreg8(state, 0x0054, &val);
if (val == 0x01)
return 0;
usleep_range(1000, 50000);
}
dev_err(&state->client->dev, "%s: init_done was not set\n",
KBUILD_MODNAME);
return ret;
}
static int si2165_upload_firmware_block(struct si2165_state *state,
const u8 *data, u32 len, u32 *poffset, u32 block_count)
{
int ret;
u8 buf_ctrl[4] = { 0x00, 0x00, 0x00, 0xc0 };
u8 wordcount;
u32 cur_block = 0;
u32 offset = poffset ? *poffset : 0;
if (len < 4)
return -EINVAL;
if (len % 4 != 0)
return -EINVAL;
deb_fw_load(
"si2165_upload_firmware_block called with len=0x%x offset=0x%x blockcount=0x%x\n",
len, offset, block_count);
while (offset+12 <= len && cur_block < block_count) {
deb_fw_load(
"si2165_upload_firmware_block in while len=0x%x offset=0x%x cur_block=0x%x blockcount=0x%x\n",
len, offset, cur_block, block_count);
wordcount = data[offset];
if (wordcount < 1 || data[offset+1] ||
data[offset+2] || data[offset+3]) {
dev_warn(&state->client->dev,
"%s: bad fw data[0..3] = %*ph\n",
KBUILD_MODNAME, 4, data);
return -EINVAL;
}
if (offset + 8 + wordcount * 4 > len) {
dev_warn(&state->client->dev,
"%s: len is too small for block len=%d, wordcount=%d\n",
KBUILD_MODNAME, len, wordcount);
return -EINVAL;
}
buf_ctrl[0] = wordcount - 1;
ret = si2165_write(state, 0x0364, buf_ctrl, 4);
if (ret < 0)
goto error;
ret = si2165_write(state, 0x0368, data+offset+4, 4);
if (ret < 0)
goto error;
offset += 8;
while (wordcount > 0) {
ret = si2165_write(state, 0x36c, data+offset, 4);
if (ret < 0)
goto error;
wordcount--;
offset += 4;
}
cur_block++;
}
deb_fw_load(
"si2165_upload_firmware_block after while len=0x%x offset=0x%x cur_block=0x%x blockcount=0x%x\n",
len, offset, cur_block, block_count);
if (poffset)
*poffset = offset;
deb_fw_load("si2165_upload_firmware_block returned offset=0x%x\n",
offset);
return 0;
error:
return ret;
}
static int si2165_upload_firmware(struct si2165_state *state)
{
u8 val[3];
u16 val16;
int ret;
const struct firmware *fw = NULL;
u8 *fw_file;
const u8 *data;
u32 len;
u32 offset;
u8 patch_version;
u8 block_count;
u16 crc_expected;
switch (state->chip_revcode) {
case 0x03:
fw_file = SI2165_FIRMWARE_REV_D;
break;
default:
dev_info(&state->client->dev, "%s: no firmware file for revision=%d\n",
KBUILD_MODNAME, state->chip_revcode);
return 0;
}
ret = request_firmware(&fw, fw_file, &state->client->dev);
if (ret) {
dev_warn(&state->client->dev, "%s: firmware file '%s' not found\n",
KBUILD_MODNAME, fw_file);
goto error;
}
data = fw->data;
len = fw->size;
dev_info(&state->client->dev, "%s: downloading firmware from file '%s' size=%d\n",
KBUILD_MODNAME, fw_file, len);
if (len % 4 != 0) {
dev_warn(&state->client->dev, "%s: firmware size is not multiple of 4\n",
KBUILD_MODNAME);
ret = -EINVAL;
goto error;
}
if (len < 8) {
dev_warn(&state->client->dev, "%s: firmware header is missing\n",
KBUILD_MODNAME);
ret = -EINVAL;
goto error;
}
if (data[0] != 1 || data[1] != 0) {
dev_warn(&state->client->dev, "%s: firmware file version is wrong\n",
KBUILD_MODNAME);
ret = -EINVAL;
goto error;
}
patch_version = data[2];
block_count = data[4];
crc_expected = data[7] << 8 | data[6];
ret = si2165_writereg8(state, 0x0341, 0x00);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x00c0, 0x00);
if (ret < 0)
goto error;
ret = si2165_readreg8(state, 0x0341, val);
if (ret < 0)
goto error;
ret = si2165_readreg8(state, 0x035c, val);
if (ret < 0)
goto error;
ret = si2165_readreg8(state, 0x035c, val);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x035c, 0x02);
if (ret < 0)
goto error;
offset = 8;
dev_info(&state->client->dev, "%s: si2165_upload_firmware extracted patch_version=0x%02x, block_count=0x%02x, crc_expected=0x%04x\n",
KBUILD_MODNAME, patch_version, block_count, crc_expected);
ret = si2165_upload_firmware_block(state, data, len, &offset, 1);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x0344, patch_version);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x0379, 0x01);
if (ret)
goto error;
ret = si2165_upload_firmware_block(state, data, len,
&offset, block_count);
if (ret < 0) {
dev_err(&state->client->dev,
"%s: firmware could not be uploaded\n",
KBUILD_MODNAME);
goto error;
}
ret = si2165_readreg16(state, 0x037a, &val16);
if (ret)
goto error;
if (val16 != crc_expected) {
dev_err(&state->client->dev,
"%s: firmware crc mismatch %04x != %04x\n",
KBUILD_MODNAME, val16, crc_expected);
ret = -EINVAL;
goto error;
}
ret = si2165_upload_firmware_block(state, data, len, &offset, 5);
if (ret)
goto error;
if (len != offset) {
dev_err(&state->client->dev,
"%s: firmware len mismatch %04x != %04x\n",
KBUILD_MODNAME, len, offset);
ret = -EINVAL;
goto error;
}
ret = si2165_writereg_mask8(state, 0x0341, 0x02, 0x02);
if (ret < 0)
goto error;
ret = si2165_writereg_mask8(state, 0x035c, 0x01, 0x01);
if (ret < 0)
goto error;
dev_info(&state->client->dev, "%s: fw load finished\n", KBUILD_MODNAME);
ret = 0;
state->firmware_loaded = true;
error:
if (fw) {
release_firmware(fw);
fw = NULL;
}
return ret;
}
static int si2165_init(struct dvb_frontend *fe)
{
int ret = 0;
struct si2165_state *state = fe->demodulator_priv;
u8 val;
u8 patch_version = 0x00;
dprintk("%s: called\n", __func__);
ret = si2165_writereg8(state, 0x0000, state->config.chip_mode);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x0104, 0x01);
if (ret < 0)
goto error;
ret = si2165_readreg8(state, 0x0000, &val);
if (ret < 0)
goto error;
if (val != state->config.chip_mode) {
dev_err(&state->client->dev, "%s: could not set chip_mode\n",
KBUILD_MODNAME);
return -EINVAL;
}
ret = si2165_writereg8(state, 0x018b, 0x00);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x0190, 0x01);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x0170, 0x00);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x0171, 0x07);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x0646, 0x00);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x0641, 0x00);
if (ret < 0)
goto error;
ret = si2165_init_pll(state);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x0050, 0x01);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x0096, 0x01);
if (ret < 0)
goto error;
ret = si2165_wait_init_done(state);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x0050, 0x00);
if (ret < 0)
goto error;
ret = si2165_writereg16(state, 0x0470, 0x7530);
if (ret < 0)
goto error;
ret = si2165_readreg8(state, 0x0344, &patch_version);
if (ret < 0)
goto error;
ret = si2165_writereg8(state, 0x00cb, 0x00);
if (ret < 0)
goto error;
ret = si2165_writereg32(state, 0x0348, 0xf4000000);
if (ret < 0)
goto error;
ret = si2165_readreg8(state, 0x0341, &val);
if (ret < 0)
goto error;
if (patch_version == 0x00) {
ret = si2165_upload_firmware(state);
if (ret < 0)
goto error;
}
ret = si2165_writereg8(state, 0x04e4, 0x20);
if (ret < 0)
return ret;
ret = si2165_writereg16(state, 0x04ef, 0x00fe);
if (ret < 0)
return ret;
ret = si2165_writereg24(state, 0x04f4, 0x555555);
if (ret < 0)
return ret;
ret = si2165_writereg8(state, 0x04e5, 0x01);
if (ret < 0)
return ret;
return 0;
error:
return ret;
}
static int si2165_sleep(struct dvb_frontend *fe)
{
int ret;
struct si2165_state *state = fe->demodulator_priv;
ret = si2165_writereg8(state, 0x0104, 0x00);
if (ret < 0)
return ret;
ret = si2165_writereg8(state, 0x0000, SI2165_MODE_OFF);
if (ret < 0)
return ret;
return 0;
}
static int si2165_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
int ret;
u8 fec_lock = 0;
struct si2165_state *state = fe->demodulator_priv;
if (!state->has_dvbt)
return -EINVAL;
ret = si2165_readreg8(state, 0x4e0, &fec_lock);
if (ret < 0)
return ret;
*status = 0;
if (fec_lock & 0x01) {
*status |= FE_HAS_SIGNAL;
*status |= FE_HAS_CARRIER;
*status |= FE_HAS_VITERBI;
*status |= FE_HAS_SYNC;
*status |= FE_HAS_LOCK;
}
return 0;
}
static int si2165_set_oversamp(struct si2165_state *state, u32 dvb_rate)
{
u64 oversamp;
u32 reg_value;
if (!dvb_rate)
return -EINVAL;
oversamp = si2165_get_fe_clk(state);
oversamp <<= 23;
do_div(oversamp, dvb_rate);
reg_value = oversamp & 0x3fffffff;
dprintk("%s: Write oversamp=%#x\n", __func__, reg_value);
return si2165_writereg32(state, 0x00e4, reg_value);
}
static int si2165_set_if_freq_shift(struct si2165_state *state)
{
struct dvb_frontend *fe = &state->fe;
u64 if_freq_shift;
s32 reg_value = 0;
u32 fe_clk = si2165_get_fe_clk(state);
u32 IF = 0;
if (!fe->ops.tuner_ops.get_if_frequency) {
dev_err(&state->client->dev,
"%s: Error: get_if_frequency() not defined at tuner. Can't work without it!\n",
KBUILD_MODNAME);
return -EINVAL;
}
if (!fe_clk)
return -EINVAL;
fe->ops.tuner_ops.get_if_frequency(fe, &IF);
if_freq_shift = IF;
if_freq_shift <<= 29;
do_div(if_freq_shift, fe_clk);
reg_value = (s32)if_freq_shift;
if (state->config.inversion)
reg_value = -reg_value;
reg_value = reg_value & 0x1fffffff;
return si2165_writereg32(state, 0x00e8, reg_value);
}
static int si2165_set_frontend_dvbt(struct dvb_frontend *fe)
{
int ret;
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct si2165_state *state = fe->demodulator_priv;
u32 dvb_rate = 0;
u16 bw10k;
u32 bw_hz = p->bandwidth_hz;
dprintk("%s: called\n", __func__);
if (!state->has_dvbt)
return -EINVAL;
if (bw_hz == 0)
return -EINVAL;
dvb_rate = bw_hz * 8 / 7;
bw10k = bw_hz / 10000;
ret = si2165_adjust_pll_divl(state, 12);
if (ret < 0)
return ret;
ret = si2165_writereg16(state, 0x0308, bw10k);
if (ret < 0)
return ret;
ret = si2165_set_oversamp(state, dvb_rate);
if (ret < 0)
return ret;
ret = si2165_write_reg_list(state, dvbt_regs, ARRAY_SIZE(dvbt_regs));
if (ret < 0)
return ret;
return 0;
}
static int si2165_set_frontend_dvbc(struct dvb_frontend *fe)
{
struct si2165_state *state = fe->demodulator_priv;
int ret;
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
const u32 dvb_rate = p->symbol_rate;
const u32 bw_hz = p->bandwidth_hz;
if (!state->has_dvbc)
return -EINVAL;
if (dvb_rate == 0)
return -EINVAL;
ret = si2165_adjust_pll_divl(state, 14);
if (ret < 0)
return ret;
ret = si2165_set_oversamp(state, dvb_rate);
if (ret < 0)
return ret;
ret = si2165_writereg32(state, 0x00c4, bw_hz);
if (ret < 0)
return ret;
ret = si2165_write_reg_list(state, dvbc_regs, ARRAY_SIZE(dvbc_regs));
if (ret < 0)
return ret;
return 0;
}
static int si2165_set_frontend(struct dvb_frontend *fe)
{
struct si2165_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
u32 delsys = p->delivery_system;
int ret;
u8 val[3];
ret = si2165_set_if_freq_shift(state);
if (ret < 0)
return ret;
switch (delsys) {
case SYS_DVBT:
ret = si2165_set_frontend_dvbt(fe);
if (ret < 0)
return ret;
break;
case SYS_DVBC_ANNEX_A:
ret = si2165_set_frontend_dvbc(fe);
if (ret < 0)
return ret;
break;
default:
return -EINVAL;
}
ret = si2165_writereg32(state, 0x0348, 0xf4000000);
if (ret < 0)
return ret;
if (fe->ops.tuner_ops.set_params)
fe->ops.tuner_ops.set_params(fe);
ret = si2165_set_if_freq_shift(state);
if (ret < 0)
return ret;
ret = si2165_readreg8(state, 0x0341, val);
if (ret < 0)
return ret;
ret = si2165_writereg8(state, 0x0341, 0x00);
if (ret < 0)
return ret;
ret = si2165_writereg8(state, 0x00c0, 0x00);
if (ret < 0)
return ret;
ret = si2165_writereg32(state, 0x0384, 0x00000000);
if (ret < 0)
return ret;
ret = si2165_write_reg_list(state, agc_rewrite,
ARRAY_SIZE(agc_rewrite));
if (ret < 0)
return ret;
ret = si2165_writereg8(state, 0x02e0, 0x01);
if (ret < 0)
return ret;
ret = si2165_readreg8(state, 0x0341, val);
if (ret < 0)
return ret;
return 0;
}
static int si2165_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct si2165_state *state = NULL;
struct si2165_platform_data *pdata = client->dev.platform_data;
int n;
int ret = 0;
u8 val;
char rev_char;
const char *chip_name;
static const struct regmap_config regmap_config = {
.reg_bits = 16,
.val_bits = 8,
.max_register = 0x08ff,
};
state = kzalloc(sizeof(struct si2165_state), GFP_KERNEL);
if (state == NULL) {
ret = -ENOMEM;
goto error;
}
state->regmap = devm_regmap_init_i2c(client, &regmap_config);
if (IS_ERR(state->regmap)) {
ret = PTR_ERR(state->regmap);
goto error;
}
state->client = client;
state->config.i2c_addr = client->addr;
state->config.chip_mode = pdata->chip_mode;
state->config.ref_freq_Hz = pdata->ref_freq_Hz;
state->config.inversion = pdata->inversion;
if (state->config.ref_freq_Hz < 4000000
|| state->config.ref_freq_Hz > 27000000) {
dev_err(&state->client->dev, "%s: ref_freq of %d Hz not supported by this driver\n",
KBUILD_MODNAME, state->config.ref_freq_Hz);
ret = -EINVAL;
goto error;
}
memcpy(&state->fe.ops, &si2165_ops,
sizeof(struct dvb_frontend_ops));
state->fe.ops.release = NULL;
state->fe.demodulator_priv = state;
i2c_set_clientdata(client, state);
ret = si2165_writereg8(state, 0x0000, state->config.chip_mode);
if (ret < 0)
goto nodev_error;
ret = si2165_readreg8(state, 0x0000, &val);
if (ret < 0)
goto nodev_error;
if (val != state->config.chip_mode)
goto nodev_error;
ret = si2165_readreg8(state, 0x0023, &state->chip_revcode);
if (ret < 0)
goto nodev_error;
ret = si2165_readreg8(state, 0x0118, &state->chip_type);
if (ret < 0)
goto nodev_error;
ret = si2165_writereg8(state, 0x0000, SI2165_MODE_OFF);
if (ret < 0)
goto nodev_error;
if (state->chip_revcode < 26)
rev_char = 'A' + state->chip_revcode;
else
rev_char = '?';
switch (state->chip_type) {
case 0x06:
chip_name = "Si2161";
state->has_dvbt = true;
break;
case 0x07:
chip_name = "Si2165";
state->has_dvbt = true;
state->has_dvbc = true;
break;
default:
dev_err(&state->client->dev, "%s: Unsupported Silicon Labs chip (type %d, rev %d)\n",
KBUILD_MODNAME, state->chip_type, state->chip_revcode);
goto nodev_error;
}
dev_info(&state->client->dev,
"%s: Detected Silicon Labs %s-%c (type %d, rev %d)\n",
KBUILD_MODNAME, chip_name, rev_char, state->chip_type,
state->chip_revcode);
strlcat(state->fe.ops.info.name, chip_name,
sizeof(state->fe.ops.info.name));
n = 0;
if (state->has_dvbt) {
state->fe.ops.delsys[n++] = SYS_DVBT;
strlcat(state->fe.ops.info.name, " DVB-T",
sizeof(state->fe.ops.info.name));
}
if (state->has_dvbc) {
state->fe.ops.delsys[n++] = SYS_DVBC_ANNEX_A;
strlcat(state->fe.ops.info.name, " DVB-C",
sizeof(state->fe.ops.info.name));
}
*pdata->fe = &state->fe;
return 0;
nodev_error:
ret = -ENODEV;
error:
kfree(state);
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int si2165_remove(struct i2c_client *client)
{
struct si2165_state *state = i2c_get_clientdata(client);
dev_dbg(&client->dev, "\n");
kfree(state);
return 0;
}
