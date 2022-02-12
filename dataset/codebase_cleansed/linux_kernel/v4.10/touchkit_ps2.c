static psmouse_ret_t touchkit_ps2_process_byte(struct psmouse *psmouse)
{
unsigned char *packet = psmouse->packet;
struct input_dev *dev = psmouse->dev;
if (psmouse->pktcnt != 5)
return PSMOUSE_GOOD_DATA;
input_report_abs(dev, ABS_X, TOUCHKIT_GET_X(packet));
input_report_abs(dev, ABS_Y, TOUCHKIT_GET_Y(packet));
input_report_key(dev, BTN_TOUCH, TOUCHKIT_GET_TOUCHED(packet));
input_sync(dev);
return PSMOUSE_FULL_PACKET;
}
int touchkit_ps2_detect(struct psmouse *psmouse, bool set_properties)
{
struct input_dev *dev = psmouse->dev;
unsigned char param[3];
int command;
param[0] = TOUCHKIT_CMD_LENGTH;
param[1] = TOUCHKIT_CMD_ACTIVE;
command = TOUCHKIT_SEND_PARMS(2, 3, TOUCHKIT_CMD);
if (ps2_command(&psmouse->ps2dev, param, command))
return -ENODEV;
if (param[0] != TOUCHKIT_CMD || param[1] != 0x01 ||
param[2] != TOUCHKIT_CMD_ACTIVE)
return -ENODEV;
if (set_properties) {
dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
dev->keybit[BIT_WORD(BTN_MOUSE)] = 0;
dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(dev, ABS_X, 0, TOUCHKIT_MAX_XC, 0, 0);
input_set_abs_params(dev, ABS_Y, 0, TOUCHKIT_MAX_YC, 0, 0);
psmouse->vendor = "eGalax";
psmouse->name = "Touchscreen";
psmouse->protocol_handler = touchkit_ps2_process_byte;
psmouse->pktsize = 5;
}
return 0;
}
