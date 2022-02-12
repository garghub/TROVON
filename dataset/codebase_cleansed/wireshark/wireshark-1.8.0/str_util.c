gchar *
ascii_strdown_inplace(gchar *str)
{
gchar *s;
for (s = str; *s; s++)
*s = g_ascii_tolower (*s);
return (str);
}
gchar *
ascii_strup_inplace(gchar *str)
{
gchar *s;
for (s = str; *s; s++)
*s = g_ascii_toupper (*s);
return (str);
}
gboolean
isprint_string(guchar *str)
{
guint pos;
for(pos = 0; str[pos] != '\0'; pos++){
if(!isprint(str[pos])){
return FALSE;
}
}
return TRUE;
}
gboolean
isdigit_string(guchar *str)
{
guint pos;
for(pos = 0; str[pos] != '\0'; pos++){
if(!isdigit(str[pos])){
return FALSE;
}
}
return TRUE;
}
