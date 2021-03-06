static int sur40_command(struct sur40_state *dev,\r\nu8 command, u16 index, void *buffer, u16 size)\r\n{\r\nreturn usb_control_msg(dev->usbdev, usb_rcvctrlpipe(dev->usbdev, 0),\r\ncommand,\r\nUSB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,\r\n0x00, index, buffer, size, 1000);\r\n}\r\nstatic int sur40_init(struct sur40_state *dev)\r\n{\r\nint result;\r\nu8 *buffer;\r\nbuffer = kmalloc(24, GFP_KERNEL);\r\nif (!buffer) {\r\nresult = -ENOMEM;\r\ngoto error;\r\n}\r\nresult = sur40_command(dev, SUR40_GET_VERSION, 0x00, buffer, 12);\r\nif (result < 0)\r\ngoto error;\r\nresult = sur40_command(dev, SUR40_GET_VERSION, 0x01, buffer, 12);\r\nif (result < 0)\r\ngoto error;\r\nresult = sur40_command(dev, SUR40_GET_VERSION, 0x02, buffer, 12);\r\nif (result < 0)\r\ngoto error;\r\nresult = sur40_command(dev, SUR40_UNKNOWN2, 0x00, buffer, 24);\r\nif (result < 0)\r\ngoto error;\r\nresult = sur40_command(dev, SUR40_UNKNOWN1, 0x00, buffer, 5);\r\nif (result < 0)\r\ngoto error;\r\nresult = sur40_command(dev, SUR40_GET_VERSION, 0x03, buffer, 12);\r\nerror:\r\nkfree(buffer);\r\nreturn result;\r\n}\r\nstatic void sur40_open(struct input_polled_dev *polldev)\r\n{\r\nstruct sur40_state *sur40 = polldev->private;\r\ndev_dbg(sur40->dev, "open\n");\r\nsur40_init(sur40);\r\n}\r\nstatic void sur40_close(struct input_polled_dev *polldev)\r\n{\r\nstruct sur40_state *sur40 = polldev->private;\r\ndev_dbg(sur40->dev, "close\n");\r\n}\r\nstatic void sur40_report_blob(struct sur40_blob *blob, struct input_dev *input)\r\n{\r\nint wide, major, minor;\r\nint bb_size_x = le16_to_cpu(blob->bb_size_x);\r\nint bb_size_y = le16_to_cpu(blob->bb_size_y);\r\nint pos_x = le16_to_cpu(blob->pos_x);\r\nint pos_y = le16_to_cpu(blob->pos_y);\r\nint ctr_x = le16_to_cpu(blob->ctr_x);\r\nint ctr_y = le16_to_cpu(blob->ctr_y);\r\nint slotnum = input_mt_get_slot_by_key(input, blob->blob_id);\r\nif (slotnum < 0 || slotnum >= MAX_CONTACTS)\r\nreturn;\r\ninput_mt_slot(input, slotnum);\r\ninput_mt_report_slot_state(input, MT_TOOL_FINGER, 1);\r\nwide = (bb_size_x > bb_size_y);\r\nmajor = max(bb_size_x, bb_size_y);\r\nminor = min(bb_size_x, bb_size_y);\r\ninput_report_abs(input, ABS_MT_POSITION_X, pos_x);\r\ninput_report_abs(input, ABS_MT_POSITION_Y, pos_y);\r\ninput_report_abs(input, ABS_MT_TOOL_X, ctr_x);\r\ninput_report_abs(input, ABS_MT_TOOL_Y, ctr_y);\r\ninput_report_abs(input, ABS_MT_ORIENTATION, wide);\r\ninput_report_abs(input, ABS_MT_TOUCH_MAJOR, major);\r\ninput_report_abs(input, ABS_MT_TOUCH_MINOR, minor);\r\n}\r\nstatic void sur40_poll(struct input_polled_dev *polldev)\r\n{\r\nstruct sur40_state *sur40 = polldev->private;\r\nstruct input_dev *input = polldev->input;\r\nint result, bulk_read, need_blobs, packet_blobs, i;\r\nu32 uninitialized_var(packet_id);\r\nstruct sur40_header *header = &sur40->bulk_in_buffer->header;\r\nstruct sur40_blob *inblob = &sur40->bulk_in_buffer->blobs[0];\r\ndev_dbg(sur40->dev, "poll\n");\r\nneed_blobs = -1;\r\ndo {\r\nresult = usb_bulk_msg(sur40->usbdev,\r\nusb_rcvbulkpipe(sur40->usbdev, sur40->bulk_in_epaddr),\r\nsur40->bulk_in_buffer, sur40->bulk_in_size,\r\n&bulk_read, 1000);\r\ndev_dbg(sur40->dev, "received %d bytes\n", bulk_read);\r\nif (result < 0) {\r\ndev_err(sur40->dev, "error in usb_bulk_read\n");\r\nreturn;\r\n}\r\nresult = bulk_read - sizeof(struct sur40_header);\r\nif (result % sizeof(struct sur40_blob) != 0) {\r\ndev_err(sur40->dev, "transfer size mismatch\n");\r\nreturn;\r\n}\r\nif (need_blobs == -1) {\r\nneed_blobs = le16_to_cpu(header->count);\r\ndev_dbg(sur40->dev, "need %d blobs\n", need_blobs);\r\npacket_id = le32_to_cpu(header->packet_id);\r\n}\r\nif (packet_id != header->packet_id)\r\ndev_dbg(sur40->dev, "packet ID mismatch\n");\r\npacket_blobs = result / sizeof(struct sur40_blob);\r\ndev_dbg(sur40->dev, "received %d blobs\n", packet_blobs);\r\nif (packet_blobs > need_blobs)\r\npacket_blobs = need_blobs;\r\nfor (i = 0; i < packet_blobs; i++) {\r\nneed_blobs--;\r\ndev_dbg(sur40->dev, "processing blob\n");\r\nsur40_report_blob(&(inblob[i]), input);\r\n}\r\n} while (need_blobs > 0);\r\ninput_mt_sync_frame(input);\r\ninput_sync(input);\r\nsur40_process_video(sur40);\r\n}\r\nstatic void sur40_process_video(struct sur40_state *sur40)\r\n{\r\nstruct sur40_image_header *img = (void *)(sur40->bulk_in_buffer);\r\nstruct sur40_buffer *new_buf;\r\nstruct usb_sg_request sgr;\r\nstruct sg_table *sgt;\r\nint result, bulk_read;\r\nif (!vb2_start_streaming_called(&sur40->queue))\r\nreturn;\r\nspin_lock(&sur40->qlock);\r\nif (list_empty(&sur40->buf_list)) {\r\ndev_dbg(sur40->dev, "buffer queue empty\n");\r\nspin_unlock(&sur40->qlock);\r\nreturn;\r\n}\r\nnew_buf = list_entry(sur40->buf_list.next, struct sur40_buffer, list);\r\nlist_del(&new_buf->list);\r\nspin_unlock(&sur40->qlock);\r\ndev_dbg(sur40->dev, "buffer acquired\n");\r\nresult = usb_bulk_msg(sur40->usbdev,\r\nusb_rcvbulkpipe(sur40->usbdev, VIDEO_ENDPOINT),\r\nsur40->bulk_in_buffer, sur40->bulk_in_size,\r\n&bulk_read, 1000);\r\nif (result < 0) {\r\ndev_err(sur40->dev, "error in usb_bulk_read\n");\r\ngoto err_poll;\r\n}\r\nif (bulk_read != sizeof(struct sur40_image_header)) {\r\ndev_err(sur40->dev, "received %d bytes (%zd expected)\n",\r\nbulk_read, sizeof(struct sur40_image_header));\r\ngoto err_poll;\r\n}\r\nif (le32_to_cpu(img->magic) != VIDEO_HEADER_MAGIC) {\r\ndev_err(sur40->dev, "image magic mismatch\n");\r\ngoto err_poll;\r\n}\r\nif (le32_to_cpu(img->size) != sur40_video_format.sizeimage) {\r\ndev_err(sur40->dev, "image size mismatch\n");\r\ngoto err_poll;\r\n}\r\ndev_dbg(sur40->dev, "header acquired\n");\r\nsgt = vb2_dma_sg_plane_desc(&new_buf->vb.vb2_buf, 0);\r\nresult = usb_sg_init(&sgr, sur40->usbdev,\r\nusb_rcvbulkpipe(sur40->usbdev, VIDEO_ENDPOINT), 0,\r\nsgt->sgl, sgt->nents, sur40_video_format.sizeimage, 0);\r\nif (result < 0) {\r\ndev_err(sur40->dev, "error %d in usb_sg_init\n", result);\r\ngoto err_poll;\r\n}\r\nusb_sg_wait(&sgr);\r\nif (sgr.status < 0) {\r\ndev_err(sur40->dev, "error %d in usb_sg_wait\n", sgr.status);\r\ngoto err_poll;\r\n}\r\ndev_dbg(sur40->dev, "image acquired\n");\r\nif (sur40->sequence == -1)\r\ngoto err_poll;\r\nnew_buf->vb.vb2_buf.timestamp = ktime_get_ns();\r\nnew_buf->vb.sequence = sur40->sequence++;\r\nnew_buf->vb.field = V4L2_FIELD_NONE;\r\nvb2_buffer_done(&new_buf->vb.vb2_buf, VB2_BUF_STATE_DONE);\r\ndev_dbg(sur40->dev, "buffer marked done\n");\r\nreturn;\r\nerr_poll:\r\nvb2_buffer_done(&new_buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);\r\n}\r\nstatic void sur40_input_setup(struct input_dev *input_dev)\r\n{\r\n__set_bit(EV_KEY, input_dev->evbit);\r\n__set_bit(EV_ABS, input_dev->evbit);\r\ninput_set_abs_params(input_dev, ABS_MT_POSITION_X,\r\n0, SENSOR_RES_X, 0, 0);\r\ninput_set_abs_params(input_dev, ABS_MT_POSITION_Y,\r\n0, SENSOR_RES_Y, 0, 0);\r\ninput_set_abs_params(input_dev, ABS_MT_TOOL_X,\r\n0, SENSOR_RES_X, 0, 0);\r\ninput_set_abs_params(input_dev, ABS_MT_TOOL_Y,\r\n0, SENSOR_RES_Y, 0, 0);\r\ninput_set_abs_params(input_dev, ABS_MT_TOUCH_MAJOR,\r\n0, SENSOR_RES_X, 0, 0);\r\ninput_set_abs_params(input_dev, ABS_MT_TOUCH_MINOR,\r\n0, SENSOR_RES_Y, 0, 0);\r\ninput_set_abs_params(input_dev, ABS_MT_ORIENTATION, 0, 1, 0, 0);\r\ninput_mt_init_slots(input_dev, MAX_CONTACTS,\r\nINPUT_MT_DIRECT | INPUT_MT_DROP_UNUSED);\r\n}\r\nstatic int sur40_probe(struct usb_interface *interface,\r\nconst struct usb_device_id *id)\r\n{\r\nstruct usb_device *usbdev = interface_to_usbdev(interface);\r\nstruct sur40_state *sur40;\r\nstruct usb_host_interface *iface_desc;\r\nstruct usb_endpoint_descriptor *endpoint;\r\nstruct input_polled_dev *poll_dev;\r\nint error;\r\niface_desc = &interface->altsetting[0];\r\nif (iface_desc->desc.bInterfaceClass != 0xFF)\r\nreturn -ENODEV;\r\nendpoint = &iface_desc->endpoint[4].desc;\r\nif (endpoint->bEndpointAddress != TOUCH_ENDPOINT)\r\nreturn -ENODEV;\r\nsur40 = kzalloc(sizeof(struct sur40_state), GFP_KERNEL);\r\nif (!sur40)\r\nreturn -ENOMEM;\r\npoll_dev = input_allocate_polled_device();\r\nif (!poll_dev) {\r\nerror = -ENOMEM;\r\ngoto err_free_dev;\r\n}\r\nINIT_LIST_HEAD(&sur40->buf_list);\r\nspin_lock_init(&sur40->qlock);\r\nmutex_init(&sur40->lock);\r\npoll_dev->private = sur40;\r\npoll_dev->poll_interval = POLL_INTERVAL;\r\npoll_dev->open = sur40_open;\r\npoll_dev->poll = sur40_poll;\r\npoll_dev->close = sur40_close;\r\nsur40_input_setup(poll_dev->input);\r\npoll_dev->input->name = DRIVER_LONG;\r\nusb_to_input_id(usbdev, &poll_dev->input->id);\r\nusb_make_path(usbdev, sur40->phys, sizeof(sur40->phys));\r\nstrlcat(sur40->phys, "/input0", sizeof(sur40->phys));\r\npoll_dev->input->phys = sur40->phys;\r\npoll_dev->input->dev.parent = &interface->dev;\r\nsur40->usbdev = usbdev;\r\nsur40->dev = &interface->dev;\r\nsur40->input = poll_dev;\r\nsur40->bulk_in_size = usb_endpoint_maxp(endpoint);\r\nsur40->bulk_in_epaddr = endpoint->bEndpointAddress;\r\nsur40->bulk_in_buffer = kmalloc(sur40->bulk_in_size, GFP_KERNEL);\r\nif (!sur40->bulk_in_buffer) {\r\ndev_err(&interface->dev, "Unable to allocate input buffer.");\r\nerror = -ENOMEM;\r\ngoto err_free_polldev;\r\n}\r\nerror = input_register_polled_device(poll_dev);\r\nif (error) {\r\ndev_err(&interface->dev,\r\n"Unable to register polled input device.");\r\ngoto err_free_buffer;\r\n}\r\nsnprintf(sur40->v4l2.name, sizeof(sur40->v4l2.name), "%s", DRIVER_LONG);\r\nerror = v4l2_device_register(sur40->dev, &sur40->v4l2);\r\nif (error) {\r\ndev_err(&interface->dev,\r\n"Unable to register video master device.");\r\ngoto err_unreg_v4l2;\r\n}\r\nsur40->queue = sur40_queue;\r\nsur40->queue.drv_priv = sur40;\r\nsur40->queue.lock = &sur40->lock;\r\nerror = vb2_queue_init(&sur40->queue);\r\nif (error)\r\ngoto err_unreg_v4l2;\r\nsur40->alloc_ctx = vb2_dma_sg_init_ctx(sur40->dev);\r\nif (IS_ERR(sur40->alloc_ctx)) {\r\ndev_err(sur40->dev, "Can't allocate buffer context");\r\nerror = PTR_ERR(sur40->alloc_ctx);\r\ngoto err_unreg_v4l2;\r\n}\r\nsur40->vdev = sur40_video_device;\r\nsur40->vdev.v4l2_dev = &sur40->v4l2;\r\nsur40->vdev.lock = &sur40->lock;\r\nsur40->vdev.queue = &sur40->queue;\r\nvideo_set_drvdata(&sur40->vdev, sur40);\r\nerror = video_register_device(&sur40->vdev, VFL_TYPE_GRABBER, -1);\r\nif (error) {\r\ndev_err(&interface->dev,\r\n"Unable to register video subdevice.");\r\ngoto err_unreg_video;\r\n}\r\nusb_set_intfdata(interface, sur40);\r\ndev_dbg(&interface->dev, "%s is now attached\n", DRIVER_DESC);\r\nreturn 0;\r\nerr_unreg_video:\r\nvideo_unregister_device(&sur40->vdev);\r\nerr_unreg_v4l2:\r\nv4l2_device_unregister(&sur40->v4l2);\r\nerr_free_buffer:\r\nkfree(sur40->bulk_in_buffer);\r\nerr_free_polldev:\r\ninput_free_polled_device(sur40->input);\r\nerr_free_dev:\r\nkfree(sur40);\r\nreturn error;\r\n}\r\nstatic void sur40_disconnect(struct usb_interface *interface)\r\n{\r\nstruct sur40_state *sur40 = usb_get_intfdata(interface);\r\nvideo_unregister_device(&sur40->vdev);\r\nv4l2_device_unregister(&sur40->v4l2);\r\nvb2_dma_sg_cleanup_ctx(sur40->alloc_ctx);\r\ninput_unregister_polled_device(sur40->input);\r\ninput_free_polled_device(sur40->input);\r\nkfree(sur40->bulk_in_buffer);\r\nkfree(sur40);\r\nusb_set_intfdata(interface, NULL);\r\ndev_dbg(&interface->dev, "%s is now disconnected\n", DRIVER_DESC);\r\n}\r\nstatic int sur40_queue_setup(struct vb2_queue *q,\r\nunsigned int *nbuffers, unsigned int *nplanes,\r\nunsigned int sizes[], void *alloc_ctxs[])\r\n{\r\nstruct sur40_state *sur40 = vb2_get_drv_priv(q);\r\nif (q->num_buffers + *nbuffers < 3)\r\n*nbuffers = 3 - q->num_buffers;\r\nalloc_ctxs[0] = sur40->alloc_ctx;\r\nif (*nplanes)\r\nreturn sizes[0] < sur40_video_format.sizeimage ? -EINVAL : 0;\r\n*nplanes = 1;\r\nsizes[0] = sur40_video_format.sizeimage;\r\nreturn 0;\r\n}\r\nstatic int sur40_buffer_prepare(struct vb2_buffer *vb)\r\n{\r\nstruct sur40_state *sur40 = vb2_get_drv_priv(vb->vb2_queue);\r\nunsigned long size = sur40_video_format.sizeimage;\r\nif (vb2_plane_size(vb, 0) < size) {\r\ndev_err(&sur40->usbdev->dev, "buffer too small (%lu < %lu)\n",\r\nvb2_plane_size(vb, 0), size);\r\nreturn -EINVAL;\r\n}\r\nvb2_set_plane_payload(vb, 0, size);\r\nreturn 0;\r\n}\r\nstatic void sur40_buffer_queue(struct vb2_buffer *vb)\r\n{\r\nstruct sur40_state *sur40 = vb2_get_drv_priv(vb->vb2_queue);\r\nstruct sur40_buffer *buf = (struct sur40_buffer *)vb;\r\nspin_lock(&sur40->qlock);\r\nlist_add_tail(&buf->list, &sur40->buf_list);\r\nspin_unlock(&sur40->qlock);\r\n}\r\nstatic void return_all_buffers(struct sur40_state *sur40,\r\nenum vb2_buffer_state state)\r\n{\r\nstruct sur40_buffer *buf, *node;\r\nspin_lock(&sur40->qlock);\r\nlist_for_each_entry_safe(buf, node, &sur40->buf_list, list) {\r\nvb2_buffer_done(&buf->vb.vb2_buf, state);\r\nlist_del(&buf->list);\r\n}\r\nspin_unlock(&sur40->qlock);\r\n}\r\nstatic int sur40_start_streaming(struct vb2_queue *vq, unsigned int count)\r\n{\r\nstruct sur40_state *sur40 = vb2_get_drv_priv(vq);\r\nsur40->sequence = 0;\r\nreturn 0;\r\n}\r\nstatic void sur40_stop_streaming(struct vb2_queue *vq)\r\n{\r\nstruct sur40_state *sur40 = vb2_get_drv_priv(vq);\r\nsur40->sequence = -1;\r\nreturn_all_buffers(sur40, VB2_BUF_STATE_ERROR);\r\n}\r\nstatic int sur40_vidioc_querycap(struct file *file, void *priv,\r\nstruct v4l2_capability *cap)\r\n{\r\nstruct sur40_state *sur40 = video_drvdata(file);\r\nstrlcpy(cap->driver, DRIVER_SHORT, sizeof(cap->driver));\r\nstrlcpy(cap->card, DRIVER_LONG, sizeof(cap->card));\r\nusb_make_path(sur40->usbdev, cap->bus_info, sizeof(cap->bus_info));\r\ncap->device_caps = V4L2_CAP_VIDEO_CAPTURE |\r\nV4L2_CAP_READWRITE |\r\nV4L2_CAP_STREAMING;\r\ncap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;\r\nreturn 0;\r\n}\r\nstatic int sur40_vidioc_enum_input(struct file *file, void *priv,\r\nstruct v4l2_input *i)\r\n{\r\nif (i->index != 0)\r\nreturn -EINVAL;\r\ni->type = V4L2_INPUT_TYPE_CAMERA;\r\ni->std = V4L2_STD_UNKNOWN;\r\nstrlcpy(i->name, "In-Cell Sensor", sizeof(i->name));\r\ni->capabilities = 0;\r\nreturn 0;\r\n}\r\nstatic int sur40_vidioc_s_input(struct file *file, void *priv, unsigned int i)\r\n{\r\nreturn (i == 0) ? 0 : -EINVAL;\r\n}\r\nstatic int sur40_vidioc_g_input(struct file *file, void *priv, unsigned int *i)\r\n{\r\n*i = 0;\r\nreturn 0;\r\n}\r\nstatic int sur40_vidioc_fmt(struct file *file, void *priv,\r\nstruct v4l2_format *f)\r\n{\r\nf->fmt.pix = sur40_video_format;\r\nreturn 0;\r\n}\r\nstatic int sur40_vidioc_enum_fmt(struct file *file, void *priv,\r\nstruct v4l2_fmtdesc *f)\r\n{\r\nif (f->index != 0)\r\nreturn -EINVAL;\r\nstrlcpy(f->description, "8-bit greyscale", sizeof(f->description));\r\nf->pixelformat = V4L2_PIX_FMT_GREY;\r\nf->flags = 0;\r\nreturn 0;\r\n}\r\nstatic int sur40_vidioc_enum_framesizes(struct file *file, void *priv,\r\nstruct v4l2_frmsizeenum *f)\r\n{\r\nif ((f->index != 0) || (f->pixel_format != V4L2_PIX_FMT_GREY))\r\nreturn -EINVAL;\r\nf->type = V4L2_FRMSIZE_TYPE_DISCRETE;\r\nf->discrete.width = sur40_video_format.width;\r\nf->discrete.height = sur40_video_format.height;\r\nreturn 0;\r\n}\r\nstatic int sur40_vidioc_enum_frameintervals(struct file *file, void *priv,\r\nstruct v4l2_frmivalenum *f)\r\n{\r\nif ((f->index > 1) || (f->pixel_format != V4L2_PIX_FMT_GREY)\r\n|| (f->width != sur40_video_format.width)\r\n|| (f->height != sur40_video_format.height))\r\nreturn -EINVAL;\r\nf->type = V4L2_FRMIVAL_TYPE_DISCRETE;\r\nf->discrete.denominator = 60/(f->index+1);\r\nf->discrete.numerator = 1;\r\nreturn 0;\r\n}
