static void
console_log_handler(const char *log_domain, GLogLevelFlags log_level,
const char *message, gpointer user_data _U_)
{
time_t curr;
struct tm *today;
const char *level;
if((log_level & G_LOG_LEVEL_MASK & prefs.console_log_level) == 0 &&
prefs.console_log_level != 0) {
return;
}
#ifdef _WIN32
if (prefs.gui_console_open != console_open_never || log_level & G_LOG_LEVEL_ERROR) {
create_console();
}
if (get_has_console()) {
#endif
switch(log_level & G_LOG_LEVEL_MASK) {
case G_LOG_LEVEL_ERROR:
level = "Err ";
break;
case G_LOG_LEVEL_CRITICAL:
level = "Crit";
break;
case G_LOG_LEVEL_WARNING:
level = "Warn";
break;
case G_LOG_LEVEL_MESSAGE:
level = "Msg ";
break;
case G_LOG_LEVEL_INFO:
level = "Info";
break;
case G_LOG_LEVEL_DEBUG:
level = "Dbg ";
break;
default:
fprintf(stderr, "unknown log_level %u\n", log_level);
level = NULL;
g_assert_not_reached();
}
time(&curr);
today = localtime(&curr);
fprintf(stderr, "%02u:%02u:%02u %8s %s %s\n",
today->tm_hour, today->tm_min, today->tm_sec,
log_domain != NULL ? log_domain : "",
level, message);
#ifdef _WIN32
if(log_level & G_LOG_LEVEL_ERROR) {
printf("\n\nPress any key to exit\n");
_getch();
}
} else {
g_log_default_handler(log_domain, log_level, message, user_data);
}
#endif
}
void set_console_log_handler(void)
{
GLogLevelFlags log_flags;
log_flags = (GLogLevelFlags)
(G_LOG_LEVEL_ERROR|
G_LOG_LEVEL_CRITICAL|
G_LOG_LEVEL_WARNING|
G_LOG_LEVEL_MESSAGE|
G_LOG_LEVEL_INFO|
G_LOG_LEVEL_DEBUG|
G_LOG_FLAG_FATAL|
G_LOG_FLAG_RECURSION);
g_log_set_handler(NULL,
log_flags,
console_log_handler, NULL );
g_log_set_handler(LOG_DOMAIN_MAIN,
log_flags,
console_log_handler, NULL );
#ifdef HAVE_LIBPCAP
g_log_set_handler(LOG_DOMAIN_CAPTURE,
log_flags,
console_log_handler, NULL );
g_log_set_handler(LOG_DOMAIN_CAPTURE_CHILD,
log_flags,
console_log_handler, NULL );
#endif
}
