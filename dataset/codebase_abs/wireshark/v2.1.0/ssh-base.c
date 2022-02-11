T_1 F_1 ( const char * V_1 , const unsigned int V_2 , const char * V_3 ,
const char * V_4 , const char * V_5 , const char * V_6 , char * * V_7 )
{
T_1 V_8 ;
V_8 = F_2 () ;
if ( V_8 == NULL ) {
* V_7 = F_3 ( L_1 ) ;
return NULL ;
}
if ( ! V_1 ) {
* V_7 = F_3 ( L_2 ) ;
goto V_9;
}
if ( F_4 ( V_8 , V_10 , V_1 ) ) {
* V_7 = F_5 ( L_3 , V_1 ) ;
goto V_9;
}
if ( V_2 != 0 ) {
if ( F_4 ( V_8 , V_11 , & V_2 ) ) {
* V_7 = F_5 ( L_4 , V_2 ) ;
goto V_9;
}
}
if ( ! V_3 )
V_3 = F_6 () ;
if ( F_4 ( V_8 , V_12 , V_3 ) ) {
* V_7 = F_5 ( L_5 , V_3 ) ;
goto V_9;
}
F_7 ( V_13 , V_14 , L_6 , V_3 , V_1 , V_2 ) ;
if ( F_8 ( V_8 ) != V_15 ) {
* V_7 = F_5 ( L_7 , V_3 , V_1 , V_2 ,
F_9 ( V_8 ) ) ;
goto V_9;
}
#ifdef F_10
F_7 (LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, (L_8);
if (ssh_userauth_agent(sshs, NULL) == SSH_AUTH_SUCCESS) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, L_9);
return sshs;
}
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, (L_10);
#endif
if (sshkey_path) {
ssh_key pkey = ssh_key_new();
int ret;
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, L_11, sshkey_path);
ret = ssh_pki_import_privkey_file(sshkey_path, sshkey_passphrase, NULL, NULL, &pkey);
if (ret == SSH_OK) {
if (ssh_userauth_publickey(sshs, NULL, pkey) == SSH_AUTH_SUCCESS) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, L_9);
ssh_key_free(pkey);
return sshs;
}
}
ssh_key_free(pkey);
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, L_12, ssh_get_error(sshs));
}
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, L_13);
if (ssh_userauth_publickey_auto(sshs, NULL, NULL) == SSH_AUTH_SUCCESS) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, L_9);
return sshs;
}
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, L_10);
if (password) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, L_14);
if (ssh_userauth_password(sshs, username, password) == SSH_AUTH_SUCCESS) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, L_9);
return sshs;
}
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, L_10);
}
*err_info = g_strdup_printf(L_15);
ssh_disconnect(sshs);
failure:
ssh_free(sshs);
return NULL;
}
int ssh_channel_printf(ssh_channel channel, const char* fmt, ...)
{
gchar* buf;
va_list arg;
int ret = EXIT_SUCCESS;
va_start(arg, fmt);
buf = g_strdup_vprintf(fmt, arg);
if (ssh_channel_write(channel, buf, (guint32)strlen(buf)) == SSH_ERROR)
ret = EXIT_FAILURE;
va_end(arg);
g_free(buf);
return ret;
}
void ssh_cleanup(ssh_session* sshs, ssh_channel* channel)
{
if (*channel) {
ssh_channel_send_eof(*channel);
ssh_channel_close(*channel);
ssh_channel_free(*channel);
*channel = NULL;
}
if (*sshs) {
ssh_disconnect(*sshs);
ssh_free(*sshs);
*sshs = NULL;
}
}
