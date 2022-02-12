const struct squashfs_decompressor *squashfs_lookup_decompressor(int id)
{
int i;
for (i = 0; decompressor[i]->id; i++)
if (id == decompressor[i]->id)
break;
return decompressor[i];
}
static void *get_comp_opts(struct super_block *sb, unsigned short flags)
{
struct squashfs_sb_info *msblk = sb->s_fs_info;
void *buffer = NULL, *comp_opts;
struct squashfs_page_actor *actor = NULL;
int length = 0;
if (SQUASHFS_COMP_OPTS(flags)) {
buffer = kmalloc(PAGE_CACHE_SIZE, GFP_KERNEL);
if (buffer == NULL) {
comp_opts = ERR_PTR(-ENOMEM);
goto out;
}
actor = squashfs_page_actor_init(&buffer, 1, 0);
if (actor == NULL) {
comp_opts = ERR_PTR(-ENOMEM);
goto out;
}
length = squashfs_read_data(sb,
sizeof(struct squashfs_super_block), 0, NULL, actor);
if (length < 0) {
comp_opts = ERR_PTR(length);
goto out;
}
}
comp_opts = squashfs_comp_opts(msblk, buffer, length);
out:
kfree(actor);
kfree(buffer);
return comp_opts;
}
void *squashfs_decompressor_setup(struct super_block *sb, unsigned short flags)
{
struct squashfs_sb_info *msblk = sb->s_fs_info;
void *stream, *comp_opts = get_comp_opts(sb, flags);
if (IS_ERR(comp_opts))
return comp_opts;
stream = squashfs_decompressor_create(msblk, comp_opts);
if (IS_ERR(stream))
kfree(comp_opts);
return stream;
}
