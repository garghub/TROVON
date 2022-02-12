void neponset_ncr_frob(unsigned int mask, unsigned int val)
{
void __iomem *base = nep_base;
if (base) {
unsigned long flags;
unsigned v;
local_irq_save(flags);
v = readb_relaxed(base + NCR_0);
writeb_relaxed((v & ~mask) | val, base + NCR_0);
local_irq_restore(flags);
} else {
WARN(1, "nep_base unset\n");
}
}
static void neponset_set_mctrl(struct uart_port *port, u_int mctrl)
{
void __iomem *base = nep_base;
u_int mdm_ctl0;
if (!base)
return;
mdm_ctl0 = readb_relaxed(base + MDM_CTL_0);
if (port->mapbase == _Ser1UTCR0) {
if (mctrl & TIOCM_RTS)
mdm_ctl0 &= ~MDM_CTL0_RTS2;
else
mdm_ctl0 |= MDM_CTL0_RTS2;
if (mctrl & TIOCM_DTR)
mdm_ctl0 &= ~MDM_CTL0_DTR2;
else
mdm_ctl0 |= MDM_CTL0_DTR2;
} else if (port->mapbase == _Ser3UTCR0) {
if (mctrl & TIOCM_RTS)
mdm_ctl0 &= ~MDM_CTL0_RTS1;
else
mdm_ctl0 |= MDM_CTL0_RTS1;
if (mctrl & TIOCM_DTR)
mdm_ctl0 &= ~MDM_CTL0_DTR1;
else
mdm_ctl0 |= MDM_CTL0_DTR1;
}
writeb_relaxed(mdm_ctl0, base + MDM_CTL_0);
}
static u_int neponset_get_mctrl(struct uart_port *port)
{
void __iomem *base = nep_base;
u_int ret = TIOCM_CD | TIOCM_CTS | TIOCM_DSR;
u_int mdm_ctl1;
if (!base)
return ret;
mdm_ctl1 = readb_relaxed(base + MDM_CTL_1);
if (port->mapbase == _Ser1UTCR0) {
if (mdm_ctl1 & MDM_CTL1_DCD2)
ret &= ~TIOCM_CD;
if (mdm_ctl1 & MDM_CTL1_CTS2)
ret &= ~TIOCM_CTS;
if (mdm_ctl1 & MDM_CTL1_DSR2)
ret &= ~TIOCM_DSR;
} else if (port->mapbase == _Ser3UTCR0) {
if (mdm_ctl1 & MDM_CTL1_DCD1)
ret &= ~TIOCM_CD;
if (mdm_ctl1 & MDM_CTL1_CTS1)
ret &= ~TIOCM_CTS;
if (mdm_ctl1 & MDM_CTL1_DSR1)
ret &= ~TIOCM_DSR;
}
return ret;
}
static void neponset_irq_handler(unsigned int irq, struct irq_desc *desc)
{
struct neponset_drvdata *d = irq_desc_get_handler_data(desc);
unsigned int irr;
while (1) {
desc->irq_data.chip->irq_ack(&desc->irq_data);
irr = readb_relaxed(d->base + IRR);
irr ^= IRR_ETHERNET | IRR_USAR;
if ((irr & (IRR_ETHERNET | IRR_USAR | IRR_SA1111)) == 0)
break;
if (irr & (IRR_ETHERNET | IRR_USAR)) {
desc->irq_data.chip->irq_mask(&desc->irq_data);
desc->irq_data.chip->irq_ack(&desc->irq_data);
if (irr & IRR_ETHERNET)
generic_handle_irq(d->irq_base + NEP_IRQ_SMC91X);
if (irr & IRR_USAR)
generic_handle_irq(d->irq_base + NEP_IRQ_USAR);
desc->irq_data.chip->irq_unmask(&desc->irq_data);
}
if (irr & IRR_SA1111)
generic_handle_irq(d->irq_base + NEP_IRQ_SA1111);
}
}
static void nochip_noop(struct irq_data *irq)
{
}
static int neponset_probe(struct platform_device *dev)
{
struct neponset_drvdata *d;
struct resource *nep_res, *sa1111_res, *smc91x_res;
struct resource sa1111_resources[] = {
DEFINE_RES_MEM(0x40000000, SZ_8K),
{ .flags = IORESOURCE_IRQ },
};
struct platform_device_info sa1111_devinfo = {
.parent = &dev->dev,
.name = "sa1111",
.id = 0,
.res = sa1111_resources,
.num_res = ARRAY_SIZE(sa1111_resources),
.data = &sa1111_info,
.size_data = sizeof(sa1111_info),
.dma_mask = 0xffffffffUL,
};
struct resource smc91x_resources[] = {
DEFINE_RES_MEM_NAMED(SA1100_CS3_PHYS,
0x02000000, "smc91x-regs"),
DEFINE_RES_MEM_NAMED(SA1100_CS3_PHYS + 0x02000000,
0x02000000, "smc91x-attrib"),
{ .flags = IORESOURCE_IRQ },
};
struct smc91x_platdata smc91x_platdata = {
.flags = SMC91X_USE_8BIT | SMC91X_IO_SHIFT_2 | SMC91X_NOWAIT,
};
struct platform_device_info smc91x_devinfo = {
.parent = &dev->dev,
.name = "smc91x",
.id = 0,
.res = smc91x_resources,
.num_res = ARRAY_SIZE(smc91x_resources),
.data = &smc91x_platdata,
.size_data = sizeof(smc91x_platdata),
};
int ret, irq;
if (nep_base)
return -EBUSY;
irq = ret = platform_get_irq(dev, 0);
if (ret < 0)
goto err_alloc;
nep_res = platform_get_resource(dev, IORESOURCE_MEM, 0);
smc91x_res = platform_get_resource(dev, IORESOURCE_MEM, 1);
sa1111_res = platform_get_resource(dev, IORESOURCE_MEM, 2);
if (!nep_res || !smc91x_res || !sa1111_res) {
ret = -ENXIO;
goto err_alloc;
}
d = kzalloc(sizeof(*d), GFP_KERNEL);
if (!d) {
ret = -ENOMEM;
goto err_alloc;
}
d->base = ioremap(nep_res->start, SZ_4K);
if (!d->base) {
ret = -ENOMEM;
goto err_ioremap;
}
if (readb_relaxed(d->base + WHOAMI) != 0x11) {
dev_warn(&dev->dev, "Neponset board detected, but wrong ID: %02x\n",
readb_relaxed(d->base + WHOAMI));
ret = -ENODEV;
goto err_id;
}
ret = irq_alloc_descs(-1, IRQ_BOARD_START, NEP_IRQ_NR, -1);
if (ret <= 0) {
dev_err(&dev->dev, "unable to allocate %u irqs: %d\n",
NEP_IRQ_NR, ret);
if (ret == 0)
ret = -ENOMEM;
goto err_irq_alloc;
}
d->irq_base = ret;
irq_set_chip_and_handler(d->irq_base + NEP_IRQ_SMC91X, &nochip,
handle_simple_irq);
set_irq_flags(d->irq_base + NEP_IRQ_SMC91X, IRQF_VALID | IRQF_PROBE);
irq_set_chip_and_handler(d->irq_base + NEP_IRQ_USAR, &nochip,
handle_simple_irq);
set_irq_flags(d->irq_base + NEP_IRQ_USAR, IRQF_VALID | IRQF_PROBE);
irq_set_chip(d->irq_base + NEP_IRQ_SA1111, &nochip);
irq_set_irq_type(irq, IRQ_TYPE_EDGE_RISING);
irq_set_chained_handler_and_data(irq, neponset_irq_handler, d);
#if 0
enable_irq_wake(irq);
#endif
dev_info(&dev->dev, "Neponset daughter board, providing IRQ%u-%u\n",
d->irq_base, d->irq_base + NEP_IRQ_NR - 1);
nep_base = d->base;
sa1100_register_uart_fns(&neponset_port_fns);
sa1110_mb_disable();
writeb_relaxed(NCR_GP01_OFF, d->base + NCR_0);
sa1111_resources[0].parent = sa1111_res;
sa1111_resources[1].start = d->irq_base + NEP_IRQ_SA1111;
sa1111_resources[1].end = d->irq_base + NEP_IRQ_SA1111;
d->sa1111 = platform_device_register_full(&sa1111_devinfo);
smc91x_resources[0].parent = smc91x_res;
smc91x_resources[1].parent = smc91x_res;
smc91x_resources[2].start = d->irq_base + NEP_IRQ_SMC91X;
smc91x_resources[2].end = d->irq_base + NEP_IRQ_SMC91X;
d->smc91x = platform_device_register_full(&smc91x_devinfo);
platform_set_drvdata(dev, d);
return 0;
err_irq_alloc:
err_id:
iounmap(d->base);
err_ioremap:
kfree(d);
err_alloc:
return ret;
}
static int neponset_remove(struct platform_device *dev)
{
struct neponset_drvdata *d = platform_get_drvdata(dev);
int irq = platform_get_irq(dev, 0);
if (!IS_ERR(d->sa1111))
platform_device_unregister(d->sa1111);
if (!IS_ERR(d->smc91x))
platform_device_unregister(d->smc91x);
irq_set_chained_handler(irq, NULL);
irq_free_descs(d->irq_base, NEP_IRQ_NR);
nep_base = NULL;
iounmap(d->base);
kfree(d);
return 0;
}
static int neponset_suspend(struct device *dev)
{
struct neponset_drvdata *d = dev_get_drvdata(dev);
d->ncr0 = readb_relaxed(d->base + NCR_0);
d->mdm_ctl_0 = readb_relaxed(d->base + MDM_CTL_0);
return 0;
}
static int neponset_resume(struct device *dev)
{
struct neponset_drvdata *d = dev_get_drvdata(dev);
writeb_relaxed(d->ncr0, d->base + NCR_0);
writeb_relaxed(d->mdm_ctl_0, d->base + MDM_CTL_0);
return 0;
}
static int __init neponset_init(void)
{
return platform_driver_register(&neponset_device_driver);
}
