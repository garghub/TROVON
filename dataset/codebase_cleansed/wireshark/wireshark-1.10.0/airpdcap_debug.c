void print_debug_line(const CHAR *function, const CHAR *msg, const INT level) {
if (level<=AIRPDCAP_DEBUG_USED_LEVEL)
g_warning("dbg(%d)|(%s) %s", level, function, msg);
}
