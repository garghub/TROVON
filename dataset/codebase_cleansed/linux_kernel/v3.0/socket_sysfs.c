static ssize_t pccard_show_type(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct pcmcia_socket *s = to_socket(dev);
if (!(s->state & SOCKET_PRESENT))
return -ENODEV;
if (s->state & SOCKET_CARDBUS)
return sprintf(buf, "32-bit\n");
return sprintf(buf, "16-bit\n");
}
static ssize_t pccard_show_voltage(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct pcmcia_socket *s = to_socket(dev);
if (!(s->state & SOCKET_PRESENT))
return -ENODEV;
if (s->socket.Vcc)
return sprintf(buf, "%d.%dV\n", s->socket.Vcc / 10,
s->socket.Vcc % 10);
return sprintf(buf, "X.XV\n");
}
static ssize_t pccard_show_vpp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct pcmcia_socket *s = to_socket(dev);
if (!(s->state & SOCKET_PRESENT))
return -ENODEV;
return sprintf(buf, "%d.%dV\n", s->socket.Vpp / 10, s->socket.Vpp % 10);
}
static ssize_t pccard_show_vcc(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct pcmcia_socket *s = to_socket(dev);
if (!(s->state & SOCKET_PRESENT))
return -ENODEV;
return sprintf(buf, "%d.%dV\n", s->socket.Vcc / 10, s->socket.Vcc % 10);
}
static ssize_t pccard_store_insert(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct pcmcia_socket *s = to_socket(dev);
if (!count)
return -EINVAL;
pcmcia_parse_uevents(s, PCMCIA_UEVENT_INSERT);
return count;
}
static ssize_t pccard_show_card_pm_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct pcmcia_socket *s = to_socket(dev);
return sprintf(buf, "%s\n", s->state & SOCKET_SUSPEND ? "off" : "on");
}
static ssize_t pccard_store_card_pm_state(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct pcmcia_socket *s = to_socket(dev);
ssize_t ret = count;
if (!count)
return -EINVAL;
if (!strncmp(buf, "off", 3))
pcmcia_parse_uevents(s, PCMCIA_UEVENT_SUSPEND);
else {
if (!strncmp(buf, "on", 2))
pcmcia_parse_uevents(s, PCMCIA_UEVENT_RESUME);
else
ret = -EINVAL;
}
return ret;
}
static ssize_t pccard_store_eject(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct pcmcia_socket *s = to_socket(dev);
if (!count)
return -EINVAL;
pcmcia_parse_uevents(s, PCMCIA_UEVENT_EJECT);
return count;
}
static ssize_t pccard_show_irq_mask(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct pcmcia_socket *s = to_socket(dev);
return sprintf(buf, "0x%04x\n", s->irq_mask);
}
static ssize_t pccard_store_irq_mask(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
ssize_t ret;
struct pcmcia_socket *s = to_socket(dev);
u32 mask;
if (!count)
return -EINVAL;
ret = sscanf(buf, "0x%x\n", &mask);
if (ret == 1) {
mutex_lock(&s->ops_mutex);
s->irq_mask &= mask;
mutex_unlock(&s->ops_mutex);
ret = 0;
}
return ret ? ret : count;
}
static ssize_t pccard_show_resource(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct pcmcia_socket *s = to_socket(dev);
return sprintf(buf, "%s\n", s->resource_setup_done ? "yes" : "no");
}
static ssize_t pccard_store_resource(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct pcmcia_socket *s = to_socket(dev);
if (!count)
return -EINVAL;
mutex_lock(&s->ops_mutex);
if (!s->resource_setup_done)
s->resource_setup_done = 1;
mutex_unlock(&s->ops_mutex);
pcmcia_parse_uevents(s, PCMCIA_UEVENT_REQUERY);
return count;
}
int pccard_sysfs_add_socket(struct device *dev)
{
return sysfs_create_group(&dev->kobj, &socket_attrs);
}
void pccard_sysfs_remove_socket(struct device *dev)
{
sysfs_remove_group(&dev->kobj, &socket_attrs);
}
