static void stmmac_config_hw_tstamping(void __iomem *ioaddr, u32 data)
{
writel(data, ioaddr + PTP_TCR);
}
static u32 stmmac_config_sub_second_increment(void __iomem *ioaddr,
u32 ptp_clock)
{
u32 value = readl(ioaddr + PTP_TCR);
unsigned long data;
data = (2000000000ULL / ptp_clock);
if (!(value & PTP_TCR_TSCTRLSSR))
data = (data * 1000) / 465;
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
int add_sub)
{
u32 value;
int limit;
writel(sec, ioaddr + PTP_STSUR);
writel(((add_sub << PTP_STNSUR_ADDSUB_SHIFT) | nsec),
ioaddr + PTP_STNSUR);
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
