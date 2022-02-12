int tps80031_ext_power_req_config(struct device *dev,
unsigned long ext_ctrl_flag, int preq_bit,
int state_reg_add, int trans_reg_add)
{
u8 res_ass_reg = 0;
int preq_mask_bit = 0;
int ret;
if (!(ext_ctrl_flag & TPS80031_EXT_PWR_REQ))
return 0;
if (ext_ctrl_flag & TPS80031_PWR_REQ_INPUT_PREQ1) {
res_ass_reg = TPS80031_PREQ1_RES_ASS_A + (preq_bit >> 3);
preq_mask_bit = 5;
} else if (ext_ctrl_flag & TPS80031_PWR_REQ_INPUT_PREQ2) {
res_ass_reg = TPS80031_PREQ2_RES_ASS_A + (preq_bit >> 3);
preq_mask_bit = 6;
} else if (ext_ctrl_flag & TPS80031_PWR_REQ_INPUT_PREQ3) {
res_ass_reg = TPS80031_PREQ3_RES_ASS_A + (preq_bit >> 3);
preq_mask_bit = 7;
}
ret = tps80031_set_bits(dev, TPS80031_SLAVE_ID1, res_ass_reg,
BIT(preq_bit & 0x7));
if (ret < 0) {
dev_err(dev, "reg 0x%02x setbit failed, err = %d\n",
res_ass_reg, ret);
return ret;
}
ret = tps80031_clr_bits(dev, TPS80031_SLAVE_ID1,
TPS80031_PHOENIX_MSK_TRANSITION, BIT(preq_mask_bit));
if (ret < 0) {
dev_err(dev, "reg 0x%02x clrbit failed, err = %d\n",
TPS80031_PHOENIX_MSK_TRANSITION, ret);
return ret;
}
if (ext_ctrl_flag & (TPS80031_PWR_REQ_INPUT_PREQ2 |
TPS80031_PWR_REQ_INPUT_PREQ3)) {
ret = tps80031_update(dev, TPS80031_SLAVE_ID1, state_reg_add,
0x0, TPS80031_STATE_MASK);
if (ret < 0)
dev_err(dev, "reg 0x%02x update failed, err = %d\n",
state_reg_add, ret);
} else {
ret = tps80031_update(dev, TPS80031_SLAVE_ID1, trans_reg_add,
TPS80031_TRANS_SLEEP_OFF,
TPS80031_TRANS_SLEEP_MASK);
if (ret < 0)
dev_err(dev, "reg 0x%02x update failed, err = %d\n",
trans_reg_add, ret);
}
return ret;
}
static void tps80031_power_off(void)
{
dev_info(tps80031_power_off_dev->dev, "switching off PMU\n");
tps80031_write(tps80031_power_off_dev->dev, TPS80031_SLAVE_ID1,
TPS80031_PHOENIX_DEV_ON, TPS80031_DEVOFF);
}
static void tps80031_pupd_init(struct tps80031 *tps80031,
struct tps80031_platform_data *pdata)
{
struct tps80031_pupd_init_data *pupd_init_data = pdata->pupd_init_data;
int data_size = pdata->pupd_init_data_size;
int i;
for (i = 0; i < data_size; ++i) {
struct tps80031_pupd_init_data *pupd_init = &pupd_init_data[i];
const struct tps80031_pupd_data *pupd =
&tps80031_pupds[pupd_init->input_pin];
u8 update_value = 0;
u8 update_mask = pupd->pulldown_bit | pupd->pullup_bit;
if (pupd_init->setting == TPS80031_PUPD_PULLDOWN)
update_value = pupd->pulldown_bit;
else if (pupd_init->setting == TPS80031_PUPD_PULLUP)
update_value = pupd->pullup_bit;
tps80031_update(tps80031->dev, TPS80031_SLAVE_ID1, pupd->reg,
update_value, update_mask);
}
}
static int tps80031_init_ext_control(struct tps80031 *tps80031,
struct tps80031_platform_data *pdata)
{
struct device *dev = tps80031->dev;
int ret;
int i;
for (i = 0; i < 9; ++i) {
ret = tps80031_write(dev, TPS80031_SLAVE_ID1,
TPS80031_PREQ1_RES_ASS_A + i, 0);
if (ret < 0) {
dev_err(dev, "reg 0x%02x write failed, err = %d\n",
TPS80031_PREQ1_RES_ASS_A + i, ret);
return ret;
}
}
ret = tps80031_set_bits(dev, TPS80031_SLAVE_ID1,
TPS80031_PHOENIX_MSK_TRANSITION, 0x7 << 5);
if (ret < 0) {
dev_err(dev, "reg 0x%02x set_bits failed, err = %d\n",
TPS80031_PHOENIX_MSK_TRANSITION, ret);
return ret;
}
return ret;
}
static int tps80031_irq_init(struct tps80031 *tps80031, int irq, int irq_base)
{
struct device *dev = tps80031->dev;
int i, ret;
for (i = 0; i < 3; i++)
tps80031_write(dev, TPS80031_SLAVE_ID2,
TPS80031_INT_MSK_STS_A + i, 0x00);
ret = regmap_add_irq_chip(tps80031->regmap[TPS80031_SLAVE_ID2], irq,
IRQF_ONESHOT, irq_base,
&tps80031_irq_chip, &tps80031->irq_data);
if (ret < 0) {
dev_err(dev, "add irq failed, err = %d\n", ret);
return ret;
}
return ret;
}
static bool rd_wr_reg_id0(struct device *dev, unsigned int reg)
{
switch (reg) {
case TPS80031_SMPS1_CFG_FORCE ... TPS80031_SMPS2_CFG_VOLTAGE:
return true;
default:
return false;
}
}
static bool rd_wr_reg_id1(struct device *dev, unsigned int reg)
{
switch (reg) {
case TPS80031_SECONDS_REG ... TPS80031_RTC_RESET_STATUS_REG:
case TPS80031_VALIDITY0 ... TPS80031_VALIDITY7:
case TPS80031_PHOENIX_START_CONDITION ... TPS80031_KEY_PRESS_DUR_CFG:
case TPS80031_SMPS4_CFG_TRANS ... TPS80031_SMPS3_CFG_VOLTAGE:
case TPS80031_BROADCAST_ADDR_ALL ... TPS80031_BROADCAST_ADDR_CLK_RST:
case TPS80031_VANA_CFG_TRANS ... TPS80031_LDO7_CFG_VOLTAGE:
case TPS80031_REGEN1_CFG_TRANS ... TPS80031_TMP_CFG_STATE:
case TPS80031_PREQ1_RES_ASS_A ... TPS80031_PREQ3_RES_ASS_C:
case TPS80031_SMPS_OFFSET ... TPS80031_BATDEBOUNCING:
case TPS80031_CFG_INPUT_PUPD1 ... TPS80031_CFG_SMPS_PD:
case TPS80031_BACKUP_REG:
return true;
default:
return false;
}
}
static bool is_volatile_reg_id1(struct device *dev, unsigned int reg)
{
switch (reg) {
case TPS80031_SMPS4_CFG_TRANS ... TPS80031_SMPS3_CFG_VOLTAGE:
case TPS80031_VANA_CFG_TRANS ... TPS80031_LDO7_CFG_VOLTAGE:
case TPS80031_REGEN1_CFG_TRANS ... TPS80031_TMP_CFG_STATE:
case TPS80031_PREQ1_RES_ASS_A ... TPS80031_PREQ3_RES_ASS_C:
case TPS80031_SMPS_OFFSET ... TPS80031_BATDEBOUNCING:
case TPS80031_CFG_INPUT_PUPD1 ... TPS80031_CFG_SMPS_PD:
return true;
default:
return false;
}
}
static bool rd_wr_reg_id2(struct device *dev, unsigned int reg)
{
switch (reg) {
case TPS80031_USB_VENDOR_ID_LSB ... TPS80031_USB_OTG_REVISION:
case TPS80031_GPADC_CTRL ... TPS80031_CTRL_P1:
case TPS80031_RTCH0_LSB ... TPS80031_GPCH0_MSB:
case TPS80031_TOGGLE1 ... TPS80031_VIBMODE:
case TPS80031_PWM1ON ... TPS80031_PWM2OFF:
case TPS80031_FG_REG_00 ... TPS80031_FG_REG_11:
case TPS80031_INT_STS_A ... TPS80031_INT_MSK_STS_C:
case TPS80031_CONTROLLER_CTRL2 ... TPS80031_LED_PWM_CTRL2:
return true;
default:
return false;
}
}
static bool rd_wr_reg_id3(struct device *dev, unsigned int reg)
{
switch (reg) {
case TPS80031_GPADC_TRIM0 ... TPS80031_GPADC_TRIM18:
return true;
default:
return false;
}
}
static int tps80031_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tps80031_platform_data *pdata = dev_get_platdata(&client->dev);
struct tps80031 *tps80031;
int ret;
uint8_t es_version;
uint8_t ep_ver;
int i;
if (!pdata) {
dev_err(&client->dev, "tps80031 requires platform data\n");
return -EINVAL;
}
tps80031 = devm_kzalloc(&client->dev, sizeof(*tps80031), GFP_KERNEL);
if (!tps80031) {
dev_err(&client->dev, "Malloc failed for tps80031\n");
return -ENOMEM;
}
for (i = 0; i < TPS80031_NUM_SLAVES; i++) {
if (tps80031_slave_address[i] == client->addr)
tps80031->clients[i] = client;
else
tps80031->clients[i] = i2c_new_dummy(client->adapter,
tps80031_slave_address[i]);
if (!tps80031->clients[i]) {
dev_err(&client->dev, "can't attach client %d\n", i);
ret = -ENOMEM;
goto fail_client_reg;
}
i2c_set_clientdata(tps80031->clients[i], tps80031);
tps80031->regmap[i] = devm_regmap_init_i2c(tps80031->clients[i],
&tps80031_regmap_configs[i]);
if (IS_ERR(tps80031->regmap[i])) {
ret = PTR_ERR(tps80031->regmap[i]);
dev_err(&client->dev,
"regmap %d init failed, err %d\n", i, ret);
goto fail_client_reg;
}
}
ret = tps80031_read(&client->dev, TPS80031_SLAVE_ID3,
TPS80031_JTAGVERNUM, &es_version);
if (ret < 0) {
dev_err(&client->dev,
"Silicon version number read failed: %d\n", ret);
goto fail_client_reg;
}
ret = tps80031_read(&client->dev, TPS80031_SLAVE_ID3,
TPS80031_EPROM_REV, &ep_ver);
if (ret < 0) {
dev_err(&client->dev,
"Silicon eeprom version read failed: %d\n", ret);
goto fail_client_reg;
}
dev_info(&client->dev, "ES version 0x%02x and EPROM version 0x%02x\n",
es_version, ep_ver);
tps80031->es_version = es_version;
tps80031->dev = &client->dev;
i2c_set_clientdata(client, tps80031);
tps80031->chip_info = id->driver_data;
ret = tps80031_irq_init(tps80031, client->irq, pdata->irq_base);
if (ret) {
dev_err(&client->dev, "IRQ init failed: %d\n", ret);
goto fail_client_reg;
}
tps80031_pupd_init(tps80031, pdata);
tps80031_init_ext_control(tps80031, pdata);
ret = mfd_add_devices(tps80031->dev, -1,
tps80031_cell, ARRAY_SIZE(tps80031_cell),
NULL, 0,
regmap_irq_get_domain(tps80031->irq_data));
if (ret < 0) {
dev_err(&client->dev, "mfd_add_devices failed: %d\n", ret);
goto fail_mfd_add;
}
if (pdata->use_power_off && !pm_power_off) {
tps80031_power_off_dev = tps80031;
pm_power_off = tps80031_power_off;
}
return 0;
fail_mfd_add:
regmap_del_irq_chip(client->irq, tps80031->irq_data);
fail_client_reg:
for (i = 0; i < TPS80031_NUM_SLAVES; i++) {
if (tps80031->clients[i] && (tps80031->clients[i] != client))
i2c_unregister_device(tps80031->clients[i]);
}
return ret;
}
static int tps80031_remove(struct i2c_client *client)
{
struct tps80031 *tps80031 = i2c_get_clientdata(client);
int i;
if (tps80031_power_off_dev == tps80031) {
tps80031_power_off_dev = NULL;
pm_power_off = NULL;
}
mfd_remove_devices(tps80031->dev);
regmap_del_irq_chip(client->irq, tps80031->irq_data);
for (i = 0; i < TPS80031_NUM_SLAVES; i++) {
if (tps80031->clients[i] != client)
i2c_unregister_device(tps80031->clients[i]);
}
return 0;
}
static int __init tps80031_init(void)
{
return i2c_add_driver(&tps80031_driver);
}
static void __exit tps80031_exit(void)
{
i2c_del_driver(&tps80031_driver);
}
