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
