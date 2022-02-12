static bool rt8973a_muic_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT8973A_REG_INTM1:
case RT8973A_REG_INTM2:
return true;
default:
break;
}
return false;
}
static int rt8973a_muic_set_path(struct rt8973a_muic_info *info,
unsigned int con_sw, bool attached)
{
int ret;
if (info->auto_config)
return 0;
if (!attached)
con_sw = DM_DP_SWITCH_UART;
switch (con_sw) {
case DM_DP_SWITCH_OPEN:
case DM_DP_SWITCH_USB:
case DM_DP_SWITCH_UART:
ret = regmap_update_bits(info->regmap, RT8973A_REG_MANUAL_SW1,
RT8973A_REG_MANUAL_SW1_DP_MASK |
RT8973A_REG_MANUAL_SW1_DM_MASK,
con_sw);
if (ret < 0) {
dev_err(info->dev,
"cannot update DM_CON/DP_CON switch\n");
return ret;
}
break;
default:
dev_err(info->dev, "Unknown DM_CON/DP_CON switch type (%d)\n",
con_sw);
return -EINVAL;
}
return 0;
}
static int rt8973a_muic_get_cable_type(struct rt8973a_muic_info *info)
{
unsigned int adc, dev1;
int ret, cable_type;
ret = regmap_read(info->regmap, RT8973A_REG_ADC, &adc);
if (ret) {
dev_err(info->dev, "failed to read ADC register\n");
return ret;
}
cable_type = adc & RT8973A_REG_ADC_MASK;
ret = regmap_read(info->regmap, RT8973A_REG_DEV1, &dev1);
if (ret) {
dev_err(info->dev, "failed to read DEV1 register\n");
return ret;
}
switch (adc) {
case RT8973A_MUIC_ADC_OPEN:
if (dev1 & RT8973A_REG_DEV1_USB_MASK)
cable_type = RT8973A_MUIC_ADC_USB;
else if (dev1 & RT8973A_REG_DEV1_DCPORT_MASK)
cable_type = RT8973A_MUIC_ADC_TA;
else
cable_type = RT8973A_MUIC_ADC_OPEN;
break;
default:
break;
}
return cable_type;
}
static int rt8973a_muic_cable_handler(struct rt8973a_muic_info *info,
enum rt8973a_event_type event)
{
static unsigned int prev_cable_type;
const char **cable_names = info->edev->supported_cable;
unsigned int con_sw = DM_DP_SWITCH_UART;
int ret, idx = 0, cable_type;
bool attached = false;
if (!cable_names)
return 0;
switch (event) {
case RT8973A_EVENT_ATTACH:
cable_type = rt8973a_muic_get_cable_type(info);
attached = true;
break;
case RT8973A_EVENT_DETACH:
cable_type = prev_cable_type;
attached = false;
break;
case RT8973A_EVENT_OVP:
case RT8973A_EVENT_OTP:
dev_warn(info->dev,
"happen Over %s issue. Need to disconnect all cables\n",
event == RT8973A_EVENT_OVP ? "Voltage" : "Temperature");
cable_type = prev_cable_type;
attached = false;
break;
default:
dev_err(info->dev,
"Cannot handle this event (event:%d)\n", event);
return -EINVAL;
}
prev_cable_type = cable_type;
switch (cable_type) {
case RT8973A_MUIC_ADC_OTG:
idx = EXTCON_CABLE_USB_HOST;
con_sw = DM_DP_SWITCH_USB;
break;
case RT8973A_MUIC_ADC_TA:
idx = EXTCON_CABLE_TA;
con_sw = DM_DP_SWITCH_OPEN;
break;
case RT8973A_MUIC_ADC_FACTORY_MODE_BOOT_OFF_USB:
idx = EXTCON_CABLE_JIG_OFF_USB;
con_sw = DM_DP_SWITCH_UART;
break;
case RT8973A_MUIC_ADC_FACTORY_MODE_BOOT_ON_USB:
idx = EXTCON_CABLE_JIG_ON_USB;
con_sw = DM_DP_SWITCH_UART;
break;
case RT8973A_MUIC_ADC_FACTORY_MODE_BOOT_OFF_UART:
idx = EXTCON_CABLE_JIG_OFF_UART;
con_sw = DM_DP_SWITCH_UART;
break;
case RT8973A_MUIC_ADC_FACTORY_MODE_BOOT_ON_UART:
idx = EXTCON_CABLE_JIG_ON_UART;
con_sw = DM_DP_SWITCH_UART;
break;
case RT8973A_MUIC_ADC_USB:
idx = EXTCON_CABLE_USB;
con_sw = DM_DP_SWITCH_USB;
break;
case RT8973A_MUIC_ADC_OPEN:
return 0;
case RT8973A_MUIC_ADC_UNKNOWN_ACC_1:
case RT8973A_MUIC_ADC_UNKNOWN_ACC_2:
case RT8973A_MUIC_ADC_UNKNOWN_ACC_3:
case RT8973A_MUIC_ADC_UNKNOWN_ACC_4:
case RT8973A_MUIC_ADC_UNKNOWN_ACC_5:
dev_warn(info->dev,
"Unknown accessory type (adc:0x%x)\n", cable_type);
return 0;
case RT8973A_MUIC_ADC_AUDIO_SEND_END_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S1_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S2_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S3_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S4_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S5_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S6_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S7_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S8_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S9_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S10_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S11_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_REMOTE_S12_BUTTON:
case RT8973A_MUIC_ADC_AUDIO_TYPE2:
dev_warn(info->dev,
"Audio device/button type (adc:0x%x)\n", cable_type);
return 0;
case RT8973A_MUIC_ADC_RESERVED_ACC_1:
case RT8973A_MUIC_ADC_RESERVED_ACC_2:
case RT8973A_MUIC_ADC_RESERVED_ACC_3:
case RT8973A_MUIC_ADC_RESERVED_ACC_4:
case RT8973A_MUIC_ADC_RESERVED_ACC_5:
case RT8973A_MUIC_ADC_PHONE_POWERED_DEV:
return 0;
default:
dev_err(info->dev,
"Cannot handle this cable_type (adc:0x%x)\n",
cable_type);
return -EINVAL;
}
ret = rt8973a_muic_set_path(info, con_sw, attached);
if (ret < 0)
return ret;
extcon_set_cable_state(info->edev, cable_names[idx], attached);
return 0;
}
static void rt8973a_muic_irq_work(struct work_struct *work)
{
struct rt8973a_muic_info *info = container_of(work,
struct rt8973a_muic_info, irq_work);
int ret = 0;
if (!info->edev)
return;
mutex_lock(&info->mutex);
if (info->irq_attach) {
ret = rt8973a_muic_cable_handler(info, RT8973A_EVENT_ATTACH);
info->irq_attach = false;
}
if (info->irq_detach) {
ret = rt8973a_muic_cable_handler(info, RT8973A_EVENT_DETACH);
info->irq_detach = false;
}
if (info->irq_ovp) {
ret = rt8973a_muic_cable_handler(info, RT8973A_EVENT_OVP);
info->irq_ovp = false;
}
if (info->irq_otp) {
ret = rt8973a_muic_cable_handler(info, RT8973A_EVENT_OTP);
info->irq_otp = false;
}
if (ret < 0)
dev_err(info->dev, "failed to handle MUIC interrupt\n");
mutex_unlock(&info->mutex);
}
static irqreturn_t rt8973a_muic_irq_handler(int irq, void *data)
{
struct rt8973a_muic_info *info = data;
int i, irq_type = -1;
for (i = 0; i < info->num_muic_irqs; i++)
if (irq == info->muic_irqs[i].virq)
irq_type = info->muic_irqs[i].irq;
switch (irq_type) {
case RT8973A_INT1_ATTACH:
info->irq_attach = true;
break;
case RT8973A_INT1_DETACH:
info->irq_detach = true;
break;
case RT8973A_INT1_OVP:
info->irq_ovp = true;
break;
case RT8973A_INT1_OTP:
info->irq_otp = true;
break;
case RT8973A_INT1_CHGDET:
case RT8973A_INT1_DCD_T:
case RT8973A_INT1_CONNECT:
case RT8973A_INT1_ADC_CHG:
case RT8973A_INT2_UVLO:
case RT8973A_INT2_POR:
case RT8973A_INT2_OTP_FET:
case RT8973A_INT2_OVP_FET:
case RT8973A_INT2_OCP_LATCH:
case RT8973A_INT2_OCP:
case RT8973A_INT2_OVP_OCP:
default:
dev_dbg(info->dev,
"Cannot handle this interrupt (%d)\n", irq_type);
break;
}
schedule_work(&info->irq_work);
return IRQ_HANDLED;
}
static void rt8973a_muic_detect_cable_wq(struct work_struct *work)
{
struct rt8973a_muic_info *info = container_of(to_delayed_work(work),
struct rt8973a_muic_info, wq_detcable);
int ret;
ret = rt8973a_muic_cable_handler(info, RT8973A_EVENT_ATTACH);
if (ret < 0)
dev_warn(info->dev, "failed to detect cable state\n");
}
static void rt8973a_init_dev_type(struct rt8973a_muic_info *info)
{
unsigned int data, vendor_id, version_id;
int i, ret;
ret = regmap_read(info->regmap, RT8973A_REG_DEVICE_ID, &data);
if (ret) {
dev_err(info->dev,
"failed to read DEVICE_ID register: %d\n", ret);
return;
}
vendor_id = ((data & RT8973A_REG_DEVICE_ID_VENDOR_MASK) >>
RT8973A_REG_DEVICE_ID_VENDOR_SHIFT);
version_id = ((data & RT8973A_REG_DEVICE_ID_VERSION_MASK) >>
RT8973A_REG_DEVICE_ID_VERSION_SHIFT);
dev_info(info->dev, "Device type: version: 0x%x, vendor: 0x%x\n",
version_id, vendor_id);
for (i = 0; i < info->num_reg_data; i++) {
u8 reg = info->reg_data[i].reg;
u8 mask = info->reg_data[i].mask;
u8 val = 0;
if (info->reg_data[i].invert)
val = ~info->reg_data[i].val;
else
val = info->reg_data[i].val;
regmap_update_bits(info->regmap, reg, mask, val);
}
ret = regmap_read(info->regmap, RT8973A_REG_CONTROL1, &data);
if (ret) {
dev_err(info->dev,
"failed to read CONTROL1 register: %d\n", ret);
return;
}
data &= RT8973A_REG_CONTROL1_AUTO_CONFIG_MASK;
if (data) {
info->auto_config = true;
dev_info(info->dev,
"Enable Auto-configuration for internal path\n");
}
}
static int rt8973a_muic_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device_node *np = i2c->dev.of_node;
struct rt8973a_muic_info *info;
int i, ret, irq_flags;
if (!np)
return -EINVAL;
info = devm_kzalloc(&i2c->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
i2c_set_clientdata(i2c, info);
info->dev = &i2c->dev;
info->i2c = i2c;
info->irq = i2c->irq;
info->muic_irqs = rt8973a_muic_irqs;
info->num_muic_irqs = ARRAY_SIZE(rt8973a_muic_irqs);
info->reg_data = rt8973a_reg_data;
info->num_reg_data = ARRAY_SIZE(rt8973a_reg_data);
mutex_init(&info->mutex);
INIT_WORK(&info->irq_work, rt8973a_muic_irq_work);
info->regmap = devm_regmap_init_i2c(i2c, &rt8973a_muic_regmap_config);
if (IS_ERR(info->regmap)) {
ret = PTR_ERR(info->regmap);
dev_err(info->dev, "failed to allocate register map: %d\n",
ret);
return ret;
}
irq_flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT | IRQF_SHARED;
ret = regmap_add_irq_chip(info->regmap, info->irq, irq_flags, 0,
&rt8973a_muic_irq_chip, &info->irq_data);
if (ret != 0) {
dev_err(info->dev, "failed to add irq_chip (irq:%d, err:%d)\n",
info->irq, ret);
return ret;
}
for (i = 0; i < info->num_muic_irqs; i++) {
struct muic_irq *muic_irq = &info->muic_irqs[i];
unsigned int virq = 0;
virq = regmap_irq_get_virq(info->irq_data, muic_irq->irq);
if (virq <= 0)
return -EINVAL;
muic_irq->virq = virq;
ret = devm_request_threaded_irq(info->dev, virq, NULL,
rt8973a_muic_irq_handler,
IRQF_NO_SUSPEND,
muic_irq->name, info);
if (ret) {
dev_err(info->dev,
"failed: irq request (IRQ: %d, error :%d)\n",
muic_irq->irq, ret);
return ret;
}
}
info->edev = devm_extcon_dev_allocate(info->dev, rt8973a_extcon_cable);
if (IS_ERR(info->edev)) {
dev_err(info->dev, "failed to allocate memory for extcon\n");
return -ENOMEM;
}
info->edev->name = np->name;
ret = devm_extcon_dev_register(info->dev, info->edev);
if (ret) {
dev_err(info->dev, "failed to register extcon device\n");
return ret;
}
INIT_DELAYED_WORK(&info->wq_detcable, rt8973a_muic_detect_cable_wq);
queue_delayed_work(system_power_efficient_wq, &info->wq_detcable,
msecs_to_jiffies(DELAY_MS_DEFAULT));
rt8973a_init_dev_type(info);
return 0;
}
static int rt8973a_muic_i2c_remove(struct i2c_client *i2c)
{
struct rt8973a_muic_info *info = i2c_get_clientdata(i2c);
regmap_del_irq_chip(info->irq, info->irq_data);
return 0;
}
static int rt8973a_muic_suspend(struct device *dev)
{
struct i2c_client *i2c = container_of(dev, struct i2c_client, dev);
struct rt8973a_muic_info *info = i2c_get_clientdata(i2c);
enable_irq_wake(info->irq);
return 0;
}
static int rt8973a_muic_resume(struct device *dev)
{
struct i2c_client *i2c = container_of(dev, struct i2c_client, dev);
struct rt8973a_muic_info *info = i2c_get_clientdata(i2c);
disable_irq_wake(info->irq);
return 0;
}
static int __init rt8973a_muic_i2c_init(void)
{
return i2c_add_driver(&rt8973a_muic_i2c_driver);
}
