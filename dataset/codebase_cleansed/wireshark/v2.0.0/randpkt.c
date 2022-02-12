int
main(int argc, char **argv)
{
wtap_dumper *dump;
const char *filename;
struct wtap_pkthdr pkthdr;
union wtap_pseudo_header *ps_header = &pkthdr.pseudo_header;
int i, j, len_this_pkt, len_random, err;
gchar *err_info;
guint8 buffer[65536];
int opt;
int produce_count = 1000;
int produce_type = PKT_ETHERNET;
char *produce_filename = NULL;
int produce_max_bytes = 5000;
pkt_example *example;
DIAG_OFF(cast-qual)
static const struct option long_options[] = {
{(char *)"help", no_argument, NULL, 'h'},
{0, 0, 0, 0 }
};
DIAG_ON(cast-qual)
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
#endif
while ((opt = getopt_long(argc, argv, "b:c:ht:", long_options, NULL)) != -1) {
switch (opt) {
case 'b':
produce_max_bytes = atoi(optarg);
if (produce_max_bytes > 65536) {
fprintf(stderr,
"randpkt: Max bytes is 65536\n");
exit(1);
}
break;
case 'c':
produce_count = atoi(optarg);
break;
case 't':
produce_type = parse_type(optarg);
break;
case 'h':
usage(FALSE);
break;
default:
usage(TRUE);
break;
}
}
if (argc > optind) {
produce_filename = argv[optind];
}
else {
usage(TRUE);
}
example = find_example(produce_type);
if (strcmp(produce_filename, "-") == 0) {
dump = wtap_dump_open_stdout(WTAP_FILE_TYPE_SUBTYPE_PCAP,
example->sample_wtap_encap, produce_max_bytes, FALSE , &err);
filename = "the standard output";
} else {
dump = wtap_dump_open(produce_filename, WTAP_FILE_TYPE_SUBTYPE_PCAP,
example->sample_wtap_encap, produce_max_bytes, FALSE , &err);
filename = produce_filename;
}
if (!dump) {
fprintf(stderr,
"randpkt: Error writing to %s\n", filename);
exit(2);
}
seed();
if (produce_max_bytes <= example->sample_length) {
fprintf(stderr,
"randpkt: Sample packet length is %d, which is greater than or equal to\n",
example->sample_length);
fprintf(stderr, "your requested max_bytes value of %d\n",
produce_max_bytes);
exit(1);
}
else {
produce_max_bytes -= example->sample_length;
}
memset(&pkthdr, 0, sizeof(pkthdr));
memset(buffer, 0, sizeof(buffer));
pkthdr.rec_type = REC_TYPE_PACKET;
pkthdr.presence_flags = WTAP_HAS_TS;
pkthdr.pkt_encap = example->sample_wtap_encap;
if (example->pseudo_buffer)
memcpy(ps_header, example->pseudo_buffer, example->pseudo_length);
if (example->sample_buffer)
memcpy(&buffer[0], example->sample_buffer, example->sample_length);
for (i = 0; i < produce_count; i++) {
if (produce_max_bytes > 0) {
len_random = (rand() % produce_max_bytes + 1);
}
else {
len_random = 0;
}
len_this_pkt = example->sample_length + len_random;
pkthdr.caplen = len_this_pkt;
pkthdr.len = len_this_pkt;
pkthdr.ts.secs = i;
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
if (!wtap_dump(dump, &pkthdr, &buffer[0], &err, &err_info)) {
fprintf(stderr, "randpkt: Error writing to %s: %s\n",
filename, wtap_strerror(err));
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
if (!wtap_dump_close(dump, &err)) {
fprintf(stderr, "Error writing to %s: %s\n",
filename, wtap_strerror(err));
return 2;
}
return 0;
}
static void
usage(gboolean is_error)
{
FILE *output;
int num_entries = array_length(examples);
int i;
if (!is_error) {
output = stdout;
}
else {
output = stderr;
}
fprintf(output, "Usage: randpkt [-b maxbytes] [-c count] [-t type] filename\n");
fprintf(output, "Default max bytes (per packet) is 5000\n");
fprintf(output, "Default count is 1000.\n");
fprintf(output, "Types:\n");
for (i = 0; i < num_entries; i++) {
fprintf(output, "\t%-16s%s\n", examples[i].abbrev, examples[i].longname);
}
fprintf(output, "\n");
exit(is_error ? 1 : 0);
}
static
int parse_type(char *string)
{
int num_entries = array_length(examples);
int i;
for (i = 0; i < num_entries; i++) {
if (strcmp(examples[i].abbrev, string) == 0) {
return examples[i].produceable_type;
}
}
fprintf(stderr, "randpkt: Type %s not known.\n", string);
exit(1);
}
static
pkt_example* find_example(int type)
{
int num_entries = array_length(examples);
int i;
for (i = 0; i < num_entries; i++) {
if (examples[i].produceable_type == type) {
return &examples[i];
}
}
fprintf(stderr,
"randpkt: Internal error. Type %d has no entry in examples table.\n",
type);
exit(1);
}
void
seed(void)
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
