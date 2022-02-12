static int mca_find_adapter_callback(struct device *dev, void *data)
{
struct mca_find_adapter_info *info = data;
struct mca_device *mca_dev = to_mca_device(dev);
if(mca_dev->pos_id != info->id)
return 0;
if(mca_dev->slot < info->slot)
return 0;
if(!info->mca_dev || info->mca_dev->slot >= mca_dev->slot)
info->mca_dev = mca_dev;
return 0;
}
int mca_find_adapter(int id, int start)
{
struct mca_find_adapter_info info;
if(id == 0xffff)
return MCA_NOTFOUND;
info.slot = start;
info.id = id;
info.mca_dev = NULL;
for(;;) {
bus_for_each_dev(&mca_bus_type, NULL, &info, mca_find_adapter_callback);
if(info.mca_dev == NULL)
return MCA_NOTFOUND;
if(info.mca_dev->status != MCA_ADAPTER_DISABLED)
break;
info.slot = info.mca_dev->slot + 1;
info.mca_dev = NULL;
}
return info.mca_dev->slot;
}
int mca_find_unused_adapter(int id, int start)
{
struct mca_find_adapter_info info = { 0 };
if (!MCA_bus || id == 0xffff)
return MCA_NOTFOUND;
info.slot = start;
info.id = id;
info.mca_dev = NULL;
for(;;) {
bus_for_each_dev(&mca_bus_type, NULL, &info, mca_find_adapter_callback);
if(info.mca_dev == NULL)
return MCA_NOTFOUND;
if(info.mca_dev->status != MCA_ADAPTER_DISABLED
&& !info.mca_dev->driver_loaded)
break;
info.slot = info.mca_dev->slot + 1;
info.mca_dev = NULL;
}
return info.mca_dev->slot;
}
static int mca_find_device_by_slot_callback(struct device *dev, void *data)
{
struct mca_find_device_by_slot_info *info = data;
struct mca_device *mca_dev = to_mca_device(dev);
if(mca_dev->slot == info->slot)
info->mca_dev = mca_dev;
return 0;
}
struct mca_device *mca_find_device_by_slot(int slot)
{
struct mca_find_device_by_slot_info info;
info.slot = slot;
info.mca_dev = NULL;
bus_for_each_dev(&mca_bus_type, NULL, &info, mca_find_device_by_slot_callback);
return info.mca_dev;
}
unsigned char mca_read_stored_pos(int slot, int reg)
{
struct mca_device *mca_dev = mca_find_device_by_slot(slot);
if(!mca_dev)
return 0;
return mca_device_read_stored_pos(mca_dev, reg);
}
unsigned char mca_read_pos(int slot, int reg)
{
struct mca_device *mca_dev = mca_find_device_by_slot(slot);
if(!mca_dev)
return 0;
return mca_device_read_pos(mca_dev, reg);
}
void mca_write_pos(int slot, int reg, unsigned char byte)
{
struct mca_device *mca_dev = mca_find_device_by_slot(slot);
if(!mca_dev)
return;
mca_device_write_pos(mca_dev, reg, byte);
}
void mca_set_adapter_name(int slot, char* name)
{
struct mca_device *mca_dev = mca_find_device_by_slot(slot);
if(!mca_dev)
return;
mca_device_set_name(mca_dev, name);
}
int mca_mark_as_used(int slot)
{
struct mca_device *mca_dev = mca_find_device_by_slot(slot);
if(!mca_dev)
return 1;
if(mca_device_claimed(mca_dev))
return 1;
mca_device_set_claim(mca_dev, 1);
return 0;
}
void mca_mark_as_unused(int slot)
{
struct mca_device *mca_dev = mca_find_device_by_slot(slot);
if(!mca_dev)
return;
mca_device_set_claim(mca_dev, 0);
}
