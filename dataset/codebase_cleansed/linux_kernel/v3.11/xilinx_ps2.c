static int xps2_recv(struct xps2data *drvdata, u8 *byte)
{
u32 sr;
int status = -1;
sr = in_be32(drvdata->base_address + XPS2_STATUS_OFFSET);
if (sr & XPS2_STATUS_RX_FULL) {
*byte = in_be32(drvdata->base_address + XPS2_RX_DATA_OFFSET);
status = 0;
}
return status;
}
static irqreturn_t xps2_interrupt(int irq, void *dev_id)
{
struct xps2data *drvdata = dev_id;
u32 intr_sr;
u8 c;
int status;
intr_sr = in_be32(drvdata->base_address + XPS2_IPISR_OFFSET);
out_be32(drvdata->base_address + XPS2_IPISR_OFFSET, intr_sr);
if (intr_sr & XPS2_IPIXR_RX_OVF)
dev_warn(drvdata->dev, "receive overrun error\n");
if (intr_sr & XPS2_IPIXR_RX_ERR)
drvdata->flags |= SERIO_PARITY;
if (intr_sr & (XPS2_IPIXR_TX_NOACK | XPS2_IPIXR_WDT_TOUT))
drvdata->flags |= SERIO_TIMEOUT;
if (intr_sr & XPS2_IPIXR_RX_FULL) {
status = xps2_recv(drvdata, &c);
if (status) {
dev_err(drvdata->dev,
"wrong rcvd byte count (%d)\n", status);
} else {
serio_interrupt(drvdata->serio, c, drvdata->flags);
drvdata->flags = 0;
}
}
return IRQ_HANDLED;
}
static int sxps2_write(struct serio *pserio, unsigned char c)
{
struct xps2data *drvdata = pserio->port_data;
unsigned long flags;
u32 sr;
int status = -1;
spin_lock_irqsave(&drvdata->lock, flags);
sr = in_be32(drvdata->base_address + XPS2_STATUS_OFFSET);
if (!(sr & XPS2_STATUS_TX_FULL)) {
out_be32(drvdata->base_address + XPS2_TX_DATA_OFFSET, c);
status = 0;
}
spin_unlock_irqrestore(&drvdata->lock, flags);
return status;
}
static int sxps2_open(struct serio *pserio)
{
struct xps2data *drvdata = pserio->port_data;
int error;
u8 c;
error = request_irq(drvdata->irq, &xps2_interrupt, 0,
DRIVER_NAME, drvdata);
if (error) {
dev_err(drvdata->dev,
"Couldn't allocate interrupt %d\n", drvdata->irq);
return error;
}
out_be32(drvdata->base_address + XPS2_GIER_OFFSET, XPS2_GIER_GIE_MASK);
out_be32(drvdata->base_address + XPS2_IPIER_OFFSET, XPS2_IPIXR_RX_ALL);
(void)xps2_recv(drvdata, &c);
return 0;
}
static void sxps2_close(struct serio *pserio)
{
struct xps2data *drvdata = pserio->port_data;
out_be32(drvdata->base_address + XPS2_GIER_OFFSET, 0x00);
out_be32(drvdata->base_address + XPS2_IPIER_OFFSET, 0x00);
free_irq(drvdata->irq, drvdata);
}
static int xps2_of_probe(struct platform_device *ofdev)
{
struct resource r_irq;
struct resource r_mem;
struct xps2data *drvdata;
struct serio *serio;
struct device *dev = &ofdev->dev;
resource_size_t remap_size, phys_addr;
int error;
dev_info(dev, "Device Tree Probing \'%s\'\n",
ofdev->dev.of_node->name);
error = of_address_to_resource(ofdev->dev.of_node, 0, &r_mem);
if (error) {
dev_err(dev, "invalid address\n");
return error;
}
if (!of_irq_to_resource(ofdev->dev.of_node, 0, &r_irq)) {
dev_err(dev, "no IRQ found\n");
return -ENODEV;
}
drvdata = kzalloc(sizeof(struct xps2data), GFP_KERNEL);
serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!drvdata || !serio) {
error = -ENOMEM;
goto failed1;
}
spin_lock_init(&drvdata->lock);
drvdata->irq = r_irq.start;
drvdata->serio = serio;
drvdata->dev = dev;
phys_addr = r_mem.start;
remap_size = resource_size(&r_mem);
if (!request_mem_region(phys_addr, remap_size, DRIVER_NAME)) {
dev_err(dev, "Couldn't lock memory region at 0x%08llX\n",
(unsigned long long)phys_addr);
error = -EBUSY;
goto failed1;
}
drvdata->base_address = ioremap(phys_addr, remap_size);
if (drvdata->base_address == NULL) {
dev_err(dev, "Couldn't ioremap memory at 0x%08llX\n",
(unsigned long long)phys_addr);
error = -EFAULT;
goto failed2;
}
out_be32(drvdata->base_address + XPS2_IPIER_OFFSET, 0);
out_be32(drvdata->base_address + XPS2_SRST_OFFSET, XPS2_SRST_RESET);
dev_info(dev, "Xilinx PS2 at 0x%08llX mapped to 0x%p, irq=%d\n",
(unsigned long long)phys_addr, drvdata->base_address,
drvdata->irq);
serio->id.type = SERIO_8042;
serio->write = sxps2_write;
serio->open = sxps2_open;
serio->close = sxps2_close;
serio->port_data = drvdata;
serio->dev.parent = dev;
snprintf(serio->name, sizeof(serio->name),
"Xilinx XPS PS/2 at %08llX", (unsigned long long)phys_addr);
snprintf(serio->phys, sizeof(serio->phys),
"xilinxps2/serio at %08llX", (unsigned long long)phys_addr);
serio_register_port(serio);
platform_set_drvdata(ofdev, drvdata);
return 0;
failed2:
release_mem_region(phys_addr, remap_size);
failed1:
kfree(serio);
kfree(drvdata);
return error;
}
static int xps2_of_remove(struct platform_device *of_dev)
{
struct xps2data *drvdata = platform_get_drvdata(of_dev);
struct resource r_mem;
serio_unregister_port(drvdata->serio);
iounmap(drvdata->base_address);
if (of_address_to_resource(of_dev->dev.of_node, 0, &r_mem))
dev_err(drvdata->dev, "invalid address\n");
else
release_mem_region(r_mem.start, resource_size(&r_mem));
kfree(drvdata);
return 0;
}
