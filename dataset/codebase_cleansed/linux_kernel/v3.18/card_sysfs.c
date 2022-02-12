static ssize_t status_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct genwqe_dev *cd = dev_get_drvdata(dev);
const char *cs[GENWQE_CARD_STATE_MAX] = { "unused", "used", "error" };
return sprintf(buf, "%s\n", cs[cd->card_state]);
}
static ssize_t appid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
char app_name[5];
struct genwqe_dev *cd = dev_get_drvdata(dev);
genwqe_read_app_id(cd, app_name, sizeof(app_name));
return sprintf(buf, "%s\n", app_name);
}
static ssize_t version_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
u64 slu_id, app_id;
struct genwqe_dev *cd = dev_get_drvdata(dev);
slu_id = __genwqe_readq(cd, IO_SLU_UNITCFG);
app_id = __genwqe_readq(cd, IO_APP_UNITCFG);
return sprintf(buf, "%016llx.%016llx\n", slu_id, app_id);
}
static ssize_t type_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
u8 card_type;
struct genwqe_dev *cd = dev_get_drvdata(dev);
card_type = genwqe_card_type(cd);
return sprintf(buf, "%s\n", (card_type >= ARRAY_SIZE(genwqe_types)) ?
"invalid" : genwqe_types[card_type]);
}
static ssize_t tempsens_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
u64 tempsens;
struct genwqe_dev *cd = dev_get_drvdata(dev);
tempsens = __genwqe_readq(cd, IO_SLU_TEMPERATURE_SENSOR);
return sprintf(buf, "%016llx\n", tempsens);
}
static ssize_t freerunning_timer_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u64 t;
struct genwqe_dev *cd = dev_get_drvdata(dev);
t = __genwqe_readq(cd, IO_SLC_FREE_RUNNING_TIMER);
return sprintf(buf, "%016llx\n", t);
}
static ssize_t queue_working_time_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u64 t;
struct genwqe_dev *cd = dev_get_drvdata(dev);
t = __genwqe_readq(cd, IO_SLC_QUEUE_WTIME);
return sprintf(buf, "%016llx\n", t);
}
static ssize_t base_clock_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u64 base_clock;
struct genwqe_dev *cd = dev_get_drvdata(dev);
base_clock = genwqe_base_clock_frequency(cd);
return sprintf(buf, "%lld\n", base_clock);
}
static ssize_t curr_bitstream_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int curr_bitstream;
struct genwqe_dev *cd = dev_get_drvdata(dev);
curr_bitstream = __genwqe_readq(cd, IO_SLU_BITSTREAM) & 0x1;
return sprintf(buf, "%d\n", curr_bitstream);
}
static ssize_t next_bitstream_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int next_bitstream;
struct genwqe_dev *cd = dev_get_drvdata(dev);
switch ((cd->softreset & 0xc) >> 2) {
case 0x2:
next_bitstream = 0;
break;
case 0x3:
next_bitstream = 1;
break;
default:
next_bitstream = -1;
break;
}
return sprintf(buf, "%d\n", next_bitstream);
}
static ssize_t next_bitstream_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int partition;
struct genwqe_dev *cd = dev_get_drvdata(dev);
if (kstrtoint(buf, 0, &partition) < 0)
return -EINVAL;
switch (partition) {
case 0x0:
cd->softreset = 0x78;
break;
case 0x1:
cd->softreset = 0x7c;
break;
default:
return -EINVAL;
}
__genwqe_writeq(cd, IO_SLC_CFGREG_SOFTRESET, cd->softreset);
return count;
}
static ssize_t reload_bitstream_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int reload;
struct genwqe_dev *cd = dev_get_drvdata(dev);
if (kstrtoint(buf, 0, &reload) < 0)
return -EINVAL;
if (reload == 0x1) {
if (cd->card_state == GENWQE_CARD_UNUSED ||
cd->card_state == GENWQE_CARD_USED)
cd->card_state = GENWQE_CARD_RELOAD_BITSTREAM;
else
return -EIO;
} else {
return -EINVAL;
}
return count;
}
static umode_t genwqe_is_visible(struct kobject *kobj,
struct attribute *attr, int n)
{
unsigned int j;
struct device *dev = container_of(kobj, struct device, kobj);
struct genwqe_dev *cd = dev_get_drvdata(dev);
umode_t mode = attr->mode;
if (genwqe_is_privileged(cd))
return mode;
for (j = 0; genwqe_normal_attributes[j] != NULL; j++)
if (genwqe_normal_attributes[j] == attr)
return mode;
return 0;
}
