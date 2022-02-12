static ssize_t amd64_hole_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
u64 hole_base = 0;
u64 hole_offset = 0;
u64 hole_size = 0;
amd64_get_dram_hole_info(mci, &hole_base, &hole_offset, &hole_size);
return sprintf(data, "%llx %llx %llx\n", hole_base, hole_offset,
hole_size);
}
int amd64_create_sysfs_dbg_files(struct mem_ctl_info *mci)
{
int rc;
rc = device_create_file(&mci->dev, &dev_attr_dhar);
if (rc < 0)
return rc;
rc = device_create_file(&mci->dev, &dev_attr_dbam);
if (rc < 0)
return rc;
rc = device_create_file(&mci->dev, &dev_attr_topmem);
if (rc < 0)
return rc;
rc = device_create_file(&mci->dev, &dev_attr_topmem2);
if (rc < 0)
return rc;
rc = device_create_file(&mci->dev, &dev_attr_dram_hole);
if (rc < 0)
return rc;
return 0;
}
void amd64_remove_sysfs_dbg_files(struct mem_ctl_info *mci)
{
device_remove_file(&mci->dev, &dev_attr_dhar);
device_remove_file(&mci->dev, &dev_attr_dbam);
device_remove_file(&mci->dev, &dev_attr_topmem);
device_remove_file(&mci->dev, &dev_attr_topmem2);
device_remove_file(&mci->dev, &dev_attr_dram_hole);
}
