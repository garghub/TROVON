static int __init via_pmu_event_init(void)
{
int err;
if (pmu_get_model() != PMU_KEYLARGO_BASED)
return -ENODEV;
pmu_input_dev = input_allocate_device();
if (!pmu_input_dev)
return -ENOMEM;
pmu_input_dev->name = "PMU";
pmu_input_dev->id.bustype = BUS_HOST;
pmu_input_dev->id.vendor = 0x0001;
pmu_input_dev->id.product = 0x0001;
pmu_input_dev->id.version = 0x0100;
set_bit(EV_KEY, pmu_input_dev->evbit);
set_bit(EV_SW, pmu_input_dev->evbit);
set_bit(KEY_POWER, pmu_input_dev->keybit);
set_bit(SW_LID, pmu_input_dev->swbit);
err = input_register_device(pmu_input_dev);
if (err)
input_free_device(pmu_input_dev);
return err;
}
void via_pmu_event(int key, int down)
{
if (unlikely(!pmu_input_dev))
return;
switch (key) {
case PMU_EVT_POWER:
input_report_key(pmu_input_dev, KEY_POWER, down);
break;
case PMU_EVT_LID:
input_report_switch(pmu_input_dev, SW_LID, down);
break;
default:
return;
}
input_sync(pmu_input_dev);
}
