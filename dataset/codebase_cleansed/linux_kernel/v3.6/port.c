void mlx4_init_mac_table(struct mlx4_dev *dev, struct mlx4_mac_table *table)
{
int i;
mutex_init(&table->mutex);
for (i = 0; i < MLX4_MAX_MAC_NUM; i++) {
table->entries[i] = 0;
table->refs[i] = 0;
}
table->max = 1 << dev->caps.log_num_macs;
table->total = 0;
}
void mlx4_init_vlan_table(struct mlx4_dev *dev, struct mlx4_vlan_table *table)
{
int i;
mutex_init(&table->mutex);
for (i = 0; i < MLX4_MAX_VLAN_NUM; i++) {
table->entries[i] = 0;
table->refs[i] = 0;
}
table->max = (1 << dev->caps.log_num_vlans) - MLX4_VLAN_REGULAR;
table->total = 0;
}
static int mlx4_uc_steer_add(struct mlx4_dev *dev, u8 port,
u64 mac, int *qpn, u64 *reg_id)
{
__be64 be_mac;
int err;
mac &= MLX4_MAC_MASK;
be_mac = cpu_to_be64(mac << 16);
switch (dev->caps.steering_mode) {
case MLX4_STEERING_MODE_B0: {
struct mlx4_qp qp;
u8 gid[16] = {0};
qp.qpn = *qpn;
memcpy(&gid[10], &be_mac, ETH_ALEN);
gid[5] = port;
err = mlx4_unicast_attach(dev, &qp, gid, 0, MLX4_PROT_ETH);
break;
}
case MLX4_STEERING_MODE_DEVICE_MANAGED: {
struct mlx4_spec_list spec_eth = { {NULL} };
__be64 mac_mask = cpu_to_be64(MLX4_MAC_MASK << 16);
struct mlx4_net_trans_rule rule = {
.queue_mode = MLX4_NET_TRANS_Q_FIFO,
.exclusive = 0,
.allow_loopback = 1,
.promisc_mode = MLX4_FS_PROMISC_NONE,
.priority = MLX4_DOMAIN_NIC,
};
rule.port = port;
rule.qpn = *qpn;
INIT_LIST_HEAD(&rule.list);
spec_eth.id = MLX4_NET_TRANS_RULE_ID_ETH;
memcpy(spec_eth.eth.dst_mac, &be_mac, ETH_ALEN);
memcpy(spec_eth.eth.dst_mac_msk, &mac_mask, ETH_ALEN);
list_add_tail(&spec_eth.list, &rule.list);
err = mlx4_flow_attach(dev, &rule, reg_id);
break;
}
default:
return -EINVAL;
}
if (err)
mlx4_warn(dev, "Failed Attaching Unicast\n");
return err;
}
static void mlx4_uc_steer_release(struct mlx4_dev *dev, u8 port,
u64 mac, int qpn, u64 reg_id)
{
switch (dev->caps.steering_mode) {
case MLX4_STEERING_MODE_B0: {
struct mlx4_qp qp;
u8 gid[16] = {0};
__be64 be_mac;
qp.qpn = qpn;
mac &= MLX4_MAC_MASK;
be_mac = cpu_to_be64(mac << 16);
memcpy(&gid[10], &be_mac, ETH_ALEN);
gid[5] = port;
mlx4_unicast_detach(dev, &qp, gid, MLX4_PROT_ETH);
break;
}
case MLX4_STEERING_MODE_DEVICE_MANAGED: {
mlx4_flow_detach(dev, reg_id);
break;
}
default:
mlx4_err(dev, "Invalid steering mode.\n");
}
}
static int validate_index(struct mlx4_dev *dev,
struct mlx4_mac_table *table, int index)
{
int err = 0;
if (index < 0 || index >= table->max || !table->entries[index]) {
mlx4_warn(dev, "No valid Mac entry for the given index\n");
err = -EINVAL;
}
return err;
}
static int find_index(struct mlx4_dev *dev,
struct mlx4_mac_table *table, u64 mac)
{
int i;
for (i = 0; i < MLX4_MAX_MAC_NUM; i++) {
if ((mac & MLX4_MAC_MASK) ==
(MLX4_MAC_MASK & be64_to_cpu(table->entries[i])))
return i;
}
return -EINVAL;
}
int mlx4_get_eth_qp(struct mlx4_dev *dev, u8 port, u64 mac, int *qpn)
{
struct mlx4_port_info *info = &mlx4_priv(dev)->port[port];
struct mlx4_mac_entry *entry;
int index = 0;
int err = 0;
u64 reg_id;
mlx4_dbg(dev, "Registering MAC: 0x%llx for adding\n",
(unsigned long long) mac);
index = mlx4_register_mac(dev, port, mac);
if (index < 0) {
err = index;
mlx4_err(dev, "Failed adding MAC: 0x%llx\n",
(unsigned long long) mac);
return err;
}
if (dev->caps.steering_mode == MLX4_STEERING_MODE_A0) {
*qpn = info->base_qpn + index;
return 0;
}
err = mlx4_qp_reserve_range(dev, 1, 1, qpn);
mlx4_dbg(dev, "Reserved qp %d\n", *qpn);
if (err) {
mlx4_err(dev, "Failed to reserve qp for mac registration\n");
goto qp_err;
}
err = mlx4_uc_steer_add(dev, port, mac, qpn, &reg_id);
if (err)
goto steer_err;
entry = kmalloc(sizeof *entry, GFP_KERNEL);
if (!entry) {
err = -ENOMEM;
goto alloc_err;
}
entry->mac = mac;
entry->reg_id = reg_id;
err = radix_tree_insert(&info->mac_tree, *qpn, entry);
if (err)
goto insert_err;
return 0;
insert_err:
kfree(entry);
alloc_err:
mlx4_uc_steer_release(dev, port, mac, *qpn, reg_id);
steer_err:
mlx4_qp_release_range(dev, *qpn, 1);
qp_err:
mlx4_unregister_mac(dev, port, mac);
return err;
}
void mlx4_put_eth_qp(struct mlx4_dev *dev, u8 port, u64 mac, int qpn)
{
struct mlx4_port_info *info = &mlx4_priv(dev)->port[port];
struct mlx4_mac_entry *entry;
mlx4_dbg(dev, "Registering MAC: 0x%llx for deleting\n",
(unsigned long long) mac);
mlx4_unregister_mac(dev, port, mac);
if (dev->caps.steering_mode != MLX4_STEERING_MODE_A0) {
entry = radix_tree_lookup(&info->mac_tree, qpn);
if (entry) {
mlx4_dbg(dev, "Releasing qp: port %d, mac 0x%llx,"
" qpn %d\n", port,
(unsigned long long) mac, qpn);
mlx4_uc_steer_release(dev, port, entry->mac,
qpn, entry->reg_id);
mlx4_qp_release_range(dev, qpn, 1);
radix_tree_delete(&info->mac_tree, qpn);
kfree(entry);
}
}
}
static int mlx4_set_port_mac_table(struct mlx4_dev *dev, u8 port,
__be64 *entries)
{
struct mlx4_cmd_mailbox *mailbox;
u32 in_mod;
int err;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
memcpy(mailbox->buf, entries, MLX4_MAC_TABLE_SIZE);
in_mod = MLX4_SET_PORT_MAC_TABLE << 8 | port;
err = mlx4_cmd(dev, mailbox->dma, in_mod, 1, MLX4_CMD_SET_PORT,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_NATIVE);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int __mlx4_register_mac(struct mlx4_dev *dev, u8 port, u64 mac)
{
struct mlx4_port_info *info = &mlx4_priv(dev)->port[port];
struct mlx4_mac_table *table = &info->mac_table;
int i, err = 0;
int free = -1;
mlx4_dbg(dev, "Registering MAC: 0x%llx for port %d\n",
(unsigned long long) mac, port);
mutex_lock(&table->mutex);
for (i = 0; i < MLX4_MAX_MAC_NUM; i++) {
if (free < 0 && !table->entries[i]) {
free = i;
continue;
}
if (mac == (MLX4_MAC_MASK & be64_to_cpu(table->entries[i]))) {
err = -EEXIST;
goto out;
}
}
mlx4_dbg(dev, "Free MAC index is %d\n", free);
if (table->total == table->max) {
err = -ENOSPC;
goto out;
}
table->entries[free] = cpu_to_be64(mac | MLX4_MAC_VALID);
err = mlx4_set_port_mac_table(dev, port, table->entries);
if (unlikely(err)) {
mlx4_err(dev, "Failed adding MAC: 0x%llx\n",
(unsigned long long) mac);
table->entries[free] = 0;
goto out;
}
err = free;
++table->total;
out:
mutex_unlock(&table->mutex);
return err;
}
int mlx4_register_mac(struct mlx4_dev *dev, u8 port, u64 mac)
{
u64 out_param;
int err;
if (mlx4_is_mfunc(dev)) {
set_param_l(&out_param, port);
err = mlx4_cmd_imm(dev, mac, &out_param, RES_MAC,
RES_OP_RESERVE_AND_MAP, MLX4_CMD_ALLOC_RES,
MLX4_CMD_TIME_CLASS_A, MLX4_CMD_WRAPPED);
if (err)
return err;
return get_param_l(&out_param);
}
return __mlx4_register_mac(dev, port, mac);
}
void __mlx4_unregister_mac(struct mlx4_dev *dev, u8 port, u64 mac)
{
struct mlx4_port_info *info = &mlx4_priv(dev)->port[port];
struct mlx4_mac_table *table = &info->mac_table;
int index;
index = find_index(dev, table, mac);
mutex_lock(&table->mutex);
if (validate_index(dev, table, index))
goto out;
table->entries[index] = 0;
mlx4_set_port_mac_table(dev, port, table->entries);
--table->total;
out:
mutex_unlock(&table->mutex);
}
void mlx4_unregister_mac(struct mlx4_dev *dev, u8 port, u64 mac)
{
u64 out_param;
if (mlx4_is_mfunc(dev)) {
set_param_l(&out_param, port);
(void) mlx4_cmd_imm(dev, mac, &out_param, RES_MAC,
RES_OP_RESERVE_AND_MAP, MLX4_CMD_FREE_RES,
MLX4_CMD_TIME_CLASS_A, MLX4_CMD_WRAPPED);
return;
}
__mlx4_unregister_mac(dev, port, mac);
return;
}
int mlx4_replace_mac(struct mlx4_dev *dev, u8 port, int qpn, u64 new_mac)
{
struct mlx4_port_info *info = &mlx4_priv(dev)->port[port];
struct mlx4_mac_table *table = &info->mac_table;
struct mlx4_mac_entry *entry;
int index = qpn - info->base_qpn;
int err = 0;
if (dev->caps.steering_mode != MLX4_STEERING_MODE_A0) {
entry = radix_tree_lookup(&info->mac_tree, qpn);
if (!entry)
return -EINVAL;
mlx4_uc_steer_release(dev, port, entry->mac,
qpn, entry->reg_id);
mlx4_unregister_mac(dev, port, entry->mac);
entry->mac = new_mac;
entry->reg_id = 0;
mlx4_register_mac(dev, port, new_mac);
err = mlx4_uc_steer_add(dev, port, entry->mac,
&qpn, &entry->reg_id);
return err;
}
mutex_lock(&table->mutex);
err = validate_index(dev, table, index);
if (err)
goto out;
table->entries[index] = cpu_to_be64(new_mac | MLX4_MAC_VALID);
err = mlx4_set_port_mac_table(dev, port, table->entries);
if (unlikely(err)) {
mlx4_err(dev, "Failed adding MAC: 0x%llx\n",
(unsigned long long) new_mac);
table->entries[index] = 0;
}
out:
mutex_unlock(&table->mutex);
return err;
}
static int mlx4_set_port_vlan_table(struct mlx4_dev *dev, u8 port,
__be32 *entries)
{
struct mlx4_cmd_mailbox *mailbox;
u32 in_mod;
int err;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
memcpy(mailbox->buf, entries, MLX4_VLAN_TABLE_SIZE);
in_mod = MLX4_SET_PORT_VLAN_TABLE << 8 | port;
err = mlx4_cmd(dev, mailbox->dma, in_mod, 1, MLX4_CMD_SET_PORT,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_WRAPPED);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_find_cached_vlan(struct mlx4_dev *dev, u8 port, u16 vid, int *idx)
{
struct mlx4_vlan_table *table = &mlx4_priv(dev)->port[port].vlan_table;
int i;
for (i = 0; i < MLX4_MAX_VLAN_NUM; ++i) {
if (table->refs[i] &&
(vid == (MLX4_VLAN_MASK &
be32_to_cpu(table->entries[i])))) {
*idx = i;
return 0;
}
}
return -ENOENT;
}
static int __mlx4_register_vlan(struct mlx4_dev *dev, u8 port, u16 vlan,
int *index)
{
struct mlx4_vlan_table *table = &mlx4_priv(dev)->port[port].vlan_table;
int i, err = 0;
int free = -1;
mutex_lock(&table->mutex);
if (table->total == table->max) {
err = -ENOSPC;
goto out;
}
for (i = MLX4_VLAN_REGULAR; i < MLX4_MAX_VLAN_NUM; i++) {
if (free < 0 && (table->refs[i] == 0)) {
free = i;
continue;
}
if (table->refs[i] &&
(vlan == (MLX4_VLAN_MASK &
be32_to_cpu(table->entries[i])))) {
*index = i;
++table->refs[i];
goto out;
}
}
if (free < 0) {
err = -ENOMEM;
goto out;
}
table->refs[free] = 1;
table->entries[free] = cpu_to_be32(vlan | MLX4_VLAN_VALID);
err = mlx4_set_port_vlan_table(dev, port, table->entries);
if (unlikely(err)) {
mlx4_warn(dev, "Failed adding vlan: %u\n", vlan);
table->refs[free] = 0;
table->entries[free] = 0;
goto out;
}
*index = free;
++table->total;
out:
mutex_unlock(&table->mutex);
return err;
}
int mlx4_register_vlan(struct mlx4_dev *dev, u8 port, u16 vlan, int *index)
{
u64 out_param;
int err;
if (mlx4_is_mfunc(dev)) {
set_param_l(&out_param, port);
err = mlx4_cmd_imm(dev, vlan, &out_param, RES_VLAN,
RES_OP_RESERVE_AND_MAP, MLX4_CMD_ALLOC_RES,
MLX4_CMD_TIME_CLASS_A, MLX4_CMD_WRAPPED);
if (!err)
*index = get_param_l(&out_param);
return err;
}
return __mlx4_register_vlan(dev, port, vlan, index);
}
static void __mlx4_unregister_vlan(struct mlx4_dev *dev, u8 port, int index)
{
struct mlx4_vlan_table *table = &mlx4_priv(dev)->port[port].vlan_table;
if (index < MLX4_VLAN_REGULAR) {
mlx4_warn(dev, "Trying to free special vlan index %d\n", index);
return;
}
mutex_lock(&table->mutex);
if (!table->refs[index]) {
mlx4_warn(dev, "No vlan entry for index %d\n", index);
goto out;
}
if (--table->refs[index]) {
mlx4_dbg(dev, "Have more references for index %d,"
"no need to modify vlan table\n", index);
goto out;
}
table->entries[index] = 0;
mlx4_set_port_vlan_table(dev, port, table->entries);
--table->total;
out:
mutex_unlock(&table->mutex);
}
void mlx4_unregister_vlan(struct mlx4_dev *dev, u8 port, int index)
{
u64 in_param;
int err;
if (mlx4_is_mfunc(dev)) {
set_param_l(&in_param, port);
err = mlx4_cmd(dev, in_param, RES_VLAN, RES_OP_RESERVE_AND_MAP,
MLX4_CMD_FREE_RES, MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_WRAPPED);
if (!err)
mlx4_warn(dev, "Failed freeing vlan at index:%d\n",
index);
return;
}
__mlx4_unregister_vlan(dev, port, index);
}
int mlx4_get_port_ib_caps(struct mlx4_dev *dev, u8 port, __be32 *caps)
{
struct mlx4_cmd_mailbox *inmailbox, *outmailbox;
u8 *inbuf, *outbuf;
int err;
inmailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(inmailbox))
return PTR_ERR(inmailbox);
outmailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(outmailbox)) {
mlx4_free_cmd_mailbox(dev, inmailbox);
return PTR_ERR(outmailbox);
}
inbuf = inmailbox->buf;
outbuf = outmailbox->buf;
memset(inbuf, 0, 256);
memset(outbuf, 0, 256);
inbuf[0] = 1;
inbuf[1] = 1;
inbuf[2] = 1;
inbuf[3] = 1;
*(__be16 *) (&inbuf[16]) = cpu_to_be16(0x0015);
*(__be32 *) (&inbuf[20]) = cpu_to_be32(port);
err = mlx4_cmd_box(dev, inmailbox->dma, outmailbox->dma, port, 3,
MLX4_CMD_MAD_IFC, MLX4_CMD_TIME_CLASS_C,
MLX4_CMD_NATIVE);
if (!err)
*caps = *(__be32 *) (outbuf + 84);
mlx4_free_cmd_mailbox(dev, inmailbox);
mlx4_free_cmd_mailbox(dev, outmailbox);
return err;
}
static int mlx4_common_set_port(struct mlx4_dev *dev, int slave, u32 in_mod,
u8 op_mod, struct mlx4_cmd_mailbox *inbox)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_port_info *port_info;
struct mlx4_mfunc_master_ctx *master = &priv->mfunc.master;
struct mlx4_slave_state *slave_st = &master->slave_state[slave];
struct mlx4_set_port_rqp_calc_context *qpn_context;
struct mlx4_set_port_general_context *gen_context;
int reset_qkey_viols;
int port;
int is_eth;
u32 in_modifier;
u32 promisc;
u16 mtu, prev_mtu;
int err;
int i;
__be32 agg_cap_mask;
__be32 slave_cap_mask;
__be32 new_cap_mask;
port = in_mod & 0xff;
in_modifier = in_mod >> 8;
is_eth = op_mod;
port_info = &priv->port[port];
if (is_eth) {
if (slave != dev->caps.function &&
in_modifier != MLX4_SET_PORT_GENERAL) {
mlx4_warn(dev, "denying SET_PORT for slave:%d\n",
slave);
return -EINVAL;
}
switch (in_modifier) {
case MLX4_SET_PORT_RQP_CALC:
qpn_context = inbox->buf;
qpn_context->base_qpn =
cpu_to_be32(port_info->base_qpn);
qpn_context->n_mac = 0x7;
promisc = be32_to_cpu(qpn_context->promisc) >>
SET_PORT_PROMISC_SHIFT;
qpn_context->promisc = cpu_to_be32(
promisc << SET_PORT_PROMISC_SHIFT |
port_info->base_qpn);
promisc = be32_to_cpu(qpn_context->mcast) >>
SET_PORT_MC_PROMISC_SHIFT;
qpn_context->mcast = cpu_to_be32(
promisc << SET_PORT_MC_PROMISC_SHIFT |
port_info->base_qpn);
break;
case MLX4_SET_PORT_GENERAL:
gen_context = inbox->buf;
mtu = be16_to_cpu(gen_context->mtu);
mtu = min_t(int, mtu, dev->caps.eth_mtu_cap[port]);
prev_mtu = slave_st->mtu[port];
slave_st->mtu[port] = mtu;
if (mtu > master->max_mtu[port])
master->max_mtu[port] = mtu;
if (mtu < prev_mtu && prev_mtu ==
master->max_mtu[port]) {
slave_st->mtu[port] = mtu;
master->max_mtu[port] = mtu;
for (i = 0; i < dev->num_slaves; i++) {
master->max_mtu[port] =
max(master->max_mtu[port],
master->slave_state[i].mtu[port]);
}
}
gen_context->mtu = cpu_to_be16(master->max_mtu[port]);
break;
}
return mlx4_cmd(dev, inbox->dma, in_mod, op_mod,
MLX4_CMD_SET_PORT, MLX4_CMD_TIME_CLASS_B,
MLX4_CMD_NATIVE);
}
if (dev->flags & MLX4_FLAG_OLD_PORT_CMDS) {
reset_qkey_viols = (*(u8 *) inbox->buf) & 0x40;
new_cap_mask = ((__be32 *) inbox->buf)[2];
} else {
reset_qkey_viols = ((u8 *) inbox->buf)[3] & 0x1;
new_cap_mask = ((__be32 *) inbox->buf)[1];
}
agg_cap_mask = 0;
slave_cap_mask =
priv->mfunc.master.slave_state[slave].ib_cap_mask[port];
priv->mfunc.master.slave_state[slave].ib_cap_mask[port] = new_cap_mask;
for (i = 0; i < dev->num_slaves; i++)
agg_cap_mask |=
priv->mfunc.master.slave_state[i].ib_cap_mask[port];
if (slave != dev->caps.function)
memset(inbox->buf, 0, 256);
if (dev->flags & MLX4_FLAG_OLD_PORT_CMDS) {
*(u8 *) inbox->buf |= !!reset_qkey_viols << 6;
((__be32 *) inbox->buf)[2] = agg_cap_mask;
} else {
((u8 *) inbox->buf)[3] |= !!reset_qkey_viols;
((__be32 *) inbox->buf)[1] = agg_cap_mask;
}
err = mlx4_cmd(dev, inbox->dma, port, is_eth, MLX4_CMD_SET_PORT,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_NATIVE);
if (err)
priv->mfunc.master.slave_state[slave].ib_cap_mask[port] =
slave_cap_mask;
return err;
}
int mlx4_SET_PORT_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
return mlx4_common_set_port(dev, slave, vhcr->in_modifier,
vhcr->op_modifier, inbox);
}
int mlx4_SET_PORT(struct mlx4_dev *dev, u8 port, int pkey_tbl_sz)
{
struct mlx4_cmd_mailbox *mailbox;
int err, vl_cap, pkey_tbl_flag = 0;
if (dev->caps.port_type[port] == MLX4_PORT_TYPE_ETH)
return 0;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
memset(mailbox->buf, 0, 256);
((__be32 *) mailbox->buf)[1] = dev->caps.ib_port_def_cap[port];
if (pkey_tbl_sz >= 0 && mlx4_is_master(dev)) {
pkey_tbl_flag = 1;
((__be16 *) mailbox->buf)[20] = cpu_to_be16(pkey_tbl_sz);
}
for (vl_cap = 8; vl_cap >= 1; vl_cap >>= 1) {
((__be32 *) mailbox->buf)[0] = cpu_to_be32(
(1 << MLX4_CHANGE_PORT_MTU_CAP) |
(1 << MLX4_CHANGE_PORT_VL_CAP) |
(pkey_tbl_flag << MLX4_CHANGE_PORT_PKEY_TBL_SZ) |
(dev->caps.port_ib_mtu[port] << MLX4_SET_PORT_MTU_CAP) |
(vl_cap << MLX4_SET_PORT_VL_CAP));
err = mlx4_cmd(dev, mailbox->dma, port, 0, MLX4_CMD_SET_PORT,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_WRAPPED);
if (err != -ENOMEM)
break;
}
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_SET_PORT_general(struct mlx4_dev *dev, u8 port, int mtu,
u8 pptx, u8 pfctx, u8 pprx, u8 pfcrx)
{
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_set_port_general_context *context;
int err;
u32 in_mod;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
context = mailbox->buf;
memset(context, 0, sizeof *context);
context->flags = SET_PORT_GEN_ALL_VALID;
context->mtu = cpu_to_be16(mtu);
context->pptx = (pptx * (!pfctx)) << 7;
context->pfctx = pfctx;
context->pprx = (pprx * (!pfcrx)) << 7;
context->pfcrx = pfcrx;
in_mod = MLX4_SET_PORT_GENERAL << 8 | port;
err = mlx4_cmd(dev, mailbox->dma, in_mod, 1, MLX4_CMD_SET_PORT,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_WRAPPED);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_SET_PORT_qpn_calc(struct mlx4_dev *dev, u8 port, u32 base_qpn,
u8 promisc)
{
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_set_port_rqp_calc_context *context;
int err;
u32 in_mod;
u32 m_promisc = (dev->caps.flags & MLX4_DEV_CAP_FLAG_VEP_MC_STEER) ?
MCAST_DIRECT : MCAST_DEFAULT;
if (dev->caps.steering_mode != MLX4_STEERING_MODE_A0)
return 0;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
context = mailbox->buf;
memset(context, 0, sizeof *context);
context->base_qpn = cpu_to_be32(base_qpn);
context->n_mac = dev->caps.log_num_macs;
context->promisc = cpu_to_be32(promisc << SET_PORT_PROMISC_SHIFT |
base_qpn);
context->mcast = cpu_to_be32(m_promisc << SET_PORT_MC_PROMISC_SHIFT |
base_qpn);
context->intra_no_vlan = 0;
context->no_vlan = MLX4_NO_VLAN_IDX;
context->intra_vlan_miss = 0;
context->vlan_miss = MLX4_VLAN_MISS_IDX;
in_mod = MLX4_SET_PORT_RQP_CALC << 8 | port;
err = mlx4_cmd(dev, mailbox->dma, in_mod, 1, MLX4_CMD_SET_PORT,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_WRAPPED);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_SET_PORT_PRIO2TC(struct mlx4_dev *dev, u8 port, u8 *prio2tc)
{
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_set_port_prio2tc_context *context;
int err;
u32 in_mod;
int i;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
context = mailbox->buf;
memset(context, 0, sizeof *context);
for (i = 0; i < MLX4_NUM_UP; i += 2)
context->prio2tc[i >> 1] = prio2tc[i] << 4 | prio2tc[i + 1];
in_mod = MLX4_SET_PORT_PRIO2TC << 8 | port;
err = mlx4_cmd(dev, mailbox->dma, in_mod, 1, MLX4_CMD_SET_PORT,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_NATIVE);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_SET_PORT_SCHEDULER(struct mlx4_dev *dev, u8 port, u8 *tc_tx_bw,
u8 *pg, u16 *ratelimit)
{
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_set_port_scheduler_context *context;
int err;
u32 in_mod;
int i;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
context = mailbox->buf;
memset(context, 0, sizeof *context);
for (i = 0; i < MLX4_NUM_TC; i++) {
struct mlx4_port_scheduler_tc_cfg_be *tc = &context->tc[i];
u16 r = ratelimit && ratelimit[i] ? ratelimit[i] :
MLX4_RATELIMIT_DEFAULT;
tc->pg = htons(pg[i]);
tc->bw_precentage = htons(tc_tx_bw[i]);
tc->max_bw_units = htons(MLX4_RATELIMIT_UNITS);
tc->max_bw_value = htons(r);
}
in_mod = MLX4_SET_PORT_SCHEDULER << 8 | port;
err = mlx4_cmd(dev, mailbox->dma, in_mod, 1, MLX4_CMD_SET_PORT,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_NATIVE);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_SET_MCAST_FLTR_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err = 0;
return err;
}
int mlx4_SET_MCAST_FLTR(struct mlx4_dev *dev, u8 port,
u64 mac, u64 clear, u8 mode)
{
return mlx4_cmd(dev, (mac | (clear << 63)), port, mode,
MLX4_CMD_SET_MCAST_FLTR, MLX4_CMD_TIME_CLASS_B,
MLX4_CMD_WRAPPED);
}
int mlx4_SET_VLAN_FLTR_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err = 0;
return err;
}
int mlx4_common_dump_eth_stats(struct mlx4_dev *dev, int slave,
u32 in_mod, struct mlx4_cmd_mailbox *outbox)
{
return mlx4_cmd_box(dev, 0, outbox->dma, in_mod, 0,
MLX4_CMD_DUMP_ETH_STATS, MLX4_CMD_TIME_CLASS_B,
MLX4_CMD_NATIVE);
}
int mlx4_DUMP_ETH_STATS_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
if (slave != dev->caps.function)
return 0;
return mlx4_common_dump_eth_stats(dev, slave,
vhcr->in_modifier, outbox);
}
void mlx4_set_stats_bitmap(struct mlx4_dev *dev, u64 *stats_bitmap)
{
if (!mlx4_is_mfunc(dev)) {
*stats_bitmap = 0;
return;
}
*stats_bitmap = (MLX4_STATS_TRAFFIC_COUNTERS_MASK |
MLX4_STATS_TRAFFIC_DROPS_MASK |
MLX4_STATS_PORT_COUNTERS_MASK);
if (mlx4_is_master(dev))
*stats_bitmap |= MLX4_STATS_ERROR_COUNTERS_MASK;
}
