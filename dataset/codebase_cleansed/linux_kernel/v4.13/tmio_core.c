int tmio_core_mmc_enable(void __iomem *cnf, int shift, unsigned long base)
{
sd_config_write16(cnf, shift, CNF_CMD, SDCREN);
sd_config_write32(cnf, shift, CNF_CTL_BASE, base & 0xfffe);
sd_config_write8(cnf, shift, CNF_PWR_CTL_3, 0x01);
sd_config_write8(cnf, shift, CNF_STOP_CLK_CTL, 0x1f);
sd_config_write8(cnf, shift, CNF_PWR_CTL_2, 0x00);
return 0;
}
int tmio_core_mmc_resume(void __iomem *cnf, int shift, unsigned long base)
{
sd_config_write16(cnf, shift, CNF_CMD, SDCREN);
sd_config_write32(cnf, shift, CNF_CTL_BASE, base & 0xfffe);
return 0;
}
void tmio_core_mmc_pwr(void __iomem *cnf, int shift, int state)
{
sd_config_write8(cnf, shift, CNF_PWR_CTL_2, state ? 0x02 : 0x00);
}
void tmio_core_mmc_clk_div(void __iomem *cnf, int shift, int state)
{
sd_config_write8(cnf, shift, CNF_SD_CLK_MODE, state ? 1 : 0);
}
