int radcom_open(wtap *wth, int *err, gchar **err_info)
{
guint8 r_magic[8], t_magic[11], search_encap[7];
struct frame_date start_date;
#if 0
guint32 sec;
struct tm tm;
#endif
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, r_magic, 8, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
r_magic[1] = 0xD2;
r_magic[2] = 0x00;
if (memcmp(r_magic, radcom_magic, 8) != 0) {
return 0;
}
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, t_magic, 11, err, err_info)) {
if (*err == WTAP_ERR_SHORT_READ) {
return 0;
}
return -1;
}
while (memcmp(t_magic, active_time_magic, 11) != 0)
{
if (file_seek(wth->fh, -10, SEEK_CUR, err) == -1)
return -1;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, t_magic, 11, err, err_info)) {
if (*err == WTAP_ERR_SHORT_READ) {
return 0;
}
return -1;
}
}
if (file_seek(wth->fh, -43, SEEK_CUR, err) == -1) return -1;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, &start_date, sizeof(struct frame_date),
err, err_info)) {
if (*err == WTAP_ERR_SHORT_READ) {
return 0;
}
return -1;
}
if (file_seek(wth->fh, sizeof(struct frame_date), SEEK_CUR, err) == -1)
return -1;
for (;;) {
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, search_encap, 4,
err, err_info)) {
if (*err == WTAP_ERR_SHORT_READ) {
return 0;
}
return -1;
}
if (memcmp(encap_magic, search_encap, 4) == 0)
break;
if (file_seek(wth->fh, -3, SEEK_CUR, err) == -1)
return -1;
}
if (file_seek(wth->fh, 12, SEEK_CUR, err) == -1)
return -1;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, search_encap, 4, err, err_info)) {
if (*err == WTAP_ERR_SHORT_READ) {
return 0;
}
return -1;
}
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_RADCOM;
wth->subtype_read = radcom_read;
wth->subtype_seek_read = radcom_seek_read;
wth->snapshot_length = 0;
wth->file_tsprec = WTAP_TSPREC_USEC;
#if 0
tm.tm_year = pletoh16(&start_date.year)-1900;
tm.tm_mon = start_date.month-1;
tm.tm_mday = start_date.day;
sec = pletoh32(&start_date.sec);
tm.tm_hour = sec/3600;
tm.tm_min = (sec%3600)/60;
tm.tm_sec = sec%60;
tm.tm_isdst = -1;
#endif
if (memcmp(search_encap, "LAPB", 4) == 0)
wth->file_encap = WTAP_ENCAP_LAPB;
else if (memcmp(search_encap, "Ethe", 4) == 0)
wth->file_encap = WTAP_ENCAP_ETHERNET;
else if (memcmp(search_encap, "ATM/", 4) == 0)
wth->file_encap = WTAP_ENCAP_ATM_RFC1483;
else {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("radcom: network type \"%.4s\" unknown", search_encap);
return -1;
}
#if 0
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, &next_date, sizeof(struct frame_date),
err, err_info))
return -1;
while (memcmp(&start_date, &next_date, 4)) {
if (file_seek(wth->fh, 1-sizeof(struct frame_date), SEEK_CUR, err) == -1)
return -1;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, &next_date, sizeof(struct frame_date),
err, err_info))
return -1;
}
#endif
if (wth->file_encap == WTAP_ENCAP_ETHERNET) {
if (file_seek(wth->fh, 294, SEEK_CUR, err) == -1)
return -1;
} else if (wth->file_encap == WTAP_ENCAP_LAPB) {
if (file_seek(wth->fh, 297, SEEK_CUR, err) == -1)
return -1;
} else if (wth->file_encap == WTAP_ENCAP_ATM_RFC1483) {
if (file_seek(wth->fh, 504, SEEK_CUR, err) == -1)
return -1;
}
return 1;
}
static gboolean radcom_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
char fcs[2];
*data_offset = file_tell(wth->fh);
if (!radcom_read_rec(wth, wth->fh, &wth->phdr, wth->frame_buffer,
err, err_info)) {
return FALSE;
}
if (wth->file_encap == WTAP_ENCAP_LAPB) {
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, &fcs, sizeof fcs, err, err_info))
return FALSE;
}
return TRUE;
}
static gboolean
radcom_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!radcom_read_rec(wth, wth->random_fh, phdr, buf, err,
err_info)) {
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
return TRUE;
}
static gboolean
radcom_read_rec(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
struct radcomrec_hdr hdr;
guint16 data_length, real_length, length;
guint32 sec;
struct tm tm;
guint8 atmhdr[8];
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes_or_eof(fh, &hdr, sizeof hdr, err, err_info))
return FALSE;
data_length = pletoh16(&hdr.data_length);
if (data_length == 0) {
*err = 0;
return FALSE;
}
length = pletoh16(&hdr.length);
real_length = pletoh16(&hdr.real_length);
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
tm.tm_year = pletoh16(&hdr.date.year)-1900;
tm.tm_mon = (hdr.date.month&0x0f)-1;
tm.tm_mday = hdr.date.day;
sec = pletoh32(&hdr.date.sec);
tm.tm_hour = sec/3600;
tm.tm_min = (sec%3600)/60;
tm.tm_sec = sec%60;
tm.tm_isdst = -1;
phdr->ts.secs = mktime(&tm);
phdr->ts.nsecs = pletoh32(&hdr.date.usec) * 1000;
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
phdr->pseudo_header.eth.fcs_len = -1;
break;
case WTAP_ENCAP_LAPB:
phdr->pseudo_header.x25.flags = (hdr.dce & 0x1) ?
0x00 : FROM_DCE;
length -= 2;
real_length -= 2;
break;
case WTAP_ENCAP_ATM_RFC1483:
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(fh, atmhdr, sizeof atmhdr, err,
err_info))
return FALSE;
length -= 8;
real_length -= 8;
break;
}
phdr->len = real_length;
phdr->caplen = length;
if (!wtap_read_packet_bytes(fh, buf, length, err, err_info))
return FALSE;
return TRUE;
}
