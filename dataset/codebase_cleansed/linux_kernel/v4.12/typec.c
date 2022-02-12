static struct usb_pd_identity *get_pd_identity(struct device *dev)
{
if (is_typec_partner(dev)) {
struct typec_partner *partner = to_typec_partner(dev);
return partner->identity;
} else if (is_typec_cable(dev)) {
struct typec_cable *cable = to_typec_cable(dev);
return cable->identity;
}
return NULL;
}
static ssize_t id_header_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct usb_pd_identity *id = get_pd_identity(dev);
return sprintf(buf, "0x%08x\n", id->id_header);
}
static ssize_t cert_stat_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct usb_pd_identity *id = get_pd_identity(dev);
return sprintf(buf, "0x%08x\n", id->cert_stat);
}
static ssize_t product_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct usb_pd_identity *id = get_pd_identity(dev);
return sprintf(buf, "0x%08x\n", id->product);
}
static void typec_report_identity(struct device *dev)
{
sysfs_notify(&dev->kobj, "identity", "id_header");
sysfs_notify(&dev->kobj, "identity", "cert_stat");
sysfs_notify(&dev->kobj, "identity", "product");
}
void typec_altmode_update_active(struct typec_altmode *alt, int mode,
bool active)
{
struct typec_mode *m = &alt->modes[mode];
char dir[6];
if (m->active == active)
return;
m->active = active;
snprintf(dir, sizeof(dir), "mode%d", mode);
sysfs_notify(&alt->dev.kobj, dir, "active");
kobject_uevent(&alt->dev.kobj, KOBJ_CHANGE);
}
struct typec_port *typec_altmode2port(struct typec_altmode *alt)
{
if (is_typec_plug(alt->dev.parent))
return to_typec_port(alt->dev.parent->parent->parent);
if (is_typec_partner(alt->dev.parent))
return to_typec_port(alt->dev.parent->parent);
if (is_typec_port(alt->dev.parent))
return to_typec_port(alt->dev.parent);
return NULL;
}
static ssize_t
typec_altmode_vdo_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct typec_mode *mode = container_of(attr, struct typec_mode,
vdo_attr);
return sprintf(buf, "0x%08x\n", mode->vdo);
}
static ssize_t
typec_altmode_desc_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct typec_mode *mode = container_of(attr, struct typec_mode,
desc_attr);
return sprintf(buf, "%s\n", mode->desc ? mode->desc : "");
}
static ssize_t
typec_altmode_active_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct typec_mode *mode = container_of(attr, struct typec_mode,
active_attr);
return sprintf(buf, "%s\n", mode->active ? "yes" : "no");
}
static ssize_t
typec_altmode_active_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t size)
{
struct typec_mode *mode = container_of(attr, struct typec_mode,
active_attr);
struct typec_port *port = typec_altmode2port(mode->alt_mode);
bool activate;
int ret;
if (!port->cap->activate_mode)
return -EOPNOTSUPP;
ret = kstrtobool(buf, &activate);
if (ret)
return ret;
ret = port->cap->activate_mode(port->cap, mode->index, activate);
if (ret)
return ret;
return size;
}
static ssize_t
typec_altmode_roles_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct typec_mode *mode = container_of(attr, struct typec_mode,
roles_attr);
ssize_t ret;
switch (mode->roles) {
case TYPEC_PORT_DFP:
ret = sprintf(buf, "source\n");
break;
case TYPEC_PORT_UFP:
ret = sprintf(buf, "sink\n");
break;
case TYPEC_PORT_DRP:
default:
ret = sprintf(buf, "source sink\n");
break;
}
return ret;
}
static void typec_init_modes(struct typec_altmode *alt,
struct typec_mode_desc *desc, bool is_port)
{
int i;
for (i = 0; i < alt->n_modes; i++, desc++) {
struct typec_mode *mode = &alt->modes[i];
mode->desc = kstrdup(desc->desc, GFP_KERNEL);
if (desc->desc && !mode->desc)
dev_err(&alt->dev, "failed to copy mode%d desc\n", i);
mode->alt_mode = alt;
mode->vdo = desc->vdo;
mode->roles = desc->roles;
mode->index = desc->index;
sprintf(mode->group_name, "mode%d", desc->index);
sysfs_attr_init(&mode->vdo_attr.attr);
mode->vdo_attr.attr.name = "vdo";
mode->vdo_attr.attr.mode = 0444;
mode->vdo_attr.show = typec_altmode_vdo_show;
sysfs_attr_init(&mode->desc_attr.attr);
mode->desc_attr.attr.name = "description";
mode->desc_attr.attr.mode = 0444;
mode->desc_attr.show = typec_altmode_desc_show;
sysfs_attr_init(&mode->active_attr.attr);
mode->active_attr.attr.name = "active";
mode->active_attr.attr.mode = 0644;
mode->active_attr.show = typec_altmode_active_show;
mode->active_attr.store = typec_altmode_active_store;
mode->attrs[0] = &mode->vdo_attr.attr;
mode->attrs[1] = &mode->desc_attr.attr;
mode->attrs[2] = &mode->active_attr.attr;
if (is_port) {
sysfs_attr_init(&mode->roles_attr.attr);
mode->roles_attr.attr.name = "supported_roles";
mode->roles_attr.attr.mode = 0444;
mode->roles_attr.show = typec_altmode_roles_show;
mode->attrs[3] = &mode->roles_attr.attr;
}
mode->group.attrs = mode->attrs;
mode->group.name = mode->group_name;
alt->mode_groups[i] = &mode->group;
}
}
static ssize_t svid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct typec_altmode *alt = to_altmode(dev);
return sprintf(buf, "%04x\n", alt->svid);
}
static void typec_altmode_release(struct device *dev)
{
struct typec_altmode *alt = to_altmode(dev);
int i;
for (i = 0; i < alt->n_modes; i++)
kfree(alt->modes[i].desc);
kfree(alt);
}
static struct typec_altmode *
typec_register_altmode(struct device *parent, struct typec_altmode_desc *desc)
{
struct typec_altmode *alt;
int ret;
alt = kzalloc(sizeof(*alt), GFP_KERNEL);
if (!alt)
return NULL;
alt->svid = desc->svid;
alt->n_modes = desc->n_modes;
typec_init_modes(alt, desc->modes, is_typec_port(parent));
alt->dev.parent = parent;
alt->dev.groups = alt->mode_groups;
alt->dev.type = &typec_altmode_dev_type;
dev_set_name(&alt->dev, "svid-%04x", alt->svid);
ret = device_register(&alt->dev);
if (ret) {
dev_err(parent, "failed to register alternate mode (%d)\n",
ret);
put_device(&alt->dev);
return NULL;
}
return alt;
}
void typec_unregister_altmode(struct typec_altmode *alt)
{
if (alt)
device_unregister(&alt->dev);
}
static ssize_t accessory_mode_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct typec_partner *p = to_typec_partner(dev);
return sprintf(buf, "%s\n", typec_accessory_modes[p->accessory]);
}
static ssize_t supports_usb_power_delivery_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct typec_partner *p = to_typec_partner(dev);
return sprintf(buf, "%s\n", p->usb_pd ? "yes" : "no");
}
static void typec_partner_release(struct device *dev)
{
struct typec_partner *partner = to_typec_partner(dev);
kfree(partner);
}
int typec_partner_set_identity(struct typec_partner *partner)
{
if (!partner->identity)
return -EINVAL;
typec_report_identity(&partner->dev);
return 0;
}
struct typec_altmode *
typec_partner_register_altmode(struct typec_partner *partner,
struct typec_altmode_desc *desc)
{
return typec_register_altmode(&partner->dev, desc);
}
struct typec_partner *typec_register_partner(struct typec_port *port,
struct typec_partner_desc *desc)
{
struct typec_partner *partner;
int ret;
partner = kzalloc(sizeof(*partner), GFP_KERNEL);
if (!partner)
return NULL;
partner->usb_pd = desc->usb_pd;
partner->accessory = desc->accessory;
if (desc->identity) {
partner->dev.groups = usb_pd_id_groups;
partner->identity = desc->identity;
}
partner->dev.class = typec_class;
partner->dev.parent = &port->dev;
partner->dev.type = &typec_partner_dev_type;
dev_set_name(&partner->dev, "%s-partner", dev_name(&port->dev));
ret = device_register(&partner->dev);
if (ret) {
dev_err(&port->dev, "failed to register partner (%d)\n", ret);
put_device(&partner->dev);
return NULL;
}
return partner;
}
void typec_unregister_partner(struct typec_partner *partner)
{
if (partner)
device_unregister(&partner->dev);
}
static void typec_plug_release(struct device *dev)
{
struct typec_plug *plug = to_typec_plug(dev);
kfree(plug);
}
struct typec_altmode *
typec_plug_register_altmode(struct typec_plug *plug,
struct typec_altmode_desc *desc)
{
return typec_register_altmode(&plug->dev, desc);
}
struct typec_plug *typec_register_plug(struct typec_cable *cable,
struct typec_plug_desc *desc)
{
struct typec_plug *plug;
char name[8];
int ret;
plug = kzalloc(sizeof(*plug), GFP_KERNEL);
if (!plug)
return NULL;
sprintf(name, "plug%d", desc->index);
plug->index = desc->index;
plug->dev.class = typec_class;
plug->dev.parent = &cable->dev;
plug->dev.type = &typec_plug_dev_type;
dev_set_name(&plug->dev, "%s-%s", dev_name(cable->dev.parent), name);
ret = device_register(&plug->dev);
if (ret) {
dev_err(&cable->dev, "failed to register plug (%d)\n", ret);
put_device(&plug->dev);
return NULL;
}
return plug;
}
void typec_unregister_plug(struct typec_plug *plug)
{
if (plug)
device_unregister(&plug->dev);
}
static ssize_t
type_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct typec_cable *cable = to_typec_cable(dev);
return sprintf(buf, "%s\n", cable->active ? "active" : "passive");
}
static ssize_t plug_type_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct typec_cable *cable = to_typec_cable(dev);
return sprintf(buf, "%s\n", typec_plug_types[cable->type]);
}
static void typec_cable_release(struct device *dev)
{
struct typec_cable *cable = to_typec_cable(dev);
kfree(cable);
}
int typec_cable_set_identity(struct typec_cable *cable)
{
if (!cable->identity)
return -EINVAL;
typec_report_identity(&cable->dev);
return 0;
}
struct typec_cable *typec_register_cable(struct typec_port *port,
struct typec_cable_desc *desc)
{
struct typec_cable *cable;
int ret;
cable = kzalloc(sizeof(*cable), GFP_KERNEL);
if (!cable)
return NULL;
cable->type = desc->type;
cable->active = desc->active;
if (desc->identity) {
cable->dev.groups = usb_pd_id_groups;
cable->identity = desc->identity;
}
cable->dev.class = typec_class;
cable->dev.parent = &port->dev;
cable->dev.type = &typec_cable_dev_type;
dev_set_name(&cable->dev, "%s-cable", dev_name(&port->dev));
ret = device_register(&cable->dev);
if (ret) {
dev_err(&port->dev, "failed to register cable (%d)\n", ret);
put_device(&cable->dev);
return NULL;
}
return cable;
}
void typec_unregister_cable(struct typec_cable *cable)
{
if (cable)
device_unregister(&cable->dev);
}
static ssize_t
preferred_role_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t size)
{
struct typec_port *port = to_typec_port(dev);
int role;
int ret;
if (port->cap->type != TYPEC_PORT_DRP) {
dev_dbg(dev, "Preferred role only supported with DRP ports\n");
return -EOPNOTSUPP;
}
if (!port->cap->try_role) {
dev_dbg(dev, "Setting preferred role not supported\n");
return -EOPNOTSUPP;
}
role = sysfs_match_string(typec_roles, buf);
if (role < 0) {
if (sysfs_streq(buf, "none"))
role = TYPEC_NO_PREFERRED_ROLE;
else
return -EINVAL;
}
ret = port->cap->try_role(port->cap, role);
if (ret)
return ret;
port->prefer_role = role;
return size;
}
static ssize_t
preferred_role_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct typec_port *port = to_typec_port(dev);
if (port->cap->type != TYPEC_PORT_DRP)
return 0;
if (port->prefer_role < 0)
return 0;
return sprintf(buf, "%s\n", typec_roles[port->prefer_role]);
}
static ssize_t data_role_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
struct typec_port *port = to_typec_port(dev);
int ret;
if (port->cap->type != TYPEC_PORT_DRP) {
dev_dbg(dev, "data role swap only supported with DRP ports\n");
return -EOPNOTSUPP;
}
if (!port->cap->dr_set) {
dev_dbg(dev, "data role swapping not supported\n");
return -EOPNOTSUPP;
}
ret = sysfs_match_string(typec_data_roles, buf);
if (ret < 0)
return ret;
ret = port->cap->dr_set(port->cap, ret);
if (ret)
return ret;
return size;
}
static ssize_t data_role_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct typec_port *port = to_typec_port(dev);
if (port->cap->type == TYPEC_PORT_DRP)
return sprintf(buf, "%s\n", port->data_role == TYPEC_HOST ?
"[host] device" : "host [device]");
return sprintf(buf, "[%s]\n", typec_data_roles[port->data_role]);
}
static ssize_t power_role_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
struct typec_port *port = to_typec_port(dev);
int ret = size;
if (!port->cap->pd_revision) {
dev_dbg(dev, "USB Power Delivery not supported\n");
return -EOPNOTSUPP;
}
if (!port->cap->pr_set) {
dev_dbg(dev, "power role swapping not supported\n");
return -EOPNOTSUPP;
}
if (port->pwr_opmode != TYPEC_PWR_MODE_PD) {
dev_dbg(dev, "partner unable to swap power role\n");
return -EIO;
}
ret = sysfs_match_string(typec_roles, buf);
if (ret < 0)
return ret;
ret = port->cap->pr_set(port->cap, ret);
if (ret)
return ret;
return size;
}
static ssize_t power_role_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct typec_port *port = to_typec_port(dev);
if (port->cap->type == TYPEC_PORT_DRP)
return sprintf(buf, "%s\n", port->pwr_role == TYPEC_SOURCE ?
"[source] sink" : "source [sink]");
return sprintf(buf, "[%s]\n", typec_roles[port->pwr_role]);
}
static ssize_t power_operation_mode_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct typec_port *port = to_typec_port(dev);
return sprintf(buf, "%s\n", typec_pwr_opmodes[port->pwr_opmode]);
}
static ssize_t vconn_source_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
struct typec_port *port = to_typec_port(dev);
bool source;
int ret;
if (!port->cap->pd_revision) {
dev_dbg(dev, "VCONN swap depends on USB Power Delivery\n");
return -EOPNOTSUPP;
}
if (!port->cap->vconn_set) {
dev_dbg(dev, "VCONN swapping not supported\n");
return -EOPNOTSUPP;
}
ret = kstrtobool(buf, &source);
if (ret)
return ret;
ret = port->cap->vconn_set(port->cap, (enum typec_role)source);
if (ret)
return ret;
return size;
}
static ssize_t vconn_source_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct typec_port *port = to_typec_port(dev);
return sprintf(buf, "%s\n",
port->vconn_role == TYPEC_SOURCE ? "yes" : "no");
}
static ssize_t supported_accessory_modes_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct typec_port *port = to_typec_port(dev);
ssize_t ret = 0;
int i;
for (i = 0; i < ARRAY_SIZE(port->cap->accessory); i++) {
if (port->cap->accessory[i])
ret += sprintf(buf + ret, "%s ",
typec_accessory_modes[port->cap->accessory[i]]);
}
if (!ret)
return sprintf(buf, "none\n");
buf[ret - 1] = '\n';
return ret;
}
static ssize_t usb_typec_revision_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct typec_port *port = to_typec_port(dev);
u16 rev = port->cap->revision;
return sprintf(buf, "%d.%d\n", (rev >> 8) & 0xff, (rev >> 4) & 0xf);
}
static ssize_t usb_power_delivery_revision_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct typec_port *p = to_typec_port(dev);
return sprintf(buf, "%d\n", (p->cap->pd_revision >> 8) & 0xff);
}
static int typec_uevent(struct device *dev, struct kobj_uevent_env *env)
{
int ret;
ret = add_uevent_var(env, "TYPEC_PORT=%s", dev_name(dev));
if (ret)
dev_err(dev, "failed to add uevent TYPEC_PORT\n");
return ret;
}
static void typec_release(struct device *dev)
{
struct typec_port *port = to_typec_port(dev);
ida_simple_remove(&typec_index_ida, port->id);
kfree(port);
}
void typec_set_data_role(struct typec_port *port, enum typec_data_role role)
{
if (port->data_role == role)
return;
port->data_role = role;
sysfs_notify(&port->dev.kobj, NULL, "data_role");
kobject_uevent(&port->dev.kobj, KOBJ_CHANGE);
}
void typec_set_pwr_role(struct typec_port *port, enum typec_role role)
{
if (port->pwr_role == role)
return;
port->pwr_role = role;
sysfs_notify(&port->dev.kobj, NULL, "power_role");
kobject_uevent(&port->dev.kobj, KOBJ_CHANGE);
}
void typec_set_vconn_role(struct typec_port *port, enum typec_role role)
{
if (port->vconn_role == role)
return;
port->vconn_role = role;
sysfs_notify(&port->dev.kobj, NULL, "vconn_source");
kobject_uevent(&port->dev.kobj, KOBJ_CHANGE);
}
void typec_set_pwr_opmode(struct typec_port *port,
enum typec_pwr_opmode opmode)
{
if (port->pwr_opmode == opmode)
return;
port->pwr_opmode = opmode;
sysfs_notify(&port->dev.kobj, NULL, "power_operation_mode");
kobject_uevent(&port->dev.kobj, KOBJ_CHANGE);
}
struct typec_altmode *
typec_port_register_altmode(struct typec_port *port,
struct typec_altmode_desc *desc)
{
return typec_register_altmode(&port->dev, desc);
}
struct typec_port *typec_register_port(struct device *parent,
const struct typec_capability *cap)
{
struct typec_port *port;
int role;
int ret;
int id;
port = kzalloc(sizeof(*port), GFP_KERNEL);
if (!port)
return NULL;
id = ida_simple_get(&typec_index_ida, 0, 0, GFP_KERNEL);
if (id < 0) {
kfree(port);
return NULL;
}
if (cap->type == TYPEC_PORT_DFP)
role = TYPEC_SOURCE;
else if (cap->type == TYPEC_PORT_UFP)
role = TYPEC_SINK;
else
role = cap->prefer_role;
if (role == TYPEC_SOURCE) {
port->data_role = TYPEC_HOST;
port->pwr_role = TYPEC_SOURCE;
port->vconn_role = TYPEC_SOURCE;
} else {
port->data_role = TYPEC_DEVICE;
port->pwr_role = TYPEC_SINK;
port->vconn_role = TYPEC_SINK;
}
port->id = id;
port->cap = cap;
port->prefer_role = cap->prefer_role;
port->dev.class = typec_class;
port->dev.parent = parent;
port->dev.fwnode = cap->fwnode;
port->dev.type = &typec_port_dev_type;
dev_set_name(&port->dev, "port%d", id);
ret = device_register(&port->dev);
if (ret) {
dev_err(parent, "failed to register port (%d)\n", ret);
put_device(&port->dev);
return NULL;
}
return port;
}
void typec_unregister_port(struct typec_port *port)
{
if (port)
device_unregister(&port->dev);
}
static int __init typec_init(void)
{
typec_class = class_create(THIS_MODULE, "typec");
return PTR_ERR_OR_ZERO(typec_class);
}
static void __exit typec_exit(void)
{
class_destroy(typec_class);
ida_destroy(&typec_index_ida);
}
