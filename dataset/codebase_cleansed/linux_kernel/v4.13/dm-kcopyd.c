static void io_job_start(struct dm_kcopyd_throttle *t)
{
unsigned throttle, now, difference;
int slept = 0, skew;
if (unlikely(!t))
return;
try_again:
spin_lock_irq(&throttle_spinlock);
throttle = ACCESS_ONCE(t->throttle);
if (likely(throttle >= 100))
goto skip_limit;
now = jiffies;
difference = now - t->last_jiffies;
t->last_jiffies = now;
if (t->num_io_jobs)
t->io_period += difference;
t->total_period += difference;
if (unlikely(t->io_period > t->total_period))
t->io_period = t->total_period;
if (unlikely(t->total_period >= (1 << ACCOUNT_INTERVAL_SHIFT))) {
int shift = fls(t->total_period >> ACCOUNT_INTERVAL_SHIFT);
t->total_period >>= shift;
t->io_period >>= shift;
}
skew = t->io_period - throttle * t->total_period / 100;
if (unlikely(skew > 0) && slept < MAX_SLEEPS) {
slept++;
spin_unlock_irq(&throttle_spinlock);
msleep(SLEEP_MSEC);
goto try_again;
}
skip_limit:
t->num_io_jobs++;
spin_unlock_irq(&throttle_spinlock);
}
static void io_job_finish(struct dm_kcopyd_throttle *t)
{
unsigned long flags;
if (unlikely(!t))
return;
spin_lock_irqsave(&throttle_spinlock, flags);
t->num_io_jobs--;
if (likely(ACCESS_ONCE(t->throttle) >= 100))
goto skip_limit;
if (!t->num_io_jobs) {
unsigned now, difference;
now = jiffies;
difference = now - t->last_jiffies;
t->last_jiffies = now;
t->io_period += difference;
t->total_period += difference;
if (unlikely(t->io_period > t->total_period))
t->io_period = t->total_period;
}
skip_limit:
spin_unlock_irqrestore(&throttle_spinlock, flags);
}
static void wake(struct dm_kcopyd_client *kc)
{
queue_work(kc->kcopyd_wq, &kc->kcopyd_work);
}
static struct page_list *alloc_pl(gfp_t gfp)
{
struct page_list *pl;
pl = kmalloc(sizeof(*pl), gfp);
if (!pl)
return NULL;
pl->page = alloc_page(gfp);
if (!pl->page) {
kfree(pl);
return NULL;
}
return pl;
}
static void free_pl(struct page_list *pl)
{
__free_page(pl->page);
kfree(pl);
}
static void kcopyd_put_pages(struct dm_kcopyd_client *kc, struct page_list *pl)
{
struct page_list *next;
do {
next = pl->next;
if (kc->nr_free_pages >= kc->nr_reserved_pages)
free_pl(pl);
else {
pl->next = kc->pages;
kc->pages = pl;
kc->nr_free_pages++;
}
pl = next;
} while (pl);
}
static int kcopyd_get_pages(struct dm_kcopyd_client *kc,
unsigned int nr, struct page_list **pages)
{
struct page_list *pl;
*pages = NULL;
do {
pl = alloc_pl(__GFP_NOWARN | __GFP_NORETRY | __GFP_KSWAPD_RECLAIM);
if (unlikely(!pl)) {
pl = kc->pages;
if (unlikely(!pl))
goto out_of_memory;
kc->pages = pl->next;
kc->nr_free_pages--;
}
pl->next = *pages;
*pages = pl;
} while (--nr);
return 0;
out_of_memory:
if (*pages)
kcopyd_put_pages(kc, *pages);
return -ENOMEM;
}
static void drop_pages(struct page_list *pl)
{
struct page_list *next;
while (pl) {
next = pl->next;
free_pl(pl);
pl = next;
}
}
static int client_reserve_pages(struct dm_kcopyd_client *kc, unsigned nr_pages)
{
unsigned i;
struct page_list *pl = NULL, *next;
for (i = 0; i < nr_pages; i++) {
next = alloc_pl(GFP_KERNEL);
if (!next) {
if (pl)
drop_pages(pl);
return -ENOMEM;
}
next->next = pl;
pl = next;
}
kc->nr_reserved_pages += nr_pages;
kcopyd_put_pages(kc, pl);
return 0;
}
static void client_free_pages(struct dm_kcopyd_client *kc)
{
BUG_ON(kc->nr_free_pages != kc->nr_reserved_pages);
drop_pages(kc->pages);
kc->pages = NULL;
kc->nr_free_pages = kc->nr_reserved_pages = 0;
}
int __init dm_kcopyd_init(void)
{
_job_cache = kmem_cache_create("kcopyd_job",
sizeof(struct kcopyd_job) * (SPLIT_COUNT + 1),
__alignof__(struct kcopyd_job), 0, NULL);
if (!_job_cache)
return -ENOMEM;
zero_page_list.next = &zero_page_list;
zero_page_list.page = ZERO_PAGE(0);
return 0;
}
void dm_kcopyd_exit(void)
{
kmem_cache_destroy(_job_cache);
_job_cache = NULL;
}
static struct kcopyd_job *pop_io_job(struct list_head *jobs,
struct dm_kcopyd_client *kc)
{
struct kcopyd_job *job;
list_for_each_entry(job, jobs, list) {
if (job->rw == READ || !test_bit(DM_KCOPYD_WRITE_SEQ, &job->flags)) {
list_del(&job->list);
return job;
}
if (job->write_offset == job->master_job->write_offset) {
job->master_job->write_offset += job->source.count;
list_del(&job->list);
return job;
}
}
return NULL;
}
static struct kcopyd_job *pop(struct list_head *jobs,
struct dm_kcopyd_client *kc)
{
struct kcopyd_job *job = NULL;
unsigned long flags;
spin_lock_irqsave(&kc->job_lock, flags);
if (!list_empty(jobs)) {
if (jobs == &kc->io_jobs)
job = pop_io_job(jobs, kc);
else {
job = list_entry(jobs->next, struct kcopyd_job, list);
list_del(&job->list);
}
}
spin_unlock_irqrestore(&kc->job_lock, flags);
return job;
}
static void push(struct list_head *jobs, struct kcopyd_job *job)
{
unsigned long flags;
struct dm_kcopyd_client *kc = job->kc;
spin_lock_irqsave(&kc->job_lock, flags);
list_add_tail(&job->list, jobs);
spin_unlock_irqrestore(&kc->job_lock, flags);
}
static void push_head(struct list_head *jobs, struct kcopyd_job *job)
{
unsigned long flags;
struct dm_kcopyd_client *kc = job->kc;
spin_lock_irqsave(&kc->job_lock, flags);
list_add(&job->list, jobs);
spin_unlock_irqrestore(&kc->job_lock, flags);
}
static int run_complete_job(struct kcopyd_job *job)
{
void *context = job->context;
int read_err = job->read_err;
unsigned long write_err = job->write_err;
dm_kcopyd_notify_fn fn = job->fn;
struct dm_kcopyd_client *kc = job->kc;
if (job->pages && job->pages != &zero_page_list)
kcopyd_put_pages(kc, job->pages);
if (job->master_job == job)
mempool_free(job, kc->job_pool);
fn(read_err, write_err, context);
if (atomic_dec_and_test(&kc->nr_jobs))
wake_up(&kc->destroyq);
return 0;
}
static void complete_io(unsigned long error, void *context)
{
struct kcopyd_job *job = (struct kcopyd_job *) context;
struct dm_kcopyd_client *kc = job->kc;
io_job_finish(kc->throttle);
if (error) {
if (op_is_write(job->rw))
job->write_err |= error;
else
job->read_err = 1;
if (!test_bit(DM_KCOPYD_IGNORE_ERROR, &job->flags)) {
push(&kc->complete_jobs, job);
wake(kc);
return;
}
}
if (op_is_write(job->rw))
push(&kc->complete_jobs, job);
else {
job->rw = WRITE;
push(&kc->io_jobs, job);
}
wake(kc);
}
static int run_io_job(struct kcopyd_job *job)
{
int r;
struct dm_io_request io_req = {
.bi_op = job->rw,
.bi_op_flags = 0,
.mem.type = DM_IO_PAGE_LIST,
.mem.ptr.pl = job->pages,
.mem.offset = 0,
.notify.fn = complete_io,
.notify.context = job,
.client = job->kc->io_client,
};
if (test_bit(DM_KCOPYD_WRITE_SEQ, &job->flags) &&
job->master_job->write_err)
return -EIO;
io_job_start(job->kc->throttle);
if (job->rw == READ)
r = dm_io(&io_req, 1, &job->source, NULL);
else
r = dm_io(&io_req, job->num_dests, job->dests, NULL);
return r;
}
static int run_pages_job(struct kcopyd_job *job)
{
int r;
unsigned nr_pages = dm_div_up(job->dests[0].count, PAGE_SIZE >> 9);
r = kcopyd_get_pages(job->kc, nr_pages, &job->pages);
if (!r) {
push(&job->kc->io_jobs, job);
return 0;
}
if (r == -ENOMEM)
return 1;
return r;
}
static int process_jobs(struct list_head *jobs, struct dm_kcopyd_client *kc,
int (*fn) (struct kcopyd_job *))
{
struct kcopyd_job *job;
int r, count = 0;
while ((job = pop(jobs, kc))) {
r = fn(job);
if (r < 0) {
if (op_is_write(job->rw))
job->write_err = (unsigned long) -1L;
else
job->read_err = 1;
push(&kc->complete_jobs, job);
break;
}
if (r > 0) {
push_head(jobs, job);
break;
}
count++;
}
return count;
}
static void do_work(struct work_struct *work)
{
struct dm_kcopyd_client *kc = container_of(work,
struct dm_kcopyd_client, kcopyd_work);
struct blk_plug plug;
blk_start_plug(&plug);
process_jobs(&kc->complete_jobs, kc, run_complete_job);
process_jobs(&kc->pages_jobs, kc, run_pages_job);
process_jobs(&kc->io_jobs, kc, run_io_job);
blk_finish_plug(&plug);
}
static void dispatch_job(struct kcopyd_job *job)
{
struct dm_kcopyd_client *kc = job->kc;
atomic_inc(&kc->nr_jobs);
if (unlikely(!job->source.count))
push(&kc->complete_jobs, job);
else if (job->pages == &zero_page_list)
push(&kc->io_jobs, job);
else
push(&kc->pages_jobs, job);
wake(kc);
}
static void segment_complete(int read_err, unsigned long write_err,
void *context)
{
sector_t progress = 0;
sector_t count = 0;
struct kcopyd_job *sub_job = (struct kcopyd_job *) context;
struct kcopyd_job *job = sub_job->master_job;
struct dm_kcopyd_client *kc = job->kc;
mutex_lock(&job->lock);
if (read_err)
job->read_err = 1;
if (write_err)
job->write_err |= write_err;
if ((!job->read_err && !job->write_err) ||
test_bit(DM_KCOPYD_IGNORE_ERROR, &job->flags)) {
progress = job->progress;
count = job->source.count - progress;
if (count) {
if (count > SUB_JOB_SIZE)
count = SUB_JOB_SIZE;
job->progress += count;
}
}
mutex_unlock(&job->lock);
if (count) {
int i;
*sub_job = *job;
sub_job->write_offset = progress;
sub_job->source.sector += progress;
sub_job->source.count = count;
for (i = 0; i < job->num_dests; i++) {
sub_job->dests[i].sector += progress;
sub_job->dests[i].count = count;
}
sub_job->fn = segment_complete;
sub_job->context = sub_job;
dispatch_job(sub_job);
} else if (atomic_dec_and_test(&job->sub_jobs)) {
push(&kc->complete_jobs, job);
wake(kc);
}
}
static void split_job(struct kcopyd_job *master_job)
{
int i;
atomic_inc(&master_job->kc->nr_jobs);
atomic_set(&master_job->sub_jobs, SPLIT_COUNT);
for (i = 0; i < SPLIT_COUNT; i++) {
master_job[i + 1].master_job = master_job;
segment_complete(0, 0u, &master_job[i + 1]);
}
}
int dm_kcopyd_copy(struct dm_kcopyd_client *kc, struct dm_io_region *from,
unsigned int num_dests, struct dm_io_region *dests,
unsigned int flags, dm_kcopyd_notify_fn fn, void *context)
{
struct kcopyd_job *job;
int i;
job = mempool_alloc(kc->job_pool, GFP_NOIO);
job->kc = kc;
job->flags = flags;
job->read_err = 0;
job->write_err = 0;
job->num_dests = num_dests;
memcpy(&job->dests, dests, sizeof(*dests) * num_dests);
if (!test_bit(DM_KCOPYD_WRITE_SEQ, &job->flags)) {
for (i = 0; i < job->num_dests; i++) {
if (bdev_zoned_model(dests[i].bdev) == BLK_ZONED_HM) {
set_bit(DM_KCOPYD_WRITE_SEQ, &job->flags);
break;
}
}
}
if (test_bit(DM_KCOPYD_WRITE_SEQ, &job->flags) &&
test_bit(DM_KCOPYD_IGNORE_ERROR, &job->flags))
clear_bit(DM_KCOPYD_IGNORE_ERROR, &job->flags);
if (from) {
job->source = *from;
job->pages = NULL;
job->rw = READ;
} else {
memset(&job->source, 0, sizeof job->source);
job->source.count = job->dests[0].count;
job->pages = &zero_page_list;
job->rw = REQ_OP_WRITE_ZEROES;
for (i = 0; i < job->num_dests; i++)
if (!bdev_write_zeroes_sectors(job->dests[i].bdev)) {
job->rw = WRITE;
break;
}
}
job->fn = fn;
job->context = context;
job->master_job = job;
job->write_offset = 0;
if (job->source.count <= SUB_JOB_SIZE)
dispatch_job(job);
else {
mutex_init(&job->lock);
job->progress = 0;
split_job(job);
}
return 0;
}
int dm_kcopyd_zero(struct dm_kcopyd_client *kc,
unsigned num_dests, struct dm_io_region *dests,
unsigned flags, dm_kcopyd_notify_fn fn, void *context)
{
return dm_kcopyd_copy(kc, NULL, num_dests, dests, flags, fn, context);
}
void *dm_kcopyd_prepare_callback(struct dm_kcopyd_client *kc,
dm_kcopyd_notify_fn fn, void *context)
{
struct kcopyd_job *job;
job = mempool_alloc(kc->job_pool, GFP_NOIO);
memset(job, 0, sizeof(struct kcopyd_job));
job->kc = kc;
job->fn = fn;
job->context = context;
job->master_job = job;
atomic_inc(&kc->nr_jobs);
return job;
}
void dm_kcopyd_do_callback(void *j, int read_err, unsigned long write_err)
{
struct kcopyd_job *job = j;
struct dm_kcopyd_client *kc = job->kc;
job->read_err = read_err;
job->write_err = write_err;
push(&kc->complete_jobs, job);
wake(kc);
}
struct dm_kcopyd_client *dm_kcopyd_client_create(struct dm_kcopyd_throttle *throttle)
{
int r = -ENOMEM;
struct dm_kcopyd_client *kc;
kc = kmalloc(sizeof(*kc), GFP_KERNEL);
if (!kc)
return ERR_PTR(-ENOMEM);
spin_lock_init(&kc->job_lock);
INIT_LIST_HEAD(&kc->complete_jobs);
INIT_LIST_HEAD(&kc->io_jobs);
INIT_LIST_HEAD(&kc->pages_jobs);
kc->throttle = throttle;
kc->job_pool = mempool_create_slab_pool(MIN_JOBS, _job_cache);
if (!kc->job_pool)
goto bad_slab;
INIT_WORK(&kc->kcopyd_work, do_work);
kc->kcopyd_wq = alloc_workqueue("kcopyd", WQ_MEM_RECLAIM, 0);
if (!kc->kcopyd_wq)
goto bad_workqueue;
kc->pages = NULL;
kc->nr_reserved_pages = kc->nr_free_pages = 0;
r = client_reserve_pages(kc, RESERVE_PAGES);
if (r)
goto bad_client_pages;
kc->io_client = dm_io_client_create();
if (IS_ERR(kc->io_client)) {
r = PTR_ERR(kc->io_client);
goto bad_io_client;
}
init_waitqueue_head(&kc->destroyq);
atomic_set(&kc->nr_jobs, 0);
return kc;
bad_io_client:
client_free_pages(kc);
bad_client_pages:
destroy_workqueue(kc->kcopyd_wq);
bad_workqueue:
mempool_destroy(kc->job_pool);
bad_slab:
kfree(kc);
return ERR_PTR(r);
}
void dm_kcopyd_client_destroy(struct dm_kcopyd_client *kc)
{
wait_event(kc->destroyq, !atomic_read(&kc->nr_jobs));
BUG_ON(!list_empty(&kc->complete_jobs));
BUG_ON(!list_empty(&kc->io_jobs));
BUG_ON(!list_empty(&kc->pages_jobs));
destroy_workqueue(kc->kcopyd_wq);
dm_io_client_destroy(kc->io_client);
client_free_pages(kc);
mempool_destroy(kc->job_pool);
kfree(kc);
}
