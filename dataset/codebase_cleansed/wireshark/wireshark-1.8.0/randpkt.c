int
main(int argc, char **argv)
{
wtap_dumper *dump;
struct wtap_pkthdr pkthdr;
union wtap_pseudo_header ps_header;
int i, j, len_this_pkt, len_random, err;
guint8 buffer[65536];
int opt;
int produce_count = 1000;
int produce_type = PKT_ETHERNET;
char *produce_filename = NULL;
int produce_max_bytes = 5000;
pkt_example *example;
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
#endif
while ((opt = getopt(argc, argv, "b:c:ht:")) != -1) {
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
default:
usage();
break;
}
}
if (argc > optind) {
produce_filename = argv[optind];
}
else {
usage();
}
example = find_example(produce_type);
dump = wtap_dump_open(produce_filename, WTAP_FILE_PCAP,
example->sample_wtap_encap, produce_max_bytes, FALSE , &err);
if (!dump) {
fprintf(stderr,
"randpkt: Error writing to %s\n", produce_filename);
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
memset(&ps_header, 0, sizeof(ps_header));
memset(buffer, 0, sizeof(buffer));
pkthdr.pkt_encap = example->sample_wtap_encap;
if (example->pseudo_buffer)
memcpy(&ps_header, example->pseudo_buffer, example->pseudo_length);
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
for (j = example->pseudo_length; j < (int) sizeof(ps_header); j++) {
((guint8*)&ps_header)[j] = (rand() % 0x100);
}
for (j = example->sample_length; j < len_this_pkt; j++) {
if ((int) (100.0*rand()/(RAND_MAX+1.0)) < 3 && j < (len_random - 3)) {
memcpy(&buffer[j], "%s", 3);
j += 2;
} else {
buffer[j] = (rand() % 0x100);
}
}
wtap_dump(dump, &pkthdr, &ps_header, &buffer[0], &err);
}
wtap_dump_close(dump, &err);
return 0;
}
static
void usage(void)
{
int num_entries = array_length(examples);
int i;
printf("Usage: randpkt [-b maxbytes] [-c count] [-t type] filename\n");
printf("Default max bytes (per packet) is 5000\n");
printf("Default count is 1000.\n");
printf("Types:\n");
for (i = 0; i < num_entries; i++) {
printf("\t%s\t%s\n", examples[i].abbrev, examples[i].longname);
}
printf("\n");
exit(0);
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
