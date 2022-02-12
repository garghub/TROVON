int ib_device_register_rdmacg(struct ib_device *device)
{
device->cg_device.name = device->name;
return rdmacg_register_device(&device->cg_device);
}
void ib_device_unregister_rdmacg(struct ib_device *device)
{
rdmacg_unregister_device(&device->cg_device);
}
int ib_rdmacg_try_charge(struct ib_rdmacg_object *cg_obj,
struct ib_device *device,
enum rdmacg_resource_type resource_index)
{
return rdmacg_try_charge(&cg_obj->cg, &device->cg_device,
resource_index);
}
void ib_rdmacg_uncharge(struct ib_rdmacg_object *cg_obj,
struct ib_device *device,
enum rdmacg_resource_type resource_index)
{
rdmacg_uncharge(cg_obj->cg, &device->cg_device,
resource_index);
}
