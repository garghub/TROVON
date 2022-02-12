static int ps2_startstreaming(struct serio *ser_dev)
{
unsigned char buf[] = START_STREAMING;
return nvec_write_async(ps2_dev.nvec, buf, sizeof(buf));
}
static void ps2_stopstreaming(struct serio *ser_dev)
{
unsigned char buf[] = STOP_STREAMING;
nvec_write_async(ps2_dev.nvec, buf, sizeof(buf));
}
static int ps2_sendcommand(struct serio *ser_dev, unsigned char cmd)
{
unsigned char buf[] = SEND_COMMAND;
buf[2] = cmd & 0xff;
dev_dbg(&ser_dev->dev, "Sending ps2 cmd %02x\n", cmd);
return nvec_write_async(ps2_dev.nvec, buf, sizeof(buf));
}
static int nvec_ps2_notifier(struct notifier_block *nb,
unsigned long event_type, void *data)
{
int i;
unsigned char *msg = (unsigned char *)data;
switch (event_type) {
case NVEC_PS2_EVT:
for (i = 0; i < msg[1]; i++)
serio_interrupt(ps2_dev.ser_dev, msg[2 + i], 0);
NVEC_PHD("ps/2 mouse event: ", &msg[2], msg[1]);
return NOTIFY_STOP;
case NVEC_PS2:
if (msg[2] == 1) {
for (i = 0; i < (msg[1] - 2); i++)
serio_interrupt(ps2_dev.ser_dev, msg[i + 4], 0);
NVEC_PHD("ps/2 mouse reply: ", &msg[4], msg[1] - 2);
}
else if (msg[1] != 2)
NVEC_PHD("unhandled mouse event: ", msg, msg[1] + 2);
return NOTIFY_STOP;
}
return NOTIFY_DONE;
}
static int __devinit nvec_mouse_probe(struct platform_device *pdev)
{
struct nvec_chip *nvec = dev_get_drvdata(pdev->dev.parent);
struct serio *ser_dev = kzalloc(sizeof(struct serio), GFP_KERNEL);
ser_dev->id.type = SERIO_PS_PSTHRU;
ser_dev->write = ps2_sendcommand;
ser_dev->start = ps2_startstreaming;
ser_dev->stop = ps2_stopstreaming;
strlcpy(ser_dev->name, "nvec mouse", sizeof(ser_dev->name));
strlcpy(ser_dev->phys, "nvec", sizeof(ser_dev->phys));
ps2_dev.ser_dev = ser_dev;
ps2_dev.notifier.notifier_call = nvec_ps2_notifier;
ps2_dev.nvec = nvec;
nvec_register_notifier(nvec, &ps2_dev.notifier, 0);
serio_register_port(ser_dev);
nvec_write_async(nvec, MOUSE_RESET, 4);
return 0;
}
static int nvec_mouse_suspend(struct platform_device *pdev, pm_message_t state)
{
struct nvec_chip *nvec = dev_get_drvdata(pdev->dev.parent);
nvec_write_async(nvec, "\x06\xf4", 2);
nvec_write_async(nvec, "\x06\x04", 2);
return 0;
}
static int nvec_mouse_resume(struct platform_device *pdev)
{
struct nvec_chip *nvec = dev_get_drvdata(pdev->dev.parent);
ps2_startstreaming(ps2_dev.ser_dev);
nvec_write_async(nvec, "\x06\xf5", 2);
return 0;
}
static int __init nvec_mouse_init(void)
{
return platform_driver_register(&nvec_mouse_driver);
}
