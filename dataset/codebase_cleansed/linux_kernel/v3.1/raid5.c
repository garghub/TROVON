static inline int raid5_bi_phys_segments(struct bio *bio)
{
return bio->bi_phys_segments & 0xffff;
}
static inline int raid5_bi_hw_segments(struct bio *bio)
{
return (bio->bi_phys_segments >> 16) & 0xffff;
}
static inline int raid5_dec_bi_phys_segments(struct bio *bio)
{
--bio->bi_phys_segments;
return raid5_bi_phys_segments(bio);
}
static inline int raid5_dec_bi_hw_segments(struct bio *bio)
{
unsigned short val = raid5_bi_hw_segments(bio);
--val;
bio->bi_phys_segments = (val << 16) | raid5_bi_phys_segments(bio);
return val;
}
static inline void raid5_set_bi_hw_segments(struct bio *bio, unsigned int cnt)
{
bio->bi_phys_segments = raid5_bi_phys_segments(bio) | (cnt << 16);
}
static inline int raid6_d0(struct stripe_head *sh)
{
if (sh->ddf_layout)
return 0;
if (sh->qd_idx == sh->disks - 1)
return 0;
else
return sh->qd_idx + 1;
}
static inline int raid6_next_disk(int disk, int raid_disks)
{
disk++;
return (disk < raid_disks) ? disk : 0;
}
static int raid6_idx_to_slot(int idx, struct stripe_head *sh,
int *count, int syndrome_disks)
{
int slot = *count;
if (sh->ddf_layout)
(*count)++;
if (idx == sh->pd_idx)
return syndrome_disks;
if (idx == sh->qd_idx)
return syndrome_disks + 1;
if (!sh->ddf_layout)
(*count)++;
return slot;
}
static void return_io(struct bio *return_bi)
{
struct bio *bi = return_bi;
while (bi) {
return_bi = bi->bi_next;
bi->bi_next = NULL;
bi->bi_size = 0;
bio_endio(bi, 0);
bi = return_bi;
}
}
static int stripe_operations_active(struct stripe_head *sh)
{
return sh->check_state || sh->reconstruct_state ||
test_bit(STRIPE_BIOFILL_RUN, &sh->state) ||
test_bit(STRIPE_COMPUTE_RUN, &sh->state);
}
static void __release_stripe(raid5_conf_t *conf, struct stripe_head *sh)
{
if (atomic_dec_and_test(&sh->count)) {
BUG_ON(!list_empty(&sh->lru));
BUG_ON(atomic_read(&conf->active_stripes)==0);
if (test_bit(STRIPE_HANDLE, &sh->state)) {
if (test_bit(STRIPE_DELAYED, &sh->state))
list_add_tail(&sh->lru, &conf->delayed_list);
else if (test_bit(STRIPE_BIT_DELAY, &sh->state) &&
sh->bm_seq - conf->seq_write > 0)
list_add_tail(&sh->lru, &conf->bitmap_list);
else {
clear_bit(STRIPE_BIT_DELAY, &sh->state);
list_add_tail(&sh->lru, &conf->handle_list);
}
md_wakeup_thread(conf->mddev->thread);
} else {
BUG_ON(stripe_operations_active(sh));
if (test_and_clear_bit(STRIPE_PREREAD_ACTIVE, &sh->state)) {
atomic_dec(&conf->preread_active_stripes);
if (atomic_read(&conf->preread_active_stripes) < IO_THRESHOLD)
md_wakeup_thread(conf->mddev->thread);
}
atomic_dec(&conf->active_stripes);
if (!test_bit(STRIPE_EXPANDING, &sh->state)) {
list_add_tail(&sh->lru, &conf->inactive_list);
wake_up(&conf->wait_for_stripe);
if (conf->retry_read_aligned)
md_wakeup_thread(conf->mddev->thread);
}
}
}
}
static void release_stripe(struct stripe_head *sh)
{
raid5_conf_t *conf = sh->raid_conf;
unsigned long flags;
spin_lock_irqsave(&conf->device_lock, flags);
__release_stripe(conf, sh);
spin_unlock_irqrestore(&conf->device_lock, flags);
}
static inline void remove_hash(struct stripe_head *sh)
{
pr_debug("remove_hash(), stripe %llu\n",
(unsigned long long)sh->sector);
hlist_del_init(&sh->hash);
}
static inline void insert_hash(raid5_conf_t *conf, struct stripe_head *sh)
{
struct hlist_head *hp = stripe_hash(conf, sh->sector);
pr_debug("insert_hash(), stripe %llu\n",
(unsigned long long)sh->sector);
CHECK_DEVLOCK();
hlist_add_head(&sh->hash, hp);
}
static struct stripe_head *get_free_stripe(raid5_conf_t *conf)
{
struct stripe_head *sh = NULL;
struct list_head *first;
CHECK_DEVLOCK();
if (list_empty(&conf->inactive_list))
goto out;
first = conf->inactive_list.next;
sh = list_entry(first, struct stripe_head, lru);
list_del_init(first);
remove_hash(sh);
atomic_inc(&conf->active_stripes);
out:
return sh;
}
static void shrink_buffers(struct stripe_head *sh)
{
struct page *p;
int i;
int num = sh->raid_conf->pool_size;
for (i = 0; i < num ; i++) {
p = sh->dev[i].page;
if (!p)
continue;
sh->dev[i].page = NULL;
put_page(p);
}
}
static int grow_buffers(struct stripe_head *sh)
{
int i;
int num = sh->raid_conf->pool_size;
for (i = 0; i < num; i++) {
struct page *page;
if (!(page = alloc_page(GFP_KERNEL))) {
return 1;
}
sh->dev[i].page = page;
}
return 0;
}
static void init_stripe(struct stripe_head *sh, sector_t sector, int previous)
{
raid5_conf_t *conf = sh->raid_conf;
int i;
BUG_ON(atomic_read(&sh->count) != 0);
BUG_ON(test_bit(STRIPE_HANDLE, &sh->state));
BUG_ON(stripe_operations_active(sh));
CHECK_DEVLOCK();
pr_debug("init_stripe called, stripe %llu\n",
(unsigned long long)sh->sector);
remove_hash(sh);
sh->generation = conf->generation - previous;
sh->disks = previous ? conf->previous_raid_disks : conf->raid_disks;
sh->sector = sector;
stripe_set_idx(sector, conf, previous, sh);
sh->state = 0;
for (i = sh->disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (dev->toread || dev->read || dev->towrite || dev->written ||
test_bit(R5_LOCKED, &dev->flags)) {
printk(KERN_ERR "sector=%llx i=%d %p %p %p %p %d\n",
(unsigned long long)sh->sector, i, dev->toread,
dev->read, dev->towrite, dev->written,
test_bit(R5_LOCKED, &dev->flags));
WARN_ON(1);
}
dev->flags = 0;
raid5_build_block(sh, i, previous);
}
insert_hash(conf, sh);
}
static struct stripe_head *__find_stripe(raid5_conf_t *conf, sector_t sector,
short generation)
{
struct stripe_head *sh;
struct hlist_node *hn;
CHECK_DEVLOCK();
pr_debug("__find_stripe, sector %llu\n", (unsigned long long)sector);
hlist_for_each_entry(sh, hn, stripe_hash(conf, sector), hash)
if (sh->sector == sector && sh->generation == generation)
return sh;
pr_debug("__stripe %llu not in cache\n", (unsigned long long)sector);
return NULL;
}
static int has_failed(raid5_conf_t *conf)
{
int degraded;
int i;
if (conf->mddev->reshape_position == MaxSector)
return conf->mddev->degraded > conf->max_degraded;
rcu_read_lock();
degraded = 0;
for (i = 0; i < conf->previous_raid_disks; i++) {
mdk_rdev_t *rdev = rcu_dereference(conf->disks[i].rdev);
if (!rdev || test_bit(Faulty, &rdev->flags))
degraded++;
else if (test_bit(In_sync, &rdev->flags))
;
else
if (conf->raid_disks >= conf->previous_raid_disks)
degraded++;
}
rcu_read_unlock();
if (degraded > conf->max_degraded)
return 1;
rcu_read_lock();
degraded = 0;
for (i = 0; i < conf->raid_disks; i++) {
mdk_rdev_t *rdev = rcu_dereference(conf->disks[i].rdev);
if (!rdev || test_bit(Faulty, &rdev->flags))
degraded++;
else if (test_bit(In_sync, &rdev->flags))
;
else
if (conf->raid_disks <= conf->previous_raid_disks)
degraded++;
}
rcu_read_unlock();
if (degraded > conf->max_degraded)
return 1;
return 0;
}
static struct stripe_head *
get_active_stripe(raid5_conf_t *conf, sector_t sector,
int previous, int noblock, int noquiesce)
{
struct stripe_head *sh;
pr_debug("get_stripe, sector %llu\n", (unsigned long long)sector);
spin_lock_irq(&conf->device_lock);
do {
wait_event_lock_irq(conf->wait_for_stripe,
conf->quiesce == 0 || noquiesce,
conf->device_lock, );
sh = __find_stripe(conf, sector, conf->generation - previous);
if (!sh) {
if (!conf->inactive_blocked)
sh = get_free_stripe(conf);
if (noblock && sh == NULL)
break;
if (!sh) {
conf->inactive_blocked = 1;
wait_event_lock_irq(conf->wait_for_stripe,
!list_empty(&conf->inactive_list) &&
(atomic_read(&conf->active_stripes)
< (conf->max_nr_stripes *3/4)
|| !conf->inactive_blocked),
conf->device_lock,
);
conf->inactive_blocked = 0;
} else
init_stripe(sh, sector, previous);
} else {
if (atomic_read(&sh->count)) {
BUG_ON(!list_empty(&sh->lru)
&& !test_bit(STRIPE_EXPANDING, &sh->state));
} else {
if (!test_bit(STRIPE_HANDLE, &sh->state))
atomic_inc(&conf->active_stripes);
if (list_empty(&sh->lru) &&
!test_bit(STRIPE_EXPANDING, &sh->state))
BUG();
list_del_init(&sh->lru);
}
}
} while (sh == NULL);
if (sh)
atomic_inc(&sh->count);
spin_unlock_irq(&conf->device_lock);
return sh;
}
static void ops_run_io(struct stripe_head *sh, struct stripe_head_state *s)
{
raid5_conf_t *conf = sh->raid_conf;
int i, disks = sh->disks;
might_sleep();
for (i = disks; i--; ) {
int rw;
struct bio *bi;
mdk_rdev_t *rdev;
if (test_and_clear_bit(R5_Wantwrite, &sh->dev[i].flags)) {
if (test_and_clear_bit(R5_WantFUA, &sh->dev[i].flags))
rw = WRITE_FUA;
else
rw = WRITE;
} else if (test_and_clear_bit(R5_Wantread, &sh->dev[i].flags))
rw = READ;
else
continue;
bi = &sh->dev[i].req;
bi->bi_rw = rw;
if (rw & WRITE)
bi->bi_end_io = raid5_end_write_request;
else
bi->bi_end_io = raid5_end_read_request;
rcu_read_lock();
rdev = rcu_dereference(conf->disks[i].rdev);
if (rdev && test_bit(Faulty, &rdev->flags))
rdev = NULL;
if (rdev)
atomic_inc(&rdev->nr_pending);
rcu_read_unlock();
while ((rw & WRITE) && rdev &&
test_bit(WriteErrorSeen, &rdev->flags)) {
sector_t first_bad;
int bad_sectors;
int bad = is_badblock(rdev, sh->sector, STRIPE_SECTORS,
&first_bad, &bad_sectors);
if (!bad)
break;
if (bad < 0) {
set_bit(BlockedBadBlocks, &rdev->flags);
if (!conf->mddev->external &&
conf->mddev->flags) {
md_check_recovery(conf->mddev);
}
md_wait_for_blocked_rdev(rdev, conf->mddev);
} else {
rdev_dec_pending(rdev, conf->mddev);
rdev = NULL;
}
}
if (rdev) {
if (s->syncing || s->expanding || s->expanded)
md_sync_acct(rdev->bdev, STRIPE_SECTORS);
set_bit(STRIPE_IO_STARTED, &sh->state);
bi->bi_bdev = rdev->bdev;
pr_debug("%s: for %llu schedule op %ld on disc %d\n",
__func__, (unsigned long long)sh->sector,
bi->bi_rw, i);
atomic_inc(&sh->count);
bi->bi_sector = sh->sector + rdev->data_offset;
bi->bi_flags = 1 << BIO_UPTODATE;
bi->bi_vcnt = 1;
bi->bi_max_vecs = 1;
bi->bi_idx = 0;
bi->bi_io_vec = &sh->dev[i].vec;
bi->bi_io_vec[0].bv_len = STRIPE_SIZE;
bi->bi_io_vec[0].bv_offset = 0;
bi->bi_size = STRIPE_SIZE;
bi->bi_next = NULL;
generic_make_request(bi);
} else {
if (rw & WRITE)
set_bit(STRIPE_DEGRADED, &sh->state);
pr_debug("skip op %ld on disc %d for sector %llu\n",
bi->bi_rw, i, (unsigned long long)sh->sector);
clear_bit(R5_LOCKED, &sh->dev[i].flags);
set_bit(STRIPE_HANDLE, &sh->state);
}
}
}
static struct dma_async_tx_descriptor *
async_copy_data(int frombio, struct bio *bio, struct page *page,
sector_t sector, struct dma_async_tx_descriptor *tx)
{
struct bio_vec *bvl;
struct page *bio_page;
int i;
int page_offset;
struct async_submit_ctl submit;
enum async_tx_flags flags = 0;
if (bio->bi_sector >= sector)
page_offset = (signed)(bio->bi_sector - sector) * 512;
else
page_offset = (signed)(sector - bio->bi_sector) * -512;
if (frombio)
flags |= ASYNC_TX_FENCE;
init_async_submit(&submit, flags, tx, NULL, NULL, NULL);
bio_for_each_segment(bvl, bio, i) {
int len = bvl->bv_len;
int clen;
int b_offset = 0;
if (page_offset < 0) {
b_offset = -page_offset;
page_offset += b_offset;
len -= b_offset;
}
if (len > 0 && page_offset + len > STRIPE_SIZE)
clen = STRIPE_SIZE - page_offset;
else
clen = len;
if (clen > 0) {
b_offset += bvl->bv_offset;
bio_page = bvl->bv_page;
if (frombio)
tx = async_memcpy(page, bio_page, page_offset,
b_offset, clen, &submit);
else
tx = async_memcpy(bio_page, page, b_offset,
page_offset, clen, &submit);
}
submit.depend_tx = tx;
if (clen < len)
break;
page_offset += len;
}
return tx;
}
static void ops_complete_biofill(void *stripe_head_ref)
{
struct stripe_head *sh = stripe_head_ref;
struct bio *return_bi = NULL;
raid5_conf_t *conf = sh->raid_conf;
int i;
pr_debug("%s: stripe %llu\n", __func__,
(unsigned long long)sh->sector);
spin_lock_irq(&conf->device_lock);
for (i = sh->disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (test_and_clear_bit(R5_Wantfill, &dev->flags)) {
struct bio *rbi, *rbi2;
BUG_ON(!dev->read);
rbi = dev->read;
dev->read = NULL;
while (rbi && rbi->bi_sector <
dev->sector + STRIPE_SECTORS) {
rbi2 = r5_next_bio(rbi, dev->sector);
if (!raid5_dec_bi_phys_segments(rbi)) {
rbi->bi_next = return_bi;
return_bi = rbi;
}
rbi = rbi2;
}
}
}
spin_unlock_irq(&conf->device_lock);
clear_bit(STRIPE_BIOFILL_RUN, &sh->state);
return_io(return_bi);
set_bit(STRIPE_HANDLE, &sh->state);
release_stripe(sh);
}
static void ops_run_biofill(struct stripe_head *sh)
{
struct dma_async_tx_descriptor *tx = NULL;
raid5_conf_t *conf = sh->raid_conf;
struct async_submit_ctl submit;
int i;
pr_debug("%s: stripe %llu\n", __func__,
(unsigned long long)sh->sector);
for (i = sh->disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (test_bit(R5_Wantfill, &dev->flags)) {
struct bio *rbi;
spin_lock_irq(&conf->device_lock);
dev->read = rbi = dev->toread;
dev->toread = NULL;
spin_unlock_irq(&conf->device_lock);
while (rbi && rbi->bi_sector <
dev->sector + STRIPE_SECTORS) {
tx = async_copy_data(0, rbi, dev->page,
dev->sector, tx);
rbi = r5_next_bio(rbi, dev->sector);
}
}
}
atomic_inc(&sh->count);
init_async_submit(&submit, ASYNC_TX_ACK, tx, ops_complete_biofill, sh, NULL);
async_trigger_callback(&submit);
}
static void mark_target_uptodate(struct stripe_head *sh, int target)
{
struct r5dev *tgt;
if (target < 0)
return;
tgt = &sh->dev[target];
set_bit(R5_UPTODATE, &tgt->flags);
BUG_ON(!test_bit(R5_Wantcompute, &tgt->flags));
clear_bit(R5_Wantcompute, &tgt->flags);
}
static void ops_complete_compute(void *stripe_head_ref)
{
struct stripe_head *sh = stripe_head_ref;
pr_debug("%s: stripe %llu\n", __func__,
(unsigned long long)sh->sector);
mark_target_uptodate(sh, sh->ops.target);
mark_target_uptodate(sh, sh->ops.target2);
clear_bit(STRIPE_COMPUTE_RUN, &sh->state);
if (sh->check_state == check_state_compute_run)
sh->check_state = check_state_compute_result;
set_bit(STRIPE_HANDLE, &sh->state);
release_stripe(sh);
}
static addr_conv_t *to_addr_conv(struct stripe_head *sh,
struct raid5_percpu *percpu)
{
return percpu->scribble + sizeof(struct page *) * (sh->disks + 2);
}
static struct dma_async_tx_descriptor *
ops_run_compute5(struct stripe_head *sh, struct raid5_percpu *percpu)
{
int disks = sh->disks;
struct page **xor_srcs = percpu->scribble;
int target = sh->ops.target;
struct r5dev *tgt = &sh->dev[target];
struct page *xor_dest = tgt->page;
int count = 0;
struct dma_async_tx_descriptor *tx;
struct async_submit_ctl submit;
int i;
pr_debug("%s: stripe %llu block: %d\n",
__func__, (unsigned long long)sh->sector, target);
BUG_ON(!test_bit(R5_Wantcompute, &tgt->flags));
for (i = disks; i--; )
if (i != target)
xor_srcs[count++] = sh->dev[i].page;
atomic_inc(&sh->count);
init_async_submit(&submit, ASYNC_TX_FENCE|ASYNC_TX_XOR_ZERO_DST, NULL,
ops_complete_compute, sh, to_addr_conv(sh, percpu));
if (unlikely(count == 1))
tx = async_memcpy(xor_dest, xor_srcs[0], 0, 0, STRIPE_SIZE, &submit);
else
tx = async_xor(xor_dest, xor_srcs, 0, count, STRIPE_SIZE, &submit);
return tx;
}
static int set_syndrome_sources(struct page **srcs, struct stripe_head *sh)
{
int disks = sh->disks;
int syndrome_disks = sh->ddf_layout ? disks : (disks - 2);
int d0_idx = raid6_d0(sh);
int count;
int i;
for (i = 0; i < disks; i++)
srcs[i] = NULL;
count = 0;
i = d0_idx;
do {
int slot = raid6_idx_to_slot(i, sh, &count, syndrome_disks);
srcs[slot] = sh->dev[i].page;
i = raid6_next_disk(i, disks);
} while (i != d0_idx);
return syndrome_disks;
}
static struct dma_async_tx_descriptor *
ops_run_compute6_1(struct stripe_head *sh, struct raid5_percpu *percpu)
{
int disks = sh->disks;
struct page **blocks = percpu->scribble;
int target;
int qd_idx = sh->qd_idx;
struct dma_async_tx_descriptor *tx;
struct async_submit_ctl submit;
struct r5dev *tgt;
struct page *dest;
int i;
int count;
if (sh->ops.target < 0)
target = sh->ops.target2;
else if (sh->ops.target2 < 0)
target = sh->ops.target;
else
BUG();
BUG_ON(target < 0);
pr_debug("%s: stripe %llu block: %d\n",
__func__, (unsigned long long)sh->sector, target);
tgt = &sh->dev[target];
BUG_ON(!test_bit(R5_Wantcompute, &tgt->flags));
dest = tgt->page;
atomic_inc(&sh->count);
if (target == qd_idx) {
count = set_syndrome_sources(blocks, sh);
blocks[count] = NULL;
BUG_ON(blocks[count+1] != dest);
init_async_submit(&submit, ASYNC_TX_FENCE, NULL,
ops_complete_compute, sh,
to_addr_conv(sh, percpu));
tx = async_gen_syndrome(blocks, 0, count+2, STRIPE_SIZE, &submit);
} else {
count = 0;
for (i = disks; i-- ; ) {
if (i == target || i == qd_idx)
continue;
blocks[count++] = sh->dev[i].page;
}
init_async_submit(&submit, ASYNC_TX_FENCE|ASYNC_TX_XOR_ZERO_DST,
NULL, ops_complete_compute, sh,
to_addr_conv(sh, percpu));
tx = async_xor(dest, blocks, 0, count, STRIPE_SIZE, &submit);
}
return tx;
}
static struct dma_async_tx_descriptor *
ops_run_compute6_2(struct stripe_head *sh, struct raid5_percpu *percpu)
{
int i, count, disks = sh->disks;
int syndrome_disks = sh->ddf_layout ? disks : disks-2;
int d0_idx = raid6_d0(sh);
int faila = -1, failb = -1;
int target = sh->ops.target;
int target2 = sh->ops.target2;
struct r5dev *tgt = &sh->dev[target];
struct r5dev *tgt2 = &sh->dev[target2];
struct dma_async_tx_descriptor *tx;
struct page **blocks = percpu->scribble;
struct async_submit_ctl submit;
pr_debug("%s: stripe %llu block1: %d block2: %d\n",
__func__, (unsigned long long)sh->sector, target, target2);
BUG_ON(target < 0 || target2 < 0);
BUG_ON(!test_bit(R5_Wantcompute, &tgt->flags));
BUG_ON(!test_bit(R5_Wantcompute, &tgt2->flags));
for (i = 0; i < disks ; i++)
blocks[i] = NULL;
count = 0;
i = d0_idx;
do {
int slot = raid6_idx_to_slot(i, sh, &count, syndrome_disks);
blocks[slot] = sh->dev[i].page;
if (i == target)
faila = slot;
if (i == target2)
failb = slot;
i = raid6_next_disk(i, disks);
} while (i != d0_idx);
BUG_ON(faila == failb);
if (failb < faila)
swap(faila, failb);
pr_debug("%s: stripe: %llu faila: %d failb: %d\n",
__func__, (unsigned long long)sh->sector, faila, failb);
atomic_inc(&sh->count);
if (failb == syndrome_disks+1) {
if (faila == syndrome_disks) {
init_async_submit(&submit, ASYNC_TX_FENCE, NULL,
ops_complete_compute, sh,
to_addr_conv(sh, percpu));
return async_gen_syndrome(blocks, 0, syndrome_disks+2,
STRIPE_SIZE, &submit);
} else {
struct page *dest;
int data_target;
int qd_idx = sh->qd_idx;
if (target == qd_idx)
data_target = target2;
else
data_target = target;
count = 0;
for (i = disks; i-- ; ) {
if (i == data_target || i == qd_idx)
continue;
blocks[count++] = sh->dev[i].page;
}
dest = sh->dev[data_target].page;
init_async_submit(&submit,
ASYNC_TX_FENCE|ASYNC_TX_XOR_ZERO_DST,
NULL, NULL, NULL,
to_addr_conv(sh, percpu));
tx = async_xor(dest, blocks, 0, count, STRIPE_SIZE,
&submit);
count = set_syndrome_sources(blocks, sh);
init_async_submit(&submit, ASYNC_TX_FENCE, tx,
ops_complete_compute, sh,
to_addr_conv(sh, percpu));
return async_gen_syndrome(blocks, 0, count+2,
STRIPE_SIZE, &submit);
}
} else {
init_async_submit(&submit, ASYNC_TX_FENCE, NULL,
ops_complete_compute, sh,
to_addr_conv(sh, percpu));
if (failb == syndrome_disks) {
return async_raid6_datap_recov(syndrome_disks+2,
STRIPE_SIZE, faila,
blocks, &submit);
} else {
return async_raid6_2data_recov(syndrome_disks+2,
STRIPE_SIZE, faila, failb,
blocks, &submit);
}
}
}
static void ops_complete_prexor(void *stripe_head_ref)
{
struct stripe_head *sh = stripe_head_ref;
pr_debug("%s: stripe %llu\n", __func__,
(unsigned long long)sh->sector);
}
static struct dma_async_tx_descriptor *
ops_run_prexor(struct stripe_head *sh, struct raid5_percpu *percpu,
struct dma_async_tx_descriptor *tx)
{
int disks = sh->disks;
struct page **xor_srcs = percpu->scribble;
int count = 0, pd_idx = sh->pd_idx, i;
struct async_submit_ctl submit;
struct page *xor_dest = xor_srcs[count++] = sh->dev[pd_idx].page;
pr_debug("%s: stripe %llu\n", __func__,
(unsigned long long)sh->sector);
for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (test_bit(R5_Wantdrain, &dev->flags))
xor_srcs[count++] = dev->page;
}
init_async_submit(&submit, ASYNC_TX_FENCE|ASYNC_TX_XOR_DROP_DST, tx,
ops_complete_prexor, sh, to_addr_conv(sh, percpu));
tx = async_xor(xor_dest, xor_srcs, 0, count, STRIPE_SIZE, &submit);
return tx;
}
static struct dma_async_tx_descriptor *
ops_run_biodrain(struct stripe_head *sh, struct dma_async_tx_descriptor *tx)
{
int disks = sh->disks;
int i;
pr_debug("%s: stripe %llu\n", __func__,
(unsigned long long)sh->sector);
for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
struct bio *chosen;
if (test_and_clear_bit(R5_Wantdrain, &dev->flags)) {
struct bio *wbi;
spin_lock_irq(&sh->raid_conf->device_lock);
chosen = dev->towrite;
dev->towrite = NULL;
BUG_ON(dev->written);
wbi = dev->written = chosen;
spin_unlock_irq(&sh->raid_conf->device_lock);
while (wbi && wbi->bi_sector <
dev->sector + STRIPE_SECTORS) {
if (wbi->bi_rw & REQ_FUA)
set_bit(R5_WantFUA, &dev->flags);
tx = async_copy_data(1, wbi, dev->page,
dev->sector, tx);
wbi = r5_next_bio(wbi, dev->sector);
}
}
}
return tx;
}
static void ops_complete_reconstruct(void *stripe_head_ref)
{
struct stripe_head *sh = stripe_head_ref;
int disks = sh->disks;
int pd_idx = sh->pd_idx;
int qd_idx = sh->qd_idx;
int i;
bool fua = false;
pr_debug("%s: stripe %llu\n", __func__,
(unsigned long long)sh->sector);
for (i = disks; i--; )
fua |= test_bit(R5_WantFUA, &sh->dev[i].flags);
for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (dev->written || i == pd_idx || i == qd_idx) {
set_bit(R5_UPTODATE, &dev->flags);
if (fua)
set_bit(R5_WantFUA, &dev->flags);
}
}
if (sh->reconstruct_state == reconstruct_state_drain_run)
sh->reconstruct_state = reconstruct_state_drain_result;
else if (sh->reconstruct_state == reconstruct_state_prexor_drain_run)
sh->reconstruct_state = reconstruct_state_prexor_drain_result;
else {
BUG_ON(sh->reconstruct_state != reconstruct_state_run);
sh->reconstruct_state = reconstruct_state_result;
}
set_bit(STRIPE_HANDLE, &sh->state);
release_stripe(sh);
}
static void
ops_run_reconstruct5(struct stripe_head *sh, struct raid5_percpu *percpu,
struct dma_async_tx_descriptor *tx)
{
int disks = sh->disks;
struct page **xor_srcs = percpu->scribble;
struct async_submit_ctl submit;
int count = 0, pd_idx = sh->pd_idx, i;
struct page *xor_dest;
int prexor = 0;
unsigned long flags;
pr_debug("%s: stripe %llu\n", __func__,
(unsigned long long)sh->sector);
if (sh->reconstruct_state == reconstruct_state_prexor_drain_run) {
prexor = 1;
xor_dest = xor_srcs[count++] = sh->dev[pd_idx].page;
for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (dev->written)
xor_srcs[count++] = dev->page;
}
} else {
xor_dest = sh->dev[pd_idx].page;
for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (i != pd_idx)
xor_srcs[count++] = dev->page;
}
}
flags = ASYNC_TX_ACK |
(prexor ? ASYNC_TX_XOR_DROP_DST : ASYNC_TX_XOR_ZERO_DST);
atomic_inc(&sh->count);
init_async_submit(&submit, flags, tx, ops_complete_reconstruct, sh,
to_addr_conv(sh, percpu));
if (unlikely(count == 1))
tx = async_memcpy(xor_dest, xor_srcs[0], 0, 0, STRIPE_SIZE, &submit);
else
tx = async_xor(xor_dest, xor_srcs, 0, count, STRIPE_SIZE, &submit);
}
static void
ops_run_reconstruct6(struct stripe_head *sh, struct raid5_percpu *percpu,
struct dma_async_tx_descriptor *tx)
{
struct async_submit_ctl submit;
struct page **blocks = percpu->scribble;
int count;
pr_debug("%s: stripe %llu\n", __func__, (unsigned long long)sh->sector);
count = set_syndrome_sources(blocks, sh);
atomic_inc(&sh->count);
init_async_submit(&submit, ASYNC_TX_ACK, tx, ops_complete_reconstruct,
sh, to_addr_conv(sh, percpu));
async_gen_syndrome(blocks, 0, count+2, STRIPE_SIZE, &submit);
}
static void ops_complete_check(void *stripe_head_ref)
{
struct stripe_head *sh = stripe_head_ref;
pr_debug("%s: stripe %llu\n", __func__,
(unsigned long long)sh->sector);
sh->check_state = check_state_check_result;
set_bit(STRIPE_HANDLE, &sh->state);
release_stripe(sh);
}
static void ops_run_check_p(struct stripe_head *sh, struct raid5_percpu *percpu)
{
int disks = sh->disks;
int pd_idx = sh->pd_idx;
int qd_idx = sh->qd_idx;
struct page *xor_dest;
struct page **xor_srcs = percpu->scribble;
struct dma_async_tx_descriptor *tx;
struct async_submit_ctl submit;
int count;
int i;
pr_debug("%s: stripe %llu\n", __func__,
(unsigned long long)sh->sector);
count = 0;
xor_dest = sh->dev[pd_idx].page;
xor_srcs[count++] = xor_dest;
for (i = disks; i--; ) {
if (i == pd_idx || i == qd_idx)
continue;
xor_srcs[count++] = sh->dev[i].page;
}
init_async_submit(&submit, 0, NULL, NULL, NULL,
to_addr_conv(sh, percpu));
tx = async_xor_val(xor_dest, xor_srcs, 0, count, STRIPE_SIZE,
&sh->ops.zero_sum_result, &submit);
atomic_inc(&sh->count);
init_async_submit(&submit, ASYNC_TX_ACK, tx, ops_complete_check, sh, NULL);
tx = async_trigger_callback(&submit);
}
static void ops_run_check_pq(struct stripe_head *sh, struct raid5_percpu *percpu, int checkp)
{
struct page **srcs = percpu->scribble;
struct async_submit_ctl submit;
int count;
pr_debug("%s: stripe %llu checkp: %d\n", __func__,
(unsigned long long)sh->sector, checkp);
count = set_syndrome_sources(srcs, sh);
if (!checkp)
srcs[count] = NULL;
atomic_inc(&sh->count);
init_async_submit(&submit, ASYNC_TX_ACK, NULL, ops_complete_check,
sh, to_addr_conv(sh, percpu));
async_syndrome_val(srcs, 0, count+2, STRIPE_SIZE,
&sh->ops.zero_sum_result, percpu->spare_page, &submit);
}
static void __raid_run_ops(struct stripe_head *sh, unsigned long ops_request)
{
int overlap_clear = 0, i, disks = sh->disks;
struct dma_async_tx_descriptor *tx = NULL;
raid5_conf_t *conf = sh->raid_conf;
int level = conf->level;
struct raid5_percpu *percpu;
unsigned long cpu;
cpu = get_cpu();
percpu = per_cpu_ptr(conf->percpu, cpu);
if (test_bit(STRIPE_OP_BIOFILL, &ops_request)) {
ops_run_biofill(sh);
overlap_clear++;
}
if (test_bit(STRIPE_OP_COMPUTE_BLK, &ops_request)) {
if (level < 6)
tx = ops_run_compute5(sh, percpu);
else {
if (sh->ops.target2 < 0 || sh->ops.target < 0)
tx = ops_run_compute6_1(sh, percpu);
else
tx = ops_run_compute6_2(sh, percpu);
}
if (tx && !test_bit(STRIPE_OP_RECONSTRUCT, &ops_request))
async_tx_ack(tx);
}
if (test_bit(STRIPE_OP_PREXOR, &ops_request))
tx = ops_run_prexor(sh, percpu, tx);
if (test_bit(STRIPE_OP_BIODRAIN, &ops_request)) {
tx = ops_run_biodrain(sh, tx);
overlap_clear++;
}
if (test_bit(STRIPE_OP_RECONSTRUCT, &ops_request)) {
if (level < 6)
ops_run_reconstruct5(sh, percpu, tx);
else
ops_run_reconstruct6(sh, percpu, tx);
}
if (test_bit(STRIPE_OP_CHECK, &ops_request)) {
if (sh->check_state == check_state_run)
ops_run_check_p(sh, percpu);
else if (sh->check_state == check_state_run_q)
ops_run_check_pq(sh, percpu, 0);
else if (sh->check_state == check_state_run_pq)
ops_run_check_pq(sh, percpu, 1);
else
BUG();
}
if (overlap_clear)
for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (test_and_clear_bit(R5_Overlap, &dev->flags))
wake_up(&sh->raid_conf->wait_for_overlap);
}
put_cpu();
}
static void async_run_ops(void *param, async_cookie_t cookie)
{
struct stripe_head *sh = param;
unsigned long ops_request = sh->ops.request;
clear_bit_unlock(STRIPE_OPS_REQ_PENDING, &sh->state);
wake_up(&sh->ops.wait_for_ops);
__raid_run_ops(sh, ops_request);
release_stripe(sh);
}
static void raid_run_ops(struct stripe_head *sh, unsigned long ops_request)
{
wait_event(sh->ops.wait_for_ops,
!test_and_set_bit_lock(STRIPE_OPS_REQ_PENDING, &sh->state));
sh->ops.request = ops_request;
atomic_inc(&sh->count);
async_schedule(async_run_ops, sh);
}
static int grow_one_stripe(raid5_conf_t *conf)
{
struct stripe_head *sh;
sh = kmem_cache_zalloc(conf->slab_cache, GFP_KERNEL);
if (!sh)
return 0;
sh->raid_conf = conf;
#ifdef CONFIG_MULTICORE_RAID456
init_waitqueue_head(&sh->ops.wait_for_ops);
#endif
if (grow_buffers(sh)) {
shrink_buffers(sh);
kmem_cache_free(conf->slab_cache, sh);
return 0;
}
atomic_set(&sh->count, 1);
atomic_inc(&conf->active_stripes);
INIT_LIST_HEAD(&sh->lru);
release_stripe(sh);
return 1;
}
static int grow_stripes(raid5_conf_t *conf, int num)
{
struct kmem_cache *sc;
int devs = max(conf->raid_disks, conf->previous_raid_disks);
if (conf->mddev->gendisk)
sprintf(conf->cache_name[0],
"raid%d-%s", conf->level, mdname(conf->mddev));
else
sprintf(conf->cache_name[0],
"raid%d-%p", conf->level, conf->mddev);
sprintf(conf->cache_name[1], "%s-alt", conf->cache_name[0]);
conf->active_name = 0;
sc = kmem_cache_create(conf->cache_name[conf->active_name],
sizeof(struct stripe_head)+(devs-1)*sizeof(struct r5dev),
0, 0, NULL);
if (!sc)
return 1;
conf->slab_cache = sc;
conf->pool_size = devs;
while (num--)
if (!grow_one_stripe(conf))
return 1;
return 0;
}
static size_t scribble_len(int num)
{
size_t len;
len = sizeof(struct page *) * (num+2) + sizeof(addr_conv_t) * (num+2);
return len;
}
static int resize_stripes(raid5_conf_t *conf, int newsize)
{
struct stripe_head *osh, *nsh;
LIST_HEAD(newstripes);
struct disk_info *ndisks;
unsigned long cpu;
int err;
struct kmem_cache *sc;
int i;
if (newsize <= conf->pool_size)
return 0;
err = md_allow_write(conf->mddev);
if (err)
return err;
sc = kmem_cache_create(conf->cache_name[1-conf->active_name],
sizeof(struct stripe_head)+(newsize-1)*sizeof(struct r5dev),
0, 0, NULL);
if (!sc)
return -ENOMEM;
for (i = conf->max_nr_stripes; i; i--) {
nsh = kmem_cache_zalloc(sc, GFP_KERNEL);
if (!nsh)
break;
nsh->raid_conf = conf;
#ifdef CONFIG_MULTICORE_RAID456
init_waitqueue_head(&nsh->ops.wait_for_ops);
#endif
list_add(&nsh->lru, &newstripes);
}
if (i) {
while (!list_empty(&newstripes)) {
nsh = list_entry(newstripes.next, struct stripe_head, lru);
list_del(&nsh->lru);
kmem_cache_free(sc, nsh);
}
kmem_cache_destroy(sc);
return -ENOMEM;
}
list_for_each_entry(nsh, &newstripes, lru) {
spin_lock_irq(&conf->device_lock);
wait_event_lock_irq(conf->wait_for_stripe,
!list_empty(&conf->inactive_list),
conf->device_lock,
);
osh = get_free_stripe(conf);
spin_unlock_irq(&conf->device_lock);
atomic_set(&nsh->count, 1);
for(i=0; i<conf->pool_size; i++)
nsh->dev[i].page = osh->dev[i].page;
for( ; i<newsize; i++)
nsh->dev[i].page = NULL;
kmem_cache_free(conf->slab_cache, osh);
}
kmem_cache_destroy(conf->slab_cache);
ndisks = kzalloc(newsize * sizeof(struct disk_info), GFP_NOIO);
if (ndisks) {
for (i=0; i<conf->raid_disks; i++)
ndisks[i] = conf->disks[i];
kfree(conf->disks);
conf->disks = ndisks;
} else
err = -ENOMEM;
get_online_cpus();
conf->scribble_len = scribble_len(newsize);
for_each_present_cpu(cpu) {
struct raid5_percpu *percpu;
void *scribble;
percpu = per_cpu_ptr(conf->percpu, cpu);
scribble = kmalloc(conf->scribble_len, GFP_NOIO);
if (scribble) {
kfree(percpu->scribble);
percpu->scribble = scribble;
} else {
err = -ENOMEM;
break;
}
}
put_online_cpus();
while(!list_empty(&newstripes)) {
nsh = list_entry(newstripes.next, struct stripe_head, lru);
list_del_init(&nsh->lru);
for (i=conf->raid_disks; i < newsize; i++)
if (nsh->dev[i].page == NULL) {
struct page *p = alloc_page(GFP_NOIO);
nsh->dev[i].page = p;
if (!p)
err = -ENOMEM;
}
release_stripe(nsh);
}
conf->slab_cache = sc;
conf->active_name = 1-conf->active_name;
conf->pool_size = newsize;
return err;
}
static int drop_one_stripe(raid5_conf_t *conf)
{
struct stripe_head *sh;
spin_lock_irq(&conf->device_lock);
sh = get_free_stripe(conf);
spin_unlock_irq(&conf->device_lock);
if (!sh)
return 0;
BUG_ON(atomic_read(&sh->count));
shrink_buffers(sh);
kmem_cache_free(conf->slab_cache, sh);
atomic_dec(&conf->active_stripes);
return 1;
}
static void shrink_stripes(raid5_conf_t *conf)
{
while (drop_one_stripe(conf))
;
if (conf->slab_cache)
kmem_cache_destroy(conf->slab_cache);
conf->slab_cache = NULL;
}
static void raid5_end_read_request(struct bio * bi, int error)
{
struct stripe_head *sh = bi->bi_private;
raid5_conf_t *conf = sh->raid_conf;
int disks = sh->disks, i;
int uptodate = test_bit(BIO_UPTODATE, &bi->bi_flags);
char b[BDEVNAME_SIZE];
mdk_rdev_t *rdev;
for (i=0 ; i<disks; i++)
if (bi == &sh->dev[i].req)
break;
pr_debug("end_read_request %llu/%d, count: %d, uptodate %d.\n",
(unsigned long long)sh->sector, i, atomic_read(&sh->count),
uptodate);
if (i == disks) {
BUG();
return;
}
if (uptodate) {
set_bit(R5_UPTODATE, &sh->dev[i].flags);
if (test_bit(R5_ReadError, &sh->dev[i].flags)) {
rdev = conf->disks[i].rdev;
printk_ratelimited(
KERN_INFO
"md/raid:%s: read error corrected"
" (%lu sectors at %llu on %s)\n",
mdname(conf->mddev), STRIPE_SECTORS,
(unsigned long long)(sh->sector
+ rdev->data_offset),
bdevname(rdev->bdev, b));
atomic_add(STRIPE_SECTORS, &rdev->corrected_errors);
clear_bit(R5_ReadError, &sh->dev[i].flags);
clear_bit(R5_ReWrite, &sh->dev[i].flags);
}
if (atomic_read(&conf->disks[i].rdev->read_errors))
atomic_set(&conf->disks[i].rdev->read_errors, 0);
} else {
const char *bdn = bdevname(conf->disks[i].rdev->bdev, b);
int retry = 0;
rdev = conf->disks[i].rdev;
clear_bit(R5_UPTODATE, &sh->dev[i].flags);
atomic_inc(&rdev->read_errors);
if (conf->mddev->degraded >= conf->max_degraded)
printk_ratelimited(
KERN_WARNING
"md/raid:%s: read error not correctable "
"(sector %llu on %s).\n",
mdname(conf->mddev),
(unsigned long long)(sh->sector
+ rdev->data_offset),
bdn);
else if (test_bit(R5_ReWrite, &sh->dev[i].flags))
printk_ratelimited(
KERN_WARNING
"md/raid:%s: read error NOT corrected!! "
"(sector %llu on %s).\n",
mdname(conf->mddev),
(unsigned long long)(sh->sector
+ rdev->data_offset),
bdn);
else if (atomic_read(&rdev->read_errors)
> conf->max_nr_stripes)
printk(KERN_WARNING
"md/raid:%s: Too many read errors, failing device %s.\n",
mdname(conf->mddev), bdn);
else
retry = 1;
if (retry)
set_bit(R5_ReadError, &sh->dev[i].flags);
else {
clear_bit(R5_ReadError, &sh->dev[i].flags);
clear_bit(R5_ReWrite, &sh->dev[i].flags);
md_error(conf->mddev, rdev);
}
}
rdev_dec_pending(conf->disks[i].rdev, conf->mddev);
clear_bit(R5_LOCKED, &sh->dev[i].flags);
set_bit(STRIPE_HANDLE, &sh->state);
release_stripe(sh);
}
static void raid5_end_write_request(struct bio *bi, int error)
{
struct stripe_head *sh = bi->bi_private;
raid5_conf_t *conf = sh->raid_conf;
int disks = sh->disks, i;
int uptodate = test_bit(BIO_UPTODATE, &bi->bi_flags);
sector_t first_bad;
int bad_sectors;
for (i=0 ; i<disks; i++)
if (bi == &sh->dev[i].req)
break;
pr_debug("end_write_request %llu/%d, count %d, uptodate: %d.\n",
(unsigned long long)sh->sector, i, atomic_read(&sh->count),
uptodate);
if (i == disks) {
BUG();
return;
}
if (!uptodate) {
set_bit(WriteErrorSeen, &conf->disks[i].rdev->flags);
set_bit(R5_WriteError, &sh->dev[i].flags);
} else if (is_badblock(conf->disks[i].rdev, sh->sector, STRIPE_SECTORS,
&first_bad, &bad_sectors))
set_bit(R5_MadeGood, &sh->dev[i].flags);
rdev_dec_pending(conf->disks[i].rdev, conf->mddev);
clear_bit(R5_LOCKED, &sh->dev[i].flags);
set_bit(STRIPE_HANDLE, &sh->state);
release_stripe(sh);
}
static void raid5_build_block(struct stripe_head *sh, int i, int previous)
{
struct r5dev *dev = &sh->dev[i];
bio_init(&dev->req);
dev->req.bi_io_vec = &dev->vec;
dev->req.bi_vcnt++;
dev->req.bi_max_vecs++;
dev->vec.bv_page = dev->page;
dev->vec.bv_len = STRIPE_SIZE;
dev->vec.bv_offset = 0;
dev->req.bi_sector = sh->sector;
dev->req.bi_private = sh;
dev->flags = 0;
dev->sector = compute_blocknr(sh, i, previous);
}
static void error(mddev_t *mddev, mdk_rdev_t *rdev)
{
char b[BDEVNAME_SIZE];
raid5_conf_t *conf = mddev->private;
pr_debug("raid456: error called\n");
if (test_and_clear_bit(In_sync, &rdev->flags)) {
unsigned long flags;
spin_lock_irqsave(&conf->device_lock, flags);
mddev->degraded++;
spin_unlock_irqrestore(&conf->device_lock, flags);
set_bit(MD_RECOVERY_INTR, &mddev->recovery);
}
set_bit(Blocked, &rdev->flags);
set_bit(Faulty, &rdev->flags);
set_bit(MD_CHANGE_DEVS, &mddev->flags);
printk(KERN_ALERT
"md/raid:%s: Disk failure on %s, disabling device.\n"
"md/raid:%s: Operation continuing on %d devices.\n",
mdname(mddev),
bdevname(rdev->bdev, b),
mdname(mddev),
conf->raid_disks - mddev->degraded);
}
static sector_t raid5_compute_sector(raid5_conf_t *conf, sector_t r_sector,
int previous, int *dd_idx,
struct stripe_head *sh)
{
sector_t stripe, stripe2;
sector_t chunk_number;
unsigned int chunk_offset;
int pd_idx, qd_idx;
int ddf_layout = 0;
sector_t new_sector;
int algorithm = previous ? conf->prev_algo
: conf->algorithm;
int sectors_per_chunk = previous ? conf->prev_chunk_sectors
: conf->chunk_sectors;
int raid_disks = previous ? conf->previous_raid_disks
: conf->raid_disks;
int data_disks = raid_disks - conf->max_degraded;
chunk_offset = sector_div(r_sector, sectors_per_chunk);
chunk_number = r_sector;
stripe = chunk_number;
*dd_idx = sector_div(stripe, data_disks);
stripe2 = stripe;
pd_idx = qd_idx = -1;
switch(conf->level) {
case 4:
pd_idx = data_disks;
break;
case 5:
switch (algorithm) {
case ALGORITHM_LEFT_ASYMMETRIC:
pd_idx = data_disks - sector_div(stripe2, raid_disks);
if (*dd_idx >= pd_idx)
(*dd_idx)++;
break;
case ALGORITHM_RIGHT_ASYMMETRIC:
pd_idx = sector_div(stripe2, raid_disks);
if (*dd_idx >= pd_idx)
(*dd_idx)++;
break;
case ALGORITHM_LEFT_SYMMETRIC:
pd_idx = data_disks - sector_div(stripe2, raid_disks);
*dd_idx = (pd_idx + 1 + *dd_idx) % raid_disks;
break;
case ALGORITHM_RIGHT_SYMMETRIC:
pd_idx = sector_div(stripe2, raid_disks);
*dd_idx = (pd_idx + 1 + *dd_idx) % raid_disks;
break;
case ALGORITHM_PARITY_0:
pd_idx = 0;
(*dd_idx)++;
break;
case ALGORITHM_PARITY_N:
pd_idx = data_disks;
break;
default:
BUG();
}
break;
case 6:
switch (algorithm) {
case ALGORITHM_LEFT_ASYMMETRIC:
pd_idx = raid_disks - 1 - sector_div(stripe2, raid_disks);
qd_idx = pd_idx + 1;
if (pd_idx == raid_disks-1) {
(*dd_idx)++;
qd_idx = 0;
} else if (*dd_idx >= pd_idx)
(*dd_idx) += 2;
break;
case ALGORITHM_RIGHT_ASYMMETRIC:
pd_idx = sector_div(stripe2, raid_disks);
qd_idx = pd_idx + 1;
if (pd_idx == raid_disks-1) {
(*dd_idx)++;
qd_idx = 0;
} else if (*dd_idx >= pd_idx)
(*dd_idx) += 2;
break;
case ALGORITHM_LEFT_SYMMETRIC:
pd_idx = raid_disks - 1 - sector_div(stripe2, raid_disks);
qd_idx = (pd_idx + 1) % raid_disks;
*dd_idx = (pd_idx + 2 + *dd_idx) % raid_disks;
break;
case ALGORITHM_RIGHT_SYMMETRIC:
pd_idx = sector_div(stripe2, raid_disks);
qd_idx = (pd_idx + 1) % raid_disks;
*dd_idx = (pd_idx + 2 + *dd_idx) % raid_disks;
break;
case ALGORITHM_PARITY_0:
pd_idx = 0;
qd_idx = 1;
(*dd_idx) += 2;
break;
case ALGORITHM_PARITY_N:
pd_idx = data_disks;
qd_idx = data_disks + 1;
break;
case ALGORITHM_ROTATING_ZERO_RESTART:
pd_idx = sector_div(stripe2, raid_disks);
qd_idx = pd_idx + 1;
if (pd_idx == raid_disks-1) {
(*dd_idx)++;
qd_idx = 0;
} else if (*dd_idx >= pd_idx)
(*dd_idx) += 2;
ddf_layout = 1;
break;
case ALGORITHM_ROTATING_N_RESTART:
stripe2 += 1;
pd_idx = raid_disks - 1 - sector_div(stripe2, raid_disks);
qd_idx = pd_idx + 1;
if (pd_idx == raid_disks-1) {
(*dd_idx)++;
qd_idx = 0;
} else if (*dd_idx >= pd_idx)
(*dd_idx) += 2;
ddf_layout = 1;
break;
case ALGORITHM_ROTATING_N_CONTINUE:
pd_idx = raid_disks - 1 - sector_div(stripe2, raid_disks);
qd_idx = (pd_idx + raid_disks - 1) % raid_disks;
*dd_idx = (pd_idx + 1 + *dd_idx) % raid_disks;
ddf_layout = 1;
break;
case ALGORITHM_LEFT_ASYMMETRIC_6:
pd_idx = data_disks - sector_div(stripe2, raid_disks-1);
if (*dd_idx >= pd_idx)
(*dd_idx)++;
qd_idx = raid_disks - 1;
break;
case ALGORITHM_RIGHT_ASYMMETRIC_6:
pd_idx = sector_div(stripe2, raid_disks-1);
if (*dd_idx >= pd_idx)
(*dd_idx)++;
qd_idx = raid_disks - 1;
break;
case ALGORITHM_LEFT_SYMMETRIC_6:
pd_idx = data_disks - sector_div(stripe2, raid_disks-1);
*dd_idx = (pd_idx + 1 + *dd_idx) % (raid_disks-1);
qd_idx = raid_disks - 1;
break;
case ALGORITHM_RIGHT_SYMMETRIC_6:
pd_idx = sector_div(stripe2, raid_disks-1);
*dd_idx = (pd_idx + 1 + *dd_idx) % (raid_disks-1);
qd_idx = raid_disks - 1;
break;
case ALGORITHM_PARITY_0_6:
pd_idx = 0;
(*dd_idx)++;
qd_idx = raid_disks - 1;
break;
default:
BUG();
}
break;
}
if (sh) {
sh->pd_idx = pd_idx;
sh->qd_idx = qd_idx;
sh->ddf_layout = ddf_layout;
}
new_sector = (sector_t)stripe * sectors_per_chunk + chunk_offset;
return new_sector;
}
static sector_t compute_blocknr(struct stripe_head *sh, int i, int previous)
{
raid5_conf_t *conf = sh->raid_conf;
int raid_disks = sh->disks;
int data_disks = raid_disks - conf->max_degraded;
sector_t new_sector = sh->sector, check;
int sectors_per_chunk = previous ? conf->prev_chunk_sectors
: conf->chunk_sectors;
int algorithm = previous ? conf->prev_algo
: conf->algorithm;
sector_t stripe;
int chunk_offset;
sector_t chunk_number;
int dummy1, dd_idx = i;
sector_t r_sector;
struct stripe_head sh2;
chunk_offset = sector_div(new_sector, sectors_per_chunk);
stripe = new_sector;
if (i == sh->pd_idx)
return 0;
switch(conf->level) {
case 4: break;
case 5:
switch (algorithm) {
case ALGORITHM_LEFT_ASYMMETRIC:
case ALGORITHM_RIGHT_ASYMMETRIC:
if (i > sh->pd_idx)
i--;
break;
case ALGORITHM_LEFT_SYMMETRIC:
case ALGORITHM_RIGHT_SYMMETRIC:
if (i < sh->pd_idx)
i += raid_disks;
i -= (sh->pd_idx + 1);
break;
case ALGORITHM_PARITY_0:
i -= 1;
break;
case ALGORITHM_PARITY_N:
break;
default:
BUG();
}
break;
case 6:
if (i == sh->qd_idx)
return 0;
switch (algorithm) {
case ALGORITHM_LEFT_ASYMMETRIC:
case ALGORITHM_RIGHT_ASYMMETRIC:
case ALGORITHM_ROTATING_ZERO_RESTART:
case ALGORITHM_ROTATING_N_RESTART:
if (sh->pd_idx == raid_disks-1)
i--;
else if (i > sh->pd_idx)
i -= 2;
break;
case ALGORITHM_LEFT_SYMMETRIC:
case ALGORITHM_RIGHT_SYMMETRIC:
if (sh->pd_idx == raid_disks-1)
i--;
else {
if (i < sh->pd_idx)
i += raid_disks;
i -= (sh->pd_idx + 2);
}
break;
case ALGORITHM_PARITY_0:
i -= 2;
break;
case ALGORITHM_PARITY_N:
break;
case ALGORITHM_ROTATING_N_CONTINUE:
if (sh->pd_idx == 0)
i--;
else {
if (i < sh->pd_idx)
i += raid_disks;
i -= (sh->pd_idx + 1);
}
break;
case ALGORITHM_LEFT_ASYMMETRIC_6:
case ALGORITHM_RIGHT_ASYMMETRIC_6:
if (i > sh->pd_idx)
i--;
break;
case ALGORITHM_LEFT_SYMMETRIC_6:
case ALGORITHM_RIGHT_SYMMETRIC_6:
if (i < sh->pd_idx)
i += data_disks + 1;
i -= (sh->pd_idx + 1);
break;
case ALGORITHM_PARITY_0_6:
i -= 1;
break;
default:
BUG();
}
break;
}
chunk_number = stripe * data_disks + i;
r_sector = chunk_number * sectors_per_chunk + chunk_offset;
check = raid5_compute_sector(conf, r_sector,
previous, &dummy1, &sh2);
if (check != sh->sector || dummy1 != dd_idx || sh2.pd_idx != sh->pd_idx
|| sh2.qd_idx != sh->qd_idx) {
printk(KERN_ERR "md/raid:%s: compute_blocknr: map not correct\n",
mdname(conf->mddev));
return 0;
}
return r_sector;
}
static void
schedule_reconstruction(struct stripe_head *sh, struct stripe_head_state *s,
int rcw, int expand)
{
int i, pd_idx = sh->pd_idx, disks = sh->disks;
raid5_conf_t *conf = sh->raid_conf;
int level = conf->level;
if (rcw) {
if (!expand) {
sh->reconstruct_state = reconstruct_state_drain_run;
set_bit(STRIPE_OP_BIODRAIN, &s->ops_request);
} else
sh->reconstruct_state = reconstruct_state_run;
set_bit(STRIPE_OP_RECONSTRUCT, &s->ops_request);
for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (dev->towrite) {
set_bit(R5_LOCKED, &dev->flags);
set_bit(R5_Wantdrain, &dev->flags);
if (!expand)
clear_bit(R5_UPTODATE, &dev->flags);
s->locked++;
}
}
if (s->locked + conf->max_degraded == disks)
if (!test_and_set_bit(STRIPE_FULL_WRITE, &sh->state))
atomic_inc(&conf->pending_full_writes);
} else {
BUG_ON(level == 6);
BUG_ON(!(test_bit(R5_UPTODATE, &sh->dev[pd_idx].flags) ||
test_bit(R5_Wantcompute, &sh->dev[pd_idx].flags)));
sh->reconstruct_state = reconstruct_state_prexor_drain_run;
set_bit(STRIPE_OP_PREXOR, &s->ops_request);
set_bit(STRIPE_OP_BIODRAIN, &s->ops_request);
set_bit(STRIPE_OP_RECONSTRUCT, &s->ops_request);
for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (i == pd_idx)
continue;
if (dev->towrite &&
(test_bit(R5_UPTODATE, &dev->flags) ||
test_bit(R5_Wantcompute, &dev->flags))) {
set_bit(R5_Wantdrain, &dev->flags);
set_bit(R5_LOCKED, &dev->flags);
clear_bit(R5_UPTODATE, &dev->flags);
s->locked++;
}
}
}
set_bit(R5_LOCKED, &sh->dev[pd_idx].flags);
clear_bit(R5_UPTODATE, &sh->dev[pd_idx].flags);
s->locked++;
if (level == 6) {
int qd_idx = sh->qd_idx;
struct r5dev *dev = &sh->dev[qd_idx];
set_bit(R5_LOCKED, &dev->flags);
clear_bit(R5_UPTODATE, &dev->flags);
s->locked++;
}
pr_debug("%s: stripe %llu locked: %d ops_request: %lx\n",
__func__, (unsigned long long)sh->sector,
s->locked, s->ops_request);
}
static int add_stripe_bio(struct stripe_head *sh, struct bio *bi, int dd_idx, int forwrite)
{
struct bio **bip;
raid5_conf_t *conf = sh->raid_conf;
int firstwrite=0;
pr_debug("adding bi b#%llu to stripe s#%llu\n",
(unsigned long long)bi->bi_sector,
(unsigned long long)sh->sector);
spin_lock_irq(&conf->device_lock);
if (forwrite) {
bip = &sh->dev[dd_idx].towrite;
if (*bip == NULL && sh->dev[dd_idx].written == NULL)
firstwrite = 1;
} else
bip = &sh->dev[dd_idx].toread;
while (*bip && (*bip)->bi_sector < bi->bi_sector) {
if ((*bip)->bi_sector + ((*bip)->bi_size >> 9) > bi->bi_sector)
goto overlap;
bip = & (*bip)->bi_next;
}
if (*bip && (*bip)->bi_sector < bi->bi_sector + ((bi->bi_size)>>9))
goto overlap;
BUG_ON(*bip && bi->bi_next && (*bip) != bi->bi_next);
if (*bip)
bi->bi_next = *bip;
*bip = bi;
bi->bi_phys_segments++;
if (forwrite) {
sector_t sector = sh->dev[dd_idx].sector;
for (bi=sh->dev[dd_idx].towrite;
sector < sh->dev[dd_idx].sector + STRIPE_SECTORS &&
bi && bi->bi_sector <= sector;
bi = r5_next_bio(bi, sh->dev[dd_idx].sector)) {
if (bi->bi_sector + (bi->bi_size>>9) >= sector)
sector = bi->bi_sector + (bi->bi_size>>9);
}
if (sector >= sh->dev[dd_idx].sector + STRIPE_SECTORS)
set_bit(R5_OVERWRITE, &sh->dev[dd_idx].flags);
}
spin_unlock_irq(&conf->device_lock);
pr_debug("added bi b#%llu to stripe s#%llu, disk %d.\n",
(unsigned long long)(*bip)->bi_sector,
(unsigned long long)sh->sector, dd_idx);
if (conf->mddev->bitmap && firstwrite) {
bitmap_startwrite(conf->mddev->bitmap, sh->sector,
STRIPE_SECTORS, 0);
sh->bm_seq = conf->seq_flush+1;
set_bit(STRIPE_BIT_DELAY, &sh->state);
}
return 1;
overlap:
set_bit(R5_Overlap, &sh->dev[dd_idx].flags);
spin_unlock_irq(&conf->device_lock);
return 0;
}
static void stripe_set_idx(sector_t stripe, raid5_conf_t *conf, int previous,
struct stripe_head *sh)
{
int sectors_per_chunk =
previous ? conf->prev_chunk_sectors : conf->chunk_sectors;
int dd_idx;
int chunk_offset = sector_div(stripe, sectors_per_chunk);
int disks = previous ? conf->previous_raid_disks : conf->raid_disks;
raid5_compute_sector(conf,
stripe * (disks - conf->max_degraded)
*sectors_per_chunk + chunk_offset,
previous,
&dd_idx, sh);
}
static void
handle_failed_stripe(raid5_conf_t *conf, struct stripe_head *sh,
struct stripe_head_state *s, int disks,
struct bio **return_bi)
{
int i;
for (i = disks; i--; ) {
struct bio *bi;
int bitmap_end = 0;
if (test_bit(R5_ReadError, &sh->dev[i].flags)) {
mdk_rdev_t *rdev;
rcu_read_lock();
rdev = rcu_dereference(conf->disks[i].rdev);
if (rdev && test_bit(In_sync, &rdev->flags))
atomic_inc(&rdev->nr_pending);
else
rdev = NULL;
rcu_read_unlock();
if (rdev) {
if (!rdev_set_badblocks(
rdev,
sh->sector,
STRIPE_SECTORS, 0))
md_error(conf->mddev, rdev);
rdev_dec_pending(rdev, conf->mddev);
}
}
spin_lock_irq(&conf->device_lock);
bi = sh->dev[i].towrite;
sh->dev[i].towrite = NULL;
if (bi) {
s->to_write--;
bitmap_end = 1;
}
if (test_and_clear_bit(R5_Overlap, &sh->dev[i].flags))
wake_up(&conf->wait_for_overlap);
while (bi && bi->bi_sector <
sh->dev[i].sector + STRIPE_SECTORS) {
struct bio *nextbi = r5_next_bio(bi, sh->dev[i].sector);
clear_bit(BIO_UPTODATE, &bi->bi_flags);
if (!raid5_dec_bi_phys_segments(bi)) {
md_write_end(conf->mddev);
bi->bi_next = *return_bi;
*return_bi = bi;
}
bi = nextbi;
}
bi = sh->dev[i].written;
sh->dev[i].written = NULL;
if (bi) bitmap_end = 1;
while (bi && bi->bi_sector <
sh->dev[i].sector + STRIPE_SECTORS) {
struct bio *bi2 = r5_next_bio(bi, sh->dev[i].sector);
clear_bit(BIO_UPTODATE, &bi->bi_flags);
if (!raid5_dec_bi_phys_segments(bi)) {
md_write_end(conf->mddev);
bi->bi_next = *return_bi;
*return_bi = bi;
}
bi = bi2;
}
if (!test_bit(R5_Wantfill, &sh->dev[i].flags) &&
(!test_bit(R5_Insync, &sh->dev[i].flags) ||
test_bit(R5_ReadError, &sh->dev[i].flags))) {
bi = sh->dev[i].toread;
sh->dev[i].toread = NULL;
if (test_and_clear_bit(R5_Overlap, &sh->dev[i].flags))
wake_up(&conf->wait_for_overlap);
if (bi) s->to_read--;
while (bi && bi->bi_sector <
sh->dev[i].sector + STRIPE_SECTORS) {
struct bio *nextbi =
r5_next_bio(bi, sh->dev[i].sector);
clear_bit(BIO_UPTODATE, &bi->bi_flags);
if (!raid5_dec_bi_phys_segments(bi)) {
bi->bi_next = *return_bi;
*return_bi = bi;
}
bi = nextbi;
}
}
spin_unlock_irq(&conf->device_lock);
if (bitmap_end)
bitmap_endwrite(conf->mddev->bitmap, sh->sector,
STRIPE_SECTORS, 0, 0);
clear_bit(R5_LOCKED, &sh->dev[i].flags);
}
if (test_and_clear_bit(STRIPE_FULL_WRITE, &sh->state))
if (atomic_dec_and_test(&conf->pending_full_writes))
md_wakeup_thread(conf->mddev->thread);
}
static void
handle_failed_sync(raid5_conf_t *conf, struct stripe_head *sh,
struct stripe_head_state *s)
{
int abort = 0;
int i;
md_done_sync(conf->mddev, STRIPE_SECTORS, 0);
clear_bit(STRIPE_SYNCING, &sh->state);
s->syncing = 0;
if (!test_bit(MD_RECOVERY_RECOVER, &conf->mddev->recovery))
return;
for (i = 0; i < conf->raid_disks; i++) {
mdk_rdev_t *rdev = conf->disks[i].rdev;
if (!rdev
|| test_bit(Faulty, &rdev->flags)
|| test_bit(In_sync, &rdev->flags))
continue;
if (!rdev_set_badblocks(rdev, sh->sector,
STRIPE_SECTORS, 0))
abort = 1;
}
if (abort) {
conf->recovery_disabled = conf->mddev->recovery_disabled;
set_bit(MD_RECOVERY_INTR, &conf->mddev->recovery);
}
}
static int fetch_block(struct stripe_head *sh, struct stripe_head_state *s,
int disk_idx, int disks)
{
struct r5dev *dev = &sh->dev[disk_idx];
struct r5dev *fdev[2] = { &sh->dev[s->failed_num[0]],
&sh->dev[s->failed_num[1]] };
if (!test_bit(R5_LOCKED, &dev->flags) &&
!test_bit(R5_UPTODATE, &dev->flags) &&
(dev->toread ||
(dev->towrite && !test_bit(R5_OVERWRITE, &dev->flags)) ||
s->syncing || s->expanding ||
(s->failed >= 1 && fdev[0]->toread) ||
(s->failed >= 2 && fdev[1]->toread) ||
(sh->raid_conf->level <= 5 && s->failed && fdev[0]->towrite &&
!test_bit(R5_OVERWRITE, &fdev[0]->flags)) ||
(sh->raid_conf->level == 6 && s->failed && s->to_write))) {
BUG_ON(test_bit(R5_Wantcompute, &dev->flags));
BUG_ON(test_bit(R5_Wantread, &dev->flags));
if ((s->uptodate == disks - 1) &&
(s->failed && (disk_idx == s->failed_num[0] ||
disk_idx == s->failed_num[1]))) {
pr_debug("Computing stripe %llu block %d\n",
(unsigned long long)sh->sector, disk_idx);
set_bit(STRIPE_COMPUTE_RUN, &sh->state);
set_bit(STRIPE_OP_COMPUTE_BLK, &s->ops_request);
set_bit(R5_Wantcompute, &dev->flags);
sh->ops.target = disk_idx;
sh->ops.target2 = -1;
s->req_compute = 1;
s->uptodate++;
return 1;
} else if (s->uptodate == disks-2 && s->failed >= 2) {
int other;
for (other = disks; other--; ) {
if (other == disk_idx)
continue;
if (!test_bit(R5_UPTODATE,
&sh->dev[other].flags))
break;
}
BUG_ON(other < 0);
pr_debug("Computing stripe %llu blocks %d,%d\n",
(unsigned long long)sh->sector,
disk_idx, other);
set_bit(STRIPE_COMPUTE_RUN, &sh->state);
set_bit(STRIPE_OP_COMPUTE_BLK, &s->ops_request);
set_bit(R5_Wantcompute, &sh->dev[disk_idx].flags);
set_bit(R5_Wantcompute, &sh->dev[other].flags);
sh->ops.target = disk_idx;
sh->ops.target2 = other;
s->uptodate += 2;
s->req_compute = 1;
return 1;
} else if (test_bit(R5_Insync, &dev->flags)) {
set_bit(R5_LOCKED, &dev->flags);
set_bit(R5_Wantread, &dev->flags);
s->locked++;
pr_debug("Reading block %d (sync=%d)\n",
disk_idx, s->syncing);
}
}
return 0;
}
static void handle_stripe_fill(struct stripe_head *sh,
struct stripe_head_state *s,
int disks)
{
int i;
if (!test_bit(STRIPE_COMPUTE_RUN, &sh->state) && !sh->check_state &&
!sh->reconstruct_state)
for (i = disks; i--; )
if (fetch_block(sh, s, i, disks))
break;
set_bit(STRIPE_HANDLE, &sh->state);
}
static void handle_stripe_clean_event(raid5_conf_t *conf,
struct stripe_head *sh, int disks, struct bio **return_bi)
{
int i;
struct r5dev *dev;
for (i = disks; i--; )
if (sh->dev[i].written) {
dev = &sh->dev[i];
if (!test_bit(R5_LOCKED, &dev->flags) &&
test_bit(R5_UPTODATE, &dev->flags)) {
struct bio *wbi, *wbi2;
int bitmap_end = 0;
pr_debug("Return write for disc %d\n", i);
spin_lock_irq(&conf->device_lock);
wbi = dev->written;
dev->written = NULL;
while (wbi && wbi->bi_sector <
dev->sector + STRIPE_SECTORS) {
wbi2 = r5_next_bio(wbi, dev->sector);
if (!raid5_dec_bi_phys_segments(wbi)) {
md_write_end(conf->mddev);
wbi->bi_next = *return_bi;
*return_bi = wbi;
}
wbi = wbi2;
}
if (dev->towrite == NULL)
bitmap_end = 1;
spin_unlock_irq(&conf->device_lock);
if (bitmap_end)
bitmap_endwrite(conf->mddev->bitmap,
sh->sector,
STRIPE_SECTORS,
!test_bit(STRIPE_DEGRADED, &sh->state),
0);
}
}
if (test_and_clear_bit(STRIPE_FULL_WRITE, &sh->state))
if (atomic_dec_and_test(&conf->pending_full_writes))
md_wakeup_thread(conf->mddev->thread);
}
static void handle_stripe_dirtying(raid5_conf_t *conf,
struct stripe_head *sh,
struct stripe_head_state *s,
int disks)
{
int rmw = 0, rcw = 0, i;
if (conf->max_degraded == 2) {
rcw = 1; rmw = 2;
} else for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if ((dev->towrite || i == sh->pd_idx) &&
!test_bit(R5_LOCKED, &dev->flags) &&
!(test_bit(R5_UPTODATE, &dev->flags) ||
test_bit(R5_Wantcompute, &dev->flags))) {
if (test_bit(R5_Insync, &dev->flags))
rmw++;
else
rmw += 2*disks;
}
if (!test_bit(R5_OVERWRITE, &dev->flags) && i != sh->pd_idx &&
!test_bit(R5_LOCKED, &dev->flags) &&
!(test_bit(R5_UPTODATE, &dev->flags) ||
test_bit(R5_Wantcompute, &dev->flags))) {
if (test_bit(R5_Insync, &dev->flags)) rcw++;
else
rcw += 2*disks;
}
}
pr_debug("for sector %llu, rmw=%d rcw=%d\n",
(unsigned long long)sh->sector, rmw, rcw);
set_bit(STRIPE_HANDLE, &sh->state);
if (rmw < rcw && rmw > 0)
for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if ((dev->towrite || i == sh->pd_idx) &&
!test_bit(R5_LOCKED, &dev->flags) &&
!(test_bit(R5_UPTODATE, &dev->flags) ||
test_bit(R5_Wantcompute, &dev->flags)) &&
test_bit(R5_Insync, &dev->flags)) {
if (
test_bit(STRIPE_PREREAD_ACTIVE, &sh->state)) {
pr_debug("Read_old block "
"%d for r-m-w\n", i);
set_bit(R5_LOCKED, &dev->flags);
set_bit(R5_Wantread, &dev->flags);
s->locked++;
} else {
set_bit(STRIPE_DELAYED, &sh->state);
set_bit(STRIPE_HANDLE, &sh->state);
}
}
}
if (rcw <= rmw && rcw > 0) {
rcw = 0;
for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (!test_bit(R5_OVERWRITE, &dev->flags) &&
i != sh->pd_idx && i != sh->qd_idx &&
!test_bit(R5_LOCKED, &dev->flags) &&
!(test_bit(R5_UPTODATE, &dev->flags) ||
test_bit(R5_Wantcompute, &dev->flags))) {
rcw++;
if (!test_bit(R5_Insync, &dev->flags))
continue;
if (
test_bit(STRIPE_PREREAD_ACTIVE, &sh->state)) {
pr_debug("Read_old block "
"%d for Reconstruct\n", i);
set_bit(R5_LOCKED, &dev->flags);
set_bit(R5_Wantread, &dev->flags);
s->locked++;
} else {
set_bit(STRIPE_DELAYED, &sh->state);
set_bit(STRIPE_HANDLE, &sh->state);
}
}
}
}
if ((s->req_compute || !test_bit(STRIPE_COMPUTE_RUN, &sh->state)) &&
(s->locked == 0 && (rcw == 0 || rmw == 0) &&
!test_bit(STRIPE_BIT_DELAY, &sh->state)))
schedule_reconstruction(sh, s, rcw == 0, 0);
}
static void handle_parity_checks5(raid5_conf_t *conf, struct stripe_head *sh,
struct stripe_head_state *s, int disks)
{
struct r5dev *dev = NULL;
set_bit(STRIPE_HANDLE, &sh->state);
switch (sh->check_state) {
case check_state_idle:
if (s->failed == 0) {
BUG_ON(s->uptodate != disks);
sh->check_state = check_state_run;
set_bit(STRIPE_OP_CHECK, &s->ops_request);
clear_bit(R5_UPTODATE, &sh->dev[sh->pd_idx].flags);
s->uptodate--;
break;
}
dev = &sh->dev[s->failed_num[0]];
case check_state_compute_result:
sh->check_state = check_state_idle;
if (!dev)
dev = &sh->dev[sh->pd_idx];
if (test_bit(STRIPE_INSYNC, &sh->state))
break;
BUG_ON(!test_bit(R5_UPTODATE, &dev->flags));
BUG_ON(s->uptodate != disks);
set_bit(R5_LOCKED, &dev->flags);
s->locked++;
set_bit(R5_Wantwrite, &dev->flags);
clear_bit(STRIPE_DEGRADED, &sh->state);
set_bit(STRIPE_INSYNC, &sh->state);
break;
case check_state_run:
break;
case check_state_check_result:
sh->check_state = check_state_idle;
if (s->failed)
break;
if ((sh->ops.zero_sum_result & SUM_CHECK_P_RESULT) == 0)
set_bit(STRIPE_INSYNC, &sh->state);
else {
conf->mddev->resync_mismatches += STRIPE_SECTORS;
if (test_bit(MD_RECOVERY_CHECK, &conf->mddev->recovery))
set_bit(STRIPE_INSYNC, &sh->state);
else {
sh->check_state = check_state_compute_run;
set_bit(STRIPE_COMPUTE_RUN, &sh->state);
set_bit(STRIPE_OP_COMPUTE_BLK, &s->ops_request);
set_bit(R5_Wantcompute,
&sh->dev[sh->pd_idx].flags);
sh->ops.target = sh->pd_idx;
sh->ops.target2 = -1;
s->uptodate++;
}
}
break;
case check_state_compute_run:
break;
default:
printk(KERN_ERR "%s: unknown check_state: %d sector: %llu\n",
__func__, sh->check_state,
(unsigned long long) sh->sector);
BUG();
}
}
static void handle_parity_checks6(raid5_conf_t *conf, struct stripe_head *sh,
struct stripe_head_state *s,
int disks)
{
int pd_idx = sh->pd_idx;
int qd_idx = sh->qd_idx;
struct r5dev *dev;
set_bit(STRIPE_HANDLE, &sh->state);
BUG_ON(s->failed > 2);
switch (sh->check_state) {
case check_state_idle:
if (s->failed == s->q_failed) {
sh->check_state = check_state_run;
}
if (!s->q_failed && s->failed < 2) {
if (sh->check_state == check_state_run)
sh->check_state = check_state_run_pq;
else
sh->check_state = check_state_run_q;
}
sh->ops.zero_sum_result = 0;
if (sh->check_state == check_state_run) {
clear_bit(R5_UPTODATE, &sh->dev[pd_idx].flags);
s->uptodate--;
}
if (sh->check_state >= check_state_run &&
sh->check_state <= check_state_run_pq) {
set_bit(STRIPE_OP_CHECK, &s->ops_request);
break;
}
BUG_ON(s->failed != 2);
case check_state_compute_result:
sh->check_state = check_state_idle;
if (test_bit(STRIPE_INSYNC, &sh->state))
break;
BUG_ON(s->uptodate < disks - 1);
if (s->failed == 2) {
dev = &sh->dev[s->failed_num[1]];
s->locked++;
set_bit(R5_LOCKED, &dev->flags);
set_bit(R5_Wantwrite, &dev->flags);
}
if (s->failed >= 1) {
dev = &sh->dev[s->failed_num[0]];
s->locked++;
set_bit(R5_LOCKED, &dev->flags);
set_bit(R5_Wantwrite, &dev->flags);
}
if (sh->ops.zero_sum_result & SUM_CHECK_P_RESULT) {
dev = &sh->dev[pd_idx];
s->locked++;
set_bit(R5_LOCKED, &dev->flags);
set_bit(R5_Wantwrite, &dev->flags);
}
if (sh->ops.zero_sum_result & SUM_CHECK_Q_RESULT) {
dev = &sh->dev[qd_idx];
s->locked++;
set_bit(R5_LOCKED, &dev->flags);
set_bit(R5_Wantwrite, &dev->flags);
}
clear_bit(STRIPE_DEGRADED, &sh->state);
set_bit(STRIPE_INSYNC, &sh->state);
break;
case check_state_run:
case check_state_run_q:
case check_state_run_pq:
break;
case check_state_check_result:
sh->check_state = check_state_idle;
if (sh->ops.zero_sum_result == 0) {
if (!s->failed)
set_bit(STRIPE_INSYNC, &sh->state);
else {
sh->check_state = check_state_compute_result;
}
} else {
conf->mddev->resync_mismatches += STRIPE_SECTORS;
if (test_bit(MD_RECOVERY_CHECK, &conf->mddev->recovery))
set_bit(STRIPE_INSYNC, &sh->state);
else {
int *target = &sh->ops.target;
sh->ops.target = -1;
sh->ops.target2 = -1;
sh->check_state = check_state_compute_run;
set_bit(STRIPE_COMPUTE_RUN, &sh->state);
set_bit(STRIPE_OP_COMPUTE_BLK, &s->ops_request);
if (sh->ops.zero_sum_result & SUM_CHECK_P_RESULT) {
set_bit(R5_Wantcompute,
&sh->dev[pd_idx].flags);
*target = pd_idx;
target = &sh->ops.target2;
s->uptodate++;
}
if (sh->ops.zero_sum_result & SUM_CHECK_Q_RESULT) {
set_bit(R5_Wantcompute,
&sh->dev[qd_idx].flags);
*target = qd_idx;
s->uptodate++;
}
}
}
break;
case check_state_compute_run:
break;
default:
printk(KERN_ERR "%s: unknown check_state: %d sector: %llu\n",
__func__, sh->check_state,
(unsigned long long) sh->sector);
BUG();
}
}
static void handle_stripe_expansion(raid5_conf_t *conf, struct stripe_head *sh)
{
int i;
struct dma_async_tx_descriptor *tx = NULL;
clear_bit(STRIPE_EXPAND_SOURCE, &sh->state);
for (i = 0; i < sh->disks; i++)
if (i != sh->pd_idx && i != sh->qd_idx) {
int dd_idx, j;
struct stripe_head *sh2;
struct async_submit_ctl submit;
sector_t bn = compute_blocknr(sh, i, 1);
sector_t s = raid5_compute_sector(conf, bn, 0,
&dd_idx, NULL);
sh2 = get_active_stripe(conf, s, 0, 1, 1);
if (sh2 == NULL)
continue;
if (!test_bit(STRIPE_EXPANDING, &sh2->state) ||
test_bit(R5_Expanded, &sh2->dev[dd_idx].flags)) {
release_stripe(sh2);
continue;
}
init_async_submit(&submit, 0, tx, NULL, NULL, NULL);
tx = async_memcpy(sh2->dev[dd_idx].page,
sh->dev[i].page, 0, 0, STRIPE_SIZE,
&submit);
set_bit(R5_Expanded, &sh2->dev[dd_idx].flags);
set_bit(R5_UPTODATE, &sh2->dev[dd_idx].flags);
for (j = 0; j < conf->raid_disks; j++)
if (j != sh2->pd_idx &&
j != sh2->qd_idx &&
!test_bit(R5_Expanded, &sh2->dev[j].flags))
break;
if (j == conf->raid_disks) {
set_bit(STRIPE_EXPAND_READY, &sh2->state);
set_bit(STRIPE_HANDLE, &sh2->state);
}
release_stripe(sh2);
}
if (tx) {
async_tx_ack(tx);
dma_wait_for_async_tx(tx);
}
}
static void analyse_stripe(struct stripe_head *sh, struct stripe_head_state *s)
{
raid5_conf_t *conf = sh->raid_conf;
int disks = sh->disks;
struct r5dev *dev;
int i;
memset(s, 0, sizeof(*s));
s->syncing = test_bit(STRIPE_SYNCING, &sh->state);
s->expanding = test_bit(STRIPE_EXPAND_SOURCE, &sh->state);
s->expanded = test_bit(STRIPE_EXPAND_READY, &sh->state);
s->failed_num[0] = -1;
s->failed_num[1] = -1;
rcu_read_lock();
spin_lock_irq(&conf->device_lock);
for (i=disks; i--; ) {
mdk_rdev_t *rdev;
sector_t first_bad;
int bad_sectors;
int is_bad = 0;
dev = &sh->dev[i];
pr_debug("check %d: state 0x%lx read %p write %p written %p\n",
i, dev->flags, dev->toread, dev->towrite, dev->written);
if (test_bit(R5_UPTODATE, &dev->flags) && dev->toread &&
!test_bit(STRIPE_BIOFILL_RUN, &sh->state))
set_bit(R5_Wantfill, &dev->flags);
if (test_bit(R5_LOCKED, &dev->flags))
s->locked++;
if (test_bit(R5_UPTODATE, &dev->flags))
s->uptodate++;
if (test_bit(R5_Wantcompute, &dev->flags)) {
s->compute++;
BUG_ON(s->compute > 2);
}
if (test_bit(R5_Wantfill, &dev->flags))
s->to_fill++;
else if (dev->toread)
s->to_read++;
if (dev->towrite) {
s->to_write++;
if (!test_bit(R5_OVERWRITE, &dev->flags))
s->non_overwrite++;
}
if (dev->written)
s->written++;
rdev = rcu_dereference(conf->disks[i].rdev);
if (rdev) {
is_bad = is_badblock(rdev, sh->sector, STRIPE_SECTORS,
&first_bad, &bad_sectors);
if (s->blocked_rdev == NULL
&& (test_bit(Blocked, &rdev->flags)
|| is_bad < 0)) {
if (is_bad < 0)
set_bit(BlockedBadBlocks,
&rdev->flags);
s->blocked_rdev = rdev;
atomic_inc(&rdev->nr_pending);
}
}
clear_bit(R5_Insync, &dev->flags);
if (!rdev)
;
else if (is_bad) {
if (!test_bit(WriteErrorSeen, &rdev->flags)) {
set_bit(R5_Insync, &dev->flags);
set_bit(R5_ReadError, &dev->flags);
}
} else if (test_bit(In_sync, &rdev->flags))
set_bit(R5_Insync, &dev->flags);
else {
if (sh->sector + STRIPE_SECTORS <= rdev->recovery_offset)
set_bit(R5_Insync, &dev->flags);
}
if (test_bit(R5_WriteError, &dev->flags)) {
clear_bit(R5_Insync, &dev->flags);
if (!test_bit(Faulty, &rdev->flags)) {
s->handle_bad_blocks = 1;
atomic_inc(&rdev->nr_pending);
} else
clear_bit(R5_WriteError, &dev->flags);
}
if (test_bit(R5_MadeGood, &dev->flags)) {
if (!test_bit(Faulty, &rdev->flags)) {
s->handle_bad_blocks = 1;
atomic_inc(&rdev->nr_pending);
} else
clear_bit(R5_MadeGood, &dev->flags);
}
if (!test_bit(R5_Insync, &dev->flags)) {
clear_bit(R5_ReadError, &dev->flags);
clear_bit(R5_ReWrite, &dev->flags);
}
if (test_bit(R5_ReadError, &dev->flags))
clear_bit(R5_Insync, &dev->flags);
if (!test_bit(R5_Insync, &dev->flags)) {
if (s->failed < 2)
s->failed_num[s->failed] = i;
s->failed++;
}
}
spin_unlock_irq(&conf->device_lock);
rcu_read_unlock();
}
static void handle_stripe(struct stripe_head *sh)
{
struct stripe_head_state s;
raid5_conf_t *conf = sh->raid_conf;
int i;
int prexor;
int disks = sh->disks;
struct r5dev *pdev, *qdev;
clear_bit(STRIPE_HANDLE, &sh->state);
if (test_and_set_bit(STRIPE_ACTIVE, &sh->state)) {
set_bit(STRIPE_HANDLE, &sh->state);
return;
}
if (test_and_clear_bit(STRIPE_SYNC_REQUESTED, &sh->state)) {
set_bit(STRIPE_SYNCING, &sh->state);
clear_bit(STRIPE_INSYNC, &sh->state);
}
clear_bit(STRIPE_DELAYED, &sh->state);
pr_debug("handling stripe %llu, state=%#lx cnt=%d, "
"pd_idx=%d, qd_idx=%d\n, check:%d, reconstruct:%d\n",
(unsigned long long)sh->sector, sh->state,
atomic_read(&sh->count), sh->pd_idx, sh->qd_idx,
sh->check_state, sh->reconstruct_state);
analyse_stripe(sh, &s);
if (s.handle_bad_blocks) {
set_bit(STRIPE_HANDLE, &sh->state);
goto finish;
}
if (unlikely(s.blocked_rdev)) {
if (s.syncing || s.expanding || s.expanded ||
s.to_write || s.written) {
set_bit(STRIPE_HANDLE, &sh->state);
goto finish;
}
rdev_dec_pending(s.blocked_rdev, conf->mddev);
s.blocked_rdev = NULL;
}
if (s.to_fill && !test_bit(STRIPE_BIOFILL_RUN, &sh->state)) {
set_bit(STRIPE_OP_BIOFILL, &s.ops_request);
set_bit(STRIPE_BIOFILL_RUN, &sh->state);
}
pr_debug("locked=%d uptodate=%d to_read=%d"
" to_write=%d failed=%d failed_num=%d,%d\n",
s.locked, s.uptodate, s.to_read, s.to_write, s.failed,
s.failed_num[0], s.failed_num[1]);
if (s.failed > conf->max_degraded && s.to_read+s.to_write+s.written)
handle_failed_stripe(conf, sh, &s, disks, &s.return_bi);
if (s.failed > conf->max_degraded && s.syncing)
handle_failed_sync(conf, sh, &s);
pdev = &sh->dev[sh->pd_idx];
s.p_failed = (s.failed >= 1 && s.failed_num[0] == sh->pd_idx)
|| (s.failed >= 2 && s.failed_num[1] == sh->pd_idx);
qdev = &sh->dev[sh->qd_idx];
s.q_failed = (s.failed >= 1 && s.failed_num[0] == sh->qd_idx)
|| (s.failed >= 2 && s.failed_num[1] == sh->qd_idx)
|| conf->level < 6;
if (s.written &&
(s.p_failed || ((test_bit(R5_Insync, &pdev->flags)
&& !test_bit(R5_LOCKED, &pdev->flags)
&& test_bit(R5_UPTODATE, &pdev->flags)))) &&
(s.q_failed || ((test_bit(R5_Insync, &qdev->flags)
&& !test_bit(R5_LOCKED, &qdev->flags)
&& test_bit(R5_UPTODATE, &qdev->flags)))))
handle_stripe_clean_event(conf, sh, disks, &s.return_bi);
if (s.to_read || s.non_overwrite
|| (conf->level == 6 && s.to_write && s.failed)
|| (s.syncing && (s.uptodate + s.compute < disks)) || s.expanding)
handle_stripe_fill(sh, &s, disks);
prexor = 0;
if (sh->reconstruct_state == reconstruct_state_prexor_drain_result)
prexor = 1;
if (sh->reconstruct_state == reconstruct_state_drain_result ||
sh->reconstruct_state == reconstruct_state_prexor_drain_result) {
sh->reconstruct_state = reconstruct_state_idle;
BUG_ON(!test_bit(R5_UPTODATE, &sh->dev[sh->pd_idx].flags));
BUG_ON(sh->qd_idx >= 0 &&
!test_bit(R5_UPTODATE, &sh->dev[sh->qd_idx].flags));
for (i = disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
if (test_bit(R5_LOCKED, &dev->flags) &&
(i == sh->pd_idx || i == sh->qd_idx ||
dev->written)) {
pr_debug("Writing block %d\n", i);
set_bit(R5_Wantwrite, &dev->flags);
if (prexor)
continue;
if (!test_bit(R5_Insync, &dev->flags) ||
((i == sh->pd_idx || i == sh->qd_idx) &&
s.failed == 0))
set_bit(STRIPE_INSYNC, &sh->state);
}
}
if (test_and_clear_bit(STRIPE_PREREAD_ACTIVE, &sh->state))
s.dec_preread_active = 1;
}
if (s.to_write && !sh->reconstruct_state && !sh->check_state)
handle_stripe_dirtying(conf, sh, &s, disks);
if (sh->check_state ||
(s.syncing && s.locked == 0 &&
!test_bit(STRIPE_COMPUTE_RUN, &sh->state) &&
!test_bit(STRIPE_INSYNC, &sh->state))) {
if (conf->level == 6)
handle_parity_checks6(conf, sh, &s, disks);
else
handle_parity_checks5(conf, sh, &s, disks);
}
if (s.syncing && s.locked == 0 && test_bit(STRIPE_INSYNC, &sh->state)) {
md_done_sync(conf->mddev, STRIPE_SECTORS, 1);
clear_bit(STRIPE_SYNCING, &sh->state);
}
if (s.failed <= conf->max_degraded && !conf->mddev->ro)
for (i = 0; i < s.failed; i++) {
struct r5dev *dev = &sh->dev[s.failed_num[i]];
if (test_bit(R5_ReadError, &dev->flags)
&& !test_bit(R5_LOCKED, &dev->flags)
&& test_bit(R5_UPTODATE, &dev->flags)
) {
if (!test_bit(R5_ReWrite, &dev->flags)) {
set_bit(R5_Wantwrite, &dev->flags);
set_bit(R5_ReWrite, &dev->flags);
set_bit(R5_LOCKED, &dev->flags);
s.locked++;
} else {
set_bit(R5_Wantread, &dev->flags);
set_bit(R5_LOCKED, &dev->flags);
s.locked++;
}
}
}
if (sh->reconstruct_state == reconstruct_state_result) {
struct stripe_head *sh_src
= get_active_stripe(conf, sh->sector, 1, 1, 1);
if (sh_src && test_bit(STRIPE_EXPAND_SOURCE, &sh_src->state)) {
set_bit(STRIPE_DELAYED, &sh->state);
set_bit(STRIPE_HANDLE, &sh->state);
if (!test_and_set_bit(STRIPE_PREREAD_ACTIVE,
&sh_src->state))
atomic_inc(&conf->preread_active_stripes);
release_stripe(sh_src);
goto finish;
}
if (sh_src)
release_stripe(sh_src);
sh->reconstruct_state = reconstruct_state_idle;
clear_bit(STRIPE_EXPANDING, &sh->state);
for (i = conf->raid_disks; i--; ) {
set_bit(R5_Wantwrite, &sh->dev[i].flags);
set_bit(R5_LOCKED, &sh->dev[i].flags);
s.locked++;
}
}
if (s.expanded && test_bit(STRIPE_EXPANDING, &sh->state) &&
!sh->reconstruct_state) {
sh->disks = conf->raid_disks;
stripe_set_idx(sh->sector, conf, 0, sh);
schedule_reconstruction(sh, &s, 1, 1);
} else if (s.expanded && !sh->reconstruct_state && s.locked == 0) {
clear_bit(STRIPE_EXPAND_READY, &sh->state);
atomic_dec(&conf->reshape_stripes);
wake_up(&conf->wait_for_overlap);
md_done_sync(conf->mddev, STRIPE_SECTORS, 1);
}
if (s.expanding && s.locked == 0 &&
!test_bit(STRIPE_COMPUTE_RUN, &sh->state))
handle_stripe_expansion(conf, sh);
finish:
if (conf->mddev->external && unlikely(s.blocked_rdev))
md_wait_for_blocked_rdev(s.blocked_rdev, conf->mddev);
if (s.handle_bad_blocks)
for (i = disks; i--; ) {
mdk_rdev_t *rdev;
struct r5dev *dev = &sh->dev[i];
if (test_and_clear_bit(R5_WriteError, &dev->flags)) {
rdev = conf->disks[i].rdev;
if (!rdev_set_badblocks(rdev, sh->sector,
STRIPE_SECTORS, 0))
md_error(conf->mddev, rdev);
rdev_dec_pending(rdev, conf->mddev);
}
if (test_and_clear_bit(R5_MadeGood, &dev->flags)) {
rdev = conf->disks[i].rdev;
rdev_clear_badblocks(rdev, sh->sector,
STRIPE_SECTORS);
rdev_dec_pending(rdev, conf->mddev);
}
}
if (s.ops_request)
raid_run_ops(sh, s.ops_request);
ops_run_io(sh, &s);
if (s.dec_preread_active) {
atomic_dec(&conf->preread_active_stripes);
if (atomic_read(&conf->preread_active_stripes) <
IO_THRESHOLD)
md_wakeup_thread(conf->mddev->thread);
}
return_io(s.return_bi);
clear_bit(STRIPE_ACTIVE, &sh->state);
}
static void raid5_activate_delayed(raid5_conf_t *conf)
{
if (atomic_read(&conf->preread_active_stripes) < IO_THRESHOLD) {
while (!list_empty(&conf->delayed_list)) {
struct list_head *l = conf->delayed_list.next;
struct stripe_head *sh;
sh = list_entry(l, struct stripe_head, lru);
list_del_init(l);
clear_bit(STRIPE_DELAYED, &sh->state);
if (!test_and_set_bit(STRIPE_PREREAD_ACTIVE, &sh->state))
atomic_inc(&conf->preread_active_stripes);
list_add_tail(&sh->lru, &conf->hold_list);
}
}
}
static void activate_bit_delay(raid5_conf_t *conf)
{
struct list_head head;
list_add(&head, &conf->bitmap_list);
list_del_init(&conf->bitmap_list);
while (!list_empty(&head)) {
struct stripe_head *sh = list_entry(head.next, struct stripe_head, lru);
list_del_init(&sh->lru);
atomic_inc(&sh->count);
__release_stripe(conf, sh);
}
}
int md_raid5_congested(mddev_t *mddev, int bits)
{
raid5_conf_t *conf = mddev->private;
if (conf->inactive_blocked)
return 1;
if (conf->quiesce)
return 1;
if (list_empty_careful(&conf->inactive_list))
return 1;
return 0;
}
static int raid5_congested(void *data, int bits)
{
mddev_t *mddev = data;
return mddev_congested(mddev, bits) ||
md_raid5_congested(mddev, bits);
}
static int raid5_mergeable_bvec(struct request_queue *q,
struct bvec_merge_data *bvm,
struct bio_vec *biovec)
{
mddev_t *mddev = q->queuedata;
sector_t sector = bvm->bi_sector + get_start_sect(bvm->bi_bdev);
int max;
unsigned int chunk_sectors = mddev->chunk_sectors;
unsigned int bio_sectors = bvm->bi_size >> 9;
if ((bvm->bi_rw & 1) == WRITE)
return biovec->bv_len;
if (mddev->new_chunk_sectors < mddev->chunk_sectors)
chunk_sectors = mddev->new_chunk_sectors;
max = (chunk_sectors - ((sector & (chunk_sectors - 1)) + bio_sectors)) << 9;
if (max < 0) max = 0;
if (max <= biovec->bv_len && bio_sectors == 0)
return biovec->bv_len;
else
return max;
}
static int in_chunk_boundary(mddev_t *mddev, struct bio *bio)
{
sector_t sector = bio->bi_sector + get_start_sect(bio->bi_bdev);
unsigned int chunk_sectors = mddev->chunk_sectors;
unsigned int bio_sectors = bio->bi_size >> 9;
if (mddev->new_chunk_sectors < mddev->chunk_sectors)
chunk_sectors = mddev->new_chunk_sectors;
return chunk_sectors >=
((sector & (chunk_sectors - 1)) + bio_sectors);
}
static void add_bio_to_retry(struct bio *bi,raid5_conf_t *conf)
{
unsigned long flags;
spin_lock_irqsave(&conf->device_lock, flags);
bi->bi_next = conf->retry_read_aligned_list;
conf->retry_read_aligned_list = bi;
spin_unlock_irqrestore(&conf->device_lock, flags);
md_wakeup_thread(conf->mddev->thread);
}
static struct bio *remove_bio_from_retry(raid5_conf_t *conf)
{
struct bio *bi;
bi = conf->retry_read_aligned;
if (bi) {
conf->retry_read_aligned = NULL;
return bi;
}
bi = conf->retry_read_aligned_list;
if(bi) {
conf->retry_read_aligned_list = bi->bi_next;
bi->bi_next = NULL;
bi->bi_phys_segments = 1;
}
return bi;
}
static void raid5_align_endio(struct bio *bi, int error)
{
struct bio* raid_bi = bi->bi_private;
mddev_t *mddev;
raid5_conf_t *conf;
int uptodate = test_bit(BIO_UPTODATE, &bi->bi_flags);
mdk_rdev_t *rdev;
bio_put(bi);
rdev = (void*)raid_bi->bi_next;
raid_bi->bi_next = NULL;
mddev = rdev->mddev;
conf = mddev->private;
rdev_dec_pending(rdev, conf->mddev);
if (!error && uptodate) {
bio_endio(raid_bi, 0);
if (atomic_dec_and_test(&conf->active_aligned_reads))
wake_up(&conf->wait_for_stripe);
return;
}
pr_debug("raid5_align_endio : io error...handing IO for a retry\n");
add_bio_to_retry(raid_bi, conf);
}
static int bio_fits_rdev(struct bio *bi)
{
struct request_queue *q = bdev_get_queue(bi->bi_bdev);
if ((bi->bi_size>>9) > queue_max_sectors(q))
return 0;
blk_recount_segments(q, bi);
if (bi->bi_phys_segments > queue_max_segments(q))
return 0;
if (q->merge_bvec_fn)
return 0;
return 1;
}
static int chunk_aligned_read(mddev_t *mddev, struct bio * raid_bio)
{
raid5_conf_t *conf = mddev->private;
int dd_idx;
struct bio* align_bi;
mdk_rdev_t *rdev;
if (!in_chunk_boundary(mddev, raid_bio)) {
pr_debug("chunk_aligned_read : non aligned\n");
return 0;
}
align_bi = bio_clone_mddev(raid_bio, GFP_NOIO, mddev);
if (!align_bi)
return 0;
align_bi->bi_end_io = raid5_align_endio;
align_bi->bi_private = raid_bio;
align_bi->bi_sector = raid5_compute_sector(conf, raid_bio->bi_sector,
0,
&dd_idx, NULL);
rcu_read_lock();
rdev = rcu_dereference(conf->disks[dd_idx].rdev);
if (rdev && test_bit(In_sync, &rdev->flags)) {
sector_t first_bad;
int bad_sectors;
atomic_inc(&rdev->nr_pending);
rcu_read_unlock();
raid_bio->bi_next = (void*)rdev;
align_bi->bi_bdev = rdev->bdev;
align_bi->bi_flags &= ~(1 << BIO_SEG_VALID);
align_bi->bi_sector += rdev->data_offset;
if (!bio_fits_rdev(align_bi) ||
is_badblock(rdev, align_bi->bi_sector, align_bi->bi_size>>9,
&first_bad, &bad_sectors)) {
bio_put(align_bi);
rdev_dec_pending(rdev, mddev);
return 0;
}
spin_lock_irq(&conf->device_lock);
wait_event_lock_irq(conf->wait_for_stripe,
conf->quiesce == 0,
conf->device_lock, );
atomic_inc(&conf->active_aligned_reads);
spin_unlock_irq(&conf->device_lock);
generic_make_request(align_bi);
return 1;
} else {
rcu_read_unlock();
bio_put(align_bi);
return 0;
}
}
static struct stripe_head *__get_priority_stripe(raid5_conf_t *conf)
{
struct stripe_head *sh;
pr_debug("%s: handle: %s hold: %s full_writes: %d bypass_count: %d\n",
__func__,
list_empty(&conf->handle_list) ? "empty" : "busy",
list_empty(&conf->hold_list) ? "empty" : "busy",
atomic_read(&conf->pending_full_writes), conf->bypass_count);
if (!list_empty(&conf->handle_list)) {
sh = list_entry(conf->handle_list.next, typeof(*sh), lru);
if (list_empty(&conf->hold_list))
conf->bypass_count = 0;
else if (!test_bit(STRIPE_IO_STARTED, &sh->state)) {
if (conf->hold_list.next == conf->last_hold)
conf->bypass_count++;
else {
conf->last_hold = conf->hold_list.next;
conf->bypass_count -= conf->bypass_threshold;
if (conf->bypass_count < 0)
conf->bypass_count = 0;
}
}
} else if (!list_empty(&conf->hold_list) &&
((conf->bypass_threshold &&
conf->bypass_count > conf->bypass_threshold) ||
atomic_read(&conf->pending_full_writes) == 0)) {
sh = list_entry(conf->hold_list.next,
typeof(*sh), lru);
conf->bypass_count -= conf->bypass_threshold;
if (conf->bypass_count < 0)
conf->bypass_count = 0;
} else
return NULL;
list_del_init(&sh->lru);
atomic_inc(&sh->count);
BUG_ON(atomic_read(&sh->count) != 1);
return sh;
}
static int make_request(mddev_t *mddev, struct bio * bi)
{
raid5_conf_t *conf = mddev->private;
int dd_idx;
sector_t new_sector;
sector_t logical_sector, last_sector;
struct stripe_head *sh;
const int rw = bio_data_dir(bi);
int remaining;
int plugged;
if (unlikely(bi->bi_rw & REQ_FLUSH)) {
md_flush_request(mddev, bi);
return 0;
}
md_write_start(mddev, bi);
if (rw == READ &&
mddev->reshape_position == MaxSector &&
chunk_aligned_read(mddev,bi))
return 0;
logical_sector = bi->bi_sector & ~((sector_t)STRIPE_SECTORS-1);
last_sector = bi->bi_sector + (bi->bi_size>>9);
bi->bi_next = NULL;
bi->bi_phys_segments = 1;
plugged = mddev_check_plugged(mddev);
for (;logical_sector < last_sector; logical_sector += STRIPE_SECTORS) {
DEFINE_WAIT(w);
int disks, data_disks;
int previous;
retry:
previous = 0;
disks = conf->raid_disks;
prepare_to_wait(&conf->wait_for_overlap, &w, TASK_UNINTERRUPTIBLE);
if (unlikely(conf->reshape_progress != MaxSector)) {
spin_lock_irq(&conf->device_lock);
if (mddev->delta_disks < 0
? logical_sector < conf->reshape_progress
: logical_sector >= conf->reshape_progress) {
disks = conf->previous_raid_disks;
previous = 1;
} else {
if (mddev->delta_disks < 0
? logical_sector < conf->reshape_safe
: logical_sector >= conf->reshape_safe) {
spin_unlock_irq(&conf->device_lock);
schedule();
goto retry;
}
}
spin_unlock_irq(&conf->device_lock);
}
data_disks = disks - conf->max_degraded;
new_sector = raid5_compute_sector(conf, logical_sector,
previous,
&dd_idx, NULL);
pr_debug("raid456: make_request, sector %llu logical %llu\n",
(unsigned long long)new_sector,
(unsigned long long)logical_sector);
sh = get_active_stripe(conf, new_sector, previous,
(bi->bi_rw&RWA_MASK), 0);
if (sh) {
if (unlikely(previous)) {
int must_retry = 0;
spin_lock_irq(&conf->device_lock);
if (mddev->delta_disks < 0
? logical_sector >= conf->reshape_progress
: logical_sector < conf->reshape_progress)
must_retry = 1;
spin_unlock_irq(&conf->device_lock);
if (must_retry) {
release_stripe(sh);
schedule();
goto retry;
}
}
if (rw == WRITE &&
logical_sector >= mddev->suspend_lo &&
logical_sector < mddev->suspend_hi) {
release_stripe(sh);
flush_signals(current);
prepare_to_wait(&conf->wait_for_overlap,
&w, TASK_INTERRUPTIBLE);
if (logical_sector >= mddev->suspend_lo &&
logical_sector < mddev->suspend_hi)
schedule();
goto retry;
}
if (test_bit(STRIPE_EXPANDING, &sh->state) ||
!add_stripe_bio(sh, bi, dd_idx, rw)) {
md_wakeup_thread(mddev->thread);
release_stripe(sh);
schedule();
goto retry;
}
finish_wait(&conf->wait_for_overlap, &w);
set_bit(STRIPE_HANDLE, &sh->state);
clear_bit(STRIPE_DELAYED, &sh->state);
if ((bi->bi_rw & REQ_SYNC) &&
!test_and_set_bit(STRIPE_PREREAD_ACTIVE, &sh->state))
atomic_inc(&conf->preread_active_stripes);
release_stripe(sh);
} else {
clear_bit(BIO_UPTODATE, &bi->bi_flags);
finish_wait(&conf->wait_for_overlap, &w);
break;
}
}
if (!plugged)
md_wakeup_thread(mddev->thread);
spin_lock_irq(&conf->device_lock);
remaining = raid5_dec_bi_phys_segments(bi);
spin_unlock_irq(&conf->device_lock);
if (remaining == 0) {
if ( rw == WRITE )
md_write_end(mddev);
bio_endio(bi, 0);
}
return 0;
}
static sector_t reshape_request(mddev_t *mddev, sector_t sector_nr, int *skipped)
{
raid5_conf_t *conf = mddev->private;
struct stripe_head *sh;
sector_t first_sector, last_sector;
int raid_disks = conf->previous_raid_disks;
int data_disks = raid_disks - conf->max_degraded;
int new_data_disks = conf->raid_disks - conf->max_degraded;
int i;
int dd_idx;
sector_t writepos, readpos, safepos;
sector_t stripe_addr;
int reshape_sectors;
struct list_head stripes;
if (sector_nr == 0) {
if (mddev->delta_disks < 0 &&
conf->reshape_progress < raid5_size(mddev, 0, 0)) {
sector_nr = raid5_size(mddev, 0, 0)
- conf->reshape_progress;
} else if (mddev->delta_disks >= 0 &&
conf->reshape_progress > 0)
sector_nr = conf->reshape_progress;
sector_div(sector_nr, new_data_disks);
if (sector_nr) {
mddev->curr_resync_completed = sector_nr;
sysfs_notify(&mddev->kobj, NULL, "sync_completed");
*skipped = 1;
return sector_nr;
}
}
if (mddev->new_chunk_sectors > mddev->chunk_sectors)
reshape_sectors = mddev->new_chunk_sectors;
else
reshape_sectors = mddev->chunk_sectors;
writepos = conf->reshape_progress;
sector_div(writepos, new_data_disks);
readpos = conf->reshape_progress;
sector_div(readpos, data_disks);
safepos = conf->reshape_safe;
sector_div(safepos, data_disks);
if (mddev->delta_disks < 0) {
writepos -= min_t(sector_t, reshape_sectors, writepos);
readpos += reshape_sectors;
safepos += reshape_sectors;
} else {
writepos += reshape_sectors;
readpos -= min_t(sector_t, reshape_sectors, readpos);
safepos -= min_t(sector_t, reshape_sectors, safepos);
}
if ((mddev->delta_disks < 0
? (safepos > writepos && readpos < writepos)
: (safepos < writepos && readpos > writepos)) ||
time_after(jiffies, conf->reshape_checkpoint + 10*HZ)) {
wait_event(conf->wait_for_overlap,
atomic_read(&conf->reshape_stripes)==0);
mddev->reshape_position = conf->reshape_progress;
mddev->curr_resync_completed = sector_nr;
conf->reshape_checkpoint = jiffies;
set_bit(MD_CHANGE_DEVS, &mddev->flags);
md_wakeup_thread(mddev->thread);
wait_event(mddev->sb_wait, mddev->flags == 0 ||
kthread_should_stop());
spin_lock_irq(&conf->device_lock);
conf->reshape_safe = mddev->reshape_position;
spin_unlock_irq(&conf->device_lock);
wake_up(&conf->wait_for_overlap);
sysfs_notify(&mddev->kobj, NULL, "sync_completed");
}
if (mddev->delta_disks < 0) {
BUG_ON(conf->reshape_progress == 0);
stripe_addr = writepos;
BUG_ON((mddev->dev_sectors &
~((sector_t)reshape_sectors - 1))
- reshape_sectors - stripe_addr
!= sector_nr);
} else {
BUG_ON(writepos != sector_nr + reshape_sectors);
stripe_addr = sector_nr;
}
INIT_LIST_HEAD(&stripes);
for (i = 0; i < reshape_sectors; i += STRIPE_SECTORS) {
int j;
int skipped_disk = 0;
sh = get_active_stripe(conf, stripe_addr+i, 0, 0, 1);
set_bit(STRIPE_EXPANDING, &sh->state);
atomic_inc(&conf->reshape_stripes);
for (j=sh->disks; j--;) {
sector_t s;
if (j == sh->pd_idx)
continue;
if (conf->level == 6 &&
j == sh->qd_idx)
continue;
s = compute_blocknr(sh, j, 0);
if (s < raid5_size(mddev, 0, 0)) {
skipped_disk = 1;
continue;
}
memset(page_address(sh->dev[j].page), 0, STRIPE_SIZE);
set_bit(R5_Expanded, &sh->dev[j].flags);
set_bit(R5_UPTODATE, &sh->dev[j].flags);
}
if (!skipped_disk) {
set_bit(STRIPE_EXPAND_READY, &sh->state);
set_bit(STRIPE_HANDLE, &sh->state);
}
list_add(&sh->lru, &stripes);
}
spin_lock_irq(&conf->device_lock);
if (mddev->delta_disks < 0)
conf->reshape_progress -= reshape_sectors * new_data_disks;
else
conf->reshape_progress += reshape_sectors * new_data_disks;
spin_unlock_irq(&conf->device_lock);
first_sector =
raid5_compute_sector(conf, stripe_addr*(new_data_disks),
1, &dd_idx, NULL);
last_sector =
raid5_compute_sector(conf, ((stripe_addr+reshape_sectors)
* new_data_disks - 1),
1, &dd_idx, NULL);
if (last_sector >= mddev->dev_sectors)
last_sector = mddev->dev_sectors - 1;
while (first_sector <= last_sector) {
sh = get_active_stripe(conf, first_sector, 1, 0, 1);
set_bit(STRIPE_EXPAND_SOURCE, &sh->state);
set_bit(STRIPE_HANDLE, &sh->state);
release_stripe(sh);
first_sector += STRIPE_SECTORS;
}
while (!list_empty(&stripes)) {
sh = list_entry(stripes.next, struct stripe_head, lru);
list_del_init(&sh->lru);
release_stripe(sh);
}
sector_nr += reshape_sectors;
if ((sector_nr - mddev->curr_resync_completed) * 2
>= mddev->resync_max - mddev->curr_resync_completed) {
wait_event(conf->wait_for_overlap,
atomic_read(&conf->reshape_stripes) == 0);
mddev->reshape_position = conf->reshape_progress;
mddev->curr_resync_completed = sector_nr;
conf->reshape_checkpoint = jiffies;
set_bit(MD_CHANGE_DEVS, &mddev->flags);
md_wakeup_thread(mddev->thread);
wait_event(mddev->sb_wait,
!test_bit(MD_CHANGE_DEVS, &mddev->flags)
|| kthread_should_stop());
spin_lock_irq(&conf->device_lock);
conf->reshape_safe = mddev->reshape_position;
spin_unlock_irq(&conf->device_lock);
wake_up(&conf->wait_for_overlap);
sysfs_notify(&mddev->kobj, NULL, "sync_completed");
}
return reshape_sectors;
}
static inline sector_t sync_request(mddev_t *mddev, sector_t sector_nr, int *skipped, int go_faster)
{
raid5_conf_t *conf = mddev->private;
struct stripe_head *sh;
sector_t max_sector = mddev->dev_sectors;
sector_t sync_blocks;
int still_degraded = 0;
int i;
if (sector_nr >= max_sector) {
if (test_bit(MD_RECOVERY_RESHAPE, &mddev->recovery)) {
end_reshape(conf);
return 0;
}
if (mddev->curr_resync < max_sector)
bitmap_end_sync(mddev->bitmap, mddev->curr_resync,
&sync_blocks, 1);
else
conf->fullsync = 0;
bitmap_close_sync(mddev->bitmap);
return 0;
}
wait_event(conf->wait_for_overlap, conf->quiesce != 2);
if (test_bit(MD_RECOVERY_RESHAPE, &mddev->recovery))
return reshape_request(mddev, sector_nr, skipped);
if (mddev->degraded >= conf->max_degraded &&
test_bit(MD_RECOVERY_SYNC, &mddev->recovery)) {
sector_t rv = mddev->dev_sectors - sector_nr;
*skipped = 1;
return rv;
}
if (!bitmap_start_sync(mddev->bitmap, sector_nr, &sync_blocks, 1) &&
!test_bit(MD_RECOVERY_REQUESTED, &mddev->recovery) &&
!conf->fullsync && sync_blocks >= STRIPE_SECTORS) {
sync_blocks /= STRIPE_SECTORS;
*skipped = 1;
return sync_blocks * STRIPE_SECTORS;
}
bitmap_cond_end_sync(mddev->bitmap, sector_nr);
sh = get_active_stripe(conf, sector_nr, 0, 1, 0);
if (sh == NULL) {
sh = get_active_stripe(conf, sector_nr, 0, 0, 0);
schedule_timeout_uninterruptible(1);
}
for (i = 0; i < conf->raid_disks; i++)
if (conf->disks[i].rdev == NULL)
still_degraded = 1;
bitmap_start_sync(mddev->bitmap, sector_nr, &sync_blocks, still_degraded);
set_bit(STRIPE_SYNC_REQUESTED, &sh->state);
handle_stripe(sh);
release_stripe(sh);
return STRIPE_SECTORS;
}
static int retry_aligned_read(raid5_conf_t *conf, struct bio *raid_bio)
{
struct stripe_head *sh;
int dd_idx;
sector_t sector, logical_sector, last_sector;
int scnt = 0;
int remaining;
int handled = 0;
logical_sector = raid_bio->bi_sector & ~((sector_t)STRIPE_SECTORS-1);
sector = raid5_compute_sector(conf, logical_sector,
0, &dd_idx, NULL);
last_sector = raid_bio->bi_sector + (raid_bio->bi_size>>9);
for (; logical_sector < last_sector;
logical_sector += STRIPE_SECTORS,
sector += STRIPE_SECTORS,
scnt++) {
if (scnt < raid5_bi_hw_segments(raid_bio))
continue;
sh = get_active_stripe(conf, sector, 0, 1, 0);
if (!sh) {
raid5_set_bi_hw_segments(raid_bio, scnt);
conf->retry_read_aligned = raid_bio;
return handled;
}
set_bit(R5_ReadError, &sh->dev[dd_idx].flags);
if (!add_stripe_bio(sh, raid_bio, dd_idx, 0)) {
release_stripe(sh);
raid5_set_bi_hw_segments(raid_bio, scnt);
conf->retry_read_aligned = raid_bio;
return handled;
}
handle_stripe(sh);
release_stripe(sh);
handled++;
}
spin_lock_irq(&conf->device_lock);
remaining = raid5_dec_bi_phys_segments(raid_bio);
spin_unlock_irq(&conf->device_lock);
if (remaining == 0)
bio_endio(raid_bio, 0);
if (atomic_dec_and_test(&conf->active_aligned_reads))
wake_up(&conf->wait_for_stripe);
return handled;
}
static void raid5d(mddev_t *mddev)
{
struct stripe_head *sh;
raid5_conf_t *conf = mddev->private;
int handled;
struct blk_plug plug;
pr_debug("+++ raid5d active\n");
md_check_recovery(mddev);
blk_start_plug(&plug);
handled = 0;
spin_lock_irq(&conf->device_lock);
while (1) {
struct bio *bio;
if (atomic_read(&mddev->plug_cnt) == 0 &&
!list_empty(&conf->bitmap_list)) {
conf->seq_flush++;
spin_unlock_irq(&conf->device_lock);
bitmap_unplug(mddev->bitmap);
spin_lock_irq(&conf->device_lock);
conf->seq_write = conf->seq_flush;
activate_bit_delay(conf);
}
if (atomic_read(&mddev->plug_cnt) == 0)
raid5_activate_delayed(conf);
while ((bio = remove_bio_from_retry(conf))) {
int ok;
spin_unlock_irq(&conf->device_lock);
ok = retry_aligned_read(conf, bio);
spin_lock_irq(&conf->device_lock);
if (!ok)
break;
handled++;
}
sh = __get_priority_stripe(conf);
if (!sh)
break;
spin_unlock_irq(&conf->device_lock);
handled++;
handle_stripe(sh);
release_stripe(sh);
cond_resched();
if (mddev->flags & ~(1<<MD_CHANGE_PENDING))
md_check_recovery(mddev);
spin_lock_irq(&conf->device_lock);
}
pr_debug("%d stripes handled\n", handled);
spin_unlock_irq(&conf->device_lock);
async_tx_issue_pending_all();
blk_finish_plug(&plug);
pr_debug("--- raid5d inactive\n");
}
static ssize_t
raid5_show_stripe_cache_size(mddev_t *mddev, char *page)
{
raid5_conf_t *conf = mddev->private;
if (conf)
return sprintf(page, "%d\n", conf->max_nr_stripes);
else
return 0;
}
int
raid5_set_cache_size(mddev_t *mddev, int size)
{
raid5_conf_t *conf = mddev->private;
int err;
if (size <= 16 || size > 32768)
return -EINVAL;
while (size < conf->max_nr_stripes) {
if (drop_one_stripe(conf))
conf->max_nr_stripes--;
else
break;
}
err = md_allow_write(mddev);
if (err)
return err;
while (size > conf->max_nr_stripes) {
if (grow_one_stripe(conf))
conf->max_nr_stripes++;
else break;
}
return 0;
}
static ssize_t
raid5_store_stripe_cache_size(mddev_t *mddev, const char *page, size_t len)
{
raid5_conf_t *conf = mddev->private;
unsigned long new;
int err;
if (len >= PAGE_SIZE)
return -EINVAL;
if (!conf)
return -ENODEV;
if (strict_strtoul(page, 10, &new))
return -EINVAL;
err = raid5_set_cache_size(mddev, new);
if (err)
return err;
return len;
}
static ssize_t
raid5_show_preread_threshold(mddev_t *mddev, char *page)
{
raid5_conf_t *conf = mddev->private;
if (conf)
return sprintf(page, "%d\n", conf->bypass_threshold);
else
return 0;
}
static ssize_t
raid5_store_preread_threshold(mddev_t *mddev, const char *page, size_t len)
{
raid5_conf_t *conf = mddev->private;
unsigned long new;
if (len >= PAGE_SIZE)
return -EINVAL;
if (!conf)
return -ENODEV;
if (strict_strtoul(page, 10, &new))
return -EINVAL;
if (new > conf->max_nr_stripes)
return -EINVAL;
conf->bypass_threshold = new;
return len;
}
static ssize_t
stripe_cache_active_show(mddev_t *mddev, char *page)
{
raid5_conf_t *conf = mddev->private;
if (conf)
return sprintf(page, "%d\n", atomic_read(&conf->active_stripes));
else
return 0;
}
static sector_t
raid5_size(mddev_t *mddev, sector_t sectors, int raid_disks)
{
raid5_conf_t *conf = mddev->private;
if (!sectors)
sectors = mddev->dev_sectors;
if (!raid_disks)
raid_disks = min(conf->raid_disks, conf->previous_raid_disks);
sectors &= ~((sector_t)mddev->chunk_sectors - 1);
sectors &= ~((sector_t)mddev->new_chunk_sectors - 1);
return sectors * (raid_disks - conf->max_degraded);
}
static void raid5_free_percpu(raid5_conf_t *conf)
{
struct raid5_percpu *percpu;
unsigned long cpu;
if (!conf->percpu)
return;
get_online_cpus();
for_each_possible_cpu(cpu) {
percpu = per_cpu_ptr(conf->percpu, cpu);
safe_put_page(percpu->spare_page);
kfree(percpu->scribble);
}
#ifdef CONFIG_HOTPLUG_CPU
unregister_cpu_notifier(&conf->cpu_notify);
#endif
put_online_cpus();
free_percpu(conf->percpu);
}
static void free_conf(raid5_conf_t *conf)
{
shrink_stripes(conf);
raid5_free_percpu(conf);
kfree(conf->disks);
kfree(conf->stripe_hashtbl);
kfree(conf);
}
static int raid456_cpu_notify(struct notifier_block *nfb, unsigned long action,
void *hcpu)
{
raid5_conf_t *conf = container_of(nfb, raid5_conf_t, cpu_notify);
long cpu = (long)hcpu;
struct raid5_percpu *percpu = per_cpu_ptr(conf->percpu, cpu);
switch (action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
if (conf->level == 6 && !percpu->spare_page)
percpu->spare_page = alloc_page(GFP_KERNEL);
if (!percpu->scribble)
percpu->scribble = kmalloc(conf->scribble_len, GFP_KERNEL);
if (!percpu->scribble ||
(conf->level == 6 && !percpu->spare_page)) {
safe_put_page(percpu->spare_page);
kfree(percpu->scribble);
pr_err("%s: failed memory allocation for cpu%ld\n",
__func__, cpu);
return notifier_from_errno(-ENOMEM);
}
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
safe_put_page(percpu->spare_page);
kfree(percpu->scribble);
percpu->spare_page = NULL;
percpu->scribble = NULL;
break;
default:
break;
}
return NOTIFY_OK;
}
static int raid5_alloc_percpu(raid5_conf_t *conf)
{
unsigned long cpu;
struct page *spare_page;
struct raid5_percpu __percpu *allcpus;
void *scribble;
int err;
allcpus = alloc_percpu(struct raid5_percpu);
if (!allcpus)
return -ENOMEM;
conf->percpu = allcpus;
get_online_cpus();
err = 0;
for_each_present_cpu(cpu) {
if (conf->level == 6) {
spare_page = alloc_page(GFP_KERNEL);
if (!spare_page) {
err = -ENOMEM;
break;
}
per_cpu_ptr(conf->percpu, cpu)->spare_page = spare_page;
}
scribble = kmalloc(conf->scribble_len, GFP_KERNEL);
if (!scribble) {
err = -ENOMEM;
break;
}
per_cpu_ptr(conf->percpu, cpu)->scribble = scribble;
}
#ifdef CONFIG_HOTPLUG_CPU
conf->cpu_notify.notifier_call = raid456_cpu_notify;
conf->cpu_notify.priority = 0;
if (err == 0)
err = register_cpu_notifier(&conf->cpu_notify);
#endif
put_online_cpus();
return err;
}
static raid5_conf_t *setup_conf(mddev_t *mddev)
{
raid5_conf_t *conf;
int raid_disk, memory, max_disks;
mdk_rdev_t *rdev;
struct disk_info *disk;
if (mddev->new_level != 5
&& mddev->new_level != 4
&& mddev->new_level != 6) {
printk(KERN_ERR "md/raid:%s: raid level not set to 4/5/6 (%d)\n",
mdname(mddev), mddev->new_level);
return ERR_PTR(-EIO);
}
if ((mddev->new_level == 5
&& !algorithm_valid_raid5(mddev->new_layout)) ||
(mddev->new_level == 6
&& !algorithm_valid_raid6(mddev->new_layout))) {
printk(KERN_ERR "md/raid:%s: layout %d not supported\n",
mdname(mddev), mddev->new_layout);
return ERR_PTR(-EIO);
}
if (mddev->new_level == 6 && mddev->raid_disks < 4) {
printk(KERN_ERR "md/raid:%s: not enough configured devices (%d, minimum 4)\n",
mdname(mddev), mddev->raid_disks);
return ERR_PTR(-EINVAL);
}
if (!mddev->new_chunk_sectors ||
(mddev->new_chunk_sectors << 9) % PAGE_SIZE ||
!is_power_of_2(mddev->new_chunk_sectors)) {
printk(KERN_ERR "md/raid:%s: invalid chunk size %d\n",
mdname(mddev), mddev->new_chunk_sectors << 9);
return ERR_PTR(-EINVAL);
}
conf = kzalloc(sizeof(raid5_conf_t), GFP_KERNEL);
if (conf == NULL)
goto abort;
spin_lock_init(&conf->device_lock);
init_waitqueue_head(&conf->wait_for_stripe);
init_waitqueue_head(&conf->wait_for_overlap);
INIT_LIST_HEAD(&conf->handle_list);
INIT_LIST_HEAD(&conf->hold_list);
INIT_LIST_HEAD(&conf->delayed_list);
INIT_LIST_HEAD(&conf->bitmap_list);
INIT_LIST_HEAD(&conf->inactive_list);
atomic_set(&conf->active_stripes, 0);
atomic_set(&conf->preread_active_stripes, 0);
atomic_set(&conf->active_aligned_reads, 0);
conf->bypass_threshold = BYPASS_THRESHOLD;
conf->raid_disks = mddev->raid_disks;
if (mddev->reshape_position == MaxSector)
conf->previous_raid_disks = mddev->raid_disks;
else
conf->previous_raid_disks = mddev->raid_disks - mddev->delta_disks;
max_disks = max(conf->raid_disks, conf->previous_raid_disks);
conf->scribble_len = scribble_len(max_disks);
conf->disks = kzalloc(max_disks * sizeof(struct disk_info),
GFP_KERNEL);
if (!conf->disks)
goto abort;
conf->mddev = mddev;
if ((conf->stripe_hashtbl = kzalloc(PAGE_SIZE, GFP_KERNEL)) == NULL)
goto abort;
conf->level = mddev->new_level;
if (raid5_alloc_percpu(conf) != 0)
goto abort;
pr_debug("raid456: run(%s) called.\n", mdname(mddev));
list_for_each_entry(rdev, &mddev->disks, same_set) {
raid_disk = rdev->raid_disk;
if (raid_disk >= max_disks
|| raid_disk < 0)
continue;
disk = conf->disks + raid_disk;
disk->rdev = rdev;
if (test_bit(In_sync, &rdev->flags)) {
char b[BDEVNAME_SIZE];
printk(KERN_INFO "md/raid:%s: device %s operational as raid"
" disk %d\n",
mdname(mddev), bdevname(rdev->bdev, b), raid_disk);
} else if (rdev->saved_raid_disk != raid_disk)
conf->fullsync = 1;
}
conf->chunk_sectors = mddev->new_chunk_sectors;
conf->level = mddev->new_level;
if (conf->level == 6)
conf->max_degraded = 2;
else
conf->max_degraded = 1;
conf->algorithm = mddev->new_layout;
conf->max_nr_stripes = NR_STRIPES;
conf->reshape_progress = mddev->reshape_position;
if (conf->reshape_progress != MaxSector) {
conf->prev_chunk_sectors = mddev->chunk_sectors;
conf->prev_algo = mddev->layout;
}
memory = conf->max_nr_stripes * (sizeof(struct stripe_head) +
max_disks * ((sizeof(struct bio) + PAGE_SIZE))) / 1024;
if (grow_stripes(conf, conf->max_nr_stripes)) {
printk(KERN_ERR
"md/raid:%s: couldn't allocate %dkB for buffers\n",
mdname(mddev), memory);
goto abort;
} else
printk(KERN_INFO "md/raid:%s: allocated %dkB\n",
mdname(mddev), memory);
conf->thread = md_register_thread(raid5d, mddev, NULL);
if (!conf->thread) {
printk(KERN_ERR
"md/raid:%s: couldn't allocate thread.\n",
mdname(mddev));
goto abort;
}
return conf;
abort:
if (conf) {
free_conf(conf);
return ERR_PTR(-EIO);
} else
return ERR_PTR(-ENOMEM);
}
static int only_parity(int raid_disk, int algo, int raid_disks, int max_degraded)
{
switch (algo) {
case ALGORITHM_PARITY_0:
if (raid_disk < max_degraded)
return 1;
break;
case ALGORITHM_PARITY_N:
if (raid_disk >= raid_disks - max_degraded)
return 1;
break;
case ALGORITHM_PARITY_0_6:
if (raid_disk == 0 ||
raid_disk == raid_disks - 1)
return 1;
break;
case ALGORITHM_LEFT_ASYMMETRIC_6:
case ALGORITHM_RIGHT_ASYMMETRIC_6:
case ALGORITHM_LEFT_SYMMETRIC_6:
case ALGORITHM_RIGHT_SYMMETRIC_6:
if (raid_disk == raid_disks - 1)
return 1;
}
return 0;
}
static int run(mddev_t *mddev)
{
raid5_conf_t *conf;
int working_disks = 0;
int dirty_parity_disks = 0;
mdk_rdev_t *rdev;
sector_t reshape_offset = 0;
if (mddev->recovery_cp != MaxSector)
printk(KERN_NOTICE "md/raid:%s: not clean"
" -- starting background reconstruction\n",
mdname(mddev));
if (mddev->reshape_position != MaxSector) {
sector_t here_new, here_old;
int old_disks;
int max_degraded = (mddev->level == 6 ? 2 : 1);
if (mddev->new_level != mddev->level) {
printk(KERN_ERR "md/raid:%s: unsupported reshape "
"required - aborting.\n",
mdname(mddev));
return -EINVAL;
}
old_disks = mddev->raid_disks - mddev->delta_disks;
here_new = mddev->reshape_position;
if (sector_div(here_new, mddev->new_chunk_sectors *
(mddev->raid_disks - max_degraded))) {
printk(KERN_ERR "md/raid:%s: reshape_position not "
"on a stripe boundary\n", mdname(mddev));
return -EINVAL;
}
reshape_offset = here_new * mddev->new_chunk_sectors;
here_old = mddev->reshape_position;
sector_div(here_old, mddev->chunk_sectors *
(old_disks-max_degraded));
if (mddev->delta_disks == 0) {
if ((here_new * mddev->new_chunk_sectors !=
here_old * mddev->chunk_sectors) ||
mddev->ro == 0) {
printk(KERN_ERR "md/raid:%s: in-place reshape must be started"
" in read-only mode - aborting\n",
mdname(mddev));
return -EINVAL;
}
} else if (mddev->delta_disks < 0
? (here_new * mddev->new_chunk_sectors <=
here_old * mddev->chunk_sectors)
: (here_new * mddev->new_chunk_sectors >=
here_old * mddev->chunk_sectors)) {
printk(KERN_ERR "md/raid:%s: reshape_position too early for "
"auto-recovery - aborting.\n",
mdname(mddev));
return -EINVAL;
}
printk(KERN_INFO "md/raid:%s: reshape will continue\n",
mdname(mddev));
} else {
BUG_ON(mddev->level != mddev->new_level);
BUG_ON(mddev->layout != mddev->new_layout);
BUG_ON(mddev->chunk_sectors != mddev->new_chunk_sectors);
BUG_ON(mddev->delta_disks != 0);
}
if (mddev->private == NULL)
conf = setup_conf(mddev);
else
conf = mddev->private;
if (IS_ERR(conf))
return PTR_ERR(conf);
mddev->thread = conf->thread;
conf->thread = NULL;
mddev->private = conf;
list_for_each_entry(rdev, &mddev->disks, same_set) {
if (rdev->raid_disk < 0)
continue;
if (test_bit(In_sync, &rdev->flags)) {
working_disks++;
continue;
}
if (mddev->major_version == 0 &&
mddev->minor_version > 90)
rdev->recovery_offset = reshape_offset;
if (rdev->recovery_offset < reshape_offset) {
if (!only_parity(rdev->raid_disk,
conf->algorithm,
conf->raid_disks,
conf->max_degraded))
continue;
}
if (!only_parity(rdev->raid_disk,
conf->prev_algo,
conf->previous_raid_disks,
conf->max_degraded))
continue;
dirty_parity_disks++;
}
mddev->degraded = (max(conf->raid_disks, conf->previous_raid_disks)
- working_disks);
if (has_failed(conf)) {
printk(KERN_ERR "md/raid:%s: not enough operational devices"
" (%d/%d failed)\n",
mdname(mddev), mddev->degraded, conf->raid_disks);
goto abort;
}
mddev->dev_sectors &= ~(mddev->chunk_sectors - 1);
mddev->resync_max_sectors = mddev->dev_sectors;
if (mddev->degraded > dirty_parity_disks &&
mddev->recovery_cp != MaxSector) {
if (mddev->ok_start_degraded)
printk(KERN_WARNING
"md/raid:%s: starting dirty degraded array"
" - data corruption possible.\n",
mdname(mddev));
else {
printk(KERN_ERR
"md/raid:%s: cannot start dirty degraded array.\n",
mdname(mddev));
goto abort;
}
}
if (mddev->degraded == 0)
printk(KERN_INFO "md/raid:%s: raid level %d active with %d out of %d"
" devices, algorithm %d\n", mdname(mddev), conf->level,
mddev->raid_disks-mddev->degraded, mddev->raid_disks,
mddev->new_layout);
else
printk(KERN_ALERT "md/raid:%s: raid level %d active with %d"
" out of %d devices, algorithm %d\n",
mdname(mddev), conf->level,
mddev->raid_disks - mddev->degraded,
mddev->raid_disks, mddev->new_layout);
print_raid5_conf(conf);
if (conf->reshape_progress != MaxSector) {
conf->reshape_safe = conf->reshape_progress;
atomic_set(&conf->reshape_stripes, 0);
clear_bit(MD_RECOVERY_SYNC, &mddev->recovery);
clear_bit(MD_RECOVERY_CHECK, &mddev->recovery);
set_bit(MD_RECOVERY_RESHAPE, &mddev->recovery);
set_bit(MD_RECOVERY_RUNNING, &mddev->recovery);
mddev->sync_thread = md_register_thread(md_do_sync, mddev,
"reshape");
}
if (mddev->to_remove == &raid5_attrs_group)
mddev->to_remove = NULL;
else if (mddev->kobj.sd &&
sysfs_create_group(&mddev->kobj, &raid5_attrs_group))
printk(KERN_WARNING
"raid5: failed to create sysfs attributes for %s\n",
mdname(mddev));
md_set_array_sectors(mddev, raid5_size(mddev, 0, 0));
if (mddev->queue) {
int chunk_size;
int data_disks = conf->previous_raid_disks - conf->max_degraded;
int stripe = data_disks *
((mddev->chunk_sectors << 9) / PAGE_SIZE);
if (mddev->queue->backing_dev_info.ra_pages < 2 * stripe)
mddev->queue->backing_dev_info.ra_pages = 2 * stripe;
blk_queue_merge_bvec(mddev->queue, raid5_mergeable_bvec);
mddev->queue->backing_dev_info.congested_data = mddev;
mddev->queue->backing_dev_info.congested_fn = raid5_congested;
chunk_size = mddev->chunk_sectors << 9;
blk_queue_io_min(mddev->queue, chunk_size);
blk_queue_io_opt(mddev->queue, chunk_size *
(conf->raid_disks - conf->max_degraded));
list_for_each_entry(rdev, &mddev->disks, same_set)
disk_stack_limits(mddev->gendisk, rdev->bdev,
rdev->data_offset << 9);
}
return 0;
abort:
md_unregister_thread(&mddev->thread);
if (conf) {
print_raid5_conf(conf);
free_conf(conf);
}
mddev->private = NULL;
printk(KERN_ALERT "md/raid:%s: failed to run raid set.\n", mdname(mddev));
return -EIO;
}
static int stop(mddev_t *mddev)
{
raid5_conf_t *conf = mddev->private;
md_unregister_thread(&mddev->thread);
if (mddev->queue)
mddev->queue->backing_dev_info.congested_fn = NULL;
free_conf(conf);
mddev->private = NULL;
mddev->to_remove = &raid5_attrs_group;
return 0;
}
static void print_sh(struct seq_file *seq, struct stripe_head *sh)
{
int i;
seq_printf(seq, "sh %llu, pd_idx %d, state %ld.\n",
(unsigned long long)sh->sector, sh->pd_idx, sh->state);
seq_printf(seq, "sh %llu, count %d.\n",
(unsigned long long)sh->sector, atomic_read(&sh->count));
seq_printf(seq, "sh %llu, ", (unsigned long long)sh->sector);
for (i = 0; i < sh->disks; i++) {
seq_printf(seq, "(cache%d: %p %ld) ",
i, sh->dev[i].page, sh->dev[i].flags);
}
seq_printf(seq, "\n");
}
static void printall(struct seq_file *seq, raid5_conf_t *conf)
{
struct stripe_head *sh;
struct hlist_node *hn;
int i;
spin_lock_irq(&conf->device_lock);
for (i = 0; i < NR_HASH; i++) {
hlist_for_each_entry(sh, hn, &conf->stripe_hashtbl[i], hash) {
if (sh->raid_conf != conf)
continue;
print_sh(seq, sh);
}
}
spin_unlock_irq(&conf->device_lock);
}
static void status(struct seq_file *seq, mddev_t *mddev)
{
raid5_conf_t *conf = mddev->private;
int i;
seq_printf(seq, " level %d, %dk chunk, algorithm %d", mddev->level,
mddev->chunk_sectors / 2, mddev->layout);
seq_printf (seq, " [%d/%d] [", conf->raid_disks, conf->raid_disks - mddev->degraded);
for (i = 0; i < conf->raid_disks; i++)
seq_printf (seq, "%s",
conf->disks[i].rdev &&
test_bit(In_sync, &conf->disks[i].rdev->flags) ? "U" : "_");
seq_printf (seq, "]");
#ifdef DEBUG
seq_printf (seq, "\n");
printall(seq, conf);
#endif
}
static void print_raid5_conf (raid5_conf_t *conf)
{
int i;
struct disk_info *tmp;
printk(KERN_DEBUG "RAID conf printout:\n");
if (!conf) {
printk("(conf==NULL)\n");
return;
}
printk(KERN_DEBUG " --- level:%d rd:%d wd:%d\n", conf->level,
conf->raid_disks,
conf->raid_disks - conf->mddev->degraded);
for (i = 0; i < conf->raid_disks; i++) {
char b[BDEVNAME_SIZE];
tmp = conf->disks + i;
if (tmp->rdev)
printk(KERN_DEBUG " disk %d, o:%d, dev:%s\n",
i, !test_bit(Faulty, &tmp->rdev->flags),
bdevname(tmp->rdev->bdev, b));
}
}
static int raid5_spare_active(mddev_t *mddev)
{
int i;
raid5_conf_t *conf = mddev->private;
struct disk_info *tmp;
int count = 0;
unsigned long flags;
for (i = 0; i < conf->raid_disks; i++) {
tmp = conf->disks + i;
if (tmp->rdev
&& tmp->rdev->recovery_offset == MaxSector
&& !test_bit(Faulty, &tmp->rdev->flags)
&& !test_and_set_bit(In_sync, &tmp->rdev->flags)) {
count++;
sysfs_notify_dirent_safe(tmp->rdev->sysfs_state);
}
}
spin_lock_irqsave(&conf->device_lock, flags);
mddev->degraded -= count;
spin_unlock_irqrestore(&conf->device_lock, flags);
print_raid5_conf(conf);
return count;
}
static int raid5_remove_disk(mddev_t *mddev, int number)
{
raid5_conf_t *conf = mddev->private;
int err = 0;
mdk_rdev_t *rdev;
struct disk_info *p = conf->disks + number;
print_raid5_conf(conf);
rdev = p->rdev;
if (rdev) {
if (number >= conf->raid_disks &&
conf->reshape_progress == MaxSector)
clear_bit(In_sync, &rdev->flags);
if (test_bit(In_sync, &rdev->flags) ||
atomic_read(&rdev->nr_pending)) {
err = -EBUSY;
goto abort;
}
if (!test_bit(Faulty, &rdev->flags) &&
mddev->recovery_disabled != conf->recovery_disabled &&
!has_failed(conf) &&
number < conf->raid_disks) {
err = -EBUSY;
goto abort;
}
p->rdev = NULL;
synchronize_rcu();
if (atomic_read(&rdev->nr_pending)) {
err = -EBUSY;
p->rdev = rdev;
}
}
abort:
print_raid5_conf(conf);
return err;
}
static int raid5_add_disk(mddev_t *mddev, mdk_rdev_t *rdev)
{
raid5_conf_t *conf = mddev->private;
int err = -EEXIST;
int disk;
struct disk_info *p;
int first = 0;
int last = conf->raid_disks - 1;
if (mddev->recovery_disabled == conf->recovery_disabled)
return -EBUSY;
if (has_failed(conf))
return -EINVAL;
if (rdev->raid_disk >= 0)
first = last = rdev->raid_disk;
if (rdev->saved_raid_disk >= 0 &&
rdev->saved_raid_disk >= first &&
conf->disks[rdev->saved_raid_disk].rdev == NULL)
disk = rdev->saved_raid_disk;
else
disk = first;
for ( ; disk <= last ; disk++)
if ((p=conf->disks + disk)->rdev == NULL) {
clear_bit(In_sync, &rdev->flags);
rdev->raid_disk = disk;
err = 0;
if (rdev->saved_raid_disk != disk)
conf->fullsync = 1;
rcu_assign_pointer(p->rdev, rdev);
break;
}
print_raid5_conf(conf);
return err;
}
static int raid5_resize(mddev_t *mddev, sector_t sectors)
{
sectors &= ~((sector_t)mddev->chunk_sectors - 1);
md_set_array_sectors(mddev, raid5_size(mddev, sectors,
mddev->raid_disks));
if (mddev->array_sectors >
raid5_size(mddev, sectors, mddev->raid_disks))
return -EINVAL;
set_capacity(mddev->gendisk, mddev->array_sectors);
revalidate_disk(mddev->gendisk);
if (sectors > mddev->dev_sectors &&
mddev->recovery_cp > mddev->dev_sectors) {
mddev->recovery_cp = mddev->dev_sectors;
set_bit(MD_RECOVERY_NEEDED, &mddev->recovery);
}
mddev->dev_sectors = sectors;
mddev->resync_max_sectors = sectors;
return 0;
}
static int check_stripe_cache(mddev_t *mddev)
{
raid5_conf_t *conf = mddev->private;
if (((mddev->chunk_sectors << 9) / STRIPE_SIZE) * 4
> conf->max_nr_stripes ||
((mddev->new_chunk_sectors << 9) / STRIPE_SIZE) * 4
> conf->max_nr_stripes) {
printk(KERN_WARNING "md/raid:%s: reshape: not enough stripes. Needed %lu\n",
mdname(mddev),
((max(mddev->chunk_sectors, mddev->new_chunk_sectors) << 9)
/ STRIPE_SIZE)*4);
return 0;
}
return 1;
}
static int check_reshape(mddev_t *mddev)
{
raid5_conf_t *conf = mddev->private;
if (mddev->delta_disks == 0 &&
mddev->new_layout == mddev->layout &&
mddev->new_chunk_sectors == mddev->chunk_sectors)
return 0;
if (mddev->bitmap)
return -EBUSY;
if (has_failed(conf))
return -EINVAL;
if (mddev->delta_disks < 0) {
int min = 2;
if (mddev->level == 6)
min = 4;
if (mddev->raid_disks + mddev->delta_disks < min)
return -EINVAL;
}
if (!check_stripe_cache(mddev))
return -ENOSPC;
return resize_stripes(conf, conf->raid_disks + mddev->delta_disks);
}
static int raid5_start_reshape(mddev_t *mddev)
{
raid5_conf_t *conf = mddev->private;
mdk_rdev_t *rdev;
int spares = 0;
unsigned long flags;
if (test_bit(MD_RECOVERY_RUNNING, &mddev->recovery))
return -EBUSY;
if (!check_stripe_cache(mddev))
return -ENOSPC;
list_for_each_entry(rdev, &mddev->disks, same_set)
if (!test_bit(In_sync, &rdev->flags)
&& !test_bit(Faulty, &rdev->flags))
spares++;
if (spares - mddev->degraded < mddev->delta_disks - conf->max_degraded)
return -EINVAL;
if (raid5_size(mddev, 0, conf->raid_disks + mddev->delta_disks)
< mddev->array_sectors) {
printk(KERN_ERR "md/raid:%s: array size must be reduced "
"before number of disks\n", mdname(mddev));
return -EINVAL;
}
atomic_set(&conf->reshape_stripes, 0);
spin_lock_irq(&conf->device_lock);
conf->previous_raid_disks = conf->raid_disks;
conf->raid_disks += mddev->delta_disks;
conf->prev_chunk_sectors = conf->chunk_sectors;
conf->chunk_sectors = mddev->new_chunk_sectors;
conf->prev_algo = conf->algorithm;
conf->algorithm = mddev->new_layout;
if (mddev->delta_disks < 0)
conf->reshape_progress = raid5_size(mddev, 0, 0);
else
conf->reshape_progress = 0;
conf->reshape_safe = conf->reshape_progress;
conf->generation++;
spin_unlock_irq(&conf->device_lock);
if (mddev->delta_disks >= 0) {
int added_devices = 0;
list_for_each_entry(rdev, &mddev->disks, same_set)
if (rdev->raid_disk < 0 &&
!test_bit(Faulty, &rdev->flags)) {
if (raid5_add_disk(mddev, rdev) == 0) {
if (rdev->raid_disk
>= conf->previous_raid_disks) {
set_bit(In_sync, &rdev->flags);
added_devices++;
} else
rdev->recovery_offset = 0;
if (sysfs_link_rdev(mddev, rdev))
;
}
} else if (rdev->raid_disk >= conf->previous_raid_disks
&& !test_bit(Faulty, &rdev->flags)) {
set_bit(In_sync, &rdev->flags);
added_devices++;
}
spin_lock_irqsave(&conf->device_lock, flags);
mddev->degraded += (conf->raid_disks - conf->previous_raid_disks)
- added_devices;
spin_unlock_irqrestore(&conf->device_lock, flags);
}
mddev->raid_disks = conf->raid_disks;
mddev->reshape_position = conf->reshape_progress;
set_bit(MD_CHANGE_DEVS, &mddev->flags);
clear_bit(MD_RECOVERY_SYNC, &mddev->recovery);
clear_bit(MD_RECOVERY_CHECK, &mddev->recovery);
set_bit(MD_RECOVERY_RESHAPE, &mddev->recovery);
set_bit(MD_RECOVERY_RUNNING, &mddev->recovery);
mddev->sync_thread = md_register_thread(md_do_sync, mddev,
"reshape");
if (!mddev->sync_thread) {
mddev->recovery = 0;
spin_lock_irq(&conf->device_lock);
mddev->raid_disks = conf->raid_disks = conf->previous_raid_disks;
conf->reshape_progress = MaxSector;
spin_unlock_irq(&conf->device_lock);
return -EAGAIN;
}
conf->reshape_checkpoint = jiffies;
md_wakeup_thread(mddev->sync_thread);
md_new_event(mddev);
return 0;
}
static void end_reshape(raid5_conf_t *conf)
{
if (!test_bit(MD_RECOVERY_INTR, &conf->mddev->recovery)) {
spin_lock_irq(&conf->device_lock);
conf->previous_raid_disks = conf->raid_disks;
conf->reshape_progress = MaxSector;
spin_unlock_irq(&conf->device_lock);
wake_up(&conf->wait_for_overlap);
if (conf->mddev->queue) {
int data_disks = conf->raid_disks - conf->max_degraded;
int stripe = data_disks * ((conf->chunk_sectors << 9)
/ PAGE_SIZE);
if (conf->mddev->queue->backing_dev_info.ra_pages < 2 * stripe)
conf->mddev->queue->backing_dev_info.ra_pages = 2 * stripe;
}
}
}
static void raid5_finish_reshape(mddev_t *mddev)
{
raid5_conf_t *conf = mddev->private;
if (!test_bit(MD_RECOVERY_INTR, &mddev->recovery)) {
if (mddev->delta_disks > 0) {
md_set_array_sectors(mddev, raid5_size(mddev, 0, 0));
set_capacity(mddev->gendisk, mddev->array_sectors);
revalidate_disk(mddev->gendisk);
} else {
int d;
mddev->degraded = conf->raid_disks;
for (d = 0; d < conf->raid_disks ; d++)
if (conf->disks[d].rdev &&
test_bit(In_sync,
&conf->disks[d].rdev->flags))
mddev->degraded--;
for (d = conf->raid_disks ;
d < conf->raid_disks - mddev->delta_disks;
d++) {
mdk_rdev_t *rdev = conf->disks[d].rdev;
if (rdev && raid5_remove_disk(mddev, d) == 0) {
sysfs_unlink_rdev(mddev, rdev);
rdev->raid_disk = -1;
}
}
}
mddev->layout = conf->algorithm;
mddev->chunk_sectors = conf->chunk_sectors;
mddev->reshape_position = MaxSector;
mddev->delta_disks = 0;
}
}
static void raid5_quiesce(mddev_t *mddev, int state)
{
raid5_conf_t *conf = mddev->private;
switch(state) {
case 2:
wake_up(&conf->wait_for_overlap);
break;
case 1:
spin_lock_irq(&conf->device_lock);
conf->quiesce = 2;
wait_event_lock_irq(conf->wait_for_stripe,
atomic_read(&conf->active_stripes) == 0 &&
atomic_read(&conf->active_aligned_reads) == 0,
conf->device_lock, );
conf->quiesce = 1;
spin_unlock_irq(&conf->device_lock);
wake_up(&conf->wait_for_overlap);
break;
case 0:
spin_lock_irq(&conf->device_lock);
conf->quiesce = 0;
wake_up(&conf->wait_for_stripe);
wake_up(&conf->wait_for_overlap);
spin_unlock_irq(&conf->device_lock);
break;
}
}
static void *raid45_takeover_raid0(mddev_t *mddev, int level)
{
struct raid0_private_data *raid0_priv = mddev->private;
sector_t sectors;
if (raid0_priv->nr_strip_zones > 1) {
printk(KERN_ERR "md/raid:%s: cannot takeover raid0 with more than one zone.\n",
mdname(mddev));
return ERR_PTR(-EINVAL);
}
sectors = raid0_priv->strip_zone[0].zone_end;
sector_div(sectors, raid0_priv->strip_zone[0].nb_dev);
mddev->dev_sectors = sectors;
mddev->new_level = level;
mddev->new_layout = ALGORITHM_PARITY_N;
mddev->new_chunk_sectors = mddev->chunk_sectors;
mddev->raid_disks += 1;
mddev->delta_disks = 1;
mddev->recovery_cp = MaxSector;
return setup_conf(mddev);
}
static void *raid5_takeover_raid1(mddev_t *mddev)
{
int chunksect;
if (mddev->raid_disks != 2 ||
mddev->degraded > 1)
return ERR_PTR(-EINVAL);
chunksect = 64*2;
while (chunksect && (mddev->array_sectors & (chunksect-1)))
chunksect >>= 1;
if ((chunksect<<9) < STRIPE_SIZE)
return ERR_PTR(-EINVAL);
mddev->new_level = 5;
mddev->new_layout = ALGORITHM_LEFT_SYMMETRIC;
mddev->new_chunk_sectors = chunksect;
return setup_conf(mddev);
}
static void *raid5_takeover_raid6(mddev_t *mddev)
{
int new_layout;
switch (mddev->layout) {
case ALGORITHM_LEFT_ASYMMETRIC_6:
new_layout = ALGORITHM_LEFT_ASYMMETRIC;
break;
case ALGORITHM_RIGHT_ASYMMETRIC_6:
new_layout = ALGORITHM_RIGHT_ASYMMETRIC;
break;
case ALGORITHM_LEFT_SYMMETRIC_6:
new_layout = ALGORITHM_LEFT_SYMMETRIC;
break;
case ALGORITHM_RIGHT_SYMMETRIC_6:
new_layout = ALGORITHM_RIGHT_SYMMETRIC;
break;
case ALGORITHM_PARITY_0_6:
new_layout = ALGORITHM_PARITY_0;
break;
case ALGORITHM_PARITY_N:
new_layout = ALGORITHM_PARITY_N;
break;
default:
return ERR_PTR(-EINVAL);
}
mddev->new_level = 5;
mddev->new_layout = new_layout;
mddev->delta_disks = -1;
mddev->raid_disks -= 1;
return setup_conf(mddev);
}
static int raid5_check_reshape(mddev_t *mddev)
{
raid5_conf_t *conf = mddev->private;
int new_chunk = mddev->new_chunk_sectors;
if (mddev->new_layout >= 0 && !algorithm_valid_raid5(mddev->new_layout))
return -EINVAL;
if (new_chunk > 0) {
if (!is_power_of_2(new_chunk))
return -EINVAL;
if (new_chunk < (PAGE_SIZE>>9))
return -EINVAL;
if (mddev->array_sectors & (new_chunk-1))
return -EINVAL;
}
if (mddev->raid_disks == 2) {
if (mddev->new_layout >= 0) {
conf->algorithm = mddev->new_layout;
mddev->layout = mddev->new_layout;
}
if (new_chunk > 0) {
conf->chunk_sectors = new_chunk ;
mddev->chunk_sectors = new_chunk;
}
set_bit(MD_CHANGE_DEVS, &mddev->flags);
md_wakeup_thread(mddev->thread);
}
return check_reshape(mddev);
}
static int raid6_check_reshape(mddev_t *mddev)
{
int new_chunk = mddev->new_chunk_sectors;
if (mddev->new_layout >= 0 && !algorithm_valid_raid6(mddev->new_layout))
return -EINVAL;
if (new_chunk > 0) {
if (!is_power_of_2(new_chunk))
return -EINVAL;
if (new_chunk < (PAGE_SIZE >> 9))
return -EINVAL;
if (mddev->array_sectors & (new_chunk-1))
return -EINVAL;
}
return check_reshape(mddev);
}
static void *raid5_takeover(mddev_t *mddev)
{
if (mddev->level == 0)
return raid45_takeover_raid0(mddev, 5);
if (mddev->level == 1)
return raid5_takeover_raid1(mddev);
if (mddev->level == 4) {
mddev->new_layout = ALGORITHM_PARITY_N;
mddev->new_level = 5;
return setup_conf(mddev);
}
if (mddev->level == 6)
return raid5_takeover_raid6(mddev);
return ERR_PTR(-EINVAL);
}
static void *raid4_takeover(mddev_t *mddev)
{
if (mddev->level == 0)
return raid45_takeover_raid0(mddev, 4);
if (mddev->level == 5 &&
mddev->layout == ALGORITHM_PARITY_N) {
mddev->new_layout = 0;
mddev->new_level = 4;
return setup_conf(mddev);
}
return ERR_PTR(-EINVAL);
}
static void *raid6_takeover(mddev_t *mddev)
{
int new_layout;
if (mddev->pers != &raid5_personality)
return ERR_PTR(-EINVAL);
if (mddev->degraded > 1)
return ERR_PTR(-EINVAL);
if (mddev->raid_disks > 253)
return ERR_PTR(-EINVAL);
if (mddev->raid_disks < 3)
return ERR_PTR(-EINVAL);
switch (mddev->layout) {
case ALGORITHM_LEFT_ASYMMETRIC:
new_layout = ALGORITHM_LEFT_ASYMMETRIC_6;
break;
case ALGORITHM_RIGHT_ASYMMETRIC:
new_layout = ALGORITHM_RIGHT_ASYMMETRIC_6;
break;
case ALGORITHM_LEFT_SYMMETRIC:
new_layout = ALGORITHM_LEFT_SYMMETRIC_6;
break;
case ALGORITHM_RIGHT_SYMMETRIC:
new_layout = ALGORITHM_RIGHT_SYMMETRIC_6;
break;
case ALGORITHM_PARITY_0:
new_layout = ALGORITHM_PARITY_0_6;
break;
case ALGORITHM_PARITY_N:
new_layout = ALGORITHM_PARITY_N;
break;
default:
return ERR_PTR(-EINVAL);
}
mddev->new_level = 6;
mddev->new_layout = new_layout;
mddev->delta_disks = 1;
mddev->raid_disks += 1;
return setup_conf(mddev);
}
static int __init raid5_init(void)
{
register_md_personality(&raid6_personality);
register_md_personality(&raid5_personality);
register_md_personality(&raid4_personality);
return 0;
}
static void raid5_exit(void)
{
unregister_md_personality(&raid6_personality);
unregister_md_personality(&raid5_personality);
unregister_md_personality(&raid4_personality);
}
