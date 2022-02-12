int rt2x00pci_regbusy_read(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
const struct rt2x00_field32 field,
u32 *reg)
{
unsigned int i;
if (!test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
return 0;
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2x00pci_register_read(rt2x00dev, offset, reg);
if (!rt2x00_get_field32(*reg, field))
return 1;
udelay(REGISTER_BUSY_DELAY);
}
printk_once(KERN_ERR "%s() Indirect register access failed: "
"offset=0x%.08x, value=0x%.08x\n", __func__, offset, *reg);
*reg = ~0;
return 0;
}
bool rt2x00pci_rxdone(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue = rt2x00dev->rx;
struct queue_entry *entry;
struct queue_entry_priv_pci *entry_priv;
struct skb_frame_desc *skbdesc;
int max_rx = 16;
while (--max_rx) {
entry = rt2x00queue_get_entry(queue, Q_INDEX);
entry_priv = entry->priv_data;
if (rt2x00dev->ops->lib->get_entry_state(entry))
break;
skbdesc = get_skb_frame_desc(entry->skb);
skbdesc->desc = entry_priv->desc;
skbdesc->desc_len = entry->queue->desc_size;
rt2x00lib_dmastart(entry);
rt2x00lib_dmadone(entry);
rt2x00lib_rxdone(entry, GFP_ATOMIC);
}
return !max_rx;
}
void rt2x00pci_flush_queue(struct data_queue *queue, bool drop)
{
unsigned int i;
for (i = 0; !rt2x00queue_empty(queue) && i < 10; i++)
msleep(10);
}
static int rt2x00pci_alloc_queue_dma(struct rt2x00_dev *rt2x00dev,
struct data_queue *queue)
{
struct queue_entry_priv_pci *entry_priv;
void *addr;
dma_addr_t dma;
unsigned int i;
addr = dma_alloc_coherent(rt2x00dev->dev,
queue->limit * queue->desc_size,
&dma, GFP_KERNEL);
if (!addr)
return -ENOMEM;
memset(addr, 0, queue->limit * queue->desc_size);
for (i = 0; i < queue->limit; i++) {
entry_priv = queue->entries[i].priv_data;
entry_priv->desc = addr + i * queue->desc_size;
entry_priv->desc_dma = dma + i * queue->desc_size;
}
return 0;
}
static void rt2x00pci_free_queue_dma(struct rt2x00_dev *rt2x00dev,
struct data_queue *queue)
{
struct queue_entry_priv_pci *entry_priv =
queue->entries[0].priv_data;
if (entry_priv->desc)
dma_free_coherent(rt2x00dev->dev,
queue->limit * queue->desc_size,
entry_priv->desc, entry_priv->desc_dma);
entry_priv->desc = NULL;
}
int rt2x00pci_initialize(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
int status;
queue_for_each(rt2x00dev, queue) {
status = rt2x00pci_alloc_queue_dma(rt2x00dev, queue);
if (status)
goto exit;
}
status = request_irq(rt2x00dev->irq,
rt2x00dev->ops->lib->irq_handler,
IRQF_SHARED, rt2x00dev->name, rt2x00dev);
if (status) {
ERROR(rt2x00dev, "IRQ %d allocation failed (error %d).\n",
rt2x00dev->irq, status);
goto exit;
}
return 0;
exit:
queue_for_each(rt2x00dev, queue)
rt2x00pci_free_queue_dma(rt2x00dev, queue);
return status;
}
void rt2x00pci_uninitialize(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
free_irq(rt2x00dev->irq, rt2x00dev);
queue_for_each(rt2x00dev, queue)
rt2x00pci_free_queue_dma(rt2x00dev, queue);
}
