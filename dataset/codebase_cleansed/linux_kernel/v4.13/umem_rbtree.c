static inline u64 node_start(struct umem_odp_node *n)
{
struct ib_umem_odp *umem_odp =
container_of(n, struct ib_umem_odp, interval_tree);
return ib_umem_start(umem_odp->umem);
}
static inline u64 node_last(struct umem_odp_node *n)
{
struct ib_umem_odp *umem_odp =
container_of(n, struct ib_umem_odp, interval_tree);
return ib_umem_end(umem_odp->umem) - 1;
}
int rbt_ib_umem_for_each_in_range(struct rb_root *root,
u64 start, u64 last,
umem_call_back cb,
void *cookie)
{
int ret_val = 0;
struct umem_odp_node *node, *next;
struct ib_umem_odp *umem;
if (unlikely(start == last))
return ret_val;
for (node = rbt_ib_umem_iter_first(root, start, last - 1);
node; node = next) {
next = rbt_ib_umem_iter_next(node, start, last - 1);
umem = container_of(node, struct ib_umem_odp, interval_tree);
ret_val = cb(umem->umem, start, last, cookie) || ret_val;
}
return ret_val;
}
struct ib_umem_odp *rbt_ib_umem_lookup(struct rb_root *root,
u64 addr, u64 length)
{
struct umem_odp_node *node;
node = rbt_ib_umem_iter_first(root, addr, addr + length - 1);
if (node)
return container_of(node, struct ib_umem_odp, interval_tree);
return NULL;
}
