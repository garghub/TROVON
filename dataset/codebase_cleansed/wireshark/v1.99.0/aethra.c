int aethra_open(wtap *wth, int *err, gchar **err_info)
{
struct aethra_hdr hdr;
struct tm tm;
aethra_t *aethra;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, hdr.magic, sizeof hdr.magic, err,
err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (memcmp(hdr.magic, aethra_magic, sizeof aethra_magic) != 0)
return 0;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, (char *)&hdr + sizeof hdr.magic,
sizeof hdr - sizeof hdr.magic, err, err_info))
return -1;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_AETHRA;
aethra = (aethra_t *)g_malloc(sizeof(aethra_t));
wth->priv = (void *)aethra;
wth->subtype_read = aethra_read;
wth->subtype_seek_read = aethra_seek_read;
tm.tm_year = pletoh16(&hdr.start_year) - 1900;
tm.tm_mon = pletoh16(&hdr.start_month) - 1;
tm.tm_mday = pletoh16(&hdr.start_day);
tm.tm_hour = hdr.start_hour;
tm.tm_min = hdr.start_min;
tm.tm_sec = hdr.start_sec;
tm.tm_isdst = -1;
aethra->start = mktime(&tm);
wth->file_encap = WTAP_ENCAP_ISDN;
wth->snapshot_length = 0;
wth->file_tsprec = WTAP_TSPREC_MSEC;
return 1;
}
static gboolean aethra_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
struct aethrarec_hdr hdr;
for (;;) {
*data_offset = file_tell(wth->fh);
if (!aethra_read_rec_header(wth, wth->fh, &hdr, &wth->phdr, err, err_info))
return FALSE;
if (wth->phdr.caplen != 0) {
if (!wtap_read_packet_bytes(wth->fh, wth->frame_buffer,
wth->phdr.caplen, err, err_info))
return FALSE;
}
#if 0
packet++;
#endif
switch (hdr.rec_type) {
case AETHRA_ISDN_LINK:
#if 0
fprintf(stderr, "Packet %u: type 0x%02x (AETHRA_ISDN_LINK)\n",
packet, hdr.rec_type);
#endif
switch (hdr.flags & AETHRA_ISDN_LINK_SUBTYPE) {
case AETHRA_ISDN_LINK_LAPD:
#if 0
fprintf(stderr, " subtype 0x%02x (AETHRA_ISDN_LINK_LAPD)\n", hdr.flags & AETHRA_ISDN_LINK_SUBTYPE);
#endif
goto found;
case AETHRA_ISDN_LINK_SA_BITS:
#if 0
fprintf(stderr, " subtype 0x%02x (AETHRA_ISDN_LINK_SA_BITS)\n", hdr.flags & AETHRA_ISDN_LINK_SUBTYPE);
#endif
break;
case AETHRA_ISDN_LINK_ALL_ALARMS_CLEARED:
#if 0
fprintf(stderr, " subtype 0x%02x (AETHRA_ISDN_LINK_ALL_ALARMS_CLEARED)\n", hdr.flags & AETHRA_ISDN_LINK_SUBTYPE);
#endif
break;
default:
#if 0
fprintf(stderr, " subtype 0x%02x, packet_size %u, direction 0x%02x\n",
hdr.flags & AETHRA_ISDN_LINK_SUBTYPE, wth->phdr.caplen, hdr.flags & AETHRA_U_TO_N);
#endif
break;
}
break;
default:
#if 0
fprintf(stderr, "Packet %u: type 0x%02x, packet_size %u, flags 0x%02x\n",
packet, hdr.rec_type, wth->phdr.caplen, hdr.flags);
#endif
break;
}
}
found:
return TRUE;
}
static gboolean
aethra_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
struct aethrarec_hdr hdr;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!aethra_read_rec_header(wth, wth->random_fh, &hdr, phdr, err,
err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
if (!wtap_read_packet_bytes(wth->random_fh, buf, phdr->caplen, err, err_info))
return FALSE;
return TRUE;
}
static gboolean
aethra_read_rec_header(wtap *wth, FILE_T fh, struct aethrarec_hdr *hdr,
struct wtap_pkthdr *phdr, int *err, gchar **err_info)
{
aethra_t *aethra = (aethra_t *)wth->priv;
guint32 rec_size;
guint32 packet_size;
guint32 msecs;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes_or_eof(fh, hdr, sizeof *hdr, err, err_info))
return FALSE;
rec_size = pletoh16(hdr->rec_size);
if (rec_size < (sizeof *hdr - sizeof hdr->rec_size)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("aethra: File has %u-byte record, less than minimum of %u",
rec_size,
(unsigned int)(sizeof *hdr - sizeof hdr->rec_size));
return FALSE;
}
packet_size = rec_size - (guint32)(sizeof *hdr - sizeof hdr->rec_size);
msecs = pletoh32(hdr->timestamp);
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
phdr->ts.secs = aethra->start + (msecs / 1000);
phdr->ts.nsecs = (msecs % 1000) * 1000000;
phdr->caplen = packet_size;
phdr->len = packet_size;
phdr->pseudo_header.isdn.uton = (hdr->flags & AETHRA_U_TO_N);
phdr->pseudo_header.isdn.channel = 0;
return TRUE;
}
