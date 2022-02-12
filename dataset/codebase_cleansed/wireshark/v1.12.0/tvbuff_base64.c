tvbuff_t *
base64_to_tvb(tvbuff_t *parent, const char *base64)
{
tvbuff_t *tvb;
char *data = g_strdup(base64);
gint len;
len = (gint) ws_base64_decode_inplace(data);
tvb = tvb_new_child_real_data(parent, (const guint8 *)data, len, len);
tvb_set_free_cb(tvb, g_free);
return tvb;
}
