void i915_syncmap_init(struct i915_syncmap **root)
{
BUILD_BUG_ON_NOT_POWER_OF_2(KSYNCMAP);
BUILD_BUG_ON_NOT_POWER_OF_2(SHIFT);
BUILD_BUG_ON(KSYNCMAP > BITS_PER_BYTE * sizeof((*root)->bitmap));
*root = NULL;
}
static inline u32 *__sync_seqno(struct i915_syncmap *p)
{
GEM_BUG_ON(p->height);
return (u32 *)(p + 1);
}
static inline struct i915_syncmap **__sync_child(struct i915_syncmap *p)
{
GEM_BUG_ON(!p->height);
return (struct i915_syncmap **)(p + 1);
}
static inline unsigned int
__sync_branch_idx(const struct i915_syncmap *p, u64 id)
{
return (id >> p->height) & MASK;
}
static inline unsigned int
__sync_leaf_idx(const struct i915_syncmap *p, u64 id)
{
GEM_BUG_ON(p->height);
return id & MASK;
}
static inline u64 __sync_branch_prefix(const struct i915_syncmap *p, u64 id)
{
return id >> p->height >> SHIFT;
}
static inline u64 __sync_leaf_prefix(const struct i915_syncmap *p, u64 id)
{
GEM_BUG_ON(p->height);
return id >> SHIFT;
}
static inline bool seqno_later(u32 a, u32 b)
{
return (s32)(a - b) >= 0;
}
bool i915_syncmap_is_later(struct i915_syncmap **root, u64 id, u32 seqno)
{
struct i915_syncmap *p;
unsigned int idx;
p = *root;
if (!p)
return false;
if (likely(__sync_leaf_prefix(p, id) == p->prefix))
goto found;
do {
p = p->parent;
if (!p)
return false;
if (__sync_branch_prefix(p, id) == p->prefix)
break;
} while (1);
do {
if (!p->height)
break;
p = __sync_child(p)[__sync_branch_idx(p, id)];
if (!p)
return false;
if (__sync_branch_prefix(p, id) != p->prefix)
return false;
} while (1);
*root = p;
found:
idx = __sync_leaf_idx(p, id);
if (!(p->bitmap & BIT(idx)))
return false;
return seqno_later(__sync_seqno(p)[idx], seqno);
}
static struct i915_syncmap *
__sync_alloc_leaf(struct i915_syncmap *parent, u64 id)
{
struct i915_syncmap *p;
p = kmalloc(sizeof(*p) + KSYNCMAP * sizeof(u32), GFP_KERNEL);
if (unlikely(!p))
return NULL;
p->parent = parent;
p->height = 0;
p->bitmap = 0;
p->prefix = __sync_leaf_prefix(p, id);
return p;
}
static inline void __sync_set_seqno(struct i915_syncmap *p, u64 id, u32 seqno)
{
unsigned int idx = __sync_leaf_idx(p, id);
p->bitmap |= BIT(idx);
__sync_seqno(p)[idx] = seqno;
}
static inline void __sync_set_child(struct i915_syncmap *p,
unsigned int idx,
struct i915_syncmap *child)
{
p->bitmap |= BIT(idx);
__sync_child(p)[idx] = child;
}
static noinline int __sync_set(struct i915_syncmap **root, u64 id, u32 seqno)
{
struct i915_syncmap *p = *root;
unsigned int idx;
if (!p) {
p = __sync_alloc_leaf(NULL, id);
if (unlikely(!p))
return -ENOMEM;
goto found;
}
GEM_BUG_ON(__sync_leaf_prefix(p, id) == p->prefix);
do {
if (!p->parent)
break;
p = p->parent;
if (__sync_branch_prefix(p, id) == p->prefix)
break;
} while (1);
do {
struct i915_syncmap *next;
if (__sync_branch_prefix(p, id) != p->prefix) {
unsigned int above;
next = kzalloc(sizeof(*next) + KSYNCMAP * sizeof(next),
GFP_KERNEL);
if (unlikely(!next))
return -ENOMEM;
above = fls64(__sync_branch_prefix(p, id) ^ p->prefix);
above = round_up(above, SHIFT);
next->height = above + p->height;
next->prefix = __sync_branch_prefix(next, id);
if (p->parent) {
idx = __sync_branch_idx(p->parent, id);
__sync_child(p->parent)[idx] = next;
GEM_BUG_ON(!(p->parent->bitmap & BIT(idx)));
}
next->parent = p->parent;
idx = p->prefix >> (above - SHIFT) & MASK;
__sync_set_child(next, idx, p);
p->parent = next;
p = next;
} else {
if (!p->height)
break;
}
GEM_BUG_ON(!p->height);
idx = __sync_branch_idx(p, id);
next = __sync_child(p)[idx];
if (!next) {
next = __sync_alloc_leaf(p, id);
if (unlikely(!next))
return -ENOMEM;
__sync_set_child(p, idx, next);
p = next;
break;
}
p = next;
} while (1);
found:
GEM_BUG_ON(p->prefix != __sync_leaf_prefix(p, id));
__sync_set_seqno(p, id, seqno);
*root = p;
return 0;
}
int i915_syncmap_set(struct i915_syncmap **root, u64 id, u32 seqno)
{
struct i915_syncmap *p = *root;
if (likely(p && __sync_leaf_prefix(p, id) == p->prefix)) {
__sync_set_seqno(p, id, seqno);
return 0;
}
return __sync_set(root, id, seqno);
}
static void __sync_free(struct i915_syncmap *p)
{
if (p->height) {
unsigned int i;
while ((i = ffs(p->bitmap))) {
p->bitmap &= ~0u << i;
__sync_free(__sync_child(p)[i - 1]);
}
}
kfree(p);
}
void i915_syncmap_free(struct i915_syncmap **root)
{
struct i915_syncmap *p;
p = *root;
if (!p)
return;
while (p->parent)
p = p->parent;
__sync_free(p);
*root = NULL;
}
