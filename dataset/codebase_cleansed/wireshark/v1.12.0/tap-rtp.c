static void
rtp_streams_stat_draw(void *arg _U_)
{
GList *list;
rtp_stream_info_t* strinfo;
gchar *payload_type;
guint32 expected;
gint32 lost;
double perc;
char *savelocale;
printf("========================= RTP Streams ========================\n");
printf("%15s %5s %15s %5s %10s %16s %5s %12s %15s %15s %15s %s\n","Src IP addr", "Port", "Dest IP addr", "Port", "SSRC", "Payload", "Pkts", "Lost", "Max Delta(ms)", "Max Jitter(ms)", "Mean Jitter(ms)", "Problems?");
savelocale = g_strdup(setlocale(LC_NUMERIC, NULL));
setlocale(LC_NUMERIC, "C");
list = the_tapinfo_struct.strinfo_list;
list = g_list_first(list);
while (list)
{
strinfo = (rtp_stream_info_t*)(list->data);
if(strinfo->pt>95){
if(strinfo->info_payload_type_str != NULL){
payload_type = g_strdup(strinfo->info_payload_type_str);
}else{
payload_type = g_strdup_printf("Unknown(%u)",strinfo->pt);
}
}else{
payload_type = g_strdup(val_to_str_ext(strinfo->pt, &rtp_payload_type_vals_ext,
"Unknown (%u)"));
}
expected = (strinfo->rtp_stats.stop_seq_nr + strinfo->rtp_stats.cycles*65536)
- strinfo->rtp_stats.start_seq_nr + 1;
lost = expected - strinfo->rtp_stats.total_nr;
if (expected){
perc = (double)(lost*100)/(double)expected;
} else {
perc = 0;
}
printf("%15s %5u %15s %5u 0x%08X %16s %5u %5d (%.1f%%) %15.2f %15.2f %15.2f %s\n",
ep_address_to_display(&(strinfo->src_addr)),
strinfo->src_port,
ep_address_to_display(&(strinfo->dest_addr)),
strinfo->dest_port,
strinfo->ssrc,
payload_type,
strinfo->npackets,
lost, perc,
strinfo->rtp_stats.max_delta,
strinfo->rtp_stats.max_jitter,
strinfo->rtp_stats.mean_jitter,
(strinfo->problem)?"X":"");
list = g_list_next(list);
g_free(payload_type);
}
printf("==============================================================\n");
setlocale(LC_NUMERIC, savelocale);
g_free(savelocale);
}
static void
rtp_streams_stat_init(const char *opt_arg _U_, void* userdata _U_)
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
register_stat_cmd_arg("rtp,streams", rtp_streams_stat_init,NULL);
}
