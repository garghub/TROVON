static int max14577_muic_set_debounce_time(struct max14577_muic_info *info,
enum max14577_muic_adc_debounce_time time)
{
u8 ret;
switch (time) {
case ADC_DEBOUNCE_TIME_5MS:
case ADC_DEBOUNCE_TIME_10MS:
case ADC_DEBOUNCE_TIME_25MS:
case ADC_DEBOUNCE_TIME_38_62MS:
ret = max14577_update_reg(info->max14577->regmap,
MAX14577_MUIC_REG_CONTROL3,
CTRL3_ADCDBSET_MASK,
time << CTRL3_ADCDBSET_SHIFT);
if (ret) {
dev_err(info->dev, "failed to set ADC debounce time\n");
return ret;
}
break;
default:
dev_err(info->dev, "invalid ADC debounce time\n");
return -EINVAL;
}
return 0;
}
static int max14577_muic_set_path(struct max14577_muic_info *info,
u8 val, bool attached)
{
int ret = 0;
u8 ctrl1, ctrl2 = 0;
ret = max14577_update_reg(info->max14577->regmap,
MAX14577_MUIC_REG_CONTROL1,
CLEAR_IDBEN_MICEN_MASK, CTRL1_SW_OPEN);
if (ret < 0) {
dev_err(info->dev, "failed to update MUIC register\n");
return ret;
}
if (attached)
ctrl1 = val;
else
ctrl1 = CTRL1_SW_OPEN;
ret = max14577_update_reg(info->max14577->regmap,
MAX14577_MUIC_REG_CONTROL1,
CLEAR_IDBEN_MICEN_MASK, ctrl1);
if (ret < 0) {
dev_err(info->dev, "failed to update MUIC register\n");
return ret;
}
if (attached)
ctrl2 |= CTRL2_CPEN_MASK;
else
ctrl2 |= CTRL2_LOWPWR_MASK;
ret = max14577_update_reg(info->max14577->regmap,
MAX14577_REG_CONTROL2,
CTRL2_LOWPWR_MASK | CTRL2_CPEN_MASK, ctrl2);
if (ret < 0) {
dev_err(info->dev, "failed to update MUIC register\n");
return ret;
}
dev_dbg(info->dev,
"CONTROL1 : 0x%02x, CONTROL2 : 0x%02x, state : %s\n",
ctrl1, ctrl2, attached ? "attached" : "detached");
return 0;
}
static int max14577_muic_get_cable_type(struct max14577_muic_info *info,
enum max14577_muic_cable_group group, bool *attached)
{
int cable_type = 0;
int adc;
int chg_type;
switch (group) {
case MAX14577_CABLE_GROUP_ADC:
adc = info->status[MAX14577_MUIC_STATUS1] & STATUS1_ADC_MASK;
adc >>= STATUS1_ADC_SHIFT;
if (adc == MAX14577_MUIC_ADC_OPEN) {
*attached = false;
cable_type = info->prev_cable_type;
info->prev_cable_type = MAX14577_MUIC_ADC_OPEN;
} else {
*attached = true;
cable_type = info->prev_cable_type = adc;
}
break;
case MAX14577_CABLE_GROUP_CHG:
chg_type = info->status[MAX14577_MUIC_STATUS2] &
STATUS2_CHGTYP_MASK;
chg_type >>= STATUS2_CHGTYP_SHIFT;
if (chg_type == MAX14577_CHARGER_TYPE_NONE) {
*attached = false;
cable_type = info->prev_chg_type;
info->prev_chg_type = MAX14577_CHARGER_TYPE_NONE;
} else {
*attached = true;
cable_type = info->prev_chg_type = chg_type;
}
break;
default:
dev_err(info->dev, "Unknown cable group (%d)\n", group);
cable_type = -EINVAL;
break;
}
return cable_type;
}
static int max14577_muic_jig_handler(struct max14577_muic_info *info,
int cable_type, bool attached)
{
int ret = 0;
u8 path = CTRL1_SW_OPEN;
dev_dbg(info->dev,
"external connector is %s (adc:0x%02x)\n",
attached ? "attached" : "detached", cable_type);
switch (cable_type) {
case MAX14577_MUIC_ADC_FACTORY_MODE_USB_OFF:
case MAX14577_MUIC_ADC_FACTORY_MODE_USB_ON:
path = CTRL1_SW_USB;
break;
case MAX14577_MUIC_ADC_FACTORY_MODE_UART_OFF:
path = CTRL1_SW_UART;
break;
default:
dev_err(info->dev, "failed to detect %s jig cable\n",
attached ? "attached" : "detached");
return -EINVAL;
}
ret = max14577_muic_set_path(info, path, attached);
if (ret < 0)
return ret;
extcon_set_cable_state_(info->edev, EXTCON_JIG, attached);
return 0;
}
static int max14577_muic_adc_handler(struct max14577_muic_info *info)
{
int cable_type;
bool attached;
int ret = 0;
cable_type = max14577_muic_get_cable_type(info,
MAX14577_CABLE_GROUP_ADC, &attached);
dev_dbg(info->dev,
"external connector is %s (adc:0x%02x, prev_adc:0x%x)\n",
attached ? "attached" : "detached", cable_type,
info->prev_cable_type);
switch (cable_type) {
case MAX14577_MUIC_ADC_FACTORY_MODE_USB_OFF:
case MAX14577_MUIC_ADC_FACTORY_MODE_USB_ON:
case MAX14577_MUIC_ADC_FACTORY_MODE_UART_OFF:
ret = max14577_muic_jig_handler(info, cable_type, attached);
if (ret < 0)
return ret;
break;
case MAX14577_MUIC_ADC_GROUND:
case MAX14577_MUIC_ADC_SEND_END_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S1_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S2_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S3_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S4_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S5_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S6_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S7_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S8_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S9_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S10_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S11_BUTTON:
case MAX14577_MUIC_ADC_REMOTE_S12_BUTTON:
case MAX14577_MUIC_ADC_RESERVED_ACC_1:
case MAX14577_MUIC_ADC_RESERVED_ACC_2:
case MAX14577_MUIC_ADC_RESERVED_ACC_3:
case MAX14577_MUIC_ADC_RESERVED_ACC_4:
case MAX14577_MUIC_ADC_RESERVED_ACC_5:
case MAX14577_MUIC_ADC_AUDIO_DEVICE_TYPE2:
case MAX14577_MUIC_ADC_PHONE_POWERED_DEV:
case MAX14577_MUIC_ADC_TTY_CONVERTER:
case MAX14577_MUIC_ADC_UART_CABLE:
case MAX14577_MUIC_ADC_CEA936A_TYPE1_CHG:
case MAX14577_MUIC_ADC_AV_CABLE_NOLOAD:
case MAX14577_MUIC_ADC_CEA936A_TYPE2_CHG:
case MAX14577_MUIC_ADC_FACTORY_MODE_UART_ON:
case MAX14577_MUIC_ADC_AUDIO_DEVICE_TYPE1:
dev_info(info->dev,
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
static int max14577_muic_chg_handler(struct max14577_muic_info *info)
{
int chg_type;
bool attached;
int ret = 0;
chg_type = max14577_muic_get_cable_type(info,
MAX14577_CABLE_GROUP_CHG, &attached);
dev_dbg(info->dev,
"external connector is %s(chg_type:0x%x, prev_chg_type:0x%x)\n",
attached ? "attached" : "detached",
chg_type, info->prev_chg_type);
switch (chg_type) {
case MAX14577_CHARGER_TYPE_USB:
ret = max14577_muic_set_path(info, info->path_usb, attached);
if (ret < 0)
return ret;
extcon_set_cable_state_(info->edev, EXTCON_USB, attached);
break;
case MAX14577_CHARGER_TYPE_DEDICATED_CHG:
extcon_set_cable_state_(info->edev, EXTCON_CHG_USB_DCP,
attached);
break;
case MAX14577_CHARGER_TYPE_DOWNSTREAM_PORT:
extcon_set_cable_state_(info->edev, EXTCON_CHG_USB_CDP,
attached);
break;
case MAX14577_CHARGER_TYPE_SPECIAL_500MA:
extcon_set_cable_state_(info->edev, EXTCON_CHG_USB_SLOW,
attached);
break;
case MAX14577_CHARGER_TYPE_SPECIAL_1A:
extcon_set_cable_state_(info->edev, EXTCON_CHG_USB_FAST,
attached);
break;
case MAX14577_CHARGER_TYPE_NONE:
case MAX14577_CHARGER_TYPE_DEAD_BATTERY:
break;
default:
dev_err(info->dev,
"failed to detect %s accessory (chg_type:0x%x)\n",
attached ? "attached" : "detached", chg_type);
return -EINVAL;
}
return 0;
}
static void max14577_muic_irq_work(struct work_struct *work)
{
struct max14577_muic_info *info = container_of(work,
struct max14577_muic_info, irq_work);
int ret = 0;
if (!info->edev)
return;
mutex_lock(&info->mutex);
ret = max14577_bulk_read(info->max14577->regmap,
MAX14577_MUIC_REG_STATUS1, info->status, 2);
if (ret) {
dev_err(info->dev, "failed to read MUIC register\n");
mutex_unlock(&info->mutex);
return;
}
if (info->irq_adc) {
ret = max14577_muic_adc_handler(info);
info->irq_adc = false;
}
if (info->irq_chg) {
ret = max14577_muic_chg_handler(info);
info->irq_chg = false;
}
if (ret < 0)
dev_err(info->dev, "failed to handle MUIC interrupt\n");
mutex_unlock(&info->mutex);
}
static int max14577_parse_irq(struct max14577_muic_info *info, int irq_type)
{
switch (irq_type) {
case MAX14577_IRQ_INT1_ADC:
case MAX14577_IRQ_INT1_ADCLOW:
case MAX14577_IRQ_INT1_ADCERR:
info->irq_adc = true;
return 1;
case MAX14577_IRQ_INT2_CHGTYP:
case MAX14577_IRQ_INT2_CHGDETRUN:
case MAX14577_IRQ_INT2_DCDTMR:
case MAX14577_IRQ_INT2_DBCHG:
case MAX14577_IRQ_INT2_VBVOLT:
info->irq_chg = true;
return 1;
default:
return 0;
}
}
static int max77836_parse_irq(struct max14577_muic_info *info, int irq_type)
{
if (max14577_parse_irq(info, irq_type))
return 1;
switch (irq_type) {
case MAX77836_IRQ_INT1_ADC1K:
info->irq_adc = true;
return 1;
case MAX77836_IRQ_INT2_VIDRM:
info->irq_chg = true;
return 1;
default:
return 0;
}
}
static irqreturn_t max14577_muic_irq_handler(int irq, void *data)
{
struct max14577_muic_info *info = data;
int i, irq_type = -1;
bool irq_parsed;
for (i = 0; i < info->muic_irqs_num; i++)
if (irq == info->muic_irqs[i].virq)
irq_type = info->muic_irqs[i].irq;
switch (info->max14577->dev_type) {
case MAXIM_DEVICE_TYPE_MAX77836:
irq_parsed = max77836_parse_irq(info, irq_type);
break;
case MAXIM_DEVICE_TYPE_MAX14577:
default:
irq_parsed = max14577_parse_irq(info, irq_type);
break;
}
if (!irq_parsed) {
dev_err(info->dev, "muic interrupt: irq %d occurred, skipped\n",
irq_type);
return IRQ_HANDLED;
}
schedule_work(&info->irq_work);
return IRQ_HANDLED;
}
static int max14577_muic_detect_accessory(struct max14577_muic_info *info)
{
int ret = 0;
int adc;
int chg_type;
bool attached;
mutex_lock(&info->mutex);
ret = max14577_bulk_read(info->max14577->regmap,
MAX14577_MUIC_REG_STATUS1, info->status, 2);
if (ret) {
dev_err(info->dev, "failed to read MUIC register\n");
mutex_unlock(&info->mutex);
return ret;
}
adc = max14577_muic_get_cable_type(info, MAX14577_CABLE_GROUP_ADC,
&attached);
if (attached && adc != MAX14577_MUIC_ADC_OPEN) {
ret = max14577_muic_adc_handler(info);
if (ret < 0) {
dev_err(info->dev, "Cannot detect accessory\n");
mutex_unlock(&info->mutex);
return ret;
}
}
chg_type = max14577_muic_get_cable_type(info, MAX14577_CABLE_GROUP_CHG,
&attached);
if (attached && chg_type != MAX14577_CHARGER_TYPE_NONE) {
ret = max14577_muic_chg_handler(info);
if (ret < 0) {
dev_err(info->dev, "Cannot detect charger accessory\n");
mutex_unlock(&info->mutex);
return ret;
}
}
mutex_unlock(&info->mutex);
return 0;
}
static void max14577_muic_detect_cable_wq(struct work_struct *work)
{
struct max14577_muic_info *info = container_of(to_delayed_work(work),
struct max14577_muic_info, wq_detcable);
max14577_muic_detect_accessory(info);
}
static int max14577_muic_probe(struct platform_device *pdev)
{
struct max14577 *max14577 = dev_get_drvdata(pdev->dev.parent);
struct max14577_muic_info *info;
int delay_jiffies;
int ret;
int i;
u8 id;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->dev = &pdev->dev;
info->max14577 = max14577;
platform_set_drvdata(pdev, info);
mutex_init(&info->mutex);
INIT_WORK(&info->irq_work, max14577_muic_irq_work);
switch (max14577->dev_type) {
case MAXIM_DEVICE_TYPE_MAX77836:
info->muic_irqs = max77836_muic_irqs;
info->muic_irqs_num = ARRAY_SIZE(max77836_muic_irqs);
break;
case MAXIM_DEVICE_TYPE_MAX14577:
default:
info->muic_irqs = max14577_muic_irqs;
info->muic_irqs_num = ARRAY_SIZE(max14577_muic_irqs);
}
for (i = 0; i < info->muic_irqs_num; i++) {
struct max14577_muic_irq *muic_irq = &info->muic_irqs[i];
unsigned int virq = 0;
virq = regmap_irq_get_virq(max14577->irq_data, muic_irq->irq);
if (virq <= 0)
return -EINVAL;
muic_irq->virq = virq;
ret = devm_request_threaded_irq(&pdev->dev, virq, NULL,
max14577_muic_irq_handler,
IRQF_NO_SUSPEND,
muic_irq->name, info);
if (ret) {
dev_err(&pdev->dev,
"failed: irq request (IRQ: %d, error :%d)\n",
muic_irq->irq, ret);
return ret;
}
}
info->edev = devm_extcon_dev_allocate(&pdev->dev,
max14577_extcon_cable);
if (IS_ERR(info->edev)) {
dev_err(&pdev->dev, "failed to allocate memory for extcon\n");
return -ENOMEM;
}
ret = devm_extcon_dev_register(&pdev->dev, info->edev);
if (ret) {
dev_err(&pdev->dev, "failed to register extcon device\n");
return ret;
}
info->path_usb = CTRL1_SW_USB;
info->path_uart = CTRL1_SW_UART;
delay_jiffies = msecs_to_jiffies(DELAY_MS_DEFAULT);
max14577_muic_set_path(info, info->path_uart, true);
ret = max14577_read_reg(info->max14577->regmap,
MAX14577_REG_DEVICEID, &id);
if (ret < 0) {
dev_err(&pdev->dev, "failed to read revision number\n");
return ret;
}
dev_info(info->dev, "device ID : 0x%x\n", id);
max14577_muic_set_debounce_time(info, ADC_DEBOUNCE_TIME_25MS);
INIT_DELAYED_WORK(&info->wq_detcable, max14577_muic_detect_cable_wq);
queue_delayed_work(system_power_efficient_wq, &info->wq_detcable,
delay_jiffies);
return ret;
}
static int max14577_muic_remove(struct platform_device *pdev)
{
struct max14577_muic_info *info = platform_get_drvdata(pdev);
cancel_work_sync(&info->irq_work);
return 0;
}
