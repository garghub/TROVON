int eprom_init(struct hfi1_devdata *dd)
{
int ret = 0;
if (dd->pcidev->device != PCI_DEVICE_ID_INTEL0)
return 0;
ret = acquire_chip_resource(dd, CR_EPROM, EPROM_TIMEOUT);
if (ret) {
dd_dev_err(dd,
"%s: unable to acquire EPROM resource, no EPROM support\n",
__func__);
goto done_asic;
}
write_csr(dd, ASIC_EEP_CTL_STAT, ASIC_EEP_CTL_STAT_EP_RESET_SMASK);
write_csr(dd, ASIC_EEP_CTL_STAT,
EP_SPEED_FULL << ASIC_EEP_CTL_STAT_RATE_SPI_SHIFT);
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_RELEASE_POWERDOWN_NOID);
dd->eprom_available = true;
release_chip_resource(dd, CR_EPROM);
done_asic:
return ret;
}
