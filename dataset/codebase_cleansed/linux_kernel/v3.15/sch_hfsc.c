static void
eltree_insert(struct hfsc_class *cl)
{
struct rb_node **p = &cl->sched->eligible.rb_node;
struct rb_node *parent = NULL;
struct hfsc_class *cl1;
while (*p != NULL) {
parent = *p;
cl1 = rb_entry(parent, struct hfsc_class, el_node);
if (cl->cl_e >= cl1->cl_e)
p = &parent->rb_right;
else
p = &parent->rb_left;
}
rb_link_node(&cl->el_node, parent, p);
rb_insert_color(&cl->el_node, &cl->sched->eligible);
}
static inline void
eltree_remove(struct hfsc_class *cl)
{
rb_erase(&cl->el_node, &cl->sched->eligible);
}
static inline void
eltree_update(struct hfsc_class *cl)
{
eltree_remove(cl);
eltree_insert(cl);
}
static inline struct hfsc_class *
eltree_get_mindl(struct hfsc_sched *q, u64 cur_time)
{
struct hfsc_class *p, *cl = NULL;
struct rb_node *n;
for (n = rb_first(&q->eligible); n != NULL; n = rb_next(n)) {
p = rb_entry(n, struct hfsc_class, el_node);
if (p->cl_e > cur_time)
break;
if (cl == NULL || p->cl_d < cl->cl_d)
cl = p;
}
return cl;
}
static inline struct hfsc_class *
eltree_get_minel(struct hfsc_sched *q)
{
struct rb_node *n;
n = rb_first(&q->eligible);
if (n == NULL)
return NULL;
return rb_entry(n, struct hfsc_class, el_node);
}
static void
vttree_insert(struct hfsc_class *cl)
{
struct rb_node **p = &cl->cl_parent->vt_tree.rb_node;
struct rb_node *parent = NULL;
struct hfsc_class *cl1;
while (*p != NULL) {
parent = *p;
cl1 = rb_entry(parent, struct hfsc_class, vt_node);
if (cl->cl_vt >= cl1->cl_vt)
p = &parent->rb_right;
else
p = &parent->rb_left;
}
rb_link_node(&cl->vt_node, parent, p);
rb_insert_color(&cl->vt_node, &cl->cl_parent->vt_tree);
}
static inline void
vttree_remove(struct hfsc_class *cl)
{
rb_erase(&cl->vt_node, &cl->cl_parent->vt_tree);
}
static inline void
vttree_update(struct hfsc_class *cl)
{
vttree_remove(cl);
vttree_insert(cl);
}
static inline struct hfsc_class *
vttree_firstfit(struct hfsc_class *cl, u64 cur_time)
{
struct hfsc_class *p;
struct rb_node *n;
for (n = rb_first(&cl->vt_tree); n != NULL; n = rb_next(n)) {
p = rb_entry(n, struct hfsc_class, vt_node);
if (p->cl_f <= cur_time)
return p;
}
return NULL;
}
static struct hfsc_class *
vttree_get_minvt(struct hfsc_class *cl, u64 cur_time)
{
if (cl->cl_cfmin > cur_time)
return NULL;
while (cl->level > 0) {
cl = vttree_firstfit(cl, cur_time);
if (cl == NULL)
return NULL;
if (cl->cl_parent->cl_cvtmin < cl->cl_vt)
cl->cl_parent->cl_cvtmin = cl->cl_vt;
}
return cl;
}
static void
cftree_insert(struct hfsc_class *cl)
{
struct rb_node **p = &cl->cl_parent->cf_tree.rb_node;
struct rb_node *parent = NULL;
struct hfsc_class *cl1;
while (*p != NULL) {
parent = *p;
cl1 = rb_entry(parent, struct hfsc_class, cf_node);
if (cl->cl_f >= cl1->cl_f)
p = &parent->rb_right;
else
p = &parent->rb_left;
}
rb_link_node(&cl->cf_node, parent, p);
rb_insert_color(&cl->cf_node, &cl->cl_parent->cf_tree);
}
static inline void
cftree_remove(struct hfsc_class *cl)
{
rb_erase(&cl->cf_node, &cl->cl_parent->cf_tree);
}
static inline void
cftree_update(struct hfsc_class *cl)
{
cftree_remove(cl);
cftree_insert(cl);
}
static inline u64
seg_x2y(u64 x, u64 sm)
{
u64 y;
y = (x >> SM_SHIFT) * sm + (((x & SM_MASK) * sm) >> SM_SHIFT);
return y;
}
static inline u64
seg_y2x(u64 y, u64 ism)
{
u64 x;
if (y == 0)
x = 0;
else if (ism == HT_INFINITY)
x = HT_INFINITY;
else {
x = (y >> ISM_SHIFT) * ism
+ (((y & ISM_MASK) * ism) >> ISM_SHIFT);
}
return x;
}
static u64
m2sm(u32 m)
{
u64 sm;
sm = ((u64)m << SM_SHIFT);
sm += PSCHED_TICKS_PER_SEC - 1;
do_div(sm, PSCHED_TICKS_PER_SEC);
return sm;
}
static u64
m2ism(u32 m)
{
u64 ism;
if (m == 0)
ism = HT_INFINITY;
else {
ism = ((u64)PSCHED_TICKS_PER_SEC << ISM_SHIFT);
ism += m - 1;
do_div(ism, m);
}
return ism;
}
static u64
d2dx(u32 d)
{
u64 dx;
dx = ((u64)d * PSCHED_TICKS_PER_SEC);
dx += USEC_PER_SEC - 1;
do_div(dx, USEC_PER_SEC);
return dx;
}
static u32
sm2m(u64 sm)
{
u64 m;
m = (sm * PSCHED_TICKS_PER_SEC) >> SM_SHIFT;
return (u32)m;
}
static u32
dx2d(u64 dx)
{
u64 d;
d = dx * USEC_PER_SEC;
do_div(d, PSCHED_TICKS_PER_SEC);
return (u32)d;
}
static void
sc2isc(struct tc_service_curve *sc, struct internal_sc *isc)
{
isc->sm1 = m2sm(sc->m1);
isc->ism1 = m2ism(sc->m1);
isc->dx = d2dx(sc->d);
isc->dy = seg_x2y(isc->dx, isc->sm1);
isc->sm2 = m2sm(sc->m2);
isc->ism2 = m2ism(sc->m2);
}
static void
rtsc_init(struct runtime_sc *rtsc, struct internal_sc *isc, u64 x, u64 y)
{
rtsc->x = x;
rtsc->y = y;
rtsc->sm1 = isc->sm1;
rtsc->ism1 = isc->ism1;
rtsc->dx = isc->dx;
rtsc->dy = isc->dy;
rtsc->sm2 = isc->sm2;
rtsc->ism2 = isc->ism2;
}
static u64
rtsc_y2x(struct runtime_sc *rtsc, u64 y)
{
u64 x;
if (y < rtsc->y)
x = rtsc->x;
else if (y <= rtsc->y + rtsc->dy) {
if (rtsc->dy == 0)
x = rtsc->x + rtsc->dx;
else
x = rtsc->x + seg_y2x(y - rtsc->y, rtsc->ism1);
} else {
x = rtsc->x + rtsc->dx
+ seg_y2x(y - rtsc->y - rtsc->dy, rtsc->ism2);
}
return x;
}
static u64
rtsc_x2y(struct runtime_sc *rtsc, u64 x)
{
u64 y;
if (x <= rtsc->x)
y = rtsc->y;
else if (x <= rtsc->x + rtsc->dx)
y = rtsc->y + seg_x2y(x - rtsc->x, rtsc->sm1);
else
y = rtsc->y + rtsc->dy
+ seg_x2y(x - rtsc->x - rtsc->dx, rtsc->sm2);
return y;
}
static void
rtsc_min(struct runtime_sc *rtsc, struct internal_sc *isc, u64 x, u64 y)
{
u64 y1, y2, dx, dy;
u32 dsm;
if (isc->sm1 <= isc->sm2) {
y1 = rtsc_x2y(rtsc, x);
if (y1 < y)
return;
rtsc->x = x;
rtsc->y = y;
return;
}
y1 = rtsc_x2y(rtsc, x);
if (y1 <= y) {
return;
}
y2 = rtsc_x2y(rtsc, x + isc->dx);
if (y2 >= y + isc->dy) {
rtsc->x = x;
rtsc->y = y;
rtsc->dx = isc->dx;
rtsc->dy = isc->dy;
return;
}
dx = (y1 - y) << SM_SHIFT;
dsm = isc->sm1 - isc->sm2;
do_div(dx, dsm);
if (rtsc->x + rtsc->dx > x)
dx += rtsc->x + rtsc->dx - x;
dy = seg_x2y(dx, isc->sm1);
rtsc->x = x;
rtsc->y = y;
rtsc->dx = dx;
rtsc->dy = dy;
}
static void
init_ed(struct hfsc_class *cl, unsigned int next_len)
{
u64 cur_time = psched_get_time();
rtsc_min(&cl->cl_deadline, &cl->cl_rsc, cur_time, cl->cl_cumul);
cl->cl_eligible = cl->cl_deadline;
if (cl->cl_rsc.sm1 <= cl->cl_rsc.sm2) {
cl->cl_eligible.dx = 0;
cl->cl_eligible.dy = 0;
}
cl->cl_e = rtsc_y2x(&cl->cl_eligible, cl->cl_cumul);
cl->cl_d = rtsc_y2x(&cl->cl_deadline, cl->cl_cumul + next_len);
eltree_insert(cl);
}
static void
update_ed(struct hfsc_class *cl, unsigned int next_len)
{
cl->cl_e = rtsc_y2x(&cl->cl_eligible, cl->cl_cumul);
cl->cl_d = rtsc_y2x(&cl->cl_deadline, cl->cl_cumul + next_len);
eltree_update(cl);
}
static inline void
update_d(struct hfsc_class *cl, unsigned int next_len)
{
cl->cl_d = rtsc_y2x(&cl->cl_deadline, cl->cl_cumul + next_len);
}
static inline void
update_cfmin(struct hfsc_class *cl)
{
struct rb_node *n = rb_first(&cl->cf_tree);
struct hfsc_class *p;
if (n == NULL) {
cl->cl_cfmin = 0;
return;
}
p = rb_entry(n, struct hfsc_class, cf_node);
cl->cl_cfmin = p->cl_f;
}
static void
init_vf(struct hfsc_class *cl, unsigned int len)
{
struct hfsc_class *max_cl;
struct rb_node *n;
u64 vt, f, cur_time;
int go_active;
cur_time = 0;
go_active = 1;
for (; cl->cl_parent != NULL; cl = cl->cl_parent) {
if (go_active && cl->cl_nactive++ == 0)
go_active = 1;
else
go_active = 0;
if (go_active) {
n = rb_last(&cl->cl_parent->vt_tree);
if (n != NULL) {
max_cl = rb_entry(n, struct hfsc_class, vt_node);
vt = max_cl->cl_vt;
if (cl->cl_parent->cl_cvtmin != 0)
vt = (cl->cl_parent->cl_cvtmin + vt)/2;
if (cl->cl_parent->cl_vtperiod !=
cl->cl_parentperiod || vt > cl->cl_vt)
cl->cl_vt = vt;
} else {
vt = cl->cl_parent->cl_cvtmax;
cl->cl_parent->cl_cvtoff += vt;
cl->cl_parent->cl_cvtmax = 0;
cl->cl_parent->cl_cvtmin = 0;
cl->cl_vt = 0;
}
cl->cl_vtoff = cl->cl_parent->cl_cvtoff -
cl->cl_pcvtoff;
vt = cl->cl_vt + cl->cl_vtoff;
rtsc_min(&cl->cl_virtual, &cl->cl_fsc, vt,
cl->cl_total);
if (cl->cl_virtual.x == vt) {
cl->cl_virtual.x -= cl->cl_vtoff;
cl->cl_vtoff = 0;
}
cl->cl_vtadj = 0;
cl->cl_vtperiod++;
cl->cl_parentperiod = cl->cl_parent->cl_vtperiod;
if (cl->cl_parent->cl_nactive == 0)
cl->cl_parentperiod++;
cl->cl_f = 0;
vttree_insert(cl);
cftree_insert(cl);
if (cl->cl_flags & HFSC_USC) {
if (cur_time == 0)
cur_time = psched_get_time();
rtsc_min(&cl->cl_ulimit, &cl->cl_usc, cur_time,
cl->cl_total);
cl->cl_myf = rtsc_y2x(&cl->cl_ulimit,
cl->cl_total);
cl->cl_myfadj = 0;
}
}
f = max(cl->cl_myf, cl->cl_cfmin);
if (f != cl->cl_f) {
cl->cl_f = f;
cftree_update(cl);
}
update_cfmin(cl->cl_parent);
}
}
static void
update_vf(struct hfsc_class *cl, unsigned int len, u64 cur_time)
{
u64 f;
int go_passive = 0;
if (cl->qdisc->q.qlen == 0 && cl->cl_flags & HFSC_FSC)
go_passive = 1;
for (; cl->cl_parent != NULL; cl = cl->cl_parent) {
cl->cl_total += len;
if (!(cl->cl_flags & HFSC_FSC) || cl->cl_nactive == 0)
continue;
if (go_passive && --cl->cl_nactive == 0)
go_passive = 1;
else
go_passive = 0;
if (go_passive) {
if (cl->cl_vt > cl->cl_parent->cl_cvtmax)
cl->cl_parent->cl_cvtmax = cl->cl_vt;
vttree_remove(cl);
cftree_remove(cl);
update_cfmin(cl->cl_parent);
continue;
}
cl->cl_vt = rtsc_y2x(&cl->cl_virtual, cl->cl_total)
- cl->cl_vtoff + cl->cl_vtadj;
if (cl->cl_vt < cl->cl_parent->cl_cvtmin) {
cl->cl_vtadj += cl->cl_parent->cl_cvtmin - cl->cl_vt;
cl->cl_vt = cl->cl_parent->cl_cvtmin;
}
vttree_update(cl);
if (cl->cl_flags & HFSC_USC) {
cl->cl_myf = cl->cl_myfadj + rtsc_y2x(&cl->cl_ulimit,
cl->cl_total);
#if 0
myf_bound = cur_time - PSCHED_JIFFIE2US(1);
if (cl->cl_myf < myf_bound) {
delta = cur_time - cl->cl_myf;
cl->cl_myfadj += delta;
cl->cl_myf += delta;
}
#endif
}
f = max(cl->cl_myf, cl->cl_cfmin);
if (f != cl->cl_f) {
cl->cl_f = f;
cftree_update(cl);
update_cfmin(cl->cl_parent);
}
}
}
static void
set_active(struct hfsc_class *cl, unsigned int len)
{
if (cl->cl_flags & HFSC_RSC)
init_ed(cl, len);
if (cl->cl_flags & HFSC_FSC)
init_vf(cl, len);
list_add_tail(&cl->dlist, &cl->sched->droplist);
}
static void
set_passive(struct hfsc_class *cl)
{
if (cl->cl_flags & HFSC_RSC)
eltree_remove(cl);
list_del(&cl->dlist);
}
static unsigned int
qdisc_peek_len(struct Qdisc *sch)
{
struct sk_buff *skb;
unsigned int len;
skb = sch->ops->peek(sch);
if (skb == NULL) {
qdisc_warn_nonwc("qdisc_peek_len", sch);
return 0;
}
len = qdisc_pkt_len(skb);
return len;
}
static void
hfsc_purge_queue(struct Qdisc *sch, struct hfsc_class *cl)
{
unsigned int len = cl->qdisc->q.qlen;
qdisc_reset(cl->qdisc);
qdisc_tree_decrease_qlen(cl->qdisc, len);
}
static void
hfsc_adjust_levels(struct hfsc_class *cl)
{
struct hfsc_class *p;
unsigned int level;
do {
level = 0;
list_for_each_entry(p, &cl->children, siblings) {
if (p->level >= level)
level = p->level + 1;
}
cl->level = level;
} while ((cl = cl->cl_parent) != NULL);
}
static inline struct hfsc_class *
hfsc_find_class(u32 classid, struct Qdisc *sch)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct Qdisc_class_common *clc;
clc = qdisc_class_find(&q->clhash, classid);
if (clc == NULL)
return NULL;
return container_of(clc, struct hfsc_class, cl_common);
}
static void
hfsc_change_rsc(struct hfsc_class *cl, struct tc_service_curve *rsc,
u64 cur_time)
{
sc2isc(rsc, &cl->cl_rsc);
rtsc_init(&cl->cl_deadline, &cl->cl_rsc, cur_time, cl->cl_cumul);
cl->cl_eligible = cl->cl_deadline;
if (cl->cl_rsc.sm1 <= cl->cl_rsc.sm2) {
cl->cl_eligible.dx = 0;
cl->cl_eligible.dy = 0;
}
cl->cl_flags |= HFSC_RSC;
}
static void
hfsc_change_fsc(struct hfsc_class *cl, struct tc_service_curve *fsc)
{
sc2isc(fsc, &cl->cl_fsc);
rtsc_init(&cl->cl_virtual, &cl->cl_fsc, cl->cl_vt, cl->cl_total);
cl->cl_flags |= HFSC_FSC;
}
static void
hfsc_change_usc(struct hfsc_class *cl, struct tc_service_curve *usc,
u64 cur_time)
{
sc2isc(usc, &cl->cl_usc);
rtsc_init(&cl->cl_ulimit, &cl->cl_usc, cur_time, cl->cl_total);
cl->cl_flags |= HFSC_USC;
}
static int
hfsc_change_class(struct Qdisc *sch, u32 classid, u32 parentid,
struct nlattr **tca, unsigned long *arg)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct hfsc_class *cl = (struct hfsc_class *)*arg;
struct hfsc_class *parent = NULL;
struct nlattr *opt = tca[TCA_OPTIONS];
struct nlattr *tb[TCA_HFSC_MAX + 1];
struct tc_service_curve *rsc = NULL, *fsc = NULL, *usc = NULL;
u64 cur_time;
int err;
if (opt == NULL)
return -EINVAL;
err = nla_parse_nested(tb, TCA_HFSC_MAX, opt, hfsc_policy);
if (err < 0)
return err;
if (tb[TCA_HFSC_RSC]) {
rsc = nla_data(tb[TCA_HFSC_RSC]);
if (rsc->m1 == 0 && rsc->m2 == 0)
rsc = NULL;
}
if (tb[TCA_HFSC_FSC]) {
fsc = nla_data(tb[TCA_HFSC_FSC]);
if (fsc->m1 == 0 && fsc->m2 == 0)
fsc = NULL;
}
if (tb[TCA_HFSC_USC]) {
usc = nla_data(tb[TCA_HFSC_USC]);
if (usc->m1 == 0 && usc->m2 == 0)
usc = NULL;
}
if (cl != NULL) {
if (parentid) {
if (cl->cl_parent &&
cl->cl_parent->cl_common.classid != parentid)
return -EINVAL;
if (cl->cl_parent == NULL && parentid != TC_H_ROOT)
return -EINVAL;
}
cur_time = psched_get_time();
if (tca[TCA_RATE]) {
err = gen_replace_estimator(&cl->bstats, &cl->rate_est,
qdisc_root_sleeping_lock(sch),
tca[TCA_RATE]);
if (err)
return err;
}
sch_tree_lock(sch);
if (rsc != NULL)
hfsc_change_rsc(cl, rsc, cur_time);
if (fsc != NULL)
hfsc_change_fsc(cl, fsc);
if (usc != NULL)
hfsc_change_usc(cl, usc, cur_time);
if (cl->qdisc->q.qlen != 0) {
if (cl->cl_flags & HFSC_RSC)
update_ed(cl, qdisc_peek_len(cl->qdisc));
if (cl->cl_flags & HFSC_FSC)
update_vf(cl, 0, cur_time);
}
sch_tree_unlock(sch);
return 0;
}
if (parentid == TC_H_ROOT)
return -EEXIST;
parent = &q->root;
if (parentid) {
parent = hfsc_find_class(parentid, sch);
if (parent == NULL)
return -ENOENT;
}
if (classid == 0 || TC_H_MAJ(classid ^ sch->handle) != 0)
return -EINVAL;
if (hfsc_find_class(classid, sch))
return -EEXIST;
if (rsc == NULL && fsc == NULL)
return -EINVAL;
cl = kzalloc(sizeof(struct hfsc_class), GFP_KERNEL);
if (cl == NULL)
return -ENOBUFS;
if (tca[TCA_RATE]) {
err = gen_new_estimator(&cl->bstats, &cl->rate_est,
qdisc_root_sleeping_lock(sch),
tca[TCA_RATE]);
if (err) {
kfree(cl);
return err;
}
}
if (rsc != NULL)
hfsc_change_rsc(cl, rsc, 0);
if (fsc != NULL)
hfsc_change_fsc(cl, fsc);
if (usc != NULL)
hfsc_change_usc(cl, usc, 0);
cl->cl_common.classid = classid;
cl->refcnt = 1;
cl->sched = q;
cl->cl_parent = parent;
cl->qdisc = qdisc_create_dflt(sch->dev_queue,
&pfifo_qdisc_ops, classid);
if (cl->qdisc == NULL)
cl->qdisc = &noop_qdisc;
INIT_LIST_HEAD(&cl->children);
cl->vt_tree = RB_ROOT;
cl->cf_tree = RB_ROOT;
sch_tree_lock(sch);
qdisc_class_hash_insert(&q->clhash, &cl->cl_common);
list_add_tail(&cl->siblings, &parent->children);
if (parent->level == 0)
hfsc_purge_queue(sch, parent);
hfsc_adjust_levels(parent);
cl->cl_pcvtoff = parent->cl_cvtoff;
sch_tree_unlock(sch);
qdisc_class_hash_grow(sch, &q->clhash);
*arg = (unsigned long)cl;
return 0;
}
static void
hfsc_destroy_class(struct Qdisc *sch, struct hfsc_class *cl)
{
struct hfsc_sched *q = qdisc_priv(sch);
tcf_destroy_chain(&cl->filter_list);
qdisc_destroy(cl->qdisc);
gen_kill_estimator(&cl->bstats, &cl->rate_est);
if (cl != &q->root)
kfree(cl);
}
static int
hfsc_delete_class(struct Qdisc *sch, unsigned long arg)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct hfsc_class *cl = (struct hfsc_class *)arg;
if (cl->level > 0 || cl->filter_cnt > 0 || cl == &q->root)
return -EBUSY;
sch_tree_lock(sch);
list_del(&cl->siblings);
hfsc_adjust_levels(cl->cl_parent);
hfsc_purge_queue(sch, cl);
qdisc_class_hash_remove(&q->clhash, &cl->cl_common);
BUG_ON(--cl->refcnt == 0);
sch_tree_unlock(sch);
return 0;
}
static struct hfsc_class *
hfsc_classify(struct sk_buff *skb, struct Qdisc *sch, int *qerr)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct hfsc_class *head, *cl;
struct tcf_result res;
struct tcf_proto *tcf;
int result;
if (TC_H_MAJ(skb->priority ^ sch->handle) == 0 &&
(cl = hfsc_find_class(skb->priority, sch)) != NULL)
if (cl->level == 0)
return cl;
*qerr = NET_XMIT_SUCCESS | __NET_XMIT_BYPASS;
head = &q->root;
tcf = q->root.filter_list;
while (tcf && (result = tc_classify(skb, tcf, &res)) >= 0) {
#ifdef CONFIG_NET_CLS_ACT
switch (result) {
case TC_ACT_QUEUED:
case TC_ACT_STOLEN:
*qerr = NET_XMIT_SUCCESS | __NET_XMIT_STOLEN;
case TC_ACT_SHOT:
return NULL;
}
#endif
cl = (struct hfsc_class *)res.class;
if (!cl) {
cl = hfsc_find_class(res.classid, sch);
if (!cl)
break;
if (cl->level >= head->level)
break;
}
if (cl->level == 0)
return cl;
tcf = cl->filter_list;
head = cl;
}
cl = hfsc_find_class(TC_H_MAKE(TC_H_MAJ(sch->handle), q->defcls), sch);
if (cl == NULL || cl->level > 0)
return NULL;
return cl;
}
static int
hfsc_graft_class(struct Qdisc *sch, unsigned long arg, struct Qdisc *new,
struct Qdisc **old)
{
struct hfsc_class *cl = (struct hfsc_class *)arg;
if (cl->level > 0)
return -EINVAL;
if (new == NULL) {
new = qdisc_create_dflt(sch->dev_queue, &pfifo_qdisc_ops,
cl->cl_common.classid);
if (new == NULL)
new = &noop_qdisc;
}
sch_tree_lock(sch);
hfsc_purge_queue(sch, cl);
*old = cl->qdisc;
cl->qdisc = new;
sch_tree_unlock(sch);
return 0;
}
static struct Qdisc *
hfsc_class_leaf(struct Qdisc *sch, unsigned long arg)
{
struct hfsc_class *cl = (struct hfsc_class *)arg;
if (cl->level == 0)
return cl->qdisc;
return NULL;
}
static void
hfsc_qlen_notify(struct Qdisc *sch, unsigned long arg)
{
struct hfsc_class *cl = (struct hfsc_class *)arg;
if (cl->qdisc->q.qlen == 0) {
update_vf(cl, 0, 0);
set_passive(cl);
}
}
static unsigned long
hfsc_get_class(struct Qdisc *sch, u32 classid)
{
struct hfsc_class *cl = hfsc_find_class(classid, sch);
if (cl != NULL)
cl->refcnt++;
return (unsigned long)cl;
}
static void
hfsc_put_class(struct Qdisc *sch, unsigned long arg)
{
struct hfsc_class *cl = (struct hfsc_class *)arg;
if (--cl->refcnt == 0)
hfsc_destroy_class(sch, cl);
}
static unsigned long
hfsc_bind_tcf(struct Qdisc *sch, unsigned long parent, u32 classid)
{
struct hfsc_class *p = (struct hfsc_class *)parent;
struct hfsc_class *cl = hfsc_find_class(classid, sch);
if (cl != NULL) {
if (p != NULL && p->level <= cl->level)
return 0;
cl->filter_cnt++;
}
return (unsigned long)cl;
}
static void
hfsc_unbind_tcf(struct Qdisc *sch, unsigned long arg)
{
struct hfsc_class *cl = (struct hfsc_class *)arg;
cl->filter_cnt--;
}
static struct tcf_proto **
hfsc_tcf_chain(struct Qdisc *sch, unsigned long arg)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct hfsc_class *cl = (struct hfsc_class *)arg;
if (cl == NULL)
cl = &q->root;
return &cl->filter_list;
}
static int
hfsc_dump_sc(struct sk_buff *skb, int attr, struct internal_sc *sc)
{
struct tc_service_curve tsc;
tsc.m1 = sm2m(sc->sm1);
tsc.d = dx2d(sc->dx);
tsc.m2 = sm2m(sc->sm2);
if (nla_put(skb, attr, sizeof(tsc), &tsc))
goto nla_put_failure;
return skb->len;
nla_put_failure:
return -1;
}
static int
hfsc_dump_curves(struct sk_buff *skb, struct hfsc_class *cl)
{
if ((cl->cl_flags & HFSC_RSC) &&
(hfsc_dump_sc(skb, TCA_HFSC_RSC, &cl->cl_rsc) < 0))
goto nla_put_failure;
if ((cl->cl_flags & HFSC_FSC) &&
(hfsc_dump_sc(skb, TCA_HFSC_FSC, &cl->cl_fsc) < 0))
goto nla_put_failure;
if ((cl->cl_flags & HFSC_USC) &&
(hfsc_dump_sc(skb, TCA_HFSC_USC, &cl->cl_usc) < 0))
goto nla_put_failure;
return skb->len;
nla_put_failure:
return -1;
}
static int
hfsc_dump_class(struct Qdisc *sch, unsigned long arg, struct sk_buff *skb,
struct tcmsg *tcm)
{
struct hfsc_class *cl = (struct hfsc_class *)arg;
struct nlattr *nest;
tcm->tcm_parent = cl->cl_parent ? cl->cl_parent->cl_common.classid :
TC_H_ROOT;
tcm->tcm_handle = cl->cl_common.classid;
if (cl->level == 0)
tcm->tcm_info = cl->qdisc->handle;
nest = nla_nest_start(skb, TCA_OPTIONS);
if (nest == NULL)
goto nla_put_failure;
if (hfsc_dump_curves(skb, cl) < 0)
goto nla_put_failure;
return nla_nest_end(skb, nest);
nla_put_failure:
nla_nest_cancel(skb, nest);
return -EMSGSIZE;
}
static int
hfsc_dump_class_stats(struct Qdisc *sch, unsigned long arg,
struct gnet_dump *d)
{
struct hfsc_class *cl = (struct hfsc_class *)arg;
struct tc_hfsc_stats xstats;
cl->qstats.qlen = cl->qdisc->q.qlen;
cl->qstats.backlog = cl->qdisc->qstats.backlog;
xstats.level = cl->level;
xstats.period = cl->cl_vtperiod;
xstats.work = cl->cl_total;
xstats.rtwork = cl->cl_cumul;
if (gnet_stats_copy_basic(d, &cl->bstats) < 0 ||
gnet_stats_copy_rate_est(d, &cl->bstats, &cl->rate_est) < 0 ||
gnet_stats_copy_queue(d, &cl->qstats) < 0)
return -1;
return gnet_stats_copy_app(d, &xstats, sizeof(xstats));
}
static void
hfsc_walk(struct Qdisc *sch, struct qdisc_walker *arg)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct hfsc_class *cl;
unsigned int i;
if (arg->stop)
return;
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry(cl, &q->clhash.hash[i],
cl_common.hnode) {
if (arg->count < arg->skip) {
arg->count++;
continue;
}
if (arg->fn(sch, (unsigned long)cl, arg) < 0) {
arg->stop = 1;
return;
}
arg->count++;
}
}
}
static void
hfsc_schedule_watchdog(struct Qdisc *sch)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct hfsc_class *cl;
u64 next_time = 0;
cl = eltree_get_minel(q);
if (cl)
next_time = cl->cl_e;
if (q->root.cl_cfmin != 0) {
if (next_time == 0 || next_time > q->root.cl_cfmin)
next_time = q->root.cl_cfmin;
}
WARN_ON(next_time == 0);
qdisc_watchdog_schedule(&q->watchdog, next_time);
}
static int
hfsc_init_qdisc(struct Qdisc *sch, struct nlattr *opt)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct tc_hfsc_qopt *qopt;
int err;
if (opt == NULL || nla_len(opt) < sizeof(*qopt))
return -EINVAL;
qopt = nla_data(opt);
q->defcls = qopt->defcls;
err = qdisc_class_hash_init(&q->clhash);
if (err < 0)
return err;
q->eligible = RB_ROOT;
INIT_LIST_HEAD(&q->droplist);
q->root.cl_common.classid = sch->handle;
q->root.refcnt = 1;
q->root.sched = q;
q->root.qdisc = qdisc_create_dflt(sch->dev_queue, &pfifo_qdisc_ops,
sch->handle);
if (q->root.qdisc == NULL)
q->root.qdisc = &noop_qdisc;
INIT_LIST_HEAD(&q->root.children);
q->root.vt_tree = RB_ROOT;
q->root.cf_tree = RB_ROOT;
qdisc_class_hash_insert(&q->clhash, &q->root.cl_common);
qdisc_class_hash_grow(sch, &q->clhash);
qdisc_watchdog_init(&q->watchdog, sch);
return 0;
}
static int
hfsc_change_qdisc(struct Qdisc *sch, struct nlattr *opt)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct tc_hfsc_qopt *qopt;
if (opt == NULL || nla_len(opt) < sizeof(*qopt))
return -EINVAL;
qopt = nla_data(opt);
sch_tree_lock(sch);
q->defcls = qopt->defcls;
sch_tree_unlock(sch);
return 0;
}
static void
hfsc_reset_class(struct hfsc_class *cl)
{
cl->cl_total = 0;
cl->cl_cumul = 0;
cl->cl_d = 0;
cl->cl_e = 0;
cl->cl_vt = 0;
cl->cl_vtadj = 0;
cl->cl_vtoff = 0;
cl->cl_cvtmin = 0;
cl->cl_cvtmax = 0;
cl->cl_cvtoff = 0;
cl->cl_pcvtoff = 0;
cl->cl_vtperiod = 0;
cl->cl_parentperiod = 0;
cl->cl_f = 0;
cl->cl_myf = 0;
cl->cl_myfadj = 0;
cl->cl_cfmin = 0;
cl->cl_nactive = 0;
cl->vt_tree = RB_ROOT;
cl->cf_tree = RB_ROOT;
qdisc_reset(cl->qdisc);
if (cl->cl_flags & HFSC_RSC)
rtsc_init(&cl->cl_deadline, &cl->cl_rsc, 0, 0);
if (cl->cl_flags & HFSC_FSC)
rtsc_init(&cl->cl_virtual, &cl->cl_fsc, 0, 0);
if (cl->cl_flags & HFSC_USC)
rtsc_init(&cl->cl_ulimit, &cl->cl_usc, 0, 0);
}
static void
hfsc_reset_qdisc(struct Qdisc *sch)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct hfsc_class *cl;
unsigned int i;
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry(cl, &q->clhash.hash[i], cl_common.hnode)
hfsc_reset_class(cl);
}
q->eligible = RB_ROOT;
INIT_LIST_HEAD(&q->droplist);
qdisc_watchdog_cancel(&q->watchdog);
sch->q.qlen = 0;
}
static void
hfsc_destroy_qdisc(struct Qdisc *sch)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct hlist_node *next;
struct hfsc_class *cl;
unsigned int i;
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry(cl, &q->clhash.hash[i], cl_common.hnode)
tcf_destroy_chain(&cl->filter_list);
}
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry_safe(cl, next, &q->clhash.hash[i],
cl_common.hnode)
hfsc_destroy_class(sch, cl);
}
qdisc_class_hash_destroy(&q->clhash);
qdisc_watchdog_cancel(&q->watchdog);
}
static int
hfsc_dump_qdisc(struct Qdisc *sch, struct sk_buff *skb)
{
struct hfsc_sched *q = qdisc_priv(sch);
unsigned char *b = skb_tail_pointer(skb);
struct tc_hfsc_qopt qopt;
struct hfsc_class *cl;
unsigned int i;
sch->qstats.backlog = 0;
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry(cl, &q->clhash.hash[i], cl_common.hnode)
sch->qstats.backlog += cl->qdisc->qstats.backlog;
}
qopt.defcls = q->defcls;
if (nla_put(skb, TCA_OPTIONS, sizeof(qopt), &qopt))
goto nla_put_failure;
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int
hfsc_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
struct hfsc_class *cl;
int uninitialized_var(err);
cl = hfsc_classify(skb, sch, &err);
if (cl == NULL) {
if (err & __NET_XMIT_BYPASS)
sch->qstats.drops++;
kfree_skb(skb);
return err;
}
err = qdisc_enqueue(skb, cl->qdisc);
if (unlikely(err != NET_XMIT_SUCCESS)) {
if (net_xmit_drop_count(err)) {
cl->qstats.drops++;
sch->qstats.drops++;
}
return err;
}
if (cl->qdisc->q.qlen == 1)
set_active(cl, qdisc_pkt_len(skb));
sch->q.qlen++;
return NET_XMIT_SUCCESS;
}
static struct sk_buff *
hfsc_dequeue(struct Qdisc *sch)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct hfsc_class *cl;
struct sk_buff *skb;
u64 cur_time;
unsigned int next_len;
int realtime = 0;
if (sch->q.qlen == 0)
return NULL;
cur_time = psched_get_time();
cl = eltree_get_mindl(q, cur_time);
if (cl) {
realtime = 1;
} else {
cl = vttree_get_minvt(&q->root, cur_time);
if (cl == NULL) {
sch->qstats.overlimits++;
hfsc_schedule_watchdog(sch);
return NULL;
}
}
skb = qdisc_dequeue_peeked(cl->qdisc);
if (skb == NULL) {
qdisc_warn_nonwc("HFSC", cl->qdisc);
return NULL;
}
bstats_update(&cl->bstats, skb);
update_vf(cl, qdisc_pkt_len(skb), cur_time);
if (realtime)
cl->cl_cumul += qdisc_pkt_len(skb);
if (cl->qdisc->q.qlen != 0) {
if (cl->cl_flags & HFSC_RSC) {
next_len = qdisc_peek_len(cl->qdisc);
if (realtime)
update_ed(cl, next_len);
else
update_d(cl, next_len);
}
} else {
set_passive(cl);
}
qdisc_unthrottled(sch);
qdisc_bstats_update(sch, skb);
sch->q.qlen--;
return skb;
}
static unsigned int
hfsc_drop(struct Qdisc *sch)
{
struct hfsc_sched *q = qdisc_priv(sch);
struct hfsc_class *cl;
unsigned int len;
list_for_each_entry(cl, &q->droplist, dlist) {
if (cl->qdisc->ops->drop != NULL &&
(len = cl->qdisc->ops->drop(cl->qdisc)) > 0) {
if (cl->qdisc->q.qlen == 0) {
update_vf(cl, 0, 0);
set_passive(cl);
} else {
list_move_tail(&cl->dlist, &q->droplist);
}
cl->qstats.drops++;
sch->qstats.drops++;
sch->q.qlen--;
return len;
}
}
return 0;
}
static int __init
hfsc_init(void)
{
return register_qdisc(&hfsc_qdisc_ops);
}
static void __exit
hfsc_cleanup(void)
{
unregister_qdisc(&hfsc_qdisc_ops);
}
