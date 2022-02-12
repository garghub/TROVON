static void rmi_f11_rel_pos_report(struct f11_data *f11, u8 n_finger)
{
struct rmi_2d_sensor *sensor = &f11->sensor;
struct f11_2d_data *data = &f11->data;
s8 x, y;
x = data->rel_pos[n_finger * RMI_F11_REL_BYTES];
y = data->rel_pos[n_finger * RMI_F11_REL_BYTES + 1];
rmi_2d_sensor_rel_report(sensor, x, y);
}
static void rmi_f11_abs_pos_process(struct f11_data *f11,
struct rmi_2d_sensor *sensor,
struct rmi_2d_sensor_abs_object *obj,
enum f11_finger_state finger_state,
u8 n_finger)
{
struct f11_2d_data *data = &f11->data;
u8 *pos_data = &data->abs_pos[n_finger * RMI_F11_ABS_BYTES];
int tool_type = MT_TOOL_FINGER;
switch (finger_state) {
case F11_PRESENT:
obj->type = RMI_2D_OBJECT_FINGER;
break;
default:
obj->type = RMI_2D_OBJECT_NONE;
}
obj->mt_tool = tool_type;
obj->x = (pos_data[0] << 4) | (pos_data[2] & 0x0F);
obj->y = (pos_data[1] << 4) | (pos_data[2] >> 4);
obj->z = pos_data[4];
obj->wx = pos_data[3] & 0x0f;
obj->wy = pos_data[3] >> 4;
rmi_2d_sensor_abs_process(sensor, obj, n_finger);
}
static inline u8 rmi_f11_parse_finger_state(const u8 *f_state, u8 n_finger)
{
return (f_state[n_finger / 4] >> (2 * (n_finger % 4))) &
FINGER_STATE_MASK;
}
static void rmi_f11_finger_handler(struct f11_data *f11,
struct rmi_2d_sensor *sensor,
unsigned long *irq_bits, int num_irq_regs)
{
const u8 *f_state = f11->data.f_state;
u8 finger_state;
u8 i;
int abs_bits = bitmap_and(f11->result_bits, irq_bits, f11->abs_mask,
num_irq_regs * 8);
int rel_bits = bitmap_and(f11->result_bits, irq_bits, f11->rel_mask,
num_irq_regs * 8);
for (i = 0; i < sensor->nbr_fingers; i++) {
finger_state = rmi_f11_parse_finger_state(f_state, i);
if (finger_state == F11_RESERVED) {
pr_err("Invalid finger state[%d]: 0x%02x", i,
finger_state);
continue;
}
if (abs_bits)
rmi_f11_abs_pos_process(f11, sensor, &sensor->objs[i],
finger_state, i);
if (rel_bits)
rmi_f11_rel_pos_report(f11, i);
}
if (abs_bits) {
if (sensor->kernel_tracking)
input_mt_assign_slots(sensor->input,
sensor->tracking_slots,
sensor->tracking_pos,
sensor->nbr_fingers,
sensor->dmax);
for (i = 0; i < sensor->nbr_fingers; i++) {
finger_state = rmi_f11_parse_finger_state(f_state, i);
if (finger_state == F11_RESERVED)
continue;
rmi_2d_sensor_abs_report(sensor, &sensor->objs[i], i);
}
input_mt_sync_frame(sensor->input);
}
}
static int f11_2d_construct_data(struct f11_data *f11)
{
struct rmi_2d_sensor *sensor = &f11->sensor;
struct f11_2d_sensor_queries *query = &f11->sens_query;
struct f11_2d_data *data = &f11->data;
int i;
sensor->nbr_fingers = (query->nr_fingers == 5 ? 10 :
query->nr_fingers + 1);
sensor->pkt_size = DIV_ROUND_UP(sensor->nbr_fingers, 4);
if (query->has_abs) {
sensor->pkt_size += (sensor->nbr_fingers * 5);
sensor->attn_size = sensor->pkt_size;
}
if (query->has_rel)
sensor->pkt_size += (sensor->nbr_fingers * 2);
if (query->query7_nonzero)
sensor->pkt_size += sizeof(u8);
if (query->query7_nonzero || query->query8_nonzero)
sensor->pkt_size += sizeof(u8);
if (query->has_pinch || query->has_flick || query->has_rotate) {
sensor->pkt_size += 3;
if (!query->has_flick)
sensor->pkt_size--;
if (!query->has_rotate)
sensor->pkt_size--;
}
if (query->has_touch_shapes)
sensor->pkt_size +=
DIV_ROUND_UP(query->nr_touch_shapes + 1, 8);
sensor->data_pkt = devm_kzalloc(&sensor->fn->dev, sensor->pkt_size,
GFP_KERNEL);
if (!sensor->data_pkt)
return -ENOMEM;
data->f_state = sensor->data_pkt;
i = DIV_ROUND_UP(sensor->nbr_fingers, 4);
if (query->has_abs) {
data->abs_pos = &sensor->data_pkt[i];
i += (sensor->nbr_fingers * RMI_F11_ABS_BYTES);
}
if (query->has_rel) {
data->rel_pos = &sensor->data_pkt[i];
i += (sensor->nbr_fingers * RMI_F11_REL_BYTES);
}
if (query->query7_nonzero) {
data->gest_1 = &sensor->data_pkt[i];
i++;
}
if (query->query7_nonzero || query->query8_nonzero) {
data->gest_2 = &sensor->data_pkt[i];
i++;
}
if (query->has_pinch) {
data->pinch = &sensor->data_pkt[i];
i++;
}
if (query->has_flick) {
if (query->has_pinch) {
data->flick = data->pinch;
i += 2;
} else {
data->flick = &sensor->data_pkt[i];
i += 3;
}
}
if (query->has_rotate) {
if (query->has_flick) {
data->rotate = data->flick + 1;
} else {
data->rotate = &sensor->data_pkt[i];
i += 2;
}
}
if (query->has_touch_shapes)
data->shapes = &sensor->data_pkt[i];
return 0;
}
static int f11_read_control_regs(struct rmi_function *fn,
struct f11_2d_ctrl *ctrl, u16 ctrl_base_addr) {
struct rmi_device *rmi_dev = fn->rmi_dev;
int error = 0;
ctrl->ctrl0_11_address = ctrl_base_addr;
error = rmi_read_block(rmi_dev, ctrl_base_addr, ctrl->ctrl0_11,
RMI_F11_CTRL_REG_COUNT);
if (error < 0) {
dev_err(&fn->dev, "Failed to read ctrl0, code: %d.\n", error);
return error;
}
return 0;
}
static int f11_write_control_regs(struct rmi_function *fn,
struct f11_2d_sensor_queries *query,
struct f11_2d_ctrl *ctrl,
u16 ctrl_base_addr)
{
struct rmi_device *rmi_dev = fn->rmi_dev;
int error;
error = rmi_write_block(rmi_dev, ctrl_base_addr, ctrl->ctrl0_11,
RMI_F11_CTRL_REG_COUNT);
if (error < 0)
return error;
return 0;
}
static int rmi_f11_get_query_parameters(struct rmi_device *rmi_dev,
struct f11_data *f11,
struct f11_2d_sensor_queries *sensor_query,
u16 query_base_addr)
{
int query_size;
int rc;
u8 query_buf[RMI_F11_QUERY_SIZE];
bool has_query36 = false;
rc = rmi_read_block(rmi_dev, query_base_addr, query_buf,
RMI_F11_QUERY_SIZE);
if (rc < 0)
return rc;
sensor_query->nr_fingers = query_buf[0] & RMI_F11_NR_FINGERS_MASK;
sensor_query->has_rel = !!(query_buf[0] & RMI_F11_HAS_REL);
sensor_query->has_abs = !!(query_buf[0] & RMI_F11_HAS_ABS);
sensor_query->has_gestures = !!(query_buf[0] & RMI_F11_HAS_GESTURES);
sensor_query->has_sensitivity_adjust =
!!(query_buf[0] & RMI_F11_HAS_SENSITIVITY_ADJ);
sensor_query->configurable = !!(query_buf[0] & RMI_F11_CONFIGURABLE);
sensor_query->nr_x_electrodes =
query_buf[1] & RMI_F11_NR_ELECTRODES_MASK;
sensor_query->nr_y_electrodes =
query_buf[2] & RMI_F11_NR_ELECTRODES_MASK;
sensor_query->max_electrodes =
query_buf[3] & RMI_F11_NR_ELECTRODES_MASK;
query_size = RMI_F11_QUERY_SIZE;
if (sensor_query->has_abs) {
rc = rmi_read(rmi_dev, query_base_addr + query_size, query_buf);
if (rc < 0)
return rc;
sensor_query->abs_data_size =
query_buf[0] & RMI_F11_ABS_DATA_SIZE_MASK;
sensor_query->has_anchored_finger =
!!(query_buf[0] & RMI_F11_HAS_ANCHORED_FINGER);
sensor_query->has_adj_hyst =
!!(query_buf[0] & RMI_F11_HAS_ADJ_HYST);
sensor_query->has_dribble =
!!(query_buf[0] & RMI_F11_HAS_DRIBBLE);
sensor_query->has_bending_correction =
!!(query_buf[0] & RMI_F11_HAS_BENDING_CORRECTION);
sensor_query->has_large_object_suppression =
!!(query_buf[0] & RMI_F11_HAS_LARGE_OBJECT_SUPPRESSION);
sensor_query->has_jitter_filter =
!!(query_buf[0] & RMI_F11_HAS_JITTER_FILTER);
query_size++;
}
if (sensor_query->has_rel) {
rc = rmi_read(rmi_dev, query_base_addr + query_size,
&sensor_query->f11_2d_query6);
if (rc < 0)
return rc;
query_size++;
}
if (sensor_query->has_gestures) {
rc = rmi_read_block(rmi_dev, query_base_addr + query_size,
query_buf, RMI_F11_QUERY_GESTURE_SIZE);
if (rc < 0)
return rc;
sensor_query->has_single_tap =
!!(query_buf[0] & RMI_F11_HAS_SINGLE_TAP);
sensor_query->has_tap_n_hold =
!!(query_buf[0] & RMI_F11_HAS_TAP_AND_HOLD);
sensor_query->has_double_tap =
!!(query_buf[0] & RMI_F11_HAS_DOUBLE_TAP);
sensor_query->has_early_tap =
!!(query_buf[0] & RMI_F11_HAS_EARLY_TAP);
sensor_query->has_flick =
!!(query_buf[0] & RMI_F11_HAS_FLICK);
sensor_query->has_press =
!!(query_buf[0] & RMI_F11_HAS_PRESS);
sensor_query->has_pinch =
!!(query_buf[0] & RMI_F11_HAS_PINCH);
sensor_query->has_chiral =
!!(query_buf[0] & RMI_F11_HAS_CHIRAL);
sensor_query->has_palm_det =
!!(query_buf[1] & RMI_F11_HAS_PALM_DET);
sensor_query->has_rotate =
!!(query_buf[1] & RMI_F11_HAS_ROTATE);
sensor_query->has_touch_shapes =
!!(query_buf[1] & RMI_F11_HAS_TOUCH_SHAPES);
sensor_query->has_scroll_zones =
!!(query_buf[1] & RMI_F11_HAS_SCROLL_ZONES);
sensor_query->has_individual_scroll_zones =
!!(query_buf[1] & RMI_F11_HAS_INDIVIDUAL_SCROLL_ZONES);
sensor_query->has_mf_scroll =
!!(query_buf[1] & RMI_F11_HAS_MF_SCROLL);
sensor_query->has_mf_edge_motion =
!!(query_buf[1] & RMI_F11_HAS_MF_EDGE_MOTION);
sensor_query->has_mf_scroll_inertia =
!!(query_buf[1] & RMI_F11_HAS_MF_SCROLL_INERTIA);
sensor_query->query7_nonzero = !!(query_buf[0]);
sensor_query->query8_nonzero = !!(query_buf[1]);
query_size += 2;
}
if (f11->has_query9) {
rc = rmi_read(rmi_dev, query_base_addr + query_size, query_buf);
if (rc < 0)
return rc;
sensor_query->has_pen =
!!(query_buf[0] & RMI_F11_HAS_PEN);
sensor_query->has_proximity =
!!(query_buf[0] & RMI_F11_HAS_PROXIMITY);
sensor_query->has_palm_det_sensitivity =
!!(query_buf[0] & RMI_F11_HAS_PALM_DET_SENSITIVITY);
sensor_query->has_suppress_on_palm_detect =
!!(query_buf[0] & RMI_F11_HAS_SUPPRESS_ON_PALM_DETECT);
sensor_query->has_two_pen_thresholds =
!!(query_buf[0] & RMI_F11_HAS_TWO_PEN_THRESHOLDS);
sensor_query->has_contact_geometry =
!!(query_buf[0] & RMI_F11_HAS_CONTACT_GEOMETRY);
sensor_query->has_pen_hover_discrimination =
!!(query_buf[0] & RMI_F11_HAS_PEN_HOVER_DISCRIMINATION);
sensor_query->has_pen_filters =
!!(query_buf[0] & RMI_F11_HAS_PEN_FILTERS);
query_size++;
}
if (sensor_query->has_touch_shapes) {
rc = rmi_read(rmi_dev, query_base_addr + query_size, query_buf);
if (rc < 0)
return rc;
sensor_query->nr_touch_shapes = query_buf[0] &
RMI_F11_NR_TOUCH_SHAPES_MASK;
query_size++;
}
if (f11->has_query11) {
rc = rmi_read(rmi_dev, query_base_addr + query_size, query_buf);
if (rc < 0)
return rc;
sensor_query->has_z_tuning =
!!(query_buf[0] & RMI_F11_HAS_Z_TUNING);
sensor_query->has_algorithm_selection =
!!(query_buf[0] & RMI_F11_HAS_ALGORITHM_SELECTION);
sensor_query->has_w_tuning =
!!(query_buf[0] & RMI_F11_HAS_W_TUNING);
sensor_query->has_pitch_info =
!!(query_buf[0] & RMI_F11_HAS_PITCH_INFO);
sensor_query->has_finger_size =
!!(query_buf[0] & RMI_F11_HAS_FINGER_SIZE);
sensor_query->has_segmentation_aggressiveness =
!!(query_buf[0] &
RMI_F11_HAS_SEGMENTATION_AGGRESSIVENESS);
sensor_query->has_XY_clip =
!!(query_buf[0] & RMI_F11_HAS_XY_CLIP);
sensor_query->has_drumming_filter =
!!(query_buf[0] & RMI_F11_HAS_DRUMMING_FILTER);
query_size++;
}
if (f11->has_query12) {
rc = rmi_read(rmi_dev, query_base_addr + query_size, query_buf);
if (rc < 0)
return rc;
sensor_query->has_gapless_finger =
!!(query_buf[0] & RMI_F11_HAS_GAPLESS_FINGER);
sensor_query->has_gapless_finger_tuning =
!!(query_buf[0] & RMI_F11_HAS_GAPLESS_FINGER_TUNING);
sensor_query->has_8bit_w =
!!(query_buf[0] & RMI_F11_HAS_8BIT_W);
sensor_query->has_adjustable_mapping =
!!(query_buf[0] & RMI_F11_HAS_ADJUSTABLE_MAPPING);
sensor_query->has_info2 =
!!(query_buf[0] & RMI_F11_HAS_INFO2);
sensor_query->has_physical_props =
!!(query_buf[0] & RMI_F11_HAS_PHYSICAL_PROPS);
sensor_query->has_finger_limit =
!!(query_buf[0] & RMI_F11_HAS_FINGER_LIMIT);
sensor_query->has_linear_coeff_2 =
!!(query_buf[0] & RMI_F11_HAS_LINEAR_COEFF);
query_size++;
}
if (sensor_query->has_jitter_filter) {
rc = rmi_read(rmi_dev, query_base_addr + query_size, query_buf);
if (rc < 0)
return rc;
sensor_query->jitter_window_size = query_buf[0] &
RMI_F11_JITTER_WINDOW_MASK;
sensor_query->jitter_filter_type = (query_buf[0] &
RMI_F11_JITTER_FILTER_MASK) >>
RMI_F11_JITTER_FILTER_SHIFT;
query_size++;
}
if (sensor_query->has_info2) {
rc = rmi_read(rmi_dev, query_base_addr + query_size, query_buf);
if (rc < 0)
return rc;
sensor_query->light_control =
query_buf[0] & RMI_F11_LIGHT_CONTROL_MASK;
sensor_query->is_clear =
!!(query_buf[0] & RMI_F11_IS_CLEAR);
sensor_query->clickpad_props =
(query_buf[0] & RMI_F11_CLICKPAD_PROPS_MASK) >>
RMI_F11_CLICKPAD_PROPS_SHIFT;
sensor_query->mouse_buttons =
(query_buf[0] & RMI_F11_MOUSE_BUTTONS_MASK) >>
RMI_F11_MOUSE_BUTTONS_SHIFT;
sensor_query->has_advanced_gestures =
!!(query_buf[0] & RMI_F11_HAS_ADVANCED_GESTURES);
query_size++;
}
if (sensor_query->has_physical_props) {
rc = rmi_read_block(rmi_dev, query_base_addr
+ query_size, query_buf, 4);
if (rc < 0)
return rc;
sensor_query->x_sensor_size_mm =
(query_buf[0] | (query_buf[1] << 8)) / 10;
sensor_query->y_sensor_size_mm =
(query_buf[2] | (query_buf[3] << 8)) / 10;
query_size += 12;
}
if (f11->has_query27)
++query_size;
if (f11->has_query28) {
rc = rmi_read(rmi_dev, query_base_addr + query_size,
query_buf);
if (rc < 0)
return rc;
has_query36 = !!(query_buf[0] & BIT(6));
}
if (has_query36) {
query_size += 2;
rc = rmi_read(rmi_dev, query_base_addr + query_size,
query_buf);
if (rc < 0)
return rc;
if (!!(query_buf[0] & BIT(5)))
f11->has_acm = true;
}
return query_size;
}
static int rmi_f11_initialize(struct rmi_function *fn)
{
struct rmi_device *rmi_dev = fn->rmi_dev;
struct f11_data *f11;
struct f11_2d_ctrl *ctrl;
u8 query_offset;
u16 query_base_addr;
u16 control_base_addr;
u16 max_x_pos, max_y_pos;
int rc;
const struct rmi_device_platform_data *pdata =
rmi_get_platform_data(rmi_dev);
struct rmi_driver_data *drvdata = dev_get_drvdata(&rmi_dev->dev);
struct rmi_2d_sensor *sensor;
u8 buf;
int mask_size;
rmi_dbg(RMI_DEBUG_FN, &fn->dev, "Initializing F11 values.\n");
mask_size = BITS_TO_LONGS(drvdata->irq_count) * sizeof(unsigned long);
f11 = devm_kzalloc(&fn->dev, sizeof(struct f11_data) + mask_size * 3,
GFP_KERNEL);
if (!f11)
return -ENOMEM;
if (fn->dev.of_node) {
rc = rmi_2d_sensor_of_probe(&fn->dev, &f11->sensor_pdata);
if (rc)
return rc;
} else if (pdata->sensor_pdata) {
f11->sensor_pdata = *pdata->sensor_pdata;
}
f11->rezero_wait_ms = f11->sensor_pdata.rezero_wait;
f11->abs_mask = (unsigned long *)((char *)f11
+ sizeof(struct f11_data));
f11->rel_mask = (unsigned long *)((char *)f11
+ sizeof(struct f11_data) + mask_size);
f11->result_bits = (unsigned long *)((char *)f11
+ sizeof(struct f11_data) + mask_size * 2);
set_bit(fn->irq_pos, f11->abs_mask);
set_bit(fn->irq_pos + 1, f11->rel_mask);
query_base_addr = fn->fd.query_base_addr;
control_base_addr = fn->fd.control_base_addr;
rc = rmi_read(rmi_dev, query_base_addr, &buf);
if (rc < 0)
return rc;
f11->has_query9 = !!(buf & RMI_F11_HAS_QUERY9);
f11->has_query11 = !!(buf & RMI_F11_HAS_QUERY11);
f11->has_query12 = !!(buf & RMI_F11_HAS_QUERY12);
f11->has_query27 = !!(buf & RMI_F11_HAS_QUERY27);
f11->has_query28 = !!(buf & RMI_F11_HAS_QUERY28);
query_offset = (query_base_addr + 1);
sensor = &f11->sensor;
sensor->fn = fn;
rc = rmi_f11_get_query_parameters(rmi_dev, f11,
&f11->sens_query, query_offset);
if (rc < 0)
return rc;
query_offset += rc;
rc = f11_read_control_regs(fn, &f11->dev_controls,
control_base_addr);
if (rc < 0) {
dev_err(&fn->dev,
"Failed to read F11 control params.\n");
return rc;
}
if (f11->sens_query.has_info2) {
if (f11->sens_query.is_clear)
f11->sensor.sensor_type = rmi_sensor_touchscreen;
else
f11->sensor.sensor_type = rmi_sensor_touchpad;
}
sensor->report_abs = f11->sens_query.has_abs;
sensor->axis_align =
f11->sensor_pdata.axis_align;
sensor->topbuttonpad = f11->sensor_pdata.topbuttonpad;
sensor->kernel_tracking = f11->sensor_pdata.kernel_tracking;
sensor->dmax = f11->sensor_pdata.dmax;
if (f11->sens_query.has_physical_props) {
sensor->x_mm = f11->sens_query.x_sensor_size_mm;
sensor->y_mm = f11->sens_query.y_sensor_size_mm;
} else {
sensor->x_mm = f11->sensor_pdata.x_mm;
sensor->y_mm = f11->sensor_pdata.y_mm;
}
if (sensor->sensor_type == rmi_sensor_default)
sensor->sensor_type =
f11->sensor_pdata.sensor_type;
sensor->report_abs = sensor->report_abs
&& !(f11->sensor_pdata.disable_report_mask
& RMI_F11_DISABLE_ABS_REPORT);
if (!sensor->report_abs)
sensor->report_rel = f11->sens_query.has_rel;
rc = rmi_read_block(rmi_dev,
control_base_addr + F11_CTRL_SENSOR_MAX_X_POS_OFFSET,
(u8 *)&max_x_pos, sizeof(max_x_pos));
if (rc < 0)
return rc;
rc = rmi_read_block(rmi_dev,
control_base_addr + F11_CTRL_SENSOR_MAX_Y_POS_OFFSET,
(u8 *)&max_y_pos, sizeof(max_y_pos));
if (rc < 0)
return rc;
sensor->max_x = max_x_pos;
sensor->max_y = max_y_pos;
rc = f11_2d_construct_data(f11);
if (rc < 0)
return rc;
if (f11->has_acm)
f11->sensor.attn_size += f11->sensor.nbr_fingers * 2;
sensor->tracking_pos = devm_kzalloc(&fn->dev,
sizeof(struct input_mt_pos) * sensor->nbr_fingers,
GFP_KERNEL);
sensor->tracking_slots = devm_kzalloc(&fn->dev,
sizeof(int) * sensor->nbr_fingers, GFP_KERNEL);
sensor->objs = devm_kzalloc(&fn->dev,
sizeof(struct rmi_2d_sensor_abs_object)
* sensor->nbr_fingers, GFP_KERNEL);
if (!sensor->tracking_pos || !sensor->tracking_slots || !sensor->objs)
return -ENOMEM;
ctrl = &f11->dev_controls;
if (sensor->axis_align.delta_x_threshold)
ctrl->ctrl0_11[RMI_F11_DELTA_X_THRESHOLD] =
sensor->axis_align.delta_x_threshold;
if (sensor->axis_align.delta_y_threshold)
ctrl->ctrl0_11[RMI_F11_DELTA_Y_THRESHOLD] =
sensor->axis_align.delta_y_threshold;
if (f11->sens_query.has_dribble)
ctrl->ctrl0_11[0] = ctrl->ctrl0_11[0] & ~BIT(6);
if (f11->sens_query.has_palm_det)
ctrl->ctrl0_11[11] = ctrl->ctrl0_11[11] & ~BIT(0);
rc = f11_write_control_regs(fn, &f11->sens_query,
&f11->dev_controls, fn->fd.query_base_addr);
if (rc)
dev_warn(&fn->dev, "Failed to write control registers\n");
mutex_init(&f11->dev_controls_mutex);
dev_set_drvdata(&fn->dev, f11);
return 0;
}
static int rmi_f11_config(struct rmi_function *fn)
{
struct f11_data *f11 = dev_get_drvdata(&fn->dev);
struct rmi_driver *drv = fn->rmi_dev->driver;
struct rmi_2d_sensor *sensor = &f11->sensor;
int rc;
if (!sensor->report_abs)
drv->clear_irq_bits(fn->rmi_dev, f11->abs_mask);
else
drv->set_irq_bits(fn->rmi_dev, f11->abs_mask);
if (!sensor->report_rel)
drv->clear_irq_bits(fn->rmi_dev, f11->rel_mask);
else
drv->set_irq_bits(fn->rmi_dev, f11->rel_mask);
rc = f11_write_control_regs(fn, &f11->sens_query,
&f11->dev_controls, fn->fd.query_base_addr);
if (rc < 0)
return rc;
return 0;
}
static int rmi_f11_attention(struct rmi_function *fn, unsigned long *irq_bits)
{
struct rmi_device *rmi_dev = fn->rmi_dev;
struct rmi_driver_data *drvdata = dev_get_drvdata(&rmi_dev->dev);
struct f11_data *f11 = dev_get_drvdata(&fn->dev);
u16 data_base_addr = fn->fd.data_base_addr;
int error;
if (rmi_dev->xport->attn_data) {
memcpy(f11->sensor.data_pkt, rmi_dev->xport->attn_data,
f11->sensor.attn_size);
rmi_dev->xport->attn_data += f11->sensor.attn_size;
rmi_dev->xport->attn_size -= f11->sensor.attn_size;
} else {
error = rmi_read_block(rmi_dev,
data_base_addr, f11->sensor.data_pkt,
f11->sensor.pkt_size);
if (error < 0)
return error;
}
rmi_f11_finger_handler(f11, &f11->sensor, irq_bits,
drvdata->num_of_irq_regs);
return 0;
}
static int rmi_f11_resume(struct rmi_function *fn)
{
struct f11_data *f11 = dev_get_drvdata(&fn->dev);
int error;
rmi_dbg(RMI_DEBUG_FN, &fn->dev, "Resuming...\n");
if (!f11->rezero_wait_ms)
return 0;
mdelay(f11->rezero_wait_ms);
error = rmi_write(fn->rmi_dev, fn->fd.command_base_addr,
RMI_F11_REZERO);
if (error) {
dev_err(&fn->dev,
"%s: failed to issue rezero command, error = %d.",
__func__, error);
return error;
}
return 0;
}
static int rmi_f11_probe(struct rmi_function *fn)
{
int error;
struct f11_data *f11;
error = rmi_f11_initialize(fn);
if (error)
return error;
f11 = dev_get_drvdata(&fn->dev);
error = rmi_2d_sensor_configure_input(fn, &f11->sensor);
if (error)
return error;
return 0;
}
