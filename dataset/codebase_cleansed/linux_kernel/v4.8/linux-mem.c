void *libcfs_kvzalloc(size_t size, gfp_t flags)
{
void *ret;
ret = kzalloc(size, flags | __GFP_NOWARN);
if (!ret)
ret = __vmalloc(size, flags | __GFP_ZERO, PAGE_KERNEL);
return ret;
}
void *libcfs_kvzalloc_cpt(struct cfs_cpt_table *cptab, int cpt, size_t size,
gfp_t flags)
{
void *ret;
ret = kzalloc_node(size, flags | __GFP_NOWARN,
cfs_cpt_spread_node(cptab, cpt));
if (!ret) {
WARN_ON(!(flags & (__GFP_FS | __GFP_HIGH)));
ret = vmalloc_node(size, cfs_cpt_spread_node(cptab, cpt));
}
return ret;
}
