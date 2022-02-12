static void do_sync(void)
{
__builtin_bfin_ssync();
}
void init_clocks(void)
{
#ifdef CONFIG_BF60x
int i, dlldatacycle, dll_ctl;
bfin_write32(CGU0_DIV, CGU_DIV_VAL);
bfin_write32(CGU0_CTL, CGU_CTL_VAL);
while ((bfin_read32(CGU0_STAT) & 0x8) || !(bfin_read32(CGU0_STAT) & 0x4))
continue;
bfin_write32(CGU0_DIV, CGU_DIV_VAL | (1 << UPDT_P));
while (bfin_read32(CGU0_STAT) & (1 << 3))
continue;
for (i = 0; i < 7; i++) {
if (ddr_config_table[i].ddr_clk == CONFIG_BFIN_DCLK) {
bfin_write_DDR0_CFG(ddr_config_table[i].dmc_ddrcfg);
bfin_write_DDR0_TR0(ddr_config_table[i].dmc_ddrtr0);
bfin_write_DDR0_TR1(ddr_config_table[i].dmc_ddrtr1);
bfin_write_DDR0_TR2(ddr_config_table[i].dmc_ddrtr2);
bfin_write_DDR0_MR(ddr_config_table[i].dmc_ddrmr);
bfin_write_DDR0_EMR1(ddr_config_table[i].dmc_ddrmr1);
bfin_write_DDR0_CTL(ddr_config_table[i].dmc_ddrctl);
break;
}
}
do_sync();
while (!(bfin_read_DDR0_STAT() & 0x4))
continue;
dlldatacycle = (bfin_read_DDR0_STAT() & 0x00f00000) >> 20;
dll_ctl = bfin_read_DDR0_DLLCTL();
dll_ctl &= 0x0ff;
bfin_write_DDR0_DLLCTL(dll_ctl | (dlldatacycle << 8));
do_sync();
while (!(bfin_read_DDR0_STAT() & 0x2000))
continue;
#else
size_t i;
for (i = 0; i < MAX_DMA_CHANNELS; ++i) {
struct dma_register *dma = dma_io_base_addr[i];
dma->cfg = 0;
}
do_sync();
#ifdef SIC_IWR0
bfin_write_SIC_IWR0(IWR_ENABLE(0));
# ifdef SIC_IWR1
if (ANOMALY_05000435)
bfin_write_SIC_IWR1(IWR_ENABLE(10) | IWR_ENABLE(11));
else
bfin_write_SIC_IWR1(IWR_DISABLE_ALL);
# endif
# ifdef SIC_IWR2
bfin_write_SIC_IWR2(IWR_DISABLE_ALL);
# endif
#else
bfin_write_SIC_IWR(IWR_ENABLE(0));
#endif
do_sync();
#ifdef EBIU_SDGCTL
bfin_write_EBIU_SDGCTL(bfin_read_EBIU_SDGCTL() | SRFS);
do_sync();
#endif
#ifdef CLKBUFOE
bfin_write16(VR_CTL, bfin_read_VR_CTL() | CLKBUFOE);
do_sync();
__asm__ __volatile__("IDLE;");
#endif
bfin_write_PLL_LOCKCNT(0x300);
do_sync();
bfin_write16(PLL_CTL, PLL_CTL_VAL);
__asm__ __volatile__("IDLE;");
bfin_write_PLL_DIV(CONFIG_CCLK_ACT_DIV | CONFIG_SCLK_DIV);
#ifdef EBIU_SDGCTL
bfin_write_EBIU_SDRRC(mem_SDRRC);
bfin_write_EBIU_SDGCTL((bfin_read_EBIU_SDGCTL() & SDGCTL_WIDTH) | mem_SDGCTL);
#else
bfin_write_EBIU_RSTCTL(bfin_read_EBIU_RSTCTL() & ~(SRREQ));
do_sync();
bfin_write_EBIU_RSTCTL(bfin_read_EBIU_RSTCTL() | 0x1);
bfin_write_EBIU_DDRCTL0(mem_DDRCTL0);
bfin_write_EBIU_DDRCTL1(mem_DDRCTL1);
bfin_write_EBIU_DDRCTL2(mem_DDRCTL2);
#ifdef CONFIG_MEM_EBIU_DDRQUE
bfin_write_EBIU_DDRQUE(CONFIG_MEM_EBIU_DDRQUE);
#endif
#endif
#endif
do_sync();
bfin_read16(0);
}
