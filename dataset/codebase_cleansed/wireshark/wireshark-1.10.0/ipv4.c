ipv4_addr*
ipv4_addr_new(void)
{
ipv4_addr *ipv4;
ipv4 = g_new(ipv4_addr, 1);
return ipv4;
}
void
ipv4_addr_free(ipv4_addr *ipv4)
{
g_free(ipv4);
}
void
ipv4_addr_set_host_order_addr(ipv4_addr *ipv4, const guint32 new_addr)
{
ipv4->addr = new_addr;
}
void
ipv4_addr_set_net_order_addr(ipv4_addr *ipv4, const guint32 new_addr)
{
ipv4->addr = g_ntohl(new_addr);
}
void
ipv4_addr_set_netmask_bits(ipv4_addr *ipv4, const guint new_nmask_bits)
{
static guint32 bitmasks[33] = {
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
g_assert(new_nmask_bits <= 32);
ipv4->nmask = bitmasks[new_nmask_bits];
}
guint32
ipv4_get_net_order_addr(ipv4_addr *ipv4)
{
return g_htonl(ipv4->addr);
}
guint32
ipv4_get_host_order_addr(ipv4_addr *ipv4)
{
return ipv4->addr;
}
void
ipv4_addr_str_buf(const ipv4_addr *ipv4, gchar *buf)
{
guint32 ipv4_host_order = g_htonl(ipv4->addr);
ip_to_str_buf((guint8*)&ipv4_host_order, buf, MAX_IP_STR_LEN);
}
gboolean
ipv4_addr_eq(const ipv4_addr *a, const ipv4_addr *b)
{
guint32 val_a, val_b, nmask;
nmask = MIN(a->nmask, b->nmask);
val_a = a->addr & nmask;
val_b = b->addr & nmask;
return (val_a == val_b);
}
gboolean
ipv4_addr_gt(const ipv4_addr *a, const ipv4_addr *b)
{
guint32 val_a, val_b, nmask;
nmask = MIN(a->nmask, b->nmask);
val_a = a->addr & nmask;
val_b = b->addr & nmask;
return (val_a > val_b);
}
gboolean
ipv4_addr_ge(const ipv4_addr *a, const ipv4_addr *b)
{
guint32 val_a, val_b, nmask;
nmask = MIN(a->nmask, b->nmask);
val_a = a->addr & nmask;
val_b = b->addr & nmask;
return (val_a >= val_b);
}
gboolean
ipv4_addr_lt(const ipv4_addr *a, const ipv4_addr *b)
{
guint32 val_a, val_b, nmask;
nmask = MIN(a->nmask, b->nmask);
val_a = a->addr & nmask;
val_b = b->addr & nmask;
return (val_a < val_b);
}
gboolean
ipv4_addr_le(const ipv4_addr *a, const ipv4_addr *b)
{
guint32 val_a, val_b, nmask;
nmask = MIN(a->nmask, b->nmask);
val_a = a->addr & nmask;
val_b = b->addr & nmask;
return (val_a <= val_b);
}
