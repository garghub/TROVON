static void ltq_stp_set(struct gpio_chip *chip, unsigned offset, int value)
{
if (value)
ltq_stp_shadow |= (1 << offset);
else
ltq_stp_shadow &= ~(1 << offset);
ltq_stp_w32(ltq_stp_shadow, LTQ_STP_CPU0);
}
static int ltq_stp_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
ltq_stp_set(chip, offset, value);
return 0;
}
static int ltq_stp_hw_init(void)
{
ltq_gpio_request(4, 1, 0, 1, "stp-st");
ltq_gpio_request(5, 1, 0, 1, "stp-d");
ltq_gpio_request(6, 1, 0, 1, "stp-sh");
ltq_stp_w32(0, LTQ_STP_AR);
ltq_stp_w32(0, LTQ_STP_CPU0);
ltq_stp_w32(0, LTQ_STP_CPU1);
ltq_stp_w32(LTQ_STP_CON_SWU, LTQ_STP_CON0);
ltq_stp_w32(0, LTQ_STP_CON1);
ltq_stp_w32_mask(LTQ_STP_EDGE_MASK, LTQ_STP_FALLING, LTQ_STP_CON0);
ltq_stp_w32_mask(0, LTQ_STP_GROUP0, LTQ_STP_CON1);
ltq_stp_w32_mask(LTQ_STP_UPD_MASK, LTQ_STP_UPD_FPI, LTQ_STP_CON1);
ltq_stp_w32_mask(LTQ_STP_SPEED_MASK, LTQ_STP_8HZ, LTQ_STP_CON1);
ltq_stp_w32_mask(0, LTQ_STP_ADSL_SRC, LTQ_STP_CON0);
ltq_pmu_enable(PMU_LED);
return 0;
}
static int __devinit ltq_stp_probe(struct platform_device *pdev)
{
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
int ret = 0;
if (!res)
return -ENOENT;
res = devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), dev_name(&pdev->dev));
if (!res) {
dev_err(&pdev->dev, "failed to request STP memory\n");
return -EBUSY;
}
ltq_stp_membase = devm_ioremap_nocache(&pdev->dev, res->start,
resource_size(res));
if (!ltq_stp_membase) {
dev_err(&pdev->dev, "failed to remap STP memory\n");
return -ENOMEM;
}
ret = gpiochip_add(&ltq_stp_chip);
if (!ret)
ret = ltq_stp_hw_init();
return ret;
}
int __init ltq_stp_init(void)
{
int ret = platform_driver_register(&ltq_stp_driver);
if (ret)
pr_info("ltq_stp: error registering platfom driver");
return ret;
}
