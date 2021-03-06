static void journal_end_buffer_io_sync(struct buffer_head *bh, int uptodate)
{
struct buffer_head *orig_bh = bh->b_private;
BUFFER_TRACE(bh, "");
if (uptodate)
set_buffer_uptodate(bh);
else
clear_buffer_uptodate(bh);
if (orig_bh) {
clear_bit_unlock(BH_Shadow, &orig_bh->b_state);
smp_mb__after_atomic();
wake_up_bit(&orig_bh->b_state, BH_Shadow);
}
unlock_buffer(bh);
}
static void release_buffer_page(struct buffer_head *bh)
{
struct page *page;
if (buffer_dirty(bh))
goto nope;
if (atomic_read(&bh->b_count) != 1)
goto nope;
page = bh->b_page;
if (!page)
goto nope;
if (page->mapping)
goto nope;
if (!trylock_page(page))
goto nope;
get_page(page);
__brelse(bh);
try_to_free_buffers(page);
unlock_page(page);
put_page(page);
return;
nope:
__brelse(bh);
}
static void jbd2_commit_block_csum_set(journal_t *j, struct buffer_head *bh)
{
struct commit_header *h;
__u32 csum;
if (!jbd2_journal_has_csum_v2or3(j))
return;
h = (struct commit_header *)(bh->b_data);
h->h_chksum_type = 0;
h->h_chksum_size = 0;
h->h_chksum[0] = 0;
csum = jbd2_chksum(j, j->j_csum_seed, bh->b_data, j->j_blocksize);
h->h_chksum[0] = cpu_to_be32(csum);
}
static int journal_submit_commit_record(journal_t *journal,
transaction_t *commit_transaction,
struct buffer_head **cbh,
__u32 crc32_sum)
{
struct commit_header *tmp;
struct buffer_head *bh;
int ret;
struct timespec64 now = current_kernel_time64();
*cbh = NULL;
if (is_journal_aborted(journal))
return 0;
bh = jbd2_journal_get_descriptor_buffer(commit_transaction,
JBD2_COMMIT_BLOCK);
if (!bh)
return 1;
tmp = (struct commit_header *)bh->b_data;
tmp->h_commit_sec = cpu_to_be64(now.tv_sec);
tmp->h_commit_nsec = cpu_to_be32(now.tv_nsec);
if (jbd2_has_feature_checksum(journal)) {
tmp->h_chksum_type = JBD2_CRC32_CHKSUM;
tmp->h_chksum_size = JBD2_CRC32_CHKSUM_SIZE;
tmp->h_chksum[0] = cpu_to_be32(crc32_sum);
}
jbd2_commit_block_csum_set(journal, bh);
BUFFER_TRACE(bh, "submit commit block");
lock_buffer(bh);
clear_buffer_dirty(bh);
set_buffer_uptodate(bh);
bh->b_end_io = journal_end_buffer_io_sync;
if (journal->j_flags & JBD2_BARRIER &&
!jbd2_has_feature_async_commit(journal))
ret = submit_bh(REQ_OP_WRITE,
REQ_SYNC | REQ_PREFLUSH | REQ_FUA, bh);
else
ret = submit_bh(REQ_OP_WRITE, REQ_SYNC, bh);
*cbh = bh;
return ret;
}
static int journal_wait_on_commit_record(journal_t *journal,
struct buffer_head *bh)
{
int ret = 0;
clear_buffer_dirty(bh);
wait_on_buffer(bh);
if (unlikely(!buffer_uptodate(bh)))
ret = -EIO;
put_bh(bh);
return ret;
}
static int journal_submit_inode_data_buffers(struct address_space *mapping)
{
int ret;
struct writeback_control wbc = {
.sync_mode = WB_SYNC_ALL,
.nr_to_write = mapping->nrpages * 2,
.range_start = 0,
.range_end = i_size_read(mapping->host),
};
ret = generic_writepages(mapping, &wbc);
return ret;
}
static int journal_submit_data_buffers(journal_t *journal,
transaction_t *commit_transaction)
{
struct jbd2_inode *jinode;
int err, ret = 0;
struct address_space *mapping;
spin_lock(&journal->j_list_lock);
list_for_each_entry(jinode, &commit_transaction->t_inode_list, i_list) {
if (!(jinode->i_flags & JI_WRITE_DATA))
continue;
mapping = jinode->i_vfs_inode->i_mapping;
jinode->i_flags |= JI_COMMIT_RUNNING;
spin_unlock(&journal->j_list_lock);
trace_jbd2_submit_inode_data(jinode->i_vfs_inode);
err = journal_submit_inode_data_buffers(mapping);
if (!ret)
ret = err;
spin_lock(&journal->j_list_lock);
J_ASSERT(jinode->i_transaction == commit_transaction);
jinode->i_flags &= ~JI_COMMIT_RUNNING;
smp_mb();
wake_up_bit(&jinode->i_flags, __JI_COMMIT_RUNNING);
}
spin_unlock(&journal->j_list_lock);
return ret;
}
static int journal_finish_inode_data_buffers(journal_t *journal,
transaction_t *commit_transaction)
{
struct jbd2_inode *jinode, *next_i;
int err, ret = 0;
spin_lock(&journal->j_list_lock);
list_for_each_entry(jinode, &commit_transaction->t_inode_list, i_list) {
if (!(jinode->i_flags & JI_WAIT_DATA))
continue;
jinode->i_flags |= JI_COMMIT_RUNNING;
spin_unlock(&journal->j_list_lock);
err = filemap_fdatawait_keep_errors(
jinode->i_vfs_inode->i_mapping);
if (!ret)
ret = err;
spin_lock(&journal->j_list_lock);
jinode->i_flags &= ~JI_COMMIT_RUNNING;
smp_mb();
wake_up_bit(&jinode->i_flags, __JI_COMMIT_RUNNING);
}
list_for_each_entry_safe(jinode, next_i,
&commit_transaction->t_inode_list, i_list) {
list_del(&jinode->i_list);
if (jinode->i_next_transaction) {
jinode->i_transaction = jinode->i_next_transaction;
jinode->i_next_transaction = NULL;
list_add(&jinode->i_list,
&jinode->i_transaction->t_inode_list);
} else {
jinode->i_transaction = NULL;
}
}
spin_unlock(&journal->j_list_lock);
return ret;
}
static __u32 jbd2_checksum_data(__u32 crc32_sum, struct buffer_head *bh)
{
struct page *page = bh->b_page;
char *addr;
__u32 checksum;
addr = kmap_atomic(page);
checksum = crc32_be(crc32_sum,
(void *)(addr + offset_in_page(bh->b_data)), bh->b_size);
kunmap_atomic(addr);
return checksum;
}
static void write_tag_block(journal_t *j, journal_block_tag_t *tag,
unsigned long long block)
{
tag->t_blocknr = cpu_to_be32(block & (u32)~0);
if (jbd2_has_feature_64bit(j))
tag->t_blocknr_high = cpu_to_be32((block >> 31) >> 1);
}
static void jbd2_block_tag_csum_set(journal_t *j, journal_block_tag_t *tag,
struct buffer_head *bh, __u32 sequence)
{
journal_block_tag3_t *tag3 = (journal_block_tag3_t *)tag;
struct page *page = bh->b_page;
__u8 *addr;
__u32 csum32;
__be32 seq;
if (!jbd2_journal_has_csum_v2or3(j))
return;
seq = cpu_to_be32(sequence);
addr = kmap_atomic(page);
csum32 = jbd2_chksum(j, j->j_csum_seed, (__u8 *)&seq, sizeof(seq));
csum32 = jbd2_chksum(j, csum32, addr + offset_in_page(bh->b_data),
bh->b_size);
kunmap_atomic(addr);
if (jbd2_has_feature_csum3(j))
tag3->t_checksum = cpu_to_be32(csum32);
else
tag->t_checksum = cpu_to_be16(csum32);
}
void jbd2_journal_commit_transaction(journal_t *journal)
{
struct transaction_stats_s stats;
transaction_t *commit_transaction;
struct journal_head *jh;
struct buffer_head *descriptor;
struct buffer_head **wbuf = journal->j_wbuf;
int bufs;
int flags;
int err;
unsigned long long blocknr;
ktime_t start_time;
u64 commit_time;
char *tagp = NULL;
journal_block_tag_t *tag = NULL;
int space_left = 0;
int first_tag = 0;
int tag_flag;
int i;
int tag_bytes = journal_tag_bytes(journal);
struct buffer_head *cbh = NULL;
__u32 crc32_sum = ~0;
struct blk_plug plug;
unsigned long first_block;
tid_t first_tid;
int update_tail;
int csum_size = 0;
LIST_HEAD(io_bufs);
LIST_HEAD(log_bufs);
if (jbd2_journal_has_csum_v2or3(journal))
csum_size = sizeof(struct jbd2_journal_block_tail);
if (journal->j_flags & JBD2_FLUSHED) {
jbd_debug(3, "super block updated\n");
mutex_lock_io(&journal->j_checkpoint_mutex);
jbd2_journal_update_sb_log_tail(journal,
journal->j_tail_sequence,
journal->j_tail,
REQ_SYNC);
mutex_unlock(&journal->j_checkpoint_mutex);
} else {
jbd_debug(3, "superblock not updated\n");
}
J_ASSERT(journal->j_running_transaction != NULL);
J_ASSERT(journal->j_committing_transaction == NULL);
commit_transaction = journal->j_running_transaction;
trace_jbd2_start_commit(journal, commit_transaction);
jbd_debug(1, "JBD2: starting commit of transaction %d\n",
commit_transaction->t_tid);
write_lock(&journal->j_state_lock);
J_ASSERT(commit_transaction->t_state == T_RUNNING);
commit_transaction->t_state = T_LOCKED;
trace_jbd2_commit_locking(journal, commit_transaction);
stats.run.rs_wait = commit_transaction->t_max_wait;
stats.run.rs_request_delay = 0;
stats.run.rs_locked = jiffies;
if (commit_transaction->t_requested)
stats.run.rs_request_delay =
jbd2_time_diff(commit_transaction->t_requested,
stats.run.rs_locked);
stats.run.rs_running = jbd2_time_diff(commit_transaction->t_start,
stats.run.rs_locked);
spin_lock(&commit_transaction->t_handle_lock);
while (atomic_read(&commit_transaction->t_updates)) {
DEFINE_WAIT(wait);
prepare_to_wait(&journal->j_wait_updates, &wait,
TASK_UNINTERRUPTIBLE);
if (atomic_read(&commit_transaction->t_updates)) {
spin_unlock(&commit_transaction->t_handle_lock);
write_unlock(&journal->j_state_lock);
schedule();
write_lock(&journal->j_state_lock);
spin_lock(&commit_transaction->t_handle_lock);
}
finish_wait(&journal->j_wait_updates, &wait);
}
spin_unlock(&commit_transaction->t_handle_lock);
J_ASSERT (atomic_read(&commit_transaction->t_outstanding_credits) <=
journal->j_max_transaction_buffers);
while (commit_transaction->t_reserved_list) {
jh = commit_transaction->t_reserved_list;
JBUFFER_TRACE(jh, "reserved, unused: refile");
if (jh->b_committed_data) {
struct buffer_head *bh = jh2bh(jh);
jbd_lock_bh_state(bh);
jbd2_free(jh->b_committed_data, bh->b_size);
jh->b_committed_data = NULL;
jbd_unlock_bh_state(bh);
}
jbd2_journal_refile_buffer(journal, jh);
}
spin_lock(&journal->j_list_lock);
__jbd2_journal_clean_checkpoint_list(journal, false);
spin_unlock(&journal->j_list_lock);
jbd_debug(3, "JBD2: commit phase 1\n");
jbd2_clear_buffer_revoked_flags(journal);
jbd2_journal_switch_revoke_table(journal);
atomic_sub(atomic_read(&journal->j_reserved_credits),
&commit_transaction->t_outstanding_credits);
trace_jbd2_commit_flushing(journal, commit_transaction);
stats.run.rs_flushing = jiffies;
stats.run.rs_locked = jbd2_time_diff(stats.run.rs_locked,
stats.run.rs_flushing);
commit_transaction->t_state = T_FLUSH;
journal->j_committing_transaction = commit_transaction;
journal->j_running_transaction = NULL;
start_time = ktime_get();
commit_transaction->t_log_start = journal->j_head;
wake_up(&journal->j_wait_transaction_locked);
write_unlock(&journal->j_state_lock);
jbd_debug(3, "JBD2: commit phase 2a\n");
err = journal_submit_data_buffers(journal, commit_transaction);
if (err)
jbd2_journal_abort(journal, err);
blk_start_plug(&plug);
jbd2_journal_write_revoke_records(commit_transaction, &log_bufs);
jbd_debug(3, "JBD2: commit phase 2b\n");
write_lock(&journal->j_state_lock);
commit_transaction->t_state = T_COMMIT;
write_unlock(&journal->j_state_lock);
trace_jbd2_commit_logging(journal, commit_transaction);
stats.run.rs_logging = jiffies;
stats.run.rs_flushing = jbd2_time_diff(stats.run.rs_flushing,
stats.run.rs_logging);
stats.run.rs_blocks =
atomic_read(&commit_transaction->t_outstanding_credits);
stats.run.rs_blocks_logged = 0;
J_ASSERT(commit_transaction->t_nr_buffers <=
atomic_read(&commit_transaction->t_outstanding_credits));
err = 0;
bufs = 0;
descriptor = NULL;
while (commit_transaction->t_buffers) {
jh = commit_transaction->t_buffers;
if (is_journal_aborted(journal)) {
clear_buffer_jbddirty(jh2bh(jh));
JBUFFER_TRACE(jh, "journal is aborting: refile");
jbd2_buffer_abort_trigger(jh,
jh->b_frozen_data ?
jh->b_frozen_triggers :
jh->b_triggers);
jbd2_journal_refile_buffer(journal, jh);
if (!commit_transaction->t_buffers)
goto start_journal_io;
continue;
}
if (!descriptor) {
J_ASSERT (bufs == 0);
jbd_debug(4, "JBD2: get descriptor\n");
descriptor = jbd2_journal_get_descriptor_buffer(
commit_transaction,
JBD2_DESCRIPTOR_BLOCK);
if (!descriptor) {
jbd2_journal_abort(journal, -EIO);
continue;
}
jbd_debug(4, "JBD2: got buffer %llu (%p)\n",
(unsigned long long)descriptor->b_blocknr,
descriptor->b_data);
tagp = &descriptor->b_data[sizeof(journal_header_t)];
space_left = descriptor->b_size -
sizeof(journal_header_t);
first_tag = 1;
set_buffer_jwrite(descriptor);
set_buffer_dirty(descriptor);
wbuf[bufs++] = descriptor;
BUFFER_TRACE(descriptor, "ph3: file as descriptor");
jbd2_file_log_bh(&log_bufs, descriptor);
}
err = jbd2_journal_next_log_block(journal, &blocknr);
if (err) {
jbd2_journal_abort(journal, err);
continue;
}
atomic_dec(&commit_transaction->t_outstanding_credits);
atomic_inc(&jh2bh(jh)->b_count);
set_bit(BH_JWrite, &jh2bh(jh)->b_state);
JBUFFER_TRACE(jh, "ph3: write metadata");
flags = jbd2_journal_write_metadata_buffer(commit_transaction,
jh, &wbuf[bufs], blocknr);
if (flags < 0) {
jbd2_journal_abort(journal, flags);
continue;
}
jbd2_file_log_bh(&io_bufs, wbuf[bufs]);
tag_flag = 0;
if (flags & 1)
tag_flag |= JBD2_FLAG_ESCAPE;
if (!first_tag)
tag_flag |= JBD2_FLAG_SAME_UUID;
tag = (journal_block_tag_t *) tagp;
write_tag_block(journal, tag, jh2bh(jh)->b_blocknr);
tag->t_flags = cpu_to_be16(tag_flag);
jbd2_block_tag_csum_set(journal, tag, wbuf[bufs],
commit_transaction->t_tid);
tagp += tag_bytes;
space_left -= tag_bytes;
bufs++;
if (first_tag) {
memcpy (tagp, journal->j_uuid, 16);
tagp += 16;
space_left -= 16;
first_tag = 0;
}
if (bufs == journal->j_wbufsize ||
commit_transaction->t_buffers == NULL ||
space_left < tag_bytes + 16 + csum_size) {
jbd_debug(4, "JBD2: Submit %d IOs\n", bufs);
tag->t_flags |= cpu_to_be16(JBD2_FLAG_LAST_TAG);
jbd2_descriptor_block_csum_set(journal, descriptor);
start_journal_io:
for (i = 0; i < bufs; i++) {
struct buffer_head *bh = wbuf[i];
if (jbd2_has_feature_checksum(journal)) {
crc32_sum =
jbd2_checksum_data(crc32_sum, bh);
}
lock_buffer(bh);
clear_buffer_dirty(bh);
set_buffer_uptodate(bh);
bh->b_end_io = journal_end_buffer_io_sync;
submit_bh(REQ_OP_WRITE, REQ_SYNC, bh);
}
cond_resched();
stats.run.rs_blocks_logged += bufs;
descriptor = NULL;
bufs = 0;
}
}
err = journal_finish_inode_data_buffers(journal, commit_transaction);
if (err) {
printk(KERN_WARNING
"JBD2: Detected IO errors while flushing file data "
"on %s\n", journal->j_devname);
if (journal->j_flags & JBD2_ABORT_ON_SYNCDATA_ERR)
jbd2_journal_abort(journal, err);
err = 0;
}
update_tail =
jbd2_journal_get_log_tail(journal, &first_tid, &first_block);
write_lock(&journal->j_state_lock);
if (update_tail) {
long freed = first_block - journal->j_tail;
if (first_block < journal->j_tail)
freed += journal->j_last - journal->j_first;
if (freed < journal->j_maxlen / 4)
update_tail = 0;
}
J_ASSERT(commit_transaction->t_state == T_COMMIT);
commit_transaction->t_state = T_COMMIT_DFLUSH;
write_unlock(&journal->j_state_lock);
if (commit_transaction->t_need_data_flush &&
(journal->j_fs_dev != journal->j_dev) &&
(journal->j_flags & JBD2_BARRIER))
blkdev_issue_flush(journal->j_fs_dev, GFP_NOFS, NULL);
if (jbd2_has_feature_async_commit(journal)) {
err = journal_submit_commit_record(journal, commit_transaction,
&cbh, crc32_sum);
if (err)
__jbd2_journal_abort_hard(journal);
}
blk_finish_plug(&plug);
jbd_debug(3, "JBD2: commit phase 3\n");
while (!list_empty(&io_bufs)) {
struct buffer_head *bh = list_entry(io_bufs.prev,
struct buffer_head,
b_assoc_buffers);
wait_on_buffer(bh);
cond_resched();
if (unlikely(!buffer_uptodate(bh)))
err = -EIO;
jbd2_unfile_log_bh(bh);
BUFFER_TRACE(bh, "dumping temporary bh");
__brelse(bh);
J_ASSERT_BH(bh, atomic_read(&bh->b_count) == 0);
free_buffer_head(bh);
jh = commit_transaction->t_shadow_list->b_tprev;
bh = jh2bh(jh);
clear_buffer_jwrite(bh);
J_ASSERT_BH(bh, buffer_jbddirty(bh));
J_ASSERT_BH(bh, !buffer_shadow(bh));
JBUFFER_TRACE(jh, "file as BJ_Forget");
jbd2_journal_file_buffer(jh, commit_transaction, BJ_Forget);
JBUFFER_TRACE(jh, "brelse shadowed buffer");
__brelse(bh);
}
J_ASSERT (commit_transaction->t_shadow_list == NULL);
jbd_debug(3, "JBD2: commit phase 4\n");
while (!list_empty(&log_bufs)) {
struct buffer_head *bh;
bh = list_entry(log_bufs.prev, struct buffer_head, b_assoc_buffers);
wait_on_buffer(bh);
cond_resched();
if (unlikely(!buffer_uptodate(bh)))
err = -EIO;
BUFFER_TRACE(bh, "ph5: control buffer writeout done: unfile");
clear_buffer_jwrite(bh);
jbd2_unfile_log_bh(bh);
__brelse(bh);
}
if (err)
jbd2_journal_abort(journal, err);
jbd_debug(3, "JBD2: commit phase 5\n");
write_lock(&journal->j_state_lock);
J_ASSERT(commit_transaction->t_state == T_COMMIT_DFLUSH);
commit_transaction->t_state = T_COMMIT_JFLUSH;
write_unlock(&journal->j_state_lock);
if (!jbd2_has_feature_async_commit(journal)) {
err = journal_submit_commit_record(journal, commit_transaction,
&cbh, crc32_sum);
if (err)
__jbd2_journal_abort_hard(journal);
}
if (cbh)
err = journal_wait_on_commit_record(journal, cbh);
if (jbd2_has_feature_async_commit(journal) &&
journal->j_flags & JBD2_BARRIER) {
blkdev_issue_flush(journal->j_dev, GFP_NOFS, NULL);
}
if (err)
jbd2_journal_abort(journal, err);
if (update_tail)
jbd2_update_log_tail(journal, first_tid, first_block);
jbd_debug(3, "JBD2: commit phase 6\n");
J_ASSERT(list_empty(&commit_transaction->t_inode_list));
J_ASSERT(commit_transaction->t_buffers == NULL);
J_ASSERT(commit_transaction->t_checkpoint_list == NULL);
J_ASSERT(commit_transaction->t_shadow_list == NULL);
restart_loop:
spin_lock(&journal->j_list_lock);
while (commit_transaction->t_forget) {
transaction_t *cp_transaction;
struct buffer_head *bh;
int try_to_free = 0;
jh = commit_transaction->t_forget;
spin_unlock(&journal->j_list_lock);
bh = jh2bh(jh);
get_bh(bh);
jbd_lock_bh_state(bh);
J_ASSERT_JH(jh, jh->b_transaction == commit_transaction);
if (jh->b_committed_data) {
jbd2_free(jh->b_committed_data, bh->b_size);
jh->b_committed_data = NULL;
if (jh->b_frozen_data) {
jh->b_committed_data = jh->b_frozen_data;
jh->b_frozen_data = NULL;
jh->b_frozen_triggers = NULL;
}
} else if (jh->b_frozen_data) {
jbd2_free(jh->b_frozen_data, bh->b_size);
jh->b_frozen_data = NULL;
jh->b_frozen_triggers = NULL;
}
spin_lock(&journal->j_list_lock);
cp_transaction = jh->b_cp_transaction;
if (cp_transaction) {
JBUFFER_TRACE(jh, "remove from old cp transaction");
cp_transaction->t_chp_stats.cs_dropped++;
__jbd2_journal_remove_checkpoint(jh);
}
if (buffer_freed(bh)) {
jh->b_modified = 0;
if (!jh->b_next_transaction) {
clear_buffer_freed(bh);
clear_buffer_jbddirty(bh);
clear_buffer_mapped(bh);
clear_buffer_new(bh);
clear_buffer_req(bh);
bh->b_bdev = NULL;
}
}
if (buffer_jbddirty(bh)) {
JBUFFER_TRACE(jh, "add to new checkpointing trans");
__jbd2_journal_insert_checkpoint(jh, commit_transaction);
if (is_journal_aborted(journal))
clear_buffer_jbddirty(bh);
} else {
J_ASSERT_BH(bh, !buffer_dirty(bh));
if (!jh->b_next_transaction)
try_to_free = 1;
}
JBUFFER_TRACE(jh, "refile or unfile buffer");
__jbd2_journal_refile_buffer(jh);
jbd_unlock_bh_state(bh);
if (try_to_free)
release_buffer_page(bh);
else
__brelse(bh);
cond_resched_lock(&journal->j_list_lock);
}
spin_unlock(&journal->j_list_lock);
write_lock(&journal->j_state_lock);
spin_lock(&journal->j_list_lock);
if (commit_transaction->t_forget) {
spin_unlock(&journal->j_list_lock);
write_unlock(&journal->j_state_lock);
goto restart_loop;
}
if (journal->j_checkpoint_transactions == NULL) {
journal->j_checkpoint_transactions = commit_transaction;
commit_transaction->t_cpnext = commit_transaction;
commit_transaction->t_cpprev = commit_transaction;
} else {
commit_transaction->t_cpnext =
journal->j_checkpoint_transactions;
commit_transaction->t_cpprev =
commit_transaction->t_cpnext->t_cpprev;
commit_transaction->t_cpnext->t_cpprev =
commit_transaction;
commit_transaction->t_cpprev->t_cpnext =
commit_transaction;
}
spin_unlock(&journal->j_list_lock);
jbd_debug(3, "JBD2: commit phase 7\n");
J_ASSERT(commit_transaction->t_state == T_COMMIT_JFLUSH);
commit_transaction->t_start = jiffies;
stats.run.rs_logging = jbd2_time_diff(stats.run.rs_logging,
commit_transaction->t_start);
stats.ts_tid = commit_transaction->t_tid;
stats.run.rs_handle_count =
atomic_read(&commit_transaction->t_handle_count);
trace_jbd2_run_stats(journal->j_fs_dev->bd_dev,
commit_transaction->t_tid, &stats.run);
stats.ts_requested = (commit_transaction->t_requested) ? 1 : 0;
commit_transaction->t_state = T_COMMIT_CALLBACK;
J_ASSERT(commit_transaction == journal->j_committing_transaction);
journal->j_commit_sequence = commit_transaction->t_tid;
journal->j_committing_transaction = NULL;
commit_time = ktime_to_ns(ktime_sub(ktime_get(), start_time));
if (likely(journal->j_average_commit_time))
journal->j_average_commit_time = (commit_time +
journal->j_average_commit_time*3) / 4;
else
journal->j_average_commit_time = commit_time;
write_unlock(&journal->j_state_lock);
if (journal->j_commit_callback)
journal->j_commit_callback(journal, commit_transaction);
trace_jbd2_end_commit(journal, commit_transaction);
jbd_debug(1, "JBD2: commit %d complete, head %d\n",
journal->j_commit_sequence, journal->j_tail_sequence);
write_lock(&journal->j_state_lock);
spin_lock(&journal->j_list_lock);
commit_transaction->t_state = T_FINISHED;
if (commit_transaction->t_checkpoint_list == NULL &&
commit_transaction->t_checkpoint_io_list == NULL) {
__jbd2_journal_drop_transaction(journal, commit_transaction);
jbd2_journal_free_transaction(commit_transaction);
}
spin_unlock(&journal->j_list_lock);
write_unlock(&journal->j_state_lock);
wake_up(&journal->j_wait_done_commit);
spin_lock(&journal->j_history_lock);
journal->j_stats.ts_tid++;
journal->j_stats.ts_requested += stats.ts_requested;
journal->j_stats.run.rs_wait += stats.run.rs_wait;
journal->j_stats.run.rs_request_delay += stats.run.rs_request_delay;
journal->j_stats.run.rs_running += stats.run.rs_running;
journal->j_stats.run.rs_locked += stats.run.rs_locked;
journal->j_stats.run.rs_flushing += stats.run.rs_flushing;
journal->j_stats.run.rs_logging += stats.run.rs_logging;
journal->j_stats.run.rs_handle_count += stats.run.rs_handle_count;
journal->j_stats.run.rs_blocks += stats.run.rs_blocks;
journal->j_stats.run.rs_blocks_logged += stats.run.rs_blocks_logged;
spin_unlock(&journal->j_history_lock);
}
