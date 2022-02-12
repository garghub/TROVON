static int wtap_file_read_pattern (wtap *wth, const char *pattern, int *err,
gchar **err_info)
{
int c;
const char *cp;
cp = pattern;
while (*cp)
{
c = file_getc(wth->fh);
if (c == EOF)
{
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (c == *cp)
cp++;
else
{
if (c == pattern[0])
cp = &pattern[1];
else
cp = pattern;
}
}
return (*cp == '\0' ? 1 : 0);
}
static int wtap_file_read_till_separator (wtap *wth, char *buffer, int buflen,
const char *separators, int *err,
gchar **err_info)
{
int c;
char *cp;
int i;
for (cp = buffer, i = 0; i < buflen; i++, cp++)
{
c = file_getc(wth->fh);
if (c == EOF)
{
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (strchr (separators, c) != NULL)
{
*cp = '\0';
break;
}
else
*cp = c;
}
return i;
}
static int wtap_file_read_number (wtap *wth, guint32 *num, int *err,
gchar **err_info)
{
int ret;
char str_num[12];
unsigned long value;
char *p;
ret = wtap_file_read_till_separator (wth, str_num, sizeof (str_num)-1, "<",
err, err_info);
if (ret != 1) {
return ret;
}
value = strtoul (str_num, &p, 10);
if (p == str_num || value > G_MAXUINT32)
return 0;
*num = (guint32)value;
return 1;
}
int peektagged_open(wtap *wth, int *err, gchar **err_info)
{
peektagged_section_header_t ap_hdr;
int bytes_read;
int ret;
guint32 fileVersion;
guint32 mediaType;
guint32 mediaSubType = 0;
int file_encap;
static const int peektagged_encap[] = {
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_IEEE_802_11_WITH_RADIO,
WTAP_ENCAP_IEEE_802_11_WITH_RADIO,
WTAP_ENCAP_IEEE_802_11_WITH_RADIO
};
#define NUM_PEEKTAGGED_ENCAPS (sizeof peektagged_encap / sizeof peektagged_encap[0])
peektagged_t *peektagged;
bytes_read = file_read(&ap_hdr, (int)sizeof(ap_hdr), wth->fh);
if (bytes_read != (int)sizeof(ap_hdr)) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (memcmp (ap_hdr.section_id, "\177ver", sizeof(ap_hdr.section_id)) != 0)
return 0;
ret = wtap_file_read_pattern (wth, "<FileVersion>", err, err_info);
if (ret != 1) {
return ret;
}
ret = wtap_file_read_number (wth, &fileVersion, err, err_info);
if (ret != 1) {
return ret;
}
if (fileVersion != 9) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("peektagged: version %u unsupported",
fileVersion);
return -1;
}
ret = wtap_file_read_pattern (wth, "<MediaType>", err, err_info);
if (ret == -1)
return -1;
if (ret == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: <MediaType> tag not found");
return -1;
}
ret = wtap_file_read_number (wth, &mediaType, err, err_info);
if (ret == -1)
return -1;
if (ret == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: <MediaType> value not found");
return -1;
}
ret = wtap_file_read_pattern (wth, "<MediaSubType>", err, err_info);
if (ret == -1)
return -1;
if (ret == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: <MediaSubType> tag not found");
return -1;
}
ret = wtap_file_read_number (wth, &mediaSubType, err, err_info);
if (ret == -1)
return -1;
if (ret == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: <MediaSubType> value not found");
return -1;
}
if (mediaSubType >= NUM_PEEKTAGGED_ENCAPS
|| peektagged_encap[mediaSubType] == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("peektagged: network type %u unknown or unsupported",
mediaSubType);
return -1;
}
ret = wtap_file_read_pattern (wth, "pkts", err, err_info);
if (ret == -1)
return -1;
if (ret == 0) {
*err = WTAP_ERR_SHORT_READ;
return -1;
}
if (file_seek (wth->fh, 8L, SEEK_CUR, err) == -1)
return 0;
file_encap = peektagged_encap[mediaSubType];
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_PEEKTAGGED;
wth->file_encap = file_encap;
wth->subtype_read = peektagged_read;
wth->subtype_seek_read = peektagged_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
peektagged = (peektagged_t *)g_malloc(sizeof(peektagged_t));
wth->priv = (void *)peektagged;
switch (mediaSubType) {
case PEEKTAGGED_NST_ETHERNET:
case PEEKTAGGED_NST_802_11:
case PEEKTAGGED_NST_802_11_2:
peektagged->has_fcs = FALSE;
break;
case PEEKTAGGED_NST_802_11_WITH_FCS:
peektagged->has_fcs = TRUE;
break;
}
wth->snapshot_length = 0;
return 1;
}
static int
peektagged_read_packet(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
peektagged_t *peektagged = (peektagged_t *)wth->priv;
hdr_info_t hdr_info;
int header_len = 0;
int bytes_read;
guint8 tag_value[6];
guint16 tag;
gboolean saw_length = FALSE;
gboolean saw_timestamp_lower = FALSE;
gboolean saw_timestamp_upper = FALSE;
int skip_len = 0;
double t;
memset(&hdr_info, 0, sizeof(hdr_info_t));
do {
bytes_read = file_read(tag_value, sizeof tag_value, fh);
if (bytes_read != (int) sizeof tag_value) {
*err = file_error(fh, err_info);
if (*err == 0) {
if (bytes_read > 0)
*err = WTAP_ERR_SHORT_READ;
else if (bytes_read == 0) {
if (header_len != 0)
*err = WTAP_ERR_SHORT_READ;
}
}
return -1;
}
header_len += (int) sizeof(tag_value);
tag = pletoh16(&tag_value[0]);
switch (tag) {
case TAG_PEEKTAGGED_LENGTH:
if (saw_length) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has two length fields");
return -1;
}
hdr_info.length = pletoh32(&tag_value[2]);
saw_length = TRUE;
break;
case TAG_PEEKTAGGED_TIMESTAMP_LOWER:
if (saw_timestamp_lower) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has two timestamp-lower fields");
return -1;
}
hdr_info.timestamp.lower = pletoh32(&tag_value[2]);
saw_timestamp_lower = TRUE;
break;
case TAG_PEEKTAGGED_TIMESTAMP_UPPER:
if (saw_timestamp_upper) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has two timestamp-upper fields");
return -1;
}
hdr_info.timestamp.upper = pletoh32(&tag_value[2]);
saw_timestamp_upper = TRUE;
break;
case TAG_PEEKTAGGED_FLAGS_AND_STATUS:
break;
case TAG_PEEKTAGGED_CHANNEL:
hdr_info.ieee_802_11.channel = pletoh32(&tag_value[2]);
break;
case TAG_PEEKTAGGED_RATE:
hdr_info.ieee_802_11.data_rate = pletoh32(&tag_value[2]);
break;
case TAG_PEEKTAGGED_SIGNAL_PERC:
hdr_info.ieee_802_11.signal_level = pletoh32(&tag_value[2]);
break;
case TAG_PEEKTAGGED_SIGNAL_DBM:
break;
case TAG_PEEKTAGGED_NOISE_PERC:
break;
case TAG_PEEKTAGGED_NOISE_DBM:
break;
case TAG_PEEKTAGGED_UNKNOWN_0x000A:
break;
case TAG_PEEKTAGGED_UNKNOWN_0x000D:
break;
case TAG_PEEKTAGGED_UNKNOWN_0x000E:
break;
case TAG_PEEKTAGGED_UNKNOWN_0x000F:
break;
case TAG_PEEKTAGGED_UNKNOWN_0x0010:
break;
case TAG_PEEKTAGGED_UNKNOWN_0x0011:
break;
case TAG_PEEKTAGGED_UNKNOWN_0x0012:
break;
case TAG_PEEKTAGGED_UNKNOWN_0x0013:
break;
case TAG_PEEKTAGGED_UNKNOWN_0x0014:
break;
case TAG_PEEKTAGGED_UNKNOWN_0x0015:
break;
case TAG_PEEKTAGGED_SLICE_LENGTH:
hdr_info.sliceLength = pletoh32(&tag_value[2]);
break;
default:
break;
}
} while (tag != TAG_PEEKTAGGED_SLICE_LENGTH);
if (!saw_length) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has no length field");
return -1;
}
if (!saw_timestamp_lower) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has no timestamp-lower field");
return -1;
}
if (!saw_timestamp_upper) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has no timestamp-upper field");
return -1;
}
if (hdr_info.sliceLength == 0)
hdr_info.sliceLength = hdr_info.length;
if (hdr_info.sliceLength > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("peektagged: File has %u-byte packet, bigger than maximum of %u",
hdr_info.sliceLength, WTAP_MAX_PACKET_SIZE);
return -1;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
phdr->len = hdr_info.length;
phdr->caplen = hdr_info.sliceLength;
t = (double) hdr_info.timestamp.lower +
(double) hdr_info.timestamp.upper * 4294967296.0;
t *= 1.0e-9;
t -= TIME_FIXUP_CONSTANT;
phdr->ts.secs = (time_t) t;
phdr->ts.nsecs = (guint32) ((t - phdr->ts.secs)*1000000000);
switch (wth->file_encap) {
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO:
phdr->pseudo_header.ieee_802_11 = hdr_info.ieee_802_11;
if (peektagged->has_fcs)
phdr->pseudo_header.ieee_802_11.fcs_len = 4;
else {
if (phdr->len < 4 || phdr->caplen < 4) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("peektagged: 802.11 packet has length < 4");
return FALSE;
}
phdr->pseudo_header.ieee_802_11.fcs_len = 0;
phdr->len -= 4;
phdr->caplen -= 4;
skip_len = 4;
}
phdr->pseudo_header.ieee_802_11.decrypted = FALSE;
break;
case WTAP_ENCAP_ETHERNET:
if (phdr->len < 4 || phdr->caplen < 4) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("peektagged: Ethernet packet has length < 4");
return FALSE;
}
phdr->pseudo_header.eth.fcs_len = 0;
phdr->len -= 4;
phdr->caplen -= 4;
skip_len = 4;
break;
}
if (!wtap_read_packet_bytes(fh, buf, phdr->caplen, err, err_info))
return -1;
return skip_len;
}
static gboolean peektagged_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
int skip_len;
*data_offset = file_tell(wth->fh);
skip_len = peektagged_read_packet(wth, wth->fh, &wth->phdr,
wth->frame_buffer, err, err_info);
if (skip_len == -1)
return FALSE;
if (skip_len != 0) {
if (!file_skip(wth->fh, skip_len, err))
return FALSE;
}
return TRUE;
}
static gboolean
peektagged_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (peektagged_read_packet(wth, wth->random_fh, phdr, buf, err, err_info) == -1) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
