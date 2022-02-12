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
int nstrace_open(wtap *wth, int *err, gchar **err_info)
{
gchar *nstrace_buf;
gint64 file_size;
gint32 page_size;
nstrace_t *nstrace;
int bytes_read;
errno = WTAP_ERR_CANT_READ;
if ((file_size = wtap_file_size(wth, err)) == -1)
return 0;
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
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("nstrace: file type %d unsupported", wth->file_type_subtype);
g_free(nstrace_buf);
return 0;
}
if ((file_seek(wth->fh, 0, SEEK_SET, err)) == -1)
{
*err = file_error(wth->fh, err_info);
g_free(nstrace_buf);
return 0;
}
bytes_read = file_read(nstrace_buf, page_size, wth->fh);
if (bytes_read != page_size)
{
*err = file_error(wth->fh, err_info);
g_free(nstrace_buf);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
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
if ((nstrace_set_start_time(wth)) == FALSE)
{
if ((file_seek(wth->fh, 0, SEEK_SET, err)) == -1)
{
*err = file_error(wth->fh, err_info);
g_free(nstrace->pnstrace_buf);
g_free(nstrace);
return 0;
}
bytes_read = file_read(nstrace_buf, page_size, wth->fh);
if (bytes_read != page_size)
{
*err = file_error(wth->fh, err_info);
g_free(nstrace->pnstrace_buf);
g_free(nstrace);
return 0;
}
nstrace->nstrace_buf_offset = 0;
}
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
wth->phdr.ts.secs = nstrace->nspm_curtime;
wth->phdr.ts.nsecs = 0;
*err = 0;
return 1;
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
if (!nspm_signature_isv20(sigv20p->sig_Signature))
return WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0;
else if (!nspm_signature_isv30(sigv20p->sig_Signature))
return WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0;
}
#undef sigv20p
}
}
return 0;
}
static gboolean nstrace_set_start_time(wtap *wth)
{
if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0)
return nstrace_set_start_time_v10(wth);
else if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0)
return nstrace_set_start_time_v20(wth);
else if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0)
return nstrace_set_start_time_v20(wth);
return FALSE;
}
static gboolean nstrace_read_v10(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
nstrace_t *nstrace = (nstrace_t *)wth->priv;
guint64 nsg_creltime = nstrace->nsg_creltime;
gchar *nstrace_buf = nstrace->pnstrace_buf;
gint32 nstrace_buf_offset = nstrace->nstrace_buf_offset;
gint32 nstrace_buflen = nstrace->nstrace_buflen;
nspr_pktracefull_v10_t *fp;
nspr_pktracepart_v10_t *pp;
int bytes_read;
*err = 0;
*err_info = NULL;
do
{
while ((nstrace_buf_offset < nstrace_buflen) &&
((nstrace_buflen - nstrace_buf_offset) >= ((gint32)sizeof(fp->nsprRecordType))))
{
#define GENERATE_CASE_FULL(phdr,type,acttype) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
fp = (nspr_pktracefull_v10_t *) &nstrace_buf[nstrace_buf_offset];\
\
(phdr)->rec_type = REC_TYPE_PACKET;\
(phdr)->presence_flags = WTAP_HAS_TS;\
nsg_creltime += ns_hrtime2nsec(pletoh32(&fp->fp_RelTimeHr));\
(phdr)->ts.secs = nstrace->nspm_curtime + (guint32) (nsg_creltime / 1000000000);\
(phdr)->ts.nsecs = (guint32) (nsg_creltime % 1000000000);\
TRACE_FULL_V##type##_REC_LEN_OFF(phdr,v##type##_full,fp,pktracefull_v##type);\
buffer_assure_space(wth->frame_buffer, (phdr)->caplen);\
memcpy(buffer_start_ptr(wth->frame_buffer), fp, (phdr)->caplen);\
*data_offset = nstrace->xxx_offset + nstrace_buf_offset;\
nstrace->nstrace_buf_offset = nstrace_buf_offset + (phdr)->len;\
nstrace->nstrace_buflen = nstrace_buflen;\
nstrace->nsg_creltime = nsg_creltime;\
return TRUE;
#define GENERATE_CASE_PART(phdr,type,acttype) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
pp = (nspr_pktracepart_v10_t *) &nstrace_buf[nstrace_buf_offset];\
\
(phdr)->rec_type = REC_TYPE_PACKET;\
(phdr)->presence_flags = WTAP_HAS_TS;\
nsg_creltime += ns_hrtime2nsec(pletoh32(&pp->pp_RelTimeHr));\
(phdr)->ts.secs = nstrace->nspm_curtime + (guint32) (nsg_creltime / 1000000000);\
(phdr)->ts.nsecs = (guint32) (nsg_creltime % 1000000000);\
TRACE_PART_V##type##_REC_LEN_OFF(phdr,v##type##_part,pp,pktracepart_v##type);\
buffer_assure_space(wth->frame_buffer, (phdr)->caplen);\
memcpy(buffer_start_ptr(wth->frame_buffer), pp, (phdr)->caplen);\
*data_offset = nstrace->xxx_offset + nstrace_buf_offset;\
nstrace->nstrace_buf_offset = nstrace_buf_offset + (phdr)->caplen;\
nstrace->nsg_creltime = nsg_creltime;\
nstrace->nstrace_buflen = nstrace_buflen;\
return TRUE;\
switch (pletoh16(&(( nspr_header_v10_t*)&nstrace_buf[nstrace_buf_offset])->ph_RecordType))
{
GENERATE_CASE_FULL(&wth->phdr,10,100)
GENERATE_CASE_PART(&wth->phdr,10,100)
#undef GENERATE_CASE_FULL
#undef GENERATE_CASE_PART
case NSPR_ABSTIME_V10:
fp = (nspr_pktracefull_v10_t *) &nstrace_buf[nstrace_buf_offset];
ns_setabstime(nstrace, pletoh32(((nspr_abstime_v10_t *) fp)->abs_Time), pletoh32(&((nspr_abstime_v10_t *) fp)->abs_RelTime));
nstrace_buf_offset += pletoh16(&fp->nsprRecordSize);
break;
case NSPR_RELTIME_V10:
fp = (nspr_pktracefull_v10_t *) &nstrace_buf[nstrace_buf_offset];
ns_setrelativetime(nstrace, pletoh32(((nspr_abstime_v10_t *) fp)->abs_RelTime));
nstrace_buf_offset += pletoh16(&fp->nsprRecordSize);
break;
case NSPR_UNUSEDSPACE_V10:
nstrace_buf_offset = nstrace_buflen;
break;
default:
fp = (nspr_pktracefull_v10_t *) &nstrace_buf[nstrace_buf_offset];
nstrace_buf_offset += pletoh16(&fp->nsprRecordSize);
break;
}
}
nstrace_buf_offset = 0;
nstrace->xxx_offset += nstrace_buflen;
nstrace_buflen = GET_READ_PAGE_SIZE((nstrace->file_size - nstrace->xxx_offset));
}while((nstrace_buflen > 0) && (bytes_read = file_read(nstrace_buf, nstrace_buflen, wth->fh)) && (bytes_read == nstrace_buflen));
return FALSE;
}
static gboolean nstrace_read_v20(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
nstrace_t *nstrace = (nstrace_t *)wth->priv;
guint64 nsg_creltime = nstrace->nsg_creltime;
gchar *nstrace_buf = nstrace->pnstrace_buf;
gint32 nstrace_buf_offset = nstrace->nstrace_buf_offset;
gint32 nstrace_buflen = nstrace->nstrace_buflen;
int bytes_read;
*err = 0;
*err_info = NULL;
do
{
while ((nstrace_buf_offset < nstrace_buflen) &&
((nstrace_buflen - nstrace_buf_offset) >= ((gint32)sizeof((( nspr_hd_v20_t*)&nstrace_buf[nstrace_buf_offset])->phd_RecordType))))
{
switch ((( nspr_hd_v20_t*)&nstrace_buf[nstrace_buf_offset])->phd_RecordType)
{
#define GENERATE_CASE_FULL(phdr,type,acttype) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define GENERATE_CASE_FULL_V25(phdr,type,acttype) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define GENERATE_CASE_PART(phdr,type,acttype) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
#define GENERATE_CASE_PART_V25(phdr,type,acttype) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
case NSPR_PDPKTRACEPARTNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
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
nstrace_buf_offset += nspr_getv20recordsize((nspr_hd_v20_t *)fp20);
ns_setabstime(nstrace, pletoh32(&((nspr_abstime_v20_t *) fp20)->abs_Time), pletoh16(&((nspr_abstime_v20_t *) fp20)->abs_RelTime));
break;
}
case NSPR_RELTIME_V20:
{
nspr_pktracefull_v20_t *fp20 = (nspr_pktracefull_v20_t *) &nstrace_buf[nstrace_buf_offset];
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
nstrace_buf_offset += nspr_getv20recordsize((nspr_hd_v20_t *)fp20);
break;
}
}
}
nstrace_buf_offset = 0;
nstrace->xxx_offset += nstrace_buflen;
nstrace_buflen = GET_READ_PAGE_SIZE((nstrace->file_size - nstrace->xxx_offset));
}while((nstrace_buflen > 0) && (bytes_read = file_read(nstrace_buf, nstrace_buflen, wth->fh)) && (bytes_read == nstrace_buflen));
return FALSE;
}
static gboolean nstrace_read_v30(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
nstrace_t *nstrace = (nstrace_t *)wth->priv;
guint64 nsg_creltime = nstrace->nsg_creltime;
gchar *nstrace_buf = nstrace->pnstrace_buf;
gint32 nstrace_buf_offset = nstrace->nstrace_buf_offset;
gint32 nstrace_buflen = nstrace->nstrace_buflen;
guint8 nstrace_tmpbuff[65536];
guint32 nstrace_tmpbuff_off=0,nst_dataSize=0,rec_size=0,nsg_nextPageOffset=0;
nspr_hd_v20_t *hdp;
int bytes_read;
*err = 0;
*err_info = NULL;
do
{
while ((nstrace_buf_offset < NSPR_PAGESIZE_TRACE) &&
nstrace_buf[nstrace_buf_offset])
{
hdp = (nspr_hd_v20_t *) &nstrace_buf[nstrace_buf_offset];
switch (hdp->phd_RecordType)
{
#define GENERATE_CASE_V30(phdr,type,acttype) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
PACKET_DESCRIBE(phdr, TIMEDEF, FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
GENERATE_CASE_V30(&wth->phdr,30, 300);
#undef GENERATE_CASE_V30
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
} while((nstrace_buflen > 0) && (bytes_read = file_read(nstrace_buf, nstrace_buflen, wth->fh)) && (bytes_read == nstrace_buflen));
return FALSE;
}
static gboolean nstrace_seek_read_v10(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
nspr_hd_v10_t hdr;
int bytes_read;
guint record_length;
guint8 *pd;
unsigned int bytes_to_read;
nspr_pktracefull_v10_t *fp;
nspr_pktracepart_v10_t *pp;
*err = 0;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
bytes_read = file_read((void *)&hdr, sizeof hdr, wth->random_fh);
if (bytes_read != sizeof hdr) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
record_length = nspr_getv10recordsize(&hdr);
buffer_assure_space(buf, record_length);
pd = buffer_start_ptr(buf);
memcpy(pd, (void *)&hdr, sizeof hdr);
if (record_length > sizeof hdr) {
bytes_to_read = (unsigned int)(record_length - sizeof hdr);
bytes_read = file_read(pd + sizeof hdr, bytes_to_read, wth->random_fh);
if (bytes_read < 0 || (unsigned int)bytes_read != bytes_to_read) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
}
#define GENERATE_CASE_FULL(phdr,type,acttype) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
fp = (nspr_pktracefull_v10_t *) pd;\
TRACE_FULL_V##type##_REC_LEN_OFF(phdr,v##type##_full,fp,pktracefull_v##type);\
(phdr)->pseudo_header.nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
break;
#define GENERATE_CASE_PART(phdr,type,acttype) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
pp = (nspr_pktracepart_v10_t *) pd;\
TRACE_PART_V##type##_REC_LEN_OFF(phdr,v##type##_part,pp,pktracepart_v##type);\
(phdr)->pseudo_header.nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
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
int bytes_read;
guint record_length;
guint hdrlen;
guint8 *pd;
unsigned int bytes_to_read;
*err = 0;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
bytes_read = file_read((void *)&hdr, 2, wth->random_fh);
if (bytes_read != 2) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
hdrlen = 2;
if (hdr.phd_RecordSizeLow & NSPR_V20RECORDSIZE_2BYTES) {
bytes_read = file_read((void *)&hdr.phd_RecordSizeHigh, 1, wth->random_fh);
if (bytes_read != 1) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
hdrlen = 3;
}
record_length = nspr_getv20recordsize(&hdr);
buffer_assure_space(buf, record_length);
pd = buffer_start_ptr(buf);
memcpy(pd, (void *)&hdr, hdrlen);
if (record_length > hdrlen) {
bytes_to_read = (unsigned int)(record_length - hdrlen);
bytes_read = file_read(pd + hdrlen, bytes_to_read, wth->random_fh);
if (bytes_read < 0 || (unsigned int)bytes_read != bytes_to_read) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
}
#define GENERATE_CASE_FULL(phdr,type,acttype) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define GENERATE_CASE_FULL_V25(phdr,type,acttype) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define GENERATE_CASE_PART(phdr,type,acttype) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
#define GENERATE_CASE_PART_V25(phdr,type,acttype) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
case NSPR_PDPKTRACEPARTNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
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
int bytes_read;
guint record_length;
guint hdrlen;
guint8 *pd;
unsigned int bytes_to_read;
*err = 0;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
bytes_read = file_read((void *)&hdr, 2, wth->random_fh);
if (bytes_read != 2) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
hdrlen = 2;
if (hdr.phd_RecordSizeLow & NSPR_V20RECORDSIZE_2BYTES) {
bytes_read = file_read((void *)&hdr.phd_RecordSizeHigh, 1, wth->random_fh);
if (bytes_read != 1) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
hdrlen = 3;
}
record_length = nspr_getv20recordsize(&hdr);
buffer_assure_space(buf, record_length);
pd = buffer_start_ptr(buf);
memcpy(pd, (void *)&hdr, hdrlen);
if (record_length > hdrlen) {
bytes_to_read = (unsigned int)(record_length - hdrlen);
bytes_read = file_read(pd + hdrlen, bytes_to_read, wth->random_fh);
if (bytes_read < 0 || (unsigned int)bytes_read != bytes_to_read) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
}
#define GENERATE_CASE_V30(phdr,type,acttype) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
TRACE_V##type##_REC_LEN_OFF((phdr),v##type##_full,fp,pktracefull_v##type);\
(phdr)->pseudo_header.nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
break;
switch ((( nspr_hd_v20_t*)pd)->phd_RecordType)
{
GENERATE_CASE_V30(phdr,30, 300);
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
return WTAP_ERR_UNSUPPORTED_ENCAP;
}
int nstrace_20_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_NSTRACE_2_0)
return 0;
return WTAP_ERR_UNSUPPORTED_ENCAP;
}
int nstrace_30_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_NSTRACE_3_0)
return 0;
return WTAP_ERR_UNSUPPORTED_ENCAP;
}
gboolean nstrace_dump_open(wtap_dumper *wdh, int *err _U_)
{
nstrace_dump_t *nstrace;
wdh->subtype_write = nstrace_dump;
nstrace = (nstrace_dump_t *)g_malloc(sizeof(nstrace_dump_t));
wdh->priv = (void *)nstrace;
nstrace->page_offset = 0;
nstrace->page_len = NSPR_PAGESIZE;
nstrace->absrec_time = 0;
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
(wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0)) {
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
const guint8 *pd, int *err)
{
nstrace_dump_t *nstrace = (nstrace_dump_t *)wdh->priv;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_REC_TYPE_UNSUPPORTED;
return FALSE;
}
if (nstrace->page_offset == 0)
{
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
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0)
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
*err = WTAP_ERR_UNSUPPORTED_FILE_TYPE;
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
*err = WTAP_ERR_UNSUPPORTED_FILE_TYPE;
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
if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0)
{
*err = WTAP_ERR_UNSUPPORTED_FILE_TYPE;
return FALSE;
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0)
{
*err = WTAP_ERR_UNSUPPORTED_FILE_TYPE;
return FALSE;
} else if (wdh->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0)
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
