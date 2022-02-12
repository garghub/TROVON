gint32 strip_trailing_blanks(guint8* a_str, guint32 a_size)
{
gint32 i = 0;
if (a_str != NULL)
{
for (i = a_size - 1; i >= 0; i--)
{
if (a_str[i] != ' ' && a_str[i] != '\0')
break;
else
a_str[i] = '\0';
}
}
return i;
}
