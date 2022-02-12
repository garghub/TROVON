guint randpkt_example_count(void)
{
return array_length(examples);
}
randpkt_example* randpkt_find_example(int type)
{
int num_entries = array_length(examples);
int i;
for (i = 0; i < num_entries; i++) {
if (examples[i].produceable_type == type) {
return &examples[i];
}
}
fprintf(stderr, "randpkt: Internal error. Type %d has no entry in examples table.\n",
type);
return NULL;
}
void randpkt_loop(randpkt_example* example, guint64 produce_count)
{
guint i;
int j;
int err;
int len_random;
int len_this_pkt;
gchar* err_info;
union wtap_pseudo_header* ps_header;
guint8 buffer[65536];
struct wtap_pkthdr* pkthdr;
pkthdr = g_new0(struct wtap_pkthdr, 1);
pkthdr->rec_type = REC_TYPE_PACKET;
pkthdr->presence_flags = WTAP_HAS_TS;
pkthdr->pkt_encap = example->sample_wtap_encap;
memset(pkthdr, 0, sizeof(struct wtap_pkthdr));
memset(buffer, 0, sizeof(buffer));
ps_header = &pkthdr->pseudo_header;
if (example->pseudo_buffer)
memcpy(ps_header, example->pseudo_buffer, example->pseudo_length);
if (example->sample_buffer)
memcpy(buffer, example->sample_buffer, example->sample_length);
for (i = 0; i < produce_count; i++) {
if (example->produce_max_bytes > 0) {
len_random = (rand() % example->produce_max_bytes + 1);
}
else {
len_random = 0;
}
len_this_pkt = example->sample_length + len_random;
pkthdr->caplen = len_this_pkt;
pkthdr->len = len_this_pkt;
pkthdr->ts.secs = i;
for (j = example->pseudo_length; j < (int) sizeof(*ps_header); j++) {
((guint8*)ps_header)[j] = (rand() % 0x100);
}
for (j = example->sample_length; j < len_this_pkt; j++) {
if ((int) (100.0*rand()/(RAND_MAX+1.0)) < 3 && j < (len_random - 3)) {
memcpy(&buffer[j], "%s", 3);
j += 2;
} else {
buffer[j] = (rand() % 0x100);
}
}
if (!wtap_dump(example->dump, pkthdr, buffer, &err, &err_info)) {
fprintf(stderr, "randpkt: Error writing to %s: %s\n",
example->filename, wtap_strerror(err));
switch (err) {
case WTAP_ERR_UNWRITABLE_ENCAP:
fprintf(stderr,
"Frame has a network type that can't be saved in a \"%s\" file.\n",
wtap_file_type_subtype_short_string(WTAP_FILE_TYPE_SUBTYPE_PCAP));
break;
case WTAP_ERR_PACKET_TOO_LARGE:
fprintf(stderr,
"Frame is too large for a \"%s\" file.\n",
wtap_file_type_subtype_short_string(WTAP_FILE_TYPE_SUBTYPE_PCAP));
break;
case WTAP_ERR_UNWRITABLE_REC_TYPE:
fprintf(stderr,
"Record has a record type that can't be saved in a \"%s\" file.\n",
wtap_file_type_subtype_short_string(WTAP_FILE_TYPE_SUBTYPE_PCAP));
break;
case WTAP_ERR_UNWRITABLE_REC_DATA:
fprintf(stderr,
"Record has data that can't be saved in a \"%s\" file.\n(%s)\n",
wtap_file_type_subtype_short_string(WTAP_FILE_TYPE_SUBTYPE_PCAP),
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
break;
}
}
}
g_free(pkthdr);
}
gboolean randpkt_example_close(randpkt_example* example)
{
int err;
if (!wtap_dump_close(example->dump, &err)) {
fprintf(stderr, "Error writing to %s: %s\n",
example->filename, wtap_strerror(err));
return FALSE;
}
return TRUE;
}
void randpkt_example_init(randpkt_example* example, char* produce_filename, int produce_max_bytes)
{
int err;
if (strcmp(produce_filename, "-") == 0) {
example->dump = wtap_dump_open_stdout(WTAP_FILE_TYPE_SUBTYPE_PCAP,
example->sample_wtap_encap, produce_max_bytes, FALSE , &err);
example->filename = "the standard output";
} else {
example->dump = wtap_dump_open(produce_filename, WTAP_FILE_TYPE_SUBTYPE_PCAP,
example->sample_wtap_encap, produce_max_bytes, FALSE , &err);
example->filename = produce_filename;
}
if (!example->dump) {
fprintf(stderr, "randpkt: Error writing to %s\n", example->filename);
exit(2);
}
if (produce_max_bytes <= example->sample_length) {
fprintf(stderr, "randpkt: Sample packet length is %d, which is greater than "
"or equal to\n", example->sample_length);
fprintf(stderr, "your requested max_bytes value of %d\n", produce_max_bytes);
exit(1);
} else {
example->produce_max_bytes = produce_max_bytes - example->sample_length;
}
}
void
randpkt_seed(void)
{
unsigned int randomness;
time_t now;
#ifndef _WIN32
int fd;
ssize_t ret;
#define RANDOM_DEV "/dev/urandom"
fd = ws_open(RANDOM_DEV, O_RDONLY);
if (fd == -1) {
if (errno != ENOENT) {
fprintf(stderr,
"randpkt: Could not open " RANDOM_DEV " for reading: %s\n",
g_strerror(errno));
exit(2);
}
goto fallback;
}
ret = ws_read(fd, &randomness, sizeof randomness);
if (ret == -1) {
fprintf(stderr,
"randpkt: Could not read from " RANDOM_DEV ": %s\n",
g_strerror(errno));
exit(2);
}
if ((size_t)ret != sizeof randomness) {
fprintf(stderr,
"randpkt: Tried to read %lu bytes from " RANDOM_DEV ", got %ld\n",
(unsigned long)sizeof randomness, (long)ret);
exit(2);
}
srand(randomness);
ws_close(fd);
return;
fallback:
#endif
now = time(NULL);
randomness = (unsigned int) now;
srand(randomness);
}
int randpkt_parse_type(char *string)
{
int num_entries = array_length(examples);
int i;
if (!string) {
return examples[rand() % num_entries].produceable_type;
}
for (i = 0; i < num_entries; i++) {
if (g_strcmp0(examples[i].abbrev, string) == 0) {
return examples[i].produceable_type;
}
}
fprintf(stderr, "randpkt: Type %s not known.\n", string);
return -1;
}
void randpkt_example_list(char*** abbrev_list, char*** longname_list)
{
unsigned i;
unsigned list_num;
list_num = randpkt_example_count();
*abbrev_list = g_new0(char*, list_num + 1);
*longname_list = g_new0(char*, list_num + 1);
for (i = 0; i < list_num; i++) {
(*abbrev_list)[i] = g_strdup(examples[i].abbrev);
(*longname_list)[i] = g_strdup(examples[i].longname);
}
}
