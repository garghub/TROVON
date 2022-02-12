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
if (ret == 0 || ret == -1) {
return ret;
}
value = strtoul (str_num, &p, 10);
if (p == str_num || value > G_MAXUINT32)
return 0;
*num = (guint32)value;
return 1;
}
wtap_open_return_val peektagged_open(wtap *wth, int *err, gchar **err_info)
{
peektagged_section_header_t ap_hdr;
int ret;
guint32 fileVersion = 0;
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
if (!wtap_read_bytes(wth->fh, &ap_hdr, (int)sizeof(ap_hdr), err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (memcmp (ap_hdr.section_id, "\177ver", sizeof(ap_hdr.section_id)) != 0)
return WTAP_OPEN_NOT_MINE;
ret = wtap_file_read_pattern (wth, "<FileVersion>", err, err_info);
if (ret == -1)
return WTAP_OPEN_ERROR;
if (ret == 0) {
return WTAP_OPEN_NOT_MINE;
}
ret = wtap_file_read_number (wth, &fileVersion, err, err_info);
if (ret == -1)
return WTAP_OPEN_ERROR;
if (ret == 0) {
return WTAP_OPEN_NOT_MINE;
}
if (fileVersion != 9) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("peektagged: version %u unsupported",
fileVersion);
return WTAP_OPEN_ERROR;
}
ret = wtap_file_read_pattern (wth, "<MediaType>", err, err_info);
if (ret == -1)
return WTAP_OPEN_ERROR;
if (ret == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: <MediaType> tag not found");
return WTAP_OPEN_ERROR;
}
ret = wtap_file_read_number (wth, &mediaType, err, err_info);
if (ret == -1)
return WTAP_OPEN_ERROR;
if (ret == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: <MediaType> value not found");
return WTAP_OPEN_ERROR;
}
ret = wtap_file_read_pattern (wth, "<MediaSubType>", err, err_info);
if (ret == -1)
return WTAP_OPEN_ERROR;
if (ret == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: <MediaSubType> tag not found");
return WTAP_OPEN_ERROR;
}
ret = wtap_file_read_number (wth, &mediaSubType, err, err_info);
if (ret == -1)
return WTAP_OPEN_ERROR;
if (ret == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: <MediaSubType> value not found");
return WTAP_OPEN_ERROR;
}
if (mediaSubType >= NUM_PEEKTAGGED_ENCAPS
|| peektagged_encap[mediaSubType] == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("peektagged: network type %u unknown or unsupported",
mediaSubType);
return WTAP_OPEN_ERROR;
}
ret = wtap_file_read_pattern (wth, "pkts", err, err_info);
if (ret == -1)
return WTAP_OPEN_ERROR;
if (ret == 0) {
*err = WTAP_ERR_SHORT_READ;
return WTAP_OPEN_ERROR;
}
if (file_seek (wth->fh, 8L, SEEK_CUR, err) == -1)
return WTAP_OPEN_NOT_MINE;
file_encap = peektagged_encap[mediaSubType];
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_PEEKTAGGED;
wth->file_encap = file_encap;
wth->subtype_read = peektagged_read;
wth->subtype_seek_read = peektagged_seek_read;
wth->file_tsprec = WTAP_TSPREC_NSEC;
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
return WTAP_OPEN_MINE;
}
static int
peektagged_read_packet(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
peektagged_t *peektagged = (peektagged_t *)wth->priv;
gboolean read_a_tag = FALSE;
guint8 tag_value[6];
guint16 tag;
gboolean saw_length = FALSE;
guint32 length = 0;
guint32 sliceLength = 0;
gboolean saw_timestamp_lower = FALSE;
gboolean saw_timestamp_upper = FALSE;
peektagged_utime timestamp;
guint32 ext_flags = 0;
gboolean saw_data_rate_or_mcs_index = FALSE;
guint32 data_rate_or_mcs_index = 0;
gint channel;
guint frequency;
struct ieee_802_11_phdr ieee_802_11;
guint i;
int skip_len = 0;
guint64 t;
timestamp.upper = 0;
timestamp.lower = 0;
memset(&ieee_802_11, 0, sizeof ieee_802_11);
ieee_802_11.fcs_len = -1;
ieee_802_11.decrypted = FALSE;
ieee_802_11.datapad = FALSE;
ieee_802_11.phy = PHDR_802_11_PHY_UNKNOWN;
do {
if (!wtap_read_bytes_or_eof(fh, tag_value, sizeof tag_value, err, err_info)) {
if (*err == 0) {
if (read_a_tag)
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
read_a_tag = TRUE;
tag = pletoh16(&tag_value[0]);
switch (tag) {
case TAG_PEEKTAGGED_LENGTH:
if (saw_length) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has two length fields");
return -1;
}
length = pletoh32(&tag_value[2]);
saw_length = TRUE;
break;
case TAG_PEEKTAGGED_TIMESTAMP_LOWER:
if (saw_timestamp_lower) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has two timestamp-lower fields");
return -1;
}
timestamp.lower = pletoh32(&tag_value[2]);
saw_timestamp_lower = TRUE;
break;
case TAG_PEEKTAGGED_TIMESTAMP_UPPER:
if (saw_timestamp_upper) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: record has two timestamp-upper fields");
return -1;
}
timestamp.upper = pletoh32(&tag_value[2]);
saw_timestamp_upper = TRUE;
break;
case TAG_PEEKTAGGED_FLAGS_AND_STATUS:
break;
case TAG_PEEKTAGGED_CHANNEL:
ieee_802_11.has_channel = TRUE;
ieee_802_11.channel = pletoh32(&tag_value[2]);
break;
case TAG_PEEKTAGGED_DATA_RATE_OR_MCS_INDEX:
data_rate_or_mcs_index = pletoh32(&tag_value[2]);
saw_data_rate_or_mcs_index = TRUE;
break;
case TAG_PEEKTAGGED_SIGNAL_PERC:
ieee_802_11.has_signal_percent = TRUE;
ieee_802_11.signal_percent = pletoh32(&tag_value[2]);
break;
case TAG_PEEKTAGGED_SIGNAL_DBM:
ieee_802_11.has_signal_dbm = TRUE;
ieee_802_11.signal_dbm = pletoh32(&tag_value[2]);
break;
case TAG_PEEKTAGGED_NOISE_PERC:
ieee_802_11.has_noise_percent = TRUE;
ieee_802_11.noise_percent = pletoh32(&tag_value[2]);
break;
case TAG_PEEKTAGGED_NOISE_DBM:
ieee_802_11.has_noise_dbm = TRUE;
ieee_802_11.noise_dbm = pletoh32(&tag_value[2]);
break;
case TAG_PEEKTAGGED_UNKNOWN_0x000A:
break;
case TAG_PEEKTAGGED_CENTER_FREQUENCY:
ieee_802_11.has_frequency = TRUE;
ieee_802_11.frequency = pletoh32(&tag_value[2]);
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
case TAG_PEEKTAGGED_EXT_FLAGS:
ext_flags = pletoh32(&tag_value[2]);
if (ext_flags & EXT_FLAG_802_11ac) {
ieee_802_11.phy = PHDR_802_11_PHY_11AC;
for (i = 0; i < 4; i++)
ieee_802_11.phy_info.info_11ac.nss[i] = 0;
switch (ext_flags & EXT_FLAGS_GI) {
case EXT_FLAG_HALF_GI:
ieee_802_11.phy_info.info_11ac.has_short_gi = TRUE;
ieee_802_11.phy_info.info_11ac.short_gi = 1;
break;
case EXT_FLAG_FULL_GI:
ieee_802_11.phy_info.info_11ac.has_short_gi = TRUE;
ieee_802_11.phy_info.info_11ac.short_gi = 0;
break;
default:
break;
}
} else {
ieee_802_11.phy = PHDR_802_11_PHY_11N;
switch (ext_flags & EXT_FLAGS_BANDWIDTH) {
case 0:
ieee_802_11.phy_info.info_11n.has_bandwidth = TRUE;
ieee_802_11.phy_info.info_11n.bandwidth = PHDR_802_11_BANDWIDTH_20_MHZ;
break;
case EXT_FLAG_20_MHZ_LOWER:
ieee_802_11.phy_info.info_11n.has_bandwidth = TRUE;
ieee_802_11.phy_info.info_11n.bandwidth = PHDR_802_11_BANDWIDTH_20_20L;
break;
case EXT_FLAG_20_MHZ_UPPER:
ieee_802_11.phy_info.info_11n.has_bandwidth = TRUE;
ieee_802_11.phy_info.info_11n.bandwidth = PHDR_802_11_BANDWIDTH_20_20U;
break;
case EXT_FLAG_40_MHZ:
ieee_802_11.phy_info.info_11n.has_bandwidth = TRUE;
ieee_802_11.phy_info.info_11n.bandwidth = PHDR_802_11_BANDWIDTH_40_MHZ;
break;
default:
break;
}
switch (ext_flags & EXT_FLAGS_GI) {
case EXT_FLAG_HALF_GI:
ieee_802_11.phy_info.info_11n.has_short_gi = TRUE;
ieee_802_11.phy_info.info_11n.short_gi = 1;
break;
case EXT_FLAG_FULL_GI:
ieee_802_11.phy_info.info_11n.has_short_gi = TRUE;
ieee_802_11.phy_info.info_11n.short_gi = 0;
break;
default:
break;
}
}
break;
case TAG_PEEKTAGGED_SLICE_LENGTH:
sliceLength = pletoh32(&tag_value[2]);
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
if (sliceLength == 0)
sliceLength = length;
if (sliceLength > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("peektagged: File has %u-byte packet, bigger than maximum of %u",
sliceLength, WTAP_MAX_PACKET_SIZE);
return -1;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
phdr->len = length;
phdr->caplen = sliceLength;
t = (((guint64) timestamp.upper) << 32) + timestamp.lower;
if (!nsfiletime_to_nstime(&phdr->ts, t)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("peektagged: time stamp outside supported range");
return -1;
}
switch (wth->file_encap) {
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO:
if (saw_data_rate_or_mcs_index) {
if (ext_flags & EXT_FLAG_MCS_INDEX_USED) {
if (!(ext_flags & EXT_FLAG_802_11ac)) {
ieee_802_11.phy_info.info_11n.has_mcs_index = TRUE;
ieee_802_11.phy_info.info_11n.mcs_index = data_rate_or_mcs_index;
}
} else {
ieee_802_11.has_data_rate = TRUE;
ieee_802_11.data_rate = data_rate_or_mcs_index;
}
}
if (ieee_802_11.has_frequency && !ieee_802_11.has_channel) {
channel = ieee80211_mhz_to_chan(ieee_802_11.frequency);
if (channel != -1) {
ieee_802_11.has_channel = TRUE;
ieee_802_11.channel = channel;
}
} else if (ieee_802_11.has_channel && !ieee_802_11.has_frequency) {
switch (ieee_802_11.phy) {
case PHDR_802_11_PHY_11_DSSS:
case PHDR_802_11_PHY_11B:
case PHDR_802_11_PHY_11G:
frequency = ieee80211_chan_to_mhz(ieee_802_11.channel, TRUE);
break;
case PHDR_802_11_PHY_11A:
frequency = ieee80211_chan_to_mhz(ieee_802_11.channel, FALSE);
break;
default:
frequency = 0;
break;
}
if (frequency != 0) {
ieee_802_11.has_frequency = TRUE;
ieee_802_11.frequency = frequency;
}
}
phdr->pseudo_header.ieee_802_11 = ieee_802_11;
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
phdr->pseudo_header.ieee_802_11.datapad = FALSE;
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
