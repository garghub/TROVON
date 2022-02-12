static void free_workspace(void)
{
vfree(lzo_mem);
vfree(lzo_compress_buf);
}
static int __init alloc_workspace(void)
{
lzo_mem = vmalloc(LZO1X_MEM_COMPRESS);
lzo_compress_buf = vmalloc(lzo1x_worst_compress(PAGE_SIZE));
if (!lzo_mem || !lzo_compress_buf) {
free_workspace();
return -ENOMEM;
}
return 0;
}
static int jffs2_lzo_compress(unsigned char *data_in, unsigned char *cpage_out,
uint32_t *sourcelen, uint32_t *dstlen)
{
size_t compress_size;
int ret;
mutex_lock(&deflate_mutex);
ret = lzo1x_1_compress(data_in, *sourcelen, lzo_compress_buf, &compress_size, lzo_mem);
if (ret != LZO_E_OK)
goto fail;
if (compress_size > *dstlen)
goto fail;
memcpy(cpage_out, lzo_compress_buf, compress_size);
mutex_unlock(&deflate_mutex);
*dstlen = compress_size;
return 0;
fail:
mutex_unlock(&deflate_mutex);
return -1;
}
static int jffs2_lzo_decompress(unsigned char *data_in, unsigned char *cpage_out,
uint32_t srclen, uint32_t destlen)
{
size_t dl = destlen;
int ret;
ret = lzo1x_decompress_safe(data_in, srclen, cpage_out, &dl);
if (ret != LZO_E_OK || dl != destlen)
return -1;
return 0;
}
int __init jffs2_lzo_init(void)
{
int ret;
ret = alloc_workspace();
if (ret < 0)
return ret;
ret = jffs2_register_compressor(&jffs2_lzo_comp);
if (ret)
free_workspace();
return ret;
}
void jffs2_lzo_exit(void)
{
jffs2_unregister_compressor(&jffs2_lzo_comp);
free_workspace();
}
