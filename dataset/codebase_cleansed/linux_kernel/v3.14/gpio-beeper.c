static void gpio_beeper_toggle(struct gpio_beeper *beep, bool on)
{
gpio_set_value_cansleep(beep->gpio, on ^ beep->active_low);
}
static void gpio_beeper_work(struct work_struct *work)
{
struct gpio_beeper *beep = container_of(work, struct gpio_beeper, work);
gpio_beeper_toggle(beep, beep->beeping);
}
static int gpio_beeper_event(struct input_dev *dev, unsigned int type,
unsigned int code, int value)
{
struct gpio_beeper *beep = input_get_drvdata(dev);
if (type != EV_SND || code != SND_BELL)
return -ENOTSUPP;
if (value < 0)
return -EINVAL;
beep->beeping = value;
schedule_work(&beep->work);
return 0;
}
static void gpio_beeper_close(struct input_dev *input)
{
struct gpio_beeper *beep = input_get_drvdata(input);
cancel_work_sync(&beep->work);
gpio_beeper_toggle(beep, false);
}
static int gpio_beeper_probe(struct platform_device *pdev)
{
struct gpio_beeper *beep;
enum of_gpio_flags flags;
struct input_dev *input;
unsigned long gflags;
int err;
beep = devm_kzalloc(&pdev->dev, sizeof(*beep), GFP_KERNEL);
if (!beep)
return -ENOMEM;
beep->gpio = of_get_gpio_flags(pdev->dev.of_node, 0, &flags);
if (!gpio_is_valid(beep->gpio))
return beep->gpio;
input = devm_input_allocate_device(&pdev->dev);
if (!input)
return -ENOMEM;
INIT_WORK(&beep->work, gpio_beeper_work);
input->name = pdev->name;
input->id.bustype = BUS_HOST;
input->id.vendor = 0x0001;
input->id.product = 0x0001;
input->id.version = 0x0100;
input->close = gpio_beeper_close;
input->event = gpio_beeper_event;
input_set_capability(input, EV_SND, SND_BELL);
beep->active_low = flags & OF_GPIO_ACTIVE_LOW;
gflags = beep->active_low ? GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW;
err = devm_gpio_request_one(&pdev->dev, beep->gpio, gflags, pdev->name);
if (err)
return err;
input_set_drvdata(input, beep);
return input_register_device(input);
}
