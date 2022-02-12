static inline int coda_fideq(struct CodaFid *fid1, struct CodaFid *fid2)
{
return memcmp(fid1, fid2, sizeof(*fid1)) == 0;
}
static void coda_fill_inode(struct inode *inode, struct coda_vattr *attr)
{
coda_vattr_to_iattr(inode, attr);
if (S_ISREG(inode->i_mode)) {
inode->i_op = &coda_file_inode_operations;
inode->i_fop = &coda_file_operations;
} else if (S_ISDIR(inode->i_mode)) {
inode->i_op = &coda_dir_inode_operations;
inode->i_fop = &coda_dir_operations;
} else if (S_ISLNK(inode->i_mode)) {
inode->i_op = &coda_symlink_inode_operations;
inode->i_data.a_ops = &coda_symlink_aops;
inode->i_mapping = &inode->i_data;
} else
init_special_inode(inode, inode->i_mode, huge_decode_dev(attr->va_rdev));
}
static int coda_test_inode(struct inode *inode, void *data)
{
struct CodaFid *fid = (struct CodaFid *)data;
struct coda_inode_info *cii = ITOC(inode);
return coda_fideq(&cii->c_fid, fid);
}
static int coda_set_inode(struct inode *inode, void *data)
{
struct CodaFid *fid = (struct CodaFid *)data;
struct coda_inode_info *cii = ITOC(inode);
cii->c_fid = *fid;
return 0;
}
struct inode * coda_iget(struct super_block * sb, struct CodaFid * fid,
struct coda_vattr * attr)
{
struct inode *inode;
struct coda_inode_info *cii;
unsigned long hash = coda_f2i(fid);
inode = iget5_locked(sb, hash, coda_test_inode, coda_set_inode, fid);
if (!inode)
return ERR_PTR(-ENOMEM);
if (inode->i_state & I_NEW) {
cii = ITOC(inode);
inode->i_ino = hash;
cii->c_mapcount = 0;
unlock_new_inode(inode);
}
coda_fill_inode(inode, attr);
return inode;
}
int coda_cnode_make(struct inode **inode, struct CodaFid *fid, struct super_block *sb)
{
struct coda_vattr attr;
int error;
error = venus_getattr(sb, fid, &attr);
if ( error ) {
*inode = NULL;
return error;
}
*inode = coda_iget(sb, fid, &attr);
if ( IS_ERR(*inode) ) {
printk("coda_cnode_make: coda_iget failed\n");
return PTR_ERR(*inode);
}
return 0;
}
void coda_replace_fid(struct inode *inode, struct CodaFid *oldfid,
struct CodaFid *newfid)
{
struct coda_inode_info *cii = ITOC(inode);
unsigned long hash = coda_f2i(newfid);
BUG_ON(!coda_fideq(&cii->c_fid, oldfid));
remove_inode_hash(inode);
cii->c_fid = *newfid;
inode->i_ino = hash;
__insert_inode_hash(inode, hash);
}
struct inode *coda_fid_to_inode(struct CodaFid *fid, struct super_block *sb)
{
struct inode *inode;
unsigned long hash = coda_f2i(fid);
if ( !sb ) {
printk("coda_fid_to_inode: no sb!\n");
return NULL;
}
inode = ilookup5(sb, hash, coda_test_inode, fid);
if ( !inode )
return NULL;
BUG_ON(inode->i_state & I_NEW);
return inode;
}
int coda_cnode_makectl(struct inode **inode, struct super_block *sb)
{
int error = -ENOMEM;
*inode = new_inode(sb);
if (*inode) {
(*inode)->i_ino = CTL_INO;
(*inode)->i_op = &coda_ioctl_inode_operations;
(*inode)->i_fop = &coda_ioctl_operations;
(*inode)->i_mode = 0444;
error = 0;
}
return error;
}
