static inline struct vvp_req *cl2vvp_req(const struct cl_req_slice *slice)
{
return container_of0(slice, struct vvp_req, vrq_cl);
}
void vvp_req_attr_set(const struct lu_env *env,
const struct cl_req_slice *slice,
const struct cl_object *obj,
struct cl_req_attr *attr, u64 flags)
{
struct inode *inode;
struct obdo *oa;
u32 valid_flags;
oa = attr->cra_oa;
inode = vvp_object_inode(obj);
valid_flags = OBD_MD_FLTYPE;
if (slice->crs_req->crq_type == CRT_WRITE) {
if (flags & OBD_MD_FLEPOCH) {
oa->o_valid |= OBD_MD_FLEPOCH;
oa->o_ioepoch = ll_i2info(inode)->lli_ioepoch;
valid_flags |= OBD_MD_FLMTIME | OBD_MD_FLCTIME |
OBD_MD_FLUID | OBD_MD_FLGID;
}
}
obdo_from_inode(oa, inode, valid_flags & flags);
obdo_set_parent_fid(oa, &ll_i2info(inode)->lli_fid);
memcpy(attr->cra_jobid, ll_i2info(inode)->lli_jobid,
JOBSTATS_JOBID_SIZE);
}
void vvp_req_completion(const struct lu_env *env,
const struct cl_req_slice *slice, int ioret)
{
struct vvp_req *vrq;
if (ioret > 0)
cl_stats_tally(slice->crs_dev, slice->crs_req->crq_type, ioret);
vrq = cl2vvp_req(slice);
kmem_cache_free(vvp_req_kmem, vrq);
}
int vvp_req_init(const struct lu_env *env, struct cl_device *dev,
struct cl_req *req)
{
struct vvp_req *vrq;
int result;
vrq = kmem_cache_zalloc(vvp_req_kmem, GFP_NOFS);
if (vrq) {
cl_req_slice_add(req, &vrq->vrq_cl, dev, &vvp_req_ops);
result = 0;
} else {
result = -ENOMEM;
}
return result;
}
