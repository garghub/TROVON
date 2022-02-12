static int
ansi_a_stat_packet(
void *tapdata,
packet_info *pinfo _U_,
epan_dissect_t *edt _U_,
const void *data)
{
ansi_a_stat_t *stat_p = (ansi_a_stat_t *)tapdata;
const ansi_a_tap_rec_t *tap_p = (const ansi_a_tap_rec_t *)data;
switch (tap_p->pdu_type)
{
case BSSAP_PDU_TYPE_BSMAP:
stat_p->bsmap_message_type[tap_p->message_type]++;
break;
case BSSAP_PDU_TYPE_DTAP:
stat_p->dtap_message_type[tap_p->message_type]++;
break;
default:
return(0);
}
return(1);
}
static void
ansi_a_stat_draw(
void *tapdata)
{
ansi_a_stat_t *stat_p = (ansi_a_stat_t *)tapdata;
guint8 i;
printf("\n");
printf("=========== ANSI A-i/f Statistics ============================\n");
printf("BSMAP\n");
printf("Message (ID)Type Number\n");
i = 0;
while (ansi_a_ios401_bsmap_strings[i].strptr)
{
if (stat_p->bsmap_message_type[ansi_a_ios401_bsmap_strings[i].value] > 0)
{
printf("0x%02x %-50s%d\n",
ansi_a_ios401_bsmap_strings[i].value,
ansi_a_ios401_bsmap_strings[i].strptr,
stat_p->bsmap_message_type[ansi_a_ios401_bsmap_strings[i].value]);
}
i++;
}
printf("\nDTAP\n");
printf("Message (ID)Type Number\n");
i = 0;
while (ansi_a_ios401_dtap_strings[i].strptr)
{
if (stat_p->dtap_message_type[ansi_a_ios401_dtap_strings[i].value] > 0)
{
printf("0x%02x %-50s%d\n",
ansi_a_ios401_dtap_strings[i].value,
ansi_a_ios401_dtap_strings[i].strptr,
stat_p->dtap_message_type[ansi_a_ios401_dtap_strings[i].value]);
}
i++;
}
printf("==============================================================\n");
}
static void
ansi_a_stat_init(const char *opt_arg _U_, void* userdata _U_)
{
ansi_a_stat_t *stat_p;
GString *err_p;
stat_p = (ansi_a_stat_t *)g_malloc(sizeof(ansi_a_stat_t));
memset(stat_p, 0, sizeof(ansi_a_stat_t));
err_p =
register_tap_listener("ansi_a", stat_p, NULL, 0,
NULL,
ansi_a_stat_packet,
ansi_a_stat_draw);
if (err_p != NULL)
{
g_free(stat_p);
g_string_free(err_p, TRUE);
exit(1);
}
}
void
register_tap_listener_ansi_astat(void)
{
register_stat_cmd_arg("ansi_a,", ansi_a_stat_init,NULL);
}
