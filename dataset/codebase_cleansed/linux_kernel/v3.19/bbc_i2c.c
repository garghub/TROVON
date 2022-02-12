static void set_device_claimage(struct bbc_i2c_bus *bp, struct platform_device *op, int val)
{
int i;
for (i = 0; i < NUM_CHILDREN; i++) {
if (bp->devs[i].device == op) {
bp->devs[i].client_claimed = val;
return;
}
}
}
struct platform_device *bbc_i2c_getdev(struct bbc_i2c_bus *bp, int index)
{
struct platform_device *op = NULL;
int curidx = 0, i;
for (i = 0; i < NUM_CHILDREN; i++) {
if (!(op = bp->devs[i].device))
break;
if (curidx == index)
goto out;
op = NULL;
curidx++;
}
out:
if (curidx == index)
return op;
return NULL;
}
struct bbc_i2c_client *bbc_i2c_attach(struct bbc_i2c_bus *bp, struct platform_device *op)
{
struct bbc_i2c_client *client;
const u32 *reg;
client = kzalloc(sizeof(*client), GFP_KERNEL);
if (!client)
return NULL;
client->bp = bp;
client->op = op;
reg = of_get_property(op->dev.of_node, "reg", NULL);
if (!reg) {
kfree(client);
return NULL;
}
client->bus = reg[0];
client->address = reg[1];
claim_device(bp, op);
return client;
}
void bbc_i2c_detach(struct bbc_i2c_client *client)
{
struct bbc_i2c_bus *bp = client->bp;
struct platform_device *op = client->op;
release_device(bp, op);
kfree(client);
}
static int wait_for_pin(struct bbc_i2c_bus *bp, u8 *status)
{
DECLARE_WAITQUEUE(wait, current);
int limit = 32;
int ret = 1;
bp->waiting = 1;
add_wait_queue(&bp->wq, &wait);
while (limit-- > 0) {
long val;
val = wait_event_interruptible_timeout(
bp->wq,
(((*status = readb(bp->i2c_control_regs + 0))
& I2C_PCF_PIN) == 0),
msecs_to_jiffies(250));
if (val > 0) {
ret = 0;
break;
}
}
remove_wait_queue(&bp->wq, &wait);
bp->waiting = 0;
return ret;
}
int bbc_i2c_writeb(struct bbc_i2c_client *client, unsigned char val, int off)
{
struct bbc_i2c_bus *bp = client->bp;
int address = client->address;
u8 status;
int ret = -1;
if (bp->i2c_bussel_reg != NULL)
writeb(client->bus, bp->i2c_bussel_reg);
writeb(address, bp->i2c_control_regs + 0x1);
writeb(I2C_PCF_START, bp->i2c_control_regs + 0x0);
if (wait_for_pin(bp, &status))
goto out;
writeb(off, bp->i2c_control_regs + 0x1);
if (wait_for_pin(bp, &status) ||
(status & I2C_PCF_LRB) != 0)
goto out;
writeb(val, bp->i2c_control_regs + 0x1);
if (wait_for_pin(bp, &status))
goto out;
ret = 0;
out:
writeb(I2C_PCF_STOP, bp->i2c_control_regs + 0x0);
return ret;
}
int bbc_i2c_readb(struct bbc_i2c_client *client, unsigned char *byte, int off)
{
struct bbc_i2c_bus *bp = client->bp;
unsigned char address = client->address, status;
int ret = -1;
if (bp->i2c_bussel_reg != NULL)
writeb(client->bus, bp->i2c_bussel_reg);
writeb(address, bp->i2c_control_regs + 0x1);
writeb(I2C_PCF_START, bp->i2c_control_regs + 0x0);
if (wait_for_pin(bp, &status))
goto out;
writeb(off, bp->i2c_control_regs + 0x1);
if (wait_for_pin(bp, &status) ||
(status & I2C_PCF_LRB) != 0)
goto out;
writeb(I2C_PCF_STOP, bp->i2c_control_regs + 0x0);
address |= 0x1;
writeb(address, bp->i2c_control_regs + 0x1);
writeb(I2C_PCF_START, bp->i2c_control_regs + 0x0);
if (wait_for_pin(bp, &status))
goto out;
(void) readb(bp->i2c_control_regs + 0x1);
if (wait_for_pin(bp, &status))
goto out;
writeb(I2C_PCF_ESO | I2C_PCF_ENI, bp->i2c_control_regs + 0x0);
*byte = readb(bp->i2c_control_regs + 0x1);
if (wait_for_pin(bp, &status))
goto out;
ret = 0;
out:
writeb(I2C_PCF_STOP, bp->i2c_control_regs + 0x0);
(void) readb(bp->i2c_control_regs + 0x1);
return ret;
}
int bbc_i2c_write_buf(struct bbc_i2c_client *client,
char *buf, int len, int off)
{
int ret = 0;
while (len > 0) {
ret = bbc_i2c_writeb(client, *buf, off);
if (ret < 0)
break;
len--;
buf++;
off++;
}
return ret;
}
int bbc_i2c_read_buf(struct bbc_i2c_client *client,
char *buf, int len, int off)
{
int ret = 0;
while (len > 0) {
ret = bbc_i2c_readb(client, buf, off);
if (ret < 0)
break;
len--;
buf++;
off++;
}
return ret;
}
static irqreturn_t bbc_i2c_interrupt(int irq, void *dev_id)
{
struct bbc_i2c_bus *bp = dev_id;
if (bp->waiting &&
!(readb(bp->i2c_control_regs + 0x0) & I2C_PCF_PIN))
wake_up_interruptible(&bp->wq);
return IRQ_HANDLED;
}
static void reset_one_i2c(struct bbc_i2c_bus *bp)
{
writeb(I2C_PCF_PIN, bp->i2c_control_regs + 0x0);
writeb(bp->own, bp->i2c_control_regs + 0x1);
writeb(I2C_PCF_PIN | I2C_PCF_ES1, bp->i2c_control_regs + 0x0);
writeb(bp->clock, bp->i2c_control_regs + 0x1);
writeb(I2C_PCF_IDLE, bp->i2c_control_regs + 0x0);
}
static struct bbc_i2c_bus * attach_one_i2c(struct platform_device *op, int index)
{
struct bbc_i2c_bus *bp;
struct device_node *dp;
int entry;
bp = kzalloc(sizeof(*bp), GFP_KERNEL);
if (!bp)
return NULL;
INIT_LIST_HEAD(&bp->temps);
INIT_LIST_HEAD(&bp->fans);
bp->i2c_control_regs = of_ioremap(&op->resource[0], 0, 0x2, "bbc_i2c_regs");
if (!bp->i2c_control_regs)
goto fail;
if (op->num_resources == 2) {
bp->i2c_bussel_reg = of_ioremap(&op->resource[1], 0, 0x1, "bbc_i2c_bussel");
if (!bp->i2c_bussel_reg)
goto fail;
}
bp->waiting = 0;
init_waitqueue_head(&bp->wq);
if (request_irq(op->archdata.irqs[0], bbc_i2c_interrupt,
IRQF_SHARED, "bbc_i2c", bp))
goto fail;
bp->index = index;
bp->op = op;
spin_lock_init(&bp->lock);
entry = 0;
for (dp = op->dev.of_node->child;
dp && entry < 8;
dp = dp->sibling, entry++) {
struct platform_device *child_op;
child_op = of_find_device_by_node(dp);
bp->devs[entry].device = child_op;
bp->devs[entry].client_claimed = 0;
}
writeb(I2C_PCF_PIN, bp->i2c_control_regs + 0x0);
bp->own = readb(bp->i2c_control_regs + 0x01);
writeb(I2C_PCF_PIN | I2C_PCF_ES1, bp->i2c_control_regs + 0x0);
bp->clock = readb(bp->i2c_control_regs + 0x01);
printk(KERN_INFO "i2c-%d: Regs at %p, %d devices, own %02x, clock %02x.\n",
bp->index, bp->i2c_control_regs, entry, bp->own, bp->clock);
reset_one_i2c(bp);
return bp;
fail:
if (bp->i2c_bussel_reg)
of_iounmap(&op->resource[1], bp->i2c_bussel_reg, 1);
if (bp->i2c_control_regs)
of_iounmap(&op->resource[0], bp->i2c_control_regs, 2);
kfree(bp);
return NULL;
}
static int bbc_i2c_probe(struct platform_device *op)
{
struct bbc_i2c_bus *bp;
int err, index = 0;
bp = attach_one_i2c(op, index);
if (!bp)
return -EINVAL;
err = bbc_envctrl_init(bp);
if (err) {
free_irq(op->archdata.irqs[0], bp);
if (bp->i2c_bussel_reg)
of_iounmap(&op->resource[0], bp->i2c_bussel_reg, 1);
if (bp->i2c_control_regs)
of_iounmap(&op->resource[1], bp->i2c_control_regs, 2);
kfree(bp);
} else {
dev_set_drvdata(&op->dev, bp);
}
return err;
}
static int bbc_i2c_remove(struct platform_device *op)
{
struct bbc_i2c_bus *bp = dev_get_drvdata(&op->dev);
bbc_envctrl_cleanup(bp);
free_irq(op->archdata.irqs[0], bp);
if (bp->i2c_bussel_reg)
of_iounmap(&op->resource[0], bp->i2c_bussel_reg, 1);
if (bp->i2c_control_regs)
of_iounmap(&op->resource[1], bp->i2c_control_regs, 2);
kfree(bp);
return 0;
}
