static guint64 ns_hrtime2nsec(guint32 tm)
{
guint32 val = tm & NSPR_HRTIME_MASKTM;
switch(tm & NSPR_HRTIME_MASKFMT)
{
case NSPR_HRTIME_SEC: return (guint64)val*1000000000;
case NSPR_HRTIME_MSEC: return (guint64)val*1000000;
case NSPR_HRTIME_USEC: return (guint64)val*1000;
case NSPR_HRTIME_NSEC: return val;
}
return tm;
}
static gboolean
nstrace_read_buf(FILE_T fh, void *buf, guint32 buflen, int *err,
gchar **err_info)
{
int bytes_read;
bytes_read = file_read(buf, buflen, fh);
if (bytes_read < 0) {
*err = file_error(fh, err_info);
return FALSE;
}
if ((guint32)bytes_read != buflen) {
*err = 0;
return FALSE;
}
return TRUE;
}
wtap_open_return_val nstrace_open(wtap *wth, int *err, gchar **err_info)
{
gchar *nstrace_buf;
gint64 file_size;
gint32 page_size;
nstrace_t *nstrace;
if ((file_size = wtap_file_size(wth, err)) == -1)
return WTAP_OPEN_NOT_MINE;
nstrace_buf = (gchar *)g_malloc(NSPR_PAGESIZE);
page_size = GET_READ_PAGE_SIZE(file_size);
switch ((wth->file_type_subtype = nspm_signature_version(wth, nstrace_buf, page_size)))
{
case WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0:
wth->file_encap = WTAP_ENCAP_NSTRACE_1_0;
break;
case WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0:
wth->file_encap = WTAP_ENCAP_NSTRACE_2_0;
break;
case WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0:
wth->file_encap = WTAP_ENCAP_NSTRACE_3_0;
g_free(nstrace_buf);
nstrace_buf = (gchar *)g_malloc(NSPR_PAGESIZE_TRACE);
page_size = GET_READ_PAGE_SIZEV3(file_size);
break;
case WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_5:
wth->file_encap = WTAP_ENCAP_NSTRACE_3_5;
g_free(nstrace_buf);
nstrace_buf = (gchar *)g_malloc(NSPR_PAGESIZE_TRACE);
page_size = GET_READ_PAGE_SIZEV3(file_size);
break;
default:
g_free(nstrace_buf);
return WTAP_OPEN_NOT_MINE;
}
if ((file_seek(wth->fh, 0, SEEK_SET, err)) == -1)
{
g_free(nstrace_buf);
return WTAP_OPEN_ERROR;
}
if (!wtap_read_bytes(wth->fh, nstrace_buf, page_size, err, err_info))
{
g_free(nstrace_buf);
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
switch (wth->file_type_subtype)
{
case WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0:
wth->subtype_read = nstrace_read_v10;
wth->subtype_seek_read = nstrace_seek_read_v10;
break;
case WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0:
wth->subtype_read = nstrace_read_v20;
wth->subtype_seek_read = nstrace_seek_read_v20;
break;
case WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0:
wth->subtype_read = nstrace_read_v30;
wth->subtype_seek_read = nstrace_seek_read_v30;
break;
case WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_5:
wth->subtype_read = nstrace_read_v30;
wth->subtype_seek_read = nstrace_seek_read_v30;
break;
}
wth->subtype_close = nstrace_close;
nstrace = (nstrace_t *)g_malloc(sizeof(nstrace_t));
wth->priv = (void *)nstrace;
nstrace->pnstrace_buf = nstrace_buf;
nstrace->xxx_offset = 0;
nstrace->nstrace_buflen = page_size;
nstrace->nstrace_buf_offset = 0;
nstrace->nspm_curtime = 0;
nstrace->nspm_curtimemsec = 0;
nstrace->nspm_curtimelastmsec = 0;
nstrace->nsg_creltime = 0;
nstrace->file_size = file_size;
if ((nstrace_set_start_time(wth, err, err_info)) == FALSE)
{
if (*err != 0)
{
return WTAP_OPEN_ERROR;
}
if ((file_seek(wth->fh, 0, SEEK_SET, err)) == -1)
{
return WTAP_OPEN_ERROR;
}
if (!wtap_read_bytes(wth->fh, nstrace_buf, page_size, err, err_info))
{
return WTAP_OPEN_ERROR;
}
nstrace->nstrace_buf_offset = 0;
}
wth->file_tsprec = WTAP_TSPREC_NSEC;
wth->phdr.ts.secs = nstrace->nspm_curtime;
wth->phdr.ts.nsecs = 0;
*err = 0;
return WTAP_OPEN_MINE;
}
static guint32
nspm_signature_version(wtap *wth, gchar *nstrace_buf, gint32 len)
{
gchar *dp = nstrace_buf;
int bytes_read;
bytes_read = file_read(dp, len, wth->fh);
if (bytes_read == len) {
for ( ; len > (gint32)(MIN(sizeof(NSPR_SIGSTR_V10), sizeof(NSPR_SIGSTR_V20))); dp++, len--)
{
#define sigv10p ((nspr_signature_v10_t*)dp)
if ((pletoh16(&sigv10p->nsprRecordType) == NSPR_SIGNATURE_V10) &&
(pletoh16(&sigv10p->nsprRecordSize) <= len) &&
((gint32)sizeof(NSPR_SIGSTR_V10) <= len) &&
(!nspm_signature_isv10(sigv10p->sig_Signature)))
return WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0;
#undef sigv10p
#define sigv20p ((nspr_signature_v20_t*)dp)
if ((sigv20p->sig_RecordType == NSPR_SIGNATURE_V20) &&
(sigv20p->sig_RecordSize <= len) &&
((gint32)sizeof(NSPR_SIGSTR_V20) <= len))
{
if (!nspm_signature_isv20(sigv20p->sig_Signature)){
return WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0;
} else if (!nspm_signature_isv30(sigv20p->sig_Signature)){
return WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0;
}else if (!nspm_signature_isv35(sigv20p->sig_Signature)){
return WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_5;
}
}
#undef sigv20p
}
}
return WTAP_FILE_TYPE_SUBTYPE_UNKNOWN;
}
static gboolean nstrace_set_start_time(wtap *wth, int *err, gchar **err_info)
{
if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0)
return nstrace_set_start_time_v10(wth, err, err_info);
else if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0)
return nstrace_set_start_time_v20(wth, err, err_info);
else if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0)
return nstrace_set_start_time_v20(wth, err, err_info);
return FALSE;
}
static gboolean nstrace_read_v10(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
nstrace_t *nstrace = (nstrace_t *)wth->priv;
guint64 nsg_creltime = nstrace->nsg_creltime;
gchar *nstrace_buf = nstrace->pnstrace_buf;
guint32 nstrace_buf_offset = nstrace->nstrace_buf_offset;
guint32 nstrace_buflen = nstrace->nstrace_buflen;
*err = 0;
*err_info = NULL;
do
{
while ((nstrace_buf_offset < nstrace_buflen) &&
((nstrace_buflen - nstrace_buf_offset) >= ((gint32)sizeof((( nspr_header_v10_t*)&nstrace_buf[nstrace_buf_offset])->ph_RecordType))))
{
#define GENERATE_CASE_FULL(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,full,ver,fp,HEADERVER);
#define GENERATE_CASE_PART(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,part,ver,pp,HEADERVER);
switch (pletoh16(&(( nspr_header_v10_t*)&nstrace_buf[nstrace_buf_offset])->ph_RecordType))
{
GENERATE_CASE_FULL(&wth->phdr,10,100)
GENERATE_CASE_PART(&wth->phdr,10,100)
#undef GENERATE_CASE_FULL
#undef GENERATE_CASE_PART
case NSPR_ABSTIME_V10:
{
nspr_pktracefull_v10_t *fp = (nspr_pktracefull_v10_t *) &nstrace_buf[nstrace_buf_offset];
if (pletoh16(&fp->nsprRecordSize) == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("nstrace: zero size record found");
return FALSE;
}
ns_setabstime(nstrace, pletoh32(((nspr_abstime_v10_t *) fp)->abs_Time), pletoh32(&((nspr_abstime_v10_t *) fp)->abs_RelTime));
nstrace_buf_offset += pletoh16(&fp->nsprRecordSize);
break;
}
case NSPR_RELTIME_V10:
{
nspr_pktracefull_v10_t *fp = (nspr_pktracefull_v10_t *) &nstrace_buf[nstrace_buf_offset];
if (pletoh16(&fp->nsprRecordSize) == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("nstrace: zero size record found");
return FALSE;
}
ns_setrelativetime(nstrace, pletoh32(((nspr_abstime_v10_t *) fp)->abs_RelTime));
nstrace_buf_offset += pletoh16(&fp->nsprRecordSize);
break;
}
case NSPR_UNUSEDSPACE_V10:
nstrace_buf_offset = nstrace_buflen;
break;
default:
{
nspr_pktracefull_v10_t *fp = (nspr_pktracefull_v10_t *) &nstrace_buf[nstrace_buf_offset];
if (pletoh16(&fp->nsprRecordSize) == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("nstrace: zero size record found");
return FALSE;
}
nstrace_buf_offset += pletoh16(&fp->nsprRecordSize);
break;
}
}
}
nstrace_buf_offset = 0;
nstrace->xxx_offset += nstrace_buflen;
nstrace_buflen = GET_READ_PAGE_SIZE((nstrace->file_size - nstrace->xxx_offset));
}while((nstrace_buflen > 0) && (nstrace_read_buf(wth->fh, nstrace_buf, nstrace_buflen, err, err_info)));
return FALSE;
}
static gboolean nstrace_read_v20(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
nstrace_t *nstrace = (nstrace_t *)wth->priv;
guint64 nsg_creltime = nstrace->nsg_creltime;
gchar *nstrace_buf = nstrace->pnstrace_buf;
guint32 nstrace_buf_offset = nstrace->nstrace_buf_offset;
guint32 nstrace_buflen = nstrace->nstrace_buflen;
*err = 0;
*err_info = NULL;
do
{
while ((nstrace_buf_offset < nstrace_buflen) &&
((nstrace_buflen - nstrace_buf_offset) >= ((gint32)sizeof((( nspr_hd_v20_t*)&nstrace_buf[nstrace_buf_offset])->phd_RecordType))))
{
switch ((( nspr_hd_v20_t*)&nstrace_buf[nstrace_buf_offset])->phd_RecordType)
{
#define GENERATE_CASE_FULL(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define GENERATE_CASE_FULL_V25(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define GENERATE_CASE_PART(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
#define GENERATE_CASE_PART_V25(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
case NSPR_PDPKTRACEPARTNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
GENERATE_CASE_FULL(&wth->phdr,20,200);
GENERATE_CASE_PART(&wth->phdr,20,200);
GENERATE_CASE_FULL(&wth->phdr,21,201);
GENERATE_CASE_PART(&wth->phdr,21,201);
GENERATE_CASE_FULL(&wth->phdr,22,202);
GENERATE_CASE_PART(&wth->phdr,22,202);
GENERATE_CASE_FULL(&wth->phdr,23,203);
GENERATE_CASE_PART(&wth->phdr,23,203);
GENERATE_CASE_FULL_V25(&wth->phdr,24,204);
GENERATE_CASE_PART_V25(&wth->phdr,24,204);
GENERATE_CASE_FULL_V25(&wth->phdr,25,205);
GENERATE_CASE_PART_V25(&wth->phdr,25,205);
GENERATE_CASE_FULL_V25(&wth->phdr,26,206);
GENERATE_CASE_PART_V25(&wth->phdr,26,206);
#undef GENERATE_CASE_FULL
#undef GENERATE_CASE_FULL_V25
#undef GENERATE_CASE_PART
#undef GENERATE_CASE_PART_V25
case NSPR_ABSTIME_V20:
{
nspr_pktracefull_v20_t *fp20 = (nspr_pktracefull_v20_t *) &nstrace_buf[nstrace_buf_offset];
if (nspr_getv20recordsize((nspr_hd_v20_t *)fp20) == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("nstrace: zero size record found");
return FALSE;
}
nstrace_buf_offset += nspr_getv20recordsize((nspr_hd_v20_t *)fp20);
ns_setabstime(nstrace, pletoh32(&((nspr_abstime_v20_t *) fp20)->abs_Time), pletoh16(&((nspr_abstime_v20_t *) fp20)->abs_RelTime));
break;
}
case NSPR_RELTIME_V20:
{
nspr_pktracefull_v20_t *fp20 = (nspr_pktracefull_v20_t *) &nstrace_buf[nstrace_buf_offset];
if (nspr_getv20recordsize((nspr_hd_v20_t *)fp20) == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("nstrace: zero size record found");
return FALSE;
}
ns_setrelativetime(nstrace, pletoh16(&((nspr_abstime_v20_t *) fp20)->abs_RelTime));
nstrace_buf_offset += nspr_getv20recordsize((nspr_hd_v20_t *)fp20);
break;
}
case NSPR_UNUSEDSPACE_V20:
{
if (nstrace_buf_offset >= NSPR_PAGESIZE/2)
nstrace_buf_offset = nstrace_buflen;
else
nstrace_buf_offset = NSPR_PAGESIZE/2;
break;
}
default:
{
nspr_pktracefull_v20_t *fp20 = (nspr_pktracefull_v20_t *) &nstrace_buf[nstrace_buf_offset];
if (nspr_getv20recordsize((nspr_hd_v20_t *)fp20) == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("nstrace: zero size record found");
return FALSE;
}
nstrace_buf_offset += nspr_getv20recordsize((nspr_hd_v20_t *)fp20);
break;
}
}
}
nstrace_buf_offset = 0;
nstrace->xxx_offset += nstrace_buflen;
nstrace_buflen = GET_READ_PAGE_SIZE((nstrace->file_size - nstrace->xxx_offset));
}while((nstrace_buflen > 0) && (nstrace_read_buf(wth->fh, nstrace_buf, nstrace_buflen, err, err_info)));
return FALSE;
}
static gboolean nstrace_read_v30(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
nstrace_t *nstrace = (nstrace_t *)wth->priv;
guint64 nsg_creltime;
gchar *nstrace_buf = nstrace->pnstrace_buf;
guint32 nstrace_buf_offset = nstrace->nstrace_buf_offset;
guint32 nstrace_buflen = nstrace->nstrace_buflen;
guint8* nstrace_tmpbuff;
guint32 nstrace_tmpbuff_off=0,nst_dataSize=0,rec_size=0,nsg_nextPageOffset=0;
nspr_hd_v20_t *hdp;
int bytes_read = 0;
*err = 0;
*err_info = NULL;
if(nstrace_buflen == 0){
return FALSE;
}
nstrace_tmpbuff = (guint8*)g_malloc(65536);
do
{
if (!nstrace_buf[nstrace_buf_offset] && nstrace_buf_offset <= NSPR_PAGESIZE_TRACE){
nstrace_buf_offset = NSPR_PAGESIZE_TRACE;
}
if (file_eof(wth->fh) && bytes_read > 0 && bytes_read < NSPR_PAGESIZE_TRACE){
memset(&nstrace_buf[bytes_read], 0, NSPR_PAGESIZE_TRACE-bytes_read);
}
while ((nstrace_buf_offset < NSPR_PAGESIZE_TRACE) &&
nstrace_buf[nstrace_buf_offset])
{
hdp = (nspr_hd_v20_t *) &nstrace_buf[nstrace_buf_offset];
if (nspr_getv20recordsize(hdp) == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("nstrace: zero size record found");
g_free(nstrace_tmpbuff);
return FALSE;
}
switch (hdp->phd_RecordType)
{
#define GENERATE_CASE_FULL_V30(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
GENERATE_CASE_FULL_V30(&wth->phdr,30,300);
#undef GENERATE_CASE_FULL_V30
#define GENERATE_CASE_FULL_V35(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
GENERATE_CASE_FULL_V35(&wth->phdr,35,350);
#undef GENERATE_CASE_FULL_V35
case NSPR_ABSTIME_V20:
{
nstrace_buf_offset += nspr_getv20recordsize(hdp);
ns_setabstime(nstrace, pletoh32(&((nspr_abstime_v20_t *) &nstrace_buf[nstrace_buf_offset])->abs_Time), pletoh16(&((nspr_abstime_v20_t *) &nstrace_buf[nstrace_buf_offset])->abs_RelTime));
break;
}
case NSPR_RELTIME_V20:
{
ns_setrelativetime(nstrace, pletoh16(&((nspr_abstime_v20_t *) &nstrace_buf[nstrace_buf_offset])->abs_RelTime));
nstrace_buf_offset += nspr_getv20recordsize(hdp);
break;
}
default:
{
nstrace_buf_offset += nspr_getv20recordsize(hdp);
break;
}
}
}
nstrace_buf_offset = 0;
nstrace->xxx_offset += nstrace_buflen;
nstrace_buflen = NSPR_PAGESIZE_TRACE;
} while((nstrace_buflen > 0) && (bytes_read = file_read(nstrace_buf, nstrace_buflen, wth->fh)) > 0 && (file_eof(wth->fh) || (guint32)bytes_read == nstrace_buflen));
if (bytes_read < 0)
*err = file_error(wth->fh, err_info);
else
*err = 0;
g_free(nstrace_tmpbuff);
return FALSE;
}
static gboolean nstrace_seek_read_v10(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
nspr_hd_v10_t hdr;
guint record_length;
guint8 *pd;
unsigned int bytes_to_read;
*err = 0;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!wtap_read_bytes(wth->random_fh, (void *)&hdr, sizeof hdr,
err, err_info))
return FALSE;
record_length = nspr_getv10recordsize(&hdr);
ws_buffer_assure_space(buf, record_length);
pd = ws_buffer_start_ptr(buf);
memcpy(pd, (void *)&hdr, sizeof hdr);
if (record_length > sizeof hdr) {
bytes_to_read = (unsigned int)(record_length - sizeof hdr);
if (!wtap_read_bytes(wth->random_fh, pd + sizeof hdr, bytes_to_read,
err, err_info))
return FALSE;
}
#define GENERATE_CASE_FULL(phdr,type,HEADERVER) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
PACKET_DESCRIBE(phdr,FULL,full,type,fp,HEADERVER);\
break;
#define GENERATE_CASE_PART(phdr,type,HEADERVER) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
PACKET_DESCRIBE(phdr,PART,part,type,pp,HEADERVER);\
break;
switch (pletoh16(&(( nspr_header_v10_t*)pd)->ph_RecordType))
{
GENERATE_CASE_FULL(phdr,10,100)
GENERATE_CASE_PART(phdr,10,100)
}
#undef GENERATE_CASE_FULL
#undef GENERATE_CASE_PART
return TRUE;
}
static gboolean nstrace_seek_read_v20(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
nspr_hd_v20_t hdr;
guint record_length;
guint hdrlen;
guint8 *pd;
unsigned int bytes_to_read;
guint64 nsg_creltime;
*err = 0;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!wtap_read_bytes(wth->random_fh, (void *)&hdr, 2, err, err_info))
return FALSE;
hdrlen = 2;
if (hdr.phd_RecordSizeLow & NSPR_V20RECORDSIZE_2BYTES) {
if (!wtap_read_bytes(wth->random_fh, (void *)&hdr.phd_RecordSizeHigh, 1,
err, err_info))
return FALSE;
hdrlen = 3;
}
record_length = nspr_getv20recordsize(&hdr);
ws_buffer_assure_space(buf, record_length);
pd = ws_buffer_start_ptr(buf);
memcpy(pd, (void *)&hdr, hdrlen);
if (record_length > hdrlen) {
bytes_to_read = (unsigned int)(record_length - hdrlen);
if (!wtap_read_bytes(wth->random_fh, pd + hdrlen, bytes_to_read,
err, err_info))
return FALSE;
}
#define GENERATE_CASE_FULL(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define GENERATE_CASE_FULL_V25(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define GENERATE_CASE_PART(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
#define GENERATE_CASE_PART_V25(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
case NSPR_PDPKTRACEPARTNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
switch ((( nspr_hd_v20_t*)pd)->phd_RecordType)
{
GENERATE_CASE_FULL(phdr,20,200)
GENERATE_CASE_PART(phdr,20,200)
GENERATE_CASE_FULL(phdr,21,201)
GENERATE_CASE_PART(phdr,21,201)
GENERATE_CASE_FULL(phdr,22,202)
GENERATE_CASE_PART(phdr,22,202)
GENERATE_CASE_FULL(phdr,23,203)
GENERATE_CASE_PART(phdr,23,203)
GENERATE_CASE_FULL_V25(phdr,24,204)
GENERATE_CASE_PART_V25(phdr,24,204)
GENERATE_CASE_FULL_V25(phdr,25,205)
GENERATE_CASE_PART_V25(phdr,25,205)
GENERATE_CASE_FULL_V25(phdr,26,206)
GENERATE_CASE_PART_V25(phdr,26,206)
}
#undef GENERATE_CASE_FULL
#undef GENERATE_CASE_FULL_V25
#undef GENERATE_CASE_PART
#undef GENERATE_CASE_PART_V25
return TRUE;
}
static gboolean nstrace_seek_read_v30(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
nspr_hd_v20_t hdr;
guint record_length;
guint hdrlen;
guint8 *pd;
unsigned int bytes_to_read;
guint64 nsg_creltime;
*err = 0;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!wtap_read_bytes(wth->random_fh, (void *)&hdr, 2, err, err_info))
return FALSE;
hdrlen = 2;
if (hdr.phd_RecordSizeLow & NSPR_V20RECORDSIZE_2BYTES) {
if (!wtap_read_bytes(wth->random_fh, (void *)&hdr.phd_RecordSizeHigh, 1,
err, err_info))
return FALSE;
hdrlen = 3;
}
record_length = nspr_getv20recordsize(&hdr);
ws_buffer_assure_space(buf, record_length);
pd = ws_buffer_start_ptr(buf);
memcpy(pd, (void *)&hdr, hdrlen);
if (record_length > hdrlen) {
bytes_to_read = (unsigned int)(record_length - hdrlen);
if (!wtap_read_bytes(wth->random_fh, pd + hdrlen, bytes_to_read,
err, err_info))
return FALSE;
}
(phdr)->caplen = (phdr)->len = record_length;
#define GENERATE_CASE_V30(phdr,ver,HEADERVER) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
switch ((( nspr_hd_v20_t*)pd)->phd_RecordType)
{
GENERATE_CASE_V30(phdr,30, 300);
GENERATE_CASE_V30(phdr,35, 350);
}
return TRUE;
}
static void nstrace_close(wtap *wth)
{
nstrace_t *nstrace = (nstrace_t *)wth->priv;
g_free(nstrace->pnstrace_buf);
}
int nstrace_10_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_NSTRACE_1_0)
return 0;
return WTAP_ERR_UNWRITABLE_ENCAP;
}
int nstrace_20_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_NSTRACE_2_0)
return 0;
return WTAP_ERR_UNWRITABLE_ENCAP;
}
int nstrace_30_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_NSTRACE_3_0)
return 0;
return WTAP_ERR_UNWRITABLE_ENCAP;
}
int nstrace_35_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_NSTRACE_3_5)
return 0;
return WTAP_ERR_UNWRITABLE_ENCAP;
}
gboolean nstrace_dump_open(wtap_dumper *wdh, int *err _U_)
{
nstrace_dump_t *nstrace;
wdh->subtype_write = nstrace_dump;
nstrace = (nstrace_dump_t *)g_malloc(sizeof(nstrace_dump_t));
wdh->priv = (void *)nstrace;
nstrace->page_offset = 0;
if ((wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0) ||
(wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_5))
nstrace->page_len = NSPR_PAGESIZE_TRACE;
else
nstrace->page_len = NSPR_PAGESIZE;
nstrace->absrec_time = 0;
nstrace->newfile = TRUE;
return TRUE;
}
static gboolean nstrace_add_signature(wtap_dumper *wdh, int *err)
{
nstrace_dump_t *nstrace = (nstrace_dump_t *)wdh->priv;
if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0)
{
guint16 val16b;
nspr_signature_v10_t sig10;
val16b = GUINT16_TO_LE(NSPR_SIGNATURE_V10);
memcpy(sig10.phd.ph_RecordType, &val16b, sizeof sig10.phd.ph_RecordType);
val16b = GUINT16_TO_LE(nspr_signature_v10_s);
memcpy(sig10.phd.ph_RecordSize, &val16b, sizeof sig10.phd.ph_RecordSize);
memset(sig10.sig_Signature, 0, NSPR_SIGSIZE_V10);
g_strlcpy(sig10.sig_Signature, NSPR_SIGSTR_V10, NSPR_SIGSIZE_V10);
if (!wtap_dump_file_write(wdh, &sig10, nspr_signature_v10_s,
err))
return FALSE;
nstrace->page_offset += (guint16) nspr_signature_v10_s;
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0)
{
nspr_signature_v20_t sig20;
sig20.sig_RecordType = NSPR_SIGNATURE_V20;
sig20.sig_RecordSize = nspr_signature_v20_s;
memcpy(sig20.sig_Signature, NSPR_SIGSTR_V20, sizeof(NSPR_SIGSTR_V20));
if (!wtap_dump_file_write(wdh, &sig20, sig20.sig_RecordSize,
err))
return FALSE;
nstrace->page_offset += (guint16) sig20.sig_RecordSize;
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0)
{
nspr_signature_v30_t sig30;
sig30.sig_RecordType = NSPR_SIGNATURE_V30;
sig30.sig_RecordSize = nspr_signature_v30_s;
memcpy(sig30.sig_Signature, NSPR_SIGSTR_V30, sizeof(NSPR_SIGSTR_V30));
if (!wtap_dump_file_write(wdh, &sig30, sig30.sig_RecordSize,
err))
return FALSE;
nstrace->page_offset += (guint16) sig30.sig_RecordSize;
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_5)
{
nspr_signature_v35_t sig35;
sig35.sig_RecordType = NSPR_SIGNATURE_V35;
sig35.sig_RecordSize = nspr_signature_v35_s;
memcpy(sig35.sig_Signature, NSPR_SIGSTR_V35, sizeof(NSPR_SIGSTR_V35));
if (!wtap_dump_file_write(wdh, &sig35, sig35.sig_RecordSize,
err))
return FALSE;
nstrace->page_offset += (guint16) sig35.sig_RecordSize;
} else
{
g_assert_not_reached();
return FALSE;
}
return TRUE;
}
static gboolean
nstrace_add_abstime(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
nstrace_dump_t *nstrace = (nstrace_dump_t *)wdh->priv;
guint64 nsg_creltime;
if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0)
{
guint16 val16;
guint32 reltime;
guint64 abstime;
nspr_abstime_v10_t abs10;
val16 = GUINT16_TO_LE(NSPR_ABSTIME_V10);
memcpy(abs10.phd.ph_RecordType, &val16, sizeof abs10.phd.ph_RecordType);
val16 = GUINT16_TO_LE(nspr_abstime_v10_s);
memcpy(abs10.phd.ph_RecordSize, &val16, sizeof abs10.phd.ph_RecordSize);
memcpy(&reltime, ((const nspr_pktracefull_v10_t *)pd)->fp_RelTimeHr, sizeof reltime);
nsg_creltime = ns_hrtime2nsec(reltime);
memset(abs10.abs_RelTime, 0, sizeof abs10.abs_RelTime);
abstime = GUINT32_TO_LE((guint32)phdr->ts.secs - (guint32)(nsg_creltime/1000000000));
memcpy(abs10.abs_Time, &abstime, sizeof abs10.abs_Time);
if (!wtap_dump_file_write(wdh, &abs10, nspr_abstime_v10_s, err))
return FALSE;
nstrace->page_offset += nspr_abstime_v10_s;
} else if ((wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0) ||
(wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0) ||
(wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_5)) {
guint32 reltime;
guint64 abstime;
nspr_abstime_v20_t abs20;
abs20.abs_RecordType = NSPR_ABSTIME_V20;
abs20.abs_RecordSize = nspr_abstime_v20_s;
memcpy(&reltime, ((const nspr_pktracefull_v20_t *)pd)->fp_RelTimeHr, sizeof reltime);
nsg_creltime = ns_hrtime2nsec(reltime);
memset(abs20.abs_RelTime, 0, sizeof abs20.abs_RelTime);
abstime = GUINT32_TO_LE((guint32)phdr->ts.secs - (guint32)(nsg_creltime/1000000000));
memcpy(abs20.abs_RelTime, &abstime, sizeof abs20.abs_RelTime);
if (!wtap_dump_file_write(wdh, &abs20, nspr_abstime_v20_s, err))
return FALSE;
nstrace->page_offset += nspr_abstime_v20_s;
} else
{
g_assert_not_reached();
return FALSE;
}
return TRUE;
}
static gboolean nstrace_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err, gchar **err_info _U_)
{
nstrace_dump_t *nstrace = (nstrace_dump_t *)wdh->priv;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
if (nstrace->newfile == TRUE)
{
nstrace->newfile = FALSE;
if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0)
{
if (!nstrace_add_signature(wdh, err) ||
!nstrace_add_abstime(wdh, phdr, pd, err))
return FALSE;
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0)
{
if (!nstrace_add_signature(wdh, err) ||
!nstrace_add_abstime(wdh, phdr, pd, err))
return FALSE;
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0 ||
wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_5 )
{
if (!nstrace_add_signature(wdh, err) ||
!nstrace_add_abstime(wdh, phdr, pd, err))
return FALSE;
} else
{
g_assert_not_reached();
return FALSE;
}
}
switch (phdr->pseudo_header.nstr.rec_type)
{
case NSPR_HEADER_VERSION100:
if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0)
{
if (nstrace->page_offset + phdr->caplen >= nstrace->page_len)
{
if (wtap_dump_file_seek(wdh, (nstrace->page_len - nstrace->page_offset), SEEK_CUR, err) == -1)
return FALSE;
nstrace->page_offset = 0;
if (!nstrace_add_signature(wdh, err))
return FALSE;
}
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
nstrace->page_offset += (guint16) phdr->caplen;
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0)
{
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
return FALSE;
}
break;
case NSPR_HEADER_VERSION200:
case NSPR_HEADER_VERSION201:
case NSPR_HEADER_VERSION202:
case NSPR_HEADER_VERSION203:
case NSPR_HEADER_VERSION204:
case NSPR_HEADER_VERSION205:
case NSPR_HEADER_VERSION206:
if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0)
{
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
return FALSE;
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0)
{
if (nstrace->page_offset + phdr->caplen >= nstrace->page_len)
{
if (wtap_dump_file_seek(wdh, (nstrace->page_len - nstrace->page_offset), SEEK_CUR, err) == -1)
return FALSE;
nstrace->page_offset = 0;
if (!nstrace_add_signature(wdh, err))
return FALSE;
}
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
nstrace->page_offset += (guint16) phdr->caplen;
}
break;
case NSPR_HEADER_VERSION300:
case NSPR_HEADER_VERSION350:
if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0)
{
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
return FALSE;
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0)
{
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
return FALSE;
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0 || wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_5)
{
if (nstrace->page_offset + phdr->caplen >= nstrace->page_len)
{
if (wtap_dump_file_seek(wdh, (nstrace->page_len - nstrace->page_offset), SEEK_CUR, err) == -1)
return FALSE;
nstrace->page_offset = 0;
if (!nstrace_add_signature(wdh, err))
return FALSE;
}
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
nstrace->page_offset += (guint16) phdr->caplen;
} else
{
g_assert_not_reached();
return FALSE;
}
break;
default:
g_assert_not_reached();
return FALSE;
}
return TRUE;
}
