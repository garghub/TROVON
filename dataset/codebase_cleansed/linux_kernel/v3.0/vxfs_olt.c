static inline void
vxfs_get_fshead(struct vxfs_oltfshead *fshp, struct vxfs_sb_info *infp)
{
BUG_ON(infp->vsi_fshino);
infp->vsi_fshino = fshp->olt_fsino[0];
}
static inline void
vxfs_get_ilist(struct vxfs_oltilist *ilistp, struct vxfs_sb_info *infp)
{
BUG_ON(infp->vsi_iext);
infp->vsi_iext = ilistp->olt_iext[0];
}
static inline u_long
vxfs_oblock(struct super_block *sbp, daddr_t block, u_long bsize)
{
BUG_ON(sbp->s_blocksize % bsize);
return (block * (sbp->s_blocksize / bsize));
}
int
vxfs_read_olt(struct super_block *sbp, u_long bsize)
{
struct vxfs_sb_info *infp = VXFS_SBI(sbp);
struct buffer_head *bp;
struct vxfs_olt *op;
char *oaddr, *eaddr;
bp = sb_bread(sbp, vxfs_oblock(sbp, infp->vsi_oltext, bsize));
if (!bp || !bp->b_data)
goto fail;
op = (struct vxfs_olt *)bp->b_data;
if (op->olt_magic != VXFS_OLT_MAGIC) {
printk(KERN_NOTICE "vxfs: ivalid olt magic number\n");
goto fail;
}
if (infp->vsi_oltsize > 1) {
printk(KERN_NOTICE "vxfs: oltsize > 1 detected.\n");
printk(KERN_NOTICE "vxfs: please notify hch@infradead.org\n");
goto fail;
}
oaddr = bp->b_data + op->olt_size;
eaddr = bp->b_data + (infp->vsi_oltsize * sbp->s_blocksize);
while (oaddr < eaddr) {
struct vxfs_oltcommon *ocp =
(struct vxfs_oltcommon *)oaddr;
switch (ocp->olt_type) {
case VXFS_OLT_FSHEAD:
vxfs_get_fshead((struct vxfs_oltfshead *)oaddr, infp);
break;
case VXFS_OLT_ILIST:
vxfs_get_ilist((struct vxfs_oltilist *)oaddr, infp);
break;
}
oaddr += ocp->olt_size;
}
brelse(bp);
return 0;
fail:
brelse(bp);
return -EINVAL;
}
