void __init at91_sysirq_mask_rtc(u32 rtc_base)
{
void __iomem *base;
base = ioremap(rtc_base, 64);
if (!base)
return;
writel_relaxed(AT91_RTC_IRQ_MASK, base + AT91_RTC_IDR);
(void)readl_relaxed(base + AT91_RTC_IMR);
iounmap(base);
}
void __init at91_sysirq_mask_rtt(u32 rtt_base)
{
void __iomem *base;
void __iomem *reg;
u32 mode;
base = ioremap(rtt_base, 16);
if (!base)
return;
reg = base + AT91_RTT_MR;
mode = readl_relaxed(reg);
if (mode & (AT91_RTT_ALMIEN | AT91_RTT_RTTINCIEN)) {
pr_info("AT91: Disabling rtt irq\n");
mode &= ~(AT91_RTT_ALMIEN | AT91_RTT_RTTINCIEN);
writel_relaxed(mode, reg);
(void)readl_relaxed(reg);
}
iounmap(base);
}
