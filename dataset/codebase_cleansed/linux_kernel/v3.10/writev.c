int jffs2_flash_direct_writev(struct jffs2_sb_info *c, const struct kvec *vecs,
unsigned long count, loff_t to, size_t *retlen)
{
if (!jffs2_is_writebuffered(c)) {
if (jffs2_sum_active()) {
int res;
res = jffs2_sum_add_kvec(c, vecs, count, (uint32_t) to);
if (res) {
return res;
}
}
}
return mtd_writev(c->mtd, vecs, count, to, retlen);
}
int jffs2_flash_direct_write(struct jffs2_sb_info *c, loff_t ofs, size_t len,
size_t *retlen, const u_char *buf)
{
int ret;
ret = mtd_write(c->mtd, ofs, len, retlen, buf);
if (jffs2_sum_active()) {
struct kvec vecs[1];
int res;
vecs[0].iov_base = (unsigned char *) buf;
vecs[0].iov_len = len;
res = jffs2_sum_add_kvec(c, vecs, 1, (uint32_t) ofs);
if (res) {
return res;
}
}
return ret;
}
