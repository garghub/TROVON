static u32 pde_get_multiple(u32 val, u32 fraction, u32 tolerance)
{
u32 remainder;
u32 factor;
u32 delta;
if (fraction == 0)
return 0;
delta = (val < fraction) ? (fraction - val) : (val - fraction);
if (delta <= tolerance)
return 1;
factor = val / fraction;
remainder = val % fraction;
if (remainder > tolerance) {
if ((fraction - remainder) <= tolerance)
factor++;
else
factor = 0;
}
return factor;
}
static void pool_register_ref(void)
{
spin_lock_bh(&pool_lock);
singleton_pool_references++;
DFS_POOL_STAT_INC(pool_reference);
spin_unlock_bh(&pool_lock);
}
static void pool_deregister_ref(void)
{
spin_lock_bh(&pool_lock);
singleton_pool_references--;
DFS_POOL_STAT_DEC(pool_reference);
if (singleton_pool_references == 0) {
struct pri_sequence *ps, *ps0;
struct pulse_elem *p, *p0;
list_for_each_entry_safe(p, p0, &pulse_pool, head) {
list_del(&p->head);
DFS_POOL_STAT_DEC(pulse_allocated);
kfree(p);
}
list_for_each_entry_safe(ps, ps0, &pseq_pool, head) {
list_del(&ps->head);
DFS_POOL_STAT_DEC(pseq_allocated);
kfree(ps);
}
}
spin_unlock_bh(&pool_lock);
}
static void pool_put_pulse_elem(struct pulse_elem *pe)
{
spin_lock_bh(&pool_lock);
list_add(&pe->head, &pulse_pool);
DFS_POOL_STAT_DEC(pulse_used);
spin_unlock_bh(&pool_lock);
}
static void pool_put_pseq_elem(struct pri_sequence *pse)
{
spin_lock_bh(&pool_lock);
list_add(&pse->head, &pseq_pool);
DFS_POOL_STAT_DEC(pseq_used);
spin_unlock_bh(&pool_lock);
}
static struct pri_sequence *pool_get_pseq_elem(void)
{
struct pri_sequence *pse = NULL;
spin_lock_bh(&pool_lock);
if (!list_empty(&pseq_pool)) {
pse = list_first_entry(&pseq_pool, struct pri_sequence, head);
list_del(&pse->head);
DFS_POOL_STAT_INC(pseq_used);
}
spin_unlock_bh(&pool_lock);
return pse;
}
static struct pulse_elem *pool_get_pulse_elem(void)
{
struct pulse_elem *pe = NULL;
spin_lock_bh(&pool_lock);
if (!list_empty(&pulse_pool)) {
pe = list_first_entry(&pulse_pool, struct pulse_elem, head);
list_del(&pe->head);
DFS_POOL_STAT_INC(pulse_used);
}
spin_unlock_bh(&pool_lock);
return pe;
}
static struct pulse_elem *pulse_queue_get_tail(struct pri_detector *pde)
{
struct list_head *l = &pde->pulses;
if (list_empty(l))
return NULL;
return list_entry(l->prev, struct pulse_elem, head);
}
static bool pulse_queue_dequeue(struct pri_detector *pde)
{
struct pulse_elem *p = pulse_queue_get_tail(pde);
if (p != NULL) {
list_del_init(&p->head);
pde->count--;
pool_put_pulse_elem(p);
}
return (pde->count > 0);
}
static void pulse_queue_check_window(struct pri_detector *pde)
{
u64 min_valid_ts;
struct pulse_elem *p;
if (pde->count < 2)
return;
if (pde->last_ts <= pde->window_size)
return;
min_valid_ts = pde->last_ts - pde->window_size;
while ((p = pulse_queue_get_tail(pde)) != NULL) {
if (p->ts >= min_valid_ts)
return;
pulse_queue_dequeue(pde);
}
}
static bool pulse_queue_enqueue(struct pri_detector *pde, u64 ts)
{
struct pulse_elem *p = pool_get_pulse_elem();
if (p == NULL) {
p = kmalloc(sizeof(*p), GFP_ATOMIC);
if (p == NULL) {
DFS_POOL_STAT_INC(pulse_alloc_error);
return false;
}
DFS_POOL_STAT_INC(pulse_allocated);
DFS_POOL_STAT_INC(pulse_used);
}
INIT_LIST_HEAD(&p->head);
p->ts = ts;
list_add(&p->head, &pde->pulses);
pde->count++;
pde->last_ts = ts;
pulse_queue_check_window(pde);
if (pde->count >= pde->max_count)
pulse_queue_dequeue(pde);
return true;
}
static bool pseq_handler_create_sequences(struct pri_detector *pde,
u64 ts, u32 min_count)
{
struct pulse_elem *p;
list_for_each_entry(p, &pde->pulses, head) {
struct pri_sequence ps, *new_ps;
struct pulse_elem *p2;
u32 tmp_false_count;
u64 min_valid_ts;
u32 delta_ts = ts - p->ts;
if (delta_ts < pde->rs->pri_min)
continue;
if (delta_ts > pde->rs->pri_max)
break;
ps.count = 2;
ps.count_falses = 0;
ps.first_ts = p->ts;
ps.last_ts = ts;
ps.pri = ts - p->ts;
ps.dur = ps.pri * (pde->rs->ppb - 1)
+ 2 * pde->rs->max_pri_tolerance;
p2 = p;
tmp_false_count = 0;
min_valid_ts = ts - ps.dur;
list_for_each_entry_continue(p2, &pde->pulses, head) {
u32 factor;
if (p2->ts < min_valid_ts)
break;
factor = pde_get_multiple(ps.last_ts - p2->ts, ps.pri,
pde->rs->max_pri_tolerance);
if (factor > 0) {
ps.count++;
ps.first_ts = p2->ts;
ps.count_falses += tmp_false_count;
tmp_false_count = 0;
} else {
tmp_false_count++;
}
}
if (ps.count < min_count)
continue;
ps.deadline_ts = ps.first_ts + ps.dur;
new_ps = pool_get_pseq_elem();
if (new_ps == NULL) {
new_ps = kmalloc(sizeof(*new_ps), GFP_ATOMIC);
if (new_ps == NULL) {
DFS_POOL_STAT_INC(pseq_alloc_error);
return false;
}
DFS_POOL_STAT_INC(pseq_allocated);
DFS_POOL_STAT_INC(pseq_used);
}
memcpy(new_ps, &ps, sizeof(ps));
INIT_LIST_HEAD(&new_ps->head);
list_add(&new_ps->head, &pde->sequences);
}
return true;
}
static u32
pseq_handler_add_to_existing_seqs(struct pri_detector *pde, u64 ts)
{
u32 max_count = 0;
struct pri_sequence *ps, *ps2;
list_for_each_entry_safe(ps, ps2, &pde->sequences, head) {
u32 delta_ts;
u32 factor;
if (ts > ps->deadline_ts) {
list_del_init(&ps->head);
pool_put_pseq_elem(ps);
continue;
}
delta_ts = ts - ps->last_ts;
factor = pde_get_multiple(delta_ts, ps->pri,
pde->rs->max_pri_tolerance);
if (factor > 0) {
ps->last_ts = ts;
ps->count++;
if (max_count < ps->count)
max_count = ps->count;
} else {
ps->count_falses++;
}
}
return max_count;
}
static struct pri_sequence *
pseq_handler_check_detection(struct pri_detector *pde)
{
struct pri_sequence *ps;
if (list_empty(&pde->sequences))
return NULL;
list_for_each_entry(ps, &pde->sequences, head) {
if ((ps->count >= pde->rs->ppb_thresh) &&
(ps->count * pde->rs->num_pri >= ps->count_falses))
return ps;
}
return NULL;
}
static void pri_detector_reset(struct pri_detector *pde, u64 ts)
{
struct pri_sequence *ps, *ps0;
struct pulse_elem *p, *p0;
list_for_each_entry_safe(ps, ps0, &pde->sequences, head) {
list_del_init(&ps->head);
pool_put_pseq_elem(ps);
}
list_for_each_entry_safe(p, p0, &pde->pulses, head) {
list_del_init(&p->head);
pool_put_pulse_elem(p);
}
pde->count = 0;
pde->last_ts = ts;
}
static void pri_detector_exit(struct pri_detector *de)
{
pri_detector_reset(de, 0);
pool_deregister_ref();
kfree(de);
}
static bool pri_detector_add_pulse(struct pri_detector *de,
struct pulse_event *event)
{
u32 max_updated_seq;
struct pri_sequence *ps;
u64 ts = event->ts;
const struct radar_detector_specs *rs = de->rs;
if ((rs->width_min > event->width) || (rs->width_max < event->width))
return false;
if ((ts - de->last_ts) < rs->max_pri_tolerance)
return false;
de->last_ts = ts;
max_updated_seq = pseq_handler_add_to_existing_seqs(de, ts);
if (!pseq_handler_create_sequences(de, ts, max_updated_seq)) {
pr_err("failed to create pulse sequences\n");
pri_detector_reset(de, ts);
return false;
}
ps = pseq_handler_check_detection(de);
if (ps != NULL) {
pr_info("DFS: radar found: pri=%d, count=%d, count_false=%d\n",
ps->pri, ps->count, ps->count_falses);
pri_detector_reset(de, ts);
return true;
}
pulse_queue_enqueue(de, ts);
return false;
}
struct pri_detector *
pri_detector_init(const struct radar_detector_specs *rs)
{
struct pri_detector *de;
de = kzalloc(sizeof(*de), GFP_KERNEL);
if (de == NULL)
return NULL;
de->exit = pri_detector_exit;
de->add_pulse = pri_detector_add_pulse;
de->reset = pri_detector_reset;
INIT_LIST_HEAD(&de->sequences);
INIT_LIST_HEAD(&de->pulses);
de->window_size = rs->pri_max * rs->ppb * rs->num_pri;
de->max_count = rs->ppb * 2;
de->rs = rs;
pool_register_ref();
return de;
}
