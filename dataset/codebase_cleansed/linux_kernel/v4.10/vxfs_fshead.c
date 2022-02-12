static void
vxfs_dumpfsh(struct vxfs_fsh *fhp)
{
printk("\n\ndumping fileset header:\n");
printk("----------------------------\n");
printk("version: %u\n", fhp->fsh_version);
printk("fsindex: %u\n", fhp->fsh_fsindex);
printk("iauino: %u\tninodes:%u\n",
fhp->fsh_iauino, fhp->fsh_ninodes);
printk("maxinode: %u\tlctino: %u\n",
fhp->fsh_maxinode, fhp->fsh_lctino);
printk("nau: %u\n", fhp->fsh_nau);
printk("ilistino[0]: %u\tilistino[1]: %u\n",
fhp->fsh_ilistino[0], fhp->fsh_ilistino[1]);
}
static struct vxfs_fsh *
vxfs_getfsh(struct inode *ip, int which)
{
struct buffer_head *bp;
bp = vxfs_bread(ip, which);
if (bp) {
struct vxfs_fsh *fhp;
if (!(fhp = kmalloc(sizeof(*fhp), GFP_KERNEL)))
goto out;
memcpy(fhp, bp->b_data, sizeof(*fhp));
put_bh(bp);
return (fhp);
}
out:
brelse(bp);
return NULL;
}
int
vxfs_read_fshead(struct super_block *sbp)
{
struct vxfs_sb_info *infp = VXFS_SBI(sbp);
struct vxfs_fsh *pfp, *sfp;
struct vxfs_inode_info *vip;
infp->vsi_fship = vxfs_blkiget(sbp, infp->vsi_iext, infp->vsi_fshino);
if (!infp->vsi_fship) {
printk(KERN_ERR "vxfs: unable to read fsh inode\n");
return -EINVAL;
}
vip = VXFS_INO(infp->vsi_fship);
if (!VXFS_ISFSH(vip)) {
printk(KERN_ERR "vxfs: fsh list inode is of wrong type (%x)\n",
vip->vii_mode & VXFS_TYPE_MASK);
goto out_iput_fship;
}
#ifdef DIAGNOSTIC
printk("vxfs: fsh inode dump:\n");
vxfs_dumpi(vip, infp->vsi_fshino);
#endif
sfp = vxfs_getfsh(infp->vsi_fship, 0);
if (!sfp) {
printk(KERN_ERR "vxfs: unable to get structural fsh\n");
goto out_iput_fship;
}
#ifdef DIAGNOSTIC
vxfs_dumpfsh(sfp);
#endif
pfp = vxfs_getfsh(infp->vsi_fship, 1);
if (!pfp) {
printk(KERN_ERR "vxfs: unable to get primary fsh\n");
goto out_free_sfp;
}
#ifdef DIAGNOSTIC
vxfs_dumpfsh(pfp);
#endif
infp->vsi_stilist = vxfs_blkiget(sbp, infp->vsi_iext,
fs32_to_cpu(infp, sfp->fsh_ilistino[0]));
if (!infp->vsi_stilist) {
printk(KERN_ERR "vxfs: unable to get structural list inode\n");
goto out_free_pfp;
}
if (!VXFS_ISILT(VXFS_INO(infp->vsi_stilist))) {
printk(KERN_ERR "vxfs: structural list inode is of wrong type (%x)\n",
VXFS_INO(infp->vsi_stilist)->vii_mode & VXFS_TYPE_MASK);
goto out_iput_stilist;
}
infp->vsi_ilist = vxfs_stiget(sbp, fs32_to_cpu(infp, pfp->fsh_ilistino[0]));
if (!infp->vsi_ilist) {
printk(KERN_ERR "vxfs: unable to get inode list inode\n");
goto out_iput_stilist;
}
if (!VXFS_ISILT(VXFS_INO(infp->vsi_ilist))) {
printk(KERN_ERR "vxfs: inode list inode is of wrong type (%x)\n",
VXFS_INO(infp->vsi_ilist)->vii_mode & VXFS_TYPE_MASK);
goto out_iput_ilist;
}
kfree(pfp);
kfree(sfp);
return 0;
out_iput_ilist:
iput(infp->vsi_ilist);
out_iput_stilist:
iput(infp->vsi_stilist);
out_free_pfp:
kfree(pfp);
out_free_sfp:
kfree(sfp);
out_iput_fship:
iput(infp->vsi_fship);
return -EINVAL;
}
