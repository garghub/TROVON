static int emi62_writememory(struct usb_device *dev, int address,
const unsigned char *data, int length,
__u8 request)
{
int result;
unsigned char *buffer = kmemdup(data, length, GFP_KERNEL);
if (!buffer) {
dev_err(&dev->dev, "kmalloc(%d) failed.\n", length);
return -ENOMEM;
}
result = usb_control_msg (dev, usb_sndctrlpipe(dev, 0), request, 0x40, address, 0, buffer, length, 300);
kfree (buffer);
return result;
}
static int emi62_set_reset (struct usb_device *dev, unsigned char reset_bit)
{
int response;
dev_info(&dev->dev, "%s - %d\n", __func__, reset_bit);
response = emi62_writememory (dev, CPUCS_REG, &reset_bit, 1, 0xa0);
if (response < 0)
dev_err(&dev->dev, "set_reset (%d) failed\n", reset_bit);
return response;
}
static int emi62_load_firmware (struct usb_device *dev)
{
const struct firmware *loader_fw = NULL;
const struct firmware *bitstream_fw = NULL;
const struct firmware *firmware_fw = NULL;
const struct ihex_binrec *rec;
int err = -ENOMEM;
int i;
__u32 addr;
__u8 *buf;
dev_dbg(&dev->dev, "load_firmware\n");
buf = kmalloc(FW_LOAD_SIZE, GFP_KERNEL);
if (!buf)
goto wraperr;
err = request_ihex_firmware(&loader_fw, "emi62/loader.fw", &dev->dev);
if (err)
goto nofw;
err = request_ihex_firmware(&bitstream_fw, "emi62/bitstream.fw",
&dev->dev);
if (err)
goto nofw;
err = request_ihex_firmware(&firmware_fw, FIRMWARE_FW, &dev->dev);
if (err) {
nofw:
goto wraperr;
}
err = emi62_set_reset(dev,1);
if (err < 0)
goto wraperr;
rec = (const struct ihex_binrec *)loader_fw->data;
while (rec) {
err = emi62_writememory(dev, be32_to_cpu(rec->addr),
rec->data, be16_to_cpu(rec->len),
ANCHOR_LOAD_INTERNAL);
if (err < 0)
goto wraperr;
rec = ihex_next_binrec(rec);
}
err = emi62_set_reset(dev,0);
if (err < 0)
goto wraperr;
msleep(250);
rec = (const struct ihex_binrec *)bitstream_fw->data;
do {
i = 0;
addr = be32_to_cpu(rec->addr);
while (rec && (i + be16_to_cpu(rec->len) < FW_LOAD_SIZE)) {
memcpy(buf + i, rec->data, be16_to_cpu(rec->len));
i += be16_to_cpu(rec->len);
rec = ihex_next_binrec(rec);
}
err = emi62_writememory(dev, addr, buf, i, ANCHOR_LOAD_FPGA);
if (err < 0)
goto wraperr;
} while (rec);
err = emi62_set_reset(dev,1);
if (err < 0)
goto wraperr;
for (rec = (const struct ihex_binrec *)loader_fw->data;
rec; rec = ihex_next_binrec(rec)) {
err = emi62_writememory(dev, be32_to_cpu(rec->addr),
rec->data, be16_to_cpu(rec->len),
ANCHOR_LOAD_INTERNAL);
if (err < 0)
goto wraperr;
}
err = emi62_set_reset(dev,0);
if (err < 0)
goto wraperr;
msleep(250);
for (rec = (const struct ihex_binrec *)firmware_fw->data;
rec; rec = ihex_next_binrec(rec)) {
if (!INTERNAL_RAM(be32_to_cpu(rec->addr))) {
err = emi62_writememory(dev, be32_to_cpu(rec->addr),
rec->data, be16_to_cpu(rec->len),
ANCHOR_LOAD_EXTERNAL);
if (err < 0)
goto wraperr;
}
}
err = emi62_set_reset(dev,1);
if (err < 0)
goto wraperr;
for (rec = (const struct ihex_binrec *)firmware_fw->data;
rec; rec = ihex_next_binrec(rec)) {
if (INTERNAL_RAM(be32_to_cpu(rec->addr))) {
err = emi62_writememory(dev, be32_to_cpu(rec->addr),
rec->data, be16_to_cpu(rec->len),
ANCHOR_LOAD_EXTERNAL);
if (err < 0)
goto wraperr;
}
}
err = emi62_set_reset(dev,0);
if (err < 0)
goto wraperr;
msleep(250);
release_firmware(loader_fw);
release_firmware(bitstream_fw);
release_firmware(firmware_fw);
kfree(buf);
return 1;
wraperr:
if (err < 0)
dev_err(&dev->dev,"%s - error loading firmware: error = %d\n",
__func__, err);
release_firmware(loader_fw);
release_firmware(bitstream_fw);
release_firmware(firmware_fw);
kfree(buf);
dev_err(&dev->dev, "Error\n");
return err;
}
static int emi62_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct usb_device *dev = interface_to_usbdev(intf);
dev_dbg(&intf->dev, "emi62_probe\n");
dev_info(&intf->dev, "%s start\n", __func__);
emi62_load_firmware(dev);
return -EIO;
}
static void emi62_disconnect(struct usb_interface *intf)
{
}
