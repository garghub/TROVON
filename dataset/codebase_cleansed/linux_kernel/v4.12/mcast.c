void rvt_driver_mcast_init(struct rvt_dev_info *rdi)
{
spin_lock_init(&rdi->n_mcast_grps_lock);
}
static struct rvt_mcast_qp *rvt_mcast_qp_alloc(struct rvt_qp *qp)
{
struct rvt_mcast_qp *mqp;
mqp = kmalloc(sizeof(*mqp), GFP_KERNEL);
if (!mqp)
goto bail;
mqp->qp = qp;
rvt_get_qp(qp);
bail:
return mqp;
}
static void rvt_mcast_qp_free(struct rvt_mcast_qp *mqp)
{
struct rvt_qp *qp = mqp->qp;
rvt_put_qp(qp);
kfree(mqp);
}
static struct rvt_mcast *rvt_mcast_alloc(union ib_gid *mgid, u16 lid)
{
struct rvt_mcast *mcast;
mcast = kzalloc(sizeof(*mcast), GFP_KERNEL);
if (!mcast)
goto bail;
mcast->mcast_addr.mgid = *mgid;
mcast->mcast_addr.lid = lid;
INIT_LIST_HEAD(&mcast->qp_list);
init_waitqueue_head(&mcast->wait);
atomic_set(&mcast->refcount, 0);
bail:
return mcast;
}
static void rvt_mcast_free(struct rvt_mcast *mcast)
{
struct rvt_mcast_qp *p, *tmp;
list_for_each_entry_safe(p, tmp, &mcast->qp_list, list)
rvt_mcast_qp_free(p);
kfree(mcast);
}
struct rvt_mcast *rvt_mcast_find(struct rvt_ibport *ibp, union ib_gid *mgid,
u16 lid)
{
struct rb_node *n;
unsigned long flags;
struct rvt_mcast *found = NULL;
spin_lock_irqsave(&ibp->lock, flags);
n = ibp->mcast_tree.rb_node;
while (n) {
int ret;
struct rvt_mcast *mcast;
mcast = rb_entry(n, struct rvt_mcast, rb_node);
ret = memcmp(mgid->raw, mcast->mcast_addr.mgid.raw,
sizeof(*mgid));
if (ret < 0) {
n = n->rb_left;
} else if (ret > 0) {
n = n->rb_right;
} else {
if (mcast->mcast_addr.lid == lid) {
atomic_inc(&mcast->refcount);
found = mcast;
}
break;
}
}
spin_unlock_irqrestore(&ibp->lock, flags);
return found;
}
static int rvt_mcast_add(struct rvt_dev_info *rdi, struct rvt_ibport *ibp,
struct rvt_mcast *mcast, struct rvt_mcast_qp *mqp)
{
struct rb_node **n = &ibp->mcast_tree.rb_node;
struct rb_node *pn = NULL;
int ret;
spin_lock_irq(&ibp->lock);
while (*n) {
struct rvt_mcast *tmcast;
struct rvt_mcast_qp *p;
pn = *n;
tmcast = rb_entry(pn, struct rvt_mcast, rb_node);
ret = memcmp(mcast->mcast_addr.mgid.raw,
tmcast->mcast_addr.mgid.raw,
sizeof(mcast->mcast_addr.mgid));
if (ret < 0) {
n = &pn->rb_left;
continue;
}
if (ret > 0) {
n = &pn->rb_right;
continue;
}
if (tmcast->mcast_addr.lid != mcast->mcast_addr.lid) {
ret = EINVAL;
goto bail;
}
list_for_each_entry_rcu(p, &tmcast->qp_list, list) {
if (p->qp == mqp->qp) {
ret = ESRCH;
goto bail;
}
}
if (tmcast->n_attached ==
rdi->dparms.props.max_mcast_qp_attach) {
ret = ENOMEM;
goto bail;
}
tmcast->n_attached++;
list_add_tail_rcu(&mqp->list, &tmcast->qp_list);
ret = EEXIST;
goto bail;
}
spin_lock(&rdi->n_mcast_grps_lock);
if (rdi->n_mcast_grps_allocated == rdi->dparms.props.max_mcast_grp) {
spin_unlock(&rdi->n_mcast_grps_lock);
ret = ENOMEM;
goto bail;
}
rdi->n_mcast_grps_allocated++;
spin_unlock(&rdi->n_mcast_grps_lock);
mcast->n_attached++;
list_add_tail_rcu(&mqp->list, &mcast->qp_list);
atomic_inc(&mcast->refcount);
rb_link_node(&mcast->rb_node, pn, n);
rb_insert_color(&mcast->rb_node, &ibp->mcast_tree);
ret = 0;
bail:
spin_unlock_irq(&ibp->lock);
return ret;
}
int rvt_attach_mcast(struct ib_qp *ibqp, union ib_gid *gid, u16 lid)
{
struct rvt_qp *qp = ibqp_to_rvtqp(ibqp);
struct rvt_dev_info *rdi = ib_to_rvt(ibqp->device);
struct rvt_ibport *ibp = rdi->ports[qp->port_num - 1];
struct rvt_mcast *mcast;
struct rvt_mcast_qp *mqp;
int ret = -ENOMEM;
if (ibqp->qp_num <= 1 || qp->state == IB_QPS_RESET)
return -EINVAL;
mcast = rvt_mcast_alloc(gid, lid);
if (!mcast)
return -ENOMEM;
mqp = rvt_mcast_qp_alloc(qp);
if (!mqp)
goto bail_mcast;
switch (rvt_mcast_add(rdi, ibp, mcast, mqp)) {
case ESRCH:
ret = 0;
goto bail_mqp;
case EEXIST:
ret = 0;
goto bail_mcast;
case ENOMEM:
ret = -ENOMEM;
goto bail_mqp;
case EINVAL:
ret = -EINVAL;
goto bail_mqp;
default:
break;
}
return 0;
bail_mqp:
rvt_mcast_qp_free(mqp);
bail_mcast:
rvt_mcast_free(mcast);
return ret;
}
int rvt_detach_mcast(struct ib_qp *ibqp, union ib_gid *gid, u16 lid)
{
struct rvt_qp *qp = ibqp_to_rvtqp(ibqp);
struct rvt_dev_info *rdi = ib_to_rvt(ibqp->device);
struct rvt_ibport *ibp = rdi->ports[qp->port_num - 1];
struct rvt_mcast *mcast = NULL;
struct rvt_mcast_qp *p, *tmp, *delp = NULL;
struct rb_node *n;
int last = 0;
int ret = 0;
if (ibqp->qp_num <= 1 || qp->state == IB_QPS_RESET)
return -EINVAL;
spin_lock_irq(&ibp->lock);
n = ibp->mcast_tree.rb_node;
while (1) {
if (!n) {
spin_unlock_irq(&ibp->lock);
return -EINVAL;
}
mcast = rb_entry(n, struct rvt_mcast, rb_node);
ret = memcmp(gid->raw, mcast->mcast_addr.mgid.raw,
sizeof(*gid));
if (ret < 0) {
n = n->rb_left;
} else if (ret > 0) {
n = n->rb_right;
} else {
if (mcast->mcast_addr.lid != lid) {
spin_unlock_irq(&ibp->lock);
return -EINVAL;
}
break;
}
}
list_for_each_entry_safe(p, tmp, &mcast->qp_list, list) {
if (p->qp != qp)
continue;
list_del_rcu(&p->list);
mcast->n_attached--;
delp = p;
if (list_empty(&mcast->qp_list)) {
rb_erase(&mcast->rb_node, &ibp->mcast_tree);
last = 1;
}
break;
}
spin_unlock_irq(&ibp->lock);
if (!delp)
return -EINVAL;
wait_event(mcast->wait, atomic_read(&mcast->refcount) <= 1);
rvt_mcast_qp_free(delp);
if (last) {
atomic_dec(&mcast->refcount);
wait_event(mcast->wait, !atomic_read(&mcast->refcount));
rvt_mcast_free(mcast);
spin_lock_irq(&rdi->n_mcast_grps_lock);
rdi->n_mcast_grps_allocated--;
spin_unlock_irq(&rdi->n_mcast_grps_lock);
}
return 0;
}
int rvt_mcast_tree_empty(struct rvt_dev_info *rdi)
{
int i;
int in_use = 0;
for (i = 0; i < rdi->dparms.nports; i++)
if (rdi->ports[i]->mcast_tree.rb_node)
in_use++;
return in_use;
}
