static void rtpstream_draw(void *arg _U_)
{
rtpstream_dlg_update(the_tapinfo_struct.strinfo_list);
return;
}
void rtpstream_scan(void)
{
gboolean was_registered = the_tapinfo_struct.is_registered;
if (!the_tapinfo_struct.is_registered)
register_tap_listener_rtp_stream();
the_tapinfo_struct.mode = TAP_ANALYSE;
cf_retap_packets(&cfile);
if (!was_registered)
remove_tap_listener_rtp_stream();
}
gboolean rtpstream_save(rtp_stream_info_t* stream, const gchar *filename)
{
gboolean was_registered = the_tapinfo_struct.is_registered;
the_tapinfo_struct.save_file = ws_fopen(filename, "wb");
if (the_tapinfo_struct.save_file==NULL) {
open_failure_alert_box(filename, errno, TRUE);
return FALSE;
}
rtp_write_header(stream, the_tapinfo_struct.save_file);
if (ferror(the_tapinfo_struct.save_file)) {
write_failure_alert_box(filename, errno);
fclose(the_tapinfo_struct.save_file);
return FALSE;
}
if (!the_tapinfo_struct.is_registered)
register_tap_listener_rtp_stream();
the_tapinfo_struct.mode = TAP_SAVE;
the_tapinfo_struct.filter_stream_fwd = stream;
cf_retap_packets(&cfile);
the_tapinfo_struct.mode = TAP_ANALYSE;
if (!was_registered)
remove_tap_listener_rtp_stream();
if (ferror(the_tapinfo_struct.save_file)) {
write_failure_alert_box(filename, errno);
fclose(the_tapinfo_struct.save_file);
return FALSE;
}
if (fclose(the_tapinfo_struct.save_file) == EOF) {
write_failure_alert_box(filename, errno);
return FALSE;
}
return TRUE;
}
void rtpstream_mark(rtp_stream_info_t* stream_fwd, rtp_stream_info_t* stream_rev)
{
gboolean was_registered = the_tapinfo_struct.is_registered;
if (!the_tapinfo_struct.is_registered)
register_tap_listener_rtp_stream();
the_tapinfo_struct.mode = TAP_MARK;
the_tapinfo_struct.filter_stream_fwd = stream_fwd;
the_tapinfo_struct.filter_stream_rev = stream_rev;
cf_retap_packets(&cfile);
the_tapinfo_struct.mode = TAP_ANALYSE;
if (!was_registered)
remove_tap_listener_rtp_stream();
}
const rtpstream_tapinfo_t* rtpstream_get_info(void)
{
return &the_tapinfo_struct;
}
void
remove_tap_listener_rtp_stream(void)
{
if (the_tapinfo_struct.is_registered) {
remove_tap_listener(&the_tapinfo_struct);
the_tapinfo_struct.is_registered = FALSE;
}
}
void
register_tap_listener_rtp_stream(void)
{
GString *error_string;
if (!the_tapinfo_struct.is_registered) {
error_string = register_tap_listener("rtp", &the_tapinfo_struct,
NULL, 0, rtpstream_reset_cb, rtpstream_packet,
rtpstream_draw);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
the_tapinfo_struct.is_registered = TRUE;
}
}
