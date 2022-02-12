void gpio_free(unsigned gpio)
{
gpiod_free(gpio_to_desc(gpio));
}
int gpio_request_one(unsigned gpio, unsigned long flags, const char *label)
{
struct gpio_desc *desc;
int err;
desc = gpio_to_desc(gpio);
err = gpiod_request(desc, label);
if (err)
return err;
if (flags & GPIOF_OPEN_DRAIN)
set_bit(FLAG_OPEN_DRAIN, &desc->flags);
if (flags & GPIOF_OPEN_SOURCE)
set_bit(FLAG_OPEN_SOURCE, &desc->flags);
if (flags & GPIOF_ACTIVE_LOW)
set_bit(FLAG_ACTIVE_LOW, &desc->flags);
if (flags & GPIOF_DIR_IN)
err = gpiod_direction_input(desc);
else
err = gpiod_direction_output_raw(desc,
(flags & GPIOF_INIT_HIGH) ? 1 : 0);
if (err)
goto free_gpio;
if (flags & GPIOF_EXPORT) {
err = gpiod_export(desc, flags & GPIOF_EXPORT_CHANGEABLE);
if (err)
goto free_gpio;
}
return 0;
free_gpio:
gpiod_free(desc);
return err;
}
int gpio_request(unsigned gpio, const char *label)
{
return gpiod_request(gpio_to_desc(gpio), label);
}
int gpio_request_array(const struct gpio *array, size_t num)
{
int i, err;
for (i = 0; i < num; i++, array++) {
err = gpio_request_one(array->gpio, array->flags, array->label);
if (err)
goto err_free;
}
return 0;
err_free:
while (i--)
gpio_free((--array)->gpio);
return err;
}
void gpio_free_array(const struct gpio *array, size_t num)
{
while (num--)
gpio_free((array++)->gpio);
}
