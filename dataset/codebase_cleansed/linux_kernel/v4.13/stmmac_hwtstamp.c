static void stmmac_config_hw_tstamping(void __iomem *ioaddr, u32 data)
{
writel(data, ioaddr + PTP_TCR);
}
static u32 stmmac_config_sub_second_increment(void __iomem *ioaddr,
u32 ptp_clock, int gmac4)
{
u32 value = readl(ioaddr + PTP_TCR);
unsigned long data;
if (value & PTP_TCR_TSCFUPDT)
data = (1000000000ULL / 50000000);
else
data = (1000000000ULL / ptp_clock);
if (!(value & PTP_TCR_TSCTRLSSR))
data = (data * 1000) / 465;
data &= PTP_SSIR_SSINC_MASK;
if (gmac4)
data = data << GMAC4_PTP_SSIR_SSINC_SHIFT;
writel(data, ioaddr + PTP_SSIR);
return data;
}
static int stmmac_init_systime(void __iomem *ioaddr, u32 sec, u32 nsec)
{
int limit;
u32 value;
writel(sec, ioaddr + PTP_STSUR);
writel(nsec, ioaddr + PTP_STNSUR);
value = readl(ioaddr + PTP_TCR);
value |= PTP_TCR_TSINIT;
writel(value, ioaddr + PTP_TCR);
limit = 10;
while (limit--) {
if (!(readl(ioaddr + PTP_TCR) & PTP_TCR_TSINIT))
break;
mdelay(10);
}
if (limit < 0)
return -EBUSY;
return 0;
}
static int stmmac_config_addend(void __iomem *ioaddr, u32 addend)
{
u32 value;
int limit;
writel(addend, ioaddr + PTP_TAR);
value = readl(ioaddr + PTP_TCR);
value |= PTP_TCR_TSADDREG;
writel(value, ioaddr + PTP_TCR);
limit = 10;
while (limit--) {
if (!(readl(ioaddr + PTP_TCR) & PTP_TCR_TSADDREG))
break;
mdelay(10);
}
if (limit < 0)
return -EBUSY;
return 0;
}
static int stmmac_adjust_systime(void __iomem *ioaddr, u32 sec, u32 nsec,
int add_sub, int gmac4)
{
u32 value;
int limit;
if (add_sub) {
if (gmac4)
sec = (100000000ULL - sec);
value = readl(ioaddr + PTP_TCR);
if (value & PTP_TCR_TSCTRLSSR)
nsec = (PTP_DIGITAL_ROLLOVER_MODE - nsec);
else
nsec = (PTP_BINARY_ROLLOVER_MODE - nsec);
}
writel(sec, ioaddr + PTP_STSUR);
value = (add_sub << PTP_STNSUR_ADDSUB_SHIFT) | nsec;
writel(value, ioaddr + PTP_STNSUR);
value = readl(ioaddr + PTP_TCR);
value |= PTP_TCR_TSUPDT;
writel(value, ioaddr + PTP_TCR);
limit = 10;
while (limit--) {
if (!(readl(ioaddr + PTP_TCR) & PTP_TCR_TSUPDT))
break;
mdelay(10);
}
if (limit < 0)
return -EBUSY;
return 0;
}
static u64 stmmac_get_systime(void __iomem *ioaddr)
{
u64 ns;
ns = readl(ioaddr + PTP_STNSR);
ns += readl(ioaddr + PTP_STSR) * 1000000000ULL;
return ns;
}
