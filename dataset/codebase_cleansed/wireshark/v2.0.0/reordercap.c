static void
print_usage(FILE *output)
{
fprintf(output, "\n");
fprintf(output, "Usage: reordercap [options] <infile> <outfile>\n");
fprintf(output, "\n");
fprintf(output, "Options:\n");
fprintf(output, " -n don't write to output file if the input file is ordered.\n");
fprintf(output, " -h display this help and exit.\n");
}
static void
frame_write(FrameRecord_t *frame, wtap *wth, wtap_dumper *pdh,
struct wtap_pkthdr *phdr, Buffer *buf, const char *infile)
{
int err;
gchar *err_info;
DEBUG_PRINT("\nDumping frame (offset=%" G_GINT64_MODIFIER "u)\n",
frame->offset);
if (!wtap_seek_read(wth, frame->offset, phdr, buf, &err, &err_info)) {
if (err != 0) {
fprintf(stderr,
"reordercap: An error occurred while re-reading \"%s\": %s.\n",
infile, wtap_strerror(err));
if (err_info != NULL) {
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
}
exit(1);
}
}
phdr->ts = frame->frame_time;
if (!wtap_dump(pdh, phdr, ws_buffer_start_ptr(buf), &err, &err_info)) {
fprintf(stderr, "reordercap: Error (%s) writing frame to outfile\n",
wtap_strerror(err));
if (err_info != NULL) {
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
}
exit(1);
}
}
static int
frames_compare(gconstpointer a, gconstpointer b)
{
const FrameRecord_t *frame1 = *(const FrameRecord_t *const *) a;
const FrameRecord_t *frame2 = *(const FrameRecord_t *const *) b;
const nstime_t *time1 = &frame1->frame_time;
const nstime_t *time2 = &frame2->frame_time;
return nstime_cmp(time1, time2);
}
static void
get_reordercap_compiled_info(GString *str)
{
g_string_append(str, ", ");
#ifdef HAVE_LIBZ
g_string_append(str, "with libz ");
#ifdef ZLIB_VERSION
g_string_append(str, ZLIB_VERSION);
#else
g_string_append(str, "(version unknown)");
#endif
#else
g_string_append(str, "without libz");
#endif
}
static void
get_reordercap_runtime_info(GString *str)
{
#if defined(HAVE_LIBZ) && !defined(_WIN32)
g_string_append_printf(str, ", with libz %s", zlibVersion());
#endif
}
int
main(int argc, char *argv[])
{
GString *comp_info_str;
GString *runtime_info_str;
wtap *wth = NULL;
wtap_dumper *pdh = NULL;
struct wtap_pkthdr dump_phdr;
Buffer buf;
int err;
gchar *err_info;
gint64 data_offset;
const struct wtap_pkthdr *phdr;
guint wrong_order_count = 0;
gboolean write_output_regardless = TRUE;
guint i;
wtapng_section_t *shb_hdr = NULL;
wtapng_iface_descriptions_t *idb_inf = NULL;
wtapng_name_res_t *nrb_hdr = NULL;
GPtrArray *frames;
FrameRecord_t *prevFrame = NULL;
int opt;
DIAG_OFF(cast-qual)
static const struct option long_options[] = {
{(char *)"help", no_argument, NULL, 'h'},
{(char *)"version", no_argument, NULL, 'v'},
{0, 0, 0, 0 }
};
DIAG_ON(cast-qual)
int file_count;
char *infile;
const char *outfile;
comp_info_str = get_compiled_version_info(NULL, get_reordercap_compiled_info);
runtime_info_str = get_runtime_version_info(get_reordercap_runtime_info);
ws_add_crash_info("Reordercap (Wireshark) %s\n"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), comp_info_str->str, runtime_info_str->str);
while ((opt = getopt_long(argc, argv, "hnv", long_options, NULL)) != -1) {
switch (opt) {
case 'n':
write_output_regardless = FALSE;
break;
case 'h':
printf("Reordercap (Wireshark) %s\n"
"Reorder timestamps of input file frames into output file.\n"
"See https://www.wireshark.org for more information.\n",
get_ws_vcs_version_info());
print_usage(stdout);
exit(0);
case 'v':
show_version("Reordercap (Wireshark)", comp_info_str, runtime_info_str);
g_string_free(comp_info_str, TRUE);
g_string_free(runtime_info_str, TRUE);
exit(0);
case '?':
print_usage(stderr);
exit(1);
}
}
file_count = argc - optind;
if (file_count == 2) {
infile = argv[optind];
outfile = argv[optind+1];
}
else {
print_usage(stderr);
exit(1);
}
wth = wtap_open_offline(infile, WTAP_TYPE_AUTO, &err, &err_info, TRUE);
if (wth == NULL) {
fprintf(stderr, "reordercap: Can't open %s: %s\n", infile,
wtap_strerror(err));
if (err_info != NULL) {
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
}
exit(1);
}
DEBUG_PRINT("file_type_subtype is %u\n", wtap_file_type_subtype(wth));
shb_hdr = wtap_file_get_shb_for_new_file(wth);
idb_inf = wtap_file_get_idb_info(wth);
nrb_hdr = wtap_file_get_nrb_for_new_file(wth);
if (strcmp(outfile, "-") == 0) {
pdh = wtap_dump_open_stdout_ng(wtap_file_type_subtype(wth), wtap_file_encap(wth),
65535, FALSE, shb_hdr, idb_inf, nrb_hdr, &err);
outfile = "standard output";
} else {
pdh = wtap_dump_open_ng(outfile, wtap_file_type_subtype(wth), wtap_file_encap(wth),
65535, FALSE, shb_hdr, idb_inf, nrb_hdr, &err);
}
g_free(idb_inf);
idb_inf = NULL;
if (pdh == NULL) {
fprintf(stderr, "reordercap: Failed to open output file: (%s) - error %s\n",
outfile, wtap_strerror(err));
wtap_free_shb(shb_hdr);
wtap_free_nrb(nrb_hdr);
exit(1);
}
frames = g_ptr_array_new();
while (wtap_read(wth, &err, &err_info, &data_offset)) {
FrameRecord_t *newFrameRecord;
phdr = wtap_phdr(wth);
newFrameRecord = g_slice_new(FrameRecord_t);
newFrameRecord->num = frames->len + 1;
newFrameRecord->offset = data_offset;
if (phdr->presence_flags & WTAP_HAS_TS) {
newFrameRecord->frame_time = phdr->ts;
} else {
nstime_set_unset(&newFrameRecord->frame_time);
}
if (prevFrame && frames_compare(&newFrameRecord, &prevFrame) < 0) {
wrong_order_count++;
}
g_ptr_array_add(frames, newFrameRecord);
prevFrame = newFrameRecord;
}
if (err != 0) {
fprintf(stderr,
"reordercap: An error occurred while reading \"%s\": %s.\n",
infile, wtap_strerror(err));
if (err_info != NULL) {
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
}
}
printf("%u frames, %u out of order\n", frames->len, wrong_order_count);
if (wrong_order_count > 0) {
g_ptr_array_sort(frames, frames_compare);
}
wtap_phdr_init(&dump_phdr);
ws_buffer_init(&buf, 1500);
for (i = 0; i < frames->len; i++) {
FrameRecord_t *frame = (FrameRecord_t *)frames->pdata[i];
if (write_output_regardless || (wrong_order_count > 0)) {
frame_write(frame, wth, pdh, &dump_phdr, &buf, infile);
}
g_slice_free(FrameRecord_t, frame);
}
wtap_phdr_cleanup(&dump_phdr);
ws_buffer_free(&buf);
if (!write_output_regardless && (wrong_order_count == 0)) {
printf("Not writing output file because input file is already in order!\n");
}
g_ptr_array_free(frames, TRUE);
if (!wtap_dump_close(pdh, &err)) {
fprintf(stderr, "reordercap: Error closing %s: %s\n", outfile,
wtap_strerror(err));
wtap_free_shb(shb_hdr);
wtap_free_nrb(nrb_hdr);
exit(1);
}
wtap_free_shb(shb_hdr);
wtap_free_nrb(nrb_hdr);
wtap_fdclose(wth);
return 0;
}
