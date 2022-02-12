int
iseries_open (wtap * wth, int *err, gchar ** err_info)
{
int bytes_read;
gint offset;
char magic[ISERIES_LINE_LENGTH];
char unicodemagic[] =
{ '\x43', '\x00', '\x4F', '\x00', '\x4D',
'\x00', '\x4D', '\x00', '\x55', '\x00', '\x4E', '\x00', '\x49', '\x00',
'\x43', '\x00', '\x41'
};
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read (&magic, sizeof magic, wth->fh);
if (bytes_read != sizeof magic)
{
*err = file_error (wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
offset=0;
while ((unsigned)offset < (ISERIES_LINE_LENGTH - (sizeof unicodemagic)))
{
if (memcmp (magic + offset, unicodemagic, sizeof unicodemagic) == 0) {
if (file_seek (wth->fh, 0, SEEK_SET, err) == -1)
{
return 0;
}
if (!iseries_check_file_type (wth, err, err_info, ISERIES_FORMAT_UNICODE))
{
if (*err == 0)
return 0;
else
return -1;
}
wth->file_encap = WTAP_ENCAP_ETHERNET;
wth->file_type = WTAP_FILE_ISERIES;
wth->snapshot_length = 0;
wth->subtype_read = iseries_read;
wth->subtype_seek_read = iseries_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
if (file_seek (wth->fh, 0, SEEK_SET, err) == -1)
{
return 0;
}
return 1;
}
offset += 1;
}
offset=0;
while (offset < (ISERIES_LINE_LENGTH - ISERIES_HDR_MAGIC_LEN))
{
if (memcmp (magic + offset, ISERIES_HDR_MAGIC_STR, ISERIES_HDR_MAGIC_LEN) == 0)
{
if (file_seek (wth->fh, 0, SEEK_SET, err) == -1)
{
return 0;
}
if (!iseries_check_file_type (wth, err, err_info, ISERIES_FORMAT_ASCII))
{
if (*err == 0)
return 0;
else
return -1;
}
wth->file_encap = WTAP_ENCAP_ETHERNET;
wth->file_type = WTAP_FILE_ISERIES;
wth->snapshot_length = 0;
wth->subtype_read = iseries_read;
wth->subtype_seek_read = iseries_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
if (file_seek (wth->fh, 0, SEEK_SET, err) == -1)
{
return 0;
}
return 1;
}
offset += 1;
}
return 0;
}
static gboolean
iseries_check_file_type (wtap * wth, int *err, gchar **err_info, int format)
{
guint line;
int num_items_scanned;
char buf[ISERIES_LINE_LENGTH], protocol[9], type[5], work[2];
iseries_t *iseries;
iseries = (iseries_t *) g_malloc (sizeof (iseries_t));
wth->priv = (void *) iseries;
iseries->have_date = FALSE;
iseries->format = format;
iseries->tcp_formatted = FALSE;
iseries->ipv6_trace = FALSE;
for (line = 0; line < ISERIES_HDR_LINES_TO_CHECK; line++)
{
if (file_gets (buf, ISERIES_LINE_LENGTH, wth->fh) != NULL)
{
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
if (memcmp (protocol, "ETHERNET", 8) != 0)
return FALSE;
}
num_items_scanned = sscanf (buf,
"%*[ \n\t]START DATE/TIME%*[ .:\n\t]%2d/%2d/%2d",
&iseries->month, &iseries->day,
&iseries->year);
if (num_items_scanned == 3)
{
iseries->have_date = TRUE;
}
num_items_scanned =
sscanf (buf+78,
"%*[ \n\t]ETHV2%*[ .:\n\t]TYPE%*[ .:\n\t]%4s", type);
if (num_items_scanned == 1)
{
if (strncmp (type, "0800", 1) == 0)
{
iseries->ipv6_trace = FALSE;
}
if (strncmp (type, "86DD", 1) == 0)
{
iseries->ipv6_trace = TRUE;
}
}
num_items_scanned = sscanf (buf,
"%*[ \n\t]IPV6 HEADER%1s",
work);
if (num_items_scanned == 1)
{
iseries->tcp_formatted = TRUE;
return TRUE;
}
num_items_scanned = sscanf (buf,
"%*[ \n\t]IP HEADER %1s",
work);
if (num_items_scanned == 1)
{
iseries->tcp_formatted = TRUE;
return TRUE;
}
}
else
{
if (file_eof (wth->fh))
*err = 0;
else
*err = file_error (wth->fh, err_info);
return FALSE;
}
}
*err = 0;
return TRUE;
}
static gboolean
iseries_read (wtap * wth, int *err, gchar ** err_info, gint64 *data_offset)
{
gint64 offset;
int pkt_len;
offset = iseries_seek_next_packet (wth, err, err_info);
if (offset < 1)
return FALSE;
pkt_len =
iseries_parse_packet (wth, wth->fh, &wth->pseudo_header, NULL, err,
err_info);
if (pkt_len == -1)
return FALSE;
*data_offset = offset;
return TRUE;
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
if (file_gets (buf, ISERIES_LINE_LENGTH, wth->fh) != NULL)
{
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
else
{
if (file_eof (wth->fh))
{
*err = 0;
}
else
{
*err = file_error (wth->fh, err_info);
}
return -1;
}
}
return -1;
}
static gboolean
iseries_seek_read (wtap * wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 * pd,
int len, int *err, gchar ** err_info)
{
int pkt_len;
if (file_seek (wth->random_fh, seek_off - 1, SEEK_SET, err) == -1)
return FALSE;
pkt_len = iseries_parse_packet (wth, wth->random_fh, pseudo_header, pd,
err, err_info);
if (pkt_len != len)
{
if (pkt_len != -1)
{
*err = WTAP_ERR_BAD_FILE;
*err_info =
g_strdup_printf ("iseries: requested length %d doesn't match record length %d",
len, pkt_len);
}
return FALSE;
}
return TRUE;
}
static int
iseries_parse_packet (wtap * wth, FILE_T fh,
union wtap_pseudo_header *pseudo_header, guint8 *pd,
int *err, gchar **err_info)
{
iseries_t *iseries = (iseries_t *)wth->priv;
gint64 cur_off;
gboolean isValid, isCurrentPacket, IPread, TCPread, isDATA, isDataHandled;
int num_items_scanned, line, pktline, buflen;
guint32 pkt_len;
int cap_len, pktnum, hr, min, sec, csec;
char direction[2], destmac[13], srcmac[13], type[5];
char ipheader[41], tcpheader[81];
char hex1[17], hex2[17], hex3[17], hex4[17];
char data[ISERIES_LINE_LENGTH * 2];
guint8 *buf;
char *tcpdatabuf, *workbuf, *asciibuf;
struct tm tm;
isValid = FALSE;
for (line = 1; line < ISERIES_PKT_LINES_TO_CHECK; line++)
{
if (file_gets (data, ISERIES_LINE_LENGTH, fh) == NULL)
{
*err = file_error (fh, err_info);
if (*err == 0)
{
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
if (iseries->format == ISERIES_FORMAT_UNICODE)
{
iseries_UNICODE_to_ASCII ((guint8 *)data, ISERIES_LINE_LENGTH);
}
ascii_strup_inplace (data);
num_items_scanned =
sscanf (data,
"%*[ \n\t]%6d%*[ *\n\t]%1s%*[ \n\t]%6d%*[ \n\t]%2d:%2d:%2d.%9d%*[ \n\t]"
"%12s%*[ \n\t]%12s%*[ \n\t]ETHV2%*[ \n\t]TYPE:%*[ \n\t]%4s",
&pktnum, direction, &cap_len, &hr, &min, &sec, &csec, destmac,
srcmac, type);
if (num_items_scanned == 10)
{
isValid = TRUE;
cap_len += 14;
break;
}
}
if (!isValid)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: packet header isn't valid");
return -1;
}
wth->phdr.presence_flags = WTAP_HAS_CAP_LEN;
if (iseries->have_date)
{
wth->phdr.presence_flags |= WTAP_HAS_TS;
tm.tm_year = 100 + iseries->year;
tm.tm_mon = iseries->month - 1;
tm.tm_mday = iseries->day;
tm.tm_hour = hr;
tm.tm_min = min;
tm.tm_sec = sec;
tm.tm_isdst = -1;
wth->phdr.ts.secs = mktime (&tm);
if (csec > 99999)
{
wth->phdr.ts.nsecs = csec * 1000;
}
else
{
wth->phdr.ts.nsecs = csec * 10000;
}
}
wth->phdr.caplen = cap_len;
wth->phdr.pkt_encap = WTAP_ENCAP_ETHERNET;
pseudo_header->eth.fcs_len = -1;
isCurrentPacket = TRUE;
IPread = FALSE;
TCPread = FALSE;
isDATA = FALSE;
tcpdatabuf = g_malloc (ISERIES_PKT_ALLOC_SIZE);
workbuf = g_malloc (ISERIES_PKT_ALLOC_SIZE);
tcpdatabuf[0] = '\0';
workbuf[0] = '\0';
pktline = 0;
while (isCurrentPacket)
{
pktline++;
if (file_gets (data, ISERIES_LINE_LENGTH, fh) == NULL)
{
if (file_eof (fh))
{
break;
}
else
{
*err = file_error (fh, err_info);
if (*err == 0)
{
*err = WTAP_ERR_SHORT_READ;
}
goto errxit;
}
}
if (iseries->format == ISERIES_FORMAT_UNICODE)
{
buflen = iseries_UNICODE_to_ASCII ((guint8 *)data, ISERIES_LINE_LENGTH);
}
else
{
buflen = (int) strlen (data);
}
if ((!iseries->ipv6_trace) || ((iseries->ipv6_trace) && (!iseries->tcp_formatted)))
{
num_items_scanned = sscanf (data + 22, "IP Header%*[ .:\n\t]%40s", ipheader);
if (num_items_scanned == 1)
{
IPread = TRUE;
}
num_items_scanned = sscanf (data + 22, "TCP Header%*[ .:\n\t]%80s", tcpheader);
if (num_items_scanned == 1)
{
TCPread = TRUE;
}
num_items_scanned =
sscanf (data + 27, "%16[A-F0-9] %16[A-F0-9] %16[A-F0-9] %16[A-F0-9]",
hex1, hex2, hex3, hex4);
if (num_items_scanned > 0)
{
isDATA = TRUE;
switch (num_items_scanned)
{
case 1:
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s", tcpdatabuf,
hex1);
break;
case 2:
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s",
tcpdatabuf, hex1, hex2);
break;
case 3:
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s%s",
tcpdatabuf, hex1, hex2, hex3);
break;
default:
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s%s%s",
tcpdatabuf, hex1, hex2, hex3, hex4);
}
memcpy (tcpdatabuf, workbuf, ISERIES_PKT_ALLOC_SIZE);
}
}
if ((iseries->ipv6_trace) && (iseries->tcp_formatted))
{
isDataHandled=FALSE;
num_items_scanned =
sscanf (data + 35, "%*[ \n\t]%16[A-F0-9]%16[A-F0-9]%16[A-F0-9]%16[A-F0-9]",
hex1, hex2, hex3, hex4);
if (num_items_scanned > 0)
{
isDATA = TRUE;
switch (num_items_scanned)
{
case 1:
if (strlen(hex1)==16)
{
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s", tcpdatabuf,
hex1);
isDataHandled=TRUE;
}
break;
case 2:
if ((strlen(hex1)==16) && (strlen(hex2)==16))
{
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s",
tcpdatabuf, hex1, hex2);
isDataHandled=TRUE;
}
break;
case 3:
if ((strlen(hex1)==16) && (strlen(hex2)==16) && (strlen(hex3)==16))
{
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s%s",
tcpdatabuf, hex1, hex2, hex3);
isDataHandled=TRUE;
}
break;
default:
if ((strlen(hex1)==16) && (strlen(hex2)==16) && (strlen(hex3)==16) && (strlen(hex4)==16))
{
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s%s%s",
tcpdatabuf, hex1, hex2, hex3, hex4);
isDataHandled=TRUE;
}
}
memcpy (tcpdatabuf, workbuf, ISERIES_PKT_ALLOC_SIZE);
}
num_items_scanned =
sscanf (data + 26, "%*[ \n\t]%16[A-F0-9]%16[A-F0-9]%16[A-F0-9]%16[A-F0-9]",
hex1, hex2, hex3, hex4);
if ((num_items_scanned > 0) && (isDataHandled==FALSE))
{
isDATA = TRUE;
switch (num_items_scanned)
{
case 1:
if (strlen(hex1)==16)
{
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s", tcpdatabuf,
hex1);
}
break;
case 2:
if ((strlen(hex1)==16) && (strlen(hex2)==16))
{
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s",
tcpdatabuf, hex1, hex2);
}
break;
case 3:
if ((strlen(hex1)==16) && (strlen(hex2)==16) && (strlen(hex3)==16))
{
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s%s",
tcpdatabuf, hex1, hex2, hex3);
}
break;
default:
if ((strlen(hex1)==16) && (strlen(hex2)==16) && (strlen(hex3)==16) && (strlen(hex4)==16))
{
g_snprintf (workbuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s%s%s",
tcpdatabuf, hex1, hex2, hex3, hex4);
}
}
memcpy (tcpdatabuf, workbuf, ISERIES_PKT_ALLOC_SIZE);
}
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
if ((iseries->tcp_formatted) && (iseries->ipv6_trace == FALSE))
{
if (!IPread)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: IP header isn't valid");
goto errxit;
}
if (!TCPread)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup ("iseries: TCP header isn't valid");
goto errxit;
}
}
asciibuf = g_malloc (ISERIES_PKT_ALLOC_SIZE);
if (isDATA)
{
if ((iseries->tcp_formatted) && (iseries->ipv6_trace == FALSE))
{
g_snprintf (asciibuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s%s%s%s",
destmac, srcmac, type, ipheader, tcpheader, tcpdatabuf);
}
else
{
g_snprintf (asciibuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s%s", destmac,
srcmac, type, tcpdatabuf);
}
}
else
{
g_snprintf (asciibuf, ISERIES_PKT_ALLOC_SIZE, "%s%s%s%s%s", destmac,
srcmac, type, ipheader, tcpheader);
}
if (!iseries->ipv6_trace)
{
sscanf (asciibuf + 32, "%4x", &pkt_len);
wth->phdr.len = pkt_len + 14;
}
else
{
sscanf (asciibuf + 36, "%4x", &pkt_len);
wth->phdr.len = pkt_len + 14;
}
if (wth->phdr.caplen > wth->phdr.len)
wth->phdr.len = wth->phdr.caplen;
if (pd == NULL)
{
buffer_assure_space (wth->frame_buffer, ISERIES_MAX_PACKET_LEN);
buf = buffer_start_ptr (wth->frame_buffer);
iseries_parse_hex_string (asciibuf, buf, (int) strlen (asciibuf));
}
else
{
iseries_parse_hex_string (asciibuf, pd, (int) strlen (asciibuf));
}
*err = 0;
g_free (asciibuf);
g_free (tcpdatabuf);
g_free (workbuf);
return wth->phdr.len;
errxit:
g_free (tcpdatabuf);
g_free (workbuf);
return -1;
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
iseries_parse_hex_string (const char * ascii, guint8 * buf, int len)
{
int i, byte;
gint hexvalue;
guint8 bytevalue;
byte = 0;
i = 0;
for (;;)
{
if (i >= len)
break;
hexvalue = g_ascii_xdigit_value(ascii[i]);
i++;
if (hexvalue == -1)
return FALSE;
bytevalue = (guint8)(hexvalue << 4);
if (i >= len)
return FALSE;
hexvalue = g_ascii_xdigit_value(ascii[i]);
i++;
if (hexvalue == -1)
return FALSE;
bytevalue |= (guint8) hexvalue;
buf[byte] = bytevalue;
byte++;
}
return TRUE;
}
