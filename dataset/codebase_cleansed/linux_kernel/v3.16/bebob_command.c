int avc_audio_set_selector(struct fw_unit *unit, unsigned int subunit_id,
unsigned int fb_id, unsigned int num)
{
u8 *buf;
int err;
buf = kzalloc(12, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
buf[0] = 0x00;
buf[1] = 0x08 | (0x07 & subunit_id);
buf[2] = 0xb8;
buf[3] = 0x80;
buf[4] = 0xff & fb_id;
buf[5] = 0x10;
buf[6] = 0x02;
buf[7] = 0xff & num;
buf[8] = 0x01;
err = fcp_avc_transaction(unit, buf, 12, buf, 12,
BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5) |
BIT(6) | BIT(7) | BIT(8));
if (err > 0 && err < 9)
err = -EIO;
else if (buf[0] == 0x08)
err = -ENOSYS;
else if (buf[0] == 0x0a)
err = -EINVAL;
else if (err > 0)
err = 0;
kfree(buf);
return err;
}
int avc_audio_get_selector(struct fw_unit *unit, unsigned int subunit_id,
unsigned int fb_id, unsigned int *num)
{
u8 *buf;
int err;
buf = kzalloc(12, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
buf[0] = 0x01;
buf[1] = 0x08 | (0x07 & subunit_id);
buf[2] = 0xb8;
buf[3] = 0x80;
buf[4] = 0xff & fb_id;
buf[5] = 0x10;
buf[6] = 0x02;
buf[7] = 0xff;
buf[8] = 0x01;
err = fcp_avc_transaction(unit, buf, 12, buf, 12,
BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5) |
BIT(6) | BIT(8));
if (err > 0 && err < 9)
err = -EIO;
else if (buf[0] == 0x08)
err = -ENOSYS;
else if (buf[0] == 0x0a)
err = -EINVAL;
else if (buf[0] == 0x0b)
err = -EAGAIN;
if (err < 0)
goto end;
*num = buf[7];
err = 0;
end:
kfree(buf);
return err;
}
static inline void
avc_bridgeco_fill_extension_addr(u8 *buf, u8 *addr)
{
buf[1] = addr[0];
memcpy(buf + 4, addr + 1, 5);
}
static inline void
avc_bridgeco_fill_plug_info_extension_command(u8 *buf, u8 *addr,
unsigned int itype)
{
buf[0] = 0x01;
buf[2] = 0x02;
buf[3] = 0xc0;
avc_bridgeco_fill_extension_addr(buf, addr);
buf[9] = itype;
}
int avc_bridgeco_get_plug_type(struct fw_unit *unit,
u8 addr[AVC_BRIDGECO_ADDR_BYTES],
enum avc_bridgeco_plug_type *type)
{
u8 *buf;
int err;
buf = kzalloc(12, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
avc_bridgeco_fill_plug_info_extension_command(buf, addr, 0x00);
err = fcp_avc_transaction(unit, buf, 12, buf, 12,
BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5) |
BIT(6) | BIT(7) | BIT(9));
if ((err >= 0) && (err < 8))
err = -EIO;
else if (buf[0] == 0x08)
err = -ENOSYS;
else if (buf[0] == 0x0a)
err = -EINVAL;
else if (buf[0] == 0x0b)
err = -EAGAIN;
if (err < 0)
goto end;
*type = buf[10];
err = 0;
end:
kfree(buf);
return err;
}
int avc_bridgeco_get_plug_ch_pos(struct fw_unit *unit,
u8 addr[AVC_BRIDGECO_ADDR_BYTES],
u8 *buf, unsigned int len)
{
int err;
avc_bridgeco_fill_plug_info_extension_command(buf, addr, 0x03);
err = fcp_avc_transaction(unit, buf, 12, buf, 256,
BIT(1) | BIT(2) | BIT(3) | BIT(4) |
BIT(5) | BIT(6) | BIT(7) | BIT(9));
if ((err >= 0) && (err < 8))
err = -EIO;
else if (buf[0] == 0x08)
err = -ENOSYS;
else if (buf[0] == 0x0a)
err = -EINVAL;
else if (buf[0] == 0x0b)
err = -EAGAIN;
if (err < 0)
goto end;
memmove(buf, buf + 10, err - 10);
err = 0;
end:
return err;
}
int avc_bridgeco_get_plug_section_type(struct fw_unit *unit,
u8 addr[AVC_BRIDGECO_ADDR_BYTES],
unsigned int id, u8 *type)
{
u8 *buf;
int err;
buf = kzalloc(12, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
avc_bridgeco_fill_plug_info_extension_command(buf, addr, 0x07);
buf[10] = 0xff & ++id;
err = fcp_avc_transaction(unit, buf, 12, buf, 12,
BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5) |
BIT(6) | BIT(7) | BIT(9) | BIT(10));
if ((err >= 0) && (err < 8))
err = -EIO;
else if (buf[0] == 0x08)
err = -ENOSYS;
else if (buf[0] == 0x0a)
err = -EINVAL;
else if (buf[0] == 0x0b)
err = -EAGAIN;
if (err < 0)
goto end;
*type = buf[11];
err = 0;
end:
kfree(buf);
return err;
}
int avc_bridgeco_get_plug_input(struct fw_unit *unit,
u8 addr[AVC_BRIDGECO_ADDR_BYTES], u8 input[7])
{
int err;
u8 *buf;
buf = kzalloc(18, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
avc_bridgeco_fill_plug_info_extension_command(buf, addr, 0x05);
err = fcp_avc_transaction(unit, buf, 16, buf, 16,
BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5) |
BIT(6) | BIT(7));
if ((err >= 0) && (err < 8))
err = -EIO;
else if (buf[0] == 0x08)
err = -ENOSYS;
else if (buf[0] == 0x0a)
err = -EINVAL;
else if (buf[0] == 0x0b)
err = -EAGAIN;
if (err < 0)
goto end;
memcpy(input, buf + 10, 5);
err = 0;
end:
kfree(buf);
return err;
}
int avc_bridgeco_get_plug_strm_fmt(struct fw_unit *unit,
u8 addr[AVC_BRIDGECO_ADDR_BYTES], u8 *buf,
unsigned int *len, unsigned int eid)
{
int err;
if ((buf == NULL) || (*len < 12)) {
err = -EINVAL;
goto end;
}
buf[0] = 0x01;
buf[2] = 0x2f;
buf[3] = 0xc1;
avc_bridgeco_fill_extension_addr(buf, addr);
buf[10] = 0xff & eid;
err = fcp_avc_transaction(unit, buf, 12, buf, *len,
BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5) |
BIT(6) | BIT(7) | BIT(10));
if ((err >= 0) && (err < 12))
err = -EIO;
else if (buf[0] == 0x08)
err = -ENOSYS;
else if (buf[0] == 0x0a)
err = -EINVAL;
else if (buf[0] == 0x0b)
err = -EAGAIN;
else if (buf[10] != eid)
err = -EIO;
if (err < 0)
goto end;
memmove(buf, buf + 11, err - 11);
*len = err - 11;
err = 0;
end:
return err;
}
