int fsl_rio_mcheck_exception(struct pt_regs *regs)
{
const struct exception_table_entry *entry;
unsigned long reason;
if (!rio_regs_win)
return 0;
reason = in_be32((u32 *)(rio_regs_win + RIO_LTLEDCSR));
if (reason & (RIO_LTLEDCSR_IER | RIO_LTLEDCSR_PRT)) {
entry = search_exception_tables(regs->nip);
if (entry) {
pr_debug("RIO: %s - MC Exception handled\n",
__func__);
out_be32((u32 *)(rio_regs_win + RIO_LTLEDCSR),
0);
regs->msr |= MSR_RI;
regs->nip = entry->fixup;
return 1;
}
}
return 0;
}
static int fsl_rio_doorbell_send(struct rio_mport *mport,
int index, u16 destid, u16 data)
{
struct rio_priv *priv = mport->priv;
pr_debug("fsl_doorbell_send: index %d destid %4.4x data %4.4x\n",
index, destid, data);
switch (mport->phy_type) {
case RIO_PHY_PARALLEL:
out_be32(&priv->dbell_atmu_regs->rowtar, destid << 22);
out_be16(priv->dbell_win, data);
break;
case RIO_PHY_SERIAL:
out_be32(&priv->msg_regs->odmr, 0x00000000);
out_be32(&priv->msg_regs->odretcr, 0x00000004);
out_be32(&priv->msg_regs->oddpr, destid << 16);
out_be32(&priv->msg_regs->oddatr, data);
out_be32(&priv->msg_regs->odmr, 0x00000001);
break;
}
return 0;
}
static int fsl_local_config_read(struct rio_mport *mport,
int index, u32 offset, int len, u32 *data)
{
struct rio_priv *priv = mport->priv;
pr_debug("fsl_local_config_read: index %d offset %8.8x\n", index,
offset);
*data = in_be32(priv->regs_win + offset);
return 0;
}
static int fsl_local_config_write(struct rio_mport *mport,
int index, u32 offset, int len, u32 data)
{
struct rio_priv *priv = mport->priv;
pr_debug
("fsl_local_config_write: index %d offset %8.8x data %8.8x\n",
index, offset, data);
out_be32(priv->regs_win + offset, data);
return 0;
}
static int
fsl_rio_config_read(struct rio_mport *mport, int index, u16 destid,
u8 hopcount, u32 offset, int len, u32 *val)
{
struct rio_priv *priv = mport->priv;
u8 *data;
u32 rval, err = 0;
pr_debug
("fsl_rio_config_read: index %d destid %d hopcount %d offset %8.8x len %d\n",
index, destid, hopcount, offset, len);
if (offset > (0x1000000 - len) || !IS_ALIGNED(offset, len))
return -EINVAL;
out_be32(&priv->maint_atmu_regs->rowtar,
(destid << 22) | (hopcount << 12) | (offset >> 12));
out_be32(&priv->maint_atmu_regs->rowtear, (destid >> 10));
data = (u8 *) priv->maint_win + (offset & (RIO_MAINT_WIN_SIZE - 1));
switch (len) {
case 1:
__fsl_read_rio_config(rval, data, err, "lbz");
break;
case 2:
__fsl_read_rio_config(rval, data, err, "lhz");
break;
case 4:
__fsl_read_rio_config(rval, data, err, "lwz");
break;
default:
return -EINVAL;
}
if (err) {
pr_debug("RIO: cfg_read error %d for %x:%x:%x\n",
err, destid, hopcount, offset);
}
*val = rval;
return err;
}
static int
fsl_rio_config_write(struct rio_mport *mport, int index, u16 destid,
u8 hopcount, u32 offset, int len, u32 val)
{
struct rio_priv *priv = mport->priv;
u8 *data;
pr_debug
("fsl_rio_config_write: index %d destid %d hopcount %d offset %8.8x len %d val %8.8x\n",
index, destid, hopcount, offset, len, val);
if (offset > (0x1000000 - len) || !IS_ALIGNED(offset, len))
return -EINVAL;
out_be32(&priv->maint_atmu_regs->rowtar,
(destid << 22) | (hopcount << 12) | (offset >> 12));
out_be32(&priv->maint_atmu_regs->rowtear, (destid >> 10));
data = (u8 *) priv->maint_win + (offset & (RIO_MAINT_WIN_SIZE - 1));
switch (len) {
case 1:
out_8((u8 *) data, val);
break;
case 2:
out_be16((u16 *) data, val);
break;
case 4:
out_be32((u32 *) data, val);
break;
default:
return -EINVAL;
}
return 0;
}
static int
fsl_add_outb_message(struct rio_mport *mport, struct rio_dev *rdev, int mbox,
void *buffer, size_t len)
{
struct rio_priv *priv = mport->priv;
u32 omr;
struct rio_tx_desc *desc = (struct rio_tx_desc *)priv->msg_tx_ring.virt
+ priv->msg_tx_ring.tx_slot;
int ret = 0;
pr_debug("RIO: fsl_add_outb_message(): destid %4.4x mbox %d buffer " \
"%8.8x len %8.8x\n", rdev->destid, mbox, (int)buffer, len);
if ((len < 8) || (len > RIO_MAX_MSG_SIZE)) {
ret = -EINVAL;
goto out;
}
memcpy(priv->msg_tx_ring.virt_buffer[priv->msg_tx_ring.tx_slot], buffer,
len);
if (len < (RIO_MAX_MSG_SIZE - 4))
memset(priv->msg_tx_ring.virt_buffer[priv->msg_tx_ring.tx_slot]
+ len, 0, RIO_MAX_MSG_SIZE - len);
switch (mport->phy_type) {
case RIO_PHY_PARALLEL:
desc->dport = mbox & 0x3;
desc->dattr = 0x28000000 | (rdev->destid << 2);
break;
case RIO_PHY_SERIAL:
desc->dport = (rdev->destid << 16) | (mbox & 0x3);
desc->dattr = 0x28000000;
break;
}
desc->dwcnt = is_power_of_2(len) ? len : 1 << get_bitmask_order(len);
desc->saddr = 0x00000004
| priv->msg_tx_ring.phys_buffer[priv->msg_tx_ring.tx_slot];
omr = in_be32(&priv->msg_regs->omr);
out_be32(&priv->msg_regs->omr, omr | RIO_MSG_OMR_MUI);
if (++priv->msg_tx_ring.tx_slot == priv->msg_tx_ring.size)
priv->msg_tx_ring.tx_slot = 0;
out:
return ret;
}
static irqreturn_t
fsl_rio_tx_handler(int irq, void *dev_instance)
{
int osr;
struct rio_mport *port = (struct rio_mport *)dev_instance;
struct rio_priv *priv = port->priv;
osr = in_be32(&priv->msg_regs->osr);
if (osr & RIO_MSG_OSR_TE) {
pr_info("RIO: outbound message transmission error\n");
out_be32(&priv->msg_regs->osr, RIO_MSG_OSR_TE);
goto out;
}
if (osr & RIO_MSG_OSR_QOI) {
pr_info("RIO: outbound message queue overflow\n");
out_be32(&priv->msg_regs->osr, RIO_MSG_OSR_QOI);
goto out;
}
if (osr & RIO_MSG_OSR_EOMI) {
u32 dqp = in_be32(&priv->msg_regs->odqdpar);
int slot = (dqp - priv->msg_tx_ring.phys) >> 5;
port->outb_msg[0].mcback(port, priv->msg_tx_ring.dev_id, -1,
slot);
out_be32(&priv->msg_regs->osr, RIO_MSG_OSR_EOMI);
}
out:
return IRQ_HANDLED;
}
static int
fsl_open_outb_mbox(struct rio_mport *mport, void *dev_id, int mbox, int entries)
{
int i, j, rc = 0;
struct rio_priv *priv = mport->priv;
if ((entries < RIO_MIN_TX_RING_SIZE) ||
(entries > RIO_MAX_TX_RING_SIZE) || (!is_power_of_2(entries))) {
rc = -EINVAL;
goto out;
}
priv->msg_tx_ring.dev_id = dev_id;
priv->msg_tx_ring.size = entries;
for (i = 0; i < priv->msg_tx_ring.size; i++) {
priv->msg_tx_ring.virt_buffer[i] =
dma_alloc_coherent(priv->dev, RIO_MSG_BUFFER_SIZE,
&priv->msg_tx_ring.phys_buffer[i], GFP_KERNEL);
if (!priv->msg_tx_ring.virt_buffer[i]) {
rc = -ENOMEM;
for (j = 0; j < priv->msg_tx_ring.size; j++)
if (priv->msg_tx_ring.virt_buffer[j])
dma_free_coherent(priv->dev,
RIO_MSG_BUFFER_SIZE,
priv->msg_tx_ring.
virt_buffer[j],
priv->msg_tx_ring.
phys_buffer[j]);
goto out;
}
}
priv->msg_tx_ring.virt = dma_alloc_coherent(priv->dev,
priv->msg_tx_ring.size * RIO_MSG_DESC_SIZE,
&priv->msg_tx_ring.phys, GFP_KERNEL);
if (!priv->msg_tx_ring.virt) {
rc = -ENOMEM;
goto out_dma;
}
memset(priv->msg_tx_ring.virt, 0,
priv->msg_tx_ring.size * RIO_MSG_DESC_SIZE);
priv->msg_tx_ring.tx_slot = 0;
out_be32(&priv->msg_regs->odqdpar, priv->msg_tx_ring.phys);
out_be32(&priv->msg_regs->odqepar, priv->msg_tx_ring.phys);
out_be32(&priv->msg_regs->osar, 0x00000004);
out_be32(&priv->msg_regs->osr, 0x000000b3);
rc = request_irq(IRQ_RIO_TX(mport), fsl_rio_tx_handler, 0,
"msg_tx", (void *)mport);
if (rc < 0)
goto out_irq;
out_be32(&priv->msg_regs->omr, 0x00100220);
out_be32(&priv->msg_regs->omr,
in_be32(&priv->msg_regs->omr) |
((get_bitmask_order(entries) - 2) << 12));
out_be32(&priv->msg_regs->omr, in_be32(&priv->msg_regs->omr) | 0x1);
out:
return rc;
out_irq:
dma_free_coherent(priv->dev,
priv->msg_tx_ring.size * RIO_MSG_DESC_SIZE,
priv->msg_tx_ring.virt, priv->msg_tx_ring.phys);
out_dma:
for (i = 0; i < priv->msg_tx_ring.size; i++)
dma_free_coherent(priv->dev, RIO_MSG_BUFFER_SIZE,
priv->msg_tx_ring.virt_buffer[i],
priv->msg_tx_ring.phys_buffer[i]);
return rc;
}
static void fsl_close_outb_mbox(struct rio_mport *mport, int mbox)
{
struct rio_priv *priv = mport->priv;
out_be32(&priv->msg_regs->omr, 0);
dma_free_coherent(priv->dev,
priv->msg_tx_ring.size * RIO_MSG_DESC_SIZE,
priv->msg_tx_ring.virt, priv->msg_tx_ring.phys);
free_irq(IRQ_RIO_TX(mport), (void *)mport);
}
static irqreturn_t
fsl_rio_rx_handler(int irq, void *dev_instance)
{
int isr;
struct rio_mport *port = (struct rio_mport *)dev_instance;
struct rio_priv *priv = port->priv;
isr = in_be32(&priv->msg_regs->isr);
if (isr & RIO_MSG_ISR_TE) {
pr_info("RIO: inbound message reception error\n");
out_be32((void *)&priv->msg_regs->isr, RIO_MSG_ISR_TE);
goto out;
}
if (isr & RIO_MSG_ISR_DIQI) {
port->inb_msg[0].mcback(port, priv->msg_rx_ring.dev_id, -1, -1);
out_be32(&priv->msg_regs->isr, RIO_MSG_ISR_DIQI);
}
out:
return IRQ_HANDLED;
}
static int
fsl_open_inb_mbox(struct rio_mport *mport, void *dev_id, int mbox, int entries)
{
int i, rc = 0;
struct rio_priv *priv = mport->priv;
if ((entries < RIO_MIN_RX_RING_SIZE) ||
(entries > RIO_MAX_RX_RING_SIZE) || (!is_power_of_2(entries))) {
rc = -EINVAL;
goto out;
}
priv->msg_rx_ring.dev_id = dev_id;
priv->msg_rx_ring.size = entries;
priv->msg_rx_ring.rx_slot = 0;
for (i = 0; i < priv->msg_rx_ring.size; i++)
priv->msg_rx_ring.virt_buffer[i] = NULL;
priv->msg_rx_ring.virt = dma_alloc_coherent(priv->dev,
priv->msg_rx_ring.size * RIO_MAX_MSG_SIZE,
&priv->msg_rx_ring.phys, GFP_KERNEL);
if (!priv->msg_rx_ring.virt) {
rc = -ENOMEM;
goto out;
}
out_be32(&priv->msg_regs->ifqdpar, (u32) priv->msg_rx_ring.phys);
out_be32(&priv->msg_regs->ifqepar, (u32) priv->msg_rx_ring.phys);
out_be32(&priv->msg_regs->isr, 0x00000091);
rc = request_irq(IRQ_RIO_RX(mport), fsl_rio_rx_handler, 0,
"msg_rx", (void *)mport);
if (rc < 0) {
dma_free_coherent(priv->dev, RIO_MSG_BUFFER_SIZE,
priv->msg_tx_ring.virt_buffer[i],
priv->msg_tx_ring.phys_buffer[i]);
goto out;
}
out_be32(&priv->msg_regs->imr, 0x001b0060);
setbits32(&priv->msg_regs->imr, (get_bitmask_order(entries) - 2) << 12);
setbits32(&priv->msg_regs->imr, 0x1);
out:
return rc;
}
static void fsl_close_inb_mbox(struct rio_mport *mport, int mbox)
{
struct rio_priv *priv = mport->priv;
out_be32(&priv->msg_regs->imr, 0);
dma_free_coherent(priv->dev, priv->msg_rx_ring.size * RIO_MAX_MSG_SIZE,
priv->msg_rx_ring.virt, priv->msg_rx_ring.phys);
free_irq(IRQ_RIO_RX(mport), (void *)mport);
}
static int fsl_add_inb_buffer(struct rio_mport *mport, int mbox, void *buf)
{
int rc = 0;
struct rio_priv *priv = mport->priv;
pr_debug("RIO: fsl_add_inb_buffer(), msg_rx_ring.rx_slot %d\n",
priv->msg_rx_ring.rx_slot);
if (priv->msg_rx_ring.virt_buffer[priv->msg_rx_ring.rx_slot]) {
printk(KERN_ERR
"RIO: error adding inbound buffer %d, buffer exists\n",
priv->msg_rx_ring.rx_slot);
rc = -EINVAL;
goto out;
}
priv->msg_rx_ring.virt_buffer[priv->msg_rx_ring.rx_slot] = buf;
if (++priv->msg_rx_ring.rx_slot == priv->msg_rx_ring.size)
priv->msg_rx_ring.rx_slot = 0;
out:
return rc;
}
static void *fsl_get_inb_message(struct rio_mport *mport, int mbox)
{
struct rio_priv *priv = mport->priv;
u32 phys_buf, virt_buf;
void *buf = NULL;
int buf_idx;
phys_buf = in_be32(&priv->msg_regs->ifqdpar);
if (phys_buf == in_be32(&priv->msg_regs->ifqepar))
goto out2;
virt_buf = (u32) priv->msg_rx_ring.virt + (phys_buf
- priv->msg_rx_ring.phys);
buf_idx = (phys_buf - priv->msg_rx_ring.phys) / RIO_MAX_MSG_SIZE;
buf = priv->msg_rx_ring.virt_buffer[buf_idx];
if (!buf) {
printk(KERN_ERR
"RIO: inbound message copy failed, no buffers\n");
goto out1;
}
memcpy(buf, (void *)virt_buf, RIO_MAX_MSG_SIZE);
priv->msg_rx_ring.virt_buffer[buf_idx] = NULL;
out1:
setbits32(&priv->msg_regs->imr, RIO_MSG_IMR_MI);
out2:
return buf;
}
static irqreturn_t
fsl_rio_dbell_handler(int irq, void *dev_instance)
{
int dsr;
struct rio_mport *port = (struct rio_mport *)dev_instance;
struct rio_priv *priv = port->priv;
dsr = in_be32(&priv->msg_regs->dsr);
if (dsr & DOORBELL_DSR_TE) {
pr_info("RIO: doorbell reception error\n");
out_be32(&priv->msg_regs->dsr, DOORBELL_DSR_TE);
goto out;
}
if (dsr & DOORBELL_DSR_QFI) {
pr_info("RIO: doorbell queue full\n");
out_be32(&priv->msg_regs->dsr, DOORBELL_DSR_QFI);
}
if (dsr & DOORBELL_DSR_DIQI) {
u32 dmsg =
(u32) priv->dbell_ring.virt +
(in_be32(&priv->msg_regs->dqdpar) & 0xfff);
struct rio_dbell *dbell;
int found = 0;
pr_debug
("RIO: processing doorbell, sid %2.2x tid %2.2x info %4.4x\n",
DBELL_SID(dmsg), DBELL_TID(dmsg), DBELL_INF(dmsg));
list_for_each_entry(dbell, &port->dbells, node) {
if ((dbell->res->start <= DBELL_INF(dmsg)) &&
(dbell->res->end >= DBELL_INF(dmsg))) {
found = 1;
break;
}
}
if (found) {
dbell->dinb(port, dbell->dev_id, DBELL_SID(dmsg), DBELL_TID(dmsg),
DBELL_INF(dmsg));
} else {
pr_debug
("RIO: spurious doorbell, sid %2.2x tid %2.2x info %4.4x\n",
DBELL_SID(dmsg), DBELL_TID(dmsg), DBELL_INF(dmsg));
}
setbits32(&priv->msg_regs->dmr, DOORBELL_DMR_DI);
out_be32(&priv->msg_regs->dsr, DOORBELL_DSR_DIQI);
}
out:
return IRQ_HANDLED;
}
static int fsl_rio_doorbell_init(struct rio_mport *mport)
{
struct rio_priv *priv = mport->priv;
int rc = 0;
priv->dbell_win = ioremap(mport->iores.start + RIO_MAINT_WIN_SIZE,
RIO_DBELL_WIN_SIZE);
if (!priv->dbell_win) {
printk(KERN_ERR
"RIO: unable to map outbound doorbell window\n");
rc = -ENOMEM;
goto out;
}
priv->dbell_ring.virt = dma_alloc_coherent(priv->dev, 512 *
DOORBELL_MESSAGE_SIZE, &priv->dbell_ring.phys, GFP_KERNEL);
if (!priv->dbell_ring.virt) {
printk(KERN_ERR "RIO: unable allocate inbound doorbell ring\n");
rc = -ENOMEM;
iounmap(priv->dbell_win);
goto out;
}
out_be32(&priv->msg_regs->dqdpar, (u32) priv->dbell_ring.phys);
out_be32(&priv->msg_regs->dqepar, (u32) priv->dbell_ring.phys);
out_be32(&priv->msg_regs->dsr, 0x00000091);
rc = request_irq(IRQ_RIO_BELL(mport), fsl_rio_dbell_handler, 0,
"dbell_rx", (void *)mport);
if (rc < 0) {
iounmap(priv->dbell_win);
dma_free_coherent(priv->dev, 512 * DOORBELL_MESSAGE_SIZE,
priv->dbell_ring.virt, priv->dbell_ring.phys);
printk(KERN_ERR
"MPC85xx RIO: unable to request inbound doorbell irq");
goto out;
}
out_be32(&priv->msg_regs->dmr, 0x00108161);
out:
return rc;
}
static void port_error_handler(struct rio_mport *port, int offset)
{
out_be32((u32 *)(rio_regs_win + RIO_LTLEDCSR), 0);
if (offset == 0) {
out_be32((u32 *)(rio_regs_win + RIO_PORT1_EDCSR), 0);
out_be32((u32 *)(rio_regs_win + RIO_PORT1_IECSR), IECSR_CLEAR);
out_be32((u32 *)(rio_regs_win + RIO_ESCSR), ESCSR_CLEAR);
} else {
out_be32((u32 *)(rio_regs_win + RIO_PORT2_EDCSR), 0);
out_be32((u32 *)(rio_regs_win + RIO_PORT2_IECSR), IECSR_CLEAR);
out_be32((u32 *)(rio_regs_win + RIO_PORT2_ESCSR), ESCSR_CLEAR);
}
}
static void msg_unit_error_handler(struct rio_mport *port)
{
struct rio_priv *priv = port->priv;
out_be32((u32 *)(rio_regs_win + RIO_LTLEDCSR), 0);
out_be32((u32 *)(rio_regs_win + RIO_IM0SR), IMSR_CLEAR);
out_be32((u32 *)(rio_regs_win + RIO_IM1SR), IMSR_CLEAR);
out_be32((u32 *)(rio_regs_win + RIO_OM0SR), OMSR_CLEAR);
out_be32((u32 *)(rio_regs_win + RIO_OM1SR), OMSR_CLEAR);
out_be32(&priv->msg_regs->odsr, ODSR_CLEAR);
out_be32(&priv->msg_regs->dsr, IDSR_CLEAR);
out_be32(&priv->msg_regs->pwsr, IPWSR_CLEAR);
}
static irqreturn_t
fsl_rio_port_write_handler(int irq, void *dev_instance)
{
u32 ipwmr, ipwsr;
struct rio_mport *port = (struct rio_mport *)dev_instance;
struct rio_priv *priv = port->priv;
u32 epwisr, tmp;
epwisr = in_be32(priv->regs_win + RIO_EPWISR);
if (!(epwisr & RIO_EPWISR_PW))
goto pw_done;
ipwmr = in_be32(&priv->msg_regs->pwmr);
ipwsr = in_be32(&priv->msg_regs->pwsr);
#ifdef DEBUG_PW
pr_debug("PW Int->IPWMR: 0x%08x IPWSR: 0x%08x (", ipwmr, ipwsr);
if (ipwsr & RIO_IPWSR_QF)
pr_debug(" QF");
if (ipwsr & RIO_IPWSR_TE)
pr_debug(" TE");
if (ipwsr & RIO_IPWSR_QFI)
pr_debug(" QFI");
if (ipwsr & RIO_IPWSR_PWD)
pr_debug(" PWD");
if (ipwsr & RIO_IPWSR_PWB)
pr_debug(" PWB");
pr_debug(" )\n");
#endif
if (ipwsr & RIO_IPWSR_QFI) {
if (kfifo_avail(&priv->pw_fifo) >= RIO_PW_MSG_SIZE) {
priv->port_write_msg.msg_count++;
kfifo_in(&priv->pw_fifo, priv->port_write_msg.virt,
RIO_PW_MSG_SIZE);
} else {
priv->port_write_msg.discard_count++;
pr_debug("RIO: ISR Discarded Port-Write Msg(s) (%d)\n",
priv->port_write_msg.discard_count);
}
out_be32(&priv->msg_regs->pwsr, RIO_IPWSR_QFI);
out_be32(&priv->msg_regs->pwmr, ipwmr | RIO_IPWMR_CQ);
schedule_work(&priv->pw_work);
}
if ((ipwmr & RIO_IPWMR_EIE) && (ipwsr & RIO_IPWSR_TE)) {
priv->port_write_msg.err_count++;
pr_debug("RIO: Port-Write Transaction Err (%d)\n",
priv->port_write_msg.err_count);
out_be32(&priv->msg_regs->pwmr, ipwmr & ~RIO_IPWMR_PWE);
out_be32(&priv->msg_regs->pwsr, RIO_IPWSR_TE);
out_be32(&priv->msg_regs->pwmr, ipwmr);
}
if (ipwsr & RIO_IPWSR_PWD) {
priv->port_write_msg.discard_count++;
pr_debug("RIO: Port Discarded Port-Write Msg(s) (%d)\n",
priv->port_write_msg.discard_count);
out_be32(&priv->msg_regs->pwsr, RIO_IPWSR_PWD);
}
pw_done:
if (epwisr & RIO_EPWISR_PINT1) {
tmp = in_be32(priv->regs_win + RIO_LTLEDCSR);
pr_debug("RIO_LTLEDCSR = 0x%x\n", tmp);
port_error_handler(port, 0);
}
if (epwisr & RIO_EPWISR_PINT2) {
tmp = in_be32(priv->regs_win + RIO_LTLEDCSR);
pr_debug("RIO_LTLEDCSR = 0x%x\n", tmp);
port_error_handler(port, 1);
}
if (epwisr & RIO_EPWISR_MU) {
tmp = in_be32(priv->regs_win + RIO_LTLEDCSR);
pr_debug("RIO_LTLEDCSR = 0x%x\n", tmp);
msg_unit_error_handler(port);
}
return IRQ_HANDLED;
}
static void fsl_pw_dpc(struct work_struct *work)
{
struct rio_priv *priv = container_of(work, struct rio_priv, pw_work);
unsigned long flags;
u32 msg_buffer[RIO_PW_MSG_SIZE/sizeof(u32)];
spin_lock_irqsave(&priv->pw_fifo_lock, flags);
while (kfifo_out(&priv->pw_fifo, (unsigned char *)msg_buffer,
RIO_PW_MSG_SIZE)) {
spin_unlock_irqrestore(&priv->pw_fifo_lock, flags);
#ifdef DEBUG_PW
{
u32 i;
pr_debug("%s : Port-Write Message:", __func__);
for (i = 0; i < RIO_PW_MSG_SIZE/sizeof(u32); i++) {
if ((i%4) == 0)
pr_debug("\n0x%02x: 0x%08x", i*4,
msg_buffer[i]);
else
pr_debug(" 0x%08x", msg_buffer[i]);
}
pr_debug("\n");
}
#endif
rio_inb_pwrite_handler((union rio_pw_msg *)msg_buffer);
spin_lock_irqsave(&priv->pw_fifo_lock, flags);
}
spin_unlock_irqrestore(&priv->pw_fifo_lock, flags);
}
static int fsl_rio_pw_enable(struct rio_mport *mport, int enable)
{
struct rio_priv *priv = mport->priv;
u32 rval;
rval = in_be32(&priv->msg_regs->pwmr);
if (enable)
rval |= RIO_IPWMR_PWE;
else
rval &= ~RIO_IPWMR_PWE;
out_be32(&priv->msg_regs->pwmr, rval);
return 0;
}
static int fsl_rio_port_write_init(struct rio_mport *mport)
{
struct rio_priv *priv = mport->priv;
int rc = 0;
out_be32(&priv->msg_regs->pwmr,
in_be32(&priv->msg_regs->pwmr) & ~RIO_IPWMR_PWE);
priv->port_write_msg.virt = dma_alloc_coherent(priv->dev,
RIO_PW_MSG_SIZE,
&priv->port_write_msg.phys, GFP_KERNEL);
if (!priv->port_write_msg.virt) {
pr_err("RIO: unable allocate port write queue\n");
return -ENOMEM;
}
priv->port_write_msg.err_count = 0;
priv->port_write_msg.discard_count = 0;
out_be32(&priv->msg_regs->epwqbar, 0);
out_be32(&priv->msg_regs->pwqbar, (u32) priv->port_write_msg.phys);
pr_debug("EIPWQBAR: 0x%08x IPWQBAR: 0x%08x\n",
in_be32(&priv->msg_regs->epwqbar),
in_be32(&priv->msg_regs->pwqbar));
out_be32(&priv->msg_regs->pwsr,
(RIO_IPWSR_TE | RIO_IPWSR_QFI | RIO_IPWSR_PWD));
out_be32(&priv->msg_regs->pwmr,
RIO_IPWMR_SEN | RIO_IPWMR_QFIE | RIO_IPWMR_EIE | RIO_IPWMR_CQ);
rc = request_irq(IRQ_RIO_PW(mport), fsl_rio_port_write_handler,
IRQF_SHARED, "port-write", (void *)mport);
if (rc < 0) {
pr_err("MPC85xx RIO: unable to request inbound doorbell irq");
goto err_out;
}
out_be32((u32 *)(rio_regs_win + RIO_LTLEECSR), LTLEECSR_ENABLE_ALL);
INIT_WORK(&priv->pw_work, fsl_pw_dpc);
spin_lock_init(&priv->pw_fifo_lock);
if (kfifo_alloc(&priv->pw_fifo, RIO_PW_MSG_SIZE * 32, GFP_KERNEL)) {
pr_err("FIFO allocation failed\n");
rc = -ENOMEM;
goto err_out_irq;
}
pr_debug("IPWMR: 0x%08x IPWSR: 0x%08x\n",
in_be32(&priv->msg_regs->pwmr),
in_be32(&priv->msg_regs->pwsr));
return rc;
err_out_irq:
free_irq(IRQ_RIO_PW(mport), (void *)mport);
err_out:
dma_free_coherent(priv->dev, RIO_PW_MSG_SIZE,
priv->port_write_msg.virt,
priv->port_write_msg.phys);
return rc;
}
static inline void fsl_rio_info(struct device *dev, u32 ccsr)
{
const char *str;
if (ccsr & 1) {
switch (ccsr >> 30) {
case 0:
str = "1";
break;
case 1:
str = "4";
break;
default:
str = "Unknown";
break;
}
dev_info(dev, "Hardware port width: %s\n", str);
switch ((ccsr >> 27) & 7) {
case 0:
str = "Single-lane 0";
break;
case 1:
str = "Single-lane 2";
break;
case 2:
str = "Four-lane";
break;
default:
str = "Unknown";
break;
}
dev_info(dev, "Training connection status: %s\n", str);
} else {
if (!(ccsr & 0x80000000))
dev_info(dev, "Output port operating in 8-bit mode\n");
if (!(ccsr & 0x08000000))
dev_info(dev, "Input port operating in 8-bit mode\n");
}
}
int fsl_rio_setup(struct platform_device *dev)
{
struct rio_ops *ops;
struct rio_mport *port;
struct rio_priv *priv;
int rc = 0;
const u32 *dt_range, *cell;
struct resource regs;
int rlen;
u32 ccsr;
u64 law_start, law_size;
int paw, aw, sw;
if (!dev->dev.of_node) {
dev_err(&dev->dev, "Device OF-Node is NULL");
return -EFAULT;
}
rc = of_address_to_resource(dev->dev.of_node, 0, &regs);
if (rc) {
dev_err(&dev->dev, "Can't get %s property 'reg'\n",
dev->dev.of_node->full_name);
return -EFAULT;
}
dev_info(&dev->dev, "Of-device full name %s\n", dev->dev.of_node->full_name);
dev_info(&dev->dev, "Regs: %pR\n", &regs);
dt_range = of_get_property(dev->dev.of_node, "ranges", &rlen);
if (!dt_range) {
dev_err(&dev->dev, "Can't get %s property 'ranges'\n",
dev->dev.of_node->full_name);
return -EFAULT;
}
cell = of_get_property(dev->dev.of_node, "#address-cells", NULL);
if (cell)
aw = *cell;
else
aw = of_n_addr_cells(dev->dev.of_node);
cell = of_get_property(dev->dev.of_node, "#size-cells", NULL);
if (cell)
sw = *cell;
else
sw = of_n_size_cells(dev->dev.of_node);
paw = of_n_addr_cells(dev->dev.of_node);
law_start = of_read_number(dt_range + aw, paw);
law_size = of_read_number(dt_range + aw + paw, sw);
dev_info(&dev->dev, "LAW start 0x%016llx, size 0x%016llx.\n",
law_start, law_size);
ops = kzalloc(sizeof(struct rio_ops), GFP_KERNEL);
if (!ops) {
rc = -ENOMEM;
goto err_ops;
}
ops->lcread = fsl_local_config_read;
ops->lcwrite = fsl_local_config_write;
ops->cread = fsl_rio_config_read;
ops->cwrite = fsl_rio_config_write;
ops->dsend = fsl_rio_doorbell_send;
ops->pwenable = fsl_rio_pw_enable;
ops->open_outb_mbox = fsl_open_outb_mbox;
ops->open_inb_mbox = fsl_open_inb_mbox;
ops->close_outb_mbox = fsl_close_outb_mbox;
ops->close_inb_mbox = fsl_close_inb_mbox;
ops->add_outb_message = fsl_add_outb_message;
ops->add_inb_buffer = fsl_add_inb_buffer;
ops->get_inb_message = fsl_get_inb_message;
port = kzalloc(sizeof(struct rio_mport), GFP_KERNEL);
if (!port) {
rc = -ENOMEM;
goto err_port;
}
port->index = 0;
priv = kzalloc(sizeof(struct rio_priv), GFP_KERNEL);
if (!priv) {
printk(KERN_ERR "Can't alloc memory for 'priv'\n");
rc = -ENOMEM;
goto err_priv;
}
INIT_LIST_HEAD(&port->dbells);
port->iores.start = law_start;
port->iores.end = law_start + law_size - 1;
port->iores.flags = IORESOURCE_MEM;
port->iores.name = "rio_io_win";
if (request_resource(&iomem_resource, &port->iores) < 0) {
dev_err(&dev->dev, "RIO: Error requesting master port region"
" 0x%016llx-0x%016llx\n",
(u64)port->iores.start, (u64)port->iores.end);
rc = -ENOMEM;
goto err_res;
}
priv->pwirq = irq_of_parse_and_map(dev->dev.of_node, 0);
priv->bellirq = irq_of_parse_and_map(dev->dev.of_node, 2);
priv->txirq = irq_of_parse_and_map(dev->dev.of_node, 3);
priv->rxirq = irq_of_parse_and_map(dev->dev.of_node, 4);
dev_info(&dev->dev, "pwirq: %d, bellirq: %d, txirq: %d, rxirq %d\n",
priv->pwirq, priv->bellirq, priv->txirq, priv->rxirq);
rio_init_dbell_res(&port->riores[RIO_DOORBELL_RESOURCE], 0, 0xffff);
rio_init_mbox_res(&port->riores[RIO_INB_MBOX_RESOURCE], 0, 0);
rio_init_mbox_res(&port->riores[RIO_OUTB_MBOX_RESOURCE], 0, 0);
strcpy(port->name, "RIO0 mport");
priv->dev = &dev->dev;
port->ops = ops;
port->priv = priv;
port->phys_efptr = 0x100;
priv->regs_win = ioremap(regs.start, resource_size(&regs));
rio_regs_win = priv->regs_win;
ccsr = in_be32(priv->regs_win + RIO_CCSR);
port->phy_type = (ccsr & 1) ? RIO_PHY_SERIAL : RIO_PHY_PARALLEL;
dev_info(&dev->dev, "RapidIO PHY type: %s\n",
(port->phy_type == RIO_PHY_PARALLEL) ? "parallel" :
((port->phy_type == RIO_PHY_SERIAL) ? "serial" :
"unknown"));
if (in_be32((priv->regs_win + RIO_ESCSR)) & 1) {
dev_err(&dev->dev, "Port is not ready. "
"Try to restart connection...\n");
switch (port->phy_type) {
case RIO_PHY_SERIAL:
out_be32(priv->regs_win + RIO_CCSR, 0);
setbits32(priv->regs_win + RIO_CCSR, 0x02000000);
setbits32(priv->regs_win + RIO_CCSR, 0x00600000);
break;
case RIO_PHY_PARALLEL:
out_be32(priv->regs_win + RIO_CCSR, 0x22000000);
out_be32(priv->regs_win + RIO_CCSR, 0x44000000);
break;
}
msleep(100);
if (in_be32((priv->regs_win + RIO_ESCSR)) & 1) {
dev_err(&dev->dev, "Port restart failed.\n");
rc = -ENOLINK;
goto err;
}
dev_info(&dev->dev, "Port restart success!\n");
}
fsl_rio_info(&dev->dev, ccsr);
port->sys_size = (in_be32((priv->regs_win + RIO_PEF_CAR))
& RIO_PEF_CTLS) >> 4;
dev_info(&dev->dev, "RapidIO Common Transport System size: %d\n",
port->sys_size ? 65536 : 256);
if (rio_register_mport(port))
goto err;
if (port->host_deviceid >= 0)
out_be32(priv->regs_win + RIO_GCCSR, RIO_PORT_GEN_HOST |
RIO_PORT_GEN_MASTER | RIO_PORT_GEN_DISCOVERED);
else
out_be32(priv->regs_win + RIO_GCCSR, 0x00000000);
priv->atmu_regs = (struct rio_atmu_regs *)(priv->regs_win
+ RIO_ATMU_REGS_OFFSET);
priv->maint_atmu_regs = priv->atmu_regs + 1;
priv->dbell_atmu_regs = priv->atmu_regs + 2;
priv->msg_regs = (struct rio_msg_regs *)(priv->regs_win +
((port->phy_type == RIO_PHY_SERIAL) ?
RIO_S_MSG_REGS_OFFSET : RIO_P_MSG_REGS_OFFSET));
if (port->phy_type == RIO_PHY_SERIAL)
out_be32((priv->regs_win + RIO_ISR_AACR), RIO_ISR_AACR_AA);
out_be32(&priv->maint_atmu_regs->rowbar, law_start >> 12);
out_be32(&priv->maint_atmu_regs->rowar,
0x80077000 | (ilog2(RIO_MAINT_WIN_SIZE) - 1));
priv->maint_win = ioremap(law_start, RIO_MAINT_WIN_SIZE);
out_be32(&priv->dbell_atmu_regs->rowbar,
(law_start + RIO_MAINT_WIN_SIZE) >> 12);
out_be32(&priv->dbell_atmu_regs->rowar, 0x8004200b);
fsl_rio_doorbell_init(port);
fsl_rio_port_write_init(port);
return 0;
err:
iounmap(priv->regs_win);
release_resource(&port->iores);
err_res:
kfree(priv);
err_priv:
kfree(port);
err_port:
kfree(ops);
err_ops:
return rc;
}
static int __devinit fsl_of_rio_rpn_probe(struct platform_device *dev)
{
printk(KERN_INFO "Setting up RapidIO peer-to-peer network %s\n",
dev->dev.of_node->full_name);
return fsl_rio_setup(dev);
}
static __init int fsl_of_rio_rpn_init(void)
{
return platform_driver_register(&fsl_of_rio_rpn_driver);
}
