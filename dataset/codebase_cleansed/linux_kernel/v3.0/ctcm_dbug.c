void ctcm_unregister_dbf_views(void)
{
int x;
for (x = 0; x < CTCM_DBF_INFOS; x++) {
debug_unregister(ctcm_dbf[x].id);
ctcm_dbf[x].id = NULL;
}
}
int ctcm_register_dbf_views(void)
{
int x;
for (x = 0; x < CTCM_DBF_INFOS; x++) {
ctcm_dbf[x].id = debug_register(ctcm_dbf[x].name,
ctcm_dbf[x].pages,
ctcm_dbf[x].areas,
ctcm_dbf[x].len);
if (ctcm_dbf[x].id == NULL) {
ctcm_unregister_dbf_views();
return -ENOMEM;
}
debug_register_view(ctcm_dbf[x].id, &debug_hex_ascii_view);
debug_set_level(ctcm_dbf[x].id, ctcm_dbf[x].level);
}
return 0;
}
void ctcm_dbf_longtext(enum ctcm_dbf_names dbf_nix, int level, char *fmt, ...)
{
char dbf_txt_buf[64];
va_list args;
if (level > (ctcm_dbf[dbf_nix].id)->level)
return;
va_start(args, fmt);
vsnprintf(dbf_txt_buf, sizeof(dbf_txt_buf), fmt, args);
va_end(args);
debug_text_event(ctcm_dbf[dbf_nix].id, level, dbf_txt_buf);
}
