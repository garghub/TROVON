static int ulpi_viewport_wait(void __iomem *view, u32 mask)
{
unsigned long usec = 2000;
while (usec--) {
if (!(readl(view) & mask))
return 0;
udelay(1);
};
return -ETIMEDOUT;
}
static int ulpi_viewport_read(struct usb_phy *otg, u32 reg)
{
int ret;
void __iomem *view = otg->io_priv;
writel(ULPI_VIEW_WAKEUP | ULPI_VIEW_WRITE, view);
ret = ulpi_viewport_wait(view, ULPI_VIEW_WAKEUP);
if (ret)
return ret;
writel(ULPI_VIEW_RUN | ULPI_VIEW_READ | ULPI_VIEW_ADDR(reg), view);
ret = ulpi_viewport_wait(view, ULPI_VIEW_RUN);
if (ret)
return ret;
return ULPI_VIEW_DATA_READ(readl(view));
}
static int ulpi_viewport_write(struct usb_phy *otg, u32 val, u32 reg)
{
int ret;
void __iomem *view = otg->io_priv;
writel(ULPI_VIEW_WAKEUP | ULPI_VIEW_WRITE, view);
ret = ulpi_viewport_wait(view, ULPI_VIEW_WAKEUP);
if (ret)
return ret;
writel(ULPI_VIEW_RUN | ULPI_VIEW_WRITE | ULPI_VIEW_DATA_WRITE(val) |
ULPI_VIEW_ADDR(reg), view);
return ulpi_viewport_wait(view, ULPI_VIEW_RUN);
}
