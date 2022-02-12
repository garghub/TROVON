static gboolean mplog_read_packet(FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
guint8 *p, *start_p;
guint64 last_ctr = 0;
guint8 block[MPLOG_BLOCK_SIZE];
guint8 data, type;
guint64 ctr;
gint pkt_bytes = 0;
guint8 pkt_type = TYPE_UNKNOWN;
guint64 pkt_ctr = 0;
ws_buffer_assure_space(buf, PKT_BUF_LEN);
p = ws_buffer_start_ptr(buf);
start_p = p;
p += ISO14443_PSEUDO_HDR_LEN;
do {
if (!wtap_read_bytes_or_eof(fh, block, sizeof(block), err, err_info)) {
if (pkt_bytes != 0) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
}
break;
}
data = block[0];
type = block[1];
ctr = pletoh48(&block[2]);
if (pkt_type == TYPE_UNKNOWN) {
if (KNOWN_TYPE(type)) {
pkt_type = type;
pkt_ctr = ctr;
}
}
if (type == pkt_type) {
if (last_ctr != 0) {
if (ctr - last_ctr > 200*100) {
file_seek(fh, -MPLOG_BLOCK_SIZE, SEEK_CUR, err);
break;
}
}
*p++ = data;
pkt_bytes++;
last_ctr = ctr;
}
else if (KNOWN_TYPE(type)) {
file_seek(fh, -MPLOG_BLOCK_SIZE, SEEK_CUR, err);
break;
}
} while (pkt_bytes < ISO14443_MAX_PKT_LEN);
if (pkt_type == TYPE_UNKNOWN)
return FALSE;
start_p[0] = ISO14443_PSEUDO_HDR_VER;
if (pkt_type==TYPE_PCD_PICC_A || pkt_type==TYPE_PCD_PICC_B)
start_p[1] = ISO14443_PSEUDO_HDR_PCD_TO_PICC;
else
start_p[1] = ISO14443_PSEUDO_HDR_PICC_TO_PCD;
start_p[2] = pkt_bytes >> 8;
start_p[3] = pkt_bytes & 0xFF;
phdr->rec_type = REC_TYPE_PACKET;
phdr->pkt_encap = WTAP_ENCAP_ISO14443;
phdr->presence_flags = WTAP_HAS_TS | WTAP_HAS_CAP_LEN;
phdr->ts.secs = (time_t)((pkt_ctr*10)/(1000*1000*1000));
phdr->ts.nsecs = (int)((pkt_ctr*10)%(1000*1000*1000));
phdr->caplen = ISO14443_PSEUDO_HDR_LEN + pkt_bytes;
phdr->len = phdr->caplen;
return TRUE;
}
static gboolean
mplog_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
return mplog_read_packet(
wth->fh, &wth->phdr, wth->frame_buffer, err, err_info);
}
static gboolean
mplog_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *pkthdr,
Buffer *buf, int *err, gchar **err_info)
{
if (-1 == file_seek(wth->random_fh, seek_off, SEEK_SET, err))
return FALSE;
if (!mplog_read_packet(wth->random_fh, pkthdr, buf, err, err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
wtap_open_return_val mplog_open(wtap *wth, int *err, gchar **err_info)
{
gboolean ok;
guint8 magic[6];
ok = wtap_read_bytes(wth->fh, magic, 6, err, err_info);
if (!ok) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (memcmp(magic, "MPCSII", 6) != 0)
return WTAP_OPEN_NOT_MINE;
wth->file_encap = WTAP_ENCAP_ISO14443;
wth->snapshot_length = 0;
wth->file_tsprec = WTAP_TSPREC_NSEC;
wth->priv = NULL;
wth->subtype_read = mplog_read;
wth->subtype_seek_read = mplog_seek_read;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_MPLOG;
if (-1 == file_seek(wth->fh, 0x80, SEEK_SET, err))
return WTAP_OPEN_ERROR;
*err = 0;
return WTAP_OPEN_MINE;
}
