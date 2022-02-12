static void *lzo_init(struct squashfs_sb_info *msblk, void *buff)
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
static int lzo_uncompress(struct squashfs_sb_info *msblk, void *strm,
struct buffer_head **bh, int b, int offset, int length,
struct squashfs_page_actor *output)
{
struct squashfs_lzo *stream = strm;
void *buff = stream->input, *data;
int avail, i, bytes = length, res;
size_t out_len = output->length;
for (i = 0; i < b; i++) {
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
data = squashfs_first_page(output);
buff = stream->output;
while (data) {
if (bytes <= PAGE_CACHE_SIZE) {
memcpy(data, buff, bytes);
break;
} else {
memcpy(data, buff, PAGE_CACHE_SIZE);
buff += PAGE_CACHE_SIZE;
bytes -= PAGE_CACHE_SIZE;
data = squashfs_next_page(output);
}
}
squashfs_finish_page(output);
return res;
failed:
return -EIO;
}
