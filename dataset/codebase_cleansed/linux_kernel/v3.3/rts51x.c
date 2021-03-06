static inline void usb_autopm_enable(struct usb_interface *intf)
{
atomic_set(&intf->pm_usage_cnt, 1);
usb_autopm_put_interface(intf);
}
static inline void usb_autopm_disable(struct usb_interface *intf)
{
atomic_set(&intf->pm_usage_cnt, 0);
usb_autopm_get_interface(intf);
}
void rts51x_try_to_enter_ss(struct rts51x_chip *chip)
{
RTS51X_DEBUGP("Ready to enter SS state\n");
usb_autopm_enable(chip->usb->pusb_intf);
}
void rts51x_try_to_exit_ss(struct rts51x_chip *chip)
{
RTS51X_DEBUGP("Exit from SS state\n");
usb_autopm_disable(chip->usb->pusb_intf);
}
int rts51x_suspend(struct usb_interface *iface, pm_message_t message)
{
struct rts51x_chip *chip = usb_get_intfdata(iface);
RTS51X_DEBUGP("%s, message.event = 0x%x\n", __func__, message.event);
mutex_lock(&chip->usb->dev_mutex);
chip->fake_card_ready = chip->card_ready;
rts51x_do_before_power_down(chip);
if (message.event == PM_EVENT_AUTO_SUSPEND) {
RTS51X_DEBUGP("Enter SS state");
chip->resume_from_scsi = 0;
RTS51X_SET_STAT(chip, STAT_SS);
} else {
RTS51X_DEBUGP("Enter SUSPEND state");
RTS51X_SET_STAT(chip, STAT_SUSPEND);
}
mutex_unlock(&chip->usb->dev_mutex);
return 0;
}
int rts51x_resume(struct usb_interface *iface)
{
struct rts51x_chip *chip = usb_get_intfdata(iface);
RTS51X_DEBUGP("%s\n", __func__);
if (!RTS51X_CHK_STAT(chip, STAT_SS) || !chip->resume_from_scsi) {
mutex_lock(&chip->usb->dev_mutex);
if (chip->option.ss_en) {
if (GET_PM_USAGE_CNT(chip) <= 0) {
RTS51X_DEBUGP("Incr pm_usage_cnt\n");
SET_PM_USAGE_CNT(chip, 1);
}
}
RTS51X_SET_STAT(chip, STAT_RUN);
rts51x_init_chip(chip);
rts51x_init_cards(chip);
mutex_unlock(&chip->usb->dev_mutex);
}
return 0;
}
int rts51x_reset_resume(struct usb_interface *iface)
{
struct rts51x_chip *chip = usb_get_intfdata(iface);
RTS51X_DEBUGP("%s\n", __func__);
mutex_lock(&chip->usb->dev_mutex);
RTS51X_SET_STAT(chip, STAT_RUN);
if (chip->option.ss_en)
SET_PM_USAGE_CNT(chip, 1);
rts51x_init_chip(chip);
rts51x_init_cards(chip);
mutex_unlock(&chip->usb->dev_mutex);
return 0;
}
void rts51x_try_to_enter_ss(struct rts51x_chip *chip)
{
}
void rts51x_try_to_exit_ss(struct rts51x_chip *chip)
{
}
int rts51x_pre_reset(struct usb_interface *iface)
{
struct rts51x_chip *chip = usb_get_intfdata(iface);
RTS51X_DEBUGP("%s\n", __func__);
mutex_lock(&chip->usb->dev_mutex);
return 0;
}
int rts51x_post_reset(struct usb_interface *iface)
{
struct rts51x_chip *chip = usb_get_intfdata(iface);
RTS51X_DEBUGP("%s\n", __func__);
mutex_unlock(&chip->usb->dev_mutex);
return 0;
}
static int rts51x_control_thread(void *__chip)
{
struct rts51x_chip *chip = (struct rts51x_chip *)__chip;
struct Scsi_Host *host = rts51x_to_host(chip);
for (;;) {
if (wait_for_completion_interruptible(&chip->usb->cmnd_ready))
break;
if (test_bit(FLIDX_DISCONNECTING, &chip->usb->dflags)) {
RTS51X_DEBUGP("-- exiting from rts51x-control\n");
break;
}
mutex_lock(&(chip->usb->dev_mutex));
scsi_lock(host);
if (chip->srb == NULL) {
scsi_unlock(host);
mutex_unlock(&chip->usb->dev_mutex);
RTS51X_DEBUGP("-- exiting from control thread\n");
break;
}
if (test_bit(FLIDX_TIMED_OUT, &chip->usb->dflags)) {
chip->srb->result = DID_ABORT << 16;
goto SkipForAbort;
}
scsi_unlock(host);
if (chip->srb->sc_data_direction == DMA_BIDIRECTIONAL) {
RTS51X_DEBUGP("UNKNOWN data direction\n");
chip->srb->result = DID_ERROR << 16;
}
else if (chip->srb->device->id) {
RTS51X_DEBUGP("Bad target number (%d:%d)\n",
chip->srb->device->id,
chip->srb->device->lun);
chip->srb->result = DID_BAD_TARGET << 16;
}
else if (chip->srb->device->lun > chip->max_lun) {
RTS51X_DEBUGP("Bad LUN (%d:%d)\n",
chip->srb->device->id,
chip->srb->device->lun);
chip->srb->result = DID_BAD_TARGET << 16;
}
else {
RTS51X_DEBUG(scsi_show_command(chip->srb));
rts51x_invoke_transport(chip->srb, chip);
}
scsi_lock(host);
if (chip->srb->result != DID_ABORT << 16)
chip->srb->scsi_done(chip->srb);
else
SkipForAbort :
RTS51X_DEBUGP("scsi command aborted\n");
if (test_bit(FLIDX_TIMED_OUT, &chip->usb->dflags)) {
complete(&(chip->usb->notify));
clear_bit(FLIDX_ABORTING, &chip->usb->dflags);
clear_bit(FLIDX_TIMED_OUT, &chip->usb->dflags);
}
chip->srb = NULL;
scsi_unlock(host);
mutex_unlock(&chip->usb->dev_mutex);
}
complete(&chip->usb->control_exit);
return 0;
}
static int rts51x_polling_thread(void *__chip)
{
struct rts51x_chip *chip = (struct rts51x_chip *)__chip;
#ifdef SCSI_SCAN_DELAY
wait_timeout((delay_use + 5) * HZ);
#endif
for (;;) {
wait_timeout(POLLING_INTERVAL);
if (test_bit(FLIDX_DISCONNECTING, &chip->usb->dflags)) {
RTS51X_DEBUGP("-- exiting from rts51x-polling\n");
break;
}
#ifdef CONFIG_PM
if (RTS51X_CHK_STAT(chip, STAT_SS) ||
RTS51X_CHK_STAT(chip, STAT_SS_PRE) ||
RTS51X_CHK_STAT(chip, STAT_SUSPEND)) {
continue;
}
if (ss_en) {
if (RTS51X_CHK_STAT(chip, STAT_IDLE)) {
if (chip->ss_counter <
(ss_delay * 1000 / POLLING_INTERVAL)) {
chip->ss_counter++;
} else {
RTS51X_SET_STAT(chip, STAT_SS_PRE);
rts51x_try_to_enter_ss(chip);
continue;
}
} else {
chip->ss_counter = 0;
}
}
#endif
mspro_polling_format_status(chip);
mutex_lock(&(chip->usb->dev_mutex));
rts51x_polling_func(chip);
mutex_unlock(&chip->usb->dev_mutex);
}
complete(&chip->usb->polling_exit);
return 0;
}
static int rts51x_scan_thread(void *__chip)
{
struct rts51x_chip *chip = (struct rts51x_chip *)__chip;
printk(KERN_DEBUG
"rts51x: device found at %d\n", chip->usb->pusb_dev->devnum);
set_freezable();
if (delay_use > 0) {
printk(KERN_DEBUG "rts51x: waiting for device "
"to settle before scanning\n");
wait_event_freezable_timeout(chip->usb->delay_wait,
test_bit(FLIDX_DONT_SCAN,
&chip->usb->dflags),
delay_use * HZ);
}
if (!test_bit(FLIDX_DONT_SCAN, &chip->usb->dflags)) {
scsi_scan_host(rts51x_to_host(chip));
printk(KERN_DEBUG "rts51x: device scan complete\n");
}
complete_and_exit(&chip->usb->scanning_done, 0);
}
static int associate_dev(struct rts51x_chip *chip, struct usb_interface *intf)
{
struct rts51x_usb *rts51x = chip->usb;
#ifdef SUPPORT_FILE_OP
int retval;
#endif
rts51x->pusb_dev = interface_to_usbdev(intf);
rts51x->pusb_intf = intf;
rts51x->ifnum = intf->cur_altsetting->desc.bInterfaceNumber;
RTS51X_DEBUGP("Vendor: 0x%04x, Product: 0x%04x, Revision: 0x%04x\n",
le16_to_cpu(rts51x->pusb_dev->descriptor.idVendor),
le16_to_cpu(rts51x->pusb_dev->descriptor.idProduct),
le16_to_cpu(rts51x->pusb_dev->descriptor.bcdDevice));
RTS51X_DEBUGP("Interface Subclass: 0x%02x, Protocol: 0x%02x\n",
intf->cur_altsetting->desc.bInterfaceSubClass,
intf->cur_altsetting->desc.bInterfaceProtocol);
usb_set_intfdata(intf, chip);
#ifdef SUPPORT_FILE_OP
retval = usb_register_dev(intf, &rts51x_class);
if (retval) {
RTS51X_DEBUGP("Not able to get a minor for this device.");
usb_set_intfdata(intf, NULL);
return -ENOMEM;
}
#endif
rts51x->cr = usb_buffer_alloc(rts51x->pusb_dev, sizeof(*rts51x->cr),
GFP_KERNEL, &rts51x->cr_dma);
if (!rts51x->cr) {
RTS51X_DEBUGP("usb_ctrlrequest allocation failed\n");
usb_set_intfdata(intf, NULL);
return -ENOMEM;
}
rts51x->iobuf = usb_buffer_alloc(rts51x->pusb_dev, RTS51X_IOBUF_SIZE,
GFP_KERNEL, &rts51x->iobuf_dma);
if (!rts51x->iobuf) {
RTS51X_DEBUGP("I/O buffer allocation failed\n");
usb_set_intfdata(intf, NULL);
return -ENOMEM;
}
return 0;
}
static void rts51x_init_options(struct rts51x_chip *chip)
{
struct rts51x_option *option = &(chip->option);
option->led_blink_speed = 7;
option->mspro_formatter_enable = 1;
option->fpga_sd_sdr104_clk = CLK_100;
option->fpga_sd_sdr50_clk = CLK_100;
option->fpga_sd_ddr50_clk = CLK_100;
option->fpga_sd_hs_clk = CLK_100;
option->fpga_mmc_52m_clk = CLK_80;
option->fpga_ms_hg_clk = CLK_80;
option->fpga_ms_4bit_clk = CLK_80;
option->asic_sd_sdr104_clk = 98;
option->asic_sd_sdr50_clk = 98;
option->asic_sd_ddr50_clk = 98;
option->asic_sd_hs_clk = 97;
option->asic_mmc_52m_clk = 95;
option->asic_ms_hg_clk = 116;
option->asic_ms_4bit_clk = 77;
option->sd_ddr_tx_phase = 0;
option->mmc_ddr_tx_phase = 1;
option->sd_speed_prior = 0;
option->sd_ctl =
SD_PUSH_POINT_AUTO | SD_SAMPLE_POINT_AUTO | SUPPORT_UHS50_MMC44;
option->ss_en = ss_en;
option->ss_delay = ss_delay;
option->needs_remote_wakeup = needs_remote_wakeup;
option->auto_delink_en = auto_delink_en;
option->FT2_fast_mode = 0;
option->pwr_delay = 800;
option->xd_rw_step = 0;
option->D3318_off_delay = 50;
option->delink_delay = 100;
option->rts5129_D3318_off_enable = 0;
option->sd20_pad_drive = 0;
option->reset_or_rw_fail_set_pad_drive = 1;
option->rcc_fail_flag = 0;
option->rcc_bug_fix_en = 1;
option->debounce_num = 2;
option->polling_time = 100;
option->led_toggle_interval = 6;
option->xd_rwn_step = 0;
option->sd_send_status_en = 0;
option->sdr50_tx_phase = 0x01;
option->sdr50_rx_phase = 0x05;
option->ddr50_tx_phase = 0x09;
option->ddr50_rx_phase = 0x06;
option->sdr50_phase_sel = 0;
option->sd30_pad_drive = 1;
option->ms_errreg_fix = 0;
option->reset_mmc_first = 0;
option->speed_mmc = 1;
option->led_always_on = 0;
}
static int get_pipes(struct rts51x_chip *chip)
{
struct rts51x_usb *rts51x = chip->usb;
struct usb_host_interface *altsetting =
rts51x->pusb_intf->cur_altsetting;
int i;
struct usb_endpoint_descriptor *ep;
struct usb_endpoint_descriptor *ep_in = NULL;
struct usb_endpoint_descriptor *ep_out = NULL;
struct usb_endpoint_descriptor *ep_int = NULL;
for (i = 0; i < altsetting->desc.bNumEndpoints; i++) {
ep = &altsetting->endpoint[i].desc;
if (usb_endpoint_xfer_bulk(ep)) {
if (usb_endpoint_dir_in(ep)) {
if (!ep_in)
ep_in = ep;
} else {
if (!ep_out)
ep_out = ep;
}
}
else if (usb_endpoint_is_int_in(ep)) {
if (!ep_int)
ep_int = ep;
}
}
if (!ep_in || !ep_out) {
RTS51X_DEBUGP("Endpoint sanity check failed!"
"Rejecting dev.\n");
return -EIO;
}
rts51x->send_ctrl_pipe = usb_sndctrlpipe(rts51x->pusb_dev, 0);
rts51x->recv_ctrl_pipe = usb_rcvctrlpipe(rts51x->pusb_dev, 0);
rts51x->send_bulk_pipe = usb_sndbulkpipe(rts51x->pusb_dev,
usb_endpoint_num(ep_out));
rts51x->recv_bulk_pipe = usb_rcvbulkpipe(rts51x->pusb_dev,
usb_endpoint_num(ep_in));
if (ep_int) {
rts51x->recv_intr_pipe = usb_rcvintpipe(rts51x->pusb_dev,
usb_endpoint_num
(ep_int));
rts51x->ep_bInterval = ep_int->bInterval;
}
return 0;
}
static int rts51x_acquire_resources(struct rts51x_chip *chip)
{
struct rts51x_usb *rts51x = chip->usb;
int retval;
rts51x->current_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!rts51x->current_urb) {
RTS51X_DEBUGP("URB allocation failed\n");
return -ENOMEM;
}
rts51x->intr_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!rts51x->intr_urb) {
RTS51X_DEBUGP("URB allocation failed\n");
return -ENOMEM;
}
chip->cmd_buf = chip->rsp_buf = rts51x->iobuf;
rts51x_init_options(chip);
retval = rts51x_init_chip(chip);
if (retval != STATUS_SUCCESS)
return -EIO;
return 0;
}
static void rts51x_release_resources(struct rts51x_chip *chip)
{
RTS51X_DEBUGP("-- %s\n", __func__);
RTS51X_DEBUGP("-- sending exit command to thread\n");
complete(&chip->usb->cmnd_ready);
if (chip->usb->ctl_thread)
wait_for_completion(&chip->usb->control_exit);
if (chip->usb->polling_thread)
wait_for_completion(&chip->usb->polling_exit);
wait_timeout(200);
rts51x_release_chip(chip);
usb_free_urb(chip->usb->current_urb);
usb_free_urb(chip->usb->intr_urb);
}
static void dissociate_dev(struct rts51x_chip *chip)
{
struct rts51x_usb *rts51x = chip->usb;
RTS51X_DEBUGP("-- %s\n", __func__);
if (rts51x->cr)
usb_buffer_free(rts51x->pusb_dev, sizeof(*rts51x->cr),
rts51x->cr, rts51x->cr_dma);
if (rts51x->iobuf)
usb_buffer_free(rts51x->pusb_dev, RTS51X_IOBUF_SIZE,
rts51x->iobuf, rts51x->iobuf_dma);
usb_set_intfdata(rts51x->pusb_intf, NULL);
#ifdef SUPPORT_FILE_OP
usb_deregister_dev(rts51x->pusb_intf, &rts51x_class);
#endif
kfree(rts51x);
chip->usb = NULL;
}
static void quiesce_and_remove_host(struct rts51x_chip *chip)
{
struct rts51x_usb *rts51x = chip->usb;
struct Scsi_Host *host = rts51x_to_host(chip);
if (rts51x->pusb_dev->state == USB_STATE_NOTATTACHED)
set_bit(FLIDX_DISCONNECTING, &rts51x->dflags);
#ifdef SCSI_SCAN_DELAY
set_bit(FLIDX_DONT_SCAN, &rts51x->dflags);
wake_up(&rts51x->delay_wait);
wait_for_completion(&rts51x->scanning_done);
#endif
scsi_remove_host(host);
scsi_lock(host);
set_bit(FLIDX_DISCONNECTING, &rts51x->dflags);
scsi_unlock(host);
#ifdef SCSI_SCAN_DELAY
wake_up(&rts51x->delay_wait);
#endif
}
static void release_everything(struct rts51x_chip *chip)
{
rts51x_release_resources(chip);
dissociate_dev(chip);
scsi_host_put(rts51x_to_host(chip));
}
static int rts51x_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct Scsi_Host *host;
struct rts51x_chip *chip;
struct rts51x_usb *rts51x;
int result;
struct task_struct *th;
RTS51X_DEBUGP("%s detected\n", RTS51X_NAME);
rts51x = kzalloc(sizeof(struct rts51x_usb), GFP_KERNEL);
if (!rts51x) {
printk(KERN_WARNING RTS51X_TIP
"Unable to allocate rts51x_usb\n");
return -ENOMEM;
}
host = scsi_host_alloc(&rts51x_host_template, sizeof(*chip));
if (!host) {
printk(KERN_WARNING RTS51X_TIP
"Unable to allocate the scsi host\n");
kfree(rts51x);
return -ENOMEM;
}
host->max_cmd_len = 16;
chip = host_to_rts51x(host);
memset(chip, 0, sizeof(struct rts51x_chip));
chip->vendor_id = id->idVendor;
chip->product_id = id->idProduct;
mutex_init(&(rts51x->dev_mutex));
init_completion(&rts51x->cmnd_ready);
init_completion(&rts51x->control_exit);
init_completion(&rts51x->polling_exit);
init_completion(&(rts51x->notify));
#ifdef SCSI_SCAN_DELAY
init_waitqueue_head(&rts51x->delay_wait);
init_completion(&rts51x->scanning_done);
#endif
chip->usb = rts51x;
result = associate_dev(chip, intf);
if (result)
goto BadDevice;
result = get_pipes(chip);
if (result)
goto BadDevice;
result = rts51x_acquire_resources(chip);
if (result)
goto BadDevice;
th = kthread_run(rts51x_control_thread, chip, RTS51X_CTL_THREAD);
if (IS_ERR(th)) {
printk(KERN_WARNING RTS51X_TIP
"Unable to start control thread\n");
result = PTR_ERR(th);
goto BadDevice;
}
rts51x->ctl_thread = th;
result = scsi_add_host(rts51x_to_host(chip), &rts51x->pusb_intf->dev);
if (result) {
printk(KERN_WARNING RTS51X_TIP "Unable to add the scsi host\n");
goto BadDevice;
}
#ifdef SCSI_SCAN_DELAY
th = kthread_create(rts51x_scan_thread, chip, RTS51X_SCAN_THREAD);
if (IS_ERR(th)) {
printk(KERN_WARNING RTS51X_TIP
"Unable to start the device-scanning thread\n");
complete(&rts51x->scanning_done);
quiesce_and_remove_host(chip);
result = PTR_ERR(th);
goto BadDevice;
}
wake_up_process(th);
#else
scsi_scan_host(rts51x_to_host(chip));
#endif
th = kthread_run(rts51x_polling_thread, chip, RTS51X_POLLING_THREAD);
if (IS_ERR(th)) {
printk(KERN_WARNING RTS51X_TIP
"Unable to start polling thread\n");
result = PTR_ERR(th);
goto BadDevice;
}
rts51x->polling_thread = th;
#ifdef CONFIG_PM
if (ss_en) {
rts51x->pusb_intf->needs_remote_wakeup = needs_remote_wakeup;
SET_PM_USAGE_CNT(chip, 1);
RTS51X_DEBUGP("pm_usage_cnt = %d\n", GET_PM_USAGE_CNT(chip));
}
#endif
return 0;
BadDevice:
RTS51X_DEBUGP("rts51x_probe() failed\n");
release_everything(chip);
return result;
}
static void rts51x_disconnect(struct usb_interface *intf)
{
struct rts51x_chip *chip = (struct rts51x_chip *)usb_get_intfdata(intf);
RTS51X_DEBUGP("rts51x_disconnect() called\n");
quiesce_and_remove_host(chip);
release_everything(chip);
}
