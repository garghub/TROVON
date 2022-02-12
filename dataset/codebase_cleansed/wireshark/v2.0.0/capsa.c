wtap_open_return_val capsa_open(wtap *wth, int *err, gchar **err_info)
{
char magic[sizeof capsa_magic];
guint16 format_indicator;
int file_type_subtype;
guint32 number_of_frames;
capsa_t *capsa;
if (!wtap_read_bytes(wth->fh, magic, sizeof magic, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (memcmp(magic, capsa_magic, sizeof capsa_magic) != 0) {
return WTAP_OPEN_NOT_MINE;
}
if (!wtap_read_bytes(wth->fh, &format_indicator, sizeof format_indicator,
err, err_info))
return WTAP_OPEN_ERROR;
format_indicator = GUINT16_FROM_LE(format_indicator);
switch (format_indicator) {
case 1:
file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_COLASOFT_CAPSA;
break;
case 2:
file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_COLASOFT_PACKET_BUILDER;
break;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("capsa: format indicator %u unsupported",
format_indicator);
return WTAP_OPEN_ERROR;
}
if (!file_skip(wth->fh, 2, err))
return WTAP_OPEN_ERROR;
if (!file_skip(wth->fh, 4, err))
return WTAP_OPEN_ERROR;
if (!file_skip(wth->fh, 4, err))
return WTAP_OPEN_ERROR;
if (!file_skip(wth->fh, 4, err))
return WTAP_OPEN_ERROR;
if (!wtap_read_bytes(wth->fh, &number_of_frames, sizeof number_of_frames,
err, err_info))
return WTAP_OPEN_ERROR;
number_of_frames = GUINT32_FROM_LE(number_of_frames);
if (!file_seek(wth->fh, 0x44ef, SEEK_SET, err))
return WTAP_OPEN_ERROR;
wth->file_type_subtype = file_type_subtype;
capsa = (capsa_t *)g_malloc(sizeof(capsa_t));
capsa->format_indicator = format_indicator;
capsa->number_of_frames = number_of_frames;
capsa->frame_count = 0;
wth->priv = (void *)capsa;
wth->subtype_read = capsa_read;
wth->subtype_seek_read = capsa_seek_read;
wth->file_encap = WTAP_ENCAP_ETHERNET;
wth->snapshot_length = 0;
wth->file_tsprec = WTAP_TSPREC_USEC;
return WTAP_OPEN_MINE;
}
static gboolean capsa_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
capsa_t *capsa = (capsa_t *)wth->priv;
guint32 frame_within_block;
int padbytes;
if (capsa->frame_count == capsa->number_of_frames) {
*err = 0;
return FALSE;
}
frame_within_block = capsa->frame_count % N_RECORDS_PER_GROUP;
if (frame_within_block == 0) {
capsa->base_offset = file_tell(wth->fh);
if (!file_skip(wth->fh, 1, err))
return FALSE;
if (!wtap_read_bytes(wth->fh, &capsa->record_offsets,
sizeof capsa->record_offsets, err, err_info))
return FALSE;
if (!file_skip(wth->fh, 4, err))
return FALSE;
}
*data_offset = capsa->base_offset +
GUINT32_FROM_LE(capsa->record_offsets[frame_within_block]);
if (!file_seek(wth->fh, *data_offset, SEEK_SET, err))
return FALSE;
padbytes = capsa_read_packet(wth, wth->fh, &wth->phdr,
wth->frame_buffer, err, err_info);
if (padbytes == -1)
return FALSE;
if (padbytes != 0) {
if (!file_skip(wth->fh, padbytes, err))
return FALSE;
}
capsa->frame_count++;
return TRUE;
}
static gboolean
capsa_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (capsa_read_packet(wth, wth->random_fh, phdr, buf, err, err_info) == -1) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static int
capsa_read_packet(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
capsa_t *capsa = (capsa_t *)wth->priv;
struct capsarec_hdr capsarec_hdr;
struct pbrec_hdr pbrec_hdr;
guint32 rec_size;
guint32 packet_size;
guint32 orig_size;
guint32 header_size;
guint64 timestamp;
switch (capsa->format_indicator) {
case 1:
if (!wtap_read_bytes_or_eof(fh, &capsarec_hdr,
sizeof capsarec_hdr, err, err_info))
return -1;
rec_size = GUINT16_FROM_LE(capsarec_hdr.rec_len);
orig_size = GUINT16_FROM_LE(capsarec_hdr.orig_len);
packet_size = GUINT16_FROM_LE(capsarec_hdr.incl_len);
header_size = sizeof capsarec_hdr;
timestamp = (((guint64)GUINT32_FROM_LE(capsarec_hdr.timestamphi))<<32) + GUINT32_FROM_LE(capsarec_hdr.timestamplo);
if (!file_skip(fh, (capsarec_hdr.count1 + capsarec_hdr.count2)*4,
err))
return -1;
header_size += (capsarec_hdr.count1 + capsarec_hdr.count2)*4;
break;
case 2:
if (!wtap_read_bytes_or_eof(fh, &pbrec_hdr,
sizeof pbrec_hdr, err, err_info))
return -1;
rec_size = GUINT16_FROM_LE(pbrec_hdr.rec_len);
orig_size = GUINT16_FROM_LE(pbrec_hdr.orig_len);
packet_size = GUINT16_FROM_LE(pbrec_hdr.incl_len);
header_size = sizeof pbrec_hdr;
timestamp = (((guint64)GUINT32_FROM_LE(pbrec_hdr.timestamphi))<<32) + GUINT32_FROM_LE(pbrec_hdr.timestamplo);
break;
default:
g_assert_not_reached();
*err = WTAP_ERR_INTERNAL;
return -1;
}
if (orig_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("capsa: File has %u-byte original length, bigger than maximum of %u",
orig_size, WTAP_MAX_PACKET_SIZE);
return -1;
}
if (packet_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("capsa: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return -1;
}
if (header_size + packet_size > rec_size) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("capsa: File has %u-byte packet with %u-byte record header, bigger than record size %u",
packet_size, header_size, rec_size);
return -1;
}
if (orig_size == packet_size + 4)
orig_size = packet_size;
phdr->pseudo_header.eth.fcs_len = 0;
phdr->rec_type = REC_TYPE_PACKET;
phdr->caplen = packet_size;
phdr->len = orig_size;
phdr->presence_flags = WTAP_HAS_CAP_LEN|WTAP_HAS_TS;
phdr->ts.secs = (time_t)(timestamp / 1000000);
phdr->ts.nsecs = ((int)(timestamp % 1000000))*1000;
if (!wtap_read_packet_bytes(fh, buf, packet_size, err, err_info))
return -1;
return rec_size - (header_size + packet_size);
}
