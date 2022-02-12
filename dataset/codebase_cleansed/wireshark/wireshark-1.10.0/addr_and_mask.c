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
