static gboolean
nettrace_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
struct Buffer *frame_buffer_saved;
gboolean result;
nettrace_3gpp_32_423_file_info_t *file_info = (nettrace_3gpp_32_423_file_info_t *)wth->priv;
frame_buffer_saved = file_info->wth_tmp_file->frame_buffer;
file_info->wth_tmp_file->frame_buffer = wth->frame_buffer;
result = wtap_read(file_info->wth_tmp_file, err, err_info, data_offset);
file_info->wth_tmp_file->frame_buffer = frame_buffer_saved;
if (!result)
return result;
wth->phdr.rec_type = file_info->wth_tmp_file->phdr.rec_type;
wth->phdr.presence_flags = file_info->wth_tmp_file->phdr.presence_flags;
wth->phdr.ts = file_info->wth_tmp_file->phdr.ts;
wth->phdr.caplen = file_info->wth_tmp_file->phdr.caplen;
wth->phdr.len = file_info->wth_tmp_file->phdr.len;
wth->phdr.pkt_encap = file_info->wth_tmp_file->phdr.pkt_encap;
wth->phdr.pkt_tsprec = file_info->wth_tmp_file->phdr.pkt_tsprec;
wth->phdr.interface_id = file_info->wth_tmp_file->phdr.interface_id;
wth->phdr.opt_comment = file_info->wth_tmp_file->phdr.opt_comment;
wth->phdr.drop_count = file_info->wth_tmp_file->phdr.drop_count;
wth->phdr.pack_flags = file_info->wth_tmp_file->phdr.pack_flags;
wth->phdr.ft_specific_data = file_info->wth_tmp_file->phdr.ft_specific_data;
return result;
}
static gboolean
nettrace_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
struct Buffer *frame_buffer_saved;
gboolean result;
nettrace_3gpp_32_423_file_info_t *file_info = (nettrace_3gpp_32_423_file_info_t *)wth->priv;
frame_buffer_saved = file_info->wth_tmp_file->frame_buffer;
file_info->wth_tmp_file->frame_buffer = wth->frame_buffer;
result = wtap_seek_read(file_info->wth_tmp_file, seek_off, phdr, buf, err, err_info);
file_info->wth_tmp_file->frame_buffer = frame_buffer_saved;
return result;
}
static void
nettrace_close(wtap *wth)
{
nettrace_3gpp_32_423_file_info_t *file_info = (nettrace_3gpp_32_423_file_info_t *)wth->priv;
wtap_close(file_info->wth_tmp_file);
wth->shb_hdr.opt_comment = NULL;
wth->shb_hdr.shb_hardware = NULL;
wth->shb_hdr.shb_os = NULL;
wth->shb_hdr.shb_user_appl = NULL;
ws_unlink(file_info->tmpname);
}
static guint8*
nettrace_parse_begin_time(guint8 *curr_pos, struct wtap_pkthdr *phdr)
{
int year, month, day, hour, minute, second, ms, UTCdiffh, UTCdiffm;
int scan_found;
struct tm tm;
guint8 *prev_pos, *next_pos;
int length;
prev_pos = curr_pos;
next_pos = strstr(curr_pos, "\"/>");
length = (int)(next_pos - prev_pos);
if (length < 2) {
return next_pos + 3;
}
scan_found = sscanf(curr_pos, "%4u-%2u-%2uT%2u:%2u:%2u%3d:%2u",
&year, &month, &day, &hour, &minute, &second, &UTCdiffh, &UTCdiffm);
phdr->ts.nsecs = 0;
if (scan_found != 8) {
scan_found = sscanf(curr_pos, "%4u-%2u-%2uT%2u:%2u:%2u,%3u%3d:%2u",
&year, &month, &day, &hour, &minute, &second, &ms, &UTCdiffh, &UTCdiffm);
if (scan_found == 9) {
phdr->ts.nsecs = ms * 1000;
scan_found = 8;
} else {
g_warning("Failed to parse second time format, scan_found %u", scan_found);
scan_found = 0;
}
}
if (scan_found == 8) {
guint UTCdiffsec;
tm.tm_year = year - 1900;
tm.tm_mon = month - 1;
tm.tm_mday = day;
tm.tm_hour = hour;
tm.tm_min = minute;
tm.tm_sec = second;
tm.tm_isdst = -1;
phdr->presence_flags = WTAP_HAS_TS;
phdr->ts.secs = mktime(&tm);
UTCdiffsec = (abs(UTCdiffh) * 60 * 60) + (UTCdiffm * 60);
if (UTCdiffh < 0) {
phdr->ts.secs = phdr->ts.secs - UTCdiffsec;
} else {
phdr->ts.secs = phdr->ts.secs + UTCdiffsec;
}
} else {
phdr->presence_flags = 0;
phdr->ts.secs = 0;
phdr->ts.nsecs = 0;
g_warning("Failed to parse time , scan_found %u", scan_found);
}
return curr_pos;
}
static wtap_open_return_val
write_packet_data(wtap_dumper *wdh, struct wtap_pkthdr *phdr, int *err, gchar **err_info, guint8 *file_buf, time_t start_time, int ms, exported_pdu_info_t *exported_pdu_info)
{
char *curr_pos, *next_pos;
char proto_name_str[16];
int tag_str_len = 0;
int proto_str_len, raw_data_len, pkt_data_len, exp_pdu_tags_len, i, j;
guint8 *packet_buf;
gchar chr;
gint val1, val2;
gboolean port_type_defined = FALSE;
memset(proto_name_str, 0, sizeof(proto_name_str));
curr_pos = strstr(file_buf, "protocol=\"");
if (!curr_pos){
return WTAP_OPEN_ERROR;
}
curr_pos = curr_pos + 10;
next_pos = strstr(curr_pos, "\"");
proto_str_len = (int)(next_pos - curr_pos);
if (proto_str_len > 15){
return WTAP_OPEN_ERROR;
}
g_strlcpy(proto_name_str, curr_pos, proto_str_len+1);
ascii_strdown_inplace(proto_name_str);
if (strcmp(proto_name_str, "gtpv2-c") == 0){
proto_name_str[5] = '\0';
proto_name_str[6] = '\0';
proto_str_len = 5;
}
if (strcmp(proto_name_str, "nas") == 0){
g_strlcpy(proto_name_str, "nas-eps_plain", 14);
proto_name_str[13] = '\0';
proto_str_len = 13;
}
curr_pos = strstr(next_pos, ">") + 1;
next_pos = strstr(next_pos, "<");
raw_data_len = (int)(next_pos - curr_pos);
tag_str_len = (proto_str_len + 3) & 0xfffffffc;
exp_pdu_tags_len = tag_str_len + 4;
if ((exported_pdu_info->precense_flags & EXP_PDU_TAG_IP_SRC_BIT) == EXP_PDU_TAG_IP_SRC_BIT) {
exp_pdu_tags_len += 4 + EXP_PDU_TAG_IPV4_SRC_LEN;
}
if ((exported_pdu_info->precense_flags & EXP_PDU_TAG_SRC_PORT_BIT) == EXP_PDU_TAG_SRC_PORT_BIT) {
if (!port_type_defined) {
exp_pdu_tags_len += 4 + EXP_PDU_TAG_PORT_TYPE_LEN;
port_type_defined = TRUE;
}
exp_pdu_tags_len += 4 + EXP_PDU_TAG_SRC_PORT_LEN;
}
if ((exported_pdu_info->precense_flags & EXP_PDU_TAG_IP_DST_BIT) == EXP_PDU_TAG_IP_DST_BIT) {
exp_pdu_tags_len += 4 + EXP_PDU_TAG_IPV4_DST_LEN;
}
if ((exported_pdu_info->precense_flags & EXP_PDU_TAG_DST_PORT_BIT) == EXP_PDU_TAG_DST_PORT_BIT) {
if (!port_type_defined) {
exp_pdu_tags_len += 4 + EXP_PDU_TAG_PORT_TYPE_LEN;
}
exp_pdu_tags_len += 4 + EXP_PDU_TAG_SRC_PORT_LEN;
}
port_type_defined = FALSE;
pkt_data_len = raw_data_len / 2;
packet_buf = (guint8 *)g_malloc0(pkt_data_len + exp_pdu_tags_len +4);
packet_buf[0] = 0;
packet_buf[1] = 12;
packet_buf[2] = 0;
packet_buf[3] = tag_str_len;
for (i = 4, j = 0; j < tag_str_len; i++, j++){
packet_buf[i] = proto_name_str[j];
}
if ((exported_pdu_info->precense_flags & EXP_PDU_TAG_IP_SRC_BIT) == EXP_PDU_TAG_IP_SRC_BIT) {
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_IPV4_SRC;
i++;
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_IPV4_SRC_LEN; ;
i++;
packet_buf[i] = exported_pdu_info->src_ipv4_d1;
i++;
packet_buf[i] = exported_pdu_info->src_ipv4_d2;
i++;
packet_buf[i] = exported_pdu_info->src_ipv4_d3;
i++;
packet_buf[i] = exported_pdu_info->src_ipv4_d4;
i++;
}
if ((exported_pdu_info->precense_flags & EXP_PDU_TAG_SRC_PORT_BIT) == EXP_PDU_TAG_SRC_PORT_BIT) {
if (!port_type_defined) {
port_type_defined = TRUE;
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_PORT_TYPE;
i++;
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_PORT_TYPE_LEN; ;
i++;
packet_buf[i] = (exported_pdu_info->ptype & 0xff000000) >> 24;
i++;
packet_buf[i] = (exported_pdu_info->ptype & 0x00ff0000) >> 16;
i++;
packet_buf[i] = (exported_pdu_info->ptype & 0x0000ff00) >> 8;
i++;
packet_buf[i] = (exported_pdu_info->ptype & 0x000000ff);
i++;
}
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_SRC_PORT;
i++;
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_SRC_PORT_LEN; ;
i++;
packet_buf[i] = (exported_pdu_info->src_port & 0xff000000) >> 24;
i++;
packet_buf[i] = (exported_pdu_info->src_port & 0x00ff0000) >> 16;
i++;
packet_buf[i] = (exported_pdu_info->src_port & 0x0000ff00) >> 8;
i++;
packet_buf[i] = (exported_pdu_info->src_port & 0x000000ff);
i++;
}
if ((exported_pdu_info->precense_flags & EXP_PDU_TAG_IP_DST_BIT) == EXP_PDU_TAG_IP_DST_BIT) {
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_IPV4_DST;
i++;
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_IPV4_DST_LEN; ;
i++;
packet_buf[i] = exported_pdu_info->dst_ipv4_d1;
i++;
packet_buf[i] = exported_pdu_info->dst_ipv4_d2;
i++;
packet_buf[i] = exported_pdu_info->dst_ipv4_d3;
i++;
packet_buf[i] = exported_pdu_info->dst_ipv4_d4;
i++;
}
if ((exported_pdu_info->precense_flags & EXP_PDU_TAG_DST_PORT_BIT) == EXP_PDU_TAG_DST_PORT_BIT) {
if (!port_type_defined) {
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_PORT_TYPE;
i++;
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_PORT_TYPE_LEN; ;
i++;
packet_buf[i] = (exported_pdu_info->ptype & 0xff000000) >> 24;
i++;
packet_buf[i] = (exported_pdu_info->ptype & 0x00ff0000) >> 16;
i++;
packet_buf[i] = (exported_pdu_info->ptype & 0x0000ff00) >> 8;
i++;
packet_buf[i] = (exported_pdu_info->ptype & 0x000000ff);
i++;
}
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_DST_PORT;
i++;
packet_buf[i] = 0;
i++;
packet_buf[i] = EXP_PDU_TAG_DST_PORT_LEN; ;
i++;
packet_buf[i] = (exported_pdu_info->src_port & 0xff000000) >> 24;
i++;
packet_buf[i] = (exported_pdu_info->src_port & 0x00ff0000) >> 16;
i++;
packet_buf[i] = (exported_pdu_info->src_port & 0x0000ff00) >> 8;
i++;
packet_buf[i] = (exported_pdu_info->src_port & 0x000000ff);
i++;
}
packet_buf[i] = 0;
i++;
packet_buf[i] = 0;
i++;
packet_buf[i] = 0;
i++;
packet_buf[i] = 0;
i++;
exp_pdu_tags_len = exp_pdu_tags_len + 4;
for (; i < (pkt_data_len + exp_pdu_tags_len); i++){
chr = *curr_pos;
val1 = g_ascii_xdigit_value(chr);
curr_pos++;
chr = *curr_pos;
val2 = g_ascii_xdigit_value(chr);
if ((val1 != -1) && (val2 != -1)){
packet_buf[i] = ((guint8)val1 * 16) + val2;
}
else{
g_free(packet_buf);
return WTAP_OPEN_ERROR;
}
curr_pos++;
}
memset(phdr, 0, sizeof(struct wtap_pkthdr));
phdr->rec_type = REC_TYPE_PACKET;
if (start_time == 0) {
phdr->presence_flags = 0;
phdr->ts.secs = 0;
phdr->ts.nsecs = 0;
} else {
phdr->presence_flags = WTAP_HAS_TS;
phdr->ts.secs = start_time;
phdr->ts.nsecs = ms * 1000000;
}
phdr->caplen = pkt_data_len + exp_pdu_tags_len;
phdr->len = pkt_data_len + exp_pdu_tags_len;
if (!wtap_dump(wdh, phdr, packet_buf, err, err_info)) {
switch (*err) {
case WTAP_ERR_UNWRITABLE_REC_DATA:
g_free(err_info);
break;
default:
break;
}
g_free(packet_buf);
return WTAP_OPEN_ERROR;
}
g_free(packet_buf);
return WTAP_OPEN_MINE;
}
static wtap_open_return_val
create_temp_pcapng_file(wtap *wth, int *err, gchar **err_info, nettrace_3gpp_32_423_file_info_t *file_info)
{
int import_file_fd;
wtap_dumper* wdh_exp_pdu;
int exp_pdu_file_err;
wtap_open_return_val result = WTAP_OPEN_MINE;
wtapng_section_t *shb_hdr = NULL;
wtapng_iface_descriptions_t *idb_inf = NULL;
wtapng_if_descr_t int_data;
GString *os_info_str;
gint64 file_size;
int packet_size;
guint8 *packet_buf = NULL;
int wrt_err;
gchar *wrt_err_info = NULL;
struct wtap_pkthdr phdr;
time_t start_time;
int scan_found, second, ms;
gboolean do_random = FALSE;
char *curr_pos, *next_msg_pos, *next_pos, *prev_pos;
exported_pdu_info_t exported_pdu_info;
exported_pdu_info.precense_flags = 0;
exported_pdu_info.src_ipv4_d1 = 0;
exported_pdu_info.src_ipv4_d2 = 0;
exported_pdu_info.src_ipv4_d3 = 0;
exported_pdu_info.src_ipv4_d4 = 0;
exported_pdu_info.ptype = PT_NONE;
exported_pdu_info.src_port = 0;
exported_pdu_info.dst_ipv4_d1 = 0;
exported_pdu_info.dst_ipv4_d2 = 0;
exported_pdu_info.dst_ipv4_d3 = 0;
exported_pdu_info.dst_ipv4_d4 = 0;
exported_pdu_info.dst_port = 0;
import_file_fd = create_tempfile(&(file_info->tmpname), "Wireshark_PDU_");
os_info_str = g_string_new("");
get_os_version_info(os_info_str);
shb_hdr = g_new(wtapng_section_t, 1);
shb_hdr->section_length = -1;
shb_hdr->opt_comment = g_strdup_printf("File converted to Exported PDU format during opening");
shb_hdr->shb_hardware = NULL;
shb_hdr->shb_os = g_string_free(os_info_str, FALSE);
shb_hdr->shb_user_appl = g_strdup_printf("Wireshark %s", get_ws_vcs_version_info());
idb_inf = g_new(wtapng_iface_descriptions_t, 1);
idb_inf->interface_data = g_array_new(FALSE, FALSE, sizeof(wtapng_if_descr_t));
int_data.wtap_encap = WTAP_ENCAP_WIRESHARK_UPPER_PDU;
int_data.time_units_per_second = 1000000;
int_data.link_type = wtap_wtap_encap_to_pcap_encap(WTAP_ENCAP_WIRESHARK_UPPER_PDU);
int_data.snap_len = WTAP_MAX_PACKET_SIZE;
int_data.if_name = g_strdup("Fake IF");
int_data.opt_comment = NULL;
int_data.if_description = NULL;
int_data.if_speed = 0;
int_data.if_tsresol = 6;
int_data.if_filter_str = NULL;
int_data.bpf_filter_len = 0;
int_data.if_filter_bpf_bytes = NULL;
int_data.if_os = NULL;
int_data.if_fcslen = -1;
int_data.num_stat_entries = 0;
int_data.interface_statistics = NULL;
g_array_append_val(idb_inf->interface_data, int_data);
wdh_exp_pdu = wtap_dump_fdopen_ng(import_file_fd, WTAP_FILE_TYPE_SUBTYPE_PCAPNG, WTAP_ENCAP_WIRESHARK_UPPER_PDU,
WTAP_MAX_PACKET_SIZE, FALSE, shb_hdr, idb_inf, NULL, &exp_pdu_file_err);
if (wdh_exp_pdu == NULL) {
result = WTAP_OPEN_ERROR;
goto end;
}
if ((file_size = wtap_file_size(wth, err)) == -1) {
result = WTAP_OPEN_ERROR;
goto end;
}
if (file_size > MAX_FILE_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("mime_file: File has %" G_GINT64_MODIFIER "d-byte packet, bigger than maximum of %u",
file_size, MAX_FILE_SIZE);
result = WTAP_OPEN_ERROR;
goto end;
}
packet_size = (int)file_size;
packet_buf = (guint8 *)g_malloc(packet_size + 12);
packet_buf[0] = 0;
packet_buf[1] = 12;
packet_buf[2] = 0;
packet_buf[3] = 4;
packet_buf[4] = 0x78;
packet_buf[5] = 0x6d;
packet_buf[6] = 0x6c;
packet_buf[7] = 0;
packet_buf[8] = 0;
packet_buf[9] = 0;
packet_buf[10] = 0;
packet_buf[11] = 0;
if (!wtap_read_bytes(wth->fh, packet_buf + 12, packet_size, &wrt_err, &wrt_err_info)){
result = WTAP_OPEN_ERROR;
goto end;
}
memset(&phdr, 0, sizeof(struct wtap_pkthdr));
curr_pos = packet_buf + 12;
curr_pos = strstr(curr_pos, "<fileHeader");
curr_pos = curr_pos + 11;
curr_pos = strstr(curr_pos, "<traceCollec beginTime=\"");
curr_pos = curr_pos + 24;
curr_pos = nettrace_parse_begin_time(curr_pos, &phdr);
start_time = phdr.ts.secs;
phdr.rec_type = REC_TYPE_PACKET;
phdr.caplen = packet_size + 12;
phdr.len = packet_size + 12;
if (!wtap_dump(wdh_exp_pdu, &phdr, packet_buf, &wrt_err, &wrt_err_info)) {
switch (wrt_err) {
case WTAP_ERR_UNWRITABLE_REC_DATA:
g_free(wrt_err_info);
wrt_err_info = NULL;
break;
default:
break;
}
result = WTAP_OPEN_ERROR;
goto end;
}
while ((curr_pos = strstr(curr_pos, "<msg")) != NULL){
wtap_open_return_val temp_val;
exported_pdu_info.precense_flags = 0;
exported_pdu_info.ptype = PT_NONE;
curr_pos = curr_pos + 4;
next_msg_pos = strstr(curr_pos, "</msg>");
if (!next_msg_pos){
break;
}
next_msg_pos = next_msg_pos + 6;
prev_pos = curr_pos;
ms = 0;
curr_pos = strstr(curr_pos, "changeTime");
if ((curr_pos)&&(curr_pos < next_msg_pos)){
curr_pos = curr_pos + 12;
scan_found = sscanf(curr_pos, "%u.%u",&second, &ms);
if ((scan_found == 2) && (start_time != 0)) {
start_time = start_time + second;
}
} else {
curr_pos = prev_pos;
}
prev_pos = curr_pos;
curr_pos = strstr(curr_pos, "<initiator>");
if ((curr_pos) && (curr_pos < next_msg_pos)) {
curr_pos = curr_pos + 11;
next_pos = strstr(curr_pos, "</initiator>");
curr_pos = strstr(curr_pos, "address");
if ((curr_pos) && (curr_pos < next_pos)) {
guint d1, d2, d3, d4, port;
char transp_str[5];
curr_pos = curr_pos + 7;
scan_found = sscanf(curr_pos, "%*s %3u.%3u.%3u.%3u, %*s %*s %5u, %*s %*s %4s",
&d1, &d2, &d3, &d4, &port, transp_str);
if (scan_found == 6) {
exported_pdu_info.precense_flags = exported_pdu_info.precense_flags + EXP_PDU_TAG_IP_SRC_BIT + EXP_PDU_TAG_SRC_PORT_BIT;
exported_pdu_info.src_ipv4_d1 = d1;
exported_pdu_info.src_ipv4_d2 = d2;
exported_pdu_info.src_ipv4_d3 = d3;
exported_pdu_info.src_ipv4_d4 = d4;
if(exported_pdu_info.ptype == PT_NONE){
if (g_ascii_strncasecmp(transp_str, "udp", 3) == 0) exported_pdu_info.ptype = PT_UDP;
else if (g_ascii_strncasecmp(transp_str, "tcp", 3) == 0) exported_pdu_info.ptype = PT_TCP;
else if (g_ascii_strncasecmp(transp_str, "sctp", 4) == 0) exported_pdu_info.ptype = PT_SCTP;
}
exported_pdu_info.src_port = port;
} else {
g_warning("scan_found:%u, %u.%u.%u.%u Port %u transport %s", scan_found, d1, d2, d3, d4, port, transp_str);
}
} else {
curr_pos = next_pos;
}
} else {
curr_pos = prev_pos;
}
prev_pos = curr_pos;
curr_pos = strstr(curr_pos, "<target>");
if ((curr_pos) && (curr_pos < next_msg_pos)) {
curr_pos = curr_pos + 8;
next_pos = strstr(curr_pos, "</target>");
curr_pos = strstr(curr_pos, "address");
if ((curr_pos) && (curr_pos < next_pos)) {
guint d1, d2, d3, d4, port;
char transp_str[5];
curr_pos = curr_pos + 7;
scan_found = sscanf(curr_pos, "%*s %3u.%3u.%3u.%3u, %*s %*s %5u, %*s %*s %4s",
&d1, &d2, &d3, &d4, &port, transp_str);
if (scan_found == 6) {
exported_pdu_info.precense_flags = exported_pdu_info.precense_flags + EXP_PDU_TAG_IP_DST_BIT + EXP_PDU_TAG_DST_PORT_BIT;
exported_pdu_info.dst_ipv4_d1 = d1;
exported_pdu_info.dst_ipv4_d2 = d2;
exported_pdu_info.dst_ipv4_d3 = d3;
exported_pdu_info.dst_ipv4_d4 = d4;
if (exported_pdu_info.ptype == PT_NONE) {
if (g_ascii_strncasecmp(transp_str, "udp", 3) == 0) exported_pdu_info.ptype = PT_UDP;
else if (g_ascii_strncasecmp(transp_str, "tcp", 3) == 0) exported_pdu_info.ptype = PT_TCP;
else if (g_ascii_strncasecmp(transp_str, "sctp", 4) == 0) exported_pdu_info.ptype = PT_SCTP;
}
exported_pdu_info.dst_port = port;
} else {
g_warning("scan_found:%u, %u.%u.%u.%u Port %u transport %s", scan_found, d1, d2, d3, d4, port, transp_str);
}
}
else {
curr_pos = next_pos;
}
} else {
curr_pos = prev_pos;
}
curr_pos = strstr(curr_pos, "<rawMsg");
if (!curr_pos){
curr_pos = next_msg_pos;
continue;
}
curr_pos = curr_pos + 7;
temp_val = write_packet_data(wdh_exp_pdu, &phdr, &wrt_err, &wrt_err_info, curr_pos, start_time, ms, &exported_pdu_info);
if (temp_val != WTAP_OPEN_MINE){
result = temp_val;
goto end;
}
curr_pos = next_msg_pos;
}
if (!wtap_dump_close(wdh_exp_pdu, err)){
result = WTAP_OPEN_ERROR;
goto end;
}
if (wth->random_fh){
do_random = TRUE;
}
file_info->wth_tmp_file =
wtap_open_offline(file_info->tmpname, WTAP_TYPE_AUTO, err, err_info, do_random);
if (!file_info->wth_tmp_file){
result = WTAP_OPEN_ERROR;
goto end;
}
end:
g_free(wrt_err_info);
g_free(packet_buf);
wtap_free_shb(shb_hdr);
wtap_free_idb_info(idb_inf);
return result;
}
wtap_open_return_val
nettrace_3gpp_32_423_file_open(wtap *wth, int *err, gchar **err_info)
{
char magic_buf[512];
int bytes_read;
char *curr_pos;
nettrace_3gpp_32_423_file_info_t *file_info;
wtap_open_return_val temp_val;
bytes_read = file_read(magic_buf, 512, wth->fh);
if (bytes_read < 0) {
*err = file_error(wth->fh, err_info);
return WTAP_OPEN_ERROR;
}
if (bytes_read == 0){
return WTAP_OPEN_NOT_MINE;
}
if (memcmp(magic_buf, xml_magic, sizeof(xml_magic)) != 0){
return WTAP_OPEN_NOT_MINE;
}
curr_pos = strstr(magic_buf, "fileFormatVersion");
if (!curr_pos){
return WTAP_OPEN_NOT_MINE;
}
curr_pos += 19;
if (memcmp(curr_pos, Threegpp_doc_no, sizeof(Threegpp_doc_no)) != 0){
return WTAP_OPEN_NOT_MINE;
}
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return WTAP_OPEN_ERROR;
file_info = g_new0(nettrace_3gpp_32_423_file_info_t, 1);
temp_val = create_temp_pcapng_file(wth, err, err_info, file_info);
if (temp_val != WTAP_OPEN_MINE){
return temp_val;
}
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return WTAP_OPEN_ERROR;
wth->shb_hdr.opt_comment = file_info->wth_tmp_file->shb_hdr.opt_comment;
wth->shb_hdr.shb_hardware = file_info->wth_tmp_file->shb_hdr.shb_hardware;
wth->shb_hdr.shb_os = file_info->wth_tmp_file->shb_hdr.shb_os;
wth->shb_hdr.shb_user_appl = file_info->wth_tmp_file->shb_hdr.shb_user_appl;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_NETTRACE_3GPP_32_423;
wth->file_encap = file_info->wth_tmp_file->file_encap;
wth->file_tsprec = file_info->wth_tmp_file->file_tsprec;
wth->subtype_read = nettrace_read;
wth->subtype_seek_read = nettrace_seek_read;
wth->subtype_close = nettrace_close;
wth->snapshot_length = 0;
wth->priv = (void*)file_info;
return WTAP_OPEN_MINE;
}
