static void usage(void)
{
fprintf(stderr, "Reordercap %s"
#ifdef SVNVERSION
" (" SVNVERSION " from " SVNPATH ")"
#endif
"\n", VERSION);
fprintf(stderr, "Reorder timestamps of input file frames into output file.\n");
fprintf(stderr, "See http://www.wireshark.org for more information.\n");
fprintf(stderr, "\n");
fprintf(stderr, "Usage: reordercap [options] <infile> <outfile>\n");
fprintf(stderr, "\n");
fprintf(stderr, "Options:\n");
fprintf(stderr, " -n don't write to output file if the input file is ordered.\n");
}
static void
frame_write(FrameRecord_t *frame, wtap *wth, wtap_dumper *pdh, Buffer *buf,
const char *infile)
{
int err;
gchar *err_info;
struct wtap_pkthdr phdr;
DEBUG_PRINT("\nDumping frame (offset=%" G_GINT64_MODIFIER "u, length=%u)\n",
frame->offset, frame->length);
if (!wtap_seek_read(wth, frame->offset, &phdr, buf, frame->length,
&err, &err_info)) {
if (err != 0) {
fprintf(stderr,
"reordercap: An error occurred while re-reading \"%s\": %s.\n",
infile, wtap_strerror(err));
switch (err) {
case WTAP_ERR_UNSUPPORTED:
case WTAP_ERR_UNSUPPORTED_ENCAP:
case WTAP_ERR_BAD_FILE:
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
break;
}
exit(1);
}
}
phdr.ts = frame->time;
if (!wtap_dump(pdh, &phdr, buffer_start_ptr(buf), &err)) {
fprintf(stderr, "reordercap: Error (%s) writing frame to outfile\n",
wtap_strerror(err));
exit(1);
}
}
static int
frames_compare(gconstpointer a, gconstpointer b)
{
const FrameRecord_t *frame1 = *(const FrameRecord_t **) a;
const FrameRecord_t *frame2 = *(const FrameRecord_t **) b;
const struct wtap_nstime *time1 = &frame1->time;
const struct wtap_nstime *time2 = &frame2->time;
if (time1->secs > time2->secs)
return 1;
if (time1->secs < time2->secs)
return -1;
if (time1->nsecs > time2->nsecs)
return 1;
if (time1->nsecs < time2->nsecs)
return -1;
if (frame1->num > frame2->num)
return 1;
if (frame1->num < frame2->num)
return -1;
return 0;
}
int main(int argc, char *argv[])
{
wtap *wth = NULL;
wtap_dumper *pdh = NULL;
Buffer buf;
int err;
gchar *err_info;
gint64 data_offset;
const struct wtap_pkthdr *phdr;
guint wrong_order_count = 0;
gboolean write_output_regardless = TRUE;
guint i;
wtapng_section_t *shb_hdr;
wtapng_iface_descriptions_t *idb_inf;
GPtrArray *frames;
FrameRecord_t *prevFrame = NULL;
int opt;
int file_count;
char *infile;
char *outfile;
while ((opt = getopt(argc, argv, "n")) != -1) {
switch (opt) {
case 'n':
write_output_regardless = FALSE;
break;
case '?':
usage();
exit(1);
}
}
file_count = argc - optind;
if (file_count == 2) {
infile = argv[optind];
outfile = argv[optind+1];
}
else {
usage();
exit(1);
}
wth = wtap_open_offline(infile, &err, &err_info, TRUE);
if (wth == NULL) {
fprintf(stderr, "reordercap: Can't open %s: %s\n", infile,
wtap_strerror(err));
switch (err) {
case WTAP_ERR_UNSUPPORTED:
case WTAP_ERR_UNSUPPORTED_ENCAP:
case WTAP_ERR_BAD_FILE:
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
break;
}
exit(1);
}
DEBUG_PRINT("file_type is %u\n", wtap_file_type(wth));
shb_hdr = wtap_file_get_shb_info(wth);
idb_inf = wtap_file_get_idb_info(wth);
pdh = wtap_dump_open_ng(outfile, wtap_file_type(wth), wtap_file_encap(wth),
65535, FALSE, shb_hdr, idb_inf, &err);
g_free(idb_inf);
if (pdh == NULL) {
fprintf(stderr, "reordercap: Failed to open output file: (%s) - error %s\n",
outfile, wtap_strerror(err));
g_free(shb_hdr);
exit(1);
}
frames = g_ptr_array_new();
while (wtap_read(wth, &err, &err_info, &data_offset)) {
FrameRecord_t *newFrameRecord;
phdr = wtap_phdr(wth);
newFrameRecord = g_slice_new(FrameRecord_t);
newFrameRecord->num = frames->len + 1;
newFrameRecord->offset = data_offset;
newFrameRecord->length = phdr->len;
newFrameRecord->time = phdr->ts;
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
switch (err) {
case WTAP_ERR_UNSUPPORTED:
case WTAP_ERR_UNSUPPORTED_ENCAP:
case WTAP_ERR_BAD_FILE:
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
break;
}
}
printf("%u frames, %u out of order\n", frames->len, wrong_order_count);
if (wrong_order_count > 0) {
g_ptr_array_sort(frames, frames_compare);
}
buffer_init(&buf, 1500);
for (i = 0; i < frames->len; i++) {
FrameRecord_t *frame = (FrameRecord_t *)frames->pdata[i];
if (write_output_regardless || (wrong_order_count > 0)) {
frame_write(frame, wth, pdh, &buf, infile);
}
g_slice_free(FrameRecord_t, frame);
}
buffer_free(&buf);
if (!write_output_regardless && (wrong_order_count == 0)) {
printf("Not writing output file because input file is already in order!\n");
}
g_ptr_array_free(frames, TRUE);
if (!wtap_dump_close(pdh, &err)) {
fprintf(stderr, "reordercap: Error closing %s: %s\n", outfile,
wtap_strerror(err));
g_free(shb_hdr);
exit(1);
}
g_free(shb_hdr);
wtap_fdclose(wth);
return 0;
}
