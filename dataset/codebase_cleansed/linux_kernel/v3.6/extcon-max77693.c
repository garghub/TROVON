static int max77693_muic_set_debounce_time(struct max77693_muic_info *info,
enum max77693_muic_adc_debounce_time time)
{
int ret = 0;
u8 ctrl3;
switch (time) {
case ADC_DEBOUNCE_TIME_5MS:
case ADC_DEBOUNCE_TIME_10MS:
case ADC_DEBOUNCE_TIME_25MS:
case ADC_DEBOUNCE_TIME_38_62MS:
ret = max77693_read_reg(info->max77693->regmap_muic,
MAX77693_MUIC_REG_CTRL3, &ctrl3);
ctrl3 &= ~CONTROL3_ADCDBSET_MASK;
ctrl3 |= (time << CONTROL3_ADCDBSET_SHIFT);
ret = max77693_write_reg(info->max77693->regmap_muic,
MAX77693_MUIC_REG_CTRL3, ctrl3);
if (ret) {
dev_err(info->dev, "failed to set ADC debounce time\n");
ret = -EINVAL;
}
break;
default:
dev_err(info->dev, "invalid ADC debounce time\n");
ret = -EINVAL;
break;
}
return ret;
}
static int max77693_muic_set_path(struct max77693_muic_info *info,
u8 val, bool attached)
{
int ret = 0;
u8 ctrl1, ctrl2 = 0;
if (attached)
ctrl1 = val;
else
ctrl1 = CONTROL1_SW_OPEN;
ret = max77693_update_reg(info->max77693->regmap_muic,
MAX77693_MUIC_REG_CTRL1, ctrl1, COMP_SW_MASK);
if (ret < 0) {
dev_err(info->dev, "failed to update MUIC register\n");
goto out;
}
if (attached)
ctrl2 |= CONTROL2_CPEN_MASK;
else
ctrl2 |= CONTROL2_LOWPWR_MASK;
ret = max77693_update_reg(info->max77693->regmap_muic,
MAX77693_MUIC_REG_CTRL2, ctrl2,
CONTROL2_LOWPWR_MASK | CONTROL2_CPEN_MASK);
if (ret < 0) {
dev_err(info->dev, "failed to update MUIC register\n");
goto out;
}
dev_info(info->dev,
"CONTROL1 : 0x%02x, CONTROL2 : 0x%02x, state : %s\n",
ctrl1, ctrl2, attached ? "attached" : "detached");
out:
return ret;
}
static int max77693_muic_adc_ground_handler(struct max77693_muic_info *info,
bool attached)
{
int ret = 0;
int type;
int adc, adc1k, adclow;
if (attached) {
adc = info->status[0] & STATUS1_ADC_MASK;
adclow = info->status[0] & STATUS1_ADCLOW_MASK;
adclow >>= STATUS1_ADCLOW_SHIFT;
adc1k = info->status[0] & STATUS1_ADC1K_MASK;
adc1k >>= STATUS1_ADC1K_SHIFT;
type = ((0x1 << 8) | (adclow << 1) | adc1k);
info->prev_adc = adc;
info->prev_adc_gnd = type;
} else
type = info->prev_adc_gnd;
switch (type) {
case MAX77693_MUIC_GND_USB_OTG:
ret = max77693_muic_set_path(info, CONTROL1_SW_USB, attached);
if (ret < 0)
goto out;
extcon_set_cable_state(info->edev, "USB-Host", attached);
break;
case MAX77693_MUIC_GND_AV_CABLE_LOAD:
ret = max77693_muic_set_path(info, CONTROL1_SW_AUDIO, attached);
if (ret < 0)
goto out;
extcon_set_cable_state(info->edev,
"Audio-video-load", attached);
break;
case MAX77693_MUIC_GND_MHL_CABLE:
extcon_set_cable_state(info->edev, "MHL", attached);
break;
default:
dev_err(info->dev, "faild to detect %s accessory\n",
attached ? "attached" : "detached");
dev_err(info->dev, "- adc:0x%x, adclow:0x%x, adc1k:0x%x\n",
adc, adclow, adc1k);
ret = -EINVAL;
break;
}
out:
return ret;
}
static int max77693_muic_adc_handler(struct max77693_muic_info *info,
int curr_adc, bool attached)
{
int ret = 0;
int adc;
if (attached) {
info->prev_adc = curr_adc;
adc = curr_adc;
} else
adc = info->prev_adc;
dev_info(info->dev,
"external connector is %s (adc:0x%02x, prev_adc:0x%x)\n",
attached ? "attached" : "detached", curr_adc, info->prev_adc);
switch (adc) {
case MAX77693_MUIC_ADC_GROUND:
max77693_muic_adc_ground_handler(info, attached);
break;
case MAX77693_MUIC_ADC_FACTORY_MODE_USB_OFF:
case MAX77693_MUIC_ADC_FACTORY_MODE_USB_ON:
ret = max77693_muic_set_path(info, CONTROL1_SW_USB, attached);
if (ret < 0)
goto out;
extcon_set_cable_state(info->edev, "USB", attached);
break;
case MAX77693_MUIC_ADC_FACTORY_MODE_UART_OFF:
case MAX77693_MUIC_ADC_FACTORY_MODE_UART_ON:
ret = max77693_muic_set_path(info, CONTROL1_SW_UART, attached);
if (ret < 0)
goto out;
extcon_set_cable_state(info->edev, "JIG", attached);
break;
case MAX77693_MUIC_ADC_AUDIO_MODE_REMOTE:
ret = max77693_muic_set_path(info, CONTROL1_SW_AUDIO, attached);
if (ret < 0)
goto out;
extcon_set_cable_state(info->edev,
"Audio-video-noload", attached);
break;
case MAX77693_MUIC_ADC_SEND_END_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S1_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S2_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S3_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S4_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S5_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S6_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S7_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S8_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S9_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S10_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S11_BUTTON:
case MAX77693_MUIC_ADC_REMOTE_S12_BUTTON:
case MAX77693_MUIC_ADC_RESERVED_ACC_1:
case MAX77693_MUIC_ADC_RESERVED_ACC_2:
case MAX77693_MUIC_ADC_RESERVED_ACC_3:
case MAX77693_MUIC_ADC_RESERVED_ACC_4:
case MAX77693_MUIC_ADC_RESERVED_ACC_5:
case MAX77693_MUIC_ADC_CEA936_AUDIO:
case MAX77693_MUIC_ADC_PHONE_POWERED_DEV:
case MAX77693_MUIC_ADC_TTY_CONVERTER:
case MAX77693_MUIC_ADC_UART_CABLE:
case MAX77693_MUIC_ADC_CEA936A_TYPE1_CHG:
case MAX77693_MUIC_ADC_AV_CABLE_NOLOAD:
case MAX77693_MUIC_ADC_CEA936A_TYPE2_CHG:
dev_info(info->dev,
"accessory is %s but it isn't used (adc:0x%x)\n",
attached ? "attached" : "detached", adc);
goto out;
default:
dev_err(info->dev,
"failed to detect %s accessory (adc:0x%x)\n",
attached ? "attached" : "detached", adc);
ret = -EINVAL;
goto out;
}
out:
return ret;
}
static int max77693_muic_chg_handler(struct max77693_muic_info *info,
int curr_chg_type, bool attached)
{
int ret = 0;
int chg_type;
if (attached) {
info->prev_chg_type = curr_chg_type;
chg_type = curr_chg_type;
} else
chg_type = info->prev_chg_type;
dev_info(info->dev,
"external connector is %s(chg_type:0x%x, prev_chg_type:0x%x)\n",
attached ? "attached" : "detached",
curr_chg_type, info->prev_chg_type);
switch (chg_type) {
case MAX77693_CHARGER_TYPE_USB:
ret = max77693_muic_set_path(info, CONTROL1_SW_USB, attached);
if (ret < 0)
goto out;
extcon_set_cable_state(info->edev, "USB", attached);
break;
case MAX77693_CHARGER_TYPE_DOWNSTREAM_PORT:
extcon_set_cable_state(info->edev,
"Charge-downstream", attached);
break;
case MAX77693_CHARGER_TYPE_DEDICATED_CHG:
extcon_set_cable_state(info->edev, "TA", attached);
break;
case MAX77693_CHARGER_TYPE_APPLE_500MA:
extcon_set_cable_state(info->edev, "Slow-charger", attached);
break;
case MAX77693_CHARGER_TYPE_APPLE_1A_2A:
extcon_set_cable_state(info->edev, "Fast-charger", attached);
break;
case MAX77693_CHARGER_TYPE_DEAD_BATTERY:
break;
default:
dev_err(info->dev,
"failed to detect %s accessory (chg_type:0x%x)\n",
attached ? "attached" : "detached", chg_type);
ret = -EINVAL;
goto out;
}
out:
return ret;
}
static void max77693_muic_irq_work(struct work_struct *work)
{
struct max77693_muic_info *info = container_of(work,
struct max77693_muic_info, irq_work);
int curr_adc, curr_chg_type;
int irq_type = -1;
int i, ret = 0;
bool attached = true;
if (!info->edev)
return;
mutex_lock(&info->mutex);
for (i = 0 ; i < ARRAY_SIZE(muic_irqs) ; i++)
if (info->irq == muic_irqs[i].virq)
irq_type = muic_irqs[i].irq;
ret = max77693_bulk_read(info->max77693->regmap_muic,
MAX77693_MUIC_REG_STATUS1, 2, info->status);
if (ret) {
dev_err(info->dev, "failed to read MUIC register\n");
mutex_unlock(&info->mutex);
return;
}
switch (irq_type) {
case MAX77693_MUIC_IRQ_INT1_ADC:
case MAX77693_MUIC_IRQ_INT1_ADC_LOW:
case MAX77693_MUIC_IRQ_INT1_ADC_ERR:
case MAX77693_MUIC_IRQ_INT1_ADC1K:
curr_adc = info->status[0] & STATUS1_ADC_MASK;
curr_adc >>= STATUS1_ADC_SHIFT;
if (curr_adc == MAX77693_MUIC_ADC_OPEN)
attached = false;
ret = max77693_muic_adc_handler(info, curr_adc, attached);
break;
case MAX77693_MUIC_IRQ_INT2_CHGTYP:
case MAX77693_MUIC_IRQ_INT2_CHGDETREUN:
case MAX77693_MUIC_IRQ_INT2_DCDTMR:
case MAX77693_MUIC_IRQ_INT2_DXOVP:
case MAX77693_MUIC_IRQ_INT2_VBVOLT:
case MAX77693_MUIC_IRQ_INT2_VIDRM:
curr_chg_type = info->status[1] & STATUS2_CHGTYP_MASK;
curr_chg_type >>= STATUS2_CHGTYP_SHIFT;
if (curr_chg_type == MAX77693_CHARGER_TYPE_NONE)
attached = false;
ret = max77693_muic_chg_handler(info, curr_chg_type, attached);
break;
case MAX77693_MUIC_IRQ_INT3_EOC:
case MAX77693_MUIC_IRQ_INT3_CGMBC:
case MAX77693_MUIC_IRQ_INT3_OVP:
case MAX77693_MUIC_IRQ_INT3_MBCCHG_ERR:
case MAX77693_MUIC_IRQ_INT3_CHG_ENABLED:
case MAX77693_MUIC_IRQ_INT3_BAT_DET:
break;
default:
dev_err(info->dev, "muic interrupt: irq %d occurred\n",
irq_type);
break;
}
if (ret < 0)
dev_err(info->dev, "failed to handle MUIC interrupt\n");
mutex_unlock(&info->mutex);
return;
}
static irqreturn_t max77693_muic_irq_handler(int irq, void *data)
{
struct max77693_muic_info *info = data;
info->irq = irq;
schedule_work(&info->irq_work);
return IRQ_HANDLED;
}
static int max77693_muic_detect_accessory(struct max77693_muic_info *info)
{
int ret = 0;
int adc, chg_type;
mutex_lock(&info->mutex);
ret = max77693_bulk_read(info->max77693->regmap_muic,
MAX77693_MUIC_REG_STATUS1, 2, info->status);
if (ret) {
dev_err(info->dev, "failed to read MUIC register\n");
mutex_unlock(&info->mutex);
return -EINVAL;
}
adc = info->status[0] & STATUS1_ADC_MASK;
adc >>= STATUS1_ADC_SHIFT;
if (adc != MAX77693_MUIC_ADC_OPEN) {
dev_info(info->dev,
"external connector is attached (adc:0x%02x)\n", adc);
ret = max77693_muic_adc_handler(info, adc, true);
if (ret < 0)
dev_err(info->dev, "failed to detect accessory\n");
goto out;
}
chg_type = info->status[1] & STATUS2_CHGTYP_MASK;
chg_type >>= STATUS2_CHGTYP_SHIFT;
if (chg_type != MAX77693_CHARGER_TYPE_NONE) {
dev_info(info->dev,
"external connector is attached (chg_type:0x%x)\n",
chg_type);
max77693_muic_chg_handler(info, chg_type, true);
if (ret < 0)
dev_err(info->dev, "failed to detect charger accessory\n");
}
out:
mutex_unlock(&info->mutex);
return ret;
}
static int __devinit max77693_muic_probe(struct platform_device *pdev)
{
struct max77693_dev *max77693 = dev_get_drvdata(pdev->dev.parent);
struct max77693_muic_info *info;
int ret, i;
u8 id;
info = kzalloc(sizeof(struct max77693_muic_info), GFP_KERNEL);
if (!info) {
dev_err(&pdev->dev, "failed to allocate memory\n");
ret = -ENOMEM;
goto err_kfree;
}
info->dev = &pdev->dev;
info->max77693 = max77693;
if (info->max77693->regmap_muic)
dev_dbg(&pdev->dev, "allocate register map\n");
else {
info->max77693->regmap_muic = devm_regmap_init_i2c(
info->max77693->muic,
&max77693_muic_regmap_config);
if (IS_ERR(info->max77693->regmap_muic)) {
ret = PTR_ERR(info->max77693->regmap_muic);
dev_err(max77693->dev,
"failed to allocate register map: %d\n", ret);
goto err_regmap;
}
}
platform_set_drvdata(pdev, info);
mutex_init(&info->mutex);
INIT_WORK(&info->irq_work, max77693_muic_irq_work);
for (i = 0; i < ARRAY_SIZE(muic_irqs); i++) {
struct max77693_muic_irq *muic_irq = &muic_irqs[i];
int virq = 0;
virq = irq_create_mapping(max77693->irq_domain, muic_irq->irq);
if (!virq)
goto err_irq;
muic_irq->virq = virq;
ret = request_threaded_irq(virq, NULL,
max77693_muic_irq_handler,
0, muic_irq->name, info);
if (ret) {
dev_err(&pdev->dev,
"failed: irq request (IRQ: %d,"
" error :%d)\n",
muic_irq->irq, ret);
for (i = i - 1; i >= 0; i--)
free_irq(muic_irq->virq, info);
goto err_irq;
}
}
info->edev = kzalloc(sizeof(struct extcon_dev), GFP_KERNEL);
if (!info->edev) {
dev_err(&pdev->dev, "failed to allocate memory for extcon\n");
ret = -ENOMEM;
goto err_irq;
}
info->edev->name = DEV_NAME;
info->edev->supported_cable = max77693_extcon_cable;
ret = extcon_dev_register(info->edev, NULL);
if (ret) {
dev_err(&pdev->dev, "failed to register extcon device\n");
goto err_extcon;
}
ret = max77693_read_reg(info->max77693->regmap_muic,
MAX77693_MUIC_REG_ID, &id);
if (ret < 0) {
dev_err(&pdev->dev, "failed to read revision number\n");
goto err_extcon;
}
dev_info(info->dev, "device ID : 0x%x\n", id);
max77693_muic_set_debounce_time(info, ADC_DEBOUNCE_TIME_25MS);
max77693_muic_detect_accessory(info);
return ret;
err_extcon:
kfree(info->edev);
err_irq:
err_regmap:
kfree(info);
err_kfree:
return ret;
}
static int __devexit max77693_muic_remove(struct platform_device *pdev)
{
struct max77693_muic_info *info = platform_get_drvdata(pdev);
int i;
for (i = 0; i < ARRAY_SIZE(muic_irqs); i++)
free_irq(muic_irqs[i].virq, info);
cancel_work_sync(&info->irq_work);
extcon_dev_unregister(info->edev);
kfree(info);
return 0;
}
