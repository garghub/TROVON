static int
hc2b(unsigned char hex)
{
hex = tolower(hex);
if ((hex >= '0') && (hex <= '9'))
return hex - '0';
if ((hex >= 'a') && (hex <= 'f'))
return hex - 'a' + 10;
return -1;
}
static int
hex2bin(guint8 *out, guint8 *out_end, char *in)
{
guint8 *out_start = out;
int is_low = 0;
int c;
while (*in != '\0')
{
c = hc2b(*(unsigned char *)in);
if (c < 0)
{
in++;
continue;
}
if (out == out_end)
{
return -1;
}
if (is_low == 0)
{
*out = c << 4;
is_low = 1;
} else {
*out |= (c & 0x0f);
is_low = 0;
out++;
}
in++;
}
return (int)(out - out_start);
}
static int
xml_get_int(int *val, const char *str, const char *pattern)
{
const char *ptr;
char *start, *end;
char buf[32];
ptr = strstr(str, pattern);
if (ptr == NULL)
return -1;
start = strchr(ptr, '"');
if (start == NULL)
return -2;
start++;
end = strchr(start, '"');
if (end == NULL)
return -3;
if (end - start > 31)
return -4;
memcpy(buf, start, end - start);
buf[end - start] = '\0';
*val = atoi(buf);
return 0;
}
int dct3trace_open(wtap *wth, int *err, gchar **err_info)
{
char line1[64], line2[64];
if (file_gets(line1, sizeof(line1), wth->fh) == NULL ||
file_gets(line2, sizeof(line2), wth->fh) == NULL)
{
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if( strncmp(dct3trace_magic_line1, line1, strlen(dct3trace_magic_line1)) != 0 ||
strncmp(dct3trace_magic_line2, line2, strlen(dct3trace_magic_line2)) != 0)
{
return 0;
}
wth->file_encap = WTAP_ENCAP_GSM_UM;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_DCT3TRACE;
wth->snapshot_length = 0;
wth->subtype_read = dct3trace_read;
wth->subtype_seek_read = dct3trace_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_SEC;
return 1;
}
static gboolean dct3trace_get_packet(FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
char line[1024];
guint8 databuf[MAX_PACKET_LEN], *bufp;
gboolean have_data = FALSE;
int len = 0;
bufp = &databuf[0];
while (file_gets(line, sizeof(line), fh) != NULL)
{
if( memcmp(dct3trace_magic_end, line, strlen(dct3trace_magic_end)) == 0 )
{
*err = 0;
return FALSE;
}
else if( memcmp(dct3trace_magic_record_end, line, strlen(dct3trace_magic_record_end)) == 0 )
{
if( have_data )
{
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = 0;
phdr->ts.secs = 0;
phdr->ts.nsecs = 0;
phdr->caplen = len;
phdr->len = len;
*err = 0;
buffer_assure_space(buf, phdr->caplen);
memcpy( buffer_start_ptr(buf), databuf, phdr->caplen );
return TRUE;
}
else
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("dct3trace: record without data");
return FALSE;
}
}
else if( memcmp(dct3trace_magic_record_start, line, strlen(dct3trace_magic_record_start)) == 0 )
{
int channel, tmp;
char *ptr;
phdr->pseudo_header.gsm_um.uplink = !strstr(line, "direction=\"down\"");
if (xml_get_int(&channel, line, "logicalchannel") != 0)
goto baddata;
if( !phdr->pseudo_header.gsm_um.uplink )
{
if (xml_get_int(&tmp, line, "physicalchannel") != 0)
goto baddata;
phdr->pseudo_header.gsm_um.arfcn = tmp;
if (xml_get_int(&tmp, line, "sequence") != 0)
goto baddata;
phdr->pseudo_header.gsm_um.tdma_frame = tmp;
if (xml_get_int(&tmp, line, "bsic") != 0)
goto baddata;
phdr->pseudo_header.gsm_um.bsic = tmp;
if (xml_get_int(&tmp, line, "error") != 0)
goto baddata;
phdr->pseudo_header.gsm_um.error = tmp;
if (xml_get_int(&tmp, line, "timeshift") != 0)
goto baddata;
phdr->pseudo_header.gsm_um.timeshift = tmp;
}
switch( channel )
{
case 128: phdr->pseudo_header.gsm_um.channel = GSM_UM_CHANNEL_SDCCH; break;
case 112: phdr->pseudo_header.gsm_um.channel = GSM_UM_CHANNEL_SACCH; break;
case 176: phdr->pseudo_header.gsm_um.channel = GSM_UM_CHANNEL_FACCH; break;
case 96: phdr->pseudo_header.gsm_um.channel = GSM_UM_CHANNEL_CCCH; break;
case 80: phdr->pseudo_header.gsm_um.channel = GSM_UM_CHANNEL_BCCH; break;
default: phdr->pseudo_header.gsm_um.channel = GSM_UM_CHANNEL_UNKNOWN; break;
}
ptr = strstr(line, "data=\"");
if( ptr )
{
have_data = TRUE;
len = hex2bin(bufp, &databuf[MAX_PACKET_LEN], ptr+6);
if (len == -1)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("dct3trace: record length %d too long", phdr->caplen);
return FALSE;
}
}
}
else if( !have_data && memcmp(dct3trace_magic_l2_start, line, strlen(dct3trace_magic_l2_start)) == 0 )
{
int data_len;
char *ptr = strstr(line, "data=\"");
if( !ptr )
{
continue;
}
have_data = TRUE;
if( phdr->pseudo_header.gsm_um.channel == GSM_UM_CHANNEL_SACCH || phdr->pseudo_header.gsm_um.channel == GSM_UM_CHANNEL_FACCH || phdr->pseudo_header.gsm_um.channel == GSM_UM_CHANNEL_SDCCH )
{
memset(bufp, 0x1, 2);
len = 3;
}
else
{
len = 1;
}
bufp += len;
data_len = hex2bin(bufp, &databuf[MAX_PACKET_LEN], ptr+6);
if (data_len == -1)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("dct3trace: record length %d too long", phdr->caplen);
return FALSE;
}
len += data_len;
*(bufp - 1) = data_len << 2 | 0x1;
}
}
*err = file_error(fh, err_info);
if (*err == 0)
{
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
baddata:
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("dct3trace: record missing mandatory attributes");
return FALSE;
}
static gboolean dct3trace_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
return dct3trace_get_packet(wth->fh, &wth->phdr, wth->frame_buffer,
err, err_info);
}
static gboolean dct3trace_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
{
return FALSE;
}
return dct3trace_get_packet(wth->random_fh, phdr, buf, err, err_info);
}
