static void *zlib_init(struct squashfs_sb_info *dummy, void *buff)
{
z_stream *stream = kmalloc(sizeof(z_stream), GFP_KERNEL);
if (stream == NULL)
goto failed;
stream->workspace = vmalloc(zlib_inflate_workspacesize());
if (stream->workspace == NULL)
goto failed;
return stream;
failed:
ERROR("Failed to allocate zlib workspace\n");
kfree(stream);
return ERR_PTR(-ENOMEM);
}
static void zlib_free(void *strm)
{
z_stream *stream = strm;
if (stream)
vfree(stream->workspace);
kfree(stream);
}
static int zlib_uncompress(struct squashfs_sb_info *msblk, void *strm,
struct buffer_head **bh, int b, int offset, int length,
struct squashfs_page_actor *output)
{
int zlib_err, zlib_init = 0, k = 0;
z_stream *stream = strm;
stream->avail_out = PAGE_SIZE;
stream->next_out = squashfs_first_page(output);
stream->avail_in = 0;
do {
if (stream->avail_in == 0 && k < b) {
int avail = min(length, msblk->devblksize - offset);
length -= avail;
stream->next_in = bh[k]->b_data + offset;
stream->avail_in = avail;
offset = 0;
}
if (stream->avail_out == 0) {
stream->next_out = squashfs_next_page(output);
if (stream->next_out != NULL)
stream->avail_out = PAGE_SIZE;
}
if (!zlib_init) {
zlib_err = zlib_inflateInit(stream);
if (zlib_err != Z_OK) {
squashfs_finish_page(output);
goto out;
}
zlib_init = 1;
}
zlib_err = zlib_inflate(stream, Z_SYNC_FLUSH);
if (stream->avail_in == 0 && k < b)
put_bh(bh[k++]);
} while (zlib_err == Z_OK);
squashfs_finish_page(output);
if (zlib_err != Z_STREAM_END)
goto out;
zlib_err = zlib_inflateEnd(stream);
if (zlib_err != Z_OK)
goto out;
if (k < b)
goto out;
return stream->total_out;
out:
for (; k < b; k++)
put_bh(bh[k]);
return -EIO;
}
