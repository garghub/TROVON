static int max8997_muic_handle_usb(struct max8997_muic_info *info,
enum max8997_muic_usb_type usb_type, bool attached)
{
int ret = 0;
if (usb_type == MAX8997_USB_HOST) {
ret = max8997_update_reg(info->muic, MAX8997_MUIC_REG_CONTROL1,
attached ? MAX8997_SW_USB : MAX8997_SW_OPEN,
SW_MASK);
if (ret) {
dev_err(info->dev, "failed to update muic register\n");
goto out;
}
}
switch (usb_type) {
case MAX8997_USB_HOST:
extcon_set_cable_state(info->edev, "USB-Host", attached);
break;
case MAX8997_USB_DEVICE:
extcon_set_cable_state(info->edev, "USB", attached);
break;
default:
ret = -EINVAL;
break;
}
out:
return ret;
}
static int max8997_muic_handle_dock(struct max8997_muic_info *info,
int adc, bool attached)
{
int ret = 0;
ret = max8997_update_reg(info->muic, MAX8997_MUIC_REG_CONTROL1,
attached ? MAX8997_SW_AUDIO : MAX8997_SW_OPEN,
SW_MASK);
if (ret) {
dev_err(info->dev, "failed to update muic register\n");
goto out;
}
switch (adc) {
case MAX8997_ADC_DESKDOCK:
extcon_set_cable_state(info->edev, "Dock-desk", attached);
break;
case MAX8997_ADC_CARDOCK:
extcon_set_cable_state(info->edev, "Dock-card", attached);
break;
default:
ret = -EINVAL;
break;
}
out:
return ret;
}
static int max8997_muic_handle_jig_uart(struct max8997_muic_info *info,
bool attached)
{
int ret = 0;
ret = max8997_update_reg(info->muic, MAX8997_MUIC_REG_CONTROL1,
attached ? MAX8997_SW_UART : MAX8997_SW_OPEN,
SW_MASK);
if (ret) {
dev_err(info->dev, "failed to update muic register\n");
goto out;
}
extcon_set_cable_state(info->edev, "JIG", attached);
out:
return ret;
}
static int max8997_muic_handle_adc_detach(struct max8997_muic_info *info)
{
int ret = 0;
switch (info->pre_adc) {
case MAX8997_ADC_GROUND:
ret = max8997_muic_handle_usb(info, MAX8997_USB_HOST, false);
break;
case MAX8997_ADC_MHL:
extcon_set_cable_state(info->edev, "MHL", false);
break;
case MAX8997_ADC_JIG_USB_1:
case MAX8997_ADC_JIG_USB_2:
ret = max8997_muic_handle_usb(info, MAX8997_USB_DEVICE, false);
break;
case MAX8997_ADC_DESKDOCK:
case MAX8997_ADC_CARDOCK:
ret = max8997_muic_handle_dock(info, info->pre_adc, false);
break;
case MAX8997_ADC_JIG_UART:
ret = max8997_muic_handle_jig_uart(info, false);
break;
default:
break;
}
return ret;
}
static int max8997_muic_handle_adc(struct max8997_muic_info *info, int adc)
{
int ret = 0;
switch (adc) {
case MAX8997_ADC_GROUND:
ret = max8997_muic_handle_usb(info, MAX8997_USB_HOST, true);
break;
case MAX8997_ADC_MHL:
extcon_set_cable_state(info->edev, "MHL", true);
break;
case MAX8997_ADC_JIG_USB_1:
case MAX8997_ADC_JIG_USB_2:
ret = max8997_muic_handle_usb(info, MAX8997_USB_DEVICE, true);
break;
case MAX8997_ADC_DESKDOCK:
case MAX8997_ADC_CARDOCK:
ret = max8997_muic_handle_dock(info, adc, true);
break;
case MAX8997_ADC_JIG_UART:
ret = max8997_muic_handle_jig_uart(info, true);
break;
case MAX8997_ADC_OPEN:
ret = max8997_muic_handle_adc_detach(info);
break;
default:
ret = -EINVAL;
goto out;
}
info->pre_adc = adc;
out:
return ret;
}
static int max8997_muic_handle_charger_type_detach(
struct max8997_muic_info *info)
{
switch (info->pre_charger_type) {
case MAX8997_CHARGER_TYPE_USB:
extcon_set_cable_state(info->edev, "USB", false);
break;
case MAX8997_CHARGER_TYPE_DOWNSTREAM_PORT:
extcon_set_cable_state(info->edev, "Charge-downstream", false);
break;
case MAX8997_CHARGER_TYPE_DEDICATED_CHG:
extcon_set_cable_state(info->edev, "TA", false);
break;
case MAX8997_CHARGER_TYPE_500MA:
extcon_set_cable_state(info->edev, "Slow-charger", false);
break;
case MAX8997_CHARGER_TYPE_1A:
extcon_set_cable_state(info->edev, "Fast-charger", false);
break;
default:
return -EINVAL;
break;
}
return 0;
}
static int max8997_muic_handle_charger_type(struct max8997_muic_info *info,
enum max8997_muic_charger_type charger_type)
{
u8 adc;
int ret;
ret = max8997_read_reg(info->muic, MAX8997_MUIC_REG_STATUS1, &adc);
if (ret) {
dev_err(info->dev, "failed to read muic register\n");
goto out;
}
switch (charger_type) {
case MAX8997_CHARGER_TYPE_NONE:
ret = max8997_muic_handle_charger_type_detach(info);
break;
case MAX8997_CHARGER_TYPE_USB:
if ((adc & STATUS1_ADC_MASK) == MAX8997_ADC_OPEN) {
max8997_muic_handle_usb(info,
MAX8997_USB_DEVICE, true);
}
break;
case MAX8997_CHARGER_TYPE_DOWNSTREAM_PORT:
extcon_set_cable_state(info->edev, "Charge-downstream", true);
break;
case MAX8997_CHARGER_TYPE_DEDICATED_CHG:
extcon_set_cable_state(info->edev, "TA", true);
break;
case MAX8997_CHARGER_TYPE_500MA:
extcon_set_cable_state(info->edev, "Slow-charger", true);
break;
case MAX8997_CHARGER_TYPE_1A:
extcon_set_cable_state(info->edev, "Fast-charger", true);
break;
default:
ret = -EINVAL;
goto out;
}
info->pre_charger_type = charger_type;
out:
return ret;
}
static void max8997_muic_irq_work(struct work_struct *work)
{
struct max8997_muic_info *info = container_of(work,
struct max8997_muic_info, irq_work);
u8 status[2];
u8 adc, chg_type;
int irq_type = 0;
int i, ret;
mutex_lock(&info->mutex);
ret = max8997_bulk_read(info->muic, MAX8997_MUIC_REG_STATUS1,
2, status);
if (ret) {
dev_err(info->dev, "failed to read muic register\n");
mutex_unlock(&info->mutex);
return;
}
dev_dbg(info->dev, "%s: STATUS1:0x%x, 2:0x%x\n", __func__,
status[0], status[1]);
for (i = 0 ; i < ARRAY_SIZE(muic_irqs) ; i++)
if (info->irq == muic_irqs[i].virq)
irq_type = muic_irqs[i].irq;
switch (irq_type) {
case MAX8997_MUICIRQ_ADC:
adc = status[0] & STATUS1_ADC_MASK;
adc >>= STATUS1_ADC_SHIFT;
max8997_muic_handle_adc(info, adc);
break;
case MAX8997_MUICIRQ_ChgTyp:
chg_type = status[1] & STATUS2_CHGTYP_MASK;
chg_type >>= STATUS2_CHGTYP_SHIFT;
max8997_muic_handle_charger_type(info, chg_type);
break;
default:
dev_info(info->dev, "misc interrupt: irq %d occurred\n",
irq_type);
break;
}
mutex_unlock(&info->mutex);
return;
}
static irqreturn_t max8997_muic_irq_handler(int irq, void *data)
{
struct max8997_muic_info *info = data;
dev_dbg(info->dev, "irq:%d\n", irq);
info->irq = irq;
schedule_work(&info->irq_work);
return IRQ_HANDLED;
}
static void max8997_muic_detect_dev(struct max8997_muic_info *info)
{
int ret;
u8 status[2], adc, chg_type;
ret = max8997_bulk_read(info->muic, MAX8997_MUIC_REG_STATUS1,
2, status);
if (ret) {
dev_err(info->dev, "failed to read muic register\n");
return;
}
dev_info(info->dev, "STATUS1:0x%x, STATUS2:0x%x\n",
status[0], status[1]);
adc = status[0] & STATUS1_ADC_MASK;
adc >>= STATUS1_ADC_SHIFT;
chg_type = status[1] & STATUS2_CHGTYP_MASK;
chg_type >>= STATUS2_CHGTYP_SHIFT;
max8997_muic_handle_adc(info, adc);
max8997_muic_handle_charger_type(info, chg_type);
}
static int max8997_muic_probe(struct platform_device *pdev)
{
struct max8997_dev *max8997 = dev_get_drvdata(pdev->dev.parent);
struct max8997_platform_data *pdata = dev_get_platdata(max8997->dev);
struct max8997_muic_info *info;
int ret, i;
info = devm_kzalloc(&pdev->dev, sizeof(struct max8997_muic_info),
GFP_KERNEL);
if (!info) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
info->dev = &pdev->dev;
info->muic = max8997->muic;
platform_set_drvdata(pdev, info);
mutex_init(&info->mutex);
INIT_WORK(&info->irq_work, max8997_muic_irq_work);
for (i = 0; i < ARRAY_SIZE(muic_irqs); i++) {
struct max8997_muic_irq *muic_irq = &muic_irqs[i];
unsigned int virq = 0;
virq = irq_create_mapping(max8997->irq_domain, muic_irq->irq);
if (!virq) {
ret = -EINVAL;
goto err_irq;
}
muic_irq->virq = virq;
ret = request_threaded_irq(virq, NULL, max8997_muic_irq_handler,
0, muic_irq->name, info);
if (ret) {
dev_err(&pdev->dev,
"failed: irq request (IRQ: %d,"
" error :%d)\n",
muic_irq->irq, ret);
goto err_irq;
}
}
info->edev = devm_kzalloc(&pdev->dev, sizeof(struct extcon_dev),
GFP_KERNEL);
if (!info->edev) {
dev_err(&pdev->dev, "failed to allocate memory for extcon\n");
ret = -ENOMEM;
goto err_irq;
}
info->edev->name = DEV_NAME;
info->edev->supported_cable = max8997_extcon_cable;
ret = extcon_dev_register(info->edev, NULL);
if (ret) {
dev_err(&pdev->dev, "failed to register extcon device\n");
goto err_irq;
}
if (pdata->muic_pdata) {
struct max8997_muic_platform_data *mdata = info->muic_pdata;
for (i = 0; i < mdata->num_init_data; i++) {
max8997_write_reg(info->muic, mdata->init_data[i].addr,
mdata->init_data[i].data);
}
}
max8997_muic_detect_dev(info);
return ret;
err_irq:
while (--i >= 0)
free_irq(muic_irqs[i].virq, info);
return ret;
}
static int max8997_muic_remove(struct platform_device *pdev)
{
struct max8997_muic_info *info = platform_get_drvdata(pdev);
int i;
for (i = 0; i < ARRAY_SIZE(muic_irqs); i++)
free_irq(muic_irqs[i].virq, info);
cancel_work_sync(&info->irq_work);
extcon_dev_unregister(info->edev);
return 0;
}
