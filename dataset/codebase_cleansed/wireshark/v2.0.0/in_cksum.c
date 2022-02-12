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
