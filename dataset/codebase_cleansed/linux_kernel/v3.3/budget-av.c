static u8 i2c_readreg(struct i2c_adapter *i2c, u8 id, u8 reg)
{
u8 mm1[] = { 0x00 };
u8 mm2[] = { 0x00 };
struct i2c_msg msgs[2];
msgs[0].flags = 0;
msgs[1].flags = I2C_M_RD;
msgs[0].addr = msgs[1].addr = id / 2;
mm1[0] = reg;
msgs[0].len = 1;
msgs[1].len = 1;
msgs[0].buf = mm1;
msgs[1].buf = mm2;
i2c_transfer(i2c, msgs, 2);
return mm2[0];
}
static int i2c_readregs(struct i2c_adapter *i2c, u8 id, u8 reg, u8 * buf, u8 len)
{
u8 mm1[] = { reg };
struct i2c_msg msgs[2] = {
{.addr = id / 2,.flags = 0,.buf = mm1,.len = 1},
{.addr = id / 2,.flags = I2C_M_RD,.buf = buf,.len = len}
};
if (i2c_transfer(i2c, msgs, 2) != 2)
return -EIO;
return 0;
}
static int i2c_writereg(struct i2c_adapter *i2c, u8 id, u8 reg, u8 val)
{
u8 msg[2] = { reg, val };
struct i2c_msg msgs;
msgs.flags = 0;
msgs.addr = id / 2;
msgs.len = 2;
msgs.buf = msg;
return i2c_transfer(i2c, &msgs, 1);
}
static int ciintf_read_attribute_mem(struct dvb_ca_en50221 *ca, int slot, int address)
{
struct budget_av *budget_av = (struct budget_av *) ca->data;
int result;
if (slot != 0)
return -EINVAL;
saa7146_setgpio(budget_av->budget.dev, 1, SAA7146_GPIO_OUTHI);
udelay(1);
result = ttpci_budget_debiread(&budget_av->budget, DEBICICAM, address & 0xfff, 1, 0, 1);
if (result == -ETIMEDOUT) {
ciintf_slot_shutdown(ca, slot);
pr_info("cam ejected 1\n");
}
return result;
}
static int ciintf_write_attribute_mem(struct dvb_ca_en50221 *ca, int slot, int address, u8 value)
{
struct budget_av *budget_av = (struct budget_av *) ca->data;
int result;
if (slot != 0)
return -EINVAL;
saa7146_setgpio(budget_av->budget.dev, 1, SAA7146_GPIO_OUTHI);
udelay(1);
result = ttpci_budget_debiwrite(&budget_av->budget, DEBICICAM, address & 0xfff, 1, value, 0, 1);
if (result == -ETIMEDOUT) {
ciintf_slot_shutdown(ca, slot);
pr_info("cam ejected 2\n");
}
return result;
}
static int ciintf_read_cam_control(struct dvb_ca_en50221 *ca, int slot, u8 address)
{
struct budget_av *budget_av = (struct budget_av *) ca->data;
int result;
if (slot != 0)
return -EINVAL;
saa7146_setgpio(budget_av->budget.dev, 1, SAA7146_GPIO_OUTLO);
udelay(1);
result = ttpci_budget_debiread(&budget_av->budget, DEBICICAM, address & 3, 1, 0, 0);
if (result == -ETIMEDOUT) {
ciintf_slot_shutdown(ca, slot);
pr_info("cam ejected 3\n");
return -ETIMEDOUT;
}
return result;
}
static int ciintf_write_cam_control(struct dvb_ca_en50221 *ca, int slot, u8 address, u8 value)
{
struct budget_av *budget_av = (struct budget_av *) ca->data;
int result;
if (slot != 0)
return -EINVAL;
saa7146_setgpio(budget_av->budget.dev, 1, SAA7146_GPIO_OUTLO);
udelay(1);
result = ttpci_budget_debiwrite(&budget_av->budget, DEBICICAM, address & 3, 1, value, 0, 0);
if (result == -ETIMEDOUT) {
ciintf_slot_shutdown(ca, slot);
pr_info("cam ejected 5\n");
}
return result;
}
static int ciintf_slot_reset(struct dvb_ca_en50221 *ca, int slot)
{
struct budget_av *budget_av = (struct budget_av *) ca->data;
struct saa7146_dev *saa = budget_av->budget.dev;
if (slot != 0)
return -EINVAL;
dprintk(1, "ciintf_slot_reset\n");
budget_av->slot_status = SLOTSTATUS_RESET;
saa7146_setgpio(saa, 2, SAA7146_GPIO_OUTHI);
saa7146_setgpio(saa, 0, SAA7146_GPIO_OUTHI);
msleep(2);
saa7146_setgpio(saa, 0, SAA7146_GPIO_OUTLO);
msleep(20);
saa7146_setgpio(saa, 2, SAA7146_GPIO_OUTLO);
ttpci_budget_set_video_port(saa, BUDGET_VIDEO_PORTB);
msleep(20);
if (budget_av->reinitialise_demod)
dvb_frontend_reinitialise(budget_av->budget.dvb_frontend);
return 0;
}
static int ciintf_slot_shutdown(struct dvb_ca_en50221 *ca, int slot)
{
struct budget_av *budget_av = (struct budget_av *) ca->data;
struct saa7146_dev *saa = budget_av->budget.dev;
if (slot != 0)
return -EINVAL;
dprintk(1, "ciintf_slot_shutdown\n");
ttpci_budget_set_video_port(saa, BUDGET_VIDEO_PORTB);
budget_av->slot_status = SLOTSTATUS_NONE;
return 0;
}
static int ciintf_slot_ts_enable(struct dvb_ca_en50221 *ca, int slot)
{
struct budget_av *budget_av = (struct budget_av *) ca->data;
struct saa7146_dev *saa = budget_av->budget.dev;
if (slot != 0)
return -EINVAL;
dprintk(1, "ciintf_slot_ts_enable: %d\n", budget_av->slot_status);
ttpci_budget_set_video_port(saa, BUDGET_VIDEO_PORTA);
return 0;
}
static int ciintf_poll_slot_status(struct dvb_ca_en50221 *ca, int slot, int open)
{
struct budget_av *budget_av = (struct budget_av *) ca->data;
struct saa7146_dev *saa = budget_av->budget.dev;
int result;
if (slot != 0)
return -EINVAL;
if (budget_av->slot_status == SLOTSTATUS_NONE) {
saa7146_setgpio(saa, 3, SAA7146_GPIO_INPUT);
udelay(1);
if (saa7146_read(saa, PSR) & MASK_06) {
if (budget_av->slot_status == SLOTSTATUS_NONE) {
budget_av->slot_status = SLOTSTATUS_PRESENT;
pr_info("cam inserted A\n");
}
}
saa7146_setgpio(saa, 3, SAA7146_GPIO_OUTLO);
}
if ((budget_av->slot_status == SLOTSTATUS_NONE) || (!open)) {
saa7146_setgpio(budget_av->budget.dev, 1, SAA7146_GPIO_OUTLO);
result = ttpci_budget_debiread(&budget_av->budget, DEBICICAM, 0, 1, 0, 1);
if ((result >= 0) && (budget_av->slot_status == SLOTSTATUS_NONE)) {
budget_av->slot_status = SLOTSTATUS_PRESENT;
pr_info("cam inserted B\n");
} else if (result < 0) {
if (budget_av->slot_status != SLOTSTATUS_NONE) {
ciintf_slot_shutdown(ca, slot);
pr_info("cam ejected 5\n");
return 0;
}
}
}
if (budget_av->slot_status == SLOTSTATUS_RESET) {
result = ciintf_read_attribute_mem(ca, slot, 0);
if (result == 0x1d) {
budget_av->slot_status = SLOTSTATUS_READY;
}
}
if (budget_av->slot_status != SLOTSTATUS_NONE) {
if (budget_av->slot_status & SLOTSTATUS_READY) {
return DVB_CA_EN50221_POLL_CAM_PRESENT | DVB_CA_EN50221_POLL_CAM_READY;
}
return DVB_CA_EN50221_POLL_CAM_PRESENT;
}
return 0;
}
static int ciintf_init(struct budget_av *budget_av)
{
struct saa7146_dev *saa = budget_av->budget.dev;
int result;
memset(&budget_av->ca, 0, sizeof(struct dvb_ca_en50221));
saa7146_setgpio(saa, 0, SAA7146_GPIO_OUTLO);
saa7146_setgpio(saa, 1, SAA7146_GPIO_OUTLO);
saa7146_setgpio(saa, 2, SAA7146_GPIO_OUTLO);
saa7146_setgpio(saa, 3, SAA7146_GPIO_OUTLO);
saa7146_write(saa, MC1, MASK_27 | MASK_11);
budget_av->ca.owner = THIS_MODULE;
budget_av->ca.read_attribute_mem = ciintf_read_attribute_mem;
budget_av->ca.write_attribute_mem = ciintf_write_attribute_mem;
budget_av->ca.read_cam_control = ciintf_read_cam_control;
budget_av->ca.write_cam_control = ciintf_write_cam_control;
budget_av->ca.slot_reset = ciintf_slot_reset;
budget_av->ca.slot_shutdown = ciintf_slot_shutdown;
budget_av->ca.slot_ts_enable = ciintf_slot_ts_enable;
budget_av->ca.poll_slot_status = ciintf_poll_slot_status;
budget_av->ca.data = budget_av;
budget_av->budget.ci_present = 1;
budget_av->slot_status = SLOTSTATUS_NONE;
if ((result = dvb_ca_en50221_init(&budget_av->budget.dvb_adapter,
&budget_av->ca, 0, 1)) != 0) {
pr_err("ci initialisation failed\n");
goto error;
}
pr_info("ci interface initialised\n");
return 0;
error:
saa7146_write(saa, MC1, MASK_27);
return result;
}
static void ciintf_deinit(struct budget_av *budget_av)
{
struct saa7146_dev *saa = budget_av->budget.dev;
saa7146_setgpio(saa, 0, SAA7146_GPIO_INPUT);
saa7146_setgpio(saa, 1, SAA7146_GPIO_INPUT);
saa7146_setgpio(saa, 2, SAA7146_GPIO_INPUT);
saa7146_setgpio(saa, 3, SAA7146_GPIO_INPUT);
dvb_ca_en50221_release(&budget_av->ca);
saa7146_write(saa, MC1, MASK_27);
}
static int saa7113_init(struct budget_av *budget_av)
{
struct budget *budget = &budget_av->budget;
struct saa7146_dev *saa = budget->dev;
const u8 *data = saa7113_tab;
saa7146_setgpio(saa, 0, SAA7146_GPIO_OUTHI);
msleep(200);
if (i2c_writereg(&budget->i2c_adap, 0x4a, 0x01, 0x08) != 1) {
dprintk(1, "saa7113 not found on KNC card\n");
return -ENODEV;
}
dprintk(1, "saa7113 detected and initializing\n");
while (*data != 0xff) {
i2c_writereg(&budget->i2c_adap, 0x4a, *data, *(data + 1));
data += 2;
}
dprintk(1, "saa7113 status=%02x\n", i2c_readreg(&budget->i2c_adap, 0x4a, 0x1f));
return 0;
}
static int saa7113_setinput(struct budget_av *budget_av, int input)
{
struct budget *budget = &budget_av->budget;
if (1 != budget_av->has_saa7113)
return -ENODEV;
if (input == 1) {
i2c_writereg(&budget->i2c_adap, 0x4a, 0x02, 0xc7);
i2c_writereg(&budget->i2c_adap, 0x4a, 0x09, 0x80);
} else if (input == 0) {
i2c_writereg(&budget->i2c_adap, 0x4a, 0x02, 0xc0);
i2c_writereg(&budget->i2c_adap, 0x4a, 0x09, 0x00);
} else
return -EINVAL;
budget_av->cur_input = input;
return 0;
}
static int philips_su1278_ty_ci_set_symbol_rate(struct dvb_frontend *fe, u32 srate, u32 ratio)
{
u8 aclk = 0;
u8 bclk = 0;
u8 m1;
aclk = 0xb5;
if (srate < 2000000)
bclk = 0x86;
else if (srate < 5000000)
bclk = 0x89;
else if (srate < 15000000)
bclk = 0x8f;
else if (srate < 45000000)
bclk = 0x95;
m1 = 0x14;
if (srate < 4000000)
m1 = 0x10;
stv0299_writereg(fe, 0x13, aclk);
stv0299_writereg(fe, 0x14, bclk);
stv0299_writereg(fe, 0x1f, (ratio >> 16) & 0xff);
stv0299_writereg(fe, 0x20, (ratio >> 8) & 0xff);
stv0299_writereg(fe, 0x21, (ratio) & 0xf0);
stv0299_writereg(fe, 0x0f, 0x80 | m1);
return 0;
}
static int philips_su1278_ty_ci_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u32 div;
u8 buf[4];
struct budget *budget = (struct budget *) fe->dvb->priv;
struct i2c_msg msg = {.addr = 0x61,.flags = 0,.buf = buf,.len = sizeof(buf) };
if ((c->frequency < 950000) || (c->frequency > 2150000))
return -EINVAL;
div = (c->frequency + (125 - 1)) / 125;
buf[0] = (div >> 8) & 0x7f;
buf[1] = div & 0xff;
buf[2] = 0x80 | ((div & 0x18000) >> 10) | 4;
buf[3] = 0x20;
if (c->symbol_rate < 4000000)
buf[3] |= 1;
if (c->frequency < 1250000)
buf[3] |= 0;
else if (c->frequency < 1550000)
buf[3] |= 0x40;
else if (c->frequency < 2050000)
buf[3] |= 0x80;
else if (c->frequency < 2150000)
buf[3] |= 0xC0;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget->i2c_adap, &msg, 1) != 1)
return -EIO;
return 0;
}
static int philips_cu1216_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct budget *budget = (struct budget *) fe->dvb->priv;
u8 buf[6];
struct i2c_msg msg = {.addr = 0x60,.flags = 0,.buf = buf,.len = sizeof(buf) };
int i;
#define CU1216_IF 36125000
#define TUNER_MUL 62500
u32 div = (c->frequency + CU1216_IF + TUNER_MUL / 2) / TUNER_MUL;
buf[0] = (div >> 8) & 0x7f;
buf[1] = div & 0xff;
buf[2] = 0xce;
buf[3] = (c->frequency < 150000000 ? 0x01 :
c->frequency < 445000000 ? 0x02 : 0x04);
buf[4] = 0xde;
buf[5] = 0x20;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget->i2c_adap, &msg, 1) != 1)
return -EIO;
msg.flags = I2C_M_RD;
msg.len = 1;
for (i = 0; i < 20; i++) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget->i2c_adap, &msg, 1) == 1 && (buf[0] & 0x40))
break;
msleep(10);
}
msg.flags = 0;
msg.len = 2;
msg.buf = &buf[2];
buf[2] &= ~0x40;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget->i2c_adap, &msg, 1) != 1)
return -EIO;
return 0;
}
static int philips_tu1216_tuner_init(struct dvb_frontend *fe)
{
struct budget *budget = (struct budget *) fe->dvb->priv;
static u8 tu1216_init[] = { 0x0b, 0xf5, 0x85, 0xab };
struct i2c_msg tuner_msg = {.addr = 0x60,.flags = 0,.buf = tu1216_init,.len = sizeof(tu1216_init) };
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget->i2c_adap, &tuner_msg, 1) != 1)
return -EIO;
msleep(1);
return 0;
}
static int philips_tu1216_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct budget *budget = (struct budget *) fe->dvb->priv;
u8 tuner_buf[4];
struct i2c_msg tuner_msg = {.addr = 0x60,.flags = 0,.buf = tuner_buf,.len =
sizeof(tuner_buf) };
int tuner_frequency = 0;
u8 band, cp, filter;
tuner_frequency = c->frequency + 36166000;
if (tuner_frequency < 87000000)
return -EINVAL;
else if (tuner_frequency < 130000000)
cp = 3;
else if (tuner_frequency < 160000000)
cp = 5;
else if (tuner_frequency < 200000000)
cp = 6;
else if (tuner_frequency < 290000000)
cp = 3;
else if (tuner_frequency < 420000000)
cp = 5;
else if (tuner_frequency < 480000000)
cp = 6;
else if (tuner_frequency < 620000000)
cp = 3;
else if (tuner_frequency < 830000000)
cp = 5;
else if (tuner_frequency < 895000000)
cp = 7;
else
return -EINVAL;
if (c->frequency < 49000000)
return -EINVAL;
else if (c->frequency < 161000000)
band = 1;
else if (c->frequency < 444000000)
band = 2;
else if (c->frequency < 861000000)
band = 4;
else
return -EINVAL;
switch (c->bandwidth_hz) {
case 6000000:
filter = 0;
break;
case 7000000:
filter = 0;
break;
case 8000000:
filter = 1;
break;
default:
return -EINVAL;
}
tuner_frequency = (((c->frequency / 1000) * 6) + 217496) / 1000;
tuner_buf[0] = (tuner_frequency >> 8) & 0x7f;
tuner_buf[1] = tuner_frequency & 0xff;
tuner_buf[2] = 0xca;
tuner_buf[3] = (cp << 5) | (filter << 3) | band;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget->i2c_adap, &tuner_msg, 1) != 1)
return -EIO;
msleep(1);
return 0;
}
static int philips_tu1216_request_firmware(struct dvb_frontend *fe,
const struct firmware **fw, char *name)
{
struct budget *budget = (struct budget *) fe->dvb->priv;
return request_firmware(fw, name, &budget->dev->pci->dev);
}
static int philips_sd1878_ci_set_symbol_rate(struct dvb_frontend *fe,
u32 srate, u32 ratio)
{
u8 aclk = 0;
u8 bclk = 0;
u8 m1;
aclk = 0xb5;
if (srate < 2000000)
bclk = 0x86;
else if (srate < 5000000)
bclk = 0x89;
else if (srate < 15000000)
bclk = 0x8f;
else if (srate < 45000000)
bclk = 0x95;
m1 = 0x14;
if (srate < 4000000)
m1 = 0x10;
stv0299_writereg(fe, 0x0e, 0x23);
stv0299_writereg(fe, 0x0f, 0x94);
stv0299_writereg(fe, 0x10, 0x39);
stv0299_writereg(fe, 0x13, aclk);
stv0299_writereg(fe, 0x14, bclk);
stv0299_writereg(fe, 0x15, 0xc9);
stv0299_writereg(fe, 0x1f, (ratio >> 16) & 0xff);
stv0299_writereg(fe, 0x20, (ratio >> 8) & 0xff);
stv0299_writereg(fe, 0x21, (ratio) & 0xf0);
stv0299_writereg(fe, 0x0f, 0x80 | m1);
return 0;
}
static u8 read_pwm(struct budget_av *budget_av)
{
u8 b = 0xff;
u8 pwm;
struct i2c_msg msg[] = { {.addr = 0x50,.flags = 0,.buf = &b,.len = 1},
{.addr = 0x50,.flags = I2C_M_RD,.buf = &pwm,.len = 1}
};
if ((i2c_transfer(&budget_av->budget.i2c_adap, msg, 2) != 2)
|| (pwm == 0xff))
pwm = 0x48;
return pwm;
}
static void frontend_init(struct budget_av *budget_av)
{
struct saa7146_dev * saa = budget_av->budget.dev;
struct dvb_frontend * fe = NULL;
saa7146_setgpio(saa, 0, SAA7146_GPIO_OUTLO);
msleep(100);
switch (saa->pci->subsystem_device) {
case SUBID_DVBS_KNC1_PLUS:
case SUBID_DVBC_KNC1_PLUS:
case SUBID_DVBT_KNC1_PLUS:
case SUBID_DVBC_EASYWATCH:
case SUBID_DVBC_KNC1_PLUS_MK3:
case SUBID_DVBS2_KNC1:
case SUBID_DVBS2_KNC1_OEM:
case SUBID_DVBS2_EASYWATCH:
saa7146_setgpio(saa, 3, SAA7146_GPIO_OUTHI);
break;
}
switch (saa->pci->subsystem_device) {
case SUBID_DVBS_KNC1:
budget_av->reinitialise_demod = 1;
case SUBID_DVBS_KNC1_PLUS:
case SUBID_DVBS_EASYWATCH_1:
if (saa->pci->subsystem_vendor == 0x1894) {
fe = dvb_attach(stv0299_attach, &cinergy_1200s_1894_0010_config,
&budget_av->budget.i2c_adap);
if (fe) {
dvb_attach(tua6100_attach, fe, 0x60, &budget_av->budget.i2c_adap);
}
} else {
fe = dvb_attach(stv0299_attach, &typhoon_config,
&budget_av->budget.i2c_adap);
if (fe) {
fe->ops.tuner_ops.set_params = philips_su1278_ty_ci_tuner_set_params;
}
}
break;
case SUBID_DVBS_TV_STAR:
case SUBID_DVBS_TV_STAR_PLUS_X4:
case SUBID_DVBS_TV_STAR_CI:
case SUBID_DVBS_CYNERGY1200N:
case SUBID_DVBS_EASYWATCH:
case SUBID_DVBS_EASYWATCH_2:
fe = dvb_attach(stv0299_attach, &philips_sd1878_config,
&budget_av->budget.i2c_adap);
if (fe) {
dvb_attach(dvb_pll_attach, fe, 0x60,
&budget_av->budget.i2c_adap,
DVB_PLL_PHILIPS_SD1878_TDA8261);
}
break;
case SUBID_DVBS_TYPHOON:
fe = dvb_attach(stv0299_attach, &typhoon_config,
&budget_av->budget.i2c_adap);
if (fe) {
fe->ops.tuner_ops.set_params = philips_su1278_ty_ci_tuner_set_params;
}
break;
case SUBID_DVBS2_KNC1:
case SUBID_DVBS2_KNC1_OEM:
case SUBID_DVBS2_EASYWATCH:
budget_av->reinitialise_demod = 1;
if ((fe = dvb_attach(stb0899_attach, &knc1_dvbs2_config, &budget_av->budget.i2c_adap)))
dvb_attach(tda8261_attach, fe, &sd1878c_config, &budget_av->budget.i2c_adap);
break;
case SUBID_DVBS_CINERGY1200:
fe = dvb_attach(stv0299_attach, &cinergy_1200s_config,
&budget_av->budget.i2c_adap);
if (fe) {
fe->ops.tuner_ops.set_params = philips_su1278_ty_ci_tuner_set_params;
}
break;
case SUBID_DVBC_KNC1:
case SUBID_DVBC_KNC1_PLUS:
case SUBID_DVBC_CINERGY1200:
case SUBID_DVBC_EASYWATCH:
budget_av->reinitialise_demod = 1;
budget_av->budget.dev->i2c_bitrate = SAA7146_I2C_BUS_BIT_RATE_240;
fe = dvb_attach(tda10021_attach, &philips_cu1216_config,
&budget_av->budget.i2c_adap,
read_pwm(budget_av));
if (fe == NULL)
fe = dvb_attach(tda10021_attach, &philips_cu1216_config_altaddress,
&budget_av->budget.i2c_adap,
read_pwm(budget_av));
if (fe) {
fe->ops.tuner_ops.set_params = philips_cu1216_tuner_set_params;
}
break;
case SUBID_DVBC_EASYWATCH_MK3:
case SUBID_DVBC_CINERGY1200_MK3:
case SUBID_DVBC_KNC1_MK3:
case SUBID_DVBC_KNC1_TDA10024:
case SUBID_DVBC_KNC1_PLUS_MK3:
budget_av->reinitialise_demod = 1;
budget_av->budget.dev->i2c_bitrate = SAA7146_I2C_BUS_BIT_RATE_240;
fe = dvb_attach(tda10023_attach,
&philips_cu1216_tda10023_config,
&budget_av->budget.i2c_adap,
read_pwm(budget_av));
if (fe) {
fe->ops.tuner_ops.set_params = philips_cu1216_tuner_set_params;
}
break;
case SUBID_DVBT_EASYWATCH:
case SUBID_DVBT_KNC1:
case SUBID_DVBT_KNC1_PLUS:
case SUBID_DVBT_CINERGY1200:
budget_av->reinitialise_demod = 1;
fe = dvb_attach(tda10046_attach, &philips_tu1216_config,
&budget_av->budget.i2c_adap);
if (fe) {
fe->ops.tuner_ops.init = philips_tu1216_tuner_init;
fe->ops.tuner_ops.set_params = philips_tu1216_tuner_set_params;
}
break;
}
if (fe == NULL) {
pr_err("A frontend driver was not found for device [%04x:%04x] subsystem [%04x:%04x]\n",
saa->pci->vendor,
saa->pci->device,
saa->pci->subsystem_vendor,
saa->pci->subsystem_device);
return;
}
budget_av->budget.dvb_frontend = fe;
if (dvb_register_frontend(&budget_av->budget.dvb_adapter,
budget_av->budget.dvb_frontend)) {
pr_err("Frontend registration failed!\n");
dvb_frontend_detach(budget_av->budget.dvb_frontend);
budget_av->budget.dvb_frontend = NULL;
}
}
static void budget_av_irq(struct saa7146_dev *dev, u32 * isr)
{
struct budget_av *budget_av = (struct budget_av *) dev->ext_priv;
dprintk(8, "dev: %p, budget_av: %p\n", dev, budget_av);
if (*isr & MASK_10)
ttpci_budget_irq10_handler(dev, isr);
}
static int budget_av_detach(struct saa7146_dev *dev)
{
struct budget_av *budget_av = (struct budget_av *) dev->ext_priv;
int err;
dprintk(2, "dev: %p\n", dev);
if (1 == budget_av->has_saa7113) {
saa7146_setgpio(dev, 0, SAA7146_GPIO_OUTLO);
msleep(200);
saa7146_unregister_device(&budget_av->vd, dev);
saa7146_vv_release(dev);
}
if (budget_av->budget.ci_present)
ciintf_deinit(budget_av);
if (budget_av->budget.dvb_frontend != NULL) {
dvb_unregister_frontend(budget_av->budget.dvb_frontend);
dvb_frontend_detach(budget_av->budget.dvb_frontend);
}
err = ttpci_budget_deinit(&budget_av->budget);
kfree(budget_av);
return err;
}
static int vidioc_enum_input(struct file *file, void *fh, struct v4l2_input *i)
{
dprintk(1, "VIDIOC_ENUMINPUT %d\n", i->index);
if (i->index >= KNC1_INPUTS)
return -EINVAL;
memcpy(i, &knc1_inputs[i->index], sizeof(struct v4l2_input));
return 0;
}
static int vidioc_g_input(struct file *file, void *fh, unsigned int *i)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct budget_av *budget_av = (struct budget_av *)dev->ext_priv;
*i = budget_av->cur_input;
dprintk(1, "VIDIOC_G_INPUT %d\n", *i);
return 0;
}
static int vidioc_s_input(struct file *file, void *fh, unsigned int input)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct budget_av *budget_av = (struct budget_av *)dev->ext_priv;
dprintk(1, "VIDIOC_S_INPUT %d\n", input);
return saa7113_setinput(budget_av, input);
}
static int budget_av_attach(struct saa7146_dev *dev, struct saa7146_pci_extension_data *info)
{
struct budget_av *budget_av;
u8 *mac;
int err;
dprintk(2, "dev: %p\n", dev);
if (!(budget_av = kzalloc(sizeof(struct budget_av), GFP_KERNEL)))
return -ENOMEM;
budget_av->has_saa7113 = 0;
budget_av->budget.ci_present = 0;
dev->ext_priv = budget_av;
err = ttpci_budget_init(&budget_av->budget, dev, info, THIS_MODULE,
adapter_nr);
if (err) {
kfree(budget_av);
return err;
}
saa7146_write(dev, DD1_STREAM_B, 0x04000000);
saa7146_write(dev, DD1_INIT, 0x07000600);
saa7146_write(dev, MC2, MASK_09 | MASK_25 | MASK_10 | MASK_26);
if (saa7113_init(budget_av) == 0) {
budget_av->has_saa7113 = 1;
if (0 != saa7146_vv_init(dev, &vv_data)) {
ERR("cannot init vv subsystem\n");
return err;
}
vv_data.ops.vidioc_enum_input = vidioc_enum_input;
vv_data.ops.vidioc_g_input = vidioc_g_input;
vv_data.ops.vidioc_s_input = vidioc_s_input;
if ((err = saa7146_register_device(&budget_av->vd, dev, "knc1", VFL_TYPE_GRABBER))) {
ERR("cannot register capture v4l2 device\n");
saa7146_vv_release(dev);
return err;
}
saa7146_set_hps_source_and_sync(dev, SAA7146_HPS_SOURCE_PORT_A,
SAA7146_HPS_SYNC_PORT_A);
saa7113_setinput(budget_av, 0);
}
saa7146_write(dev, PCI_BT_V1, 0x1c00101f);
mac = budget_av->budget.dvb_adapter.proposed_mac;
if (i2c_readregs(&budget_av->budget.i2c_adap, 0xa0, 0x30, mac, 6)) {
pr_err("KNC1-%d: Could not read MAC from KNC1 card\n",
budget_av->budget.dvb_adapter.num);
memset(mac, 0, 6);
} else {
pr_info("KNC1-%d: MAC addr = %pM\n",
budget_av->budget.dvb_adapter.num, mac);
}
budget_av->budget.dvb_adapter.priv = budget_av;
frontend_init(budget_av);
ciintf_init(budget_av);
ttpci_budget_init_hooks(&budget_av->budget);
return 0;
}
static int __init budget_av_init(void)
{
return saa7146_register_extension(&budget_extension);
}
static void __exit budget_av_exit(void)
{
saa7146_unregister_extension(&budget_extension);
}
