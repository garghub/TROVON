static int adjust_smc_value(int *value, struct smc_range *range, int size)
{
int maximum = (range + size - 1)->max;
int remainder;
do {
if (*value < range->min) {
remainder = range->min - *value;
*value = range->min;
return remainder;
} else if ((range->min <= *value) && (*value <= range->max))
return 0;
range++;
} while (--size);
*value = maximum;
return -1;
}
static int calc_smc_vals(struct device *dev,
int *setup, int *pulse, int *cycle, int *cs_pulse)
{
int ret_val;
int err = 0;
struct smc_range range_setup[] = {
{.min = 0, .max = 31},
{.min = 128, .max = 159}
};
struct smc_range range_pulse[] = {
{.min = 0, .max = 63},
{.min = 256, .max = 319}
};
struct smc_range range_cycle[] = {
{.min = 0, .max = 127},
{.min = 256, .max = 383},
{.min = 512, .max = 639},
{.min = 768, .max = 895}
};
ret_val = adjust_smc_value(setup, range_setup, ARRAY_SIZE(range_setup));
if (ret_val < 0)
dev_warn(dev, "maximal SMC Setup value\n");
else
*cycle += ret_val;
ret_val = adjust_smc_value(pulse, range_pulse, ARRAY_SIZE(range_pulse));
if (ret_val < 0)
dev_warn(dev, "maximal SMC Pulse value\n");
else
*cycle += ret_val;
ret_val = adjust_smc_value(cycle, range_cycle, ARRAY_SIZE(range_cycle));
if (ret_val < 0)
dev_warn(dev, "maximal SMC Cycle value\n");
*cs_pulse = *cycle;
if (*cs_pulse > CS_PULSE_MAXIMUM) {
dev_err(dev, "unable to calculate valid SMC settings\n");
return -ER_SMC_CALC;
}
ret_val = adjust_smc_value(cs_pulse, range_pulse,
ARRAY_SIZE(range_pulse));
if (ret_val < 0) {
dev_warn(dev, "maximal SMC CS Pulse value\n");
} else if (ret_val != 0) {
*cycle = *cs_pulse;
dev_warn(dev, "SMC Cycle extended\n");
err = -ER_SMC_RECALC;
}
return err;
}
static void to_smc_format(int *setup, int *pulse, int *cycle, int *cs_pulse)
{
*setup = (*setup & 0x1f) | ((*setup & 0x80) >> 2);
*pulse = (*pulse & 0x3f) | ((*pulse & 0x100) >> 2);
*cycle = (*cycle & 0x7f) | ((*cycle & 0x300) >> 1);
*cs_pulse = (*cs_pulse & 0x3f) | ((*cs_pulse & 0x100) >> 2);
}
static unsigned long calc_mck_cycles(unsigned long ns, unsigned long mck_hz)
{
unsigned long mul;
mul = (mck_hz / 10000) << 16;
mul /= 100000;
return (ns * mul + 65536) >> 16;
}
static void set_smc_timing(struct device *dev, struct ata_device *adev,
struct at91_ide_info *info, const struct ata_timing *ata)
{
int ret = 0;
int use_iordy;
unsigned int t6z;
unsigned int cycle;
unsigned int setup;
unsigned int pulse;
unsigned int cs_setup = 0;
unsigned int cs_pulse;
unsigned int tdf_cycles;
unsigned long mck_hz;
t6z = (ata->mode < XFER_PIO_5) ? 30 : 20;
mck_hz = clk_get_rate(info->mck);
cycle = calc_mck_cycles(ata->cyc8b, mck_hz);
setup = calc_mck_cycles(ata->setup, mck_hz);
pulse = calc_mck_cycles(ata->act8b, mck_hz);
tdf_cycles = calc_mck_cycles(t6z, mck_hz);
do {
ret = calc_smc_vals(dev, &setup, &pulse, &cycle, &cs_pulse);
} while (ret == -ER_SMC_RECALC);
if (ret == -ER_SMC_CALC)
dev_err(dev, "Interface may not operate correctly\n");
dev_dbg(dev, "SMC Setup=%u, Pulse=%u, Cycle=%u, CS Pulse=%u\n",
setup, pulse, cycle, cs_pulse);
to_smc_format(&setup, &pulse, &cycle, &cs_pulse);
use_iordy = ata_pio_need_iordy(adev);
if (use_iordy)
info->mode |= AT91_SMC_EXNWMODE_READY;
if (tdf_cycles > 15) {
tdf_cycles = 15;
dev_warn(dev, "maximal SMC TDF Cycles value\n");
}
dev_dbg(dev, "Use IORDY=%u, TDF Cycles=%u\n", use_iordy, tdf_cycles);
info->mode |= AT91_SMC_TDF_(tdf_cycles);
at91_sys_write(AT91_SMC_SETUP(info->cs),
AT91_SMC_NWESETUP_(setup) |
AT91_SMC_NRDSETUP_(setup) |
AT91_SMC_NCS_WRSETUP_(cs_setup) |
AT91_SMC_NCS_RDSETUP_(cs_setup));
at91_sys_write(AT91_SMC_PULSE(info->cs),
AT91_SMC_NWEPULSE_(pulse) |
AT91_SMC_NRDPULSE_(pulse) |
AT91_SMC_NCS_WRPULSE_(cs_pulse) |
AT91_SMC_NCS_RDPULSE_(cs_pulse));
at91_sys_write(AT91_SMC_CYCLE(info->cs),
AT91_SMC_NWECYCLE_(cycle) |
AT91_SMC_NRDCYCLE_(cycle));
at91_sys_write(AT91_SMC_MODE(info->cs), info->mode);
}
static void pata_at91_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct at91_ide_info *info = ap->host->private_data;
struct ata_timing timing;
int ret;
ret = ata_timing_compute(adev, adev->pio_mode, &timing, 1000, 0);
if (ret) {
dev_warn(ap->dev, "Failed to compute ATA timing %d, "
"set PIO_0 timing\n", ret);
timing = *ata_timing_find_mode(XFER_PIO_0);
}
set_smc_timing(ap->dev, adev, info, &timing);
}
static unsigned int pata_at91_data_xfer_noirq(struct ata_device *dev,
unsigned char *buf, unsigned int buflen, int rw)
{
struct at91_ide_info *info = dev->link->ap->host->private_data;
unsigned int consumed;
unsigned long flags;
unsigned int mode;
local_irq_save(flags);
mode = at91_sys_read(AT91_SMC_MODE(info->cs));
at91_sys_write(AT91_SMC_MODE(info->cs),
(mode & ~AT91_SMC_DBW) | AT91_SMC_DBW_16);
consumed = ata_sff_data_xfer(dev, buf, buflen, rw);
at91_sys_write(AT91_SMC_MODE(info->cs),
(mode & ~AT91_SMC_DBW) | AT91_SMC_DBW_8);
local_irq_restore(flags);
return consumed;
}
static int __devinit pata_at91_probe(struct platform_device *pdev)
{
struct at91_cf_data *board = pdev->dev.platform_data;
struct device *dev = &pdev->dev;
struct at91_ide_info *info;
struct resource *mem_res;
struct ata_host *host;
struct ata_port *ap;
int irq_flags = 0;
int irq = 0;
int ret;
if (pdev->num_resources != 1) {
dev_err(&pdev->dev, "invalid number of resources\n");
return -EINVAL;
}
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem_res) {
dev_err(dev, "failed to get mem resource\n");
return -EINVAL;
}
irq = board->irq_pin;
host = ata_host_alloc(dev, 1);
if (!host)
return -ENOMEM;
ap = host->ports[0];
ap->ops = &pata_at91_port_ops;
ap->flags |= ATA_FLAG_SLAVE_POSS;
ap->pio_mask = ATA_PIO4;
if (!irq) {
ap->flags |= ATA_FLAG_PIO_POLLING;
ata_port_desc(ap, "no IRQ, using PIO polling");
}
info = devm_kzalloc(dev, sizeof(*info), GFP_KERNEL);
if (!info) {
dev_err(dev, "failed to allocate memory for private data\n");
return -ENOMEM;
}
info->mck = clk_get(NULL, "mck");
if (IS_ERR(info->mck)) {
dev_err(dev, "failed to get access to mck clock\n");
return -ENODEV;
}
info->cs = board->chipselect;
info->mode = AT91_SMC_READMODE | AT91_SMC_WRITEMODE |
AT91_SMC_EXNWMODE_READY | AT91_SMC_BAT_SELECT |
AT91_SMC_DBW_8 | AT91_SMC_TDF_(0);
info->ide_addr = devm_ioremap(dev,
mem_res->start + CF_IDE_OFFSET, CF_IDE_RES_SIZE);
if (!info->ide_addr) {
dev_err(dev, "failed to map IO base\n");
ret = -ENOMEM;
goto err_put;
}
info->alt_addr = devm_ioremap(dev,
mem_res->start + CF_ALT_IDE_OFFSET, CF_IDE_RES_SIZE);
if (!info->alt_addr) {
dev_err(dev, "failed to map CTL base\n");
ret = -ENOMEM;
goto err_put;
}
ap->ioaddr.cmd_addr = info->ide_addr;
ap->ioaddr.ctl_addr = info->alt_addr + 0x06;
ap->ioaddr.altstatus_addr = ap->ioaddr.ctl_addr;
ata_sff_std_ports(&ap->ioaddr);
ata_port_desc(ap, "mmio cmd 0x%llx ctl 0x%llx",
(unsigned long long)mem_res->start + CF_IDE_OFFSET,
(unsigned long long)mem_res->start + CF_ALT_IDE_OFFSET);
host->private_data = info;
return ata_host_activate(host, irq ? gpio_to_irq(irq) : 0,
irq ? ata_sff_interrupt : NULL,
irq_flags, &pata_at91_sht);
err_put:
clk_put(info->mck);
return ret;
}
static int __devexit pata_at91_remove(struct platform_device *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
struct at91_ide_info *info;
if (!host)
return 0;
info = host->private_data;
ata_host_detach(host);
if (!info)
return 0;
clk_put(info->mck);
return 0;
}
static int __init pata_at91_init(void)
{
return platform_driver_register(&pata_at91_driver);
}
static void __exit pata_at91_exit(void)
{
platform_driver_unregister(&pata_at91_driver);
}
