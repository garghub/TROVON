void
get_glib_version_info(GString *str)
{
g_string_append(str, "with ");
g_string_append_printf(str,
#ifdef GLIB_MAJOR_VERSION
"GLib %d.%d.%d", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION,
GLIB_MICRO_VERSION);
#else
"GLib (version unknown)");
