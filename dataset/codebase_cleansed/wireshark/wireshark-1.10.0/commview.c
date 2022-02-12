int commview_open(wtap *wth, int *err, gchar **err_info)
{
commview_header_t cv_hdr;
if(!commview_read_header(&cv_hdr, wth->fh, err, err_info)) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
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
return 0;
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return -1;
wth->subtype_read = commview_read;
wth->subtype_seek_read = commview_seek_read;
wth->file_type = WTAP_FILE_COMMVIEW;
wth->file_encap = WTAP_ENCAP_PER_PACKET;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
return 1;
}
static gboolean
commview_set_packet_header(const commview_header_t *cv_hdrp, struct wtap_pkthdr *phdr)
{
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
struct tm tm;
phdr->len = cv_hdrp->data_len;
phdr->caplen = cv_hdrp->data_len;
tm.tm_year = cv_hdrp->year - 1900;
tm.tm_mon = cv_hdrp->month - 1;
tm.tm_mday = cv_hdrp->day;
tm.tm_hour = cv_hdrp->hours;
tm.tm_min = cv_hdrp->minutes;
tm.tm_sec = cv_hdrp->seconds;
tm.tm_isdst = -1;
phdr->ts.secs = mktime(&tm);
phdr->ts.nsecs = cv_hdrp->usecs * 1000;
phdr->presence_flags = WTAP_HAS_TS;
switch(cv_hdrp->flags & FLAGS_MEDIUM) {
case MEDIUM_ETHERNET :
phdr->pkt_encap = WTAP_ENCAP_ETHERNET;
pseudo_header->eth.fcs_len = -1;
return TRUE;
case MEDIUM_WIFI :
phdr->pkt_encap = WTAP_ENCAP_IEEE_802_11_WITH_RADIO;
pseudo_header->ieee_802_11.fcs_len = -1;
pseudo_header->ieee_802_11.decrypted = FALSE;
pseudo_header->ieee_802_11.channel = cv_hdrp->channel;
pseudo_header->ieee_802_11.data_rate =
cv_hdrp->rate | (cv_hdrp->direction << 8);
pseudo_header->ieee_802_11.signal_level = cv_hdrp->signal_level_percent;
return TRUE;
case MEDIUM_TOKEN_RING :
phdr->pkt_encap = WTAP_ENCAP_TOKEN_RING;
return TRUE;
}
return FALSE;
}
static gboolean
commview_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
commview_header_t cv_hdr;
int bytes_read;
*data_offset = file_tell(wth->fh);
if(!commview_read_header(&cv_hdr, wth->fh, err, err_info))
return FALSE;
if(!commview_set_packet_header(&cv_hdr, &wth->phdr)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("commview: unsupported encap: %u",
cv_hdr.flags & FLAGS_MEDIUM);
return FALSE;
}
buffer_assure_space(wth->frame_buffer, cv_hdr.data_len);
bytes_read = file_read(buffer_start_ptr(wth->frame_buffer),
cv_hdr.data_len, wth->fh);
if(bytes_read != cv_hdr.data_len) {
*err = file_error(wth->fh, err_info);
if(*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
commview_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
guint8 *pd, int length, int *err,
gchar **err_info)
{
commview_header_t cv_hdr;
int bytes_read;
if(file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if(!commview_read_header(&cv_hdr, wth->random_fh, err, err_info)) {
if(*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
if(!commview_set_packet_header(&cv_hdr, phdr)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("commview: unsupported encap: %u",
cv_hdr.flags & FLAGS_MEDIUM);
return FALSE;
}
if(length != (int)phdr->caplen) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("commview: record length %u doesn't match requested length %d", phdr->caplen, length);
return FALSE;
}
bytes_read = file_read(pd, cv_hdr.data_len, wth->random_fh);
if(bytes_read != cv_hdr.data_len) {
*err = file_error(wth->random_fh, err_info);
if(*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
commview_read_header(commview_header_t *cv_hdr, FILE_T fh, int *err,
gchar **err_info)
{
wtap_file_read_expected_bytes(&cv_hdr->data_len, 2, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->source_data_len, 2, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->version, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->year, 2, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->month, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->day, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->hours, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->minutes, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->seconds, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->usecs, 4, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->flags, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->signal_level_percent, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->rate, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->band, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->channel, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->direction, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->signal_level_dbm, 1, fh, err, err_info);
wtap_file_read_expected_bytes(&cv_hdr->noise_level, 1, fh, err, err_info);
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
return WTAP_ERR_UNSUPPORTED_ENCAP;
}
}
gboolean commview_dump_open(wtap_dumper *wdh, int *err _U_)
{
wdh->subtype_write = commview_dump;
wdh->subtype_close = NULL;
wdh->bytes_dumped = 0;
return TRUE;
}
static gboolean commview_dump(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
commview_header_t cv_hdr;
struct tm *tm;
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
cv_hdr.channel = pseudo_header->ieee_802_11.channel;
cv_hdr.rate = (guint8)(pseudo_header->ieee_802_11.data_rate & 0xFF);
cv_hdr.direction = (guint8)((pseudo_header->ieee_802_11.data_rate >> 8) & 0xFF);
cv_hdr.signal_level_percent = pseudo_header->ieee_802_11.signal_level;
break;
case WTAP_ENCAP_TOKEN_RING :
cv_hdr.flags |= MEDIUM_TOKEN_RING;
break;
default :
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
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
