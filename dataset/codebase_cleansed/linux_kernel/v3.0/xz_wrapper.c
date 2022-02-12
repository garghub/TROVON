static void *squashfs_xz_init(struct squashfs_sb_info *msblk, void *buff,
int len)
{
struct comp_opts *comp_opts = buff;
struct squashfs_xz *stream;
int dict_size = msblk->block_size;
int err, n;
if (comp_opts) {
if (len < sizeof(*comp_opts)) {
err = -EIO;
goto failed;
}
dict_size = le32_to_cpu(comp_opts->dictionary_size);
n = ffs(dict_size) - 1;
if (dict_size != (1 << n) && dict_size != (1 << n) +
(1 << (n + 1))) {
err = -EIO;
goto failed;
}
}
dict_size = max_t(int, dict_size, SQUASHFS_METADATA_SIZE);
stream = kmalloc(sizeof(*stream), GFP_KERNEL);
if (stream == NULL) {
err = -ENOMEM;
goto failed;
}
stream->state = xz_dec_init(XZ_PREALLOC, dict_size);
if (stream->state == NULL) {
kfree(stream);
err = -ENOMEM;
goto failed;
}
return stream;
failed:
ERROR("Failed to initialise xz decompressor\n");
return ERR_PTR(err);
}
static void squashfs_xz_free(void *strm)
{
struct squashfs_xz *stream = strm;
if (stream) {
xz_dec_end(stream->state);
kfree(stream);
}
}
static int squashfs_xz_uncompress(struct squashfs_sb_info *msblk, void **buffer,
struct buffer_head **bh, int b, int offset, int length, int srclength,
int pages)
{
enum xz_ret xz_err;
int avail, total = 0, k = 0, page = 0;
struct squashfs_xz *stream = msblk->stream;
mutex_lock(&msblk->read_data_mutex);
xz_dec_reset(stream->state);
stream->buf.in_pos = 0;
stream->buf.in_size = 0;
stream->buf.out_pos = 0;
stream->buf.out_size = PAGE_CACHE_SIZE;
stream->buf.out = buffer[page++];
do {
if (stream->buf.in_pos == stream->buf.in_size && k < b) {
avail = min(length, msblk->devblksize - offset);
length -= avail;
wait_on_buffer(bh[k]);
if (!buffer_uptodate(bh[k]))
goto release_mutex;
stream->buf.in = bh[k]->b_data + offset;
stream->buf.in_size = avail;
stream->buf.in_pos = 0;
offset = 0;
}
if (stream->buf.out_pos == stream->buf.out_size
&& page < pages) {
stream->buf.out = buffer[page++];
stream->buf.out_pos = 0;
total += PAGE_CACHE_SIZE;
}
xz_err = xz_dec_run(stream->state, &stream->buf);
if (stream->buf.in_pos == stream->buf.in_size && k < b)
put_bh(bh[k++]);
} while (xz_err == XZ_OK);
if (xz_err != XZ_STREAM_END) {
ERROR("xz_dec_run error, data probably corrupt\n");
goto release_mutex;
}
if (k < b) {
ERROR("xz_uncompress error, input remaining\n");
goto release_mutex;
}
total += stream->buf.out_pos;
mutex_unlock(&msblk->read_data_mutex);
return total;
release_mutex:
mutex_unlock(&msblk->read_data_mutex);
for (; k < b; k++)
put_bh(bh[k]);
return -EIO;
}
