static inline void pch_can_bit_set(void __iomem *addr, u32 mask)
{
iowrite32(ioread32(addr) | mask, addr);
}
static inline void pch_can_bit_clear(void __iomem *addr, u32 mask)
{
iowrite32(ioread32(addr) & ~mask, addr);
}
static void pch_can_set_run_mode(struct pch_can_priv *priv,
enum pch_can_mode mode)
{
switch (mode) {
case PCH_CAN_RUN:
pch_can_bit_clear(&priv->regs->cont, PCH_CTRL_INIT);
break;
case PCH_CAN_STOP:
pch_can_bit_set(&priv->regs->cont, PCH_CTRL_INIT);
break;
default:
netdev_err(priv->ndev, "%s -> Invalid Mode.\n", __func__);
break;
}
}
static void pch_can_set_optmode(struct pch_can_priv *priv)
{
u32 reg_val = ioread32(&priv->regs->opt);
if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY)
reg_val |= PCH_OPT_SILENT;
if (priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK)
reg_val |= PCH_OPT_LBACK;
pch_can_bit_set(&priv->regs->cont, PCH_CTRL_OPT);
iowrite32(reg_val, &priv->regs->opt);
}
static void pch_can_rw_msg_obj(void __iomem *creq_addr, u32 num)
{
int counter = PCH_COUNTER_LIMIT;
u32 ifx_creq;
iowrite32(num, creq_addr);
while (counter) {
ifx_creq = ioread32(creq_addr) & PCH_IF_CREQ_BUSY;
if (!ifx_creq)
break;
counter--;
udelay(1);
}
if (!counter)
pr_err("%s:IF1 BUSY Flag is set forever.\n", __func__);
}
static void pch_can_set_int_enables(struct pch_can_priv *priv,
enum pch_can_mode interrupt_no)
{
switch (interrupt_no) {
case PCH_CAN_DISABLE:
pch_can_bit_clear(&priv->regs->cont, PCH_CTRL_IE);
break;
case PCH_CAN_ALL:
pch_can_bit_set(&priv->regs->cont, PCH_CTRL_IE_SIE_EIE);
break;
case PCH_CAN_NONE:
pch_can_bit_clear(&priv->regs->cont, PCH_CTRL_IE_SIE_EIE);
break;
default:
netdev_err(priv->ndev, "Invalid interrupt number.\n");
break;
}
}
static void pch_can_set_rxtx(struct pch_can_priv *priv, u32 buff_num,
int set, enum pch_ifreg dir)
{
u32 ie;
if (dir)
ie = PCH_IF_MCONT_TXIE;
else
ie = PCH_IF_MCONT_RXIE;
iowrite32(PCH_CMASK_RX_TX_GET, &priv->regs->ifregs[dir].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[dir].creq, buff_num);
iowrite32(PCH_CMASK_RDWR | PCH_CMASK_ARB | PCH_CMASK_CTRL,
&priv->regs->ifregs[dir].cmask);
if (set) {
pch_can_bit_set(&priv->regs->ifregs[dir].mcont, ie);
pch_can_bit_set(&priv->regs->ifregs[dir].id2, PCH_ID_MSGVAL);
} else {
pch_can_bit_clear(&priv->regs->ifregs[dir].mcont, ie);
pch_can_bit_clear(&priv->regs->ifregs[dir].id2, PCH_ID_MSGVAL);
}
pch_can_rw_msg_obj(&priv->regs->ifregs[dir].creq, buff_num);
}
static void pch_can_set_rx_all(struct pch_can_priv *priv, int set)
{
int i;
for (i = PCH_RX_OBJ_START; i <= PCH_RX_OBJ_END; i++)
pch_can_set_rxtx(priv, i, set, PCH_RX_IFREG);
}
static void pch_can_set_tx_all(struct pch_can_priv *priv, int set)
{
int i;
for (i = PCH_TX_OBJ_START; i <= PCH_TX_OBJ_END; i++)
pch_can_set_rxtx(priv, i, set, PCH_TX_IFREG);
}
static u32 pch_can_int_pending(struct pch_can_priv *priv)
{
return ioread32(&priv->regs->intr) & 0xffff;
}
static void pch_can_clear_if_buffers(struct pch_can_priv *priv)
{
int i;
for (i = PCH_RX_OBJ_START; i <= PCH_TX_OBJ_END; i++) {
iowrite32(PCH_CMASK_RX_TX_SET, &priv->regs->ifregs[0].cmask);
iowrite32(0xffff, &priv->regs->ifregs[0].mask1);
iowrite32(0xffff, &priv->regs->ifregs[0].mask2);
iowrite32(0x0, &priv->regs->ifregs[0].id1);
iowrite32(0x0, &priv->regs->ifregs[0].id2);
iowrite32(0x0, &priv->regs->ifregs[0].mcont);
iowrite32(0x0, &priv->regs->ifregs[0].data[0]);
iowrite32(0x0, &priv->regs->ifregs[0].data[1]);
iowrite32(0x0, &priv->regs->ifregs[0].data[2]);
iowrite32(0x0, &priv->regs->ifregs[0].data[3]);
iowrite32(PCH_CMASK_RDWR | PCH_CMASK_MASK |
PCH_CMASK_ARB | PCH_CMASK_CTRL,
&priv->regs->ifregs[0].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[0].creq, i);
}
}
static void pch_can_config_rx_tx_buffers(struct pch_can_priv *priv)
{
int i;
for (i = PCH_RX_OBJ_START; i <= PCH_RX_OBJ_END; i++) {
iowrite32(PCH_CMASK_RX_TX_GET, &priv->regs->ifregs[0].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[0].creq, i);
iowrite32(0x0, &priv->regs->ifregs[0].id1);
iowrite32(0x0, &priv->regs->ifregs[0].id2);
pch_can_bit_set(&priv->regs->ifregs[0].mcont,
PCH_IF_MCONT_UMASK);
if (i == PCH_RX_OBJ_END)
pch_can_bit_set(&priv->regs->ifregs[0].mcont,
PCH_IF_MCONT_EOB);
else
pch_can_bit_clear(&priv->regs->ifregs[0].mcont,
PCH_IF_MCONT_EOB);
iowrite32(0, &priv->regs->ifregs[0].mask1);
pch_can_bit_clear(&priv->regs->ifregs[0].mask2,
0x1fff | PCH_MASK2_MDIR_MXTD);
iowrite32(PCH_CMASK_RDWR | PCH_CMASK_MASK | PCH_CMASK_ARB |
PCH_CMASK_CTRL, &priv->regs->ifregs[0].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[0].creq, i);
}
for (i = PCH_TX_OBJ_START; i <= PCH_TX_OBJ_END; i++) {
iowrite32(PCH_CMASK_RX_TX_GET, &priv->regs->ifregs[1].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[1].creq, i);
iowrite32(0x0, &priv->regs->ifregs[1].id1);
iowrite32(PCH_ID2_DIR, &priv->regs->ifregs[1].id2);
iowrite32(PCH_IF_MCONT_EOB | PCH_IF_MCONT_UMASK,
&priv->regs->ifregs[1].mcont);
iowrite32(0, &priv->regs->ifregs[1].mask1);
pch_can_bit_clear(&priv->regs->ifregs[1].mask2, 0x1fff);
iowrite32(PCH_CMASK_RDWR | PCH_CMASK_MASK | PCH_CMASK_ARB |
PCH_CMASK_CTRL, &priv->regs->ifregs[1].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[1].creq, i);
}
}
static void pch_can_init(struct pch_can_priv *priv)
{
pch_can_set_run_mode(priv, PCH_CAN_STOP);
pch_can_clear_if_buffers(priv);
pch_can_config_rx_tx_buffers(priv);
pch_can_set_int_enables(priv, PCH_CAN_ALL);
}
static void pch_can_release(struct pch_can_priv *priv)
{
pch_can_set_run_mode(priv, PCH_CAN_STOP);
pch_can_set_int_enables(priv, PCH_CAN_NONE);
pch_can_set_rx_all(priv, 0);
pch_can_set_tx_all(priv, 0);
}
static void pch_can_int_clr(struct pch_can_priv *priv, u32 mask)
{
if ((mask >= PCH_RX_OBJ_START) && (mask <= PCH_RX_OBJ_END)) {
iowrite32(PCH_CMASK_RDWR | PCH_CMASK_CTRL | PCH_CMASK_ARB,
&priv->regs->ifregs[0].cmask);
pch_can_bit_clear(&priv->regs->ifregs[0].id2, PCH_ID2_DIR);
pch_can_bit_clear(&priv->regs->ifregs[0].mcont,
PCH_IF_MCONT_NEWDAT | PCH_IF_MCONT_INTPND);
pch_can_rw_msg_obj(&priv->regs->ifregs[0].creq, mask);
} else if ((mask >= PCH_TX_OBJ_START) && (mask <= PCH_TX_OBJ_END)) {
iowrite32(PCH_CMASK_RDWR | PCH_CMASK_CTRL | PCH_CMASK_ARB,
&priv->regs->ifregs[1].cmask);
pch_can_bit_set(&priv->regs->ifregs[1].id2,
PCH_ID2_DIR | (0x7ff << 2));
iowrite32(0x0, &priv->regs->ifregs[1].id1);
pch_can_bit_clear(&priv->regs->ifregs[1].mcont,
PCH_IF_MCONT_NEWDAT | PCH_IF_MCONT_INTPND |
PCH_IF_MCONT_TXRQXT);
pch_can_rw_msg_obj(&priv->regs->ifregs[1].creq, mask);
}
}
static void pch_can_reset(struct pch_can_priv *priv)
{
iowrite32(1, &priv->regs->srst);
iowrite32(0, &priv->regs->srst);
}
static void pch_can_error(struct net_device *ndev, u32 status)
{
struct sk_buff *skb;
struct pch_can_priv *priv = netdev_priv(ndev);
struct can_frame *cf;
u32 errc, lec;
struct net_device_stats *stats = &(priv->ndev->stats);
enum can_state state = priv->can.state;
skb = alloc_can_err_skb(ndev, &cf);
if (!skb)
return;
if (status & PCH_BUS_OFF) {
pch_can_set_tx_all(priv, 0);
pch_can_set_rx_all(priv, 0);
state = CAN_STATE_BUS_OFF;
cf->can_id |= CAN_ERR_BUSOFF;
can_bus_off(ndev);
}
errc = ioread32(&priv->regs->errc);
if (status & PCH_EWARN) {
state = CAN_STATE_ERROR_WARNING;
priv->can.can_stats.error_warning++;
cf->can_id |= CAN_ERR_CRTL;
if (((errc & PCH_REC) >> 8) > 96)
cf->data[1] |= CAN_ERR_CRTL_RX_WARNING;
if ((errc & PCH_TEC) > 96)
cf->data[1] |= CAN_ERR_CRTL_TX_WARNING;
netdev_dbg(ndev,
"%s -> Error Counter is more than 96.\n", __func__);
}
if (status & PCH_EPASSIV) {
priv->can.can_stats.error_passive++;
state = CAN_STATE_ERROR_PASSIVE;
cf->can_id |= CAN_ERR_CRTL;
if (errc & PCH_RP)
cf->data[1] |= CAN_ERR_CRTL_RX_PASSIVE;
if ((errc & PCH_TEC) > 127)
cf->data[1] |= CAN_ERR_CRTL_TX_PASSIVE;
netdev_dbg(ndev,
"%s -> CAN controller is ERROR PASSIVE .\n", __func__);
}
lec = status & PCH_LEC_ALL;
switch (lec) {
case PCH_STUF_ERR:
cf->data[2] |= CAN_ERR_PROT_STUFF;
priv->can.can_stats.bus_error++;
stats->rx_errors++;
break;
case PCH_FORM_ERR:
cf->data[2] |= CAN_ERR_PROT_FORM;
priv->can.can_stats.bus_error++;
stats->rx_errors++;
break;
case PCH_ACK_ERR:
cf->can_id |= CAN_ERR_ACK;
priv->can.can_stats.bus_error++;
stats->rx_errors++;
break;
case PCH_BIT1_ERR:
case PCH_BIT0_ERR:
cf->data[2] |= CAN_ERR_PROT_BIT;
priv->can.can_stats.bus_error++;
stats->rx_errors++;
break;
case PCH_CRC_ERR:
cf->data[3] |= CAN_ERR_PROT_LOC_CRC_SEQ |
CAN_ERR_PROT_LOC_CRC_DEL;
priv->can.can_stats.bus_error++;
stats->rx_errors++;
break;
case PCH_LEC_ALL:
break;
}
cf->data[6] = errc & PCH_TEC;
cf->data[7] = (errc & PCH_REC) >> 8;
priv->can.state = state;
netif_receive_skb(skb);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
}
static irqreturn_t pch_can_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = (struct net_device *)dev_id;
struct pch_can_priv *priv = netdev_priv(ndev);
if (!pch_can_int_pending(priv))
return IRQ_NONE;
pch_can_set_int_enables(priv, PCH_CAN_NONE);
napi_schedule(&priv->napi);
return IRQ_HANDLED;
}
static void pch_fifo_thresh(struct pch_can_priv *priv, int obj_id)
{
if (obj_id < PCH_FIFO_THRESH) {
iowrite32(PCH_CMASK_RDWR | PCH_CMASK_CTRL |
PCH_CMASK_ARB, &priv->regs->ifregs[0].cmask);
pch_can_bit_clear(&priv->regs->ifregs[0].id2, PCH_ID2_DIR);
pch_can_bit_clear(&priv->regs->ifregs[0].mcont,
PCH_IF_MCONT_INTPND);
pch_can_rw_msg_obj(&priv->regs->ifregs[0].creq, obj_id);
} else if (obj_id > PCH_FIFO_THRESH) {
pch_can_int_clr(priv, obj_id);
} else if (obj_id == PCH_FIFO_THRESH) {
int cnt;
for (cnt = 0; cnt < PCH_FIFO_THRESH; cnt++)
pch_can_int_clr(priv, cnt + 1);
}
}
static void pch_can_rx_msg_lost(struct net_device *ndev, int obj_id)
{
struct pch_can_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &(priv->ndev->stats);
struct sk_buff *skb;
struct can_frame *cf;
netdev_dbg(priv->ndev, "Msg Obj is overwritten.\n");
pch_can_bit_clear(&priv->regs->ifregs[0].mcont,
PCH_IF_MCONT_MSGLOST);
iowrite32(PCH_CMASK_RDWR | PCH_CMASK_CTRL,
&priv->regs->ifregs[0].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[0].creq, obj_id);
skb = alloc_can_err_skb(ndev, &cf);
if (!skb)
return;
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
stats->rx_over_errors++;
stats->rx_errors++;
netif_receive_skb(skb);
}
static int pch_can_rx_normal(struct net_device *ndev, u32 obj_num, int quota)
{
u32 reg;
canid_t id;
int rcv_pkts = 0;
struct sk_buff *skb;
struct can_frame *cf;
struct pch_can_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &(priv->ndev->stats);
int i;
u32 id2;
u16 data_reg;
do {
iowrite32(PCH_CMASK_RX_TX_GET, &priv->regs->ifregs[0].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[0].creq, obj_num);
reg = ioread32(&priv->regs->ifregs[0].mcont);
if (reg & PCH_IF_MCONT_EOB)
break;
if (reg & PCH_IF_MCONT_MSGLOST) {
pch_can_rx_msg_lost(ndev, obj_num);
rcv_pkts++;
quota--;
obj_num++;
continue;
} else if (!(reg & PCH_IF_MCONT_NEWDAT)) {
obj_num++;
continue;
}
skb = alloc_can_skb(priv->ndev, &cf);
if (!skb) {
netdev_err(ndev, "alloc_can_skb Failed\n");
return rcv_pkts;
}
id2 = ioread32(&priv->regs->ifregs[0].id2);
if (id2 & PCH_ID2_XTD) {
id = (ioread32(&priv->regs->ifregs[0].id1) & 0xffff);
id |= (((id2) & 0x1fff) << 16);
cf->can_id = id | CAN_EFF_FLAG;
} else {
id = (id2 >> 2) & CAN_SFF_MASK;
cf->can_id = id;
}
if (id2 & PCH_ID2_DIR)
cf->can_id |= CAN_RTR_FLAG;
cf->can_dlc = get_can_dlc((ioread32(&priv->regs->
ifregs[0].mcont)) & 0xF);
for (i = 0; i < cf->can_dlc; i += 2) {
data_reg = ioread16(&priv->regs->ifregs[0].data[i / 2]);
cf->data[i] = data_reg;
cf->data[i + 1] = data_reg >> 8;
}
netif_receive_skb(skb);
rcv_pkts++;
stats->rx_packets++;
quota--;
stats->rx_bytes += cf->can_dlc;
pch_fifo_thresh(priv, obj_num);
obj_num++;
} while (quota > 0);
return rcv_pkts;
}
static void pch_can_tx_complete(struct net_device *ndev, u32 int_stat)
{
struct pch_can_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &(priv->ndev->stats);
u32 dlc;
can_get_echo_skb(ndev, int_stat - PCH_RX_OBJ_END - 1);
iowrite32(PCH_CMASK_RX_TX_GET | PCH_CMASK_CLRINTPND,
&priv->regs->ifregs[1].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[1].creq, int_stat);
dlc = get_can_dlc(ioread32(&priv->regs->ifregs[1].mcont) &
PCH_IF_MCONT_DLC);
stats->tx_bytes += dlc;
stats->tx_packets++;
if (int_stat == PCH_TX_OBJ_END)
netif_wake_queue(ndev);
}
static int pch_can_poll(struct napi_struct *napi, int quota)
{
struct net_device *ndev = napi->dev;
struct pch_can_priv *priv = netdev_priv(ndev);
u32 int_stat;
u32 reg_stat;
int quota_save = quota;
int_stat = pch_can_int_pending(priv);
if (!int_stat)
goto end;
if (int_stat == PCH_STATUS_INT) {
reg_stat = ioread32(&priv->regs->stat);
if ((reg_stat & (PCH_BUS_OFF | PCH_LEC_ALL)) &&
((reg_stat & PCH_LEC_ALL) != PCH_LEC_ALL)) {
pch_can_error(ndev, reg_stat);
quota--;
}
if (reg_stat & (PCH_TX_OK | PCH_RX_OK))
pch_can_bit_clear(&priv->regs->stat,
reg_stat & (PCH_TX_OK | PCH_RX_OK));
int_stat = pch_can_int_pending(priv);
}
if (quota == 0)
goto end;
if ((int_stat >= PCH_RX_OBJ_START) && (int_stat <= PCH_RX_OBJ_END)) {
quota -= pch_can_rx_normal(ndev, int_stat, quota);
} else if ((int_stat >= PCH_TX_OBJ_START) &&
(int_stat <= PCH_TX_OBJ_END)) {
pch_can_tx_complete(ndev, int_stat);
}
end:
napi_complete(napi);
pch_can_set_int_enables(priv, PCH_CAN_ALL);
return quota_save - quota;
}
static int pch_set_bittiming(struct net_device *ndev)
{
struct pch_can_priv *priv = netdev_priv(ndev);
const struct can_bittiming *bt = &priv->can.bittiming;
u32 canbit;
u32 bepe;
pch_can_bit_set(&priv->regs->cont, PCH_CTRL_CCE);
canbit = (bt->brp - 1) & PCH_MSK_BITT_BRP;
canbit |= (bt->sjw - 1) << PCH_BIT_SJW_SHIFT;
canbit |= (bt->phase_seg1 + bt->prop_seg - 1) << PCH_BIT_TSEG1_SHIFT;
canbit |= (bt->phase_seg2 - 1) << PCH_BIT_TSEG2_SHIFT;
bepe = ((bt->brp - 1) & PCH_MSK_BRPE_BRPE) >> PCH_BIT_BRPE_BRPE_SHIFT;
iowrite32(canbit, &priv->regs->bitt);
iowrite32(bepe, &priv->regs->brpe);
pch_can_bit_clear(&priv->regs->cont, PCH_CTRL_CCE);
return 0;
}
static void pch_can_start(struct net_device *ndev)
{
struct pch_can_priv *priv = netdev_priv(ndev);
if (priv->can.state != CAN_STATE_STOPPED)
pch_can_reset(priv);
pch_set_bittiming(ndev);
pch_can_set_optmode(priv);
pch_can_set_tx_all(priv, 1);
pch_can_set_rx_all(priv, 1);
pch_can_set_run_mode(priv, PCH_CAN_RUN);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
return;
}
static int pch_can_do_set_mode(struct net_device *ndev, enum can_mode mode)
{
int ret = 0;
switch (mode) {
case CAN_MODE_START:
pch_can_start(ndev);
netif_wake_queue(ndev);
break;
default:
ret = -EOPNOTSUPP;
break;
}
return ret;
}
static int pch_can_open(struct net_device *ndev)
{
struct pch_can_priv *priv = netdev_priv(ndev);
int retval;
retval = request_irq(priv->dev->irq, pch_can_interrupt, IRQF_SHARED,
ndev->name, ndev);
if (retval) {
netdev_err(ndev, "request_irq failed.\n");
goto req_irq_err;
}
retval = open_candev(ndev);
if (retval) {
netdev_err(ndev, "open_candev() failed %d\n", retval);
goto err_open_candev;
}
pch_can_init(priv);
pch_can_start(ndev);
napi_enable(&priv->napi);
netif_start_queue(ndev);
return 0;
err_open_candev:
free_irq(priv->dev->irq, ndev);
req_irq_err:
pch_can_release(priv);
return retval;
}
static int pch_close(struct net_device *ndev)
{
struct pch_can_priv *priv = netdev_priv(ndev);
netif_stop_queue(ndev);
napi_disable(&priv->napi);
pch_can_release(priv);
free_irq(priv->dev->irq, ndev);
close_candev(ndev);
priv->can.state = CAN_STATE_STOPPED;
return 0;
}
static netdev_tx_t pch_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct pch_can_priv *priv = netdev_priv(ndev);
struct can_frame *cf = (struct can_frame *)skb->data;
int tx_obj_no;
int i;
u32 id2;
if (can_dropped_invalid_skb(ndev, skb))
return NETDEV_TX_OK;
tx_obj_no = priv->tx_obj;
if (priv->tx_obj == PCH_TX_OBJ_END) {
if (ioread32(&priv->regs->treq2) & PCH_TREQ2_TX_MASK)
netif_stop_queue(ndev);
priv->tx_obj = PCH_TX_OBJ_START;
} else {
priv->tx_obj++;
}
pch_can_bit_set(&priv->regs->ifregs[1].cmask, PCH_CMASK_ALL);
if (cf->can_id & CAN_EFF_FLAG) {
iowrite32(cf->can_id & 0xffff, &priv->regs->ifregs[1].id1);
id2 = ((cf->can_id >> 16) & 0x1fff) | PCH_ID2_XTD;
} else {
iowrite32(0, &priv->regs->ifregs[1].id1);
id2 = (cf->can_id & CAN_SFF_MASK) << 2;
}
id2 |= PCH_ID_MSGVAL;
if (!(cf->can_id & CAN_RTR_FLAG))
id2 |= PCH_ID2_DIR;
iowrite32(id2, &priv->regs->ifregs[1].id2);
for (i = 0; i < cf->can_dlc; i += 2) {
iowrite16(cf->data[i] | (cf->data[i + 1] << 8),
&priv->regs->ifregs[1].data[i / 2]);
}
can_put_echo_skb(skb, ndev, tx_obj_no - PCH_RX_OBJ_END - 1);
iowrite32(cf->can_dlc | PCH_IF_MCONT_NEWDAT | PCH_IF_MCONT_TXRQXT |
PCH_IF_MCONT_TXIE, &priv->regs->ifregs[1].mcont);
pch_can_rw_msg_obj(&priv->regs->ifregs[1].creq, tx_obj_no);
return NETDEV_TX_OK;
}
static void pch_can_remove(struct pci_dev *pdev)
{
struct net_device *ndev = pci_get_drvdata(pdev);
struct pch_can_priv *priv = netdev_priv(ndev);
unregister_candev(priv->ndev);
if (priv->use_msi)
pci_disable_msi(priv->dev);
pci_release_regions(pdev);
pci_disable_device(pdev);
pch_can_reset(priv);
pci_iounmap(pdev, priv->regs);
free_candev(priv->ndev);
}
static void pch_can_set_int_custom(struct pch_can_priv *priv)
{
pch_can_bit_clear(&priv->regs->cont, PCH_CTRL_IE_SIE_EIE);
pch_can_bit_set(&priv->regs->cont,
((priv->int_enables & PCH_MSK_CTRL_IE_SIE_EIE) << 1));
}
static u32 pch_can_get_int_enables(struct pch_can_priv *priv)
{
return (ioread32(&priv->regs->cont) & PCH_CTRL_IE_SIE_EIE) >> 1;
}
static u32 pch_can_get_rxtx_ir(struct pch_can_priv *priv, u32 buff_num,
enum pch_ifreg dir)
{
u32 ie, enable;
if (dir)
ie = PCH_IF_MCONT_RXIE;
else
ie = PCH_IF_MCONT_TXIE;
iowrite32(PCH_CMASK_RX_TX_GET, &priv->regs->ifregs[dir].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[dir].creq, buff_num);
if (((ioread32(&priv->regs->ifregs[dir].id2)) & PCH_ID_MSGVAL) &&
((ioread32(&priv->regs->ifregs[dir].mcont)) & ie))
enable = 1;
else
enable = 0;
return enable;
}
static void pch_can_set_rx_buffer_link(struct pch_can_priv *priv,
u32 buffer_num, int set)
{
iowrite32(PCH_CMASK_RX_TX_GET, &priv->regs->ifregs[0].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[0].creq, buffer_num);
iowrite32(PCH_CMASK_RDWR | PCH_CMASK_CTRL,
&priv->regs->ifregs[0].cmask);
if (set)
pch_can_bit_clear(&priv->regs->ifregs[0].mcont,
PCH_IF_MCONT_EOB);
else
pch_can_bit_set(&priv->regs->ifregs[0].mcont, PCH_IF_MCONT_EOB);
pch_can_rw_msg_obj(&priv->regs->ifregs[0].creq, buffer_num);
}
static u32 pch_can_get_rx_buffer_link(struct pch_can_priv *priv, u32 buffer_num)
{
u32 link;
iowrite32(PCH_CMASK_RX_TX_GET, &priv->regs->ifregs[0].cmask);
pch_can_rw_msg_obj(&priv->regs->ifregs[0].creq, buffer_num);
if (ioread32(&priv->regs->ifregs[0].mcont) & PCH_IF_MCONT_EOB)
link = 0;
else
link = 1;
return link;
}
static int pch_can_get_buffer_status(struct pch_can_priv *priv)
{
return (ioread32(&priv->regs->treq1) & 0xffff) |
(ioread32(&priv->regs->treq2) << 16);
}
static int pch_can_suspend(struct pci_dev *pdev, pm_message_t state)
{
int i;
int retval;
u32 buf_stat;
int counter = PCH_COUNTER_LIMIT;
struct net_device *dev = pci_get_drvdata(pdev);
struct pch_can_priv *priv = netdev_priv(dev);
pch_can_set_run_mode(priv, PCH_CAN_STOP);
priv->can.state = CAN_STATE_STOPPED;
while (counter) {
buf_stat = pch_can_get_buffer_status(priv);
if (!buf_stat)
break;
counter--;
udelay(1);
}
if (!counter)
dev_err(&pdev->dev, "%s -> Transmission time out.\n", __func__);
priv->int_enables = pch_can_get_int_enables(priv);
pch_can_set_int_enables(priv, PCH_CAN_DISABLE);
for (i = PCH_TX_OBJ_START; i <= PCH_TX_OBJ_END; i++)
priv->tx_enable[i - 1] = pch_can_get_rxtx_ir(priv, i,
PCH_TX_IFREG);
pch_can_set_tx_all(priv, 0);
for (i = PCH_RX_OBJ_START; i <= PCH_RX_OBJ_END; i++) {
priv->rx_enable[i - 1] = pch_can_get_rxtx_ir(priv, i,
PCH_RX_IFREG);
priv->rx_link[i - 1] = pch_can_get_rx_buffer_link(priv, i);
}
pch_can_set_rx_all(priv, 0);
retval = pci_save_state(pdev);
if (retval) {
dev_err(&pdev->dev, "pci_save_state failed.\n");
} else {
pci_enable_wake(pdev, PCI_D3hot, 0);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
}
return retval;
}
static int pch_can_resume(struct pci_dev *pdev)
{
int i;
int retval;
struct net_device *dev = pci_get_drvdata(pdev);
struct pch_can_priv *priv = netdev_priv(dev);
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
retval = pci_enable_device(pdev);
if (retval) {
dev_err(&pdev->dev, "pci_enable_device failed.\n");
return retval;
}
pci_enable_wake(pdev, PCI_D3hot, 0);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
pch_can_set_int_enables(priv, PCH_CAN_DISABLE);
pch_can_set_run_mode(priv, PCH_CAN_STOP);
pch_can_config_rx_tx_buffers(priv);
pch_set_bittiming(dev);
pch_can_set_optmode(priv);
for (i = PCH_TX_OBJ_START; i <= PCH_TX_OBJ_END; i++)
pch_can_set_rxtx(priv, i, priv->tx_enable[i - 1], PCH_TX_IFREG);
for (i = PCH_RX_OBJ_START; i <= PCH_RX_OBJ_END; i++) {
pch_can_set_rx_buffer_link(priv, i, priv->rx_link[i - 1]);
pch_can_set_rxtx(priv, i, priv->rx_enable[i - 1], PCH_RX_IFREG);
}
pch_can_set_int_custom(priv);
pch_can_set_run_mode(priv, PCH_CAN_RUN);
return retval;
}
static int pch_can_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
struct pch_can_priv *priv = netdev_priv(dev);
u32 errc = ioread32(&priv->regs->errc);
bec->txerr = errc & PCH_TEC;
bec->rxerr = (errc & PCH_REC) >> 8;
return 0;
}
static int pch_can_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct net_device *ndev;
struct pch_can_priv *priv;
int rc;
void __iomem *addr;
rc = pci_enable_device(pdev);
if (rc) {
dev_err(&pdev->dev, "Failed pci_enable_device %d\n", rc);
goto probe_exit_endev;
}
rc = pci_request_regions(pdev, KBUILD_MODNAME);
if (rc) {
dev_err(&pdev->dev, "Failed pci_request_regions %d\n", rc);
goto probe_exit_pcireq;
}
addr = pci_iomap(pdev, 1, 0);
if (!addr) {
rc = -EIO;
dev_err(&pdev->dev, "Failed pci_iomap\n");
goto probe_exit_ipmap;
}
ndev = alloc_candev(sizeof(struct pch_can_priv), PCH_TX_OBJ_END);
if (!ndev) {
rc = -ENOMEM;
dev_err(&pdev->dev, "Failed alloc_candev\n");
goto probe_exit_alloc_candev;
}
priv = netdev_priv(ndev);
priv->ndev = ndev;
priv->regs = addr;
priv->dev = pdev;
priv->can.bittiming_const = &pch_can_bittiming_const;
priv->can.do_set_mode = pch_can_do_set_mode;
priv->can.do_get_berr_counter = pch_can_get_berr_counter;
priv->can.ctrlmode_supported = CAN_CTRLMODE_LISTENONLY |
CAN_CTRLMODE_LOOPBACK;
priv->tx_obj = PCH_TX_OBJ_START;
ndev->irq = pdev->irq;
ndev->flags |= IFF_ECHO;
pci_set_drvdata(pdev, ndev);
SET_NETDEV_DEV(ndev, &pdev->dev);
ndev->netdev_ops = &pch_can_netdev_ops;
priv->can.clock.freq = PCH_CAN_CLK;
netif_napi_add(ndev, &priv->napi, pch_can_poll, PCH_RX_OBJ_END);
rc = pci_enable_msi(priv->dev);
if (rc) {
netdev_err(ndev, "PCH CAN opened without MSI\n");
priv->use_msi = 0;
} else {
netdev_err(ndev, "PCH CAN opened with MSI\n");
pci_set_master(pdev);
priv->use_msi = 1;
}
rc = register_candev(ndev);
if (rc) {
dev_err(&pdev->dev, "Failed register_candev %d\n", rc);
goto probe_exit_reg_candev;
}
return 0;
probe_exit_reg_candev:
if (priv->use_msi)
pci_disable_msi(priv->dev);
free_candev(ndev);
probe_exit_alloc_candev:
pci_iounmap(pdev, addr);
probe_exit_ipmap:
pci_release_regions(pdev);
probe_exit_pcireq:
pci_disable_device(pdev);
probe_exit_endev:
return rc;
}
