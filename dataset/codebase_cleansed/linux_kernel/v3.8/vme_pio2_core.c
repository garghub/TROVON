static int pio2_get_led(struct pio2_card *card)
{
return card->led;
}
static int pio2_set_led(struct pio2_card *card, int state)
{
u8 reg;
int retval;
reg = card->irq_level;
if (!state)
reg |= PIO2_LED;
if (loopback)
reg |= PIO2_LOOP;
retval = vme_master_write(card->window, &reg, 1, PIO2_REGS_CTRL);
if (retval < 0)
return retval;
card->led = state ? 1 : 0;
return 0;
}
static void pio2_int(int level, int vector, void *ptr)
{
int vec, i, channel, retval;
u8 reg;
struct pio2_card *card = ptr;
vec = vector & ~PIO2_VME_VECTOR_MASK;
switch (vec) {
case 0:
dev_warn(&card->vdev->dev, "Spurious Interrupt\n");
break;
case 1:
case 2:
case 3:
case 4:
retval = vme_master_read(card->window, &reg, 1,
PIO2_REGS_INT_STAT[vec - 1]);
if (retval < 0) {
dev_err(&card->vdev->dev,
"Unable to read IRQ status register\n");
return;
}
for (i = 0; i < 8; i++) {
channel = ((vec - 1) * 8) + i;
if (reg & PIO2_CHANNEL_BIT[channel])
dev_info(&card->vdev->dev,
"Interrupt on I/O channel %d\n",
channel);
}
break;
case 5:
case 6:
case 7:
case 8:
case 9:
case 10:
dev_err(&card->vdev->dev,
"Counter interrupt\n");
break;
}
}
static int pio2_reset_card(struct pio2_card *card)
{
int retval = 0;
u8 data = 0;
retval = vme_master_write(card->window, &data, 1, PIO2_REGS_CTRL);
if (retval < 0)
return retval;
retval = vme_master_write(card->window, &data, 1, PIO2_REGS_VME_VECTOR);
if (retval < 0)
return retval;
retval = pio2_gpio_reset(card);
if (retval < 0)
return retval;
retval = pio2_cntr_reset(card);
if (retval < 0)
return retval;
return 0;
}
static int __init pio2_init(void)
{
if (bus_num == 0) {
pr_err("No cards, skipping registration\n");
return -ENODEV;
}
if (bus_num > PIO2_CARDS_MAX) {
pr_err("Driver only able to handle %d PIO2 Cards\n",
PIO2_CARDS_MAX);
bus_num = PIO2_CARDS_MAX;
}
return vme_register_driver(&pio2_driver, bus_num);
}
static int pio2_match(struct vme_dev *vdev)
{
if (vdev->num >= bus_num) {
dev_err(&vdev->dev,
"The enumeration of the VMEbus to which the board is connected must be specified");
return 0;
}
if (vdev->num >= base_num) {
dev_err(&vdev->dev,
"The VME address for the cards registers must be specified");
return 0;
}
if (vdev->num >= vector_num) {
dev_err(&vdev->dev,
"The IRQ vector used by the card must be specified");
return 0;
}
if (vdev->num >= level_num) {
dev_err(&vdev->dev,
"The IRQ level used by the card must be specified");
return 0;
}
if (vdev->num >= variant_num) {
dev_err(&vdev->dev, "The variant of the card must be specified");
return 0;
}
return 1;
}
static int pio2_probe(struct vme_dev *vdev)
{
struct pio2_card *card;
int retval;
int i;
u8 reg;
int vec;
card = kzalloc(sizeof(struct pio2_card), GFP_KERNEL);
if (card == NULL) {
dev_err(&vdev->dev, "Unable to allocate card structure\n");
retval = -ENOMEM;
goto err_struct;
}
card->id = vdev->num;
card->bus = bus[card->id];
card->base = base[card->id];
card->irq_vector = vector[card->id];
card->irq_level = level[card->id] & PIO2_VME_INT_MASK;
strncpy(card->variant, variant[card->id], PIO2_VARIANT_LENGTH);
card->vdev = vdev;
for (i = 0; i < PIO2_VARIANT_LENGTH; i++) {
if (isdigit(card->variant[i]) == 0) {
dev_err(&card->vdev->dev, "Variant invalid\n");
retval = -EINVAL;
goto err_variant;
}
}
if (card->irq_vector & ~PIO2_VME_VECTOR_MASK) {
dev_err(&card->vdev->dev,
"Invalid VME IRQ Vector, vector must not use lower 4 bits\n");
retval = -EINVAL;
goto err_vector;
}
for (i = 1; i < PIO2_VARIANT_LENGTH; i++) {
switch (card->variant[i]) {
case '0':
card->bank[i-1].config = NOFIT;
break;
case '1':
case '2':
case '3':
case '4':
card->bank[i-1].config = INPUT;
break;
case '5':
card->bank[i-1].config = OUTPUT;
break;
case '6':
case '7':
case '8':
case '9':
card->bank[i-1].config = BOTH;
break;
}
}
card->window = vme_master_request(vdev, VME_A24, VME_SCT, VME_D16);
if (card->window == NULL) {
dev_err(&card->vdev->dev,
"Unable to assign VME master resource\n");
retval = -EIO;
goto err_window;
}
retval = vme_master_set(card->window, 1, card->base, 0x10000, VME_A24,
(VME_SCT | VME_USER | VME_DATA), VME_D16);
if (retval) {
dev_err(&card->vdev->dev,
"Unable to configure VME master resource\n");
goto err_set;
}
retval = vme_master_read(card->window, &reg, 1, PIO2_REGS_ID);
if (retval < 0) {
dev_err(&card->vdev->dev, "Unable to read from device\n");
goto err_read;
}
dev_dbg(&card->vdev->dev, "ID Register:%x\n", reg);
retval = pio2_reset_card(card);
if (retval) {
dev_err(&card->vdev->dev,
"Failed to reset card, is location valid?");
retval = -ENODEV;
goto err_reset;
}
reg = card->irq_level;
if (pio2_get_led(card))
reg |= PIO2_LED;
if (loopback)
reg |= PIO2_LOOP;
retval = vme_master_write(card->window, &reg, 1, PIO2_REGS_CTRL);
if (retval < 0)
return retval;
retval = vme_master_write(card->window, &card->irq_vector, 1,
PIO2_REGS_VME_VECTOR);
if (retval < 0)
return retval;
vec = card->irq_vector | PIO2_VME_VECTOR_SPUR;
retval = vme_irq_request(vdev, card->irq_level, vec,
&pio2_int, (void *)card);
if (retval < 0) {
dev_err(&card->vdev->dev,
"Unable to attach VME interrupt vector0x%x, level 0x%x\n",
vec, card->irq_level);
goto err_irq;
}
for (i = 0; i < 4; i++) {
vec = card->irq_vector | PIO2_VECTOR_BANK[i];
retval = vme_irq_request(vdev, card->irq_level, vec,
&pio2_int, (void *)card);
if (retval < 0) {
dev_err(&card->vdev->dev,
"Unable to attach VME interrupt vector0x%x, level 0x%x\n",
vec, card->irq_level);
goto err_gpio_irq;
}
}
for (i = 0; i < 6; i++) {
vec = card->irq_vector | PIO2_VECTOR_CNTR[i];
retval = vme_irq_request(vdev, card->irq_level, vec,
&pio2_int, (void *)card);
if (retval < 0) {
dev_err(&card->vdev->dev,
"Unable to attach VME interrupt vector0x%x, level 0x%x\n",
vec, card->irq_level);
goto err_cntr_irq;
}
}
retval = pio2_gpio_init(card);
if (retval < 0) {
dev_err(&card->vdev->dev,
"Unable to register with GPIO framework\n");
goto err_gpio;
}
retval = pio2_set_led(card, 0);
if (retval < 0) {
dev_err(&card->vdev->dev, "Unable to set LED\n");
goto err_led;
}
dev_set_drvdata(&card->vdev->dev, card);
dev_info(&card->vdev->dev,
"PIO2 (variant %s) configured at 0x%lx\n", card->variant,
card->base);
return 0;
err_led:
pio2_gpio_exit(card);
err_gpio:
i = 6;
err_cntr_irq:
while (i > 0) {
i--;
vec = card->irq_vector | PIO2_VECTOR_CNTR[i];
vme_irq_free(vdev, card->irq_level, vec);
}
i = 4;
err_gpio_irq:
while (i > 0) {
i--;
vec = card->irq_vector | PIO2_VECTOR_BANK[i];
vme_irq_free(vdev, card->irq_level, vec);
}
vec = (card->irq_vector & PIO2_VME_VECTOR_MASK) | PIO2_VME_VECTOR_SPUR;
vme_irq_free(vdev, card->irq_level, vec);
err_irq:
pio2_reset_card(card);
err_reset:
err_read:
vme_master_set(card->window, 0, 0, 0, VME_A16, 0, VME_D16);
err_set:
vme_master_free(card->window);
err_window:
err_vector:
err_variant:
kfree(card);
err_struct:
return retval;
}
static int pio2_remove(struct vme_dev *vdev)
{
int vec;
int i;
struct pio2_card *card = dev_get_drvdata(&vdev->dev);
pio2_gpio_exit(card);
for (i = 0; i < 6; i++) {
vec = card->irq_vector | PIO2_VECTOR_CNTR[i];
vme_irq_free(vdev, card->irq_level, vec);
}
for (i = 0; i < 4; i++) {
vec = card->irq_vector | PIO2_VECTOR_BANK[i];
vme_irq_free(vdev, card->irq_level, vec);
}
vec = (card->irq_vector & PIO2_VME_VECTOR_MASK) | PIO2_VME_VECTOR_SPUR;
vme_irq_free(vdev, card->irq_level, vec);
pio2_reset_card(card);
vme_master_set(card->window, 0, 0, 0, VME_A16, 0, VME_D16);
vme_master_free(card->window);
kfree(card);
return 0;
}
static void __exit pio2_exit(void)
{
vme_unregister_driver(&pio2_driver);
}
