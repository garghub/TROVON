static bool bcma_wait_reg(struct bcma_bus *bus, void __iomem *addr, u32 mask,
u32 value, int timeout)
{
unsigned long deadline = jiffies + timeout;
u32 val;
do {
val = readl(addr);
if ((val & mask) == value)
return true;
cpu_relax();
udelay(10);
} while (!time_after_eq(jiffies, deadline));
bcma_err(bus, "Timeout waiting for register %p\n", addr);
return false;
}
void bcma_chipco_b_mii_write(struct bcma_drv_cc_b *ccb, u32 offset, u32 value)
{
struct bcma_bus *bus = ccb->core->bus;
writel(offset, ccb->mii + 0x00);
bcma_wait_reg(bus, ccb->mii + 0x00, 0x0100, 0x0000, 100);
writel(value, ccb->mii + 0x04);
bcma_wait_reg(bus, ccb->mii + 0x00, 0x0100, 0x0000, 100);
}
int bcma_core_chipcommon_b_init(struct bcma_drv_cc_b *ccb)
{
if (ccb->setup_done)
return 0;
ccb->setup_done = 1;
ccb->mii = ioremap_nocache(ccb->core->addr_s[1], BCMA_CORE_SIZE);
if (!ccb->mii)
return -ENOMEM;
return 0;
}
void bcma_core_chipcommon_b_free(struct bcma_drv_cc_b *ccb)
{
if (ccb->mii)
iounmap(ccb->mii);
}
