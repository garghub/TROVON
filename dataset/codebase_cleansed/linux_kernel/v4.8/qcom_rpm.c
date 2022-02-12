int qcom_rpm_write(struct qcom_rpm *rpm,
int state,
int resource,
u32 *buf, size_t count)
{
const struct qcom_rpm_resource *res;
const struct qcom_rpm_data *data = rpm->data;
u32 sel_mask[RPM_MAX_SEL_SIZE] = { 0 };
int left;
int ret = 0;
int i;
if (WARN_ON(resource < 0 || resource >= data->n_resources))
return -EINVAL;
res = &data->resource_table[resource];
if (WARN_ON(res->size != count))
return -EINVAL;
mutex_lock(&rpm->lock);
for (i = 0; i < res->size; i++)
writel_relaxed(buf[i], RPM_REQ_REG(rpm, res->target_id + i));
bitmap_set((unsigned long *)sel_mask, res->select_id, 1);
for (i = 0; i < rpm->data->req_sel_size; i++) {
writel_relaxed(sel_mask[i],
RPM_CTRL_REG(rpm, rpm->data->req_sel_off + i));
}
writel_relaxed(BIT(state), RPM_CTRL_REG(rpm, rpm->data->req_ctx_off));
reinit_completion(&rpm->ack);
regmap_write(rpm->ipc_regmap, rpm->ipc_offset, BIT(rpm->ipc_bit));
left = wait_for_completion_timeout(&rpm->ack, RPM_REQUEST_TIMEOUT);
if (!left)
ret = -ETIMEDOUT;
else if (rpm->ack_status & RPM_REJECTED)
ret = -EIO;
mutex_unlock(&rpm->lock);
return ret;
}
static irqreturn_t qcom_rpm_ack_interrupt(int irq, void *dev)
{
struct qcom_rpm *rpm = dev;
u32 ack;
int i;
ack = readl_relaxed(RPM_CTRL_REG(rpm, rpm->data->ack_ctx_off));
for (i = 0; i < rpm->data->ack_sel_size; i++)
writel_relaxed(0,
RPM_CTRL_REG(rpm, rpm->data->ack_sel_off + i));
writel(0, RPM_CTRL_REG(rpm, rpm->data->ack_ctx_off));
if (ack & RPM_NOTIFICATION) {
dev_warn(rpm->dev, "ignoring notification!\n");
} else {
rpm->ack_status = ack;
complete(&rpm->ack);
}
return IRQ_HANDLED;
}
static irqreturn_t qcom_rpm_err_interrupt(int irq, void *dev)
{
struct qcom_rpm *rpm = dev;
regmap_write(rpm->ipc_regmap, rpm->ipc_offset, BIT(rpm->ipc_bit));
dev_err(rpm->dev, "RPM triggered fatal error\n");
return IRQ_HANDLED;
}
static irqreturn_t qcom_rpm_wakeup_interrupt(int irq, void *dev)
{
return IRQ_HANDLED;
}
static int qcom_rpm_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct device_node *syscon_np;
struct resource *res;
struct qcom_rpm *rpm;
u32 fw_version[3];
int irq_wakeup;
int irq_ack;
int irq_err;
int ret;
rpm = devm_kzalloc(&pdev->dev, sizeof(*rpm), GFP_KERNEL);
if (!rpm)
return -ENOMEM;
rpm->dev = &pdev->dev;
mutex_init(&rpm->lock);
init_completion(&rpm->ack);
irq_ack = platform_get_irq_byname(pdev, "ack");
if (irq_ack < 0) {
dev_err(&pdev->dev, "required ack interrupt missing\n");
return irq_ack;
}
irq_err = platform_get_irq_byname(pdev, "err");
if (irq_err < 0) {
dev_err(&pdev->dev, "required err interrupt missing\n");
return irq_err;
}
irq_wakeup = platform_get_irq_byname(pdev, "wakeup");
if (irq_wakeup < 0) {
dev_err(&pdev->dev, "required wakeup interrupt missing\n");
return irq_wakeup;
}
match = of_match_device(qcom_rpm_of_match, &pdev->dev);
if (!match)
return -ENODEV;
rpm->data = match->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rpm->status_regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rpm->status_regs))
return PTR_ERR(rpm->status_regs);
rpm->ctrl_regs = rpm->status_regs + 0x400;
rpm->req_regs = rpm->status_regs + 0x600;
syscon_np = of_parse_phandle(pdev->dev.of_node, "qcom,ipc", 0);
if (!syscon_np) {
dev_err(&pdev->dev, "no qcom,ipc node\n");
return -ENODEV;
}
rpm->ipc_regmap = syscon_node_to_regmap(syscon_np);
if (IS_ERR(rpm->ipc_regmap))
return PTR_ERR(rpm->ipc_regmap);
ret = of_property_read_u32_index(pdev->dev.of_node, "qcom,ipc", 1,
&rpm->ipc_offset);
if (ret < 0) {
dev_err(&pdev->dev, "no offset in qcom,ipc\n");
return -EINVAL;
}
ret = of_property_read_u32_index(pdev->dev.of_node, "qcom,ipc", 2,
&rpm->ipc_bit);
if (ret < 0) {
dev_err(&pdev->dev, "no bit in qcom,ipc\n");
return -EINVAL;
}
dev_set_drvdata(&pdev->dev, rpm);
fw_version[0] = readl(RPM_STATUS_REG(rpm, 0));
fw_version[1] = readl(RPM_STATUS_REG(rpm, 1));
fw_version[2] = readl(RPM_STATUS_REG(rpm, 2));
if (fw_version[0] != rpm->data->version) {
dev_err(&pdev->dev,
"RPM version %u.%u.%u incompatible with driver version %u",
fw_version[0],
fw_version[1],
fw_version[2],
rpm->data->version);
return -EFAULT;
}
dev_info(&pdev->dev, "RPM firmware %u.%u.%u\n", fw_version[0],
fw_version[1],
fw_version[2]);
ret = devm_request_irq(&pdev->dev,
irq_ack,
qcom_rpm_ack_interrupt,
IRQF_TRIGGER_RISING,
"qcom_rpm_ack",
rpm);
if (ret) {
dev_err(&pdev->dev, "failed to request ack interrupt\n");
return ret;
}
ret = irq_set_irq_wake(irq_ack, 1);
if (ret)
dev_warn(&pdev->dev, "failed to mark ack irq as wakeup\n");
ret = devm_request_irq(&pdev->dev,
irq_err,
qcom_rpm_err_interrupt,
IRQF_TRIGGER_RISING,
"qcom_rpm_err",
rpm);
if (ret) {
dev_err(&pdev->dev, "failed to request err interrupt\n");
return ret;
}
ret = devm_request_irq(&pdev->dev,
irq_wakeup,
qcom_rpm_wakeup_interrupt,
IRQF_TRIGGER_RISING,
"qcom_rpm_wakeup",
rpm);
if (ret) {
dev_err(&pdev->dev, "failed to request wakeup interrupt\n");
return ret;
}
ret = irq_set_irq_wake(irq_wakeup, 1);
if (ret)
dev_warn(&pdev->dev, "failed to mark wakeup irq as wakeup\n");
return of_platform_populate(pdev->dev.of_node, NULL, NULL, &pdev->dev);
}
static int qcom_rpm_remove(struct platform_device *pdev)
{
of_platform_depopulate(&pdev->dev);
return 0;
}
static int __init qcom_rpm_init(void)
{
return platform_driver_register(&qcom_rpm_driver);
}
static void __exit qcom_rpm_exit(void)
{
platform_driver_unregister(&qcom_rpm_driver);
}
