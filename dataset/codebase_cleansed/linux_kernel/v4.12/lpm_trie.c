static inline int extract_bit(const u8 *data, size_t index)
{
return !!(data[index / 8] & (1 << (7 - (index % 8))));
}
static size_t longest_prefix_match(const struct lpm_trie *trie,
const struct lpm_trie_node *node,
const struct bpf_lpm_trie_key *key)
{
size_t prefixlen = 0;
size_t i;
for (i = 0; i < trie->data_size; i++) {
size_t b;
b = 8 - fls(node->data[i] ^ key->data[i]);
prefixlen += b;
if (prefixlen >= node->prefixlen || prefixlen >= key->prefixlen)
return min(node->prefixlen, key->prefixlen);
if (b < 8)
break;
}
return prefixlen;
}
static void *trie_lookup_elem(struct bpf_map *map, void *_key)
{
struct lpm_trie *trie = container_of(map, struct lpm_trie, map);
struct lpm_trie_node *node, *found = NULL;
struct bpf_lpm_trie_key *key = _key;
for (node = rcu_dereference(trie->root); node;) {
unsigned int next_bit;
size_t matchlen;
matchlen = longest_prefix_match(trie, node, key);
if (matchlen == trie->max_prefixlen) {
found = node;
break;
}
if (matchlen < node->prefixlen)
break;
if (!(node->flags & LPM_TREE_NODE_FLAG_IM))
found = node;
next_bit = extract_bit(key->data, node->prefixlen);
node = rcu_dereference(node->child[next_bit]);
}
if (!found)
return NULL;
return found->data + trie->data_size;
}
static struct lpm_trie_node *lpm_trie_node_alloc(const struct lpm_trie *trie,
const void *value)
{
struct lpm_trie_node *node;
size_t size = sizeof(struct lpm_trie_node) + trie->data_size;
if (value)
size += trie->map.value_size;
node = kmalloc(size, GFP_ATOMIC | __GFP_NOWARN);
if (!node)
return NULL;
node->flags = 0;
if (value)
memcpy(node->data + trie->data_size, value,
trie->map.value_size);
return node;
}
static int trie_update_elem(struct bpf_map *map,
void *_key, void *value, u64 flags)
{
struct lpm_trie *trie = container_of(map, struct lpm_trie, map);
struct lpm_trie_node *node, *im_node = NULL, *new_node = NULL;
struct lpm_trie_node __rcu **slot;
struct bpf_lpm_trie_key *key = _key;
unsigned long irq_flags;
unsigned int next_bit;
size_t matchlen = 0;
int ret = 0;
if (unlikely(flags > BPF_EXIST))
return -EINVAL;
if (key->prefixlen > trie->max_prefixlen)
return -EINVAL;
raw_spin_lock_irqsave(&trie->lock, irq_flags);
if (trie->n_entries == trie->map.max_entries) {
ret = -ENOSPC;
goto out;
}
new_node = lpm_trie_node_alloc(trie, value);
if (!new_node) {
ret = -ENOMEM;
goto out;
}
trie->n_entries++;
new_node->prefixlen = key->prefixlen;
RCU_INIT_POINTER(new_node->child[0], NULL);
RCU_INIT_POINTER(new_node->child[1], NULL);
memcpy(new_node->data, key->data, trie->data_size);
slot = &trie->root;
while ((node = rcu_dereference_protected(*slot,
lockdep_is_held(&trie->lock)))) {
matchlen = longest_prefix_match(trie, node, key);
if (node->prefixlen != matchlen ||
node->prefixlen == key->prefixlen ||
node->prefixlen == trie->max_prefixlen)
break;
next_bit = extract_bit(key->data, node->prefixlen);
slot = &node->child[next_bit];
}
if (!node) {
rcu_assign_pointer(*slot, new_node);
goto out;
}
if (node->prefixlen == matchlen) {
new_node->child[0] = node->child[0];
new_node->child[1] = node->child[1];
if (!(node->flags & LPM_TREE_NODE_FLAG_IM))
trie->n_entries--;
rcu_assign_pointer(*slot, new_node);
kfree_rcu(node, rcu);
goto out;
}
if (matchlen == key->prefixlen) {
next_bit = extract_bit(node->data, matchlen);
rcu_assign_pointer(new_node->child[next_bit], node);
rcu_assign_pointer(*slot, new_node);
goto out;
}
im_node = lpm_trie_node_alloc(trie, NULL);
if (!im_node) {
ret = -ENOMEM;
goto out;
}
im_node->prefixlen = matchlen;
im_node->flags |= LPM_TREE_NODE_FLAG_IM;
memcpy(im_node->data, node->data, trie->data_size);
if (extract_bit(key->data, matchlen)) {
rcu_assign_pointer(im_node->child[0], node);
rcu_assign_pointer(im_node->child[1], new_node);
} else {
rcu_assign_pointer(im_node->child[0], new_node);
rcu_assign_pointer(im_node->child[1], node);
}
rcu_assign_pointer(*slot, im_node);
out:
if (ret) {
if (new_node)
trie->n_entries--;
kfree(new_node);
kfree(im_node);
}
raw_spin_unlock_irqrestore(&trie->lock, irq_flags);
return ret;
}
static int trie_delete_elem(struct bpf_map *map, void *key)
{
return -ENOSYS;
}
static struct bpf_map *trie_alloc(union bpf_attr *attr)
{
struct lpm_trie *trie;
u64 cost = sizeof(*trie), cost_per_node;
int ret;
if (!capable(CAP_SYS_ADMIN))
return ERR_PTR(-EPERM);
if (attr->max_entries == 0 ||
attr->map_flags != BPF_F_NO_PREALLOC ||
attr->key_size < LPM_KEY_SIZE_MIN ||
attr->key_size > LPM_KEY_SIZE_MAX ||
attr->value_size < LPM_VAL_SIZE_MIN ||
attr->value_size > LPM_VAL_SIZE_MAX)
return ERR_PTR(-EINVAL);
trie = kzalloc(sizeof(*trie), GFP_USER | __GFP_NOWARN);
if (!trie)
return ERR_PTR(-ENOMEM);
trie->map.map_type = attr->map_type;
trie->map.key_size = attr->key_size;
trie->map.value_size = attr->value_size;
trie->map.max_entries = attr->max_entries;
trie->map.map_flags = attr->map_flags;
trie->data_size = attr->key_size -
offsetof(struct bpf_lpm_trie_key, data);
trie->max_prefixlen = trie->data_size * 8;
cost_per_node = sizeof(struct lpm_trie_node) +
attr->value_size + trie->data_size;
cost += (u64) attr->max_entries * cost_per_node;
if (cost >= U32_MAX - PAGE_SIZE) {
ret = -E2BIG;
goto out_err;
}
trie->map.pages = round_up(cost, PAGE_SIZE) >> PAGE_SHIFT;
ret = bpf_map_precharge_memlock(trie->map.pages);
if (ret)
goto out_err;
raw_spin_lock_init(&trie->lock);
return &trie->map;
out_err:
kfree(trie);
return ERR_PTR(ret);
}
static void trie_free(struct bpf_map *map)
{
struct lpm_trie *trie = container_of(map, struct lpm_trie, map);
struct lpm_trie_node __rcu **slot;
struct lpm_trie_node *node;
raw_spin_lock(&trie->lock);
for (;;) {
slot = &trie->root;
for (;;) {
node = rcu_dereference_protected(*slot,
lockdep_is_held(&trie->lock));
if (!node)
goto unlock;
if (rcu_access_pointer(node->child[0])) {
slot = &node->child[0];
continue;
}
if (rcu_access_pointer(node->child[1])) {
slot = &node->child[1];
continue;
}
kfree(node);
RCU_INIT_POINTER(*slot, NULL);
break;
}
}
unlock:
raw_spin_unlock(&trie->lock);
}
static int trie_get_next_key(struct bpf_map *map, void *key, void *next_key)
{
return -ENOTSUPP;
}
