gboolean jsmn_is_json(const guint8* buf, const size_t len)
{
guint max_tokens = 1024;
jsmntok_t* t;
jsmn_parser p;
gboolean ret = TRUE;
int rcode;
t = g_new0(jsmntok_t, max_tokens);
if (!t)
return FALSE;
jsmn_init(&p);
rcode = jsmn_parse(&p, buf, len, t, max_tokens);
if (rcode < 0) {
switch (rcode) {
case JSMN_ERROR_NOMEM:
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "jsmn: not enough tokens were provided");
break;
case JSMN_ERROR_INVAL:
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "jsmn: invalid character inside JSON string");
break;
case JSMN_ERROR_PART:
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "jsmn: the string is not a full JSON packet, "
"more bytes expected");
break;
default:
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "jsmn: unexpected error");
break;
}
ret = FALSE;
}
g_free(t);
return ret;
}
int wsjsmn_parse(const char *buf, jsmntok_t *tokens, unsigned int max_tokens)
{
jsmn_parser p;
jsmn_init(&p);
return jsmn_parse(&p, buf, strlen(buf), tokens, max_tokens);
}
