static void ltq_ebu_apply(void)
{
unsigned long flags;
spin_lock_irqsave(&ebu_lock, flags);
ltq_ebu_w32(LTQ_EBU_BUSCON, LTQ_EBU_BUSCON1);
*((__u16 *)ltq_ebu_gpio_membase) = ltq_ebu_gpio_shadow;
ltq_ebu_w32(LTQ_EBU_BUSCON | LTQ_EBU_WP, LTQ_EBU_BUSCON1);
spin_unlock_irqrestore(&ebu_lock, flags);
}
static void ltq_ebu_set(struct gpio_chip *chip, unsigned offset, int value)
{
if (value)
ltq_ebu_gpio_shadow |= (1 << offset);
else
ltq_ebu_gpio_shadow &= ~(1 << offset);
ltq_ebu_apply();
}
static int ltq_ebu_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
ltq_ebu_set(chip, offset, value);
return 0;
}
static int ltq_ebu_probe(struct platform_device *pdev)
{
int ret = 0;
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get memory resource\n");
return -ENOENT;
}
res = devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), dev_name(&pdev->dev));
if (!res) {
dev_err(&pdev->dev, "failed to request memory resource\n");
return -EBUSY;
}
ltq_ebu_gpio_membase = devm_ioremap_nocache(&pdev->dev, res->start,
resource_size(res));
if (!ltq_ebu_gpio_membase) {
dev_err(&pdev->dev, "Failed to ioremap mem region\n");
return -ENOMEM;
}
ltq_ebu_gpio_shadow = (unsigned int) pdev->dev.platform_data;
ltq_ebu_w32(pdev->resource->start | 0x1, LTQ_EBU_ADDRSEL1);
ltq_ebu_w32(LTQ_EBU_BUSCON | LTQ_EBU_WP, LTQ_EBU_BUSCON1);
ret = gpiochip_add(&ltq_ebu_chip);
if (!ret)
ltq_ebu_apply();
return ret;
}
static int __init ltq_ebu_init(void)
{
int ret = platform_driver_register(&ltq_ebu_driver);
if (ret)
pr_info("ltq_ebu : Error registering platfom driver!");
return ret;
}
