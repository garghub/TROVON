int jfs_umount(struct super_block *sb)
{
struct jfs_sb_info *sbi = JFS_SBI(sb);
struct inode *ipbmap = sbi->ipbmap;
struct inode *ipimap = sbi->ipimap;
struct inode *ipaimap = sbi->ipaimap;
struct inode *ipaimap2 = sbi->ipaimap2;
struct jfs_log *log;
int rc = 0;
jfs_info("UnMount JFS: sb:0x%p", sb);
if ((log = sbi->log))
jfs_flush_journal(log, 1);
diUnmount(ipimap, 0);
diFreeSpecial(ipimap);
sbi->ipimap = NULL;
ipaimap2 = sbi->ipaimap2;
if (ipaimap2) {
diUnmount(ipaimap2, 0);
diFreeSpecial(ipaimap2);
sbi->ipaimap2 = NULL;
}
ipaimap = sbi->ipaimap;
diUnmount(ipaimap, 0);
diFreeSpecial(ipaimap);
sbi->ipaimap = NULL;
dbUnmount(ipbmap, 0);
diFreeSpecial(ipbmap);
sbi->ipimap = NULL;
filemap_write_and_wait(sbi->direct_inode->i_mapping);
if (log) {
updateSuper(sb, FM_CLEAN);
rc = lmLogClose(sb);
}
jfs_info("UnMount JFS Complete: rc = %d", rc);
return rc;
}
int jfs_umount_rw(struct super_block *sb)
{
struct jfs_sb_info *sbi = JFS_SBI(sb);
struct jfs_log *log = sbi->log;
if (!log)
return 0;
jfs_flush_journal(log, 1);
dbSync(sbi->ipbmap);
diSync(sbi->ipimap);
filemap_write_and_wait(sbi->direct_inode->i_mapping);
updateSuper(sb, FM_CLEAN);
return lmLogClose(sb);
}
