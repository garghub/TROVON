static void aspeed_i2c_ic_irq_handler(struct irq_desc *desc)
{
struct aspeed_i2c_ic *i2c_ic = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned long bit, status;
unsigned int bus_irq;
chained_irq_enter(chip, desc);
status = readl(i2c_ic->base);
for_each_set_bit(bit, &status, ASPEED_I2C_IC_NUM_BUS) {
bus_irq = irq_find_mapping(i2c_ic->irq_domain, bit);
generic_handle_irq(bus_irq);
}
chained_irq_exit(chip, desc);
}
static int aspeed_i2c_ic_map_irq_domain(struct irq_domain *domain,
unsigned int irq, irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &dummy_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
return 0;
}
static int __init aspeed_i2c_ic_of_init(struct device_node *node,
struct device_node *parent)
{
struct aspeed_i2c_ic *i2c_ic;
int ret = 0;
i2c_ic = kzalloc(sizeof(*i2c_ic), GFP_KERNEL);
if (!i2c_ic)
return -ENOMEM;
i2c_ic->base = of_iomap(node, 0);
if (IS_ERR(i2c_ic->base)) {
ret = PTR_ERR(i2c_ic->base);
goto err_free_ic;
}
i2c_ic->parent_irq = irq_of_parse_and_map(node, 0);
if (i2c_ic->parent_irq < 0) {
ret = i2c_ic->parent_irq;
goto err_iounmap;
}
i2c_ic->irq_domain = irq_domain_add_linear(node, ASPEED_I2C_IC_NUM_BUS,
&aspeed_i2c_ic_irq_domain_ops,
NULL);
if (!i2c_ic->irq_domain) {
ret = -ENOMEM;
goto err_iounmap;
}
i2c_ic->irq_domain->name = "aspeed-i2c-domain";
irq_set_chained_handler_and_data(i2c_ic->parent_irq,
aspeed_i2c_ic_irq_handler, i2c_ic);
pr_info("i2c controller registered, irq %d\n", i2c_ic->parent_irq);
return 0;
err_iounmap:
iounmap(i2c_ic->base);
err_free_ic:
kfree(i2c_ic);
return ret;
}
