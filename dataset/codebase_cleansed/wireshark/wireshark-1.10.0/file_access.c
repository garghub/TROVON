static void init_open_routines(void) {
if (open_routines_arr) return;
open_routines_arr = g_array_new(FALSE,TRUE,sizeof(wtap_open_routine_t));
g_array_append_vals(open_routines_arr,open_routines_base,N_FILE_TYPES);
open_routines = (wtap_open_routine_t*)(void *)open_routines_arr->data;
}
void wtap_register_open_routine(wtap_open_routine_t open_routine, gboolean has_magic) {
init_open_routines();
if (has_magic)
g_array_prepend_val(open_routines_arr,open_routine);
else
g_array_append_val(open_routines_arr,open_routine);
open_routines = (wtap_open_routine_t*)(void *)open_routines_arr->data;
}
wtap* wtap_open_offline(const char *filename, int *err, char **err_info,
gboolean do_random)
{
int fd;
ws_statb64 statb;
wtap *wth;
unsigned int i;
gboolean use_stdin = FALSE;
if (strcmp(filename, "-") == 0)
use_stdin = TRUE;
if (use_stdin) {
if (ws_fstat64(0, &statb) < 0) {
*err = errno;
return NULL;
}
} else {
if (ws_stat64(filename, &statb) < 0) {
*err = errno;
return NULL;
}
}
if (S_ISFIFO(statb.st_mode)) {
if (do_random) {
*err = WTAP_ERR_RANDOM_OPEN_PIPE;
return NULL;
}
} else if (S_ISDIR(statb.st_mode)) {
*err = EISDIR;
return NULL;
} else if (! S_ISREG(statb.st_mode)) {
*err = WTAP_ERR_NOT_REGULAR_FILE;
return NULL;
}
if (use_stdin && do_random) {
*err = WTAP_ERR_RANDOM_OPEN_STDIN;
return NULL;
}
errno = ENOMEM;
wth = (wtap *)g_malloc0(sizeof(wtap));
errno = WTAP_ERR_CANT_OPEN;
if (use_stdin) {
fd = ws_dup(0);
if (fd < 0) {
*err = errno;
g_free(wth);
return NULL;
}
#ifdef _WIN32
if (_setmode(fd, O_BINARY) == -1) {
*err = errno;
g_free(wth);
return NULL;
}
#endif
if (!(wth->fh = file_fdopen(fd))) {
*err = errno;
ws_close(fd);
g_free(wth);
return NULL;
}
} else {
if (!(wth->fh = file_open(filename))) {
*err = errno;
g_free(wth);
return NULL;
}
}
if (do_random) {
if (!(wth->random_fh = file_open(filename))) {
*err = errno;
file_close(wth->fh);
g_free(wth);
return NULL;
}
} else
wth->random_fh = NULL;
wth->file_encap = WTAP_ENCAP_UNKNOWN;
wth->subtype_sequential_close = NULL;
wth->subtype_close = NULL;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
wth->priv = NULL;
init_open_routines();
if (wth->random_fh) {
wth->fast_seek = g_ptr_array_new();
file_set_random_access(wth->fh, FALSE, wth->fast_seek);
file_set_random_access(wth->random_fh, TRUE, wth->fast_seek);
}
for (i = 0; i < open_routines_arr->len; i++) {
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1) {
wtap_close(wth);
return NULL;
}
switch ((*open_routines[i])(wth, err, err_info)) {
case -1:
wtap_close(wth);
return NULL;
case 0:
break;
case 1:
goto success;
}
}
wtap_close(wth);
*err = WTAP_ERR_FILE_UNKNOWN_FORMAT;
return NULL;
success:
wth->frame_buffer = (struct Buffer *)g_malloc(sizeof(struct Buffer));
buffer_init(wth->frame_buffer, 1500);
if(wth->file_type == WTAP_FILE_PCAP){
wtapng_if_descr_t descr;
descr.wtap_encap = wth->file_encap;
descr.time_units_per_second = 1000000;
descr.link_type = wtap_wtap_encap_to_pcap_encap(wth->file_encap);
descr.snap_len = wth->snapshot_length;
descr.opt_comment = NULL;
descr.if_name = NULL;
descr.if_description = NULL;
descr.if_speed = 0;
descr.if_tsresol = 6;
descr.if_filter_str= NULL;
descr.bpf_filter_len= 0;
descr.if_filter_bpf_bytes= NULL;
descr.if_os = NULL;
descr.if_fcslen = -1;
descr.num_stat_entries = 0;
descr.interface_statistics = NULL;
wth->number_of_interfaces= 1;
wth->interface_data= g_array_new(FALSE, FALSE, sizeof(wtapng_if_descr_t));
g_array_append_val(wth->interface_data, descr);
}
return wth;
}
gboolean
wtap_fdreopen(wtap *wth, const char *filename, int *err)
{
ws_statb64 statb;
if (strcmp(filename, "-") == 0) {
*err = WTAP_ERR_RANDOM_OPEN_STDIN;
return FALSE;
}
if (ws_stat64(filename, &statb) < 0) {
*err = errno;
return FALSE;
}
if (S_ISFIFO(statb.st_mode)) {
*err = WTAP_ERR_RANDOM_OPEN_PIPE;
return FALSE;
} else if (S_ISDIR(statb.st_mode)) {
*err = EISDIR;
return FALSE;
} else if (! S_ISREG(statb.st_mode)) {
*err = WTAP_ERR_NOT_REGULAR_FILE;
return FALSE;
}
errno = WTAP_ERR_CANT_OPEN;
if (!file_fdreopen(wth->random_fh, filename)) {
*err = errno;
return FALSE;
}
return TRUE;
}
static void init_file_types(void) {
if (dump_open_table_arr) return;
dump_open_table_arr = g_array_new(FALSE,TRUE,sizeof(struct file_type_info));
g_array_append_vals(dump_open_table_arr,dump_open_table_base,wtap_num_file_types);
dump_open_table = (const struct file_type_info*)(void *)dump_open_table_arr->data;
}
int wtap_register_file_type(const struct file_type_info* fi) {
init_file_types();
g_array_append_val(dump_open_table_arr,*fi);
dump_open_table = (const struct file_type_info*)(void *)dump_open_table_arr->data;
return wtap_num_file_types++;
}
int wtap_get_num_file_types(void)
{
return wtap_num_file_types;
}
int
wtap_dump_file_encap_type(const GArray *file_encaps)
{
int encap;
encap = WTAP_ENCAP_PER_PACKET;
if (file_encaps->len == 1) {
encap = g_array_index(file_encaps, gint, 0);
}
return encap;
}
static gboolean
wtap_dump_can_write_encap(int filetype, int encap)
{
if (filetype < 0 || filetype >= wtap_num_file_types
|| dump_open_table[filetype].can_write_encap == NULL)
return FALSE;
if ((*dump_open_table[filetype].can_write_encap)(encap) != 0)
return FALSE;
return TRUE;
}
static gboolean
wtap_dump_can_write_format(int ft, const GArray *file_encaps,
guint32 required_comment_types)
{
guint i;
if (!wtap_dump_can_open(ft)) {
return FALSE;
}
if (!wtap_dump_supports_comment_types(ft, required_comment_types)) {
return FALSE;
}
if (!wtap_dump_can_write_encap(ft, wtap_dump_file_encap_type(file_encaps))) {
return FALSE;
}
for (i = 0; i < file_encaps->len; i++) {
if (!wtap_dump_can_write_encap(ft,
g_array_index(file_encaps, int, i))) {
return FALSE;
}
}
return TRUE;
}
gboolean
wtap_dump_can_write(const GArray *file_encaps, guint32 required_comment_types)
{
int ft;
for (ft = 0; ft < WTAP_NUM_FILE_TYPES; ft++) {
if (wtap_dump_can_write_format(ft, file_encaps, required_comment_types)) {
return TRUE;
}
}
return FALSE;
}
GArray *
wtap_get_savable_file_types(int file_type, const GArray *file_encaps,
guint32 required_comment_types)
{
GArray *savable_file_types;
int ft;
int default_file_type = -1;
int other_file_type = -1;
if (wtap_dump_can_write_format(file_type, file_encaps,
required_comment_types)) {
default_file_type = file_type;
} else {
default_file_type = -1;
for (ft = 0; ft < WTAP_NUM_FILE_TYPES; ft++) {
if (wtap_dump_can_write_format(ft, file_encaps,
required_comment_types)) {
default_file_type = ft;
}
}
}
if (default_file_type == -1) {
return NULL;
}
savable_file_types = g_array_new(FALSE, FALSE, (guint)sizeof (int));
g_array_append_val(savable_file_types, default_file_type);
if (default_file_type == WTAP_FILE_PCAP) {
if (wtap_dump_can_write_format(WTAP_FILE_PCAPNG, file_encaps,
required_comment_types))
other_file_type = WTAP_FILE_PCAPNG;
} else if (default_file_type == WTAP_FILE_PCAPNG) {
if (wtap_dump_can_write_format(WTAP_FILE_PCAP, file_encaps,
required_comment_types))
other_file_type = WTAP_FILE_PCAP;
}
if (other_file_type != -1)
g_array_append_val(savable_file_types, other_file_type);
for (ft = 0; ft < WTAP_NUM_FILE_TYPES; ft++) {
if (ft == WTAP_FILE_UNKNOWN)
continue;
if (ft == default_file_type || ft == other_file_type)
continue;
if (wtap_dump_can_write_format(ft, file_encaps,
required_comment_types)) {
g_array_append_val(savable_file_types, ft);
}
}
return savable_file_types;
}
const char *wtap_file_type_string(int filetype)
{
if (filetype < 0 || filetype >= wtap_num_file_types) {
g_error("Unknown capture file type %d", filetype);
return "";
} else
return dump_open_table[filetype].name;
}
const char *wtap_file_type_short_string(int filetype)
{
if (filetype < 0 || filetype >= wtap_num_file_types)
return NULL;
else
return dump_open_table[filetype].short_name;
}
int wtap_short_string_to_file_type(const char *short_name)
{
int filetype;
for (filetype = 0; filetype < wtap_num_file_types; filetype++) {
if (dump_open_table[filetype].short_name != NULL &&
strcmp(short_name, dump_open_table[filetype].short_name) == 0)
return filetype;
}
return -1;
}
static GSList *add_extensions(GSList *extensions, const gchar *extension,
GSList *compressed_file_extensions)
{
GSList *compressed_file_extension;
extensions = g_slist_append(extensions, g_strdup(extension));
for (compressed_file_extension = compressed_file_extensions;
compressed_file_extension != NULL;
compressed_file_extension = g_slist_next(compressed_file_extension)) {
extensions = g_slist_append(extensions,
g_strdup_printf("%s.%s", extension,
(gchar *)compressed_file_extension->data));
}
return extensions;
}
GSList *wtap_get_file_extensions_list(int filetype, gboolean include_compressed)
{
gchar **extensions_set, **extensionp;
gchar *extension;
GSList *compressed_file_extensions;
GSList *extensions;
if (filetype < 0 || filetype >= wtap_num_file_types)
return NULL;
if (dump_open_table[filetype].default_file_extension == NULL)
return NULL;
extensions = NULL;
if (include_compressed)
compressed_file_extensions = wtap_get_compressed_file_extensions();
else
compressed_file_extensions = NULL;
extensions = add_extensions(extensions,
dump_open_table[filetype].default_file_extension,
compressed_file_extensions);
if (dump_open_table[filetype].additional_file_extensions != NULL) {
extensions_set = g_strsplit(dump_open_table[filetype].additional_file_extensions,
";", 0);
for (extensionp = extensions_set; *extensionp != NULL;
extensionp++) {
extension = *extensionp;
extensions = add_extensions(extensions, extension,
compressed_file_extensions);
}
g_strfreev(extensions_set);
}
g_slist_free(compressed_file_extensions);
return extensions;
}
void wtap_free_file_extensions_list(GSList *extensions)
{
GSList *extension;
for (extension = extensions; extension != NULL;
extension = g_slist_next(extension)) {
g_free(extension->data);
}
g_slist_free(extensions);
}
const char *wtap_default_file_extension(int filetype)
{
if (filetype < 0 || filetype >= wtap_num_file_types)
return NULL;
else
return dump_open_table[filetype].default_file_extension;
}
gboolean wtap_dump_can_open(int filetype)
{
if (filetype < 0 || filetype >= wtap_num_file_types
|| dump_open_table[filetype].dump_open == NULL)
return FALSE;
return TRUE;
}
gboolean wtap_dump_can_compress(int filetype)
{
if (filetype < 0 || filetype >= wtap_num_file_types
|| dump_open_table[filetype].writing_must_seek)
return FALSE;
return TRUE;
}
gboolean wtap_dump_can_compress(int filetype _U_)
{
return FALSE;
}
gboolean wtap_dump_has_name_resolution(int filetype)
{
if (filetype < 0 || filetype >= wtap_num_file_types
|| dump_open_table[filetype].has_name_resolution == FALSE)
return FALSE;
return TRUE;
}
gboolean wtap_dump_supports_comment_types(int filetype, guint32 comment_types)
{
guint32 supported_comment_types;
if (filetype < 0 || filetype >= wtap_num_file_types)
return FALSE;
supported_comment_types = dump_open_table[filetype].supported_comment_types;
if ((comment_types & supported_comment_types) == comment_types)
return TRUE;
return FALSE;
}
wtap_dumper* wtap_dump_open(const char *filename, int filetype, int encap,
int snaplen, gboolean compressed, int *err)
{
return wtap_dump_open_ng(filename, filetype, encap,snaplen, compressed, NULL, NULL, err);
}
static wtap_dumper *
wtap_dump_init_dumper(int filetype, int encap, int snaplen, gboolean compressed,
wtapng_section_t *shb_hdr, wtapng_iface_descriptions_t *idb_inf, int *err)
{
wtap_dumper *wdh;
wdh = wtap_dump_alloc_wdh(filetype, encap, snaplen, compressed, err);
if (wdh == NULL)
return NULL;
wdh->shb_hdr = shb_hdr;
if ((idb_inf != NULL) && (idb_inf->number_of_interfaces > 0)) {
wdh->number_of_interfaces = idb_inf->number_of_interfaces;
wdh->interface_data = idb_inf->interface_data;
} else {
wtapng_if_descr_t descr;
descr.wtap_encap = encap;
descr.time_units_per_second = 1000000;
descr.link_type = wtap_wtap_encap_to_pcap_encap(encap);
descr.snap_len = snaplen;
descr.opt_comment = NULL;
descr.if_name = g_strdup("Unknown/not available in original file format(libpcap)");
descr.if_description = NULL;
descr.if_speed = 0;
descr.if_tsresol = 6;
descr.if_filter_str= NULL;
descr.bpf_filter_len= 0;
descr.if_filter_bpf_bytes= NULL;
descr.if_os = NULL;
descr.if_fcslen = -1;
descr.num_stat_entries = 0;
descr.interface_statistics = NULL;
wdh->number_of_interfaces= 1;
wdh->interface_data= g_array_new(FALSE, FALSE, sizeof(wtapng_if_descr_t));
g_array_append_val(wdh->interface_data, descr);
}
return wdh;
}
wtap_dumper* wtap_dump_open_ng(const char *filename, int filetype, int encap,
int snaplen, gboolean compressed, wtapng_section_t *shb_hdr, wtapng_iface_descriptions_t *idb_inf, int *err)
{
wtap_dumper *wdh;
WFILE_T fh;
if (!wtap_dump_open_check(filetype, encap, compressed, err))
return NULL;
wdh = wtap_dump_init_dumper(filetype, encap, snaplen, compressed,
shb_hdr, idb_inf, err);
if (wdh == NULL)
return NULL;
if (strcmp(filename, "-") == 0) {
if (compressed) {
*err = EINVAL;
g_free(wdh);
return NULL;
}
#ifdef _WIN32
if (_setmode(fileno(stdout), O_BINARY) == -1) {
*err = errno;
g_free(wdh);
return NULL;
}
#endif
wdh->fh = stdout;
} else {
errno = WTAP_ERR_CANT_OPEN;
fh = wtap_dump_file_open(wdh, filename);
if (fh == NULL) {
*err = errno;
g_free(wdh);
return NULL;
}
wdh->fh = fh;
}
if (!wtap_dump_open_finish(wdh, filetype, compressed, err)) {
if (wdh->fh != stdout) {
wtap_dump_file_close(wdh);
ws_unlink(filename);
}
g_free(wdh);
return NULL;
}
return wdh;
}
wtap_dumper* wtap_dump_fdopen(int fd, int filetype, int encap, int snaplen,
gboolean compressed, int *err)
{
return wtap_dump_fdopen_ng(fd, filetype, encap, snaplen, compressed, NULL, NULL, err);
}
wtap_dumper* wtap_dump_fdopen_ng(int fd, int filetype, int encap, int snaplen,
gboolean compressed, wtapng_section_t *shb_hdr, wtapng_iface_descriptions_t *idb_inf, int *err)
{
wtap_dumper *wdh;
WFILE_T fh;
if (!wtap_dump_open_check(filetype, encap, compressed, err))
return NULL;
wdh = wtap_dump_init_dumper(filetype, encap, snaplen, compressed,
shb_hdr, idb_inf, err);
if (wdh == NULL)
return NULL;
#ifdef _WIN32
if (fd == 1) {
if (_setmode(fileno(stdout), O_BINARY) == -1) {
*err = errno;
g_free(wdh);
return NULL;
}
}
#endif
errno = WTAP_ERR_CANT_OPEN;
fh = wtap_dump_file_fdopen(wdh, fd);
if (fh == NULL) {
*err = errno;
g_free(wdh);
return NULL;
}
wdh->fh = fh;
if (!wtap_dump_open_finish(wdh, filetype, compressed, err)) {
wtap_dump_file_close(wdh);
g_free(wdh);
return NULL;
}
return wdh;
}
static gboolean wtap_dump_open_check(int filetype, int encap, gboolean compressed, int *err)
{
if (!wtap_dump_can_open(filetype)) {
*err = WTAP_ERR_UNSUPPORTED_FILE_TYPE;
return FALSE;
}
*err = (*dump_open_table[filetype].can_write_encap)(encap);
if (*err != 0)
return FALSE;
if(compressed && !wtap_dump_can_compress(filetype)) {
*err = WTAP_ERR_COMPRESSION_NOT_SUPPORTED;
return FALSE;
}
*err = (*dump_open_table[filetype].can_write_encap)(encap);
if (*err != 0)
return FALSE;
return TRUE;
}
static wtap_dumper* wtap_dump_alloc_wdh(int filetype, int encap, int snaplen,
gboolean compressed, int *err)
{
wtap_dumper *wdh;
wdh = (wtap_dumper *)g_malloc0(sizeof (wtap_dumper));
if (wdh == NULL) {
*err = errno;
return NULL;
}
wdh->file_type = filetype;
wdh->snaplen = snaplen;
wdh->encap = encap;
wdh->compressed = compressed;
return wdh;
}
static gboolean wtap_dump_open_finish(wtap_dumper *wdh, int filetype, gboolean compressed, int *err)
{
int fd;
gboolean cant_seek;
if(compressed) {
cant_seek = TRUE;
} else {
fd = fileno((FILE *)wdh->fh);
if (lseek(fd, 1, SEEK_CUR) == -1)
cant_seek = TRUE;
else {
lseek(fd, 0, SEEK_SET);
cant_seek = FALSE;
}
}
if (dump_open_table[filetype].writing_must_seek && cant_seek) {
*err = WTAP_ERR_CANT_WRITE_TO_PIPE;
return FALSE;
}
if (!(*dump_open_table[filetype].dump_open)(wdh, err)) {
return FALSE;
}
return TRUE;
}
gboolean wtap_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
return (wdh->subtype_write)(wdh, phdr, pd, err);
}
void wtap_dump_flush(wtap_dumper *wdh)
{
#ifdef HAVE_LIBZ
if(wdh->compressed) {
gzwfile_flush((GZWFILE_T)wdh->fh);
} else
#endif
{
fflush((FILE *)wdh->fh);
}
}
gboolean wtap_dump_close(wtap_dumper *wdh, int *err)
{
gboolean ret = TRUE;
if (wdh->subtype_close != NULL) {
if (!(wdh->subtype_close)(wdh, err))
ret = FALSE;
}
errno = WTAP_ERR_CANT_CLOSE;
if (wdh->fh != stdout) {
if (wtap_dump_file_close(wdh) == EOF) {
if (ret) {
if (err != NULL)
*err = errno;
}
ret = FALSE;
}
} else {
wtap_dump_flush(wdh);
}
if (wdh->priv != NULL)
g_free(wdh->priv);
g_free(wdh);
return ret;
}
gint64 wtap_get_bytes_dumped(wtap_dumper *wdh)
{
return wdh->bytes_dumped;
}
void wtap_set_bytes_dumped(wtap_dumper *wdh, gint64 bytes_dumped)
{
wdh->bytes_dumped = bytes_dumped;
}
gboolean wtap_dump_set_addrinfo_list(wtap_dumper *wdh, struct addrinfo *addrinfo_list)
{
if (!wdh || wdh->file_type < 0 || wdh->file_type >= wtap_num_file_types
|| dump_open_table[wdh->file_type].has_name_resolution == FALSE)
return FALSE;
wdh->addrinfo_list = addrinfo_list;
return TRUE;
}
static WFILE_T wtap_dump_file_open(wtap_dumper *wdh, const char *filename)
{
if(wdh->compressed) {
return gzwfile_open(filename);
} else {
return ws_fopen(filename, "wb");
}
}
static WFILE_T wtap_dump_file_open(wtap_dumper *wdh _U_, const char *filename)
{
return ws_fopen(filename, "wb");
}
static WFILE_T wtap_dump_file_fdopen(wtap_dumper *wdh, int fd)
{
if(wdh->compressed) {
return gzwfile_fdopen(fd);
} else {
return fdopen(fd, "wb");
}
}
static WFILE_T wtap_dump_file_fdopen(wtap_dumper *wdh _U_, int fd)
{
return fdopen(fd, "wb");
}
gboolean wtap_dump_file_write(wtap_dumper *wdh, const void *buf, size_t bufsize,
int *err)
{
size_t nwritten;
#ifdef HAVE_LIBZ
if (wdh->compressed) {
nwritten = gzwfile_write((GZWFILE_T)wdh->fh, buf, (unsigned) bufsize);
if (nwritten == 0) {
*err = gzwfile_geterr((GZWFILE_T)wdh->fh);
return FALSE;
}
} else
#endif
{
nwritten = fwrite(buf, 1, bufsize, (FILE *)wdh->fh);
if (nwritten != bufsize) {
if (ferror((FILE *)wdh->fh))
*err = errno;
else
*err = WTAP_ERR_SHORT_WRITE;
return FALSE;
}
}
return TRUE;
}
static int wtap_dump_file_close(wtap_dumper *wdh)
{
#ifdef HAVE_LIBZ
if(wdh->compressed) {
return gzwfile_close((GZWFILE_T)wdh->fh);
} else
#endif
{
return fclose((FILE *)wdh->fh);
}
}
gint64 wtap_dump_file_seek(wtap_dumper *wdh, gint64 offset, int whence, int *err)
{
#ifdef HAVE_LIBZ
if(wdh->compressed) {
*err = WTAP_ERR_CANT_SEEK_COMPRESSED;
return -1;
} else
#endif
{
if (-1 == fseek((FILE *)wdh->fh, (long)offset, whence)) {
*err = errno;
return -1;
} else
{
return 0;
}
}
}
gint64 wtap_dump_file_tell(wtap_dumper *wdh, int *err)
{
gint64 rval;
#ifdef HAVE_LIBZ
if(wdh->compressed) {
*err = WTAP_ERR_CANT_SEEK_COMPRESSED;
return -1;
} else
#endif
{
if (-1 == (rval = ftell((FILE *)wdh->fh))) {
*err = errno;
return -1;
} else
{
return rval;
}
}
}
