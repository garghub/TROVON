static int twl6030_irq_pm_notifier(struct notifier_block *notifier,
unsigned long pm_event, void *unused)
{
int chained_wakeups;
struct twl6030_irq *pdata = container_of(notifier, struct twl6030_irq,
pm_nb);
switch (pm_event) {
case PM_SUSPEND_PREPARE:
chained_wakeups = atomic_read(&pdata->wakeirqs);
if (chained_wakeups && !pdata->irq_wake_enabled) {
if (enable_irq_wake(pdata->twl_irq))
pr_err("twl6030 IRQ wake enable failed\n");
else
pdata->irq_wake_enabled = true;
} else if (!chained_wakeups && pdata->irq_wake_enabled) {
disable_irq_wake(pdata->twl_irq);
pdata->irq_wake_enabled = false;
}
disable_irq(pdata->twl_irq);
break;
case PM_POST_SUSPEND:
enable_irq(pdata->twl_irq);
break;
default:
break;
}
return NOTIFY_DONE;
}
static irqreturn_t twl6030_irq_thread(int irq, void *data)
{
int i, ret;
union {
u8 bytes[4];
__le32 int_sts;
} sts;
u32 int_sts;
struct twl6030_irq *pdata = data;
ret = twl_i2c_read(TWL_MODULE_PIH, sts.bytes, REG_INT_STS_A, 3);
if (ret) {
pr_warn("twl6030_irq: I2C error %d reading PIH ISR\n", ret);
return IRQ_HANDLED;
}
sts.bytes[3] = 0;
if (sts.bytes[2] & 0x10)
sts.bytes[2] |= 0x08;
int_sts = le32_to_cpu(sts.int_sts);
for (i = 0; int_sts; int_sts >>= 1, i++)
if (int_sts & 0x1) {
int module_irq =
irq_find_mapping(pdata->irq_domain,
pdata->irq_mapping_tbl[i]);
if (module_irq)
handle_nested_irq(module_irq);
else
pr_err("twl6030_irq: Unmapped PIH ISR %u detected\n",
i);
pr_debug("twl6030_irq: PIH ISR %u, virq%u\n",
i, module_irq);
}
ret = twl_i2c_write_u8(TWL_MODULE_PIH, 0x00, REG_INT_STS_A);
if (ret)
pr_warn("twl6030_irq: I2C error in clearing PIH ISR\n");
return IRQ_HANDLED;
}
static int twl6030_irq_set_wake(struct irq_data *d, unsigned int on)
{
struct twl6030_irq *pdata = irq_get_chip_data(d->irq);
if (on)
atomic_inc(&pdata->wakeirqs);
else
atomic_dec(&pdata->wakeirqs);
return 0;
}
int twl6030_interrupt_unmask(u8 bit_mask, u8 offset)
{
int ret;
u8 unmask_value;
ret = twl_i2c_read_u8(TWL_MODULE_PIH, &unmask_value,
REG_INT_STS_A + offset);
unmask_value &= (~(bit_mask));
ret |= twl_i2c_write_u8(TWL_MODULE_PIH, unmask_value,
REG_INT_STS_A + offset);
return ret;
}
int twl6030_interrupt_mask(u8 bit_mask, u8 offset)
{
int ret;
u8 mask_value;
ret = twl_i2c_read_u8(TWL_MODULE_PIH, &mask_value,
REG_INT_STS_A + offset);
mask_value |= (bit_mask);
ret |= twl_i2c_write_u8(TWL_MODULE_PIH, mask_value,
REG_INT_STS_A + offset);
return ret;
}
int twl6030_mmc_card_detect_config(void)
{
int ret;
u8 reg_val = 0;
twl6030_interrupt_unmask(TWL6030_MMCDETECT_INT_MASK,
REG_INT_MSK_LINE_B);
twl6030_interrupt_unmask(TWL6030_MMCDETECT_INT_MASK,
REG_INT_MSK_STS_B);
ret = twl_i2c_read_u8(TWL6030_MODULE_ID0, &reg_val, TWL6030_MMCCTRL);
if (ret < 0) {
pr_err("twl6030: Failed to read MMCCTRL, error %d\n", ret);
return ret;
}
reg_val &= ~VMMC_AUTO_OFF;
reg_val |= SW_FC;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID0, reg_val, TWL6030_MMCCTRL);
if (ret < 0) {
pr_err("twl6030: Failed to write MMCCTRL, error %d\n", ret);
return ret;
}
ret = twl_i2c_read_u8(TWL6030_MODULE_ID0, &reg_val,
TWL6030_CFG_INPUT_PUPD3);
if (ret < 0) {
pr_err("twl6030: Failed to read CFG_INPUT_PUPD3, error %d\n",
ret);
return ret;
}
reg_val &= ~(MMC_PU | MMC_PD);
ret = twl_i2c_write_u8(TWL6030_MODULE_ID0, reg_val,
TWL6030_CFG_INPUT_PUPD3);
if (ret < 0) {
pr_err("twl6030: Failed to write CFG_INPUT_PUPD3, error %d\n",
ret);
return ret;
}
return irq_find_mapping(twl6030_irq->irq_domain,
MMCDETECT_INTR_OFFSET);
}
int twl6030_mmc_card_detect(struct device *dev, int slot)
{
int ret = -EIO;
u8 read_reg = 0;
struct platform_device *pdev = to_platform_device(dev);
if (pdev->id) {
pr_err("Unknown MMC controller %d in %s\n", pdev->id, __func__);
return ret;
}
ret = twl_i2c_read_u8(TWL6030_MODULE_ID0, &read_reg,
TWL6030_MMCCTRL);
if (ret >= 0)
ret = read_reg & STS_MMC;
return ret;
}
static int twl6030_irq_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hwirq)
{
struct twl6030_irq *pdata = d->host_data;
irq_set_chip_data(virq, pdata);
irq_set_chip_and_handler(virq, &pdata->irq_chip, handle_simple_irq);
irq_set_nested_thread(virq, true);
irq_set_parent(virq, pdata->twl_irq);
#ifdef CONFIG_ARM
set_irq_flags(virq, IRQF_VALID);
#else
irq_set_noprobe(virq);
#endif
return 0;
}
static void twl6030_irq_unmap(struct irq_domain *d, unsigned int virq)
{
#ifdef CONFIG_ARM
set_irq_flags(virq, 0);
#endif
irq_set_chip_and_handler(virq, NULL, NULL);
irq_set_chip_data(virq, NULL);
}
int twl6030_init_irq(struct device *dev, int irq_num)
{
struct device_node *node = dev->of_node;
int nr_irqs;
int status;
u8 mask[3];
const struct of_device_id *of_id;
of_id = of_match_device(twl6030_of_match, dev);
if (!of_id || !of_id->data) {
dev_err(dev, "Unknown TWL device model\n");
return -EINVAL;
}
nr_irqs = TWL6030_NR_IRQS;
twl6030_irq = devm_kzalloc(dev, sizeof(*twl6030_irq), GFP_KERNEL);
if (!twl6030_irq) {
dev_err(dev, "twl6030_irq: Memory allocation failed\n");
return -ENOMEM;
}
mask[0] = 0xFF;
mask[1] = 0xFF;
mask[2] = 0xFF;
status = twl_i2c_write(TWL_MODULE_PIH, &mask[0], REG_INT_MSK_LINE_A, 3);
status |= twl_i2c_write(TWL_MODULE_PIH, &mask[0], REG_INT_MSK_STS_A, 3);
status |= twl_i2c_write(TWL_MODULE_PIH, &mask[0], REG_INT_STS_A, 3);
if (status < 0) {
dev_err(dev, "I2C err writing TWL_MODULE_PIH: %d\n", status);
return status;
}
twl6030_irq->irq_chip = dummy_irq_chip;
twl6030_irq->irq_chip.name = "twl6030";
twl6030_irq->irq_chip.irq_set_type = NULL;
twl6030_irq->irq_chip.irq_set_wake = twl6030_irq_set_wake;
twl6030_irq->pm_nb.notifier_call = twl6030_irq_pm_notifier;
atomic_set(&twl6030_irq->wakeirqs, 0);
twl6030_irq->irq_mapping_tbl = of_id->data;
twl6030_irq->irq_domain =
irq_domain_add_linear(node, nr_irqs,
&twl6030_irq_domain_ops, twl6030_irq);
if (!twl6030_irq->irq_domain) {
dev_err(dev, "Can't add irq_domain\n");
return -ENOMEM;
}
dev_info(dev, "PIH (irq %d) nested IRQs\n", irq_num);
status = request_threaded_irq(irq_num, NULL, twl6030_irq_thread,
IRQF_ONESHOT, "TWL6030-PIH", twl6030_irq);
if (status < 0) {
dev_err(dev, "could not claim irq %d: %d\n", irq_num, status);
goto fail_irq;
}
twl6030_irq->twl_irq = irq_num;
register_pm_notifier(&twl6030_irq->pm_nb);
return 0;
fail_irq:
irq_domain_remove(twl6030_irq->irq_domain);
return status;
}
int twl6030_exit_irq(void)
{
if (twl6030_irq && twl6030_irq->twl_irq) {
unregister_pm_notifier(&twl6030_irq->pm_nb);
free_irq(twl6030_irq->twl_irq, NULL);
}
return 0;
}
