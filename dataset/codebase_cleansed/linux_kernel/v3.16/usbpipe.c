int vnt_control_out(struct vnt_private *priv, u8 request, u16 value,
u16 index, u16 length, u8 *buffer)
{
int status = 0;
if (priv->Flags & fMP_DISCONNECTED)
return STATUS_FAILURE;
mutex_lock(&priv->usb_lock);
status = usb_control_msg(priv->usb,
usb_sndctrlpipe(priv->usb, 0), request, 0x40, value,
index, buffer, length, USB_CTL_WAIT);
mutex_unlock(&priv->usb_lock);
if (status < (int)length)
return STATUS_FAILURE;
return STATUS_SUCCESS;
}
void vnt_control_out_u8(struct vnt_private *priv, u8 reg, u8 reg_off, u8 data)
{
vnt_control_out(priv, MESSAGE_TYPE_WRITE,
reg_off, reg, sizeof(u8), &data);
}
int vnt_control_in(struct vnt_private *priv, u8 request, u16 value,
u16 index, u16 length, u8 *buffer)
{
int status;
if (priv->Flags & fMP_DISCONNECTED)
return STATUS_FAILURE;
mutex_lock(&priv->usb_lock);
status = usb_control_msg(priv->usb,
usb_rcvctrlpipe(priv->usb, 0), request, 0xc0, value,
index, buffer, length, USB_CTL_WAIT);
mutex_unlock(&priv->usb_lock);
if (status < (int)length)
return STATUS_FAILURE;
return STATUS_SUCCESS;
}
void vnt_control_in_u8(struct vnt_private *priv, u8 reg, u8 reg_off, u8 *data)
{
vnt_control_in(priv, MESSAGE_TYPE_READ,
reg_off, reg, sizeof(u8), data);
}
int PIPEnsInterruptRead(struct vnt_private *priv)
{
int status = STATUS_FAILURE;
if (priv->int_buf.in_use == true)
return STATUS_FAILURE;
priv->int_buf.in_use = true;
usb_fill_int_urb(priv->pInterruptURB,
priv->usb,
usb_rcvintpipe(priv->usb, 1),
priv->int_buf.data_buf,
MAX_INTERRUPT_SIZE,
s_nsInterruptUsbIoCompleteRead,
priv,
priv->int_interval);
status = usb_submit_urb(priv->pInterruptURB, GFP_ATOMIC);
if (status) {
dev_dbg(&priv->usb->dev, "Submit int URB failed %d\n", status);
priv->int_buf.in_use = false;
}
return status;
}
static void s_nsInterruptUsbIoCompleteRead(struct urb *urb)
{
struct vnt_private *priv = urb->context;
int status;
switch (urb->status) {
case 0:
case -ETIMEDOUT:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
priv->int_buf.in_use = false;
return;
default:
break;
}
status = urb->status;
if (status != STATUS_SUCCESS) {
priv->int_buf.in_use = false;
dev_dbg(&priv->usb->dev, "%s status = %d\n", __func__, status);
} else {
INTnsProcessData(priv);
}
status = usb_submit_urb(priv->pInterruptURB, GFP_ATOMIC);
if (status) {
dev_dbg(&priv->usb->dev, "Submit int URB failed %d\n", status);
} else {
priv->int_buf.in_use = true;
}
return;
}
int PIPEnsBulkInUsbRead(struct vnt_private *priv, struct vnt_rcb *rcb)
{
int status = 0;
struct urb *urb;
if (priv->Flags & fMP_DISCONNECTED)
return STATUS_FAILURE;
urb = rcb->pUrb;
if (rcb->skb == NULL) {
dev_dbg(&priv->usb->dev, "rcb->skb is null\n");
return status;
}
usb_fill_bulk_urb(urb,
priv->usb,
usb_rcvbulkpipe(priv->usb, 2),
(void *) (rcb->skb->data),
MAX_TOTAL_SIZE_WITH_ALL_HEADERS,
s_nsBulkInUsbIoCompleteRead,
rcb);
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status != 0) {
dev_dbg(&priv->usb->dev, "Submit Rx URB failed %d\n", status);
return STATUS_FAILURE ;
}
rcb->Ref = 1;
rcb->bBoolInUse = true;
return status;
}
static void s_nsBulkInUsbIoCompleteRead(struct urb *urb)
{
struct vnt_rcb *rcb = urb->context;
struct vnt_private *priv = rcb->pDevice;
unsigned long flags;
int re_alloc_skb = false;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
case -ETIMEDOUT:
default:
dev_dbg(&priv->usb->dev, "BULK In failed %d\n", urb->status);
break;
}
if (urb->actual_length) {
spin_lock_irqsave(&priv->lock, flags);
if (RXbBulkInProcessData(priv, rcb, urb->actual_length) == true)
re_alloc_skb = true;
spin_unlock_irqrestore(&priv->lock, flags);
}
rcb->Ref--;
if (rcb->Ref == 0) {
dev_dbg(&priv->usb->dev,
"RxvFreeNormal %d\n", priv->NumRecvFreeList);
spin_lock_irqsave(&priv->lock, flags);
RXvFreeRCB(rcb, re_alloc_skb);
spin_unlock_irqrestore(&priv->lock, flags);
}
return;
}
int PIPEnsSendBulkOut(struct vnt_private *priv,
struct vnt_usb_send_context *context)
{
int status;
struct urb *urb;
priv->bPWBitOn = false;
if (!(MP_IS_READY(priv) && priv->Flags & fMP_POST_WRITES)) {
context->in_use = false;
return STATUS_RESOURCES;
}
urb = context->urb;
usb_fill_bulk_urb(urb,
priv->usb,
usb_sndbulkpipe(priv->usb, 3),
context->data,
context->buf_len,
s_nsBulkOutIoCompleteWrite,
context);
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status != 0) {
dev_dbg(&priv->usb->dev, "Submit Tx URB failed %d\n", status);
context->in_use = false;
return STATUS_FAILURE;
}
return STATUS_PENDING;
}
static void s_nsBulkOutIoCompleteWrite(struct urb *urb)
{
struct vnt_usb_send_context *context = urb->context;
struct vnt_private *priv = context->priv;
u8 context_type = context->type;
switch (urb->status) {
case 0:
dev_dbg(&priv->usb->dev, "Write %d bytes\n", context->buf_len);
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
context->in_use = false;
return;
case -ETIMEDOUT:
default:
dev_dbg(&priv->usb->dev, "BULK Out failed %d\n", urb->status);
break;
}
if (!netif_device_present(priv->dev))
return;
if (CONTEXT_DATA_PACKET == context_type) {
if (context->skb != NULL) {
dev_kfree_skb_irq(context->skb);
context->skb = NULL;
dev_dbg(&priv->usb->dev,
"tx %d bytes\n", context->buf_len);
}
priv->dev->trans_start = jiffies;
}
if (priv->bLinkPass == true) {
if (netif_queue_stopped(priv->dev))
netif_wake_queue(priv->dev);
}
context->in_use = false;
return;
}
