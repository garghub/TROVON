struct platform_device *__init imx_add_imx_keypad(
const struct imx_imx_keypad_data *data,
const struct matrix_keymap_data *pdata)
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
return imx_add_platform_device("imx-keypad", -1,
res, ARRAY_SIZE(res), pdata, sizeof(*pdata));
}
