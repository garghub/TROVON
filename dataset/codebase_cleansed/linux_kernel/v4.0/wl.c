static void update_fastmap_work_fn(struct work_struct *wrk)
{
struct ubi_device *ubi = container_of(wrk, struct ubi_device, fm_work);
ubi_update_fastmap(ubi);
}
static int ubi_is_fm_block(struct ubi_device *ubi, int pnum)
{
int i;
if (!ubi->fm)
return 0;
for (i = 0; i < ubi->fm->used_blocks; i++)
if (ubi->fm->e[i]->pnum == pnum)
return 1;
return 0;
}
static int ubi_is_fm_block(struct ubi_device *ubi, int pnum)
{
return 0;
}
static void wl_tree_add(struct ubi_wl_entry *e, struct rb_root *root)
{
struct rb_node **p, *parent = NULL;
p = &root->rb_node;
while (*p) {
struct ubi_wl_entry *e1;
parent = *p;
e1 = rb_entry(parent, struct ubi_wl_entry, u.rb);
if (e->ec < e1->ec)
p = &(*p)->rb_left;
else if (e->ec > e1->ec)
p = &(*p)->rb_right;
else {
ubi_assert(e->pnum != e1->pnum);
if (e->pnum < e1->pnum)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
}
}
rb_link_node(&e->u.rb, parent, p);
rb_insert_color(&e->u.rb, root);
}
static int do_work(struct ubi_device *ubi)
{
int err;
struct ubi_work *wrk;
cond_resched();
down_read(&ubi->work_sem);
spin_lock(&ubi->wl_lock);
if (list_empty(&ubi->works)) {
spin_unlock(&ubi->wl_lock);
up_read(&ubi->work_sem);
return 0;
}
wrk = list_entry(ubi->works.next, struct ubi_work, list);
list_del(&wrk->list);
ubi->works_count -= 1;
ubi_assert(ubi->works_count >= 0);
spin_unlock(&ubi->wl_lock);
err = wrk->func(ubi, wrk, 0);
if (err)
ubi_err(ubi, "work failed with error code %d", err);
up_read(&ubi->work_sem);
return err;
}
static int produce_free_peb(struct ubi_device *ubi)
{
int err;
while (!ubi->free.rb_node && ubi->works_count) {
spin_unlock(&ubi->wl_lock);
dbg_wl("do one work synchronously");
err = do_work(ubi);
spin_lock(&ubi->wl_lock);
if (err)
return err;
}
return 0;
}
static int in_wl_tree(struct ubi_wl_entry *e, struct rb_root *root)
{
struct rb_node *p;
p = root->rb_node;
while (p) {
struct ubi_wl_entry *e1;
e1 = rb_entry(p, struct ubi_wl_entry, u.rb);
if (e->pnum == e1->pnum) {
ubi_assert(e == e1);
return 1;
}
if (e->ec < e1->ec)
p = p->rb_left;
else if (e->ec > e1->ec)
p = p->rb_right;
else {
ubi_assert(e->pnum != e1->pnum);
if (e->pnum < e1->pnum)
p = p->rb_left;
else
p = p->rb_right;
}
}
return 0;
}
static void prot_queue_add(struct ubi_device *ubi, struct ubi_wl_entry *e)
{
int pq_tail = ubi->pq_head - 1;
if (pq_tail < 0)
pq_tail = UBI_PROT_QUEUE_LEN - 1;
ubi_assert(pq_tail >= 0 && pq_tail < UBI_PROT_QUEUE_LEN);
list_add_tail(&e->u.list, &ubi->pq[pq_tail]);
dbg_wl("added PEB %d EC %d to the protection queue", e->pnum, e->ec);
}
static struct ubi_wl_entry *find_wl_entry(struct ubi_device *ubi,
struct rb_root *root, int diff)
{
struct rb_node *p;
struct ubi_wl_entry *e, *prev_e = NULL;
int max;
e = rb_entry(rb_first(root), struct ubi_wl_entry, u.rb);
max = e->ec + diff;
p = root->rb_node;
while (p) {
struct ubi_wl_entry *e1;
e1 = rb_entry(p, struct ubi_wl_entry, u.rb);
if (e1->ec >= max)
p = p->rb_left;
else {
p = p->rb_right;
prev_e = e;
e = e1;
}
}
if (prev_e && !ubi->fm_disabled &&
!ubi->fm && e->pnum < UBI_FM_MAX_START)
return prev_e;
return e;
}
static struct ubi_wl_entry *find_mean_wl_entry(struct ubi_device *ubi,
struct rb_root *root)
{
struct ubi_wl_entry *e, *first, *last;
first = rb_entry(rb_first(root), struct ubi_wl_entry, u.rb);
last = rb_entry(rb_last(root), struct ubi_wl_entry, u.rb);
if (last->ec - first->ec < WL_FREE_MAX_DIFF) {
e = rb_entry(root->rb_node, struct ubi_wl_entry, u.rb);
#ifdef CONFIG_MTD_UBI_FASTMAP
if (e && !ubi->fm_disabled && !ubi->fm &&
e->pnum < UBI_FM_MAX_START)
e = rb_entry(rb_next(root->rb_node),
struct ubi_wl_entry, u.rb);
#endif
} else
e = find_wl_entry(ubi, root, WL_FREE_MAX_DIFF/2);
return e;
}
static struct ubi_wl_entry *find_anchor_wl_entry(struct rb_root *root)
{
struct rb_node *p;
struct ubi_wl_entry *e, *victim = NULL;
int max_ec = UBI_MAX_ERASECOUNTER;
ubi_rb_for_each_entry(p, e, root, u.rb) {
if (e->pnum < UBI_FM_MAX_START && e->ec < max_ec) {
victim = e;
max_ec = e->ec;
}
}
return victim;
}
static int anchor_pebs_avalible(struct rb_root *root)
{
struct rb_node *p;
struct ubi_wl_entry *e;
ubi_rb_for_each_entry(p, e, root, u.rb)
if (e->pnum < UBI_FM_MAX_START)
return 1;
return 0;
}
struct ubi_wl_entry *ubi_wl_get_fm_peb(struct ubi_device *ubi, int anchor)
{
struct ubi_wl_entry *e = NULL;
if (!ubi->free.rb_node || (ubi->free_count - ubi->beb_rsvd_pebs < 1))
goto out;
if (anchor)
e = find_anchor_wl_entry(&ubi->free);
else
e = find_mean_wl_entry(ubi, &ubi->free);
if (!e)
goto out;
self_check_in_wl_tree(ubi, e, &ubi->free);
rb_erase(&e->u.rb, &ubi->free);
ubi->free_count--;
out:
return e;
}
static int __wl_get_peb(struct ubi_device *ubi)
{
int err;
struct ubi_wl_entry *e;
retry:
if (!ubi->free.rb_node) {
if (ubi->works_count == 0) {
ubi_err(ubi, "no free eraseblocks");
ubi_assert(list_empty(&ubi->works));
return -ENOSPC;
}
err = produce_free_peb(ubi);
if (err < 0)
return err;
goto retry;
}
e = find_mean_wl_entry(ubi, &ubi->free);
if (!e) {
ubi_err(ubi, "no free eraseblocks");
return -ENOSPC;
}
self_check_in_wl_tree(ubi, e, &ubi->free);
rb_erase(&e->u.rb, &ubi->free);
ubi->free_count--;
dbg_wl("PEB %d EC %d", e->pnum, e->ec);
#ifndef CONFIG_MTD_UBI_FASTMAP
prot_queue_add(ubi, e);
#endif
return e->pnum;
}
static void return_unused_pool_pebs(struct ubi_device *ubi,
struct ubi_fm_pool *pool)
{
int i;
struct ubi_wl_entry *e;
for (i = pool->used; i < pool->size; i++) {
e = ubi->lookuptbl[pool->pebs[i]];
wl_tree_add(e, &ubi->free);
ubi->free_count++;
}
}
static void refill_wl_pool(struct ubi_device *ubi)
{
struct ubi_wl_entry *e;
struct ubi_fm_pool *pool = &ubi->fm_wl_pool;
return_unused_pool_pebs(ubi, pool);
for (pool->size = 0; pool->size < pool->max_size; pool->size++) {
if (!ubi->free.rb_node ||
(ubi->free_count - ubi->beb_rsvd_pebs < 5))
break;
e = find_wl_entry(ubi, &ubi->free, WL_FREE_MAX_DIFF);
self_check_in_wl_tree(ubi, e, &ubi->free);
rb_erase(&e->u.rb, &ubi->free);
ubi->free_count--;
pool->pebs[pool->size] = e->pnum;
}
pool->used = 0;
}
static void refill_wl_user_pool(struct ubi_device *ubi)
{
struct ubi_fm_pool *pool = &ubi->fm_pool;
return_unused_pool_pebs(ubi, pool);
for (pool->size = 0; pool->size < pool->max_size; pool->size++) {
pool->pebs[pool->size] = __wl_get_peb(ubi);
if (pool->pebs[pool->size] < 0)
break;
}
pool->used = 0;
}
void ubi_refill_pools(struct ubi_device *ubi)
{
spin_lock(&ubi->wl_lock);
refill_wl_pool(ubi);
refill_wl_user_pool(ubi);
spin_unlock(&ubi->wl_lock);
}
int ubi_wl_get_peb(struct ubi_device *ubi)
{
int ret;
struct ubi_fm_pool *pool = &ubi->fm_pool;
struct ubi_fm_pool *wl_pool = &ubi->fm_wl_pool;
if (!pool->size || !wl_pool->size || pool->used == pool->size ||
wl_pool->used == wl_pool->size)
ubi_update_fastmap(ubi);
if (!pool->size)
ret = -ENOSPC;
else {
spin_lock(&ubi->wl_lock);
ret = pool->pebs[pool->used++];
prot_queue_add(ubi, ubi->lookuptbl[ret]);
spin_unlock(&ubi->wl_lock);
}
return ret;
}
static struct ubi_wl_entry *get_peb_for_wl(struct ubi_device *ubi)
{
struct ubi_fm_pool *pool = &ubi->fm_wl_pool;
int pnum;
if (pool->used == pool->size || !pool->size) {
schedule_work(&ubi->fm_work);
return NULL;
} else {
pnum = pool->pebs[pool->used++];
return ubi->lookuptbl[pnum];
}
}
static struct ubi_wl_entry *get_peb_for_wl(struct ubi_device *ubi)
{
struct ubi_wl_entry *e;
e = find_wl_entry(ubi, &ubi->free, WL_FREE_MAX_DIFF);
self_check_in_wl_tree(ubi, e, &ubi->free);
ubi->free_count--;
ubi_assert(ubi->free_count >= 0);
rb_erase(&e->u.rb, &ubi->free);
return e;
}
int ubi_wl_get_peb(struct ubi_device *ubi)
{
int peb, err;
spin_lock(&ubi->wl_lock);
peb = __wl_get_peb(ubi);
spin_unlock(&ubi->wl_lock);
if (peb < 0)
return peb;
err = ubi_self_check_all_ff(ubi, peb, ubi->vid_hdr_aloffset,
ubi->peb_size - ubi->vid_hdr_aloffset);
if (err) {
ubi_err(ubi, "new PEB %d does not contain all 0xFF bytes",
peb);
return err;
}
return peb;
}
static int prot_queue_del(struct ubi_device *ubi, int pnum)
{
struct ubi_wl_entry *e;
e = ubi->lookuptbl[pnum];
if (!e)
return -ENODEV;
if (self_check_in_pq(ubi, e))
return -ENODEV;
list_del(&e->u.list);
dbg_wl("deleted PEB %d from the protection queue", e->pnum);
return 0;
}
static int sync_erase(struct ubi_device *ubi, struct ubi_wl_entry *e,
int torture)
{
int err;
struct ubi_ec_hdr *ec_hdr;
unsigned long long ec = e->ec;
dbg_wl("erase PEB %d, old EC %llu", e->pnum, ec);
err = self_check_ec(ubi, e->pnum, e->ec);
if (err)
return -EINVAL;
ec_hdr = kzalloc(ubi->ec_hdr_alsize, GFP_NOFS);
if (!ec_hdr)
return -ENOMEM;
err = ubi_io_sync_erase(ubi, e->pnum, torture);
if (err < 0)
goto out_free;
ec += err;
if (ec > UBI_MAX_ERASECOUNTER) {
ubi_err(ubi, "erase counter overflow at PEB %d, EC %llu",
e->pnum, ec);
err = -EINVAL;
goto out_free;
}
dbg_wl("erased PEB %d, new EC %llu", e->pnum, ec);
ec_hdr->ec = cpu_to_be64(ec);
err = ubi_io_write_ec_hdr(ubi, e->pnum, ec_hdr);
if (err)
goto out_free;
e->ec = ec;
spin_lock(&ubi->wl_lock);
if (e->ec > ubi->max_ec)
ubi->max_ec = e->ec;
spin_unlock(&ubi->wl_lock);
out_free:
kfree(ec_hdr);
return err;
}
static void serve_prot_queue(struct ubi_device *ubi)
{
struct ubi_wl_entry *e, *tmp;
int count;
repeat:
count = 0;
spin_lock(&ubi->wl_lock);
list_for_each_entry_safe(e, tmp, &ubi->pq[ubi->pq_head], u.list) {
dbg_wl("PEB %d EC %d protection over, move to used tree",
e->pnum, e->ec);
list_del(&e->u.list);
wl_tree_add(e, &ubi->used);
if (count++ > 32) {
spin_unlock(&ubi->wl_lock);
cond_resched();
goto repeat;
}
}
ubi->pq_head += 1;
if (ubi->pq_head == UBI_PROT_QUEUE_LEN)
ubi->pq_head = 0;
ubi_assert(ubi->pq_head >= 0 && ubi->pq_head < UBI_PROT_QUEUE_LEN);
spin_unlock(&ubi->wl_lock);
}
static void __schedule_ubi_work(struct ubi_device *ubi, struct ubi_work *wrk)
{
spin_lock(&ubi->wl_lock);
list_add_tail(&wrk->list, &ubi->works);
ubi_assert(ubi->works_count >= 0);
ubi->works_count += 1;
if (ubi->thread_enabled && !ubi_dbg_is_bgt_disabled(ubi))
wake_up_process(ubi->bgt_thread);
spin_unlock(&ubi->wl_lock);
}
static void schedule_ubi_work(struct ubi_device *ubi, struct ubi_work *wrk)
{
down_read(&ubi->work_sem);
__schedule_ubi_work(ubi, wrk);
up_read(&ubi->work_sem);
}
int ubi_is_erase_work(struct ubi_work *wrk)
{
return wrk->func == erase_worker;
}
static int schedule_erase(struct ubi_device *ubi, struct ubi_wl_entry *e,
int vol_id, int lnum, int torture)
{
struct ubi_work *wl_wrk;
ubi_assert(e);
ubi_assert(!ubi_is_fm_block(ubi, e->pnum));
dbg_wl("schedule erasure of PEB %d, EC %d, torture %d",
e->pnum, e->ec, torture);
wl_wrk = kmalloc(sizeof(struct ubi_work), GFP_NOFS);
if (!wl_wrk)
return -ENOMEM;
wl_wrk->func = &erase_worker;
wl_wrk->e = e;
wl_wrk->vol_id = vol_id;
wl_wrk->lnum = lnum;
wl_wrk->torture = torture;
schedule_ubi_work(ubi, wl_wrk);
return 0;
}
static int do_sync_erase(struct ubi_device *ubi, struct ubi_wl_entry *e,
int vol_id, int lnum, int torture)
{
struct ubi_work *wl_wrk;
dbg_wl("sync erase of PEB %i", e->pnum);
wl_wrk = kmalloc(sizeof(struct ubi_work), GFP_NOFS);
if (!wl_wrk)
return -ENOMEM;
wl_wrk->e = e;
wl_wrk->vol_id = vol_id;
wl_wrk->lnum = lnum;
wl_wrk->torture = torture;
return erase_worker(ubi, wl_wrk, 0);
}
int ubi_wl_put_fm_peb(struct ubi_device *ubi, struct ubi_wl_entry *fm_e,
int lnum, int torture)
{
struct ubi_wl_entry *e;
int vol_id, pnum = fm_e->pnum;
dbg_wl("PEB %d", pnum);
ubi_assert(pnum >= 0);
ubi_assert(pnum < ubi->peb_count);
spin_lock(&ubi->wl_lock);
e = ubi->lookuptbl[pnum];
if (!e) {
e = fm_e;
ubi_assert(e->ec >= 0);
ubi->lookuptbl[pnum] = e;
} else {
e->ec = fm_e->ec;
kfree(fm_e);
}
spin_unlock(&ubi->wl_lock);
vol_id = lnum ? UBI_FM_DATA_VOLUME_ID : UBI_FM_SB_VOLUME_ID;
return schedule_erase(ubi, e, vol_id, lnum, torture);
}
static int ensure_wear_leveling(struct ubi_device *ubi, int nested)
{
int err = 0;
struct ubi_wl_entry *e1;
struct ubi_wl_entry *e2;
struct ubi_work *wrk;
spin_lock(&ubi->wl_lock);
if (ubi->wl_scheduled)
goto out_unlock;
if (!ubi->scrub.rb_node) {
if (!ubi->used.rb_node || !ubi->free.rb_node)
goto out_unlock;
e1 = rb_entry(rb_first(&ubi->used), struct ubi_wl_entry, u.rb);
e2 = find_wl_entry(ubi, &ubi->free, WL_FREE_MAX_DIFF);
if (!(e2->ec - e1->ec >= UBI_WL_THRESHOLD))
goto out_unlock;
dbg_wl("schedule wear-leveling");
} else
dbg_wl("schedule scrubbing");
ubi->wl_scheduled = 1;
spin_unlock(&ubi->wl_lock);
wrk = kmalloc(sizeof(struct ubi_work), GFP_NOFS);
if (!wrk) {
err = -ENOMEM;
goto out_cancel;
}
wrk->anchor = 0;
wrk->func = &wear_leveling_worker;
if (nested)
__schedule_ubi_work(ubi, wrk);
else
schedule_ubi_work(ubi, wrk);
return err;
out_cancel:
spin_lock(&ubi->wl_lock);
ubi->wl_scheduled = 0;
out_unlock:
spin_unlock(&ubi->wl_lock);
return err;
}
int ubi_ensure_anchor_pebs(struct ubi_device *ubi)
{
struct ubi_work *wrk;
spin_lock(&ubi->wl_lock);
if (ubi->wl_scheduled) {
spin_unlock(&ubi->wl_lock);
return 0;
}
ubi->wl_scheduled = 1;
spin_unlock(&ubi->wl_lock);
wrk = kmalloc(sizeof(struct ubi_work), GFP_NOFS);
if (!wrk) {
spin_lock(&ubi->wl_lock);
ubi->wl_scheduled = 0;
spin_unlock(&ubi->wl_lock);
return -ENOMEM;
}
wrk->anchor = 1;
wrk->func = &wear_leveling_worker;
schedule_ubi_work(ubi, wrk);
return 0;
}
static int erase_worker(struct ubi_device *ubi, struct ubi_work *wl_wrk,
int shutdown)
{
struct ubi_wl_entry *e = wl_wrk->e;
int pnum = e->pnum;
int vol_id = wl_wrk->vol_id;
int lnum = wl_wrk->lnum;
int err, available_consumed = 0;
if (shutdown) {
dbg_wl("cancel erasure of PEB %d EC %d", pnum, e->ec);
kfree(wl_wrk);
kmem_cache_free(ubi_wl_entry_slab, e);
return 0;
}
dbg_wl("erase PEB %d EC %d LEB %d:%d",
pnum, e->ec, wl_wrk->vol_id, wl_wrk->lnum);
ubi_assert(!ubi_is_fm_block(ubi, e->pnum));
err = sync_erase(ubi, e, wl_wrk->torture);
if (!err) {
kfree(wl_wrk);
spin_lock(&ubi->wl_lock);
wl_tree_add(e, &ubi->free);
ubi->free_count++;
spin_unlock(&ubi->wl_lock);
serve_prot_queue(ubi);
err = ensure_wear_leveling(ubi, 1);
return err;
}
ubi_err(ubi, "failed to erase PEB %d, error %d", pnum, err);
kfree(wl_wrk);
if (err == -EINTR || err == -ENOMEM || err == -EAGAIN ||
err == -EBUSY) {
int err1;
err1 = schedule_erase(ubi, e, vol_id, lnum, 0);
if (err1) {
err = err1;
goto out_ro;
}
return err;
}
kmem_cache_free(ubi_wl_entry_slab, e);
if (err != -EIO)
goto out_ro;
if (!ubi->bad_allowed) {
ubi_err(ubi, "bad physical eraseblock %d detected", pnum);
goto out_ro;
}
spin_lock(&ubi->volumes_lock);
if (ubi->beb_rsvd_pebs == 0) {
if (ubi->avail_pebs == 0) {
spin_unlock(&ubi->volumes_lock);
ubi_err(ubi, "no reserved/available physical eraseblocks");
goto out_ro;
}
ubi->avail_pebs -= 1;
available_consumed = 1;
}
spin_unlock(&ubi->volumes_lock);
ubi_msg(ubi, "mark PEB %d as bad", pnum);
err = ubi_io_mark_bad(ubi, pnum);
if (err)
goto out_ro;
spin_lock(&ubi->volumes_lock);
if (ubi->beb_rsvd_pebs > 0) {
if (available_consumed) {
ubi->avail_pebs += 1;
available_consumed = 0;
}
ubi->beb_rsvd_pebs -= 1;
}
ubi->bad_peb_count += 1;
ubi->good_peb_count -= 1;
ubi_calculate_reserved(ubi);
if (available_consumed)
ubi_warn(ubi, "no PEBs in the reserved pool, used an available PEB");
else if (ubi->beb_rsvd_pebs)
ubi_msg(ubi, "%d PEBs left in the reserve",
ubi->beb_rsvd_pebs);
else
ubi_warn(ubi, "last PEB from the reserve was used");
spin_unlock(&ubi->volumes_lock);
return err;
out_ro:
if (available_consumed) {
spin_lock(&ubi->volumes_lock);
ubi->avail_pebs += 1;
spin_unlock(&ubi->volumes_lock);
}
ubi_ro_mode(ubi);
return err;
}
int ubi_wl_put_peb(struct ubi_device *ubi, int vol_id, int lnum,
int pnum, int torture)
{
int err;
struct ubi_wl_entry *e;
dbg_wl("PEB %d", pnum);
ubi_assert(pnum >= 0);
ubi_assert(pnum < ubi->peb_count);
retry:
spin_lock(&ubi->wl_lock);
e = ubi->lookuptbl[pnum];
if (e == ubi->move_from) {
dbg_wl("PEB %d is being moved, wait", pnum);
spin_unlock(&ubi->wl_lock);
mutex_lock(&ubi->move_mutex);
mutex_unlock(&ubi->move_mutex);
goto retry;
} else if (e == ubi->move_to) {
dbg_wl("PEB %d is the target of data moving", pnum);
ubi_assert(!ubi->move_to_put);
ubi->move_to_put = 1;
spin_unlock(&ubi->wl_lock);
return 0;
} else {
if (in_wl_tree(e, &ubi->used)) {
self_check_in_wl_tree(ubi, e, &ubi->used);
rb_erase(&e->u.rb, &ubi->used);
} else if (in_wl_tree(e, &ubi->scrub)) {
self_check_in_wl_tree(ubi, e, &ubi->scrub);
rb_erase(&e->u.rb, &ubi->scrub);
} else if (in_wl_tree(e, &ubi->erroneous)) {
self_check_in_wl_tree(ubi, e, &ubi->erroneous);
rb_erase(&e->u.rb, &ubi->erroneous);
ubi->erroneous_peb_count -= 1;
ubi_assert(ubi->erroneous_peb_count >= 0);
torture = 1;
} else {
err = prot_queue_del(ubi, e->pnum);
if (err) {
ubi_err(ubi, "PEB %d not found", pnum);
ubi_ro_mode(ubi);
spin_unlock(&ubi->wl_lock);
return err;
}
}
}
spin_unlock(&ubi->wl_lock);
err = schedule_erase(ubi, e, vol_id, lnum, torture);
if (err) {
spin_lock(&ubi->wl_lock);
wl_tree_add(e, &ubi->used);
spin_unlock(&ubi->wl_lock);
}
return err;
}
int ubi_wl_scrub_peb(struct ubi_device *ubi, int pnum)
{
struct ubi_wl_entry *e;
ubi_msg(ubi, "schedule PEB %d for scrubbing", pnum);
retry:
spin_lock(&ubi->wl_lock);
e = ubi->lookuptbl[pnum];
if (e == ubi->move_from || in_wl_tree(e, &ubi->scrub) ||
in_wl_tree(e, &ubi->erroneous)) {
spin_unlock(&ubi->wl_lock);
return 0;
}
if (e == ubi->move_to) {
spin_unlock(&ubi->wl_lock);
dbg_wl("the PEB %d is not in proper tree, retry", pnum);
yield();
goto retry;
}
if (in_wl_tree(e, &ubi->used)) {
self_check_in_wl_tree(ubi, e, &ubi->used);
rb_erase(&e->u.rb, &ubi->used);
} else {
int err;
err = prot_queue_del(ubi, e->pnum);
if (err) {
ubi_err(ubi, "PEB %d not found", pnum);
ubi_ro_mode(ubi);
spin_unlock(&ubi->wl_lock);
return err;
}
}
wl_tree_add(e, &ubi->scrub);
spin_unlock(&ubi->wl_lock);
return ensure_wear_leveling(ubi, 0);
}
int ubi_wl_flush(struct ubi_device *ubi, int vol_id, int lnum)
{
int err = 0;
int found = 1;
dbg_wl("flush pending work for LEB %d:%d (%d pending works)",
vol_id, lnum, ubi->works_count);
while (found) {
struct ubi_work *wrk, *tmp;
found = 0;
down_read(&ubi->work_sem);
spin_lock(&ubi->wl_lock);
list_for_each_entry_safe(wrk, tmp, &ubi->works, list) {
if ((vol_id == UBI_ALL || wrk->vol_id == vol_id) &&
(lnum == UBI_ALL || wrk->lnum == lnum)) {
list_del(&wrk->list);
ubi->works_count -= 1;
ubi_assert(ubi->works_count >= 0);
spin_unlock(&ubi->wl_lock);
err = wrk->func(ubi, wrk, 0);
if (err) {
up_read(&ubi->work_sem);
return err;
}
spin_lock(&ubi->wl_lock);
found = 1;
break;
}
}
spin_unlock(&ubi->wl_lock);
up_read(&ubi->work_sem);
}
down_write(&ubi->work_sem);
up_write(&ubi->work_sem);
return err;
}
static void tree_destroy(struct rb_root *root)
{
struct rb_node *rb;
struct ubi_wl_entry *e;
rb = root->rb_node;
while (rb) {
if (rb->rb_left)
rb = rb->rb_left;
else if (rb->rb_right)
rb = rb->rb_right;
else {
e = rb_entry(rb, struct ubi_wl_entry, u.rb);
rb = rb_parent(rb);
if (rb) {
if (rb->rb_left == &e->u.rb)
rb->rb_left = NULL;
else
rb->rb_right = NULL;
}
kmem_cache_free(ubi_wl_entry_slab, e);
}
}
}
int ubi_thread(void *u)
{
int failures = 0;
struct ubi_device *ubi = u;
ubi_msg(ubi, "background thread \"%s\" started, PID %d",
ubi->bgt_name, task_pid_nr(current));
set_freezable();
for (;;) {
int err;
if (kthread_should_stop())
break;
if (try_to_freeze())
continue;
spin_lock(&ubi->wl_lock);
if (list_empty(&ubi->works) || ubi->ro_mode ||
!ubi->thread_enabled || ubi_dbg_is_bgt_disabled(ubi)) {
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock(&ubi->wl_lock);
schedule();
continue;
}
spin_unlock(&ubi->wl_lock);
err = do_work(ubi);
if (err) {
ubi_err(ubi, "%s: work failed with error code %d",
ubi->bgt_name, err);
if (failures++ > WL_MAX_FAILURES) {
ubi_msg(ubi, "%s: %d consecutive failures",
ubi->bgt_name, WL_MAX_FAILURES);
ubi_ro_mode(ubi);
ubi->thread_enabled = 0;
continue;
}
} else
failures = 0;
cond_resched();
}
dbg_wl("background thread \"%s\" is killed", ubi->bgt_name);
return 0;
}
static void shutdown_work(struct ubi_device *ubi)
{
while (!list_empty(&ubi->works)) {
struct ubi_work *wrk;
wrk = list_entry(ubi->works.next, struct ubi_work, list);
list_del(&wrk->list);
wrk->func(ubi, wrk, 1);
ubi->works_count -= 1;
ubi_assert(ubi->works_count >= 0);
}
}
int ubi_wl_init(struct ubi_device *ubi, struct ubi_attach_info *ai)
{
int err, i, reserved_pebs, found_pebs = 0;
struct rb_node *rb1, *rb2;
struct ubi_ainf_volume *av;
struct ubi_ainf_peb *aeb, *tmp;
struct ubi_wl_entry *e;
ubi->used = ubi->erroneous = ubi->free = ubi->scrub = RB_ROOT;
spin_lock_init(&ubi->wl_lock);
mutex_init(&ubi->move_mutex);
init_rwsem(&ubi->work_sem);
ubi->max_ec = ai->max_ec;
INIT_LIST_HEAD(&ubi->works);
#ifdef CONFIG_MTD_UBI_FASTMAP
INIT_WORK(&ubi->fm_work, update_fastmap_work_fn);
#endif
sprintf(ubi->bgt_name, UBI_BGT_NAME_PATTERN, ubi->ubi_num);
err = -ENOMEM;
ubi->lookuptbl = kzalloc(ubi->peb_count * sizeof(void *), GFP_KERNEL);
if (!ubi->lookuptbl)
return err;
for (i = 0; i < UBI_PROT_QUEUE_LEN; i++)
INIT_LIST_HEAD(&ubi->pq[i]);
ubi->pq_head = 0;
list_for_each_entry_safe(aeb, tmp, &ai->erase, u.list) {
cond_resched();
e = kmem_cache_alloc(ubi_wl_entry_slab, GFP_KERNEL);
if (!e)
goto out_free;
e->pnum = aeb->pnum;
e->ec = aeb->ec;
ubi_assert(!ubi_is_fm_block(ubi, e->pnum));
ubi->lookuptbl[e->pnum] = e;
if (schedule_erase(ubi, e, aeb->vol_id, aeb->lnum, 0)) {
kmem_cache_free(ubi_wl_entry_slab, e);
goto out_free;
}
found_pebs++;
}
ubi->free_count = 0;
list_for_each_entry(aeb, &ai->free, u.list) {
cond_resched();
e = kmem_cache_alloc(ubi_wl_entry_slab, GFP_KERNEL);
if (!e)
goto out_free;
e->pnum = aeb->pnum;
e->ec = aeb->ec;
ubi_assert(e->ec >= 0);
ubi_assert(!ubi_is_fm_block(ubi, e->pnum));
wl_tree_add(e, &ubi->free);
ubi->free_count++;
ubi->lookuptbl[e->pnum] = e;
found_pebs++;
}
ubi_rb_for_each_entry(rb1, av, &ai->volumes, rb) {
ubi_rb_for_each_entry(rb2, aeb, &av->root, u.rb) {
cond_resched();
e = kmem_cache_alloc(ubi_wl_entry_slab, GFP_KERNEL);
if (!e)
goto out_free;
e->pnum = aeb->pnum;
e->ec = aeb->ec;
ubi->lookuptbl[e->pnum] = e;
if (!aeb->scrub) {
dbg_wl("add PEB %d EC %d to the used tree",
e->pnum, e->ec);
wl_tree_add(e, &ubi->used);
} else {
dbg_wl("add PEB %d EC %d to the scrub tree",
e->pnum, e->ec);
wl_tree_add(e, &ubi->scrub);
}
found_pebs++;
}
}
dbg_wl("found %i PEBs", found_pebs);
if (ubi->fm)
ubi_assert(ubi->good_peb_count == \
found_pebs + ubi->fm->used_blocks);
else
ubi_assert(ubi->good_peb_count == found_pebs);
reserved_pebs = WL_RESERVED_PEBS;
#ifdef CONFIG_MTD_UBI_FASTMAP
reserved_pebs += (ubi->fm_size / ubi->leb_size) * 2;
#endif
if (ubi->avail_pebs < reserved_pebs) {
ubi_err(ubi, "no enough physical eraseblocks (%d, need %d)",
ubi->avail_pebs, reserved_pebs);
if (ubi->corr_peb_count)
ubi_err(ubi, "%d PEBs are corrupted and not used",
ubi->corr_peb_count);
goto out_free;
}
ubi->avail_pebs -= reserved_pebs;
ubi->rsvd_pebs += reserved_pebs;
err = ensure_wear_leveling(ubi, 0);
if (err)
goto out_free;
return 0;
out_free:
shutdown_work(ubi);
tree_destroy(&ubi->used);
tree_destroy(&ubi->free);
tree_destroy(&ubi->scrub);
kfree(ubi->lookuptbl);
return err;
}
static void protection_queue_destroy(struct ubi_device *ubi)
{
int i;
struct ubi_wl_entry *e, *tmp;
for (i = 0; i < UBI_PROT_QUEUE_LEN; ++i) {
list_for_each_entry_safe(e, tmp, &ubi->pq[i], u.list) {
list_del(&e->u.list);
kmem_cache_free(ubi_wl_entry_slab, e);
}
}
}
void ubi_wl_close(struct ubi_device *ubi)
{
dbg_wl("close the WL sub-system");
shutdown_work(ubi);
protection_queue_destroy(ubi);
tree_destroy(&ubi->used);
tree_destroy(&ubi->erroneous);
tree_destroy(&ubi->free);
tree_destroy(&ubi->scrub);
kfree(ubi->lookuptbl);
}
static int self_check_ec(struct ubi_device *ubi, int pnum, int ec)
{
int err;
long long read_ec;
struct ubi_ec_hdr *ec_hdr;
if (!ubi_dbg_chk_gen(ubi))
return 0;
ec_hdr = kzalloc(ubi->ec_hdr_alsize, GFP_NOFS);
if (!ec_hdr)
return -ENOMEM;
err = ubi_io_read_ec_hdr(ubi, pnum, ec_hdr, 0);
if (err && err != UBI_IO_BITFLIPS) {
err = 0;
goto out_free;
}
read_ec = be64_to_cpu(ec_hdr->ec);
if (ec != read_ec && read_ec - ec > 1) {
ubi_err(ubi, "self-check failed for PEB %d", pnum);
ubi_err(ubi, "read EC is %lld, should be %d", read_ec, ec);
dump_stack();
err = 1;
} else
err = 0;
out_free:
kfree(ec_hdr);
return err;
}
static int self_check_in_wl_tree(const struct ubi_device *ubi,
struct ubi_wl_entry *e, struct rb_root *root)
{
if (!ubi_dbg_chk_gen(ubi))
return 0;
if (in_wl_tree(e, root))
return 0;
ubi_err(ubi, "self-check failed for PEB %d, EC %d, RB-tree %p ",
e->pnum, e->ec, root);
dump_stack();
return -EINVAL;
}
static int self_check_in_pq(const struct ubi_device *ubi,
struct ubi_wl_entry *e)
{
struct ubi_wl_entry *p;
int i;
if (!ubi_dbg_chk_gen(ubi))
return 0;
for (i = 0; i < UBI_PROT_QUEUE_LEN; ++i)
list_for_each_entry(p, &ubi->pq[i], u.list)
if (p == e)
return 0;
ubi_err(ubi, "self-check failed for PEB %d, EC %d, Protect queue",
e->pnum, e->ec);
dump_stack();
return -EINVAL;
}
