static const char *get_appcast_update_url(software_update_channel_e chan) {
const char *chan_name;
const char *arch = "x86";
if (!update_url_str) {
update_url_str = g_string_new("");
}
if (sizeof(arch) != 4) {
arch = "x86-64";
}
switch (chan) {
case UPDATE_CHANNEL_DEVELOPMENT:
chan_name = "development";
break;
default:
chan_name = "stable";
break;
}
g_string_printf(update_url_str, "https://www.wireshark.org/%s/%u/%s/%s/%s/%s/en-US/%s.xml",
SU_SCHEMA_PREFIX,
SU_SCHEMA_VERSION,
SU_APPLICATION,
VERSION,
SU_OSNAME,
arch,
chan_name);
return update_url_str->str;
}
void
software_update_init(void) {
const char *update_url = get_appcast_update_url(prefs.gui_update_channel);
win_sparkle_set_registry_path("Software\\Wireshark\\WinSparkle Settings");
win_sparkle_set_appcast_url(update_url);
win_sparkle_set_automatic_check_for_updates(prefs.gui_update_enabled ? 1 : 0);
win_sparkle_set_update_check_interval(prefs.gui_update_interval);
win_sparkle_set_can_shutdown_callback(software_update_can_shutdown_callback);
win_sparkle_set_shutdown_request_callback(software_update_shutdown_request_callback);
win_sparkle_init();
}
void
software_update_check(void) {
win_sparkle_check_update_with_ui();
}
extern void software_update_cleanup(void) {
win_sparkle_cleanup();
}
void
software_update_init(void) {
}
void
software_update_check(void) {
}
void software_update_cleanup(void) {
}
int software_update_can_shutdown_callback(void) {
return FALSE;
}
void software_update_shutdown_request_callback(void) {
}
