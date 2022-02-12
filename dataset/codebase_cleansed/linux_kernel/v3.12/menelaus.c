static int menelaus_write_reg(int reg, u8 value)
{
int val = i2c_smbus_write_byte_data(the_menelaus->client, reg, value);
if (val < 0) {
pr_err(DRIVER_NAME ": write error");
return val;
}
return 0;
}
static int menelaus_read_reg(int reg)
{
int val = i2c_smbus_read_byte_data(the_menelaus->client, reg);
if (val < 0)
pr_err(DRIVER_NAME ": read error");
return val;
}
static int menelaus_enable_irq(int irq)
{
if (irq > 7) {
irq -= 8;
the_menelaus->mask2 &= ~(1 << irq);
return menelaus_write_reg(MENELAUS_INT_MASK2,
the_menelaus->mask2);
} else {
the_menelaus->mask1 &= ~(1 << irq);
return menelaus_write_reg(MENELAUS_INT_MASK1,
the_menelaus->mask1);
}
}
static int menelaus_disable_irq(int irq)
{
if (irq > 7) {
irq -= 8;
the_menelaus->mask2 |= (1 << irq);
return menelaus_write_reg(MENELAUS_INT_MASK2,
the_menelaus->mask2);
} else {
the_menelaus->mask1 |= (1 << irq);
return menelaus_write_reg(MENELAUS_INT_MASK1,
the_menelaus->mask1);
}
}
static int menelaus_ack_irq(int irq)
{
if (irq > 7)
return menelaus_write_reg(MENELAUS_INT_ACK2, 1 << (irq - 8));
else
return menelaus_write_reg(MENELAUS_INT_ACK1, 1 << irq);
}
static int menelaus_add_irq_work(int irq,
void (*handler)(struct menelaus_chip *))
{
int ret = 0;
mutex_lock(&the_menelaus->lock);
the_menelaus->handlers[irq] = handler;
ret = menelaus_enable_irq(irq);
mutex_unlock(&the_menelaus->lock);
return ret;
}
static int menelaus_remove_irq_work(int irq)
{
int ret = 0;
mutex_lock(&the_menelaus->lock);
ret = menelaus_disable_irq(irq);
the_menelaus->handlers[irq] = NULL;
mutex_unlock(&the_menelaus->lock);
return ret;
}
static void menelaus_mmc_cd_work(struct menelaus_chip *menelaus_hw)
{
int reg;
unsigned char card_mask = 0;
reg = menelaus_read_reg(MENELAUS_MCT_PIN_ST);
if (reg < 0)
return;
if (!(reg & 0x1))
card_mask |= MCT_PIN_ST_S1_CD_ST;
if (!(reg & 0x2))
card_mask |= MCT_PIN_ST_S2_CD_ST;
if (menelaus_hw->mmc_callback)
menelaus_hw->mmc_callback(menelaus_hw->mmc_callback_data,
card_mask);
}
int menelaus_set_mmc_opendrain(int slot, int enable)
{
int ret, val;
if (slot != 1 && slot != 2)
return -EINVAL;
mutex_lock(&the_menelaus->lock);
ret = menelaus_read_reg(MENELAUS_MCT_CTRL1);
if (ret < 0) {
mutex_unlock(&the_menelaus->lock);
return ret;
}
val = ret;
if (slot == 1) {
if (enable)
val |= MCT_CTRL1_S1_CMD_OD;
else
val &= ~MCT_CTRL1_S1_CMD_OD;
} else {
if (enable)
val |= MCT_CTRL1_S2_CMD_OD;
else
val &= ~MCT_CTRL1_S2_CMD_OD;
}
ret = menelaus_write_reg(MENELAUS_MCT_CTRL1, val);
mutex_unlock(&the_menelaus->lock);
return ret;
}
int menelaus_set_slot_sel(int enable)
{
int ret;
mutex_lock(&the_menelaus->lock);
ret = menelaus_read_reg(MENELAUS_GPIO_CTRL);
if (ret < 0)
goto out;
ret |= GPIO2_DIR_INPUT;
if (enable)
ret |= GPIO_CTRL_SLOTSELEN;
else
ret &= ~GPIO_CTRL_SLOTSELEN;
ret = menelaus_write_reg(MENELAUS_GPIO_CTRL, ret);
out:
mutex_unlock(&the_menelaus->lock);
return ret;
}
int menelaus_set_mmc_slot(int slot, int enable, int power, int cd_en)
{
int ret, val;
if (slot != 1 && slot != 2)
return -EINVAL;
if (power >= 3)
return -EINVAL;
mutex_lock(&the_menelaus->lock);
ret = menelaus_read_reg(MENELAUS_MCT_CTRL2);
if (ret < 0)
goto out;
val = ret;
if (slot == 1) {
if (cd_en)
val |= MCT_CTRL2_S1CD_BUFEN | MCT_CTRL2_S1CD_DBEN;
else
val &= ~(MCT_CTRL2_S1CD_BUFEN | MCT_CTRL2_S1CD_DBEN);
} else {
if (cd_en)
val |= MCT_CTRL2_S2CD_BUFEN | MCT_CTRL2_S2CD_BEN;
else
val &= ~(MCT_CTRL2_S2CD_BUFEN | MCT_CTRL2_S2CD_BEN);
}
ret = menelaus_write_reg(MENELAUS_MCT_CTRL2, val);
if (ret < 0)
goto out;
ret = menelaus_read_reg(MENELAUS_MCT_CTRL3);
if (ret < 0)
goto out;
val = ret;
if (slot == 1) {
if (enable)
val |= MCT_CTRL3_SLOT1_EN;
else
val &= ~MCT_CTRL3_SLOT1_EN;
} else {
int b;
if (enable)
val |= MCT_CTRL3_SLOT2_EN;
else
val &= ~MCT_CTRL3_SLOT2_EN;
b = menelaus_read_reg(MENELAUS_MCT_CTRL2);
b &= ~(MCT_CTRL2_VS2_SEL_D0 | MCT_CTRL2_VS2_SEL_D1);
b |= power;
ret = menelaus_write_reg(MENELAUS_MCT_CTRL2, b);
if (ret < 0)
goto out;
}
val &= ~(MCT_CTRL3_S1_AUTO_EN | MCT_CTRL3_S2_AUTO_EN);
ret = menelaus_write_reg(MENELAUS_MCT_CTRL3, val);
out:
mutex_unlock(&the_menelaus->lock);
return ret;
}
int menelaus_register_mmc_callback(void (*callback)(void *data, u8 card_mask),
void *data)
{
int ret = 0;
the_menelaus->mmc_callback_data = data;
the_menelaus->mmc_callback = callback;
ret = menelaus_add_irq_work(MENELAUS_MMC_S1CD_IRQ,
menelaus_mmc_cd_work);
if (ret < 0)
return ret;
ret = menelaus_add_irq_work(MENELAUS_MMC_S2CD_IRQ,
menelaus_mmc_cd_work);
if (ret < 0)
return ret;
ret = menelaus_add_irq_work(MENELAUS_MMC_S1D1_IRQ,
menelaus_mmc_cd_work);
if (ret < 0)
return ret;
ret = menelaus_add_irq_work(MENELAUS_MMC_S2D1_IRQ,
menelaus_mmc_cd_work);
return ret;
}
void menelaus_unregister_mmc_callback(void)
{
menelaus_remove_irq_work(MENELAUS_MMC_S1CD_IRQ);
menelaus_remove_irq_work(MENELAUS_MMC_S2CD_IRQ);
menelaus_remove_irq_work(MENELAUS_MMC_S1D1_IRQ);
menelaus_remove_irq_work(MENELAUS_MMC_S2D1_IRQ);
the_menelaus->mmc_callback = NULL;
the_menelaus->mmc_callback_data = NULL;
}
static int menelaus_set_voltage(const struct menelaus_vtg *vtg, int mV,
int vtg_val, int mode)
{
int val, ret;
struct i2c_client *c = the_menelaus->client;
mutex_lock(&the_menelaus->lock);
if (!vtg)
goto set_voltage;
ret = menelaus_read_reg(vtg->vtg_reg);
if (ret < 0)
goto out;
val = ret & ~(((1 << vtg->vtg_bits) - 1) << vtg->vtg_shift);
val |= vtg_val << vtg->vtg_shift;
dev_dbg(&c->dev, "Setting voltage '%s'"
"to %d mV (reg 0x%02x, val 0x%02x)\n",
vtg->name, mV, vtg->vtg_reg, val);
ret = menelaus_write_reg(vtg->vtg_reg, val);
if (ret < 0)
goto out;
set_voltage:
ret = menelaus_write_reg(vtg->mode_reg, mode);
out:
mutex_unlock(&the_menelaus->lock);
if (ret == 0) {
msleep(1);
}
return ret;
}
static int menelaus_get_vtg_value(int vtg, const struct menelaus_vtg_value *tbl,
int n)
{
int i;
for (i = 0; i < n; i++, tbl++)
if (tbl->vtg == vtg)
return tbl->val;
return -EINVAL;
}
int menelaus_set_vcore_sw(unsigned int mV)
{
int val, ret;
struct i2c_client *c = the_menelaus->client;
val = menelaus_get_vtg_value(mV, vcore_values,
ARRAY_SIZE(vcore_values));
if (val < 0)
return -EINVAL;
dev_dbg(&c->dev, "Setting VCORE to %d mV (val 0x%02x)\n", mV, val);
mutex_lock(&the_menelaus->lock);
ret = menelaus_write_reg(MENELAUS_VCORE_CTRL1, val);
if (ret == 0)
the_menelaus->vcore_hw_mode = 0;
mutex_unlock(&the_menelaus->lock);
msleep(1);
return ret;
}
int menelaus_set_vcore_hw(unsigned int roof_mV, unsigned int floor_mV)
{
int fval, rval, val, ret;
struct i2c_client *c = the_menelaus->client;
rval = menelaus_get_vtg_value(roof_mV, vcore_values,
ARRAY_SIZE(vcore_values));
if (rval < 0)
return -EINVAL;
fval = menelaus_get_vtg_value(floor_mV, vcore_values,
ARRAY_SIZE(vcore_values));
if (fval < 0)
return -EINVAL;
dev_dbg(&c->dev, "Setting VCORE FLOOR to %d mV and ROOF to %d mV\n",
floor_mV, roof_mV);
mutex_lock(&the_menelaus->lock);
ret = menelaus_write_reg(MENELAUS_VCORE_CTRL3, fval);
if (ret < 0)
goto out;
ret = menelaus_write_reg(MENELAUS_VCORE_CTRL4, rval);
if (ret < 0)
goto out;
if (!the_menelaus->vcore_hw_mode) {
val = menelaus_read_reg(MENELAUS_VCORE_CTRL1);
val |= (VCORE_CTRL1_HW_NSW | VCORE_CTRL1_BYP_COMP);
ret = menelaus_write_reg(MENELAUS_VCORE_CTRL1, val);
the_menelaus->vcore_hw_mode = 1;
}
msleep(1);
out:
mutex_unlock(&the_menelaus->lock);
return ret;
}
int menelaus_set_vmem(unsigned int mV)
{
int val;
if (mV == 0)
return menelaus_set_voltage(&vmem_vtg, 0, 0, 0);
val = menelaus_get_vtg_value(mV, vmem_values, ARRAY_SIZE(vmem_values));
if (val < 0)
return -EINVAL;
return menelaus_set_voltage(&vmem_vtg, mV, val, 0x02);
}
int menelaus_set_vio(unsigned int mV)
{
int val;
if (mV == 0)
return menelaus_set_voltage(&vio_vtg, 0, 0, 0);
val = menelaus_get_vtg_value(mV, vio_values, ARRAY_SIZE(vio_values));
if (val < 0)
return -EINVAL;
return menelaus_set_voltage(&vio_vtg, mV, val, 0x02);
}
int menelaus_set_vdcdc(int dcdc, unsigned int mV)
{
const struct menelaus_vtg *vtg;
int val;
if (dcdc != 2 && dcdc != 3)
return -EINVAL;
if (dcdc == 2)
vtg = &vdcdc2_vtg;
else
vtg = &vdcdc3_vtg;
if (mV == 0)
return menelaus_set_voltage(vtg, 0, 0, 0);
val = menelaus_get_vtg_value(mV, vdcdc_values,
ARRAY_SIZE(vdcdc_values));
if (val < 0)
return -EINVAL;
return menelaus_set_voltage(vtg, mV, val, 0x03);
}
int menelaus_set_vmmc(unsigned int mV)
{
int val;
if (mV == 0)
return menelaus_set_voltage(&vmmc_vtg, 0, 0, 0);
val = menelaus_get_vtg_value(mV, vmmc_values, ARRAY_SIZE(vmmc_values));
if (val < 0)
return -EINVAL;
return menelaus_set_voltage(&vmmc_vtg, mV, val, 0x02);
}
int menelaus_set_vaux(unsigned int mV)
{
int val;
if (mV == 0)
return menelaus_set_voltage(&vaux_vtg, 0, 0, 0);
val = menelaus_get_vtg_value(mV, vaux_values, ARRAY_SIZE(vaux_values));
if (val < 0)
return -EINVAL;
return menelaus_set_voltage(&vaux_vtg, mV, val, 0x02);
}
int menelaus_get_slot_pin_states(void)
{
return menelaus_read_reg(MENELAUS_MCT_PIN_ST);
}
int menelaus_set_regulator_sleep(int enable, u32 val)
{
int t, ret;
struct i2c_client *c = the_menelaus->client;
mutex_lock(&the_menelaus->lock);
ret = menelaus_write_reg(MENELAUS_SLEEP_CTRL2, val);
if (ret < 0)
goto out;
dev_dbg(&c->dev, "regulator sleep configuration: %02x\n", val);
ret = menelaus_read_reg(MENELAUS_GPIO_CTRL);
if (ret < 0)
goto out;
t = (GPIO_CTRL_SLPCTLEN | GPIO3_DIR_INPUT);
if (enable)
ret |= t;
else
ret &= ~t;
ret = menelaus_write_reg(MENELAUS_GPIO_CTRL, ret);
out:
mutex_unlock(&the_menelaus->lock);
return ret;
}
static void menelaus_work(struct work_struct *_menelaus)
{
struct menelaus_chip *menelaus =
container_of(_menelaus, struct menelaus_chip, work);
void (*handler)(struct menelaus_chip *menelaus);
while (1) {
unsigned isr;
isr = (menelaus_read_reg(MENELAUS_INT_STATUS2)
& ~menelaus->mask2) << 8;
isr |= menelaus_read_reg(MENELAUS_INT_STATUS1)
& ~menelaus->mask1;
if (!isr)
break;
while (isr) {
int irq = fls(isr) - 1;
isr &= ~(1 << irq);
mutex_lock(&menelaus->lock);
menelaus_disable_irq(irq);
menelaus_ack_irq(irq);
handler = menelaus->handlers[irq];
if (handler)
handler(menelaus);
menelaus_enable_irq(irq);
mutex_unlock(&menelaus->lock);
}
}
enable_irq(menelaus->client->irq);
}
static irqreturn_t menelaus_irq(int irq, void *_menelaus)
{
struct menelaus_chip *menelaus = _menelaus;
disable_irq_nosync(irq);
(void)schedule_work(&menelaus->work);
return IRQ_HANDLED;
}
static void menelaus_to_time(char *regs, struct rtc_time *t)
{
t->tm_sec = bcd2bin(regs[0]);
t->tm_min = bcd2bin(regs[1]);
if (the_menelaus->rtc_control & RTC_CTRL_MODE12) {
t->tm_hour = bcd2bin(regs[2] & 0x1f) - 1;
if (regs[2] & RTC_HR_PM)
t->tm_hour += 12;
} else
t->tm_hour = bcd2bin(regs[2] & 0x3f);
t->tm_mday = bcd2bin(regs[3]);
t->tm_mon = bcd2bin(regs[4]) - 1;
t->tm_year = bcd2bin(regs[5]) + 100;
}
static int time_to_menelaus(struct rtc_time *t, int regnum)
{
int hour, status;
status = menelaus_write_reg(regnum++, bin2bcd(t->tm_sec));
if (status < 0)
goto fail;
status = menelaus_write_reg(regnum++, bin2bcd(t->tm_min));
if (status < 0)
goto fail;
if (the_menelaus->rtc_control & RTC_CTRL_MODE12) {
hour = t->tm_hour + 1;
if (hour > 12)
hour = RTC_HR_PM | bin2bcd(hour - 12);
else
hour = bin2bcd(hour);
} else
hour = bin2bcd(t->tm_hour);
status = menelaus_write_reg(regnum++, hour);
if (status < 0)
goto fail;
status = menelaus_write_reg(regnum++, bin2bcd(t->tm_mday));
if (status < 0)
goto fail;
status = menelaus_write_reg(regnum++, bin2bcd(t->tm_mon + 1));
if (status < 0)
goto fail;
status = menelaus_write_reg(regnum++, bin2bcd(t->tm_year - 100));
if (status < 0)
goto fail;
return 0;
fail:
dev_err(&the_menelaus->client->dev, "rtc write reg %02x, err %d\n",
--regnum, status);
return status;
}
static int menelaus_read_time(struct device *dev, struct rtc_time *t)
{
struct i2c_msg msg[2];
char regs[7];
int status;
regs[0] = MENELAUS_RTC_SEC;
msg[0].addr = MENELAUS_I2C_ADDRESS;
msg[0].flags = 0;
msg[0].len = 1;
msg[0].buf = regs;
msg[1].addr = MENELAUS_I2C_ADDRESS;
msg[1].flags = I2C_M_RD;
msg[1].len = sizeof(regs);
msg[1].buf = regs;
status = i2c_transfer(the_menelaus->client->adapter, msg, 2);
if (status != 2) {
dev_err(dev, "%s error %d\n", "read", status);
return -EIO;
}
menelaus_to_time(regs, t);
t->tm_wday = bcd2bin(regs[6]);
return 0;
}
static int menelaus_set_time(struct device *dev, struct rtc_time *t)
{
int status;
status = time_to_menelaus(t, MENELAUS_RTC_SEC);
if (status < 0)
return status;
status = menelaus_write_reg(MENELAUS_RTC_WKDAY, bin2bcd(t->tm_wday));
if (status < 0) {
dev_err(&the_menelaus->client->dev, "rtc write reg %02x "
"err %d\n", MENELAUS_RTC_WKDAY, status);
return status;
}
status = menelaus_write_reg(MENELAUS_RTC_UPDATE, RTC_UPDATE_EVERY);
if (status < 0)
dev_err(&the_menelaus->client->dev, "rtc commit time, err %d\n",
status);
return 0;
}
static int menelaus_read_alarm(struct device *dev, struct rtc_wkalrm *w)
{
struct i2c_msg msg[2];
char regs[6];
int status;
regs[0] = MENELAUS_RTC_AL_SEC;
msg[0].addr = MENELAUS_I2C_ADDRESS;
msg[0].flags = 0;
msg[0].len = 1;
msg[0].buf = regs;
msg[1].addr = MENELAUS_I2C_ADDRESS;
msg[1].flags = I2C_M_RD;
msg[1].len = sizeof(regs);
msg[1].buf = regs;
status = i2c_transfer(the_menelaus->client->adapter, msg, 2);
if (status != 2) {
dev_err(dev, "%s error %d\n", "alarm read", status);
return -EIO;
}
menelaus_to_time(regs, &w->time);
w->enabled = !!(the_menelaus->rtc_control & RTC_CTRL_AL_EN);
w->pending = 0;
return 0;
}
static int menelaus_set_alarm(struct device *dev, struct rtc_wkalrm *w)
{
int status;
if (the_menelaus->client->irq <= 0 && w->enabled)
return -ENODEV;
if (the_menelaus->rtc_control & RTC_CTRL_AL_EN) {
the_menelaus->rtc_control &= ~RTC_CTRL_AL_EN;
status = menelaus_write_reg(MENELAUS_RTC_CTRL,
the_menelaus->rtc_control);
if (status < 0)
return status;
}
status = time_to_menelaus(&w->time, MENELAUS_RTC_AL_SEC);
if (status < 0)
return status;
if (w->enabled) {
the_menelaus->rtc_control |= RTC_CTRL_AL_EN;
status = menelaus_write_reg(MENELAUS_RTC_CTRL,
the_menelaus->rtc_control);
}
return status;
}
static void menelaus_rtc_update_work(struct menelaus_chip *m)
{
local_irq_disable();
rtc_update_irq(m->rtc, 1, RTC_IRQF | RTC_UF);
local_irq_enable();
}
static int menelaus_ioctl(struct device *dev, unsigned cmd, unsigned long arg)
{
int status;
if (the_menelaus->client->irq <= 0)
return -ENOIOCTLCMD;
switch (cmd) {
case RTC_AIE_ON:
if (the_menelaus->rtc_control & RTC_CTRL_AL_EN)
return 0;
the_menelaus->rtc_control |= RTC_CTRL_AL_EN;
break;
case RTC_AIE_OFF:
if (!(the_menelaus->rtc_control & RTC_CTRL_AL_EN))
return 0;
the_menelaus->rtc_control &= ~RTC_CTRL_AL_EN;
break;
case RTC_UIE_ON:
if (the_menelaus->uie)
return 0;
status = menelaus_remove_irq_work(MENELAUS_RTCTMR_IRQ);
status = menelaus_add_irq_work(MENELAUS_RTCTMR_IRQ,
menelaus_rtc_update_work);
if (status == 0)
the_menelaus->uie = 1;
return status;
case RTC_UIE_OFF:
if (!the_menelaus->uie)
return 0;
status = menelaus_remove_irq_work(MENELAUS_RTCTMR_IRQ);
if (status == 0)
the_menelaus->uie = 0;
return status;
default:
return -ENOIOCTLCMD;
}
return menelaus_write_reg(MENELAUS_RTC_CTRL, the_menelaus->rtc_control);
}
static void menelaus_rtc_alarm_work(struct menelaus_chip *m)
{
local_irq_disable();
rtc_update_irq(m->rtc, 1, RTC_IRQF | RTC_AF);
local_irq_enable();
the_menelaus->rtc_control &= ~RTC_CTRL_AL_EN;
menelaus_write_reg(MENELAUS_RTC_CTRL, the_menelaus->rtc_control);
}
static inline void menelaus_rtc_init(struct menelaus_chip *m)
{
int alarm = (m->client->irq > 0);
if (!(menelaus_read_reg(MENELAUS_OSC_CTRL) & 0x80)) {
dev_dbg(&m->client->dev, "no 32k oscillator\n");
return;
}
if (alarm) {
if (menelaus_add_irq_work(MENELAUS_RTCALM_IRQ,
menelaus_rtc_alarm_work) < 0) {
dev_err(&m->client->dev, "can't handle RTC alarm\n");
return;
}
device_init_wakeup(&m->client->dev, 1);
}
m->rtc_control = menelaus_read_reg(MENELAUS_RTC_CTRL);
if (!(m->rtc_control & RTC_CTRL_RTC_EN)
|| (m->rtc_control & RTC_CTRL_AL_EN)
|| (m->rtc_control & RTC_CTRL_EVERY_MASK)) {
if (!(m->rtc_control & RTC_CTRL_RTC_EN)) {
dev_warn(&m->client->dev, "rtc clock needs setting\n");
m->rtc_control |= RTC_CTRL_RTC_EN;
}
m->rtc_control &= ~RTC_CTRL_EVERY_MASK;
m->rtc_control &= ~RTC_CTRL_AL_EN;
menelaus_write_reg(MENELAUS_RTC_CTRL, m->rtc_control);
}
m->rtc = rtc_device_register(DRIVER_NAME,
&m->client->dev,
&menelaus_rtc_ops, THIS_MODULE);
if (IS_ERR(m->rtc)) {
if (alarm) {
menelaus_remove_irq_work(MENELAUS_RTCALM_IRQ);
device_init_wakeup(&m->client->dev, 0);
}
dev_err(&m->client->dev, "can't register RTC: %d\n",
(int) PTR_ERR(m->rtc));
the_menelaus->rtc = NULL;
}
}
static inline void menelaus_rtc_init(struct menelaus_chip *m)
{
}
static int menelaus_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct menelaus_chip *menelaus;
int rev = 0, val;
int err = 0;
struct menelaus_platform_data *menelaus_pdata =
dev_get_platdata(&client->dev);
if (the_menelaus) {
dev_dbg(&client->dev, "only one %s for now\n",
DRIVER_NAME);
return -ENODEV;
}
menelaus = devm_kzalloc(&client->dev, sizeof(*menelaus), GFP_KERNEL);
if (!menelaus)
return -ENOMEM;
i2c_set_clientdata(client, menelaus);
the_menelaus = menelaus;
menelaus->client = client;
rev = menelaus_read_reg(MENELAUS_REV);
if (rev < 0) {
pr_err(DRIVER_NAME ": device not found");
return -ENODEV;
}
menelaus_write_reg(MENELAUS_INT_ACK1, 0xff);
menelaus_write_reg(MENELAUS_INT_ACK2, 0xff);
menelaus_write_reg(MENELAUS_INT_MASK1, 0xff);
menelaus_write_reg(MENELAUS_INT_MASK2, 0xff);
menelaus->mask1 = 0xff;
menelaus->mask2 = 0xff;
menelaus_write_reg(MENELAUS_MCT_CTRL1, 0x73);
if (client->irq > 0) {
err = request_irq(client->irq, menelaus_irq, 0,
DRIVER_NAME, menelaus);
if (err) {
dev_dbg(&client->dev, "can't get IRQ %d, err %d\n",
client->irq, err);
return err;
}
}
mutex_init(&menelaus->lock);
INIT_WORK(&menelaus->work, menelaus_work);
pr_info("Menelaus rev %d.%d\n", rev >> 4, rev & 0x0f);
val = menelaus_read_reg(MENELAUS_VCORE_CTRL1);
if (val < 0)
goto fail;
if (val & (1 << 7))
menelaus->vcore_hw_mode = 1;
else
menelaus->vcore_hw_mode = 0;
if (menelaus_pdata != NULL && menelaus_pdata->late_init != NULL) {
err = menelaus_pdata->late_init(&client->dev);
if (err < 0)
goto fail;
}
menelaus_rtc_init(menelaus);
return 0;
fail:
free_irq(client->irq, menelaus);
flush_work(&menelaus->work);
return err;
}
static int __exit menelaus_remove(struct i2c_client *client)
{
struct menelaus_chip *menelaus = i2c_get_clientdata(client);
free_irq(client->irq, menelaus);
flush_work(&menelaus->work);
the_menelaus = NULL;
return 0;
}
static int __init menelaus_init(void)
{
int res;
res = i2c_add_driver(&menelaus_i2c_driver);
if (res < 0) {
pr_err(DRIVER_NAME ": driver registration failed\n");
return res;
}
return 0;
}
static void __exit menelaus_exit(void)
{
i2c_del_driver(&menelaus_i2c_driver);
}
