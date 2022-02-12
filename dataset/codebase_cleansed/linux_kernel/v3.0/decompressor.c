const struct squashfs_decompressor *squashfs_lookup_decompressor(int id)
{
int i;
for (i = 0; decompressor[i]->id; i++)
if (id == decompressor[i]->id)
break;
return decompressor[i];
}
void *squashfs_decompressor_init(struct super_block *sb, unsigned short flags)
{
struct squashfs_sb_info *msblk = sb->s_fs_info;
void *strm, *buffer = NULL;
int length = 0;
if (SQUASHFS_COMP_OPTS(flags)) {
buffer = kmalloc(PAGE_CACHE_SIZE, GFP_KERNEL);
if (buffer == NULL)
return ERR_PTR(-ENOMEM);
length = squashfs_read_data(sb, &buffer,
sizeof(struct squashfs_super_block), 0, NULL,
PAGE_CACHE_SIZE, 1);
if (length < 0) {
strm = ERR_PTR(length);
goto finished;
}
}
strm = msblk->decompressor->init(msblk, buffer, length);
finished:
kfree(buffer);
return strm;
}
