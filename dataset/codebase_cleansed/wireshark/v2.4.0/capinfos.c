static void
enable_all_infos(void)
{
report_all_infos = TRUE;
cap_file_type = TRUE;
cap_file_encap = TRUE;
cap_snaplen = TRUE;
cap_packet_count = TRUE;
cap_file_size = TRUE;
cap_comment = TRUE;
cap_file_more_info = TRUE;
cap_file_idb = TRUE;
cap_data_size = TRUE;
cap_duration = TRUE;
cap_start_time = TRUE;
cap_end_time = TRUE;
cap_order = TRUE;
cap_data_rate_byte = TRUE;
cap_data_rate_bit = TRUE;
cap_packet_size = TRUE;
cap_packet_rate = TRUE;
cap_file_hashes = TRUE;
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
cap_comment = FALSE;
cap_file_more_info = FALSE;
cap_file_idb = FALSE;
cap_data_size = FALSE;
cap_duration = FALSE;
cap_start_time = FALSE;
cap_end_time = FALSE;
cap_order = FALSE;
cap_data_rate_byte = FALSE;
cap_data_rate_bit = FALSE;
cap_packet_size = FALSE;
cap_packet_rate = FALSE;
cap_file_hashes = FALSE;
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
absolute_time_string(nstime_t *timer, int tsprecision, capture_info *cf_info)
{
static gchar time_string_buf[4+1+2+1+2+1+2+1+2+1+2+1+9+1+1];
struct tm *ti_tm;
if (cf_info->times_known && cf_info->packet_count > 0) {
if (time_as_secs) {
switch (tsprecision) {
case WTAP_TSPREC_SEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu",
(unsigned long)timer->secs);
break;
case WTAP_TSPREC_DSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu%s%01d",
(unsigned long)timer->secs,
decimal_point,
timer->nsecs / 100000000);
break;
case WTAP_TSPREC_CSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu%s%02d",
(unsigned long)timer->secs,
decimal_point,
timer->nsecs / 10000000);
break;
case WTAP_TSPREC_MSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu%s%03d",
(unsigned long)timer->secs,
decimal_point,
timer->nsecs / 1000000);
break;
case WTAP_TSPREC_USEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu%s%06d",
(unsigned long)timer->secs,
decimal_point,
timer->nsecs / 1000);
break;
case WTAP_TSPREC_NSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu%s%09d",
(unsigned long)timer->secs,
decimal_point,
timer->nsecs);
break;
default:
g_snprintf(time_string_buf, sizeof time_string_buf,
"Unknown precision %d",
tsprecision);
break;
}
return time_string_buf;
} else {
ti_tm = localtime(&timer->secs);
if (ti_tm == NULL) {
g_snprintf(time_string_buf, sizeof time_string_buf, "Not representable");
return time_string_buf;
}
switch (tsprecision) {
case WTAP_TSPREC_SEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%04d-%02d-%02d %02d:%02d:%02d",
ti_tm->tm_year + 1900,
ti_tm->tm_mon + 1,
ti_tm->tm_mday,
ti_tm->tm_hour,
ti_tm->tm_min,
ti_tm->tm_sec);
break;
case WTAP_TSPREC_DSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%04d-%02d-%02d %02d:%02d:%02d%s%01d",
ti_tm->tm_year + 1900,
ti_tm->tm_mon + 1,
ti_tm->tm_mday,
ti_tm->tm_hour,
ti_tm->tm_min,
ti_tm->tm_sec,
decimal_point,
timer->nsecs / 100000000);
break;
case WTAP_TSPREC_CSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%04d-%02d-%02d %02d:%02d:%02d%s%02d",
ti_tm->tm_year + 1900,
ti_tm->tm_mon + 1,
ti_tm->tm_mday,
ti_tm->tm_hour,
ti_tm->tm_min,
ti_tm->tm_sec,
decimal_point,
timer->nsecs / 10000000);
break;
case WTAP_TSPREC_MSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%04d-%02d-%02d %02d:%02d:%02d%s%03d",
ti_tm->tm_year + 1900,
ti_tm->tm_mon + 1,
ti_tm->tm_mday,
ti_tm->tm_hour,
ti_tm->tm_min,
ti_tm->tm_sec,
decimal_point,
timer->nsecs / 1000000);
break;
case WTAP_TSPREC_USEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%04d-%02d-%02d %02d:%02d:%02d%s%06d",
ti_tm->tm_year + 1900,
ti_tm->tm_mon + 1,
ti_tm->tm_mday,
ti_tm->tm_hour,
ti_tm->tm_min,
ti_tm->tm_sec,
decimal_point,
timer->nsecs / 1000);
break;
case WTAP_TSPREC_NSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%04d-%02d-%02d %02d:%02d:%02d%s%09d",
ti_tm->tm_year + 1900,
ti_tm->tm_mon + 1,
ti_tm->tm_mday,
ti_tm->tm_hour,
ti_tm->tm_min,
ti_tm->tm_sec,
decimal_point,
timer->nsecs);
break;
default:
g_snprintf(time_string_buf, sizeof time_string_buf,
"Unknown precision %d",
tsprecision);
break;
}
return time_string_buf;
}
}
g_snprintf(time_string_buf, sizeof time_string_buf, "n/a");
return time_string_buf;
}
static gchar *
relative_time_string(nstime_t *timer, int tsprecision, capture_info *cf_info, gboolean want_seconds)
{
const gchar *second = want_seconds ? " second" : "";
const gchar *plural = want_seconds ? "s" : "";
static gchar time_string_buf[4+1+2+1+2+1+2+1+2+1+2+1+1];
if (cf_info->times_known && cf_info->packet_count > 0) {
switch (tsprecision) {
case WTAP_TSPREC_SEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu%s%s",
(unsigned long)timer->secs,
second,
timer->secs == 1 ? "" : plural);
break;
case WTAP_TSPREC_DSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu%s%01d%s%s",
(unsigned long)timer->secs,
decimal_point,
timer->nsecs / 100000000,
second,
(timer->secs == 1 && timer->nsecs == 0) ? "" : plural);
break;
case WTAP_TSPREC_CSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu%s%02d%s%s",
(unsigned long)timer->secs,
decimal_point,
timer->nsecs / 10000000,
second,
(timer->secs == 1 && timer->nsecs == 0) ? "" : plural);
break;
case WTAP_TSPREC_MSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu%s%03d%s%s",
(unsigned long)timer->secs,
decimal_point,
timer->nsecs / 1000000,
second,
(timer->secs == 1 && timer->nsecs == 0) ? "" : plural);
break;
case WTAP_TSPREC_USEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu%s%06d%s%s",
(unsigned long)timer->secs,
decimal_point,
timer->nsecs / 1000,
second,
(timer->secs == 1 && timer->nsecs == 0) ? "" : plural);
break;
case WTAP_TSPREC_NSEC:
g_snprintf(time_string_buf, sizeof time_string_buf,
"%lu%s%09d%s%s",
(unsigned long)timer->secs,
decimal_point,
timer->nsecs,
second,
(timer->secs == 1 && timer->nsecs == 0) ? "" : plural);
break;
default:
g_snprintf(time_string_buf, sizeof time_string_buf,
"Unknown precision %d",
tsprecision);
break;
}
return time_string_buf;
}
g_snprintf(time_string_buf, sizeof time_string_buf, "n/a");
return time_string_buf;
}
static void print_value(const gchar *text_p1, gint width, const gchar *text_p2, double value) {
if (value > 0.0)
printf("%s%.*f%s\n", text_p1, width, value, text_p2);
else
printf("%sn/a\n", text_p1);
}
static void
string_replace_newlines(gchar *str)
{
gchar *p;
if (str) {
p = str;
while (*p != '\0') {
if (*p == '\n')
*p = ' ';
if (*p == '\r')
*p = ' ';
p++;
}
}
}
static void
show_option_string(const char *prefix, const char *option_str)
{
char *str;
if (option_str != NULL && option_str[0] != '\0') {
str = g_strdup(option_str);
string_replace_newlines(str);
printf("%s%s\n", prefix, str);
g_free(str);
}
}
static void
print_stats(const gchar *filename, capture_info *cf_info)
{
const gchar *file_type_string, *file_encap_string;
gchar *size_string;
file_type_string = wtap_file_type_subtype_string(cf_info->file_type);
file_encap_string = wtap_encap_string(cf_info->file_encap);
if (filename) printf ("File name: %s\n", filename);
if (cap_file_type) printf ("File type: %s%s\n",
file_type_string,
cf_info->iscompressed ? " (gzip compressed)" : "");
if (cap_file_encap) {
printf ("File encapsulation: %s\n", file_encap_string);
if (cf_info->file_encap == WTAP_ENCAP_PER_PACKET) {
int i;
printf ("Encapsulation in use by packets (# of pkts):\n");
for (i=0; i<WTAP_NUM_ENCAP_TYPES; i++) {
if (cf_info->encap_counts[i] > 0)
printf(" %s (%d)\n",
wtap_encap_string(i), cf_info->encap_counts[i]);
}
}
}
if (cap_file_more_info) {
printf ("File timestamp precision: %s (%d)\n",
wtap_tsprec_string(cf_info->file_tsprec), cf_info->file_tsprec);
}
if (cap_snaplen && cf_info->snap_set)
printf ("Packet size limit: file hdr: %u bytes\n", cf_info->snaplen);
else if (cap_snaplen && !cf_info->snap_set)
printf ("Packet size limit: file hdr: (not set)\n");
if (cf_info->snaplen_max_inferred > 0) {
if (cf_info->snaplen_min_inferred == cf_info->snaplen_max_inferred)
printf ("Packet size limit: inferred: %u bytes\n", cf_info->snaplen_min_inferred);
else
printf ("Packet size limit: inferred: %u bytes - %u bytes (range)\n",
cf_info->snaplen_min_inferred, cf_info->snaplen_max_inferred);
}
if (cap_packet_count) {
printf ("Number of packets: ");
if (machine_readable) {
printf ("%u\n", cf_info->packet_count);
} else {
size_string = format_size(cf_info->packet_count, format_size_unit_none);
printf ("%s\n", size_string);
g_free(size_string);
}
}
if (cap_file_size) {
printf ("File size: ");
if (machine_readable) {
printf ("%" G_GINT64_MODIFIER "d bytes\n", cf_info->filesize);
} else {
size_string = format_size(cf_info->filesize, format_size_unit_bytes);
printf ("%s\n", size_string);
g_free(size_string);
}
}
if (cap_data_size) {
printf ("Data size: ");
if (machine_readable) {
printf ("%" G_GINT64_MODIFIER "u bytes\n", cf_info->packet_bytes);
} else {
size_string = format_size(cf_info->packet_bytes, format_size_unit_bytes);
printf ("%s\n", size_string);
g_free(size_string);
}
}
if (cf_info->times_known) {
if (cap_duration)
printf("Capture duration: %s\n", relative_time_string(&cf_info->duration, cf_info->duration_tsprec, cf_info, TRUE));
if (cap_start_time)
printf("First packet time: %s\n", absolute_time_string(&cf_info->start_time, cf_info->start_time_tsprec, cf_info));
if (cap_end_time)
printf("Last packet time: %s\n", absolute_time_string(&cf_info->stop_time, cf_info->stop_time_tsprec, cf_info));
if (cap_data_rate_byte) {
printf("Data byte rate: ");
if (machine_readable) {
print_value("", 2, " bytes/sec", cf_info->data_rate);
} else {
size_string = format_size((gint64)cf_info->data_rate, format_size_unit_bytes_s);
printf ("%s\n", size_string);
g_free(size_string);
}
}
if (cap_data_rate_bit) {
printf("Data bit rate: ");
if (machine_readable) {
print_value("", 2, " bits/sec", cf_info->data_rate*8);
} else {
size_string = format_size((gint64)(cf_info->data_rate*8), format_size_unit_bits_s);
printf ("%s\n", size_string);
g_free(size_string);
}
}
}
if (cap_packet_size) printf("Average packet size: %.2f bytes\n", cf_info->packet_size);
if (cf_info->times_known) {
if (cap_packet_rate) {
printf("Average packet rate: ");
if (machine_readable) {
print_value("", 2, " packets/sec", cf_info->packet_rate);
} else {
size_string = format_size((gint64)cf_info->packet_rate, format_size_unit_packets_s);
printf ("%s\n", size_string);
g_free(size_string);
}
}
}
if (cap_file_hashes) {
printf ("SHA1: %s\n", file_sha1);
printf ("RIPEMD160: %s\n", file_rmd160);
printf ("MD5: %s\n", file_md5);
}
if (cap_order) printf ("Strict time order: %s\n", order_string(cf_info->order));
if (cf_info->shb != NULL) {
if (cap_file_more_info) {
char *str;
if (wtap_block_get_string_option_value(cf_info->shb, OPT_SHB_HARDWARE, &str) == WTAP_OPTTYPE_SUCCESS)
show_option_string("Capture hardware: ", str);
if (wtap_block_get_string_option_value(cf_info->shb, OPT_SHB_OS, &str) == WTAP_OPTTYPE_SUCCESS)
show_option_string("Capture oper-sys: ", str);
if (wtap_block_get_string_option_value(cf_info->shb, OPT_SHB_USERAPPL, &str) == WTAP_OPTTYPE_SUCCESS)
show_option_string("Capture application: ", str);
}
if (cap_comment) {
unsigned int i;
char *str;
for (i = 0; wtap_block_get_nth_string_option_value(cf_info->shb, OPT_COMMENT, i, &str) == WTAP_OPTTYPE_SUCCESS; i++) {
show_option_string("Capture comment: ", str);
}
}
if (cap_file_idb && cf_info->num_interfaces != 0) {
guint i;
g_assert(cf_info->num_interfaces == cf_info->idb_info_strings->len);
printf ("Number of interfaces in file: %u\n", cf_info->num_interfaces);
for (i = 0; i < cf_info->idb_info_strings->len; i++) {
gchar *s = g_array_index(cf_info->idb_info_strings, gchar*, i);
guint32 packet_count = 0;
if (i < cf_info->interface_packet_counts->len)
packet_count = g_array_index(cf_info->interface_packet_counts, guint32, i);
printf ("Interface #%u info:\n", i);
printf ("%s", s);
printf (" Number of packets = %u\n", packet_count);
}
}
}
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
if (cap_file_more_info) print_stats_table_header_label("File time precision");
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
if (cap_file_hashes) {
print_stats_table_header_label("SHA1");
print_stats_table_header_label("RIPEMD160");
print_stats_table_header_label("MD5");
}
if (cap_order) print_stats_table_header_label("Strict time order");
if (cap_file_more_info) {
print_stats_table_header_label("Capture hardware");
print_stats_table_header_label("Capture oper-sys");
print_stats_table_header_label("Capture application");
}
if (cap_comment) print_stats_table_header_label("Capture comment");
printf("\n");
}
static void
print_stats_table(const gchar *filename, capture_info *cf_info)
{
const gchar *file_type_string, *file_encap_string;
file_type_string = wtap_file_type_subtype_string(cf_info->file_type);
file_encap_string = wtap_encap_string(cf_info->file_encap);
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
if (cap_file_more_info) {
putsep();
putquote();
printf("%s", wtap_tsprec_string(cf_info->file_tsprec));
putquote();
}
if (cap_snaplen) {
putsep();
putquote();
if (cf_info->snap_set)
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
printf("%s", relative_time_string(&cf_info->duration, cf_info->duration_tsprec, cf_info, FALSE));
putquote();
}
if (cap_start_time) {
putsep();
putquote();
printf("%s", absolute_time_string(&cf_info->start_time, cf_info->start_time_tsprec, cf_info));
putquote();
}
if (cap_end_time) {
putsep();
putquote();
printf("%s", absolute_time_string(&cf_info->stop_time, cf_info->stop_time_tsprec, cf_info));
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
if (cap_order) {
putsep();
putquote();
printf("%s", order_string(cf_info->order));
putquote();
}
if (cf_info->shb != NULL) {
if (cap_file_more_info) {
char *str;
putsep();
putquote();
if (wtap_block_get_string_option_value(cf_info->shb, OPT_SHB_HARDWARE, &str) == WTAP_OPTTYPE_SUCCESS) {
printf("%s", str);
}
putquote();
putsep();
putquote();
if (wtap_block_get_string_option_value(cf_info->shb, OPT_SHB_OS, &str) == WTAP_OPTTYPE_SUCCESS) {
printf("%s", str);
}
putquote();
putsep();
putquote();
if (wtap_block_get_string_option_value(cf_info->shb, OPT_SHB_USERAPPL, &str) == WTAP_OPTTYPE_SUCCESS) {
printf("%s", str);
}
putquote();
}
if (cap_comment) {
unsigned int i;
char *opt_comment;
gboolean have_cap = FALSE;
for (i = 0; wtap_block_get_nth_string_option_value(cf_info->shb, OPT_COMMENT, i, &opt_comment) == WTAP_OPTTYPE_SUCCESS; i++) {
have_cap = TRUE;
putsep();
putquote();
printf("%s", opt_comment);
putquote();
}
if(!have_cap) {
putsep();
putquote();
putquote();
}
}
}
printf("\n");
}
static void
cleanup_capture_info(capture_info *cf_info)
{
guint i;
g_assert(cf_info != NULL);
g_free(cf_info->encap_counts);
cf_info->encap_counts = NULL;
g_array_free(cf_info->interface_packet_counts, TRUE);
cf_info->interface_packet_counts = NULL;
if (cf_info->idb_info_strings) {
for (i = 0; i < cf_info->idb_info_strings->len; i++) {
gchar *s = g_array_index(cf_info->idb_info_strings, gchar*, i);
g_free(s);
}
g_array_free(cf_info->idb_info_strings, TRUE);
}
cf_info->idb_info_strings = NULL;
}
static int
process_cap_file(wtap *wth, const char *filename)
{
int status = 0;
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
nstime_t start_time;
int start_time_tsprec;
nstime_t stop_time;
int stop_time_tsprec;
nstime_t cur_time;
nstime_t prev_time;
gboolean know_order = FALSE;
order_t order = IN_ORDER;
guint i;
wtapng_iface_descriptions_t *idb_info;
g_assert(wth != NULL);
g_assert(filename != NULL);
nstime_set_zero(&start_time);
start_time_tsprec = WTAP_TSPREC_UNKNOWN;
nstime_set_zero(&stop_time);
stop_time_tsprec = WTAP_TSPREC_UNKNOWN;
nstime_set_zero(&cur_time);
nstime_set_zero(&prev_time);
cf_info.shb = wtap_file_get_shb(wth);
cf_info.encap_counts = g_new0(int,WTAP_NUM_ENCAP_TYPES);
idb_info = wtap_file_get_idb_info(wth);
g_assert(idb_info->interface_data != NULL);
cf_info.num_interfaces = idb_info->interface_data->len;
cf_info.interface_packet_counts = g_array_sized_new(FALSE, TRUE, sizeof(guint32), cf_info.num_interfaces);
g_array_set_size(cf_info.interface_packet_counts, cf_info.num_interfaces);
cf_info.pkt_interface_id_unknown = 0;
g_free(idb_info);
idb_info = NULL;
while (wtap_read(wth, &err, &err_info, &data_offset)) {
phdr = wtap_phdr(wth);
if (phdr->presence_flags & WTAP_HAS_TS) {
prev_time = cur_time;
cur_time = phdr->ts;
if (packet == 0) {
start_time = phdr->ts;
start_time_tsprec = phdr->pkt_tsprec;
stop_time = phdr->ts;
stop_time_tsprec = phdr->pkt_tsprec;
prev_time = phdr->ts;
}
if (nstime_cmp(&cur_time, &prev_time) < 0) {
order = NOT_IN_ORDER;
}
if (nstime_cmp(&cur_time, &start_time) < 0) {
start_time = cur_time;
start_time_tsprec = phdr->pkt_tsprec;
}
if (nstime_cmp(&cur_time, &stop_time) > 0) {
stop_time = cur_time;
stop_time_tsprec = phdr->pkt_tsprec;
}
} else {
have_times = FALSE;
if (order != NOT_IN_ORDER)
order = ORDER_UNKNOWN;
}
if (phdr->rec_type == REC_TYPE_PACKET) {
bytes+=phdr->len;
packet++;
if (phdr->caplen < phdr->len) {
if (phdr->caplen < snaplen_min_inferred)
snaplen_min_inferred = phdr->caplen;
if (phdr->caplen > snaplen_max_inferred)
snaplen_max_inferred = phdr->caplen;
}
if ((phdr->pkt_encap > 0) && (phdr->pkt_encap < WTAP_NUM_ENCAP_TYPES)) {
cf_info.encap_counts[phdr->pkt_encap] += 1;
} else {
fprintf(stderr, "capinfos: Unknown packet encapsulation %d in frame %u of file \"%s\"\n",
phdr->pkt_encap, packet, filename);
}
if (phdr->presence_flags & WTAP_HAS_INTERFACE_ID) {
if (phdr->interface_id >= cf_info.num_interfaces) {
idb_info = wtap_file_get_idb_info(wth);
cf_info.num_interfaces = idb_info->interface_data->len;
g_array_set_size(cf_info.interface_packet_counts, cf_info.num_interfaces);
g_free(idb_info);
idb_info = NULL;
}
if (phdr->interface_id < cf_info.num_interfaces) {
g_array_index(cf_info.interface_packet_counts, guint32, phdr->interface_id) += 1;
}
else {
cf_info.pkt_interface_id_unknown += 1;
}
}
else {
if (cf_info.num_interfaces != 0) {
g_array_index(cf_info.interface_packet_counts, guint32, 0) += 1;
}
else {
cf_info.pkt_interface_id_unknown += 1;
}
}
}
}
idb_info = wtap_file_get_idb_info(wth);
cf_info.idb_info_strings = g_array_sized_new(FALSE, FALSE, sizeof(gchar*), cf_info.num_interfaces);
cf_info.num_interfaces = idb_info->interface_data->len;
for (i = 0; i < cf_info.num_interfaces; i++) {
const wtap_block_t if_descr = g_array_index(idb_info->interface_data, wtap_block_t, i);
gchar *s = wtap_get_debug_if_descr(if_descr, 21, "\n");
g_array_append_val(cf_info.idb_info_strings, s);
}
g_free(idb_info);
idb_info = NULL;
if (err != 0) {
fprintf(stderr,
"capinfos: An error occurred after reading %u packets from \"%s\".\n",
packet, filename);
cfile_read_failure_message("capinfos", filename, err, err_info);
if (err == WTAP_ERR_SHORT_READ) {
status = 1;
fprintf(stderr,
" (will continue anyway, checksums might be incorrect)\n");
} else {
cleanup_capture_info(&cf_info);
return 1;
}
}
size = wtap_file_size(wth, &err);
if (size == -1) {
fprintf(stderr,
"capinfos: Can't get size of \"%s\": %s.\n",
filename, g_strerror(err));
cleanup_capture_info(&cf_info);
return 1;
}
cf_info.filesize = size;
cf_info.file_type = wtap_file_type_subtype(wth);
cf_info.iscompressed = wtap_iscompressed(wth);
cf_info.file_encap = wtap_file_encap(wth);
cf_info.file_tsprec = wtap_file_tsprec(wth);
cf_info.snaplen = wtap_snapshot_length(wth);
if (cf_info.snaplen > 0)
cf_info.snap_set = TRUE;
else
cf_info.snap_set = FALSE;
cf_info.snaplen_min_inferred = snaplen_min_inferred;
cf_info.snaplen_max_inferred = snaplen_max_inferred;
cf_info.packet_count = packet;
cf_info.times_known = have_times;
cf_info.start_time = start_time;
cf_info.start_time_tsprec = start_time_tsprec;
cf_info.stop_time = stop_time;
cf_info.stop_time_tsprec = stop_time_tsprec;
nstime_delta(&cf_info.duration, &stop_time, &start_time);
if (cf_info.stop_time_tsprec > cf_info.start_time_tsprec)
cf_info.duration_tsprec = cf_info.stop_time_tsprec;
else
cf_info.duration_tsprec = cf_info.start_time_tsprec;
cf_info.know_order = know_order;
cf_info.order = order;
cf_info.packet_bytes = bytes;
cf_info.data_rate = 0.0;
cf_info.packet_rate = 0.0;
cf_info.packet_size = 0.0;
if (packet > 0) {
double delta_time = nstime_to_sec(&stop_time) - nstime_to_sec(&start_time);
if (delta_time > 0.0) {
cf_info.data_rate = (double)bytes / delta_time;
cf_info.packet_rate = (double)packet / delta_time;
}
cf_info.packet_size = (double)bytes / packet;
}
if (long_report) {
print_stats(filename, &cf_info);
} else {
print_stats_table(filename, &cf_info);
}
cleanup_capture_info(&cf_info);
return status;
}
static void
print_usage(FILE *output)
{
fprintf(output, "\n");
fprintf(output, "Usage: capinfos [options] <infile> ...\n");
fprintf(output, "\n");
fprintf(output, "General infos:\n");
fprintf(output, " -t display the capture file type\n");
fprintf(output, " -E display the capture file encapsulation\n");
fprintf(output, " -I display the capture file interface information\n");
fprintf(output, " -F display additional capture file information\n");
fprintf(output, " -H display the SHA1, RMD160, and MD5 hashes of the file\n");
fprintf(output, " -k display the capture comment\n");
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
fprintf(output, " -M display machine-readable values in long reports\n");
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
fprintf(output, " -K disable displaying the capture comment\n");
fprintf(output, "\n");
fprintf(output, "Options are processed from left to right order with later options superceding\n");
fprintf(output, "or adding to earlier options.\n");
fprintf(output, "\n");
fprintf(output, "If no options are given the default is to display all infos in long report\n");
fprintf(output, "output format.\n");
}
static void
failure_warning_message(const char *msg_format, va_list ap)
{
fprintf(stderr, "capinfos: ");
vfprintf(stderr, msg_format, ap);
fprintf(stderr, "\n");
}
static void
failure_message_cont(const char *msg_format, va_list ap)
{
vfprintf(stderr, msg_format, ap);
fprintf(stderr, "\n");
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
GString *comp_info_str;
GString *runtime_info_str;
char *init_progfile_dir_error;
wtap *wth;
int err;
gchar *err_info;
int opt;
int overall_error_status = EXIT_SUCCESS;
static const struct option long_options[] = {
{"help", no_argument, NULL, 'h'},
{"version", no_argument, NULL, 'v'},
{0, 0, 0, 0 }
};
int status = 0;
FILE *fh;
char *hash_buf = NULL;
gcry_md_hd_t hd = NULL;
size_t hash_bytes;
setlocale(LC_ALL, "");
cmdarg_err_init(failure_warning_message, failure_message_cont);
decimal_point = g_strdup(localeconv()->decimal_point);
comp_info_str = get_compiled_version_info(NULL, NULL);
runtime_info_str = get_runtime_version_info(NULL);
ws_add_crash_info("Capinfos (Wireshark) %s\n"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), comp_info_str->str, runtime_info_str->str);
g_string_free(comp_info_str, TRUE);
g_string_free(runtime_info_str, TRUE);
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
#endif
init_process_policies();
init_progfile_dir_error = init_progfile_dir(argv[0], main);
if (init_progfile_dir_error != NULL) {
fprintf(stderr,
"capinfos: Can't get pathname of directory containing the capinfos program: %s.\n",
init_progfile_dir_error);
g_free(init_progfile_dir_error);
}
wtap_init();
#ifdef HAVE_PLUGINS
init_report_message(failure_warning_message, failure_warning_message,
NULL, NULL, NULL);
scan_plugins(DONT_REPORT_LOAD_FAILURE);
register_all_wiretap_modules();
#endif
while ((opt = getopt_long(argc, argv, "abcdehiklmoqrstuvxyzABCEFHIKLMNQRST", long_options, NULL)) !=-1) {
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
case 'H':
if (report_all_infos) disable_all_infos();
cap_file_hashes = TRUE;
break;
case 'o':
if (report_all_infos) disable_all_infos();
cap_order = TRUE;
break;
case 'k':
if (report_all_infos) disable_all_infos();
cap_comment = TRUE;
break;
case 'K':
cap_comment = FALSE;
break;
case 'F':
if (report_all_infos) disable_all_infos();
cap_file_more_info = TRUE;
break;
case 'I':
if (report_all_infos) disable_all_infos();
cap_file_idb = TRUE;
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
case 'M':
machine_readable = TRUE;
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
printf("Capinfos (Wireshark) %s\n"
"Print various information (infos) about capture files.\n"
"See https://www.wireshark.org for more information.\n",
get_ws_vcs_version_info());
print_usage(stdout);
goto exit;
break;
case 'v':
comp_info_str = get_compiled_version_info(NULL, NULL);
runtime_info_str = get_runtime_version_info(NULL);
show_version("Capinfos (Wireshark)", comp_info_str, runtime_info_str);
g_string_free(comp_info_str, TRUE);
g_string_free(runtime_info_str, TRUE);
goto exit;
break;
case '?':
print_usage(stderr);
overall_error_status = BAD_FLAG;
goto exit;
break;
}
}
if ((argc - optind) < 1) {
print_usage(stderr);
overall_error_status = INVALID_OPTION;
goto exit;
}
if (!long_report && table_report_header) {
print_stats_table_header();
}
if (cap_file_hashes) {
gcry_check_version(NULL);
gcry_md_open(&hd, GCRY_MD_SHA1, 0);
if (hd) {
gcry_md_enable(hd, GCRY_MD_RMD160);
gcry_md_enable(hd, GCRY_MD_MD5);
}
hash_buf = (char *)g_malloc(HASH_BUF_SIZE);
}
overall_error_status = 0;
for (opt = optind; opt < argc; opt++) {
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
wth = wtap_open_offline(argv[opt], WTAP_TYPE_AUTO, &err, &err_info, FALSE);
if (!wth) {
cfile_open_failure_message("capinfos", argv[opt], err, err_info);
overall_error_status = 2;
if (!continue_after_wtap_open_offline_failure)
goto exit;
}
if (wth) {
if ((opt > optind) && (long_report))
printf("\n");
status = process_cap_file(wth, argv[opt]);
wtap_close(wth);
if (status) {
overall_error_status = status;
goto exit;
}
}
}
exit:
g_free(hash_buf);
wtap_cleanup();
free_progdirs();
#ifdef HAVE_PLUGINS
plugins_cleanup();
#endif
return overall_error_status;
}
