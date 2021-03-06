static irqreturn_t cdirq(int irq, void *data)
{
struct xxs1500_pcmcia_sock *sock = data;
pcmcia_parse_events(&sock->socket, SS_DETECT);
return IRQ_HANDLED;
}
static int xxs1500_pcmcia_configure(struct pcmcia_socket *skt,
struct socket_state_t *state)
{
struct xxs1500_pcmcia_sock *sock = to_xxs_socket(skt);
unsigned int changed;
switch (state->Vcc) {
case 0:
gpio_set_value(GPIO_POWER, 1);
break;
case 33:
gpio_set_value(GPIO_POWER, 0);
break;
case 50:
default:
return -EINVAL;
}
changed = state->flags ^ sock->old_flags;
if (changed & SS_RESET) {
if (state->flags & SS_RESET) {
gpio_set_value(GPIO_RESET, 1);
gpio_set_value(GPIO_OUTEN, 1);
} else {
gpio_set_value(GPIO_RESET, 0);
gpio_set_value(GPIO_OUTEN, 0);
msleep(500);
}
}
sock->old_flags = state->flags;
return 0;
}
static int xxs1500_pcmcia_get_status(struct pcmcia_socket *skt,
unsigned int *value)
{
unsigned int status;
int i;
status = 0;
if (!gpio_get_value(GPIO_CDA) && !gpio_get_value(GPIO_CDB))
status |= SS_DETECT;
i = (!!gpio_get_value(GPIO_VSL)) | ((!!gpio_get_value(GPIO_VSH)) << 1);
switch (i) {
case 0:
case 1:
case 2:
status |= SS_3VCARD;
break;
case 3:
default:
status |= SS_XVCARD;
}
status |= gpio_get_value(GPIO_POWER) ? 0 : SS_POWERON;
status |= gpio_get_value(GPIO_RESET) ? SS_RESET : SS_READY;
status |= gpio_get_value(GPIO_BATTDEAD) ? 0 : SS_BATDEAD;
status |= gpio_get_value(GPIO_BATTWARN) ? 0 : SS_BATWARN;
*value = status;
return 0;
}
static int xxs1500_pcmcia_sock_init(struct pcmcia_socket *skt)
{
gpio_direction_input(GPIO_CDA);
gpio_direction_input(GPIO_CDB);
gpio_direction_input(GPIO_VSL);
gpio_direction_input(GPIO_VSH);
gpio_direction_input(GPIO_BATTDEAD);
gpio_direction_input(GPIO_BATTWARN);
gpio_direction_output(GPIO_RESET, 1);
gpio_direction_output(GPIO_OUTEN, 1);
gpio_direction_output(GPIO_POWER, 1);
return 0;
}
static int xxs1500_pcmcia_sock_suspend(struct pcmcia_socket *skt)
{
return 0;
}
static int au1x00_pcmcia_set_io_map(struct pcmcia_socket *skt,
struct pccard_io_map *map)
{
struct xxs1500_pcmcia_sock *sock = to_xxs_socket(skt);
map->start = (u32)sock->virt_io;
map->stop = map->start + IO_MAP_SIZE;
return 0;
}
static int au1x00_pcmcia_set_mem_map(struct pcmcia_socket *skt,
struct pccard_mem_map *map)
{
struct xxs1500_pcmcia_sock *sock = to_xxs_socket(skt);
if (map->flags & MAP_ATTRIB)
map->static_start = sock->phys_attr + map->card_start;
else
map->static_start = sock->phys_mem + map->card_start;
return 0;
}
static int __devinit xxs1500_pcmcia_probe(struct platform_device *pdev)
{
struct xxs1500_pcmcia_sock *sock;
struct resource *r;
int ret, irq;
sock = kzalloc(sizeof(struct xxs1500_pcmcia_sock), GFP_KERNEL);
if (!sock)
return -ENOMEM;
ret = -ENODEV;
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, "pcmcia-attr");
if (!r) {
dev_err(&pdev->dev, "missing 'pcmcia-attr' resource!\n");
goto out0;
}
sock->phys_attr = r->start;
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, "pcmcia-mem");
if (!r) {
dev_err(&pdev->dev, "missing 'pcmcia-mem' resource!\n");
goto out0;
}
sock->phys_mem = r->start;
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, "pcmcia-io");
if (!r) {
dev_err(&pdev->dev, "missing 'pcmcia-io' resource!\n");
goto out0;
}
sock->phys_io = r->start;
sock->virt_io = (void *)(ioremap(sock->phys_io, IO_MAP_SIZE) -
mips_io_port_base);
if (!sock->virt_io) {
dev_err(&pdev->dev, "cannot remap IO area\n");
ret = -ENOMEM;
goto out0;
}
sock->socket.ops = &xxs1500_pcmcia_operations;
sock->socket.owner = THIS_MODULE;
sock->socket.pci_irq = gpio_to_irq(GPIO_CARDIRQ);
sock->socket.features = SS_CAP_STATIC_MAP | SS_CAP_PCCARD;
sock->socket.map_size = MEM_MAP_SIZE;
sock->socket.io_offset = (unsigned long)sock->virt_io;
sock->socket.dev.parent = &pdev->dev;
sock->socket.resource_ops = &pccard_static_ops;
platform_set_drvdata(pdev, sock);
irq = gpio_to_irq(GPIO_CDA);
irq_set_irq_type(irq, IRQ_TYPE_EDGE_BOTH);
ret = request_irq(irq, cdirq, 0, "pcmcia_carddetect", sock);
if (ret) {
dev_err(&pdev->dev, "cannot setup cd irq\n");
goto out1;
}
ret = pcmcia_register_socket(&sock->socket);
if (ret) {
dev_err(&pdev->dev, "failed to register\n");
goto out2;
}
printk(KERN_INFO "MyCable XXS1500 PCMCIA socket services\n");
return 0;
out2:
free_irq(gpio_to_irq(GPIO_CDA), sock);
out1:
iounmap((void *)(sock->virt_io + (u32)mips_io_port_base));
out0:
kfree(sock);
return ret;
}
static int __devexit xxs1500_pcmcia_remove(struct platform_device *pdev)
{
struct xxs1500_pcmcia_sock *sock = platform_get_drvdata(pdev);
pcmcia_unregister_socket(&sock->socket);
free_irq(gpio_to_irq(GPIO_CDA), sock);
iounmap((void *)(sock->virt_io + (u32)mips_io_port_base));
kfree(sock);
return 0;
}
int __init xxs1500_pcmcia_socket_load(void)
{
return platform_driver_register(&xxs1500_pcmcia_socket_driver);
}
void __exit xxs1500_pcmcia_socket_unload(void)
{
platform_driver_unregister(&xxs1500_pcmcia_socket_driver);
}
