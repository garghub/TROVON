static int bfq_gt(u64 a, u64 b)
{
return (s64)(a - b) > 0;
}
static struct bfq_entity *bfq_root_active_entity(struct rb_root *tree)
{
struct rb_node *node = tree->rb_node;
return rb_entry(node, struct bfq_entity, rb_node);
}
static unsigned int bfq_class_idx(struct bfq_entity *entity)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
return bfqq ? bfqq->ioprio_class - 1 :
BFQ_DEFAULT_GRP_CLASS - 1;
}
static bool bfq_update_next_in_service(struct bfq_sched_data *sd,
struct bfq_entity *new_entity)
{
struct bfq_entity *next_in_service = sd->next_in_service;
bool parent_sched_may_change = false;
if (new_entity && new_entity != sd->next_in_service) {
bool replace_next = true;
if (next_in_service) {
unsigned int new_entity_class_idx =
bfq_class_idx(new_entity);
struct bfq_service_tree *st =
sd->service_tree + new_entity_class_idx;
replace_next =
(new_entity_class_idx ==
bfq_class_idx(next_in_service)
&&
!bfq_gt(new_entity->start, st->vtime)
&&
bfq_gt(next_in_service->finish,
new_entity->finish))
||
new_entity_class_idx <
bfq_class_idx(next_in_service);
}
if (replace_next)
next_in_service = new_entity;
} else
next_in_service = bfq_lookup_next_entity(sd);
if (next_in_service) {
parent_sched_may_change = !sd->next_in_service ||
bfq_update_parent_budget(next_in_service);
}
sd->next_in_service = next_in_service;
if (!next_in_service)
return parent_sched_may_change;
return parent_sched_may_change;
}
struct bfq_group *bfq_bfqq_to_bfqg(struct bfq_queue *bfqq)
{
struct bfq_entity *group_entity = bfqq->entity.parent;
if (!group_entity)
group_entity = &bfqq->bfqd->root_group->entity;
return container_of(group_entity, struct bfq_group, entity);
}
static bool bfq_update_parent_budget(struct bfq_entity *next_in_service)
{
struct bfq_entity *bfqg_entity;
struct bfq_group *bfqg;
struct bfq_sched_data *group_sd;
bool ret = false;
group_sd = next_in_service->sched_data;
bfqg = container_of(group_sd, struct bfq_group, sched_data);
bfqg_entity = bfqg->my_entity;
if (bfqg_entity) {
if (bfqg_entity->budget > next_in_service->budget)
ret = true;
bfqg_entity->budget = next_in_service->budget;
}
return ret;
}
static bool bfq_no_longer_next_in_service(struct bfq_entity *entity)
{
struct bfq_group *bfqg;
if (bfq_entity_to_bfqq(entity))
return true;
bfqg = container_of(entity, struct bfq_group, entity);
if (bfqg->active_entities == 1)
return true;
return false;
}
struct bfq_group *bfq_bfqq_to_bfqg(struct bfq_queue *bfqq)
{
return bfqq->bfqd->root_group;
}
static bool bfq_update_parent_budget(struct bfq_entity *next_in_service)
{
return false;
}
static bool bfq_no_longer_next_in_service(struct bfq_entity *entity)
{
return true;
}
struct bfq_queue *bfq_entity_to_bfqq(struct bfq_entity *entity)
{
struct bfq_queue *bfqq = NULL;
if (!entity->my_sched_data)
bfqq = container_of(entity, struct bfq_queue, entity);
return bfqq;
}
static u64 bfq_delta(unsigned long service, unsigned long weight)
{
u64 d = (u64)service << WFQ_SERVICE_SHIFT;
do_div(d, weight);
return d;
}
static void bfq_calc_finish(struct bfq_entity *entity, unsigned long service)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
entity->finish = entity->start +
bfq_delta(service, entity->weight);
if (bfqq) {
bfq_log_bfqq(bfqq->bfqd, bfqq,
"calc_finish: serv %lu, w %d",
service, entity->weight);
bfq_log_bfqq(bfqq->bfqd, bfqq,
"calc_finish: start %llu, finish %llu, delta %llu",
entity->start, entity->finish,
bfq_delta(service, entity->weight));
}
}
struct bfq_entity *bfq_entity_of(struct rb_node *node)
{
struct bfq_entity *entity = NULL;
if (node)
entity = rb_entry(node, struct bfq_entity, rb_node);
return entity;
}
static void bfq_extract(struct rb_root *root, struct bfq_entity *entity)
{
entity->tree = NULL;
rb_erase(&entity->rb_node, root);
}
static void bfq_idle_extract(struct bfq_service_tree *st,
struct bfq_entity *entity)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
struct rb_node *next;
if (entity == st->first_idle) {
next = rb_next(&entity->rb_node);
st->first_idle = bfq_entity_of(next);
}
if (entity == st->last_idle) {
next = rb_prev(&entity->rb_node);
st->last_idle = bfq_entity_of(next);
}
bfq_extract(&st->idle, entity);
if (bfqq)
list_del(&bfqq->bfqq_list);
}
static void bfq_insert(struct rb_root *root, struct bfq_entity *entity)
{
struct bfq_entity *entry;
struct rb_node **node = &root->rb_node;
struct rb_node *parent = NULL;
while (*node) {
parent = *node;
entry = rb_entry(parent, struct bfq_entity, rb_node);
if (bfq_gt(entry->finish, entity->finish))
node = &parent->rb_left;
else
node = &parent->rb_right;
}
rb_link_node(&entity->rb_node, parent, node);
rb_insert_color(&entity->rb_node, root);
entity->tree = root;
}
static void bfq_update_min(struct bfq_entity *entity, struct rb_node *node)
{
struct bfq_entity *child;
if (node) {
child = rb_entry(node, struct bfq_entity, rb_node);
if (bfq_gt(entity->min_start, child->min_start))
entity->min_start = child->min_start;
}
}
static void bfq_update_active_node(struct rb_node *node)
{
struct bfq_entity *entity = rb_entry(node, struct bfq_entity, rb_node);
entity->min_start = entity->start;
bfq_update_min(entity, node->rb_right);
bfq_update_min(entity, node->rb_left);
}
static void bfq_update_active_tree(struct rb_node *node)
{
struct rb_node *parent;
up:
bfq_update_active_node(node);
parent = rb_parent(node);
if (!parent)
return;
if (node == parent->rb_left && parent->rb_right)
bfq_update_active_node(parent->rb_right);
else if (parent->rb_left)
bfq_update_active_node(parent->rb_left);
node = parent;
goto up;
}
static void bfq_active_insert(struct bfq_service_tree *st,
struct bfq_entity *entity)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
struct rb_node *node = &entity->rb_node;
#ifdef CONFIG_BFQ_GROUP_IOSCHED
struct bfq_sched_data *sd = NULL;
struct bfq_group *bfqg = NULL;
struct bfq_data *bfqd = NULL;
#endif
bfq_insert(&st->active, entity);
if (node->rb_left)
node = node->rb_left;
else if (node->rb_right)
node = node->rb_right;
bfq_update_active_tree(node);
#ifdef CONFIG_BFQ_GROUP_IOSCHED
sd = entity->sched_data;
bfqg = container_of(sd, struct bfq_group, sched_data);
bfqd = (struct bfq_data *)bfqg->bfqd;
#endif
if (bfqq)
list_add(&bfqq->bfqq_list, &bfqq->bfqd->active_list);
#ifdef CONFIG_BFQ_GROUP_IOSCHED
else
bfq_weights_tree_add(bfqd, entity, &bfqd->group_weights_tree);
if (bfqg != bfqd->root_group)
bfqg->active_entities++;
#endif
}
unsigned short bfq_ioprio_to_weight(int ioprio)
{
return (IOPRIO_BE_NR - ioprio) * BFQ_WEIGHT_CONVERSION_COEFF;
}
static unsigned short bfq_weight_to_ioprio(int weight)
{
return max_t(int, 0,
IOPRIO_BE_NR * BFQ_WEIGHT_CONVERSION_COEFF - weight);
}
static void bfq_get_entity(struct bfq_entity *entity)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
if (bfqq) {
bfqq->ref++;
bfq_log_bfqq(bfqq->bfqd, bfqq, "get_entity: %p %d",
bfqq, bfqq->ref);
}
}
static struct rb_node *bfq_find_deepest(struct rb_node *node)
{
struct rb_node *deepest;
if (!node->rb_right && !node->rb_left)
deepest = rb_parent(node);
else if (!node->rb_right)
deepest = node->rb_left;
else if (!node->rb_left)
deepest = node->rb_right;
else {
deepest = rb_next(node);
if (deepest->rb_right)
deepest = deepest->rb_right;
else if (rb_parent(deepest) != node)
deepest = rb_parent(deepest);
}
return deepest;
}
static void bfq_active_extract(struct bfq_service_tree *st,
struct bfq_entity *entity)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
struct rb_node *node;
#ifdef CONFIG_BFQ_GROUP_IOSCHED
struct bfq_sched_data *sd = NULL;
struct bfq_group *bfqg = NULL;
struct bfq_data *bfqd = NULL;
#endif
node = bfq_find_deepest(&entity->rb_node);
bfq_extract(&st->active, entity);
if (node)
bfq_update_active_tree(node);
#ifdef CONFIG_BFQ_GROUP_IOSCHED
sd = entity->sched_data;
bfqg = container_of(sd, struct bfq_group, sched_data);
bfqd = (struct bfq_data *)bfqg->bfqd;
#endif
if (bfqq)
list_del(&bfqq->bfqq_list);
#ifdef CONFIG_BFQ_GROUP_IOSCHED
else
bfq_weights_tree_remove(bfqd, entity,
&bfqd->group_weights_tree);
if (bfqg != bfqd->root_group)
bfqg->active_entities--;
#endif
}
static void bfq_idle_insert(struct bfq_service_tree *st,
struct bfq_entity *entity)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
struct bfq_entity *first_idle = st->first_idle;
struct bfq_entity *last_idle = st->last_idle;
if (!first_idle || bfq_gt(first_idle->finish, entity->finish))
st->first_idle = entity;
if (!last_idle || bfq_gt(entity->finish, last_idle->finish))
st->last_idle = entity;
bfq_insert(&st->idle, entity);
if (bfqq)
list_add(&bfqq->bfqq_list, &bfqq->bfqd->idle_list);
}
static void bfq_forget_entity(struct bfq_service_tree *st,
struct bfq_entity *entity,
bool is_in_service)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
entity->on_st = false;
st->wsum -= entity->weight;
if (bfqq && !is_in_service)
bfq_put_queue(bfqq);
}
void bfq_put_idle_entity(struct bfq_service_tree *st, struct bfq_entity *entity)
{
bfq_idle_extract(st, entity);
bfq_forget_entity(st, entity,
entity == entity->sched_data->in_service_entity);
}
static void bfq_forget_idle(struct bfq_service_tree *st)
{
struct bfq_entity *first_idle = st->first_idle;
struct bfq_entity *last_idle = st->last_idle;
if (RB_EMPTY_ROOT(&st->active) && last_idle &&
!bfq_gt(last_idle->finish, st->vtime)) {
st->vtime = last_idle->finish;
}
if (first_idle && !bfq_gt(first_idle->finish, st->vtime))
bfq_put_idle_entity(st, first_idle);
}
struct bfq_service_tree *bfq_entity_service_tree(struct bfq_entity *entity)
{
struct bfq_sched_data *sched_data = entity->sched_data;
unsigned int idx = bfq_class_idx(entity);
return sched_data->service_tree + idx;
}
struct bfq_service_tree *
__bfq_entity_update_weight_prio(struct bfq_service_tree *old_st,
struct bfq_entity *entity,
bool update_class_too)
{
struct bfq_service_tree *new_st = old_st;
if (entity->prio_changed) {
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
unsigned int prev_weight, new_weight;
struct bfq_data *bfqd = NULL;
struct rb_root *root;
#ifdef CONFIG_BFQ_GROUP_IOSCHED
struct bfq_sched_data *sd;
struct bfq_group *bfqg;
#endif
if (bfqq)
bfqd = bfqq->bfqd;
#ifdef CONFIG_BFQ_GROUP_IOSCHED
else {
sd = entity->my_sched_data;
bfqg = container_of(sd, struct bfq_group, sched_data);
bfqd = (struct bfq_data *)bfqg->bfqd;
}
#endif
old_st->wsum -= entity->weight;
if (entity->new_weight != entity->orig_weight) {
if (entity->new_weight < BFQ_MIN_WEIGHT ||
entity->new_weight > BFQ_MAX_WEIGHT) {
pr_crit("update_weight_prio: new_weight %d\n",
entity->new_weight);
if (entity->new_weight < BFQ_MIN_WEIGHT)
entity->new_weight = BFQ_MIN_WEIGHT;
else
entity->new_weight = BFQ_MAX_WEIGHT;
}
entity->orig_weight = entity->new_weight;
if (bfqq)
bfqq->ioprio =
bfq_weight_to_ioprio(entity->orig_weight);
}
if (bfqq && update_class_too)
bfqq->ioprio_class = bfqq->new_ioprio_class;
if (!bfqq || bfqq->ioprio_class == bfqq->new_ioprio_class)
entity->prio_changed = 0;
new_st = bfq_entity_service_tree(entity);
prev_weight = entity->weight;
new_weight = entity->orig_weight *
(bfqq ? bfqq->wr_coeff : 1);
if (prev_weight != new_weight) {
root = bfqq ? &bfqd->queue_weights_tree :
&bfqd->group_weights_tree;
bfq_weights_tree_remove(bfqd, entity, root);
}
entity->weight = new_weight;
if (prev_weight != new_weight &&
(bfqq ? bfqq->wr_coeff == 1 : 1))
bfq_weights_tree_add(bfqd, entity, root);
new_st->wsum += entity->weight;
if (new_st != old_st)
entity->start = new_st->vtime;
}
return new_st;
}
void bfq_bfqq_served(struct bfq_queue *bfqq, int served)
{
struct bfq_entity *entity = &bfqq->entity;
struct bfq_service_tree *st;
for_each_entity(entity) {
st = bfq_entity_service_tree(entity);
entity->service += served;
st->vtime += bfq_delta(served, st->wsum);
bfq_forget_idle(st);
}
bfqg_stats_set_start_empty_time(bfqq_group(bfqq));
bfq_log_bfqq(bfqq->bfqd, bfqq, "bfqq_served %d secs", served);
}
void bfq_bfqq_charge_time(struct bfq_data *bfqd, struct bfq_queue *bfqq,
unsigned long time_ms)
{
struct bfq_entity *entity = &bfqq->entity;
int tot_serv_to_charge = entity->service;
unsigned int timeout_ms = jiffies_to_msecs(bfq_timeout);
if (time_ms > 0 && time_ms < timeout_ms)
tot_serv_to_charge =
(bfqd->bfq_max_budget * time_ms) / timeout_ms;
if (tot_serv_to_charge < entity->service)
tot_serv_to_charge = entity->service;
if (tot_serv_to_charge > entity->budget)
entity->budget = tot_serv_to_charge;
bfq_bfqq_served(bfqq,
max_t(int, 0, tot_serv_to_charge - entity->service));
}
static void bfq_update_fin_time_enqueue(struct bfq_entity *entity,
struct bfq_service_tree *st,
bool backshifted)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
st = __bfq_entity_update_weight_prio(st, entity, true);
bfq_calc_finish(entity, entity->budget);
if (backshifted && bfq_gt(st->vtime, entity->finish)) {
unsigned long delta = st->vtime - entity->finish;
if (bfqq)
delta /= bfqq->wr_coeff;
entity->start += delta;
entity->finish += delta;
}
bfq_active_insert(st, entity);
}
static void __bfq_activate_entity(struct bfq_entity *entity,
bool non_blocking_wait_rq)
{
struct bfq_service_tree *st = bfq_entity_service_tree(entity);
bool backshifted = false;
unsigned long long min_vstart;
if (non_blocking_wait_rq && bfq_gt(st->vtime, entity->finish)) {
backshifted = true;
min_vstart = entity->finish;
} else
min_vstart = st->vtime;
if (entity->tree == &st->idle) {
bfq_idle_extract(st, entity);
entity->start = bfq_gt(min_vstart, entity->finish) ?
min_vstart : entity->finish;
} else {
entity->start = min_vstart;
st->wsum += entity->weight;
bfq_get_entity(entity);
entity->on_st = true;
}
bfq_update_fin_time_enqueue(entity, st, backshifted);
}
static void __bfq_requeue_entity(struct bfq_entity *entity)
{
struct bfq_sched_data *sd = entity->sched_data;
struct bfq_service_tree *st = bfq_entity_service_tree(entity);
if (entity == sd->in_service_entity) {
bfq_calc_finish(entity, entity->service);
entity->start = entity->finish;
if (entity->tree)
bfq_active_extract(st, entity);
} else {
bfq_active_extract(st, entity);
}
bfq_update_fin_time_enqueue(entity, st, false);
}
static void __bfq_activate_requeue_entity(struct bfq_entity *entity,
struct bfq_sched_data *sd,
bool non_blocking_wait_rq)
{
struct bfq_service_tree *st = bfq_entity_service_tree(entity);
if (sd->in_service_entity == entity || entity->tree == &st->active)
__bfq_requeue_entity(entity);
else
__bfq_activate_entity(entity, non_blocking_wait_rq);
}
static void bfq_activate_requeue_entity(struct bfq_entity *entity,
bool non_blocking_wait_rq,
bool requeue)
{
struct bfq_sched_data *sd;
for_each_entity(entity) {
sd = entity->sched_data;
__bfq_activate_requeue_entity(entity, sd, non_blocking_wait_rq);
if (!bfq_update_next_in_service(sd, entity) && !requeue)
break;
}
}
bool __bfq_deactivate_entity(struct bfq_entity *entity, bool ins_into_idle_tree)
{
struct bfq_sched_data *sd = entity->sched_data;
struct bfq_service_tree *st;
bool is_in_service;
if (!entity->on_st)
return false;
st = bfq_entity_service_tree(entity);
is_in_service = entity == sd->in_service_entity;
if (is_in_service) {
bfq_calc_finish(entity, entity->service);
sd->in_service_entity = NULL;
}
if (entity->tree == &st->active)
bfq_active_extract(st, entity);
else if (!is_in_service && entity->tree == &st->idle)
bfq_idle_extract(st, entity);
if (!ins_into_idle_tree || !bfq_gt(entity->finish, st->vtime))
bfq_forget_entity(st, entity, is_in_service);
else
bfq_idle_insert(st, entity);
return true;
}
static void bfq_deactivate_entity(struct bfq_entity *entity,
bool ins_into_idle_tree,
bool expiration)
{
struct bfq_sched_data *sd;
struct bfq_entity *parent = NULL;
for_each_entity_safe(entity, parent) {
sd = entity->sched_data;
if (!__bfq_deactivate_entity(entity, ins_into_idle_tree)) {
return;
}
if (sd->next_in_service == entity)
bfq_update_next_in_service(sd, NULL);
if (sd->next_in_service || sd->in_service_entity) {
break;
}
ins_into_idle_tree = true;
}
entity = parent;
for_each_entity(entity) {
__bfq_requeue_entity(entity);
sd = entity->sched_data;
if (!bfq_update_next_in_service(sd, entity) &&
!expiration)
break;
}
}
static u64 bfq_calc_vtime_jump(struct bfq_service_tree *st)
{
struct bfq_entity *root_entity = bfq_root_active_entity(&st->active);
if (bfq_gt(root_entity->min_start, st->vtime))
return root_entity->min_start;
return st->vtime;
}
static void bfq_update_vtime(struct bfq_service_tree *st, u64 new_value)
{
if (new_value > st->vtime) {
st->vtime = new_value;
bfq_forget_idle(st);
}
}
static struct bfq_entity *bfq_first_active_entity(struct bfq_service_tree *st,
u64 vtime)
{
struct bfq_entity *entry, *first = NULL;
struct rb_node *node = st->active.rb_node;
while (node) {
entry = rb_entry(node, struct bfq_entity, rb_node);
left:
if (!bfq_gt(entry->start, vtime))
first = entry;
if (node->rb_left) {
entry = rb_entry(node->rb_left,
struct bfq_entity, rb_node);
if (!bfq_gt(entry->min_start, vtime)) {
node = node->rb_left;
goto left;
}
}
if (first)
break;
node = node->rb_right;
}
return first;
}
static struct bfq_entity *
__bfq_lookup_next_entity(struct bfq_service_tree *st, bool in_service)
{
struct bfq_entity *entity;
u64 new_vtime;
if (RB_EMPTY_ROOT(&st->active))
return NULL;
new_vtime = bfq_calc_vtime_jump(st);
if (!in_service)
bfq_update_vtime(st, new_vtime);
entity = bfq_first_active_entity(st, new_vtime);
return entity;
}
static struct bfq_entity *bfq_lookup_next_entity(struct bfq_sched_data *sd)
{
struct bfq_service_tree *st = sd->service_tree;
struct bfq_service_tree *idle_class_st = st + (BFQ_IOPRIO_CLASSES - 1);
struct bfq_entity *entity = NULL;
int class_idx = 0;
if (time_is_before_jiffies(sd->bfq_class_idle_last_service +
BFQ_CL_IDLE_TIMEOUT)) {
if (!RB_EMPTY_ROOT(&idle_class_st->active))
class_idx = BFQ_IOPRIO_CLASSES - 1;
sd->bfq_class_idle_last_service = jiffies;
}
for (; class_idx < BFQ_IOPRIO_CLASSES; class_idx++) {
entity = __bfq_lookup_next_entity(st + class_idx,
sd->in_service_entity);
if (entity)
break;
}
if (!entity)
return NULL;
return entity;
}
bool next_queue_may_preempt(struct bfq_data *bfqd)
{
struct bfq_sched_data *sd = &bfqd->root_group->sched_data;
return sd->next_in_service != sd->in_service_entity;
}
struct bfq_queue *bfq_get_next_queue(struct bfq_data *bfqd)
{
struct bfq_entity *entity = NULL;
struct bfq_sched_data *sd;
struct bfq_queue *bfqq;
if (bfqd->busy_queues == 0)
return NULL;
sd = &bfqd->root_group->sched_data;
for (; sd ; sd = entity->my_sched_data) {
entity = sd->next_in_service;
sd->in_service_entity = entity;
entity->service = 0;
if (bfq_no_longer_next_in_service(entity))
bfq_active_extract(bfq_entity_service_tree(entity),
entity);
}
bfqq = bfq_entity_to_bfqq(entity);
for_each_entity(entity) {
struct bfq_sched_data *sd = entity->sched_data;
if (!bfq_update_next_in_service(sd, NULL))
break;
}
return bfqq;
}
void __bfq_bfqd_reset_in_service(struct bfq_data *bfqd)
{
struct bfq_queue *in_serv_bfqq = bfqd->in_service_queue;
struct bfq_entity *in_serv_entity = &in_serv_bfqq->entity;
struct bfq_entity *entity = in_serv_entity;
bfq_clear_bfqq_wait_request(in_serv_bfqq);
hrtimer_try_to_cancel(&bfqd->idle_slice_timer);
bfqd->in_service_queue = NULL;
for_each_entity(entity)
entity->sched_data->in_service_entity = NULL;
if (!in_serv_entity->on_st)
bfq_put_queue(in_serv_bfqq);
}
void bfq_deactivate_bfqq(struct bfq_data *bfqd, struct bfq_queue *bfqq,
bool ins_into_idle_tree, bool expiration)
{
struct bfq_entity *entity = &bfqq->entity;
bfq_deactivate_entity(entity, ins_into_idle_tree, expiration);
}
void bfq_activate_bfqq(struct bfq_data *bfqd, struct bfq_queue *bfqq)
{
struct bfq_entity *entity = &bfqq->entity;
bfq_activate_requeue_entity(entity, bfq_bfqq_non_blocking_wait_rq(bfqq),
false);
bfq_clear_bfqq_non_blocking_wait_rq(bfqq);
}
void bfq_requeue_bfqq(struct bfq_data *bfqd, struct bfq_queue *bfqq)
{
struct bfq_entity *entity = &bfqq->entity;
bfq_activate_requeue_entity(entity, false,
bfqq == bfqd->in_service_queue);
}
void bfq_del_bfqq_busy(struct bfq_data *bfqd, struct bfq_queue *bfqq,
bool expiration)
{
bfq_log_bfqq(bfqd, bfqq, "del from busy");
bfq_clear_bfqq_busy(bfqq);
bfqd->busy_queues--;
if (!bfqq->dispatched)
bfq_weights_tree_remove(bfqd, &bfqq->entity,
&bfqd->queue_weights_tree);
if (bfqq->wr_coeff > 1)
bfqd->wr_busy_queues--;
bfqg_stats_update_dequeue(bfqq_group(bfqq));
bfq_deactivate_bfqq(bfqd, bfqq, true, expiration);
}
void bfq_add_bfqq_busy(struct bfq_data *bfqd, struct bfq_queue *bfqq)
{
bfq_log_bfqq(bfqd, bfqq, "add to busy");
bfq_activate_bfqq(bfqd, bfqq);
bfq_mark_bfqq_busy(bfqq);
bfqd->busy_queues++;
if (!bfqq->dispatched)
if (bfqq->wr_coeff == 1)
bfq_weights_tree_add(bfqd, &bfqq->entity,
&bfqd->queue_weights_tree);
if (bfqq->wr_coeff > 1)
bfqd->wr_busy_queues++;
}
