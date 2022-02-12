int pmbus_set_page(struct i2c_client *client, u8 page)
{
struct pmbus_data *data = i2c_get_clientdata(client);
int rv = 0;
int newpage;
if (page != data->currpage) {
rv = i2c_smbus_write_byte_data(client, PMBUS_PAGE, page);
newpage = i2c_smbus_read_byte_data(client, PMBUS_PAGE);
if (newpage != page)
rv = -EIO;
else
data->currpage = page;
}
return rv;
}
int pmbus_write_byte(struct i2c_client *client, int page, u8 value)
{
int rv;
if (page >= 0) {
rv = pmbus_set_page(client, page);
if (rv < 0)
return rv;
}
return i2c_smbus_write_byte(client, value);
}
static int _pmbus_write_byte(struct i2c_client *client, int page, u8 value)
{
struct pmbus_data *data = i2c_get_clientdata(client);
const struct pmbus_driver_info *info = data->info;
int status;
if (info->write_byte) {
status = info->write_byte(client, page, value);
if (status != -ENODATA)
return status;
}
return pmbus_write_byte(client, page, value);
}
int pmbus_write_word_data(struct i2c_client *client, u8 page, u8 reg, u16 word)
{
int rv;
rv = pmbus_set_page(client, page);
if (rv < 0)
return rv;
return i2c_smbus_write_word_data(client, reg, word);
}
static int _pmbus_write_word_data(struct i2c_client *client, int page, int reg,
u16 word)
{
struct pmbus_data *data = i2c_get_clientdata(client);
const struct pmbus_driver_info *info = data->info;
int status;
if (info->write_word_data) {
status = info->write_word_data(client, page, reg, word);
if (status != -ENODATA)
return status;
}
if (reg >= PMBUS_VIRT_BASE)
return -ENXIO;
return pmbus_write_word_data(client, page, reg, word);
}
int pmbus_read_word_data(struct i2c_client *client, u8 page, u8 reg)
{
int rv;
rv = pmbus_set_page(client, page);
if (rv < 0)
return rv;
return i2c_smbus_read_word_data(client, reg);
}
static int _pmbus_read_word_data(struct i2c_client *client, int page, int reg)
{
struct pmbus_data *data = i2c_get_clientdata(client);
const struct pmbus_driver_info *info = data->info;
int status;
if (info->read_word_data) {
status = info->read_word_data(client, page, reg);
if (status != -ENODATA)
return status;
}
if (reg >= PMBUS_VIRT_BASE)
return -ENXIO;
return pmbus_read_word_data(client, page, reg);
}
int pmbus_read_byte_data(struct i2c_client *client, int page, u8 reg)
{
int rv;
if (page >= 0) {
rv = pmbus_set_page(client, page);
if (rv < 0)
return rv;
}
return i2c_smbus_read_byte_data(client, reg);
}
static int _pmbus_read_byte_data(struct i2c_client *client, int page, int reg)
{
struct pmbus_data *data = i2c_get_clientdata(client);
const struct pmbus_driver_info *info = data->info;
int status;
if (info->read_byte_data) {
status = info->read_byte_data(client, page, reg);
if (status != -ENODATA)
return status;
}
return pmbus_read_byte_data(client, page, reg);
}
static void pmbus_clear_fault_page(struct i2c_client *client, int page)
{
_pmbus_write_byte(client, page, PMBUS_CLEAR_FAULTS);
}
void pmbus_clear_faults(struct i2c_client *client)
{
struct pmbus_data *data = i2c_get_clientdata(client);
int i;
for (i = 0; i < data->info->pages; i++)
pmbus_clear_fault_page(client, i);
}
static int pmbus_check_status_cml(struct i2c_client *client)
{
int status, status2;
status = _pmbus_read_byte_data(client, -1, PMBUS_STATUS_BYTE);
if (status < 0 || (status & PB_STATUS_CML)) {
status2 = _pmbus_read_byte_data(client, -1, PMBUS_STATUS_CML);
if (status2 < 0 || (status2 & PB_CML_FAULT_INVALID_COMMAND))
return -EIO;
}
return 0;
}
bool pmbus_check_byte_register(struct i2c_client *client, int page, int reg)
{
int rv;
struct pmbus_data *data = i2c_get_clientdata(client);
rv = _pmbus_read_byte_data(client, page, reg);
if (rv >= 0 && !(data->flags & PMBUS_SKIP_STATUS_CHECK))
rv = pmbus_check_status_cml(client);
pmbus_clear_fault_page(client, -1);
return rv >= 0;
}
bool pmbus_check_word_register(struct i2c_client *client, int page, int reg)
{
int rv;
struct pmbus_data *data = i2c_get_clientdata(client);
rv = _pmbus_read_word_data(client, page, reg);
if (rv >= 0 && !(data->flags & PMBUS_SKIP_STATUS_CHECK))
rv = pmbus_check_status_cml(client);
pmbus_clear_fault_page(client, -1);
return rv >= 0;
}
const struct pmbus_driver_info *pmbus_get_driver_info(struct i2c_client *client)
{
struct pmbus_data *data = i2c_get_clientdata(client);
return data->info;
}
static struct pmbus_data *pmbus_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct pmbus_data *data = i2c_get_clientdata(client);
const struct pmbus_driver_info *info = data->info;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
int i;
for (i = 0; i < info->pages; i++)
data->status[PB_STATUS_BASE + i]
= _pmbus_read_byte_data(client, i,
PMBUS_STATUS_BYTE);
for (i = 0; i < info->pages; i++) {
if (!(info->func[i] & PMBUS_HAVE_STATUS_VOUT))
continue;
data->status[PB_STATUS_VOUT_BASE + i]
= _pmbus_read_byte_data(client, i, PMBUS_STATUS_VOUT);
}
for (i = 0; i < info->pages; i++) {
if (!(info->func[i] & PMBUS_HAVE_STATUS_IOUT))
continue;
data->status[PB_STATUS_IOUT_BASE + i]
= _pmbus_read_byte_data(client, i, PMBUS_STATUS_IOUT);
}
for (i = 0; i < info->pages; i++) {
if (!(info->func[i] & PMBUS_HAVE_STATUS_TEMP))
continue;
data->status[PB_STATUS_TEMP_BASE + i]
= _pmbus_read_byte_data(client, i,
PMBUS_STATUS_TEMPERATURE);
}
for (i = 0; i < info->pages; i++) {
if (!(info->func[i] & PMBUS_HAVE_STATUS_FAN12))
continue;
data->status[PB_STATUS_FAN_BASE + i]
= _pmbus_read_byte_data(client, i,
PMBUS_STATUS_FAN_12);
}
for (i = 0; i < info->pages; i++) {
if (!(info->func[i] & PMBUS_HAVE_STATUS_FAN34))
continue;
data->status[PB_STATUS_FAN34_BASE + i]
= _pmbus_read_byte_data(client, i,
PMBUS_STATUS_FAN_34);
}
if (info->func[0] & PMBUS_HAVE_STATUS_INPUT)
data->status[PB_STATUS_INPUT_BASE]
= _pmbus_read_byte_data(client, 0,
PMBUS_STATUS_INPUT);
for (i = 0; i < data->num_sensors; i++) {
struct pmbus_sensor *sensor = &data->sensors[i];
if (!data->valid || sensor->update)
sensor->data
= _pmbus_read_word_data(client,
sensor->page,
sensor->reg);
}
pmbus_clear_faults(client);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static long pmbus_reg2data_linear(struct pmbus_data *data,
struct pmbus_sensor *sensor)
{
s16 exponent;
s32 mantissa;
long val;
if (sensor->class == PSC_VOLTAGE_OUT) {
exponent = data->exponent;
mantissa = (u16) sensor->data;
} else {
exponent = ((s16)sensor->data) >> 11;
mantissa = ((s16)((sensor->data & 0x7ff) << 5)) >> 5;
}
val = mantissa;
if (sensor->class != PSC_FAN)
val = val * 1000L;
if (sensor->class == PSC_POWER)
val = val * 1000L;
if (exponent >= 0)
val <<= exponent;
else
val >>= -exponent;
return val;
}
static long pmbus_reg2data_direct(struct pmbus_data *data,
struct pmbus_sensor *sensor)
{
long val = (s16) sensor->data;
long m, b, R;
m = data->info->m[sensor->class];
b = data->info->b[sensor->class];
R = data->info->R[sensor->class];
if (m == 0)
return 0;
R = -R;
if (sensor->class != PSC_FAN) {
R += 3;
b *= 1000;
}
if (sensor->class == PSC_POWER) {
R += 3;
b *= 1000;
}
while (R > 0) {
val *= 10;
R--;
}
while (R < 0) {
val = DIV_ROUND_CLOSEST(val, 10);
R++;
}
return (val - b) / m;
}
static long pmbus_reg2data_vid(struct pmbus_data *data,
struct pmbus_sensor *sensor)
{
long val = sensor->data;
if (val < 0x02 || val > 0xb2)
return 0;
return DIV_ROUND_CLOSEST(160000 - (val - 2) * 625, 100);
}
static long pmbus_reg2data(struct pmbus_data *data, struct pmbus_sensor *sensor)
{
long val;
switch (data->info->format[sensor->class]) {
case direct:
val = pmbus_reg2data_direct(data, sensor);
break;
case vid:
val = pmbus_reg2data_vid(data, sensor);
break;
case linear:
default:
val = pmbus_reg2data_linear(data, sensor);
break;
}
return val;
}
static u16 pmbus_data2reg_linear(struct pmbus_data *data,
enum pmbus_sensor_classes class, long val)
{
s16 exponent = 0, mantissa;
bool negative = false;
if (val == 0)
return 0;
if (class == PSC_VOLTAGE_OUT) {
if (val < 0)
return 0;
if (data->exponent < 0)
val <<= -data->exponent;
else
val >>= data->exponent;
val = DIV_ROUND_CLOSEST(val, 1000);
return val & 0xffff;
}
if (val < 0) {
negative = true;
val = -val;
}
if (class == PSC_POWER)
val = DIV_ROUND_CLOSEST(val, 1000L);
if (class == PSC_FAN)
val = val * 1000;
while (val >= MAX_MANTISSA && exponent < 15) {
exponent++;
val >>= 1;
}
while (val < MIN_MANTISSA && exponent > -15) {
exponent--;
val <<= 1;
}
mantissa = DIV_ROUND_CLOSEST(val, 1000);
if (mantissa > 0x3ff)
mantissa = 0x3ff;
if (negative)
mantissa = -mantissa;
return (mantissa & 0x7ff) | ((exponent << 11) & 0xf800);
}
static u16 pmbus_data2reg_direct(struct pmbus_data *data,
enum pmbus_sensor_classes class, long val)
{
long m, b, R;
m = data->info->m[class];
b = data->info->b[class];
R = data->info->R[class];
if (class == PSC_POWER) {
R -= 3;
b *= 1000;
}
if (class != PSC_FAN) {
R -= 3;
b *= 1000;
}
val = val * m + b;
while (R > 0) {
val *= 10;
R--;
}
while (R < 0) {
val = DIV_ROUND_CLOSEST(val, 10);
R++;
}
return val;
}
static u16 pmbus_data2reg_vid(struct pmbus_data *data,
enum pmbus_sensor_classes class, long val)
{
val = SENSORS_LIMIT(val, 500, 1600);
return 2 + DIV_ROUND_CLOSEST((1600 - val) * 100, 625);
}
static u16 pmbus_data2reg(struct pmbus_data *data,
enum pmbus_sensor_classes class, long val)
{
u16 regval;
switch (data->info->format[class]) {
case direct:
regval = pmbus_data2reg_direct(data, class, val);
break;
case vid:
regval = pmbus_data2reg_vid(data, class, val);
break;
case linear:
default:
regval = pmbus_data2reg_linear(data, class, val);
break;
}
return regval;
}
static int pmbus_get_boolean(struct pmbus_data *data, int index)
{
u8 s1 = (index >> 24) & 0xff;
u8 s2 = (index >> 16) & 0xff;
u8 reg = (index >> 8) & 0xff;
u8 mask = index & 0xff;
int ret, status;
u8 regval;
status = data->status[reg];
if (status < 0)
return status;
regval = status & mask;
if (!s1 && !s2)
ret = !!regval;
else {
long v1, v2;
struct pmbus_sensor *sensor1, *sensor2;
sensor1 = &data->sensors[s1];
if (sensor1->data < 0)
return sensor1->data;
sensor2 = &data->sensors[s2];
if (sensor2->data < 0)
return sensor2->data;
v1 = pmbus_reg2data(data, sensor1);
v2 = pmbus_reg2data(data, sensor2);
ret = !!(regval && v1 >= v2);
}
return ret;
}
static ssize_t pmbus_show_boolean(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct pmbus_data *data = pmbus_update_device(dev);
int val;
val = pmbus_get_boolean(data, attr->index);
if (val < 0)
return val;
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t pmbus_show_sensor(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct pmbus_data *data = pmbus_update_device(dev);
struct pmbus_sensor *sensor;
sensor = &data->sensors[attr->index];
if (sensor->data < 0)
return sensor->data;
return snprintf(buf, PAGE_SIZE, "%ld\n", pmbus_reg2data(data, sensor));
}
static ssize_t pmbus_set_sensor(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct pmbus_data *data = i2c_get_clientdata(client);
struct pmbus_sensor *sensor = &data->sensors[attr->index];
ssize_t rv = count;
long val = 0;
int ret;
u16 regval;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
regval = pmbus_data2reg(data, sensor->class, val);
ret = _pmbus_write_word_data(client, sensor->page, sensor->reg, regval);
if (ret < 0)
rv = ret;
else
data->sensors[attr->index].data = regval;
mutex_unlock(&data->update_lock);
return rv;
}
static ssize_t pmbus_show_label(struct device *dev,
struct device_attribute *da, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct pmbus_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
return snprintf(buf, PAGE_SIZE, "%s\n",
data->labels[attr->index].label);
}
static void pmbus_add_boolean(struct pmbus_data *data,
const char *name, const char *type, int seq,
int idx)
{
struct pmbus_boolean *boolean;
BUG_ON(data->num_booleans >= data->max_booleans);
boolean = &data->booleans[data->num_booleans];
snprintf(boolean->name, sizeof(boolean->name), "%s%d_%s",
name, seq, type);
PMBUS_ADD_GET_ATTR(data, boolean->name, boolean, idx);
data->num_booleans++;
}
static void pmbus_add_boolean_reg(struct pmbus_data *data,
const char *name, const char *type,
int seq, int reg, int bit)
{
pmbus_add_boolean(data, name, type, seq, (reg << 8) | bit);
}
static void pmbus_add_boolean_cmp(struct pmbus_data *data,
const char *name, const char *type,
int seq, int i1, int i2, int reg, int mask)
{
pmbus_add_boolean(data, name, type, seq,
(i1 << 24) | (i2 << 16) | (reg << 8) | mask);
}
static void pmbus_add_sensor(struct pmbus_data *data,
const char *name, const char *type, int seq,
int page, int reg, enum pmbus_sensor_classes class,
bool update, bool readonly)
{
struct pmbus_sensor *sensor;
BUG_ON(data->num_sensors >= data->max_sensors);
sensor = &data->sensors[data->num_sensors];
snprintf(sensor->name, sizeof(sensor->name), "%s%d_%s",
name, seq, type);
sensor->page = page;
sensor->reg = reg;
sensor->class = class;
sensor->update = update;
if (readonly)
PMBUS_ADD_GET_ATTR(data, sensor->name, sensor,
data->num_sensors);
else
PMBUS_ADD_SET_ATTR(data, sensor->name, sensor,
data->num_sensors);
data->num_sensors++;
}
static void pmbus_add_label(struct pmbus_data *data,
const char *name, int seq,
const char *lstring, int index)
{
struct pmbus_label *label;
BUG_ON(data->num_labels >= data->max_labels);
label = &data->labels[data->num_labels];
snprintf(label->name, sizeof(label->name), "%s%d_label", name, seq);
if (!index)
strncpy(label->label, lstring, sizeof(label->label) - 1);
else
snprintf(label->label, sizeof(label->label), "%s%d", lstring,
index);
PMBUS_ADD_GET_ATTR(data, label->name, label, data->num_labels);
data->num_labels++;
}
static void pmbus_find_max_attr(struct i2c_client *client,
struct pmbus_data *data)
{
const struct pmbus_driver_info *info = data->info;
int page, max_sensors, max_booleans, max_labels;
max_sensors = PMBUS_MAX_INPUT_SENSORS;
max_booleans = PMBUS_MAX_INPUT_BOOLEANS;
max_labels = PMBUS_MAX_INPUT_LABELS;
for (page = 0; page < info->pages; page++) {
if (info->func[page] & PMBUS_HAVE_VOUT) {
max_sensors += PMBUS_VOUT_SENSORS_PER_PAGE;
max_booleans += PMBUS_VOUT_BOOLEANS_PER_PAGE;
max_labels++;
}
if (info->func[page] & PMBUS_HAVE_IOUT) {
max_sensors += PMBUS_IOUT_SENSORS_PER_PAGE;
max_booleans += PMBUS_IOUT_BOOLEANS_PER_PAGE;
max_labels++;
}
if (info->func[page] & PMBUS_HAVE_POUT) {
max_sensors += PMBUS_POUT_SENSORS_PER_PAGE;
max_booleans += PMBUS_POUT_BOOLEANS_PER_PAGE;
max_labels++;
}
if (info->func[page] & PMBUS_HAVE_FAN12) {
max_sensors += 2 * PMBUS_MAX_SENSORS_PER_FAN;
max_booleans += 2 * PMBUS_MAX_BOOLEANS_PER_FAN;
}
if (info->func[page] & PMBUS_HAVE_FAN34) {
max_sensors += 2 * PMBUS_MAX_SENSORS_PER_FAN;
max_booleans += 2 * PMBUS_MAX_BOOLEANS_PER_FAN;
}
if (info->func[page] & PMBUS_HAVE_TEMP) {
max_sensors += PMBUS_MAX_SENSORS_PER_TEMP;
max_booleans += PMBUS_MAX_BOOLEANS_PER_TEMP;
}
if (info->func[page] & PMBUS_HAVE_TEMP2) {
max_sensors += PMBUS_MAX_SENSORS_PER_TEMP;
max_booleans += PMBUS_MAX_BOOLEANS_PER_TEMP;
}
if (info->func[page] & PMBUS_HAVE_TEMP3) {
max_sensors += PMBUS_MAX_SENSORS_PER_TEMP;
max_booleans += PMBUS_MAX_BOOLEANS_PER_TEMP;
}
}
data->max_sensors = max_sensors;
data->max_booleans = max_booleans;
data->max_labels = max_labels;
data->max_attributes = max_sensors + max_booleans + max_labels;
}
static bool pmbus_add_limit_attrs(struct i2c_client *client,
struct pmbus_data *data,
const struct pmbus_driver_info *info,
const char *name, int index, int page,
int cbase,
const struct pmbus_sensor_attr *attr)
{
const struct pmbus_limit_attr *l = attr->limit;
int nlimit = attr->nlimit;
bool have_alarm = false;
int i, cindex;
for (i = 0; i < nlimit; i++) {
if (pmbus_check_word_register(client, page, l->reg)) {
cindex = data->num_sensors;
pmbus_add_sensor(data, name, l->attr, index, page,
l->reg, attr->class,
attr->update || l->update,
false);
if (l->sbit && (info->func[page] & attr->sfunc)) {
if (attr->compare) {
pmbus_add_boolean_cmp(data, name,
l->alarm, index,
l->low ? cindex : cbase,
l->low ? cbase : cindex,
attr->sbase + page, l->sbit);
} else {
pmbus_add_boolean_reg(data, name,
l->alarm, index,
attr->sbase + page, l->sbit);
}
have_alarm = true;
}
}
l++;
}
return have_alarm;
}
static void pmbus_add_sensor_attrs_one(struct i2c_client *client,
struct pmbus_data *data,
const struct pmbus_driver_info *info,
const char *name,
int index, int page,
const struct pmbus_sensor_attr *attr)
{
bool have_alarm;
int cbase = data->num_sensors;
if (attr->label)
pmbus_add_label(data, name, index, attr->label,
attr->paged ? page + 1 : 0);
pmbus_add_sensor(data, name, "input", index, page, attr->reg,
attr->class, true, true);
if (attr->sfunc) {
have_alarm = pmbus_add_limit_attrs(client, data, info, name,
index, page, cbase, attr);
if (!have_alarm && attr->gbit &&
pmbus_check_byte_register(client, page, PMBUS_STATUS_BYTE))
pmbus_add_boolean_reg(data, name, "alarm", index,
PB_STATUS_BASE + page,
attr->gbit);
}
}
static void pmbus_add_sensor_attrs(struct i2c_client *client,
struct pmbus_data *data,
const char *name,
const struct pmbus_sensor_attr *attrs,
int nattrs)
{
const struct pmbus_driver_info *info = data->info;
int index, i;
index = 1;
for (i = 0; i < nattrs; i++) {
int page, pages;
pages = attrs->paged ? info->pages : 1;
for (page = 0; page < pages; page++) {
if (!(info->func[page] & attrs->func))
continue;
pmbus_add_sensor_attrs_one(client, data, info, name,
index, page, attrs);
index++;
}
attrs++;
}
}
static void pmbus_add_fan_attributes(struct i2c_client *client,
struct pmbus_data *data)
{
const struct pmbus_driver_info *info = data->info;
int index = 1;
int page;
for (page = 0; page < info->pages; page++) {
int f;
for (f = 0; f < ARRAY_SIZE(pmbus_fan_registers); f++) {
int regval;
if (!(info->func[page] & pmbus_fan_flags[f]))
break;
if (!pmbus_check_word_register(client, page,
pmbus_fan_registers[f]))
break;
regval = _pmbus_read_byte_data(client, page,
pmbus_fan_config_registers[f]);
if (regval < 0 ||
(!(regval & (PB_FAN_1_INSTALLED >> ((f & 1) * 4)))))
continue;
pmbus_add_sensor(data, "fan", "input", index, page,
pmbus_fan_registers[f], PSC_FAN, true,
true);
if ((info->func[page] & pmbus_fan_status_flags[f]) &&
pmbus_check_byte_register(client,
page, pmbus_fan_status_registers[f])) {
int base;
if (f > 1)
base = PB_STATUS_FAN34_BASE + page;
else
base = PB_STATUS_FAN_BASE + page;
pmbus_add_boolean_reg(data, "fan", "alarm",
index, base,
PB_FAN_FAN1_WARNING >> (f & 1));
pmbus_add_boolean_reg(data, "fan", "fault",
index, base,
PB_FAN_FAN1_FAULT >> (f & 1));
}
index++;
}
}
}
static void pmbus_find_attributes(struct i2c_client *client,
struct pmbus_data *data)
{
pmbus_add_sensor_attrs(client, data, "in", voltage_attributes,
ARRAY_SIZE(voltage_attributes));
pmbus_add_sensor_attrs(client, data, "curr", current_attributes,
ARRAY_SIZE(current_attributes));
pmbus_add_sensor_attrs(client, data, "power", power_attributes,
ARRAY_SIZE(power_attributes));
pmbus_add_sensor_attrs(client, data, "temp", temp_attributes,
ARRAY_SIZE(temp_attributes));
pmbus_add_fan_attributes(client, data);
}
static int pmbus_identify_common(struct i2c_client *client,
struct pmbus_data *data)
{
int vout_mode = -1;
if (pmbus_check_byte_register(client, 0, PMBUS_VOUT_MODE))
vout_mode = _pmbus_read_byte_data(client, 0, PMBUS_VOUT_MODE);
if (vout_mode >= 0 && vout_mode != 0xff) {
switch (vout_mode >> 5) {
case 0:
if (data->info->format[PSC_VOLTAGE_OUT] != linear)
return -ENODEV;
data->exponent = ((s8)(vout_mode << 3)) >> 3;
break;
case 1:
if (data->info->format[PSC_VOLTAGE_OUT] != vid)
return -ENODEV;
break;
case 2:
if (data->info->format[PSC_VOLTAGE_OUT] != direct)
return -ENODEV;
break;
default:
return -ENODEV;
}
}
pmbus_find_max_attr(client, data);
pmbus_clear_fault_page(client, 0);
return 0;
}
int pmbus_do_probe(struct i2c_client *client, const struct i2c_device_id *id,
struct pmbus_driver_info *info)
{
const struct pmbus_platform_data *pdata = client->dev.platform_data;
struct pmbus_data *data;
int ret;
if (!info) {
dev_err(&client->dev, "Missing chip information");
return -ENODEV;
}
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WRITE_BYTE
| I2C_FUNC_SMBUS_BYTE_DATA
| I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
dev_err(&client->dev, "No memory to allocate driver data\n");
return -ENOMEM;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
if (i2c_smbus_read_byte_data(client, PMBUS_STATUS_BYTE) < 0) {
dev_err(&client->dev, "PMBus status register not found\n");
return -ENODEV;
}
if (pdata)
data->flags = pdata->flags;
data->info = info;
pmbus_clear_faults(client);
if (info->identify) {
ret = (*info->identify)(client, info);
if (ret < 0) {
dev_err(&client->dev, "Chip identification failed\n");
return ret;
}
}
if (info->pages <= 0 || info->pages > PMBUS_PAGES) {
dev_err(&client->dev, "Bad number of PMBus pages: %d\n",
info->pages);
return -ENODEV;
}
ret = pmbus_identify_common(client, data);
if (ret < 0) {
dev_err(&client->dev, "Failed to identify chip capabilities\n");
return ret;
}
ret = -ENOMEM;
data->sensors = devm_kzalloc(&client->dev, sizeof(struct pmbus_sensor)
* data->max_sensors, GFP_KERNEL);
if (!data->sensors) {
dev_err(&client->dev, "No memory to allocate sensor data\n");
return -ENOMEM;
}
data->booleans = devm_kzalloc(&client->dev, sizeof(struct pmbus_boolean)
* data->max_booleans, GFP_KERNEL);
if (!data->booleans) {
dev_err(&client->dev, "No memory to allocate boolean data\n");
return -ENOMEM;
}
data->labels = devm_kzalloc(&client->dev, sizeof(struct pmbus_label)
* data->max_labels, GFP_KERNEL);
if (!data->labels) {
dev_err(&client->dev, "No memory to allocate label data\n");
return -ENOMEM;
}
data->attributes = devm_kzalloc(&client->dev, sizeof(struct attribute *)
* data->max_attributes, GFP_KERNEL);
if (!data->attributes) {
dev_err(&client->dev, "No memory to allocate attribute data\n");
return -ENOMEM;
}
pmbus_find_attributes(client, data);
if (!data->num_attributes) {
dev_err(&client->dev, "No attributes found\n");
return -ENODEV;
}
data->group.attrs = data->attributes;
ret = sysfs_create_group(&client->dev.kobj, &data->group);
if (ret) {
dev_err(&client->dev, "Failed to create sysfs entries\n");
return ret;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
dev_err(&client->dev, "Failed to register hwmon device\n");
goto out_hwmon_device_register;
}
return 0;
out_hwmon_device_register:
sysfs_remove_group(&client->dev.kobj, &data->group);
return ret;
}
int pmbus_do_remove(struct i2c_client *client)
{
struct pmbus_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &data->group);
return 0;
}
