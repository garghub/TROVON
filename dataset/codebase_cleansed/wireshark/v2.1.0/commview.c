wtap_open_return_val commview_open(wtap *wth, int *err, gchar **err_info)
{
commview_header_t cv_hdr;
if(!commview_read_header(&cv_hdr, wth->fh, err, err_info)) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if(cv_hdr.version != 0 ||
cv_hdr.year < 1970 || cv_hdr.year >= 2038 ||
cv_hdr.month < 1 || cv_hdr.month > 12 ||
cv_hdr.day < 1 || cv_hdr.day > 31 ||
cv_hdr.hours > 23 ||
cv_hdr.minutes > 59 ||
cv_hdr.seconds > 60 ||
cv_hdr.signal_level_percent > 100 ||
(cv_hdr.flags & FLAGS_RESERVED) != 0 ||
((cv_hdr.flags & FLAGS_MEDIUM) != MEDIUM_ETHERNET &&
(cv_hdr.flags & FLAGS_MEDIUM) != MEDIUM_WIFI &&
(cv_hdr.flags & FLAGS_MEDIUM) != MEDIUM_TOKEN_RING))
return WTAP_OPEN_NOT_MINE;
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return WTAP_OPEN_ERROR;
wth->subtype_read = commview_read;
wth->subtype_seek_read = commview_seek_read;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_COMMVIEW;
wth->file_encap = WTAP_ENCAP_PER_PACKET;
wth->file_tsprec = WTAP_TSPREC_USEC;
return WTAP_OPEN_MINE;
}
static int
commview_read_packet(FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
commview_header_t cv_hdr;
struct tm tm;
guint frequency;
if(!commview_read_header(&cv_hdr, fh, err, err_info))
return FALSE;
switch(cv_hdr.flags & FLAGS_MEDIUM) {
case MEDIUM_ETHERNET :
phdr->pkt_encap = WTAP_ENCAP_ETHERNET;
phdr->pseudo_header.eth.fcs_len = -1;
break;
case MEDIUM_WIFI :
phdr->pkt_encap = WTAP_ENCAP_IEEE_802_11_WITH_RADIO;
memset(&phdr->pseudo_header.ieee_802_11, 0, sizeof(phdr->pseudo_header.ieee_802_11));
phdr->pseudo_header.ieee_802_11.fcs_len = -1;
phdr->pseudo_header.ieee_802_11.decrypted = FALSE;
phdr->pseudo_header.ieee_802_11.datapad = FALSE;
phdr->pseudo_header.ieee_802_11.phy = PHDR_802_11_PHY_UNKNOWN;
switch (cv_hdr.band) {
case BAND_11A:
phdr->pseudo_header.ieee_802_11.phy = PHDR_802_11_PHY_11A;
phdr->pseudo_header.ieee_802_11.phy_info.info_11a.has_turbo_type = TRUE;
phdr->pseudo_header.ieee_802_11.phy_info.info_11a.turbo_type =
PHDR_802_11A_TURBO_TYPE_NORMAL;
frequency = ieee80211_chan_to_mhz(cv_hdr.channel, FALSE);
break;
case BAND_11B:
phdr->pseudo_header.ieee_802_11.phy = PHDR_802_11_PHY_11B;
frequency = ieee80211_chan_to_mhz(cv_hdr.channel, TRUE);
break;
case BAND_11G:
phdr->pseudo_header.ieee_802_11.phy = PHDR_802_11_PHY_11G;
phdr->pseudo_header.ieee_802_11.phy_info.info_11g.has_mode = TRUE;
phdr->pseudo_header.ieee_802_11.phy_info.info_11g.mode =
PHDR_802_11G_MODE_NORMAL;
frequency = ieee80211_chan_to_mhz(cv_hdr.channel, TRUE);
break;
case BAND_11A_TURBO:
phdr->pseudo_header.ieee_802_11.phy = PHDR_802_11_PHY_11A;
phdr->pseudo_header.ieee_802_11.phy_info.info_11a.has_turbo_type = TRUE;
phdr->pseudo_header.ieee_802_11.phy_info.info_11a.turbo_type =
PHDR_802_11A_TURBO_TYPE_TURBO;
frequency = ieee80211_chan_to_mhz(cv_hdr.channel, FALSE);
break;
case BAND_SUPERG:
phdr->pseudo_header.ieee_802_11.phy = PHDR_802_11_PHY_11G;
phdr->pseudo_header.ieee_802_11.phy_info.info_11g.has_mode = TRUE;
phdr->pseudo_header.ieee_802_11.phy_info.info_11g.mode =
PHDR_802_11G_MODE_SUPER_G;
frequency = ieee80211_chan_to_mhz(cv_hdr.channel, TRUE);
break;
case BAND_11N_5GHZ:
phdr->pseudo_header.ieee_802_11.phy = PHDR_802_11_PHY_11N;
frequency = ieee80211_chan_to_mhz(cv_hdr.channel, FALSE);
break;
case BAND_11N_2_4GHZ:
phdr->pseudo_header.ieee_802_11.phy = PHDR_802_11_PHY_11N;
frequency = ieee80211_chan_to_mhz(cv_hdr.channel, TRUE);
break;
case BAND_PUBLIC_SAFETY:
frequency = 0;
break;
default:
frequency = 0;
break;
}
if (frequency != 0) {
phdr->pseudo_header.ieee_802_11.has_frequency = TRUE;
phdr->pseudo_header.ieee_802_11.frequency = frequency;
}
phdr->pseudo_header.ieee_802_11.has_channel = TRUE;
phdr->pseudo_header.ieee_802_11.channel = cv_hdr.channel;
phdr->pseudo_header.ieee_802_11.has_data_rate = TRUE;
phdr->pseudo_header.ieee_802_11.data_rate =
cv_hdr.rate | (cv_hdr.direction << 8);
phdr->pseudo_header.ieee_802_11.has_signal_percent = TRUE;
phdr->pseudo_header.ieee_802_11.signal_percent = cv_hdr.signal_level_percent;
if (cv_hdr.signal_level_dbm != 0) {
phdr->pseudo_header.ieee_802_11.signal_dbm = -cv_hdr.signal_level_dbm;
phdr->pseudo_header.ieee_802_11.has_signal_dbm = TRUE;
}
if (cv_hdr.noise_level != 0) {
phdr->pseudo_header.ieee_802_11.noise_dbm = -cv_hdr.noise_level;
phdr->pseudo_header.ieee_802_11.has_noise_dbm = TRUE;
}
break;
case MEDIUM_TOKEN_RING :
phdr->pkt_encap = WTAP_ENCAP_TOKEN_RING;
break;
default :
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("commview: unsupported encap: %u",
cv_hdr.flags & FLAGS_MEDIUM);
return FALSE;
}
tm.tm_year = cv_hdr.year - 1900;
tm.tm_mon = cv_hdr.month - 1;
tm.tm_mday = cv_hdr.day;
tm.tm_hour = cv_hdr.hours;
tm.tm_min = cv_hdr.minutes;
tm.tm_sec = cv_hdr.seconds;
tm.tm_isdst = -1;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
phdr->len = cv_hdr.data_len;
phdr->caplen = cv_hdr.data_len;
phdr->ts.secs = mktime(&tm);
phdr->ts.nsecs = cv_hdr.usecs * 1000;
return wtap_read_packet_bytes(fh, buf, phdr->caplen, err, err_info);
}
static gboolean
commview_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
return commview_read_packet(wth->fh, &wth->phdr, wth->frame_buffer, err,
err_info);
}
static gboolean
commview_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
if(file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
return commview_read_packet(wth->random_fh, phdr, buf, err, err_info);
}
static gboolean
commview_read_header(commview_header_t *cv_hdr, FILE_T fh, int *err,
gchar **err_info)
{
if (!wtap_read_bytes_or_eof(fh, &cv_hdr->data_len, 2, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->source_data_len, 2, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->version, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->year, 2, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->month, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->day, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->hours, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->minutes, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->seconds, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->usecs, 4, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->flags, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->signal_level_percent, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->rate, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->band, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->channel, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->direction, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->signal_level_dbm, 1, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &cv_hdr->noise_level, 1, err, err_info))
return FALSE;
cv_hdr->data_len = GUINT16_FROM_LE(cv_hdr->data_len);
cv_hdr->source_data_len = GUINT16_FROM_LE(cv_hdr->source_data_len);
cv_hdr->year = GUINT16_FROM_LE(cv_hdr->year);
cv_hdr->usecs = GUINT32_FROM_LE(cv_hdr->usecs);
return TRUE;
}
int commview_dump_can_write_encap(int encap)
{
switch (encap) {
case WTAP_ENCAP_ETHERNET :
case WTAP_ENCAP_IEEE_802_11 :
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO :
case WTAP_ENCAP_TOKEN_RING :
case WTAP_ENCAP_PER_PACKET :
return 0;
default:
return WTAP_ERR_UNWRITABLE_ENCAP;
}
}
gboolean commview_dump_open(wtap_dumper *wdh, int *err _U_)
{
wdh->subtype_write = commview_dump;
wdh->bytes_dumped = 0;
return TRUE;
}
static gboolean commview_dump(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err, gchar **err_info _U_)
{
commview_header_t cv_hdr;
struct tm *tm;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
if (phdr->caplen > 65535) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
memset(&cv_hdr, 0, sizeof(cv_hdr));
cv_hdr.data_len = GUINT16_TO_LE((guint16)phdr->caplen);
cv_hdr.source_data_len = GUINT16_TO_LE((guint16)phdr->caplen);
cv_hdr.version = 0;
tm = localtime(&phdr->ts.secs);
cv_hdr.year = tm->tm_year + 1900;
cv_hdr.month = tm->tm_mon + 1;
cv_hdr.day = tm->tm_mday;
cv_hdr.hours = tm->tm_hour;
cv_hdr.minutes = tm->tm_min;
cv_hdr.seconds = tm->tm_sec;
cv_hdr.usecs = GUINT32_TO_LE(phdr->ts.nsecs / 1000);
switch(phdr->pkt_encap) {
case WTAP_ENCAP_ETHERNET :
cv_hdr.flags |= MEDIUM_ETHERNET;
break;
case WTAP_ENCAP_IEEE_802_11 :
cv_hdr.flags |= MEDIUM_WIFI;
break;
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO :
cv_hdr.flags |= MEDIUM_WIFI;
switch (phdr->pseudo_header.ieee_802_11.phy) {
case PHDR_802_11_PHY_11A:
if (!phdr->pseudo_header.ieee_802_11.phy_info.info_11a.has_turbo_type ||
phdr->pseudo_header.ieee_802_11.phy_info.info_11a.turbo_type == PHDR_802_11A_TURBO_TYPE_NORMAL)
cv_hdr.band = BAND_11A;
else
cv_hdr.band = BAND_11A_TURBO;
break;
case PHDR_802_11_PHY_11B:
cv_hdr.band = BAND_11B;
break;
case PHDR_802_11_PHY_11G:
if (!phdr->pseudo_header.ieee_802_11.phy_info.info_11g.has_mode)
cv_hdr.band = BAND_11G;
else {
switch (phdr->pseudo_header.ieee_802_11.phy_info.info_11g.mode) {
case PHDR_802_11G_MODE_NORMAL:
cv_hdr.band = BAND_11G;
break;
case PHDR_802_11G_MODE_SUPER_G:
cv_hdr.band = BAND_SUPERG;
break;
default:
cv_hdr.band = BAND_11G;
break;
}
}
break;
case PHDR_802_11_PHY_11N:
if (phdr->pseudo_header.ieee_802_11.has_frequency) {
if (phdr->pseudo_header.ieee_802_11.frequency > 2484) {
cv_hdr.band = BAND_11N_5GHZ;
} else {
cv_hdr.band = BAND_11N_2_4GHZ;
}
} else {
cv_hdr.band = 0;
}
break;
default:
cv_hdr.band = 0;
break;
}
cv_hdr.channel =
phdr->pseudo_header.ieee_802_11.has_channel ?
phdr->pseudo_header.ieee_802_11.channel :
0;
cv_hdr.rate =
phdr->pseudo_header.ieee_802_11.has_data_rate ?
(guint8)(phdr->pseudo_header.ieee_802_11.data_rate & 0xFF) :
0;
cv_hdr.direction =
phdr->pseudo_header.ieee_802_11.has_data_rate ?
(guint8)((phdr->pseudo_header.ieee_802_11.data_rate >> 8) & 0xFF) :
0;
cv_hdr.signal_level_percent =
phdr->pseudo_header.ieee_802_11.has_signal_percent ?
phdr->pseudo_header.ieee_802_11.signal_percent :
0;
cv_hdr.signal_level_dbm =
phdr->pseudo_header.ieee_802_11.has_signal_dbm ?
-phdr->pseudo_header.ieee_802_11.signal_dbm :
0;
cv_hdr.noise_level =
phdr->pseudo_header.ieee_802_11.has_noise_dbm ?
-phdr->pseudo_header.ieee_802_11.noise_dbm :
0;
break;
case WTAP_ENCAP_TOKEN_RING :
cv_hdr.flags |= MEDIUM_TOKEN_RING;
break;
default :
*err = WTAP_ERR_UNWRITABLE_ENCAP;
return FALSE;
}
if (!wtap_dump_file_write(wdh, &cv_hdr.data_len, 2, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.source_data_len, 2, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.version, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.year, 2, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.month, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.day, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.hours, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.minutes, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.seconds, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.usecs, 4, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.flags, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.signal_level_percent, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.rate, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.band, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.channel, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.direction, 1, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.signal_level_dbm, 2, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &cv_hdr.noise_level, 2, err))
return FALSE;
wdh->bytes_dumped += COMMVIEW_HEADER_SIZE;
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
wdh->bytes_dumped += phdr->caplen;
return TRUE;
}
