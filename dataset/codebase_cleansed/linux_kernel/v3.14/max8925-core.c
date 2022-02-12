static inline struct max8925_irq_data *irq_to_max8925(struct max8925_chip *chip,
int irq)
{
return &max8925_irqs[irq - chip->irq_base];
}
static irqreturn_t max8925_irq(int irq, void *data)
{
struct max8925_chip *chip = data;
struct max8925_irq_data *irq_data;
struct i2c_client *i2c;
int read_reg = -1, value = 0;
int i;
for (i = 0; i < ARRAY_SIZE(max8925_irqs); i++) {
irq_data = &max8925_irqs[i];
if (irq_data->tsc_irq)
continue;
if (irq_data->flags == FLAGS_RTC)
i2c = chip->rtc;
else if (irq_data->flags == FLAGS_ADC)
i2c = chip->adc;
else
i2c = chip->i2c;
if (read_reg != irq_data->reg) {
read_reg = irq_data->reg;
value = max8925_reg_read(i2c, irq_data->reg);
}
if (value & irq_data->enable)
handle_nested_irq(chip->irq_base + i);
}
return IRQ_HANDLED;
}
static irqreturn_t max8925_tsc_irq(int irq, void *data)
{
struct max8925_chip *chip = data;
struct max8925_irq_data *irq_data;
struct i2c_client *i2c;
int read_reg = -1, value = 0;
int i;
for (i = 0; i < ARRAY_SIZE(max8925_irqs); i++) {
irq_data = &max8925_irqs[i];
if (!irq_data->tsc_irq)
continue;
if (irq_data->flags == FLAGS_RTC)
i2c = chip->rtc;
else if (irq_data->flags == FLAGS_ADC)
i2c = chip->adc;
else
i2c = chip->i2c;
if (read_reg != irq_data->reg) {
read_reg = irq_data->reg;
value = max8925_reg_read(i2c, irq_data->reg);
}
if (value & irq_data->enable)
handle_nested_irq(chip->irq_base + i);
}
return IRQ_HANDLED;
}
static void max8925_irq_lock(struct irq_data *data)
{
struct max8925_chip *chip = irq_data_get_irq_chip_data(data);
mutex_lock(&chip->irq_lock);
}
static void max8925_irq_sync_unlock(struct irq_data *data)
{
struct max8925_chip *chip = irq_data_get_irq_chip_data(data);
struct max8925_irq_data *irq_data;
static unsigned char cache_chg[2] = {0xff, 0xff};
static unsigned char cache_on[2] = {0xff, 0xff};
static unsigned char cache_rtc = 0xff, cache_tsc = 0xff;
unsigned char irq_chg[2], irq_on[2];
unsigned char irq_rtc, irq_tsc;
int i;
irq_chg[0] = cache_chg[0];
irq_chg[1] = cache_chg[1];
irq_on[0] = cache_on[0];
irq_on[1] = cache_on[1];
irq_rtc = cache_rtc;
irq_tsc = cache_tsc;
for (i = 0; i < ARRAY_SIZE(max8925_irqs); i++) {
irq_data = &max8925_irqs[i];
switch (irq_data->mask_reg) {
case MAX8925_CHG_IRQ1_MASK:
irq_chg[0] &= ~irq_data->enable;
break;
case MAX8925_CHG_IRQ2_MASK:
irq_chg[1] &= ~irq_data->enable;
break;
case MAX8925_ON_OFF_IRQ1_MASK:
irq_on[0] &= ~irq_data->enable;
break;
case MAX8925_ON_OFF_IRQ2_MASK:
irq_on[1] &= ~irq_data->enable;
break;
case MAX8925_RTC_IRQ_MASK:
irq_rtc &= ~irq_data->enable;
break;
case MAX8925_TSC_IRQ_MASK:
irq_tsc &= ~irq_data->enable;
break;
default:
dev_err(chip->dev, "wrong IRQ\n");
break;
}
}
if (cache_chg[0] != irq_chg[0]) {
cache_chg[0] = irq_chg[0];
max8925_reg_write(chip->i2c, MAX8925_CHG_IRQ1_MASK,
irq_chg[0]);
}
if (cache_chg[1] != irq_chg[1]) {
cache_chg[1] = irq_chg[1];
max8925_reg_write(chip->i2c, MAX8925_CHG_IRQ2_MASK,
irq_chg[1]);
}
if (cache_on[0] != irq_on[0]) {
cache_on[0] = irq_on[0];
max8925_reg_write(chip->i2c, MAX8925_ON_OFF_IRQ1_MASK,
irq_on[0]);
}
if (cache_on[1] != irq_on[1]) {
cache_on[1] = irq_on[1];
max8925_reg_write(chip->i2c, MAX8925_ON_OFF_IRQ2_MASK,
irq_on[1]);
}
if (cache_rtc != irq_rtc) {
cache_rtc = irq_rtc;
max8925_reg_write(chip->rtc, MAX8925_RTC_IRQ_MASK, irq_rtc);
}
if (cache_tsc != irq_tsc) {
cache_tsc = irq_tsc;
max8925_reg_write(chip->adc, MAX8925_TSC_IRQ_MASK, irq_tsc);
}
mutex_unlock(&chip->irq_lock);
}
static void max8925_irq_enable(struct irq_data *data)
{
struct max8925_chip *chip = irq_data_get_irq_chip_data(data);
max8925_irqs[data->irq - chip->irq_base].enable
= max8925_irqs[data->irq - chip->irq_base].offs;
}
static void max8925_irq_disable(struct irq_data *data)
{
struct max8925_chip *chip = irq_data_get_irq_chip_data(data);
max8925_irqs[data->irq - chip->irq_base].enable = 0;
}
static int max8925_irq_domain_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
irq_set_chip_data(virq, d->host_data);
irq_set_chip_and_handler(virq, &max8925_irq_chip, handle_edge_irq);
irq_set_nested_thread(virq, 1);
#ifdef CONFIG_ARM
set_irq_flags(virq, IRQF_VALID);
#else
irq_set_noprobe(virq);
#endif
return 0;
}
static int max8925_irq_init(struct max8925_chip *chip, int irq,
struct max8925_platform_data *pdata)
{
unsigned long flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT;
int ret;
struct device_node *node = chip->dev->of_node;
max8925_reg_read(chip->i2c, MAX8925_CHG_IRQ1);
max8925_reg_read(chip->i2c, MAX8925_CHG_IRQ2);
max8925_reg_read(chip->i2c, MAX8925_ON_OFF_IRQ1);
max8925_reg_read(chip->i2c, MAX8925_ON_OFF_IRQ2);
max8925_reg_read(chip->rtc, MAX8925_RTC_IRQ);
max8925_reg_read(chip->adc, MAX8925_TSC_IRQ);
max8925_reg_write(chip->rtc, MAX8925_ALARM0_CNTL, 0);
max8925_reg_write(chip->rtc, MAX8925_ALARM1_CNTL, 0);
max8925_reg_write(chip->i2c, MAX8925_CHG_IRQ1_MASK, 0xff);
max8925_reg_write(chip->i2c, MAX8925_CHG_IRQ2_MASK, 0xff);
max8925_reg_write(chip->i2c, MAX8925_ON_OFF_IRQ1_MASK, 0xff);
max8925_reg_write(chip->i2c, MAX8925_ON_OFF_IRQ2_MASK, 0xff);
max8925_reg_write(chip->rtc, MAX8925_RTC_IRQ_MASK, 0xff);
mutex_init(&chip->irq_lock);
chip->irq_base = irq_alloc_descs(-1, 0, MAX8925_NR_IRQS, 0);
if (chip->irq_base < 0) {
dev_err(chip->dev, "Failed to allocate interrupts, ret:%d\n",
chip->irq_base);
return -EBUSY;
}
irq_domain_add_legacy(node, MAX8925_NR_IRQS, chip->irq_base, 0,
&max8925_irq_domain_ops, chip);
chip->core_irq = irq;
if (!chip->core_irq)
return -EBUSY;
ret = request_threaded_irq(irq, NULL, max8925_irq, flags | IRQF_ONESHOT,
"max8925", chip);
if (ret) {
dev_err(chip->dev, "Failed to request core IRQ: %d\n", ret);
chip->core_irq = 0;
return -EBUSY;
}
max8925_reg_write(chip->adc, MAX8925_TSC_IRQ_MASK, 0x0f);
if (!pdata->tsc_irq) {
dev_warn(chip->dev, "No interrupt support on TSC IRQ\n");
return 0;
}
chip->tsc_irq = pdata->tsc_irq;
ret = request_threaded_irq(chip->tsc_irq, NULL, max8925_tsc_irq,
flags | IRQF_ONESHOT, "max8925-tsc", chip);
if (ret) {
dev_err(chip->dev, "Failed to request TSC IRQ: %d\n", ret);
chip->tsc_irq = 0;
}
return 0;
}
static void init_regulator(struct max8925_chip *chip,
struct max8925_platform_data *pdata)
{
int ret;
if (!pdata)
return;
if (pdata->sd1) {
reg_devs[0].platform_data = pdata->sd1;
reg_devs[0].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->sd2) {
reg_devs[1].platform_data = pdata->sd2;
reg_devs[1].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->sd3) {
reg_devs[2].platform_data = pdata->sd3;
reg_devs[2].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo1) {
reg_devs[3].platform_data = pdata->ldo1;
reg_devs[3].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo2) {
reg_devs[4].platform_data = pdata->ldo2;
reg_devs[4].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo3) {
reg_devs[5].platform_data = pdata->ldo3;
reg_devs[5].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo4) {
reg_devs[6].platform_data = pdata->ldo4;
reg_devs[6].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo5) {
reg_devs[7].platform_data = pdata->ldo5;
reg_devs[7].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo6) {
reg_devs[8].platform_data = pdata->ldo6;
reg_devs[8].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo7) {
reg_devs[9].platform_data = pdata->ldo7;
reg_devs[9].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo8) {
reg_devs[10].platform_data = pdata->ldo8;
reg_devs[10].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo9) {
reg_devs[11].platform_data = pdata->ldo9;
reg_devs[11].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo10) {
reg_devs[12].platform_data = pdata->ldo10;
reg_devs[12].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo11) {
reg_devs[13].platform_data = pdata->ldo11;
reg_devs[13].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo12) {
reg_devs[14].platform_data = pdata->ldo12;
reg_devs[14].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo13) {
reg_devs[15].platform_data = pdata->ldo13;
reg_devs[15].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo14) {
reg_devs[16].platform_data = pdata->ldo14;
reg_devs[16].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo15) {
reg_devs[17].platform_data = pdata->ldo15;
reg_devs[17].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo16) {
reg_devs[18].platform_data = pdata->ldo16;
reg_devs[18].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo17) {
reg_devs[19].platform_data = pdata->ldo17;
reg_devs[19].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo18) {
reg_devs[20].platform_data = pdata->ldo18;
reg_devs[20].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo19) {
reg_devs[21].platform_data = pdata->ldo19;
reg_devs[21].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo20) {
reg_devs[22].platform_data = pdata->ldo20;
reg_devs[22].pdata_size = sizeof(struct regulator_init_data);
}
ret = mfd_add_devices(chip->dev, 0, reg_devs, ARRAY_SIZE(reg_devs),
NULL, 0, NULL);
if (ret < 0) {
dev_err(chip->dev, "Failed to add regulator subdev\n");
return;
}
}
int max8925_device_init(struct max8925_chip *chip,
struct max8925_platform_data *pdata)
{
int ret;
max8925_irq_init(chip, chip->i2c->irq, pdata);
if (pdata && (pdata->power || pdata->touch)) {
max8925_set_bits(chip->i2c, MAX8925_RESET_CNFG, 1, 1);
max8925_set_bits(chip->adc, MAX8925_TSC_CNFG1, 3, 2);
do {
ret = max8925_reg_read(chip->adc, MAX8925_TSC_IRQ);
} while (ret & MAX8925_NREF_OK);
max8925_set_bits(chip->adc, MAX8925_ADC_SCHED, 3, 2);
}
max8925_set_bits(chip->rtc, MAX8925_MPL_CNTL, 1 << 4, 1 << 4);
ret = mfd_add_devices(chip->dev, 0, &rtc_devs[0],
ARRAY_SIZE(rtc_devs),
NULL, chip->irq_base, NULL);
if (ret < 0) {
dev_err(chip->dev, "Failed to add rtc subdev\n");
goto out;
}
ret = mfd_add_devices(chip->dev, 0, &onkey_devs[0],
ARRAY_SIZE(onkey_devs),
NULL, chip->irq_base, NULL);
if (ret < 0) {
dev_err(chip->dev, "Failed to add onkey subdev\n");
goto out_dev;
}
init_regulator(chip, pdata);
if (pdata && pdata->backlight) {
bk_devs[0].platform_data = &pdata->backlight;
bk_devs[0].pdata_size = sizeof(struct max8925_backlight_pdata);
}
ret = mfd_add_devices(chip->dev, 0, bk_devs, ARRAY_SIZE(bk_devs),
NULL, 0, NULL);
if (ret < 0) {
dev_err(chip->dev, "Failed to add backlight subdev\n");
goto out_dev;
}
ret = mfd_add_devices(chip->dev, 0, &power_devs[0],
ARRAY_SIZE(power_devs),
NULL, 0, NULL);
if (ret < 0) {
dev_err(chip->dev,
"Failed to add power supply subdev, err = %d\n", ret);
goto out_dev;
}
if (pdata && pdata->touch) {
ret = mfd_add_devices(chip->dev, 0, &touch_devs[0],
ARRAY_SIZE(touch_devs),
NULL, chip->tsc_irq, NULL);
if (ret < 0) {
dev_err(chip->dev, "Failed to add touch subdev\n");
goto out_dev;
}
}
return 0;
out_dev:
mfd_remove_devices(chip->dev);
out:
return ret;
}
void max8925_device_exit(struct max8925_chip *chip)
{
if (chip->core_irq)
free_irq(chip->core_irq, chip);
if (chip->tsc_irq)
free_irq(chip->tsc_irq, chip);
mfd_remove_devices(chip->dev);
}
