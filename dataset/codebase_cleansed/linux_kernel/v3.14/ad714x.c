static void ad714x_use_com_int(struct ad714x_chip *ad714x,
int start_stage, int end_stage)
{
unsigned short data;
unsigned short mask;
mask = ((1 << (end_stage + 1)) - 1) - ((1 << start_stage) - 1);
ad714x->read(ad714x, STG_COM_INT_EN_REG, &data, 1);
data |= 1 << end_stage;
ad714x->write(ad714x, STG_COM_INT_EN_REG, data);
ad714x->read(ad714x, STG_HIGH_INT_EN_REG, &data, 1);
data &= ~mask;
ad714x->write(ad714x, STG_HIGH_INT_EN_REG, data);
}
static void ad714x_use_thr_int(struct ad714x_chip *ad714x,
int start_stage, int end_stage)
{
unsigned short data;
unsigned short mask;
mask = ((1 << (end_stage + 1)) - 1) - ((1 << start_stage) - 1);
ad714x->read(ad714x, STG_COM_INT_EN_REG, &data, 1);
data &= ~(1 << end_stage);
ad714x->write(ad714x, STG_COM_INT_EN_REG, data);
ad714x->read(ad714x, STG_HIGH_INT_EN_REG, &data, 1);
data |= mask;
ad714x->write(ad714x, STG_HIGH_INT_EN_REG, data);
}
static int ad714x_cal_highest_stage(struct ad714x_chip *ad714x,
int start_stage, int end_stage)
{
int max_res = 0;
int max_idx = 0;
int i;
for (i = start_stage; i <= end_stage; i++) {
if (ad714x->sensor_val[i] > max_res) {
max_res = ad714x->sensor_val[i];
max_idx = i;
}
}
return max_idx;
}
static int ad714x_cal_abs_pos(struct ad714x_chip *ad714x,
int start_stage, int end_stage,
int highest_stage, int max_coord)
{
int a_param, b_param;
if (highest_stage == start_stage) {
a_param = ad714x->sensor_val[start_stage + 1];
b_param = ad714x->sensor_val[start_stage] +
ad714x->sensor_val[start_stage + 1];
} else if (highest_stage == end_stage) {
a_param = ad714x->sensor_val[end_stage] *
(end_stage - start_stage) +
ad714x->sensor_val[end_stage - 1] *
(end_stage - start_stage - 1);
b_param = ad714x->sensor_val[end_stage] +
ad714x->sensor_val[end_stage - 1];
} else {
a_param = ad714x->sensor_val[highest_stage] *
(highest_stage - start_stage) +
ad714x->sensor_val[highest_stage - 1] *
(highest_stage - start_stage - 1) +
ad714x->sensor_val[highest_stage + 1] *
(highest_stage - start_stage + 1);
b_param = ad714x->sensor_val[highest_stage] +
ad714x->sensor_val[highest_stage - 1] +
ad714x->sensor_val[highest_stage + 1];
}
return (max_coord / (end_stage - start_stage)) * a_param / b_param;
}
static void ad714x_button_state_machine(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_button_plat *hw = &ad714x->hw->button[idx];
struct ad714x_button_drv *sw = &ad714x->sw->button[idx];
switch (sw->state) {
case IDLE:
if (((ad714x->h_state & hw->h_mask) == hw->h_mask) &&
((ad714x->l_state & hw->l_mask) == hw->l_mask)) {
dev_dbg(ad714x->dev, "button %d touched\n", idx);
input_report_key(sw->input, hw->keycode, 1);
input_sync(sw->input);
sw->state = ACTIVE;
}
break;
case ACTIVE:
if (((ad714x->h_state & hw->h_mask) != hw->h_mask) ||
((ad714x->l_state & hw->l_mask) != hw->l_mask)) {
dev_dbg(ad714x->dev, "button %d released\n", idx);
input_report_key(sw->input, hw->keycode, 0);
input_sync(sw->input);
sw->state = IDLE;
}
break;
default:
break;
}
}
static void ad714x_slider_cal_sensor_val(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_slider_plat *hw = &ad714x->hw->slider[idx];
int i;
ad714x->read(ad714x, CDC_RESULT_S0 + hw->start_stage,
&ad714x->adc_reg[hw->start_stage],
hw->end_stage - hw->start_stage + 1);
for (i = hw->start_stage; i <= hw->end_stage; i++) {
ad714x->read(ad714x, STAGE0_AMBIENT + i * PER_STAGE_REG_NUM,
&ad714x->amb_reg[i], 1);
ad714x->sensor_val[i] =
abs(ad714x->adc_reg[i] - ad714x->amb_reg[i]);
}
}
static void ad714x_slider_cal_highest_stage(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_slider_plat *hw = &ad714x->hw->slider[idx];
struct ad714x_slider_drv *sw = &ad714x->sw->slider[idx];
sw->highest_stage = ad714x_cal_highest_stage(ad714x, hw->start_stage,
hw->end_stage);
dev_dbg(ad714x->dev, "slider %d highest_stage:%d\n", idx,
sw->highest_stage);
}
static void ad714x_slider_cal_abs_pos(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_slider_plat *hw = &ad714x->hw->slider[idx];
struct ad714x_slider_drv *sw = &ad714x->sw->slider[idx];
sw->abs_pos = ad714x_cal_abs_pos(ad714x, hw->start_stage, hw->end_stage,
sw->highest_stage, hw->max_coord);
dev_dbg(ad714x->dev, "slider %d absolute position:%d\n", idx,
sw->abs_pos);
}
static void ad714x_slider_cal_flt_pos(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_slider_drv *sw = &ad714x->sw->slider[idx];
sw->flt_pos = (sw->flt_pos * (10 - 4) +
sw->abs_pos * 4)/10;
dev_dbg(ad714x->dev, "slider %d filter position:%d\n", idx,
sw->flt_pos);
}
static void ad714x_slider_use_com_int(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_slider_plat *hw = &ad714x->hw->slider[idx];
ad714x_use_com_int(ad714x, hw->start_stage, hw->end_stage);
}
static void ad714x_slider_use_thr_int(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_slider_plat *hw = &ad714x->hw->slider[idx];
ad714x_use_thr_int(ad714x, hw->start_stage, hw->end_stage);
}
static void ad714x_slider_state_machine(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_slider_plat *hw = &ad714x->hw->slider[idx];
struct ad714x_slider_drv *sw = &ad714x->sw->slider[idx];
unsigned short h_state, c_state;
unsigned short mask;
mask = ((1 << (hw->end_stage + 1)) - 1) - ((1 << hw->start_stage) - 1);
h_state = ad714x->h_state & mask;
c_state = ad714x->c_state & mask;
switch (sw->state) {
case IDLE:
if (h_state) {
sw->state = JITTER;
ad714x_slider_use_com_int(ad714x, idx);
dev_dbg(ad714x->dev, "slider %d touched\n", idx);
}
break;
case JITTER:
if (c_state == mask) {
ad714x_slider_cal_sensor_val(ad714x, idx);
ad714x_slider_cal_highest_stage(ad714x, idx);
ad714x_slider_cal_abs_pos(ad714x, idx);
sw->flt_pos = sw->abs_pos;
sw->state = ACTIVE;
}
break;
case ACTIVE:
if (c_state == mask) {
if (h_state) {
ad714x_slider_cal_sensor_val(ad714x, idx);
ad714x_slider_cal_highest_stage(ad714x, idx);
ad714x_slider_cal_abs_pos(ad714x, idx);
ad714x_slider_cal_flt_pos(ad714x, idx);
input_report_abs(sw->input, ABS_X, sw->flt_pos);
input_report_key(sw->input, BTN_TOUCH, 1);
} else {
ad714x_slider_use_thr_int(ad714x, idx);
sw->state = IDLE;
input_report_key(sw->input, BTN_TOUCH, 0);
dev_dbg(ad714x->dev, "slider %d released\n",
idx);
}
input_sync(sw->input);
}
break;
default:
break;
}
}
static void ad714x_wheel_cal_highest_stage(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_wheel_plat *hw = &ad714x->hw->wheel[idx];
struct ad714x_wheel_drv *sw = &ad714x->sw->wheel[idx];
sw->pre_highest_stage = sw->highest_stage;
sw->highest_stage = ad714x_cal_highest_stage(ad714x, hw->start_stage,
hw->end_stage);
dev_dbg(ad714x->dev, "wheel %d highest_stage:%d\n", idx,
sw->highest_stage);
}
static void ad714x_wheel_cal_sensor_val(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_wheel_plat *hw = &ad714x->hw->wheel[idx];
int i;
ad714x->read(ad714x, CDC_RESULT_S0 + hw->start_stage,
&ad714x->adc_reg[hw->start_stage],
hw->end_stage - hw->start_stage + 1);
for (i = hw->start_stage; i <= hw->end_stage; i++) {
ad714x->read(ad714x, STAGE0_AMBIENT + i * PER_STAGE_REG_NUM,
&ad714x->amb_reg[i], 1);
if (ad714x->adc_reg[i] > ad714x->amb_reg[i])
ad714x->sensor_val[i] =
ad714x->adc_reg[i] - ad714x->amb_reg[i];
else
ad714x->sensor_val[i] = 0;
}
}
static void ad714x_wheel_cal_abs_pos(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_wheel_plat *hw = &ad714x->hw->wheel[idx];
struct ad714x_wheel_drv *sw = &ad714x->sw->wheel[idx];
int stage_num = hw->end_stage - hw->start_stage + 1;
int first_before, highest, first_after;
int a_param, b_param;
first_before = (sw->highest_stage + stage_num - 1) % stage_num;
highest = sw->highest_stage;
first_after = (sw->highest_stage + stage_num + 1) % stage_num;
a_param = ad714x->sensor_val[highest] *
(highest - hw->start_stage) +
ad714x->sensor_val[first_before] *
(highest - hw->start_stage - 1) +
ad714x->sensor_val[first_after] *
(highest - hw->start_stage + 1);
b_param = ad714x->sensor_val[highest] +
ad714x->sensor_val[first_before] +
ad714x->sensor_val[first_after];
sw->abs_pos = ((hw->max_coord / (hw->end_stage - hw->start_stage)) *
a_param) / b_param;
if (sw->abs_pos > hw->max_coord)
sw->abs_pos = hw->max_coord;
else if (sw->abs_pos < 0)
sw->abs_pos = 0;
}
static void ad714x_wheel_cal_flt_pos(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_wheel_plat *hw = &ad714x->hw->wheel[idx];
struct ad714x_wheel_drv *sw = &ad714x->sw->wheel[idx];
if (((sw->pre_highest_stage == hw->end_stage) &&
(sw->highest_stage == hw->start_stage)) ||
((sw->pre_highest_stage == hw->start_stage) &&
(sw->highest_stage == hw->end_stage)))
sw->flt_pos = sw->abs_pos;
else
sw->flt_pos = ((sw->flt_pos * 30) + (sw->abs_pos * 71)) / 100;
if (sw->flt_pos > hw->max_coord)
sw->flt_pos = hw->max_coord;
}
static void ad714x_wheel_use_com_int(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_wheel_plat *hw = &ad714x->hw->wheel[idx];
ad714x_use_com_int(ad714x, hw->start_stage, hw->end_stage);
}
static void ad714x_wheel_use_thr_int(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_wheel_plat *hw = &ad714x->hw->wheel[idx];
ad714x_use_thr_int(ad714x, hw->start_stage, hw->end_stage);
}
static void ad714x_wheel_state_machine(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_wheel_plat *hw = &ad714x->hw->wheel[idx];
struct ad714x_wheel_drv *sw = &ad714x->sw->wheel[idx];
unsigned short h_state, c_state;
unsigned short mask;
mask = ((1 << (hw->end_stage + 1)) - 1) - ((1 << hw->start_stage) - 1);
h_state = ad714x->h_state & mask;
c_state = ad714x->c_state & mask;
switch (sw->state) {
case IDLE:
if (h_state) {
sw->state = JITTER;
ad714x_wheel_use_com_int(ad714x, idx);
dev_dbg(ad714x->dev, "wheel %d touched\n", idx);
}
break;
case JITTER:
if (c_state == mask) {
ad714x_wheel_cal_sensor_val(ad714x, idx);
ad714x_wheel_cal_highest_stage(ad714x, idx);
ad714x_wheel_cal_abs_pos(ad714x, idx);
sw->flt_pos = sw->abs_pos;
sw->state = ACTIVE;
}
break;
case ACTIVE:
if (c_state == mask) {
if (h_state) {
ad714x_wheel_cal_sensor_val(ad714x, idx);
ad714x_wheel_cal_highest_stage(ad714x, idx);
ad714x_wheel_cal_abs_pos(ad714x, idx);
ad714x_wheel_cal_flt_pos(ad714x, idx);
input_report_abs(sw->input, ABS_WHEEL,
sw->flt_pos);
input_report_key(sw->input, BTN_TOUCH, 1);
} else {
ad714x_wheel_use_thr_int(ad714x, idx);
sw->state = IDLE;
input_report_key(sw->input, BTN_TOUCH, 0);
dev_dbg(ad714x->dev, "wheel %d released\n",
idx);
}
input_sync(sw->input);
}
break;
default:
break;
}
}
static void touchpad_cal_sensor_val(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_touchpad_plat *hw = &ad714x->hw->touchpad[idx];
int i;
ad714x->read(ad714x, CDC_RESULT_S0 + hw->x_start_stage,
&ad714x->adc_reg[hw->x_start_stage],
hw->x_end_stage - hw->x_start_stage + 1);
for (i = hw->x_start_stage; i <= hw->x_end_stage; i++) {
ad714x->read(ad714x, STAGE0_AMBIENT + i * PER_STAGE_REG_NUM,
&ad714x->amb_reg[i], 1);
if (ad714x->adc_reg[i] > ad714x->amb_reg[i])
ad714x->sensor_val[i] =
ad714x->adc_reg[i] - ad714x->amb_reg[i];
else
ad714x->sensor_val[i] = 0;
}
}
static void touchpad_cal_highest_stage(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_touchpad_plat *hw = &ad714x->hw->touchpad[idx];
struct ad714x_touchpad_drv *sw = &ad714x->sw->touchpad[idx];
sw->x_highest_stage = ad714x_cal_highest_stage(ad714x,
hw->x_start_stage, hw->x_end_stage);
sw->y_highest_stage = ad714x_cal_highest_stage(ad714x,
hw->y_start_stage, hw->y_end_stage);
dev_dbg(ad714x->dev,
"touchpad %d x_highest_stage:%d, y_highest_stage:%d\n",
idx, sw->x_highest_stage, sw->y_highest_stage);
}
static int touchpad_check_second_peak(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_touchpad_plat *hw = &ad714x->hw->touchpad[idx];
struct ad714x_touchpad_drv *sw = &ad714x->sw->touchpad[idx];
int i;
for (i = hw->x_start_stage; i < sw->x_highest_stage; i++) {
if ((ad714x->sensor_val[i] - ad714x->sensor_val[i + 1])
> (ad714x->sensor_val[i + 1] / 10))
return 1;
}
for (i = sw->x_highest_stage; i < hw->x_end_stage; i++) {
if ((ad714x->sensor_val[i + 1] - ad714x->sensor_val[i])
> (ad714x->sensor_val[i] / 10))
return 1;
}
for (i = hw->y_start_stage; i < sw->y_highest_stage; i++) {
if ((ad714x->sensor_val[i] - ad714x->sensor_val[i + 1])
> (ad714x->sensor_val[i + 1] / 10))
return 1;
}
for (i = sw->y_highest_stage; i < hw->y_end_stage; i++) {
if ((ad714x->sensor_val[i + 1] - ad714x->sensor_val[i])
> (ad714x->sensor_val[i] / 10))
return 1;
}
return 0;
}
static void touchpad_cal_abs_pos(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_touchpad_plat *hw = &ad714x->hw->touchpad[idx];
struct ad714x_touchpad_drv *sw = &ad714x->sw->touchpad[idx];
sw->x_abs_pos = ad714x_cal_abs_pos(ad714x, hw->x_start_stage,
hw->x_end_stage, sw->x_highest_stage, hw->x_max_coord);
sw->y_abs_pos = ad714x_cal_abs_pos(ad714x, hw->y_start_stage,
hw->y_end_stage, sw->y_highest_stage, hw->y_max_coord);
dev_dbg(ad714x->dev, "touchpad %d absolute position:(%d, %d)\n", idx,
sw->x_abs_pos, sw->y_abs_pos);
}
static void touchpad_cal_flt_pos(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_touchpad_drv *sw = &ad714x->sw->touchpad[idx];
sw->x_flt_pos = (sw->x_flt_pos * (10 - 4) +
sw->x_abs_pos * 4)/10;
sw->y_flt_pos = (sw->y_flt_pos * (10 - 4) +
sw->y_abs_pos * 4)/10;
dev_dbg(ad714x->dev, "touchpad %d filter position:(%d, %d)\n",
idx, sw->x_flt_pos, sw->y_flt_pos);
}
static int touchpad_check_endpoint(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_touchpad_plat *hw = &ad714x->hw->touchpad[idx];
struct ad714x_touchpad_drv *sw = &ad714x->sw->touchpad[idx];
int percent_sensor_diff;
percent_sensor_diff = (ad714x->sensor_val[hw->x_start_stage] -
ad714x->sensor_val[hw->x_start_stage + 1]) * 100 /
ad714x->sensor_val[hw->x_start_stage + 1];
if (!sw->left_ep) {
if (percent_sensor_diff >= LEFT_END_POINT_DETECTION_LEVEL) {
sw->left_ep = 1;
sw->left_ep_val =
ad714x->sensor_val[hw->x_start_stage + 1];
}
} else {
if ((percent_sensor_diff < LEFT_END_POINT_DETECTION_LEVEL) &&
(ad714x->sensor_val[hw->x_start_stage + 1] >
LEFT_RIGHT_END_POINT_DEAVTIVALION_LEVEL + sw->left_ep_val))
sw->left_ep = 0;
}
percent_sensor_diff = (ad714x->sensor_val[hw->x_end_stage] -
ad714x->sensor_val[hw->x_end_stage - 1]) * 100 /
ad714x->sensor_val[hw->x_end_stage - 1];
if (!sw->right_ep) {
if (percent_sensor_diff >= RIGHT_END_POINT_DETECTION_LEVEL) {
sw->right_ep = 1;
sw->right_ep_val =
ad714x->sensor_val[hw->x_end_stage - 1];
}
} else {
if ((percent_sensor_diff < RIGHT_END_POINT_DETECTION_LEVEL) &&
(ad714x->sensor_val[hw->x_end_stage - 1] >
LEFT_RIGHT_END_POINT_DEAVTIVALION_LEVEL + sw->right_ep_val))
sw->right_ep = 0;
}
percent_sensor_diff = (ad714x->sensor_val[hw->y_start_stage] -
ad714x->sensor_val[hw->y_start_stage + 1]) * 100 /
ad714x->sensor_val[hw->y_start_stage + 1];
if (!sw->top_ep) {
if (percent_sensor_diff >= TOP_END_POINT_DETECTION_LEVEL) {
sw->top_ep = 1;
sw->top_ep_val =
ad714x->sensor_val[hw->y_start_stage + 1];
}
} else {
if ((percent_sensor_diff < TOP_END_POINT_DETECTION_LEVEL) &&
(ad714x->sensor_val[hw->y_start_stage + 1] >
TOP_BOTTOM_END_POINT_DEAVTIVALION_LEVEL + sw->top_ep_val))
sw->top_ep = 0;
}
percent_sensor_diff = (ad714x->sensor_val[hw->y_end_stage] -
ad714x->sensor_val[hw->y_end_stage - 1]) * 100 /
ad714x->sensor_val[hw->y_end_stage - 1];
if (!sw->bottom_ep) {
if (percent_sensor_diff >= BOTTOM_END_POINT_DETECTION_LEVEL) {
sw->bottom_ep = 1;
sw->bottom_ep_val =
ad714x->sensor_val[hw->y_end_stage - 1];
}
} else {
if ((percent_sensor_diff < BOTTOM_END_POINT_DETECTION_LEVEL) &&
(ad714x->sensor_val[hw->y_end_stage - 1] >
TOP_BOTTOM_END_POINT_DEAVTIVALION_LEVEL + sw->bottom_ep_val))
sw->bottom_ep = 0;
}
return sw->left_ep || sw->right_ep || sw->top_ep || sw->bottom_ep;
}
static void touchpad_use_com_int(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_touchpad_plat *hw = &ad714x->hw->touchpad[idx];
ad714x_use_com_int(ad714x, hw->x_start_stage, hw->x_end_stage);
}
static void touchpad_use_thr_int(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_touchpad_plat *hw = &ad714x->hw->touchpad[idx];
ad714x_use_thr_int(ad714x, hw->x_start_stage, hw->x_end_stage);
ad714x_use_thr_int(ad714x, hw->y_start_stage, hw->y_end_stage);
}
static void ad714x_touchpad_state_machine(struct ad714x_chip *ad714x, int idx)
{
struct ad714x_touchpad_plat *hw = &ad714x->hw->touchpad[idx];
struct ad714x_touchpad_drv *sw = &ad714x->sw->touchpad[idx];
unsigned short h_state, c_state;
unsigned short mask;
mask = (((1 << (hw->x_end_stage + 1)) - 1) -
((1 << hw->x_start_stage) - 1)) +
(((1 << (hw->y_end_stage + 1)) - 1) -
((1 << hw->y_start_stage) - 1));
h_state = ad714x->h_state & mask;
c_state = ad714x->c_state & mask;
switch (sw->state) {
case IDLE:
if (h_state) {
sw->state = JITTER;
touchpad_use_com_int(ad714x, idx);
dev_dbg(ad714x->dev, "touchpad %d touched\n", idx);
}
break;
case JITTER:
if (c_state == mask) {
touchpad_cal_sensor_val(ad714x, idx);
touchpad_cal_highest_stage(ad714x, idx);
if ((!touchpad_check_second_peak(ad714x, idx)) &&
(!touchpad_check_endpoint(ad714x, idx))) {
dev_dbg(ad714x->dev,
"touchpad%d, 2 fingers or endpoint\n",
idx);
touchpad_cal_abs_pos(ad714x, idx);
sw->x_flt_pos = sw->x_abs_pos;
sw->y_flt_pos = sw->y_abs_pos;
sw->state = ACTIVE;
}
}
break;
case ACTIVE:
if (c_state == mask) {
if (h_state) {
touchpad_cal_sensor_val(ad714x, idx);
touchpad_cal_highest_stage(ad714x, idx);
if ((!touchpad_check_second_peak(ad714x, idx))
&& (!touchpad_check_endpoint(ad714x, idx))) {
touchpad_cal_abs_pos(ad714x, idx);
touchpad_cal_flt_pos(ad714x, idx);
input_report_abs(sw->input, ABS_X,
sw->x_flt_pos);
input_report_abs(sw->input, ABS_Y,
sw->y_flt_pos);
input_report_key(sw->input, BTN_TOUCH,
1);
}
} else {
touchpad_use_thr_int(ad714x, idx);
sw->state = IDLE;
input_report_key(sw->input, BTN_TOUCH, 0);
dev_dbg(ad714x->dev, "touchpad %d released\n",
idx);
}
input_sync(sw->input);
}
break;
default:
break;
}
}
static int ad714x_hw_detect(struct ad714x_chip *ad714x)
{
unsigned short data;
ad714x->read(ad714x, AD714X_PARTID_REG, &data, 1);
switch (data & 0xFFF0) {
case AD7142_PARTID:
ad714x->product = 0x7142;
ad714x->version = data & 0xF;
dev_info(ad714x->dev, "found AD7142 captouch, rev:%d\n",
ad714x->version);
return 0;
case AD7143_PARTID:
ad714x->product = 0x7143;
ad714x->version = data & 0xF;
dev_info(ad714x->dev, "found AD7143 captouch, rev:%d\n",
ad714x->version);
return 0;
case AD7147_PARTID:
ad714x->product = 0x7147;
ad714x->version = data & 0xF;
dev_info(ad714x->dev, "found AD7147(A) captouch, rev:%d\n",
ad714x->version);
return 0;
case AD7148_PARTID:
ad714x->product = 0x7148;
ad714x->version = data & 0xF;
dev_info(ad714x->dev, "found AD7148 captouch, rev:%d\n",
ad714x->version);
return 0;
default:
dev_err(ad714x->dev,
"fail to detect AD714X captouch, read ID is %04x\n",
data);
return -ENODEV;
}
}
static void ad714x_hw_init(struct ad714x_chip *ad714x)
{
int i, j;
unsigned short reg_base;
unsigned short data;
for (i = 0; i < STAGE_NUM; i++) {
reg_base = AD714X_STAGECFG_REG + i * STAGE_CFGREG_NUM;
for (j = 0; j < STAGE_CFGREG_NUM; j++)
ad714x->write(ad714x, reg_base + j,
ad714x->hw->stage_cfg_reg[i][j]);
}
for (i = 0; i < SYS_CFGREG_NUM; i++)
ad714x->write(ad714x, AD714X_SYSCFG_REG + i,
ad714x->hw->sys_cfg_reg[i]);
for (i = 0; i < SYS_CFGREG_NUM; i++)
ad714x->read(ad714x, AD714X_SYSCFG_REG + i, &data, 1);
ad714x->write(ad714x, AD714X_STG_CAL_EN_REG, 0xFFF);
ad714x->read(ad714x, STG_LOW_INT_STA_REG, &ad714x->l_state, 3);
}
static irqreturn_t ad714x_interrupt_thread(int irq, void *data)
{
struct ad714x_chip *ad714x = data;
int i;
mutex_lock(&ad714x->mutex);
ad714x->read(ad714x, STG_LOW_INT_STA_REG, &ad714x->l_state, 3);
for (i = 0; i < ad714x->hw->button_num; i++)
ad714x_button_state_machine(ad714x, i);
for (i = 0; i < ad714x->hw->slider_num; i++)
ad714x_slider_state_machine(ad714x, i);
for (i = 0; i < ad714x->hw->wheel_num; i++)
ad714x_wheel_state_machine(ad714x, i);
for (i = 0; i < ad714x->hw->touchpad_num; i++)
ad714x_touchpad_state_machine(ad714x, i);
mutex_unlock(&ad714x->mutex);
return IRQ_HANDLED;
}
struct ad714x_chip *ad714x_probe(struct device *dev, u16 bus_type, int irq,
ad714x_read_t read, ad714x_write_t write)
{
int i, alloc_idx;
int error;
struct input_dev *input[MAX_DEVICE_NUM];
struct ad714x_platform_data *plat_data = dev_get_platdata(dev);
struct ad714x_chip *ad714x;
void *drv_mem;
unsigned long irqflags;
struct ad714x_button_drv *bt_drv;
struct ad714x_slider_drv *sd_drv;
struct ad714x_wheel_drv *wl_drv;
struct ad714x_touchpad_drv *tp_drv;
if (irq <= 0) {
dev_err(dev, "IRQ not configured!\n");
error = -EINVAL;
goto err_out;
}
if (dev_get_platdata(dev) == NULL) {
dev_err(dev, "platform data for ad714x doesn't exist\n");
error = -EINVAL;
goto err_out;
}
ad714x = kzalloc(sizeof(*ad714x) + sizeof(*ad714x->sw) +
sizeof(*sd_drv) * plat_data->slider_num +
sizeof(*wl_drv) * plat_data->wheel_num +
sizeof(*tp_drv) * plat_data->touchpad_num +
sizeof(*bt_drv) * plat_data->button_num, GFP_KERNEL);
if (!ad714x) {
error = -ENOMEM;
goto err_out;
}
ad714x->hw = plat_data;
drv_mem = ad714x + 1;
ad714x->sw = drv_mem;
drv_mem += sizeof(*ad714x->sw);
ad714x->sw->slider = sd_drv = drv_mem;
drv_mem += sizeof(*sd_drv) * ad714x->hw->slider_num;
ad714x->sw->wheel = wl_drv = drv_mem;
drv_mem += sizeof(*wl_drv) * ad714x->hw->wheel_num;
ad714x->sw->touchpad = tp_drv = drv_mem;
drv_mem += sizeof(*tp_drv) * ad714x->hw->touchpad_num;
ad714x->sw->button = bt_drv = drv_mem;
drv_mem += sizeof(*bt_drv) * ad714x->hw->button_num;
ad714x->read = read;
ad714x->write = write;
ad714x->irq = irq;
ad714x->dev = dev;
error = ad714x_hw_detect(ad714x);
if (error)
goto err_free_mem;
ad714x_hw_init(ad714x);
mutex_init(&ad714x->mutex);
alloc_idx = 0;
if (ad714x->hw->slider_num > 0) {
struct ad714x_slider_plat *sd_plat = ad714x->hw->slider;
for (i = 0; i < ad714x->hw->slider_num; i++) {
sd_drv[i].input = input[alloc_idx] = input_allocate_device();
if (!input[alloc_idx]) {
error = -ENOMEM;
goto err_free_dev;
}
__set_bit(EV_ABS, input[alloc_idx]->evbit);
__set_bit(EV_KEY, input[alloc_idx]->evbit);
__set_bit(ABS_X, input[alloc_idx]->absbit);
__set_bit(BTN_TOUCH, input[alloc_idx]->keybit);
input_set_abs_params(input[alloc_idx],
ABS_X, 0, sd_plat->max_coord, 0, 0);
input[alloc_idx]->id.bustype = bus_type;
input[alloc_idx]->id.product = ad714x->product;
input[alloc_idx]->id.version = ad714x->version;
input[alloc_idx]->name = "ad714x_captouch_slider";
input[alloc_idx]->dev.parent = dev;
error = input_register_device(input[alloc_idx]);
if (error)
goto err_free_dev;
alloc_idx++;
}
}
if (ad714x->hw->wheel_num > 0) {
struct ad714x_wheel_plat *wl_plat = ad714x->hw->wheel;
for (i = 0; i < ad714x->hw->wheel_num; i++) {
wl_drv[i].input = input[alloc_idx] = input_allocate_device();
if (!input[alloc_idx]) {
error = -ENOMEM;
goto err_free_dev;
}
__set_bit(EV_KEY, input[alloc_idx]->evbit);
__set_bit(EV_ABS, input[alloc_idx]->evbit);
__set_bit(ABS_WHEEL, input[alloc_idx]->absbit);
__set_bit(BTN_TOUCH, input[alloc_idx]->keybit);
input_set_abs_params(input[alloc_idx],
ABS_WHEEL, 0, wl_plat->max_coord, 0, 0);
input[alloc_idx]->id.bustype = bus_type;
input[alloc_idx]->id.product = ad714x->product;
input[alloc_idx]->id.version = ad714x->version;
input[alloc_idx]->name = "ad714x_captouch_wheel";
input[alloc_idx]->dev.parent = dev;
error = input_register_device(input[alloc_idx]);
if (error)
goto err_free_dev;
alloc_idx++;
}
}
if (ad714x->hw->touchpad_num > 0) {
struct ad714x_touchpad_plat *tp_plat = ad714x->hw->touchpad;
for (i = 0; i < ad714x->hw->touchpad_num; i++) {
tp_drv[i].input = input[alloc_idx] = input_allocate_device();
if (!input[alloc_idx]) {
error = -ENOMEM;
goto err_free_dev;
}
__set_bit(EV_ABS, input[alloc_idx]->evbit);
__set_bit(EV_KEY, input[alloc_idx]->evbit);
__set_bit(ABS_X, input[alloc_idx]->absbit);
__set_bit(ABS_Y, input[alloc_idx]->absbit);
__set_bit(BTN_TOUCH, input[alloc_idx]->keybit);
input_set_abs_params(input[alloc_idx],
ABS_X, 0, tp_plat->x_max_coord, 0, 0);
input_set_abs_params(input[alloc_idx],
ABS_Y, 0, tp_plat->y_max_coord, 0, 0);
input[alloc_idx]->id.bustype = bus_type;
input[alloc_idx]->id.product = ad714x->product;
input[alloc_idx]->id.version = ad714x->version;
input[alloc_idx]->name = "ad714x_captouch_pad";
input[alloc_idx]->dev.parent = dev;
error = input_register_device(input[alloc_idx]);
if (error)
goto err_free_dev;
alloc_idx++;
}
}
if (ad714x->hw->button_num > 0) {
struct ad714x_button_plat *bt_plat = ad714x->hw->button;
input[alloc_idx] = input_allocate_device();
if (!input[alloc_idx]) {
error = -ENOMEM;
goto err_free_dev;
}
__set_bit(EV_KEY, input[alloc_idx]->evbit);
for (i = 0; i < ad714x->hw->button_num; i++) {
bt_drv[i].input = input[alloc_idx];
__set_bit(bt_plat[i].keycode, input[alloc_idx]->keybit);
}
input[alloc_idx]->id.bustype = bus_type;
input[alloc_idx]->id.product = ad714x->product;
input[alloc_idx]->id.version = ad714x->version;
input[alloc_idx]->name = "ad714x_captouch_button";
input[alloc_idx]->dev.parent = dev;
error = input_register_device(input[alloc_idx]);
if (error)
goto err_free_dev;
alloc_idx++;
}
irqflags = plat_data->irqflags ?: IRQF_TRIGGER_FALLING;
irqflags |= IRQF_ONESHOT;
error = request_threaded_irq(ad714x->irq, NULL, ad714x_interrupt_thread,
irqflags, "ad714x_captouch", ad714x);
if (error) {
dev_err(dev, "can't allocate irq %d\n", ad714x->irq);
goto err_unreg_dev;
}
return ad714x;
err_free_dev:
dev_err(dev, "failed to setup AD714x input device %i\n", alloc_idx);
input_free_device(input[alloc_idx]);
err_unreg_dev:
while (--alloc_idx >= 0)
input_unregister_device(input[alloc_idx]);
err_free_mem:
kfree(ad714x);
err_out:
return ERR_PTR(error);
}
void ad714x_remove(struct ad714x_chip *ad714x)
{
struct ad714x_platform_data *hw = ad714x->hw;
struct ad714x_driver_data *sw = ad714x->sw;
int i;
free_irq(ad714x->irq, ad714x);
for (i = 0; i < hw->slider_num; i++)
input_unregister_device(sw->slider[i].input);
for (i = 0; i < hw->wheel_num; i++)
input_unregister_device(sw->wheel[i].input);
for (i = 0; i < hw->touchpad_num; i++)
input_unregister_device(sw->touchpad[i].input);
if (hw->button_num)
input_unregister_device(sw->button[0].input);
kfree(ad714x);
}
int ad714x_disable(struct ad714x_chip *ad714x)
{
unsigned short data;
dev_dbg(ad714x->dev, "%s enter\n", __func__);
mutex_lock(&ad714x->mutex);
data = ad714x->hw->sys_cfg_reg[AD714X_PWR_CTRL] | 0x3;
ad714x->write(ad714x, AD714X_PWR_CTRL, data);
mutex_unlock(&ad714x->mutex);
return 0;
}
int ad714x_enable(struct ad714x_chip *ad714x)
{
dev_dbg(ad714x->dev, "%s enter\n", __func__);
mutex_lock(&ad714x->mutex);
ad714x->write(ad714x, AD714X_PWR_CTRL,
ad714x->hw->sys_cfg_reg[AD714X_PWR_CTRL]);
ad714x->read(ad714x, STG_LOW_INT_STA_REG, &ad714x->l_state, 3);
mutex_unlock(&ad714x->mutex);
return 0;
}
