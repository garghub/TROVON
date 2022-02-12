void k12_fprintf(const char* fmt, ...) {
va_list ap;
va_start(ap,fmt);
vfprintf(dbg_out, fmt, ap);
va_end(ap);
}
void k12_hex_ascii_dump(guint level, gint64 offset, const char* label, const unsigned char* b, unsigned int len) {
static const char* c2t[] = {
"00","01","02","03","04","05","06","07","08","09","0a","0b","0c","0d","0e","0f",
"10","11","12","13","14","15","16","17","18","19","1a","1b","1c","1d","1e","1f",
"20","21","22","23","24","25","26","27","28","29","2a","2b","2c","2d","2e","2f",
"30","31","32","33","34","35","36","37","38","39","3a","3b","3c","3d","3e","3f",
"40","41","42","43","44","45","46","47","48","49","4a","4b","4c","4d","4e","4f",
"50","51","52","53","54","55","56","57","58","59","5a","5b","5c","5d","5e","5f",
"60","61","62","63","64","65","66","67","68","69","6a","6b","6c","6d","6e","6f",
"70","71","72","73","74","75","76","77","78","79","7a","7b","7c","7d","7e","7f",
"80","81","82","83","84","85","86","87","88","89","8a","8b","8c","8d","8e","8f",
"90","91","92","93","94","95","96","97","98","99","9a","9b","9c","9d","9e","9f",
"a0","a1","a2","a3","a4","a5","a6","a7","a8","a9","aa","ab","ac","ad","ae","af",
"b0","b1","b2","b3","b4","b5","b6","b7","b8","b9","ba","bb","bc","bd","be","bf",
"c0","c1","c2","c3","c4","c5","c6","c7","c8","c9","ca","cb","cc","cd","ce","cf",
"d0","d1","d2","d3","d4","d5","d6","d7","d8","d9","da","db","dc","dd","de","df",
"e0","e1","e2","e3","e4","e5","e6","e7","e8","e9","ea","eb","ec","ed","ee","ef",
"f0","f1","f2","f3","f4","f5","f6","f7","f8","f9","fa","fb","fc","fd","fe","ff"
};
unsigned int i, j;
if (debug_level < level) return;
fprintf(dbg_out,"%s(%.8" G_GINT64_MODIFIER "x,%.4x):\n",label,offset,len);
for (i=0 ; i<len ; i += 16) {
for (j=0; j<16; j++) {
if ((j%4)==0)
fprintf(dbg_out," ");
if ((i+j)<len)
fprintf(dbg_out, "%s", c2t[b[i+j]]);
else
fprintf(dbg_out, " ");
}
fprintf(dbg_out, " ");
for (j=0; j<16; j++) {
if ((i+j)<len)
fprintf(dbg_out, "%c", g_ascii_isprint(b[i+j]) ? b[i+j] : '.');
}
fprintf(dbg_out,"\n");
}
}
void k12_ascii_dump(guint level, guint8 *buf, guint32 len, guint32 buf_offset) {
guint32 i;
if (debug_level < level) return;
for (i = buf_offset; i < len; i++) {
if (g_ascii_isprint(buf[i]) || buf[i] == '\n' || buf[i] == '\t')
putc(buf[i], dbg_out);
else if (buf[i] == '\0')
fprintf(dbg_out, "(NUL)\n");
}
}
static gint get_record(k12_t *file_data, FILE_T fh, gint64 file_offset,
gboolean is_random, int *err, gchar **err_info) {
guint8 *buffer = is_random ? file_data->rand_read_buff : file_data->seq_read_buff;
guint buffer_len = is_random ? file_data->rand_read_buff_len : file_data->seq_read_buff_len;
guint total_read = 0;
guint left;
guint8* writep;
#ifdef DEBUG_K12
guint actual_len;
#endif
guint junky_offset = 8192 - (gint) ( (file_offset - K12_FILE_HDR_LEN) % 8192 );
K12_DBG(6,("get_record: ENTER: junky_offset=%" G_GINT64_MODIFIER "d, file_offset=%" G_GINT64_MODIFIER "d",junky_offset,file_offset));
if (buffer == NULL) {
buffer = (guint8*)g_malloc(8192);
buffer_len = 8192;
if (is_random) {
file_data->rand_read_buff = buffer;
file_data->rand_read_buff_len = buffer_len;
} else {
file_data->seq_read_buff = buffer;
file_data->seq_read_buff_len = buffer_len;
}
}
if ( junky_offset == 8192 ) {
if ( ! file_skip( fh, K12_FILE_BLOB_LEN, err ) )
return -1;
total_read += K12_FILE_BLOB_LEN;
}
if ( !wtap_read_bytes( fh, buffer, 4, err, err_info ) )
return -1;
total_read += 4;
left = pntoh32(buffer + K12_RECORD_LEN);
#ifdef DEBUG_K12
actual_len = left;
#endif
junky_offset -= 4;
K12_DBG(5,("get_record: GET length=%u",left));
if (left < 8) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("k12: Record length %u is less than 8 bytes long",left);
return -1;
}
if (left > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("k12: Record length %u is greater than the maximum %u",left,WTAP_MAX_PACKET_SIZE);
return -1;
}
while (left > buffer_len) {
buffer = (guint8*)g_realloc(buffer,buffer_len*=2);
if (is_random) {
file_data->rand_read_buff = buffer;
file_data->rand_read_buff_len = buffer_len;
} else {
file_data->seq_read_buff = buffer;
file_data->seq_read_buff_len = buffer_len;
}
}
writep = buffer + 4;
left -= 4;
do {
K12_DBG(6,("get_record: looping left=%d junky_offset=%" G_GINT64_MODIFIER "d",left,junky_offset));
if (junky_offset > left) {
if ( !wtap_read_bytes( fh, writep, left, err, err_info ) )
return -1;
total_read += left;
break;
} else {
if ( !wtap_read_bytes( fh, writep, junky_offset, err, err_info ) )
return -1;
total_read += junky_offset;
writep += junky_offset;
if ( !file_skip( fh, K12_FILE_BLOB_LEN, err ) )
return -1;
total_read += K12_FILE_BLOB_LEN;
left -= junky_offset;
junky_offset = 8192;
}
} while(left);
K12_HEX_ASCII_DUMP(5,file_offset, "GOT record", buffer, actual_len);
return total_read;
}
static gboolean
memiszero(const void *ptr, size_t count)
{
const guint8 *p = (const guint8 *)ptr;
while (count != 0) {
if (*p != 0)
return FALSE;
p++;
count--;
}
return TRUE;
}
static void
process_packet_data(struct wtap_pkthdr *phdr, Buffer *target, guint8 *buffer,
gint len, k12_t *k12)
{
guint32 type;
guint buffer_offset;
guint64 ts;
guint32 length;
guint32 extra_len;
guint32 src_id;
k12_src_desc_t* src_desc;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
ts = pntoh64(buffer + K12_PACKET_TIMESTAMP);
phdr->ts.secs = (guint32) ((ts / 2000000) + 631152000);
phdr->ts.nsecs = (guint32) ( (ts % 2000000) * 500 );
length = pntoh32(buffer + K12_RECORD_FRAME_LEN) & 0x00001FFF;
phdr->len = phdr->caplen = length;
type = pntoh32(buffer + K12_RECORD_TYPE);
buffer_offset = (type == K12_REC_D0020) ? K12_PACKET_FRAME_D0020 : K12_PACKET_FRAME;
ws_buffer_assure_space(target, length);
memcpy(ws_buffer_start_ptr(target), buffer + buffer_offset, length);
extra_len = len - buffer_offset - length;
ws_buffer_assure_space(&(k12->extra_info), extra_len);
memcpy(ws_buffer_start_ptr(&(k12->extra_info)),
buffer + buffer_offset + length, extra_len);
phdr->pseudo_header.k12.extra_info = (guint8*)ws_buffer_start_ptr(&(k12->extra_info));
phdr->pseudo_header.k12.extra_length = extra_len;
src_id = pntoh32(buffer + K12_RECORD_SRC_ID);
K12_DBG(5,("process_packet_data: src_id=%.8x",src_id));
phdr->pseudo_header.k12.input = src_id;
if ( ! (src_desc = (k12_src_desc_t*)g_hash_table_lookup(k12->src_by_id,GUINT_TO_POINTER(src_id))) ) {
src_desc = (k12_src_desc_t*)g_hash_table_lookup(k12->src_by_id,GUINT_TO_POINTER(src_id&K12_RECORD_SRC_ID_MASK));
}
if (src_desc) {
K12_DBG(5,("process_packet_data: input_name='%s' stack_file='%s' type=%x",src_desc->input_name,src_desc->stack_file,src_desc->input_type));
phdr->pseudo_header.k12.input_name = src_desc->input_name;
phdr->pseudo_header.k12.stack_file = src_desc->stack_file;
phdr->pseudo_header.k12.input_type = src_desc->input_type;
switch(src_desc->input_type) {
case K12_PORT_ATMPVC:
if ((long)(buffer_offset + length + K12_PACKET_OFFSET_CID) < len) {
phdr->pseudo_header.k12.input_info.atm.vp = pntoh16(buffer + buffer_offset + length + K12_PACKET_OFFSET_VP);
phdr->pseudo_header.k12.input_info.atm.vc = pntoh16(buffer + buffer_offset + length + K12_PACKET_OFFSET_VC);
phdr->pseudo_header.k12.input_info.atm.cid = *((unsigned char*)(buffer + buffer_offset + length + K12_PACKET_OFFSET_CID));
break;
}
default:
memcpy(&(phdr->pseudo_header.k12.input_info),&(src_desc->input_info),sizeof(src_desc->input_info));
break;
}
} else {
K12_DBG(5,("process_packet_data: NO SRC_RECORD FOUND"));
memset(&(phdr->pseudo_header.k12),0,sizeof(phdr->pseudo_header.k12));
phdr->pseudo_header.k12.input_name = "unknown port";
phdr->pseudo_header.k12.stack_file = "unknown stack file";
}
phdr->pseudo_header.k12.input = src_id;
phdr->pseudo_header.k12.stuff = k12;
}
static gboolean k12_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset) {
k12_t *k12 = (k12_t *)wth->priv;
k12_src_desc_t* src_desc;
guint8* buffer;
gint64 offset;
gint len;
guint32 type;
guint32 src_id;
offset = file_tell(wth->fh);
do {
if ( k12->num_of_records == 0 ) {
*err = 0;
return FALSE;
}
K12_DBG(5,("k12_read: offset=%i",offset));
*data_offset = offset;
len = get_record(k12, wth->fh, offset, FALSE, err, err_info);
if (len < 0) {
return FALSE;
} else if (len == 0) {
*err = WTAP_ERR_SHORT_READ;
return FALSE;
} else if (len < K12_RECORD_SRC_ID + 4) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("data record length %d too short", len);
return FALSE;
}
k12->num_of_records--;
buffer = k12->seq_read_buff;
type = pntoh32(buffer + K12_RECORD_TYPE);
src_id = pntoh32(buffer + K12_RECORD_SRC_ID);
if ( ! (src_desc = (k12_src_desc_t*)g_hash_table_lookup(k12->src_by_id,GUINT_TO_POINTER(src_id))) ) {
src_desc = (k12_src_desc_t*)g_hash_table_lookup(k12->src_by_id,GUINT_TO_POINTER(src_id&K12_RECORD_SRC_ID_MASK));
}
K12_DBG(5,("k12_read: record type=%x src_id=%x",type,src_id));
offset += len;
} while ( ((type & K12_MASK_PACKET) != K12_REC_PACKET && (type & K12_MASK_PACKET) != K12_REC_D0020) || !src_id || !src_desc );
process_packet_data(&wth->phdr, wth->frame_buffer, buffer, len, k12);
return TRUE;
}
static gboolean k12_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info) {
k12_t *k12 = (k12_t *)wth->priv;
guint8* buffer;
gint len;
K12_DBG(5,("k12_seek_read: ENTER"));
if ( file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1) {
K12_DBG(5,("k12_seek_read: SEEK ERROR"));
return FALSE;
}
len = get_record(k12, wth->random_fh, seek_off, TRUE, err, err_info);
if (len < 0) {
K12_DBG(5,("k12_seek_read: READ ERROR"));
return FALSE;
} else if (len < K12_RECORD_SRC_ID + 4) {
K12_DBG(5,("k12_seek_read: SHORT READ"));
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
buffer = k12->rand_read_buff;
process_packet_data(phdr, buf, buffer, len, k12);
K12_DBG(5,("k12_seek_read: DONE OK"));
return TRUE;
}
static k12_t* new_k12_file_data(void) {
k12_t* fd = g_new(k12_t,1);
fd->file_len = 0;
fd->num_of_records = 0;
fd->src_by_name = g_hash_table_new(g_str_hash,g_str_equal);
fd->src_by_id = g_hash_table_new(g_direct_hash,g_direct_equal);
fd->seq_read_buff = NULL;
fd->seq_read_buff_len = 0;
fd->rand_read_buff = NULL;
fd->rand_read_buff_len = 0;
ws_buffer_init(&(fd->extra_info), 100);
return fd;
}
static gboolean destroy_srcdsc(gpointer k _U_, gpointer v, gpointer p _U_) {
k12_src_desc_t* rec = (k12_src_desc_t*)v;
g_free(rec->input_name);
g_free(rec->stack_file);
g_free(rec);
return TRUE;
}
static void destroy_k12_file_data(k12_t* fd) {
g_hash_table_destroy(fd->src_by_id);
g_hash_table_foreach_remove(fd->src_by_name,destroy_srcdsc,NULL);
g_hash_table_destroy(fd->src_by_name);
ws_buffer_free(&(fd->extra_info));
g_free(fd->seq_read_buff);
g_free(fd->rand_read_buff);
g_free(fd);
}
static void k12_close(wtap *wth) {
k12_t *k12 = (k12_t *)wth->priv;
destroy_k12_file_data(k12);
wth->priv = NULL;
#ifdef DEBUG_K12
K12_DBG(5,("k12_close: CLOSED"));
if (env_file) fclose(dbg_out);
#endif
}
wtap_open_return_val k12_open(wtap *wth, int *err, gchar **err_info) {
k12_src_desc_t* rec;
guint8 header_buffer[K12_FILE_HDR_LEN];
guint8* read_buffer;
guint32 type;
long offset;
long len;
guint port_type;
guint32 rec_len;
guint32 hwpart_len;
guint32 name_len;
guint32 stack_len;
guint i;
k12_t* file_data;
#ifdef DEBUG_K12
gchar* env_level = getenv("K12_DEBUG_LEVEL");
env_file = getenv("K12_DEBUG_FILENAME");
if ( env_file ) {
dbg_out = ws_fopen(env_file,"w");
if (dbg_out == NULL) {
dbg_out = stderr;
K12_DBG(1,("unable to open K12 DEBUG FILENAME for writing! Logging to standard error"));
}
}
else
dbg_out = stderr;
if ( env_level ) debug_level = (unsigned int)strtoul(env_level,NULL,10);
K12_DBG(1,("k12_open: ENTER debug_level=%u",debug_level));
#endif
if ( !wtap_read_bytes(wth->fh,header_buffer,K12_FILE_HDR_LEN,err,err_info) ) {
K12_DBG(1,("k12_open: FILE HEADER TOO SHORT OR READ ERROR"));
if (*err != WTAP_ERR_SHORT_READ) {
return WTAP_OPEN_ERROR;
}
return WTAP_OPEN_NOT_MINE;
}
if ( memcmp(header_buffer,k12_file_magic,8) != 0 ) {
K12_DBG(1,("k12_open: BAD MAGIC"));
return WTAP_OPEN_NOT_MINE;
}
offset = K12_FILE_HDR_LEN;
file_data = new_k12_file_data();
file_data->file_len = pntoh32( header_buffer + 0x8);
if (memiszero(header_buffer + 0x10, K12_FILE_HDR_LEN - 0x10)) {
file_data->num_of_records = pntoh32( header_buffer + 0x0C );
} else {
file_data->num_of_records = pntoh32( header_buffer + K12_FILE_HDR_RECORD_COUNT_1 );
if ( file_data->num_of_records != pntoh32( header_buffer + K12_FILE_HDR_RECORD_COUNT_2 ) ) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("k12: two different record counts, %u at 0x%02x and %u at 0x%02x",
file_data->num_of_records,
K12_FILE_HDR_RECORD_COUNT_1,
pntoh32( header_buffer + K12_FILE_HDR_RECORD_COUNT_2 ),
K12_FILE_HDR_RECORD_COUNT_2 );
return WTAP_OPEN_ERROR;
}
}
K12_DBG(5,("k12_open: FILE_HEADER OK: offset=%x file_len=%i records=%i",
offset,
file_data->file_len,
file_data->num_of_records ));
do {
if ( file_data->num_of_records == 0 ) {
*err = WTAP_ERR_SHORT_READ;
destroy_k12_file_data(file_data);
return WTAP_OPEN_ERROR;
}
len = get_record(file_data, wth->fh, offset, FALSE, err, err_info);
if ( len < 0 ) {
K12_DBG(1,("k12_open: BAD HEADER RECORD",len));
destroy_k12_file_data(file_data);
return WTAP_OPEN_ERROR;
}
if ( len == 0 ) {
K12_DBG(1,("k12_open: BAD HEADER RECORD",len));
*err = WTAP_ERR_SHORT_READ;
destroy_k12_file_data(file_data);
return WTAP_OPEN_ERROR;
}
read_buffer = file_data->seq_read_buff;
rec_len = pntoh32( read_buffer + K12_RECORD_LEN );
if (rec_len < K12_RECORD_TYPE + 4) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("k12_open: record length %u < %u",
rec_len, K12_RECORD_TYPE + 4);
return WTAP_OPEN_ERROR;
}
type = pntoh32( read_buffer + K12_RECORD_TYPE );
if ( (type & K12_MASK_PACKET) == K12_REC_PACKET ||
(type & K12_MASK_PACKET) == K12_REC_D0020) {
if (file_seek(wth->fh, offset, SEEK_SET, err) == -1) {
destroy_k12_file_data(file_data);
return WTAP_OPEN_ERROR;
}
K12_DBG(5,("k12_open: FIRST PACKET offset=%x",offset));
break;
}
switch (type) {
case K12_REC_SRCDSC:
case K12_REC_SRCDSC2:
rec = g_new0(k12_src_desc_t,1);
if (rec_len < K12_SRCDESC_HWPART) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("k12_open: source descriptor record length %u < %u",
rec_len, K12_SRCDESC_HWPART);
destroy_k12_file_data(file_data);
g_free(rec);
return WTAP_OPEN_ERROR;
}
port_type = read_buffer[K12_SRCDESC_PORT_TYPE];
hwpart_len = pntoh16( read_buffer + K12_SRCDESC_HWPARTLEN );
name_len = pntoh16( read_buffer + K12_SRCDESC_NAMELEN );
stack_len = pntoh16( read_buffer + K12_SRCDESC_STACKLEN );
rec->input = pntoh32( read_buffer + K12_RECORD_SRC_ID );
K12_DBG(5,("k12_open: INTERFACE RECORD offset=%x interface=%x",offset,rec->input));
if (name_len == 0) {
K12_DBG(5,("k12_open: failed (name_len == 0 in source description"));
destroy_k12_file_data(file_data);
g_free(rec);
return WTAP_OPEN_NOT_MINE;
}
if (stack_len == 0) {
K12_DBG(5,("k12_open: failed (stack_len == 0 in source description"));
destroy_k12_file_data(file_data);
g_free(rec);
return WTAP_OPEN_NOT_MINE;
}
if (rec_len < K12_SRCDESC_HWPART + hwpart_len + name_len + stack_len) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("k12_open: source descriptor record length %u < %u (%u + %u + %u + %u)",
rec_len,
K12_SRCDESC_HWPART + hwpart_len + name_len + stack_len,
K12_SRCDESC_HWPART, hwpart_len, name_len, stack_len);
destroy_k12_file_data(file_data);
g_free(rec);
return WTAP_OPEN_ERROR;
}
if (hwpart_len) {
if (hwpart_len < 4) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("k12_open: source descriptor hardware part length %u < 4",
hwpart_len);
destroy_k12_file_data(file_data);
g_free(rec);
return WTAP_OPEN_ERROR;
}
switch(( rec->input_type = pntoh32( read_buffer + K12_SRCDESC_HWPART + K12_SRCDESC_HWPARTTYPE ) )) {
case K12_PORT_DS0S:
rec->input_info.ds0mask = 0x00000000;
if (hwpart_len > K12_SRCDESC_DS0_MASK) {
for (i = 0; i < hwpart_len - K12_SRCDESC_DS0_MASK; i++) {
rec->input_info.ds0mask |= ( *(read_buffer + K12_SRCDESC_HWPART + K12_SRCDESC_DS0_MASK + i) == 0xff ) ? 1U<<(31-i) : 0x0;
}
}
break;
case K12_PORT_ATMPVC:
if (hwpart_len < K12_SRCDESC_ATM_VCI + 2) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("k12_open: source descriptor hardware part length %u < %u",
hwpart_len,
K12_SRCDESC_ATM_VCI + 2);
destroy_k12_file_data(file_data);
g_free(rec);
return WTAP_OPEN_ERROR;
}
rec->input_info.atm.vp = pntoh16( read_buffer + K12_SRCDESC_HWPART + K12_SRCDESC_ATM_VPI );
rec->input_info.atm.vc = pntoh16( read_buffer + K12_SRCDESC_HWPART + K12_SRCDESC_ATM_VCI );
break;
default:
break;
}
} else {
if (port_type >= 0x14
&& port_type <= 0x17) {
rec->input_type = K12_PORT_ATMPVC;
rec->input_info.atm.vp = 0;
rec->input_info.atm.vc = 0;
}
}
if (read_buffer[K12_SRCDESC_HWPART + hwpart_len + name_len - 1] != '\0') {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("k12_open: source descriptor record contains non-null-terminated link-layer name");
destroy_k12_file_data(file_data);
g_free(rec);
return WTAP_OPEN_ERROR;
}
if (read_buffer[K12_SRCDESC_HWPART + hwpart_len + name_len + stack_len - 1] != '\0') {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("k12_open: source descriptor record contains non-null-terminated stack path");
destroy_k12_file_data(file_data);
g_free(rec);
return WTAP_OPEN_ERROR;
}
rec->input_name = (gchar *)g_memdup(read_buffer + K12_SRCDESC_HWPART + hwpart_len, name_len);
rec->stack_file = (gchar *)g_memdup(read_buffer + K12_SRCDESC_HWPART + hwpart_len + name_len, stack_len);
ascii_strdown_inplace (rec->stack_file);
g_hash_table_insert(file_data->src_by_id,GUINT_TO_POINTER(rec->input),rec);
g_hash_table_insert(file_data->src_by_name,rec->stack_file,rec);
break;
case K12_REC_STK_FILE:
K12_DBG(1,("k12_open: K12_REC_STK_FILE"));
K12_DBG(1,("Field 1: 0x%08x",pntoh32( read_buffer + 0x08 )));
K12_DBG(1,("Field 2: 0x%08x",pntoh32( read_buffer + 0x0c )));
K12_ASCII_DUMP(1, read_buffer, rec_len, 16);
break;
default:
K12_DBG(1,("k12_open: RECORD TYPE 0x%08x",type));
break;
}
offset += len;
file_data->num_of_records--;
} while(1);
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_K12;
wth->file_encap = WTAP_ENCAP_K12;
wth->snapshot_length = 0;
wth->subtype_read = k12_read;
wth->subtype_seek_read = k12_seek_read;
wth->subtype_close = k12_close;
wth->priv = (void *)file_data;
wth->file_tsprec = WTAP_TSPREC_NSEC;
return WTAP_OPEN_MINE;
}
int k12_dump_can_write_encap(int encap) {
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (encap != WTAP_ENCAP_K12)
return WTAP_ERR_UNWRITABLE_ENCAP;
return 0;
}
static gboolean k12_dump_record(wtap_dumper *wdh, guint32 len, guint8* buffer, int *err_p) {
k12_dump_t *k12 = (k12_dump_t *)wdh->priv;
guint32 junky_offset = (8192 - ( (k12->file_offset - K12_FILE_HDR_LEN) % 8192 )) % 8192;
if (len > junky_offset) {
if (junky_offset) {
if (! wtap_dump_file_write(wdh, buffer, junky_offset, err_p))
return FALSE;
}
if (! wtap_dump_file_write(wdh, dumpy_junk, K12_FILE_BLOB_LEN, err_p))
return FALSE;
if (! wtap_dump_file_write(wdh, buffer+junky_offset, len - junky_offset, err_p))
return FALSE;
k12->file_offset += len + K12_FILE_BLOB_LEN;
k12->file_len += len + K12_FILE_BLOB_LEN;
} else {
if (! wtap_dump_file_write(wdh, buffer, len, err_p))
return FALSE;
k12->file_offset += len;
k12->file_len += len;
}
k12->num_of_records++;
return TRUE;
}
static void k12_dump_src_setting(gpointer k _U_, gpointer v, gpointer p) {
k12_src_desc_t* src_desc = (k12_src_desc_t*)v;
wtap_dumper *wdh = (wtap_dumper *)p;
guint32 len;
guint offset;
guint i;
int errxxx;
union {
guint8 buffer[8192];
struct {
guint32 len;
guint32 type;
guint32 unk32_1;
guint32 input;
guint16 unk32_2;
guint16 color;
guint32 unk32_3;
guint32 unk32_4;
guint16 unk16_1;
guint16 hwpart_len;
guint16 name_len;
guint16 stack_len;
struct {
guint32 type;
union {
struct {
guint32 unk32;
guint8 mask[32];
} ds0mask;
struct {
guint8 unk_data[16];
guint16 vp;
guint16 vc;
} atm;
guint32 unk;
} desc;
} extra;
} record;
} obj;
obj.record.type = g_htonl(K12_REC_SRCDSC);
obj.record.unk32_1 = g_htonl(0x00000001);
obj.record.input = g_htonl(src_desc->input);
obj.record.unk32_2 = g_htons(0x0000);
obj.record.color = g_htons(0x060f);
obj.record.unk32_3 = g_htonl(0x00000003);
switch (src_desc->input_type) {
case K12_PORT_ATMPVC:
obj.record.unk32_4 = g_htonl(0x01001400);
break;
default:
obj.record.unk32_4 = g_htonl(0x01000100);
}
obj.record.unk16_1 = g_htons(0x0000);
obj.record.name_len = (guint16) strlen(src_desc->input_name) + 1;
obj.record.stack_len = (guint16) strlen(src_desc->stack_file) + 1;
obj.record.extra.type = g_htonl(src_desc->input_type);
switch (src_desc->input_type) {
case K12_PORT_ATMPVC:
obj.record.hwpart_len = g_htons(0x18);
obj.record.extra.desc.atm.vp = g_htons(src_desc->input_info.atm.vp);
obj.record.extra.desc.atm.vc = g_htons(src_desc->input_info.atm.vc);
offset = 0x3c;
break;
case K12_PORT_DS0S:
obj.record.hwpart_len = g_htons(0x18);
for( i=0; i<32; i++ ) {
obj.record.extra.desc.ds0mask.mask[i] =
(src_desc->input_info.ds0mask & (1 << i)) ? 0xff : 0x00;
}
offset = 0x3c;
break;
default:
obj.record.hwpart_len = g_htons(0x08);
offset = 0x2c;
break;
}
memcpy(obj.buffer + offset,
src_desc->input_name,
obj.record.name_len);
memcpy(obj.buffer + offset + obj.record.name_len,
src_desc->stack_file,
obj.record.stack_len);
len = offset + obj.record.name_len + obj.record.stack_len;
len += (len % 4) ? 4 - (len % 4) : 0;
obj.record.len = g_htonl(len);
obj.record.name_len = g_htons(obj.record.name_len);
obj.record.stack_len = g_htons(obj.record.stack_len);
k12_dump_record(wdh,len,obj.buffer, &errxxx);
}
static gboolean k12_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err, gchar **err_info _U_) {
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
k12_dump_t *k12 = (k12_dump_t *)wdh->priv;
guint32 len;
union {
guint8 buffer[8192];
struct {
guint32 len;
guint32 type;
guint32 frame_len;
guint32 input;
guint32 datum_1;
guint32 datum_2;
guint64 ts;
guint8 frame[0x1fc0];
} record;
} obj;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
if (k12->num_of_records == 0) {
k12_t* file_data = (k12_t*)pseudo_header->k12.stuff;
g_hash_table_foreach(file_data->src_by_id,k12_dump_src_setting,wdh);
}
obj.record.len = 0x20 + phdr->caplen;
obj.record.len += (obj.record.len % 4) ? 4 - obj.record.len % 4 : 0;
len = obj.record.len;
obj.record.len = g_htonl(obj.record.len);
obj.record.type = g_htonl(K12_REC_PACKET);
obj.record.frame_len = g_htonl(phdr->caplen);
obj.record.input = g_htonl(pseudo_header->k12.input);
obj.record.ts = GUINT64_TO_BE((((guint64)phdr->ts.secs - 631152000) * 2000000) + (phdr->ts.nsecs / 1000 * 2));
memcpy(obj.record.frame,pd,phdr->caplen);
return k12_dump_record(wdh,len,obj.buffer, err);
}
static gboolean k12_dump_finish(wtap_dumper *wdh, int *err) {
k12_dump_t *k12 = (k12_dump_t *)wdh->priv;
union {
guint8 b[sizeof(guint32)];
guint32 u;
} d;
if (! wtap_dump_file_write(wdh, k12_eof, 2, err))
return FALSE;
k12->file_len += 2;
if (wtap_dump_file_seek(wdh, K12_FILE_HDR_FILE_SIZE, SEEK_SET, err) == -1)
return FALSE;
d.u = g_htonl(k12->file_len);
if (! wtap_dump_file_write(wdh, d.b, 4, err))
return FALSE;
if (wtap_dump_file_seek(wdh, K12_FILE_HDR_PAGE_SIZE, SEEK_SET, err) == -1)
return FALSE;
d.u = g_htonl(8192);
if (! wtap_dump_file_write(wdh, d.b, 4, err))
return FALSE;
if (wtap_dump_file_seek(wdh, K12_FILE_HDR_RECORD_COUNT_1, SEEK_SET, err) == -1)
return FALSE;
d.u = g_htonl(k12->num_of_records);
if (! wtap_dump_file_write(wdh, d.b, 4, err))
return FALSE;
if (wtap_dump_file_seek(wdh, K12_FILE_HDR_RECORD_COUNT_2, SEEK_SET, err) == -1)
return FALSE;
d.u = g_htonl(k12->num_of_records);
if (! wtap_dump_file_write(wdh, d.b, 4, err))
return FALSE;
return TRUE;
}
gboolean k12_dump_open(wtap_dumper *wdh, int *err) {
k12_dump_t *k12;
if ( ! wtap_dump_file_write(wdh, k12_file_magic, 8, err)) {
return FALSE;
}
if (wtap_dump_file_seek(wdh, K12_FILE_HDR_LEN, SEEK_SET, err) == -1)
return FALSE;
wdh->subtype_write = k12_dump;
wdh->subtype_finish = k12_dump_finish;
k12 = (k12_dump_t *)g_malloc(sizeof(k12_dump_t));
wdh->priv = (void *)k12;
k12->file_len = K12_FILE_HDR_LEN;
k12->num_of_records = 0;
k12->file_offset = K12_FILE_HDR_LEN;
return TRUE;
}
