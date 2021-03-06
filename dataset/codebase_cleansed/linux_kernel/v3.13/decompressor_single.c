void *squashfs_decompressor_create(struct squashfs_sb_info *msblk,
void *comp_opts)
{
struct squashfs_stream *stream;
int err = -ENOMEM;
stream = kmalloc(sizeof(*stream), GFP_KERNEL);
if (stream == NULL)
goto out;
stream->stream = msblk->decompressor->init(msblk, comp_opts);
if (IS_ERR(stream->stream)) {
err = PTR_ERR(stream->stream);
goto out;
}
kfree(comp_opts);
mutex_init(&stream->mutex);
return stream;
out:
kfree(stream);
return ERR_PTR(err);
}
void squashfs_decompressor_destroy(struct squashfs_sb_info *msblk)
{
struct squashfs_stream *stream = msblk->stream;
if (stream) {
msblk->decompressor->free(stream->stream);
kfree(stream);
}
}
int squashfs_decompress(struct squashfs_sb_info *msblk, struct buffer_head **bh,
int b, int offset, int length, struct squashfs_page_actor *output)
{
int res;
struct squashfs_stream *stream = msblk->stream;
mutex_lock(&stream->mutex);
res = msblk->decompressor->decompress(msblk, stream->stream, bh, b,
offset, length, output);
mutex_unlock(&stream->mutex);
if (res < 0)
ERROR("%s decompression failed, data probably corrupt\n",
msblk->decompressor->name);
return res;
}
int squashfs_max_decompressors(void)
{
return 1;
}
