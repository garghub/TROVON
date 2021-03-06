static void
iousers_draw(void *arg)
{
conv_hash_t *hash = (conv_hash_t*)arg;
io_users_t *iu = (io_users_t *)hash->user_data;
conv_item_t *iui;
guint64 last_frames, max_frames;
struct tm * tm_time;
guint i;
gboolean display_ports = (!strncmp(iu->type, "TCP", 3) || !strncmp(iu->type, "UDP", 3) || !strncmp(iu->type, "SCTP", 4)) ? TRUE : FALSE;
printf("================================================================================\n");
printf("%s Conversations\n", iu->type);
printf("Filter:%s\n", iu->filter ? iu->filter : "<No Filter>");
switch (timestamp_get_type()) {
case TS_ABSOLUTE:
case TS_UTC:
printf("%s | <- | | -> | | Total | Absolute Time | Duration |\n",
display_ports ? " " : "");
printf("%s | Frames Bytes | | Frames Bytes | | Frames Bytes | Start | |\n",
display_ports ? " " : "");
break;
case TS_ABSOLUTE_WITH_YMD:
case TS_ABSOLUTE_WITH_YDOY:
case TS_UTC_WITH_YMD:
case TS_UTC_WITH_YDOY:
printf("%s | <- | | -> | | Total | Absolute Date | Duration |\n",
display_ports ? " " : "");
printf("%s | Frames Bytes | | Frames Bytes | | Frames Bytes | Start | |\n",
display_ports ? " " : "");
break;
case TS_RELATIVE:
case TS_NOT_SET:
default:
printf("%s | <- | | -> | | Total | Relative | Duration |\n",
display_ports ? " " : "");
printf("%s | Frames Bytes | | Frames Bytes | | Frames Bytes | Start | |\n",
display_ports ? " " : "");
break;
}
max_frames = UINT_MAX;
do {
last_frames = 0;
for (i=0; (iu->hash.conv_array && i < iu->hash.conv_array->len); i++) {
guint64 tot_frames;
iui = &g_array_index(iu->hash.conv_array, conv_item_t, i);
tot_frames = iui->rx_frames + iui->tx_frames;
if ((tot_frames > last_frames) && (tot_frames < max_frames)) {
last_frames = tot_frames;
}
}
for (i=0; (iu->hash.conv_array && i < iu->hash.conv_array->len); i++) {
guint64 tot_frames;
char *src_addr, *dst_addr;
iui = &g_array_index(iu->hash.conv_array, conv_item_t, i);
tot_frames = iui->rx_frames + iui->tx_frames;
if (tot_frames == last_frames) {
src_addr = get_conversation_address(NULL, &iui->src_address, TRUE);
dst_addr = get_conversation_address(NULL, &iui->dst_address, TRUE);
if (display_ports) {
char *src, *dst, *src_port, *dst_port;
src_port = get_conversation_port(NULL, iui->src_port, iui->ptype, TRUE);
dst_port = get_conversation_port(NULL, iui->dst_port, iui->ptype, TRUE);
src = wmem_strconcat(NULL, src_addr, ":", src_port, NULL);
dst = wmem_strconcat(NULL, dst_addr, ":", dst_port, NULL);
printf("%-26s <-> %-26s %6" G_GINT64_MODIFIER "u %9" G_GINT64_MODIFIER
"u %6" G_GINT64_MODIFIER "u %9" G_GINT64_MODIFIER "u %6"
G_GINT64_MODIFIER "u %9" G_GINT64_MODIFIER "u ",
src, dst,
iui->rx_frames, iui->rx_bytes,
iui->tx_frames, iui->tx_bytes,
iui->tx_frames+iui->rx_frames,
iui->tx_bytes+iui->rx_bytes
);
wmem_free(NULL, src_port);
wmem_free(NULL, dst_port);
wmem_free(NULL, src);
wmem_free(NULL, dst);
} else {
printf("%-20s <-> %-20s %6" G_GINT64_MODIFIER "u %9" G_GINT64_MODIFIER
"u %6" G_GINT64_MODIFIER "u %9" G_GINT64_MODIFIER "u %6"
G_GINT64_MODIFIER "u %9" G_GINT64_MODIFIER "u ",
src_addr, dst_addr,
iui->rx_frames, iui->rx_bytes,
iui->tx_frames, iui->tx_bytes,
iui->tx_frames+iui->rx_frames,
iui->tx_bytes+iui->rx_bytes
);
}
wmem_free(NULL, src_addr);
wmem_free(NULL, dst_addr);
switch (timestamp_get_type()) {
case TS_ABSOLUTE:
tm_time = localtime(&iui->start_abs_time.secs);
printf("%02d:%02d:%02d %12.4f\n",
tm_time->tm_hour,
tm_time->tm_min,
tm_time->tm_sec,
nstime_to_sec(&iui->stop_time) - nstime_to_sec(&iui->start_time));
break;
case TS_ABSOLUTE_WITH_YMD:
tm_time = localtime(&iui->start_abs_time.secs);
printf("%04d-%02d-%02d %02d:%02d:%02d %12.4f\n",
tm_time->tm_year + 1900,
tm_time->tm_mon + 1,
tm_time->tm_mday,
tm_time->tm_hour,
tm_time->tm_min,
tm_time->tm_sec,
nstime_to_sec(&iui->stop_time) - nstime_to_sec(&iui->start_time));
break;
case TS_ABSOLUTE_WITH_YDOY:
tm_time = localtime(&iui->start_abs_time.secs);
printf("%04d/%03d %02d:%02d:%02d %12.4f\n",
tm_time->tm_year + 1900,
tm_time->tm_yday + 1,
tm_time->tm_hour,
tm_time->tm_min,
tm_time->tm_sec,
nstime_to_sec(&iui->stop_time) - nstime_to_sec(&iui->start_time));
break;
case TS_UTC:
tm_time = gmtime(&iui->start_abs_time.secs);
printf("%02d:%02d:%02d %12.4f\n",
tm_time->tm_hour,
tm_time->tm_min,
tm_time->tm_sec,
nstime_to_sec(&iui->stop_time) - nstime_to_sec(&iui->start_time));
break;
case TS_UTC_WITH_YMD:
tm_time = gmtime(&iui->start_abs_time.secs);
printf("%04d-%02d-%02d %02d:%02d:%02d %12.4f\n",
tm_time->tm_year + 1900,
tm_time->tm_mon + 1,
tm_time->tm_mday,
tm_time->tm_hour,
tm_time->tm_min,
tm_time->tm_sec,
nstime_to_sec(&iui->stop_time) - nstime_to_sec(&iui->start_time));
break;
case TS_UTC_WITH_YDOY:
tm_time = gmtime(&iui->start_abs_time.secs);
printf("%04d/%03d %02d:%02d:%02d %12.4f\n",
tm_time->tm_year + 1900,
tm_time->tm_yday + 1,
tm_time->tm_hour,
tm_time->tm_min,
tm_time->tm_sec,
nstime_to_sec(&iui->stop_time) - nstime_to_sec(&iui->start_time));
break;
case TS_RELATIVE:
case TS_NOT_SET:
default:
printf("%14.9f %12.4f\n",
nstime_to_sec(&iui->start_time),
nstime_to_sec(&iui->stop_time) - nstime_to_sec(&iui->start_time)
);
break;
}
}
}
max_frames = last_frames;
} while (last_frames);
printf("================================================================================\n");
}
void init_iousers(struct register_ct *ct, const char *filter)
{
io_users_t *iu;
GString *error_string;
iu = g_new0(io_users_t, 1);
iu->type = proto_get_protocol_short_name(find_protocol_by_id(get_conversation_proto_id(ct)));
iu->filter = g_strdup(filter);
iu->hash.user_data = iu;
error_string = register_tap_listener(proto_get_protocol_filter_name(get_conversation_proto_id(ct)), &iu->hash, filter, 0, NULL, get_conversation_packet_func(ct), iousers_draw);
if (error_string) {
g_free(iu);
fprintf(stderr, "tshark: Couldn't register conversations tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
