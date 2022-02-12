static gboolean
read_block(FILE_T fh, guint8 *buf, guint16 buf_len, int *err, gchar **err_info)
{
int bytes_read;
bytes_read = file_read((void *)buf, buf_len, fh);
if (bytes_read != buf_len) {
*err = file_error(fh, err_info);
if (bytes_read>0 && *err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
return TRUE;
}
static gboolean
find_next_pkt_dat_type_len(FILE_T fh,
guint8 *dat_trans_type,
guint16 *dat_len,
int *err, gchar **err_info)
{
guint8 block[2];
size_read_t size_stat;
if (!dat_trans_type || !dat_len)
return FALSE;
RESET_STAT_VALS;
do {
if (read_block(fh, block, sizeof(block), err, err_info) == FALSE) {
RESET_STAT_VALS;
return FALSE;
}
switch (block[1]) {
case TRANS_READ_SIZE_LOW:
if (*dat_trans_type != TRANS_CAM_HOST)
RESET_STAT_VALS;
*dat_trans_type = TRANS_CAM_HOST;
*dat_len |= block[0];
SIZE_ADD_LOW;
break;
case TRANS_READ_SIZE_HIGH:
if (*dat_trans_type != TRANS_CAM_HOST)
RESET_STAT_VALS;
*dat_trans_type = TRANS_CAM_HOST;
*dat_len |= (block[0] << 8);
SIZE_ADD_HIGH;
break;
case TRANS_WRITE_SIZE_LOW:
if (*dat_trans_type != TRANS_HOST_CAM)
RESET_STAT_VALS;
*dat_trans_type = TRANS_HOST_CAM;
*dat_len |= block[0];
SIZE_ADD_LOW;
break;
case TRANS_WRITE_SIZE_HIGH:
if (*dat_trans_type != TRANS_HOST_CAM)
RESET_STAT_VALS;
*dat_trans_type = TRANS_HOST_CAM;
*dat_len |= (block[0] << 8);
SIZE_ADD_HIGH;
break;
default:
break;
}
} while (size_stat != SIZE_HAVE_ALL);
return TRUE;
}
static gint
read_packet_data(FILE_T fh, guint8 dat_trans_type, guint8 *buf, guint16 dat_len,
int *err, gchar **err_info)
{
guint8 *p;
guint8 block[2];
guint16 bytes_count = 0;
if (!buf)
return -1;
p = buf;
while (bytes_count < dat_len) {
if (read_block(fh, block, sizeof(block), err, err_info) == FALSE)
break;
if (block[1] == dat_trans_type) {
*p++ = block[0];
bytes_count++;
}
else if (IS_TRANS_SIZE(block[1])) {
if (-1 == file_seek(fh, -(gint64)sizeof(block), SEEK_CUR, err))
return -1;
break;
}
}
return bytes_count;
}
static gint
create_pseudo_hdr(guint8 *buf, guint8 dat_trans_type, guint16 dat_len)
{
if (!buf)
return -1;
buf[0] = DVB_CI_PSEUDO_HDR_VER;
if (dat_trans_type==TRANS_CAM_HOST)
buf[1] = DVB_CI_PSEUDO_HDR_CAM_TO_HOST;
else if (dat_trans_type==TRANS_HOST_CAM)
buf[1] = DVB_CI_PSEUDO_HDR_HOST_TO_CAM;
else
return -1;
buf[2] = (dat_len>>8) & 0xFF;
buf[3] = dat_len & 0xFF;
return DVB_CI_PSEUDO_HDR_LEN;
}
static gboolean
camins_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
guint8 dat_trans_type;
guint16 dat_len;
gboolean ret;
guint8 *p;
gint offset, bytes_read;
*data_offset = file_tell(wth->fh);
ret = find_next_pkt_dat_type_len(
wth->fh, &dat_trans_type, &dat_len, err, err_info);
if (!ret)
return FALSE;
buffer_assure_space(wth->frame_buffer, DVB_CI_PSEUDO_HDR_LEN+dat_len);
p = buffer_start_ptr(wth->frame_buffer);
offset = create_pseudo_hdr(p, dat_trans_type, dat_len);
if (offset<0) {
*err = WTAP_ERR_INTERNAL;
return FALSE;
}
bytes_read = read_packet_data(wth->fh, dat_trans_type,
&p[offset], dat_len, err, err_info);
if (bytes_read < 0)
return FALSE;
offset += bytes_read;
wth->phdr.pkt_encap = WTAP_ENCAP_DVBCI;
wth->phdr.ts.secs = 0;
wth->phdr.ts.nsecs = 0;
wth->phdr.caplen = offset;
wth->phdr.len = offset;
return TRUE;
}
static gboolean
camins_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *pkthdr _U_, guint8 *pd, int length,
int *err, gchar **err_info)
{
guint8 dat_trans_type;
guint16 dat_len;
gboolean ret;
gint offset, bytes_read;
if (-1 == file_seek(wth->random_fh, seek_off, SEEK_SET, err))
return FALSE;
ret = find_next_pkt_dat_type_len(wth->random_fh, &dat_trans_type,
&dat_len, err, err_info);
if (!ret)
return FALSE;
offset = create_pseudo_hdr(pd, dat_trans_type, dat_len);
if (offset<0)
return FALSE;
bytes_read = read_packet_data(wth->random_fh, dat_trans_type,
&pd[offset], length, err, err_info);
if (bytes_read < 0)
return FALSE;
return TRUE;
}
int camins_open(wtap *wth, int *err, gchar **err_info _U_)
{
guint8 found_start_blocks = 0;
guint8 count = 0;
guint8 block[2];
int bytes_read;
do {
bytes_read = file_read(block, sizeof(block), wth->fh);
if (bytes_read != sizeof(block))
break;
if (block[0]==0x00 && block[1] == 0xE1)
found_start_blocks++;
count++;
} while (count<20);
if (found_start_blocks < 2)
return 0;
if (-1 == file_seek(wth->fh, 0, SEEK_SET, err))
return -1;
wth->file_encap = WTAP_ENCAP_DVBCI;
wth->snapshot_length = 0;
wth->tsprecision = WTAP_FILE_TSPREC_MSEC;
wth->priv = NULL;
wth->subtype_read = camins_read;
wth->subtype_seek_read = camins_seek_read;
wth->file_type = WTAP_FILE_CAMINS;
*err = 0;
return 1;
}
