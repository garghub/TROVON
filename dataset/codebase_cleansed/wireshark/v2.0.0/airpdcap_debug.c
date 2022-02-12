void print_debug_line(const CHAR *function, const CHAR *msg, const INT level) {\r\nif (level<=AIRPDCAP_DEBUG_USED_LEVEL)\r\ng_warning("dbg(%d)|(%s) %s", level, function, msg);\r\n}
