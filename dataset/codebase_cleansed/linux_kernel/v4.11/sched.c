static int t4_sched_class_fw_cmd(struct port_info *pi,
struct ch_sched_params *p,
enum sched_fw_ops op)
{
struct adapter *adap = pi->adapter;
struct sched_table *s = pi->sched_tbl;
struct sched_class *e;
int err = 0;
e = &s->tab[p->u.params.class];
switch (op) {
case SCHED_FW_OP_ADD:
err = t4_sched_params(adap, p->type,
p->u.params.level, p->u.params.mode,
p->u.params.rateunit,
p->u.params.ratemode,
p->u.params.channel, e->idx,
p->u.params.minrate, p->u.params.maxrate,
p->u.params.weight, p->u.params.pktsize);
break;
default:
err = -ENOTSUPP;
break;
}
return err;
}
static int t4_sched_bind_unbind_op(struct port_info *pi, void *arg,
enum sched_bind_type type, bool bind)
{
struct adapter *adap = pi->adapter;
u32 fw_mnem, fw_class, fw_param;
unsigned int pf = adap->pf;
unsigned int vf = 0;
int err = 0;
switch (type) {
case SCHED_QUEUE: {
struct sched_queue_entry *qe;
qe = (struct sched_queue_entry *)arg;
fw_mnem = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DMAQ) |
FW_PARAMS_PARAM_X_V(
FW_PARAMS_PARAM_DMAQ_EQ_SCHEDCLASS_ETH));
fw_class = bind ? qe->param.class : FW_SCHED_CLS_NONE;
fw_param = (fw_mnem | FW_PARAMS_PARAM_YZ_V(qe->cntxt_id));
pf = adap->pf;
vf = 0;
break;
}
default:
err = -ENOTSUPP;
goto out;
}
err = t4_set_params(adap, adap->mbox, pf, vf, 1, &fw_param, &fw_class);
out:
return err;
}
static struct sched_class *t4_sched_queue_lookup(struct port_info *pi,
const unsigned int qid,
int *index)
{
struct sched_table *s = pi->sched_tbl;
struct sched_class *e, *end;
struct sched_class *found = NULL;
int i;
end = &s->tab[s->sched_size];
for (e = &s->tab[0]; e != end; ++e) {
struct sched_queue_entry *qe;
i = 0;
if (e->state == SCHED_STATE_UNUSED)
continue;
list_for_each_entry(qe, &e->queue_list, list) {
if (qe->cntxt_id == qid) {
found = e;
if (index)
*index = i;
break;
}
i++;
}
if (found)
break;
}
return found;
}
static int t4_sched_queue_unbind(struct port_info *pi, struct ch_sched_queue *p)
{
struct adapter *adap = pi->adapter;
struct sched_class *e;
struct sched_queue_entry *qe = NULL;
struct sge_eth_txq *txq;
unsigned int qid;
int index = -1;
int err = 0;
if (p->queue < 0 || p->queue >= pi->nqsets)
return -ERANGE;
txq = &adap->sge.ethtxq[pi->first_qset + p->queue];
qid = txq->q.cntxt_id;
e = t4_sched_queue_lookup(pi, qid, &index);
if (e && index >= 0) {
int i = 0;
spin_lock(&e->lock);
list_for_each_entry(qe, &e->queue_list, list) {
if (i == index)
break;
i++;
}
err = t4_sched_bind_unbind_op(pi, (void *)qe, SCHED_QUEUE,
false);
if (err) {
spin_unlock(&e->lock);
goto out;
}
list_del(&qe->list);
t4_free_mem(qe);
if (atomic_dec_and_test(&e->refcnt)) {
e->state = SCHED_STATE_UNUSED;
memset(&e->info, 0, sizeof(e->info));
}
spin_unlock(&e->lock);
}
out:
return err;
}
static int t4_sched_queue_bind(struct port_info *pi, struct ch_sched_queue *p)
{
struct adapter *adap = pi->adapter;
struct sched_table *s = pi->sched_tbl;
struct sched_class *e;
struct sched_queue_entry *qe = NULL;
struct sge_eth_txq *txq;
unsigned int qid;
int err = 0;
if (p->queue < 0 || p->queue >= pi->nqsets)
return -ERANGE;
qe = t4_alloc_mem(sizeof(struct sched_queue_entry));
if (!qe)
return -ENOMEM;
txq = &adap->sge.ethtxq[pi->first_qset + p->queue];
qid = txq->q.cntxt_id;
err = t4_sched_queue_unbind(pi, p);
if (err) {
t4_free_mem(qe);
goto out;
}
memset(qe, 0, sizeof(*qe));
qe->cntxt_id = qid;
memcpy(&qe->param, p, sizeof(qe->param));
e = &s->tab[qe->param.class];
spin_lock(&e->lock);
err = t4_sched_bind_unbind_op(pi, (void *)qe, SCHED_QUEUE, true);
if (err) {
t4_free_mem(qe);
spin_unlock(&e->lock);
goto out;
}
list_add_tail(&qe->list, &e->queue_list);
atomic_inc(&e->refcnt);
spin_unlock(&e->lock);
out:
return err;
}
static void t4_sched_class_unbind_all(struct port_info *pi,
struct sched_class *e,
enum sched_bind_type type)
{
if (!e)
return;
switch (type) {
case SCHED_QUEUE: {
struct sched_queue_entry *qe;
list_for_each_entry(qe, &e->queue_list, list)
t4_sched_queue_unbind(pi, &qe->param);
break;
}
default:
break;
}
}
static int t4_sched_class_bind_unbind_op(struct port_info *pi, void *arg,
enum sched_bind_type type, bool bind)
{
int err = 0;
if (!arg)
return -EINVAL;
switch (type) {
case SCHED_QUEUE: {
struct ch_sched_queue *qe = (struct ch_sched_queue *)arg;
if (bind)
err = t4_sched_queue_bind(pi, qe);
else
err = t4_sched_queue_unbind(pi, qe);
break;
}
default:
err = -ENOTSUPP;
break;
}
return err;
}
int cxgb4_sched_class_bind(struct net_device *dev, void *arg,
enum sched_bind_type type)
{
struct port_info *pi = netdev2pinfo(dev);
struct sched_table *s;
int err = 0;
u8 class_id;
if (!can_sched(dev))
return -ENOTSUPP;
if (!arg)
return -EINVAL;
switch (type) {
case SCHED_QUEUE: {
struct ch_sched_queue *qe = (struct ch_sched_queue *)arg;
class_id = qe->class;
break;
}
default:
return -ENOTSUPP;
}
if (!valid_class_id(dev, class_id))
return -EINVAL;
if (class_id == SCHED_CLS_NONE)
return -ENOTSUPP;
s = pi->sched_tbl;
write_lock(&s->rw_lock);
err = t4_sched_class_bind_unbind_op(pi, arg, type, true);
write_unlock(&s->rw_lock);
return err;
}
int cxgb4_sched_class_unbind(struct net_device *dev, void *arg,
enum sched_bind_type type)
{
struct port_info *pi = netdev2pinfo(dev);
struct sched_table *s;
int err = 0;
u8 class_id;
if (!can_sched(dev))
return -ENOTSUPP;
if (!arg)
return -EINVAL;
switch (type) {
case SCHED_QUEUE: {
struct ch_sched_queue *qe = (struct ch_sched_queue *)arg;
class_id = qe->class;
break;
}
default:
return -ENOTSUPP;
}
if (!valid_class_id(dev, class_id))
return -EINVAL;
s = pi->sched_tbl;
write_lock(&s->rw_lock);
err = t4_sched_class_bind_unbind_op(pi, arg, type, false);
write_unlock(&s->rw_lock);
return err;
}
static struct sched_class *t4_sched_class_lookup(struct port_info *pi,
const struct ch_sched_params *p)
{
struct sched_table *s = pi->sched_tbl;
struct sched_class *e, *end;
struct sched_class *found = NULL;
if (!p) {
end = &s->tab[s->sched_size];
for (e = &s->tab[0]; e != end; ++e) {
if (e->state == SCHED_STATE_UNUSED) {
found = e;
break;
}
}
} else {
struct ch_sched_params info;
struct ch_sched_params tp;
memcpy(&tp, p, sizeof(tp));
tp.u.params.class = SCHED_CLS_NONE;
end = &s->tab[s->sched_size];
for (e = &s->tab[0]; e != end; ++e) {
if (e->state == SCHED_STATE_UNUSED)
continue;
memcpy(&info, &e->info, sizeof(info));
info.u.params.class = SCHED_CLS_NONE;
if ((info.type == tp.type) &&
(!memcmp(&info.u.params, &tp.u.params,
sizeof(info.u.params)))) {
found = e;
break;
}
}
}
return found;
}
static struct sched_class *t4_sched_class_alloc(struct port_info *pi,
struct ch_sched_params *p)
{
struct sched_table *s = pi->sched_tbl;
struct sched_class *e;
u8 class_id;
int err;
if (!p)
return NULL;
class_id = p->u.params.class;
if (class_id != SCHED_CLS_NONE)
return NULL;
write_lock(&s->rw_lock);
e = t4_sched_class_lookup(pi, p);
if (!e) {
struct ch_sched_params np;
e = t4_sched_class_lookup(pi, NULL);
if (!e)
goto out;
memcpy(&np, p, sizeof(np));
np.u.params.class = e->idx;
spin_lock(&e->lock);
err = t4_sched_class_fw_cmd(pi, &np, SCHED_FW_OP_ADD);
if (err) {
spin_unlock(&e->lock);
e = NULL;
goto out;
}
memcpy(&e->info, &np, sizeof(e->info));
atomic_set(&e->refcnt, 0);
e->state = SCHED_STATE_ACTIVE;
spin_unlock(&e->lock);
}
out:
write_unlock(&s->rw_lock);
return e;
}
struct sched_class *cxgb4_sched_class_alloc(struct net_device *dev,
struct ch_sched_params *p)
{
struct port_info *pi = netdev2pinfo(dev);
u8 class_id;
if (!can_sched(dev))
return NULL;
class_id = p->u.params.class;
if (!valid_class_id(dev, class_id))
return NULL;
return t4_sched_class_alloc(pi, p);
}
static void t4_sched_class_free(struct port_info *pi, struct sched_class *e)
{
t4_sched_class_unbind_all(pi, e, SCHED_QUEUE);
}
struct sched_table *t4_init_sched(unsigned int sched_size)
{
struct sched_table *s;
unsigned int i;
s = t4_alloc_mem(sizeof(*s) + sched_size * sizeof(struct sched_class));
if (!s)
return NULL;
s->sched_size = sched_size;
rwlock_init(&s->rw_lock);
for (i = 0; i < s->sched_size; i++) {
memset(&s->tab[i], 0, sizeof(struct sched_class));
s->tab[i].idx = i;
s->tab[i].state = SCHED_STATE_UNUSED;
INIT_LIST_HEAD(&s->tab[i].queue_list);
spin_lock_init(&s->tab[i].lock);
atomic_set(&s->tab[i].refcnt, 0);
}
return s;
}
void t4_cleanup_sched(struct adapter *adap)
{
struct sched_table *s;
unsigned int i;
for_each_port(adap, i) {
struct port_info *pi = netdev2pinfo(adap->port[i]);
s = pi->sched_tbl;
for (i = 0; i < s->sched_size; i++) {
struct sched_class *e;
write_lock(&s->rw_lock);
e = &s->tab[i];
if (e->state == SCHED_STATE_ACTIVE)
t4_sched_class_free(pi, e);
write_unlock(&s->rw_lock);
}
t4_free_mem(s);
}
}
