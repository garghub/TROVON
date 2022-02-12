int tipc_ref_table_init(u32 requested_size, u32 start)
{
struct reference *table;
u32 actual_size;
requested_size++;
for (actual_size = 16; actual_size < requested_size; actual_size <<= 1)
;
table = vzalloc(actual_size * sizeof(struct reference));
if (table == NULL)
return -ENOMEM;
tipc_ref_table.entries = table;
tipc_ref_table.capacity = requested_size;
tipc_ref_table.init_point = 1;
tipc_ref_table.first_free = 0;
tipc_ref_table.last_free = 0;
tipc_ref_table.index_mask = actual_size - 1;
tipc_ref_table.start_mask = start & ~tipc_ref_table.index_mask;
return 0;
}
void tipc_ref_table_stop(void)
{
if (!tipc_ref_table.entries)
return;
vfree(tipc_ref_table.entries);
tipc_ref_table.entries = NULL;
}
u32 tipc_ref_acquire(void *object, spinlock_t **lock)
{
u32 index;
u32 index_mask;
u32 next_plus_upper;
u32 ref;
struct reference *entry = NULL;
if (!object) {
err("Attempt to acquire reference to non-existent object\n");
return 0;
}
if (!tipc_ref_table.entries) {
err("Reference table not found during acquisition attempt\n");
return 0;
}
write_lock_bh(&ref_table_lock);
if (tipc_ref_table.first_free) {
index = tipc_ref_table.first_free;
entry = &(tipc_ref_table.entries[index]);
index_mask = tipc_ref_table.index_mask;
next_plus_upper = entry->ref;
tipc_ref_table.first_free = next_plus_upper & index_mask;
ref = (next_plus_upper & ~index_mask) + index;
} else if (tipc_ref_table.init_point < tipc_ref_table.capacity) {
index = tipc_ref_table.init_point++;
entry = &(tipc_ref_table.entries[index]);
spin_lock_init(&entry->lock);
ref = tipc_ref_table.start_mask + index;
} else {
ref = 0;
}
write_unlock_bh(&ref_table_lock);
if (entry) {
spin_lock_bh(&entry->lock);
entry->ref = ref;
entry->object = object;
*lock = &entry->lock;
}
return ref;
}
void tipc_ref_discard(u32 ref)
{
struct reference *entry;
u32 index;
u32 index_mask;
if (!tipc_ref_table.entries) {
err("Reference table not found during discard attempt\n");
return;
}
index_mask = tipc_ref_table.index_mask;
index = ref & index_mask;
entry = &(tipc_ref_table.entries[index]);
write_lock_bh(&ref_table_lock);
if (!entry->object) {
err("Attempt to discard reference to non-existent object\n");
goto exit;
}
if (entry->ref != ref) {
err("Attempt to discard non-existent reference\n");
goto exit;
}
entry->object = NULL;
entry->ref = (ref & ~index_mask) + (index_mask + 1);
if (tipc_ref_table.first_free == 0)
tipc_ref_table.first_free = index;
else
tipc_ref_table.entries[tipc_ref_table.last_free].ref |= index;
tipc_ref_table.last_free = index;
exit:
write_unlock_bh(&ref_table_lock);
}
void *tipc_ref_lock(u32 ref)
{
if (likely(tipc_ref_table.entries)) {
struct reference *entry;
entry = &tipc_ref_table.entries[ref &
tipc_ref_table.index_mask];
if (likely(entry->ref != 0)) {
spin_lock_bh(&entry->lock);
if (likely((entry->ref == ref) && (entry->object)))
return entry->object;
spin_unlock_bh(&entry->lock);
}
}
return NULL;
}
void *tipc_ref_deref(u32 ref)
{
if (likely(tipc_ref_table.entries)) {
struct reference *entry;
entry = &tipc_ref_table.entries[ref &
tipc_ref_table.index_mask];
if (likely(entry->ref == ref))
return entry->object;
}
return NULL;
}
