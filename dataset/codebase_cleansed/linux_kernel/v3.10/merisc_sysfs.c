static ssize_t merisc_model_show(struct class *class, char *buf)
{
ssize_t ret = 0;
sprintf(buf, "%s\n", merisc_model());
ret = strlen(buf) + 1;
return ret;
}
static ssize_t merisc_revision_show(struct class *class, char *buf)
{
ssize_t ret = 0;
sprintf(buf, "%s\n", merisc_revision());
ret = strlen(buf) + 1;
return ret;
}
static int __init merisc_sysfs_init(void)
{
int status;
status = class_register(&merisc_class);
if (status < 0)
return status;
return 0;
}
