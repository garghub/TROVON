wtap_open_return_val
iseries_open (wtap * wth, int *err, gchar ** err_info)
{
gint offset;
char magic[ISERIES_LINE_LENGTH];
if (!wtap_read_bytes (wth->fh, &magic, sizeof magic, err, err_info))
{
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
offset=0;
while ((unsigned int)offset < (ISERIES_LINE_LENGTH - (sizeof iseries_hdr_magic_le_ucs_2)))
{
if (memcmp (magic + offset, iseries_hdr_magic_le_ucs_2, sizeof iseries_hdr_magic_le_ucs_2) == 0) {
if (file_seek (wth->fh, 0, SEEK_SET, err) == -1)
{
return WTAP_OPEN_ERROR;
}
if (!iseries_check_file_type (wth, err, err_info, ISERIES_FORMAT_UNICODE))
{
if (*err == 0)
return WTAP_OPEN_NOT_MINE;
else
return WTAP_OPEN_ERROR;
}
wth->file_encap = WTAP_ENCAP_ETHERNET;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_ISERIES;
wth->snapshot_length = 0;
wth->subtype_read = iseries_read;
wth->subtype_seek_read = iseries_seek_read;
wth->file_tsprec = WTAP_TSPREC_USEC;
if (file_seek (wth->fh, 0, SEEK_SET, err) == -1)
{
return WTAP_OPEN_ERROR;
}
return WTAP_OPEN_MINE;
}
offset += 1;
}
offset=0;
while ((unsigned int)offset < (ISERIES_LINE_LENGTH - sizeof iseries_hdr_magic_ascii))
{
if (memcmp (magic + offset, iseries_hdr_magic_ascii, sizeof iseries_hdr_magic_ascii) == 0)
{
if (file_seek (wth->fh, 0, SEEK_SET, err) == -1)
{
return WTAP_OPEN_ERROR;
}
if (!iseries_check_file_type (wth, err, err_info, ISERIES_FORMAT_ASCII))
{
if (*err == 0)
return WTAP_OPEN_NOT_MINE;
else
return WTAP_OPEN_ERROR;
}
wth->file_encap = WTAP_ENCAP_ETHERNET;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_ISERIES;
wth->snapshot_length = 0;
wth->subtype_read = iseries_read;
wth->subtype_seek_read = iseries_seek_read;
wth->file_tsprec = WTAP_TSPREC_USEC;
if (file_seek (wth->fh, 0, SEEK_SET, err) == -1)
{
return WTAP_OPEN_ERROR;
}
return WTAP_OPEN_MINE;
}
offset += 1;
}
return WTAP_OPEN_NOT_MINE;
}
static gboolean
iseries_check_file_type (wtap * wth, int *err, gchar **err_info, int format)
{
gboolean is_iseries = FALSE;
guint line;
int num_items_scanned;
char buf[ISERIES_LINE_LENGTH], protocol[9];
iseries_t *iseries;
iseries = (iseries_t *) g_malloc (sizeof (iseries_t));
iseries->have_date = FALSE;
iseries->format = format;
for (line = 0; line < ISERIES_HDR_LINES_TO_CHECK; line++)
{
memset(buf, 0x0, sizeof(buf));
if (file_gets (buf, ISERIES_LINE_LENGTH, wth->fh) == NULL)
{
*err = file_error (wth->fh, err_info);
if (*err == WTAP_ERR_SHORT_READ)
*err = 0;
break;
}
if (iseries->format == ISERIES_FORMAT_UNICODE)
{
iseries_UNICODE_to_ASCII ((guint8 *)buf, ISERIES_LINE_LENGTH);
}
ascii_strup_inplace (buf);
num_items_scanned = sscanf (buf,
"%*[ \n\t]OBJECT PROTOCOL%*[ .:\n\t]%8s",
protocol);
if (num_items_scanned == 1)
{
if (memcmp (protocol, "ETHERNET", 8) == 0)
{
*err = 0;
is_iseries = TRUE;
}
}
num_items_scanned = sscanf (buf,
"%*[ \n\t]START DATE/TIME%*[ .:\n\t]%2d/%2d/%2d",
&iseries->month, &iseries->day,
&iseries->year);
if (num_items_scanned == 3)
{
iseries->have_date = TRUE;
}
}
if (is_iseries)
wth->priv = (void *) iseries;
else
g_free(iseries);
return is_iseries;
}
static gboolean
iseries_read (wtap * wth, int *err, gchar ** err_info, gint64 *data_offset)
{
gint64 offset;
offset = iseries_seek_next_packet (wth, err, err_info);
if (offset < 0)
return FALSE;
*data_offset = offset;
return iseries_parse_packet (wth, wth->fh, &wth->phdr, wth->frame_buffer,
err, err_info);
}
static gint64
iseries_seek_next_packet (wtap * wth, int *err, gchar **err_info)
{
iseries_t *iseries = (iseries_t *)wth->priv;
char buf[ISERIES_LINE_LENGTH],type[5];
int line, num_items_scanned;
gint64 cur_off;
long buflen;
for (line = 0; line < ISERIES_MAX_TRACE_LEN; line++)
{
if (file_gets (buf, ISERIES_LINE_LENGTH, wth->fh) == NULL)
{
*err = file_error (wth->fh, err_info);
return -1;
}
if (iseries->format == ISERIES_FORMAT_UNICODE)
{
buflen = iseries_UNICODE_to_ASCII ((guint8 *) buf, ISERIES_LINE_LENGTH);
}
else
{
buflen = (long) strlen (buf);
}
ascii_strup_inplace (buf);
num_items_scanned =
sscanf (buf+78,
"%*[ \n\t]ETHV2%*[ .:\n\t]TYPE%*[ .:\n\t]%4s",type);
if (num_items_scanned == 1)
{
cur_off = file_tell (wth->fh);
if (cur_off == -1)
{
*err = file_error (wth->fh, err_info);
return -1;
}
if (file_seek (wth->fh, cur_off - buflen, SEEK_SET, err) == -1)
{
return -1;
}
return cur_off - buflen;
}
}
*err = WTAP_ERR_BAD_FILE;
*err_info =
g_strdup_printf ("iseries: next packet header not found within %d lines",
ISERIES_MAX_TRACE_LEN);
return -1;
}
static gboolean
iseries_seek_read (wtap * wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer * buf, int *err, gchar ** err_info)
{
if (file_seek (wth->random_fh, seek_off - 1, SEEK_SET, err) == -1)
return FALSE;
return iseries_parse_packet (wth, wth->random_fh, phdr, buf,
err, err_info);
}
static int
append_hex_digits(char *ascii_buf, int ascii_offset, int max_offset,
char *data, int *err, gchar **err_info)
{
int in_offset, out_offset;
int c;
unsigned int i;
gboolean overflow = FALSE;
in_offset = 0;
out_offset = ascii_offset;
for (;;)
{
for (i = 0; i < 16; i++, in_offset++)
{
c = data[in_offset] & 0xFF;
if (c == '\0' || c == ' ' || c == '*' || c == '\r' || c == '\n')
{
goto done;
}
if (!g_ascii_isxdigit(c) || g_ascii_islower(c))
{
return ascii_offset;
}
if (out_offset >= max_offset)
overflow = TRUE;
else
{
ascii_buf[out_offset] = c;
out_offset++;
}
}
for (; (data[in_offset] & 0xFF) == ' '; in_offset++)
;
}
done:
if ((i % 2) != 0)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("iseries: odd number of hex digits in a line");
return -1;
}
if (overflow)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("iseries: more packet data than the packet length indicated");
return -1;
}
return out_offset;
}
static gboolean
iseries_parse_packet (wtap * wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
iseries_t *iseries = (iseries_t *)wth->priv;
gint64 cur_off;
gboolean isValid, isCurrentPacket;
int num_items_scanned, line, pktline, buflen;
int pkt_len, pktnum, hr, min, sec;
char direction[2], destmac[13], srcmac[13], type[5], csec[9+1];
char data[ISERIES_LINE_LENGTH * 2];
int offset;
char *ascii_buf;
int ascii_offset;
struct tm tm;
isValid = FALSE;
for (line = 1; line < ISERIES_PKT_LINES_TO_CHECK; line++)
{
if (file_gets (data, ISERIES_LINE_LENGTH, fh) == NULL)
{
*err = file_error (fh, err_info);
return FALSE;
}
if (iseries->format == ISERIES_FORMAT_UNICODE)
{
iseries_UNICODE_to_ASCII ((guint8 *)data, ISERIES_LINE_LENGTH);
}
ascii_strup_inplace (data);
num_items_scanned =
sscanf (data,
"%*[ \n\t]%6d%*[ *\n\t]%1s%*[ \n\t]%6d%*[ \n\t]%2d:%2d:%2d.%9[0-9]%*[ \n\t]"
"%12s%*[ \n\t]%12s%*[ \n\t]ETHV2%*[ \n\t]TYPE:%*[ \n\t]%4s",
&pktnum, direction, &pkt_len, &hr, &min, &sec, csec, destmac,
srcmac, type);
if (num_items_scanned == 10)
{
if (pktnum < 0)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header has a negative packet number");
return FALSE;
}
if (pkt_len < 0)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header has a negative packet length");
return FALSE;
}
if (hr < 0)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header has a negative hour in the time stamp");
return FALSE;
}
if (hr > 23)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header has a hour in the time stamp greater than 23");
return FALSE;
}
if (min < 0)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header has a negative minute in the time stamp");
return FALSE;
}
if (min > 59)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header has a minute in the time stamp greater than 59");
return FALSE;
}
if (sec < 0)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header has a negative second in the time stamp");
return FALSE;
}
if (sec > 60)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header has a second in the time stamp greater than 60");
return FALSE;
}
if (strlen(destmac) != 12)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header has a destination MAC address shorter than 6 bytes");
return FALSE;
}
if (strlen(srcmac) != 12)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header has a source MAC address shorter than 6 bytes");
return FALSE;
}
if (strlen(type) != 4)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header has an Ethernet type/length field than 2 bytes");
return FALSE;
}
isValid = TRUE;
if (pkt_len > WTAP_MAX_PACKET_SIZE - 14)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iseries: File has %" G_GUINT64_FORMAT "-byte packet, bigger than maximum of %u",
(guint64)pkt_len + 14,
WTAP_MAX_PACKET_SIZE);
return FALSE;
}
pkt_len += 14;
break;
}
}
if (!isValid)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header isn't valid");
return FALSE;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_CAP_LEN;
if (iseries->have_date)
{
phdr->presence_flags |= WTAP_HAS_TS;
tm.tm_year = 100 + iseries->year;
tm.tm_mon = iseries->month - 1;
tm.tm_mday = iseries->day;
tm.tm_hour = hr;
tm.tm_min = min;
tm.tm_sec = sec;
tm.tm_isdst = -1;
phdr->ts.secs = mktime (&tm);
csec[sizeof(csec) - 1] = '\0';
switch (strlen(csec))
{
case 0:
phdr->ts.nsecs = 0;
break;
case 1:
phdr->ts.nsecs = atoi(csec) * 100000000;
break;
case 2:
phdr->ts.nsecs = atoi(csec) * 10000000;
break;
case 3:
phdr->ts.nsecs = atoi(csec) * 1000000;
break;
case 4:
phdr->ts.nsecs = atoi(csec) * 100000;
break;
case 5:
phdr->ts.nsecs = atoi(csec) * 10000;
break;
case 6:
phdr->ts.nsecs = atoi(csec) * 1000;
break;
case 7:
phdr->ts.nsecs = atoi(csec) * 100;
break;
case 8:
phdr->ts.nsecs = atoi(csec) * 10;
break;
case 9:
phdr->ts.nsecs = atoi(csec);
break;
}
}
phdr->len = pkt_len;
phdr->pkt_encap = WTAP_ENCAP_ETHERNET;
phdr->pseudo_header.eth.fcs_len = -1;
ascii_buf = (char *)g_malloc (pkt_len*2);
ascii_offset = 0;
memcpy(&ascii_buf[0], destmac, 12);
ascii_offset += 12;
memcpy(&ascii_buf[12], srcmac, 12);
ascii_offset += 12;
memcpy(&ascii_buf[24], type, 4);
ascii_offset += 4;
isCurrentPacket = TRUE;
pktline = 0;
while (isCurrentPacket)
{
pktline++;
if (file_gets (data, ISERIES_LINE_LENGTH, fh) == NULL)
{
*err = file_error (fh, err_info);
if (*err == 0)
{
break;
}
goto errxit;
}
if (iseries->format == ISERIES_FORMAT_UNICODE)
{
buflen = iseries_UNICODE_to_ASCII ((guint8 *)data, ISERIES_LINE_LENGTH);
}
else
{
buflen = (int) strlen (data);
}
for (offset = 0; g_ascii_isspace(data[offset]); offset++)
;
if (offset == 22)
{
if (strncmp(data + 22, "IP Header : ", 14) == 0 ||
strncmp(data + 22, "IPv6 Header: ", 14) == 0 ||
strncmp(data + 22, "ARP Header : ", 14) == 0 ||
strncmp(data + 22, "TCP Header : ", 14) == 0 ||
strncmp(data + 22, "UDP Header : ", 14) == 0 ||
strncmp(data + 22, "ICMP Header: ", 14) == 0 ||
strncmp(data + 22, "ICMPv6 Hdr: ", 14) == 0 ||
strncmp(data + 22, "Option Hdr: ", 14) == 0)
{
ascii_offset = append_hex_digits(ascii_buf, ascii_offset,
pkt_len*2,
data + 22 + 14, err,
err_info);
if (ascii_offset == -1)
{
return FALSE;
}
continue;
}
}
if (offset == 9)
{
if (strncmp(data + 9, "Data . . . . . : ", 18) == 0)
{
ascii_offset = append_hex_digits(ascii_buf, ascii_offset,
pkt_len*2,
data + 9 + 18, err,
err_info);
if (ascii_offset == -1)
{
return FALSE;
}
continue;
}
}
if (offset == 36 || offset == 27)
{
ascii_offset = append_hex_digits(ascii_buf, ascii_offset,
pkt_len*2,
data + offset, err,
err_info);
if (ascii_offset == -1)
{
return FALSE;
}
continue;
}
ascii_strup_inplace (data);
num_items_scanned =
sscanf (data+78,
"%*[ \n\t]ETHV2%*[ .:\n\t]TYPE%*[ .:\n\t]%4s",type);
if ((num_items_scanned == 1) && pktline > 1)
{
isCurrentPacket = FALSE;
cur_off = file_tell( fh);
if (cur_off == -1)
{
*err = file_error (fh, err_info);
goto errxit;
}
if (file_seek (fh, cur_off - buflen, SEEK_SET, err) == -1)
{
goto errxit;
}
}
}
phdr->caplen = ((guint32) ascii_offset)/2;
ws_buffer_assure_space (buf, phdr->caplen);
iseries_parse_hex_string (ascii_buf, ws_buffer_start_ptr (buf), ascii_offset);
*err = 0;
g_free (ascii_buf);
return TRUE;
errxit:
g_free (ascii_buf);
return FALSE;
}
static int
iseries_UNICODE_to_ASCII (guint8 * buf, guint bytes)
{
guint i;
guint8 *bufptr;
bufptr = buf;
for (i = 0; i < bytes; i++)
{
switch (buf[i])
{
case 0xFE:
case 0xFF:
case 0x00:
break;
default:
*bufptr = buf[i];
bufptr++;
}
if (buf[i] == 0x0A)
return i;
}
return i;
}
static gboolean
iseries_parse_hex_string (const char * ascii, guint8 * buf, size_t len)
{
size_t i;
int byte;
gint hexvalue;
guint8 bytevalue;
byte = 0;
for (i = 0; i < len; i++)
{
hexvalue = g_ascii_xdigit_value(ascii[i]);
i++;
if (hexvalue == -1)
return FALSE;
bytevalue = (guint8)(hexvalue << 4);
if (i >= len)
return FALSE;
hexvalue = g_ascii_xdigit_value(ascii[i]);
if (hexvalue == -1)
return FALSE;
bytevalue |= (guint8) hexvalue;
buf[byte] = bytevalue;
byte++;
}
return TRUE;
}
