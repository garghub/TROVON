static void *zcomp_lz4_create(void)
{
return kzalloc(LZ4_MEM_COMPRESS, GFP_KERNEL);
}
static void zcomp_lz4_destroy(void *private)
{
kfree(private);
}
static int zcomp_lz4_compress(const unsigned char *src, unsigned char *dst,
size_t *dst_len, void *private)
{
return lz4_compress(src, PAGE_SIZE, dst, dst_len, private);
}
static int zcomp_lz4_decompress(const unsigned char *src, size_t src_len,
unsigned char *dst)
{
size_t dst_len = PAGE_SIZE;
return lz4_decompress_unknownoutputsize(src, src_len, dst, &dst_len);
}
