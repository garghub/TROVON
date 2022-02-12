static irqreturn_t host_irq(struct ci_hdrc *ci)
{
return usb_hcd_irq(ci->irq, ci->hcd);
}
static int host_start(struct ci_hdrc *ci)
{
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
int ret;
if (usb_disabled())
return -ENODEV;
hcd = usb_create_hcd(&ci_ehci_hc_driver, ci->dev, dev_name(ci->dev));
if (!hcd)
return -ENOMEM;
dev_set_drvdata(ci->dev, ci);
hcd->rsrc_start = ci->hw_bank.phys;
hcd->rsrc_len = ci->hw_bank.size;
hcd->regs = ci->hw_bank.abs;
hcd->has_tt = 1;
hcd->power_budget = ci->platdata->power_budget;
hcd->usb_phy = ci->transceiver;
hcd->tpl_support = ci->platdata->tpl_support;
ehci = hcd_to_ehci(hcd);
ehci->caps = ci->hw_bank.cap;
ehci->has_hostpc = ci->hw_bank.lpm;
ehci->has_tdi_phy_lpm = ci->hw_bank.lpm;
ehci->imx28_write_fix = ci->imx28_write_fix;
if (ci->platdata->reg_vbus && !ci_otg_is_fsm_mode(ci)) {
ret = regulator_enable(ci->platdata->reg_vbus);
if (ret) {
dev_err(ci->dev,
"Failed to enable vbus regulator, ret=%d\n",
ret);
goto put_hcd;
}
}
ret = usb_add_hcd(hcd, 0, 0);
if (ret) {
goto disable_reg;
} else {
struct usb_otg *otg = ci->transceiver->otg;
ci->hcd = hcd;
if (otg) {
otg->host = &hcd->self;
hcd->self.otg_port = 1;
}
}
if (ci->platdata->flags & CI_HDRC_DISABLE_STREAMING)
hw_write(ci, OP_USBMODE, USBMODE_CI_SDIS, USBMODE_CI_SDIS);
return ret;
disable_reg:
if (ci->platdata->reg_vbus && !ci_otg_is_fsm_mode(ci))
regulator_disable(ci->platdata->reg_vbus);
put_hcd:
usb_put_hcd(hcd);
return ret;
}
static void host_stop(struct ci_hdrc *ci)
{
struct usb_hcd *hcd = ci->hcd;
if (hcd) {
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
if (ci->platdata->reg_vbus && !ci_otg_is_fsm_mode(ci))
regulator_disable(ci->platdata->reg_vbus);
}
}
void ci_hdrc_host_destroy(struct ci_hdrc *ci)
{
if (ci->role == CI_ROLE_HOST && ci->hcd)
host_stop(ci);
}
int ci_hdrc_host_init(struct ci_hdrc *ci)
{
struct ci_role_driver *rdrv;
if (!hw_read(ci, CAP_DCCPARAMS, DCCPARAMS_HC))
return -ENXIO;
rdrv = devm_kzalloc(ci->dev, sizeof(struct ci_role_driver), GFP_KERNEL);
if (!rdrv)
return -ENOMEM;
rdrv->start = host_start;
rdrv->stop = host_stop;
rdrv->irq = host_irq;
rdrv->name = "host";
ci->roles[CI_ROLE_HOST] = rdrv;
ehci_init_driver(&ci_ehci_hc_driver, NULL);
return 0;
}
