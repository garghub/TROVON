static int wcove_typec_func(struct wcove_typec *wcove,
enum wcove_typec_func func, int param)
{
union acpi_object *obj;
union acpi_object tmp;
union acpi_object argv4 = ACPI_INIT_DSM_ARGV4(1, &tmp);
tmp.type = ACPI_TYPE_INTEGER;
tmp.integer.value = param;
obj = acpi_evaluate_dsm(ACPI_HANDLE(wcove->dev), uuid.b, 1, func,
&argv4);
if (!obj) {
dev_err(wcove->dev, "%s: failed to evaluate _DSM\n", __func__);
return -EIO;
}
ACPI_FREE(obj);
return 0;
}
static irqreturn_t wcove_typec_irq(int irq, void *data)
{
enum typec_role role = TYPEC_SINK;
struct typec_partner_desc partner;
struct wcove_typec *wcove = data;
unsigned int cc1_ctrl;
unsigned int cc2_ctrl;
unsigned int cc_irq1;
unsigned int cc_irq2;
unsigned int status1;
unsigned int status2;
int ret;
mutex_lock(&wcove->lock);
ret = regmap_read(wcove->regmap, USBC_IRQ1, &cc_irq1);
if (ret)
goto err;
ret = regmap_read(wcove->regmap, USBC_IRQ2, &cc_irq2);
if (ret)
goto err;
ret = regmap_read(wcove->regmap, USBC_STATUS1, &status1);
if (ret)
goto err;
ret = regmap_read(wcove->regmap, USBC_STATUS2, &status2);
if (ret)
goto err;
ret = regmap_read(wcove->regmap, USBC_CC1_CTRL, &cc1_ctrl);
if (ret)
goto err;
ret = regmap_read(wcove->regmap, USBC_CC2_CTRL, &cc2_ctrl);
if (ret)
goto err;
if (cc_irq1) {
if (cc_irq1 & USBC_IRQ1_OVERTEMP)
dev_err(wcove->dev, "VCONN Switch Over Temperature!\n");
if (cc_irq1 & USBC_IRQ1_SHORT)
dev_err(wcove->dev, "VCONN Switch Short Circuit!\n");
ret = regmap_write(wcove->regmap, USBC_IRQ1, cc_irq1);
if (ret)
goto err;
}
if (cc_irq2) {
ret = regmap_write(wcove->regmap, USBC_IRQ2, cc_irq2);
if (ret)
goto err;
if (cc_irq2 & ~USBC_IRQ2_CC_CHANGE) {
dev_WARN(wcove->dev, "USB PD handling missing\n");
goto err;
}
}
if (status1 & USBC_STATUS1_DET_ONGOING)
goto out;
if (USBC_STATUS1_RSLT(status1) == USBC_RSLT_NOTHING) {
if (wcove->partner) {
typec_unregister_partner(wcove->partner);
wcove->partner = NULL;
}
wcove_typec_func(wcove, WCOVE_FUNC_ORIENTATION,
WCOVE_ORIENTATION_NORMAL);
wcove_typec_func(wcove, WCOVE_FUNC_ROLE, WCOVE_ROLE_HOST);
typec_set_data_role(wcove->port, TYPEC_DEVICE);
typec_set_pwr_role(wcove->port, TYPEC_SINK);
typec_set_pwr_opmode(wcove->port, TYPEC_PWR_MODE_USB);
goto out;
}
if (wcove->partner)
goto out;
switch (USBC_STATUS1_ORIENT(status1)) {
case USBC_ORIENT_NORMAL:
wcove_typec_func(wcove, WCOVE_FUNC_ORIENTATION,
WCOVE_ORIENTATION_NORMAL);
break;
case USBC_ORIENT_REVERSE:
wcove_typec_func(wcove, WCOVE_FUNC_ORIENTATION,
WCOVE_ORIENTATION_REVERSE);
default:
break;
}
memset(&partner, 0, sizeof(partner));
switch (USBC_STATUS1_RSLT(status1)) {
case USBC_RSLT_SRC_DEFAULT:
typec_set_pwr_opmode(wcove->port, TYPEC_PWR_MODE_USB);
break;
case USBC_RSLT_SRC_1_5A:
typec_set_pwr_opmode(wcove->port, TYPEC_PWR_MODE_1_5A);
break;
case USBC_RSLT_SRC_3_0A:
typec_set_pwr_opmode(wcove->port, TYPEC_PWR_MODE_3_0A);
break;
case USBC_RSLT_SNK:
role = TYPEC_SOURCE;
break;
case USBC_RSLT_DEBUG_ACC:
partner.accessory = TYPEC_ACCESSORY_DEBUG;
break;
case USBC_RSLT_AUDIO_ACC:
partner.accessory = TYPEC_ACCESSORY_AUDIO;
break;
default:
dev_WARN(wcove->dev, "%s Undefined result\n", __func__);
goto err;
}
if (role == TYPEC_SINK) {
wcove_typec_func(wcove, WCOVE_FUNC_ROLE, WCOVE_ROLE_DEVICE);
typec_set_data_role(wcove->port, TYPEC_DEVICE);
typec_set_pwr_role(wcove->port, TYPEC_SINK);
} else {
wcove_typec_func(wcove, WCOVE_FUNC_ROLE, WCOVE_ROLE_HOST);
typec_set_pwr_role(wcove->port, TYPEC_SOURCE);
typec_set_data_role(wcove->port, TYPEC_HOST);
}
wcove->partner = typec_register_partner(wcove->port, &partner);
if (!wcove->partner)
dev_err(wcove->dev, "failed register partner\n");
out:
if ((cc1_ctrl & USBC_CC_CTRL_VCONN_EN) ||
(cc2_ctrl & USBC_CC_CTRL_VCONN_EN))
wcove_typec_func(wcove, WCOVE_FUNC_DRIVE_VCONN, true);
else
wcove_typec_func(wcove, WCOVE_FUNC_DRIVE_VCONN, false);
wcove_typec_func(wcove, WCOVE_FUNC_DRIVE_VBUS,
!!(status2 & USBC_STATUS2_VBUS_REQ));
err:
regmap_write(wcove->regmap, WCOVE_CHGRIRQ0, BIT(5));
mutex_unlock(&wcove->lock);
return IRQ_HANDLED;
}
static int wcove_typec_probe(struct platform_device *pdev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(pdev->dev.parent);
struct wcove_typec *wcove;
unsigned int val;
int ret;
wcove = devm_kzalloc(&pdev->dev, sizeof(*wcove), GFP_KERNEL);
if (!wcove)
return -ENOMEM;
mutex_init(&wcove->lock);
wcove->dev = &pdev->dev;
wcove->regmap = pmic->regmap;
ret = regmap_irq_get_virq(pmic->irq_chip_data_level2,
platform_get_irq(pdev, 0));
if (ret < 0)
return ret;
ret = devm_request_threaded_irq(&pdev->dev, ret, NULL,
wcove_typec_irq, IRQF_ONESHOT,
"wcove_typec", wcove);
if (ret)
return ret;
if (!acpi_check_dsm(ACPI_HANDLE(&pdev->dev), uuid.b, 0, 0x1f)) {
dev_err(&pdev->dev, "Missing _DSM functions\n");
return -ENODEV;
}
wcove->cap.type = TYPEC_PORT_DRP;
wcove->cap.revision = USB_TYPEC_REV_1_1;
wcove->cap.prefer_role = TYPEC_NO_PREFERRED_ROLE;
regmap_read(wcove->regmap, USBC_CONTROL3, &val);
regmap_write(wcove->regmap, USBC_CONTROL3, val | USBC_CONTROL3_PD_DIS);
regmap_read(wcove->regmap, USBC_CONTROL1, &val);
regmap_write(wcove->regmap, USBC_CONTROL1, USBC_CONTROL1_MODE_DRP(val));
wcove->port = typec_register_port(&pdev->dev, &wcove->cap);
if (!wcove->port)
return -ENODEV;
regmap_read(wcove->regmap, USBC_IRQMASK1, &val);
regmap_write(wcove->regmap, USBC_IRQMASK1, val & ~USBC_IRQMASK1_ALL);
regmap_read(wcove->regmap, USBC_IRQMASK2, &val);
regmap_write(wcove->regmap, USBC_IRQMASK2, val & ~USBC_IRQMASK2_ALL);
platform_set_drvdata(pdev, wcove);
return 0;
}
static int wcove_typec_remove(struct platform_device *pdev)
{
struct wcove_typec *wcove = platform_get_drvdata(pdev);
unsigned int val;
regmap_read(wcove->regmap, USBC_IRQMASK1, &val);
regmap_write(wcove->regmap, USBC_IRQMASK1, val | USBC_IRQMASK1_ALL);
regmap_read(wcove->regmap, USBC_IRQMASK2, &val);
regmap_write(wcove->regmap, USBC_IRQMASK2, val | USBC_IRQMASK2_ALL);
typec_unregister_partner(wcove->partner);
typec_unregister_port(wcove->port);
return 0;
}
