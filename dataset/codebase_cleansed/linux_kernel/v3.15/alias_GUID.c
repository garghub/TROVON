void mlx4_ib_update_cache_on_guid_change(struct mlx4_ib_dev *dev, int block_num,
u8 port_num, u8 *p_data)
{
int i;
u64 guid_indexes;
int slave_id;
int port_index = port_num - 1;
if (!mlx4_is_master(dev->dev))
return;
guid_indexes = be64_to_cpu((__force __be64) dev->sriov.alias_guid.
ports_guid[port_num - 1].
all_rec_per_port[block_num].guid_indexes);
pr_debug("port: %d, guid_indexes: 0x%llx\n", port_num, guid_indexes);
for (i = 0; i < NUM_ALIAS_GUID_IN_REC; i++) {
if (test_bit(i + 4, (unsigned long *)&guid_indexes)) {
slave_id = (block_num * NUM_ALIAS_GUID_IN_REC) + i ;
if (slave_id >= dev->dev->num_slaves) {
pr_debug("The last slave: %d\n", slave_id);
return;
}
memcpy(&dev->sriov.demux[port_index].guid_cache[slave_id],
&p_data[i * GUID_REC_SIZE],
GUID_REC_SIZE);
} else
pr_debug("Guid number: %d in block: %d"
" was not updated\n", i, block_num);
}
}
static __be64 get_cached_alias_guid(struct mlx4_ib_dev *dev, int port, int index)
{
if (index >= NUM_ALIAS_GUID_PER_PORT) {
pr_err("%s: ERROR: asked for index:%d\n", __func__, index);
return (__force __be64) -1;
}
return *(__be64 *)&dev->sriov.demux[port - 1].guid_cache[index];
}
ib_sa_comp_mask mlx4_ib_get_aguid_comp_mask_from_ix(int index)
{
return IB_SA_COMP_MASK(4 + index);
}
void mlx4_ib_notify_slaves_on_guid_change(struct mlx4_ib_dev *dev,
int block_num, u8 port_num,
u8 *p_data)
{
int i;
u64 guid_indexes;
int slave_id;
enum slave_port_state new_state;
enum slave_port_state prev_state;
__be64 tmp_cur_ag, form_cache_ag;
enum slave_port_gen_event gen_event;
if (!mlx4_is_master(dev->dev))
return;
guid_indexes = be64_to_cpu((__force __be64) dev->sriov.alias_guid.
ports_guid[port_num - 1].
all_rec_per_port[block_num].guid_indexes);
pr_debug("port: %d, guid_indexes: 0x%llx\n", port_num, guid_indexes);
for (i = 0; i < NUM_ALIAS_GUID_IN_REC; i++) {
if (!(test_bit(i + 4, (unsigned long *)&guid_indexes)))
continue;
slave_id = (block_num * NUM_ALIAS_GUID_IN_REC) + i ;
if (slave_id >= dev->dev->num_vfs + 1)
return;
tmp_cur_ag = *(__be64 *)&p_data[i * GUID_REC_SIZE];
form_cache_ag = get_cached_alias_guid(dev, port_num,
(NUM_ALIAS_GUID_IN_REC * block_num) + i);
if (tmp_cur_ag != form_cache_ag)
continue;
mlx4_gen_guid_change_eqe(dev->dev, slave_id, port_num);
if (tmp_cur_ag != MLX4_NOT_SET_GUID) {
prev_state = mlx4_get_slave_port_state(dev->dev, slave_id, port_num);
new_state = set_and_calc_slave_port_state(dev->dev, slave_id, port_num,
MLX4_PORT_STATE_IB_PORT_STATE_EVENT_GID_VALID,
&gen_event);
pr_debug("slave: %d, port: %d prev_port_state: %d,"
" new_port_state: %d, gen_event: %d\n",
slave_id, port_num, prev_state, new_state, gen_event);
if (gen_event == SLAVE_PORT_GEN_EVENT_UP) {
pr_debug("sending PORT_UP event to slave: %d, port: %d\n",
slave_id, port_num);
mlx4_gen_port_state_change_eqe(dev->dev, slave_id,
port_num, MLX4_PORT_CHANGE_SUBTYPE_ACTIVE);
}
} else {
set_and_calc_slave_port_state(dev->dev, slave_id, port_num,
MLX4_PORT_STATE_IB_EVENT_GID_INVALID,
&gen_event);
pr_debug("sending PORT DOWN event to slave: %d, port: %d\n",
slave_id, port_num);
mlx4_gen_port_state_change_eqe(dev->dev, slave_id, port_num,
MLX4_PORT_CHANGE_SUBTYPE_DOWN);
}
}
}
static void aliasguid_query_handler(int status,
struct ib_sa_guidinfo_rec *guid_rec,
void *context)
{
struct mlx4_ib_dev *dev;
struct mlx4_alias_guid_work_context *cb_ctx = context;
u8 port_index ;
int i;
struct mlx4_sriov_alias_guid_info_rec_det *rec;
unsigned long flags, flags1;
if (!context)
return;
dev = cb_ctx->dev;
port_index = cb_ctx->port - 1;
rec = &dev->sriov.alias_guid.ports_guid[port_index].
all_rec_per_port[cb_ctx->block_num];
if (status) {
rec->status = MLX4_GUID_INFO_STATUS_IDLE;
pr_debug("(port: %d) failed: status = %d\n",
cb_ctx->port, status);
goto out;
}
if (guid_rec->block_num != cb_ctx->block_num) {
pr_err("block num mismatch: %d != %d\n",
cb_ctx->block_num, guid_rec->block_num);
goto out;
}
pr_debug("lid/port: %d/%d, block_num: %d\n",
be16_to_cpu(guid_rec->lid), cb_ctx->port,
guid_rec->block_num);
rec = &dev->sriov.alias_guid.ports_guid[port_index].
all_rec_per_port[guid_rec->block_num];
rec->status = MLX4_GUID_INFO_STATUS_SET;
rec->method = MLX4_GUID_INFO_RECORD_SET;
for (i = 0 ; i < NUM_ALIAS_GUID_IN_REC; i++) {
__be64 tmp_cur_ag;
tmp_cur_ag = *(__be64 *)&guid_rec->guid_info_list[i * GUID_REC_SIZE];
if (tmp_cur_ag == MLX4_NOT_SET_GUID) {
mlx4_ib_warn(&dev->ib_dev, "%s:Record num %d in "
"block_num: %d was declined by SM, "
"ownership by %d (0 = driver, 1=sysAdmin,"
" 2=None)\n", __func__, i,
guid_rec->block_num, rec->ownership);
if (rec->ownership == MLX4_GUID_DRIVER_ASSIGN) {
*(__be64 *)&rec->all_recs[i * GUID_REC_SIZE] =
MLX4_NOT_SET_GUID;
rec->status = MLX4_GUID_INFO_STATUS_IDLE;
rec->guid_indexes |= mlx4_ib_get_aguid_comp_mask_from_ix(i);
}
} else {
if (rec->ownership == MLX4_GUID_SYSADMIN_ASSIGN &&
tmp_cur_ag != *(__be64 *)&rec->all_recs[i * GUID_REC_SIZE]) {
mlx4_ib_warn(&dev->ib_dev, "%s: Failed to set"
" admin guid after SysAdmin "
"configuration. "
"Record num %d in block_num:%d "
"was declined by SM, "
"new val(0x%llx) was kept\n",
__func__, i,
guid_rec->block_num,
be64_to_cpu(*(__be64 *) &
rec->all_recs[i * GUID_REC_SIZE]));
} else {
memcpy(&rec->all_recs[i * GUID_REC_SIZE],
&guid_rec->guid_info_list[i * GUID_REC_SIZE],
GUID_REC_SIZE);
}
}
}
mlx4_ib_notify_slaves_on_guid_change(dev, guid_rec->block_num,
cb_ctx->port,
guid_rec->guid_info_list);
out:
spin_lock_irqsave(&dev->sriov.going_down_lock, flags);
spin_lock_irqsave(&dev->sriov.alias_guid.ag_work_lock, flags1);
if (!dev->sriov.is_going_down)
queue_delayed_work(dev->sriov.alias_guid.ports_guid[port_index].wq,
&dev->sriov.alias_guid.ports_guid[port_index].
alias_guid_work, 0);
if (cb_ctx->sa_query) {
list_del(&cb_ctx->list);
kfree(cb_ctx);
} else
complete(&cb_ctx->done);
spin_unlock_irqrestore(&dev->sriov.alias_guid.ag_work_lock, flags1);
spin_unlock_irqrestore(&dev->sriov.going_down_lock, flags);
}
static void invalidate_guid_record(struct mlx4_ib_dev *dev, u8 port, int index)
{
int i;
u64 cur_admin_val;
ib_sa_comp_mask comp_mask = 0;
dev->sriov.alias_guid.ports_guid[port - 1].all_rec_per_port[index].status
= MLX4_GUID_INFO_STATUS_IDLE;
dev->sriov.alias_guid.ports_guid[port - 1].all_rec_per_port[index].method
= MLX4_GUID_INFO_RECORD_SET;
for (i = 0; i < NUM_ALIAS_GUID_IN_REC; i++) {
cur_admin_val =
*(u64 *)&dev->sriov.alias_guid.ports_guid[port - 1].
all_rec_per_port[index].all_recs[GUID_REC_SIZE * i];
if (MLX4_GUID_FOR_DELETE_VAL == cur_admin_val ||
(!index && !i) ||
MLX4_GUID_NONE_ASSIGN == dev->sriov.alias_guid.
ports_guid[port - 1].all_rec_per_port[index].ownership)
continue;
comp_mask |= mlx4_ib_get_aguid_comp_mask_from_ix(i);
}
dev->sriov.alias_guid.ports_guid[port - 1].
all_rec_per_port[index].guid_indexes = comp_mask;
}
static int set_guid_rec(struct ib_device *ibdev,
u8 port, int index,
struct mlx4_sriov_alias_guid_info_rec_det *rec_det)
{
int err;
struct mlx4_ib_dev *dev = to_mdev(ibdev);
struct ib_sa_guidinfo_rec guid_info_rec;
ib_sa_comp_mask comp_mask;
struct ib_port_attr attr;
struct mlx4_alias_guid_work_context *callback_context;
unsigned long resched_delay, flags, flags1;
struct list_head *head =
&dev->sriov.alias_guid.ports_guid[port - 1].cb_list;
err = __mlx4_ib_query_port(ibdev, port, &attr, 1);
if (err) {
pr_debug("mlx4_ib_query_port failed (err: %d), port: %d\n",
err, port);
return err;
}
if (attr.state != IB_PORT_ACTIVE) {
pr_debug("port %d not active...rescheduling\n", port);
resched_delay = 5 * HZ;
err = -EAGAIN;
goto new_schedule;
}
callback_context = kmalloc(sizeof *callback_context, GFP_KERNEL);
if (!callback_context) {
err = -ENOMEM;
resched_delay = HZ * 5;
goto new_schedule;
}
callback_context->port = port;
callback_context->dev = dev;
callback_context->block_num = index;
memset(&guid_info_rec, 0, sizeof (struct ib_sa_guidinfo_rec));
guid_info_rec.lid = cpu_to_be16(attr.lid);
guid_info_rec.block_num = index;
memcpy(guid_info_rec.guid_info_list, rec_det->all_recs,
GUID_REC_SIZE * NUM_ALIAS_GUID_IN_REC);
comp_mask = IB_SA_GUIDINFO_REC_LID | IB_SA_GUIDINFO_REC_BLOCK_NUM |
rec_det->guid_indexes;
init_completion(&callback_context->done);
spin_lock_irqsave(&dev->sriov.alias_guid.ag_work_lock, flags1);
list_add_tail(&callback_context->list, head);
spin_unlock_irqrestore(&dev->sriov.alias_guid.ag_work_lock, flags1);
callback_context->query_id =
ib_sa_guid_info_rec_query(dev->sriov.alias_guid.sa_client,
ibdev, port, &guid_info_rec,
comp_mask, rec_det->method, 1000,
GFP_KERNEL, aliasguid_query_handler,
callback_context,
&callback_context->sa_query);
if (callback_context->query_id < 0) {
pr_debug("ib_sa_guid_info_rec_query failed, query_id: "
"%d. will reschedule to the next 1 sec.\n",
callback_context->query_id);
spin_lock_irqsave(&dev->sriov.alias_guid.ag_work_lock, flags1);
list_del(&callback_context->list);
kfree(callback_context);
spin_unlock_irqrestore(&dev->sriov.alias_guid.ag_work_lock, flags1);
resched_delay = 1 * HZ;
err = -EAGAIN;
goto new_schedule;
}
err = 0;
goto out;
new_schedule:
spin_lock_irqsave(&dev->sriov.going_down_lock, flags);
spin_lock_irqsave(&dev->sriov.alias_guid.ag_work_lock, flags1);
invalidate_guid_record(dev, port, index);
if (!dev->sriov.is_going_down) {
queue_delayed_work(dev->sriov.alias_guid.ports_guid[port - 1].wq,
&dev->sriov.alias_guid.ports_guid[port - 1].alias_guid_work,
resched_delay);
}
spin_unlock_irqrestore(&dev->sriov.alias_guid.ag_work_lock, flags1);
spin_unlock_irqrestore(&dev->sriov.going_down_lock, flags);
out:
return err;
}
void mlx4_ib_invalidate_all_guid_record(struct mlx4_ib_dev *dev, int port)
{
int i;
unsigned long flags, flags1;
pr_debug("port %d\n", port);
spin_lock_irqsave(&dev->sriov.going_down_lock, flags);
spin_lock_irqsave(&dev->sriov.alias_guid.ag_work_lock, flags1);
for (i = 0; i < NUM_ALIAS_GUID_REC_IN_PORT; i++)
invalidate_guid_record(dev, port, i);
if (mlx4_is_master(dev->dev) && !dev->sriov.is_going_down) {
cancel_delayed_work(&dev->sriov.alias_guid.
ports_guid[port - 1].alias_guid_work);
queue_delayed_work(dev->sriov.alias_guid.ports_guid[port - 1].wq,
&dev->sriov.alias_guid.ports_guid[port - 1].alias_guid_work,
0);
}
spin_unlock_irqrestore(&dev->sriov.alias_guid.ag_work_lock, flags1);
spin_unlock_irqrestore(&dev->sriov.going_down_lock, flags);
}
static int get_next_record_to_update(struct mlx4_ib_dev *dev, u8 port,
struct mlx4_next_alias_guid_work *rec)
{
int j;
unsigned long flags;
for (j = 0; j < NUM_ALIAS_GUID_REC_IN_PORT; j++) {
spin_lock_irqsave(&dev->sriov.alias_guid.ag_work_lock, flags);
if (dev->sriov.alias_guid.ports_guid[port].all_rec_per_port[j].status ==
MLX4_GUID_INFO_STATUS_IDLE) {
memcpy(&rec->rec_det,
&dev->sriov.alias_guid.ports_guid[port].all_rec_per_port[j],
sizeof (struct mlx4_sriov_alias_guid_info_rec_det));
rec->port = port;
rec->block_num = j;
dev->sriov.alias_guid.ports_guid[port].all_rec_per_port[j].status =
MLX4_GUID_INFO_STATUS_PENDING;
spin_unlock_irqrestore(&dev->sriov.alias_guid.ag_work_lock, flags);
return 0;
}
spin_unlock_irqrestore(&dev->sriov.alias_guid.ag_work_lock, flags);
}
return -ENOENT;
}
static void set_administratively_guid_record(struct mlx4_ib_dev *dev, int port,
int rec_index,
struct mlx4_sriov_alias_guid_info_rec_det *rec_det)
{
dev->sriov.alias_guid.ports_guid[port].all_rec_per_port[rec_index].guid_indexes =
rec_det->guid_indexes;
memcpy(dev->sriov.alias_guid.ports_guid[port].all_rec_per_port[rec_index].all_recs,
rec_det->all_recs, NUM_ALIAS_GUID_IN_REC * GUID_REC_SIZE);
dev->sriov.alias_guid.ports_guid[port].all_rec_per_port[rec_index].status =
rec_det->status;
}
static void set_all_slaves_guids(struct mlx4_ib_dev *dev, int port)
{
int j;
struct mlx4_sriov_alias_guid_info_rec_det rec_det ;
for (j = 0 ; j < NUM_ALIAS_GUID_REC_IN_PORT ; j++) {
memset(rec_det.all_recs, 0, NUM_ALIAS_GUID_IN_REC * GUID_REC_SIZE);
rec_det.guid_indexes = (!j ? 0 : IB_SA_GUIDINFO_REC_GID0) |
IB_SA_GUIDINFO_REC_GID1 | IB_SA_GUIDINFO_REC_GID2 |
IB_SA_GUIDINFO_REC_GID3 | IB_SA_GUIDINFO_REC_GID4 |
IB_SA_GUIDINFO_REC_GID5 | IB_SA_GUIDINFO_REC_GID6 |
IB_SA_GUIDINFO_REC_GID7;
rec_det.status = MLX4_GUID_INFO_STATUS_IDLE;
set_administratively_guid_record(dev, port, j, &rec_det);
}
}
static void alias_guid_work(struct work_struct *work)
{
struct delayed_work *delay = to_delayed_work(work);
int ret = 0;
struct mlx4_next_alias_guid_work *rec;
struct mlx4_sriov_alias_guid_port_rec_det *sriov_alias_port =
container_of(delay, struct mlx4_sriov_alias_guid_port_rec_det,
alias_guid_work);
struct mlx4_sriov_alias_guid *sriov_alias_guid = sriov_alias_port->parent;
struct mlx4_ib_sriov *ib_sriov = container_of(sriov_alias_guid,
struct mlx4_ib_sriov,
alias_guid);
struct mlx4_ib_dev *dev = container_of(ib_sriov, struct mlx4_ib_dev, sriov);
rec = kzalloc(sizeof *rec, GFP_KERNEL);
if (!rec) {
pr_err("alias_guid_work: No Memory\n");
return;
}
pr_debug("starting [port: %d]...\n", sriov_alias_port->port + 1);
ret = get_next_record_to_update(dev, sriov_alias_port->port, rec);
if (ret) {
pr_debug("No more records to update.\n");
goto out;
}
set_guid_rec(&dev->ib_dev, rec->port + 1, rec->block_num,
&rec->rec_det);
out:
kfree(rec);
}
void mlx4_ib_init_alias_guid_work(struct mlx4_ib_dev *dev, int port)
{
unsigned long flags, flags1;
if (!mlx4_is_master(dev->dev))
return;
spin_lock_irqsave(&dev->sriov.going_down_lock, flags);
spin_lock_irqsave(&dev->sriov.alias_guid.ag_work_lock, flags1);
if (!dev->sriov.is_going_down) {
queue_delayed_work(dev->sriov.alias_guid.ports_guid[port].wq,
&dev->sriov.alias_guid.ports_guid[port].alias_guid_work, 0);
}
spin_unlock_irqrestore(&dev->sriov.alias_guid.ag_work_lock, flags1);
spin_unlock_irqrestore(&dev->sriov.going_down_lock, flags);
}
void mlx4_ib_destroy_alias_guid_service(struct mlx4_ib_dev *dev)
{
int i;
struct mlx4_ib_sriov *sriov = &dev->sriov;
struct mlx4_alias_guid_work_context *cb_ctx;
struct mlx4_sriov_alias_guid_port_rec_det *det;
struct ib_sa_query *sa_query;
unsigned long flags;
for (i = 0 ; i < dev->num_ports; i++) {
cancel_delayed_work(&dev->sriov.alias_guid.ports_guid[i].alias_guid_work);
det = &sriov->alias_guid.ports_guid[i];
spin_lock_irqsave(&sriov->alias_guid.ag_work_lock, flags);
while (!list_empty(&det->cb_list)) {
cb_ctx = list_entry(det->cb_list.next,
struct mlx4_alias_guid_work_context,
list);
sa_query = cb_ctx->sa_query;
cb_ctx->sa_query = NULL;
list_del(&cb_ctx->list);
spin_unlock_irqrestore(&sriov->alias_guid.ag_work_lock, flags);
ib_sa_cancel_query(cb_ctx->query_id, sa_query);
wait_for_completion(&cb_ctx->done);
kfree(cb_ctx);
spin_lock_irqsave(&sriov->alias_guid.ag_work_lock, flags);
}
spin_unlock_irqrestore(&sriov->alias_guid.ag_work_lock, flags);
}
for (i = 0 ; i < dev->num_ports; i++) {
flush_workqueue(dev->sriov.alias_guid.ports_guid[i].wq);
destroy_workqueue(dev->sriov.alias_guid.ports_guid[i].wq);
}
ib_sa_unregister_client(dev->sriov.alias_guid.sa_client);
kfree(dev->sriov.alias_guid.sa_client);
}
int mlx4_ib_init_alias_guid_service(struct mlx4_ib_dev *dev)
{
char alias_wq_name[15];
int ret = 0;
int i, j, k;
union ib_gid gid;
if (!mlx4_is_master(dev->dev))
return 0;
dev->sriov.alias_guid.sa_client =
kzalloc(sizeof *dev->sriov.alias_guid.sa_client, GFP_KERNEL);
if (!dev->sriov.alias_guid.sa_client)
return -ENOMEM;
ib_sa_register_client(dev->sriov.alias_guid.sa_client);
spin_lock_init(&dev->sriov.alias_guid.ag_work_lock);
for (i = 1; i <= dev->num_ports; ++i) {
if (dev->ib_dev.query_gid(&dev->ib_dev , i, 0, &gid)) {
ret = -EFAULT;
goto err_unregister;
}
}
for (i = 0 ; i < dev->num_ports; i++) {
memset(&dev->sriov.alias_guid.ports_guid[i], 0,
sizeof (struct mlx4_sriov_alias_guid_port_rec_det));
for (j = 0; j < NUM_ALIAS_GUID_REC_IN_PORT; j++) {
if (mlx4_ib_sm_guid_assign) {
dev->sriov.alias_guid.ports_guid[i].
all_rec_per_port[j].
ownership = MLX4_GUID_DRIVER_ASSIGN;
continue;
}
dev->sriov.alias_guid.ports_guid[i].all_rec_per_port[j].
ownership = MLX4_GUID_NONE_ASSIGN;
for (k = 0; k < NUM_ALIAS_GUID_IN_REC; k++) {
*(__be64 *)&dev->sriov.alias_guid.ports_guid[i].
all_rec_per_port[j].all_recs[GUID_REC_SIZE * k] =
cpu_to_be64(MLX4_GUID_FOR_DELETE_VAL);
}
}
INIT_LIST_HEAD(&dev->sriov.alias_guid.ports_guid[i].cb_list);
for (j = 0 ; j < NUM_ALIAS_GUID_REC_IN_PORT; j++)
invalidate_guid_record(dev, i + 1, j);
dev->sriov.alias_guid.ports_guid[i].parent = &dev->sriov.alias_guid;
dev->sriov.alias_guid.ports_guid[i].port = i;
if (mlx4_ib_sm_guid_assign)
set_all_slaves_guids(dev, i);
snprintf(alias_wq_name, sizeof alias_wq_name, "alias_guid%d", i);
dev->sriov.alias_guid.ports_guid[i].wq =
create_singlethread_workqueue(alias_wq_name);
if (!dev->sriov.alias_guid.ports_guid[i].wq) {
ret = -ENOMEM;
goto err_thread;
}
INIT_DELAYED_WORK(&dev->sriov.alias_guid.ports_guid[i].alias_guid_work,
alias_guid_work);
}
return 0;
err_thread:
for (--i; i >= 0; i--) {
destroy_workqueue(dev->sriov.alias_guid.ports_guid[i].wq);
dev->sriov.alias_guid.ports_guid[i].wq = NULL;
}
err_unregister:
ib_sa_unregister_client(dev->sriov.alias_guid.sa_client);
kfree(dev->sriov.alias_guid.sa_client);
dev->sriov.alias_guid.sa_client = NULL;
pr_err("init_alias_guid_service: Failed. (ret:%d)\n", ret);
return ret;
}
