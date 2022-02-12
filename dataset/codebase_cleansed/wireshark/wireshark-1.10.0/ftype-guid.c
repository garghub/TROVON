static void
guid_fvalue_set(fvalue_t *fv, gpointer value, gboolean already_copied)
{
g_assert(!already_copied);
fv->value.guid = *(e_guid_t*)value;
}
static gpointer
value_get(fvalue_t *fv)
{
return &(fv->value.guid);
}
static gboolean
get_guid(char *s, e_guid_t *guid)
{
size_t i, n;
char *p, digits[9];
static const char fmt[] = "XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX";
n = strlen(s);
if (n != strlen(fmt))
return FALSE;
for (i=0; i<n; i++) {
if (fmt[i] == 'X') {
if (!isxdigit((guchar)s[i]))
return FALSE;
} else {
if (s[i] != fmt[i])
return FALSE;
}
}
p = s;
strncpy(digits, p, 8);
digits[8] = '\0';
guid->data1 = (guint32)strtoul(digits, NULL, 16);
p += 9;
strncpy(digits, p, 4);
digits[4] = '\0';
guid->data2 = (guint16)strtoul(digits, NULL, 16);
p += 5;
strncpy(digits, p, 4);
digits[4] = '\0';
guid->data3 = (guint16)strtoul(digits, NULL, 16);
p += 5;
for (i=0; i < sizeof(guid->data4); i++) {
if (*p == '-') p++;
digits[0] = *(p++);
digits[1] = *(p++);
digits[2] = '\0';
guid->data4[i] = (guint8)strtoul(digits, NULL, 16);
}
return TRUE;
}
static gboolean
guid_from_unparsed(fvalue_t *fv, char *s, gboolean allow_partial_value _U_, LogFunc logfunc)
{
e_guid_t guid;
if (!get_guid(s, &guid)) {
logfunc("\"%s\" is not a valid GUID.", s);
return FALSE;
}
fv->value.guid = guid;
return TRUE;
}
static int
guid_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_)
{
return GUID_STR_LEN;
}
static void
guid_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, char *buf)
{
guid_to_str_buf(&fv->value.guid, buf, GUID_STR_LEN);
}
static gboolean
cmp_eq(const fvalue_t *a, const fvalue_t *b)
{
return memcmp(&a->value.guid, &b->value.guid, sizeof(e_guid_t)) == 0;
}
static gboolean
cmp_ne(const fvalue_t *a, const fvalue_t *b)
{
return memcmp(&a->value.guid, &b->value.guid, sizeof(e_guid_t)) != 0;
}
void
ftype_register_guid(void)
{
static ftype_t guid_type = {
FT_GUID,
"FT_GUID",
"Globally Unique Identifier",
GUID_LEN,
NULL,
NULL,
guid_from_unparsed,
NULL,
guid_to_repr,
guid_repr_len,
guid_fvalue_set,
NULL,
NULL,
NULL,
NULL,
value_get,
NULL,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
};
ftype_register(FT_GUID, &guid_type);
}
