void sirfsoc_rtc_iobrg_wait_sync(void)
{
while (readl_relaxed(sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_CTRL))
cpu_relax();
}
void sirfsoc_rtc_iobrg_besyncing(void)
{
unsigned long flags;
spin_lock_irqsave(&rtciobrg_lock, flags);
sirfsoc_rtc_iobrg_wait_sync();
spin_unlock_irqrestore(&rtciobrg_lock, flags);
}
u32 __sirfsoc_rtc_iobrg_readl(u32 addr)
{
sirfsoc_rtc_iobrg_wait_sync();
writel_relaxed(0x00, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_WRBE);
writel_relaxed(addr, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_ADDR);
writel_relaxed(0x01, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_CTRL);
sirfsoc_rtc_iobrg_wait_sync();
return readl_relaxed(sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_DATA);
}
u32 sirfsoc_rtc_iobrg_readl(u32 addr)
{
unsigned long flags, val;
spin_lock_irqsave(&rtciobrg_lock, flags);
val = __sirfsoc_rtc_iobrg_readl(addr);
spin_unlock_irqrestore(&rtciobrg_lock, flags);
return val;
}
void sirfsoc_rtc_iobrg_pre_writel(u32 val, u32 addr)
{
sirfsoc_rtc_iobrg_wait_sync();
writel_relaxed(0xf1, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_WRBE);
writel_relaxed(addr, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_ADDR);
writel_relaxed(val, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_DATA);
}
void sirfsoc_rtc_iobrg_writel(u32 val, u32 addr)
{
unsigned long flags;
spin_lock_irqsave(&rtciobrg_lock, flags);
sirfsoc_rtc_iobrg_pre_writel(val, addr);
writel_relaxed(0x01, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_CTRL);
sirfsoc_rtc_iobrg_wait_sync();
spin_unlock_irqrestore(&rtciobrg_lock, flags);
}
static int __devinit sirfsoc_rtciobrg_probe(struct platform_device *op)
{
struct device_node *np = op->dev.of_node;
sirfsoc_rtciobrg_base = of_iomap(np, 0);
if (!sirfsoc_rtciobrg_base)
panic("unable to map rtc iobrg registers\n");
return 0;
}
static int __init sirfsoc_rtciobrg_init(void)
{
return platform_driver_register(&sirfsoc_rtciobrg_driver);
}
