struct platform_device *__init imx_add_imx_uart_1irq(
const struct imx_imx_uart_1irq_data *data,
const struct imxuart_platform_data *pdata)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + data->iosize - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irq,
.end = data->irq,
.flags = IORESOURCE_IRQ,
},
};
return imx_add_platform_device("imx21-uart", data->id,
res, ARRAY_SIZE(res), pdata, sizeof(*pdata));
}
