static int tps65217_config_charger(struct tps65217_charger *charger)
{
int ret;
dev_dbg(charger->dev, "%s\n", __func__);
ret = tps65217_clear_bits(charger->tps, TPS65217_REG_CHGCONFIG1,
TPS65217_CHGCONFIG1_NTC_TYPE,
TPS65217_PROTECT_NONE);
if (ret) {
dev_err(charger->dev,
"failed to set 100k NTC setting: %d\n", ret);
return ret;
}
return 0;
}
static int tps65217_enable_charging(struct tps65217_charger *charger)
{
int ret;
if (charger->ac_online)
return 0;
dev_dbg(charger->dev, "%s: enable charging\n", __func__);
ret = tps65217_set_bits(charger->tps, TPS65217_REG_CHGCONFIG1,
TPS65217_CHGCONFIG1_CHG_EN,
TPS65217_CHGCONFIG1_CHG_EN,
TPS65217_PROTECT_NONE);
if (ret) {
dev_err(charger->dev,
"%s: Error in writing CHG_EN in reg 0x%x: %d\n",
__func__, TPS65217_REG_CHGCONFIG1, ret);
return ret;
}
charger->ac_online = 1;
return 0;
}
static int tps65217_ac_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct tps65217_charger *charger = power_supply_get_drvdata(psy);
if (psp == POWER_SUPPLY_PROP_ONLINE) {
val->intval = charger->ac_online;
return 0;
}
return -EINVAL;
}
static irqreturn_t tps65217_charger_irq(int irq, void *dev)
{
int ret, val;
struct tps65217_charger *charger = dev;
charger->prev_ac_online = charger->ac_online;
ret = tps65217_reg_read(charger->tps, TPS65217_REG_STATUS, &val);
if (ret < 0) {
dev_err(charger->dev, "%s: Error in reading reg 0x%x\n",
__func__, TPS65217_REG_STATUS);
return IRQ_HANDLED;
}
dev_dbg(charger->dev, "%s: 0x%x\n", __func__, val);
if (val & TPS65217_STATUS_ACPWR) {
ret = tps65217_enable_charging(charger);
if (ret) {
dev_err(charger->dev,
"failed to enable charger: %d\n", ret);
return IRQ_HANDLED;
}
} else {
charger->ac_online = 0;
}
if (charger->prev_ac_online != charger->ac_online)
power_supply_changed(charger->ac);
ret = tps65217_reg_read(charger->tps, TPS65217_REG_CHGCONFIG0, &val);
if (ret < 0) {
dev_err(charger->dev, "%s: Error in reading reg 0x%x\n",
__func__, TPS65217_REG_CHGCONFIG0);
return IRQ_HANDLED;
}
if (val & TPS65217_CHGCONFIG0_ACTIVE)
dev_dbg(charger->dev, "%s: charger is charging\n", __func__);
else
dev_dbg(charger->dev,
"%s: charger is NOT charging\n", __func__);
return IRQ_HANDLED;
}
static int tps65217_charger_poll_task(void *data)
{
set_freezable();
while (!kthread_should_stop()) {
schedule_timeout_interruptible(POLL_INTERVAL);
try_to_freeze();
tps65217_charger_irq(-1, data);
}
return 0;
}
static int tps65217_charger_probe(struct platform_device *pdev)
{
struct tps65217 *tps = dev_get_drvdata(pdev->dev.parent);
struct tps65217_charger *charger;
struct power_supply_config cfg = {};
int ret;
dev_dbg(&pdev->dev, "%s\n", __func__);
charger = devm_kzalloc(&pdev->dev, sizeof(*charger), GFP_KERNEL);
if (!charger)
return -ENOMEM;
charger->tps = tps;
charger->dev = &pdev->dev;
cfg.of_node = pdev->dev.of_node;
cfg.drv_data = charger;
charger->ac = devm_power_supply_register(&pdev->dev,
&tps65217_charger_desc,
&cfg);
if (IS_ERR(charger->ac)) {
dev_err(&pdev->dev, "failed: power supply register\n");
return PTR_ERR(charger->ac);
}
ret = tps65217_config_charger(charger);
if (ret < 0) {
dev_err(charger->dev, "charger config failed, err %d\n", ret);
return ret;
}
charger->poll_task = kthread_run(tps65217_charger_poll_task,
charger, "ktps65217charger");
if (IS_ERR(charger->poll_task)) {
ret = PTR_ERR(charger->poll_task);
dev_err(charger->dev, "Unable to run kthread err %d\n", ret);
return ret;
}
return 0;
}
static int tps65217_charger_remove(struct platform_device *pdev)
{
struct tps65217_charger *charger = platform_get_drvdata(pdev);
kthread_stop(charger->poll_task);
return 0;
}
