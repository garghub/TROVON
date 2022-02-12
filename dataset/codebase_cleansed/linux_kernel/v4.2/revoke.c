static inline int hash(journal_t *journal, unsigned long long block)
{
return hash_64(block, journal->j_revoke->hash_shift);
}
static int insert_revoke_hash(journal_t *journal, unsigned long long blocknr,
tid_t seq)
{
struct list_head *hash_list;
struct jbd2_revoke_record_s *record;
gfp_t gfp_mask = GFP_NOFS;
if (journal_oom_retry)
gfp_mask |= __GFP_NOFAIL;
record = kmem_cache_alloc(jbd2_revoke_record_cache, gfp_mask);
if (!record)
return -ENOMEM;
record->sequence = seq;
record->blocknr = blocknr;
hash_list = &journal->j_revoke->hash_table[hash(journal, blocknr)];
spin_lock(&journal->j_revoke_lock);
list_add(&record->hash, hash_list);
spin_unlock(&journal->j_revoke_lock);
return 0;
}
static struct jbd2_revoke_record_s *find_revoke_record(journal_t *journal,
unsigned long long blocknr)
{
struct list_head *hash_list;
struct jbd2_revoke_record_s *record;
hash_list = &journal->j_revoke->hash_table[hash(journal, blocknr)];
spin_lock(&journal->j_revoke_lock);
record = (struct jbd2_revoke_record_s *) hash_list->next;
while (&(record->hash) != hash_list) {
if (record->blocknr == blocknr) {
spin_unlock(&journal->j_revoke_lock);
return record;
}
record = (struct jbd2_revoke_record_s *) record->hash.next;
}
spin_unlock(&journal->j_revoke_lock);
return NULL;
}
void jbd2_journal_destroy_revoke_caches(void)
{
if (jbd2_revoke_record_cache) {
kmem_cache_destroy(jbd2_revoke_record_cache);
jbd2_revoke_record_cache = NULL;
}
if (jbd2_revoke_table_cache) {
kmem_cache_destroy(jbd2_revoke_table_cache);
jbd2_revoke_table_cache = NULL;
}
}
int __init jbd2_journal_init_revoke_caches(void)
{
J_ASSERT(!jbd2_revoke_record_cache);
J_ASSERT(!jbd2_revoke_table_cache);
jbd2_revoke_record_cache = KMEM_CACHE(jbd2_revoke_record_s,
SLAB_HWCACHE_ALIGN|SLAB_TEMPORARY);
if (!jbd2_revoke_record_cache)
goto record_cache_failure;
jbd2_revoke_table_cache = KMEM_CACHE(jbd2_revoke_table_s,
SLAB_TEMPORARY);
if (!jbd2_revoke_table_cache)
goto table_cache_failure;
return 0;
table_cache_failure:
jbd2_journal_destroy_revoke_caches();
record_cache_failure:
return -ENOMEM;
}
static struct jbd2_revoke_table_s *jbd2_journal_init_revoke_table(int hash_size)
{
int shift = 0;
int tmp = hash_size;
struct jbd2_revoke_table_s *table;
table = kmem_cache_alloc(jbd2_revoke_table_cache, GFP_KERNEL);
if (!table)
goto out;
while((tmp >>= 1UL) != 0UL)
shift++;
table->hash_size = hash_size;
table->hash_shift = shift;
table->hash_table =
kmalloc(hash_size * sizeof(struct list_head), GFP_KERNEL);
if (!table->hash_table) {
kmem_cache_free(jbd2_revoke_table_cache, table);
table = NULL;
goto out;
}
for (tmp = 0; tmp < hash_size; tmp++)
INIT_LIST_HEAD(&table->hash_table[tmp]);
out:
return table;
}
static void jbd2_journal_destroy_revoke_table(struct jbd2_revoke_table_s *table)
{
int i;
struct list_head *hash_list;
for (i = 0; i < table->hash_size; i++) {
hash_list = &table->hash_table[i];
J_ASSERT(list_empty(hash_list));
}
kfree(table->hash_table);
kmem_cache_free(jbd2_revoke_table_cache, table);
}
int jbd2_journal_init_revoke(journal_t *journal, int hash_size)
{
J_ASSERT(journal->j_revoke_table[0] == NULL);
J_ASSERT(is_power_of_2(hash_size));
journal->j_revoke_table[0] = jbd2_journal_init_revoke_table(hash_size);
if (!journal->j_revoke_table[0])
goto fail0;
journal->j_revoke_table[1] = jbd2_journal_init_revoke_table(hash_size);
if (!journal->j_revoke_table[1])
goto fail1;
journal->j_revoke = journal->j_revoke_table[1];
spin_lock_init(&journal->j_revoke_lock);
return 0;
fail1:
jbd2_journal_destroy_revoke_table(journal->j_revoke_table[0]);
fail0:
return -ENOMEM;
}
void jbd2_journal_destroy_revoke(journal_t *journal)
{
journal->j_revoke = NULL;
if (journal->j_revoke_table[0])
jbd2_journal_destroy_revoke_table(journal->j_revoke_table[0]);
if (journal->j_revoke_table[1])
jbd2_journal_destroy_revoke_table(journal->j_revoke_table[1]);
}
int jbd2_journal_revoke(handle_t *handle, unsigned long long blocknr,
struct buffer_head *bh_in)
{
struct buffer_head *bh = NULL;
journal_t *journal;
struct block_device *bdev;
int err;
might_sleep();
if (bh_in)
BUFFER_TRACE(bh_in, "enter");
journal = handle->h_transaction->t_journal;
if (!jbd2_journal_set_features(journal, 0, 0, JBD2_FEATURE_INCOMPAT_REVOKE)){
J_ASSERT (!"Cannot set revoke feature!");
return -EINVAL;
}
bdev = journal->j_fs_dev;
bh = bh_in;
if (!bh) {
bh = __find_get_block(bdev, blocknr, journal->j_blocksize);
if (bh)
BUFFER_TRACE(bh, "found on hash");
}
#ifdef JBD2_EXPENSIVE_CHECKING
else {
struct buffer_head *bh2;
bh2 = __find_get_block(bdev, blocknr, journal->j_blocksize);
if (bh2) {
if (bh2 != bh && buffer_revokevalid(bh2))
J_ASSERT_BH(bh2, buffer_revoked(bh2));
put_bh(bh2);
}
}
#endif
if (bh) {
if (!J_EXPECT_BH(bh, !buffer_revoked(bh),
"inconsistent data on disk")) {
if (!bh_in)
brelse(bh);
return -EIO;
}
set_buffer_revoked(bh);
set_buffer_revokevalid(bh);
if (bh_in) {
BUFFER_TRACE(bh_in, "call jbd2_journal_forget");
jbd2_journal_forget(handle, bh_in);
} else {
BUFFER_TRACE(bh, "call brelse");
__brelse(bh);
}
}
jbd_debug(2, "insert revoke for block %llu, bh_in=%p\n",blocknr, bh_in);
err = insert_revoke_hash(journal, blocknr,
handle->h_transaction->t_tid);
BUFFER_TRACE(bh_in, "exit");
return err;
}
int jbd2_journal_cancel_revoke(handle_t *handle, struct journal_head *jh)
{
struct jbd2_revoke_record_s *record;
journal_t *journal = handle->h_transaction->t_journal;
int need_cancel;
int did_revoke = 0;
struct buffer_head *bh = jh2bh(jh);
jbd_debug(4, "journal_head %p, cancelling revoke\n", jh);
if (test_set_buffer_revokevalid(bh)) {
need_cancel = test_clear_buffer_revoked(bh);
} else {
need_cancel = 1;
clear_buffer_revoked(bh);
}
if (need_cancel) {
record = find_revoke_record(journal, bh->b_blocknr);
if (record) {
jbd_debug(4, "cancelled existing revoke on "
"blocknr %llu\n", (unsigned long long)bh->b_blocknr);
spin_lock(&journal->j_revoke_lock);
list_del(&record->hash);
spin_unlock(&journal->j_revoke_lock);
kmem_cache_free(jbd2_revoke_record_cache, record);
did_revoke = 1;
}
}
#ifdef JBD2_EXPENSIVE_CHECKING
record = find_revoke_record(journal, bh->b_blocknr);
J_ASSERT_JH(jh, record == NULL);
#endif
if (need_cancel) {
struct buffer_head *bh2;
bh2 = __find_get_block(bh->b_bdev, bh->b_blocknr, bh->b_size);
if (bh2) {
if (bh2 != bh)
clear_buffer_revoked(bh2);
__brelse(bh2);
}
}
return did_revoke;
}
void jbd2_clear_buffer_revoked_flags(journal_t *journal)
{
struct jbd2_revoke_table_s *revoke = journal->j_revoke;
int i = 0;
for (i = 0; i < revoke->hash_size; i++) {
struct list_head *hash_list;
struct list_head *list_entry;
hash_list = &revoke->hash_table[i];
list_for_each(list_entry, hash_list) {
struct jbd2_revoke_record_s *record;
struct buffer_head *bh;
record = (struct jbd2_revoke_record_s *)list_entry;
bh = __find_get_block(journal->j_fs_dev,
record->blocknr,
journal->j_blocksize);
if (bh) {
clear_buffer_revoked(bh);
__brelse(bh);
}
}
}
}
void jbd2_journal_switch_revoke_table(journal_t *journal)
{
int i;
if (journal->j_revoke == journal->j_revoke_table[0])
journal->j_revoke = journal->j_revoke_table[1];
else
journal->j_revoke = journal->j_revoke_table[0];
for (i = 0; i < journal->j_revoke->hash_size; i++)
INIT_LIST_HEAD(&journal->j_revoke->hash_table[i]);
}
void jbd2_journal_write_revoke_records(journal_t *journal,
transaction_t *transaction,
struct list_head *log_bufs,
int write_op)
{
struct buffer_head *descriptor;
struct jbd2_revoke_record_s *record;
struct jbd2_revoke_table_s *revoke;
struct list_head *hash_list;
int i, offset, count;
descriptor = NULL;
offset = 0;
count = 0;
revoke = journal->j_revoke == journal->j_revoke_table[0] ?
journal->j_revoke_table[1] : journal->j_revoke_table[0];
for (i = 0; i < revoke->hash_size; i++) {
hash_list = &revoke->hash_table[i];
while (!list_empty(hash_list)) {
record = (struct jbd2_revoke_record_s *)
hash_list->next;
write_one_revoke_record(journal, transaction, log_bufs,
&descriptor, &offset,
record, write_op);
count++;
list_del(&record->hash);
kmem_cache_free(jbd2_revoke_record_cache, record);
}
}
if (descriptor)
flush_descriptor(journal, descriptor, offset, write_op);
jbd_debug(1, "Wrote %d revoke records\n", count);
}
static void write_one_revoke_record(journal_t *journal,
transaction_t *transaction,
struct list_head *log_bufs,
struct buffer_head **descriptorp,
int *offsetp,
struct jbd2_revoke_record_s *record,
int write_op)
{
int csum_size = 0;
struct buffer_head *descriptor;
int sz, offset;
journal_header_t *header;
if (is_journal_aborted(journal))
return;
descriptor = *descriptorp;
offset = *offsetp;
if (jbd2_journal_has_csum_v2or3(journal))
csum_size = sizeof(struct jbd2_journal_revoke_tail);
if (JBD2_HAS_INCOMPAT_FEATURE(journal, JBD2_FEATURE_INCOMPAT_64BIT))
sz = 8;
else
sz = 4;
if (descriptor) {
if (offset + sz > journal->j_blocksize - csum_size) {
flush_descriptor(journal, descriptor, offset, write_op);
descriptor = NULL;
}
}
if (!descriptor) {
descriptor = jbd2_journal_get_descriptor_buffer(journal);
if (!descriptor)
return;
header = (journal_header_t *)descriptor->b_data;
header->h_magic = cpu_to_be32(JBD2_MAGIC_NUMBER);
header->h_blocktype = cpu_to_be32(JBD2_REVOKE_BLOCK);
header->h_sequence = cpu_to_be32(transaction->t_tid);
BUFFER_TRACE(descriptor, "file in log_bufs");
jbd2_file_log_bh(log_bufs, descriptor);
offset = sizeof(jbd2_journal_revoke_header_t);
*descriptorp = descriptor;
}
if (JBD2_HAS_INCOMPAT_FEATURE(journal, JBD2_FEATURE_INCOMPAT_64BIT))
* ((__be64 *)(&descriptor->b_data[offset])) =
cpu_to_be64(record->blocknr);
else
* ((__be32 *)(&descriptor->b_data[offset])) =
cpu_to_be32(record->blocknr);
offset += sz;
*offsetp = offset;
}
static void jbd2_revoke_csum_set(journal_t *j, struct buffer_head *bh)
{
struct jbd2_journal_revoke_tail *tail;
__u32 csum;
if (!jbd2_journal_has_csum_v2or3(j))
return;
tail = (struct jbd2_journal_revoke_tail *)(bh->b_data + j->j_blocksize -
sizeof(struct jbd2_journal_revoke_tail));
tail->r_checksum = 0;
csum = jbd2_chksum(j, j->j_csum_seed, bh->b_data, j->j_blocksize);
tail->r_checksum = cpu_to_be32(csum);
}
static void flush_descriptor(journal_t *journal,
struct buffer_head *descriptor,
int offset, int write_op)
{
jbd2_journal_revoke_header_t *header;
if (is_journal_aborted(journal)) {
put_bh(descriptor);
return;
}
header = (jbd2_journal_revoke_header_t *)descriptor->b_data;
header->r_count = cpu_to_be32(offset);
jbd2_revoke_csum_set(journal, descriptor);
set_buffer_jwrite(descriptor);
BUFFER_TRACE(descriptor, "write");
set_buffer_dirty(descriptor);
write_dirty_buffer(descriptor, write_op);
}
int jbd2_journal_set_revoke(journal_t *journal,
unsigned long long blocknr,
tid_t sequence)
{
struct jbd2_revoke_record_s *record;
record = find_revoke_record(journal, blocknr);
if (record) {
if (tid_gt(sequence, record->sequence))
record->sequence = sequence;
return 0;
}
return insert_revoke_hash(journal, blocknr, sequence);
}
int jbd2_journal_test_revoke(journal_t *journal,
unsigned long long blocknr,
tid_t sequence)
{
struct jbd2_revoke_record_s *record;
record = find_revoke_record(journal, blocknr);
if (!record)
return 0;
if (tid_gt(sequence, record->sequence))
return 0;
return 1;
}
void jbd2_journal_clear_revoke(journal_t *journal)
{
int i;
struct list_head *hash_list;
struct jbd2_revoke_record_s *record;
struct jbd2_revoke_table_s *revoke;
revoke = journal->j_revoke;
for (i = 0; i < revoke->hash_size; i++) {
hash_list = &revoke->hash_table[i];
while (!list_empty(hash_list)) {
record = (struct jbd2_revoke_record_s*) hash_list->next;
list_del(&record->hash);
kmem_cache_free(jbd2_revoke_record_cache, record);
}
}
}
