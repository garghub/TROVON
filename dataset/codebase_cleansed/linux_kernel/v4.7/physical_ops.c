static int
physical_op_open(struct rpcrdma_ia *ia, struct rpcrdma_ep *ep,
struct rpcrdma_create_data_internal *cdata)
{
struct ib_mr *mr;
mr = ib_get_dma_mr(ia->ri_pd,
IB_ACCESS_LOCAL_WRITE |
IB_ACCESS_REMOTE_WRITE |
IB_ACCESS_REMOTE_READ);
if (IS_ERR(mr)) {
pr_err("%s: ib_get_dma_mr for failed with %lX\n",
__func__, PTR_ERR(mr));
return -ENOMEM;
}
ia->ri_dma_mr = mr;
rpcrdma_set_max_header_sizes(ia, cdata, min_t(unsigned int,
RPCRDMA_MAX_DATA_SEGS,
RPCRDMA_MAX_HDR_SEGS));
return 0;
}
static size_t
physical_op_maxpages(struct rpcrdma_xprt *r_xprt)
{
return min_t(unsigned int, RPCRDMA_MAX_DATA_SEGS,
RPCRDMA_MAX_HDR_SEGS);
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
seg->mr_rkey = ia->ri_dma_mr->rkey;
seg->mr_base = seg->mr_dma;
return 1;
}
static void
physical_op_unmap_sync(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req)
{
struct ib_device *device = r_xprt->rx_ia.ri_device;
unsigned int i;
for (i = 0; req->rl_nchunks; --req->rl_nchunks)
rpcrdma_unmap_one(device, &req->rl_segments[i++]);
}
static void
physical_op_unmap_safe(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req,
bool sync)
{
physical_op_unmap_sync(r_xprt, req);
}
static void
physical_op_destroy(struct rpcrdma_buffer *buf)
{
}
