static void switch_to_flash(struct async_state *state)
{
local_irq_save(state->irq_flags);
gpio_set_value(state->enet_flash_pin, 0);
state->save_ambctl0 = bfin_read_EBIU_AMBCTL0();
state->save_ambctl1 = bfin_read_EBIU_AMBCTL1();
bfin_write_EBIU_AMBCTL0(state->flash_ambctl0);
bfin_write_EBIU_AMBCTL1(state->flash_ambctl1);
SSYNC();
}
static void switch_back(struct async_state *state)
{
bfin_write_EBIU_AMBCTL0(state->save_ambctl0);
bfin_write_EBIU_AMBCTL1(state->save_ambctl1);
SSYNC();
gpio_set_value(state->enet_flash_pin, 1);
local_irq_restore(state->irq_flags);
}
static map_word bfin_flash_read(struct map_info *map, unsigned long ofs)
{
struct async_state *state = (struct async_state *)map->map_priv_1;
uint16_t word;
map_word test;
switch_to_flash(state);
word = readw(map->virt + ofs);
switch_back(state);
test.x[0] = word;
return test;
}
static void bfin_flash_copy_from(struct map_info *map, void *to, unsigned long from, ssize_t len)
{
struct async_state *state = (struct async_state *)map->map_priv_1;
switch_to_flash(state);
memcpy(to, map->virt + from, len);
switch_back(state);
}
static void bfin_flash_write(struct map_info *map, map_word d1, unsigned long ofs)
{
struct async_state *state = (struct async_state *)map->map_priv_1;
uint16_t d;
d = d1.x[0];
switch_to_flash(state);
writew(d, map->virt + ofs);
SSYNC();
switch_back(state);
}
static void bfin_flash_copy_to(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
struct async_state *state = (struct async_state *)map->map_priv_1;
switch_to_flash(state);
memcpy(map->virt + to, from, len);
SSYNC();
switch_back(state);
}
static int __devinit bfin_flash_probe(struct platform_device *pdev)
{
int ret;
struct physmap_flash_data *pdata = pdev->dev.platform_data;
struct resource *memory = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct resource *flash_ambctl = platform_get_resource(pdev, IORESOURCE_MEM, 1);
struct async_state *state;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return -ENOMEM;
state->map.name = DRIVER_NAME;
state->map.read = bfin_flash_read;
state->map.copy_from = bfin_flash_copy_from;
state->map.write = bfin_flash_write;
state->map.copy_to = bfin_flash_copy_to;
state->map.bankwidth = pdata->width;
state->map.size = memory->end - memory->start + 1;
state->map.virt = (void __iomem *)memory->start;
state->map.phys = memory->start;
state->map.map_priv_1 = (unsigned long)state;
state->enet_flash_pin = platform_get_irq(pdev, 0);
state->flash_ambctl0 = flash_ambctl->start;
state->flash_ambctl1 = flash_ambctl->end;
if (gpio_request(state->enet_flash_pin, DRIVER_NAME)) {
pr_devinit(KERN_ERR DRIVER_NAME ": Failed to request gpio %d\n", state->enet_flash_pin);
kfree(state);
return -EBUSY;
}
gpio_direction_output(state->enet_flash_pin, 1);
pr_devinit(KERN_NOTICE DRIVER_NAME ": probing %d-bit flash bus\n", state->map.bankwidth * 8);
state->mtd = do_map_probe(memory->name, &state->map);
if (!state->mtd) {
gpio_free(state->enet_flash_pin);
kfree(state);
return -ENXIO;
}
ret = parse_mtd_partitions(state->mtd, part_probe_types, &pdata->parts, 0);
if (ret > 0) {
pr_devinit(KERN_NOTICE DRIVER_NAME ": Using commandline partition definition\n");
mtd_device_register(state->mtd, pdata->parts, ret);
state->parts = pdata->parts;
} else if (pdata->nr_parts) {
pr_devinit(KERN_NOTICE DRIVER_NAME ": Using board partition definition\n");
mtd_device_register(state->mtd, pdata->parts, pdata->nr_parts);
} else {
pr_devinit(KERN_NOTICE DRIVER_NAME ": no partition info available, registering whole flash at once\n");
mtd_device_register(state->mtd, NULL, 0);
}
platform_set_drvdata(pdev, state);
return 0;
}
static int __devexit bfin_flash_remove(struct platform_device *pdev)
{
struct async_state *state = platform_get_drvdata(pdev);
gpio_free(state->enet_flash_pin);
mtd_device_unregister(state->mtd);
kfree(state->parts);
map_destroy(state->mtd);
kfree(state);
return 0;
}
static int __init bfin_flash_init(void)
{
return platform_driver_register(&bfin_flash_driver);
}
static void __exit bfin_flash_exit(void)
{
platform_driver_unregister(&bfin_flash_driver);
}
