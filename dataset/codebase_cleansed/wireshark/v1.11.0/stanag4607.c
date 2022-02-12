static gboolean is_valid_id(guint16 version_id)
{
#define VERSION_21 0x3231
#define VERSION_30 0x3330
if ((version_id != VERSION_21) &&
(version_id != VERSION_30))
return FALSE;
return TRUE;
}
static gboolean stanag4607_read_file(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
stanag4607_t *stanag4607 = (stanag4607_t *)wth->priv;
guint32 millisecs, secs, nsecs;
gint64 offset = 0;
guint8 stanag_pkt_hdr[37];
int bytes_read;
guint32 packet_size;
*err = 0;
bytes_read = file_read(stanag_pkt_hdr, sizeof stanag_pkt_hdr, fh);
if (bytes_read != sizeof stanag_pkt_hdr)
goto fail;
offset += bytes_read;
if (!is_valid_id(pntohs(&stanag_pkt_hdr[0]))) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("Bad version number");
return FALSE;
}
packet_size = pntohl(&stanag_pkt_hdr[2]);
phdr->caplen = packet_size;
phdr->len = packet_size;
phdr->presence_flags = WTAP_HAS_TS;
phdr->ts.secs = stanag4607->base_secs;
phdr->ts.nsecs = 0;
millisecs = 0;
#define MISSION_SEGMENT 1
#define DWELL_SEGMENT 2
#define JOB_DEFINITION_SEGMENT 5
#define PLATFORM_LOCATION_SEGMENT 13
if (MISSION_SEGMENT == stanag_pkt_hdr[32]) {
guint8 mseg[39];
struct tm tm;
bytes_read = file_read(&mseg, sizeof mseg, fh);
if (bytes_read != sizeof mseg)
goto fail;
offset += bytes_read;
tm.tm_year = pntohs(&mseg[35]) - 1900;
tm.tm_mon = mseg[37] - 1;
tm.tm_mday = mseg[38];
tm.tm_hour = 0;
tm.tm_min = 0;
tm.tm_sec = 0;
tm.tm_isdst = -1;
stanag4607->base_secs = mktime(&tm);
phdr->ts.secs = stanag4607->base_secs;
}
else if (PLATFORM_LOCATION_SEGMENT == stanag_pkt_hdr[32]) {
bytes_read = file_read(&millisecs, sizeof millisecs, fh);
if (bytes_read != sizeof millisecs)
goto fail;
offset += bytes_read;
millisecs = g_ntohl(millisecs);
}
else if (DWELL_SEGMENT == stanag_pkt_hdr[32]) {
guint8 dseg[19];
bytes_read = file_read(&dseg, sizeof dseg, fh);
if (bytes_read != sizeof dseg)
goto fail;
offset += bytes_read;
millisecs = pntohl(&dseg[15]);
}
if (0 != millisecs) {
secs = millisecs/1000;
nsecs = (millisecs - 1000 * secs) * 1000000;
phdr->ts.secs = stanag4607->base_secs + secs;
phdr->ts.nsecs = nsecs;
}
if (file_seek(fh, - offset, SEEK_CUR, err) == -1)
goto fail;
return wtap_read_packet_bytes(fh, buf, packet_size, err, err_info);
fail:
*err = file_error(wth->fh, err_info);
return FALSE;
}
static gboolean stanag4607_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
gint64 offset;
*err = 0;
offset = file_tell(wth->fh);
*data_offset = offset;
return stanag4607_read_file(wth, wth->fh, &wth->phdr, wth->frame_buffer, err, err_info);
}
static gboolean stanag4607_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr,
Buffer *buf, int length _U_, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
return stanag4607_read_file(wth, wth->random_fh, phdr, buf, err, err_info);
}
int stanag4607_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
guint16 version_id;
stanag4607_t *stanag4607;
bytes_read = file_read(&version_id, sizeof version_id, wth->fh);
if (bytes_read != sizeof version_id) {
*err = file_error(wth->fh, err_info);
return (*err != 0) ? -1 : 0;
}
if (!is_valid_id(GUINT16_TO_BE(version_id)))
return 0;
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return -1;
wth->file_type = WTAP_FILE_STANAG_4607;
wth->file_encap = WTAP_ENCAP_STANAG_4607;
wth->snapshot_length = 0;
stanag4607 = (stanag4607_t *)g_malloc(sizeof(stanag4607_t));
wth->priv = (void *)stanag4607;
stanag4607->base_secs = 0;
wth->subtype_read = stanag4607_read;
wth->subtype_seek_read = stanag4607_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_MSEC;
return 1;
}
