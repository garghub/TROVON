static __be32
nfsd4_block_proc_layoutget(struct inode *inode, const struct svc_fh *fhp,
struct nfsd4_layoutget *args)
{
struct nfsd4_layout_seg *seg = &args->lg_seg;
struct super_block *sb = inode->i_sb;
u32 block_size = (1 << inode->i_blkbits);
struct pnfs_block_extent *bex;
struct iomap iomap;
u32 device_generation = 0;
int error;
if (seg->offset & (block_size - 1)) {
dprintk("pnfsd: I/O misaligned\n");
goto out_layoutunavailable;
}
error = -ENOMEM;
bex = kzalloc(sizeof(*bex), GFP_KERNEL);
if (!bex)
goto out_error;
args->lg_content = bex;
error = sb->s_export_op->map_blocks(inode, seg->offset, seg->length,
&iomap, seg->iomode != IOMODE_READ,
&device_generation);
if (error) {
if (error == -ENXIO)
goto out_layoutunavailable;
goto out_error;
}
if (iomap.length < args->lg_minlength) {
dprintk("pnfsd: extent smaller than minlength\n");
goto out_layoutunavailable;
}
switch (iomap.type) {
case IOMAP_MAPPED:
if (seg->iomode == IOMODE_READ)
bex->es = PNFS_BLOCK_READ_DATA;
else
bex->es = PNFS_BLOCK_READWRITE_DATA;
bex->soff = (iomap.blkno << 9);
break;
case IOMAP_UNWRITTEN:
if (seg->iomode & IOMODE_RW) {
if (args->lg_minlength == 0) {
dprintk("pnfsd: no soup for you!\n");
goto out_layoutunavailable;
}
bex->es = PNFS_BLOCK_INVALID_DATA;
bex->soff = (iomap.blkno << 9);
break;
}
case IOMAP_HOLE:
if (seg->iomode == IOMODE_READ) {
bex->es = PNFS_BLOCK_NONE_DATA;
break;
}
case IOMAP_DELALLOC:
default:
WARN(1, "pnfsd: filesystem returned %d extent\n", iomap.type);
goto out_layoutunavailable;
}
error = nfsd4_set_deviceid(&bex->vol_id, fhp, device_generation);
if (error)
goto out_error;
bex->foff = iomap.offset;
bex->len = iomap.length;
seg->offset = iomap.offset;
seg->length = iomap.length;
dprintk("GET: 0x%llx:0x%llx %d\n", bex->foff, bex->len, bex->es);
return 0;
out_error:
seg->length = 0;
return nfserrno(error);
out_layoutunavailable:
seg->length = 0;
return nfserr_layoutunavailable;
}
static __be32
nfsd4_block_commit_blocks(struct inode *inode, struct nfsd4_layoutcommit *lcp,
struct iomap *iomaps, int nr_iomaps)
{
loff_t new_size = lcp->lc_last_wr + 1;
struct iattr iattr = { .ia_valid = 0 };
int error;
if (lcp->lc_mtime.tv_nsec == UTIME_NOW ||
timespec_compare(&lcp->lc_mtime, &inode->i_mtime) < 0)
lcp->lc_mtime = current_time(inode);
iattr.ia_valid |= ATTR_ATIME | ATTR_CTIME | ATTR_MTIME;
iattr.ia_atime = iattr.ia_ctime = iattr.ia_mtime = lcp->lc_mtime;
if (new_size > i_size_read(inode)) {
iattr.ia_valid |= ATTR_SIZE;
iattr.ia_size = new_size;
}
error = inode->i_sb->s_export_op->commit_blocks(inode, iomaps,
nr_iomaps, &iattr);
kfree(iomaps);
return nfserrno(error);
}
static int
nfsd4_block_get_device_info_simple(struct super_block *sb,
struct nfsd4_getdeviceinfo *gdp)
{
struct pnfs_block_deviceaddr *dev;
struct pnfs_block_volume *b;
dev = kzalloc(sizeof(struct pnfs_block_deviceaddr) +
sizeof(struct pnfs_block_volume), GFP_KERNEL);
if (!dev)
return -ENOMEM;
gdp->gd_device = dev;
dev->nr_volumes = 1;
b = &dev->volumes[0];
b->type = PNFS_BLOCK_VOLUME_SIMPLE;
b->simple.sig_len = PNFS_BLOCK_UUID_LEN;
return sb->s_export_op->get_uuid(sb, b->simple.sig, &b->simple.sig_len,
&b->simple.offset);
}
static __be32
nfsd4_block_proc_getdeviceinfo(struct super_block *sb,
struct svc_rqst *rqstp,
struct nfs4_client *clp,
struct nfsd4_getdeviceinfo *gdp)
{
if (sb->s_bdev != sb->s_bdev->bd_contains)
return nfserr_inval;
return nfserrno(nfsd4_block_get_device_info_simple(sb, gdp));
}
static __be32
nfsd4_block_proc_layoutcommit(struct inode *inode,
struct nfsd4_layoutcommit *lcp)
{
struct iomap *iomaps;
int nr_iomaps;
nr_iomaps = nfsd4_block_decode_layoutupdate(lcp->lc_up_layout,
lcp->lc_up_len, &iomaps, 1 << inode->i_blkbits);
if (nr_iomaps < 0)
return nfserrno(nr_iomaps);
return nfsd4_block_commit_blocks(inode, lcp, iomaps, nr_iomaps);
}
static int nfsd4_scsi_identify_device(struct block_device *bdev,
struct pnfs_block_volume *b)
{
struct request_queue *q = bdev->bd_disk->queue;
struct request *rq;
size_t bufflen = 252, len, id_len;
u8 *buf, *d, type, assoc;
int error;
buf = kzalloc(bufflen, GFP_KERNEL);
if (!buf)
return -ENOMEM;
rq = blk_get_request(q, READ, GFP_KERNEL);
if (IS_ERR(rq)) {
error = -ENOMEM;
goto out_free_buf;
}
blk_rq_set_block_pc(rq);
error = blk_rq_map_kern(q, rq, buf, bufflen, GFP_KERNEL);
if (error)
goto out_put_request;
rq->cmd[0] = INQUIRY;
rq->cmd[1] = 1;
rq->cmd[2] = 0x83;
rq->cmd[3] = bufflen >> 8;
rq->cmd[4] = bufflen & 0xff;
rq->cmd_len = COMMAND_SIZE(INQUIRY);
error = blk_execute_rq(rq->q, NULL, rq, 1);
if (error) {
pr_err("pNFS: INQUIRY 0x83 failed with: %x\n",
rq->errors);
goto out_put_request;
}
len = (buf[2] << 8) + buf[3] + 4;
if (len > bufflen) {
pr_err("pNFS: INQUIRY 0x83 response invalid (len = %zd)\n",
len);
goto out_put_request;
}
d = buf + 4;
for (d = buf + 4; d < buf + len; d += id_len + 4) {
id_len = d[3];
type = d[1] & 0xf;
assoc = (d[1] >> 4) & 0x3;
if (assoc != 0x00)
continue;
if (type != 0x02 && type != 0x03)
continue;
if (id_len != 8 && id_len != 12 && id_len != 16)
continue;
b->scsi.code_set = PS_CODE_SET_BINARY;
b->scsi.designator_type = type == 0x02 ?
PS_DESIGNATOR_EUI64 : PS_DESIGNATOR_NAA;
b->scsi.designator_len = id_len;
memcpy(b->scsi.designator, d + 4, id_len);
if (id_len == 16)
break;
}
out_put_request:
blk_put_request(rq);
out_free_buf:
kfree(buf);
return error;
}
static u64 nfsd4_scsi_pr_key(struct nfs4_client *clp)
{
return ((u64)clp->cl_clientid.cl_boot << 32) | clp->cl_clientid.cl_id;
}
static int
nfsd4_block_get_device_info_scsi(struct super_block *sb,
struct nfs4_client *clp,
struct nfsd4_getdeviceinfo *gdp)
{
struct pnfs_block_deviceaddr *dev;
struct pnfs_block_volume *b;
const struct pr_ops *ops;
int error;
dev = kzalloc(sizeof(struct pnfs_block_deviceaddr) +
sizeof(struct pnfs_block_volume), GFP_KERNEL);
if (!dev)
return -ENOMEM;
gdp->gd_device = dev;
dev->nr_volumes = 1;
b = &dev->volumes[0];
b->type = PNFS_BLOCK_VOLUME_SCSI;
b->scsi.pr_key = nfsd4_scsi_pr_key(clp);
error = nfsd4_scsi_identify_device(sb->s_bdev, b);
if (error)
return error;
ops = sb->s_bdev->bd_disk->fops->pr_ops;
if (!ops) {
pr_err("pNFS: device %s does not support PRs.\n",
sb->s_id);
return -EINVAL;
}
error = ops->pr_register(sb->s_bdev, 0, NFSD_MDS_PR_KEY, true);
if (error) {
pr_err("pNFS: failed to register key for device %s.\n",
sb->s_id);
return -EINVAL;
}
error = ops->pr_reserve(sb->s_bdev, NFSD_MDS_PR_KEY,
PR_EXCLUSIVE_ACCESS_REG_ONLY, 0);
if (error) {
pr_err("pNFS: failed to reserve device %s.\n",
sb->s_id);
return -EINVAL;
}
return 0;
}
static __be32
nfsd4_scsi_proc_getdeviceinfo(struct super_block *sb,
struct svc_rqst *rqstp,
struct nfs4_client *clp,
struct nfsd4_getdeviceinfo *gdp)
{
if (sb->s_bdev != sb->s_bdev->bd_contains)
return nfserr_inval;
return nfserrno(nfsd4_block_get_device_info_scsi(sb, clp, gdp));
}
static __be32
nfsd4_scsi_proc_layoutcommit(struct inode *inode,
struct nfsd4_layoutcommit *lcp)
{
struct iomap *iomaps;
int nr_iomaps;
nr_iomaps = nfsd4_scsi_decode_layoutupdate(lcp->lc_up_layout,
lcp->lc_up_len, &iomaps, 1 << inode->i_blkbits);
if (nr_iomaps < 0)
return nfserrno(nr_iomaps);
return nfsd4_block_commit_blocks(inode, lcp, iomaps, nr_iomaps);
}
static void
nfsd4_scsi_fence_client(struct nfs4_layout_stateid *ls)
{
struct nfs4_client *clp = ls->ls_stid.sc_client;
struct block_device *bdev = ls->ls_file->f_path.mnt->mnt_sb->s_bdev;
bdev->bd_disk->fops->pr_ops->pr_preempt(bdev, NFSD_MDS_PR_KEY,
nfsd4_scsi_pr_key(clp), 0, true);
}
