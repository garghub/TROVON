void bitswap_buf_inplace(guint8 *buf, size_t len)
{
size_t i;
for (i = 0; i < len; i++)
buf[i] = swaptab[buf[i]];
}
