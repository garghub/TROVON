static inline const char *mtt_states_str(enum res_mtt_states state)
{
switch (state) {
case RES_MTT_BUSY: return "RES_MTT_BUSY";
case RES_MTT_ALLOCATED: return "RES_MTT_ALLOCATED";
default: return "Unknown";
}
}
static void *res_tracker_lookup(struct rb_root *root, u64 res_id)
{
struct rb_node *node = root->rb_node;
while (node) {
struct res_common *res = container_of(node, struct res_common,
node);
if (res_id < res->res_id)
node = node->rb_left;
else if (res_id > res->res_id)
node = node->rb_right;
else
return res;
}
return NULL;
}
static int res_tracker_insert(struct rb_root *root, struct res_common *res)
{
struct rb_node **new = &(root->rb_node), *parent = NULL;
while (*new) {
struct res_common *this = container_of(*new, struct res_common,
node);
parent = *new;
if (res->res_id < this->res_id)
new = &((*new)->rb_left);
else if (res->res_id > this->res_id)
new = &((*new)->rb_right);
else
return -EEXIST;
}
rb_link_node(&res->node, parent, new);
rb_insert_color(&res->node, root);
return 0;
}
static const char *ResourceType(enum mlx4_resource rt)
{
switch (rt) {
case RES_QP: return "RES_QP";
case RES_CQ: return "RES_CQ";
case RES_SRQ: return "RES_SRQ";
case RES_MPT: return "RES_MPT";
case RES_MTT: return "RES_MTT";
case RES_MAC: return "RES_MAC";
case RES_VLAN: return "RES_VLAN";
case RES_EQ: return "RES_EQ";
case RES_COUNTER: return "RES_COUNTER";
case RES_FS_RULE: return "RES_FS_RULE";
case RES_XRCD: return "RES_XRCD";
default: return "Unknown resource type !!!";
};
}
static inline int mlx4_grant_resource(struct mlx4_dev *dev, int slave,
enum mlx4_resource res_type, int count,
int port)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct resource_allocator *res_alloc =
&priv->mfunc.master.res_tracker.res_alloc[res_type];
int err = -EINVAL;
int allocated, free, reserved, guaranteed, from_free;
if (slave > dev->num_vfs)
return -EINVAL;
spin_lock(&res_alloc->alloc_lock);
allocated = (port > 0) ?
res_alloc->allocated[(port - 1) * (dev->num_vfs + 1) + slave] :
res_alloc->allocated[slave];
free = (port > 0) ? res_alloc->res_port_free[port - 1] :
res_alloc->res_free;
reserved = (port > 0) ? res_alloc->res_port_rsvd[port - 1] :
res_alloc->res_reserved;
guaranteed = res_alloc->guaranteed[slave];
if (allocated + count > res_alloc->quota[slave])
goto out;
if (allocated + count <= guaranteed) {
err = 0;
} else {
if (guaranteed - allocated > 0)
from_free = count - (guaranteed - allocated);
else
from_free = count;
if (free - from_free > reserved)
err = 0;
}
if (!err) {
if (port > 0) {
res_alloc->allocated[(port - 1) * (dev->num_vfs + 1) + slave] += count;
res_alloc->res_port_free[port - 1] -= count;
} else {
res_alloc->allocated[slave] += count;
res_alloc->res_free -= count;
}
}
out:
spin_unlock(&res_alloc->alloc_lock);
return err;
}
static inline void mlx4_release_resource(struct mlx4_dev *dev, int slave,
enum mlx4_resource res_type, int count,
int port)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct resource_allocator *res_alloc =
&priv->mfunc.master.res_tracker.res_alloc[res_type];
if (slave > dev->num_vfs)
return;
spin_lock(&res_alloc->alloc_lock);
if (port > 0) {
res_alloc->allocated[(port - 1) * (dev->num_vfs + 1) + slave] -= count;
res_alloc->res_port_free[port - 1] += count;
} else {
res_alloc->allocated[slave] -= count;
res_alloc->res_free += count;
}
spin_unlock(&res_alloc->alloc_lock);
return;
}
static inline void initialize_res_quotas(struct mlx4_dev *dev,
struct resource_allocator *res_alloc,
enum mlx4_resource res_type,
int vf, int num_instances)
{
res_alloc->guaranteed[vf] = num_instances / (2 * (dev->num_vfs + 1));
res_alloc->quota[vf] = (num_instances / 2) + res_alloc->guaranteed[vf];
if (vf == mlx4_master_func_num(dev)) {
res_alloc->res_free = num_instances;
if (res_type == RES_MTT) {
res_alloc->res_free += dev->caps.reserved_mtts;
res_alloc->guaranteed[vf] += dev->caps.reserved_mtts;
res_alloc->quota[vf] += dev->caps.reserved_mtts;
}
}
}
void mlx4_init_quotas(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int pf;
if (mlx4_is_slave(dev))
return;
if (!mlx4_is_mfunc(dev)) {
dev->quotas.qp = dev->caps.num_qps - dev->caps.reserved_qps -
mlx4_num_reserved_sqps(dev);
dev->quotas.cq = dev->caps.num_cqs - dev->caps.reserved_cqs;
dev->quotas.srq = dev->caps.num_srqs - dev->caps.reserved_srqs;
dev->quotas.mtt = dev->caps.num_mtts - dev->caps.reserved_mtts;
dev->quotas.mpt = dev->caps.num_mpts - dev->caps.reserved_mrws;
return;
}
pf = mlx4_master_func_num(dev);
dev->quotas.qp =
priv->mfunc.master.res_tracker.res_alloc[RES_QP].quota[pf];
dev->quotas.cq =
priv->mfunc.master.res_tracker.res_alloc[RES_CQ].quota[pf];
dev->quotas.srq =
priv->mfunc.master.res_tracker.res_alloc[RES_SRQ].quota[pf];
dev->quotas.mtt =
priv->mfunc.master.res_tracker.res_alloc[RES_MTT].quota[pf];
dev->quotas.mpt =
priv->mfunc.master.res_tracker.res_alloc[RES_MPT].quota[pf];
}
int mlx4_init_resource_tracker(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int i, j;
int t;
priv->mfunc.master.res_tracker.slave_list =
kzalloc(dev->num_slaves * sizeof(struct slave_list),
GFP_KERNEL);
if (!priv->mfunc.master.res_tracker.slave_list)
return -ENOMEM;
for (i = 0 ; i < dev->num_slaves; i++) {
for (t = 0; t < MLX4_NUM_OF_RESOURCE_TYPE; ++t)
INIT_LIST_HEAD(&priv->mfunc.master.res_tracker.
slave_list[i].res_list[t]);
mutex_init(&priv->mfunc.master.res_tracker.slave_list[i].mutex);
}
mlx4_dbg(dev, "Started init_resource_tracker: %ld slaves\n",
dev->num_slaves);
for (i = 0 ; i < MLX4_NUM_OF_RESOURCE_TYPE; i++)
priv->mfunc.master.res_tracker.res_tree[i] = RB_ROOT;
for (i = 0; i < MLX4_NUM_OF_RESOURCE_TYPE; i++) {
struct resource_allocator *res_alloc =
&priv->mfunc.master.res_tracker.res_alloc[i];
res_alloc->quota = kmalloc((dev->num_vfs + 1) * sizeof(int), GFP_KERNEL);
res_alloc->guaranteed = kmalloc((dev->num_vfs + 1) * sizeof(int), GFP_KERNEL);
if (i == RES_MAC || i == RES_VLAN)
res_alloc->allocated = kzalloc(MLX4_MAX_PORTS *
(dev->num_vfs + 1) * sizeof(int),
GFP_KERNEL);
else
res_alloc->allocated = kzalloc((dev->num_vfs + 1) * sizeof(int), GFP_KERNEL);
if (!res_alloc->quota || !res_alloc->guaranteed ||
!res_alloc->allocated)
goto no_mem_err;
spin_lock_init(&res_alloc->alloc_lock);
for (t = 0; t < dev->num_vfs + 1; t++) {
switch (i) {
case RES_QP:
initialize_res_quotas(dev, res_alloc, RES_QP,
t, dev->caps.num_qps -
dev->caps.reserved_qps -
mlx4_num_reserved_sqps(dev));
break;
case RES_CQ:
initialize_res_quotas(dev, res_alloc, RES_CQ,
t, dev->caps.num_cqs -
dev->caps.reserved_cqs);
break;
case RES_SRQ:
initialize_res_quotas(dev, res_alloc, RES_SRQ,
t, dev->caps.num_srqs -
dev->caps.reserved_srqs);
break;
case RES_MPT:
initialize_res_quotas(dev, res_alloc, RES_MPT,
t, dev->caps.num_mpts -
dev->caps.reserved_mrws);
break;
case RES_MTT:
initialize_res_quotas(dev, res_alloc, RES_MTT,
t, dev->caps.num_mtts -
dev->caps.reserved_mtts);
break;
case RES_MAC:
if (t == mlx4_master_func_num(dev)) {
res_alloc->quota[t] = MLX4_MAX_MAC_NUM;
res_alloc->guaranteed[t] = 2;
for (j = 0; j < MLX4_MAX_PORTS; j++)
res_alloc->res_port_free[j] = MLX4_MAX_MAC_NUM;
} else {
res_alloc->quota[t] = MLX4_MAX_MAC_NUM;
res_alloc->guaranteed[t] = 2;
}
break;
case RES_VLAN:
if (t == mlx4_master_func_num(dev)) {
res_alloc->quota[t] = MLX4_MAX_VLAN_NUM;
res_alloc->guaranteed[t] = MLX4_MAX_VLAN_NUM / 2;
for (j = 0; j < MLX4_MAX_PORTS; j++)
res_alloc->res_port_free[j] =
res_alloc->quota[t];
} else {
res_alloc->quota[t] = MLX4_MAX_VLAN_NUM / 2;
res_alloc->guaranteed[t] = 0;
}
break;
case RES_COUNTER:
res_alloc->quota[t] = dev->caps.max_counters;
res_alloc->guaranteed[t] = 0;
if (t == mlx4_master_func_num(dev))
res_alloc->res_free = res_alloc->quota[t];
break;
default:
break;
}
if (i == RES_MAC || i == RES_VLAN) {
for (j = 0; j < MLX4_MAX_PORTS; j++)
res_alloc->res_port_rsvd[j] +=
res_alloc->guaranteed[t];
} else {
res_alloc->res_reserved += res_alloc->guaranteed[t];
}
}
}
spin_lock_init(&priv->mfunc.master.res_tracker.lock);
return 0;
no_mem_err:
for (i = 0; i < MLX4_NUM_OF_RESOURCE_TYPE; i++) {
kfree(priv->mfunc.master.res_tracker.res_alloc[i].allocated);
priv->mfunc.master.res_tracker.res_alloc[i].allocated = NULL;
kfree(priv->mfunc.master.res_tracker.res_alloc[i].guaranteed);
priv->mfunc.master.res_tracker.res_alloc[i].guaranteed = NULL;
kfree(priv->mfunc.master.res_tracker.res_alloc[i].quota);
priv->mfunc.master.res_tracker.res_alloc[i].quota = NULL;
}
return -ENOMEM;
}
void mlx4_free_resource_tracker(struct mlx4_dev *dev,
enum mlx4_res_tracker_free_type type)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int i;
if (priv->mfunc.master.res_tracker.slave_list) {
if (type != RES_TR_FREE_STRUCTS_ONLY) {
for (i = 0; i < dev->num_slaves; i++) {
if (type == RES_TR_FREE_ALL ||
dev->caps.function != i)
mlx4_delete_all_resources_for_slave(dev, i);
}
i = dev->caps.function;
mutex_lock(&priv->mfunc.master.res_tracker.slave_list[i].mutex);
rem_slave_vlans(dev, i);
mutex_unlock(&priv->mfunc.master.res_tracker.slave_list[i].mutex);
}
if (type != RES_TR_FREE_SLAVES_ONLY) {
for (i = 0; i < MLX4_NUM_OF_RESOURCE_TYPE; i++) {
kfree(priv->mfunc.master.res_tracker.res_alloc[i].allocated);
priv->mfunc.master.res_tracker.res_alloc[i].allocated = NULL;
kfree(priv->mfunc.master.res_tracker.res_alloc[i].guaranteed);
priv->mfunc.master.res_tracker.res_alloc[i].guaranteed = NULL;
kfree(priv->mfunc.master.res_tracker.res_alloc[i].quota);
priv->mfunc.master.res_tracker.res_alloc[i].quota = NULL;
}
kfree(priv->mfunc.master.res_tracker.slave_list);
priv->mfunc.master.res_tracker.slave_list = NULL;
}
}
}
static void update_pkey_index(struct mlx4_dev *dev, int slave,
struct mlx4_cmd_mailbox *inbox)
{
u8 sched = *(u8 *)(inbox->buf + 64);
u8 orig_index = *(u8 *)(inbox->buf + 35);
u8 new_index;
struct mlx4_priv *priv = mlx4_priv(dev);
int port;
port = (sched >> 6 & 1) + 1;
new_index = priv->virt2phys_pkey[slave][port - 1][orig_index];
*(u8 *)(inbox->buf + 35) = new_index;
}
static void update_gid(struct mlx4_dev *dev, struct mlx4_cmd_mailbox *inbox,
u8 slave)
{
struct mlx4_qp_context *qp_ctx = inbox->buf + 8;
enum mlx4_qp_optpar optpar = be32_to_cpu(*(__be32 *) inbox->buf);
u32 ts = (be32_to_cpu(qp_ctx->flags) >> 16) & 0xff;
if (MLX4_QP_ST_UD == ts)
qp_ctx->pri_path.mgid_index = 0x80 | slave;
if (MLX4_QP_ST_RC == ts || MLX4_QP_ST_UC == ts) {
if (optpar & MLX4_QP_OPTPAR_PRIMARY_ADDR_PATH)
qp_ctx->pri_path.mgid_index = slave & 0x7F;
if (optpar & MLX4_QP_OPTPAR_ALT_ADDR_PATH)
qp_ctx->alt_path.mgid_index = slave & 0x7F;
}
}
static int update_vport_qp_param(struct mlx4_dev *dev,
struct mlx4_cmd_mailbox *inbox,
u8 slave, u32 qpn)
{
struct mlx4_qp_context *qpc = inbox->buf + 8;
struct mlx4_vport_oper_state *vp_oper;
struct mlx4_priv *priv;
u32 qp_type;
int port;
port = (qpc->pri_path.sched_queue & 0x40) ? 2 : 1;
priv = mlx4_priv(dev);
vp_oper = &priv->mfunc.master.vf_oper[slave].vport[port];
if (MLX4_VGT != vp_oper->state.default_vlan) {
qp_type = (be32_to_cpu(qpc->flags) >> 16) & 0xff;
if (MLX4_QP_ST_RC == qp_type ||
(MLX4_QP_ST_UD == qp_type &&
!mlx4_is_qp_reserved(dev, qpn)))
return -EINVAL;
if (mlx4_is_qp_reserved(dev, qpn))
return 0;
qpc->param3 &= ~cpu_to_be32(MLX4_STRIP_VLAN);
if (vp_oper->state.link_state == IFLA_VF_LINK_STATE_DISABLE &&
dev->caps.flags2 & MLX4_DEV_CAP_FLAG2_UPDATE_QP) {
qpc->pri_path.vlan_control =
MLX4_VLAN_CTRL_ETH_TX_BLOCK_TAGGED |
MLX4_VLAN_CTRL_ETH_TX_BLOCK_PRIO_TAGGED |
MLX4_VLAN_CTRL_ETH_TX_BLOCK_UNTAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_PRIO_TAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_UNTAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_TAGGED;
} else if (0 != vp_oper->state.default_vlan) {
qpc->pri_path.vlan_control =
MLX4_VLAN_CTRL_ETH_TX_BLOCK_TAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_PRIO_TAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_UNTAGGED;
} else {
qpc->pri_path.vlan_control =
MLX4_VLAN_CTRL_ETH_TX_BLOCK_TAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_TAGGED;
}
qpc->pri_path.fvl_rx |= MLX4_FVL_RX_FORCE_ETH_VLAN;
qpc->pri_path.vlan_index = vp_oper->vlan_idx;
qpc->pri_path.fl |= MLX4_FL_CV | MLX4_FL_ETH_HIDE_CQE_VLAN;
qpc->pri_path.feup |= MLX4_FEUP_FORCE_ETH_UP | MLX4_FVL_FORCE_ETH_VLAN;
qpc->pri_path.sched_queue &= 0xC7;
qpc->pri_path.sched_queue |= (vp_oper->state.default_qos) << 3;
}
if (vp_oper->state.spoofchk) {
qpc->pri_path.feup |= MLX4_FSM_FORCE_ETH_SRC_MAC;
qpc->pri_path.grh_mylmc = (0x80 & qpc->pri_path.grh_mylmc) + vp_oper->mac_idx;
}
return 0;
}
static int mpt_mask(struct mlx4_dev *dev)
{
return dev->caps.num_mpts - 1;
}
static void *find_res(struct mlx4_dev *dev, u64 res_id,
enum mlx4_resource type)
{
struct mlx4_priv *priv = mlx4_priv(dev);
return res_tracker_lookup(&priv->mfunc.master.res_tracker.res_tree[type],
res_id);
}
static int get_res(struct mlx4_dev *dev, int slave, u64 res_id,
enum mlx4_resource type,
void *res)
{
struct res_common *r;
int err = 0;
spin_lock_irq(mlx4_tlock(dev));
r = find_res(dev, res_id, type);
if (!r) {
err = -ENONET;
goto exit;
}
if (r->state == RES_ANY_BUSY) {
err = -EBUSY;
goto exit;
}
if (r->owner != slave) {
err = -EPERM;
goto exit;
}
r->from_state = r->state;
r->state = RES_ANY_BUSY;
if (res)
*((struct res_common **)res) = r;
exit:
spin_unlock_irq(mlx4_tlock(dev));
return err;
}
int mlx4_get_slave_from_resource_id(struct mlx4_dev *dev,
enum mlx4_resource type,
u64 res_id, int *slave)
{
struct res_common *r;
int err = -ENOENT;
int id = res_id;
if (type == RES_QP)
id &= 0x7fffff;
spin_lock(mlx4_tlock(dev));
r = find_res(dev, id, type);
if (r) {
*slave = r->owner;
err = 0;
}
spin_unlock(mlx4_tlock(dev));
return err;
}
static void put_res(struct mlx4_dev *dev, int slave, u64 res_id,
enum mlx4_resource type)
{
struct res_common *r;
spin_lock_irq(mlx4_tlock(dev));
r = find_res(dev, res_id, type);
if (r)
r->state = r->from_state;
spin_unlock_irq(mlx4_tlock(dev));
}
static struct res_common *alloc_qp_tr(int id)
{
struct res_qp *ret;
ret = kzalloc(sizeof *ret, GFP_KERNEL);
if (!ret)
return NULL;
ret->com.res_id = id;
ret->com.state = RES_QP_RESERVED;
ret->local_qpn = id;
INIT_LIST_HEAD(&ret->mcg_list);
spin_lock_init(&ret->mcg_spl);
atomic_set(&ret->ref_count, 0);
return &ret->com;
}
static struct res_common *alloc_mtt_tr(int id, int order)
{
struct res_mtt *ret;
ret = kzalloc(sizeof *ret, GFP_KERNEL);
if (!ret)
return NULL;
ret->com.res_id = id;
ret->order = order;
ret->com.state = RES_MTT_ALLOCATED;
atomic_set(&ret->ref_count, 0);
return &ret->com;
}
static struct res_common *alloc_mpt_tr(int id, int key)
{
struct res_mpt *ret;
ret = kzalloc(sizeof *ret, GFP_KERNEL);
if (!ret)
return NULL;
ret->com.res_id = id;
ret->com.state = RES_MPT_RESERVED;
ret->key = key;
return &ret->com;
}
static struct res_common *alloc_eq_tr(int id)
{
struct res_eq *ret;
ret = kzalloc(sizeof *ret, GFP_KERNEL);
if (!ret)
return NULL;
ret->com.res_id = id;
ret->com.state = RES_EQ_RESERVED;
return &ret->com;
}
static struct res_common *alloc_cq_tr(int id)
{
struct res_cq *ret;
ret = kzalloc(sizeof *ret, GFP_KERNEL);
if (!ret)
return NULL;
ret->com.res_id = id;
ret->com.state = RES_CQ_ALLOCATED;
atomic_set(&ret->ref_count, 0);
return &ret->com;
}
static struct res_common *alloc_srq_tr(int id)
{
struct res_srq *ret;
ret = kzalloc(sizeof *ret, GFP_KERNEL);
if (!ret)
return NULL;
ret->com.res_id = id;
ret->com.state = RES_SRQ_ALLOCATED;
atomic_set(&ret->ref_count, 0);
return &ret->com;
}
static struct res_common *alloc_counter_tr(int id)
{
struct res_counter *ret;
ret = kzalloc(sizeof *ret, GFP_KERNEL);
if (!ret)
return NULL;
ret->com.res_id = id;
ret->com.state = RES_COUNTER_ALLOCATED;
return &ret->com;
}
static struct res_common *alloc_xrcdn_tr(int id)
{
struct res_xrcdn *ret;
ret = kzalloc(sizeof *ret, GFP_KERNEL);
if (!ret)
return NULL;
ret->com.res_id = id;
ret->com.state = RES_XRCD_ALLOCATED;
return &ret->com;
}
static struct res_common *alloc_fs_rule_tr(u64 id, int qpn)
{
struct res_fs_rule *ret;
ret = kzalloc(sizeof *ret, GFP_KERNEL);
if (!ret)
return NULL;
ret->com.res_id = id;
ret->com.state = RES_FS_RULE_ALLOCATED;
ret->qpn = qpn;
return &ret->com;
}
static struct res_common *alloc_tr(u64 id, enum mlx4_resource type, int slave,
int extra)
{
struct res_common *ret;
switch (type) {
case RES_QP:
ret = alloc_qp_tr(id);
break;
case RES_MPT:
ret = alloc_mpt_tr(id, extra);
break;
case RES_MTT:
ret = alloc_mtt_tr(id, extra);
break;
case RES_EQ:
ret = alloc_eq_tr(id);
break;
case RES_CQ:
ret = alloc_cq_tr(id);
break;
case RES_SRQ:
ret = alloc_srq_tr(id);
break;
case RES_MAC:
printk(KERN_ERR "implementation missing\n");
return NULL;
case RES_COUNTER:
ret = alloc_counter_tr(id);
break;
case RES_XRCD:
ret = alloc_xrcdn_tr(id);
break;
case RES_FS_RULE:
ret = alloc_fs_rule_tr(id, extra);
break;
default:
return NULL;
}
if (ret)
ret->owner = slave;
return ret;
}
static int add_res_range(struct mlx4_dev *dev, int slave, u64 base, int count,
enum mlx4_resource type, int extra)
{
int i;
int err;
struct mlx4_priv *priv = mlx4_priv(dev);
struct res_common **res_arr;
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct rb_root *root = &tracker->res_tree[type];
res_arr = kzalloc(count * sizeof *res_arr, GFP_KERNEL);
if (!res_arr)
return -ENOMEM;
for (i = 0; i < count; ++i) {
res_arr[i] = alloc_tr(base + i, type, slave, extra);
if (!res_arr[i]) {
for (--i; i >= 0; --i)
kfree(res_arr[i]);
kfree(res_arr);
return -ENOMEM;
}
}
spin_lock_irq(mlx4_tlock(dev));
for (i = 0; i < count; ++i) {
if (find_res(dev, base + i, type)) {
err = -EEXIST;
goto undo;
}
err = res_tracker_insert(root, res_arr[i]);
if (err)
goto undo;
list_add_tail(&res_arr[i]->list,
&tracker->slave_list[slave].res_list[type]);
}
spin_unlock_irq(mlx4_tlock(dev));
kfree(res_arr);
return 0;
undo:
for (--i; i >= base; --i)
rb_erase(&res_arr[i]->node, root);
spin_unlock_irq(mlx4_tlock(dev));
for (i = 0; i < count; ++i)
kfree(res_arr[i]);
kfree(res_arr);
return err;
}
static int remove_qp_ok(struct res_qp *res)
{
if (res->com.state == RES_QP_BUSY || atomic_read(&res->ref_count) ||
!list_empty(&res->mcg_list)) {
pr_err("resource tracker: fail to remove qp, state %d, ref_count %d\n",
res->com.state, atomic_read(&res->ref_count));
return -EBUSY;
} else if (res->com.state != RES_QP_RESERVED) {
return -EPERM;
}
return 0;
}
static int remove_mtt_ok(struct res_mtt *res, int order)
{
if (res->com.state == RES_MTT_BUSY ||
atomic_read(&res->ref_count)) {
printk(KERN_DEBUG "%s-%d: state %s, ref_count %d\n",
__func__, __LINE__,
mtt_states_str(res->com.state),
atomic_read(&res->ref_count));
return -EBUSY;
} else if (res->com.state != RES_MTT_ALLOCATED)
return -EPERM;
else if (res->order != order)
return -EINVAL;
return 0;
}
static int remove_mpt_ok(struct res_mpt *res)
{
if (res->com.state == RES_MPT_BUSY)
return -EBUSY;
else if (res->com.state != RES_MPT_RESERVED)
return -EPERM;
return 0;
}
static int remove_eq_ok(struct res_eq *res)
{
if (res->com.state == RES_MPT_BUSY)
return -EBUSY;
else if (res->com.state != RES_MPT_RESERVED)
return -EPERM;
return 0;
}
static int remove_counter_ok(struct res_counter *res)
{
if (res->com.state == RES_COUNTER_BUSY)
return -EBUSY;
else if (res->com.state != RES_COUNTER_ALLOCATED)
return -EPERM;
return 0;
}
static int remove_xrcdn_ok(struct res_xrcdn *res)
{
if (res->com.state == RES_XRCD_BUSY)
return -EBUSY;
else if (res->com.state != RES_XRCD_ALLOCATED)
return -EPERM;
return 0;
}
static int remove_fs_rule_ok(struct res_fs_rule *res)
{
if (res->com.state == RES_FS_RULE_BUSY)
return -EBUSY;
else if (res->com.state != RES_FS_RULE_ALLOCATED)
return -EPERM;
return 0;
}
static int remove_cq_ok(struct res_cq *res)
{
if (res->com.state == RES_CQ_BUSY)
return -EBUSY;
else if (res->com.state != RES_CQ_ALLOCATED)
return -EPERM;
return 0;
}
static int remove_srq_ok(struct res_srq *res)
{
if (res->com.state == RES_SRQ_BUSY)
return -EBUSY;
else if (res->com.state != RES_SRQ_ALLOCATED)
return -EPERM;
return 0;
}
static int remove_ok(struct res_common *res, enum mlx4_resource type, int extra)
{
switch (type) {
case RES_QP:
return remove_qp_ok((struct res_qp *)res);
case RES_CQ:
return remove_cq_ok((struct res_cq *)res);
case RES_SRQ:
return remove_srq_ok((struct res_srq *)res);
case RES_MPT:
return remove_mpt_ok((struct res_mpt *)res);
case RES_MTT:
return remove_mtt_ok((struct res_mtt *)res, extra);
case RES_MAC:
return -ENOSYS;
case RES_EQ:
return remove_eq_ok((struct res_eq *)res);
case RES_COUNTER:
return remove_counter_ok((struct res_counter *)res);
case RES_XRCD:
return remove_xrcdn_ok((struct res_xrcdn *)res);
case RES_FS_RULE:
return remove_fs_rule_ok((struct res_fs_rule *)res);
default:
return -EINVAL;
}
}
static int rem_res_range(struct mlx4_dev *dev, int slave, u64 base, int count,
enum mlx4_resource type, int extra)
{
u64 i;
int err;
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct res_common *r;
spin_lock_irq(mlx4_tlock(dev));
for (i = base; i < base + count; ++i) {
r = res_tracker_lookup(&tracker->res_tree[type], i);
if (!r) {
err = -ENOENT;
goto out;
}
if (r->owner != slave) {
err = -EPERM;
goto out;
}
err = remove_ok(r, type, extra);
if (err)
goto out;
}
for (i = base; i < base + count; ++i) {
r = res_tracker_lookup(&tracker->res_tree[type], i);
rb_erase(&r->node, &tracker->res_tree[type]);
list_del(&r->list);
kfree(r);
}
err = 0;
out:
spin_unlock_irq(mlx4_tlock(dev));
return err;
}
static int qp_res_start_move_to(struct mlx4_dev *dev, int slave, int qpn,
enum res_qp_states state, struct res_qp **qp,
int alloc)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct res_qp *r;
int err = 0;
spin_lock_irq(mlx4_tlock(dev));
r = res_tracker_lookup(&tracker->res_tree[RES_QP], qpn);
if (!r)
err = -ENOENT;
else if (r->com.owner != slave)
err = -EPERM;
else {
switch (state) {
case RES_QP_BUSY:
mlx4_dbg(dev, "%s: failed RES_QP, 0x%llx\n",
__func__, r->com.res_id);
err = -EBUSY;
break;
case RES_QP_RESERVED:
if (r->com.state == RES_QP_MAPPED && !alloc)
break;
mlx4_dbg(dev, "failed RES_QP, 0x%llx\n", r->com.res_id);
err = -EINVAL;
break;
case RES_QP_MAPPED:
if ((r->com.state == RES_QP_RESERVED && alloc) ||
r->com.state == RES_QP_HW)
break;
else {
mlx4_dbg(dev, "failed RES_QP, 0x%llx\n",
r->com.res_id);
err = -EINVAL;
}
break;
case RES_QP_HW:
if (r->com.state != RES_QP_MAPPED)
err = -EINVAL;
break;
default:
err = -EINVAL;
}
if (!err) {
r->com.from_state = r->com.state;
r->com.to_state = state;
r->com.state = RES_QP_BUSY;
if (qp)
*qp = r;
}
}
spin_unlock_irq(mlx4_tlock(dev));
return err;
}
static int mr_res_start_move_to(struct mlx4_dev *dev, int slave, int index,
enum res_mpt_states state, struct res_mpt **mpt)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct res_mpt *r;
int err = 0;
spin_lock_irq(mlx4_tlock(dev));
r = res_tracker_lookup(&tracker->res_tree[RES_MPT], index);
if (!r)
err = -ENOENT;
else if (r->com.owner != slave)
err = -EPERM;
else {
switch (state) {
case RES_MPT_BUSY:
err = -EINVAL;
break;
case RES_MPT_RESERVED:
if (r->com.state != RES_MPT_MAPPED)
err = -EINVAL;
break;
case RES_MPT_MAPPED:
if (r->com.state != RES_MPT_RESERVED &&
r->com.state != RES_MPT_HW)
err = -EINVAL;
break;
case RES_MPT_HW:
if (r->com.state != RES_MPT_MAPPED)
err = -EINVAL;
break;
default:
err = -EINVAL;
}
if (!err) {
r->com.from_state = r->com.state;
r->com.to_state = state;
r->com.state = RES_MPT_BUSY;
if (mpt)
*mpt = r;
}
}
spin_unlock_irq(mlx4_tlock(dev));
return err;
}
static int eq_res_start_move_to(struct mlx4_dev *dev, int slave, int index,
enum res_eq_states state, struct res_eq **eq)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct res_eq *r;
int err = 0;
spin_lock_irq(mlx4_tlock(dev));
r = res_tracker_lookup(&tracker->res_tree[RES_EQ], index);
if (!r)
err = -ENOENT;
else if (r->com.owner != slave)
err = -EPERM;
else {
switch (state) {
case RES_EQ_BUSY:
err = -EINVAL;
break;
case RES_EQ_RESERVED:
if (r->com.state != RES_EQ_HW)
err = -EINVAL;
break;
case RES_EQ_HW:
if (r->com.state != RES_EQ_RESERVED)
err = -EINVAL;
break;
default:
err = -EINVAL;
}
if (!err) {
r->com.from_state = r->com.state;
r->com.to_state = state;
r->com.state = RES_EQ_BUSY;
if (eq)
*eq = r;
}
}
spin_unlock_irq(mlx4_tlock(dev));
return err;
}
static int cq_res_start_move_to(struct mlx4_dev *dev, int slave, int cqn,
enum res_cq_states state, struct res_cq **cq)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct res_cq *r;
int err;
spin_lock_irq(mlx4_tlock(dev));
r = res_tracker_lookup(&tracker->res_tree[RES_CQ], cqn);
if (!r) {
err = -ENOENT;
} else if (r->com.owner != slave) {
err = -EPERM;
} else if (state == RES_CQ_ALLOCATED) {
if (r->com.state != RES_CQ_HW)
err = -EINVAL;
else if (atomic_read(&r->ref_count))
err = -EBUSY;
else
err = 0;
} else if (state != RES_CQ_HW || r->com.state != RES_CQ_ALLOCATED) {
err = -EINVAL;
} else {
err = 0;
}
if (!err) {
r->com.from_state = r->com.state;
r->com.to_state = state;
r->com.state = RES_CQ_BUSY;
if (cq)
*cq = r;
}
spin_unlock_irq(mlx4_tlock(dev));
return err;
}
static int srq_res_start_move_to(struct mlx4_dev *dev, int slave, int index,
enum res_srq_states state, struct res_srq **srq)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct res_srq *r;
int err = 0;
spin_lock_irq(mlx4_tlock(dev));
r = res_tracker_lookup(&tracker->res_tree[RES_SRQ], index);
if (!r) {
err = -ENOENT;
} else if (r->com.owner != slave) {
err = -EPERM;
} else if (state == RES_SRQ_ALLOCATED) {
if (r->com.state != RES_SRQ_HW)
err = -EINVAL;
else if (atomic_read(&r->ref_count))
err = -EBUSY;
} else if (state != RES_SRQ_HW || r->com.state != RES_SRQ_ALLOCATED) {
err = -EINVAL;
}
if (!err) {
r->com.from_state = r->com.state;
r->com.to_state = state;
r->com.state = RES_SRQ_BUSY;
if (srq)
*srq = r;
}
spin_unlock_irq(mlx4_tlock(dev));
return err;
}
static void res_abort_move(struct mlx4_dev *dev, int slave,
enum mlx4_resource type, int id)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct res_common *r;
spin_lock_irq(mlx4_tlock(dev));
r = res_tracker_lookup(&tracker->res_tree[type], id);
if (r && (r->owner == slave))
r->state = r->from_state;
spin_unlock_irq(mlx4_tlock(dev));
}
static void res_end_move(struct mlx4_dev *dev, int slave,
enum mlx4_resource type, int id)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct res_common *r;
spin_lock_irq(mlx4_tlock(dev));
r = res_tracker_lookup(&tracker->res_tree[type], id);
if (r && (r->owner == slave))
r->state = r->to_state;
spin_unlock_irq(mlx4_tlock(dev));
}
static int valid_reserved(struct mlx4_dev *dev, int slave, int qpn)
{
return mlx4_is_qp_reserved(dev, qpn) &&
(mlx4_is_master(dev) || mlx4_is_guest_proxy(dev, slave, qpn));
}
static int fw_reserved(struct mlx4_dev *dev, int qpn)
{
return qpn < dev->caps.reserved_qps_cnt[MLX4_QP_REGION_FW];
}
static int qp_alloc_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
int err;
int count;
int align;
int base;
int qpn;
switch (op) {
case RES_OP_RESERVE:
count = get_param_l(&in_param);
align = get_param_h(&in_param);
err = mlx4_grant_resource(dev, slave, RES_QP, count, 0);
if (err)
return err;
err = __mlx4_qp_reserve_range(dev, count, align, &base);
if (err) {
mlx4_release_resource(dev, slave, RES_QP, count, 0);
return err;
}
err = add_res_range(dev, slave, base, count, RES_QP, 0);
if (err) {
mlx4_release_resource(dev, slave, RES_QP, count, 0);
__mlx4_qp_release_range(dev, base, count);
return err;
}
set_param_l(out_param, base);
break;
case RES_OP_MAP_ICM:
qpn = get_param_l(&in_param) & 0x7fffff;
if (valid_reserved(dev, slave, qpn)) {
err = add_res_range(dev, slave, qpn, 1, RES_QP, 0);
if (err)
return err;
}
err = qp_res_start_move_to(dev, slave, qpn, RES_QP_MAPPED,
NULL, 1);
if (err)
return err;
if (!fw_reserved(dev, qpn)) {
err = __mlx4_qp_alloc_icm(dev, qpn);
if (err) {
res_abort_move(dev, slave, RES_QP, qpn);
return err;
}
}
res_end_move(dev, slave, RES_QP, qpn);
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int mtt_alloc_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
int err = -EINVAL;
int base;
int order;
if (op != RES_OP_RESERVE_AND_MAP)
return err;
order = get_param_l(&in_param);
err = mlx4_grant_resource(dev, slave, RES_MTT, 1 << order, 0);
if (err)
return err;
base = __mlx4_alloc_mtt_range(dev, order);
if (base == -1) {
mlx4_release_resource(dev, slave, RES_MTT, 1 << order, 0);
return -ENOMEM;
}
err = add_res_range(dev, slave, base, 1, RES_MTT, order);
if (err) {
mlx4_release_resource(dev, slave, RES_MTT, 1 << order, 0);
__mlx4_free_mtt_range(dev, base, order);
} else {
set_param_l(out_param, base);
}
return err;
}
static int mpt_alloc_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
int err = -EINVAL;
int index;
int id;
struct res_mpt *mpt;
switch (op) {
case RES_OP_RESERVE:
err = mlx4_grant_resource(dev, slave, RES_MPT, 1, 0);
if (err)
break;
index = __mlx4_mpt_reserve(dev);
if (index == -1) {
mlx4_release_resource(dev, slave, RES_MPT, 1, 0);
break;
}
id = index & mpt_mask(dev);
err = add_res_range(dev, slave, id, 1, RES_MPT, index);
if (err) {
mlx4_release_resource(dev, slave, RES_MPT, 1, 0);
__mlx4_mpt_release(dev, index);
break;
}
set_param_l(out_param, index);
break;
case RES_OP_MAP_ICM:
index = get_param_l(&in_param);
id = index & mpt_mask(dev);
err = mr_res_start_move_to(dev, slave, id,
RES_MPT_MAPPED, &mpt);
if (err)
return err;
err = __mlx4_mpt_alloc_icm(dev, mpt->key);
if (err) {
res_abort_move(dev, slave, RES_MPT, id);
return err;
}
res_end_move(dev, slave, RES_MPT, id);
break;
}
return err;
}
static int cq_alloc_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
int cqn;
int err;
switch (op) {
case RES_OP_RESERVE_AND_MAP:
err = mlx4_grant_resource(dev, slave, RES_CQ, 1, 0);
if (err)
break;
err = __mlx4_cq_alloc_icm(dev, &cqn);
if (err) {
mlx4_release_resource(dev, slave, RES_CQ, 1, 0);
break;
}
err = add_res_range(dev, slave, cqn, 1, RES_CQ, 0);
if (err) {
mlx4_release_resource(dev, slave, RES_CQ, 1, 0);
__mlx4_cq_free_icm(dev, cqn);
break;
}
set_param_l(out_param, cqn);
break;
default:
err = -EINVAL;
}
return err;
}
static int srq_alloc_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
int srqn;
int err;
switch (op) {
case RES_OP_RESERVE_AND_MAP:
err = mlx4_grant_resource(dev, slave, RES_SRQ, 1, 0);
if (err)
break;
err = __mlx4_srq_alloc_icm(dev, &srqn);
if (err) {
mlx4_release_resource(dev, slave, RES_SRQ, 1, 0);
break;
}
err = add_res_range(dev, slave, srqn, 1, RES_SRQ, 0);
if (err) {
mlx4_release_resource(dev, slave, RES_SRQ, 1, 0);
__mlx4_srq_free_icm(dev, srqn);
break;
}
set_param_l(out_param, srqn);
break;
default:
err = -EINVAL;
}
return err;
}
static int mac_add_to_slave(struct mlx4_dev *dev, int slave, u64 mac, int port)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct mac_res *res;
if (mlx4_grant_resource(dev, slave, RES_MAC, 1, port))
return -EINVAL;
res = kzalloc(sizeof *res, GFP_KERNEL);
if (!res) {
mlx4_release_resource(dev, slave, RES_MAC, 1, port);
return -ENOMEM;
}
res->mac = mac;
res->port = (u8) port;
list_add_tail(&res->list,
&tracker->slave_list[slave].res_list[RES_MAC]);
return 0;
}
static void mac_del_from_slave(struct mlx4_dev *dev, int slave, u64 mac,
int port)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *mac_list =
&tracker->slave_list[slave].res_list[RES_MAC];
struct mac_res *res, *tmp;
list_for_each_entry_safe(res, tmp, mac_list, list) {
if (res->mac == mac && res->port == (u8) port) {
list_del(&res->list);
mlx4_release_resource(dev, slave, RES_MAC, 1, port);
kfree(res);
break;
}
}
}
static void rem_slave_macs(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *mac_list =
&tracker->slave_list[slave].res_list[RES_MAC];
struct mac_res *res, *tmp;
list_for_each_entry_safe(res, tmp, mac_list, list) {
list_del(&res->list);
__mlx4_unregister_mac(dev, res->port, res->mac);
mlx4_release_resource(dev, slave, RES_MAC, 1, res->port);
kfree(res);
}
}
static int mac_alloc_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param, int in_port)
{
int err = -EINVAL;
int port;
u64 mac;
if (op != RES_OP_RESERVE_AND_MAP)
return err;
port = !in_port ? get_param_l(out_param) : in_port;
mac = in_param;
err = __mlx4_register_mac(dev, port, mac);
if (err >= 0) {
set_param_l(out_param, err);
err = 0;
}
if (!err) {
err = mac_add_to_slave(dev, slave, mac, port);
if (err)
__mlx4_unregister_mac(dev, port, mac);
}
return err;
}
static int vlan_add_to_slave(struct mlx4_dev *dev, int slave, u16 vlan,
int port, int vlan_index)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *vlan_list =
&tracker->slave_list[slave].res_list[RES_VLAN];
struct vlan_res *res, *tmp;
list_for_each_entry_safe(res, tmp, vlan_list, list) {
if (res->vlan == vlan && res->port == (u8) port) {
++res->ref_count;
return 0;
}
}
if (mlx4_grant_resource(dev, slave, RES_VLAN, 1, port))
return -EINVAL;
res = kzalloc(sizeof(*res), GFP_KERNEL);
if (!res) {
mlx4_release_resource(dev, slave, RES_VLAN, 1, port);
return -ENOMEM;
}
res->vlan = vlan;
res->port = (u8) port;
res->vlan_index = vlan_index;
res->ref_count = 1;
list_add_tail(&res->list,
&tracker->slave_list[slave].res_list[RES_VLAN]);
return 0;
}
static void vlan_del_from_slave(struct mlx4_dev *dev, int slave, u16 vlan,
int port)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *vlan_list =
&tracker->slave_list[slave].res_list[RES_VLAN];
struct vlan_res *res, *tmp;
list_for_each_entry_safe(res, tmp, vlan_list, list) {
if (res->vlan == vlan && res->port == (u8) port) {
if (!--res->ref_count) {
list_del(&res->list);
mlx4_release_resource(dev, slave, RES_VLAN,
1, port);
kfree(res);
}
break;
}
}
}
static void rem_slave_vlans(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *vlan_list =
&tracker->slave_list[slave].res_list[RES_VLAN];
struct vlan_res *res, *tmp;
int i;
list_for_each_entry_safe(res, tmp, vlan_list, list) {
list_del(&res->list);
for (i = 0; i < res->ref_count; i++)
__mlx4_unregister_vlan(dev, res->port, res->vlan);
mlx4_release_resource(dev, slave, RES_VLAN, 1, res->port);
kfree(res);
}
}
static int vlan_alloc_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param, int in_port)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_slave_state *slave_state = priv->mfunc.master.slave_state;
int err;
u16 vlan;
int vlan_index;
int port;
port = !in_port ? get_param_l(out_param) : in_port;
if (!port || op != RES_OP_RESERVE_AND_MAP)
return -EINVAL;
if (!in_port && port > 0 && port <= dev->caps.num_ports) {
slave_state[slave].old_vlan_api = true;
return 0;
}
vlan = (u16) in_param;
err = __mlx4_register_vlan(dev, port, vlan, &vlan_index);
if (!err) {
set_param_l(out_param, (u32) vlan_index);
err = vlan_add_to_slave(dev, slave, vlan, port, vlan_index);
if (err)
__mlx4_unregister_vlan(dev, port, vlan);
}
return err;
}
static int counter_alloc_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
u32 index;
int err;
if (op != RES_OP_RESERVE)
return -EINVAL;
err = mlx4_grant_resource(dev, slave, RES_COUNTER, 1, 0);
if (err)
return err;
err = __mlx4_counter_alloc(dev, &index);
if (err) {
mlx4_release_resource(dev, slave, RES_COUNTER, 1, 0);
return err;
}
err = add_res_range(dev, slave, index, 1, RES_COUNTER, 0);
if (err) {
__mlx4_counter_free(dev, index);
mlx4_release_resource(dev, slave, RES_COUNTER, 1, 0);
} else {
set_param_l(out_param, index);
}
return err;
}
static int xrcdn_alloc_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
u32 xrcdn;
int err;
if (op != RES_OP_RESERVE)
return -EINVAL;
err = __mlx4_xrcd_alloc(dev, &xrcdn);
if (err)
return err;
err = add_res_range(dev, slave, xrcdn, 1, RES_XRCD, 0);
if (err)
__mlx4_xrcd_free(dev, xrcdn);
else
set_param_l(out_param, xrcdn);
return err;
}
int mlx4_ALLOC_RES_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int alop = vhcr->op_modifier;
switch (vhcr->in_modifier & 0xFF) {
case RES_QP:
err = qp_alloc_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
break;
case RES_MTT:
err = mtt_alloc_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
break;
case RES_MPT:
err = mpt_alloc_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
break;
case RES_CQ:
err = cq_alloc_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
break;
case RES_SRQ:
err = srq_alloc_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
break;
case RES_MAC:
err = mac_alloc_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param,
(vhcr->in_modifier >> 8) & 0xFF);
break;
case RES_VLAN:
err = vlan_alloc_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param,
(vhcr->in_modifier >> 8) & 0xFF);
break;
case RES_COUNTER:
err = counter_alloc_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
break;
case RES_XRCD:
err = xrcdn_alloc_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int qp_free_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param)
{
int err;
int count;
int base;
int qpn;
switch (op) {
case RES_OP_RESERVE:
base = get_param_l(&in_param) & 0x7fffff;
count = get_param_h(&in_param);
err = rem_res_range(dev, slave, base, count, RES_QP, 0);
if (err)
break;
mlx4_release_resource(dev, slave, RES_QP, count, 0);
__mlx4_qp_release_range(dev, base, count);
break;
case RES_OP_MAP_ICM:
qpn = get_param_l(&in_param) & 0x7fffff;
err = qp_res_start_move_to(dev, slave, qpn, RES_QP_RESERVED,
NULL, 0);
if (err)
return err;
if (!fw_reserved(dev, qpn))
__mlx4_qp_free_icm(dev, qpn);
res_end_move(dev, slave, RES_QP, qpn);
if (valid_reserved(dev, slave, qpn))
err = rem_res_range(dev, slave, qpn, 1, RES_QP, 0);
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int mtt_free_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
int err = -EINVAL;
int base;
int order;
if (op != RES_OP_RESERVE_AND_MAP)
return err;
base = get_param_l(&in_param);
order = get_param_h(&in_param);
err = rem_res_range(dev, slave, base, 1, RES_MTT, order);
if (!err) {
mlx4_release_resource(dev, slave, RES_MTT, 1 << order, 0);
__mlx4_free_mtt_range(dev, base, order);
}
return err;
}
static int mpt_free_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param)
{
int err = -EINVAL;
int index;
int id;
struct res_mpt *mpt;
switch (op) {
case RES_OP_RESERVE:
index = get_param_l(&in_param);
id = index & mpt_mask(dev);
err = get_res(dev, slave, id, RES_MPT, &mpt);
if (err)
break;
index = mpt->key;
put_res(dev, slave, id, RES_MPT);
err = rem_res_range(dev, slave, id, 1, RES_MPT, 0);
if (err)
break;
mlx4_release_resource(dev, slave, RES_MPT, 1, 0);
__mlx4_mpt_release(dev, index);
break;
case RES_OP_MAP_ICM:
index = get_param_l(&in_param);
id = index & mpt_mask(dev);
err = mr_res_start_move_to(dev, slave, id,
RES_MPT_RESERVED, &mpt);
if (err)
return err;
__mlx4_mpt_free_icm(dev, mpt->key);
res_end_move(dev, slave, RES_MPT, id);
return err;
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int cq_free_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
int cqn;
int err;
switch (op) {
case RES_OP_RESERVE_AND_MAP:
cqn = get_param_l(&in_param);
err = rem_res_range(dev, slave, cqn, 1, RES_CQ, 0);
if (err)
break;
mlx4_release_resource(dev, slave, RES_CQ, 1, 0);
__mlx4_cq_free_icm(dev, cqn);
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int srq_free_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
int srqn;
int err;
switch (op) {
case RES_OP_RESERVE_AND_MAP:
srqn = get_param_l(&in_param);
err = rem_res_range(dev, slave, srqn, 1, RES_SRQ, 0);
if (err)
break;
mlx4_release_resource(dev, slave, RES_SRQ, 1, 0);
__mlx4_srq_free_icm(dev, srqn);
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int mac_free_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param, int in_port)
{
int port;
int err = 0;
switch (op) {
case RES_OP_RESERVE_AND_MAP:
port = !in_port ? get_param_l(out_param) : in_port;
mac_del_from_slave(dev, slave, in_param, port);
__mlx4_unregister_mac(dev, port, in_param);
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int vlan_free_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param, int port)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_slave_state *slave_state = priv->mfunc.master.slave_state;
int err = 0;
switch (op) {
case RES_OP_RESERVE_AND_MAP:
if (slave_state[slave].old_vlan_api)
return 0;
if (!port)
return -EINVAL;
vlan_del_from_slave(dev, slave, in_param, port);
__mlx4_unregister_vlan(dev, port, in_param);
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int counter_free_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
int index;
int err;
if (op != RES_OP_RESERVE)
return -EINVAL;
index = get_param_l(&in_param);
err = rem_res_range(dev, slave, index, 1, RES_COUNTER, 0);
if (err)
return err;
__mlx4_counter_free(dev, index);
mlx4_release_resource(dev, slave, RES_COUNTER, 1, 0);
return err;
}
static int xrcdn_free_res(struct mlx4_dev *dev, int slave, int op, int cmd,
u64 in_param, u64 *out_param)
{
int xrcdn;
int err;
if (op != RES_OP_RESERVE)
return -EINVAL;
xrcdn = get_param_l(&in_param);
err = rem_res_range(dev, slave, xrcdn, 1, RES_XRCD, 0);
if (err)
return err;
__mlx4_xrcd_free(dev, xrcdn);
return err;
}
int mlx4_FREE_RES_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err = -EINVAL;
int alop = vhcr->op_modifier;
switch (vhcr->in_modifier & 0xFF) {
case RES_QP:
err = qp_free_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param);
break;
case RES_MTT:
err = mtt_free_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
break;
case RES_MPT:
err = mpt_free_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param);
break;
case RES_CQ:
err = cq_free_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
break;
case RES_SRQ:
err = srq_free_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
break;
case RES_MAC:
err = mac_free_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param,
(vhcr->in_modifier >> 8) & 0xFF);
break;
case RES_VLAN:
err = vlan_free_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param,
(vhcr->in_modifier >> 8) & 0xFF);
break;
case RES_COUNTER:
err = counter_free_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
break;
case RES_XRCD:
err = xrcdn_free_res(dev, slave, vhcr->op_modifier, alop,
vhcr->in_param, &vhcr->out_param);
default:
break;
}
return err;
}
static int mr_phys_mpt(struct mlx4_mpt_entry *mpt)
{
return (be32_to_cpu(mpt->flags) >> 9) & 1;
}
static int mr_get_mtt_addr(struct mlx4_mpt_entry *mpt)
{
return (int)be64_to_cpu(mpt->mtt_addr) & 0xfffffff8;
}
static int mr_get_mtt_size(struct mlx4_mpt_entry *mpt)
{
return be32_to_cpu(mpt->mtt_sz);
}
static u32 mr_get_pd(struct mlx4_mpt_entry *mpt)
{
return be32_to_cpu(mpt->pd_flags) & 0x00ffffff;
}
static int mr_is_fmr(struct mlx4_mpt_entry *mpt)
{
return be32_to_cpu(mpt->pd_flags) & MLX4_MPT_PD_FLAG_FAST_REG;
}
static int mr_is_bind_enabled(struct mlx4_mpt_entry *mpt)
{
return be32_to_cpu(mpt->flags) & MLX4_MPT_FLAG_BIND_ENABLE;
}
static int mr_is_region(struct mlx4_mpt_entry *mpt)
{
return be32_to_cpu(mpt->flags) & MLX4_MPT_FLAG_REGION;
}
static int qp_get_mtt_addr(struct mlx4_qp_context *qpc)
{
return be32_to_cpu(qpc->mtt_base_addr_l) & 0xfffffff8;
}
static int srq_get_mtt_addr(struct mlx4_srq_context *srqc)
{
return be32_to_cpu(srqc->mtt_base_addr_l) & 0xfffffff8;
}
static int qp_get_mtt_size(struct mlx4_qp_context *qpc)
{
int page_shift = (qpc->log_page_size & 0x3f) + 12;
int log_sq_size = (qpc->sq_size_stride >> 3) & 0xf;
int log_sq_sride = qpc->sq_size_stride & 7;
int log_rq_size = (qpc->rq_size_stride >> 3) & 0xf;
int log_rq_stride = qpc->rq_size_stride & 7;
int srq = (be32_to_cpu(qpc->srqn) >> 24) & 1;
int rss = (be32_to_cpu(qpc->flags) >> 13) & 1;
u32 ts = (be32_to_cpu(qpc->flags) >> 16) & 0xff;
int xrc = (ts == MLX4_QP_ST_XRC) ? 1 : 0;
int sq_size;
int rq_size;
int total_pages;
int total_mem;
int page_offset = (be32_to_cpu(qpc->params2) >> 6) & 0x3f;
sq_size = 1 << (log_sq_size + log_sq_sride + 4);
rq_size = (srq|rss|xrc) ? 0 : (1 << (log_rq_size + log_rq_stride + 4));
total_mem = sq_size + rq_size;
total_pages =
roundup_pow_of_two((total_mem + (page_offset << 6)) >>
page_shift);
return total_pages;
}
static int check_mtt_range(struct mlx4_dev *dev, int slave, int start,
int size, struct res_mtt *mtt)
{
int res_start = mtt->com.res_id;
int res_size = (1 << mtt->order);
if (start < res_start || start + size > res_start + res_size)
return -EPERM;
return 0;
}
int mlx4_SW2HW_MPT_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int index = vhcr->in_modifier;
struct res_mtt *mtt;
struct res_mpt *mpt;
int mtt_base = mr_get_mtt_addr(inbox->buf) / dev->caps.mtt_entry_sz;
int phys;
int id;
u32 pd;
int pd_slave;
id = index & mpt_mask(dev);
err = mr_res_start_move_to(dev, slave, id, RES_MPT_HW, &mpt);
if (err)
return err;
if (!mr_is_region(inbox->buf)) {
err = -EPERM;
goto ex_abort;
}
pd = mr_get_pd(inbox->buf);
pd_slave = (pd >> 17) & 0x7f;
if (pd_slave != 0 && pd_slave != slave) {
err = -EPERM;
goto ex_abort;
}
if (mr_is_fmr(inbox->buf)) {
if (mr_is_bind_enabled(inbox->buf)) {
err = -EPERM;
goto ex_abort;
}
if (!mr_is_region(inbox->buf)) {
err = -EPERM;
goto ex_abort;
}
}
phys = mr_phys_mpt(inbox->buf);
if (!phys) {
err = get_res(dev, slave, mtt_base, RES_MTT, &mtt);
if (err)
goto ex_abort;
err = check_mtt_range(dev, slave, mtt_base,
mr_get_mtt_size(inbox->buf), mtt);
if (err)
goto ex_put;
mpt->mtt = mtt;
}
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
if (err)
goto ex_put;
if (!phys) {
atomic_inc(&mtt->ref_count);
put_res(dev, slave, mtt->com.res_id, RES_MTT);
}
res_end_move(dev, slave, RES_MPT, id);
return 0;
ex_put:
if (!phys)
put_res(dev, slave, mtt->com.res_id, RES_MTT);
ex_abort:
res_abort_move(dev, slave, RES_MPT, id);
return err;
}
int mlx4_HW2SW_MPT_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int index = vhcr->in_modifier;
struct res_mpt *mpt;
int id;
id = index & mpt_mask(dev);
err = mr_res_start_move_to(dev, slave, id, RES_MPT_MAPPED, &mpt);
if (err)
return err;
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
if (err)
goto ex_abort;
if (mpt->mtt)
atomic_dec(&mpt->mtt->ref_count);
res_end_move(dev, slave, RES_MPT, id);
return 0;
ex_abort:
res_abort_move(dev, slave, RES_MPT, id);
return err;
}
int mlx4_QUERY_MPT_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int index = vhcr->in_modifier;
struct res_mpt *mpt;
int id;
id = index & mpt_mask(dev);
err = get_res(dev, slave, id, RES_MPT, &mpt);
if (err)
return err;
if (mpt->com.from_state != RES_MPT_HW) {
err = -EBUSY;
goto out;
}
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
out:
put_res(dev, slave, id, RES_MPT);
return err;
}
static int qp_get_rcqn(struct mlx4_qp_context *qpc)
{
return be32_to_cpu(qpc->cqn_recv) & 0xffffff;
}
static int qp_get_scqn(struct mlx4_qp_context *qpc)
{
return be32_to_cpu(qpc->cqn_send) & 0xffffff;
}
static u32 qp_get_srqn(struct mlx4_qp_context *qpc)
{
return be32_to_cpu(qpc->srqn) & 0x1ffffff;
}
static void adjust_proxy_tun_qkey(struct mlx4_dev *dev, struct mlx4_vhcr *vhcr,
struct mlx4_qp_context *context)
{
u32 qpn = vhcr->in_modifier & 0xffffff;
u32 qkey = 0;
if (mlx4_get_parav_qkey(dev, qpn, &qkey))
return;
context->qkey = cpu_to_be32(qkey);
}
int mlx4_RST2INIT_QP_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int qpn = vhcr->in_modifier & 0x7fffff;
struct res_mtt *mtt;
struct res_qp *qp;
struct mlx4_qp_context *qpc = inbox->buf + 8;
int mtt_base = qp_get_mtt_addr(qpc) / dev->caps.mtt_entry_sz;
int mtt_size = qp_get_mtt_size(qpc);
struct res_cq *rcq;
struct res_cq *scq;
int rcqn = qp_get_rcqn(qpc);
int scqn = qp_get_scqn(qpc);
u32 srqn = qp_get_srqn(qpc) & 0xffffff;
int use_srq = (qp_get_srqn(qpc) >> 24) & 1;
struct res_srq *srq;
int local_qpn = be32_to_cpu(qpc->local_qpn) & 0xffffff;
err = qp_res_start_move_to(dev, slave, qpn, RES_QP_HW, &qp, 0);
if (err)
return err;
qp->local_qpn = local_qpn;
qp->sched_queue = 0;
qp->param3 = 0;
qp->vlan_control = 0;
qp->fvl_rx = 0;
qp->pri_path_fl = 0;
qp->vlan_index = 0;
qp->feup = 0;
qp->qpc_flags = be32_to_cpu(qpc->flags);
err = get_res(dev, slave, mtt_base, RES_MTT, &mtt);
if (err)
goto ex_abort;
err = check_mtt_range(dev, slave, mtt_base, mtt_size, mtt);
if (err)
goto ex_put_mtt;
err = get_res(dev, slave, rcqn, RES_CQ, &rcq);
if (err)
goto ex_put_mtt;
if (scqn != rcqn) {
err = get_res(dev, slave, scqn, RES_CQ, &scq);
if (err)
goto ex_put_rcq;
} else
scq = rcq;
if (use_srq) {
err = get_res(dev, slave, srqn, RES_SRQ, &srq);
if (err)
goto ex_put_scq;
}
adjust_proxy_tun_qkey(dev, vhcr, qpc);
update_pkey_index(dev, slave, inbox);
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
if (err)
goto ex_put_srq;
atomic_inc(&mtt->ref_count);
qp->mtt = mtt;
atomic_inc(&rcq->ref_count);
qp->rcq = rcq;
atomic_inc(&scq->ref_count);
qp->scq = scq;
if (scqn != rcqn)
put_res(dev, slave, scqn, RES_CQ);
if (use_srq) {
atomic_inc(&srq->ref_count);
put_res(dev, slave, srqn, RES_SRQ);
qp->srq = srq;
}
put_res(dev, slave, rcqn, RES_CQ);
put_res(dev, slave, mtt_base, RES_MTT);
res_end_move(dev, slave, RES_QP, qpn);
return 0;
ex_put_srq:
if (use_srq)
put_res(dev, slave, srqn, RES_SRQ);
ex_put_scq:
if (scqn != rcqn)
put_res(dev, slave, scqn, RES_CQ);
ex_put_rcq:
put_res(dev, slave, rcqn, RES_CQ);
ex_put_mtt:
put_res(dev, slave, mtt_base, RES_MTT);
ex_abort:
res_abort_move(dev, slave, RES_QP, qpn);
return err;
}
static int eq_get_mtt_addr(struct mlx4_eq_context *eqc)
{
return be32_to_cpu(eqc->mtt_base_addr_l) & 0xfffffff8;
}
static int eq_get_mtt_size(struct mlx4_eq_context *eqc)
{
int log_eq_size = eqc->log_eq_size & 0x1f;
int page_shift = (eqc->log_page_size & 0x3f) + 12;
if (log_eq_size + 5 < page_shift)
return 1;
return 1 << (log_eq_size + 5 - page_shift);
}
static int cq_get_mtt_addr(struct mlx4_cq_context *cqc)
{
return be32_to_cpu(cqc->mtt_base_addr_l) & 0xfffffff8;
}
static int cq_get_mtt_size(struct mlx4_cq_context *cqc)
{
int log_cq_size = (be32_to_cpu(cqc->logsize_usrpage) >> 24) & 0x1f;
int page_shift = (cqc->log_page_size & 0x3f) + 12;
if (log_cq_size + 5 < page_shift)
return 1;
return 1 << (log_cq_size + 5 - page_shift);
}
int mlx4_SW2HW_EQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int eqn = vhcr->in_modifier;
int res_id = (slave << 8) | eqn;
struct mlx4_eq_context *eqc = inbox->buf;
int mtt_base = eq_get_mtt_addr(eqc) / dev->caps.mtt_entry_sz;
int mtt_size = eq_get_mtt_size(eqc);
struct res_eq *eq;
struct res_mtt *mtt;
err = add_res_range(dev, slave, res_id, 1, RES_EQ, 0);
if (err)
return err;
err = eq_res_start_move_to(dev, slave, res_id, RES_EQ_HW, &eq);
if (err)
goto out_add;
err = get_res(dev, slave, mtt_base, RES_MTT, &mtt);
if (err)
goto out_move;
err = check_mtt_range(dev, slave, mtt_base, mtt_size, mtt);
if (err)
goto out_put;
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
if (err)
goto out_put;
atomic_inc(&mtt->ref_count);
eq->mtt = mtt;
put_res(dev, slave, mtt->com.res_id, RES_MTT);
res_end_move(dev, slave, RES_EQ, res_id);
return 0;
out_put:
put_res(dev, slave, mtt->com.res_id, RES_MTT);
out_move:
res_abort_move(dev, slave, RES_EQ, res_id);
out_add:
rem_res_range(dev, slave, res_id, 1, RES_EQ, 0);
return err;
}
static int get_containing_mtt(struct mlx4_dev *dev, int slave, int start,
int len, struct res_mtt **res)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct res_mtt *mtt;
int err = -EINVAL;
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry(mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if (!check_mtt_range(dev, slave, start, len, mtt)) {
*res = mtt;
mtt->com.from_state = mtt->com.state;
mtt->com.state = RES_MTT_BUSY;
err = 0;
break;
}
}
spin_unlock_irq(mlx4_tlock(dev));
return err;
}
static int verify_qp_parameters(struct mlx4_dev *dev,
struct mlx4_cmd_mailbox *inbox,
enum qp_transition transition, u8 slave)
{
u32 qp_type;
struct mlx4_qp_context *qp_ctx;
enum mlx4_qp_optpar optpar;
qp_ctx = inbox->buf + 8;
qp_type = (be32_to_cpu(qp_ctx->flags) >> 16) & 0xff;
optpar = be32_to_cpu(*(__be32 *) inbox->buf);
switch (qp_type) {
case MLX4_QP_ST_RC:
case MLX4_QP_ST_UC:
switch (transition) {
case QP_TRANS_INIT2RTR:
case QP_TRANS_RTR2RTS:
case QP_TRANS_RTS2RTS:
case QP_TRANS_SQD2SQD:
case QP_TRANS_SQD2RTS:
if (slave != mlx4_master_func_num(dev))
if (optpar & MLX4_QP_OPTPAR_PRIMARY_ADDR_PATH)
if (qp_ctx->pri_path.mgid_index)
return -EINVAL;
if (optpar & MLX4_QP_OPTPAR_ALT_ADDR_PATH)
if (qp_ctx->alt_path.mgid_index)
return -EINVAL;
break;
default:
break;
}
break;
default:
break;
}
return 0;
}
int mlx4_WRITE_MTT_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
struct mlx4_mtt mtt;
__be64 *page_list = inbox->buf;
u64 *pg_list = (u64 *)page_list;
int i;
struct res_mtt *rmtt = NULL;
int start = be64_to_cpu(page_list[0]);
int npages = vhcr->in_modifier;
int err;
err = get_containing_mtt(dev, slave, start, npages, &rmtt);
if (err)
return err;
mtt.offset = 0;
mtt.order = 0;
mtt.page_shift = 0;
for (i = 0; i < npages; ++i)
pg_list[i + 2] = (be64_to_cpu(page_list[i + 2]) & ~1ULL);
err = __mlx4_write_mtt(dev, &mtt, be64_to_cpu(page_list[0]), npages,
((u64 *)page_list + 2));
if (rmtt)
put_res(dev, slave, rmtt->com.res_id, RES_MTT);
return err;
}
int mlx4_HW2SW_EQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int eqn = vhcr->in_modifier;
int res_id = eqn | (slave << 8);
struct res_eq *eq;
int err;
err = eq_res_start_move_to(dev, slave, res_id, RES_EQ_RESERVED, &eq);
if (err)
return err;
err = get_res(dev, slave, eq->mtt->com.res_id, RES_MTT, NULL);
if (err)
goto ex_abort;
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
if (err)
goto ex_put;
atomic_dec(&eq->mtt->ref_count);
put_res(dev, slave, eq->mtt->com.res_id, RES_MTT);
res_end_move(dev, slave, RES_EQ, res_id);
rem_res_range(dev, slave, res_id, 1, RES_EQ, 0);
return 0;
ex_put:
put_res(dev, slave, eq->mtt->com.res_id, RES_MTT);
ex_abort:
res_abort_move(dev, slave, RES_EQ, res_id);
return err;
}
int mlx4_GEN_EQE(struct mlx4_dev *dev, int slave, struct mlx4_eqe *eqe)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_slave_event_eq_info *event_eq;
struct mlx4_cmd_mailbox *mailbox;
u32 in_modifier = 0;
int err;
int res_id;
struct res_eq *req;
if (!priv->mfunc.master.slave_state)
return -EINVAL;
event_eq = &priv->mfunc.master.slave_state[slave].event_eq[eqe->type];
if (event_eq->eqn < 0)
return 0;
mutex_lock(&priv->mfunc.master.gen_eqe_mutex[slave]);
res_id = (slave << 8) | event_eq->eqn;
err = get_res(dev, slave, res_id, RES_EQ, &req);
if (err)
goto unlock;
if (req->com.from_state != RES_EQ_HW) {
err = -EINVAL;
goto put;
}
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox)) {
err = PTR_ERR(mailbox);
goto put;
}
if (eqe->type == MLX4_EVENT_TYPE_CMD) {
++event_eq->token;
eqe->event.cmd.token = cpu_to_be16(event_eq->token);
}
memcpy(mailbox->buf, (u8 *) eqe, 28);
in_modifier = (slave & 0xff) | ((event_eq->eqn & 0xff) << 16);
err = mlx4_cmd(dev, mailbox->dma, in_modifier, 0,
MLX4_CMD_GEN_EQE, MLX4_CMD_TIME_CLASS_B,
MLX4_CMD_NATIVE);
put_res(dev, slave, res_id, RES_EQ);
mutex_unlock(&priv->mfunc.master.gen_eqe_mutex[slave]);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
put:
put_res(dev, slave, res_id, RES_EQ);
unlock:
mutex_unlock(&priv->mfunc.master.gen_eqe_mutex[slave]);
return err;
}
int mlx4_QUERY_EQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int eqn = vhcr->in_modifier;
int res_id = eqn | (slave << 8);
struct res_eq *eq;
int err;
err = get_res(dev, slave, res_id, RES_EQ, &eq);
if (err)
return err;
if (eq->com.from_state != RES_EQ_HW) {
err = -EINVAL;
goto ex_put;
}
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
ex_put:
put_res(dev, slave, res_id, RES_EQ);
return err;
}
int mlx4_SW2HW_CQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int cqn = vhcr->in_modifier;
struct mlx4_cq_context *cqc = inbox->buf;
int mtt_base = cq_get_mtt_addr(cqc) / dev->caps.mtt_entry_sz;
struct res_cq *cq;
struct res_mtt *mtt;
err = cq_res_start_move_to(dev, slave, cqn, RES_CQ_HW, &cq);
if (err)
return err;
err = get_res(dev, slave, mtt_base, RES_MTT, &mtt);
if (err)
goto out_move;
err = check_mtt_range(dev, slave, mtt_base, cq_get_mtt_size(cqc), mtt);
if (err)
goto out_put;
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
if (err)
goto out_put;
atomic_inc(&mtt->ref_count);
cq->mtt = mtt;
put_res(dev, slave, mtt->com.res_id, RES_MTT);
res_end_move(dev, slave, RES_CQ, cqn);
return 0;
out_put:
put_res(dev, slave, mtt->com.res_id, RES_MTT);
out_move:
res_abort_move(dev, slave, RES_CQ, cqn);
return err;
}
int mlx4_HW2SW_CQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int cqn = vhcr->in_modifier;
struct res_cq *cq;
err = cq_res_start_move_to(dev, slave, cqn, RES_CQ_ALLOCATED, &cq);
if (err)
return err;
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
if (err)
goto out_move;
atomic_dec(&cq->mtt->ref_count);
res_end_move(dev, slave, RES_CQ, cqn);
return 0;
out_move:
res_abort_move(dev, slave, RES_CQ, cqn);
return err;
}
int mlx4_QUERY_CQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int cqn = vhcr->in_modifier;
struct res_cq *cq;
int err;
err = get_res(dev, slave, cqn, RES_CQ, &cq);
if (err)
return err;
if (cq->com.from_state != RES_CQ_HW)
goto ex_put;
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
ex_put:
put_res(dev, slave, cqn, RES_CQ);
return err;
}
static int handle_resize(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd,
struct res_cq *cq)
{
int err;
struct res_mtt *orig_mtt;
struct res_mtt *mtt;
struct mlx4_cq_context *cqc = inbox->buf;
int mtt_base = cq_get_mtt_addr(cqc) / dev->caps.mtt_entry_sz;
err = get_res(dev, slave, cq->mtt->com.res_id, RES_MTT, &orig_mtt);
if (err)
return err;
if (orig_mtt != cq->mtt) {
err = -EINVAL;
goto ex_put;
}
err = get_res(dev, slave, mtt_base, RES_MTT, &mtt);
if (err)
goto ex_put;
err = check_mtt_range(dev, slave, mtt_base, cq_get_mtt_size(cqc), mtt);
if (err)
goto ex_put1;
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
if (err)
goto ex_put1;
atomic_dec(&orig_mtt->ref_count);
put_res(dev, slave, orig_mtt->com.res_id, RES_MTT);
atomic_inc(&mtt->ref_count);
cq->mtt = mtt;
put_res(dev, slave, mtt->com.res_id, RES_MTT);
return 0;
ex_put1:
put_res(dev, slave, mtt->com.res_id, RES_MTT);
ex_put:
put_res(dev, slave, orig_mtt->com.res_id, RES_MTT);
return err;
}
int mlx4_MODIFY_CQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int cqn = vhcr->in_modifier;
struct res_cq *cq;
int err;
err = get_res(dev, slave, cqn, RES_CQ, &cq);
if (err)
return err;
if (cq->com.from_state != RES_CQ_HW)
goto ex_put;
if (vhcr->op_modifier == 0) {
err = handle_resize(dev, slave, vhcr, inbox, outbox, cmd, cq);
goto ex_put;
}
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
ex_put:
put_res(dev, slave, cqn, RES_CQ);
return err;
}
static int srq_get_mtt_size(struct mlx4_srq_context *srqc)
{
int log_srq_size = (be32_to_cpu(srqc->state_logsize_srqn) >> 24) & 0xf;
int log_rq_stride = srqc->logstride & 7;
int page_shift = (srqc->log_page_size & 0x3f) + 12;
if (log_srq_size + log_rq_stride + 4 < page_shift)
return 1;
return 1 << (log_srq_size + log_rq_stride + 4 - page_shift);
}
int mlx4_SW2HW_SRQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int srqn = vhcr->in_modifier;
struct res_mtt *mtt;
struct res_srq *srq;
struct mlx4_srq_context *srqc = inbox->buf;
int mtt_base = srq_get_mtt_addr(srqc) / dev->caps.mtt_entry_sz;
if (srqn != (be32_to_cpu(srqc->state_logsize_srqn) & 0xffffff))
return -EINVAL;
err = srq_res_start_move_to(dev, slave, srqn, RES_SRQ_HW, &srq);
if (err)
return err;
err = get_res(dev, slave, mtt_base, RES_MTT, &mtt);
if (err)
goto ex_abort;
err = check_mtt_range(dev, slave, mtt_base, srq_get_mtt_size(srqc),
mtt);
if (err)
goto ex_put_mtt;
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
if (err)
goto ex_put_mtt;
atomic_inc(&mtt->ref_count);
srq->mtt = mtt;
put_res(dev, slave, mtt->com.res_id, RES_MTT);
res_end_move(dev, slave, RES_SRQ, srqn);
return 0;
ex_put_mtt:
put_res(dev, slave, mtt->com.res_id, RES_MTT);
ex_abort:
res_abort_move(dev, slave, RES_SRQ, srqn);
return err;
}
int mlx4_HW2SW_SRQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int srqn = vhcr->in_modifier;
struct res_srq *srq;
err = srq_res_start_move_to(dev, slave, srqn, RES_SRQ_ALLOCATED, &srq);
if (err)
return err;
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
if (err)
goto ex_abort;
atomic_dec(&srq->mtt->ref_count);
if (srq->cq)
atomic_dec(&srq->cq->ref_count);
res_end_move(dev, slave, RES_SRQ, srqn);
return 0;
ex_abort:
res_abort_move(dev, slave, RES_SRQ, srqn);
return err;
}
int mlx4_QUERY_SRQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int srqn = vhcr->in_modifier;
struct res_srq *srq;
err = get_res(dev, slave, srqn, RES_SRQ, &srq);
if (err)
return err;
if (srq->com.from_state != RES_SRQ_HW) {
err = -EBUSY;
goto out;
}
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
out:
put_res(dev, slave, srqn, RES_SRQ);
return err;
}
int mlx4_ARM_SRQ_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int srqn = vhcr->in_modifier;
struct res_srq *srq;
err = get_res(dev, slave, srqn, RES_SRQ, &srq);
if (err)
return err;
if (srq->com.from_state != RES_SRQ_HW) {
err = -EBUSY;
goto out;
}
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
out:
put_res(dev, slave, srqn, RES_SRQ);
return err;
}
int mlx4_GEN_QP_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int qpn = vhcr->in_modifier & 0x7fffff;
struct res_qp *qp;
err = get_res(dev, slave, qpn, RES_QP, &qp);
if (err)
return err;
if (qp->com.from_state != RES_QP_HW) {
err = -EBUSY;
goto out;
}
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
out:
put_res(dev, slave, qpn, RES_QP);
return err;
}
int mlx4_INIT2INIT_QP_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
struct mlx4_qp_context *context = inbox->buf + 8;
adjust_proxy_tun_qkey(dev, vhcr, context);
update_pkey_index(dev, slave, inbox);
return mlx4_GEN_QP_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
}
int mlx4_INIT2RTR_QP_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
struct mlx4_qp_context *qpc = inbox->buf + 8;
int qpn = vhcr->in_modifier & 0x7fffff;
struct res_qp *qp;
u8 orig_sched_queue;
__be32 orig_param3 = qpc->param3;
u8 orig_vlan_control = qpc->pri_path.vlan_control;
u8 orig_fvl_rx = qpc->pri_path.fvl_rx;
u8 orig_pri_path_fl = qpc->pri_path.fl;
u8 orig_vlan_index = qpc->pri_path.vlan_index;
u8 orig_feup = qpc->pri_path.feup;
err = verify_qp_parameters(dev, inbox, QP_TRANS_INIT2RTR, slave);
if (err)
return err;
update_pkey_index(dev, slave, inbox);
update_gid(dev, inbox, (u8)slave);
adjust_proxy_tun_qkey(dev, vhcr, qpc);
orig_sched_queue = qpc->pri_path.sched_queue;
err = update_vport_qp_param(dev, inbox, slave, qpn);
if (err)
return err;
err = get_res(dev, slave, qpn, RES_QP, &qp);
if (err)
return err;
if (qp->com.from_state != RES_QP_HW) {
err = -EBUSY;
goto out;
}
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
out:
if (!err) {
qp->sched_queue = orig_sched_queue;
qp->param3 = orig_param3;
qp->vlan_control = orig_vlan_control;
qp->fvl_rx = orig_fvl_rx;
qp->pri_path_fl = orig_pri_path_fl;
qp->vlan_index = orig_vlan_index;
qp->feup = orig_feup;
}
put_res(dev, slave, qpn, RES_QP);
return err;
}
int mlx4_RTR2RTS_QP_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
struct mlx4_qp_context *context = inbox->buf + 8;
err = verify_qp_parameters(dev, inbox, QP_TRANS_RTR2RTS, slave);
if (err)
return err;
update_pkey_index(dev, slave, inbox);
update_gid(dev, inbox, (u8)slave);
adjust_proxy_tun_qkey(dev, vhcr, context);
return mlx4_GEN_QP_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
}
int mlx4_RTS2RTS_QP_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
struct mlx4_qp_context *context = inbox->buf + 8;
err = verify_qp_parameters(dev, inbox, QP_TRANS_RTS2RTS, slave);
if (err)
return err;
update_pkey_index(dev, slave, inbox);
update_gid(dev, inbox, (u8)slave);
adjust_proxy_tun_qkey(dev, vhcr, context);
return mlx4_GEN_QP_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
}
int mlx4_SQERR2RTS_QP_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
struct mlx4_qp_context *context = inbox->buf + 8;
adjust_proxy_tun_qkey(dev, vhcr, context);
return mlx4_GEN_QP_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
}
int mlx4_SQD2SQD_QP_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
struct mlx4_qp_context *context = inbox->buf + 8;
err = verify_qp_parameters(dev, inbox, QP_TRANS_SQD2SQD, slave);
if (err)
return err;
adjust_proxy_tun_qkey(dev, vhcr, context);
update_gid(dev, inbox, (u8)slave);
update_pkey_index(dev, slave, inbox);
return mlx4_GEN_QP_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
}
int mlx4_SQD2RTS_QP_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
struct mlx4_qp_context *context = inbox->buf + 8;
err = verify_qp_parameters(dev, inbox, QP_TRANS_SQD2RTS, slave);
if (err)
return err;
adjust_proxy_tun_qkey(dev, vhcr, context);
update_gid(dev, inbox, (u8)slave);
update_pkey_index(dev, slave, inbox);
return mlx4_GEN_QP_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
}
int mlx4_2RST_QP_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int qpn = vhcr->in_modifier & 0x7fffff;
struct res_qp *qp;
err = qp_res_start_move_to(dev, slave, qpn, RES_QP_MAPPED, &qp, 0);
if (err)
return err;
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
if (err)
goto ex_abort;
atomic_dec(&qp->mtt->ref_count);
atomic_dec(&qp->rcq->ref_count);
atomic_dec(&qp->scq->ref_count);
if (qp->srq)
atomic_dec(&qp->srq->ref_count);
res_end_move(dev, slave, RES_QP, qpn);
return 0;
ex_abort:
res_abort_move(dev, slave, RES_QP, qpn);
return err;
}
static struct res_gid *find_gid(struct mlx4_dev *dev, int slave,
struct res_qp *rqp, u8 *gid)
{
struct res_gid *res;
list_for_each_entry(res, &rqp->mcg_list, list) {
if (!memcmp(res->gid, gid, 16))
return res;
}
return NULL;
}
static int add_mcg_res(struct mlx4_dev *dev, int slave, struct res_qp *rqp,
u8 *gid, enum mlx4_protocol prot,
enum mlx4_steer_type steer, u64 reg_id)
{
struct res_gid *res;
int err;
res = kzalloc(sizeof *res, GFP_KERNEL);
if (!res)
return -ENOMEM;
spin_lock_irq(&rqp->mcg_spl);
if (find_gid(dev, slave, rqp, gid)) {
kfree(res);
err = -EEXIST;
} else {
memcpy(res->gid, gid, 16);
res->prot = prot;
res->steer = steer;
res->reg_id = reg_id;
list_add_tail(&res->list, &rqp->mcg_list);
err = 0;
}
spin_unlock_irq(&rqp->mcg_spl);
return err;
}
static int rem_mcg_res(struct mlx4_dev *dev, int slave, struct res_qp *rqp,
u8 *gid, enum mlx4_protocol prot,
enum mlx4_steer_type steer, u64 *reg_id)
{
struct res_gid *res;
int err;
spin_lock_irq(&rqp->mcg_spl);
res = find_gid(dev, slave, rqp, gid);
if (!res || res->prot != prot || res->steer != steer)
err = -EINVAL;
else {
*reg_id = res->reg_id;
list_del(&res->list);
kfree(res);
err = 0;
}
spin_unlock_irq(&rqp->mcg_spl);
return err;
}
static int qp_attach(struct mlx4_dev *dev, struct mlx4_qp *qp, u8 gid[16],
int block_loopback, enum mlx4_protocol prot,
enum mlx4_steer_type type, u64 *reg_id)
{
switch (dev->caps.steering_mode) {
case MLX4_STEERING_MODE_DEVICE_MANAGED:
return mlx4_trans_to_dmfs_attach(dev, qp, gid, gid[5],
block_loopback, prot,
reg_id);
case MLX4_STEERING_MODE_B0:
return mlx4_qp_attach_common(dev, qp, gid,
block_loopback, prot, type);
default:
return -EINVAL;
}
}
static int qp_detach(struct mlx4_dev *dev, struct mlx4_qp *qp, u8 gid[16],
enum mlx4_protocol prot, enum mlx4_steer_type type,
u64 reg_id)
{
switch (dev->caps.steering_mode) {
case MLX4_STEERING_MODE_DEVICE_MANAGED:
return mlx4_flow_detach(dev, reg_id);
case MLX4_STEERING_MODE_B0:
return mlx4_qp_detach_common(dev, qp, gid, prot, type);
default:
return -EINVAL;
}
}
int mlx4_QP_ATTACH_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
struct mlx4_qp qp;
u8 *gid = inbox->buf;
enum mlx4_protocol prot = (vhcr->in_modifier >> 28) & 0x7;
int err;
int qpn;
struct res_qp *rqp;
u64 reg_id = 0;
int attach = vhcr->op_modifier;
int block_loopback = vhcr->in_modifier >> 31;
u8 steer_type_mask = 2;
enum mlx4_steer_type type = (gid[7] & steer_type_mask) >> 1;
qpn = vhcr->in_modifier & 0xffffff;
err = get_res(dev, slave, qpn, RES_QP, &rqp);
if (err)
return err;
qp.qpn = qpn;
if (attach) {
err = qp_attach(dev, &qp, gid, block_loopback, prot,
type, &reg_id);
if (err) {
pr_err("Fail to attach rule to qp 0x%x\n", qpn);
goto ex_put;
}
err = add_mcg_res(dev, slave, rqp, gid, prot, type, reg_id);
if (err)
goto ex_detach;
} else {
err = rem_mcg_res(dev, slave, rqp, gid, prot, type, &reg_id);
if (err)
goto ex_put;
err = qp_detach(dev, &qp, gid, prot, type, reg_id);
if (err)
pr_err("Fail to detach rule from qp 0x%x reg_id = 0x%llx\n",
qpn, reg_id);
}
put_res(dev, slave, qpn, RES_QP);
return err;
ex_detach:
qp_detach(dev, &qp, gid, prot, type, reg_id);
ex_put:
put_res(dev, slave, qpn, RES_QP);
return err;
}
static int validate_eth_header_mac(int slave, struct _rule_hw *eth_header,
struct list_head *rlist)
{
struct mac_res *res, *tmp;
__be64 be_mac;
if (!is_multicast_ether_addr(eth_header->eth.dst_mac) &&
!is_broadcast_ether_addr(eth_header->eth.dst_mac)) {
list_for_each_entry_safe(res, tmp, rlist, list) {
be_mac = cpu_to_be64(res->mac << 16);
if (ether_addr_equal((u8 *)&be_mac, eth_header->eth.dst_mac))
return 0;
}
pr_err("MAC %pM doesn't belong to VF %d, Steering rule rejected\n",
eth_header->eth.dst_mac, slave);
return -EINVAL;
}
return 0;
}
static int add_eth_header(struct mlx4_dev *dev, int slave,
struct mlx4_cmd_mailbox *inbox,
struct list_head *rlist, int header_id)
{
struct mac_res *res, *tmp;
u8 port;
struct mlx4_net_trans_rule_hw_ctrl *ctrl;
struct mlx4_net_trans_rule_hw_eth *eth_header;
struct mlx4_net_trans_rule_hw_ipv4 *ip_header;
struct mlx4_net_trans_rule_hw_tcp_udp *l4_header;
__be64 be_mac = 0;
__be64 mac_msk = cpu_to_be64(MLX4_MAC_MASK << 16);
ctrl = (struct mlx4_net_trans_rule_hw_ctrl *)inbox->buf;
port = ctrl->port;
eth_header = (struct mlx4_net_trans_rule_hw_eth *)(ctrl + 1);
switch (header_id) {
case MLX4_NET_TRANS_RULE_ID_IPV4:
ip_header =
(struct mlx4_net_trans_rule_hw_ipv4 *)(eth_header + 1);
memmove(ip_header, eth_header,
sizeof(*ip_header) + sizeof(*l4_header));
break;
case MLX4_NET_TRANS_RULE_ID_TCP:
case MLX4_NET_TRANS_RULE_ID_UDP:
l4_header = (struct mlx4_net_trans_rule_hw_tcp_udp *)
(eth_header + 1);
memmove(l4_header, eth_header, sizeof(*l4_header));
break;
default:
return -EINVAL;
}
list_for_each_entry_safe(res, tmp, rlist, list) {
if (port == res->port) {
be_mac = cpu_to_be64(res->mac << 16);
break;
}
}
if (!be_mac) {
pr_err("Failed adding eth header to FS rule, Can't find matching MAC for port %d .\n",
port);
return -EINVAL;
}
memset(eth_header, 0, sizeof(*eth_header));
eth_header->size = sizeof(*eth_header) >> 2;
eth_header->id = cpu_to_be16(__sw_id_hw[MLX4_NET_TRANS_RULE_ID_ETH]);
memcpy(eth_header->dst_mac, &be_mac, ETH_ALEN);
memcpy(eth_header->dst_mac_msk, &mac_msk, ETH_ALEN);
return 0;
}
int mlx4_QP_FLOW_STEERING_ATTACH_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *rlist = &tracker->slave_list[slave].res_list[RES_MAC];
int err;
int qpn;
struct res_qp *rqp;
struct mlx4_net_trans_rule_hw_ctrl *ctrl;
struct _rule_hw *rule_header;
int header_id;
if (dev->caps.steering_mode !=
MLX4_STEERING_MODE_DEVICE_MANAGED)
return -EOPNOTSUPP;
ctrl = (struct mlx4_net_trans_rule_hw_ctrl *)inbox->buf;
qpn = be32_to_cpu(ctrl->qpn) & 0xffffff;
err = get_res(dev, slave, qpn, RES_QP, &rqp);
if (err) {
pr_err("Steering rule with qpn 0x%x rejected.\n", qpn);
return err;
}
rule_header = (struct _rule_hw *)(ctrl + 1);
header_id = map_hw_to_sw_id(be16_to_cpu(rule_header->id));
switch (header_id) {
case MLX4_NET_TRANS_RULE_ID_ETH:
if (validate_eth_header_mac(slave, rule_header, rlist)) {
err = -EINVAL;
goto err_put;
}
break;
case MLX4_NET_TRANS_RULE_ID_IB:
break;
case MLX4_NET_TRANS_RULE_ID_IPV4:
case MLX4_NET_TRANS_RULE_ID_TCP:
case MLX4_NET_TRANS_RULE_ID_UDP:
pr_warn("Can't attach FS rule without L2 headers, adding L2 header.\n");
if (add_eth_header(dev, slave, inbox, rlist, header_id)) {
err = -EINVAL;
goto err_put;
}
vhcr->in_modifier +=
sizeof(struct mlx4_net_trans_rule_hw_eth) >> 2;
break;
default:
pr_err("Corrupted mailbox.\n");
err = -EINVAL;
goto err_put;
}
err = mlx4_cmd_imm(dev, inbox->dma, &vhcr->out_param,
vhcr->in_modifier, 0,
MLX4_QP_FLOW_STEERING_ATTACH, MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
if (err)
goto err_put;
err = add_res_range(dev, slave, vhcr->out_param, 1, RES_FS_RULE, qpn);
if (err) {
mlx4_err(dev, "Fail to add flow steering resources.\n ");
mlx4_cmd(dev, vhcr->out_param, 0, 0,
MLX4_QP_FLOW_STEERING_DETACH, MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
goto err_put;
}
atomic_inc(&rqp->ref_count);
err_put:
put_res(dev, slave, qpn, RES_QP);
return err;
}
int mlx4_QP_FLOW_STEERING_DETACH_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
struct res_qp *rqp;
struct res_fs_rule *rrule;
if (dev->caps.steering_mode !=
MLX4_STEERING_MODE_DEVICE_MANAGED)
return -EOPNOTSUPP;
err = get_res(dev, slave, vhcr->in_param, RES_FS_RULE, &rrule);
if (err)
return err;
put_res(dev, slave, vhcr->in_param, RES_FS_RULE);
err = get_res(dev, slave, rrule->qpn, RES_QP, &rqp);
if (err)
return err;
err = rem_res_range(dev, slave, vhcr->in_param, 1, RES_FS_RULE, 0);
if (err) {
mlx4_err(dev, "Fail to remove flow steering resources.\n ");
goto out;
}
err = mlx4_cmd(dev, vhcr->in_param, 0, 0,
MLX4_QP_FLOW_STEERING_DETACH, MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
if (!err)
atomic_dec(&rqp->ref_count);
out:
put_res(dev, slave, rrule->qpn, RES_QP);
return err;
}
int mlx4_QUERY_IF_STAT_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
int err;
int index = vhcr->in_modifier & 0xffff;
err = get_res(dev, slave, index, RES_COUNTER, NULL);
if (err)
return err;
err = mlx4_DMA_wrapper(dev, slave, vhcr, inbox, outbox, cmd);
put_res(dev, slave, index, RES_COUNTER);
return err;
}
int mlx4_FLOW_STEERING_IB_UC_QP_RANGE_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
return -EPERM;
}
static void detach_qp(struct mlx4_dev *dev, int slave, struct res_qp *rqp)
{
struct res_gid *rgid;
struct res_gid *tmp;
struct mlx4_qp qp;
list_for_each_entry_safe(rgid, tmp, &rqp->mcg_list, list) {
switch (dev->caps.steering_mode) {
case MLX4_STEERING_MODE_DEVICE_MANAGED:
mlx4_flow_detach(dev, rgid->reg_id);
break;
case MLX4_STEERING_MODE_B0:
qp.qpn = rqp->local_qpn;
(void) mlx4_qp_detach_common(dev, &qp, rgid->gid,
rgid->prot, rgid->steer);
break;
}
list_del(&rgid->list);
kfree(rgid);
}
}
static int _move_all_busy(struct mlx4_dev *dev, int slave,
enum mlx4_resource type, int print)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker =
&priv->mfunc.master.res_tracker;
struct list_head *rlist = &tracker->slave_list[slave].res_list[type];
struct res_common *r;
struct res_common *tmp;
int busy;
busy = 0;
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry_safe(r, tmp, rlist, list) {
if (r->owner == slave) {
if (!r->removing) {
if (r->state == RES_ANY_BUSY) {
if (print)
mlx4_dbg(dev,
"%s id 0x%llx is busy\n",
ResourceType(type),
r->res_id);
++busy;
} else {
r->from_state = r->state;
r->state = RES_ANY_BUSY;
r->removing = 1;
}
}
}
}
spin_unlock_irq(mlx4_tlock(dev));
return busy;
}
static int move_all_busy(struct mlx4_dev *dev, int slave,
enum mlx4_resource type)
{
unsigned long begin;
int busy;
begin = jiffies;
do {
busy = _move_all_busy(dev, slave, type, 0);
if (time_after(jiffies, begin + 5 * HZ))
break;
if (busy)
cond_resched();
} while (busy);
if (busy)
busy = _move_all_busy(dev, slave, type, 1);
return busy;
}
static void rem_slave_qps(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *qp_list =
&tracker->slave_list[slave].res_list[RES_QP];
struct res_qp *qp;
struct res_qp *tmp;
int state;
u64 in_param;
int qpn;
int err;
err = move_all_busy(dev, slave, RES_QP);
if (err)
mlx4_warn(dev, "rem_slave_qps: Could not move all qps to busy"
"for slave %d\n", slave);
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry_safe(qp, tmp, qp_list, com.list) {
spin_unlock_irq(mlx4_tlock(dev));
if (qp->com.owner == slave) {
qpn = qp->com.res_id;
detach_qp(dev, slave, qp);
state = qp->com.from_state;
while (state != 0) {
switch (state) {
case RES_QP_RESERVED:
spin_lock_irq(mlx4_tlock(dev));
rb_erase(&qp->com.node,
&tracker->res_tree[RES_QP]);
list_del(&qp->com.list);
spin_unlock_irq(mlx4_tlock(dev));
if (!valid_reserved(dev, slave, qpn)) {
__mlx4_qp_release_range(dev, qpn, 1);
mlx4_release_resource(dev, slave,
RES_QP, 1, 0);
}
kfree(qp);
state = 0;
break;
case RES_QP_MAPPED:
if (!valid_reserved(dev, slave, qpn))
__mlx4_qp_free_icm(dev, qpn);
state = RES_QP_RESERVED;
break;
case RES_QP_HW:
in_param = slave;
err = mlx4_cmd(dev, in_param,
qp->local_qpn, 2,
MLX4_CMD_2RST_QP,
MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
if (err)
mlx4_dbg(dev, "rem_slave_qps: failed"
" to move slave %d qpn %d to"
" reset\n", slave,
qp->local_qpn);
atomic_dec(&qp->rcq->ref_count);
atomic_dec(&qp->scq->ref_count);
atomic_dec(&qp->mtt->ref_count);
if (qp->srq)
atomic_dec(&qp->srq->ref_count);
state = RES_QP_MAPPED;
break;
default:
state = 0;
}
}
}
spin_lock_irq(mlx4_tlock(dev));
}
spin_unlock_irq(mlx4_tlock(dev));
}
static void rem_slave_srqs(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *srq_list =
&tracker->slave_list[slave].res_list[RES_SRQ];
struct res_srq *srq;
struct res_srq *tmp;
int state;
u64 in_param;
LIST_HEAD(tlist);
int srqn;
int err;
err = move_all_busy(dev, slave, RES_SRQ);
if (err)
mlx4_warn(dev, "rem_slave_srqs: Could not move all srqs to "
"busy for slave %d\n", slave);
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry_safe(srq, tmp, srq_list, com.list) {
spin_unlock_irq(mlx4_tlock(dev));
if (srq->com.owner == slave) {
srqn = srq->com.res_id;
state = srq->com.from_state;
while (state != 0) {
switch (state) {
case RES_SRQ_ALLOCATED:
__mlx4_srq_free_icm(dev, srqn);
spin_lock_irq(mlx4_tlock(dev));
rb_erase(&srq->com.node,
&tracker->res_tree[RES_SRQ]);
list_del(&srq->com.list);
spin_unlock_irq(mlx4_tlock(dev));
mlx4_release_resource(dev, slave,
RES_SRQ, 1, 0);
kfree(srq);
state = 0;
break;
case RES_SRQ_HW:
in_param = slave;
err = mlx4_cmd(dev, in_param, srqn, 1,
MLX4_CMD_HW2SW_SRQ,
MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
if (err)
mlx4_dbg(dev, "rem_slave_srqs: failed"
" to move slave %d srq %d to"
" SW ownership\n",
slave, srqn);
atomic_dec(&srq->mtt->ref_count);
if (srq->cq)
atomic_dec(&srq->cq->ref_count);
state = RES_SRQ_ALLOCATED;
break;
default:
state = 0;
}
}
}
spin_lock_irq(mlx4_tlock(dev));
}
spin_unlock_irq(mlx4_tlock(dev));
}
static void rem_slave_cqs(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *cq_list =
&tracker->slave_list[slave].res_list[RES_CQ];
struct res_cq *cq;
struct res_cq *tmp;
int state;
u64 in_param;
LIST_HEAD(tlist);
int cqn;
int err;
err = move_all_busy(dev, slave, RES_CQ);
if (err)
mlx4_warn(dev, "rem_slave_cqs: Could not move all cqs to "
"busy for slave %d\n", slave);
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry_safe(cq, tmp, cq_list, com.list) {
spin_unlock_irq(mlx4_tlock(dev));
if (cq->com.owner == slave && !atomic_read(&cq->ref_count)) {
cqn = cq->com.res_id;
state = cq->com.from_state;
while (state != 0) {
switch (state) {
case RES_CQ_ALLOCATED:
__mlx4_cq_free_icm(dev, cqn);
spin_lock_irq(mlx4_tlock(dev));
rb_erase(&cq->com.node,
&tracker->res_tree[RES_CQ]);
list_del(&cq->com.list);
spin_unlock_irq(mlx4_tlock(dev));
mlx4_release_resource(dev, slave,
RES_CQ, 1, 0);
kfree(cq);
state = 0;
break;
case RES_CQ_HW:
in_param = slave;
err = mlx4_cmd(dev, in_param, cqn, 1,
MLX4_CMD_HW2SW_CQ,
MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
if (err)
mlx4_dbg(dev, "rem_slave_cqs: failed"
" to move slave %d cq %d to"
" SW ownership\n",
slave, cqn);
atomic_dec(&cq->mtt->ref_count);
state = RES_CQ_ALLOCATED;
break;
default:
state = 0;
}
}
}
spin_lock_irq(mlx4_tlock(dev));
}
spin_unlock_irq(mlx4_tlock(dev));
}
static void rem_slave_mrs(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *mpt_list =
&tracker->slave_list[slave].res_list[RES_MPT];
struct res_mpt *mpt;
struct res_mpt *tmp;
int state;
u64 in_param;
LIST_HEAD(tlist);
int mptn;
int err;
err = move_all_busy(dev, slave, RES_MPT);
if (err)
mlx4_warn(dev, "rem_slave_mrs: Could not move all mpts to "
"busy for slave %d\n", slave);
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry_safe(mpt, tmp, mpt_list, com.list) {
spin_unlock_irq(mlx4_tlock(dev));
if (mpt->com.owner == slave) {
mptn = mpt->com.res_id;
state = mpt->com.from_state;
while (state != 0) {
switch (state) {
case RES_MPT_RESERVED:
__mlx4_mpt_release(dev, mpt->key);
spin_lock_irq(mlx4_tlock(dev));
rb_erase(&mpt->com.node,
&tracker->res_tree[RES_MPT]);
list_del(&mpt->com.list);
spin_unlock_irq(mlx4_tlock(dev));
mlx4_release_resource(dev, slave,
RES_MPT, 1, 0);
kfree(mpt);
state = 0;
break;
case RES_MPT_MAPPED:
__mlx4_mpt_free_icm(dev, mpt->key);
state = RES_MPT_RESERVED;
break;
case RES_MPT_HW:
in_param = slave;
err = mlx4_cmd(dev, in_param, mptn, 0,
MLX4_CMD_HW2SW_MPT,
MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
if (err)
mlx4_dbg(dev, "rem_slave_mrs: failed"
" to move slave %d mpt %d to"
" SW ownership\n",
slave, mptn);
if (mpt->mtt)
atomic_dec(&mpt->mtt->ref_count);
state = RES_MPT_MAPPED;
break;
default:
state = 0;
}
}
}
spin_lock_irq(mlx4_tlock(dev));
}
spin_unlock_irq(mlx4_tlock(dev));
}
static void rem_slave_mtts(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker =
&priv->mfunc.master.res_tracker;
struct list_head *mtt_list =
&tracker->slave_list[slave].res_list[RES_MTT];
struct res_mtt *mtt;
struct res_mtt *tmp;
int state;
LIST_HEAD(tlist);
int base;
int err;
err = move_all_busy(dev, slave, RES_MTT);
if (err)
mlx4_warn(dev, "rem_slave_mtts: Could not move all mtts to "
"busy for slave %d\n", slave);
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry_safe(mtt, tmp, mtt_list, com.list) {
spin_unlock_irq(mlx4_tlock(dev));
if (mtt->com.owner == slave) {
base = mtt->com.res_id;
state = mtt->com.from_state;
while (state != 0) {
switch (state) {
case RES_MTT_ALLOCATED:
__mlx4_free_mtt_range(dev, base,
mtt->order);
spin_lock_irq(mlx4_tlock(dev));
rb_erase(&mtt->com.node,
&tracker->res_tree[RES_MTT]);
list_del(&mtt->com.list);
spin_unlock_irq(mlx4_tlock(dev));
mlx4_release_resource(dev, slave, RES_MTT,
1 << mtt->order, 0);
kfree(mtt);
state = 0;
break;
default:
state = 0;
}
}
}
spin_lock_irq(mlx4_tlock(dev));
}
spin_unlock_irq(mlx4_tlock(dev));
}
static void rem_slave_fs_rule(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker =
&priv->mfunc.master.res_tracker;
struct list_head *fs_rule_list =
&tracker->slave_list[slave].res_list[RES_FS_RULE];
struct res_fs_rule *fs_rule;
struct res_fs_rule *tmp;
int state;
u64 base;
int err;
err = move_all_busy(dev, slave, RES_FS_RULE);
if (err)
mlx4_warn(dev, "rem_slave_fs_rule: Could not move all mtts to busy for slave %d\n",
slave);
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry_safe(fs_rule, tmp, fs_rule_list, com.list) {
spin_unlock_irq(mlx4_tlock(dev));
if (fs_rule->com.owner == slave) {
base = fs_rule->com.res_id;
state = fs_rule->com.from_state;
while (state != 0) {
switch (state) {
case RES_FS_RULE_ALLOCATED:
err = mlx4_cmd(dev, base, 0, 0,
MLX4_QP_FLOW_STEERING_DETACH,
MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
spin_lock_irq(mlx4_tlock(dev));
rb_erase(&fs_rule->com.node,
&tracker->res_tree[RES_FS_RULE]);
list_del(&fs_rule->com.list);
spin_unlock_irq(mlx4_tlock(dev));
kfree(fs_rule);
state = 0;
break;
default:
state = 0;
}
}
}
spin_lock_irq(mlx4_tlock(dev));
}
spin_unlock_irq(mlx4_tlock(dev));
}
static void rem_slave_eqs(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *eq_list =
&tracker->slave_list[slave].res_list[RES_EQ];
struct res_eq *eq;
struct res_eq *tmp;
int err;
int state;
LIST_HEAD(tlist);
int eqn;
struct mlx4_cmd_mailbox *mailbox;
err = move_all_busy(dev, slave, RES_EQ);
if (err)
mlx4_warn(dev, "rem_slave_eqs: Could not move all eqs to "
"busy for slave %d\n", slave);
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry_safe(eq, tmp, eq_list, com.list) {
spin_unlock_irq(mlx4_tlock(dev));
if (eq->com.owner == slave) {
eqn = eq->com.res_id;
state = eq->com.from_state;
while (state != 0) {
switch (state) {
case RES_EQ_RESERVED:
spin_lock_irq(mlx4_tlock(dev));
rb_erase(&eq->com.node,
&tracker->res_tree[RES_EQ]);
list_del(&eq->com.list);
spin_unlock_irq(mlx4_tlock(dev));
kfree(eq);
state = 0;
break;
case RES_EQ_HW:
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox)) {
cond_resched();
continue;
}
err = mlx4_cmd_box(dev, slave, 0,
eqn & 0xff, 0,
MLX4_CMD_HW2SW_EQ,
MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
if (err)
mlx4_dbg(dev, "rem_slave_eqs: failed"
" to move slave %d eqs %d to"
" SW ownership\n", slave, eqn);
mlx4_free_cmd_mailbox(dev, mailbox);
atomic_dec(&eq->mtt->ref_count);
state = RES_EQ_RESERVED;
break;
default:
state = 0;
}
}
}
spin_lock_irq(mlx4_tlock(dev));
}
spin_unlock_irq(mlx4_tlock(dev));
}
static void rem_slave_counters(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *counter_list =
&tracker->slave_list[slave].res_list[RES_COUNTER];
struct res_counter *counter;
struct res_counter *tmp;
int err;
int index;
err = move_all_busy(dev, slave, RES_COUNTER);
if (err)
mlx4_warn(dev, "rem_slave_counters: Could not move all counters to "
"busy for slave %d\n", slave);
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry_safe(counter, tmp, counter_list, com.list) {
if (counter->com.owner == slave) {
index = counter->com.res_id;
rb_erase(&counter->com.node,
&tracker->res_tree[RES_COUNTER]);
list_del(&counter->com.list);
kfree(counter);
__mlx4_counter_free(dev, index);
mlx4_release_resource(dev, slave, RES_COUNTER, 1, 0);
}
}
spin_unlock_irq(mlx4_tlock(dev));
}
static void rem_slave_xrcdns(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource_tracker *tracker = &priv->mfunc.master.res_tracker;
struct list_head *xrcdn_list =
&tracker->slave_list[slave].res_list[RES_XRCD];
struct res_xrcdn *xrcd;
struct res_xrcdn *tmp;
int err;
int xrcdn;
err = move_all_busy(dev, slave, RES_XRCD);
if (err)
mlx4_warn(dev, "rem_slave_xrcdns: Could not move all xrcdns to "
"busy for slave %d\n", slave);
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry_safe(xrcd, tmp, xrcdn_list, com.list) {
if (xrcd->com.owner == slave) {
xrcdn = xrcd->com.res_id;
rb_erase(&xrcd->com.node, &tracker->res_tree[RES_XRCD]);
list_del(&xrcd->com.list);
kfree(xrcd);
__mlx4_xrcd_free(dev, xrcdn);
}
}
spin_unlock_irq(mlx4_tlock(dev));
}
void mlx4_delete_all_resources_for_slave(struct mlx4_dev *dev, int slave)
{
struct mlx4_priv *priv = mlx4_priv(dev);
mutex_lock(&priv->mfunc.master.res_tracker.slave_list[slave].mutex);
rem_slave_vlans(dev, slave);
rem_slave_macs(dev, slave);
rem_slave_fs_rule(dev, slave);
rem_slave_qps(dev, slave);
rem_slave_srqs(dev, slave);
rem_slave_cqs(dev, slave);
rem_slave_mrs(dev, slave);
rem_slave_eqs(dev, slave);
rem_slave_mtts(dev, slave);
rem_slave_counters(dev, slave);
rem_slave_xrcdns(dev, slave);
mutex_unlock(&priv->mfunc.master.res_tracker.slave_list[slave].mutex);
}
void mlx4_vf_immed_vlan_work_handler(struct work_struct *_work)
{
struct mlx4_vf_immed_vlan_work *work =
container_of(_work, struct mlx4_vf_immed_vlan_work, work);
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_update_qp_context *upd_context;
struct mlx4_dev *dev = &work->priv->dev;
struct mlx4_resource_tracker *tracker =
&work->priv->mfunc.master.res_tracker;
struct list_head *qp_list =
&tracker->slave_list[work->slave].res_list[RES_QP];
struct res_qp *qp;
struct res_qp *tmp;
u64 qp_path_mask_vlan_ctrl =
((1ULL << MLX4_UPD_QP_PATH_MASK_ETH_TX_BLOCK_UNTAGGED) |
(1ULL << MLX4_UPD_QP_PATH_MASK_ETH_TX_BLOCK_1P) |
(1ULL << MLX4_UPD_QP_PATH_MASK_ETH_TX_BLOCK_TAGGED) |
(1ULL << MLX4_UPD_QP_PATH_MASK_ETH_RX_BLOCK_UNTAGGED) |
(1ULL << MLX4_UPD_QP_PATH_MASK_ETH_RX_BLOCK_1P) |
(1ULL << MLX4_UPD_QP_PATH_MASK_ETH_RX_BLOCK_TAGGED));
u64 qp_path_mask = ((1ULL << MLX4_UPD_QP_PATH_MASK_VLAN_INDEX) |
(1ULL << MLX4_UPD_QP_PATH_MASK_FVL) |
(1ULL << MLX4_UPD_QP_PATH_MASK_CV) |
(1ULL << MLX4_UPD_QP_PATH_MASK_ETH_HIDE_CQE_VLAN) |
(1ULL << MLX4_UPD_QP_PATH_MASK_FEUP) |
(1ULL << MLX4_UPD_QP_PATH_MASK_FVL_RX) |
(1ULL << MLX4_UPD_QP_PATH_MASK_SCHED_QUEUE));
int err;
int port, errors = 0;
u8 vlan_control;
if (mlx4_is_slave(dev)) {
mlx4_warn(dev, "Trying to update-qp in slave %d\n",
work->slave);
goto out;
}
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
goto out;
if (work->flags & MLX4_VF_IMMED_VLAN_FLAG_LINK_DISABLE)
vlan_control = MLX4_VLAN_CTRL_ETH_TX_BLOCK_TAGGED |
MLX4_VLAN_CTRL_ETH_TX_BLOCK_PRIO_TAGGED |
MLX4_VLAN_CTRL_ETH_TX_BLOCK_UNTAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_PRIO_TAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_UNTAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_TAGGED;
else if (!work->vlan_id)
vlan_control = MLX4_VLAN_CTRL_ETH_TX_BLOCK_TAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_TAGGED;
else
vlan_control = MLX4_VLAN_CTRL_ETH_TX_BLOCK_TAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_PRIO_TAGGED |
MLX4_VLAN_CTRL_ETH_RX_BLOCK_UNTAGGED;
upd_context = mailbox->buf;
upd_context->qp_mask = cpu_to_be64(MLX4_UPD_QP_MASK_VSD);
spin_lock_irq(mlx4_tlock(dev));
list_for_each_entry_safe(qp, tmp, qp_list, com.list) {
spin_unlock_irq(mlx4_tlock(dev));
if (qp->com.owner == work->slave) {
if (qp->com.from_state != RES_QP_HW ||
!qp->sched_queue ||
mlx4_is_qp_reserved(dev, qp->local_qpn) ||
qp->qpc_flags & (1 << MLX4_RSS_QPC_FLAG_OFFSET)) {
spin_lock_irq(mlx4_tlock(dev));
continue;
}
port = (qp->sched_queue >> 6 & 1) + 1;
if (port != work->port) {
spin_lock_irq(mlx4_tlock(dev));
continue;
}
if (MLX4_QP_ST_RC == ((qp->qpc_flags >> 16) & 0xff))
upd_context->primary_addr_path_mask = cpu_to_be64(qp_path_mask);
else
upd_context->primary_addr_path_mask =
cpu_to_be64(qp_path_mask | qp_path_mask_vlan_ctrl);
if (work->vlan_id == MLX4_VGT) {
upd_context->qp_context.param3 = qp->param3;
upd_context->qp_context.pri_path.vlan_control = qp->vlan_control;
upd_context->qp_context.pri_path.fvl_rx = qp->fvl_rx;
upd_context->qp_context.pri_path.vlan_index = qp->vlan_index;
upd_context->qp_context.pri_path.fl = qp->pri_path_fl;
upd_context->qp_context.pri_path.feup = qp->feup;
upd_context->qp_context.pri_path.sched_queue =
qp->sched_queue;
} else {
upd_context->qp_context.param3 = qp->param3 & ~cpu_to_be32(MLX4_STRIP_VLAN);
upd_context->qp_context.pri_path.vlan_control = vlan_control;
upd_context->qp_context.pri_path.vlan_index = work->vlan_ix;
upd_context->qp_context.pri_path.fvl_rx =
qp->fvl_rx | MLX4_FVL_RX_FORCE_ETH_VLAN;
upd_context->qp_context.pri_path.fl =
qp->pri_path_fl | MLX4_FL_CV | MLX4_FL_ETH_HIDE_CQE_VLAN;
upd_context->qp_context.pri_path.feup =
qp->feup | MLX4_FEUP_FORCE_ETH_UP | MLX4_FVL_FORCE_ETH_VLAN;
upd_context->qp_context.pri_path.sched_queue =
qp->sched_queue & 0xC7;
upd_context->qp_context.pri_path.sched_queue |=
((work->qos & 0x7) << 3);
}
err = mlx4_cmd(dev, mailbox->dma,
qp->local_qpn & 0xffffff,
0, MLX4_CMD_UPDATE_QP,
MLX4_CMD_TIME_CLASS_C, MLX4_CMD_NATIVE);
if (err) {
mlx4_info(dev, "UPDATE_QP failed for slave %d, "
"port %d, qpn %d (%d)\n",
work->slave, port, qp->local_qpn,
err);
errors++;
}
}
spin_lock_irq(mlx4_tlock(dev));
}
spin_unlock_irq(mlx4_tlock(dev));
mlx4_free_cmd_mailbox(dev, mailbox);
if (errors)
mlx4_err(dev, "%d UPDATE_QP failures for slave %d, port %d\n",
errors, work->slave, work->port);
if (work->flags & MLX4_VF_IMMED_VLAN_FLAG_VLAN && !errors &&
NO_INDX != work->orig_vlan_ix)
__mlx4_unregister_vlan(&work->priv->dev, work->port,
work->orig_vlan_id);
out:
kfree(work);
return;
}
