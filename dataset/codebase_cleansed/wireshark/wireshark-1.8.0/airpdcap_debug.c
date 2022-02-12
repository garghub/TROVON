void print_debug_line(CHAR *function, CHAR *msg, INT level) {
if (level<=AIRPDCAP_DEBUG_USED_LEVEL)
g_warning("dbg(%d)|(%s) %s", level, function, msg);
}
