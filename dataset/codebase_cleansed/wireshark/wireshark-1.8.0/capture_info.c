void capture_info_open(capture_options *capture_opts)
{
info_data.counts.total = 0;
info_data.counts.sctp = 0;
info_data.counts.tcp = 0;
info_data.counts.udp = 0;
info_data.counts.icmp = 0;
info_data.counts.ospf = 0;
info_data.counts.gre = 0;
info_data.counts.ipx = 0;
info_data.counts.netbios = 0;
info_data.counts.vines = 0;
info_data.counts.other = 0;
info_data.counts.arp = 0;
info_data.counts.i2c_event = 0;
info_data.counts.i2c_data = 0;
info_data.wtap = NULL;
info_data.ui.counts = &info_data.counts;
capture_info_ui_create(&info_data.ui, capture_opts);
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
errmsg = "The file \"%s\" isn't a capture file in a format TShark understands.";
break;
case WTAP_ERR_UNSUPPORTED:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" isn't a capture file in a format TShark understands.\n"
"(%s)", err_info);
g_free(err_info);
errmsg = errmsg_errno;
break;
case WTAP_ERR_CANT_WRITE_TO_PIPE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" is a pipe, and %s capture files can't be "
"written to a pipe.", wtap_file_type_string(file_type));
errmsg = errmsg_errno;
break;
case WTAP_ERR_UNSUPPORTED_FILE_TYPE:
errmsg = "TShark doesn't support writing capture files in that format.";
break;
case WTAP_ERR_UNSUPPORTED_ENCAP:
if (for_writing)
errmsg = "TShark can't save this capture in that format.";
else {
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" is a capture for a network type that TShark doesn't support.\n"
"(%s)", err_info);
g_free(err_info);
errmsg = errmsg_errno;
}
break;
case WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED:
if (for_writing)
errmsg = "TShark can't save this capture in that format.";
else
errmsg = "The file \"%s\" is a capture for a network type that TShark doesn't support.";
break;
case WTAP_ERR_BAD_FILE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" appears to be damaged or corrupt.\n"
"(%s)", err_info);
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
"(%s)", err_info);
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
gboolean capture_info_new_file(const char *new_filename)
{
int err;
gchar *err_info;
gchar *err_msg;
if(info_data.wtap != NULL) {
wtap_close(info_data.wtap);
}
info_data.wtap = wtap_open_offline(new_filename, &err, &err_info, FALSE);
if (!info_data.wtap) {
err_msg = g_strdup_printf(cf_open_error_message(err, err_info, FALSE, WTAP_FILE_PCAP),
new_filename);
g_warning("capture_info_new_file: %d (%s)", err, err_msg);
g_free (err_msg);
return FALSE;
} else
return TRUE;
}
void capture_info_new_packets(int to_read)
{
int err;
gchar *err_info;
gint64 data_offset;
const struct wtap_pkthdr *phdr;
union wtap_pseudo_header *pseudo_header;
int wtap_linktype;
const guchar *buf;
info_data.ui.new_packets = to_read;
while (to_read > 0) {
wtap_cleareof(info_data.wtap);
if (wtap_read(info_data.wtap, &err, &err_info, &data_offset)) {
phdr = wtap_phdr(info_data.wtap);
pseudo_header = wtap_pseudoheader(info_data.wtap);
wtap_linktype = phdr->pkt_encap;
buf = wtap_buf_ptr(info_data.wtap);
capture_info_packet(&info_data.counts, wtap_linktype, buf, phdr->caplen, pseudo_header);
to_read--;
}
}
capture_info_ui_update(&info_data.ui);
}
void capture_info_close(void)
{
capture_info_ui_destroy(&info_data.ui);
if(info_data.wtap)
wtap_close(info_data.wtap);
}
static void
capture_info_packet(packet_counts *counts, gint wtap_linktype, const guchar *pd, guint32 caplen, union wtap_pseudo_header *pseudo_header)
{
counts->total++;
switch (wtap_linktype) {
case WTAP_ENCAP_ETHERNET:
capture_eth(pd, 0, caplen, counts);
break;
case WTAP_ENCAP_FDDI:
case WTAP_ENCAP_FDDI_BITSWAPPED:
capture_fddi(pd, caplen, counts);
break;
case WTAP_ENCAP_IEEE_802_11_PRISM:
capture_prism(pd, 0, caplen, counts);
break;
case WTAP_ENCAP_TOKEN_RING:
capture_tr(pd, 0, caplen, counts);
break;
case WTAP_ENCAP_NULL:
capture_null(pd, caplen, counts);
break;
case WTAP_ENCAP_PPP:
capture_ppp_hdlc(pd, 0, caplen, counts);
break;
case WTAP_ENCAP_RAW_IP:
capture_raw(pd, caplen, counts);
break;
case WTAP_ENCAP_SLL:
capture_sll(pd, caplen, counts);
break;
case WTAP_ENCAP_LINUX_ATM_CLIP:
capture_clip(pd, caplen, counts);
break;
case WTAP_ENCAP_IEEE_802_11:
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO:
capture_ieee80211(pd, 0, caplen, counts);
break;
case WTAP_ENCAP_IEEE_802_11_RADIOTAP:
capture_radiotap(pd, 0, caplen, counts);
break;
case WTAP_ENCAP_IEEE_802_11_AVS:
capture_wlancap(pd, 0, caplen, counts);
break;
case WTAP_ENCAP_CHDLC:
capture_chdlc(pd, 0, caplen, counts);
break;
case WTAP_ENCAP_LOCALTALK:
capture_llap(counts);
break;
case WTAP_ENCAP_ATM_PDUS:
capture_atm(pseudo_header, pd, caplen, counts);
break;
case WTAP_ENCAP_IP_OVER_FC:
capture_ipfc(pd, caplen, counts);
break;
case WTAP_ENCAP_ARCNET:
capture_arcnet(pd, caplen, counts, FALSE, TRUE);
break;
case WTAP_ENCAP_ARCNET_LINUX:
capture_arcnet(pd, caplen, counts, TRUE, FALSE);
break;
case WTAP_ENCAP_APPLE_IP_OVER_IEEE1394:
capture_ap1394(pd, 0, caplen, counts);
break;
case WTAP_ENCAP_FRELAY:
case WTAP_ENCAP_FRELAY_WITH_PHDR:
capture_fr(pd, 0, caplen, counts);
break;
case WTAP_ENCAP_ENC:
capture_enc(pd, caplen, counts);
break;
case WTAP_ENCAP_PPI:
capture_ppi(pd, caplen, counts);
break;
case WTAP_ENCAP_I2C:
capture_i2c(pseudo_header, counts);
break;
}
}
