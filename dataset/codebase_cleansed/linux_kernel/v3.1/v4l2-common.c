int v4l2_ctrl_check(struct v4l2_ext_control *ctrl, struct v4l2_queryctrl *qctrl,
const char * const *menu_items)
{
if (qctrl->flags & V4L2_CTRL_FLAG_DISABLED)
return -EINVAL;
if (qctrl->flags & V4L2_CTRL_FLAG_GRABBED)
return -EBUSY;
if (qctrl->type == V4L2_CTRL_TYPE_STRING)
return 0;
if (qctrl->type == V4L2_CTRL_TYPE_BUTTON ||
qctrl->type == V4L2_CTRL_TYPE_INTEGER64 ||
qctrl->type == V4L2_CTRL_TYPE_CTRL_CLASS)
return 0;
if (ctrl->value < qctrl->minimum || ctrl->value > qctrl->maximum)
return -ERANGE;
if (qctrl->type == V4L2_CTRL_TYPE_MENU && menu_items != NULL) {
if (menu_items[ctrl->value] == NULL ||
menu_items[ctrl->value][0] == '\0')
return -EINVAL;
}
if (qctrl->type == V4L2_CTRL_TYPE_BITMASK &&
(ctrl->value & ~qctrl->maximum))
return -ERANGE;
return 0;
}
int v4l2_ctrl_query_fill(struct v4l2_queryctrl *qctrl, s32 min, s32 max, s32 step, s32 def)
{
const char *name;
v4l2_ctrl_fill(qctrl->id, &name, &qctrl->type,
&min, &max, &step, &def, &qctrl->flags);
if (name == NULL)
return -EINVAL;
qctrl->minimum = min;
qctrl->maximum = max;
qctrl->step = step;
qctrl->default_value = def;
qctrl->reserved[0] = qctrl->reserved[1] = 0;
strlcpy(qctrl->name, name, sizeof(qctrl->name));
return 0;
}
int v4l2_ctrl_query_menu(struct v4l2_querymenu *qmenu, struct v4l2_queryctrl *qctrl,
const char * const *menu_items)
{
int i;
qmenu->reserved = 0;
if (menu_items == NULL)
menu_items = v4l2_ctrl_get_menu(qmenu->id);
if (menu_items == NULL ||
(qctrl && (qmenu->index < qctrl->minimum || qmenu->index > qctrl->maximum)))
return -EINVAL;
for (i = 0; i < qmenu->index && menu_items[i]; i++) ;
if (menu_items[i] == NULL || menu_items[i][0] == '\0')
return -EINVAL;
strlcpy(qmenu->name, menu_items[qmenu->index], sizeof(qmenu->name));
return 0;
}
int v4l2_ctrl_query_menu_valid_items(struct v4l2_querymenu *qmenu, const u32 *ids)
{
const char * const *menu_items = v4l2_ctrl_get_menu(qmenu->id);
qmenu->reserved = 0;
if (menu_items == NULL || ids == NULL)
return -EINVAL;
while (*ids != V4L2_CTRL_MENU_IDS_END) {
if (*ids++ == qmenu->index) {
strlcpy(qmenu->name, menu_items[qmenu->index],
sizeof(qmenu->name));
return 0;
}
}
return -EINVAL;
}
u32 v4l2_ctrl_next(const u32 * const * ctrl_classes, u32 id)
{
u32 ctrl_class = V4L2_CTRL_ID2CLASS(id);
const u32 *pctrl;
if (ctrl_classes == NULL)
return 0;
if ((id & V4L2_CTRL_FLAG_NEXT_CTRL) == 0) {
while (*ctrl_classes && V4L2_CTRL_ID2CLASS(**ctrl_classes) != ctrl_class)
ctrl_classes++;
if (*ctrl_classes == NULL)
return 0;
pctrl = *ctrl_classes;
while (*pctrl && *pctrl != id) pctrl++;
return *pctrl ? id : 0;
}
id &= V4L2_CTRL_ID_MASK;
id++;
while (*ctrl_classes && V4L2_CTRL_ID2CLASS(**ctrl_classes) < ctrl_class)
ctrl_classes++;
if (*ctrl_classes == NULL)
return 0;
pctrl = *ctrl_classes;
while (*pctrl && *pctrl < id) pctrl++;
if (*pctrl)
return *pctrl;
ctrl_classes++;
if (*ctrl_classes == NULL)
return 0;
return **ctrl_classes;
}
int v4l2_chip_match_host(const struct v4l2_dbg_match *match)
{
switch (match->type) {
case V4L2_CHIP_MATCH_HOST:
return match->addr == 0;
default:
return 0;
}
}
int v4l2_chip_match_i2c_client(struct i2c_client *c, const struct v4l2_dbg_match *match)
{
int len;
if (c == NULL || match == NULL)
return 0;
switch (match->type) {
case V4L2_CHIP_MATCH_I2C_DRIVER:
if (c->driver == NULL || c->driver->driver.name == NULL)
return 0;
len = strlen(c->driver->driver.name);
if (len && c->driver->driver.name[len - 1] == '\'')
len--;
return len && !strncmp(c->driver->driver.name, match->name, len);
case V4L2_CHIP_MATCH_I2C_ADDR:
return c->addr == match->addr;
default:
return 0;
}
}
int v4l2_chip_ident_i2c_client(struct i2c_client *c, struct v4l2_dbg_chip_ident *chip,
u32 ident, u32 revision)
{
if (!v4l2_chip_match_i2c_client(c, &chip->match))
return 0;
if (chip->ident == V4L2_IDENT_NONE) {
chip->ident = ident;
chip->revision = revision;
}
else {
chip->ident = V4L2_IDENT_AMBIGUOUS;
chip->revision = 0;
}
return 0;
}
void v4l2_i2c_subdev_init(struct v4l2_subdev *sd, struct i2c_client *client,
const struct v4l2_subdev_ops *ops)
{
v4l2_subdev_init(sd, ops);
sd->flags |= V4L2_SUBDEV_FL_IS_I2C;
sd->owner = client->driver->driver.owner;
v4l2_set_subdevdata(sd, client);
i2c_set_clientdata(client, sd);
snprintf(sd->name, sizeof(sd->name), "%s %d-%04x",
client->driver->driver.name, i2c_adapter_id(client->adapter),
client->addr);
}
struct v4l2_subdev *v4l2_i2c_new_subdev_board(struct v4l2_device *v4l2_dev,
struct i2c_adapter *adapter, struct i2c_board_info *info,
const unsigned short *probe_addrs)
{
struct v4l2_subdev *sd = NULL;
struct i2c_client *client;
BUG_ON(!v4l2_dev);
request_module(I2C_MODULE_PREFIX "%s", info->type);
if (info->addr == 0 && probe_addrs)
client = i2c_new_probed_device(adapter, info, probe_addrs,
NULL);
else
client = i2c_new_device(adapter, info);
if (client == NULL || client->driver == NULL)
goto error;
if (!try_module_get(client->driver->driver.owner))
goto error;
sd = i2c_get_clientdata(client);
if (v4l2_device_register_subdev(v4l2_dev, sd))
sd = NULL;
module_put(client->driver->driver.owner);
error:
if (client && sd == NULL)
i2c_unregister_device(client);
return sd;
}
struct v4l2_subdev *v4l2_i2c_new_subdev(struct v4l2_device *v4l2_dev,
struct i2c_adapter *adapter, const char *client_type,
u8 addr, const unsigned short *probe_addrs)
{
struct i2c_board_info info;
memset(&info, 0, sizeof(info));
strlcpy(info.type, client_type, sizeof(info.type));
info.addr = addr;
return v4l2_i2c_new_subdev_board(v4l2_dev, adapter, &info, probe_addrs);
}
unsigned short v4l2_i2c_subdev_addr(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return client ? client->addr : I2C_CLIENT_END;
}
const unsigned short *v4l2_i2c_tuner_addrs(enum v4l2_i2c_tuner_type type)
{
static const unsigned short radio_addrs[] = {
#if defined(CONFIG_MEDIA_TUNER_TEA5761) || defined(CONFIG_MEDIA_TUNER_TEA5761_MODULE)
0x10,
#endif
0x60,
I2C_CLIENT_END
};
static const unsigned short demod_addrs[] = {
0x42, 0x43, 0x4a, 0x4b,
I2C_CLIENT_END
};
static const unsigned short tv_addrs[] = {
0x42, 0x43, 0x4a, 0x4b,
0x60, 0x61, 0x62, 0x63, 0x64,
I2C_CLIENT_END
};
switch (type) {
case ADDRS_RADIO:
return radio_addrs;
case ADDRS_DEMOD:
return demod_addrs;
case ADDRS_TV:
return tv_addrs;
case ADDRS_TV_WITH_DEMOD:
return tv_addrs + 4;
}
return NULL;
}
void v4l2_spi_subdev_init(struct v4l2_subdev *sd, struct spi_device *spi,
const struct v4l2_subdev_ops *ops)
{
v4l2_subdev_init(sd, ops);
sd->flags |= V4L2_SUBDEV_FL_IS_SPI;
sd->owner = spi->dev.driver->owner;
v4l2_set_subdevdata(sd, spi);
spi_set_drvdata(spi, sd);
strlcpy(sd->name, spi->dev.driver->name, sizeof(sd->name));
}
struct v4l2_subdev *v4l2_spi_new_subdev(struct v4l2_device *v4l2_dev,
struct spi_master *master, struct spi_board_info *info)
{
struct v4l2_subdev *sd = NULL;
struct spi_device *spi = NULL;
BUG_ON(!v4l2_dev);
if (info->modalias)
request_module(info->modalias);
spi = spi_new_device(master, info);
if (spi == NULL || spi->dev.driver == NULL)
goto error;
if (!try_module_get(spi->dev.driver->owner))
goto error;
sd = spi_get_drvdata(spi);
if (v4l2_device_register_subdev(v4l2_dev, sd))
sd = NULL;
module_put(spi->dev.driver->owner);
error:
if (spi && sd == NULL)
spi_unregister_device(spi);
return sd;
}
static unsigned int clamp_align(unsigned int x, unsigned int min,
unsigned int max, unsigned int align)
{
unsigned int mask = ~((1 << align) - 1);
if (align)
x = (x + (1 << (align - 1))) & mask;
if (x < min)
x = (min + ~mask) & mask;
else if (x > max)
x = max & mask;
return x;
}
void v4l_bound_align_image(u32 *w, unsigned int wmin, unsigned int wmax,
unsigned int walign,
u32 *h, unsigned int hmin, unsigned int hmax,
unsigned int halign, unsigned int salign)
{
*w = clamp_align(*w, wmin, wmax, walign);
*h = clamp_align(*h, hmin, hmax, halign);
if (!salign)
return;
walign = __ffs(*w);
halign = __ffs(*h);
if (walign + halign < salign) {
unsigned int wmaxa = __fls(wmax ^ (wmin - 1));
unsigned int hmaxa = __fls(hmax ^ (hmin - 1));
do {
if (halign >= hmaxa ||
(walign <= halign && walign < wmaxa)) {
*w = clamp_align(*w, wmin, wmax, walign + 1);
walign = __ffs(*w);
} else {
*h = clamp_align(*h, hmin, hmax, halign + 1);
halign = __ffs(*h);
}
} while (halign + walign < salign);
}
}
int v4l_fill_dv_preset_info(u32 preset, struct v4l2_dv_enum_preset *info)
{
static const struct v4l2_dv_preset_info {
u16 width;
u16 height;
const char *name;
} dv_presets[] = {
{ 0, 0, "Invalid" },
{ 720, 480, "480p@59.94" },
{ 720, 576, "576p@50" },
{ 1280, 720, "720p@24" },
{ 1280, 720, "720p@25" },
{ 1280, 720, "720p@30" },
{ 1280, 720, "720p@50" },
{ 1280, 720, "720p@59.94" },
{ 1280, 720, "720p@60" },
{ 1920, 1080, "1080i@29.97" },
{ 1920, 1080, "1080i@30" },
{ 1920, 1080, "1080i@25" },
{ 1920, 1080, "1080i@50" },
{ 1920, 1080, "1080i@60" },
{ 1920, 1080, "1080p@24" },
{ 1920, 1080, "1080p@25" },
{ 1920, 1080, "1080p@30" },
{ 1920, 1080, "1080p@50" },
{ 1920, 1080, "1080p@60" },
};
if (info == NULL || preset >= ARRAY_SIZE(dv_presets))
return -EINVAL;
info->preset = preset;
info->width = dv_presets[preset].width;
info->height = dv_presets[preset].height;
strlcpy(info->name, dv_presets[preset].name, sizeof(info->name));
return 0;
}
const struct v4l2_frmsize_discrete *v4l2_find_nearest_format(
const struct v4l2_discrete_probe *probe,
s32 width, s32 height)
{
int i;
u32 error, min_error = UINT_MAX;
const struct v4l2_frmsize_discrete *size, *best = NULL;
if (!probe)
return best;
for (i = 0, size = probe->sizes; i < probe->num_sizes; i++, size++) {
error = abs(size->width - width) + abs(size->height - height);
if (error < min_error) {
min_error = error;
best = size;
}
if (!error)
break;
}
return best;
}
