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
len = utf8s_to_utf16s(s->s, len, UTF16_LITTLE_ENDIAN,
(wchar_t *) &buf[2], 126);
if (len < 0)
return -EINVAL;
buf [0] = (len + 1) * 2;
buf [1] = USB_DT_STRING;
return buf [0];
}
