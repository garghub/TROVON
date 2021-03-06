static int
sv_packet(void *prs _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pri)
{
int i;
const sv_frame_data * sv_data = (const sv_frame_data *)pri;
printf("%f %u ", nstime_to_sec(&pinfo->rel_ts), sv_data->smpCnt);
for (i = 0; i < sv_data->num_phsMeas; i++) {
printf("%d ", sv_data->phsMeas[i].value);
}
printf("\n");
return 0;
}
static void
svstat_init(const char *opt_arg _U_, void *userdata _U_)
{
GString *error_string;
error_string = register_tap_listener(
"sv",
NULL,
NULL,
0,
NULL,
sv_packet,
NULL);
if (error_string) {
fprintf(stderr, "tshark: Couldn't register sv,stat tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_sv(void)
{
register_stat_tap_ui(&svstat_ui, NULL);
}
