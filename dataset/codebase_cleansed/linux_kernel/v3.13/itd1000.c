static int itd1000_write_regs(struct itd1000_state *state, u8 reg, u8 v[], u8 len)
{
u8 buf[MAX_XFER_SIZE];
struct i2c_msg msg = {
.addr = state->cfg->i2c_address, .flags = 0, .buf = buf, .len = len+1
};
if (1 + len > sizeof(buf)) {
printk(KERN_WARNING
"itd1000: i2c wr reg=%04x: len=%d is too big!\n",
reg, len);
return -EINVAL;
}
buf[0] = reg;
memcpy(&buf[1], v, len);
if (i2c_transfer(state->i2c, &msg, 1) != 1) {
printk(KERN_WARNING "itd1000 I2C write failed\n");
return -EREMOTEIO;
}
return 0;
}
static int itd1000_read_reg(struct itd1000_state *state, u8 reg)
{
u8 val;
struct i2c_msg msg[2] = {
{ .addr = state->cfg->i2c_address, .flags = 0, .buf = &reg, .len = 1 },
{ .addr = state->cfg->i2c_address, .flags = I2C_M_RD, .buf = &val, .len = 1 },
};
itd1000_write_regs(state, (reg - 1) & 0xff, &state->shadow[(reg - 1) & 0xff], 1);
if (i2c_transfer(state->i2c, msg, 2) != 2) {
itd_warn("itd1000 I2C read failed\n");
return -EREMOTEIO;
}
return val;
}
static inline int itd1000_write_reg(struct itd1000_state *state, u8 r, u8 v)
{
int ret = itd1000_write_regs(state, r, &v, 1);
state->shadow[r] = v;
return ret;
}
static void itd1000_set_lpf_bw(struct itd1000_state *state, u32 symbol_rate)
{
u8 i;
u8 con1 = itd1000_read_reg(state, CON1) & 0xfd;
u8 pllfh = itd1000_read_reg(state, PLLFH) & 0x0f;
u8 bbgvmin = itd1000_read_reg(state, BBGVMIN) & 0xf0;
u8 bw = itd1000_read_reg(state, BW) & 0xf0;
itd_dbg("symbol_rate = %d\n", symbol_rate);
itd1000_write_reg(state, CON1, con1 | (1 << 1));
for (i = 0; i < ARRAY_SIZE(itd1000_lpf_pga); i++)
if (symbol_rate < itd1000_lpf_pga[i].symbol_rate) {
itd_dbg("symrate: index: %d pgaext: %x, bbgvmin: %x\n", i, itd1000_lpf_pga[i].pgaext, itd1000_lpf_pga[i].bbgvmin);
itd1000_write_reg(state, PLLFH, pllfh | (itd1000_lpf_pga[i].pgaext << 4));
itd1000_write_reg(state, BBGVMIN, bbgvmin | (itd1000_lpf_pga[i].bbgvmin));
itd1000_write_reg(state, BW, bw | (i & 0x0f));
break;
}
itd1000_write_reg(state, CON1, con1 | (0 << 1));
}
static void itd1000_set_vco(struct itd1000_state *state, u32 freq_khz)
{
u8 i;
u8 gvbb_i2c = itd1000_read_reg(state, GVBB_I2C) & 0xbf;
u8 vco_chp1_i2c = itd1000_read_reg(state, VCO_CHP1_I2C) & 0x0f;
u8 adcout;
itd1000_write_reg(state, GVBB_I2C, gvbb_i2c | (1 << 6));
for (i = 0; i < ARRAY_SIZE(itd1000_vcorg); i++) {
if (freq_khz < itd1000_vcorg[i].fmax_rg) {
itd1000_write_reg(state, VCO_CHP1_I2C, vco_chp1_i2c | (itd1000_vcorg[i].vcorg << 4));
msleep(1);
adcout = itd1000_read_reg(state, PLLLOCK) & 0x0f;
itd_dbg("VCO: %dkHz: %d -> ADCOUT: %d %02x\n", freq_khz, itd1000_vcorg[i].vcorg, adcout, vco_chp1_i2c);
if (adcout > 13) {
if (!(itd1000_vcorg[i].vcorg == 7 || itd1000_vcorg[i].vcorg == 15))
itd1000_write_reg(state, VCO_CHP1_I2C, vco_chp1_i2c | ((itd1000_vcorg[i].vcorg + 1) << 4));
} else if (adcout < 2) {
if (!(itd1000_vcorg[i].vcorg == 1 || itd1000_vcorg[i].vcorg == 9))
itd1000_write_reg(state, VCO_CHP1_I2C, vco_chp1_i2c | ((itd1000_vcorg[i].vcorg - 1) << 4));
}
break;
}
}
}
static void itd1000_set_lo(struct itd1000_state *state, u32 freq_khz)
{
int i, j;
u32 plln, pllf;
u64 tmp;
plln = (freq_khz * 1000) / 2 / FREF;
tmp = plln % 1000000;
plln /= 1000000;
tmp *= 1048576;
do_div(tmp, 1000000);
pllf = (u32) tmp;
state->frequency = ((plln * 1000) + (pllf * 1000)/1048576) * 2*FREF;
itd_dbg("frequency: %dkHz (wanted) %dkHz (set), PLLF = %d, PLLN = %d\n", freq_khz, state->frequency, pllf, plln);
itd1000_write_reg(state, PLLNH, 0x80);
itd1000_write_reg(state, PLLNL, plln & 0xff);
itd1000_write_reg(state, PLLFH, (itd1000_read_reg(state, PLLFH) & 0xf0) | ((pllf >> 16) & 0x0f));
itd1000_write_reg(state, PLLFM, (pllf >> 8) & 0xff);
itd1000_write_reg(state, PLLFL, (pllf >> 0) & 0xff);
for (i = 0; i < ARRAY_SIZE(itd1000_fre_values); i++) {
if (freq_khz <= itd1000_fre_values[i].freq) {
itd_dbg("fre_values: %d\n", i);
itd1000_write_reg(state, RFTR, itd1000_fre_values[i].values[0]);
for (j = 0; j < 9; j++)
itd1000_write_reg(state, RFST1+j, itd1000_fre_values[i].values[j+1]);
break;
}
}
itd1000_set_vco(state, freq_khz);
}
static int itd1000_set_parameters(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct itd1000_state *state = fe->tuner_priv;
u8 pllcon1;
itd1000_set_lo(state, c->frequency);
itd1000_set_lpf_bw(state, c->symbol_rate);
pllcon1 = itd1000_read_reg(state, PLLCON1) & 0x7f;
itd1000_write_reg(state, PLLCON1, pllcon1 | (1 << 7));
itd1000_write_reg(state, PLLCON1, pllcon1);
return 0;
}
static int itd1000_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct itd1000_state *state = fe->tuner_priv;
*frequency = state->frequency;
return 0;
}
static int itd1000_get_bandwidth(struct dvb_frontend *fe, u32 *bandwidth)
{
return 0;
}
static int itd1000_init(struct dvb_frontend *fe)
{
struct itd1000_state *state = fe->tuner_priv;
int i;
for (i = 0; i < ARRAY_SIZE(itd1000_init_tab); i++)
itd1000_write_reg(state, itd1000_init_tab[i][0], itd1000_init_tab[i][1]);
for (i = 0; i < ARRAY_SIZE(itd1000_reinit_tab); i++)
itd1000_write_reg(state, itd1000_reinit_tab[i][0], itd1000_reinit_tab[i][1]);
return 0;
}
static int itd1000_sleep(struct dvb_frontend *fe)
{
return 0;
}
static int itd1000_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
struct dvb_frontend *itd1000_attach(struct dvb_frontend *fe, struct i2c_adapter *i2c, struct itd1000_config *cfg)
{
struct itd1000_state *state = NULL;
u8 i = 0;
state = kzalloc(sizeof(struct itd1000_state), GFP_KERNEL);
if (state == NULL)
return NULL;
state->cfg = cfg;
state->i2c = i2c;
i = itd1000_read_reg(state, 0);
if (i != 0) {
kfree(state);
return NULL;
}
itd_info("successfully identified (ID: %d)\n", i);
memset(state->shadow, 0xff, sizeof(state->shadow));
for (i = 0x65; i < 0x9c; i++)
state->shadow[i] = itd1000_read_reg(state, i);
memcpy(&fe->ops.tuner_ops, &itd1000_tuner_ops, sizeof(struct dvb_tuner_ops));
fe->tuner_priv = state;
return fe;
}
