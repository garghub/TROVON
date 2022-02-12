struct platform_device *__init mxs_add_gpio(
char *name, int id, resource_size_t iobase, int irq)
{
struct resource res[] = {
{
.start = iobase,
.end = iobase + SZ_8K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = irq,
.end = irq,
.flags = IORESOURCE_IRQ,
},
};
return platform_device_register_resndata(&mxs_apbh_bus,
name, id, res, ARRAY_SIZE(res), NULL, 0);
}
