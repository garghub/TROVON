unsigned int twl_rev(void)
{
return twl_id;
}
int twl_i2c_write(u8 mod_no, u8 *value, u8 reg, unsigned num_bytes)
{
int ret;
int sid;
struct twl_client *twl;
struct i2c_msg *msg;
if (unlikely(mod_no > TWL_MODULE_LAST)) {
pr_err("%s: invalid module number %d\n", DRIVER_NAME, mod_no);
return -EPERM;
}
if (unlikely(!inuse)) {
pr_err("%s: not initialized\n", DRIVER_NAME);
return -EPERM;
}
sid = twl_map[mod_no].sid;
if (unlikely(sid == SUB_CHIP_ID_INVAL)) {
pr_err("%s: module %d is not part of the pmic\n",
DRIVER_NAME, mod_no);
return -EINVAL;
}
twl = &twl_modules[sid];
mutex_lock(&twl->xfer_lock);
msg = &twl->xfer_msg[0];
msg->addr = twl->address;
msg->len = num_bytes + 1;
msg->flags = 0;
msg->buf = value;
*value = twl_map[mod_no].base + reg;
ret = i2c_transfer(twl->client->adapter, twl->xfer_msg, 1);
mutex_unlock(&twl->xfer_lock);
if (ret != 1) {
pr_err("%s: i2c_write failed to transfer all messages\n",
DRIVER_NAME);
if (ret < 0)
return ret;
else
return -EIO;
} else {
return 0;
}
}
int twl_i2c_read(u8 mod_no, u8 *value, u8 reg, unsigned num_bytes)
{
int ret;
u8 val;
int sid;
struct twl_client *twl;
struct i2c_msg *msg;
if (unlikely(mod_no > TWL_MODULE_LAST)) {
pr_err("%s: invalid module number %d\n", DRIVER_NAME, mod_no);
return -EPERM;
}
if (unlikely(!inuse)) {
pr_err("%s: not initialized\n", DRIVER_NAME);
return -EPERM;
}
sid = twl_map[mod_no].sid;
if (unlikely(sid == SUB_CHIP_ID_INVAL)) {
pr_err("%s: module %d is not part of the pmic\n",
DRIVER_NAME, mod_no);
return -EINVAL;
}
twl = &twl_modules[sid];
mutex_lock(&twl->xfer_lock);
msg = &twl->xfer_msg[0];
msg->addr = twl->address;
msg->len = 1;
msg->flags = 0;
val = twl_map[mod_no].base + reg;
msg->buf = &val;
msg = &twl->xfer_msg[1];
msg->addr = twl->address;
msg->flags = I2C_M_RD;
msg->len = num_bytes;
msg->buf = value;
ret = i2c_transfer(twl->client->adapter, twl->xfer_msg, 2);
mutex_unlock(&twl->xfer_lock);
if (ret != 2) {
pr_err("%s: i2c_read failed to transfer all messages\n",
DRIVER_NAME);
if (ret < 0)
return ret;
else
return -EIO;
} else {
return 0;
}
}
int twl_i2c_write_u8(u8 mod_no, u8 value, u8 reg)
{
u8 temp_buffer[2] = { 0 };
temp_buffer[1] = value;
return twl_i2c_write(mod_no, temp_buffer, reg, 1);
}
int twl_i2c_read_u8(u8 mod_no, u8 *value, u8 reg)
{
return twl_i2c_read(mod_no, value, reg, 1);
}
static int twl_read_idcode_register(void)
{
int err;
err = twl_i2c_write_u8(TWL4030_MODULE_INTBR, TWL_EEPROM_R_UNLOCK,
REG_UNLOCK_TEST_REG);
if (err) {
pr_err("TWL4030 Unable to unlock IDCODE registers -%d\n", err);
goto fail;
}
err = twl_i2c_read(TWL4030_MODULE_INTBR, (u8 *)(&twl_idcode),
REG_IDCODE_7_0, 4);
if (err) {
pr_err("TWL4030: unable to read IDCODE -%d\n", err);
goto fail;
}
err = twl_i2c_write_u8(TWL4030_MODULE_INTBR, 0x0, REG_UNLOCK_TEST_REG);
if (err)
pr_err("TWL4030 Unable to relock IDCODE registers -%d\n", err);
fail:
return err;
}
int twl_get_type(void)
{
return TWL_SIL_TYPE(twl_idcode);
}
int twl_get_version(void)
{
return TWL_SIL_REV(twl_idcode);
}
int twl_get_hfclk_rate(void)
{
u8 ctrl;
int rate;
twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &ctrl, R_CFG_BOOT);
switch (ctrl & 0x3) {
case HFCLK_FREQ_19p2_MHZ:
rate = 19200000;
break;
case HFCLK_FREQ_26_MHZ:
rate = 26000000;
break;
case HFCLK_FREQ_38p4_MHZ:
rate = 38400000;
break;
default:
pr_err("TWL4030: HFCLK is not configured\n");
rate = -EINVAL;
break;
}
return rate;
}
static struct device *
add_numbered_child(unsigned chip, const char *name, int num,
void *pdata, unsigned pdata_len,
bool can_wakeup, int irq0, int irq1)
{
struct platform_device *pdev;
struct twl_client *twl = &twl_modules[chip];
int status;
pdev = platform_device_alloc(name, num);
if (!pdev) {
dev_dbg(&twl->client->dev, "can't alloc dev\n");
status = -ENOMEM;
goto err;
}
pdev->dev.parent = &twl->client->dev;
if (pdata) {
status = platform_device_add_data(pdev, pdata, pdata_len);
if (status < 0) {
dev_dbg(&pdev->dev, "can't add platform_data\n");
goto err;
}
}
if (irq0) {
struct resource r[2] = {
{ .start = irq0, .flags = IORESOURCE_IRQ, },
{ .start = irq1, .flags = IORESOURCE_IRQ, },
};
status = platform_device_add_resources(pdev, r, irq1 ? 2 : 1);
if (status < 0) {
dev_dbg(&pdev->dev, "can't add irqs\n");
goto err;
}
}
status = platform_device_add(pdev);
if (status == 0)
device_init_wakeup(&pdev->dev, can_wakeup);
err:
if (status < 0) {
platform_device_put(pdev);
dev_err(&twl->client->dev, "can't add %s dev\n", name);
return ERR_PTR(status);
}
return &pdev->dev;
}
static inline struct device *add_child(unsigned chip, const char *name,
void *pdata, unsigned pdata_len,
bool can_wakeup, int irq0, int irq1)
{
return add_numbered_child(chip, name, -1, pdata, pdata_len,
can_wakeup, irq0, irq1);
}
static struct device *
add_regulator_linked(int num, struct regulator_init_data *pdata,
struct regulator_consumer_supply *consumers,
unsigned num_consumers, unsigned long features)
{
unsigned sub_chip_id;
struct twl_regulator_driver_data drv_data;
if (!pdata)
return NULL;
if (consumers) {
pdata->consumer_supplies = consumers;
pdata->num_consumer_supplies = num_consumers;
}
if (pdata->driver_data) {
struct twl_regulator_driver_data *tmp;
tmp = pdata->driver_data;
tmp->features |= features;
} else {
drv_data.features = features;
drv_data.set_voltage = NULL;
drv_data.get_voltage = NULL;
drv_data.data = NULL;
pdata->driver_data = &drv_data;
}
sub_chip_id = twl_map[TWL_MODULE_PM_MASTER].sid;
return add_numbered_child(sub_chip_id, "twl_reg", num,
pdata, sizeof(*pdata), false, 0, 0);
}
static struct device *
add_regulator(int num, struct regulator_init_data *pdata,
unsigned long features)
{
return add_regulator_linked(num, pdata, NULL, 0, features);
}
static int
add_children(struct twl4030_platform_data *pdata, unsigned irq_base,
unsigned long features)
{
struct device *child;
unsigned sub_chip_id;
if (IS_ENABLED(CONFIG_GPIO_TWL4030) && pdata->gpio) {
child = add_child(SUB_CHIP_ID1, "twl4030_gpio",
pdata->gpio, sizeof(*pdata->gpio),
false, irq_base + GPIO_INTR_OFFSET, 0);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_KEYBOARD_TWL4030) && pdata->keypad) {
child = add_child(SUB_CHIP_ID2, "twl4030_keypad",
pdata->keypad, sizeof(*pdata->keypad),
true, irq_base + KEYPAD_INTR_OFFSET, 0);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_TWL4030_MADC) && pdata->madc) {
child = add_child(2, "twl4030_madc",
pdata->madc, sizeof(*pdata->madc),
true, irq_base + MADC_INTR_OFFSET, 0);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_RTC_DRV_TWL4030)) {
sub_chip_id = twl_map[TWL_MODULE_RTC].sid;
child = add_child(sub_chip_id, "twl_rtc",
NULL, 0,
true, irq_base + RTC_INTR_OFFSET, 0);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_PWM_TWL6030) && twl_class_is_6030()) {
child = add_child(SUB_CHIP_ID1, "twl6030-pwm", NULL, 0,
false, 0, 0);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_TWL4030_USB) && pdata->usb &&
twl_class_is_4030()) {
static struct regulator_consumer_supply usb1v5 = {
.supply = "usb1v5",
};
static struct regulator_consumer_supply usb1v8 = {
.supply = "usb1v8",
};
static struct regulator_consumer_supply usb3v1[] = {
{ .supply = "usb3v1" },
{ .supply = "bci3v1" },
};
if (IS_ENABLED(CONFIG_REGULATOR_TWL4030)) {
struct regulator_init_data usb_fixed = {
.constraints.valid_modes_mask =
REGULATOR_MODE_NORMAL
| REGULATOR_MODE_STANDBY,
.constraints.valid_ops_mask =
REGULATOR_CHANGE_MODE
| REGULATOR_CHANGE_STATUS,
};
child = add_regulator_linked(TWL4030_REG_VUSB1V5,
&usb_fixed, &usb1v5, 1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator_linked(TWL4030_REG_VUSB1V8,
&usb_fixed, &usb1v8, 1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator_linked(TWL4030_REG_VUSB3V1,
&usb_fixed, usb3v1, 2,
features);
if (IS_ERR(child))
return PTR_ERR(child);
}
child = add_child(0, "twl4030_usb",
pdata->usb, sizeof(*pdata->usb),
true,
irq_base + USB_PRES_INTR_OFFSET,
irq_base + USB_INTR_OFFSET);
if (IS_ERR(child))
return PTR_ERR(child);
if (IS_ENABLED(CONFIG_REGULATOR_TWL4030) && child) {
usb1v5.dev_name = dev_name(child);
usb1v8.dev_name = dev_name(child);
usb3v1[0].dev_name = dev_name(child);
}
}
if (IS_ENABLED(CONFIG_TWL6030_USB) && pdata->usb &&
twl_class_is_6030()) {
static struct regulator_consumer_supply usb3v3;
int regulator;
if (IS_ENABLED(CONFIG_REGULATOR_TWL4030)) {
struct regulator_init_data usb_fixed = {
.constraints.valid_modes_mask =
REGULATOR_MODE_NORMAL
| REGULATOR_MODE_STANDBY,
.constraints.valid_ops_mask =
REGULATOR_CHANGE_MODE
| REGULATOR_CHANGE_STATUS,
};
if (features & TWL6025_SUBCLASS) {
usb3v3.supply = "ldousb";
regulator = TWL6025_REG_LDOUSB;
} else {
usb3v3.supply = "vusb";
regulator = TWL6030_REG_VUSB;
}
child = add_regulator_linked(regulator, &usb_fixed,
&usb3v3, 1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
}
pdata->usb->features = features;
child = add_child(0, "twl6030_usb",
pdata->usb, sizeof(*pdata->usb),
true,
irq_base + USBOTG_INTR_OFFSET,
irq_base + USB_PRES_INTR_OFFSET);
if (IS_ERR(child))
return PTR_ERR(child);
if (IS_ENABLED(CONFIG_REGULATOR_TWL4030) && child)
usb3v3.dev_name = dev_name(child);
} else if (IS_ENABLED(CONFIG_REGULATOR_TWL4030) &&
twl_class_is_6030()) {
if (features & TWL6025_SUBCLASS)
child = add_regulator(TWL6025_REG_LDOUSB,
pdata->ldousb, features);
else
child = add_regulator(TWL6030_REG_VUSB,
pdata->vusb, features);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_TWL4030_WATCHDOG) && twl_class_is_4030()) {
child = add_child(0, "twl4030_wdt", NULL, 0, false, 0, 0);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_INPUT_TWL4030_PWRBUTTON) && twl_class_is_4030()) {
child = add_child(1, "twl4030_pwrbutton",
NULL, 0, true, irq_base + 8 + 0, 0);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_MFD_TWL4030_AUDIO) && pdata->audio &&
twl_class_is_4030()) {
sub_chip_id = twl_map[TWL_MODULE_AUDIO_VOICE].sid;
child = add_child(sub_chip_id, "twl4030-audio",
pdata->audio, sizeof(*pdata->audio),
false, 0, 0);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_REGULATOR_TWL4030) && twl_class_is_4030()) {
child = add_regulator(TWL4030_REG_VPLL1, pdata->vpll1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VIO, pdata->vio,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VDD1, pdata->vdd1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VDD2, pdata->vdd2,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VMMC1, pdata->vmmc1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VDAC, pdata->vdac,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator((features & TWL4030_VAUX2)
? TWL4030_REG_VAUX2_4030
: TWL4030_REG_VAUX2,
pdata->vaux2, features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VINTANA1, pdata->vintana1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VINTANA2, pdata->vintana2,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VINTDIG, pdata->vintdig,
features);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_REGULATOR_TWL4030) && !(features & TPS_SUBSET)
&& twl_class_is_4030()) {
child = add_regulator(TWL4030_REG_VPLL2, pdata->vpll2,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VMMC2, pdata->vmmc2,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VSIM, pdata->vsim,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VAUX1, pdata->vaux1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VAUX3, pdata->vaux3,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL4030_REG_VAUX4, pdata->vaux4,
features);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_REGULATOR_TWL4030) && twl_class_is_6030() &&
!(features & TWL6025_SUBCLASS)) {
child = add_regulator(TWL6030_REG_VDD1, pdata->vdd1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_VDD2, pdata->vdd2,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_VDD3, pdata->vdd3,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_V1V8, pdata->v1v8,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_V2V1, pdata->v2v1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_VMMC, pdata->vmmc,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_VPP, pdata->vpp,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_VUSIM, pdata->vusim,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_VCXIO, pdata->vcxio,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_VDAC, pdata->vdac,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_VAUX1_6030, pdata->vaux1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_VAUX2_6030, pdata->vaux2,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_VAUX3_6030, pdata->vaux3,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6030_REG_CLK32KG, pdata->clk32kg,
features);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_REGULATOR_TWL4030) && twl_class_is_6030()) {
child = add_regulator(TWL6030_REG_VANA, pdata->vana,
features);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_REGULATOR_TWL4030) && twl_class_is_6030() &&
(features & TWL6025_SUBCLASS)) {
child = add_regulator(TWL6025_REG_LDO5, pdata->ldo5,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6025_REG_LDO1, pdata->ldo1,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6025_REG_LDO7, pdata->ldo7,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6025_REG_LDO6, pdata->ldo6,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6025_REG_LDOLN, pdata->ldoln,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6025_REG_LDO2, pdata->ldo2,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6025_REG_LDO4, pdata->ldo4,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6025_REG_LDO3, pdata->ldo3,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6025_REG_SMPS3, pdata->smps3,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6025_REG_SMPS4, pdata->smps4,
features);
if (IS_ERR(child))
return PTR_ERR(child);
child = add_regulator(TWL6025_REG_VIO, pdata->vio6025,
features);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (IS_ENABLED(CONFIG_CHARGER_TWL4030) && pdata->bci &&
!(features & (TPS_SUBSET | TWL5031))) {
child = add_child(3, "twl4030_bci",
pdata->bci, sizeof(*pdata->bci), false,
irq_base + BCI_PRES_INTR_OFFSET,
irq_base + BCI_INTR_OFFSET);
if (IS_ERR(child))
return PTR_ERR(child);
}
return 0;
}
static inline int __init protect_pm_master(void)
{
int e = 0;
e = twl_i2c_write_u8(TWL4030_MODULE_PM_MASTER, 0,
TWL4030_PM_MASTER_PROTECT_KEY);
return e;
}
static inline int __init unprotect_pm_master(void)
{
int e = 0;
e |= twl_i2c_write_u8(TWL4030_MODULE_PM_MASTER,
TWL4030_PM_MASTER_KEY_CFG1,
TWL4030_PM_MASTER_PROTECT_KEY);
e |= twl_i2c_write_u8(TWL4030_MODULE_PM_MASTER,
TWL4030_PM_MASTER_KEY_CFG2,
TWL4030_PM_MASTER_PROTECT_KEY);
return e;
}
static void clocks_init(struct device *dev,
struct twl4030_clock_init_data *clock)
{
int e = 0;
struct clk *osc;
u32 rate;
u8 ctrl = HFCLK_FREQ_26_MHZ;
osc = clk_get(dev, "fck");
if (IS_ERR(osc)) {
printk(KERN_WARNING "Skipping twl internal clock init and "
"using bootloader value (unknown osc rate)\n");
return;
}
rate = clk_get_rate(osc);
clk_put(osc);
switch (rate) {
case 19200000:
ctrl = HFCLK_FREQ_19p2_MHZ;
break;
case 26000000:
ctrl = HFCLK_FREQ_26_MHZ;
break;
case 38400000:
ctrl = HFCLK_FREQ_38p4_MHZ;
break;
}
ctrl |= HIGH_PERF_SQ;
if (clock && clock->ck32k_lowpwr_enable)
ctrl |= CK32K_LOWPWR_EN;
e |= unprotect_pm_master();
e |= twl_i2c_write_u8(TWL_MODULE_PM_MASTER, ctrl, R_CFG_BOOT);
e |= protect_pm_master();
if (e < 0)
pr_err("%s: clock init err [%d]\n", DRIVER_NAME, e);
}
static int twl_remove(struct i2c_client *client)
{
unsigned i, num_slaves;
int status;
if (twl_class_is_4030()) {
status = twl4030_exit_irq();
num_slaves = TWL_NUM_SLAVES;
} else {
status = twl6030_exit_irq();
num_slaves = TWL_NUM_SLAVES - 1;
}
if (status < 0)
return status;
for (i = 0; i < num_slaves; i++) {
struct twl_client *twl = &twl_modules[i];
if (twl->client && twl->client != client)
i2c_unregister_device(twl->client);
twl_modules[i].client = NULL;
}
inuse = false;
return 0;
}
static int __devinit
twl_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct twl4030_platform_data *pdata = client->dev.platform_data;
struct device_node *node = client->dev.of_node;
struct platform_device *pdev;
int irq_base = 0;
int status;
unsigned i, num_slaves;
pdev = platform_device_alloc(DRIVER_NAME, -1);
if (!pdev) {
dev_err(&client->dev, "can't alloc pdev\n");
return -ENOMEM;
}
status = platform_device_add(pdev);
if (status) {
platform_device_put(pdev);
return status;
}
if (node && !pdata) {
pdata = devm_kzalloc(&client->dev,
sizeof(struct twl4030_platform_data),
GFP_KERNEL);
if (!pdata) {
status = -ENOMEM;
goto free;
}
}
if (!pdata) {
dev_dbg(&client->dev, "no platform data?\n");
status = -EINVAL;
goto free;
}
platform_set_drvdata(pdev, pdata);
if (i2c_check_functionality(client->adapter, I2C_FUNC_I2C) == 0) {
dev_dbg(&client->dev, "can't talk I2C?\n");
status = -EIO;
goto free;
}
if (inuse) {
dev_dbg(&client->dev, "driver is already in use\n");
status = -EBUSY;
goto free;
}
if ((id->driver_data) & TWL6030_CLASS) {
twl_id = TWL6030_CLASS_ID;
twl_map = &twl6030_map[0];
num_slaves = TWL_NUM_SLAVES - 1;
} else {
twl_id = TWL4030_CLASS_ID;
twl_map = &twl4030_map[0];
num_slaves = TWL_NUM_SLAVES;
}
for (i = 0; i < num_slaves; i++) {
struct twl_client *twl = &twl_modules[i];
twl->address = client->addr + i;
if (i == 0) {
twl->client = client;
} else {
twl->client = i2c_new_dummy(client->adapter,
twl->address);
if (!twl->client) {
dev_err(&client->dev,
"can't attach client %d\n", i);
status = -ENOMEM;
goto fail;
}
}
mutex_init(&twl->xfer_lock);
}
inuse = true;
clocks_init(&pdev->dev, pdata->clock);
if (twl_id == TWL4030_CLASS_ID) {
status = twl_read_idcode_register();
WARN(status < 0, "Error: reading twl_idcode register value\n");
}
if (IS_ENABLED(CONFIG_TWL4030_POWER) && pdata->power)
twl4030_power_init(pdata->power);
if (client->irq) {
if (twl_class_is_4030()) {
twl4030_init_chip_irq(id->name);
irq_base = twl4030_init_irq(&client->dev, client->irq);
} else {
irq_base = twl6030_init_irq(&client->dev, client->irq);
}
if (irq_base < 0) {
status = irq_base;
goto fail;
}
}
if (twl_class_is_4030()) {
u8 temp;
twl_i2c_read_u8(TWL4030_MODULE_INTBR, &temp, REG_GPPUPDCTR1);
temp &= ~(SR_I2C_SDA_CTRL_PU | SR_I2C_SCL_CTRL_PU | \
I2C_SDA_CTRL_PU | I2C_SCL_CTRL_PU);
twl_i2c_write_u8(TWL4030_MODULE_INTBR, temp, REG_GPPUPDCTR1);
}
status = -ENODEV;
if (node)
status = of_platform_populate(node, NULL, NULL, &client->dev);
if (status)
status = add_children(pdata, irq_base, id->driver_data);
fail:
if (status < 0)
twl_remove(client);
free:
if (status < 0)
platform_device_unregister(pdev);
return status;
}
static int __init twl_init(void)
{
return i2c_add_driver(&twl_driver);
}
static void __exit twl_exit(void)
{
i2c_del_driver(&twl_driver);
}
