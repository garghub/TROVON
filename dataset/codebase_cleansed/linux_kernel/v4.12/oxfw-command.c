int avc_stream_set_format(struct fw_unit *unit, enum avc_general_plug_dir dir,
unsigned int pid, u8 *format, unsigned int len)
{
u8 *buf;
int err;
buf = kmalloc(len + 10, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
buf[0] = 0x00;
buf[1] = 0xff;
buf[2] = 0xbf;
buf[3] = 0xc0;
buf[4] = dir;
buf[5] = 0x00;
buf[6] = 0x00;
buf[7] = 0xff & pid;
buf[8] = 0xff;
buf[9] = 0xff;
memcpy(buf + 10, format, len);
err = fcp_avc_transaction(unit, buf, len + 10, buf, len + 10,
BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5) |
BIT(6) | BIT(7) | BIT(8));
if (err < 0)
;
else if (err < len + 10)
err = -EIO;
else if (buf[0] == 0x08)
err = -ENOSYS;
else if (buf[0] == 0x0a)
err = -EINVAL;
else
err = 0;
kfree(buf);
return err;
}
int avc_stream_get_format(struct fw_unit *unit,
enum avc_general_plug_dir dir, unsigned int pid,
u8 *buf, unsigned int *len, unsigned int eid)
{
unsigned int subfunc;
int err;
if (eid == 0xff)
subfunc = 0xc0;
else
subfunc = 0xc1;
buf[0] = 0x01;
buf[1] = 0xff;
buf[2] = 0xbf;
buf[3] = subfunc;
buf[4] = dir;
buf[5] = 0x00;
buf[6] = 0x00;
buf[7] = 0xff & pid;
buf[8] = 0xff;
buf[9] = 0xff;
buf[10] = 0xff & eid;
buf[11] = 0xff;
err = fcp_avc_transaction(unit, buf, 12, buf, *len,
BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5) |
BIT(6) | BIT(7));
if (err < 0)
;
else if (err < 12)
err = -EIO;
else if (buf[0] == 0x08)
err = -ENOSYS;
else if (buf[0] == 0x0a)
err = -EINVAL;
else if (buf[0] == 0x0b)
err = -EAGAIN;
else if ((subfunc == 0xc1) && (buf[10] != eid))
err = -EIO;
if (err < 0)
goto end;
if (subfunc == 0xc0) {
memmove(buf, buf + 10, err - 10);
*len = err - 10;
} else {
memmove(buf, buf + 11, err - 11);
*len = err - 11;
}
err = 0;
end:
return err;
}
int avc_general_inquiry_sig_fmt(struct fw_unit *unit, unsigned int rate,
enum avc_general_plug_dir dir,
unsigned short pid)
{
unsigned int sfc;
u8 *buf;
int err;
for (sfc = 0; sfc < CIP_SFC_COUNT; sfc++) {
if (amdtp_rate_table[sfc] == rate)
break;
}
if (sfc == CIP_SFC_COUNT)
return -EINVAL;
buf = kzalloc(8, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
buf[0] = 0x02;
buf[1] = 0xff;
if (dir == AVC_GENERAL_PLUG_DIR_IN)
buf[2] = 0x19;
else
buf[2] = 0x18;
buf[3] = 0xff & pid;
buf[4] = 0x90;
buf[5] = 0x07 & sfc;
buf[6] = 0xff;
buf[7] = 0xff;
err = fcp_avc_transaction(unit, buf, 8, buf, 8,
BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5));
if (err < 0)
;
else if (err < 8)
err = -EIO;
else if (buf[0] == 0x08)
err = -ENOSYS;
if (err < 0)
goto end;
err = 0;
end:
kfree(buf);
return err;
}
