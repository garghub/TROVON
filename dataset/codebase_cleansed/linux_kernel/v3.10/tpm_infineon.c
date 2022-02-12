static inline void tpm_data_out(unsigned char data, unsigned char offset)
{
if (tpm_dev.iotype == TPM_INF_IO_PORT)
outb(data, tpm_dev.data_regs + offset);
else
writeb(data, tpm_dev.mem_base + tpm_dev.data_regs + offset);
}
static inline unsigned char tpm_data_in(unsigned char offset)
{
if (tpm_dev.iotype == TPM_INF_IO_PORT)
return inb(tpm_dev.data_regs + offset);
else
return readb(tpm_dev.mem_base + tpm_dev.data_regs + offset);
}
static inline void tpm_config_out(unsigned char data, unsigned char offset)
{
if (tpm_dev.iotype == TPM_INF_IO_PORT)
outb(data, tpm_dev.config_port + offset);
else
writeb(data, tpm_dev.mem_base + tpm_dev.index_off + offset);
}
static inline unsigned char tpm_config_in(unsigned char offset)
{
if (tpm_dev.iotype == TPM_INF_IO_PORT)
return inb(tpm_dev.config_port + offset);
else
return readb(tpm_dev.mem_base + tpm_dev.index_off + offset);
}
static int empty_fifo(struct tpm_chip *chip, int clear_wrfifo)
{
int status;
int check = 0;
int i;
if (clear_wrfifo) {
for (i = 0; i < 4096; i++) {
status = tpm_data_in(WRFIFO);
if (status == 0xff) {
if (check == 5)
break;
else
check++;
}
}
}
i = 0;
do {
status = tpm_data_in(RDFIFO);
status = tpm_data_in(STAT);
i++;
if (i == TPM_MAX_TRIES)
return -EIO;
} while ((status & (1 << STAT_RDA)) != 0);
return 0;
}
static int wait(struct tpm_chip *chip, int wait_for_bit)
{
int status;
int i;
for (i = 0; i < TPM_MAX_TRIES; i++) {
status = tpm_data_in(STAT);
if (status & 1 << wait_for_bit)
break;
msleep(TPM_MSLEEP_TIME);
}
if (i == TPM_MAX_TRIES) {
if (wait_for_bit == STAT_XFE)
dev_err(chip->dev, "Timeout in wait(STAT_XFE)\n");
if (wait_for_bit == STAT_RDA)
dev_err(chip->dev, "Timeout in wait(STAT_RDA)\n");
return -EIO;
}
return 0;
}
static void wait_and_send(struct tpm_chip *chip, u8 sendbyte)
{
wait(chip, STAT_XFE);
tpm_data_out(sendbyte, WRFIFO);
}
static void tpm_wtx(struct tpm_chip *chip)
{
number_of_wtx++;
dev_info(chip->dev, "Granting WTX (%02d / %02d)\n",
number_of_wtx, TPM_MAX_WTX_PACKAGES);
wait_and_send(chip, TPM_VL_VER);
wait_and_send(chip, TPM_CTRL_WTX);
wait_and_send(chip, 0x00);
wait_and_send(chip, 0x00);
msleep(TPM_WTX_MSLEEP_TIME);
}
static void tpm_wtx_abort(struct tpm_chip *chip)
{
dev_info(chip->dev, "Aborting WTX\n");
wait_and_send(chip, TPM_VL_VER);
wait_and_send(chip, TPM_CTRL_WTX_ABORT);
wait_and_send(chip, 0x00);
wait_and_send(chip, 0x00);
number_of_wtx = 0;
msleep(TPM_WTX_MSLEEP_TIME);
}
static int tpm_inf_recv(struct tpm_chip *chip, u8 * buf, size_t count)
{
int i;
int ret;
u32 size = 0;
number_of_wtx = 0;
recv_begin:
for (i = 0; i < 4; i++) {
ret = wait(chip, STAT_RDA);
if (ret)
return -EIO;
buf[i] = tpm_data_in(RDFIFO);
}
if (buf[0] != TPM_VL_VER) {
dev_err(chip->dev,
"Wrong transport protocol implementation!\n");
return -EIO;
}
if (buf[1] == TPM_CTRL_DATA) {
size = ((buf[2] << 8) | buf[3]);
for (i = 0; i < size; i++) {
wait(chip, STAT_RDA);
buf[i] = tpm_data_in(RDFIFO);
}
if ((size == 0x6D00) && (buf[1] == 0x80)) {
dev_err(chip->dev, "Error handling on vendor layer!\n");
return -EIO;
}
for (i = 0; i < size; i++)
buf[i] = buf[i + 6];
size = size - 6;
return size;
}
if (buf[1] == TPM_CTRL_WTX) {
dev_info(chip->dev, "WTX-package received\n");
if (number_of_wtx < TPM_MAX_WTX_PACKAGES) {
tpm_wtx(chip);
goto recv_begin;
} else {
tpm_wtx_abort(chip);
goto recv_begin;
}
}
if (buf[1] == TPM_CTRL_WTX_ABORT_ACK) {
dev_info(chip->dev, "WTX-abort acknowledged\n");
return size;
}
if (buf[1] == TPM_CTRL_ERROR) {
dev_err(chip->dev, "ERROR-package received:\n");
if (buf[4] == TPM_INF_NAK)
dev_err(chip->dev,
"-> Negative acknowledgement"
" - retransmit command!\n");
return -EIO;
}
return -EIO;
}
static int tpm_inf_send(struct tpm_chip *chip, u8 * buf, size_t count)
{
int i;
int ret;
u8 count_high, count_low, count_4, count_3, count_2, count_1;
tpm_data_out(RESET_LP_IRQC_DISABLE, CMD);
ret = empty_fifo(chip, 1);
if (ret) {
dev_err(chip->dev, "Timeout while clearing FIFO\n");
return -EIO;
}
ret = wait(chip, STAT_XFE);
if (ret)
return -EIO;
count_4 = (count & 0xff000000) >> 24;
count_3 = (count & 0x00ff0000) >> 16;
count_2 = (count & 0x0000ff00) >> 8;
count_1 = (count & 0x000000ff);
count_high = ((count + 6) & 0xffffff00) >> 8;
count_low = ((count + 6) & 0x000000ff);
wait_and_send(chip, TPM_VL_VER);
wait_and_send(chip, TPM_CTRL_DATA);
wait_and_send(chip, count_high);
wait_and_send(chip, count_low);
wait_and_send(chip, TPM_VL_VER);
wait_and_send(chip, TPM_VL_CHANNEL_TPM);
wait_and_send(chip, count_4);
wait_and_send(chip, count_3);
wait_and_send(chip, count_2);
wait_and_send(chip, count_1);
for (i = 0; i < count; i++) {
wait_and_send(chip, buf[i]);
}
return count;
}
static void tpm_inf_cancel(struct tpm_chip *chip)
{
}
static u8 tpm_inf_status(struct tpm_chip *chip)
{
return tpm_data_in(STAT);
}
static int tpm_inf_pnp_probe(struct pnp_dev *dev,
const struct pnp_device_id *dev_id)
{
int rc = 0;
u8 iol, ioh;
int vendorid[2];
int version[2];
int productid[2];
char chipname[20];
struct tpm_chip *chip;
if (pnp_port_valid(dev, 0) && pnp_port_valid(dev, 1) &&
!(pnp_port_flags(dev, 0) & IORESOURCE_DISABLED)) {
tpm_dev.iotype = TPM_INF_IO_PORT;
tpm_dev.config_port = pnp_port_start(dev, 0);
tpm_dev.config_size = pnp_port_len(dev, 0);
tpm_dev.data_regs = pnp_port_start(dev, 1);
tpm_dev.data_size = pnp_port_len(dev, 1);
if ((tpm_dev.data_size < 4) || (tpm_dev.config_size < 2)) {
rc = -EINVAL;
goto err_last;
}
dev_info(&dev->dev, "Found %s with ID %s\n",
dev->name, dev_id->id);
if (!((tpm_dev.data_regs >> 8) & 0xff)) {
rc = -EINVAL;
goto err_last;
}
if (request_region(tpm_dev.data_regs, tpm_dev.data_size,
"tpm_infineon0") == NULL) {
rc = -EINVAL;
goto err_last;
}
if (request_region(tpm_dev.config_port, tpm_dev.config_size,
"tpm_infineon0") == NULL) {
release_region(tpm_dev.data_regs, tpm_dev.data_size);
rc = -EINVAL;
goto err_last;
}
} else if (pnp_mem_valid(dev, 0) &&
!(pnp_mem_flags(dev, 0) & IORESOURCE_DISABLED)) {
tpm_dev.iotype = TPM_INF_IO_MEM;
tpm_dev.map_base = pnp_mem_start(dev, 0);
tpm_dev.map_size = pnp_mem_len(dev, 0);
dev_info(&dev->dev, "Found %s with ID %s\n",
dev->name, dev_id->id);
if (request_mem_region(tpm_dev.map_base, tpm_dev.map_size,
"tpm_infineon0") == NULL) {
rc = -EINVAL;
goto err_last;
}
tpm_dev.mem_base = ioremap(tpm_dev.map_base, tpm_dev.map_size);
if (tpm_dev.mem_base == NULL) {
release_mem_region(tpm_dev.map_base, tpm_dev.map_size);
rc = -EINVAL;
goto err_last;
}
tpm_dev.index_off = TPM_ADDR;
tpm_dev.data_regs = 0x0;
} else {
rc = -EINVAL;
goto err_last;
}
tpm_config_out(ENABLE_REGISTER_PAIR, TPM_INF_ADDR);
tpm_config_out(IDVENL, TPM_INF_ADDR);
vendorid[1] = tpm_config_in(TPM_INF_DATA);
tpm_config_out(IDVENH, TPM_INF_ADDR);
vendorid[0] = tpm_config_in(TPM_INF_DATA);
tpm_config_out(IDPDL, TPM_INF_ADDR);
productid[1] = tpm_config_in(TPM_INF_DATA);
tpm_config_out(IDPDH, TPM_INF_ADDR);
productid[0] = tpm_config_in(TPM_INF_DATA);
tpm_config_out(CHIP_ID1, TPM_INF_ADDR);
version[1] = tpm_config_in(TPM_INF_DATA);
tpm_config_out(CHIP_ID2, TPM_INF_ADDR);
version[0] = tpm_config_in(TPM_INF_DATA);
switch ((productid[0] << 8) | productid[1]) {
case 6:
snprintf(chipname, sizeof(chipname), " (SLD 9630 TT 1.1)");
break;
case 11:
snprintf(chipname, sizeof(chipname), " (SLB 9635 TT 1.2)");
break;
default:
snprintf(chipname, sizeof(chipname), " (unknown chip)");
break;
}
if ((vendorid[0] << 8 | vendorid[1]) == (TPM_INFINEON_DEV_VEN_VALUE)) {
tpm_config_out(IOLIMH, TPM_INF_ADDR);
tpm_config_out((tpm_dev.data_regs >> 8) & 0xff, TPM_INF_DATA);
tpm_config_out(IOLIML, TPM_INF_ADDR);
tpm_config_out((tpm_dev.data_regs & 0xff), TPM_INF_DATA);
tpm_config_out(IOLIMH, TPM_INF_ADDR);
ioh = tpm_config_in(TPM_INF_DATA);
tpm_config_out(IOLIML, TPM_INF_ADDR);
iol = tpm_config_in(TPM_INF_DATA);
if ((ioh << 8 | iol) != tpm_dev.data_regs) {
dev_err(&dev->dev,
"Could not set IO-data registers to 0x%x\n",
tpm_dev.data_regs);
rc = -EIO;
goto err_release_region;
}
tpm_config_out(TPM_DAR, TPM_INF_ADDR);
tpm_config_out(0x01, TPM_INF_DATA);
tpm_config_out(DISABLE_REGISTER_PAIR, TPM_INF_ADDR);
tpm_data_out(RESET_LP_IRQC_DISABLE, CMD);
dev_info(&dev->dev, "TPM found: "
"config base 0x%lx, "
"data base 0x%lx, "
"chip version 0x%02x%02x, "
"vendor id 0x%x%x (Infineon), "
"product id 0x%02x%02x"
"%s\n",
tpm_dev.iotype == TPM_INF_IO_PORT ?
tpm_dev.config_port :
tpm_dev.map_base + tpm_dev.index_off,
tpm_dev.iotype == TPM_INF_IO_PORT ?
tpm_dev.data_regs :
tpm_dev.map_base + tpm_dev.data_regs,
version[0], version[1],
vendorid[0], vendorid[1],
productid[0], productid[1], chipname);
if (!(chip = tpm_register_hardware(&dev->dev, &tpm_inf)))
goto err_release_region;
return 0;
} else {
rc = -ENODEV;
goto err_release_region;
}
err_release_region:
if (tpm_dev.iotype == TPM_INF_IO_PORT) {
release_region(tpm_dev.data_regs, tpm_dev.data_size);
release_region(tpm_dev.config_port, tpm_dev.config_size);
} else {
iounmap(tpm_dev.mem_base);
release_mem_region(tpm_dev.map_base, tpm_dev.map_size);
}
err_last:
return rc;
}
static void tpm_inf_pnp_remove(struct pnp_dev *dev)
{
struct tpm_chip *chip = pnp_get_drvdata(dev);
if (chip) {
if (tpm_dev.iotype == TPM_INF_IO_PORT) {
release_region(tpm_dev.data_regs, tpm_dev.data_size);
release_region(tpm_dev.config_port,
tpm_dev.config_size);
} else {
iounmap(tpm_dev.mem_base);
release_mem_region(tpm_dev.map_base, tpm_dev.map_size);
}
tpm_dev_vendor_release(chip);
tpm_remove_hardware(chip->dev);
}
}
static int tpm_inf_pnp_suspend(struct pnp_dev *dev, pm_message_t pm_state)
{
struct tpm_chip *chip = pnp_get_drvdata(dev);
int rc;
if (chip) {
u8 savestate[] = {
0, 193,
0, 0, 0, 10,
0, 0, 0, 152
};
dev_info(&dev->dev, "saving TPM state\n");
rc = tpm_inf_send(chip, savestate, sizeof(savestate));
if (rc < 0) {
dev_err(&dev->dev, "error while saving TPM state\n");
return rc;
}
}
return 0;
}
static int tpm_inf_pnp_resume(struct pnp_dev *dev)
{
tpm_config_out(ENABLE_REGISTER_PAIR, TPM_INF_ADDR);
tpm_config_out(IOLIMH, TPM_INF_ADDR);
tpm_config_out((tpm_dev.data_regs >> 8) & 0xff, TPM_INF_DATA);
tpm_config_out(IOLIML, TPM_INF_ADDR);
tpm_config_out((tpm_dev.data_regs & 0xff), TPM_INF_DATA);
tpm_config_out(TPM_DAR, TPM_INF_ADDR);
tpm_config_out(0x01, TPM_INF_DATA);
tpm_config_out(DISABLE_REGISTER_PAIR, TPM_INF_ADDR);
tpm_data_out(RESET_LP_IRQC_DISABLE, CMD);
return tpm_pm_resume(&dev->dev);
}
static int __init init_inf(void)
{
return pnp_register_driver(&tpm_inf_pnp_driver);
}
static void __exit cleanup_inf(void)
{
pnp_unregister_driver(&tpm_inf_pnp_driver);
}
