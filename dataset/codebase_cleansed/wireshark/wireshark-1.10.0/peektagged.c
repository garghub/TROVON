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
wth->file_type = WTAP_FILE_PEEKTAGGED;
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
peektagged_process_header(FILE_T fh, hdr_info_t *hdr_info, int *err,
gchar **err_info)
{
int header_len = 0;
int bytes_read;
guint8 tag_value[6];
guint16 tag;
gboolean saw_length = FALSE;
gboolean saw_timestamp_lower = FALSE;
gboolean saw_timestamp_upper = FALSE;
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
return 0;
}
header_len += (int) sizeof(tag_value);
tag = pletohs(&tag_value[0]);
switch (tag) {
case TAG_PEEKTAGGED_LENGTH:
if (saw_length) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has two length fields");
return 0;
}
hdr_info->length = pletohl(&tag_value[2]);
saw_length = TRUE;
break;
case TAG_PEEKTAGGED_TIMESTAMP_LOWER:
if (saw_timestamp_lower) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has two timestamp-lower fields");
return 0;
}
hdr_info->timestamp.lower = pletohl(&tag_value[2]);
saw_timestamp_lower = TRUE;
break;
case TAG_PEEKTAGGED_TIMESTAMP_UPPER:
if (saw_timestamp_upper) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has two timestamp-upper fields");
return 0;
}
hdr_info->timestamp.upper = pletohl(&tag_value[2]);
saw_timestamp_upper = TRUE;
break;
case TAG_PEEKTAGGED_FLAGS_AND_STATUS:
break;
case TAG_PEEKTAGGED_CHANNEL:
hdr_info->ieee_802_11.channel = pletohl(&tag_value[2]);
break;
case TAG_PEEKTAGGED_RATE:
hdr_info->ieee_802_11.data_rate = pletohl(&tag_value[2]);
break;
case TAG_PEEKTAGGED_SIGNAL_PERC:
hdr_info->ieee_802_11.signal_level = pletohl(&tag_value[2]);
break;
case TAG_PEEKTAGGED_SIGNAL_DBM:
break;
case TAG_PEEKTAGGED_NOISE_PERC:
break;
case TAG_PEEKTAGGED_NOISE_DBM:
break;
case TAG_PEEKTAGGED_UNKNOWN_0x000D:
break;
case TAG_PEEKTAGGED_SLICE_LENGTH:
hdr_info->sliceLength = pletohl(&tag_value[2]);
break;
default:
break;
}
} while (tag != TAG_PEEKTAGGED_SLICE_LENGTH);
if (!saw_length) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has no length field");
return 0;
}
if (!saw_timestamp_lower) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has no timestamp-lower field");
return 0;
}
if (!saw_timestamp_upper) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has no timestamp-upper field");
return 0;
}
return header_len;
}
static gboolean peektagged_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
peektagged_t *peektagged = (peektagged_t *)wth->priv;
hdr_info_t hdr_info;
int hdrlen;
double t;
*data_offset = file_tell(wth->fh);
hdrlen = peektagged_process_header(wth->fh, &hdr_info, err, err_info);
if (hdrlen == 0)
return FALSE;
if (hdr_info.sliceLength == 0)
hdr_info.sliceLength = hdr_info.length;
if (hdr_info.sliceLength > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("peektagged: File has %u-byte packet, bigger than maximum of %u",
hdr_info.sliceLength, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
wth->phdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
wth->phdr.len = hdr_info.length;
wth->phdr.caplen = hdr_info.sliceLength;
buffer_assure_space(wth->frame_buffer, hdr_info.sliceLength);
wtap_file_read_expected_bytes(buffer_start_ptr(wth->frame_buffer),
hdr_info.sliceLength, wth->fh, err,
err_info);
t = (double) hdr_info.timestamp.lower +
(double) hdr_info.timestamp.upper * 4294967296.0;
t *= 1.0e-9;
t -= TIME_FIXUP_CONSTANT;
wth->phdr.ts.secs = (time_t) t;
wth->phdr.ts.nsecs = (guint32) ((t - wth->phdr.ts.secs)*1000000000);
switch (wth->file_encap) {
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO:
wth->phdr.pseudo_header.ieee_802_11 = hdr_info.ieee_802_11;
if (peektagged->has_fcs)
wth->phdr.pseudo_header.ieee_802_11.fcs_len = 4;
else {
wth->phdr.pseudo_header.ieee_802_11.fcs_len = 0;
wth->phdr.len -= 4;
wth->phdr.caplen -= 4;
}
wth->phdr.pseudo_header.ieee_802_11.decrypted = FALSE;
break;
case WTAP_ENCAP_ETHERNET:
wth->phdr.pseudo_header.eth.fcs_len = 0;
wth->phdr.len -= 4;
wth->phdr.caplen -= 4;
break;
}
return TRUE;
}
static gboolean
peektagged_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, guint8 *pd, int length,
int *err, gchar **err_info)
{
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
peektagged_t *peektagged = (peektagged_t *)wth->priv;
hdr_info_t hdr_info;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (peektagged_process_header(wth->random_fh, &hdr_info, err, err_info) == -1)
return FALSE;
switch (wth->file_encap) {
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO:
pseudo_header->ieee_802_11 = hdr_info.ieee_802_11;
if (peektagged->has_fcs)
pseudo_header->ieee_802_11.fcs_len = 4;
else
pseudo_header->ieee_802_11.fcs_len = 0;
pseudo_header->ieee_802_11.decrypted = FALSE;
break;
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = 0;
break;
}
errno = WTAP_ERR_CANT_READ;
wtap_file_read_expected_bytes(pd, length, wth->random_fh, err, err_info);
return TRUE;
}
