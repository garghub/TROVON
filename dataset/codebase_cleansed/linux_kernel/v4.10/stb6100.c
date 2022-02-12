static inline void stb6100_normalise_regs(u8 regs[])
{
int i;
for (i = 0; i < STB6100_NUMREGS; i++)
regs[i] = (regs[i] & stb6100_template[i].mask) | stb6100_template[i].set;
}
static int stb6100_read_regs(struct stb6100_state *state, u8 regs[])
{
int rc;
struct i2c_msg msg = {
.addr = state->config->tuner_address,
.flags = I2C_M_RD,
.buf = regs,
.len = STB6100_NUMREGS
};
rc = i2c_transfer(state->i2c, &msg, 1);
if (unlikely(rc != 1)) {
dprintk(verbose, FE_ERROR, 1, "Read (0x%x) err, rc=[%d]",
state->config->tuner_address, rc);
return -EREMOTEIO;
}
if (unlikely(verbose > FE_DEBUG)) {
int i;
dprintk(verbose, FE_DEBUG, 1, " Read from 0x%02x", state->config->tuner_address);
for (i = 0; i < STB6100_NUMREGS; i++)
dprintk(verbose, FE_DEBUG, 1, " %s: 0x%02x", stb6100_regnames[i], regs[i]);
}
return 0;
}
static int stb6100_read_reg(struct stb6100_state *state, u8 reg)
{
u8 regs[STB6100_NUMREGS];
struct i2c_msg msg = {
.addr = state->config->tuner_address + reg,
.flags = I2C_M_RD,
.buf = regs,
.len = 1
};
i2c_transfer(state->i2c, &msg, 1);
if (unlikely(reg >= STB6100_NUMREGS)) {
dprintk(verbose, FE_ERROR, 1, "Invalid register offset 0x%x", reg);
return -EINVAL;
}
if (unlikely(verbose > FE_DEBUG)) {
dprintk(verbose, FE_DEBUG, 1, " Read from 0x%02x", state->config->tuner_address);
dprintk(verbose, FE_DEBUG, 1, " %s: 0x%02x", stb6100_regnames[reg], regs[0]);
}
return (unsigned int)regs[0];
}
static int stb6100_write_reg_range(struct stb6100_state *state, u8 buf[], int start, int len)
{
int rc;
u8 cmdbuf[MAX_XFER_SIZE];
struct i2c_msg msg = {
.addr = state->config->tuner_address,
.flags = 0,
.buf = cmdbuf,
.len = len + 1
};
if (1 + len > sizeof(cmdbuf)) {
printk(KERN_WARNING
"%s: i2c wr: len=%d is too big!\n",
KBUILD_MODNAME, len);
return -EINVAL;
}
if (unlikely(start < 1 || start + len > STB6100_NUMREGS)) {
dprintk(verbose, FE_ERROR, 1, "Invalid register range %d:%d",
start, len);
return -EINVAL;
}
memcpy(&cmdbuf[1], buf, len);
cmdbuf[0] = start;
if (unlikely(verbose > FE_DEBUG)) {
int i;
dprintk(verbose, FE_DEBUG, 1, " Write @ 0x%02x: [%d:%d]", state->config->tuner_address, start, len);
for (i = 0; i < len; i++)
dprintk(verbose, FE_DEBUG, 1, " %s: 0x%02x", stb6100_regnames[start + i], buf[i]);
}
rc = i2c_transfer(state->i2c, &msg, 1);
if (unlikely(rc != 1)) {
dprintk(verbose, FE_ERROR, 1, "(0x%x) write err [%d:%d], rc=[%d]",
(unsigned int)state->config->tuner_address, start, len, rc);
return -EREMOTEIO;
}
return 0;
}
static int stb6100_write_reg(struct stb6100_state *state, u8 reg, u8 data)
{
if (unlikely(reg >= STB6100_NUMREGS)) {
dprintk(verbose, FE_ERROR, 1, "Invalid register offset 0x%x", reg);
return -EREMOTEIO;
}
data = (data & stb6100_template[reg].mask) | stb6100_template[reg].set;
return stb6100_write_reg_range(state, &data, reg, 1);
}
static int stb6100_get_status(struct dvb_frontend *fe, u32 *status)
{
int rc;
struct stb6100_state *state = fe->tuner_priv;
rc = stb6100_read_reg(state, STB6100_LD);
if (rc < 0) {
dprintk(verbose, FE_ERROR, 1, "%s failed", __func__);
return rc;
}
return (rc & STB6100_LD_LOCK) ? TUNER_STATUS_LOCKED : 0;
}
static int stb6100_get_bandwidth(struct dvb_frontend *fe, u32 *bandwidth)
{
int rc;
u8 f;
u32 bw;
struct stb6100_state *state = fe->tuner_priv;
rc = stb6100_read_reg(state, STB6100_F);
if (rc < 0)
return rc;
f = rc & STB6100_F_F;
bw = (f + 5) * 2000;
*bandwidth = state->bandwidth = bw * 1000;
dprintk(verbose, FE_DEBUG, 1, "bandwidth = %u Hz", state->bandwidth);
return 0;
}
static int stb6100_set_bandwidth(struct dvb_frontend *fe, u32 bandwidth)
{
u32 tmp;
int rc;
struct stb6100_state *state = fe->tuner_priv;
dprintk(verbose, FE_DEBUG, 1, "set bandwidth to %u Hz", bandwidth);
bandwidth /= 2;
if (bandwidth >= 36000000)
tmp = 31;
else if (bandwidth <= 5000000)
tmp = 0;
else
tmp = (bandwidth + 500000) / 1000000 - 5;
rc = stb6100_write_reg(state, STB6100_FCCK, 0x0d | STB6100_FCCK_FCCK);
if (rc < 0)
return rc;
rc = stb6100_write_reg(state, STB6100_F, 0xc0 | tmp);
if (rc < 0)
return rc;
msleep(5);
rc = stb6100_write_reg(state, STB6100_FCCK, 0x0d);
if (rc < 0)
return rc;
msleep(10);
return 0;
}
static int stb6100_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
int rc;
u32 nint, nfrac, fvco;
int psd2, odiv;
struct stb6100_state *state = fe->tuner_priv;
u8 regs[STB6100_NUMREGS];
rc = stb6100_read_regs(state, regs);
if (rc < 0)
return rc;
odiv = (regs[STB6100_VCO] & STB6100_VCO_ODIV) >> STB6100_VCO_ODIV_SHIFT;
psd2 = (regs[STB6100_K] & STB6100_K_PSD2) >> STB6100_K_PSD2_SHIFT;
nint = regs[STB6100_NI];
nfrac = ((regs[STB6100_K] & STB6100_K_NF_MSB) << 8) | regs[STB6100_NF_LSB];
fvco = (nfrac * state->reference >> (9 - psd2)) + (nint * state->reference << psd2);
*frequency = state->frequency = fvco >> (odiv + 1);
dprintk(verbose, FE_DEBUG, 1,
"frequency = %u kHz, odiv = %u, psd2 = %u, fxtal = %u kHz, fvco = %u kHz, N(I) = %u, N(F) = %u",
state->frequency, odiv, psd2, state->reference, fvco, nint, nfrac);
return 0;
}
static int stb6100_set_frequency(struct dvb_frontend *fe, u32 frequency)
{
int rc;
const struct stb6100_lkup *ptr;
struct stb6100_state *state = fe->tuner_priv;
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
u32 srate = 0, fvco, nint, nfrac;
u8 regs[STB6100_NUMREGS];
u8 g, psd2, odiv;
dprintk(verbose, FE_DEBUG, 1, "Version 2010-8-14 13:51");
if (fe->ops.get_frontend) {
dprintk(verbose, FE_DEBUG, 1, "Get frontend parameters");
fe->ops.get_frontend(fe, p);
}
srate = p->symbol_rate;
rc = stb6100_write_reg(state, STB6100_FCCK, 0x4d | STB6100_FCCK_FCCK);
if (rc < 0)
return rc;
regs[STB6100_LPEN] = 0xeb;
rc = stb6100_write_reg(state, STB6100_LPEN, regs[STB6100_LPEN]);
if (rc < 0)
return rc;
if (frequency <= 1075000)
odiv = 1;
else
odiv = 0;
regs[STB6100_VCO] = 0xe0 | (odiv << STB6100_VCO_ODIV_SHIFT);
for (ptr = lkup;
(ptr->val_high != 0) && !CHKRANGE(frequency, ptr->val_low, ptr->val_high);
ptr++);
if (ptr->val_high == 0) {
printk(KERN_ERR "%s: frequency out of range: %u kHz\n", __func__, frequency);
return -EINVAL;
}
regs[STB6100_VCO] = (regs[STB6100_VCO] & ~STB6100_VCO_OSM) | ptr->reg;
rc = stb6100_write_reg(state, STB6100_VCO, regs[STB6100_VCO]);
if (rc < 0)
return rc;
if ((frequency > 1075000) && (frequency <= 1325000))
psd2 = 0;
else
psd2 = 1;
fvco = frequency << (1 + odiv);
nint = fvco / (state->reference << psd2);
nfrac = DIV_ROUND_CLOSEST((fvco - (nint * state->reference << psd2))
<< (9 - psd2), state->reference);
regs[STB6100_NI] = nint;
rc = stb6100_write_reg(state, STB6100_NI, regs[STB6100_NI]);
if (rc < 0)
return rc;
regs[STB6100_NF_LSB] = nfrac;
rc = stb6100_write_reg(state, STB6100_NF_LSB, regs[STB6100_NF_LSB]);
if (rc < 0)
return rc;
regs[STB6100_K] = (0x38 & ~STB6100_K_PSD2) | (psd2 << STB6100_K_PSD2_SHIFT);
regs[STB6100_K] = (regs[STB6100_K] & ~STB6100_K_NF_MSB) | ((nfrac >> 8) & STB6100_K_NF_MSB);
rc = stb6100_write_reg(state, STB6100_K, regs[STB6100_K]);
if (rc < 0)
return rc;
if (srate >= 15000000)
g = 9;
else if (srate >= 5000000)
g = 11;
else
g = 14;
regs[STB6100_G] = (0x10 & ~STB6100_G_G) | g;
regs[STB6100_G] &= ~STB6100_G_GCT;
regs[STB6100_G] |= (1 << 5);
rc = stb6100_write_reg(state, STB6100_G, regs[STB6100_G]);
if (rc < 0)
return rc;
regs[STB6100_DLB] = 0xcc;
rc = stb6100_write_reg(state, STB6100_DLB, regs[STB6100_DLB]);
if (rc < 0)
return rc;
dprintk(verbose, FE_DEBUG, 1,
"frequency = %u, srate = %u, g = %u, odiv = %u, psd2 = %u, fxtal = %u, osm = %u, fvco = %u, N(I) = %u, N(F) = %u",
frequency, srate, (unsigned int)g, (unsigned int)odiv,
(unsigned int)psd2, state->reference,
ptr->reg, fvco, nint, nfrac);
regs[STB6100_TEST1] = 0x8f;
rc = stb6100_write_reg(state, STB6100_TEST1, regs[STB6100_TEST1]);
if (rc < 0)
return rc;
regs[STB6100_TEST3] = 0xde;
rc = stb6100_write_reg(state, STB6100_TEST3, regs[STB6100_TEST3]);
if (rc < 0)
return rc;
regs[STB6100_LPEN] = 0xfb;
rc = stb6100_write_reg(state, STB6100_LPEN, regs[STB6100_LPEN]);
if (rc < 0)
return rc;
msleep(2);
regs[STB6100_VCO] &= ~STB6100_VCO_OCK;
rc = stb6100_write_reg(state, STB6100_VCO, regs[STB6100_VCO]);
if (rc < 0)
return rc;
msleep(10);
regs[STB6100_VCO] &= ~STB6100_VCO_OSCH;
regs[STB6100_VCO] |= STB6100_VCO_OCK;
rc = stb6100_write_reg(state, STB6100_VCO, regs[STB6100_VCO]);
if (rc < 0)
return rc;
rc = stb6100_write_reg(state, STB6100_FCCK, 0x0d);
if (rc < 0)
return rc;
msleep(10);
return 0;
}
static int stb6100_sleep(struct dvb_frontend *fe)
{
return 0;
}
static int stb6100_init(struct dvb_frontend *fe)
{
struct stb6100_state *state = fe->tuner_priv;
int refclk = 27000000;
state->bandwidth = 36000000;
state->reference = refclk / 1000;
return 0;
}
static int stb6100_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
if (c->frequency > 0)
stb6100_set_frequency(fe, c->frequency);
if (c->bandwidth_hz > 0)
stb6100_set_bandwidth(fe, c->bandwidth_hz);
return 0;
}
struct dvb_frontend *stb6100_attach(struct dvb_frontend *fe,
const struct stb6100_config *config,
struct i2c_adapter *i2c)
{
struct stb6100_state *state = NULL;
state = kzalloc(sizeof (struct stb6100_state), GFP_KERNEL);
if (!state)
return NULL;
state->config = config;
state->i2c = i2c;
state->frontend = fe;
state->reference = config->refclock / 1000;
fe->tuner_priv = state;
fe->ops.tuner_ops = stb6100_ops;
printk("%s: Attaching STB6100 \n", __func__);
return fe;
}
static void stb6100_release(struct dvb_frontend *fe)
{
struct stb6100_state *state = fe->tuner_priv;
fe->tuner_priv = NULL;
kfree(state);
}
