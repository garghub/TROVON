static struct ssb_bus *ssb_gpio_get_bus(struct gpio_chip *chip)
{
return container_of(chip, struct ssb_bus, gpio);
}
static int ssb_gpio_chipco_get_value(struct gpio_chip *chip, unsigned gpio)
{
struct ssb_bus *bus = ssb_gpio_get_bus(chip);
return !!ssb_chipco_gpio_in(&bus->chipco, 1 << gpio);
}
static void ssb_gpio_chipco_set_value(struct gpio_chip *chip, unsigned gpio,
int value)
{
struct ssb_bus *bus = ssb_gpio_get_bus(chip);
ssb_chipco_gpio_out(&bus->chipco, 1 << gpio, value ? 1 << gpio : 0);
}
static int ssb_gpio_chipco_direction_input(struct gpio_chip *chip,
unsigned gpio)
{
struct ssb_bus *bus = ssb_gpio_get_bus(chip);
ssb_chipco_gpio_outen(&bus->chipco, 1 << gpio, 0);
return 0;
}
static int ssb_gpio_chipco_direction_output(struct gpio_chip *chip,
unsigned gpio, int value)
{
struct ssb_bus *bus = ssb_gpio_get_bus(chip);
ssb_chipco_gpio_outen(&bus->chipco, 1 << gpio, 1 << gpio);
ssb_chipco_gpio_out(&bus->chipco, 1 << gpio, value ? 1 << gpio : 0);
return 0;
}
static int ssb_gpio_chipco_request(struct gpio_chip *chip, unsigned gpio)
{
struct ssb_bus *bus = ssb_gpio_get_bus(chip);
ssb_chipco_gpio_control(&bus->chipco, 1 << gpio, 0);
ssb_chipco_gpio_pulldown(&bus->chipco, 1 << gpio, 0);
ssb_chipco_gpio_pullup(&bus->chipco, 1 << gpio, 1 << gpio);
return 0;
}
static void ssb_gpio_chipco_free(struct gpio_chip *chip, unsigned gpio)
{
struct ssb_bus *bus = ssb_gpio_get_bus(chip);
ssb_chipco_gpio_pullup(&bus->chipco, 1 << gpio, 0);
}
static int ssb_gpio_chipco_init(struct ssb_bus *bus)
{
struct gpio_chip *chip = &bus->gpio;
chip->label = "ssb_chipco_gpio";
chip->owner = THIS_MODULE;
chip->request = ssb_gpio_chipco_request;
chip->free = ssb_gpio_chipco_free;
chip->get = ssb_gpio_chipco_get_value;
chip->set = ssb_gpio_chipco_set_value;
chip->direction_input = ssb_gpio_chipco_direction_input;
chip->direction_output = ssb_gpio_chipco_direction_output;
chip->ngpio = 16;
if (bus->bustype == SSB_BUSTYPE_SSB)
chip->base = 0;
else
chip->base = -1;
return gpiochip_add(chip);
}
static int ssb_gpio_extif_get_value(struct gpio_chip *chip, unsigned gpio)
{
struct ssb_bus *bus = ssb_gpio_get_bus(chip);
return !!ssb_extif_gpio_in(&bus->extif, 1 << gpio);
}
static void ssb_gpio_extif_set_value(struct gpio_chip *chip, unsigned gpio,
int value)
{
struct ssb_bus *bus = ssb_gpio_get_bus(chip);
ssb_extif_gpio_out(&bus->extif, 1 << gpio, value ? 1 << gpio : 0);
}
static int ssb_gpio_extif_direction_input(struct gpio_chip *chip,
unsigned gpio)
{
struct ssb_bus *bus = ssb_gpio_get_bus(chip);
ssb_extif_gpio_outen(&bus->extif, 1 << gpio, 0);
return 0;
}
static int ssb_gpio_extif_direction_output(struct gpio_chip *chip,
unsigned gpio, int value)
{
struct ssb_bus *bus = ssb_gpio_get_bus(chip);
ssb_extif_gpio_outen(&bus->extif, 1 << gpio, 1 << gpio);
ssb_extif_gpio_out(&bus->extif, 1 << gpio, value ? 1 << gpio : 0);
return 0;
}
static int ssb_gpio_extif_init(struct ssb_bus *bus)
{
struct gpio_chip *chip = &bus->gpio;
chip->label = "ssb_extif_gpio";
chip->owner = THIS_MODULE;
chip->get = ssb_gpio_extif_get_value;
chip->set = ssb_gpio_extif_set_value;
chip->direction_input = ssb_gpio_extif_direction_input;
chip->direction_output = ssb_gpio_extif_direction_output;
chip->ngpio = 5;
if (bus->bustype == SSB_BUSTYPE_SSB)
chip->base = 0;
else
chip->base = -1;
return gpiochip_add(chip);
}
static int ssb_gpio_extif_init(struct ssb_bus *bus)
{
return -ENOTSUPP;
}
int ssb_gpio_init(struct ssb_bus *bus)
{
if (ssb_chipco_available(&bus->chipco))
return ssb_gpio_chipco_init(bus);
else if (ssb_extif_available(&bus->extif))
return ssb_gpio_extif_init(bus);
else
SSB_WARN_ON(1);
return -1;
}
int ssb_gpio_unregister(struct ssb_bus *bus)
{
if (ssb_chipco_available(&bus->chipco) ||
ssb_extif_available(&bus->extif)) {
return gpiochip_remove(&bus->gpio);
} else {
SSB_WARN_ON(1);
}
return -1;
}
