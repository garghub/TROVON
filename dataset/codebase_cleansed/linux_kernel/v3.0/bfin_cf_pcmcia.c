static int bfin_cf_reset(void)
{
outw(0, CF_ATASEL_ENA);
mdelay(200);
outw(0, CF_ATASEL_DIS);
return 0;
}
static int bfin_cf_ss_init(struct pcmcia_socket *s)
{
return 0;
}
static void bfin_cf_timer(unsigned long _cf)
{
struct bfin_cf_socket *cf = (void *)_cf;
unsigned short present = bfin_cf_present(cf->cd_pfx);
if (present != cf->present) {
cf->present = present;
dev_dbg(&cf->pdev->dev, ": card %s\n",
present ? "present" : "gone");
pcmcia_parse_events(&cf->socket, SS_DETECT);
}
if (cf->active)
mod_timer(&cf->timer, jiffies + POLL_INTERVAL);
}
static int bfin_cf_get_status(struct pcmcia_socket *s, u_int *sp)
{
struct bfin_cf_socket *cf;
if (!sp)
return -EINVAL;
cf = container_of(s, struct bfin_cf_socket, socket);
if (bfin_cf_present(cf->cd_pfx)) {
*sp = SS_READY | SS_DETECT | SS_POWERON | SS_3VCARD;
s->pcmcia_irq = 0;
s->pci_irq = cf->irq;
} else
*sp = 0;
return 0;
}
static int
bfin_cf_set_socket(struct pcmcia_socket *sock, struct socket_state_t *s)
{
struct bfin_cf_socket *cf;
cf = container_of(sock, struct bfin_cf_socket, socket);
switch (s->Vcc) {
case 0:
case 33:
break;
case 50:
break;
default:
return -EINVAL;
}
if (s->flags & SS_RESET) {
disable_irq(cf->irq);
bfin_cf_reset();
enable_irq(cf->irq);
}
dev_dbg(&cf->pdev->dev, ": Vcc %d, io_irq %d, flags %04x csc %04x\n",
s->Vcc, s->io_irq, s->flags, s->csc_mask);
return 0;
}
static int bfin_cf_ss_suspend(struct pcmcia_socket *s)
{
return bfin_cf_set_socket(s, &dead_socket);
}
static int bfin_cf_set_io_map(struct pcmcia_socket *s, struct pccard_io_map *io)
{
struct bfin_cf_socket *cf;
cf = container_of(s, struct bfin_cf_socket, socket);
io->flags &= MAP_ACTIVE | MAP_ATTRIB | MAP_16BIT;
io->start = cf->phys_cf_io;
io->stop = io->start + SZ_2K - 1;
return 0;
}
static int
bfin_cf_set_mem_map(struct pcmcia_socket *s, struct pccard_mem_map *map)
{
struct bfin_cf_socket *cf;
if (map->card_start)
return -EINVAL;
cf = container_of(s, struct bfin_cf_socket, socket);
map->static_start = cf->phys_cf_io;
map->flags &= MAP_ACTIVE | MAP_ATTRIB | MAP_16BIT;
if (map->flags & MAP_ATTRIB)
map->static_start = cf->phys_cf_attr;
return 0;
}
static int __devinit bfin_cf_probe(struct platform_device *pdev)
{
struct bfin_cf_socket *cf;
struct resource *io_mem, *attr_mem;
int irq;
unsigned short cd_pfx;
int status = 0;
dev_info(&pdev->dev, "Blackfin CompactFlash/PCMCIA Socket Driver\n");
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return -EINVAL;
cd_pfx = platform_get_irq(pdev, 1);
if (gpio_request(cd_pfx, "pcmcia: CD")) {
dev_err(&pdev->dev,
"Failed ro request Card Detect GPIO_%d\n",
cd_pfx);
return -EBUSY;
}
gpio_direction_input(cd_pfx);
cf = kzalloc(sizeof *cf, GFP_KERNEL);
if (!cf) {
gpio_free(cd_pfx);
return -ENOMEM;
}
cf->cd_pfx = cd_pfx;
setup_timer(&cf->timer, bfin_cf_timer, (unsigned long)cf);
cf->pdev = pdev;
platform_set_drvdata(pdev, cf);
cf->irq = irq;
cf->socket.pci_irq = irq;
irq_set_irq_type(irq, IRQF_TRIGGER_LOW);
io_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
attr_mem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!io_mem || !attr_mem)
goto fail0;
cf->phys_cf_io = io_mem->start;
cf->phys_cf_attr = attr_mem->start;
cf->socket.io_offset = (unsigned long)
ioremap(cf->phys_cf_io, SZ_2K);
if (!cf->socket.io_offset)
goto fail0;
dev_err(&pdev->dev, ": on irq %d\n", irq);
dev_dbg(&pdev->dev, ": %s\n",
bfin_cf_present(cf->cd_pfx) ? "present" : "(not present)");
cf->socket.owner = THIS_MODULE;
cf->socket.dev.parent = &pdev->dev;
cf->socket.ops = &bfin_cf_ops;
cf->socket.resource_ops = &pccard_static_ops;
cf->socket.features = SS_CAP_PCCARD | SS_CAP_STATIC_MAP
| SS_CAP_MEM_ALIGN;
cf->socket.map_size = SZ_2K;
status = pcmcia_register_socket(&cf->socket);
if (status < 0)
goto fail2;
cf->active = 1;
mod_timer(&cf->timer, jiffies + POLL_INTERVAL);
return 0;
fail2:
iounmap((void __iomem *)cf->socket.io_offset);
release_mem_region(cf->phys_cf_io, SZ_8K);
fail0:
gpio_free(cf->cd_pfx);
kfree(cf);
platform_set_drvdata(pdev, NULL);
return status;
}
static int __devexit bfin_cf_remove(struct platform_device *pdev)
{
struct bfin_cf_socket *cf = platform_get_drvdata(pdev);
gpio_free(cf->cd_pfx);
cf->active = 0;
pcmcia_unregister_socket(&cf->socket);
del_timer_sync(&cf->timer);
iounmap((void __iomem *)cf->socket.io_offset);
release_mem_region(cf->phys_cf_io, SZ_8K);
platform_set_drvdata(pdev, NULL);
kfree(cf);
return 0;
}
static int __init bfin_cf_init(void)
{
return platform_driver_register(&bfin_cf_driver);
}
static void __exit bfin_cf_exit(void)
{
platform_driver_unregister(&bfin_cf_driver);
}
