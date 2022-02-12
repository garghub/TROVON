static int mlx4_status_to_errno(u8 status)
{
static const int trans_table[] = {
[CMD_STAT_INTERNAL_ERR] = -EIO,
[CMD_STAT_BAD_OP] = -EPERM,
[CMD_STAT_BAD_PARAM] = -EINVAL,
[CMD_STAT_BAD_SYS_STATE] = -ENXIO,
[CMD_STAT_BAD_RESOURCE] = -EBADF,
[CMD_STAT_RESOURCE_BUSY] = -EBUSY,
[CMD_STAT_EXCEED_LIM] = -ENOMEM,
[CMD_STAT_BAD_RES_STATE] = -EBADF,
[CMD_STAT_BAD_INDEX] = -EBADF,
[CMD_STAT_BAD_NVMEM] = -EFAULT,
[CMD_STAT_ICM_ERROR] = -ENFILE,
[CMD_STAT_BAD_QP_STATE] = -EINVAL,
[CMD_STAT_BAD_SEG_PARAM] = -EFAULT,
[CMD_STAT_REG_BOUND] = -EBUSY,
[CMD_STAT_LAM_NOT_PRE] = -EAGAIN,
[CMD_STAT_BAD_PKT] = -EINVAL,
[CMD_STAT_BAD_SIZE] = -ENOMEM,
[CMD_STAT_MULTI_FUNC_REQ] = -EACCES,
};
if (status >= ARRAY_SIZE(trans_table) ||
(status != CMD_STAT_OK && trans_table[status] == 0))
return -EIO;
return trans_table[status];
}
static u8 mlx4_errno_to_status(int errno)
{
switch (errno) {
case -EPERM:
return CMD_STAT_BAD_OP;
case -EINVAL:
return CMD_STAT_BAD_PARAM;
case -ENXIO:
return CMD_STAT_BAD_SYS_STATE;
case -EBUSY:
return CMD_STAT_RESOURCE_BUSY;
case -ENOMEM:
return CMD_STAT_EXCEED_LIM;
case -ENFILE:
return CMD_STAT_ICM_ERROR;
default:
return CMD_STAT_INTERNAL_ERR;
}
}
static int comm_pending(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
u32 status = readl(&priv->mfunc.comm->slave_read);
return (swab32(status) >> 31) != priv->cmd.comm_toggle;
}
static void mlx4_comm_cmd_post(struct mlx4_dev *dev, u8 cmd, u16 param)
{
struct mlx4_priv *priv = mlx4_priv(dev);
u32 val;
priv->cmd.comm_toggle ^= 1;
val = param | (cmd << 16) | (priv->cmd.comm_toggle << 31);
__raw_writel((__force u32) cpu_to_be32(val),
&priv->mfunc.comm->slave_write);
mmiowb();
}
static int mlx4_comm_cmd_poll(struct mlx4_dev *dev, u8 cmd, u16 param,
unsigned long timeout)
{
struct mlx4_priv *priv = mlx4_priv(dev);
unsigned long end;
int err = 0;
int ret_from_pending = 0;
if (comm_pending(dev)) {
mlx4_warn(dev, "Communication channel is not idle."
"my toggle is %d (cmd:0x%x)\n",
priv->cmd.comm_toggle, cmd);
return -EAGAIN;
}
down(&priv->cmd.poll_sem);
mlx4_comm_cmd_post(dev, cmd, param);
end = msecs_to_jiffies(timeout) + jiffies;
while (comm_pending(dev) && time_before(jiffies, end))
cond_resched();
ret_from_pending = comm_pending(dev);
if (ret_from_pending) {
if ((MLX4_COMM_CMD_RESET == cmd)) {
err = MLX4_DELAY_RESET_SLAVE;
} else {
mlx4_warn(dev, "Communication channel timed out\n");
err = -ETIMEDOUT;
}
}
up(&priv->cmd.poll_sem);
return err;
}
static int mlx4_comm_cmd_wait(struct mlx4_dev *dev, u8 op,
u16 param, unsigned long timeout)
{
struct mlx4_cmd *cmd = &mlx4_priv(dev)->cmd;
struct mlx4_cmd_context *context;
unsigned long end;
int err = 0;
down(&cmd->event_sem);
spin_lock(&cmd->context_lock);
BUG_ON(cmd->free_head < 0);
context = &cmd->context[cmd->free_head];
context->token += cmd->token_mask + 1;
cmd->free_head = context->next;
spin_unlock(&cmd->context_lock);
init_completion(&context->done);
mlx4_comm_cmd_post(dev, op, param);
if (!wait_for_completion_timeout(&context->done,
msecs_to_jiffies(timeout))) {
mlx4_warn(dev, "communication channel command 0x%x timed out\n",
op);
err = -EBUSY;
goto out;
}
err = context->result;
if (err && context->fw_status != CMD_STAT_MULTI_FUNC_REQ) {
mlx4_err(dev, "command 0x%x failed: fw status = 0x%x\n",
op, context->fw_status);
goto out;
}
out:
end = msecs_to_jiffies(timeout) + jiffies;
while (comm_pending(dev) && time_before(jiffies, end))
cond_resched();
spin_lock(&cmd->context_lock);
context->next = cmd->free_head;
cmd->free_head = context - cmd->context;
spin_unlock(&cmd->context_lock);
up(&cmd->event_sem);
return err;
}
int mlx4_comm_cmd(struct mlx4_dev *dev, u8 cmd, u16 param,
unsigned long timeout)
{
if (mlx4_priv(dev)->cmd.use_events)
return mlx4_comm_cmd_wait(dev, cmd, param, timeout);
return mlx4_comm_cmd_poll(dev, cmd, param, timeout);
}
static int cmd_pending(struct mlx4_dev *dev)
{
u32 status;
if (pci_channel_offline(dev->pdev))
return -EIO;
status = readl(mlx4_priv(dev)->cmd.hcr + HCR_STATUS_OFFSET);
return (status & swab32(1 << HCR_GO_BIT)) ||
(mlx4_priv(dev)->cmd.toggle ==
!!(status & swab32(1 << HCR_T_BIT)));
}
static int mlx4_cmd_post(struct mlx4_dev *dev, u64 in_param, u64 out_param,
u32 in_modifier, u8 op_modifier, u16 op, u16 token,
int event)
{
struct mlx4_cmd *cmd = &mlx4_priv(dev)->cmd;
u32 __iomem *hcr = cmd->hcr;
int ret = -EAGAIN;
unsigned long end;
mutex_lock(&cmd->hcr_mutex);
if (pci_channel_offline(dev->pdev)) {
ret = -EIO;
goto out;
}
end = jiffies;
if (event)
end += msecs_to_jiffies(GO_BIT_TIMEOUT_MSECS);
while (cmd_pending(dev)) {
if (pci_channel_offline(dev->pdev)) {
ret = -EIO;
goto out;
}
if (time_after_eq(jiffies, end)) {
mlx4_err(dev, "%s:cmd_pending failed\n", __func__);
goto out;
}
cond_resched();
}
__raw_writel((__force u32) cpu_to_be32(in_param >> 32), hcr + 0);
__raw_writel((__force u32) cpu_to_be32(in_param & 0xfffffffful), hcr + 1);
__raw_writel((__force u32) cpu_to_be32(in_modifier), hcr + 2);
__raw_writel((__force u32) cpu_to_be32(out_param >> 32), hcr + 3);
__raw_writel((__force u32) cpu_to_be32(out_param & 0xfffffffful), hcr + 4);
__raw_writel((__force u32) cpu_to_be32(token << 16), hcr + 5);
wmb();
__raw_writel((__force u32) cpu_to_be32((1 << HCR_GO_BIT) |
(cmd->toggle << HCR_T_BIT) |
(event ? (1 << HCR_E_BIT) : 0) |
(op_modifier << HCR_OPMOD_SHIFT) |
op), hcr + 6);
mmiowb();
cmd->toggle = cmd->toggle ^ 1;
ret = 0;
out:
mutex_unlock(&cmd->hcr_mutex);
return ret;
}
static int mlx4_slave_cmd(struct mlx4_dev *dev, u64 in_param, u64 *out_param,
int out_is_imm, u32 in_modifier, u8 op_modifier,
u16 op, unsigned long timeout)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_vhcr_cmd *vhcr = priv->mfunc.vhcr;
int ret;
mutex_lock(&priv->cmd.slave_cmd_mutex);
vhcr->in_param = cpu_to_be64(in_param);
vhcr->out_param = out_param ? cpu_to_be64(*out_param) : 0;
vhcr->in_modifier = cpu_to_be32(in_modifier);
vhcr->opcode = cpu_to_be16((((u16) op_modifier) << 12) | (op & 0xfff));
vhcr->token = cpu_to_be16(CMD_POLL_TOKEN);
vhcr->status = 0;
vhcr->flags = !!(priv->cmd.use_events) << 6;
if (mlx4_is_master(dev)) {
ret = mlx4_master_process_vhcr(dev, dev->caps.function, vhcr);
if (!ret) {
if (out_is_imm) {
if (out_param)
*out_param =
be64_to_cpu(vhcr->out_param);
else {
mlx4_err(dev, "response expected while"
"output mailbox is NULL for "
"command 0x%x\n", op);
vhcr->status = CMD_STAT_BAD_PARAM;
}
}
ret = mlx4_status_to_errno(vhcr->status);
}
} else {
ret = mlx4_comm_cmd(dev, MLX4_COMM_CMD_VHCR_POST, 0,
MLX4_COMM_TIME + timeout);
if (!ret) {
if (out_is_imm) {
if (out_param)
*out_param =
be64_to_cpu(vhcr->out_param);
else {
mlx4_err(dev, "response expected while"
"output mailbox is NULL for "
"command 0x%x\n", op);
vhcr->status = CMD_STAT_BAD_PARAM;
}
}
ret = mlx4_status_to_errno(vhcr->status);
} else
mlx4_err(dev, "failed execution of VHCR_POST command"
"opcode 0x%x\n", op);
}
mutex_unlock(&priv->cmd.slave_cmd_mutex);
return ret;
}
static int mlx4_cmd_poll(struct mlx4_dev *dev, u64 in_param, u64 *out_param,
int out_is_imm, u32 in_modifier, u8 op_modifier,
u16 op, unsigned long timeout)
{
struct mlx4_priv *priv = mlx4_priv(dev);
void __iomem *hcr = priv->cmd.hcr;
int err = 0;
unsigned long end;
u32 stat;
down(&priv->cmd.poll_sem);
if (pci_channel_offline(dev->pdev)) {
err = -EIO;
goto out;
}
err = mlx4_cmd_post(dev, in_param, out_param ? *out_param : 0,
in_modifier, op_modifier, op, CMD_POLL_TOKEN, 0);
if (err)
goto out;
end = msecs_to_jiffies(timeout) + jiffies;
while (cmd_pending(dev) && time_before(jiffies, end)) {
if (pci_channel_offline(dev->pdev)) {
err = -EIO;
goto out;
}
cond_resched();
}
if (cmd_pending(dev)) {
mlx4_warn(dev, "command 0x%x timed out (go bit not cleared)\n",
op);
err = -ETIMEDOUT;
goto out;
}
if (out_is_imm)
*out_param =
(u64) be32_to_cpu((__force __be32)
__raw_readl(hcr + HCR_OUT_PARAM_OFFSET)) << 32 |
(u64) be32_to_cpu((__force __be32)
__raw_readl(hcr + HCR_OUT_PARAM_OFFSET + 4));
stat = be32_to_cpu((__force __be32)
__raw_readl(hcr + HCR_STATUS_OFFSET)) >> 24;
err = mlx4_status_to_errno(stat);
if (err)
mlx4_err(dev, "command 0x%x failed: fw status = 0x%x\n",
op, stat);
out:
up(&priv->cmd.poll_sem);
return err;
}
void mlx4_cmd_event(struct mlx4_dev *dev, u16 token, u8 status, u64 out_param)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_cmd_context *context =
&priv->cmd.context[token & priv->cmd.token_mask];
if (token != context->token)
return;
context->fw_status = status;
context->result = mlx4_status_to_errno(status);
context->out_param = out_param;
complete(&context->done);
}
static int mlx4_cmd_wait(struct mlx4_dev *dev, u64 in_param, u64 *out_param,
int out_is_imm, u32 in_modifier, u8 op_modifier,
u16 op, unsigned long timeout)
{
struct mlx4_cmd *cmd = &mlx4_priv(dev)->cmd;
struct mlx4_cmd_context *context;
int err = 0;
down(&cmd->event_sem);
spin_lock(&cmd->context_lock);
BUG_ON(cmd->free_head < 0);
context = &cmd->context[cmd->free_head];
context->token += cmd->token_mask + 1;
cmd->free_head = context->next;
spin_unlock(&cmd->context_lock);
init_completion(&context->done);
mlx4_cmd_post(dev, in_param, out_param ? *out_param : 0,
in_modifier, op_modifier, op, context->token, 1);
if (!wait_for_completion_timeout(&context->done,
msecs_to_jiffies(timeout))) {
mlx4_warn(dev, "command 0x%x timed out (go bit not cleared)\n",
op);
err = -EBUSY;
goto out;
}
err = context->result;
if (err) {
mlx4_err(dev, "command 0x%x failed: fw status = 0x%x\n",
op, context->fw_status);
goto out;
}
if (out_is_imm)
*out_param = context->out_param;
out:
spin_lock(&cmd->context_lock);
context->next = cmd->free_head;
cmd->free_head = context - cmd->context;
spin_unlock(&cmd->context_lock);
up(&cmd->event_sem);
return err;
}
int __mlx4_cmd(struct mlx4_dev *dev, u64 in_param, u64 *out_param,
int out_is_imm, u32 in_modifier, u8 op_modifier,
u16 op, unsigned long timeout, int native)
{
if (pci_channel_offline(dev->pdev))
return -EIO;
if (!mlx4_is_mfunc(dev) || (native && mlx4_is_master(dev))) {
if (mlx4_priv(dev)->cmd.use_events)
return mlx4_cmd_wait(dev, in_param, out_param,
out_is_imm, in_modifier,
op_modifier, op, timeout);
else
return mlx4_cmd_poll(dev, in_param, out_param,
out_is_imm, in_modifier,
op_modifier, op, timeout);
}
return mlx4_slave_cmd(dev, in_param, out_param, out_is_imm,
in_modifier, op_modifier, op, timeout);
}
static int mlx4_ARM_COMM_CHANNEL(struct mlx4_dev *dev)
{
return mlx4_cmd(dev, 0, 0, 0, MLX4_CMD_ARM_COMM_CHANNEL,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_NATIVE);
}
static int mlx4_ACCESS_MEM(struct mlx4_dev *dev, u64 master_addr,
int slave, u64 slave_addr,
int size, int is_read)
{
u64 in_param;
u64 out_param;
if ((slave_addr & 0xfff) | (master_addr & 0xfff) |
(slave & ~0x7f) | (size & 0xff)) {
mlx4_err(dev, "Bad access mem params - slave_addr:0x%llx "
"master_addr:0x%llx slave_id:%d size:%d\n",
slave_addr, master_addr, slave, size);
return -EINVAL;
}
if (is_read) {
in_param = (u64) slave | slave_addr;
out_param = (u64) dev->caps.function | master_addr;
} else {
in_param = (u64) dev->caps.function | master_addr;
out_param = (u64) slave | slave_addr;
}
return mlx4_cmd_imm(dev, in_param, &out_param, size, 0,
MLX4_CMD_ACCESS_MEM,
MLX4_CMD_TIME_CLASS_A, MLX4_CMD_NATIVE);
}
static int query_pkey_block(struct mlx4_dev *dev, u8 port, u16 index, u16 *pkey,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox)
{
struct ib_smp *in_mad = (struct ib_smp *)(inbox->buf);
struct ib_smp *out_mad = (struct ib_smp *)(outbox->buf);
int err;
int i;
if (index & 0x1f)
return -EINVAL;
in_mad->attr_mod = cpu_to_be32(index / 32);
err = mlx4_cmd_box(dev, inbox->dma, outbox->dma, port, 3,
MLX4_CMD_MAD_IFC, MLX4_CMD_TIME_CLASS_C,
MLX4_CMD_NATIVE);
if (err)
return err;
for (i = 0; i < 32; ++i)
pkey[i] = be16_to_cpu(((__be16 *) out_mad->data)[i]);
return err;
}
static int get_full_pkey_table(struct mlx4_dev *dev, u8 port, u16 *table,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox)
{
int i;
int err;
for (i = 0; i < dev->caps.pkey_table_len[port]; i += 32) {
err = query_pkey_block(dev, port, i, table + i, inbox, outbox);
if (err)
return err;
}
return 0;
}
static enum ib_port_state vf_port_state(struct mlx4_dev *dev, int port, int vf)
{
if (mlx4_get_slave_port_state(dev, vf, port) == SLAVE_PORT_UP)
return IB_PORT_ACTIVE;
else
return IB_PORT_DOWN;
}
static int mlx4_MAD_IFC_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
struct ib_smp *smp = inbox->buf;
u32 index;
u8 port;
u16 *table;
int err;
int vidx, pidx;
struct mlx4_priv *priv = mlx4_priv(dev);
struct ib_smp *outsmp = outbox->buf;
__be16 *outtab = (__be16 *)(outsmp->data);
__be32 slave_cap_mask;
__be64 slave_node_guid;
port = vhcr->in_modifier;
if (smp->base_version == 1 &&
smp->mgmt_class == IB_MGMT_CLASS_SUBN_LID_ROUTED &&
smp->class_version == 1) {
if (smp->method == IB_MGMT_METHOD_GET) {
if (smp->attr_id == IB_SMP_ATTR_PKEY_TABLE) {
index = be32_to_cpu(smp->attr_mod);
if (port < 1 || port > dev->caps.num_ports)
return -EINVAL;
table = kcalloc(dev->caps.pkey_table_len[port], sizeof *table, GFP_KERNEL);
if (!table)
return -ENOMEM;
err = get_full_pkey_table(dev, port, table, inbox, outbox);
if (!err) {
for (vidx = index * 32; vidx < (index + 1) * 32; ++vidx) {
pidx = priv->virt2phys_pkey[slave][port - 1][vidx];
outtab[vidx % 32] = cpu_to_be16(table[pidx]);
}
}
kfree(table);
return err;
}
if (smp->attr_id == IB_SMP_ATTR_PORT_INFO) {
err = mlx4_cmd_box(dev, inbox->dma, outbox->dma,
vhcr->in_modifier, vhcr->op_modifier,
vhcr->op, MLX4_CMD_TIME_CLASS_C, MLX4_CMD_NATIVE);
if (!err && slave != mlx4_master_func_num(dev)) {
u8 *state = outsmp->data + PORT_STATE_OFFSET;
*state = (*state & 0xf0) | vf_port_state(dev, port, slave);
slave_cap_mask = priv->mfunc.master.slave_state[slave].ib_cap_mask[port];
memcpy(outsmp->data + PORT_CAPABILITY_LOCATION_IN_SMP, &slave_cap_mask, 4);
}
return err;
}
if (smp->attr_id == IB_SMP_ATTR_GUID_INFO) {
smp->attr_mod = cpu_to_be32(slave / 8);
err = mlx4_cmd_box(dev, inbox->dma, outbox->dma,
vhcr->in_modifier, vhcr->op_modifier,
vhcr->op, MLX4_CMD_TIME_CLASS_C, MLX4_CMD_NATIVE);
if (!err) {
if (slave % 8)
memcpy(outsmp->data,
outsmp->data + (slave % 8) * 8, 8);
memset(outsmp->data + 8, 0, 56);
}
return err;
}
if (smp->attr_id == IB_SMP_ATTR_NODE_INFO) {
err = mlx4_cmd_box(dev, inbox->dma, outbox->dma,
vhcr->in_modifier, vhcr->op_modifier,
vhcr->op, MLX4_CMD_TIME_CLASS_C, MLX4_CMD_NATIVE);
if (!err) {
slave_node_guid = mlx4_get_slave_node_guid(dev, slave);
memcpy(outsmp->data + 12, &slave_node_guid, 8);
}
return err;
}
}
}
if (slave != mlx4_master_func_num(dev) &&
((smp->mgmt_class == IB_MGMT_CLASS_SUBN_DIRECTED_ROUTE) ||
(smp->mgmt_class == IB_MGMT_CLASS_SUBN_LID_ROUTED &&
smp->method == IB_MGMT_METHOD_SET))) {
mlx4_err(dev, "slave %d is trying to execute a Subnet MGMT MAD, "
"class 0x%x, method 0x%x for attr 0x%x. Rejecting\n",
slave, smp->method, smp->mgmt_class,
be16_to_cpu(smp->attr_id));
return -EPERM;
}
return mlx4_cmd_box(dev, inbox->dma, outbox->dma,
vhcr->in_modifier, vhcr->op_modifier,
vhcr->op, MLX4_CMD_TIME_CLASS_C, MLX4_CMD_NATIVE);
}
static int MLX4_CMD_UPDATE_QP_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
return -EPERM;
}
static int MLX4_CMD_GET_OP_REQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
return -EPERM;
}
int mlx4_DMA_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
u64 in_param;
u64 out_param;
int err;
in_param = cmd->has_inbox ? (u64) inbox->dma : vhcr->in_param;
out_param = cmd->has_outbox ? (u64) outbox->dma : vhcr->out_param;
if (cmd->encode_slave_id) {
in_param &= 0xffffffffffffff00ll;
in_param |= slave;
}
err = __mlx4_cmd(dev, in_param, &out_param, cmd->out_is_imm,
vhcr->in_modifier, vhcr->op_modifier, vhcr->op,
MLX4_CMD_TIME_CLASS_A, MLX4_CMD_NATIVE);
if (cmd->out_is_imm)
vhcr->out_param = out_param;
return err;
}
static int mlx4_master_process_vhcr(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr_cmd *in_vhcr)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_cmd_info *cmd = NULL;
struct mlx4_vhcr_cmd *vhcr_cmd = in_vhcr ? in_vhcr : priv->mfunc.vhcr;
struct mlx4_vhcr *vhcr;
struct mlx4_cmd_mailbox *inbox = NULL;
struct mlx4_cmd_mailbox *outbox = NULL;
u64 in_param;
u64 out_param;
int ret = 0;
int i;
int err = 0;
vhcr = kzalloc(sizeof(struct mlx4_vhcr), GFP_KERNEL);
if (!vhcr)
return -ENOMEM;
if (!in_vhcr) {
ret = mlx4_ACCESS_MEM(dev, priv->mfunc.vhcr_dma, slave,
priv->mfunc.master.slave_state[slave].vhcr_dma,
ALIGN(sizeof(struct mlx4_vhcr_cmd),
MLX4_ACCESS_MEM_ALIGN), 1);
if (ret) {
mlx4_err(dev, "%s:Failed reading vhcr"
"ret: 0x%x\n", __func__, ret);
kfree(vhcr);
return ret;
}
}
vhcr->in_param = be64_to_cpu(vhcr_cmd->in_param);
vhcr->out_param = be64_to_cpu(vhcr_cmd->out_param);
vhcr->in_modifier = be32_to_cpu(vhcr_cmd->in_modifier);
vhcr->token = be16_to_cpu(vhcr_cmd->token);
vhcr->op = be16_to_cpu(vhcr_cmd->opcode) & 0xfff;
vhcr->op_modifier = (u8) (be16_to_cpu(vhcr_cmd->opcode) >> 12);
vhcr->e_bit = vhcr_cmd->flags & (1 << 6);
for (i = 0; i < ARRAY_SIZE(cmd_info); ++i) {
if (vhcr->op == cmd_info[i].opcode) {
cmd = &cmd_info[i];
break;
}
}
if (!cmd) {
mlx4_err(dev, "Unknown command:0x%x accepted from slave:%d\n",
vhcr->op, slave);
vhcr_cmd->status = CMD_STAT_BAD_PARAM;
goto out_status;
}
if (cmd->has_inbox) {
vhcr->in_param &= INBOX_MASK;
inbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(inbox)) {
vhcr_cmd->status = CMD_STAT_BAD_SIZE;
inbox = NULL;
goto out_status;
}
if (mlx4_ACCESS_MEM(dev, inbox->dma, slave,
vhcr->in_param,
MLX4_MAILBOX_SIZE, 1)) {
mlx4_err(dev, "%s: Failed reading inbox (cmd:0x%x)\n",
__func__, cmd->opcode);
vhcr_cmd->status = CMD_STAT_INTERNAL_ERR;
goto out_status;
}
}
if (cmd->verify && cmd->verify(dev, slave, vhcr, inbox)) {
mlx4_warn(dev, "Command:0x%x from slave: %d failed protection "
"checks for resource_id:%d\n", vhcr->op, slave,
vhcr->in_modifier);
vhcr_cmd->status = CMD_STAT_BAD_OP;
goto out_status;
}
if (cmd->has_outbox) {
outbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(outbox)) {
vhcr_cmd->status = CMD_STAT_BAD_SIZE;
outbox = NULL;
goto out_status;
}
}
if (cmd->wrapper) {
err = cmd->wrapper(dev, slave, vhcr, inbox, outbox,
cmd);
if (cmd->out_is_imm)
vhcr_cmd->out_param = cpu_to_be64(vhcr->out_param);
} else {
in_param = cmd->has_inbox ? (u64) inbox->dma :
vhcr->in_param;
out_param = cmd->has_outbox ? (u64) outbox->dma :
vhcr->out_param;
err = __mlx4_cmd(dev, in_param, &out_param,
cmd->out_is_imm, vhcr->in_modifier,
vhcr->op_modifier, vhcr->op,
MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
if (cmd->out_is_imm) {
vhcr->out_param = out_param;
vhcr_cmd->out_param = cpu_to_be64(vhcr->out_param);
}
}
if (err) {
mlx4_warn(dev, "vhcr command:0x%x slave:%d failed with"
" error:%d, status %d\n",
vhcr->op, slave, vhcr->errno, err);
vhcr_cmd->status = mlx4_errno_to_status(err);
goto out_status;
}
if (cmd->has_outbox && !vhcr_cmd->status) {
ret = mlx4_ACCESS_MEM(dev, outbox->dma, slave,
vhcr->out_param,
MLX4_MAILBOX_SIZE, MLX4_CMD_WRAPPED);
if (ret) {
mlx4_err(dev, "%s:Failed writing outbox\n", __func__);
goto out;
}
}
out_status:
if (!in_vhcr) {
ret = mlx4_ACCESS_MEM(dev, priv->mfunc.vhcr_dma, slave,
priv->mfunc.master.slave_state[slave].vhcr_dma,
ALIGN(sizeof(struct mlx4_vhcr),
MLX4_ACCESS_MEM_ALIGN),
MLX4_CMD_WRAPPED);
if (ret)
mlx4_err(dev, "%s:Failed writing vhcr result\n",
__func__);
else if (vhcr->e_bit &&
mlx4_GEN_EQE(dev, slave, &priv->mfunc.master.cmd_eqe))
mlx4_warn(dev, "Failed to generate command completion "
"eqe for slave %d\n", slave);
}
out:
kfree(vhcr);
mlx4_free_cmd_mailbox(dev, inbox);
mlx4_free_cmd_mailbox(dev, outbox);
return ret;
}
static int calculate_transition(u16 oper_vlan, u16 admin_vlan)
{
return (2 * (oper_vlan == MLX4_VGT) + (admin_vlan == MLX4_VGT));
}
static int mlx4_master_immediate_activate_vlan_qos(struct mlx4_priv *priv,
int slave, int port)
{
struct mlx4_vport_oper_state *vp_oper;
struct mlx4_vport_state *vp_admin;
struct mlx4_vf_immed_vlan_work *work;
struct mlx4_dev *dev = &(priv->dev);
int err;
int admin_vlan_ix = NO_INDX;
enum mlx4_vlan_transition vlan_trans;
vp_oper = &priv->mfunc.master.vf_oper[slave].vport[port];
vp_admin = &priv->mfunc.master.vf_admin[slave].vport[port];
if (vp_oper->state.default_vlan == vp_admin->default_vlan &&
vp_oper->state.default_qos == vp_admin->default_qos &&
vp_oper->state.link_state == vp_admin->link_state)
return 0;
vlan_trans = calculate_transition(vp_oper->state.default_vlan,
vp_admin->default_vlan);
if (!(priv->mfunc.master.slave_state[slave].active &&
dev->caps.flags2 & MLX4_DEV_CAP_FLAG2_UPDATE_QP &&
vlan_trans == MLX4_VLAN_TRANSITION_VST_VST)) {
vp_oper->state.link_state = vp_admin->link_state;
return -1;
}
mlx4_dbg(dev, "updating immediately admin params slave %d port %d\n",
slave, port);
mlx4_dbg(dev, "vlan %d QoS %d link down %d\n", vp_admin->default_vlan,
vp_admin->default_qos, vp_admin->link_state);
work = kzalloc(sizeof(*work), GFP_KERNEL);
if (!work)
return -ENOMEM;
if (vp_oper->state.default_vlan != vp_admin->default_vlan) {
err = __mlx4_register_vlan(&priv->dev, port,
vp_admin->default_vlan,
&admin_vlan_ix);
if (err) {
kfree(work);
mlx4_warn((&priv->dev),
"No vlan resources slave %d, port %d\n",
slave, port);
return err;
}
work->flags |= MLX4_VF_IMMED_VLAN_FLAG_VLAN;
mlx4_dbg((&(priv->dev)),
"alloc vlan %d idx %d slave %d port %d\n",
(int)(vp_admin->default_vlan),
admin_vlan_ix, slave, port);
}
work->orig_vlan_id = vp_oper->state.default_vlan;
work->orig_vlan_ix = vp_oper->vlan_idx;
if (vp_oper->state.default_qos != vp_admin->default_qos)
work->flags |= MLX4_VF_IMMED_VLAN_FLAG_QOS;
if (work->flags & MLX4_VF_IMMED_VLAN_FLAG_VLAN)
vp_oper->vlan_idx = admin_vlan_ix;
vp_oper->state.default_vlan = vp_admin->default_vlan;
vp_oper->state.default_qos = vp_admin->default_qos;
vp_oper->state.link_state = vp_admin->link_state;
if (vp_admin->link_state == IFLA_VF_LINK_STATE_DISABLE)
work->flags |= MLX4_VF_IMMED_VLAN_FLAG_LINK_DISABLE;
work->port = port;
work->slave = slave;
work->qos = vp_oper->state.default_qos;
work->vlan_id = vp_oper->state.default_vlan;
work->vlan_ix = vp_oper->vlan_idx;
work->priv = priv;
INIT_WORK(&work->work, mlx4_vf_immed_vlan_work_handler);
queue_work(priv->mfunc.master.comm_wq, &work->work);
return 0;
}
static int mlx4_master_activate_admin_state(struct mlx4_priv *priv, int slave)
{
int port, err;
struct mlx4_vport_state *vp_admin;
struct mlx4_vport_oper_state *vp_oper;
for (port = 1; port <= MLX4_MAX_PORTS; port++) {
vp_oper = &priv->mfunc.master.vf_oper[slave].vport[port];
vp_admin = &priv->mfunc.master.vf_admin[slave].vport[port];
vp_oper->state = *vp_admin;
if (MLX4_VGT != vp_admin->default_vlan) {
err = __mlx4_register_vlan(&priv->dev, port,
vp_admin->default_vlan, &(vp_oper->vlan_idx));
if (err) {
vp_oper->vlan_idx = NO_INDX;
mlx4_warn((&priv->dev),
"No vlan resorces slave %d, port %d\n",
slave, port);
return err;
}
mlx4_dbg((&(priv->dev)), "alloc vlan %d idx %d slave %d port %d\n",
(int)(vp_oper->state.default_vlan),
vp_oper->vlan_idx, slave, port);
}
if (vp_admin->spoofchk) {
vp_oper->mac_idx = __mlx4_register_mac(&priv->dev,
port,
vp_admin->mac);
if (0 > vp_oper->mac_idx) {
err = vp_oper->mac_idx;
vp_oper->mac_idx = NO_INDX;
mlx4_warn((&priv->dev),
"No mac resorces slave %d, port %d\n",
slave, port);
return err;
}
mlx4_dbg((&(priv->dev)), "alloc mac %llx idx %d slave %d port %d\n",
vp_oper->state.mac, vp_oper->mac_idx, slave, port);
}
}
return 0;
}
static void mlx4_master_deactivate_admin_state(struct mlx4_priv *priv, int slave)
{
int port;
struct mlx4_vport_oper_state *vp_oper;
for (port = 1; port <= MLX4_MAX_PORTS; port++) {
vp_oper = &priv->mfunc.master.vf_oper[slave].vport[port];
if (NO_INDX != vp_oper->vlan_idx) {
__mlx4_unregister_vlan(&priv->dev,
port, vp_oper->vlan_idx);
vp_oper->vlan_idx = NO_INDX;
}
if (NO_INDX != vp_oper->mac_idx) {
__mlx4_unregister_mac(&priv->dev, port, vp_oper->mac_idx);
vp_oper->mac_idx = NO_INDX;
}
}
return;
}
static void mlx4_master_do_cmd(struct mlx4_dev *dev, int slave, u8 cmd,
u16 param, u8 toggle)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_slave_state *slave_state = priv->mfunc.master.slave_state;
u32 reply;
u8 is_going_down = 0;
int i;
unsigned long flags;
slave_state[slave].comm_toggle ^= 1;
reply = (u32) slave_state[slave].comm_toggle << 31;
if (toggle != slave_state[slave].comm_toggle) {
mlx4_warn(dev, "Incorrect toggle %d from slave %d. *** MASTER"
"STATE COMPROMISIED ***\n", toggle, slave);
goto reset_slave;
}
if (cmd == MLX4_COMM_CMD_RESET) {
mlx4_warn(dev, "Received reset from slave:%d\n", slave);
slave_state[slave].active = false;
mlx4_master_deactivate_admin_state(priv, slave);
for (i = 0; i < MLX4_EVENT_TYPES_NUM; ++i) {
slave_state[slave].event_eq[i].eqn = -1;
slave_state[slave].event_eq[i].token = 0;
}
if (MLX4_COMM_CMD_FLR == slave_state[slave].last_cmd)
goto inform_slave_state;
mlx4_dispatch_event(dev, MLX4_DEV_EVENT_SLAVE_SHUTDOWN, slave);
reply |= mlx4_comm_get_version();
goto reset_slave;
}
if (cmd != MLX4_COMM_CMD_RESET &&
MLX4_COMM_CMD_FLR == slave_state[slave].last_cmd) {
mlx4_warn(dev, "slave:%d is Trying to run cmd(0x%x) "
"in the middle of FLR\n", slave, cmd);
return;
}
switch (cmd) {
case MLX4_COMM_CMD_VHCR0:
if (slave_state[slave].last_cmd != MLX4_COMM_CMD_RESET)
goto reset_slave;
slave_state[slave].vhcr_dma = ((u64) param) << 48;
priv->mfunc.master.slave_state[slave].cookie = 0;
mutex_init(&priv->mfunc.master.gen_eqe_mutex[slave]);
break;
case MLX4_COMM_CMD_VHCR1:
if (slave_state[slave].last_cmd != MLX4_COMM_CMD_VHCR0)
goto reset_slave;
slave_state[slave].vhcr_dma |= ((u64) param) << 32;
break;
case MLX4_COMM_CMD_VHCR2:
if (slave_state[slave].last_cmd != MLX4_COMM_CMD_VHCR1)
goto reset_slave;
slave_state[slave].vhcr_dma |= ((u64) param) << 16;
break;
case MLX4_COMM_CMD_VHCR_EN:
if (slave_state[slave].last_cmd != MLX4_COMM_CMD_VHCR2)
goto reset_slave;
slave_state[slave].vhcr_dma |= param;
if (mlx4_master_activate_admin_state(priv, slave))
goto reset_slave;
slave_state[slave].active = true;
mlx4_dispatch_event(dev, MLX4_DEV_EVENT_SLAVE_INIT, slave);
break;
case MLX4_COMM_CMD_VHCR_POST:
if ((slave_state[slave].last_cmd != MLX4_COMM_CMD_VHCR_EN) &&
(slave_state[slave].last_cmd != MLX4_COMM_CMD_VHCR_POST))
goto reset_slave;
mutex_lock(&priv->cmd.slave_cmd_mutex);
if (mlx4_master_process_vhcr(dev, slave, NULL)) {
mlx4_err(dev, "Failed processing vhcr for slave:%d,"
" resetting slave.\n", slave);
mutex_unlock(&priv->cmd.slave_cmd_mutex);
goto reset_slave;
}
mutex_unlock(&priv->cmd.slave_cmd_mutex);
break;
default:
mlx4_warn(dev, "Bad comm cmd:%d from slave:%d\n", cmd, slave);
goto reset_slave;
}
spin_lock_irqsave(&priv->mfunc.master.slave_state_lock, flags);
if (!slave_state[slave].is_slave_going_down)
slave_state[slave].last_cmd = cmd;
else
is_going_down = 1;
spin_unlock_irqrestore(&priv->mfunc.master.slave_state_lock, flags);
if (is_going_down) {
mlx4_warn(dev, "Slave is going down aborting command(%d)"
" executing from slave:%d\n",
cmd, slave);
return;
}
__raw_writel((__force u32) cpu_to_be32(reply),
&priv->mfunc.comm[slave].slave_read);
mmiowb();
return;
reset_slave:
mlx4_delete_all_resources_for_slave(dev, slave);
spin_lock_irqsave(&priv->mfunc.master.slave_state_lock, flags);
if (!slave_state[slave].is_slave_going_down)
slave_state[slave].last_cmd = MLX4_COMM_CMD_RESET;
spin_unlock_irqrestore(&priv->mfunc.master.slave_state_lock, flags);
inform_slave_state:
memset(&slave_state[slave].event_eq, 0,
sizeof(struct mlx4_slave_event_eq_info));
__raw_writel((__force u32) cpu_to_be32(reply),
&priv->mfunc.comm[slave].slave_read);
wmb();
}
void mlx4_master_comm_channel(struct work_struct *work)
{
struct mlx4_mfunc_master_ctx *master =
container_of(work,
struct mlx4_mfunc_master_ctx,
comm_work);
struct mlx4_mfunc *mfunc =
container_of(master, struct mlx4_mfunc, master);
struct mlx4_priv *priv =
container_of(mfunc, struct mlx4_priv, mfunc);
struct mlx4_dev *dev = &priv->dev;
__be32 *bit_vec;
u32 comm_cmd;
u32 vec;
int i, j, slave;
int toggle;
int served = 0;
int reported = 0;
u32 slt;
bit_vec = master->comm_arm_bit_vector;
for (i = 0; i < COMM_CHANNEL_BIT_ARRAY_SIZE; i++) {
vec = be32_to_cpu(bit_vec[i]);
for (j = 0; j < 32; j++) {
if (!(vec & (1 << j)))
continue;
++reported;
slave = (i * 32) + j;
comm_cmd = swab32(readl(
&mfunc->comm[slave].slave_write));
slt = swab32(readl(&mfunc->comm[slave].slave_read))
>> 31;
toggle = comm_cmd >> 31;
if (toggle != slt) {
if (master->slave_state[slave].comm_toggle
!= slt) {
printk(KERN_INFO "slave %d out of sync."
" read toggle %d, state toggle %d. "
"Resynching.\n", slave, slt,
master->slave_state[slave].comm_toggle);
master->slave_state[slave].comm_toggle =
slt;
}
mlx4_master_do_cmd(dev, slave,
comm_cmd >> 16 & 0xff,
comm_cmd & 0xffff, toggle);
++served;
}
}
}
if (reported && reported != served)
mlx4_warn(dev, "Got command event with bitmask from %d slaves"
" but %d were served\n",
reported, served);
if (mlx4_ARM_COMM_CHANNEL(dev))
mlx4_warn(dev, "Failed to arm comm channel events\n");
}
static int sync_toggles(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int wr_toggle;
int rd_toggle;
unsigned long end;
wr_toggle = swab32(readl(&priv->mfunc.comm->slave_write)) >> 31;
end = jiffies + msecs_to_jiffies(5000);
while (time_before(jiffies, end)) {
rd_toggle = swab32(readl(&priv->mfunc.comm->slave_read)) >> 31;
if (rd_toggle == wr_toggle) {
priv->cmd.comm_toggle = rd_toggle;
return 0;
}
cond_resched();
}
mlx4_warn(dev, "recovering from previously mis-behaved VM\n");
__raw_writel((__force u32) 0, &priv->mfunc.comm->slave_read);
__raw_writel((__force u32) 0, &priv->mfunc.comm->slave_write);
priv->cmd.comm_toggle = 0;
return 0;
}
int mlx4_multi_func_init(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_slave_state *s_state;
int i, j, err, port;
if (mlx4_is_master(dev))
priv->mfunc.comm =
ioremap(pci_resource_start(dev->pdev, priv->fw.comm_bar) +
priv->fw.comm_base, MLX4_COMM_PAGESIZE);
else
priv->mfunc.comm =
ioremap(pci_resource_start(dev->pdev, 2) +
MLX4_SLAVE_COMM_BASE, MLX4_COMM_PAGESIZE);
if (!priv->mfunc.comm) {
mlx4_err(dev, "Couldn't map communication vector.\n");
goto err_vhcr;
}
if (mlx4_is_master(dev)) {
priv->mfunc.master.slave_state =
kzalloc(dev->num_slaves *
sizeof(struct mlx4_slave_state), GFP_KERNEL);
if (!priv->mfunc.master.slave_state)
goto err_comm;
priv->mfunc.master.vf_admin =
kzalloc(dev->num_slaves *
sizeof(struct mlx4_vf_admin_state), GFP_KERNEL);
if (!priv->mfunc.master.vf_admin)
goto err_comm_admin;
priv->mfunc.master.vf_oper =
kzalloc(dev->num_slaves *
sizeof(struct mlx4_vf_oper_state), GFP_KERNEL);
if (!priv->mfunc.master.vf_oper)
goto err_comm_oper;
for (i = 0; i < dev->num_slaves; ++i) {
s_state = &priv->mfunc.master.slave_state[i];
s_state->last_cmd = MLX4_COMM_CMD_RESET;
for (j = 0; j < MLX4_EVENT_TYPES_NUM; ++j)
s_state->event_eq[j].eqn = -1;
__raw_writel((__force u32) 0,
&priv->mfunc.comm[i].slave_write);
__raw_writel((__force u32) 0,
&priv->mfunc.comm[i].slave_read);
mmiowb();
for (port = 1; port <= MLX4_MAX_PORTS; port++) {
s_state->vlan_filter[port] =
kzalloc(sizeof(struct mlx4_vlan_fltr),
GFP_KERNEL);
if (!s_state->vlan_filter[port]) {
if (--port)
kfree(s_state->vlan_filter[port]);
goto err_slaves;
}
INIT_LIST_HEAD(&s_state->mcast_filters[port]);
priv->mfunc.master.vf_admin[i].vport[port].default_vlan = MLX4_VGT;
priv->mfunc.master.vf_oper[i].vport[port].state.default_vlan = MLX4_VGT;
priv->mfunc.master.vf_oper[i].vport[port].vlan_idx = NO_INDX;
priv->mfunc.master.vf_oper[i].vport[port].mac_idx = NO_INDX;
}
spin_lock_init(&s_state->lock);
}
memset(&priv->mfunc.master.cmd_eqe, 0, dev->caps.eqe_size);
priv->mfunc.master.cmd_eqe.type = MLX4_EVENT_TYPE_CMD;
INIT_WORK(&priv->mfunc.master.comm_work,
mlx4_master_comm_channel);
INIT_WORK(&priv->mfunc.master.slave_event_work,
mlx4_gen_slave_eqe);
INIT_WORK(&priv->mfunc.master.slave_flr_event_work,
mlx4_master_handle_slave_flr);
spin_lock_init(&priv->mfunc.master.slave_state_lock);
spin_lock_init(&priv->mfunc.master.slave_eq.event_lock);
priv->mfunc.master.comm_wq =
create_singlethread_workqueue("mlx4_comm");
if (!priv->mfunc.master.comm_wq)
goto err_slaves;
if (mlx4_init_resource_tracker(dev))
goto err_thread;
err = mlx4_ARM_COMM_CHANNEL(dev);
if (err) {
mlx4_err(dev, " Failed to arm comm channel eq: %x\n",
err);
goto err_resource;
}
} else {
err = sync_toggles(dev);
if (err) {
mlx4_err(dev, "Couldn't sync toggles\n");
goto err_comm;
}
}
return 0;
err_resource:
mlx4_free_resource_tracker(dev, RES_TR_FREE_ALL);
err_thread:
flush_workqueue(priv->mfunc.master.comm_wq);
destroy_workqueue(priv->mfunc.master.comm_wq);
err_slaves:
while (--i) {
for (port = 1; port <= MLX4_MAX_PORTS; port++)
kfree(priv->mfunc.master.slave_state[i].vlan_filter[port]);
}
kfree(priv->mfunc.master.vf_oper);
err_comm_oper:
kfree(priv->mfunc.master.vf_admin);
err_comm_admin:
kfree(priv->mfunc.master.slave_state);
err_comm:
iounmap(priv->mfunc.comm);
err_vhcr:
dma_free_coherent(&(dev->pdev->dev), PAGE_SIZE,
priv->mfunc.vhcr,
priv->mfunc.vhcr_dma);
priv->mfunc.vhcr = NULL;
return -ENOMEM;
}
int mlx4_cmd_init(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
mutex_init(&priv->cmd.hcr_mutex);
mutex_init(&priv->cmd.slave_cmd_mutex);
sema_init(&priv->cmd.poll_sem, 1);
priv->cmd.use_events = 0;
priv->cmd.toggle = 1;
priv->cmd.hcr = NULL;
priv->mfunc.vhcr = NULL;
if (!mlx4_is_slave(dev)) {
priv->cmd.hcr = ioremap(pci_resource_start(dev->pdev, 0) +
MLX4_HCR_BASE, MLX4_HCR_SIZE);
if (!priv->cmd.hcr) {
mlx4_err(dev, "Couldn't map command register.\n");
return -ENOMEM;
}
}
if (mlx4_is_mfunc(dev)) {
priv->mfunc.vhcr = dma_alloc_coherent(&(dev->pdev->dev), PAGE_SIZE,
&priv->mfunc.vhcr_dma,
GFP_KERNEL);
if (!priv->mfunc.vhcr)
goto err_hcr;
}
priv->cmd.pool = pci_pool_create("mlx4_cmd", dev->pdev,
MLX4_MAILBOX_SIZE,
MLX4_MAILBOX_SIZE, 0);
if (!priv->cmd.pool)
goto err_vhcr;
return 0;
err_vhcr:
if (mlx4_is_mfunc(dev))
dma_free_coherent(&(dev->pdev->dev), PAGE_SIZE,
priv->mfunc.vhcr, priv->mfunc.vhcr_dma);
priv->mfunc.vhcr = NULL;
err_hcr:
if (!mlx4_is_slave(dev))
iounmap(priv->cmd.hcr);
return -ENOMEM;
}
void mlx4_multi_func_cleanup(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int i, port;
if (mlx4_is_master(dev)) {
flush_workqueue(priv->mfunc.master.comm_wq);
destroy_workqueue(priv->mfunc.master.comm_wq);
for (i = 0; i < dev->num_slaves; i++) {
for (port = 1; port <= MLX4_MAX_PORTS; port++)
kfree(priv->mfunc.master.slave_state[i].vlan_filter[port]);
}
kfree(priv->mfunc.master.slave_state);
kfree(priv->mfunc.master.vf_admin);
kfree(priv->mfunc.master.vf_oper);
}
iounmap(priv->mfunc.comm);
}
void mlx4_cmd_cleanup(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
pci_pool_destroy(priv->cmd.pool);
if (!mlx4_is_slave(dev))
iounmap(priv->cmd.hcr);
if (mlx4_is_mfunc(dev))
dma_free_coherent(&(dev->pdev->dev), PAGE_SIZE,
priv->mfunc.vhcr, priv->mfunc.vhcr_dma);
priv->mfunc.vhcr = NULL;
}
int mlx4_cmd_use_events(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int i;
int err = 0;
priv->cmd.context = kmalloc(priv->cmd.max_cmds *
sizeof (struct mlx4_cmd_context),
GFP_KERNEL);
if (!priv->cmd.context)
return -ENOMEM;
for (i = 0; i < priv->cmd.max_cmds; ++i) {
priv->cmd.context[i].token = i;
priv->cmd.context[i].next = i + 1;
}
priv->cmd.context[priv->cmd.max_cmds - 1].next = -1;
priv->cmd.free_head = 0;
sema_init(&priv->cmd.event_sem, priv->cmd.max_cmds);
spin_lock_init(&priv->cmd.context_lock);
for (priv->cmd.token_mask = 1;
priv->cmd.token_mask < priv->cmd.max_cmds;
priv->cmd.token_mask <<= 1)
;
--priv->cmd.token_mask;
down(&priv->cmd.poll_sem);
priv->cmd.use_events = 1;
return err;
}
void mlx4_cmd_use_polling(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int i;
priv->cmd.use_events = 0;
for (i = 0; i < priv->cmd.max_cmds; ++i)
down(&priv->cmd.event_sem);
kfree(priv->cmd.context);
up(&priv->cmd.poll_sem);
}
struct mlx4_cmd_mailbox *mlx4_alloc_cmd_mailbox(struct mlx4_dev *dev)
{
struct mlx4_cmd_mailbox *mailbox;
mailbox = kmalloc(sizeof *mailbox, GFP_KERNEL);
if (!mailbox)
return ERR_PTR(-ENOMEM);
mailbox->buf = pci_pool_alloc(mlx4_priv(dev)->cmd.pool, GFP_KERNEL,
&mailbox->dma);
if (!mailbox->buf) {
kfree(mailbox);
return ERR_PTR(-ENOMEM);
}
return mailbox;
}
void mlx4_free_cmd_mailbox(struct mlx4_dev *dev,
struct mlx4_cmd_mailbox *mailbox)
{
if (!mailbox)
return;
pci_pool_free(mlx4_priv(dev)->cmd.pool, mailbox->buf, mailbox->dma);
kfree(mailbox);
}
u32 mlx4_comm_get_version(void)
{
return ((u32) CMD_CHAN_IF_REV << 8) | (u32) CMD_CHAN_VER;
}
static int mlx4_get_slave_indx(struct mlx4_dev *dev, int vf)
{
if ((vf < 0) || (vf >= dev->num_vfs)) {
mlx4_err(dev, "Bad vf number:%d (number of activated vf: %d)\n", vf, dev->num_vfs);
return -EINVAL;
}
return vf+1;
}
int mlx4_set_vf_mac(struct mlx4_dev *dev, int port, int vf, u64 mac)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_vport_state *s_info;
int slave;
if (!mlx4_is_master(dev))
return -EPROTONOSUPPORT;
slave = mlx4_get_slave_indx(dev, vf);
if (slave < 0)
return -EINVAL;
s_info = &priv->mfunc.master.vf_admin[slave].vport[port];
s_info->mac = mac;
mlx4_info(dev, "default mac on vf %d port %d to %llX will take afect only after vf restart\n",
vf, port, s_info->mac);
return 0;
}
int mlx4_set_vf_vlan(struct mlx4_dev *dev, int port, int vf, u16 vlan, u8 qos)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_vport_oper_state *vf_oper;
struct mlx4_vport_state *vf_admin;
int slave;
if ((!mlx4_is_master(dev)) ||
!(dev->caps.flags2 & MLX4_DEV_CAP_FLAG2_VLAN_CONTROL))
return -EPROTONOSUPPORT;
if ((vlan > 4095) || (qos > 7))
return -EINVAL;
slave = mlx4_get_slave_indx(dev, vf);
if (slave < 0)
return -EINVAL;
vf_admin = &priv->mfunc.master.vf_admin[slave].vport[port];
vf_oper = &priv->mfunc.master.vf_oper[slave].vport[port];
if ((0 == vlan) && (0 == qos))
vf_admin->default_vlan = MLX4_VGT;
else
vf_admin->default_vlan = vlan;
vf_admin->default_qos = qos;
if (mlx4_master_immediate_activate_vlan_qos(priv, slave, port))
mlx4_info(dev,
"updating vf %d port %d config will take effect on next VF restart\n",
vf, port);
return 0;
}
int mlx4_set_vf_spoofchk(struct mlx4_dev *dev, int port, int vf, bool setting)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_vport_state *s_info;
int slave;
if ((!mlx4_is_master(dev)) ||
!(dev->caps.flags2 & MLX4_DEV_CAP_FLAG2_FSM))
return -EPROTONOSUPPORT;
slave = mlx4_get_slave_indx(dev, vf);
if (slave < 0)
return -EINVAL;
s_info = &priv->mfunc.master.vf_admin[slave].vport[port];
s_info->spoofchk = setting;
return 0;
}
int mlx4_get_vf_config(struct mlx4_dev *dev, int port, int vf, struct ifla_vf_info *ivf)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_vport_state *s_info;
int slave;
if (!mlx4_is_master(dev))
return -EPROTONOSUPPORT;
slave = mlx4_get_slave_indx(dev, vf);
if (slave < 0)
return -EINVAL;
s_info = &priv->mfunc.master.vf_admin[slave].vport[port];
ivf->vf = vf;
ivf->mac[0] = ((s_info->mac >> (5*8)) & 0xff);
ivf->mac[1] = ((s_info->mac >> (4*8)) & 0xff);
ivf->mac[2] = ((s_info->mac >> (3*8)) & 0xff);
ivf->mac[3] = ((s_info->mac >> (2*8)) & 0xff);
ivf->mac[4] = ((s_info->mac >> (1*8)) & 0xff);
ivf->mac[5] = ((s_info->mac) & 0xff);
ivf->vlan = s_info->default_vlan;
ivf->qos = s_info->default_qos;
ivf->tx_rate = s_info->tx_rate;
ivf->spoofchk = s_info->spoofchk;
ivf->linkstate = s_info->link_state;
return 0;
}
int mlx4_set_vf_link_state(struct mlx4_dev *dev, int port, int vf, int link_state)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_vport_state *s_info;
int slave;
u8 link_stat_event;
slave = mlx4_get_slave_indx(dev, vf);
if (slave < 0)
return -EINVAL;
switch (link_state) {
case IFLA_VF_LINK_STATE_AUTO:
if (!priv->sense.do_sense_port[port])
link_stat_event = MLX4_PORT_CHANGE_SUBTYPE_ACTIVE;
else
link_stat_event = MLX4_PORT_CHANGE_SUBTYPE_DOWN;
break;
case IFLA_VF_LINK_STATE_ENABLE:
link_stat_event = MLX4_PORT_CHANGE_SUBTYPE_ACTIVE;
break;
case IFLA_VF_LINK_STATE_DISABLE:
link_stat_event = MLX4_PORT_CHANGE_SUBTYPE_DOWN;
break;
default:
mlx4_warn(dev, "unknown value for link_state %02x on slave %d port %d\n",
link_state, slave, port);
return -EINVAL;
};
s_info = &priv->mfunc.master.vf_admin[slave].vport[port];
s_info->link_state = link_state;
mlx4_gen_port_state_change_eqe(dev, slave, port, link_stat_event);
if (mlx4_master_immediate_activate_vlan_qos(priv, slave, port))
mlx4_dbg(dev,
"updating vf %d port %d no link state HW enforcment\n",
vf, port);
return 0;
}
