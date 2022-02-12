static void
insert_chunk(active_file *file, export_object_entry_t *entry, const smb_eo_t *eo_info)
{
gint nfreechunks = g_slist_length(file->free_chunk_list);
gint i;
free_chunk *current_free_chunk;
free_chunk *new_free_chunk;
guint64 chunk_offset = eo_info->smb_file_offset;
guint64 chunk_length = eo_info->payload_len;
guint64 chunk_end_offset = chunk_offset + chunk_length-1;
guint64 calculated_size = chunk_offset + chunk_length;
gpointer dest_memory_addr;
if ((file->data_gathered == 0) && (nfreechunks == 0)) {
new_free_chunk = (free_chunk *)g_malloc(sizeof(free_chunk));
new_free_chunk->start_offset = 0;
new_free_chunk->end_offset = MAX(file->file_length, chunk_end_offset+1) - 1;
file->free_chunk_list = NULL;
file->free_chunk_list = g_slist_append(file->free_chunk_list, new_free_chunk);
nfreechunks += 1;
} else {
if (chunk_end_offset > file->file_length-1) {
new_free_chunk = (free_chunk *)g_malloc(sizeof(free_chunk));
new_free_chunk->start_offset = file->file_length;
new_free_chunk->end_offset = chunk_end_offset;
file->free_chunk_list = g_slist_append(file->free_chunk_list, new_free_chunk);
nfreechunks += 1;
}
}
file->file_length = MAX(file->file_length, chunk_end_offset+1);
for (i=0; i<nfreechunks; i++) {
current_free_chunk = (free_chunk *)g_slist_nth_data(file->free_chunk_list, i);
if (chunk_end_offset<current_free_chunk->start_offset) {
continue;
}
if (chunk_offset<=current_free_chunk->start_offset && chunk_end_offset>=current_free_chunk->start_offset && chunk_end_offset<current_free_chunk->end_offset) {
file->data_gathered += chunk_end_offset-current_free_chunk->start_offset+1;
current_free_chunk->start_offset=chunk_end_offset+1;
continue;
}
if (chunk_offset<=current_free_chunk->start_offset && chunk_end_offset>=current_free_chunk->end_offset) {
file->data_gathered += current_free_chunk->end_offset-current_free_chunk->start_offset+1;
file->free_chunk_list = g_slist_remove(file->free_chunk_list, current_free_chunk);
nfreechunks -= 1;
if (nfreechunks == 0) {
g_slist_free(file->free_chunk_list);
file->free_chunk_list = NULL;
break;
}
i--;
continue;
}
if (chunk_offset>current_free_chunk->start_offset && chunk_end_offset<current_free_chunk->end_offset) {
new_free_chunk = (free_chunk *)g_malloc(sizeof(free_chunk));
new_free_chunk->start_offset = chunk_end_offset + 1;
new_free_chunk->end_offset = current_free_chunk->end_offset;
current_free_chunk->end_offset = chunk_offset-1;
file->free_chunk_list = g_slist_insert(file->free_chunk_list, new_free_chunk, i + 1);
file->data_gathered += chunk_length;
continue;
}
if (chunk_offset>current_free_chunk->start_offset && chunk_offset<=current_free_chunk->end_offset && chunk_end_offset>=current_free_chunk->end_offset) {
file->data_gathered += current_free_chunk->end_offset-chunk_offset+1;
current_free_chunk->end_offset = chunk_offset-1;
continue;
}
if (chunk_offset>current_free_chunk->end_offset) {
continue;
}
}
if (!entry->payload_data) {
if (calculated_size > G_MAXSIZE) {
entry->payload_data = NULL;
} else {
entry->payload_data = (guint8 *)g_try_malloc((gsize)calculated_size);
entry->payload_len = calculated_size;
}
if (!entry->payload_data) {
file->is_out_of_memory = TRUE;
}
} else {
if (calculated_size > (guint64) entry->payload_len &&
!file->is_out_of_memory) {
if (calculated_size > G_MAXSIZE) {
dest_memory_addr = NULL;
} else {
dest_memory_addr = g_try_realloc(
entry->payload_data,
(gsize)calculated_size);
}
if (!dest_memory_addr) {
file->is_out_of_memory = TRUE;
g_free(entry->payload_data);
entry->payload_data = NULL;
entry->payload_len = 0;
} else {
entry->payload_data = (guint8 *)dest_memory_addr;
entry->payload_len = calculated_size;
}
}
}
if (!file->is_out_of_memory) {
dest_memory_addr = entry->payload_data + chunk_offset;
g_memmove(dest_memory_addr, eo_info->payload_data, eo_info->payload_len);
}
}
static int
find_incoming_file(GSList *GSL_active_files_p, active_file *incoming_file)
{
int i, row, last;
active_file *in_list_file;
row = -1;
last = g_slist_length(GSL_active_files_p) - 1;
for (i=last; i>=0; i--) {
in_list_file = (active_file *)g_slist_nth_data(GSL_active_files_p, i);
if (in_list_file->tid == incoming_file->tid &&
in_list_file->fid == incoming_file->fid) {
row = i;
break;
}
}
return row;
}
gboolean
eo_smb_packet(void *tapdata, packet_info *pinfo, epan_dissect_t *edt _U_, const void *data)
{
export_object_list_t *object_list = (export_object_list_t *)tapdata;
const smb_eo_t *eo_info = (const smb_eo_t *)data;
export_object_entry_t *entry;
export_object_entry_t *current_entry;
active_file incoming_file;
gint active_row;
active_file *new_file;
active_file *current_file;
guint8 contains;
gboolean is_supported_filetype;
gfloat percent;
gchar *aux_smb_fid_type_string;
if (eo_info->smbversion==1) {
is_supported_filetype = (eo_info->fid_type == SMB_FID_TYPE_FILE);
aux_smb_fid_type_string=g_strdup(try_val_to_str(eo_info->fid_type, smb_fid_types));
switch(eo_info->cmd) {
case SMB_COM_READ_ANDX:
case SMB_COM_READ:
contains = SMB_EO_CONTAINS_READS;
break;
case SMB_COM_WRITE_ANDX:
case SMB_COM_WRITE:
contains = SMB_EO_CONTAINS_WRITES;
break;
default:
contains = SMB_EO_CONTAINS_NOTHING;
break;
}
} else {
is_supported_filetype = (eo_info->fid_type == SMB2_FID_TYPE_FILE );
aux_smb_fid_type_string=g_strdup(try_val_to_str(eo_info->fid_type, smb2_fid_types));
switch(eo_info->cmd) {
case SMB2_COM_READ:
contains = SMB_EO_CONTAINS_READS;
break;
case SMB2_COM_WRITE:
contains = SMB_EO_CONTAINS_WRITES;
break;
default:
contains = SMB_EO_CONTAINS_NOTHING;
break;
}
}
incoming_file.tid = eo_info->tid;
incoming_file.uid = eo_info->uid;
incoming_file.fid = eo_info->fid;
active_row = find_incoming_file(GSL_active_files, &incoming_file);
if (active_row == -1) {
entry = (export_object_entry_t *)g_malloc(sizeof(export_object_entry_t));
entry->payload_data = NULL;
entry->payload_len = 0;
new_file = (active_file *)g_malloc(sizeof(active_file));
new_file->tid = incoming_file.tid;
new_file->uid = incoming_file.uid;
new_file->fid = incoming_file.fid;
new_file->file_length = eo_info->end_of_file;
new_file->flag_contains = contains;
new_file->free_chunk_list = NULL;
new_file->data_gathered = 0;
new_file->is_out_of_memory = FALSE;
entry->pkt_num = pinfo->fd->num;
entry->hostname=g_filename_display_name(g_strcanon(eo_info->hostname,LEGAL_FILENAME_CHARS,'?'));
entry->filename=g_filename_display_name(g_strcanon(eo_info->filename,LEGAL_FILENAME_CHARS,'?'));
if (is_supported_filetype) {
insert_chunk(new_file, entry, eo_info);
}
if (new_file->is_out_of_memory) {
entry->content_type =
g_strdup_printf("%s (%"G_GUINT64_FORMAT"?/%"G_GUINT64_FORMAT") %s [mem!!]",
aux_smb_fid_type_string,
new_file->data_gathered,
new_file->file_length,
try_val_to_str(contains, smb_eo_contains_string));
} else {
if (new_file->file_length > 0) {
percent = (gfloat) (100*new_file->data_gathered/new_file->file_length);
} else {
percent = 0.0f;
}
entry->content_type =
g_strdup_printf("%s (%"G_GUINT64_FORMAT"/%"G_GUINT64_FORMAT") %s [%5.2f%%]",
aux_smb_fid_type_string,
new_file->data_gathered,
new_file->file_length,
try_val_to_str(contains, smb_eo_contains_string),
percent);
}
object_list_add_entry(object_list, entry);
GSL_active_files = g_slist_append(GSL_active_files, new_file);
}
else if (is_supported_filetype) {
current_file = (active_file *)g_slist_nth_data(GSL_active_files, active_row);
current_file->flag_contains = current_file->flag_contains|contains;
current_entry = object_list_get_entry(object_list, active_row);
insert_chunk(current_file, current_entry, eo_info);
if (current_file->is_out_of_memory) {
current_entry->content_type =
g_strdup_printf("%s (%"G_GUINT64_FORMAT"?/%"G_GUINT64_FORMAT") %s [mem!!]",
aux_smb_fid_type_string,
current_file->data_gathered,
current_file->file_length,
try_val_to_str(current_file->flag_contains, smb_eo_contains_string));
} else {
percent = (gfloat) (100*current_file->data_gathered/current_file->file_length);
current_entry->content_type =
g_strdup_printf("%s (%"G_GUINT64_FORMAT"/%"G_GUINT64_FORMAT") %s [%5.2f%%]",
aux_smb_fid_type_string,
current_file->data_gathered,
current_file->file_length,
try_val_to_str(current_file->flag_contains, smb_eo_contains_string),
percent);
}
}
return TRUE;
}
void
eo_smb_cleanup(void)
{
int i, last;
active_file *in_list_file;
last = g_slist_length(GSL_active_files);
if (GSL_active_files) {
for (i=last-1; i>=0; i--) {
in_list_file = (active_file *)g_slist_nth_data(GSL_active_files, i);
if (in_list_file->free_chunk_list) {
g_slist_free(in_list_file->free_chunk_list);
in_list_file->free_chunk_list = NULL;
}
g_free(in_list_file);
}
g_slist_free(GSL_active_files);
GSL_active_files = NULL;
}
}
