static void uas_do_work(struct work_struct *work)\r\n{\r\nstruct uas_cmd_info *cmdinfo;\r\nstruct uas_cmd_info *temp;\r\nstruct list_head list;\r\nint err;\r\nspin_lock_irq(&uas_work_lock);\r\nlist_replace_init(&uas_work_list, &list);\r\nspin_unlock_irq(&uas_work_lock);\r\nlist_for_each_entry_safe(cmdinfo, temp, &list, list) {\r\nstruct scsi_pointer *scp = (void *)cmdinfo;\r\nstruct scsi_cmnd *cmnd = container_of(scp,\r\nstruct scsi_cmnd, SCp);\r\nerr = uas_submit_urbs(cmnd, cmnd->device->hostdata, GFP_NOIO);\r\nif (err) {\r\nlist_del(&cmdinfo->list);\r\nspin_lock_irq(&uas_work_lock);\r\nlist_add_tail(&cmdinfo->list, &uas_work_list);\r\nspin_unlock_irq(&uas_work_lock);\r\nschedule_work(&uas_work);\r\n}\r\n}\r\n}\r\nstatic void uas_sense(struct urb *urb, struct scsi_cmnd *cmnd)\r\n{\r\nstruct sense_iu *sense_iu = urb->transfer_buffer;\r\nstruct scsi_device *sdev = cmnd->device;\r\nstruct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;\r\nif (urb->actual_length > 16) {\r\nunsigned len = be16_to_cpup(&sense_iu->len);\r\nif (len + 16 != urb->actual_length) {\r\nint newlen = min(len + 16, urb->actual_length) - 16;\r\nif (newlen < 0)\r\nnewlen = 0;\r\nsdev_printk(KERN_INFO, sdev, "%s: urb length %d "\r\n"disagrees with IU sense data length %d, "\r\n"using %d bytes of sense data\n", __func__,\r\nurb->actual_length, len, newlen);\r\nlen = newlen;\r\n}\r\nmemcpy(cmnd->sense_buffer, sense_iu->sense, len);\r\n}\r\ncmnd->result = sense_iu->status;\r\nif (!(cmdinfo->state & DATA_COMPLETES_CMD))\r\ncmnd->scsi_done(cmnd);\r\n}\r\nstatic void uas_sense_old(struct urb *urb, struct scsi_cmnd *cmnd)\r\n{\r\nstruct sense_iu_old *sense_iu = urb->transfer_buffer;\r\nstruct scsi_device *sdev = cmnd->device;\r\nstruct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;\r\nif (urb->actual_length > 8) {\r\nunsigned len = be16_to_cpup(&sense_iu->len) - 2;\r\nif (len + 8 != urb->actual_length) {\r\nint newlen = min(len + 8, urb->actual_length) - 8;\r\nif (newlen < 0)\r\nnewlen = 0;\r\nsdev_printk(KERN_INFO, sdev, "%s: urb length %d "\r\n"disagrees with IU sense data length %d, "\r\n"using %d bytes of sense data\n", __func__,\r\nurb->actual_length, len, newlen);\r\nlen = newlen;\r\n}\r\nmemcpy(cmnd->sense_buffer, sense_iu->sense, len);\r\n}\r\ncmnd->result = sense_iu->status;\r\nif (!(cmdinfo->state & DATA_COMPLETES_CMD))\r\ncmnd->scsi_done(cmnd);\r\n}\r\nstatic void uas_xfer_data(struct urb *urb, struct scsi_cmnd *cmnd,\r\nunsigned direction)\r\n{\r\nstruct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;\r\nint err;\r\ncmdinfo->state = direction;\r\nerr = uas_submit_urbs(cmnd, cmnd->device->hostdata, GFP_ATOMIC);\r\nif (err) {\r\nspin_lock(&uas_work_lock);\r\nlist_add_tail(&cmdinfo->list, &uas_work_list);\r\nspin_unlock(&uas_work_lock);\r\nschedule_work(&uas_work);\r\n}\r\n}\r\nstatic void uas_stat_cmplt(struct urb *urb)\r\n{\r\nstruct iu *iu = urb->transfer_buffer;\r\nstruct Scsi_Host *shost = urb->context;\r\nstruct uas_dev_info *devinfo = (void *)shost->hostdata[0];\r\nstruct scsi_cmnd *cmnd;\r\nstruct uas_cmd_info *cmdinfo;\r\nu16 tag;\r\nint ret;\r\nif (urb->status) {\r\ndev_err(&urb->dev->dev, "URB BAD STATUS %d\n", urb->status);\r\nif (devinfo->use_streams)\r\nusb_free_urb(urb);\r\nreturn;\r\n}\r\ntag = be16_to_cpup(&iu->tag) - 1;\r\nif (tag == 0)\r\ncmnd = devinfo->cmnd;\r\nelse\r\ncmnd = scsi_host_find_tag(shost, tag - 1);\r\nif (!cmnd) {\r\nif (devinfo->use_streams) {\r\nusb_free_urb(urb);\r\nreturn;\r\n}\r\nret = usb_submit_urb(urb, GFP_ATOMIC);\r\nif (ret)\r\ndev_err(&urb->dev->dev, "failed submit status urb\n");\r\nreturn;\r\n}\r\ncmdinfo = (void *)&cmnd->SCp;\r\nswitch (iu->iu_id) {\r\ncase IU_ID_STATUS:\r\nif (devinfo->cmnd == cmnd)\r\ndevinfo->cmnd = NULL;\r\nif (!(cmdinfo->state & COMPLETED_DATA_IN) &&\r\ncmdinfo->data_in_urb) {\r\nif (devinfo->use_streams) {\r\ncmdinfo->state |= DATA_COMPLETES_CMD;\r\nusb_unlink_urb(cmdinfo->data_in_urb);\r\n} else {\r\nusb_free_urb(cmdinfo->data_in_urb);\r\n}\r\n}\r\nif (!(cmdinfo->state & COMPLETED_DATA_OUT) &&\r\ncmdinfo->data_out_urb) {\r\nif (devinfo->use_streams) {\r\ncmdinfo->state |= DATA_COMPLETES_CMD;\r\nusb_unlink_urb(cmdinfo->data_in_urb);\r\n} else {\r\nusb_free_urb(cmdinfo->data_out_urb);\r\n}\r\n}\r\nif (urb->actual_length < 16)\r\ndevinfo->uas_sense_old = 1;\r\nif (devinfo->uas_sense_old)\r\nuas_sense_old(urb, cmnd);\r\nelse\r\nuas_sense(urb, cmnd);\r\nbreak;\r\ncase IU_ID_READ_READY:\r\nuas_xfer_data(urb, cmnd, SUBMIT_DATA_IN_URB);\r\nbreak;\r\ncase IU_ID_WRITE_READY:\r\nuas_xfer_data(urb, cmnd, SUBMIT_DATA_OUT_URB);\r\nbreak;\r\ndefault:\r\nscmd_printk(KERN_ERR, cmnd,\r\n"Bogus IU (%d) received on status pipe\n", iu->iu_id);\r\n}\r\nif (devinfo->use_streams) {\r\nusb_free_urb(urb);\r\nreturn;\r\n}\r\nret = usb_submit_urb(urb, GFP_ATOMIC);\r\nif (ret)\r\ndev_err(&urb->dev->dev, "failed submit status urb\n");\r\n}\r\nstatic void uas_data_out_cmplt(struct urb *urb)\r\n{\r\nstruct scsi_cmnd *cmnd = urb->context;\r\nstruct scsi_data_buffer *sdb = scsi_out(cmnd);\r\nstruct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;\r\ncmdinfo->state |= COMPLETED_DATA_OUT;\r\nsdb->resid = sdb->length - urb->actual_length;\r\nusb_free_urb(urb);\r\nif (cmdinfo->state & DATA_COMPLETES_CMD)\r\ncmnd->scsi_done(cmnd);\r\n}\r\nstatic void uas_data_in_cmplt(struct urb *urb)\r\n{\r\nstruct scsi_cmnd *cmnd = urb->context;\r\nstruct scsi_data_buffer *sdb = scsi_in(cmnd);\r\nstruct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;\r\ncmdinfo->state |= COMPLETED_DATA_IN;\r\nsdb->resid = sdb->length - urb->actual_length;\r\nusb_free_urb(urb);\r\nif (cmdinfo->state & DATA_COMPLETES_CMD)\r\ncmnd->scsi_done(cmnd);\r\n}\r\nstatic struct urb *uas_alloc_data_urb(struct uas_dev_info *devinfo, gfp_t gfp,\r\nunsigned int pipe, struct scsi_cmnd *cmnd,\r\nenum dma_data_direction dir)\r\n{\r\nstruct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;\r\nstruct usb_device *udev = devinfo->udev;\r\nstruct urb *urb = usb_alloc_urb(0, gfp);\r\nstruct scsi_data_buffer *sdb;\r\nusb_complete_t complete_fn;\r\nu16 stream_id = cmdinfo->stream;\r\nif (!urb)\r\ngoto out;\r\nif (dir == DMA_FROM_DEVICE) {\r\nsdb = scsi_in(cmnd);\r\ncomplete_fn = uas_data_in_cmplt;\r\n} else {\r\nsdb = scsi_out(cmnd);\r\ncomplete_fn = uas_data_out_cmplt;\r\n}\r\nusb_fill_bulk_urb(urb, udev, pipe, NULL, sdb->length,\r\ncomplete_fn, cmnd);\r\nurb->stream_id = stream_id;\r\nurb->num_sgs = udev->bus->sg_tablesize ? sdb->table.nents : 0;\r\nurb->sg = sdb->table.sgl;\r\nout:\r\nreturn urb;\r\n}\r\nstatic struct urb *uas_alloc_sense_urb(struct uas_dev_info *devinfo, gfp_t gfp,\r\nstruct Scsi_Host *shost, u16 stream_id)\r\n{\r\nstruct usb_device *udev = devinfo->udev;\r\nstruct urb *urb = usb_alloc_urb(0, gfp);\r\nstruct sense_iu *iu;\r\nif (!urb)\r\ngoto out;\r\niu = kzalloc(sizeof(*iu), gfp);\r\nif (!iu)\r\ngoto free;\r\nusb_fill_bulk_urb(urb, udev, devinfo->status_pipe, iu, sizeof(*iu),\r\nuas_stat_cmplt, shost);\r\nurb->stream_id = stream_id;\r\nurb->transfer_flags |= URB_FREE_BUFFER;\r\nout:\r\nreturn urb;\r\nfree:\r\nusb_free_urb(urb);\r\nreturn NULL;\r\n}\r\nstatic struct urb *uas_alloc_cmd_urb(struct uas_dev_info *devinfo, gfp_t gfp,\r\nstruct scsi_cmnd *cmnd, u16 stream_id)\r\n{\r\nstruct usb_device *udev = devinfo->udev;\r\nstruct scsi_device *sdev = cmnd->device;\r\nstruct urb *urb = usb_alloc_urb(0, gfp);\r\nstruct command_iu *iu;\r\nint len;\r\nif (!urb)\r\ngoto out;\r\nlen = cmnd->cmd_len - 16;\r\nif (len < 0)\r\nlen = 0;\r\nlen = ALIGN(len, 4);\r\niu = kzalloc(sizeof(*iu) + len, gfp);\r\nif (!iu)\r\ngoto free;\r\niu->iu_id = IU_ID_COMMAND;\r\nif (blk_rq_tagged(cmnd->request))\r\niu->tag = cpu_to_be16(cmnd->request->tag + 2);\r\nelse\r\niu->tag = cpu_to_be16(1);\r\niu->prio_attr = UAS_SIMPLE_TAG;\r\niu->len = len;\r\nint_to_scsilun(sdev->lun, &iu->lun);\r\nmemcpy(iu->cdb, cmnd->cmnd, cmnd->cmd_len);\r\nusb_fill_bulk_urb(urb, udev, devinfo->cmd_pipe, iu, sizeof(*iu) + len,\r\nusb_free_urb, NULL);\r\nurb->transfer_flags |= URB_FREE_BUFFER;\r\nout:\r\nreturn urb;\r\nfree:\r\nusb_free_urb(urb);\r\nreturn NULL;\r\n}\r\nstatic int uas_submit_urbs(struct scsi_cmnd *cmnd,\r\nstruct uas_dev_info *devinfo, gfp_t gfp)\r\n{\r\nstruct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;\r\nif (cmdinfo->state & ALLOC_STATUS_URB) {\r\ncmdinfo->status_urb = uas_alloc_sense_urb(devinfo, gfp,\r\ncmnd->device->host, cmdinfo->stream);\r\nif (!cmdinfo->status_urb)\r\nreturn SCSI_MLQUEUE_DEVICE_BUSY;\r\ncmdinfo->state &= ~ALLOC_STATUS_URB;\r\n}\r\nif (cmdinfo->state & SUBMIT_STATUS_URB) {\r\nif (usb_submit_urb(cmdinfo->status_urb, gfp)) {\r\nscmd_printk(KERN_INFO, cmnd,\r\n"sense urb submission failure\n");\r\nreturn SCSI_MLQUEUE_DEVICE_BUSY;\r\n}\r\ncmdinfo->state &= ~SUBMIT_STATUS_URB;\r\n}\r\nif (cmdinfo->state & ALLOC_DATA_IN_URB) {\r\ncmdinfo->data_in_urb = uas_alloc_data_urb(devinfo, gfp,\r\ndevinfo->data_in_pipe, cmnd,\r\nDMA_FROM_DEVICE);\r\nif (!cmdinfo->data_in_urb)\r\nreturn SCSI_MLQUEUE_DEVICE_BUSY;\r\ncmdinfo->state &= ~ALLOC_DATA_IN_URB;\r\n}\r\nif (cmdinfo->state & SUBMIT_DATA_IN_URB) {\r\nif (usb_submit_urb(cmdinfo->data_in_urb, gfp)) {\r\nscmd_printk(KERN_INFO, cmnd,\r\n"data in urb submission failure\n");\r\nreturn SCSI_MLQUEUE_DEVICE_BUSY;\r\n}\r\ncmdinfo->state &= ~SUBMIT_DATA_IN_URB;\r\n}\r\nif (cmdinfo->state & ALLOC_DATA_OUT_URB) {\r\ncmdinfo->data_out_urb = uas_alloc_data_urb(devinfo, gfp,\r\ndevinfo->data_out_pipe, cmnd,\r\nDMA_TO_DEVICE);\r\nif (!cmdinfo->data_out_urb)\r\nreturn SCSI_MLQUEUE_DEVICE_BUSY;\r\ncmdinfo->state &= ~ALLOC_DATA_OUT_URB;\r\n}\r\nif (cmdinfo->state & SUBMIT_DATA_OUT_URB) {\r\nif (usb_submit_urb(cmdinfo->data_out_urb, gfp)) {\r\nscmd_printk(KERN_INFO, cmnd,\r\n"data out urb submission failure\n");\r\nreturn SCSI_MLQUEUE_DEVICE_BUSY;\r\n}\r\ncmdinfo->state &= ~SUBMIT_DATA_OUT_URB;\r\n}\r\nif (cmdinfo->state & ALLOC_CMD_URB) {\r\ncmdinfo->cmd_urb = uas_alloc_cmd_urb(devinfo, gfp, cmnd,\r\ncmdinfo->stream);\r\nif (!cmdinfo->cmd_urb)\r\nreturn SCSI_MLQUEUE_DEVICE_BUSY;\r\ncmdinfo->state &= ~ALLOC_CMD_URB;\r\n}\r\nif (cmdinfo->state & SUBMIT_CMD_URB) {\r\nif (usb_submit_urb(cmdinfo->cmd_urb, gfp)) {\r\nscmd_printk(KERN_INFO, cmnd,\r\n"cmd urb submission failure\n");\r\nreturn SCSI_MLQUEUE_DEVICE_BUSY;\r\n}\r\ncmdinfo->state &= ~SUBMIT_CMD_URB;\r\n}\r\nreturn 0;\r\n}\r\nstatic int uas_queuecommand_lck(struct scsi_cmnd *cmnd,\r\nvoid (*done)(struct scsi_cmnd *))\r\n{\r\nstruct scsi_device *sdev = cmnd->device;\r\nstruct uas_dev_info *devinfo = sdev->hostdata;\r\nstruct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;\r\nint err;\r\nBUILD_BUG_ON(sizeof(struct uas_cmd_info) > sizeof(struct scsi_pointer));\r\nif (devinfo->cmnd)\r\nreturn SCSI_MLQUEUE_DEVICE_BUSY;\r\nif (blk_rq_tagged(cmnd->request)) {\r\ncmdinfo->stream = cmnd->request->tag + 2;\r\n} else {\r\ndevinfo->cmnd = cmnd;\r\ncmdinfo->stream = 1;\r\n}\r\ncmnd->scsi_done = done;\r\ncmdinfo->state = ALLOC_STATUS_URB | SUBMIT_STATUS_URB |\r\nALLOC_CMD_URB | SUBMIT_CMD_URB;\r\nswitch (cmnd->sc_data_direction) {\r\ncase DMA_FROM_DEVICE:\r\ncmdinfo->state |= ALLOC_DATA_IN_URB | SUBMIT_DATA_IN_URB;\r\nbreak;\r\ncase DMA_BIDIRECTIONAL:\r\ncmdinfo->state |= ALLOC_DATA_IN_URB | SUBMIT_DATA_IN_URB;\r\ncase DMA_TO_DEVICE:\r\ncmdinfo->state |= ALLOC_DATA_OUT_URB | SUBMIT_DATA_OUT_URB;\r\ncase DMA_NONE:\r\nbreak;\r\n}\r\nif (!devinfo->use_streams) {\r\ncmdinfo->state &= ~(SUBMIT_DATA_IN_URB | SUBMIT_DATA_OUT_URB |\r\nALLOC_STATUS_URB | SUBMIT_STATUS_URB);\r\ncmdinfo->stream = 0;\r\n}\r\nerr = uas_submit_urbs(cmnd, devinfo, GFP_ATOMIC);\r\nif (err) {\r\nif (cmdinfo->state & SUBMIT_STATUS_URB) {\r\nusb_free_urb(cmdinfo->status_urb);\r\nreturn SCSI_MLQUEUE_DEVICE_BUSY;\r\n}\r\nspin_lock(&uas_work_lock);\r\nlist_add_tail(&cmdinfo->list, &uas_work_list);\r\nspin_unlock(&uas_work_lock);\r\nschedule_work(&uas_work);\r\n}\r\nreturn 0;\r\n}\r\nstatic int uas_eh_device_reset_handler(struct scsi_cmnd *cmnd)\r\n{\r\nstruct scsi_device *sdev = cmnd->device;\r\nsdev_printk(KERN_INFO, sdev, "%s tag %d\n", __func__,\r\ncmnd->request->tag);\r\nreturn FAILED;\r\n}\r\nstatic int uas_eh_target_reset_handler(struct scsi_cmnd *cmnd)\r\n{\r\nstruct scsi_device *sdev = cmnd->device;\r\nsdev_printk(KERN_INFO, sdev, "%s tag %d\n", __func__,\r\ncmnd->request->tag);\r\nreturn FAILED;\r\n}\r\nstatic int uas_eh_bus_reset_handler(struct scsi_cmnd *cmnd)\r\n{\r\nstruct scsi_device *sdev = cmnd->device;\r\nstruct uas_dev_info *devinfo = sdev->hostdata;\r\nstruct usb_device *udev = devinfo->udev;\r\nsdev_printk(KERN_INFO, sdev, "%s tag %d\n", __func__,\r\ncmnd->request->tag);\r\nif (usb_reset_device(udev))\r\nreturn SUCCESS;\r\nreturn FAILED;\r\n}\r\nstatic int uas_slave_alloc(struct scsi_device *sdev)\r\n{\r\nsdev->hostdata = (void *)sdev->host->hostdata[0];\r\nreturn 0;\r\n}\r\nstatic int uas_slave_configure(struct scsi_device *sdev)\r\n{\r\nstruct uas_dev_info *devinfo = sdev->hostdata;\r\nscsi_set_tag_type(sdev, MSG_ORDERED_TAG);\r\nscsi_activate_tcq(sdev, devinfo->qdepth - 2);\r\nreturn 0;\r\n}\r\nstatic int uas_is_interface(struct usb_host_interface *intf)\r\n{\r\nreturn (intf->desc.bInterfaceClass == USB_CLASS_MASS_STORAGE &&\r\nintf->desc.bInterfaceSubClass == USB_SC_SCSI &&\r\nintf->desc.bInterfaceProtocol == USB_PR_UAS);\r\n}\r\nstatic int uas_isnt_supported(struct usb_device *udev)\r\n{\r\nstruct usb_hcd *hcd = bus_to_hcd(udev->bus);\r\ndev_warn(&udev->dev, "The driver for the USB controller %s does not "\r\n"support scatter-gather which is\n",\r\nhcd->driver->description);\r\ndev_warn(&udev->dev, "required by the UAS driver. Please try an"\r\n"alternative USB controller if you wish to use UAS.\n");\r\nreturn -ENODEV;\r\n}\r\nstatic int uas_switch_interface(struct usb_device *udev,\r\nstruct usb_interface *intf)\r\n{\r\nint i;\r\nint sg_supported = udev->bus->sg_tablesize != 0;\r\nfor (i = 0; i < intf->num_altsetting; i++) {\r\nstruct usb_host_interface *alt = &intf->altsetting[i];\r\nif (uas_is_interface(alt)) {\r\nif (!sg_supported)\r\nreturn uas_isnt_supported(udev);\r\nreturn usb_set_interface(udev,\r\nalt->desc.bInterfaceNumber,\r\nalt->desc.bAlternateSetting);\r\n}\r\n}\r\nreturn -ENODEV;\r\n}\r\nstatic void uas_configure_endpoints(struct uas_dev_info *devinfo)\r\n{\r\nstruct usb_host_endpoint *eps[4] = { };\r\nstruct usb_interface *intf = devinfo->intf;\r\nstruct usb_device *udev = devinfo->udev;\r\nstruct usb_host_endpoint *endpoint = intf->cur_altsetting->endpoint;\r\nunsigned i, n_endpoints = intf->cur_altsetting->desc.bNumEndpoints;\r\ndevinfo->uas_sense_old = 0;\r\ndevinfo->cmnd = NULL;\r\nfor (i = 0; i < n_endpoints; i++) {\r\nunsigned char *extra = endpoint[i].extra;\r\nint len = endpoint[i].extralen;\r\nwhile (len > 1) {\r\nif (extra[1] == USB_DT_PIPE_USAGE) {\r\nunsigned pipe_id = extra[2];\r\nif (pipe_id > 0 && pipe_id < 5)\r\neps[pipe_id - 1] = &endpoint[i];\r\nbreak;\r\n}\r\nlen -= extra[0];\r\nextra += extra[0];\r\n}\r\n}\r\nif (!eps[0]) {\r\ndevinfo->cmd_pipe = usb_sndbulkpipe(udev, 1);\r\ndevinfo->status_pipe = usb_rcvbulkpipe(udev, 1);\r\ndevinfo->data_in_pipe = usb_rcvbulkpipe(udev, 2);\r\ndevinfo->data_out_pipe = usb_sndbulkpipe(udev, 2);\r\neps[1] = usb_pipe_endpoint(udev, devinfo->status_pipe);\r\neps[2] = usb_pipe_endpoint(udev, devinfo->data_in_pipe);\r\neps[3] = usb_pipe_endpoint(udev, devinfo->data_out_pipe);\r\n} else {\r\ndevinfo->cmd_pipe = usb_sndbulkpipe(udev,\r\neps[0]->desc.bEndpointAddress);\r\ndevinfo->status_pipe = usb_rcvbulkpipe(udev,\r\neps[1]->desc.bEndpointAddress);\r\ndevinfo->data_in_pipe = usb_rcvbulkpipe(udev,\r\neps[2]->desc.bEndpointAddress);\r\ndevinfo->data_out_pipe = usb_sndbulkpipe(udev,\r\neps[3]->desc.bEndpointAddress);\r\n}\r\ndevinfo->qdepth = usb_alloc_streams(devinfo->intf, eps + 1, 3, 256,\r\nGFP_KERNEL);\r\nif (devinfo->qdepth < 0) {\r\ndevinfo->qdepth = 256;\r\ndevinfo->use_streams = 0;\r\n} else {\r\ndevinfo->use_streams = 1;\r\n}\r\n}\r\nstatic int uas_alloc_status_urb(struct uas_dev_info *devinfo,\r\nstruct Scsi_Host *shost)\r\n{\r\nif (devinfo->use_streams) {\r\ndevinfo->status_urb = NULL;\r\nreturn 0;\r\n}\r\ndevinfo->status_urb = uas_alloc_sense_urb(devinfo, GFP_KERNEL,\r\nshost, 0);\r\nif (!devinfo->status_urb)\r\ngoto err_s_urb;\r\nif (usb_submit_urb(devinfo->status_urb, GFP_KERNEL))\r\ngoto err_submit_urb;\r\nreturn 0;\r\nerr_submit_urb:\r\nusb_free_urb(devinfo->status_urb);\r\nerr_s_urb:\r\nreturn -ENOMEM;\r\n}\r\nstatic void uas_free_streams(struct uas_dev_info *devinfo)\r\n{\r\nstruct usb_device *udev = devinfo->udev;\r\nstruct usb_host_endpoint *eps[3];\r\neps[0] = usb_pipe_endpoint(udev, devinfo->status_pipe);\r\neps[1] = usb_pipe_endpoint(udev, devinfo->data_in_pipe);\r\neps[2] = usb_pipe_endpoint(udev, devinfo->data_out_pipe);\r\nusb_free_streams(devinfo->intf, eps, 3, GFP_KERNEL);\r\n}\r\nstatic int uas_probe(struct usb_interface *intf, const struct usb_device_id *id)\r\n{\r\nint result;\r\nstruct Scsi_Host *shost;\r\nstruct uas_dev_info *devinfo;\r\nstruct usb_device *udev = interface_to_usbdev(intf);\r\nif (uas_switch_interface(udev, intf))\r\nreturn -ENODEV;\r\ndevinfo = kmalloc(sizeof(struct uas_dev_info), GFP_KERNEL);\r\nif (!devinfo)\r\nreturn -ENOMEM;\r\nresult = -ENOMEM;\r\nshost = scsi_host_alloc(&uas_host_template, sizeof(void *));\r\nif (!shost)\r\ngoto free;\r\nshost->max_cmd_len = 16 + 252;\r\nshost->max_id = 1;\r\nshost->sg_tablesize = udev->bus->sg_tablesize;\r\ndevinfo->intf = intf;\r\ndevinfo->udev = udev;\r\nuas_configure_endpoints(devinfo);\r\nresult = scsi_init_shared_tag_map(shost, devinfo->qdepth - 2);\r\nif (result)\r\ngoto free;\r\nresult = scsi_add_host(shost, &intf->dev);\r\nif (result)\r\ngoto deconfig_eps;\r\nshost->hostdata[0] = (unsigned long)devinfo;\r\nresult = uas_alloc_status_urb(devinfo, shost);\r\nif (result)\r\ngoto err_alloc_status;\r\nscsi_scan_host(shost);\r\nusb_set_intfdata(intf, shost);\r\nreturn result;\r\nerr_alloc_status:\r\nscsi_remove_host(shost);\r\nshost = NULL;\r\ndeconfig_eps:\r\nuas_free_streams(devinfo);\r\nfree:\r\nkfree(devinfo);\r\nif (shost)\r\nscsi_host_put(shost);\r\nreturn result;\r\n}\r\nstatic int uas_pre_reset(struct usb_interface *intf)\r\n{\r\nreturn 0;\r\n}\r\nstatic int uas_post_reset(struct usb_interface *intf)\r\n{\r\nreturn 0;\r\n}\r\nstatic void uas_disconnect(struct usb_interface *intf)\r\n{\r\nstruct Scsi_Host *shost = usb_get_intfdata(intf);\r\nstruct uas_dev_info *devinfo = (void *)shost->hostdata[0];\r\nscsi_remove_host(shost);\r\nusb_kill_urb(devinfo->status_urb);\r\nusb_free_urb(devinfo->status_urb);\r\nuas_free_streams(devinfo);\r\nkfree(devinfo);\r\n}
