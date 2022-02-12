gint
wrs_strcmp(gconstpointer a, gconstpointer b)
{
return strcmp((const char*)a, (const char*)b);
}
gint
wrs_strcmp_with_data(gconstpointer a, gconstpointer b, gpointer user_data _U_)
{
return strcmp((const char*)a, (const char*)b);
}
gboolean
wrs_str_equal(gconstpointer a, gconstpointer b)
{
return !strcmp((const char*)a, (const char*)b);
}
guchar
wrs_check_charset(const guchar table[256], const char *str)
{
const char *p = str;
guchar c;
do {
c = *(p++);
} while (table[c]);
return c;
}
guint
wrs_str_hash(gconstpointer v)
{
const signed char *p = v;
guint32 h = *p;
if (h)
for (p += 1; *p != '\0'; p++)
h = (h << 5) - h + *p;
return h;
}
