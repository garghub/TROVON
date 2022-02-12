static int wf_lm87_read_reg(struct i2c_client *chip, int reg)
{
int rc, tries = 0;
u8 buf;
for (;;) {
buf = (u8)reg;
rc = i2c_master_send(chip, &buf, 1);
if (rc <= 0)
goto error;
rc = i2c_master_recv(chip, &buf, 1);
if (rc <= 0)
goto error;
return (int)buf;
error:
DBG("wf_lm87: Error reading LM87, retrying...\n");
if (++tries > 10) {
printk(KERN_ERR "wf_lm87: Error reading LM87 !\n");
return -EIO;
}
msleep(10);
}
}
static int wf_lm87_get(struct wf_sensor *sr, s32 *value)
{
struct wf_lm87_sensor *lm = sr->priv;
s32 temp;
if (lm->i2c == NULL)
return -ENODEV;
#define LM87_INT_TEMP 0x27
temp = wf_lm87_read_reg(lm->i2c, LM87_INT_TEMP);
if (temp < 0)
return temp;
*value = temp << 16;
return 0;
}
static void wf_lm87_release(struct wf_sensor *sr)
{
struct wf_lm87_sensor *lm = wf_to_lm87(sr);
kfree(lm);
}
static int wf_lm87_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct wf_lm87_sensor *lm;
const char *name = NULL, *loc;
struct device_node *np = NULL;
int rc;
while ((np = of_get_next_child(client->dev.of_node, np)) != NULL) {
if (strcmp(np->name, "int-temp"))
continue;
loc = of_get_property(np, "location", NULL);
if (!loc)
continue;
if (strstr(loc, "DIMM"))
name = "dimms-temp";
else if (strstr(loc, "Processors"))
name = "between-cpus-temp";
if (name) {
of_node_put(np);
break;
}
}
if (!name) {
pr_warning("wf_lm87: Unsupported sensor %pOF\n",
client->dev.of_node);
return -ENODEV;
}
lm = kzalloc(sizeof(struct wf_lm87_sensor), GFP_KERNEL);
if (lm == NULL)
return -ENODEV;
lm->i2c = client;
lm->sens.name = name;
lm->sens.ops = &wf_lm87_ops;
lm->sens.priv = lm;
i2c_set_clientdata(client, lm);
rc = wf_register_sensor(&lm->sens);
if (rc)
kfree(lm);
return rc;
}
static int wf_lm87_remove(struct i2c_client *client)
{
struct wf_lm87_sensor *lm = i2c_get_clientdata(client);
DBG("wf_lm87: i2c detatch called for %s\n", lm->sens.name);
lm->i2c = NULL;
wf_unregister_sensor(&lm->sens);
return 0;
}
static int __init wf_lm87_sensor_init(void)
{
if (!of_machine_is_compatible("RackMac3,1"))
return -ENODEV;
return i2c_add_driver(&wf_lm87_driver);
}
static void __exit wf_lm87_sensor_exit(void)
{
i2c_del_driver(&wf_lm87_driver);
}
