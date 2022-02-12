static void help(extcap_parameters* extcap_conf)
{
unsigned i = 0;
char** abbrev_list;
char** longname_list;
extcap_help_print(extcap_conf);
printf("\nPacket types:\n");
randpkt_example_list(&abbrev_list, &longname_list);
while (abbrev_list[i] && longname_list[i]) {
printf("\t%-16s%s\n", abbrev_list[i], longname_list[i]);
i++;
}
printf("\n");
g_strfreev(abbrev_list);
g_strfreev(longname_list);
}
static int list_config(char *interface)
{
unsigned inc = 0;
unsigned i = 0;
char** abbrev_list;
char** longname_list;
if (!interface) {
g_warning("No interface specified.");
return EXIT_FAILURE;
}
if (g_strcmp0(interface, RANDPKT_EXTCAP_INTERFACE)) {
g_warning("Interface must be %s", RANDPKT_EXTCAP_INTERFACE);
return EXIT_FAILURE;
}
printf("arg {number=%u}{call=--maxbytes}{display=Max bytes in a packet}"
"{type=unsigned}{range=1,5000}{default=5000}{tooltip=The max number of bytes in a packet}\n",
inc++);
printf("arg {number=%u}{call=--count}{display=Number of packets}"
"{type=long}{default=1000}{tooltip=Number of packets to generate (-1 for infinite)}\n",
inc++);
printf("arg {number=%u}{call=--random-type}{display=Random type}"
"{type=boolean}{default=false}{tooltip=The packets type is randomly chosen}\n",
inc++);
printf("arg {number=%u}{call=--all-random}{display=All random packets}"
"{type=boolean}{default=false}{tooltip=Packet type for each packet is randomly chosen}\n",
inc++);
printf("arg {number=%u}{call=--type}{display=Type of packet}"
"{type=selector}{tooltip=Type of packet to generate}\n",
inc);
randpkt_example_list(&abbrev_list, &longname_list);
while (abbrev_list[i] && longname_list[i]) {
printf("value {arg=%u}{value=%s}{display=%s}\n", inc, abbrev_list[i], longname_list[i]);
i++;
}
g_strfreev(abbrev_list);
g_strfreev(longname_list);
inc++;
return EXIT_SUCCESS;
}
int main(int argc, char *argv[])
{
int option_idx = 0;
int result;
guint16 maxbytes = 5000;
guint64 count = 1000;
int random_type = FALSE;
int all_random = FALSE;
char* type = NULL;
int produce_type = -1;
randpkt_example *example;
wtap_dumper* savedump;
int i;
int ret = EXIT_FAILURE;
#ifdef _WIN32
WSADATA wsaData;
#endif
extcap_parameters * extcap_conf = g_new0(extcap_parameters, 1);
char* help_url;
char* help_header = NULL;
help_url = data_file_url("randpktdump.html");
extcap_base_set_util_info(extcap_conf, argv[0], RANDPKTDUMP_VERSION_MAJOR, RANDPKTDUMP_VERSION_MINOR,
RANDPKTDUMP_VERSION_RELEASE, help_url);
g_free(help_url);
extcap_base_register_interface(extcap_conf, RANDPKT_EXTCAP_INTERFACE, "Random packet generator", 147, "Generator dependent DLT");
help_header = g_strdup_printf(
" %s --extcap-interfaces\n"
" %s --extcap-interface=%s --extcap-dlts\n"
" %s --extcap-interface=%s --extcap-config\n"
" %s --extcap-interface=%s --type dns --count 10 "
"--fifo=FILENAME --capture\n", argv[0], argv[0], RANDPKT_EXTCAP_INTERFACE, argv[0], RANDPKT_EXTCAP_INTERFACE,
argv[0], RANDPKT_EXTCAP_INTERFACE);
extcap_help_add_header(extcap_conf, help_header);
g_free(help_header);
extcap_help_add_option(extcap_conf, "--help", "print this help");
extcap_help_add_option(extcap_conf, "--version", "print the version");
extcap_help_add_option(extcap_conf, "--maxbytes <bytes>", "max bytes per pack");
extcap_help_add_option(extcap_conf, "--count <num>", "number of packets to generate");
extcap_help_add_option(extcap_conf, "--random-type", "one random type is chosen for all packets");
extcap_help_add_option(extcap_conf, "--all-random", "a random type is chosen for each packet");
extcap_help_add_option(extcap_conf, "--type <type>", "the packet type");
if (argc == 1) {
help(extcap_conf);
goto end;
}
#ifdef _WIN32
attach_parent_console();
#endif
for (i = 0; i < argc; i++)
g_debug("%s ", argv[i]);
while ((result = getopt_long(argc, argv, ":", longopts, &option_idx)) != -1) {
switch (result) {
case OPT_VERSION:
printf("%s\n", extcap_conf->version);
ret = EXIT_SUCCESS;
goto end;
case OPT_HELP:
help(extcap_conf);
ret = EXIT_SUCCESS;
goto end;
case OPT_MAXBYTES:
if (!ws_strtou16(optarg, NULL, &maxbytes)) {
g_warning("Invalid parameter maxbytes: %s (max value is %u)",
optarg, G_MAXUINT16);
goto end;
}
break;
case OPT_COUNT:
if (!ws_strtou64(optarg, NULL, &count)) {
g_warning("Invalid packet count: %s", optarg);
goto end;
}
break;
case OPT_RANDOM_TYPE:
if (!g_ascii_strcasecmp("true", optarg)) {
random_type = TRUE;
}
break;
case OPT_ALL_RANDOM:
if (!g_ascii_strcasecmp("true", optarg)) {
all_random = TRUE;
}
break;
case OPT_TYPE:
g_free(type);
type = g_strdup(optarg);
break;
case ':':
g_warning("Option '%s' requires an argument", argv[optind - 1]);
break;
default:
if (!extcap_base_parse_options(extcap_conf, result - EXTCAP_OPT_LIST_INTERFACES, optarg))
{
g_warning("Invalid option: %s", argv[optind - 1]);
goto end;
}
}
}
if (optind != argc) {
g_warning("Invalid option: %s", argv[optind]);
goto end;
}
if (extcap_base_handle_interface(extcap_conf)) {
ret = EXIT_SUCCESS;
goto end;
}
if (extcap_conf->show_config) {
ret = list_config(extcap_conf->interface);
goto end;
}
if ((random_type) && (all_random)) {
g_warning("You can specify only one between: --random-type, --all-random");
goto end;
}
if (random_type || all_random) {
g_free(type);
type = NULL;
}
#ifdef _WIN32
result = WSAStartup(MAKEWORD(1,1), &wsaData);
if (result != 0) {
g_warning("ERROR: WSAStartup failed with error: %d", result);
goto end;
}
#endif
if (extcap_conf->capture) {
if (g_strcmp0(extcap_conf->interface, RANDPKT_EXTCAP_INTERFACE)) {
g_warning("ERROR: invalid interface");
goto end;
}
if (!all_random) {
produce_type = randpkt_parse_type(type);
example = randpkt_find_example(produce_type);
if (!example)
goto end;
g_debug("Generating packets: %s", example->abbrev);
randpkt_example_init(example, extcap_conf->fifo, maxbytes);
randpkt_loop(example, count);
randpkt_example_close(example);
} else {
produce_type = randpkt_parse_type(NULL);
example = randpkt_find_example(produce_type);
if (!example)
goto end;
randpkt_example_init(example, extcap_conf->fifo, maxbytes);
while (count-- > 0) {
randpkt_loop(example, 1);
produce_type = randpkt_parse_type(NULL);
savedump = example->dump;
example = randpkt_find_example(produce_type);
if (!example)
goto end;
example->dump = savedump;
}
randpkt_example_close(example);
}
ret = EXIT_SUCCESS;
}
end:
g_free(type);
extcap_base_cleanup(&extcap_conf);
return ret;
}
int _stdcall
WinMain (struct HINSTANCE__ *hInstance,
struct HINSTANCE__ *hPrevInstance,
char *lpszCmdLine,
int nCmdShow)
{
return main(__argc, __argv);
}
