static inline void __buffer_unlink_first(struct journal_head *jh)
{
transaction_t *transaction = jh->b_cp_transaction;
jh->b_cpnext->b_cpprev = jh->b_cpprev;
jh->b_cpprev->b_cpnext = jh->b_cpnext;
if (transaction->t_checkpoint_list == jh) {
transaction->t_checkpoint_list = jh->b_cpnext;
if (transaction->t_checkpoint_list == jh)
transaction->t_checkpoint_list = NULL;
}
}
static inline void __buffer_unlink(struct journal_head *jh)
{
transaction_t *transaction = jh->b_cp_transaction;
__buffer_unlink_first(jh);
if (transaction->t_checkpoint_io_list == jh) {
transaction->t_checkpoint_io_list = jh->b_cpnext;
if (transaction->t_checkpoint_io_list == jh)
transaction->t_checkpoint_io_list = NULL;
}
}
static inline void __buffer_relink_io(struct journal_head *jh)
{
transaction_t *transaction = jh->b_cp_transaction;
__buffer_unlink_first(jh);
if (!transaction->t_checkpoint_io_list) {
jh->b_cpnext = jh->b_cpprev = jh;
} else {
jh->b_cpnext = transaction->t_checkpoint_io_list;
jh->b_cpprev = transaction->t_checkpoint_io_list->b_cpprev;
jh->b_cpprev->b_cpnext = jh;
jh->b_cpnext->b_cpprev = jh;
}
transaction->t_checkpoint_io_list = jh;
}
static int __try_to_free_cp_buf(struct journal_head *jh)
{
int ret = 0;
struct buffer_head *bh = jh2bh(jh);
if (jh->b_jlist == BJ_None && !buffer_locked(bh) &&
!buffer_dirty(bh) && !buffer_write_io_error(bh)) {
get_bh(bh);
JBUFFER_TRACE(jh, "remove from checkpoint list");
ret = __journal_remove_checkpoint(jh) + 1;
jbd_unlock_bh_state(bh);
BUFFER_TRACE(bh, "release");
__brelse(bh);
} else {
jbd_unlock_bh_state(bh);
}
return ret;
}
void __log_wait_for_space(journal_t *journal)
{
int nblocks, space_left;
assert_spin_locked(&journal->j_state_lock);
nblocks = jbd_space_needed(journal);
while (__log_space_left(journal) < nblocks) {
if (journal->j_flags & JFS_ABORT)
return;
spin_unlock(&journal->j_state_lock);
mutex_lock(&journal->j_checkpoint_mutex);
spin_lock(&journal->j_state_lock);
spin_lock(&journal->j_list_lock);
nblocks = jbd_space_needed(journal);
space_left = __log_space_left(journal);
if (space_left < nblocks) {
int chkpt = journal->j_checkpoint_transactions != NULL;
tid_t tid = 0;
if (journal->j_committing_transaction)
tid = journal->j_committing_transaction->t_tid;
spin_unlock(&journal->j_list_lock);
spin_unlock(&journal->j_state_lock);
if (chkpt) {
log_do_checkpoint(journal);
} else if (cleanup_journal_tail(journal) == 0) {
;
} else if (tid) {
log_wait_commit(journal, tid);
} else {
printk(KERN_ERR "%s: needed %d blocks and "
"only had %d space available\n",
__func__, nblocks, space_left);
printk(KERN_ERR "%s: no way to get more "
"journal space\n", __func__);
WARN_ON(1);
journal_abort(journal, 0);
}
spin_lock(&journal->j_state_lock);
} else {
spin_unlock(&journal->j_list_lock);
}
mutex_unlock(&journal->j_checkpoint_mutex);
}
}
static void jbd_sync_bh(journal_t *journal, struct buffer_head *bh)
__releases(journal->j_list_lock)
{
get_bh(bh);
spin_unlock(&journal->j_list_lock);
jbd_lock_bh_state(bh);
jbd_unlock_bh_state(bh);
put_bh(bh);
}
static int __wait_cp_io(journal_t *journal, transaction_t *transaction)
{
struct journal_head *jh;
struct buffer_head *bh;
tid_t this_tid;
int released = 0;
int ret = 0;
this_tid = transaction->t_tid;
restart:
if (journal->j_checkpoint_transactions != transaction ||
transaction->t_tid != this_tid)
return ret;
while (!released && transaction->t_checkpoint_io_list) {
jh = transaction->t_checkpoint_io_list;
bh = jh2bh(jh);
if (!jbd_trylock_bh_state(bh)) {
jbd_sync_bh(journal, bh);
spin_lock(&journal->j_list_lock);
goto restart;
}
get_bh(bh);
if (buffer_locked(bh)) {
spin_unlock(&journal->j_list_lock);
jbd_unlock_bh_state(bh);
wait_on_buffer(bh);
BUFFER_TRACE(bh, "brelse");
__brelse(bh);
spin_lock(&journal->j_list_lock);
goto restart;
}
if (unlikely(buffer_write_io_error(bh)))
ret = -EIO;
released = __journal_remove_checkpoint(jh);
jbd_unlock_bh_state(bh);
__brelse(bh);
}
return ret;
}
static void
__flush_batch(journal_t *journal, struct buffer_head **bhs, int *batch_count)
{
int i;
struct blk_plug plug;
blk_start_plug(&plug);
for (i = 0; i < *batch_count; i++)
write_dirty_buffer(bhs[i], WRITE_SYNC);
blk_finish_plug(&plug);
for (i = 0; i < *batch_count; i++) {
struct buffer_head *bh = bhs[i];
clear_buffer_jwrite(bh);
BUFFER_TRACE(bh, "brelse");
__brelse(bh);
}
*batch_count = 0;
}
static int __process_buffer(journal_t *journal, struct journal_head *jh,
struct buffer_head **bhs, int *batch_count)
{
struct buffer_head *bh = jh2bh(jh);
int ret = 0;
if (buffer_locked(bh)) {
get_bh(bh);
spin_unlock(&journal->j_list_lock);
jbd_unlock_bh_state(bh);
wait_on_buffer(bh);
BUFFER_TRACE(bh, "brelse");
__brelse(bh);
ret = 1;
} else if (jh->b_transaction != NULL) {
transaction_t *t = jh->b_transaction;
tid_t tid = t->t_tid;
spin_unlock(&journal->j_list_lock);
jbd_unlock_bh_state(bh);
log_start_commit(journal, tid);
log_wait_commit(journal, tid);
ret = 1;
} else if (!buffer_dirty(bh)) {
ret = 1;
if (unlikely(buffer_write_io_error(bh)))
ret = -EIO;
get_bh(bh);
J_ASSERT_JH(jh, !buffer_jbddirty(bh));
BUFFER_TRACE(bh, "remove from checkpoint");
__journal_remove_checkpoint(jh);
spin_unlock(&journal->j_list_lock);
jbd_unlock_bh_state(bh);
__brelse(bh);
} else {
BUFFER_TRACE(bh, "queue");
get_bh(bh);
J_ASSERT_BH(bh, !buffer_jwrite(bh));
set_buffer_jwrite(bh);
bhs[*batch_count] = bh;
__buffer_relink_io(jh);
jbd_unlock_bh_state(bh);
(*batch_count)++;
if (*batch_count == NR_BATCH) {
spin_unlock(&journal->j_list_lock);
__flush_batch(journal, bhs, batch_count);
ret = 1;
}
}
return ret;
}
int log_do_checkpoint(journal_t *journal)
{
transaction_t *transaction;
tid_t this_tid;
int result;
jbd_debug(1, "Start checkpoint\n");
result = cleanup_journal_tail(journal);
trace_jbd_checkpoint(journal, result);
jbd_debug(1, "cleanup_journal_tail returned %d\n", result);
if (result <= 0)
return result;
result = 0;
spin_lock(&journal->j_list_lock);
if (!journal->j_checkpoint_transactions)
goto out;
transaction = journal->j_checkpoint_transactions;
this_tid = transaction->t_tid;
restart:
if (journal->j_checkpoint_transactions == transaction &&
transaction->t_tid == this_tid) {
int batch_count = 0;
struct buffer_head *bhs[NR_BATCH];
struct journal_head *jh;
int retry = 0, err;
while (!retry && transaction->t_checkpoint_list) {
struct buffer_head *bh;
jh = transaction->t_checkpoint_list;
bh = jh2bh(jh);
if (!jbd_trylock_bh_state(bh)) {
jbd_sync_bh(journal, bh);
retry = 1;
break;
}
retry = __process_buffer(journal, jh, bhs,&batch_count);
if (retry < 0 && !result)
result = retry;
if (!retry && (need_resched() ||
spin_needbreak(&journal->j_list_lock))) {
spin_unlock(&journal->j_list_lock);
retry = 1;
break;
}
}
if (batch_count) {
if (!retry) {
spin_unlock(&journal->j_list_lock);
retry = 1;
}
__flush_batch(journal, bhs, &batch_count);
}
if (retry) {
spin_lock(&journal->j_list_lock);
goto restart;
}
err = __wait_cp_io(journal, transaction);
if (!result)
result = err;
}
out:
spin_unlock(&journal->j_list_lock);
if (result < 0)
journal_abort(journal, result);
else
result = cleanup_journal_tail(journal);
return (result < 0) ? result : 0;
}
int cleanup_journal_tail(journal_t *journal)
{
transaction_t * transaction;
tid_t first_tid;
unsigned int blocknr, freed;
if (is_journal_aborted(journal))
return 1;
spin_lock(&journal->j_state_lock);
spin_lock(&journal->j_list_lock);
transaction = journal->j_checkpoint_transactions;
if (transaction) {
first_tid = transaction->t_tid;
blocknr = transaction->t_log_start;
} else if ((transaction = journal->j_committing_transaction) != NULL) {
first_tid = transaction->t_tid;
blocknr = transaction->t_log_start;
} else if ((transaction = journal->j_running_transaction) != NULL) {
first_tid = transaction->t_tid;
blocknr = journal->j_head;
} else {
first_tid = journal->j_transaction_sequence;
blocknr = journal->j_head;
}
spin_unlock(&journal->j_list_lock);
J_ASSERT(blocknr != 0);
if (journal->j_tail_sequence == first_tid) {
spin_unlock(&journal->j_state_lock);
return 1;
}
spin_unlock(&journal->j_state_lock);
journal_update_sb_log_tail(journal, first_tid, blocknr,
WRITE_FLUSH_FUA);
spin_lock(&journal->j_state_lock);
freed = blocknr - journal->j_tail;
if (blocknr < journal->j_tail)
freed = freed + journal->j_last - journal->j_first;
trace_jbd_cleanup_journal_tail(journal, first_tid, blocknr, freed);
jbd_debug(1,
"Cleaning journal tail from %d to %d (offset %u), "
"freeing %u\n",
journal->j_tail_sequence, first_tid, blocknr, freed);
journal->j_free += freed;
journal->j_tail_sequence = first_tid;
journal->j_tail = blocknr;
spin_unlock(&journal->j_state_lock);
return 0;
}
static int journal_clean_one_cp_list(struct journal_head *jh, int *released)
{
struct journal_head *last_jh;
struct journal_head *next_jh = jh;
int ret, freed = 0;
*released = 0;
if (!jh)
return 0;
last_jh = jh->b_cpprev;
do {
jh = next_jh;
next_jh = jh->b_cpnext;
if (jbd_trylock_bh_state(jh2bh(jh))) {
ret = __try_to_free_cp_buf(jh);
if (ret) {
freed++;
if (ret == 2) {
*released = 1;
return freed;
}
}
}
if (need_resched())
return freed;
} while (jh != last_jh);
return freed;
}
int __journal_clean_checkpoint_list(journal_t *journal)
{
transaction_t *transaction, *last_transaction, *next_transaction;
int ret = 0;
int released;
transaction = journal->j_checkpoint_transactions;
if (!transaction)
goto out;
last_transaction = transaction->t_cpprev;
next_transaction = transaction;
do {
transaction = next_transaction;
next_transaction = transaction->t_cpnext;
ret += journal_clean_one_cp_list(transaction->
t_checkpoint_list, &released);
if (need_resched())
goto out;
if (released)
continue;
ret += journal_clean_one_cp_list(transaction->
t_checkpoint_io_list, &released);
if (need_resched())
goto out;
} while (transaction != last_transaction);
out:
return ret;
}
int __journal_remove_checkpoint(struct journal_head *jh)
{
transaction_t *transaction;
journal_t *journal;
int ret = 0;
JBUFFER_TRACE(jh, "entry");
if ((transaction = jh->b_cp_transaction) == NULL) {
JBUFFER_TRACE(jh, "not on transaction");
goto out;
}
journal = transaction->t_journal;
JBUFFER_TRACE(jh, "removing from transaction");
__buffer_unlink(jh);
jh->b_cp_transaction = NULL;
journal_put_journal_head(jh);
if (transaction->t_checkpoint_list != NULL ||
transaction->t_checkpoint_io_list != NULL)
goto out;
if (transaction->t_state != T_FINISHED)
goto out;
__journal_drop_transaction(journal, transaction);
wake_up(&journal->j_wait_logspace);
ret = 1;
out:
return ret;
}
void __journal_insert_checkpoint(struct journal_head *jh,
transaction_t *transaction)
{
JBUFFER_TRACE(jh, "entry");
J_ASSERT_JH(jh, buffer_dirty(jh2bh(jh)) || buffer_jbddirty(jh2bh(jh)));
J_ASSERT_JH(jh, jh->b_cp_transaction == NULL);
journal_grab_journal_head(jh2bh(jh));
jh->b_cp_transaction = transaction;
if (!transaction->t_checkpoint_list) {
jh->b_cpnext = jh->b_cpprev = jh;
} else {
jh->b_cpnext = transaction->t_checkpoint_list;
jh->b_cpprev = transaction->t_checkpoint_list->b_cpprev;
jh->b_cpprev->b_cpnext = jh;
jh->b_cpnext->b_cpprev = jh;
}
transaction->t_checkpoint_list = jh;
}
void __journal_drop_transaction(journal_t *journal, transaction_t *transaction)
{
assert_spin_locked(&journal->j_list_lock);
if (transaction->t_cpnext) {
transaction->t_cpnext->t_cpprev = transaction->t_cpprev;
transaction->t_cpprev->t_cpnext = transaction->t_cpnext;
if (journal->j_checkpoint_transactions == transaction)
journal->j_checkpoint_transactions =
transaction->t_cpnext;
if (journal->j_checkpoint_transactions == transaction)
journal->j_checkpoint_transactions = NULL;
}
J_ASSERT(transaction->t_state == T_FINISHED);
J_ASSERT(transaction->t_buffers == NULL);
J_ASSERT(transaction->t_sync_datalist == NULL);
J_ASSERT(transaction->t_forget == NULL);
J_ASSERT(transaction->t_iobuf_list == NULL);
J_ASSERT(transaction->t_shadow_list == NULL);
J_ASSERT(transaction->t_log_list == NULL);
J_ASSERT(transaction->t_checkpoint_list == NULL);
J_ASSERT(transaction->t_checkpoint_io_list == NULL);
J_ASSERT(transaction->t_updates == 0);
J_ASSERT(journal->j_committing_transaction != transaction);
J_ASSERT(journal->j_running_transaction != transaction);
trace_jbd_drop_transaction(journal, transaction);
jbd_debug(1, "Dropping transaction %d, all done\n", transaction->t_tid);
kfree(transaction);
}
