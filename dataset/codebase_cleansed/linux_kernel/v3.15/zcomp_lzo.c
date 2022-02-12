static void *lzo_create(void)
{
return kzalloc(LZO1X_MEM_COMPRESS, GFP_KERNEL);
}
static void lzo_destroy(void *private)
{
kfree(private);
}
static int lzo_compress(const unsigned char *src, unsigned char *dst,
size_t *dst_len, void *private)
{
int ret = lzo1x_1_compress(src, PAGE_SIZE, dst, dst_len, private);
return ret == LZO_E_OK ? 0 : ret;
}
static int lzo_decompress(const unsigned char *src, size_t src_len,
unsigned char *dst)
{
size_t dst_len = PAGE_SIZE;
int ret = lzo1x_decompress_safe(src, src_len, dst, &dst_len);
return ret == LZO_E_OK ? 0 : ret;
}
