int pwc_dec1_init(struct pwc_device *pwc, int type, int release, void *buffer)
{
struct pwc_dec1_private *pdec;
if (pwc->decompress_data == NULL) {
pdec = kmalloc(sizeof(struct pwc_dec1_private), GFP_KERNEL);
if (pdec == NULL)
return -ENOMEM;
pwc->decompress_data = pdec;
}
pdec = pwc->decompress_data;
return 0;
}
