int input_event_from_user(const char __user *buffer,
struct input_event *event)
{
if (INPUT_COMPAT_TEST && !COMPAT_USE_64BIT_TIME) {
struct input_event_compat compat_event;
if (copy_from_user(&compat_event, buffer,
sizeof(struct input_event_compat)))
return -EFAULT;
event->time.tv_sec = compat_event.time.tv_sec;
event->time.tv_usec = compat_event.time.tv_usec;
event->type = compat_event.type;
event->code = compat_event.code;
event->value = compat_event.value;
} else {
if (copy_from_user(event, buffer, sizeof(struct input_event)))
return -EFAULT;
}
return 0;
}
int input_event_to_user(char __user *buffer,
const struct input_event *event)
{
if (INPUT_COMPAT_TEST && !COMPAT_USE_64BIT_TIME) {
struct input_event_compat compat_event;
compat_event.time.tv_sec = event->time.tv_sec;
compat_event.time.tv_usec = event->time.tv_usec;
compat_event.type = event->type;
compat_event.code = event->code;
compat_event.value = event->value;
if (copy_to_user(buffer, &compat_event,
sizeof(struct input_event_compat)))
return -EFAULT;
} else {
if (copy_to_user(buffer, event, sizeof(struct input_event)))
return -EFAULT;
}
return 0;
}
int input_ff_effect_from_user(const char __user *buffer, size_t size,
struct ff_effect *effect)
{
if (INPUT_COMPAT_TEST) {
struct ff_effect_compat *compat_effect;
if (size != sizeof(struct ff_effect_compat))
return -EINVAL;
compat_effect = (struct ff_effect_compat *)effect;
if (copy_from_user(compat_effect, buffer,
sizeof(struct ff_effect_compat)))
return -EFAULT;
if (compat_effect->type == FF_PERIODIC &&
compat_effect->u.periodic.waveform == FF_CUSTOM)
effect->u.periodic.custom_data =
compat_ptr(compat_effect->u.periodic.custom_data);
} else {
if (size != sizeof(struct ff_effect))
return -EINVAL;
if (copy_from_user(effect, buffer, sizeof(struct ff_effect)))
return -EFAULT;
}
return 0;
}
int input_event_from_user(const char __user *buffer,
struct input_event *event)
{
if (copy_from_user(event, buffer, sizeof(struct input_event)))
return -EFAULT;
return 0;
}
int input_event_to_user(char __user *buffer,
const struct input_event *event)
{
if (copy_to_user(buffer, event, sizeof(struct input_event)))
return -EFAULT;
return 0;
}
int input_ff_effect_from_user(const char __user *buffer, size_t size,
struct ff_effect *effect)
{
if (size != sizeof(struct ff_effect))
return -EINVAL;
if (copy_from_user(effect, buffer, sizeof(struct ff_effect)))
return -EFAULT;
return 0;
}
