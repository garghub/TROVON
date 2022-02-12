static irqreturn_t pwrkey_press_irq(int irq, void *_pwr)
{
struct input_dev *pwr = _pwr;
input_report_key(pwr, KEY_POWER, 1);
input_sync(pwr);
return IRQ_HANDLED;
}
static irqreturn_t pwrkey_release_irq(int irq, void *_pwr)
{
struct input_dev *pwr = _pwr;
input_report_key(pwr, KEY_POWER, 0);
input_sync(pwr);
return IRQ_HANDLED;
}
static int __maybe_unused pmic8xxx_pwrkey_suspend(struct device *dev)
{
struct pmic8xxx_pwrkey *pwrkey = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(pwrkey->key_press_irq);
return 0;
}
static int __maybe_unused pmic8xxx_pwrkey_resume(struct device *dev)
{
struct pmic8xxx_pwrkey *pwrkey = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(pwrkey->key_press_irq);
return 0;
}
static void pmic8xxx_pwrkey_shutdown(struct platform_device *pdev)
{
struct pmic8xxx_pwrkey *pwrkey = platform_get_drvdata(pdev);
int error;
u8 mask, val;
bool reset = system_state == SYSTEM_RESTART;
if (pwrkey->shutdown_fn) {
error = pwrkey->shutdown_fn(pwrkey, reset);
if (error)
return;
}
mask = PON_CNTL_1_PULL_UP_EN | PON_CNTL_1_USB_PWR_EN;
mask |= PON_CNTL_1_WD_EN_RESET;
val = mask;
if (!reset)
val &= ~PON_CNTL_1_WD_EN_RESET;
regmap_update_bits(pwrkey->regmap, PON_CNTL_1, mask, val);
}
static int pm8058_disable_smps_locally_set_pull_down(struct regmap *regmap,
u16 ctrl_addr, u16 test2_addr, u16 master_enable_addr,
u8 master_enable_bit)
{
int error;
u8 vref_sel, vlow_sel, band, vprog, bank;
unsigned int reg;
bank = PM8058_REGULATOR_BANK_SEL(7);
error = regmap_write(regmap, test2_addr, bank);
if (error)
return error;
error = regmap_read(regmap, test2_addr, &reg);
if (error)
return error;
reg &= PM8058_SMPS_ADVANCED_MODE_MASK;
if (reg == PM8058_SMPS_ADVANCED_MODE) {
error = regmap_read(regmap, ctrl_addr, &reg);
if (error)
return error;
band = reg & PM8058_SMPS_ADVANCED_BAND_MASK;
band >>= PM8058_SMPS_ADVANCED_BAND_SHIFT;
switch (band) {
case 3:
vref_sel = 0;
vlow_sel = 0;
break;
case 2:
vref_sel = PM8058_SMPS_LEGACY_VREF_SEL;
vlow_sel = 0;
break;
case 1:
vref_sel = PM8058_SMPS_LEGACY_VREF_SEL;
vlow_sel = PM8058_SMPS_LEGACY_VLOW_SEL;
break;
default:
pr_err("%s: regulator already disabled\n", __func__);
return -EPERM;
}
vprog = reg & PM8058_SMPS_ADVANCED_VPROG_MASK;
vprog = (vprog + 1) >> 1;
if (vprog > PM8058_SMPS_LEGACY_VPROG_MASK)
vprog = PM8058_SMPS_LEGACY_VPROG_MASK;
bank = PM8058_REGULATOR_BANK_SEL(1);
error = regmap_write(regmap, test2_addr, bank);
if (error)
return error;
error = regmap_update_bits(regmap, test2_addr,
PM8058_REGULATOR_BANK_WRITE | PM8058_REGULATOR_BANK_MASK
| PM8058_SMPS_LEGACY_VLOW_SEL,
PM8058_REGULATOR_BANK_WRITE |
PM8058_REGULATOR_BANK_SEL(1) | vlow_sel);
if (error)
return error;
bank = PM8058_REGULATOR_BANK_SEL(7);
error = regmap_write(regmap, test2_addr, bank);
if (error)
return error;
error = regmap_update_bits(regmap, test2_addr,
PM8058_REGULATOR_BANK_WRITE |
PM8058_REGULATOR_BANK_MASK |
PM8058_SMPS_ADVANCED_MODE_MASK,
PM8058_REGULATOR_BANK_WRITE |
PM8058_REGULATOR_BANK_SEL(7) |
PM8058_SMPS_LEGACY_MODE);
if (error)
return error;
error = regmap_update_bits(regmap, ctrl_addr,
PM8058_REGULATOR_ENABLE_MASK |
PM8058_REGULATOR_PULL_DOWN_MASK |
PM8058_SMPS_LEGACY_VREF_SEL |
PM8058_SMPS_LEGACY_VPROG_MASK,
PM8058_REGULATOR_ENABLE | PM8058_REGULATOR_PULL_DOWN_EN
| vref_sel | vprog);
if (error)
return error;
}
error = regmap_update_bits(regmap, master_enable_addr,
master_enable_bit, master_enable_bit);
if (error)
return error;
return regmap_update_bits(regmap, ctrl_addr,
PM8058_REGULATOR_ENABLE_MASK | PM8058_REGULATOR_PULL_DOWN_MASK,
PM8058_REGULATOR_DISABLE | PM8058_REGULATOR_PULL_DOWN_EN);
}
static int pm8058_disable_ldo_locally_set_pull_down(struct regmap *regmap,
u16 ctrl_addr, u16 master_enable_addr, u8 master_enable_bit)
{
int error;
error = regmap_update_bits(regmap, master_enable_addr,
master_enable_bit, master_enable_bit);
if (error)
return error;
return regmap_update_bits(regmap, ctrl_addr,
PM8058_REGULATOR_ENABLE_MASK | PM8058_REGULATOR_PULL_DOWN_MASK,
PM8058_REGULATOR_DISABLE | PM8058_REGULATOR_PULL_DOWN_EN);
}
static int pm8058_pwrkey_shutdown(struct pmic8xxx_pwrkey *pwrkey, bool reset)
{
int error;
struct regmap *regmap = pwrkey->regmap;
u8 mask, val;
if (!reset) {
pm8058_disable_smps_locally_set_pull_down(regmap,
PM8058_S0_CTRL, PM8058_S0_TEST2,
REG_PM8058_VREG_EN_MSM, BIT(7));
pm8058_disable_smps_locally_set_pull_down(regmap,
PM8058_S1_CTRL, PM8058_S1_TEST2,
REG_PM8058_VREG_EN_MSM, BIT(6));
pm8058_disable_smps_locally_set_pull_down(regmap,
PM8058_S3_CTRL, PM8058_S3_TEST2,
REG_PM8058_VREG_EN_GRP_5_4, BIT(7) | BIT(4));
pm8058_disable_ldo_locally_set_pull_down(regmap,
PM8058_L21_CTRL, REG_PM8058_VREG_EN_GRP_5_4,
BIT(1));
}
error = regmap_update_bits(regmap, PM8058_L22_CTRL, 0xbf, 0x93);
if (error)
return error;
mask = SLEEP_CTRL_SMPL_EN_RESET;
val = 0;
if (reset)
val = mask;
return regmap_update_bits(regmap, PM8058_SLEEP_CTRL, mask, val);
}
static int pm8921_pwrkey_shutdown(struct pmic8xxx_pwrkey *pwrkey, bool reset)
{
struct regmap *regmap = pwrkey->regmap;
u8 mask = SLEEP_CTRL_SMPL_EN_RESET;
u8 val = 0;
if (reset)
val = mask;
return regmap_update_bits(regmap, PM8921_SLEEP_CTRL, mask, val);
}
static int pmic8xxx_pwrkey_probe(struct platform_device *pdev)
{
struct input_dev *pwr;
int key_release_irq = platform_get_irq(pdev, 0);
int key_press_irq = platform_get_irq(pdev, 1);
int err;
unsigned int delay;
unsigned int pon_cntl;
struct regmap *regmap;
struct pmic8xxx_pwrkey *pwrkey;
u32 kpd_delay;
bool pull_up;
if (of_property_read_u32(pdev->dev.of_node, "debounce", &kpd_delay))
kpd_delay = 15625;
if (kpd_delay > USEC_PER_SEC * 2 || kpd_delay < USEC_PER_SEC / 64) {
dev_err(&pdev->dev, "invalid power key trigger delay\n");
return -EINVAL;
}
pull_up = of_property_read_bool(pdev->dev.of_node, "pull-up");
regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!regmap) {
dev_err(&pdev->dev, "failed to locate regmap for the device\n");
return -ENODEV;
}
pwrkey = devm_kzalloc(&pdev->dev, sizeof(*pwrkey), GFP_KERNEL);
if (!pwrkey)
return -ENOMEM;
pwrkey->shutdown_fn = of_device_get_match_data(&pdev->dev);
pwrkey->regmap = regmap;
pwrkey->key_press_irq = key_press_irq;
pwr = devm_input_allocate_device(&pdev->dev);
if (!pwr) {
dev_dbg(&pdev->dev, "Can't allocate power button\n");
return -ENOMEM;
}
input_set_capability(pwr, EV_KEY, KEY_POWER);
pwr->name = "pmic8xxx_pwrkey";
pwr->phys = "pmic8xxx_pwrkey/input0";
delay = (kpd_delay << 6) / USEC_PER_SEC;
delay = ilog2(delay);
err = regmap_read(regmap, PON_CNTL_1, &pon_cntl);
if (err < 0) {
dev_err(&pdev->dev, "failed reading PON_CNTL_1 err=%d\n", err);
return err;
}
pon_cntl &= ~PON_CNTL_TRIG_DELAY_MASK;
pon_cntl |= (delay & PON_CNTL_TRIG_DELAY_MASK);
if (pull_up)
pon_cntl |= PON_CNTL_PULL_UP;
else
pon_cntl &= ~PON_CNTL_PULL_UP;
err = regmap_write(regmap, PON_CNTL_1, pon_cntl);
if (err < 0) {
dev_err(&pdev->dev, "failed writing PON_CNTL_1 err=%d\n", err);
return err;
}
err = devm_request_irq(&pdev->dev, key_press_irq, pwrkey_press_irq,
IRQF_TRIGGER_RISING,
"pmic8xxx_pwrkey_press", pwr);
if (err) {
dev_err(&pdev->dev, "Can't get %d IRQ for pwrkey: %d\n",
key_press_irq, err);
return err;
}
err = devm_request_irq(&pdev->dev, key_release_irq, pwrkey_release_irq,
IRQF_TRIGGER_RISING,
"pmic8xxx_pwrkey_release", pwr);
if (err) {
dev_err(&pdev->dev, "Can't get %d IRQ for pwrkey: %d\n",
key_release_irq, err);
return err;
}
err = input_register_device(pwr);
if (err) {
dev_err(&pdev->dev, "Can't register power key: %d\n", err);
return err;
}
platform_set_drvdata(pdev, pwrkey);
device_init_wakeup(&pdev->dev, 1);
return 0;
}
