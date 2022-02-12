gboolean
merge_open_in_files(int in_file_count, char *const *in_file_names,
merge_in_file_t **in_files, int *err, gchar **err_info,
int *err_fileno)
{
gint i;
gint j;
size_t files_size = in_file_count * sizeof(merge_in_file_t);
merge_in_file_t *files;
gint64 size;
files = (merge_in_file_t *)g_malloc(files_size);
*in_files = files;
for (i = 0; i < in_file_count; i++) {
files[i].filename = in_file_names[i];
files[i].wth = wtap_open_offline(in_file_names[i], WTAP_TYPE_AUTO, err, err_info, FALSE);
files[i].data_offset = 0;
files[i].state = PACKET_NOT_PRESENT;
files[i].packet_num = 0;
if (!files[i].wth) {
for (j = 0; j < i; j++)
wtap_close(files[j].wth);
*err_fileno = i;
return FALSE;
}
size = wtap_file_size(files[i].wth, err);
if (size == -1) {
for (j = 0; j + 1 > j && j <= i; j++)
wtap_close(files[j].wth);
*err_fileno = i;
return FALSE;
}
files[i].size = size;
}
return TRUE;
}
void
merge_close_in_files(int count, merge_in_file_t in_files[])
{
int i;
for (i = 0; i < count; i++) {
wtap_close(in_files[i].wth);
}
}
int
merge_select_frame_type(int count, merge_in_file_t files[])
{
int i;
int selected_frame_type;
selected_frame_type = wtap_file_encap(files[0].wth);
for (i = 1; i < count; i++) {
int this_frame_type = wtap_file_encap(files[i].wth);
if (selected_frame_type != this_frame_type) {
selected_frame_type = WTAP_ENCAP_PER_PACKET;
break;
}
}
return selected_frame_type;
}
int
merge_max_snapshot_length(int count, merge_in_file_t in_files[])
{
int i;
int max_snapshot = 0;
int snapshot_length;
for (i = 0; i < count; i++) {
snapshot_length = wtap_snapshot_length(in_files[i].wth);
if (snapshot_length == 0) {
snapshot_length = WTAP_MAX_PACKET_SIZE;
}
if (snapshot_length > max_snapshot)
max_snapshot = snapshot_length;
}
return max_snapshot;
}
static gboolean
is_earlier(nstime_t *l, nstime_t *r)
{
if (l->secs > r->secs) {
return FALSE;
} else if (l->secs < r->secs) {
return TRUE;
} else if (l->nsecs > r->nsecs) {
return FALSE;
}
return TRUE;
}
merge_in_file_t *
merge_read_packet(int in_file_count, merge_in_file_t in_files[],
int *err, gchar **err_info)
{
int i;
int ei = -1;
nstime_t tv = { sizeof(time_t) > sizeof(int) ? LONG_MAX : INT_MAX, INT_MAX };
struct wtap_pkthdr *phdr;
for (i = 0; i < in_file_count; i++) {
if (in_files[i].state == PACKET_NOT_PRESENT) {
if (!wtap_read(in_files[i].wth, err, err_info, &in_files[i].data_offset)) {
if (*err != 0) {
in_files[i].state = GOT_ERROR;
return &in_files[i];
}
in_files[i].state = AT_EOF;
} else
in_files[i].state = PACKET_PRESENT;
}
if (in_files[i].state == PACKET_PRESENT) {
phdr = wtap_phdr(in_files[i].wth);
if (is_earlier(&phdr->ts, &tv)) {
tv = phdr->ts;
ei = i;
}
}
}
if (ei == -1) {
*err = 0;
return NULL;
}
in_files[ei].state = PACKET_NOT_PRESENT;
in_files[ei].packet_num++;
*err = 0;
return &in_files[ei];
}
merge_in_file_t *
merge_append_read_packet(int in_file_count, merge_in_file_t in_files[],
int *err, gchar **err_info)
{
int i;
for (i = 0; i < in_file_count; i++) {
if (in_files[i].state == AT_EOF)
continue;
if (wtap_read(in_files[i].wth, err, err_info, &in_files[i].data_offset))
break;
if (*err != 0) {
in_files[i].state = GOT_ERROR;
return &in_files[i];
}
in_files[i].state = AT_EOF;
}
if (i == in_file_count) {
*err = 0;
return NULL;
}
*err = 0;
return &in_files[i];
}
