static const char *dwc2_op_state_str(struct dwc2_hsotg *hsotg)
{
switch (hsotg->op_state) {
case OTG_STATE_A_HOST:
return "a_host";
case OTG_STATE_A_SUSPEND:
return "a_suspend";
case OTG_STATE_A_PERIPHERAL:
return "a_peripheral";
case OTG_STATE_B_PERIPHERAL:
return "b_peripheral";
case OTG_STATE_B_HOST:
return "b_host";
default:
return "unknown";
}
}
static void dwc2_handle_usb_port_intr(struct dwc2_hsotg *hsotg)
{
u32 hprt0 = dwc2_readl(hsotg->regs + HPRT0);
if (hprt0 & HPRT0_ENACHG) {
hprt0 &= ~HPRT0_ENA;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
}
dwc2_writel(GINTSTS_PRTINT, hsotg->regs + GINTSTS);
}
static void dwc2_handle_mode_mismatch_intr(struct dwc2_hsotg *hsotg)
{
dev_warn(hsotg->dev, "Mode Mismatch Interrupt: currently in %s mode\n",
dwc2_is_host_mode(hsotg) ? "Host" : "Device");
dwc2_writel(GINTSTS_MODEMIS, hsotg->regs + GINTSTS);
}
static void dwc2_handle_otg_intr(struct dwc2_hsotg *hsotg)
{
u32 gotgint;
u32 gotgctl;
u32 gintmsk;
gotgint = dwc2_readl(hsotg->regs + GOTGINT);
gotgctl = dwc2_readl(hsotg->regs + GOTGCTL);
dev_dbg(hsotg->dev, "++OTG Interrupt gotgint=%0x [%s]\n", gotgint,
dwc2_op_state_str(hsotg));
if (gotgint & GOTGINT_SES_END_DET) {
dev_dbg(hsotg->dev,
" ++OTG Interrupt: Session End Detected++ (%s)\n",
dwc2_op_state_str(hsotg));
gotgctl = dwc2_readl(hsotg->regs + GOTGCTL);
if (dwc2_is_device_mode(hsotg))
dwc2_hsotg_disconnect(hsotg);
if (hsotg->op_state == OTG_STATE_B_HOST) {
hsotg->op_state = OTG_STATE_B_PERIPHERAL;
} else {
if (gotgctl & GOTGCTL_DEVHNPEN) {
dev_dbg(hsotg->dev, "Session End Detected\n");
dev_err(hsotg->dev,
"Device Not Connected/Responding!\n");
}
hsotg->lx_state = DWC2_L0;
}
gotgctl = dwc2_readl(hsotg->regs + GOTGCTL);
gotgctl &= ~GOTGCTL_DEVHNPEN;
dwc2_writel(gotgctl, hsotg->regs + GOTGCTL);
}
if (gotgint & GOTGINT_SES_REQ_SUC_STS_CHNG) {
dev_dbg(hsotg->dev,
" ++OTG Interrupt: Session Request Success Status Change++\n");
gotgctl = dwc2_readl(hsotg->regs + GOTGCTL);
if (gotgctl & GOTGCTL_SESREQSCS) {
if (hsotg->core_params->phy_type ==
DWC2_PHY_TYPE_PARAM_FS
&& hsotg->core_params->i2c_enable > 0) {
hsotg->srp_success = 1;
} else {
gotgctl = dwc2_readl(hsotg->regs + GOTGCTL);
gotgctl &= ~GOTGCTL_SESREQ;
dwc2_writel(gotgctl, hsotg->regs + GOTGCTL);
}
}
}
if (gotgint & GOTGINT_HST_NEG_SUC_STS_CHNG) {
gotgctl = dwc2_readl(hsotg->regs + GOTGCTL);
if (hsotg->hw_params.snpsid >= DWC2_CORE_REV_3_00a)
udelay(100);
if (gotgctl & GOTGCTL_HSTNEGSCS) {
if (dwc2_is_host_mode(hsotg)) {
hsotg->op_state = OTG_STATE_B_HOST;
gintmsk = dwc2_readl(hsotg->regs + GINTMSK);
gintmsk &= ~GINTSTS_SOF;
dwc2_writel(gintmsk, hsotg->regs + GINTMSK);
spin_unlock(&hsotg->lock);
dwc2_hcd_start(hsotg);
spin_lock(&hsotg->lock);
hsotg->op_state = OTG_STATE_B_HOST;
}
} else {
gotgctl = dwc2_readl(hsotg->regs + GOTGCTL);
gotgctl &= ~(GOTGCTL_HNPREQ | GOTGCTL_DEVHNPEN);
dwc2_writel(gotgctl, hsotg->regs + GOTGCTL);
dev_dbg(hsotg->dev, "HNP Failed\n");
dev_err(hsotg->dev,
"Device Not Connected/Responding\n");
}
}
if (gotgint & GOTGINT_HST_NEG_DET) {
dev_dbg(hsotg->dev,
" ++OTG Interrupt: Host Negotiation Detected++ (%s)\n",
(dwc2_is_host_mode(hsotg) ? "Host" : "Device"));
if (dwc2_is_device_mode(hsotg)) {
dev_dbg(hsotg->dev, "a_suspend->a_peripheral (%d)\n",
hsotg->op_state);
spin_unlock(&hsotg->lock);
dwc2_hcd_disconnect(hsotg);
spin_lock(&hsotg->lock);
hsotg->op_state = OTG_STATE_A_PERIPHERAL;
} else {
gintmsk = dwc2_readl(hsotg->regs + GINTMSK);
gintmsk &= ~GINTSTS_SOF;
dwc2_writel(gintmsk, hsotg->regs + GINTMSK);
spin_unlock(&hsotg->lock);
dwc2_hcd_start(hsotg);
spin_lock(&hsotg->lock);
hsotg->op_state = OTG_STATE_A_HOST;
}
}
if (gotgint & GOTGINT_A_DEV_TOUT_CHG)
dev_dbg(hsotg->dev,
" ++OTG Interrupt: A-Device Timeout Change++\n");
if (gotgint & GOTGINT_DBNCE_DONE)
dev_dbg(hsotg->dev, " ++OTG Interrupt: Debounce Done++\n");
dwc2_writel(gotgint, hsotg->regs + GOTGINT);
}
static void dwc2_handle_conn_id_status_change_intr(struct dwc2_hsotg *hsotg)
{
u32 gintmsk = dwc2_readl(hsotg->regs + GINTMSK);
gintmsk &= ~GINTSTS_SOF;
dwc2_writel(gintmsk, hsotg->regs + GINTMSK);
dev_dbg(hsotg->dev, " ++Connector ID Status Change Interrupt++ (%s)\n",
dwc2_is_host_mode(hsotg) ? "Host" : "Device");
if (hsotg->wq_otg) {
spin_unlock(&hsotg->lock);
queue_work(hsotg->wq_otg, &hsotg->wf_otg);
spin_lock(&hsotg->lock);
}
dwc2_writel(GINTSTS_CONIDSTSCHNG, hsotg->regs + GINTSTS);
}
static void dwc2_handle_session_req_intr(struct dwc2_hsotg *hsotg)
{
int ret;
dev_dbg(hsotg->dev, "Session request interrupt - lx_state=%d\n",
hsotg->lx_state);
dwc2_writel(GINTSTS_SESSREQINT, hsotg->regs + GINTSTS);
if (dwc2_is_device_mode(hsotg)) {
if (hsotg->lx_state == DWC2_L2) {
ret = dwc2_exit_hibernation(hsotg, true);
if (ret && (ret != -ENOTSUPP))
dev_err(hsotg->dev,
"exit hibernation failed\n");
}
dwc2_hsotg_disconnect(hsotg);
}
}
static void dwc2_handle_wakeup_detected_intr(struct dwc2_hsotg *hsotg)
{
int ret;
dev_dbg(hsotg->dev, "++Resume or Remote Wakeup Detected Interrupt++\n");
dev_dbg(hsotg->dev, "%s lxstate = %d\n", __func__, hsotg->lx_state);
if (dwc2_is_device_mode(hsotg)) {
dev_dbg(hsotg->dev, "DSTS=0x%0x\n",
dwc2_readl(hsotg->regs + DSTS));
if (hsotg->lx_state == DWC2_L2) {
u32 dctl = dwc2_readl(hsotg->regs + DCTL);
dctl &= ~DCTL_RMTWKUPSIG;
dwc2_writel(dctl, hsotg->regs + DCTL);
ret = dwc2_exit_hibernation(hsotg, true);
if (ret && (ret != -ENOTSUPP))
dev_err(hsotg->dev, "exit hibernation failed\n");
call_gadget(hsotg, resume);
}
hsotg->lx_state = DWC2_L0;
} else {
if (hsotg->core_params->hibernation) {
dwc2_writel(GINTSTS_WKUPINT, hsotg->regs + GINTSTS);
return;
}
if (hsotg->lx_state != DWC2_L1) {
u32 pcgcctl = dwc2_readl(hsotg->regs + PCGCTL);
pcgcctl &= ~PCGCTL_STOPPCLK;
dwc2_writel(pcgcctl, hsotg->regs + PCGCTL);
mod_timer(&hsotg->wkp_timer,
jiffies + msecs_to_jiffies(71));
} else {
hsotg->lx_state = DWC2_L0;
}
}
dwc2_writel(GINTSTS_WKUPINT, hsotg->regs + GINTSTS);
}
static void dwc2_handle_disconnect_intr(struct dwc2_hsotg *hsotg)
{
dev_dbg(hsotg->dev, "++Disconnect Detected Interrupt++ (%s) %s\n",
dwc2_is_host_mode(hsotg) ? "Host" : "Device",
dwc2_op_state_str(hsotg));
if (hsotg->op_state == OTG_STATE_A_HOST)
dwc2_hcd_disconnect(hsotg);
dwc2_writel(GINTSTS_DISCONNINT, hsotg->regs + GINTSTS);
}
static void dwc2_handle_usb_suspend_intr(struct dwc2_hsotg *hsotg)
{
u32 dsts;
int ret;
dev_dbg(hsotg->dev, "USB SUSPEND\n");
if (dwc2_is_device_mode(hsotg)) {
dsts = dwc2_readl(hsotg->regs + DSTS);
dev_dbg(hsotg->dev, "DSTS=0x%0x\n", dsts);
dev_dbg(hsotg->dev,
"DSTS.Suspend Status=%d HWCFG4.Power Optimize=%d\n",
!!(dsts & DSTS_SUSPSTS),
hsotg->hw_params.power_optimized);
if ((dsts & DSTS_SUSPSTS) && hsotg->hw_params.power_optimized) {
if (!dwc2_is_device_connected(hsotg)) {
dev_dbg(hsotg->dev,
"ignore suspend request before enumeration\n");
goto clear_int;
}
ret = dwc2_enter_hibernation(hsotg);
if (ret) {
if (ret != -ENOTSUPP)
dev_err(hsotg->dev,
"enter hibernation failed\n");
goto skip_power_saving;
}
udelay(100);
if (!IS_ERR_OR_NULL(hsotg->uphy))
usb_phy_set_suspend(hsotg->uphy, true);
skip_power_saving:
hsotg->lx_state = DWC2_L2;
call_gadget(hsotg, suspend);
}
} else {
if (hsotg->op_state == OTG_STATE_A_PERIPHERAL) {
dev_dbg(hsotg->dev, "a_peripheral->a_host\n");
hsotg->lx_state = DWC2_L2;
spin_unlock(&hsotg->lock);
dwc2_hcd_start(hsotg);
spin_lock(&hsotg->lock);
hsotg->op_state = OTG_STATE_A_HOST;
}
}
clear_int:
dwc2_writel(GINTSTS_USBSUSP, hsotg->regs + GINTSTS);
}
static u32 dwc2_read_common_intr(struct dwc2_hsotg *hsotg)
{
u32 gintsts;
u32 gintmsk;
u32 gahbcfg;
u32 gintmsk_common = GINTMSK_COMMON;
gintsts = dwc2_readl(hsotg->regs + GINTSTS);
gintmsk = dwc2_readl(hsotg->regs + GINTMSK);
gahbcfg = dwc2_readl(hsotg->regs + GAHBCFG);
if (gintsts & gintmsk_common)
dev_dbg(hsotg->dev, "gintsts=%08x gintmsk=%08x\n",
gintsts, gintmsk);
if (gahbcfg & GAHBCFG_GLBL_INTR_EN)
return gintsts & gintmsk & gintmsk_common;
else
return 0;
}
irqreturn_t dwc2_handle_common_intr(int irq, void *dev)
{
struct dwc2_hsotg *hsotg = dev;
u32 gintsts;
irqreturn_t retval = IRQ_NONE;
spin_lock(&hsotg->lock);
if (!dwc2_is_controller_alive(hsotg)) {
dev_warn(hsotg->dev, "Controller is dead\n");
goto out;
}
gintsts = dwc2_read_common_intr(hsotg);
if (gintsts & ~GINTSTS_PRTINT)
retval = IRQ_HANDLED;
if (gintsts & GINTSTS_MODEMIS)
dwc2_handle_mode_mismatch_intr(hsotg);
if (gintsts & GINTSTS_OTGINT)
dwc2_handle_otg_intr(hsotg);
if (gintsts & GINTSTS_CONIDSTSCHNG)
dwc2_handle_conn_id_status_change_intr(hsotg);
if (gintsts & GINTSTS_DISCONNINT)
dwc2_handle_disconnect_intr(hsotg);
if (gintsts & GINTSTS_SESSREQINT)
dwc2_handle_session_req_intr(hsotg);
if (gintsts & GINTSTS_WKUPINT)
dwc2_handle_wakeup_detected_intr(hsotg);
if (gintsts & GINTSTS_USBSUSP)
dwc2_handle_usb_suspend_intr(hsotg);
if (gintsts & GINTSTS_PRTINT) {
if (dwc2_is_device_mode(hsotg)) {
dev_dbg(hsotg->dev,
" --Port interrupt received in Device mode--\n");
dwc2_handle_usb_port_intr(hsotg);
retval = IRQ_HANDLED;
}
}
out:
spin_unlock(&hsotg->lock);
return retval;
}
