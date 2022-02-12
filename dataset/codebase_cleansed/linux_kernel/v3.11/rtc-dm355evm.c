static int dm355evm_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
union evm_time time;
int status;
int tries = 0;
do {
status = dm355evm_msp_read(DM355EVM_MSP_RTC_0);
if (status < 0)
return status;
if (tries && time.bytes[0] == status)
break;
time.bytes[0] = status;
status = dm355evm_msp_read(DM355EVM_MSP_RTC_1);
if (status < 0)
return status;
if (tries && time.bytes[1] == status)
break;
time.bytes[1] = status;
status = dm355evm_msp_read(DM355EVM_MSP_RTC_2);
if (status < 0)
return status;
if (tries && time.bytes[2] == status)
break;
time.bytes[2] = status;
status = dm355evm_msp_read(DM355EVM_MSP_RTC_3);
if (status < 0)
return status;
if (tries && time.bytes[3] == status)
break;
time.bytes[3] = status;
} while (++tries < 5);
dev_dbg(dev, "read timestamp %08x\n", time.value);
rtc_time_to_tm(le32_to_cpu(time.value), tm);
return 0;
}
static int dm355evm_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
union evm_time time;
unsigned long value;
int status;
rtc_tm_to_time(tm, &value);
time.value = cpu_to_le32(value);
dev_dbg(dev, "write timestamp %08x\n", time.value);
status = dm355evm_msp_write(time.bytes[0], DM355EVM_MSP_RTC_0);
if (status < 0)
return status;
status = dm355evm_msp_write(time.bytes[1], DM355EVM_MSP_RTC_1);
if (status < 0)
return status;
status = dm355evm_msp_write(time.bytes[2], DM355EVM_MSP_RTC_2);
if (status < 0)
return status;
status = dm355evm_msp_write(time.bytes[3], DM355EVM_MSP_RTC_3);
if (status < 0)
return status;
return 0;
}
static int dm355evm_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtc;
rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&dm355evm_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc)) {
dev_err(&pdev->dev, "can't register RTC device, err %ld\n",
PTR_ERR(rtc));
return PTR_ERR(rtc);
}
platform_set_drvdata(pdev, rtc);
return 0;
}
