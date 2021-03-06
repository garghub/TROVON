static inline u8 ezusb_reply_inc(u8 count)
{
if (count < 0x7F)
return count + 1;
else
return 1;
}
static void ezusb_request_context_put(struct request_context *ctx)
{
if (!atomic_dec_and_test(&ctx->refcount))
return;
WARN_ON(!ctx->done.done);
BUG_ON(ctx->outurb->status == -EINPROGRESS);
BUG_ON(timer_pending(&ctx->timer));
usb_free_urb(ctx->outurb);
kfree(ctx->buf);
kfree(ctx);
}
static inline void ezusb_mod_timer(struct ezusb_priv *upriv,
struct timer_list *timer,
unsigned long expire)
{
if (!upriv->udev)
return;
mod_timer(timer, expire);
}
static void ezusb_request_timerfn(u_long _ctx)
{
struct request_context *ctx = (void *) _ctx;
ctx->outurb->transfer_flags |= URB_ASYNC_UNLINK;
if (usb_unlink_urb(ctx->outurb) == -EINPROGRESS) {
ctx->state = EZUSB_CTX_REQ_TIMEOUT;
} else {
ctx->state = EZUSB_CTX_RESP_TIMEOUT;
dbg("couldn't unlink");
atomic_inc(&ctx->refcount);
ctx->killed = 1;
ezusb_ctx_complete(ctx);
ezusb_request_context_put(ctx);
}
}
static struct request_context *ezusb_alloc_ctx(struct ezusb_priv *upriv,
u16 out_rid, u16 in_rid)
{
struct request_context *ctx;
ctx = kzalloc(sizeof(*ctx), GFP_ATOMIC);
if (!ctx)
return NULL;
ctx->buf = kmalloc(BULK_BUF_SIZE, GFP_ATOMIC);
if (!ctx->buf) {
kfree(ctx);
return NULL;
}
ctx->outurb = usb_alloc_urb(0, GFP_ATOMIC);
if (!ctx->outurb) {
kfree(ctx->buf);
kfree(ctx);
return NULL;
}
ctx->upriv = upriv;
ctx->state = EZUSB_CTX_START;
ctx->out_rid = out_rid;
ctx->in_rid = in_rid;
atomic_set(&ctx->refcount, 1);
init_completion(&ctx->done);
init_timer(&ctx->timer);
ctx->timer.function = ezusb_request_timerfn;
ctx->timer.data = (u_long) ctx;
return ctx;
}
static inline void ezusb_complete_all(struct completion *comp)
{
complete(comp);
complete(comp);
complete(comp);
complete(comp);
}
static void ezusb_ctx_complete(struct request_context *ctx)
{
struct ezusb_priv *upriv = ctx->upriv;
unsigned long flags;
spin_lock_irqsave(&upriv->req_lock, flags);
list_del_init(&ctx->list);
if (upriv->udev) {
spin_unlock_irqrestore(&upriv->req_lock, flags);
ezusb_req_queue_run(upriv);
spin_lock_irqsave(&upriv->req_lock, flags);
}
switch (ctx->state) {
case EZUSB_CTX_COMPLETE:
case EZUSB_CTX_REQSUBMIT_FAIL:
case EZUSB_CTX_REQ_FAILED:
case EZUSB_CTX_REQ_TIMEOUT:
case EZUSB_CTX_RESP_TIMEOUT:
spin_unlock_irqrestore(&upriv->req_lock, flags);
if ((ctx->out_rid == EZUSB_RID_TX) && upriv->dev) {
struct net_device *dev = upriv->dev;
struct orinoco_private *priv = ndev_priv(dev);
struct net_device_stats *stats = &priv->stats;
if (ctx->state != EZUSB_CTX_COMPLETE)
stats->tx_errors++;
else
stats->tx_packets++;
netif_wake_queue(dev);
}
ezusb_complete_all(&ctx->done);
ezusb_request_context_put(ctx);
break;
default:
spin_unlock_irqrestore(&upriv->req_lock, flags);
if (!upriv->udev) {
err("Called, CTX not terminating, but device gone");
ezusb_complete_all(&ctx->done);
ezusb_request_context_put(ctx);
break;
}
err("Called, CTX not in terminating state.");
break;
}
}
static void ezusb_req_queue_run(struct ezusb_priv *upriv)
{
unsigned long flags;
struct request_context *ctx;
int result;
spin_lock_irqsave(&upriv->req_lock, flags);
if (!list_empty(&upriv->req_active))
goto unlock;
if (list_empty(&upriv->req_pending))
goto unlock;
ctx =
list_entry(upriv->req_pending.next, struct request_context,
list);
if (!ctx->upriv->udev)
goto unlock;
list_move_tail(&ctx->list, &upriv->req_active);
if (ctx->state == EZUSB_CTX_QUEUED) {
atomic_inc(&ctx->refcount);
result = usb_submit_urb(ctx->outurb, GFP_ATOMIC);
if (result) {
ctx->state = EZUSB_CTX_REQSUBMIT_FAIL;
spin_unlock_irqrestore(&upriv->req_lock, flags);
err("Fatal, failed to submit command urb."
" error=%d\n", result);
ezusb_ctx_complete(ctx);
ezusb_request_context_put(ctx);
goto done;
}
ctx->state = EZUSB_CTX_REQ_SUBMITTED;
ezusb_mod_timer(ctx->upriv, &ctx->timer,
jiffies + DEF_TIMEOUT);
}
unlock:
spin_unlock_irqrestore(&upriv->req_lock, flags);
done:
return;
}
static void ezusb_req_enqueue_run(struct ezusb_priv *upriv,
struct request_context *ctx)
{
unsigned long flags;
spin_lock_irqsave(&upriv->req_lock, flags);
if (!ctx->upriv->udev) {
spin_unlock_irqrestore(&upriv->req_lock, flags);
goto done;
}
atomic_inc(&ctx->refcount);
list_add_tail(&ctx->list, &upriv->req_pending);
spin_unlock_irqrestore(&upriv->req_lock, flags);
ctx->state = EZUSB_CTX_QUEUED;
ezusb_req_queue_run(upriv);
done:
return;
}
static void ezusb_request_out_callback(struct urb *urb)
{
unsigned long flags;
enum ezusb_state state;
struct request_context *ctx = urb->context;
struct ezusb_priv *upriv = ctx->upriv;
spin_lock_irqsave(&upriv->req_lock, flags);
del_timer(&ctx->timer);
if (ctx->killed) {
spin_unlock_irqrestore(&upriv->req_lock, flags);
pr_warning("interrupt called with dead ctx");
goto out;
}
state = ctx->state;
if (urb->status == 0) {
switch (state) {
case EZUSB_CTX_REQ_SUBMITTED:
if (ctx->in_rid) {
ctx->state = EZUSB_CTX_REQ_COMPLETE;
ezusb_mod_timer(upriv, &ctx->timer,
jiffies + DEF_TIMEOUT);
spin_unlock_irqrestore(&upriv->req_lock,
flags);
break;
}
case EZUSB_CTX_RESP_RECEIVED:
ctx->state = EZUSB_CTX_COMPLETE;
spin_unlock_irqrestore(&upriv->req_lock, flags);
ezusb_ctx_complete(ctx);
break;
default:
spin_unlock_irqrestore(&upriv->req_lock, flags);
err("Unexpected state(0x%x, %d) in OUT URB",
state, urb->status);
break;
}
} else {
switch (state) {
case EZUSB_CTX_REQ_SUBMITTED:
case EZUSB_CTX_RESP_RECEIVED:
ctx->state = EZUSB_CTX_REQ_FAILED;
case EZUSB_CTX_REQ_FAILED:
case EZUSB_CTX_REQ_TIMEOUT:
spin_unlock_irqrestore(&upriv->req_lock, flags);
ezusb_ctx_complete(ctx);
break;
default:
spin_unlock_irqrestore(&upriv->req_lock, flags);
err("Unexpected state(0x%x, %d) in OUT URB",
state, urb->status);
break;
}
}
out:
ezusb_request_context_put(ctx);
}
static void ezusb_request_in_callback(struct ezusb_priv *upriv,
struct urb *urb)
{
struct ezusb_packet *ans = urb->transfer_buffer;
struct request_context *ctx = NULL;
enum ezusb_state state;
unsigned long flags;
spin_lock_irqsave(&upriv->req_lock, flags);
if (upriv->udev) {
struct list_head *item;
list_for_each(item, &upriv->req_active) {
struct request_context *c;
int reply_count;
c = list_entry(item, struct request_context, list);
reply_count =
ezusb_reply_inc(c->buf->req_reply_count);
if ((ans->ans_reply_count == reply_count)
&& (le16_to_cpu(ans->hermes_rid) == c->in_rid)) {
ctx = c;
break;
}
dbg("Skipped (0x%x/0x%x) (%d/%d)",
le16_to_cpu(ans->hermes_rid),
c->in_rid, ans->ans_reply_count, reply_count);
}
}
if (ctx == NULL) {
spin_unlock_irqrestore(&upriv->req_lock, flags);
err("%s: got unexpected RID: 0x%04X", __func__,
le16_to_cpu(ans->hermes_rid));
ezusb_req_queue_run(upriv);
return;
}
urb->transfer_buffer = ctx->buf;
ctx->buf = (void *) ans;
ctx->buf_length = urb->actual_length;
state = ctx->state;
switch (state) {
case EZUSB_CTX_REQ_SUBMITTED:
ctx->state = EZUSB_CTX_RESP_RECEIVED;
spin_unlock_irqrestore(&upriv->req_lock, flags);
break;
case EZUSB_CTX_REQ_COMPLETE:
ctx->state = EZUSB_CTX_COMPLETE;
del_timer(&ctx->timer);
spin_unlock_irqrestore(&upriv->req_lock, flags);
ezusb_ctx_complete(ctx);
break;
default:
spin_unlock_irqrestore(&upriv->req_lock, flags);
pr_warning("Matched IN URB, unexpected context state(0x%x)",
state);
del_timer(&ctx->timer);
ctx->outurb->transfer_flags |= URB_ASYNC_UNLINK;
usb_unlink_urb(ctx->outurb);
ezusb_req_queue_run(upriv);
break;
}
}
static void ezusb_req_ctx_wait(struct ezusb_priv *upriv,
struct request_context *ctx)
{
switch (ctx->state) {
case EZUSB_CTX_QUEUED:
case EZUSB_CTX_REQ_SUBMITTED:
case EZUSB_CTX_REQ_COMPLETE:
case EZUSB_CTX_RESP_RECEIVED:
if (in_softirq()) {
int msecs = DEF_TIMEOUT * (1000 / HZ);
while (!ctx->done.done && msecs--)
udelay(1000);
} else {
wait_event_interruptible(ctx->done.wait,
ctx->done.done);
}
break;
default:
break;
}
}
static inline u16 build_crc(struct ezusb_packet *data)
{
u16 crc = 0;
u8 *bytes = (u8 *)data;
int i;
for (i = 0; i < 8; i++)
crc = (crc << 1) + bytes[i];
return crc;
}
static int ezusb_fill_req(struct ezusb_packet *req, u16 length, u16 rid,
const void *data, u16 frame_type, u8 reply_count)
{
int total_size = sizeof(*req) + length;
BUG_ON(total_size > BULK_BUF_SIZE);
req->magic = cpu_to_le16(EZUSB_MAGIC);
req->req_reply_count = reply_count;
req->ans_reply_count = 0;
req->frame_type = cpu_to_le16(frame_type);
req->size = cpu_to_le16(length + 4);
req->crc = cpu_to_le16(build_crc(req));
req->hermes_len = cpu_to_le16(HERMES_BYTES_TO_RECLEN(length));
req->hermes_rid = cpu_to_le16(rid);
if (data)
memcpy(req->data, data, length);
return total_size;
}
static int ezusb_submit_in_urb(struct ezusb_priv *upriv)
{
int retval = 0;
void *cur_buf = upriv->read_urb->transfer_buffer;
if (upriv->read_urb->status == -EINPROGRESS) {
dbg("urb busy, not resubmiting");
retval = -EBUSY;
goto exit;
}
usb_fill_bulk_urb(upriv->read_urb, upriv->udev, upriv->read_pipe,
cur_buf, BULK_BUF_SIZE,
ezusb_bulk_in_callback, upriv);
upriv->read_urb->transfer_flags = 0;
retval = usb_submit_urb(upriv->read_urb, GFP_ATOMIC);
if (retval)
err("%s submit failed %d", __func__, retval);
exit:
return retval;
}
static inline int ezusb_8051_cpucs(struct ezusb_priv *upriv, int reset)
{
u8 res_val = reset;
if (!upriv->udev) {
err("%s: !upriv->udev", __func__);
return -EFAULT;
}
return usb_control_msg(upriv->udev,
usb_sndctrlpipe(upriv->udev, 0),
EZUSB_REQUEST_FW_TRANS,
USB_TYPE_VENDOR | USB_RECIP_DEVICE |
USB_DIR_OUT, EZUSB_CPUCS_REG, 0, &res_val,
sizeof(res_val), DEF_TIMEOUT);
}
static int ezusb_firmware_download(struct ezusb_priv *upriv,
struct ez_usb_fw *fw)
{
u8 fw_buffer[FW_BUF_SIZE];
int retval, addr;
int variant_offset;
variant_offset = be16_to_cpup((__be16 *) &fw->code[FW_VAR_OFFSET_PTR]);
if (variant_offset >= fw->size) {
printk(KERN_ERR PFX "Invalid firmware variant offset: "
"0x%04x\n", variant_offset);
retval = -EINVAL;
goto fail;
}
retval = ezusb_8051_cpucs(upriv, 1);
if (retval < 0)
goto fail;
for (addr = 0; addr < fw->size; addr += FW_BUF_SIZE) {
if ((addr >= FW_HOLE_START) && (addr < FW_HOLE_END))
continue;
memcpy(fw_buffer, &fw->code[addr], FW_BUF_SIZE);
if (variant_offset >= addr &&
variant_offset < addr + FW_BUF_SIZE) {
dbg("Patching card_variant byte at 0x%04X",
variant_offset);
fw_buffer[variant_offset - addr] = FW_VAR_VALUE;
}
retval = usb_control_msg(upriv->udev,
usb_sndctrlpipe(upriv->udev, 0),
EZUSB_REQUEST_FW_TRANS,
USB_TYPE_VENDOR | USB_RECIP_DEVICE
| USB_DIR_OUT,
addr, 0x0,
fw_buffer, FW_BUF_SIZE,
DEF_TIMEOUT);
if (retval < 0)
goto fail;
}
retval = ezusb_8051_cpucs(upriv, 0);
if (retval < 0)
goto fail;
goto exit;
fail:
printk(KERN_ERR PFX "Firmware download failed, error %d\n",
retval);
exit:
return retval;
}
static int ezusb_access_ltv(struct ezusb_priv *upriv,
struct request_context *ctx,
u16 length, const void *data, u16 frame_type,
void *ans_buff, int ans_size, u16 *ans_length)
{
int req_size;
int retval = 0;
enum ezusb_state state;
BUG_ON(in_irq());
if (!upriv->udev) {
dbg("Device disconnected");
return -ENODEV;
}
if (upriv->read_urb->status != -EINPROGRESS)
err("%s: in urb not pending", __func__);
spin_lock_bh(&upriv->reply_count_lock);
req_size = ezusb_fill_req(ctx->buf, length, ctx->out_rid, data,
frame_type, upriv->reply_count);
usb_fill_bulk_urb(ctx->outurb, upriv->udev, upriv->write_pipe,
ctx->buf, req_size,
ezusb_request_out_callback, ctx);
if (ctx->in_rid)
upriv->reply_count = ezusb_reply_inc(upriv->reply_count);
ezusb_req_enqueue_run(upriv, ctx);
spin_unlock_bh(&upriv->reply_count_lock);
if (ctx->in_rid)
ezusb_req_ctx_wait(upriv, ctx);
state = ctx->state;
switch (state) {
case EZUSB_CTX_COMPLETE:
retval = ctx->outurb->status;
break;
case EZUSB_CTX_QUEUED:
case EZUSB_CTX_REQ_SUBMITTED:
if (!ctx->in_rid)
break;
default:
err("%s: Unexpected context state %d", __func__,
state);
case EZUSB_CTX_REQ_TIMEOUT:
case EZUSB_CTX_REQ_FAILED:
case EZUSB_CTX_RESP_TIMEOUT:
case EZUSB_CTX_REQSUBMIT_FAIL:
printk(KERN_ERR PFX "Access failed, resetting (state %d,"
" reply_count %d)\n", state, upriv->reply_count);
upriv->reply_count = 0;
if (state == EZUSB_CTX_REQ_TIMEOUT
|| state == EZUSB_CTX_RESP_TIMEOUT) {
printk(KERN_ERR PFX "ctx timed out\n");
retval = -ETIMEDOUT;
} else {
printk(KERN_ERR PFX "ctx failed\n");
retval = -EFAULT;
}
goto exit;
break;
}
if (ctx->in_rid) {
struct ezusb_packet *ans = ctx->buf;
int exp_len;
if (ans->hermes_len != 0)
exp_len = le16_to_cpu(ans->hermes_len) * 2 + 12;
else
exp_len = 14;
if (exp_len != ctx->buf_length) {
err("%s: length mismatch for RID 0x%04x: "
"expected %d, got %d", __func__,
ctx->in_rid, exp_len, ctx->buf_length);
retval = -EIO;
goto exit;
}
if (ans_buff)
memcpy(ans_buff, ans->data,
min_t(int, exp_len, ans_size));
if (ans_length)
*ans_length = le16_to_cpu(ans->hermes_len);
}
exit:
ezusb_request_context_put(ctx);
return retval;
}
static int ezusb_write_ltv(struct hermes *hw, int bap, u16 rid,
u16 length, const void *data)
{
struct ezusb_priv *upriv = hw->priv;
u16 frame_type;
struct request_context *ctx;
if (length == 0)
return -EINVAL;
length = HERMES_RECLEN_TO_BYTES(length);
if (length == 0)
return 0;
ctx = ezusb_alloc_ctx(upriv, rid, EZUSB_RID_ACK);
if (!ctx)
return -ENOMEM;
if (rid == EZUSB_RID_TX)
frame_type = EZUSB_FRAME_DATA;
else
frame_type = EZUSB_FRAME_CONTROL;
return ezusb_access_ltv(upriv, ctx, length, data, frame_type,
NULL, 0, NULL);
}
static int ezusb_read_ltv(struct hermes *hw, int bap, u16 rid,
unsigned bufsize, u16 *length, void *buf)
{
struct ezusb_priv *upriv = hw->priv;
struct request_context *ctx;
if ((bufsize < 0) || (bufsize % 2))
return -EINVAL;
ctx = ezusb_alloc_ctx(upriv, rid, rid);
if (!ctx)
return -ENOMEM;
return ezusb_access_ltv(upriv, ctx, 0, NULL, EZUSB_FRAME_CONTROL,
buf, bufsize, length);
}
static int ezusb_doicmd_wait(struct hermes *hw, u16 cmd, u16 parm0, u16 parm1,
u16 parm2, struct hermes_response *resp)
{
struct ezusb_priv *upriv = hw->priv;
struct request_context *ctx;
__le16 data[4] = {
cpu_to_le16(cmd),
cpu_to_le16(parm0),
cpu_to_le16(parm1),
cpu_to_le16(parm2),
};
dbg("0x%04X, parm0 0x%04X, parm1 0x%04X, parm2 0x%04X",
cmd, parm0, parm1, parm2);
ctx = ezusb_alloc_ctx(upriv, EZUSB_RID_DOCMD, EZUSB_RID_ACK);
if (!ctx)
return -ENOMEM;
return ezusb_access_ltv(upriv, ctx, sizeof(data), &data,
EZUSB_FRAME_CONTROL, NULL, 0, NULL);
}
static int ezusb_docmd_wait(struct hermes *hw, u16 cmd, u16 parm0,
struct hermes_response *resp)
{
struct ezusb_priv *upriv = hw->priv;
struct request_context *ctx;
__le16 data[4] = {
cpu_to_le16(cmd),
cpu_to_le16(parm0),
0,
0,
};
dbg("0x%04X, parm0 0x%04X", cmd, parm0);
ctx = ezusb_alloc_ctx(upriv, EZUSB_RID_DOCMD, EZUSB_RID_ACK);
if (!ctx)
return -ENOMEM;
return ezusb_access_ltv(upriv, ctx, sizeof(data), &data,
EZUSB_FRAME_CONTROL, NULL, 0, NULL);
}
static int ezusb_bap_pread(struct hermes *hw, int bap,
void *buf, int len, u16 id, u16 offset)
{
struct ezusb_priv *upriv = hw->priv;
struct ezusb_packet *ans = (void *) upriv->read_urb->transfer_buffer;
int actual_length = upriv->read_urb->actual_length;
if (id == EZUSB_RID_RX) {
if ((sizeof(*ans) + offset + len) > actual_length) {
printk(KERN_ERR PFX "BAP read beyond buffer end "
"in rx frame\n");
return -EINVAL;
}
memcpy(buf, ans->data + offset, len);
return 0;
}
if (EZUSB_IS_INFO(id)) {
if ((sizeof(*ans) + offset + len - 4) > actual_length) {
printk(KERN_ERR PFX "BAP read beyond buffer end "
"in info frame\n");
return -EFAULT;
}
memcpy(buf, ans->data + offset - 4, len);
} else {
printk(KERN_ERR PFX "Unexpected fid 0x%04x\n", id);
return -EINVAL;
}
return 0;
}
static int ezusb_read_pda(struct hermes *hw, __le16 *pda,
u32 pda_addr, u16 pda_len)
{
struct ezusb_priv *upriv = hw->priv;
struct request_context *ctx;
__le16 data[] = {
cpu_to_le16(pda_addr & 0xffff),
cpu_to_le16(pda_len - 4)
};
ctx = ezusb_alloc_ctx(upriv, EZUSB_RID_READ_PDA, EZUSB_RID_READ_PDA);
if (!ctx)
return -ENOMEM;
pda[0] = cpu_to_le16(pda_len - 2);
pda[1] = cpu_to_le16(0x0800);
return ezusb_access_ltv(upriv, ctx, sizeof(data), &data,
EZUSB_FRAME_CONTROL, &pda[2], pda_len - 4,
NULL);
}
static int ezusb_program_init(struct hermes *hw, u32 entry_point)
{
struct ezusb_priv *upriv = hw->priv;
struct request_context *ctx;
__le32 data = cpu_to_le32(entry_point);
ctx = ezusb_alloc_ctx(upriv, EZUSB_RID_PROG_INIT, EZUSB_RID_ACK);
if (!ctx)
return -ENOMEM;
return ezusb_access_ltv(upriv, ctx, sizeof(data), &data,
EZUSB_FRAME_CONTROL, NULL, 0, NULL);
}
static int ezusb_program_end(struct hermes *hw)
{
struct ezusb_priv *upriv = hw->priv;
struct request_context *ctx;
ctx = ezusb_alloc_ctx(upriv, EZUSB_RID_PROG_END, EZUSB_RID_ACK);
if (!ctx)
return -ENOMEM;
return ezusb_access_ltv(upriv, ctx, 0, NULL,
EZUSB_FRAME_CONTROL, NULL, 0, NULL);
}
static int ezusb_program_bytes(struct hermes *hw, const char *buf,
u32 addr, u32 len)
{
struct ezusb_priv *upriv = hw->priv;
struct request_context *ctx;
__le32 data = cpu_to_le32(addr);
int err;
ctx = ezusb_alloc_ctx(upriv, EZUSB_RID_PROG_SET_ADDR, EZUSB_RID_ACK);
if (!ctx)
return -ENOMEM;
err = ezusb_access_ltv(upriv, ctx, sizeof(data), &data,
EZUSB_FRAME_CONTROL, NULL, 0, NULL);
if (err)
return err;
ctx = ezusb_alloc_ctx(upriv, EZUSB_RID_PROG_BYTES, EZUSB_RID_ACK);
if (!ctx)
return -ENOMEM;
return ezusb_access_ltv(upriv, ctx, len, buf,
EZUSB_FRAME_CONTROL, NULL, 0, NULL);
}
static int ezusb_program(struct hermes *hw, const char *buf,
u32 addr, u32 len)
{
u32 ch_addr;
u32 ch_len;
int err = 0;
ch_len = (len < MAX_DL_SIZE) ? len : MAX_DL_SIZE;
ch_addr = addr;
while (ch_addr < (addr + len)) {
pr_debug("Programming subblock of length %d "
"to address 0x%08x. Data @ %p\n",
ch_len, ch_addr, &buf[ch_addr - addr]);
err = ezusb_program_bytes(hw, &buf[ch_addr - addr],
ch_addr, ch_len);
if (err)
break;
ch_addr += ch_len;
ch_len = ((addr + len - ch_addr) < MAX_DL_SIZE) ?
(addr + len - ch_addr) : MAX_DL_SIZE;
}
return err;
}
static netdev_tx_t ezusb_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct orinoco_private *priv = ndev_priv(dev);
struct net_device_stats *stats = &priv->stats;
struct ezusb_priv *upriv = priv->card;
u8 mic[MICHAEL_MIC_LEN + 1];
int err = 0;
int tx_control;
unsigned long flags;
struct request_context *ctx;
u8 *buf;
int tx_size;
if (!netif_running(dev)) {
printk(KERN_ERR "%s: Tx on stopped device!\n",
dev->name);
return NETDEV_TX_BUSY;
}
if (netif_queue_stopped(dev)) {
printk(KERN_DEBUG "%s: Tx while transmitter busy!\n",
dev->name);
return NETDEV_TX_BUSY;
}
if (orinoco_lock(priv, &flags) != 0) {
printk(KERN_ERR
"%s: ezusb_xmit() called while hw_unavailable\n",
dev->name);
return NETDEV_TX_BUSY;
}
if (!netif_carrier_ok(dev) ||
(priv->iw_mode == NL80211_IFTYPE_MONITOR)) {
goto drop;
}
if (skb->len < ETH_HLEN)
goto drop;
ctx = ezusb_alloc_ctx(upriv, EZUSB_RID_TX, 0);
if (!ctx)
goto busy;
memset(ctx->buf, 0, BULK_BUF_SIZE);
buf = ctx->buf->data;
tx_control = 0;
err = orinoco_process_xmit_skb(skb, dev, priv, &tx_control,
&mic[0]);
if (err)
goto drop;
{
__le16 *tx_cntl = (__le16 *)buf;
*tx_cntl = cpu_to_le16(tx_control);
buf += sizeof(*tx_cntl);
}
memcpy(buf, skb->data, skb->len);
buf += skb->len;
if (tx_control & HERMES_TXCTRL_MIC) {
u8 *m = mic;
if (skb->len % 2)
m++;
memcpy(buf, m, MICHAEL_MIC_LEN);
buf += MICHAEL_MIC_LEN;
}
netif_stop_queue(dev);
tx_size = ALIGN(buf - ctx->buf->data, 2);
err = ezusb_access_ltv(upriv, ctx, tx_size, NULL,
EZUSB_FRAME_DATA, NULL, 0, NULL);
if (err) {
netif_start_queue(dev);
if (net_ratelimit())
printk(KERN_ERR "%s: Error %d transmitting packet\n",
dev->name, err);
goto busy;
}
dev->trans_start = jiffies;
stats->tx_bytes += skb->len;
goto ok;
drop:
stats->tx_errors++;
stats->tx_dropped++;
ok:
orinoco_unlock(priv, &flags);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
busy:
orinoco_unlock(priv, &flags);
return NETDEV_TX_BUSY;
}
static int ezusb_allocate(struct hermes *hw, u16 size, u16 *fid)
{
*fid = EZUSB_RID_TX;
return 0;
}
static int ezusb_hard_reset(struct orinoco_private *priv)
{
struct ezusb_priv *upriv = priv->card;
int retval = ezusb_8051_cpucs(upriv, 1);
if (retval < 0) {
err("Failed to reset");
return retval;
}
retval = ezusb_8051_cpucs(upriv, 0);
if (retval < 0) {
err("Failed to unreset");
return retval;
}
dbg("sending control message");
retval = usb_control_msg(upriv->udev,
usb_sndctrlpipe(upriv->udev, 0),
EZUSB_REQUEST_TRIGER,
USB_TYPE_VENDOR | USB_RECIP_DEVICE |
USB_DIR_OUT, 0x0, 0x0, NULL, 0,
DEF_TIMEOUT);
if (retval < 0) {
err("EZUSB_REQUEST_TRIGER failed retval %d", retval);
return retval;
}
#if 0
dbg("Sending EZUSB_REQUEST_TRIG_AC");
retval = usb_control_msg(upriv->udev,
usb_sndctrlpipe(upriv->udev, 0),
EZUSB_REQUEST_TRIG_AC,
USB_TYPE_VENDOR | USB_RECIP_DEVICE |
USB_DIR_OUT, 0x00FA, 0x0, NULL, 0,
DEF_TIMEOUT);
if (retval < 0) {
err("EZUSB_REQUEST_TRIG_AC failed retval %d", retval);
return retval;
}
#endif
return 0;
}
static int ezusb_init(struct hermes *hw)
{
struct ezusb_priv *upriv = hw->priv;
int retval;
BUG_ON(in_interrupt());
BUG_ON(!upriv);
upriv->reply_count = 0;
hermes_write_regn(hw, SWSUPPORT0, HERMES_MAGIC);
hermes_write_regn(hw, RXFID, EZUSB_RID_RX);
usb_kill_urb(upriv->read_urb);
ezusb_submit_in_urb(upriv);
retval = ezusb_write_ltv(hw, 0, EZUSB_RID_INIT1,
HERMES_BYTES_TO_RECLEN(2), "\x10\x00");
if (retval < 0) {
printk(KERN_ERR PFX "EZUSB_RID_INIT1 error %d\n", retval);
return retval;
}
retval = ezusb_docmd_wait(hw, HERMES_CMD_INIT, 0, NULL);
if (retval < 0) {
printk(KERN_ERR PFX "HERMES_CMD_INIT error %d\n", retval);
return retval;
}
return 0;
}
static void ezusb_bulk_in_callback(struct urb *urb)
{
struct ezusb_priv *upriv = (struct ezusb_priv *) urb->context;
struct ezusb_packet *ans = urb->transfer_buffer;
u16 crc;
u16 hermes_rid;
if (upriv->udev == NULL) {
dbg("disconnected");
return;
}
if (urb->status == -ETIMEDOUT) {
pr_warning("%s: urb timed out, not resubmiting", __func__);
return;
}
if (urb->status == -ECONNABORTED) {
pr_warning("%s: connection abort, resubmiting urb",
__func__);
goto resubmit;
}
if ((urb->status == -EILSEQ)
|| (urb->status == -ENOENT)
|| (urb->status == -ECONNRESET)) {
dbg("status %d, not resubmiting", urb->status);
return;
}
if (urb->status)
dbg("status: %d length: %d",
urb->status, urb->actual_length);
if (urb->actual_length < sizeof(*ans)) {
err("%s: short read, ignoring", __func__);
goto resubmit;
}
crc = build_crc(ans);
if (le16_to_cpu(ans->crc) != crc) {
err("CRC error, ignoring packet");
goto resubmit;
}
hermes_rid = le16_to_cpu(ans->hermes_rid);
if ((hermes_rid != EZUSB_RID_RX) && !EZUSB_IS_INFO(hermes_rid)) {
ezusb_request_in_callback(upriv, urb);
} else if (upriv->dev) {
struct net_device *dev = upriv->dev;
struct orinoco_private *priv = ndev_priv(dev);
struct hermes *hw = &priv->hw;
if (hermes_rid == EZUSB_RID_RX) {
__orinoco_ev_rx(dev, hw);
} else {
hermes_write_regn(hw, INFOFID,
le16_to_cpu(ans->hermes_rid));
__orinoco_ev_info(dev, hw);
}
}
resubmit:
if (upriv->udev)
ezusb_submit_in_urb(upriv);
}
static inline void ezusb_delete(struct ezusb_priv *upriv)
{
struct net_device *dev;
struct list_head *item;
struct list_head *tmp_item;
unsigned long flags;
BUG_ON(in_interrupt());
BUG_ON(!upriv);
dev = upriv->dev;
mutex_lock(&upriv->mtx);
upriv->udev = NULL;
usb_kill_urb(upriv->read_urb);
spin_lock_irqsave(&upriv->req_lock, flags);
list_for_each_safe(item, tmp_item, &upriv->req_active) {
struct request_context *ctx;
int err;
ctx = list_entry(item, struct request_context, list);
atomic_inc(&ctx->refcount);
ctx->outurb->transfer_flags |= URB_ASYNC_UNLINK;
err = usb_unlink_urb(ctx->outurb);
spin_unlock_irqrestore(&upriv->req_lock, flags);
if (err == -EINPROGRESS)
wait_for_completion(&ctx->done);
del_timer_sync(&ctx->timer);
if (!list_empty(&ctx->list))
ezusb_ctx_complete(ctx);
ezusb_request_context_put(ctx);
spin_lock_irqsave(&upriv->req_lock, flags);
}
spin_unlock_irqrestore(&upriv->req_lock, flags);
list_for_each_safe(item, tmp_item, &upriv->req_pending)
ezusb_ctx_complete(list_entry(item,
struct request_context, list));
if (upriv->read_urb && upriv->read_urb->status == -EINPROGRESS)
printk(KERN_ERR PFX "Some URB in progress\n");
mutex_unlock(&upriv->mtx);
if (upriv->read_urb) {
kfree(upriv->read_urb->transfer_buffer);
usb_free_urb(upriv->read_urb);
}
kfree(upriv->bap_buf);
if (upriv->dev) {
struct orinoco_private *priv = ndev_priv(upriv->dev);
orinoco_if_del(priv);
free_orinocodev(priv);
}
}
static void ezusb_lock_irqsave(spinlock_t *lock,
unsigned long *flags) __acquires(lock)
{
spin_lock_bh(lock);
}
static void ezusb_unlock_irqrestore(spinlock_t *lock,
unsigned long *flags) __releases(lock)
{
spin_unlock_bh(lock);
}
static void ezusb_lock_irq(spinlock_t *lock) __acquires(lock)
{
spin_lock_bh(lock);
}
static void ezusb_unlock_irq(spinlock_t *lock) __releases(lock)
{
spin_unlock_bh(lock);
}
static int ezusb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(interface);
struct orinoco_private *priv;
struct hermes *hw;
struct ezusb_priv *upriv = NULL;
struct usb_interface_descriptor *iface_desc;
struct usb_endpoint_descriptor *ep;
const struct firmware *fw_entry;
int retval = 0;
int i;
priv = alloc_orinocodev(sizeof(*upriv), &udev->dev,
ezusb_hard_reset, NULL);
if (!priv) {
err("Couldn't allocate orinocodev");
goto exit;
}
hw = &priv->hw;
upriv = priv->card;
mutex_init(&upriv->mtx);
spin_lock_init(&upriv->reply_count_lock);
spin_lock_init(&upriv->req_lock);
INIT_LIST_HEAD(&upriv->req_pending);
INIT_LIST_HEAD(&upriv->req_active);
upriv->udev = udev;
hw->iobase = (void __force __iomem *) &upriv->hermes_reg_fake;
hw->reg_spacing = HERMES_16BIT_REGSPACING;
hw->priv = upriv;
hw->ops = &ezusb_ops;
iface_desc = &interface->altsetting[0].desc;
for (i = 0; i < iface_desc->bNumEndpoints; ++i) {
ep = &interface->altsetting[0].endpoint[i].desc;
if (((ep->bEndpointAddress & USB_ENDPOINT_DIR_MASK)
== USB_DIR_IN) &&
((ep->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK)
== USB_ENDPOINT_XFER_BULK)) {
if (upriv->read_urb != NULL) {
pr_warning("Found a second bulk in ep, ignored");
continue;
}
upriv->read_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!upriv->read_urb) {
err("No free urbs available");
goto error;
}
if (le16_to_cpu(ep->wMaxPacketSize) != 64)
pr_warning("bulk in: wMaxPacketSize!= 64");
if (ep->bEndpointAddress != (2 | USB_DIR_IN))
pr_warning("bulk in: bEndpointAddress: %d",
ep->bEndpointAddress);
upriv->read_pipe = usb_rcvbulkpipe(udev,
ep->
bEndpointAddress);
upriv->read_urb->transfer_buffer =
kmalloc(BULK_BUF_SIZE, GFP_KERNEL);
if (!upriv->read_urb->transfer_buffer) {
err("Couldn't allocate IN buffer");
goto error;
}
}
if (((ep->bEndpointAddress & USB_ENDPOINT_DIR_MASK)
== USB_DIR_OUT) &&
((ep->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK)
== USB_ENDPOINT_XFER_BULK)) {
if (upriv->bap_buf != NULL) {
pr_warning("Found a second bulk out ep, ignored");
continue;
}
if (le16_to_cpu(ep->wMaxPacketSize) != 64)
pr_warning("bulk out: wMaxPacketSize != 64");
if (ep->bEndpointAddress != 2)
pr_warning("bulk out: bEndpointAddress: %d",
ep->bEndpointAddress);
upriv->write_pipe = usb_sndbulkpipe(udev,
ep->
bEndpointAddress);
upriv->bap_buf = kmalloc(BULK_BUF_SIZE, GFP_KERNEL);
if (!upriv->bap_buf) {
err("Couldn't allocate bulk_out_buffer");
goto error;
}
}
}
if (!upriv->bap_buf || !upriv->read_urb) {
err("Didn't find the required bulk endpoints");
goto error;
}
if (request_firmware(&fw_entry, "orinoco_ezusb_fw",
&interface->dev) == 0) {
firmware.size = fw_entry->size;
firmware.code = fw_entry->data;
}
if (firmware.size && firmware.code) {
ezusb_firmware_download(upriv, &firmware);
} else {
err("No firmware to download");
goto error;
}
if (ezusb_hard_reset(priv) < 0) {
err("Cannot reset the device");
goto error;
}
if (ezusb_init(hw) < 0) {
err("Couldn't initialize the device");
err("Firmware may not be downloaded or may be wrong.");
goto error;
}
if (orinoco_init(priv) != 0) {
err("orinoco_init() failed\n");
goto error;
}
if (orinoco_if_add(priv, 0, 0, &ezusb_netdev_ops) != 0) {
upriv->dev = NULL;
err("%s: orinoco_if_add() failed", __func__);
goto error;
}
upriv->dev = priv->ndev;
goto exit;
error:
ezusb_delete(upriv);
if (upriv->dev) {
free_orinocodev(priv);
}
upriv = NULL;
retval = -EFAULT;
exit:
if (fw_entry) {
firmware.code = NULL;
firmware.size = 0;
release_firmware(fw_entry);
}
usb_set_intfdata(interface, upriv);
return retval;
}
static void ezusb_disconnect(struct usb_interface *intf)
{
struct ezusb_priv *upriv = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
ezusb_delete(upriv);
printk(KERN_INFO PFX "Disconnected\n");
}
static int __init ezusb_module_init(void)
{
int err;
printk(KERN_DEBUG "%s\n", version);
err = usb_register(&orinoco_driver);
if (err < 0) {
printk(KERN_ERR PFX "usb_register failed, error %d\n",
err);
return err;
}
return 0;
}
static void __exit ezusb_module_exit(void)
{
usb_deregister(&orinoco_driver);
}
