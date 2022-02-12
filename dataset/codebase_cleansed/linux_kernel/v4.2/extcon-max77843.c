static int max77843_muic_set_path(struct max77843_muic_info *info,
u8 val, bool attached)
{
struct max77843 *max77843 = info->max77843;
int ret = 0;
unsigned int ctrl1, ctrl2;
if (attached)
ctrl1 = val;
else
ctrl1 = CONTROL1_SW_OPEN;
ret = regmap_update_bits(max77843->regmap_muic,
MAX77843_MUIC_REG_CONTROL1,
CONTROL1_COM_SW, ctrl1);
if (ret < 0) {
dev_err(info->dev, "Cannot switch MUIC port\n");
return ret;
}
if (attached)
ctrl2 = MAX77843_MUIC_CONTROL2_CPEN_MASK;
else
ctrl2 = MAX77843_MUIC_CONTROL2_LOWPWR_MASK;
ret = regmap_update_bits(max77843->regmap_muic,
MAX77843_MUIC_REG_CONTROL2,
MAX77843_MUIC_CONTROL2_LOWPWR_MASK |
MAX77843_MUIC_CONTROL2_CPEN_MASK, ctrl2);
if (ret < 0) {
dev_err(info->dev, "Cannot update lowpower mode\n");
return ret;
}
dev_dbg(info->dev,
"CONTROL1 : 0x%02x, CONTROL2 : 0x%02x, state : %s\n",
ctrl1, ctrl2, attached ? "attached" : "detached");
return 0;
}
static int max77843_muic_get_cable_type(struct max77843_muic_info *info,
enum max77843_muic_cable_group group, bool *attached)
{
int adc, chg_type, cable_type, gnd_type;
adc = info->status[MAX77843_MUIC_STATUS1] &
MAX77843_MUIC_STATUS1_ADC_MASK;
adc >>= STATUS1_ADC_SHIFT;
switch (group) {
case MAX77843_CABLE_GROUP_ADC:
if (adc == MAX77843_MUIC_ADC_OPEN) {
*attached = false;
cable_type = info->prev_cable_type;
info->prev_cable_type = MAX77843_MUIC_ADC_OPEN;
} else {
*attached = true;
cable_type = info->prev_cable_type = adc;
}
break;
case MAX77843_CABLE_GROUP_CHG:
chg_type = info->status[MAX77843_MUIC_STATUS2] &
MAX77843_MUIC_STATUS2_CHGTYP_MASK;
if (adc == MAX77843_MUIC_ADC_GROUND) {
if (chg_type == MAX77843_MUIC_CHG_NONE) {
*attached = false;
cable_type = info->prev_chg_type;
info->prev_chg_type = MAX77843_MUIC_CHG_NONE;
} else {
*attached = true;
cable_type = MAX77843_MUIC_CHG_GND;
info->prev_chg_type = MAX77843_MUIC_CHG_GND;
}
break;
}
if (chg_type == MAX77843_MUIC_CHG_NONE) {
*attached = false;
cable_type = info->prev_chg_type;
info->prev_chg_type = MAX77843_MUIC_CHG_NONE;
} else {
*attached = true;
cable_type = info->prev_chg_type = chg_type;
}
break;
case MAX77843_CABLE_GROUP_ADC_GND:
if (adc == MAX77843_MUIC_ADC_OPEN) {
*attached = false;
cable_type = info->prev_gnd_type;
info->prev_gnd_type = MAX77843_MUIC_ADC_OPEN;
} else {
*attached = true;
gnd_type = (info->status[MAX77843_MUIC_STATUS1] &
MAX77843_MUIC_STATUS1_ADC1K_MASK);
gnd_type |= (info->status[MAX77843_MUIC_STATUS2] &
MAX77843_MUIC_STATUS2_VBVOLT_MASK);
gnd_type >>= STATUS2_VBVOLT_SHIFT;
gnd_type |= MAX77843_MUIC_GND_USB_HOST;
cable_type = info->prev_gnd_type = gnd_type;
}
break;
default:
dev_err(info->dev, "Unknown cable group (%d)\n", group);
cable_type = -EINVAL;
break;
}
return cable_type;
}
static int max77843_muic_adc_gnd_handler(struct max77843_muic_info *info)
{
int ret, gnd_cable_type;
bool attached;
gnd_cable_type = max77843_muic_get_cable_type(info,
MAX77843_CABLE_GROUP_ADC_GND, &attached);
dev_dbg(info->dev, "external connector is %s (gnd:0x%02x)\n",
attached ? "attached" : "detached", gnd_cable_type);
switch (gnd_cable_type) {
case MAX77843_MUIC_GND_USB_HOST:
case MAX77843_MUIC_GND_USB_HOST_VB:
ret = max77843_muic_set_path(info, CONTROL1_SW_USB, attached);
if (ret < 0)
return ret;
extcon_set_cable_state_(info->edev, EXTCON_USB_HOST, attached);
break;
case MAX77843_MUIC_GND_MHL_VB:
case MAX77843_MUIC_GND_MHL:
ret = max77843_muic_set_path(info, CONTROL1_SW_OPEN, attached);
if (ret < 0)
return ret;
extcon_set_cable_state_(info->edev, EXTCON_MHL, attached);
break;
default:
dev_err(info->dev, "failed to detect %s accessory(gnd:0x%x)\n",
attached ? "attached" : "detached", gnd_cable_type);
return -EINVAL;
}
return 0;
}
static int max77843_muic_jig_handler(struct max77843_muic_info *info,
int cable_type, bool attached)
{
int ret;
u8 path = CONTROL1_SW_OPEN;
dev_dbg(info->dev, "external connector is %s (adc:0x%02x)\n",
attached ? "attached" : "detached", cable_type);
switch (cable_type) {
case MAX77843_MUIC_ADC_FACTORY_MODE_USB_OFF:
case MAX77843_MUIC_ADC_FACTORY_MODE_USB_ON:
path = CONTROL1_SW_USB;
break;
case MAX77843_MUIC_ADC_FACTORY_MODE_UART_OFF:
path = CONTROL1_SW_UART;
break;
default:
return -EINVAL;
}
ret = max77843_muic_set_path(info, path, attached);
if (ret < 0)
return ret;
extcon_set_cable_state_(info->edev, EXTCON_JIG, attached);
return 0;
}
static int max77843_muic_adc_handler(struct max77843_muic_info *info)
{
int ret, cable_type;
bool attached;
cable_type = max77843_muic_get_cable_type(info,
MAX77843_CABLE_GROUP_ADC, &attached);
dev_dbg(info->dev,
"external connector is %s (adc:0x%02x, prev_adc:0x%x)\n",
attached ? "attached" : "detached", cable_type,
info->prev_cable_type);
switch (cable_type) {
case MAX77843_MUIC_ADC_GROUND:
ret = max77843_muic_adc_gnd_handler(info);
if (ret < 0)
return ret;
break;
case MAX77843_MUIC_ADC_FACTORY_MODE_USB_OFF:
case MAX77843_MUIC_ADC_FACTORY_MODE_USB_ON:
case MAX77843_MUIC_ADC_FACTORY_MODE_UART_OFF:
ret = max77843_muic_jig_handler(info, cable_type, attached);
if (ret < 0)
return ret;
break;
case MAX77843_MUIC_ADC_SEND_END_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S1_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S2_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S3_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S4_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S5_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S6_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S7_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S8_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S9_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S10_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S11_BUTTON:
case MAX77843_MUIC_ADC_REMOTE_S12_BUTTON:
case MAX77843_MUIC_ADC_RESERVED_ACC_1:
case MAX77843_MUIC_ADC_RESERVED_ACC_2:
case MAX77843_MUIC_ADC_RESERVED_ACC_3:
case MAX77843_MUIC_ADC_RESERVED_ACC_4:
case MAX77843_MUIC_ADC_RESERVED_ACC_5:
case MAX77843_MUIC_ADC_AUDIO_DEVICE_TYPE2:
case MAX77843_MUIC_ADC_PHONE_POWERED_DEV:
case MAX77843_MUIC_ADC_TTY_CONVERTER:
case MAX77843_MUIC_ADC_UART_CABLE:
case MAX77843_MUIC_ADC_CEA936A_TYPE1_CHG:
case MAX77843_MUIC_ADC_AV_CABLE_NOLOAD:
case MAX77843_MUIC_ADC_CEA936A_TYPE2_CHG:
case MAX77843_MUIC_ADC_FACTORY_MODE_UART_ON:
case MAX77843_MUIC_ADC_AUDIO_DEVICE_TYPE1:
case MAX77843_MUIC_ADC_OPEN:
dev_err(info->dev,
"accessory is %s but it isn't used (adc:0x%x)\n",
attached ? "attached" : "detached", cable_type);
return -EAGAIN;
default:
dev_err(info->dev,
"failed to detect %s accessory (adc:0x%x)\n",
attached ? "attached" : "detached", cable_type);
return -EINVAL;
}
return 0;
}
static int max77843_muic_chg_handler(struct max77843_muic_info *info)
{
int ret, chg_type, gnd_type;
bool attached;
chg_type = max77843_muic_get_cable_type(info,
MAX77843_CABLE_GROUP_CHG, &attached);
dev_dbg(info->dev,
"external connector is %s(chg_type:0x%x, prev_chg_type:0x%x)\n",
attached ? "attached" : "detached",
chg_type, info->prev_chg_type);
switch (chg_type) {
case MAX77843_MUIC_CHG_USB:
ret = max77843_muic_set_path(info, CONTROL1_SW_USB, attached);
if (ret < 0)
return ret;
extcon_set_cable_state_(info->edev, EXTCON_USB, attached);
break;
case MAX77843_MUIC_CHG_DOWNSTREAM:
ret = max77843_muic_set_path(info, CONTROL1_SW_OPEN, attached);
if (ret < 0)
return ret;
extcon_set_cable_state_(info->edev, EXTCON_CHARGE_DOWNSTREAM,
attached);
break;
case MAX77843_MUIC_CHG_DEDICATED:
ret = max77843_muic_set_path(info, CONTROL1_SW_OPEN, attached);
if (ret < 0)
return ret;
extcon_set_cable_state_(info->edev, EXTCON_TA, attached);
break;
case MAX77843_MUIC_CHG_SPECIAL_500MA:
ret = max77843_muic_set_path(info, CONTROL1_SW_OPEN, attached);
if (ret < 0)
return ret;
extcon_set_cable_state_(info->edev, EXTCON_SLOW_CHARGER,
attached);
break;
case MAX77843_MUIC_CHG_SPECIAL_1A:
ret = max77843_muic_set_path(info, CONTROL1_SW_OPEN, attached);
if (ret < 0)
return ret;
extcon_set_cable_state_(info->edev, EXTCON_FAST_CHARGER,
attached);
break;
case MAX77843_MUIC_CHG_GND:
gnd_type = max77843_muic_get_cable_type(info,
MAX77843_CABLE_GROUP_ADC_GND, &attached);
if (gnd_type == MAX77843_MUIC_GND_MHL_VB)
extcon_set_cable_state_(info->edev, EXTCON_TA, true);
else if (gnd_type == MAX77843_MUIC_GND_MHL)
extcon_set_cable_state_(info->edev, EXTCON_TA, false);
break;
case MAX77843_MUIC_CHG_NONE:
break;
default:
dev_err(info->dev,
"failed to detect %s accessory (chg_type:0x%x)\n",
attached ? "attached" : "detached", chg_type);
max77843_muic_set_path(info, CONTROL1_SW_OPEN, attached);
return -EINVAL;
}
return 0;
}
static void max77843_muic_irq_work(struct work_struct *work)
{
struct max77843_muic_info *info = container_of(work,
struct max77843_muic_info, irq_work);
struct max77843 *max77843 = info->max77843;
int ret = 0;
mutex_lock(&info->mutex);
ret = regmap_bulk_read(max77843->regmap_muic,
MAX77843_MUIC_REG_STATUS1, info->status,
MAX77843_MUIC_STATUS_NUM);
if (ret) {
dev_err(info->dev, "Cannot read STATUS registers\n");
mutex_unlock(&info->mutex);
return;
}
if (info->irq_adc) {
ret = max77843_muic_adc_handler(info);
if (ret)
dev_err(info->dev, "Unknown cable type\n");
info->irq_adc = false;
}
if (info->irq_chg) {
ret = max77843_muic_chg_handler(info);
if (ret)
dev_err(info->dev, "Unknown charger type\n");
info->irq_chg = false;
}
mutex_unlock(&info->mutex);
}
static irqreturn_t max77843_muic_irq_handler(int irq, void *data)
{
struct max77843_muic_info *info = data;
int i, irq_type = -1;
for (i = 0; i < ARRAY_SIZE(max77843_muic_irqs); i++)
if (irq == max77843_muic_irqs[i].virq)
irq_type = max77843_muic_irqs[i].irq;
switch (irq_type) {
case MAX77843_MUIC_IRQ_INT1_ADC:
case MAX77843_MUIC_IRQ_INT1_ADCERROR:
case MAX77843_MUIC_IRQ_INT1_ADC1K:
info->irq_adc = true;
break;
case MAX77843_MUIC_IRQ_INT2_CHGTYP:
case MAX77843_MUIC_IRQ_INT2_CHGDETRUN:
case MAX77843_MUIC_IRQ_INT2_DCDTMR:
case MAX77843_MUIC_IRQ_INT2_DXOVP:
case MAX77843_MUIC_IRQ_INT2_VBVOLT:
info->irq_chg = true;
break;
case MAX77843_MUIC_IRQ_INT3_VBADC:
case MAX77843_MUIC_IRQ_INT3_VDNMON:
case MAX77843_MUIC_IRQ_INT3_DNRES:
case MAX77843_MUIC_IRQ_INT3_MPNACK:
case MAX77843_MUIC_IRQ_INT3_MRXBUFOW:
case MAX77843_MUIC_IRQ_INT3_MRXTRF:
case MAX77843_MUIC_IRQ_INT3_MRXPERR:
case MAX77843_MUIC_IRQ_INT3_MRXRDY:
break;
default:
dev_err(info->dev, "Cannot recognize IRQ(%d)\n", irq_type);
break;
}
schedule_work(&info->irq_work);
return IRQ_HANDLED;
}
static void max77843_muic_detect_cable_wq(struct work_struct *work)
{
struct max77843_muic_info *info = container_of(to_delayed_work(work),
struct max77843_muic_info, wq_detcable);
struct max77843 *max77843 = info->max77843;
int chg_type, adc, ret;
bool attached;
mutex_lock(&info->mutex);
ret = regmap_bulk_read(max77843->regmap_muic,
MAX77843_MUIC_REG_STATUS1, info->status,
MAX77843_MUIC_STATUS_NUM);
if (ret) {
dev_err(info->dev, "Cannot read STATUS registers\n");
goto err_cable_wq;
}
adc = max77843_muic_get_cable_type(info,
MAX77843_CABLE_GROUP_ADC, &attached);
if (attached && adc != MAX77843_MUIC_ADC_OPEN) {
ret = max77843_muic_adc_handler(info);
if (ret < 0) {
dev_err(info->dev, "Cannot detect accessory\n");
goto err_cable_wq;
}
}
chg_type = max77843_muic_get_cable_type(info,
MAX77843_CABLE_GROUP_CHG, &attached);
if (attached && chg_type != MAX77843_MUIC_CHG_NONE) {
ret = max77843_muic_chg_handler(info);
if (ret < 0) {
dev_err(info->dev, "Cannot detect charger accessory\n");
goto err_cable_wq;
}
}
err_cable_wq:
mutex_unlock(&info->mutex);
}
static int max77843_muic_set_debounce_time(struct max77843_muic_info *info,
enum max77843_muic_adc_debounce_time time)
{
struct max77843 *max77843 = info->max77843;
int ret;
switch (time) {
case MAX77843_DEBOUNCE_TIME_5MS:
case MAX77843_DEBOUNCE_TIME_10MS:
case MAX77843_DEBOUNCE_TIME_25MS:
case MAX77843_DEBOUNCE_TIME_38_62MS:
ret = regmap_update_bits(max77843->regmap_muic,
MAX77843_MUIC_REG_CONTROL4,
MAX77843_MUIC_CONTROL4_ADCDBSET_MASK,
time << CONTROL4_ADCDBSET_SHIFT);
if (ret < 0) {
dev_err(info->dev, "Cannot write MUIC regmap\n");
return ret;
}
break;
default:
dev_err(info->dev, "Invalid ADC debounce time\n");
return -EINVAL;
}
return 0;
}
static int max77843_init_muic_regmap(struct max77843 *max77843)
{
int ret;
max77843->i2c_muic = i2c_new_dummy(max77843->i2c->adapter,
I2C_ADDR_MUIC);
if (!max77843->i2c_muic) {
dev_err(&max77843->i2c->dev,
"Cannot allocate I2C device for MUIC\n");
return -ENOMEM;
}
i2c_set_clientdata(max77843->i2c_muic, max77843);
max77843->regmap_muic = devm_regmap_init_i2c(max77843->i2c_muic,
&max77843_muic_regmap_config);
if (IS_ERR(max77843->regmap_muic)) {
ret = PTR_ERR(max77843->regmap_muic);
goto err_muic_i2c;
}
ret = regmap_add_irq_chip(max77843->regmap_muic, max77843->irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT | IRQF_SHARED,
0, &max77843_muic_irq_chip, &max77843->irq_data_muic);
if (ret < 0) {
dev_err(&max77843->i2c->dev, "Cannot add MUIC IRQ chip\n");
goto err_muic_i2c;
}
return 0;
err_muic_i2c:
i2c_unregister_device(max77843->i2c_muic);
return ret;
}
static int max77843_muic_probe(struct platform_device *pdev)
{
struct max77843 *max77843 = dev_get_drvdata(pdev->dev.parent);
struct max77843_muic_info *info;
unsigned int id;
int i, ret;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->dev = &pdev->dev;
info->max77843 = max77843;
platform_set_drvdata(pdev, info);
mutex_init(&info->mutex);
ret = max77843_init_muic_regmap(max77843);
if (ret) {
dev_err(&pdev->dev, "Failed to init MUIC regmap\n");
return ret;
}
ret = regmap_update_bits(max77843->regmap_muic,
MAX77843_MUIC_REG_CONTROL4,
MAX77843_MUIC_CONTROL4_USBAUTO_MASK |
MAX77843_MUIC_CONTROL4_FCTAUTO_MASK,
CONTROL4_AUTO_DISABLE);
info->edev = devm_extcon_dev_allocate(&pdev->dev,
max77843_extcon_cable);
if (IS_ERR(info->edev)) {
dev_err(&pdev->dev, "Failed to allocate memory for extcon\n");
ret = -ENODEV;
goto err_muic_irq;
}
ret = devm_extcon_dev_register(&pdev->dev, info->edev);
if (ret) {
dev_err(&pdev->dev, "Failed to register extcon device\n");
goto err_muic_irq;
}
max77843_muic_set_debounce_time(info, MAX77843_DEBOUNCE_TIME_25MS);
max77843_muic_set_path(info, CONTROL1_SW_UART, true);
ret = regmap_read(max77843->regmap_muic, MAX77843_MUIC_REG_ID, &id);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to read revision number\n");
goto err_muic_irq;
}
dev_info(info->dev, "MUIC device ID : 0x%x\n", id);
INIT_WORK(&info->irq_work, max77843_muic_irq_work);
for (i = 0; i < ARRAY_SIZE(max77843_muic_irqs); i++) {
struct max77843_muic_irq *muic_irq = &max77843_muic_irqs[i];
unsigned int virq = 0;
virq = regmap_irq_get_virq(max77843->irq_data_muic,
muic_irq->irq);
if (virq <= 0) {
ret = -EINVAL;
goto err_muic_irq;
}
muic_irq->virq = virq;
ret = devm_request_threaded_irq(&pdev->dev, virq, NULL,
max77843_muic_irq_handler, IRQF_NO_SUSPEND,
muic_irq->name, info);
if (ret) {
dev_err(&pdev->dev,
"Failed to request irq (IRQ: %d, error: %d)\n",
muic_irq->irq, ret);
goto err_muic_irq;
}
}
INIT_DELAYED_WORK(&info->wq_detcable, max77843_muic_detect_cable_wq);
queue_delayed_work(system_power_efficient_wq,
&info->wq_detcable, msecs_to_jiffies(DELAY_MS_DEFAULT));
return 0;
err_muic_irq:
regmap_del_irq_chip(max77843->irq, max77843->irq_data_muic);
i2c_unregister_device(max77843->i2c_muic);
return ret;
}
static int max77843_muic_remove(struct platform_device *pdev)
{
struct max77843_muic_info *info = platform_get_drvdata(pdev);
struct max77843 *max77843 = info->max77843;
cancel_work_sync(&info->irq_work);
regmap_del_irq_chip(max77843->irq, max77843->irq_data_muic);
i2c_unregister_device(max77843->i2c_muic);
return 0;
}
static int __init max77843_muic_init(void)
{
return platform_driver_register(&max77843_muic_driver);
}
