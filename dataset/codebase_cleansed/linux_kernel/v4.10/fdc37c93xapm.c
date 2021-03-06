static int __init smsc_superio_setup(void)
{
unsigned char devid, devrev;
outb(SMSC_ENTER_CONFIG_KEY, SMSC_CONFIG_PORT_ADDR);
devid = SMSC_READ_INDEXED(SMSC_DEVICE_ID_INDEX);
devrev = SMSC_READ_INDEXED(SMSC_DEVICE_REV_INDEX);
if ((devid == 0x30) && (devrev == 0x01))
printk("SMSC FDC37C93xAPM SuperIO device detected\n");
else
return -ENODEV;
SMSC_WRITE_INDEXED(SMSC_KEYBOARD_DEVICE, SMCS_LOGICAL_DEV_INDEX);
SMSC_WRITE_INDEXED(1, SMSC_ACTIVATE_INDEX);
SMSC_WRITE_INDEXED(MICRODEV_FPGA_IRQ_KEYBOARD, SMSC_PRIMARY_INT_INDEX);
SMSC_WRITE_INDEXED(MICRODEV_FPGA_IRQ_MOUSE, SMSC_SECONDARY_INT_INDEX);
SMSC_WRITE_INDEXED(SMSC_SERIAL1_DEVICE, SMCS_LOGICAL_DEV_INDEX);
SMSC_WRITE_INDEXED(1, SMSC_ACTIVATE_INDEX);
SMSC_WRITE_INDEXED(MSB(SERIAL1_PRIMARY_BASE), SMSC_PRIMARY_BASE_INDEX+0);
SMSC_WRITE_INDEXED(LSB(SERIAL1_PRIMARY_BASE), SMSC_PRIMARY_BASE_INDEX+1);
SMSC_WRITE_INDEXED(0x00, SMSC_HDCS0_INDEX);
SMSC_WRITE_INDEXED(MICRODEV_FPGA_IRQ_SERIAL1, SMSC_PRIMARY_INT_INDEX);
SMSC_WRITE_INDEXED(SMSC_SERIAL2_DEVICE, SMCS_LOGICAL_DEV_INDEX);
SMSC_WRITE_INDEXED(1, SMSC_ACTIVATE_INDEX);
SMSC_WRITE_INDEXED(MSB(SERIAL2_PRIMARY_BASE), SMSC_PRIMARY_BASE_INDEX+0);
SMSC_WRITE_INDEXED(LSB(SERIAL2_PRIMARY_BASE), SMSC_PRIMARY_BASE_INDEX+1);
SMSC_WRITE_INDEXED(0x00, SMSC_HDCS0_INDEX);
SMSC_WRITE_INDEXED(MICRODEV_FPGA_IRQ_SERIAL2, SMSC_PRIMARY_INT_INDEX);
SMSC_WRITE_INDEXED(SMSC_IDE1_DEVICE, SMCS_LOGICAL_DEV_INDEX);
SMSC_WRITE_INDEXED(1, SMSC_ACTIVATE_INDEX);
SMSC_WRITE_INDEXED(MSB(IDE1_PRIMARY_BASE), SMSC_PRIMARY_BASE_INDEX+0);
SMSC_WRITE_INDEXED(LSB(IDE1_PRIMARY_BASE), SMSC_PRIMARY_BASE_INDEX+1);
SMSC_WRITE_INDEXED(MSB(IDE1_SECONDARY_BASE), SMSC_SECONDARY_BASE_INDEX+0);
SMSC_WRITE_INDEXED(LSB(IDE1_SECONDARY_BASE), SMSC_SECONDARY_BASE_INDEX+1);
SMSC_WRITE_INDEXED(0x0c, SMSC_HDCS0_INDEX);
SMSC_WRITE_INDEXED(0x00, SMSC_HDCS1_INDEX);
SMSC_WRITE_INDEXED(MICRODEV_FPGA_IRQ_IDE1, SMSC_PRIMARY_INT_INDEX);
SMSC_WRITE_INDEXED(SMSC_IDE2_DEVICE, SMCS_LOGICAL_DEV_INDEX);
SMSC_WRITE_INDEXED(1, SMSC_ACTIVATE_INDEX);
SMSC_WRITE_INDEXED(MSB(IDE2_PRIMARY_BASE), SMSC_PRIMARY_BASE_INDEX+0);
SMSC_WRITE_INDEXED(LSB(IDE2_PRIMARY_BASE), SMSC_PRIMARY_BASE_INDEX+1);
SMSC_WRITE_INDEXED(MSB(IDE2_SECONDARY_BASE), SMSC_SECONDARY_BASE_INDEX+0);
SMSC_WRITE_INDEXED(LSB(IDE2_SECONDARY_BASE), SMSC_SECONDARY_BASE_INDEX+1);
SMSC_WRITE_INDEXED(MICRODEV_FPGA_IRQ_IDE2, SMSC_PRIMARY_INT_INDEX);
SMSC_WRITE_INDEXED(SMSC_CONFIG_REGISTERS, SMCS_LOGICAL_DEV_INDEX);
SMSC_WRITE_INDEXED(0x00, 0xc2);
SMSC_WRITE_INDEXED(0x01, 0xc5);
SMSC_WRITE_INDEXED(0x00, 0xc6);
SMSC_WRITE_INDEXED(0x00, 0xc7);
SMSC_WRITE_INDEXED(0x08, 0xe8);
outb(SMSC_EXIT_CONFIG_KEY, SMSC_CONFIG_PORT_ADDR);
return 0;
}
