size_t epan_base64_decode(char *s)
{
static const char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/\r\n";
int bit_offset, byte_offset, idx, i;
unsigned char *d = (unsigned char *)s;
char *p;
int cr_idx;
cr_idx = (int) (strchr(b64, '\r') - b64);
i=0;
while (*s && (p=strchr(b64, *s))) {
idx = (int)(p - b64);
if(idx < cr_idx) {
byte_offset = (i*6)/8;
bit_offset = (i*6)%8;
d[byte_offset] &= ~((1<<(8-bit_offset))-1);
if (bit_offset < 3) {
d[byte_offset] |= (idx << (2-bit_offset));
} else {
d[byte_offset] |= (idx >> (bit_offset-2));
d[byte_offset+1] = 0;
d[byte_offset+1] |= (idx << (8-(bit_offset-2))) & 0xFF;
}
i++;
}
s++;
}
return i*3/4;
}
tvbuff_t *
base64_to_tvb(tvbuff_t *parent, const char *base64)
{
tvbuff_t *tvb;
char *data = g_strdup(base64);
gint len;
len = (gint) epan_base64_decode(data);
tvb = tvb_new_child_real_data(parent, (const guint8 *)data, len, len);
tvb_set_free_cb(tvb, g_free);
return tvb;
}
