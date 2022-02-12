int lanalyzer_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
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
bytes_read = file_read(&rec_header, LA_RecordHeaderSize, wth->fh);
if (bytes_read != LA_RecordHeaderSize) {
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
record_type = pletohs(rec_header.record_type);
record_length = pletohs(rec_header.record_length);
if (record_type != RT_HeaderRegular && record_type != RT_HeaderCyclic) {
return 0;
}
if (record_length < 2) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("lanalyzer: trace header record length %u < 2",
record_length);
return -1;
}
bytes_read = file_read(&header_fixed, sizeof header_fixed, wth->fh);
if (bytes_read != sizeof header_fixed) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
}
record_length -= sizeof header_fixed;
if (record_length != 0) {
comment = (char *)g_malloc(record_length + 1);
bytes_read = file_read(comment, record_length, wth->fh);
if (bytes_read != record_length) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
}
comment[record_length] = '\0';
wth->shb_hdr.opt_comment = comment;
}
wth->file_type = WTAP_FILE_LANALYZER;
lanalyzer = (lanalyzer_t *)g_malloc(sizeof(lanalyzer_t));
wth->priv = (void *)lanalyzer;
wth->subtype_read = lanalyzer_read;
wth->subtype_seek_read = lanalyzer_seek_read;
wth->snapshot_length = 0;
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
while (1) {
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&rec_header, LA_RecordHeaderSize, wth->fh);
if (bytes_read != LA_RecordHeaderSize) {
*err = file_error(wth->fh, err_info);
if (*err != 0) {
g_free(wth->priv);
return -1;
}
g_free(wth->priv);
return 0;
}
record_type = pletohs(rec_header.record_type);
record_length = pletohs(rec_header.record_length);
switch (record_type) {
case RT_Summary:
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(summary, sizeof summary,
wth->fh);
if (bytes_read != sizeof summary) {
*err = file_error(wth->fh, err_info);
if (*err != 0) {
g_free(wth->priv);
return -1;
}
g_free(wth->priv);
return 0;
}
cr_day = summary[0];
cr_month = summary[1];
cr_year = pletohs(&summary[2]);
tm.tm_year = cr_year - 1900;
tm.tm_mon = cr_month - 1;
tm.tm_mday = cr_day;
tm.tm_hour = 0;
tm.tm_min = 0;
tm.tm_sec = 0;
tm.tm_isdst = -1;
lanalyzer->start = mktime(&tm);
mxslc = pletohs(&summary[30]);
wth->snapshot_length = mxslc;
board_type = pletohs(&summary[188]);
switch (board_type) {
case BOARD_325:
wth->file_encap = WTAP_ENCAP_ETHERNET;
break;
case BOARD_325TR:
wth->file_encap = WTAP_ENCAP_TOKEN_RING;
break;
default:
g_free(wth->priv);
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("lanalyzer: board type %u unknown",
board_type);
return -1;
}
break;
case RT_PacketData:
if (file_seek(wth->fh, -LA_RecordHeaderSize, SEEK_CUR, err) == -1) {
g_free(wth->priv);
return -1;
}
return 1;
default:
if (file_seek(wth->fh, record_length, SEEK_CUR, err) == -1) {
g_free(wth->priv);
return -1;
}
break;
}
}
}
static gboolean lanalyzer_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
int packet_size = 0;
int bytes_read;
char LE_record_type[2];
char LE_record_length[2];
guint16 record_type, record_length;
gchar descriptor[DESCRIPTOR_LEN];
guint16 time_low, time_med, time_high, true_size;
guint64 t;
time_t tsecs;
lanalyzer_t *lanalyzer;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(LE_record_type, 2, wth->fh);
if (bytes_read != 2) {
*err = file_error(wth->fh, err_info);
if (*err == 0 && bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
bytes_read = file_read(LE_record_length, 2, wth->fh);
if (bytes_read != 2) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
record_type = pletohs(LE_record_type);
record_length = pletohs(LE_record_length);
if (record_type != RT_PacketData) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("lanalyzer: record type %u seen after trace summary record",
record_type);
return FALSE;
}
else {
if (record_length < DESCRIPTOR_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("lanalyzer: file has a %u-byte record, too small to have even a packet descriptor",
record_length);
return FALSE;
}
packet_size = record_length - DESCRIPTOR_LEN;
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(descriptor, DESCRIPTOR_LEN, wth->fh);
if (bytes_read != DESCRIPTOR_LEN) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
buffer_assure_space(wth->frame_buffer, packet_size);
*data_offset = file_tell(wth->fh);
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(buffer_start_ptr(wth->frame_buffer),
packet_size, wth->fh);
if (bytes_read != packet_size) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
true_size = pletohs(&descriptor[4]);
packet_size = pletohs(&descriptor[6]);
if (packet_size > record_length - DESCRIPTOR_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("lanalyzer: Record length is less than packet size");
return FALSE;
}
wth->phdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
time_low = pletohs(&descriptor[8]);
time_med = pletohs(&descriptor[10]);
time_high = pletohs(&descriptor[12]);
t = (((guint64)time_low) << 0) + (((guint64)time_med) << 16) +
(((guint64)time_high) << 32);
tsecs = (time_t) (t/2000000);
lanalyzer = (lanalyzer_t *)wth->priv;
wth->phdr.ts.secs = tsecs + lanalyzer->start;
wth->phdr.ts.nsecs = ((guint32) (t - tsecs*2000000)) * 500;
if (true_size - 4 >= packet_size) {
true_size -= 4;
}
wth->phdr.len = true_size;
wth->phdr.caplen = packet_size;
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
wth->pseudo_header.eth.fcs_len = 0;
break;
}
return TRUE;
}
static gboolean lanalyzer_seek_read(wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int length,
int *err, gchar **err_info)
{
int bytes_read;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
bytes_read = file_read(pd, length, wth->random_fh);
if (bytes_read != length) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = 0;
break;
}
return TRUE;
}
static gboolean s0write(wtap_dumper *wdh, size_t cnt, int *err)
{
static const guint8 z64[64];
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
gint32 usec = a->tv_usec;
c->tv_sec = a->tv_sec - b->tv_sec;
if (b->tv_usec > usec) {
c->tv_sec--;
usec += 1000000;
}
c->tv_usec = usec - b->tv_usec;
}
static gboolean lanalyzer_dump(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const union wtap_pseudo_header *pseudo_header _U_,
const guint8 *pd, int *err)
{
double x;
int i;
int len;
struct timeval tv;
LA_TmpInfo *itmp = (LA_TmpInfo*)(wdh->priv);
struct timeval td;
int thisSize = phdr->caplen + LA_PacketRecordSize + LA_RecordHeaderSize;
if (wdh->bytes_dumped + thisSize > LA_ProFileLimit) {
*err = EFBIG;
return FALSE;
}
len = phdr->caplen + (phdr->caplen ? LA_PacketRecordSize : 0);
if (!s16write(wdh, htoles(0x1005), err))
return FALSE;
if (!s16write(wdh, htoles(len), err))
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
if (!s16write(wdh, htoles(0x0001), err))
return FALSE;
if (!s16write(wdh, htoles(0x0008), err))
return FALSE;
if (!s16write(wdh, htoles(phdr->len + 4), err))
return FALSE;
if (!s16write(wdh, htoles(phdr->caplen), err))
return FALSE;
for (i = 0; i < 3; i++) {
if (!s16write(wdh, htoles((guint16) x), err))
return FALSE;
x /= 0xffff;
}
if (!s32write(wdh, htolel(++itmp->pkts), err))
return FALSE;
if (!s16write(wdh, htoles(itmp->lastlen), err))
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
if (fseek(wdh->fh, jump, SEEK_SET) == -1) {
*err = errno;
return FALSE;
}
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
fseek(wdh->fh, 0, SEEK_SET);
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
if (!s16write(wdh, htoles(RT_Summary), err))
return FALSE;
if (!s16write(wdh, htoles(SummarySize), err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_mday, err))
return FALSE;
if (!s8write(wdh, (guint8) (fT->tm_mon+1), err))
return FALSE;
if (!s16write(wdh, htoles(fT->tm_year + 1900), err))
return FALSE;
if (!s8write(wdh, (guint8) fT->tm_mday, err))
return FALSE;
if (!s8write(wdh, (guint8) (fT->tm_mon+1), err))
return FALSE;
if (!s16write(wdh, htoles(fT->tm_year + 1900), err))
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
if (!s16write(wdh, htoles(1), err))
return FALSE;
if (!s16write(wdh, htoles(0), err))
return FALSE;
if (!s16write(wdh, htoles(1514), err))
return FALSE;
if (!s32write(wdh, htolel(itmp->pkts), err))
return FALSE;
if (!s0write(wdh, 12, err))
return FALSE;
if (!s32write(wdh, htolel(itmp->pkts), err))
return FALSE;
if (!s0write(wdh, 34*4, err))
return FALSE;
if (!s16write(wdh, htoles(board_type), err))
return FALSE;
if (!s0write(wdh, 20, err))
return FALSE;
if (!s16write(wdh, htoles(RT_SubfileSummary), err))
return FALSE;
if (!s16write(wdh, htoles(LA_SubfileSummaryRecordSize-4), err))
return FALSE;
if (!s16write(wdh, htoles(1), err))
return FALSE;
if (!s32write(wdh, htolel(itmp->pkts), err))
return FALSE;
if (!wtap_dump_file_write(wdh, &LA_CyclicInformationFake,
sizeof LA_CyclicInformationFake, err))
return FALSE;
if (!s16write(wdh, htoles(RT_Index), err))
return FALSE;
if (!s16write(wdh, htoles(LA_IndexRecordSize -4), err))
return FALSE;
if (!s16write(wdh, htoles(LA_IndexSize), err))
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
