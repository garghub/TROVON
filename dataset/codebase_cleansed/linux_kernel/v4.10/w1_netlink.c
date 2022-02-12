static u16 w1_reply_len(struct w1_cb_block *block)
{
if (!block->cn)
return 0;
return (u8 *)block->cn - (u8 *)block->first_cn + block->cn->len;
}
static void w1_unref_block(struct w1_cb_block *block)
{
if (atomic_sub_return(1, &block->refcnt) == 0) {
u16 len = w1_reply_len(block);
if (len) {
cn_netlink_send_mult(block->first_cn, len,
block->portid, 0, GFP_KERNEL);
}
kfree(block);
}
}
static void w1_reply_make_space(struct w1_cb_block *block, u16 space)
{
u16 len = w1_reply_len(block);
if (len + space >= block->maxlen) {
cn_netlink_send_mult(block->first_cn, len, block->portid, 0, GFP_KERNEL);
block->first_cn->len = 0;
block->cn = NULL;
block->msg = NULL;
block->cmd = NULL;
}
}
static void w1_netlink_check_send(struct w1_cb_block *block)
{
if (!(block->request_cn.flags & W1_CN_BUNDLE) && block->cn)
w1_reply_make_space(block, block->maxlen);
}
static void w1_netlink_setup_msg(struct w1_cb_block *block, u32 ack)
{
if (block->cn && block->cn->ack == ack) {
block->msg = (struct w1_netlink_msg *)(block->cn->data + block->cn->len);
} else {
if (block->cn)
block->cn = (struct cn_msg *)(block->cn->data +
block->cn->len);
else
block->cn = block->first_cn;
memcpy(block->cn, &block->request_cn, sizeof(*block->cn));
block->cn->len = 0;
block->cn->ack = ack;
block->msg = (struct w1_netlink_msg *)block->cn->data;
}
}
static void w1_netlink_queue_cmd(struct w1_cb_block *block,
struct w1_netlink_cmd *cmd)
{
u32 space;
w1_reply_make_space(block, sizeof(struct cn_msg) +
sizeof(struct w1_netlink_msg) + sizeof(*cmd) + cmd->len);
w1_netlink_setup_msg(block, block->request_cn.seq + 1);
memcpy(block->msg, block->cur_msg, sizeof(*block->msg));
block->cn->len += sizeof(*block->msg);
block->msg->len = 0;
block->cmd = (struct w1_netlink_cmd *)(block->msg->data);
space = sizeof(*cmd) + cmd->len;
if (block->cmd != cmd)
memcpy(block->cmd, cmd, space);
block->cn->len += space;
block->msg->len += space;
}
static void w1_netlink_queue_status(struct w1_cb_block *block,
struct w1_netlink_msg *req_msg, struct w1_netlink_cmd *req_cmd,
int error)
{
u16 space = sizeof(struct cn_msg) + sizeof(*req_msg) + sizeof(*req_cmd);
w1_reply_make_space(block, space);
w1_netlink_setup_msg(block, block->request_cn.ack);
memcpy(block->msg, req_msg, sizeof(*req_msg));
block->cn->len += sizeof(*req_msg);
block->msg->len = 0;
block->msg->status = (u8)-error;
if (req_cmd) {
struct w1_netlink_cmd *cmd = (struct w1_netlink_cmd *)block->msg->data;
memcpy(cmd, req_cmd, sizeof(*cmd));
block->cn->len += sizeof(*cmd);
block->msg->len += sizeof(*cmd);
cmd->len = 0;
}
w1_netlink_check_send(block);
}
static void w1_netlink_send_error(struct cn_msg *cn, struct w1_netlink_msg *msg,
int portid, int error)
{
struct {
struct cn_msg cn;
struct w1_netlink_msg msg;
} packet;
memcpy(&packet.cn, cn, sizeof(packet.cn));
memcpy(&packet.msg, msg, sizeof(packet.msg));
packet.cn.len = sizeof(packet.msg);
packet.msg.len = 0;
packet.msg.status = (u8)-error;
cn_netlink_send(&packet.cn, portid, 0, GFP_KERNEL);
}
void w1_netlink_send(struct w1_master *dev, struct w1_netlink_msg *msg)
{
struct {
struct cn_msg cn;
struct w1_netlink_msg msg;
} packet;
memset(&packet, 0, sizeof(packet));
packet.cn.id.idx = CN_W1_IDX;
packet.cn.id.val = CN_W1_VAL;
packet.cn.seq = dev->seq++;
packet.cn.len = sizeof(*msg);
memcpy(&packet.msg, msg, sizeof(*msg));
packet.msg.len = 0;
cn_netlink_send(&packet.cn, 0, 0, GFP_KERNEL);
}
static void w1_send_slave(struct w1_master *dev, u64 rn)
{
struct w1_cb_block *block = dev->priv;
struct w1_netlink_cmd *cache_cmd = block->cmd;
u64 *data;
w1_reply_make_space(block, sizeof(*data));
if (!block->cmd) {
cache_cmd->len = 0;
w1_netlink_queue_cmd(block, cache_cmd);
}
data = (u64 *)(block->cmd->data + block->cmd->len);
*data = rn;
block->cn->len += sizeof(*data);
block->msg->len += sizeof(*data);
block->cmd->len += sizeof(*data);
}
static void w1_found_send_slave(struct w1_master *dev, u64 rn)
{
w1_slave_found(dev, rn);
w1_send_slave(dev, rn);
}
static int w1_get_slaves(struct w1_master *dev, struct w1_netlink_cmd *req_cmd)
{
struct w1_slave *sl;
req_cmd->len = 0;
w1_netlink_queue_cmd(dev->priv, req_cmd);
if (req_cmd->cmd == W1_CMD_LIST_SLAVES) {
u64 rn;
mutex_lock(&dev->list_mutex);
list_for_each_entry(sl, &dev->slist, w1_slave_entry) {
memcpy(&rn, &sl->reg_num, sizeof(rn));
w1_send_slave(dev, rn);
}
mutex_unlock(&dev->list_mutex);
} else {
w1_search_process_cb(dev, req_cmd->cmd == W1_CMD_ALARM_SEARCH ?
W1_ALARM_SEARCH : W1_SEARCH, w1_found_send_slave);
}
return 0;
}
static int w1_process_command_io(struct w1_master *dev,
struct w1_netlink_cmd *cmd)
{
int err = 0;
switch (cmd->cmd) {
case W1_CMD_TOUCH:
w1_touch_block(dev, cmd->data, cmd->len);
w1_netlink_queue_cmd(dev->priv, cmd);
break;
case W1_CMD_READ:
w1_read_block(dev, cmd->data, cmd->len);
w1_netlink_queue_cmd(dev->priv, cmd);
break;
case W1_CMD_WRITE:
w1_write_block(dev, cmd->data, cmd->len);
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int w1_process_command_addremove(struct w1_master *dev,
struct w1_netlink_cmd *cmd)
{
struct w1_slave *sl;
int err = 0;
struct w1_reg_num *id;
if (cmd->len != sizeof(*id))
return -EINVAL;
id = (struct w1_reg_num *)cmd->data;
sl = w1_slave_search_device(dev, id);
switch (cmd->cmd) {
case W1_CMD_SLAVE_ADD:
if (sl)
err = -EINVAL;
else
err = w1_attach_slave_device(dev, id);
break;
case W1_CMD_SLAVE_REMOVE:
if (sl)
w1_slave_detach(sl);
else
err = -EINVAL;
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int w1_process_command_master(struct w1_master *dev,
struct w1_netlink_cmd *req_cmd)
{
int err = -EINVAL;
switch (req_cmd->cmd) {
case W1_CMD_SEARCH:
case W1_CMD_ALARM_SEARCH:
case W1_CMD_LIST_SLAVES:
mutex_unlock(&dev->bus_mutex);
err = w1_get_slaves(dev, req_cmd);
mutex_lock(&dev->bus_mutex);
break;
case W1_CMD_READ:
case W1_CMD_WRITE:
case W1_CMD_TOUCH:
err = w1_process_command_io(dev, req_cmd);
break;
case W1_CMD_RESET:
err = w1_reset_bus(dev);
break;
case W1_CMD_SLAVE_ADD:
case W1_CMD_SLAVE_REMOVE:
mutex_unlock(&dev->bus_mutex);
mutex_lock(&dev->mutex);
err = w1_process_command_addremove(dev, req_cmd);
mutex_unlock(&dev->mutex);
mutex_lock(&dev->bus_mutex);
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int w1_process_command_slave(struct w1_slave *sl,
struct w1_netlink_cmd *cmd)
{
dev_dbg(&sl->master->dev, "%s: %02x.%012llx.%02x: cmd=%02x, len=%u.\n",
__func__, sl->reg_num.family, (unsigned long long)sl->reg_num.id,
sl->reg_num.crc, cmd->cmd, cmd->len);
return w1_process_command_io(sl->master, cmd);
}
static int w1_process_command_root(struct cn_msg *req_cn, u32 portid)
{
struct w1_master *dev;
struct cn_msg *cn;
struct w1_netlink_msg *msg;
u32 *id;
cn = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!cn)
return -ENOMEM;
cn->id.idx = CN_W1_IDX;
cn->id.val = CN_W1_VAL;
cn->seq = req_cn->seq;
cn->ack = req_cn->seq + 1;
cn->len = sizeof(struct w1_netlink_msg);
msg = (struct w1_netlink_msg *)cn->data;
msg->type = W1_LIST_MASTERS;
msg->status = 0;
msg->len = 0;
id = (u32 *)msg->data;
mutex_lock(&w1_mlock);
list_for_each_entry(dev, &w1_masters, w1_master_entry) {
if (cn->len + sizeof(*id) > PAGE_SIZE - sizeof(struct cn_msg)) {
cn_netlink_send(cn, portid, 0, GFP_KERNEL);
cn->len = sizeof(struct w1_netlink_msg);
msg->len = 0;
id = (u32 *)msg->data;
}
*id = dev->id;
msg->len += sizeof(*id);
cn->len += sizeof(*id);
id++;
}
cn_netlink_send(cn, portid, 0, GFP_KERNEL);
mutex_unlock(&w1_mlock);
kfree(cn);
return 0;
}
static void w1_process_cb(struct w1_master *dev, struct w1_async_cmd *async_cmd)
{
struct w1_cb_node *node = container_of(async_cmd, struct w1_cb_node,
async);
u16 mlen = node->msg->len;
u16 len;
int err = 0;
struct w1_slave *sl = node->sl;
struct w1_netlink_cmd *cmd = (struct w1_netlink_cmd *)node->msg->data;
mutex_lock(&dev->bus_mutex);
dev->priv = node->block;
if (sl && w1_reset_select_slave(sl))
err = -ENODEV;
node->block->cur_msg = node->msg;
while (mlen && !err) {
if (cmd->len + sizeof(struct w1_netlink_cmd) > mlen) {
err = -E2BIG;
break;
}
if (sl)
err = w1_process_command_slave(sl, cmd);
else
err = w1_process_command_master(dev, cmd);
w1_netlink_check_send(node->block);
w1_netlink_queue_status(node->block, node->msg, cmd, err);
err = 0;
len = sizeof(*cmd) + cmd->len;
cmd = (struct w1_netlink_cmd *)((u8 *)cmd + len);
mlen -= len;
}
if (!cmd || err)
w1_netlink_queue_status(node->block, node->msg, cmd, err);
if (sl)
w1_unref_slave(sl);
else
atomic_dec(&dev->refcnt);
dev->priv = NULL;
mutex_unlock(&dev->bus_mutex);
mutex_lock(&dev->list_mutex);
list_del(&async_cmd->async_entry);
mutex_unlock(&dev->list_mutex);
w1_unref_block(node->block);
}
static void w1_list_count_cmds(struct w1_netlink_msg *msg, int *cmd_count,
u16 *slave_len)
{
struct w1_netlink_cmd *cmd = (struct w1_netlink_cmd *)msg->data;
u16 mlen = msg->len;
u16 len;
int slave_list = 0;
while (mlen) {
if (cmd->len + sizeof(struct w1_netlink_cmd) > mlen)
break;
switch (cmd->cmd) {
case W1_CMD_SEARCH:
case W1_CMD_ALARM_SEARCH:
case W1_CMD_LIST_SLAVES:
++slave_list;
}
++*cmd_count;
len = sizeof(*cmd) + cmd->len;
cmd = (struct w1_netlink_cmd *)((u8 *)cmd + len);
mlen -= len;
}
if (slave_list) {
struct w1_master *dev = w1_search_master_id(msg->id.mst.id);
if (dev) {
*slave_len += sizeof(struct w1_reg_num) * slave_list *
(dev->slave_count + dev->max_slave_count);
atomic_dec(&dev->refcnt);
}
}
}
static void w1_cn_callback(struct cn_msg *cn, struct netlink_skb_parms *nsp)
{
struct w1_netlink_msg *msg = (struct w1_netlink_msg *)(cn + 1);
struct w1_slave *sl;
struct w1_master *dev;
u16 msg_len;
u16 slave_len = 0;
int err = 0;
struct w1_cb_block *block = NULL;
struct w1_cb_node *node = NULL;
int node_count = 0;
int cmd_count = 0;
if (cn->flags & ~(W1_CN_BUNDLE)) {
w1_netlink_send_error(cn, msg, nsp->portid, -EINVAL);
return;
}
msg_len = cn->len;
while (msg_len && !err) {
if (msg->len + sizeof(struct w1_netlink_msg) > msg_len) {
err = -E2BIG;
break;
}
if (msg->type == W1_MASTER_CMD || msg->type == W1_SLAVE_CMD) {
++node_count;
w1_list_count_cmds(msg, &cmd_count, &slave_len);
}
msg_len -= sizeof(struct w1_netlink_msg) + msg->len;
msg = (struct w1_netlink_msg *)(((u8 *)msg) +
sizeof(struct w1_netlink_msg) + msg->len);
}
msg = (struct w1_netlink_msg *)(cn + 1);
if (node_count) {
int size;
int reply_size = sizeof(*cn) + cn->len + slave_len;
if (cn->flags & W1_CN_BUNDLE) {
reply_size += 2 * cmd_count * (sizeof(struct cn_msg) +
sizeof(struct w1_netlink_msg) +
sizeof(struct w1_netlink_cmd));
}
reply_size = MIN(CONNECTOR_MAX_MSG_SIZE, reply_size);
size =
sizeof(struct w1_cb_block) + sizeof(*cn) + cn->len +
node_count * sizeof(struct w1_cb_node) +
sizeof(struct cn_msg) + reply_size;
block = kzalloc(size, GFP_KERNEL);
if (!block) {
w1_netlink_send_error(cn, msg, nsp->portid, -ENOMEM);
return;
}
atomic_set(&block->refcnt, 1);
block->portid = nsp->portid;
memcpy(&block->request_cn, cn, sizeof(*cn) + cn->len);
node = (struct w1_cb_node *)(block->request_cn.data + cn->len);
block->maxlen = reply_size;
block->first_cn = (struct cn_msg *)(node + node_count);
memset(block->first_cn, 0, sizeof(*block->first_cn));
}
msg_len = cn->len;
while (msg_len && !err) {
dev = NULL;
sl = NULL;
if (msg->len + sizeof(struct w1_netlink_msg) > msg_len) {
err = -E2BIG;
break;
}
if (msg->type == W1_LIST_MASTERS) {
err = w1_process_command_root(cn, nsp->portid);
goto out_cont;
}
if (!msg->len) {
err = -EPROTO;
goto out_cont;
}
if (msg->type == W1_MASTER_CMD) {
dev = w1_search_master_id(msg->id.mst.id);
} else if (msg->type == W1_SLAVE_CMD) {
sl = w1_search_slave((struct w1_reg_num *)msg->id.id);
if (sl)
dev = sl->master;
} else {
pr_notice("%s: cn: %x.%x, wrong type: %u, len: %u.\n",
__func__, cn->id.idx, cn->id.val,
msg->type, msg->len);
err = -EPROTO;
goto out_cont;
}
if (!dev) {
err = -ENODEV;
goto out_cont;
}
err = 0;
atomic_inc(&block->refcnt);
node->async.cb = w1_process_cb;
node->block = block;
node->msg = (struct w1_netlink_msg *)((u8 *)&block->request_cn +
(size_t)((u8 *)msg - (u8 *)cn));
node->sl = sl;
node->dev = dev;
mutex_lock(&dev->list_mutex);
list_add_tail(&node->async.async_entry, &dev->async_list);
wake_up_process(dev->thread);
mutex_unlock(&dev->list_mutex);
++node;
out_cont:
if (err)
w1_netlink_send_error(cn, msg, nsp->portid, err);
msg_len -= sizeof(struct w1_netlink_msg) + msg->len;
msg = (struct w1_netlink_msg *)(((u8 *)msg) +
sizeof(struct w1_netlink_msg) + msg->len);
if (err == -ENODEV)
err = 0;
}
if (block)
w1_unref_block(block);
}
int w1_init_netlink(void)
{
struct cb_id w1_id = {.idx = CN_W1_IDX, .val = CN_W1_VAL};
return cn_add_callback(&w1_id, "w1", &w1_cn_callback);
}
void w1_fini_netlink(void)
{
struct cb_id w1_id = {.idx = CN_W1_IDX, .val = CN_W1_VAL};
cn_del_callback(&w1_id);
}
void w1_netlink_send(struct w1_master *dev, struct w1_netlink_msg *cn)
{
}
int w1_init_netlink(void)
{
return 0;
}
void w1_fini_netlink(void)
{
}
