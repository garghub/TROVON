static int exynos4_dwmci_get_bus_wd(u32 slot_id)
{
return 4;
}
static int exynos4_dwmci_init(u32 slot_id, irq_handler_t handler, void *data)
{
return 0;
}
void __init exynos4_dwmci_set_platdata(struct dw_mci_board *pd)
{
struct dw_mci_board *npd;
npd = s3c_set_platdata(pd, sizeof(struct dw_mci_board),
&exynos4_device_dwmci);
if (!npd->init)
npd->init = exynos4_dwmci_init;
if (!npd->get_bus_wd)
npd->get_bus_wd = exynos4_dwmci_get_bus_wd;
}
