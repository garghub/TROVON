static void rtpstream_draw(void *ti_ptr)
{
rtpstream_tapinfo_t *tapinfo = (rtpstream_tapinfo_t *)ti_ptr;
if (tapinfo && tapinfo->tap_draw) {
tapinfo->tap_draw(tapinfo);
}
return;
}
void rtpstream_scan(rtpstream_tapinfo_t *tapinfo, capture_file *cap_file, const char *fstring)
{
gboolean was_registered;
if (!tapinfo || !cap_file) {
return;
}
was_registered = tapinfo->is_registered;
if (!tapinfo->is_registered)
register_tap_listener_rtp_stream(tapinfo, fstring);
tapinfo->mode = TAP_ANALYSE;
cf_retap_packets(cap_file);
if (!was_registered)
remove_tap_listener_rtp_stream(tapinfo);
}
gboolean rtpstream_save(rtpstream_tapinfo_t *tapinfo, capture_file *cap_file, rtp_stream_info_t* stream, const gchar *filename)
{
gboolean was_registered;
if (!tapinfo) {
return FALSE;
}
was_registered = tapinfo->is_registered;
tapinfo->save_file = ws_fopen(filename, "wb");
if (tapinfo->save_file==NULL) {
open_failure_alert_box(filename, errno, TRUE);
return FALSE;
}
rtp_write_header(stream, tapinfo->save_file);
if (ferror(tapinfo->save_file)) {
write_failure_alert_box(filename, errno);
fclose(tapinfo->save_file);
return FALSE;
}
if (!tapinfo->is_registered)
register_tap_listener_rtp_stream(tapinfo, NULL);
tapinfo->mode = TAP_SAVE;
tapinfo->filter_stream_fwd = stream;
cf_retap_packets(cap_file);
tapinfo->mode = TAP_ANALYSE;
if (!was_registered)
remove_tap_listener_rtp_stream(tapinfo);
if (ferror(tapinfo->save_file)) {
write_failure_alert_box(filename, errno);
fclose(tapinfo->save_file);
return FALSE;
}
if (fclose(tapinfo->save_file) == EOF) {
write_failure_alert_box(filename, errno);
return FALSE;
}
return TRUE;
}
gboolean rtp_stream_info_is_reverse(const rtp_stream_info_t *stream_a, rtp_stream_info_t *stream_b)
{
if (stream_a == NULL || stream_b == NULL)
return FALSE;
if ((addresses_equal(&(stream_a->src_addr), &(stream_b->dest_addr)))
&& (stream_a->src_port == stream_b->dest_port)
&& (addresses_equal(&(stream_a->dest_addr), &(stream_b->src_addr)))
&& (stream_a->dest_port == stream_b->src_port))
return TRUE;
else
return FALSE;
}
void rtpstream_mark(rtpstream_tapinfo_t *tapinfo, capture_file *cap_file, rtp_stream_info_t* stream_fwd, rtp_stream_info_t* stream_rev)
{
gboolean was_registered;
if (!tapinfo) {
return;
}
was_registered = tapinfo->is_registered;
if (!tapinfo->is_registered)
register_tap_listener_rtp_stream(tapinfo, NULL);
tapinfo->mode = TAP_MARK;
tapinfo->filter_stream_fwd = stream_fwd;
tapinfo->filter_stream_rev = stream_rev;
cf_retap_packets(cap_file);
tapinfo->mode = TAP_ANALYSE;
if (!was_registered)
remove_tap_listener_rtp_stream(tapinfo);
}
void
remove_tap_listener_rtp_stream(rtpstream_tapinfo_t *tapinfo)
{
if (tapinfo && tapinfo->is_registered) {
remove_tap_listener(tapinfo);
tapinfo->is_registered = FALSE;
}
}
void
register_tap_listener_rtp_stream(rtpstream_tapinfo_t *tapinfo, const char *fstring)
{
GString *error_string;
if (!tapinfo) {
return;
}
if (!tapinfo->is_registered) {
error_string = register_tap_listener("rtp", tapinfo,
fstring, 0, rtpstream_reset_cb, rtpstream_packet,
rtpstream_draw);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
tapinfo->is_registered = TRUE;
}
}
