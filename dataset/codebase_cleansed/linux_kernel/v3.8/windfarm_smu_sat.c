struct smu_sdbp_header *smu_sat_get_sdb_partition(unsigned int sat_id, int id,
unsigned int *size)
{
struct wf_sat *sat;
int err;
unsigned int i, len;
u8 *buf;
u8 data[4];
if (sat_id > 1 || (sat = sats[sat_id]) == NULL)
return NULL;
err = i2c_smbus_write_word_data(sat->i2c, 8, id << 8);
if (err) {
printk(KERN_ERR "smu_sat_get_sdb_part wr error %d\n", err);
return NULL;
}
err = i2c_smbus_read_word_data(sat->i2c, 9);
if (err < 0) {
printk(KERN_ERR "smu_sat_get_sdb_part rd len error\n");
return NULL;
}
len = err;
if (len == 0) {
printk(KERN_ERR "smu_sat_get_sdb_part no partition %x\n", id);
return NULL;
}
len = le16_to_cpu(len);
len = (len + 3) & ~3;
buf = kmalloc(len, GFP_KERNEL);
if (buf == NULL)
return NULL;
for (i = 0; i < len; i += 4) {
err = i2c_smbus_read_i2c_block_data(sat->i2c, 0xa, 4, data);
if (err < 0) {
printk(KERN_ERR "smu_sat_get_sdb_part rd err %d\n",
err);
goto fail;
}
buf[i] = data[1];
buf[i+1] = data[0];
buf[i+2] = data[3];
buf[i+3] = data[2];
}
#ifdef DEBUG
DBG(KERN_DEBUG "sat %d partition %x:", sat_id, id);
for (i = 0; i < len; ++i)
DBG(" %x", buf[i]);
DBG("\n");
#endif
if (size)
*size = len;
return (struct smu_sdbp_header *) buf;
fail:
kfree(buf);
return NULL;
}
static int wf_sat_read_cache(struct wf_sat *sat)
{
int err;
err = i2c_smbus_read_i2c_block_data(sat->i2c, 0x3f, 16, sat->cache);
if (err < 0)
return err;
sat->last_read = jiffies;
#ifdef LOTSA_DEBUG
{
int i;
DBG(KERN_DEBUG "wf_sat_get: data is");
for (i = 0; i < 16; ++i)
DBG(" %.2x", sat->cache[i]);
DBG("\n");
}
#endif
return 0;
}
static int wf_sat_sensor_get(struct wf_sensor *sr, s32 *value)
{
struct wf_sat_sensor *sens = wf_to_sat(sr);
struct wf_sat *sat = sens->sat;
int i, err;
s32 val;
if (sat->i2c == NULL)
return -ENODEV;
mutex_lock(&sat->mutex);
if (time_after(jiffies, (sat->last_read + MAX_AGE))) {
err = wf_sat_read_cache(sat);
if (err)
goto fail;
}
i = sens->index * 2;
val = ((sat->cache[i] << 8) + sat->cache[i+1]) << sens->shift;
if (sens->index2 >= 0) {
i = sens->index2 * 2;
val = (val * ((sat->cache[i] << 8) + sat->cache[i+1])) >> 4;
}
*value = val;
err = 0;
fail:
mutex_unlock(&sat->mutex);
return err;
}
static void wf_sat_release(struct kref *ref)
{
struct wf_sat *sat = container_of(ref, struct wf_sat, ref);
if (sat->nr >= 0)
sats[sat->nr] = NULL;
kfree(sat);
}
static void wf_sat_sensor_release(struct wf_sensor *sr)
{
struct wf_sat_sensor *sens = wf_to_sat(sr);
struct wf_sat *sat = sens->sat;
kfree(sens);
kref_put(&sat->ref, wf_sat_release);
}
static int wf_sat_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device_node *dev = client->dev.of_node;
struct wf_sat *sat;
struct wf_sat_sensor *sens;
const u32 *reg;
const char *loc, *type;
u8 chip, core;
struct device_node *child;
int shift, cpu, index;
char *name;
int vsens[2], isens[2];
sat = kzalloc(sizeof(struct wf_sat), GFP_KERNEL);
if (sat == NULL)
return -ENOMEM;
sat->nr = -1;
sat->node = of_node_get(dev);
kref_init(&sat->ref);
mutex_init(&sat->mutex);
sat->i2c = client;
INIT_LIST_HEAD(&sat->sensors);
i2c_set_clientdata(client, sat);
vsens[0] = vsens[1] = -1;
isens[0] = isens[1] = -1;
child = NULL;
while ((child = of_get_next_child(dev, child)) != NULL) {
reg = of_get_property(child, "reg", NULL);
type = of_get_property(child, "device_type", NULL);
loc = of_get_property(child, "location", NULL);
if (reg == NULL || loc == NULL)
continue;
if (*reg < 0x30 || *reg > 0x37)
continue;
index = *reg - 0x30;
if (strncmp(loc, "CPU ", 4) != 0)
continue;
chip = loc[4] - 'A';
core = loc[5] - '0';
if (chip > 1 || core > 1) {
printk(KERN_ERR "wf_sat_create: don't understand "
"location %s for %s\n", loc, child->full_name);
continue;
}
cpu = 2 * chip + core;
if (sat->nr < 0)
sat->nr = chip;
else if (sat->nr != chip) {
printk(KERN_ERR "wf_sat_create: can't cope with "
"multiple CPU chips on one SAT (%s)\n", loc);
continue;
}
if (strcmp(type, "voltage-sensor") == 0) {
name = "cpu-voltage";
shift = 4;
vsens[core] = index;
} else if (strcmp(type, "current-sensor") == 0) {
name = "cpu-current";
shift = 8;
isens[core] = index;
} else if (strcmp(type, "temp-sensor") == 0) {
name = "cpu-temp";
shift = 10;
} else
continue;
sens = kzalloc(sizeof(struct wf_sat_sensor) + 16, GFP_KERNEL);
if (sens == NULL) {
printk(KERN_ERR "wf_sat_create: couldn't create "
"%s sensor %d (no memory)\n", name, cpu);
continue;
}
sens->index = index;
sens->index2 = -1;
sens->shift = shift;
sens->sat = sat;
sens->sens.ops = &wf_sat_ops;
sens->sens.name = (char *) (sens + 1);
snprintf((char *)sens->sens.name, 16, "%s-%d", name, cpu);
if (wf_register_sensor(&sens->sens))
kfree(sens);
else {
list_add(&sens->link, &sat->sensors);
kref_get(&sat->ref);
}
}
for (core = 0; core < 2; ++core) {
if (vsens[core] < 0 || isens[core] < 0)
continue;
cpu = 2 * sat->nr + core;
sens = kzalloc(sizeof(struct wf_sat_sensor) + 16, GFP_KERNEL);
if (sens == NULL) {
printk(KERN_ERR "wf_sat_create: couldn't create power "
"sensor %d (no memory)\n", cpu);
continue;
}
sens->index = vsens[core];
sens->index2 = isens[core];
sens->shift = 0;
sens->sat = sat;
sens->sens.ops = &wf_sat_ops;
sens->sens.name = (char *) (sens + 1);
snprintf((char *)sens->sens.name, 16, "cpu-power-%d", cpu);
if (wf_register_sensor(&sens->sens))
kfree(sens);
else {
list_add(&sens->link, &sat->sensors);
kref_get(&sat->ref);
}
}
if (sat->nr >= 0)
sats[sat->nr] = sat;
return 0;
}
static int wf_sat_remove(struct i2c_client *client)
{
struct wf_sat *sat = i2c_get_clientdata(client);
struct wf_sat_sensor *sens;
while(!list_empty(&sat->sensors)) {
sens = list_first_entry(&sat->sensors,
struct wf_sat_sensor, link);
list_del(&sens->link);
wf_unregister_sensor(&sens->sens);
}
sat->i2c = NULL;
i2c_set_clientdata(client, NULL);
kref_put(&sat->ref, wf_sat_release);
return 0;
}
