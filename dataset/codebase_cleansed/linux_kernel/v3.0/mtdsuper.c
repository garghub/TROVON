static int get_sb_mtd_compare(struct super_block *sb, void *_mtd)
{
struct mtd_info *mtd = _mtd;
if (sb->s_mtd == mtd) {
DEBUG(2, "MTDSB: Match on device %d (\"%s\")\n",
mtd->index, mtd->name);
return 1;
}
DEBUG(2, "MTDSB: No match, device %d (\"%s\"), device %d (\"%s\")\n",
sb->s_mtd->index, sb->s_mtd->name, mtd->index, mtd->name);
return 0;
}
static int get_sb_mtd_set(struct super_block *sb, void *_mtd)
{
struct mtd_info *mtd = _mtd;
sb->s_mtd = mtd;
sb->s_dev = MKDEV(MTD_BLOCK_MAJOR, mtd->index);
sb->s_bdi = mtd->backing_dev_info;
return 0;
}
static struct dentry *mount_mtd_aux(struct file_system_type *fs_type, int flags,
const char *dev_name, void *data,
struct mtd_info *mtd,
int (*fill_super)(struct super_block *, void *, int))
{
struct super_block *sb;
int ret;
sb = sget(fs_type, get_sb_mtd_compare, get_sb_mtd_set, mtd);
if (IS_ERR(sb))
goto out_error;
if (sb->s_root)
goto already_mounted;
DEBUG(1, "MTDSB: New superblock for device %d (\"%s\")\n",
mtd->index, mtd->name);
sb->s_flags = flags;
ret = fill_super(sb, data, flags & MS_SILENT ? 1 : 0);
if (ret < 0) {
deactivate_locked_super(sb);
return ERR_PTR(ret);
}
sb->s_flags |= MS_ACTIVE;
return dget(sb->s_root);
already_mounted:
DEBUG(1, "MTDSB: Device %d (\"%s\") is already mounted\n",
mtd->index, mtd->name);
put_mtd_device(mtd);
return dget(sb->s_root);
out_error:
put_mtd_device(mtd);
return ERR_CAST(sb);
}
static struct dentry *mount_mtd_nr(struct file_system_type *fs_type, int flags,
const char *dev_name, void *data, int mtdnr,
int (*fill_super)(struct super_block *, void *, int))
{
struct mtd_info *mtd;
mtd = get_mtd_device(NULL, mtdnr);
if (IS_ERR(mtd)) {
DEBUG(0, "MTDSB: Device #%u doesn't appear to exist\n", mtdnr);
return ERR_CAST(mtd);
}
return mount_mtd_aux(fs_type, flags, dev_name, data, mtd, fill_super);
}
struct dentry *mount_mtd(struct file_system_type *fs_type, int flags,
const char *dev_name, void *data,
int (*fill_super)(struct super_block *, void *, int))
{
#ifdef CONFIG_BLOCK
struct block_device *bdev;
int ret, major;
#endif
int mtdnr;
if (!dev_name)
return ERR_PTR(-EINVAL);
DEBUG(2, "MTDSB: dev_name \"%s\"\n", dev_name);
if (dev_name[0] == 'm' && dev_name[1] == 't' && dev_name[2] == 'd') {
if (dev_name[3] == ':') {
struct mtd_info *mtd;
DEBUG(1, "MTDSB: mtd:%%s, name \"%s\"\n",
dev_name + 4);
mtd = get_mtd_device_nm(dev_name + 4);
if (!IS_ERR(mtd))
return mount_mtd_aux(
fs_type, flags,
dev_name, data, mtd,
fill_super);
printk(KERN_NOTICE "MTD:"
" MTD device with name \"%s\" not found.\n",
dev_name + 4);
} else if (isdigit(dev_name[3])) {
char *endptr;
mtdnr = simple_strtoul(dev_name + 3, &endptr, 0);
if (!*endptr) {
DEBUG(1, "MTDSB: mtd%%d, mtdnr %d\n",
mtdnr);
return mount_mtd_nr(fs_type, flags,
dev_name, data,
mtdnr, fill_super);
}
}
}
#ifdef CONFIG_BLOCK
bdev = lookup_bdev(dev_name);
if (IS_ERR(bdev)) {
ret = PTR_ERR(bdev);
DEBUG(1, "MTDSB: lookup_bdev() returned %d\n", ret);
return ERR_PTR(ret);
}
DEBUG(1, "MTDSB: lookup_bdev() returned 0\n");
ret = -EINVAL;
major = MAJOR(bdev->bd_dev);
mtdnr = MINOR(bdev->bd_dev);
bdput(bdev);
if (major != MTD_BLOCK_MAJOR)
goto not_an_MTD_device;
return mount_mtd_nr(fs_type, flags, dev_name, data, mtdnr, fill_super);
not_an_MTD_device:
#endif
if (!(flags & MS_SILENT))
printk(KERN_NOTICE
"MTD: Attempt to mount non-MTD device \"%s\"\n",
dev_name);
return ERR_PTR(-EINVAL);
}
void kill_mtd_super(struct super_block *sb)
{
generic_shutdown_super(sb);
put_mtd_device(sb->s_mtd);
sb->s_mtd = NULL;
}
