static void *zlib_init(struct squashfs_sb_info *dummy, void *buff, int len)
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
static int zlib_uncompress(struct squashfs_sb_info *msblk, void **buffer,
struct buffer_head **bh, int b, int offset, int length, int srclength,
int pages)
{
int zlib_err, zlib_init = 0;
int k = 0, page = 0;
z_stream *stream = msblk->stream;
mutex_lock(&msblk->read_data_mutex);
stream->avail_out = 0;
stream->avail_in = 0;
do {
if (stream->avail_in == 0 && k < b) {
int avail = min(length, msblk->devblksize - offset);
length -= avail;
wait_on_buffer(bh[k]);
if (!buffer_uptodate(bh[k]))
goto release_mutex;
stream->next_in = bh[k]->b_data + offset;
stream->avail_in = avail;
offset = 0;
}
if (stream->avail_out == 0 && page < pages) {
stream->next_out = buffer[page++];
stream->avail_out = PAGE_CACHE_SIZE;
}
if (!zlib_init) {
zlib_err = zlib_inflateInit(stream);
if (zlib_err != Z_OK) {
ERROR("zlib_inflateInit returned unexpected "
"result 0x%x, srclength %d\n",
zlib_err, srclength);
goto release_mutex;
}
zlib_init = 1;
}
zlib_err = zlib_inflate(stream, Z_SYNC_FLUSH);
if (stream->avail_in == 0 && k < b)
put_bh(bh[k++]);
} while (zlib_err == Z_OK);
if (zlib_err != Z_STREAM_END) {
ERROR("zlib_inflate error, data probably corrupt\n");
goto release_mutex;
}
zlib_err = zlib_inflateEnd(stream);
if (zlib_err != Z_OK) {
ERROR("zlib_inflate error, data probably corrupt\n");
goto release_mutex;
}
if (k < b) {
ERROR("zlib_uncompress error, data remaining\n");
goto release_mutex;
}
length = stream->total_out;
mutex_unlock(&msblk->read_data_mutex);
return length;
release_mutex:
mutex_unlock(&msblk->read_data_mutex);
for (; k < b; k++)
put_bh(bh[k]);
return -EIO;
}
