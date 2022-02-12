void __init s5p_ehci_set_platdata(struct s5p_ehci_platdata *pd)
{
struct s5p_ehci_platdata *npd;
npd = s3c_set_platdata(pd, sizeof(struct s5p_ehci_platdata),
&s5p_device_ehci);
if (!npd->phy_init)
npd->phy_init = s5p_usb_phy_init;
if (!npd->phy_exit)
npd->phy_exit = s5p_usb_phy_exit;
}
