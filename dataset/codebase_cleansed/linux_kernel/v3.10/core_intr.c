static const char *dwc2_op_state_str(struct dwc2_hsotg *hsotg)
{
#ifdef DEBUG
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
#else
return "";
#endif
}
static void dwc2_handle_mode_mismatch_intr(struct dwc2_hsotg *hsotg)
{
dev_warn(hsotg->dev, "Mode Mismatch Interrupt: currently in %s mode\n",
dwc2_is_host_mode(hsotg) ? "Host" : "Device");
writel(GINTSTS_MODEMIS, hsotg->regs + GINTSTS);
}
static void dwc2_handle_otg_intr(struct dwc2_hsotg *hsotg)
{
u32 gotgint;
u32 gotgctl;
u32 gintmsk;
gotgint = readl(hsotg->regs + GOTGINT);
gotgctl = readl(hsotg->regs + GOTGCTL);
dev_dbg(hsotg->dev, "++OTG Interrupt gotgint=%0x [%s]\n", gotgint,
dwc2_op_state_str(hsotg));
if (gotgint & GOTGINT_SES_END_DET) {
dev_dbg(hsotg->dev,
" ++OTG Interrupt: Session End Detected++ (%s)\n",
dwc2_op_state_str(hsotg));
gotgctl = readl(hsotg->regs + GOTGCTL);
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
gotgctl = readl(hsotg->regs + GOTGCTL);
gotgctl &= ~GOTGCTL_DEVHNPEN;
writel(gotgctl, hsotg->regs + GOTGCTL);
}
if (gotgint & GOTGINT_SES_REQ_SUC_STS_CHNG) {
dev_dbg(hsotg->dev,
" ++OTG Interrupt: Session Request Success Status Change++\n");
gotgctl = readl(hsotg->regs + GOTGCTL);
if (gotgctl & GOTGCTL_SESREQSCS) {
if (hsotg->core_params->phy_type ==
DWC2_PHY_TYPE_PARAM_FS
&& hsotg->core_params->i2c_enable > 0) {
hsotg->srp_success = 1;
} else {
gotgctl = readl(hsotg->regs + GOTGCTL);
gotgctl &= ~GOTGCTL_SESREQ;
writel(gotgctl, hsotg->regs + GOTGCTL);
}
}
}
if (gotgint & GOTGINT_HST_NEG_SUC_STS_CHNG) {
gotgctl = readl(hsotg->regs + GOTGCTL);
if (hsotg->snpsid >= DWC2_CORE_REV_3_00a)
udelay(100);
if (gotgctl & GOTGCTL_HSTNEGSCS) {
if (dwc2_is_host_mode(hsotg)) {
hsotg->op_state = OTG_STATE_B_HOST;
gintmsk = readl(hsotg->regs + GINTMSK);
gintmsk &= ~GINTSTS_SOF;
writel(gintmsk, hsotg->regs + GINTMSK);
spin_unlock(&hsotg->lock);
dwc2_hcd_start(hsotg);
spin_lock(&hsotg->lock);
hsotg->op_state = OTG_STATE_B_HOST;
}
} else {
gotgctl = readl(hsotg->regs + GOTGCTL);
gotgctl &= ~(GOTGCTL_HNPREQ | GOTGCTL_DEVHNPEN);
writel(gotgctl, hsotg->regs + GOTGCTL);
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
gintmsk = readl(hsotg->regs + GINTMSK);
gintmsk &= ~GINTSTS_SOF;
writel(gintmsk, hsotg->regs + GINTMSK);
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
writel(gotgint, hsotg->regs + GOTGINT);
}
static void dwc2_handle_conn_id_status_change_intr(struct dwc2_hsotg *hsotg)
{
u32 gintmsk = readl(hsotg->regs + GINTMSK);
gintmsk &= ~GINTSTS_SOF;
writel(gintmsk, hsotg->regs + GINTMSK);
dev_dbg(hsotg->dev, " ++Connector ID Status Change Interrupt++ (%s)\n",
dwc2_is_host_mode(hsotg) ? "Host" : "Device");
spin_unlock(&hsotg->lock);
queue_work(hsotg->wq_otg, &hsotg->wf_otg);
spin_lock(&hsotg->lock);
writel(GINTSTS_CONIDSTSCHNG, hsotg->regs + GINTSTS);
}
static void dwc2_handle_session_req_intr(struct dwc2_hsotg *hsotg)
{
dev_dbg(hsotg->dev, "++Session Request Interrupt++\n");
writel(GINTSTS_SESSREQINT, hsotg->regs + GINTSTS);
}
static void dwc2_handle_wakeup_detected_intr(struct dwc2_hsotg *hsotg)
{
dev_dbg(hsotg->dev, "++Resume or Remote Wakeup Detected Interrupt++\n");
dev_dbg(hsotg->dev, "%s lxstate = %d\n", __func__, hsotg->lx_state);
if (dwc2_is_device_mode(hsotg)) {
dev_dbg(hsotg->dev, "DSTS=0x%0x\n", readl(hsotg->regs + DSTS));
if (hsotg->lx_state == DWC2_L2) {
u32 dctl = readl(hsotg->regs + DCTL);
dctl &= ~DCTL_RMTWKUPSIG;
writel(dctl, hsotg->regs + DCTL);
}
hsotg->lx_state = DWC2_L0;
} else {
if (hsotg->lx_state != DWC2_L1) {
u32 pcgcctl = readl(hsotg->regs + PCGCTL);
pcgcctl &= ~PCGCTL_STOPPCLK;
writel(pcgcctl, hsotg->regs + PCGCTL);
mod_timer(&hsotg->wkp_timer,
jiffies + msecs_to_jiffies(71));
} else {
hsotg->lx_state = DWC2_L0;
}
}
writel(GINTSTS_WKUPINT, hsotg->regs + GINTSTS);
}
static void dwc2_handle_disconnect_intr(struct dwc2_hsotg *hsotg)
{
dev_dbg(hsotg->dev, "++Disconnect Detected Interrupt++ (%s) %s\n",
dwc2_is_host_mode(hsotg) ? "Host" : "Device",
dwc2_op_state_str(hsotg));
hsotg->lx_state = DWC2_L3;
writel(GINTSTS_DISCONNINT, hsotg->regs + GINTSTS);
}
static void dwc2_handle_usb_suspend_intr(struct dwc2_hsotg *hsotg)
{
u32 dsts;
dev_dbg(hsotg->dev, "USB SUSPEND\n");
if (dwc2_is_device_mode(hsotg)) {
dsts = readl(hsotg->regs + DSTS);
dev_dbg(hsotg->dev, "DSTS=0x%0x\n", dsts);
dev_dbg(hsotg->dev,
"DSTS.Suspend Status=%d HWCFG4.Power Optimize=%d\n",
!!(dsts & DSTS_SUSPSTS),
!!(hsotg->hwcfg4 & GHWCFG4_POWER_OPTIMIZ));
} else {
if (hsotg->op_state == OTG_STATE_A_PERIPHERAL) {
dev_dbg(hsotg->dev, "a_peripheral->a_host\n");
spin_unlock(&hsotg->lock);
dwc2_hcd_start(hsotg);
spin_lock(&hsotg->lock);
hsotg->op_state = OTG_STATE_A_HOST;
}
}
hsotg->lx_state = DWC2_L2;
writel(GINTSTS_USBSUSP, hsotg->regs + GINTSTS);
}
static u32 dwc2_read_common_intr(struct dwc2_hsotg *hsotg)
{
u32 gintsts;
u32 gintmsk;
u32 gahbcfg;
u32 gintmsk_common = GINTMSK_COMMON;
gintsts = readl(hsotg->regs + GINTSTS);
gintmsk = readl(hsotg->regs + GINTMSK);
gahbcfg = readl(hsotg->regs + GAHBCFG);
#ifdef DEBUG
if (gintsts & gintmsk_common)
dev_dbg(hsotg->dev, "gintsts=%08x gintmsk=%08x\n",
gintsts, gintmsk);
#endif
if (gahbcfg & GAHBCFG_GLBL_INTR_EN)
return gintsts & gintmsk & gintmsk_common;
else
return 0;
}
irqreturn_t dwc2_handle_common_intr(int irq, void *dev)
{
struct dwc2_hsotg *hsotg = dev;
u32 gintsts;
int retval = 0;
if (dwc2_check_core_status(hsotg) < 0) {
dev_warn(hsotg->dev, "Controller is disconnected\n");
goto out;
}
spin_lock(&hsotg->lock);
gintsts = dwc2_read_common_intr(hsotg);
if (gintsts & ~GINTSTS_PRTINT)
retval = 1;
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
if (gintsts & GINTSTS_RESTOREDONE) {
gintsts = GINTSTS_RESTOREDONE;
writel(gintsts, hsotg->regs + GINTSTS);
dev_dbg(hsotg->dev, " --Restore done interrupt received--\n");
}
if (gintsts & GINTSTS_PRTINT) {
if (dwc2_is_device_mode(hsotg)) {
dev_dbg(hsotg->dev,
" --Port interrupt received in Device mode--\n");
gintsts = GINTSTS_PRTINT;
writel(gintsts, hsotg->regs + GINTSTS);
retval = 1;
}
}
spin_unlock(&hsotg->lock);
out:
return IRQ_RETVAL(retval);
}
