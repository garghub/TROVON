int radcom_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
guint8 r_magic[8], t_magic[11], search_encap[7];
struct frame_date start_date;
#if 0
guint32 sec;
struct tm tm;
#endif
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(r_magic, 8, wth->fh);
if (bytes_read != 8) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
r_magic[1] = 0xD2;
r_magic[2] = 0x00;
if (memcmp(r_magic, radcom_magic, 8) != 0) {
return 0;
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(t_magic, 11, wth->fh);
if (bytes_read != 11) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
while (memcmp(t_magic, active_time_magic, 11) != 0)
{
if (file_seek(wth->fh, -10, SEEK_CUR, err) == -1)
return -1;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(t_magic, 11, wth->fh);
if (bytes_read != 11) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
}
if (file_seek(wth->fh, -43, SEEK_CUR, err) == -1) return -1;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&start_date, sizeof(struct frame_date),
wth->fh);
if (bytes_read != sizeof(struct frame_date)) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
wth->file_type = WTAP_FILE_RADCOM;
wth->subtype_read = radcom_read;
wth->subtype_seek_read = radcom_seek_read;
wth->snapshot_length = 0;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
#if 0
tm.tm_year = pletohs(&start_date.year)-1900;
tm.tm_mon = start_date.month-1;
tm.tm_mday = start_date.day;
sec = pletohl(&start_date.sec);
tm.tm_hour = sec/3600;
tm.tm_min = (sec%3600)/60;
tm.tm_sec = sec%60;
tm.tm_isdst = -1;
#endif
if (file_seek(wth->fh, sizeof(struct frame_date), SEEK_CUR, err) == -1)
return -1;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(search_encap, 4, wth->fh);
if (bytes_read != 4) {
goto read_error;
}
while (memcmp(encap_magic, search_encap, 4)) {
if (file_seek(wth->fh, -3, SEEK_CUR, err) == -1)
return -1;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(search_encap, 4, wth->fh);
if (bytes_read != 4) {
goto read_error;
}
}
if (file_seek(wth->fh, 12, SEEK_CUR, err) == -1)
return -1;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(search_encap, 4, wth->fh);
if (bytes_read != 4) {
goto read_error;
}
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
bytes_read = file_read(&next_date, sizeof(struct frame_date), wth->fh);
errno = WTAP_ERR_CANT_READ;
if (bytes_read != sizeof(struct frame_date)) {
goto read_error;
}
while (memcmp(&start_date, &next_date, 4)) {
if (file_seek(wth->fh, 1-sizeof(struct frame_date), SEEK_CUR, err) == -1)
return -1;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&next_date, sizeof(struct frame_date),
wth->fh);
if (bytes_read != sizeof(struct frame_date)) {
goto read_error;
}
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
read_error:
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
static gboolean radcom_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
int ret;
struct radcomrec_hdr hdr;
guint16 data_length, real_length, length;
guint32 sec;
int bytes_read;
struct tm tm;
guint8 phdr[8];
char fcs[2];
*data_offset = file_tell(wth->fh);
ret = radcom_read_rec_header(wth->fh, &hdr, err, err_info);
if (ret <= 0) {
return FALSE;
}
data_length = pletohs(&hdr.data_length);
if (data_length == 0) {
*err = 0;
return FALSE;
}
length = pletohs(&hdr.length);
real_length = pletohs(&hdr.real_length);
if (wth->file_encap == WTAP_ENCAP_LAPB) {
length -= 2;
real_length -= 2;
}
wth->phdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
wth->phdr.len = real_length;
wth->phdr.caplen = length;
tm.tm_year = pletohs(&hdr.date.year)-1900;
tm.tm_mon = (hdr.date.month&0x0f)-1;
tm.tm_mday = hdr.date.day;
sec = pletohl(&hdr.date.sec);
tm.tm_hour = sec/3600;
tm.tm_min = (sec%3600)/60;
tm.tm_sec = sec%60;
tm.tm_isdst = -1;
wth->phdr.ts.secs = mktime(&tm);
wth->phdr.ts.nsecs = pletohl(&hdr.date.usec) * 1000;
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
wth->phdr.pseudo_header.eth.fcs_len = -1;
break;
case WTAP_ENCAP_LAPB:
wth->phdr.pseudo_header.x25.flags = (hdr.dce & 0x1) ?
0x00 : FROM_DCE;
break;
case WTAP_ENCAP_ATM_RFC1483:
if (!radcom_read_rec_data(wth->fh, phdr, sizeof phdr, err,
err_info))
return FALSE;
length -= 8;
wth->phdr.len -= 8;
wth->phdr.caplen -= 8;
break;
}
buffer_assure_space(wth->frame_buffer, length);
if (!radcom_read_rec_data(wth->fh,
buffer_start_ptr(wth->frame_buffer), length, err, err_info))
return FALSE;
if (wth->file_encap == WTAP_ENCAP_LAPB) {
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&fcs, sizeof fcs, wth->fh);
if (bytes_read != sizeof fcs) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
}
return TRUE;
}
static gboolean
radcom_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *pkhdr, guint8 *pd, int length,
int *err, gchar **err_info)
{
union wtap_pseudo_header *pseudo_header = &pkhdr->pseudo_header;
int ret;
struct radcomrec_hdr hdr;
guint8 phdr[8];
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
ret = radcom_read_rec_header(wth->random_fh, &hdr, err, err_info);
if (ret <= 0) {
if (ret == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = -1;
break;
case WTAP_ENCAP_LAPB:
pseudo_header->x25.flags = (hdr.dce & 0x1) ? 0x00 : FROM_DCE;
break;
case WTAP_ENCAP_ATM_RFC1483:
if (!radcom_read_rec_data(wth->random_fh, phdr, sizeof phdr,
err, err_info))
return FALSE;
break;
}
return radcom_read_rec_data(wth->random_fh, pd, length, err, err_info);
}
static int
radcom_read_rec_header(FILE_T fh, struct radcomrec_hdr *hdr, int *err,
gchar **err_info)
{
int bytes_read;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(hdr, sizeof *hdr, fh);
if (bytes_read != sizeof *hdr) {
*err = file_error(fh, err_info);
if (*err != 0)
return -1;
if (bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
return -1;
}
return 0;
}
return 1;
}
static gboolean
radcom_read_rec_data(FILE_T fh, guint8 *pd, int length, int *err,
gchar **err_info)
{
int bytes_read;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(pd, length, fh);
if (bytes_read != length) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
