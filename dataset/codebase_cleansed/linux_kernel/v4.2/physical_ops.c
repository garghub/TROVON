static int
physical_op_open(struct rpcrdma_ia *ia, struct rpcrdma_ep *ep,
struct rpcrdma_create_data_internal *cdata)
{
return 0;
}
static size_t
physical_op_maxpages(struct rpcrdma_xprt *r_xprt)
{
return min_t(unsigned int, RPCRDMA_MAX_DATA_SEGS,
rpcrdma_max_segments(r_xprt));
}
static int
physical_op_init(struct rpcrdma_xprt *r_xprt)
{
return 0;
}
static int
physical_op_map(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mr_seg *seg,
int nsegs, bool writing)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
rpcrdma_map_one(ia->ri_device, seg, rpcrdma_data_dir(writing));
seg->mr_rkey = ia->ri_bind_mem->rkey;
seg->mr_base = seg->mr_dma;
seg->mr_nsegs = 1;
return 1;
}
static int
physical_op_unmap(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mr_seg *seg)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
rpcrdma_unmap_one(ia->ri_device, seg);
return 1;
}
static void
physical_op_destroy(struct rpcrdma_buffer *buf)
{
}
