static inline u32 ar5312_rst_reg_read(u32 reg)
{
return __raw_readl(ar5312_rst_base + reg);
}
static inline void ar5312_rst_reg_write(u32 reg, u32 val)
{
__raw_writel(val, ar5312_rst_base + reg);
}
static inline void ar5312_rst_reg_mask(u32 reg, u32 mask, u32 val)
{
u32 ret = ar5312_rst_reg_read(reg);
ret &= ~mask;
ret |= val;
ar5312_rst_reg_write(reg, ret);
}
static irqreturn_t ar5312_ahb_err_handler(int cpl, void *dev_id)
{
u32 proc1 = ar5312_rst_reg_read(AR5312_PROC1);
u32 proc_addr = ar5312_rst_reg_read(AR5312_PROCADDR);
u32 dma1 = ar5312_rst_reg_read(AR5312_DMA1);
u32 dma_addr = ar5312_rst_reg_read(AR5312_DMAADDR);
pr_emerg("AHB interrupt: PROCADDR=0x%8.8x PROC1=0x%8.8x DMAADDR=0x%8.8x DMA1=0x%8.8x\n",
proc_addr, proc1, dma_addr, dma1);
machine_restart("AHB error");
return IRQ_HANDLED;
}
static void ar5312_misc_irq_handler(struct irq_desc *desc)
{
u32 pending = ar5312_rst_reg_read(AR5312_ISR) &
ar5312_rst_reg_read(AR5312_IMR);
unsigned nr, misc_irq = 0;
if (pending) {
struct irq_domain *domain = irq_desc_get_handler_data(desc);
nr = __ffs(pending);
misc_irq = irq_find_mapping(domain, nr);
}
if (misc_irq) {
generic_handle_irq(misc_irq);
if (nr == AR5312_MISC_IRQ_TIMER)
ar5312_rst_reg_read(AR5312_TIMER);
} else {
spurious_interrupt();
}
}
static void ar5312_misc_irq_unmask(struct irq_data *d)
{
ar5312_rst_reg_mask(AR5312_IMR, 0, BIT(d->hwirq));
}
static void ar5312_misc_irq_mask(struct irq_data *d)
{
ar5312_rst_reg_mask(AR5312_IMR, BIT(d->hwirq), 0);
ar5312_rst_reg_read(AR5312_IMR);
}
static int ar5312_misc_irq_map(struct irq_domain *d, unsigned irq,
irq_hw_number_t hw)
{
irq_set_chip_and_handler(irq, &ar5312_misc_irq_chip, handle_level_irq);
return 0;
}
static void ar5312_irq_dispatch(void)
{
u32 pending = read_c0_status() & read_c0_cause();
if (pending & CAUSEF_IP2)
do_IRQ(AR5312_IRQ_WLAN0);
else if (pending & CAUSEF_IP5)
do_IRQ(AR5312_IRQ_WLAN1);
else if (pending & CAUSEF_IP6)
do_IRQ(AR5312_IRQ_MISC);
else if (pending & CAUSEF_IP7)
do_IRQ(ATH25_IRQ_CPU_CLOCK);
else
spurious_interrupt();
}
void __init ar5312_arch_init_irq(void)
{
struct irq_domain *domain;
unsigned irq;
ath25_irq_dispatch = ar5312_irq_dispatch;
domain = irq_domain_add_linear(NULL, AR5312_MISC_IRQ_COUNT,
&ar5312_misc_irq_domain_ops, NULL);
if (!domain)
panic("Failed to add IRQ domain");
irq = irq_create_mapping(domain, AR5312_MISC_IRQ_AHB_PROC);
setup_irq(irq, &ar5312_ahb_err_interrupt);
irq_set_chained_handler_and_data(AR5312_IRQ_MISC,
ar5312_misc_irq_handler, domain);
ar5312_misc_irq_domain = domain;
}
static void __init ar5312_flash_init(void)
{
void __iomem *flashctl_base;
u32 ctl;
flashctl_base = ioremap_nocache(AR5312_FLASHCTL_BASE,
AR5312_FLASHCTL_SIZE);
ctl = __raw_readl(flashctl_base + AR5312_FLASHCTL0);
ctl &= AR5312_FLASHCTL_MW;
switch (ctl) {
case AR5312_FLASHCTL_MW16:
ar5312_flash_data.width = 2;
break;
case AR5312_FLASHCTL_MW8:
default:
ar5312_flash_data.width = 1;
break;
}
ctl |= AR5312_FLASHCTL_E | AR5312_FLASHCTL_AC_8M | AR5312_FLASHCTL_RBLE;
ctl |= 0x01 << AR5312_FLASHCTL_IDCY_S;
ctl |= 0x07 << AR5312_FLASHCTL_WST1_S;
ctl |= 0x07 << AR5312_FLASHCTL_WST2_S;
__raw_writel(ctl, flashctl_base + AR5312_FLASHCTL0);
ctl = __raw_readl(flashctl_base + AR5312_FLASHCTL1);
ctl &= ~(AR5312_FLASHCTL_E | AR5312_FLASHCTL_AC);
__raw_writel(ctl, flashctl_base + AR5312_FLASHCTL1);
ctl = __raw_readl(flashctl_base + AR5312_FLASHCTL2);
ctl &= ~(AR5312_FLASHCTL_E | AR5312_FLASHCTL_AC);
__raw_writel(ctl, flashctl_base + AR5312_FLASHCTL2);
iounmap(flashctl_base);
}
void __init ar5312_init_devices(void)
{
struct ath25_boarddata *config;
ar5312_flash_init();
ath25_find_config(AR5312_FLASH_BASE, AR5312_FLASH_SIZE);
config = ath25_board.config;
if ((current_cpu_data.processor_id & 0xff) == 0x0a)
ath25_soc = ATH25_SOC_AR2313;
else if (config->flags & BD_ISCASPER)
ath25_soc = ATH25_SOC_AR2312;
else
ath25_soc = ATH25_SOC_AR5312;
platform_device_register(&ar5312_physmap_flash);
switch (ath25_soc) {
case ATH25_SOC_AR5312:
if (!ath25_board.radio)
return;
if (!(config->flags & BD_WLAN0))
break;
ath25_add_wmac(0, AR5312_WLAN0_BASE, AR5312_IRQ_WLAN0);
break;
case ATH25_SOC_AR2312:
case ATH25_SOC_AR2313:
if (!ath25_board.radio)
return;
break;
default:
break;
}
if (config->flags & BD_WLAN1)
ath25_add_wmac(1, AR5312_WLAN1_BASE, AR5312_IRQ_WLAN1);
}
static void ar5312_restart(char *command)
{
local_irq_disable();
while (1)
ar5312_rst_reg_write(AR5312_RESET, AR5312_RESET_SYSTEM);
}
static unsigned __init ar5312_cpu_frequency(void)
{
u32 scratch, devid, clock_ctl1;
u32 predivide_mask, multiplier_mask, doubler_mask;
unsigned predivide_shift, multiplier_shift;
unsigned predivide_select, predivisor, multiplier;
scratch = ar5312_rst_reg_read(AR5312_SCRATCH);
if (scratch)
return scratch;
devid = ar5312_rst_reg_read(AR5312_REV);
devid = (devid & AR5312_REV_MAJ) >> AR5312_REV_MAJ_S;
if (devid == AR5312_REV_MAJ_AR2313) {
predivide_mask = AR2313_CLOCKCTL1_PREDIVIDE_MASK;
predivide_shift = AR2313_CLOCKCTL1_PREDIVIDE_SHIFT;
multiplier_mask = AR2313_CLOCKCTL1_MULTIPLIER_MASK;
multiplier_shift = AR2313_CLOCKCTL1_MULTIPLIER_SHIFT;
doubler_mask = AR2313_CLOCKCTL1_DOUBLER_MASK;
} else {
predivide_mask = AR5312_CLOCKCTL1_PREDIVIDE_MASK;
predivide_shift = AR5312_CLOCKCTL1_PREDIVIDE_SHIFT;
multiplier_mask = AR5312_CLOCKCTL1_MULTIPLIER_MASK;
multiplier_shift = AR5312_CLOCKCTL1_MULTIPLIER_SHIFT;
doubler_mask = AR5312_CLOCKCTL1_DOUBLER_MASK;
}
clock_ctl1 = ar5312_rst_reg_read(AR5312_CLOCKCTL1);
predivide_select = (clock_ctl1 & predivide_mask) >> predivide_shift;
predivisor = clockctl1_predivide_table[predivide_select];
multiplier = (clock_ctl1 & multiplier_mask) >> multiplier_shift;
if (clock_ctl1 & doubler_mask)
multiplier <<= 1;
return (40000000 / predivisor) * multiplier;
}
static inline unsigned ar5312_sys_frequency(void)
{
return ar5312_cpu_frequency() / 4;
}
void __init ar5312_plat_time_init(void)
{
mips_hpt_frequency = ar5312_cpu_frequency() / 2;
}
void __init ar5312_plat_mem_setup(void)
{
void __iomem *sdram_base;
u32 memsize, memcfg, bank0_ac, bank1_ac;
u32 devid;
sdram_base = ioremap_nocache(AR5312_SDRAMCTL_BASE,
AR5312_SDRAMCTL_SIZE);
memcfg = __raw_readl(sdram_base + AR5312_MEM_CFG1);
bank0_ac = ATH25_REG_MS(memcfg, AR5312_MEM_CFG1_AC0);
bank1_ac = ATH25_REG_MS(memcfg, AR5312_MEM_CFG1_AC1);
memsize = (bank0_ac ? (1 << (bank0_ac + 1)) : 0) +
(bank1_ac ? (1 << (bank1_ac + 1)) : 0);
memsize <<= 20;
add_memory_region(0, memsize, BOOT_MEM_RAM);
iounmap(sdram_base);
ar5312_rst_base = ioremap_nocache(AR5312_RST_BASE, AR5312_RST_SIZE);
devid = ar5312_rst_reg_read(AR5312_REV);
devid >>= AR5312_REV_WMAC_MIN_S;
devid &= AR5312_REV_CHIP;
ath25_board.devid = (u16)devid;
ar5312_rst_reg_read(AR5312_PROCADDR);
ar5312_rst_reg_read(AR5312_DMAADDR);
ar5312_rst_reg_write(AR5312_WDT_CTRL, AR5312_WDT_CTRL_IGNORE);
_machine_restart = ar5312_restart;
}
void __init ar5312_arch_init(void)
{
unsigned irq = irq_create_mapping(ar5312_misc_irq_domain,
AR5312_MISC_IRQ_UART0);
ath25_serial_setup(AR5312_UART0_BASE, irq, ar5312_sys_frequency());
}
