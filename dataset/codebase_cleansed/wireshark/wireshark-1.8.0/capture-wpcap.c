void
load_wpcap(void)
{
static const symbol_table_t symbols[] = {
SYM(pcap_lookupdev, FALSE),
SYM(pcap_close, FALSE),
SYM(pcap_stats, FALSE),
SYM(pcap_dispatch, FALSE),
SYM(pcap_snapshot, FALSE),
SYM(pcap_datalink, FALSE),
SYM(pcap_setfilter, FALSE),
SYM(pcap_geterr, FALSE),
SYM(pcap_compile, FALSE),
SYM(pcap_compile_nopcap, FALSE),
SYM(pcap_lookupnet, FALSE),
#ifdef HAVE_PCAP_REMOTE
SYM(pcap_open, FALSE),
SYM(pcap_findalldevs_ex, FALSE),
SYM(pcap_createsrcstr, FALSE),
#endif
SYM(pcap_open_live, FALSE),
#ifdef HAVE_PCAP_OPEN_DEAD
SYM(pcap_open_dead, FALSE),
#endif
#ifdef HAVE_PCAP_SETSAMPLING
SYM(pcap_setsampling, TRUE),
#endif
SYM(pcap_loop, FALSE),
SYM(pcap_freecode, TRUE),
#ifdef HAVE_PCAP_FINDALLDEVS
SYM(pcap_findalldevs, TRUE),
SYM(pcap_freealldevs, TRUE),
#endif
#ifdef HAVE_PCAP_DATALINK_NAME_TO_VAL
SYM(pcap_datalink_name_to_val, TRUE),
#endif
#ifdef HAVE_PCAP_DATALINK_VAL_TO_NAME
SYM(pcap_datalink_val_to_name, TRUE),
#endif
#ifdef HAVE_PCAP_DATALINK_VAL_TO_DESCRIPTION
SYM(pcap_datalink_val_to_description, TRUE),
#endif
#ifdef HAVE_PCAP_BREAKLOOP
SYM(pcap_breakloop, FALSE),
#endif
SYM(pcap_lib_version, TRUE),
SYM(pcap_setbuff, TRUE),
SYM(pcap_next_ex, TRUE),
#ifdef HAVE_PCAP_LIST_DATALINKS
SYM(pcap_list_datalinks, FALSE),
#endif
#ifdef HAVE_PCAP_SET_DATALINK
SYM(pcap_set_datalink, FALSE),
#endif
#ifdef HAVE_PCAP_FREE_DATALINKS
SYM(pcap_free_datalinks, TRUE),
#endif
#ifdef HAVE_BPF_IMAGE
SYM(bpf_image, FALSE),
#endif
{ NULL, NULL, FALSE }
};
GModule *wh;
const symbol_table_t *sym;
wh = ws_module_open("wpcap.dll", 0);
if (!wh) {
return;
}
sym = symbols;
while (sym->name) {
if (!g_module_symbol(wh, sym->name, sym->ptr)) {
if (sym->optional) {
*sym->ptr = NULL;
} else {
return;
}
}
sym++;
}
has_wpcap = TRUE;
}
char *
cant_load_winpcap_err(const char *app_name)
{
return g_strdup_printf(
"Unable to load WinPcap (wpcap.dll); %s will not be able to capture\n"
"packets.\n"
"\n"
"In order to capture packets, WinPcap must be installed; see\n"
"\n"
" http://www.winpcap.org/\n"
"\n"
"or the mirror at\n"
"\n"
" http://www.mirrors.wiretapped.net/security/packet-capture/winpcap/\n"
"\n"
"or the mirror at\n"
"\n"
" http://winpcap.cs.pu.edu.tw/\n"
"\n"
"for a downloadable version of WinPcap and for instructions on how to install\n"
"WinPcap.",
app_name);
}
char*
pcap_lookupdev (char *a)
{
if (!has_wpcap) {
return NULL;
}
return p_pcap_lookupdev(a);
}
void
pcap_close(pcap_t *a)
{
g_assert(has_wpcap);
p_pcap_close(a);
}
int
pcap_stats(pcap_t *a, struct pcap_stat *b)
{
g_assert(has_wpcap);
return p_pcap_stats(a, b);
}
int
pcap_dispatch(pcap_t *a, int b, pcap_handler c, guchar *d)
{
g_assert(has_wpcap);
return p_pcap_dispatch(a, b, c, d);
}
int
pcap_snapshot(pcap_t *a)
{
g_assert(has_wpcap);
return p_pcap_snapshot(a);
}
int
pcap_datalink(pcap_t *a)
{
g_assert(has_wpcap);
return p_pcap_datalink(a);
}
int
pcap_set_datalink(pcap_t *p, int dlt)
{
g_assert(has_wpcap);
return p_pcap_set_datalink(p, dlt);
}
int
pcap_setfilter(pcap_t *a, struct bpf_program *b)
{
g_assert(has_wpcap);
return p_pcap_setfilter(a, b);
}
char*
pcap_geterr(pcap_t *a)
{
g_assert(has_wpcap);
return p_pcap_geterr(a);
}
int
pcap_compile(pcap_t *a, struct bpf_program *b, const char *c, int d,
bpf_u_int32 e)
{
g_assert(has_wpcap);
return p_pcap_compile(a, b, c, d, e);
}
int
pcap_compile_nopcap(int a, int b, struct bpf_program *c, const char *d, int e,
bpf_u_int32 f)
{
g_assert(has_wpcap);
return p_pcap_compile_nopcap(a, b, c, d, e, f);
}
int
pcap_lookupnet(const char *a, bpf_u_int32 *b, bpf_u_int32 *c, char *d)
{
g_assert(has_wpcap);
return p_pcap_lookupnet(a, b, c, d);
}
pcap_t*
pcap_open_live(const char *a, int b, int c, int d, char *e)
{
if (!has_wpcap) {
g_snprintf(e, PCAP_ERRBUF_SIZE,
"unable to load WinPcap (wpcap.dll); can't open %s to capture",
a);
return NULL;
}
return p_pcap_open_live(a, b, c, d, e);
}
pcap_t*
pcap_open_dead(int a, int b)
{
if (!has_wpcap) {
return NULL;
}
return p_pcap_open_dead(a, b);
}
char *
bpf_image(const struct bpf_insn *a, int b)
{
if (!has_wpcap) {
return NULL;
}
return p_bpf_image(a, b);
}
pcap_t*
pcap_open(const char *a, int b, int c, int d, struct pcap_rmtauth *e, char *f)
{
if (!has_wpcap) {
g_snprintf(f, PCAP_ERRBUF_SIZE,
"unable to load WinPcap (wpcap.dll); can't open %s to capture",
a);
return NULL;
}
return p_pcap_open(a, b, c, d, e, f);
}
int
pcap_findalldevs_ex(char *a, struct pcap_rmtauth *b, pcap_if_t **c, char *d)
{
g_assert(has_wpcap);
return p_pcap_findalldevs_ex(a, b, c, d);
}
int
pcap_createsrcstr(char *a, int b, const char *c, const char *d, const char *e,
char *f)
{
g_assert(has_wpcap);
return p_pcap_createsrcstr(a, b, c, d, e, f);
}
struct pcap_samp *
pcap_setsampling(pcap_t *a)
{
g_assert(has_wpcap);
if (p_pcap_setsampling != NULL) {
return p_pcap_setsampling(a);
}
return NULL;
}
int
pcap_loop(pcap_t *a, int b, pcap_handler c, guchar *d)
{
g_assert(has_wpcap);
return p_pcap_loop(a, b, c, d);
}
void
pcap_freecode(struct bpf_program *a)
{
g_assert(has_wpcap);
if(p_pcap_freecode) {
p_pcap_freecode(a);
}
}
int
pcap_findalldevs(pcap_if_t **a, char *b)
{
g_assert(has_wpcap && p_pcap_findalldevs != NULL);
return p_pcap_findalldevs(a, b);
}
void
pcap_freealldevs(pcap_if_t *a)
{
g_assert(has_wpcap && p_pcap_freealldevs != NULL);
p_pcap_freealldevs(a);
}
int
pcap_datalink_name_to_val(const char *name)
{
int i;
g_assert(has_wpcap);
if (p_pcap_datalink_name_to_val != NULL)
return p_pcap_datalink_name_to_val(name);
else {
for (i = 0; dlt_choices[i].name != NULL; i++) {
if (g_ascii_strcasecmp(dlt_choices[i].name + sizeof("DLT_") - 1,
name) == 0)
return dlt_choices[i].dlt;
}
return -1;
}
}
int
pcap_list_datalinks(pcap_t *p, int **ddlt)
{
g_assert(has_wpcap);
return p_pcap_list_datalinks(p, ddlt);
}
void
pcap_free_datalinks(int *ddlt)
{
g_assert(has_wpcap);
if (p_pcap_free_datalinks != NULL)
p_pcap_free_datalinks(ddlt);
}
const char *
pcap_datalink_val_to_name(int dlt)
{
int i;
g_assert(has_wpcap);
if (p_pcap_datalink_val_to_name != NULL)
return p_pcap_datalink_val_to_name(dlt);
else {
for (i = 0; dlt_choices[i].name != NULL; i++) {
if (dlt_choices[i].dlt == dlt)
return dlt_choices[i].name + sizeof("DLT_") - 1;
}
return NULL;
}
}
const char *
pcap_datalink_val_to_description(int dlt)
{
int i;
g_assert(has_wpcap);
if (p_pcap_datalink_val_to_description != NULL)
return p_pcap_datalink_val_to_description(dlt);
else {
for (i = 0; dlt_choices[i].name != NULL; i++) {
if (dlt_choices[i].dlt == dlt)
return (dlt_choices[i].description);
}
return NULL;
}
}
void pcap_breakloop(pcap_t *a)
{
p_pcap_breakloop(a);
}
int pcap_setbuff(pcap_t *a, int b)
{
g_assert(has_wpcap);
return p_pcap_setbuff(a, b);
}
int pcap_next_ex (pcap_t *a, struct pcap_pkthdr **b, const u_char **c)
{
g_assert(has_wpcap);
return p_pcap_next_ex(a, b, c);
}
GList *
get_remote_interface_list(const char *hostname, const char *port,
int auth_type, const char *username,
const char *passwd, int *err, char **err_str)
{
struct pcap_rmtauth auth;
char source[PCAP_BUF_SIZE];
char errbuf[PCAP_ERRBUF_SIZE];
GList *result;
if (pcap_createsrcstr(source, PCAP_SRC_IFREMOTE, hostname, port,
NULL, errbuf) == -1) {
*err = CANT_GET_INTERFACE_LIST;
if (err_str != NULL)
*err_str = cant_get_if_list_error_message(errbuf);
return NULL;
}
auth.type = auth_type;
auth.username = g_strdup(username);
auth.password = g_strdup(passwd);
result = get_interface_list_findalldevs_ex(source, &auth, err, err_str);
g_free(auth.username);
g_free(auth.password);
return result;
}
GList *
get_interface_list(int *err, char **err_str)
{
GList *il = NULL;
wchar_t *names;
char *win95names;
char ascii_name[MAX_WIN_IF_NAME_LEN + 1];
char ascii_desc[MAX_WIN_IF_NAME_LEN + 1];
int i, j;
char errbuf[PCAP_ERRBUF_SIZE];
if (!has_wpcap) {
*err = DONT_HAVE_PCAP;
*err_str = cant_load_winpcap_err("you");
return NULL;
}
#ifdef HAVE_PCAP_FINDALLDEVS
if (p_pcap_findalldevs != NULL)
return get_interface_list_findalldevs(err, err_str);
#endif
names = (wchar_t *)pcap_lookupdev(errbuf);
i = 0;
if (names) {
char* desc = 0;
int desc_pos = 0;
if (names[0]<256) {
while (*(names+desc_pos) || *(names+desc_pos-1))
desc_pos++;
desc_pos++;
desc = (char*)(names + desc_pos);
while (names[i] != 0) {
j = 0;
while (*desc != 0) {
if (j < MAX_WIN_IF_NAME_LEN)
ascii_desc[j++] = *desc;
desc++;
}
ascii_desc[j] = '\0';
desc++;
j = 0;
while (names[i] != 0) {
if (j < MAX_WIN_IF_NAME_LEN)
ascii_name[j++] = (char) names[i++];
}
ascii_name[j] = '\0';
i++;
il = g_list_append(il,
if_info_new(ascii_name, ascii_desc));
}
} else {
win95names=(char *)names;
while (*(win95names+desc_pos) || *(win95names+desc_pos-1))
desc_pos++;
desc_pos++;
desc = win95names + desc_pos;
while (win95names[i] != '\0') {
il = g_list_append(il,
if_info_new(&win95names[i], desc));
while (*desc != 0)
desc++;
desc++;
while (win95names[i] != 0)
i++;
i++;
}
}
}
if (il == NULL) {
*err = NO_INTERFACES_FOUND;
if (err_str != NULL)
*err_str = NULL;
}
return il;
}
gchar *
cant_get_if_list_error_message(const char *err_str)
{
if (strstr(err_str, "Not enough storage is available to process this command") != NULL ||
strstr(err_str, "The operation completed successfully") != NULL) {
return g_strdup_printf("Can't get list of interfaces: %s\n"
"This might be a problem with WinPcap 3.0; you should try updating to\n"
"a later version of WinPcap - see the WinPcap site at www.winpcap.org",
err_str);
}
return g_strdup_printf("Can't get list of interfaces: %s", err_str);
}
void
get_compiled_pcap_version(GString *str)
{
g_string_append(str, "with WinPcap (" STRINGIFY(PCAP_VERSION) ")");
}
void
get_runtime_pcap_version(GString *str)
{
GModule *handle;
static gchar *packetVer;
gchar *blankp;
if (has_wpcap) {
g_string_append_printf(str, "with ");
if (p_pcap_lib_version != NULL)
g_string_append_printf(str, p_pcap_lib_version());
else {
if (packetVer == NULL) {
packetVer = "version unknown";
handle = ws_module_open("packet.dll", 0);
if (handle != NULL) {
if (g_module_symbol(handle,
"PacketLibraryVersion",
(gpointer*)&packetVer)) {
packetVer = g_strdup(packetVer);
blankp = strchr(packetVer, ' ');
if (blankp != NULL)
*blankp = '\0';
} else {
packetVer = "version unknown";
}
g_module_close(handle);
}
}
g_string_append_printf(str, "WinPcap (%s)", packetVer);
}
} else
g_string_append(str, "without WinPcap");
}
void
load_wpcap(void)
{
return;
}
void
get_compiled_pcap_version(GString *str)
{
g_string_append(str, "without WinPcap");
}
void
get_runtime_pcap_version(GString *str _U_)
{
}
