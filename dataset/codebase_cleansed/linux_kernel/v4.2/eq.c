static u64 get_async_ev_mask(struct mlx4_dev *dev)
{
u64 async_ev_mask = MLX4_ASYNC_EVENT_MASK;
if (dev->caps.flags & MLX4_DEV_CAP_FLAG_PORT_MNG_CHG_EV)
async_ev_mask |= (1ull << MLX4_EVENT_TYPE_PORT_MNG_CHG_EVENT);
if (dev->caps.flags2 & MLX4_DEV_CAP_FLAG2_RECOVERABLE_ERROR_EVENT)
async_ev_mask |= (1ull << MLX4_EVENT_TYPE_RECOVERABLE_ERROR_EVENT);
return async_ev_mask;
}
static void eq_set_ci(struct mlx4_eq *eq, int req_not)
{
__raw_writel((__force u32) cpu_to_be32((eq->cons_index & 0xffffff) |
req_not << 31),
eq->doorbell);
mb();
}
static struct mlx4_eqe *get_eqe(struct mlx4_eq *eq, u32 entry, u8 eqe_factor,
u8 eqe_size)
{
unsigned long offset = (entry & (eq->nent - 1)) * eqe_size;
return eq->page_list[offset / PAGE_SIZE].buf + (offset + (eqe_factor ? MLX4_EQ_ENTRY_SIZE : 0)) % PAGE_SIZE;
}
static struct mlx4_eqe *next_eqe_sw(struct mlx4_eq *eq, u8 eqe_factor, u8 size)
{
struct mlx4_eqe *eqe = get_eqe(eq, eq->cons_index, eqe_factor, size);
return !!(eqe->owner & 0x80) ^ !!(eq->cons_index & eq->nent) ? NULL : eqe;
}
static struct mlx4_eqe *next_slave_event_eqe(struct mlx4_slave_event_eq *slave_eq)
{
struct mlx4_eqe *eqe =
&slave_eq->event_eqe[slave_eq->cons & (SLAVE_EVENT_EQ_SIZE - 1)];
return (!!(eqe->owner & 0x80) ^
!!(slave_eq->cons & SLAVE_EVENT_EQ_SIZE)) ?
eqe : NULL;
}
void mlx4_gen_slave_eqe(struct work_struct *work)
{
struct mlx4_mfunc_master_ctx *master =
container_of(work, struct mlx4_mfunc_master_ctx,
slave_event_work);
struct mlx4_mfunc *mfunc =
container_of(master, struct mlx4_mfunc, master);
struct mlx4_priv *priv = container_of(mfunc, struct mlx4_priv, mfunc);
struct mlx4_dev *dev = &priv->dev;
struct mlx4_slave_event_eq *slave_eq = &mfunc->master.slave_eq;
struct mlx4_eqe *eqe;
u8 slave;
int i, phys_port, slave_port;
for (eqe = next_slave_event_eqe(slave_eq); eqe;
eqe = next_slave_event_eqe(slave_eq)) {
slave = eqe->slave_id;
if (slave == ALL_SLAVES) {
for (i = 0; i <= dev->persist->num_vfs; i++) {
phys_port = 0;
if (eqe->type == MLX4_EVENT_TYPE_PORT_MNG_CHG_EVENT &&
eqe->subtype == MLX4_DEV_PMC_SUBTYPE_PORT_INFO) {
phys_port = eqe->event.port_mgmt_change.port;
slave_port = mlx4_phys_to_slave_port(dev, i, phys_port);
if (slave_port < 0)
continue;
eqe->event.port_mgmt_change.port = slave_port;
}
if (mlx4_GEN_EQE(dev, i, eqe))
mlx4_warn(dev, "Failed to generate event for slave %d\n",
i);
if (phys_port)
eqe->event.port_mgmt_change.port = phys_port;
}
} else {
if (mlx4_GEN_EQE(dev, slave, eqe))
mlx4_warn(dev, "Failed to generate event for slave %d\n",
slave);
}
++slave_eq->cons;
}
}
static void slave_event(struct mlx4_dev *dev, u8 slave, struct mlx4_eqe *eqe)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_slave_event_eq *slave_eq = &priv->mfunc.master.slave_eq;
struct mlx4_eqe *s_eqe;
unsigned long flags;
spin_lock_irqsave(&slave_eq->event_lock, flags);
s_eqe = &slave_eq->event_eqe[slave_eq->prod & (SLAVE_EVENT_EQ_SIZE - 1)];
if ((!!(s_eqe->owner & 0x80)) ^
(!!(slave_eq->prod & SLAVE_EVENT_EQ_SIZE))) {
mlx4_warn(dev, "Master failed to generate an EQE for slave: %d. No free EQE on slave events queue\n",
slave);
spin_unlock_irqrestore(&slave_eq->event_lock, flags);
return;
}
memcpy(s_eqe, eqe, dev->caps.eqe_size - 1);
s_eqe->slave_id = slave;
dma_wmb();
s_eqe->owner = !!(slave_eq->prod & SLAVE_EVENT_EQ_SIZE) ? 0x0 : 0x80;
++slave_eq->prod;
queue_work(priv->mfunc.master.comm_wq,
&priv->mfunc.master.slave_event_work);
spin_unlock_irqrestore(&slave_eq->event_lock, flags);
}
static void mlx4_slave_event(struct mlx4_dev *dev, int slave,
struct mlx4_eqe *eqe)
{
struct mlx4_priv *priv = mlx4_priv(dev);
if (slave < 0 || slave > dev->persist->num_vfs ||
slave == dev->caps.function ||
!priv->mfunc.master.slave_state[slave].active)
return;
slave_event(dev, slave, eqe);
}
static void mlx4_set_eq_affinity_hint(struct mlx4_priv *priv, int vec)
{
int hint_err;
struct mlx4_dev *dev = &priv->dev;
struct mlx4_eq *eq = &priv->eq_table.eq[vec];
if (!eq->affinity_mask || cpumask_empty(eq->affinity_mask))
return;
hint_err = irq_set_affinity_hint(eq->irq, eq->affinity_mask);
if (hint_err)
mlx4_warn(dev, "irq_set_affinity_hint failed, err %d\n", hint_err);
}
int mlx4_gen_pkey_eqe(struct mlx4_dev *dev, int slave, u8 port)
{
struct mlx4_eqe eqe;
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_slave_state *s_slave = &priv->mfunc.master.slave_state[slave];
if (!s_slave->active)
return 0;
memset(&eqe, 0, sizeof eqe);
eqe.type = MLX4_EVENT_TYPE_PORT_MNG_CHG_EVENT;
eqe.subtype = MLX4_DEV_PMC_SUBTYPE_PKEY_TABLE;
eqe.event.port_mgmt_change.port = mlx4_phys_to_slave_port(dev, slave, port);
return mlx4_GEN_EQE(dev, slave, &eqe);
}
int mlx4_gen_guid_change_eqe(struct mlx4_dev *dev, int slave, u8 port)
{
struct mlx4_eqe eqe;
if (dev->persist->num_vfs < slave)
return 0;
memset(&eqe, 0, sizeof eqe);
eqe.type = MLX4_EVENT_TYPE_PORT_MNG_CHG_EVENT;
eqe.subtype = MLX4_DEV_PMC_SUBTYPE_GUID_INFO;
eqe.event.port_mgmt_change.port = mlx4_phys_to_slave_port(dev, slave, port);
return mlx4_GEN_EQE(dev, slave, &eqe);
}
int mlx4_gen_port_state_change_eqe(struct mlx4_dev *dev, int slave, u8 port,
u8 port_subtype_change)
{
struct mlx4_eqe eqe;
u8 slave_port = mlx4_phys_to_slave_port(dev, slave, port);
if (dev->persist->num_vfs < slave)
return 0;
memset(&eqe, 0, sizeof eqe);
eqe.type = MLX4_EVENT_TYPE_PORT_CHANGE;
eqe.subtype = port_subtype_change;
eqe.event.port_change.port = cpu_to_be32(slave_port << 28);
mlx4_dbg(dev, "%s: sending: %d to slave: %d on port: %d\n", __func__,
port_subtype_change, slave, port);
return mlx4_GEN_EQE(dev, slave, &eqe);
}
enum slave_port_state mlx4_get_slave_port_state(struct mlx4_dev *dev, int slave, u8 port)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_slave_state *s_state = priv->mfunc.master.slave_state;
struct mlx4_active_ports actv_ports = mlx4_get_active_ports(dev, slave);
if (slave >= dev->num_slaves || port > dev->caps.num_ports ||
port <= 0 || !test_bit(port - 1, actv_ports.ports)) {
pr_err("%s: Error: asking for slave:%d, port:%d\n",
__func__, slave, port);
return SLAVE_PORT_DOWN;
}
return s_state[slave].port_state[port];
}
static int mlx4_set_slave_port_state(struct mlx4_dev *dev, int slave, u8 port,
enum slave_port_state state)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_slave_state *s_state = priv->mfunc.master.slave_state;
struct mlx4_active_ports actv_ports = mlx4_get_active_ports(dev, slave);
if (slave >= dev->num_slaves || port > dev->caps.num_ports ||
port <= 0 || !test_bit(port - 1, actv_ports.ports)) {
pr_err("%s: Error: asking for slave:%d, port:%d\n",
__func__, slave, port);
return -1;
}
s_state[slave].port_state[port] = state;
return 0;
}
static void set_all_slave_state(struct mlx4_dev *dev, u8 port, int event)
{
int i;
enum slave_port_gen_event gen_event;
struct mlx4_slaves_pport slaves_pport = mlx4_phys_to_slaves_pport(dev,
port);
for (i = 0; i < dev->persist->num_vfs + 1; i++)
if (test_bit(i, slaves_pport.slaves))
set_and_calc_slave_port_state(dev, i, port,
event, &gen_event);
}
int set_and_calc_slave_port_state(struct mlx4_dev *dev, int slave,
u8 port, int event,
enum slave_port_gen_event *gen_event)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_slave_state *ctx = NULL;
unsigned long flags;
int ret = -1;
struct mlx4_active_ports actv_ports = mlx4_get_active_ports(dev, slave);
enum slave_port_state cur_state =
mlx4_get_slave_port_state(dev, slave, port);
*gen_event = SLAVE_PORT_GEN_EVENT_NONE;
if (slave >= dev->num_slaves || port > dev->caps.num_ports ||
port <= 0 || !test_bit(port - 1, actv_ports.ports)) {
pr_err("%s: Error: asking for slave:%d, port:%d\n",
__func__, slave, port);
return ret;
}
ctx = &priv->mfunc.master.slave_state[slave];
spin_lock_irqsave(&ctx->lock, flags);
switch (cur_state) {
case SLAVE_PORT_DOWN:
if (MLX4_PORT_STATE_DEV_EVENT_PORT_UP == event)
mlx4_set_slave_port_state(dev, slave, port,
SLAVE_PENDING_UP);
break;
case SLAVE_PENDING_UP:
if (MLX4_PORT_STATE_DEV_EVENT_PORT_DOWN == event)
mlx4_set_slave_port_state(dev, slave, port,
SLAVE_PORT_DOWN);
else if (MLX4_PORT_STATE_IB_PORT_STATE_EVENT_GID_VALID == event) {
mlx4_set_slave_port_state(dev, slave, port,
SLAVE_PORT_UP);
*gen_event = SLAVE_PORT_GEN_EVENT_UP;
}
break;
case SLAVE_PORT_UP:
if (MLX4_PORT_STATE_DEV_EVENT_PORT_DOWN == event) {
mlx4_set_slave_port_state(dev, slave, port,
SLAVE_PORT_DOWN);
*gen_event = SLAVE_PORT_GEN_EVENT_DOWN;
} else if (MLX4_PORT_STATE_IB_EVENT_GID_INVALID ==
event) {
mlx4_set_slave_port_state(dev, slave, port,
SLAVE_PENDING_UP);
*gen_event = SLAVE_PORT_GEN_EVENT_DOWN;
}
break;
default:
pr_err("%s: BUG!!! UNKNOWN state: slave:%d, port:%d\n",
__func__, slave, port);
goto out;
}
ret = mlx4_get_slave_port_state(dev, slave, port);
out:
spin_unlock_irqrestore(&ctx->lock, flags);
return ret;
}
int mlx4_gen_slaves_port_mgt_ev(struct mlx4_dev *dev, u8 port, int attr)
{
struct mlx4_eqe eqe;
memset(&eqe, 0, sizeof eqe);
eqe.type = MLX4_EVENT_TYPE_PORT_MNG_CHG_EVENT;
eqe.subtype = MLX4_DEV_PMC_SUBTYPE_PORT_INFO;
eqe.event.port_mgmt_change.port = port;
eqe.event.port_mgmt_change.params.port_info.changed_attr =
cpu_to_be32((u32) attr);
slave_event(dev, ALL_SLAVES, &eqe);
return 0;
}
void mlx4_master_handle_slave_flr(struct work_struct *work)
{
struct mlx4_mfunc_master_ctx *master =
container_of(work, struct mlx4_mfunc_master_ctx,
slave_flr_event_work);
struct mlx4_mfunc *mfunc =
container_of(master, struct mlx4_mfunc, master);
struct mlx4_priv *priv =
container_of(mfunc, struct mlx4_priv, mfunc);
struct mlx4_dev *dev = &priv->dev;
struct mlx4_slave_state *slave_state = priv->mfunc.master.slave_state;
int i;
int err;
unsigned long flags;
mlx4_dbg(dev, "mlx4_handle_slave_flr\n");
for (i = 0 ; i < dev->num_slaves; i++) {
if (MLX4_COMM_CMD_FLR == slave_state[i].last_cmd) {
mlx4_dbg(dev, "mlx4_handle_slave_flr: clean slave: %d\n",
i);
if (dev->persist->interface_state &
MLX4_INTERFACE_STATE_UP)
mlx4_delete_all_resources_for_slave(dev, i);
spin_lock_irqsave(&priv->mfunc.master.slave_state_lock, flags);
slave_state[i].last_cmd = MLX4_COMM_CMD_RESET;
slave_state[i].is_slave_going_down = 0;
spin_unlock_irqrestore(&priv->mfunc.master.slave_state_lock, flags);
err = mlx4_cmd(dev, 0, i, 0, MLX4_CMD_INFORM_FLR_DONE,
MLX4_CMD_TIME_CLASS_A, MLX4_CMD_WRAPPED);
if (err)
mlx4_warn(dev, "Failed to notify FW on FLR done (slave:%d)\n",
i);
}
}
}
static int mlx4_eq_int(struct mlx4_dev *dev, struct mlx4_eq *eq)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_eqe *eqe;
int cqn = -1;
int eqes_found = 0;
int set_ci = 0;
int port;
int slave = 0;
int ret;
u32 flr_slave;
u8 update_slave_state;
int i;
enum slave_port_gen_event gen_event;
unsigned long flags;
struct mlx4_vport_state *s_info;
int eqe_size = dev->caps.eqe_size;
while ((eqe = next_eqe_sw(eq, dev->caps.eqe_factor, eqe_size))) {
dma_rmb();
switch (eqe->type) {
case MLX4_EVENT_TYPE_COMP:
cqn = be32_to_cpu(eqe->event.comp.cqn) & 0xffffff;
mlx4_cq_completion(dev, cqn);
break;
case MLX4_EVENT_TYPE_PATH_MIG:
case MLX4_EVENT_TYPE_COMM_EST:
case MLX4_EVENT_TYPE_SQ_DRAINED:
case MLX4_EVENT_TYPE_SRQ_QP_LAST_WQE:
case MLX4_EVENT_TYPE_WQ_CATAS_ERROR:
case MLX4_EVENT_TYPE_PATH_MIG_FAILED:
case MLX4_EVENT_TYPE_WQ_INVAL_REQ_ERROR:
case MLX4_EVENT_TYPE_WQ_ACCESS_ERROR:
mlx4_dbg(dev, "event %d arrived\n", eqe->type);
if (mlx4_is_master(dev)) {
ret = mlx4_get_slave_from_resource_id(dev,
RES_QP,
be32_to_cpu(eqe->event.qp.qpn)
& 0xffffff, &slave);
if (ret && ret != -ENOENT) {
mlx4_dbg(dev, "QP event %02x(%02x) on EQ %d at index %u: could not get slave id (%d)\n",
eqe->type, eqe->subtype,
eq->eqn, eq->cons_index, ret);
break;
}
if (!ret && slave != dev->caps.function) {
mlx4_slave_event(dev, slave, eqe);
break;
}
}
mlx4_qp_event(dev, be32_to_cpu(eqe->event.qp.qpn) &
0xffffff, eqe->type);
break;
case MLX4_EVENT_TYPE_SRQ_LIMIT:
mlx4_dbg(dev, "%s: MLX4_EVENT_TYPE_SRQ_LIMIT\n",
__func__);
case MLX4_EVENT_TYPE_SRQ_CATAS_ERROR:
if (mlx4_is_master(dev)) {
ret = mlx4_get_slave_from_resource_id(dev,
RES_SRQ,
be32_to_cpu(eqe->event.srq.srqn)
& 0xffffff,
&slave);
if (ret && ret != -ENOENT) {
mlx4_warn(dev, "SRQ event %02x(%02x) on EQ %d at index %u: could not get slave id (%d)\n",
eqe->type, eqe->subtype,
eq->eqn, eq->cons_index, ret);
break;
}
mlx4_warn(dev, "%s: slave:%d, srq_no:0x%x, event: %02x(%02x)\n",
__func__, slave,
be32_to_cpu(eqe->event.srq.srqn),
eqe->type, eqe->subtype);
if (!ret && slave != dev->caps.function) {
mlx4_warn(dev, "%s: sending event %02x(%02x) to slave:%d\n",
__func__, eqe->type,
eqe->subtype, slave);
mlx4_slave_event(dev, slave, eqe);
break;
}
}
mlx4_srq_event(dev, be32_to_cpu(eqe->event.srq.srqn) &
0xffffff, eqe->type);
break;
case MLX4_EVENT_TYPE_CMD:
mlx4_cmd_event(dev,
be16_to_cpu(eqe->event.cmd.token),
eqe->event.cmd.status,
be64_to_cpu(eqe->event.cmd.out_param));
break;
case MLX4_EVENT_TYPE_PORT_CHANGE: {
struct mlx4_slaves_pport slaves_port;
port = be32_to_cpu(eqe->event.port_change.port) >> 28;
slaves_port = mlx4_phys_to_slaves_pport(dev, port);
if (eqe->subtype == MLX4_PORT_CHANGE_SUBTYPE_DOWN) {
mlx4_dispatch_event(dev, MLX4_DEV_EVENT_PORT_DOWN,
port);
mlx4_priv(dev)->sense.do_sense_port[port] = 1;
if (!mlx4_is_master(dev))
break;
for (i = 0; i < dev->persist->num_vfs + 1;
i++) {
if (!test_bit(i, slaves_port.slaves))
continue;
if (dev->caps.port_type[port] == MLX4_PORT_TYPE_ETH) {
if (i == mlx4_master_func_num(dev))
continue;
mlx4_dbg(dev, "%s: Sending MLX4_PORT_CHANGE_SUBTYPE_DOWN to slave: %d, port:%d\n",
__func__, i, port);
s_info = &priv->mfunc.master.vf_oper[i].vport[port].state;
if (IFLA_VF_LINK_STATE_AUTO == s_info->link_state) {
eqe->event.port_change.port =
cpu_to_be32(
(be32_to_cpu(eqe->event.port_change.port) & 0xFFFFFFF)
| (mlx4_phys_to_slave_port(dev, i, port) << 28));
mlx4_slave_event(dev, i, eqe);
}
} else {
set_and_calc_slave_port_state(dev, i, port,
MLX4_PORT_STATE_DEV_EVENT_PORT_DOWN,
&gen_event);
if (SLAVE_PORT_GEN_EVENT_DOWN == gen_event) {
if (i == mlx4_master_func_num(dev))
continue;
eqe->event.port_change.port =
cpu_to_be32(
(be32_to_cpu(eqe->event.port_change.port) & 0xFFFFFFF)
| (mlx4_phys_to_slave_port(dev, i, port) << 28));
mlx4_slave_event(dev, i, eqe);
}
}
}
} else {
mlx4_dispatch_event(dev, MLX4_DEV_EVENT_PORT_UP, port);
mlx4_priv(dev)->sense.do_sense_port[port] = 0;
if (!mlx4_is_master(dev))
break;
if (dev->caps.port_type[port] == MLX4_PORT_TYPE_ETH)
for (i = 0;
i < dev->persist->num_vfs + 1;
i++) {
if (!test_bit(i, slaves_port.slaves))
continue;
if (i == mlx4_master_func_num(dev))
continue;
s_info = &priv->mfunc.master.vf_oper[i].vport[port].state;
if (IFLA_VF_LINK_STATE_AUTO == s_info->link_state) {
eqe->event.port_change.port =
cpu_to_be32(
(be32_to_cpu(eqe->event.port_change.port) & 0xFFFFFFF)
| (mlx4_phys_to_slave_port(dev, i, port) << 28));
mlx4_slave_event(dev, i, eqe);
}
}
else
set_all_slave_state(dev, port, MLX4_DEV_EVENT_PORT_UP);
}
break;
}
case MLX4_EVENT_TYPE_CQ_ERROR:
mlx4_warn(dev, "CQ %s on CQN %06x\n",
eqe->event.cq_err.syndrome == 1 ?
"overrun" : "access violation",
be32_to_cpu(eqe->event.cq_err.cqn) & 0xffffff);
if (mlx4_is_master(dev)) {
ret = mlx4_get_slave_from_resource_id(dev,
RES_CQ,
be32_to_cpu(eqe->event.cq_err.cqn)
& 0xffffff, &slave);
if (ret && ret != -ENOENT) {
mlx4_dbg(dev, "CQ event %02x(%02x) on EQ %d at index %u: could not get slave id (%d)\n",
eqe->type, eqe->subtype,
eq->eqn, eq->cons_index, ret);
break;
}
if (!ret && slave != dev->caps.function) {
mlx4_slave_event(dev, slave, eqe);
break;
}
}
mlx4_cq_event(dev,
be32_to_cpu(eqe->event.cq_err.cqn)
& 0xffffff,
eqe->type);
break;
case MLX4_EVENT_TYPE_EQ_OVERFLOW:
mlx4_warn(dev, "EQ overrun on EQN %d\n", eq->eqn);
break;
case MLX4_EVENT_TYPE_OP_REQUIRED:
atomic_inc(&priv->opreq_count);
queue_work(mlx4_wq, &priv->opreq_task);
break;
case MLX4_EVENT_TYPE_COMM_CHANNEL:
if (!mlx4_is_master(dev)) {
mlx4_warn(dev, "Received comm channel event for non master device\n");
break;
}
memcpy(&priv->mfunc.master.comm_arm_bit_vector,
eqe->event.comm_channel_arm.bit_vec,
sizeof eqe->event.comm_channel_arm.bit_vec);
queue_work(priv->mfunc.master.comm_wq,
&priv->mfunc.master.comm_work);
break;
case MLX4_EVENT_TYPE_FLR_EVENT:
flr_slave = be32_to_cpu(eqe->event.flr_event.slave_id);
if (!mlx4_is_master(dev)) {
mlx4_warn(dev, "Non-master function received FLR event\n");
break;
}
mlx4_dbg(dev, "FLR event for slave: %d\n", flr_slave);
if (flr_slave >= dev->num_slaves) {
mlx4_warn(dev,
"Got FLR for unknown function: %d\n",
flr_slave);
update_slave_state = 0;
} else
update_slave_state = 1;
spin_lock_irqsave(&priv->mfunc.master.slave_state_lock, flags);
if (update_slave_state) {
priv->mfunc.master.slave_state[flr_slave].active = false;
priv->mfunc.master.slave_state[flr_slave].last_cmd = MLX4_COMM_CMD_FLR;
priv->mfunc.master.slave_state[flr_slave].is_slave_going_down = 1;
}
spin_unlock_irqrestore(&priv->mfunc.master.slave_state_lock, flags);
mlx4_dispatch_event(dev, MLX4_DEV_EVENT_SLAVE_SHUTDOWN,
flr_slave);
queue_work(priv->mfunc.master.comm_wq,
&priv->mfunc.master.slave_flr_event_work);
break;
case MLX4_EVENT_TYPE_FATAL_WARNING:
if (eqe->subtype == MLX4_FATAL_WARNING_SUBTYPE_WARMING) {
if (mlx4_is_master(dev))
for (i = 0; i < dev->num_slaves; i++) {
mlx4_dbg(dev, "%s: Sending MLX4_FATAL_WARNING_SUBTYPE_WARMING to slave: %d\n",
__func__, i);
if (i == dev->caps.function)
continue;
mlx4_slave_event(dev, i, eqe);
}
mlx4_err(dev, "Temperature Threshold was reached! Threshold: %d celsius degrees; Current Temperature: %d\n",
be16_to_cpu(eqe->event.warming.warning_threshold),
be16_to_cpu(eqe->event.warming.current_temperature));
} else
mlx4_warn(dev, "Unhandled event FATAL WARNING (%02x), subtype %02x on EQ %d at index %u. owner=%x, nent=0x%x, slave=%x, ownership=%s\n",
eqe->type, eqe->subtype, eq->eqn,
eq->cons_index, eqe->owner, eq->nent,
eqe->slave_id,
!!(eqe->owner & 0x80) ^
!!(eq->cons_index & eq->nent) ? "HW" : "SW");
break;
case MLX4_EVENT_TYPE_PORT_MNG_CHG_EVENT:
mlx4_dispatch_event(dev, MLX4_DEV_EVENT_PORT_MGMT_CHANGE,
(unsigned long) eqe);
break;
case MLX4_EVENT_TYPE_RECOVERABLE_ERROR_EVENT:
switch (eqe->subtype) {
case MLX4_RECOVERABLE_ERROR_EVENT_SUBTYPE_BAD_CABLE:
mlx4_warn(dev, "Bad cable detected on port %u\n",
eqe->event.bad_cable.port);
break;
case MLX4_RECOVERABLE_ERROR_EVENT_SUBTYPE_UNSUPPORTED_CABLE:
mlx4_warn(dev, "Unsupported cable detected\n");
break;
default:
mlx4_dbg(dev,
"Unhandled recoverable error event detected: %02x(%02x) on EQ %d at index %u. owner=%x, nent=0x%x, ownership=%s\n",
eqe->type, eqe->subtype, eq->eqn,
eq->cons_index, eqe->owner, eq->nent,
!!(eqe->owner & 0x80) ^
!!(eq->cons_index & eq->nent) ? "HW" : "SW");
break;
}
break;
case MLX4_EVENT_TYPE_EEC_CATAS_ERROR:
case MLX4_EVENT_TYPE_ECC_DETECT:
default:
mlx4_warn(dev, "Unhandled event %02x(%02x) on EQ %d at index %u. owner=%x, nent=0x%x, slave=%x, ownership=%s\n",
eqe->type, eqe->subtype, eq->eqn,
eq->cons_index, eqe->owner, eq->nent,
eqe->slave_id,
!!(eqe->owner & 0x80) ^
!!(eq->cons_index & eq->nent) ? "HW" : "SW");
break;
};
++eq->cons_index;
eqes_found = 1;
++set_ci;
if (unlikely(set_ci >= MLX4_NUM_SPARE_EQE)) {
eq_set_ci(eq, 0);
set_ci = 0;
}
}
eq_set_ci(eq, 1);
if (!(cqn & ~0xffffff))
tasklet_schedule(&eq->tasklet_ctx.task);
return eqes_found;
}
static irqreturn_t mlx4_interrupt(int irq, void *dev_ptr)
{
struct mlx4_dev *dev = dev_ptr;
struct mlx4_priv *priv = mlx4_priv(dev);
int work = 0;
int i;
writel(priv->eq_table.clr_mask, priv->eq_table.clr_int);
for (i = 0; i < dev->caps.num_comp_vectors + 1; ++i)
work |= mlx4_eq_int(dev, &priv->eq_table.eq[i]);
return IRQ_RETVAL(work);
}
static irqreturn_t mlx4_msi_x_interrupt(int irq, void *eq_ptr)
{
struct mlx4_eq *eq = eq_ptr;
struct mlx4_dev *dev = eq->dev;
mlx4_eq_int(dev, eq);
return IRQ_HANDLED;
}
int mlx4_MAP_EQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_slave_event_eq_info *event_eq =
priv->mfunc.master.slave_state[slave].event_eq;
u32 in_modifier = vhcr->in_modifier;
u32 eqn = in_modifier & 0x3FF;
u64 in_param = vhcr->in_param;
int err = 0;
int i;
if (slave == dev->caps.function)
err = mlx4_cmd(dev, in_param, (in_modifier & 0x80000000) | eqn,
0, MLX4_CMD_MAP_EQ, MLX4_CMD_TIME_CLASS_B,
MLX4_CMD_NATIVE);
if (!err)
for (i = 0; i < MLX4_EVENT_TYPES_NUM; ++i)
if (in_param & (1LL << i))
event_eq[i].eqn = in_modifier >> 31 ? -1 : eqn;
return err;
}
static int mlx4_MAP_EQ(struct mlx4_dev *dev, u64 event_mask, int unmap,
int eq_num)
{
return mlx4_cmd(dev, event_mask, (unmap << 31) | eq_num,
0, MLX4_CMD_MAP_EQ, MLX4_CMD_TIME_CLASS_B,
MLX4_CMD_WRAPPED);
}
static int mlx4_SW2HW_EQ(struct mlx4_dev *dev, struct mlx4_cmd_mailbox *mailbox,
int eq_num)
{
return mlx4_cmd(dev, mailbox->dma, eq_num, 0,
MLX4_CMD_SW2HW_EQ, MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_WRAPPED);
}
static int mlx4_HW2SW_EQ(struct mlx4_dev *dev, int eq_num)
{
return mlx4_cmd(dev, 0, eq_num, 1, MLX4_CMD_HW2SW_EQ,
MLX4_CMD_TIME_CLASS_A, MLX4_CMD_WRAPPED);
}
static int mlx4_num_eq_uar(struct mlx4_dev *dev)
{
return (dev->caps.num_comp_vectors + 1 + dev->caps.reserved_eqs) / 4 -
dev->caps.reserved_eqs / 4 + 1;
}
static void __iomem *mlx4_get_eq_uar(struct mlx4_dev *dev, struct mlx4_eq *eq)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int index;
index = eq->eqn / 4 - dev->caps.reserved_eqs / 4;
if (!priv->eq_table.uar_map[index]) {
priv->eq_table.uar_map[index] =
ioremap(pci_resource_start(dev->persist->pdev, 2) +
((eq->eqn / 4) << PAGE_SHIFT),
PAGE_SIZE);
if (!priv->eq_table.uar_map[index]) {
mlx4_err(dev, "Couldn't map EQ doorbell for EQN 0x%06x\n",
eq->eqn);
return NULL;
}
}
return priv->eq_table.uar_map[index] + 0x800 + 8 * (eq->eqn % 4);
}
static void mlx4_unmap_uar(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int i;
for (i = 0; i < mlx4_num_eq_uar(dev); ++i)
if (priv->eq_table.uar_map[i]) {
iounmap(priv->eq_table.uar_map[i]);
priv->eq_table.uar_map[i] = NULL;
}
}
static int mlx4_create_eq(struct mlx4_dev *dev, int nent,
u8 intr, struct mlx4_eq *eq)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_eq_context *eq_context;
int npages;
u64 *dma_list = NULL;
dma_addr_t t;
u64 mtt_addr;
int err = -ENOMEM;
int i;
eq->dev = dev;
eq->nent = roundup_pow_of_two(max(nent, 2));
npages = PAGE_ALIGN(eq->nent * dev->caps.eqe_size) / PAGE_SIZE;
eq->page_list = kmalloc(npages * sizeof *eq->page_list,
GFP_KERNEL);
if (!eq->page_list)
goto err_out;
for (i = 0; i < npages; ++i)
eq->page_list[i].buf = NULL;
dma_list = kmalloc(npages * sizeof *dma_list, GFP_KERNEL);
if (!dma_list)
goto err_out_free;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
goto err_out_free;
eq_context = mailbox->buf;
for (i = 0; i < npages; ++i) {
eq->page_list[i].buf = dma_alloc_coherent(&dev->persist->
pdev->dev,
PAGE_SIZE, &t,
GFP_KERNEL);
if (!eq->page_list[i].buf)
goto err_out_free_pages;
dma_list[i] = t;
eq->page_list[i].map = t;
memset(eq->page_list[i].buf, 0, PAGE_SIZE);
}
eq->eqn = mlx4_bitmap_alloc(&priv->eq_table.bitmap);
if (eq->eqn == -1)
goto err_out_free_pages;
eq->doorbell = mlx4_get_eq_uar(dev, eq);
if (!eq->doorbell) {
err = -ENOMEM;
goto err_out_free_eq;
}
err = mlx4_mtt_init(dev, npages, PAGE_SHIFT, &eq->mtt);
if (err)
goto err_out_free_eq;
err = mlx4_write_mtt(dev, &eq->mtt, 0, npages, dma_list);
if (err)
goto err_out_free_mtt;
eq_context->flags = cpu_to_be32(MLX4_EQ_STATUS_OK |
MLX4_EQ_STATE_ARMED);
eq_context->log_eq_size = ilog2(eq->nent);
eq_context->intr = intr;
eq_context->log_page_size = PAGE_SHIFT - MLX4_ICM_PAGE_SHIFT;
mtt_addr = mlx4_mtt_addr(dev, &eq->mtt);
eq_context->mtt_base_addr_h = mtt_addr >> 32;
eq_context->mtt_base_addr_l = cpu_to_be32(mtt_addr & 0xffffffff);
err = mlx4_SW2HW_EQ(dev, mailbox, eq->eqn);
if (err) {
mlx4_warn(dev, "SW2HW_EQ failed (%d)\n", err);
goto err_out_free_mtt;
}
kfree(dma_list);
mlx4_free_cmd_mailbox(dev, mailbox);
eq->cons_index = 0;
INIT_LIST_HEAD(&eq->tasklet_ctx.list);
INIT_LIST_HEAD(&eq->tasklet_ctx.process_list);
spin_lock_init(&eq->tasklet_ctx.lock);
tasklet_init(&eq->tasklet_ctx.task, mlx4_cq_tasklet_cb,
(unsigned long)&eq->tasklet_ctx);
return err;
err_out_free_mtt:
mlx4_mtt_cleanup(dev, &eq->mtt);
err_out_free_eq:
mlx4_bitmap_free(&priv->eq_table.bitmap, eq->eqn, MLX4_USE_RR);
err_out_free_pages:
for (i = 0; i < npages; ++i)
if (eq->page_list[i].buf)
dma_free_coherent(&dev->persist->pdev->dev, PAGE_SIZE,
eq->page_list[i].buf,
eq->page_list[i].map);
mlx4_free_cmd_mailbox(dev, mailbox);
err_out_free:
kfree(eq->page_list);
kfree(dma_list);
err_out:
return err;
}
static void mlx4_free_eq(struct mlx4_dev *dev,
struct mlx4_eq *eq)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int err;
int i;
int npages = PAGE_ALIGN(dev->caps.eqe_size * eq->nent) / PAGE_SIZE;
err = mlx4_HW2SW_EQ(dev, eq->eqn);
if (err)
mlx4_warn(dev, "HW2SW_EQ failed (%d)\n", err);
synchronize_irq(eq->irq);
tasklet_disable(&eq->tasklet_ctx.task);
mlx4_mtt_cleanup(dev, &eq->mtt);
for (i = 0; i < npages; ++i)
dma_free_coherent(&dev->persist->pdev->dev, PAGE_SIZE,
eq->page_list[i].buf,
eq->page_list[i].map);
kfree(eq->page_list);
mlx4_bitmap_free(&priv->eq_table.bitmap, eq->eqn, MLX4_USE_RR);
}
static void mlx4_free_irqs(struct mlx4_dev *dev)
{
struct mlx4_eq_table *eq_table = &mlx4_priv(dev)->eq_table;
int i;
if (eq_table->have_irq)
free_irq(dev->persist->pdev->irq, dev);
for (i = 0; i < dev->caps.num_comp_vectors + 1; ++i)
if (eq_table->eq[i].have_irq) {
free_cpumask_var(eq_table->eq[i].affinity_mask);
#if defined(CONFIG_SMP)
irq_set_affinity_hint(eq_table->eq[i].irq, NULL);
#endif
free_irq(eq_table->eq[i].irq, eq_table->eq + i);
eq_table->eq[i].have_irq = 0;
}
kfree(eq_table->irq_names);
}
static int mlx4_map_clr_int(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
priv->clr_base = ioremap(pci_resource_start(dev->persist->pdev,
priv->fw.clr_int_bar) +
priv->fw.clr_int_base, MLX4_CLR_INT_SIZE);
if (!priv->clr_base) {
mlx4_err(dev, "Couldn't map interrupt clear register, aborting\n");
return -ENOMEM;
}
return 0;
}
static void mlx4_unmap_clr_int(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
iounmap(priv->clr_base);
}
int mlx4_alloc_eq_table(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
priv->eq_table.eq = kcalloc(dev->caps.num_eqs - dev->caps.reserved_eqs,
sizeof *priv->eq_table.eq, GFP_KERNEL);
if (!priv->eq_table.eq)
return -ENOMEM;
return 0;
}
void mlx4_free_eq_table(struct mlx4_dev *dev)
{
kfree(mlx4_priv(dev)->eq_table.eq);
}
int mlx4_init_eq_table(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int err;
int i;
priv->eq_table.uar_map = kcalloc(mlx4_num_eq_uar(dev),
sizeof *priv->eq_table.uar_map,
GFP_KERNEL);
if (!priv->eq_table.uar_map) {
err = -ENOMEM;
goto err_out_free;
}
err = mlx4_bitmap_init(&priv->eq_table.bitmap,
roundup_pow_of_two(dev->caps.num_eqs),
dev->caps.num_eqs - 1,
dev->caps.reserved_eqs,
roundup_pow_of_two(dev->caps.num_eqs) -
dev->caps.num_eqs);
if (err)
goto err_out_free;
for (i = 0; i < mlx4_num_eq_uar(dev); ++i)
priv->eq_table.uar_map[i] = NULL;
if (!mlx4_is_slave(dev)) {
err = mlx4_map_clr_int(dev);
if (err)
goto err_out_bitmap;
priv->eq_table.clr_mask =
swab32(1 << (priv->eq_table.inta_pin & 31));
priv->eq_table.clr_int = priv->clr_base +
(priv->eq_table.inta_pin < 32 ? 4 : 0);
}
priv->eq_table.irq_names =
kmalloc(MLX4_IRQNAME_SIZE * (dev->caps.num_comp_vectors + 1),
GFP_KERNEL);
if (!priv->eq_table.irq_names) {
err = -ENOMEM;
goto err_out_clr_int;
}
for (i = 0; i < dev->caps.num_comp_vectors + 1; ++i) {
if (i == MLX4_EQ_ASYNC) {
err = mlx4_create_eq(dev,
MLX4_NUM_ASYNC_EQE + MLX4_NUM_SPARE_EQE,
0, &priv->eq_table.eq[MLX4_EQ_ASYNC]);
} else {
struct mlx4_eq *eq = &priv->eq_table.eq[i];
#ifdef CONFIG_RFS_ACCEL
int port = find_first_bit(eq->actv_ports.ports,
dev->caps.num_ports) + 1;
if (port <= dev->caps.num_ports) {
struct mlx4_port_info *info =
&mlx4_priv(dev)->port[port];
if (!info->rmap) {
info->rmap = alloc_irq_cpu_rmap(
mlx4_get_eqs_per_port(dev, port));
if (!info->rmap) {
mlx4_warn(dev, "Failed to allocate cpu rmap\n");
err = -ENOMEM;
goto err_out_unmap;
}
}
err = irq_cpu_rmap_add(
info->rmap, eq->irq);
if (err)
mlx4_warn(dev, "Failed adding irq rmap\n");
}
#endif
err = mlx4_create_eq(dev, dev->caps.num_cqs -
dev->caps.reserved_cqs +
MLX4_NUM_SPARE_EQE,
(dev->flags & MLX4_FLAG_MSI_X) ?
i + 1 - !!(i > MLX4_EQ_ASYNC) : 0,
eq);
}
if (err)
goto err_out_unmap;
}
if (dev->flags & MLX4_FLAG_MSI_X) {
const char *eq_name;
snprintf(priv->eq_table.irq_names +
MLX4_EQ_ASYNC * MLX4_IRQNAME_SIZE,
MLX4_IRQNAME_SIZE,
"mlx4-async@pci:%s",
pci_name(dev->persist->pdev));
eq_name = priv->eq_table.irq_names +
MLX4_EQ_ASYNC * MLX4_IRQNAME_SIZE;
err = request_irq(priv->eq_table.eq[MLX4_EQ_ASYNC].irq,
mlx4_msi_x_interrupt, 0, eq_name,
priv->eq_table.eq + MLX4_EQ_ASYNC);
if (err)
goto err_out_unmap;
priv->eq_table.eq[MLX4_EQ_ASYNC].have_irq = 1;
} else {
snprintf(priv->eq_table.irq_names,
MLX4_IRQNAME_SIZE,
DRV_NAME "@pci:%s",
pci_name(dev->persist->pdev));
err = request_irq(dev->persist->pdev->irq, mlx4_interrupt,
IRQF_SHARED, priv->eq_table.irq_names, dev);
if (err)
goto err_out_unmap;
priv->eq_table.have_irq = 1;
}
err = mlx4_MAP_EQ(dev, get_async_ev_mask(dev), 0,
priv->eq_table.eq[MLX4_EQ_ASYNC].eqn);
if (err)
mlx4_warn(dev, "MAP_EQ for async EQ %d failed (%d)\n",
priv->eq_table.eq[MLX4_EQ_ASYNC].eqn, err);
eq_set_ci(&priv->eq_table.eq[MLX4_EQ_ASYNC], 1);
return 0;
err_out_unmap:
while (i >= 0)
mlx4_free_eq(dev, &priv->eq_table.eq[i--]);
#ifdef CONFIG_RFS_ACCEL
for (i = 1; i <= dev->caps.num_ports; i++) {
if (mlx4_priv(dev)->port[i].rmap) {
free_irq_cpu_rmap(mlx4_priv(dev)->port[i].rmap);
mlx4_priv(dev)->port[i].rmap = NULL;
}
}
#endif
mlx4_free_irqs(dev);
err_out_clr_int:
if (!mlx4_is_slave(dev))
mlx4_unmap_clr_int(dev);
err_out_bitmap:
mlx4_unmap_uar(dev);
mlx4_bitmap_cleanup(&priv->eq_table.bitmap);
err_out_free:
kfree(priv->eq_table.uar_map);
return err;
}
void mlx4_cleanup_eq_table(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int i;
mlx4_MAP_EQ(dev, get_async_ev_mask(dev), 1,
priv->eq_table.eq[MLX4_EQ_ASYNC].eqn);
#ifdef CONFIG_RFS_ACCEL
for (i = 1; i <= dev->caps.num_ports; i++) {
if (mlx4_priv(dev)->port[i].rmap) {
free_irq_cpu_rmap(mlx4_priv(dev)->port[i].rmap);
mlx4_priv(dev)->port[i].rmap = NULL;
}
}
#endif
mlx4_free_irqs(dev);
for (i = 0; i < dev->caps.num_comp_vectors + 1; ++i)
mlx4_free_eq(dev, &priv->eq_table.eq[i]);
if (!mlx4_is_slave(dev))
mlx4_unmap_clr_int(dev);
mlx4_unmap_uar(dev);
mlx4_bitmap_cleanup(&priv->eq_table.bitmap);
kfree(priv->eq_table.uar_map);
}
int mlx4_test_interrupts(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int i;
int err;
err = mlx4_NOP(dev);
if (!(dev->flags & MLX4_FLAG_MSI_X) || mlx4_is_slave(dev))
return err;
for(i = 0; !err && (i < dev->caps.num_comp_vectors); ++i) {
mlx4_cmd_use_polling(dev);
err = mlx4_MAP_EQ(dev, get_async_ev_mask(dev), 0,
priv->eq_table.eq[i].eqn);
if (err) {
mlx4_warn(dev, "Failed mapping eq for interrupt test\n");
mlx4_cmd_use_events(dev);
break;
}
mlx4_cmd_use_events(dev);
err = mlx4_NOP(dev);
}
mlx4_MAP_EQ(dev, get_async_ev_mask(dev), 0,
priv->eq_table.eq[MLX4_EQ_ASYNC].eqn);
return err;
}
bool mlx4_is_eq_vector_valid(struct mlx4_dev *dev, u8 port, int vector)
{
struct mlx4_priv *priv = mlx4_priv(dev);
vector = MLX4_CQ_TO_EQ_VECTOR(vector);
if (vector < 0 || (vector >= dev->caps.num_comp_vectors + 1) ||
(vector == MLX4_EQ_ASYNC))
return false;
return test_bit(port - 1, priv->eq_table.eq[vector].actv_ports.ports);
}
u32 mlx4_get_eqs_per_port(struct mlx4_dev *dev, u8 port)
{
struct mlx4_priv *priv = mlx4_priv(dev);
unsigned int i;
unsigned int sum = 0;
for (i = 0; i < dev->caps.num_comp_vectors + 1; i++)
sum += !!test_bit(port - 1,
priv->eq_table.eq[i].actv_ports.ports);
return sum;
}
int mlx4_is_eq_shared(struct mlx4_dev *dev, int vector)
{
struct mlx4_priv *priv = mlx4_priv(dev);
vector = MLX4_CQ_TO_EQ_VECTOR(vector);
if (vector <= 0 || (vector >= dev->caps.num_comp_vectors + 1))
return -EINVAL;
return !!(bitmap_weight(priv->eq_table.eq[vector].actv_ports.ports,
dev->caps.num_ports) > 1);
}
struct cpu_rmap *mlx4_get_cpu_rmap(struct mlx4_dev *dev, int port)
{
return mlx4_priv(dev)->port[port].rmap;
}
int mlx4_assign_eq(struct mlx4_dev *dev, u8 port, int *vector)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int err = 0, i = 0;
u32 min_ref_count_val = (u32)-1;
int requested_vector = MLX4_CQ_TO_EQ_VECTOR(*vector);
int *prequested_vector = NULL;
mutex_lock(&priv->msix_ctl.pool_lock);
if (requested_vector < (dev->caps.num_comp_vectors + 1) &&
(requested_vector >= 0) &&
(requested_vector != MLX4_EQ_ASYNC)) {
if (test_bit(port - 1,
priv->eq_table.eq[requested_vector].actv_ports.ports)) {
prequested_vector = &requested_vector;
} else {
struct mlx4_eq *eq;
for (i = 1; i < port;
requested_vector += mlx4_get_eqs_per_port(dev, i++))
;
eq = &priv->eq_table.eq[requested_vector];
if (requested_vector < dev->caps.num_comp_vectors + 1 &&
test_bit(port - 1, eq->actv_ports.ports)) {
prequested_vector = &requested_vector;
}
}
}
if (!prequested_vector) {
requested_vector = -1;
for (i = 0; min_ref_count_val && i < dev->caps.num_comp_vectors + 1;
i++) {
struct mlx4_eq *eq = &priv->eq_table.eq[i];
if (min_ref_count_val > eq->ref_count &&
test_bit(port - 1, eq->actv_ports.ports)) {
min_ref_count_val = eq->ref_count;
requested_vector = i;
}
}
if (requested_vector < 0) {
err = -ENOSPC;
goto err_unlock;
}
prequested_vector = &requested_vector;
}
if (!test_bit(*prequested_vector, priv->msix_ctl.pool_bm) &&
dev->flags & MLX4_FLAG_MSI_X) {
set_bit(*prequested_vector, priv->msix_ctl.pool_bm);
snprintf(priv->eq_table.irq_names +
*prequested_vector * MLX4_IRQNAME_SIZE,
MLX4_IRQNAME_SIZE, "mlx4-%d@%s",
*prequested_vector, dev_name(&dev->persist->pdev->dev));
err = request_irq(priv->eq_table.eq[*prequested_vector].irq,
mlx4_msi_x_interrupt, 0,
&priv->eq_table.irq_names[*prequested_vector << 5],
priv->eq_table.eq + *prequested_vector);
if (err) {
clear_bit(*prequested_vector, priv->msix_ctl.pool_bm);
*prequested_vector = -1;
} else {
#if defined(CONFIG_SMP)
mlx4_set_eq_affinity_hint(priv, *prequested_vector);
#endif
eq_set_ci(&priv->eq_table.eq[*prequested_vector], 1);
priv->eq_table.eq[*prequested_vector].have_irq = 1;
}
}
if (!err && *prequested_vector >= 0)
priv->eq_table.eq[*prequested_vector].ref_count++;
err_unlock:
mutex_unlock(&priv->msix_ctl.pool_lock);
if (!err && *prequested_vector >= 0)
*vector = MLX4_EQ_TO_CQ_VECTOR(*prequested_vector);
else
*vector = 0;
return err;
}
int mlx4_eq_get_irq(struct mlx4_dev *dev, int cq_vec)
{
struct mlx4_priv *priv = mlx4_priv(dev);
return priv->eq_table.eq[MLX4_CQ_TO_EQ_VECTOR(cq_vec)].irq;
}
void mlx4_release_eq(struct mlx4_dev *dev, int vec)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int eq_vec = MLX4_CQ_TO_EQ_VECTOR(vec);
mutex_lock(&priv->msix_ctl.pool_lock);
priv->eq_table.eq[eq_vec].ref_count--;
mutex_unlock(&priv->msix_ctl.pool_lock);
}
