int pcf50633_mbc_usb_curlim_set(struct pcf50633 *pcf, int ma)
{
struct pcf50633_mbc *mbc = platform_get_drvdata(pcf->mbc_pdev);
int ret = 0;
u8 bits;
int charging_start = 1;
u8 mbcs2, chgmod;
unsigned int mbcc5;
if (ma >= 1000) {
bits = PCF50633_MBCC7_USB_1000mA;
ma = 1000;
} else if (ma >= 500) {
bits = PCF50633_MBCC7_USB_500mA;
ma = 500;
} else if (ma >= 100) {
bits = PCF50633_MBCC7_USB_100mA;
ma = 100;
} else {
bits = PCF50633_MBCC7_USB_SUSPEND;
charging_start = 0;
ma = 0;
}
ret = pcf50633_reg_set_bit_mask(pcf, PCF50633_REG_MBCC7,
PCF50633_MBCC7_USB_MASK, bits);
if (ret)
dev_err(pcf->dev, "error setting usb curlim to %d mA\n", ma);
else
dev_info(pcf->dev, "usb curlim to %d mA\n", ma);
if (mbc->pcf->pdata->charger_reference_current_ma) {
mbcc5 = (ma << 8) / mbc->pcf->pdata->charger_reference_current_ma;
if (mbcc5 > 255)
mbcc5 = 255;
pcf50633_reg_write(mbc->pcf, PCF50633_REG_MBCC5, mbcc5);
}
mbcs2 = pcf50633_reg_read(mbc->pcf, PCF50633_REG_MBCS2);
chgmod = (mbcs2 & PCF50633_MBCS2_MBC_MASK);
if (chgmod != PCF50633_MBCS2_MBC_BAT_FULL)
pcf50633_reg_set_bit_mask(pcf, PCF50633_REG_MBCC1,
PCF50633_MBCC1_CHGENA, PCF50633_MBCC1_CHGENA);
else {
pcf50633_reg_clear_bits(pcf, PCF50633_REG_MBCC1,
PCF50633_MBCC1_CHGENA);
pcf50633_reg_set_bit_mask(pcf, PCF50633_REG_MBCC1,
PCF50633_MBCC1_CHGENA, PCF50633_MBCC1_CHGENA);
}
power_supply_changed(mbc->usb);
return ret;
}
int pcf50633_mbc_get_status(struct pcf50633 *pcf)
{
struct pcf50633_mbc *mbc = platform_get_drvdata(pcf->mbc_pdev);
int status = 0;
u8 chgmod;
if (!mbc)
return 0;
chgmod = pcf50633_reg_read(mbc->pcf, PCF50633_REG_MBCS2)
& PCF50633_MBCS2_MBC_MASK;
if (mbc->usb_online)
status |= PCF50633_MBC_USB_ONLINE;
if (chgmod == PCF50633_MBCS2_MBC_USB_PRE ||
chgmod == PCF50633_MBCS2_MBC_USB_PRE_WAIT ||
chgmod == PCF50633_MBCS2_MBC_USB_FAST ||
chgmod == PCF50633_MBCS2_MBC_USB_FAST_WAIT)
status |= PCF50633_MBC_USB_ACTIVE;
if (mbc->adapter_online)
status |= PCF50633_MBC_ADAPTER_ONLINE;
if (chgmod == PCF50633_MBCS2_MBC_ADP_PRE ||
chgmod == PCF50633_MBCS2_MBC_ADP_PRE_WAIT ||
chgmod == PCF50633_MBCS2_MBC_ADP_FAST ||
chgmod == PCF50633_MBCS2_MBC_ADP_FAST_WAIT)
status |= PCF50633_MBC_ADAPTER_ACTIVE;
return status;
}
int pcf50633_mbc_get_usb_online_status(struct pcf50633 *pcf)
{
struct pcf50633_mbc *mbc = platform_get_drvdata(pcf->mbc_pdev);
if (!mbc)
return 0;
return mbc->usb_online;
}
static ssize_t
show_chgmode(struct device *dev, struct device_attribute *attr, char *buf)
{
struct pcf50633_mbc *mbc = dev_get_drvdata(dev);
u8 mbcs2 = pcf50633_reg_read(mbc->pcf, PCF50633_REG_MBCS2);
u8 chgmod = (mbcs2 & PCF50633_MBCS2_MBC_MASK);
return sprintf(buf, "%d\n", chgmod);
}
static ssize_t
show_usblim(struct device *dev, struct device_attribute *attr, char *buf)
{
struct pcf50633_mbc *mbc = dev_get_drvdata(dev);
u8 usblim = pcf50633_reg_read(mbc->pcf, PCF50633_REG_MBCC7) &
PCF50633_MBCC7_USB_MASK;
unsigned int ma;
if (usblim == PCF50633_MBCC7_USB_1000mA)
ma = 1000;
else if (usblim == PCF50633_MBCC7_USB_500mA)
ma = 500;
else if (usblim == PCF50633_MBCC7_USB_100mA)
ma = 100;
else
ma = 0;
return sprintf(buf, "%u\n", ma);
}
static ssize_t set_usblim(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct pcf50633_mbc *mbc = dev_get_drvdata(dev);
unsigned long ma;
int ret;
ret = kstrtoul(buf, 10, &ma);
if (ret)
return ret;
pcf50633_mbc_usb_curlim_set(mbc->pcf, ma);
return count;
}
static ssize_t
show_chglim(struct device *dev, struct device_attribute *attr, char *buf)
{
struct pcf50633_mbc *mbc = dev_get_drvdata(dev);
u8 mbcc5 = pcf50633_reg_read(mbc->pcf, PCF50633_REG_MBCC5);
unsigned int ma;
if (!mbc->pcf->pdata->charger_reference_current_ma)
return -ENODEV;
ma = (mbc->pcf->pdata->charger_reference_current_ma * mbcc5) >> 8;
return sprintf(buf, "%u\n", ma);
}
static ssize_t set_chglim(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct pcf50633_mbc *mbc = dev_get_drvdata(dev);
unsigned long ma;
unsigned int mbcc5;
int ret;
if (!mbc->pcf->pdata->charger_reference_current_ma)
return -ENODEV;
ret = kstrtoul(buf, 10, &ma);
if (ret)
return ret;
mbcc5 = (ma << 8) / mbc->pcf->pdata->charger_reference_current_ma;
if (mbcc5 > 255)
mbcc5 = 255;
pcf50633_reg_write(mbc->pcf, PCF50633_REG_MBCC5, mbcc5);
return count;
}
static void
pcf50633_mbc_irq_handler(int irq, void *data)
{
struct pcf50633_mbc *mbc = data;
if (irq == PCF50633_IRQ_USBINS) {
mbc->usb_online = 1;
} else if (irq == PCF50633_IRQ_USBREM) {
mbc->usb_online = 0;
pcf50633_mbc_usb_curlim_set(mbc->pcf, 0);
}
if (irq == PCF50633_IRQ_ADPINS)
mbc->adapter_online = 1;
else if (irq == PCF50633_IRQ_ADPREM)
mbc->adapter_online = 0;
power_supply_changed(mbc->ac);
power_supply_changed(mbc->usb);
power_supply_changed(mbc->adapter);
if (mbc->pcf->pdata->mbc_event_callback)
mbc->pcf->pdata->mbc_event_callback(mbc->pcf, irq);
}
static int adapter_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct pcf50633_mbc *mbc = power_supply_get_drvdata(psy);
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = mbc->adapter_online;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int usb_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct pcf50633_mbc *mbc = power_supply_get_drvdata(psy);
int ret = 0;
u8 usblim = pcf50633_reg_read(mbc->pcf, PCF50633_REG_MBCC7) &
PCF50633_MBCC7_USB_MASK;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = mbc->usb_online &&
(usblim <= PCF50633_MBCC7_USB_500mA);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int ac_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct pcf50633_mbc *mbc = power_supply_get_drvdata(psy);
int ret = 0;
u8 usblim = pcf50633_reg_read(mbc->pcf, PCF50633_REG_MBCC7) &
PCF50633_MBCC7_USB_MASK;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = mbc->usb_online &&
(usblim == PCF50633_MBCC7_USB_1000mA);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int pcf50633_mbc_probe(struct platform_device *pdev)
{
struct power_supply_config psy_cfg = {};
struct pcf50633_mbc *mbc;
int i;
u8 mbcs1;
mbc = devm_kzalloc(&pdev->dev, sizeof(*mbc), GFP_KERNEL);
if (!mbc)
return -ENOMEM;
platform_set_drvdata(pdev, mbc);
mbc->pcf = dev_to_pcf50633(pdev->dev.parent);
for (i = 0; i < ARRAY_SIZE(mbc_irq_handlers); i++)
pcf50633_register_irq(mbc->pcf, mbc_irq_handlers[i],
pcf50633_mbc_irq_handler, mbc);
psy_cfg.supplied_to = mbc->pcf->pdata->batteries;
psy_cfg.num_supplicants = mbc->pcf->pdata->num_batteries;
psy_cfg.drv_data = mbc;
mbc->adapter = power_supply_register(&pdev->dev,
&pcf50633_mbc_adapter_desc,
&psy_cfg);
if (IS_ERR(mbc->adapter)) {
dev_err(mbc->pcf->dev, "failed to register adapter\n");
return PTR_ERR(mbc->adapter);
}
mbc->usb = power_supply_register(&pdev->dev, &pcf50633_mbc_usb_desc,
&psy_cfg);
if (IS_ERR(mbc->usb)) {
dev_err(mbc->pcf->dev, "failed to register usb\n");
power_supply_unregister(mbc->adapter);
return PTR_ERR(mbc->usb);
}
mbc->ac = power_supply_register(&pdev->dev, &pcf50633_mbc_ac_desc,
&psy_cfg);
if (IS_ERR(mbc->ac)) {
dev_err(mbc->pcf->dev, "failed to register ac\n");
power_supply_unregister(mbc->adapter);
power_supply_unregister(mbc->usb);
return PTR_ERR(mbc->ac);
}
if (sysfs_create_group(&pdev->dev.kobj, &mbc_attr_group))
dev_err(mbc->pcf->dev, "failed to create sysfs entries\n");
mbcs1 = pcf50633_reg_read(mbc->pcf, PCF50633_REG_MBCS1);
if (mbcs1 & PCF50633_MBCS1_USBPRES)
pcf50633_mbc_irq_handler(PCF50633_IRQ_USBINS, mbc);
if (mbcs1 & PCF50633_MBCS1_ADAPTPRES)
pcf50633_mbc_irq_handler(PCF50633_IRQ_ADPINS, mbc);
return 0;
}
static int pcf50633_mbc_remove(struct platform_device *pdev)
{
struct pcf50633_mbc *mbc = platform_get_drvdata(pdev);
int i;
for (i = 0; i < ARRAY_SIZE(mbc_irq_handlers); i++)
pcf50633_free_irq(mbc->pcf, mbc_irq_handlers[i]);
sysfs_remove_group(&pdev->dev.kobj, &mbc_attr_group);
power_supply_unregister(mbc->usb);
power_supply_unregister(mbc->adapter);
power_supply_unregister(mbc->ac);
return 0;
}
