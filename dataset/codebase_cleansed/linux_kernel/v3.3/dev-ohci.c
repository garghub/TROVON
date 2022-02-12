void __init exynos4_ohci_set_platdata(struct exynos4_ohci_platdata *pd)
{
struct exynos4_ohci_platdata *npd;
npd = s3c_set_platdata(pd, sizeof(struct exynos4_ohci_platdata),
&exynos4_device_ohci);
if (!npd->phy_init)
npd->phy_init = s5p_usb_phy_init;
if (!npd->phy_exit)
npd->phy_exit = s5p_usb_phy_exit;
}
