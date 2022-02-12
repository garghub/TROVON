int
in_cksum(const vec_t *vec, int veclen)
{
register const guint16 *w;
register int sum = 0;
register int mlen = 0;
int byte_swapped = 0;
union {
guint8 c[2];
guint16 s;
} s_util;
union {
guint16 s[2];
guint32 l;
} l_util;
for (; veclen != 0; vec++, veclen--) {
if (vec->len == 0)
continue;
w = (const guint16 *)(const void *)vec->ptr;
if (mlen == -1) {
s_util.c[1] = *(const guint8 *)w;
sum += s_util.s;
w = (const guint16 *)(const void *)((const guint8 *)w + 1);
mlen = vec->len - 1;
} else
mlen = vec->len;
if ((1 & (unsigned long) w) && (mlen > 0)) {
REDUCE;
sum <<= 8;
s_util.c[0] = *(const guint8 *)w;
w = (const guint16 *)(const void *)((const guint8 *)w + 1);
mlen--;
byte_swapped = 1;
}
while ((mlen -= 32) >= 0) {
sum += w[0]; sum += w[1]; sum += w[2]; sum += w[3];
sum += w[4]; sum += w[5]; sum += w[6]; sum += w[7];
sum += w[8]; sum += w[9]; sum += w[10]; sum += w[11];
sum += w[12]; sum += w[13]; sum += w[14]; sum += w[15];
w += 16;
}
mlen += 32;
while ((mlen -= 8) >= 0) {
sum += w[0]; sum += w[1]; sum += w[2]; sum += w[3];
w += 4;
}
mlen += 8;
if (mlen == 0 && byte_swapped == 0)
continue;
REDUCE;
while ((mlen -= 2) >= 0) {
sum += *w++;
}
if (byte_swapped) {
REDUCE;
sum <<= 8;
byte_swapped = 0;
if (mlen == -1) {
s_util.c[1] = *(const guint8 *)w;
sum += s_util.s;
mlen = 0;
} else
mlen = -1;
} else if (mlen == -1)
s_util.c[0] = *(const guint8 *)w;
}
if (mlen == -1) {
s_util.c[1] = 0;
sum += s_util.s;
}
REDUCE;
return (~sum & 0xffff);
}
guint16
ip_checksum(const guint8 *ptr, int len)
{
vec_t cksum_vec[1];
SET_CKSUM_VEC_PTR(cksum_vec[0], ptr, len);
return in_cksum(&cksum_vec[0], 1);
}
guint16
ip_checksum_tvb(tvbuff_t *tvb, int offset, int len)
{
vec_t cksum_vec[1];
SET_CKSUM_VEC_TVB(cksum_vec[0], tvb, offset, len);
return in_cksum(&cksum_vec[0], 1);
}
guint16
in_cksum_shouldbe(guint16 sum, guint16 computed_sum)
{
guint32 shouldbe;
shouldbe = sum;
shouldbe += g_ntohs(computed_sum);
shouldbe = (shouldbe & 0xFFFF) + (shouldbe >> 16);
shouldbe = (shouldbe & 0xFFFF) + (shouldbe >> 16);
return shouldbe;
}
