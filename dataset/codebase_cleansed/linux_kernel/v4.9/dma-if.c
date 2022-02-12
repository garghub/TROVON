void ishtp_cl_alloc_dma_buf(struct ishtp_device *dev)
{
dma_addr_t h;
if (dev->ishtp_host_dma_tx_buf)
return;
dev->ishtp_host_dma_tx_buf_size = 1024*1024;
dev->ishtp_host_dma_rx_buf_size = 1024*1024;
dev->ishtp_host_dma_tx_buf = dma_alloc_coherent(dev->devc,
dev->ishtp_host_dma_tx_buf_size,
&h, GFP_KERNEL);
if (dev->ishtp_host_dma_tx_buf)
dev->ishtp_host_dma_tx_buf_phys = h;
dev->ishtp_dma_num_slots = dev->ishtp_host_dma_tx_buf_size /
DMA_SLOT_SIZE;
dev->ishtp_dma_tx_map = kcalloc(dev->ishtp_dma_num_slots,
sizeof(uint8_t),
GFP_KERNEL);
spin_lock_init(&dev->ishtp_dma_tx_lock);
dev->ishtp_host_dma_rx_buf = dma_alloc_coherent(dev->devc,
dev->ishtp_host_dma_rx_buf_size,
&h, GFP_KERNEL);
if (dev->ishtp_host_dma_rx_buf)
dev->ishtp_host_dma_rx_buf_phys = h;
}
void ishtp_cl_free_dma_buf(struct ishtp_device *dev)
{
dma_addr_t h;
if (dev->ishtp_host_dma_tx_buf) {
h = dev->ishtp_host_dma_tx_buf_phys;
dma_free_coherent(dev->devc, dev->ishtp_host_dma_tx_buf_size,
dev->ishtp_host_dma_tx_buf, h);
}
if (dev->ishtp_host_dma_rx_buf) {
h = dev->ishtp_host_dma_rx_buf_phys;
dma_free_coherent(dev->devc, dev->ishtp_host_dma_rx_buf_size,
dev->ishtp_host_dma_rx_buf, h);
}
kfree(dev->ishtp_dma_tx_map);
dev->ishtp_host_dma_tx_buf = NULL;
dev->ishtp_host_dma_rx_buf = NULL;
dev->ishtp_dma_tx_map = NULL;
}
void *ishtp_cl_get_dma_send_buf(struct ishtp_device *dev,
uint32_t size)
{
unsigned long flags;
int i, j, free;
int required_slots = (size / DMA_SLOT_SIZE)
+ 1 * (size % DMA_SLOT_SIZE != 0);
spin_lock_irqsave(&dev->ishtp_dma_tx_lock, flags);
for (i = 0; i <= (dev->ishtp_dma_num_slots - required_slots); i++) {
free = 1;
for (j = 0; j < required_slots; j++)
if (dev->ishtp_dma_tx_map[i+j]) {
free = 0;
i += j;
break;
}
if (free) {
for (j = 0; j < required_slots; j++)
dev->ishtp_dma_tx_map[i+j] = 1;
spin_unlock_irqrestore(&dev->ishtp_dma_tx_lock, flags);
return (i * DMA_SLOT_SIZE) +
(unsigned char *)dev->ishtp_host_dma_tx_buf;
}
}
spin_unlock_irqrestore(&dev->ishtp_dma_tx_lock, flags);
dev_err(dev->devc, "No free DMA buffer to send msg\n");
return NULL;
}
void ishtp_cl_release_dma_acked_mem(struct ishtp_device *dev,
void *msg_addr,
uint8_t size)
{
unsigned long flags;
int acked_slots = (size / DMA_SLOT_SIZE)
+ 1 * (size % DMA_SLOT_SIZE != 0);
int i, j;
if ((msg_addr - dev->ishtp_host_dma_tx_buf) % DMA_SLOT_SIZE) {
dev_err(dev->devc, "Bad DMA Tx ack address\n");
return;
}
i = (msg_addr - dev->ishtp_host_dma_tx_buf) / DMA_SLOT_SIZE;
spin_lock_irqsave(&dev->ishtp_dma_tx_lock, flags);
for (j = 0; j < acked_slots; j++) {
if ((i + j) >= dev->ishtp_dma_num_slots ||
!dev->ishtp_dma_tx_map[i+j]) {
spin_unlock_irqrestore(&dev->ishtp_dma_tx_lock, flags);
dev_err(dev->devc, "Bad DMA Tx ack address\n");
return;
}
dev->ishtp_dma_tx_map[i+j] = 0;
}
spin_unlock_irqrestore(&dev->ishtp_dma_tx_lock, flags);
}
