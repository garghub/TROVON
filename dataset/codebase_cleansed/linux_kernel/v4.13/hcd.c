static void dwc2_enable_common_interrupts(struct dwc2_hsotg *hsotg)
{
u32 intmsk;
dwc2_writel(0xffffffff, hsotg->regs + GOTGINT);
dwc2_writel(0xffffffff, hsotg->regs + GINTSTS);
intmsk = GINTSTS_MODEMIS | GINTSTS_OTGINT;
if (!hsotg->params.host_dma)
intmsk |= GINTSTS_RXFLVL;
if (!hsotg->params.external_id_pin_ctl)
intmsk |= GINTSTS_CONIDSTSCHNG;
intmsk |= GINTSTS_WKUPINT | GINTSTS_USBSUSP |
GINTSTS_SESSREQINT;
dwc2_writel(intmsk, hsotg->regs + GINTMSK);
}
static void dwc2_init_fs_ls_pclk_sel(struct dwc2_hsotg *hsotg)
{
u32 hcfg, val;
if ((hsotg->hw_params.hs_phy_type == GHWCFG2_HS_PHY_TYPE_ULPI &&
hsotg->hw_params.fs_phy_type == GHWCFG2_FS_PHY_TYPE_DEDICATED &&
hsotg->params.ulpi_fs_ls) ||
hsotg->params.phy_type == DWC2_PHY_TYPE_PARAM_FS) {
val = HCFG_FSLSPCLKSEL_48_MHZ;
} else {
val = HCFG_FSLSPCLKSEL_30_60_MHZ;
}
dev_dbg(hsotg->dev, "Initializing HCFG.FSLSPClkSel to %08x\n", val);
hcfg = dwc2_readl(hsotg->regs + HCFG);
hcfg &= ~HCFG_FSLSPCLKSEL_MASK;
hcfg |= val << HCFG_FSLSPCLKSEL_SHIFT;
dwc2_writel(hcfg, hsotg->regs + HCFG);
}
static int dwc2_fs_phy_init(struct dwc2_hsotg *hsotg, bool select_phy)
{
u32 usbcfg, ggpio, i2cctl;
int retval = 0;
if (select_phy) {
dev_dbg(hsotg->dev, "FS PHY selected\n");
usbcfg = dwc2_readl(hsotg->regs + GUSBCFG);
if (!(usbcfg & GUSBCFG_PHYSEL)) {
usbcfg |= GUSBCFG_PHYSEL;
dwc2_writel(usbcfg, hsotg->regs + GUSBCFG);
retval = dwc2_core_reset_and_force_dr_mode(hsotg);
if (retval) {
dev_err(hsotg->dev,
"%s: Reset failed, aborting", __func__);
return retval;
}
}
if (hsotg->params.activate_stm_fs_transceiver) {
ggpio = dwc2_readl(hsotg->regs + GGPIO);
if (!(ggpio & GGPIO_STM32_OTG_GCCFG_PWRDWN)) {
dev_dbg(hsotg->dev, "Activating transceiver\n");
ggpio |= GGPIO_STM32_OTG_GCCFG_PWRDWN;
dwc2_writel(ggpio, hsotg->regs + GGPIO);
}
}
}
if (dwc2_is_host_mode(hsotg))
dwc2_init_fs_ls_pclk_sel(hsotg);
if (hsotg->params.i2c_enable) {
dev_dbg(hsotg->dev, "FS PHY enabling I2C\n");
usbcfg = dwc2_readl(hsotg->regs + GUSBCFG);
usbcfg |= GUSBCFG_OTG_UTMI_FS_SEL;
dwc2_writel(usbcfg, hsotg->regs + GUSBCFG);
i2cctl = dwc2_readl(hsotg->regs + GI2CCTL);
i2cctl &= ~GI2CCTL_I2CDEVADDR_MASK;
i2cctl |= 1 << GI2CCTL_I2CDEVADDR_SHIFT;
i2cctl &= ~GI2CCTL_I2CEN;
dwc2_writel(i2cctl, hsotg->regs + GI2CCTL);
i2cctl |= GI2CCTL_I2CEN;
dwc2_writel(i2cctl, hsotg->regs + GI2CCTL);
}
return retval;
}
static int dwc2_hs_phy_init(struct dwc2_hsotg *hsotg, bool select_phy)
{
u32 usbcfg, usbcfg_old;
int retval = 0;
if (!select_phy)
return 0;
usbcfg = dwc2_readl(hsotg->regs + GUSBCFG);
usbcfg_old = usbcfg;
switch (hsotg->params.phy_type) {
case DWC2_PHY_TYPE_PARAM_ULPI:
dev_dbg(hsotg->dev, "HS ULPI PHY selected\n");
usbcfg |= GUSBCFG_ULPI_UTMI_SEL;
usbcfg &= ~(GUSBCFG_PHYIF16 | GUSBCFG_DDRSEL);
if (hsotg->params.phy_ulpi_ddr)
usbcfg |= GUSBCFG_DDRSEL;
break;
case DWC2_PHY_TYPE_PARAM_UTMI:
dev_dbg(hsotg->dev, "HS UTMI+ PHY selected\n");
usbcfg &= ~(GUSBCFG_ULPI_UTMI_SEL | GUSBCFG_PHYIF16);
if (hsotg->params.phy_utmi_width == 16)
usbcfg |= GUSBCFG_PHYIF16;
break;
default:
dev_err(hsotg->dev, "FS PHY selected at HS!\n");
break;
}
if (usbcfg != usbcfg_old) {
dwc2_writel(usbcfg, hsotg->regs + GUSBCFG);
retval = dwc2_core_reset_and_force_dr_mode(hsotg);
if (retval) {
dev_err(hsotg->dev,
"%s: Reset failed, aborting", __func__);
return retval;
}
}
return retval;
}
static int dwc2_phy_init(struct dwc2_hsotg *hsotg, bool select_phy)
{
u32 usbcfg;
int retval = 0;
if ((hsotg->params.speed == DWC2_SPEED_PARAM_FULL ||
hsotg->params.speed == DWC2_SPEED_PARAM_LOW) &&
hsotg->params.phy_type == DWC2_PHY_TYPE_PARAM_FS) {
retval = dwc2_fs_phy_init(hsotg, select_phy);
if (retval)
return retval;
} else {
retval = dwc2_hs_phy_init(hsotg, select_phy);
if (retval)
return retval;
}
if (hsotg->hw_params.hs_phy_type == GHWCFG2_HS_PHY_TYPE_ULPI &&
hsotg->hw_params.fs_phy_type == GHWCFG2_FS_PHY_TYPE_DEDICATED &&
hsotg->params.ulpi_fs_ls) {
dev_dbg(hsotg->dev, "Setting ULPI FSLS\n");
usbcfg = dwc2_readl(hsotg->regs + GUSBCFG);
usbcfg |= GUSBCFG_ULPI_FS_LS;
usbcfg |= GUSBCFG_ULPI_CLK_SUSP_M;
dwc2_writel(usbcfg, hsotg->regs + GUSBCFG);
} else {
usbcfg = dwc2_readl(hsotg->regs + GUSBCFG);
usbcfg &= ~GUSBCFG_ULPI_FS_LS;
usbcfg &= ~GUSBCFG_ULPI_CLK_SUSP_M;
dwc2_writel(usbcfg, hsotg->regs + GUSBCFG);
}
return retval;
}
static int dwc2_gahbcfg_init(struct dwc2_hsotg *hsotg)
{
u32 ahbcfg = dwc2_readl(hsotg->regs + GAHBCFG);
switch (hsotg->hw_params.arch) {
case GHWCFG2_EXT_DMA_ARCH:
dev_err(hsotg->dev, "External DMA Mode not supported\n");
return -EINVAL;
case GHWCFG2_INT_DMA_ARCH:
dev_dbg(hsotg->dev, "Internal DMA Mode\n");
if (hsotg->params.ahbcfg != -1) {
ahbcfg &= GAHBCFG_CTRL_MASK;
ahbcfg |= hsotg->params.ahbcfg &
~GAHBCFG_CTRL_MASK;
}
break;
case GHWCFG2_SLAVE_ONLY_ARCH:
default:
dev_dbg(hsotg->dev, "Slave Only Mode\n");
break;
}
dev_dbg(hsotg->dev, "host_dma:%d dma_desc_enable:%d\n",
hsotg->params.host_dma,
hsotg->params.dma_desc_enable);
if (hsotg->params.host_dma) {
if (hsotg->params.dma_desc_enable)
dev_dbg(hsotg->dev, "Using Descriptor DMA mode\n");
else
dev_dbg(hsotg->dev, "Using Buffer DMA mode\n");
} else {
dev_dbg(hsotg->dev, "Using Slave mode\n");
hsotg->params.dma_desc_enable = false;
}
if (hsotg->params.host_dma)
ahbcfg |= GAHBCFG_DMA_EN;
dwc2_writel(ahbcfg, hsotg->regs + GAHBCFG);
return 0;
}
static void dwc2_gusbcfg_init(struct dwc2_hsotg *hsotg)
{
u32 usbcfg;
usbcfg = dwc2_readl(hsotg->regs + GUSBCFG);
usbcfg &= ~(GUSBCFG_HNPCAP | GUSBCFG_SRPCAP);
switch (hsotg->hw_params.op_mode) {
case GHWCFG2_OP_MODE_HNP_SRP_CAPABLE:
if (hsotg->params.otg_cap ==
DWC2_CAP_PARAM_HNP_SRP_CAPABLE)
usbcfg |= GUSBCFG_HNPCAP;
if (hsotg->params.otg_cap !=
DWC2_CAP_PARAM_NO_HNP_SRP_CAPABLE)
usbcfg |= GUSBCFG_SRPCAP;
break;
case GHWCFG2_OP_MODE_SRP_ONLY_CAPABLE:
case GHWCFG2_OP_MODE_SRP_CAPABLE_DEVICE:
case GHWCFG2_OP_MODE_SRP_CAPABLE_HOST:
if (hsotg->params.otg_cap !=
DWC2_CAP_PARAM_NO_HNP_SRP_CAPABLE)
usbcfg |= GUSBCFG_SRPCAP;
break;
case GHWCFG2_OP_MODE_NO_HNP_SRP_CAPABLE:
case GHWCFG2_OP_MODE_NO_SRP_CAPABLE_DEVICE:
case GHWCFG2_OP_MODE_NO_SRP_CAPABLE_HOST:
default:
break;
}
dwc2_writel(usbcfg, hsotg->regs + GUSBCFG);
}
static void dwc2_enable_host_interrupts(struct dwc2_hsotg *hsotg)
{
u32 intmsk;
dev_dbg(hsotg->dev, "%s()\n", __func__);
dwc2_writel(0, hsotg->regs + GINTMSK);
dwc2_writel(0, hsotg->regs + HAINTMSK);
dwc2_enable_common_interrupts(hsotg);
intmsk = dwc2_readl(hsotg->regs + GINTMSK);
intmsk |= GINTSTS_DISCONNINT | GINTSTS_PRTINT | GINTSTS_HCHINT;
dwc2_writel(intmsk, hsotg->regs + GINTMSK);
}
static void dwc2_disable_host_interrupts(struct dwc2_hsotg *hsotg)
{
u32 intmsk = dwc2_readl(hsotg->regs + GINTMSK);
intmsk &= ~(GINTSTS_SOF | GINTSTS_PRTINT | GINTSTS_HCHINT |
GINTSTS_PTXFEMP | GINTSTS_NPTXFEMP | GINTSTS_DISCONNINT);
dwc2_writel(intmsk, hsotg->regs + GINTMSK);
}
static void dwc2_calculate_dynamic_fifo(struct dwc2_hsotg *hsotg)
{
struct dwc2_core_params *params = &hsotg->params;
struct dwc2_hw_params *hw = &hsotg->hw_params;
u32 rxfsiz, nptxfsiz, ptxfsiz, total_fifo_size;
total_fifo_size = hw->total_fifo_size;
rxfsiz = params->host_rx_fifo_size;
nptxfsiz = params->host_nperio_tx_fifo_size;
ptxfsiz = params->host_perio_tx_fifo_size;
if (total_fifo_size < (rxfsiz + nptxfsiz + ptxfsiz)) {
rxfsiz = 516 + hw->host_channels;
nptxfsiz = 256;
ptxfsiz = 768;
params->host_rx_fifo_size = rxfsiz;
params->host_nperio_tx_fifo_size = nptxfsiz;
params->host_perio_tx_fifo_size = ptxfsiz;
}
if (unlikely(total_fifo_size < (rxfsiz + nptxfsiz + ptxfsiz)))
dev_err(hsotg->dev, "invalid fifo sizes\n");
}
static void dwc2_config_fifos(struct dwc2_hsotg *hsotg)
{
struct dwc2_core_params *params = &hsotg->params;
u32 nptxfsiz, hptxfsiz, dfifocfg, grxfsiz;
if (!params->enable_dynamic_fifo)
return;
dwc2_calculate_dynamic_fifo(hsotg);
grxfsiz = dwc2_readl(hsotg->regs + GRXFSIZ);
dev_dbg(hsotg->dev, "initial grxfsiz=%08x\n", grxfsiz);
grxfsiz &= ~GRXFSIZ_DEPTH_MASK;
grxfsiz |= params->host_rx_fifo_size <<
GRXFSIZ_DEPTH_SHIFT & GRXFSIZ_DEPTH_MASK;
dwc2_writel(grxfsiz, hsotg->regs + GRXFSIZ);
dev_dbg(hsotg->dev, "new grxfsiz=%08x\n",
dwc2_readl(hsotg->regs + GRXFSIZ));
dev_dbg(hsotg->dev, "initial gnptxfsiz=%08x\n",
dwc2_readl(hsotg->regs + GNPTXFSIZ));
nptxfsiz = params->host_nperio_tx_fifo_size <<
FIFOSIZE_DEPTH_SHIFT & FIFOSIZE_DEPTH_MASK;
nptxfsiz |= params->host_rx_fifo_size <<
FIFOSIZE_STARTADDR_SHIFT & FIFOSIZE_STARTADDR_MASK;
dwc2_writel(nptxfsiz, hsotg->regs + GNPTXFSIZ);
dev_dbg(hsotg->dev, "new gnptxfsiz=%08x\n",
dwc2_readl(hsotg->regs + GNPTXFSIZ));
dev_dbg(hsotg->dev, "initial hptxfsiz=%08x\n",
dwc2_readl(hsotg->regs + HPTXFSIZ));
hptxfsiz = params->host_perio_tx_fifo_size <<
FIFOSIZE_DEPTH_SHIFT & FIFOSIZE_DEPTH_MASK;
hptxfsiz |= (params->host_rx_fifo_size +
params->host_nperio_tx_fifo_size) <<
FIFOSIZE_STARTADDR_SHIFT & FIFOSIZE_STARTADDR_MASK;
dwc2_writel(hptxfsiz, hsotg->regs + HPTXFSIZ);
dev_dbg(hsotg->dev, "new hptxfsiz=%08x\n",
dwc2_readl(hsotg->regs + HPTXFSIZ));
if (hsotg->params.en_multiple_tx_fifo &&
hsotg->hw_params.snpsid >= DWC2_CORE_REV_2_91a) {
dfifocfg = dwc2_readl(hsotg->regs + GDFIFOCFG);
dfifocfg &= ~GDFIFOCFG_EPINFOBASE_MASK;
dfifocfg |= (params->host_rx_fifo_size +
params->host_nperio_tx_fifo_size +
params->host_perio_tx_fifo_size) <<
GDFIFOCFG_EPINFOBASE_SHIFT &
GDFIFOCFG_EPINFOBASE_MASK;
dwc2_writel(dfifocfg, hsotg->regs + GDFIFOCFG);
}
}
u32 dwc2_calc_frame_interval(struct dwc2_hsotg *hsotg)
{
u32 usbcfg;
u32 hprt0;
int clock = 60;
usbcfg = dwc2_readl(hsotg->regs + GUSBCFG);
hprt0 = dwc2_readl(hsotg->regs + HPRT0);
if (!(usbcfg & GUSBCFG_PHYSEL) && (usbcfg & GUSBCFG_ULPI_UTMI_SEL) &&
!(usbcfg & GUSBCFG_PHYIF16))
clock = 60;
if ((usbcfg & GUSBCFG_PHYSEL) && hsotg->hw_params.fs_phy_type ==
GHWCFG2_FS_PHY_TYPE_SHARED_ULPI)
clock = 48;
if (!(usbcfg & GUSBCFG_PHY_LP_CLK_SEL) && !(usbcfg & GUSBCFG_PHYSEL) &&
!(usbcfg & GUSBCFG_ULPI_UTMI_SEL) && (usbcfg & GUSBCFG_PHYIF16))
clock = 30;
if (!(usbcfg & GUSBCFG_PHY_LP_CLK_SEL) && !(usbcfg & GUSBCFG_PHYSEL) &&
!(usbcfg & GUSBCFG_ULPI_UTMI_SEL) && !(usbcfg & GUSBCFG_PHYIF16))
clock = 60;
if ((usbcfg & GUSBCFG_PHY_LP_CLK_SEL) && !(usbcfg & GUSBCFG_PHYSEL) &&
!(usbcfg & GUSBCFG_ULPI_UTMI_SEL) && (usbcfg & GUSBCFG_PHYIF16))
clock = 48;
if ((usbcfg & GUSBCFG_PHYSEL) && !(usbcfg & GUSBCFG_PHYIF16) &&
hsotg->hw_params.fs_phy_type == GHWCFG2_FS_PHY_TYPE_SHARED_UTMI)
clock = 48;
if ((usbcfg & GUSBCFG_PHYSEL) &&
hsotg->hw_params.fs_phy_type == GHWCFG2_FS_PHY_TYPE_DEDICATED)
clock = 48;
if ((hprt0 & HPRT0_SPD_MASK) >> HPRT0_SPD_SHIFT == HPRT0_SPD_HIGH_SPEED)
return 125 * clock - 1;
return 1000 * clock - 1;
}
void dwc2_read_packet(struct dwc2_hsotg *hsotg, u8 *dest, u16 bytes)
{
u32 __iomem *fifo = hsotg->regs + HCFIFO(0);
u32 *data_buf = (u32 *)dest;
int word_count = (bytes + 3) / 4;
int i;
dev_vdbg(hsotg->dev, "%s(%p,%p,%d)\n", __func__, hsotg, dest, bytes);
for (i = 0; i < word_count; i++, data_buf++)
*data_buf = dwc2_readl(fifo);
}
static void dwc2_dump_channel_info(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan)
{
#ifdef VERBOSE_DEBUG
int num_channels = hsotg->params.host_channels;
struct dwc2_qh *qh;
u32 hcchar;
u32 hcsplt;
u32 hctsiz;
u32 hc_dma;
int i;
if (!chan)
return;
hcchar = dwc2_readl(hsotg->regs + HCCHAR(chan->hc_num));
hcsplt = dwc2_readl(hsotg->regs + HCSPLT(chan->hc_num));
hctsiz = dwc2_readl(hsotg->regs + HCTSIZ(chan->hc_num));
hc_dma = dwc2_readl(hsotg->regs + HCDMA(chan->hc_num));
dev_dbg(hsotg->dev, " Assigned to channel %p:\n", chan);
dev_dbg(hsotg->dev, " hcchar 0x%08x, hcsplt 0x%08x\n",
hcchar, hcsplt);
dev_dbg(hsotg->dev, " hctsiz 0x%08x, hc_dma 0x%08x\n",
hctsiz, hc_dma);
dev_dbg(hsotg->dev, " dev_addr: %d, ep_num: %d, ep_is_in: %d\n",
chan->dev_addr, chan->ep_num, chan->ep_is_in);
dev_dbg(hsotg->dev, " ep_type: %d\n", chan->ep_type);
dev_dbg(hsotg->dev, " max_packet: %d\n", chan->max_packet);
dev_dbg(hsotg->dev, " data_pid_start: %d\n", chan->data_pid_start);
dev_dbg(hsotg->dev, " xfer_started: %d\n", chan->xfer_started);
dev_dbg(hsotg->dev, " halt_status: %d\n", chan->halt_status);
dev_dbg(hsotg->dev, " xfer_buf: %p\n", chan->xfer_buf);
dev_dbg(hsotg->dev, " xfer_dma: %08lx\n",
(unsigned long)chan->xfer_dma);
dev_dbg(hsotg->dev, " xfer_len: %d\n", chan->xfer_len);
dev_dbg(hsotg->dev, " qh: %p\n", chan->qh);
dev_dbg(hsotg->dev, " NP inactive sched:\n");
list_for_each_entry(qh, &hsotg->non_periodic_sched_inactive,
qh_list_entry)
dev_dbg(hsotg->dev, " %p\n", qh);
dev_dbg(hsotg->dev, " NP active sched:\n");
list_for_each_entry(qh, &hsotg->non_periodic_sched_active,
qh_list_entry)
dev_dbg(hsotg->dev, " %p\n", qh);
dev_dbg(hsotg->dev, " Channels:\n");
for (i = 0; i < num_channels; i++) {
struct dwc2_host_chan *chan = hsotg->hc_ptr_array[i];
dev_dbg(hsotg->dev, " %2d: %p\n", i, chan);
}
#endif
}
static void dwc2_host_start(struct dwc2_hsotg *hsotg)
{
struct usb_hcd *hcd = dwc2_hsotg_to_hcd(hsotg);
hcd->self.is_b_host = dwc2_hcd_is_b_host(hsotg);
_dwc2_hcd_start(hcd);
}
static void dwc2_host_disconnect(struct dwc2_hsotg *hsotg)
{
struct usb_hcd *hcd = dwc2_hsotg_to_hcd(hsotg);
hcd->self.is_b_host = 0;
}
static void dwc2_host_hub_info(struct dwc2_hsotg *hsotg, void *context,
int *hub_addr, int *hub_port)
{
struct urb *urb = context;
if (urb->dev->tt)
*hub_addr = urb->dev->tt->hub->devnum;
else
*hub_addr = 0;
*hub_port = urb->dev->ttport;
}
static void dwc2_hc_enable_slave_ints(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan)
{
u32 hcintmsk = HCINTMSK_CHHLTD;
switch (chan->ep_type) {
case USB_ENDPOINT_XFER_CONTROL:
case USB_ENDPOINT_XFER_BULK:
dev_vdbg(hsotg->dev, "control/bulk\n");
hcintmsk |= HCINTMSK_XFERCOMPL;
hcintmsk |= HCINTMSK_STALL;
hcintmsk |= HCINTMSK_XACTERR;
hcintmsk |= HCINTMSK_DATATGLERR;
if (chan->ep_is_in) {
hcintmsk |= HCINTMSK_BBLERR;
} else {
hcintmsk |= HCINTMSK_NAK;
hcintmsk |= HCINTMSK_NYET;
if (chan->do_ping)
hcintmsk |= HCINTMSK_ACK;
}
if (chan->do_split) {
hcintmsk |= HCINTMSK_NAK;
if (chan->complete_split)
hcintmsk |= HCINTMSK_NYET;
else
hcintmsk |= HCINTMSK_ACK;
}
if (chan->error_state)
hcintmsk |= HCINTMSK_ACK;
break;
case USB_ENDPOINT_XFER_INT:
if (dbg_perio())
dev_vdbg(hsotg->dev, "intr\n");
hcintmsk |= HCINTMSK_XFERCOMPL;
hcintmsk |= HCINTMSK_NAK;
hcintmsk |= HCINTMSK_STALL;
hcintmsk |= HCINTMSK_XACTERR;
hcintmsk |= HCINTMSK_DATATGLERR;
hcintmsk |= HCINTMSK_FRMOVRUN;
if (chan->ep_is_in)
hcintmsk |= HCINTMSK_BBLERR;
if (chan->error_state)
hcintmsk |= HCINTMSK_ACK;
if (chan->do_split) {
if (chan->complete_split)
hcintmsk |= HCINTMSK_NYET;
else
hcintmsk |= HCINTMSK_ACK;
}
break;
case USB_ENDPOINT_XFER_ISOC:
if (dbg_perio())
dev_vdbg(hsotg->dev, "isoc\n");
hcintmsk |= HCINTMSK_XFERCOMPL;
hcintmsk |= HCINTMSK_FRMOVRUN;
hcintmsk |= HCINTMSK_ACK;
if (chan->ep_is_in) {
hcintmsk |= HCINTMSK_XACTERR;
hcintmsk |= HCINTMSK_BBLERR;
}
break;
default:
dev_err(hsotg->dev, "## Unknown EP type ##\n");
break;
}
dwc2_writel(hcintmsk, hsotg->regs + HCINTMSK(chan->hc_num));
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "set HCINTMSK to %08x\n", hcintmsk);
}
static void dwc2_hc_enable_dma_ints(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan)
{
u32 hcintmsk = HCINTMSK_CHHLTD;
if (!hsotg->params.dma_desc_enable) {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "desc DMA disabled\n");
hcintmsk |= HCINTMSK_AHBERR;
} else {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "desc DMA enabled\n");
if (chan->ep_type == USB_ENDPOINT_XFER_ISOC)
hcintmsk |= HCINTMSK_XFERCOMPL;
}
if (chan->error_state && !chan->do_split &&
chan->ep_type != USB_ENDPOINT_XFER_ISOC) {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "setting ACK\n");
hcintmsk |= HCINTMSK_ACK;
if (chan->ep_is_in) {
hcintmsk |= HCINTMSK_DATATGLERR;
if (chan->ep_type != USB_ENDPOINT_XFER_INT)
hcintmsk |= HCINTMSK_NAK;
}
}
dwc2_writel(hcintmsk, hsotg->regs + HCINTMSK(chan->hc_num));
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "set HCINTMSK to %08x\n", hcintmsk);
}
static void dwc2_hc_enable_ints(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan)
{
u32 intmsk;
if (hsotg->params.host_dma) {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "DMA enabled\n");
dwc2_hc_enable_dma_ints(hsotg, chan);
} else {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "DMA disabled\n");
dwc2_hc_enable_slave_ints(hsotg, chan);
}
intmsk = dwc2_readl(hsotg->regs + HAINTMSK);
intmsk |= 1 << chan->hc_num;
dwc2_writel(intmsk, hsotg->regs + HAINTMSK);
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "set HAINTMSK to %08x\n", intmsk);
intmsk = dwc2_readl(hsotg->regs + GINTMSK);
intmsk |= GINTSTS_HCHINT;
dwc2_writel(intmsk, hsotg->regs + GINTMSK);
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "set GINTMSK to %08x\n", intmsk);
}
static void dwc2_hc_init(struct dwc2_hsotg *hsotg, struct dwc2_host_chan *chan)
{
u8 hc_num = chan->hc_num;
u32 hcintmsk;
u32 hcchar;
u32 hcsplt = 0;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "%s()\n", __func__);
hcintmsk = 0xffffffff;
hcintmsk &= ~HCINTMSK_RESERVED14_31;
dwc2_writel(hcintmsk, hsotg->regs + HCINT(hc_num));
dwc2_hc_enable_ints(hsotg, chan);
hcchar = chan->dev_addr << HCCHAR_DEVADDR_SHIFT & HCCHAR_DEVADDR_MASK;
hcchar |= chan->ep_num << HCCHAR_EPNUM_SHIFT & HCCHAR_EPNUM_MASK;
if (chan->ep_is_in)
hcchar |= HCCHAR_EPDIR;
if (chan->speed == USB_SPEED_LOW)
hcchar |= HCCHAR_LSPDDEV;
hcchar |= chan->ep_type << HCCHAR_EPTYPE_SHIFT & HCCHAR_EPTYPE_MASK;
hcchar |= chan->max_packet << HCCHAR_MPS_SHIFT & HCCHAR_MPS_MASK;
dwc2_writel(hcchar, hsotg->regs + HCCHAR(hc_num));
if (dbg_hc(chan)) {
dev_vdbg(hsotg->dev, "set HCCHAR(%d) to %08x\n",
hc_num, hcchar);
dev_vdbg(hsotg->dev, "%s: Channel %d\n",
__func__, hc_num);
dev_vdbg(hsotg->dev, " Dev Addr: %d\n",
chan->dev_addr);
dev_vdbg(hsotg->dev, " Ep Num: %d\n",
chan->ep_num);
dev_vdbg(hsotg->dev, " Is In: %d\n",
chan->ep_is_in);
dev_vdbg(hsotg->dev, " Is Low Speed: %d\n",
chan->speed == USB_SPEED_LOW);
dev_vdbg(hsotg->dev, " Ep Type: %d\n",
chan->ep_type);
dev_vdbg(hsotg->dev, " Max Pkt: %d\n",
chan->max_packet);
}
if (chan->do_split) {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev,
"Programming HC %d with split --> %s\n",
hc_num,
chan->complete_split ? "CSPLIT" : "SSPLIT");
if (chan->complete_split)
hcsplt |= HCSPLT_COMPSPLT;
hcsplt |= chan->xact_pos << HCSPLT_XACTPOS_SHIFT &
HCSPLT_XACTPOS_MASK;
hcsplt |= chan->hub_addr << HCSPLT_HUBADDR_SHIFT &
HCSPLT_HUBADDR_MASK;
hcsplt |= chan->hub_port << HCSPLT_PRTADDR_SHIFT &
HCSPLT_PRTADDR_MASK;
if (dbg_hc(chan)) {
dev_vdbg(hsotg->dev, " comp split %d\n",
chan->complete_split);
dev_vdbg(hsotg->dev, " xact pos %d\n",
chan->xact_pos);
dev_vdbg(hsotg->dev, " hub addr %d\n",
chan->hub_addr);
dev_vdbg(hsotg->dev, " hub port %d\n",
chan->hub_port);
dev_vdbg(hsotg->dev, " is_in %d\n",
chan->ep_is_in);
dev_vdbg(hsotg->dev, " Max Pkt %d\n",
chan->max_packet);
dev_vdbg(hsotg->dev, " xferlen %d\n",
chan->xfer_len);
}
}
dwc2_writel(hcsplt, hsotg->regs + HCSPLT(hc_num));
}
void dwc2_hc_halt(struct dwc2_hsotg *hsotg, struct dwc2_host_chan *chan,
enum dwc2_halt_status halt_status)
{
u32 nptxsts, hptxsts, hcchar;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "%s()\n", __func__);
if (halt_status == DWC2_HC_XFER_NO_HALT_STATUS)
dev_err(hsotg->dev, "!!! halt_status = %d !!!\n", halt_status);
if (halt_status == DWC2_HC_XFER_URB_DEQUEUE ||
halt_status == DWC2_HC_XFER_AHB_ERR) {
u32 hcintmsk = HCINTMSK_CHHLTD;
dev_vdbg(hsotg->dev, "dequeue/error\n");
dwc2_writel(hcintmsk, hsotg->regs + HCINTMSK(chan->hc_num));
dwc2_writel(~hcintmsk, hsotg->regs + HCINT(chan->hc_num));
chan->halt_status = halt_status;
hcchar = dwc2_readl(hsotg->regs + HCCHAR(chan->hc_num));
if (!(hcchar & HCCHAR_CHENA)) {
return;
}
}
if (chan->halt_pending) {
dev_vdbg(hsotg->dev,
"*** %s: Channel %d, chan->halt_pending already set ***\n",
__func__, chan->hc_num);
return;
}
hcchar = dwc2_readl(hsotg->regs + HCCHAR(chan->hc_num));
if (!hsotg->params.dma_desc_enable) {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "desc DMA disabled\n");
hcchar |= HCCHAR_CHENA;
} else {
if (dbg_hc(chan))
dev_dbg(hsotg->dev, "desc DMA enabled\n");
}
hcchar |= HCCHAR_CHDIS;
if (!hsotg->params.host_dma) {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "DMA not enabled\n");
hcchar |= HCCHAR_CHENA;
if (chan->ep_type == USB_ENDPOINT_XFER_CONTROL ||
chan->ep_type == USB_ENDPOINT_XFER_BULK) {
dev_vdbg(hsotg->dev, "control/bulk\n");
nptxsts = dwc2_readl(hsotg->regs + GNPTXSTS);
if ((nptxsts & TXSTS_QSPCAVAIL_MASK) == 0) {
dev_vdbg(hsotg->dev, "Disabling channel\n");
hcchar &= ~HCCHAR_CHENA;
}
} else {
if (dbg_perio())
dev_vdbg(hsotg->dev, "isoc/intr\n");
hptxsts = dwc2_readl(hsotg->regs + HPTXSTS);
if ((hptxsts & TXSTS_QSPCAVAIL_MASK) == 0 ||
hsotg->queuing_high_bandwidth) {
if (dbg_perio())
dev_vdbg(hsotg->dev, "Disabling channel\n");
hcchar &= ~HCCHAR_CHENA;
}
}
} else {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "DMA enabled\n");
}
dwc2_writel(hcchar, hsotg->regs + HCCHAR(chan->hc_num));
chan->halt_status = halt_status;
if (hcchar & HCCHAR_CHENA) {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "Channel enabled\n");
chan->halt_pending = 1;
chan->halt_on_queue = 0;
} else {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "Channel disabled\n");
chan->halt_on_queue = 1;
}
if (dbg_hc(chan)) {
dev_vdbg(hsotg->dev, "%s: Channel %d\n", __func__,
chan->hc_num);
dev_vdbg(hsotg->dev, " hcchar: 0x%08x\n",
hcchar);
dev_vdbg(hsotg->dev, " halt_pending: %d\n",
chan->halt_pending);
dev_vdbg(hsotg->dev, " halt_on_queue: %d\n",
chan->halt_on_queue);
dev_vdbg(hsotg->dev, " halt_status: %d\n",
chan->halt_status);
}
}
void dwc2_hc_cleanup(struct dwc2_hsotg *hsotg, struct dwc2_host_chan *chan)
{
u32 hcintmsk;
chan->xfer_started = 0;
list_del_init(&chan->split_order_list_entry);
dwc2_writel(0, hsotg->regs + HCINTMSK(chan->hc_num));
hcintmsk = 0xffffffff;
hcintmsk &= ~HCINTMSK_RESERVED14_31;
dwc2_writel(hcintmsk, hsotg->regs + HCINT(chan->hc_num));
}
static void dwc2_hc_set_even_odd_frame(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, u32 *hcchar)
{
if (chan->ep_type == USB_ENDPOINT_XFER_INT ||
chan->ep_type == USB_ENDPOINT_XFER_ISOC) {
int host_speed;
int xfer_ns;
int xfer_us;
int bytes_in_fifo;
u16 fifo_space;
u16 frame_number;
u16 wire_frame;
host_speed = (chan->speed != USB_SPEED_HIGH &&
!chan->do_split) ? chan->speed : USB_SPEED_HIGH;
fifo_space = (dwc2_readl(hsotg->regs + HPTXSTS) &
TXSTS_FSPCAVAIL_MASK) >> TXSTS_FSPCAVAIL_SHIFT;
bytes_in_fifo = sizeof(u32) *
(hsotg->params.host_perio_tx_fifo_size -
fifo_space);
xfer_ns = usb_calc_bus_time(host_speed, false, false,
chan->xfer_len + bytes_in_fifo);
xfer_us = NS_TO_US(xfer_ns);
frame_number = dwc2_hcd_get_future_frame_number(hsotg, xfer_us);
wire_frame = dwc2_frame_num_inc(chan->qh->next_active_frame, 1);
if (dwc2_frame_num_gt(frame_number, wire_frame)) {
dwc2_sch_vdbg(hsotg,
"QH=%p EO MISS fr=%04x=>%04x (%+d)\n",
chan->qh, wire_frame, frame_number,
dwc2_frame_num_dec(frame_number,
wire_frame));
wire_frame = frame_number;
chan->qh->next_active_frame =
dwc2_frame_num_dec(frame_number, 1);
}
if (wire_frame & 1)
*hcchar |= HCCHAR_ODDFRM;
else
*hcchar &= ~HCCHAR_ODDFRM;
}
}
static void dwc2_set_pid_isoc(struct dwc2_host_chan *chan)
{
if (chan->speed == USB_SPEED_HIGH) {
if (chan->ep_is_in) {
if (chan->multi_count == 1)
chan->data_pid_start = DWC2_HC_PID_DATA0;
else if (chan->multi_count == 2)
chan->data_pid_start = DWC2_HC_PID_DATA1;
else
chan->data_pid_start = DWC2_HC_PID_DATA2;
} else {
if (chan->multi_count == 1)
chan->data_pid_start = DWC2_HC_PID_DATA0;
else
chan->data_pid_start = DWC2_HC_PID_MDATA;
}
} else {
chan->data_pid_start = DWC2_HC_PID_DATA0;
}
}
static void dwc2_hc_write_packet(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan)
{
u32 i;
u32 remaining_count;
u32 byte_count;
u32 dword_count;
u32 __iomem *data_fifo;
u32 *data_buf = (u32 *)chan->xfer_buf;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "%s()\n", __func__);
data_fifo = (u32 __iomem *)(hsotg->regs + HCFIFO(chan->hc_num));
remaining_count = chan->xfer_len - chan->xfer_count;
if (remaining_count > chan->max_packet)
byte_count = chan->max_packet;
else
byte_count = remaining_count;
dword_count = (byte_count + 3) / 4;
if (((unsigned long)data_buf & 0x3) == 0) {
for (i = 0; i < dword_count; i++, data_buf++)
dwc2_writel(*data_buf, data_fifo);
} else {
for (i = 0; i < dword_count; i++, data_buf++) {
u32 data = data_buf[0] | data_buf[1] << 8 |
data_buf[2] << 16 | data_buf[3] << 24;
dwc2_writel(data, data_fifo);
}
}
chan->xfer_count += byte_count;
chan->xfer_buf += byte_count;
}
static void dwc2_hc_do_ping(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan)
{
u32 hcchar;
u32 hctsiz;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "%s: Channel %d\n", __func__,
chan->hc_num);
hctsiz = TSIZ_DOPNG;
hctsiz |= 1 << TSIZ_PKTCNT_SHIFT;
dwc2_writel(hctsiz, hsotg->regs + HCTSIZ(chan->hc_num));
hcchar = dwc2_readl(hsotg->regs + HCCHAR(chan->hc_num));
hcchar |= HCCHAR_CHENA;
hcchar &= ~HCCHAR_CHDIS;
dwc2_writel(hcchar, hsotg->regs + HCCHAR(chan->hc_num));
}
static void dwc2_hc_start_transfer(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan)
{
u32 max_hc_xfer_size = hsotg->params.max_transfer_size;
u16 max_hc_pkt_count = hsotg->params.max_packet_count;
u32 hcchar;
u32 hctsiz = 0;
u16 num_packets;
u32 ec_mc;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "%s()\n", __func__);
if (chan->do_ping) {
if (!hsotg->params.host_dma) {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "ping, no DMA\n");
dwc2_hc_do_ping(hsotg, chan);
chan->xfer_started = 1;
return;
}
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "ping, DMA\n");
hctsiz |= TSIZ_DOPNG;
}
if (chan->do_split) {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "split\n");
num_packets = 1;
if (chan->complete_split && !chan->ep_is_in)
chan->xfer_len = 0;
else if (chan->ep_is_in || chan->xfer_len > chan->max_packet)
chan->xfer_len = chan->max_packet;
else if (!chan->ep_is_in && chan->xfer_len > 188)
chan->xfer_len = 188;
hctsiz |= chan->xfer_len << TSIZ_XFERSIZE_SHIFT &
TSIZ_XFERSIZE_MASK;
if (chan->ep_type == USB_ENDPOINT_XFER_INT ||
chan->ep_type == USB_ENDPOINT_XFER_ISOC)
ec_mc = 3;
else
ec_mc = 1;
} else {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "no split\n");
if (chan->ep_type == USB_ENDPOINT_XFER_INT ||
chan->ep_type == USB_ENDPOINT_XFER_ISOC) {
u32 max_periodic_len =
chan->multi_count * chan->max_packet;
if (chan->xfer_len > max_periodic_len)
chan->xfer_len = max_periodic_len;
} else if (chan->xfer_len > max_hc_xfer_size) {
chan->xfer_len =
max_hc_xfer_size - chan->max_packet + 1;
}
if (chan->xfer_len > 0) {
num_packets = (chan->xfer_len + chan->max_packet - 1) /
chan->max_packet;
if (num_packets > max_hc_pkt_count) {
num_packets = max_hc_pkt_count;
chan->xfer_len = num_packets * chan->max_packet;
}
} else {
num_packets = 1;
}
if (chan->ep_is_in)
chan->xfer_len = num_packets * chan->max_packet;
if (chan->ep_type == USB_ENDPOINT_XFER_INT ||
chan->ep_type == USB_ENDPOINT_XFER_ISOC)
chan->multi_count = num_packets;
if (chan->ep_type == USB_ENDPOINT_XFER_ISOC)
dwc2_set_pid_isoc(chan);
hctsiz |= chan->xfer_len << TSIZ_XFERSIZE_SHIFT &
TSIZ_XFERSIZE_MASK;
ec_mc = chan->multi_count;
}
chan->start_pkt_count = num_packets;
hctsiz |= num_packets << TSIZ_PKTCNT_SHIFT & TSIZ_PKTCNT_MASK;
hctsiz |= chan->data_pid_start << TSIZ_SC_MC_PID_SHIFT &
TSIZ_SC_MC_PID_MASK;
dwc2_writel(hctsiz, hsotg->regs + HCTSIZ(chan->hc_num));
if (dbg_hc(chan)) {
dev_vdbg(hsotg->dev, "Wrote %08x to HCTSIZ(%d)\n",
hctsiz, chan->hc_num);
dev_vdbg(hsotg->dev, "%s: Channel %d\n", __func__,
chan->hc_num);
dev_vdbg(hsotg->dev, " Xfer Size: %d\n",
(hctsiz & TSIZ_XFERSIZE_MASK) >>
TSIZ_XFERSIZE_SHIFT);
dev_vdbg(hsotg->dev, " Num Pkts: %d\n",
(hctsiz & TSIZ_PKTCNT_MASK) >>
TSIZ_PKTCNT_SHIFT);
dev_vdbg(hsotg->dev, " Start PID: %d\n",
(hctsiz & TSIZ_SC_MC_PID_MASK) >>
TSIZ_SC_MC_PID_SHIFT);
}
if (hsotg->params.host_dma) {
dwc2_writel((u32)chan->xfer_dma,
hsotg->regs + HCDMA(chan->hc_num));
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "Wrote %08lx to HCDMA(%d)\n",
(unsigned long)chan->xfer_dma, chan->hc_num);
}
if (chan->do_split) {
u32 hcsplt = dwc2_readl(hsotg->regs + HCSPLT(chan->hc_num));
hcsplt |= HCSPLT_SPLTENA;
dwc2_writel(hcsplt, hsotg->regs + HCSPLT(chan->hc_num));
}
hcchar = dwc2_readl(hsotg->regs + HCCHAR(chan->hc_num));
hcchar &= ~HCCHAR_MULTICNT_MASK;
hcchar |= (ec_mc << HCCHAR_MULTICNT_SHIFT) & HCCHAR_MULTICNT_MASK;
dwc2_hc_set_even_odd_frame(hsotg, chan, &hcchar);
if (hcchar & HCCHAR_CHDIS)
dev_warn(hsotg->dev,
"%s: chdis set, channel %d, hcchar 0x%08x\n",
__func__, chan->hc_num, hcchar);
hcchar |= HCCHAR_CHENA;
hcchar &= ~HCCHAR_CHDIS;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, " Multi Cnt: %d\n",
(hcchar & HCCHAR_MULTICNT_MASK) >>
HCCHAR_MULTICNT_SHIFT);
dwc2_writel(hcchar, hsotg->regs + HCCHAR(chan->hc_num));
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "Wrote %08x to HCCHAR(%d)\n", hcchar,
chan->hc_num);
chan->xfer_started = 1;
chan->requests++;
if (!hsotg->params.host_dma &&
!chan->ep_is_in && chan->xfer_len > 0)
dwc2_hc_write_packet(hsotg, chan);
}
void dwc2_hc_start_transfer_ddma(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan)
{
u32 hcchar;
u32 hctsiz = 0;
if (chan->do_ping)
hctsiz |= TSIZ_DOPNG;
if (chan->ep_type == USB_ENDPOINT_XFER_ISOC)
dwc2_set_pid_isoc(chan);
hctsiz |= chan->data_pid_start << TSIZ_SC_MC_PID_SHIFT &
TSIZ_SC_MC_PID_MASK;
hctsiz |= (chan->ntd - 1) << TSIZ_NTD_SHIFT & TSIZ_NTD_MASK;
hctsiz |= chan->schinfo << TSIZ_SCHINFO_SHIFT & TSIZ_SCHINFO_MASK;
if (dbg_hc(chan)) {
dev_vdbg(hsotg->dev, "%s: Channel %d\n", __func__,
chan->hc_num);
dev_vdbg(hsotg->dev, " Start PID: %d\n",
chan->data_pid_start);
dev_vdbg(hsotg->dev, " NTD: %d\n", chan->ntd - 1);
}
dwc2_writel(hctsiz, hsotg->regs + HCTSIZ(chan->hc_num));
dma_sync_single_for_device(hsotg->dev, chan->desc_list_addr,
chan->desc_list_sz, DMA_TO_DEVICE);
dwc2_writel(chan->desc_list_addr, hsotg->regs + HCDMA(chan->hc_num));
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "Wrote %pad to HCDMA(%d)\n",
&chan->desc_list_addr, chan->hc_num);
hcchar = dwc2_readl(hsotg->regs + HCCHAR(chan->hc_num));
hcchar &= ~HCCHAR_MULTICNT_MASK;
hcchar |= chan->multi_count << HCCHAR_MULTICNT_SHIFT &
HCCHAR_MULTICNT_MASK;
if (hcchar & HCCHAR_CHDIS)
dev_warn(hsotg->dev,
"%s: chdis set, channel %d, hcchar 0x%08x\n",
__func__, chan->hc_num, hcchar);
hcchar |= HCCHAR_CHENA;
hcchar &= ~HCCHAR_CHDIS;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, " Multi Cnt: %d\n",
(hcchar & HCCHAR_MULTICNT_MASK) >>
HCCHAR_MULTICNT_SHIFT);
dwc2_writel(hcchar, hsotg->regs + HCCHAR(chan->hc_num));
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "Wrote %08x to HCCHAR(%d)\n", hcchar,
chan->hc_num);
chan->xfer_started = 1;
chan->requests++;
}
static int dwc2_hc_continue_transfer(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan)
{
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "%s: Channel %d\n", __func__,
chan->hc_num);
if (chan->do_split)
return 0;
if (chan->data_pid_start == DWC2_HC_PID_SETUP)
return 0;
if (chan->ep_is_in) {
u32 hcchar = dwc2_readl(hsotg->regs + HCCHAR(chan->hc_num));
dwc2_hc_set_even_odd_frame(hsotg, chan, &hcchar);
hcchar |= HCCHAR_CHENA;
hcchar &= ~HCCHAR_CHDIS;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, " IN xfer: hcchar = 0x%08x\n",
hcchar);
dwc2_writel(hcchar, hsotg->regs + HCCHAR(chan->hc_num));
chan->requests++;
return 1;
}
if (chan->xfer_count < chan->xfer_len) {
if (chan->ep_type == USB_ENDPOINT_XFER_INT ||
chan->ep_type == USB_ENDPOINT_XFER_ISOC) {
u32 hcchar = dwc2_readl(hsotg->regs +
HCCHAR(chan->hc_num));
dwc2_hc_set_even_odd_frame(hsotg, chan,
&hcchar);
}
dwc2_hc_write_packet(hsotg, chan);
chan->requests++;
return 1;
}
return 0;
}
static void dwc2_kill_urbs_in_qh_list(struct dwc2_hsotg *hsotg,
struct list_head *qh_list)
{
struct dwc2_qh *qh, *qh_tmp;
struct dwc2_qtd *qtd, *qtd_tmp;
list_for_each_entry_safe(qh, qh_tmp, qh_list, qh_list_entry) {
list_for_each_entry_safe(qtd, qtd_tmp, &qh->qtd_list,
qtd_list_entry) {
dwc2_host_complete(hsotg, qtd, -ECONNRESET);
dwc2_hcd_qtd_unlink_and_free(hsotg, qtd, qh);
}
}
}
static void dwc2_qh_list_free(struct dwc2_hsotg *hsotg,
struct list_head *qh_list)
{
struct dwc2_qtd *qtd, *qtd_tmp;
struct dwc2_qh *qh, *qh_tmp;
unsigned long flags;
if (!qh_list->next)
return;
spin_lock_irqsave(&hsotg->lock, flags);
dwc2_kill_urbs_in_qh_list(hsotg, qh_list);
list_for_each_entry_safe(qh, qh_tmp, qh_list, qh_list_entry) {
dwc2_hcd_qh_unlink(hsotg, qh);
list_for_each_entry_safe(qtd, qtd_tmp, &qh->qtd_list,
qtd_list_entry)
dwc2_hcd_qtd_unlink_and_free(hsotg, qtd, qh);
if (qh->channel && qh->channel->qh == qh)
qh->channel->qh = NULL;
spin_unlock_irqrestore(&hsotg->lock, flags);
dwc2_hcd_qh_free(hsotg, qh);
spin_lock_irqsave(&hsotg->lock, flags);
}
spin_unlock_irqrestore(&hsotg->lock, flags);
}
static void dwc2_kill_all_urbs(struct dwc2_hsotg *hsotg)
{
dwc2_kill_urbs_in_qh_list(hsotg, &hsotg->non_periodic_sched_inactive);
dwc2_kill_urbs_in_qh_list(hsotg, &hsotg->non_periodic_sched_active);
dwc2_kill_urbs_in_qh_list(hsotg, &hsotg->periodic_sched_inactive);
dwc2_kill_urbs_in_qh_list(hsotg, &hsotg->periodic_sched_ready);
dwc2_kill_urbs_in_qh_list(hsotg, &hsotg->periodic_sched_assigned);
dwc2_kill_urbs_in_qh_list(hsotg, &hsotg->periodic_sched_queued);
}
void dwc2_hcd_start(struct dwc2_hsotg *hsotg)
{
u32 hprt0;
if (hsotg->op_state == OTG_STATE_B_HOST) {
hprt0 = dwc2_read_hprt0(hsotg);
hprt0 |= HPRT0_RST;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
}
queue_delayed_work(hsotg->wq_otg, &hsotg->start_work,
msecs_to_jiffies(50));
}
static void dwc2_hcd_cleanup_channels(struct dwc2_hsotg *hsotg)
{
int num_channels = hsotg->params.host_channels;
struct dwc2_host_chan *channel;
u32 hcchar;
int i;
if (!hsotg->params.host_dma) {
for (i = 0; i < num_channels; i++) {
channel = hsotg->hc_ptr_array[i];
if (!list_empty(&channel->hc_list_entry))
continue;
hcchar = dwc2_readl(hsotg->regs + HCCHAR(i));
if (hcchar & HCCHAR_CHENA) {
hcchar &= ~(HCCHAR_CHENA | HCCHAR_EPDIR);
hcchar |= HCCHAR_CHDIS;
dwc2_writel(hcchar, hsotg->regs + HCCHAR(i));
}
}
}
for (i = 0; i < num_channels; i++) {
channel = hsotg->hc_ptr_array[i];
if (!list_empty(&channel->hc_list_entry))
continue;
hcchar = dwc2_readl(hsotg->regs + HCCHAR(i));
if (hcchar & HCCHAR_CHENA) {
hcchar |= HCCHAR_CHDIS;
dwc2_writel(hcchar, hsotg->regs + HCCHAR(i));
}
dwc2_hc_cleanup(hsotg, channel);
list_add_tail(&channel->hc_list_entry, &hsotg->free_hc_list);
channel->qh = NULL;
}
if (hsotg->params.uframe_sched) {
hsotg->available_host_channels =
hsotg->params.host_channels;
} else {
hsotg->non_periodic_channels = 0;
hsotg->periodic_channels = 0;
}
}
void dwc2_hcd_connect(struct dwc2_hsotg *hsotg)
{
if (hsotg->lx_state != DWC2_L0)
usb_hcd_resume_root_hub(hsotg->priv);
hsotg->flags.b.port_connect_status_change = 1;
hsotg->flags.b.port_connect_status = 1;
}
void dwc2_hcd_disconnect(struct dwc2_hsotg *hsotg, bool force)
{
u32 intr;
u32 hprt0;
hsotg->flags.b.port_connect_status_change = 1;
hsotg->flags.b.port_connect_status = 0;
intr = dwc2_readl(hsotg->regs + GINTMSK);
intr &= ~(GINTSTS_NPTXFEMP | GINTSTS_PTXFEMP | GINTSTS_HCHINT);
dwc2_writel(intr, hsotg->regs + GINTMSK);
intr = GINTSTS_NPTXFEMP | GINTSTS_PTXFEMP | GINTSTS_HCHINT;
dwc2_writel(intr, hsotg->regs + GINTSTS);
if (dwc2_is_device_mode(hsotg)) {
if (hsotg->op_state != OTG_STATE_A_SUSPEND) {
dev_dbg(hsotg->dev, "Disconnect: PortPower off\n");
dwc2_writel(0, hsotg->regs + HPRT0);
}
dwc2_disable_host_interrupts(hsotg);
}
dwc2_kill_all_urbs(hsotg);
if (dwc2_is_host_mode(hsotg))
dwc2_hcd_cleanup_channels(hsotg);
dwc2_host_disconnect(hsotg);
if (!force) {
hprt0 = dwc2_readl(hsotg->regs + HPRT0);
if (!(hprt0 & HPRT0_CONNDET) && (hprt0 & HPRT0_CONNSTS))
dwc2_hcd_connect(hsotg);
}
}
static void dwc2_hcd_rem_wakeup(struct dwc2_hsotg *hsotg)
{
if (hsotg->bus_suspended) {
hsotg->flags.b.port_suspend_change = 1;
usb_hcd_resume_root_hub(hsotg->priv);
}
if (hsotg->lx_state == DWC2_L1)
hsotg->flags.b.port_l1_change = 1;
}
void dwc2_hcd_stop(struct dwc2_hsotg *hsotg)
{
dev_dbg(hsotg->dev, "DWC OTG HCD STOP\n");
dwc2_disable_host_interrupts(hsotg);
dev_dbg(hsotg->dev, "PortPower off\n");
dwc2_writel(0, hsotg->regs + HPRT0);
}
static int dwc2_hcd_urb_enqueue(struct dwc2_hsotg *hsotg,
struct dwc2_hcd_urb *urb, struct dwc2_qh *qh,
struct dwc2_qtd *qtd)
{
u32 intr_mask;
int retval;
int dev_speed;
if (!hsotg->flags.b.port_connect_status) {
dev_err(hsotg->dev, "Not connected\n");
return -ENODEV;
}
dev_speed = dwc2_host_get_speed(hsotg, urb->priv);
if ((dev_speed == USB_SPEED_LOW) &&
(hsotg->hw_params.fs_phy_type == GHWCFG2_FS_PHY_TYPE_DEDICATED) &&
(hsotg->hw_params.hs_phy_type == GHWCFG2_HS_PHY_TYPE_UTMI)) {
u32 hprt0 = dwc2_readl(hsotg->regs + HPRT0);
u32 prtspd = (hprt0 & HPRT0_SPD_MASK) >> HPRT0_SPD_SHIFT;
if (prtspd == HPRT0_SPD_FULL_SPEED)
return -ENODEV;
}
if (!qtd)
return -EINVAL;
dwc2_hcd_qtd_init(qtd, urb);
retval = dwc2_hcd_qtd_add(hsotg, qtd, qh);
if (retval) {
dev_err(hsotg->dev,
"DWC OTG HCD URB Enqueue failed adding QTD. Error status %d\n",
retval);
return retval;
}
intr_mask = dwc2_readl(hsotg->regs + GINTMSK);
if (!(intr_mask & GINTSTS_SOF)) {
enum dwc2_transaction_type tr_type;
if (qtd->qh->ep_type == USB_ENDPOINT_XFER_BULK &&
!(qtd->urb->flags & URB_GIVEBACK_ASAP))
return 0;
tr_type = dwc2_hcd_select_transactions(hsotg);
if (tr_type != DWC2_TRANSACTION_NONE)
dwc2_hcd_queue_transactions(hsotg, tr_type);
}
return 0;
}
static int dwc2_hcd_urb_dequeue(struct dwc2_hsotg *hsotg,
struct dwc2_hcd_urb *urb)
{
struct dwc2_qh *qh;
struct dwc2_qtd *urb_qtd;
urb_qtd = urb->qtd;
if (!urb_qtd) {
dev_dbg(hsotg->dev, "## Urb QTD is NULL ##\n");
return -EINVAL;
}
qh = urb_qtd->qh;
if (!qh) {
dev_dbg(hsotg->dev, "## Urb QTD QH is NULL ##\n");
return -EINVAL;
}
urb->priv = NULL;
if (urb_qtd->in_process && qh->channel) {
dwc2_dump_channel_info(hsotg, qh->channel);
if (hsotg->flags.b.port_connect_status)
dwc2_hc_halt(hsotg, qh->channel,
DWC2_HC_XFER_URB_DEQUEUE);
}
if (!hsotg->params.dma_desc_enable) {
u8 in_process = urb_qtd->in_process;
dwc2_hcd_qtd_unlink_and_free(hsotg, urb_qtd, qh);
if (in_process) {
dwc2_hcd_qh_deactivate(hsotg, qh, 0);
qh->channel = NULL;
} else if (list_empty(&qh->qtd_list)) {
dwc2_hcd_qh_unlink(hsotg, qh);
}
} else {
dwc2_hcd_qtd_unlink_and_free(hsotg, urb_qtd, qh);
}
return 0;
}
static int dwc2_hcd_endpoint_disable(struct dwc2_hsotg *hsotg,
struct usb_host_endpoint *ep, int retry)
{
struct dwc2_qtd *qtd, *qtd_tmp;
struct dwc2_qh *qh;
unsigned long flags;
int rc;
spin_lock_irqsave(&hsotg->lock, flags);
qh = ep->hcpriv;
if (!qh) {
rc = -EINVAL;
goto err;
}
while (!list_empty(&qh->qtd_list) && retry--) {
if (retry == 0) {
dev_err(hsotg->dev,
"## timeout in dwc2_hcd_endpoint_disable() ##\n");
rc = -EBUSY;
goto err;
}
spin_unlock_irqrestore(&hsotg->lock, flags);
msleep(20);
spin_lock_irqsave(&hsotg->lock, flags);
qh = ep->hcpriv;
if (!qh) {
rc = -EINVAL;
goto err;
}
}
dwc2_hcd_qh_unlink(hsotg, qh);
list_for_each_entry_safe(qtd, qtd_tmp, &qh->qtd_list, qtd_list_entry)
dwc2_hcd_qtd_unlink_and_free(hsotg, qtd, qh);
ep->hcpriv = NULL;
if (qh->channel && qh->channel->qh == qh)
qh->channel->qh = NULL;
spin_unlock_irqrestore(&hsotg->lock, flags);
dwc2_hcd_qh_free(hsotg, qh);
return 0;
err:
ep->hcpriv = NULL;
spin_unlock_irqrestore(&hsotg->lock, flags);
return rc;
}
static int dwc2_hcd_endpoint_reset(struct dwc2_hsotg *hsotg,
struct usb_host_endpoint *ep)
{
struct dwc2_qh *qh = ep->hcpriv;
if (!qh)
return -EINVAL;
qh->data_toggle = DWC2_HC_PID_DATA0;
return 0;
}
static int dwc2_core_init(struct dwc2_hsotg *hsotg, bool initial_setup)
{
u32 usbcfg, otgctl;
int retval;
dev_dbg(hsotg->dev, "%s(%p)\n", __func__, hsotg);
usbcfg = dwc2_readl(hsotg->regs + GUSBCFG);
usbcfg &= ~GUSBCFG_ULPI_EXT_VBUS_DRV;
if (hsotg->params.phy_ulpi_ext_vbus)
usbcfg |= GUSBCFG_ULPI_EXT_VBUS_DRV;
usbcfg &= ~GUSBCFG_TERMSELDLPULSE;
if (hsotg->params.ts_dline)
usbcfg |= GUSBCFG_TERMSELDLPULSE;
dwc2_writel(usbcfg, hsotg->regs + GUSBCFG);
if (!initial_setup) {
retval = dwc2_core_reset_and_force_dr_mode(hsotg);
if (retval) {
dev_err(hsotg->dev, "%s(): Reset failed, aborting\n",
__func__);
return retval;
}
}
retval = dwc2_phy_init(hsotg, initial_setup);
if (retval)
return retval;
retval = dwc2_gahbcfg_init(hsotg);
if (retval)
return retval;
dwc2_gusbcfg_init(hsotg);
otgctl = dwc2_readl(hsotg->regs + GOTGCTL);
otgctl &= ~GOTGCTL_OTGVER;
dwc2_writel(otgctl, hsotg->regs + GOTGCTL);
hsotg->srp_success = 0;
dwc2_enable_common_interrupts(hsotg);
if (dwc2_is_host_mode(hsotg)) {
dev_dbg(hsotg->dev, "Host Mode\n");
hsotg->op_state = OTG_STATE_A_HOST;
} else {
dev_dbg(hsotg->dev, "Device Mode\n");
hsotg->op_state = OTG_STATE_B_PERIPHERAL;
}
return 0;
}
static void dwc2_core_host_init(struct dwc2_hsotg *hsotg)
{
u32 hcfg, hfir, otgctl;
dev_dbg(hsotg->dev, "%s(%p)\n", __func__, hsotg);
dwc2_writel(0, hsotg->regs + PCGCTL);
dwc2_init_fs_ls_pclk_sel(hsotg);
if (hsotg->params.speed == DWC2_SPEED_PARAM_FULL ||
hsotg->params.speed == DWC2_SPEED_PARAM_LOW) {
hcfg = dwc2_readl(hsotg->regs + HCFG);
hcfg |= HCFG_FSLSSUPP;
dwc2_writel(hcfg, hsotg->regs + HCFG);
}
if (hsotg->params.reload_ctl) {
hfir = dwc2_readl(hsotg->regs + HFIR);
hfir |= HFIR_RLDCTRL;
dwc2_writel(hfir, hsotg->regs + HFIR);
}
if (hsotg->params.dma_desc_enable) {
u32 op_mode = hsotg->hw_params.op_mode;
if (hsotg->hw_params.snpsid < DWC2_CORE_REV_2_90a ||
!hsotg->hw_params.dma_desc_enable ||
op_mode == GHWCFG2_OP_MODE_SRP_CAPABLE_DEVICE ||
op_mode == GHWCFG2_OP_MODE_NO_SRP_CAPABLE_DEVICE ||
op_mode == GHWCFG2_OP_MODE_UNDEFINED) {
dev_err(hsotg->dev,
"Hardware does not support descriptor DMA mode -\n");
dev_err(hsotg->dev,
"falling back to buffer DMA mode.\n");
hsotg->params.dma_desc_enable = false;
} else {
hcfg = dwc2_readl(hsotg->regs + HCFG);
hcfg |= HCFG_DESCDMA;
dwc2_writel(hcfg, hsotg->regs + HCFG);
}
}
dwc2_config_fifos(hsotg);
otgctl = dwc2_readl(hsotg->regs + GOTGCTL);
otgctl &= ~GOTGCTL_HSTSETHNPEN;
dwc2_writel(otgctl, hsotg->regs + GOTGCTL);
dwc2_flush_tx_fifo(hsotg, 0x10 );
dwc2_flush_rx_fifo(hsotg);
otgctl = dwc2_readl(hsotg->regs + GOTGCTL);
otgctl &= ~GOTGCTL_HSTSETHNPEN;
dwc2_writel(otgctl, hsotg->regs + GOTGCTL);
if (!hsotg->params.dma_desc_enable) {
int num_channels, i;
u32 hcchar;
num_channels = hsotg->params.host_channels;
for (i = 0; i < num_channels; i++) {
hcchar = dwc2_readl(hsotg->regs + HCCHAR(i));
hcchar &= ~HCCHAR_CHENA;
hcchar |= HCCHAR_CHDIS;
hcchar &= ~HCCHAR_EPDIR;
dwc2_writel(hcchar, hsotg->regs + HCCHAR(i));
}
for (i = 0; i < num_channels; i++) {
int count = 0;
hcchar = dwc2_readl(hsotg->regs + HCCHAR(i));
hcchar |= HCCHAR_CHENA | HCCHAR_CHDIS;
hcchar &= ~HCCHAR_EPDIR;
dwc2_writel(hcchar, hsotg->regs + HCCHAR(i));
dev_dbg(hsotg->dev, "%s: Halt channel %d\n",
__func__, i);
do {
hcchar = dwc2_readl(hsotg->regs + HCCHAR(i));
if (++count > 1000) {
dev_err(hsotg->dev,
"Unable to clear enable on channel %d\n",
i);
break;
}
udelay(1);
} while (hcchar & HCCHAR_CHENA);
}
}
dev_dbg(hsotg->dev, "Init: Port Power? op_state=%d\n", hsotg->op_state);
if (hsotg->op_state == OTG_STATE_A_HOST) {
u32 hprt0 = dwc2_read_hprt0(hsotg);
dev_dbg(hsotg->dev, "Init: Power Port (%d)\n",
!!(hprt0 & HPRT0_PWR));
if (!(hprt0 & HPRT0_PWR)) {
hprt0 |= HPRT0_PWR;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
}
}
dwc2_enable_host_interrupts(hsotg);
}
static void dwc2_hcd_reinit(struct dwc2_hsotg *hsotg)
{
struct dwc2_host_chan *chan, *chan_tmp;
int num_channels;
int i;
hsotg->flags.d32 = 0;
hsotg->non_periodic_qh_ptr = &hsotg->non_periodic_sched_active;
if (hsotg->params.uframe_sched) {
hsotg->available_host_channels =
hsotg->params.host_channels;
} else {
hsotg->non_periodic_channels = 0;
hsotg->periodic_channels = 0;
}
list_for_each_entry_safe(chan, chan_tmp, &hsotg->free_hc_list,
hc_list_entry)
list_del_init(&chan->hc_list_entry);
num_channels = hsotg->params.host_channels;
for (i = 0; i < num_channels; i++) {
chan = hsotg->hc_ptr_array[i];
list_add_tail(&chan->hc_list_entry, &hsotg->free_hc_list);
dwc2_hc_cleanup(hsotg, chan);
}
dwc2_core_host_init(hsotg);
}
static void dwc2_hc_init_split(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan,
struct dwc2_qtd *qtd, struct dwc2_hcd_urb *urb)
{
int hub_addr, hub_port;
chan->do_split = 1;
chan->xact_pos = qtd->isoc_split_pos;
chan->complete_split = qtd->complete_split;
dwc2_host_hub_info(hsotg, urb->priv, &hub_addr, &hub_port);
chan->hub_addr = (u8)hub_addr;
chan->hub_port = (u8)hub_port;
}
static void dwc2_hc_init_xfer(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan,
struct dwc2_qtd *qtd)
{
struct dwc2_hcd_urb *urb = qtd->urb;
struct dwc2_hcd_iso_packet_desc *frame_desc;
switch (dwc2_hcd_get_pipe_type(&urb->pipe_info)) {
case USB_ENDPOINT_XFER_CONTROL:
chan->ep_type = USB_ENDPOINT_XFER_CONTROL;
switch (qtd->control_phase) {
case DWC2_CONTROL_SETUP:
dev_vdbg(hsotg->dev, " Control setup transaction\n");
chan->do_ping = 0;
chan->ep_is_in = 0;
chan->data_pid_start = DWC2_HC_PID_SETUP;
if (hsotg->params.host_dma)
chan->xfer_dma = urb->setup_dma;
else
chan->xfer_buf = urb->setup_packet;
chan->xfer_len = 8;
break;
case DWC2_CONTROL_DATA:
dev_vdbg(hsotg->dev, " Control data transaction\n");
chan->data_pid_start = qtd->data_toggle;
break;
case DWC2_CONTROL_STATUS:
dev_vdbg(hsotg->dev, " Control status transaction\n");
if (urb->length == 0)
chan->ep_is_in = 1;
else
chan->ep_is_in =
dwc2_hcd_is_pipe_out(&urb->pipe_info);
if (chan->ep_is_in)
chan->do_ping = 0;
chan->data_pid_start = DWC2_HC_PID_DATA1;
chan->xfer_len = 0;
if (hsotg->params.host_dma)
chan->xfer_dma = hsotg->status_buf_dma;
else
chan->xfer_buf = hsotg->status_buf;
break;
}
break;
case USB_ENDPOINT_XFER_BULK:
chan->ep_type = USB_ENDPOINT_XFER_BULK;
break;
case USB_ENDPOINT_XFER_INT:
chan->ep_type = USB_ENDPOINT_XFER_INT;
break;
case USB_ENDPOINT_XFER_ISOC:
chan->ep_type = USB_ENDPOINT_XFER_ISOC;
if (hsotg->params.dma_desc_enable)
break;
frame_desc = &urb->iso_descs[qtd->isoc_frame_index];
frame_desc->status = 0;
if (hsotg->params.host_dma) {
chan->xfer_dma = urb->dma;
chan->xfer_dma += frame_desc->offset +
qtd->isoc_split_offset;
} else {
chan->xfer_buf = urb->buf;
chan->xfer_buf += frame_desc->offset +
qtd->isoc_split_offset;
}
chan->xfer_len = frame_desc->length - qtd->isoc_split_offset;
if (chan->xact_pos == DWC2_HCSPLT_XACTPOS_ALL) {
if (chan->xfer_len <= 188)
chan->xact_pos = DWC2_HCSPLT_XACTPOS_ALL;
else
chan->xact_pos = DWC2_HCSPLT_XACTPOS_BEGIN;
}
break;
}
}
static void dwc2_free_dma_aligned_buffer(struct urb *urb)
{
struct dma_aligned_buffer *temp;
if (!(urb->transfer_flags & URB_ALIGNED_TEMP_BUFFER))
return;
temp = container_of(urb->transfer_buffer,
struct dma_aligned_buffer, data);
if (usb_urb_dir_in(urb))
memcpy(temp->old_xfer_buffer, temp->data,
urb->transfer_buffer_length);
urb->transfer_buffer = temp->old_xfer_buffer;
kfree(temp->kmalloc_ptr);
urb->transfer_flags &= ~URB_ALIGNED_TEMP_BUFFER;
}
static int dwc2_alloc_dma_aligned_buffer(struct urb *urb, gfp_t mem_flags)
{
struct dma_aligned_buffer *temp, *kmalloc_ptr;
size_t kmalloc_size;
if (urb->num_sgs || urb->sg ||
urb->transfer_buffer_length == 0 ||
!((uintptr_t)urb->transfer_buffer & (DWC2_USB_DMA_ALIGN - 1)))
return 0;
kmalloc_size = urb->transfer_buffer_length +
sizeof(struct dma_aligned_buffer) + DWC2_USB_DMA_ALIGN - 1;
kmalloc_ptr = kmalloc(kmalloc_size, mem_flags);
if (!kmalloc_ptr)
return -ENOMEM;
temp = PTR_ALIGN(kmalloc_ptr + 1, DWC2_USB_DMA_ALIGN) - 1;
temp->kmalloc_ptr = kmalloc_ptr;
temp->old_xfer_buffer = urb->transfer_buffer;
if (usb_urb_dir_out(urb))
memcpy(temp->data, urb->transfer_buffer,
urb->transfer_buffer_length);
urb->transfer_buffer = temp->data;
urb->transfer_flags |= URB_ALIGNED_TEMP_BUFFER;
return 0;
}
static int dwc2_map_urb_for_dma(struct usb_hcd *hcd, struct urb *urb,
gfp_t mem_flags)
{
int ret;
WARN_ON_ONCE(urb->setup_dma &&
(urb->setup_dma & (DWC2_USB_DMA_ALIGN - 1)));
ret = dwc2_alloc_dma_aligned_buffer(urb, mem_flags);
if (ret)
return ret;
ret = usb_hcd_map_urb_for_dma(hcd, urb, mem_flags);
if (ret)
dwc2_free_dma_aligned_buffer(urb);
return ret;
}
static void dwc2_unmap_urb_for_dma(struct usb_hcd *hcd, struct urb *urb)
{
usb_hcd_unmap_urb_for_dma(hcd, urb);
dwc2_free_dma_aligned_buffer(urb);
}
static int dwc2_assign_and_init_hc(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
struct dwc2_host_chan *chan;
struct dwc2_hcd_urb *urb;
struct dwc2_qtd *qtd;
if (dbg_qh(qh))
dev_vdbg(hsotg->dev, "%s(%p,%p)\n", __func__, hsotg, qh);
if (list_empty(&qh->qtd_list)) {
dev_dbg(hsotg->dev, "No QTDs in QH list\n");
return -ENOMEM;
}
if (list_empty(&hsotg->free_hc_list)) {
dev_dbg(hsotg->dev, "No free channel to assign\n");
return -ENOMEM;
}
chan = list_first_entry(&hsotg->free_hc_list, struct dwc2_host_chan,
hc_list_entry);
list_del_init(&chan->hc_list_entry);
qtd = list_first_entry(&qh->qtd_list, struct dwc2_qtd, qtd_list_entry);
urb = qtd->urb;
qh->channel = chan;
qtd->in_process = 1;
chan->dev_addr = dwc2_hcd_get_dev_addr(&urb->pipe_info);
chan->ep_num = dwc2_hcd_get_ep_num(&urb->pipe_info);
chan->speed = qh->dev_speed;
chan->max_packet = dwc2_max_packet(qh->maxp);
chan->xfer_started = 0;
chan->halt_status = DWC2_HC_XFER_NO_HALT_STATUS;
chan->error_state = (qtd->error_count > 0);
chan->halt_on_queue = 0;
chan->halt_pending = 0;
chan->requests = 0;
chan->ep_is_in = (dwc2_hcd_is_pipe_in(&urb->pipe_info) != 0);
if (chan->ep_is_in)
chan->do_ping = 0;
else
chan->do_ping = qh->ping_state;
chan->data_pid_start = qh->data_toggle;
chan->multi_count = 1;
if (urb->actual_length > urb->length &&
!dwc2_hcd_is_pipe_in(&urb->pipe_info))
urb->actual_length = urb->length;
if (hsotg->params.host_dma)
chan->xfer_dma = urb->dma + urb->actual_length;
else
chan->xfer_buf = (u8 *)urb->buf + urb->actual_length;
chan->xfer_len = urb->length - urb->actual_length;
chan->xfer_count = 0;
if (qh->do_split)
dwc2_hc_init_split(hsotg, chan, qtd, urb);
else
chan->do_split = 0;
dwc2_hc_init_xfer(hsotg, chan, qtd);
if (chan->ep_type == USB_ENDPOINT_XFER_INT ||
chan->ep_type == USB_ENDPOINT_XFER_ISOC)
chan->multi_count = dwc2_hb_mult(qh->maxp);
if (hsotg->params.dma_desc_enable) {
chan->desc_list_addr = qh->desc_list_dma;
chan->desc_list_sz = qh->desc_list_sz;
}
dwc2_hc_init(hsotg, chan);
chan->qh = qh;
return 0;
}
enum dwc2_transaction_type dwc2_hcd_select_transactions(
struct dwc2_hsotg *hsotg)
{
enum dwc2_transaction_type ret_val = DWC2_TRANSACTION_NONE;
struct list_head *qh_ptr;
struct dwc2_qh *qh;
int num_channels;
#ifdef DWC2_DEBUG_SOF
dev_vdbg(hsotg->dev, " Select Transactions\n");
#endif
qh_ptr = hsotg->periodic_sched_ready.next;
while (qh_ptr != &hsotg->periodic_sched_ready) {
if (list_empty(&hsotg->free_hc_list))
break;
if (hsotg->params.uframe_sched) {
if (hsotg->available_host_channels <= 1)
break;
hsotg->available_host_channels--;
}
qh = list_entry(qh_ptr, struct dwc2_qh, qh_list_entry);
if (dwc2_assign_and_init_hc(hsotg, qh))
break;
qh_ptr = qh_ptr->next;
list_move_tail(&qh->qh_list_entry,
&hsotg->periodic_sched_assigned);
ret_val = DWC2_TRANSACTION_PERIODIC;
}
num_channels = hsotg->params.host_channels;
qh_ptr = hsotg->non_periodic_sched_inactive.next;
while (qh_ptr != &hsotg->non_periodic_sched_inactive) {
if (!hsotg->params.uframe_sched &&
hsotg->non_periodic_channels >= num_channels -
hsotg->periodic_channels)
break;
if (list_empty(&hsotg->free_hc_list))
break;
qh = list_entry(qh_ptr, struct dwc2_qh, qh_list_entry);
if (hsotg->params.uframe_sched) {
if (hsotg->available_host_channels < 1)
break;
hsotg->available_host_channels--;
}
if (dwc2_assign_and_init_hc(hsotg, qh))
break;
qh_ptr = qh_ptr->next;
list_move_tail(&qh->qh_list_entry,
&hsotg->non_periodic_sched_active);
if (ret_val == DWC2_TRANSACTION_NONE)
ret_val = DWC2_TRANSACTION_NON_PERIODIC;
else
ret_val = DWC2_TRANSACTION_ALL;
if (!hsotg->params.uframe_sched)
hsotg->non_periodic_channels++;
}
return ret_val;
}
static int dwc2_queue_transaction(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan,
u16 fifo_dwords_avail)
{
int retval = 0;
if (chan->do_split)
list_move_tail(&chan->split_order_list_entry,
&hsotg->split_order);
if (hsotg->params.host_dma) {
if (hsotg->params.dma_desc_enable) {
if (!chan->xfer_started ||
chan->ep_type == USB_ENDPOINT_XFER_ISOC) {
dwc2_hcd_start_xfer_ddma(hsotg, chan->qh);
chan->qh->ping_state = 0;
}
} else if (!chan->xfer_started) {
dwc2_hc_start_transfer(hsotg, chan);
chan->qh->ping_state = 0;
}
} else if (chan->halt_pending) {
} else if (chan->halt_on_queue) {
dwc2_hc_halt(hsotg, chan, chan->halt_status);
} else if (chan->do_ping) {
if (!chan->xfer_started)
dwc2_hc_start_transfer(hsotg, chan);
} else if (!chan->ep_is_in ||
chan->data_pid_start == DWC2_HC_PID_SETUP) {
if ((fifo_dwords_avail * 4) >= chan->max_packet) {
if (!chan->xfer_started) {
dwc2_hc_start_transfer(hsotg, chan);
retval = 1;
} else {
retval = dwc2_hc_continue_transfer(hsotg, chan);
}
} else {
retval = -1;
}
} else {
if (!chan->xfer_started) {
dwc2_hc_start_transfer(hsotg, chan);
retval = 1;
} else {
retval = dwc2_hc_continue_transfer(hsotg, chan);
}
}
return retval;
}
static void dwc2_process_periodic_channels(struct dwc2_hsotg *hsotg)
{
struct list_head *qh_ptr;
struct dwc2_qh *qh;
u32 tx_status;
u32 fspcavail;
u32 gintmsk;
int status;
bool no_queue_space = false;
bool no_fifo_space = false;
u32 qspcavail;
if (list_empty(&hsotg->periodic_sched_assigned))
goto exit;
if (dbg_perio())
dev_vdbg(hsotg->dev, "Queue periodic transactions\n");
tx_status = dwc2_readl(hsotg->regs + HPTXSTS);
qspcavail = (tx_status & TXSTS_QSPCAVAIL_MASK) >>
TXSTS_QSPCAVAIL_SHIFT;
fspcavail = (tx_status & TXSTS_FSPCAVAIL_MASK) >>
TXSTS_FSPCAVAIL_SHIFT;
if (dbg_perio()) {
dev_vdbg(hsotg->dev, " P Tx Req Queue Space Avail (before queue): %d\n",
qspcavail);
dev_vdbg(hsotg->dev, " P Tx FIFO Space Avail (before queue): %d\n",
fspcavail);
}
qh_ptr = hsotg->periodic_sched_assigned.next;
while (qh_ptr != &hsotg->periodic_sched_assigned) {
tx_status = dwc2_readl(hsotg->regs + HPTXSTS);
qspcavail = (tx_status & TXSTS_QSPCAVAIL_MASK) >>
TXSTS_QSPCAVAIL_SHIFT;
if (qspcavail == 0) {
no_queue_space = true;
break;
}
qh = list_entry(qh_ptr, struct dwc2_qh, qh_list_entry);
if (!qh->channel) {
qh_ptr = qh_ptr->next;
continue;
}
if (qh->tt_buffer_dirty) {
qh_ptr = qh_ptr->next;
continue;
}
if (!hsotg->params.host_dma &&
qh->channel->multi_count > 1)
hsotg->queuing_high_bandwidth = 1;
fspcavail = (tx_status & TXSTS_FSPCAVAIL_MASK) >>
TXSTS_FSPCAVAIL_SHIFT;
status = dwc2_queue_transaction(hsotg, qh->channel, fspcavail);
if (status < 0) {
no_fifo_space = true;
break;
}
if (hsotg->params.host_dma || status == 0 ||
qh->channel->requests == qh->channel->multi_count) {
qh_ptr = qh_ptr->next;
list_move_tail(&qh->qh_list_entry,
&hsotg->periodic_sched_queued);
hsotg->queuing_high_bandwidth = 0;
}
}
exit:
if (no_queue_space || no_fifo_space ||
(!hsotg->params.host_dma &&
!list_empty(&hsotg->periodic_sched_assigned))) {
gintmsk = dwc2_readl(hsotg->regs + GINTMSK);
if (!(gintmsk & GINTSTS_PTXFEMP)) {
gintmsk |= GINTSTS_PTXFEMP;
dwc2_writel(gintmsk, hsotg->regs + GINTMSK);
}
} else {
gintmsk = dwc2_readl(hsotg->regs + GINTMSK);
if (gintmsk & GINTSTS_PTXFEMP) {
gintmsk &= ~GINTSTS_PTXFEMP;
dwc2_writel(gintmsk, hsotg->regs + GINTMSK);
}
}
}
static void dwc2_process_non_periodic_channels(struct dwc2_hsotg *hsotg)
{
struct list_head *orig_qh_ptr;
struct dwc2_qh *qh;
u32 tx_status;
u32 qspcavail;
u32 fspcavail;
u32 gintmsk;
int status;
int no_queue_space = 0;
int no_fifo_space = 0;
int more_to_do = 0;
dev_vdbg(hsotg->dev, "Queue non-periodic transactions\n");
tx_status = dwc2_readl(hsotg->regs + GNPTXSTS);
qspcavail = (tx_status & TXSTS_QSPCAVAIL_MASK) >>
TXSTS_QSPCAVAIL_SHIFT;
fspcavail = (tx_status & TXSTS_FSPCAVAIL_MASK) >>
TXSTS_FSPCAVAIL_SHIFT;
dev_vdbg(hsotg->dev, " NP Tx Req Queue Space Avail (before queue): %d\n",
qspcavail);
dev_vdbg(hsotg->dev, " NP Tx FIFO Space Avail (before queue): %d\n",
fspcavail);
if (hsotg->non_periodic_qh_ptr == &hsotg->non_periodic_sched_active)
hsotg->non_periodic_qh_ptr = hsotg->non_periodic_qh_ptr->next;
orig_qh_ptr = hsotg->non_periodic_qh_ptr;
do {
tx_status = dwc2_readl(hsotg->regs + GNPTXSTS);
qspcavail = (tx_status & TXSTS_QSPCAVAIL_MASK) >>
TXSTS_QSPCAVAIL_SHIFT;
if (!hsotg->params.host_dma && qspcavail == 0) {
no_queue_space = 1;
break;
}
qh = list_entry(hsotg->non_periodic_qh_ptr, struct dwc2_qh,
qh_list_entry);
if (!qh->channel)
goto next;
if (qh->tt_buffer_dirty)
goto next;
fspcavail = (tx_status & TXSTS_FSPCAVAIL_MASK) >>
TXSTS_FSPCAVAIL_SHIFT;
status = dwc2_queue_transaction(hsotg, qh->channel, fspcavail);
if (status > 0) {
more_to_do = 1;
} else if (status < 0) {
no_fifo_space = 1;
break;
}
next:
hsotg->non_periodic_qh_ptr = hsotg->non_periodic_qh_ptr->next;
if (hsotg->non_periodic_qh_ptr ==
&hsotg->non_periodic_sched_active)
hsotg->non_periodic_qh_ptr =
hsotg->non_periodic_qh_ptr->next;
} while (hsotg->non_periodic_qh_ptr != orig_qh_ptr);
if (!hsotg->params.host_dma) {
tx_status = dwc2_readl(hsotg->regs + GNPTXSTS);
qspcavail = (tx_status & TXSTS_QSPCAVAIL_MASK) >>
TXSTS_QSPCAVAIL_SHIFT;
fspcavail = (tx_status & TXSTS_FSPCAVAIL_MASK) >>
TXSTS_FSPCAVAIL_SHIFT;
dev_vdbg(hsotg->dev,
" NP Tx Req Queue Space Avail (after queue): %d\n",
qspcavail);
dev_vdbg(hsotg->dev,
" NP Tx FIFO Space Avail (after queue): %d\n",
fspcavail);
if (more_to_do || no_queue_space || no_fifo_space) {
gintmsk = dwc2_readl(hsotg->regs + GINTMSK);
gintmsk |= GINTSTS_NPTXFEMP;
dwc2_writel(gintmsk, hsotg->regs + GINTMSK);
} else {
gintmsk = dwc2_readl(hsotg->regs + GINTMSK);
gintmsk &= ~GINTSTS_NPTXFEMP;
dwc2_writel(gintmsk, hsotg->regs + GINTMSK);
}
}
}
void dwc2_hcd_queue_transactions(struct dwc2_hsotg *hsotg,
enum dwc2_transaction_type tr_type)
{
#ifdef DWC2_DEBUG_SOF
dev_vdbg(hsotg->dev, "Queue Transactions\n");
#endif
if (tr_type == DWC2_TRANSACTION_PERIODIC ||
tr_type == DWC2_TRANSACTION_ALL)
dwc2_process_periodic_channels(hsotg);
if (tr_type == DWC2_TRANSACTION_NON_PERIODIC ||
tr_type == DWC2_TRANSACTION_ALL) {
if (!list_empty(&hsotg->non_periodic_sched_active)) {
dwc2_process_non_periodic_channels(hsotg);
} else {
u32 gintmsk = dwc2_readl(hsotg->regs + GINTMSK);
gintmsk &= ~GINTSTS_NPTXFEMP;
dwc2_writel(gintmsk, hsotg->regs + GINTMSK);
}
}
}
static void dwc2_conn_id_status_change(struct work_struct *work)
{
struct dwc2_hsotg *hsotg = container_of(work, struct dwc2_hsotg,
wf_otg);
u32 count = 0;
u32 gotgctl;
unsigned long flags;
dev_dbg(hsotg->dev, "%s()\n", __func__);
gotgctl = dwc2_readl(hsotg->regs + GOTGCTL);
dev_dbg(hsotg->dev, "gotgctl=%0x\n", gotgctl);
dev_dbg(hsotg->dev, "gotgctl.b.conidsts=%d\n",
!!(gotgctl & GOTGCTL_CONID_B));
if (gotgctl & GOTGCTL_CONID_B) {
dev_dbg(hsotg->dev, "connId B\n");
if (hsotg->bus_suspended) {
dev_info(hsotg->dev,
"Do port resume before switching to device mode\n");
dwc2_port_resume(hsotg);
}
while (!dwc2_is_device_mode(hsotg)) {
dev_info(hsotg->dev,
"Waiting for Peripheral Mode, Mode=%s\n",
dwc2_is_host_mode(hsotg) ? "Host" :
"Peripheral");
msleep(20);
gotgctl = dwc2_readl(hsotg->regs + GOTGCTL);
if (!(gotgctl & GOTGCTL_CONID_B))
goto host;
if (++count > 250)
break;
}
if (count > 250)
dev_err(hsotg->dev,
"Connection id status change timed out\n");
hsotg->op_state = OTG_STATE_B_PERIPHERAL;
dwc2_core_init(hsotg, false);
dwc2_enable_global_interrupts(hsotg);
spin_lock_irqsave(&hsotg->lock, flags);
dwc2_hsotg_disconnect(hsotg);
dwc2_hsotg_core_init_disconnected(hsotg, false);
spin_unlock_irqrestore(&hsotg->lock, flags);
dwc2_hsotg_core_connect(hsotg);
} else {
host:
dev_dbg(hsotg->dev, "connId A\n");
while (!dwc2_is_host_mode(hsotg)) {
dev_info(hsotg->dev, "Waiting for Host Mode, Mode=%s\n",
dwc2_is_host_mode(hsotg) ?
"Host" : "Peripheral");
msleep(20);
if (++count > 250)
break;
}
if (count > 250)
dev_err(hsotg->dev,
"Connection id status change timed out\n");
hsotg->op_state = OTG_STATE_A_HOST;
dwc2_core_init(hsotg, false);
dwc2_enable_global_interrupts(hsotg);
dwc2_hcd_start(hsotg);
}
}
static void dwc2_wakeup_detected(unsigned long data)
{
struct dwc2_hsotg *hsotg = (struct dwc2_hsotg *)data;
u32 hprt0;
dev_dbg(hsotg->dev, "%s()\n", __func__);
hprt0 = dwc2_read_hprt0(hsotg);
dev_dbg(hsotg->dev, "Resume: HPRT0=%0x\n", hprt0);
hprt0 &= ~HPRT0_RES;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
dev_dbg(hsotg->dev, "Clear Resume: HPRT0=%0x\n",
dwc2_readl(hsotg->regs + HPRT0));
dwc2_hcd_rem_wakeup(hsotg);
hsotg->bus_suspended = false;
hsotg->lx_state = DWC2_L0;
}
static int dwc2_host_is_b_hnp_enabled(struct dwc2_hsotg *hsotg)
{
struct usb_hcd *hcd = dwc2_hsotg_to_hcd(hsotg);
return hcd->self.b_hnp_enable;
}
static void dwc2_port_suspend(struct dwc2_hsotg *hsotg, u16 windex)
{
unsigned long flags;
u32 hprt0;
u32 pcgctl;
u32 gotgctl;
dev_dbg(hsotg->dev, "%s()\n", __func__);
spin_lock_irqsave(&hsotg->lock, flags);
if (windex == hsotg->otg_port && dwc2_host_is_b_hnp_enabled(hsotg)) {
gotgctl = dwc2_readl(hsotg->regs + GOTGCTL);
gotgctl |= GOTGCTL_HSTSETHNPEN;
dwc2_writel(gotgctl, hsotg->regs + GOTGCTL);
hsotg->op_state = OTG_STATE_A_SUSPEND;
}
hprt0 = dwc2_read_hprt0(hsotg);
hprt0 |= HPRT0_SUSP;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
hsotg->bus_suspended = true;
if (!hsotg->params.hibernation) {
pcgctl = dwc2_readl(hsotg->regs + PCGCTL);
pcgctl |= PCGCTL_STOPPCLK;
dwc2_writel(pcgctl, hsotg->regs + PCGCTL);
udelay(10);
}
if (dwc2_host_is_b_hnp_enabled(hsotg)) {
pcgctl = dwc2_readl(hsotg->regs + PCGCTL);
pcgctl &= ~PCGCTL_STOPPCLK;
dwc2_writel(pcgctl, hsotg->regs + PCGCTL);
spin_unlock_irqrestore(&hsotg->lock, flags);
msleep(200);
} else {
spin_unlock_irqrestore(&hsotg->lock, flags);
}
}
static void dwc2_port_resume(struct dwc2_hsotg *hsotg)
{
unsigned long flags;
u32 hprt0;
u32 pcgctl;
spin_lock_irqsave(&hsotg->lock, flags);
if (!hsotg->params.hibernation) {
pcgctl = dwc2_readl(hsotg->regs + PCGCTL);
pcgctl &= ~PCGCTL_STOPPCLK;
dwc2_writel(pcgctl, hsotg->regs + PCGCTL);
spin_unlock_irqrestore(&hsotg->lock, flags);
msleep(20);
spin_lock_irqsave(&hsotg->lock, flags);
}
hprt0 = dwc2_read_hprt0(hsotg);
hprt0 |= HPRT0_RES;
hprt0 &= ~HPRT0_SUSP;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
spin_unlock_irqrestore(&hsotg->lock, flags);
msleep(USB_RESUME_TIMEOUT);
spin_lock_irqsave(&hsotg->lock, flags);
hprt0 = dwc2_read_hprt0(hsotg);
hprt0 &= ~(HPRT0_RES | HPRT0_SUSP);
dwc2_writel(hprt0, hsotg->regs + HPRT0);
hsotg->bus_suspended = false;
spin_unlock_irqrestore(&hsotg->lock, flags);
}
static int dwc2_hcd_hub_control(struct dwc2_hsotg *hsotg, u16 typereq,
u16 wvalue, u16 windex, char *buf, u16 wlength)
{
struct usb_hub_descriptor *hub_desc;
int retval = 0;
u32 hprt0;
u32 port_status;
u32 speed;
u32 pcgctl;
switch (typereq) {
case ClearHubFeature:
dev_dbg(hsotg->dev, "ClearHubFeature %1xh\n", wvalue);
switch (wvalue) {
case C_HUB_LOCAL_POWER:
case C_HUB_OVER_CURRENT:
break;
default:
retval = -EINVAL;
dev_err(hsotg->dev,
"ClearHubFeature request %1xh unknown\n",
wvalue);
}
break;
case ClearPortFeature:
if (wvalue != USB_PORT_FEAT_L1)
if (!windex || windex > 1)
goto error;
switch (wvalue) {
case USB_PORT_FEAT_ENABLE:
dev_dbg(hsotg->dev,
"ClearPortFeature USB_PORT_FEAT_ENABLE\n");
hprt0 = dwc2_read_hprt0(hsotg);
hprt0 |= HPRT0_ENA;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
break;
case USB_PORT_FEAT_SUSPEND:
dev_dbg(hsotg->dev,
"ClearPortFeature USB_PORT_FEAT_SUSPEND\n");
if (hsotg->bus_suspended)
dwc2_port_resume(hsotg);
break;
case USB_PORT_FEAT_POWER:
dev_dbg(hsotg->dev,
"ClearPortFeature USB_PORT_FEAT_POWER\n");
hprt0 = dwc2_read_hprt0(hsotg);
hprt0 &= ~HPRT0_PWR;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
break;
case USB_PORT_FEAT_INDICATOR:
dev_dbg(hsotg->dev,
"ClearPortFeature USB_PORT_FEAT_INDICATOR\n");
break;
case USB_PORT_FEAT_C_CONNECTION:
dev_dbg(hsotg->dev,
"ClearPortFeature USB_PORT_FEAT_C_CONNECTION\n");
hsotg->flags.b.port_connect_status_change = 0;
break;
case USB_PORT_FEAT_C_RESET:
dev_dbg(hsotg->dev,
"ClearPortFeature USB_PORT_FEAT_C_RESET\n");
hsotg->flags.b.port_reset_change = 0;
break;
case USB_PORT_FEAT_C_ENABLE:
dev_dbg(hsotg->dev,
"ClearPortFeature USB_PORT_FEAT_C_ENABLE\n");
hsotg->flags.b.port_enable_change = 0;
break;
case USB_PORT_FEAT_C_SUSPEND:
dev_dbg(hsotg->dev,
"ClearPortFeature USB_PORT_FEAT_C_SUSPEND\n");
hsotg->flags.b.port_suspend_change = 0;
break;
case USB_PORT_FEAT_C_PORT_L1:
dev_dbg(hsotg->dev,
"ClearPortFeature USB_PORT_FEAT_C_PORT_L1\n");
hsotg->flags.b.port_l1_change = 0;
break;
case USB_PORT_FEAT_C_OVER_CURRENT:
dev_dbg(hsotg->dev,
"ClearPortFeature USB_PORT_FEAT_C_OVER_CURRENT\n");
hsotg->flags.b.port_over_current_change = 0;
break;
default:
retval = -EINVAL;
dev_err(hsotg->dev,
"ClearPortFeature request %1xh unknown or unsupported\n",
wvalue);
}
break;
case GetHubDescriptor:
dev_dbg(hsotg->dev, "GetHubDescriptor\n");
hub_desc = (struct usb_hub_descriptor *)buf;
hub_desc->bDescLength = 9;
hub_desc->bDescriptorType = USB_DT_HUB;
hub_desc->bNbrPorts = 1;
hub_desc->wHubCharacteristics =
cpu_to_le16(HUB_CHAR_COMMON_LPSM |
HUB_CHAR_INDV_PORT_OCPM);
hub_desc->bPwrOn2PwrGood = 1;
hub_desc->bHubContrCurrent = 0;
hub_desc->u.hs.DeviceRemovable[0] = 0;
hub_desc->u.hs.DeviceRemovable[1] = 0xff;
break;
case GetHubStatus:
dev_dbg(hsotg->dev, "GetHubStatus\n");
memset(buf, 0, 4);
break;
case GetPortStatus:
dev_vdbg(hsotg->dev,
"GetPortStatus wIndex=0x%04x flags=0x%08x\n", windex,
hsotg->flags.d32);
if (!windex || windex > 1)
goto error;
port_status = 0;
if (hsotg->flags.b.port_connect_status_change)
port_status |= USB_PORT_STAT_C_CONNECTION << 16;
if (hsotg->flags.b.port_enable_change)
port_status |= USB_PORT_STAT_C_ENABLE << 16;
if (hsotg->flags.b.port_suspend_change)
port_status |= USB_PORT_STAT_C_SUSPEND << 16;
if (hsotg->flags.b.port_l1_change)
port_status |= USB_PORT_STAT_C_L1 << 16;
if (hsotg->flags.b.port_reset_change)
port_status |= USB_PORT_STAT_C_RESET << 16;
if (hsotg->flags.b.port_over_current_change) {
dev_warn(hsotg->dev, "Overcurrent change detected\n");
port_status |= USB_PORT_STAT_C_OVERCURRENT << 16;
}
if (!hsotg->flags.b.port_connect_status) {
*(__le32 *)buf = cpu_to_le32(port_status);
break;
}
hprt0 = dwc2_readl(hsotg->regs + HPRT0);
dev_vdbg(hsotg->dev, " HPRT0: 0x%08x\n", hprt0);
if (hprt0 & HPRT0_CONNSTS)
port_status |= USB_PORT_STAT_CONNECTION;
if (hprt0 & HPRT0_ENA)
port_status |= USB_PORT_STAT_ENABLE;
if (hprt0 & HPRT0_SUSP)
port_status |= USB_PORT_STAT_SUSPEND;
if (hprt0 & HPRT0_OVRCURRACT)
port_status |= USB_PORT_STAT_OVERCURRENT;
if (hprt0 & HPRT0_RST)
port_status |= USB_PORT_STAT_RESET;
if (hprt0 & HPRT0_PWR)
port_status |= USB_PORT_STAT_POWER;
speed = (hprt0 & HPRT0_SPD_MASK) >> HPRT0_SPD_SHIFT;
if (speed == HPRT0_SPD_HIGH_SPEED)
port_status |= USB_PORT_STAT_HIGH_SPEED;
else if (speed == HPRT0_SPD_LOW_SPEED)
port_status |= USB_PORT_STAT_LOW_SPEED;
if (hprt0 & HPRT0_TSTCTL_MASK)
port_status |= USB_PORT_STAT_TEST;
if (hsotg->params.dma_desc_fs_enable) {
if (hsotg->new_connection &&
((port_status &
(USB_PORT_STAT_CONNECTION |
USB_PORT_STAT_HIGH_SPEED |
USB_PORT_STAT_LOW_SPEED)) ==
USB_PORT_STAT_CONNECTION)) {
u32 hcfg;
dev_info(hsotg->dev, "Enabling descriptor DMA mode\n");
hsotg->params.dma_desc_enable = true;
hcfg = dwc2_readl(hsotg->regs + HCFG);
hcfg |= HCFG_DESCDMA;
dwc2_writel(hcfg, hsotg->regs + HCFG);
hsotg->new_connection = false;
}
}
dev_vdbg(hsotg->dev, "port_status=%08x\n", port_status);
*(__le32 *)buf = cpu_to_le32(port_status);
break;
case SetHubFeature:
dev_dbg(hsotg->dev, "SetHubFeature\n");
break;
case SetPortFeature:
dev_dbg(hsotg->dev, "SetPortFeature\n");
if (wvalue != USB_PORT_FEAT_TEST && (!windex || windex > 1))
goto error;
if (!hsotg->flags.b.port_connect_status) {
break;
}
switch (wvalue) {
case USB_PORT_FEAT_SUSPEND:
dev_dbg(hsotg->dev,
"SetPortFeature - USB_PORT_FEAT_SUSPEND\n");
if (windex != hsotg->otg_port)
goto error;
dwc2_port_suspend(hsotg, windex);
break;
case USB_PORT_FEAT_POWER:
dev_dbg(hsotg->dev,
"SetPortFeature - USB_PORT_FEAT_POWER\n");
hprt0 = dwc2_read_hprt0(hsotg);
hprt0 |= HPRT0_PWR;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
break;
case USB_PORT_FEAT_RESET:
hprt0 = dwc2_read_hprt0(hsotg);
dev_dbg(hsotg->dev,
"SetPortFeature - USB_PORT_FEAT_RESET\n");
pcgctl = dwc2_readl(hsotg->regs + PCGCTL);
pcgctl &= ~(PCGCTL_ENBL_SLEEP_GATING | PCGCTL_STOPPCLK);
dwc2_writel(pcgctl, hsotg->regs + PCGCTL);
dwc2_writel(0, hsotg->regs + PCGCTL);
hprt0 = dwc2_read_hprt0(hsotg);
hprt0 &= ~HPRT0_SUSP;
if (!dwc2_hcd_is_b_host(hsotg)) {
hprt0 |= HPRT0_PWR | HPRT0_RST;
dev_dbg(hsotg->dev,
"In host mode, hprt0=%08x\n", hprt0);
dwc2_writel(hprt0, hsotg->regs + HPRT0);
}
msleep(50);
hprt0 &= ~HPRT0_RST;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
hsotg->lx_state = DWC2_L0;
break;
case USB_PORT_FEAT_INDICATOR:
dev_dbg(hsotg->dev,
"SetPortFeature - USB_PORT_FEAT_INDICATOR\n");
break;
case USB_PORT_FEAT_TEST:
hprt0 = dwc2_read_hprt0(hsotg);
dev_dbg(hsotg->dev,
"SetPortFeature - USB_PORT_FEAT_TEST\n");
hprt0 &= ~HPRT0_TSTCTL_MASK;
hprt0 |= (windex >> 8) << HPRT0_TSTCTL_SHIFT;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
break;
default:
retval = -EINVAL;
dev_err(hsotg->dev,
"SetPortFeature %1xh unknown or unsupported\n",
wvalue);
break;
}
break;
default:
error:
retval = -EINVAL;
dev_dbg(hsotg->dev,
"Unknown hub control request: %1xh wIndex: %1xh wValue: %1xh\n",
typereq, windex, wvalue);
break;
}
return retval;
}
static int dwc2_hcd_is_status_changed(struct dwc2_hsotg *hsotg, int port)
{
int retval;
if (port != 1)
return -EINVAL;
retval = (hsotg->flags.b.port_connect_status_change ||
hsotg->flags.b.port_reset_change ||
hsotg->flags.b.port_enable_change ||
hsotg->flags.b.port_suspend_change ||
hsotg->flags.b.port_over_current_change);
if (retval) {
dev_dbg(hsotg->dev,
"DWC OTG HCD HUB STATUS DATA: Root port status changed\n");
dev_dbg(hsotg->dev, " port_connect_status_change: %d\n",
hsotg->flags.b.port_connect_status_change);
dev_dbg(hsotg->dev, " port_reset_change: %d\n",
hsotg->flags.b.port_reset_change);
dev_dbg(hsotg->dev, " port_enable_change: %d\n",
hsotg->flags.b.port_enable_change);
dev_dbg(hsotg->dev, " port_suspend_change: %d\n",
hsotg->flags.b.port_suspend_change);
dev_dbg(hsotg->dev, " port_over_current_change: %d\n",
hsotg->flags.b.port_over_current_change);
}
return retval;
}
int dwc2_hcd_get_frame_number(struct dwc2_hsotg *hsotg)
{
u32 hfnum = dwc2_readl(hsotg->regs + HFNUM);
#ifdef DWC2_DEBUG_SOF
dev_vdbg(hsotg->dev, "DWC OTG HCD GET FRAME NUMBER %d\n",
(hfnum & HFNUM_FRNUM_MASK) >> HFNUM_FRNUM_SHIFT);
#endif
return (hfnum & HFNUM_FRNUM_MASK) >> HFNUM_FRNUM_SHIFT;
}
int dwc2_hcd_get_future_frame_number(struct dwc2_hsotg *hsotg, int us)
{
u32 hprt = dwc2_readl(hsotg->regs + HPRT0);
u32 hfir = dwc2_readl(hsotg->regs + HFIR);
u32 hfnum = dwc2_readl(hsotg->regs + HFNUM);
unsigned int us_per_frame;
unsigned int frame_number;
unsigned int remaining;
unsigned int interval;
unsigned int phy_clks;
us_per_frame = (hprt & HPRT0_SPD_MASK) ? 1000 : 125;
frame_number = (hfnum & HFNUM_FRNUM_MASK) >> HFNUM_FRNUM_SHIFT;
remaining = (hfnum & HFNUM_FRREM_MASK) >> HFNUM_FRREM_SHIFT;
interval = (hfir & HFIR_FRINT_MASK) >> HFIR_FRINT_SHIFT;
phy_clks = (interval - remaining) +
DIV_ROUND_UP(interval * us, us_per_frame);
return dwc2_frame_num_inc(frame_number, phy_clks / interval);
}
int dwc2_hcd_is_b_host(struct dwc2_hsotg *hsotg)
{
return hsotg->op_state == OTG_STATE_B_HOST;
}
static struct dwc2_hcd_urb *dwc2_hcd_urb_alloc(struct dwc2_hsotg *hsotg,
int iso_desc_count,
gfp_t mem_flags)
{
struct dwc2_hcd_urb *urb;
u32 size = sizeof(*urb) + iso_desc_count *
sizeof(struct dwc2_hcd_iso_packet_desc);
urb = kzalloc(size, mem_flags);
if (urb)
urb->packet_count = iso_desc_count;
return urb;
}
static void dwc2_hcd_urb_set_pipeinfo(struct dwc2_hsotg *hsotg,
struct dwc2_hcd_urb *urb, u8 dev_addr,
u8 ep_num, u8 ep_type, u8 ep_dir, u16 mps)
{
if (dbg_perio() ||
ep_type == USB_ENDPOINT_XFER_BULK ||
ep_type == USB_ENDPOINT_XFER_CONTROL)
dev_vdbg(hsotg->dev,
"addr=%d, ep_num=%d, ep_dir=%1x, ep_type=%1x, mps=%d\n",
dev_addr, ep_num, ep_dir, ep_type, mps);
urb->pipe_info.dev_addr = dev_addr;
urb->pipe_info.ep_num = ep_num;
urb->pipe_info.pipe_type = ep_type;
urb->pipe_info.pipe_dir = ep_dir;
urb->pipe_info.mps = mps;
}
void dwc2_hcd_dump_state(struct dwc2_hsotg *hsotg)
{
#ifdef DEBUG
struct dwc2_host_chan *chan;
struct dwc2_hcd_urb *urb;
struct dwc2_qtd *qtd;
int num_channels;
u32 np_tx_status;
u32 p_tx_status;
int i;
num_channels = hsotg->params.host_channels;
dev_dbg(hsotg->dev, "\n");
dev_dbg(hsotg->dev,
"************************************************************\n");
dev_dbg(hsotg->dev, "HCD State:\n");
dev_dbg(hsotg->dev, " Num channels: %d\n", num_channels);
for (i = 0; i < num_channels; i++) {
chan = hsotg->hc_ptr_array[i];
dev_dbg(hsotg->dev, " Channel %d:\n", i);
dev_dbg(hsotg->dev,
" dev_addr: %d, ep_num: %d, ep_is_in: %d\n",
chan->dev_addr, chan->ep_num, chan->ep_is_in);
dev_dbg(hsotg->dev, " speed: %d\n", chan->speed);
dev_dbg(hsotg->dev, " ep_type: %d\n", chan->ep_type);
dev_dbg(hsotg->dev, " max_packet: %d\n", chan->max_packet);
dev_dbg(hsotg->dev, " data_pid_start: %d\n",
chan->data_pid_start);
dev_dbg(hsotg->dev, " multi_count: %d\n", chan->multi_count);
dev_dbg(hsotg->dev, " xfer_started: %d\n",
chan->xfer_started);
dev_dbg(hsotg->dev, " xfer_buf: %p\n", chan->xfer_buf);
dev_dbg(hsotg->dev, " xfer_dma: %08lx\n",
(unsigned long)chan->xfer_dma);
dev_dbg(hsotg->dev, " xfer_len: %d\n", chan->xfer_len);
dev_dbg(hsotg->dev, " xfer_count: %d\n", chan->xfer_count);
dev_dbg(hsotg->dev, " halt_on_queue: %d\n",
chan->halt_on_queue);
dev_dbg(hsotg->dev, " halt_pending: %d\n",
chan->halt_pending);
dev_dbg(hsotg->dev, " halt_status: %d\n", chan->halt_status);
dev_dbg(hsotg->dev, " do_split: %d\n", chan->do_split);
dev_dbg(hsotg->dev, " complete_split: %d\n",
chan->complete_split);
dev_dbg(hsotg->dev, " hub_addr: %d\n", chan->hub_addr);
dev_dbg(hsotg->dev, " hub_port: %d\n", chan->hub_port);
dev_dbg(hsotg->dev, " xact_pos: %d\n", chan->xact_pos);
dev_dbg(hsotg->dev, " requests: %d\n", chan->requests);
dev_dbg(hsotg->dev, " qh: %p\n", chan->qh);
if (chan->xfer_started) {
u32 hfnum, hcchar, hctsiz, hcint, hcintmsk;
hfnum = dwc2_readl(hsotg->regs + HFNUM);
hcchar = dwc2_readl(hsotg->regs + HCCHAR(i));
hctsiz = dwc2_readl(hsotg->regs + HCTSIZ(i));
hcint = dwc2_readl(hsotg->regs + HCINT(i));
hcintmsk = dwc2_readl(hsotg->regs + HCINTMSK(i));
dev_dbg(hsotg->dev, " hfnum: 0x%08x\n", hfnum);
dev_dbg(hsotg->dev, " hcchar: 0x%08x\n", hcchar);
dev_dbg(hsotg->dev, " hctsiz: 0x%08x\n", hctsiz);
dev_dbg(hsotg->dev, " hcint: 0x%08x\n", hcint);
dev_dbg(hsotg->dev, " hcintmsk: 0x%08x\n", hcintmsk);
}
if (!(chan->xfer_started && chan->qh))
continue;
list_for_each_entry(qtd, &chan->qh->qtd_list, qtd_list_entry) {
if (!qtd->in_process)
break;
urb = qtd->urb;
dev_dbg(hsotg->dev, " URB Info:\n");
dev_dbg(hsotg->dev, " qtd: %p, urb: %p\n",
qtd, urb);
if (urb) {
dev_dbg(hsotg->dev,
" Dev: %d, EP: %d %s\n",
dwc2_hcd_get_dev_addr(&urb->pipe_info),
dwc2_hcd_get_ep_num(&urb->pipe_info),
dwc2_hcd_is_pipe_in(&urb->pipe_info) ?
"IN" : "OUT");
dev_dbg(hsotg->dev,
" Max packet size: %d\n",
dwc2_hcd_get_mps(&urb->pipe_info));
dev_dbg(hsotg->dev,
" transfer_buffer: %p\n",
urb->buf);
dev_dbg(hsotg->dev,
" transfer_dma: %08lx\n",
(unsigned long)urb->dma);
dev_dbg(hsotg->dev,
" transfer_buffer_length: %d\n",
urb->length);
dev_dbg(hsotg->dev, " actual_length: %d\n",
urb->actual_length);
}
}
}
dev_dbg(hsotg->dev, " non_periodic_channels: %d\n",
hsotg->non_periodic_channels);
dev_dbg(hsotg->dev, " periodic_channels: %d\n",
hsotg->periodic_channels);
dev_dbg(hsotg->dev, " periodic_usecs: %d\n", hsotg->periodic_usecs);
np_tx_status = dwc2_readl(hsotg->regs + GNPTXSTS);
dev_dbg(hsotg->dev, " NP Tx Req Queue Space Avail: %d\n",
(np_tx_status & TXSTS_QSPCAVAIL_MASK) >> TXSTS_QSPCAVAIL_SHIFT);
dev_dbg(hsotg->dev, " NP Tx FIFO Space Avail: %d\n",
(np_tx_status & TXSTS_FSPCAVAIL_MASK) >> TXSTS_FSPCAVAIL_SHIFT);
p_tx_status = dwc2_readl(hsotg->regs + HPTXSTS);
dev_dbg(hsotg->dev, " P Tx Req Queue Space Avail: %d\n",
(p_tx_status & TXSTS_QSPCAVAIL_MASK) >> TXSTS_QSPCAVAIL_SHIFT);
dev_dbg(hsotg->dev, " P Tx FIFO Space Avail: %d\n",
(p_tx_status & TXSTS_FSPCAVAIL_MASK) >> TXSTS_FSPCAVAIL_SHIFT);
dwc2_hcd_dump_frrem(hsotg);
dwc2_dump_global_registers(hsotg);
dwc2_dump_host_registers(hsotg);
dev_dbg(hsotg->dev,
"************************************************************\n");
dev_dbg(hsotg->dev, "\n");
#endif
}
void dwc2_hcd_dump_frrem(struct dwc2_hsotg *hsotg)
{
#ifdef DWC2_DUMP_FRREM
dev_dbg(hsotg->dev, "Frame remaining at SOF:\n");
dev_dbg(hsotg->dev, " samples %u, accum %llu, avg %llu\n",
hsotg->frrem_samples, hsotg->frrem_accum,
hsotg->frrem_samples > 0 ?
hsotg->frrem_accum / hsotg->frrem_samples : 0);
dev_dbg(hsotg->dev, "\n");
dev_dbg(hsotg->dev, "Frame remaining at start_transfer (uframe 7):\n");
dev_dbg(hsotg->dev, " samples %u, accum %llu, avg %llu\n",
hsotg->hfnum_7_samples,
hsotg->hfnum_7_frrem_accum,
hsotg->hfnum_7_samples > 0 ?
hsotg->hfnum_7_frrem_accum / hsotg->hfnum_7_samples : 0);
dev_dbg(hsotg->dev, "Frame remaining at start_transfer (uframe 0):\n");
dev_dbg(hsotg->dev, " samples %u, accum %llu, avg %llu\n",
hsotg->hfnum_0_samples,
hsotg->hfnum_0_frrem_accum,
hsotg->hfnum_0_samples > 0 ?
hsotg->hfnum_0_frrem_accum / hsotg->hfnum_0_samples : 0);
dev_dbg(hsotg->dev, "Frame remaining at start_transfer (uframe 1-6):\n");
dev_dbg(hsotg->dev, " samples %u, accum %llu, avg %llu\n",
hsotg->hfnum_other_samples,
hsotg->hfnum_other_frrem_accum,
hsotg->hfnum_other_samples > 0 ?
hsotg->hfnum_other_frrem_accum / hsotg->hfnum_other_samples :
0);
dev_dbg(hsotg->dev, "\n");
dev_dbg(hsotg->dev, "Frame remaining at sample point A (uframe 7):\n");
dev_dbg(hsotg->dev, " samples %u, accum %llu, avg %llu\n",
hsotg->hfnum_7_samples_a, hsotg->hfnum_7_frrem_accum_a,
hsotg->hfnum_7_samples_a > 0 ?
hsotg->hfnum_7_frrem_accum_a / hsotg->hfnum_7_samples_a : 0);
dev_dbg(hsotg->dev, "Frame remaining at sample point A (uframe 0):\n");
dev_dbg(hsotg->dev, " samples %u, accum %llu, avg %llu\n",
hsotg->hfnum_0_samples_a, hsotg->hfnum_0_frrem_accum_a,
hsotg->hfnum_0_samples_a > 0 ?
hsotg->hfnum_0_frrem_accum_a / hsotg->hfnum_0_samples_a : 0);
dev_dbg(hsotg->dev, "Frame remaining at sample point A (uframe 1-6):\n");
dev_dbg(hsotg->dev, " samples %u, accum %llu, avg %llu\n",
hsotg->hfnum_other_samples_a, hsotg->hfnum_other_frrem_accum_a,
hsotg->hfnum_other_samples_a > 0 ?
hsotg->hfnum_other_frrem_accum_a / hsotg->hfnum_other_samples_a
: 0);
dev_dbg(hsotg->dev, "\n");
dev_dbg(hsotg->dev, "Frame remaining at sample point B (uframe 7):\n");
dev_dbg(hsotg->dev, " samples %u, accum %llu, avg %llu\n",
hsotg->hfnum_7_samples_b, hsotg->hfnum_7_frrem_accum_b,
hsotg->hfnum_7_samples_b > 0 ?
hsotg->hfnum_7_frrem_accum_b / hsotg->hfnum_7_samples_b : 0);
dev_dbg(hsotg->dev, "Frame remaining at sample point B (uframe 0):\n");
dev_dbg(hsotg->dev, " samples %u, accum %llu, avg %llu\n",
hsotg->hfnum_0_samples_b, hsotg->hfnum_0_frrem_accum_b,
(hsotg->hfnum_0_samples_b > 0) ?
hsotg->hfnum_0_frrem_accum_b / hsotg->hfnum_0_samples_b : 0);
dev_dbg(hsotg->dev, "Frame remaining at sample point B (uframe 1-6):\n");
dev_dbg(hsotg->dev, " samples %u, accum %llu, avg %llu\n",
hsotg->hfnum_other_samples_b, hsotg->hfnum_other_frrem_accum_b,
(hsotg->hfnum_other_samples_b > 0) ?
hsotg->hfnum_other_frrem_accum_b / hsotg->hfnum_other_samples_b
: 0);
#endif
}
static struct dwc2_hsotg *dwc2_hcd_to_hsotg(struct usb_hcd *hcd)
{
struct wrapper_priv_data *p;
p = (struct wrapper_priv_data *)&hcd->hcd_priv;
return p->hsotg;
}
struct dwc2_tt *dwc2_host_get_tt_info(struct dwc2_hsotg *hsotg, void *context,
gfp_t mem_flags, int *ttport)
{
struct urb *urb = context;
struct dwc2_tt *dwc_tt = NULL;
if (urb->dev->tt) {
*ttport = urb->dev->ttport;
dwc_tt = urb->dev->tt->hcpriv;
if (!dwc_tt) {
size_t bitmap_size;
bitmap_size = DWC2_ELEMENTS_PER_LS_BITMAP *
sizeof(dwc_tt->periodic_bitmaps[0]);
if (urb->dev->tt->multi)
bitmap_size *= urb->dev->tt->hub->maxchild;
dwc_tt = kzalloc(sizeof(*dwc_tt) + bitmap_size,
mem_flags);
if (!dwc_tt)
return NULL;
dwc_tt->usb_tt = urb->dev->tt;
dwc_tt->usb_tt->hcpriv = dwc_tt;
}
dwc_tt->refcount++;
}
return dwc_tt;
}
void dwc2_host_put_tt_info(struct dwc2_hsotg *hsotg, struct dwc2_tt *dwc_tt)
{
if (!dwc_tt)
return;
WARN_ON(dwc_tt->refcount < 1);
dwc_tt->refcount--;
if (!dwc_tt->refcount) {
dwc_tt->usb_tt->hcpriv = NULL;
kfree(dwc_tt);
}
}
int dwc2_host_get_speed(struct dwc2_hsotg *hsotg, void *context)
{
struct urb *urb = context;
return urb->dev->speed;
}
static void dwc2_allocate_bus_bandwidth(struct usb_hcd *hcd, u16 bw,
struct urb *urb)
{
struct usb_bus *bus = hcd_to_bus(hcd);
if (urb->interval)
bus->bandwidth_allocated += bw / urb->interval;
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS)
bus->bandwidth_isoc_reqs++;
else
bus->bandwidth_int_reqs++;
}
static void dwc2_free_bus_bandwidth(struct usb_hcd *hcd, u16 bw,
struct urb *urb)
{
struct usb_bus *bus = hcd_to_bus(hcd);
if (urb->interval)
bus->bandwidth_allocated -= bw / urb->interval;
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS)
bus->bandwidth_isoc_reqs--;
else
bus->bandwidth_int_reqs--;
}
void dwc2_host_complete(struct dwc2_hsotg *hsotg, struct dwc2_qtd *qtd,
int status)
{
struct urb *urb;
int i;
if (!qtd) {
dev_dbg(hsotg->dev, "## %s: qtd is NULL ##\n", __func__);
return;
}
if (!qtd->urb) {
dev_dbg(hsotg->dev, "## %s: qtd->urb is NULL ##\n", __func__);
return;
}
urb = qtd->urb->priv;
if (!urb) {
dev_dbg(hsotg->dev, "## %s: urb->priv is NULL ##\n", __func__);
return;
}
urb->actual_length = dwc2_hcd_urb_get_actual_length(qtd->urb);
if (dbg_urb(urb))
dev_vdbg(hsotg->dev,
"%s: urb %p device %d ep %d-%s status %d actual %d\n",
__func__, urb, usb_pipedevice(urb->pipe),
usb_pipeendpoint(urb->pipe),
usb_pipein(urb->pipe) ? "IN" : "OUT", status,
urb->actual_length);
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS) {
urb->error_count = dwc2_hcd_urb_get_error_count(qtd->urb);
for (i = 0; i < urb->number_of_packets; ++i) {
urb->iso_frame_desc[i].actual_length =
dwc2_hcd_urb_get_iso_desc_actual_length(
qtd->urb, i);
urb->iso_frame_desc[i].status =
dwc2_hcd_urb_get_iso_desc_status(qtd->urb, i);
}
}
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS && dbg_perio()) {
for (i = 0; i < urb->number_of_packets; i++)
dev_vdbg(hsotg->dev, " ISO Desc %d status %d\n",
i, urb->iso_frame_desc[i].status);
}
urb->status = status;
if (!status) {
if ((urb->transfer_flags & URB_SHORT_NOT_OK) &&
urb->actual_length < urb->transfer_buffer_length)
urb->status = -EREMOTEIO;
}
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS ||
usb_pipetype(urb->pipe) == PIPE_INTERRUPT) {
struct usb_host_endpoint *ep = urb->ep;
if (ep)
dwc2_free_bus_bandwidth(dwc2_hsotg_to_hcd(hsotg),
dwc2_hcd_get_ep_bandwidth(hsotg, ep),
urb);
}
usb_hcd_unlink_urb_from_ep(dwc2_hsotg_to_hcd(hsotg), urb);
urb->hcpriv = NULL;
kfree(qtd->urb);
qtd->urb = NULL;
usb_hcd_giveback_urb(dwc2_hsotg_to_hcd(hsotg), urb, status);
}
static void dwc2_hcd_start_func(struct work_struct *work)
{
struct dwc2_hsotg *hsotg = container_of(work, struct dwc2_hsotg,
start_work.work);
dev_dbg(hsotg->dev, "%s() %p\n", __func__, hsotg);
dwc2_host_start(hsotg);
}
static void dwc2_hcd_reset_func(struct work_struct *work)
{
struct dwc2_hsotg *hsotg = container_of(work, struct dwc2_hsotg,
reset_work.work);
unsigned long flags;
u32 hprt0;
dev_dbg(hsotg->dev, "USB RESET function called\n");
spin_lock_irqsave(&hsotg->lock, flags);
hprt0 = dwc2_read_hprt0(hsotg);
hprt0 &= ~HPRT0_RST;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
hsotg->flags.b.port_reset_change = 1;
spin_unlock_irqrestore(&hsotg->lock, flags);
}
static int _dwc2_hcd_start(struct usb_hcd *hcd)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
struct usb_bus *bus = hcd_to_bus(hcd);
unsigned long flags;
dev_dbg(hsotg->dev, "DWC OTG HCD START\n");
spin_lock_irqsave(&hsotg->lock, flags);
hsotg->lx_state = DWC2_L0;
hcd->state = HC_STATE_RUNNING;
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
if (dwc2_is_device_mode(hsotg)) {
spin_unlock_irqrestore(&hsotg->lock, flags);
return 0;
}
dwc2_hcd_reinit(hsotg);
if (bus->root_hub) {
dev_dbg(hsotg->dev, "DWC OTG HCD Has Root Hub\n");
usb_hcd_resume_root_hub(hcd);
}
spin_unlock_irqrestore(&hsotg->lock, flags);
return 0;
}
static void _dwc2_hcd_stop(struct usb_hcd *hcd)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
unsigned long flags;
dwc2_disable_host_interrupts(hsotg);
synchronize_irq(hcd->irq);
spin_lock_irqsave(&hsotg->lock, flags);
dwc2_hcd_disconnect(hsotg, true);
dwc2_hcd_stop(hsotg);
hsotg->lx_state = DWC2_L3;
hcd->state = HC_STATE_HALT;
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
spin_unlock_irqrestore(&hsotg->lock, flags);
usleep_range(1000, 3000);
}
static int _dwc2_hcd_suspend(struct usb_hcd *hcd)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
unsigned long flags;
int ret = 0;
u32 hprt0;
spin_lock_irqsave(&hsotg->lock, flags);
if (hsotg->lx_state != DWC2_L0)
goto unlock;
if (!HCD_HW_ACCESSIBLE(hcd))
goto unlock;
if (hsotg->op_state == OTG_STATE_B_PERIPHERAL)
goto unlock;
if (!hsotg->params.hibernation)
goto skip_power_saving;
if (!hsotg->bus_suspended) {
hprt0 = dwc2_read_hprt0(hsotg);
hprt0 |= HPRT0_SUSP;
hprt0 &= ~HPRT0_PWR;
dwc2_writel(hprt0, hsotg->regs + HPRT0);
}
ret = dwc2_enter_hibernation(hsotg);
if (ret) {
if (ret != -ENOTSUPP)
dev_err(hsotg->dev,
"enter hibernation failed\n");
goto skip_power_saving;
}
if (!IS_ERR_OR_NULL(hsotg->uphy)) {
spin_unlock_irqrestore(&hsotg->lock, flags);
usb_phy_set_suspend(hsotg->uphy, true);
spin_lock_irqsave(&hsotg->lock, flags);
}
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
skip_power_saving:
hsotg->lx_state = DWC2_L2;
unlock:
spin_unlock_irqrestore(&hsotg->lock, flags);
return ret;
}
static int _dwc2_hcd_resume(struct usb_hcd *hcd)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&hsotg->lock, flags);
if (hsotg->lx_state != DWC2_L2)
goto unlock;
if (!hsotg->params.hibernation) {
hsotg->lx_state = DWC2_L0;
goto unlock;
}
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
if (!IS_ERR_OR_NULL(hsotg->uphy)) {
spin_unlock_irqrestore(&hsotg->lock, flags);
usb_phy_set_suspend(hsotg->uphy, false);
spin_lock_irqsave(&hsotg->lock, flags);
}
ret = dwc2_exit_hibernation(hsotg, true);
if (ret && (ret != -ENOTSUPP))
dev_err(hsotg->dev, "exit hibernation failed\n");
hsotg->lx_state = DWC2_L0;
spin_unlock_irqrestore(&hsotg->lock, flags);
if (hsotg->bus_suspended) {
spin_lock_irqsave(&hsotg->lock, flags);
hsotg->flags.b.port_suspend_change = 1;
spin_unlock_irqrestore(&hsotg->lock, flags);
dwc2_port_resume(hsotg);
} else {
usleep_range(3000, 5000);
dwc2_writel(HPRT0_PWR | HPRT0_CONNDET |
HPRT0_ENACHG, hsotg->regs + HPRT0);
usleep_range(5000, 7000);
}
return ret;
unlock:
spin_unlock_irqrestore(&hsotg->lock, flags);
return ret;
}
static int _dwc2_hcd_get_frame_number(struct usb_hcd *hcd)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
return dwc2_hcd_get_frame_number(hsotg);
}
static void dwc2_dump_urb_info(struct usb_hcd *hcd, struct urb *urb,
char *fn_name)
{
#ifdef VERBOSE_DEBUG
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
char *pipetype = NULL;
char *speed = NULL;
dev_vdbg(hsotg->dev, "%s, urb %p\n", fn_name, urb);
dev_vdbg(hsotg->dev, " Device address: %d\n",
usb_pipedevice(urb->pipe));
dev_vdbg(hsotg->dev, " Endpoint: %d, %s\n",
usb_pipeendpoint(urb->pipe),
usb_pipein(urb->pipe) ? "IN" : "OUT");
switch (usb_pipetype(urb->pipe)) {
case PIPE_CONTROL:
pipetype = "CONTROL";
break;
case PIPE_BULK:
pipetype = "BULK";
break;
case PIPE_INTERRUPT:
pipetype = "INTERRUPT";
break;
case PIPE_ISOCHRONOUS:
pipetype = "ISOCHRONOUS";
break;
}
dev_vdbg(hsotg->dev, " Endpoint type: %s %s (%s)\n", pipetype,
usb_urb_dir_in(urb) ? "IN" : "OUT", usb_pipein(urb->pipe) ?
"IN" : "OUT");
switch (urb->dev->speed) {
case USB_SPEED_HIGH:
speed = "HIGH";
break;
case USB_SPEED_FULL:
speed = "FULL";
break;
case USB_SPEED_LOW:
speed = "LOW";
break;
default:
speed = "UNKNOWN";
break;
}
dev_vdbg(hsotg->dev, " Speed: %s\n", speed);
dev_vdbg(hsotg->dev, " Max packet size: %d\n",
usb_maxpacket(urb->dev, urb->pipe, usb_pipeout(urb->pipe)));
dev_vdbg(hsotg->dev, " Data buffer length: %d\n",
urb->transfer_buffer_length);
dev_vdbg(hsotg->dev, " Transfer buffer: %p, Transfer DMA: %08lx\n",
urb->transfer_buffer, (unsigned long)urb->transfer_dma);
dev_vdbg(hsotg->dev, " Setup buffer: %p, Setup DMA: %08lx\n",
urb->setup_packet, (unsigned long)urb->setup_dma);
dev_vdbg(hsotg->dev, " Interval: %d\n", urb->interval);
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS) {
int i;
for (i = 0; i < urb->number_of_packets; i++) {
dev_vdbg(hsotg->dev, " ISO Desc %d:\n", i);
dev_vdbg(hsotg->dev, " offset: %d, length %d\n",
urb->iso_frame_desc[i].offset,
urb->iso_frame_desc[i].length);
}
}
#endif
}
static int _dwc2_hcd_urb_enqueue(struct usb_hcd *hcd, struct urb *urb,
gfp_t mem_flags)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
struct usb_host_endpoint *ep = urb->ep;
struct dwc2_hcd_urb *dwc2_urb;
int i;
int retval;
int alloc_bandwidth = 0;
u8 ep_type = 0;
u32 tflags = 0;
void *buf;
unsigned long flags;
struct dwc2_qh *qh;
bool qh_allocated = false;
struct dwc2_qtd *qtd;
if (dbg_urb(urb)) {
dev_vdbg(hsotg->dev, "DWC OTG HCD URB Enqueue\n");
dwc2_dump_urb_info(hcd, urb, "urb_enqueue");
}
if (!ep)
return -EINVAL;
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS ||
usb_pipetype(urb->pipe) == PIPE_INTERRUPT) {
spin_lock_irqsave(&hsotg->lock, flags);
if (!dwc2_hcd_is_bandwidth_allocated(hsotg, ep))
alloc_bandwidth = 1;
spin_unlock_irqrestore(&hsotg->lock, flags);
}
switch (usb_pipetype(urb->pipe)) {
case PIPE_CONTROL:
ep_type = USB_ENDPOINT_XFER_CONTROL;
break;
case PIPE_ISOCHRONOUS:
ep_type = USB_ENDPOINT_XFER_ISOC;
break;
case PIPE_BULK:
ep_type = USB_ENDPOINT_XFER_BULK;
break;
case PIPE_INTERRUPT:
ep_type = USB_ENDPOINT_XFER_INT;
break;
}
dwc2_urb = dwc2_hcd_urb_alloc(hsotg, urb->number_of_packets,
mem_flags);
if (!dwc2_urb)
return -ENOMEM;
dwc2_hcd_urb_set_pipeinfo(hsotg, dwc2_urb, usb_pipedevice(urb->pipe),
usb_pipeendpoint(urb->pipe), ep_type,
usb_pipein(urb->pipe),
usb_maxpacket(urb->dev, urb->pipe,
!(usb_pipein(urb->pipe))));
buf = urb->transfer_buffer;
if (hcd->self.uses_dma) {
if (!buf && (urb->transfer_dma & 3)) {
dev_err(hsotg->dev,
"%s: unaligned transfer with no transfer_buffer",
__func__);
retval = -EINVAL;
goto fail0;
}
}
if (!(urb->transfer_flags & URB_NO_INTERRUPT))
tflags |= URB_GIVEBACK_ASAP;
if (urb->transfer_flags & URB_ZERO_PACKET)
tflags |= URB_SEND_ZERO_PACKET;
dwc2_urb->priv = urb;
dwc2_urb->buf = buf;
dwc2_urb->dma = urb->transfer_dma;
dwc2_urb->length = urb->transfer_buffer_length;
dwc2_urb->setup_packet = urb->setup_packet;
dwc2_urb->setup_dma = urb->setup_dma;
dwc2_urb->flags = tflags;
dwc2_urb->interval = urb->interval;
dwc2_urb->status = -EINPROGRESS;
for (i = 0; i < urb->number_of_packets; ++i)
dwc2_hcd_urb_set_iso_desc_params(dwc2_urb, i,
urb->iso_frame_desc[i].offset,
urb->iso_frame_desc[i].length);
urb->hcpriv = dwc2_urb;
qh = (struct dwc2_qh *)ep->hcpriv;
if (!qh) {
qh = dwc2_hcd_qh_create(hsotg, dwc2_urb, mem_flags);
if (!qh) {
retval = -ENOMEM;
goto fail0;
}
ep->hcpriv = qh;
qh_allocated = true;
}
qtd = kzalloc(sizeof(*qtd), mem_flags);
if (!qtd) {
retval = -ENOMEM;
goto fail1;
}
spin_lock_irqsave(&hsotg->lock, flags);
retval = usb_hcd_link_urb_to_ep(hcd, urb);
if (retval)
goto fail2;
retval = dwc2_hcd_urb_enqueue(hsotg, dwc2_urb, qh, qtd);
if (retval)
goto fail3;
if (alloc_bandwidth) {
dwc2_allocate_bus_bandwidth(hcd,
dwc2_hcd_get_ep_bandwidth(hsotg, ep),
urb);
}
spin_unlock_irqrestore(&hsotg->lock, flags);
return 0;
fail3:
dwc2_urb->priv = NULL;
usb_hcd_unlink_urb_from_ep(hcd, urb);
if (qh_allocated && qh->channel && qh->channel->qh == qh)
qh->channel->qh = NULL;
fail2:
spin_unlock_irqrestore(&hsotg->lock, flags);
urb->hcpriv = NULL;
kfree(qtd);
qtd = NULL;
fail1:
if (qh_allocated) {
struct dwc2_qtd *qtd2, *qtd2_tmp;
ep->hcpriv = NULL;
dwc2_hcd_qh_unlink(hsotg, qh);
list_for_each_entry_safe(qtd2, qtd2_tmp, &qh->qtd_list,
qtd_list_entry)
dwc2_hcd_qtd_unlink_and_free(hsotg, qtd2, qh);
dwc2_hcd_qh_free(hsotg, qh);
}
fail0:
kfree(dwc2_urb);
return retval;
}
static int _dwc2_hcd_urb_dequeue(struct usb_hcd *hcd, struct urb *urb,
int status)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
int rc;
unsigned long flags;
dev_dbg(hsotg->dev, "DWC OTG HCD URB Dequeue\n");
dwc2_dump_urb_info(hcd, urb, "urb_dequeue");
spin_lock_irqsave(&hsotg->lock, flags);
rc = usb_hcd_check_unlink_urb(hcd, urb, status);
if (rc)
goto out;
if (!urb->hcpriv) {
dev_dbg(hsotg->dev, "## urb->hcpriv is NULL ##\n");
goto out;
}
rc = dwc2_hcd_urb_dequeue(hsotg, urb->hcpriv);
usb_hcd_unlink_urb_from_ep(hcd, urb);
kfree(urb->hcpriv);
urb->hcpriv = NULL;
spin_unlock(&hsotg->lock);
usb_hcd_giveback_urb(hcd, urb, status);
spin_lock(&hsotg->lock);
dev_dbg(hsotg->dev, "Called usb_hcd_giveback_urb()\n");
dev_dbg(hsotg->dev, " urb->status = %d\n", urb->status);
out:
spin_unlock_irqrestore(&hsotg->lock, flags);
return rc;
}
static void _dwc2_hcd_endpoint_disable(struct usb_hcd *hcd,
struct usb_host_endpoint *ep)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
dev_dbg(hsotg->dev,
"DWC OTG HCD EP DISABLE: bEndpointAddress=0x%02x, ep->hcpriv=%p\n",
ep->desc.bEndpointAddress, ep->hcpriv);
dwc2_hcd_endpoint_disable(hsotg, ep, 250);
}
static void _dwc2_hcd_endpoint_reset(struct usb_hcd *hcd,
struct usb_host_endpoint *ep)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
unsigned long flags;
dev_dbg(hsotg->dev,
"DWC OTG HCD EP RESET: bEndpointAddress=0x%02x\n",
ep->desc.bEndpointAddress);
spin_lock_irqsave(&hsotg->lock, flags);
dwc2_hcd_endpoint_reset(hsotg, ep);
spin_unlock_irqrestore(&hsotg->lock, flags);
}
static irqreturn_t _dwc2_hcd_irq(struct usb_hcd *hcd)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
return dwc2_handle_hcd_intr(hsotg);
}
static int _dwc2_hcd_hub_status_data(struct usb_hcd *hcd, char *buf)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
buf[0] = dwc2_hcd_is_status_changed(hsotg, 1) << 1;
return buf[0] != 0;
}
static int _dwc2_hcd_hub_control(struct usb_hcd *hcd, u16 typereq, u16 wvalue,
u16 windex, char *buf, u16 wlength)
{
int retval = dwc2_hcd_hub_control(dwc2_hcd_to_hsotg(hcd), typereq,
wvalue, windex, buf, wlength);
return retval;
}
static void _dwc2_hcd_clear_tt_buffer_complete(struct usb_hcd *hcd,
struct usb_host_endpoint *ep)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
struct dwc2_qh *qh;
unsigned long flags;
qh = ep->hcpriv;
if (!qh)
return;
spin_lock_irqsave(&hsotg->lock, flags);
qh->tt_buffer_dirty = 0;
if (hsotg->flags.b.port_connect_status)
dwc2_hcd_queue_transactions(hsotg, DWC2_TRANSACTION_ALL);
spin_unlock_irqrestore(&hsotg->lock, flags);
}
static void dwc2_change_bus_speed(struct usb_hcd *hcd, int speed)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
if (hsotg->params.speed == speed)
return;
hsotg->params.speed = speed;
queue_work(hsotg->wq_otg, &hsotg->wf_otg);
}
static void dwc2_free_dev(struct usb_hcd *hcd, struct usb_device *udev)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
if (!hsotg->params.change_speed_quirk)
return;
if (udev->parent && udev->parent->speed > USB_SPEED_UNKNOWN &&
udev->parent->speed < USB_SPEED_HIGH) {
dev_info(hsotg->dev, "Set speed to default high-speed\n");
dwc2_change_bus_speed(hcd, HPRT0_SPD_HIGH_SPEED);
}
}
static int dwc2_reset_device(struct usb_hcd *hcd, struct usb_device *udev)
{
struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);
if (!hsotg->params.change_speed_quirk)
return 0;
if (udev->speed == USB_SPEED_HIGH) {
dev_info(hsotg->dev, "Set speed to high-speed\n");
dwc2_change_bus_speed(hcd, HPRT0_SPD_HIGH_SPEED);
} else if ((udev->speed == USB_SPEED_FULL ||
udev->speed == USB_SPEED_LOW)) {
dev_info(hsotg->dev, "Set speed to full-speed\n");
dwc2_change_bus_speed(hcd, HPRT0_SPD_FULL_SPEED);
}
return 0;
}
static void dwc2_hcd_free(struct dwc2_hsotg *hsotg)
{
u32 ahbcfg;
u32 dctl;
int i;
dev_dbg(hsotg->dev, "DWC OTG HCD FREE\n");
dwc2_qh_list_free(hsotg, &hsotg->non_periodic_sched_inactive);
dwc2_qh_list_free(hsotg, &hsotg->non_periodic_sched_active);
dwc2_qh_list_free(hsotg, &hsotg->periodic_sched_inactive);
dwc2_qh_list_free(hsotg, &hsotg->periodic_sched_ready);
dwc2_qh_list_free(hsotg, &hsotg->periodic_sched_assigned);
dwc2_qh_list_free(hsotg, &hsotg->periodic_sched_queued);
for (i = 0; i < MAX_EPS_CHANNELS; i++) {
struct dwc2_host_chan *chan = hsotg->hc_ptr_array[i];
if (chan) {
dev_dbg(hsotg->dev, "HCD Free channel #%i, chan=%p\n",
i, chan);
hsotg->hc_ptr_array[i] = NULL;
kfree(chan);
}
}
if (hsotg->params.host_dma) {
if (hsotg->status_buf) {
dma_free_coherent(hsotg->dev, DWC2_HCD_STATUS_BUF_SIZE,
hsotg->status_buf,
hsotg->status_buf_dma);
hsotg->status_buf = NULL;
}
} else {
kfree(hsotg->status_buf);
hsotg->status_buf = NULL;
}
ahbcfg = dwc2_readl(hsotg->regs + GAHBCFG);
ahbcfg &= ~GAHBCFG_GLBL_INTR_EN;
dwc2_writel(ahbcfg, hsotg->regs + GAHBCFG);
dwc2_writel(0, hsotg->regs + GINTMSK);
if (hsotg->hw_params.snpsid >= DWC2_CORE_REV_3_00a) {
dctl = dwc2_readl(hsotg->regs + DCTL);
dctl |= DCTL_SFTDISCON;
dwc2_writel(dctl, hsotg->regs + DCTL);
}
if (hsotg->wq_otg) {
if (!cancel_work_sync(&hsotg->wf_otg))
flush_workqueue(hsotg->wq_otg);
destroy_workqueue(hsotg->wq_otg);
}
del_timer(&hsotg->wkp_timer);
}
static void dwc2_hcd_release(struct dwc2_hsotg *hsotg)
{
dwc2_disable_host_interrupts(hsotg);
dwc2_hcd_free(hsotg);
}
int dwc2_hcd_init(struct dwc2_hsotg *hsotg)
{
struct platform_device *pdev = to_platform_device(hsotg->dev);
struct resource *res;
struct usb_hcd *hcd;
struct dwc2_host_chan *channel;
u32 hcfg;
int i, num_channels;
int retval;
if (usb_disabled())
return -ENODEV;
dev_dbg(hsotg->dev, "DWC OTG HCD INIT\n");
retval = -ENOMEM;
hcfg = dwc2_readl(hsotg->regs + HCFG);
dev_dbg(hsotg->dev, "hcfg=%08x\n", hcfg);
#ifdef CONFIG_USB_DWC2_TRACK_MISSED_SOFS
hsotg->frame_num_array = kzalloc(sizeof(*hsotg->frame_num_array) *
FRAME_NUM_ARRAY_SIZE, GFP_KERNEL);
if (!hsotg->frame_num_array)
goto error1;
hsotg->last_frame_num_array = kzalloc(
sizeof(*hsotg->last_frame_num_array) *
FRAME_NUM_ARRAY_SIZE, GFP_KERNEL);
if (!hsotg->last_frame_num_array)
goto error1;
#endif
hsotg->last_frame_num = HFNUM_MAX_FRNUM;
if (hsotg->params.host_dma &&
!hsotg->dev->dma_mask) {
dev_warn(hsotg->dev,
"dma_mask not set, disabling DMA\n");
hsotg->params.host_dma = false;
hsotg->params.dma_desc_enable = false;
}
if (hsotg->params.host_dma) {
if (dma_set_mask(hsotg->dev, DMA_BIT_MASK(32)) < 0)
dev_warn(hsotg->dev, "can't set DMA mask\n");
if (dma_set_coherent_mask(hsotg->dev, DMA_BIT_MASK(32)) < 0)
dev_warn(hsotg->dev, "can't set coherent DMA mask\n");
}
if (hsotg->params.change_speed_quirk) {
dwc2_hc_driver.free_dev = dwc2_free_dev;
dwc2_hc_driver.reset_device = dwc2_reset_device;
}
hcd = usb_create_hcd(&dwc2_hc_driver, hsotg->dev, dev_name(hsotg->dev));
if (!hcd)
goto error1;
if (!hsotg->params.host_dma)
hcd->self.uses_dma = 0;
hcd->has_tt = 1;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
((struct wrapper_priv_data *)&hcd->hcd_priv)->hsotg = hsotg;
hsotg->priv = hcd;
dwc2_disable_global_interrupts(hsotg);
retval = dwc2_core_init(hsotg, true);
if (retval)
goto error2;
retval = -ENOMEM;
hsotg->wq_otg = alloc_ordered_workqueue("dwc2", 0);
if (!hsotg->wq_otg) {
dev_err(hsotg->dev, "Failed to create workqueue\n");
goto error2;
}
INIT_WORK(&hsotg->wf_otg, dwc2_conn_id_status_change);
setup_timer(&hsotg->wkp_timer, dwc2_wakeup_detected,
(unsigned long)hsotg);
INIT_LIST_HEAD(&hsotg->non_periodic_sched_inactive);
INIT_LIST_HEAD(&hsotg->non_periodic_sched_active);
INIT_LIST_HEAD(&hsotg->periodic_sched_inactive);
INIT_LIST_HEAD(&hsotg->periodic_sched_ready);
INIT_LIST_HEAD(&hsotg->periodic_sched_assigned);
INIT_LIST_HEAD(&hsotg->periodic_sched_queued);
INIT_LIST_HEAD(&hsotg->split_order);
INIT_LIST_HEAD(&hsotg->free_hc_list);
num_channels = hsotg->params.host_channels;
memset(&hsotg->hc_ptr_array[0], 0, sizeof(hsotg->hc_ptr_array));
for (i = 0; i < num_channels; i++) {
channel = kzalloc(sizeof(*channel), GFP_KERNEL);
if (!channel)
goto error3;
channel->hc_num = i;
INIT_LIST_HEAD(&channel->split_order_list_entry);
hsotg->hc_ptr_array[i] = channel;
}
INIT_DELAYED_WORK(&hsotg->start_work, dwc2_hcd_start_func);
INIT_DELAYED_WORK(&hsotg->reset_work, dwc2_hcd_reset_func);
if (hsotg->params.host_dma)
hsotg->status_buf = dma_alloc_coherent(hsotg->dev,
DWC2_HCD_STATUS_BUF_SIZE,
&hsotg->status_buf_dma, GFP_KERNEL);
else
hsotg->status_buf = kzalloc(DWC2_HCD_STATUS_BUF_SIZE,
GFP_KERNEL);
if (!hsotg->status_buf)
goto error3;
if (hsotg->params.dma_desc_enable ||
hsotg->params.dma_desc_fs_enable) {
hsotg->desc_gen_cache = kmem_cache_create("dwc2-gen-desc",
sizeof(struct dwc2_dma_desc) *
MAX_DMA_DESC_NUM_GENERIC, 512, SLAB_CACHE_DMA,
NULL);
if (!hsotg->desc_gen_cache) {
dev_err(hsotg->dev,
"unable to create dwc2 generic desc cache\n");
hsotg->params.dma_desc_enable = false;
hsotg->params.dma_desc_fs_enable = false;
}
hsotg->desc_hsisoc_cache = kmem_cache_create("dwc2-hsisoc-desc",
sizeof(struct dwc2_dma_desc) *
MAX_DMA_DESC_NUM_HS_ISOC, 512, 0, NULL);
if (!hsotg->desc_hsisoc_cache) {
dev_err(hsotg->dev,
"unable to create dwc2 hs isoc desc cache\n");
kmem_cache_destroy(hsotg->desc_gen_cache);
hsotg->params.dma_desc_enable = false;
hsotg->params.dma_desc_fs_enable = false;
}
}
hsotg->otg_port = 1;
hsotg->frame_list = NULL;
hsotg->frame_list_dma = 0;
hsotg->periodic_qh_count = 0;
hsotg->lx_state = DWC2_L3;
hcd->self.otg_port = hsotg->otg_port;
hcd->self.sg_tablesize = 0;
if (!IS_ERR_OR_NULL(hsotg->uphy))
otg_set_host(hsotg->uphy->otg, &hcd->self);
retval = usb_add_hcd(hcd, hsotg->irq, IRQF_SHARED);
if (retval < 0)
goto error4;
device_wakeup_enable(hcd->self.controller);
dwc2_hcd_dump_state(hsotg);
dwc2_enable_global_interrupts(hsotg);
return 0;
error4:
kmem_cache_destroy(hsotg->desc_gen_cache);
kmem_cache_destroy(hsotg->desc_hsisoc_cache);
error3:
dwc2_hcd_release(hsotg);
error2:
usb_put_hcd(hcd);
error1:
#ifdef CONFIG_USB_DWC2_TRACK_MISSED_SOFS
kfree(hsotg->last_frame_num_array);
kfree(hsotg->frame_num_array);
#endif
dev_err(hsotg->dev, "%s() FAILED, returning %d\n", __func__, retval);
return retval;
}
void dwc2_hcd_remove(struct dwc2_hsotg *hsotg)
{
struct usb_hcd *hcd;
dev_dbg(hsotg->dev, "DWC OTG HCD REMOVE\n");
hcd = dwc2_hsotg_to_hcd(hsotg);
dev_dbg(hsotg->dev, "hsotg->hcd = %p\n", hcd);
if (!hcd) {
dev_dbg(hsotg->dev, "%s: dwc2_hsotg_to_hcd(hsotg) NULL!\n",
__func__);
return;
}
if (!IS_ERR_OR_NULL(hsotg->uphy))
otg_set_host(hsotg->uphy->otg, NULL);
usb_remove_hcd(hcd);
hsotg->priv = NULL;
kmem_cache_destroy(hsotg->desc_gen_cache);
kmem_cache_destroy(hsotg->desc_hsisoc_cache);
dwc2_hcd_release(hsotg);
usb_put_hcd(hcd);
#ifdef CONFIG_USB_DWC2_TRACK_MISSED_SOFS
kfree(hsotg->last_frame_num_array);
kfree(hsotg->frame_num_array);
#endif
}
int dwc2_backup_host_registers(struct dwc2_hsotg *hsotg)
{
struct dwc2_hregs_backup *hr;
int i;
dev_dbg(hsotg->dev, "%s\n", __func__);
hr = &hsotg->hr_backup;
hr->hcfg = dwc2_readl(hsotg->regs + HCFG);
hr->haintmsk = dwc2_readl(hsotg->regs + HAINTMSK);
for (i = 0; i < hsotg->params.host_channels; ++i)
hr->hcintmsk[i] = dwc2_readl(hsotg->regs + HCINTMSK(i));
hr->hprt0 = dwc2_read_hprt0(hsotg);
hr->hfir = dwc2_readl(hsotg->regs + HFIR);
hr->valid = true;
return 0;
}
int dwc2_restore_host_registers(struct dwc2_hsotg *hsotg)
{
struct dwc2_hregs_backup *hr;
int i;
dev_dbg(hsotg->dev, "%s\n", __func__);
hr = &hsotg->hr_backup;
if (!hr->valid) {
dev_err(hsotg->dev, "%s: no host registers to restore\n",
__func__);
return -EINVAL;
}
hr->valid = false;
dwc2_writel(hr->hcfg, hsotg->regs + HCFG);
dwc2_writel(hr->haintmsk, hsotg->regs + HAINTMSK);
for (i = 0; i < hsotg->params.host_channels; ++i)
dwc2_writel(hr->hcintmsk[i], hsotg->regs + HCINTMSK(i));
dwc2_writel(hr->hprt0, hsotg->regs + HPRT0);
dwc2_writel(hr->hfir, hsotg->regs + HFIR);
hsotg->frame_number = 0;
return 0;
}
