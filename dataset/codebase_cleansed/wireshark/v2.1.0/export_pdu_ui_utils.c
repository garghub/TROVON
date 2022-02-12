static void
exp_pdu_file_open(exp_pdu_t *exp_pdu_tap_data)
{
int import_file_fd;
char *tmpname, *capfile_name;
int err;
import_file_fd = create_tempfile(&tmpname, "Wireshark_PDU_", NULL);
capfile_name = g_strdup(tmpname);
err = exp_pdu_open(exp_pdu_tap_data, import_file_fd,
g_strdup_printf("Dump of PDUs from %s", cfile.filename));
if (err != 0) {
open_failure_alert_box(capfile_name ? capfile_name : "temporary file", err, TRUE);
goto end;
}
cf_retap_packets(&cfile);
err = exp_pdu_close(exp_pdu_tap_data);
if (err!= 0) {
write_failure_alert_box(capfile_name, err);
}
if (cf_open(&cfile, capfile_name, WTAP_TYPE_AUTO, TRUE , &err) != CF_OK) {
open_failure_alert_box(capfile_name, err, FALSE);
goto end;
}
switch (cf_read(&cfile, FALSE)) {
case CF_READ_OK:
case CF_READ_ERROR:
break;
case CF_READ_ABORTED:
break;
}
end:
g_free(capfile_name);
}
gboolean
do_export_pdu(const char *filter, gchar *tap_name, exp_pdu_t *exp_pdu_tap_data)
{
char *error;
error = exp_pdu_pre_open(tap_name, filter, exp_pdu_tap_data);
if (error) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error);
g_free(error);
return FALSE;
}
exp_pdu_file_open(exp_pdu_tap_data);
return TRUE;
}
