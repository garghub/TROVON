struct platform_device *__init imx_add_imx_udc(
const struct imx_imx_udc_data *data,
const struct imxusb_platform_data *pdata)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + data->iosize - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irq0,
.end = data->irq0,
.flags = IORESOURCE_IRQ,
}, {
.start = data->irq1,
.end = data->irq1,
.flags = IORESOURCE_IRQ,
}, {
.start = data->irq2,
.end = data->irq2,
.flags = IORESOURCE_IRQ,
}, {
.start = data->irq3,
.end = data->irq3,
.flags = IORESOURCE_IRQ,
}, {
.start = data->irq4,
.end = data->irq4,
.flags = IORESOURCE_IRQ,
}, {
.start = data->irq5,
.end = data->irq5,
.flags = IORESOURCE_IRQ,
}, {
.start = data->irq6,
.end = data->irq6,
.flags = IORESOURCE_IRQ,
},
};
return imx_add_platform_device("imx_udc", 0,
res, ARRAY_SIZE(res), pdata, sizeof(*pdata));
}
