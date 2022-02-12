void pblk_rb_data_free(struct pblk_rb *rb)
{
struct pblk_rb_pages *p, *t;
down_write(&pblk_rb_lock);
list_for_each_entry_safe(p, t, &rb->pages, list) {
free_pages((unsigned long)page_address(p->pages), p->order);
list_del(&p->list);
kfree(p);
}
up_write(&pblk_rb_lock);
}
int pblk_rb_init(struct pblk_rb *rb, struct pblk_rb_entry *rb_entry_base,
unsigned int power_size, unsigned int power_seg_sz)
{
struct pblk *pblk = container_of(rb, struct pblk, rwb);
unsigned int init_entry = 0;
unsigned int alloc_order = power_size;
unsigned int max_order = MAX_ORDER - 1;
unsigned int order, iter;
down_write(&pblk_rb_lock);
rb->entries = rb_entry_base;
rb->seg_size = (1 << power_seg_sz);
rb->nr_entries = (1 << power_size);
rb->mem = rb->subm = rb->sync = rb->l2p_update = 0;
rb->sync_point = EMPTY_ENTRY;
spin_lock_init(&rb->w_lock);
spin_lock_init(&rb->s_lock);
INIT_LIST_HEAD(&rb->pages);
if (alloc_order >= max_order) {
order = max_order;
iter = (1 << (alloc_order - max_order));
} else {
order = alloc_order;
iter = 1;
}
do {
struct pblk_rb_entry *entry;
struct pblk_rb_pages *page_set;
void *kaddr;
unsigned long set_size;
int i;
page_set = kmalloc(sizeof(struct pblk_rb_pages), GFP_KERNEL);
if (!page_set) {
up_write(&pblk_rb_lock);
return -ENOMEM;
}
page_set->order = order;
page_set->pages = alloc_pages(GFP_KERNEL, order);
if (!page_set->pages) {
kfree(page_set);
pblk_rb_data_free(rb);
up_write(&pblk_rb_lock);
return -ENOMEM;
}
kaddr = page_address(page_set->pages);
entry = &rb->entries[init_entry];
entry->data = kaddr;
entry->cacheline = pblk_cacheline_to_addr(init_entry++);
entry->w_ctx.flags = PBLK_WRITABLE_ENTRY;
set_size = (1 << order);
for (i = 1; i < set_size; i++) {
entry = &rb->entries[init_entry];
entry->cacheline = pblk_cacheline_to_addr(init_entry++);
entry->data = kaddr + (i * rb->seg_size);
entry->w_ctx.flags = PBLK_WRITABLE_ENTRY;
bio_list_init(&entry->w_ctx.bios);
}
list_add_tail(&page_set->list, &rb->pages);
iter--;
} while (iter > 0);
up_write(&pblk_rb_lock);
#ifdef CONFIG_NVM_DEBUG
atomic_set(&rb->inflight_sync_point, 0);
#endif
pblk_rl_init(&pblk->rl, rb->nr_entries);
return 0;
}
unsigned int pblk_rb_calculate_size(unsigned int nr_entries)
{
return (1 << max(get_count_order(nr_entries), 7));
}
void *pblk_rb_entries_ref(struct pblk_rb *rb)
{
return rb->entries;
}
static void clean_wctx(struct pblk_w_ctx *w_ctx)
{
int flags;
try:
flags = READ_ONCE(w_ctx->flags);
if (!(flags & PBLK_SUBMITTED_ENTRY))
goto try;
smp_store_release(&w_ctx->flags, PBLK_WRITABLE_ENTRY);
pblk_ppa_set_empty(&w_ctx->ppa);
w_ctx->lba = ADDR_EMPTY;
}
static unsigned int pblk_rb_space(struct pblk_rb *rb)
{
unsigned int mem = READ_ONCE(rb->mem);
unsigned int sync = READ_ONCE(rb->sync);
return pblk_rb_ring_space(rb, mem, sync, rb->nr_entries);
}
unsigned int pblk_rb_read_count(struct pblk_rb *rb)
{
unsigned int mem = READ_ONCE(rb->mem);
unsigned int subm = READ_ONCE(rb->subm);
return pblk_rb_ring_count(mem, subm, rb->nr_entries);
}
unsigned int pblk_rb_sync_count(struct pblk_rb *rb)
{
unsigned int mem = READ_ONCE(rb->mem);
unsigned int sync = READ_ONCE(rb->sync);
return pblk_rb_ring_count(mem, sync, rb->nr_entries);
}
unsigned int pblk_rb_read_commit(struct pblk_rb *rb, unsigned int nr_entries)
{
unsigned int subm;
subm = READ_ONCE(rb->subm);
smp_store_release(&rb->subm,
(subm + nr_entries) & (rb->nr_entries - 1));
return subm;
}
static int __pblk_rb_update_l2p(struct pblk_rb *rb, unsigned int *l2p_upd,
unsigned int to_update)
{
struct pblk *pblk = container_of(rb, struct pblk, rwb);
struct pblk_line *line;
struct pblk_rb_entry *entry;
struct pblk_w_ctx *w_ctx;
unsigned int user_io = 0, gc_io = 0;
unsigned int i;
int flags;
for (i = 0; i < to_update; i++) {
entry = &rb->entries[*l2p_upd];
w_ctx = &entry->w_ctx;
flags = READ_ONCE(entry->w_ctx.flags);
if (flags & PBLK_IOTYPE_USER)
user_io++;
else if (flags & PBLK_IOTYPE_GC)
gc_io++;
else
WARN(1, "pblk: unknown IO type\n");
pblk_update_map_dev(pblk, w_ctx->lba, w_ctx->ppa,
entry->cacheline);
line = &pblk->lines[pblk_tgt_ppa_to_line(w_ctx->ppa)];
kref_put(&line->ref, pblk_line_put);
clean_wctx(w_ctx);
*l2p_upd = (*l2p_upd + 1) & (rb->nr_entries - 1);
}
pblk_rl_out(&pblk->rl, user_io, gc_io);
return 0;
}
static int pblk_rb_update_l2p(struct pblk_rb *rb, unsigned int nr_entries,
unsigned int mem, unsigned int sync)
{
unsigned int space, count;
int ret = 0;
lockdep_assert_held(&rb->w_lock);
space = pblk_rb_ring_space(rb, mem, rb->l2p_update, rb->nr_entries);
if (space > nr_entries)
goto out;
count = nr_entries - space;
ret = __pblk_rb_update_l2p(rb, &rb->l2p_update, count);
out:
return ret;
}
void pblk_rb_sync_l2p(struct pblk_rb *rb)
{
unsigned int sync;
unsigned int to_update;
spin_lock(&rb->w_lock);
sync = smp_load_acquire(&rb->sync);
to_update = pblk_rb_ring_count(sync, rb->l2p_update, rb->nr_entries);
__pblk_rb_update_l2p(rb, &rb->l2p_update, to_update);
spin_unlock(&rb->w_lock);
}
static void __pblk_rb_write_entry(struct pblk_rb *rb, void *data,
struct pblk_w_ctx w_ctx,
struct pblk_rb_entry *entry)
{
memcpy(entry->data, data, rb->seg_size);
entry->w_ctx.lba = w_ctx.lba;
entry->w_ctx.ppa = w_ctx.ppa;
}
void pblk_rb_write_entry_user(struct pblk_rb *rb, void *data,
struct pblk_w_ctx w_ctx, unsigned int ring_pos)
{
struct pblk *pblk = container_of(rb, struct pblk, rwb);
struct pblk_rb_entry *entry;
int flags;
entry = &rb->entries[ring_pos];
flags = READ_ONCE(entry->w_ctx.flags);
#ifdef CONFIG_NVM_DEBUG
BUG_ON(!(flags & PBLK_WRITABLE_ENTRY));
#endif
__pblk_rb_write_entry(rb, data, w_ctx, entry);
pblk_update_map_cache(pblk, w_ctx.lba, entry->cacheline);
flags = w_ctx.flags | PBLK_WRITTEN_DATA;
smp_store_release(&entry->w_ctx.flags, flags);
}
void pblk_rb_write_entry_gc(struct pblk_rb *rb, void *data,
struct pblk_w_ctx w_ctx, struct pblk_line *gc_line,
unsigned int ring_pos)
{
struct pblk *pblk = container_of(rb, struct pblk, rwb);
struct pblk_rb_entry *entry;
int flags;
entry = &rb->entries[ring_pos];
flags = READ_ONCE(entry->w_ctx.flags);
#ifdef CONFIG_NVM_DEBUG
BUG_ON(!(flags & PBLK_WRITABLE_ENTRY));
#endif
__pblk_rb_write_entry(rb, data, w_ctx, entry);
if (!pblk_update_map_gc(pblk, w_ctx.lba, entry->cacheline, gc_line))
entry->w_ctx.lba = ADDR_EMPTY;
flags = w_ctx.flags | PBLK_WRITTEN_DATA;
smp_store_release(&entry->w_ctx.flags, flags);
}
static int pblk_rb_sync_point_set(struct pblk_rb *rb, struct bio *bio,
unsigned int pos)
{
struct pblk_rb_entry *entry;
unsigned int subm, sync_point;
int flags;
subm = READ_ONCE(rb->subm);
#ifdef CONFIG_NVM_DEBUG
atomic_inc(&rb->inflight_sync_point);
#endif
if (pos == subm)
return 0;
sync_point = (pos == 0) ? (rb->nr_entries - 1) : (pos - 1);
entry = &rb->entries[sync_point];
flags = READ_ONCE(entry->w_ctx.flags);
flags |= PBLK_FLUSH_ENTRY;
smp_store_release(&entry->w_ctx.flags, flags);
smp_store_release(&rb->sync_point, sync_point);
if (!bio)
return 0;
spin_lock_irq(&rb->s_lock);
bio_list_add(&entry->w_ctx.bios, bio);
spin_unlock_irq(&rb->s_lock);
return 1;
}
static int __pblk_rb_may_write(struct pblk_rb *rb, unsigned int nr_entries,
unsigned int *pos)
{
unsigned int mem;
unsigned int sync;
sync = READ_ONCE(rb->sync);
mem = READ_ONCE(rb->mem);
if (pblk_rb_ring_space(rb, mem, sync, rb->nr_entries) < nr_entries)
return 0;
if (pblk_rb_update_l2p(rb, nr_entries, mem, sync))
return 0;
*pos = mem;
return 1;
}
static int pblk_rb_may_write(struct pblk_rb *rb, unsigned int nr_entries,
unsigned int *pos)
{
if (!__pblk_rb_may_write(rb, nr_entries, pos))
return 0;
smp_store_release(&rb->mem, (*pos + nr_entries) & (rb->nr_entries - 1));
return 1;
}
void pblk_rb_flush(struct pblk_rb *rb)
{
struct pblk *pblk = container_of(rb, struct pblk, rwb);
unsigned int mem = READ_ONCE(rb->mem);
if (pblk_rb_sync_point_set(rb, NULL, mem))
return;
pblk_write_should_kick(pblk);
}
static int pblk_rb_may_write_flush(struct pblk_rb *rb, unsigned int nr_entries,
unsigned int *pos, struct bio *bio,
int *io_ret)
{
unsigned int mem;
if (!__pblk_rb_may_write(rb, nr_entries, pos))
return 0;
mem = (*pos + nr_entries) & (rb->nr_entries - 1);
*io_ret = NVM_IO_DONE;
if (bio->bi_opf & REQ_PREFLUSH) {
struct pblk *pblk = container_of(rb, struct pblk, rwb);
#ifdef CONFIG_NVM_DEBUG
atomic_long_inc(&pblk->nr_flush);
#endif
if (pblk_rb_sync_point_set(&pblk->rwb, bio, mem))
*io_ret = NVM_IO_OK;
}
smp_store_release(&rb->mem, mem);
return 1;
}
int pblk_rb_may_write_user(struct pblk_rb *rb, struct bio *bio,
unsigned int nr_entries, unsigned int *pos)
{
struct pblk *pblk = container_of(rb, struct pblk, rwb);
int io_ret;
spin_lock(&rb->w_lock);
io_ret = pblk_rl_user_may_insert(&pblk->rl, nr_entries);
if (io_ret) {
spin_unlock(&rb->w_lock);
return io_ret;
}
if (!pblk_rb_may_write_flush(rb, nr_entries, pos, bio, &io_ret)) {
spin_unlock(&rb->w_lock);
return NVM_IO_REQUEUE;
}
pblk_rl_user_in(&pblk->rl, nr_entries);
spin_unlock(&rb->w_lock);
return io_ret;
}
int pblk_rb_may_write_gc(struct pblk_rb *rb, unsigned int nr_entries,
unsigned int *pos)
{
struct pblk *pblk = container_of(rb, struct pblk, rwb);
spin_lock(&rb->w_lock);
if (!pblk_rl_gc_may_insert(&pblk->rl, nr_entries)) {
spin_unlock(&rb->w_lock);
return 0;
}
if (!pblk_rb_may_write(rb, nr_entries, pos)) {
spin_unlock(&rb->w_lock);
return 0;
}
pblk_rl_gc_in(&pblk->rl, nr_entries);
spin_unlock(&rb->w_lock);
return 1;
}
unsigned int pblk_rb_read_to_bio_list(struct pblk_rb *rb, struct bio *bio,
struct list_head *list,
unsigned int max)
{
struct pblk_rb_entry *entry, *tentry;
struct page *page;
unsigned int read = 0;
int ret;
list_for_each_entry_safe(entry, tentry, list, index) {
if (read > max) {
pr_err("pblk: too many entries on list\n");
goto out;
}
page = virt_to_page(entry->data);
if (!page) {
pr_err("pblk: could not allocate write bio page\n");
goto out;
}
ret = bio_add_page(bio, page, rb->seg_size, 0);
if (ret != rb->seg_size) {
pr_err("pblk: could not add page to write bio\n");
goto out;
}
list_del(&entry->index);
read++;
}
out:
return read;
}
unsigned int pblk_rb_read_to_bio(struct pblk_rb *rb, struct nvm_rq *rqd,
struct bio *bio, unsigned int pos,
unsigned int nr_entries, unsigned int count)
{
struct pblk *pblk = container_of(rb, struct pblk, rwb);
struct request_queue *q = pblk->dev->q;
struct pblk_c_ctx *c_ctx = nvm_rq_to_pdu(rqd);
struct pblk_rb_entry *entry;
struct page *page;
unsigned int pad = 0, to_read = nr_entries;
unsigned int i;
int flags;
if (count < nr_entries) {
pad = nr_entries - count;
to_read = count;
}
c_ctx->sentry = pos;
c_ctx->nr_valid = to_read;
c_ctx->nr_padded = pad;
for (i = 0; i < to_read; i++) {
entry = &rb->entries[pos];
try:
flags = READ_ONCE(entry->w_ctx.flags);
if (!(flags & PBLK_WRITTEN_DATA)) {
io_schedule();
goto try;
}
page = virt_to_page(entry->data);
if (!page) {
pr_err("pblk: could not allocate write bio page\n");
flags &= ~PBLK_WRITTEN_DATA;
flags |= PBLK_SUBMITTED_ENTRY;
smp_store_release(&entry->w_ctx.flags, flags);
return NVM_IO_ERR;
}
if (bio_add_pc_page(q, bio, page, rb->seg_size, 0) !=
rb->seg_size) {
pr_err("pblk: could not add page to write bio\n");
flags &= ~PBLK_WRITTEN_DATA;
flags |= PBLK_SUBMITTED_ENTRY;
smp_store_release(&entry->w_ctx.flags, flags);
return NVM_IO_ERR;
}
if (flags & PBLK_FLUSH_ENTRY) {
unsigned int sync_point;
sync_point = READ_ONCE(rb->sync_point);
if (sync_point == pos) {
smp_store_release(&rb->sync_point, EMPTY_ENTRY);
}
flags &= ~PBLK_FLUSH_ENTRY;
#ifdef CONFIG_NVM_DEBUG
atomic_dec(&rb->inflight_sync_point);
#endif
}
flags &= ~PBLK_WRITTEN_DATA;
flags |= PBLK_SUBMITTED_ENTRY;
smp_store_release(&entry->w_ctx.flags, flags);
pos = (pos + 1) & (rb->nr_entries - 1);
}
if (pad) {
if (pblk_bio_add_pages(pblk, bio, GFP_KERNEL, pad)) {
pr_err("pblk: could not pad page in write bio\n");
return NVM_IO_ERR;
}
}
#ifdef CONFIG_NVM_DEBUG
atomic_long_add(pad, &((struct pblk *)
(container_of(rb, struct pblk, rwb)))->padded_writes);
#endif
return NVM_IO_OK;
}
int pblk_rb_copy_to_bio(struct pblk_rb *rb, struct bio *bio, sector_t lba,
struct ppa_addr ppa, int bio_iter, bool advanced_bio)
{
struct pblk *pblk = container_of(rb, struct pblk, rwb);
struct pblk_rb_entry *entry;
struct pblk_w_ctx *w_ctx;
struct ppa_addr l2p_ppa;
u64 pos = pblk_addr_to_cacheline(ppa);
void *data;
int flags;
int ret = 1;
#ifdef CONFIG_NVM_DEBUG
BUG_ON(pos >= rb->nr_entries);
#endif
entry = &rb->entries[pos];
w_ctx = &entry->w_ctx;
flags = READ_ONCE(w_ctx->flags);
spin_lock(&rb->w_lock);
spin_lock(&pblk->trans_lock);
l2p_ppa = pblk_trans_map_get(pblk, lba);
spin_unlock(&pblk->trans_lock);
if (!pblk_ppa_comp(l2p_ppa, ppa) || w_ctx->lba != lba ||
flags & PBLK_WRITABLE_ENTRY) {
ret = 0;
goto out;
}
if (unlikely(!advanced_bio))
bio_advance(bio, bio_iter * PBLK_EXPOSED_PAGE_SIZE);
data = bio_data(bio);
memcpy(data, entry->data, rb->seg_size);
out:
spin_unlock(&rb->w_lock);
return ret;
}
struct pblk_w_ctx *pblk_rb_w_ctx(struct pblk_rb *rb, unsigned int pos)
{
unsigned int entry = pos & (rb->nr_entries - 1);
return &rb->entries[entry].w_ctx;
}
unsigned int pblk_rb_sync_init(struct pblk_rb *rb, unsigned long *flags)
__acquires(&rb->s_lock
void pblk_rb_sync_end(struct pblk_rb *rb, unsigned long *flags)
__releases(&rb->s_lock
unsigned int pblk_rb_sync_advance(struct pblk_rb *rb, unsigned int nr_entries)
{
unsigned int sync;
unsigned int i;
lockdep_assert_held(&rb->s_lock);
sync = READ_ONCE(rb->sync);
for (i = 0; i < nr_entries; i++)
sync = (sync + 1) & (rb->nr_entries - 1);
smp_store_release(&rb->sync, sync);
return sync;
}
unsigned int pblk_rb_sync_point_count(struct pblk_rb *rb)
{
unsigned int subm, sync_point;
unsigned int count;
sync_point = smp_load_acquire(&rb->sync_point);
if (sync_point == EMPTY_ENTRY)
return 0;
subm = READ_ONCE(rb->subm);
count = pblk_rb_ring_count(sync_point, subm, rb->nr_entries) + 1;
return count;
}
struct pblk_rb_entry *pblk_rb_sync_scan_entry(struct pblk_rb *rb,
struct ppa_addr *ppa)
{
unsigned int sync, subm, count;
unsigned int i;
sync = READ_ONCE(rb->sync);
subm = READ_ONCE(rb->subm);
count = pblk_rb_ring_count(subm, sync, rb->nr_entries);
for (i = 0; i < count; i++)
sync = (sync + 1) & (rb->nr_entries - 1);
return NULL;
}
int pblk_rb_tear_down_check(struct pblk_rb *rb)
{
struct pblk_rb_entry *entry;
int i;
int ret = 0;
spin_lock(&rb->w_lock);
spin_lock_irq(&rb->s_lock);
if ((rb->mem == rb->subm) && (rb->subm == rb->sync) &&
(rb->sync == rb->l2p_update) &&
(rb->sync_point == EMPTY_ENTRY)) {
goto out;
}
if (!rb->entries) {
ret = 1;
goto out;
}
for (i = 0; i < rb->nr_entries; i++) {
entry = &rb->entries[i];
if (!entry->data) {
ret = 1;
goto out;
}
}
out:
spin_unlock(&rb->w_lock);
spin_unlock_irq(&rb->s_lock);
return ret;
}
unsigned int pblk_rb_wrap_pos(struct pblk_rb *rb, unsigned int pos)
{
return (pos & (rb->nr_entries - 1));
}
int pblk_rb_pos_oob(struct pblk_rb *rb, u64 pos)
{
return (pos >= rb->nr_entries);
}
ssize_t pblk_rb_sysfs(struct pblk_rb *rb, char *buf)
{
struct pblk *pblk = container_of(rb, struct pblk, rwb);
struct pblk_c_ctx *c;
ssize_t offset;
int queued_entries = 0;
spin_lock_irq(&rb->s_lock);
list_for_each_entry(c, &pblk->compl_list, list)
queued_entries++;
spin_unlock_irq(&rb->s_lock);
if (rb->sync_point != EMPTY_ENTRY)
offset = scnprintf(buf, PAGE_SIZE,
"%u\t%u\t%u\t%u\t%u\t%u\t%u - %u/%u/%u - %d\n",
rb->nr_entries,
rb->mem,
rb->subm,
rb->sync,
rb->l2p_update,
#ifdef CONFIG_NVM_DEBUG
atomic_read(&rb->inflight_sync_point),
#else
0,
#endif
rb->sync_point,
pblk_rb_read_count(rb),
pblk_rb_space(rb),
pblk_rb_sync_point_count(rb),
queued_entries);
else
offset = scnprintf(buf, PAGE_SIZE,
"%u\t%u\t%u\t%u\t%u\t%u\tNULL - %u/%u/%u - %d\n",
rb->nr_entries,
rb->mem,
rb->subm,
rb->sync,
rb->l2p_update,
#ifdef CONFIG_NVM_DEBUG
atomic_read(&rb->inflight_sync_point),
#else
0,
#endif
pblk_rb_read_count(rb),
pblk_rb_space(rb),
pblk_rb_sync_point_count(rb),
queued_entries);
return offset;
}
