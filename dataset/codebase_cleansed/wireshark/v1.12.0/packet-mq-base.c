guint64 tvb_get_guint64_endian(tvbuff_t *a_tvb, gint a_iOffset, gint a_rep)
{
guint64 iResult;
if (a_rep & ENC_LITTLE_ENDIAN)
iResult = tvb_get_letoh64(a_tvb, a_iOffset);
else
iResult = tvb_get_ntoh64(a_tvb, a_iOffset);
return iResult;
}
guint32 tvb_get_guint32_endian(tvbuff_t *a_tvb, gint a_iOffset, gint a_rep)
{
guint32 iResult;
if (a_rep & ENC_LITTLE_ENDIAN)
iResult = tvb_get_letohl(a_tvb, a_iOffset);
else
iResult = tvb_get_ntohl(a_tvb, a_iOffset);
return iResult;
}
guint16 tvb_get_guint16_endian(tvbuff_t *a_tvb, gint a_iOffset, gint a_rep)
{
guint16 sResult;
if (a_rep & ENC_LITTLE_ENDIAN)
sResult = tvb_get_letohs(a_tvb, a_iOffset);
else
sResult = tvb_get_ntohs(a_tvb, a_iOffset);
return sResult;
}
gint32 strip_trailing_blanks(guint8* a_str, guint32 a_size)
{
gint32 i = 0;
if (a_str != NULL)
{
for (i = a_size-1; i >=0; i--)
{
if (a_str[i] != ' ' && a_str[i] != '\0')
break;
else
a_str[i]='\0';
}
}
return i;
}
