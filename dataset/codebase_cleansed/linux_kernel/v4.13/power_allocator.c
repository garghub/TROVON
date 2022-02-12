static inline s64 mul_frac(s64 x, s64 y)
{
return (x * y) >> FRAC_BITS;
}
static inline s64 div_frac(s64 x, s64 y)
{
return div_s64(x << FRAC_BITS, y);
}
static u32 estimate_sustainable_power(struct thermal_zone_device *tz)
{
u32 sustainable_power = 0;
struct thermal_instance *instance;
struct power_allocator_params *params = tz->governor_data;
list_for_each_entry(instance, &tz->thermal_instances, tz_node) {
struct thermal_cooling_device *cdev = instance->cdev;
u32 min_power;
if (instance->trip != params->trip_max_desired_temperature)
continue;
if (power_actor_get_min_power(cdev, tz, &min_power))
continue;
sustainable_power += min_power;
}
return sustainable_power;
}
static void estimate_pid_constants(struct thermal_zone_device *tz,
u32 sustainable_power, int trip_switch_on,
int control_temp, bool force)
{
int ret;
int switch_on_temp;
u32 temperature_threshold;
ret = tz->ops->get_trip_temp(tz, trip_switch_on, &switch_on_temp);
if (ret)
switch_on_temp = 0;
temperature_threshold = control_temp - switch_on_temp;
if (!temperature_threshold)
return;
if (!tz->tzp->k_po || force)
tz->tzp->k_po = int_to_frac(sustainable_power) /
temperature_threshold;
if (!tz->tzp->k_pu || force)
tz->tzp->k_pu = int_to_frac(2 * sustainable_power) /
temperature_threshold;
if (!tz->tzp->k_i || force)
tz->tzp->k_i = int_to_frac(10) / 1000;
}
static u32 pid_controller(struct thermal_zone_device *tz,
int control_temp,
u32 max_allocatable_power)
{
s64 p, i, d, power_range;
s32 err, max_power_frac;
u32 sustainable_power;
struct power_allocator_params *params = tz->governor_data;
max_power_frac = int_to_frac(max_allocatable_power);
if (tz->tzp->sustainable_power) {
sustainable_power = tz->tzp->sustainable_power;
} else {
sustainable_power = estimate_sustainable_power(tz);
estimate_pid_constants(tz, sustainable_power,
params->trip_switch_on, control_temp,
true);
}
err = control_temp - tz->temperature;
err = int_to_frac(err);
p = mul_frac(err < 0 ? tz->tzp->k_po : tz->tzp->k_pu, err);
i = mul_frac(tz->tzp->k_i, params->err_integral);
if (err < int_to_frac(tz->tzp->integral_cutoff)) {
s64 i_next = i + mul_frac(tz->tzp->k_i, err);
if (abs(i_next) < max_power_frac) {
i = i_next;
params->err_integral += err;
}
}
d = mul_frac(tz->tzp->k_d, err - params->prev_err);
d = div_frac(d, tz->passive_delay);
params->prev_err = err;
power_range = p + i + d;
power_range = sustainable_power + frac_to_int(power_range);
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
u64 req_range = (u64)req_power[i] * power_range;
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
int control_temp)
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
if (!num_actors) {
ret = -ENODEV;
goto unlock;
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
power_range = pid_controller(tz, control_temp, max_allocatable_power);
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
max_allocatable_power, tz->temperature,
control_temp - tz->temperature);
kfree(req_power);
unlock:
mutex_unlock(&tz->lock);
return ret;
}
static void get_governor_trips(struct thermal_zone_device *tz,
struct power_allocator_params *params)
{
int i, last_active, last_passive;
bool found_first_passive;
found_first_passive = false;
last_active = INVALID_TRIP;
last_passive = INVALID_TRIP;
for (i = 0; i < tz->trips; i++) {
enum thermal_trip_type type;
int ret;
ret = tz->ops->get_trip_type(tz, i, &type);
if (ret) {
dev_warn(&tz->device,
"Failed to get trip point %d type: %d\n", i,
ret);
continue;
}
if (type == THERMAL_TRIP_PASSIVE) {
if (!found_first_passive) {
params->trip_switch_on = i;
found_first_passive = true;
} else {
last_passive = i;
}
} else if (type == THERMAL_TRIP_ACTIVE) {
last_active = i;
} else {
break;
}
}
if (last_passive != INVALID_TRIP) {
params->trip_max_desired_temperature = last_passive;
} else if (found_first_passive) {
params->trip_max_desired_temperature = params->trip_switch_on;
params->trip_switch_on = INVALID_TRIP;
} else {
params->trip_switch_on = INVALID_TRIP;
params->trip_max_desired_temperature = last_active;
}
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
mutex_lock(&instance->cdev->lock);
instance->cdev->updated = false;
mutex_unlock(&instance->cdev->lock);
thermal_cdev_update(instance->cdev);
}
}
static int power_allocator_bind(struct thermal_zone_device *tz)
{
int ret;
struct power_allocator_params *params;
int control_temp;
params = kzalloc(sizeof(*params), GFP_KERNEL);
if (!params)
return -ENOMEM;
if (!tz->tzp) {
tz->tzp = kzalloc(sizeof(*tz->tzp), GFP_KERNEL);
if (!tz->tzp) {
ret = -ENOMEM;
goto free_params;
}
params->allocated_tzp = true;
}
if (!tz->tzp->sustainable_power)
dev_warn(&tz->device, "power_allocator: sustainable_power will be estimated\n");
get_governor_trips(tz, params);
if (tz->trips > 0) {
ret = tz->ops->get_trip_temp(tz,
params->trip_max_desired_temperature,
&control_temp);
if (!ret)
estimate_pid_constants(tz, tz->tzp->sustainable_power,
params->trip_switch_on,
control_temp, false);
}
reset_pid_controller(params);
tz->governor_data = params;
return 0;
free_params:
kfree(params);
return ret;
}
static void power_allocator_unbind(struct thermal_zone_device *tz)
{
struct power_allocator_params *params = tz->governor_data;
dev_dbg(&tz->device, "Unbinding from thermal zone %d\n", tz->id);
if (params->allocated_tzp) {
kfree(tz->tzp);
tz->tzp = NULL;
}
kfree(tz->governor_data);
tz->governor_data = NULL;
}
static int power_allocator_throttle(struct thermal_zone_device *tz, int trip)
{
int ret;
int switch_on_temp, control_temp;
struct power_allocator_params *params = tz->governor_data;
if (trip != params->trip_max_desired_temperature)
return 0;
ret = tz->ops->get_trip_temp(tz, params->trip_switch_on,
&switch_on_temp);
if (!ret && (tz->temperature < switch_on_temp)) {
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
return allocate_power(tz, control_temp);
}
int thermal_gov_power_allocator_register(void)
{
return thermal_register_governor(&thermal_gov_power_allocator);
}
void thermal_gov_power_allocator_unregister(void)
{
thermal_unregister_governor(&thermal_gov_power_allocator);
}
