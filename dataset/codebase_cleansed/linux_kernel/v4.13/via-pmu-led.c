static void pmu_req_done(struct adb_request * req)
{
unsigned long flags;
spin_lock_irqsave(&pmu_blink_lock, flags);
if (requested_change != -1 && !pmu_sys_suspended)
pmu_request(&pmu_blink_req, NULL, 4, 0xee, 4, 0, requested_change);
requested_change = -1;
spin_unlock_irqrestore(&pmu_blink_lock, flags);
}
static void pmu_led_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
unsigned long flags;
spin_lock_irqsave(&pmu_blink_lock, flags);
switch (brightness) {
case LED_OFF:
requested_change = 0;
break;
case LED_FULL:
requested_change = 1;
break;
default:
goto out;
break;
}
if (pmu_blink_req.complete && !pmu_sys_suspended)
pmu_request(&pmu_blink_req, NULL, 4, 0xee, 4, 0, requested_change);
out:
spin_unlock_irqrestore(&pmu_blink_lock, flags);
}
static int __init via_pmu_led_init(void)
{
struct device_node *dt;
const char *model;
if (pmu_get_model() != PMU_KEYLARGO_BASED)
return -ENODEV;
dt = of_find_node_by_path("/");
if (dt == NULL)
return -ENODEV;
model = of_get_property(dt, "model", NULL);
if (model == NULL) {
of_node_put(dt);
return -ENODEV;
}
if (strncmp(model, "PowerBook", strlen("PowerBook")) != 0 &&
strncmp(model, "iBook", strlen("iBook")) != 0 &&
strcmp(model, "PowerMac7,2") != 0 &&
strcmp(model, "PowerMac7,3") != 0) {
of_node_put(dt);
return -ENODEV;
}
of_node_put(dt);
spin_lock_init(&pmu_blink_lock);
pmu_blink_req.complete = 1;
pmu_blink_req.done = pmu_req_done;
return led_classdev_register(NULL, &pmu_led);
}
