static inline u32 pcmcia_readl(struct bcm63xx_pcmcia_socket *skt, u32 off)
{
return bcm_readl(skt->base + off);
}
static inline void pcmcia_writel(struct bcm63xx_pcmcia_socket *skt,
u32 val, u32 off)
{
bcm_writel(val, skt->base + off);
}
static int bcm63xx_pcmcia_sock_init(struct pcmcia_socket *sock)
{
return 0;
}
static int bcm63xx_pcmcia_suspend(struct pcmcia_socket *sock)
{
return 0;
}
static int bcm63xx_pcmcia_set_socket(struct pcmcia_socket *sock,
socket_state_t *state)
{
struct bcm63xx_pcmcia_socket *skt;
unsigned long flags;
u32 val;
skt = sock->driver_data;
spin_lock_irqsave(&skt->lock, flags);
val = pcmcia_readl(skt, PCMCIA_C1_REG);
if (state->flags & SS_RESET)
val |= PCMCIA_C1_RESET_MASK;
else
val &= ~PCMCIA_C1_RESET_MASK;
if (skt->card_detected && (skt->card_type & CARD_CARDBUS))
val ^= PCMCIA_C1_RESET_MASK;
pcmcia_writel(skt, val, PCMCIA_C1_REG);
skt->requested_state = *state;
spin_unlock_irqrestore(&skt->lock, flags);
return 0;
}
static unsigned int __get_socket_status(struct bcm63xx_pcmcia_socket *skt)
{
unsigned int stat;
u32 val;
stat = 0;
val = pcmcia_readl(skt, PCMCIA_C1_REG);
if (!(val & PCMCIA_C1_CD1_MASK) && !(val & PCMCIA_C1_CD2_MASK))
stat |= SS_DETECT;
if ((stat & SS_DETECT) && !skt->card_detected) {
unsigned int stat = 0;
val |= PCMCIA_C1_VS1OE_MASK;
val |= PCMCIA_C1_VS2OE_MASK;
pcmcia_writel(skt, val, PCMCIA_C1_REG);
udelay(10);
val = pcmcia_readl(skt, PCMCIA_C1_REG);
stat |= (val & PCMCIA_C1_VS1_MASK) ? IN_VS1 : 0;
stat |= (val & PCMCIA_C1_VS2_MASK) ? IN_VS2 : 0;
val &= ~PCMCIA_C1_VS1OE_MASK;
val |= PCMCIA_C1_VS2OE_MASK;
pcmcia_writel(skt, val, PCMCIA_C1_REG);
udelay(10);
val = pcmcia_readl(skt, PCMCIA_C1_REG);
stat |= (val & PCMCIA_C1_CD1_MASK) ? IN_CD1_VS2H : 0;
stat |= (val & PCMCIA_C1_CD2_MASK) ? IN_CD2_VS2H : 0;
val |= PCMCIA_C1_VS1OE_MASK;
val &= ~PCMCIA_C1_VS2OE_MASK;
pcmcia_writel(skt, val, PCMCIA_C1_REG);
udelay(10);
val = pcmcia_readl(skt, PCMCIA_C1_REG);
stat |= (val & PCMCIA_C1_CD1_MASK) ? IN_CD1_VS1H : 0;
stat |= (val & PCMCIA_C1_CD2_MASK) ? IN_CD2_VS1H : 0;
skt->card_type = vscd_to_cardtype[stat];
if (!skt->card_type)
dev_err(&skt->socket.dev, "unsupported card type\n");
val &= ~(PCMCIA_C1_VS1OE_MASK | PCMCIA_C1_VS2OE_MASK);
val &= ~(PCMCIA_C1_EN_PCMCIA_MASK | PCMCIA_C1_EN_CARDBUS_MASK);
if (skt->card_type & CARD_PCCARD)
val |= PCMCIA_C1_EN_PCMCIA_MASK;
else
val |= PCMCIA_C1_EN_CARDBUS_MASK;
pcmcia_writel(skt, val, PCMCIA_C1_REG);
}
skt->card_detected = (stat & SS_DETECT) ? 1 : 0;
if (skt->card_type & CARD_CARDBUS)
stat |= SS_CARDBUS;
if (skt->card_type & CARD_3V)
stat |= SS_3VCARD;
if (skt->card_type & CARD_XV)
stat |= SS_XVCARD;
stat |= SS_POWERON;
if (gpio_get_value(skt->pd->ready_gpio))
stat |= SS_READY;
return stat;
}
static int bcm63xx_pcmcia_get_status(struct pcmcia_socket *sock,
unsigned int *status)
{
struct bcm63xx_pcmcia_socket *skt;
skt = sock->driver_data;
spin_lock_bh(&skt->lock);
*status = __get_socket_status(skt);
spin_unlock_bh(&skt->lock);
return 0;
}
static void bcm63xx_pcmcia_poll(unsigned long data)
{
struct bcm63xx_pcmcia_socket *skt;
unsigned int stat, events;
skt = (struct bcm63xx_pcmcia_socket *)data;
spin_lock_bh(&skt->lock);
stat = __get_socket_status(skt);
events = (stat ^ skt->old_status) & skt->requested_state.csc_mask;
skt->old_status = stat;
spin_unlock_bh(&skt->lock);
if (events)
pcmcia_parse_events(&skt->socket, events);
mod_timer(&skt->timer,
jiffies + msecs_to_jiffies(BCM63XX_PCMCIA_POLL_RATE));
}
static int bcm63xx_pcmcia_set_io_map(struct pcmcia_socket *sock,
struct pccard_io_map *map)
{
return 0;
}
static int bcm63xx_pcmcia_set_mem_map(struct pcmcia_socket *sock,
struct pccard_mem_map *map)
{
struct bcm63xx_pcmcia_socket *skt;
struct resource *res;
skt = sock->driver_data;
if (map->flags & MAP_ATTRIB)
res = skt->attr_res;
else
res = skt->common_res;
map->static_start = res->start + map->card_start;
return 0;
}
static int __devinit bcm63xx_drv_pcmcia_probe(struct platform_device *pdev)
{
struct bcm63xx_pcmcia_socket *skt;
struct pcmcia_socket *sock;
struct resource *res, *irq_res;
unsigned int regmem_size = 0, iomem_size = 0;
u32 val;
int ret;
skt = kzalloc(sizeof(*skt), GFP_KERNEL);
if (!skt)
return -ENOMEM;
spin_lock_init(&skt->lock);
sock = &skt->socket;
sock->driver_data = skt;
skt->common_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
skt->attr_res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
skt->pd = pdev->dev.platform_data;
if (!skt->common_res || !skt->attr_res || !irq_res || !skt->pd) {
ret = -EINVAL;
goto err;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regmem_size = resource_size(res);
if (!request_mem_region(res->start, regmem_size, "bcm63xx_pcmcia")) {
ret = -EINVAL;
goto err;
}
skt->reg_res = res;
skt->base = ioremap(res->start, regmem_size);
if (!skt->base) {
ret = -ENOMEM;
goto err;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 3);
iomem_size = resource_size(res);
skt->io_base = ioremap(res->start, iomem_size);
if (!skt->io_base) {
ret = -ENOMEM;
goto err;
}
sock->resource_ops = &pccard_static_ops;
sock->ops = &bcm63xx_pcmcia_operations;
sock->owner = THIS_MODULE;
sock->dev.parent = &pdev->dev;
sock->features = SS_CAP_STATIC_MAP | SS_CAP_PCCARD;
sock->io_offset = (unsigned long)skt->io_base;
sock->pci_irq = irq_res->start;
#ifdef CONFIG_CARDBUS
sock->cb_dev = bcm63xx_cb_dev;
if (bcm63xx_cb_dev)
sock->features |= SS_CAP_CARDBUS;
#endif
sock->map_size = resource_size(skt->common_res);
setup_timer(&skt->timer, bcm63xx_pcmcia_poll, (unsigned long)skt);
val = pcmcia_readl(skt, PCMCIA_C1_REG);
val &= PCMCIA_C1_CBIDSEL_MASK;
val |= PCMCIA_C1_EN_PCMCIA_GPIO_MASK;
pcmcia_writel(skt, val, PCMCIA_C1_REG);
val = PCMCIA_C2_DATA16_MASK;
val |= 10 << PCMCIA_C2_RWCOUNT_SHIFT;
val |= 6 << PCMCIA_C2_INACTIVE_SHIFT;
val |= 3 << PCMCIA_C2_SETUP_SHIFT;
val |= 3 << PCMCIA_C2_HOLD_SHIFT;
pcmcia_writel(skt, val, PCMCIA_C2_REG);
ret = pcmcia_register_socket(sock);
if (ret)
goto err;
mod_timer(&skt->timer,
jiffies + msecs_to_jiffies(BCM63XX_PCMCIA_POLL_RATE));
platform_set_drvdata(pdev, skt);
return 0;
err:
if (skt->io_base)
iounmap(skt->io_base);
if (skt->base)
iounmap(skt->base);
if (skt->reg_res)
release_mem_region(skt->reg_res->start, regmem_size);
kfree(skt);
return ret;
}
static int __devexit bcm63xx_drv_pcmcia_remove(struct platform_device *pdev)
{
struct bcm63xx_pcmcia_socket *skt;
struct resource *res;
skt = platform_get_drvdata(pdev);
del_timer_sync(&skt->timer);
iounmap(skt->base);
iounmap(skt->io_base);
res = skt->reg_res;
release_mem_region(res->start, resource_size(res));
kfree(skt);
return 0;
}
static int __devinit bcm63xx_cb_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
bcm63xx_cb_dev = dev;
return platform_driver_register(&bcm63xx_pcmcia_driver);
}
static void __devexit bcm63xx_cb_exit(struct pci_dev *dev)
{
platform_driver_unregister(&bcm63xx_pcmcia_driver);
bcm63xx_cb_dev = NULL;
}
static int __init bcm63xx_pcmcia_init(void)
{
#ifdef CONFIG_CARDBUS
return pci_register_driver(&bcm63xx_cardbus_driver);
#else
return platform_driver_register(&bcm63xx_pcmcia_driver);
#endif
}
static void __exit bcm63xx_pcmcia_exit(void)
{
#ifdef CONFIG_CARDBUS
return pci_unregister_driver(&bcm63xx_cardbus_driver);
#else
platform_driver_unregister(&bcm63xx_pcmcia_driver);
#endif
}
