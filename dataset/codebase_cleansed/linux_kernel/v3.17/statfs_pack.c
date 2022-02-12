void statfs_pack(struct obd_statfs *osfs, struct kstatfs *sfs)
{
memset(osfs, 0, sizeof(*osfs));
osfs->os_type = sfs->f_type;
osfs->os_blocks = sfs->f_blocks;
osfs->os_bfree = sfs->f_bfree;
osfs->os_bavail = sfs->f_bavail;
osfs->os_files = sfs->f_files;
osfs->os_ffree = sfs->f_ffree;
osfs->os_bsize = sfs->f_bsize;
osfs->os_namelen = sfs->f_namelen;
}
void statfs_unpack(struct kstatfs *sfs, struct obd_statfs *osfs)
{
memset(sfs, 0, sizeof(*sfs));
sfs->f_type = osfs->os_type;
sfs->f_blocks = osfs->os_blocks;
sfs->f_bfree = osfs->os_bfree;
sfs->f_bavail = osfs->os_bavail;
sfs->f_files = osfs->os_files;
sfs->f_ffree = osfs->os_ffree;
sfs->f_bsize = osfs->os_bsize;
sfs->f_namelen = osfs->os_namelen;
}
