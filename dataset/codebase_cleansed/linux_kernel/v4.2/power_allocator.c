static inline s64 mul_frac(s64 x, s64 y)
{
return (x * y) >> FRAC_BITS;
}
static inline s64 div_frac(s64 x, s64 y)
{
return div_s64(x << FRAC_BITS, y);
}
static u32 pid_controller(struct thermal_zone_device *tz,
unsigned long current_temp,
unsigned long control_temp,
u32 max_allocatable_power)
{
s64 p, i, d, power_range;
s32 err, max_power_frac;
struct power_allocator_params *params = tz->governor_data;
max_power_frac = int_to_frac(max_allocatable_power);
err = ((s32)control_temp - (s32)current_temp);
err = int_to_frac(err);
p = mul_frac(err < 0 ? tz->tzp->k_po : tz->tzp->k_pu, err);
i = mul_frac(tz->tzp->k_i, params->err_integral);
if (err < int_to_frac(tz->tzp->integral_cutoff)) {
s64 i_next = i + mul_frac(tz->tzp->k_i, err);
if (abs64(i_next) < max_power_frac) {
i = i_next;
params->err_integral += err;
}
}
d = mul_frac(tz->tzp->k_d, err - params->prev_err);
d = div_frac(d, tz->passive_delay);
params->prev_err = err;
power_range = p + i + d;
power_range = tz->tzp->sustainable_power + frac_to_int(power_range);
power_range = clamp(power_range, (s64)0, (s64)max_allocatable_power);
trace_thermal_power_allocator_pid(tz, frac_to_int(err),
frac_to_int(params->err_integral),
frac_to_int(p), frac_to_int(i),
frac_to_int(d), power_range);
return power_range;
}
static void divvy_up_power(u32 *req_power, u32 *max_power, int num_actors,
u32 total_req_power, u32 power_range,
u32 *granted_power, u32 *extra_actor_power)
{
u32 extra_power, capped_extra_power;
int i;
if (!total_req_power)
total_req_power = 1;
capped_extra_power = 0;
extra_power = 0;
for (i = 0; i < num_actors; i++) {
u64 req_range = req_power[i] * power_range;
granted_power[i] = DIV_ROUND_CLOSEST_ULL(req_range,
total_req_power);
if (granted_power[i] > max_power[i]) {
extra_power += granted_power[i] - max_power[i];
granted_power[i] = max_power[i];
}
extra_actor_power[i] = max_power[i] - granted_power[i];
capped_extra_power += extra_actor_power[i];
}
if (!extra_power)
return;
extra_power = min(extra_power, capped_extra_power);
if (capped_extra_power > 0)
for (i = 0; i < num_actors; i++)
granted_power[i] += (extra_actor_power[i] *
extra_power) / capped_extra_power;
}
static int allocate_power(struct thermal_zone_device *tz,
unsigned long current_temp,
unsigned long control_temp)
{
struct thermal_instance *instance;
struct power_allocator_params *params = tz->governor_data;
u32 *req_power, *max_power, *granted_power, *extra_actor_power;
u32 *weighted_req_power;
u32 total_req_power, max_allocatable_power, total_weighted_req_power;
u32 total_granted_power, power_range;
int i, num_actors, total_weight, ret = 0;
int trip_max_desired_temperature = params->trip_max_desired_temperature;
mutex_lock(&tz->lock);
num_actors = 0;
total_weight = 0;
list_for_each_entry(instance, &tz->thermal_instances, tz_node) {
if ((instance->trip == trip_max_desired_temperature) &&
cdev_is_power_actor(instance->cdev)) {
num_actors++;
total_weight += instance->weight;
}
}
BUILD_BUG_ON(sizeof(*req_power) != sizeof(*max_power));
BUILD_BUG_ON(sizeof(*req_power) != sizeof(*granted_power));
BUILD_BUG_ON(sizeof(*req_power) != sizeof(*extra_actor_power));
BUILD_BUG_ON(sizeof(*req_power) != sizeof(*weighted_req_power));
req_power = kcalloc(num_actors * 5, sizeof(*req_power), GFP_KERNEL);
if (!req_power) {
ret = -ENOMEM;
goto unlock;
}
max_power = &req_power[num_actors];
granted_power = &req_power[2 * num_actors];
extra_actor_power = &req_power[3 * num_actors];
weighted_req_power = &req_power[4 * num_actors];
i = 0;
total_weighted_req_power = 0;
total_req_power = 0;
max_allocatable_power = 0;
list_for_each_entry(instance, &tz->thermal_instances, tz_node) {
int weight;
struct thermal_cooling_device *cdev = instance->cdev;
if (instance->trip != trip_max_desired_temperature)
continue;
if (!cdev_is_power_actor(cdev))
continue;
if (cdev->ops->get_requested_power(cdev, tz, &req_power[i]))
continue;
if (!total_weight)
weight = 1 << FRAC_BITS;
else
weight = instance->weight;
weighted_req_power[i] = frac_to_int(weight * req_power[i]);
if (power_actor_get_max_power(cdev, tz, &max_power[i]))
continue;
total_req_power += req_power[i];
max_allocatable_power += max_power[i];
total_weighted_req_power += weighted_req_power[i];
i++;
}
power_range = pid_controller(tz, current_temp, control_temp,
max_allocatable_power);
divvy_up_power(weighted_req_power, max_power, num_actors,
total_weighted_req_power, power_range, granted_power,
extra_actor_power);
total_granted_power = 0;
i = 0;
list_for_each_entry(instance, &tz->thermal_instances, tz_node) {
if (instance->trip != trip_max_desired_temperature)
continue;
if (!cdev_is_power_actor(instance->cdev))
continue;
power_actor_set_power(instance->cdev, instance,
granted_power[i]);
total_granted_power += granted_power[i];
i++;
}
trace_thermal_power_allocator(tz, req_power, total_req_power,
granted_power, total_granted_power,
num_actors, power_range,
max_allocatable_power, current_temp,
(s32)control_temp - (s32)current_temp);
kfree(req_power);
unlock:
mutex_unlock(&tz->lock);
return ret;
}
static int get_governor_trips(struct thermal_zone_device *tz,
struct power_allocator_params *params)
{
int i, ret, last_passive;
bool found_first_passive;
found_first_passive = false;
last_passive = -1;
ret = -EINVAL;
for (i = 0; i < tz->trips; i++) {
enum thermal_trip_type type;
ret = tz->ops->get_trip_type(tz, i, &type);
if (ret)
return ret;
if (!found_first_passive) {
if (type == THERMAL_TRIP_PASSIVE) {
params->trip_switch_on = i;
found_first_passive = true;
}
} else if (type == THERMAL_TRIP_PASSIVE) {
last_passive = i;
} else {
break;
}
}
if (last_passive != -1) {
params->trip_max_desired_temperature = last_passive;
ret = 0;
} else {
ret = -EINVAL;
}
return ret;
}
static void reset_pid_controller(struct power_allocator_params *params)
{
params->err_integral = 0;
params->prev_err = 0;
}
static void allow_maximum_power(struct thermal_zone_device *tz)
{
struct thermal_instance *instance;
struct power_allocator_params *params = tz->governor_data;
list_for_each_entry(instance, &tz->thermal_instances, tz_node) {
if ((instance->trip != params->trip_max_desired_temperature) ||
(!cdev_is_power_actor(instance->cdev)))
continue;
instance->target = 0;
instance->cdev->updated = false;
thermal_cdev_update(instance->cdev);
}
}
static int power_allocator_bind(struct thermal_zone_device *tz)
{
int ret;
struct power_allocator_params *params;
unsigned long switch_on_temp, control_temp;
u32 temperature_threshold;
if (!tz->tzp || !tz->tzp->sustainable_power) {
dev_err(&tz->device,
"power_allocator: missing sustainable_power\n");
return -EINVAL;
}
params = kzalloc(sizeof(*params), GFP_KERNEL);
if (!params)
return -ENOMEM;
ret = get_governor_trips(tz, params);
if (ret) {
dev_err(&tz->device,
"thermal zone %s has wrong trip setup for power allocator\n",
tz->type);
goto free;
}
ret = tz->ops->get_trip_temp(tz, params->trip_switch_on,
&switch_on_temp);
if (ret)
goto free;
ret = tz->ops->get_trip_temp(tz, params->trip_max_desired_temperature,
&control_temp);
if (ret)
goto free;
temperature_threshold = control_temp - switch_on_temp;
tz->tzp->k_po = tz->tzp->k_po ?:
int_to_frac(tz->tzp->sustainable_power) / temperature_threshold;
tz->tzp->k_pu = tz->tzp->k_pu ?:
int_to_frac(2 * tz->tzp->sustainable_power) /
temperature_threshold;
tz->tzp->k_i = tz->tzp->k_i ?: int_to_frac(10) / 1000;
reset_pid_controller(params);
tz->governor_data = params;
return 0;
free:
kfree(params);
return ret;
}
static void power_allocator_unbind(struct thermal_zone_device *tz)
{
dev_dbg(&tz->device, "Unbinding from thermal zone %d\n", tz->id);
kfree(tz->governor_data);
tz->governor_data = NULL;
}
static int power_allocator_throttle(struct thermal_zone_device *tz, int trip)
{
int ret;
unsigned long switch_on_temp, control_temp, current_temp;
struct power_allocator_params *params = tz->governor_data;
if (trip != params->trip_max_desired_temperature)
return 0;
ret = thermal_zone_get_temp(tz, &current_temp);
if (ret) {
dev_warn(&tz->device, "Failed to get temperature: %d\n", ret);
return ret;
}
ret = tz->ops->get_trip_temp(tz, params->trip_switch_on,
&switch_on_temp);
if (ret) {
dev_warn(&tz->device,
"Failed to get switch on temperature: %d\n", ret);
return ret;
}
if (current_temp < switch_on_temp) {
tz->passive = 0;
reset_pid_controller(params);
allow_maximum_power(tz);
return 0;
}
tz->passive = 1;
ret = tz->ops->get_trip_temp(tz, params->trip_max_desired_temperature,
&control_temp);
if (ret) {
dev_warn(&tz->device,
"Failed to get the maximum desired temperature: %d\n",
ret);
return ret;
}
return allocate_power(tz, current_temp, control_temp);
}
int thermal_gov_power_allocator_register(void)
{
return thermal_register_governor(&thermal_gov_power_allocator);
}
void thermal_gov_power_allocator_unregister(void)
{
thermal_unregister_governor(&thermal_gov_power_allocator);
}
