void
EBCDIC_to_ASCII(guint8 *buf, guint bytes)
{
guint i;
guint8 *bufptr;
bufptr = buf;
for (i = 0; i < bytes; i++, bufptr++) {
*bufptr = EBCDIC_translate_ASCII[*bufptr];
}
}
guint8
EBCDIC_to_ASCII1(guint8 c)
{
return EBCDIC_translate_ASCII[c];
}
