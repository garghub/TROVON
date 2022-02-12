static int utf8_to_utf16le(const char *s, __le16 *cp, unsigned len)
{
int count = 0;
u8 c;
u16 uchar;
while (len != 0 && (c = (u8) *s++) != 0) {
if (unlikely(c & 0x80)) {
if ((c & 0xe0) == 0xc0) {
uchar = (c & 0x1f) << 6;
c = (u8) *s++;
if ((c & 0xc0) != 0x80)
goto fail;
c &= 0x3f;
uchar |= c;
} else if ((c & 0xf0) == 0xe0) {
uchar = (c & 0x0f) << 12;
c = (u8) *s++;
if ((c & 0xc0) != 0x80)
goto fail;
c &= 0x3f;
uchar |= c << 6;
c = (u8) *s++;
if ((c & 0xc0) != 0x80)
goto fail;
c &= 0x3f;
uchar |= c;
if (0xd800 <= uchar && uchar <= 0xdfff)
goto fail;
} else
goto fail;
} else
uchar = c;
put_unaligned_le16(uchar, cp++);
count++;
len--;
}
return count;
fail:
return -1;
}
int
usb_gadget_get_string (struct usb_gadget_strings *table, int id, u8 *buf)
{
struct usb_string *s;
int len;
if (id == 0) {
buf [0] = 4;
buf [1] = USB_DT_STRING;
buf [2] = (u8) table->language;
buf [3] = (u8) (table->language >> 8);
return 4;
}
for (s = table->strings; s && s->s; s++)
if (s->id == id)
break;
if (!s || !s->s)
return -EINVAL;
len = min ((size_t) 126, strlen (s->s));
memset (buf + 2, 0, 2 * len);
len = utf8_to_utf16le(s->s, (__le16 *)&buf[2], len);
if (len < 0)
return -EINVAL;
buf [0] = (len + 1) * 2;
buf [1] = USB_DT_STRING;
return buf [0];
}
