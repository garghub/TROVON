static inline bool keyring_ptr_is_keyring(const struct assoc_array_ptr *x)
{
return (unsigned long)x & KEYRING_PTR_SUBTYPE;
}
static inline struct key *keyring_ptr_to_key(const struct assoc_array_ptr *x)
{
void *object = assoc_array_ptr_to_leaf(x);
return (struct key *)((unsigned long)object & ~KEYRING_PTR_SUBTYPE);
}
static inline void *keyring_key_to_ptr(struct key *key)
{
if (key->type == &key_type_keyring)
return (void *)((unsigned long)key | KEYRING_PTR_SUBTYPE);
return key;
}
static inline unsigned keyring_hash(const char *desc)
{
unsigned bucket = 0;
for (; *desc; desc++)
bucket += (unsigned char)*desc;
return bucket & (KEYRING_NAME_HASH_SIZE - 1);
}
static void keyring_publish_name(struct key *keyring)
{
int bucket;
if (keyring->description) {
bucket = keyring_hash(keyring->description);
write_lock(&keyring_name_lock);
if (!keyring_name_hash[bucket].next)
INIT_LIST_HEAD(&keyring_name_hash[bucket]);
list_add_tail(&keyring->type_data.link,
&keyring_name_hash[bucket]);
write_unlock(&keyring_name_lock);
}
}
static int keyring_instantiate(struct key *keyring,
struct key_preparsed_payload *prep)
{
int ret;
ret = -EINVAL;
if (prep->datalen == 0) {
assoc_array_init(&keyring->keys);
keyring_publish_name(keyring);
ret = 0;
}
return ret;
}
static u64 mult_64x32_and_fold(u64 x, u32 y)
{
u64 hi = (u64)(u32)(x >> 32) * y;
u64 lo = (u64)(u32)(x) * y;
return lo + ((u64)(u32)hi << 32) + (u32)(hi >> 32);
}
static unsigned long hash_key_type_and_desc(const struct keyring_index_key *index_key)
{
const unsigned level_shift = ASSOC_ARRAY_LEVEL_STEP;
const unsigned long fan_mask = ASSOC_ARRAY_FAN_MASK;
const char *description = index_key->description;
unsigned long hash, type;
u32 piece;
u64 acc;
int n, desc_len = index_key->desc_len;
type = (unsigned long)index_key->type;
acc = mult_64x32_and_fold(type, desc_len + 13);
acc = mult_64x32_and_fold(acc, 9207);
for (;;) {
n = desc_len;
if (n <= 0)
break;
if (n > 4)
n = 4;
piece = 0;
memcpy(&piece, description, n);
description += n;
desc_len -= n;
acc = mult_64x32_and_fold(acc, piece);
acc = mult_64x32_and_fold(acc, 9207);
}
hash = acc;
if (ASSOC_ARRAY_KEY_CHUNK_SIZE == 32)
hash ^= acc >> 32;
if (index_key->type != &key_type_keyring && (hash & fan_mask) == 0)
return hash | (hash >> (ASSOC_ARRAY_KEY_CHUNK_SIZE - level_shift)) | 1;
if (index_key->type == &key_type_keyring && (hash & fan_mask) != 0)
return (hash + (hash << level_shift)) & ~fan_mask;
return hash;
}
static unsigned long keyring_get_key_chunk(const void *data, int level)
{
const struct keyring_index_key *index_key = data;
unsigned long chunk = 0;
long offset = 0;
int desc_len = index_key->desc_len, n = sizeof(chunk);
level /= ASSOC_ARRAY_KEY_CHUNK_SIZE;
switch (level) {
case 0:
return hash_key_type_and_desc(index_key);
case 1:
return ((unsigned long)index_key->type << 8) | desc_len;
case 2:
if (desc_len == 0)
return (u8)((unsigned long)index_key->type >>
(ASSOC_ARRAY_KEY_CHUNK_SIZE - 8));
n--;
offset = 1;
default:
offset += sizeof(chunk) - 1;
offset += (level - 3) * sizeof(chunk);
if (offset >= desc_len)
return 0;
desc_len -= offset;
if (desc_len > n)
desc_len = n;
offset += desc_len;
do {
chunk <<= 8;
chunk |= ((u8*)index_key->description)[--offset];
} while (--desc_len > 0);
if (level == 2) {
chunk <<= 8;
chunk |= (u8)((unsigned long)index_key->type >>
(ASSOC_ARRAY_KEY_CHUNK_SIZE - 8));
}
return chunk;
}
}
static unsigned long keyring_get_object_key_chunk(const void *object, int level)
{
const struct key *key = keyring_ptr_to_key(object);
return keyring_get_key_chunk(&key->index_key, level);
}
static bool keyring_compare_object(const void *object, const void *data)
{
const struct keyring_index_key *index_key = data;
const struct key *key = keyring_ptr_to_key(object);
return key->index_key.type == index_key->type &&
key->index_key.desc_len == index_key->desc_len &&
memcmp(key->index_key.description, index_key->description,
index_key->desc_len) == 0;
}
static int keyring_diff_objects(const void *object, const void *data)
{
const struct key *key_a = keyring_ptr_to_key(object);
const struct keyring_index_key *a = &key_a->index_key;
const struct keyring_index_key *b = data;
unsigned long seg_a, seg_b;
int level, i;
level = 0;
seg_a = hash_key_type_and_desc(a);
seg_b = hash_key_type_and_desc(b);
if ((seg_a ^ seg_b) != 0)
goto differ;
level += ASSOC_ARRAY_KEY_CHUNK_SIZE / 8;
seg_a = a->desc_len;
seg_b = b->desc_len;
if ((seg_a ^ seg_b) != 0)
goto differ;
level++;
seg_a = (unsigned long)a->type;
seg_b = (unsigned long)b->type;
if ((seg_a ^ seg_b) != 0)
goto differ;
level += sizeof(unsigned long);
if (a->desc_len == 0)
goto same;
i = 0;
if (((unsigned long)a->description | (unsigned long)b->description) &
(sizeof(unsigned long) - 1)) {
do {
seg_a = *(unsigned long *)(a->description + i);
seg_b = *(unsigned long *)(b->description + i);
if ((seg_a ^ seg_b) != 0)
goto differ_plus_i;
i += sizeof(unsigned long);
} while (i < (a->desc_len & (sizeof(unsigned long) - 1)));
}
for (; i < a->desc_len; i++) {
seg_a = *(unsigned char *)(a->description + i);
seg_b = *(unsigned char *)(b->description + i);
if ((seg_a ^ seg_b) != 0)
goto differ_plus_i;
}
same:
return -1;
differ_plus_i:
level += i;
differ:
i = level * 8 + __ffs(seg_a ^ seg_b);
return i;
}
static void keyring_free_object(void *object)
{
key_put(keyring_ptr_to_key(object));
}
static void keyring_destroy(struct key *keyring)
{
if (keyring->description) {
write_lock(&keyring_name_lock);
if (keyring->type_data.link.next != NULL &&
!list_empty(&keyring->type_data.link))
list_del(&keyring->type_data.link);
write_unlock(&keyring_name_lock);
}
assoc_array_destroy(&keyring->keys, &keyring_assoc_array_ops);
}
static void keyring_describe(const struct key *keyring, struct seq_file *m)
{
if (keyring->description)
seq_puts(m, keyring->description);
else
seq_puts(m, "[anon]");
if (key_is_instantiated(keyring)) {
if (keyring->keys.nr_leaves_on_tree != 0)
seq_printf(m, ": %lu", keyring->keys.nr_leaves_on_tree);
else
seq_puts(m, ": empty");
}
}
static int keyring_read_iterator(const void *object, void *data)
{
struct keyring_read_iterator_context *ctx = data;
const struct key *key = keyring_ptr_to_key(object);
int ret;
kenter("{%s,%d},,{%zu/%zu}",
key->type->name, key->serial, ctx->count, ctx->qty);
if (ctx->count >= ctx->qty)
return 1;
ret = put_user(key->serial, ctx->buffer);
if (ret < 0)
return ret;
ctx->buffer++;
ctx->count += sizeof(key->serial);
return 0;
}
static long keyring_read(const struct key *keyring,
char __user *buffer, size_t buflen)
{
struct keyring_read_iterator_context ctx;
unsigned long nr_keys;
int ret;
kenter("{%d},,%zu", key_serial(keyring), buflen);
if (buflen & (sizeof(key_serial_t) - 1))
return -EINVAL;
nr_keys = keyring->keys.nr_leaves_on_tree;
if (nr_keys == 0)
return 0;
ctx.qty = nr_keys * sizeof(key_serial_t);
if (!buffer || !buflen)
return ctx.qty;
if (buflen > ctx.qty)
ctx.qty = buflen;
ctx.buffer = (key_serial_t __user *)buffer;
ctx.count = 0;
ret = assoc_array_iterate(&keyring->keys, keyring_read_iterator, &ctx);
if (ret < 0) {
kleave(" = %d [iterate]", ret);
return ret;
}
kleave(" = %zu [ok]", ctx.count);
return ctx.count;
}
struct key *keyring_alloc(const char *description, kuid_t uid, kgid_t gid,
const struct cred *cred, key_perm_t perm,
unsigned long flags, struct key *dest)
{
struct key *keyring;
int ret;
keyring = key_alloc(&key_type_keyring, description,
uid, gid, cred, perm, flags);
if (!IS_ERR(keyring)) {
ret = key_instantiate_and_link(keyring, NULL, 0, dest, NULL);
if (ret < 0) {
key_put(keyring);
keyring = ERR_PTR(ret);
}
}
return keyring;
}
static int keyring_search_iterator(const void *object, void *iterator_data)
{
struct keyring_search_context *ctx = iterator_data;
const struct key *key = keyring_ptr_to_key(object);
unsigned long kflags = key->flags;
kenter("{%d}", key->serial);
if (key->type != ctx->index_key.type) {
kleave(" = 0 [!type]");
return 0;
}
if (ctx->flags & KEYRING_SEARCH_DO_STATE_CHECK) {
if (kflags & ((1 << KEY_FLAG_INVALIDATED) |
(1 << KEY_FLAG_REVOKED))) {
ctx->result = ERR_PTR(-EKEYREVOKED);
kleave(" = %d [invrev]", ctx->skipped_ret);
goto skipped;
}
if (key->expiry && ctx->now.tv_sec >= key->expiry) {
ctx->result = ERR_PTR(-EKEYEXPIRED);
kleave(" = %d [expire]", ctx->skipped_ret);
goto skipped;
}
}
if (!ctx->match(key, ctx->match_data)) {
kleave(" = 0 [!match]");
return 0;
}
if (!(ctx->flags & KEYRING_SEARCH_NO_CHECK_PERM) &&
key_task_permission(make_key_ref(key, ctx->possessed),
ctx->cred, KEY_SEARCH) < 0) {
ctx->result = ERR_PTR(-EACCES);
kleave(" = %d [!perm]", ctx->skipped_ret);
goto skipped;
}
if (ctx->flags & KEYRING_SEARCH_DO_STATE_CHECK) {
if (kflags & (1 << KEY_FLAG_NEGATIVE)) {
smp_rmb();
ctx->result = ERR_PTR(key->type_data.reject_error);
kleave(" = %d [neg]", ctx->skipped_ret);
goto skipped;
}
}
ctx->result = make_key_ref(key, ctx->possessed);
kleave(" = 1 [found]");
return 1;
skipped:
return ctx->skipped_ret;
}
static int search_keyring(struct key *keyring, struct keyring_search_context *ctx)
{
if ((ctx->flags & KEYRING_SEARCH_LOOKUP_TYPE) ==
KEYRING_SEARCH_LOOKUP_DIRECT) {
const void *object;
object = assoc_array_find(&keyring->keys,
&keyring_assoc_array_ops,
&ctx->index_key);
return object ? ctx->iterator(object, ctx) : 0;
}
return assoc_array_iterate(&keyring->keys, ctx->iterator, ctx);
}
static bool search_nested_keyrings(struct key *keyring,
struct keyring_search_context *ctx)
{
struct {
struct key *keyring;
struct assoc_array_node *node;
int slot;
} stack[KEYRING_SEARCH_MAX_DEPTH];
struct assoc_array_shortcut *shortcut;
struct assoc_array_node *node;
struct assoc_array_ptr *ptr;
struct key *key;
int sp = 0, slot;
kenter("{%d},{%s,%s}",
keyring->serial,
ctx->index_key.type->name,
ctx->index_key.description);
if (ctx->index_key.description)
ctx->index_key.desc_len = strlen(ctx->index_key.description);
if (ctx->flags & KEYRING_SEARCH_LOOKUP_ITERATE ||
keyring_compare_object(keyring, &ctx->index_key)) {
ctx->skipped_ret = 2;
ctx->flags |= KEYRING_SEARCH_DO_STATE_CHECK;
switch (ctx->iterator(keyring_key_to_ptr(keyring), ctx)) {
case 1:
goto found;
case 2:
return false;
default:
break;
}
}
ctx->skipped_ret = 0;
if (ctx->flags & KEYRING_SEARCH_NO_STATE_CHECK)
ctx->flags &= ~KEYRING_SEARCH_DO_STATE_CHECK;
descend_to_keyring:
kdebug("descend to %d", keyring->serial);
if (keyring->flags & ((1 << KEY_FLAG_INVALIDATED) |
(1 << KEY_FLAG_REVOKED)))
goto not_this_keyring;
if (search_keyring(keyring, ctx))
goto found;
ptr = ACCESS_ONCE(keyring->keys.root);
if (!ptr)
goto not_this_keyring;
if (assoc_array_ptr_is_shortcut(ptr)) {
shortcut = assoc_array_ptr_to_shortcut(ptr);
smp_read_barrier_depends();
if ((shortcut->index_key[0] & ASSOC_ARRAY_FAN_MASK) != 0)
goto not_this_keyring;
ptr = ACCESS_ONCE(shortcut->next_node);
node = assoc_array_ptr_to_node(ptr);
goto begin_node;
}
node = assoc_array_ptr_to_node(ptr);
smp_read_barrier_depends();
ptr = node->slots[0];
if (!assoc_array_ptr_is_meta(ptr))
goto begin_node;
descend_to_node:
kdebug("descend");
if (assoc_array_ptr_is_shortcut(ptr)) {
shortcut = assoc_array_ptr_to_shortcut(ptr);
smp_read_barrier_depends();
ptr = ACCESS_ONCE(shortcut->next_node);
BUG_ON(!assoc_array_ptr_is_node(ptr));
}
node = assoc_array_ptr_to_node(ptr);
begin_node:
kdebug("begin_node");
smp_read_barrier_depends();
slot = 0;
ascend_to_node:
for (; slot < ASSOC_ARRAY_FAN_OUT; slot++) {
ptr = ACCESS_ONCE(node->slots[slot]);
if (assoc_array_ptr_is_meta(ptr) && node->back_pointer)
goto descend_to_node;
if (!keyring_ptr_is_keyring(ptr))
continue;
key = keyring_ptr_to_key(ptr);
if (sp >= KEYRING_SEARCH_MAX_DEPTH) {
if (ctx->flags & KEYRING_SEARCH_DETECT_TOO_DEEP) {
ctx->result = ERR_PTR(-ELOOP);
return false;
}
goto not_this_keyring;
}
if (!(ctx->flags & KEYRING_SEARCH_NO_CHECK_PERM) &&
key_task_permission(make_key_ref(key, ctx->possessed),
ctx->cred, KEY_SEARCH) < 0)
continue;
stack[sp].keyring = keyring;
stack[sp].node = node;
stack[sp].slot = slot;
sp++;
keyring = key;
goto descend_to_keyring;
}
ptr = ACCESS_ONCE(node->back_pointer);
slot = node->parent_slot;
if (ptr && assoc_array_ptr_is_shortcut(ptr)) {
shortcut = assoc_array_ptr_to_shortcut(ptr);
smp_read_barrier_depends();
ptr = ACCESS_ONCE(shortcut->back_pointer);
slot = shortcut->parent_slot;
}
if (!ptr)
goto not_this_keyring;
node = assoc_array_ptr_to_node(ptr);
smp_read_barrier_depends();
slot++;
if (node->back_pointer) {
kdebug("ascend %d", slot);
goto ascend_to_node;
}
not_this_keyring:
kdebug("not_this_keyring %d", sp);
if (sp <= 0) {
kleave(" = false");
return false;
}
sp--;
keyring = stack[sp].keyring;
node = stack[sp].node;
slot = stack[sp].slot + 1;
kdebug("ascend to %d [%d]", keyring->serial, slot);
goto ascend_to_node;
found:
key = key_ref_to_ptr(ctx->result);
key_check(key);
if (!(ctx->flags & KEYRING_SEARCH_NO_UPDATE_TIME)) {
key->last_used_at = ctx->now.tv_sec;
keyring->last_used_at = ctx->now.tv_sec;
while (sp > 0)
stack[--sp].keyring->last_used_at = ctx->now.tv_sec;
}
kleave(" = true");
return true;
}
key_ref_t keyring_search_aux(key_ref_t keyring_ref,
struct keyring_search_context *ctx)
{
struct key *keyring;
long err;
ctx->iterator = keyring_search_iterator;
ctx->possessed = is_key_possessed(keyring_ref);
ctx->result = ERR_PTR(-EAGAIN);
keyring = key_ref_to_ptr(keyring_ref);
key_check(keyring);
if (keyring->type != &key_type_keyring)
return ERR_PTR(-ENOTDIR);
if (!(ctx->flags & KEYRING_SEARCH_NO_CHECK_PERM)) {
err = key_task_permission(keyring_ref, ctx->cred, KEY_SEARCH);
if (err < 0)
return ERR_PTR(err);
}
rcu_read_lock();
ctx->now = current_kernel_time();
if (search_nested_keyrings(keyring, ctx))
__key_get(key_ref_to_ptr(ctx->result));
rcu_read_unlock();
return ctx->result;
}
key_ref_t keyring_search(key_ref_t keyring,
struct key_type *type,
const char *description)
{
struct keyring_search_context ctx = {
.index_key.type = type,
.index_key.description = description,
.cred = current_cred(),
.match = type->match,
.match_data = description,
.flags = (type->def_lookup_type |
KEYRING_SEARCH_DO_STATE_CHECK),
};
if (!ctx.match)
return ERR_PTR(-ENOKEY);
return keyring_search_aux(keyring, &ctx);
}
key_ref_t find_key_to_update(key_ref_t keyring_ref,
const struct keyring_index_key *index_key)
{
struct key *keyring, *key;
const void *object;
keyring = key_ref_to_ptr(keyring_ref);
kenter("{%d},{%s,%s}",
keyring->serial, index_key->type->name, index_key->description);
object = assoc_array_find(&keyring->keys, &keyring_assoc_array_ops,
index_key);
if (object)
goto found;
kleave(" = NULL");
return NULL;
found:
key = keyring_ptr_to_key(object);
if (key->flags & ((1 << KEY_FLAG_INVALIDATED) |
(1 << KEY_FLAG_REVOKED))) {
kleave(" = NULL [x]");
return NULL;
}
__key_get(key);
kleave(" = {%d}", key->serial);
return make_key_ref(key, is_key_possessed(keyring_ref));
}
struct key *find_keyring_by_name(const char *name, bool skip_perm_check)
{
struct key *keyring;
int bucket;
if (!name)
return ERR_PTR(-EINVAL);
bucket = keyring_hash(name);
read_lock(&keyring_name_lock);
if (keyring_name_hash[bucket].next) {
list_for_each_entry(keyring,
&keyring_name_hash[bucket],
type_data.link
) {
if (!kuid_has_mapping(current_user_ns(), keyring->user->uid))
continue;
if (test_bit(KEY_FLAG_REVOKED, &keyring->flags))
continue;
if (strcmp(keyring->description, name) != 0)
continue;
if (!skip_perm_check &&
key_permission(make_key_ref(keyring, 0),
KEY_SEARCH) < 0)
continue;
if (!atomic_inc_not_zero(&keyring->usage))
continue;
keyring->last_used_at = current_kernel_time().tv_sec;
goto out;
}
}
keyring = ERR_PTR(-ENOKEY);
out:
read_unlock(&keyring_name_lock);
return keyring;
}
static int keyring_detect_cycle_iterator(const void *object,
void *iterator_data)
{
struct keyring_search_context *ctx = iterator_data;
const struct key *key = keyring_ptr_to_key(object);
kenter("{%d}", key->serial);
BUG_ON(key != ctx->match_data);
ctx->result = ERR_PTR(-EDEADLK);
return 1;
}
static int keyring_detect_cycle(struct key *A, struct key *B)
{
struct keyring_search_context ctx = {
.index_key = A->index_key,
.match_data = A,
.iterator = keyring_detect_cycle_iterator,
.flags = (KEYRING_SEARCH_LOOKUP_DIRECT |
KEYRING_SEARCH_NO_STATE_CHECK |
KEYRING_SEARCH_NO_UPDATE_TIME |
KEYRING_SEARCH_NO_CHECK_PERM |
KEYRING_SEARCH_DETECT_TOO_DEEP),
};
rcu_read_lock();
search_nested_keyrings(B, &ctx);
rcu_read_unlock();
return PTR_ERR(ctx.result) == -EAGAIN ? 0 : PTR_ERR(ctx.result);
}
int __key_link_begin(struct key *keyring,
const struct keyring_index_key *index_key,
struct assoc_array_edit **_edit)
__acquires(&keyring->sem
int __key_link_check_live_key(struct key *keyring, struct key *key)
{
if (key->type == &key_type_keyring)
return keyring_detect_cycle(keyring, key);
return 0;
}
void __key_link(struct key *key, struct assoc_array_edit **_edit)
{
__key_get(key);
assoc_array_insert_set_object(*_edit, keyring_key_to_ptr(key));
assoc_array_apply_edit(*_edit);
*_edit = NULL;
}
void __key_link_end(struct key *keyring,
const struct keyring_index_key *index_key,
struct assoc_array_edit *edit)
__releases(&keyring->sem
int key_link(struct key *keyring, struct key *key)
{
struct assoc_array_edit *edit;
int ret;
kenter("{%d,%d}", keyring->serial, atomic_read(&keyring->usage));
key_check(keyring);
key_check(key);
if (test_bit(KEY_FLAG_TRUSTED_ONLY, &keyring->flags) &&
!test_bit(KEY_FLAG_TRUSTED, &key->flags))
return -EPERM;
ret = __key_link_begin(keyring, &key->index_key, &edit);
if (ret == 0) {
kdebug("begun {%d,%d}", keyring->serial, atomic_read(&keyring->usage));
ret = __key_link_check_live_key(keyring, key);
if (ret == 0)
__key_link(key, &edit);
__key_link_end(keyring, &key->index_key, edit);
}
kleave(" = %d {%d,%d}", ret, keyring->serial, atomic_read(&keyring->usage));
return ret;
}
int key_unlink(struct key *keyring, struct key *key)
{
struct assoc_array_edit *edit;
int ret;
key_check(keyring);
key_check(key);
if (keyring->type != &key_type_keyring)
return -ENOTDIR;
down_write(&keyring->sem);
edit = assoc_array_delete(&keyring->keys, &keyring_assoc_array_ops,
&key->index_key);
if (IS_ERR(edit)) {
ret = PTR_ERR(edit);
goto error;
}
ret = -ENOENT;
if (edit == NULL)
goto error;
assoc_array_apply_edit(edit);
key_payload_reserve(keyring, keyring->datalen - KEYQUOTA_LINK_BYTES);
ret = 0;
error:
up_write(&keyring->sem);
return ret;
}
int keyring_clear(struct key *keyring)
{
struct assoc_array_edit *edit;
int ret;
if (keyring->type != &key_type_keyring)
return -ENOTDIR;
down_write(&keyring->sem);
edit = assoc_array_clear(&keyring->keys, &keyring_assoc_array_ops);
if (IS_ERR(edit)) {
ret = PTR_ERR(edit);
} else {
if (edit)
assoc_array_apply_edit(edit);
key_payload_reserve(keyring, 0);
ret = 0;
}
up_write(&keyring->sem);
return ret;
}
static void keyring_revoke(struct key *keyring)
{
struct assoc_array_edit *edit;
edit = assoc_array_clear(&keyring->keys, &keyring_assoc_array_ops);
if (!IS_ERR(edit)) {
if (edit)
assoc_array_apply_edit(edit);
key_payload_reserve(keyring, 0);
}
}
static bool keyring_gc_select_iterator(void *object, void *iterator_data)
{
struct key *key = keyring_ptr_to_key(object);
time_t *limit = iterator_data;
if (key_is_dead(key, *limit))
return false;
key_get(key);
return true;
}
static int keyring_gc_check_iterator(const void *object, void *iterator_data)
{
const struct key *key = keyring_ptr_to_key(object);
time_t *limit = iterator_data;
key_check(key);
return key_is_dead(key, *limit);
}
void keyring_gc(struct key *keyring, time_t limit)
{
int result;
kenter("%x{%s}", keyring->serial, keyring->description ?: "");
if (keyring->flags & ((1 << KEY_FLAG_INVALIDATED) |
(1 << KEY_FLAG_REVOKED)))
goto dont_gc;
rcu_read_lock();
result = assoc_array_iterate(&keyring->keys,
keyring_gc_check_iterator, &limit);
rcu_read_unlock();
if (result == true)
goto do_gc;
dont_gc:
kleave(" [no gc]");
return;
do_gc:
down_write(&keyring->sem);
assoc_array_gc(&keyring->keys, &keyring_assoc_array_ops,
keyring_gc_select_iterator, &limit);
up_write(&keyring->sem);
kleave(" [gc]");
}
