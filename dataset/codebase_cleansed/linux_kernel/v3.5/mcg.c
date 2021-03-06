int mlx4_get_mgm_entry_size(struct mlx4_dev *dev)
{
return min((1 << mlx4_log_num_mgm_entry_size), MLX4_MAX_MGM_ENTRY_SIZE);
}
int mlx4_get_qp_per_mgm(struct mlx4_dev *dev)
{
return 4 * (mlx4_get_mgm_entry_size(dev) / 16 - 2);
}
static int mlx4_READ_ENTRY(struct mlx4_dev *dev, int index,
struct mlx4_cmd_mailbox *mailbox)
{
return mlx4_cmd_box(dev, 0, mailbox->dma, index, 0, MLX4_CMD_READ_MCG,
MLX4_CMD_TIME_CLASS_A, MLX4_CMD_NATIVE);
}
static int mlx4_WRITE_ENTRY(struct mlx4_dev *dev, int index,
struct mlx4_cmd_mailbox *mailbox)
{
return mlx4_cmd(dev, mailbox->dma, index, 0, MLX4_CMD_WRITE_MCG,
MLX4_CMD_TIME_CLASS_A, MLX4_CMD_NATIVE);
}
static int mlx4_WRITE_PROMISC(struct mlx4_dev *dev, u8 port, u8 steer,
struct mlx4_cmd_mailbox *mailbox)
{
u32 in_mod;
in_mod = (u32) port << 16 | steer << 1;
return mlx4_cmd(dev, mailbox->dma, in_mod, 0x1,
MLX4_CMD_WRITE_MCG, MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
}
static int mlx4_GID_HASH(struct mlx4_dev *dev, struct mlx4_cmd_mailbox *mailbox,
u16 *hash, u8 op_mod)
{
u64 imm;
int err;
err = mlx4_cmd_imm(dev, mailbox->dma, &imm, 0, op_mod,
MLX4_CMD_MGID_HASH, MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
if (!err)
*hash = imm;
return err;
}
static struct mlx4_promisc_qp *get_promisc_qp(struct mlx4_dev *dev, u8 pf_num,
enum mlx4_steer_type steer,
u32 qpn)
{
struct mlx4_steer *s_steer = &mlx4_priv(dev)->steer[pf_num];
struct mlx4_promisc_qp *pqp;
list_for_each_entry(pqp, &s_steer->promisc_qps[steer], list) {
if (pqp->qpn == qpn)
return pqp;
}
return NULL;
}
static int new_steering_entry(struct mlx4_dev *dev, u8 port,
enum mlx4_steer_type steer,
unsigned int index, u32 qpn)
{
struct mlx4_steer *s_steer;
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_mgm *mgm;
u32 members_count;
struct mlx4_steer_index *new_entry;
struct mlx4_promisc_qp *pqp;
struct mlx4_promisc_qp *dqp = NULL;
u32 prot;
int err;
s_steer = &mlx4_priv(dev)->steer[port - 1];
new_entry = kzalloc(sizeof *new_entry, GFP_KERNEL);
if (!new_entry)
return -ENOMEM;
INIT_LIST_HEAD(&new_entry->duplicates);
new_entry->index = index;
list_add_tail(&new_entry->list, &s_steer->steer_entries[steer]);
pqp = get_promisc_qp(dev, 0, steer, qpn);
if (pqp) {
dqp = kmalloc(sizeof *dqp, GFP_KERNEL);
if (!dqp) {
err = -ENOMEM;
goto out_alloc;
}
dqp->qpn = qpn;
list_add_tail(&dqp->list, &new_entry->duplicates);
}
if (list_empty(&s_steer->promisc_qps[steer]))
return 0;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox)) {
err = -ENOMEM;
goto out_alloc;
}
mgm = mailbox->buf;
err = mlx4_READ_ENTRY(dev, index, mailbox);
if (err)
goto out_mailbox;
members_count = be32_to_cpu(mgm->members_count) & 0xffffff;
prot = be32_to_cpu(mgm->members_count) >> 30;
list_for_each_entry(pqp, &s_steer->promisc_qps[steer], list) {
if (pqp->qpn == qpn)
continue;
if (members_count == dev->caps.num_qp_per_mgm) {
err = -ENOMEM;
goto out_mailbox;
}
mgm->qp[members_count++] = cpu_to_be32(pqp->qpn & MGM_QPN_MASK);
}
mgm->members_count = cpu_to_be32(members_count | (prot << 30));
err = mlx4_WRITE_ENTRY(dev, index, mailbox);
out_mailbox:
mlx4_free_cmd_mailbox(dev, mailbox);
if (!err)
return 0;
out_alloc:
if (dqp) {
list_del(&dqp->list);
kfree(dqp);
}
list_del(&new_entry->list);
kfree(new_entry);
return err;
}
static int existing_steering_entry(struct mlx4_dev *dev, u8 port,
enum mlx4_steer_type steer,
unsigned int index, u32 qpn)
{
struct mlx4_steer *s_steer;
struct mlx4_steer_index *tmp_entry, *entry = NULL;
struct mlx4_promisc_qp *pqp;
struct mlx4_promisc_qp *dqp;
s_steer = &mlx4_priv(dev)->steer[port - 1];
pqp = get_promisc_qp(dev, 0, steer, qpn);
if (!pqp)
return 0;
list_for_each_entry(tmp_entry, &s_steer->steer_entries[steer], list) {
if (tmp_entry->index == index) {
entry = tmp_entry;
break;
}
}
if (unlikely(!entry)) {
mlx4_warn(dev, "Steering entry at index %x is not registered\n", index);
return -EINVAL;
}
list_for_each_entry(dqp, &entry->duplicates, list) {
if (qpn == pqp->qpn)
return 0;
}
dqp = kmalloc(sizeof *dqp, GFP_KERNEL);
if (!dqp)
return -ENOMEM;
dqp->qpn = qpn;
list_add_tail(&dqp->list, &entry->duplicates);
return 0;
}
static bool check_duplicate_entry(struct mlx4_dev *dev, u8 port,
enum mlx4_steer_type steer,
unsigned int index, u32 qpn)
{
struct mlx4_steer *s_steer;
struct mlx4_steer_index *tmp_entry, *entry = NULL;
struct mlx4_promisc_qp *dqp, *tmp_dqp;
s_steer = &mlx4_priv(dev)->steer[port - 1];
if (!get_promisc_qp(dev, 0, steer, qpn))
return false;
list_for_each_entry(tmp_entry, &s_steer->steer_entries[steer], list) {
if (tmp_entry->index == index) {
entry = tmp_entry;
break;
}
}
if (unlikely(!entry)) {
mlx4_warn(dev, "Steering entry for index %x is not registered\n", index);
return false;
}
list_for_each_entry_safe(dqp, tmp_dqp, &entry->duplicates, list) {
if (dqp->qpn == qpn) {
list_del(&dqp->list);
kfree(dqp);
}
}
return true;
}
static bool can_remove_steering_entry(struct mlx4_dev *dev, u8 port,
enum mlx4_steer_type steer,
unsigned int index, u32 tqpn)
{
struct mlx4_steer *s_steer;
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_mgm *mgm;
struct mlx4_steer_index *entry = NULL, *tmp_entry;
u32 qpn;
u32 members_count;
bool ret = false;
int i;
s_steer = &mlx4_priv(dev)->steer[port - 1];
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return false;
mgm = mailbox->buf;
if (mlx4_READ_ENTRY(dev, index, mailbox))
goto out;
members_count = be32_to_cpu(mgm->members_count) & 0xffffff;
for (i = 0; i < members_count; i++) {
qpn = be32_to_cpu(mgm->qp[i]) & MGM_QPN_MASK;
if (!get_promisc_qp(dev, 0, steer, qpn) && qpn != tqpn) {
goto out;
}
}
ret = true;
list_for_each_entry_safe(entry, tmp_entry, &s_steer->steer_entries[steer], list) {
if (entry->index == index) {
if (list_empty(&entry->duplicates)) {
list_del(&entry->list);
kfree(entry);
} else {
ret = false;
goto out;
}
}
}
out:
mlx4_free_cmd_mailbox(dev, mailbox);
return ret;
}
static int add_promisc_qp(struct mlx4_dev *dev, u8 port,
enum mlx4_steer_type steer, u32 qpn)
{
struct mlx4_steer *s_steer;
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_mgm *mgm;
struct mlx4_steer_index *entry;
struct mlx4_promisc_qp *pqp;
struct mlx4_promisc_qp *dqp;
u32 members_count;
u32 prot;
int i;
bool found;
int err;
struct mlx4_priv *priv = mlx4_priv(dev);
s_steer = &mlx4_priv(dev)->steer[port - 1];
mutex_lock(&priv->mcg_table.mutex);
if (get_promisc_qp(dev, 0, steer, qpn)) {
err = 0;
goto out_mutex;
}
pqp = kmalloc(sizeof *pqp, GFP_KERNEL);
if (!pqp) {
err = -ENOMEM;
goto out_mutex;
}
pqp->qpn = qpn;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox)) {
err = -ENOMEM;
goto out_alloc;
}
mgm = mailbox->buf;
list_for_each_entry(entry, &s_steer->steer_entries[steer], list) {
err = mlx4_READ_ENTRY(dev, entry->index, mailbox);
if (err)
goto out_mailbox;
members_count = be32_to_cpu(mgm->members_count) & 0xffffff;
prot = be32_to_cpu(mgm->members_count) >> 30;
found = false;
for (i = 0; i < members_count; i++) {
if ((be32_to_cpu(mgm->qp[i]) & MGM_QPN_MASK) == qpn) {
dqp = kmalloc(sizeof *dqp, GFP_KERNEL);
if (!dqp)
goto out_mailbox;
dqp->qpn = qpn;
list_add_tail(&dqp->list, &entry->duplicates);
found = true;
}
}
if (!found) {
if (members_count == dev->caps.num_qp_per_mgm) {
err = -ENOMEM;
goto out_mailbox;
}
mgm->qp[members_count++] = cpu_to_be32(qpn & MGM_QPN_MASK);
mgm->members_count = cpu_to_be32(members_count | (prot << 30));
err = mlx4_WRITE_ENTRY(dev, entry->index, mailbox);
if (err)
goto out_mailbox;
}
}
list_add_tail(&pqp->list, &s_steer->promisc_qps[steer]);
memset(mgm, 0, sizeof *mgm);
members_count = 0;
list_for_each_entry(dqp, &s_steer->promisc_qps[steer], list)
mgm->qp[members_count++] = cpu_to_be32(dqp->qpn & MGM_QPN_MASK);
mgm->members_count = cpu_to_be32(members_count | MLX4_PROT_ETH << 30);
err = mlx4_WRITE_PROMISC(dev, port, steer, mailbox);
if (err)
goto out_list;
mlx4_free_cmd_mailbox(dev, mailbox);
mutex_unlock(&priv->mcg_table.mutex);
return 0;
out_list:
list_del(&pqp->list);
out_mailbox:
mlx4_free_cmd_mailbox(dev, mailbox);
out_alloc:
kfree(pqp);
out_mutex:
mutex_unlock(&priv->mcg_table.mutex);
return err;
}
static int remove_promisc_qp(struct mlx4_dev *dev, u8 port,
enum mlx4_steer_type steer, u32 qpn)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_steer *s_steer;
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_mgm *mgm;
struct mlx4_steer_index *entry;
struct mlx4_promisc_qp *pqp;
struct mlx4_promisc_qp *dqp;
u32 members_count;
bool found;
bool back_to_list = false;
int loc, i;
int err;
s_steer = &mlx4_priv(dev)->steer[port - 1];
mutex_lock(&priv->mcg_table.mutex);
pqp = get_promisc_qp(dev, 0, steer, qpn);
if (unlikely(!pqp)) {
mlx4_warn(dev, "QP %x is not promiscuous QP\n", qpn);
err = 0;
goto out_mutex;
}
list_del(&pqp->list);
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox)) {
err = -ENOMEM;
back_to_list = true;
goto out_list;
}
mgm = mailbox->buf;
memset(mgm, 0, sizeof *mgm);
members_count = 0;
list_for_each_entry(dqp, &s_steer->promisc_qps[steer], list)
mgm->qp[members_count++] = cpu_to_be32(dqp->qpn & MGM_QPN_MASK);
mgm->members_count = cpu_to_be32(members_count | MLX4_PROT_ETH << 30);
err = mlx4_WRITE_PROMISC(dev, port, steer, mailbox);
if (err)
goto out_mailbox;
list_for_each_entry(entry, &s_steer->steer_entries[steer], list) {
found = false;
list_for_each_entry(dqp, &entry->duplicates, list) {
if (dqp->qpn == qpn) {
found = true;
break;
}
}
if (found) {
list_del(&dqp->list);
kfree(dqp);
} else {
err = mlx4_READ_ENTRY(dev, entry->index, mailbox);
if (err)
goto out_mailbox;
members_count = be32_to_cpu(mgm->members_count) & 0xffffff;
for (loc = -1, i = 0; i < members_count; ++i)
if ((be32_to_cpu(mgm->qp[i]) & MGM_QPN_MASK) == qpn)
loc = i;
mgm->members_count = cpu_to_be32(--members_count |
(MLX4_PROT_ETH << 30));
mgm->qp[loc] = mgm->qp[i - 1];
mgm->qp[i - 1] = 0;
err = mlx4_WRITE_ENTRY(dev, entry->index, mailbox);
if (err)
goto out_mailbox;
}
}
out_mailbox:
mlx4_free_cmd_mailbox(dev, mailbox);
out_list:
if (back_to_list)
list_add_tail(&pqp->list, &s_steer->promisc_qps[steer]);
else
kfree(pqp);
out_mutex:
mutex_unlock(&priv->mcg_table.mutex);
return err;
}
static int find_entry(struct mlx4_dev *dev, u8 port,
u8 *gid, enum mlx4_protocol prot,
struct mlx4_cmd_mailbox *mgm_mailbox,
int *prev, int *index)
{
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_mgm *mgm = mgm_mailbox->buf;
u8 *mgid;
int err;
u16 hash;
u8 op_mod = (prot == MLX4_PROT_ETH) ?
!!(dev->caps.flags & MLX4_DEV_CAP_FLAG_VEP_MC_STEER) : 0;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return -ENOMEM;
mgid = mailbox->buf;
memcpy(mgid, gid, 16);
err = mlx4_GID_HASH(dev, mailbox, &hash, op_mod);
mlx4_free_cmd_mailbox(dev, mailbox);
if (err)
return err;
if (0)
mlx4_dbg(dev, "Hash for %pI6 is %04x\n", gid, hash);
*index = hash;
*prev = -1;
do {
err = mlx4_READ_ENTRY(dev, *index, mgm_mailbox);
if (err)
return err;
if (!(be32_to_cpu(mgm->members_count) & 0xffffff)) {
if (*index != hash) {
mlx4_err(dev, "Found zero MGID in AMGM.\n");
err = -EINVAL;
}
return err;
}
if (!memcmp(mgm->gid, gid, 16) &&
be32_to_cpu(mgm->members_count) >> 30 == prot)
return err;
*prev = *index;
*index = be32_to_cpu(mgm->next_gid_index) >> 6;
} while (*index);
*index = -1;
return err;
}
int mlx4_qp_attach_common(struct mlx4_dev *dev, struct mlx4_qp *qp, u8 gid[16],
int block_mcast_loopback, enum mlx4_protocol prot,
enum mlx4_steer_type steer)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_mgm *mgm;
u32 members_count;
int index, prev;
int link = 0;
int i;
int err;
u8 port = gid[5];
u8 new_entry = 0;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
mgm = mailbox->buf;
mutex_lock(&priv->mcg_table.mutex);
err = find_entry(dev, port, gid, prot,
mailbox, &prev, &index);
if (err)
goto out;
if (index != -1) {
if (!(be32_to_cpu(mgm->members_count) & 0xffffff)) {
new_entry = 1;
memcpy(mgm->gid, gid, 16);
}
} else {
link = 1;
index = mlx4_bitmap_alloc(&priv->mcg_table.bitmap);
if (index == -1) {
mlx4_err(dev, "No AMGM entries left\n");
err = -ENOMEM;
goto out;
}
index += dev->caps.num_mgms;
new_entry = 1;
memset(mgm, 0, sizeof *mgm);
memcpy(mgm->gid, gid, 16);
}
members_count = be32_to_cpu(mgm->members_count) & 0xffffff;
if (members_count == dev->caps.num_qp_per_mgm) {
mlx4_err(dev, "MGM at index %x is full.\n", index);
err = -ENOMEM;
goto out;
}
for (i = 0; i < members_count; ++i)
if ((be32_to_cpu(mgm->qp[i]) & MGM_QPN_MASK) == qp->qpn) {
mlx4_dbg(dev, "QP %06x already a member of MGM\n", qp->qpn);
err = 0;
goto out;
}
if (block_mcast_loopback)
mgm->qp[members_count++] = cpu_to_be32((qp->qpn & MGM_QPN_MASK) |
(1U << MGM_BLCK_LB_BIT));
else
mgm->qp[members_count++] = cpu_to_be32(qp->qpn & MGM_QPN_MASK);
mgm->members_count = cpu_to_be32(members_count | (u32) prot << 30);
err = mlx4_WRITE_ENTRY(dev, index, mailbox);
if (err)
goto out;
if (!link)
goto out;
err = mlx4_READ_ENTRY(dev, prev, mailbox);
if (err)
goto out;
mgm->next_gid_index = cpu_to_be32(index << 6);
err = mlx4_WRITE_ENTRY(dev, prev, mailbox);
if (err)
goto out;
out:
if (prot == MLX4_PROT_ETH) {
if (new_entry)
new_steering_entry(dev, port, steer, index, qp->qpn);
else
existing_steering_entry(dev, port, steer,
index, qp->qpn);
}
if (err && link && index != -1) {
if (index < dev->caps.num_mgms)
mlx4_warn(dev, "Got AMGM index %d < %d",
index, dev->caps.num_mgms);
else
mlx4_bitmap_free(&priv->mcg_table.bitmap,
index - dev->caps.num_mgms);
}
mutex_unlock(&priv->mcg_table.mutex);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_qp_detach_common(struct mlx4_dev *dev, struct mlx4_qp *qp, u8 gid[16],
enum mlx4_protocol prot, enum mlx4_steer_type steer)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_mgm *mgm;
u32 members_count;
int prev, index;
int i, loc;
int err;
u8 port = gid[5];
bool removed_entry = false;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
mgm = mailbox->buf;
mutex_lock(&priv->mcg_table.mutex);
err = find_entry(dev, port, gid, prot,
mailbox, &prev, &index);
if (err)
goto out;
if (index == -1) {
mlx4_err(dev, "MGID %pI6 not found\n", gid);
err = -EINVAL;
goto out;
}
if (prot == MLX4_PROT_ETH &&
check_duplicate_entry(dev, port, steer, index, qp->qpn))
goto out;
members_count = be32_to_cpu(mgm->members_count) & 0xffffff;
for (loc = -1, i = 0; i < members_count; ++i)
if ((be32_to_cpu(mgm->qp[i]) & MGM_QPN_MASK) == qp->qpn)
loc = i;
if (loc == -1) {
mlx4_err(dev, "QP %06x not found in MGM\n", qp->qpn);
err = -EINVAL;
goto out;
}
mgm->members_count = cpu_to_be32(--members_count | (u32) prot << 30);
mgm->qp[loc] = mgm->qp[i - 1];
mgm->qp[i - 1] = 0;
if (prot == MLX4_PROT_ETH)
removed_entry = can_remove_steering_entry(dev, port, steer,
index, qp->qpn);
if (i != 1 && (prot != MLX4_PROT_ETH || !removed_entry)) {
err = mlx4_WRITE_ENTRY(dev, index, mailbox);
goto out;
}
mgm->members_count = cpu_to_be32((u32) prot << 30);
if (prev == -1) {
int amgm_index = be32_to_cpu(mgm->next_gid_index) >> 6;
if (amgm_index) {
err = mlx4_READ_ENTRY(dev, amgm_index, mailbox);
if (err)
goto out;
} else
memset(mgm->gid, 0, 16);
err = mlx4_WRITE_ENTRY(dev, index, mailbox);
if (err)
goto out;
if (amgm_index) {
if (amgm_index < dev->caps.num_mgms)
mlx4_warn(dev, "MGM entry %d had AMGM index %d < %d",
index, amgm_index, dev->caps.num_mgms);
else
mlx4_bitmap_free(&priv->mcg_table.bitmap,
amgm_index - dev->caps.num_mgms);
}
} else {
int cur_next_index = be32_to_cpu(mgm->next_gid_index) >> 6;
err = mlx4_READ_ENTRY(dev, prev, mailbox);
if (err)
goto out;
mgm->next_gid_index = cpu_to_be32(cur_next_index << 6);
err = mlx4_WRITE_ENTRY(dev, prev, mailbox);
if (err)
goto out;
if (index < dev->caps.num_mgms)
mlx4_warn(dev, "entry %d had next AMGM index %d < %d",
prev, index, dev->caps.num_mgms);
else
mlx4_bitmap_free(&priv->mcg_table.bitmap,
index - dev->caps.num_mgms);
}
out:
mutex_unlock(&priv->mcg_table.mutex);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
static int mlx4_QP_ATTACH(struct mlx4_dev *dev, struct mlx4_qp *qp,
u8 gid[16], u8 attach, u8 block_loopback,
enum mlx4_protocol prot)
{
struct mlx4_cmd_mailbox *mailbox;
int err = 0;
int qpn;
if (!mlx4_is_mfunc(dev))
return -EBADF;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
memcpy(mailbox->buf, gid, 16);
qpn = qp->qpn;
qpn |= (prot << 28);
if (attach && block_loopback)
qpn |= (1 << 31);
err = mlx4_cmd(dev, mailbox->dma, qpn, attach,
MLX4_CMD_QP_ATTACH, MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_WRAPPED);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_multicast_attach(struct mlx4_dev *dev, struct mlx4_qp *qp, u8 gid[16],
int block_mcast_loopback, enum mlx4_protocol prot)
{
if (prot == MLX4_PROT_ETH &&
!(dev->caps.flags & MLX4_DEV_CAP_FLAG_VEP_MC_STEER))
return 0;
if (prot == MLX4_PROT_ETH)
gid[7] |= (MLX4_MC_STEER << 1);
if (mlx4_is_mfunc(dev))
return mlx4_QP_ATTACH(dev, qp, gid, 1,
block_mcast_loopback, prot);
return mlx4_qp_attach_common(dev, qp, gid, block_mcast_loopback,
prot, MLX4_MC_STEER);
}
int mlx4_multicast_detach(struct mlx4_dev *dev, struct mlx4_qp *qp, u8 gid[16],
enum mlx4_protocol prot)
{
if (prot == MLX4_PROT_ETH &&
!(dev->caps.flags & MLX4_DEV_CAP_FLAG_VEP_MC_STEER))
return 0;
if (prot == MLX4_PROT_ETH)
gid[7] |= (MLX4_MC_STEER << 1);
if (mlx4_is_mfunc(dev))
return mlx4_QP_ATTACH(dev, qp, gid, 0, 0, prot);
return mlx4_qp_detach_common(dev, qp, gid, prot, MLX4_MC_STEER);
}
int mlx4_unicast_attach(struct mlx4_dev *dev,
struct mlx4_qp *qp, u8 gid[16],
int block_mcast_loopback, enum mlx4_protocol prot)
{
if (prot == MLX4_PROT_ETH &&
!(dev->caps.flags & MLX4_DEV_CAP_FLAG_VEP_UC_STEER))
return 0;
if (prot == MLX4_PROT_ETH)
gid[7] |= (MLX4_UC_STEER << 1);
if (mlx4_is_mfunc(dev))
return mlx4_QP_ATTACH(dev, qp, gid, 1,
block_mcast_loopback, prot);
return mlx4_qp_attach_common(dev, qp, gid, block_mcast_loopback,
prot, MLX4_UC_STEER);
}
int mlx4_unicast_detach(struct mlx4_dev *dev, struct mlx4_qp *qp,
u8 gid[16], enum mlx4_protocol prot)
{
if (prot == MLX4_PROT_ETH &&
!(dev->caps.flags & MLX4_DEV_CAP_FLAG_VEP_UC_STEER))
return 0;
if (prot == MLX4_PROT_ETH)
gid[7] |= (MLX4_UC_STEER << 1);
if (mlx4_is_mfunc(dev))
return mlx4_QP_ATTACH(dev, qp, gid, 0, 0, prot);
return mlx4_qp_detach_common(dev, qp, gid, prot, MLX4_UC_STEER);
}
int mlx4_PROMISC_wrapper(struct mlx4_dev *dev, int slave,
struct mlx4_vhcr *vhcr,
struct mlx4_cmd_mailbox *inbox,
struct mlx4_cmd_mailbox *outbox,
struct mlx4_cmd_info *cmd)
{
u32 qpn = (u32) vhcr->in_param & 0xffffffff;
u8 port = vhcr->in_param >> 62;
enum mlx4_steer_type steer = vhcr->in_modifier;
if (mlx4_is_mfunc(dev) && steer == MLX4_UC_STEER)
return 0;
if (vhcr->op_modifier)
return add_promisc_qp(dev, port, steer, qpn);
else
return remove_promisc_qp(dev, port, steer, qpn);
}
static int mlx4_PROMISC(struct mlx4_dev *dev, u32 qpn,
enum mlx4_steer_type steer, u8 add, u8 port)
{
return mlx4_cmd(dev, (u64) qpn | (u64) port << 62, (u32) steer, add,
MLX4_CMD_PROMISC, MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_WRAPPED);
}
int mlx4_multicast_promisc_add(struct mlx4_dev *dev, u32 qpn, u8 port)
{
if (!(dev->caps.flags & MLX4_DEV_CAP_FLAG_VEP_MC_STEER))
return 0;
if (mlx4_is_mfunc(dev))
return mlx4_PROMISC(dev, qpn, MLX4_MC_STEER, 1, port);
return add_promisc_qp(dev, port, MLX4_MC_STEER, qpn);
}
int mlx4_multicast_promisc_remove(struct mlx4_dev *dev, u32 qpn, u8 port)
{
if (!(dev->caps.flags & MLX4_DEV_CAP_FLAG_VEP_MC_STEER))
return 0;
if (mlx4_is_mfunc(dev))
return mlx4_PROMISC(dev, qpn, MLX4_MC_STEER, 0, port);
return remove_promisc_qp(dev, port, MLX4_MC_STEER, qpn);
}
int mlx4_unicast_promisc_add(struct mlx4_dev *dev, u32 qpn, u8 port)
{
if (!(dev->caps.flags & MLX4_DEV_CAP_FLAG_VEP_UC_STEER))
return 0;
if (mlx4_is_mfunc(dev))
return mlx4_PROMISC(dev, qpn, MLX4_UC_STEER, 1, port);
return add_promisc_qp(dev, port, MLX4_UC_STEER, qpn);
}
int mlx4_unicast_promisc_remove(struct mlx4_dev *dev, u32 qpn, u8 port)
{
if (!(dev->caps.flags & MLX4_DEV_CAP_FLAG_VEP_UC_STEER))
return 0;
if (mlx4_is_mfunc(dev))
return mlx4_PROMISC(dev, qpn, MLX4_UC_STEER, 0, port);
return remove_promisc_qp(dev, port, MLX4_UC_STEER, qpn);
}
int mlx4_init_mcg_table(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int err;
err = mlx4_bitmap_init(&priv->mcg_table.bitmap, dev->caps.num_amgms,
dev->caps.num_amgms - 1, 0, 0);
if (err)
return err;
mutex_init(&priv->mcg_table.mutex);
return 0;
}
void mlx4_cleanup_mcg_table(struct mlx4_dev *dev)
{
mlx4_bitmap_cleanup(&mlx4_priv(dev)->mcg_table.bitmap);
}
