struct sms_board *sms_get_board(unsigned id)
{
BUG_ON(id >= ARRAY_SIZE(sms_boards));
return &sms_boards[id];
}
static inline void sms_gpio_assign_11xx_default_led_config(
struct smscore_gpio_config *pGpioConfig) {
pGpioConfig->Direction = SMS_GPIO_DIRECTION_OUTPUT;
pGpioConfig->InputCharacteristics =
SMS_GPIO_INPUT_CHARACTERISTICS_NORMAL;
pGpioConfig->OutputDriving = SMS_GPIO_OUTPUT_DRIVING_4mA;
pGpioConfig->OutputSlewRate = SMS_GPIO_OUTPUT_SLEW_RATE_0_45_V_NS;
pGpioConfig->PullUpDown = SMS_GPIO_PULL_UP_DOWN_NONE;
}
int sms_board_event(struct smscore_device_t *coredev,
enum SMS_BOARD_EVENTS gevent) {
struct smscore_gpio_config MyGpioConfig;
sms_gpio_assign_11xx_default_led_config(&MyGpioConfig);
switch (gevent) {
case BOARD_EVENT_POWER_INIT:
break;
case BOARD_EVENT_POWER_SUSPEND:
break;
case BOARD_EVENT_POWER_RESUME:
break;
case BOARD_EVENT_BIND:
break;
case BOARD_EVENT_SCAN_PROG:
break;
case BOARD_EVENT_SCAN_COMP:
break;
case BOARD_EVENT_EMERGENCY_WARNING_SIGNAL:
break;
case BOARD_EVENT_FE_LOCK:
break;
case BOARD_EVENT_FE_UNLOCK:
break;
case BOARD_EVENT_DEMOD_LOCK:
break;
case BOARD_EVENT_DEMOD_UNLOCK:
break;
case BOARD_EVENT_RECEPTION_MAX_4:
break;
case BOARD_EVENT_RECEPTION_3:
break;
case BOARD_EVENT_RECEPTION_2:
break;
case BOARD_EVENT_RECEPTION_1:
break;
case BOARD_EVENT_RECEPTION_LOST_0:
break;
case BOARD_EVENT_MULTIPLEX_OK:
break;
case BOARD_EVENT_MULTIPLEX_ERRORS:
break;
default:
sms_err("Unknown SMS board event");
break;
}
return 0;
}
static int sms_set_gpio(struct smscore_device_t *coredev, int pin, int enable)
{
int lvl, ret;
u32 gpio;
struct smscore_config_gpio gpioconfig = {
.direction = SMS_GPIO_DIRECTION_OUTPUT,
.pullupdown = SMS_GPIO_PULLUPDOWN_NONE,
.inputcharacteristics = SMS_GPIO_INPUTCHARACTERISTICS_NORMAL,
.outputslewrate = SMS_GPIO_OUTPUTSLEWRATE_FAST,
.outputdriving = SMS_GPIO_OUTPUTDRIVING_4mA,
};
if (pin == 0)
return -EINVAL;
if (pin < 0) {
gpio = pin * -1;
lvl = enable ? 0 : 1;
} else {
gpio = pin;
lvl = enable ? 1 : 0;
}
ret = smscore_configure_gpio(coredev, gpio, &gpioconfig);
if (ret < 0)
return ret;
return smscore_set_gpio(coredev, gpio, lvl);
}
int sms_board_setup(struct smscore_device_t *coredev)
{
int board_id = smscore_get_board_id(coredev);
struct sms_board *board = sms_get_board(board_id);
switch (board_id) {
case SMS1XXX_BOARD_HAUPPAUGE_WINDHAM:
sms_set_gpio(coredev, board->led_power, 0);
sms_set_gpio(coredev, board->led_hi, 0);
sms_set_gpio(coredev, board->led_lo, 0);
break;
case SMS1XXX_BOARD_HAUPPAUGE_TIGER_MINICARD_R2:
case SMS1XXX_BOARD_HAUPPAUGE_TIGER_MINICARD:
sms_set_gpio(coredev, board->lna_ctrl, 0);
break;
}
return 0;
}
int sms_board_power(struct smscore_device_t *coredev, int onoff)
{
int board_id = smscore_get_board_id(coredev);
struct sms_board *board = sms_get_board(board_id);
switch (board_id) {
case SMS1XXX_BOARD_HAUPPAUGE_WINDHAM:
sms_set_gpio(coredev,
board->led_power, onoff ? 1 : 0);
break;
case SMS1XXX_BOARD_HAUPPAUGE_TIGER_MINICARD_R2:
case SMS1XXX_BOARD_HAUPPAUGE_TIGER_MINICARD:
if (!onoff)
sms_set_gpio(coredev, board->lna_ctrl, 0);
break;
}
return 0;
}
int sms_board_led_feedback(struct smscore_device_t *coredev, int led)
{
int board_id = smscore_get_board_id(coredev);
struct sms_board *board = sms_get_board(board_id);
if (smscore_led_state(coredev, -1) == led)
return 0;
switch (board_id) {
case SMS1XXX_BOARD_HAUPPAUGE_WINDHAM:
sms_set_gpio(coredev,
board->led_lo, (led & SMS_LED_LO) ? 1 : 0);
sms_set_gpio(coredev,
board->led_hi, (led & SMS_LED_HI) ? 1 : 0);
smscore_led_state(coredev, led);
break;
}
return 0;
}
int sms_board_lna_control(struct smscore_device_t *coredev, int onoff)
{
int board_id = smscore_get_board_id(coredev);
struct sms_board *board = sms_get_board(board_id);
sms_debug("%s: LNA %s", __func__, onoff ? "enabled" : "disabled");
switch (board_id) {
case SMS1XXX_BOARD_HAUPPAUGE_TIGER_MINICARD_R2:
case SMS1XXX_BOARD_HAUPPAUGE_TIGER_MINICARD:
sms_set_gpio(coredev,
board->rf_switch, onoff ? 1 : 0);
return sms_set_gpio(coredev,
board->lna_ctrl, onoff ? 1 : 0);
}
return -EINVAL;
}
int sms_board_load_modules(int id)
{
switch (id) {
case SMS1XXX_BOARD_HAUPPAUGE_CATAMOUNT:
case SMS1XXX_BOARD_HAUPPAUGE_OKEMO_A:
case SMS1XXX_BOARD_HAUPPAUGE_OKEMO_B:
case SMS1XXX_BOARD_HAUPPAUGE_WINDHAM:
case SMS1XXX_BOARD_HAUPPAUGE_TIGER_MINICARD:
case SMS1XXX_BOARD_HAUPPAUGE_TIGER_MINICARD_R2:
request_module("smsdvb");
break;
default:
break;
}
return 0;
}
