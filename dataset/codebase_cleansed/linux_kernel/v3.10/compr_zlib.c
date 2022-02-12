static int __init alloc_workspaces(void)
{
def_strm.workspace = vmalloc(zlib_deflate_workspacesize(MAX_WBITS,
MAX_MEM_LEVEL));
if (!def_strm.workspace)
return -ENOMEM;
jffs2_dbg(1, "Allocated %d bytes for deflate workspace\n",
zlib_deflate_workspacesize(MAX_WBITS, MAX_MEM_LEVEL));
inf_strm.workspace = vmalloc(zlib_inflate_workspacesize());
if (!inf_strm.workspace) {
vfree(def_strm.workspace);
return -ENOMEM;
}
jffs2_dbg(1, "Allocated %d bytes for inflate workspace\n",
zlib_inflate_workspacesize());
return 0;
}
static void free_workspaces(void)
{
vfree(def_strm.workspace);
vfree(inf_strm.workspace);
}
static int jffs2_zlib_compress(unsigned char *data_in,
unsigned char *cpage_out,
uint32_t *sourcelen, uint32_t *dstlen)
{
int ret;
if (*dstlen <= STREAM_END_SPACE)
return -1;
mutex_lock(&deflate_mutex);
if (Z_OK != zlib_deflateInit(&def_strm, 3)) {
pr_warn("deflateInit failed\n");
mutex_unlock(&deflate_mutex);
return -1;
}
def_strm.next_in = data_in;
def_strm.total_in = 0;
def_strm.next_out = cpage_out;
def_strm.total_out = 0;
while (def_strm.total_out < *dstlen - STREAM_END_SPACE && def_strm.total_in < *sourcelen) {
def_strm.avail_out = *dstlen - (def_strm.total_out + STREAM_END_SPACE);
def_strm.avail_in = min((unsigned)(*sourcelen-def_strm.total_in), def_strm.avail_out);
jffs2_dbg(1, "calling deflate with avail_in %d, avail_out %d\n",
def_strm.avail_in, def_strm.avail_out);
ret = zlib_deflate(&def_strm, Z_PARTIAL_FLUSH);
jffs2_dbg(1, "deflate returned with avail_in %d, avail_out %d, total_in %ld, total_out %ld\n",
def_strm.avail_in, def_strm.avail_out,
def_strm.total_in, def_strm.total_out);
if (ret != Z_OK) {
jffs2_dbg(1, "deflate in loop returned %d\n", ret);
zlib_deflateEnd(&def_strm);
mutex_unlock(&deflate_mutex);
return -1;
}
}
def_strm.avail_out += STREAM_END_SPACE;
def_strm.avail_in = 0;
ret = zlib_deflate(&def_strm, Z_FINISH);
zlib_deflateEnd(&def_strm);
if (ret != Z_STREAM_END) {
jffs2_dbg(1, "final deflate returned %d\n", ret);
ret = -1;
goto out;
}
if (def_strm.total_out >= def_strm.total_in) {
jffs2_dbg(1, "zlib compressed %ld bytes into %ld; failing\n",
def_strm.total_in, def_strm.total_out);
ret = -1;
goto out;
}
jffs2_dbg(1, "zlib compressed %ld bytes into %ld\n",
def_strm.total_in, def_strm.total_out);
*dstlen = def_strm.total_out;
*sourcelen = def_strm.total_in;
ret = 0;
out:
mutex_unlock(&deflate_mutex);
return ret;
}
static int jffs2_zlib_decompress(unsigned char *data_in,
unsigned char *cpage_out,
uint32_t srclen, uint32_t destlen)
{
int ret;
int wbits = MAX_WBITS;
mutex_lock(&inflate_mutex);
inf_strm.next_in = data_in;
inf_strm.avail_in = srclen;
inf_strm.total_in = 0;
inf_strm.next_out = cpage_out;
inf_strm.avail_out = destlen;
inf_strm.total_out = 0;
if (srclen > 2 && !(data_in[1] & PRESET_DICT) &&
((data_in[0] & 0x0f) == Z_DEFLATED) &&
!(((data_in[0]<<8) + data_in[1]) % 31)) {
jffs2_dbg(2, "inflate skipping adler32\n");
wbits = -((data_in[0] >> 4) + 8);
inf_strm.next_in += 2;
inf_strm.avail_in -= 2;
} else {
jffs2_dbg(1, "inflate not skipping adler32\n");
}
if (Z_OK != zlib_inflateInit2(&inf_strm, wbits)) {
pr_warn("inflateInit failed\n");
mutex_unlock(&inflate_mutex);
return 1;
}
while((ret = zlib_inflate(&inf_strm, Z_FINISH)) == Z_OK)
;
if (ret != Z_STREAM_END) {
pr_notice("inflate returned %d\n", ret);
}
zlib_inflateEnd(&inf_strm);
mutex_unlock(&inflate_mutex);
return 0;
}
int __init jffs2_zlib_init(void)
{
int ret;
ret = alloc_workspaces();
if (ret)
return ret;
ret = jffs2_register_compressor(&jffs2_zlib_comp);
if (ret)
free_workspaces();
return ret;
}
void jffs2_zlib_exit(void)
{
jffs2_unregister_compressor(&jffs2_zlib_comp);
free_workspaces();
}
