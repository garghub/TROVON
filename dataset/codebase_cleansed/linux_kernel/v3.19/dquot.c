void __quota_error(struct super_block *sb, const char *func,
const char *fmt, ...)
{
if (printk_ratelimit()) {
va_list args;
struct va_format vaf;
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
printk(KERN_ERR "Quota error (device %s): %s: %pV\n",
sb->s_id, func, &vaf);
va_end(args);
}
}
int register_quota_format(struct quota_format_type *fmt)
{
spin_lock(&dq_list_lock);
fmt->qf_next = quota_formats;
quota_formats = fmt;
spin_unlock(&dq_list_lock);
return 0;
}
void unregister_quota_format(struct quota_format_type *fmt)
{
struct quota_format_type **actqf;
spin_lock(&dq_list_lock);
for (actqf = &quota_formats; *actqf && *actqf != fmt;
actqf = &(*actqf)->qf_next)
;
if (*actqf)
*actqf = (*actqf)->qf_next;
spin_unlock(&dq_list_lock);
}
static struct quota_format_type *find_quota_format(int id)
{
struct quota_format_type *actqf;
spin_lock(&dq_list_lock);
for (actqf = quota_formats; actqf && actqf->qf_fmt_id != id;
actqf = actqf->qf_next)
;
if (!actqf || !try_module_get(actqf->qf_owner)) {
int qm;
spin_unlock(&dq_list_lock);
for (qm = 0; module_names[qm].qm_fmt_id &&
module_names[qm].qm_fmt_id != id; qm++)
;
if (!module_names[qm].qm_fmt_id ||
request_module(module_names[qm].qm_mod_name))
return NULL;
spin_lock(&dq_list_lock);
for (actqf = quota_formats; actqf && actqf->qf_fmt_id != id;
actqf = actqf->qf_next)
;
if (actqf && !try_module_get(actqf->qf_owner))
actqf = NULL;
}
spin_unlock(&dq_list_lock);
return actqf;
}
static void put_quota_format(struct quota_format_type *fmt)
{
module_put(fmt->qf_owner);
}
static inline unsigned int
hashfn(const struct super_block *sb, struct kqid qid)
{
unsigned int id = from_kqid(&init_user_ns, qid);
int type = qid.type;
unsigned long tmp;
tmp = (((unsigned long)sb>>L1_CACHE_SHIFT) ^ id) * (MAXQUOTAS - type);
return (tmp + (tmp >> dq_hash_bits)) & dq_hash_mask;
}
static inline void insert_dquot_hash(struct dquot *dquot)
{
struct hlist_head *head;
head = dquot_hash + hashfn(dquot->dq_sb, dquot->dq_id);
hlist_add_head(&dquot->dq_hash, head);
}
static inline void remove_dquot_hash(struct dquot *dquot)
{
hlist_del_init(&dquot->dq_hash);
}
static struct dquot *find_dquot(unsigned int hashent, struct super_block *sb,
struct kqid qid)
{
struct hlist_node *node;
struct dquot *dquot;
hlist_for_each (node, dquot_hash+hashent) {
dquot = hlist_entry(node, struct dquot, dq_hash);
if (dquot->dq_sb == sb && qid_eq(dquot->dq_id, qid))
return dquot;
}
return NULL;
}
static inline void put_dquot_last(struct dquot *dquot)
{
list_add_tail(&dquot->dq_free, &free_dquots);
dqstats_inc(DQST_FREE_DQUOTS);
}
static inline void remove_free_dquot(struct dquot *dquot)
{
if (list_empty(&dquot->dq_free))
return;
list_del_init(&dquot->dq_free);
dqstats_dec(DQST_FREE_DQUOTS);
}
static inline void put_inuse(struct dquot *dquot)
{
list_add_tail(&dquot->dq_inuse, &inuse_list);
dqstats_inc(DQST_ALLOC_DQUOTS);
}
static inline void remove_inuse(struct dquot *dquot)
{
dqstats_dec(DQST_ALLOC_DQUOTS);
list_del(&dquot->dq_inuse);
}
static void wait_on_dquot(struct dquot *dquot)
{
mutex_lock(&dquot->dq_lock);
mutex_unlock(&dquot->dq_lock);
}
static inline int dquot_dirty(struct dquot *dquot)
{
return test_bit(DQ_MOD_B, &dquot->dq_flags);
}
static inline int mark_dquot_dirty(struct dquot *dquot)
{
return dquot->dq_sb->dq_op->mark_dirty(dquot);
}
int dquot_mark_dquot_dirty(struct dquot *dquot)
{
int ret = 1;
if (test_bit(DQ_MOD_B, &dquot->dq_flags))
return 1;
spin_lock(&dq_list_lock);
if (!test_and_set_bit(DQ_MOD_B, &dquot->dq_flags)) {
list_add(&dquot->dq_dirty, &sb_dqopt(dquot->dq_sb)->
info[dquot->dq_id.type].dqi_dirty_list);
ret = 0;
}
spin_unlock(&dq_list_lock);
return ret;
}
static inline int mark_all_dquot_dirty(struct dquot * const *dquot)
{
int ret, err, cnt;
ret = err = 0;
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (dquot[cnt])
ret = mark_dquot_dirty(dquot[cnt]);
if (!err)
err = ret;
}
return err;
}
static inline void dqput_all(struct dquot **dquot)
{
unsigned int cnt;
for (cnt = 0; cnt < MAXQUOTAS; cnt++)
dqput(dquot[cnt]);
}
static inline int clear_dquot_dirty(struct dquot *dquot)
{
if (!test_and_clear_bit(DQ_MOD_B, &dquot->dq_flags))
return 0;
list_del_init(&dquot->dq_dirty);
return 1;
}
void mark_info_dirty(struct super_block *sb, int type)
{
set_bit(DQF_INFO_DIRTY_B, &sb_dqopt(sb)->info[type].dqi_flags);
}
int dquot_acquire(struct dquot *dquot)
{
int ret = 0, ret2 = 0;
struct quota_info *dqopt = sb_dqopt(dquot->dq_sb);
mutex_lock(&dquot->dq_lock);
mutex_lock(&dqopt->dqio_mutex);
if (!test_bit(DQ_READ_B, &dquot->dq_flags))
ret = dqopt->ops[dquot->dq_id.type]->read_dqblk(dquot);
if (ret < 0)
goto out_iolock;
set_bit(DQ_READ_B, &dquot->dq_flags);
if (!test_bit(DQ_ACTIVE_B, &dquot->dq_flags) && !dquot->dq_off) {
ret = dqopt->ops[dquot->dq_id.type]->commit_dqblk(dquot);
if (info_dirty(&dqopt->info[dquot->dq_id.type])) {
ret2 = dqopt->ops[dquot->dq_id.type]->write_file_info(
dquot->dq_sb, dquot->dq_id.type);
}
if (ret < 0)
goto out_iolock;
if (ret2 < 0) {
ret = ret2;
goto out_iolock;
}
}
set_bit(DQ_ACTIVE_B, &dquot->dq_flags);
out_iolock:
mutex_unlock(&dqopt->dqio_mutex);
mutex_unlock(&dquot->dq_lock);
return ret;
}
int dquot_commit(struct dquot *dquot)
{
int ret = 0;
struct quota_info *dqopt = sb_dqopt(dquot->dq_sb);
mutex_lock(&dqopt->dqio_mutex);
spin_lock(&dq_list_lock);
if (!clear_dquot_dirty(dquot)) {
spin_unlock(&dq_list_lock);
goto out_sem;
}
spin_unlock(&dq_list_lock);
if (test_bit(DQ_ACTIVE_B, &dquot->dq_flags))
ret = dqopt->ops[dquot->dq_id.type]->commit_dqblk(dquot);
else
ret = -EIO;
out_sem:
mutex_unlock(&dqopt->dqio_mutex);
return ret;
}
int dquot_release(struct dquot *dquot)
{
int ret = 0, ret2 = 0;
struct quota_info *dqopt = sb_dqopt(dquot->dq_sb);
mutex_lock(&dquot->dq_lock);
if (atomic_read(&dquot->dq_count) > 1)
goto out_dqlock;
mutex_lock(&dqopt->dqio_mutex);
if (dqopt->ops[dquot->dq_id.type]->release_dqblk) {
ret = dqopt->ops[dquot->dq_id.type]->release_dqblk(dquot);
if (info_dirty(&dqopt->info[dquot->dq_id.type])) {
ret2 = dqopt->ops[dquot->dq_id.type]->write_file_info(
dquot->dq_sb, dquot->dq_id.type);
}
if (ret >= 0)
ret = ret2;
}
clear_bit(DQ_ACTIVE_B, &dquot->dq_flags);
mutex_unlock(&dqopt->dqio_mutex);
out_dqlock:
mutex_unlock(&dquot->dq_lock);
return ret;
}
void dquot_destroy(struct dquot *dquot)
{
kmem_cache_free(dquot_cachep, dquot);
}
static inline void do_destroy_dquot(struct dquot *dquot)
{
dquot->dq_sb->dq_op->destroy_dquot(dquot);
}
static void invalidate_dquots(struct super_block *sb, int type)
{
struct dquot *dquot, *tmp;
restart:
spin_lock(&dq_list_lock);
list_for_each_entry_safe(dquot, tmp, &inuse_list, dq_inuse) {
if (dquot->dq_sb != sb)
continue;
if (dquot->dq_id.type != type)
continue;
if (atomic_read(&dquot->dq_count)) {
DEFINE_WAIT(wait);
dqgrab(dquot);
prepare_to_wait(&dquot->dq_wait_unused, &wait,
TASK_UNINTERRUPTIBLE);
spin_unlock(&dq_list_lock);
if (atomic_read(&dquot->dq_count) > 1)
schedule();
finish_wait(&dquot->dq_wait_unused, &wait);
dqput(dquot);
goto restart;
}
remove_dquot_hash(dquot);
remove_free_dquot(dquot);
remove_inuse(dquot);
do_destroy_dquot(dquot);
}
spin_unlock(&dq_list_lock);
}
int dquot_scan_active(struct super_block *sb,
int (*fn)(struct dquot *dquot, unsigned long priv),
unsigned long priv)
{
struct dquot *dquot, *old_dquot = NULL;
int ret = 0;
mutex_lock(&sb_dqopt(sb)->dqonoff_mutex);
spin_lock(&dq_list_lock);
list_for_each_entry(dquot, &inuse_list, dq_inuse) {
if (!test_bit(DQ_ACTIVE_B, &dquot->dq_flags))
continue;
if (dquot->dq_sb != sb)
continue;
atomic_inc(&dquot->dq_count);
spin_unlock(&dq_list_lock);
dqstats_inc(DQST_LOOKUPS);
dqput(old_dquot);
old_dquot = dquot;
wait_on_dquot(dquot);
if (test_bit(DQ_ACTIVE_B, &dquot->dq_flags)) {
ret = fn(dquot, priv);
if (ret < 0)
goto out;
}
spin_lock(&dq_list_lock);
}
spin_unlock(&dq_list_lock);
out:
dqput(old_dquot);
mutex_unlock(&sb_dqopt(sb)->dqonoff_mutex);
return ret;
}
int dquot_writeback_dquots(struct super_block *sb, int type)
{
struct list_head *dirty;
struct dquot *dquot;
struct quota_info *dqopt = sb_dqopt(sb);
int cnt;
int err, ret = 0;
mutex_lock(&dqopt->dqonoff_mutex);
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (type != -1 && cnt != type)
continue;
if (!sb_has_quota_active(sb, cnt))
continue;
spin_lock(&dq_list_lock);
dirty = &dqopt->info[cnt].dqi_dirty_list;
while (!list_empty(dirty)) {
dquot = list_first_entry(dirty, struct dquot,
dq_dirty);
if (!test_bit(DQ_ACTIVE_B, &dquot->dq_flags)) {
clear_dquot_dirty(dquot);
continue;
}
dqgrab(dquot);
spin_unlock(&dq_list_lock);
dqstats_inc(DQST_LOOKUPS);
err = sb->dq_op->write_dquot(dquot);
if (!ret && err)
ret = err;
dqput(dquot);
spin_lock(&dq_list_lock);
}
spin_unlock(&dq_list_lock);
}
for (cnt = 0; cnt < MAXQUOTAS; cnt++)
if ((cnt == type || type == -1) && sb_has_quota_active(sb, cnt)
&& info_dirty(&dqopt->info[cnt]))
sb->dq_op->write_info(sb, cnt);
dqstats_inc(DQST_SYNCS);
mutex_unlock(&dqopt->dqonoff_mutex);
return ret;
}
int dquot_quota_sync(struct super_block *sb, int type)
{
struct quota_info *dqopt = sb_dqopt(sb);
int cnt;
int ret;
ret = dquot_writeback_dquots(sb, type);
if (ret)
return ret;
if (dqopt->flags & DQUOT_QUOTA_SYS_FILE)
return 0;
if (sb->s_op->sync_fs)
sb->s_op->sync_fs(sb, 1);
sync_blockdev(sb->s_bdev);
mutex_lock(&dqopt->dqonoff_mutex);
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (type != -1 && cnt != type)
continue;
if (!sb_has_quota_active(sb, cnt))
continue;
mutex_lock(&dqopt->files[cnt]->i_mutex);
truncate_inode_pages(&dqopt->files[cnt]->i_data, 0);
mutex_unlock(&dqopt->files[cnt]->i_mutex);
}
mutex_unlock(&dqopt->dqonoff_mutex);
return 0;
}
static unsigned long
dqcache_shrink_scan(struct shrinker *shrink, struct shrink_control *sc)
{
struct list_head *head;
struct dquot *dquot;
unsigned long freed = 0;
spin_lock(&dq_list_lock);
head = free_dquots.prev;
while (head != &free_dquots && sc->nr_to_scan) {
dquot = list_entry(head, struct dquot, dq_free);
remove_dquot_hash(dquot);
remove_free_dquot(dquot);
remove_inuse(dquot);
do_destroy_dquot(dquot);
sc->nr_to_scan--;
freed++;
head = free_dquots.prev;
}
spin_unlock(&dq_list_lock);
return freed;
}
static unsigned long
dqcache_shrink_count(struct shrinker *shrink, struct shrink_control *sc)
{
return vfs_pressure_ratio(
percpu_counter_read_positive(&dqstats.counter[DQST_FREE_DQUOTS]));
}
void dqput(struct dquot *dquot)
{
int ret;
if (!dquot)
return;
#ifdef CONFIG_QUOTA_DEBUG
if (!atomic_read(&dquot->dq_count)) {
quota_error(dquot->dq_sb, "trying to free free dquot of %s %d",
quotatypes[dquot->dq_id.type],
from_kqid(&init_user_ns, dquot->dq_id));
BUG();
}
#endif
dqstats_inc(DQST_DROPS);
we_slept:
spin_lock(&dq_list_lock);
if (atomic_read(&dquot->dq_count) > 1) {
atomic_dec(&dquot->dq_count);
if (!sb_has_quota_active(dquot->dq_sb, dquot->dq_id.type) &&
atomic_read(&dquot->dq_count) == 1)
wake_up(&dquot->dq_wait_unused);
spin_unlock(&dq_list_lock);
return;
}
if (test_bit(DQ_ACTIVE_B, &dquot->dq_flags) && dquot_dirty(dquot)) {
spin_unlock(&dq_list_lock);
ret = dquot->dq_sb->dq_op->write_dquot(dquot);
if (ret < 0) {
quota_error(dquot->dq_sb, "Can't write quota structure"
" (error %d). Quota may get out of sync!",
ret);
spin_lock(&dq_list_lock);
clear_dquot_dirty(dquot);
spin_unlock(&dq_list_lock);
}
goto we_slept;
}
clear_dquot_dirty(dquot);
if (test_bit(DQ_ACTIVE_B, &dquot->dq_flags)) {
spin_unlock(&dq_list_lock);
dquot->dq_sb->dq_op->release_dquot(dquot);
goto we_slept;
}
atomic_dec(&dquot->dq_count);
#ifdef CONFIG_QUOTA_DEBUG
BUG_ON(!list_empty(&dquot->dq_free));
#endif
put_dquot_last(dquot);
spin_unlock(&dq_list_lock);
}
struct dquot *dquot_alloc(struct super_block *sb, int type)
{
return kmem_cache_zalloc(dquot_cachep, GFP_NOFS);
}
static struct dquot *get_empty_dquot(struct super_block *sb, int type)
{
struct dquot *dquot;
dquot = sb->dq_op->alloc_dquot(sb, type);
if(!dquot)
return NULL;
mutex_init(&dquot->dq_lock);
INIT_LIST_HEAD(&dquot->dq_free);
INIT_LIST_HEAD(&dquot->dq_inuse);
INIT_HLIST_NODE(&dquot->dq_hash);
INIT_LIST_HEAD(&dquot->dq_dirty);
init_waitqueue_head(&dquot->dq_wait_unused);
dquot->dq_sb = sb;
dquot->dq_id = make_kqid_invalid(type);
atomic_set(&dquot->dq_count, 1);
return dquot;
}
struct dquot *dqget(struct super_block *sb, struct kqid qid)
{
unsigned int hashent = hashfn(sb, qid);
struct dquot *dquot = NULL, *empty = NULL;
if (!sb_has_quota_active(sb, qid.type))
return NULL;
we_slept:
spin_lock(&dq_list_lock);
spin_lock(&dq_state_lock);
if (!sb_has_quota_active(sb, qid.type)) {
spin_unlock(&dq_state_lock);
spin_unlock(&dq_list_lock);
goto out;
}
spin_unlock(&dq_state_lock);
dquot = find_dquot(hashent, sb, qid);
if (!dquot) {
if (!empty) {
spin_unlock(&dq_list_lock);
empty = get_empty_dquot(sb, qid.type);
if (!empty)
schedule();
goto we_slept;
}
dquot = empty;
empty = NULL;
dquot->dq_id = qid;
put_inuse(dquot);
insert_dquot_hash(dquot);
spin_unlock(&dq_list_lock);
dqstats_inc(DQST_LOOKUPS);
} else {
if (!atomic_read(&dquot->dq_count))
remove_free_dquot(dquot);
atomic_inc(&dquot->dq_count);
spin_unlock(&dq_list_lock);
dqstats_inc(DQST_CACHE_HITS);
dqstats_inc(DQST_LOOKUPS);
}
wait_on_dquot(dquot);
if (!test_bit(DQ_ACTIVE_B, &dquot->dq_flags) &&
sb->dq_op->acquire_dquot(dquot) < 0) {
dqput(dquot);
dquot = NULL;
goto out;
}
#ifdef CONFIG_QUOTA_DEBUG
BUG_ON(!dquot->dq_sb);
#endif
out:
if (empty)
do_destroy_dquot(empty);
return dquot;
}
static inline struct dquot **i_dquot(struct inode *inode)
{
return inode->i_sb->s_op->get_dquots(inode);
}
static int dqinit_needed(struct inode *inode, int type)
{
int cnt;
if (IS_NOQUOTA(inode))
return 0;
if (type != -1)
return !i_dquot(inode)[type];
for (cnt = 0; cnt < MAXQUOTAS; cnt++)
if (!i_dquot(inode)[cnt])
return 1;
return 0;
}
static void add_dquot_ref(struct super_block *sb, int type)
{
struct inode *inode, *old_inode = NULL;
#ifdef CONFIG_QUOTA_DEBUG
int reserved = 0;
#endif
spin_lock(&inode_sb_list_lock);
list_for_each_entry(inode, &sb->s_inodes, i_sb_list) {
spin_lock(&inode->i_lock);
if ((inode->i_state & (I_FREEING|I_WILL_FREE|I_NEW)) ||
!atomic_read(&inode->i_writecount) ||
!dqinit_needed(inode, type)) {
spin_unlock(&inode->i_lock);
continue;
}
__iget(inode);
spin_unlock(&inode->i_lock);
spin_unlock(&inode_sb_list_lock);
#ifdef CONFIG_QUOTA_DEBUG
if (unlikely(inode_get_rsv_space(inode) > 0))
reserved = 1;
#endif
iput(old_inode);
__dquot_initialize(inode, type);
old_inode = inode;
spin_lock(&inode_sb_list_lock);
}
spin_unlock(&inode_sb_list_lock);
iput(old_inode);
#ifdef CONFIG_QUOTA_DEBUG
if (reserved) {
quota_error(sb, "Writes happened before quota was turned on "
"thus quota information is probably inconsistent. "
"Please run quotacheck(8)");
}
#endif
}
static void remove_inode_dquot_ref(struct inode *inode, int type,
struct list_head *tofree_head)
{
struct dquot *dquot = i_dquot(inode)[type];
i_dquot(inode)[type] = NULL;
if (!dquot)
return;
if (list_empty(&dquot->dq_free)) {
spin_lock(&dq_list_lock);
list_add(&dquot->dq_free, tofree_head);
spin_unlock(&dq_list_lock);
} else {
dqput(dquot);
}
}
static void put_dquot_list(struct list_head *tofree_head)
{
struct list_head *act_head;
struct dquot *dquot;
act_head = tofree_head->next;
while (act_head != tofree_head) {
dquot = list_entry(act_head, struct dquot, dq_free);
act_head = act_head->next;
list_del_init(&dquot->dq_free);
dqput(dquot);
}
}
static void remove_dquot_ref(struct super_block *sb, int type,
struct list_head *tofree_head)
{
struct inode *inode;
int reserved = 0;
spin_lock(&inode_sb_list_lock);
list_for_each_entry(inode, &sb->s_inodes, i_sb_list) {
spin_lock(&dq_data_lock);
if (!IS_NOQUOTA(inode)) {
if (unlikely(inode_get_rsv_space(inode) > 0))
reserved = 1;
remove_inode_dquot_ref(inode, type, tofree_head);
}
spin_unlock(&dq_data_lock);
}
spin_unlock(&inode_sb_list_lock);
#ifdef CONFIG_QUOTA_DEBUG
if (reserved) {
printk(KERN_WARNING "VFS (%s): Writes happened after quota"
" was disabled thus quota information is probably "
"inconsistent. Please run quotacheck(8).\n", sb->s_id);
}
#endif
}
static void drop_dquot_ref(struct super_block *sb, int type)
{
LIST_HEAD(tofree_head);
if (sb->dq_op) {
remove_dquot_ref(sb, type, &tofree_head);
synchronize_srcu(&dquot_srcu);
put_dquot_list(&tofree_head);
}
}
static inline void dquot_incr_inodes(struct dquot *dquot, qsize_t number)
{
dquot->dq_dqb.dqb_curinodes += number;
}
static inline void dquot_incr_space(struct dquot *dquot, qsize_t number)
{
dquot->dq_dqb.dqb_curspace += number;
}
static inline void dquot_resv_space(struct dquot *dquot, qsize_t number)
{
dquot->dq_dqb.dqb_rsvspace += number;
}
static void dquot_claim_reserved_space(struct dquot *dquot, qsize_t number)
{
if (dquot->dq_dqb.dqb_rsvspace < number) {
WARN_ON_ONCE(1);
number = dquot->dq_dqb.dqb_rsvspace;
}
dquot->dq_dqb.dqb_curspace += number;
dquot->dq_dqb.dqb_rsvspace -= number;
}
static void dquot_reclaim_reserved_space(struct dquot *dquot, qsize_t number)
{
if (WARN_ON_ONCE(dquot->dq_dqb.dqb_curspace < number))
number = dquot->dq_dqb.dqb_curspace;
dquot->dq_dqb.dqb_rsvspace += number;
dquot->dq_dqb.dqb_curspace -= number;
}
static inline
void dquot_free_reserved_space(struct dquot *dquot, qsize_t number)
{
if (dquot->dq_dqb.dqb_rsvspace >= number)
dquot->dq_dqb.dqb_rsvspace -= number;
else {
WARN_ON_ONCE(1);
dquot->dq_dqb.dqb_rsvspace = 0;
}
}
static void dquot_decr_inodes(struct dquot *dquot, qsize_t number)
{
if (sb_dqopt(dquot->dq_sb)->flags & DQUOT_NEGATIVE_USAGE ||
dquot->dq_dqb.dqb_curinodes >= number)
dquot->dq_dqb.dqb_curinodes -= number;
else
dquot->dq_dqb.dqb_curinodes = 0;
if (dquot->dq_dqb.dqb_curinodes <= dquot->dq_dqb.dqb_isoftlimit)
dquot->dq_dqb.dqb_itime = (time_t) 0;
clear_bit(DQ_INODES_B, &dquot->dq_flags);
}
static void dquot_decr_space(struct dquot *dquot, qsize_t number)
{
if (sb_dqopt(dquot->dq_sb)->flags & DQUOT_NEGATIVE_USAGE ||
dquot->dq_dqb.dqb_curspace >= number)
dquot->dq_dqb.dqb_curspace -= number;
else
dquot->dq_dqb.dqb_curspace = 0;
if (dquot->dq_dqb.dqb_curspace <= dquot->dq_dqb.dqb_bsoftlimit)
dquot->dq_dqb.dqb_btime = (time_t) 0;
clear_bit(DQ_BLKS_B, &dquot->dq_flags);
}
static int warning_issued(struct dquot *dquot, const int warntype)
{
int flag = (warntype == QUOTA_NL_BHARDWARN ||
warntype == QUOTA_NL_BSOFTLONGWARN) ? DQ_BLKS_B :
((warntype == QUOTA_NL_IHARDWARN ||
warntype == QUOTA_NL_ISOFTLONGWARN) ? DQ_INODES_B : 0);
if (!flag)
return 0;
return test_and_set_bit(flag, &dquot->dq_flags);
}
static int need_print_warning(struct dquot_warn *warn)
{
if (!flag_print_warnings)
return 0;
switch (warn->w_dq_id.type) {
case USRQUOTA:
return uid_eq(current_fsuid(), warn->w_dq_id.uid);
case GRPQUOTA:
return in_group_p(warn->w_dq_id.gid);
case PRJQUOTA:
return 0;
}
return 0;
}
static void print_warning(struct dquot_warn *warn)
{
char *msg = NULL;
struct tty_struct *tty;
int warntype = warn->w_type;
if (warntype == QUOTA_NL_IHARDBELOW ||
warntype == QUOTA_NL_ISOFTBELOW ||
warntype == QUOTA_NL_BHARDBELOW ||
warntype == QUOTA_NL_BSOFTBELOW || !need_print_warning(warn))
return;
tty = get_current_tty();
if (!tty)
return;
tty_write_message(tty, warn->w_sb->s_id);
if (warntype == QUOTA_NL_ISOFTWARN || warntype == QUOTA_NL_BSOFTWARN)
tty_write_message(tty, ": warning, ");
else
tty_write_message(tty, ": write failed, ");
tty_write_message(tty, quotatypes[warn->w_dq_id.type]);
switch (warntype) {
case QUOTA_NL_IHARDWARN:
msg = " file limit reached.\r\n";
break;
case QUOTA_NL_ISOFTLONGWARN:
msg = " file quota exceeded too long.\r\n";
break;
case QUOTA_NL_ISOFTWARN:
msg = " file quota exceeded.\r\n";
break;
case QUOTA_NL_BHARDWARN:
msg = " block limit reached.\r\n";
break;
case QUOTA_NL_BSOFTLONGWARN:
msg = " block quota exceeded too long.\r\n";
break;
case QUOTA_NL_BSOFTWARN:
msg = " block quota exceeded.\r\n";
break;
}
tty_write_message(tty, msg);
tty_kref_put(tty);
}
static void prepare_warning(struct dquot_warn *warn, struct dquot *dquot,
int warntype)
{
if (warning_issued(dquot, warntype))
return;
warn->w_type = warntype;
warn->w_sb = dquot->dq_sb;
warn->w_dq_id = dquot->dq_id;
}
static void flush_warnings(struct dquot_warn *warn)
{
int i;
for (i = 0; i < MAXQUOTAS; i++) {
if (warn[i].w_type == QUOTA_NL_NOWARN)
continue;
#ifdef CONFIG_PRINT_QUOTA_WARNING
print_warning(&warn[i]);
#endif
quota_send_warning(warn[i].w_dq_id,
warn[i].w_sb->s_dev, warn[i].w_type);
}
}
static int ignore_hardlimit(struct dquot *dquot)
{
struct mem_dqinfo *info = &sb_dqopt(dquot->dq_sb)->info[dquot->dq_id.type];
return capable(CAP_SYS_RESOURCE) &&
(info->dqi_format->qf_fmt_id != QFMT_VFS_OLD ||
!(info->dqi_flags & V1_DQF_RSQUASH));
}
static int check_idq(struct dquot *dquot, qsize_t inodes,
struct dquot_warn *warn)
{
qsize_t newinodes = dquot->dq_dqb.dqb_curinodes + inodes;
if (!sb_has_quota_limits_enabled(dquot->dq_sb, dquot->dq_id.type) ||
test_bit(DQ_FAKE_B, &dquot->dq_flags))
return 0;
if (dquot->dq_dqb.dqb_ihardlimit &&
newinodes > dquot->dq_dqb.dqb_ihardlimit &&
!ignore_hardlimit(dquot)) {
prepare_warning(warn, dquot, QUOTA_NL_IHARDWARN);
return -EDQUOT;
}
if (dquot->dq_dqb.dqb_isoftlimit &&
newinodes > dquot->dq_dqb.dqb_isoftlimit &&
dquot->dq_dqb.dqb_itime &&
get_seconds() >= dquot->dq_dqb.dqb_itime &&
!ignore_hardlimit(dquot)) {
prepare_warning(warn, dquot, QUOTA_NL_ISOFTLONGWARN);
return -EDQUOT;
}
if (dquot->dq_dqb.dqb_isoftlimit &&
newinodes > dquot->dq_dqb.dqb_isoftlimit &&
dquot->dq_dqb.dqb_itime == 0) {
prepare_warning(warn, dquot, QUOTA_NL_ISOFTWARN);
dquot->dq_dqb.dqb_itime = get_seconds() +
sb_dqopt(dquot->dq_sb)->info[dquot->dq_id.type].dqi_igrace;
}
return 0;
}
static int check_bdq(struct dquot *dquot, qsize_t space, int prealloc,
struct dquot_warn *warn)
{
qsize_t tspace;
struct super_block *sb = dquot->dq_sb;
if (!sb_has_quota_limits_enabled(sb, dquot->dq_id.type) ||
test_bit(DQ_FAKE_B, &dquot->dq_flags))
return 0;
tspace = dquot->dq_dqb.dqb_curspace + dquot->dq_dqb.dqb_rsvspace
+ space;
if (dquot->dq_dqb.dqb_bhardlimit &&
tspace > dquot->dq_dqb.dqb_bhardlimit &&
!ignore_hardlimit(dquot)) {
if (!prealloc)
prepare_warning(warn, dquot, QUOTA_NL_BHARDWARN);
return -EDQUOT;
}
if (dquot->dq_dqb.dqb_bsoftlimit &&
tspace > dquot->dq_dqb.dqb_bsoftlimit &&
dquot->dq_dqb.dqb_btime &&
get_seconds() >= dquot->dq_dqb.dqb_btime &&
!ignore_hardlimit(dquot)) {
if (!prealloc)
prepare_warning(warn, dquot, QUOTA_NL_BSOFTLONGWARN);
return -EDQUOT;
}
if (dquot->dq_dqb.dqb_bsoftlimit &&
tspace > dquot->dq_dqb.dqb_bsoftlimit &&
dquot->dq_dqb.dqb_btime == 0) {
if (!prealloc) {
prepare_warning(warn, dquot, QUOTA_NL_BSOFTWARN);
dquot->dq_dqb.dqb_btime = get_seconds() +
sb_dqopt(sb)->info[dquot->dq_id.type].dqi_bgrace;
}
else
return -EDQUOT;
}
return 0;
}
static int info_idq_free(struct dquot *dquot, qsize_t inodes)
{
qsize_t newinodes;
if (test_bit(DQ_FAKE_B, &dquot->dq_flags) ||
dquot->dq_dqb.dqb_curinodes <= dquot->dq_dqb.dqb_isoftlimit ||
!sb_has_quota_limits_enabled(dquot->dq_sb, dquot->dq_id.type))
return QUOTA_NL_NOWARN;
newinodes = dquot->dq_dqb.dqb_curinodes - inodes;
if (newinodes <= dquot->dq_dqb.dqb_isoftlimit)
return QUOTA_NL_ISOFTBELOW;
if (dquot->dq_dqb.dqb_curinodes >= dquot->dq_dqb.dqb_ihardlimit &&
newinodes < dquot->dq_dqb.dqb_ihardlimit)
return QUOTA_NL_IHARDBELOW;
return QUOTA_NL_NOWARN;
}
static int info_bdq_free(struct dquot *dquot, qsize_t space)
{
if (test_bit(DQ_FAKE_B, &dquot->dq_flags) ||
dquot->dq_dqb.dqb_curspace <= dquot->dq_dqb.dqb_bsoftlimit)
return QUOTA_NL_NOWARN;
if (dquot->dq_dqb.dqb_curspace - space <= dquot->dq_dqb.dqb_bsoftlimit)
return QUOTA_NL_BSOFTBELOW;
if (dquot->dq_dqb.dqb_curspace >= dquot->dq_dqb.dqb_bhardlimit &&
dquot->dq_dqb.dqb_curspace - space < dquot->dq_dqb.dqb_bhardlimit)
return QUOTA_NL_BHARDBELOW;
return QUOTA_NL_NOWARN;
}
static int dquot_active(const struct inode *inode)
{
struct super_block *sb = inode->i_sb;
if (IS_NOQUOTA(inode))
return 0;
return sb_any_quota_loaded(sb) & ~sb_any_quota_suspended(sb);
}
static void __dquot_initialize(struct inode *inode, int type)
{
int cnt, init_needed = 0;
struct dquot *got[MAXQUOTAS];
struct super_block *sb = inode->i_sb;
qsize_t rsv;
if (!dquot_active(inode))
return;
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
struct kqid qid;
got[cnt] = NULL;
if (type != -1 && cnt != type)
continue;
if (i_dquot(inode)[cnt])
continue;
init_needed = 1;
switch (cnt) {
case USRQUOTA:
qid = make_kqid_uid(inode->i_uid);
break;
case GRPQUOTA:
qid = make_kqid_gid(inode->i_gid);
break;
}
got[cnt] = dqget(sb, qid);
}
if (!init_needed)
return;
spin_lock(&dq_data_lock);
if (IS_NOQUOTA(inode))
goto out_err;
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (type != -1 && cnt != type)
continue;
if (!sb_has_quota_active(sb, cnt))
continue;
if (!got[cnt])
continue;
if (!i_dquot(inode)[cnt]) {
i_dquot(inode)[cnt] = got[cnt];
got[cnt] = NULL;
rsv = inode_get_rsv_space(inode);
if (unlikely(rsv))
dquot_resv_space(i_dquot(inode)[cnt], rsv);
}
}
out_err:
spin_unlock(&dq_data_lock);
dqput_all(got);
}
void dquot_initialize(struct inode *inode)
{
__dquot_initialize(inode, -1);
}
static void __dquot_drop(struct inode *inode)
{
int cnt;
struct dquot *put[MAXQUOTAS];
spin_lock(&dq_data_lock);
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
put[cnt] = i_dquot(inode)[cnt];
i_dquot(inode)[cnt] = NULL;
}
spin_unlock(&dq_data_lock);
dqput_all(put);
}
void dquot_drop(struct inode *inode)
{
int cnt;
if (IS_NOQUOTA(inode))
return;
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (i_dquot(inode)[cnt])
break;
}
if (cnt < MAXQUOTAS)
__dquot_drop(inode);
}
static qsize_t *inode_reserved_space(struct inode * inode)
{
BUG_ON(!inode->i_sb->dq_op->get_reserved_space);
return inode->i_sb->dq_op->get_reserved_space(inode);
}
void inode_add_rsv_space(struct inode *inode, qsize_t number)
{
spin_lock(&inode->i_lock);
*inode_reserved_space(inode) += number;
spin_unlock(&inode->i_lock);
}
void inode_claim_rsv_space(struct inode *inode, qsize_t number)
{
spin_lock(&inode->i_lock);
*inode_reserved_space(inode) -= number;
__inode_add_bytes(inode, number);
spin_unlock(&inode->i_lock);
}
void inode_reclaim_rsv_space(struct inode *inode, qsize_t number)
{
spin_lock(&inode->i_lock);
*inode_reserved_space(inode) += number;
__inode_sub_bytes(inode, number);
spin_unlock(&inode->i_lock);
}
void inode_sub_rsv_space(struct inode *inode, qsize_t number)
{
spin_lock(&inode->i_lock);
*inode_reserved_space(inode) -= number;
spin_unlock(&inode->i_lock);
}
static qsize_t inode_get_rsv_space(struct inode *inode)
{
qsize_t ret;
if (!inode->i_sb->dq_op->get_reserved_space)
return 0;
spin_lock(&inode->i_lock);
ret = *inode_reserved_space(inode);
spin_unlock(&inode->i_lock);
return ret;
}
static void inode_incr_space(struct inode *inode, qsize_t number,
int reserve)
{
if (reserve)
inode_add_rsv_space(inode, number);
else
inode_add_bytes(inode, number);
}
static void inode_decr_space(struct inode *inode, qsize_t number, int reserve)
{
if (reserve)
inode_sub_rsv_space(inode, number);
else
inode_sub_bytes(inode, number);
}
int __dquot_alloc_space(struct inode *inode, qsize_t number, int flags)
{
int cnt, ret = 0, index;
struct dquot_warn warn[MAXQUOTAS];
struct dquot **dquots = i_dquot(inode);
int reserve = flags & DQUOT_SPACE_RESERVE;
if (!dquot_active(inode)) {
inode_incr_space(inode, number, reserve);
goto out;
}
for (cnt = 0; cnt < MAXQUOTAS; cnt++)
warn[cnt].w_type = QUOTA_NL_NOWARN;
index = srcu_read_lock(&dquot_srcu);
spin_lock(&dq_data_lock);
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (!dquots[cnt])
continue;
ret = check_bdq(dquots[cnt], number,
!(flags & DQUOT_SPACE_WARN), &warn[cnt]);
if (ret && !(flags & DQUOT_SPACE_NOFAIL)) {
spin_unlock(&dq_data_lock);
goto out_flush_warn;
}
}
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (!dquots[cnt])
continue;
if (reserve)
dquot_resv_space(dquots[cnt], number);
else
dquot_incr_space(dquots[cnt], number);
}
inode_incr_space(inode, number, reserve);
spin_unlock(&dq_data_lock);
if (reserve)
goto out_flush_warn;
mark_all_dquot_dirty(dquots);
out_flush_warn:
srcu_read_unlock(&dquot_srcu, index);
flush_warnings(warn);
out:
return ret;
}
int dquot_alloc_inode(struct inode *inode)
{
int cnt, ret = 0, index;
struct dquot_warn warn[MAXQUOTAS];
struct dquot * const *dquots = i_dquot(inode);
if (!dquot_active(inode))
return 0;
for (cnt = 0; cnt < MAXQUOTAS; cnt++)
warn[cnt].w_type = QUOTA_NL_NOWARN;
index = srcu_read_lock(&dquot_srcu);
spin_lock(&dq_data_lock);
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (!dquots[cnt])
continue;
ret = check_idq(dquots[cnt], 1, &warn[cnt]);
if (ret)
goto warn_put_all;
}
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (!dquots[cnt])
continue;
dquot_incr_inodes(dquots[cnt], 1);
}
warn_put_all:
spin_unlock(&dq_data_lock);
if (ret == 0)
mark_all_dquot_dirty(dquots);
srcu_read_unlock(&dquot_srcu, index);
flush_warnings(warn);
return ret;
}
int dquot_claim_space_nodirty(struct inode *inode, qsize_t number)
{
int cnt, index;
if (!dquot_active(inode)) {
inode_claim_rsv_space(inode, number);
return 0;
}
index = srcu_read_lock(&dquot_srcu);
spin_lock(&dq_data_lock);
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (i_dquot(inode)[cnt])
dquot_claim_reserved_space(i_dquot(inode)[cnt],
number);
}
inode_claim_rsv_space(inode, number);
spin_unlock(&dq_data_lock);
mark_all_dquot_dirty(i_dquot(inode));
srcu_read_unlock(&dquot_srcu, index);
return 0;
}
void dquot_reclaim_space_nodirty(struct inode *inode, qsize_t number)
{
int cnt, index;
if (!dquot_active(inode)) {
inode_reclaim_rsv_space(inode, number);
return;
}
index = srcu_read_lock(&dquot_srcu);
spin_lock(&dq_data_lock);
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (i_dquot(inode)[cnt])
dquot_reclaim_reserved_space(i_dquot(inode)[cnt],
number);
}
inode_reclaim_rsv_space(inode, number);
spin_unlock(&dq_data_lock);
mark_all_dquot_dirty(i_dquot(inode));
srcu_read_unlock(&dquot_srcu, index);
return;
}
void __dquot_free_space(struct inode *inode, qsize_t number, int flags)
{
unsigned int cnt;
struct dquot_warn warn[MAXQUOTAS];
struct dquot **dquots = i_dquot(inode);
int reserve = flags & DQUOT_SPACE_RESERVE, index;
if (!dquot_active(inode)) {
inode_decr_space(inode, number, reserve);
return;
}
index = srcu_read_lock(&dquot_srcu);
spin_lock(&dq_data_lock);
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
int wtype;
warn[cnt].w_type = QUOTA_NL_NOWARN;
if (!dquots[cnt])
continue;
wtype = info_bdq_free(dquots[cnt], number);
if (wtype != QUOTA_NL_NOWARN)
prepare_warning(&warn[cnt], dquots[cnt], wtype);
if (reserve)
dquot_free_reserved_space(dquots[cnt], number);
else
dquot_decr_space(dquots[cnt], number);
}
inode_decr_space(inode, number, reserve);
spin_unlock(&dq_data_lock);
if (reserve)
goto out_unlock;
mark_all_dquot_dirty(dquots);
out_unlock:
srcu_read_unlock(&dquot_srcu, index);
flush_warnings(warn);
}
void dquot_free_inode(struct inode *inode)
{
unsigned int cnt;
struct dquot_warn warn[MAXQUOTAS];
struct dquot * const *dquots = i_dquot(inode);
int index;
if (!dquot_active(inode))
return;
index = srcu_read_lock(&dquot_srcu);
spin_lock(&dq_data_lock);
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
int wtype;
warn[cnt].w_type = QUOTA_NL_NOWARN;
if (!dquots[cnt])
continue;
wtype = info_idq_free(dquots[cnt], 1);
if (wtype != QUOTA_NL_NOWARN)
prepare_warning(&warn[cnt], dquots[cnt], wtype);
dquot_decr_inodes(dquots[cnt], 1);
}
spin_unlock(&dq_data_lock);
mark_all_dquot_dirty(dquots);
srcu_read_unlock(&dquot_srcu, index);
flush_warnings(warn);
}
int __dquot_transfer(struct inode *inode, struct dquot **transfer_to)
{
qsize_t space, cur_space;
qsize_t rsv_space = 0;
struct dquot *transfer_from[MAXQUOTAS] = {};
int cnt, ret = 0;
char is_valid[MAXQUOTAS] = {};
struct dquot_warn warn_to[MAXQUOTAS];
struct dquot_warn warn_from_inodes[MAXQUOTAS];
struct dquot_warn warn_from_space[MAXQUOTAS];
if (IS_NOQUOTA(inode))
return 0;
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
warn_to[cnt].w_type = QUOTA_NL_NOWARN;
warn_from_inodes[cnt].w_type = QUOTA_NL_NOWARN;
warn_from_space[cnt].w_type = QUOTA_NL_NOWARN;
}
spin_lock(&dq_data_lock);
if (IS_NOQUOTA(inode)) {
spin_unlock(&dq_data_lock);
return 0;
}
cur_space = inode_get_bytes(inode);
rsv_space = inode_get_rsv_space(inode);
space = cur_space + rsv_space;
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (!transfer_to[cnt])
continue;
if (!sb_has_quota_active(inode->i_sb, cnt))
continue;
is_valid[cnt] = 1;
transfer_from[cnt] = i_dquot(inode)[cnt];
ret = check_idq(transfer_to[cnt], 1, &warn_to[cnt]);
if (ret)
goto over_quota;
ret = check_bdq(transfer_to[cnt], space, 0, &warn_to[cnt]);
if (ret)
goto over_quota;
}
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (!is_valid[cnt])
continue;
if (transfer_from[cnt]) {
int wtype;
wtype = info_idq_free(transfer_from[cnt], 1);
if (wtype != QUOTA_NL_NOWARN)
prepare_warning(&warn_from_inodes[cnt],
transfer_from[cnt], wtype);
wtype = info_bdq_free(transfer_from[cnt], space);
if (wtype != QUOTA_NL_NOWARN)
prepare_warning(&warn_from_space[cnt],
transfer_from[cnt], wtype);
dquot_decr_inodes(transfer_from[cnt], 1);
dquot_decr_space(transfer_from[cnt], cur_space);
dquot_free_reserved_space(transfer_from[cnt],
rsv_space);
}
dquot_incr_inodes(transfer_to[cnt], 1);
dquot_incr_space(transfer_to[cnt], cur_space);
dquot_resv_space(transfer_to[cnt], rsv_space);
i_dquot(inode)[cnt] = transfer_to[cnt];
}
spin_unlock(&dq_data_lock);
mark_all_dquot_dirty(transfer_from);
mark_all_dquot_dirty(transfer_to);
flush_warnings(warn_to);
flush_warnings(warn_from_inodes);
flush_warnings(warn_from_space);
for (cnt = 0; cnt < MAXQUOTAS; cnt++)
if (is_valid[cnt])
transfer_to[cnt] = transfer_from[cnt];
return 0;
over_quota:
spin_unlock(&dq_data_lock);
flush_warnings(warn_to);
return ret;
}
int dquot_transfer(struct inode *inode, struct iattr *iattr)
{
struct dquot *transfer_to[MAXQUOTAS] = {};
struct super_block *sb = inode->i_sb;
int ret;
if (!dquot_active(inode))
return 0;
if (iattr->ia_valid & ATTR_UID && !uid_eq(iattr->ia_uid, inode->i_uid))
transfer_to[USRQUOTA] = dqget(sb, make_kqid_uid(iattr->ia_uid));
if (iattr->ia_valid & ATTR_GID && !gid_eq(iattr->ia_gid, inode->i_gid))
transfer_to[GRPQUOTA] = dqget(sb, make_kqid_gid(iattr->ia_gid));
ret = __dquot_transfer(inode, transfer_to);
dqput_all(transfer_to);
return ret;
}
int dquot_commit_info(struct super_block *sb, int type)
{
int ret;
struct quota_info *dqopt = sb_dqopt(sb);
mutex_lock(&dqopt->dqio_mutex);
ret = dqopt->ops[type]->write_file_info(sb, type);
mutex_unlock(&dqopt->dqio_mutex);
return ret;
}
int dquot_file_open(struct inode *inode, struct file *file)
{
int error;
error = generic_file_open(inode, file);
if (!error && (file->f_mode & FMODE_WRITE))
dquot_initialize(inode);
return error;
}
int dquot_disable(struct super_block *sb, int type, unsigned int flags)
{
int cnt, ret = 0;
struct quota_info *dqopt = sb_dqopt(sb);
struct inode *toputinode[MAXQUOTAS];
if ((flags & DQUOT_USAGE_ENABLED && !(flags & DQUOT_LIMITS_ENABLED))
|| (flags & DQUOT_SUSPENDED && flags & (DQUOT_LIMITS_ENABLED |
DQUOT_USAGE_ENABLED)))
return -EINVAL;
mutex_lock(&dqopt->dqonoff_mutex);
if (!sb_any_quota_loaded(sb)) {
mutex_unlock(&dqopt->dqonoff_mutex);
return 0;
}
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
toputinode[cnt] = NULL;
if (type != -1 && cnt != type)
continue;
if (!sb_has_quota_loaded(sb, cnt))
continue;
if (flags & DQUOT_SUSPENDED) {
spin_lock(&dq_state_lock);
dqopt->flags |=
dquot_state_flag(DQUOT_SUSPENDED, cnt);
spin_unlock(&dq_state_lock);
} else {
spin_lock(&dq_state_lock);
dqopt->flags &= ~dquot_state_flag(flags, cnt);
if (!sb_has_quota_loaded(sb, cnt) &&
sb_has_quota_suspended(sb, cnt)) {
dqopt->flags &= ~dquot_state_flag(
DQUOT_SUSPENDED, cnt);
spin_unlock(&dq_state_lock);
iput(dqopt->files[cnt]);
dqopt->files[cnt] = NULL;
continue;
}
spin_unlock(&dq_state_lock);
}
if (sb_has_quota_loaded(sb, cnt) && !(flags & DQUOT_SUSPENDED))
continue;
drop_dquot_ref(sb, cnt);
invalidate_dquots(sb, cnt);
if (info_dirty(&dqopt->info[cnt]))
sb->dq_op->write_info(sb, cnt);
if (dqopt->ops[cnt]->free_file_info)
dqopt->ops[cnt]->free_file_info(sb, cnt);
put_quota_format(dqopt->info[cnt].dqi_format);
toputinode[cnt] = dqopt->files[cnt];
if (!sb_has_quota_loaded(sb, cnt))
dqopt->files[cnt] = NULL;
dqopt->info[cnt].dqi_flags = 0;
dqopt->info[cnt].dqi_igrace = 0;
dqopt->info[cnt].dqi_bgrace = 0;
dqopt->ops[cnt] = NULL;
}
mutex_unlock(&dqopt->dqonoff_mutex);
if (dqopt->flags & DQUOT_QUOTA_SYS_FILE)
goto put_inodes;
if (sb->s_op->sync_fs)
sb->s_op->sync_fs(sb, 1);
sync_blockdev(sb->s_bdev);
for (cnt = 0; cnt < MAXQUOTAS; cnt++)
if (toputinode[cnt]) {
mutex_lock(&dqopt->dqonoff_mutex);
if (!sb_has_quota_loaded(sb, cnt)) {
mutex_lock(&toputinode[cnt]->i_mutex);
toputinode[cnt]->i_flags &= ~(S_IMMUTABLE |
S_NOATIME | S_NOQUOTA);
truncate_inode_pages(&toputinode[cnt]->i_data,
0);
mutex_unlock(&toputinode[cnt]->i_mutex);
mark_inode_dirty_sync(toputinode[cnt]);
}
mutex_unlock(&dqopt->dqonoff_mutex);
}
if (sb->s_bdev)
invalidate_bdev(sb->s_bdev);
put_inodes:
for (cnt = 0; cnt < MAXQUOTAS; cnt++)
if (toputinode[cnt]) {
if (!(flags & DQUOT_SUSPENDED))
iput(toputinode[cnt]);
else if (!toputinode[cnt]->i_nlink)
ret = -EBUSY;
}
return ret;
}
int dquot_quota_off(struct super_block *sb, int type)
{
return dquot_disable(sb, type,
DQUOT_USAGE_ENABLED | DQUOT_LIMITS_ENABLED);
}
static int vfs_load_quota_inode(struct inode *inode, int type, int format_id,
unsigned int flags)
{
struct quota_format_type *fmt = find_quota_format(format_id);
struct super_block *sb = inode->i_sb;
struct quota_info *dqopt = sb_dqopt(sb);
int error;
int oldflags = -1;
if (!fmt)
return -ESRCH;
if (!S_ISREG(inode->i_mode)) {
error = -EACCES;
goto out_fmt;
}
if (IS_RDONLY(inode)) {
error = -EROFS;
goto out_fmt;
}
if (!sb->s_op->quota_write || !sb->s_op->quota_read) {
error = -EINVAL;
goto out_fmt;
}
if (!(flags & DQUOT_USAGE_ENABLED)) {
error = -EINVAL;
goto out_fmt;
}
if (!(dqopt->flags & DQUOT_QUOTA_SYS_FILE)) {
sync_filesystem(sb);
invalidate_bdev(sb->s_bdev);
}
mutex_lock(&dqopt->dqonoff_mutex);
if (sb_has_quota_loaded(sb, type)) {
error = -EBUSY;
goto out_lock;
}
if (!(dqopt->flags & DQUOT_QUOTA_SYS_FILE)) {
mutex_lock(&inode->i_mutex);
oldflags = inode->i_flags & (S_NOATIME | S_IMMUTABLE |
S_NOQUOTA);
inode->i_flags |= S_NOQUOTA | S_NOATIME | S_IMMUTABLE;
mutex_unlock(&inode->i_mutex);
__dquot_drop(inode);
}
error = -EIO;
dqopt->files[type] = igrab(inode);
if (!dqopt->files[type])
goto out_lock;
error = -EINVAL;
if (!fmt->qf_ops->check_quota_file(sb, type))
goto out_file_init;
dqopt->ops[type] = fmt->qf_ops;
dqopt->info[type].dqi_format = fmt;
dqopt->info[type].dqi_fmt_id = format_id;
INIT_LIST_HEAD(&dqopt->info[type].dqi_dirty_list);
mutex_lock(&dqopt->dqio_mutex);
error = dqopt->ops[type]->read_file_info(sb, type);
if (error < 0) {
mutex_unlock(&dqopt->dqio_mutex);
goto out_file_init;
}
if (dqopt->flags & DQUOT_QUOTA_SYS_FILE)
dqopt->info[type].dqi_flags |= DQF_SYS_FILE;
mutex_unlock(&dqopt->dqio_mutex);
spin_lock(&dq_state_lock);
dqopt->flags |= dquot_state_flag(flags, type);
spin_unlock(&dq_state_lock);
add_dquot_ref(sb, type);
mutex_unlock(&dqopt->dqonoff_mutex);
return 0;
out_file_init:
dqopt->files[type] = NULL;
iput(inode);
out_lock:
if (oldflags != -1) {
mutex_lock(&inode->i_mutex);
inode->i_flags &= ~(S_NOATIME | S_NOQUOTA | S_IMMUTABLE);
inode->i_flags |= oldflags;
mutex_unlock(&inode->i_mutex);
}
mutex_unlock(&dqopt->dqonoff_mutex);
out_fmt:
put_quota_format(fmt);
return error;
}
int dquot_resume(struct super_block *sb, int type)
{
struct quota_info *dqopt = sb_dqopt(sb);
struct inode *inode;
int ret = 0, cnt;
unsigned int flags;
for (cnt = 0; cnt < MAXQUOTAS; cnt++) {
if (type != -1 && cnt != type)
continue;
mutex_lock(&dqopt->dqonoff_mutex);
if (!sb_has_quota_suspended(sb, cnt)) {
mutex_unlock(&dqopt->dqonoff_mutex);
continue;
}
inode = dqopt->files[cnt];
dqopt->files[cnt] = NULL;
spin_lock(&dq_state_lock);
flags = dqopt->flags & dquot_state_flag(DQUOT_USAGE_ENABLED |
DQUOT_LIMITS_ENABLED,
cnt);
dqopt->flags &= ~dquot_state_flag(DQUOT_STATE_FLAGS, cnt);
spin_unlock(&dq_state_lock);
mutex_unlock(&dqopt->dqonoff_mutex);
flags = dquot_generic_flag(flags, cnt);
ret = vfs_load_quota_inode(inode, cnt,
dqopt->info[cnt].dqi_fmt_id, flags);
iput(inode);
}
return ret;
}
int dquot_quota_on(struct super_block *sb, int type, int format_id,
struct path *path)
{
int error = security_quota_on(path->dentry);
if (error)
return error;
if (path->dentry->d_sb != sb)
error = -EXDEV;
else
error = vfs_load_quota_inode(path->dentry->d_inode, type,
format_id, DQUOT_USAGE_ENABLED |
DQUOT_LIMITS_ENABLED);
return error;
}
int dquot_enable(struct inode *inode, int type, int format_id,
unsigned int flags)
{
int ret = 0;
struct super_block *sb = inode->i_sb;
struct quota_info *dqopt = sb_dqopt(sb);
BUG_ON(flags & DQUOT_SUSPENDED);
if (!flags)
return 0;
if (sb_has_quota_loaded(sb, type)) {
mutex_lock(&dqopt->dqonoff_mutex);
if (!sb_has_quota_loaded(sb, type)) {
mutex_unlock(&dqopt->dqonoff_mutex);
goto load_quota;
}
if (flags & DQUOT_USAGE_ENABLED &&
sb_has_quota_usage_enabled(sb, type)) {
ret = -EBUSY;
goto out_lock;
}
if (flags & DQUOT_LIMITS_ENABLED &&
sb_has_quota_limits_enabled(sb, type)) {
ret = -EBUSY;
goto out_lock;
}
spin_lock(&dq_state_lock);
sb_dqopt(sb)->flags |= dquot_state_flag(flags, type);
spin_unlock(&dq_state_lock);
out_lock:
mutex_unlock(&dqopt->dqonoff_mutex);
return ret;
}
load_quota:
return vfs_load_quota_inode(inode, type, format_id, flags);
}
int dquot_quota_on_mount(struct super_block *sb, char *qf_name,
int format_id, int type)
{
struct dentry *dentry;
int error;
mutex_lock(&sb->s_root->d_inode->i_mutex);
dentry = lookup_one_len(qf_name, sb->s_root, strlen(qf_name));
mutex_unlock(&sb->s_root->d_inode->i_mutex);
if (IS_ERR(dentry))
return PTR_ERR(dentry);
if (!dentry->d_inode) {
error = -ENOENT;
goto out;
}
error = security_quota_on(dentry);
if (!error)
error = vfs_load_quota_inode(dentry->d_inode, type, format_id,
DQUOT_USAGE_ENABLED | DQUOT_LIMITS_ENABLED);
out:
dput(dentry);
return error;
}
static inline qsize_t qbtos(qsize_t blocks)
{
return blocks << QIF_DQBLKSIZE_BITS;
}
static inline qsize_t stoqb(qsize_t space)
{
return (space + QIF_DQBLKSIZE - 1) >> QIF_DQBLKSIZE_BITS;
}
static void do_get_dqblk(struct dquot *dquot, struct qc_dqblk *di)
{
struct mem_dqblk *dm = &dquot->dq_dqb;
memset(di, 0, sizeof(*di));
spin_lock(&dq_data_lock);
di->d_spc_hardlimit = dm->dqb_bhardlimit;
di->d_spc_softlimit = dm->dqb_bsoftlimit;
di->d_ino_hardlimit = dm->dqb_ihardlimit;
di->d_ino_softlimit = dm->dqb_isoftlimit;
di->d_space = dm->dqb_curspace + dm->dqb_rsvspace;
di->d_ino_count = dm->dqb_curinodes;
di->d_spc_timer = dm->dqb_btime;
di->d_ino_timer = dm->dqb_itime;
spin_unlock(&dq_data_lock);
}
int dquot_get_dqblk(struct super_block *sb, struct kqid qid,
struct qc_dqblk *di)
{
struct dquot *dquot;
dquot = dqget(sb, qid);
if (!dquot)
return -ESRCH;
do_get_dqblk(dquot, di);
dqput(dquot);
return 0;
}
static int do_set_dqblk(struct dquot *dquot, struct qc_dqblk *di)
{
struct mem_dqblk *dm = &dquot->dq_dqb;
int check_blim = 0, check_ilim = 0;
struct mem_dqinfo *dqi = &sb_dqopt(dquot->dq_sb)->info[dquot->dq_id.type];
if (di->d_fieldmask & ~VFS_QC_MASK)
return -EINVAL;
if (((di->d_fieldmask & QC_SPC_SOFT) &&
stoqb(di->d_spc_softlimit) > dqi->dqi_maxblimit) ||
((di->d_fieldmask & QC_SPC_HARD) &&
stoqb(di->d_spc_hardlimit) > dqi->dqi_maxblimit) ||
((di->d_fieldmask & QC_INO_SOFT) &&
(di->d_ino_softlimit > dqi->dqi_maxilimit)) ||
((di->d_fieldmask & QC_INO_HARD) &&
(di->d_ino_hardlimit > dqi->dqi_maxilimit)))
return -ERANGE;
spin_lock(&dq_data_lock);
if (di->d_fieldmask & QC_SPACE) {
dm->dqb_curspace = di->d_space - dm->dqb_rsvspace;
check_blim = 1;
set_bit(DQ_LASTSET_B + QIF_SPACE_B, &dquot->dq_flags);
}
if (di->d_fieldmask & QC_SPC_SOFT)
dm->dqb_bsoftlimit = di->d_spc_softlimit;
if (di->d_fieldmask & QC_SPC_HARD)
dm->dqb_bhardlimit = di->d_spc_hardlimit;
if (di->d_fieldmask & (QC_SPC_SOFT | QC_SPC_HARD)) {
check_blim = 1;
set_bit(DQ_LASTSET_B + QIF_BLIMITS_B, &dquot->dq_flags);
}
if (di->d_fieldmask & QC_INO_COUNT) {
dm->dqb_curinodes = di->d_ino_count;
check_ilim = 1;
set_bit(DQ_LASTSET_B + QIF_INODES_B, &dquot->dq_flags);
}
if (di->d_fieldmask & QC_INO_SOFT)
dm->dqb_isoftlimit = di->d_ino_softlimit;
if (di->d_fieldmask & QC_INO_HARD)
dm->dqb_ihardlimit = di->d_ino_hardlimit;
if (di->d_fieldmask & (QC_INO_SOFT | QC_INO_HARD)) {
check_ilim = 1;
set_bit(DQ_LASTSET_B + QIF_ILIMITS_B, &dquot->dq_flags);
}
if (di->d_fieldmask & QC_SPC_TIMER) {
dm->dqb_btime = di->d_spc_timer;
check_blim = 1;
set_bit(DQ_LASTSET_B + QIF_BTIME_B, &dquot->dq_flags);
}
if (di->d_fieldmask & QC_INO_TIMER) {
dm->dqb_itime = di->d_ino_timer;
check_ilim = 1;
set_bit(DQ_LASTSET_B + QIF_ITIME_B, &dquot->dq_flags);
}
if (check_blim) {
if (!dm->dqb_bsoftlimit ||
dm->dqb_curspace < dm->dqb_bsoftlimit) {
dm->dqb_btime = 0;
clear_bit(DQ_BLKS_B, &dquot->dq_flags);
} else if (!(di->d_fieldmask & QC_SPC_TIMER))
dm->dqb_btime = get_seconds() + dqi->dqi_bgrace;
}
if (check_ilim) {
if (!dm->dqb_isoftlimit ||
dm->dqb_curinodes < dm->dqb_isoftlimit) {
dm->dqb_itime = 0;
clear_bit(DQ_INODES_B, &dquot->dq_flags);
} else if (!(di->d_fieldmask & QC_INO_TIMER))
dm->dqb_itime = get_seconds() + dqi->dqi_igrace;
}
if (dm->dqb_bhardlimit || dm->dqb_bsoftlimit || dm->dqb_ihardlimit ||
dm->dqb_isoftlimit)
clear_bit(DQ_FAKE_B, &dquot->dq_flags);
else
set_bit(DQ_FAKE_B, &dquot->dq_flags);
spin_unlock(&dq_data_lock);
mark_dquot_dirty(dquot);
return 0;
}
int dquot_set_dqblk(struct super_block *sb, struct kqid qid,
struct qc_dqblk *di)
{
struct dquot *dquot;
int rc;
dquot = dqget(sb, qid);
if (!dquot) {
rc = -ESRCH;
goto out;
}
rc = do_set_dqblk(dquot, di);
dqput(dquot);
out:
return rc;
}
int dquot_get_dqinfo(struct super_block *sb, int type, struct if_dqinfo *ii)
{
struct mem_dqinfo *mi;
mutex_lock(&sb_dqopt(sb)->dqonoff_mutex);
if (!sb_has_quota_active(sb, type)) {
mutex_unlock(&sb_dqopt(sb)->dqonoff_mutex);
return -ESRCH;
}
mi = sb_dqopt(sb)->info + type;
spin_lock(&dq_data_lock);
ii->dqi_bgrace = mi->dqi_bgrace;
ii->dqi_igrace = mi->dqi_igrace;
ii->dqi_flags = mi->dqi_flags & DQF_GETINFO_MASK;
ii->dqi_valid = IIF_ALL;
spin_unlock(&dq_data_lock);
mutex_unlock(&sb_dqopt(sb)->dqonoff_mutex);
return 0;
}
int dquot_set_dqinfo(struct super_block *sb, int type, struct if_dqinfo *ii)
{
struct mem_dqinfo *mi;
int err = 0;
mutex_lock(&sb_dqopt(sb)->dqonoff_mutex);
if (!sb_has_quota_active(sb, type)) {
err = -ESRCH;
goto out;
}
mi = sb_dqopt(sb)->info + type;
spin_lock(&dq_data_lock);
if (ii->dqi_valid & IIF_BGRACE)
mi->dqi_bgrace = ii->dqi_bgrace;
if (ii->dqi_valid & IIF_IGRACE)
mi->dqi_igrace = ii->dqi_igrace;
if (ii->dqi_valid & IIF_FLAGS)
mi->dqi_flags = (mi->dqi_flags & ~DQF_SETINFO_MASK) |
(ii->dqi_flags & DQF_SETINFO_MASK);
spin_unlock(&dq_data_lock);
mark_info_dirty(sb, type);
sb->dq_op->write_info(sb, type);
out:
mutex_unlock(&sb_dqopt(sb)->dqonoff_mutex);
return err;
}
static int do_proc_dqstats(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
unsigned int type = (int *)table->data - dqstats.stat;
dqstats.stat[type] =
percpu_counter_sum_positive(&dqstats.counter[type]);
return proc_dointvec(table, write, buffer, lenp, ppos);
}
static int __init dquot_init(void)
{
int i, ret;
unsigned long nr_hash, order;
printk(KERN_NOTICE "VFS: Disk quotas %s\n", __DQUOT_VERSION__);
register_sysctl_table(sys_table);
dquot_cachep = kmem_cache_create("dquot",
sizeof(struct dquot), sizeof(unsigned long) * 4,
(SLAB_HWCACHE_ALIGN|SLAB_RECLAIM_ACCOUNT|
SLAB_MEM_SPREAD|SLAB_PANIC),
NULL);
order = 0;
dquot_hash = (struct hlist_head *)__get_free_pages(GFP_ATOMIC, order);
if (!dquot_hash)
panic("Cannot create dquot hash table");
for (i = 0; i < _DQST_DQSTAT_LAST; i++) {
ret = percpu_counter_init(&dqstats.counter[i], 0, GFP_KERNEL);
if (ret)
panic("Cannot create dquot stat counters");
}
nr_hash = (1UL << order) * PAGE_SIZE / sizeof(struct hlist_head);
dq_hash_bits = 0;
do {
dq_hash_bits++;
} while (nr_hash >> dq_hash_bits);
dq_hash_bits--;
nr_hash = 1UL << dq_hash_bits;
dq_hash_mask = nr_hash - 1;
for (i = 0; i < nr_hash; i++)
INIT_HLIST_HEAD(dquot_hash + i);
pr_info("VFS: Dquot-cache hash table entries: %ld (order %ld,"
" %ld bytes)\n", nr_hash, order, (PAGE_SIZE << order));
register_shrinker(&dqcache_shrinker);
return 0;
}
