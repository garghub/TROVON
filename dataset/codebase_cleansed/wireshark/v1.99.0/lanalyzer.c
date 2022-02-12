int lanalyzer_open(wtap *wth, int *err, gchar **err_info)
{
LA_RecordHeader rec_header;
char header_fixed[2];
char *comment;
char summary[210];
guint16 board_type, mxslc;
guint16 record_type, record_length;
guint8 cr_day, cr_month;
guint16 cr_year;
struct tm tm;
lanalyzer_t *lanalyzer;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, &rec_header, LA_RecordHeaderSize,
err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
record_type = pletoh16(rec_header.record_type);
record_length = pletoh16(rec_header.record_length);
if (record_type != RT_HeaderRegular && record_type != RT_HeaderCyclic) {
return 0;
}
if (record_length < 2) {
return 0;
}
if (!wtap_read_bytes(wth->fh, &header_fixed, sizeof header_fixed,
err, err_info)) {
if (*err == WTAP_ERR_SHORT_READ) {
return 0;
}
return -1;
}
record_length -= sizeof header_fixed;
if (record_length != 0) {
comment = (char *)g_malloc(record_length + 1);
if (!wtap_read_bytes(wth->fh, comment, record_length,
err, err_info)) {
if (*err == WTAP_ERR_SHORT_READ) {
return 0;
}
return -1;
}
comment[record_length] = '\0';
wth->shb_hdr.opt_comment = comment;
}
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_LANALYZER;
lanalyzer = (lanalyzer_t *)g_malloc(sizeof(lanalyzer_t));
wth->priv = (void *)lanalyzer;
wth->subtype_read = lanalyzer_read;
wth->subtype_seek_read = lanalyzer_seek_read;
wth->snapshot_length = 0;
wth->file_tsprec = WTAP_TSPREC_NSEC;
while (1) {
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes_or_eof(wth->fh, &rec_header,
LA_RecordHeaderSize, err, err_info)) {
if (*err == 0) {
return 1;
}
return -1;
}
record_type = pletoh16(rec_header.record_type);
record_length = pletoh16(rec_header.record_length);
switch (record_type) {
case RT_Summary:
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, summary,
sizeof summary, err, err_info))
return -1;
cr_day = summary[0];
cr_month = summary[1];
cr_year = pletoh16(&summary[2]);
tm.tm_year = cr_year - 1900;
tm.tm_mon = cr_month - 1;
tm.tm_mday = cr_day;
tm.tm_hour = 0;
tm.tm_min = 0;
tm.tm_sec = 0;
tm.tm_isdst = -1;
lanalyzer->start = mktime(&tm);
mxslc = pletoh16(&summary[30]);
wth->snapshot_length = mxslc;
board_type = pletoh16(&summary[188]);
switch (board_type) {
case BOARD_325:
wth->file_encap = WTAP_ENCAP_ETHERNET;
break;
case BOARD_325TR:
wth->file_encap = WTAP_ENCAP_TOKEN_RING;
break;
default:
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("lanalyzer: board type %u unknown",
board_type);
return -1;
}
break;
case RT_PacketData:
if (file_seek(wth->fh, -LA_RecordHeaderSize, SEEK_CUR, err) == -1) {
return -1;
}
return 1;
default:
if (file_seek(wth->fh, record_length, SEEK_CUR, err) == -1) {
return -1;
}
break;
}
}
}
static gboolean lanalyzer_read_trace_record(wtap *wth, FILE_T fh,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
char LE_record_type[2];
char LE_record_length[2];
guint16 record_type, record_length;
int record_data_size;
int packet_size;
gchar descriptor[DESCRIPTOR_LEN];
lanalyzer_t *lanalyzer;
guint16 time_low, time_med, time_high, true_size;
guint64 t;
time_t tsecs;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes_or_eof(fh, LE_record_type, 2, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, LE_record_length, 2, err, err_info))
return FALSE;
record_type = pletoh16(LE_record_type);
record_length = pletoh16(LE_record_length);
if (record_type != RT_PacketData) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("lanalyzer: record type %u seen after trace summary record",
record_type);
return FALSE;
}
if (record_length < DESCRIPTOR_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("lanalyzer: file has a %u-byte record, too small to have even a packet descriptor",
record_length);
return FALSE;
}
record_data_size = record_length - DESCRIPTOR_LEN;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(fh, descriptor, DESCRIPTOR_LEN, err, err_info))
return FALSE;
true_size = pletoh16(&descriptor[4]);
packet_size = pletoh16(&descriptor[6]);
if (packet_size > record_data_size) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("lanalyzer: Record length is less than packet size");
return FALSE;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
time_low = pletoh16(&descriptor[8]);
time_med = pletoh16(&descriptor[10]);
time_high = pletoh16(&descriptor[12]);
t = (((guint64)time_low) << 0) + (((guint64)time_med) << 16) +
(((guint64)time_high) << 32);
tsecs = (time_t) (t/2000000);
lanalyzer = (lanalyzer_t *)wth->priv;
phdr->ts.secs = tsecs + lanalyzer->start;
phdr->ts.nsecs = ((guint32) (t - tsecs*2000000)) * 500;
if (true_size - 4 >= packet_size) {
true_size -= 4;
}
phdr->len = true_size;
phdr->caplen = packet_size;
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
phdr->pseudo_header.eth.fcs_len = 0;
break;
}
return wtap_read_packet_bytes(fh, buf, packet_size, err, err_info);
}
static gboolean lanalyzer_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
return lanalyzer_read_trace_record(wth, wth->fh, &wth->phdr,
wth->frame_buffer, err, err_info);
}
static gboolean lanalyzer_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!lanalyzer_read_trace_record(wth, wth->random_fh, phdr, buf,
err, err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean s0write(wtap_dumper *wdh, size_t cnt, int *err)
{
size_t snack;
while (cnt) {
snack = cnt > 64 ? 64 : cnt;
if (!wtap_dump_file_write(wdh, z64, snack, err))
return FALSE;
cnt -= snack;
}
return TRUE;
}
static gboolean s8write(wtap_dumper *wdh, const guint8 s8, int *err)
{
return wtap_dump_file_write(wdh, &s8, 1, err);
}
static gboolean s16write(wtap_dumper *wdh, const guint16 s16, int *err)
{
return wtap_dump_file_write(wdh, &s16, 2, err);
}
static gboolean s32write(wtap_dumper *wdh, const guint32 s32, int *err)
{
return wtap_dump_file_write(wdh, &s32, 4, err);
}
static void my_timersub(const struct timeval *a,
const struct timeval *b,
struct timeval *c)
{
gint32 usec = (gint32)a->tv_usec;
c->tv_sec = a->tv_sec - b->tv_sec;
if (b->tv_usec > usec) {
c->tv_sec--;
usec += 1000000;
}
c->tv_usec = usec - b->tv_usec;
}
static gboolean lanalyzer_dump(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
double x;
int i;
int len;
struct timeval tv;
LA_TmpInfo *itmp = (LA_TmpInfo*)(wdh->priv);
struct timeval td;
int thisSize = phdr->caplen + LA_PacketRecordSize + LA_RecordHeaderSize;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_REC_TYPE_UNSUPPORTED;
return FALSE;
}
if (wdh->bytes_dumped + thisSize > LA_ProFileLimit) {
*err = EFBIG;
return FALSE;
}
len = phdr->caplen + (phdr->caplen ? LA_PacketRecordSize : 0);
if (len > 65535) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
if (!s16write(wdh, GUINT16_TO_LE(0x1005), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(len), err))
return FALSE;
tv.tv_sec = (long int) phdr->ts.secs;
tv.tv_usec = phdr->ts.nsecs / 1000;
if (!itmp->init) {
itmp->start = tv;
itmp->pkts = 0;
itmp->init = TRUE;
itmp->encap = wdh->encap;
itmp->lastlen = 0;
}
my_timersub(&(tv),&(itmp->start),&td);
x = (double) td.tv_usec;
x += (double) td.tv_sec * 1000000;
x *= 2;
if (!s16write(wdh, GUINT16_TO_LE(0x0001), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(0x0008), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(phdr->len + 4), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(phdr->caplen), err))
return FALSE;
for (i = 0; i < 3; i++) {
if (!s16write(wdh, GUINT16_TO_LE((guint16) x), err))
return FALSE;
x /= 0xffff;
}
if (!s32write(wdh, GUINT32_TO_LE(++itmp->pkts), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(itmp->lastlen), err))
return FALSE;
itmp->lastlen = len;
if (!s0write(wdh, 12, err))
return FALSE;
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
wdh->bytes_dumped += thisSize;
return TRUE;
}
int lanalyzer_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if ( encap != WTAP_ENCAP_ETHERNET
&& encap != WTAP_ENCAP_TOKEN_RING )
return WTAP_ERR_UNSUPPORTED_ENCAP;
return 0;
}
gboolean lanalyzer_dump_open(wtap_dumper *wdh, int *err)
{
int jump;
void *tmp;
tmp = g_malloc(sizeof(LA_TmpInfo));
if (!tmp) {
*err = errno;
return FALSE;
}
((LA_TmpInfo*)tmp)->init = FALSE;
wdh->priv = tmp;
wdh->subtype_write = lanalyzer_dump;
wdh->subtype_close = lanalyzer_dump_close;
jump = sizeof (LA_HeaderRegularFake)
+ sizeof (LA_RxChannelNameFake)
+ sizeof (LA_TxChannelNameFake)
+ sizeof (LA_RxTemplateNameFake)
+ sizeof (LA_TxTemplateNameFake)
+ sizeof (LA_DisplayOptionsFake)
+ LA_SummaryRecordSize
+ LA_SubfileSummaryRecordSize
+ sizeof (LA_CyclicInformationFake)
+ LA_IndexRecordSize;
if (wtap_dump_file_seek(wdh, jump, SEEK_SET, err) == -1)
return FALSE;
wdh->bytes_dumped = jump;
return TRUE;
}
static gboolean lanalyzer_dump_header(wtap_dumper *wdh, int *err)
{
LA_TmpInfo *itmp = (LA_TmpInfo*)(wdh->priv);
guint16 board_type = itmp->encap == WTAP_ENCAP_TOKEN_RING
? BOARD_325TR
: BOARD_325;
time_t secs;
struct tm *fT;
secs = itmp->start.tv_sec;
fT = localtime(&secs);
if (fT == NULL)
return FALSE;
if (wtap_dump_file_seek(wdh, 0, SEEK_SET, err) == -1)
return FALSE;
if (!wtap_dump_file_write(wdh, &LA_HeaderRegularFake,
sizeof LA_HeaderRegularFake, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &LA_RxChannelNameFake,
sizeof LA_RxChannelNameFake, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &LA_TxChannelNameFake,
sizeof LA_TxChannelNameFake, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &LA_RxTemplateNameFake,
sizeof LA_RxTemplateNameFake, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &LA_TxTemplateNameFake,
sizeof LA_TxTemplateNameFake, err))
return FALSE;
if (!wtap_dump_file_write(wdh, &LA_DisplayOptionsFake,
sizeof LA_DisplayOptionsFake, err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(RT_Summary), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(SummarySize), err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_mday, err))
return FALSE;
if (!s8write(wdh, (guint8) (fT->tm_mon+1), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(fT->tm_year + 1900), err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_mday, err))
return FALSE;
if (!s8write(wdh, (guint8) (fT->tm_mon+1), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(fT->tm_year + 1900), err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_sec, err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_min, err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_hour, err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_mday, err))
return FALSE;
if (!s0write(wdh, 2, err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_sec, err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_min, err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_hour, err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_mday, err))
return FALSE;
if (!s0write(wdh, 2, err))
return FALSE;
if (!s0write(wdh, 6, err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(1), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(0), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(1514), err))
return FALSE;
if (!s32write(wdh, GUINT32_TO_LE(itmp->pkts), err))
return FALSE;
if (!s0write(wdh, 12, err))
return FALSE;
if (!s32write(wdh, GUINT32_TO_LE(itmp->pkts), err))
return FALSE;
if (!s0write(wdh, 34*4, err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(board_type), err))
return FALSE;
if (!s0write(wdh, 20, err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(RT_SubfileSummary), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(LA_SubfileSummaryRecordSize-4), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(1), err))
return FALSE;
if (!s32write(wdh, GUINT32_TO_LE(itmp->pkts), err))
return FALSE;
if (!wtap_dump_file_write(wdh, &LA_CyclicInformationFake,
sizeof LA_CyclicInformationFake, err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(RT_Index), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(LA_IndexRecordSize -4), err))
return FALSE;
if (!s16write(wdh, GUINT16_TO_LE(LA_IndexSize), err))
return FALSE;
if (!s0write(wdh, LA_IndexRecordSize - 6, err))
return FALSE;
return TRUE;
}
static gboolean lanalyzer_dump_close(wtap_dumper *wdh, int *err)
{
lanalyzer_dump_header(wdh,err);
return *err ? FALSE : TRUE;
}
