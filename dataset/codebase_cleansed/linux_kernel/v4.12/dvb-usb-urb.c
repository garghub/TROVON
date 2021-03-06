int dvb_usb_generic_rw(struct dvb_usb_device *d, u8 *wbuf, u16 wlen, u8 *rbuf,\r\nu16 rlen, int delay_ms)\r\n{\r\nint actlen,ret = -ENOMEM;\r\nif (!d || wbuf == NULL || wlen == 0)\r\nreturn -EINVAL;\r\nif (d->props.generic_bulk_ctrl_endpoint == 0) {\r\nerr("endpoint for generic control not specified.");\r\nreturn -EINVAL;\r\n}\r\nif ((ret = mutex_lock_interruptible(&d->usb_mutex)))\r\nreturn ret;\r\ndeb_xfer(">>> ");\r\ndebug_dump(wbuf,wlen,deb_xfer);\r\nret = usb_bulk_msg(d->udev,usb_sndbulkpipe(d->udev,\r\nd->props.generic_bulk_ctrl_endpoint), wbuf,wlen,&actlen,\r\n2000);\r\nif (ret)\r\nerr("bulk message failed: %d (%d/%d)",ret,wlen,actlen);\r\nelse\r\nret = actlen != wlen ? -1 : 0;\r\nif (!ret && rbuf && rlen) {\r\nif (delay_ms)\r\nmsleep(delay_ms);\r\nret = usb_bulk_msg(d->udev,usb_rcvbulkpipe(d->udev,\r\nd->props.generic_bulk_ctrl_endpoint_response ?\r\nd->props.generic_bulk_ctrl_endpoint_response :\r\nd->props.generic_bulk_ctrl_endpoint),rbuf,rlen,&actlen,\r\n2000);\r\nif (ret)\r\nerr("recv bulk message failed: %d",ret);\r\nelse {\r\ndeb_xfer("<<< ");\r\ndebug_dump(rbuf,actlen,deb_xfer);\r\n}\r\n}\r\nmutex_unlock(&d->usb_mutex);\r\nreturn ret;\r\n}\r\nint dvb_usb_generic_write(struct dvb_usb_device *d, u8 *buf, u16 len)\r\n{\r\nreturn dvb_usb_generic_rw(d,buf,len,NULL,0,0);\r\n}\r\nstatic void dvb_usb_data_complete(struct usb_data_stream *stream, u8 *buffer, size_t length)\r\n{\r\nstruct dvb_usb_adapter *adap = stream->user_priv;\r\nif (adap->feedcount > 0 && adap->state & DVB_USB_ADAP_STATE_DVB)\r\ndvb_dmx_swfilter(&adap->demux, buffer, length);\r\n}\r\nstatic void dvb_usb_data_complete_204(struct usb_data_stream *stream, u8 *buffer, size_t length)\r\n{\r\nstruct dvb_usb_adapter *adap = stream->user_priv;\r\nif (adap->feedcount > 0 && adap->state & DVB_USB_ADAP_STATE_DVB)\r\ndvb_dmx_swfilter_204(&adap->demux, buffer, length);\r\n}\r\nstatic void dvb_usb_data_complete_raw(struct usb_data_stream *stream,\r\nu8 *buffer, size_t length)\r\n{\r\nstruct dvb_usb_adapter *adap = stream->user_priv;\r\nif (adap->feedcount > 0 && adap->state & DVB_USB_ADAP_STATE_DVB)\r\ndvb_dmx_swfilter_raw(&adap->demux, buffer, length);\r\n}\r\nint dvb_usb_adapter_stream_init(struct dvb_usb_adapter *adap)\r\n{\r\nint i, ret = 0;\r\nfor (i = 0; i < adap->props.num_frontends; i++) {\r\nadap->fe_adap[i].stream.udev = adap->dev->udev;\r\nif (adap->props.fe[i].caps & DVB_USB_ADAP_RECEIVES_204_BYTE_TS)\r\nadap->fe_adap[i].stream.complete =\r\ndvb_usb_data_complete_204;\r\nelse\r\nif (adap->props.fe[i].caps & DVB_USB_ADAP_RECEIVES_RAW_PAYLOAD)\r\nadap->fe_adap[i].stream.complete =\r\ndvb_usb_data_complete_raw;\r\nelse\r\nadap->fe_adap[i].stream.complete = dvb_usb_data_complete;\r\nadap->fe_adap[i].stream.user_priv = adap;\r\nret = usb_urb_init(&adap->fe_adap[i].stream,\r\n&adap->props.fe[i].stream);\r\nif (ret < 0)\r\nbreak;\r\n}\r\nreturn ret;\r\n}\r\nint dvb_usb_adapter_stream_exit(struct dvb_usb_adapter *adap)\r\n{\r\nint i;\r\nfor (i = 0; i < adap->props.num_frontends; i++)\r\nusb_urb_exit(&adap->fe_adap[i].stream);\r\nreturn 0;\r\n}
