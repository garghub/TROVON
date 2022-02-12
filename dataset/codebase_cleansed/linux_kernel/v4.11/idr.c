int idr_alloc(struct idr *idr, void *ptr, int start, int end, gfp_t gfp)
{
void __rcu **slot;
struct radix_tree_iter iter;
if (WARN_ON_ONCE(start < 0))
return -EINVAL;
if (WARN_ON_ONCE(radix_tree_is_internal_node(ptr)))
return -EINVAL;
radix_tree_iter_init(&iter, start);
slot = idr_get_free(&idr->idr_rt, &iter, gfp, end);
if (IS_ERR(slot))
return PTR_ERR(slot);
radix_tree_iter_replace(&idr->idr_rt, &iter, slot, ptr);
radix_tree_iter_tag_clear(&idr->idr_rt, &iter, IDR_FREE);
return iter.index;
}
int idr_alloc_cyclic(struct idr *idr, void *ptr, int start, int end, gfp_t gfp)
{
int id, curr = idr->idr_next;
if (curr < start)
curr = start;
id = idr_alloc(idr, ptr, curr, end, gfp);
if ((id == -ENOSPC) && (curr > start))
id = idr_alloc(idr, ptr, start, curr, gfp);
if (id >= 0)
idr->idr_next = id + 1U;
return id;
}
int idr_for_each(const struct idr *idr,
int (*fn)(int id, void *p, void *data), void *data)
{
struct radix_tree_iter iter;
void __rcu **slot;
radix_tree_for_each_slot(slot, &idr->idr_rt, &iter, 0) {
int ret = fn(iter.index, rcu_dereference_raw(*slot), data);
if (ret)
return ret;
}
return 0;
}
void *idr_get_next(struct idr *idr, int *nextid)
{
struct radix_tree_iter iter;
void __rcu **slot;
slot = radix_tree_iter_find(&idr->idr_rt, &iter, *nextid);
if (!slot)
return NULL;
*nextid = iter.index;
return rcu_dereference_raw(*slot);
}
void *idr_replace(struct idr *idr, void *ptr, int id)
{
struct radix_tree_node *node;
void __rcu **slot = NULL;
void *entry;
if (WARN_ON_ONCE(id < 0))
return ERR_PTR(-EINVAL);
if (WARN_ON_ONCE(radix_tree_is_internal_node(ptr)))
return ERR_PTR(-EINVAL);
entry = __radix_tree_lookup(&idr->idr_rt, id, &node, &slot);
if (!slot || radix_tree_tag_get(&idr->idr_rt, id, IDR_FREE))
return ERR_PTR(-ENOENT);
__radix_tree_replace(&idr->idr_rt, node, slot, ptr, NULL, NULL);
return entry;
}
int ida_get_new_above(struct ida *ida, int start, int *id)
{
struct radix_tree_root *root = &ida->ida_rt;
void __rcu **slot;
struct radix_tree_iter iter;
struct ida_bitmap *bitmap;
unsigned long index;
unsigned bit, ebit;
int new;
index = start / IDA_BITMAP_BITS;
bit = start % IDA_BITMAP_BITS;
ebit = bit + RADIX_TREE_EXCEPTIONAL_SHIFT;
slot = radix_tree_iter_init(&iter, index);
for (;;) {
if (slot)
slot = radix_tree_next_slot(slot, &iter,
RADIX_TREE_ITER_TAGGED);
if (!slot) {
slot = idr_get_free(root, &iter, GFP_NOWAIT, IDA_MAX);
if (IS_ERR(slot)) {
if (slot == ERR_PTR(-ENOMEM))
return -EAGAIN;
return PTR_ERR(slot);
}
}
if (iter.index > index) {
bit = 0;
ebit = RADIX_TREE_EXCEPTIONAL_SHIFT;
}
new = iter.index * IDA_BITMAP_BITS;
bitmap = rcu_dereference_raw(*slot);
if (radix_tree_exception(bitmap)) {
unsigned long tmp = (unsigned long)bitmap;
ebit = find_next_zero_bit(&tmp, BITS_PER_LONG, ebit);
if (ebit < BITS_PER_LONG) {
tmp |= 1UL << ebit;
rcu_assign_pointer(*slot, (void *)tmp);
*id = new + ebit - RADIX_TREE_EXCEPTIONAL_SHIFT;
return 0;
}
bitmap = this_cpu_xchg(ida_bitmap, NULL);
if (!bitmap)
return -EAGAIN;
memset(bitmap, 0, sizeof(*bitmap));
bitmap->bitmap[0] = tmp >> RADIX_TREE_EXCEPTIONAL_SHIFT;
rcu_assign_pointer(*slot, bitmap);
}
if (bitmap) {
bit = find_next_zero_bit(bitmap->bitmap,
IDA_BITMAP_BITS, bit);
new += bit;
if (new < 0)
return -ENOSPC;
if (bit == IDA_BITMAP_BITS)
continue;
__set_bit(bit, bitmap->bitmap);
if (bitmap_full(bitmap->bitmap, IDA_BITMAP_BITS))
radix_tree_iter_tag_clear(root, &iter,
IDR_FREE);
} else {
new += bit;
if (new < 0)
return -ENOSPC;
if (ebit < BITS_PER_LONG) {
bitmap = (void *)((1UL << ebit) |
RADIX_TREE_EXCEPTIONAL_ENTRY);
radix_tree_iter_replace(root, &iter, slot,
bitmap);
*id = new;
return 0;
}
bitmap = this_cpu_xchg(ida_bitmap, NULL);
if (!bitmap)
return -EAGAIN;
memset(bitmap, 0, sizeof(*bitmap));
__set_bit(bit, bitmap->bitmap);
radix_tree_iter_replace(root, &iter, slot, bitmap);
}
*id = new;
return 0;
}
}
void ida_remove(struct ida *ida, int id)
{
unsigned long index = id / IDA_BITMAP_BITS;
unsigned offset = id % IDA_BITMAP_BITS;
struct ida_bitmap *bitmap;
unsigned long *btmp;
struct radix_tree_iter iter;
void __rcu **slot;
slot = radix_tree_iter_lookup(&ida->ida_rt, &iter, index);
if (!slot)
goto err;
bitmap = rcu_dereference_raw(*slot);
if (radix_tree_exception(bitmap)) {
btmp = (unsigned long *)slot;
offset += RADIX_TREE_EXCEPTIONAL_SHIFT;
if (offset >= BITS_PER_LONG)
goto err;
} else {
btmp = bitmap->bitmap;
}
if (!test_bit(offset, btmp))
goto err;
__clear_bit(offset, btmp);
radix_tree_iter_tag_set(&ida->ida_rt, &iter, IDR_FREE);
if (radix_tree_exception(bitmap)) {
if (rcu_dereference_raw(*slot) ==
(void *)RADIX_TREE_EXCEPTIONAL_ENTRY)
radix_tree_iter_delete(&ida->ida_rt, &iter, slot);
} else if (bitmap_empty(btmp, IDA_BITMAP_BITS)) {
kfree(bitmap);
radix_tree_iter_delete(&ida->ida_rt, &iter, slot);
}
return;
err:
WARN(1, "ida_remove called for id=%d which is not allocated.\n", id);
}
void ida_destroy(struct ida *ida)
{
struct radix_tree_iter iter;
void __rcu **slot;
radix_tree_for_each_slot(slot, &ida->ida_rt, &iter, 0) {
struct ida_bitmap *bitmap = rcu_dereference_raw(*slot);
if (!radix_tree_exception(bitmap))
kfree(bitmap);
radix_tree_iter_delete(&ida->ida_rt, &iter, slot);
}
}
int ida_simple_get(struct ida *ida, unsigned int start, unsigned int end,
gfp_t gfp_mask)
{
int ret, id;
unsigned int max;
unsigned long flags;
BUG_ON((int)start < 0);
BUG_ON((int)end < 0);
if (end == 0)
max = 0x80000000;
else {
BUG_ON(end < start);
max = end - 1;
}
again:
if (!ida_pre_get(ida, gfp_mask))
return -ENOMEM;
spin_lock_irqsave(&simple_ida_lock, flags);
ret = ida_get_new_above(ida, start, &id);
if (!ret) {
if (id > max) {
ida_remove(ida, id);
ret = -ENOSPC;
} else {
ret = id;
}
}
spin_unlock_irqrestore(&simple_ida_lock, flags);
if (unlikely(ret == -EAGAIN))
goto again;
return ret;
}
void ida_simple_remove(struct ida *ida, unsigned int id)
{
unsigned long flags;
BUG_ON((int)id < 0);
spin_lock_irqsave(&simple_ida_lock, flags);
ida_remove(ida, id);
spin_unlock_irqrestore(&simple_ida_lock, flags);
}
