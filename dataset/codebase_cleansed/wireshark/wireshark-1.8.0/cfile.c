void
cap_file_init(capture_file *cf)
{
cf->filename = NULL;
cf->source = NULL;
cf->is_tempfile = FALSE;
cf->unsaved_changes = FALSE;
cf->count = 0;
cf->has_snap = FALSE;
cf->snap = WTAP_MAX_PACKET_SIZE;
cf->wth = NULL;
cf->rfcode = NULL;
cf->dfilter = NULL;
cf->redissecting = FALSE;
cf->frames = NULL;
}
