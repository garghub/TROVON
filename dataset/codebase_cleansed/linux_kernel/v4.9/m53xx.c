static void __init m53xx_clk_init(void)
{
unsigned i;
for (i = 0; i < ARRAY_SIZE(enable_clks); ++i)
__clk_init_enabled(enable_clks[i]);
for (i = 0; i < ARRAY_SIZE(disable_clks); ++i)
__clk_init_disabled(disable_clks[i]);
}
static void __init m53xx_qspi_init(void)
{
#if IS_ENABLED(CONFIG_SPI_COLDFIRE_QSPI)
writew(0x01f0, MCFGPIO_PAR_QSPI);
#endif
}
static void __init m53xx_uarts_init(void)
{
writew(readw(MCFGPIO_PAR_UART) | 0x0FFF, MCFGPIO_PAR_UART);
}
static void __init m53xx_fec_init(void)
{
u8 v;
v = readb(MCFGPIO_PAR_FECI2C);
v |= MCF_GPIO_PAR_FECI2C_PAR_MDC_EMDC |
MCF_GPIO_PAR_FECI2C_PAR_MDIO_EMDIO;
writeb(v, MCFGPIO_PAR_FECI2C);
v = readb(MCFGPIO_PAR_FEC);
v = MCF_GPIO_PAR_FEC_PAR_FEC_7W_FEC | MCF_GPIO_PAR_FEC_PAR_FEC_MII_FEC;
writeb(v, MCFGPIO_PAR_FEC);
}
void __init config_BSP(char *commandp, int size)
{
#if !defined(CONFIG_BOOTPARAM)
memcpy(commandp, (char *) 0x4000, 4);
if(strncmp(commandp, "kcl ", 4) == 0){
memcpy(commandp, (char *) 0x4004, size);
commandp[size-1] = 0;
} else {
memset(commandp, 0, size);
}
#endif
mach_sched_init = hw_timer_init;
m53xx_clk_init();
m53xx_uarts_init();
m53xx_fec_init();
m53xx_qspi_init();
#ifdef CONFIG_BDM_DISABLE
wdebug(MCFDEBUG_CSR, MCFDEBUG_CSR_PSTCLK);
#endif
}
asmlinkage void __init sysinit(void)
{
clock_pll(0, 0);
wtm_init();
scm_init();
gpio_init();
fbcs_init();
sdramc_init();
}
void wtm_init(void)
{
writew(0, MCF_WTM_WCR);
}
void scm_init(void)
{
writel(0x77777777, MCF_SCM_MPR);
writel(0, MCF_SCM_PACRA);
writel(0, MCF_SCM_PACRB);
writel(0, MCF_SCM_PACRC);
writel(0, MCF_SCM_PACRD);
writel(0, MCF_SCM_PACRE);
writel(0, MCF_SCM_PACRF);
writel(MCF_SCM_BCR_GBR | MCF_SCM_BCR_GBW, MCF_SCM_BCR);
}
void fbcs_init(void)
{
writeb(0x3E, MCFGPIO_PAR_CS);
writel(0x10080000, MCF_FBCS1_CSAR);
writel(0x002A3780, MCF_FBCS1_CSCR);
writel(MCF_FBCS_CSMR_BAM_2M | MCF_FBCS_CSMR_V, MCF_FBCS1_CSMR);
writew(0xffff, 0x10080000);
writel(EXT_SRAM_ADDRESS, MCF_FBCS1_CSAR);
writel(MCF_FBCS_CSCR_PS_16 |
MCF_FBCS_CSCR_AA |
MCF_FBCS_CSCR_SBM |
MCF_FBCS_CSCR_WS(1),
MCF_FBCS1_CSCR);
writel(MCF_FBCS_CSMR_BAM_512K | MCF_FBCS_CSMR_V, MCF_FBCS1_CSMR);
writel(FLASH_ADDRESS, MCF_FBCS0_CSAR);
writel(MCF_FBCS_CSCR_PS_16 |
MCF_FBCS_CSCR_BEM |
MCF_FBCS_CSCR_AA |
MCF_FBCS_CSCR_SBM |
MCF_FBCS_CSCR_WS(7),
MCF_FBCS0_CSCR);
writel(MCF_FBCS_CSMR_BAM_32M | MCF_FBCS_CSMR_V, MCF_FBCS0_CSMR);
}
void sdramc_init(void)
{
if (!(readl(MCF_SDRAMC_SDCR) & MCF_SDRAMC_SDCR_REF)) {
writel(MCF_SDRAMC_SDCS_BA(SDRAM_ADDRESS) |
MCF_SDRAMC_SDCS_CSSZ(MCF_SDRAMC_SDCS_CSSZ_32MBYTE),
MCF_SDRAMC_SDCS0);
writel(MCF_SDRAMC_SDCFG1_SRD2RW((int)((SDRAM_CASL + 2) + 0.5)) |
MCF_SDRAMC_SDCFG1_SWT2RD(SDRAM_TWR + 1) |
MCF_SDRAMC_SDCFG1_RDLAT((int)((SDRAM_CASL * 2) + 2)) |
MCF_SDRAMC_SDCFG1_ACT2RW((int)(SDRAM_TRCD + 0.5)) |
MCF_SDRAMC_SDCFG1_PRE2ACT((int)(SDRAM_TRP + 0.5)) |
MCF_SDRAMC_SDCFG1_REF2ACT((int)(SDRAM_TRFC + 0.5)) |
MCF_SDRAMC_SDCFG1_WTLAT(3),
MCF_SDRAMC_SDCFG1);
writel(MCF_SDRAMC_SDCFG2_BRD2PRE(SDRAM_BL / 2 + 1) |
MCF_SDRAMC_SDCFG2_BWT2RW(SDRAM_BL / 2 + SDRAM_TWR) |
MCF_SDRAMC_SDCFG2_BRD2WT((int)((SDRAM_CASL + SDRAM_BL / 2 - 1.0) + 0.5)) |
MCF_SDRAMC_SDCFG2_BL(SDRAM_BL - 1),
MCF_SDRAMC_SDCFG2);
writel(MCF_SDRAMC_SDCR_MODE_EN |
MCF_SDRAMC_SDCR_CKE |
MCF_SDRAMC_SDCR_DDR |
MCF_SDRAMC_SDCR_MUX(1) |
MCF_SDRAMC_SDCR_RCNT((int)(((SDRAM_TREFI / (SYSTEM_PERIOD * 64)) - 1) + 0.5)) |
MCF_SDRAMC_SDCR_PS_16 |
MCF_SDRAMC_SDCR_IPALL,
MCF_SDRAMC_SDCR);
writel(MCF_SDRAMC_SDMR_BNKAD_LEMR |
MCF_SDRAMC_SDMR_AD(0x0) |
MCF_SDRAMC_SDMR_CMD,
MCF_SDRAMC_SDMR);
writel(MCF_SDRAMC_SDMR_BNKAD_LMR |
MCF_SDRAMC_SDMR_AD(0x163) |
MCF_SDRAMC_SDMR_CMD,
MCF_SDRAMC_SDMR);
writel(readl(MCF_SDRAMC_SDCR) | MCF_SDRAMC_SDCR_IPALL, MCF_SDRAMC_SDCR);
writel(readl(MCF_SDRAMC_SDCR) | MCF_SDRAMC_SDCR_IREF, MCF_SDRAMC_SDCR);
writel(readl(MCF_SDRAMC_SDCR) | MCF_SDRAMC_SDCR_IREF, MCF_SDRAMC_SDCR);
writel(MCF_SDRAMC_SDMR_BNKAD_LMR |
MCF_SDRAMC_SDMR_AD(0x063) |
MCF_SDRAMC_SDMR_CMD,
MCF_SDRAMC_SDMR);
writel(readl(MCF_SDRAMC_SDCR) & ~MCF_SDRAMC_SDCR_MODE_EN,
MCF_SDRAMC_SDCR);
writel(MCF_SDRAMC_SDCR_REF | MCF_SDRAMC_SDCR_DQS_OE(0xC),
MCF_SDRAMC_SDCR);
}
}
void gpio_init(void)
{
writew(MCF_GPIO_PAR_UART_PAR_URXD0 | MCF_GPIO_PAR_UART_PAR_UTXD0,
MCFGPIO_PAR_UART);
writeb(0x00, MCFGPIO_PAR_TIMER);
writeb(0x08, MCFGPIO_PDDR_TIMER);
writeb(0x00, MCFGPIO_PCLRR_TIMER);
}
int clock_pll(int fsys, int flags)
{
int fref, temp, fout, mfd;
u32 i;
fref = FREF;
if (fsys == 0) {
mfd = readb(MCF_PLL_PFDR);
return (fref * mfd / (BUSDIV * 4));
}
if (fsys > MAX_FSYS)
fsys = MAX_FSYS;
if (fsys < MIN_FSYS)
fsys = MIN_FSYS;
temp = 100 * fsys / fref;
mfd = 4 * BUSDIV * temp / 100;
fout = (fref * mfd / (BUSDIV * 4));
if (readl(MCF_SDRAMC_SDCR) & MCF_SDRAMC_SDCR_REF)
writel(readl(MCF_SDRAMC_SDCR) & ~MCF_SDRAMC_SDCR_CKE,
MCF_SDRAMC_SDCR);
clock_limp(DEFAULT_LPD);
writeb(MCF_PLL_PODR_CPUDIV(BUSDIV/3) | MCF_PLL_PODR_BUSDIV(BUSDIV),
MCF_PLL_PODR);
writeb(mfd, MCF_PLL_PFDR);
clock_exit_limp();
if (readl(MCF_SDRAMC_SDCR) & MCF_SDRAMC_SDCR_REF)
writel(readl(MCF_SDRAMC_SDCR) | MCF_SDRAMC_SDCR_CKE,
MCF_SDRAMC_SDCR);
writel(MCF_SDRAMC_REFRESH, MCF_SDRAMC_LIMP_FIX);
for (i = 0; i < 0x200; i++)
;
return fout;
}
int clock_limp(int div)
{
u32 temp;
if (div < MIN_LPD)
div = MIN_LPD;
if (div > MAX_LPD)
div = MAX_LPD;
temp = readw(MCF_CCM_CDR) & MCF_CCM_CDR_SSIDIV(0xF);
writew(MCF_CCM_CDR_LPDIV(div) | MCF_CCM_CDR_SSIDIV(temp), MCF_CCM_CDR);
writew(readw(MCF_CCM_MISCCR) | MCF_CCM_MISCCR_LIMP, MCF_CCM_MISCCR);
return (FREF/(3*(1 << div)));
}
int clock_exit_limp(void)
{
int fout;
writew(readw(MCF_CCM_MISCCR) & ~MCF_CCM_MISCCR_LIMP, MCF_CCM_MISCCR);
while (!(readw(MCF_CCM_MISCCR) & MCF_CCM_MISCCR_PLL_LOCK))
;
fout = get_sys_clock();
return fout;
}
int get_sys_clock(void)
{
int divider;
if (readw(MCF_CCM_MISCCR) & MCF_CCM_MISCCR_LIMP) {
divider = readw(MCF_CCM_CDR) & MCF_CCM_CDR_LPDIV(0xF);
return (FREF/(2 << divider));
}
else
return (FREF * readb(MCF_PLL_PFDR)) / (BUSDIV * 4);
}
