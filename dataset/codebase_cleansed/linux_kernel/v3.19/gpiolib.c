static inline void desc_set_label(struct gpio_desc *d, const char *label)
{
d->label = label;
}
struct gpio_desc *gpio_to_desc(unsigned gpio)
{
struct gpio_chip *chip;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
list_for_each_entry(chip, &gpio_chips, list) {
if (chip->base <= gpio && chip->base + chip->ngpio > gpio) {
spin_unlock_irqrestore(&gpio_lock, flags);
return &chip->desc[gpio - chip->base];
}
}
spin_unlock_irqrestore(&gpio_lock, flags);
if (!gpio_is_valid(gpio))
WARN(1, "invalid GPIO %d\n", gpio);
return NULL;
}
struct gpio_desc *gpiochip_get_desc(struct gpio_chip *chip,
u16 hwnum)
{
if (hwnum >= chip->ngpio)
return ERR_PTR(-EINVAL);
return &chip->desc[hwnum];
}
int desc_to_gpio(const struct gpio_desc *desc)
{
return desc->chip->base + (desc - &desc->chip->desc[0]);
}
struct gpio_chip *gpiod_to_chip(const struct gpio_desc *desc)
{
return desc ? desc->chip : NULL;
}
static int gpiochip_find_base(int ngpio)
{
struct gpio_chip *chip;
int base = ARCH_NR_GPIOS - ngpio;
list_for_each_entry_reverse(chip, &gpio_chips, list) {
if (chip->base + chip->ngpio <= base)
break;
else
base = chip->base - ngpio;
}
if (gpio_is_valid(base)) {
pr_debug("%s: found new base at %d\n", __func__, base);
return base;
} else {
pr_err("%s: cannot find free range\n", __func__);
return -ENOSPC;
}
}
int gpiod_get_direction(struct gpio_desc *desc)
{
struct gpio_chip *chip;
unsigned offset;
int status = -EINVAL;
chip = gpiod_to_chip(desc);
offset = gpio_chip_hwgpio(desc);
if (!chip->get_direction)
return status;
status = chip->get_direction(chip, offset);
if (status > 0) {
status = 1;
clear_bit(FLAG_IS_OUT, &desc->flags);
}
if (status == 0) {
set_bit(FLAG_IS_OUT, &desc->flags);
}
return status;
}
static int gpiochip_add_to_list(struct gpio_chip *chip)
{
struct list_head *pos = &gpio_chips;
struct gpio_chip *_chip;
int err = 0;
list_for_each(pos, &gpio_chips) {
_chip = list_entry(pos, struct gpio_chip, list);
if (_chip->base >= chip->base + chip->ngpio)
break;
}
if (pos != &gpio_chips && pos->prev != &gpio_chips) {
_chip = list_entry(pos->prev, struct gpio_chip, list);
if (_chip->base + _chip->ngpio > chip->base) {
dev_err(chip->dev,
"GPIO integer space overlap, cannot add chip\n");
err = -EBUSY;
}
}
if (!err)
list_add_tail(&chip->list, pos);
return err;
}
int gpiochip_add(struct gpio_chip *chip)
{
unsigned long flags;
int status = 0;
unsigned id;
int base = chip->base;
struct gpio_desc *descs;
descs = kcalloc(chip->ngpio, sizeof(descs[0]), GFP_KERNEL);
if (!descs)
return -ENOMEM;
spin_lock_irqsave(&gpio_lock, flags);
if (base < 0) {
base = gpiochip_find_base(chip->ngpio);
if (base < 0) {
status = base;
spin_unlock_irqrestore(&gpio_lock, flags);
goto err_free_descs;
}
chip->base = base;
}
status = gpiochip_add_to_list(chip);
if (status) {
spin_unlock_irqrestore(&gpio_lock, flags);
goto err_free_descs;
}
for (id = 0; id < chip->ngpio; id++) {
struct gpio_desc *desc = &descs[id];
desc->chip = chip;
desc->flags = !chip->direction_input ? (1 << FLAG_IS_OUT) : 0;
}
chip->desc = descs;
spin_unlock_irqrestore(&gpio_lock, flags);
#ifdef CONFIG_PINCTRL
INIT_LIST_HEAD(&chip->pin_ranges);
#endif
of_gpiochip_add(chip);
acpi_gpiochip_add(chip);
status = gpiochip_export(chip);
if (status)
goto err_remove_chip;
pr_debug("%s: registered GPIOs %d to %d on device: %s\n", __func__,
chip->base, chip->base + chip->ngpio - 1,
chip->label ? : "generic");
return 0;
err_remove_chip:
acpi_gpiochip_remove(chip);
of_gpiochip_remove(chip);
spin_lock_irqsave(&gpio_lock, flags);
list_del(&chip->list);
spin_unlock_irqrestore(&gpio_lock, flags);
chip->desc = NULL;
err_free_descs:
kfree(descs);
pr_err("%s: GPIOs %d..%d (%s) failed to register\n", __func__,
chip->base, chip->base + chip->ngpio - 1,
chip->label ? : "generic");
return status;
}
void gpiochip_remove(struct gpio_chip *chip)
{
unsigned long flags;
unsigned id;
gpiochip_unexport(chip);
gpiochip_irqchip_remove(chip);
acpi_gpiochip_remove(chip);
gpiochip_remove_pin_ranges(chip);
of_gpiochip_remove(chip);
spin_lock_irqsave(&gpio_lock, flags);
for (id = 0; id < chip->ngpio; id++) {
if (test_bit(FLAG_REQUESTED, &chip->desc[id].flags))
dev_crit(chip->dev, "REMOVING GPIOCHIP WITH GPIOS STILL REQUESTED\n");
}
for (id = 0; id < chip->ngpio; id++)
chip->desc[id].chip = NULL;
list_del(&chip->list);
spin_unlock_irqrestore(&gpio_lock, flags);
kfree(chip->desc);
chip->desc = NULL;
}
struct gpio_chip *gpiochip_find(void *data,
int (*match)(struct gpio_chip *chip,
void *data))
{
struct gpio_chip *chip;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
list_for_each_entry(chip, &gpio_chips, list)
if (match(chip, data))
break;
if (&chip->list == &gpio_chips)
chip = NULL;
spin_unlock_irqrestore(&gpio_lock, flags);
return chip;
}
static int gpiochip_match_name(struct gpio_chip *chip, void *data)
{
const char *name = data;
return !strcmp(chip->label, name);
}
static struct gpio_chip *find_chip_by_name(const char *name)
{
return gpiochip_find((void *)name, gpiochip_match_name);
}
void gpiochip_set_chained_irqchip(struct gpio_chip *gpiochip,
struct irq_chip *irqchip,
int parent_irq,
irq_flow_handler_t parent_handler)
{
unsigned int offset;
if (!gpiochip->irqdomain) {
chip_err(gpiochip, "called %s before setting up irqchip\n",
__func__);
return;
}
if (parent_handler) {
if (gpiochip->can_sleep) {
chip_err(gpiochip,
"you cannot have chained interrupts on a "
"chip that may sleep\n");
return;
}
irq_set_handler_data(parent_irq, gpiochip);
irq_set_chained_handler(parent_irq, parent_handler);
}
for (offset = 0; offset < gpiochip->ngpio; offset++)
irq_set_parent(irq_find_mapping(gpiochip->irqdomain, offset),
parent_irq);
}
static int gpiochip_irq_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct gpio_chip *chip = d->host_data;
irq_set_chip_data(irq, chip);
irq_set_lockdep_class(irq, &gpiochip_irq_lock_class);
irq_set_chip_and_handler(irq, chip->irqchip, chip->irq_handler);
if (chip->can_sleep && !chip->irq_not_threaded)
irq_set_nested_thread(irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
if (chip->irq_default_type != IRQ_TYPE_NONE)
irq_set_irq_type(irq, chip->irq_default_type);
return 0;
}
static void gpiochip_irq_unmap(struct irq_domain *d, unsigned int irq)
{
struct gpio_chip *chip = d->host_data;
#ifdef CONFIG_ARM
set_irq_flags(irq, 0);
#endif
if (chip->can_sleep)
irq_set_nested_thread(irq, 0);
irq_set_chip_and_handler(irq, NULL, NULL);
irq_set_chip_data(irq, NULL);
}
static int gpiochip_irq_reqres(struct irq_data *d)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
if (gpiochip_lock_as_irq(chip, d->hwirq)) {
chip_err(chip,
"unable to lock HW IRQ %lu for IRQ\n",
d->hwirq);
return -EINVAL;
}
return 0;
}
static void gpiochip_irq_relres(struct irq_data *d)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
gpiochip_unlock_as_irq(chip, d->hwirq);
}
static int gpiochip_to_irq(struct gpio_chip *chip, unsigned offset)
{
return irq_find_mapping(chip->irqdomain, offset);
}
static void gpiochip_irqchip_remove(struct gpio_chip *gpiochip)
{
unsigned int offset;
acpi_gpiochip_free_interrupts(gpiochip);
if (gpiochip->irqdomain) {
for (offset = 0; offset < gpiochip->ngpio; offset++)
irq_dispose_mapping(
irq_find_mapping(gpiochip->irqdomain, offset));
irq_domain_remove(gpiochip->irqdomain);
}
if (gpiochip->irqchip) {
gpiochip->irqchip->irq_request_resources = NULL;
gpiochip->irqchip->irq_release_resources = NULL;
gpiochip->irqchip = NULL;
}
}
int gpiochip_irqchip_add(struct gpio_chip *gpiochip,
struct irq_chip *irqchip,
unsigned int first_irq,
irq_flow_handler_t handler,
unsigned int type)
{
struct device_node *of_node;
unsigned int offset;
unsigned irq_base = 0;
if (!gpiochip || !irqchip)
return -EINVAL;
if (!gpiochip->dev) {
pr_err("missing gpiochip .dev parent pointer\n");
return -EINVAL;
}
of_node = gpiochip->dev->of_node;
#ifdef CONFIG_OF_GPIO
if (gpiochip->of_node)
of_node = gpiochip->of_node;
#endif
gpiochip->irqchip = irqchip;
gpiochip->irq_handler = handler;
gpiochip->irq_default_type = type;
gpiochip->to_irq = gpiochip_to_irq;
gpiochip->irqdomain = irq_domain_add_simple(of_node,
gpiochip->ngpio, first_irq,
&gpiochip_domain_ops, gpiochip);
if (!gpiochip->irqdomain) {
gpiochip->irqchip = NULL;
return -EINVAL;
}
irqchip->irq_request_resources = gpiochip_irq_reqres;
irqchip->irq_release_resources = gpiochip_irq_relres;
for (offset = 0; offset < gpiochip->ngpio; offset++) {
irq_base = irq_create_mapping(gpiochip->irqdomain, offset);
if (offset == 0)
gpiochip->irq_base = irq_base;
}
acpi_gpiochip_request_interrupts(gpiochip);
return 0;
}
static void gpiochip_irqchip_remove(struct gpio_chip *gpiochip) {}
int gpiochip_add_pingroup_range(struct gpio_chip *chip,
struct pinctrl_dev *pctldev,
unsigned int gpio_offset, const char *pin_group)
{
struct gpio_pin_range *pin_range;
int ret;
pin_range = kzalloc(sizeof(*pin_range), GFP_KERNEL);
if (!pin_range) {
chip_err(chip, "failed to allocate pin ranges\n");
return -ENOMEM;
}
pin_range->range.id = gpio_offset;
pin_range->range.gc = chip;
pin_range->range.name = chip->label;
pin_range->range.base = chip->base + gpio_offset;
pin_range->pctldev = pctldev;
ret = pinctrl_get_group_pins(pctldev, pin_group,
&pin_range->range.pins,
&pin_range->range.npins);
if (ret < 0) {
kfree(pin_range);
return ret;
}
pinctrl_add_gpio_range(pctldev, &pin_range->range);
chip_dbg(chip, "created GPIO range %d->%d ==> %s PINGRP %s\n",
gpio_offset, gpio_offset + pin_range->range.npins - 1,
pinctrl_dev_get_devname(pctldev), pin_group);
list_add_tail(&pin_range->node, &chip->pin_ranges);
return 0;
}
int gpiochip_add_pin_range(struct gpio_chip *chip, const char *pinctl_name,
unsigned int gpio_offset, unsigned int pin_offset,
unsigned int npins)
{
struct gpio_pin_range *pin_range;
int ret;
pin_range = kzalloc(sizeof(*pin_range), GFP_KERNEL);
if (!pin_range) {
chip_err(chip, "failed to allocate pin ranges\n");
return -ENOMEM;
}
pin_range->range.id = gpio_offset;
pin_range->range.gc = chip;
pin_range->range.name = chip->label;
pin_range->range.base = chip->base + gpio_offset;
pin_range->range.pin_base = pin_offset;
pin_range->range.npins = npins;
pin_range->pctldev = pinctrl_find_and_add_gpio_range(pinctl_name,
&pin_range->range);
if (IS_ERR(pin_range->pctldev)) {
ret = PTR_ERR(pin_range->pctldev);
chip_err(chip, "could not create pin range\n");
kfree(pin_range);
return ret;
}
chip_dbg(chip, "created GPIO range %d->%d ==> %s PIN %d->%d\n",
gpio_offset, gpio_offset + npins - 1,
pinctl_name,
pin_offset, pin_offset + npins - 1);
list_add_tail(&pin_range->node, &chip->pin_ranges);
return 0;
}
void gpiochip_remove_pin_ranges(struct gpio_chip *chip)
{
struct gpio_pin_range *pin_range, *tmp;
list_for_each_entry_safe(pin_range, tmp, &chip->pin_ranges, node) {
list_del(&pin_range->node);
pinctrl_remove_gpio_range(pin_range->pctldev,
&pin_range->range);
kfree(pin_range);
}
}
static int __gpiod_request(struct gpio_desc *desc, const char *label)
{
struct gpio_chip *chip = desc->chip;
int status;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
if (test_and_set_bit(FLAG_REQUESTED, &desc->flags) == 0) {
desc_set_label(desc, label ? : "?");
status = 0;
} else {
status = -EBUSY;
goto done;
}
if (chip->request) {
spin_unlock_irqrestore(&gpio_lock, flags);
status = chip->request(chip, gpio_chip_hwgpio(desc));
spin_lock_irqsave(&gpio_lock, flags);
if (status < 0) {
desc_set_label(desc, NULL);
clear_bit(FLAG_REQUESTED, &desc->flags);
goto done;
}
}
if (chip->get_direction) {
spin_unlock_irqrestore(&gpio_lock, flags);
gpiod_get_direction(desc);
spin_lock_irqsave(&gpio_lock, flags);
}
done:
spin_unlock_irqrestore(&gpio_lock, flags);
return status;
}
int gpiod_request(struct gpio_desc *desc, const char *label)
{
int status = -EPROBE_DEFER;
struct gpio_chip *chip;
if (!desc) {
pr_warn("%s: invalid GPIO\n", __func__);
return -EINVAL;
}
chip = desc->chip;
if (!chip)
goto done;
if (try_module_get(chip->owner)) {
status = __gpiod_request(desc, label);
if (status < 0)
module_put(chip->owner);
}
done:
if (status)
gpiod_dbg(desc, "%s: status %d\n", __func__, status);
return status;
}
static bool __gpiod_free(struct gpio_desc *desc)
{
bool ret = false;
unsigned long flags;
struct gpio_chip *chip;
might_sleep();
gpiod_unexport(desc);
spin_lock_irqsave(&gpio_lock, flags);
chip = desc->chip;
if (chip && test_bit(FLAG_REQUESTED, &desc->flags)) {
if (chip->free) {
spin_unlock_irqrestore(&gpio_lock, flags);
might_sleep_if(chip->can_sleep);
chip->free(chip, gpio_chip_hwgpio(desc));
spin_lock_irqsave(&gpio_lock, flags);
}
desc_set_label(desc, NULL);
clear_bit(FLAG_ACTIVE_LOW, &desc->flags);
clear_bit(FLAG_REQUESTED, &desc->flags);
clear_bit(FLAG_OPEN_DRAIN, &desc->flags);
clear_bit(FLAG_OPEN_SOURCE, &desc->flags);
ret = true;
}
spin_unlock_irqrestore(&gpio_lock, flags);
return ret;
}
void gpiod_free(struct gpio_desc *desc)
{
if (desc && __gpiod_free(desc))
module_put(desc->chip->owner);
else
WARN_ON(extra_checks);
}
const char *gpiochip_is_requested(struct gpio_chip *chip, unsigned offset)
{
struct gpio_desc *desc;
if (!GPIO_OFFSET_VALID(chip, offset))
return NULL;
desc = &chip->desc[offset];
if (test_bit(FLAG_REQUESTED, &desc->flags) == 0)
return NULL;
return desc->label;
}
struct gpio_desc *gpiochip_request_own_desc(struct gpio_chip *chip, u16 hwnum,
const char *label)
{
struct gpio_desc *desc = gpiochip_get_desc(chip, hwnum);
int err;
if (IS_ERR(desc)) {
chip_err(chip, "failed to get GPIO descriptor\n");
return desc;
}
err = __gpiod_request(desc, label);
if (err < 0)
return ERR_PTR(err);
return desc;
}
void gpiochip_free_own_desc(struct gpio_desc *desc)
{
if (desc)
__gpiod_free(desc);
}
int gpiod_direction_input(struct gpio_desc *desc)
{
struct gpio_chip *chip;
int status = -EINVAL;
if (!desc || !desc->chip) {
pr_warn("%s: invalid GPIO\n", __func__);
return -EINVAL;
}
chip = desc->chip;
if (!chip->get || !chip->direction_input) {
gpiod_warn(desc,
"%s: missing get() or direction_input() operations\n",
__func__);
return -EIO;
}
status = chip->direction_input(chip, gpio_chip_hwgpio(desc));
if (status == 0)
clear_bit(FLAG_IS_OUT, &desc->flags);
trace_gpio_direction(desc_to_gpio(desc), 1, status);
return status;
}
static int _gpiod_direction_output_raw(struct gpio_desc *desc, int value)
{
struct gpio_chip *chip;
int status = -EINVAL;
if (test_bit(FLAG_USED_AS_IRQ, &desc->flags)) {
gpiod_err(desc,
"%s: tried to set a GPIO tied to an IRQ as output\n",
__func__);
return -EIO;
}
if (value && test_bit(FLAG_OPEN_DRAIN, &desc->flags))
return gpiod_direction_input(desc);
if (!value && test_bit(FLAG_OPEN_SOURCE, &desc->flags))
return gpiod_direction_input(desc);
chip = desc->chip;
if (!chip->set || !chip->direction_output) {
gpiod_warn(desc,
"%s: missing set() or direction_output() operations\n",
__func__);
return -EIO;
}
status = chip->direction_output(chip, gpio_chip_hwgpio(desc), value);
if (status == 0)
set_bit(FLAG_IS_OUT, &desc->flags);
trace_gpio_value(desc_to_gpio(desc), 0, value);
trace_gpio_direction(desc_to_gpio(desc), 0, status);
return status;
}
int gpiod_direction_output_raw(struct gpio_desc *desc, int value)
{
if (!desc || !desc->chip) {
pr_warn("%s: invalid GPIO\n", __func__);
return -EINVAL;
}
return _gpiod_direction_output_raw(desc, value);
}
int gpiod_direction_output(struct gpio_desc *desc, int value)
{
if (!desc || !desc->chip) {
pr_warn("%s: invalid GPIO\n", __func__);
return -EINVAL;
}
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
return _gpiod_direction_output_raw(desc, value);
}
int gpiod_set_debounce(struct gpio_desc *desc, unsigned debounce)
{
struct gpio_chip *chip;
if (!desc || !desc->chip) {
pr_warn("%s: invalid GPIO\n", __func__);
return -EINVAL;
}
chip = desc->chip;
if (!chip->set || !chip->set_debounce) {
gpiod_dbg(desc,
"%s: missing set() or set_debounce() operations\n",
__func__);
return -ENOTSUPP;
}
return chip->set_debounce(chip, gpio_chip_hwgpio(desc), debounce);
}
int gpiod_is_active_low(const struct gpio_desc *desc)
{
return test_bit(FLAG_ACTIVE_LOW, &desc->flags);
}
static bool _gpiod_get_raw_value(const struct gpio_desc *desc)
{
struct gpio_chip *chip;
bool value;
int offset;
chip = desc->chip;
offset = gpio_chip_hwgpio(desc);
value = chip->get ? chip->get(chip, offset) : false;
trace_gpio_value(desc_to_gpio(desc), 1, value);
return value;
}
int gpiod_get_raw_value(const struct gpio_desc *desc)
{
if (!desc)
return 0;
WARN_ON(desc->chip->can_sleep);
return _gpiod_get_raw_value(desc);
}
int gpiod_get_value(const struct gpio_desc *desc)
{
int value;
if (!desc)
return 0;
WARN_ON(desc->chip->can_sleep);
value = _gpiod_get_raw_value(desc);
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
return value;
}
static void _gpio_set_open_drain_value(struct gpio_desc *desc, bool value)
{
int err = 0;
struct gpio_chip *chip = desc->chip;
int offset = gpio_chip_hwgpio(desc);
if (value) {
err = chip->direction_input(chip, offset);
if (!err)
clear_bit(FLAG_IS_OUT, &desc->flags);
} else {
err = chip->direction_output(chip, offset, 0);
if (!err)
set_bit(FLAG_IS_OUT, &desc->flags);
}
trace_gpio_direction(desc_to_gpio(desc), value, err);
if (err < 0)
gpiod_err(desc,
"%s: Error in set_value for open drain err %d\n",
__func__, err);
}
static void _gpio_set_open_source_value(struct gpio_desc *desc, bool value)
{
int err = 0;
struct gpio_chip *chip = desc->chip;
int offset = gpio_chip_hwgpio(desc);
if (value) {
err = chip->direction_output(chip, offset, 1);
if (!err)
set_bit(FLAG_IS_OUT, &desc->flags);
} else {
err = chip->direction_input(chip, offset);
if (!err)
clear_bit(FLAG_IS_OUT, &desc->flags);
}
trace_gpio_direction(desc_to_gpio(desc), !value, err);
if (err < 0)
gpiod_err(desc,
"%s: Error in set_value for open source err %d\n",
__func__, err);
}
static void _gpiod_set_raw_value(struct gpio_desc *desc, bool value)
{
struct gpio_chip *chip;
chip = desc->chip;
trace_gpio_value(desc_to_gpio(desc), 0, value);
if (test_bit(FLAG_OPEN_DRAIN, &desc->flags))
_gpio_set_open_drain_value(desc, value);
else if (test_bit(FLAG_OPEN_SOURCE, &desc->flags))
_gpio_set_open_source_value(desc, value);
else
chip->set(chip, gpio_chip_hwgpio(desc), value);
}
static void gpio_chip_set_multiple(struct gpio_chip *chip,
unsigned long *mask, unsigned long *bits)
{
if (chip->set_multiple) {
chip->set_multiple(chip, mask, bits);
} else {
int i;
for (i = 0; i < chip->ngpio; i++) {
if (mask[BIT_WORD(i)] == 0) {
i = (BIT_WORD(i) + 1) * BITS_PER_LONG - 1;
continue;
}
if (__test_and_clear_bit(i, mask)) {
chip->set(chip, i, test_bit(i, bits));
}
}
}
}
static void gpiod_set_array_priv(bool raw, bool can_sleep,
unsigned int array_size,
struct gpio_desc **desc_array,
int *value_array)
{
int i = 0;
while (i < array_size) {
struct gpio_chip *chip = desc_array[i]->chip;
unsigned long mask[BITS_TO_LONGS(chip->ngpio)];
unsigned long bits[BITS_TO_LONGS(chip->ngpio)];
int count = 0;
if (!can_sleep) {
WARN_ON(chip->can_sleep);
}
memset(mask, 0, sizeof(mask));
do {
struct gpio_desc *desc = desc_array[i];
int hwgpio = gpio_chip_hwgpio(desc);
int value = value_array[i];
if (!raw && test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
trace_gpio_value(desc_to_gpio(desc), 0, value);
if (test_bit(FLAG_OPEN_DRAIN, &desc->flags)) {
_gpio_set_open_drain_value(desc,value);
} else if (test_bit(FLAG_OPEN_SOURCE, &desc->flags)) {
_gpio_set_open_source_value(desc, value);
} else {
__set_bit(hwgpio, mask);
if (value) {
__set_bit(hwgpio, bits);
} else {
__clear_bit(hwgpio, bits);
}
count++;
}
i++;
} while ((i < array_size) && (desc_array[i]->chip == chip));
if (count != 0) {
gpio_chip_set_multiple(chip, mask, bits);
}
}
}
void gpiod_set_raw_value(struct gpio_desc *desc, int value)
{
if (!desc)
return;
WARN_ON(desc->chip->can_sleep);
_gpiod_set_raw_value(desc, value);
}
void gpiod_set_value(struct gpio_desc *desc, int value)
{
if (!desc)
return;
WARN_ON(desc->chip->can_sleep);
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
_gpiod_set_raw_value(desc, value);
}
void gpiod_set_raw_array(unsigned int array_size,
struct gpio_desc **desc_array, int *value_array)
{
if (!desc_array)
return;
gpiod_set_array_priv(true, false, array_size, desc_array, value_array);
}
void gpiod_set_array(unsigned int array_size,
struct gpio_desc **desc_array, int *value_array)
{
if (!desc_array)
return;
gpiod_set_array_priv(false, false, array_size, desc_array, value_array);
}
int gpiod_cansleep(const struct gpio_desc *desc)
{
if (!desc)
return 0;
return desc->chip->can_sleep;
}
int gpiod_to_irq(const struct gpio_desc *desc)
{
struct gpio_chip *chip;
int offset;
if (!desc)
return -EINVAL;
chip = desc->chip;
offset = gpio_chip_hwgpio(desc);
return chip->to_irq ? chip->to_irq(chip, offset) : -ENXIO;
}
int gpiochip_lock_as_irq(struct gpio_chip *chip, unsigned int offset)
{
if (offset >= chip->ngpio)
return -EINVAL;
if (test_bit(FLAG_IS_OUT, &chip->desc[offset].flags)) {
chip_err(chip,
"%s: tried to flag a GPIO set as output for IRQ\n",
__func__);
return -EIO;
}
set_bit(FLAG_USED_AS_IRQ, &chip->desc[offset].flags);
return 0;
}
void gpiochip_unlock_as_irq(struct gpio_chip *chip, unsigned int offset)
{
if (offset >= chip->ngpio)
return;
clear_bit(FLAG_USED_AS_IRQ, &chip->desc[offset].flags);
}
int gpiod_get_raw_value_cansleep(const struct gpio_desc *desc)
{
might_sleep_if(extra_checks);
if (!desc)
return 0;
return _gpiod_get_raw_value(desc);
}
int gpiod_get_value_cansleep(const struct gpio_desc *desc)
{
int value;
might_sleep_if(extra_checks);
if (!desc)
return 0;
value = _gpiod_get_raw_value(desc);
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
return value;
}
void gpiod_set_raw_value_cansleep(struct gpio_desc *desc, int value)
{
might_sleep_if(extra_checks);
if (!desc)
return;
_gpiod_set_raw_value(desc, value);
}
void gpiod_set_value_cansleep(struct gpio_desc *desc, int value)
{
might_sleep_if(extra_checks);
if (!desc)
return;
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
_gpiod_set_raw_value(desc, value);
}
void gpiod_set_raw_array_cansleep(unsigned int array_size,
struct gpio_desc **desc_array,
int *value_array)
{
might_sleep_if(extra_checks);
if (!desc_array)
return;
gpiod_set_array_priv(true, true, array_size, desc_array, value_array);
}
void gpiod_set_array_cansleep(unsigned int array_size,
struct gpio_desc **desc_array,
int *value_array)
{
might_sleep_if(extra_checks);
if (!desc_array)
return;
gpiod_set_array_priv(false, true, array_size, desc_array, value_array);
}
void gpiod_add_lookup_table(struct gpiod_lookup_table *table)
{
mutex_lock(&gpio_lookup_lock);
list_add_tail(&table->list, &gpio_lookup_list);
mutex_unlock(&gpio_lookup_lock);
}
static struct gpio_desc *of_find_gpio(struct device *dev, const char *con_id,
unsigned int idx,
enum gpio_lookup_flags *flags)
{
static const char *suffixes[] = { "gpios", "gpio" };
char prop_name[32];
enum of_gpio_flags of_flags;
struct gpio_desc *desc;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(suffixes); i++) {
if (con_id)
snprintf(prop_name, 32, "%s-%s", con_id, suffixes[i]);
else
snprintf(prop_name, 32, "%s", suffixes[i]);
desc = of_get_named_gpiod_flags(dev->of_node, prop_name, idx,
&of_flags);
if (!IS_ERR(desc) || (PTR_ERR(desc) == -EPROBE_DEFER))
break;
}
if (IS_ERR(desc))
return desc;
if (of_flags & OF_GPIO_ACTIVE_LOW)
*flags |= GPIO_ACTIVE_LOW;
return desc;
}
static struct gpio_desc *acpi_find_gpio(struct device *dev, const char *con_id,
unsigned int idx,
enum gpio_lookup_flags *flags)
{
static const char * const suffixes[] = { "gpios", "gpio" };
struct acpi_device *adev = ACPI_COMPANION(dev);
struct acpi_gpio_info info;
struct gpio_desc *desc;
char propname[32];
int i;
for (i = 0; i < ARRAY_SIZE(suffixes); i++) {
if (con_id && strcmp(con_id, "gpios")) {
snprintf(propname, sizeof(propname), "%s-%s",
con_id, suffixes[i]);
} else {
snprintf(propname, sizeof(propname), "%s",
suffixes[i]);
}
desc = acpi_get_gpiod_by_index(adev, propname, idx, &info);
if (!IS_ERR(desc) || (PTR_ERR(desc) == -EPROBE_DEFER))
break;
}
if (IS_ERR(desc)) {
desc = acpi_get_gpiod_by_index(adev, NULL, idx, &info);
if (IS_ERR(desc))
return desc;
}
if (info.active_low)
*flags |= GPIO_ACTIVE_LOW;
return desc;
}
static struct gpiod_lookup_table *gpiod_find_lookup_table(struct device *dev)
{
const char *dev_id = dev ? dev_name(dev) : NULL;
struct gpiod_lookup_table *table;
mutex_lock(&gpio_lookup_lock);
list_for_each_entry(table, &gpio_lookup_list, list) {
if (table->dev_id && dev_id) {
if (!strcmp(table->dev_id, dev_id))
goto found;
} else {
if (dev_id == table->dev_id)
goto found;
}
}
table = NULL;
found:
mutex_unlock(&gpio_lookup_lock);
return table;
}
static struct gpio_desc *gpiod_find(struct device *dev, const char *con_id,
unsigned int idx,
enum gpio_lookup_flags *flags)
{
struct gpio_desc *desc = ERR_PTR(-ENOENT);
struct gpiod_lookup_table *table;
struct gpiod_lookup *p;
table = gpiod_find_lookup_table(dev);
if (!table)
return desc;
for (p = &table->table[0]; p->chip_label; p++) {
struct gpio_chip *chip;
if (p->idx != idx)
continue;
if (p->con_id && (!con_id || strcmp(p->con_id, con_id)))
continue;
chip = find_chip_by_name(p->chip_label);
if (!chip) {
dev_err(dev, "cannot find GPIO chip %s\n",
p->chip_label);
return ERR_PTR(-ENODEV);
}
if (chip->ngpio <= p->chip_hwnum) {
dev_err(dev,
"requested GPIO %d is out of range [0..%d] for chip %s\n",
idx, chip->ngpio, chip->label);
return ERR_PTR(-EINVAL);
}
desc = gpiochip_get_desc(chip, p->chip_hwnum);
*flags = p->flags;
return desc;
}
return desc;
}
struct gpio_desc *__must_check __gpiod_get(struct device *dev, const char *con_id,
enum gpiod_flags flags)
{
return gpiod_get_index(dev, con_id, 0, flags);
}
struct gpio_desc *__must_check __gpiod_get_optional(struct device *dev,
const char *con_id,
enum gpiod_flags flags)
{
return gpiod_get_index_optional(dev, con_id, 0, flags);
}
struct gpio_desc *__must_check __gpiod_get_index(struct device *dev,
const char *con_id,
unsigned int idx,
enum gpiod_flags flags)
{
struct gpio_desc *desc = NULL;
int status;
enum gpio_lookup_flags lookupflags = 0;
dev_dbg(dev, "GPIO lookup for consumer %s\n", con_id);
if (IS_ENABLED(CONFIG_OF) && dev && dev->of_node) {
dev_dbg(dev, "using device tree for GPIO lookup\n");
desc = of_find_gpio(dev, con_id, idx, &lookupflags);
} else if (IS_ENABLED(CONFIG_ACPI) && dev && ACPI_HANDLE(dev)) {
dev_dbg(dev, "using ACPI for GPIO lookup\n");
desc = acpi_find_gpio(dev, con_id, idx, &lookupflags);
}
if (!desc || desc == ERR_PTR(-ENOENT)) {
dev_dbg(dev, "using lookup tables for GPIO lookup\n");
desc = gpiod_find(dev, con_id, idx, &lookupflags);
}
if (IS_ERR(desc)) {
dev_dbg(dev, "lookup for GPIO %s failed\n", con_id);
return desc;
}
status = gpiod_request(desc, con_id);
if (status < 0)
return ERR_PTR(status);
if (lookupflags & GPIO_ACTIVE_LOW)
set_bit(FLAG_ACTIVE_LOW, &desc->flags);
if (lookupflags & GPIO_OPEN_DRAIN)
set_bit(FLAG_OPEN_DRAIN, &desc->flags);
if (lookupflags & GPIO_OPEN_SOURCE)
set_bit(FLAG_OPEN_SOURCE, &desc->flags);
if (!(flags & GPIOD_FLAGS_BIT_DIR_SET))
return desc;
if (flags & GPIOD_FLAGS_BIT_DIR_OUT)
status = gpiod_direction_output(desc,
flags & GPIOD_FLAGS_BIT_DIR_VAL);
else
status = gpiod_direction_input(desc);
if (status < 0) {
dev_dbg(dev, "setup of GPIO %s failed\n", con_id);
gpiod_put(desc);
return ERR_PTR(status);
}
return desc;
}
struct gpio_desc *fwnode_get_named_gpiod(struct fwnode_handle *fwnode,
const char *propname)
{
struct gpio_desc *desc = ERR_PTR(-ENODEV);
bool active_low = false;
int ret;
if (!fwnode)
return ERR_PTR(-EINVAL);
if (is_of_node(fwnode)) {
enum of_gpio_flags flags;
desc = of_get_named_gpiod_flags(of_node(fwnode), propname, 0,
&flags);
if (!IS_ERR(desc))
active_low = flags & OF_GPIO_ACTIVE_LOW;
} else if (is_acpi_node(fwnode)) {
struct acpi_gpio_info info;
desc = acpi_get_gpiod_by_index(acpi_node(fwnode), propname, 0,
&info);
if (!IS_ERR(desc))
active_low = info.active_low;
}
if (IS_ERR(desc))
return desc;
ret = gpiod_request(desc, NULL);
if (ret)
return ERR_PTR(ret);
if (active_low)
set_bit(FLAG_ACTIVE_LOW, &desc->flags);
return desc;
}
struct gpio_desc *__must_check __gpiod_get_index_optional(struct device *dev,
const char *con_id,
unsigned int index,
enum gpiod_flags flags)
{
struct gpio_desc *desc;
desc = gpiod_get_index(dev, con_id, index, flags);
if (IS_ERR(desc)) {
if (PTR_ERR(desc) == -ENOENT)
return NULL;
}
return desc;
}
void gpiod_put(struct gpio_desc *desc)
{
gpiod_free(desc);
}
static void gpiolib_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
unsigned i;
unsigned gpio = chip->base;
struct gpio_desc *gdesc = &chip->desc[0];
int is_out;
int is_irq;
for (i = 0; i < chip->ngpio; i++, gpio++, gdesc++) {
if (!test_bit(FLAG_REQUESTED, &gdesc->flags))
continue;
gpiod_get_direction(gdesc);
is_out = test_bit(FLAG_IS_OUT, &gdesc->flags);
is_irq = test_bit(FLAG_USED_AS_IRQ, &gdesc->flags);
seq_printf(s, " gpio-%-3d (%-20.20s) %s %s %s",
gpio, gdesc->label,
is_out ? "out" : "in ",
chip->get
? (chip->get(chip, i) ? "hi" : "lo")
: "? ",
is_irq ? "IRQ" : " ");
seq_printf(s, "\n");
}
}
static void *gpiolib_seq_start(struct seq_file *s, loff_t *pos)
{
unsigned long flags;
struct gpio_chip *chip = NULL;
loff_t index = *pos;
s->private = "";
spin_lock_irqsave(&gpio_lock, flags);
list_for_each_entry(chip, &gpio_chips, list)
if (index-- == 0) {
spin_unlock_irqrestore(&gpio_lock, flags);
return chip;
}
spin_unlock_irqrestore(&gpio_lock, flags);
return NULL;
}
static void *gpiolib_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
unsigned long flags;
struct gpio_chip *chip = v;
void *ret = NULL;
spin_lock_irqsave(&gpio_lock, flags);
if (list_is_last(&chip->list, &gpio_chips))
ret = NULL;
else
ret = list_entry(chip->list.next, struct gpio_chip, list);
spin_unlock_irqrestore(&gpio_lock, flags);
s->private = "\n";
++*pos;
return ret;
}
static void gpiolib_seq_stop(struct seq_file *s, void *v)
{
}
static int gpiolib_seq_show(struct seq_file *s, void *v)
{
struct gpio_chip *chip = v;
struct device *dev;
seq_printf(s, "%sGPIOs %d-%d", (char *)s->private,
chip->base, chip->base + chip->ngpio - 1);
dev = chip->dev;
if (dev)
seq_printf(s, ", %s/%s", dev->bus ? dev->bus->name : "no-bus",
dev_name(dev));
if (chip->label)
seq_printf(s, ", %s", chip->label);
if (chip->can_sleep)
seq_printf(s, ", can sleep");
seq_printf(s, ":\n");
if (chip->dbg_show)
chip->dbg_show(s, chip);
else
gpiolib_dbg_show(s, chip);
return 0;
}
static int gpiolib_open(struct inode *inode, struct file *file)
{
return seq_open(file, &gpiolib_seq_ops);
}
static int __init gpiolib_debugfs_init(void)
{
(void) debugfs_create_file("gpio", S_IFREG | S_IRUGO,
NULL, NULL, &gpiolib_operations);
return 0;
}
