static int ulpi_poll(void __iomem *view, u32 bit)
{
int timeout = 10000;
while (timeout--) {
u32 data = __raw_readl(view);
if (!(data & bit))
return 0;
cpu_relax();
};
printk(KERN_WARNING "timeout polling for ULPI device\n");
return -ETIMEDOUT;
}
static int ulpi_read(struct usb_phy *otg, u32 reg)
{
int ret;
void __iomem *view = otg->io_priv;
if (!(__raw_readl(view) & ULPIVW_SS)) {
__raw_writel(ULPIVW_WU, view);
ret = ulpi_poll(view, ULPIVW_WU);
if (ret)
return ret;
}
__raw_writel((ULPIVW_RUN | (reg << ULPIVW_ADDR_SHIFT)), view);
ret = ulpi_poll(view, ULPIVW_RUN);
if (ret)
return ret;
return (__raw_readl(view) >> ULPIVW_RDATA_SHIFT) & ULPIVW_RDATA_MASK;
}
static int ulpi_write(struct usb_phy *otg, u32 val, u32 reg)
{
int ret;
void __iomem *view = otg->io_priv;
if (!(__raw_readl(view) & ULPIVW_SS)) {
__raw_writel(ULPIVW_WU, view);
ret = ulpi_poll(view, ULPIVW_WU);
if (ret)
return ret;
}
__raw_writel((ULPIVW_RUN | ULPIVW_WRITE |
(reg << ULPIVW_ADDR_SHIFT) |
((val & ULPIVW_WDATA_MASK) << ULPIVW_WDATA_SHIFT)), view);
return ulpi_poll(view, ULPIVW_RUN);
}
struct usb_phy *imx_otg_ulpi_create(unsigned int flags)
{
return otg_ulpi_create(&mxc_ulpi_access_ops, flags);
}
