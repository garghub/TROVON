static u32 men_z125_lookup_uartclk(struct mcb_device *mdev)
{
u32 clkval = 1041666;
dev_info(&mdev->dev, "%s on board %s\n",
dev_name(&mdev->dev),
mdev->bus->name);
if (strncmp(mdev->bus->name, "F075", 4) == 0)
clkval = 1041666;
else if (strncmp(mdev->bus->name, "F216", 4) == 0)
clkval = 1843200;
else if (strncmp(mdev->bus->name, "G215", 4) == 0)
clkval = 1843200;
else
dev_info(&mdev->dev,
"board not detected, using default uartclk\n");
clkval = clkval << 4;
return clkval;
}
static int serial_8250_men_mcb_probe(struct mcb_device *mdev,
const struct mcb_device_id *id)
{
struct serial_8250_men_mcb_data *data;
struct resource *mem;
data = devm_kzalloc(&mdev->dev,
sizeof(struct serial_8250_men_mcb_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
mcb_set_drvdata(mdev, data);
data->uart.port.dev = mdev->dma_dev;
spin_lock_init(&data->uart.port.lock);
data->uart.port.type = PORT_16550;
data->uart.port.flags = UPF_SKIP_TEST | UPF_SHARE_IRQ | UPF_FIXED_TYPE;
data->uart.port.iotype = UPIO_MEM;
data->uart.port.uartclk = men_z125_lookup_uartclk(mdev);
data->uart.port.regshift = 0;
data->uart.port.fifosize = 60;
mem = mcb_get_resource(mdev, IORESOURCE_MEM);
if (mem == NULL)
return -ENXIO;
data->uart.port.irq = mcb_get_irq(mdev);
data->uart.port.membase = devm_ioremap_resource(&mdev->dev, mem);
if (IS_ERR(data->uart.port.membase))
return PTR_ERR_OR_ZERO(data->uart.port.membase);
data->uart.port.mapbase = (unsigned long) mem->start;
data->uart.port.iobase = data->uart.port.mapbase;
data->line = serial8250_register_8250_port(&data->uart);
if (data->line < 0)
return data->line;
dev_info(&mdev->dev, "found 16Z125 UART: ttyS%d\n", data->line);
return 0;
}
static void serial_8250_men_mcb_remove(struct mcb_device *mdev)
{
struct serial_8250_men_mcb_data *data = mcb_get_drvdata(mdev);
if (data)
serial8250_unregister_port(data->line);
}
