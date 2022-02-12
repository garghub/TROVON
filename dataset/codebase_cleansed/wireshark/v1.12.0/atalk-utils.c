gchar *
atalk_addr_to_str(const struct atalk_ddp_addr *addrp)
{
gchar *cur;
cur=(gchar *)ep_alloc(14);
atalk_addr_to_str_buf(addrp, cur, 14);
return cur;
}
void
atalk_addr_to_str_buf(const struct atalk_ddp_addr *addrp, gchar *buf, int buf_len)
{
g_snprintf(buf, buf_len, "%u.%u", addrp->net, addrp->node );
}
