static int ti_sci_debug_show(struct seq_file *s, void *unused)
{
struct ti_sci_info *info = s->private;
memcpy_fromio(info->debug_buffer, info->debug_region,
info->debug_region_size);
seq_puts(s, info->debug_buffer);
return 0;
}
static int ti_sci_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, ti_sci_debug_show, inode->i_private);
}
static int ti_sci_debugfs_create(struct platform_device *pdev,
struct ti_sci_info *info)
{
struct device *dev = &pdev->dev;
struct resource *res;
char debug_name[50] = "ti_sci_debug@";
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"debug_messages");
info->debug_region = devm_ioremap_resource(dev, res);
if (IS_ERR(info->debug_region))
return 0;
info->debug_region_size = resource_size(res);
info->debug_buffer = devm_kcalloc(dev, info->debug_region_size + 1,
sizeof(char), GFP_KERNEL);
if (!info->debug_buffer)
return -ENOMEM;
info->debug_buffer[info->debug_region_size] = 0;
info->d = debugfs_create_file(strncat(debug_name, dev_name(dev),
sizeof(debug_name)),
0444, NULL, info, &ti_sci_debug_fops);
if (IS_ERR(info->d))
return PTR_ERR(info->d);
dev_dbg(dev, "Debug region => %p, size = %zu bytes, resource: %pr\n",
info->debug_region, info->debug_region_size, res);
return 0;
}
static void ti_sci_debugfs_destroy(struct platform_device *pdev,
struct ti_sci_info *info)
{
if (IS_ERR(info->debug_region))
return;
debugfs_remove(info->d);
}
static inline int ti_sci_debugfs_create(struct platform_device *dev,
struct ti_sci_info *info)
{
return 0;
}
static inline void ti_sci_debugfs_destroy(struct platform_device *dev,
struct ti_sci_info *info)
{
}
static inline void ti_sci_dump_header_dbg(struct device *dev,
struct ti_sci_msg_hdr *hdr)
{
dev_dbg(dev, "MSGHDR:type=0x%04x host=0x%02x seq=0x%02x flags=0x%08x\n",
hdr->type, hdr->host, hdr->seq, hdr->flags);
}
static void ti_sci_rx_callback(struct mbox_client *cl, void *m)
{
struct ti_sci_info *info = cl_to_ti_sci_info(cl);
struct device *dev = info->dev;
struct ti_sci_xfers_info *minfo = &info->minfo;
struct ti_msgmgr_message *mbox_msg = m;
struct ti_sci_msg_hdr *hdr = (struct ti_sci_msg_hdr *)mbox_msg->buf;
struct ti_sci_xfer *xfer;
u8 xfer_id;
xfer_id = hdr->seq;
if (!test_bit(xfer_id, minfo->xfer_alloc_table)) {
dev_err(dev, "Message for %d is not expected!\n", xfer_id);
return;
}
xfer = &minfo->xfer_block[xfer_id];
if (mbox_msg->len > info->desc->max_msg_size) {
dev_err(dev, "Unable to handle %d xfer(max %d)\n",
mbox_msg->len, info->desc->max_msg_size);
ti_sci_dump_header_dbg(dev, hdr);
return;
}
if (mbox_msg->len < xfer->rx_len) {
dev_err(dev, "Recv xfer %d < expected %d length\n",
mbox_msg->len, xfer->rx_len);
ti_sci_dump_header_dbg(dev, hdr);
return;
}
ti_sci_dump_header_dbg(dev, hdr);
memcpy(xfer->xfer_buf, mbox_msg->buf, xfer->rx_len);
complete(&xfer->done);
}
static struct ti_sci_xfer *ti_sci_get_one_xfer(struct ti_sci_info *info,
u16 msg_type, u32 msg_flags,
size_t tx_message_size,
size_t rx_message_size)
{
struct ti_sci_xfers_info *minfo = &info->minfo;
struct ti_sci_xfer *xfer;
struct ti_sci_msg_hdr *hdr;
unsigned long flags;
unsigned long bit_pos;
u8 xfer_id;
int ret;
int timeout;
if (rx_message_size > info->desc->max_msg_size ||
tx_message_size > info->desc->max_msg_size ||
rx_message_size < sizeof(*hdr) || tx_message_size < sizeof(*hdr))
return ERR_PTR(-ERANGE);
timeout = msecs_to_jiffies(info->desc->max_rx_timeout_ms) * 5;
ret = down_timeout(&minfo->sem_xfer_count, timeout);
if (ret < 0)
return ERR_PTR(ret);
spin_lock_irqsave(&minfo->xfer_lock, flags);
bit_pos = find_first_zero_bit(minfo->xfer_alloc_table,
info->desc->max_msgs);
set_bit(bit_pos, minfo->xfer_alloc_table);
spin_unlock_irqrestore(&minfo->xfer_lock, flags);
xfer_id = (u8)bit_pos;
xfer = &minfo->xfer_block[xfer_id];
hdr = (struct ti_sci_msg_hdr *)xfer->tx_message.buf;
xfer->tx_message.len = tx_message_size;
xfer->rx_len = (u8)rx_message_size;
reinit_completion(&xfer->done);
hdr->seq = xfer_id;
hdr->type = msg_type;
hdr->host = info->desc->host_id;
hdr->flags = msg_flags;
return xfer;
}
static void ti_sci_put_one_xfer(struct ti_sci_xfers_info *minfo,
struct ti_sci_xfer *xfer)
{
unsigned long flags;
struct ti_sci_msg_hdr *hdr;
u8 xfer_id;
hdr = (struct ti_sci_msg_hdr *)xfer->tx_message.buf;
xfer_id = hdr->seq;
spin_lock_irqsave(&minfo->xfer_lock, flags);
clear_bit(xfer_id, minfo->xfer_alloc_table);
spin_unlock_irqrestore(&minfo->xfer_lock, flags);
up(&minfo->sem_xfer_count);
}
static inline int ti_sci_do_xfer(struct ti_sci_info *info,
struct ti_sci_xfer *xfer)
{
int ret;
int timeout;
struct device *dev = info->dev;
ret = mbox_send_message(info->chan_tx, &xfer->tx_message);
if (ret < 0)
return ret;
ret = 0;
timeout = msecs_to_jiffies(info->desc->max_rx_timeout_ms);
if (!wait_for_completion_timeout(&xfer->done, timeout)) {
dev_err(dev, "Mbox timedout in resp(caller: %pF)\n",
(void *)_RET_IP_);
ret = -ETIMEDOUT;
}
mbox_client_txdone(info->chan_tx, ret);
return ret;
}
static int ti_sci_cmd_get_revision(struct ti_sci_info *info)
{
struct device *dev = info->dev;
struct ti_sci_handle *handle = &info->handle;
struct ti_sci_version_info *ver = &handle->version;
struct ti_sci_msg_resp_version *rev_info;
struct ti_sci_xfer *xfer;
int ret;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_VERSION,
0x0, sizeof(struct ti_sci_msg_hdr),
sizeof(*rev_info));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
rev_info = (struct ti_sci_msg_resp_version *)xfer->xfer_buf;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
ver->abi_major = rev_info->abi_major;
ver->abi_minor = rev_info->abi_minor;
ver->firmware_revision = rev_info->firmware_revision;
strncpy(ver->firmware_description, rev_info->firmware_description,
sizeof(ver->firmware_description));
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static inline bool ti_sci_is_response_ack(void *r)
{
struct ti_sci_msg_hdr *hdr = r;
return hdr->flags & TI_SCI_FLAG_RESP_GENERIC_ACK ? true : false;
}
static int ti_sci_set_device_state(const struct ti_sci_handle *handle,
u32 id, u32 flags, u8 state)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_set_device_state *req;
struct ti_sci_msg_hdr *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_SET_DEVICE_STATE,
flags | TI_SCI_FLAG_REQ_ACK_ON_PROCESSED,
sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_set_device_state *)xfer->xfer_buf;
req->id = id;
req->state = state;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_hdr *)xfer->xfer_buf;
ret = ti_sci_is_response_ack(resp) ? 0 : -ENODEV;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static int ti_sci_get_device_state(const struct ti_sci_handle *handle,
u32 id, u32 *clcnt, u32 *resets,
u8 *p_state, u8 *c_state)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_get_device_state *req;
struct ti_sci_msg_resp_get_device_state *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle)
return -EINVAL;
if (!clcnt && !resets && !p_state && !c_state)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_GET_DEVICE_STATE,
0, sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_get_device_state *)xfer->xfer_buf;
req->id = id;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_resp_get_device_state *)xfer->xfer_buf;
if (!ti_sci_is_response_ack(resp)) {
ret = -ENODEV;
goto fail;
}
if (clcnt)
*clcnt = resp->context_loss_count;
if (resets)
*resets = resp->resets;
if (p_state)
*p_state = resp->programmed_state;
if (c_state)
*c_state = resp->current_state;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static int ti_sci_cmd_get_device(const struct ti_sci_handle *handle, u32 id)
{
return ti_sci_set_device_state(handle, id,
MSG_FLAG_DEVICE_EXCLUSIVE,
MSG_DEVICE_SW_STATE_ON);
}
static int ti_sci_cmd_idle_device(const struct ti_sci_handle *handle, u32 id)
{
return ti_sci_set_device_state(handle, id,
MSG_FLAG_DEVICE_EXCLUSIVE,
MSG_DEVICE_SW_STATE_RETENTION);
}
static int ti_sci_cmd_put_device(const struct ti_sci_handle *handle, u32 id)
{
return ti_sci_set_device_state(handle, id,
0, MSG_DEVICE_SW_STATE_AUTO_OFF);
}
static int ti_sci_cmd_dev_is_valid(const struct ti_sci_handle *handle, u32 id)
{
u8 unused;
return ti_sci_get_device_state(handle, id, NULL, NULL, NULL, &unused);
}
static int ti_sci_cmd_dev_get_clcnt(const struct ti_sci_handle *handle, u32 id,
u32 *count)
{
return ti_sci_get_device_state(handle, id, count, NULL, NULL, NULL);
}
static int ti_sci_cmd_dev_is_idle(const struct ti_sci_handle *handle, u32 id,
bool *r_state)
{
int ret;
u8 state;
if (!r_state)
return -EINVAL;
ret = ti_sci_get_device_state(handle, id, NULL, NULL, &state, NULL);
if (ret)
return ret;
*r_state = (state == MSG_DEVICE_SW_STATE_RETENTION);
return 0;
}
static int ti_sci_cmd_dev_is_stop(const struct ti_sci_handle *handle, u32 id,
bool *r_state, bool *curr_state)
{
int ret;
u8 p_state, c_state;
if (!r_state && !curr_state)
return -EINVAL;
ret =
ti_sci_get_device_state(handle, id, NULL, NULL, &p_state, &c_state);
if (ret)
return ret;
if (r_state)
*r_state = (p_state == MSG_DEVICE_SW_STATE_AUTO_OFF);
if (curr_state)
*curr_state = (c_state == MSG_DEVICE_HW_STATE_OFF);
return 0;
}
static int ti_sci_cmd_dev_is_on(const struct ti_sci_handle *handle, u32 id,
bool *r_state, bool *curr_state)
{
int ret;
u8 p_state, c_state;
if (!r_state && !curr_state)
return -EINVAL;
ret =
ti_sci_get_device_state(handle, id, NULL, NULL, &p_state, &c_state);
if (ret)
return ret;
if (r_state)
*r_state = (p_state == MSG_DEVICE_SW_STATE_ON);
if (curr_state)
*curr_state = (c_state == MSG_DEVICE_HW_STATE_ON);
return 0;
}
static int ti_sci_cmd_dev_is_trans(const struct ti_sci_handle *handle, u32 id,
bool *curr_state)
{
int ret;
u8 state;
if (!curr_state)
return -EINVAL;
ret = ti_sci_get_device_state(handle, id, NULL, NULL, NULL, &state);
if (ret)
return ret;
*curr_state = (state == MSG_DEVICE_HW_STATE_TRANS);
return 0;
}
static int ti_sci_cmd_set_device_resets(const struct ti_sci_handle *handle,
u32 id, u32 reset_state)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_set_device_resets *req;
struct ti_sci_msg_hdr *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_SET_DEVICE_RESETS,
TI_SCI_FLAG_REQ_ACK_ON_PROCESSED,
sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_set_device_resets *)xfer->xfer_buf;
req->id = id;
req->resets = reset_state;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_hdr *)xfer->xfer_buf;
ret = ti_sci_is_response_ack(resp) ? 0 : -ENODEV;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static int ti_sci_cmd_get_device_resets(const struct ti_sci_handle *handle,
u32 id, u32 *reset_state)
{
return ti_sci_get_device_state(handle, id, NULL, reset_state, NULL,
NULL);
}
static int ti_sci_set_clock_state(const struct ti_sci_handle *handle,
u32 dev_id, u8 clk_id,
u32 flags, u8 state)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_set_clock_state *req;
struct ti_sci_msg_hdr *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_SET_CLOCK_STATE,
flags | TI_SCI_FLAG_REQ_ACK_ON_PROCESSED,
sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_set_clock_state *)xfer->xfer_buf;
req->dev_id = dev_id;
req->clk_id = clk_id;
req->request_state = state;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_hdr *)xfer->xfer_buf;
ret = ti_sci_is_response_ack(resp) ? 0 : -ENODEV;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static int ti_sci_cmd_get_clock_state(const struct ti_sci_handle *handle,
u32 dev_id, u8 clk_id,
u8 *programmed_state, u8 *current_state)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_get_clock_state *req;
struct ti_sci_msg_resp_get_clock_state *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle)
return -EINVAL;
if (!programmed_state && !current_state)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_GET_CLOCK_STATE,
TI_SCI_FLAG_REQ_ACK_ON_PROCESSED,
sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_get_clock_state *)xfer->xfer_buf;
req->dev_id = dev_id;
req->clk_id = clk_id;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_resp_get_clock_state *)xfer->xfer_buf;
if (!ti_sci_is_response_ack(resp)) {
ret = -ENODEV;
goto fail;
}
if (programmed_state)
*programmed_state = resp->programmed_state;
if (current_state)
*current_state = resp->current_state;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static int ti_sci_cmd_get_clock(const struct ti_sci_handle *handle, u32 dev_id,
u8 clk_id, bool needs_ssc, bool can_change_freq,
bool enable_input_term)
{
u32 flags = 0;
flags |= needs_ssc ? MSG_FLAG_CLOCK_ALLOW_SSC : 0;
flags |= can_change_freq ? MSG_FLAG_CLOCK_ALLOW_FREQ_CHANGE : 0;
flags |= enable_input_term ? MSG_FLAG_CLOCK_INPUT_TERM : 0;
return ti_sci_set_clock_state(handle, dev_id, clk_id, flags,
MSG_CLOCK_SW_STATE_REQ);
}
static int ti_sci_cmd_idle_clock(const struct ti_sci_handle *handle,
u32 dev_id, u8 clk_id)
{
return ti_sci_set_clock_state(handle, dev_id, clk_id, 0,
MSG_CLOCK_SW_STATE_UNREQ);
}
static int ti_sci_cmd_put_clock(const struct ti_sci_handle *handle,
u32 dev_id, u8 clk_id)
{
return ti_sci_set_clock_state(handle, dev_id, clk_id, 0,
MSG_CLOCK_SW_STATE_AUTO);
}
static int ti_sci_cmd_clk_is_auto(const struct ti_sci_handle *handle,
u32 dev_id, u8 clk_id, bool *req_state)
{
u8 state = 0;
int ret;
if (!req_state)
return -EINVAL;
ret = ti_sci_cmd_get_clock_state(handle, dev_id, clk_id, &state, NULL);
if (ret)
return ret;
*req_state = (state == MSG_CLOCK_SW_STATE_AUTO);
return 0;
}
static int ti_sci_cmd_clk_is_on(const struct ti_sci_handle *handle, u32 dev_id,
u8 clk_id, bool *req_state, bool *curr_state)
{
u8 c_state = 0, r_state = 0;
int ret;
if (!req_state && !curr_state)
return -EINVAL;
ret = ti_sci_cmd_get_clock_state(handle, dev_id, clk_id,
&r_state, &c_state);
if (ret)
return ret;
if (req_state)
*req_state = (r_state == MSG_CLOCK_SW_STATE_REQ);
if (curr_state)
*curr_state = (c_state == MSG_CLOCK_HW_STATE_READY);
return 0;
}
static int ti_sci_cmd_clk_is_off(const struct ti_sci_handle *handle, u32 dev_id,
u8 clk_id, bool *req_state, bool *curr_state)
{
u8 c_state = 0, r_state = 0;
int ret;
if (!req_state && !curr_state)
return -EINVAL;
ret = ti_sci_cmd_get_clock_state(handle, dev_id, clk_id,
&r_state, &c_state);
if (ret)
return ret;
if (req_state)
*req_state = (r_state == MSG_CLOCK_SW_STATE_UNREQ);
if (curr_state)
*curr_state = (c_state == MSG_CLOCK_HW_STATE_NOT_READY);
return 0;
}
static int ti_sci_cmd_clk_set_parent(const struct ti_sci_handle *handle,
u32 dev_id, u8 clk_id, u8 parent_id)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_set_clock_parent *req;
struct ti_sci_msg_hdr *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_SET_CLOCK_PARENT,
TI_SCI_FLAG_REQ_ACK_ON_PROCESSED,
sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_set_clock_parent *)xfer->xfer_buf;
req->dev_id = dev_id;
req->clk_id = clk_id;
req->parent_id = parent_id;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_hdr *)xfer->xfer_buf;
ret = ti_sci_is_response_ack(resp) ? 0 : -ENODEV;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static int ti_sci_cmd_clk_get_parent(const struct ti_sci_handle *handle,
u32 dev_id, u8 clk_id, u8 *parent_id)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_get_clock_parent *req;
struct ti_sci_msg_resp_get_clock_parent *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle || !parent_id)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_GET_CLOCK_PARENT,
TI_SCI_FLAG_REQ_ACK_ON_PROCESSED,
sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_get_clock_parent *)xfer->xfer_buf;
req->dev_id = dev_id;
req->clk_id = clk_id;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_resp_get_clock_parent *)xfer->xfer_buf;
if (!ti_sci_is_response_ack(resp))
ret = -ENODEV;
else
*parent_id = resp->parent_id;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static int ti_sci_cmd_clk_get_num_parents(const struct ti_sci_handle *handle,
u32 dev_id, u8 clk_id,
u8 *num_parents)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_get_clock_num_parents *req;
struct ti_sci_msg_resp_get_clock_num_parents *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle || !num_parents)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_GET_NUM_CLOCK_PARENTS,
TI_SCI_FLAG_REQ_ACK_ON_PROCESSED,
sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_get_clock_num_parents *)xfer->xfer_buf;
req->dev_id = dev_id;
req->clk_id = clk_id;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_resp_get_clock_num_parents *)xfer->xfer_buf;
if (!ti_sci_is_response_ack(resp))
ret = -ENODEV;
else
*num_parents = resp->num_parents;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static int ti_sci_cmd_clk_get_match_freq(const struct ti_sci_handle *handle,
u32 dev_id, u8 clk_id, u64 min_freq,
u64 target_freq, u64 max_freq,
u64 *match_freq)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_query_clock_freq *req;
struct ti_sci_msg_resp_query_clock_freq *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle || !match_freq)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_QUERY_CLOCK_FREQ,
TI_SCI_FLAG_REQ_ACK_ON_PROCESSED,
sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_query_clock_freq *)xfer->xfer_buf;
req->dev_id = dev_id;
req->clk_id = clk_id;
req->min_freq_hz = min_freq;
req->target_freq_hz = target_freq;
req->max_freq_hz = max_freq;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_resp_query_clock_freq *)xfer->xfer_buf;
if (!ti_sci_is_response_ack(resp))
ret = -ENODEV;
else
*match_freq = resp->freq_hz;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static int ti_sci_cmd_clk_set_freq(const struct ti_sci_handle *handle,
u32 dev_id, u8 clk_id, u64 min_freq,
u64 target_freq, u64 max_freq)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_set_clock_freq *req;
struct ti_sci_msg_hdr *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_SET_CLOCK_FREQ,
TI_SCI_FLAG_REQ_ACK_ON_PROCESSED,
sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_set_clock_freq *)xfer->xfer_buf;
req->dev_id = dev_id;
req->clk_id = clk_id;
req->min_freq_hz = min_freq;
req->target_freq_hz = target_freq;
req->max_freq_hz = max_freq;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_hdr *)xfer->xfer_buf;
ret = ti_sci_is_response_ack(resp) ? 0 : -ENODEV;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static int ti_sci_cmd_clk_get_freq(const struct ti_sci_handle *handle,
u32 dev_id, u8 clk_id, u64 *freq)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_get_clock_freq *req;
struct ti_sci_msg_resp_get_clock_freq *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle || !freq)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_GET_CLOCK_FREQ,
TI_SCI_FLAG_REQ_ACK_ON_PROCESSED,
sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_get_clock_freq *)xfer->xfer_buf;
req->dev_id = dev_id;
req->clk_id = clk_id;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_resp_get_clock_freq *)xfer->xfer_buf;
if (!ti_sci_is_response_ack(resp))
ret = -ENODEV;
else
*freq = resp->freq_hz;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static int ti_sci_cmd_core_reboot(const struct ti_sci_handle *handle)
{
struct ti_sci_info *info;
struct ti_sci_msg_req_reboot *req;
struct ti_sci_msg_hdr *resp;
struct ti_sci_xfer *xfer;
struct device *dev;
int ret = 0;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
dev = info->dev;
xfer = ti_sci_get_one_xfer(info, TI_SCI_MSG_SYS_RESET,
TI_SCI_FLAG_REQ_ACK_ON_PROCESSED,
sizeof(*req), sizeof(*resp));
if (IS_ERR(xfer)) {
ret = PTR_ERR(xfer);
dev_err(dev, "Message alloc failed(%d)\n", ret);
return ret;
}
req = (struct ti_sci_msg_req_reboot *)xfer->xfer_buf;
ret = ti_sci_do_xfer(info, xfer);
if (ret) {
dev_err(dev, "Mbox send fail %d\n", ret);
goto fail;
}
resp = (struct ti_sci_msg_hdr *)xfer->xfer_buf;
if (!ti_sci_is_response_ack(resp))
ret = -ENODEV;
else
ret = 0;
fail:
ti_sci_put_one_xfer(&info->minfo, xfer);
return ret;
}
static void ti_sci_setup_ops(struct ti_sci_info *info)
{
struct ti_sci_ops *ops = &info->handle.ops;
struct ti_sci_core_ops *core_ops = &ops->core_ops;
struct ti_sci_dev_ops *dops = &ops->dev_ops;
struct ti_sci_clk_ops *cops = &ops->clk_ops;
core_ops->reboot_device = ti_sci_cmd_core_reboot;
dops->get_device = ti_sci_cmd_get_device;
dops->idle_device = ti_sci_cmd_idle_device;
dops->put_device = ti_sci_cmd_put_device;
dops->is_valid = ti_sci_cmd_dev_is_valid;
dops->get_context_loss_count = ti_sci_cmd_dev_get_clcnt;
dops->is_idle = ti_sci_cmd_dev_is_idle;
dops->is_stop = ti_sci_cmd_dev_is_stop;
dops->is_on = ti_sci_cmd_dev_is_on;
dops->is_transitioning = ti_sci_cmd_dev_is_trans;
dops->set_device_resets = ti_sci_cmd_set_device_resets;
dops->get_device_resets = ti_sci_cmd_get_device_resets;
cops->get_clock = ti_sci_cmd_get_clock;
cops->idle_clock = ti_sci_cmd_idle_clock;
cops->put_clock = ti_sci_cmd_put_clock;
cops->is_auto = ti_sci_cmd_clk_is_auto;
cops->is_on = ti_sci_cmd_clk_is_on;
cops->is_off = ti_sci_cmd_clk_is_off;
cops->set_parent = ti_sci_cmd_clk_set_parent;
cops->get_parent = ti_sci_cmd_clk_get_parent;
cops->get_num_parents = ti_sci_cmd_clk_get_num_parents;
cops->get_best_match_freq = ti_sci_cmd_clk_get_match_freq;
cops->set_freq = ti_sci_cmd_clk_set_freq;
cops->get_freq = ti_sci_cmd_clk_get_freq;
}
const struct ti_sci_handle *ti_sci_get_handle(struct device *dev)
{
struct device_node *ti_sci_np;
struct list_head *p;
struct ti_sci_handle *handle = NULL;
struct ti_sci_info *info;
if (!dev) {
pr_err("I need a device pointer\n");
return ERR_PTR(-EINVAL);
}
ti_sci_np = of_get_parent(dev->of_node);
if (!ti_sci_np) {
dev_err(dev, "No OF information\n");
return ERR_PTR(-EINVAL);
}
mutex_lock(&ti_sci_list_mutex);
list_for_each(p, &ti_sci_list) {
info = list_entry(p, struct ti_sci_info, node);
if (ti_sci_np == info->dev->of_node) {
handle = &info->handle;
info->users++;
break;
}
}
mutex_unlock(&ti_sci_list_mutex);
of_node_put(ti_sci_np);
if (!handle)
return ERR_PTR(-EPROBE_DEFER);
return handle;
}
int ti_sci_put_handle(const struct ti_sci_handle *handle)
{
struct ti_sci_info *info;
if (IS_ERR(handle))
return PTR_ERR(handle);
if (!handle)
return -EINVAL;
info = handle_to_ti_sci_info(handle);
mutex_lock(&ti_sci_list_mutex);
if (!WARN_ON(!info->users))
info->users--;
mutex_unlock(&ti_sci_list_mutex);
return 0;
}
static void devm_ti_sci_release(struct device *dev, void *res)
{
const struct ti_sci_handle **ptr = res;
const struct ti_sci_handle *handle = *ptr;
int ret;
ret = ti_sci_put_handle(handle);
if (ret)
dev_err(dev, "failed to put handle %d\n", ret);
}
const struct ti_sci_handle *devm_ti_sci_get_handle(struct device *dev)
{
const struct ti_sci_handle **ptr;
const struct ti_sci_handle *handle;
ptr = devres_alloc(devm_ti_sci_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
handle = ti_sci_get_handle(dev);
if (!IS_ERR(handle)) {
*ptr = handle;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return handle;
}
static int tisci_reboot_handler(struct notifier_block *nb, unsigned long mode,
void *cmd)
{
struct ti_sci_info *info = reboot_to_ti_sci_info(nb);
const struct ti_sci_handle *handle = &info->handle;
ti_sci_cmd_core_reboot(handle);
return NOTIFY_BAD;
}
static int ti_sci_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *of_id;
const struct ti_sci_desc *desc;
struct ti_sci_xfer *xfer;
struct ti_sci_info *info = NULL;
struct ti_sci_xfers_info *minfo;
struct mbox_client *cl;
int ret = -EINVAL;
int i;
int reboot = 0;
of_id = of_match_device(ti_sci_of_match, dev);
if (!of_id) {
dev_err(dev, "OF data missing\n");
return -EINVAL;
}
desc = of_id->data;
info = devm_kzalloc(dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->dev = dev;
info->desc = desc;
reboot = of_property_read_bool(dev->of_node,
"ti,system-reboot-controller");
INIT_LIST_HEAD(&info->node);
minfo = &info->minfo;
if (WARN_ON(desc->max_msgs >=
1 << 8 * sizeof(((struct ti_sci_msg_hdr *)0)->seq)))
return -EINVAL;
minfo->xfer_block = devm_kcalloc(dev,
desc->max_msgs,
sizeof(*minfo->xfer_block),
GFP_KERNEL);
if (!minfo->xfer_block)
return -ENOMEM;
minfo->xfer_alloc_table = devm_kzalloc(dev,
BITS_TO_LONGS(desc->max_msgs)
* sizeof(unsigned long),
GFP_KERNEL);
if (!minfo->xfer_alloc_table)
return -ENOMEM;
bitmap_zero(minfo->xfer_alloc_table, desc->max_msgs);
for (i = 0, xfer = minfo->xfer_block; i < desc->max_msgs; i++, xfer++) {
xfer->xfer_buf = devm_kcalloc(dev, 1, desc->max_msg_size,
GFP_KERNEL);
if (!xfer->xfer_buf)
return -ENOMEM;
xfer->tx_message.buf = xfer->xfer_buf;
init_completion(&xfer->done);
}
ret = ti_sci_debugfs_create(pdev, info);
if (ret)
dev_warn(dev, "Failed to create debug file\n");
platform_set_drvdata(pdev, info);
cl = &info->cl;
cl->dev = dev;
cl->tx_block = false;
cl->rx_callback = ti_sci_rx_callback;
cl->knows_txdone = true;
spin_lock_init(&minfo->xfer_lock);
sema_init(&minfo->sem_xfer_count, desc->max_msgs);
info->chan_rx = mbox_request_channel_byname(cl, "rx");
if (IS_ERR(info->chan_rx)) {
ret = PTR_ERR(info->chan_rx);
goto out;
}
info->chan_tx = mbox_request_channel_byname(cl, "tx");
if (IS_ERR(info->chan_tx)) {
ret = PTR_ERR(info->chan_tx);
goto out;
}
ret = ti_sci_cmd_get_revision(info);
if (ret) {
dev_err(dev, "Unable to communicate with TISCI(%d)\n", ret);
goto out;
}
ti_sci_setup_ops(info);
if (reboot) {
info->nb.notifier_call = tisci_reboot_handler;
info->nb.priority = 128;
ret = register_restart_handler(&info->nb);
if (ret) {
dev_err(dev, "reboot registration fail(%d)\n", ret);
return ret;
}
}
dev_info(dev, "ABI: %d.%d (firmware rev 0x%04x '%s')\n",
info->handle.version.abi_major, info->handle.version.abi_minor,
info->handle.version.firmware_revision,
info->handle.version.firmware_description);
mutex_lock(&ti_sci_list_mutex);
list_add_tail(&info->node, &ti_sci_list);
mutex_unlock(&ti_sci_list_mutex);
return of_platform_populate(dev->of_node, NULL, NULL, dev);
out:
if (!IS_ERR(info->chan_tx))
mbox_free_channel(info->chan_tx);
if (!IS_ERR(info->chan_rx))
mbox_free_channel(info->chan_rx);
debugfs_remove(info->d);
return ret;
}
static int ti_sci_remove(struct platform_device *pdev)
{
struct ti_sci_info *info;
struct device *dev = &pdev->dev;
int ret = 0;
of_platform_depopulate(dev);
info = platform_get_drvdata(pdev);
if (info->nb.notifier_call)
unregister_restart_handler(&info->nb);
mutex_lock(&ti_sci_list_mutex);
if (info->users)
ret = -EBUSY;
else
list_del(&info->node);
mutex_unlock(&ti_sci_list_mutex);
if (!ret) {
ti_sci_debugfs_destroy(pdev, info);
mbox_free_channel(info->chan_tx);
mbox_free_channel(info->chan_rx);
}
return ret;
}
