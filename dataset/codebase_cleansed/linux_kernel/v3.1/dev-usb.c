void __init s3c_ohci_set_platdata(struct s3c2410_hcd_info *info)
{
s3c_set_platdata(info, sizeof(struct s3c2410_hcd_info),
&s3c_device_ohci);
}
