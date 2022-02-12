int aethra_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
struct aethra_hdr hdr;
struct tm tm;
aethra_t *aethra;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(hdr.magic, sizeof hdr.magic, wth->fh);
if (bytes_read != sizeof hdr.magic) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (memcmp(hdr.magic, aethra_magic, sizeof aethra_magic) != 0)
return 0;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read((char *)&hdr + sizeof hdr.magic,
sizeof hdr - sizeof hdr.magic, wth->fh);
if (bytes_read != sizeof hdr - sizeof hdr.magic) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
}
wth->file_type = WTAP_FILE_AETHRA;
aethra = (aethra_t *)g_malloc(sizeof(aethra_t));
wth->priv = (void *)aethra;
wth->subtype_read = aethra_read;
wth->subtype_seek_read = aethra_seek_read;
tm.tm_year = pletohs(&hdr.start_year) - 1900;
tm.tm_mon = pletohs(&hdr.start_month) - 1;
tm.tm_mday = pletohs(&hdr.start_day);
tm.tm_hour = hdr.start_hour;
tm.tm_min = hdr.start_min;
tm.tm_sec = hdr.start_sec;
tm.tm_isdst = -1;
aethra->start = mktime(&tm);
wth->file_encap = WTAP_ENCAP_ISDN;
wth->snapshot_length = 0;
wth->tsprecision = WTAP_FILE_TSPREC_MSEC;
return 1;
}
static gboolean aethra_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
aethra_t *aethra = (aethra_t *)wth->priv;
struct aethrarec_hdr hdr;
guint32 rec_size;
guint32 packet_size;
guint32 msecs;
for (;;) {
*data_offset = file_tell(wth->fh);
if (!aethra_read_rec_header(wth->fh, &hdr, &wth->phdr.pseudo_header,
err, err_info))
return FALSE;
rec_size = pletohs(hdr.rec_size);
if (rec_size < (sizeof hdr - sizeof hdr.rec_size)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("aethra: File has %u-byte record, less than minimum of %u",
rec_size, (unsigned int)(sizeof hdr - sizeof hdr.rec_size));
return FALSE;
}
packet_size = rec_size - (guint32)(sizeof hdr - sizeof hdr.rec_size);
if (packet_size != 0) {
buffer_assure_space(wth->frame_buffer, packet_size);
if (!aethra_read_rec_data(wth->fh, buffer_start_ptr(wth->frame_buffer),
packet_size, err, err_info))
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
hdr.flags & AETHRA_ISDN_LINK_SUBTYPE, packet_size, hdr.flags & AETHRA_U_TO_N);
#endif
break;
}
break;
default:
#if 0
fprintf(stderr, "Packet %u: type 0x%02x, packet_size %u, flags 0x%02x\n",
packet, hdr.rec_type, packet_size, hdr.flags);
#endif
break;
}
}
found:
msecs = pletohl(hdr.timestamp);
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.ts.secs = aethra->start + (msecs / 1000);
wth->phdr.ts.nsecs = (msecs % 1000) * 1000000;
wth->phdr.caplen = packet_size;
wth->phdr.len = packet_size;
return TRUE;
}
static gboolean
aethra_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, guint8 *pd, int length,
int *err, gchar **err_info)
{
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
struct aethrarec_hdr hdr;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!aethra_read_rec_header(wth->random_fh, &hdr, pseudo_header, err, err_info))
return FALSE;
if (!aethra_read_rec_data(wth->random_fh, pd, length, err, err_info))
return FALSE;
return TRUE;
}
static gboolean
aethra_read_rec_header(FILE_T fh, struct aethrarec_hdr *hdr,
union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
int bytes_read;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(hdr, sizeof *hdr, fh);
if (bytes_read != sizeof *hdr) {
*err = file_error(fh, err_info);
if (*err == 0 && bytes_read != 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
pseudo_header->isdn.uton = (hdr->flags & AETHRA_U_TO_N);
pseudo_header->isdn.channel = 0;
return TRUE;
}
static gboolean
aethra_read_rec_data(FILE_T fh, guint8 *pd, int length, int *err,
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
