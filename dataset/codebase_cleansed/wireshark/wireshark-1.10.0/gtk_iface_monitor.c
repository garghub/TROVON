static void
gtk_iface_mon_event_cb(const char *iface, int up)
{
int present = 0;
guint ifs, j;
interface_t device;
interface_options interface_opts;
for (ifs = 0; ifs < global_capture_opts.all_ifaces->len; ifs++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, ifs);
if (!strcmp(device.name, iface)) {
present = 1;
if (!up) {
for (j = 0; j < global_capture_opts.ifaces->len; j++) {
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, j);
if (strcmp(interface_opts.name, device.name) == 0) {
g_array_remove_index(global_capture_opts.ifaces, j);
}
}
}
}
}
if (present == up)
return;
refresh_local_interface_lists();
}
static gboolean
gtk_iface_mon_event(GIOChannel *source _U_, GIOCondition condition _U_, gpointer data _U_)
{
iface_mon_event();
return TRUE;
}
int
gtk_iface_mon_start(void)
{
int sock, err;
err = iface_mon_start(&gtk_iface_mon_event_cb);
if (err)
return err;
sock = iface_mon_get_sock();
iface_mon_channel = g_io_channel_unix_new(sock);
g_io_channel_set_encoding(iface_mon_channel, NULL, NULL);
g_io_add_watch(iface_mon_channel,
(GIOCondition)(G_IO_IN|G_IO_ERR|G_IO_HUP),
&gtk_iface_mon_event,
NULL);
return 0;
}
int
gtk_iface_mon_stop(void)
{
iface_mon_stop();
return 0;
}
