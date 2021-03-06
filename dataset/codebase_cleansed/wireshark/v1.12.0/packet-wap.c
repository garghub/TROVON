guint
tvb_get_guintvar (tvbuff_t *tvb, guint offset, guint *octetCount)
{
guint value = 0;
guint octet;
guint counter = 0;
char cont = 1;
#ifdef DEBUG
if (octetCount != NULL)
{
fprintf (stderr, "dissect_wap: Starting tvb_get_guintvar at offset %d, count=%d\n", offset, *octetCount);
}
else
{
fprintf (stderr, "dissect_wap: Starting tvb_get_guintvar at offset %d, count=NULL\n", offset);
}
#endif
while (cont != 0)
{
value <<= 7;
octet = tvb_get_guint8 (tvb, offset+counter);
counter += 1;
value += (octet & 0x7F);
cont = (octet & 0x80);
#ifdef DEBUG
fprintf (stderr, "dissect_wap: computing: octet is %d (0x%02x), count=%d, value=%d, cont=%d\n",
octet, octet, counter, value, cont);
#endif
}
if (octetCount != NULL)
{
*octetCount = counter;
#ifdef DEBUG
fprintf (stderr, "dissect_wap: Leaving tvb_get_guintvar count=%d, value=%u\n", *octetCount, value);
#endif
}
return (value);
}
