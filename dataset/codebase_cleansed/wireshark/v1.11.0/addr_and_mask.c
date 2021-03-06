guint32
ip_get_subnet_mask(const guint32 mask_length)
{
static guint32 masks[33] = {
0x00000000,
0x80000000, 0xc0000000, 0xe0000000, 0xf0000000,
0xf8000000, 0xfc000000, 0xfe000000, 0xff000000,
0xff800000, 0xffc00000, 0xffe00000, 0xfff00000,
0xfff80000, 0xfffc0000, 0xfffe0000, 0xffff0000,
0xffff8000, 0xffffc000, 0xffffe000, 0xfffff000,
0xfffff800, 0xfffffc00, 0xfffffe00, 0xffffff00,
0xffffff80, 0xffffffc0, 0xffffffe0, 0xfffffff0,
0xfffffff8, 0xfffffffc, 0xfffffffe, 0xffffffff,
};
g_assert(mask_length <= 32);
return masks[mask_length];
}
int
ipv4_addr_and_mask(tvbuff_t *tvb, int offset, guint8 *addr, guint32 prefix_len)
{
guint32 addr_len;
if (prefix_len > 32)
return -1;
addr_len = (prefix_len + 7) / 8;
memset(addr, 0, 4);
tvb_memcpy(tvb, addr, offset, addr_len);
if (prefix_len % 8)
addr[addr_len - 1] &= ((0xff00 >> (prefix_len % 8)) & 0xff);
return addr_len;
}
int
ipv6_addr_and_mask(tvbuff_t *tvb, int offset, struct e_in6_addr *addr,
guint32 prefix_len)
{
guint32 addr_len;
if (prefix_len > 128)
return -1;
addr_len = (prefix_len + 7) / 8;
memset(addr->bytes, 0, 16);
tvb_memcpy(tvb, addr->bytes, offset, addr_len);
if (prefix_len % 8) {
addr->bytes[addr_len - 1] &=
((0xff00 >> (prefix_len % 8)) & 0xff);
}
return addr_len;
}
