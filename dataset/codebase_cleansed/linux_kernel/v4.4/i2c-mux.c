static int i2c_mux_master_xfer(struct i2c_adapter *adap,
struct i2c_msg msgs[], int num)
{
struct i2c_mux_priv *priv = adap->algo_data;
struct i2c_adapter *parent = priv->parent;
int ret;
ret = priv->select(parent, priv->mux_priv, priv->chan_id);
if (ret >= 0)
ret = __i2c_transfer(parent, msgs, num);
if (priv->deselect)
priv->deselect(parent, priv->mux_priv, priv->chan_id);
return ret;
}
static int i2c_mux_smbus_xfer(struct i2c_adapter *adap,
u16 addr, unsigned short flags,
char read_write, u8 command,
int size, union i2c_smbus_data *data)
{
struct i2c_mux_priv *priv = adap->algo_data;
struct i2c_adapter *parent = priv->parent;
int ret;
ret = priv->select(parent, priv->mux_priv, priv->chan_id);
if (ret >= 0)
ret = parent->algo->smbus_xfer(parent, addr, flags,
read_write, command, size, data);
if (priv->deselect)
priv->deselect(parent, priv->mux_priv, priv->chan_id);
return ret;
}
static u32 i2c_mux_functionality(struct i2c_adapter *adap)
{
struct i2c_mux_priv *priv = adap->algo_data;
struct i2c_adapter *parent = priv->parent;
return parent->algo->functionality(parent);
}
static unsigned int i2c_mux_parent_classes(struct i2c_adapter *parent)
{
unsigned int class = 0;
do {
class |= parent->class;
parent = i2c_parent_is_i2c_adapter(parent);
} while (parent);
return class;
}
struct i2c_adapter *i2c_add_mux_adapter(struct i2c_adapter *parent,
struct device *mux_dev,
void *mux_priv, u32 force_nr, u32 chan_id,
unsigned int class,
int (*select) (struct i2c_adapter *,
void *, u32),
int (*deselect) (struct i2c_adapter *,
void *, u32))
{
struct i2c_mux_priv *priv;
char symlink_name[20];
int ret;
priv = kzalloc(sizeof(struct i2c_mux_priv), GFP_KERNEL);
if (!priv)
return NULL;
priv->parent = parent;
priv->mux_dev = mux_dev;
priv->mux_priv = mux_priv;
priv->chan_id = chan_id;
priv->select = select;
priv->deselect = deselect;
if (parent->algo->master_xfer)
priv->algo.master_xfer = i2c_mux_master_xfer;
if (parent->algo->smbus_xfer)
priv->algo.smbus_xfer = i2c_mux_smbus_xfer;
priv->algo.functionality = i2c_mux_functionality;
snprintf(priv->adap.name, sizeof(priv->adap.name),
"i2c-%d-mux (chan_id %d)", i2c_adapter_id(parent), chan_id);
priv->adap.owner = THIS_MODULE;
priv->adap.algo = &priv->algo;
priv->adap.algo_data = priv;
priv->adap.dev.parent = &parent->dev;
priv->adap.retries = parent->retries;
priv->adap.timeout = parent->timeout;
priv->adap.quirks = parent->quirks;
if (i2c_mux_parent_classes(parent) & class)
dev_err(&parent->dev,
"Segment %d behind mux can't share classes with ancestors\n",
chan_id);
else
priv->adap.class = class;
if (mux_dev->of_node) {
struct device_node *child;
u32 reg;
for_each_child_of_node(mux_dev->of_node, child) {
ret = of_property_read_u32(child, "reg", &reg);
if (ret)
continue;
if (chan_id == reg) {
priv->adap.dev.of_node = child;
break;
}
}
}
if (has_acpi_companion(mux_dev))
acpi_preset_companion(&priv->adap.dev, ACPI_COMPANION(mux_dev),
chan_id);
if (force_nr) {
priv->adap.nr = force_nr;
ret = i2c_add_numbered_adapter(&priv->adap);
} else {
ret = i2c_add_adapter(&priv->adap);
}
if (ret < 0) {
dev_err(&parent->dev,
"failed to add mux-adapter (error=%d)\n",
ret);
kfree(priv);
return NULL;
}
WARN(sysfs_create_link(&priv->adap.dev.kobj, &mux_dev->kobj, "mux_device"),
"can't create symlink to mux device\n");
snprintf(symlink_name, sizeof(symlink_name), "channel-%u", chan_id);
WARN(sysfs_create_link(&mux_dev->kobj, &priv->adap.dev.kobj, symlink_name),
"can't create symlink for channel %u\n", chan_id);
dev_info(&parent->dev, "Added multiplexed i2c bus %d\n",
i2c_adapter_id(&priv->adap));
return &priv->adap;
}
void i2c_del_mux_adapter(struct i2c_adapter *adap)
{
struct i2c_mux_priv *priv = adap->algo_data;
char symlink_name[20];
snprintf(symlink_name, sizeof(symlink_name), "channel-%u", priv->chan_id);
sysfs_remove_link(&priv->mux_dev->kobj, symlink_name);
sysfs_remove_link(&priv->adap.dev.kobj, "mux_device");
i2c_del_adapter(adap);
kfree(priv);
}
