gchar *
sna_fid_to_str(const address *addr)
{
gchar *cur;
cur=(gchar *)ep_alloc(14);
sna_fid_to_str_buf(addr, cur, 14);
return cur;
}
void
sna_fid_to_str_buf(const address *addr, gchar *buf, int buf_len)
{
const guint8 *addrdata;
struct sna_fid_type_4_addr sna_fid_type_4_addr;
switch (addr->len) {
case 1:
addrdata = (const guint8 *)addr->data;
g_snprintf(buf, buf_len, "%04X", addrdata[0]);
break;
case 2:
addrdata = (const guint8 *)addr->data;
g_snprintf(buf, buf_len, "%04X", pntoh16(&addrdata[0]));
break;
case SNA_FID_TYPE_4_ADDR_LEN:
memcpy(&sna_fid_type_4_addr, addr->data, SNA_FID_TYPE_4_ADDR_LEN);
g_snprintf(buf, buf_len, "%08X.%04X", sna_fid_type_4_addr.saf,
sna_fid_type_4_addr.ef);
break;
}
}
