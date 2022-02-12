const char *ipprotostr(const int proto) {
const char *s;
if ((s = match_strval_ext(proto, &ipproto_val_ext)) != NULL)
return s;
s = "Unknown";
#ifdef HAVE_GETPROTOBYNUMBER
if (gbl_resolv_flags != 0) {
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
