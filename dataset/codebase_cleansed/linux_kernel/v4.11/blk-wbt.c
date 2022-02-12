static inline bool rwb_enabled(struct rq_wb *rwb)
{
return rwb && rwb->wb_normal != 0;
}
static bool atomic_inc_below(atomic_t *v, int below)
{
int cur = atomic_read(v);
for (;;) {
int old;
if (cur >= below)
return false;
old = atomic_cmpxchg(v, cur, cur + 1);
if (old == cur)
break;
cur = old;
}
return true;
}
static void wb_timestamp(struct rq_wb *rwb, unsigned long *var)
{
if (rwb_enabled(rwb)) {
const unsigned long cur = jiffies;
if (cur != *var)
*var = cur;
}
}
static bool wb_recent_wait(struct rq_wb *rwb)
{
struct bdi_writeback *wb = &rwb->queue->backing_dev_info->wb;
return time_before(jiffies, wb->dirty_sleep + HZ);
}
static inline struct rq_wait *get_rq_wait(struct rq_wb *rwb, bool is_kswapd)
{
return &rwb->rq_wait[is_kswapd];
}
static void rwb_wake_all(struct rq_wb *rwb)
{
int i;
for (i = 0; i < WBT_NUM_RWQ; i++) {
struct rq_wait *rqw = &rwb->rq_wait[i];
if (waitqueue_active(&rqw->wait))
wake_up_all(&rqw->wait);
}
}
void __wbt_done(struct rq_wb *rwb, enum wbt_flags wb_acct)
{
struct rq_wait *rqw;
int inflight, limit;
if (!(wb_acct & WBT_TRACKED))
return;
rqw = get_rq_wait(rwb, wb_acct & WBT_KSWAPD);
inflight = atomic_dec_return(&rqw->inflight);
if (unlikely(!rwb_enabled(rwb))) {
rwb_wake_all(rwb);
return;
}
if (rwb->wc && !wb_recent_wait(rwb))
limit = 0;
else
limit = rwb->wb_normal;
if (inflight && inflight >= limit)
return;
if (waitqueue_active(&rqw->wait)) {
int diff = limit - inflight;
if (!inflight || diff >= rwb->wb_background / 2)
wake_up_all(&rqw->wait);
}
}
void wbt_done(struct rq_wb *rwb, struct blk_issue_stat *stat)
{
if (!rwb)
return;
if (!wbt_is_tracked(stat)) {
if (rwb->sync_cookie == stat) {
rwb->sync_issue = 0;
rwb->sync_cookie = NULL;
}
if (wbt_is_read(stat))
wb_timestamp(rwb, &rwb->last_comp);
wbt_clear_state(stat);
} else {
WARN_ON_ONCE(stat == rwb->sync_cookie);
__wbt_done(rwb, wbt_stat_to_mask(stat));
wbt_clear_state(stat);
}
}
static bool calc_wb_limits(struct rq_wb *rwb)
{
unsigned int depth;
bool ret = false;
if (!rwb->min_lat_nsec) {
rwb->wb_max = rwb->wb_normal = rwb->wb_background = 0;
return false;
}
if (rwb->queue_depth == 1) {
if (rwb->scale_step > 0)
rwb->wb_max = rwb->wb_normal = 1;
else {
rwb->wb_max = rwb->wb_normal = 2;
ret = true;
}
rwb->wb_background = 1;
} else {
depth = min_t(unsigned int, RWB_DEF_DEPTH, rwb->queue_depth);
if (rwb->scale_step > 0)
depth = 1 + ((depth - 1) >> min(31, rwb->scale_step));
else if (rwb->scale_step < 0) {
unsigned int maxd = 3 * rwb->queue_depth / 4;
depth = 1 + ((depth - 1) << -rwb->scale_step);
if (depth > maxd) {
depth = maxd;
ret = true;
}
}
rwb->wb_max = depth;
rwb->wb_normal = (rwb->wb_max + 1) / 2;
rwb->wb_background = (rwb->wb_max + 3) / 4;
}
return ret;
}
static inline bool stat_sample_valid(struct blk_rq_stat *stat)
{
return stat[BLK_STAT_READ].nr_samples >= 1 &&
stat[BLK_STAT_WRITE].nr_samples >= RWB_MIN_WRITE_SAMPLES;
}
static u64 rwb_sync_issue_lat(struct rq_wb *rwb)
{
u64 now, issue = ACCESS_ONCE(rwb->sync_issue);
if (!issue || !rwb->sync_cookie)
return 0;
now = ktime_to_ns(ktime_get());
return now - issue;
}
static int __latency_exceeded(struct rq_wb *rwb, struct blk_rq_stat *stat)
{
struct backing_dev_info *bdi = rwb->queue->backing_dev_info;
u64 thislat;
thislat = rwb_sync_issue_lat(rwb);
if (thislat > rwb->cur_win_nsec ||
(thislat > rwb->min_lat_nsec && !stat[BLK_STAT_READ].nr_samples)) {
trace_wbt_lat(bdi, thislat);
return LAT_EXCEEDED;
}
if (!stat_sample_valid(stat)) {
if ((stat[BLK_STAT_WRITE].nr_samples && blk_stat_is_current(stat)) ||
wb_recent_wait(rwb) || wbt_inflight(rwb))
return LAT_UNKNOWN_WRITES;
return LAT_UNKNOWN;
}
if (stat[BLK_STAT_READ].min > rwb->min_lat_nsec) {
trace_wbt_lat(bdi, stat[BLK_STAT_READ].min);
trace_wbt_stat(bdi, stat);
return LAT_EXCEEDED;
}
if (rwb->scale_step)
trace_wbt_stat(bdi, stat);
return LAT_OK;
}
static int latency_exceeded(struct rq_wb *rwb)
{
struct blk_rq_stat stat[2];
blk_queue_stat_get(rwb->queue, stat);
return __latency_exceeded(rwb, stat);
}
static void rwb_trace_step(struct rq_wb *rwb, const char *msg)
{
struct backing_dev_info *bdi = rwb->queue->backing_dev_info;
trace_wbt_step(bdi, msg, rwb->scale_step, rwb->cur_win_nsec,
rwb->wb_background, rwb->wb_normal, rwb->wb_max);
}
static void scale_up(struct rq_wb *rwb)
{
if (rwb->scaled_max)
return;
rwb->scale_step--;
rwb->unknown_cnt = 0;
blk_stat_clear(rwb->queue);
rwb->scaled_max = calc_wb_limits(rwb);
rwb_wake_all(rwb);
rwb_trace_step(rwb, "step up");
}
static void scale_down(struct rq_wb *rwb, bool hard_throttle)
{
if (rwb->wb_max == 1)
return;
if (rwb->scale_step < 0 && hard_throttle)
rwb->scale_step = 0;
else
rwb->scale_step++;
rwb->scaled_max = false;
rwb->unknown_cnt = 0;
blk_stat_clear(rwb->queue);
calc_wb_limits(rwb);
rwb_trace_step(rwb, "step down");
}
static void rwb_arm_timer(struct rq_wb *rwb)
{
unsigned long expires;
if (rwb->scale_step > 0) {
rwb->cur_win_nsec = div_u64(rwb->win_nsec << 4,
int_sqrt((rwb->scale_step + 1) << 8));
} else {
rwb->cur_win_nsec = rwb->win_nsec;
}
expires = jiffies + nsecs_to_jiffies(rwb->cur_win_nsec);
mod_timer(&rwb->window_timer, expires);
}
static void wb_timer_fn(unsigned long data)
{
struct rq_wb *rwb = (struct rq_wb *) data;
unsigned int inflight = wbt_inflight(rwb);
int status;
status = latency_exceeded(rwb);
trace_wbt_timer(rwb->queue->backing_dev_info, status, rwb->scale_step,
inflight);
switch (status) {
case LAT_EXCEEDED:
scale_down(rwb, true);
break;
case LAT_OK:
scale_up(rwb);
break;
case LAT_UNKNOWN_WRITES:
scale_up(rwb);
break;
case LAT_UNKNOWN:
if (++rwb->unknown_cnt < RWB_UNKNOWN_BUMP)
break;
if (rwb->scale_step > 0)
scale_up(rwb);
else if (rwb->scale_step < 0)
scale_down(rwb, false);
break;
default:
break;
}
if (rwb->scale_step || inflight)
rwb_arm_timer(rwb);
}
void wbt_update_limits(struct rq_wb *rwb)
{
rwb->scale_step = 0;
rwb->scaled_max = false;
calc_wb_limits(rwb);
rwb_wake_all(rwb);
}
static bool close_io(struct rq_wb *rwb)
{
const unsigned long now = jiffies;
return time_before(now, rwb->last_issue + HZ / 10) ||
time_before(now, rwb->last_comp + HZ / 10);
}
static inline unsigned int get_limit(struct rq_wb *rwb, unsigned long rw)
{
unsigned int limit;
if ((rw & REQ_HIPRIO) || wb_recent_wait(rwb) || current_is_kswapd())
limit = rwb->wb_max;
else if ((rw & REQ_BACKGROUND) || close_io(rwb)) {
limit = rwb->wb_background;
} else
limit = rwb->wb_normal;
return limit;
}
static inline bool may_queue(struct rq_wb *rwb, struct rq_wait *rqw,
wait_queue_t *wait, unsigned long rw)
{
if (!rwb_enabled(rwb)) {
atomic_inc(&rqw->inflight);
return true;
}
if (waitqueue_active(&rqw->wait) &&
rqw->wait.task_list.next != &wait->task_list)
return false;
return atomic_inc_below(&rqw->inflight, get_limit(rwb, rw));
}
static void __wbt_wait(struct rq_wb *rwb, unsigned long rw, spinlock_t *lock)
__releases(lock)
__acquires(lock)
{
struct rq_wait *rqw = get_rq_wait(rwb, current_is_kswapd());
DEFINE_WAIT(wait);
if (may_queue(rwb, rqw, &wait, rw))
return;
do {
prepare_to_wait_exclusive(&rqw->wait, &wait,
TASK_UNINTERRUPTIBLE);
if (may_queue(rwb, rqw, &wait, rw))
break;
if (lock) {
spin_unlock_irq(lock);
io_schedule();
spin_lock_irq(lock);
} else
io_schedule();
} while (1);
finish_wait(&rqw->wait, &wait);
}
static inline bool wbt_should_throttle(struct rq_wb *rwb, struct bio *bio)
{
const int op = bio_op(bio);
if (op != REQ_OP_WRITE)
return false;
if ((bio->bi_opf & (REQ_SYNC | REQ_IDLE)) == (REQ_SYNC | REQ_IDLE))
return false;
return true;
}
enum wbt_flags wbt_wait(struct rq_wb *rwb, struct bio *bio, spinlock_t *lock)
{
unsigned int ret = 0;
if (!rwb_enabled(rwb))
return 0;
if (bio_op(bio) == REQ_OP_READ)
ret = WBT_READ;
if (!wbt_should_throttle(rwb, bio)) {
if (ret & WBT_READ)
wb_timestamp(rwb, &rwb->last_issue);
return ret;
}
__wbt_wait(rwb, bio->bi_opf, lock);
if (!timer_pending(&rwb->window_timer))
rwb_arm_timer(rwb);
if (current_is_kswapd())
ret |= WBT_KSWAPD;
return ret | WBT_TRACKED;
}
void wbt_issue(struct rq_wb *rwb, struct blk_issue_stat *stat)
{
if (!rwb_enabled(rwb))
return;
if (wbt_is_read(stat) && !rwb->sync_issue) {
rwb->sync_cookie = stat;
rwb->sync_issue = blk_stat_time(stat);
}
}
void wbt_requeue(struct rq_wb *rwb, struct blk_issue_stat *stat)
{
if (!rwb_enabled(rwb))
return;
if (stat == rwb->sync_cookie) {
rwb->sync_issue = 0;
rwb->sync_cookie = NULL;
}
}
void wbt_set_queue_depth(struct rq_wb *rwb, unsigned int depth)
{
if (rwb) {
rwb->queue_depth = depth;
wbt_update_limits(rwb);
}
}
void wbt_set_write_cache(struct rq_wb *rwb, bool write_cache_on)
{
if (rwb)
rwb->wc = write_cache_on;
}
void wbt_disable_default(struct request_queue *q)
{
struct rq_wb *rwb = q->rq_wb;
if (rwb && rwb->enable_state == WBT_STATE_ON_DEFAULT) {
del_timer_sync(&rwb->window_timer);
rwb->win_nsec = rwb->min_lat_nsec = 0;
wbt_update_limits(rwb);
}
}
u64 wbt_default_latency_nsec(struct request_queue *q)
{
if (blk_queue_nonrot(q))
return 2000000ULL;
else
return 75000000ULL;
}
int wbt_init(struct request_queue *q)
{
struct rq_wb *rwb;
int i;
BUILD_BUG_ON(RWB_WINDOW_NSEC > BLK_STAT_NSEC);
BUILD_BUG_ON(WBT_NR_BITS > BLK_STAT_RES_BITS);
rwb = kzalloc(sizeof(*rwb), GFP_KERNEL);
if (!rwb)
return -ENOMEM;
for (i = 0; i < WBT_NUM_RWQ; i++) {
atomic_set(&rwb->rq_wait[i].inflight, 0);
init_waitqueue_head(&rwb->rq_wait[i].wait);
}
setup_timer(&rwb->window_timer, wb_timer_fn, (unsigned long) rwb);
rwb->wc = 1;
rwb->queue_depth = RWB_DEF_DEPTH;
rwb->last_comp = rwb->last_issue = jiffies;
rwb->queue = q;
rwb->win_nsec = RWB_WINDOW_NSEC;
rwb->enable_state = WBT_STATE_ON_DEFAULT;
wbt_update_limits(rwb);
q->rq_wb = rwb;
blk_stat_enable(q);
rwb->min_lat_nsec = wbt_default_latency_nsec(q);
wbt_set_queue_depth(rwb, blk_queue_depth(q));
wbt_set_write_cache(rwb, test_bit(QUEUE_FLAG_WC, &q->queue_flags));
return 0;
}
void wbt_exit(struct request_queue *q)
{
struct rq_wb *rwb = q->rq_wb;
if (rwb) {
del_timer_sync(&rwb->window_timer);
q->rq_wb = NULL;
kfree(rwb);
}
}
