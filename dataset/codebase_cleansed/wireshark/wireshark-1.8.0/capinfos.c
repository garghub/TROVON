static void
enable_all_infos(void)
{
report_all_infos = TRUE;
cap_file_type = TRUE;
cap_file_encap = TRUE;
cap_snaplen = TRUE;
cap_packet_count = TRUE;
cap_file_size = TRUE;
cap_data_size = TRUE;
cap_duration = TRUE;
cap_start_time = TRUE;
cap_end_time = TRUE;
cap_order = TRUE;
cap_data_rate_byte = TRUE;
cap_data_rate_bit = TRUE;
cap_packet_size = TRUE;
cap_packet_rate = TRUE;
#ifdef HAVE_LIBGCRYPT
cap_file_hashes = TRUE;
#endif
}
static void
disable_all_infos(void)
{
report_all_infos = FALSE;
cap_file_type = FALSE;
cap_file_encap = FALSE;
cap_snaplen = FALSE;
cap_packet_count = FALSE;
cap_file_size = FALSE;
cap_data_size = FALSE;
cap_duration = FALSE;
cap_start_time = FALSE;
cap_end_time = FALSE;
cap_order = FALSE;
cap_data_rate_byte = FALSE;
cap_data_rate_bit = FALSE;
cap_packet_size = FALSE;
cap_packet_rate = FALSE;
#ifdef HAVE_LIBGCRYPT
cap_file_hashes = FALSE;
#endif
}
static const gchar *
order_string(order_t order)
{
switch (order) {
case IN_ORDER:
return "True";
case NOT_IN_ORDER:
return "False";
case ORDER_UNKNOWN:
return "Unknown";
default:
return "???";
}
}
static gchar *
time_string(time_t timer, capture_info *cf_info, gboolean want_lf)
{
const gchar *lf = want_lf ? "\n" : "";
static gchar time_string_buf[20];
char *time_string_ctime;
if (cf_info->times_known && cf_info->packet_count > 0) {
if (time_as_secs) {
g_snprintf(time_string_buf, 20, "%lu%s", (unsigned long)timer, lf);
return time_string_buf;
} else {
#ifdef _MSC_VER
if (timer > 2000000000) {
time_string_ctime = NULL;
} else
#endif
time_string_ctime = ctime(&timer);
if (time_string_ctime == NULL) {
g_snprintf(time_string_buf, 20, "Not representable%s", lf);
return time_string_buf;
}
if (!want_lf) {
time_string_ctime[24] = '\0';
}
return time_string_ctime;
}
}
g_snprintf(time_string_buf, 15, "n/a%s", lf);
return time_string_buf;
}
static double
secs_nsecs(const struct wtap_nstime * nstime)
{
return (nstime->nsecs / 1000000000.0) + (double)nstime->secs;
}
static void print_value(const gchar *text_p1, gint width, const gchar *text_p2, double value) {
if (value > 0.0)
printf("%s%.*f%s\n", text_p1, width, value, text_p2);
else
printf("%sn/a\n", text_p1);
}
static void
print_stats(const gchar *filename, capture_info *cf_info)
{
const gchar *file_type_string, *file_encap_string;
time_t start_time_t;
time_t stop_time_t;
file_type_string = wtap_file_type_string(cf_info->file_type);
file_encap_string = wtap_encap_string(cf_info->file_encap);
start_time_t = (time_t)cf_info->start_time;
stop_time_t = (time_t)cf_info->stop_time;
if (filename) printf ("File name: %s\n", filename);
if (cap_file_type) printf ("File type: %s%s\n",
file_type_string,
cf_info->iscompressed ? " (gzip compressed)" : "");
if (cap_file_encap) printf ("File encapsulation: %s\n", file_encap_string);
if (cap_file_encap && (cf_info->file_encap == WTAP_ENCAP_PER_PACKET)) {
int i;
for (i=0; i<WTAP_NUM_ENCAP_TYPES; i++) {
if (cf_info->encap_counts[i] > 0)
printf(" %s\n", wtap_encap_string(i));
}
}
if (cap_snaplen && cf_info->snap_set)
printf ("Packet size limit: file hdr: %u bytes\n", cf_info->snaplen);
else if(cap_snaplen && !cf_info->snap_set)
printf ("Packet size limit: file hdr: (not set)\n");
if (cf_info->snaplen_max_inferred > 0) {
if (cf_info->snaplen_min_inferred == cf_info->snaplen_max_inferred)
printf ("Packet size limit: inferred: %u bytes\n", cf_info->snaplen_min_inferred);
else
printf ("Packet size limit: inferred: %u bytes - %u bytes (range)\n",
cf_info->snaplen_min_inferred, cf_info->snaplen_max_inferred);
}
if (cap_packet_count) printf ("Number of packets: %u\n", cf_info->packet_count);
if (cap_file_size) printf ("File size: %" G_GINT64_MODIFIER "d bytes\n", cf_info->filesize);
if (cap_data_size) printf ("Data size: %" G_GINT64_MODIFIER "u bytes\n", cf_info->packet_bytes);
if (cf_info->times_known) {
if (cap_duration)
print_value("Capture duration: ", 0, " seconds", cf_info->duration);
if (cap_start_time)
printf ("Start time: %s", time_string(start_time_t, cf_info, TRUE));
if (cap_end_time)
printf ("End time: %s", time_string(stop_time_t, cf_info, TRUE));
if (cap_data_rate_byte)
print_value("Data byte rate: ", 2, " bytes/sec", cf_info->data_rate);
if (cap_data_rate_bit)
print_value("Data bit rate: ", 2, " bits/sec", cf_info->data_rate*8);
}
if (cap_packet_size) printf ("Average packet size: %.2f bytes\n", cf_info->packet_size);
if (cf_info->times_known) {
if (cap_packet_rate)
print_value("Average packet rate: ", 2, " packets/sec", cf_info->packet_rate);
}
#ifdef HAVE_LIBGCRYPT
if (cap_file_hashes) {
printf ("SHA1: %s\n", file_sha1);
printf ("RIPEMD160: %s\n", file_rmd160);
printf ("MD5: %s\n", file_md5);
}
#endif
if (cap_order) printf ("Strict time order: %s\n", order_string(cf_info->order));
}
static void
putsep(void)
{
if (field_separator) putchar(field_separator);
}
static void
putquote(void)
{
if (quote_char) putchar(quote_char);
}
static void
print_stats_table_header_label(const gchar *label)
{
putsep();
putquote();
printf("%s", label);
putquote();
}
static void
print_stats_table_header(void)
{
putquote();
printf("File name");
putquote();
if (cap_file_type) print_stats_table_header_label("File type");
if (cap_file_encap) print_stats_table_header_label("File encapsulation");
if (cap_snaplen) print_stats_table_header_label("Packet size limit");
if (cap_snaplen) print_stats_table_header_label("Packet size limit min (inferred)");
if (cap_snaplen) print_stats_table_header_label("Packet size limit max (inferred)");
if (cap_packet_count) print_stats_table_header_label("Number of packets");
if (cap_file_size) print_stats_table_header_label("File size (bytes)");
if (cap_data_size) print_stats_table_header_label("Data size (bytes)");
if (cap_duration) print_stats_table_header_label("Capture duration (seconds)");
if (cap_start_time) print_stats_table_header_label("Start time");
if (cap_end_time) print_stats_table_header_label("End time");
if (cap_data_rate_byte) print_stats_table_header_label("Data byte rate (bytes/sec)");
if (cap_data_rate_bit) print_stats_table_header_label("Data bit rate (bits/sec)");
if (cap_packet_size) print_stats_table_header_label("Average packet size (bytes)");
if (cap_packet_rate) print_stats_table_header_label("Average packet rate (packets/sec)");
#ifdef HAVE_LIBGCRYPT
if (cap_file_hashes) {
print_stats_table_header_label("SHA1");
print_stats_table_header_label("RIPEMD160");
print_stats_table_header_label("MD5");
}
#endif
if (cap_order) print_stats_table_header_label("Strict time order");
printf("\n");
}
static void
print_stats_table(const gchar *filename, capture_info *cf_info)
{
const gchar *file_type_string, *file_encap_string;
time_t start_time_t;
time_t stop_time_t;
file_type_string = wtap_file_type_string(cf_info->file_type);
file_encap_string = wtap_encap_string(cf_info->file_encap);
start_time_t = (time_t)cf_info->start_time;
stop_time_t = (time_t)cf_info->stop_time;
if (filename) {
putquote();
printf("%s", filename);
putquote();
}
if (cap_file_type) {
putsep();
putquote();
printf("%s", file_type_string);
putquote();
}
if (cap_file_encap) {
putsep();
putquote();
printf("%s", file_encap_string);
putquote();
}
if (cap_snaplen) {
putsep();
putquote();
if(cf_info->snap_set)
printf("%u", cf_info->snaplen);
else
printf("(not set)");
putquote();
if (cf_info->snaplen_max_inferred > 0) {
putsep();
putquote();
printf("%u", cf_info->snaplen_min_inferred);
putquote();
putsep();
putquote();
printf("%u", cf_info->snaplen_max_inferred);
putquote();
}
else {
putsep();
putquote();
printf("n/a");
putquote();
putsep();
putquote();
printf("n/a");
putquote();
}
}
if (cap_packet_count) {
putsep();
putquote();
printf("%u", cf_info->packet_count);
putquote();
}
if (cap_file_size) {
putsep();
putquote();
printf("%" G_GINT64_MODIFIER "d", cf_info->filesize);
putquote();
}
if (cap_data_size) {
putsep();
putquote();
printf("%" G_GINT64_MODIFIER "u", cf_info->packet_bytes);
putquote();
}
if (cap_duration) {
putsep();
putquote();
if (cf_info->times_known)
printf("%f", cf_info->duration);
else
printf("n/a");
putquote();
}
if (cap_start_time) {
putsep();
putquote();
printf("%s", time_string(start_time_t, cf_info, FALSE));
putquote();
}
if (cap_end_time) {
putsep();
putquote();
printf("%s", time_string(stop_time_t, cf_info, FALSE));
putquote();
}
if (cap_data_rate_byte) {
putsep();
putquote();
if (cf_info->times_known)
printf("%.2f", cf_info->data_rate);
else
printf("n/a");
putquote();
}
if (cap_data_rate_bit) {
putsep();
putquote();
if (cf_info->times_known)
printf("%.2f", cf_info->data_rate*8);
else
printf("n/a");
putquote();
}
if (cap_packet_size) {
putsep();
putquote();
printf("%.2f", cf_info->packet_size);
putquote();
}
if (cap_packet_rate) {
putsep();
putquote();
if (cf_info->times_known)
printf("%.2f", cf_info->packet_rate);
else
printf("n/a");
putquote();
}
#ifdef HAVE_LIBGCRYPT
if (cap_file_hashes) {
putsep();
putquote();
printf("%s", file_sha1);
putquote();
putsep();
putquote();
printf("%s", file_rmd160);
putquote();
putsep();
putquote();
printf("%s", file_md5);
putquote();
}
#endif
if (cap_order) {
putsep();
putquote();
printf("%s", order_string(cf_info->order));
putquote();
}
printf("\n");
}
static int
process_cap_file(wtap *wth, const char *filename)
{
int err;
gchar *err_info;
gint64 size;
gint64 data_offset;
guint32 packet = 0;
gint64 bytes = 0;
guint32 snaplen_min_inferred = 0xffffffff;
guint32 snaplen_max_inferred = 0;
const struct wtap_pkthdr *phdr;
capture_info cf_info;
gboolean have_times = TRUE;
double start_time = 0;
double stop_time = 0;
double cur_time = 0;
double prev_time = 0;
gboolean know_order = FALSE;
order_t order = IN_ORDER;
cf_info.encap_counts = g_malloc0(WTAP_NUM_ENCAP_TYPES * sizeof(int));
while (wtap_read(wth, &err, &err_info, &data_offset)) {
phdr = wtap_phdr(wth);
if (phdr->presence_flags & WTAP_HAS_TS) {
prev_time = cur_time;
cur_time = secs_nsecs(&phdr->ts);
if(packet==0) {
start_time = cur_time;
stop_time = cur_time;
prev_time = cur_time;
}
if (cur_time < prev_time) {
order = NOT_IN_ORDER;
}
if (cur_time < start_time) {
start_time = cur_time;
}
if (cur_time > stop_time) {
stop_time = cur_time;
}
} else {
have_times = FALSE;
if (order != NOT_IN_ORDER)
order = ORDER_UNKNOWN;
}
bytes+=phdr->len;
packet++;
if (phdr->caplen < phdr->len) {
if (phdr->caplen < snaplen_min_inferred)
snaplen_min_inferred = phdr->caplen;
if (phdr->caplen > snaplen_max_inferred)
snaplen_max_inferred = phdr->caplen;
}
if (wtap_file_encap(wth) == WTAP_ENCAP_PER_PACKET) {
if ((phdr->pkt_encap > 0) && (phdr->pkt_encap < WTAP_NUM_ENCAP_TYPES)) {
cf_info.encap_counts[phdr->pkt_encap] += 1;
} else {
fprintf(stderr, "capinfos: Unknown per-packet encapsulation: %d [frame number: %d]\n", phdr->pkt_encap, packet);
}
}
}
if (err != 0) {
fprintf(stderr,
"capinfos: An error occurred after reading %u packets from \"%s\": %s.\n",
packet, filename, wtap_strerror(err));
switch (err) {
case WTAP_ERR_UNSUPPORTED:
case WTAP_ERR_UNSUPPORTED_ENCAP:
case WTAP_ERR_BAD_FILE:
case WTAP_ERR_DECOMPRESS:
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
break;
}
g_free(cf_info.encap_counts);
return 1;
}
size = wtap_file_size(wth, &err);
if (size == -1) {
fprintf(stderr,
"capinfos: Can't get size of \"%s\": %s.\n",
filename, g_strerror(err));
g_free(cf_info.encap_counts);
return 1;
}
cf_info.filesize = size;
cf_info.file_type = wtap_file_type(wth);
cf_info.iscompressed = wtap_iscompressed(wth);
cf_info.file_encap = wtap_file_encap(wth);
cf_info.snaplen = wtap_snapshot_length(wth);
if(cf_info.snaplen > 0)
cf_info.snap_set = TRUE;
else
cf_info.snap_set = FALSE;
cf_info.snaplen_min_inferred = snaplen_min_inferred;
cf_info.snaplen_max_inferred = snaplen_max_inferred;
cf_info.packet_count = packet;
cf_info.times_known = have_times;
cf_info.start_time = start_time;
cf_info.stop_time = stop_time;
cf_info.duration = stop_time-start_time;
cf_info.know_order = know_order;
cf_info.order = order;
cf_info.packet_bytes = bytes;
cf_info.data_rate = 0.0;
cf_info.packet_rate = 0.0;
cf_info.packet_size = 0.0;
if (packet > 0) {
if (cf_info.duration > 0.0) {
cf_info.data_rate = (double)bytes / (stop_time-start_time);
cf_info.packet_rate = (double)packet / (stop_time-start_time);
}
cf_info.packet_size = (double)bytes / packet;
}
if(long_report) {
print_stats(filename, &cf_info);
} else {
print_stats_table(filename, &cf_info);
}
g_free(cf_info.encap_counts);
return 0;
}
static void
usage(gboolean is_error)
{
FILE *output;
if (!is_error) {
output = stdout;
}
else {
output = stderr;
}
fprintf(output, "Capinfos %s"
#ifdef SVNVERSION
" (" SVNVERSION " from " SVNPATH ")"
#endif
"\n", VERSION);
fprintf(output, "Prints various information (infos) about capture files.\n");
fprintf(output, "See http://www.wireshark.org for more information.\n");
fprintf(output, "\n");
fprintf(output, "Usage: capinfos [options] <infile> ...\n");
fprintf(output, "\n");
fprintf(output, "General infos:\n");
fprintf(output, " -t display the capture file type\n");
fprintf(output, " -E display the capture file encapsulation\n");
#ifdef HAVE_LIBGCRYPT
fprintf(output, " -H display the SHA1, RMD160, and MD5 hashes of the file\n");
#endif
fprintf(output, "\n");
fprintf(output, "Size infos:\n");
fprintf(output, " -c display the number of packets\n");
fprintf(output, " -s display the size of the file (in bytes)\n");
fprintf(output, " -d display the total length of all packets (in bytes)\n");
fprintf(output, " -l display the packet size limit (snapshot length)\n");
fprintf(output, "\n");
fprintf(output, "Time infos:\n");
fprintf(output, " -u display the capture duration (in seconds)\n");
fprintf(output, " -a display the capture start time\n");
fprintf(output, " -e display the capture end time\n");
fprintf(output, " -o display the capture file chronological status (True/False)\n");
fprintf(output, " -S display start and end times as seconds\n");
fprintf(output, "\n");
fprintf(output, "Statistic infos:\n");
fprintf(output, " -y display average data rate (in bytes/sec)\n");
fprintf(output, " -i display average data rate (in bits/sec)\n");
fprintf(output, " -z display average packet size (in bytes)\n");
fprintf(output, " -x display average packet rate (in packets/sec)\n");
fprintf(output, "\n");
fprintf(output, "Output format:\n");
fprintf(output, " -L generate long report (default)\n");
fprintf(output, " -T generate table report\n");
fprintf(output, "\n");
fprintf(output, "Table report options:\n");
fprintf(output, " -R generate header record (default)\n");
fprintf(output, " -r do not generate header record\n");
fprintf(output, "\n");
fprintf(output, " -B separate infos with TAB character (default)\n");
fprintf(output, " -m separate infos with comma (,) character\n");
fprintf(output, " -b separate infos with SPACE character\n");
fprintf(output, "\n");
fprintf(output, " -N do not quote infos (default)\n");
fprintf(output, " -q quote infos with single quotes (')\n");
fprintf(output, " -Q quote infos with double quotes (\")\n");
fprintf(output, "\n");
fprintf(output, "Miscellaneous:\n");
fprintf(output, " -h display this help and exit\n");
fprintf(output, " -C cancel processing if file open fails (default is to continue)\n");
fprintf(output, " -A generate all infos (default)\n");
fprintf(output, "\n");
fprintf(output, "Options are processed from left to right order with later options superceeding\n");
fprintf(output, "or adding to earlier options.\n");
fprintf(output, "\n");
fprintf(output, "If no options are given the default is to display all infos in long report\n");
fprintf(output, "output format.\n");
#ifndef HAVE_LIBGCRYPT
fprintf(output, "\nFile hashing support (-H) is not present.\n");
#endif
}
static void
failure_message(const char *msg_format _U_, va_list ap _U_)
{
return;
}
static void
hash_to_str(const unsigned char *hash, size_t length, char *str) {
int i;
for (i = 0; i < (int) length; i++) {
g_snprintf(str+(i*2), 3, "%02x", hash[i]);
}
}
int
main(int argc, char *argv[])
{
wtap *wth;
int err;
gchar *err_info;
int opt;
int overall_error_status;
int status = 0;
#ifdef HAVE_PLUGINS
char *init_progfile_dir_error;
#endif
#ifdef HAVE_LIBGCRYPT
FILE *fh;
char *hash_buf = NULL;
gcry_md_hd_t hd = NULL;
size_t hash_bytes;
#endif
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
#endif
init_process_policies();
#ifdef HAVE_PLUGINS
if ((init_progfile_dir_error = init_progfile_dir(argv[0], main))) {
g_warning("capinfos: init_progfile_dir(): %s", init_progfile_dir_error);
g_free(init_progfile_dir_error);
} else {
init_report_err(failure_message,NULL,NULL,NULL);
init_plugins();
}
#endif
while ((opt = getopt(argc, argv, "tEcs" FILE_HASH_OPT "dluaeyizvhxoCALTRrSNqQBmb")) !=-1) {
switch (opt) {
case 't':
if (report_all_infos) disable_all_infos();
cap_file_type = TRUE;
break;
case 'E':
if (report_all_infos) disable_all_infos();
cap_file_encap = TRUE;
break;
case 'l':
if (report_all_infos) disable_all_infos();
cap_snaplen = TRUE;
break;
case 'c':
if (report_all_infos) disable_all_infos();
cap_packet_count = TRUE;
break;
case 's':
if (report_all_infos) disable_all_infos();
cap_file_size = TRUE;
break;
case 'd':
if (report_all_infos) disable_all_infos();
cap_data_size = TRUE;
break;
case 'u':
if (report_all_infos) disable_all_infos();
cap_duration = TRUE;
break;
case 'a':
if (report_all_infos) disable_all_infos();
cap_start_time = TRUE;
break;
case 'e':
if (report_all_infos) disable_all_infos();
cap_end_time = TRUE;
break;
case 'S':
time_as_secs = TRUE;
break;
case 'y':
if (report_all_infos) disable_all_infos();
cap_data_rate_byte = TRUE;
break;
case 'i':
if (report_all_infos) disable_all_infos();
cap_data_rate_bit = TRUE;
break;
case 'z':
if (report_all_infos) disable_all_infos();
cap_packet_size = TRUE;
break;
case 'x':
if (report_all_infos) disable_all_infos();
cap_packet_rate = TRUE;
break;
#ifdef HAVE_LIBGCRYPT
case 'H':
if (report_all_infos) disable_all_infos();
cap_file_hashes = TRUE;
break;
#endif
case 'o':
if (report_all_infos) disable_all_infos();
cap_order = TRUE;
break;
case 'C':
continue_after_wtap_open_offline_failure = FALSE;
break;
case 'A':
enable_all_infos();
break;
case 'L':
long_report = TRUE;
break;
case 'T':
long_report = FALSE;
break;
case 'R':
table_report_header = TRUE;
break;
case 'r':
table_report_header = FALSE;
break;
case 'N':
quote_char = '\0';
break;
case 'q':
quote_char = '\'';
break;
case 'Q':
quote_char = '"';
break;
case 'B':
field_separator = '\t';
break;
case 'm':
field_separator = ',';
break;
case 'b':
field_separator = ' ';
break;
case 'h':
usage(FALSE);
exit(1);
break;
case '?':
usage(TRUE);
exit(1);
break;
}
}
if ((argc - optind) < 1) {
usage(TRUE);
exit(1);
}
if(!long_report && table_report_header) {
print_stats_table_header();
}
#ifdef HAVE_LIBGCRYPT
if (cap_file_hashes) {
gcry_check_version(NULL);
gcry_md_open(&hd, GCRY_MD_SHA1, 0);
if (hd) {
gcry_md_enable(hd, GCRY_MD_RMD160);
gcry_md_enable(hd, GCRY_MD_MD5);
}
hash_buf = (char *)g_malloc(HASH_BUF_SIZE);
}
#endif
overall_error_status = 0;
for (opt = optind; opt < argc; opt++) {
#ifdef HAVE_LIBGCRYPT
g_strlcpy(file_sha1, "<unknown>", HASH_STR_SIZE);
g_strlcpy(file_rmd160, "<unknown>", HASH_STR_SIZE);
g_strlcpy(file_md5, "<unknown>", HASH_STR_SIZE);
if (cap_file_hashes) {
fh = ws_fopen(argv[opt], "rb");
if (fh && hd) {
while((hash_bytes = fread(hash_buf, 1, HASH_BUF_SIZE, fh)) > 0) {
gcry_md_write(hd, hash_buf, hash_bytes);
}
gcry_md_final(hd);
hash_to_str(gcry_md_read(hd, GCRY_MD_SHA1), HASH_SIZE_SHA1, file_sha1);
hash_to_str(gcry_md_read(hd, GCRY_MD_RMD160), HASH_SIZE_RMD160, file_rmd160);
hash_to_str(gcry_md_read(hd, GCRY_MD_MD5), HASH_SIZE_MD5, file_md5);
}
if (fh) fclose(fh);
if (hd) gcry_md_reset(hd);
}
#endif
wth = wtap_open_offline(argv[opt], &err, &err_info, FALSE);
if (!wth) {
fprintf(stderr, "capinfos: Can't open %s: %s\n", argv[opt],
wtap_strerror(err));
switch (err) {
case WTAP_ERR_UNSUPPORTED:
case WTAP_ERR_UNSUPPORTED_ENCAP:
case WTAP_ERR_BAD_FILE:
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
break;
}
overall_error_status = 1;
if(!continue_after_wtap_open_offline_failure)
exit(1);
}
if(wth) {
if ((opt > optind) && (long_report))
printf("\n");
status = process_cap_file(wth, argv[opt]);
wtap_close(wth);
if (status)
exit(status);
}
}
return overall_error_status;
}
