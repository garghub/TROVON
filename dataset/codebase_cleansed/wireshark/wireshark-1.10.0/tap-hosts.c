static void
hosts_draw(void *dummy _U_)
{
struct addrinfo *ai;
struct sockaddr_in *sa4;
struct sockaddr_in6 *sa6;
char addr_str[ADDRSTRLEN];
int i, tab_count;
printf("# TShark hosts output\n");
printf("#\n");
printf("# Host data gathered from %s\n", cfile.filename);
printf("\n");
for (ai = get_addrinfo_list(); ai; ai = ai->ai_next) {
if (!dump_v4 || ai->ai_family != AF_INET) {
continue;
}
sa4 = (struct sockaddr_in *)(void *)ai->ai_addr;
if (inet_ntop(AF_INET, &(sa4->sin_addr.s_addr), addr_str, ADDRSTRLEN)) {
tab_count = (HOSTNAME_POS - (int)strlen(addr_str)) / 8;
printf("%s", addr_str);
for (i = 0; i < tab_count; i++)
printf("\t");
printf("%s\n", ai->ai_canonname);
}
}
for (ai = get_addrinfo_list(); ai; ai = ai->ai_next) {
if (!dump_v6 || ai->ai_family != AF_INET6) {
continue;
}
sa6 = (struct sockaddr_in6 *)(void *)ai->ai_addr;
if (inet_ntop(AF_INET6, sa6->sin6_addr.s6_addr, addr_str, ADDRSTRLEN)) {
tab_count = (HOSTNAME_POS - (int)strlen(addr_str)) / 8;
printf("%s", addr_str);
for (i = 0; i < tab_count; i++)
printf("\t");
printf("%s\n", ai->ai_canonname);
}
}
}
static void
hosts_init(const char *optarg, void* userdata _U_)
{
GString *error_string;
gchar **tokens;
gint opt_count;
dump_v4 = FALSE;
dump_v6 = FALSE;
if(strcmp(TAP_NAME, optarg)==0) {
dump_v4 = TRUE;
dump_v6 = TRUE;
} else {
tokens = g_strsplit(optarg,",", 0);
opt_count=0;
while (tokens[opt_count]) {
if (strcmp("ipv4", tokens[opt_count]) == 0) {
dump_v4 = TRUE;
} else if (strcmp("ipv6", tokens[opt_count]) == 0) {
dump_v6 = TRUE;
} else if (opt_count > 0) {
fprintf(stderr, "tshark: invalid \"-z " TAP_NAME "[,ipv4|ipv6]\" argument\n");
exit(1);
}
opt_count++;
}
g_strfreev(tokens);
}
error_string=register_tap_listener("frame", NULL, NULL, TL_REQUIRES_PROTO_TREE,
NULL, NULL, hosts_draw);
if(error_string){
fprintf(stderr, "tshark: Couldn't register " TAP_NAME " tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_hosts(void)
{
register_stat_cmd_arg(TAP_NAME, hosts_init, NULL);
}
