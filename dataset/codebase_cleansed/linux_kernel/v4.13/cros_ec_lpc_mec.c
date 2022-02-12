static void cros_ec_lpc_mec_emi_write_address(u16 addr,
enum cros_ec_lpc_mec_emi_access_mode access_type)
{
addr -= MEC_EMI_RANGE_START;
outb((addr & 0xfc) | access_type, MEC_EMI_EC_ADDRESS_B0);
outb((addr >> 8) & 0x7f, MEC_EMI_EC_ADDRESS_B1);
}
u8 cros_ec_lpc_io_bytes_mec(enum cros_ec_lpc_mec_io_type io_type,
unsigned int offset, unsigned int length,
u8 *buf)
{
int i = 0;
int io_addr;
u8 sum = 0;
enum cros_ec_lpc_mec_emi_access_mode access, new_access;
if (offset & 0x3 || length < 4)
access = ACCESS_TYPE_BYTE;
else
access = ACCESS_TYPE_LONG_AUTO_INCREMENT;
mutex_lock(&io_mutex);
cros_ec_lpc_mec_emi_write_address(offset, access);
io_addr = MEC_EMI_EC_DATA_B0 + (offset & 0x3);
while (i < length) {
while (io_addr <= MEC_EMI_EC_DATA_B3) {
if (io_type == MEC_IO_READ)
buf[i] = inb(io_addr++);
else
outb(buf[i], io_addr++);
sum += buf[i++];
offset++;
if (i == length)
goto done;
}
if (length - i < 4 && io_type == MEC_IO_WRITE)
new_access = ACCESS_TYPE_BYTE;
else
new_access = ACCESS_TYPE_LONG_AUTO_INCREMENT;
if (new_access != access ||
access != ACCESS_TYPE_LONG_AUTO_INCREMENT) {
access = new_access;
cros_ec_lpc_mec_emi_write_address(offset, access);
}
io_addr = MEC_EMI_EC_DATA_B0;
}
done:
mutex_unlock(&io_mutex);
return sum;
}
void cros_ec_lpc_mec_init(void)
{
mutex_init(&io_mutex);
}
void cros_ec_lpc_mec_destroy(void)
{
mutex_destroy(&io_mutex);
}
