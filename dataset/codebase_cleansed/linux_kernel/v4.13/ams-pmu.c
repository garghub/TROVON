static void ams_pmu_req_complete(struct adb_request *req)
{
complete((struct completion *)req->arg);
}
static void ams_pmu_set_register(u8 reg, u8 value)
{
static struct adb_request req;
DECLARE_COMPLETION(req_complete);
req.arg = &req_complete;
if (pmu_request(&req, ams_pmu_req_complete, 4, ams_pmu_cmd, 0x00, reg, value))
return;
wait_for_completion(&req_complete);
}
static u8 ams_pmu_get_register(u8 reg)
{
static struct adb_request req;
DECLARE_COMPLETION(req_complete);
req.arg = &req_complete;
if (pmu_request(&req, ams_pmu_req_complete, 3, ams_pmu_cmd, 0x01, reg))
return 0;
wait_for_completion(&req_complete);
if (req.reply_len > 0)
return req.reply[0];
else
return 0;
}
static void ams_pmu_set_irq(enum ams_irq reg, char enable)
{
if (reg & AMS_IRQ_FREEFALL) {
u8 val = ams_pmu_get_register(AMS_FF_ENABLE);
if (enable)
val |= 0x80;
else
val &= ~0x80;
ams_pmu_set_register(AMS_FF_ENABLE, val);
}
if (reg & AMS_IRQ_SHOCK) {
u8 val = ams_pmu_get_register(AMS_SHOCK_ENABLE);
if (enable)
val |= 0x80;
else
val &= ~0x80;
ams_pmu_set_register(AMS_SHOCK_ENABLE, val);
}
if (reg & AMS_IRQ_GLOBAL) {
u8 val = ams_pmu_get_register(AMS_CONTROL);
if (enable)
val |= 0x80;
else
val &= ~0x80;
ams_pmu_set_register(AMS_CONTROL, val);
}
}
static void ams_pmu_clear_irq(enum ams_irq reg)
{
if (reg & AMS_IRQ_FREEFALL)
ams_pmu_set_register(AMS_FF_CLEAR, 0x00);
if (reg & AMS_IRQ_SHOCK)
ams_pmu_set_register(AMS_SHOCK_CLEAR, 0x00);
}
static u8 ams_pmu_get_vendor(void)
{
return ams_pmu_get_register(AMS_VENDOR);
}
static void ams_pmu_get_xyz(s8 *x, s8 *y, s8 *z)
{
*x = ams_pmu_get_register(AMS_X);
*y = ams_pmu_get_register(AMS_Y);
*z = ams_pmu_get_register(AMS_Z);
}
static void ams_pmu_exit(void)
{
ams_sensor_detach();
ams_pmu_set_irq(AMS_IRQ_ALL, 0);
ams_pmu_clear_irq(AMS_IRQ_ALL);
ams_info.has_device = 0;
printk(KERN_INFO "ams: Unloading\n");
}
int __init ams_pmu_init(struct device_node *np)
{
const u32 *prop;
int result;
ams_info.of_node = np;
ams_info.exit = ams_pmu_exit;
ams_info.get_vendor = ams_pmu_get_vendor;
ams_info.get_xyz = ams_pmu_get_xyz;
ams_info.clear_irq = ams_pmu_clear_irq;
ams_info.bustype = BUS_HOST;
prop = of_get_property(ams_info.of_node, "reg", NULL);
if (!prop)
return -ENODEV;
ams_pmu_cmd = ((*prop) >> 8) & 0xff;
ams_pmu_set_irq(AMS_IRQ_ALL, 0);
ams_pmu_clear_irq(AMS_IRQ_ALL);
result = ams_sensor_attach();
if (result < 0)
return result;
ams_pmu_set_register(AMS_FF_LOW_LIMIT, 0x15);
ams_pmu_set_register(AMS_FF_ENABLE, 0x08);
ams_pmu_set_register(AMS_FF_DEBOUNCE, 0x14);
ams_pmu_set_register(AMS_SHOCK_HIGH_LIMIT, 0x60);
ams_pmu_set_register(AMS_SHOCK_ENABLE, 0x0f);
ams_pmu_set_register(AMS_SHOCK_DEBOUNCE, 0x14);
ams_pmu_set_register(AMS_CONTROL, 0x4f);
ams_pmu_clear_irq(AMS_IRQ_ALL);
ams_info.has_device = 1;
ams_pmu_set_irq(AMS_IRQ_ALL, 1);
printk(KERN_INFO "ams: Found PMU based motion sensor\n");
return 0;
}
