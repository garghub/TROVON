void pwc_dec1_init(int type, int release, void *buffer, void *table)
{
}
void pwc_dec1_exit(void)
{
}
int pwc_dec1_alloc(struct pwc_device *pwc)
{
pwc->decompress_data = kmalloc(sizeof(struct pwc_dec1_private), GFP_KERNEL);
if (pwc->decompress_data == NULL)
return -ENOMEM;
return 0;
}
