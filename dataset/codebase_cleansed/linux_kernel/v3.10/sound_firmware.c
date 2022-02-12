static int do_mod_firmware_load(const char *fn, char **fp)
{
struct file* filp;
long l;
char *dp;
loff_t pos;
filp = filp_open(fn, 0, 0);
if (IS_ERR(filp))
{
printk(KERN_INFO "Unable to load '%s'.\n", fn);
return 0;
}
l = i_size_read(file_inode(filp));
if (l <= 0 || l > 131072)
{
printk(KERN_INFO "Invalid firmware '%s'\n", fn);
fput(filp);
return 0;
}
dp = vmalloc(l);
if (dp == NULL)
{
printk(KERN_INFO "Out of memory loading '%s'.\n", fn);
fput(filp);
return 0;
}
pos = 0;
if (vfs_read(filp, dp, l, &pos) != l)
{
printk(KERN_INFO "Failed to read '%s'.\n", fn);
vfree(dp);
fput(filp);
return 0;
}
fput(filp);
*fp = dp;
return (int) l;
}
int mod_firmware_load(const char *fn, char **fp)
{
int r;
mm_segment_t fs = get_fs();
set_fs(get_ds());
r = do_mod_firmware_load(fn, fp);
set_fs(fs);
return r;
}
