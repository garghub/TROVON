static const value_string *
val_to_valstr(guint32 val, const value_valuestring *vvs)
{
gint i = 0;
while (vvs[i].valstrptr) {
if (vvs[i].value == val)
return(vvs[i].valstrptr);
i++;
}
return(NULL);
}
static char *
default_opaque_binary_tag(tvbuff_t *tvb, guint32 offset,
guint8 token _U_, guint8 codepage _U_, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of opaque data)", data_len);
*length += data_len;
return str;
}
static char *
default_opaque_literal_tag(tvbuff_t *tvb, guint32 offset,
const char *token _U_, guint8 codepage _U_, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of opaque data)", data_len);
*length += data_len;
return str;
}
static char *
default_opaque_binary_attr(tvbuff_t *tvb, guint32 offset,
guint8 token _U_, guint8 codepage _U_, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of opaque data)", data_len);
*length += data_len;
return str;
}
static char *
default_opaque_literal_attr(tvbuff_t *tvb, guint32 offset,
const char *token _U_, guint8 codepage _U_, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of opaque data)", data_len);
*length += data_len;
return str;
}
static char *
date_time_from_opaque(tvbuff_t *tvb, guint32 offset, guint32 data_len)
{
char *str;
switch (data_len) {
case 4:
str = wmem_strdup_printf(wmem_packet_scope(), "%%DateTime: "
"%02x%02x-%02x-%02xT00:00:00Z",
tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset + 1),
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3));
break;
case 5:
str = wmem_strdup_printf(wmem_packet_scope(), "%%DateTime: "
"%02x%02x-%02x-%02xT%02x:00:00Z",
tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset + 1),
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + 4));
break;
case 6:
str = wmem_strdup_printf(wmem_packet_scope(), "%%DateTime: "
"%02x%02x-%02x-%02xT%02x:%02x:00Z",
tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset + 1),
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + 4),
tvb_get_guint8(tvb, offset + 5));
break;
case 7:
str = wmem_strdup_printf(wmem_packet_scope(), "%%DateTime: "
"%02x%02x-%02x-%02xT%02x:%02x:%02xZ",
tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset + 1),
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + 4),
tvb_get_guint8(tvb, offset + 5),
tvb_get_guint8(tvb, offset + 6));
break;
default:
str = wmem_strdup_printf(wmem_packet_scope(), "<Error: invalid binary %%DateTime "
"(%d bytes of opaque data)>", data_len);
break;
}
return str;
}
static char *
wv_datetime_from_opaque(tvbuff_t *tvb, guint32 offset, guint32 data_len)
{
char *str;
guint16 year;
guint8 month, day, hour, minute, second, time_zone;
guint8 peek;
if (data_len == 6) {
year = tvb_get_guint8(tvb, offset) & 0x3F;
year <<=6;
peek = tvb_get_guint8(tvb, offset + 1);
year += (peek >> 2);
month = (peek & 0x03) << 2;
peek = tvb_get_guint8(tvb, offset + 2);
month += (peek >> 6);
day = (peek & 0x3E) >> 1;
hour = (peek & 0x01) << 4;
peek = tvb_get_guint8(tvb, offset + 3);
hour += (peek >> 4);
minute = (peek & 0x0F) << 2;
peek = tvb_get_guint8(tvb, offset + 4);
minute += (peek >> 6);
second = peek & 0x3F;
time_zone = tvb_get_guint8(tvb, offset + 5);
str = wmem_strdup_printf(wmem_packet_scope(), "WV-CSP DateTime: "
"%04d-%02d-%02dT%02d:%02d:%02d%c",
year, month, day, hour, minute, second, time_zone);
} else {
str = wmem_strdup_printf(wmem_packet_scope(), "<Error: invalid binary WV-CSP DateTime value "
"(%d bytes of opaque data)>", data_len);
}
return str;
}
static char *
wv_integer_from_opaque(tvbuff_t *tvb, guint32 offset, guint32 data_len)
{
char *str;
switch (data_len) {
case 1:
str = wmem_strdup_printf(wmem_packet_scope(), "WV-CSP Integer: %d",
tvb_get_guint8(tvb, offset));
break;
case 2:
str = wmem_strdup_printf(wmem_packet_scope(), "WV-CSP Integer: %d",
tvb_get_ntohs(tvb, offset));
break;
case 3:
str = wmem_strdup_printf(wmem_packet_scope(), "WV-CSP Integer: %d",
tvb_get_ntoh24(tvb, offset));
break;
case 4:
str = wmem_strdup_printf(wmem_packet_scope(), "WV-CSP Integer: %d",
tvb_get_ntohl(tvb, offset));
break;
default:
str = wmem_strdup_printf(wmem_packet_scope(), "<Error: invalid binary WV-CSP Integer value "
"(%d bytes of opaque data)>", data_len);
break;
}
return str;
}
static char *
wv_csp10_opaque_binary_tag(tvbuff_t *tvb, guint32 offset,
guint8 token, guint8 codepage, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
switch (codepage) {
case 0:
switch (token) {
case 0x0B:
case 0x0F:
case 0x1A:
case 0x3C:
str = wv_integer_from_opaque(tvb,
offset + *length, data_len);
break;
case 0x11:
str = wv_datetime_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
case 1:
switch (token) {
case 0x1C:
case 0x32:
str = wv_integer_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
case 3:
switch (token) {
case 0x06:
case 0x0C:
case 0x0D:
case 0x0E:
case 0x11:
case 0x12:
case 0x13:
str = wv_integer_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
default:
break;
}
if (str == NULL) {
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
wv_csp10_opaque_literal_tag(tvbuff_t *tvb, guint32 offset,
const char *token, guint8 codepage _U_, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
if ( token && ( (strcmp(token, "Code") == 0)
|| (strcmp(token, "ContentSize") == 0)
|| (strcmp(token, "MessageCount") == 0)
|| (strcmp(token, "Validity") == 0)
|| (strcmp(token, "KeepAliveTime") == 0)
|| (strcmp(token, "TimeToLive") == 0)
|| (strcmp(token, "AcceptedContentLength") == 0)
|| (strcmp(token, "MultiTrans") == 0)
|| (strcmp(token, "ParserSize") == 0)
|| (strcmp(token, "ServerPollMin") == 0)
|| (strcmp(token, "TCPAddress") == 0)
|| (strcmp(token, "TCPPort") == 0)
|| (strcmp(token, "UDPPort") == 0) ) )
{
str = wv_integer_from_opaque(tvb, offset + *length, data_len);
}
else if ( token && ( strcmp(token, "DateTime") == 0) )
{
str = wv_datetime_from_opaque(tvb, offset + *length, data_len);
}
if (str == NULL) {
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
wv_csp11_opaque_binary_tag(tvbuff_t *tvb, guint32 offset,
guint8 token, guint8 codepage, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
switch (codepage) {
case 0:
switch (token) {
case 0x0B:
case 0x0F:
case 0x1A:
case 0x3C:
str = wv_integer_from_opaque(tvb,
offset + *length, data_len);
break;
case 0x11:
str = wv_datetime_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
case 1:
switch (token) {
case 0x1C:
case 0x32:
str = wv_integer_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
case 3:
switch (token) {
case 0x06:
case 0x0C:
case 0x0D:
case 0x0E:
case 0x12:
case 0x13:
str = wv_integer_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
case 6:
switch (token) {
case 0x1A:
str = wv_datetime_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
default:
break;
}
if (str == NULL) {
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
wv_csp11_opaque_literal_tag(tvbuff_t *tvb, guint32 offset,
const char *token, guint8 codepage _U_, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
if ( token && ( (strcmp(token, "Code") == 0)
|| (strcmp(token, "ContentSize") == 0)
|| (strcmp(token, "MessageCount") == 0)
|| (strcmp(token, "Validity") == 0)
|| (strcmp(token, "KeepAliveTime") == 0)
|| (strcmp(token, "TimeToLive") == 0)
|| (strcmp(token, "AcceptedContentLength") == 0)
|| (strcmp(token, "MultiTrans") == 0)
|| (strcmp(token, "ParserSize") == 0)
|| (strcmp(token, "ServerPollMin") == 0)
|| (strcmp(token, "TCPPort") == 0)
|| (strcmp(token, "UDPPort") == 0) ) )
{
str = wv_integer_from_opaque(tvb, offset + *length, data_len);
}
else
if ( token && ( (strcmp(token, "DateTime") == 0)
|| (strcmp(token, "DeliveryTime") == 0) ) )
{
str = wv_datetime_from_opaque(tvb, offset + *length, data_len);
}
if (str == NULL) {
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
wv_csp12_opaque_binary_tag(tvbuff_t *tvb, guint32 offset,
guint8 token, guint8 codepage, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
switch (codepage) {
case 0:
switch (token) {
case 0x0B:
case 0x0F:
case 0x1A:
case 0x3C:
str = wv_integer_from_opaque(tvb,
offset + *length, data_len);
break;
case 0x11:
str = wv_datetime_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
case 1:
switch (token) {
case 0x1C:
case 0x32:
str = wv_integer_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
case 3:
switch (token) {
case 0x06:
case 0x0C:
case 0x0D:
case 0x0E:
case 0x12:
case 0x13:
str = wv_integer_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
case 6:
switch (token) {
case 0x1A:
str = wv_datetime_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
case 9:
switch (token) {
case 0x08:
case 0x0A:
str = wv_integer_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
default:
break;
}
if (str == NULL) {
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
wv_csp12_opaque_literal_tag(tvbuff_t *tvb, guint32 offset,
const char *token, guint8 codepage _U_, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
if ( token && ( (strcmp(token, "Code") == 0)
|| (strcmp(token, "ContentSize") == 0)
|| (strcmp(token, "MessageCount") == 0)
|| (strcmp(token, "Validity") == 0)
|| (strcmp(token, "KeepAliveTime") == 0)
|| (strcmp(token, "TimeToLive") == 0)
|| (strcmp(token, "AcceptedContentLength") == 0)
|| (strcmp(token, "MultiTrans") == 0)
|| (strcmp(token, "ParserSize") == 0)
|| (strcmp(token, "ServerPollMin") == 0)
|| (strcmp(token, "TCPPort") == 0)
|| (strcmp(token, "UDPPort") == 0)
|| (strcmp(token, "HistoryPeriod") == 0)
|| (strcmp(token, "MaxWatcherList") == 0) ) )
{
str = wv_integer_from_opaque(tvb, offset + *length, data_len);
}
else
if ( token && ( (strcmp(token, "DateTime") == 0)
|| (strcmp(token, "DeliveryTime") == 0) ) )
{
str = wv_datetime_from_opaque(tvb, offset + *length, data_len);
}
if (str == NULL) {
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
wv_csp13_opaque_binary_tag(tvbuff_t *tvb, guint32 offset,
guint8 token, guint8 codepage, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
switch (codepage)
{
case 0:
switch (token)
{
case 0x0B:
case 0x0F:
case 0x1A:
case 0x3C:
str = wv_integer_from_opaque(tvb, offset + *length, data_len);
break;
case 0x11:
str = wv_datetime_from_opaque(tvb, offset + *length, data_len);
break;
default:
break;
}
break;
case 1:
switch (token)
{
case 0x1C:
case 0x25:
case 0x26:
case 0x27:
case 0x28:
case 0x32:
str = wv_integer_from_opaque(tvb, offset + *length, data_len);
break;
default:
break;
}
break;
case 3:
switch (token)
{
case 0x06:
case 0x0C:
case 0x0D:
case 0x0E:
case 0x12:
case 0x13:
case 0x16:
case 0x17:
case 0x18:
case 0x19:
case 0x1B:
case 0x1C:
case 0x1F:
case 0x21:
case 0x24:
str = wv_integer_from_opaque(tvb, offset + *length, data_len);
break;
default:
break;
}
break;
case 5:
switch (token)
{
case 0x3C:
case 0x3D:
case 0x3E:
str = wv_integer_from_opaque(tvb, offset + *length, data_len);
break;
default:
break;
}
break;
case 6:
switch (token)
{
case 0x1A:
case 0x1C:
str = wv_datetime_from_opaque(tvb, offset + *length, data_len);
break;
default:
break;
}
break;
case 9:
switch (token)
{
case 0x08:
case 0x0A:
case 0x25:
case 0x28:
case 0x30:
case 0x3A:
case 0x3B:
str = wv_integer_from_opaque(tvb, offset + *length, data_len);
break;
default:
break;
}
break;
case 10:
switch (token)
{
case 0x0C:
str = wv_integer_from_opaque(tvb, offset + *length, data_len);
break;
default:
break;
}
break;
default:
break;
}
if (str == NULL)
{
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
wv_csp13_opaque_literal_tag(tvbuff_t *tvb, guint32 offset,
const char *token, guint8 codepage _U_, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
if ( token && ( (strcmp(token, "Code") == 0)
|| (strcmp(token, "ContentSize") == 0)
|| (strcmp(token, "MessageCount") == 0)
|| (strcmp(token, "Validity") == 0)
|| (strcmp(token, "KeepAliveTime") == 0)
|| (strcmp(token, "TimeToLive") == 0)
|| (strcmp(token, "AcceptedContentLength") == 0)
|| (strcmp(token, "MultiTrans") == 0)
|| (strcmp(token, "ParserSize") == 0)
|| (strcmp(token, "ServerPollMin") == 0)
|| (strcmp(token, "TCPPort") == 0)
|| (strcmp(token, "UDPPort") == 0)
|| (strcmp(token, "HistoryPeriod") == 0)
|| (strcmp(token, "MaxWatcherList") == 0)
|| (strcmp(token, "SearchFindings") == 0)
|| (strcmp(token, "SearchID") == 0)
|| (strcmp(token, "SearchIndex") == 0)
|| (strcmp(token, "SearchLimit") == 0)
|| (strcmp(token, "AcceptedPullLength") == 0)
|| (strcmp(token, "AcceptedPushLength") == 0)
|| (strcmp(token, "AcceptedRichContentLength") == 0)
|| (strcmp(token, "AcceptedTextContentLength") == 0)
|| (strcmp(token, "SessionPriority") == 0)
|| (strcmp(token, "UserSessionLimit") == 0)
|| (strcmp(token, "MultiTransPerMessage") == 0)
|| (strcmp(token, "ContentPolicyLimit") == 0)
|| (strcmp(token, "AnswerOptionID") == 0)
|| (strcmp(token, "SegmentCount") == 0)
|| (strcmp(token, "SegmentReference") == 0)
|| (strcmp(token, "TryAgainTimeout") == 0)
|| (strcmp(token, "GroupContentLimit") == 0)
|| (strcmp(token, "MessageTotalCount") == 0)
|| (strcmp(token, "PairID") == 0) ) )
{
str = wv_integer_from_opaque(tvb, offset + *length, data_len);
}
else
if ( token && ( (strcmp(token, "DateTime") == 0)
|| (strcmp(token, "DeliveryTime") == 0) ) )
{
str = wv_datetime_from_opaque(tvb, offset + *length, data_len);
}
if (str == NULL) {
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
sic10_opaque_literal_attr(tvbuff_t *tvb, guint32 offset,
const char *token, guint8 codepage _U_, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
if ( token && ( (strcmp(token, "created") == 0)
|| (strcmp(token, "si-expires") == 0) ) )
{
str = date_time_from_opaque(tvb, offset + *length, data_len);
}
if (str == NULL) {
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
sic10_opaque_binary_attr(tvbuff_t *tvb, guint32 offset,
guint8 token, guint8 codepage, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
switch (codepage) {
case 0:
switch (token) {
case 0x0A:
case 0x10:
str = date_time_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
default:
break;
}
if (str == NULL) {
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
emnc10_opaque_literal_attr(tvbuff_t *tvb, guint32 offset,
const char *token, guint8 codepage _U_, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
if ( token && (strcmp(token, "timestamp") == 0) )
{
str = date_time_from_opaque(tvb, offset + *length, data_len);
}
if (str == NULL) {
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
emnc10_opaque_binary_attr(tvbuff_t *tvb, guint32 offset,
guint8 token, guint8 codepage, guint32 *length)
{
guint32 data_len = tvb_get_guintvar(tvb, offset, length);
char *str = NULL;
switch (codepage) {
case 0:
switch (token) {
case 0x05:
str = date_time_from_opaque(tvb,
offset + *length, data_len);
break;
default:
break;
}
break;
default:
break;
}
if (str == NULL) {
str = wmem_strdup_printf(wmem_packet_scope(), "(%d bytes of unparsed opaque data)", data_len);
}
*length += data_len;
return str;
}
static char *
ext_t_0_wml_10(tvbuff_t *tvb, guint32 value, guint32 str_tbl)
{
char *str = wmem_strdup_printf(wmem_packet_scope(), "Variable substitution - escaped: '%s'",
tvb_get_const_stringz(tvb, str_tbl + value, NULL));
return str;
}
static char *
ext_t_1_wml_10(tvbuff_t *tvb, guint32 value, guint32 str_tbl)
{
char *str = wmem_strdup_printf(wmem_packet_scope(), "Variable substitution - unescaped: '%s'",
tvb_get_const_stringz(tvb, str_tbl + value, NULL));
return str;
}
static char *
ext_t_2_wml_10(tvbuff_t *tvb, guint32 value, guint32 str_tbl)
{
char *str = wmem_strdup_printf(wmem_packet_scope(), "Variable substitution - no transformation: '%s'",
tvb_get_const_stringz(tvb, str_tbl + value, NULL));
return str;
}
static char *
ext_t_0_wv_cspc_11(tvbuff_t *tvb _U_, guint32 value, guint32 str_tbl _U_)
{
char *str = wmem_strdup_printf(wmem_packet_scope(), "Common Value: '%s'",
val_to_str_ext(value, &vals_wv_csp_11_element_value_tokens_ext,
"<Unknown WV-CSP 1.1 Common Value token 0x%X>"));
return str;
}
static char *
ext_t_0_wv_cspc_12(tvbuff_t *tvb _U_, guint32 value, guint32 str_tbl _U_)
{
char *str = wmem_strdup_printf(wmem_packet_scope(), "Common Value: '%s'",
val_to_str(value, vals_wv_csp_12_element_value_tokens,
"<Unknown WV-CSP 1.2 Common Value token 0x%X>"));
return str;
}
static char *
ext_t_0_wv_cspc_13(tvbuff_t *tvb _U_, guint32 value, guint32 str_tbl _U_)
{
char *str = wmem_strdup_printf(wmem_packet_scope(), "Common Value: '%s'",
val_to_str(value, vals_wv_csp_13_element_value_tokens,
"<Unknown WV-CSP 1.3 Common Value token 0x%X>"));
return str;
}
static const wbxml_decoding *
wv_csp_discriminator(tvbuff_t *tvb, guint32 offset)
{
guint32 magic_1 = tvb_get_ntohl(tvb, offset + 0);
guint16 magic_2 = tvb_get_ntohs(tvb, offset + 4);
if (magic_1 == 0xFE050331 && magic_2 == 0x2e30)
{
return &decode_wv_cspc_10;
}
else if (magic_1 == 0xC9050331 && magic_2 == 0x2e31)
{
return &decode_wv_cspc_11;
}
else if (magic_1 == 0xC9080331 && magic_2 == 0x2e32)
{
return &decode_wv_cspc_12;
}
else if ( magic_1 == 0xC90B0331 && magic_2 == 0x2E33)
{
return &decode_wv_cspc_13;
}
return &decode_wv_cspc_12;
}
static const wbxml_decoding *get_wbxml_decoding_from_public_id (guint32 public_id)
{
const wbxml_decoding *map = NULL;
DebugLog(("get_wbxml_decoding_from_public_id: public_id = %u\n",
public_id));
if (public_id >= 2) {
const wbxml_integer_list *item = well_known_public_id_list;
while (item && item->public_id && item->map) {
if (item->public_id == public_id) {
map = item->map;
break;
}
item++;
}
}
return map;
}
static const wbxml_decoding *get_wbxml_decoding_from_content_type (
const char *content_type, tvbuff_t *tvb, guint32 offset)
{
const wbxml_decoding *map = NULL;
DebugLog(("get_wbxml_decoding_from_content_type: content_type = [%s]\n",
content_type));
if (content_type && content_type[0]) {
const wbxml_literal_list *item = content_type_list;
while (item && item->content_type) {
if (g_ascii_strcasecmp(content_type, item->content_type) == 0) {
if (item->discriminator != NULL) {
map = item->discriminator(tvb, offset);
}
if (map == NULL) {
map = item->map;
}
break;
}
item++;
}
}
return map;
}
static const char *
map_token (const value_valuestring *token_map, guint8 codepage, guint8 token) {
const value_string *vs;
const char *s;
if (token_map) {
if ((vs = val_to_valstr (codepage, token_map))) {
s = try_val_to_str (token, vs);
if (s) {
DebugLog(("map_token(codepage = %u, token = %u: [%s]\n", codepage, token, s));
return s;
}
DebugLog(("map_token(codepage = %u, token = %u: "
wbxml_UNDEFINED_TOKEN "\n", codepage, token));
return wbxml_UNDEFINED_TOKEN;
}
DebugLog(("map_token(codepage = %u, token = %u: "
wbxml_UNDEFINED_TOKEN_CODE_PAGE "\n", codepage, token));
return wbxml_UNDEFINED_TOKEN_CODE_PAGE;
}
DebugLog(("map_token(codepage = %u, token = %u: "
wbxml_UNDEFINED_TOKEN_MAP "\n", codepage, token));
return wbxml_UNDEFINED_TOKEN_MAP;
}
static void
dissect_wbxml(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_wbxml_common(tvb, pinfo, tree, NULL);
}
static void
dissect_uaprof(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_wbxml_common(tvb, pinfo, tree, &decode_uaprof_wap_248);
}
static void
dissect_wbxml_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
const wbxml_decoding *override_content_map)
{
proto_item *ti;
proto_tree *wbxml_tree;
proto_tree *wbxml_str_tbl_tree;
proto_tree *wbxml_content_tree;
guint8 version;
guint offset = 0;
guint32 len;
guint32 charset = 0;
guint32 charset_len = 0;
guint32 publicid;
guint32 publicid_index = 0;
guint32 publicid_len;
guint32 str_tbl;
guint32 str_tbl_len;
guint32 str_tbl_len_len = 0;
guint8 level = 0;
const wbxml_decoding *content_map = NULL;
gchar *summary = NULL;
guint8 codepage_stag = 0;
guint8 codepage_attr = 0;
DebugLog(("dissect_wbxml: Dissecting packet %u\n", pinfo->fd->num));
switch ( version = tvb_get_guint8 (tvb, 0) ) {
case 0x00:
break;
case 0x01:
case 0x02:
case 0x03:
break;
default:
col_append_fstr(pinfo->cinfo, COL_INFO, " (Unknown WBXML version 0x%02x)", version);
ti = proto_tree_add_item (tree, proto_wbxml, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ", Unknown version 0x%02x", version);
return;
}
publicid = tvb_get_guintvar(tvb, 1, &publicid_len);
if (! publicid) {
publicid_index = tvb_get_guintvar (tvb, 1+publicid_len, &len);
publicid_len += len;
}
offset = 1 + publicid_len;
switch ( version ) {
case 0x00:
break;
case 0x01:
case 0x02:
case 0x03:
charset = tvb_get_guintvar (tvb, offset, &charset_len);
offset += charset_len;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
tvb_get_guintvar (tvb, offset, &str_tbl_len_len);
str_tbl = offset + str_tbl_len_len;
if ( publicid ) {
summary = wmem_strdup_printf(wmem_packet_scope(), "%s, Public ID: \"%s\"",
val_to_str_ext (version, &vals_wbxml_versions_ext, "(unknown 0x%x)"),
val_to_str_ext (publicid, &vals_wbxml_public_ids_ext, "(unknown 0x%x)"));
} else {
len = tvb_strsize (tvb, str_tbl + publicid_index);
summary = wmem_strdup_printf(wmem_packet_scope(), "%s, Public ID: \"%s\"",
val_to_str_ext (version, &vals_wbxml_versions_ext, "(unknown 0x%x)"),
tvb_format_text (tvb, str_tbl + publicid_index, len - 1));
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (WBXML %s)", summary);
ti = proto_tree_add_item (tree, proto_wbxml, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ", Version: %s", summary);
if ( tree ) {
wbxml_tree = proto_item_add_subtree(ti, ett_wbxml);
proto_tree_add_uint (wbxml_tree, hf_wbxml_version,
tvb, 0, 1, version);
if (publicid) {
proto_tree_add_uint(wbxml_tree, hf_wbxml_public_id_known,
tvb, 1, publicid_len, publicid);
} else {
proto_tree_add_item (wbxml_tree, hf_wbxml_public_id_literal,
tvb, 1, publicid_len, ENC_ASCII|ENC_NA);
}
offset = 1 + publicid_len;
if ( version ) {
proto_tree_add_uint (wbxml_tree, hf_wbxml_charset,
tvb, 1 + publicid_len, charset_len, charset);
offset += charset_len;
}
str_tbl_len = tvb_get_guintvar (tvb, offset, &len);
str_tbl = offset + len;
ti = proto_tree_add_text(wbxml_tree,
tvb, offset, len + str_tbl_len, "String table: %u bytes",
str_tbl_len);
if (wbxml_tree && str_tbl_len) {
wbxml_str_tbl_tree = proto_item_add_subtree (ti,
ett_wbxml_str_tbl);
show_wbxml_string_table (wbxml_str_tbl_tree, tvb,
str_tbl, str_tbl_len);
}
offset += len + str_tbl_len;
if (disable_wbxml_token_parsing) {
proto_tree_add_text (wbxml_tree, tvb, offset, -1,
"Data representation not shown "
"(edit WBXML preferences to show)");
return;
}
ti = proto_tree_add_text (wbxml_tree, tvb, offset, -1,
"Data representation");
wbxml_content_tree = proto_item_add_subtree (ti, ett_wbxml_content);
if (wbxml_tree) {
if (override_content_map != NULL) {
content_map = override_content_map;
proto_item_append_text(ti,
" is based on: %s",
content_map->name);
} else {
content_map = get_wbxml_decoding_from_public_id (publicid);
if (! content_map) {
content_map = get_wbxml_decoding_from_content_type(
pinfo->match_string, tvb, offset);
if (! content_map) {
proto_tree_add_text (wbxml_content_tree,
tvb, offset, -1,
"[Rendering of this content type"
" not (yet) supported]");
} else {
proto_item_append_text(ti,
" is based on Content-Type: %s "
"(chosen decoding: %s)",
pinfo->match_string, content_map->name);
}
}
}
if (content_map && skip_wbxml_token_mapping) {
proto_tree_add_text (wbxml_content_tree,
tvb, offset, -1,
"[Rendering of this content type"
" has been disabled "
"(edit WBXML preferences to enable)]");
content_map = NULL;
}
proto_tree_add_text (wbxml_content_tree, tvb,
offset, -1,
"Level | State | Codepage "
"| WBXML Token Description "
"| Rendering");
if (content_map) {
len = parse_wbxml_tag_defined (wbxml_content_tree,
tvb, offset, str_tbl, &level, &codepage_stag,
&codepage_attr, content_map);
} else {
len = parse_wbxml_tag (wbxml_content_tree, tvb, offset,
str_tbl, &level, &codepage_stag, &codepage_attr);
}
}
return;
}
}
static void
show_wbxml_string_table (proto_tree *tree, tvbuff_t *tvb, guint32 str_tbl,
guint32 str_tbl_len)
{
guint32 off = str_tbl;
guint32 len = 0;
guint32 end = str_tbl + str_tbl_len;
proto_tree_add_text (tree, tvb, off, end,
"Start | Length | String");
while (off < end) {
len = tvb_strsize (tvb, off);
proto_tree_add_text (tree, tvb, off, len,
"%6d | %6d | '%s'",
off - str_tbl, len,
tvb_format_text (tvb, off, len-1));
off += len;
}
}
static const char * Indent (guint8 level) {
return indent_buffer + (512 - 2 * (level));
}
static guint32
parse_wbxml_tag_defined (proto_tree *tree, tvbuff_t *tvb, guint32 offset,
guint32 str_tbl, guint8 *level, guint8 *codepage_stag, guint8 *codepage_attr,
const wbxml_decoding *map)
{
guint32 tvb_len = tvb_reported_length (tvb);
guint32 off = offset;
guint32 len;
guint str_len;
guint32 ent;
guint32 idx;
guint8 peek;
guint32 tag_len;
guint8 tag_save_known = 0;
guint8 tag_new_known = 0;
const char *tag_save_literal;
const char *tag_new_literal;
guint8 parsing_tag_content = FALSE;
tag_save_literal = NULL;
DebugLog(("parse_wbxml_tag_defined (level = %u, offset = %u)\n", *level, offset));
while (off < tvb_len) {
peek = tvb_get_guint8 (tvb, off);
DebugLog(("STAG: (top of while) level = %3u, peek = 0x%02X, off = %u, tvb_len = %u\n", *level, peek, off, tvb_len));
if ((peek & 0x3F) < 4) switch (peek) {
case 0x00:
*codepage_stag = tvb_get_guint8 (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 2,
" | Tag | T -->%3d "
"| SWITCH_PAGE (Tag code page) "
"|",
*codepage_stag);
off += 2;
break;
case 0x01:
if (tag_save_known) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| END (Known Tag 0x%02X) "
"| %s</%s>",
*level, *codepage_stag,
tag_save_known, Indent (*level),
tag_save_literal);
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| END (Literal Tag) "
"| %s</%s>",
*level, *codepage_stag, Indent (*level),
tag_save_literal ? tag_save_literal : "");
}
(*level)--;
off++;
DebugLog(("STAG: level = %u, Return: len = %u\n", *level, off - offset));
return (off - offset);
case 0x02:
ent = tvb_get_guintvar (tvb, off+1, &len);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Tag | T %3d "
"| ENTITY "
"| %s'&#%u;'",
*level, *codepage_stag, Indent (*level), ent);
off += 1+len;
break;
case 0x03:
len = tvb_strsize (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Tag | T %3d "
"| STR_I (Inline string) "
"| %s\'%s\'",
*level, *codepage_stag, Indent(*level),
tvb_format_text (tvb, off+1, len-1));
off += 1+len;
break;
case 0x40:
case 0x41:
case 0x42:
len = tvb_strsize (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Tag | T %3d "
"| EXT_I_%1x (Extension Token) "
"| %s(%s: \'%s\')",
*level, *codepage_stag,
peek & 0x0f, Indent (*level),
map_token (map->global, 0, peek),
tvb_format_text (tvb, off+1, len-1));
off += 1+len;
break;
case 0x43:
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| PI (XML Processing Instruction) "
"| %s<?xml",
*level, *codepage_stag, Indent (*level));
len = parse_wbxml_attribute_list_defined (tree, tvb, off,
str_tbl, *level, codepage_attr, map);
off += len;
if (off >= tvb_len) {
DebugLog(("STAG: level = %u, ThrowException: len = %u (short frame)\n", *level, off - offset));
THROW(ReportedBoundsError);
}
proto_tree_add_text (tree, tvb, off-1, 1,
" %3d | Tag | T %3d "
"| END (PI) "
"| %s?>",
*level, *codepage_stag, Indent (*level));
break;
case 0x80:
case 0x81:
case 0x82:
idx = tvb_get_guintvar (tvb, off+1, &len);
{ char *s;
if (map->ext_t[peek & 0x03])
s = (map->ext_t[peek & 0x03])(tvb, idx, str_tbl);
else
s = wmem_strdup_printf(wmem_packet_scope(), "EXT_T_%1x (%s)", peek & 0x03,
map_token (map->global, 0, peek));
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Tag | T %3d "
"| EXT_T_%1x (Extension Token) "
"| %s%s",
*level, *codepage_stag, peek & 0x0f, Indent (*level),
s);
}
off += 1+len;
break;
case 0x83:
idx = tvb_get_guintvar (tvb, off+1, &len);
str_len = tvb_strsize (tvb, str_tbl+idx);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Tag | T %3d "
"| STR_T (Tableref string) "
"| %s\'%s\'",
*level, *codepage_stag, Indent (*level),
tvb_format_text (tvb, str_tbl+idx, str_len-1));
off += 1+len;
break;
case 0xC0:
case 0xC1:
case 0xC2:
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| EXT_%1x (Extension Token) "
"| %s(%s)",
*level, *codepage_stag, peek & 0x0f, Indent (*level),
map_token (map->global, 0, peek));
off++;
break;
case 0xC3:
if (tvb_get_guint8 (tvb, 0)) {
char *str;
if (tag_save_known) {
if (map->opaque_binary_tag) {
str = map->opaque_binary_tag(tvb, off + 1,
tag_save_known, *codepage_stag, &len);
} else {
str = default_opaque_binary_tag(tvb, off + 1,
tag_save_known, *codepage_stag, &len);
}
} else {
if (map->opaque_literal_tag) {
str = map->opaque_literal_tag(tvb, off + 1,
tag_save_literal, *codepage_stag, &len);
} else {
str = default_opaque_literal_tag(tvb, off + 1,
tag_save_literal, *codepage_stag, &len);
}
}
proto_tree_add_text (tree, tvb, off, 1 + len,
" %3d | Tag | T %3d "
"| OPAQUE (Opaque data) "
"| %s%s",
*level, *codepage_stag, Indent (*level), str);
off += 1 + len;
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| RESERVED_2 (Invalid Token!) "
"| WBXML 1.0 parsing stops here.",
*level, *codepage_stag);
off = tvb_len;
DebugLog(("STAG: level = %u, Return: len = %u\n", *level, off - offset));
return (off - offset);
}
break;
} else {
tag_len = 0;
if ((peek & 0x3F) == 4) {
DebugLog(("STAG: LITERAL tag (peek = 0x%02X, off = %u) - TableRef follows!\n", peek, off));
idx = tvb_get_guintvar (tvb, off+1, &tag_len);
str_len = tvb_strsize (tvb, str_tbl+idx);
tag_new_literal = (const gchar*)tvb_get_ptr (tvb, str_tbl+idx, str_len);
tag_new_known = 0;
} else {
tag_new_known = peek & 0x3F;
tag_new_literal = map_token (map->tags, *codepage_stag,
tag_new_known);
}
if (peek & 0x40) {
if (parsing_tag_content) {
DebugLog(("STAG: Tag in Tag - RECURSE! (off = %u)\n", off));
(*level)++;
len = parse_wbxml_tag_defined (tree, tvb, off, str_tbl,
level, codepage_stag, codepage_attr, map);
off += len;
} else {
if ((peek & 0x3F) == 4) {
tag_save_literal = tag_new_literal;
tag_save_known = 0;
} else {
tag_save_known = tag_new_known;
tag_save_literal = tag_new_literal;
}
if (peek & 0x80) {
if (tag_new_known) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| Known Tag 0x%02X (AC) "
"| %s<%s",
*level, *codepage_stag, tag_new_known,
Indent (*level), tag_new_literal);
off++;
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| LITERAL_AC (Literal tag) (AC) "
"| %s<%s",
*level, *codepage_stag, Indent (*level), tag_new_literal);
off += 1 + tag_len;
}
len = parse_wbxml_attribute_list_defined (tree, tvb,
off, str_tbl, *level, codepage_attr, map);
off += len;
if (off >= tvb_len) {
DebugLog(("STAG: level = %u, ThrowException: len = %u (short frame)\n",
*level, off - offset));
THROW(ReportedBoundsError);
}
proto_tree_add_text (tree, tvb, off-1, 1,
" %3d | Tag | T %3d "
"| END (attribute list) "
"| %s>",
*level, *codepage_stag, Indent (*level));
} else {
if (tag_new_known) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| Known Tag 0x%02X (.C) "
"| %s<%s>",
*level, *codepage_stag, tag_new_known,
Indent (*level), tag_new_literal);
off++;
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| LITERAL_C (Literal Tag) (.C) "
"| %s<%s>",
*level, *codepage_stag, Indent (*level),
tag_new_literal);
off += 1 + tag_len;
}
}
parsing_tag_content = TRUE;
DebugLog(("Tag in Tag - No recursion this time! (off = %u)\n", off));
}
} else {
DebugLog(("<Tag/> in Tag - No recursion! (off = %u)\n", off));
(*level)++;
if (peek & 0x80) {
if (tag_new_known) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| Known Tag 0x%02X (A.) "
"| %s<%s",
*level, *codepage_stag, tag_new_known,
Indent (*level), tag_new_literal);
off++;
len = parse_wbxml_attribute_list_defined (tree, tvb,
off, str_tbl, *level, codepage_attr, map);
off += len;
if (off > tvb_len) {
DebugLog(("STAG: level = %u, ThrowException: len = %u (short frame)\n", *level, off - offset));
THROW(ReportedBoundsError);
}
proto_tree_add_text (tree, tvb, off-1, 1,
" %3d | Tag | T %3d "
"| END (Known Tag) "
"| %s/>",
*level, *codepage_stag, Indent (*level));
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| LITERAL_A (Literal Tag) (A.) "
"| %s<%s",
*level, *codepage_stag, Indent (*level), tag_new_literal);
off += 1 + tag_len;
len = parse_wbxml_attribute_list_defined (tree, tvb,
off, str_tbl, *level, codepage_attr, map);
off += len;
if (off >= tvb_len) {
DebugLog(("STAG: level = %u, ThrowException: len = %u (short frame)\n", *level, off - offset));
THROW(ReportedBoundsError);
}
proto_tree_add_text (tree, tvb, off-1, 1,
" %3d | Tag | T %3d "
"| END (Literal Tag) "
"| %s/>",
*level, *codepage_stag, Indent (*level));
}
} else {
if (tag_new_known) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| Known Tag 0x%02x (..) "
"| %s<%s />",
*level, *codepage_stag, tag_new_known,
Indent (*level), tag_new_literal);
off++;
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| LITERAL (Literal Tag) (..) "
"| %s<%s />",
*level, *codepage_stag, Indent (*level),
tag_new_literal);
off += 1 + tag_len;
}
}
(*level)--;
}
}
}
DebugLog(("STAG: level = %u, Return: len = %u (end of function body)\n", *level, off - offset));
return (off - offset);
}
static guint32
parse_wbxml_tag (proto_tree *tree, tvbuff_t *tvb, guint32 offset,
guint32 str_tbl, guint8 *level,
guint8 *codepage_stag, guint8 *codepage_attr)
{
guint32 tvb_len = tvb_reported_length (tvb);
guint32 off = offset;
guint32 len;
guint str_len;
guint32 ent;
guint32 idx;
guint8 peek;
guint32 tag_len;
guint8 tag_save_known = 0;
guint8 tag_new_known = 0;
const char *tag_save_literal;
const char *tag_new_literal;
char *tag_save_buf = NULL;
char *tag_new_buf = NULL;
guint8 parsing_tag_content = FALSE;
tag_save_literal = NULL;
DebugLog(("parse_wbxml_tag (level = %u, offset = %u)\n", *level, offset));
while (off < tvb_len) {
peek = tvb_get_guint8 (tvb, off);
DebugLog(("STAG: (top of while) level = %3u, peek = 0x%02X, off = %u, tvb_len = %u\n", *level, peek, off, tvb_len));
if ((peek & 0x3F) < 4) switch (peek) {
case 0x00:
*codepage_stag = tvb_get_guint8 (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 2,
" | Tag | T -->%3d "
"| SWITCH_PAGE (Tag code page) "
"|",
*codepage_stag);
off += 2;
break;
case 0x01:
if (tag_save_known) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| END (Known Tag 0x%02X) "
"| %s</%s>",
*level, *codepage_stag, tag_save_known,
Indent (*level),
tag_save_literal);
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| END (Literal Tag) "
"| %s</%s>",
*level, *codepage_stag, Indent (*level),
tag_save_literal ? tag_save_literal : "");
}
(*level)--;
off++;
DebugLog(("STAG: level = %u, Return: len = %u\n",
*level, off - offset));
return (off - offset);
case 0x02:
ent = tvb_get_guintvar (tvb, off+1, &len);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Tag | T %3d "
"| ENTITY "
"| %s'&#%u;'",
*level, *codepage_stag, Indent (*level), ent);
off += 1+len;
break;
case 0x03:
len = tvb_strsize (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Tag | T %3d "
"| STR_I (Inline string) "
"| %s\'%s\'",
*level, *codepage_stag, Indent(*level),
tvb_format_text (tvb, off+1, len-1));
off += 1+len;
break;
case 0x40:
case 0x41:
case 0x42:
len = tvb_strsize (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Tag | T %3d "
"| EXT_I_%1x (Extension Token) "
"| %s(Inline string extension: \'%s\')",
*level, *codepage_stag, peek & 0x0f, Indent (*level),
tvb_format_text (tvb, off+1, len-1));
off += 1+len;
break;
case 0x43:
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| PI (XML Processing Instruction) "
"| %s<?xml",
*level, *codepage_stag, Indent (*level));
len = parse_wbxml_attribute_list (tree, tvb, off, str_tbl,
*level, codepage_attr);
off += len;
if (off >= tvb_len) {
DebugLog(("STAG: level = %u, ThrowException: len = %u (short frame)\n",
*level, off - offset));
THROW(ReportedBoundsError);
}
proto_tree_add_text (tree, tvb, off-1, 1,
" %3d | Tag | T %3d "
"| END (PI) "
"| %s?>",
*level, *codepage_stag, Indent (*level));
break;
case 0x80:
case 0x81:
case 0x82:
idx = tvb_get_guintvar (tvb, off+1, &len);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Tag | T %3d "
"| EXT_T_%1x (Extension Token) "
"| %s(Extension Token, integer value: %u)",
*level, *codepage_stag, peek & 0x0f, Indent (*level),
idx);
off += 1+len;
break;
case 0x83:
idx = tvb_get_guintvar (tvb, off+1, &len);
str_len = tvb_strsize (tvb, str_tbl+idx);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Tag | T %3d "
"| STR_T (Tableref string) "
"| %s\'%s\'",
*level, *codepage_stag, Indent (*level),
tvb_format_text (tvb, str_tbl+idx, str_len-1));
off += 1+len;
break;
case 0xC0:
case 0xC1:
case 0xC2:
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| EXT_%1x (Extension Token) "
"| %s(Single-byte extension)",
*level, *codepage_stag, peek & 0x0f, Indent (*level));
off++;
break;
case 0xC3:
if (tvb_get_guint8 (tvb, 0)) {
idx = tvb_get_guintvar (tvb, off+1, &len);
proto_tree_add_text (tree, tvb, off, 1 + len + idx,
" %3d | Tag | T %3d "
"| OPAQUE (Opaque data) "
"| %s(%d bytes of opaque data)",
*level, *codepage_stag, Indent (*level), idx);
off += 1+len+idx;
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| RESERVED_2 (Invalid Token!) "
"| WBXML 1.0 parsing stops here.",
*level, *codepage_stag);
off = tvb_len;
DebugLog(("STAG: level = %u, Return: len = %u\n",
*level, off - offset));
return (off - offset);
}
break;
} else {
tag_len = 0;
if ((peek & 0x3F) == 4) {
DebugLog(("STAG: LITERAL tag (peek = 0x%02X, off = %u)"
" - TableRef follows!\n", peek, off));
idx = tvb_get_guintvar (tvb, off+1, &tag_len);
str_len = tvb_strsize (tvb, str_tbl+idx);
tag_new_literal = (const gchar*)tvb_get_ptr (tvb, str_tbl+idx, str_len);
tag_new_known = 0;
} else {
tag_new_known = peek & 0x3F;
tag_new_buf=wmem_strdup_printf(wmem_packet_scope(), "Tag_0x%02X",
tag_new_known);
tag_new_literal = tag_new_buf;
}
if (peek & 0x40) {
if (parsing_tag_content) {
DebugLog(("STAG: Tag in Tag - RECURSE! (off = %u)\n", off));
(*level)++;
len = parse_wbxml_tag (tree, tvb, off, str_tbl, level,
codepage_stag, codepage_attr);
off += len;
} else {
if ((peek & 0x3F) == 4) {
tag_save_literal = tag_new_literal;
tag_save_known = 0;
} else {
tag_save_known = tag_new_known;
tag_save_buf=wmem_strdup_printf(wmem_packet_scope(), "Tag_0x%02X",
tag_new_known);
tag_save_literal = tag_save_buf;
}
if (peek & 0x80) {
if (tag_new_known) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| Known Tag 0x%02X (AC) "
"| %s<%s",
*level, *codepage_stag, tag_new_known,
Indent (*level), tag_new_literal);
off++;
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| LITERAL_AC (Literal tag) (AC) "
"| %s<%s",
*level, *codepage_stag, Indent (*level),
tag_new_literal);
off += 1 + tag_len;
}
len = parse_wbxml_attribute_list (tree, tvb,
off, str_tbl, *level, codepage_attr);
off += len;
if (off >= tvb_len) {
DebugLog(("STAG: level = %u, ThrowException: "
"len = %u (short frame)\n",
*level, off - offset));
THROW(ReportedBoundsError);
}
proto_tree_add_text (tree, tvb, off-1, 1,
" %3d | Tag | T %3d "
"| END (attribute list) "
"| %s>",
*level, *codepage_stag, Indent (*level));
} else {
if (tag_new_known) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| Known Tag 0x%02X (.C) "
"| %s<%s>",
*level, *codepage_stag, tag_new_known,
Indent (*level), tag_new_literal);
off++;
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| LITERAL_C (Literal Tag) (.C) "
"| %s<%s>",
*level, *codepage_stag, Indent (*level),
tag_new_literal);
off += 1 + tag_len;
}
}
parsing_tag_content = TRUE;
DebugLog(("Tag in Tag - No recursion this time! "
"(off = %u)\n", off));
}
} else {
DebugLog(("<Tag/> in Tag - No recursion! (off = %u)\n", off));
(*level)++;
if (peek & 0x80) {
if (tag_new_known) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| Known Tag 0x%02X (A.) "
"| %s<%s",
*level, *codepage_stag, tag_new_known,
Indent (*level), tag_new_literal);
off++;
len = parse_wbxml_attribute_list (tree, tvb,
off, str_tbl, *level, codepage_attr);
off += len;
if (off >= tvb_len) {
DebugLog(("STAG: level = %u, ThrowException: "
"len = %u (short frame)\n",
*level, off - offset));
THROW(ReportedBoundsError);
}
proto_tree_add_text (tree, tvb, off-1, 1,
" %3d | Tag | T %3d "
"| END (Known Tag) "
"| %s/>",
*level, *codepage_stag, Indent (*level));
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| LITERAL_A (Literal Tag) (A.) "
"| %s<%s",
*level, *codepage_stag, Indent (*level),
tag_new_literal);
off += 1 + tag_len;
len = parse_wbxml_attribute_list (tree, tvb,
off, str_tbl, *level, codepage_attr);
off += len;
if (off >= tvb_len) {
DebugLog(("STAG: level = %u, ThrowException: "
"len = %u (short frame)\n",
*level, off - offset));
THROW(ReportedBoundsError);
}
proto_tree_add_text (tree, tvb, off-1, 1,
" %3d | Tag | T %3d "
"| END (Literal Tag) "
"| %s/>",
*level, *codepage_stag, Indent (*level));
}
} else {
if (tag_new_known) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| Known Tag 0x%02x (..) "
"| %s<%s />",
*level, *codepage_stag, tag_new_known,
Indent (*level), tag_new_literal);
off++;
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Tag | T %3d "
"| LITERAL (Literal Tag) (..) "
"| %s<%s />",
*level, *codepage_stag, Indent (*level),
tag_new_literal);
off += 1 + tag_len;
}
}
(*level)--;
}
}
}
DebugLog(("STAG: level = %u, Return: len = %u (end of function body)\n",
*level, off - offset));
return (off - offset);
}
static guint32
parse_wbxml_attribute_list_defined (proto_tree *tree, tvbuff_t *tvb,
guint32 offset, guint32 str_tbl, guint8 level, guint8 *codepage_attr,
const wbxml_decoding *map)
{
guint32 tvb_len = tvb_reported_length (tvb);
guint32 off = offset;
guint32 len;
guint str_len;
guint32 ent;
guint32 idx;
guint8 peek;
guint8 attr_save_known = 0;
const char *attr_save_literal = NULL;
DebugLog(("parse_wbxml_attr_defined (level = %u, offset = %u)\n",
level, offset));
while (off < tvb_len) {
peek = tvb_get_guint8 (tvb, off);
DebugLog(("ATTR: (top of while) level = %3u, peek = 0x%02X, "
"off = %u, tvb_len = %u\n", level, peek, off, tvb_len));
if ((peek & 0x3F) < 5) switch (peek) {
case 0x00:
*codepage_attr = tvb_get_guint8 (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 2,
" | Attr | A -->%3d "
"| SWITCH_PAGE (Attr code page) |",
*codepage_attr);
off += 2;
break;
case 0x01:
off++;
DebugLog(("ATTR: level = %u, Return: len = %u\n",
level, off - offset));
return (off - offset);
case 0x02:
ent = tvb_get_guintvar (tvb, off+1, &len);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Attr | A %3d "
"| ENTITY "
"| %s'&#%u;'",
level, *codepage_attr, Indent (level), ent);
off += 1+len;
break;
case 0x03:
len = tvb_strsize (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Attr | A %3d "
"| STR_I (Inline string) "
"| %s\'%s\'",
level, *codepage_attr, Indent (level),
tvb_format_text (tvb, off+1, len-1));
off += 1+len;
break;
case 0x04:
idx = tvb_get_guintvar (tvb, off+1, &len);
str_len = tvb_strsize (tvb, str_tbl+idx);
attr_save_known = 0;
attr_save_literal = tvb_format_text (tvb,
str_tbl+idx, str_len-1);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Attr | A %3d "
"| LITERAL (Literal Attribute) "
"| %s<%s />",
level, *codepage_attr, Indent (level),
attr_save_literal);
off += 1+len;
break;
case 0x40:
case 0x41:
case 0x42:
len = tvb_strsize (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Attr | A %3d "
"| EXT_I_%1x (Extension Token) "
"| %s(%s: \'%s\')",
level, *codepage_attr, peek & 0x0f, Indent (level),
map_token (map->global, 0, peek),
tvb_format_text (tvb, off+1, len-1));
off += 1+len;
break;
case 0x80:
case 0x81:
case 0x82:
idx = tvb_get_guintvar (tvb, off+1, &len);
{ char *s;
if (map->ext_t[peek & 0x03])
s = (map->ext_t[peek & 0x03])(tvb, idx, str_tbl);
else
s = wmem_strdup_printf(wmem_packet_scope(), "EXT_T_%1x (%s)", peek & 0x03,
map_token (map->global, 0, peek));
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Tag | T %3d "
"| EXT_T_%1x (Extension Token) "
"| %s%s)",
level, *codepage_attr, peek & 0x0f, Indent (level),
s);
}
off += 1+len;
break;
case 0x83:
idx = tvb_get_guintvar (tvb, off+1, &len);
str_len = tvb_strsize (tvb, str_tbl+idx);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Attr | A %3d "
"| STR_T (Tableref string) "
"| %s\'%s\'",
level, *codepage_attr, Indent (level),
tvb_format_text (tvb, str_tbl+idx, str_len-1));
off += 1+len;
break;
case 0xC0:
case 0xC1:
case 0xC2:
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Attr | A %3d "
"| EXT_%1x (Extension Token) "
"| %s(%s)",
level, *codepage_attr, peek & 0x0f, Indent (level),
map_token (map->global, 0, peek));
off++;
break;
case 0xC3:
if (tvb_get_guint8 (tvb, 0)) {
char *str;
if (attr_save_known) {
if (map->opaque_binary_attr) {
str = map->opaque_binary_attr(tvb, off + 1,
attr_save_known, *codepage_attr, &len);
} else {
str = default_opaque_binary_attr(tvb, off + 1,
attr_save_known, *codepage_attr, &len);
}
} else {
if (map->opaque_literal_tag) {
str = map->opaque_literal_attr(tvb, off + 1,
attr_save_literal, *codepage_attr, &len);
} else {
str = default_opaque_literal_attr(tvb, off + 1,
attr_save_literal, *codepage_attr, &len);
}
}
proto_tree_add_text (tree, tvb, off, 1 + len,
" %3d | Attr | A %3d "
"| OPAQUE (Opaque data) "
"| %s%s",
level, *codepage_attr, Indent (level), str);
off += 1 + len;
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Attr | A %3d "
"| RESERVED_2 (Invalid Token!) "
"| WBXML 1.0 parsing stops here.",
level, *codepage_attr);
off = tvb_len;
DebugLog(("ATTR: level = %u, Return: len = %u\n",
level, off - offset));
return (off - offset);
}
break;
default:
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Attr | A %3d "
"| %-10s (Invalid Token!) "
"| WBXML parsing stops here.",
level, *codepage_attr,
val_to_str_ext (peek, &vals_wbxml1x_global_tokens_ext, "(unknown 0x%x)"));
off = tvb_len;
break;
} else {
if (peek & 0x80) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Attr | A %3d "
"| Known attrValue 0x%02X "
"| %s%s",
level, *codepage_attr, peek & 0x7f, Indent (level),
map_token (map->attrValue, *codepage_attr, peek));
off++;
} else {
attr_save_known = peek & 0x7f;
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Attr | A %3d "
"| Known attrStart 0x%02X "
"| %s%s",
level, *codepage_attr, attr_save_known, Indent (level),
map_token (map->attrStart, *codepage_attr, peek));
off++;
}
}
}
DebugLog(("ATTR: level = %u, Return: len = %u (end of function body)\n",
level, off - offset));
return (off - offset);
}
static guint32
parse_wbxml_attribute_list (proto_tree *tree, tvbuff_t *tvb,
guint32 offset, guint32 str_tbl, guint8 level, guint8 *codepage_attr)
{
guint32 tvb_len = tvb_reported_length (tvb);
guint32 off = offset;
guint32 len;
guint str_len;
guint32 ent;
guint32 idx;
guint8 peek;
DebugLog(("parse_wbxml_attr (level = %u, offset = %u)\n", level, offset));
while (off < tvb_len) {
peek = tvb_get_guint8 (tvb, off);
DebugLog(("ATTR: (top of while) level = %3u, peek = 0x%02X, "
"off = %u, tvb_len = %u\n", level, peek, off, tvb_len));
if ((peek & 0x3F) < 5) switch (peek) {
case 0x00:
*codepage_attr = tvb_get_guint8 (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 2,
" | Attr | A -->%3d "
"| SWITCH_PAGE (Attr code page) |",
*codepage_attr);
off += 2;
break;
case 0x01:
off++;
DebugLog(("ATTR: level = %u, Return: len = %u\n",
level, off - offset));
return (off - offset);
case 0x02:
ent = tvb_get_guintvar (tvb, off+1, &len);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Attr | A %3d "
"| ENTITY "
"| %s'&#%u;'",
level, *codepage_attr, Indent (level), ent);
off += 1+len;
break;
case 0x03:
len = tvb_strsize (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Attr | A %3d "
"| STR_I (Inline string) "
"| %s\'%s\'",
level, *codepage_attr, Indent (level),
tvb_format_text (tvb, off+1, len-1));
off += 1+len;
break;
case 0x04:
idx = tvb_get_guintvar (tvb, off+1, &len);
str_len = tvb_strsize (tvb, str_tbl+idx);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Attr | A %3d "
"| LITERAL (Literal Attribute) "
"| %s<%s />",
level, *codepage_attr, Indent (level),
tvb_format_text (tvb, str_tbl+idx, str_len-1));
off += 1+len;
break;
case 0x40:
case 0x41:
case 0x42:
len = tvb_strsize (tvb, off+1);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Attr | A %3d "
"| EXT_I_%1x (Extension Token) "
"| %s(Inline string extension: \'%s\')",
level, *codepage_attr, peek & 0x0f, Indent (level),
tvb_format_text (tvb, off+1, len-1));
off += 1+len;
break;
case 0x80:
case 0x81:
case 0x82:
idx = tvb_get_guintvar (tvb, off+1, &len);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Attr | A %3d "
"| EXT_T_%1x (Extension Token) "
"| %s(Extension Token, integer value: %u)",
level, *codepage_attr, peek & 0x0f, Indent (level),
idx);
off += 1+len;
break;
case 0x83:
idx = tvb_get_guintvar (tvb, off+1, &len);
str_len = tvb_strsize (tvb, str_tbl+idx);
proto_tree_add_text (tree, tvb, off, 1+len,
" %3d | Attr | A %3d "
"| STR_T (Tableref string) "
"| %s\'%s\'",
level, *codepage_attr, Indent (level),
tvb_format_text (tvb, str_tbl+idx, str_len-1));
off += 1+len;
break;
case 0xC0:
case 0xC1:
case 0xC2:
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Attr | A %3d "
"| EXT_%1x (Extension Token) "
"| %s(Single-byte extension)",
level, *codepage_attr, peek & 0x0f, Indent (level));
off++;
break;
case 0xC3:
if (tvb_get_guint8 (tvb, 0)) {
idx = tvb_get_guintvar (tvb, off+1, &len);
proto_tree_add_text (tree, tvb, off, 1 + len + idx,
" %3d | Attr | A %3d "
"| OPAQUE (Opaque data) "
"| %s(%d bytes of opaque data)",
level, *codepage_attr, Indent (level), idx);
off += 1+len+idx;
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Attr | A %3d "
"| RESERVED_2 (Invalid Token!) "
"| WBXML 1.0 parsing stops here.",
level, *codepage_attr);
off = tvb_len;
DebugLog(("ATTR: level = %u, Return: len = %u\n",
level, off - offset));
return (off - offset);
}
break;
default:
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Attr | A %3d "
"| %-10s (Invalid Token!) "
"| WBXML parsing stops here.",
level, *codepage_attr,
val_to_str_ext (peek, &vals_wbxml1x_global_tokens_ext, "(unknown 0x%x)"));
off = tvb_len;
break;
} else {
if (peek & 0x80) {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Attr | A %3d "
"| Known attrValue 0x%02X "
"| %sattrValue_0x%02X",
level, *codepage_attr, peek & 0x7f, Indent (level),
peek);
off++;
} else {
proto_tree_add_text (tree, tvb, off, 1,
" %3d | Attr | A %3d "
"| Known attrStart 0x%02X "
"| %sattrStart_0x%02X",
level, *codepage_attr, peek & 0x7f, Indent (level),
peek);
off++;
}
}
}
DebugLog(("ATTR: level = %u, Return: len = %u (end of function body)\n",
level, off - offset));
return (off - offset);
}
void
proto_register_wbxml(void)
{
module_t *wbxml_module;
static hf_register_info hf[] = {
{ &hf_wbxml_version,
{ "Version",
"wbxml.version",
FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&vals_wbxml_versions_ext, 0x00,
"WBXML Version", HFILL }
},
{ &hf_wbxml_public_id_known,
{ "Public Identifier (known)",
"wbxml.public_id.known",
FT_UINT32, BASE_HEX|BASE_EXT_STRING,
&vals_wbxml_public_ids_ext, 0x00,
"WBXML Known Public Identifier (integer)", HFILL }
},
{ &hf_wbxml_public_id_literal,
{ "Public Identifier (literal)",
"wbxml.public_id.literal",
FT_STRING, BASE_NONE,
NULL, 0x00,
"WBXML Literal Public Identifier (text string)", HFILL }
},
{ &hf_wbxml_charset,
{ "Character Set",
"wbxml.charset",
FT_UINT32, BASE_HEX|BASE_EXT_STRING,
&wap_mib_enum_vals_character_sets_ext, 0x00,
"WBXML Character Set", HFILL }
},
};
static gint *ett[] = {
&ett_wbxml,
&ett_wbxml_str_tbl,
&ett_wbxml_content,
};
proto_wbxml = proto_register_protocol(
"WAP Binary XML",
"WBXML",
"wbxml"
);
proto_register_field_array(proto_wbxml, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
wbxml_module = prefs_register_protocol(proto_wbxml, NULL);
prefs_register_bool_preference(wbxml_module,
"skip_wbxml_token_mapping",
"Skip the mapping of WBXML tokens to media type tokens.",
"Enable this preference if you want to view the WBXML "
"tokens without the representation in a media type "
"(e.g., WML). Tokens will show up as Tag_0x12, "
"attrStart_0x08 or attrValue_0x0B for example.",
&skip_wbxml_token_mapping);
prefs_register_bool_preference(wbxml_module,
"disable_wbxml_token_parsing",
"Disable the parsing of the WBXML tokens.",
"Enable this preference if you want to skip the "
"parsing of the WBXML tokens that constitute the body "
"of the WBXML document. Only the WBXML header will be "
"dissected (and visualized) then.",
&disable_wbxml_token_parsing);
register_dissector("wbxml", dissect_wbxml, proto_wbxml);
register_dissector("wbxml-uaprof", dissect_uaprof, proto_wbxml);
}
void
proto_reg_handoff_wbxml(void)
{
dissector_handle_t wbxml_handle;
wbxml_handle = find_dissector("wbxml");
dissector_add_string("media_type",
"application/vnd.wap.wmlc", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.wap.wta-eventc", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.wap.wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.wap.sic", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.wap.slc", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.wap.coc", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.wap.connectivity-wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.wap.locc+wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.syncml+wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.syncml.dm+wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.oma.drm.rights+wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.wv.csp.wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.ms-sync.wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.ms-sync", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.uplanet.cacheop-wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.uplanet.alert-wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.uplanet.list-wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.uplanet.listcmd-wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.uplanet.channel-wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.uplanet.bearer-choice-wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.phonecom.mmc-wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/vnd.nokia.syncset+wbxml", wbxml_handle);
dissector_add_string("media_type",
"application/x-wap-prov.browser-bookmarks", wbxml_handle);
dissector_add_string("media_type",
"application/x-wap-prov.browser-settings", wbxml_handle);
dissector_add_string("media_type",
"application/x-prov.syncset+wbxml", wbxml_handle);
}
