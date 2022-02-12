void k12_fprintf(char* fmt, ...) {
va_list ap;
va_start(ap,fmt);
vfprintf(dbg_out, fmt, ap);
va_end(ap);
}
void k12_hexdump(guint level, gint64 offset, char* label, unsigned char* b, unsigned int len) {
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
unsigned int i;
if (debug_level < level) return;
fprintf(dbg_out,"%s(%.8" G_GINT64_MODIFIER "x,%.4x): ",label,offset,len);
for (i=0 ; i<len ; i++) {
if (!(i%32))
fprintf(dbg_out,"\n");
else if (!(i%4))
fprintf(dbg_out," ");
fprintf(dbg_out, "%s", c2t[b[i]]);
}
fprintf(dbg_out,"\n");
}
static gint get_record(guint8** bufferp, FILE_T fh, gint64 file_offset,
int *err, gchar **err_info) {
static guint8* buffer = NULL;
static guint buffer_len = 0x2000 ;
guint bytes_read;
guint last_read;
guint left;
guint8 junk[0x14];
guint8* writep;
#ifdef DEBUG_K12
guint actual_len;
#endif
guint junky_offset = 0x2000 - (gint) ( (file_offset - 0x200) % 0x2000 );
K12_DBG(6,("get_record: ENTER: junky_offset=%" G_GINT64_MODIFIER "d, file_offset=%" G_GINT64_MODIFIER "d",junky_offset,file_offset));
if (buffer == NULL) {
buffer = (guint8*)g_malloc(0x2000);
buffer_len = 0x2000;
}
*bufferp = buffer;
if ( junky_offset == 0x2000 ) {
bytes_read = file_read(junk,0x14,fh);
if (bytes_read == 2 && junk[0] == 0xff && junk[1] == 0xff) {
K12_DBG(1,("get_record: EOF"));
return 0;
} else if ( bytes_read < 0x14 ){
K12_DBG(1,("get_record: SHORT READ OR ERROR"));
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
memcpy(buffer,&(junk[0x10]),4);
} else {
bytes_read = file_read(buffer, 0x4, fh);
if (bytes_read == 2 && buffer[0] == 0xff && buffer[1] == 0xff) {
K12_DBG(1,("get_record: EOF"));
return 0;
} else if ( bytes_read != 0x4 ) {
K12_DBG(1,("get_record: SHORT READ OR ERROR"));
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
}
left = pntohl(buffer);
#ifdef DEBUG_K12
actual_len = left;
#endif
junky_offset -= 0x4;
K12_DBG(5,("get_record: GET length=%u",left));
if (left < 4 || left > WTAP_MAX_PACKET_SIZE) {
K12_DBG(1,("get_record: Invalid GET length=%u",left));
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("get_record: Invalid GET length=%u",left);
return -1;
}
while (left > buffer_len) *bufferp = buffer = (guint8*)g_realloc(buffer,buffer_len*=2);
writep = buffer + 4;
left -= 4;
do {
K12_DBG(6,("get_record: looping left=%d junky_offset=%" G_GINT64_MODIFIER "d",left,junky_offset));
if (junky_offset > left) {
bytes_read += last_read = file_read(writep, left, fh);
if ( last_read != left ) {
K12_DBG(1,("get_record: SHORT READ OR ERROR"));
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return -1;
} else {
K12_HEXDMP(5,file_offset, "GOT record", buffer, actual_len);
return bytes_read;
}
} else {
bytes_read += last_read = file_read(writep, junky_offset, fh);
if ( last_read != junky_offset ) {
K12_DBG(1,("get_record: SHORT READ OR ERROR, read=%d expected=%d",last_read, junky_offset));
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
writep += last_read;
bytes_read += last_read = file_read(junk, 0x10, fh);
if ( last_read != 0x10 ) {
K12_DBG(1,("get_record: SHORT READ OR ERROR"));
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
left -= junky_offset;
junky_offset = 0x2000;
}
} while(left);
K12_HEXDMP(5,file_offset, "GOT record", buffer, actual_len);
return bytes_read;
}
static gboolean k12_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset) {
k12_t *k12 = (k12_t *)wth->priv;
k12_src_desc_t* src_desc;
guint8* buffer = NULL;
gint64 offset;
gint len;
guint32 type;
guint32 src_id;
guint64 ts;
guint32 extra_len;
offset = file_tell(wth->fh);
do {
K12_DBG(5,("k12_read: offset=%i",offset));
*data_offset = offset;
len = get_record(&buffer, wth->fh, offset, err, err_info);
if (len < 0) {
return FALSE;
} else if (len == 0) {
*err = 0;
return FALSE;
}
type = pntohl(buffer + K12_RECORD_TYPE);
src_id = pntohl(buffer + K12_RECORD_SRC_ID);
if ( ! (src_desc = (k12_src_desc_t*)g_hash_table_lookup(k12->src_by_id,GUINT_TO_POINTER(src_id))) ) {
src_desc = (k12_src_desc_t*)g_hash_table_lookup(k12->src_by_id,GUINT_TO_POINTER(src_id&K12_RECORD_SRC_ID_MASK));
}
K12_DBG(5,("k12_read: record type=%x src_id=%x",type,src_id));
offset += len;
} while ( ((type & K12_MASK_PACKET) != K12_REC_PACKET) || !src_id || !src_desc );
wth->phdr.presence_flags = WTAP_HAS_TS;
ts = pntohll(buffer + K12_PACKET_TIMESTAMP);
wth->phdr.ts.secs = (guint32) ((ts / 2000000) + 631152000);
wth->phdr.ts.nsecs = (guint32) ( (ts % 2000000) * 500 );
K12_DBG(3,("k12_read: PACKET RECORD type=%x src_id=%x secs=%u nsecs=%u",type,src_id, wth->phdr.ts.secs,wth->phdr.ts.nsecs));
wth->phdr.len = wth->phdr.caplen = pntohl(buffer + K12_RECORD_FRAME_LEN) & 0x00001FFF;
extra_len = len - K12_PACKET_FRAME - wth->phdr.caplen;
buffer_assure_space(wth->frame_buffer, wth->phdr.caplen);
memcpy(buffer_start_ptr(wth->frame_buffer), buffer + K12_PACKET_FRAME, wth->phdr.caplen);
buffer_assure_space(&(k12->extra_info), extra_len);
memcpy(buffer_start_ptr(&(k12->extra_info)),
buffer + K12_PACKET_FRAME + wth->phdr.caplen, extra_len);
wth->phdr.pseudo_header.k12.extra_info = (guint8*)buffer_start_ptr(&(k12->extra_info));
wth->phdr.pseudo_header.k12.extra_length = extra_len;
wth->phdr.pseudo_header.k12.input = src_id;
K12_DBG(5,("k12_read: wth->pseudo_header.k12.input=%x wth->phdr.len=%i input_name='%s' stack_file='%s' type=%x",
wth->pseudo_header.k12.input,wth->phdr.len,src_desc->input_name,src_desc->stack_file,src_desc->input_type));\
wth->phdr.pseudo_header.k12.input_name = src_desc->input_name;
wth->phdr.pseudo_header.k12.stack_file = src_desc->stack_file;
wth->phdr.pseudo_header.k12.input_type = src_desc->input_type;
switch(src_desc->input_type) {
case K12_PORT_ATMPVC:
if ((long)(K12_PACKET_FRAME + wth->phdr.len + K12_PACKET_OFFSET_CID) < len) {
wth->phdr.pseudo_header.k12.input_info.atm.vp = pntohs(buffer + (K12_PACKET_FRAME + wth->phdr.caplen + K12_PACKET_OFFSET_VP));
wth->phdr.pseudo_header.k12.input_info.atm.vc = pntohs(buffer + (K12_PACKET_FRAME + wth->phdr.caplen + K12_PACKET_OFFSET_VC));
wth->phdr.pseudo_header.k12.input_info.atm.cid = *((unsigned char*)(buffer + K12_PACKET_FRAME + wth->phdr.len + K12_PACKET_OFFSET_CID));
break;
}
default:
memcpy(&(wth->phdr.pseudo_header.k12.input_info),&(src_desc->input_info),sizeof(src_desc->input_info));
break;
}
wth->phdr.pseudo_header.k12.stuff = k12;
return TRUE;
}
static gboolean k12_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr, guint8 *pd, int length, int *err _U_, gchar **err_info) {
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
k12_t *k12 = (k12_t *)wth->priv;
k12_src_desc_t* src_desc;
guint8* buffer;
gint len;
guint32 extra_len;
guint32 input;
K12_DBG(5,("k12_seek_read: ENTER"));
if ( file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1) {
K12_DBG(5,("k12_seek_read: SEEK ERROR"));
return FALSE;
}
len = get_record(&buffer, wth->random_fh, seek_off, err, err_info);
if (len < 0) {
K12_DBG(5,("k12_seek_read: READ ERROR"));
return FALSE;
}
if (len < 1) {
K12_DBG(5,("k12_seek_read: SHORT READ"));
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
memcpy(pd, buffer + K12_PACKET_FRAME, length);
extra_len = len - K12_PACKET_FRAME - length;
buffer_assure_space(&(k12->extra_info), extra_len);
memcpy(buffer_start_ptr(&(k12->extra_info)),
buffer + K12_PACKET_FRAME + length, extra_len);
wth->phdr.pseudo_header.k12.extra_info = (guint8*)buffer_start_ptr(&(k12->extra_info));
wth->phdr.pseudo_header.k12.extra_length = extra_len;
if (pseudo_header) {
pseudo_header->k12.extra_info = (guint8*)buffer_start_ptr(&(k12->extra_info));
pseudo_header->k12.extra_length = extra_len;
}
input = pntohl(buffer + K12_RECORD_SRC_ID);
K12_DBG(5,("k12_seek_read: input=%.8x",input));
if ( ! (src_desc = (k12_src_desc_t*)g_hash_table_lookup(k12->src_by_id,GUINT_TO_POINTER(input))) ) {
src_desc = (k12_src_desc_t*)g_hash_table_lookup(k12->src_by_id,GUINT_TO_POINTER(input&K12_RECORD_SRC_ID_MASK));
}
if (src_desc) {
K12_DBG(5,("k12_seek_read: input_name='%s' stack_file='%s' type=%x",src_desc->input_name,src_desc->stack_file,src_desc->input_type));
if (pseudo_header) {
pseudo_header->k12.input_name = src_desc->input_name;
pseudo_header->k12.stack_file = src_desc->stack_file;
pseudo_header->k12.input_type = src_desc->input_type;
switch(src_desc->input_type) {
case K12_PORT_ATMPVC:
if ((long)(K12_PACKET_FRAME + length + K12_PACKET_OFFSET_CID) < len) {
pseudo_header->k12.input_info.atm.vp = pntohs(buffer + K12_PACKET_FRAME + length + K12_PACKET_OFFSET_VP);
pseudo_header->k12.input_info.atm.vc = pntohs(buffer + K12_PACKET_FRAME + length + K12_PACKET_OFFSET_VC);
pseudo_header->k12.input_info.atm.cid = *((unsigned char*)(buffer + K12_PACKET_FRAME + length + K12_PACKET_OFFSET_CID));
break;
}
default:
memcpy(&(pseudo_header->k12.input_info),&(src_desc->input_info),sizeof(src_desc->input_info));
break;
}
}
wth->phdr.pseudo_header.k12.input_name = src_desc->input_name;
wth->phdr.pseudo_header.k12.stack_file = src_desc->stack_file;
wth->phdr.pseudo_header.k12.input_type = src_desc->input_type;
switch(src_desc->input_type) {
case K12_PORT_ATMPVC:
if ((long)(K12_PACKET_FRAME + length + K12_PACKET_OFFSET_CID) < len) {
wth->phdr.pseudo_header.k12.input_info.atm.vp = pntohs(buffer + K12_PACKET_FRAME + length + K12_PACKET_OFFSET_VP);
wth->phdr.pseudo_header.k12.input_info.atm.vc = pntohs(buffer + K12_PACKET_FRAME + length + K12_PACKET_OFFSET_VC);
wth->phdr.pseudo_header.k12.input_info.atm.cid = *((unsigned char*)(buffer + K12_PACKET_FRAME + length + K12_PACKET_OFFSET_CID));
}
break;
default:
memcpy(&(wth->phdr.pseudo_header.k12.input_info),&(src_desc->input_info),sizeof(src_desc->input_info));
break;
}
} else {
K12_DBG(5,("k12_seek_read: NO SRC_RECORD FOUND"));
if (pseudo_header) {
memset(&(pseudo_header->k12),0,sizeof(pseudo_header->k12));
pseudo_header->k12.input_name = "unknown port";
pseudo_header->k12.stack_file = "unknown stack file";
}
memset(&(wth->phdr.pseudo_header.k12),0,sizeof(wth->phdr.pseudo_header.k12));
wth->phdr.pseudo_header.k12.input_name = "unknown port";
wth->phdr.pseudo_header.k12.stack_file = "unknown stack file";
}
if (pseudo_header) {
pseudo_header->k12.input = input;
pseudo_header->k12.stuff = k12;
}
wth->phdr.pseudo_header.k12.input = input;
wth->phdr.pseudo_header.k12.stuff = k12;
K12_DBG(5,("k12_seek_read: DONE OK"));
return TRUE;
}
static k12_t* new_k12_file_data(void) {
k12_t* fd = g_new(k12_t,1);
fd->file_len = 0;
fd->num_of_records = 0;
fd->src_by_name = g_hash_table_new(g_str_hash,g_str_equal);
fd->src_by_id = g_hash_table_new(g_direct_hash,g_direct_equal);
buffer_init(&(fd->extra_info), 100);
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
buffer_free(&(fd->extra_info));
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
int k12_dump_can_write_encap(int encap) {
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (encap != WTAP_ENCAP_K12)
return WTAP_ERR_UNSUPPORTED_ENCAP;
return 0;
}
static gboolean k12_dump_record(wtap_dumper *wdh, guint32 len, guint8* buffer, int *err_p) {
k12_dump_t *k12 = (k12_dump_t *)wdh->priv;
guint32 junky_offset = (0x2000 - ( (k12->file_offset - 0x200) % 0x2000 )) % 0x2000;
if (len > junky_offset) {
if (junky_offset) {
if (! wtap_dump_file_write(wdh, buffer, junky_offset, err_p))
return FALSE;
}
if (! wtap_dump_file_write(wdh, dumpy_junk, 0x10, err_p))
return FALSE;
if (! wtap_dump_file_write(wdh, buffer+junky_offset, len - junky_offset, err_p))
return FALSE;
k12->file_offset += len + 0x10;
} else {
if (! wtap_dump_file_write(wdh, buffer, len, err_p))
return FALSE;
k12->file_offset += len;
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
guint8 buffer[0x2000];
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
guint16 extra_len;
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
guint8 unk_data[0x10];
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
obj.record.extra_len = g_htons(0x18);
obj.record.extra.desc.atm.vp = g_htons(src_desc->input_info.atm.vp);
obj.record.extra.desc.atm.vc = g_htons(src_desc->input_info.atm.vc);
offset = 0x3c;
break;
case K12_PORT_DS0S:
obj.record.extra_len = g_htons(0x18);
for( i=0; i<32; i++ ) {
obj.record.extra.desc.ds0mask.mask[i] =
(src_desc->input_info.ds0mask & (1 << i)) ? 0xff : 0x00;
}
offset = 0x3c;
break;
default:
obj.record.extra_len = g_htons(0x08);
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
const guint8 *pd, int *err) {
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
k12_dump_t *k12 = (k12_dump_t *)wdh->priv;
guint32 len;
union {
guint8 buffer[0x2000];
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
if (k12->num_of_records == 0) {
k12_t* file_data = (k12_t*)pseudo_header->k12.stuff;
g_hash_table_foreach(file_data->src_by_id,k12_dump_src_setting,wdh);
}
obj.record.len = 0x20 + phdr->len;
obj.record.len += (obj.record.len % 4) ? 4 - obj.record.len % 4 : 0;
len = obj.record.len;
obj.record.len = g_htonl(obj.record.len);
obj.record.type = g_htonl(K12_REC_PACKET);
obj.record.frame_len = g_htonl(phdr->len);
obj.record.input = g_htonl(pseudo_header->k12.input);
obj.record.ts = GUINT64_TO_BE((((guint64)phdr->ts.secs - 631152000) * 2000000) + (phdr->ts.nsecs / 1000 * 2));
memcpy(obj.record.frame,pd,phdr->len);
return k12_dump_record(wdh,len,obj.buffer, err);
}
static gboolean k12_dump_close(wtap_dumper *wdh, int *err) {
k12_dump_t *k12 = (k12_dump_t *)wdh->priv;
union {
guint8 b[sizeof(guint32)];
guint32 u;
} d;
if (! wtap_dump_file_write(wdh, k12_eof, 2, err))
return FALSE;
if (wtap_dump_file_seek(wdh, 8, SEEK_SET, err) == -1)
return FALSE;
d.u = g_htonl(k12->file_len);
if (! wtap_dump_file_write(wdh, d.b, 4, err))
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
if (wtap_dump_file_seek(wdh, 0x200, SEEK_SET, err) == -1)
return FALSE;
wdh->subtype_write = k12_dump;
wdh->subtype_close = k12_dump_close;
k12 = (k12_dump_t *)g_malloc(sizeof(k12_dump_t));
wdh->priv = (void *)k12;
k12->file_len = 0x200;
k12->num_of_records = 0;
k12->file_offset = 0x200;
return TRUE;
}
