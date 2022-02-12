static int check_data(int data)
{
int i, parity = 0;
if (!(data & 0x400)) {
dev_warn(&ams_delta_serio->dev,
"invalid stop bit, data=0x%X\n",
data);
return SERIO_FRAME;
}
for (i = 1; i < 10; i++) {
if (data & (1 << i))
parity++;
}
if (!(parity & 0x01)) {
dev_warn(&ams_delta_serio->dev,
"paritiy check failed, data=0x%X parity=0x%X\n",
data, parity);
return SERIO_PARITY;
}
return 0;
}
static irqreturn_t ams_delta_serio_interrupt(int irq, void *dev_id)
{
int *circ_buff = &fiq_buffer[FIQ_CIRC_BUFF];
int data, dfl;
u8 scancode;
fiq_buffer[FIQ_IRQ_PEND] = 0;
while (fiq_buffer[FIQ_KEYS_CNT] > 0) {
data = circ_buff[fiq_buffer[FIQ_HEAD_OFFSET]++];
fiq_buffer[FIQ_KEYS_CNT]--;
if (fiq_buffer[FIQ_HEAD_OFFSET] == fiq_buffer[FIQ_BUF_LEN])
fiq_buffer[FIQ_HEAD_OFFSET] = 0;
dfl = check_data(data);
scancode = (u8) (data >> 1) & 0xFF;
serio_interrupt(ams_delta_serio, scancode, dfl);
}
return IRQ_HANDLED;
}
static int ams_delta_serio_open(struct serio *serio)
{
ams_delta_latch2_write(AMD_DELTA_LATCH2_KEYBRD_PWR,
AMD_DELTA_LATCH2_KEYBRD_PWR);
return 0;
}
static void ams_delta_serio_close(struct serio *serio)
{
ams_delta_latch2_write(AMD_DELTA_LATCH2_KEYBRD_PWR, 0);
}
static int __init ams_delta_serio_init(void)
{
int err;
if (!machine_is_ams_delta())
return -ENODEV;
ams_delta_serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!ams_delta_serio)
return -ENOMEM;
ams_delta_serio->id.type = SERIO_8042;
ams_delta_serio->open = ams_delta_serio_open;
ams_delta_serio->close = ams_delta_serio_close;
strlcpy(ams_delta_serio->name, "AMS DELTA keyboard adapter",
sizeof(ams_delta_serio->name));
strlcpy(ams_delta_serio->phys, "GPIO/serio0",
sizeof(ams_delta_serio->phys));
err = gpio_request(AMS_DELTA_GPIO_PIN_KEYBRD_DATA, "serio-data");
if (err) {
pr_err("ams_delta_serio: Couldn't request gpio pin for data\n");
goto serio;
}
gpio_direction_input(AMS_DELTA_GPIO_PIN_KEYBRD_DATA);
err = gpio_request(AMS_DELTA_GPIO_PIN_KEYBRD_CLK, "serio-clock");
if (err) {
pr_err("ams_delta_serio: couldn't request gpio pin for clock\n");
goto gpio_data;
}
gpio_direction_input(AMS_DELTA_GPIO_PIN_KEYBRD_CLK);
err = request_irq(gpio_to_irq(AMS_DELTA_GPIO_PIN_KEYBRD_CLK),
ams_delta_serio_interrupt, IRQ_TYPE_EDGE_RISING,
"ams-delta-serio", 0);
if (err < 0) {
pr_err("ams_delta_serio: couldn't request gpio interrupt %d\n",
gpio_to_irq(AMS_DELTA_GPIO_PIN_KEYBRD_CLK));
goto gpio_clk;
}
irq_set_handler(gpio_to_irq(AMS_DELTA_GPIO_PIN_KEYBRD_CLK),
handle_simple_irq);
serio_register_port(ams_delta_serio);
dev_info(&ams_delta_serio->dev, "%s\n", ams_delta_serio->name);
return 0;
gpio_clk:
gpio_free(AMS_DELTA_GPIO_PIN_KEYBRD_CLK);
gpio_data:
gpio_free(AMS_DELTA_GPIO_PIN_KEYBRD_DATA);
serio:
kfree(ams_delta_serio);
return err;
}
static void __exit ams_delta_serio_exit(void)
{
serio_unregister_port(ams_delta_serio);
free_irq(OMAP_GPIO_IRQ(AMS_DELTA_GPIO_PIN_KEYBRD_CLK), 0);
gpio_free(AMS_DELTA_GPIO_PIN_KEYBRD_CLK);
gpio_free(AMS_DELTA_GPIO_PIN_KEYBRD_DATA);
}
