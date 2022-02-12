static void *lz4_comp_opts(struct squashfs_sb_info *msblk,
void *buff, int len)
{
struct lz4_comp_opts *comp_opts = buff;
if (comp_opts == NULL || len < sizeof(*comp_opts))
return ERR_PTR(-EIO);
if (le32_to_cpu(comp_opts->version) != LZ4_LEGACY) {
ERROR("Unknown LZ4 version\n");
return ERR_PTR(-EINVAL);
}
return NULL;
}
static void *lz4_init(struct squashfs_sb_info *msblk, void *buff)
{
int block_size = max_t(int, msblk->block_size, SQUASHFS_METADATA_SIZE);
struct squashfs_lz4 *stream;
stream = kzalloc(sizeof(*stream), GFP_KERNEL);
if (stream == NULL)
goto failed;
stream->input = vmalloc(block_size);
if (stream->input == NULL)
goto failed2;
stream->output = vmalloc(block_size);
if (stream->output == NULL)
goto failed3;
return stream;
failed3:
vfree(stream->input);
failed2:
kfree(stream);
failed:
ERROR("Failed to initialise LZ4 decompressor\n");
return ERR_PTR(-ENOMEM);
}
static void lz4_free(void *strm)
{
struct squashfs_lz4 *stream = strm;
if (stream) {
vfree(stream->input);
vfree(stream->output);
}
kfree(stream);
}
static int lz4_uncompress(struct squashfs_sb_info *msblk, void *strm,
struct buffer_head **bh, int b, int offset, int length,
struct squashfs_page_actor *output)
{
struct squashfs_lz4 *stream = strm;
void *buff = stream->input, *data;
int avail, i, bytes = length, res;
for (i = 0; i < b; i++) {
avail = min(bytes, msblk->devblksize - offset);
memcpy(buff, bh[i]->b_data + offset, avail);
buff += avail;
bytes -= avail;
offset = 0;
put_bh(bh[i]);
}
res = LZ4_decompress_safe(stream->input, stream->output,
length, output->length);
if (res < 0)
return -EIO;
bytes = res;
data = squashfs_first_page(output);
buff = stream->output;
while (data) {
if (bytes <= PAGE_SIZE) {
memcpy(data, buff, bytes);
break;
}
memcpy(data, buff, PAGE_SIZE);
buff += PAGE_SIZE;
bytes -= PAGE_SIZE;
data = squashfs_next_page(output);
}
squashfs_finish_page(output);
return res;
}
