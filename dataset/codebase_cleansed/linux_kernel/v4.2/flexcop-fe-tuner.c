static int flexcop_fe_request_firmware(struct dvb_frontend *fe,
const struct firmware **fw, char *name)
{
struct flexcop_device *fc = fe->dvb->priv;
return request_firmware(fw, name, fc->dev);
}
static int flexcop_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct flexcop_device *fc = fe->dvb->priv;
flexcop_ibi_value v;
deb_tuner("polarity/voltage = %u\n", voltage);
v = fc->read_ibi_reg(fc, misc_204);
switch (voltage) {
case SEC_VOLTAGE_OFF:
v.misc_204.ACPI1_sig = 1;
break;
case SEC_VOLTAGE_13:
v.misc_204.ACPI1_sig = 0;
v.misc_204.LNB_L_H_sig = 0;
break;
case SEC_VOLTAGE_18:
v.misc_204.ACPI1_sig = 0;
v.misc_204.LNB_L_H_sig = 1;
break;
default:
err("unknown SEC_VOLTAGE value");
return -EINVAL;
}
return fc->write_ibi_reg(fc, misc_204, v);
}
static int flexcop_sleep(struct dvb_frontend* fe)
{
struct flexcop_device *fc = fe->dvb->priv;
if (fc->fe_sleep)
return fc->fe_sleep(fe);
return 0;
}
static int flexcop_set_tone(struct dvb_frontend *fe, enum fe_sec_tone_mode tone)
{
struct flexcop_device *fc = fe->dvb->priv;
flexcop_ibi_value v;
u16 ax;
v.raw = 0;
deb_tuner("tone = %u\n",tone);
switch (tone) {
case SEC_TONE_ON:
ax = 0x01ff;
break;
case SEC_TONE_OFF:
ax = 0;
break;
default:
err("unknown SEC_TONE value");
return -EINVAL;
}
v.lnb_switch_freq_200.LNB_CTLPrescaler_sig = 1;
v.lnb_switch_freq_200.LNB_CTLHighCount_sig = ax;
v.lnb_switch_freq_200.LNB_CTLLowCount_sig = ax == 0 ? 0x1ff : ax;
return fc->write_ibi_reg(fc,lnb_switch_freq_200,v);
}
static void flexcop_diseqc_send_bit(struct dvb_frontend* fe, int data)
{
flexcop_set_tone(fe, SEC_TONE_ON);
udelay(data ? 500 : 1000);
flexcop_set_tone(fe, SEC_TONE_OFF);
udelay(data ? 1000 : 500);
}
static void flexcop_diseqc_send_byte(struct dvb_frontend* fe, int data)
{
int i, par = 1, d;
for (i = 7; i >= 0; i--) {
d = (data >> i) & 1;
par ^= d;
flexcop_diseqc_send_bit(fe, d);
}
flexcop_diseqc_send_bit(fe, par);
}
static int flexcop_send_diseqc_msg(struct dvb_frontend *fe,
int len, u8 *msg, unsigned long burst)
{
int i;
flexcop_set_tone(fe, SEC_TONE_OFF);
mdelay(16);
for (i = 0; i < len; i++)
flexcop_diseqc_send_byte(fe,msg[i]);
mdelay(16);
if (burst != -1) {
if (burst)
flexcop_diseqc_send_byte(fe, 0xff);
else {
flexcop_set_tone(fe, SEC_TONE_ON);
mdelay(12);
udelay(500);
flexcop_set_tone(fe, SEC_TONE_OFF);
}
msleep(20);
}
return 0;
}
static int flexcop_diseqc_send_master_cmd(struct dvb_frontend *fe,
struct dvb_diseqc_master_cmd *cmd)
{
return flexcop_send_diseqc_msg(fe, cmd->msg_len, cmd->msg, 0);
}
static int flexcop_diseqc_send_burst(struct dvb_frontend *fe,
enum fe_sec_mini_cmd minicmd)
{
return flexcop_send_diseqc_msg(fe, 0, NULL, minicmd);
}
static int skystar2_rev23_attach(struct flexcop_device *fc,
struct i2c_adapter *i2c)
{
struct dvb_frontend_ops *ops;
fc->fe = dvb_attach(mt312_attach, &skystar23_samsung_tbdu18132_config, i2c);
if (!fc->fe)
return 0;
if (!dvb_attach(dvb_pll_attach, fc->fe, 0x61, i2c,
DVB_PLL_SAMSUNG_TBDU18132))
return 0;
ops = &fc->fe->ops;
ops->diseqc_send_master_cmd = flexcop_diseqc_send_master_cmd;
ops->diseqc_send_burst = flexcop_diseqc_send_burst;
ops->set_tone = flexcop_set_tone;
ops->set_voltage = flexcop_set_voltage;
fc->fe_sleep = ops->sleep;
ops->sleep = flexcop_sleep;
return 1;
}
static int samsung_tbmu24112_set_symbol_rate(struct dvb_frontend *fe,
u32 srate, u32 ratio)
{
u8 aclk = 0;
u8 bclk = 0;
if (srate < 1500000) {
aclk = 0xb7; bclk = 0x47;
} else if (srate < 3000000) {
aclk = 0xb7; bclk = 0x4b;
} else if (srate < 7000000) {
aclk = 0xb7; bclk = 0x4f;
} else if (srate < 14000000) {
aclk = 0xb7; bclk = 0x53;
} else if (srate < 30000000) {
aclk = 0xb6; bclk = 0x53;
} else if (srate < 45000000) {
aclk = 0xb4; bclk = 0x51;
}
stv0299_writereg(fe, 0x13, aclk);
stv0299_writereg(fe, 0x14, bclk);
stv0299_writereg(fe, 0x1f, (ratio >> 16) & 0xff);
stv0299_writereg(fe, 0x20, (ratio >> 8) & 0xff);
stv0299_writereg(fe, 0x21, ratio & 0xf0);
return 0;
}
static int skystar2_rev26_attach(struct flexcop_device *fc,
struct i2c_adapter *i2c)
{
fc->fe = dvb_attach(stv0299_attach, &samsung_tbmu24112_config, i2c);
if (!fc->fe)
return 0;
if (!dvb_attach(dvb_pll_attach, fc->fe, 0x61, i2c,
DVB_PLL_SAMSUNG_TBMU24112))
return 0;
fc->fe->ops.set_voltage = flexcop_set_voltage;
fc->fe_sleep = fc->fe->ops.sleep;
fc->fe->ops.sleep = flexcop_sleep;
return 1;
}
static int skystar2_rev27_attach(struct flexcop_device *fc,
struct i2c_adapter *i2c)
{
flexcop_ibi_value r108;
struct i2c_adapter *i2c_tuner;
fc->fc_i2c_adap[0].no_base_addr = 1;
fc->fe = dvb_attach(s5h1420_attach, &skystar2_rev2_7_s5h1420_config,
i2c);
if (!fc->fe)
goto fail;
i2c_tuner = s5h1420_get_tuner_i2c_adapter(fc->fe);
if (!i2c_tuner)
goto fail;
fc->fe_sleep = fc->fe->ops.sleep;
fc->fe->ops.sleep = flexcop_sleep;
fc->fc_i2c_adap[2].no_base_addr = 1;
if (!dvb_attach(isl6421_attach, fc->fe, &fc->fc_i2c_adap[2].i2c_adap,
0x08, 1, 1, false)) {
err("ISL6421 could NOT be attached");
goto fail_isl;
}
info("ISL6421 successfully attached");
r108.raw = 0x00000506;
fc->write_ibi_reg(fc, tw_sm_c_108, r108);
if (!dvb_attach(itd1000_attach, fc->fe, i2c_tuner,
&skystar2_rev2_7_itd1000_config)) {
err("ITD1000 could NOT be attached");
goto fail_isl;
}
info("ITD1000 successfully attached");
return 1;
fail_isl:
fc->fc_i2c_adap[2].no_base_addr = 0;
fail:
fc->fc_i2c_adap[0].no_base_addr = 0;
return 0;
}
static int skystar2_rev28_attach(struct flexcop_device *fc,
struct i2c_adapter *i2c)
{
struct i2c_adapter *i2c_tuner;
fc->fe = dvb_attach(cx24123_attach, &skystar2_rev2_8_cx24123_config,
i2c);
if (!fc->fe)
return 0;
i2c_tuner = cx24123_get_tuner_i2c_adapter(fc->fe);
if (!i2c_tuner)
return 0;
if (!dvb_attach(cx24113_attach, fc->fe, &skystar2_rev2_8_cx24113_config,
i2c_tuner)) {
err("CX24113 could NOT be attached");
return 0;
}
info("CX24113 successfully attached");
fc->fc_i2c_adap[2].no_base_addr = 1;
if (!dvb_attach(isl6421_attach, fc->fe, &fc->fc_i2c_adap[2].i2c_adap,
0x08, 0, 0, false)) {
err("ISL6421 could NOT be attached");
fc->fc_i2c_adap[2].no_base_addr = 0;
return 0;
}
info("ISL6421 successfully attached");
return 1;
}
static int samsung_tdtc9251dh0_demod_init(struct dvb_frontend *fe)
{
static u8 mt352_clock_config[] = { 0x89, 0x18, 0x2d };
static u8 mt352_reset[] = { 0x50, 0x80 };
static u8 mt352_adc_ctl_1_cfg[] = { 0x8E, 0x40 };
static u8 mt352_agc_cfg[] = { 0x67, 0x28, 0xa1 };
static u8 mt352_capt_range_cfg[] = { 0x75, 0x32 };
mt352_write(fe, mt352_clock_config, sizeof(mt352_clock_config));
udelay(2000);
mt352_write(fe, mt352_reset, sizeof(mt352_reset));
mt352_write(fe, mt352_adc_ctl_1_cfg, sizeof(mt352_adc_ctl_1_cfg));
mt352_write(fe, mt352_agc_cfg, sizeof(mt352_agc_cfg));
mt352_write(fe, mt352_capt_range_cfg, sizeof(mt352_capt_range_cfg));
return 0;
}
static int airstar_dvbt_attach(struct flexcop_device *fc,
struct i2c_adapter *i2c)
{
fc->fe = dvb_attach(mt352_attach, &samsung_tdtc9251dh0_config, i2c);
if (!fc->fe)
return 0;
return !!dvb_attach(dvb_pll_attach, fc->fe, 0x61, NULL,
DVB_PLL_SAMSUNG_TDTC9251DH0);
}
static int airstar_atsc1_attach(struct flexcop_device *fc,
struct i2c_adapter *i2c)
{
fc->fe = dvb_attach(bcm3510_attach, &air2pc_atsc_first_gen_config, i2c);
return fc->fe != NULL;
}
static int airstar_atsc2_attach(struct flexcop_device *fc,
struct i2c_adapter *i2c)
{
fc->fe = dvb_attach(nxt200x_attach, &samsung_tbmv_config, i2c);
if (!fc->fe)
return 0;
return !!dvb_attach(dvb_pll_attach, fc->fe, 0x61, NULL,
DVB_PLL_SAMSUNG_TBMV);
}
static int airstar_atsc3_attach(struct flexcop_device *fc,
struct i2c_adapter *i2c)
{
fc->fe = dvb_attach(lgdt330x_attach, &air2pc_atsc_hd5000_config, i2c);
if (!fc->fe)
return 0;
return !!dvb_attach(simple_tuner_attach, fc->fe, i2c, 0x61,
TUNER_LG_TDVS_H06XF);
}
static int cablestar2_attach(struct flexcop_device *fc,
struct i2c_adapter *i2c)
{
fc->fc_i2c_adap[0].no_base_addr = 1;
fc->fe = dvb_attach(stv0297_attach, &alps_tdee4_stv0297_config, i2c);
if (!fc->fe)
goto fail;
if (fc->fe->ops.i2c_gate_ctrl)
fc->fe->ops.i2c_gate_ctrl(fc->fe, 0);
fc->fe->ops.i2c_gate_ctrl = NULL;
if (!dvb_attach(dvb_pll_attach, fc->fe, 0x61,
&fc->fc_i2c_adap[2].i2c_adap, DVB_PLL_TDEE4))
goto fail;
return 1;
fail:
fc->fc_i2c_adap[0].no_base_addr = 0;
return 0;
}
static int skystarS2_rev33_attach(struct flexcop_device *fc,
struct i2c_adapter *i2c)
{
fc->fe = dvb_attach(cx24120_attach,
&skystar2_rev3_3_cx24120_config, i2c);
if (!fc->fe)
return 0;
fc->dev_type = FC_SKYS2_REV33;
fc->fc_i2c_adap[2].no_base_addr = 1;
if (!dvb_attach(isl6421_attach, fc->fe, &fc->fc_i2c_adap[2].i2c_adap,
0x08, 0, 0, false)) {
err("ISL6421 could NOT be attached!");
fc->fc_i2c_adap[2].no_base_addr = 0;
return 0;
}
info("ISL6421 successfully attached.");
if (fc->has_32_hw_pid_filter)
fc->skip_6_hw_pid_filter = 1;
return 1;
}
int flexcop_frontend_init(struct flexcop_device *fc)
{
int i;
for (i = 0; i < ARRAY_SIZE(flexcop_frontends); i++) {
if (!flexcop_frontends[i].attach)
continue;
fc->dev_type = flexcop_frontends[i].type;
if (flexcop_frontends[i].attach(fc, &fc->fc_i2c_adap[0].i2c_adap))
goto fe_found;
if (fc->fe) {
dvb_frontend_detach(fc->fe);
fc->fe = NULL;
}
}
fc->dev_type = FC_UNK;
err("no frontend driver found for this B2C2/FlexCop adapter");
return -ENODEV;
fe_found:
info("found '%s' .", fc->fe->ops.info.name);
if (dvb_register_frontend(&fc->dvb_adapter, fc->fe)) {
err("frontend registration failed!");
dvb_frontend_detach(fc->fe);
fc->fe = NULL;
return -EINVAL;
}
fc->init_state |= FC_STATE_FE_INIT;
return 0;
}
void flexcop_frontend_exit(struct flexcop_device *fc)
{
if (fc->init_state & FC_STATE_FE_INIT) {
dvb_unregister_frontend(fc->fe);
dvb_frontend_detach(fc->fe);
}
fc->init_state &= ~FC_STATE_FE_INIT;
}
