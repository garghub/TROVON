static void *lzo_init(struct squashfs_sb_info *msblk, void *buff, int len)
{
int block_size = max_t(int, msblk->block_size, SQUASHFS_METADATA_SIZE);
struct squashfs_lzo *stream = kzalloc(sizeof(*stream), GFP_KERNEL);
if (stream == NULL)
goto failed;
stream->input = vmalloc(block_size);
if (stream->input == NULL)
goto failed;
stream->output = vmalloc(block_size);
if (stream->output == NULL)
goto failed2;
return stream;
failed2:
vfree(stream->input);
failed:
ERROR("Failed to allocate lzo workspace\n");
kfree(stream);
return ERR_PTR(-ENOMEM);
}
static void lzo_free(void *strm)
{
struct squashfs_lzo *stream = strm;
if (stream) {
vfree(stream->input);
vfree(stream->output);
}
kfree(stream);
}
static int lzo_uncompress(struct squashfs_sb_info *msblk, void **buffer,
struct buffer_head **bh, int b, int offset, int length, int srclength,
int pages)
{
struct squashfs_lzo *stream = msblk->stream;
void *buff = stream->input;
int avail, i, bytes = length, res;
size_t out_len = srclength;
mutex_lock(&msblk->read_data_mutex);
for (i = 0; i < b; i++) {
wait_on_buffer(bh[i]);
if (!buffer_uptodate(bh[i]))
goto block_release;
avail = min(bytes, msblk->devblksize - offset);
memcpy(buff, bh[i]->b_data + offset, avail);
buff += avail;
bytes -= avail;
offset = 0;
put_bh(bh[i]);
}
res = lzo1x_decompress_safe(stream->input, (size_t)length,
stream->output, &out_len);
if (res != LZO_E_OK)
goto failed;
res = bytes = (int)out_len;
for (i = 0, buff = stream->output; bytes && i < pages; i++) {
avail = min_t(int, bytes, PAGE_CACHE_SIZE);
memcpy(buffer[i], buff, avail);
buff += avail;
bytes -= avail;
}
mutex_unlock(&msblk->read_data_mutex);
return res;
block_release:
for (; i < b; i++)
put_bh(bh[i]);
failed:
mutex_unlock(&msblk->read_data_mutex);
ERROR("lzo decompression failed, data probably corrupt\n");
return -EIO;
}
