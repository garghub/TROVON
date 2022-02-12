int __next_node_in(int node, const nodemask_t *srcp)
{
int ret = __next_node(node, srcp);
if (ret == MAX_NUMNODES)
ret = __first_node(srcp);
return ret;
}
int node_random(const nodemask_t *maskp)
{
int w, bit = NUMA_NO_NODE;
w = nodes_weight(*maskp);
if (w)
bit = bitmap_ord_to_pos(maskp->bits,
get_random_int() % w, MAX_NUMNODES);
return bit;
}
