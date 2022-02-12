static ssize_t
compatible_show (struct device *dev, struct device_attribute *attr, char *buf)
{
struct platform_device *of;
const char *compat;
int cplen;
int length = 0;
of = &to_macio_device (dev)->ofdev;
compat = of_get_property(of->dev.of_node, "compatible", &cplen);
if (!compat) {
*buf = '\0';
return 0;
}
while (cplen > 0) {
int l;
length += sprintf (buf, "%s\n", compat);
buf += length;
l = strlen (compat) + 1;
compat += l;
cplen -= l;
}
return length;
}
static ssize_t modalias_show (struct device *dev, struct device_attribute *attr,
char *buf)
{
int len = of_device_get_modalias(dev, buf, PAGE_SIZE - 2);
buf[len] = '\n';
buf[len+1] = 0;
return len+1;
}
static ssize_t devspec_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *ofdev;
ofdev = to_platform_device(dev);
return sprintf(buf, "%s\n", ofdev->dev.of_node->full_name);
}
