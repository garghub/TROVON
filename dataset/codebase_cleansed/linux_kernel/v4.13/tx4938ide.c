static void tx4938ide_tune_ebusc(unsigned int ebus_ch,
unsigned int gbus_clock,
u8 pio)
{
struct ide_timing *t = ide_timing_find_mode(XFER_PIO_0 + pio);
u64 cr = __raw_readq(&tx4938_ebuscptr->cr[ebus_ch]);
unsigned int sp = (cr >> 4) & 3;
unsigned int clock = gbus_clock / (4 - sp);
unsigned int cycle = 1000000000 / clock;
unsigned int shwt;
int wt;
wt = DIV_ROUND_UP(t->act8b, cycle) - 2;
wt = max_t(int, wt, DIV_ROUND_UP(35, cycle));
if (wt > 2 && (wt & 1))
wt++;
wt &= ~1;
shwt = DIV_ROUND_UP(t->setup, cycle);
while ((shwt * 4 + wt + (wt ? 2 : 3)) * cycle < t->cycle)
shwt++;
if (shwt > 7) {
pr_warning("tx4938ide: SHWT violation (%d)\n", shwt);
shwt = 7;
}
pr_debug("tx4938ide: ebus %d, bus cycle %dns, WT %d, SHWT %d\n",
ebus_ch, cycle, wt, shwt);
__raw_writeq((cr & ~0x3f007ull) | (wt << 12) | shwt,
&tx4938_ebuscptr->cr[ebus_ch]);
}
static void tx4938ide_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct tx4938ide_platform_info *pdata = dev_get_platdata(hwif->dev);
u8 safe = drive->pio_mode - XFER_PIO_0;
ide_drive_t *pair;
pair = ide_get_pair_dev(drive);
if (pair)
safe = min_t(u8, safe, pair->pio_mode - XFER_PIO_0);
tx4938ide_tune_ebusc(pdata->ebus_ch, pdata->gbus_clock, safe);
}
static void tx4938ide_input_data_swap(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
unsigned long port = drive->hwif->io_ports.data_addr;
unsigned short *ptr = buf;
unsigned int count = (len + 1) / 2;
while (count--)
*ptr++ = cpu_to_le16(__raw_readw((void __iomem *)port));
__ide_flush_dcache_range((unsigned long)buf, roundup(len, 2));
}
static void tx4938ide_output_data_swap(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
unsigned long port = drive->hwif->io_ports.data_addr;
unsigned short *ptr = buf;
unsigned int count = (len + 1) / 2;
while (count--) {
__raw_writew(le16_to_cpu(*ptr), (void __iomem *)port);
ptr++;
}
__ide_flush_dcache_range((unsigned long)buf, roundup(len, 2));
}
static int __init tx4938ide_probe(struct platform_device *pdev)
{
struct ide_hw hw, *hws[] = { &hw };
struct ide_host *host;
struct resource *res;
struct tx4938ide_platform_info *pdata = dev_get_platdata(&pdev->dev);
int irq, ret, i;
unsigned long mapbase, mapctl;
struct ide_port_info d = tx4938ide_port_info;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), "tx4938ide"))
return -EBUSY;
mapbase = (unsigned long)devm_ioremap(&pdev->dev, res->start,
8 << pdata->ioport_shift);
mapctl = (unsigned long)devm_ioremap(&pdev->dev,
res->start + 0x10000 +
(6 << pdata->ioport_shift),
1 << pdata->ioport_shift);
if (!mapbase || !mapctl)
return -EBUSY;
memset(&hw, 0, sizeof(hw));
if (pdata->ioport_shift) {
unsigned long port = mapbase;
unsigned long ctl = mapctl;
hw.io_ports_array[0] = port;
#ifdef __BIG_ENDIAN
port++;
ctl++;
#endif
for (i = 1; i <= 7; i++)
hw.io_ports_array[i] =
port + (i << pdata->ioport_shift);
hw.io_ports.ctl_addr = ctl;
} else
ide_std_init_ports(&hw, mapbase, mapctl);
hw.irq = irq;
hw.dev = &pdev->dev;
pr_info("TX4938 IDE interface (base %#lx, ctl %#lx, irq %d)\n",
mapbase, mapctl, hw.irq);
if (pdata->gbus_clock)
tx4938ide_tune_ebusc(pdata->ebus_ch, pdata->gbus_clock, 0);
else
d.port_ops = NULL;
ret = ide_host_add(&d, hws, 1, &host);
if (!ret)
platform_set_drvdata(pdev, host);
return ret;
}
static int __exit tx4938ide_remove(struct platform_device *pdev)
{
struct ide_host *host = platform_get_drvdata(pdev);
ide_host_remove(host);
return 0;
}
