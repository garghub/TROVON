static inline unsigned int ioready(void)
{
return readl(bus_status) & 1;
}
static inline void wait_ioready(void)
{
do { } while (!ioready());
}
static inline void wait_ioclear(void)
{
do { } while (ioready());
}
static inline void check_ioclear(void)
{
if (ioready()) {
pr_debug("ioclear: initially busy\n");
do {
(void) readl(bus_xfer);
DELAY();
} while (ioready());
pr_debug("ioclear: cleared busy\n");
}
}
u32 pic32_bus_readl(u32 reg)
{
unsigned long flags;
u32 status, val;
spin_lock_irqsave(&pic32_bus_lock, flags);
check_ioclear();
writel((PIC32_RD << 24) | (reg & 0x00ffffff), bus_xfer);
DELAY();
wait_ioready();
status = readl(bus_xfer);
DELAY();
val = readl(bus_xfer);
wait_ioclear();
pr_debug("pic32_bus_readl: *%x -> %x (status=%x)\n", reg, val, status);
spin_unlock_irqrestore(&pic32_bus_lock, flags);
return val;
}
void pic32_bus_writel(u32 val, u32 reg)
{
unsigned long flags;
u32 status;
spin_lock_irqsave(&pic32_bus_lock, flags);
check_ioclear();
writel((PIC32_WR << 24) | (reg & 0x00ffffff), bus_xfer);
DELAY();
writel(val, bus_xfer);
DELAY();
wait_ioready();
status = readl(bus_xfer);
wait_ioclear();
pr_debug("pic32_bus_writel: *%x <- %x (status=%x)\n", reg, val, status);
spin_unlock_irqrestore(&pic32_bus_lock, flags);
}
