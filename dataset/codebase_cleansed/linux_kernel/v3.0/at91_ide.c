static void set_smc_timings(const u8 chipselect, const u16 cycle,
const u16 setup, const u16 pulse,
const u16 data_float, int use_iordy)
{
unsigned long mode = AT91_SMC_READMODE | AT91_SMC_WRITEMODE |
AT91_SMC_BAT_SELECT;
if (use_iordy)
mode |= AT91_SMC_EXNWMODE_READY;
if (data_float)
mode |= AT91_SMC_TDF_(data_float);
at91_sys_write(AT91_SMC_MODE(chipselect), mode);
at91_sys_write(AT91_SMC_SETUP(chipselect), AT91_SMC_NWESETUP_(setup) |
AT91_SMC_NCS_WRSETUP_(0) |
AT91_SMC_NRDSETUP_(setup) |
AT91_SMC_NCS_RDSETUP_(0));
at91_sys_write(AT91_SMC_PULSE(chipselect), AT91_SMC_NWEPULSE_(pulse) |
AT91_SMC_NCS_WRPULSE_(cycle) |
AT91_SMC_NRDPULSE_(pulse) |
AT91_SMC_NCS_RDPULSE_(cycle));
at91_sys_write(AT91_SMC_CYCLE(chipselect), AT91_SMC_NWECYCLE_(cycle) |
AT91_SMC_NRDCYCLE_(cycle));
}
static unsigned int calc_mck_cycles(unsigned int ns, unsigned int mck_hz)
{
u64 tmp = ns;
tmp *= mck_hz;
tmp += 1000*1000*1000 - 1;
do_div(tmp, 1000*1000*1000);
return (unsigned int) tmp;
}
static void apply_timings(const u8 chipselect, const u8 pio,
const struct ide_timing *timing, int use_iordy)
{
unsigned int t0, t1, t2, t6z;
unsigned int cycle, setup, pulse, data_float;
unsigned int mck_hz;
struct clk *mck;
t0 = timing->cyc8b;
t1 = timing->setup;
t2 = timing->act8b;
t6z = (pio < 5) ? 30 : 20;
pdbg("t0=%u t1=%u t2=%u t6z=%u\n", t0, t1, t2, t6z);
mck = clk_get(NULL, "mck");
BUG_ON(IS_ERR(mck));
mck_hz = clk_get_rate(mck);
pdbg("mck_hz=%u\n", mck_hz);
cycle = calc_mck_cycles(t0, mck_hz);
setup = calc_mck_cycles(t1, mck_hz);
pulse = calc_mck_cycles(t2, mck_hz);
data_float = calc_mck_cycles(t6z, mck_hz);
pdbg("cycle=%u setup=%u pulse=%u data_float=%u\n",
cycle, setup, pulse, data_float);
set_smc_timings(chipselect, cycle, setup, pulse, data_float, use_iordy);
}
static void at91_ide_input_data(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
ide_hwif_t *hwif = drive->hwif;
struct ide_io_ports *io_ports = &hwif->io_ports;
u8 chipselect = hwif->select_data;
unsigned long mode;
pdbg("cs %u buf %p len %d\n", chipselect, buf, len);
len++;
enter_16bit(chipselect, mode);
readsw((void __iomem *)io_ports->data_addr, buf, len / 2);
leave_16bit(chipselect, mode);
}
static void at91_ide_output_data(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
ide_hwif_t *hwif = drive->hwif;
struct ide_io_ports *io_ports = &hwif->io_ports;
u8 chipselect = hwif->select_data;
unsigned long mode;
pdbg("cs %u buf %p len %d\n", chipselect, buf, len);
enter_16bit(chipselect, mode);
writesw((void __iomem *)io_ports->data_addr, buf, len / 2);
leave_16bit(chipselect, mode);
}
static void at91_ide_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct ide_timing *timing;
u8 chipselect = hwif->select_data;
int use_iordy = 0;
const u8 pio = drive->pio_mode - XFER_PIO_0;
pdbg("chipselect %u pio %u\n", chipselect, pio);
timing = ide_timing_find_mode(XFER_PIO_0 + pio);
BUG_ON(!timing);
if (ide_pio_need_iordy(drive, pio))
use_iordy = 1;
apply_timings(chipselect, pio, timing, use_iordy);
}
irqreturn_t at91_irq_handler(int irq, void *dev_id)
{
int ntries = 8;
int pin_val1, pin_val2;
do {
pin_val1 = at91_get_gpio_value(irq);
pin_val2 = at91_get_gpio_value(irq);
} while (pin_val1 != pin_val2 && --ntries > 0);
if (pin_val1 == 0 || ntries <= 0)
return IRQ_HANDLED;
return ide_intr(irq, dev_id);
}
static int __init at91_ide_probe(struct platform_device *pdev)
{
int ret;
struct ide_hw hw, *hws[] = { &hw };
struct ide_host *host;
struct resource *res;
unsigned long tf_base = 0, ctl_base = 0;
struct at91_cf_data *board = pdev->dev.platform_data;
if (!board)
return -ENODEV;
if (board->det_pin && at91_get_gpio_value(board->det_pin) != 0) {
perr("no device detected\n");
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
perr("can't get memory resource\n");
return -ENODEV;
}
if (!devm_request_mem_region(&pdev->dev, res->start + TASK_FILE,
REGS_SIZE, "ide") ||
!devm_request_mem_region(&pdev->dev, res->start + ALT_MODE,
REGS_SIZE, "alt")) {
perr("memory resources in use\n");
return -EBUSY;
}
pdbg("chipselect %u irq %u res %08lx\n", board->chipselect,
board->irq_pin, (unsigned long) res->start);
tf_base = (unsigned long) devm_ioremap(&pdev->dev, res->start + TASK_FILE,
REGS_SIZE);
ctl_base = (unsigned long) devm_ioremap(&pdev->dev, res->start + ALT_MODE,
REGS_SIZE);
if (!tf_base || !ctl_base) {
perr("can't map memory regions\n");
return -EBUSY;
}
memset(&hw, 0, sizeof(hw));
if (board->flags & AT91_IDE_SWAP_A0_A2) {
hw.io_ports.data_addr = tf_base + 0;
hw.io_ports.error_addr = tf_base + 4;
hw.io_ports.nsect_addr = tf_base + 2;
hw.io_ports.lbal_addr = tf_base + 6;
hw.io_ports.lbam_addr = tf_base + 1;
hw.io_ports.lbah_addr = tf_base + 5;
hw.io_ports.device_addr = tf_base + 3;
hw.io_ports.command_addr = tf_base + 7;
hw.io_ports.ctl_addr = ctl_base + 3;
} else
ide_std_init_ports(&hw, tf_base, ctl_base + 6);
hw.irq = board->irq_pin;
hw.dev = &pdev->dev;
host = ide_host_alloc(&at91_ide_port_info, hws, 1);
if (!host) {
perr("failed to allocate ide host\n");
return -ENOMEM;
}
apply_timings(board->chipselect, 0, ide_timing_find_mode(XFER_PIO_0), 0);
if (board->irq_pin >= PIN_BASE)
host->irq_handler = at91_irq_handler;
host->ports[0]->select_data = board->chipselect;
ret = ide_host_register(host, &at91_ide_port_info, hws);
if (ret) {
perr("failed to register ide host\n");
goto err_free_host;
}
platform_set_drvdata(pdev, host);
return 0;
err_free_host:
ide_host_free(host);
return ret;
}
static int __exit at91_ide_remove(struct platform_device *pdev)
{
struct ide_host *host = platform_get_drvdata(pdev);
ide_host_remove(host);
return 0;
}
static int __init at91_ide_init(void)
{
return platform_driver_probe(&at91_ide_driver, at91_ide_probe);
}
static void __exit at91_ide_exit(void)
{
platform_driver_unregister(&at91_ide_driver);
}
