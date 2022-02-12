static irqreturn_t
fsl_rio_tx_handler(int irq, void *dev_instance)
{
int osr;
struct rio_mport *port = (struct rio_mport *)dev_instance;
struct fsl_rmu *rmu = GET_RMM_HANDLE(port);
osr = in_be32(&rmu->msg_regs->osr);
if (osr & RIO_MSG_OSR_TE) {
pr_info("RIO: outbound message transmission error\n");
out_be32(&rmu->msg_regs->osr, RIO_MSG_OSR_TE);
goto out;
}
if (osr & RIO_MSG_OSR_QOI) {
pr_info("RIO: outbound message queue overflow\n");
out_be32(&rmu->msg_regs->osr, RIO_MSG_OSR_QOI);
goto out;
}
if (osr & RIO_MSG_OSR_EOMI) {
u32 dqp = in_be32(&rmu->msg_regs->odqdpar);
int slot = (dqp - rmu->msg_tx_ring.phys) >> 5;
if (port->outb_msg[0].mcback != NULL) {
port->outb_msg[0].mcback(port, rmu->msg_tx_ring.dev_id,
-1,
slot);
}
out_be32(&rmu->msg_regs->osr, RIO_MSG_OSR_EOMI);
}
out:
return IRQ_HANDLED;
}
static irqreturn_t
fsl_rio_rx_handler(int irq, void *dev_instance)
{
int isr;
struct rio_mport *port = (struct rio_mport *)dev_instance;
struct fsl_rmu *rmu = GET_RMM_HANDLE(port);
isr = in_be32(&rmu->msg_regs->isr);
if (isr & RIO_MSG_ISR_TE) {
pr_info("RIO: inbound message reception error\n");
out_be32((void *)&rmu->msg_regs->isr, RIO_MSG_ISR_TE);
goto out;
}
if (isr & RIO_MSG_ISR_DIQI) {
if (port->inb_msg[0].mcback != NULL)
port->inb_msg[0].mcback(port, rmu->msg_rx_ring.dev_id,
-1,
-1);
out_be32(&rmu->msg_regs->isr, RIO_MSG_ISR_DIQI);
}
out:
return IRQ_HANDLED;
}
static irqreturn_t
fsl_rio_dbell_handler(int irq, void *dev_instance)
{
int dsr;
struct fsl_rio_dbell *fsl_dbell = (struct fsl_rio_dbell *)dev_instance;
int i;
dsr = in_be32(&fsl_dbell->dbell_regs->dsr);
if (dsr & DOORBELL_DSR_TE) {
pr_info("RIO: doorbell reception error\n");
out_be32(&fsl_dbell->dbell_regs->dsr, DOORBELL_DSR_TE);
goto out;
}
if (dsr & DOORBELL_DSR_QFI) {
pr_info("RIO: doorbell queue full\n");
out_be32(&fsl_dbell->dbell_regs->dsr, DOORBELL_DSR_QFI);
}
if (dsr & DOORBELL_DSR_DIQI) {
struct rio_dbell_msg *dmsg =
fsl_dbell->dbell_ring.virt +
(in_be32(&fsl_dbell->dbell_regs->dqdpar) & 0xfff);
struct rio_dbell *dbell;
int found = 0;
pr_debug
("RIO: processing doorbell,"
" sid %2.2x tid %2.2x info %4.4x\n",
dmsg->sid, dmsg->tid, dmsg->info);
for (i = 0; i < MAX_PORT_NUM; i++) {
if (fsl_dbell->mport[i]) {
list_for_each_entry(dbell,
&fsl_dbell->mport[i]->dbells, node) {
if ((dbell->res->start
<= dmsg->info)
&& (dbell->res->end
>= dmsg->info)) {
found = 1;
break;
}
}
if (found && dbell->dinb) {
dbell->dinb(fsl_dbell->mport[i],
dbell->dev_id, dmsg->sid,
dmsg->tid,
dmsg->info);
break;
}
}
}
if (!found) {
pr_debug
("RIO: spurious doorbell,"
" sid %2.2x tid %2.2x info %4.4x\n",
dmsg->sid, dmsg->tid,
dmsg->info);
}
setbits32(&fsl_dbell->dbell_regs->dmr, DOORBELL_DMR_DI);
out_be32(&fsl_dbell->dbell_regs->dsr, DOORBELL_DSR_DIQI);
}
out:
return IRQ_HANDLED;
}
void msg_unit_error_handler(void)
{
out_be32((u32 *)(rio_regs_win + RIO_LTLEDCSR), 0);
out_be32((u32 *)(rmu_regs_win + RIO_IM0SR), IMSR_CLEAR);
out_be32((u32 *)(rmu_regs_win + RIO_IM1SR), IMSR_CLEAR);
out_be32((u32 *)(rmu_regs_win + RIO_OM0SR), OMSR_CLEAR);
out_be32((u32 *)(rmu_regs_win + RIO_OM1SR), OMSR_CLEAR);
out_be32(&dbell->dbell_regs->odsr, ODSR_CLEAR);
out_be32(&dbell->dbell_regs->dsr, IDSR_CLEAR);
out_be32(&pw->pw_regs->pwsr, IPWSR_CLEAR);
}
static irqreturn_t
fsl_rio_port_write_handler(int irq, void *dev_instance)
{
u32 ipwmr, ipwsr;
struct fsl_rio_pw *pw = (struct fsl_rio_pw *)dev_instance;
u32 epwisr, tmp;
epwisr = in_be32(rio_regs_win + RIO_EPWISR);
if (!(epwisr & RIO_EPWISR_PW))
goto pw_done;
ipwmr = in_be32(&pw->pw_regs->pwmr);
ipwsr = in_be32(&pw->pw_regs->pwsr);
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
if (kfifo_avail(&pw->pw_fifo) >= RIO_PW_MSG_SIZE) {
pw->port_write_msg.msg_count++;
kfifo_in(&pw->pw_fifo, pw->port_write_msg.virt,
RIO_PW_MSG_SIZE);
} else {
pw->port_write_msg.discard_count++;
pr_debug("RIO: ISR Discarded Port-Write Msg(s) (%d)\n",
pw->port_write_msg.discard_count);
}
out_be32(&pw->pw_regs->pwsr, RIO_IPWSR_QFI);
out_be32(&pw->pw_regs->pwmr, ipwmr | RIO_IPWMR_CQ);
schedule_work(&pw->pw_work);
}
if ((ipwmr & RIO_IPWMR_EIE) && (ipwsr & RIO_IPWSR_TE)) {
pw->port_write_msg.err_count++;
pr_debug("RIO: Port-Write Transaction Err (%d)\n",
pw->port_write_msg.err_count);
out_be32(&pw->pw_regs->pwmr, ipwmr & ~RIO_IPWMR_PWE);
out_be32(&pw->pw_regs->pwsr, RIO_IPWSR_TE);
out_be32(&pw->pw_regs->pwmr, ipwmr);
}
if (ipwsr & RIO_IPWSR_PWD) {
pw->port_write_msg.discard_count++;
pr_debug("RIO: Port Discarded Port-Write Msg(s) (%d)\n",
pw->port_write_msg.discard_count);
out_be32(&pw->pw_regs->pwsr, RIO_IPWSR_PWD);
}
pw_done:
if (epwisr & RIO_EPWISR_PINT1) {
tmp = in_be32(rio_regs_win + RIO_LTLEDCSR);
pr_debug("RIO_LTLEDCSR = 0x%x\n", tmp);
fsl_rio_port_error_handler(0);
}
if (epwisr & RIO_EPWISR_PINT2) {
tmp = in_be32(rio_regs_win + RIO_LTLEDCSR);
pr_debug("RIO_LTLEDCSR = 0x%x\n", tmp);
fsl_rio_port_error_handler(1);
}
if (epwisr & RIO_EPWISR_MU) {
tmp = in_be32(rio_regs_win + RIO_LTLEDCSR);
pr_debug("RIO_LTLEDCSR = 0x%x\n", tmp);
msg_unit_error_handler();
}
return IRQ_HANDLED;
}
static void fsl_pw_dpc(struct work_struct *work)
{
struct fsl_rio_pw *pw = container_of(work, struct fsl_rio_pw, pw_work);
union rio_pw_msg msg_buffer;
int i;
while (kfifo_out_spinlocked(&pw->pw_fifo, (unsigned char *)&msg_buffer,
RIO_PW_MSG_SIZE, &pw->pw_fifo_lock)) {
#ifdef DEBUG_PW
{
u32 i;
pr_debug("%s : Port-Write Message:", __func__);
for (i = 0; i < RIO_PW_MSG_SIZE/sizeof(u32); i++) {
if ((i%4) == 0)
pr_debug("\n0x%02x: 0x%08x", i*4,
msg_buffer.raw[i]);
else
pr_debug(" 0x%08x", msg_buffer.raw[i]);
}
pr_debug("\n");
}
#endif
for (i = 0; i < MAX_PORT_NUM; i++) {
if (pw->mport[i])
rio_inb_pwrite_handler(pw->mport[i],
&msg_buffer);
}
}
}
int fsl_rio_pw_enable(struct rio_mport *mport, int enable)
{
u32 rval;
rval = in_be32(&pw->pw_regs->pwmr);
if (enable)
rval |= RIO_IPWMR_PWE;
else
rval &= ~RIO_IPWMR_PWE;
out_be32(&pw->pw_regs->pwmr, rval);
return 0;
}
int fsl_rio_port_write_init(struct fsl_rio_pw *pw)
{
int rc = 0;
out_be32(&pw->pw_regs->pwmr,
in_be32(&pw->pw_regs->pwmr) & ~RIO_IPWMR_PWE);
pw->port_write_msg.virt = dma_alloc_coherent(pw->dev,
RIO_PW_MSG_SIZE,
&pw->port_write_msg.phys, GFP_KERNEL);
if (!pw->port_write_msg.virt) {
pr_err("RIO: unable allocate port write queue\n");
return -ENOMEM;
}
pw->port_write_msg.err_count = 0;
pw->port_write_msg.discard_count = 0;
out_be32(&pw->pw_regs->epwqbar, 0);
out_be32(&pw->pw_regs->pwqbar, (u32) pw->port_write_msg.phys);
pr_debug("EIPWQBAR: 0x%08x IPWQBAR: 0x%08x\n",
in_be32(&pw->pw_regs->epwqbar),
in_be32(&pw->pw_regs->pwqbar));
out_be32(&pw->pw_regs->pwsr,
(RIO_IPWSR_TE | RIO_IPWSR_QFI | RIO_IPWSR_PWD));
out_be32(&pw->pw_regs->pwmr,
RIO_IPWMR_SEN | RIO_IPWMR_QFIE | RIO_IPWMR_EIE | RIO_IPWMR_CQ);
rc = request_irq(IRQ_RIO_PW(pw), fsl_rio_port_write_handler,
IRQF_SHARED, "port-write", (void *)pw);
if (rc < 0) {
pr_err("MPC85xx RIO: unable to request inbound doorbell irq");
goto err_out;
}
out_be32((u32 *)(rio_regs_win + RIO_LTLEECSR), LTLEECSR_ENABLE_ALL);
INIT_WORK(&pw->pw_work, fsl_pw_dpc);
spin_lock_init(&pw->pw_fifo_lock);
if (kfifo_alloc(&pw->pw_fifo, RIO_PW_MSG_SIZE * 32, GFP_KERNEL)) {
pr_err("FIFO allocation failed\n");
rc = -ENOMEM;
goto err_out_irq;
}
pr_debug("IPWMR: 0x%08x IPWSR: 0x%08x\n",
in_be32(&pw->pw_regs->pwmr),
in_be32(&pw->pw_regs->pwsr));
return rc;
err_out_irq:
free_irq(IRQ_RIO_PW(pw), (void *)pw);
err_out:
dma_free_coherent(pw->dev, RIO_PW_MSG_SIZE,
pw->port_write_msg.virt,
pw->port_write_msg.phys);
return rc;
}
int fsl_rio_doorbell_send(struct rio_mport *mport,
int index, u16 destid, u16 data)
{
unsigned long flags;
pr_debug("fsl_doorbell_send: index %d destid %4.4x data %4.4x\n",
index, destid, data);
spin_lock_irqsave(&fsl_rio_doorbell_lock, flags);
out_be32(&dbell->dbell_regs->odmr, 0x00000000);
out_be32(&dbell->dbell_regs->odretcr, 0x00000004);
out_be32(&dbell->dbell_regs->oddpr, destid << 16);
out_be32(&dbell->dbell_regs->oddatr, (index << 20) | data);
out_be32(&dbell->dbell_regs->odmr, 0x00000001);
spin_unlock_irqrestore(&fsl_rio_doorbell_lock, flags);
return 0;
}
int
fsl_add_outb_message(struct rio_mport *mport, struct rio_dev *rdev, int mbox,
void *buffer, size_t len)
{
struct fsl_rmu *rmu = GET_RMM_HANDLE(mport);
u32 omr;
struct rio_tx_desc *desc = (struct rio_tx_desc *)rmu->msg_tx_ring.virt
+ rmu->msg_tx_ring.tx_slot;
int ret = 0;
pr_debug("RIO: fsl_add_outb_message(): destid %4.4x mbox %d buffer " \
"%p len %8.8zx\n", rdev->destid, mbox, buffer, len);
if ((len < 8) || (len > RIO_MAX_MSG_SIZE)) {
ret = -EINVAL;
goto out;
}
memcpy(rmu->msg_tx_ring.virt_buffer[rmu->msg_tx_ring.tx_slot], buffer,
len);
if (len < (RIO_MAX_MSG_SIZE - 4))
memset(rmu->msg_tx_ring.virt_buffer[rmu->msg_tx_ring.tx_slot]
+ len, 0, RIO_MAX_MSG_SIZE - len);
desc->dport = (rdev->destid << 16) | (mbox & 0x3);
desc->dattr = 0x28000000 | ((mport->index) << 20);
desc->dwcnt = is_power_of_2(len) ? len : 1 << get_bitmask_order(len);
desc->saddr = 0x00000004
| rmu->msg_tx_ring.phys_buffer[rmu->msg_tx_ring.tx_slot];
omr = in_be32(&rmu->msg_regs->omr);
out_be32(&rmu->msg_regs->omr, omr | RIO_MSG_OMR_MUI);
if (++rmu->msg_tx_ring.tx_slot == rmu->msg_tx_ring.size)
rmu->msg_tx_ring.tx_slot = 0;
out:
return ret;
}
int
fsl_open_outb_mbox(struct rio_mport *mport, void *dev_id, int mbox, int entries)
{
int i, j, rc = 0;
struct rio_priv *priv = mport->priv;
struct fsl_rmu *rmu = GET_RMM_HANDLE(mport);
if ((entries < RIO_MIN_TX_RING_SIZE) ||
(entries > RIO_MAX_TX_RING_SIZE) || (!is_power_of_2(entries))) {
rc = -EINVAL;
goto out;
}
rmu->msg_tx_ring.dev_id = dev_id;
rmu->msg_tx_ring.size = entries;
for (i = 0; i < rmu->msg_tx_ring.size; i++) {
rmu->msg_tx_ring.virt_buffer[i] =
dma_alloc_coherent(priv->dev, RIO_MSG_BUFFER_SIZE,
&rmu->msg_tx_ring.phys_buffer[i], GFP_KERNEL);
if (!rmu->msg_tx_ring.virt_buffer[i]) {
rc = -ENOMEM;
for (j = 0; j < rmu->msg_tx_ring.size; j++)
if (rmu->msg_tx_ring.virt_buffer[j])
dma_free_coherent(priv->dev,
RIO_MSG_BUFFER_SIZE,
rmu->msg_tx_ring.
virt_buffer[j],
rmu->msg_tx_ring.
phys_buffer[j]);
goto out;
}
}
rmu->msg_tx_ring.virt = dma_alloc_coherent(priv->dev,
rmu->msg_tx_ring.size * RIO_MSG_DESC_SIZE,
&rmu->msg_tx_ring.phys, GFP_KERNEL);
if (!rmu->msg_tx_ring.virt) {
rc = -ENOMEM;
goto out_dma;
}
memset(rmu->msg_tx_ring.virt, 0,
rmu->msg_tx_ring.size * RIO_MSG_DESC_SIZE);
rmu->msg_tx_ring.tx_slot = 0;
out_be32(&rmu->msg_regs->odqdpar, rmu->msg_tx_ring.phys);
out_be32(&rmu->msg_regs->odqepar, rmu->msg_tx_ring.phys);
out_be32(&rmu->msg_regs->osar, 0x00000004);
out_be32(&rmu->msg_regs->osr, 0x000000b3);
rc = request_irq(IRQ_RIO_TX(mport), fsl_rio_tx_handler, 0,
"msg_tx", (void *)mport);
if (rc < 0)
goto out_irq;
out_be32(&rmu->msg_regs->omr, 0x00100220);
out_be32(&rmu->msg_regs->omr,
in_be32(&rmu->msg_regs->omr) |
((get_bitmask_order(entries) - 2) << 12));
out_be32(&rmu->msg_regs->omr, in_be32(&rmu->msg_regs->omr) | 0x1);
out:
return rc;
out_irq:
dma_free_coherent(priv->dev,
rmu->msg_tx_ring.size * RIO_MSG_DESC_SIZE,
rmu->msg_tx_ring.virt, rmu->msg_tx_ring.phys);
out_dma:
for (i = 0; i < rmu->msg_tx_ring.size; i++)
dma_free_coherent(priv->dev, RIO_MSG_BUFFER_SIZE,
rmu->msg_tx_ring.virt_buffer[i],
rmu->msg_tx_ring.phys_buffer[i]);
return rc;
}
void fsl_close_outb_mbox(struct rio_mport *mport, int mbox)
{
struct rio_priv *priv = mport->priv;
struct fsl_rmu *rmu = GET_RMM_HANDLE(mport);
out_be32(&rmu->msg_regs->omr, 0);
dma_free_coherent(priv->dev,
rmu->msg_tx_ring.size * RIO_MSG_DESC_SIZE,
rmu->msg_tx_ring.virt, rmu->msg_tx_ring.phys);
free_irq(IRQ_RIO_TX(mport), (void *)mport);
}
int
fsl_open_inb_mbox(struct rio_mport *mport, void *dev_id, int mbox, int entries)
{
int i, rc = 0;
struct rio_priv *priv = mport->priv;
struct fsl_rmu *rmu = GET_RMM_HANDLE(mport);
if ((entries < RIO_MIN_RX_RING_SIZE) ||
(entries > RIO_MAX_RX_RING_SIZE) || (!is_power_of_2(entries))) {
rc = -EINVAL;
goto out;
}
rmu->msg_rx_ring.dev_id = dev_id;
rmu->msg_rx_ring.size = entries;
rmu->msg_rx_ring.rx_slot = 0;
for (i = 0; i < rmu->msg_rx_ring.size; i++)
rmu->msg_rx_ring.virt_buffer[i] = NULL;
rmu->msg_rx_ring.virt = dma_alloc_coherent(priv->dev,
rmu->msg_rx_ring.size * RIO_MAX_MSG_SIZE,
&rmu->msg_rx_ring.phys, GFP_KERNEL);
if (!rmu->msg_rx_ring.virt) {
rc = -ENOMEM;
goto out;
}
out_be32(&rmu->msg_regs->ifqdpar, (u32) rmu->msg_rx_ring.phys);
out_be32(&rmu->msg_regs->ifqepar, (u32) rmu->msg_rx_ring.phys);
out_be32(&rmu->msg_regs->isr, 0x00000091);
rc = request_irq(IRQ_RIO_RX(mport), fsl_rio_rx_handler, 0,
"msg_rx", (void *)mport);
if (rc < 0) {
dma_free_coherent(priv->dev,
rmu->msg_rx_ring.size * RIO_MAX_MSG_SIZE,
rmu->msg_rx_ring.virt, rmu->msg_rx_ring.phys);
goto out;
}
out_be32(&rmu->msg_regs->imr, 0x001b0060);
setbits32(&rmu->msg_regs->imr, (get_bitmask_order(entries) - 2) << 12);
setbits32(&rmu->msg_regs->imr, 0x1);
out:
return rc;
}
void fsl_close_inb_mbox(struct rio_mport *mport, int mbox)
{
struct rio_priv *priv = mport->priv;
struct fsl_rmu *rmu = GET_RMM_HANDLE(mport);
out_be32(&rmu->msg_regs->imr, 0);
dma_free_coherent(priv->dev, rmu->msg_rx_ring.size * RIO_MAX_MSG_SIZE,
rmu->msg_rx_ring.virt, rmu->msg_rx_ring.phys);
free_irq(IRQ_RIO_RX(mport), (void *)mport);
}
int fsl_add_inb_buffer(struct rio_mport *mport, int mbox, void *buf)
{
int rc = 0;
struct fsl_rmu *rmu = GET_RMM_HANDLE(mport);
pr_debug("RIO: fsl_add_inb_buffer(), msg_rx_ring.rx_slot %d\n",
rmu->msg_rx_ring.rx_slot);
if (rmu->msg_rx_ring.virt_buffer[rmu->msg_rx_ring.rx_slot]) {
printk(KERN_ERR
"RIO: error adding inbound buffer %d, buffer exists\n",
rmu->msg_rx_ring.rx_slot);
rc = -EINVAL;
goto out;
}
rmu->msg_rx_ring.virt_buffer[rmu->msg_rx_ring.rx_slot] = buf;
if (++rmu->msg_rx_ring.rx_slot == rmu->msg_rx_ring.size)
rmu->msg_rx_ring.rx_slot = 0;
out:
return rc;
}
void *fsl_get_inb_message(struct rio_mport *mport, int mbox)
{
struct fsl_rmu *rmu = GET_RMM_HANDLE(mport);
u32 phys_buf;
void *virt_buf;
void *buf = NULL;
int buf_idx;
phys_buf = in_be32(&rmu->msg_regs->ifqdpar);
if (phys_buf == in_be32(&rmu->msg_regs->ifqepar))
goto out2;
virt_buf = rmu->msg_rx_ring.virt + (phys_buf
- rmu->msg_rx_ring.phys);
buf_idx = (phys_buf - rmu->msg_rx_ring.phys) / RIO_MAX_MSG_SIZE;
buf = rmu->msg_rx_ring.virt_buffer[buf_idx];
if (!buf) {
printk(KERN_ERR
"RIO: inbound message copy failed, no buffers\n");
goto out1;
}
memcpy(buf, virt_buf, RIO_MAX_MSG_SIZE);
rmu->msg_rx_ring.virt_buffer[buf_idx] = NULL;
out1:
setbits32(&rmu->msg_regs->imr, RIO_MSG_IMR_MI);
out2:
return buf;
}
int fsl_rio_doorbell_init(struct fsl_rio_dbell *dbell)
{
int rc = 0;
dbell->dbell_ring.virt = dma_alloc_coherent(dbell->dev, 512 *
DOORBELL_MESSAGE_SIZE, &dbell->dbell_ring.phys, GFP_KERNEL);
if (!dbell->dbell_ring.virt) {
printk(KERN_ERR "RIO: unable allocate inbound doorbell ring\n");
rc = -ENOMEM;
goto out;
}
out_be32(&dbell->dbell_regs->dqdpar, (u32) dbell->dbell_ring.phys);
out_be32(&dbell->dbell_regs->dqepar, (u32) dbell->dbell_ring.phys);
out_be32(&dbell->dbell_regs->dsr, 0x00000091);
rc = request_irq(IRQ_RIO_BELL(dbell), fsl_rio_dbell_handler, 0,
"dbell_rx", (void *)dbell);
if (rc < 0) {
dma_free_coherent(dbell->dev, 512 * DOORBELL_MESSAGE_SIZE,
dbell->dbell_ring.virt, dbell->dbell_ring.phys);
printk(KERN_ERR
"MPC85xx RIO: unable to request inbound doorbell irq");
goto out;
}
out_be32(&dbell->dbell_regs->dmr, 0x00108161);
out:
return rc;
}
int fsl_rio_setup_rmu(struct rio_mport *mport, struct device_node *node)
{
struct rio_priv *priv;
struct fsl_rmu *rmu;
u64 msg_start;
const u32 *msg_addr;
int mlen;
int aw;
if (!mport || !mport->priv)
return -EINVAL;
priv = mport->priv;
if (!node) {
dev_warn(priv->dev, "Can't get %pOF property 'fsl,rmu'\n",
priv->dev->of_node);
return -EINVAL;
}
rmu = kzalloc(sizeof(struct fsl_rmu), GFP_KERNEL);
if (!rmu)
return -ENOMEM;
aw = of_n_addr_cells(node);
msg_addr = of_get_property(node, "reg", &mlen);
if (!msg_addr) {
pr_err("%pOF: unable to find 'reg' property of message-unit\n",
node);
kfree(rmu);
return -ENOMEM;
}
msg_start = of_read_number(msg_addr, aw);
rmu->msg_regs = (struct rio_msg_regs *)
(rmu_regs_win + (u32)msg_start);
rmu->txirq = irq_of_parse_and_map(node, 0);
rmu->rxirq = irq_of_parse_and_map(node, 1);
printk(KERN_INFO "%pOF: txirq: %d, rxirq %d\n",
node, rmu->txirq, rmu->rxirq);
priv->rmm_handle = rmu;
rio_init_dbell_res(&mport->riores[RIO_DOORBELL_RESOURCE], 0, 0xffff);
rio_init_mbox_res(&mport->riores[RIO_INB_MBOX_RESOURCE], 0, 0);
rio_init_mbox_res(&mport->riores[RIO_OUTB_MBOX_RESOURCE], 0, 0);
return 0;
}
