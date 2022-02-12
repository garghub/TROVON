static int
get_natural_int(const char *string, const char *name)
{
long number;
char *p;
number = strtol(string, &p, 10);
if (p == string || *p != '\0') {
fprintf(stderr, "mergecap: The specified %s \"%s\" isn't a decimal number\n",
name, string);
exit(1);
}
if (number < 0) {
fprintf(stderr, "mergecap: The specified %s is a negative number\n", name);
exit(1);
}
if (number > INT_MAX) {
fprintf(stderr, "mergecap: The specified %s is too large (greater than %d)\n",
name, INT_MAX);
exit(1);
}
return (int)number;
}
static int
get_positive_int(const char *string, const char *name)
{
int number;
number = get_natural_int(string, name);
if (number == 0) {
fprintf(stderr, "mergecap: The specified %s is zero\n", name);
exit(1);
}
return number;
}
static void
usage(void)
{
fprintf(stderr, "Mergecap %s"
#ifdef SVNVERSION
" (" SVNVERSION " from " SVNPATH ")"
#endif
"\n", VERSION);
fprintf(stderr, "Merge two or more capture files into one.\n");
fprintf(stderr, "See http://www.wireshark.org for more information.\n");
fprintf(stderr, "\n");
fprintf(stderr, "Usage: mergecap [options] -w <outfile>|- <infile> [<infile> ...]\n");
fprintf(stderr, "\n");
fprintf(stderr, "Output:\n");
fprintf(stderr, " -a concatenate rather than merge files.\n");
fprintf(stderr, " default is to merge based on frame timestamps.\n");
fprintf(stderr, " -s <snaplen> truncate packets to <snaplen> bytes of data.\n");
fprintf(stderr, " -w <outfile>|- set the output filename to <outfile> or '-' for stdout.\n");
fprintf(stderr, " -F <capture type> set the output file type; default is pcapng.\n");
fprintf(stderr, " an empty \"-F\" option will list the file types.\n");
fprintf(stderr, " -T <encap type> set the output file encapsulation type;\n");
fprintf(stderr, " default is the same as the first input file.\n");
fprintf(stderr, " an empty \"-T\" option will list the encapsulation types.\n");
fprintf(stderr, "\n");
fprintf(stderr, "Miscellaneous:\n");
fprintf(stderr, " -h display this help and exit.\n");
fprintf(stderr, " -v verbose output.\n");
}
static gint
string_compare(gconstpointer a, gconstpointer b)
{
return strcmp(((const struct string_elem *)a)->sstr,
((const struct string_elem *)b)->sstr);
}
static gint
string_nat_compare(gconstpointer a, gconstpointer b)
{
return strnatcmp(((const struct string_elem *)a)->sstr,
((const struct string_elem *)b)->sstr);
}
static void
string_elem_print(gpointer data, gpointer not_used _U_)
{
fprintf(stderr, " %s - %s\n", ((struct string_elem *)data)->sstr,
((struct string_elem *)data)->lstr);
}
static void
list_capture_types(void) {
int i;
struct string_elem *captypes;
GSList *list = NULL;
captypes = g_new(struct string_elem,WTAP_NUM_FILE_TYPES);
fprintf(stderr, "mergecap: The available capture file types for the \"-F\" flag are:\n");
for (i = 0; i < WTAP_NUM_FILE_TYPES; i++) {
if (wtap_dump_can_open(i)) {
captypes[i].sstr = wtap_file_type_short_string(i);
captypes[i].lstr = wtap_file_type_string(i);
list = g_slist_insert_sorted(list, &captypes[i], string_compare);
}
}
g_slist_foreach(list, string_elem_print, NULL);
g_slist_free(list);
g_free(captypes);
}
static void
list_encap_types(void) {
int i;
struct string_elem *encaps;
GSList *list = NULL;
encaps = g_new(struct string_elem,WTAP_NUM_ENCAP_TYPES);
fprintf(stderr, "mergecap: The available encapsulation types for the \"-T\" flag are:\n");
for (i = 0; i < WTAP_NUM_ENCAP_TYPES; i++) {
encaps[i].sstr = wtap_encap_short_string(i);
if (encaps[i].sstr != NULL) {
encaps[i].lstr = wtap_encap_string(i);
list = g_slist_insert_sorted(list, &encaps[i], string_nat_compare);
}
}
g_slist_foreach(list, string_elem_print, NULL);
g_slist_free(list);
g_free(encaps);
}
int
main(int argc, char *argv[])
{
int opt;
gboolean do_append = FALSE;
gboolean verbose = FALSE;
int in_file_count = 0;
guint snaplen = 0;
#ifdef PCAP_NG_DEFAULT
int file_type = WTAP_FILE_PCAPNG;
#else
int file_type = WTAP_FILE_PCAP;
#endif
int frame_type = -2;
int out_fd;
merge_in_file_t *in_files = NULL, *in_file;
int i;
struct wtap_pkthdr *phdr, snap_phdr;
wtap_dumper *pdh;
int open_err, read_err = 0, write_err, close_err;
gchar *err_info;
int err_fileno;
char *out_filename = NULL;
gboolean got_read_error = FALSE, got_write_error = FALSE;
int count;
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
#endif
while ((opt = getopt(argc, argv, "aF:hs:T:vw:")) != -1) {
switch (opt) {
case 'a':
do_append = !do_append;
break;
case 'F':
file_type = wtap_short_string_to_file_type(optarg);
if (file_type < 0) {
fprintf(stderr, "mergecap: \"%s\" isn't a valid capture file type\n",
optarg);
list_capture_types();
exit(1);
}
break;
case 'h':
usage();
exit(0);
break;
case 's':
snaplen = get_positive_int(optarg, "snapshot length");
break;
case 'T':
frame_type = wtap_short_string_to_encap(optarg);
if (frame_type < 0) {
fprintf(stderr, "mergecap: \"%s\" isn't a valid encapsulation type\n",
optarg);
list_encap_types();
exit(1);
}
break;
case 'v':
verbose = TRUE;
break;
case 'w':
out_filename = optarg;
break;
case '?':
switch(optopt) {
case'F':
list_capture_types();
break;
case'T':
list_encap_types();
break;
default:
usage();
}
exit(1);
break;
}
}
in_file_count = argc - optind;
if (!out_filename) {
fprintf(stderr, "mergecap: an output filename must be set with -w\n");
fprintf(stderr, " run with -h for help\n");
return 1;
}
if (in_file_count < 1) {
fprintf(stderr, "mergecap: No input files were specified\n");
return 1;
}
if (!merge_open_in_files(in_file_count, &argv[optind], &in_files,
&open_err, &err_info, &err_fileno)) {
fprintf(stderr, "mergecap: Can't open %s: %s\n", argv[optind + err_fileno],
wtap_strerror(open_err));
switch (open_err) {
case WTAP_ERR_UNSUPPORTED:
case WTAP_ERR_UNSUPPORTED_ENCAP:
case WTAP_ERR_BAD_FILE:
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
break;
}
return 2;
}
if (verbose) {
for (i = 0; i < in_file_count; i++)
fprintf(stderr, "mergecap: %s is type %s.\n", argv[optind + i],
wtap_file_type_string(wtap_file_type(in_files[i].wth)));
}
if (snaplen == 0) {
snaplen = merge_max_snapshot_length(in_file_count, in_files);
}
if (frame_type == -2) {
frame_type = merge_select_frame_type(in_file_count, in_files);
if (verbose) {
if (frame_type == WTAP_ENCAP_PER_PACKET) {
int first_frame_type, this_frame_type;
first_frame_type = wtap_file_encap(in_files[0].wth);
for (i = 1; i < in_file_count; i++) {
this_frame_type = wtap_file_encap(in_files[i].wth);
if (first_frame_type != this_frame_type) {
fprintf(stderr, "mergecap: multiple frame encapsulation types detected\n");
fprintf(stderr, " defaulting to WTAP_ENCAP_PER_PACKET\n");
fprintf(stderr, " %s had type %s (%s)\n",
in_files[0].filename,
wtap_encap_string(first_frame_type),
wtap_encap_short_string(first_frame_type));
fprintf(stderr, " %s had type %s (%s)\n",
in_files[i].filename,
wtap_encap_string(this_frame_type),
wtap_encap_short_string(this_frame_type));
break;
}
}
}
fprintf(stderr, "mergecap: selected frame_type %s (%s)\n",
wtap_encap_string(frame_type),
wtap_encap_short_string(frame_type));
}
}
if (strncmp(out_filename, "-", 2) == 0) {
out_fd = 1 ;
} else {
out_fd = ws_open(out_filename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, 0644);
if (out_fd == -1) {
fprintf(stderr, "mergecap: Couldn't open output file %s: %s\n",
out_filename, g_strerror(errno));
exit(1);
}
}
if(file_type == WTAP_FILE_PCAPNG ){
wtapng_section_t *shb_hdr;
GString *comment_gstr;
shb_hdr = g_new(wtapng_section_t,1);
comment_gstr = g_string_new("File created by merging: \n");
for (i = 0; i < in_file_count; i++) {
g_string_append_printf(comment_gstr, "File%d: %s \n",i+1,in_files[i].filename);
}
shb_hdr->section_length = -1;
shb_hdr->opt_comment = comment_gstr->str;
shb_hdr->shb_hardware = NULL;
shb_hdr->shb_os = NULL;
shb_hdr->shb_user_appl = "mergecap";
pdh = wtap_dump_fdopen_ng(out_fd, file_type, frame_type, snaplen,
FALSE , shb_hdr, NULL , &open_err);
g_string_free(comment_gstr, TRUE);
} else {
pdh = wtap_dump_fdopen(out_fd, file_type, frame_type, snaplen, FALSE , &open_err);
}
if (pdh == NULL) {
merge_close_in_files(in_file_count, in_files);
g_free(in_files);
fprintf(stderr, "mergecap: Can't open or create %s: %s\n", out_filename,
wtap_strerror(open_err));
exit(1);
}
count = 1;
for (;;) {
if (do_append)
in_file = merge_append_read_packet(in_file_count, in_files, &read_err,
&err_info);
else
in_file = merge_read_packet(in_file_count, in_files, &read_err,
&err_info);
if (in_file == NULL) {
break;
}
if (read_err != 0) {
got_read_error = TRUE;
break;
}
if (verbose)
fprintf(stderr, "Record: %u\n", count++);
phdr = wtap_phdr(in_file->wth);
if (snaplen != 0 && phdr->caplen > snaplen) {
snap_phdr = *phdr;
snap_phdr.caplen = snaplen;
phdr = &snap_phdr;
}
if (!wtap_dump(pdh, phdr, wtap_buf_ptr(in_file->wth), &write_err)) {
got_write_error = TRUE;
break;
}
}
merge_close_in_files(in_file_count, in_files);
if (!got_read_error && !got_write_error) {
if (!wtap_dump_close(pdh, &write_err))
got_write_error = TRUE;
} else
wtap_dump_close(pdh, &close_err);
if (got_read_error) {
for (i = 0; i < in_file_count; i++) {
if (in_files[i].state == GOT_ERROR) {
fprintf(stderr, "mergecap: Error reading %s: %s\n",
in_files[i].filename, wtap_strerror(read_err));
switch (read_err) {
case WTAP_ERR_UNSUPPORTED:
case WTAP_ERR_UNSUPPORTED_ENCAP:
case WTAP_ERR_BAD_FILE:
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
break;
}
}
}
}
if (got_write_error) {
switch (write_err) {
case WTAP_ERR_UNSUPPORTED_ENCAP:
fprintf(stderr, "mergecap: Frame %u of \"%s\" has a network type that can't be saved in a file with that format\n.",
in_file->packet_num, in_file->filename);
break;
default:
fprintf(stderr, "mergecap: Error writing to outfile: %s\n",
wtap_strerror(write_err));
break;
}
}
g_free(in_files);
return (!got_read_error && !got_write_error) ? 0 : 2;
}
