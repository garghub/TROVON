static void init_gmt_to_localtime_offset(void)
{
if (gmt_to_localtime_offset == (time_t) -1) {
time_t ansi_epoch_plus_one_day = 86400;
struct tm gmt_tm;
struct tm local_tm;
gmt_tm = *gmtime(&ansi_epoch_plus_one_day);
local_tm = *localtime(&ansi_epoch_plus_one_day);
local_tm.tm_isdst = 0;
gmt_to_localtime_offset = mktime(&gmt_tm) - mktime(&local_tm);
}
}
wtap_open_return_val network_instruments_open(wtap *wth, int *err, gchar **err_info)
{
int offset;
capture_file_header file_header;
guint i;
tlv_header tlvh;
int seek_increment;
int header_offset;
packet_entry_header packet_header;
observer_dump_private_state * private_state = NULL;
offset = 0;
if (!wtap_read_bytes(wth->fh, &file_header, sizeof file_header,
err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
offset += (int)sizeof file_header;
CAPTURE_FILE_HEADER_FROM_LE_IN_PLACE(file_header);
if (memcmp(file_header.observer_version, network_instruments_magic, true_magic_length)!=0) {
return WTAP_OPEN_NOT_MINE;
}
private_state = (observer_dump_private_state *) g_malloc(sizeof(observer_dump_private_state));
private_state->time_format = TIME_INFO_LOCAL;
wth->priv = (void *) private_state;
header_offset = file_header.offset_to_first_packet + ((int)(file_header.offset_to_first_packet_high_byte)<<16);
for (i = 0; i < file_header.number_of_information_elements; i++) {
if (offset >= header_offset)
break;
if (!wtap_read_bytes(wth->fh, &tlvh, sizeof tlvh, err, err_info))
return WTAP_OPEN_ERROR;
offset += (int)sizeof tlvh;
TLV_HEADER_FROM_LE_IN_PLACE(tlvh);
if (tlvh.length < sizeof tlvh) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("Observer: bad record (TLV length %u < %lu)",
tlvh.length, (unsigned long)sizeof tlvh);
return WTAP_OPEN_ERROR;
}
switch (tlvh.type) {
case INFORMATION_TYPE_TIME_INFO:
if (!wtap_read_bytes(wth->fh, &private_state->time_format,
sizeof private_state->time_format,
err, err_info))
return WTAP_OPEN_ERROR;
private_state->time_format = GUINT32_FROM_LE(private_state->time_format);
offset += (int)sizeof private_state->time_format;
break;
default:
seek_increment = tlvh.length - (int)sizeof tlvh;
if (seek_increment > 0) {
if (file_seek(wth->fh, seek_increment, SEEK_CUR, err) == -1)
return WTAP_OPEN_ERROR;
}
offset += seek_increment;
}
}
if (header_offset < offset) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("Observer: bad record (offset to first packet %d < %d)",
header_offset, offset);
return WTAP_OPEN_ERROR;
}
seek_increment = header_offset - offset;
if (seek_increment > 0) {
if (file_seek(wth->fh, seek_increment, SEEK_CUR, err) == -1)
return WTAP_OPEN_ERROR;
}
if (!wtap_read_bytes(wth->fh, &packet_header, sizeof packet_header,
err, err_info))
return WTAP_OPEN_ERROR;
PACKET_ENTRY_HEADER_FROM_LE_IN_PLACE(packet_header);
if (packet_header.packet_magic != observer_packet_magic) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("Observer: unsupported packet version %ul", packet_header.packet_magic);
return WTAP_OPEN_ERROR;
}
if (observer_to_wtap_encap(packet_header.network_type) == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("Observer: network type %u unknown or unsupported", packet_header.network_type);
return WTAP_OPEN_ERROR;
}
wth->file_encap = observer_to_wtap_encap(packet_header.network_type);
private_state->packet_count = 0;
private_state->network_type = wtap_to_observer_encap(wth->file_encap);
wth->subtype_read = observer_read;
wth->subtype_seek_read = observer_seek_read;
wth->subtype_close = NULL;
wth->subtype_sequential_close = NULL;
wth->snapshot_length = 0;
wth->file_tsprec = WTAP_TSPREC_NSEC;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_NETWORK_INSTRUMENTS;
if (file_seek(wth->fh, header_offset, SEEK_SET, err) == -1)
return WTAP_OPEN_ERROR;
init_gmt_to_localtime_offset();
return WTAP_OPEN_MINE;
}
static gboolean observer_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
int header_bytes_consumed;
int data_bytes_consumed;
packet_entry_header packet_header;
for (;;) {
*data_offset = file_tell(wth->fh);
header_bytes_consumed = read_packet_header(wth, wth->fh, &wth->phdr.pseudo_header, &packet_header, err,
err_info);
if (header_bytes_consumed <= 0)
return FALSE;
if (packet_header.packet_type == PACKET_TYPE_DATA_PACKET)
break;
if (!skip_to_next_packet(wth, packet_header.offset_to_next_packet,
header_bytes_consumed, err, err_info)) {
return FALSE;
}
}
if (!process_packet_header(wth, &packet_header, &wth->phdr, err, err_info))
return FALSE;
data_bytes_consumed = read_packet_data(wth->fh, packet_header.offset_to_frame,
header_bytes_consumed, wth->frame_buffer,
wth->phdr.caplen, err, err_info);
if (data_bytes_consumed < 0) {
return FALSE;
}
if (!skip_to_next_packet(wth, packet_header.offset_to_next_packet,
header_bytes_consumed + data_bytes_consumed, err, err_info)) {
return FALSE;
}
return TRUE;
}
static gboolean observer_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
packet_entry_header packet_header;
int offset;
int data_bytes_consumed;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
offset = read_packet_header(wth, wth->random_fh, pseudo_header, &packet_header, err,
err_info);
if (offset <= 0)
return FALSE;
if (!process_packet_header(wth, &packet_header, phdr, err, err_info))
return FALSE;
data_bytes_consumed = read_packet_data(wth->random_fh, packet_header.offset_to_frame,
offset, buf, phdr->caplen, err, err_info);
if (data_bytes_consumed < 0) {
return FALSE;
}
return TRUE;
}
static int
read_packet_header(wtap *wth, FILE_T fh, union wtap_pseudo_header *pseudo_header,
packet_entry_header *packet_header, int *err, gchar **err_info)
{
int offset;
guint i;
tlv_header tlvh;
int seek_increment;
tlv_wireless_info wireless_header;
offset = 0;
if (!wtap_read_bytes_or_eof(fh, packet_header, sizeof *packet_header,
err, err_info)) {
if (*err != 0)
return -1;
return 0;
}
offset += (int)sizeof *packet_header;
PACKET_ENTRY_HEADER_FROM_LE_IN_PLACE(*packet_header);
if (packet_header->packet_magic != observer_packet_magic) {
for (i = 0; i < sizeof *packet_header; i++) {
if (((guint8*) packet_header)[i] != 0)
break;
}
if (i == sizeof *packet_header) {
*err = 0;
return 0;
}
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("Observer: bad record: Invalid magic number 0x%08x",
packet_header->packet_magic);
return -1;
}
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = 0;
break;
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO:
pseudo_header->ieee_802_11.fcs_len = 0;
pseudo_header->ieee_802_11.decrypted = FALSE;
pseudo_header->ieee_802_11.datapad = FALSE;
pseudo_header->ieee_802_11.phy = PHDR_802_11_PHY_UNKNOWN;
pseudo_header->ieee_802_11.presence_flags = 0;
break;
}
for (i = 0; i < packet_header->number_of_information_elements; i++) {
if (!wtap_read_bytes(fh, &tlvh, sizeof tlvh, err, err_info))
return -1;
offset += (int)sizeof tlvh;
TLV_HEADER_FROM_LE_IN_PLACE(tlvh);
if (tlvh.length < sizeof tlvh) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("Observer: bad record (TLV length %u < %lu)",
tlvh.length, (unsigned long)sizeof tlvh);
return -1;
}
switch (tlvh.type) {
case INFORMATION_TYPE_WIRELESS:
if (!wtap_read_bytes(fh, &wireless_header, sizeof wireless_header,
err, err_info))
return -1;
pseudo_header->ieee_802_11.presence_flags |=
PHDR_802_11_HAS_CHANNEL |
PHDR_802_11_HAS_DATA_RATE |
PHDR_802_11_HAS_SIGNAL_PERCENT;
pseudo_header->ieee_802_11.decrypted = (wireless_header.conditions & WIRELESS_WEP_SUCCESS) != 0;
pseudo_header->ieee_802_11.channel = wireless_header.frequency;
pseudo_header->ieee_802_11.data_rate = wireless_header.rate;
pseudo_header->ieee_802_11.signal_percent = wireless_header.strengthPercent;
offset += (int)sizeof wireless_header;
break;
default:
seek_increment = tlvh.length - (int)sizeof tlvh;
if (seek_increment > 0) {
if (file_seek(fh, seek_increment, SEEK_CUR, err) == -1)
return -1;
}
offset += seek_increment;
}
}
return offset;
}
static gboolean
process_packet_header(wtap *wth, packet_entry_header *packet_header,
struct wtap_pkthdr *phdr, int *err, gchar **err_info)
{
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
phdr->pkt_encap = observer_to_wtap_encap(packet_header->network_type);
if(wth->file_encap == WTAP_ENCAP_FIBRE_CHANNEL_FC2_WITH_FRAME_DELIMS) {
phdr->len = packet_header->network_size;
phdr->caplen = packet_header->captured_size;
} else {
if (packet_header->network_size < 4) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("Observer: bad record: Packet length %u < 4",
packet_header->network_size);
return FALSE;
}
phdr->len = packet_header->network_size - 4;
phdr->caplen = MIN(packet_header->captured_size, phdr->len);
}
phdr->ts.secs = (time_t) ((packet_header->nano_seconds_since_2000 / 1000000000) + ansi_to_observer_epoch_offset);
phdr->ts.nsecs = (int) (packet_header->nano_seconds_since_2000 % 1000000000);
if (((observer_dump_private_state*)wth->priv)->time_format == TIME_INFO_LOCAL)
{
struct tm daylight_tm;
struct tm standard_tm;
time_t dst_offset;
phdr->ts.secs += gmt_to_localtime_offset;
standard_tm = *localtime(&phdr->ts.secs);
if (standard_tm.tm_isdst > 0) {
daylight_tm = standard_tm;
standard_tm.tm_isdst = 0;
dst_offset = mktime(&standard_tm) - mktime(&daylight_tm);
phdr->ts.secs -= dst_offset;
}
}
return TRUE;
}
static int
read_packet_data(FILE_T fh, int offset_to_frame, int current_offset_from_packet_header, Buffer *buf,
int length, int *err, char **err_info)
{
int seek_increment;
int bytes_consumed = 0;
if (offset_to_frame < current_offset_from_packet_header) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("Observer: bad record (offset to packet data %d < %d)",
offset_to_frame, current_offset_from_packet_header);
return -1;
}
seek_increment = offset_to_frame - current_offset_from_packet_header;
if (seek_increment > 0) {
if (file_seek(fh, seek_increment, SEEK_CUR, err) == -1) {
return -1;
}
bytes_consumed += seek_increment;
}
ws_buffer_assure_space(buf, length);
if (!wtap_read_packet_bytes(fh, buf, length, err, err_info))
return FALSE;
bytes_consumed += length;
return bytes_consumed;
}
static gboolean
skip_to_next_packet(wtap *wth, int offset_to_next_packet, int current_offset_from_packet_header, int *err,
char **err_info)
{
int seek_increment;
if (offset_to_next_packet < current_offset_from_packet_header) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("Observer: bad record (offset to next packet %d < %d)",
offset_to_next_packet, current_offset_from_packet_header);
return FALSE;
}
seek_increment = offset_to_next_packet - current_offset_from_packet_header;
if (seek_increment > 0) {
if (file_seek(wth->fh, seek_increment, SEEK_CUR, err) == -1)
return FALSE;
}
return TRUE;
}
int network_instruments_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (encap < 0 || (wtap_to_observer_encap(encap) == OBSERVER_UNDEFINED))
return WTAP_ERR_UNWRITABLE_ENCAP;
return 0;
}
gboolean network_instruments_dump_open(wtap_dumper *wdh, int *err)
{
observer_dump_private_state * private_state = NULL;
capture_file_header file_header;
tlv_header comment_header;
tlv_time_info time_header;
char comment[64];
size_t comment_length;
struct tm * current_time;
time_t system_time;
private_state = (observer_dump_private_state *) g_malloc(sizeof(observer_dump_private_state));
private_state->packet_count = 0;
private_state->network_type = wtap_to_observer_encap(wdh->encap);
private_state->time_format = TIME_INFO_GMT;
wdh->priv = (void *) private_state;
wdh->subtype_write = observer_dump;
memset(&file_header, 0x00, sizeof(file_header));
g_strlcpy(file_header.observer_version, network_instruments_magic, 31);
file_header.offset_to_first_packet = (guint16)sizeof(file_header);
file_header.offset_to_first_packet_high_byte = 0;
{
time(&system_time);
current_time = localtime(&system_time);
memset(&comment, 0x00, sizeof(comment));
g_snprintf(comment, 64, "This capture was saved from Wireshark on %s", asctime(current_time));
comment_length = strlen(comment);
comment_header.type = INFORMATION_TYPE_COMMENT;
comment_header.length = (guint16) (sizeof(comment_header) + comment_length);
file_header.number_of_information_elements++;
file_header.offset_to_first_packet += comment_header.length;
}
{
time_header.type = INFORMATION_TYPE_TIME_INFO;
time_header.length = (guint16) (sizeof(time_header));
time_header.time_format = TIME_INFO_GMT;
file_header.number_of_information_elements++;
file_header.offset_to_first_packet += time_header.length;
}
CAPTURE_FILE_HEADER_TO_LE_IN_PLACE(file_header);
if (!wtap_dump_file_write(wdh, &file_header, sizeof(file_header), err)) {
return FALSE;
}
wdh->bytes_dumped += sizeof(file_header);
{
TLV_HEADER_TO_LE_IN_PLACE(comment_header);
if (!wtap_dump_file_write(wdh, &comment_header, sizeof(comment_header), err)) {
return FALSE;
}
wdh->bytes_dumped += sizeof(comment_header);
if (!wtap_dump_file_write(wdh, &comment, comment_length, err)) {
return FALSE;
}
wdh->bytes_dumped += comment_length;
}
{
TLV_TIME_INFO_TO_LE_IN_PLACE(time_header);
if (!wtap_dump_file_write(wdh, &time_header, sizeof(time_header), err)) {
return FALSE;
}
wdh->bytes_dumped += sizeof(time_header);
}
init_gmt_to_localtime_offset();
return TRUE;
}
static gboolean observer_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const guint8 *pd,
int *err, gchar **err_info _U_)
{
observer_dump_private_state * private_state = NULL;
packet_entry_header packet_header;
guint64 seconds_since_2000;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
if (phdr->caplen > 65535) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
if (phdr->ts.secs < ansi_to_observer_epoch_offset) {
if(phdr->ts.secs > (time_t) 0) {
seconds_since_2000 = phdr->ts.secs;
} else {
seconds_since_2000 = (time_t) 0;
}
} else {
seconds_since_2000 = phdr->ts.secs - ansi_to_observer_epoch_offset;
}
private_state = (observer_dump_private_state *) wdh->priv;
memset(&packet_header, 0x00, sizeof(packet_header));
packet_header.packet_magic = observer_packet_magic;
packet_header.network_speed = 1000000;
packet_header.captured_size = (guint16) phdr->caplen;
packet_header.network_size = (guint16) (phdr->len + 4);
packet_header.offset_to_frame = sizeof(packet_header);
packet_header.offset_to_next_packet = (guint16)sizeof(packet_header) + phdr->caplen;
packet_header.network_type = private_state->network_type;
packet_header.flags = 0x00;
packet_header.number_of_information_elements = 0;
packet_header.packet_type = PACKET_TYPE_DATA_PACKET;
packet_header.packet_number = private_state->packet_count;
packet_header.original_packet_number = packet_header.packet_number;
packet_header.nano_seconds_since_2000 = seconds_since_2000 * 1000000000 + phdr->ts.nsecs;
private_state->packet_count++;
PACKET_ENTRY_HEADER_TO_LE_IN_PLACE(packet_header);
if (!wtap_dump_file_write(wdh, &packet_header, sizeof(packet_header), err)) {
return FALSE;
}
wdh->bytes_dumped += sizeof(packet_header);
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err)) {
return FALSE;
}
wdh->bytes_dumped += phdr->caplen;
return TRUE;
}
static gint observer_to_wtap_encap(int observer_encap)
{
switch(observer_encap) {
case OBSERVER_ETHERNET:
return WTAP_ENCAP_ETHERNET;
case OBSERVER_TOKENRING:
return WTAP_ENCAP_TOKEN_RING;
case OBSERVER_FIBRE_CHANNEL:
return WTAP_ENCAP_FIBRE_CHANNEL_FC2_WITH_FRAME_DELIMS;
case OBSERVER_WIRELESS_802_11:
return WTAP_ENCAP_IEEE_802_11_WITH_RADIO;
case OBSERVER_UNDEFINED:
return WTAP_ENCAP_UNKNOWN;
}
return WTAP_ENCAP_UNKNOWN;
}
static gint wtap_to_observer_encap(int wtap_encap)
{
switch(wtap_encap) {
case WTAP_ENCAP_ETHERNET:
return OBSERVER_ETHERNET;
case WTAP_ENCAP_TOKEN_RING:
return OBSERVER_TOKENRING;
case WTAP_ENCAP_FIBRE_CHANNEL_FC2_WITH_FRAME_DELIMS:
return OBSERVER_FIBRE_CHANNEL;
case WTAP_ENCAP_UNKNOWN:
return OBSERVER_UNDEFINED;
}
return OBSERVER_UNDEFINED;
}
