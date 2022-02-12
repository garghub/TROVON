unsigned int *ltq_get_cp1_base(void)
{
if (!cp1_base)
panic("no cp1 base was set\n");
return cp1_base;
}
static int vmmc_probe(struct platform_device *pdev)
{
#define CP1_SIZE (1 << 20)
int gpio_count;
dma_addr_t dma;
cp1_base =
(void *) CPHYSADDR(dma_alloc_coherent(NULL, CP1_SIZE,
&dma, GFP_ATOMIC));
gpio_count = of_gpio_count(pdev->dev.of_node);
while (gpio_count > 0) {
enum of_gpio_flags flags;
int gpio = of_get_gpio_flags(pdev->dev.of_node,
--gpio_count, &flags);
if (gpio_request(gpio, "vmmc-relay"))
continue;
dev_info(&pdev->dev, "requested GPIO %d\n", gpio);
gpio_direction_output(gpio,
(flags & OF_GPIO_ACTIVE_LOW) ? (0) : (1));
}
dev_info(&pdev->dev, "reserved %dMB at 0x%p", CP1_SIZE >> 20, cp1_base);
return 0;
}
