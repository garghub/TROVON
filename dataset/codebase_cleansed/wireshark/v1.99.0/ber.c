static gboolean ber_read_file(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
gint64 file_size;
int packet_size;
if ((file_size = wtap_file_size(wth, err)) == -1)
return FALSE;
if (file_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("ber: File has %" G_GINT64_MODIFIER "d-byte packet, bigger than maximum of %u",
file_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
packet_size = (int)file_size;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = 0;
phdr->caplen = packet_size;
phdr->len = packet_size;
phdr->ts.secs = 0;
phdr->ts.nsecs = 0;
return wtap_read_packet_bytes(fh, buf, packet_size, err, err_info);
}
static gboolean ber_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
gint64 offset;
*err = 0;
offset = file_tell(wth->fh);
if (offset != 0)
return FALSE;
*data_offset = offset;
return ber_read_file(wth, wth->fh, &wth->phdr, wth->frame_buffer, err, err_info);
}
static gboolean ber_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr _U_,
Buffer *buf, int *err, gchar **err_info)
{
if(seek_off > 0) {
*err = 0;
return FALSE;
}
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
return ber_read_file(wth, wth->random_fh, phdr, buf, err, err_info);
}
int ber_open(wtap *wth, int *err, gchar **err_info)
{
#define BER_BYTES_TO_CHECK 8
guint8 bytes[BER_BYTES_TO_CHECK];
guint8 ber_id;
gint8 ber_class;
gint8 ber_tag;
gboolean ber_pc;
guint8 oct, nlb = 0;
int len = 0;
gint64 file_size;
int offset = 0, i;
if (!wtap_read_bytes(wth->fh, &bytes, BER_BYTES_TO_CHECK, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
ber_id = bytes[offset++];
ber_class = (ber_id>>6) & 0x03;
ber_pc = (ber_id>>5) & 0x01;
ber_tag = ber_id & 0x1F;
if(!(ber_pc &&
(((ber_class == BER_CLASS_UNI) && ((ber_tag == BER_UNI_TAG_SET) || (ber_tag == BER_UNI_TAG_SEQ))) ||
((ber_class == BER_CLASS_CON) && (ber_tag < 32)))))
return 0;
oct = bytes[offset++];
if(oct != 0x80) {
if(!(oct & 0x80))
len = oct;
else {
nlb = oct & 0x7F;
if((nlb > 0) && (nlb <= (BER_BYTES_TO_CHECK - 2))) {
i = nlb;
while(i--) {
oct = bytes[offset++];
len = (len<<8) + oct;
}
}
}
len += (2 + nlb);
file_size = wtap_file_size(wth, err);
if(len != file_size) {
return 0;
}
} else {
}
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return -1;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_BER;
wth->file_encap = WTAP_ENCAP_BER;
wth->snapshot_length = 0;
wth->subtype_read = ber_read;
wth->subtype_seek_read = ber_seek_read;
wth->file_tsprec = WTAP_TSPREC_SEC;
return 1;
}
