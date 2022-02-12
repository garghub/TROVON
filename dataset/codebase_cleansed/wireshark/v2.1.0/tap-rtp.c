static void
rtp_streams_stat_draw(void *arg _U_)
{
GList *list;
rtp_stream_info_t *strinfo;
gchar *payload_type;
guint32 expected;
gint32 lost;
double perc;
char *savelocale;
char *src_addr, *dst_addr;
printf("========================= RTP Streams ========================\n");
printf("%15s %5s %15s %5s %10s %16s %5s %12s %15s %15s %15s %s\n","Src IP addr", "Port", "Dest IP addr", "Port", "SSRC", "Payload", "Pkts", "Lost", "Max Delta(ms)", "Max Jitter(ms)", "Mean Jitter(ms)", "Problems?");
savelocale = g_strdup(setlocale(LC_NUMERIC, NULL));
setlocale(LC_NUMERIC, "C");
list = the_tapinfo_struct.strinfo_list;
list = g_list_first(list);
while (list)
{
strinfo = (rtp_stream_info_t*)(list->data);
if (strinfo->payload_type > 95) {
if (strinfo->payload_type_name != NULL) {
payload_type = wmem_strdup(NULL, strinfo->payload_type_name);
}else{
payload_type = wmem_strdup_printf(NULL, "Unknown(%u)", strinfo->payload_type);
}
}else{
payload_type = val_to_str_ext_wmem(NULL, strinfo->payload_type, &rtp_payload_type_vals_ext, "Unknown (%u)");
}
expected = (strinfo->rtp_stats.stop_seq_nr + strinfo->rtp_stats.cycles*65536)
- strinfo->rtp_stats.start_seq_nr + 1;
lost = expected - strinfo->rtp_stats.total_nr;
if (expected) {
perc = (double)(lost*100)/(double)expected;
} else {
perc = 0;
}
src_addr = address_to_display(NULL, &(strinfo->src_addr));
dst_addr = address_to_display(NULL, &(strinfo->dest_addr));
printf("%15s %5u %15s %5u 0x%08X %16s %5u %5d (%.1f%%) %15.2f %15.2f %15.2f %s\n",
src_addr,
strinfo->src_port,
dst_addr,
strinfo->dest_port,
strinfo->ssrc,
payload_type,
strinfo->packet_count,
lost, perc,
strinfo->rtp_stats.max_delta,
strinfo->rtp_stats.max_jitter,
strinfo->rtp_stats.mean_jitter,
(strinfo->problem)?"X":"");
list = g_list_next(list);
wmem_free(NULL, src_addr);
wmem_free(NULL, dst_addr);
wmem_free(NULL, payload_type);
}
printf("==============================================================\n");
setlocale(LC_NUMERIC, savelocale);
g_free(savelocale);
}
static void
rtp_streams_stat_init(const char *opt_arg _U_, void *userdata _U_)
{
GString *err_p;
err_p =
register_tap_listener("rtp", &the_tapinfo_struct, NULL, 0,
rtpstream_reset_cb,
rtpstream_packet,
rtp_streams_stat_draw);
if (err_p != NULL)
{
g_string_free(err_p, TRUE);
exit(1);
}
}
void
register_tap_listener_rtp_streams(void)
{
register_stat_tap_ui(&rtp_streams_stat_ui, NULL);
}
