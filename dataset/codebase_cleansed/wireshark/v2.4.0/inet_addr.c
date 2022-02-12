static inline gboolean
_inet_pton(int af, const gchar *src, gpointer dst)
{
gint ret;
ret = inet_pton(af, src, dst);
g_assert(ret >= 0);
return ret == 1;
}
const gchar *
ws_inet_ntop4(gconstpointer src, gchar *dst, guint dst_size)
{
return inet_ntop(AF_INET, src, dst, dst_size);
}
gboolean
ws_inet_pton4(const gchar *src, guint32 *dst)
{
return _inet_pton(AF_INET, src, dst);
}
const gchar *
ws_inet_ntop6(gconstpointer src, gchar *dst, guint dst_size)
{
return inet_ntop(AF_INET6, src, dst, dst_size);
}
gboolean
ws_inet_pton6(const gchar *src, struct e_in6_addr *dst)
{
return _inet_pton(AF_INET6, src, dst);
}
