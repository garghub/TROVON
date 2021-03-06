void capture_info_open(capture_session *cap_session, info_data_t* cap_info)
{
if (cap_info->counts.counts_hash != NULL)
{
g_hash_table_destroy(cap_info->counts.counts_hash);
}
cap_info->counts.counts_hash = g_hash_table_new_full( g_direct_hash, g_direct_equal, NULL, g_free );
cap_info->counts.other = 0;
cap_info->counts.total = 0;
cap_info->wtap = NULL;
cap_info->ui.counts = &cap_info->counts;
capture_info_ui_create(&cap_info->ui, cap_session);
}
static const char *
cf_open_error_message(int err, gchar *err_info, gboolean for_writing,
int file_type)
{
const char *errmsg;
static char errmsg_errno[1024+1];
if (err < 0) {
switch (err) {
case WTAP_ERR_NOT_REGULAR_FILE:
errmsg = "The file \"%s\" is a \"special file\" or socket or other non-regular file.";
break;
case WTAP_ERR_FILE_UNKNOWN_FORMAT:
errmsg = "The file \"%s\" isn't a capture file in a format Wireshark understands.";
break;
case WTAP_ERR_UNSUPPORTED:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" contains record data that Wireshark doesn't support.\n"
"(%s)", err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
errmsg = errmsg_errno;
break;
case WTAP_ERR_CANT_WRITE_TO_PIPE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" is a pipe, and %s capture files can't be "
"written to a pipe.", wtap_file_type_subtype_string(file_type));
errmsg = errmsg_errno;
break;
case WTAP_ERR_UNWRITABLE_FILE_TYPE:
errmsg = "Wireshark doesn't support writing capture files in that format.";
break;
case WTAP_ERR_UNWRITABLE_ENCAP:
errmsg = "Wireshark can't save this capture in that format.";
break;
case WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED:
if (for_writing)
errmsg = "Wireshark can't save this capture in that format.";
else
errmsg = "The file \"%s\" is a capture for a network type that Wireshark doesn't support.";
break;
case WTAP_ERR_BAD_FILE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" appears to be damaged or corrupt.\n"
"(%s)", err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
errmsg = errmsg_errno;
break;
case WTAP_ERR_CANT_OPEN:
if (for_writing)
errmsg = "The file \"%s\" could not be created for some unknown reason.";
else
errmsg = "The file \"%s\" could not be opened for some unknown reason.";
break;
case WTAP_ERR_SHORT_READ:
errmsg = "The file \"%s\" appears to have been cut short"
" in the middle of a packet or other data.";
break;
case WTAP_ERR_SHORT_WRITE:
errmsg = "A full header couldn't be written to the file \"%s\".";
break;
case WTAP_ERR_DECOMPRESS:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The compressed file \"%%s\" appears to be damaged or corrupt.\n"
"(%s)", err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
errmsg = errmsg_errno;
break;
default:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" could not be %s: %s.",
for_writing ? "created" : "opened",
wtap_strerror(err));
errmsg = errmsg_errno;
break;
}
} else
errmsg = file_open_error_message(err, for_writing);
return errmsg;
}
gboolean capture_info_new_file(const char *new_filename, info_data_t* cap_info)
{
int err;
gchar *err_info;
gchar *err_msg;
if(cap_info->wtap != NULL) {
wtap_close(cap_info->wtap);
}
cap_info->wtap = wtap_open_offline(new_filename, WTAP_TYPE_AUTO, &err, &err_info, FALSE);
if (!cap_info->wtap) {
err_msg = g_strdup_printf(cf_open_error_message(err, err_info, FALSE, WTAP_FILE_TYPE_SUBTYPE_UNKNOWN),
new_filename);
g_warning("capture_info_new_file: %d (%s)", err, err_msg);
g_free (err_msg);
return FALSE;
} else
return TRUE;
}
static void
capture_info_packet(info_data_t* cap_info, gint wtap_linktype, const guchar *pd, guint32 caplen, union wtap_pseudo_header *pseudo_header)
{
capture_packet_info_t cpinfo;
cpinfo.counts = cap_info->counts.counts_hash;
cap_info->counts.total++;
if (!try_capture_dissector("wtap_encap", wtap_linktype, pd, 0, caplen, &cpinfo, pseudo_header))
cap_info->counts.other++;
}
void capture_info_new_packets(int to_read, info_data_t* cap_info)
{
int err;
gchar *err_info;
gint64 data_offset;
struct wtap_pkthdr *phdr;
union wtap_pseudo_header *pseudo_header;
int wtap_linktype;
const guchar *buf;
cap_info->ui.new_packets = to_read;
while (to_read > 0) {
wtap_cleareof(cap_info->wtap);
if (wtap_read(cap_info->wtap, &err, &err_info, &data_offset)) {
phdr = wtap_phdr(cap_info->wtap);
pseudo_header = &phdr->pseudo_header;
wtap_linktype = phdr->pkt_encap;
buf = wtap_buf_ptr(cap_info->wtap);
capture_info_packet(cap_info, wtap_linktype, buf, phdr->caplen, pseudo_header);
to_read--;
}
}
capture_info_ui_update(&cap_info->ui);
}
void capture_info_close(info_data_t* cap_info)
{
capture_info_ui_destroy(&cap_info->ui);
if(cap_info->wtap)
wtap_close(cap_info->wtap);
}
