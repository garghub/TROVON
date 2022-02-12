static inline int
strncasecmpz(const char *str, const char *cmp, size_t len)
{
if (strlen(cmp) != len)
return len;
return strncasecmp(str, cmp, len);
}
const char *
nouveau_stropt(const char *optstr, const char *opt, int *arglen)
{
while (optstr && *optstr != '\0') {
int len = strcspn(optstr, ",=");
switch (optstr[len]) {
case '=':
if (!strncasecmpz(optstr, opt, len)) {
optstr += len + 1;
*arglen = strcspn(optstr, ",=");
return *arglen ? optstr : NULL;
}
optstr++;
break;
case ',':
optstr++;
break;
default:
break;
}
optstr += len;
}
return NULL;
}
bool
nouveau_boolopt(const char *optstr, const char *opt, bool value)
{
int arglen;
optstr = nouveau_stropt(optstr, opt, &arglen);
if (optstr) {
if (!strncasecmpz(optstr, "0", arglen) ||
!strncasecmpz(optstr, "no", arglen) ||
!strncasecmpz(optstr, "off", arglen) ||
!strncasecmpz(optstr, "false", arglen))
value = false;
else
if (!strncasecmpz(optstr, "1", arglen) ||
!strncasecmpz(optstr, "yes", arglen) ||
!strncasecmpz(optstr, "on", arglen) ||
!strncasecmpz(optstr, "true", arglen))
value = true;
}
return value;
}
int
nouveau_dbgopt(const char *optstr, const char *sub)
{
int mode = 1, level = CONFIG_NOUVEAU_DEBUG_DEFAULT;
while (optstr) {
int len = strcspn(optstr, ",=");
switch (optstr[len]) {
case '=':
if (strncasecmpz(optstr, sub, len))
mode = 0;
optstr++;
break;
default:
if (mode) {
if (!strncasecmpz(optstr, "fatal", len))
level = NV_DBG_FATAL;
else if (!strncasecmpz(optstr, "error", len))
level = NV_DBG_ERROR;
else if (!strncasecmpz(optstr, "warn", len))
level = NV_DBG_WARN;
else if (!strncasecmpz(optstr, "info", len))
level = NV_DBG_INFO;
else if (!strncasecmpz(optstr, "debug", len))
level = NV_DBG_DEBUG;
else if (!strncasecmpz(optstr, "trace", len))
level = NV_DBG_TRACE;
else if (!strncasecmpz(optstr, "paranoia", len))
level = NV_DBG_PARANOIA;
else if (!strncasecmpz(optstr, "spam", len))
level = NV_DBG_SPAM;
}
if (optstr[len] != '\0') {
optstr++;
mode = 1;
break;
}
return level;
}
optstr += len;
}
return level;
}
