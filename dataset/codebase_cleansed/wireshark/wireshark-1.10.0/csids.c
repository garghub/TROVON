int csids_open(wtap *wth, int *err, gchar **err_info)
{
int tmp,iplen,bytesRead;
gboolean byteswap = FALSE;
struct csids_header hdr;
csids_t *csids;
bytesRead = file_read( &hdr, sizeof( struct csids_header), wth->fh );
if( bytesRead != sizeof( struct csids_header) ) {
*err = file_error( wth->fh, err_info );
if( *err != 0 && *err != WTAP_ERR_SHORT_READ ) {
return -1;
}
return 0;
}
if( hdr.zeropad != 0 || hdr.caplen == 0 ) {
return 0;
}
hdr.seconds = pntohl( &hdr.seconds );
hdr.caplen = pntohs( &hdr.caplen );
bytesRead = file_read( &tmp, 2, wth->fh );
if( bytesRead != 2 ) {
*err = file_error( wth->fh, err_info );
if( *err != 0 && *err != WTAP_ERR_SHORT_READ ) {
return -1;
}
return 0;
}
bytesRead = file_read( &iplen, 2, wth->fh );
if( bytesRead != 2 ) {
*err = file_error( wth->fh, err_info );
if( *err != 0 && *err != WTAP_ERR_SHORT_READ ) {
return -1;
}
return 0;
}
iplen = pntohs(&iplen);
if ( iplen == 0 )
return 0;
if( iplen > hdr.caplen ) {
iplen = BSWAP16(iplen);
if( iplen <= hdr.caplen ) {
byteswap = TRUE;
} else {
return 0;
}
} else {
byteswap = FALSE;
}
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return -1;
csids = (csids_t *)g_malloc(sizeof(csids_t));
wth->priv = (void *)csids;
csids->byteswapped = byteswap;
wth->file_encap = WTAP_ENCAP_RAW_IP;
wth->file_type = WTAP_FILE_CSIDS;
wth->snapshot_length = 0;
wth->subtype_read = csids_read;
wth->subtype_seek_read = csids_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_SEC;
return 1;
}
static gboolean csids_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
csids_t *csids = (csids_t *)wth->priv;
guint8 *buf;
int bytesRead = 0;
struct csids_header hdr;
*data_offset = file_tell(wth->fh);
bytesRead = file_read( &hdr, sizeof( struct csids_header) , wth->fh );
if( bytesRead != sizeof( struct csids_header) ) {
*err = file_error( wth->fh, err_info );
if (*err == 0 && bytesRead != 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
hdr.seconds = pntohl(&hdr.seconds);
hdr.caplen = pntohs(&hdr.caplen);
buffer_assure_space(wth->frame_buffer, hdr.caplen);
buf = buffer_start_ptr(wth->frame_buffer);
bytesRead = file_read( buf, hdr.caplen, wth->fh );
if( bytesRead != hdr.caplen ) {
*err = file_error( wth->fh, err_info );
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.len = hdr.caplen;
wth->phdr.caplen = hdr.caplen;
wth->phdr.ts.secs = hdr.seconds;
wth->phdr.ts.nsecs = 0;
if( csids->byteswapped ) {
if( hdr.caplen >= 2 ) {
PBSWAP16(buf);
if( hdr.caplen >= 4 ) {
PBSWAP16(buf+2);
if( hdr.caplen >= 6 )
PBSWAP16(buf+4);
}
}
}
return TRUE;
}
static gboolean
csids_seek_read (wtap *wth,
gint64 seek_off,
struct wtap_pkthdr *phdr _U_,
guint8 *pd,
int len,
int *err,
gchar **err_info)
{
csids_t *csids = (csids_t *)wth->priv;
int bytesRead;
struct csids_header hdr;
if( file_seek( wth->random_fh, seek_off, SEEK_SET, err ) == -1 )
return FALSE;
bytesRead = file_read( &hdr, sizeof( struct csids_header), wth->random_fh );
if( bytesRead != sizeof( struct csids_header) ) {
*err = file_error( wth->random_fh, err_info );
if( *err == 0 ) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
hdr.seconds = pntohl(&hdr.seconds);
hdr.caplen = pntohs(&hdr.caplen);
if( len != hdr.caplen ) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("csids: record length %u doesn't match requested length %d",
hdr.caplen, len);
return FALSE;
}
bytesRead = file_read( pd, hdr.caplen, wth->random_fh );
if( bytesRead != hdr.caplen ) {
*err = file_error( wth->random_fh, err_info );
if( *err == 0 ) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
if( csids->byteswapped ) {
if( hdr.caplen >= 2 ) {
PBSWAP16(pd);
if( hdr.caplen >= 4 ) {
PBSWAP16(pd+2);
if( hdr.caplen >= 6 )
PBSWAP16(pd+4);
}
}
}
return TRUE;
}
