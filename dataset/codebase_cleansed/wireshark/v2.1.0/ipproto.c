const char *ipprotostr(const int proto) {
const char *s;
if ((s = try_val_to_str_ext(proto, &ipproto_val_ext)) != NULL)
return s;
s = "Unknown";
#ifdef HAVE_GETPROTOBYNUMBER
if (gbl_resolv_flags.mac_name || gbl_resolv_flags.network_name ||
gbl_resolv_flags.transport_name) {
static char buf[128];
struct protoent *pe;
pe = getprotobynumber(proto);
if (pe) {
g_strlcpy(buf, pe->p_name, sizeof(buf));
s = buf;
}
}
#endif
return s;
}
static gboolean ipv6_exthdr_check(int proto)
{
switch (proto) {
case IP_PROTO_HOPOPTS:
case IP_PROTO_ROUTING:
case IP_PROTO_FRAGMENT:
case IP_PROTO_ESP:
case IP_PROTO_AH:
case IP_PROTO_DSTOPTS:
case IP_PROTO_MIPV6:
case IP_PROTO_HIP:
case IP_PROTO_SHIM6:
return TRUE;
break;
default:
break;
}
return FALSE;
}
const char *ipv6extprotostr(int proto)
{
if (ipv6_exthdr_check(proto))
return ipprotostr(proto);
return NULL;
}
