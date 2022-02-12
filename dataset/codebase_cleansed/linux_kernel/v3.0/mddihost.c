void mddi_init(void)
{
if (mddi_host_initialized)
return;
mddi_host_initialized = TRUE;
sema_init(&mddi_host_mutex, 1);
if (!mddi_host_powered) {
down(&mddi_host_mutex);
mddi_host_init(MDDI_HOST_PRIM);
mddi_host_powered = TRUE;
up(&mddi_host_mutex);
mdelay(10);
}
}
int mddi_host_register_read(uint32 reg_addr,
uint32 *reg_value_ptr, boolean wait, mddi_host_type host) {
mddi_linked_list_type *curr_llist_ptr;
mddi_register_access_packet_type *regacc_pkt_ptr;
uint16 curr_llist_idx;
int ret = 0;
if (in_interrupt())
MDDI_MSG_CRIT("Called from ISR context\n");
if (!mddi_host_powered) {
MDDI_MSG_ERR("MDDI powered down!\n");
mddi_init();
}
down(&mddi_host_mutex);
mddi_reg_read_value_ptr = reg_value_ptr;
curr_llist_idx = mddi_get_reg_read_llist_item(host, TRUE);
if (curr_llist_idx == UNASSIGNED_INDEX) {
up(&mddi_host_mutex);
MDDI_MSG_ERR("Attempting to queue up more than 1 reg read\n");
return -EINVAL;
}
curr_llist_ptr = &llist_extern[host][curr_llist_idx];
curr_llist_ptr->link_controller_flags = 0x11;
curr_llist_ptr->packet_header_count = 14;
curr_llist_ptr->packet_data_count = 0;
curr_llist_ptr->next_packet_pointer = NULL;
curr_llist_ptr->packet_data_pointer = NULL;
curr_llist_ptr->reserved = 0;
regacc_pkt_ptr = &curr_llist_ptr->packet_header.register_pkt;
regacc_pkt_ptr->packet_length = curr_llist_ptr->packet_header_count;
regacc_pkt_ptr->packet_type = 146;
regacc_pkt_ptr->bClient_ID = 0;
regacc_pkt_ptr->read_write_info = 0x8001;
regacc_pkt_ptr->register_address = reg_addr;
mddi_queue_forward_packets(curr_llist_idx, curr_llist_idx, wait,
NULL, host);
up(&mddi_host_mutex);
if (wait) {
int wait_ret;
mddi_linked_list_notify_type *llist_notify_ptr;
llist_notify_ptr = &llist_extern_notify[host][curr_llist_idx];
wait_ret = wait_for_completion_timeout(
&(llist_notify_ptr->done_comp), 5 * HZ);
if (wait_ret <= 0)
ret = -EBUSY;
if (wait_ret < 0)
printk(KERN_ERR "%s: failed to wait for completion!\n",
__func__);
else if (!wait_ret)
printk(KERN_ERR "%s: Timed out waiting!\n", __func__);
}
MDDI_MSG_DEBUG("Reg Read value=0x%x\n", *reg_value_ptr);
return ret;
}
int mddi_host_register_write(uint32 reg_addr,
uint32 reg_val, enum mddi_data_packet_size_type packet_size,
boolean wait, mddi_llist_done_cb_type done_cb, mddi_host_type host) {
mddi_linked_list_type *curr_llist_ptr;
mddi_linked_list_type *curr_llist_dma_ptr;
mddi_register_access_packet_type *regacc_pkt_ptr;
uint16 curr_llist_idx;
int ret = 0;
if (in_interrupt())
MDDI_MSG_CRIT("Called from ISR context\n");
if (!mddi_host_powered) {
MDDI_MSG_ERR("MDDI powered down!\n");
mddi_init();
}
down(&mddi_host_mutex);
curr_llist_idx = mddi_get_next_free_llist_item(host, TRUE);
curr_llist_ptr = &llist_extern[host][curr_llist_idx];
curr_llist_dma_ptr = &llist_dma_extern[host][curr_llist_idx];
curr_llist_ptr->link_controller_flags = 1;
curr_llist_ptr->packet_header_count = 14;
curr_llist_ptr->packet_data_count = 4;
curr_llist_ptr->next_packet_pointer = NULL;
curr_llist_ptr->reserved = 0;
regacc_pkt_ptr = &curr_llist_ptr->packet_header.register_pkt;
regacc_pkt_ptr->packet_length = curr_llist_ptr->packet_header_count +
(uint16)packet_size;
regacc_pkt_ptr->packet_type = 146;
regacc_pkt_ptr->bClient_ID = 0;
regacc_pkt_ptr->read_write_info = 0x0001;
regacc_pkt_ptr->register_address = reg_addr;
regacc_pkt_ptr->register_data_list = reg_val;
MDDI_MSG_DEBUG("Reg Access write reg=0x%x, value=0x%x\n",
regacc_pkt_ptr->register_address,
regacc_pkt_ptr->register_data_list);
regacc_pkt_ptr = &curr_llist_dma_ptr->packet_header.register_pkt;
curr_llist_ptr->packet_data_pointer =
(void *)(&regacc_pkt_ptr->register_data_list);
mddi_queue_forward_packets(curr_llist_idx, curr_llist_idx, wait,
done_cb, host);
up(&mddi_host_mutex);
if (wait) {
int wait_ret;
mddi_linked_list_notify_type *llist_notify_ptr;
llist_notify_ptr = &llist_extern_notify[host][curr_llist_idx];
wait_ret = wait_for_completion_timeout(
&(llist_notify_ptr->done_comp), 5 * HZ);
if (wait_ret <= 0)
ret = -EBUSY;
if (wait_ret < 0)
printk(KERN_ERR "%s: failed to wait for completion!\n",
__func__);
else if (!wait_ret)
printk(KERN_ERR "%s: Timed out waiting!\n", __func__);
}
return ret;
}
boolean mddi_host_register_read_int
(uint32 reg_addr, uint32 *reg_value_ptr, mddi_host_type host) {
mddi_linked_list_type *curr_llist_ptr;
mddi_register_access_packet_type *regacc_pkt_ptr;
uint16 curr_llist_idx;
if (!in_interrupt())
MDDI_MSG_CRIT("Called from TASK context\n");
if (!mddi_host_powered) {
MDDI_MSG_ERR("MDDI powered down!\n");
return FALSE;
}
if (down_trylock(&mddi_host_mutex) != 0)
return FALSE;
mddi_reg_read_value_ptr = reg_value_ptr;
curr_llist_idx = mddi_get_reg_read_llist_item(host, FALSE);
if (curr_llist_idx == UNASSIGNED_INDEX) {
up(&mddi_host_mutex);
return FALSE;
}
curr_llist_ptr = &llist_extern[host][curr_llist_idx];
curr_llist_ptr->link_controller_flags = 0x11;
curr_llist_ptr->packet_header_count = 14;
curr_llist_ptr->packet_data_count = 0;
curr_llist_ptr->next_packet_pointer = NULL;
curr_llist_ptr->packet_data_pointer = NULL;
curr_llist_ptr->reserved = 0;
regacc_pkt_ptr = &curr_llist_ptr->packet_header.register_pkt;
regacc_pkt_ptr->packet_length = curr_llist_ptr->packet_header_count;
regacc_pkt_ptr->packet_type = 146;
regacc_pkt_ptr->bClient_ID = 0;
regacc_pkt_ptr->read_write_info = 0x8001;
regacc_pkt_ptr->register_address = reg_addr;
mddi_queue_forward_packets(curr_llist_idx, curr_llist_idx, FALSE,
NULL, host);
up(&mddi_host_mutex);
return TRUE;
}
boolean mddi_host_register_write_int
(uint32 reg_addr,
uint32 reg_val, mddi_llist_done_cb_type done_cb, mddi_host_type host) {
mddi_linked_list_type *curr_llist_ptr;
mddi_linked_list_type *curr_llist_dma_ptr;
mddi_register_access_packet_type *regacc_pkt_ptr;
uint16 curr_llist_idx;
if (!in_interrupt())
MDDI_MSG_CRIT("Called from TASK context\n");
if (!mddi_host_powered) {
MDDI_MSG_ERR("MDDI powered down!\n");
return FALSE;
}
if (down_trylock(&mddi_host_mutex) != 0)
return FALSE;
curr_llist_idx = mddi_get_next_free_llist_item(host, FALSE);
if (curr_llist_idx == UNASSIGNED_INDEX) {
up(&mddi_host_mutex);
return FALSE;
}
curr_llist_ptr = &llist_extern[host][curr_llist_idx];
curr_llist_dma_ptr = &llist_dma_extern[host][curr_llist_idx];
curr_llist_ptr->link_controller_flags = 1;
curr_llist_ptr->packet_header_count = 14;
curr_llist_ptr->packet_data_count = 4;
curr_llist_ptr->next_packet_pointer = NULL;
curr_llist_ptr->reserved = 0;
regacc_pkt_ptr = &curr_llist_ptr->packet_header.register_pkt;
regacc_pkt_ptr->packet_length = curr_llist_ptr->packet_header_count + 4;
regacc_pkt_ptr->packet_type = 146;
regacc_pkt_ptr->bClient_ID = 0;
regacc_pkt_ptr->read_write_info = 0x0001;
regacc_pkt_ptr->register_address = reg_addr;
regacc_pkt_ptr->register_data_list = reg_val;
regacc_pkt_ptr = &curr_llist_dma_ptr->packet_header.register_pkt;
curr_llist_ptr->packet_data_pointer =
(void *)(&(regacc_pkt_ptr->register_data_list));
mddi_queue_forward_packets(curr_llist_idx, curr_llist_idx, FALSE,
done_cb, host);
up(&mddi_host_mutex);
return TRUE;
}
void mddi_wait(uint16 time_ms)
{
mdelay(time_ms);
}
void mddi_client_lcd_vsync_detected(boolean detected)
{
if (mddi_lcd.vsync_detected)
(*mddi_lcd.vsync_detected) (detected);
}
void mddi_window_adjust_ext(struct msm_fb_data_type *mfd,
uint16 x1,
uint16 x2,
uint16 y1,
uint16 y2, mddi_llist_done_cb_type done_cb)
{
#ifdef FEATURE_MDDI_HITACHI
if (mfd->panel.id == HITACHI)
mddi_hitachi_window_adjust(x1, x2, y1, y2);
#elif defined(FEATURE_MDDI_S6D0142)
if (mfd->panel.id == MDDI_LCD_S6D0142)
mddi_s6d0142_window_adjust(x1, x2, y1, y2, done_cb);
#else
(void)x1;
(void)x2;
(void)y1;
(void)y2;
(void)done_cb;
#endif
}
void mddi_window_adjust(struct msm_fb_data_type *mfd,
uint16 x1, uint16 x2, uint16 y1, uint16 y2)
{
mddi_window_adjust_ext(mfd, x1, x2, y1, y2, NULL);
}
