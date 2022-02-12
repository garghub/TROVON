static void pata_bk3710_setudmamode(void __iomem *base, unsigned int dev,
unsigned int mode)
{
u32 val32;
u16 val16;
u8 tenv, trp, t0;
t0 = DIV_ROUND_UP(pata_bk3710_udmatimings[mode].cycletime,
ideclk_period) - 1;
tenv = DIV_ROUND_UP(20, ideclk_period) - 1;
trp = DIV_ROUND_UP(pata_bk3710_udmatimings[mode].rptime,
ideclk_period) - 1;
val32 = ioread32(base + BK3710_UDMASTB) & (0xFF << (dev ? 0 : 8));
val32 |= t0 << (dev ? 8 : 0);
iowrite32(val32, base + BK3710_UDMASTB);
val32 = ioread32(base + BK3710_UDMATRP) & (0xFF << (dev ? 0 : 8));
val32 |= trp << (dev ? 8 : 0);
iowrite32(val32, base + BK3710_UDMATRP);
val32 = ioread32(base + BK3710_UDMAENV) & (0xFF << (dev ? 0 : 8));
val32 |= tenv << (dev ? 8 : 0);
iowrite32(val32, base + BK3710_UDMAENV);
val16 = ioread16(base + BK3710_UDMACTL) | (1 << dev);
iowrite16(val16, base + BK3710_UDMACTL);
}
static void pata_bk3710_setmwdmamode(void __iomem *base, unsigned int dev,
unsigned short min_cycle,
unsigned int mode)
{
const struct ata_timing *t;
int cycletime;
u32 val32;
u16 val16;
u8 td, tkw, t0;
t = ata_timing_find_mode(mode);
cycletime = max_t(int, t->cycle, min_cycle);
t0 = DIV_ROUND_UP(cycletime, ideclk_period);
td = DIV_ROUND_UP(t->active, ideclk_period);
tkw = t0 - td - 1;
td--;
val32 = ioread32(base + BK3710_DMASTB) & (0xFF << (dev ? 0 : 8));
val32 |= td << (dev ? 8 : 0);
iowrite32(val32, base + BK3710_DMASTB);
val32 = ioread32(base + BK3710_DMARCVR) & (0xFF << (dev ? 0 : 8));
val32 |= tkw << (dev ? 8 : 0);
iowrite32(val32, base + BK3710_DMARCVR);
val16 = ioread16(base + BK3710_UDMACTL) & ~(1 << dev);
iowrite16(val16, base + BK3710_UDMACTL);
}
static void pata_bk3710_set_dmamode(struct ata_port *ap,
struct ata_device *adev)
{
void __iomem *base = (void __iomem *)ap->ioaddr.bmdma_addr;
int is_slave = adev->devno;
const u8 xferspeed = adev->dma_mode;
if (xferspeed >= XFER_UDMA_0)
pata_bk3710_setudmamode(base, is_slave,
xferspeed - XFER_UDMA_0);
else
pata_bk3710_setmwdmamode(base, is_slave,
adev->id[ATA_ID_EIDE_DMA_MIN],
xferspeed);
}
static void pata_bk3710_setpiomode(void __iomem *base, struct ata_device *pair,
unsigned int dev, unsigned int cycletime,
unsigned int mode)
{
const struct ata_timing *t;
u32 val32;
u8 t2, t2i, t0;
t = ata_timing_find_mode(XFER_PIO_0 + mode);
t0 = DIV_ROUND_UP(cycletime, ideclk_period);
t2 = DIV_ROUND_UP(t->active, ideclk_period);
t2i = t0 - t2 - 1;
t2--;
val32 = ioread32(base + BK3710_DATSTB) & (0xFF << (dev ? 0 : 8));
val32 |= t2 << (dev ? 8 : 0);
iowrite32(val32, base + BK3710_DATSTB);
val32 = ioread32(base + BK3710_DATRCVR) & (0xFF << (dev ? 0 : 8));
val32 |= t2i << (dev ? 8 : 0);
iowrite32(val32, base + BK3710_DATRCVR);
if (pair) {
u8 mode2 = pair->pio_mode - XFER_PIO_0;
if (mode2 < mode)
mode = mode2;
}
t0 = DIV_ROUND_UP(t->cyc8b, ideclk_period);
t2 = DIV_ROUND_UP(t->act8b, ideclk_period);
t2i = t0 - t2 - 1;
t2--;
val32 = ioread32(base + BK3710_REGSTB) & (0xFF << (dev ? 0 : 8));
val32 |= t2 << (dev ? 8 : 0);
iowrite32(val32, base + BK3710_REGSTB);
val32 = ioread32(base + BK3710_REGRCVR) & (0xFF << (dev ? 0 : 8));
val32 |= t2i << (dev ? 8 : 0);
iowrite32(val32, base + BK3710_REGRCVR);
}
static void pata_bk3710_set_piomode(struct ata_port *ap,
struct ata_device *adev)
{
void __iomem *base = (void __iomem *)ap->ioaddr.bmdma_addr;
struct ata_device *pair = ata_dev_pair(adev);
const struct ata_timing *t = ata_timing_find_mode(adev->pio_mode);
const u16 *id = adev->id;
unsigned int cycle_time = 0;
int is_slave = adev->devno;
const u8 pio = adev->pio_mode - XFER_PIO_0;
if (id[ATA_ID_FIELD_VALID] & 2) {
if (ata_id_has_iordy(id))
cycle_time = id[ATA_ID_EIDE_PIO_IORDY];
else
cycle_time = id[ATA_ID_EIDE_PIO];
if (pio < 3 && cycle_time < t->cycle)
cycle_time = 0;
}
if (!cycle_time)
cycle_time = t->cycle;
pata_bk3710_setpiomode(base, pair, is_slave, cycle_time, pio);
}
static void pata_bk3710_chipinit(void __iomem *base)
{
iowrite16(BIT(15), base + BK3710_IDETIMP);
iowrite16(0, base + BK3710_UDMACTL);
iowrite32(0x001, base + BK3710_MISCCTL);
iowrite32(0, base + BK3710_IORDYTMP);
iowrite16(0xE, base + BK3710_BMISP);
pata_bk3710_setpiomode(base, NULL, 0, 600, 0);
pata_bk3710_setpiomode(base, NULL, 1, 600, 0);
}
static int __init pata_bk3710_probe(struct platform_device *pdev)
{
struct clk *clk;
struct resource *mem;
struct ata_host *host;
struct ata_port *ap;
void __iomem *base;
unsigned long rate;
int irq;
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk))
return -ENODEV;
clk_enable(clk);
rate = clk_get_rate(clk);
if (!rate)
return -EINVAL;
ideclk_period = 1000000000UL / rate;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
pr_err(DRV_NAME ": failed to get IRQ resource\n");
return irq;
}
base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(base))
return PTR_ERR(base);
pata_bk3710_chipinit(base);
host = ata_host_alloc(&pdev->dev, 1);
if (!host)
return -ENOMEM;
ap = host->ports[0];
ap->ops = &pata_bk3710_ports_ops;
ap->pio_mask = ATA_PIO4;
ap->mwdma_mask = ATA_MWDMA2;
ap->udma_mask = rate < 100000000 ? ATA_UDMA4 : ATA_UDMA5;
ap->flags |= ATA_FLAG_SLAVE_POSS;
ap->ioaddr.data_addr = base + BK3710_TF_OFFSET;
ap->ioaddr.error_addr = base + BK3710_TF_OFFSET + 1;
ap->ioaddr.feature_addr = base + BK3710_TF_OFFSET + 1;
ap->ioaddr.nsect_addr = base + BK3710_TF_OFFSET + 2;
ap->ioaddr.lbal_addr = base + BK3710_TF_OFFSET + 3;
ap->ioaddr.lbam_addr = base + BK3710_TF_OFFSET + 4;
ap->ioaddr.lbah_addr = base + BK3710_TF_OFFSET + 5;
ap->ioaddr.device_addr = base + BK3710_TF_OFFSET + 6;
ap->ioaddr.status_addr = base + BK3710_TF_OFFSET + 7;
ap->ioaddr.command_addr = base + BK3710_TF_OFFSET + 7;
ap->ioaddr.altstatus_addr = base + BK3710_CTL_OFFSET;
ap->ioaddr.ctl_addr = base + BK3710_CTL_OFFSET;
ap->ioaddr.bmdma_addr = base;
ata_port_desc(ap, "cmd 0x%lx ctl 0x%lx",
(unsigned long)base + BK3710_TF_OFFSET,
(unsigned long)base + BK3710_CTL_OFFSET);
return ata_host_activate(host, irq, ata_sff_interrupt, 0,
&pata_bk3710_sht);
}
static int __init pata_bk3710_init(void)
{
return platform_driver_probe(&pata_bk3710_driver, pata_bk3710_probe);
}
