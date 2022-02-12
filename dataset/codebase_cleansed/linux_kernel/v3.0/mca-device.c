unsigned char mca_device_read_stored_pos(struct mca_device *mca_dev, int reg)
{
if(reg < 0 || reg >= 8)
return 0;
return mca_dev->pos[reg];
}
unsigned char mca_device_read_pos(struct mca_device *mca_dev, int reg)
{
struct mca_bus *mca_bus = to_mca_bus(mca_dev->dev.parent);
return mca_bus->f.mca_read_pos(mca_dev, reg);
return mca_dev->pos[reg];
}
void mca_device_write_pos(struct mca_device *mca_dev, int reg,
unsigned char byte)
{
struct mca_bus *mca_bus = to_mca_bus(mca_dev->dev.parent);
mca_bus->f.mca_write_pos(mca_dev, reg, byte);
}
int mca_device_transform_irq(struct mca_device *mca_dev, int irq)
{
struct mca_bus *mca_bus = to_mca_bus(mca_dev->dev.parent);
return mca_bus->f.mca_transform_irq(mca_dev, irq);
}
int mca_device_transform_ioport(struct mca_device *mca_dev, int port)
{
struct mca_bus *mca_bus = to_mca_bus(mca_dev->dev.parent);
return mca_bus->f.mca_transform_ioport(mca_dev, port);
}
void *mca_device_transform_memory(struct mca_device *mca_dev, void *mem)
{
struct mca_bus *mca_bus = to_mca_bus(mca_dev->dev.parent);
return mca_bus->f.mca_transform_memory(mca_dev, mem);
}
int mca_device_claimed(struct mca_device *mca_dev)
{
return mca_dev->driver_loaded;
}
void mca_device_set_claim(struct mca_device *mca_dev, int val)
{
mca_dev->driver_loaded = val;
}
enum MCA_AdapterStatus mca_device_status(struct mca_device *mca_dev)
{
return mca_dev->status;
}
void mca_device_set_name(struct mca_device *mca_dev, const char *name)
{
if(!mca_dev)
return;
strlcpy(mca_dev->name, name, sizeof(mca_dev->name));
}
